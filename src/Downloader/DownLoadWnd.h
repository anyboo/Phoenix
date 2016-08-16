#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "Vendor.h"
#include "TimeUI.h"
#include <map>

class DownLoadWnd :
	public WindowImplBase
{
public:
	DownLoadWnd();
	~DownLoadWnd();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
	
	void SearchFile();
	
	void SetBtDataImage(std::string& BT_Name, std::string& day);
	int GetSubListCurSel(CListContainerElementUI* SubList, CListUI* pList);
	void AddSubFileList(size_t CurSel);
	void GetChannel();
	void GetDataTime();
	void ReadJsonFile();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

	void OnSearch(TNotifyUI& msg);
	void OnLogin(TNotifyUI& msg);
	void OnCloseWnd(TNotifyUI& msg);

	void OnUseSearchCtrl(TNotifyUI& msg);
	void OnSelectCalendar(TNotifyUI& msg);
	void OnSelectDayTime(TNotifyUI& msg);
	void OnSelectTimeType(TNotifyUI& msg);

	void InitTime();
	void BuildControlDDX();
	
private:
	CVendor		m_Vendor;
	int			m_FileCount;
	BOOL		m_beginTag;
	SYSTEMTIME		 m_sysTime;
	Device*		m_Device;
	size_t			m_ChannelCount;
	std::vector<size_t>	m_Channel;
	time_range		m_timeRangeSearch;
	std::vector<std::string>		m_onlineIP;
	std::string			m_DeviceID;
	std::map<int, string>		m_VnameAndType;

	CTimeUI*	_TimeControl;
	CButtonUI*  _SearchControl;
	CListUI*	_VendorList;
	CLabelUI*	_StartDate;
	CLabelUI*	_StopDate;
	CLabelUI*	_StartTime;
	CLabelUI*	_StopTime;
};

