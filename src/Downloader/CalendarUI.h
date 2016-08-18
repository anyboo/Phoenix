#pragma once
#include <DuiLib/UIlib.h>
#include "DownLoadWnd.h"

#include <ATLComTime.h>

class CalendarUI :
	public WindowImplBase
{
public:
	CalendarUI();
	~CalendarUI();

	CDuiString GetData();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
	
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

	void OnNextYear(TNotifyUI& msg);
	void OnPreYear(TNotifyUI& msg);
	void OnInputDay(TNotifyUI& msg);

	void OnSelectedMonth(TNotifyUI& msg);
	void OnClose(TNotifyUI& msg);

	void SaveData();
	void OnPrepare();
	void DrawCalendar(SYSTEMTIME m_sysTime);
	size_t GetDayOfWeek(SYSTEMTIME m_sysTime);
	size_t GetMonthDays(size_t year, size_t month);
	CDuiString GetMonth();
	CDuiString GetDay();
	void BuildControlDDX();
	void InitDays();
	void SelectMonth(size_t month);
private:
	BOOL			m_bTag;
	SYSTEMTIME		 m_sysTime;
	COleDateTime	m_ctime;

	unsigned short	_PrevMonth;
	CDuiString	_data;

	CComboUI*	_month;
	CLabelUI*	_year;
	std::vector<CButtonUI*>	_days;

	CButtonUI* _user_selected_day;
};
