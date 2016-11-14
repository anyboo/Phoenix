
#include "DVR/DVRDownloadPakcetContainer.h"

namespace DVR{
	DVRDownloadPakcetContainer::DVRDownloadPakcetContainer()
	{
	}


	DVRDownloadPakcetContainer::~DVRDownloadPakcetContainer()
	{
		Clear();
	}

	void DVRDownloadPakcetContainer::AddDownloadItem(const std::string device_name, std::vector<size_t>& IDs, long current_time, const std::string search_time, const std::string downlaodpath)
	{
		Mutex::ScopedLock lock(_mutex);
		std::shared_ptr<DVRDownloadPacket> pDownloadItem = std::make_shared<DVRDownloadPacket>();
		pDownloadItem->AddTask(IDs);
		pDownloadItem->SetDeviceName(device_name);
		pDownloadItem->SetSearchTime(search_time);
		pDownloadItem->SetDownloadPath(downlaodpath);
		_DownloadItems[current_time] = pDownloadItem;
	}

	DVRDownloadPacket* DVRDownloadPakcetContainer::GetDownloadItem(const long  current_time)
	{
		Mutex::ScopedLock lock(_mutex);
		for (auto it = _DownloadItems.begin(); it != _DownloadItems.end(); it++)
		{
			if (it->first == current_time)
			{
				return it->second.get();
			}
		}
		return NULL;
	}

	void DVRDownloadPakcetContainer::DeleteDownloadItem(const long  current_time)
	{
		Mutex::ScopedLock lock(_mutex);
		for (auto it = _DownloadItems.begin(); it != _DownloadItems.end(); it++)
		{
			if (it->first == current_time)
			{
				DVRDownloadPacket *pDownload = it->second.get();
				pDownload->DeleteWholeTask();
				_DownloadItems.erase(it);
			}
		}
	}

	
	void DVRDownloadPakcetContainer::Clear()
	{
		Mutex::ScopedLock lock(_mutex);
		_DownloadItems.clear();
	}

	int DVRDownloadPakcetContainer::GetSize()
	{
		return _DownloadItems.size();
	}

	
}

