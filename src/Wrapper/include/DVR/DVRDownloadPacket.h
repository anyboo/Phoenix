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
		long        starttime;
		long        handle;		
		RecordFile  rfile; 
	}Download_Info, *pDownload_Info;
	class DVR_API DVRDownloadPacket
	{
	public:
		DVRDownloadPacket();
		~DVRDownloadPacket();

		
		void AddTask(std::vector<size_t>& IDs);
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
		void GetDeivceName(std::string& devicename);
		void SetDeviceName(const std::string devicename);
		void GetSearchTime(std::string& searchname);
		void SetSearchTime(const std::string searchname);
		long GetDownloadHandle(const size_t id);
		void SetDownloadHandle(const size_t id, const long handle);
		
	private:
		std::map<std::string, std::deque<std::shared_ptr<Download_Info>>>		_DownloadPacket;		
		std::vector<std::shared_ptr<Download_Info>>				_downloadIDs;
		Mutex                              _mutex;
		std::string                        _device_name;
		std::string                        _search_time;
	};
}


