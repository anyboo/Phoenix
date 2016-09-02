#pragma once
#include <DuiLib/UIlib.h>

#define BT_SEARCH_CANCEL		(_T("Search_cel"))

class CProgtessUI :
	public WindowImplBase
{
public:
	CProgtessUI();
	~CProgtessUI();

	virtual void InitWindow();
	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnCancelSearch(TNotifyUI& msg);

	void ShowProgress();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

private:
	int			_files_count;
	int			_search_file_count;

private:
	CLabelUI*			_lab_progress;
	CProgressUI*		_pro_search;
};

