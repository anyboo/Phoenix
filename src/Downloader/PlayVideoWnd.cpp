#include "stdafx.h"
#include "PlayVideoWnd.h"

#include "PlayVideoWorker.h"

#include "TestWindows.h"
#include <Poco/NotificationQueue.h>
#include <Poco/ThreadPool.h>

#include "PlayWndUI.h"

using Poco::NotificationQueue;
using Poco::ThreadPool;


CPlayVideoWnd::CPlayVideoWnd(Device* device, RecordFile& rf)
{
	m_Device = device;
	m_rf = rf;
	queuePlayVideo = new NotificationQueue();
}


CPlayVideoWnd::~CPlayVideoWnd()
{
	//delete queuePlayVideo;
	//queuePlayVideo = nullptr;

	//delete pv;
	//pv = nullptr;
}

DUI_BEGIN_MESSAGE_MAP(CPlayVideoWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_PLWND, OnCloseWnd)
DUI_END_MESSAGE_MAP()

LPCTSTR CPlayVideoWnd::GetWindowClassName() const
{
	return _T("PlayVideoWnd");
}

CDuiString CPlayVideoWnd::GetSkinFolder()
{
	return _T("skin");
}


void CPlayVideoWnd::InitWindow()
{
	pv = new CPlayVideoWorker(m_Device, m_rf, GetPlayHwnd(), *queuePlayVideo);
	ThreadPool::defaultPool().start(*pv);
}

CDuiString CPlayVideoWnd::GetSkinFile()
{
	return _T("xml\\PlayVideoWnd.xml");
}

void CPlayVideoWnd::OnFinalMessage(HWND hWnd)
{	
	WindowImplBase::OnFinalMessage(hWnd);
}

void CPlayVideoWnd::Notify(TNotifyUI& msg)
{
	WindowImplBase::Notify(msg);
}

void CPlayVideoWnd::OnCloseWnd(TNotifyUI& msg)
{
	queuePlayVideo->enqueueNotification(new CNotificationPlayVideo(Notification_Type_Play_Video_Stop));
	Sleep(1000);
	Close();
}

HWND CPlayVideoWnd::GetPlayHwnd()
{	 
	std::auto_ptr<CPlayWndUI> pDlg(new CPlayWndUI);
	assert(pDlg.get());
	HWND pHwnd = pDlg->Create(GetHWND(), NULL, UI_WNDSTYLE_CHILD, NULL, 0, 0, 0, 0, 0);

	CDuiRect rcWnd;
	GetWindowRect(pHwnd, &rcWnd);
	::SetWindowPos(pHwnd, NULL, rcWnd.left, rcWnd.top + 40, rcWnd.GetWidth(), rcWnd.GetHeight(), SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);

	return pHwnd;
}
