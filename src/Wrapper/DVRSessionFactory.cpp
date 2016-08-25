#include "stdafx.h"
#include "DVRSessionFactory.h"
#include <cassert>

namespace DVR {

	DVRSessionFactory::DVRSessionFactory()
	{
	}


	DVRSessionFactory::~DVRSessionFactory()
	{
	}

	DVRSessionFactory& DVRSessionFactory::instance()
	{
		static DVRSessionFactory sf;
		return sf;
	}

	void DVRSessionFactory::add(DVRConnector* pIn)
	{
		Poco::FastMutex::ScopedLock lock(_mutex);
		SessionInfo Info(pIn);
		std::pair<DVRConnectors::iterator, bool> res =
			_connectors.insert(std::make_pair(pIn->name(), Info));
		if (!res.second) res.first->second.cnt++;
	}

	void DVRSessionFactory::remove(const std::string& key)
	{
		Poco::FastMutex::ScopedLock lock(_mutex);
		DVRConnectors::iterator it = _connectors.find(key);
		poco_assert(_connectors.end() != it);

		--(it->second.cnt);
		if (it->second.cnt == 0) _connectors.erase(it);
	}

	DVRSession DVRSessionFactory::create(const std::string& key,
		const std::string& connectionString,
		std::size_t timeout)
	{
		Poco::FastMutex::ScopedLock lock(_mutex);
		DVRConnectors::iterator it = _connectors.find(key);
		poco_assert(_connectors.end() != it);

		return DVRSession(it->second.ptrSI->createSession(connectionString, timeout));
	}

	DVRSessionFactory::SessionInfo::SessionInfo(DVRConnector* pSI) :
		cnt(1),
		ptrSI(pSI)
	{
	}

}