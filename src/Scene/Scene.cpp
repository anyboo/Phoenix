// Scene.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Scene.h"


// This is an example of an exported variable
SCENE_API int nScene=0;

// This is an example of an exported function.
SCENE_API int fnScene(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Scene.h for the class definition
CScene::CScene()
{
	return;
}
