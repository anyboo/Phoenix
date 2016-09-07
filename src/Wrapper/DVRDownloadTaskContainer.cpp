#include "DVRDownloadTaskContainer.h"

namespace DVR{
	DVRDownloadTaskContainer::DVRDownloadTaskContainer()
		:_current_packet_id(0)
	{
	}


	DVRDownloadTaskContainer::~DVRDownloadTaskContainer()
	{
	}

	void DVRDownloadTaskContainer::AddTaskPacket(DVRDownloadTask* Task)
	{
		_current_packet_id = _Downloadpacket_Container.size() + 1;
		_Downloadpacket_Container.insert(std::pair<size_t, DVRDownloadTask*>(_current_packet_id, Task));
	}

	size_t DVRDownloadTaskContainer::GetNewAddTaskID()
	{
		return _current_packet_id;
	}

	DVRDownloadTask* DVRDownloadTaskContainer::GetTaskPacketByID(const size_t packet_id)
	{
		return _Downloadpacket_Container[packet_id];
	}

	void DVRDownloadTaskContainer::DeleteTaskPacket(const size_t packet_id)
	{
		DVRDownloadTask* task = _Downloadpacket_Container[packet_id];
		task->DeleteWholeTask();
		_Downloadpacket_Container.erase(packet_id);
	}

	void DVRDownloadTaskContainer::DeleteSubTask(const size_t packet_id, const std::string fname)
	{
		_Downloadpacket_Container[packet_id]->DeleteTaskByName(fname);
	}
}

