
#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "QMSqlite.h"
#include <sstream>


class CVideoVendorUI :
	public WindowImplBase
{
public:
	CVideoVendorUI();
	~CVideoVendorUI();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void GetPrevPage();
	void GetNextPage();
	void SelectEquipment();

	void InitDevice(STDSTRING& Input);

	void InsertToDB();

	void ShowVendorDevice(int page);


private:
	BOOL				m_Init;
	QMSqlite*			m_pDb;
	int					m_pageCount;
	std::vector<string> m_sRecord;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};
