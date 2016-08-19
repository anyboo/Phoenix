#pragma once
#include <Poco/NotificationCenter.h>
#include "NICStatusNotification.h"

class NICStatusChanged
{
public:

	NICStatusChanged();
	~NICStatusChanged();
protected:
	virtual void OnStatusChanged(NETWORK_STATUS st) = 0;
	void OnNotify(NICStatusNotification* pNf);

private:
	Poco::NotificationCenter& _nc;
	NETWORK_STATUS  _st;
};


