#include "stdafx.h"
#include "ProgressManager.h"


ProgressManager::ProgressManager()
{
}


ProgressManager::~ProgressManager()
{
}

void ProgressManager::SaveSubList(CProgressUI* progress, size_t ID)
{
	m_SubList.insert(std::pair<CProgressUI*, size_t>(progress, ID));
}

size_t ProgressManager::GetListSize()
{
	return m_SubList.size();
}

CProgressUI* ProgressManager::GetSubList(size_t CurSel)
{
	CProgressUI* progress = new CProgressUI;
	
	std::map<CProgressUI*, size_t>::iterator iter = m_SubList.begin();
	size_t i = 0;
	while (i != CurSel)
	{
		i++;
		iter++;
	}
	return iter->first;
}