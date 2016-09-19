
#include "DVR/DVRDownloadPakcetContainer.h"

namespace DVR{
	DVRDownloadPakcetContainer::DVRDownloadPakcetContainer()
	{
	}


	DVRDownloadPakcetContainer::~DVRDownloadPakcetContainer()
	{
	}

	void DVRDownloadPakcetContainer::AddPacket(DVRDownloadPacket* packet)
	{
		std::string keyname = std::string("packet") + std::to_string(rand());
		_packetContainer.insert(std::pair<std::string, DVRDownloadPacket*>(keyname, packet));
	}

	DVRDownloadPacket* DVRDownloadPakcetContainer::GetPacket(const std::string name)
	{
		return _packetContainer[name];
	}

	void DVRDownloadPakcetContainer::DeletePacketTask(const std::string name)
	{
		_packetContainer[name]->DeleteWholeTask();
		_packetContainer.erase(name);
	}

	void DVRDownloadPakcetContainer::DeleteSubTask(const std::string name, const std::string fname)
	{
		_packetContainer[name]->DeleteSubTaskByName(fname);
	}
}

