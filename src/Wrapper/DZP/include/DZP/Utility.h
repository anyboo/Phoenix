#pragma once
#include "DZPLite.h"
#include <Poco/DateTime.h>
#include <string>
#include "DVR/DVRSession.h"
#include <Poco/Net/SocketAddress.h>
#include <map>

namespace DVR {
namespace DZPLite {

class DZPLite_API Utility
{
public:
	~Utility();

	typedef void* HANDLE;
	typedef struct FILEINFO{} FILEINFO;
	typedef struct TIMEINFO{} TIMEINFO;
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

	typedef void(*EventCallbackType)(void* pVal);

	template <typename T, typename CBT>
	static bool registerUpdateHandler(void* Handle, CBT callbackFn, T* pParam)
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
		typedef std::multimap<void*, CBPair> CBMap;
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
				if ((callbackFn == 0) && (*pRet == *it->second.second))
				{
					retMap.erase(it);
					return true;
				}

				if ((callbackFn == it->second.first) && (*pRet == *it->second.second))
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
	static void __stdcall CallbackFn(long handle, long totalSize, long curSize, long opCode);
	static int  __stdcall DataCallbackFn(long handle, long type, unsigned char *buffer, long len, long opCode);

	//static void* eventHookRegister(void* Handle, EventCallbackType callbackFn, void* pParam);
private:
	Utility();
	Utility(const Utility&);
	Utility& operator = (const Utility&);
};

}}
