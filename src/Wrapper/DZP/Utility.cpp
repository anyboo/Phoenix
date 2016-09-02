#include "DZP/Utility.h"
#include "netsdk.h"
#include <Poco/DateTime.h>
#include <Poco/SharedLibrary.h>

extern "C"
{
	typedef long (CALL_METHOD *LibrayFnType)(long lLoginID, H264_DVR_FILE_DATA *sPlayBackFile, char *sSavedFileName,
		fDownLoadPosCallBack cbDownLoadPos, long dwDataUser, fRealDataCallBack fDownLoadDataCallBack);
}

std::string path("");
Poco::SharedLibrary sl(path);

namespace DVR {
namespace DZPLite {

Utility::Utility()
{
}


Utility::~Utility()
{
}

std::string Utility::lastError(Utility::HANDLE handle)
{
	return "error";
}

std::string Utility::lastError(const DVRSession& session)
{
	return "error";
}

void Utility::throwException(Utility::HANDLE handle)
{

}

void Utility::throwException(int rc, const std::string& addErrMsg)
{

}

Utility::HANDLE Utility::login(const Poco::Net::SocketAddress& _addr, 
							   const std::string& user, 
							   const std::string& password,
							   DVRINFO& info)
{
	Utility::HANDLE handle = 0;
	//deviceLocation = "192.168.1.25:32";

	/*std::string usr(user);
	std::string pwd(password);
	if (usr.empty()) usr = "admin";
	if (pwd.empty()) pwd = "";*/
	//*_pDvr = H264_DVR_Login(const_cast<char*>(host.c_str()), port,
	//	const_cast<char*>(usr.c_str()), const_cast<char*>(pwd.c_str()),
	//	&info, &error, SocketStyle::UDPSOCKET); //how do I know the type of socket,OMG FAITH
	return handle;
}

int Utility::logout(Utility::HANDLE handle)
{
	//int rc = H264_DVR_Logout(*_pDvr);
	return success;
}

int Utility::setTimeOut(std::size_t timeout, std::size_t times)
{
	//int rc = H264_DVR_SetConnectTime(timeout, TRY_TIMES);
	return success;
}

int Utility::Init()
{
	//int rc = H264_DVR_Init(0,0);
	return success;
}

int Utility::CleanUp()
{
	//bool rc = H264_DVR_Cleanup();
	return success;
}

int Utility::GetFile(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo, const std::string& path)
{
	/*poco_assert(sl.isLoaded());
	LibrayFnType H264_DVR_GetFileByName = (LibrayFnType)sl.getSymbol("H264_DVR_GetFileByName");*/

	//typedef void(CALL_METHOD *fDownLoadPosCallBack) (long lPlayHandle, long lTotalSize, long lDownLoadSize, long dwUser);
	//opCode = OPERATION_DOWNLOAD;
	/*int rc = H264_DVR_GetFileByName(*_pDvr, &result, const_cast<char*>(path.c_str()),
	Utility::CallbackFn, opCode, Utility::DataCallbackFn);*/
	return success;
}

int Utility::GetFile(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, const std::string& path, bool merge)
{
	/*int rc = H264_DVR_GetFileByTime(*_pDvr, &cond, "", false,
	Utility::CallbackFn, (unsigned long)this, 0);*/
	return success;
}

int Utility::Playback(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo)
{
	/*int rc = H264_DVR_PlayBackByName_V2(*_pDvr, &result,
	Utility::CallbackFn, 0, (unsigned long)this);*/
	return success;
}

int Utility::Playback(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo)
{
	/*int rc = H264_DVR_PlayBackByTimeEx(*_pDvr, &cond,
	0, (unsigned long)this, Utility::CallbackFn, 0);*/
	return success;
}

int Utility::FindFile(Utility::HANDLE handle, const Utility::TIMEINFO timeinfo, std::size_t timeout)
{
	int count = 0;
	//int rc = H264_DVR_FindFile(*_pDvr, &condition, &result.front(), maxCount, &count, timeout);
	return count;
}

void Utility::CallbackFn(long handle, long totalSize, long curSize, long opCode)
{

}

int Utility::DataCallbackFn(long handle, long type, unsigned char *buffer, long len, long opCode)
{
	return 0;
}

}}