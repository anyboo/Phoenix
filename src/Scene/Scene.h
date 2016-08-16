// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SCENE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SCENE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SCENE_EXPORTS
#define SCENE_API __declspec(dllexport)
#else
#define SCENE_API __declspec(dllimport)
#endif

// This class is exported from the Scene.dll
class SCENE_API CScene {
public:
	CScene(void);
	// TODO: add your methods here.
};

extern SCENE_API int nScene;

SCENE_API int fnScene(void);
