#pragma once
#include <Poco/RefCountedObject.h>
#include "DVR/DVR.h"
#include <Poco/Any.h>

namespace DVR {
	class DVRStatementImpl;
	class DVR_API DVRSessionImpl
		:public Poco::RefCountedObject
	{
	public:
		static const std::size_t LOGIN_TIMEOUT_INFINITE = 0;
		static const std::size_t LOGIN_TIMEOUT_DEFAULT = 60;
		static const std::size_t CONNECTION_TIMEOUT_INFINITE = 0;
		static const std::size_t CONNECTION_TIMEOUT_DEFAULT = CONNECTION_TIMEOUT_INFINITE;

		DVRSessionImpl(const std::string& connectionString,
			std::size_t timeout = LOGIN_TIMEOUT_DEFAULT);
		virtual ~DVRSessionImpl();

		virtual DVRStatementImpl* createStatementImpl() = 0;
		virtual void login(const std::string& user = "", const std::string& password = "") = 0;
		virtual void logout() = 0;
		virtual bool isLoggedIn()const = 0;

		virtual void setLoginTimeout(std::size_t timeout) = 0;
		virtual std::size_t getLoginTimeout() const = 0;
		void reconnect();

		virtual void setFeature(const std::string& name, bool state) = 0;
		virtual bool getFeature(const std::string& name) = 0;
		virtual void setProperty(const std::string& name, const Poco::Any& value) = 0;
		virtual Poco::Any getProperty(const std::string& name) = 0;
	private:
		DVRSessionImpl();
		DVRSessionImpl(const DVRSessionImpl&);
		DVRSessionImpl& operator = (const DVRSessionImpl&);

		std::string _connectionString;
		std::size_t _loginTimeout;

	};
}

