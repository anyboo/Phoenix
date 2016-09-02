#pragma once
#include "DVR/DVR.h"
#include <Poco/SharedPtr.h>
#include <Poco/DateTime.h>
#include "DVR/DVRSessionImpl.h"

namespace DVR {

	class DVR_API DVRStatementImpl
	{
	public:
		typedef Poco::SharedPtr<DVRStatementImpl> Ptr;

		DVRStatementImpl(DVRSessionImpl& rSession);
		virtual ~DVRStatementImpl();

		void beginList(const std::string& beginTime, const std::string& endTime);
		void beginDownload(const std::string& filename);
		void play(const std::string& filename);
		void abort();

	protected:
		virtual void donwloadByName(const std::string& filename) = 0;
		virtual void downloadByTime(const Poco::DateTime& time) = 0;

		virtual void playByName(const std::string& filename) = 0;
		virtual void playByTime(const Poco::DateTime& time) = 0;

		virtual void list(const Poco::DateTime& beginTime, const Poco::DateTime& endTime) = 0;

		virtual bool canDownloadByName() = 0;
		virtual bool canPlayByName() = 0;

		DVRSessionImpl& session();

	private:
		DVRSessionImpl&	_rSession;
	};
}
