#pragma once
#include "DVR/DVR.h"
#include <map>
#include <vector>
#include "Poco/SingletonHolder.h"
#include "DVR/DVRSearchFilesContainer.h"

namespace DVR{
	typedef struct DOWNLOADINFO
	{
		std::string fname;
		size_t		fsize;
		size_t		channel;
		int			proValue;
		int			speed;
		int			lasttime;
	}Download_Info, *pDownload_Info;
	class DVR_API DVRDownloadPacket
	{
	public:
		DVRDownloadPacket();
		~DVRDownloadPacket();

		static DVRDownloadPacket& getInstance()
		{
			static Poco::SingletonHolder<DVRDownloadPacket>	sing;
			return *sing.get();
		}

		void AddTask(const std::vector<size_t>& IDs);
		void GetMainTask(Download_Info& files_info);
		void GetDownloadIDs(std::vector<size_t>& IDs);
		int	getTaskSize();
		Download_Info* GetTaskPacket(const size_t id);
		void DeleteWholeTask();
		int GetDownloadSize();
		void DeleteSubTask(const std::string fname, const size_t channel);
		void UpdateDataByID(const size_t id, const int proValue);
		
	private:
		std::vector<pDownload_Info>		_DownloadPacket;
		std::vector<int>				_prev_proValue;
		std::vector<int>				_elapsed;
		std::vector<size_t>				_downloadIDs;
	};
}


