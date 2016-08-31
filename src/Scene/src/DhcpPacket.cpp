#include "Scene/DhcpPacket.h"
#include "Poco/ByteOrder.h"

using Poco::Net::NetworkInterface;

CDhcpPacket::CDhcpPacket() :
_opcode(1), _htype(1), _hlen(6), _hops(0), _xid(0x3903F326), _secs(0), _flags(0x0080),
_ciaddr(0), _yiaddr(0), _siaddr(0), _giaddr(0), _magic_cookie(0x63538263)
{
	SetDiscoverData();
}


CDhcpPacket::~CDhcpPacket()
{
}

void CDhcpPacket::SetMacAddress(std::string& NetworkCardName)
{
	NetworkInterface _inft = NetworkInterface::forName(NetworkCardName);
	_mac = _inft.macAddress();
}

void CDhcpPacket::setPacket(Poco::UInt8 *packet)
{
	Dhcp_packet *p = (Dhcp_packet*)packet;
	memcpy(p->chaddr, _mac.data(), _mac.size());

	p->opcode = _opcode;
	p->htype = _htype;
	p->hlen = _hlen;
	p->hops = _hops;
	p->xid = _xid;
	p->secs = _secs;
	p->flags = _flags;
	p->ciaddr = _ciaddr;
	p->yiaddr = _yiaddr;
	p->siaddr = _siaddr;
	p->giaddr = _giaddr;
	p->magic_cookie = _magic_cookie;
	memcpy(p->bp_options, _Toptions, 256);

}


void CDhcpPacket::SetDiscoverData()
{
	memset(_Toptions, 0, 256);
	Poco::UInt8 DCoption[4] = { 0x35, 0x01, 0x01, 0xff };
	memcpy(_Toptions, DCoption, 4);
}

void CDhcpPacket::SetRequestData(Poco::UInt8* Src)
{
	memset(_Toptions, 0, 256);
	memcpy(_Toptions, Src, 256);
}

