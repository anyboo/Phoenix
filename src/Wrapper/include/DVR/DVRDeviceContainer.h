#pragma once
#include "DVR/DVR.h"
#include "DVR/DVRDevice.h"
#include <map>
#include <Poco/String.h>
#include <Poco/AutoPtr.h>
#include <Poco/Mutex.h>

#include <Poco/SingletonHolder.h>


using Poco::Mutex;

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
		//static DVRDeviceContainer* getInstance()
		//{
		//	if (instance == NULL)
		//	{
		//		_lockMutex.lock();
		//		if (instance == NULL)
		//		{
		//			instance = new DVRDeviceContainer();
		//		}
		//		_lockMutex.unlock();
		//	}

		//	return instance;
		//}

		void add(DVRDevice* device);
		void remove(const std::string& name);
		bool has(const std::string& name) const;
		DVRDevice& get(const std::string& name);
		int count() const;

	private:
		
		typedef std::map<std::string, Poco::AutoPtr<DVRDevice>, Poco::CILess> DevicePoolMap;

		DVRDeviceContainer(const DVRDeviceContainer&);
		DVRDeviceContainer operator =(const DVRDeviceContainer&);

		DevicePoolMap _devicePool;
		Poco::FastMutex _mutex;
	//	static Poco::Mutex _lockMutex;
	//	static DVRDeviceContainer* instance;
	};
	
	

	void DVRDeviceContainer::remove(const std::string& name)
	{
		_devicePool.erase(name);
	}

	bool DVRDeviceContainer::has(const std::string& name) const
	{
		return _devicePool.find(name) != _devicePool.end();
	}

	int DVRDeviceContainer::count() const
	{
		return static_cast<int>(_devicePool.size());
	}
}

