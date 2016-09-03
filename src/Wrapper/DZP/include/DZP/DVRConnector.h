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

#if !defined(POCO_NO_AUTOMATIC_LIB_INIT)
	#if defined(POCO_OS_FAMILY_WINDOWS) && !defined(__GNUC__)
		extern "C" const struct DZPLite_API DZPLiteConnectorRegistrator DvrDZPLiteConnectorRegistrator;
		#if defined(DZPLITE_EXPORTS)
			#if defined(_WIN64) || defined(_WIN32_WCE)
				#define DVR_DZPLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:"#s))
			#elif defined(_WIN32)
				#define DVR_DZPLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/export:_"#s))
			#endif
		#else  // !DZPLITE_EXPORTS
			#if defined(_WIN64) || defined(_WIN32_WCE)
				#define DVR_DZPLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:"#s))
			#elif defined(_WIN32)
				#define DVR_DZPLITE_FORCE_SYMBOL(s) __pragma(comment (linker, "/include:_"#s))
			#endif
		#endif // DZPLITE_EXPORTS
	#else // !POCO_OS_FAMILY_WINDOWS
		#define DVR_DZPLITE_FORCE_SYMBOL(s) extern "C" const struct DZPLiteConnectorRegistrator s;
	#endif // POCO_OS_FAMILY_WINDOWS
	DVR_DZPLITE_FORCE_SYMBOL(DvrDZPLiteConnectorRegistrator)
#endif // POCO_NO_AUTOMATIC_LIB_INIT