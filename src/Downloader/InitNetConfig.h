#pragma once
#include <Poco/Net/NetworkInterface.h>
#include "Scene/SetIpByArp.h"



class CInitNetConfig
{
public:
	CInitNetConfig();
	~CInitNetConfig();

protected:
	void GetLocalInterfc();
	void SetIp();
};

