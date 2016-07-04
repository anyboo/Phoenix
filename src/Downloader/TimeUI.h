#pragma once
#include <DuiLib/UIlib.h>


class CTimeUI :
	public WindowImplBase
{
public:
	CTimeUI();
	~CTimeUI();

	void SaveTimeToJson();

	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();

	void InputControl(STDSTRING& Input);
	void SetBtNumEnabled(int begin_num, int end_num, bool IsEnabled);
private:
	int				m_Site;

protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};