#pragma once
#include <DuiLib/UIlib.h>

#define BT_VERIFY			(_T("bt_ok"))
#define BT_RESET			(_T("bt_delete"))


class CTimeUI :
	public WindowImplBase
{
public:
	CTimeUI();
	~CTimeUI();

	CDuiString GetTime();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void OnReset(TNotifyUI& msg);
	void OnVerify(TNotifyUI& msg);

	void InputControl(CDuiString& Input);
	void SetBtNumEnabled(int begin_num, int end_num, bool IsEnabled);
private:
	int				_site;
	CLabelUI*		_lab_time;
	CDuiString		_setTime;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};