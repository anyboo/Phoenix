#pragma once

#include "DVR/DVR.h"
#include "DVR/DVRSessionImpl.h"
#include "DVR/PooledSessionHolder.h"
#include <Poco/AutoPtr.h>


namespace DVR {


class SessionPool;


class DVR_API PooledSessionImpl: public DVRSessionImpl
	/// PooledSessionImpl is a decorator created by
	/// SessionPool that adds session pool
	/// management to SessionImpl objects.
{
public:
	PooledSessionImpl(PooledSessionHolder* pHolder);
		/// Creates the PooledSessionImpl.

	~PooledSessionImpl();
		/// Destroys the PooledSessionImpl.

	// SessionImpl
	DVRStatementImpl* createStatementImpl();

	void login(const std::string& user = "", const std::string& password = "");
	void logout();
	bool isLoggedIn()const;
	void list();
	void download();
	void playback();
	void abort();
	void setLoginTimeout(std::size_t timeout);
	std::size_t getLoginTimeout() const;
	void reconnect();
	const std::string& connectionString() const;
	const std::string& connectorName() const;
	void setFeature(const std::string& name, bool state);
	bool getFeature(const std::string& name);
	void setProperty(const std::string& name, const Poco::Any& value);
	Poco::Any getProperty(const std::string& name);
	
protected:
	DVRSessionImpl* access() const;
		/// Updates the last access timestamp,
		/// verifies validity of the session
		/// and returns the session if it is valid.
		///
		/// Throws an SessionUnavailableException if the
		/// session is no longer valid.
		
	DVRSessionImpl* impl() const;
		/// Returns a pointer to the SessionImpl.
				
private:	
	mutable Poco::AutoPtr<PooledSessionHolder> _pHolder;
};


//
// inlines
//
inline DVRSessionImpl* PooledSessionImpl::impl() const
{
	return _pHolder->session();
}


}

