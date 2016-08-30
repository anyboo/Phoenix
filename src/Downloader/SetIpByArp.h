#pragma once
#include <set>
#include "pcap.h"

typedef struct arppkt
{
	unsigned short hdtyp;//hd type
	unsigned short protyp;//protocol type
	unsigned char hdsize;//hd length
	unsigned char prosize;//protocol length
	unsigned short op;//op type
	u_char smac[6];//src MAC address
	u_char sip[4];//src IP
	u_char dmac[6];//dest MAC address
	u_char dip[4];//dest IP
}arpp;

class SetIpByArp
{
public:
	SetIpByArp();
	~SetIpByArp();

	bool getDirectDevice(vector<string>& IPs, set<string>& ipList, set<string>& dstList);


protected:
	bool SetArpPacket();
	void GetArpPacket(set<string>& ipList, set<string>& dstList);

private:
	pcap_t *				_adhandle;
	std::vector<string>		_IPs;
};

