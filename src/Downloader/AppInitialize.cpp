#include "stdafx.h"
#include "AppInitialize.h"

CAppInitialize::CAppInitialize()
{
	_netStatus.start();
}

CAppInitialize::~CAppInitialize()
{
	_netStatus.stop();
}