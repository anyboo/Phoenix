#pragma once
#include "Poco/Net/NetworkInterface.h"
#include "Poco/Exception.h"
#include "Poco/Net/IPAddress.h"
#include "Poco/Activity.h"
#include "Poco/Thread.h"
#include "NICStatus.h"


using Poco::Activity;
using Poco::Thread;


enum NETWORK_STATUS
{
	OFF_LINE = 0,
	ON_LINE,
	DISABLE,
};

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
	Activity<CNetworkStatus>	_activity;
	NETWORK_STATUS				_NetStatus;
	NETWORK_STATUS				_NetStatus_Tmp;
};

