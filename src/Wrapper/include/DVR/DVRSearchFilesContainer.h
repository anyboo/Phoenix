#pragma once
#include "DVR/DVR.h"
#include <vector>
#include <map>
#include <Poco/DateTime.h>
#include "DVR/DVRSearchFiles.h"

namespace DVR{

	class DVR_API DVRSearchFilesContainer
	{
	public:
		DVRSearchFilesContainer();
		~DVRSearchFilesContainer();

		void Add(DVRSearchFiles* file);
		void Clear();
		void GetSearchFiles(std::vector<DVRSearchFiles*>& files);
		void GetDownloadFilesByID(std::vector<size_t>& fileIDs, std::vector<DVRSearchFiles*>& files);
		DVRSearchFiles* GetPlayFileById(const size_t id);

	private:
		std::map<size_t, DVRSearchFiles*>		_filesMap;
		size_t					_Count;
	};
}


