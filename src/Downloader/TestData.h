#pragma once
#include <vector>
#include <map>

class DVRSession;

typedef struct VendorInfo
{
	std::string channels;
	std::string vendorName;
	std::string ipAddr;
}Vendor_Info, *pVendor_Info;

typedef struct SearchFileInfo
{
	std::string filename;
	int			channel;
	__time64_t  startTime;
	__time64_t  stopTime;
	size_t		size;
}Serach_fileInfo, pSearch_fileInfo;


class CTestData
{
private:	
	CTestData():_playhandle(0){}
public:

	static CTestData* getInstance();
	void SaveLoginInfo(const std::string& vName, const std::string& ipAddr);
	void GetLoginInfo(std::string& channels, std::string& vName, std::string& ipAddr);

	void GetSearchFiles(std::vector<SearchFileInfo>& files);

	void SetPlayhandle(int id);
	void GetPlayFileInfo(Serach_fileInfo& file);

private:
	std::vector<Vendor_Info>			_Login_Info;
	std::vector<SearchFileInfo>			_Files_Info;
	static CTestData* m_instance;

	int									_playhandle;
};

