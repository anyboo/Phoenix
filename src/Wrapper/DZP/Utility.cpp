#include "DZP/Utility.h"
#include "sdk/netsdk.h"
#include <Poco/DateTime.h>
#include <Poco/SharedLibrary.h>


extern "C"
{
	typedef long (CALL_METHOD *LibrayFnType)(long lLoginID, H264_DVR_FILE_DATA *sPlayBackFile, char *sSavedFileName,
		fDownLoadPosCallBack cbDownLoadPos, long dwDataUser, fRealDataCallBack fDownLoadDataCallBack);

	typedef long (CALL_METHOD *PH264_DVR_Init)(fDisConnect cbDisConnect, unsigned long dwUser);
	typedef bool (CALL_METHOD *PH264_DVR_Cleanup)();

	typedef long (CALL_METHOD *PH264_DVR_Login)(char *sDVRIP, unsigned short wDVRPort, char *sUserName, char *sPassword,
		LPH264_DVR_DEVICEINFO lpDeviceInfo, int *error, int socketType);
	typedef long (CALL_METHOD *PH264_DVR_Logout)(long lLoginID);

	typedef bool (CALL_METHOD *PH264_DVR_SetConnectTime)(long nWaitTime, long nTryTimes);

	typedef long (CALL_METHOD *PH264_DVR_GetFileByTime)(long lLoginID, H264_DVR_FINDINFO* lpFindInfo, char *sSavedFileDIR, bool bMerge ,
		fDownLoadPosCallBack cbDownLoadPos, long dwDataUser, fRealDataCallBack fDownLoadDataCallBack);	

	typedef long (CALL_METHOD *PH264_DVR_FindFile)(long lLoginID, H264_DVR_FINDINFO* lpFindInfo, H264_DVR_FILE_DATA *lpFileData, int lMaxCount, 
		int *findcount, int waittime);

	typedef long (CALL_METHOD *PH264_DVR_PlayBackByName)(long lLoginID, H264_DVR_FILE_DATA *sPlayBackFile, fDownLoadPosCallBack cbDownLoadPos,
		fRealDataCallBack fDownLoadDataCallBack, long dwDataUser);
	typedef bool (CALL_METHOD *PH264_DVR_StopPlayBack)(long lPlayHandle);
	typedef bool (CALL_METHOD *PH264_DVR_SetPlayPos)(long lPlayHandle, float fRelativPos);
	typedef float (CALL_METHOD *PH264_DVR_GetPlayPos)(long lPlayHandle);
}

extern Poco::SharedLibrary sl;


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

	H264_DVR_DEVICEINFO OutDev;
	memset(&OutDev, 0, sizeof(H264_DVR_DEVICEINFO));
	int nError = 0;

	poco_assert(sl.hasSymbol("H264_DVR_Login"));
	PH264_DVR_Login H264_DVR_Login = (PH264_DVR_Login)sl.getSymbol("H264_DVR_Login");
	sockaddr_in* pSin = (sockaddr_in*)_addr.addr();
	std::cout << "IP:" << inet_ntoa(pSin->sin_addr) << "port:" << _addr.port() << std::endl;
	long loginHandle = H264_DVR_Login(inet_ntoa(pSin->sin_addr), _addr.port(), (char *)user.c_str(), (char *)password.c_str(), &OutDev, &nError, TCPSOCKET);
	handle = loginHandle;

	std::cout << "login handle: " << handle << std::endl;
	
	return handle;
}

int Utility::logout(Utility::HANDLE handle)
{
	//int rc = H264_DVR_Logout(*_pDvr);
	poco_assert(sl.hasSymbol("H264_DVR_Logout"));
	PH264_DVR_Logout H264_DVR_Logout = (PH264_DVR_Logout)sl.getSymbol("H264_DVR_Logout");

	if (H264_DVR_Logout(handle))
	{
		std::cout << "logout success" << std::endl;
		return true;
	}		
	else
		return false;
}

int Utility::setTimeOut(std::size_t timeout, std::size_t times)
{
	//int rc = H264_DVR_SetConnectTime(timeout, TRY_TIMES);
	poco_assert(sl.hasSymbol("H264_DVR_SetConnectTime"));
	PH264_DVR_SetConnectTime pDZPSetConnectTime = (PH264_DVR_SetConnectTime)sl.getSymbol("H264_DVR_SetConnectTime");
	pDZPSetConnectTime(timeout, times);

	return success;
}

int Utility::Init()
{	
	std::cout << "init " << std::endl;
	poco_assert(sl.isLoaded());
	poco_assert(sl.hasSymbol("H264_DVR_Init"));
	PH264_DVR_Init H264_DVR_Init = (PH264_DVR_Init)sl.getSymbol("H264_DVR_Init");
	return H264_DVR_Init(NULL, NULL);
}

int Utility::CleanUp()
{
	//bool rc = H264_DVR_Cleanup();
	std::cout << "cleat up" << std::endl;
	poco_assert(sl.isLoaded());
	poco_assert(sl.hasSymbol("H264_DVR_Cleanup"));
	PH264_DVR_Cleanup H264_DVR_Cleanup = (PH264_DVR_Cleanup)sl.getSymbol("H264_DVR_Cleanup");
	H264_DVR_Cleanup();
	return success;
}

void NetTimeToTM(const SDK_SYSTEM_TIME& nt, tm& t)
{
	t.tm_year = nt.year - 1900;
	t.tm_mon = nt.month - 1;
	t.tm_mday = nt.day;
	t.tm_hour = nt.hour;
	t.tm_min = nt.minute;
	t.tm_sec = nt.second;
}

void TMToNetTime(const tm& t, H264_DVR_TIME& nt)
{
	nt.dwYear = t.tm_year + 1900;
	nt.dwMonth = t.tm_mon + 1;
	nt.dwDay = t.tm_mday;
	nt.dwHour = t.tm_hour;
	nt.dwMinute = t.tm_min;
	nt.dwSecond = t.tm_sec;
}

void TMToSDKTime(tm& t, SDK_SYSTEM_TIME& nt)
{
	nt.year = t.tm_year + 1900;
	nt.month = t.tm_mon + 1;
	nt.day = t.tm_mday;
	nt.hour = t.tm_hour;
	nt.minute = t.tm_min;
	nt.second = t.tm_sec;
}

int Utility::GetFile(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo, const std::string& path)
{
	poco_assert(sl.hasSymbol("H264_DVR_GetFileByName"));
	LibrayFnType H264_DVR_GetFileByName = (LibrayFnType)sl.getSymbol("H264_DVR_GetFileByName");

	
	H264_DVR_FILE_DATA info;
	memset(&info, 0, sizeof(info));
	info.ch = fileinfo.ch;
	strncpy(info.sFileName, (const char *)fileinfo.sFileName, strlen(fileinfo.sFileName));
	info.size = fileinfo.size;
	struct tm Tm;
	_localtime64_s(&Tm, (const time_t*)&fileinfo.stBeginTime);
	TMToSDKTime(Tm, info.stBeginTime);
	_localtime64_s(&Tm, (const time_t*)&fileinfo.stEndTime);
	TMToSDKTime(Tm, info.stEndTime);

	long ret = H264_DVR_GetFileByName((long)handle, &info, (char *)path.c_str(), nullptr, 0, 0);

	if (ret <= 0)
		return false;

	typedef void(CALL_METHOD *fDownLoadPosCallBack) (long lPlayHandle, long lTotalSize, long lDownLoadSize, long dwUser);
	//opCode = OPERATION_DOWNLOAD;
	//int rc = H264_DVR_GetFileByName(*_pDvr, &result, const_cast<char*>(path.c_str()), Utility::CallbackFn, opCode, Utility::DataCallbackFn);
	return success;
}

int Utility::GetFile(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, const std::string& path, bool merge)
{
	/*int rc = H264_DVR_GetFileByTime(*_pDvr, &cond, "", false,
	Utility::CallbackFn, (unsigned long)this, 0);*/
	poco_assert(sl.hasSymbol("H264_DVR_GetFileByTime"));
	PH264_DVR_GetFileByTime H264_DVR_GetFileByTime = (PH264_DVR_GetFileByTime)sl.getSymbol("H264_DVR_GetFileByTime");


	H264_DVR_FINDINFO info;
	memset(&info, 0, sizeof(info));
	info.nChannelN0 = timeinfo.ch;
	info.nFileType = SDK_RECORD_ALL;
	struct tm Tm;
	_localtime64_s(&Tm, (const time_t*)&timeinfo.stBeginTime);
	TMToNetTime(Tm, info.startTime);
	_localtime64_s(&Tm, (const time_t*)&timeinfo.stEndTime);
	TMToNetTime(Tm, info.endTime);

	long ret = H264_DVR_GetFileByTime((long)handle, &info, (char *)path.c_str(), false, nullptr, 0, 0);

	if (ret <= 0)
		return false;
	return success;
}

int Utility::Playback(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo)
{
	/*int rc = H264_DVR_PlayBackByName_V2(*_pDvr, &result,
	Utility::CallbackFn, 0, (unsigned long)this);*/
	poco_assert(sl.hasSymbol("H264_DVR_PlayBackByName"));
	PH264_DVR_PlayBackByName H264_DVR_PlayBackByName = (PH264_DVR_PlayBackByName)sl.getSymbol("H264_DVR_PlayBackByName");

	H264_DVR_FILE_DATA fileData;
	memset(&fileData, 0, sizeof(fileData));
	fileData.ch = fileinfo.ch;
	fileData.hWnd = fileinfo.hwnd;
	fileData.size = fileinfo.size;
	strncpy(fileData.sFileName, fileinfo.sFileName, strlen(fileinfo.sFileName));
	struct tm Tm;
	_localtime64_s(&Tm, (const time_t*)&fileinfo.stBeginTime);
	TMToSDKTime(Tm, fileData.stBeginTime);
	_localtime64_s(&Tm, (const time_t*)&fileinfo.stEndTime);
	TMToSDKTime(Tm, fileData.stEndTime);

	if (H264_DVR_PlayBackByName((long)handle, &fileData, nullptr, NULL, 0) == 0)
	{
		return false;
	}
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
	poco_assert(sl.hasSymbol("H264_DVR_FindFile"));
	PH264_DVR_FindFile H264_DVR_FindFile = (PH264_DVR_FindFile)sl.getSymbol("H264_DVR_FindFile");

	H264_DVR_FINDINFO info;
	memset(&info, 0, sizeof(info));
	info.nChannelN0 = timeinfo.ch;
	info.nFileType = SDK_RECORD_ALL;
	struct tm Tm;
	_localtime64_s(&Tm, (const time_t*)&timeinfo.stBeginTime);
	TMToNetTime(Tm, info.startTime);
	_localtime64_s(&Tm, (const time_t*)&timeinfo.stEndTime);
	TMToNetTime(Tm, info.endTime);

	H264_DVR_FILE_DATA nriFileinfo[2000];
	int fileCount;
	if (H264_DVR_FindFile((long)handle, &info, nriFileinfo, sizeof(nriFileinfo) / sizeof(H264_DVR_FILE_DATA), &fileCount, timeout) <= 0)
	{
		return 0;
	}

	return count;
}

void Utility::CallbackFn(long handle, long totalSize, long curSize, long opCode)
{

}

int Utility::DataCallbackFn(long handle, long type, unsigned char *buffer, long len, long opCode)
{
	return 0;
}

int Utility::stopPlayback(long lPlayHandle)
{
	poco_assert(sl.hasSymbol("H264_DVR_StopPlayBack"));
	PH264_DVR_StopPlayBack H264_DVR_StopPlayBack = (PH264_DVR_StopPlayBack)sl.getSymbol("H264_DVR_StopPlayBack");
	
	return  H264_DVR_StopPlayBack(lPlayHandle);	
}

int Utility::setPlayback(__int64 playbackHandle, __int32 pos)
{
	poco_assert(sl.hasSymbol("H264_DVR_SetPlayPos"));
	PH264_DVR_SetPlayPos H264_DVR_SetPlayPos = (PH264_DVR_SetPlayPos)sl.getSymbol("H264_DVR_SetPlayPos");

	return H264_DVR_SetPlayPos(playbackHandle, pos / 100.0);
}

int Utility::getPlayback(__int64 playbackHandle, __int32 *pos)
{
	poco_assert(sl.hasSymbol("H264_DVR_GetPlayPos"));
	PH264_DVR_GetPlayPos H264_DVR_GetPlayPos = (PH264_DVR_GetPlayPos)sl.getSymbol("H264_DVR_GetPlayPos");

	*pos = H264_DVR_GetPlayPos(playbackHandle) * 100;
	return true;
}

}}