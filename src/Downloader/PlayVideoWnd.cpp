#include "stdafx.h"
#include "PlayVideoWnd.h"

#include "PlayVideoWorker.h"

#include "TestWindows.h"
#include <Poco/NotificationQueue.h>
#include <Poco/ThreadPool.h>

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
	delete queuePlayVideo;
	queuePlayVideo = nullptr;

	delete pv;
	pv = nullptr;
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
	HWND play_Hwnd;
	play_Hwnd = GetPlayHwnd();
	if (!play_Hwnd)
	{
		return;
	}

	pv = new CPlayVideoWorker(m_Device, m_rf, play_Hwnd, *queuePlayVideo);
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
	if (msg.sType == DUI_MSGTYPE_CLICK && msg.pSender->GetName() == _T("close"))
	{
		
	}
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
	CVerticalLayoutUI* PlayLyt = static_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("wnd_lyt")));
	
	CDialogBuilder builder;
	CHorizontalLayoutUI* subLyt = (CHorizontalLayoutUI*)(builder.Create(_T("xml//playLyt.xml"), (UINT)0, NULL, &m_PaintManager));
	PlayLyt->Add(subLyt);
	CPaintManagerUI* vLytppm = subLyt->GetManager();
	
	HWND vHwnd = vLytppm->GetPaintWindow();
	HWND playHwnd = PlayLyt->GetNativeWindow();
	HWND hhhwnd = this->GetHWND();
	return vHwnd;
}
