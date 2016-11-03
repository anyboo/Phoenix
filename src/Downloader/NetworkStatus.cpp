#include "stdafx.h"
#include "NetworkStatus.h"
#include "NICStatus.h"
#include <Poco/Net/NetworkInterface.h>
#include <Poco/Exception.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Thread.h>
#include <iostream>

using Poco::Activity;
using Poco::Thread;
using Poco::Exception;
using Poco::Net::IPAddress;
using Poco::Net::NetworkInterface;

CNetworkStatus::CNetworkStatus()
:_activity(this, &CNetworkStatus::runActivity)
, _previousStaus(OFF_LINE)
, _nc(Poco::NotificationCenter::defaultCenter())
{

}

CNetworkStatus::~CNetworkStatus()
{

}

void CNetworkStatus::start()
{
	_activity.start();
}

void CNetworkStatus::stop()
{
	_activity.stop();
	_activity.wait();
}

NETWORK_STATUS CNetworkStatus::GetNetStatus()
{
	try
	{
		NetworkInterface::Map map = NetworkInterface::map(false, false);
		for (NetworkInterface::Map::iterator it = map.begin();
			it != map.end(); ++it)
		{
			NetworkInterface& netInter = it->second;
			if (netInter.type() == netInter.NI_TYPE_ETHERNET_CSMACD && netInter.isUp())
			{
				return ON_LINE;
			}
		}
		return OFF_LINE;
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
		return OFF_LINE;
	}
}

void CNetworkStatus::runActivity()
{
	while (!_activity.isStopped())
	{
		Thread::sleep(1000);
		_NetStatus = GetNetStatus();
		if (_previousStaus != _NetStatus)
		{
			_previousStaus = _NetStatus;
			_nc.postNotification(new NICStatusNotification(_NetStatus));
		}
	}
}