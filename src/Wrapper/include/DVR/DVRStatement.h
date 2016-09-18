#pragma once
#include "DVR/DVR.h"
#include "DVR/DVRStatementImpl.h"
#include <Poco/Mutex.h>

namespace DVR {
	class DVRSession;
	class DVR_API DVRStatement
	{
	public:
		DVRStatement(DVRStatementImpl::Ptr pImpl);
		explicit DVRStatement(DVRSession& session);
		
		~DVRStatement();

		void DownloadByName(const std::string& name);
		void DownloadByTime(const Poco::DateTime stime, const Poco::DateTime etime);

		void Searchfile(const Poco::DateTime stime, const Poco::DateTime etime, const std::vector<int>& channels);

		virtual void playByName(const std::string& filename);
		virtual void playByTime(const Poco::DateTime& stime, const  Poco::DateTime etime);

		DVRStatement(const DVRStatement& stmt);
		DVRStatement& operator = (const DVRStatement& stmt);
		DVRStatement& reset(DVRSession& session);
		void swap(DVRStatement& other);

		template <typename T>
		DVRStatement& operator << (const T& t)
		{
			_pImpl->add(t);
			return *this;
		}

	protected:
		typedef DVRStatementImpl::Ptr ImplPtr;
		ImplPtr impl() const;
		DVRSession session();
		
	private:
		DVRStatementImpl::Ptr _pImpl;
	};

}