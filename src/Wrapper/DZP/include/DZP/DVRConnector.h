#pragma once
#include "DZPLite.h"
#include "DVR/DVRConnector.h"
#include <string>

#define DVR_CONNECTOR_NAME "DZP"

namespace DVR {
namespace DZPLite {
class DZPLite_API DVRConnector : public DVR::DVRConnector
{
public:
	static const std::string KEY;

	DVRConnector();
	~DVRConnector();

	virtual const std::string& name() const;
	virtual Poco::AutoPtr<DVR::DVRSessionImpl> createSession(const std::string& connectionString,
		std::size_t timeout = DVR::DVRSessionImpl::LOGIN_TIMEOUT_DEFAULT);

	static void registerConnector();
	static void unregisterConnector();
};

inline const std::string& DVRConnector::name() const
{
	static const std::string n(DVR_CONNECTOR_NAME);
	return n;
}

}}

struct DZPLite_API DZPLiteConnectorRegistrator
{
	DZPLiteConnectorRegistrator()
	{
		DVR::DZPLite::DVRConnector::registerConnector();
	}

	~DZPLiteConnectorRegistrator()
	{
		try
		{
			DVR::DZPLite::DVRConnector::unregisterConnector();
		}
		catch (...)
		{
			poco_unexpected();
		}
	}
};