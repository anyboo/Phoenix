#pragma once
#include "Scene.h"
#include <Poco/Net/NetworkInterface.h>

typedef struct IPADDRESSINFO
{
	std::string strIP;
	std::string strSubNet;
	std::string strBroadcast;

}IPADDRESS_INFO;

class SCENE_API CSetIPAddress
{
public:
	CSetIPAddress();
	~CSetIPAddress();

	IPADDRESS_INFO GetCurIPAddress();
	bool setNetConfig(const std::string& sIP, const std::string& sMask, const std::string& sGate);

protected:
	void InitNetIF();

private:
	Poco::Net::NetworkInterface     _inft;
};

