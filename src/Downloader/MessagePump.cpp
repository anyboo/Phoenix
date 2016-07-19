#include "stdafx.h"
#include "MessagePump.h"
#include <Poco/Thread.h>
#include <Poco/Notification.h>
#include <Poco/NotificationQueue.h>

using Poco::Thread;
using Poco::Notification;
using Poco::NotificationQueue;

MessagePump::MessagePump()
:_pump(this, &MessagePump::runActivity)
{
}


MessagePump::~MessagePump()
{
}

void MessagePump::start()
{
	_pump.start();
}

void MessagePump::stop()
{
	_pump.stop();
	_pump.wait();
}

void MessagePump::runActivity()
{
	while (!_pump.isStopped())
	{
		NotificationQueue& queue = NotificationQueue::defaultQueue();
		Notification::Ptr pNf = queue.waitDequeueNotification();
		if (pNf)
		{
			/*WorkNotification::Ptr pWorkNf = pNf.cast<WorkNotification>();
			if (pWorkNf)
			{
				nc.notify();
			}*/
		}
		else Thread::sleep(200);
	}
}
