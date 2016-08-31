#pragma once
#include "Scene.h"
#include <Poco/Foundation.h>
#include <Poco/Net/Net.h>
#include <vector>
#include <Poco/Net/NetworkInterface.h>


typedef struct DhcpPacket
{
	Poco::UInt8			  opcode;
	Poco::UInt8			  htype;
	Poco::UInt8			  hlen;
	Poco::UInt8			  hops;
	Poco::UInt32		  xid;
	Poco::UInt16		  secs;
	Poco::UInt16		  flags;
	Poco::UInt32		  ciaddr;
	Poco::UInt32		  yiaddr;
	Poco::UInt32		  siaddr;
	Poco::UInt32		  giaddr;
	Poco::UInt8			  chaddr[16];
	char				  bp_sname[64];
	char				  bp_file[128];
	Poco::UInt32		  magic_cookie;
	Poco::UInt8			  bp_options[256];
} Dhcp_packet;

class CDhcpPacket
{
public:

	CDhcpPacket();
	~CDhcpPacket();

	void setPacket(Poco::UInt8 *packet);
	void SetMacAddress(std::string& NetworkCardName);

	void SetDiscoverData();
	void SetRequestData(Poco::UInt8* Src);

private:
	Poco::UInt8			_opcode;
	Poco::UInt8			_htype;
	Poco::UInt8			_hlen;
	Poco::UInt8			_hops;
	Poco::UInt32		_xid;
	Poco::UInt16		_secs;
	Poco::UInt16		_flags;
	Poco::UInt32		_ciaddr;
	Poco::UInt32        _yiaddr;
	Poco::UInt32        _siaddr;
	Poco::UInt32        _giaddr;
	Poco::UInt32        _magic_cookie;

	Poco::UInt8 _Toptions[256];
	Poco::Net::NetworkInterface::MACAddress _mac;
};

