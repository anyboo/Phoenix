#include "DZP/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/Exception.h>
#include <Poco/Path.h>
#include "netsdk.h"

extern "C"
{
	typedef long (CALL_METHOD *FnType)();
	typedef long (CALL_METHOD *FnParamType)(long);

	typedef long (CALL_METHOD *Fn2ParamTypeA)(long, long);
	typedef long (CALL_METHOD *Fn2ParamTypeB)(long, float);
	typedef long (CALL_METHOD *Fn2ParamTypeC)(void*, unsigned long);

	typedef long (CALL_METHOD *Fn3ParamType)(long, long, long);

	typedef long (CALL_METHOD *Fn4ParamType)(long, void*, void*, long);
	typedef long (CALL_METHOD *Fn5ParamTypeA)(long, long, unsigned char*, long, long);
	typedef long (CALL_METHOD *Fn5ParamTypeB)(long, void*, void*, void*, long);

	typedef long (CALL_METHOD *Fn6ParamTypeA)(long, void*, char*, void*, long, void*);
	typedef long (CALL_METHOD *Fn6ParamTypeB)(long, void*, void*, int, int*, int);

	typedef long (CALL_METHOD *Fn7ParamTypeA)(char*,unsigned short, char*, char*,void*, int*, int);
	typedef long (CALL_METHOD *Fn7ParamTypeB)(long,void*, char*, bool, void*, long, void*);
}

namespace DVR {
namespace DZPLite {

const int Utility::success = SDK_RET_CODE::H264_DVR_SUCCESS;
Poco::SharedLibrary Utility::_dependency("sdk\\DZP\\StreamReader.dll");
Poco::SharedLibrary Utility::_library("sdk\\DZP\\NetSDK.dll");
Poco::Mutex Utility::_mutex;
Utility::Utility()
{	

}


Utility::~Utility()
{	
}

void Utility::Init()
{
	{
		Poco::Mutex::ScopedLock lock(_mutex);
		static Utility u;
	}

	std::string fn("H264_DVR_Init");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn2ParamTypeC pFn = (Fn2ParamTypeC)Utility::_library.getSymbol(fn);
		int rc = pFn(0, 0);
		if (Utility::success != rc) poco_unexpected();
	}	
}

void Utility::Cleanup()
{
	std::string fn("H264_DVR_Cleanup");
	if (Utility::_library.hasSymbol(fn))
	{
		FnType pFn = (FnType)Utility::_library.getSymbol(fn);
		int rc = pFn();
		if (Utility::success != rc) poco_unexpected();
	}
}

Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& address, const std::string& user, const std::string& password)
{
	std::string fn("H264_DVR_Login");
	H264_DVR_DEVICEINFO OutDev;
	if (Utility::_library.hasSymbol(fn))
	{
		Fn7ParamTypeA pFn = (Fn7ParamTypeA)Utility::_library.getSymbol(fn);
		std::string ip = address.host().toString();
		unsigned short port = address.port();
		int nError = 0;
		return pFn((char*)ip.c_str(), port, (char*)user.c_str(), (char*)password.c_str(), &OutDev, &nError, TCPSOCKET);
	}

	return 0;
}

bool Utility::logout(Utility::HANDLE handle)
{
	std::string fn("H264_DVR_Logout");
	if (Utility::_library.hasSymbol(fn))
	{
		FnParamType pFn = (FnParamType)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle));
	}
	
	return false;
}

bool Utility::readDeviceInfo(DeviceInfo& info)
{
	return true;
}

void Utility::setTimeOut(std::size_t timeout, std::size_t times)
{
	std::string fn("H264_DVR_SetConnectTime");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn2ParamTypeA pFn = (Fn2ParamTypeA)Utility::_library.getSymbol(fn);
		int rc = pFn(timeout, times);
		if (Utility::success != rc) poco_unexpected();
	}
}

bool Utility::readStream(Utility::HANDLE handle, Record& data, const std::string& newname)
{
	std::string fn("H264_DVR_GetFileByName");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn6ParamTypeA pFn = (Fn6ParamTypeA)Utility::_library.getSymbol(fn);
		Poco::Path p(newname);
		std::string path = p.parent().toString();
		return (Utility::success == pFn(handle, &data, (char*)path.c_str(), nullptr, 0, nullptr));
	}
	return false;
}

bool Utility::readStream(Utility::HANDLE handle, Condition& time, const std::string& newname, bool merge)
{
	std::string fn("H264_DVR_GetFileByTime");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn7ParamTypeB pFn = (Fn7ParamTypeB)Utility::_library.getSymbol(fn);
		Poco::Path p(newname);
		std::string path = p.parent().toString();
		return (Utility::success == pFn(handle, &time, (char*)path.c_str(), false, nullptr, 0, nullptr));
	}
	return false;
}

bool Utility::closeStream(Utility::HANDLE handle)
{
	std::string fn("H264_DVR_StopGetFile");
	if (Utility::_library.hasSymbol(fn))
	{
		FnParamType pFn = (FnParamType)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle));
	}
	return false;
}

bool Utility::playStream(Utility::HANDLE handle, const Record& record)
{
	std::string fn("H264_DVR_PlayBackByName");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn5ParamTypeB pFn = (Fn5ParamTypeB)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle, (void*)(&record), nullptr, nullptr, 0));
	}
	return false;
}

bool Utility::playStream(Utility::HANDLE handle, const Condition& time)
{
	std::string fn("H264_DVR_PlayBackByTime");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn5ParamTypeB pFn = (Fn5ParamTypeB)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle, (void*)(&time), nullptr, nullptr, 0));
	}
	return false;
}

bool Utility::stopStream(Utility::HANDLE handle)
{
	std::string fn("H264_DVR_StopPlayBack");
	if (Utility::_library.hasSymbol(fn))
	{
		FnParamType pFn = (FnParamType)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle));
	}
	return false;
}

bool Utility::seek(Utility::HANDLE handle, int pos)
{
	std::string fn("H264_DVR_PlayBackControl");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn3ParamType pFn = (Fn3ParamType)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle, ACTION::SDK_PLAY_BACK_SEEK, pos));
	}
	return false;
}

bool Utility::play(Utility::HANDLE handle)
{
	std::string fn("H264_DVR_PlayBackControl");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn3ParamType pFn = (Fn3ParamType)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle, ACTION::SDK_PLAY_BACK_CONTINUE, 0));
	}
	return 0;
}

bool Utility::pause(Utility::HANDLE handle)
{
	std::string fn("H264_DVR_PlayBackControl");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn3ParamType pFn = (Fn3ParamType)Utility::_library.getSymbol(fn);
		return (Utility::success == pFn(handle, ACTION::SDK_PLAY_BACK_PAUSE, 0));
	}
	return false;
}

size_t Utility::findStream(Utility::HANDLE handle, const Condition& cond, Record& record, int recordCount)
{
	std::string fn("H264_DVR_FindFile");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn6ParamTypeB pFn = (Fn6ParamTypeB)Utility::_library.getSymbol(fn);
		int count = 0;
		int timeout = 5000;
		if (Utility::success != pFn(handle, (void*)&cond, (void*)&record, recordCount, &count, timeout))
			throwException(lastError(), "H264_DVR_FindFile failed!");
		return count;
	}
	return 0;
}

size_t Utility::findStream(Utility::HANDLE handle, const Time& time, Result& result)
{
	std::string fn("H264_DVR_FindFileByTime");
	if (Utility::_library.hasSymbol(fn))
	{
		Fn4ParamType pFn = (Fn4ParamType)Utility::_library.getSymbol(fn);
		int timeout = 10000;
		if (Utility::success != pFn(handle, (void*)&time, (void*)&result, timeout))
			throwException(lastError(), "H264_DVR_FindFileByTime failed!");
	}
	return 0;
}

long Utility::lastError()
{
	std::string fn("H264_DVR_GetLastError");
	if (Utility::_library.hasSymbol(fn))
	{
		FnType pFn = (FnType)Utility::_library.getSymbol(fn);
		return pFn();
	}
	return 0;
}

void Utility::throwException(long rc, const std::string& addErrMsg)
{
	switch(rc){
		case H264_DVR_NOPOWER:
		case H264_DVR_PASSWORD_NOT_VALID:
		case H264_DVR_LOGIN_USER_NOEXIST:
		case H264_DVR_USER_LOCKED:
		case H264_DVR_USER_IN_BLACKLIST:
		case H264_DVR_USER_HAS_USED:
		case H264_DVR_USER_NOT_LOGIN:
		case H264_DVR_CONNECT_DEVICE_ERROR:
		case H264_DVR_ACCOUNT_INPUT_NOT_VALID:
		case H264_DVR_ACCOUNT_OVERLAP:
		case H264_DVR_ACCOUNT_OBJECT_NONE:
		case H264_DVR_ACCOUNT_OBJECT_NOT_VALID:
		case H264_DVR_ACCOUNT_OBJECT_IN_USE:
		case H264_DVR_ACCOUNT_SUBSET_OVERLAP:
		case H264_DVR_ACCOUNT_PWD_NOT_VALID:
		case H264_DVR_ACCOUNT_PWD_NOT_MATCH:
		case H264_DVR_ACCOUNT_RESERVED:
		case H264_DVR_CTRL_PAUSE_ERROR:
		case H264_DVR_SDK_NOTFOUND:
		case H264_DVR_CFG_NOT_ENABLE:
		case H264_DVR_DECORD_FAIL:
		case H264_DVR_SDK_NOTVALID:
		case H264_DVR_NO_INIT:
		case H264_DVR_ILLEGAL_PARAM:
		case H264_DVR_INVALID_HANDLE:
		case H264_DVR_SDK_UNINIT_ERROR:
		case H264_DVR_SDK_TIMEOUT:
		case H264_DVR_SDK_MEMORY_ERROR:
		case H264_DVR_SDK_NET_ERROR:
		case H264_DVR_SDK_OPEN_FILE_ERROR:
		case H264_DVR_SDK_UNKNOWNERROR:
		case H264_DVR_DEV_VER_NOMATCH:
		case H264_DVR_SDK_NOTSUPPORT:
		case H264_DVR_OPEN_CHANNEL_ERROR:
		case H264_DVR_CLOSE_CHANNEL_ERROR:
		case H264_DVR_SUB_CONNECT_ERROR:
		case H264_DVR_SUB_CONNECT_SEND_ERROR:
		case H264_DVR_NATCONNET_REACHED_MAX:
			throw Poco::IOException(addErrMsg);
		default:
			throw Poco::IOException("default exception!");
	}
}

}}