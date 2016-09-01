#include "SetIpByArp.h"

#include <windows.h>
#include <Winsock2.h>
#include <iphlpapi.h>
#include <tlhelp32.h>

SetIpByArp::SetIpByArp()
{
}


SetIpByArp::~SetIpByArp()
{
}

bool SetIpByArp::getDirectDevice(vector<string>& IPs, set<string>& ipList, set<string>& dstList)
{
	ipList.clear();
	_IPs = IPs;
	if (!SetArpPacket())
		return false;
	
	GetArpPacket(ipList, dstList);

	return !ipList.empty();
}

bool SetIpByArp::SetArpPacket()
{
	pcap_if_t * alldevs;//pcap_if_t list point
	char errbuf[PCAP_ERRBUF_SIZE];
	u_int netmask; //define netmask 
	char packet_filter[] = "ether proto \\arp";
	struct bpf_program fcode;

	//get all net device
	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		poco_error_f1(logger_handle, "Error in pcap_findalldevs:%s", string(errbuf));
		return false;
	}

	if (!alldevs)
	{
		poco_error(logger_handle, "cannot find net device!  install WinPcap?");
		return false;
	}

	poco_information_f2(logger_handle, "desc: %s, name: %s", string(alldevs->description), string(alldevs->name));

	if ((_adhandle = pcap_open_live(alldevs->name, 65536, 1, 1000, errbuf)) == NULL)
	{
		poco_error_f1(logger_handle, "pcap_open_live failed!  not surpport by WinPcap : %s", string(alldevs->name));
		pcap_freealldevs(alldevs);
		return false;
	}

	if (pcap_datalink(_adhandle) != DLT_EN10MB || alldevs->addresses == NULL) {
		poco_error(logger_handle, "pcap_datalink(adhandle) != DLT_EN10MB || alldevs->addresses == NULL");
		return false;
	}


	netmask = ((struct sockaddr_in *)(alldevs->addresses->netmask))->sin_addr.S_un.S_addr;
	pcap_freealldevs(alldevs);


	//build filter, only get ARP packet
	if (pcap_compile(_adhandle, &fcode, packet_filter, 1, netmask) < 0)
	{
		poco_error(logger_handle, "unable to compile the packet filter.Check the syntax.");
		return false;
	}

	//set filter
	if (pcap_setfilter(_adhandle, &fcode) < 0)
	{
		poco_error(logger_handle, "Error setting the filter.");
		return false;
	}

	return true;
}

void SetIpByArp::GetArpPacket(set<string>& ipList, set<string>& dstList)
{
	struct pcap_pkthdr * header;
	const u_char * pkt_data;
	const int nMaxSeconds = 5;
	int start = GetTickCount();
	while (true)
	{
		if (GetTickCount() - start > nMaxSeconds * 1000)
		{
			poco_information(logger_handle, "arp time out");
			break;
		}
		//get arp packet
		if (pcap_next_ex(_adhandle, &header, &pkt_data) == 0){
			continue;
		}
		arpp* arph = (arpp *)(pkt_data + 14);
		if (htons(arph->op) == 1) //arp
		{
			if (arph->sip[0] == 0)
			{
				continue;
			}
			if (arph->sip[0] == 169 && arph->sip[1] == 254)
			{
				continue;
			}

			char szIP[30] = { 0 };
			sprintf_s(szIP, "%d.%d.%d.%d", arph->sip[0], arph->sip[1], arph->sip[2], arph->sip[3]);
			poco_information_f1(logger_handle, "ip 0: %s", string(szIP));

			string source = string(szIP);
			if (_IPs.end() != std::find(_IPs.begin(), _IPs.end(), source)){
				continue;
			}

			ipList.insert(source);
		}
		else
		{
			if (arph->sip[0] == 0)
			{
				continue;
			}
			if (arph->sip[0] == 169 && arph->sip[1] == 254)
			{
				continue;
			}

			char szsource[30] = { 0 };
			sprintf_s(szsource, "%d.%d.%d.%d", arph->sip[0], arph->sip[1], arph->sip[2], arph->sip[3]);
			poco_information_f1(logger_handle, "ip 6: %s", string(szsource));
			string source = string(szsource);
			if (_IPs.end() != std::find(_IPs.begin(), _IPs.end(), source)){
				continue;
			}

			dstList.insert(source);

			break;
		}
	}
	if (_adhandle)
		pcap_close(_adhandle);

}
