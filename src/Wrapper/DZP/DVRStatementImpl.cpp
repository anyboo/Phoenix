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

//void DVRStatementImpl::download()
//{
//	Record fileinfo;
//	std::string newname;
//	if (!Utility::readStream(_handle, fileinfo, newname))
//	{
//		Condition t;
//		std::string filename;
//		if (Utility::readStream(_handle, t, filename))
//		{
//			int err = Utility::lastError();
//			Utility::throwException(err, "download is failed!");
//		}
//	}
//}
//
//void DVRStatementImpl::play()
//{
//
//}


long DVRStatementImpl::donwloadByName(const RecordFile& rf, const std::string& filename)
{
	Record fileinfo;
	fileinfo.ch = rf.channel;
	memcpy(fileinfo.sFileName, rf.name.c_str(), rf.name.length());
	fileinfo.size = rf.size;
	fileinfo.stBeginTime = { 0 };
	fileinfo.stEndTime = { 0 };
	fileinfo.stBeginTime.year = rf.beginTime.year();
	fileinfo.stBeginTime.month = rf.beginTime.month();
	fileinfo.stBeginTime.day = rf.beginTime.day();
	fileinfo.stBeginTime.hour = rf.beginTime.hour();
	fileinfo.stBeginTime.minute = rf.beginTime.minute();
	fileinfo.stBeginTime.second = rf.beginTime.second();
	fileinfo.stEndTime.year = rf.endTime.year();
	fileinfo.stEndTime.month = rf.endTime.month();
	fileinfo.stEndTime.day = rf.endTime.day();
	fileinfo.stEndTime.hour = rf.endTime.hour();
	fileinfo.stEndTime.minute = rf.endTime.minute();
	fileinfo.stEndTime.second = rf.endTime.second();

	long dhandle = Utility::readStream(_handle, fileinfo, filename);
	if (dhandle <= 0)
	{
		int err = Utility::lastError();
		Utility::throwException(err, "download is failed!");
	}
	return dhandle;
}

int DVRStatementImpl::getdownloadPos(const long handle)
{
	int pos = Utility::readStreamPos(handle);
	return pos;
}

void DVRStatementImpl::stopDownload(const long handle)
{
	Utility::stopStream(handle);
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

int DVRStatementImpl::playByName(const RecordFile& filename, HWND& hwnd)
{
	Record rf;
	rf.ch = filename.channel;
	rf.hWnd = hwnd;
	rf.stBeginTime = { 0 };
	rf.stEndTime = { 0 };
	rf.stBeginTime.year = filename.beginTime.year();
	rf.stBeginTime.month = filename.beginTime.month();
	rf.stBeginTime.day = filename.beginTime.day();
	rf.stBeginTime.hour = filename.beginTime.hour();
	rf.stBeginTime.minute = filename.beginTime.minute();
	rf.stBeginTime.second = filename.beginTime.second();
	rf.stEndTime.year = filename.endTime.year();
	rf.stEndTime.month = filename.endTime.month();
	rf.stEndTime.day = filename.endTime.day();
	rf.stEndTime.hour = filename.endTime.hour();
	rf.stEndTime.minute = filename.endTime.minute();
	rf.stEndTime.second = filename.endTime.second();
	memcpy(rf.sFileName, filename.name.c_str(), filename.name.length());
	rf.size = filename.size;

	paly_handle = Utility::playStream(_handle, rf);
	return paly_handle;
}

void DVRStatementImpl::stopPlayback(int playhandle)
{
	bool rc = Utility::stopStream(playhandle);
}

int DVRStatementImpl::getplayPos(const int playhandle)
{
	int pos = Utility::playPos(playhandle);
	return pos;
}

void DVRStatementImpl::setplayPos(const int playhandle, const int proValue)
{
	Utility::seek(playhandle, proValue);
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
void DVRStatementImpl::ChangeTime(const Poco::DateTime& datatime, __time64_t& outTime)
{
	struct tm InTime = { 0 };
	InTime.tm_year = datatime.year() - 1900;
	InTime.tm_mon = datatime.month() - 1;
	InTime.tm_mday = datatime.day();
	InTime.tm_hour = datatime.hour();
	InTime.tm_min = datatime.minute();

	outTime = mktime(&InTime);
}


void DVRStatementImpl::list(const Poco::DateTime& beginTime, const Poco::DateTime& endTime, const std::vector<int>& channels, std::vector<RecordFile>& files)
{
	int maxCount = 1000;
	int ONEDAY = 24 * 60 * 60;
	__time64_t timeBegin, timeEnd;
	ChangeTime(beginTime, timeBegin);
	ChangeTime(endTime, timeEnd);

	Poco::DateTime TmpTime(beginTime.year(), beginTime.month(), beginTime.day());
	__time64_t everytime, startTime, stopTime;
	ChangeTime(TmpTime, everytime);
	startTime = timeBegin;

	if (beginTime.day() == endTime.day() && beginTime.month() == endTime.month() && beginTime.year() == endTime.year())
	{
		startTime = timeBegin;
		stopTime = timeEnd;
	}
	for (; everytime < timeEnd; everytime += ONEDAY)
	{
		if (beginTime.day() != endTime.day() || beginTime.month() != endTime.month() || beginTime.year() != endTime.year())
		{
			if (startTime == timeBegin)
			{
				timeBegin += 1;
				stopTime = everytime + ONEDAY - 1;
			}
			else
			{
				startTime = everytime;
				if ((everytime + ONEDAY) > timeEnd)
				{
					stopTime = timeEnd;
				}
				else{
					stopTime = everytime + ONEDAY - 1;
				}

			}

		}

		struct tm startTM, stopTM;
		_localtime64_s(&startTM, (const time_t*)&startTime);
		_localtime64_s(&stopTM, (const time_t*)&stopTime);

		H264_DVR_TIME startTime, stopTime;
		startTime.dwYear = startTM.tm_year + 1900;
		startTime.dwMonth = startTM.tm_mon + 1;
		startTime.dwDay = startTM.tm_mday;
		startTime.dwHour = startTM.tm_hour;
		startTime.dwMinute = startTM.tm_min;
		startTime.dwSecond = 0;

		stopTime.dwYear = stopTM.tm_year + 1900;
		stopTime.dwMonth = stopTM.tm_mon + 1;
		stopTime.dwDay = stopTM.tm_mday;
		stopTime.dwHour = stopTM.tm_hour;
		stopTime.dwMinute = stopTM.tm_min;
		stopTime.dwSecond = 0;

		Condition cond;

		cond.nFileType = SDK_File_Type::SDK_RECORD_ALL;
		cond.startTime = startTime;
		cond.endTime = stopTime;
		cond.hWnd = 0;
		memset(cond.szFileName, 0, 32);

		
		int timeout = 5000;
		//将多天的查询范围，切分成1天的范围多次查询，多次通知
		//	int count = Utility::FindFile(_handle, timeinfo, timeout);
		for (size_t n = 0; n < channels.size(); n++)
		{
			cond.nChannelN0 = channels[n];

			Record* _pRecord = nullptr;
			_pRecord = new Record[100];
			size_t findcount = Utility::findStream(_handle, cond, *_pRecord, 100);

			//	if (findcount <= 0)
			//		Utility::throwException(_handle);
			RecordFile rf;
			for (size_t i = 0; i < findcount; i++)
			{
				rf.name = _pRecord[i].sFileName;
				rf.size = _pRecord[i].size;
				rf.beginTime = Poco::DateTime(_pRecord[i].stBeginTime.year, _pRecord[i].stBeginTime.month, _pRecord[i].stBeginTime.day, \
					_pRecord[i].stBeginTime.hour, _pRecord[i].stBeginTime.minute, _pRecord[i].stBeginTime.second);
				rf.endTime = Poco::DateTime(_pRecord[i].stEndTime.year, _pRecord[i].stEndTime.month, _pRecord[i].stEndTime.day, \
					_pRecord[i].stEndTime.hour, _pRecord[i].stEndTime.minute, _pRecord[i].stEndTime.second);
				rf.channel = _pRecord[i].ch;
				files.push_back(rf);
			}
		}
	}
	
}

}}