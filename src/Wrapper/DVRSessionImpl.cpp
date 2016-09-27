#include "DVR/DVRSessionImpl.h"

namespace DVR 
{
	DVRSessionImpl::DVRSessionImpl(const std::string& connectionString,
		std::size_t timeout):
		/*_connectionString(connectionString),*/
		_loginTimeout(timeout)

	{
		_connectionString = connectionString;
	}


	DVRSessionImpl::~DVRSessionImpl()
	{
	}

	void DVRSessionImpl::reconnect()
	{
		logout();
		login();
	}
}