#ifndef __RECIVEUIQUNUE_H__
#define __RECIVEUIQUNUE_H__

#include "Poco/NotificationQueue.h"

using Poco::NotificationQueue;

#include <iostream>
#include <ctime>

class ReciveUIQunue:public NotificationQueue
{
public:
	ReciveUIQunue();
	~ReciveUIQunue();

	static ReciveUIQunue* GetInstance();

	static void DestroyInstance();

protected:
	static ReciveUIQunue *m_pReceiveUIQueue;
};

#endif 

