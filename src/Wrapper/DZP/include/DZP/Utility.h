#pragma once
#include "DZPLite.h"
#include <Poco/DateTime.h>
#include <string>
#include "DVR/DVRSession.h"
#include <Poco/Net/SocketAddress.h>

namespace DVR {
namespace DZPLite {

class DZPLite_API Utility
{
public:
	~Utility();

	typedef long HANDLE;
	typedef struct FILEINFO
	{
		int ch;						//通道号
		int size;					//文件大小
		char sFileName[108];		///< 文件名
		__time64_t stBeginTime;	///< 文件开始时间
		__time64_t stEndTime;		///< 文件结束时间
		HWND hwnd;
	} FILEINFO;

	typedef struct TIMEINFO
	{
		int ch;						//通道号
		int size;					//文件大小
		char sFileName[108];		///< 文件名
		__time64_t stBeginTime;	///< 文件开始时间
		__time64_t stEndTime;		///< 文件结束时间
		HWND hwnd;
	} TIMEINFO;

	typedef struct DVRINFO{} DVRINFO;
	typedef struct CONDITION{} CONDITION;

	static const int success = 1;
	static Utility::HANDLE dvrHandle(const DVRSession& session);
	static std::string lastError(Utility::HANDLE handle);
	static std::string lastError(const DVRSession& session);
	static void throwException(Utility::HANDLE handle);
	static void throwException(int rc, const std::string& addErrMsg = std::string());

	static Utility::HANDLE login(const Poco::Net::SocketAddress& _addr, 
								 const std::string& user, 
								 const std::string& password,
								 DVRINFO& info);

	static int logout(Utility::HANDLE handle);
	static int setTimeOut(std::size_t timeout, std::size_t times);

	static int Init();
	static int CleanUp();

	static int GetFile(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo, const std::string& path);
	static int GetFile(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo, const std::string& path, bool merge);

	static int Playback(Utility::HANDLE handle, const Utility::FILEINFO& fileinfo);
	static int Playback(Utility::HANDLE handle, const Utility::TIMEINFO& timeinfo);

	static int FindFile(Utility::HANDLE handle, const Utility::TIMEINFO timeinfo, std::size_t timeout);

	static int stopPlayback(long lPlayHandle);
	static int setPlayback(__int64 playbackHandle, __int32 pos);
	static int getPlayback(__int64 playbackHandle, __int32 *pos);
protected:
	static void __stdcall CallbackFn(long handle, long totalSize, long curSize, long opCode);
	static int  __stdcall DataCallbackFn(long handle, long type, unsigned char *buffer, long len, long opCode);
private:
	Utility();
	Utility(const Utility&);
	Utility& operator = (const Utility&);
};

}}
