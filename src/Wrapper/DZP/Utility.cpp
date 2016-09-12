#include "DZP/Utility.h"
#include <Poco/DateTime.h>
#include <Poco/Exception.h>
#include <Poco/Path.h>
#include "netsdk.h"

extern "C"
{
	typedef long (CALL_METHOD *FnType)();
	typedef long (CALL_METHOD *FnParamType)(long);
	typedef float (CALL_METHOD *FnParamTypeA)(long);

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

#define check_symbol(fn) if (!Utility::_library.hasSymbol(fn)) \
							throw Poco::NotFoundException(fn)
namespace DVR {
namespace DZPLite {

const int Utility::success = SDK_RET_CODE::H264_DVR_SUCCESS;
DeviceInfo* Utility::_pDevice_info = nullptr;
Poco::SharedLibrary Utility::_dependency("sdk\\DZP\\StreamReader.dll");
Poco::SharedLibrary Utility::_dependencyA("sdk\\DZP\\DllDeinterlace.dll");
//Poco::SharedLibrary Utility::_dependencyB("sdk\\DZP\\H264Play.dll");
Poco::SharedLibrary Utility::_library("sdk\\DZP\\NetSDK.dll");
Poco::Mutex Utility::_mutex;
Utility::Utility()
{	
	if (!_pDevice_info)
	{
		_pDevice_info = new DeviceInfo();
		memset(_pDevice_info, 0, sizeof(DeviceInfo));
	}
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
	check_symbol(fn);
	Fn2ParamTypeC pFn = (Fn2ParamTypeC)Utility::_library.getSymbol(fn);
	int rc = pFn(0, 0);
	if (Utility::success != rc) poco_unexpected();
}

void Utility::Cleanup()
{
	std::string fn("H264_DVR_Cleanup");
	check_symbol(fn);
	FnType pFn = (FnType)Utility::_library.getSymbol(fn);
	int rc = pFn();
	if (Utility::success != rc) poco_unexpected();
}

Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& address, const std::string& user, const std::string& password)
{
	std::string fn("H264_DVR_Login");
	check_symbol(fn);
	
	memset(_pDevice_info, 0, sizeof(DeviceInfo));
	Fn7ParamTypeA pFn = (Fn7ParamTypeA)Utility::_library.getSymbol(fn);
	std::string ip = address.host().toString();
	unsigned short port = address.port();
	int nError = 0;
	return pFn((char*)ip.c_str(), port, (char*)user.c_str(), (char*)password.c_str(), _pDevice_info, &nError, TCPSOCKET);
}

bool Utility::logout(Utility::HANDLE handle)
{
	std::string fn("H264_DVR_Logout");
	check_symbol(fn);
	FnParamType pFn = (FnParamType)Utility::_library.getSymbol(fn);
	return (Utility::success == pFn(handle));
}

void Utility::readDeviceInfo(DeviceInfo& info)
{
	poco_check_ptr(_pDevice_info);
	memcpy(&info, _pDevice_info, sizeof(DeviceInfo));
}

void Utility::setTimeOut(std::size_t timeout, std::size_t times)
{
	std::string fn("H264_DVR_SetConnectTime");
	check_symbol(fn);
	Fn2ParamTypeA pFn = (Fn2ParamTypeA)Utility::_library.getSymbol(fn);
	pFn(timeout, times);
}

Utility::FileHandle Utility::readStream(Utility::HANDLE handle, Record& data, const std::string& newname)
{
	std::string fn("H264_DVR_GetFileByName");
	check_symbol(fn);
	
	Fn6ParamTypeA pFn = (Fn6ParamTypeA)Utility::_library.getSymbol(fn);
	FileHandle file = pFn(handle, &data, (char*)newname.c_str(), nullptr, 0, nullptr);
	if (file > 0) return file;

	return 0;
}

Utility::FileHandle Utility::readStream(Utility::HANDLE handle, Condition& time, const std::string& newname, bool merge)
{

	std::string fn("H264_DVR_GetFileByTime");
	check_symbol(fn);

	Fn7ParamTypeB pFn = (Fn7ParamTypeB)Utility::_library.getSymbol(fn);
	FileHandle file = pFn(handle, &time, (char*)newname.c_str(), false, nullptr, 0, nullptr);
	if (file > 0) return file;

	return 0;
}

int Utility::readStreamPos(Utility::FileHandle handle)
{
	std::string fn("H264_DVR_GetDownloadPos");
	check_symbol(fn);
	FnParamType pFn = (FnParamType)Utility::_library.getSymbol(fn);
	return pFn(handle);
}


bool Utility::closeStream(Utility::FileHandle handle)
{
	std::string fn("H264_DVR_StopGetFile");
	check_symbol(fn);
	
	FnParamType pFn = (FnParamType)Utility::_library.getSymbol(fn);
	return (Utility::success == pFn(handle));
}

Utility::PlayHandle Utility::playStream(Utility::HANDLE handle, const Record& record)
{
	std::string fn("H264_DVR_PlayBackByName_V2");
	check_symbol(fn);

	Fn5ParamTypeB pFn = (Fn5ParamTypeB)Utility::_library.getSymbol(fn);
	Utility::PlayHandle play = pFn(handle, (void*)(&record), nullptr, nullptr, 0);
	if (play > 0) return play;

	return 0;
}

Utility::PlayHandle Utility::playStream(Utility::HANDLE handle, const Condition& time)
{
	std::string fn("H264_DVR_PlayBackByTime");
	check_symbol(fn);
	
	Fn5ParamTypeB pFn = (Fn5ParamTypeB)Utility::_library.getSymbol(fn);
	Utility::PlayHandle play = pFn(handle, (void*)(&time), nullptr, nullptr, 0);
	if (play > 0) return play;

	return 0;
}

float Utility::playPos(Utility::PlayHandle handle)
{
	std::string fn("H264_DVR_GetPlayPos");
	check_symbol(fn);
	FnParamTypeA pFn = (FnParamTypeA)Utility::_library.getSymbol(fn);
	return pFn(handle) * 1000;
}

bool Utility::stopStream(Utility::PlayHandle handle)
{
	std::string fn("H264_DVR_StopPlayBack");
	check_symbol(fn);

	FnParamType pFn = (FnParamType)Utility::_library.getSymbol(fn);
	return (Utility::success == pFn(handle));
}

bool Utility::seek(Utility::PlayHandle handle, int pos)
{
	std::string fn("H264_DVR_PlayBackControl");
	check_symbol(fn);
	
	Fn3ParamType pFn = (Fn3ParamType)Utility::_library.getSymbol(fn);
	return (Utility::success == pFn(handle, ACTION::SDK_PLAY_BACK_SEEK, pos));
}

bool Utility::play(Utility::PlayHandle handle)
{
	std::string fn("H264_DVR_PlayBackControl");
	check_symbol(fn);
	
	Fn3ParamType pFn = (Fn3ParamType)Utility::_library.getSymbol(fn);
	return (Utility::success == pFn(handle, ACTION::SDK_PLAY_BACK_CONTINUE, 0));
}

bool Utility::pause(Utility::PlayHandle handle)
{
	std::string fn("H264_DVR_PlayBackControl");
	check_symbol(fn);
	
	Fn3ParamType pFn = (Fn3ParamType)Utility::_library.getSymbol(fn);
	return (Utility::success == pFn(handle, ACTION::SDK_PLAY_BACK_PAUSE, 0));
}

size_t Utility::findStream(Utility::HANDLE handle, const Condition& cond, Record& record, int recordCount)
{
	std::string fn("H264_DVR_FindFile");
	check_symbol(fn);

	Fn6ParamTypeB pFn = (Fn6ParamTypeB)Utility::_library.getSymbol(fn);
	int count = 0;
	int timeout = 5000;
	if (Utility::success != pFn(handle, (void*)&cond, (void*)&record, recordCount, &count, timeout))
		throwException(lastError(), "findStream failed!");
	return count;
}

size_t Utility::findStream(Utility::HANDLE handle, const Time& time, Result& result)
{
	throw Poco::NotImplementedException("findStream by time!");
	/*
	std::string fn("H264_DVR_FindFileByTime");
	check_symbol(fn);
	
	Fn4ParamType pFn = (Fn4ParamType)Utility::_library.getSymbol(fn);
	int timeout = 10000;
	if (Utility::success != pFn(handle, (void*)&time, (void*)&result, timeout))
		throwException(lastError(), "H264_DVR_FindFileByTime failed!");

	return result.nInfoNum;
	*/
}

long Utility::lastError()
{
	std::string fn("H264_DVR_GetLastError");
	check_symbol(fn);
	
	FnType pFn = (FnType)Utility::_library.getSymbol(fn);
	return pFn();
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