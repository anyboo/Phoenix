#pragma once
#include <Poco/RefCountedObject.h>
#include "Wrapper.h"

namespace DVR {
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

		virtual void login(const std::string& user = "", const std::string& password = "") = 0;
		virtual void logout() = 0;
		virtual bool isLoggedIn()const = 0;

		void setLoginTimeout(std::size_t timeout);
		std::size_t getLoginTimeout() const;
		void reconnect();

		virtual void beginList(const std::string& path = "", bool extended = false) = 0;
		virtual void beginDownload(const std::string& path) = 0;
		virtual void play(const std::string& filename) = 0;
		virtual void abort() = 0;
	private:
		DVRSessionImpl();
		DVRSessionImpl(const DVRSessionImpl&);
		DVRSessionImpl& operator = (const DVRSessionImpl&);

		std::string _connectionString;
		std::size_t _loginTimeout;

	};
}

