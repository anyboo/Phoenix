#pragma once
#include "DVR/DVR.h"
#include "DVRDownloadTask.h"
#include <map>

namespace DVR{
	class DVR_API DVRDownloadTaskContainer
	{
	public:
		DVRDownloadTaskContainer();
		~DVRDownloadTaskContainer();

		void AddTaskPacket(DVRDownloadTask* Task);
		std::string& GetNewAddTaskID();
		DVRDownloadTask* GetTaskPacketByName(const std::string KeyName);
		void DeleteTaskPacket(const std::string KeyName);
		void DeleteSubTask(const std::string KeyName, const std::string fname);

	private:
		std::string				_New_packetName;
		std::map<std::string, DVRDownloadTask*>		_Downloadpacket_Container;
	};
}


