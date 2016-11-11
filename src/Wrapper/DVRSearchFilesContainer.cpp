
#include "DVR/DVRSearchFilesContainer.h"

namespace DVR{
	DVRSearchFilesContainer::DVRSearchFilesContainer()
	{
	}


	DVRSearchFilesContainer::~DVRSearchFilesContainer()
	{
	}

	//void DVRSearchFilesContainer::Add(DVRSearchFiles* file)
	//{
	//	_Count++;
	//	_filesMap.insert(std::pair<size_t, DVRSearchFiles*>(_Count, file));
	//}

	void DVRSearchFilesContainer::Add(const std::vector<RecordFile> rf)
	{
		_recordfiles = rf;		
	}

	void DVRSearchFilesContainer::Clear()
	{		
		_recordfiles.clear();
	}

	

	void DVRSearchFilesContainer::GetSearchFiles( std::vector<RecordFile>& rf)
	{
		rf = _recordfiles;
				
	}


	void DVRSearchFilesContainer::GetDownloadfiles(const std::vector<size_t>& IDs, std::vector<RecordFile>& files)
	{
		for (size_t i = 0; i < IDs.size(); i++)
		{
			files.push_back(_recordfiles[IDs[i]]);
		}
	}

	

	RecordFile& DVRSearchFilesContainer::GetFileById(const size_t id)
	{
		return _recordfiles[id];
	}
}

