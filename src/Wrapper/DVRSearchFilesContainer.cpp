
#include "DVR/DVRSearchFilesContainer.h"

namespace DVR{
	DVRSearchFilesContainer::DVRSearchFilesContainer() :_Count(0)
	{
	}


	DVRSearchFilesContainer::~DVRSearchFilesContainer()
	{
	}

	void DVRSearchFilesContainer::Add(DVRSearchFiles* file)
	{
		_Count++;
		_filesMap.insert(std::pair<size_t, DVRSearchFiles*>(_Count, file));
	}

	void DVRSearchFilesContainer::Clear()
	{
		_filesMap.clear();
		_Count = 0;
	}

	void DVRSearchFilesContainer::GetSearchFiles(std::vector<DVRSearchFiles*>& files)
	{
		std::map<size_t, DVRSearchFiles*>::iterator itor;
		for (itor = _filesMap.begin(); itor != _filesMap.end(); itor++)
		{
			files.push_back(itor->second);
		}
	}

	void DVRSearchFilesContainer::GetDownloadFilesByID(std::vector<size_t>& fileIDs, std::vector<DVRSearchFiles*>& files)
	{
		std::vector<const size_t>::iterator itor;
		for (itor = fileIDs.begin(); itor != fileIDs.end(); itor++)
		{
			files.push_back(_filesMap[*itor]);
		}
	}

	DVRSearchFiles* DVRSearchFilesContainer::GetPlayFileById(const size_t id)
	{
		return _filesMap[id];
	}
}

