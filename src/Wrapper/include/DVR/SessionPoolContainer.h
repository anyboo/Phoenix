#pragma once

#include "DVR/DVR.h"
#include "DVR/DVRSession.h"
#include "DVR/SessionPool.h"
#include <Poco/String.h>
#include <Poco/Mutex.h>


namespace DVR {


class DVR_API SessionPoolContainer
	/// This class implements container of session pools.
{
public:
	SessionPoolContainer();
		/// Creates the SessionPoolContainer for sessions with the given session parameters.

	~SessionPoolContainer();
		/// Destroys the SessionPoolContainer.
	
	void add(SessionPool* pPool);
		/// Adds existing session pool to the container.
		/// Throws SessionPoolExistsException if pool already exists.

	DVRSession add(const std::string& sessionKey, 
		const std::string& connectionString,
		int minSessions = 1, 
		int maxSessions = 32, 
		int idleTime = 60);
		/// Adds a new session pool to the container and returns a Session from
		/// newly created pool. If pool already exists, request to add is silently
		/// ignored and session is returned from the existing pool.

	bool has(const std::string& name) const;
		/// Returns true if the requested name exists, false otherwise.

	bool isActive(const std::string& sessionKey,
		const std::string& connectionString = "") const;
		/// Returns true if the session is active (i.e. not shut down).
		/// If connectionString is empty string, sessionKey must be a 
		/// fully qualified session name as registered with the pool
		/// container.

	DVRSession get(const std::string& name);
		/// Returns the requested Session.
		/// Throws NotFoundException if session is not found.

	SessionPool& getPool(const std::string& name);
		/// Returns a SessionPool reference.
		/// Throws NotFoundException if session is not found.

	void remove(const std::string& name);
		/// Removes a SessionPool.
		
	int count() const;
		/// Returns the number of session pols in the container.

	void shutdown();
		/// Shuts down all the held pools.

private:
	typedef std::map<std::string, Poco::AutoPtr<SessionPool>, Poco::CILess> SessionPoolMap;

	SessionPoolContainer(const SessionPoolContainer&);
	SessionPoolContainer& operator = (const SessionPoolContainer&);
		
	SessionPoolMap  _sessionPools;
	Poco::FastMutex _mutex;
};


inline bool SessionPoolContainer::has(const std::string& name) const
{
	return _sessionPools.find(name) != _sessionPools.end();
}


inline void SessionPoolContainer::remove(const std::string& name)
{
	_sessionPools.erase(name);
}


inline int SessionPoolContainer::count() const
{
	return static_cast<int>(_sessionPools.size());
}


}


