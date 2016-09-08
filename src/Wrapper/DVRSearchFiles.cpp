
#include "DVRSearchFiles.h"
#include <time.h>

namespace DVR{
	DVRSearchFiles::DVRSearchFiles()
	{
	}


	DVRSearchFiles::~DVRSearchFiles()
	{
	}


	void DVRSearchFiles::GetSeachFilesInfo(std::vector<Search_fileInfo>& sFiles)
	{
		_search_files.clear();
		time_t now_time;
		now_time = time(&now_time);
		for (size_t i = 0; i < 4; i++)
		{
			Search_fileInfo files;
			files.channel = i;
			files.stime = now_time - 10000;
			files.etime = now_time;
			files.fsize = 141231;
			files.fname = std::string("filename") + std::to_string(i);
			_search_files.push_back(files);
		}
		sFiles = _search_files;
	}

	void DVRSearchFiles::GetFileInfoByName(const std::string sName, Search_fileInfo& sFileInfo)
	{
		for (size_t i = 0; i < _search_files.size(); i++)
		{
			if (_search_files[i].fname == sName)
			{
				sFileInfo = _search_files[i];
			}
		}
	}
}

