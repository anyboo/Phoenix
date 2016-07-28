#include "stdafx.h"
#include "PlayVideoWnd.h"

#include "PlayVideoWorker.h"

#include "TestWindows.h"
#include <Poco/NotificationQueue.h>
#include <Poco/ThreadPool.h>

#include "PlayWndUI.h"

using Poco::NotificationQueue;
using Poco::ThreadPool;

#include <Poco/NotificationCenter.h>
#include "Poco/Observer.h"

#include "MessagePump.h"

using Poco::NotificationCenter;
using Poco::Observer;



CPlayVideoWnd::CPlayVideoWnd(Device* device, RecordFile& rf)
:m_IsPlay(true), m_stopPos(0)
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

	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.removeObserver(Observer<CPlayVideoWnd, CNotificationPlayVideo>(*this, &CPlayVideoWnd::HandleNotificationPlayPos));
}

DUI_BEGIN_MESSAGE_MAP(CPlayVideoWnd, WindowImplBase)
DUI_ON_CLICK_CTRNAME(BT_CLOSE_PLWND, OnCloseWnd)
DUI_ON_CLICK_CTRNAME(BT_PLAY_STOP, OnStartStop)
DUI_ON_MSGTYPE_CTRNAME(DUI_MSGTYPE_VALUECHANGED, SLIDER_PLAYPOS, OnAdjustPlayPos)
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

	NotificationCenter& nc = NotificationCenter::defaultCenter();
	nc.addObserver(Observer<CPlayVideoWnd, CNotificationPlayVideo>(*this, &CPlayVideoWnd::HandleNotificationPlayPos));
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

void CPlayVideoWnd::OnStartStop(TNotifyUI& msg)
{
	if (m_IsPlay)
	{
		queuePlayVideo->enqueueNotification(new CNotificationPlayVideo(Notification_Type_Play_Video_Stop));
		Sleep(1000);
		CButtonUI* btn_play = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Start_stop")));
		btn_play->SetText(_T("²¥·Å"));
		CSliderUI* slider = dynamic_cast<CSliderUI*>(m_PaintManager.FindControl(_T("play_progress")));
		int m_stopPos = slider->GetValue();
		m_IsPlay = false;
	}
	else if (!m_IsPlay)
	{
		ThreadPool::defaultPool().start(*pv);
		queuePlayVideo->enqueueNotification(new CNotificationPlayVideo(Notification_Type_Play_Video_Pos, m_stopPos));
		Sleep(1000);
		CButtonUI* btn_stop = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Start_stop")));
		btn_stop->SetText(_T("ÔÝÍ£"));
		m_IsPlay = true;
	}
}

void CPlayVideoWnd::OnAdjustPlayPos(TNotifyUI& msg)
{
	CSliderUI* slider = dynamic_cast<CSliderUI*>(m_PaintManager.FindControl(_T("play_progress")));
	m_stopPos = slider->GetValue();
	queuePlayVideo->enqueueNotification(new CNotificationPlayVideo(Notification_Type_Play_Video_Pos, m_stopPos));
}

void CPlayVideoWnd::HandleNotificationPlayPos(CNotificationPlayVideo* pNf)
{
	CSliderUI* slider = dynamic_cast<CSliderUI*>(m_PaintManager.FindControl(_T("play_progress")));
	if (!pNf || pNf->name().compare("class CNotificationPlayVideo"))
		return;
	if (!pNf->name().compare("class CNotificationPlayVideo"))
		return;
	m_stopPos = pNf->GetPos();
	slider->SetValue(m_stopPos);
}

HWND CPlayVideoWnd::GetPlayHwnd()
{	 
	std::auto_ptr<CPlayWndUI> pDlg(new CPlayWndUI);
	assert(pDlg.get());
	HWND pHwnd = pDlg->Create(GetHWND(), NULL, UI_WNDSTYLE_CHILD, NULL, 0, 0, 0, 0, 0);

	CDuiRect rcWnd;
	GetWindowRect(pHwnd, &rcWnd);
	::SetWindowPos(pHwnd, NULL, rcWnd.left, rcWnd.top + 40, rcWnd.GetWidth(), rcWnd.GetHeight(), SWP_NOZORDER | SWP_NOSIZE | SWP_DRAWFRAME);


	return pHwnd;
}
