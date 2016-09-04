#pragma once
#include <DuiLib/UIlib.h>

#define BT_SEARCH_CANCEL		(_T("Search_cel"))

class CProgtessUI :
	public WindowImplBase
{
public:
	CProgtessUI();
	~CProgtessUI();

	bool IsCancelSearch();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnCancelSearch(TNotifyUI& msg);

	void ShowProgress();

	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

private:
	int			_files_count;
	int			_search_file_count;
	bool		_bCancel;
private:
	CLabelUI*			_lab_progress;
	CProgressUI*		_pro_search;
};

