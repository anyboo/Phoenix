#pragma once
#include <Poco/Activity.h>

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
};

