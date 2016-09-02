#include "DVR/DVRSession.h"
#include "DVR/DVRSessionFactory.h"

namespace DVR {

	DVRSession::DVRSession(Poco::AutoPtr<DVRSessionImpl> ptrImpl) :
		_pImpl(ptrImpl)
	{
		poco_check_ptr(ptrImpl.get());
	}

	DVRSession::DVRSession(const std::string& connector,
		const std::string& connectionString,
		std::size_t timeout)
	{
		DVRSession newSession(DVRSessionFactory::instance().create(connector, connectionString, timeout));
		swap(newSession);
	}

	DVRSession::DVRSession(const DVRSession& other) :
		_pImpl(other._pImpl)
	{

	}

	DVRSession& DVRSession::operator = (const DVRSession& other)
	{
		DVRSession tmp(other);
		swap(tmp);
		return *this;
	}

	DVRSession::~DVRSession()
	{
	}

	void DVRSession::swap(DVRSession& other)
	{
		using std::swap;
		swap(_pImpl, other._pImpl);
	}
}