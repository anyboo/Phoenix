#pragma once
#include <Poco/NotificationCenter.h>

class NICStatusNotification
	: public Poco::Notification
{
public:
	NICStatusNotification(const std::string& data)
		:_data(data)
	{

	}
	std::string GetStatus()const
	{
		return _data;
	}
private:
	std::string _data;
};

class StatusNotification
	: public Poco::Notification
{
public:
	StatusNotification(const int data)
		:_data(data)
	{

	}
	int GetStatus()const
	{
		return _data;
	}
private:
	int _data;
};

class NICStatusChanged
{
public:
	enum STATUS
	{
		ONLINE,
		OFFLINE,
	};

	NICStatusChanged();
	~NICStatusChanged();
protected:
	virtual void OnStatusChanged(STATUS st) = 0;
	void OnNotify(NICStatusNotification* pNf);

private:
	Poco::NotificationCenter& _nc;
};


