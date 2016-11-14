#pragma once
#include "DVR/DVR.h"
#include "DVR/DVRDownloadPakcetContainer.h"
#include "DVR/DVRDownloadPacket.h"


namespace DVR{

	class DVR_API DVRDownloadPakcetContainer
	{
	public:
		DVRDownloadPakcetContainer();
		~DVRDownloadPakcetContainer();

		static DVRDownloadPakcetContainer& getInstance()
		{
			static Poco::SingletonHolder<DVRDownloadPakcetContainer>	sing;
			return *sing.get();
		}

		void AddDownloadItem(const std::string devicename, std::vector<size_t>& IDs, long current_time, const std::string  searchtime, const std::string downlaodpath);
		DVRDownloadPacket* GetDownloadItem(const long  current_time);
		void DeleteDownloadItem(const long  current_time);
		void Clear();

		int GetSize();

	private:
		std::map<long, std::shared_ptr<DVRDownloadPacket>>		_DownloadItems;
		Mutex                              _mutex;
	};
}


