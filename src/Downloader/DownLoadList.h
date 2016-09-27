#pragma once

class CDownLoadList
	:public CNotifyPump
{
public:
	CDownLoadList();
	~CDownLoadList();

	void SetPaintMagager(CPaintManagerUI* pPaintMgr);

	void AddDownloadTask(const std::vector<size_t>& IDs, const std::vector<long>& handle, const std::string name);
	void AddDataToSubList(CListContainerElementUI* TaskList, const size_t fileID);
	CDuiString TimeChange(__time64_t inputTime);

	void Show_Off_SubList(CDuiString& strSendName);
	int GetSubListCurSel(CListContainerElementUI* SubList, CListUI* pList);

	CListContainerElementUI* Add_FileInfoList();
	void RemoveSubList(CDuiString& strSendName);

	void RenewList();


	void AddSubListAttr(CListContainerElementUI* SubList);
private:
	CPaintManagerUI* _ppm;
	int				_taskCount;
	std::vector<long>		_download_handle;
	std::vector<size_t>		_download_filesID;
	std::vector<int>		_prev_pro;
	std::string				_device_name;
};

