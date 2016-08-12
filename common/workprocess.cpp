#include "stdafx.h"
#include <objbase.h>
#include <shellapi.h>
#include "workprocess.h"


#include <client\windows\handler\exception_handler.h>
#include "pipe.h"

#include "MainWnd.h"
#include "resource.h"

#include "portscan.h"
#include "QMFileSqlite.h"
#include "QMSqlite.h"

#include "SearchDevice.h"
#include "DeviceManager.h"

#include "JXJVendor.h"
#include "DZPVendor.h"
#include "DHVendor.h"
#include "HKVendor.h"

#include "ipset.h"

#include <fstream>

#include "MessagePump.h"
#include "log.h"

namespace WorkProcess
{
	static std::wstring g_dump_path;

	static void OpenConsole()
	{
		AllocConsole();
		HANDLE   handle = GetStdHandle(STD_OUTPUT_HANDLE);
		int   hCrt = _open_osfhandle((long)handle, _O_TEXT);
		FILE   *   hf = _fdopen(hCrt, "w");
		*stdout = *hf;
	}

	int WorkProcessMain(_In_ HINSTANCE hInstance,
		_In_opt_ HINSTANCE hPrevInstance,
		_In_ LPTSTR    lpCmdLine,
		_In_ int       nCmdShow)
	{
#ifdef _DEBUG  
		OpenConsole();
#endif

		StartServerExe();
		AddExceptionCatch();

		return appinit(hInstance);
	}

	int appinit(_In_ HINSTANCE hInstance)
	{
		MessagePump pump;
		pump.start();

		CPaintManagerUI::SetInstance(hInstance);
		CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Min"));

		HRESULT Hr = ::CoInitialize(NULL);
		if (FAILED(Hr)) return 0;

		std::auto_ptr<CMainWnd> pFrame(new CMainWnd);
		assert(pFrame.get());
		pFrame->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE | WS_EX_ACCEPTFILES);
		pFrame->SetIcon(IDI_ICON1);
		pFrame->CenterWindow();
		pFrame->ShowWindow(true);

		//	HideTaskBar();
		Loggering::Setup_logger();
		/************************* 初始化数据库 **********************/
		//获取指针
		fstream _file;
		_file.open("phoenix.db", ios::in);
		if (!_file)
		{
			QFileSqlite *pFileDb = QFileSqlite::getInstance();
			//删除表
			pFileDb->dropTable(DROP_LOGIN_DEVICE_INFO_TABLE);
			//创建记录表
			pFileDb->createTable(CREATE_LOGIN_DEVICE_INFO_TABLE);
		}

		//获取指针
		QMSqlite *pDb = QMSqlite::getInstance();
		//删除表
		pDb->dropTable(DROP_SEARCH_VIDEO_TABLE);
		//创建记录表
		pDb->createTable(CREATE_SEARCH_VIDEO_TABLE);

		/************************* 初始化SDK厂商 **********************/
		VENDOR_LIST pVendorList;
		CJXJVendor* jxjVendor = new CJXJVendor();
		CDZPVendor* dzpVendor = new CDZPVendor();
		//DHVendor* dhVendor = new DHVendor();
		//HKVendor* hkVendor = new HKVendor();

		pVendorList.push_back(jxjVendor);
		pVendorList.push_back(dzpVendor);
		/*	pVendorList.push_back(dhVendor);
		pVendorList.push_back(hkVendor);*/

		/************************* IP setting **************************/

		//std::cout << CCommonUtrl::getInstance().GetCurTime() << "ip setting Start!" << std::endl;
		//IPSet ipset;
		//ipset.run();
		//Sleep(5000);

		/*std::cout << CCommonUtrl::getInstance().GetCurTime() << "ip setting Start!" << std::endl;
		IPSet ipset;
		ipset.run();
		Sleep(5000);*/


		///************************* 初始化IP列表 **********************/
		DEVICE_INFO_SIMPLE_LIST listDeviceSimpleInfo;
		std::cout << CCommonUtrl::getInstance().GetCurTime() << "Scan Port Start!" << std::endl;
		NotificationQueue queuePortScan;	
		PortScan portScan(queuePortScan);
		//开始扫描
		ThreadPool::defaultPool().start(portScan);

		while (true)
		{
			Notification::Ptr pNf(queuePortScan.waitDequeueNotification());
			if (pNf)
			{
				ScanNotification::Ptr pWorkNf = pNf.cast<ScanNotification>();
				if (pWorkNf)
				{
					listDeviceSimpleInfo = CSearchDevice::GetDeviceInfoSimpleList();
					std::cout << CCommonUtrl::getInstance().GetCurTime() << "Scan Port Stop!" << std::endl;
					break;
				}
			}
		}		

		/************************* 设备发现类测试 **********************/
		std::cout << CCommonUtrl::getInstance().GetCurTime() << "Search Device Start!" << std::endl;
		NotificationQueue queueSearchDevice; // 设备发现消息队列
		CSearchDevice sd(pVendorList, listDeviceSimpleInfo, queueSearchDevice);
		ThreadPool::defaultPool().start(sd);
		//queueSearchDevice.enqueueNotification(new CNotificationSearchDevice(Notification_Type_Search_Device_Cancel));

		/************************* 设备管理类测试 **********************/
		NotificationQueue queueDeviceManager; // 设备管理消息队列
		CDeviceManager dm(pVendorList, queueDeviceManager);
		ThreadPool::defaultPool().start(dm);
		//queueDeviceManager.enqueueNotification(new CNotificationDeviceManager(Notification_Type_Device_Manager_Cancel));

		//while (true)
		//{
		//	Notification::Ptr pNf(NotificationQueue::defaultQueue().waitDequeueNotification());
		//	if (pNf)
		//	{
		//		CNotificationSearchDevice::Ptr pWorkNf = pNf.cast<CNotificationSearchDevice>();
		//		//CNotificationDeviceManager::Ptr pWorkNf = pNf.cast<CNotificationDeviceManager>();
		//		if (pWorkNf)
		//		{
		//			if (pWorkNf->GetNotificationType() == Notification_Type_Search_Device_Finish)
		//			{
		//				break;
		//			}
		//		}
		//	}
		//}

		DEVICE_INFO_LIST devInfoList = CSearchDevice::GetDeviceInfoList();

		CPaintManagerUI::MessageLoop();

		::CoUninitialize();

		pump.stop();

		return 1;
	}
	
	DWORD WINAPI AsynUpload(void* context)
	{
		//std::map<std::wstring, std::wstring> parameters;
		//int timeout = 30000;  //30second send or receive timeout
		//std::wstring response_body;
		//int response_code = 0;
		//bool bRet = google_breakpad::HTTPUpload::SendRequest(L"http://172.17.195.141/hfs_up/",
		//	parameters,
		//	g_dump_path.c_str(),
		//	L"ufile01",
		//	&timeout,
		//	&response_body,
		//	&response_code);
		return 0;
	}

	bool ShowDumpResults(const wchar_t* dump_path,
		const wchar_t* minidump_id,
		void* context,
		EXCEPTION_POINTERS* exinfo,
		MDRawAssertionInfo* assertion,
		bool succeeded) {
		//In case of out-of-process dump generation, dump_path will be NULL.
		if (dump_path == NULL)
		{
			return succeeded;
		}
		g_dump_path = dump_path;
		QueueUserWorkItem(AsynUpload, NULL, WT_EXECUTEDEFAULT);
		return succeeded;
	}

	void AddExceptionCatch()
	{
		std::wstring dump_folder = L"dumps\\";
		::CreateDirectoryW(dump_folder.c_str(), NULL);
		google_breakpad::CustomClientInfo custom_info = { kCustomInfoEntries, kCustomInfoCount };
		static google_breakpad::ExceptionHandler* handler = new google_breakpad::ExceptionHandler(dump_folder.c_str(),
			NULL,
			ShowDumpResults,
			NULL,
			google_breakpad::ExceptionHandler::HANDLER_ALL,
			MiniDumpNormal,
			kPipeName,
			&custom_info);
	}

	std::wstring GetGUIDStr()
	{
		wchar_t buffer[128] = { 0 };
		GUID guid;
		if (::CoCreateGuid(&guid) != S_OK)
		{
			return L"";
		}
		::_snwprintf_s(buffer, _countof(buffer), _countof(buffer), L"%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",
			guid.Data1, guid.Data2, guid.Data3,
			guid.Data4[0], guid.Data4[1], guid.Data4[2],
			guid.Data4[3], guid.Data4[4], guid.Data4[5],
			guid.Data4[6], guid.Data4[7]);
		return buffer;
	}

	void StartServerExe()
	{
		wchar_t lpszFileName[MAX_PATH] = { 0 };
		::GetModuleFileNameW(NULL, lpszFileName, MAX_PATH);
		std::wstring strFullName = lpszFileName;
		std::wstring strGUID = GetGUIDStr();
		HANDLE hEvent = ::CreateEventW(NULL, FALSE, FALSE, strGUID.c_str());
		std::wstring strParam = L"crash_server=";
		strParam += strGUID;
		::ShellExecuteW(NULL, L"open", strFullName.c_str(), strParam.c_str(), NULL, SW_SHOWNORMAL);
		if (hEvent != NULL)
		{
			// wait for the crash_server start, wait 2 seconds.
			DWORD dwRet = ::WaitForSingleObject(hEvent, 2000);
			if (dwRet != WAIT_OBJECT_0)
			{
				//error
			}
			::CloseHandle(hEvent);
		}
		else
		{
			//error
		}
	}
}

