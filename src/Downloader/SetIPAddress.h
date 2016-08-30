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

	IPADDRESS_INFO GetCurIPAddress();
	bool setNetConfig(const string& sIP, const string& sMask, const string& sGate);

protected:
	void InitNetIF();

private:
	Poco::Net::NetworkInterface     _inft;
};

