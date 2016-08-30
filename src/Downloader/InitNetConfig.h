#pragma once
#include <Poco/Net/NetworkInterface.h>
#include "SetIpByArp.h"
#include "SetIpByDhcp.h"


class CInitNetConfig
{
public:
	CInitNetConfig();
	~CInitNetConfig();

protected:
	void GetLocalInterfc();
	void SetIp();
	void OnSetIpByDhcp();
	bool IsOnLine();	

private:
	Poco::Net::NetworkInterface     _inft;
	SetIpByDhcp						_dhcp;
	mutable Poco::Net::SocketAddress::Family _family;
};

