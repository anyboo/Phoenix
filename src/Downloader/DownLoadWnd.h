#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "Vendor.h"
#include "DownLoadList.h"
#include "TimeUI.h"
#include <map>
#include <Poco/DateTime.h>

typedef enum
{
	DL_STATUS_WAITING = 0,
	DL_STATUS_DOWNLOADING,
	DL_STATUS_FINISH
};

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
	
	void ReadJsonFile();

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

	void OnSearch(TNotifyUI& msg);
	bool SearchBegin();
	void OnLogin(TNotifyUI& msg);
	void OnBackward(TNotifyUI& msg);

	void OnSelectCalendar(TNotifyUI& msg);
	void OnSelectDayTime(TNotifyUI& msg);
	void OnAdjustOffsetTime(TNotifyUI& msg);
	void FixedSliderPosition(TNotifyUI& msg);

	void InitTime();
	void BuildControlDDX();

	void CheckOption(CDuiString& sName);

	void OnCheckAllchannels(TNotifyUI& msg);

	void GetDataAndTime(Poco::DateTime& start, Poco::DateTime& stop);

	void SetButtonImage(const CDuiString& ctr_name, const CDuiString& day);
	void SetLabelText(const CDuiString& ctr_name, const CDuiString& text);
	CDuiString AppenText(const CDuiString& str);

	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);


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
	std::vector<int>		_all_channels;
	CVendor		_vendorManage;
	CDownLoadList	_downloadManage;
	CButtonUI*			_btn_offset1;
	CButtonUI*			_btn_offset2;
	CButtonUI*			_btn_search;
	SYSTEMTIME		 m_sysTime;
	CTimeUI*	_TimeControl;
	CListUI*	_vList;
	CButtonUI*  _SearchControl;
	CListUI*	_VendorList;
	std::string			_device_name;

	std::string			_DownloadPath;
	std::vector<size_t>	_download_fileID;
	std::map<int, std::string>		_VnameAndType;
	CDuiStringPtrMap _ControlMatrix;

	const CDuiString ico_startdate = _T("DataTime1");
	const CDuiString ico_stopdate = _T("DataTime2");
	const CDuiString startdate = _T("DatatimeText1");
	const CDuiString stopdate = _T("DatatimeText2");
	const CDuiString starttime = _T("daytimeText1");
	const CDuiString stoptime = _T("daytimeText2");
	const CDuiString timetype = _T("Select_time");

	std::vector<long>	_download_handle;
	size_t		_file_id;
	std::vector<int>		_pro_value;
	std::string             _search_time;
//	Poco::Timer t;
//	Poco::TimerCallback<DownLoadWnd> tc;
};

