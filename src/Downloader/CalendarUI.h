#pragma once
#include <DuiLib/UIlib.h>
#include "DownLoadWnd.h"

#include <ATLComTime.h>

#define BT_CANCEL			(_T("closebtn1"))
#define BT_BKCOLOR1		0x64263231
#define BT_BKCOLOR2		0xc3324534
#define BT_BKCOLOR3		0x64263232

class CalendarUI :
	public WindowImplBase
{
public:
	CalendarUI();
	~CalendarUI();

	STDSTRING GetData();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
	void OnClose(TNotifyUI& msg);

	void SaveData(STDSTRING& btnName);
	void OnPrepare();
	void DrawCalendar(SYSTEMTIME m_sysTime);
	int GetDayOfWeek(SYSTEMTIME m_sysTime);
	int GetMonthDays(int iY, int iM);
	
	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
private:
	BOOL			m_bTag;
	SYSTEMTIME		 m_sysTime;
	COleDateTime	m_ctime;
	int				 m_PrevMonth;
	STDSTRING		m_strData;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};
