#pragma once
#include <DuiLib/UIlib.h>
#include <map>

#define BT_VideoVendor			(_T("select_Vendor"))
#define BT_LOGIN				(_T("LogIn"))
#define BT_PREVPAGE				(_T("Prev_page"))
#define BT_NEXTPAGE				(_T("Next_page"))
#define BT_CLOSELOGWND			(_T("closebtn"))
#define Edit_SearchVendor		(_T("brand_Edit"))

enum ISLogIn
{
	LogInDevice,
	NoLogDevice
};

class VideoLoginUI :
	public WindowImplBase
{
public:
	VideoLoginUI();
	~VideoLoginUI();

	void LogIn();
	bool GetLoginState();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnLogIn(TNotifyUI& msg);
	void OnPrevPage(TNotifyUI& msg);
	void OnNextPage(TNotifyUI& msg);
	void OnClose(TNotifyUI& msg);

	void OnOpenVideoVendorWnd(TNotifyUI& msg);
	void OnShowDeviceInfo(CDuiString& SendName);

	void OnSearchVendorList(TNotifyUI& msg);

	void OnShowDevice(int pages);

	void GetNextPage();
	void GetPrevPage();

	void ShowPagesLable(int page);

	void CountDevice();

	void InsertVendorToDB();
	void SearchVendorList();
	void InsertVendorToList();

	void CreateSubvLyt();
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	void BuildControlDDX();

private:
	ISLogIn			m_IsLogIn;
	size_t						m_page_Count;
	size_t				m_pages;
	std::vector<string> m_sRecord;
	std::map<int, string>		m_CnameAndType;

private:
	CEditUI*		_brand_edit;
	CEditUI*		_ip_edit;
	CEditUI*		_port_edit;
	CEditUI*		_user;
	CEditUI*		_pswd;
	CLabelUI*		_vendorCount;
	CVerticalLayoutUI*	_login_info_lyt;
	CVerticalLayoutUI*	_vendorList;
	CHorizontalLayoutUI*	_HLayout;
	CListUI*			_device_list;
	CLabelUI*			_pages;
};