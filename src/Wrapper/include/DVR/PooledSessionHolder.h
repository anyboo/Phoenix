#pragma once

#include "DVR/DVR.h"
#include "DVR/DVRSessionImpl.h"
#include <Poco/AutoPtr.h>
#include <Poco/Timestamp.h>
#include <Poco/Mutex.h>


namespace DVR {

class SessionPool;

class DVR_API PooledSessionHolder: public Poco::RefCountedObject
	/// This class is used by SessionPool to manage SessionImpl objects.
{
public:
	PooledSessionHolder(SessionPool& owner, DVRSessionImpl* pSessionImpl);
		/// Creates the PooledSessionHolder.

	~PooledSessionHolder();
		/// Destroys the PooledSessionHolder.

	DVRSessionImpl* session();
		/// Returns a pointer to the SessionImpl.

	SessionPool& owner();
		/// Returns a reference to the SessionHolder's owner.

	void access();
		/// Updates the last access timestamp.

	int idle() const;
		/// Returns the number of seconds the session has not been used.

private:
	SessionPool& _owner;
	Poco::AutoPtr<DVRSessionImpl> _pImpl;
	Poco::Timestamp _lastUsed;
	mutable Poco::FastMutex _mutex;
};


//
// inlines
//
inline DVRSessionImpl* PooledSessionHolder::session()
{
	return _pImpl;
}


inline SessionPool& PooledSessionHolder::owner()
{
	return _owner;
}


inline void PooledSessionHolder::access()
{
	Poco::FastMutex::ScopedLock lock(_mutex);
	
	_lastUsed.update();
}


inline int PooledSessionHolder::idle() const
{
	Poco::FastMutex::ScopedLock lock(_mutex);

	return (int) (_lastUsed.elapsed()/Poco::Timestamp::resolution());
}

}
