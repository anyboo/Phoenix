#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "Vendor.h"
#include "TimeUI.h"
#include <map>
//#include "NICStatus.h"

//class NICStatusChanged;

class DownLoadWnd :
	public WindowImplBase
//	public NICStatusChanged
{
public:
	DownLoadWnd();
	~DownLoadWnd();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
	
	void ReadJsonFile();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

	void OnSearch(TNotifyUI& msg);
	void OnLogin(TNotifyUI& msg);
	void OnBackward(TNotifyUI& msg);

	void OnSelectCalendar(TNotifyUI& msg);
	void OnSelectDayTime(TNotifyUI& msg);
	void FixedSliderPosition(TNotifyUI& msg);

	void InitTime();
	void BuildControlDDX();

//	virtual void OnStatusChanged(NETWORK_STATUS st);
	void SetButtonImage(const CDuiString& ctr_name, const CDuiString& day);
	void SetLabelText(const CDuiString& ctr_name, const CDuiString& text);
	CDuiString AppenText(const CDuiString& str);

	template<class T>
	void AddControl(CDuiString ctr_name)
	{
		T* c = dynamic_cast<T*>(m_PaintManager.FindControl(ctr_name));
		assert(c);
		if (c){
			ctr_name.MakeLower();
			_ControlMatrix.Insert(ctr_name, c);
		}
	}

	template<class T>
	T* GetControl(CDuiString ctr_name)
	{
		ctr_name.MakeLower();
		assert(_ControlMatrix.Find(ctr_name));
		T* c = static_cast<T*>(_ControlMatrix.Find(ctr_name));
		assert(c);
		return c;
	}

private:
	CVendor		m_Vendor;
	SYSTEMTIME		 m_sysTime;

	CTimeUI*	_TimeControl;
	CButtonUI*  _SearchControl;
	CListUI*	_VendorList;

	CDuiStringPtrMap _ControlMatrix;

	const CDuiString ico_startdate = _T("DataTime1");
	const CDuiString ico_stopdate = _T("DataTime2");
	const CDuiString startdate = _T("DatatimeText1");
	const CDuiString stopdate = _T("DatatimeText2");
	const CDuiString starttime = _T("daytimeText1");
	const CDuiString stoptime = _T("daytimeText2");
	const CDuiString timetype = _T("Select_time");
};

