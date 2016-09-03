#include "stdafx.h"
#include "TestData.h"
#include <mutex> 
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

void CTestData::SaveLoginInfo(const std::string& vName, const std::string& ipAddr)
{
	Vendor_Info vendor;
	vendor.ipAddr = ipAddr;
	vendor.vendorName = vName;
	vendor.channels = std::to_string(4);
	_Login_Info.push_back(vendor);
}

void CTestData::GetLoginInfo(std::string& channels, std::string& vName, std::string& ipAddr)
{
	size_t n = _Login_Info.size() - 1;
	channels = _Login_Info[n].channels;
	vName = _Login_Info[n].vendorName;
	ipAddr = _Login_Info[n].ipAddr;
}
