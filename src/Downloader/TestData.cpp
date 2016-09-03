#include "stdafx.h"
#include "TestData.h"
#include <mutex> 
#include "DVR/DVRSession.h"
std::mutex mtx;


CTestData *CTestData::m_instance = nullptr;

CTestData* CTestData::getInstance()
{
	if (nullptr == m_instance)
	{
		mtx.lock();
		if (NULL == m_instance)
		{
			m_instance = new CTestData;
		}
		mtx.unlock();
	}
	return m_instance;
}

void CTestData::SaveLoginInfo(Vendor_Info& vendor)
{
	_SessionID += 1;
	vendor.channels = 4;
	_Login_Info.insert(pair<unsigned long, Vendor_Info>(_SessionID, vendor));
}

void CTestData::GetLoginInfo(Vendor_Info& vendor)
{
	vendor = _Login_Info[_SessionID];
}

unsigned long CTestData::GetLoginID()
{
	return _SessionID;
}

void CTestData::GetSearchFiles(std::vector<SearchFileInfo>& files)
{
	time_t now_time;
	now_time = time(NULL);

	Serach_fileInfo file_info;
	for (int i = 1; i <= 10; i++)
	{
		file_info.channel = 1;
		file_info.filename = std::string("filename") + to_string(i);
		file_info.startTime = now_time - 10000;
		file_info.stopTime = now_time;
		file_info.size = 324213;
		files.push_back(file_info);
	}
	_Files_Info = files;
}

void CTestData::SetPlayhandle(int id)
{
	_playhandle = id;
}

void CTestData::GetPlayFileInfo(Serach_fileInfo& file)
{
	file = _Files_Info[_playhandle];
}
