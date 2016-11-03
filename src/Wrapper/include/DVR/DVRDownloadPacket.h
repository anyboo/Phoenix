#pragma once
#include "DVR/DVR.h"
#include <map>
#include <vector>
#include <memory>
#include "Poco/SingletonHolder.h"
#include "DVR/DVRSearchFilesContainer.h"
#include "Poco/Mutex.h"
#include <iostream>
using Poco::Mutex;

namespace DVR{

	typedef enum
	{
		DL_STATUS_WAITING = 0,
		DL_STATUS_DOWNLOADING,
		DL_STATUS_FINISH
	};

	typedef struct DOWNLOADINFO
	{
		std::string fname;
		size_t		fsize;
		size_t		channel;
		int			proValue;
		int			speed;
		long		lasttime;
		int         id;
		int         status;
		int         order;
		long        starttime;
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

		void AddTask(const std::string devicename, std::vector<size_t>& IDs);
		void GetMainTask(Download_Info& files_info);
		void GetDownloadIDs(std::vector<size_t>& IDs);
		int	getTaskSize();
		Download_Info* GetTaskPacket(const size_t id);
		void DeleteWholeTask();
		int GetDownloadSize();
		void DeleteSubTask(const std::string fname, const size_t channel);
		void UpdateDataByID(const size_t id, const int proValue);
		void GetDownloading(std::vector<size_t>& ids);
		int  GetDownloadStatus(const size_t id);
		void SetDownloadStatus(const size_t id, const int status);
		
	private:
		std::map<std::string, std::deque<std::shared_ptr<Download_Info>>>		_DownloadPacket;		
		std::vector<std::shared_ptr<Download_Info>>				_downloadIDs;
		Mutex                              _mutex;
	};
}


