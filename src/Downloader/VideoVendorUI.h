
#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "QMSqlite.h"
#include <sstream>

#define BT_PREV_PAGE		(_T("Prev_page"))
#define BT_NEXT_PAGE		(_T("Next_page"))
#define BT_CLOSE			(_T("close_btn"))
#define BT_OK				(_T("BT_OK"))


enum Select
{
	GetDeviceName,
	GetNothing
};

class CVideoVendorUI :
	public WindowImplBase
{
public:
	CVideoVendorUI();
	~CVideoVendorUI();
	STDSTRING GetDevice();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnCancel(TNotifyUI& msg);
	void GetPrevPage(TNotifyUI& msg);
	void GetNextPage(TNotifyUI& msg);
	void OnSelect(TNotifyUI& msg);

	void SelectEquipment();
	void InitDevice(STDSTRING& Input);
	void InsertToDB();
	void ShowVendorDevice(int page);
	

private:
	BOOL				m_Init;
	QMSqlite*				m_pDb;
	size_t				m_pages;
	size_t					m_pageCount;
	std::vector<string> m_sRecord;
	Select					m_Select;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};
