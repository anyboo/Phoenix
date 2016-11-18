#pragma once
#include "Scene.h"
#include <Poco/Net/NetworkInterface.h>

typedef struct IPADDRESSINFO
{
	std::string strIP;
	std::string strSubNet;	

}IPADDRESS_INFO;



class SCENE_API CSetIPAddress
{
public:
	CSetIPAddress();
	~CSetIPAddress();

	void GetCurIPAddress(std::vector<IPADDRESS_INFO>& ipList, std::vector<std::string>& gatewayList);
	bool setNetConfig(const std::string& sIP, const std::string& sMask, const std::string& sGate);
	void GetLocalNetCar(std::string AdapterName, std::vector<IPADDRESSINFO>& IPList, std::vector<std::string>& Gatewayl);

protected:
	void InitNetIF();

private:
	Poco::Net::NetworkInterface     _inft;
};

