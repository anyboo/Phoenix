#include "stdafx.h"
#include "DVRStreamSocketFactory.h"
#include "DVRStreamSocket.h"
#include <Poco/SingletonHolder.h>
#include <cassert>

DVRStreamSocketFactory::DVRStreamSocketFactory()
{
}


DVRStreamSocketFactory::~DVRStreamSocketFactory()
{
}

namespace
{
	static Poco::SingletonHolder<DVRStreamSocketFactory> sh;
}

DVRStreamSocketFactory& DVRStreamSocketFactory::instance()
{
	return *sh.get();
}

DVRStreamSocket* DVRStreamSocketFactory::get(const std::string& brand)
{
	assert(_pool.find(brand) != _pool.end());
	return _pool[brand];
}