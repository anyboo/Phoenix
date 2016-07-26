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


}


CPlayVideoWnd::~CPlayVideoWnd()
{
}

DUI_BEGIN_MESSAGE_MAP(CPlayVideoWnd, WindowImplBase)
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
	HWND m_hWnd;
	m_hWnd = GetPlayHwnd();

	NotificationQueue* queuePlayVideo = new NotificationQueue(); // 设备管理消息队列
	CPlayVideoWorker pv(m_Device, m_rf, m_hWnd, *queuePlayVideo);
	ThreadPool::defaultPool().start(pv);
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

HWND CPlayVideoWnd::GetPlayHwnd()
{
	 
	CVerticalLayoutUI* PlayLyt = static_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("wnd_lyt")));
	CPaintManagerUI* vLytppm = PlayLyt->GetManager();
	HWND m_hwnd = vLytppm->GetPaintWindow();

	return m_hwnd;
}