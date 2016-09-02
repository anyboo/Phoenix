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

		DVRStatement(const DVRStatement& stmt);
		DVRStatement& operator = (const DVRStatement& stmt);
		DVRStatement& reset(DVRSession& session);
		void swap(DVRStatement& other);

		void beginList(const std::string& beginTime, const std::string& endTime);
		void beginDownload(const std::string& filename);
		void play(const std::string& filename);
		void abort();

	protected:
		typedef DVRStatementImpl::Ptr ImplPtr;
		ImplPtr impl() const;
		DVRSession session();
		
	private:
		DVRStatementImpl::Ptr _pImpl;
	};

	inline void DVRStatement::beginList(const std::string& beginTime, const std::string& endTime)
	{
		_pImpl->beginList(beginTime, endTime);
	}

	inline void DVRStatement::beginDownload(const std::string& filename)
	{
		/*
		download one file use one session, so we must manage sessions for file list.
		*/
		_pImpl->beginDownload(filename);
	}

	inline void DVRStatement::play(const std::string& filename)
	{
		_pImpl->play(filename);
	}

	inline void DVRStatement::abort()
	{
		_pImpl->abort();
	}

}