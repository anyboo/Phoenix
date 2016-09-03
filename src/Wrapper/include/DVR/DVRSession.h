#pragma once
#include "DVR/DVR.h"
//#include "DVR/DVRSessionImpl.h"
//#include "DVR/DVRStatement.h"
#include "DVR/DVRStatementCreator.h"
#include <Poco/AutoPtr.h>
#include <Poco/Any.h>
#include <string>

namespace DVR {
	class DVRStatementImpl;
	/*
	DVRSession just a session, we need a device object represents device.
	a device can be connnected by more than one session.
	Then UI manages the devobject to operate.
	DeviceCollation
	*/
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

		template <typename T>
		DVRStatement operator << (const T& t)
		{
			return _statementCreator << t;
		}

		DVRStatementImpl* createStatementImpl();

		~DVRSession();

		void swap(DVRSession& other);

		void login(const std::string& user, const std::string& password);
		void logout();
		bool isLoggedIn() const;

		void setLoginTimeout(std::size_t timeout);
		std::size_t getLoginTimeout() const;
		void reconnect();

		void setFeature(const std::string& name, bool state);
		bool getFeature(const std::string& name);
		void setProperty(const std::string& name, const Poco::Any& value);
		Poco::Any getProperty(const std::string& name)const;

		DVRSessionImpl* impl();

	private:
		DVRSession();

		Poco::AutoPtr<DVRSessionImpl> _pImpl;
		DVRStatementCreator           _statementCreator;

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

	inline DVRStatementImpl* DVRSession::createStatementImpl()
	{
		return _pImpl->createStatementImpl();
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