#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(ZWLITE_EXPORTS)
		#define ZWLite_API __declspec(dllexport)
	#else
		#define ZWLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(ZWLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define ZWLite_API __attribute__ ((visibility ("default")))
	#else
		#define ZWLite_API
	#endif
#endif


//
// Automatically link ZWLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(ZWLITE_EXPORTS)
		#pragma comment(lib, "ZWLite" POCO_LIB_SUFFIX)
	#endif
#endif