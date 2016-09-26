#pragma once
#include <DuiLib/UIlib.h>

#define BT_SAVE_PATH		(_T("ok_btn"))
#define BT_SELECT_PATH		(_T("select_path"))
#define CMB_SELECT_CASE		(_T("Case_Numb"))

class CFileLogInfoUI :
	public WindowImplBase
{
public:
	CFileLogInfoUI();
	~CFileLogInfoUI();

	std::string GetTime();
	std::string GetPath();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void InitDownloadConfig();
	void OnSaveDownloadPath(TNotifyUI& msg);
	void OnSelectCaseToSave(TNotifyUI& msg);
	void OnSelectPath(TNotifyUI& msg);

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

private:
	CEditUI*		_edit_path;
	CComboUI*		_comb_case;
	CEditUI*		_edit_time;
};