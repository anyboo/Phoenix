#pragma once
#include <map>

class ProgressManager
{
public:
	ProgressManager();
	~ProgressManager();

	void SaveSubList(CProgressUI* progress, size_t ID);
	size_t GetListSize();
	CProgressUI* GetSubList(size_t CurSel);
private:
	std::map<CProgressUI*, size_t>		m_SubList;
};

