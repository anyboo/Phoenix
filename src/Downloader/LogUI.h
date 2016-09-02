#pragma once
#include <DuiLib/UIlib.h>
#include <vector>

class CNotificationNetworkStatus;

#define  BT_SearchLog		(_T("search"))
#define		BT_OnStartTime		(_T("DataTime1"))
#define	 BT_OnStopTime		(_T("DataTime2"))

typedef struct 
{
	std::string	Time;
	std::string	Handle;
	std::string	Description;
}Log_Search;

typedef struct 
{
	std::string	Time;
	std::string	Address;
	std::string	Collect_people;
	std::string	CaseName;
	std::string	Case_description;
	std::string	EquipmentIP;
	std::string	Remark;
}Case_Search;

class CLogUI :
	public WindowImplBase
{
public:
	CLogUI();
	~CLogUI();
	virtual void InitWindow();
	virtual void OnFinalMessage(HWND /*hWnd*/);
	virtual void Notify(TNotifyUI& msg);
	DUI_DECLARE_MESSAGE_MAP();
	void OnBeginSearch(TNotifyUI& msg);

	void OnSearchLog();
	void OnSearchCaseLog();

	void CreateLogList();
	void CreateCaseList();

	void InsertLogInfoToList();
	void InsertCaseInfoToList();

	void OnSelectStartTime(TNotifyUI& msg);
	void OnSelectStopTime(TNotifyUI& msg);
	void exportLog();
	void InitTime();

	void SetBtDataImage(std::string& BT_Name, std::string& day);

	void HandleNotificationNetworkStatus(CNotificationNetworkStatus* pNf);

protected:
	std::vector<Log_Search>		m_LogInfo;
	std::vector<Case_Search>		m_CaseInfo;
	BOOL					m_bInit;
	SYSTEMTIME		 m_sysTime;
protected:
	virtual LPCTSTR GetWindowClassName() const;
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
};
