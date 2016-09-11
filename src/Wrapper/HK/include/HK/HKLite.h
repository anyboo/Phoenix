#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(HKLITE_EXPORTS)
		#define HKLite_API __declspec(dllexport)
	#else
		#define HKLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(HKLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define HKLite_API __attribute__ ((visibility ("default")))
	#else
		#define HKLite_API
	#endif
#endif


//
// Automatically link HKLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(HKLITE_EXPORTS)
		#pragma comment(lib, "HKLite" POCO_LIB_SUFFIX)
	#endif
#endif