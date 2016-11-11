#pragma once
#include "DVR/DVR.h"
#include <vector>
#include <map>
#include <memory>
#include <queue>
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
	
		void Add(const std::vector<RecordFile> rf);		
		void Clear();
		void GetSearchFiles(std::vector<RecordFile>& rf);
	//	void GetSearchFiles(std::vector<DVRSearchFiles*>& files);
	//	void GetDownloadFilesByID(std::vector<size_t>& fileIDs, std::vector<DVRSearchFiles*>& files);
	//	DVRSearchFiles* GetPlayFileById(const size_t id);
		RecordFile& GetFileById(const size_t id);
		void GetDownloadfiles(const std::vector<size_t>& IDs, std::vector<RecordFile>& files);

	private:
		void GetDownloadRow();
		void findDownloadMap(std::string s);

	private:
		std::vector<RecordFile> _recordfiles;		

		DVRSearchFilesContainer(const DVRSearchFilesContainer&);
		DVRSearchFilesContainer operator =(const DVRSearchFilesContainer&);
	};
}


