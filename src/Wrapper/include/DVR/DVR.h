#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(DVRLITE_EXPORTS)
		#define DVR_API __declspec(dllexport)
	#else
		#define DVR_API __declspec(dllimport)
	#endif
#endif


#if !defined(DVR_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define DVR_API __attribute__ ((visibility ("default")))
	#else
		#define DVR_API
	#endif
#endif


//
// Automatically link DZPLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(DVRLITE_EXPORTS)
		#pragma comment(lib, "DVRLite" POCO_LIB_SUFFIX)
	#endif
#endif