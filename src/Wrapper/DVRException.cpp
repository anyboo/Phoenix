//
// DVRException.cpp
//
//
// Library: DVRLite
// Package: DVRLiteCore
// Module:  DVRException
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "DVR/DVRException.h"
#include <typeinfo>


namespace DVR {


POCO_IMPLEMENT_EXCEPTION(DVRException, Poco::IOException, "Database Exception")
POCO_IMPLEMENT_EXCEPTION(RowDataMissingException, DVRException, "Data for row missing")
POCO_IMPLEMENT_EXCEPTION(UnknownDataBaseException, DVRException, "Type of data base unknown")
POCO_IMPLEMENT_EXCEPTION(UnknownTypeException, DVRException, "Type of data unknown")
POCO_IMPLEMENT_EXCEPTION(ExecutionException, DVRException, "Execution error")
POCO_IMPLEMENT_EXCEPTION(BindingException, DVRException, "Binding error")
POCO_IMPLEMENT_EXCEPTION(ExtractException, DVRException, "Extraction error")
POCO_IMPLEMENT_EXCEPTION(LimitException, DVRException, "Limit error")
POCO_IMPLEMENT_EXCEPTION(NotSupportedException, DVRException, "Feature or property not supported")
POCO_IMPLEMENT_EXCEPTION(SessionUnavailableException, DVRException, "Session is unavailable")
POCO_IMPLEMENT_EXCEPTION(SessionPoolExhaustedException, DVRException, "No more sessions available from the session pool")
POCO_IMPLEMENT_EXCEPTION(SessionPoolExistsException, DVRException, "Session already exists in the pool")
POCO_IMPLEMENT_EXCEPTION(NoDataException, DVRException, "No data found")
POCO_IMPLEMENT_EXCEPTION(LengthExceededException, DVRException, "Data too long")
POCO_IMPLEMENT_EXCEPTION(ConnectionFailedException, DVRException, "Connection attempt failed")
POCO_IMPLEMENT_EXCEPTION(NotConnectedException, DVRException, "Not connected to data source")


} // namespace DVR
