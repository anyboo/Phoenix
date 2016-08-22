#pragma once
#include <Poco/Net/NetworkInterface.h>

typedef struct IPADDRESSINFO
{
	std::string strIP;
	std::string strSubNet;
	std::string strBroadcast;
}IPADDRESS_INFO;

class CSetIPAddress
{
public:
	CSetIPAddress();
	~CSetIPAddress();

	void SetIPAddress(std::string& strIP, std::string& strSubNet, std::string& strBroadcast);
	IPADDRESS_INFO GetCurIPAddress();
protected:
	void InitNetIF();
private:
	Poco::Net::NetworkInterface     _inft;
};

