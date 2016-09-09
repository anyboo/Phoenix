#include "DVR/DVRDownloadTaskContainer.h"
#include "time.h"

namespace DVR{
	DVRDownloadTaskContainer::DVRDownloadTaskContainer()
		:_New_packetName("")
	{
	}


	DVRDownloadTaskContainer::~DVRDownloadTaskContainer()
	{
	}

	void DVRDownloadTaskContainer::AddTaskPacket(DVRDownloadTask* Task)
	{
		std::string KeyName = std::string("packet") + std::to_string(rand());
		_New_packetName = KeyName;
		_Downloadpacket_Container.insert(std::pair<std::string, DVRDownloadTask*>(KeyName, Task));
	}

	std::string DVRDownloadTaskContainer::GetNewAddTaskID()
	{
		return _New_packetName;
	}

	DVRDownloadTask* DVRDownloadTaskContainer::GetTaskPacketByName(const std::string KeyName)
	{
		return _Downloadpacket_Container[KeyName];
	}

	bool DVRDownloadTaskContainer::DeleteTaskPacket(const std::string KeyName)
	{
		DVRDownloadTask* task = _Downloadpacket_Container[KeyName];
		bool bRet = task->DeleteWholeTask();
		_Downloadpacket_Container.erase(KeyName);
		return bRet;
	}

	bool DVRDownloadTaskContainer::DeleteSubTask(const std::string KeyName, const std::string fname)
	{
		return _Downloadpacket_Container[KeyName]->DeleteTaskByName(fname);
	}
}

