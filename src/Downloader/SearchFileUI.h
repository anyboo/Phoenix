#pragma once
#include <DuiLib/UIlib.h>
#include <Poco/datetime.h>
#include <vector>

#define BT_CLOSE_SEARCHWND		(_T("close_bt"))
#define BT_BEGINDOWNLOAD		(_T("BT_Download"))
#define BT_SELECT_ALL			(_T("All"))

enum IsDownLoadFile
{
	beginDownload,
	closeWnd
};

class SearchFileUI :
	public WindowImplBase
{
public:
	SearchFileUI(const std::string name);
	~SearchFileUI();

	void GetDownloadHandles(std::vector<long>& handles);
	void GetDownloadfileIDs(std::vector<size_t>& IDs);
	bool IsBeginDownload();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnCloseWnd(TNotifyUI& msg);
	void OnDownLoadFile(TNotifyUI& msg);

	void BuildControlDDX();


	void OnCheckAll(TNotifyUI& msg);

	void OnShowFileList();

	void GetFileCountAndSize();

	CDuiString TimeChange(Poco::DateTime inputTime);

	void GetSelectOption(CDuiString& optionName);

	void GetFileInfo(std::string& SendName);
	void OnPlayVideo(int CurSel);
			
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

private:
	std::vector<size_t>		_checked_files;
	std::vector<long>		_Download_handles;
	IsDownLoadFile		m_IsDownLoad;
	std::string		_CurrentDname;
	//std::vector<SearchFileInfo> _file_info;
private:
	CListUI*			_pList;
	COptionUI*			_oCheckAll;
	CLabelUI*			_lab_CountText;
};