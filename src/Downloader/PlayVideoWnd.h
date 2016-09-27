#pragma once
#include <DuiLib/UIlib.h>
#include "DVR/DVRStatement.h"
#include "Poco/Timer.h"

#define BT_CLOSE_PLWND			(_T("close"))
#define BT_PLAY_STOP			(_T("Start_stop"))
#define SLIDER_PLAYPOS			(_T("play_progress"))


class CPlayVideoWnd :
	public WindowImplBase
{
public:
	CPlayVideoWnd(const std::string name, const int Cursel);
	~CPlayVideoWnd();

	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void BuildControlDDX();

	void BeginPlay();

	void OnCloseWnd(TNotifyUI& msg);

	void OnStartStop(TNotifyUI& msg);

	void OnAdjustPlayPos(TNotifyUI& msg);

	HWND GetPlayHwnd();
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

	void onTimer(Poco::Timer& timer);
private:
	Poco::Timer t;
	Poco::TimerCallback<CPlayVideoWnd> tc;

	bool		m_IsPlay;
	int			m_stopPos;
	int			_play_handle;
	int			_fileID;
	HWND			_play_hwnd;
	int			_playtimes;
	int  _totaltimes;
	DVR::DVRStatement*		_statement;
private:
	CButtonUI*				_btn_play;
	CSliderUI*				_slider;
};