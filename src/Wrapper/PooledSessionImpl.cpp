//
// PooledSessionImpl.cpp
//
// $Id: //poco/Main/Data/src/PooledSessionImpl.cpp#3 $
//
// Library: Data
// Package: SessionPooling
// Module:  PooledSessionImpl
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "DVR/PooledSessionImpl.h"
#include "DVR/DVRException.h"
#include "DVR/SessionPool.h"


namespace DVR {


PooledSessionImpl::PooledSessionImpl(PooledSessionHolder* pHolder):
	DVRSessionImpl(pHolder->session()->connectionString(),
		pHolder->session()->getLoginTimeout()),
	_pHolder(pHolder, true)
{
}


PooledSessionImpl::~PooledSessionImpl()
{
	try
	{
		logout();
	}
	catch (...)
	{
		poco_unexpected();
	}
}


DVRStatementImpl* PooledSessionImpl::createStatementImpl()
{
	return access()->createStatementImpl();
}


void PooledSessionImpl::list()
{
	return access()->list();
}


void PooledSessionImpl::download()
{
	return access()->download();
}

void PooledSessionImpl::playback()
{
	return access()->playback();
}

void PooledSessionImpl::abort()
{
	return access()->abort();
}

bool PooledSessionImpl::isLoggedIn() const
{
	return access()->isLoggedIn();
}


void PooledSessionImpl::setLoginTimeout(std::size_t timeout)
{
	return access()->setLoginTimeout(timeout);
}


std::size_t PooledSessionImpl::getLoginTimeout() const
{
	return access()->getLoginTimeout();
}

void PooledSessionImpl::reconnect()
{
	return access()->reconnect();
}

void PooledSessionImpl::login(const std::string& user, const std::string& password)
{
	access()->login(user, password);
}


void PooledSessionImpl::logout()
{
	if (_pHolder)
	{
		if (isLoggedIn())
		{
			try
			{
				//rollback();
			}
			catch (...)
			{
				// Something's wrong with the session. Get rid of it.
				access()->logout();
			}
		}
		_pHolder->owner().putBack(_pHolder);
		_pHolder = 0;
	}
}

const std::string& PooledSessionImpl::connectionString() const
{
	return access()->connectionString();
}

const std::string& PooledSessionImpl::connectorName() const
{
	return access()->connectorName();
}


void PooledSessionImpl::setFeature(const std::string& name, bool state)	
{
	access()->setFeature(name, state);
}


bool PooledSessionImpl::getFeature(const std::string& name)
{
	return access()->getFeature(name);
}


void PooledSessionImpl::setProperty(const std::string& name, const Poco::Any& value)
{
	access()->setProperty(name, value);
}


Poco::Any PooledSessionImpl::getProperty(const std::string& name)
{
	return access()->getProperty(name);
}


DVRSessionImpl* PooledSessionImpl::access() const
{
	if (_pHolder)
	{
		_pHolder->access();
		return impl();
	}
	else throw SessionUnavailableException();
}


} 
