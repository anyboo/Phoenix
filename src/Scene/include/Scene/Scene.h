#pragma once

#include "Poco/Foundation.h"


#if defined(_WIN32) && defined(POCO_DLL)
#if defined(SCENE_EXPORTS)
#define SCENE_API __declspec(dllexport)
#else
#define SCENE_API __declspec(dllimport)
#endif
#endif


#if !defined(SCENE_API)
#if !defined(POCO_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
#define SCENE_API __attribute__ ((visibility ("default")))
#else
#define SCENE_API
#endif
#endif


//
// Automatically link Net library.
//
#if defined(_MSC_VER)
#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(SCENE_EXPORTS)
#pragma comment(lib, "Scene" POCO_LIB_SUFFIX)
#endif
#endif


