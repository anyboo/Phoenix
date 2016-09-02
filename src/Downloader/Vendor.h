#pragma once
#include <DuiLib/UIlib.h>

class CVendor
	:public CNotifyPump
{
public:
	CVendor();
	~CVendor();

	void SetPaintMagager(CPaintManagerUI* pPaintMgr);

	void ShowOfflineVendor();
	void AddVendorList(std::string& VendorName, std::string& VendorIP);
	void AddChannelsList(int CurSel, size_t Channel_Count);
	CListContainerElementUI* AddChannels(size_t Channel_Count);

	DUI_DECLARE_MESSAGE_MAP();
	
	

private:
	CPaintManagerUI* ppm;
	int				m_ContListSel;
};
