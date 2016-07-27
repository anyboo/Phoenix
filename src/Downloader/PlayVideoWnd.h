#pragma once
#include <DuiLib/UIlib.h>
#include "Device.h"
#include "AbstractVendor.h"

#include "NotificationQueue.h"
#include "PlayVideoWorker.h"



#define BT_CLOSE_PLWND			(_T("close"))
#define BT_PLAY_STOP			(_T("Start_stop"))
#define SLIDER_PLAYPOS			(_T("play_progress"))

class CPlayVideoWnd :
	public WindowImplBase
{
public:
	CPlayVideoWnd(Device* device, RecordFile& rf);
	~CPlayVideoWnd();

	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnCloseWnd(TNotifyUI& msg);

	void OnStartStop(TNotifyUI& msg);

	void OnAdjustPlayPos(TNotifyUI& msg);

	int GetCountTime();

	void HandleNotificationPlayPos(CNotificationPlayVideo* pNf);


	HWND GetPlayHwnd();
private:
	Device*		m_Device;
	RecordFile	m_rf;
	NotificationQueue* queuePlayVideo; 
	CPlayVideoWorker* pv;
	bool		m_IsPlay;
	time_t			m_TimeCount;
	int			m_stopPos;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};