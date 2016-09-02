#include "stdafx.h"
#include "OVPlayerUI.h"

#include "Poco/Observer.h"
#include <Poco/NotificationCenter.h>

using Poco::NotificationCenter;
using Poco::Observer;


COVPlayerUI::COVPlayerUI()
{
}


COVPlayerUI::~COVPlayerUI()
{
	//NotificationCenter& nc = NotificationCenter::defaultCenter();
	//nc.removeObserver(Observer<COVPlayerUI, CNotificationNetworkStatus>(*this, &COVPlayerUI::HandleNotificationNetworkStatus));
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
	//NotificationCenter& nc = NotificationCenter::defaultCenter();
	//nc.addObserver(Observer<COVPlayerUI, CNotificationNetworkStatus>(*this, &COVPlayerUI::HandleNotificationNetworkStatus));
}