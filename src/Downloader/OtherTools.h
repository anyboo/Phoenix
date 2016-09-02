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

	void OnOpenExeFile(std::string& filePath);

	void HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf);

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};


