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

	void DVRDeviceContainer::add(DVRDevice* device)
	{
		poco_check_ptr(device);

		FastMutex::ScopedLock lock(_mutex);

		if (_devicePool.find(device->name()) != _devicePool.end())
			throw DevicePoolExistsException("device already exists" + device->name());

		device->duplicate();
		_devicePool.insert(DevicePoolMap::value_type(device->name(), device));

	}

	DVRDevice& DVRDeviceContainer::get(const std::string& name)
	{
		poco_assert(name.empty());

		FastMutex::ScopedLock lock(_mutex);
		DevicePoolMap::iterator it = _devicePool.find(name);
		if (_devicePool.end() == it) throw Poco::NotFoundException(name);
		return *it->second;
	}

}
