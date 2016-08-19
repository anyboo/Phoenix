#include "stdafx.h"
#include "NICStatus.h"
#include <Poco/NotificationCenter.h>
#include <Poco/Observer.h>

using Poco::Observer;
using Poco::NotificationCenter;

NICStatusChanged::NICStatusChanged()
:_nc(NotificationCenter::defaultCenter()), _st(OFF_LINE)
{
	Observer<NICStatusChanged, NICStatusNotification> obs(*this, &NICStatusChanged::OnNotify);
	_nc.addObserver(obs);
}

NICStatusChanged::~NICStatusChanged()
{
	Observer<NICStatusChanged, NICStatusNotification> obs(*this, &NICStatusChanged::OnNotify);
	_nc.removeObserver(obs);
}

void NICStatusChanged::OnNotify(NICStatusNotification* pNf)
{
	poco_check_ptr(pNf);
	if (pNf)
	{
		_st = pNf->GetStatus();
		this->OnStatusChanged(_st);
		pNf->release();
	}	
}
