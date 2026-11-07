#include "../../include/BSSimpleList.h"
// Unit-local header for fallout_shared/bgscamerapath.cpp.
#ifndef FNV_BGSCAMERAPATH_UNIT_H
#define FNV_BGSCAMERAPATH_UNIT_H
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTLargeArray.h"

#include "layout_support.h"
#include "../../include/BGSCameraPath.h"
class TESConditionInit
{
  public:
    void InitItem(TESForm* form);
};
class CameraPathManager
{
  public:
    NiFormArray* GetPathArray();
    void AddCameraPath(BGSCameraPath*);
};
extern CameraPathManager* DAT_011ca700;
BGSCameraPath* __cdecl GetTextureResourcePath();
class FUN_005a71d0
{
  public:
    unsigned int parent, previous;
    void TwoValues_Endian();
};
class ScriptVariableInfo;
class TESTopicInfo;
template <class T> class NiTMallocInterface;
template <class T, class A> class NiTLargeArray;

class CameraFileFormType
{
  public:
    ENUM_FORM_ID GetTESForm();
};
class TESSound;
class CameraCondition
{
  public:
    void Load(TESFile*);
};
#endif
