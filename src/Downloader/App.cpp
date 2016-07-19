// App.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
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
#include "MessagePump.h"

static VENDOR_LIST pVendorList;

DEVICE_INFO_SIMPLE_LIST GetDeviceInfoSimpleList()
{
	DEVICE_INFO_SIMPLE_LIST listDeviceSimpleInfo;

	std::vector<ScanPortRecord> scanResults;
	//获取指针
	QMSqlite *pDb = QMSqlite::getInstance();
	std::string sql = SELECT_ALL_SCAN_PORT;
	pDb->GetData(sql, scanResults);

	for (size_t i = 0; i < scanResults.size(); i++)
	{
		ScanPortRecord spr = scanResults[i];
		if (spr.get<1>() == 80)
		{
			continue;
		}

		NET_DEVICE_INFO_SIMPLE* devInfoSimple = new NET_DEVICE_INFO_SIMPLE;
		memset(devInfoSimple, 0, sizeof(NET_DEVICE_INFO_SIMPLE));
		std::string ip = spr.get<0>();
		memcpy(devInfoSimple->szIP, ip.c_str(), ip.length());
		devInfoSimple->nPort = spr.get<1>();
		listDeviceSimpleInfo.push_back(devInfoSimple);
	}

	return listDeviceSimpleInfo;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	MessagePump pump;
	pump.start();

	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skins\\Min"));

	//CPaintManagerUI::SetResourcePath("bin");
	
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	std::auto_ptr<CMainWnd> pFrame(new CMainWnd);
	assert(pFrame.get());
	pFrame->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE | WS_EX_ACCEPTFILES);
	pFrame->SetIcon(IDI_ICON1);
	pFrame->CenterWindow();
	pFrame->ShowWindow(true);

	/*LPARAM lParam;
	lParam = ABS_AUTOHIDE | ABS_ALWAYSONTOP;
	HWND task = FindWindow(_T("Shell_TrayWnd"), NULL);
	::ShowWindow(task, SW_HIDE);

	APPBARDATA apBar;
	memset(&apBar, 0, sizeof(apBar));
	apBar.cbSize = sizeof(apBar);
	apBar.hWnd = task;
	if (apBar.hWnd != NULL)
	{
		apBar.lParam = lParam;
		SHAppBarMessage(ABM_SETSTATE, &apBar);
	}*/

	/************************* 初始化SDK厂商 **********************/
	
	CJXJVendor* jxjVendor = new CJXJVendor();
	CDZPVendor* dzpVendor = new CDZPVendor();
	DHVendor* dhVendor = new DHVendor();
	HKVendor* hkVendor = new HKVendor();

	pVendorList.push_back(jxjVendor);
	//pVendorList.push_back(dzpVendor);
	//pVendorList.push_back(dhVendor);
	//pVendorList.push_back(hkVendor);

	/************************* 初始化IP列表 **********************/
	//std::cout << CCommonUtrl::getInstance().GetCurTime() << "Scan Port Start!" << std::endl;
	//NotificationQueue queuePortScan;
	//PortScan portScan(queuePortScan);
	////开始扫描
	//ThreadPool::defaultPool().start(portScan);

	DEVICE_INFO_SIMPLE_LIST listDeviceSimpleInfo;
	//while (true)
	//{
	//	Notification::Ptr pNf(queuePortScan.waitDequeueNotification());
	//	if (pNf)
	//	{
	//		ScanNotification::Ptr pWorkNf = pNf.cast<ScanNotification>();
	//		if (pWorkNf)
	//		{
	//			listDeviceSimpleInfo = GetDeviceInfoSimpleList();
	//			std::cout << CCommonUtrl::getInstance().GetCurTime() << "Scan Port Stop!" << std::endl;
	//			break;
	//		}
	//	}
	//}

	/************************* 设备发现类测试 **********************/
	std::cout << CCommonUtrl::getInstance().GetCurTime() << "Search Device Start!" << std::endl;
	NotificationQueue queueSearchDevice; // 设备发现消息队列
	CSearchDevice sd(pVendorList, listDeviceSimpleInfo, queueSearchDevice);
	ThreadPool::defaultPool().start(sd);
	//queueSearchDevice.enqueueNotification(new CNotificationSearchDevice(Notification_Type_Search_Device_Cancel));

	/************************* 设备管理类测试 **********************/
	//NotificationQueue queueDeviceManager; // 设备管理消息队列
	//CDeviceManager dm(pVendorList, queueDeviceManager);
	//ThreadPool::defaultPool().start(dm);
	//queueDeviceManager.enqueueNotification(new CNotificationDeviceManager(Notification_Type_Device_Manager_Cancel));

	while (true)
	{
		Notification::Ptr pNf(NotificationQueue::defaultQueue().waitDequeueNotification());
		if (pNf)
		{
			CNotificationSearchDevice::Ptr pWorkNf = pNf.cast<CNotificationSearchDevice>();
			if (pWorkNf)
			{
				if (pWorkNf->GetNotificationType() == Notification_Type_Search_Device_Finish)
				{
					std::cout << CCommonUtrl::getInstance().GetCurTime() << "Search Device Stop!" << std::endl;
					break;
				}
			}
		}
	}
	
	//DEVICE_INFO_LIST devInfoList = CSearchDevice::GetDeviceInfoList();

	CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	
	pump.stop();

	return 0;
}


