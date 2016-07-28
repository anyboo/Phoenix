#pragma once
#include <DuiLib/UIlib.h>
#include <vector>

class CNotificationNetworkStatus;
class COtherTools :
	public WindowImplBase
{
public:
	COtherTools();
	~COtherTools();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnOpenExeFile(STDSTRING& filePath);

	void HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf);
	void SetNetWorkState(NOTIFICATION_TYPE& eNotify);


protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};


