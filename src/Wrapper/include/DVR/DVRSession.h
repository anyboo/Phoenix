#pragma once
#include "DVR/DVR.h"
#include "DVR/DVRSessionImpl.h"
#include <Poco/AutoPtr.h>
#include <Poco/Any.h>
#include <string>

namespace DVR {

	class DVR_API DVRSession
	{
	public:
		static const std::size_t LOGIN_TIMEOUT_DEFAULT = DVRSessionImpl::LOGIN_TIMEOUT_DEFAULT;
		static const Poco::UInt32 TRANSACTION_READ_UNCOMMITTED = 0x00000001L;
		static const Poco::UInt32 TRANSACTION_READ_COMMITTED = 0x00000002L;
		static const Poco::UInt32 TRANSACTION_REPEATABLE_READ = 0x00000004L;
		static const Poco::UInt32 TRANSACTION_SERIALIZABLE = 0x00000008L;

		DVRSession(Poco::AutoPtr<DVRSessionImpl> ptrImpl);

		DVRSession(const std::string& connector,
			const std::string& connectionString,/*ipaddress port example: 192.168.0.22:35*/
			std::size_t timeout = LOGIN_TIMEOUT_DEFAULT);

		DVRSession(const DVRSession&);
		DVRSession& operator = (const DVRSession&);

		~DVRSession();

		void swap(DVRSession& other);

		void login(const std::string& user, const std::string& password);
		void logout();
		bool isLoggedIn() const;

		void setLoginTimeout(std::size_t timeout);
		std::size_t getLoginTimeout() const;
		void reconnect();

		void beginList(const std::string& path = "", bool extended = false);
		void beginDownload(const std::string& path);
		void play(const std::string& filename);
		void abort();

		void setFeature(const std::string& name, bool state);
		bool getFeature(const std::string& name);
		void setProperty(const std::string& name, const Poco::Any& value);
		Poco::Any getProperty(const std::string& name)const;

		DVRSessionImpl* impl();

	private:
		DVRSession();

		Poco::AutoPtr<DVRSessionImpl> _pImpl;

	};

	inline void DVRSession::login(const std::string& user, const std::string& password)
	{
		_pImpl->login(user, password);
	}

	inline void DVRSession::logout()
	{
		_pImpl->logout();
	}

	inline bool DVRSession::isLoggedIn() const
	{
		return _pImpl->isLoggedIn();
	}

	inline void DVRSession::setLoginTimeout(std::size_t timeout)
	{
		_pImpl->setLoginTimeout(timeout);
	}

	inline std::size_t DVRSession::getLoginTimeout() const
	{
		return _pImpl->getLoginTimeout();
	}

	inline void DVRSession::reconnect()
	{
		_pImpl->reconnect();
	}

	inline void DVRSession::beginList(const std::string& path, bool extended)
	{
		_pImpl->beginList(path, extended);
	}

	inline void DVRSession::beginDownload(const std::string& path)
	{
		_pImpl->beginDownload(path);
	}

	inline void DVRSession::play(const std::string& filename)
	{
		_pImpl->play(filename);
	}

	inline void DVRSession::abort()
	{
		_pImpl->abort();
	}

	inline void DVRSession::setFeature(const std::string& name, bool state)
	{
		_pImpl->setFeature(name, state);
	}

	inline bool DVRSession::getFeature(const std::string& name)
	{
		return const_cast<DVRSessionImpl*>(_pImpl.get())->getFeature(name);
	}

	inline void DVRSession::setProperty(const std::string& name, const Poco::Any& value)
	{
		_pImpl->setProperty(name, value);
	}

	inline Poco::Any DVRSession::getProperty(const std::string& name)const
	{
		return const_cast<DVRSessionImpl*>(_pImpl.get())->getProperty(name);
	}

	inline DVRSessionImpl* DVRSession::impl()
	{
		return _pImpl;
	}

	inline void swap(DVRSession& s1, DVRSession& s2)
	{
		s1.swap(s2);
	}
}


namespace std
{
	template<>
	inline void swap<DVR::DVRSession>(DVR::DVRSession& s1, DVR::DVRSession& s2)
	{
		s1.swap(s2);
	}
}