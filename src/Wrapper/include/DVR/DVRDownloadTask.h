#pragma once
#include "DVR/DVR.h"
#include <vector>


namespace DVR{
	class DVR_API DVRDownloadTask
	{
	public:
		DVRDownloadTask();
		~DVRDownloadTask();

		std::string fname();
		std::size_t fsize();
		std::size_t proValue();
		std::size_t speed();
		std::size_t elapsedTime();

	};
}


