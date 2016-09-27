#include "DVR/DVRSession.h"

#include "HK/DVRSessionImpl.h"
#include "HK/DVRConnector.h"
#include "HK/DVRStatementImpl.h"

#include <sstream>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTime.h>
#include <Poco/DateTimeParser.h>




namespace DVR {
	namespace HKLite {

DVRSessionImpl::DVRSessionImpl(const std::string& deviceLocation,
	std::size_t timeout):
	DVR::AbstractSessionImpl<DVRSessionImpl>(deviceLocation, timeout),
	_connector(DVRConnector::KEY),
	_timeout(timeout),//common use by DVR::DVRSessionImpl
	_connected(false),
	_addr(deviceLocation),
	_handle(0)
{
	setLoginTimeout(_timeout);
	setProperty("handle", _handle);
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
	
	Utility::DVRINFO info;
	int error = 0;
	memset(&info, 0, sizeof(info));

	_handle = Utility::login(_addr, user, password, info);

	if (_handle <= 0) Utility::throwException(_handle);
	
	_connected = true;
}

void DVRSessionImpl::logout()
{
	int rc = Utility::logout(_handle);
	
	if (rc != Utility::success ) 
		Utility::throwException(_handle);

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
	int rc = Utility::setTimeOut(timeout, TRY_TIMES);
	
	if (rc != Utility::success) Utility::throwException(_handle);
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

void DVRSessionImpl::list()
{

}

void DVRSessionImpl::download()
{

}

void DVRSessionImpl::playback()
{

}

void DVRSessionImpl::abort()
{

}


// NOTE: Utility::dvrHandle() has been moved here from Utility.cpp
// as a workaround for a failing AnyCast with Clang.
// for a discussion.

Utility::HANDLE Utility::dvrHandle(const DVRSession& session)
{
	return Poco::AnyCast<Utility::HANDLE>(session.getProperty("handle"));
}

}}