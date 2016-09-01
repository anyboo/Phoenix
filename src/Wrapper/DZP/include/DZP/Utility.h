#pragma once
#include "DZPLite.h"
#include "DVR/DVRSession.h"
#include <Poco/DateTime.h>
#include <string>

extern "C"
{
	typedef struct _H264_DVR_DEVICEINFO dvrinfo;
	typedef long dvrhandle;
	typedef struct SDK_SYSTEM_TIME sdktime;
}


namespace DVR {
namespace DZPLite {

class DZPLite_API Utility
{
public:
	~Utility();

	static dvrhandle* dvrHandle(const DVRSession& session);
	static std::string lastError(dvrhandle* pDvr);
	static std::string lastError(const DVRSession& session);
	static void throwException(int rc, const std::string& addErrMsg = std::string());
	static Poco::DateTime toDateTime(const sdktime& time);
private:
	Utility();
	Utility(const Utility&);
	Utility& operator = (const Utility&);
};

}}
