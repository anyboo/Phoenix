#pragma once
#include <string>
#include "DVR/DVR.h"
#include <Poco/AutoPtr.h>
#include "DVR/DVRSessionImpl.h"

namespace DVR {
	class DVR_API DVRConnector
	{
	public:
		DVRConnector();
		virtual ~DVRConnector();
		virtual const std::string& name() const = 0;
		virtual Poco::AutoPtr<DVRSessionImpl> createSession(const std::string& connectionString,
			std::size_t timeout = DVRSessionImpl::LOGIN_TIMEOUT_DEFAULT) = 0;
	};
}

