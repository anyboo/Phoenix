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
		size_t GetNewAddTaskID();
		DVRDownloadTask* GetTaskPacketByID(const size_t packet_id);
		void DeleteTaskPacket(const size_t packet_id);
		void DeleteSubTask(const size_t packet_id, const std::string fname);

	private:
		size_t	_current_packet_id;
		std::map<size_t, DVRDownloadTask*>		_Downloadpacket_Container;
	};
}


