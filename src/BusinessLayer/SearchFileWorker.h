#pragma once

#include "Poco/NotificationQueue.h"
#include "Poco/Runnable.h"
#include "Poco/Mutex.h"
#include "Poco/Random.h"
#include "Poco/Thread.h"

#include "CommonUtrl.h"
#include "SearchFileException.h"

#include <vector>
#include <ctime>
#include <stdint.h>

#include "Device.h"
#include "SearchFileNotification.h"
#include "ReciveUINotification.h"
#include "ReciveUIQunue.h"

using Poco::NotificationQueue;
using Poco::Runnable;
using Poco::FastMutex;
using Poco::Thread;


class SearchFileWorker :public Runnable
{
public:   
	///     Function:  Query video file
	///     Parameter: Device* pDevice -- A pointer to the object of device class
	///				   const time_range& range -- The time range query video files     
	///				   const std::vector<size_t> channelList -- The channel number
	///				   ReciveUIQunue& queue -- Receive a message queue
	///     Return:	   None
	///     Note:      When creating a class object, needs to be the object into the thread pool

	//查询视频文件
	//注：shou
	SearchFileWorker(Device* pDevice, const time_range& range, const std::vector<size_t> channelList, ReciveUIQunue& queue);

	~SearchFileWorker();

private:
	virtual void run();

private:
	ReciveUIQunue& m_queue;
	static FastMutex   m_mutex;

	time_range m_range;
	std::vector<size_t> m_channelList;
	Device* m_pDevice;

	bool m_bCancel;
};