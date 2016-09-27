#include "DVR/DVRDownloadTask.h"


namespace DVR{
	DVRDownloadTask::DVRDownloadTask()
	{
	}

	DVRDownloadTask::~DVRDownloadTask()
	{
	}

	std::string DVRDownloadTask::fname()
	{
		return std::string("name");
	}

	std::size_t DVRDownloadTask::fsize()
	{
		return 3432141;
	}

	std::size_t DVRDownloadTask::proValue()
	{
		return 33;
	}

	std::size_t DVRDownloadTask::speed()
	{
		return 12;
	}

	std::size_t DVRDownloadTask::elapsedTime()
	{
		return 110;
	}

	void DVRDownloadTask::DeleteTaskByName(const std::string name)
	{

	}

}




