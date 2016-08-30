#include "stdafx.h"
#include "InitNetConfig.h"
#include "SetIPAddress.h"

#include <Poco/Net/IPAddress.h>
#include "Poco/Net/ICMPClient.h"

using Poco::Net::NetworkInterface;
using Poco::Net::IPAddress;

CInitNetConfig::CInitNetConfig()
:_family(IPAddress::IPv4)
{
	SetIp();
}


CInitNetConfig::~CInitNetConfig()
{
}


void CInitNetConfig::SetIp()
{
	GetLocalInterfc();

	if (!IsOnLine())
		return;
	std::string sIP, sMac, sGate;
	CSetIPAddress setip;

	_dhcp.GetUseableNetConfig(sIP, sMac, sGate);
	setip.setNetConfig(sIP, sMac, sGate);

	Poco::Net::ICMPClient test(_family);
	int iRet = test.ping(sIP, 10);
}
	
void CInitNetConfig::GetLocalInterfc()
{
	NetworkInterface::Map map = NetworkInterface::map(false, false);
	for (NetworkInterface::Map::iterator it = map.begin();
		it != map.end(); ++it)
	{
		NetworkInterface& netInter = it->second;
		if (netInter.type() == netInter.NI_TYPE_ETHERNET_CSMACD && netInter.isUp())
		{
			_inft = netInter;
		}
	}
}

bool CInitNetConfig::IsOnLine()
{
	return _inft.isUp();
}
