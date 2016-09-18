#pragma once
#include "DVR/DVR.h"
#include <vector>
#include <Poco/DateTime.h>


namespace DVR{
	class DVR_API DVRSearchFiles
	{
	public:
		DVRSearchFiles();
		~DVRSearchFiles();

		std::string fname();
		std::size_t channel();
		Poco::DateTime startTime();
		Poco::DateTime stopTime();
		std::size_t fsize();
	};
}

