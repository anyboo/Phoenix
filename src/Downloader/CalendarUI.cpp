#include "stdafx.h"
#include "CalendarUI.h"

#define CTR_NEXTYEAR	_T("Add_Year")
#define CTR_PREYEAR		_T("Sub_Year")
#define CTR_INPUTYEAR	_T("InputYear")
#define CTR_MONTH		_T("CB_month")
#define CTR_INPUTDAY	_T("Button")

#define BT_BKCOLOR1		0x64263231
#define BT_BKCOLOR2		0xc3324534
#define BT_BKCOLOR3		0x64263232

CalendarUI::CalendarUI()
:m_bTag(true), _PrevMonth(0)
{	
}


CalendarUI::~CalendarUI()
{
}

DUI_BEGIN_MESSAGE_MAP(CalendarUI, WindowImplBase)
DUI_ON_CLICK_CTRNAME(CTR_NEXTYEAR, OnNextYear)
DUI_ON_CLICK_CTRNAME(CTR_PREYEAR, OnPreYear)
DUI_ON_MSGTYPE_CTRNAME(DUI_MSGTYPE_ITEMSELECT, CTR_MONTH, OnSelectedMonth)
DUI_END_MESSAGE_MAP()

LPCTSTR CalendarUI::GetWindowClassName() const
{
	return _T("CalendarUI");
}

CDuiString CalendarUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CalendarUI::GetSkinFile()
{
	return _T("xml\\CalendarUI.xml");
}

void CalendarUI::InitWindow()
{
	BuildControlDDX();
	OnPrepare();
}

void CalendarUI::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
}

void CalendarUI::BuildControlDDX()
{
	_month = dynamic_cast<CComboUI*>(m_PaintManager.FindControl(CTR_MONTH));
	_year  = dynamic_cast<CLabelUI*>(m_PaintManager.FindControl(CTR_INPUTYEAR));

	InitDays();
}

void CalendarUI::OnNextYear(TNotifyUI& msg)
{
	m_sysTime.wYear = m_sysTime.wYear + 1;
	DrawCalendar(m_sysTime);
}

void CalendarUI::OnPreYear(TNotifyUI& msg)
{
	m_sysTime.wYear = m_sysTime.wYear - 1;
	DrawCalendar(m_sysTime);
}

void CalendarUI::OnInputDay(TNotifyUI& msg)
{
	CDuiString str = msg.pSender->GetName();
	str.Replace(CTR_INPUTDAY, "");
	int i = std::stoi(str.GetData());
	_user_selected_day = _days[i];

	SaveData();
	Close();
}

void CalendarUI::OnSelectedMonth(TNotifyUI& msg)
{
	int newmonth = _month->GetCurSel() + 1;
	if (newmonth > _PrevMonth){
		m_sysTime.wMonth = m_sysTime.wMonth + newmonth - _PrevMonth;
		DrawCalendar(m_sysTime);
	}
	else if (newmonth < _PrevMonth){
		m_sysTime.wMonth = m_sysTime.wMonth + newmonth - _PrevMonth;
		DrawCalendar(m_sysTime);
	}
	_PrevMonth = newmonth;
}

void CalendarUI::Notify(TNotifyUI& msg)
{
	DUI__Trace(msg.pSender->GetName());
	if(!msg.pSender->GetName().Find(CTR_INPUTDAY))
		OnInputDay(msg);
	WindowImplBase::Notify(msg);
}

void CalendarUI::OnPrepare()
{
	::GetLocalTime(&m_sysTime);
	_PrevMonth = m_sysTime.wMonth;
	DrawCalendar(m_sysTime);
}

void CalendarUI::InitDays()
{
	for (int i = 0; i < 42; i++) // need fixed 42, auto by xml
	{
		CDuiString name("Button");
		name += std::to_string(i).c_str();
		CButtonUI* btn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(name));
		if (btn) _days.push_back(btn);
	}
}

void CalendarUI::SelectMonth(size_t month)
{
	int index = month - 1;
	_month->SelectItem(index, false, false);
}
//绘制日历
void CalendarUI::DrawCalendar(SYSTEMTIME m_sysTime)
{
	m_sysTime.wDay = 1;
	size_t iStartDay = GetDayOfWeek(m_sysTime);
	//days of the previous month
	size_t iLastMonthStartDays = 31 - iStartDay;
	if (m_sysTime.wMonth > 1)
		iLastMonthStartDays = GetMonthDays(m_sysTime.wYear, m_sysTime.wMonth - 1) - iStartDay;
	//days of the month
	size_t iMonthDays = GetMonthDays(m_sysTime.wYear, m_sysTime.wMonth);
	//days of the next month
	size_t iNextMonthDays = 0;
	size_t iDay = 0;

	for (size_t i = 0; i < _days.size(); i++)
	{
		CButtonUI& btn = *(_days[i]);
		CDuiString date;
		unsigned long color;
		
		if (i<iStartDay)
		{
			iLastMonthStartDays++;
			date = std::to_string(iLastMonthStartDays).c_str();
			color = BT_BKCOLOR1;
		}
		else if (i >= iStartDay && iDay < iMonthDays)
		{
			iDay++;
			date = std::to_string(iDay).c_str();
			color = BT_BKCOLOR2;
		}
		else
		{
			iNextMonthDays++;
			date = std::to_string(iNextMonthDays).c_str();
			color = BT_BKCOLOR3;
		}

		btn.SetText(date);
		btn.SetBkColor(color);
	}

	SelectMonth(m_sysTime.wMonth);

	_year->SetText(std::to_string(m_sysTime.wYear).c_str());
}

size_t CalendarUI::GetMonthDays(size_t year, size_t month)
{
	size_t TotalDay = 31;
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			TotalDay = 29;
		else
			TotalDay = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		TotalDay = 30;
	return TotalDay;
}

size_t CalendarUI::GetDayOfWeek(SYSTEMTIME m_sysTime)
{
	m_ctime.SetDate(m_sysTime.wYear, m_sysTime.wMonth, m_sysTime.wDay);
	return m_ctime.GetDayOfWeek() - 1;
}

CDuiString CalendarUI::GetMonth()
{
	DWORD bkcolor = _user_selected_day->GetBkColor();
	int month = _month->GetCurSel() + 1;
	if (bkcolor == BT_BKCOLOR1)
	{
		month--;
	}
	else if (bkcolor == BT_BKCOLOR3)
	{
		month++;
	}

	//assert(month < 10 && month > 0);
	CDuiString str, format;
	if (month < 10 && month > 0)
		format = "0%d";
	else format = "%d";
	str.Format(format, month);
	return str;
}

CDuiString CalendarUI::GetDay()
{
	CDuiString d = _user_selected_day->GetText();

	if (d.GetLength() < 2)
		d.Format("0%s",d);

	return d;
}

void CalendarUI::SaveData()
{
	CDuiString year = _year->GetText();
	CDuiString day = GetDay();
	CDuiString month = GetMonth();

	_data.Empty();
	_data += year;
	_data += "-";
	_data += month;
	_data += "-";
	_data += day;

	DUI__Trace("user select date : %s", _data);
}


CDuiString CalendarUI::GetData()
{
	return _data;
}