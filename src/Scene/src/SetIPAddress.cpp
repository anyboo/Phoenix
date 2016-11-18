#include "Scene/SetIPAddress.h"
#include <Poco/Exception.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/ActiveMethod.h>
#include <IPTypes.h>
#include <iphlpapi.h>

#pragma comment(lib,"iphlpapi.lib")

using Poco::Exception;
using Poco::Net::IPAddress;
using Poco::Net::NetworkInterface;

CSetIPAddress::CSetIPAddress()
{
	InitNetIF();
}


CSetIPAddress::~CSetIPAddress()
{
}

void CSetIPAddress::InitNetIF()
{
	NetworkInterface::Map map = NetworkInterface::map(false, false);
	for (NetworkInterface::Map::iterator it = map.begin();
		it != map.end(); ++it)
	{
		NetworkInterface& netInter = it->second;
		if (netInter.type() == netInter.NI_TYPE_ETHERNET_CSMACD && netInter.isUp())
		{
			_inft = netInter;
			std::cout << "init net if: " << _inft.displayName() << std::endl;
			std::cout << "init net if1: " << _inft.adapterName() << std::endl;
		}
	}
}

void CSetIPAddress::GetLocalNetCar(std::string AdapterName, std::vector<IPADDRESSINFO>& IPList, std::vector<std::string>& Gatewaylist)
{
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);
	int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	int netCardNum = 0;
	int IPnumPerNetCard = 0;	
	std::string sNetName;
	PIP_ADAPTER_INFO pfirstIpAdapterInfo;

	if (ERROR_BUFFER_OVERFLOW == nRel)
	{
		delete pIpAdapterInfo;
		pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
		pfirstIpAdapterInfo = pIpAdapterInfo;
		nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	}
	else
	{
		pfirstIpAdapterInfo = pIpAdapterInfo;
	}
	if (ERROR_SUCCESS == nRel)
	{
		while (pIpAdapterInfo)
		{
			switch (pIpAdapterInfo->Type)
			{
			case MIB_IF_TYPE_OTHER:
				break;
			case MIB_IF_TYPE_ETHERNET:
				sNetName = std::string(pIpAdapterInfo->AdapterName);	
				if ( sNetName == AdapterName)
				{									
					IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
					do
					{
						IPADDRESSINFO ipinfo;
						ipinfo.strIP = std::string(pIpAddrString->IpAddress.String);
						ipinfo.strSubNet = std::string(pIpAddrString->IpMask.String);
						IPList.push_back(ipinfo);
						pIpAddrString = pIpAddrString->Next;
					} while (pIpAddrString);

					IP_ADDR_STRING *pGatewayString = &(pIpAdapterInfo->GatewayList);
					do
					{
						Gatewaylist.push_back(std::string(pGatewayString->IpAddress.String));
						pGatewayString = pGatewayString->Next;
					} while (pGatewayString);
					////copy mac
					//for (int i = 0; i < 6; i++)
					//{
					//	Macaddr[i] = pIpAdapterInfo->Address[i];
					//}
				}

				break;
			case MIB_IF_TYPE_TOKENRING:
				break;
			case MIB_IF_TYPE_FDDI:
				break;
			case MIB_IF_TYPE_PPP:
				break;
			case MIB_IF_TYPE_LOOPBACK:
				break;
			case MIB_IF_TYPE_SLIP:
				break;
			default:

				break;
			}

			pIpAdapterInfo = pIpAdapterInfo->Next;
		}
	}
	delete[] pfirstIpAdapterInfo;

}

void CSetIPAddress::GetCurIPAddress(std::vector<IPADDRESS_INFO>& ipsubList, std::vector<std::string>& gatewayList)
{	
	std::cout << "GetCurIPAddress" << std::endl;
	
	GetLocalNetCar(_inft.adapterName(), ipsubList, gatewayList);	
	
}

#include <shellapi.h>
bool CSetIPAddress::setNetConfig(const std::string& sIP, const std::string& sMask, const std::string& sGate)
{
	std::string mask(" mask=");
	mask.append(sMask);
	std::string sssname = _inft.name();
	int len = MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)sssname.c_str(), -1, NULL, 0);
	wchar_t * wszGBK = new wchar_t[len];
	memset(wszGBK, 0, len);
	MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)sssname.c_str(), -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	std::string sNetName(szGBK);
	delete[] szGBK;
	delete[] wszGBK;

	std::string name(" name = \"");
	name += sNetName;
	name.append("\"");
	std::string addr(" addr=");
	addr += sIP;
	std::string argList;

	if (!sGate.empty())
	{
		argList = "interface ip set address";
		argList += name;
		argList.append(" source = static ");
		argList = argList + addr + mask;
		std::string gateway(" gateway=");
		gateway += sGate;
		argList += gateway;

	}
	else
	{
		argList = "interface ip add address";
		argList += name;
		argList = argList + addr + mask;
	}
	std::cout << "shell text: " << argList << std::endl;
	int nRun = (int)::ShellExecuteA(NULL, (LPCSTR)"open", (LPCSTR)"netsh.exe", (LPCSTR)argList.c_str(), NULL, SW_HIDE);
	if (nRun <= 32)
		return false;

	return true;
}

