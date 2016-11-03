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

		long DownloadByName(const RecordFile& file, const std::string path);
		int GetDownloadPro(const long handle);
		void StopDownload(const long handle);
		void DownloadByTime(const Poco::DateTime stime, const Poco::DateTime etime);

		void Searchfile(const Poco::DateTime stime, const Poco::DateTime etime, const std::vector<int>& channels);

		virtual int playByName(const size_t fileID, HWND& hwnd);
		virtual void playByTime(const size_t fileID, HWND& hwnd);
		void stopPlay(const int playhandle);
		int getplayPos(const int playhandle);
		void setplayPos(const int playhandle, const int Pos);

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
		std::string     _Device_Name;
	};

}