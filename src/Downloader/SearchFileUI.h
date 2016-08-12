#pragma once
#include <DuiLib/UIlib.h>

#include "QMSqlite.h"
#include "SearchFileNotification.h"

#include "DownloadPackage.h"
#include "Device.h"

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
	SearchFileUI(Device* device);
	~SearchFileUI();


	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify(TNotifyUI& msg);

	void OnCloseWnd(TNotifyUI& msg);
	void OnDownLoadFile(TNotifyUI& msg);

	DUI_DECLARE_MESSAGE_MAP();
	void OnShowFileList();

	STDSTRING TimeChange(__time64_t inputTime);

	void GetSelectOption(STDSTRING& optionName);

	void GetFileSizeAndCount();

	void GetFileInfo(STDSTRING& SendName);
	void OnPlayVideo(int CurSel);

	void ReceiveSearchFile(SearchFileNotification* pNf);

	bool ReadDataFromTable();
	
private:
	std::vector<size_t>		m_Select_file;
	bool		m_InitShowFileList;
	std::vector<readSearchVideo>  m_FileList;
	IsDownLoadFile		m_IsDownLoad;
	Device*				m_device;
//	DownloadItem		m_DownLoaditem;
	size_t					m_DownloadID;
	DownloadPackage		m_DownLoadList;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};