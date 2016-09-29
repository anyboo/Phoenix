#include "DVR/DVRDownloadPacket.h"
#include "time.h"
#include "DVR/DVRSearchFilesContainer.h"

namespace DVR{
	DVRDownloadPacket::DVRDownloadPacket()
	{
	}


	DVRDownloadPacket::~DVRDownloadPacket()
	{
	}

	void DVRDownloadPacket::AddTask(const std::vector<size_t>& IDs)
	{
		_downloadIDs = IDs;
		std::vector<RecordFile>	files;
		DVR::DVRSearchFilesContainer::getInstance().GetDownloadfiles(IDs, files);
		for (size_t i = 0; i < files.size(); i++)
		{
			Download_Info* download = new Download_Info;
			download->channel = files[i].channel;
			download->fname = files[i].name;
			download->fsize = files[i].size;
			download->lasttime = 99999999;
			download->proValue = 0;
			download->speed = 0;

			_DownloadPacket.push_back(download);
			_prev_proValue.push_back(0);
			_elapsed.push_back(0);
		}	
	}

	Download_Info* DVRDownloadPacket::GetTaskPacket(const size_t id)
	{
		return _DownloadPacket[id];
	}

	void DVRDownloadPacket::GetDownloadIDs(std::vector<size_t>& IDs)
	{
		IDs = _downloadIDs;
	}

	int DVRDownloadPacket::getTaskSize()
	{
		return _DownloadPacket.size();
	}

	void DVRDownloadPacket::DeleteWholeTask()
	{
		_DownloadPacket.clear();
		_elapsed.clear();
		_prev_proValue.clear();
		_downloadIDs.clear();
	}

	void DVRDownloadPacket::DeleteSubTask(const std::string fname, const size_t channel)
	{
		for (size_t i = 0; i < _DownloadPacket.size(); i++)
		{
			if (_DownloadPacket[i]->fname == fname && _DownloadPacket[i]->channel == channel)
			{
				_DownloadPacket.erase(_DownloadPacket.begin() + i);
				_elapsed.erase(_elapsed.begin() + i);
				_prev_proValue.erase(_prev_proValue.begin() + i);
			}
		}
	}
	void DVRDownloadPacket::GetMainTask(Download_Info& files_info)
	{
		size_t Task_Size = _DownloadPacket.size();
		size_t fsize = 0; int proValue = 0;
		int speed = 0; int lasttime = 0;
		std::vector<Download_Info*>::iterator itor;
		for (size_t i = 0; i < _DownloadPacket.size(); i++)
		{
			fsize += _DownloadPacket[i]->fsize;
			proValue += _DownloadPacket[i]->proValue;
			speed += _DownloadPacket[i]->speed;
			lasttime += _DownloadPacket[i]->lasttime;
		}
		proValue = proValue / Task_Size;
		files_info.fsize = fsize;
		if (speed == 0 && proValue != 100){
			files_info.lasttime = 99999999;
		}
		else if(speed != 0 && proValue != 100){
			files_info.lasttime = (100 - proValue) * fsize / speed;
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
		return _DownloadPacket.size();
	}

	void DVRDownloadPacket::UpdateDataByID(const size_t id, const int proValue)
	{
		_elapsed[id]++;
		if (proValue == 0)
			return;
		if (proValue != _prev_proValue[id] && proValue != 100)
		{
			_DownloadPacket[id]->speed = (proValue - _prev_proValue[id]) * _DownloadPacket[id]->fsize / (100 * _elapsed[id]);
			_DownloadPacket[id]->lasttime = (100 - proValue) *  _DownloadPacket[id]->fsize / _DownloadPacket[id]->speed;
			_prev_proValue[id] = proValue;
			_DownloadPacket[id]->proValue = proValue;
			_elapsed[id] = 0;
		}
		if (_elapsed[id] >= 5)
		{
			_DownloadPacket[id]->speed = 0;
			_DownloadPacket[id]->lasttime = 99999999;
		}
		if (proValue == 100)
		{
			_DownloadPacket[id]->lasttime = 0;
			_DownloadPacket[id]->speed = 0;
			_DownloadPacket[id]->proValue = 100;
		}
	}

}

