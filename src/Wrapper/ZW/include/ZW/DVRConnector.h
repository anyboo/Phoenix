#pragma once
#include "ZWLite.h"
#include "DVR/DVRConnector.h"
#include <string>

#define DVR_CONNECTOR_NAME "ZW"

namespace DVR {
namespace ZWLite {
		class ZWLite_API DVRConnector : public DVR::DVRConnector
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

struct ZWLite_API ZWLiteConnectorRegistrator
{
	ZWLiteConnectorRegistrator()
	{
		DVR::ZWLite::DVRConnector::registerConnector();
	}

	~ZWLiteConnectorRegistrator()
	{
		try
		{
			DVR::ZWLite::DVRConnector::unregisterConnector();
		}
		catch (...)
		{
			poco_unexpected();
		}
	}
};

#if !defined(POCO_NO_AUTOMATIC_LIB_INIT)
#if defined(POCO_OS_FAMILY_WINDOWS) && !defined(__GNUC__)
extern "C" const struct ZWLite_API ZWLiteConnectorRegistrator DvrZWLiteConnectorRegistrator;
#if defined(ZWLITE_EXPORTS)
#if defined(_WIN64) || defined(_WIN32_WCE)
#define DVR_ZWLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:"#s))
#elif defined(_WIN32)
#define DVR_ZWLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:_"#s))
#endif
#else  // !ZWLITE_EXPORTS
#if defined(_WIN64) || defined(_WIN32_WCE)
#define DVR_ZWLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:"#s))
#elif defined(_WIN32)
#define DVR_ZWLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:_"#s))
#endif
#endif // ZWLITE_EXPORTS
#else // !POCO_OS_FAMILY_WINDOWS
#define DVR_ZWLITE_FORCE_SYMBOL(s) extern "C" const struct ZWLiteConnectorRegistrator s;
#endif // POCO_OS_FAMILY_WINDOWS
DVR_ZWLITE_FORCE_SYMBOL(DvrZWLiteConnectorRegistrator)
#endif // POCO_NO_AUTOMATIC_LIB_INIT