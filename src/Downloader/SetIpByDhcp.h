#pragma once
#include "DhcpPacket.h"
#include "Poco/Net/SocketAddress.h"

class SetIpByDhcp
{
public:
	SetIpByDhcp();
	~SetIpByDhcp();
	void GetUseableNetConfig(std::string& ip, std::string& sMsk, std::string& sGate);

protected:
	std::string GetIPAddress(Poco::UInt32 ipAddr);
	void GetMaskAndGate(Poco::UInt8* option, std::string& sMask, std::string& sGate);
	void ConnectUint8(Poco::UInt8* Des, Poco::UInt8* Src, int size);

	void MakeRequestPacket(Poco::UInt8* packet);
private:
	int _timeout;
	int _tmpSize;
	CDhcpPacket		_packet;
	Poco::Net::NetworkInterface     _inft;
	mutable Poco::Net::SocketAddress::Family _family;
};

