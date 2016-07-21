#pragma once
#include <Poco/Activity.h>

#include <Poco/NotificationQueue.h>

using Poco::NotificationQueue;

class MessagePump
{
public:
	MessagePump();
	~MessagePump();

	void start();
	void stop();
protected:
	void runActivity();

private:
	Poco::Activity<MessagePump> _pump;

public:
	static NotificationQueue queuePortScan;
	static NotificationQueue queueSearchDevice;
	static NotificationQueue queueDeviceManager;
}; 

