#include "DVR/DVRSession.h"

#include "DZP/DVRSessionImpl.h"
#include "DZP/DVRConnector.h"
#include "DZP/DVRStatementImpl.h"

#include <sstream>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTime.h>
#include <Poco/DateTimeParser.h>
#include "netsdk.h"




namespace DVR {
namespace DZPLite {

DVRSessionImpl::DVRSessionImpl(const std::string& deviceLocation,
	std::size_t timeout):
	DVR::AbstractSessionImpl<DVRSessionImpl>(deviceLocation, timeout),
	_connector(DVRConnector::KEY),
	_timeout(timeout),//common use by DVR::DVRSessionImpl
	_connected(false),
	_addr(deviceLocation),
	_handle(0),
	_channels(0)
{
	setLoginTimeout(_timeout);
	setProperty("handle", _handle);
	setProperty("channels", _channels);
}

DVRSessionImpl::~DVRSessionImpl()
{
	try
	{
		logout();
	}
	catch (...)
	{
		poco_unexpected();
	}
}

void DVRSessionImpl::login(const std::string& user, const std::string& password)
{
	std::string host = _addr.host().toString();
	unsigned short port = _addr.port();
	
	_handle = Utility::login(_addr, user, password);
	poco_assert(_handle > 0);
	if (_handle <= 0)
	{
		Utility::throwException(Utility::lastError(), "login failed!");
	}
	
	setChannels();
	_connected = true;
}

void DVRSessionImpl::setChannels()
{
	DeviceInfo info = { 0 };
	Utility::readDeviceInfo(info);
	_channels = info.byChanNum;
}

void DVRSessionImpl::logout()
{
	if (!Utility::logout(_handle))
	{
		Utility::throwException(_handle);
	}
		
	_handle = 0;
	_connected = false;
}

bool DVRSessionImpl::isLoggedIn()const
{	
	poco_assert(_handle == 0);
	return _connected;
}

void DVRSessionImpl::setLoginTimeout(std::size_t timeout)
{
	Utility::setTimeOut(timeout, TRY_TIMES);
}

std::size_t DVRSessionImpl::getLoginTimeout() const
{
	return _timeout;
}

DVR::DVRStatementImpl* DVRSessionImpl::createStatementImpl()
{
	poco_check_ptr(_handle);
	return new DVRStatementImpl(*this, _handle);
}

// NOTE: Utility::dvrHandle() has been moved here from Utility.cpp
// as a workaround for a failing AnyCast with Clang.
// for a discussion.

Utility::HANDLE Utility::dvrHandle(const DVRSession& session)
{
	return Poco::AnyCast<Utility::HANDLE>(session.getProperty("handle"));
}

}}