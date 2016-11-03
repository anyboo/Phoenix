#include "DVR/DVRDeviceContainer.h"
#include "DVR/DVRDevice.h"
#include "DVR/DVRException.h"

using Poco::FastMutex;

namespace DVR{
	DVRDeviceContainer::DVRDeviceContainer()
	{
	}

	DVRDeviceContainer::~DVRDeviceContainer()
	{
	}

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

	void DVRDeviceContainer::add(DVRDevice* device)
	{
		poco_check_ptr(device);

		FastMutex::ScopedLock lock(_mutex);

		if (_devicePool.find(device->name()+device->address()) != _devicePool.end())
			throw DevicePoolExistsException("device already exists" + device->name());

		device->duplicate();
		std::string ipport = device->address();
		_devicePool.insert(DevicePoolMap::value_type(device->name() + "(" + ipport.substr(0, ipport.find(":")) + ")", device));

	}

	DVRDevice& DVRDeviceContainer::get(const std::string& name)
	{
		poco_assert(!name.empty());

		FastMutex::ScopedLock lock(_mutex);
		DevicePoolMap::iterator it = _devicePool.find(name);
		if (_devicePool.end() == it) throw Poco::NotFoundException(name);
		return *it->second;
		//QNzrdXMy
	}

	void DVRDeviceContainer::getAllDeviceName(std::vector<std::string>& names)
	{
		DevicePoolMap::iterator it = _devicePool.begin();
		for (it; it != _devicePool.end(); it++)
		{
			std::string name = it->first;
			names.push_back(name);
		}
	}


}
