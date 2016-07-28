#include "stdafx.h"
#include "OtherTools.h"


#include "Poco/Observer.h"
#include <Poco/NotificationCenter.h>

#include "NotificationNetworkStatus.h"
using Poco::NotificationCenter;
using Poco::Observer;

COtherTools::COtherTools()
{
}


COtherTools::~COtherTools()
{
}

DUI_BEGIN_MESSAGE_MAP(COtherTools, WindowImplBase)

DUI_END_MESSAGE_MAP()

LPCTSTR COtherTools::GetWindowClassName() const
{
	return _T("CLogUI");
}

CDuiString COtherTools::GetSkinFolder()
{
	return _T("skin");
}

CDuiString COtherTools::GetSkinFile()
{
	return _T("xml//OtherTools.xml");
}

void COtherTools::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}


void COtherTools::InitWindow()
{
	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.addObserver(Observer<COtherTools, CNotificationNetworkStatus>(*this, &COtherTools::HandleNotificationNetworkStatus));
}

void COtherTools::HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf)
{
	if (pNf == nullptr)
		return;
	if (pNf->name().compare("class CNotificationNetworkStatus"))
		return;

	NOTIFICATION_TYPE eNotify;
	eNotify = pNf->GetNotificationType();
	SetNetWorkState(eNotify);
}

void COtherTools::SetNetWorkState(NOTIFICATION_TYPE& eNotify)
{
	CControlUI* NetWorkUI = dynamic_cast<CControlUI*>(m_PaintManager.FindControl(_T("Network")));
	if (eNotify == Notification_Type_Network_status_Connect)
		NetWorkUI->SetBkImage(_T("skin/network_online.png"));
	else if (eNotify == Notification_Type_Network_status_Disconnect)
		NetWorkUI->SetBkImage(_T("skin/network_offline.png"));
}

void COtherTools::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (msg.pSender->GetName() == _T("DH_Tool"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\DaHuaTool\\DiskCopy.exe")));
		}
		if (msg.pSender->GetName() == _T("HK_Tool"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\hikPlay\\APT-LPB.exe")));
		}
		if (msg.pSender->GetName() == _T("Record_Tool"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\screenRecord\\ScreenCap.exe")));
		}
		if (msg.pSender->GetName() == _T("Video_Play"))
		{
			OnOpenExeFile(STDSTRING(_T("D:\\code\\Phoenix\\bin\\OVPlayer\\OVPlayer_V1.3.7(UK).exe")));
		}
	}
	WindowImplBase::Notify(msg);
}

void COtherTools::OnOpenExeFile(STDSTRING& filePath)
{
	HINSTANCE hIns = ShellExecute(NULL, _T("Open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
	int dret = (int)hIns;
	if (dret < 32)
		MessageBox(NULL, _T("无法打开"), _T("提示"), MB_OK);
}
