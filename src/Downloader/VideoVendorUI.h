
#pragma once
#include <DuiLib/UIlib.h>
#include <vector>
#include "QMSqlite.h"
#include <sstream>

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
	Select				m_Select;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};
