#pragma once
#include <vector>
#include <map>

typedef struct VendorInfo
{
	std::string channels;
	std::string vendorName;
	std::string ipAddr;
}Vendor_Info, *pVendor_Info;

class CTestData
{
private:	
	CTestData(){}
public:

	static CTestData* getInstance();
	void SaveLoginInfo(const std::string& vName, const std::string& ipAddr);

	void GetLoginInfo(std::string& channels, std::string& vName, std::string& ipAddr);

private:
	std::vector<Vendor_Info>			_Login_Info;
	static CTestData* m_instance;
};

