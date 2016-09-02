#include "DVR/DVRStatementImpl.h"
#include <Poco/DateTimeParser.h>
namespace DVR {

DVRStatementImpl::DVRStatementImpl(DVRSessionImpl& rSession):
_rSession(rSession)
{
}


DVRStatementImpl::~DVRStatementImpl()
{
}

void DVRStatementImpl::beginList(const std::string& beginTime, const std::string& endTime)
{
	int timeZoneDifferential = 0;
	Poco::DateTime begin = Poco::DateTimeParser::parse(beginTime, timeZoneDifferential);
	Poco::DateTime end = Poco::DateTimeParser::parse(endTime, timeZoneDifferential);
	list(begin, end);
}

void DVRStatementImpl::beginDownload(const std::string& filename)
{
	if (canDownloadByName())
		donwloadByName(filename);
	else
	{
		Poco::DateTime time;
		downloadByTime(time);
	}
		
}

void DVRStatementImpl::play(const std::string& filename)
{
	if (canPlayByName())
		playByName(filename);
	else
	{
		Poco::DateTime time;
		playByTime(time);
	}
}

void DVRStatementImpl::abort()
{

}

}

