#pragma once
#include "DVR/DVR.h"
#include "DVR/DVRDownloadPakcetContainer.h"
#include "DVR/DVRDownloadPacket.h"

namespace DVR{
	class DVR_API DVRDownloadPakcetContainer
	{
	public:
		DVRDownloadPakcetContainer();
		~DVRDownloadPakcetContainer();

		void AddPacket(DVRDownloadPacket* packet);
		DVRDownloadPacket* GetPacket(const std::string name);
		void DeletePacketTask(const std::string name);
		void DeleteSubTask(const std::string name, const std::string fname);

	private:
		std::map<std::string, DVRDownloadPacket*>		_packetContainer;
	};
}


