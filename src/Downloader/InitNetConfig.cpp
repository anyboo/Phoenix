#include "stdafx.h"
#include "InitNetConfig.h"
#include "Scene/SetIPAddress.h"
#include "Scene/DHCPClient.h"

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

	NetworkInterface::Map map = NetworkInterface::map(false, false);
	for (NetworkInterface::Map::iterator it = map.begin();
		it != map.end(); ++it)
	{
		NetworkInterface& netInter = it->second;
		if (netInter.type() == netInter.NI_TYPE_ETHERNET_CSMACD && netInter.isUp())
		{
			std::string strName = netInter.name();
			bool bRet = dhcp.Request(strName);
		}
	}
}
	


