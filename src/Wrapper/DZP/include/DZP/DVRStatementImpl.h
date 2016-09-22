#pragma once
#include "DZPLite.h"
#include "DVR/DVRStatementImpl.h"
#include "DZP/Utility.h"

namespace DVR {
namespace DZPLite {

class DZPLite_API DVRStatementImpl : public DVR::DVRStatementImpl
{
public:
	DVRStatementImpl(DVR::DVRSessionImpl& rSession, Utility::HANDLE pDvr);
	~DVRStatementImpl();



	void donwloadByName(const std::string& filename);
	void downloadByTime(const Poco::DateTime& time);

	void playByName(const RecordFile& filename, HWND& hwnd);
	void playByTime(const Poco::DateTime& time);

	void list(const Poco::DateTime& beginTime, const Poco::DateTime& endTime, const std::vector<int>& channels, std::vector<RecordFile>& files);

	bool canDownloadByName();
	bool canPlayByName();

	typedef void (*ProcessCallbackType)(long lPlayHandle, long lTotalSize, long lDownLoadSize, long dwUser);
private:
	void ChangeTime(const Poco::DateTime& datatime, __time64_t& outTime);
	Utility::HANDLE _handle;
	int _state;
};

inline bool DVRStatementImpl::canDownloadByName()
{
	return true;
}

inline bool DVRStatementImpl::canPlayByName()
{
	return true;
}

}}
