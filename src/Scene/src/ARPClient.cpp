#include "Scene/ARPClient.h"
#include "Scene/ARPFindSegment.h"
#include "Poco/Net/ICMPClient.h"

using Poco::Net::ICMPClient;

ARPClient::ARPClient()
{
}


ARPClient::~ARPClient()
{
}

bool ARPClient::Request(const std::string& NetworkCardName)
{
	return SetIpByArp(NetworkCardName);
}

bool ARPClient::SetIpByArp(const std::string& NetworkCardName)
{
	ICMPClient ic(Poco::Net::IPAddress::IPv4);
	ARPFindSegment arpfs;
	std::set<std::string>::iterator itor;
	std::set<std::string> ipList;
	std::set<std::string> dstList;
	std::set<std::string> Domains;
	arpfs.GetSearchBackIPs(NetworkCardName, ipList, dstList);

	if (ipList.size() == 1)
	{
		itor = ipList.begin();
		std::string strIp = *itor;
		std::string strGate = strIp;
		std::string strMsk("255.255.255.0");
		std::string strnum = strIp.substr(strIp.find_last_of(".") + 1, strIp.size());
		strIp = strIp.substr(0, strIp.find_last_of(".") + 1);
		int number = stoi(strnum) + 1;
		strIp = strIp.append(std::to_string(number));	
		_setip.setNetConfig(strIp, strMsk, strGate);
		if (ic.ping(strIp) != 0)
			return true;
	}
	else
	{
		for (itor = ipList.begin(); itor != ipList.end(); itor++)
		{
			std::string sDomain = *itor;
			sDomain = sDomain.substr(0, sDomain.find_last_of("."));
			Domains.insert(sDomain);
		}
	
		for (itor = Domains.begin(); itor != Domains.end(); itor++)
		{
			std::string sNetGate(*itor);
			sNetGate.append(".1");
			std::string sIP(*itor);
			sIP.append(".144");
			std::string strMsk("255.255.255.0");	
			_setip.setNetConfig(sIP, strMsk, sNetGate);
			if (ic.ping(sIP) != 0)
				return true;
		}
	}

	return false;
}