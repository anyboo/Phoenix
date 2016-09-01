
#include "Scene/ARPFindSegment.h"

#include <vector>

#include <windows.h>
#include <Winsock2.h>
#include <assert.h>
#include "Poco/Net/NetworkInterface.h"

using Poco::Net::NetworkInterface;

typedef struct arppkt
{
	unsigned short hdtyp;//hd type
	unsigned short protyp;//protocol type
	unsigned char hdsize;//hd length
	unsigned char prosize;//protocol length
	unsigned short op;//op type
	u_char smac[6];//src MAC address
	u_char sip[4];//src IP
	u_char dmac[6];//dest MAC address
	u_char dip[4];//dest IP
}arpp;

ARPFindSegment::ARPFindSegment()
{
}


ARPFindSegment::~ARPFindSegment()
{
}

void ARPFindSegment::GetSearchBackIPs(const std::string& NetworkCardName, std::set<std::string>& ipList, std::set<std::string>& dstList)
{
	ipList.clear();
	GetArpHandle();
	assert(_handle);

	std::vector<std::string> IPs;
	GetLocalIPs(NetworkCardName, IPs);
	const int nMaxSeconds = 5;
	int start = GetTickCount();
	std::string specialIP;
	struct pcap_pkthdr * header;
	const u_char * pkt_data;

	while (true)
	{
		if (GetTickCount() - start > nMaxSeconds * 1000)
		{
			break;
		}
		//get arp packet
		if (pcap_next_ex(_handle, &header, &pkt_data) == 0){
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

			std::string source = std::string(szIP);
			if (IPs.end() != std::find(IPs.begin(), IPs.end(), source)){
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
			std::string source = std::string(szsource);
			if (IPs.end() != std::find(IPs.begin(), IPs.end(), source)){
				continue;
			}

			dstList.insert(source);

			break;
		}
	}
	if (_handle)
		pcap_close(_handle);
}


bool ARPFindSegment::GetArpHandle()
{
	pcap_if_t * alldevs;//pcap_if_t list point
	
	char errbuf[PCAP_ERRBUF_SIZE];
	u_int netmask; //define netmask 
	char packet_filter[] = "ether proto \\arp";
	struct bpf_program fcode;
	
	//get all net device
	if (pcap_findalldevs(&alldevs, errbuf) == -1)
		return false;

	assert(alldevs);
	if ((_handle = pcap_open_live(alldevs->name, 65536, 1, 1000, errbuf)) == NULL)
	{
		pcap_freealldevs(alldevs);
		return false;
	}

	if (pcap_datalink(_handle) != DLT_EN10MB || alldevs->addresses == NULL)
		return false;

	netmask = ((struct sockaddr_in *)(alldevs->addresses->netmask))->sin_addr.S_un.S_addr;
	pcap_freealldevs(alldevs);

	//build filter, only get ARP packet
	if (pcap_compile(_handle, &fcode, packet_filter, 1, netmask) < 0)
		return false;

	//set filter
	if (pcap_setfilter(_handle, &fcode) < 0)
		return false;
	return true;
}

void ARPFindSegment::GetLocalIPs(const std::string& NetworkCardName, std::vector<std::string>& IPs)
{
	NetworkInterface intf = NetworkInterface::forName(NetworkCardName);
	NetworkInterface::AddressList ipList = intf.addressList();

	for (size_t i = 1; i < ipList.size(); i++)
	{
		std::string ip = ipList[i].get<0>().toString();
		IPs.push_back(ip);
	}
}

