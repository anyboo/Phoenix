#pragma once
#include "DVR/DVR.h"
#include <vector>


namespace DVR{
	typedef struct SearchFileInfo
	{
		std::string fname;
		size_t		channel;
		__time64_t  stime;
		__time64_t  etime;
		size_t		fsize;
	}Search_fileInfo, *pSearch_fileInfo;

	class DVR_API DVRSearchFiles
	{
	public:
		DVRSearchFiles();
		~DVRSearchFiles();

		void GetFileInfoByName(const std::string sName, Search_fileInfo& sFileInfo);
		void GetSeachFilesInfo(std::vector<Search_fileInfo>& sFiles);
	
	private:
		std::vector<Search_fileInfo>		_search_files;
	};
}

