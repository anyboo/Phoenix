#pragma once
#include <DuiLib/UIlib.h>

#define BT_CLOSE_SEARCHWND		(_T("close_bt"))
#define BT_BEGINDOWNLOAD		(_T("BT_Download"))

enum IsDownLoadFile
{
	beginDownload,
	closeWnd
};

class SearchFileUI :
	public WindowImplBase
{
public:
	SearchFileUI();
	~SearchFileUI();


	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify(TNotifyUI& msg);

	void OnCloseWnd(TNotifyUI& msg);
	void OnDownLoadFile(TNotifyUI& msg);

	DUI_DECLARE_MESSAGE_MAP();
	void OnShowFileList();

	std::string TimeChange(__time64_t inputTime);

	void GetSelectOption(std::string& optionName);

	void GetFileInfo(std::string& SendName);
	void OnPlayVideo(int CurSel);
	
private:
	std::vector<size_t>		m_Select_file;
	bool		m_InitShowFileList;
	IsDownLoadFile		m_IsDownLoad;
	size_t					m_DownloadID;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};