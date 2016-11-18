#include "Scene/DHCPClient.h"
#include "Scene/SetIPAddress.h"

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/NTPEventArgs.h"
#include "Poco/Net/NTPClient.h"
#include "Poco/ByteOrder.h"
#include "Poco/Net/ICMPClient.h"


using Poco::Exception;
using Poco::Net::IPAddress;
using Poco::Net::NetworkInterface;
using Poco::ByteOrder;
using Poco::Net::SocketAddress;
using Poco::Net::DatagramSocket;
using Poco::Net::NTPEventArgs;

DHCPClient::DHCPClient()
:_family(IPAddress::IPv4), _timeout(6000000), _tmpSize(0)
{
}


DHCPClient::~DHCPClient()
{
}

bool DHCPClient::Request(std::string& NetworkCardName)
{
	_packet.SetMacAddress(NetworkCardName);
	return SetNetConfig();
}

bool DHCPClient::SetNetConfig()
{
	SocketAddress SerVerAddr(IPAddress::broadcast(), 67);
	SocketAddress ClientAddr(IPAddress::wildcard(), 68);
	DatagramSocket ntpSocket(_family);
	ntpSocket.setReceiveTimeout(_timeout);
	ntpSocket.setBroadcast(true);
	ntpSocket.bind(ClientAddr);

	NTPEventArgs eventArgs(SerVerAddr);

	Poco::UInt8 p[1024];
	memset(&p, 0, 1024);
	_packet.setPacket(&p[0]);

	int disvocer_size = ntpSocket.sendTo(p, 512, SerVerAddr);
	try
	{
		int offer_size = ntpSocket.receiveFrom(p, sizeof(p)-1, ClientAddr);
	}
	catch (Poco::TimeoutException &)
	{
		// ignore
	}

	MakeRequestPacket(p);
	memset(&p, 0, 1024);
	_packet.setPacket(&p[0]);
	int request_size = ntpSocket.sendTo(p, 512, SerVerAddr);
	try
	{
		int ack_size = ntpSocket.receiveFrom(p, sizeof(p)-1, ClientAddr);
	}
	catch (Poco::TimeoutException &)
	{
		// ignore
	}

	Poco::UInt8 ack_Info[256] = { 0 };
	Dhcp_packet* ack_packet = (Dhcp_packet*)p;
	memcpy(ack_Info, ack_packet->bp_options, 256);

	std::string ip = GetIPAddress(ack_packet->yiaddr);
	std::string sMsk, sGate;
	GetMaskAndGate(ack_Info, sMsk, sGate);

	CSetIPAddress setip;
	Poco::Net::ICMPClient ic(_family);

	setip.setNetConfig(ip, sMsk, sGate);
	//int a = ic.ping(ip, 3);
	//if (a != 0)
	//	return true;	
	return true;
}

void DHCPClient::MakeRequestPacket(Poco::UInt8* packet)
{
	Dhcp_packet* dp = (Dhcp_packet*)packet;
	Poco::UInt8 option[256] = { 0 };
	Poco::UInt8 msg_type[3] = { 0x35, 0x01, 0x03 };
	Poco::UInt8 msg_ip[2] = { 0x32, 0x04 };
	Poco::UInt8 ipAddr[4] = { 0 };
	memcpy(ipAddr, &dp->yiaddr, 4);
	int size = sizeof(msg_type);
	ConnectUint8(option, msg_type, sizeof(msg_type));
	ConnectUint8(option, msg_ip, sizeof(msg_ip));
	ConnectUint8(option, ipAddr, sizeof(ipAddr));
	option[_tmpSize] = { 0xff };

	_packet.SetRequestData(option);
}

void DHCPClient::ConnectUint8(Poco::UInt8* Des, Poco::UInt8* Src, int size)
{
	Poco::UInt8 tmp[64] = { 0 };
	memcpy(tmp, Src, size);

	for (int i = _tmpSize; i < size + _tmpSize; i++)
	{
		Des[i] = tmp[i - _tmpSize];
	}

	_tmpSize += size;
}

void DHCPClient::GetMaskAndGate(Poco::UInt8* option, std::string& sMask, std::string& sGate)
{
	int nextLen = 256;
	char subnetmask[16] = { 0 };
	char gateway[16] = { 0 };
	Poco::UInt8 optionTmp[256] = { 0 };
	memcpy(optionTmp, option, 256);
	while (nextLen > 0)
	{
		int MsgType = optionTmp[0];
		if (MsgType != 1 && MsgType != 3)
		{
			int Len = optionTmp[1];
			nextLen = nextLen - Len - 2;
			for (int i = 0; i < nextLen; i++)
			{
				optionTmp[i] = optionTmp[i + Len + 2];
			}
		}
		else if (MsgType == 1)
		{
			sprintf_s(subnetmask, "%d.%d.%d.%d", optionTmp[2], optionTmp[3], optionTmp[4], optionTmp[5]);
			sMask = std::string(subnetmask);
			nextLen = nextLen - 6;
			for (int j = 0; j < nextLen; j++)
			{
				optionTmp[j] = optionTmp[j + 6];
			}
		}
		else if (MsgType == 3)
		{
			sprintf_s(gateway, "%d.%d.%d.%d", optionTmp[2], optionTmp[3], optionTmp[4], optionTmp[5]);
			sGate = std::string(gateway);
			nextLen = nextLen - 6;
			for (int k = 0; k < nextLen; k++)
			{
				optionTmp[k] = optionTmp[k + 6];
			}
		}
		else if (!sMask.empty() && !sGate.empty())
		{
			break;
		}
	}
}

std::string DHCPClient::GetIPAddress(Poco::UInt32 ipAddr)
{
	Poco::UInt32 ClientIP = ByteOrder::toNetwork(ipAddr);

	char str[30] = { 0 };
	const char* tmpIP = itoa(ClientIP, str, 16);
	std::string strIP(tmpIP);
	std::string str1 = strIP.substr(0, 2);
	std::string str2 = strIP.substr(2, 2);
	std::string str3 = strIP.substr(4, 2);
	std::string str4 = strIP.substr(6, 2);

	char *stop;
	memset(str, 0, 30);
	sprintf_s(str, "%d.%d.%d.%d", strtol(str1.c_str(), &stop, 16), strtol(str2.c_str(), &stop, 16), \
		strtol(str3.c_str(), &stop, 16), strtol(str4.c_str(), &stop, 16));

	return std::string(str);
}