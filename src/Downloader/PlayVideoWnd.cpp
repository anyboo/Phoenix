#include "stdafx.h"
#include "PlayVideoWnd.h"
#include "PlayWndUI.h"
#include "DVR/DVRSession.h"
#include "TestData.h"

#include "DVR/DVRDevice.h"
#include "DVR/DVRDeviceContainer.h"
#include "DVR/DVRSearchFilesContainer.h"

CPlayVideoWnd::CPlayVideoWnd(const std::string name, const int Cursel)
:m_IsPlay(true), m_stopPos(0), _play_handle(0), _playtimes(0), _totaltimes(0),
t(100, 1000), tc(*this, &CPlayVideoWnd::onTimer)
{
	_fileID = Cursel;
	DVR::DVRDevice& Device = DVR::DVRDeviceContainer::getInstance().get(name);
	DVR::DVRStatement statement(Device.session());
	_statement = new DVR::DVRStatement(Device.session());
}

CPlayVideoWnd::~CPlayVideoWnd()
{
	delete _statement;
	t.stop();
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
	DVR::RecordFile rf = DVR::DVRSearchFilesContainer::getInstance().GetFileById(_fileID);
	Poco::DateTime start = rf.beginTime;
	Poco::DateTime stop = rf.endTime;
	struct tm sTM = { 0 };
	struct tm eTM = { 0 };
	sTM.tm_year = start.year() - 1900;
	sTM.tm_mon = start.month() - 1;
	sTM.tm_mday = start.day();
	sTM.tm_hour = start.hour();
	sTM.tm_min = start.minute();
	sTM.tm_sec = start.second();

	eTM.tm_year = stop.year() - 1900;
	eTM.tm_mon = stop.month() - 1;
	eTM.tm_mday = stop.day();
	eTM.tm_hour = stop.hour();
	eTM.tm_min = stop.minute();
	eTM.tm_sec = stop.second();

	__time64_t begin = mktime(&sTM);
	__time64_t end = mktime(&eTM);
	__time64_t times = end - begin;
	size_t tt = times;
	_totaltimes = tt;
	BuildControlDDX();
	t.start(tc);

	BeginPlay();
}

void CPlayVideoWnd::BeginPlay()
{
	_play_hwnd = GetPlayHwnd();
	_play_handle = _statement->playByName(_fileID, _play_hwnd);
}

void CPlayVideoWnd::BuildControlDDX()
{
	_btn_play = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("Start_stop")));
	_slider = dynamic_cast<CSliderUI*>(m_PaintManager.FindControl(_T("play_progress")));
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
	_statement->stopPlay(_play_handle);
	Close();
}

void CPlayVideoWnd::OnStartStop(TNotifyUI& msg)
{
	if (m_IsPlay)
	{
		_btn_play->SetText(_T("play"));
		int m_stopPos = _slider->GetValue();
		_statement->stopPlay(_play_handle);
		m_IsPlay = false;
	}
	else if (!m_IsPlay)
	{
		_btn_play->SetText(_T("stop"));
		_play_handle = _statement->playByName(_fileID, _play_hwnd);
		m_IsPlay = true;
	}
}

void CPlayVideoWnd::OnAdjustPlayPos(TNotifyUI& msg)
{
	m_stopPos = _slider->GetValue();
	_statement->setplayPos(_play_handle, m_stopPos);
	_playtimes = (_totaltimes * m_stopPos) / 100;
}


HWND CPlayVideoWnd::GetPlayHwnd()
{	 
	std::auto_ptr<CPlayWndUI> pDlg(new CPlayWndUI);
	assert(pDlg.get());
	HWND pHwnd = pDlg->Create(GetHWND(), NULL, UI_WNDSTYLE_CHILD, NULL, 0, 0, 0, 0, 0);

	CDuiRect rcWnd;
	GetWindowRect(pHwnd, &rcWnd);
	::SetWindowPos(pHwnd, NULL, rcWnd.left, rcWnd.top + 40, rcWnd.GetWidth(), rcWnd.GetHeight(), SWP_NOZORDER | SWP_NOSIZE | SWP_DRAWFRAME | SWP_SHOWWINDOW);

	return pHwnd;
}

void CPlayVideoWnd::onTimer(Poco::Timer& timer)
{
//	int pos = _statement->getplayPos(_play_handle);
	if (m_IsPlay)
	{
		_playtimes += 1;
		int proValue = (_playtimes * 100) / _totaltimes;
		_slider->SetValue(proValue);
	}	
}
