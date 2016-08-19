#pragma once
#include <DuiLib/UIlib.h>
#include "SetIPAddress.h"

#define BT_ADDSET			(_T("Add_Setting"))
#define BT_DELSET			(_T("Delete"))
#define BT_CLOSEIPWND		(_T("bt_close"))
#define BT_USE_IP			(_T("Add_Use"))

class CSetIpWnd :
	public WindowImplBase
{
public:
	CSetIpWnd();
	~CSetIpWnd();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnCloseWnd(TNotifyUI& msg);
	void OnAddIPSet(TNotifyUI& msg);
	void OnDelIPSet(TNotifyUI& msg);
	void OnInputNum(TNotifyUI& msg);
	void OnUseSelectIP(TNotifyUI& msg);

	void NextInput(CDuiString& SendName);

	void AddIP_Address();

	void InsertList(CDuiString& strIP, CDuiString& strSubNet, CDuiString& strGateWay);
	void RemoveSubList();


protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();

	void InitShowCurIPAddress();

private:
	CSetIPAddress	setip;
private:
	CEditUI*		_edit_ip1;
	CEditUI*		_edit_ip2;
	CEditUI*		_edit_ip3;
	CEditUI*		_edit_ip4;
	CEditUI*		_edit_subnet1;
	CEditUI*		_edit_subnet2;
	CEditUI*		_edit_subnet3;
	CEditUI*		_edit_subnet4;
	CEditUI*		_edit_broadcast1;
	CEditUI*		_edit_broadcast2;
	CEditUI*		_edit_broadcast3;
	CEditUI*		_edit_broadcast4;
	CListUI*		_pList;
	CLabelUI*		_lab_setIPaddress;
	CLabelUI*		_lab_setSubNetAddress;
	CLabelUI*		_lab_setBroadcastAddress;
};