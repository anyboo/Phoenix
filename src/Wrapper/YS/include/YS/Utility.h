#pragma once
#include "YSLite.h"

#include <Poco/DateTime.h>
#include <string>
#include "DVR/DVRSession.h"
#include <Poco/Net/SocketAddress.h>
#include <Poco/SharedLibrary.h>
#include <map>

#include "NetDEVSDK.h"

extern "C"
{	
	typedef struct tagNETDEVFingData        Record;
	typedef struct tagNETDEVFindCond		Condition;
	typedef struct tagNETDEVDeviceInfo		DeviceInfo;
	typedef struct tagNETDEVPlayBackInfo    Play;
	typedef struct tagNETDEVPlayBackCondition PlayCondition;
}

namespace DVR {
namespace YSLite {
class YSLite_API Utility
{
public:
	~Utility(); 
	typedef LPVOID HANDLE;
	typedef LPVOID FileHandle;
	typedef LPVOID PlayHandle;
	static const int success;

	static Utility::HANDLE dvrHandle(const DVRSession& session);
	//static std::string lastError(Utility::HANDLE handle);
	//static std::string lastError(const DVRSession& session);
	//static long Utility::lastError();
	//static void throwException(Utility::HANDLE handle);
	static void throwException(long rc, const std::string& addErrMsg = std::string());

	static void Init();
	static void Cleanup();

	static Utility::HANDLE login(const Poco::Net::SocketAddress& _addr, const std::string& user, const std::string& password);
	static bool logout(Utility::HANDLE handle);	

	static Utility::FileHandle readStream(Utility::HANDLE handle, Play& data, const std::string& newname);	
	static Utility::FileHandle readStreamByTime(Utility::HANDLE handle, PlayCondition& data, const std::string& newname);
	static int Utility::readStreamPos(Utility::FileHandle handle);
	static bool closeStream(Utility::FileHandle handle);

	static Utility::PlayHandle playStream(Utility::HANDLE handle, Play& data);
	static Utility::PlayHandle playStreamByTime(Utility::HANDLE handle, PlayCondition& data);
	static bool playPos(Utility::PlayHandle handle, INT64 *iTime);
	static bool stopStream(Utility::PlayHandle handle);

	static bool seek(Utility::PlayHandle handle, int pos);	
	static bool pause(Utility::PlayHandle handle);

	static LPVOID findStream(Utility::HANDLE handle, const Condition& cond);
	static bool findNextStream(Utility::HANDLE findHandle, Record& record);
	static bool closeFindStream(Utility::HANDLE findHandle);

	static void readDeviceInfo(DeviceInfo& info);

	typedef void(*EventCallbackType)(void* pVal);

	template <typename T, typename CBT>
	static bool registerUpdateHandler(Utility::HANDLE Handle, CBT callbackFn, T* pParam)
		/// Registers the callback for (1)(insert, delete, update), (2)(commit) or 
		/// or (3)(rollback) events. Only one function per group can be registered
		/// at a time. Registration is not thread-safe. Storage pointed to by pParam
		/// must remain valid as long as registration is active. Registering with
		/// callbackFn set to zero disables notifications.
		/// 
		/// See http://www.sqlite.org/c3ref/update_hook.html and 
		/// http://www.sqlite.org/c3ref/commit_hook.html for details.
	{
		typedef std::pair<CBT, T*> CBPair;
		typedef std::multimap<Utility::HANDLE, CBPair> CBMap;
		typedef typename CBMap::iterator CBMapIt;
		typedef std::pair<CBMapIt, CBMapIt> CBMapItPair;

		static CBMap retMap;

		if (retMap.find(Handle) == retMap.end())//insert callbackFn when key is noexist.
		{
			retMap.insert(std::make_pair(Handle, CBPair(callbackFn, pParam)));
			return true;
		}
		else //update callbackFn when key is exist.
		{
			CBMapItPair retMapRange = retMap.equal_range(Handle);
			for (CBMapIt it = retMapRange.first; it != retMapRange.second; ++it)
			{
				poco_assert(it->second.first != 0);
				if ((callbackFn == 0) && (*pParam == *it->second.second))
				{
					retMap.erase(it);
					return true;
				}

				if ((callbackFn == it->second.first) && (*pParam == *it->second.second))
				{
					it->second.second = pParam;
					return true;
				}
			}
		}

		return false;
	}

	template <typename T, typename CBT>
	static bool registerUpdateHandler(const DVRSession& session, CBT callbackFn, T* pParam)
		/// Registers the callback by calling registerUpdateHandler(sqlite3*, CBT, T*).
	{
		return registerUpdateHandler(dvrHandle(session), callbackFn, pParam);
	}

protected:
	//static void callback();
private:
	Utility();
	Utility(const Utility&);
	Utility& operator = (const Utility&);

	static Poco::Mutex _mutex;
	static Poco::SharedLibrary _library;	
	static DeviceInfo* _pDevice_info;
};

//inline std::string Utility::lastError(Utility::HANDLE handle)
//{
//	long errCode = Utility::lastError();
//	return std::string("errCode");
//}

}}
