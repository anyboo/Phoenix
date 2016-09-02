#pragma once
#include <DuiLib/UIlib.h>


class CNotificationNetworkStatus;

class COVPlayerUI :
	public WindowImplBase
{
public:
	COVPlayerUI();
	~COVPlayerUI();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();


	void HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf);

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};