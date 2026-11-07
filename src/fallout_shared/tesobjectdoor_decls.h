#include "../../include/Interface.h"
// Supporting declarations for fallout_shared/tesobjectdoor_o2_variant.cpp.
#ifndef TESOBJECTDOOR_DECLS_H
#define TESOBJECTDOOR_DECLS_H

#include "../../include/Actor.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSOpenCloseForm.h"
#include "../../include/BSAudio.h"
#include "../../include/BaseProcess.h"
#include "../../include/DoorAccessData.h"
#include "../../include/ExtraLock.h"
#include "../../include/NiPoint3.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/Setting.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/TES.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSound.h"
#include "../../include/BSSimpleList.h"

class NiFixedString;
extern NiFixedString* DAT_011c61dc;
class Script;
class TESGlobal;
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/CHUNK_ID.h"
class TESObjectCELL;
class TESWorldSpace;
class NiNode;
class Animation;
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};
class LockExtraData
{
  public:
    unsigned int level;
    TESBoundObject* key;
    bool IsLocked();
    int GetLockLevel(TESObjectREFR*);
    bool MeetsMinimumLockLevel();
};
class TeleportableReference
{
  public:
    TESObjectCELL* DoorTeleportData_GetTeleportCell();
    TESWorldSpace* GetTeleportWorldspace();
    NiPoint3* GetPosition();
    NiPoint3* GetRotation();
};
class Animation
{
  public:
    void SpecialIdleFree(bool, bool);
};

extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern TESBoundObject* g_pLockpickItem;
extern TESObjectREFR* DAT_011c9350;
extern Setting DAT_011c9384, DAT_011d276c, DAT_011d5110;
extern const float DAT_010162c0;
void TESObjectDOOR_LinkRandomTeleportDoors(TESObjectREFR*, TESObjectREFR*);
void TESIdleManager_SetUsedItem(TESBoundObject*);
void TESIdleManager_SetUsedItemLevel(int);
void TESIdleManager_SetUsedItemActivate(bool);
void Interface_CreateLockPickMenu(TESObjectREFR*, int, int);
void ApplyPerkModifiers(int, Actor*, float*);
int Warning(const char*, ...);
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
#endif
