#pragma once
#include "DHLite.h"
#include "DVR/DVRConnector.h"
#include <string>

#define DVR_CONNECTOR_NAME "DH"

namespace DVR {
	namespace DHLite {
		class DHLite_API DVRConnector : public DVR::DVRConnector
		{
		public:
			static const std::string KEY;

			DVRConnector();
			~DVRConnector();

			const std::string& name() const;
			Poco::AutoPtr<DVR::DVRSessionImpl> createSession(const std::string& connectionString,
				std::size_t timeout = DVR::DVRSessionImpl::LOGIN_TIMEOUT_DEFAULT);

			static void registerConnector();
			static void unregisterConnector();
		};

		inline const std::string& DVRConnector::name() const
		{
			static const std::string n(DVR_CONNECTOR_NAME);
			return n;
		}

	}
}

struct DHLite_API DHLiteConnectorRegistrator
{
	DHLiteConnectorRegistrator()
	{
		DVR::DHLite::DVRConnector::registerConnector();
	}

	~DHLiteConnectorRegistrator()
	{
		try
		{
			DVR::DHLite::DVRConnector::unregisterConnector();
		}
		catch (...)
		{
			poco_unexpected();
		}
	}
};

#if !defined(POCO_NO_AUTOMATIC_LIB_INIT)
#if defined(POCO_OS_FAMILY_WINDOWS) && !defined(__GNUC__)
extern "C" const struct DHLite_API DHLiteConnectorRegistrator DvrDHLiteConnectorRegistrator;
#if defined(DHLITE_EXPORTS)
#if defined(_WIN64) || defined(_WIN32_WCE)
#define DVR_DHLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:"#s))
#elif defined(_WIN32)
#define DVR_DHLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:_"#s))
#endif
#else  // !DHLITE_EXPORTS
#if defined(_WIN64) || defined(_WIN32_WCE)
#define DVR_DHLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:"#s))
#elif defined(_WIN32)
#define DVR_DHLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:_"#s))
#endif
#endif // DHLITE_EXPORTS
#else // !POCO_OS_FAMILY_WINDOWS
#define DVR_DHLITE_FORCE_SYMBOL(s) extern "C" const struct DHLiteConnectorRegistrator s;
#endif // POCO_OS_FAMILY_WINDOWS
DVR_DHLITE_FORCE_SYMBOL(DvrDHLiteConnectorRegistrator)
#endif // POCO_NO_AUTOMATIC_LIB_INIT