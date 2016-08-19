#pragma once

#include <Poco/Activity.h>
#include <Poco/NotificationCenter.h>
#include "NICStatus.h"

class CNetworkStatus
{
public:
	CNetworkStatus();	
	~CNetworkStatus();

	void start();
	void stop();
	NETWORK_STATUS GetNetStatus();
protected:
	void runActivity();

private:
	Poco::Activity<CNetworkStatus>	_activity;
	NETWORK_STATUS				_NetStatus;
	NETWORK_STATUS				_previousStaus;
	Poco::NotificationCenter&	_nc;
};

