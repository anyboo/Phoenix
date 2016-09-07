#pragma once

#include "DVR/DVR.h"
#include <string>
#include <vector>
#include <Poco/RefCountedObject.h>

namespace DVR{
	class DVRSession;
	class DVR_API DVRDevice : public Poco::RefCountedObject
	{
	public:
		static const int NumberOfChannel = 4;

		DVRDevice(DVRSession& session);
		~DVRDevice();

		const std::string name() const;
		const std::string address() const;
		size_t channelCount();
		void selectChannel(int index);
		void unselectChannel(int index);
		void selectAllChannel();
		bool isLoggedIn()const;

		DVRSession& session();
	private:
		DVRDevice();
		DVRDevice(const DVRDevice& other);
		DVRDevice& operator = (const DVRDevice& other);

		void InitChannel();

		std::string _name;
		std::string _ipAndport;
		std::vector<bool> _channels;//bool for selected, index from 0 - max

		DVRSession& _MainSession;
	};

	inline size_t DVRDevice::channelCount()
	{
		return _channels.size();
	}

	inline void DVRDevice::selectChannel(int index)
	{
		poco_assert(0 <= index && index < _channels.size());
		_channels[index] = true;
	}

	inline void DVRDevice::unselectChannel(int index)
	{
		poco_assert(0 <= index && index < _channels.size());
		_channels[index] = false;
	}
}
