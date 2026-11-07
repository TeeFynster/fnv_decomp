// CameraPathManager.h: camera path manager declarations
#ifndef FNV_CAMERA_PATH_MANAGER_H
#define FNV_CAMERA_PATH_MANAGER_H

#include "bgscamerapathmanager_layout_support.h"
#include "../include/BGSCameraPath.h"
#include "../include/CameraShotData.h"
#include "../include/NiFormArray.h"
#include "../include/TESForm.h"

#include "../include/NiTPrimitiveArray.h"
class CameraPathManager
{
  public:
    NiFormArray m_kCameraPathArray;
    NiTPrimitiveArray<BGSCameraPath*> m_kCameraPathList;
    void InitializeCameraPaths();
    static BGSCameraPath* GetTextureResourcePath();
    void UpdateCameraPaths();
    void DestroyCameraPaths();
    TESFile* BGSCameraPathManager_GetCameraPathToPlay(unsigned int arg1, unsigned int arg2);

  protected:
    static BGSCameraPath* ms_pDefaultCameraPath;
};
FNV_STATIC_ASSERT(sizeof(NiFormArray) == 24);
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray<BGSCameraPath*>) == 16);
FNV_STATIC_ASSERT(sizeof(CameraPathManager) == 40);
FNV_STATIC_ASSERT(offsetof(CameraPathManager, m_kCameraPathList) == 24);
#endif
