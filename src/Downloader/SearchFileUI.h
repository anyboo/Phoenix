#pragma once
#include <DuiLib/UIlib.h>


class SearchFileUI :
	public WindowImplBase
{
public:
	SearchFileUI();
	~SearchFileUI();
	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify(TNotifyUI& msg);

	DUI_DECLARE_MESSAGE_MAP();
	void SearchTest();

	void GetFileInfo(STDSTRING& SendName);
	void OnPlayVideo(STDSTRING& filename, STDSTRING& channel, STDSTRING& stime, STDSTRING& etime);

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};