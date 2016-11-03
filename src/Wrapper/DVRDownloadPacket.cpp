#include "DVR/DVRDownloadPacket.h"
#include "time.h"
#include "DVR/DVRSearchFilesContainer.h"

namespace DVR{
	DVRDownloadPacket::DVRDownloadPacket()
	{
	}


	DVRDownloadPacket::~DVRDownloadPacket()
	{
		_downloadIDs.clear();
	}

	void DVRDownloadPacket::AddTask(const std::string devicename, std::vector<size_t>& IDs)
	{		
		std::vector<RecordFile>	files;
		DVR::DVRSearchFilesContainer::getInstance().GetDownloadfiles(IDs, files);
		Mutex::ScopedLock lock(_mutex);
	
		for (size_t i = 0; i < files.size(); i++)
		{
			std::shared_ptr<Download_Info> download = std::make_shared<Download_Info>();			
			download->channel = files[i].channel;
			char name[100] = { 0 };
			sprintf_s(name, "%d%02d%02d%02d%02d-%d%02d%02d%02d%02d",
				files[i].beginTime.year(), files[i].beginTime.month(), files[i].beginTime.day(), files[i].beginTime.hour(), files[i].beginTime.minute(),
				files[i].endTime.year(), files[i].endTime.month(), files[i].endTime.day(), files[i].endTime.hour(), files[i].endTime.minute());
			download->fname = std::string(name);
			download->fsize = files[i].size;
			download->lasttime = 99999999;
			download->proValue = 0;
			download->speed = 0;
			download->id = IDs[i];
			download->status = DL_STATUS_WAITING;
			download->order = i;
			download->starttime = 0;

			std::string ipchannel = devicename + " " + std::to_string(files[i].channel);
			auto it = _DownloadPacket.find(ipchannel);
			if (it != _DownloadPacket.end())
			{
				_DownloadPacket[ipchannel].push_back(download);
			}
			else
			{
				std::deque<std::shared_ptr<Download_Info>> qdowninfo;
				qdowninfo.push_back(download);
				_DownloadPacket[ipchannel] = qdowninfo;
			}
			_downloadIDs.push_back(download);					
		}		
	}

	Download_Info* DVRDownloadPacket::GetTaskPacket(const size_t id)
	{
		for (int i = 0; i < _downloadIDs.size(); i++)
		{
			if (id == _downloadIDs[i]->id)
				return _downloadIDs[i].get();
		}
		return NULL;		
	}

	void DVRDownloadPacket::GetDownloading(std::vector<size_t>& ids)
	{
		
		Mutex::ScopedLock lock(_mutex);
		for (auto it = _DownloadPacket.begin(); it != _DownloadPacket.end(); it++)
		{		
			//std::cout << "deque size: " <<  it->second.size() << std::endl;
			if (it->second.size() > 0)
			{
				ids.push_back(it->second.front()->id);
			}

		}			
	}
	
	int  DVRDownloadPacket::GetDownloadStatus(const size_t id)
	{		
		for (auto it = _DownloadPacket.begin(); it != _DownloadPacket.end(); it++)
		{
			for (int i = 0; i < it->second.size(); i++)
			{
				if (id == it->second[i]->id)
				{
					return it->second[i]->status;
				}
			}
		}		
		return -1;
	}

	void DVRDownloadPacket::SetDownloadStatus(const size_t id, const int status)
	{		
		for (auto it = _DownloadPacket.begin(); it != _DownloadPacket.end(); it++)
		{
			for (int i = 0; i < it->second.size(); i++)
			{
				if (id == it->second[i]->id)
				{
					it->second[i]->status = status;
					if (status == DL_STATUS_FINISH)
					{
						std::cout << "i: " << i << " id: " << it->second[i]->id << " order: " << it->second[i]->order  << " size: " << it->second.size() << std::endl;						
						it->second.pop_front();
					}	
					return;
				}
			}
		}
		
	}

	void DVRDownloadPacket::GetDownloadIDs(std::vector<size_t>& IDs)
	{
		for (int i = 0; i < _downloadIDs.size(); i++)
		{
			IDs.push_back(_downloadIDs[i]->id);
		}		
	}

	int DVRDownloadPacket::getTaskSize()
	{
		int taskcount = 0;
		Mutex::ScopedLock lock(_mutex);
		for (auto it = _DownloadPacket.begin(); it != _DownloadPacket.end(); it++)
		{
			taskcount += it->second.size();
		}
		
		return taskcount;
	}

	void DVRDownloadPacket::DeleteWholeTask()
	{
		Mutex::ScopedLock lock(_mutex);
		for (auto it = _DownloadPacket.begin(); it != _DownloadPacket.end(); it++)
		{			
			it->second.clear();
		}
		_DownloadPacket.clear();		
		_downloadIDs.clear();
	}

	void DVRDownloadPacket::DeleteSubTask(const std::string fname, const size_t channel)
	{
		Mutex::ScopedLock lock(_mutex);
		for (auto it = _DownloadPacket.begin(); it != _DownloadPacket.end(); it++)
		{
			for (int i = 0; i < it->second.size(); i++)
			{
				if (fname == it->second[i]->fname && channel == it->second[i]->channel)
				{					
					it->second.erase(it->second.begin() + i);					
				}
			}
		}		
	}

	void DVRDownloadPacket::GetMainTask(Download_Info& files_info)
	{
		size_t Task_Size = _downloadIDs.size();
		size_t fsize = 0; int proValue = 0;
		int speed = 0; int lasttime = 0;
		std::vector<Download_Info*>::iterator itor;
		for (int i = 0; i < _downloadIDs.size(); i++)
		{
			
			fsize += _downloadIDs[i]->fsize;
			proValue += _downloadIDs[i]->proValue;
			if (_downloadIDs[i]->status == DL_STATUS_DOWNLOADING)
				speed += _downloadIDs[i]->speed;			
		}
		
		proValue = proValue / Task_Size;
		
		files_info.fsize = fsize;
		if (speed == 0 && proValue != 100){
			files_info.lasttime = 99999999;
		}
		else if(speed != 0 && proValue != 100){
			files_info.lasttime = (100 - proValue) * fsize / speed / 100;
		}
		else if (proValue == 100){
			files_info.lasttime = 0;
		}
		files_info.speed = speed;
		files_info.proValue = proValue;
		files_info.fname = std::string("DZP_download");
	}

	int DVRDownloadPacket::GetDownloadSize()
	{
		return _downloadIDs.size();
	}

	void DVRDownloadPacket::UpdateDataByID(const size_t id, const int proValue)
	{
		std::cout << "id: " << id << " provalue: " << proValue << std::endl;

		Mutex::ScopedLock lock(_mutex);

		if (proValue == 0)
			return;

		for(int i = 0; i < _downloadIDs.size(); i++)
		{
			if (id == _downloadIDs[i]->id)
			{				
				if (_downloadIDs[i]->starttime == 0 && _downloadIDs[i]->status == DL_STATUS_DOWNLOADING)
				{			
					long time1 = GetTickCount();
					std::cout << "start time :" << time1 << std::endl;
					_downloadIDs[i]->starttime = time1;	
					return;
				}
								 
				_downloadIDs[i]->proValue = proValue;
				long cur_time = GetTickCount();
				std::cout << "exec time: " << cur_time - _downloadIDs[i]->starttime << std::endl;
				if (cur_time - _downloadIDs[i]->starttime != 0)
					_downloadIDs[i]->speed = (_downloadIDs[i]->fsize * proValue / 100) * 1000  / (GetTickCount() - _downloadIDs[i]->starttime);
				std::cout << "id: " << id << " speed: " << _downloadIDs[i]->speed << std::endl;
				if (_downloadIDs[i]->speed != 0)
					_downloadIDs[i]->lasttime = (_downloadIDs[i]->fsize * (100 - proValue) / 100) / _downloadIDs[i]->speed;

				return;
				
			}
				
		}

	}
}

