#pragma once
#include <DuiLib/UIlib.h>

#define BT_SAVE_PATH		(_T("ok_btn"))
#define BT_SELECT_PATH		(_T("select_path"))

class CFileLogInfoUI :
	public WindowImplBase
{
public:
	CFileLogInfoUI();
	~CFileLogInfoUI();

	std::string GetTime();

	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnSaveDownloadPath(TNotifyUI& msg);

	void OnSelectPath(TNotifyUI& msg);

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

private:
	CEditUI*		_edit_path;
};