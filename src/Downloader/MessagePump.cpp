#include "stdafx.h"
#include "MessagePump.h"
#include <Poco/Thread.h>
#include <Poco/Notification.h>
#include <Poco/NotificationQueue.h>
#include <Poco/NotificationCenter.h>

using Poco::Thread;
using Poco::Notification;
using Poco::NotificationQueue;
using Poco::NotificationCenter;

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

/*
runActivity can't dispatch download thread's notification,
because download notification will be freq.
*/

void MessagePump::runActivity()
{
	NotificationQueue& queue = NotificationQueue::defaultQueue();
	NotificationCenter& nc = NotificationCenter::defaultCenter();

	while (!_pump.isStopped())
	{
		Notification::Ptr pNf = queue.waitDequeueNotification();
		
		if (pNf && nc.hasObservers())
		{
			nc.postNotification(pNf);
		}
		else Thread::sleep(200);
	}
}
