#include "DVR/DVRDownloadTask.h"
//#include "DVRSearchFiles.h"

namespace DVR{
	DVRDownloadTask::DVRDownloadTask()
	{
		InitDownloadPacketInfo();
	}

	DVRDownloadTask::~DVRDownloadTask()
	{
	}

	void DVRDownloadTask::InitDownloadPacketInfo()
	{
	//	DVRSearchFiles Search;
		Download_packet taskinfo;
	//	std::vector<Search_fileInfo>	files;
	//	Search.GetSeachFilesInfo(files);
		for (size_t i = 0; i < 4; i++)
		{
			taskinfo.fname = std::string("task") + std::to_string(i);
			taskinfo.fsize = 123123;
			taskinfo.lastTime = 0;
			taskinfo.proValue = 0;
			taskinfo.speed = 0;
			_TaskPacket_Info.push_back(taskinfo);
		}
	}

	void DVRDownloadTask::GetDownloadPacketInfo(std::vector<Download_packet>& TaskPacket)
	{
		TaskPacket = _TaskPacket_Info;
	}

	bool DVRDownloadTask::DeleteWholeTask()
	{
		_TaskPacket_Info.clear();
		if (_TaskPacket_Info.empty())
			return true;
		return false;
	}

	bool DVRDownloadTask::DeleteTaskByName(const std::string fName)
	{
		for (size_t i = 0; i < _TaskPacket_Info.size(); i++)
		{
			if (_TaskPacket_Info[i].fname == fName)
			{
				_TaskPacket_Info.erase(_TaskPacket_Info.begin() + i);
				return true;
			}
		}
		return false;
	}
}




