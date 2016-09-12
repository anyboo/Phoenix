#include "DZP/DVRStatementImpl.h"
#include "DZP/Notifier.h"

#include <vector>
#include <sstream>
#include "netsdk.h"

namespace DVR {
namespace DZPLite {

DVRStatementImpl::DVRStatementImpl(DVR::DVRSessionImpl& rSession, Utility::HANDLE pDvr):
DVR::DVRStatementImpl(rSession),
_handle(pDvr)
{
}


DVRStatementImpl::~DVRStatementImpl()
{
}

void DVRStatementImpl::download()
{
	Record fileinfo;
	std::string newname;
	if (!Utility::readStream(_handle, fileinfo, newname))
	{
		Condition t;
		std::string filename;
		if (Utility::readStream(_handle, t, filename))
		{
			int err = Utility::lastError();
			Utility::throwException(err, "download is failed!");
		}
	}
}

void DVRStatementImpl::play()
{

}

void DVRStatementImpl::donwloadByName(const std::string& filename)
{
	Record fileinfo;
	if (Utility::readStream(_handle, fileinfo, filename))
	{
		int err = Utility::lastError();
		Utility::throwException(err, "download is failed!");
	}
}

void DVRStatementImpl::downloadByTime(const Poco::DateTime& time)
{
	Condition t;
	std::string filename;
	if (Utility::readStream(_handle, t, filename))
	{
		int err = Utility::lastError();
		Utility::throwException(err, "download is failed!");
	}
}

void DVRStatementImpl::playByName(const std::string& filename)
{
	/*
	Utility::FILEINFO fileinfo;
	int rc = Utility::Playback(_handle, fileinfo);
	
	if (Utility::success != rc)
		Utility::throwException(_handle);
	*/
}

void DVRStatementImpl::playByTime(const Poco::DateTime& time)
{
	/*
	Utility::CONDITION cond;
	Utility::TIMEINFO timeinfo;

	int rc = Utility::Playback(_handle, timeinfo);

	if (Utility::success != rc)
		Utility::throwException(_handle);
	*/
}

/*
list 需要异步操作
*/
void DVRStatementImpl::list(const Poco::DateTime& beginTime, const Poco::DateTime& endTime)
{
	/*
	Utility::CONDITION condition;
	Utility::TIMEINFO timeinfo;
	std::size_t timeout = 3000;
	std::vector<RESULT> result(1000);
	int count = 0;
	int maxCount = 1000;
	int timeout = 5000;
	//将多天的查询范围，切分成1天的范围多次查询，多次通知
	int count = Utility::FindFile(_handle, timeinfo, timeout);
	
	if (count <= 0)
		Utility::throwException(_handle);
	*/
}

}}