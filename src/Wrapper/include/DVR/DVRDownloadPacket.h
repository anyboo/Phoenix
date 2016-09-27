#pragma once
#include "DVR/DVR.h"
#include "DVRDownloadTask.h"
#include <map>

namespace DVR{
	class DVR_API DVRDownloadPacket
	{
	public:
		DVRDownloadPacket();
		~DVRDownloadPacket();

		void AddTask(DVRDownloadTask* Task);
		void GetMainTask();
		void GetTaskPacket(std::vector<DVRDownloadTask*>& TaskPacket);
		void DeleteWholeTask();
		void DeleteSubTaskByName(const std::string fname);
		
	private:
		std::vector<DVRDownloadTask*>		_DownloadPacket;
	};
}


