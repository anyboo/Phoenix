#pragma once

#include <map>
#include <string>
#include "DVRSession.h"
#include "DVRConnector.h"
#include <Poco/SharedPtr.h>
#include <Poco/Mutex.h>
#include <Poco/String.h>

namespace DVR {
	class DVR_API DVRSessionFactory
	{
	public:
		static DVRSessionFactory& instance();
		void add(DVRConnector* pIn);
		void remove(const std::string& key);

		DVRSession create(const std::string& key,
			const std::string& connectionString,
			std::size_t timeout = DVRSession::LOGIN_TIMEOUT_DEFAULT);

	private:
		DVRSessionFactory();
		~DVRSessionFactory();
		DVRSessionFactory(const DVRSessionFactory&);
		DVRSessionFactory& operator = (DVRSessionFactory&);

		struct SessionInfo
		{
			int cnt;
			Poco::SharedPtr<DVRConnector> ptrSI;
			SessionInfo(DVRConnector* pSI);
		};

		typedef std::map<std::string, SessionInfo, Poco::CILess> DVRConnectors;
		DVRConnectors	_connectors;
		Poco::FastMutex _mutex;
	};
}

