#pragma once
#include "DVR/DVR.h"
#include <vector>


namespace DVR{
	typedef struct Downloadpacket
	{
		std::string fname;
		size_t		fsize;
		size_t		proValue;
		size_t		speed;
		size_t		lastTime;
	}Download_packet, *pDownload_packet;

	class DVR_API DVRDownloadTask
	{
	public:
		DVRDownloadTask();
		~DVRDownloadTask();
	
		void GetDownloadPacketInfo(std::vector<Download_packet>& TaskPacket);
		bool DeleteWholeTask();
		bool DeleteTaskByName(const std::string fName);

	protected:
		void InitDownloadPacketInfo();
		
	private:
		std::vector<Download_packet>		_TaskPacket_Info;
	};
}


