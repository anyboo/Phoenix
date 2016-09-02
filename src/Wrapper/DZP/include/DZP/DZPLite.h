#pragma once

#include <Poco/Foundation.h>

#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(DZPLITE_EXPORTS)
		#define DZPLite_API __declspec(dllexport)
	#else
		#define DZPLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(DZPLite_API)
	#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define DZPLite_API __attribute__ ((visibility ("default")))
	#else
		#define DZPLite_API
	#endif
#endif


//
// Automatically link DZPLite library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(DZPLITE_EXPORTS)
		#pragma comment(lib, "DVRDZPLite" POCO_LIB_SUFFIX)
	#endif
#endif