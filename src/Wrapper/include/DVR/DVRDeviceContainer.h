#pragma once
#include "DVR/DVR.h"
#include "DVR/DVRDevice.h"
#include <map>
#include <Poco/String.h>
#include <Poco/AutoPtr.h>
#include <Poco/Mutex.h>

#include <Poco/SingletonHolder.h>

using Poco::Mutex;


		
		//static DVRDeviceContainer& DVRDeviceContainer::getInstance()
		//{
		//	static Poco::SingletonHolder<DVR::DVRDeviceContainer> _Dc;
		//	return *_Dc.get();
		//}
		//static DVRDeviceContainer* getInstance()
		//{
		//	if (nullptr == m_instance)
		//	{
		//		if (NULL == m_instance)
		//		{
		//			m_instance = new DVRDeviceContainer;
		//		}
		//	}
		//	return m_instance;
		//}
	
namespace DVR{
		class DVRDevice;
		class DVR_API DVRDeviceContainer
		{
		public:
			DVRDeviceContainer();
			~DVRDeviceContainer();

			static DVRDeviceContainer& DVRDeviceContainer::getInstance()
			{
				static Poco::SingletonHolder<DVR::DVRDeviceContainer> _Dc;
				return *_Dc.get();
			}

			void add(DVRDevice* device);
			void remove(const std::string& name);
			bool has(const std::string& name) const;
			DVRDevice& get(const std::string& name);
			void getAllDeviceName(std::vector<std::string>& names);
			int count() const;

		private:
			typedef std::map<std::string, Poco::AutoPtr<DVRDevice>, Poco::CILess> DevicePoolMap;

			DVRDeviceContainer(const DVRDeviceContainer&);
			DVRDeviceContainer operator =(const DVRDeviceContainer&);

			DevicePoolMap _devicePool;
			Poco::FastMutex _mutex;
		};
}

