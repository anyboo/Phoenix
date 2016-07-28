#include "stdafx.h"
#include "OVPlayerUI.h"

#include "Poco/Observer.h"
#include <Poco/NotificationCenter.h>

#include "NotificationNetworkStatus.h"
using Poco::NotificationCenter;
using Poco::Observer;


COVPlayerUI::COVPlayerUI()
{
}


COVPlayerUI::~COVPlayerUI()
{
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.removeObserver(Observer<COVPlayerUI, CNotificationNetworkStatus>(*this, &COVPlayerUI::HandleNotificationNetworkStatus));
}

DUI_BEGIN_MESSAGE_MAP(COVPlayerUI, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR COVPlayerUI::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString COVPlayerUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString COVPlayerUI::GetSkinFile()
{
	return _T("xml//OVPlayerUI.xml");
}

void COVPlayerUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void COVPlayerUI::Notify(TNotifyUI& msg)
{

	WindowImplBase::Notify(msg);
}


void COVPlayerUI::InitWindow()
{
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.addObserver(Observer<COVPlayerUI, CNotificationNetworkStatus>(*this, &COVPlayerUI::HandleNotificationNetworkStatus));
}

void COVPlayerUI::HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf)
{
	if (pNf == nullptr)
		return;
	if (pNf->name().compare("class CNotificationNetworkStatus"))
		return;

	NOTIFICATION_TYPE eNotify;
	eNotify = pNf->GetNotificationType();
	SetNetWorkState(eNotify);
}

void COVPlayerUI::SetNetWorkState(NOTIFICATION_TYPE& eNotify)
{
	CControlUI* NetWorkUI = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("Network")));
	if (eNotify == Notification_Type_Network_status_Connect)
		NetWorkUI->SetBkImage(_T("skin/network_online.png"));
	else if (eNotify == Notification_Type_Network_status_Disconnect)
		NetWorkUI->SetBkImage(_T("skin/network_offline.png"));
}
