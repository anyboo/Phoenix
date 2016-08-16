// Wrapper.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Wrapper.h"


// This is an example of an exported variable
WRAPPER_API int nWrapper=0;

// This is an example of an exported function.
WRAPPER_API int fnWrapper(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Wrapper.h for the class definition
CWrapper::CWrapper()
{
	return;
}
