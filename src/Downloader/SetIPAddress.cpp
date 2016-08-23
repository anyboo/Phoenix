#include "stdafx.h"
#include "SetIPAddress.h"
#include <Poco/Exception.h>
#include <Poco/Net/IPAddress.h>

using Poco::Exception;
using Poco::Net::IPAddress;
using Poco::Net::NetworkInterface;

CSetIPAddress::CSetIPAddress()
{
	InitNetIF();
}


CSetIPAddress::~CSetIPAddress()
{
}

void CSetIPAddress::InitNetIF()
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

void CSetIPAddress::SetIPAddress(std::string& strIP, std::string& strSubNet, std::string& strBroadcast)
{
	IPAddress NewIP(strIP);
	IPAddress NewSubNet(strSubNet);
	IPAddress NewBroadcast(strBroadcast);
	_inft.addAddress(NewIP, NewSubNet, NewBroadcast);
}

IPADDRESS_INFO CSetIPAddress::GetCurIPAddress()
{
	IPADDRESS_INFO ipaddress_Info;
	NetworkInterface::AddressList ipList = _inft.addressList();
	size_t n = ipList.size() - 1;
	IPAddress ipAddress = ipList[n].get<0>();
	IPAddress subnetAddress = ipList[n].get<1>();
	IPAddress broadcastAddress = ipList[n].get<2>();
	ipaddress_Info.strIP = ipAddress.toString();
	ipaddress_Info.strSubNet = subnetAddress.toString();
	ipaddress_Info.strBroadcast = broadcastAddress.toString();
	return ipaddress_Info;
}


