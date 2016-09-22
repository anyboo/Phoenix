#pragma once
#include "DVR/DVR.h"
#include <vector>
#include <map>
#include <Poco/DateTime.h>
#include "DVR/DVRSearchFiles.h"
#include <Poco/SingletonHolder.h>
#include "DVR/DVRStatement.h"

namespace DVR{

	class DVR_API DVRSearchFilesContainer
	{
	public:
		DVRSearchFilesContainer();
		~DVRSearchFilesContainer();

		static DVRSearchFilesContainer& getInstance()
		{
			static Poco::SingletonHolder<DVRSearchFilesContainer> Ds;
			return *Ds.get();
		}

		void Add(DVRSearchFiles* file);
		void Add(const std::vector<RecordFile> rf);
		void Clear();
		void GetSearchFiles(std::vector<RecordFile>& rf);
		void GetSearchFiles(std::vector<DVRSearchFiles*>& files);
		void GetDownloadFilesByID(std::vector<size_t>& fileIDs, std::vector<DVRSearchFiles*>& files);
	//	DVRSearchFiles* GetPlayFileById(const size_t id);
		RecordFile& GetPlayFileById(const size_t id);

	private:
		std::vector<RecordFile>				_recordfiles;
		std::map<size_t, DVRSearchFiles*>		_filesMap;
		size_t					_Count;

		DVRSearchFilesContainer(const DVRSearchFilesContainer&);
		DVRSearchFilesContainer operator =(const DVRSearchFilesContainer&);
	};
}


