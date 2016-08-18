#pragma once

#include "NetworkStatus.h"
#include "NICStatus.h"

class CAppInitialize
{
public:
	CAppInitialize::CAppInitialize();

	CAppInitialize::~CAppInitialize();
	
private:
	CNetworkStatus     _netStatus;

};

