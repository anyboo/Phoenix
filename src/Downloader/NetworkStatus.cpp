#include "stdafx.h"
#include "NetworkStatus.h"


using Poco::Exception;
using Poco::Net::IPAddress;
using Poco::Net::NetworkInterface;

CNetworkStatus::CNetworkStatus()
:_activity(this, &CNetworkStatus::runActivity), _NetStatus_Tmp(OFF_LINE)
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
		Thread::sleep(2000);
		_NetStatus = GetNetStatus();
		while (_NetStatus != _NetStatus_Tmp)
		{
			_NetStatus_Tmp = _NetStatus;
			Poco::NotificationCenter::defaultCenter().postNotification(new StatusNotification(_NetStatus));
		}
	}
}