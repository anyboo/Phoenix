#include "stdafx.h"
#include "InitNetConfig.h"
#include "SetIPAddress.h"
#include "DHCPClient.h"
#include "ARPClient.h"

using Poco::Net::NetworkInterface;
using Poco::Net::IPAddress;

CInitNetConfig::CInitNetConfig()
{
	SetIp();
}


CInitNetConfig::~CInitNetConfig()
{
}


void CInitNetConfig::SetIp()
{
	DHCPClient dhcp;
	ARPClient arp;

	NetworkInterface::Map map = NetworkInterface::map(false, false);
	for (NetworkInterface::Map::iterator it = map.begin();
		it != map.end(); ++it)
	{
		NetworkInterface& netInter = it->second;
		if (netInter.type() == netInter.NI_TYPE_ETHERNET_CSMACD && netInter.isUp())
		{
			std::string strName = netInter.name();
			bool bRet1 = dhcp.Request(strName);
			if (!bRet1)
			{
				bool bRet2 = arp.Request(strName);
			}
		}
	}
}
	


