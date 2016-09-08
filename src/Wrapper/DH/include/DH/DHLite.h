#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(DHLITE_EXPORTS)
		#define DHLite_API __declspec(dllexport)
	#else
		#define DHLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(DHLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define DHLite_API __attribute__ ((visibility ("default")))
	#else
		#define DHLite_API
	#endif
#endif


//
// Automatically link DHLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(DHLITE_EXPORTS)
		#pragma comment(lib, "DHLite" POCO_LIB_SUFFIX)
	#endif
#endif