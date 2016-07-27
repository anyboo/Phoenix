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
	///     Query video file
	///     @param		Device* pDevice -- A pointer to the object of device class
	///		@param		const time_range& range -- The time range query video files     
	///		@param		const std::vector<size_t> channelList -- The channel number
	///		@param		ReciveUIQunue& queue -- Receive a message queue
	///     @return 	None
	///     @see 		
	///     @note      When creating a class object, needs to be the object into the thread pool
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