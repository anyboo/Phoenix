
#include "DVRSearchFiles.h"

namespace DVR{
	DVRSearchFiles::DVRSearchFiles()
	{
	}


	DVRSearchFiles::~DVRSearchFiles()
	{
	}


	void DVRSearchFiles::GetSeachFilesInfo(std::vector<Search_fileInfo>& sFiles)
	{
		//_search_files ;
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

