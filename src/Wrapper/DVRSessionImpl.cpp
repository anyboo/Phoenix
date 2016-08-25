#include "stdafx.h"
#include "DVRSessionImpl.h"

namespace DVR 
{
	DVRSessionImpl::DVRSessionImpl()
	{
	}


	DVRSessionImpl::~DVRSessionImpl()
	{
	}


	void DVRSessionImpl::setLoginTimeout(std::size_t timeout)
	{
		_loginTimeout = timeout;
	}

	std::size_t DVRSessionImpl::getLoginTimeout() const
	{
		return _loginTimeout;
	}
	void DVRSessionImpl::reconnect()
	{
		logout();
		login();
	}
}