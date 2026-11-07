// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESIDLEFORM_H
#define FNV_TESIDLEFORM_H

class TESConditionItem;
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "PerkEntryConditionSet.h"
#include "../../include/TESForm.h"
#include "layout_support.h"
class BSFileEntry;
class IdleAnimationData;
class NiFormArray;
class TESIdleForm;
class TESObjectREFR;
class IdleReplayDelayEntry;
class TESModel;
class TESModelAnim;
class FileEntryList;
template <class T> class BSSimpleList;
class TESTopic;
#include "../../include/TESTopicInfo.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelAnim.h"
#include "../../include/TESIdleForm.h"
class BGSPerkEntry;
class BGSCameraShot;
#include "../../include/TESObjectANIO.h"
#include "../../include/NiFormArray.h"
class BGSTextureSet;
#include "../../include/BGSImpactData.h"
int __cdecl Warning(const char*, ...);
// TESFileFormInt_tesidleform: local type (was include/TESFileFormInt.h, which had no evidence of one real class); its methods are 0x00472660 TESFile::GetTESForm
class TESFileFormInt_tesidleform
{
public:
    int GetTESForm();
};
class FUN_005a71d0
{
  public:
    unsigned int parent;
    unsigned int previous;
    void TwoValues_Endian();
};
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);
#include "../../include/TESDataHandler.h"
class IdleAnimationManager
{
  public:
    void AddIdleToArray(TESIdleForm*);
    bool InterfaceManager_GetMagicPageNumber();
    NiFormArray* GetIdleArray(TESForm*);
    NiFormArray* GetFormArray(TESIdleForm*);
};
extern TESDataHandler* g_dataHandler;
extern IdleAnimationManager* DAT_011cb6a0;
#endif
