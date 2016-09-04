#pragma once
#include "Scene.h"
#include "SetIPAddress.h"

class SCENE_API ARPClient
{
public:
	ARPClient();
	~ARPClient();

	bool Request(const std::string& NetworkCardName);
protected:
	bool SetIpByArp(const std::string& NetworkCardName);

private:
	CSetIPAddress		_setip;
};

