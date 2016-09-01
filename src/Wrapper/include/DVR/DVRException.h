//
// DVRException.h
//
//
// Library: DVRLite
// Package: DVRLiteCore
// Module:  DVRException
//
// Definition of the DVRException class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#pragma once

#include "DVR/DVR.h"
#include "Poco/Exception.h"


namespace DVR {


POCO_DECLARE_EXCEPTION(DVR_API, DVRException, Poco::IOException)
POCO_DECLARE_EXCEPTION(DVR_API, RowDataMissingException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, UnknownDataBaseException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, UnknownTypeException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, ExecutionException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, BindingException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, ExtractException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, LimitException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, NotSupportedException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, SessionUnavailableException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, SessionPoolExhaustedException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, SessionPoolExistsException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, NoDataException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, LengthExceededException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, ConnectionFailedException, DVRException)
POCO_DECLARE_EXCEPTION(DVR_API, NotConnectedException, DVRException)


}  // namespace DVR


