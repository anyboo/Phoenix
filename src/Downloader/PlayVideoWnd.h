#pragma once
#include <DuiLib/UIlib.h>
#include "Device.h"
#include "AbstractVendor.h"

#include "NotificationQueue.h"
#include "PlayVideoWorker.h"

#define BT_CLOSE_PLWND			(_T("close"))

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

	HWND GetPlayHwnd();
private:
	Device*		m_Device;
	RecordFile	m_rf;
	NotificationQueue* queuePlayVideo; 
	CPlayVideoWorker* pv;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};