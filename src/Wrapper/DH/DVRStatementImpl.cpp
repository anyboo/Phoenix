#include "DH/DVRStatementImpl.h"
#include "DH/Notifier.h"

#include <vector>
#include <sstream>

namespace DVR {
	namespace DHLite {

DVRStatementImpl::DVRStatementImpl(DVR::DVRSessionImpl& rSession, Utility::HANDLE pDvr):
DVR::DVRStatementImpl(rSession),
_handle(pDvr)
{
}


DVRStatementImpl::~DVRStatementImpl()
{
}

void DVRStatementImpl::donwloadByName(const std::string& filename)
{
	Utility::FILEINFO fileinfo;
	std::string path;
	int rc = Utility::GetFile(_handle, fileinfo, path);
	
	if (Utility::success != rc)
		Utility::throwException(_handle);
	//rename filename
}

void DVRStatementImpl::downloadByTime(const Poco::DateTime& time)
{
	Utility::CONDITION cond;
	Utility::TIMEINFO timeinfo;

	std::string path;
	int rc = Utility::GetFile(_handle, timeinfo, path, false);
	
	if (Utility::success != rc)
		Utility::throwException(_handle);

}

void DVRStatementImpl::playByName(const std::string& filename)
{
	Utility::FILEINFO fileinfo;
	int rc = Utility::Playback(_handle, fileinfo);
	
	if (Utility::success != rc)
		Utility::throwException(_handle);
}

void DVRStatementImpl::playByTime(const Poco::DateTime& time)
{
	Utility::CONDITION cond;
	Utility::TIMEINFO timeinfo;

	int rc = Utility::Playback(_handle, timeinfo);

	if (Utility::success != rc)
		Utility::throwException(_handle);
}

/*
list 需要异步操作
*/
void DVRStatementImpl::list(const Poco::DateTime& beginTime, const Poco::DateTime& endTime)
{
	Utility::CONDITION condition;
	Utility::TIMEINFO timeinfo;
	std::size_t timeout = 3000;
	//std::vector<RESULT> result(1000);
	//int count = 0;
	//int maxCount = 1000;
	//int timeout = 5000;
	//将多天的查询范围，切分成1天的范围多次查询，多次通知
	int count = Utility::FindFile(_handle, timeinfo, timeout);
	
	if (count <= 0)
		Utility::throwException(_handle);
}

}}