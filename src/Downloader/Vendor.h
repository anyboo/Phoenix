#pragma once
#include <DuiLib/UIlib.h>

class CVendor
	:public CNotifyPump
{
public:
	CVendor();
	~CVendor();

	void SetPaintMagager(CPaintManagerUI* pPaintMgr);

	void Off_line();
	void DeleteVendor(CDuiString& sName);
	void AddVendorList(std::string& VendorName, std::string& VendorIP);
	void ChangeChannelsList(CDuiString& sName, size_t Channel_Count);

	DUI_DECLARE_MESSAGE_MAP();
	
protected:
	CListContainerElementUI* AddChannels(size_t Channel_Count);
	void DeleteChannelList(int Cursel, int channels);

private:
	CPaintManagerUI* ppm;
	int				m_ContListSel;
};
