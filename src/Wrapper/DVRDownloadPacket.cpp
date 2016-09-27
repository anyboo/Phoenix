#include "DVR/DVRDownloadPacket.h"
#include "time.h"

namespace DVR{
	DVRDownloadPacket::DVRDownloadPacket()
	{
	}


	DVRDownloadPacket::~DVRDownloadPacket()
	{
	}

	void DVRDownloadPacket::AddTask(DVRDownloadTask* Task)
	{
		_DownloadPacket.push_back(Task);
	}

	void DVRDownloadPacket::DeleteWholeTask()
	{
		std::vector<DVRDownloadTask*>::iterator itor;
		for (itor == _DownloadPacket.begin(); itor != _DownloadPacket.end(); itor++)
		{
			std::string fname = (*itor)->fname();
			(*itor)->DeleteTaskByName(fname);
			_DownloadPacket.erase(itor);
		}
	}

	void DVRDownloadPacket::DeleteSubTaskByName(const std::string fname)
	{
		std::vector<DVRDownloadTask*>::iterator itor;
		for (itor == _DownloadPacket.begin(); itor != _DownloadPacket.end(); itor++)
		{
			if ((*itor)->fname() == fname){
				(*itor)->DeleteTaskByName(fname);
				_DownloadPacket.erase(itor);break;
			}
		}
	}
	void DVRDownloadPacket::GetMainTask()
	{
		size_t fsize = 0, proValue = 0, speed = 0, elapsedTime = 0;
		size_t Task_Size = _DownloadPacket.size();
		std::vector<DVRDownloadTask*>::iterator itor;
		for (itor == _DownloadPacket.begin(); itor != _DownloadPacket.end(); itor++)
		{
			fsize += (*itor)->fsize();
			proValue += (*itor)->proValue();
			speed += (*itor)->speed();
			elapsedTime += (*itor)->elapsedTime();
		}
		proValue = proValue / Task_Size;
	}

	void DVRDownloadPacket::GetTaskPacket(std::vector<DVRDownloadTask*>& TaskPacket)
	{
		TaskPacket = _DownloadPacket;
	}

}

