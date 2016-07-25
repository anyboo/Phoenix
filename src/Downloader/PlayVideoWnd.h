#pragma once
#include <DuiLib/UIlib.h>

#include "Device.h"
#include "AbstractVendor.h"

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

	HWND GetPlayHwnd();
private:
	Device*		m_Device;
	RecordFile	m_rf;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};