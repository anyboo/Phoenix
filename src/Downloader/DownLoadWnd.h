#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "Vendor.h"
#include "TimeUI.h"
#include <map>

#include "DownloadPackage.h"
		
#define	BT_Calendar1			(_T("DataTime1"))
#define	BT_Calendar2			(_T("DataTime2"))
#define BT_OnVideoLoginUI		(_T("Add_device"))
#define BTNAMELONG				9
#define SUBLISTNAMELONG				8
#define BTNAMETAG				STDSTRING(_T("BT_Cancel"))
#define SUBLISTNAMETAG			STDSTRING(_T("ContList"))
#define BT_TIMEWND1				(_T("daytime1"))
#define BT_TIMEWND2				(_T("daytime2"))
#define BT_SEARCHFILE			(_T("Search"))
#define BT_CLOSE_D				(_T("CloseWnd"))

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

	void OnCloseWnd(TNotifyUI& msg);

	void OnSelectTimeType();
	void OnSelectCalendar(STDSTRING& SendName);
	void OnSearchFileWnd(TNotifyUI& msg);
	void OnSelectDayTime(STDSTRING& SendName);

	void OnVideoLoginWnd(TNotifyUI& msg);

	void SearchFile();
	void ShowTotalFileList();

	void Show_Off_SubList(STDSTRING& strSendName);
	void RemoveSubList(STDSTRING& strSendName);

	void Show_Off_VendorList(STDSTRING& strSendName);
	void All_SelectChannels();
	void RemoveVendor(STDSTRING& strSendName);

	void InitTime();
	void SetBtDataImage(STDSTRING& BT_Name, STDSTRING& day);

	int GetSubListCurSel(CListContainerElementUI* SubList, CListUI* pList);

	void AddSubFileList(size_t CurSel);

	void GetChannel();
	void GetDataTime();

	void ShowOnlineDevice();

	void ReadJsonFile();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	
	//std::vector<readSearchVideo>  m_FileInfo;
private:
	CVendor		m_Vendor;
	CTimeUI		m_TimeUI;
	int			m_FileCount;
	BOOL		m_beginTag;
	SYSTEMTIME		 m_sysTime;
	Device*		m_Device;
	size_t			m_ChannelCount;
	std::vector<size_t>	m_Channel;
	time_range		m_timeRangeSearch;
	std::vector<STDSTRING>		m_onlineIP;

private:
	std::string			m_DeviceID;
	std::map<int, string>		m_VnameAndType;
};

