#pragma once
#include <set>
#include <vector>
#include "pcap.h"

class ARPFindSegment
{
public:
	ARPFindSegment();
	~ARPFindSegment();

	void GetSearchBackIPs(const std::string& NetworkCardName, std::set<std::string>& ipList, std::set<std::string>& dstList);

	bool GetArpHandle();
protected:
	void GetLocalIPs(const std::string& NetworkCardName, std::vector<std::string>& IPs);

private:
	pcap_t*			_handle;//define get packet handle
};

