
#include "DVR/DVRSearchFiles.h"
#include <time.h>

namespace DVR{
	DVRSearchFiles::DVRSearchFiles()
	{
	}


	DVRSearchFiles::~DVRSearchFiles()
	{
	}

	std::string DVRSearchFiles::fname()
	{
		return std::string("filename");
	}

	std::size_t DVRSearchFiles::channel()
	{
		return 4;
	}

	Poco::DateTime DVRSearchFiles::startTime()
	{
		return Poco::DateTime(2016, 9, 10);
	}

	Poco::DateTime DVRSearchFiles::stopTime()
	{
		return Poco::DateTime(2016, 9, 10, 23, 59, 59);
	}

	std::size_t DVRSearchFiles::fsize()
	{
		return 2412321;
	}

}

