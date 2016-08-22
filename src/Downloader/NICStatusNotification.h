#pragma once
#include <Poco/Notification.h>

enum NETWORK_STATUS
{
	OFF_LINE = 0,
	ON_LINE,
	DISABLE,
};

class NICStatusNotification
	: public Poco::Notification
{
public:

	NICStatusNotification(NETWORK_STATUS data)
		:_data(data)
	{

	}
	NETWORK_STATUS GetStatus() const
	{
		return _data;
	}
private:
	NETWORK_STATUS _data;
};