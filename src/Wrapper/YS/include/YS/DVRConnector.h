#pragma once
#include "YSLite.h"
#include "DVR/DVRConnector.h"
#include <string>

#define DVR_CONNECTOR_NAME "YS"

namespace DVR {
namespace YSLite {
	class YSLite_API DVRConnector : public DVR::DVRConnector
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

struct YSLite_API YSLiteConnectorRegistrator
{
	YSLiteConnectorRegistrator()
	{
		DVR::YSLite::DVRConnector::registerConnector();
	}

	~YSLiteConnectorRegistrator()
	{
		try
		{
			DVR::YSLite::DVRConnector::unregisterConnector();
		}
		catch (...)
		{
			poco_unexpected();
		}
	}
};

#if !defined(POCO_NO_AUTOMATIC_LIB_INIT)
#if defined(POCO_OS_FAMILY_WINDOWS) && !defined(__GNUC__)
extern "C" const struct YSLite_API YSLiteConnectorRegistrator DvrYSLiteConnectorRegistrator;
#if defined(YSLITE_EXPORTS)
#if defined(_WIN64) || defined(_WIN32_WCE)
#define DVR_YSLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:"#s))
#elif defined(_WIN32)
#define DVR_YSLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:_"#s))
#endif
#else  // !YSLITE_EXPORTS
#if defined(_WIN64) || defined(_WIN32_WCE)
#define DVR_YSLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:"#s))
#elif defined(_WIN32)
#define DVR_YSLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:_"#s))
#endif
#endif // YSLITE_EXPORTS
#else // !POCO_OS_FAMILY_WINDOWS
#define DVR_YSLITE_FORCE_SYMBOL(s) extern "C" const struct YSLiteConnectorRegistrator s;
#endif // POCO_OS_FAMILY_WINDOWS
DVR_YSLITE_FORCE_SYMBOL(DvrYSLiteConnectorRegistrator)
#endif // POCO_NO_AUTOMATIC_LIB_INIT