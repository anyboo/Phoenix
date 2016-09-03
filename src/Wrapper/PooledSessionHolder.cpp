//
// PooledSessionHolder.cpp
//
// $Id: //poco/Main/Data/src/PooledSessionHolder.cpp#1 $
//
// Library: Data
// Package: SessionPooling
// Module:  PooledSessionHolder
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "DVR/PooledSessionHolder.h"


namespace DVR {


PooledSessionHolder::PooledSessionHolder(SessionPool& rOwner, DVRSessionImpl* pSessionImpl):
	_owner(rOwner),
	_pImpl(pSessionImpl, true)
{
}


PooledSessionHolder::~PooledSessionHolder()
{
}


}
