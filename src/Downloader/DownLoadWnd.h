#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "Vendor.h"
#include "TimeUI.h"
		
#define	BT_Calendar1			(_T("DataTime1"))
#define	BT_Calendar2			(_T("DataTime2"))
#define BT_OnVideoLoginUI		(_T("Add_device"))
#define BTNAMELONG				9
#define SUBLISTNAMELONG				8
#define BTNAMETAG				STDSTRING(_T("BT_Cancel"))
#define SUBLISTNAMETAG			STDSTRING(_T("ContList"))
#define BT_TIMEWND1				(_T("daytime1"))
#define BT_TIMEWND2				(_T("daytime2"))


typedef struct 
{
	STDSTRING	filename;
	int			filesize;
	STDSTRING	process;
	STDSTRING	speed;
	STDSTRING	remain_time;
	STDSTRING	state;
	STDSTRING	handle;
}FILE_INFO;

class DownLoadWnd :
	public WindowImplBase
{
public:
	DownLoadWnd();
	~DownLoadWnd();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
	void OnSelectTimeType();
	void OnSelectCalendar();
	void OnSearchFileWnd();
	void OnSelectDayTime();

	void OnVideoLoginWnd(TNotifyUI& msg);

	BOOL SearchFiles();
	void ShowFileList();

	void Show_Off_SubList(STDSTRING& strSendName);
	void RemoveSubList(STDSTRING& strSendName);

	void Show_Off_VendorList(STDSTRING& strSendName);
	void All_SelectChannels();
	void RemoveVendor(STDSTRING& strSendName);

	void ShowTime(STDSTRING& InputName);
	void ShowData(STDSTRING& InputName);

	int GetSubListCurSel(CListContainerElementUI* SubList, CListUI* pList);

	CListContainerElementUI* Add_FileInfoList(int n, bool IsShowCloseBT);

protected:
	vector<FILE_INFO>	m_fileInfo;
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

private:
	CVendor		m_Vendor;
	CTimeUI		m_TimeUI;
	int			m_FileCount;
};

