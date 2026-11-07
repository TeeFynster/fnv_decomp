#include "../../include/SettingT.h"

// src/staging/blk_00960000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/NiTMallocInterface.h"
#include <stddef.h>
#include "../../include/SETTING_VALUE.h"
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
#pragma intrinsic(memcpy)
#include "../../include/NiTPointerMap.h"
class GameSettingCollection;
struct _RTL_CRITICAL_SECTION;
// Avoid collision with MSVC's generated constructor closure name.
#define __local_vftable_ctor_closure DeclaredVftableCtorClosure
#include "../../include/BSSimpleList.h"

#include "../../include/Actor.h"
#include "../../include/ActorCombatGroup.h"
// BSSpinLockUnlock_blk_00960000_od: local type (was include/BSSpinLockUnlock.h, which had no evidence of one real class); its methods are 0x0040fba0 BSSpinLock::Unlock, 0x0040fbf0 BSSpinLock::Lock
class BSSpinLockUnlock_blk_00960000_od
{
public:
    void Lock(const char*);
    void Unlock();
};
#include "../../include/CombatActor.h"
#include "../../include/BGSPerk.h"
#include "../../include/BGSQuestObjective.h"
#include "../../include/BaseProcess.h"
#include "../../include/CombatTargetTimestamp.h"
#include "../../include/ImageSpaceModifierInstanceDOF.h"
#include "../../include/ImageSpaceModifierInstanceDRB.h"
#include "../../include/MemoryManager.h"
#include "../../include/StartMenu.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESRace.h"
#include "../../include/TopicInfoArray.h"

#include "../../include/CombatAction.h"
#include "../../include/CombatWorldStateListNode.h"
#include "../../include/CombatActionAttackRangedExplosive.h"
#include "../../include/GO.h"
#include "../../include/StrArr.h"
#include "../../include/TES.h"
#include "../../include/NiPoint3.h"
#include "../../include/TESForm.h"
#include "../../include/OSGlobals.h"
#include "../../include/BSScrapArray.h"
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/NiAVObject.h"
#include "../../include/TESSound.h"
#include "../../include/TESPackage.h"
#include "../../include/CombatController.h"
#include "../../include/NiPoint3.h"
#undef __local_vftable_ctor_closure

struct FUN_00961260_Class
{
    unsigned int GetFieldAt608();
};

// @fnv 0x00961260
unsigned int FUN_00961260_Class::GetFieldAt608()
{
    return *(unsigned int*)((char*)this + 0x608);
}

struct FUN_00961f30_Class
{
    void SetByteAt54(unsigned char value);
};

// @fnv 0x00961f30
void FUN_00961f30_Class::SetByteAt54(unsigned char value)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x54) = value;
}

// Unit-only accessors missing from OSGlobals.h; all storage comes from the shared OSGlobals layout.
struct OSGlobalFlagAccess : OSGlobals
{
    bool IsFlycam();
    void SetByteAtOffset6(unsigned char value);
    void SetByteAtOffset7(unsigned char value);
};

// @fnv 0x00961f50
void OSGlobalFlagAccess::SetByteAtOffset7(unsigned char value)
{
    layoutPadding7 = value;
}

// @fnv 0x00961f70
void OSGlobalFlagAccess::SetByteAtOffset6(unsigned char param)
{
    *reinterpret_cast<unsigned char*>(&isFlycam) = param;
}

struct FUN_009627f0_Class
{
    void PlayerCharacter_ResetInsufficientChargeMessage();
};
// @fnv 0x009627f0
// src: XBOX_PDB 0x009627f0
void FUN_009627f0_Class::PlayerCharacter_ResetInsufficientChargeMessage()
{
    *reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x86c) = 0;
}

struct FUN_00962cb0_Class
{
    void SetByteAtOffset49(unsigned char param);
};

// @fnv 0x00962cb0
void FUN_00962cb0_Class::SetByteAtOffset49(unsigned char param)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x31) = param;
}

struct FUN_00966a00_Class
{
    void Projectile_SetSpeedMult(float value);
};

// @fnv 0x00966a00
// src: XBOX_PDB 0x00966a00
void FUN_00966a00_Class::Projectile_SetSpeedMult(float value)
{
    *(float*)((char*)this + 0xd0) = value;
}

struct FUN_00966a50_Class
{
    int PlayerCharacter_GetNumNotes();
};

// @fnv 0x00966a50
// src: COMMUNITY 0x00966a50
int FUN_00966a50_Class::PlayerCharacter_GetNumNotes()
{
    return reinterpret_cast<BSSimpleList<TESRace*>*>(reinterpret_cast<char*>(this) + 0x5e4)->ItemsInList();
}

struct CombatGroupMemberArray
{
    Member** BSSimpleArray_CombatTarget_1024_GetAt(int);
};


// @fnv 0x00968630
// src: XBOX_PDB 0x00968630
Member* __thiscall ActorCombatGroup::CombatGroup_GetTarget(int a)
{
    return *((CombatGroupMemberArray*)((char*)this + 8))->BSSimpleArray_CombatTarget_1024_GetAt(a);
}

struct Arr
{
    unsigned int GetSize();
};

struct FUN_00968650_Class
{
    unsigned int CombatManager_GetCombatGroupCount();
};

// @fnv 0x00968650
// src: XBOX_PDB 0x00968650
unsigned int FUN_00968650_Class::CombatManager_GetCombatGroupCount()
{
    return ((Arr*)this)->GetSize();
}

TESForm* __cdecl GetFormByID(int);

// @fnv 0x00969910
// src: COMMUNITY 0x00969910
TESForm* __thiscall TESRace::AudioMarker_GetMediaLocationController()
{
    return GetFormByID(*(int*)((char*)this + 0x24));
}

extern "C" void* __cdecl DAT_0108b474;
struct FUN_0096a280_class
{
    void* m_ppVirtualMethodTable;
    void __thiscall Init(void* p);
    void* __thiscall NiTMap_unsigned_int_unsigned_char_NiTMap(void* p);
};
// @fnv 0x0096a280
// src: EXE 0x0096a280
void* __thiscall FUN_0096a280_class::NiTMap_unsigned_int_unsigned_char_NiTMap(void* p)
{
    Init(p);
    m_ppVirtualMethodTable = &DAT_0108b474;
    return this;
}

struct FUN_0096a350_class
{
    unsigned int GetShortAtOffset4();
};

// @fnv 0x0096a350
unsigned int FUN_0096a350_class::GetShortAtOffset4()
{
    return *(unsigned short*)((char*)this + 4);
}

struct FUN_0096a370_Class
{
    void* __thiscall GetElementAddress_0096a370(int index);
};

// @fnv 0x0096a370
// src: GUESS 0x0096a370 (confidence: low)
void* __thiscall FUN_0096a370_Class::GetElementAddress_0096a370(int index)
{
    return reinterpret_cast<char*>(*reinterpret_cast<int**>(this)) + index * 0x30;
}

struct Unk6b
{
    void FreeMemory(void*);
};

struct FUN_0096a540_class
{
    void ReleaseStorage_0096a540(void* arg);
};

// Clears the byte at offset 8 of arg, then calls FreeMemory on the object at this+0xc with arg.
// @fnv 0x0096a540
// src: GUESS 0x0096a540 (confidence: medium)
void FUN_0096a540_class::ReleaseStorage_0096a540(void* arg)
{
    *(unsigned char*)((char*)arg + 8) = 0;
    ((Unk6b*)((char*)this + 0xc))->FreeMemory(arg);
}

extern "C" void* DAT_0108b4b4;
struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};
struct FUN_0096a570_Class
{
    void* vtable;
    AX* BSSimpleArray_ItemChange_1024_BSSimpleArray();
};
// Sets the vtable to DAT_0108b4b4, calls FUN_006b3eb0 with 0, 0 on this, and returns this as an AX pointer.
// @fnv 0x0096a570
// src: EXE 0x0096a570
AX* FUN_0096a570_Class::BSSimpleArray_ItemChange_1024_BSSimpleArray()
{
    vtable = &DAT_0108b4b4;
    reinterpret_cast<AX*>(this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return reinterpret_cast<AX*>(this);
}

namespace fnv_0096a5a0 {
extern int DAT_0108b4b4;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool);
    void ResetVirtualTableAndClear_0096a5a0();
};

// @fnv 0x0096a5a0
// src: GUESS 0x0096a5a0 (confidence: medium)
void GlobalObject_00869f00::ResetVirtualTableAndClear_0096a5a0()
{
    p = &DAT_0108b4b4;
    Clear(true);
}
}  // namespace fnv_0096a5a0

namespace fnv_0096a5c0 {
extern void* DAT_0108b4c8;

struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
};

struct FUN_0096a5c0 : AX
{
    void* vtable;
    FUN_0096a5c0();
};

// Sets the vtable pointer to DAT_0108b4c8 and calls FUN_006b3eb0 with 0, 0.
// @fnv 0x0096a5c0
FUN_0096a5c0::FUN_0096a5c0()
{
    vtable = &DAT_0108b4c8;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
}
}  // namespace fnv_0096a5c0

extern int DAT_0108b4c8;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool);
    void SetVtableAndProcessState_0096a5f0();
};

// @fnv 0x0096a5f0
// src: GUESS 0x0096a5f0 (confidence: low)
void GlobalObject_00869f00::SetVtableAndProcessState_0096a5f0()
{
    *(int*)this = (int)&DAT_0108b4c8;
    Clear(true);
}

extern int DAT_0108b4dc;

struct FUN_0096a640_Class
{
    void __thiscall Initialize(int a, int b);
    int __thiscall InitVtable(int a, int b);
};

// Calls Initialize with the two arguments, then stores the address of DAT_0108b4dc into this and returns this.
// @fnv 0x0096a640
int __thiscall FUN_0096a640_Class::InitVtable(int a, int b)
{
    Initialize(a, b);
    *(int**)this = &DAT_0108b4dc;
    return (int)this;
}

struct FUN_0096a730_class
{
    void __thiscall SetVtableAndProcessState_0096a750();
    void __thiscall ForwardCall_0096a730();
};

// @fnv 0x0096a730
// src: GUESS 0x0096a730 (confidence: low)
void __thiscall FUN_0096a730_class::ForwardCall_0096a730()
{
    SetVtableAndProcessState_0096a750();
}

struct FUN_0096a930_class
{
    void ReleaseStorage_0096ad00();
    void ForwardCall_0096a930();
};

// @fnv 0x0096a930
// src: GUESS 0x0096a930 (confidence: low)
void FUN_0096a930_class::ForwardCall_0096a930()
{
    ReleaseStorage_0096ad00();
}

namespace fnv_0096a950 {
struct FUN_0096a930_class
{
    void ForwardCall_0096a930();
    void ForwardCall_0096a950();
};

// @fnv 0x0096a950
// src: GUESS 0x0096a950 (confidence: low)
void FUN_0096a930_class::ForwardCall_0096a950()
{
    ForwardCall_0096a930();
}
}  // namespace fnv_0096a950

extern int DAT_0108c0d0;

struct FUN_0096afe0_base
{
    void __thiscall FUN_0096afe0(int, int);
};

struct FUN_0096af30 : public FUN_0096afe0_base
{
    FUN_0096af30* __thiscall init(int a, int b);
};

// Calls the base initializer with a and b, stores the address of DAT_0108c0d0 in this, and returns this.
// @fnv 0x0096af30
FUN_0096af30* __thiscall FUN_0096af30::init(int aiArg1, int aiArg2)
{
    FUN_0096afe0(aiArg1, aiArg2);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0108c0d0);
    return this;
}

void* __cdecl _NiMalloc(unsigned int);

// @fnv 0x0096afc0
template <>
ActorCombatGroup** NiTMallocInterface<ActorCombatGroup*>::Allocate(unsigned int a)
{
    return static_cast<ActorCombatGroup**>(_NiMalloc(a << 2));
}

struct FUN_00977770_Class
{
    void ProcessLists_SendGrenadeMineAlert(float a, float b);
};

// Initializes three local variables to zero, zero and FLT_MAX; the values are unused.
// @fnv 0x00977770
// src: XBOX_PDB 0x00977770
void FUN_00977770_Class::ProcessLists_SendGrenadeMineAlert(float afValueA, float afValueB)
{
    int v3 = 0;
    int v1 = 0;
    float v2 = 3.402823466e+38F;
    (void)v1;
    (void)v2;
    (void)v3;
}

struct FUN_00977c70_class
{
    float GetField43C();
};

// @fnv 0x00977c70
float FUN_00977c70_class::GetField43C()
{
    return *(float*)((char*)this + 0x43c);
}

struct FUN_00977c90_class
{
    void HighProcess_SetRadiationLevel(float value);
};

// @fnv 0x00977c90
// src: XBOX_PDB 0x00977c90
void FUN_00977c90_class::HighProcess_SetRadiationLevel(float value)
{
    *(float*)((char*)this + 0x440) = value;
}

namespace fnv_00978a60 {
extern int DAT_0108c23c;

struct GlobalObject_00869f00
{
    int* data;
    void Clear(bool flag);
    void ResetToGlobalData();
};

// @fnv 0x00978a60
void GlobalObject_00869f00::ResetToGlobalData()
{
    data = &DAT_0108c23c;
    Clear(true);
}
}  // namespace fnv_00978a60

namespace fnv_00978cd0 {
extern int DAT_0108c278;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_00978cd0_Class
{
    void SetVtableAndProcessState_00978cd0();
};

// @fnv 0x00978cd0
// src: GUESS 0x00978cd0 (confidence: low)
void __thiscall FUN_00978cd0_Class::SetVtableAndProcessState_00978cd0()
{
    *(int**)this = (int*)&DAT_0108c278;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00978cd0

extern int DAT_0108c278;
struct Dummy_0061bf20
{
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(int, int);
    Dummy_0061bf20* InitializeFields_00978ea0();
};
// @fnv 0x00978ea0
// src: GUESS 0x00978ea0 (confidence: low)
Dummy_0061bf20* Dummy_0061bf20::InitializeFields_00978ea0()
{
    *(int*)this = (int)&DAT_0108c278;
    BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(0, 0);
    return this;
}

struct FUN_0097f220_t
{
    void CombatTimer_ForceTrigger();
};

// @fnv 0x0097f200
// src: XBOX_PDB 0x0097f200
void CombatController::ForcePlanUpdate()
{
    ((FUN_0097f220_t*)((char*)this + 0xb4))->CombatTimer_ForceTrigger();
}

struct FUN_0097f220_Class
{
    int m_iWordAt00;
    float m_iWordAt04;
    void CombatTimer_ForceTrigger();
};

// @fnv 0x0097f220
// src: XBOX_PDB 0x0097f220
void FUN_0097f220_Class::CombatTimer_ForceTrigger()
{
    m_iWordAt04 = -1.0f;
}

extern "C" void* DAT_0108b494;
extern "C" void* NiFreeAlias(void*);

struct FUN_0096a510_Class
{
    void* m_vtbl;
    void* m_p;
    void* m_q;
    void __thiscall UpdateState_0096a510();
};

// Resets the vtable pointer, clears the pointer map contents, and frees m_q.
// @fnv 0x0096a510
// src: GUESS 0x0096a510 (confidence: low)
void __thiscall FUN_0096a510_Class::UpdateState_0096a510()
{
    m_vtbl = &DAT_0108b494;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(m_q);
}

struct T_
{
    void __thiscall SetValue(void*);
};
// 0x004ae750 is a nullable wrapper around 0x00620b80; ScriptLocals::GetLocalData is 0x00541c80.
struct NullableObjectDataAccess
{
    void* __thiscall GetObjectData();
};
struct FUN_00961200_Class
{
    void __thiscall ApplyToScriptLocals(void* a);
};
// Gets the script locals object from this and, if present, calls FUN_004a3f10 on a with the locals at offset 0x30.
// @fnv 0x00961200
void __thiscall FUN_00961200_Class::ApplyToScriptLocals(void* pTarget)
{
    void* p = ((NullableObjectDataAccess*)this)->GetObjectData();
    if (p)
        ((T_*)pTarget)->SetValue((char*)p + 0x30);
}

namespace fnv_00961230 {
struct T_
{
    void __thiscall SetValue(void*);
};
// 0x004ae750 is a nullable wrapper around 0x00620b80; ScriptLocals::GetLocalData is 0x00541c80.
struct NullableObjectDataAccess
{
    void* __thiscall GetObjectData();
};
struct FUN_00961230_Class
{
    void __thiscall bhkMouseSpringAction_GetPositionInRbLocal(T_* param);
};
// @fnv 0x00961230
// src: COMMUNITY 0x00961230
void __thiscall FUN_00961230_Class::bhkMouseSpringAction_GetPositionInRbLocal(T_* pTarget)
{
    void* result = ((NullableObjectDataAccess*)this)->GetObjectData();
    if (result)
        pTarget->SetValue((char*)result + 0x20);
}
}  // namespace fnv_00961230

struct FUN_00962490_Class
{
    void PlayerCharacter_SetLightPointer(void* p, unsigned char flag);
};
// @fnv 0x00962490
// src: COMMUNITY 0x00962490
void FUN_00962490_Class::PlayerCharacter_SetLightPointer(void* p, unsigned char flag)
{
    if (flag)
        *(GO*)((char*)this + 0x864) = p;
    else
        *(GO*)((char*)this + 0x868) = p;
}



extern StartMenu g_011d3048;
extern float _DAT_010162c0;
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
struct FUN_009627a0_Class
{
    void ShowStartMenuMessageOnce();
};
// If the byte at offset 0x86c is clear, sets it to 1 and queues a UI message using the start menu's string and _DAT_010162c0.
// @fnv 0x009627a0
void FUN_009627a0_Class::ShowStartMenuMessageOnce()
{
    if (!(*((unsigned char*)this + 0x86c)))
    {
        *((char*)this + 0x86c) = 1;
        QueueUIMessage(((const StartMenu*)&g_011d3048)->GetMenuTitle(), 0, 0, 0, _DAT_010162c0, false);
    }
}


struct FUN_0056aac0_map
{
    void SetAt(TESObjectREFR*, bool);
};
struct FUN_00962850_Class
{
    void __thiscall PlayerCharacter_SetLastSpaceForDoor(TESSound* sound, bool flag);
};
// If sound is non-null, inserts the reference returned by sound->Deallocate() into the map at this+0x854 with the given flag.
// @fnv 0x00962850
// src: COMMUNITY 0x00962850
void __thiscall FUN_00962850_Class::PlayerCharacter_SetLastSpaceForDoor(TESSound* sound, bool flag)
{
    if (sound)
        ((FUN_0056aac0_map*)((char*)this + 0x854))->SetAt((TESObjectREFR*)sound->Deallocate(), flag);
}

struct IntegerPairPointerRecord
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
};
struct PlayerActionObjectList
{
    IntegerPairPointerRecord* item;
    PlayerActionObjectList* next;
    PlayerActionObjectList* __thiscall ref_006815c0();
};
struct FUN_009640b0_Class
{
    int m_60c;
    unsigned int PlayerCharacter_GetRecentAction();
};
// @fnv 0x009640b0
// src: COMMUNITY 0x009640b0
unsigned int FUN_009640b0_Class::PlayerCharacter_GetRecentAction()
{
    unsigned int result = 0;
    if (*(void**)((char*)this + 0x60c))
    {
        if (((PlayerActionObjectList*)*(void**)((char*)this + 0x60c))->ref_006815c0()->item)
        {
            result = (unsigned int)((PlayerActionObjectList*)*(void**)((char*)this + 0x60c))->ref_006815c0()->item->m_8;
        }
    }
    return result;
}

extern "C" unsigned char DAT_011f9423;

// @fnv 0x00965240
// src: COMMUNITY 0x00965240
void BSShaderManager_SetFullScreenMotionBlurIronSights(unsigned char value)
{
    DAT_011f9423 = value;
}

void __cdecl Deallocate(void*);
struct FUN_0096a300_Class
{
    void __thiscall FUN_0096a4b0();
    void* __thiscall FUN_0096a300(unsigned int flags);
};
// Calls FUN_0096a4b0, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0096a300
void* __thiscall FUN_0096a300_Class::FUN_0096a300(unsigned int flags)
{
    FUN_0096a4b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void* dst, int c, unsigned int n);
struct FUN_0096a390_Class
{
    void* m_vtbl;
    unsigned int m_p;
    void* m_q;
    unsigned int m_r;
    void* __thiscall Init(unsigned int n);
};
// Sets the vtable, stores n in m_p, allocates m_p*4 bytes into m_q, zeroes that buffer, and returns this.
// @fnv 0x0096a390
void* __thiscall FUN_0096a390_Class::Init(unsigned int auiCount)
{
    m_vtbl = &DAT_0108b494;
    m_p = auiCount;
    m_r = 0;
    unsigned int size = m_p << 2;
    m_q = _NiMalloc(size);
    memset(m_q, 0, m_p << 2);
    return (void*)this;
}

void __cdecl Deallocate(void* p);

struct FUN_0096a5a0_Class
{
    void ResetVirtualTableAndClear_0096a5a0();
    void* __thiscall FUN_0096a6a0(unsigned int flags);
};

// @fnv 0x0096a6a0
void* FUN_0096a5a0_Class::FUN_0096a6a0(unsigned int flags)
{
    ResetVirtualTableAndClear_0096a5a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void* p);

struct FUN_0096a730_Class
{
    void ForwardCall_0096a730();
    void* __thiscall FUN_0096a700(unsigned int flags);
};

// Calls FUN_0096a730, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0096a700
void* __thiscall FUN_0096a730_Class::FUN_0096a700(unsigned int flags)
{
    ForwardCall_0096a730();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0096ac30_Class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;
    int m_iWordAt04;
    int m_5;
    int m_6;
    int m_7;
    int m_8;
    int m_9;
    int m_10;
    int m_11;
    int m_12;
    int m_13;
    int m_14;
    int m_15;
    void __thiscall ProcessArray_CheckNextUpdateBounds();
};

// For each of four slots, resets the value at offset 0x30 to the lower bound at 0x10 when it is below that bound or at/above the upper bound at 0x20.
// @fnv 0x0096ac30
// src: COMMUNITY 0x0096ac30
void __thiscall FUN_0096ac30_Class::ProcessArray_CheckNextUpdateBounds()
{
    for (int i = 0; i < 4; i++)
    {
        if (*(unsigned int*)((char*)this + 0x30 + i * 4) < *(unsigned int*)((char*)this + 0x10 + i * 4) ||
            *(unsigned int*)((char*)this + 0x30 + i * 4) >= *(unsigned int*)((char*)this + 0x20 + i * 4))
            *(int*)((char*)this + 0x30 + i * 4) = *(int*)((char*)this + 0x10 + i * 4);
    }
}

extern "C" void* DAT_0108c250;
struct FUN_008c1cb0
{
    virtual ~FUN_008c1cb0();
};
struct FUN_00978b60 : public FUN_008c1cb0
{
    void* p;
    void Clear(bool);
    ~FUN_00978b60();
};
// @fnv 0x00978b60
FUN_00978b60::~FUN_00978b60()
{
    Clear(true);
}

extern unsigned int DAT_010a2720;
struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
};
struct FUN_00978d50_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    ScrapHeapBuffer* m_10;
    void* BSScrapArray_NavMeshSearchLink_1024_Allocate(unsigned int a);
};
// Allocates a block of a * 0xc bytes through m_10 and returns the pointer.
// @fnv 0x00978d50
// src: COMMUNITY 0x00978d50
void* FUN_00978d50_Class::BSScrapArray_NavMeshSearchLink_1024_Allocate(unsigned int a)
{
    void* p = m_10->Allocate(a * 0xc, DAT_010a2720);
    return p;
}

void __cdecl operator delete(void*);
void ResetToGlobalData();
struct FUN_00978d80_Class
{
    void ResetToGlobalData();
    void* FUN_00978d80(unsigned int flags);
};
// Calls ResetToGlobalData, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00978d80
void* FUN_00978d80_Class::FUN_00978d80(unsigned int flags)
{
    ResetToGlobalData();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00978de0_Class
{
    void __thiscall FUN_00978b60();
    void* __thiscall FUN_00978de0(unsigned int flags);
};

// Calls FUN_00978b60, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00978de0
void* __thiscall FUN_00978de0_Class::FUN_00978de0(unsigned int flags)
{
    FUN_00978b60();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_00978cd0_Class
{
    void __thiscall SetVtableAndProcessState_00978cd0();
};

struct FUN_00978e10_Class
{
    void* __thiscall FUN_00978e10(unsigned int flags);
};

// @fnv 0x00978e10
void* __thiscall FUN_00978e10_Class::FUN_00978e10(unsigned int flags)
{
    ((FUN_00978cd0_Class*)this)->SetVtableAndProcessState_00978cd0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_00978cf0_Class
{
    void __thiscall FUN_00978cf0();
};
struct FUN_00978e40_Class
{
    void* __thiscall FUN_00978e40(unsigned int flags);
};
// @fnv 0x00978e40
void* __thiscall FUN_00978e40_Class::FUN_00978e40(unsigned int flags)
{
    ((FUN_00978cf0_Class*)this)->FUN_00978cf0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00978f40_Class
{
    void __thiscall FUN_00978f70();
    void* __thiscall FUN_00978f40(unsigned int flags);
};
// Calls FUN_00978f70, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00978f40
void* __thiscall FUN_00978f40_Class::FUN_00978f40(unsigned int flags)
{
    FUN_00978f70();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl memset(void* dest, int value, unsigned int count);

struct RegionObjectEntry
{
    int* GetReference();
};
struct Flt
{
    operator unsigned int();
};
extern BSSimpleList<CombatAction*>* DAT_011f13d0;
extern CombatAction* DAT_011f1420[27];

// @fnv 0x0097a990
void InitCombatActions()
{
    memset(&DAT_011f13d0, 0, 0x50);
    for (unsigned int i = 0; i < 27; ++i)
    {
        CombatAction* action = CombatAction::CreateAction(i);
        DAT_011f1420[i] = action;
        if (action)
        {
            CombatWorldStateListNode* entry = reinterpret_cast<CombatWorldStateListNode*>(
                reinterpret_cast<BGSQuestObjective*>(action)->GetTargetList());
            while (entry && *reinterpret_cast<RegionObjectEntry*>(entry)->GetReference())
            {
                int ref = *reinterpret_cast<RegionObjectEntry*>(entry)->GetReference();
                CombatActionAttackRangedExplosive::Execute(reinterpret_cast<Flt*>(ref)->operator unsigned int(),
                                                           action);
                entry = entry->GetNext();
            }
        }
    }
}

void __cdecl Deallocate(void*);
struct FUN_00979c80_Class
{
    void __thiscall FUN_00979c80();
};
struct FUN_0097ab00_Class
{
    void* __thiscall FUN_0097ab00(unsigned int flags);
};
// Calls FUN_00979c80 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0097ab00
void* __thiscall FUN_0097ab00_Class::FUN_0097ab00(unsigned int flags)
{
    ((FUN_00979c80_Class*)this)->FUN_00979c80();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_0108b4e4;
struct FUN_0096a7b0_Class
{
    void* m_vtbl;
    ActorCombatGroup** m_p;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    unsigned short m_iThirdValue;
    unsigned short m_iFourthElementInteger;
    void* __thiscall Initialize(unsigned short a, unsigned short b);
};
// @fnv 0x0096a7b0
void* __thiscall FUN_0096a7b0_Class::Initialize(unsigned short ausCapacity, unsigned short b)
{
    m_vtbl = &DAT_0108b4e4;
    m_kPointA = ausCapacity;
    m_iFourthElementInteger = b;
    m_kPointB = 0;
    m_iThirdValue = 0;
    if (m_kPointA > 0)
        m_p = NiTMallocInterface<ActorCombatGroup*>::Allocate(m_kPointA);
    else
        m_p = 0;
    return this;
}

struct FUN_00964060_Class
{
    int m_60c;
    int GetActionObjectItemId();
};

// @fnv 0x00964060
int FUN_00964060_Class::GetActionObjectItemId()
{
    int result = 0;
    if (*(int*)((char*)this + 0x60c))
    {
        if (((PlayerActionObjectList*)*(int*)((char*)this + 0x60c))->ref_006815c0()->item)
            result = ((PlayerActionObjectList*)*(int*)((char*)this + 0x60c))->ref_006815c0()->item->m_iWordAt00;
    }
    return result;
}

struct Arr2
{
    unsigned int* GetAt(int);
};
struct FUN_0096aa40_Class : public FUN_0096ac30_Class
{
    int FindRangeIndex(int);
    void ProcessArray_RemoveActor(int param_2);
};

// @fnv 0x0096aa40
// src: XBOX_PDB 0x0096aa40
void FUN_0096aa40_Class::ProcessArray_RemoveActor(int aiIndex)
{
    int local2 = FindRangeIndex(aiIndex);
    if (local2 == -1)
        return;
    if (*(unsigned int*)((char*)this + 0x20 + local2 * 4) > *(unsigned int*)((char*)this + 0x10 + local2 * 4))
        *(int*)((char*)this + 0x20 + local2 * 4) = *(int*)((char*)this + 0x20 + local2 * 4) - 1;
    if (aiIndex != *(int*)((char*)this + 0x20 + local2 * 4))
        ((StrArr*)this)
            ->SetAt(aiIndex, *(char**)((Arr2*)this)->GetAt(*(unsigned int*)((char*)this + 0x20 + local2 * 4)));
    int local_c2 = 0;
    ((StrArr*)this)->SetAt(*(unsigned int*)((char*)this + 0x20 + local2 * 4), (char*&)local_c2);
    ProcessArray_CheckNextUpdateBounds();
}


extern "C" void* DAT_0108c0c8;
struct FUN_0096afe0
{
    void* vtbl;
    ActorCombatGroup** m;
    unsigned short a;
    unsigned short b;
    unsigned short d;
    unsigned short c;
    FUN_0096afe0(unsigned short x, unsigned short y);
};
// Sets the vtable, stores x and y, zeroes b and d, and allocates an array of a elements into m (or null when a is 0).
// @fnv 0x0096afe0
FUN_0096afe0::FUN_0096afe0(unsigned short x, unsigned short y)
{
    vtbl = &DAT_0108c0c8;
    a = x;
    c = y;
    b = 0;
    d = 0;
    if (a > 0)
        m = NiTMallocInterface<ActorCombatGroup*>::Allocate(a);
    else
        m = 0;
}

struct XActor
{
    char pad[0xcc];
    float m_cc;
    float m_d0;
    void* __thiscall GetActorBase();
};

float __fastcall GetFloatAtOffset68(char const*);
float __cdecl BlendWithSetting(float, float, float);

struct FUN_009669c0_Class
{
    char pad[0xcc];
    float m_cc;
    float m_d0;
    float Projectile_GetSpeed();
};

// Calls BlendWithSetting with the result of GetFloatAtOffset68 on the actor base pointer and the m_cc and m_d0 fields, returning the float result.
// @fnv 0x009669c0
// src: XBOX_PDB 0x009669c0
float FUN_009669c0_Class::Projectile_GetSpeed()
{
    return BlendWithSetting(GetFloatAtOffset68((char const*)((XActor*)this)->GetActorBase()), m_cc, m_d0);
}


// Exe 0x00962590: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BlkOffset08View
{
    unsigned int GetFlags();
};

struct LogDate
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual BlkOffset08View* GetArrSI();
};

int __cdecl ArrowProjectile_GetArrowCount();
void __cdecl ArrowProjectile_DeleteAttachedArrows_008ce180(unsigned int flags, int limit, TES* object, int, int);

struct FUN_00962590_Class : public TES
{
    void PlayerCharacter_EnteringMenuMode();
};

// If FUN_00570f60() returns a positive value, gets the log date, reads its ArrSI flags, and calls FUN_008ce180 with those flags when nonzero.
// @fnv 0x00962590
// src: COMMUNITY 0x00962590
void FUN_00962590_Class::PlayerCharacter_EnteringMenuMode()
{
    LogDate* pLogDate;
    unsigned int flags;
    BlkOffset08View* pArrSI;
    int limit;

    if (ArrowProjectile_GetArrowCount() > 0)
    {
        pLogDate = reinterpret_cast<LogDate*>(this->GetLogDate());
        if (pLogDate != 0)
        {
            if (pLogDate->GetArrSI() != 0)
            {
                pArrSI = pLogDate->GetArrSI();
                flags = pArrSI->GetFlags();
                limit = 0x7fffffff;
                if (flags != 0)
                {
                    if (limit != 0)
                        ArrowProjectile_DeleteAttachedArrows_008ce180(flags, limit, this, 1, 1);
                }
            }
        }
    }
}

struct FUN_0057c850_cls
{
    bool NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_GetAt(void* value, bool* flag);
};

struct FUN_00962810_Class
{
    char m_ucUnknownByte[0x854];
    FUN_0057c850_cls m_854;

    unsigned char PlayerCharacter_GetLastSpaceForDoor(TESSound* sound);
};

// If sound is non-null, deallocates it and passes the result to m_854.FUN_0057c850, returning the resulting byte (0xff otherwise).
// @fnv 0x00962810
// src: COMMUNITY 0x00962810
unsigned char FUN_00962810_Class::PlayerCharacter_GetLastSpaceForDoor(TESSound* sound)
{
    unsigned char result = 0xff;
    if (sound)
    {
        m_854.NiTMapBase_NiTPointerAllocator_unsigned_int_TESObjectREFR_bool_GetAt(reinterpret_cast<void*>(sound->Deallocate()), reinterpret_cast<bool*>(&result));
    }
    return result;
}


extern BSSimpleList<TESObjectREFR*> g_011e0ae8;

struct FUN_00962cd0_Class
{
    void PlayerCharacter_RemoveConflictingObject(TESObjectREFR* a);
};

// If a is non-null, passes its address to g_011e0ae8's list routine.
// @fnv 0x00962cd0
// src: COMMUNITY 0x00962cd0
void FUN_00962cd0_Class::PlayerCharacter_RemoveConflictingObject(TESObjectREFR* pRef)
{
    if (pRef)
        g_011e0ae8.Remove(pRef);
}

extern float _DAT_011f1c00;

// @fnv 0x00966a40
// src: XBOX_PDB 0x00966a40
float CombatUtilities_GetWorldGravity()
{
    return _DAT_011f1c00;
}

struct FUN_0096a330_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    char* __thiscall GetEntryAt(int index);
};

// @fnv 0x0096a330
char* FUN_0096a330_Class::GetEntryAt(int index)
{
    return (char*)m_iWordAt04 + index * 0x68;
}

struct FUN_0096a670_Class
{
    void UpdateState_0096a510();
    void* __thiscall FUN_0096a670(unsigned int flags);
};
// Calls FUN_0096a510, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x0096a670
void* FUN_0096a670_Class::FUN_0096a670(unsigned int flags)
{
    UpdateState_0096a510();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0096a6d0_Class : GlobalObject_00869f00
{
    void* FUN_0096a6d0(unsigned int flags);
};
// Calls FUN_0096a5f0, then deallocates this if the flags bit 0 is set, and returns this.
// @fnv 0x0096a6d0
void* FUN_0096a6d0_Class::FUN_0096a6d0(unsigned int flags)
{
    SetVtableAndProcessState_0096a5f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


struct FUN_0096a750_layout
{
    int* vtable;
    void** p;
};

// Sets the object's vtable to DAT_0108b4e4 and deallocates its p pointer via NiTMallocInterface<void*>::Deallocate.
// @fnv 0x0096a750
// src: GUESS 0x0096a750 (confidence: low)
void FUN_0096a730_class::SetVtableAndProcessState_0096a750()
{
    reinterpret_cast<FUN_0096a750_layout*>(this)->vtable = &DAT_0108b4e4;
    NiTMallocInterface<void*>::Deallocate(reinterpret_cast<FUN_0096a750_layout*>(this)->p);
}

struct FUN_0096a780_Class : public FUN_0096a730_class
{
    void* __thiscall FUN_0096a780(unsigned int flags);
};

// Calls FUN_0096a750, then deallocates this if the low bit of flags is set, and returns this.
// @fnv 0x0096a780
void* FUN_0096a780_Class::FUN_0096a780(unsigned int flags)
{
    SetVtableAndProcessState_0096a750();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern void* _DAT_0108c0c8;

#include "../../include/NiTMallocInterface.h"

// @fnv 0x0096ad00
// src: GUESS 0x0096ad00 (confidence: medium)
void FUN_0096a930_class::ReleaseStorage_0096ad00()
{
    *((void**)this) = &_DAT_0108c0c8;
    NiTMallocInterface<void*>::Deallocate(*((void***)((char*)this + 4)));
}

struct FUN_0096af60_Class : public FUN_0096a930_class
{
    void* __thiscall FUN_0096af60(unsigned int flags);
};
// Calls FUN_0096ad00, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x0096af60
void* FUN_0096af60_Class::FUN_0096af60(unsigned int flags)
{
    ReleaseStorage_0096ad00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0096af90_Class : public FUN_0096a930_class
{
    void* __thiscall FUN_0096af90(unsigned int flags);
};

// @fnv 0x0096af90
void* FUN_0096af90_Class::FUN_0096af90(unsigned int flags)
{
    ForwardCall_0096a930();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Animation;
// Unit-only deleting wrapper missing from BSScrapArray.h; storage and destruction use the shared class.
template <class T, unsigned int N = 1024>
struct ScrapArrayDeletion : BSScrapArray<T, N>
{
    void* __thiscall DestroyAndFreeIfFlagged(unsigned int flags);
};
// @fnv 0x00978db0
template <>
void* ScrapArrayDeletion<Animation*>::DestroyAndFreeIfFlagged(unsigned int flags)
{
    this->BSScrapArray<Animation*>::~BSScrapArray();
    if (flags & 1)
        ::_Deallocate(this);
    return this;
}


// 0x006815c0 returns the address at this; this caller copies 12 embedded bytes rather than a BGSPerk pointer.
struct EmbeddedRecordDataAccess
{
    void* GetData();
};
struct FUN_0097be80_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    BGSPerk* CombatProcedureMove_GetDestinationPos(BGSPerk* dst);
};
// Copies the perk returned by the list at offset 0x14 into dst and returns dst.
// @fnv 0x0097be80
// src: COMMUNITY 0x0097be80
BGSPerk* FUN_0097be80_Class::CombatProcedureMove_GetDestinationPos(BGSPerk* apPerkOut)
{
    memcpy(apPerkOut, reinterpret_cast<EmbeddedRecordDataAccess*>(reinterpret_cast<char*>(this) + 0x14)->GetData(), 12);
    return apPerkOut;
}



struct FUN_0097f240_Class
{
    unsigned char m_auiShapeKeys[0xe0];
    int m_uiFilterValue;

    void CombatState_SetLastDoorFleeTime(float value);
};

// @fnv 0x0097f240
// src: COMMUNITY 0x0097f240
void FUN_0097f240_Class::CombatState_SetLastDoorFleeTime(float value)
{
    CombatTargetTimestamp timestamp(value);
    m_uiFilterValue = *reinterpret_cast<int*>(&timestamp.fTimeStamp);
}

extern double _DAT_01012060;
struct FUN_0097fa50_Class
{
    int m_iWordAt00;
    float m_iWordAt04;
    bool CombatTimer_IsSet();
};
// Returns whether the float member differs from the global _DAT_01012060.
// @fnv 0x0097fa50
// src: XBOX_PDB 0x0097fa50
bool FUN_0097fa50_Class::CombatTimer_IsSet()
{
    return m_iWordAt04 != _DAT_01012060;
}

extern int DAT_011cc5ec;

// @fnv 0x00960510
// src: COMMUNITY 0x00960510
int __cdecl ViewCaster_GetFuzzyBody()
{
    return DAT_011cc5ec;
}

struct EngineRoot;
struct SceneManager;
struct WorldData;
struct ActionNode;
struct ActionItem;
struct InteractionHandler;
extern "C" EngineRoot* DAT_011dea3c;
struct EngineRoot
{
    SceneManager* BSFile_GetDevice();
};
struct SceneManager
{
    WorldData* ExtraDataList_GetFollowerExtra();
};
struct WorldData
{
    int flags;
    int status;
    int count;
    ActionNode* actions;
};
struct ActionNode
{
    ActionItem* item;
    ActionNode* next;
    ActionNode* ref_006815c0();
    ActionNode* FUN_00726070();
};
struct ActionItem
{
    InteractionHandler* FUN_008d8520();
};
struct InteractionHandler
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void Process(ActionItem*, bool);
};
struct PlayerUIManager
{
    void ProcessAllActions();
};
// Walks the world's action list and calls Process(item, true) on each item's interaction handler, restarting from the head if the list changes.
// @fnv 0x00962880
void PlayerUIManager::ProcessAllActions()
{
    WorldData* world = DAT_011dea3c->BSFile_GetDevice()->ExtraDataList_GetFollowerExtra();
    if (world != 0 && world->actions != 0)
    {
        ActionNode* current = world->actions;
        while (current && current->ref_006815c0()->item != 0)
        {
            ActionNode* next = current->FUN_00726070();
            ActionItem* item = current->ref_006815c0()->item;
            if (item != 0 && item->FUN_008d8520() != 0)
            {
                item->FUN_008d8520()->Process(item, true);
                if (next != current->FUN_00726070())
                    current = world->actions;
                else
                    current = next;
            }
            else
            {
                current = next;
            }
        }
    }
}


struct FUN_00962d00_Node
{
    TESObjectREFR* m_item;
    FUN_00962d00_Node* m_pkNext;
    bool IsEmpty();
    TESObjectREFR*& GetItem();
    FUN_00962d00_Node* GetNext();
    void PopHead(TESObjectREFR** out);
};
void __cdecl bhkWorld_EnableCollision(NiNode* ref, int a, int b, int c);
struct FUN_00962d00_Class
{
    bool ProcessLists_ProcessActors(NiNode* ref);
    void PlayerCharacter_UpdateConflictingObjects();
};
// @fnv 0x00962d00
// src: COMMUNITY 0x00962d00
void FUN_00962d00_Class::PlayerCharacter_UpdateConflictingObjects()
{
    if (reinterpret_cast<FUN_00962d00_Node*>(&g_011e0ae8)->IsEmpty())
    {
        return;
    }
    FUN_00962d00_Node* cur = reinterpret_cast<FUN_00962d00_Node*>(&g_011e0ae8);
    while (cur != 0)
    {
        bool flag = false;
        TESObjectREFR* ref = cur->GetItem();
        NiNode* result = ref->GetNiNode();
        if (result == 0)
        {
            flag = true;
        }
        else if (!this->ProcessLists_ProcessActors(result))
        {
            flag = true;
            reinterpret_cast<NiAVObject*>(result)->FUN_00450f90(0);
            bhkWorld_EnableCollision(result, 1, 1, 0);
        }
        if (flag)
        {
            reinterpret_cast<FUN_00962d00_Node*>(&g_011e0ae8)->PopHead(&ref);
            if (reinterpret_cast<FUN_00962d00_Node*>(&g_011e0ae8)->IsEmpty())
            {
                break;
            }
            cur = reinterpret_cast<FUN_00962d00_Node*>(&g_011e0ae8);
        }
        else
        {
            cur = cur->GetNext();
        }
    }
}

struct FUN_0096a400_Node
{
    FUN_0096a400_Node* m_next;
    unsigned int m_04;
    unsigned char m_08;
};

class FUN_0096a400_cls
{
  public:
    virtual void v00();
    virtual int v04(unsigned int key);
    unsigned int m_04;
    FUN_0096a400_Node** m_08;
    void GetNextEntry(FUN_0096a400_Node** cursor, unsigned int* outKey, unsigned char* outFlag);
};

// @fnv 0x0096a400
void FUN_0096a400_cls::GetNextEntry(FUN_0096a400_Node** cursor, unsigned int* outKey, unsigned char* outFlag)
{
    FUN_0096a400_Node* cur = *cursor;
    *outKey = cur->m_04;
    *outFlag = cur->m_08;
    if (cur->m_next != 0)
    {
        *cursor = cur->m_next;
        return;
    }
    unsigned int i = this->v04(cur->m_04);
    i++;
    for (; i < this->m_04; i++)
    {
        cur = this->m_08[i];
        if (cur != 0)
        {
            *cursor = cur;
            return;
        }
    }
    *cursor = 0;
}

struct FUN_0096a970_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10[4];
    int m_20[4];
    int* FUN_00877a30(int value, int index);
    void FUN_0096ae90(int value, int* p);
    int GetShortAtOffsetA();
    void ResizeAndClear(int n);
    void ProcessArray_CheckNextUpdateBounds();
    void InsertAt(int v);
    void InsertAt(int a1, int index);
};

// @fnv 0x0096a970
void FUN_0096a970_Class::InsertAt(int aiValue, int index)
{
    if (index != -1)
    {
        int iNextIndex = index + 1;
        if (index < 3)
        {
            if (m_20[index] + 1 > (unsigned int)m_10[iNextIndex])
            {
                InsertAt(*FUN_00877a30(m_10[iNextIndex], iNextIndex));
                m_10[iNextIndex] = m_20[index] + 1;
            }
        }
        FUN_0096ae90(m_20[index], &aiValue);
        m_20[index] = m_20[index] + 1;
        if ((unsigned int)m_20[index] >= (unsigned int)GetShortAtOffsetA())
        {
            ResizeAndClear(100);
        }
    }
    ProcessArray_CheckNextUpdateBounds();
}

class B96AB20Ranges
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_auiMin[4];
    unsigned int m_auiMax[4];

    int FindRangeIndex(unsigned int uiValue);
};

// Returns the index of the first of four min/max ranges that contains uiValue, or -1 if none does.
// @fnv 0x0096ab20
int B96AB20Ranges::FindRangeIndex(unsigned int uiValue)
{
    for (int i = 0; i < 4; i++)
    {
        if (uiValue >= m_auiMin[i] && uiValue < m_auiMax[i])
        {
            switch (i)
            {
            case 0:
                return 0;
                break;
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            default:
                return -1;
            }
        }
    }
    return -1;
}

struct FUN_00877a30_Class
{
    int* FUN_00877a30(unsigned int idx);
};

class FUN_0096abc0_cls
{
  public:
    int FindKeyIndex(int key, unsigned int start);
};

// Scans entries from start until the count at offset 0x2c, returning the index whose key matches, or -1 if key is 0 or none match.
// @fnv 0x0096abc0
int FUN_0096abc0_cls::FindKeyIndex(int key, unsigned int start)
{
    int found = -1;
    if (key != 0)
    {
        for (unsigned int i = ((unsigned int*)((char*)this + 0x10))[start];
             i < *(unsigned int*)((char*)this + 0x2c) && found == -1; i++)
        {
            if (key == *((FUN_00877a30_Class*)this)->FUN_00877a30(i))
            {
                return (int)i;
            }
        }
    }
    return found;
}

struct PAVActor
{
    void* _vtable;
    PAVActor();
    ~PAVActor();
    AX* __thiscall FUN_008c1c00();
};



MemoryManager* __cdecl MemoryManager_Instance();

struct FUN_00978ae0 : public PAVActor
{
    char pad[0x0c];
    void* m_10;
    FUN_00978ae0();
};

PAVActor::PAVActor()
{
    this->FUN_008c1c00();
}

PAVActor::~PAVActor()
{}

// Sets the vtable, stores a value from FUN_00401020()->GetContextTracker() at m_10, and calls FUN_006b3eb0(0, 0).
// @fnv 0x00978ae0
FUN_00978ae0::FUN_00978ae0()
{
    *(void**)this = &DAT_0108c250;
    this->m_10 = MemoryManager_Instance()->GetContextTracker();
    ((AX*)this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
}

namespace fnv_00978c50 {
struct FUN_00978ea0
{
    virtual ~FUN_00978ea0();
    FUN_00978ea0();
    int m_pOwnerObject;
    int m_uiItemCount;
    void* m_data;
};


MemoryManager* __cdecl MemoryManager_Instance();

struct FUN_00978c50 : FUN_00978ea0
{
    unsigned int m_resource;
    FUN_00978c50();
    virtual ~FUN_00978c50();
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(unsigned int, unsigned int);
};
// Initializes the base class, stores the value returned by FUN_00401020()->GetContextTracker() in m_resource, then calls FUN_006b3f40(0, 0).
// @fnv 0x00978c50
FUN_00978c50::FUN_00978c50() : FUN_00978ea0()
{
    m_resource = reinterpret_cast<unsigned int>(MemoryManager_Instance()->GetContextTracker());
    BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(0, 0);
}
}  // namespace fnv_00978c50

struct FUN_00978cd0
{
    virtual ~FUN_00978cd0();
};
FUN_00978cd0::~FUN_00978cd0()
{}
struct FUN_00978cf0 : public FUN_00978cd0
{
    void FUN_008454f0(int value);
    virtual ~FUN_00978cf0();
};
// Destructor that calls FUN_008454f0 with the value 1.
// @fnv 0x00978cf0
FUN_00978cf0::~FUN_00978cf0()
{
    FUN_008454f0(1);
}

class C978F70List
{
  public:
    ~C978F70List();

    int unk00;
};

class C978F70Projectile
{
  public:
    ~C978F70Projectile();

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
};

class FUN_00978f70 : public C978F70Projectile
{
  public:
    ~FUN_00978f70();

    C978F70List m_kList;
};

// Destructor for a projectile that also owns a C978F70List member; the compiler-generated member destruction runs after this body.
// @fnv 0x00978f70
FUN_00978f70::~FUN_00978f70()
{}

class TESObjectREFR978;

class PathingSolution978;

template <class T> class PathingRef978
{
  public:
    PathingRef978(T* pObject = 0);
    ~PathingRef978();
    void Reset(T* pObject);

    T* m_pObject;
};

class BaseExtra978
{
  public:
    virtual ~BaseExtra978();
};

class Base978 : public TESForm, public BaseExtra978
{
  public:
    Base978(bool bFlag);
    virtual ~Base978();

    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
};

class FUN_00978fd0 : public Base978
{
  public:
    FUN_00978fd0(bool bFlag);
    virtual ~FUN_00978fd0();

    PathingRef978<PathingSolution978> m_spSolution;
};

// Initializes a Base978-derived form with form type 0x3f and clears the pathing solution reference.
// @fnv 0x00978fd0
FUN_00978fd0::FUN_00978fd0(bool bFlag) : Base978(bFlag)
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x3f));
    m_spSolution.Reset(0);
}

void __cdecl Deallocate(void*);

struct ItemNode
{
    void* value;
    ItemNode* next;
};

struct ItemList
{
    ItemNode* first;
    ItemNode* last;

    ItemNode* __thiscall ref_006815c0();
    void __thiscall FUN_0063f7b0();
    void __thiscall DestroyFields_007b9000();
    ~ItemList()
    {
        DestroyFields_007b9000();
    }
};

struct FUN_00979c80
{
    virtual ~FUN_00979c80();

    ItemList actions;
    ItemList states;
    ItemList targets;
    ItemList effects;
};

// @fnv 0x00979c80
FUN_00979c80::~FUN_00979c80()
{
    ItemList* list = &targets;

    // Keep the retrieved values and the pointers being released in separate scopes.
    {
        void *current1, *current2, *current3, *current4;
        {
            void *owned1, *owned2, *owned3, *owned4;

            while (list != 0 && list->ref_006815c0()->value != 0)
            {
                current4 = list->ref_006815c0()->value;
                owned3 = current4;
                Deallocate(owned3);
                list->FUN_0063f7b0();
            }

            list = &actions;

            while (list != 0 && list->ref_006815c0()->value != 0)
            {
                current1 = list->ref_006815c0()->value;
                owned1 = current1;
                Deallocate(owned1);
                list->FUN_0063f7b0();
            }

            list = &states;

            while (list != 0 && list->ref_006815c0()->value != 0)
            {
                current2 = list->ref_006815c0()->value;
                owned4 = current2;
                Deallocate(owned4);
                list->FUN_0063f7b0();
            }

            list = &effects;

            while (list != 0 && list->ref_006815c0()->value != 0)
            {
                current3 = list->ref_006815c0()->value;
                owned2 = current3;
                Deallocate(owned2);
                list->FUN_0063f7b0();
            }
        }
    }
}

class B97AA40CombatAction
{
  public:
    ~B97AA40CombatAction();

    int unk00;
};

class B97AA40ActionList
{
  public:
    ~B97AA40ActionList();

    void RemoveAll();

    void* m_pvItem;
    B97AA40ActionList* m_pkNext;
};

extern B97AA40CombatAction* g_apkB97AA40Actions[];
extern B97AA40ActionList* g_apkB97AA40ActionLists[];

// @fnv 0x0097aa40
void __cdecl DestroyCombatActionTables()
{
    for (unsigned int i = 0; i < 27; i++)
        delete g_apkB97AA40Actions[i];

    for (unsigned int j = 0; j < 20; j++)
    {
        if (g_apkB97AA40ActionLists[j])
        {
            g_apkB97AA40ActionLists[j]->RemoveAll();
            delete g_apkB97AA40ActionLists[j];
        }
    }
}

// CombatPlanner stand-in: vtable at +0, two counters compared at +4 and +8.
struct S_0097e490_CP
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int CombatPlan_IsFinished();
};

// @fnv 0x0097e490
// src: COMMUNITY 0x0097e490
unsigned int S_0097e490_CP::CombatPlan_IsFinished()
{
    return this->unk08 >= this->unk04;
}

struct Triple12
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
extern "C" Triple12 DAT_011f426c;

struct FUN_0097ede0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;

    FUN_0097ede0_cls* BGSWorldLocation_BGSWorldLocation();
};

// Copies the global Triple12 into this object, clears m_0c, and returns this.
// @fnv 0x0097ede0
// src: XBOX_PDB 0x0097ede0
FUN_0097ede0_cls* FUN_0097ede0_cls::BGSWorldLocation_BGSWorldLocation()
{
    *(Triple12*)this = DAT_011f426c;
    m_0c = 0;
    return this;
}

struct FUN_0097f270_arg
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int v34();
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

float __cdecl CombatTimer_GetTimer();
void __cdecl FUN_00401460(void* a, void* b, int c);

struct FUN_0097f270_cls
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    float m_184;

    void InitFromArg(FUN_0097f270_arg* arg);
};

// @fnv 0x0097f270
void FUN_0097f270_cls::InitFromArg(FUN_0097f270_arg* arg)
{
    FUN_00401460(&m_14c, &m_158, 0x30);
    m_17c = arg->v34();
    m_180 = arg->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    m_184 = CombatTimer_GetTimer();
}

namespace fnv_0097fa90 {
struct FUN_0097fa90_Class
{
    float value;
    float GetClampedDifference();
};
extern double __cdecl CombatTimer_GetTimer();
extern double _DAT_01017b70;

// Returns the difference between FUN_00435dd0() and value, clamped to at most _DAT_01017b70.
// @fnv 0x0097fa90
float FUN_0097fa90_Class::GetClampedDifference()
{
    return (float)(CombatTimer_GetTimer() - value > _DAT_01017b70 ? _DAT_01017b70 : CombatTimer_GetTimer() - value);
}
}  // namespace fnv_0097fa90

// GetValue94: thiscall member with one stack argument.
// Copies the 4-byte value struct stored at this+0x94 into *pOut and returns pOut.
struct FUN_0097fae0_val
{
    int m_v;
};
struct FUN_0097fae0_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    FUN_0097fae0_val m_v94;
    FUN_0097fae0_val* GetValue94(FUN_0097fae0_val* pOut);
};

// @fnv 0x0097fae0
FUN_0097fae0_val* FUN_0097fae0_cls::GetValue94(FUN_0097fae0_val* pOut)
{
    *pOut = m_v94;
    return pOut;
}

// Thiscall getter: copies the dword at +0x98 through the out pointer argument
// and returns that out pointer.
struct FUN_0097fb00_val
{
    unsigned int v;
};

struct FUN_0097fb00_cls
{
    char unk00[0x98];
    FUN_0097fb00_val m_98;
    FUN_0097fb00_val* GetValue98(FUN_0097fb00_val* out);
};

// @fnv 0x0097fb00
FUN_0097fb00_val* FUN_0097fb00_cls::GetValue98(FUN_0097fb00_val* out)
{
    *out = m_98;
    return out;
}

class PKPoint3
{
  public:
    float x;
    float y;
    float z;

    PKPoint3(float afX, float afY, float afZ);
    PKPoint3 operator+(const PKPoint3& arOther) const;
    float Dot(const PKPoint3& arOther) const;
};

struct PKForm
{
    unsigned int GetFormID();
};

struct PKObjectPtr
{
    PKForm* GetObject();
};

struct PKRecord
{
    PKPoint3* GetPlaneNormal();
    PKForm* GetObject();
};

struct PKResults
{
    PKRecord* GetAt(unsigned int auiIndex);
};

struct PKPick
{
    void SetPickType(bool abValue);
    void SetSortType(bool abValue);
    void SetFrontOnly(bool abValue);
    void SetTarget(void* apRoot);
    bool PerformPick(const PKPoint3& arOrigin, const PKPoint3& arDir, bool abAppend);
    void ClearResults(int aiUnk);
    PKResults* GetResults();
};

struct PKFormSet
{
    int unk00;
};

struct PKPlayer
{
    float GetHeight() const;
};

struct PKHighProcess
{
    bool CheckInsideOfObject();
};

bool __cdecl PKSetContains(PKFormSet* apSet, unsigned int auiFormID);

extern PKPick* g_pPKPick;
extern PKPick g_kPKPick;
extern PKPlayer* g_pPKPlayer;
extern PKFormSet g_kPKIgnoredForms;

struct PKRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual PKPoint3* GetPos();

    PKHighProcess* FUN_009306d0();
    bool ProcessLists_ProcessActors(void* apRoot);
};

// @fnv 0x00962950
// src: XBOX_PDB 0x00962950
bool PKRef::ProcessLists_ProcessActors(void* apRoot)
{
    if (!apRoot)
        return false;

    if (!g_pPKPick)
    {
        g_pPKPick = &g_kPKPick;
        g_pPKPick->SetPickType(false);
        g_pPKPick->SetSortType(true);
        g_pPKPick->SetFrontOnly(true);
    }

    PKPoint3 kPos = *GetPos();
    PKPoint3 kDir3(0.0f, 24.0f, 0.0f);
    bool bBlocked = false;
    kPos.z += g_pPKPlayer->GetHeight() * 0.25;
    g_pPKPick->SetTarget(apRoot);

    if (g_pPKPick->PerformPick(kPos + kDir3, kDir3, false))
    {
        PKRecord* pRecordA = g_pPKPick->GetResults()->GetAt(0);
        PKPoint3 kNormal = *pRecordA->GetPlaneNormal();
        if (kDir3.Dot(kNormal) > 0.0 && !PKSetContains(&g_kPKIgnoredForms, pRecordA->GetObject()->GetFormID()))
            bBlocked = true;
    }
    if (!bBlocked)
    {
        kDir3 = PKPoint3(24.0f, -24.0f, 0.0f);
        if (g_pPKPick->PerformPick(kPos + kDir3, kDir3, false))
        {
            PKRecord* pRecordA = g_pPKPick->GetResults()->GetAt(0);
            PKPoint3 kNormal = *pRecordA->GetPlaneNormal();
            if (kDir3.Dot(kNormal) > 0.0 && !PKSetContains(&g_kPKIgnoredForms, pRecordA->GetObject()->GetFormID()))
                bBlocked = true;
        }
        if (!bBlocked)
        {
            kDir3 = PKPoint3(-24.0f, -24.0f, 0.0f);
            if (g_pPKPick->PerformPick(kPos + kDir3, kDir3, false))
            {
                PKRecord* pRecordA = g_pPKPick->GetResults()->GetAt(0);
                PKPoint3 kNormal = *pRecordA->GetPlaneNormal();
                if (kDir3.Dot(kNormal) > 0.0 && !PKSetContains(&g_kPKIgnoredForms, pRecordA->GetObject()->GetFormID()))
                    bBlocked = true;
            }
        }
    }

    g_pPKPick->SetTarget(0);
    g_pPKPick->ClearResults(0);
    if (bBlocked)
        return true;
    return FUN_009306d0()->CheckInsideOfObject();
}

using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting525;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting526;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting527;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting528;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting535;

struct TimeGlobal
{
    float GetMovementDelta();
};
extern TimeGlobal g_timeGlobal;

void BSClamp_float(float& value, float lo, float hi);



struct PlayerDOFOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    ImageSpaceModifierInstanceDOF* dof;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    short unk648;
    bool unk64a;
    bool Actor_GetIronSights();
    void UpdateDepthOfField();
};

// Creates the DOF instance if missing, then steps its distance toward a target setting and applies distance and strength.
// @fnv 0x009650a0
void PlayerDOFOwner::UpdateDepthOfField()
{
    if (dof == 0)
    {
        dof = ImageSpaceModifierInstanceDOF::CreateAndRegister(*originalRuntimeFloatSetting527.Float(),
                                                               *originalRuntimeFloatSetting528.Float(),
                                                               ImageSpaceModifierInstanceDOF::DOF_FRONT_MASK, 0.0f, 0.0f, 0.0f);
        if (dof != 0)
            dof->ImageSpaceModifierInstance_SetPermanent(true);
    }
    float fCap = *originalRuntimeFloatSetting526.Float();
    float fTarget = 0.0f;
    float fCurTmp = dof->GetDistance();
    float fFar = 0.0f;
    if (Actor_GetIronSights() && !unk64a)
    {
        fFar = *originalRuntimeFloatSetting535.Float();
        fTarget = *originalRuntimeFloatSetting526.Float();
        BSShaderManager_SetFullScreenMotionBlurIronSights(1);
    }
    else
    {
        BSShaderManager_SetFullScreenMotionBlurIronSights(0);
    }
    if (fTarget != fCurTmp)
    {
        float fStep = 1.0f / *originalRuntimeFloatSetting525.Float() * g_timeGlobal.GetMovementDelta();
        if (fTarget > fCurTmp)
            fCurTmp += fStep;
        else
            fCurTmp -= fStep;
        BSClamp_float(fCurTmp, 0.0f, fCap);
    }
    dof->SetDistance(fCurTmp);
    dof->SetStrength(originalRuntimeFloatSetting535.GetFloatValue());
}

namespace fnv_00965270 {

using ::SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting529;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting530;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting531;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting532;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting533;
struct GlobalObject_0040e0b0
{
    float* Float();
};
extern GlobalObject_0040e0b0 g_011ce924;
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;


void BSClamp_float(float*, float, float);

extern TESObjectREFR* DAT_011f21cc;
extern BlkOffset08View DAT_011f2250;
class EffectOwner : public TESObjectREFR
{
  public:
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    ImageSpaceModifierInstanceDOF* depthOfField;
    ImageSpaceModifierInstanceDRB* radialBlur;
    void UpdateImageSpaceEffects();
};
// @fnv 0x00965270
void EffectOwner::UpdateImageSpaceEffects()
{
    // Local spellings preserve the original MSVC9 stack layout.
    float i = 0.0f;  // Focus distance.
    if (!depthOfField)
    {
        depthOfField = ImageSpaceModifierInstanceDOF::CreateAndRegister(
            i, originalRuntimeFloatSetting530.Float()[0], ImageSpaceModifierInstanceDOF::DOF_FRONT_BACK, 0.0f, 0.0f, 0.0f);
        if (depthOfField)
            depthOfField->ImageSpaceModifierInstance_SetPermanent(true);
    }
    if (!radialBlur)
    {
        radialBlur = ImageSpaceModifierInstanceDRB::Trigger(
            i, originalRuntimeFloatSetting530.Float()[0], ImageSpaceModifierInstanceDOF::DOF_FRONT_BACK, 0.0f,
            originalRuntimeFloatSetting532.Float()[0], originalRuntimeFloatSetting533.Float()[0], 0.0f, 0.0f,
            NiPoint2(0.5f, 0.5f), 0.0f);
        if (radialBlur)
            reinterpret_cast<ImageSpaceModifierInstanceDOF*>(radialBlur)->ImageSpaceModifierInstance_SetPermanent(true);
    }
    float a = originalRuntimeFloatSetting531.Float()[0];  // Maximum radial blur.
    float f = *g_011ce924.Float();                        // Maximum depth-of-field strength.
    float p = 0.0f;                                       // Desired depth-of-field strength.
    float s = 0.0f;                                       // Desired radial-blur strength.
    float h = depthOfField->FUN_0084d030();               // Current depth-of-field strength.
    float eb = reinterpret_cast<ImageSpaceModifierInstanceDOF*>(radialBlur)->FUN_0084d030();                // Current radial-blur strength.
    if ((DAT_011f2250.GetFlags() == 2 || DAT_011f2250.GetFlags() == 3) && DAT_011f21cc)
    {
        s = a;
        p = f;
        i = (*static_cast<const TESObjectREFR*>(DAT_011f21cc)->GetPos() - *static_cast<const TESObjectREFR*>(this)->GetPos()).Length();
    }
    if (p != h)
    {
        float depthStep = (1.0f / originalRuntimeFloatSetting529.Float()[0]) * g_timeGlobal.FUN_0084d030();
        if (p > h)
            h += depthStep;
        else
            h -= depthStep;
        BSClamp_float(&h, 0.0f, f);
    }
    if (s != eb)
    {
        float blurStep = (1.0f / originalRuntimeFloatSetting529.Float()[0]) * g_timeGlobal.FUN_0084d030();
        if (s > eb)
            eb += blurStep;
        else
            eb -= blurStep;
        BSClamp_float(&eb, 0.0f, a);
    }
    depthOfField->FUN_0063f790(h);
    depthOfField->BaseProcess_SetLastTimeProcessed(i);
    reinterpret_cast<ImageSpaceModifierInstanceDOF*>(radialBlur)->FUN_0063f790(eb);
    reinterpret_cast<ImageSpaceModifierInstanceDOF*>(radialBlur)->SetIntensity(i);
}
}  // namespace fnv_00965270

struct Pathing96d290Item
{
    ~Pathing96d290Item();
    int unk00;
};

struct Member96a950
{
    ~Member96a950();
    int unk00004;
    int unk00008;
    int unk0000C;
    int unk00010;
    int unk00014;
    int unk00018;
    int unk0001C;
    int unk00020;
    int unk00024;
    int unk00028;
    int unk0002C;
    int unk00030;
    int unk00034;
    int unk00038;
    int unk0003C;
    int unk00040;
};

struct Member4ee840
{
    ~Member4ee840();
    int unk00;
    int unk04;
};

struct SoundSlot483710
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct SlotPool8ca350
{
    void* vtable;
    int unk04;
    int unk08;
    SoundSlot483710 slots[0x1000];
    int unk1000C;
};

struct Member8c9430
{
    ~Member8c9430();
    int unk00000;
    int unk00004;
    int unk00008;
    int unk0000C;
    int unk00010;
    int unk00014;
    int unk00018;
    int unk0001C;
    int unk00020;
    int unk00024;
    int unk00028;
    int unk0002C;
    int unk00030;
    int unk00034;
    int unk00038;
    int unk0003C;
    int unk00040;
    int unk00044;
    int unk00048;
    int unk0004C;
    int unk00050;
    int unk00054;
    int unk00058;
    int unk0005C;
    int unk00060;
    int unk00064;
    int unk00068;
    int unk0006C;
    int unk00070;
    int unk00074;
    int unk00078;
    int unk0007C;
    int unk00080;
    int unk00084;
    int unk00088;
    int unk0008C;
    int unk00090;
    int unk00094;
    int unk00098;
    int unk0009C;
    int unk000A0;
    int unk000A4;
    int unk000A8;
    int unk000AC;
    int unk000B0;
    int unk000B4;
    int unk000B8;
    int unk000BC;
    int unk000C0;
    int unk000C4;
    int unk000C8;
    int unk000CC;
    int unk000D0;
    int unk000D4;
    int unk000D8;
    int unk000DC;
    int unk000E0;
    int unk000E4;
    int unk000E8;
    int unk000EC;
    int unk000F0;
    int unk000F4;
    int unk000F8;
    int unk000FC;
    int unk00100;
    int unk00104;
    int unk00108;
    int unk0010C;
    int unk00110;
    int unk00114;
    int unk00118;
    int unk0011C;
    int unk00120;
    int unk00124;
    int unk00128;
    int unk0012C;
    int unk00130;
    int unk00134;
    int unk00138;
    int unk0013C;
    int unk00140;
    int unk00144;
    int unk00148;
    int unk0014C;
    int unk00150;
    int unk00154;
    int unk00158;
    int unk0015C;
    int unk00160;
    int unk00164;
    int unk00168;
    int unk0016C;
    int unk00170;
    SlotPool8ca350 unk174;
};

struct Member905e50
{
    ~Member905e50();
    int unk10360;
    int unk10364;
    int unk10368;
    int unk1036C;
    int unk10370;
    int unk10374;
    int unk10378;
    int unk1037C;
    int unk10380;
    int unk10384;
    int unk10388;
    int unk1038C;
    int unk10390;
    int unk10394;
    int unk10398;
    int unk1039C;
    int unk103A0;
    int unk103A4;
    int unk103A8;
    int unk103AC;
    int unk103B0;
    int unk103B4;
    int unk103B8;
    int unk103BC;
};

struct Member55a2d0
{
    ~Member55a2d0();
    int unk00;
};

struct FUN_0096d290
{
    int unk00;
    Member96a950 unk04;
    BSSimpleList<Pathing96d290Item*>* lists[5];
    Member4ee840 unk58;
    Member4ee840 unk60;
    BSSimpleList<void*> unk68;
    BSSimpleList<void*> unk70;
    BSSimpleList<void*> unk78;
    BSSimpleList<void*> unk80;
    int unk00088;
    int unk0008C;
    int unk00090;
    int unk00094;
    int unk00098;
    int unk0009C;
    int unk000A0;
    int unk000A4;
    int unk000A8;
    int unk000AC;
    int unk000B0;
    int unk000B4;
    int unk000B8;
    int unk000BC;
    int unk000C0;
    int unk000C4;
    int unk000C8;
    int unk000CC;
    int unk000D0;
    int unk000D4;
    int unk000D8;
    int unk000DC;
    int unk000E0;
    int unk000E4;
    int unk000E8;
    int unk000EC;
    int unk000F0;
    int unk000F4;
    int unk000F8;
    int unk000FC;
    int unk00100;
    int unk00104;
    int unk00108;
    int unk0010C;
    int unk00110;
    int unk00114;
    int unk00118;
    int unk0011C;
    int unk00120;
    int unk00124;
    int unk00128;
    int unk0012C;
    int unk00130;
    int unk00134;
    int unk00138;
    int unk0013C;
    int unk00140;
    int unk00144;
    int unk00148;
    int unk0014C;
    int unk00150;
    int unk00154;
    int unk00158;
    int unk0015C;
    Member8c9430 unk160;
    BSSimpleList<void*> unk102E4;
    int unk102EC;
    int unk102F0;
    int unk102F4;
    int unk102F8;
    int unk102FC;
    int unk10300;
    int unk10304;
    int unk10308;
    int unk1030C;
    int unk10310;
    int unk10314;
    int unk10318;
    int unk1031C;
    int unk10320;
    int unk10324;
    int unk10328;
    int unk1032C;
    int unk10330;
    int unk10334;
    int unk10338;
    int unk1033C;
    int unk10340;
    int unk10344;
    int unk10348;
    int unk1034C;
    int unk10350;
    int unk10354;
    int unk10358;
    int unk1035C;
    Member905e50 unk10360;
    Member55a2d0 unk103C0;

    ~FUN_0096d290();
};

// Destructor: deletes every item and list in the five lists, then clears the lists at unk70 and unk80.
// @fnv 0x0096d290
FUN_0096d290::~FUN_0096d290()
{
    for (int i = 0; i < 5; i++)
    {
        BSSimpleList<Pathing96d290Item*>* list = lists[i];
        while (list && list->GetItem())
        {
            Pathing96d290Item* item = list->GetItem();
            delete item;
            list->RemoveHead();
        }
        delete list;
    }
    unk70.RemoveAll();
    unk80.RemoveAll();
}




void* __fastcall GetActorParentCell(Actor*);

struct GameClock
{
    float FUN_00867da0();
};
extern "C" GameClock DAT_011de7b8;
struct ActorUpdateManager
{
    void* vtable;
    TopicInfoArray actors;
    void UpdateActors();
};
// @fnv 0x0096df40
void ActorUpdateManager::UpdateActors()
{
    for (unsigned int i = 0; i < actors.ProcessArray_GetProcessLevelTail(0); i++)
    {
        Actor* actor = actors.ProcessArray_GetItem(i);
        if (actor && actor->IsActor() && !actor->TESForm_IsStillLoading() && (GetActorParentCell(actor) || actor->TESObjectREFR_GetWorldSpace()))
        {
            Actor* ref = actor;
            if (ref && ref != reinterpret_cast<Actor*>(DAT_011dea3c) && ref->GetProcess() && !ref->GetDeleted() &&
                !ref->GetDisabled() && !ref->Actor_IsInCombat())
            {
                float previousHour = ref->GetProcess()->FUN_007df1f0();
                {
                    float currentHour = DAT_011de7b8.FUN_00867da0();
                    {
                        float elapsedHours = currentHour - previousHour;
                        if (currentHour < previousHour)
                            elapsedHours = currentHour + 24.0 - previousHour;
                        {
                            bool followingPlayer = false;
                            if (elapsedHours < 0.05)
                                elapsedHours = 0.0f;
                            if (ref->GetProcess() && ref->GetProcess()->GetCurrentPackage() &&
                                ref->GetProcess()->GetCurrentPackage()->GetPackType() == 2)
                                followingPlayer = true;
                            if (!((followingPlayer || ref->Actor_IsFollowing()) &&
                                  ref->GetProcess()->GetTarget() == reinterpret_cast<Actor*>(DAT_011dea3c)))
                                reinterpret_cast<void (__thiscall*)(Actor*, float)>((*reinterpret_cast<void***>(ref))[0x97])(ref, elapsedHours);
                        }
                    }
                }
            }
        }
    }
}

struct LoadBuffer
{
    virtual unsigned char GetVersion();
    void LoadData(void*, unsigned int);
    unsigned int FUN_00864a60();
};
struct LoadedEntry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    LoadedEntry();
    void ReadFromStream(LoadBuffer*);
};
struct EntryListNode
{
    LoadedEntry* entry;
    EntryListNode* next;
    EntryListNode();
    void FUN_00470470();
    void FUN_005ae3d0(LoadedEntry*&);
};
struct FUN_00975930_shell
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    EntryListNode* lists[5];
    unsigned __int64 f58, f60, f68, f70, f78, f80, f88, f90, f98, fA0, fA8, fB0, fB8, fC0, fC8, fD0, fD8, fE0, fE8, fF0,
        fF8, f100, f108, f110, f118, f120, f128, f130, f138, f140, f148;
    unsigned int unk00150, unk00154, unk00158, unk0015C;
    unsigned __int64 f160, f168, f170, f178, f180, f188, f190, f198, f1A0, f1A8, f1B0, f1B8, f1C0, f1C8, f1D0, f1D8,
        f1E0, f1E8, f1F0, f1F8, f200, f208, f210, f218, f220, f228, f230, f238, f240, f248, f250, f258, f260, f268,
        f270, f278, f280, f288, f290, f298, f2A0, f2A8, f2B0, f2B8, f2C0, f2C8, f2D0, f2D8, f2E0, f2E8, f2F0, f2F8,
        f300, f308, f310, f318, f320, f328, f330, f338, f340, f348, f350, f358, f360, f368, f370, f378, f380, f388,
        f390, f398, f3A0, f3A8, f3B0, f3B8, f3C0, f3C8, f3D0, f3D8, f3E0, f3E8, f3F0, f3F8, f400, f408, f410, f418,
        f420, f428, f430, f438, f440, f448, f450, f458, f460, f468, f470, f478, f480, f488, f490, f498, f4A0, f4A8,
        f4B0, f4B8, f4C0, f4C8, f4D0, f4D8, f4E0, f4E8, f4F0, f4F8, f500, f508, f510, f518, f520, f528, f530, f538,
        f540, f548, f550, f558, f560, f568, f570, f578, f580, f588, f590, f598, f5A0, f5A8, f5B0, f5B8, f5C0, f5C8,
        f5D0, f5D8, f5E0, f5E8, f5F0, f5F8, f600, f608, f610, f618, f620, f628, f630, f638, f640, f648, f650, f658,
        f660, f668, f670, f678, f680, f688, f690, f698, f6A0, f6A8, f6B0, f6B8, f6C0, f6C8, f6D0, f6D8, f6E0, f6E8,
        f6F0, f6F8, f700, f708, f710, f718, f720, f728, f730, f738, f740, f748, f750, f758, f760, f768, f770, f778,
        f780, f788, f790, f798, f7A0, f7A8, f7B0, f7B8, f7C0, f7C8, f7D0, f7D8, f7E0, f7E8, f7F0, f7F8, f800, f808,
        f810, f818, f820, f828, f830, f838, f840, f848, f850, f858, f860, f868, f870, f878, f880, f888, f890, f898,
        f8A0, f8A8, f8B0, f8B8, f8C0, f8C8, f8D0, f8D8, f8E0, f8E8, f8F0, f8F8, f900, f908, f910, f918, f920, f928,
        f930, f938, f940, f948, f950, f958, f960, f968, f970, f978, f980, f988, f990, f998, f9A0, f9A8, f9B0, f9B8,
        f9C0, f9C8, f9D0, f9D8, f9E0, f9E8, f9F0, f9F8, fA00, fA08, fA10, fA18, fA20, fA28, fA30, fA38, fA40, fA48,
        fA50, fA58, fA60, fA68, fA70, fA78, fA80, fA88, fA90, fA98, fAA0, fAA8, fAB0, fAB8, fAC0, fAC8, fAD0, fAD8,
        fAE0, fAE8, fAF0, fAF8, fB00, fB08, fB10, fB18, fB20, fB28, fB30, fB38, fB40, fB48, fB50, fB58, fB60, fB68,
        fB70, fB78, fB80, fB88, fB90, fB98, fBA0, fBA8, fBB0, fBB8, fBC0, fBC8, fBD0, fBD8, fBE0, fBE8, fBF0, fBF8,
        fC00, fC08, fC10, fC18, fC20, fC28, fC30, fC38, fC40, fC48, fC50, fC58, fC60, fC68, fC70, fC78, fC80, fC88,
        fC90, fC98, fCA0, fCA8, fCB0, fCB8, fCC0, fCC8, fCD0, fCD8, fCE0, fCE8, fCF0, fCF8, fD00, fD08, fD10, fD18,
        fD20, fD28, fD30, fD38, fD40, fD48, fD50, fD58, fD60, fD68, fD70, fD78, fD80, fD88, fD90, fD98, fDA0, fDA8,
        fDB0, fDB8, fDC0, fDC8, fDD0, fDD8, fDE0, fDE8, fDF0, fDF8, fE00, fE08, fE10, fE18, fE20, fE28, fE30, fE38,
        fE40, fE48, fE50, fE58, fE60, fE68, fE70, fE78, fE80, fE88, fE90, fE98, fEA0, fEA8, fEB0, fEB8, fEC0, fEC8,
        fED0, fED8, fEE0, fEE8, fEF0, fEF8, fF00, fF08, fF10, fF18, fF20, fF28, fF30, fF38, fF40, fF48, fF50, fF58,
        fF60, fF68, fF70, fF78, fF80, fF88, fF90, fF98, fFA0, fFA8, fFB0, fFB8, fFC0, fFC8, fFD0, fFD8, fFE0, fFE8,
        fFF0, fFF8, f1000, f1008, f1010, f1018, f1020, f1028, f1030, f1038, f1040, f1048, f1050, f1058, f1060, f1068,
        f1070, f1078, f1080, f1088, f1090, f1098, f10A0, f10A8, f10B0, f10B8, f10C0, f10C8, f10D0, f10D8, f10E0, f10E8,
        f10F0, f10F8, f1100, f1108, f1110, f1118, f1120, f1128, f1130, f1138, f1140, f1148, f1150, f1158, f1160, f1168,
        f1170, f1178, f1180, f1188, f1190, f1198, f11A0, f11A8, f11B0, f11B8, f11C0, f11C8, f11D0, f11D8, f11E0, f11E8,
        f11F0, f11F8, f1200, f1208, f1210, f1218, f1220, f1228, f1230, f1238, f1240, f1248, f1250, f1258, f1260, f1268,
        f1270, f1278, f1280, f1288, f1290, f1298, f12A0, f12A8, f12B0, f12B8, f12C0, f12C8, f12D0, f12D8, f12E0, f12E8,
        f12F0, f12F8, f1300, f1308, f1310, f1318, f1320, f1328, f1330, f1338, f1340, f1348, f1350, f1358, f1360, f1368,
        f1370, f1378, f1380, f1388, f1390, f1398, f13A0, f13A8, f13B0, f13B8, f13C0, f13C8, f13D0, f13D8, f13E0, f13E8,
        f13F0, f13F8, f1400, f1408, f1410, f1418, f1420, f1428, f1430, f1438, f1440, f1448, f1450, f1458, f1460, f1468,
        f1470, f1478, f1480, f1488, f1490, f1498, f14A0, f14A8, f14B0, f14B8, f14C0, f14C8, f14D0, f14D8, f14E0, f14E8,
        f14F0, f14F8, f1500, f1508, f1510, f1518, f1520, f1528, f1530, f1538, f1540, f1548, f1550, f1558, f1560, f1568,
        f1570, f1578, f1580, f1588, f1590, f1598, f15A0, f15A8, f15B0, f15B8, f15C0, f15C8, f15D0, f15D8, f15E0, f15E8,
        f15F0, f15F8, f1600, f1608, f1610, f1618, f1620, f1628, f1630, f1638, f1640, f1648, f1650, f1658, f1660, f1668,
        f1670, f1678, f1680, f1688, f1690, f1698, f16A0, f16A8, f16B0, f16B8, f16C0, f16C8, f16D0, f16D8, f16E0, f16E8,
        f16F0, f16F8, f1700, f1708, f1710, f1718, f1720, f1728, f1730, f1738, f1740, f1748, f1750, f1758, f1760, f1768,
        f1770, f1778, f1780, f1788, f1790, f1798, f17A0, f17A8, f17B0, f17B8, f17C0, f17C8, f17D0, f17D8, f17E0, f17E8,
        f17F0, f17F8, f1800, f1808, f1810, f1818, f1820, f1828, f1830, f1838, f1840, f1848, f1850, f1858, f1860, f1868,
        f1870, f1878, f1880, f1888, f1890, f1898, f18A0, f18A8, f18B0, f18B8, f18C0, f18C8, f18D0, f18D8, f18E0, f18E8,
        f18F0, f18F8, f1900, f1908, f1910, f1918, f1920, f1928, f1930, f1938, f1940, f1948, f1950, f1958, f1960, f1968,
        f1970, f1978, f1980, f1988, f1990, f1998, f19A0, f19A8, f19B0, f19B8, f19C0, f19C8, f19D0, f19D8, f19E0, f19E8,
        f19F0, f19F8, f1A00, f1A08, f1A10, f1A18, f1A20, f1A28, f1A30, f1A38, f1A40, f1A48, f1A50, f1A58, f1A60, f1A68,
        f1A70, f1A78, f1A80, f1A88, f1A90, f1A98, f1AA0, f1AA8, f1AB0, f1AB8, f1AC0, f1AC8, f1AD0, f1AD8, f1AE0, f1AE8,
        f1AF0, f1AF8, f1B00, f1B08, f1B10, f1B18, f1B20, f1B28, f1B30, f1B38, f1B40, f1B48, f1B50, f1B58, f1B60, f1B68,
        f1B70, f1B78, f1B80, f1B88, f1B90, f1B98, f1BA0, f1BA8, f1BB0, f1BB8, f1BC0, f1BC8, f1BD0, f1BD8, f1BE0, f1BE8,
        f1BF0, f1BF8, f1C00, f1C08, f1C10, f1C18, f1C20, f1C28, f1C30, f1C38, f1C40, f1C48, f1C50, f1C58, f1C60, f1C68,
        f1C70, f1C78, f1C80, f1C88, f1C90, f1C98, f1CA0, f1CA8, f1CB0, f1CB8, f1CC0, f1CC8, f1CD0, f1CD8, f1CE0, f1CE8,
        f1CF0, f1CF8, f1D00, f1D08, f1D10, f1D18, f1D20, f1D28, f1D30, f1D38, f1D40, f1D48, f1D50, f1D58, f1D60, f1D68,
        f1D70, f1D78, f1D80, f1D88, f1D90, f1D98, f1DA0, f1DA8, f1DB0, f1DB8, f1DC0, f1DC8, f1DD0, f1DD8, f1DE0, f1DE8,
        f1DF0, f1DF8, f1E00, f1E08, f1E10, f1E18, f1E20, f1E28, f1E30, f1E38, f1E40, f1E48, f1E50, f1E58, f1E60, f1E68,
        f1E70, f1E78, f1E80, f1E88, f1E90, f1E98, f1EA0, f1EA8, f1EB0, f1EB8, f1EC0, f1EC8, f1ED0, f1ED8, f1EE0, f1EE8,
        f1EF0, f1EF8, f1F00, f1F08, f1F10, f1F18, f1F20, f1F28, f1F30, f1F38, f1F40, f1F48, f1F50, f1F58, f1F60, f1F68,
        f1F70, f1F78, f1F80, f1F88, f1F90, f1F98, f1FA0, f1FA8, f1FB0, f1FB8, f1FC0, f1FC8, f1FD0, f1FD8, f1FE0, f1FE8,
        f1FF0, f1FF8, f2000, f2008, f2010, f2018, f2020, f2028, f2030, f2038, f2040, f2048, f2050, f2058, f2060, f2068,
        f2070, f2078, f2080, f2088, f2090, f2098, f20A0, f20A8, f20B0, f20B8, f20C0, f20C8, f20D0, f20D8, f20E0, f20E8,
        f20F0, f20F8, f2100, f2108, f2110, f2118, f2120, f2128, f2130, f2138, f2140, f2148, f2150, f2158, f2160, f2168,
        f2170, f2178, f2180, f2188, f2190, f2198, f21A0, f21A8, f21B0, f21B8, f21C0, f21C8, f21D0, f21D8, f21E0, f21E8,
        f21F0, f21F8, f2200, f2208, f2210, f2218, f2220, f2228, f2230, f2238, f2240, f2248, f2250, f2258, f2260, f2268,
        f2270, f2278, f2280, f2288, f2290, f2298, f22A0, f22A8, f22B0, f22B8, f22C0, f22C8, f22D0, f22D8, f22E0, f22E8,
        f22F0, f22F8, f2300, f2308, f2310, f2318, f2320, f2328, f2330, f2338, f2340, f2348, f2350, f2358, f2360, f2368,
        f2370, f2378, f2380, f2388, f2390, f2398, f23A0, f23A8, f23B0, f23B8, f23C0, f23C8, f23D0, f23D8, f23E0, f23E8,
        f23F0, f23F8, f2400, f2408, f2410, f2418, f2420, f2428, f2430, f2438, f2440, f2448, f2450, f2458, f2460, f2468,
        f2470, f2478, f2480, f2488, f2490, f2498, f24A0, f24A8, f24B0, f24B8, f24C0, f24C8, f24D0, f24D8, f24E0, f24E8,
        f24F0, f24F8, f2500, f2508, f2510, f2518, f2520, f2528, f2530, f2538, f2540, f2548, f2550, f2558, f2560, f2568,
        f2570, f2578, f2580, f2588, f2590, f2598, f25A0, f25A8, f25B0, f25B8, f25C0, f25C8, f25D0, f25D8, f25E0, f25E8,
        f25F0, f25F8, f2600, f2608, f2610, f2618, f2620, f2628, f2630, f2638, f2640, f2648, f2650, f2658, f2660, f2668,
        f2670, f2678, f2680, f2688, f2690, f2698, f26A0, f26A8, f26B0, f26B8, f26C0, f26C8, f26D0, f26D8, f26E0, f26E8,
        f26F0, f26F8, f2700, f2708, f2710, f2718, f2720, f2728, f2730, f2738, f2740, f2748, f2750, f2758, f2760, f2768,
        f2770, f2778, f2780, f2788, f2790, f2798, f27A0, f27A8, f27B0, f27B8, f27C0, f27C8, f27D0, f27D8, f27E0, f27E8,
        f27F0, f27F8, f2800, f2808, f2810, f2818, f2820, f2828, f2830, f2838, f2840, f2848, f2850, f2858, f2860, f2868,
        f2870, f2878, f2880, f2888, f2890, f2898, f28A0, f28A8, f28B0, f28B8, f28C0, f28C8, f28D0, f28D8, f28E0, f28E8,
        f28F0, f28F8, f2900, f2908, f2910, f2918, f2920, f2928, f2930, f2938, f2940, f2948, f2950, f2958, f2960, f2968,
        f2970, f2978, f2980, f2988, f2990, f2998, f29A0, f29A8, f29B0, f29B8, f29C0, f29C8, f29D0, f29D8, f29E0, f29E8,
        f29F0, f29F8, f2A00, f2A08, f2A10, f2A18, f2A20, f2A28, f2A30, f2A38, f2A40, f2A48, f2A50, f2A58, f2A60, f2A68,
        f2A70, f2A78, f2A80, f2A88, f2A90, f2A98, f2AA0, f2AA8, f2AB0, f2AB8, f2AC0, f2AC8, f2AD0, f2AD8, f2AE0, f2AE8,
        f2AF0, f2AF8, f2B00, f2B08, f2B10, f2B18, f2B20, f2B28, f2B30, f2B38, f2B40, f2B48, f2B50, f2B58, f2B60, f2B68,
        f2B70, f2B78, f2B80, f2B88, f2B90, f2B98, f2BA0, f2BA8, f2BB0, f2BB8, f2BC0, f2BC8, f2BD0, f2BD8, f2BE0, f2BE8,
        f2BF0, f2BF8, f2C00, f2C08, f2C10, f2C18, f2C20, f2C28, f2C30, f2C38, f2C40, f2C48, f2C50, f2C58, f2C60, f2C68,
        f2C70, f2C78, f2C80, f2C88, f2C90, f2C98, f2CA0, f2CA8, f2CB0, f2CB8, f2CC0, f2CC8, f2CD0, f2CD8, f2CE0, f2CE8,
        f2CF0, f2CF8, f2D00, f2D08, f2D10, f2D18, f2D20, f2D28, f2D30, f2D38, f2D40, f2D48, f2D50, f2D58, f2D60, f2D68,
        f2D70, f2D78, f2D80, f2D88, f2D90, f2D98, f2DA0, f2DA8, f2DB0, f2DB8, f2DC0, f2DC8, f2DD0, f2DD8, f2DE0, f2DE8,
        f2DF0, f2DF8, f2E00, f2E08, f2E10, f2E18, f2E20, f2E28, f2E30, f2E38, f2E40, f2E48, f2E50, f2E58, f2E60, f2E68,
        f2E70, f2E78, f2E80, f2E88, f2E90, f2E98, f2EA0, f2EA8, f2EB0, f2EB8, f2EC0, f2EC8, f2ED0, f2ED8, f2EE0, f2EE8,
        f2EF0, f2EF8, f2F00, f2F08, f2F10, f2F18, f2F20, f2F28, f2F30, f2F38, f2F40, f2F48, f2F50, f2F58, f2F60, f2F68,
        f2F70, f2F78, f2F80, f2F88, f2F90, f2F98, f2FA0, f2FA8, f2FB0, f2FB8, f2FC0, f2FC8, f2FD0, f2FD8, f2FE0, f2FE8,
        f2FF0, f2FF8, f3000, f3008, f3010, f3018, f3020, f3028, f3030, f3038, f3040, f3048, f3050, f3058, f3060, f3068,
        f3070, f3078, f3080, f3088, f3090, f3098, f30A0, f30A8, f30B0, f30B8, f30C0, f30C8, f30D0, f30D8, f30E0, f30E8,
        f30F0, f30F8, f3100, f3108, f3110, f3118, f3120, f3128, f3130, f3138, f3140, f3148, f3150, f3158, f3160, f3168,
        f3170, f3178, f3180, f3188, f3190, f3198, f31A0, f31A8, f31B0, f31B8, f31C0, f31C8, f31D0, f31D8, f31E0, f31E8,
        f31F0, f31F8, f3200, f3208, f3210, f3218, f3220, f3228, f3230, f3238, f3240, f3248, f3250, f3258, f3260, f3268,
        f3270, f3278, f3280, f3288, f3290, f3298, f32A0, f32A8, f32B0, f32B8, f32C0, f32C8, f32D0, f32D8, f32E0, f32E8,
        f32F0, f32F8, f3300, f3308, f3310, f3318, f3320, f3328, f3330, f3338, f3340, f3348, f3350, f3358, f3360, f3368,
        f3370, f3378, f3380, f3388, f3390, f3398, f33A0, f33A8, f33B0, f33B8, f33C0, f33C8, f33D0, f33D8, f33E0, f33E8,
        f33F0, f33F8, f3400, f3408, f3410, f3418, f3420, f3428, f3430, f3438, f3440, f3448, f3450, f3458, f3460, f3468,
        f3470, f3478, f3480, f3488, f3490, f3498, f34A0, f34A8, f34B0, f34B8, f34C0, f34C8, f34D0, f34D8, f34E0, f34E8,
        f34F0, f34F8, f3500, f3508, f3510, f3518, f3520, f3528, f3530, f3538, f3540, f3548, f3550, f3558, f3560, f3568,
        f3570, f3578, f3580, f3588, f3590, f3598, f35A0, f35A8, f35B0, f35B8, f35C0, f35C8, f35D0, f35D8, f35E0, f35E8,
        f35F0, f35F8, f3600, f3608, f3610, f3618, f3620, f3628, f3630, f3638, f3640, f3648, f3650, f3658, f3660, f3668,
        f3670, f3678, f3680, f3688, f3690, f3698, f36A0, f36A8, f36B0, f36B8, f36C0, f36C8, f36D0, f36D8, f36E0, f36E8,
        f36F0, f36F8, f3700, f3708, f3710, f3718, f3720, f3728, f3730, f3738, f3740, f3748, f3750, f3758, f3760, f3768,
        f3770, f3778, f3780, f3788, f3790, f3798, f37A0, f37A8, f37B0, f37B8, f37C0, f37C8, f37D0, f37D8, f37E0, f37E8,
        f37F0, f37F8, f3800, f3808, f3810, f3818, f3820, f3828, f3830, f3838, f3840, f3848, f3850, f3858, f3860, f3868,
        f3870, f3878, f3880, f3888, f3890, f3898, f38A0, f38A8, f38B0, f38B8, f38C0, f38C8, f38D0, f38D8, f38E0, f38E8,
        f38F0, f38F8, f3900, f3908, f3910, f3918, f3920, f3928, f3930, f3938, f3940, f3948, f3950, f3958, f3960, f3968,
        f3970, f3978, f3980, f3988, f3990, f3998, f39A0, f39A8, f39B0, f39B8, f39C0, f39C8, f39D0, f39D8, f39E0, f39E8,
        f39F0, f39F8, f3A00, f3A08, f3A10, f3A18, f3A20, f3A28, f3A30, f3A38, f3A40, f3A48, f3A50, f3A58, f3A60, f3A68,
        f3A70, f3A78, f3A80, f3A88, f3A90, f3A98, f3AA0, f3AA8, f3AB0, f3AB8, f3AC0, f3AC8, f3AD0, f3AD8, f3AE0, f3AE8,
        f3AF0, f3AF8, f3B00, f3B08, f3B10, f3B18, f3B20, f3B28, f3B30, f3B38, f3B40, f3B48, f3B50, f3B58, f3B60, f3B68,
        f3B70, f3B78, f3B80, f3B88, f3B90, f3B98, f3BA0, f3BA8, f3BB0, f3BB8, f3BC0, f3BC8, f3BD0, f3BD8, f3BE0, f3BE8,
        f3BF0, f3BF8, f3C00, f3C08, f3C10, f3C18, f3C20, f3C28, f3C30, f3C38, f3C40, f3C48, f3C50, f3C58, f3C60, f3C68,
        f3C70, f3C78, f3C80, f3C88, f3C90, f3C98, f3CA0, f3CA8, f3CB0, f3CB8, f3CC0, f3CC8, f3CD0, f3CD8, f3CE0, f3CE8,
        f3CF0, f3CF8, f3D00, f3D08, f3D10, f3D18, f3D20, f3D28, f3D30, f3D38, f3D40, f3D48, f3D50, f3D58, f3D60, f3D68,
        f3D70, f3D78, f3D80, f3D88, f3D90, f3D98, f3DA0, f3DA8, f3DB0, f3DB8, f3DC0, f3DC8, f3DD0, f3DD8, f3DE0, f3DE8,
        f3DF0, f3DF8, f3E00, f3E08, f3E10, f3E18, f3E20, f3E28, f3E30, f3E38, f3E40, f3E48, f3E50, f3E58, f3E60, f3E68,
        f3E70, f3E78, f3E80, f3E88, f3E90, f3E98, f3EA0, f3EA8, f3EB0, f3EB8, f3EC0, f3EC8, f3ED0, f3ED8, f3EE0, f3EE8,
        f3EF0, f3EF8, f3F00, f3F08, f3F10, f3F18, f3F20, f3F28, f3F30, f3F38, f3F40, f3F48, f3F50, f3F58, f3F60, f3F68,
        f3F70, f3F78, f3F80, f3F88, f3F90, f3F98, f3FA0, f3FA8, f3FB0, f3FB8, f3FC0, f3FC8, f3FD0, f3FD8, f3FE0, f3FE8,
        f3FF0, f3FF8, f4000, f4008, f4010, f4018, f4020, f4028, f4030, f4038, f4040, f4048, f4050, f4058, f4060, f4068,
        f4070, f4078, f4080, f4088, f4090, f4098, f40A0, f40A8, f40B0, f40B8, f40C0, f40C8, f40D0, f40D8, f40E0, f40E8,
        f40F0, f40F8, f4100, f4108, f4110, f4118, f4120, f4128, f4130, f4138, f4140, f4148, f4150, f4158, f4160, f4168,
        f4170, f4178, f4180, f4188, f4190, f4198, f41A0, f41A8, f41B0, f41B8, f41C0, f41C8, f41D0, f41D8, f41E0, f41E8,
        f41F0, f41F8, f4200, f4208, f4210, f4218, f4220, f4228, f4230, f4238, f4240, f4248, f4250, f4258, f4260, f4268,
        f4270, f4278, f4280, f4288, f4290, f4298, f42A0, f42A8, f42B0, f42B8, f42C0, f42C8, f42D0, f42D8, f42E0, f42E8,
        f42F0, f42F8, f4300, f4308, f4310, f4318, f4320, f4328, f4330, f4338, f4340, f4348, f4350, f4358, f4360, f4368,
        f4370, f4378, f4380, f4388, f4390, f4398, f43A0, f43A8, f43B0, f43B8, f43C0, f43C8, f43D0, f43D8, f43E0, f43E8,
        f43F0, f43F8, f4400, f4408, f4410, f4418, f4420, f4428, f4430, f4438, f4440, f4448, f4450, f4458, f4460, f4468,
        f4470, f4478, f4480, f4488, f4490, f4498, f44A0, f44A8, f44B0, f44B8, f44C0, f44C8, f44D0, f44D8, f44E0, f44E8,
        f44F0, f44F8, f4500, f4508, f4510, f4518, f4520, f4528, f4530, f4538, f4540, f4548, f4550, f4558, f4560, f4568,
        f4570, f4578, f4580, f4588, f4590, f4598, f45A0, f45A8, f45B0, f45B8, f45C0, f45C8, f45D0, f45D8, f45E0, f45E8,
        f45F0, f45F8, f4600, f4608, f4610, f4618, f4620, f4628, f4630, f4638, f4640, f4648, f4650, f4658, f4660, f4668,
        f4670, f4678, f4680, f4688, f4690, f4698, f46A0, f46A8, f46B0, f46B8, f46C0, f46C8, f46D0, f46D8, f46E0, f46E8,
        f46F0, f46F8, f4700, f4708, f4710, f4718, f4720, f4728, f4730, f4738, f4740, f4748, f4750, f4758, f4760, f4768,
        f4770, f4778, f4780, f4788, f4790, f4798, f47A0, f47A8, f47B0, f47B8, f47C0, f47C8, f47D0, f47D8, f47E0, f47E8,
        f47F0, f47F8, f4800, f4808, f4810, f4818, f4820, f4828, f4830, f4838, f4840, f4848, f4850, f4858, f4860, f4868,
        f4870, f4878, f4880, f4888, f4890, f4898, f48A0, f48A8, f48B0, f48B8, f48C0, f48C8, f48D0, f48D8, f48E0, f48E8,
        f48F0, f48F8, f4900, f4908, f4910, f4918, f4920, f4928, f4930, f4938, f4940, f4948, f4950, f4958, f4960, f4968,
        f4970, f4978, f4980, f4988, f4990, f4998, f49A0, f49A8, f49B0, f49B8, f49C0, f49C8, f49D0, f49D8, f49E0, f49E8,
        f49F0, f49F8, f4A00, f4A08, f4A10, f4A18, f4A20, f4A28, f4A30, f4A38, f4A40, f4A48, f4A50, f4A58, f4A60, f4A68,
        f4A70, f4A78, f4A80, f4A88, f4A90, f4A98, f4AA0, f4AA8, f4AB0, f4AB8, f4AC0, f4AC8, f4AD0, f4AD8, f4AE0, f4AE8,
        f4AF0, f4AF8, f4B00, f4B08, f4B10, f4B18, f4B20, f4B28, f4B30, f4B38, f4B40, f4B48, f4B50, f4B58, f4B60, f4B68,
        f4B70, f4B78, f4B80, f4B88, f4B90, f4B98, f4BA0, f4BA8, f4BB0, f4BB8, f4BC0, f4BC8, f4BD0, f4BD8, f4BE0, f4BE8,
        f4BF0, f4BF8, f4C00, f4C08, f4C10, f4C18, f4C20, f4C28, f4C30, f4C38, f4C40, f4C48, f4C50, f4C58, f4C60, f4C68,
        f4C70, f4C78, f4C80, f4C88, f4C90, f4C98, f4CA0, f4CA8, f4CB0, f4CB8, f4CC0, f4CC8, f4CD0, f4CD8, f4CE0, f4CE8,
        f4CF0, f4CF8, f4D00, f4D08, f4D10, f4D18, f4D20, f4D28, f4D30, f4D38, f4D40, f4D48, f4D50, f4D58, f4D60, f4D68,
        f4D70, f4D78, f4D80, f4D88, f4D90, f4D98, f4DA0, f4DA8, f4DB0, f4DB8, f4DC0, f4DC8, f4DD0, f4DD8, f4DE0, f4DE8,
        f4DF0, f4DF8, f4E00, f4E08, f4E10, f4E18, f4E20, f4E28, f4E30, f4E38, f4E40, f4E48, f4E50, f4E58, f4E60, f4E68,
        f4E70, f4E78, f4E80, f4E88, f4E90, f4E98, f4EA0, f4EA8, f4EB0, f4EB8, f4EC0, f4EC8, f4ED0, f4ED8, f4EE0, f4EE8,
        f4EF0, f4EF8, f4F00, f4F08, f4F10, f4F18, f4F20, f4F28, f4F30, f4F38, f4F40, f4F48, f4F50, f4F58, f4F60, f4F68,
        f4F70, f4F78, f4F80, f4F88, f4F90, f4F98, f4FA0, f4FA8, f4FB0, f4FB8, f4FC0, f4FC8, f4FD0, f4FD8, f4FE0, f4FE8,
        f4FF0, f4FF8, f5000, f5008, f5010, f5018, f5020, f5028, f5030, f5038, f5040, f5048, f5050, f5058, f5060, f5068,
        f5070, f5078, f5080, f5088, f5090, f5098, f50A0, f50A8, f50B0, f50B8, f50C0, f50C8, f50D0, f50D8, f50E0, f50E8,
        f50F0, f50F8, f5100, f5108, f5110, f5118, f5120, f5128, f5130, f5138, f5140, f5148, f5150, f5158, f5160, f5168,
        f5170, f5178, f5180, f5188, f5190, f5198, f51A0, f51A8, f51B0, f51B8, f51C0, f51C8, f51D0, f51D8, f51E0, f51E8,
        f51F0, f51F8, f5200, f5208, f5210, f5218, f5220, f5228, f5230, f5238, f5240, f5248, f5250, f5258, f5260, f5268,
        f5270, f5278, f5280, f5288, f5290, f5298, f52A0, f52A8, f52B0, f52B8, f52C0, f52C8, f52D0, f52D8, f52E0, f52E8,
        f52F0, f52F8, f5300, f5308, f5310, f5318, f5320, f5328, f5330, f5338, f5340, f5348, f5350, f5358, f5360, f5368,
        f5370, f5378, f5380, f5388, f5390, f5398, f53A0, f53A8, f53B0, f53B8, f53C0, f53C8, f53D0, f53D8, f53E0, f53E8,
        f53F0, f53F8, f5400, f5408, f5410, f5418, f5420, f5428, f5430, f5438, f5440, f5448, f5450, f5458, f5460, f5468,
        f5470, f5478, f5480, f5488, f5490, f5498, f54A0, f54A8, f54B0, f54B8, f54C0, f54C8, f54D0, f54D8, f54E0, f54E8,
        f54F0, f54F8, f5500, f5508, f5510, f5518, f5520, f5528, f5530, f5538, f5540, f5548, f5550, f5558, f5560, f5568,
        f5570, f5578, f5580, f5588, f5590, f5598, f55A0, f55A8, f55B0, f55B8, f55C0, f55C8, f55D0, f55D8, f55E0, f55E8,
        f55F0, f55F8, f5600, f5608, f5610, f5618, f5620, f5628, f5630, f5638, f5640, f5648, f5650, f5658, f5660, f5668,
        f5670, f5678, f5680, f5688, f5690, f5698, f56A0, f56A8, f56B0, f56B8, f56C0, f56C8, f56D0, f56D8, f56E0, f56E8,
        f56F0, f56F8, f5700, f5708, f5710, f5718, f5720, f5728, f5730, f5738, f5740, f5748, f5750, f5758, f5760, f5768,
        f5770, f5778, f5780, f5788, f5790, f5798, f57A0, f57A8, f57B0, f57B8, f57C0, f57C8, f57D0, f57D8, f57E0, f57E8,
        f57F0, f57F8, f5800, f5808, f5810, f5818, f5820, f5828, f5830, f5838, f5840, f5848, f5850, f5858, f5860, f5868,
        f5870, f5878, f5880, f5888, f5890, f5898, f58A0, f58A8, f58B0, f58B8, f58C0, f58C8, f58D0, f58D8, f58E0, f58E8,
        f58F0, f58F8, f5900, f5908, f5910, f5918, f5920, f5928, f5930, f5938, f5940, f5948, f5950, f5958, f5960, f5968,
        f5970, f5978, f5980, f5988, f5990, f5998, f59A0, f59A8, f59B0, f59B8, f59C0, f59C8, f59D0, f59D8, f59E0, f59E8,
        f59F0, f59F8, f5A00, f5A08, f5A10, f5A18, f5A20, f5A28, f5A30, f5A38, f5A40, f5A48, f5A50, f5A58, f5A60, f5A68,
        f5A70, f5A78, f5A80, f5A88, f5A90, f5A98, f5AA0, f5AA8, f5AB0, f5AB8, f5AC0, f5AC8, f5AD0, f5AD8, f5AE0, f5AE8,
        f5AF0, f5AF8, f5B00, f5B08, f5B10, f5B18, f5B20, f5B28, f5B30, f5B38, f5B40, f5B48, f5B50, f5B58, f5B60, f5B68,
        f5B70, f5B78, f5B80, f5B88, f5B90, f5B98, f5BA0, f5BA8, f5BB0, f5BB8, f5BC0, f5BC8, f5BD0, f5BD8, f5BE0, f5BE8,
        f5BF0, f5BF8, f5C00, f5C08, f5C10, f5C18, f5C20, f5C28, f5C30, f5C38, f5C40, f5C48, f5C50, f5C58, f5C60, f5C68,
        f5C70, f5C78, f5C80, f5C88, f5C90, f5C98, f5CA0, f5CA8, f5CB0, f5CB8, f5CC0, f5CC8, f5CD0, f5CD8, f5CE0, f5CE8,
        f5CF0, f5CF8, f5D00, f5D08, f5D10, f5D18, f5D20, f5D28, f5D30, f5D38, f5D40, f5D48, f5D50, f5D58, f5D60, f5D68,
        f5D70, f5D78, f5D80, f5D88, f5D90, f5D98, f5DA0, f5DA8, f5DB0, f5DB8, f5DC0, f5DC8, f5DD0, f5DD8, f5DE0, f5DE8,
        f5DF0, f5DF8, f5E00, f5E08, f5E10, f5E18, f5E20, f5E28, f5E30, f5E38, f5E40, f5E48, f5E50, f5E58, f5E60, f5E68,
        f5E70, f5E78, f5E80, f5E88, f5E90, f5E98, f5EA0, f5EA8, f5EB0, f5EB8, f5EC0, f5EC8, f5ED0, f5ED8, f5EE0, f5EE8,
        f5EF0, f5EF8, f5F00, f5F08, f5F10, f5F18, f5F20, f5F28, f5F30, f5F38, f5F40, f5F48, f5F50, f5F58, f5F60, f5F68,
        f5F70, f5F78, f5F80, f5F88, f5F90, f5F98, f5FA0, f5FA8, f5FB0, f5FB8, f5FC0, f5FC8, f5FD0, f5FD8, f5FE0, f5FE8,
        f5FF0, f5FF8, f6000, f6008, f6010, f6018, f6020, f6028, f6030, f6038, f6040, f6048, f6050, f6058, f6060, f6068,
        f6070, f6078, f6080, f6088, f6090, f6098, f60A0, f60A8, f60B0, f60B8, f60C0, f60C8, f60D0, f60D8, f60E0, f60E8,
        f60F0, f60F8, f6100, f6108, f6110, f6118, f6120, f6128, f6130, f6138, f6140, f6148, f6150, f6158, f6160, f6168,
        f6170, f6178, f6180, f6188, f6190, f6198, f61A0, f61A8, f61B0, f61B8, f61C0, f61C8, f61D0, f61D8, f61E0, f61E8,
        f61F0, f61F8, f6200, f6208, f6210, f6218, f6220, f6228, f6230, f6238, f6240, f6248, f6250, f6258, f6260, f6268,
        f6270, f6278, f6280, f6288, f6290, f6298, f62A0, f62A8, f62B0, f62B8, f62C0, f62C8, f62D0, f62D8, f62E0, f62E8,
        f62F0, f62F8, f6300, f6308, f6310, f6318, f6320, f6328, f6330, f6338, f6340, f6348, f6350, f6358, f6360, f6368,
        f6370, f6378, f6380, f6388, f6390, f6398, f63A0, f63A8, f63B0, f63B8, f63C0, f63C8, f63D0, f63D8, f63E0, f63E8,
        f63F0, f63F8, f6400, f6408, f6410, f6418, f6420, f6428, f6430, f6438, f6440, f6448, f6450, f6458, f6460, f6468,
        f6470, f6478, f6480, f6488, f6490, f6498, f64A0, f64A8, f64B0, f64B8, f64C0, f64C8, f64D0, f64D8, f64E0, f64E8,
        f64F0, f64F8, f6500, f6508, f6510, f6518, f6520, f6528, f6530, f6538, f6540, f6548, f6550, f6558, f6560, f6568,
        f6570, f6578, f6580, f6588, f6590, f6598, f65A0, f65A8, f65B0, f65B8, f65C0, f65C8, f65D0, f65D8, f65E0, f65E8,
        f65F0, f65F8, f6600, f6608, f6610, f6618, f6620, f6628, f6630, f6638, f6640, f6648, f6650, f6658, f6660, f6668,
        f6670, f6678, f6680, f6688, f6690, f6698, f66A0, f66A8, f66B0, f66B8, f66C0, f66C8, f66D0, f66D8, f66E0, f66E8,
        f66F0, f66F8, f6700, f6708, f6710, f6718, f6720, f6728, f6730, f6738, f6740, f6748, f6750, f6758, f6760, f6768,
        f6770, f6778, f6780, f6788, f6790, f6798, f67A0, f67A8, f67B0, f67B8, f67C0, f67C8, f67D0, f67D8, f67E0, f67E8,
        f67F0, f67F8, f6800, f6808, f6810, f6818, f6820, f6828, f6830, f6838, f6840, f6848, f6850, f6858, f6860, f6868,
        f6870, f6878, f6880, f6888, f6890, f6898, f68A0, f68A8, f68B0, f68B8, f68C0, f68C8, f68D0, f68D8, f68E0, f68E8,
        f68F0, f68F8, f6900, f6908, f6910, f6918, f6920, f6928, f6930, f6938, f6940, f6948, f6950, f6958, f6960, f6968,
        f6970, f6978, f6980, f6988, f6990, f6998, f69A0, f69A8, f69B0, f69B8, f69C0, f69C8, f69D0, f69D8, f69E0, f69E8,
        f69F0, f69F8, f6A00, f6A08, f6A10, f6A18, f6A20, f6A28, f6A30, f6A38, f6A40, f6A48, f6A50, f6A58, f6A60, f6A68,
        f6A70, f6A78, f6A80, f6A88, f6A90, f6A98, f6AA0, f6AA8, f6AB0, f6AB8, f6AC0, f6AC8, f6AD0, f6AD8, f6AE0, f6AE8,
        f6AF0, f6AF8, f6B00, f6B08, f6B10, f6B18, f6B20, f6B28, f6B30, f6B38, f6B40, f6B48, f6B50, f6B58, f6B60, f6B68,
        f6B70, f6B78, f6B80, f6B88, f6B90, f6B98, f6BA0, f6BA8, f6BB0, f6BB8, f6BC0, f6BC8, f6BD0, f6BD8, f6BE0, f6BE8,
        f6BF0, f6BF8, f6C00, f6C08, f6C10, f6C18, f6C20, f6C28, f6C30, f6C38, f6C40, f6C48, f6C50, f6C58, f6C60, f6C68,
        f6C70, f6C78, f6C80, f6C88, f6C90, f6C98, f6CA0, f6CA8, f6CB0, f6CB8, f6CC0, f6CC8, f6CD0, f6CD8, f6CE0, f6CE8,
        f6CF0, f6CF8, f6D00, f6D08, f6D10, f6D18, f6D20, f6D28, f6D30, f6D38, f6D40, f6D48, f6D50, f6D58, f6D60, f6D68,
        f6D70, f6D78, f6D80, f6D88, f6D90, f6D98, f6DA0, f6DA8, f6DB0, f6DB8, f6DC0, f6DC8, f6DD0, f6DD8, f6DE0, f6DE8,
        f6DF0, f6DF8, f6E00, f6E08, f6E10, f6E18, f6E20, f6E28, f6E30, f6E38, f6E40, f6E48, f6E50, f6E58, f6E60, f6E68,
        f6E70, f6E78, f6E80, f6E88, f6E90, f6E98, f6EA0, f6EA8, f6EB0, f6EB8, f6EC0, f6EC8, f6ED0, f6ED8, f6EE0, f6EE8,
        f6EF0, f6EF8, f6F00, f6F08, f6F10, f6F18, f6F20, f6F28, f6F30, f6F38, f6F40, f6F48, f6F50, f6F58, f6F60, f6F68,
        f6F70, f6F78, f6F80, f6F88, f6F90, f6F98, f6FA0, f6FA8, f6FB0, f6FB8, f6FC0, f6FC8, f6FD0, f6FD8, f6FE0, f6FE8,
        f6FF0, f6FF8, f7000, f7008, f7010, f7018, f7020, f7028, f7030, f7038, f7040, f7048, f7050, f7058, f7060, f7068,
        f7070, f7078, f7080, f7088, f7090, f7098, f70A0, f70A8, f70B0, f70B8, f70C0, f70C8, f70D0, f70D8, f70E0, f70E8,
        f70F0, f70F8, f7100, f7108, f7110, f7118, f7120, f7128, f7130, f7138, f7140, f7148, f7150, f7158, f7160, f7168,
        f7170, f7178, f7180, f7188, f7190, f7198, f71A0, f71A8, f71B0, f71B8, f71C0, f71C8, f71D0, f71D8, f71E0, f71E8,
        f71F0, f71F8, f7200, f7208, f7210, f7218, f7220, f7228, f7230, f7238, f7240, f7248, f7250, f7258, f7260, f7268,
        f7270, f7278, f7280, f7288, f7290, f7298, f72A0, f72A8, f72B0, f72B8, f72C0, f72C8, f72D0, f72D8, f72E0, f72E8,
        f72F0, f72F8, f7300, f7308, f7310, f7318, f7320, f7328, f7330, f7338, f7340, f7348, f7350, f7358, f7360, f7368,
        f7370, f7378, f7380, f7388, f7390, f7398, f73A0, f73A8, f73B0, f73B8, f73C0, f73C8, f73D0, f73D8, f73E0, f73E8,
        f73F0, f73F8, f7400, f7408, f7410, f7418, f7420, f7428, f7430, f7438, f7440, f7448, f7450, f7458, f7460, f7468,
        f7470, f7478, f7480, f7488, f7490, f7498, f74A0, f74A8, f74B0, f74B8, f74C0, f74C8, f74D0, f74D8, f74E0, f74E8,
        f74F0, f74F8, f7500, f7508, f7510, f7518, f7520, f7528, f7530, f7538, f7540, f7548, f7550, f7558, f7560, f7568,
        f7570, f7578, f7580, f7588, f7590, f7598, f75A0, f75A8, f75B0, f75B8, f75C0, f75C8, f75D0, f75D8, f75E0, f75E8,
        f75F0, f75F8, f7600, f7608, f7610, f7618, f7620, f7628, f7630, f7638, f7640, f7648, f7650, f7658, f7660, f7668,
        f7670, f7678, f7680, f7688, f7690, f7698, f76A0, f76A8, f76B0, f76B8, f76C0, f76C8, f76D0, f76D8, f76E0, f76E8,
        f76F0, f76F8, f7700, f7708, f7710, f7718, f7720, f7728, f7730, f7738, f7740, f7748, f7750, f7758, f7760, f7768,
        f7770, f7778, f7780, f7788, f7790, f7798, f77A0, f77A8, f77B0, f77B8, f77C0, f77C8, f77D0, f77D8, f77E0, f77E8,
        f77F0, f77F8, f7800, f7808, f7810, f7818, f7820, f7828, f7830, f7838, f7840, f7848, f7850, f7858, f7860, f7868,
        f7870, f7878, f7880, f7888, f7890, f7898, f78A0, f78A8, f78B0, f78B8, f78C0, f78C8, f78D0, f78D8, f78E0, f78E8,
        f78F0, f78F8, f7900, f7908, f7910, f7918, f7920, f7928, f7930, f7938, f7940, f7948, f7950, f7958, f7960, f7968,
        f7970, f7978, f7980, f7988, f7990, f7998, f79A0, f79A8, f79B0, f79B8, f79C0, f79C8, f79D0, f79D8, f79E0, f79E8,
        f79F0, f79F8, f7A00, f7A08, f7A10, f7A18, f7A20, f7A28, f7A30, f7A38, f7A40, f7A48, f7A50, f7A58, f7A60, f7A68,
        f7A70, f7A78, f7A80, f7A88, f7A90, f7A98, f7AA0, f7AA8, f7AB0, f7AB8, f7AC0, f7AC8, f7AD0, f7AD8, f7AE0, f7AE8,
        f7AF0, f7AF8, f7B00, f7B08, f7B10, f7B18, f7B20, f7B28, f7B30, f7B38, f7B40, f7B48, f7B50, f7B58, f7B60, f7B68,
        f7B70, f7B78, f7B80, f7B88, f7B90, f7B98, f7BA0, f7BA8, f7BB0, f7BB8, f7BC0, f7BC8, f7BD0, f7BD8, f7BE0, f7BE8,
        f7BF0, f7BF8, f7C00, f7C08, f7C10, f7C18, f7C20, f7C28, f7C30, f7C38, f7C40, f7C48, f7C50, f7C58, f7C60, f7C68,
        f7C70, f7C78, f7C80, f7C88, f7C90, f7C98, f7CA0, f7CA8, f7CB0, f7CB8, f7CC0, f7CC8, f7CD0, f7CD8, f7CE0, f7CE8,
        f7CF0, f7CF8, f7D00, f7D08, f7D10, f7D18, f7D20, f7D28, f7D30, f7D38, f7D40, f7D48, f7D50, f7D58, f7D60, f7D68,
        f7D70, f7D78, f7D80, f7D88, f7D90, f7D98, f7DA0, f7DA8, f7DB0, f7DB8, f7DC0, f7DC8, f7DD0, f7DD8, f7DE0, f7DE8,
        f7DF0, f7DF8, f7E00, f7E08, f7E10, f7E18, f7E20, f7E28, f7E30, f7E38, f7E40, f7E48, f7E50, f7E58, f7E60, f7E68,
        f7E70, f7E78, f7E80, f7E88, f7E90, f7E98, f7EA0, f7EA8, f7EB0, f7EB8, f7EC0, f7EC8, f7ED0, f7ED8, f7EE0, f7EE8,
        f7EF0, f7EF8, f7F00, f7F08, f7F10, f7F18, f7F20, f7F28, f7F30, f7F38, f7F40, f7F48, f7F50, f7F58, f7F60, f7F68,
        f7F70, f7F78, f7F80, f7F88, f7F90, f7F98, f7FA0, f7FA8, f7FB0, f7FB8, f7FC0, f7FC8, f7FD0, f7FD8, f7FE0, f7FE8,
        f7FF0, f7FF8, f8000, f8008, f8010, f8018, f8020, f8028, f8030, f8038, f8040, f8048, f8050, f8058, f8060, f8068,
        f8070, f8078, f8080, f8088, f8090, f8098, f80A0, f80A8, f80B0, f80B8, f80C0, f80C8, f80D0, f80D8, f80E0, f80E8,
        f80F0, f80F8, f8100, f8108, f8110, f8118, f8120, f8128, f8130, f8138, f8140, f8148, f8150, f8158, f8160, f8168,
        f8170, f8178, f8180, f8188, f8190, f8198, f81A0, f81A8, f81B0, f81B8, f81C0, f81C8, f81D0, f81D8, f81E0, f81E8,
        f81F0, f81F8, f8200, f8208, f8210, f8218, f8220, f8228, f8230, f8238, f8240, f8248, f8250, f8258, f8260, f8268,
        f8270, f8278, f8280, f8288, f8290, f8298, f82A0, f82A8, f82B0, f82B8, f82C0, f82C8, f82D0, f82D8, f82E0, f82E8,
        f82F0, f82F8, f8300, f8308, f8310, f8318, f8320, f8328, f8330, f8338, f8340, f8348, f8350, f8358, f8360, f8368,
        f8370, f8378, f8380, f8388, f8390, f8398, f83A0, f83A8, f83B0, f83B8, f83C0, f83C8, f83D0, f83D8, f83E0, f83E8,
        f83F0, f83F8, f8400, f8408, f8410, f8418, f8420, f8428, f8430, f8438, f8440, f8448, f8450, f8458, f8460, f8468,
        f8470, f8478, f8480, f8488, f8490, f8498, f84A0, f84A8, f84B0, f84B8, f84C0, f84C8, f84D0, f84D8, f84E0, f84E8,
        f84F0, f84F8, f8500, f8508, f8510, f8518, f8520, f8528, f8530, f8538, f8540, f8548, f8550, f8558, f8560, f8568,
        f8570, f8578, f8580, f8588, f8590, f8598, f85A0, f85A8, f85B0, f85B8, f85C0, f85C8, f85D0, f85D8, f85E0, f85E8,
        f85F0, f85F8, f8600, f8608, f8610, f8618, f8620, f8628, f8630, f8638, f8640, f8648, f8650, f8658, f8660, f8668,
        f8670, f8678, f8680, f8688, f8690, f8698, f86A0, f86A8, f86B0, f86B8, f86C0, f86C8, f86D0, f86D8, f86E0, f86E8,
        f86F0, f86F8, f8700, f8708, f8710, f8718, f8720, f8728, f8730, f8738, f8740, f8748, f8750, f8758, f8760, f8768,
        f8770, f8778, f8780, f8788, f8790, f8798, f87A0, f87A8, f87B0, f87B8, f87C0, f87C8, f87D0, f87D8, f87E0, f87E8,
        f87F0, f87F8, f8800, f8808, f8810, f8818, f8820, f8828, f8830, f8838, f8840, f8848, f8850, f8858, f8860, f8868,
        f8870, f8878, f8880, f8888, f8890, f8898, f88A0, f88A8, f88B0, f88B8, f88C0, f88C8, f88D0, f88D8, f88E0, f88E8,
        f88F0, f88F8, f8900, f8908, f8910, f8918, f8920, f8928, f8930, f8938, f8940, f8948, f8950, f8958, f8960, f8968,
        f8970, f8978, f8980, f8988, f8990, f8998, f89A0, f89A8, f89B0, f89B8, f89C0, f89C8, f89D0, f89D8, f89E0, f89E8,
        f89F0, f89F8, f8A00, f8A08, f8A10, f8A18, f8A20, f8A28, f8A30, f8A38, f8A40, f8A48, f8A50, f8A58, f8A60, f8A68,
        f8A70, f8A78, f8A80, f8A88, f8A90, f8A98, f8AA0, f8AA8, f8AB0, f8AB8, f8AC0, f8AC8, f8AD0, f8AD8, f8AE0, f8AE8,
        f8AF0, f8AF8, f8B00, f8B08, f8B10, f8B18, f8B20, f8B28, f8B30, f8B38, f8B40, f8B48, f8B50, f8B58, f8B60, f8B68,
        f8B70, f8B78, f8B80, f8B88, f8B90, f8B98, f8BA0, f8BA8, f8BB0, f8BB8, f8BC0, f8BC8, f8BD0, f8BD8, f8BE0, f8BE8,
        f8BF0, f8BF8, f8C00, f8C08, f8C10, f8C18, f8C20, f8C28, f8C30, f8C38, f8C40, f8C48, f8C50, f8C58, f8C60, f8C68,
        f8C70, f8C78, f8C80, f8C88, f8C90, f8C98, f8CA0, f8CA8, f8CB0, f8CB8, f8CC0, f8CC8, f8CD0, f8CD8, f8CE0, f8CE8,
        f8CF0, f8CF8, f8D00, f8D08, f8D10, f8D18, f8D20, f8D28, f8D30, f8D38, f8D40, f8D48, f8D50, f8D58, f8D60, f8D68,
        f8D70, f8D78, f8D80, f8D88, f8D90, f8D98, f8DA0, f8DA8, f8DB0, f8DB8, f8DC0, f8DC8, f8DD0, f8DD8, f8DE0, f8DE8,
        f8DF0, f8DF8, f8E00, f8E08, f8E10, f8E18, f8E20, f8E28, f8E30, f8E38, f8E40, f8E48, f8E50, f8E58, f8E60, f8E68,
        f8E70, f8E78, f8E80, f8E88, f8E90, f8E98, f8EA0, f8EA8, f8EB0, f8EB8, f8EC0, f8EC8, f8ED0, f8ED8, f8EE0, f8EE8,
        f8EF0, f8EF8, f8F00, f8F08, f8F10, f8F18, f8F20, f8F28, f8F30, f8F38, f8F40, f8F48, f8F50, f8F58, f8F60, f8F68,
        f8F70, f8F78, f8F80, f8F88, f8F90, f8F98, f8FA0, f8FA8, f8FB0, f8FB8, f8FC0, f8FC8, f8FD0, f8FD8, f8FE0, f8FE8,
        f8FF0, f8FF8, f9000, f9008, f9010, f9018, f9020, f9028, f9030, f9038, f9040, f9048, f9050, f9058, f9060, f9068,
        f9070, f9078, f9080, f9088, f9090, f9098, f90A0, f90A8, f90B0, f90B8, f90C0, f90C8, f90D0, f90D8, f90E0, f90E8,
        f90F0, f90F8, f9100, f9108, f9110, f9118, f9120, f9128, f9130, f9138, f9140, f9148, f9150, f9158, f9160, f9168,
        f9170, f9178, f9180, f9188, f9190, f9198, f91A0, f91A8, f91B0, f91B8, f91C0, f91C8, f91D0, f91D8, f91E0, f91E8,
        f91F0, f91F8, f9200, f9208, f9210, f9218, f9220, f9228, f9230, f9238, f9240, f9248, f9250, f9258, f9260, f9268,
        f9270, f9278, f9280, f9288, f9290, f9298, f92A0, f92A8, f92B0, f92B8, f92C0, f92C8, f92D0, f92D8, f92E0, f92E8,
        f92F0, f92F8, f9300, f9308, f9310, f9318, f9320, f9328, f9330, f9338, f9340, f9348, f9350, f9358, f9360, f9368,
        f9370, f9378, f9380, f9388, f9390, f9398, f93A0, f93A8, f93B0, f93B8, f93C0, f93C8, f93D0, f93D8, f93E0, f93E8,
        f93F0, f93F8, f9400, f9408, f9410, f9418, f9420, f9428, f9430, f9438, f9440, f9448, f9450, f9458, f9460, f9468,
        f9470, f9478, f9480, f9488, f9490, f9498, f94A0, f94A8, f94B0, f94B8, f94C0, f94C8, f94D0, f94D8, f94E0, f94E8,
        f94F0, f94F8, f9500, f9508, f9510, f9518, f9520, f9528, f9530, f9538, f9540, f9548, f9550, f9558, f9560, f9568,
        f9570, f9578, f9580, f9588, f9590, f9598, f95A0, f95A8, f95B0, f95B8, f95C0, f95C8, f95D0, f95D8, f95E0, f95E8,
        f95F0, f95F8, f9600, f9608, f9610, f9618, f9620, f9628, f9630, f9638, f9640, f9648, f9650, f9658, f9660, f9668,
        f9670, f9678, f9680, f9688, f9690, f9698, f96A0, f96A8, f96B0, f96B8, f96C0, f96C8, f96D0, f96D8, f96E0, f96E8,
        f96F0, f96F8, f9700, f9708, f9710, f9718, f9720, f9728, f9730, f9738, f9740, f9748, f9750, f9758, f9760, f9768,
        f9770, f9778, f9780, f9788, f9790, f9798, f97A0, f97A8, f97B0, f97B8, f97C0, f97C8, f97D0, f97D8, f97E0, f97E8,
        f97F0, f97F8, f9800, f9808, f9810, f9818, f9820, f9828, f9830, f9838, f9840, f9848, f9850, f9858, f9860, f9868,
        f9870, f9878, f9880, f9888, f9890, f9898, f98A0, f98A8, f98B0, f98B8, f98C0, f98C8, f98D0, f98D8, f98E0, f98E8,
        f98F0, f98F8, f9900, f9908, f9910, f9918, f9920, f9928, f9930, f9938, f9940, f9948, f9950, f9958, f9960, f9968,
        f9970, f9978, f9980, f9988, f9990, f9998, f99A0, f99A8, f99B0, f99B8, f99C0, f99C8, f99D0, f99D8, f99E0, f99E8,
        f99F0, f99F8, f9A00, f9A08, f9A10, f9A18, f9A20, f9A28, f9A30, f9A38, f9A40, f9A48, f9A50, f9A58, f9A60, f9A68,
        f9A70, f9A78, f9A80, f9A88, f9A90, f9A98, f9AA0, f9AA8, f9AB0, f9AB8, f9AC0, f9AC8, f9AD0, f9AD8, f9AE0, f9AE8,
        f9AF0, f9AF8, f9B00, f9B08, f9B10, f9B18, f9B20, f9B28, f9B30, f9B38, f9B40, f9B48, f9B50, f9B58, f9B60, f9B68,
        f9B70, f9B78, f9B80, f9B88, f9B90, f9B98, f9BA0, f9BA8, f9BB0, f9BB8, f9BC0, f9BC8, f9BD0, f9BD8, f9BE0, f9BE8,
        f9BF0, f9BF8, f9C00, f9C08, f9C10, f9C18, f9C20, f9C28, f9C30, f9C38, f9C40, f9C48, f9C50, f9C58, f9C60, f9C68,
        f9C70, f9C78, f9C80, f9C88, f9C90, f9C98, f9CA0, f9CA8, f9CB0, f9CB8, f9CC0, f9CC8, f9CD0, f9CD8, f9CE0, f9CE8,
        f9CF0, f9CF8, f9D00, f9D08, f9D10, f9D18, f9D20, f9D28, f9D30, f9D38, f9D40, f9D48, f9D50, f9D58, f9D60, f9D68,
        f9D70, f9D78, f9D80, f9D88, f9D90, f9D98, f9DA0, f9DA8, f9DB0, f9DB8, f9DC0, f9DC8, f9DD0, f9DD8, f9DE0, f9DE8,
        f9DF0, f9DF8, f9E00, f9E08, f9E10, f9E18, f9E20, f9E28, f9E30, f9E38, f9E40, f9E48, f9E50, f9E58, f9E60, f9E68,
        f9E70, f9E78, f9E80, f9E88, f9E90, f9E98, f9EA0, f9EA8, f9EB0, f9EB8, f9EC0, f9EC8, f9ED0, f9ED8, f9EE0, f9EE8,
        f9EF0, f9EF8, f9F00, f9F08, f9F10, f9F18, f9F20, f9F28, f9F30, f9F38, f9F40, f9F48, f9F50, f9F58, f9F60, f9F68,
        f9F70, f9F78, f9F80, f9F88, f9F90, f9F98, f9FA0, f9FA8, f9FB0, f9FB8, f9FC0, f9FC8, f9FD0, f9FD8, f9FE0, f9FE8,
        f9FF0, f9FF8, fA000, fA008, fA010, fA018, fA020, fA028, fA030, fA038, fA040, fA048, fA050, fA058, fA060, fA068,
        fA070, fA078, fA080, fA088, fA090, fA098, fA0A0, fA0A8, fA0B0, fA0B8, fA0C0, fA0C8, fA0D0, fA0D8, fA0E0, fA0E8,
        fA0F0, fA0F8, fA100, fA108, fA110, fA118, fA120, fA128, fA130, fA138, fA140, fA148, fA150, fA158, fA160, fA168,
        fA170, fA178, fA180, fA188, fA190, fA198, fA1A0, fA1A8, fA1B0, fA1B8, fA1C0, fA1C8, fA1D0, fA1D8, fA1E0, fA1E8,
        fA1F0, fA1F8, fA200, fA208, fA210, fA218, fA220, fA228, fA230, fA238, fA240, fA248, fA250, fA258, fA260, fA268,
        fA270, fA278, fA280, fA288, fA290, fA298, fA2A0, fA2A8, fA2B0, fA2B8, fA2C0, fA2C8, fA2D0, fA2D8, fA2E0, fA2E8,
        fA2F0, fA2F8, fA300, fA308, fA310, fA318, fA320, fA328, fA330, fA338, fA340, fA348, fA350, fA358, fA360, fA368,
        fA370, fA378, fA380, fA388, fA390, fA398, fA3A0, fA3A8, fA3B0, fA3B8, fA3C0, fA3C8, fA3D0, fA3D8, fA3E0, fA3E8,
        fA3F0, fA3F8, fA400, fA408, fA410, fA418, fA420, fA428, fA430, fA438, fA440, fA448, fA450, fA458, fA460, fA468,
        fA470, fA478, fA480, fA488, fA490, fA498, fA4A0, fA4A8, fA4B0, fA4B8, fA4C0, fA4C8, fA4D0, fA4D8, fA4E0, fA4E8,
        fA4F0, fA4F8, fA500, fA508, fA510, fA518, fA520, fA528, fA530, fA538, fA540, fA548, fA550, fA558, fA560, fA568,
        fA570, fA578, fA580, fA588, fA590, fA598, fA5A0, fA5A8, fA5B0, fA5B8, fA5C0, fA5C8, fA5D0, fA5D8, fA5E0, fA5E8,
        fA5F0, fA5F8, fA600, fA608, fA610, fA618, fA620, fA628, fA630, fA638, fA640, fA648, fA650, fA658, fA660, fA668,
        fA670, fA678, fA680, fA688, fA690, fA698, fA6A0, fA6A8, fA6B0, fA6B8, fA6C0, fA6C8, fA6D0, fA6D8, fA6E0, fA6E8,
        fA6F0, fA6F8, fA700, fA708, fA710, fA718, fA720, fA728, fA730, fA738, fA740, fA748, fA750, fA758, fA760, fA768,
        fA770, fA778, fA780, fA788, fA790, fA798, fA7A0, fA7A8, fA7B0, fA7B8, fA7C0, fA7C8, fA7D0, fA7D8, fA7E0, fA7E8,
        fA7F0, fA7F8, fA800, fA808, fA810, fA818, fA820, fA828, fA830, fA838, fA840, fA848, fA850, fA858, fA860, fA868,
        fA870, fA878, fA880, fA888, fA890, fA898, fA8A0, fA8A8, fA8B0, fA8B8, fA8C0, fA8C8, fA8D0, fA8D8, fA8E0, fA8E8,
        fA8F0, fA8F8, fA900, fA908, fA910, fA918, fA920, fA928, fA930, fA938, fA940, fA948, fA950, fA958, fA960, fA968,
        fA970, fA978, fA980, fA988, fA990, fA998, fA9A0, fA9A8, fA9B0, fA9B8, fA9C0, fA9C8, fA9D0, fA9D8, fA9E0, fA9E8,
        fA9F0, fA9F8, fAA00, fAA08, fAA10, fAA18, fAA20, fAA28, fAA30, fAA38, fAA40, fAA48, fAA50, fAA58, fAA60, fAA68,
        fAA70, fAA78, fAA80, fAA88, fAA90, fAA98, fAAA0, fAAA8, fAAB0, fAAB8, fAAC0, fAAC8, fAAD0, fAAD8, fAAE0, fAAE8,
        fAAF0, fAAF8, fAB00, fAB08, fAB10, fAB18, fAB20, fAB28, fAB30, fAB38, fAB40, fAB48, fAB50, fAB58, fAB60, fAB68,
        fAB70, fAB78, fAB80, fAB88, fAB90, fAB98, fABA0, fABA8, fABB0, fABB8, fABC0, fABC8, fABD0, fABD8, fABE0, fABE8,
        fABF0, fABF8, fAC00, fAC08, fAC10, fAC18, fAC20, fAC28, fAC30, fAC38, fAC40, fAC48, fAC50, fAC58, fAC60, fAC68,
        fAC70, fAC78, fAC80, fAC88, fAC90, fAC98, fACA0, fACA8, fACB0, fACB8, fACC0, fACC8, fACD0, fACD8, fACE0, fACE8,
        fACF0, fACF8, fAD00, fAD08, fAD10, fAD18, fAD20, fAD28, fAD30, fAD38, fAD40, fAD48, fAD50, fAD58, fAD60, fAD68,
        fAD70, fAD78, fAD80, fAD88, fAD90, fAD98, fADA0, fADA8, fADB0, fADB8, fADC0, fADC8, fADD0, fADD8, fADE0, fADE8,
        fADF0, fADF8, fAE00, fAE08, fAE10, fAE18, fAE20, fAE28, fAE30, fAE38, fAE40, fAE48, fAE50, fAE58, fAE60, fAE68,
        fAE70, fAE78, fAE80, fAE88, fAE90, fAE98, fAEA0, fAEA8, fAEB0, fAEB8, fAEC0, fAEC8, fAED0, fAED8, fAEE0, fAEE8,
        fAEF0, fAEF8, fAF00, fAF08, fAF10, fAF18, fAF20, fAF28, fAF30, fAF38, fAF40, fAF48, fAF50, fAF58, fAF60, fAF68,
        fAF70, fAF78, fAF80, fAF88, fAF90, fAF98, fAFA0, fAFA8, fAFB0, fAFB8, fAFC0, fAFC8, fAFD0, fAFD8, fAFE0, fAFE8,
        fAFF0, fAFF8, fB000, fB008, fB010, fB018, fB020, fB028, fB030, fB038, fB040, fB048, fB050, fB058, fB060, fB068,
        fB070, fB078, fB080, fB088, fB090, fB098, fB0A0, fB0A8, fB0B0, fB0B8, fB0C0, fB0C8, fB0D0, fB0D8, fB0E0, fB0E8,
        fB0F0, fB0F8, fB100, fB108, fB110, fB118, fB120, fB128, fB130, fB138, fB140, fB148, fB150, fB158, fB160, fB168,
        fB170, fB178, fB180, fB188, fB190, fB198, fB1A0, fB1A8, fB1B0, fB1B8, fB1C0, fB1C8, fB1D0, fB1D8, fB1E0, fB1E8,
        fB1F0, fB1F8, fB200, fB208, fB210, fB218, fB220, fB228, fB230, fB238, fB240, fB248, fB250, fB258, fB260, fB268,
        fB270, fB278, fB280, fB288, fB290, fB298, fB2A0, fB2A8, fB2B0, fB2B8, fB2C0, fB2C8, fB2D0, fB2D8, fB2E0, fB2E8,
        fB2F0, fB2F8, fB300, fB308, fB310, fB318, fB320, fB328, fB330, fB338, fB340, fB348, fB350, fB358, fB360, fB368,
        fB370, fB378, fB380, fB388, fB390, fB398, fB3A0, fB3A8, fB3B0, fB3B8, fB3C0, fB3C8, fB3D0, fB3D8, fB3E0, fB3E8,
        fB3F0, fB3F8, fB400, fB408, fB410, fB418, fB420, fB428, fB430, fB438, fB440, fB448, fB450, fB458, fB460, fB468,
        fB470, fB478, fB480, fB488, fB490, fB498, fB4A0, fB4A8, fB4B0, fB4B8, fB4C0, fB4C8, fB4D0, fB4D8, fB4E0, fB4E8,
        fB4F0, fB4F8, fB500, fB508, fB510, fB518, fB520, fB528, fB530, fB538, fB540, fB548, fB550, fB558, fB560, fB568,
        fB570, fB578, fB580, fB588, fB590, fB598, fB5A0, fB5A8, fB5B0, fB5B8, fB5C0, fB5C8, fB5D0, fB5D8, fB5E0, fB5E8,
        fB5F0, fB5F8, fB600, fB608, fB610, fB618, fB620, fB628, fB630, fB638, fB640, fB648, fB650, fB658, fB660, fB668,
        fB670, fB678, fB680, fB688, fB690, fB698, fB6A0, fB6A8, fB6B0, fB6B8, fB6C0, fB6C8, fB6D0, fB6D8, fB6E0, fB6E8,
        fB6F0, fB6F8, fB700, fB708, fB710, fB718, fB720, fB728, fB730, fB738, fB740, fB748, fB750, fB758, fB760, fB768,
        fB770, fB778, fB780, fB788, fB790, fB798, fB7A0, fB7A8, fB7B0, fB7B8, fB7C0, fB7C8, fB7D0, fB7D8, fB7E0, fB7E8,
        fB7F0, fB7F8, fB800, fB808, fB810, fB818, fB820, fB828, fB830, fB838, fB840, fB848, fB850, fB858, fB860, fB868,
        fB870, fB878, fB880, fB888, fB890, fB898, fB8A0, fB8A8, fB8B0, fB8B8, fB8C0, fB8C8, fB8D0, fB8D8, fB8E0, fB8E8,
        fB8F0, fB8F8, fB900, fB908, fB910, fB918, fB920, fB928, fB930, fB938, fB940, fB948, fB950, fB958, fB960, fB968,
        fB970, fB978, fB980, fB988, fB990, fB998, fB9A0, fB9A8, fB9B0, fB9B8, fB9C0, fB9C8, fB9D0, fB9D8, fB9E0, fB9E8,
        fB9F0, fB9F8, fBA00, fBA08, fBA10, fBA18, fBA20, fBA28, fBA30, fBA38, fBA40, fBA48, fBA50, fBA58, fBA60, fBA68,
        fBA70, fBA78, fBA80, fBA88, fBA90, fBA98, fBAA0, fBAA8, fBAB0, fBAB8, fBAC0, fBAC8, fBAD0, fBAD8, fBAE0, fBAE8,
        fBAF0, fBAF8, fBB00, fBB08, fBB10, fBB18, fBB20, fBB28, fBB30, fBB38, fBB40, fBB48, fBB50, fBB58, fBB60, fBB68,
        fBB70, fBB78, fBB80, fBB88, fBB90, fBB98, fBBA0, fBBA8, fBBB0, fBBB8, fBBC0, fBBC8, fBBD0, fBBD8, fBBE0, fBBE8,
        fBBF0, fBBF8, fBC00, fBC08, fBC10, fBC18, fBC20, fBC28, fBC30, fBC38, fBC40, fBC48, fBC50, fBC58, fBC60, fBC68,
        fBC70, fBC78, fBC80, fBC88, fBC90, fBC98, fBCA0, fBCA8, fBCB0, fBCB8, fBCC0, fBCC8, fBCD0, fBCD8, fBCE0, fBCE8,
        fBCF0, fBCF8, fBD00, fBD08, fBD10, fBD18, fBD20, fBD28, fBD30, fBD38, fBD40, fBD48, fBD50, fBD58, fBD60, fBD68,
        fBD70, fBD78, fBD80, fBD88, fBD90, fBD98, fBDA0, fBDA8, fBDB0, fBDB8, fBDC0, fBDC8, fBDD0, fBDD8, fBDE0, fBDE8,
        fBDF0, fBDF8, fBE00, fBE08, fBE10, fBE18, fBE20, fBE28, fBE30, fBE38, fBE40, fBE48, fBE50, fBE58, fBE60, fBE68,
        fBE70, fBE78, fBE80, fBE88, fBE90, fBE98, fBEA0, fBEA8, fBEB0, fBEB8, fBEC0, fBEC8, fBED0, fBED8, fBEE0, fBEE8,
        fBEF0, fBEF8, fBF00, fBF08, fBF10, fBF18, fBF20, fBF28, fBF30, fBF38, fBF40, fBF48, fBF50, fBF58, fBF60, fBF68,
        fBF70, fBF78, fBF80, fBF88, fBF90, fBF98, fBFA0, fBFA8, fBFB0, fBFB8, fBFC0, fBFC8, fBFD0, fBFD8, fBFE0, fBFE8,
        fBFF0, fBFF8, fC000, fC008, fC010, fC018, fC020, fC028, fC030, fC038, fC040, fC048, fC050, fC058, fC060, fC068,
        fC070, fC078, fC080, fC088, fC090, fC098, fC0A0, fC0A8, fC0B0, fC0B8, fC0C0, fC0C8, fC0D0, fC0D8, fC0E0, fC0E8,
        fC0F0, fC0F8, fC100, fC108, fC110, fC118, fC120, fC128, fC130, fC138, fC140, fC148, fC150, fC158, fC160, fC168,
        fC170, fC178, fC180, fC188, fC190, fC198, fC1A0, fC1A8, fC1B0, fC1B8, fC1C0, fC1C8, fC1D0, fC1D8, fC1E0, fC1E8,
        fC1F0, fC1F8, fC200, fC208, fC210, fC218, fC220, fC228, fC230, fC238, fC240, fC248, fC250, fC258, fC260, fC268,
        fC270, fC278, fC280, fC288, fC290, fC298, fC2A0, fC2A8, fC2B0, fC2B8, fC2C0, fC2C8, fC2D0, fC2D8, fC2E0, fC2E8,
        fC2F0, fC2F8, fC300, fC308, fC310, fC318, fC320, fC328, fC330, fC338, fC340, fC348, fC350, fC358, fC360, fC368,
        fC370, fC378, fC380, fC388, fC390, fC398, fC3A0, fC3A8, fC3B0, fC3B8, fC3C0, fC3C8, fC3D0, fC3D8, fC3E0, fC3E8,
        fC3F0, fC3F8, fC400, fC408, fC410, fC418, fC420, fC428, fC430, fC438, fC440, fC448, fC450, fC458, fC460, fC468,
        fC470, fC478, fC480, fC488, fC490, fC498, fC4A0, fC4A8, fC4B0, fC4B8, fC4C0, fC4C8, fC4D0, fC4D8, fC4E0, fC4E8,
        fC4F0, fC4F8, fC500, fC508, fC510, fC518, fC520, fC528, fC530, fC538, fC540, fC548, fC550, fC558, fC560, fC568,
        fC570, fC578, fC580, fC588, fC590, fC598, fC5A0, fC5A8, fC5B0, fC5B8, fC5C0, fC5C8, fC5D0, fC5D8, fC5E0, fC5E8,
        fC5F0, fC5F8, fC600, fC608, fC610, fC618, fC620, fC628, fC630, fC638, fC640, fC648, fC650, fC658, fC660, fC668,
        fC670, fC678, fC680, fC688, fC690, fC698, fC6A0, fC6A8, fC6B0, fC6B8, fC6C0, fC6C8, fC6D0, fC6D8, fC6E0, fC6E8,
        fC6F0, fC6F8, fC700, fC708, fC710, fC718, fC720, fC728, fC730, fC738, fC740, fC748, fC750, fC758, fC760, fC768,
        fC770, fC778, fC780, fC788, fC790, fC798, fC7A0, fC7A8, fC7B0, fC7B8, fC7C0, fC7C8, fC7D0, fC7D8, fC7E0, fC7E8,
        fC7F0, fC7F8, fC800, fC808, fC810, fC818, fC820, fC828, fC830, fC838, fC840, fC848, fC850, fC858, fC860, fC868,
        fC870, fC878, fC880, fC888, fC890, fC898, fC8A0, fC8A8, fC8B0, fC8B8, fC8C0, fC8C8, fC8D0, fC8D8, fC8E0, fC8E8,
        fC8F0, fC8F8, fC900, fC908, fC910, fC918, fC920, fC928, fC930, fC938, fC940, fC948, fC950, fC958, fC960, fC968,
        fC970, fC978, fC980, fC988, fC990, fC998, fC9A0, fC9A8, fC9B0, fC9B8, fC9C0, fC9C8, fC9D0, fC9D8, fC9E0, fC9E8,
        fC9F0, fC9F8, fCA00, fCA08, fCA10, fCA18, fCA20, fCA28, fCA30, fCA38, fCA40, fCA48, fCA50, fCA58, fCA60, fCA68,
        fCA70, fCA78, fCA80, fCA88, fCA90, fCA98, fCAA0, fCAA8, fCAB0, fCAB8, fCAC0, fCAC8, fCAD0, fCAD8, fCAE0, fCAE8,
        fCAF0, fCAF8, fCB00, fCB08, fCB10, fCB18, fCB20, fCB28, fCB30, fCB38, fCB40, fCB48, fCB50, fCB58, fCB60, fCB68,
        fCB70, fCB78, fCB80, fCB88, fCB90, fCB98, fCBA0, fCBA8, fCBB0, fCBB8, fCBC0, fCBC8, fCBD0, fCBD8, fCBE0, fCBE8,
        fCBF0, fCBF8, fCC00, fCC08, fCC10, fCC18, fCC20, fCC28, fCC30, fCC38, fCC40, fCC48, fCC50, fCC58, fCC60, fCC68,
        fCC70, fCC78, fCC80, fCC88, fCC90, fCC98, fCCA0, fCCA8, fCCB0, fCCB8, fCCC0, fCCC8, fCCD0, fCCD8, fCCE0, fCCE8,
        fCCF0, fCCF8, fCD00, fCD08, fCD10, fCD18, fCD20, fCD28, fCD30, fCD38, fCD40, fCD48, fCD50, fCD58, fCD60, fCD68,
        fCD70, fCD78, fCD80, fCD88, fCD90, fCD98, fCDA0, fCDA8, fCDB0, fCDB8, fCDC0, fCDC8, fCDD0, fCDD8, fCDE0, fCDE8,
        fCDF0, fCDF8, fCE00, fCE08, fCE10, fCE18, fCE20, fCE28, fCE30, fCE38, fCE40, fCE48, fCE50, fCE58, fCE60, fCE68,
        fCE70, fCE78, fCE80, fCE88, fCE90, fCE98, fCEA0, fCEA8, fCEB0, fCEB8, fCEC0, fCEC8, fCED0, fCED8, fCEE0, fCEE8,
        fCEF0, fCEF8, fCF00, fCF08, fCF10, fCF18, fCF20, fCF28, fCF30, fCF38, fCF40, fCF48, fCF50, fCF58, fCF60, fCF68,
        fCF70, fCF78, fCF80, fCF88, fCF90, fCF98, fCFA0, fCFA8, fCFB0, fCFB8, fCFC0, fCFC8, fCFD0, fCFD8, fCFE0, fCFE8,
        fCFF0, fCFF8, fD000, fD008, fD010, fD018, fD020, fD028, fD030, fD038, fD040, fD048, fD050, fD058, fD060, fD068,
        fD070, fD078, fD080, fD088, fD090, fD098, fD0A0, fD0A8, fD0B0, fD0B8, fD0C0, fD0C8, fD0D0, fD0D8, fD0E0, fD0E8,
        fD0F0, fD0F8, fD100, fD108, fD110, fD118, fD120, fD128, fD130, fD138, fD140, fD148, fD150, fD158, fD160, fD168,
        fD170, fD178, fD180, fD188, fD190, fD198, fD1A0, fD1A8, fD1B0, fD1B8, fD1C0, fD1C8, fD1D0, fD1D8, fD1E0, fD1E8,
        fD1F0, fD1F8, fD200, fD208, fD210, fD218, fD220, fD228, fD230, fD238, fD240, fD248, fD250, fD258, fD260, fD268,
        fD270, fD278, fD280, fD288, fD290, fD298, fD2A0, fD2A8, fD2B0, fD2B8, fD2C0, fD2C8, fD2D0, fD2D8, fD2E0, fD2E8,
        fD2F0, fD2F8, fD300, fD308, fD310, fD318, fD320, fD328, fD330, fD338, fD340, fD348, fD350, fD358, fD360, fD368,
        fD370, fD378, fD380, fD388, fD390, fD398, fD3A0, fD3A8, fD3B0, fD3B8, fD3C0, fD3C8, fD3D0, fD3D8, fD3E0, fD3E8,
        fD3F0, fD3F8, fD400, fD408, fD410, fD418, fD420, fD428, fD430, fD438, fD440, fD448, fD450, fD458, fD460, fD468,
        fD470, fD478, fD480, fD488, fD490, fD498, fD4A0, fD4A8, fD4B0, fD4B8, fD4C0, fD4C8, fD4D0, fD4D8, fD4E0, fD4E8,
        fD4F0, fD4F8, fD500, fD508, fD510, fD518, fD520, fD528, fD530, fD538, fD540, fD548, fD550, fD558, fD560, fD568,
        fD570, fD578, fD580, fD588, fD590, fD598, fD5A0, fD5A8, fD5B0, fD5B8, fD5C0, fD5C8, fD5D0, fD5D8, fD5E0, fD5E8,
        fD5F0, fD5F8, fD600, fD608, fD610, fD618, fD620, fD628, fD630, fD638, fD640, fD648, fD650, fD658, fD660, fD668,
        fD670, fD678, fD680, fD688, fD690, fD698, fD6A0, fD6A8, fD6B0, fD6B8, fD6C0, fD6C8, fD6D0, fD6D8, fD6E0, fD6E8,
        fD6F0, fD6F8, fD700, fD708, fD710, fD718, fD720, fD728, fD730, fD738, fD740, fD748, fD750, fD758, fD760, fD768,
        fD770, fD778, fD780, fD788, fD790, fD798, fD7A0, fD7A8, fD7B0, fD7B8, fD7C0, fD7C8, fD7D0, fD7D8, fD7E0, fD7E8,
        fD7F0, fD7F8, fD800, fD808, fD810, fD818, fD820, fD828, fD830, fD838, fD840, fD848, fD850, fD858, fD860, fD868,
        fD870, fD878, fD880, fD888, fD890, fD898, fD8A0, fD8A8, fD8B0, fD8B8, fD8C0, fD8C8, fD8D0, fD8D8, fD8E0, fD8E8,
        fD8F0, fD8F8, fD900, fD908, fD910, fD918, fD920, fD928, fD930, fD938, fD940, fD948, fD950, fD958, fD960, fD968,
        fD970, fD978, fD980, fD988, fD990, fD998, fD9A0, fD9A8, fD9B0, fD9B8, fD9C0, fD9C8, fD9D0, fD9D8, fD9E0, fD9E8,
        fD9F0, fD9F8, fDA00, fDA08, fDA10, fDA18, fDA20, fDA28, fDA30, fDA38, fDA40, fDA48, fDA50, fDA58, fDA60, fDA68,
        fDA70, fDA78, fDA80, fDA88, fDA90, fDA98, fDAA0, fDAA8, fDAB0, fDAB8, fDAC0, fDAC8, fDAD0, fDAD8, fDAE0, fDAE8,
        fDAF0, fDAF8, fDB00, fDB08, fDB10, fDB18, fDB20, fDB28, fDB30, fDB38, fDB40, fDB48, fDB50, fDB58, fDB60, fDB68,
        fDB70, fDB78, fDB80, fDB88, fDB90, fDB98, fDBA0, fDBA8, fDBB0, fDBB8, fDBC0, fDBC8, fDBD0, fDBD8, fDBE0, fDBE8,
        fDBF0, fDBF8, fDC00, fDC08, fDC10, fDC18, fDC20, fDC28, fDC30, fDC38, fDC40, fDC48, fDC50, fDC58, fDC60, fDC68,
        fDC70, fDC78, fDC80, fDC88, fDC90, fDC98, fDCA0, fDCA8, fDCB0, fDCB8, fDCC0, fDCC8, fDCD0, fDCD8, fDCE0, fDCE8,
        fDCF0, fDCF8, fDD00, fDD08, fDD10, fDD18, fDD20, fDD28, fDD30, fDD38, fDD40, fDD48, fDD50, fDD58, fDD60, fDD68,
        fDD70, fDD78, fDD80, fDD88, fDD90, fDD98, fDDA0, fDDA8, fDDB0, fDDB8, fDDC0, fDDC8, fDDD0, fDDD8, fDDE0, fDDE8,
        fDDF0, fDDF8, fDE00, fDE08, fDE10, fDE18, fDE20, fDE28, fDE30, fDE38, fDE40, fDE48, fDE50, fDE58, fDE60, fDE68,
        fDE70, fDE78, fDE80, fDE88, fDE90, fDE98, fDEA0, fDEA8, fDEB0, fDEB8, fDEC0, fDEC8, fDED0, fDED8, fDEE0, fDEE8,
        fDEF0, fDEF8, fDF00, fDF08, fDF10, fDF18, fDF20, fDF28, fDF30, fDF38, fDF40, fDF48, fDF50, fDF58, fDF60, fDF68,
        fDF70, fDF78, fDF80, fDF88, fDF90, fDF98, fDFA0, fDFA8, fDFB0, fDFB8, fDFC0, fDFC8, fDFD0, fDFD8, fDFE0, fDFE8,
        fDFF0, fDFF8, fE000, fE008, fE010, fE018, fE020, fE028, fE030, fE038, fE040, fE048, fE050, fE058, fE060, fE068,
        fE070, fE078, fE080, fE088, fE090, fE098, fE0A0, fE0A8, fE0B0, fE0B8, fE0C0, fE0C8, fE0D0, fE0D8, fE0E0, fE0E8,
        fE0F0, fE0F8, fE100, fE108, fE110, fE118, fE120, fE128, fE130, fE138, fE140, fE148, fE150, fE158, fE160, fE168,
        fE170, fE178, fE180, fE188, fE190, fE198, fE1A0, fE1A8, fE1B0, fE1B8, fE1C0, fE1C8, fE1D0, fE1D8, fE1E0, fE1E8,
        fE1F0, fE1F8, fE200, fE208, fE210, fE218, fE220, fE228, fE230, fE238, fE240, fE248, fE250, fE258, fE260, fE268,
        fE270, fE278, fE280, fE288, fE290, fE298, fE2A0, fE2A8, fE2B0, fE2B8, fE2C0, fE2C8, fE2D0, fE2D8, fE2E0, fE2E8,
        fE2F0, fE2F8, fE300, fE308, fE310, fE318, fE320, fE328, fE330, fE338, fE340, fE348, fE350, fE358, fE360, fE368,
        fE370, fE378, fE380, fE388, fE390, fE398, fE3A0, fE3A8, fE3B0, fE3B8, fE3C0, fE3C8, fE3D0, fE3D8, fE3E0, fE3E8,
        fE3F0, fE3F8, fE400, fE408, fE410, fE418, fE420, fE428, fE430, fE438, fE440, fE448, fE450, fE458, fE460, fE468,
        fE470, fE478, fE480, fE488, fE490, fE498, fE4A0, fE4A8, fE4B0, fE4B8, fE4C0, fE4C8, fE4D0, fE4D8, fE4E0, fE4E8,
        fE4F0, fE4F8, fE500, fE508, fE510, fE518, fE520, fE528, fE530, fE538, fE540, fE548, fE550, fE558, fE560, fE568,
        fE570, fE578, fE580, fE588, fE590, fE598, fE5A0, fE5A8, fE5B0, fE5B8, fE5C0, fE5C8, fE5D0, fE5D8, fE5E0, fE5E8,
        fE5F0, fE5F8, fE600, fE608, fE610, fE618, fE620, fE628, fE630, fE638, fE640, fE648, fE650, fE658, fE660, fE668,
        fE670, fE678, fE680, fE688, fE690, fE698, fE6A0, fE6A8, fE6B0, fE6B8, fE6C0, fE6C8, fE6D0, fE6D8, fE6E0, fE6E8,
        fE6F0, fE6F8, fE700, fE708, fE710, fE718, fE720, fE728, fE730, fE738, fE740, fE748, fE750, fE758, fE760, fE768,
        fE770, fE778, fE780, fE788, fE790, fE798, fE7A0, fE7A8, fE7B0, fE7B8, fE7C0, fE7C8, fE7D0, fE7D8, fE7E0, fE7E8,
        fE7F0, fE7F8, fE800, fE808, fE810, fE818, fE820, fE828, fE830, fE838, fE840, fE848, fE850, fE858, fE860, fE868,
        fE870, fE878, fE880, fE888, fE890, fE898, fE8A0, fE8A8, fE8B0, fE8B8, fE8C0, fE8C8, fE8D0, fE8D8, fE8E0, fE8E8,
        fE8F0, fE8F8, fE900, fE908, fE910, fE918, fE920, fE928, fE930, fE938, fE940, fE948, fE950, fE958, fE960, fE968,
        fE970, fE978, fE980, fE988, fE990, fE998, fE9A0, fE9A8, fE9B0, fE9B8, fE9C0, fE9C8, fE9D0, fE9D8, fE9E0, fE9E8,
        fE9F0, fE9F8, fEA00, fEA08, fEA10, fEA18, fEA20, fEA28, fEA30, fEA38, fEA40, fEA48, fEA50, fEA58, fEA60, fEA68,
        fEA70, fEA78, fEA80, fEA88, fEA90, fEA98, fEAA0, fEAA8, fEAB0, fEAB8, fEAC0, fEAC8, fEAD0, fEAD8, fEAE0, fEAE8,
        fEAF0, fEAF8, fEB00, fEB08, fEB10, fEB18, fEB20, fEB28, fEB30, fEB38, fEB40, fEB48, fEB50, fEB58, fEB60, fEB68,
        fEB70, fEB78, fEB80, fEB88, fEB90, fEB98, fEBA0, fEBA8, fEBB0, fEBB8, fEBC0, fEBC8, fEBD0, fEBD8, fEBE0, fEBE8,
        fEBF0, fEBF8, fEC00, fEC08, fEC10, fEC18, fEC20, fEC28, fEC30, fEC38, fEC40, fEC48, fEC50, fEC58, fEC60, fEC68,
        fEC70, fEC78, fEC80, fEC88, fEC90, fEC98, fECA0, fECA8, fECB0, fECB8, fECC0, fECC8, fECD0, fECD8, fECE0, fECE8,
        fECF0, fECF8, fED00, fED08, fED10, fED18, fED20, fED28, fED30, fED38, fED40, fED48, fED50, fED58, fED60, fED68,
        fED70, fED78, fED80, fED88, fED90, fED98, fEDA0, fEDA8, fEDB0, fEDB8, fEDC0, fEDC8, fEDD0, fEDD8, fEDE0, fEDE8,
        fEDF0, fEDF8, fEE00, fEE08, fEE10, fEE18, fEE20, fEE28, fEE30, fEE38, fEE40, fEE48, fEE50, fEE58, fEE60, fEE68,
        fEE70, fEE78, fEE80, fEE88, fEE90, fEE98, fEEA0, fEEA8, fEEB0, fEEB8, fEEC0, fEEC8, fEED0, fEED8, fEEE0, fEEE8,
        fEEF0, fEEF8, fEF00, fEF08, fEF10, fEF18, fEF20, fEF28, fEF30, fEF38, fEF40, fEF48, fEF50, fEF58, fEF60, fEF68,
        fEF70, fEF78, fEF80, fEF88, fEF90, fEF98, fEFA0, fEFA8, fEFB0, fEFB8, fEFC0, fEFC8, fEFD0, fEFD8, fEFE0, fEFE8,
        fEFF0, fEFF8, fF000, fF008, fF010, fF018, fF020, fF028, fF030, fF038, fF040, fF048, fF050, fF058, fF060, fF068,
        fF070, fF078, fF080, fF088, fF090, fF098, fF0A0, fF0A8, fF0B0, fF0B8, fF0C0, fF0C8, fF0D0, fF0D8, fF0E0, fF0E8,
        fF0F0, fF0F8, fF100, fF108, fF110, fF118, fF120, fF128, fF130, fF138, fF140, fF148, fF150, fF158, fF160, fF168,
        fF170, fF178, fF180, fF188, fF190, fF198, fF1A0, fF1A8, fF1B0, fF1B8, fF1C0, fF1C8, fF1D0, fF1D8, fF1E0, fF1E8,
        fF1F0, fF1F8, fF200, fF208, fF210, fF218, fF220, fF228, fF230, fF238, fF240, fF248, fF250, fF258, fF260, fF268,
        fF270, fF278, fF280, fF288, fF290, fF298, fF2A0, fF2A8, fF2B0, fF2B8, fF2C0, fF2C8, fF2D0, fF2D8, fF2E0, fF2E8,
        fF2F0, fF2F8, fF300, fF308, fF310, fF318, fF320, fF328, fF330, fF338, fF340, fF348, fF350, fF358, fF360, fF368,
        fF370, fF378, fF380, fF388, fF390, fF398, fF3A0, fF3A8, fF3B0, fF3B8, fF3C0, fF3C8, fF3D0, fF3D8, fF3E0, fF3E8,
        fF3F0, fF3F8, fF400, fF408, fF410, fF418, fF420, fF428, fF430, fF438, fF440, fF448, fF450, fF458, fF460, fF468,
        fF470, fF478, fF480, fF488, fF490, fF498, fF4A0, fF4A8, fF4B0, fF4B8, fF4C0, fF4C8, fF4D0, fF4D8, fF4E0, fF4E8,
        fF4F0, fF4F8, fF500, fF508, fF510, fF518, fF520, fF528, fF530, fF538, fF540, fF548, fF550, fF558, fF560, fF568,
        fF570, fF578, fF580, fF588, fF590, fF598, fF5A0, fF5A8, fF5B0, fF5B8, fF5C0, fF5C8, fF5D0, fF5D8, fF5E0, fF5E8,
        fF5F0, fF5F8, fF600, fF608, fF610, fF618, fF620, fF628, fF630, fF638, fF640, fF648, fF650, fF658, fF660, fF668,
        fF670, fF678, fF680, fF688, fF690, fF698, fF6A0, fF6A8, fF6B0, fF6B8, fF6C0, fF6C8, fF6D0, fF6D8, fF6E0, fF6E8,
        fF6F0, fF6F8, fF700, fF708, fF710, fF718, fF720, fF728, fF730, fF738, fF740, fF748, fF750, fF758, fF760, fF768,
        fF770, fF778, fF780, fF788, fF790, fF798, fF7A0, fF7A8, fF7B0, fF7B8, fF7C0, fF7C8, fF7D0, fF7D8, fF7E0, fF7E8,
        fF7F0, fF7F8, fF800, fF808, fF810, fF818, fF820, fF828, fF830, fF838, fF840, fF848, fF850, fF858, fF860, fF868,
        fF870, fF878, fF880, fF888, fF890, fF898, fF8A0, fF8A8, fF8B0, fF8B8, fF8C0, fF8C8, fF8D0, fF8D8, fF8E0, fF8E8,
        fF8F0, fF8F8, fF900, fF908, fF910, fF918, fF920, fF928, fF930, fF938, fF940, fF948, fF950, fF958, fF960, fF968,
        fF970, fF978, fF980, fF988, fF990, fF998, fF9A0, fF9A8, fF9B0, fF9B8, fF9C0, fF9C8, fF9D0, fF9D8, fF9E0, fF9E8,
        fF9F0, fF9F8, fFA00, fFA08, fFA10, fFA18, fFA20, fFA28, fFA30, fFA38, fFA40, fFA48, fFA50, fFA58, fFA60, fFA68,
        fFA70, fFA78, fFA80, fFA88, fFA90, fFA98, fFAA0, fFAA8, fFAB0, fFAB8, fFAC0, fFAC8, fFAD0, fFAD8, fFAE0, fFAE8,
        fFAF0, fFAF8, fFB00, fFB08, fFB10, fFB18, fFB20, fFB28, fFB30, fFB38, fFB40, fFB48, fFB50, fFB58, fFB60, fFB68,
        fFB70, fFB78, fFB80, fFB88, fFB90, fFB98, fFBA0, fFBA8, fFBB0, fFBB8, fFBC0, fFBC8, fFBD0, fFBD8, fFBE0, fFBE8,
        fFBF0, fFBF8, fFC00, fFC08, fFC10, fFC18, fFC20, fFC28, fFC30, fFC38, fFC40, fFC48, fFC50, fFC58, fFC60, fFC68,
        fFC70, fFC78, fFC80, fFC88, fFC90, fFC98, fFCA0, fFCA8, fFCB0, fFCB8, fFCC0, fFCC8, fFCD0, fFCD8, fFCE0, fFCE8,
        fFCF0, fFCF8, fFD00, fFD08, fFD10, fFD18, fFD20, fFD28, fFD30, fFD38, fFD40, fFD48, fFD50, fFD58, fFD60, fFD68,
        fFD70, fFD78, fFD80, fFD88, fFD90, fFD98, fFDA0, fFDA8, fFDB0, fFDB8, fFDC0, fFDC8, fFDD0, fFDD8, fFDE0, fFDE8,
        fFDF0, fFDF8, fFE00, fFE08, fFE10, fFE18, fFE20, fFE28, fFE30, fFE38, fFE40, fFE48, fFE50, fFE58, fFE60, fFE68,
        fFE70, fFE78, fFE80, fFE88, fFE90, fFE98, fFEA0, fFEA8, fFEB0, fFEB8, fFEC0, fFEC8, fFED0, fFED8, fFEE0, fFEE8,
        fFEF0, fFEF8, fFF00, fFF08, fFF10, fFF18, fFF20, fFF28, fFF30, fFF38, fFF40, fFF48, fFF50, fFF58, fFF60, fFF68,
        fFF70, fFF78, fFF80, fFF88, fFF90, fFF98, fFFA0, fFFA8, fFFB0, fFFB8, fFFC0, fFFC8, fFFD0, fFFD8, fFFE0, fFFE8,
        fFFF0, fFFF8, f10000, f10008, f10010, f10018, f10020, f10028, f10030, f10038, f10040, f10048, f10050, f10058,
        f10060, f10068, f10070, f10078, f10080, f10088, f10090, f10098, f100A0, f100A8, f100B0, f100B8, f100C0, f100C8,
        f100D0, f100D8, f100E0, f100E8, f100F0, f100F8, f10100, f10108, f10110, f10118, f10120, f10128, f10130, f10138,
        f10140, f10148, f10150, f10158, f10160, f10168, f10170, f10178, f10180, f10188, f10190, f10198, f101A0, f101A8,
        f101B0, f101B8, f101C0, f101C8, f101D0, f101D8, f101E0, f101E8, f101F0, f101F8, f10200, f10208, f10210, f10218,
        f10220, f10228, f10230, f10238, f10240, f10248, f10250, f10258, f10260, f10268, f10270, f10278, f10280, f10288,
        f10290, f10298, f102A0, f102A8, f102B0, f102B8, f102C0, f102C8, f102D0, f102D8, f102E0, f102E8, f102F0, f102F8,
        f10300, f10308, f10310, f10318, f10320, f10328, f10330, f10338, f10340, f10348, f10350, f10358, f10360, f10368,
        f10370, f10378, f10380, f10388, f10390, f10398, f103A0, f103A8;
    unsigned int unk103B0, unk103B4, unk103B8;
    void ProcessLists_LoadGame(LoadBuffer*);
};
// @fnv 0x00975930
// src: COMMUNITY 0x00975930
void FUN_00975930_shell::ProcessLists_LoadGame(LoadBuffer* buffer)
{
    buffer->LoadData(&unk00154, 4);
    if (buffer->GetVersion() >= 18)
        buffer->LoadData(&unk00158, 4);
    buffer->LoadData(&unk103B4, 4);
    buffer->LoadData(&unk103B8, 4);
    for (unsigned int i = 0; i < 5; ++i)
    {
        unsigned int count = buffer->FUN_00864a60();
        if (count)
        {
            if (lists[i])
                lists[i]->FUN_00470470();
            else
                lists[i] = new EntryListNode;
            for (unsigned int j = 0; j < count; ++j)
            {
                LoadedEntry* item = new LoadedEntry;
                item->ReadFromStream(buffer);
                lists[i]->FUN_005ae3d0(item);
            }
        }
    }
}

// Retained destructor model: BSScrapArray.h lacks Clear(bool) and the base cleanup at 0x00978a60 used by 0x00978a80.
struct ScrapArrayBase
{
    virtual ~ScrapArrayBase();
};
struct FUN_00978a80 : ScrapArrayBase
{
    void Clear(bool releaseMemory);
    virtual ~FUN_00978a80();
};
// Destructor that clears the array, releasing its memory.
// @fnv 0x00978a80
FUN_00978a80::~FUN_00978a80()
{
    Clear(true);
}

struct Equipment97
{
    bool TESObjectWEAP_IsThrownWeapon();
};
struct Inventory97
{
    Equipment97* GetFlags();
    int FUN_00726070();
};
struct Process97
{
    virtual void virtual_000();
    virtual void virtual_004();
    virtual void virtual_008();
    virtual void virtual_00c();
    virtual void virtual_010();
    virtual void virtual_014();
    virtual void virtual_018();
    virtual void virtual_01c();
    virtual void virtual_020();
    virtual void virtual_024();
    virtual void virtual_028();
    virtual void virtual_02c();
    virtual void virtual_030();
    virtual void virtual_034();
    virtual void virtual_038();
    virtual void virtual_03c();
    virtual void virtual_040();
    virtual void virtual_044();
    virtual void virtual_048();
    virtual void virtual_04c();
    virtual void virtual_050();
    virtual void virtual_054();
    virtual void virtual_058();
    virtual void virtual_05c();
    virtual void virtual_060();
    virtual void virtual_064();
    virtual void virtual_068();
    virtual void virtual_06c();
    virtual void virtual_070();
    virtual void virtual_074();
    virtual void virtual_078();
    virtual void virtual_07c();
    virtual void virtual_080();
    virtual void virtual_084();
    virtual void virtual_088();
    virtual void virtual_08c();
    virtual void virtual_090();
    virtual void virtual_094();
    virtual void virtual_098();
    virtual void virtual_09c();
    virtual void virtual_0a0();
    virtual void virtual_0a4();
    virtual void virtual_0a8();
    virtual void virtual_0ac();
    virtual void virtual_0b0();
    virtual void virtual_0b4();
    virtual void virtual_0b8();
    virtual void virtual_0bc();
    virtual void virtual_0c0();
    virtual void virtual_0c4();
    virtual void virtual_0c8();
    virtual void virtual_0cc();
    virtual void virtual_0d0();
    virtual void virtual_0d4();
    virtual void virtual_0d8();
    virtual void virtual_0dc();
    virtual void virtual_0e0();
    virtual void virtual_0e4();
    virtual void virtual_0e8();
    virtual void virtual_0ec();
    virtual void virtual_0f0();
    virtual void virtual_0f4();
    virtual void virtual_0f8();
    virtual void virtual_0fc();
    virtual void virtual_100();
    virtual void virtual_104();
    virtual void virtual_108();
    virtual void virtual_10c();
    virtual void virtual_110();
    virtual void virtual_114();
    virtual void virtual_118();
    virtual void virtual_11c();
    virtual void virtual_120();
    virtual void virtual_124();
    virtual void virtual_128();
    virtual void virtual_12c();
    virtual void virtual_130();
    virtual void virtual_134();
    virtual void virtual_138();
    virtual void virtual_13c();
    virtual void virtual_140();
    virtual void virtual_144();
    virtual Inventory97* GetEquippedEntry();
    virtual void virtual_14c();
    virtual void virtual_150();
    virtual void virtual_154();
    virtual void virtual_158();
    virtual void virtual_15c();
    virtual void virtual_160();
    virtual void virtual_164();
    virtual void virtual_168();
    virtual void virtual_16c();
    virtual void virtual_170();
    virtual void virtual_174();
    virtual void virtual_178();
    virtual void virtual_17c();
    virtual void virtual_180();
    virtual void virtual_184();
    virtual void virtual_188();
    virtual void virtual_18c();
    virtual void virtual_190();
    virtual void virtual_194();
    virtual void virtual_198();
    virtual void virtual_19c();
    virtual void virtual_1a0();
    virtual void virtual_1a4();
    virtual void virtual_1a8();
    virtual void virtual_1ac();
    virtual void virtual_1b0();
    virtual void virtual_1b4();
    virtual void virtual_1b8();
    virtual void virtual_1bc();
    virtual void virtual_1c0();
    virtual void virtual_1c4();
    virtual void virtual_1c8();
    virtual void virtual_1cc();
    virtual void virtual_1d0();
    virtual void virtual_1d4();
    virtual void virtual_1d8();
    virtual void virtual_1dc();
    virtual void virtual_1e0();
    virtual void virtual_1e4();
    virtual void virtual_1e8();
    virtual void virtual_1ec();
    virtual void virtual_1f0();
    virtual void virtual_1f4();
    virtual void virtual_1f8();
    virtual void virtual_1fc();
    virtual void virtual_200();
    virtual void virtual_204();
    virtual void virtual_208();
    virtual void virtual_20c();
    virtual void virtual_210();
    virtual void virtual_214();
    virtual void virtual_218();
    virtual void virtual_21c();
    virtual void virtual_220();
    virtual void virtual_224();
    virtual void virtual_228();
    virtual void virtual_22c();
    virtual void virtual_230();
    virtual void virtual_234();
    virtual void virtual_238();
    virtual void virtual_23c();
    virtual void virtual_240();
    virtual void virtual_244();
    virtual void virtual_248();
    virtual void virtual_24c();
    virtual void virtual_250();
    virtual void virtual_254();
    virtual void virtual_258();
    virtual void virtual_25c();
    virtual void virtual_260();
    virtual void virtual_264();
    virtual void virtual_268();
    virtual void virtual_26c();
    virtual void virtual_270();
    virtual void virtual_274();
    virtual void virtual_278();
    virtual void virtual_27c();
    virtual void virtual_280();
    virtual void virtual_284();
    virtual void virtual_288();
    virtual void virtual_28c();
    virtual void virtual_290();
    virtual void virtual_294();
    virtual void virtual_298();
    virtual void virtual_29c();
    virtual void virtual_2a0();
    virtual void virtual_2a4();
    virtual void virtual_2a8();
    virtual void virtual_2ac();
    virtual void virtual_2b0();
    virtual void virtual_2b4();
    virtual void virtual_2b8();
    virtual void virtual_2bc();
    virtual void virtual_2c0();
    virtual void virtual_2c4();
    virtual void virtual_2c8();
    virtual void virtual_2cc();
    virtual void virtual_2d0();
    virtual void virtual_2d4();
    virtual void virtual_2d8();
    virtual void virtual_2dc();
    virtual void virtual_2e0();
    virtual void virtual_2e4();
    virtual void virtual_2e8();
    virtual void virtual_2ec();
    virtual void virtual_2f0();
    virtual void virtual_2f4();
    virtual void virtual_2f8();
    virtual void virtual_2fc();
    virtual void virtual_300();
    virtual void virtual_304();
    virtual void virtual_308();
    virtual void virtual_30c();
    virtual void virtual_310();
    virtual void virtual_314();
    virtual void virtual_318();
    virtual void virtual_31c();
    virtual void virtual_320();
    virtual void virtual_324();
    virtual void virtual_328();
    virtual void virtual_32c();
    virtual void virtual_330();
    virtual void virtual_334();
    virtual void virtual_338();
    virtual void virtual_33c();
    virtual void virtual_340();
    virtual void virtual_344();
    virtual void virtual_348();
    virtual void virtual_34c();
    virtual void virtual_350();
    virtual void virtual_354();
    virtual void virtual_358();
    virtual void virtual_35c();
    virtual void virtual_360();
    virtual void virtual_364();
    virtual void virtual_368();
    virtual void virtual_36c();
    virtual void virtual_370();
    virtual void virtual_374();
    virtual void virtual_378();
    virtual void virtual_37c();
    virtual void virtual_380();
    virtual void virtual_384();
    virtual void virtual_388();
    virtual void virtual_38c();
    virtual void virtual_390();
    virtual void virtual_394();
    virtual void virtual_398();
    virtual void virtual_39c();
    virtual void virtual_3a0();
    virtual void virtual_3a4();
    virtual void virtual_3a8();
    virtual void virtual_3ac();
    virtual void virtual_3b0();
    virtual void virtual_3b4();
    virtual void virtual_3b8();
    virtual void virtual_3bc();
    virtual void virtual_3c0();
    virtual void virtual_3c4();
    virtual void virtual_3c8();
    virtual void virtual_3cc();
    virtual void virtual_3d0();
    virtual void virtual_3d4();
    virtual void virtual_3d8();
    virtual void virtual_3dc();
    virtual void virtual_3e0();
    virtual void virtual_3e4();
    virtual void virtual_3e8();
    virtual void virtual_3ec();
    virtual void virtual_3f0();
    virtual void virtual_3f4();
    virtual void virtual_3f8();
    virtual void virtual_3fc();
    virtual void virtual_400();
    virtual void virtual_404();
    virtual void virtual_408();
    virtual void virtual_40c();
    virtual void virtual_410();
    virtual void virtual_414();
    virtual void virtual_418();
    virtual void virtual_41c();
    virtual void virtual_420();
    virtual void virtual_424();
    virtual void virtual_428();
    virtual void virtual_42c();
    virtual void virtual_430();
    virtual void virtual_434();
    virtual void virtual_438();
    virtual void virtual_43c();
    virtual void virtual_440();
    virtual void virtual_444();
    virtual void virtual_448();
    virtual void virtual_44c();
    virtual void SetWeaponFlag(bool flag);
    virtual void virtual_454();
    virtual void UpdateActor(void* actor, bool flag);
};
struct Actor97
{
    virtual void virtual_000();
    virtual void virtual_004();
    virtual void virtual_008();
    virtual void virtual_00c();
    virtual void virtual_010();
    virtual void virtual_014();
    virtual void virtual_018();
    virtual void virtual_01c();
    virtual void virtual_020();
    virtual void virtual_024();
    virtual void virtual_028();
    virtual void virtual_02c();
    virtual void virtual_030();
    virtual void virtual_034();
    virtual void virtual_038();
    virtual void virtual_03c();
    virtual void virtual_040();
    virtual void virtual_044();
    virtual void virtual_048();
    virtual void virtual_04c();
    virtual void virtual_050();
    virtual void virtual_054();
    virtual void virtual_058();
    virtual void virtual_05c();
    virtual void virtual_060();
    virtual void virtual_064();
    virtual void virtual_068();
    virtual void virtual_06c();
    virtual void virtual_070();
    virtual void virtual_074();
    virtual void virtual_078();
    virtual void virtual_07c();
    virtual void virtual_080();
    virtual void virtual_084();
    virtual void virtual_088();
    virtual void virtual_08c();
    virtual void virtual_090();
    virtual void virtual_094();
    virtual void virtual_098();
    virtual void virtual_09c();
    virtual void virtual_0a0();
    virtual void virtual_0a4();
    virtual void virtual_0a8();
    virtual void virtual_0ac();
    virtual void virtual_0b0();
    virtual void virtual_0b4();
    virtual void virtual_0b8();
    virtual void virtual_0bc();
    virtual void virtual_0c0();
    virtual void virtual_0c4();
    virtual void virtual_0c8();
    virtual void virtual_0cc();
    virtual void virtual_0d0();
    virtual void virtual_0d4();
    virtual void virtual_0d8();
    virtual void virtual_0dc();
    virtual void virtual_0e0();
    virtual void virtual_0e4();
    virtual void virtual_0e8();
    virtual void virtual_0ec();
    virtual void virtual_0f0();
    virtual void virtual_0f4();
    virtual void virtual_0f8();
    virtual void virtual_0fc();
    virtual void virtual_100();
    virtual void virtual_104();
    virtual void virtual_108();
    virtual void virtual_10c();
    virtual void virtual_110();
    virtual void virtual_114();
    virtual void virtual_118();
    virtual void virtual_11c();
    virtual void virtual_120();
    virtual void virtual_124();
    virtual void virtual_128();
    virtual void virtual_12c();
    virtual void virtual_130();
    virtual void virtual_134();
    virtual void virtual_138();
    virtual void virtual_13c();
    virtual void virtual_140();
    virtual void virtual_144();
    virtual void virtual_148();
    virtual void virtual_14c();
    virtual void virtual_150();
    virtual void virtual_154();
    virtual void virtual_158();
    virtual void virtual_15c();
    virtual void virtual_160();
    virtual void virtual_164();
    virtual void virtual_168();
    virtual void virtual_16c();
    virtual void virtual_170();
    virtual void virtual_174();
    virtual void virtual_178();
    virtual void virtual_17c();
    virtual void virtual_180();
    virtual void virtual_184();
    virtual void virtual_188();
    virtual void virtual_18c();
    virtual void virtual_190();
    virtual void virtual_194();
    virtual void virtual_198();
    virtual void virtual_19c();
    virtual void virtual_1a0();
    virtual void virtual_1a4();
    virtual void virtual_1a8();
    virtual void virtual_1ac();
    virtual void virtual_1b0();
    virtual void virtual_1b4();
    virtual void virtual_1b8();
    virtual void virtual_1bc();
    virtual void virtual_1c0();
    virtual void virtual_1c4();
    virtual void virtual_1c8();
    virtual void virtual_1cc();
    virtual int IsEquipmentReady();
    Process97* GetProcess();
    int FUN_00575610(Equipment97* equipment);
    void EquipObject(Equipment97* equipment, int count, void* extra, bool a, bool b, bool c);
    bool UnEquipObject(Equipment97* equipment, int count, void* extra, bool a, bool b, bool c);
};
struct CombatData97
{
    unsigned char BSFaceGenNiNode_GetApplyRotToParent();
    void CombatState_SetLastDoorFleeTime(float value);
    Equipment97* GetBestWeapon();
    void CombatState_ChangeProcessLevel(int first, int second);
};
// @fnv 0x0097efe0
void CombatController::UpdateCombatEquipment(int first, int second)
{
    if (second == 0)
    {
        equipmentChanged = false;
        ForcePlanUpdate();
        bool active = reinterpret_cast<CombatData97*>(combat)->BSFaceGenNiNode_GetApplyRotToParent() != 0;
        reinterpret_cast<Actor97*>(actor)->GetProcess()->SetWeaponFlag(!active);
        if (active)
        {
            reinterpret_cast<CombatData97*>(combat)->CombatState_SetLastDoorFleeTime(CombatTimer_GetTimer());
        }
        if (reinterpret_cast<Actor97*>(actor)->IsEquipmentReady())
        {
            Equipment97* entry = reinterpret_cast<CombatData97*>(combat)->GetBestWeapon();
            Inventory97* pEquippedEntry = reinterpret_cast<Actor97*>(actor)->GetProcess()->GetEquippedEntry();
            Equipment97* current = pEquippedEntry ? pEquippedEntry->GetFlags() : 0;
            if (entry && entry != current)
            {
                reinterpret_cast<Actor97*>(actor)->EquipObject(entry, entry->TESObjectWEAP_IsThrownWeapon() ? reinterpret_cast<Actor97*>(actor)->FUN_00575610(entry) : 1, 0, true, false, true);
            }
            else if (!entry && current)
            {
                reinterpret_cast<Actor97*>(actor)->UnEquipObject(current, pEquippedEntry->FUN_00726070(), 0, false, false, true);
            }
        }
        else
        {
            reinterpret_cast<Actor97*>(actor)->GetProcess()->UpdateActor(reinterpret_cast<Actor97*>(actor), !active);
        }
    }
    reinterpret_cast<CombatData97*>(combat)->CombatState_ChangeProcessLevel(first, second);
    if (first == 0 || second == 0)
    {
        DestroyOwnedObject();
        ClearProcedures();
        ClearBackgroundProcedures();
        lastUpdate = -1.0f;
    }
}

struct ActorPoint3
{
    float x;
    float y;
    float z;
};

extern OSGlobals* DAT_011dea0c;

struct ActorDecomp
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual void vf0D0();
    virtual void vf0D4();
    virtual void vf0D8();
    virtual void vf0DC();
    virtual void vf0E0();
    virtual void vf0E4();
    virtual void vf0E8();
    virtual void vf0EC();
    virtual void vf0F0();
    virtual void vf0F4();
    virtual void vf0F8();
    virtual void vf0FC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15C();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16C();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17C();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18C();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19C();
    virtual void vf1A0();
    virtual void vf1A4();
    virtual void vf1A8();
    virtual void vf1AC();
    virtual void vf1B0();
    virtual void vf1B4();
    virtual void vf1B8();
    virtual void vf1BC();
    virtual void vf1C0();
    virtual void vf1C4();
    virtual void vf1C8();
    virtual void vf1CC();
    virtual void vf1D0();
    virtual void vf1D4();
    virtual void vf1D8();
    virtual void vf1DC();
    virtual void vf1E0();
    virtual void vf1E4();
    virtual void vf1E8();
    virtual void vf1EC();
    virtual void vf1F0();
    virtual ActorPoint3* vf1F4();
    float TESObjectREFR_GetScale_00567400();
    ActorPoint3* FUN_00430830();

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    float unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    float unk7E0;
    float unk7E4;
    ActorPoint3 unk7E8;

    unsigned char PlayerCharacter_ToggleFlyCam(unsigned char value);
};

FUN_00961f30_Class* __cdecl Interface_GetHUDEffects();

// Toggles a global state, propagates it to DAT_011dea0c and FUN_00705950, and when enabled copies the actor's position and updates unk7E8.z, unk7E0 and unk7E4.
// @fnv 0x00961e30
// src: COMMUNITY 0x00961e30
unsigned char ActorDecomp::PlayerCharacter_ToggleFlyCam(unsigned char value)
{
    unsigned char state = (unsigned char)static_cast<OSGlobalFlagAccess*>(DAT_011dea0c)->IsFlycam();
    state = (state != 0) ? 0 : 1;
    static_cast<OSGlobalFlagAccess*>(DAT_011dea0c)->SetByteAtOffset6(state);
    static_cast<OSGlobalFlagAccess*>(DAT_011dea0c)->SetByteAtOffset7(state && value);
    Interface_GetHUDEffects()->SetByteAt54(state);
    if (state)
    {
        this->unk7E8 = *this->vf1F4();
        this->unk7E8.z = this->TESObjectREFR_GetScale_00567400() * this->unk698 + this->unk7E8.z;
        this->unk7E0 = this->FUN_00430830()->z;
        this->unk7E4 = this->FUN_00430830()->x;
    }
    return state;
}

namespace fnv_00967da0 {
struct Unk_8f25e0
{
    ~Unk_8f25e0();
};

struct CombatActionNode;
struct TargetForm;




struct TargetForm
{
    int FUN_0041ca90();
    void SpectatorPackage_RemoveActorAsThreatSourceOrTarget(CombatActor*);
    void RemoveRef(CombatActor*);
};

struct CombatGroupManager
{
    unsigned int CombatManager_GetCombatGroupCount();
    ActorCombatGroup* ProcessArray_GetItem(unsigned int index);
    ActorCombatGroup* CombatManager_CreateCombatGroup();
};
struct GroupNotification
{
    void TryStartDialogue(CombatActor* chosen, void* owner, int type, int flags, int enabled, int mode);
};
struct CombatActionNode
{
    CombatActor** FUN_006815c0();
    CombatActionNode* FUN_00726070();
    unsigned char FUN_008256d0();
    void RemoveMatchingItem(CombatActor** actor);
    void FUN_0063f7b0();
};
struct ActionEntryList
{
    CombatActionNode* ProcessLists_RemoveCrimesForYieldCheck(float time);
    CombatActionNode* FUN_0096e290();
};
struct FloatSetting
{
    float* Setting_Float_00403e20();
};
struct CleanupTarget
{
    void CombatController_ForceStopCombat();
};

extern FloatSetting DAT_011ce3a8;
extern ActionEntryList DAT_011e0e80;
extern CombatGroupManager* DAT_011f1958;
extern GroupNotification* DAT_011f1708;

extern float DAT_0108a8a0;





}  // namespace fnv_00967da0

class CombatActorVtable
{
public:
    void* slot000;
    void* slot001;
    void* slot002;
    void* slot003;
    void* slot004;
    void* slot005;
    void* slot006;
    void* slot007;
    void* slot008;
    void* slot009;
    void* slot010;
    void* slot011;
    void* slot012;
    void* slot013;
    void* slot014;
    void* slot015;
    void* slot016;
    void* slot017;
    void* slot018;
    void* slot019;
    void* slot020;
    void* slot021;
    void* slot022;
    void* slot023;
    void* slot024;
    void* slot025;
    void* slot026;
    void* slot027;
    void* slot028;
    void* slot029;
    void* slot030;
    void* slot031;
    void* slot032;
    void* slot033;
    void* slot034;
    void* slot035;
    void* slot036;
    void* slot037;
    void* slot038;
    void* slot039;
    void* slot040;
    void* slot041;
    void* slot042;
    void* slot043;
    void* slot044;
    void* slot045;
    void* slot046;
    void* slot047;
    void* slot048;
    void* slot049;
    void* slot050;
    void* slot051;
    void* slot052;
    void* slot053;
    void* slot054;
    void* slot055;
    void* slot056;
    void* slot057;
    void* slot058;
    void* slot059;
    void* slot060;
    void* slot061;
    void* slot062;
    void* slot063;
    void* slot064;
    void* slot065;
    void* slot066;
    void* slot067;
    void* slot068;
    void* slot069;
    void* slot070;
    void* slot071;
    void* slot072;
    void* slot073;
    void* slot074;
    void* slot075;
    void* slot076;
    void* slot077;
    void* slot078;
    void* slot079;
    void* slot080;
    void* slot081;
    void* slot082;
    void* slot083;
    void* slot084;
    void* slot085;
    void* slot086;
    void* slot087;
    void* slot088;
    void* slot089;
    void* slot090;
    void* slot091;
    void* slot092;
    void* slot093;
    void* slot094;
    void* slot095;
    void* slot096;
    void* slot097;
    void* slot098;
    void* slot099;
    void* slot100;
    void* slot101;
    void* slot102;
    void* slot103;
    void* slot104;
    void* slot105;
    void* slot106;
    void* slot107;
    void* slot108;
    void* slot109;
    void* slot110;
    void* slot111;
    void* slot112;
    void* slot113;
    void* slot114;
    void* slot115;
    void* slot116;
    void* slot117;
    void* slot118;
    void* slot119;
    void* slot120;
    void* slot121;
    void* slot122;
    void* slot123;
    void* slot124;
    NiPoint3*(__thiscall* GetPosition)(CombatActor*);
    void* slot126;
    void* slot127;
    void* slot128;
    void* slot129;
    void* slot130;
    void* slot131;
    void* slot132;
    void* slot133;
    void* slot134;
    void* slot135;
    void* slot136;
    void* slot137;
    void* slot138;
    void* slot139;
    void* slot140;
    void* slot141;
    void* slot142;
    void* slot143;
    void* slot144;
    void* slot145;
    void* slot146;
    void* slot147;
    void* slot148;
    void* slot149;
    void* slot150;
    void* slot151;
    void* slot152;
    void* slot153;
    void* slot154;
    void* slot155;
    void* slot156;
    void* slot157;
    void* slot158;
    void* slot159;
    void* slot160;
    void* slot161;
    void* slot162;
    void* slot163;
    void* slot164;
    void* slot165;
    void* slot166;
    void* slot167;
    void* slot168;
    void* slot169;
    void* slot170;
    void* slot171;
    void* slot172;
    void* slot173;
    void* slot174;
    void* slot175;
    void* slot176;
    void* slot177;
    void* slot178;
    void* slot179;
    void* slot180;
    void* slot181;
    void* slot182;
    void* slot183;
    void* slot184;
    void* slot185;
    void* slot186;
    void* slot187;
    void* slot188;
    void* slot189;
    void* slot190;
    void* slot191;
    void* slot192;
    void* slot193;
    void* slot194;
    void* slot195;
    void* slot196;
    void* slot197;
    void* slot198;
    void* slot199;
    void* slot200;
    void* slot201;
    void* slot202;
    void* slot203;
    void* slot204;
    void* slot205;
    void* slot206;
    void* slot207;
    void* slot208;
    void* slot209;
    void* slot210;
    void* slot211;
    void* slot212;
    void* slot213;
    void* slot214;
    void* slot215;
    void* slot216;
    void* slot217;
    void* slot218;
    void* slot219;
    void* slot220;
    void* slot221;
    void* slot222;
    void* slot223;
    void* slot224;
    void* slot225;
    void* slot226;
    void* slot227;
    void* slot228;
    void* slot229;
    void* slot230;
    void* slot231;
    void* slot232;
    void* slot233;
    void* slot234;
    void* slot235;
    void* slot236;
    void* slot237;
    void* slot238;
    void* slot239;
    void* slot240;
    void* slot241;
    void* slot242;
    void* slot243;
    void* slot244;
    void* slot245;
    void* slot246;
    void* slot247;
    void* slot248;
    void* slot249;
    void* slot250;
    void* slot251;
    void* slot252;
    void* slot253;
    void* slot254;
    void(__thiscall* Migrate)(CombatActor*, ActorCombatGroup*);
    void* slot256;
    void* slot257;
    void* slot258;
    void* slot259;
    void* slot260;
    void* slot261;
    void* slot262;
    void* slot263;
    void* slot264;
    void* slot265;
    fnv_00967da0::CleanupTarget*(__thiscall* GetCleanup)(CombatActor*);
    void* slot267;
    void* slot268;
    void(__thiscall* Remove)(CombatActor*, int);
};

// @fnv 0x00967da0
// src: XBOX_PDB 0x00967da0
int CombatController::PlayerCharacter_AttemptYield()
{
    using fnv_00967da0::Unk_8f25e0;
    using fnv_00967da0::CombatActionNode;
    using fnv_00967da0::TargetForm;
    using fnv_00967da0::DAT_011ce3a8;
    using fnv_00967da0::DAT_011e0e80;
    using fnv_00967da0::DAT_011f1958;
    using fnv_00967da0::DAT_011f1708;
    using fnv_00967da0::DAT_0108a8a0;

    // p: groupCount
    // h: originalSize
    // a: activeCount
    // i: inactiveCount
    // s: actions
    // f: allNode
    // eb: originalGroup
    // cf: temporaryGroup
    // q: transferCount
    // b: pendingNode
    CombatActionNode* b;
    CombatActionNode* f;
    unsigned int q = 0;
    CombatActionNode* s = DAT_011e0e80.ProcessLists_RemoveCrimesForYieldCheck(*DAT_011ce3a8.Setting_Float_00403e20());
    if (!s)
        return 0;

    ActorCombatGroup* eb = *reinterpret_cast<ActorCombatGroup**>(reinterpret_cast<char*>(this) + 0xD64);
    ActorCombatGroup* cf = 0;
    unsigned int h = eb ? eb->CombatGroup_GetMemberCount() : 0;
    unsigned int a = 0;
    unsigned int i = 0;

    for (unsigned int memberIndex = 0; memberIndex < h; memberIndex++)
    {
        CombatActor* member = eb->GetIntAt(memberIndex);
        if (member == reinterpret_cast<CombatActor*>(DAT_011dea3c))
            continue;
        if (member->FUN_00566950())
            a++;
        else
            i++;
    }

    if (i != 0)
    {
        cf = DAT_011f1958->CombatManager_CreateCombatGroup();
        cf->CombatGroup_CopyTargets(eb);
    }

    unsigned int p = DAT_011f1958->CombatManager_GetCombatGroupCount();
    for (unsigned int groupIndex = 0; groupIndex < p; groupIndex++)
    {
        ActorCombatGroup* a = DAT_011f1958->ProcessArray_GetItem(groupIndex);
        if (a == 0 || a == eb || a == cf)
            continue;
        if (!a->CombatGroup_IsTarget(this))
            continue;

        // p: allowed; a: group; f: nearest; b: groupSize; ba: preserve; k: reference; l: bestCandidate
        unsigned char p = 1;
        unsigned char ba = 1;
        unsigned int b = a->CombatGroup_GetMemberCount();
        for (unsigned int j = 0; j < b; j++)
        {
            CombatActor* candidate = a->GetIntAt(j);
            int result = 0;
            if (candidate->IsHostileTo(this, 0, &result, 1))
            {
                p = 0;
                break;
            }
            if (ba && i != 0)
            {
                for (unsigned int index = 0; index < h; index++)
                {
                    CombatActor* old = eb->GetIntAt(index);
                    if (old == reinterpret_cast<CombatActor*>(DAT_011dea3c) || old->FUN_00566950())
                        continue;
                    if (candidate->IsHostileTo(old, 0, &result, 1) || old->IsHostileTo(candidate, 0, &result, 1))
                    {
                        ba = 0;
                        break;
                    }
                }
            }
        }
        if (!p)
            continue;

        CombatActor* l = 0;
        float f = DAT_0108a8a0;
        NiPoint3 k = *reinterpret_cast<CombatActor*>(this)->vtable->GetPosition(reinterpret_cast<CombatActor*>(this));

        if (eb != 0)
        {
            for (unsigned int index = 0; index < h; index++)
            {
                CombatActor* old = eb->GetIntAt(index);
                if (ba || old->FUN_00566950() || old == reinterpret_cast<CombatActor*>(DAT_011dea3c))
                {
                    a->RemoveByTarget(old);
                }
                else if (!ba && cf)
                {
                    cf->CombatGroup_AddMember(old);
                }
            }
        }
        else
        {
            a->RemoveByTarget(reinterpret_cast<CombatActor*>(this));
        }

        for (unsigned int index = 0; index < static_cast<unsigned int>(a->PathingSolution_GetVirtualNodeCount()); index++)
        {
            CombatActor* old = a->CombatGroup_GetTarget(index);
            if (old && old->FUN_00566950() && !old->Actor_IsAngryWithPlayer())
            {
                a->RemoveByTarget(old);
                index--;
                old->vtable->Remove(old, 0);
            }
        }

        for (unsigned int index = 0; index < b; index++)
        {
            // p: difference; h: distance; b: candidate; ba: previous; k: current
            CombatActor* b = a->GetIntAt(index);
            q++;
            if (eb)
                eb->RemoveByTarget(b);
            if (ba && cf)
                cf->RemoveByTarget(b);

            NiPoint3 p = k.SubtractIntoVector(b->vtable->GetPosition(b));
            float h = p.FUN_004a7290();
            if (h < f)
            {
                l = b;
                f = h;
            }

            CombatActionNode* k = s;
            CombatActionNode* ba = 0;
            while (k && !k->FUN_008256d0())
            {
                CombatActor* referenceActor = *k->FUN_006815c0();
                bool remove = false;
                if (referenceActor)
                {
                    if (referenceActor->FUN_0044ddc0() == b)
                    {
                        delete (Unk_8f25e0*)referenceActor;
                        remove = true;
                    }
                }
                else
                {
                    remove = true;
                }

                if (remove)
                {
                    if (ba)
                    {
                        ba->RemoveMatchingItem(k->FUN_006815c0());
                        k = ba->FUN_00726070();
                    }
                    else
                    {
                        k->FUN_0063f7b0();
                    }
                }
                else
                {
                    ba = k;
                    k = k->FUN_00726070();
                }
            }
        }
        if (l)
            DAT_011f1708->TryStartDialogue(l, this, 2, 11, 1, 0);
    }

    if (eb && q > 0)
    {
        for (unsigned int index = 0; index < eb->CombatGroup_GetMemberCount(); index++)
        {
            CombatActor* actor = eb->GetIntAt(index);
            if (actor && actor->vtable->GetCleanup(actor))
                actor->vtable->GetCleanup(actor)->CombatController_ForceStopCombat();
        }
        while (static_cast<unsigned int>(eb->PathingSolution_GetVirtualNodeCount()) > 0)
        {
            eb->RemoveByTarget(eb->CombatGroup_GetTarget(0u));
        }
    }

    for (f = DAT_011e0e80.FUN_0096e290(); f; f = f->FUN_00726070())
    {
        CombatActor* ref = *f->FUN_006815c0();
        if (ref)
        {
            TargetForm* form = static_cast<TargetForm*>(ref->FUN_009344a0());
            if (form)
            {
                int kind = form->FUN_0041ca90();
                if (kind == 0x18)
                {
                    TargetForm* targetedForm = form;
                    targetedForm->SpectatorPackage_RemoveActorAsThreatSourceOrTarget(reinterpret_cast<CombatActor*>(DAT_011dea3c));
                    ref->Actor_EvaluatePackage(0, 0);
                }
                else if (kind == 0x16)
                {
                    TargetForm* effectForm = form;
                    effectForm->RemoveRef(reinterpret_cast<CombatActor*>(DAT_011dea3c));
                    ref->Actor_EvaluatePackage(0, 0);
                }
                else if (kind == 10)
                {
                    ref->Actor_EvaluatePackage(0, 0);
                }
            }
        }
    }

    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xDF0) = 0;
    b = s;
    while (b)
    {
        CombatActor* ref = *b->FUN_006815c0();
        if (ref)
        {
            CombatActor* actor = ref->FUN_0044ddc0();
            if (actor)
                actor->CopyScaleAndResetItems(ref);
        }
        b = b->FUN_00726070();
    }

    if (cf)
    {
        unsigned int remaining = cf->CombatGroup_GetMemberCount();
        for (unsigned int index = 0; index < remaining; index++)
        {
            CombatActor* actor = cf->GetIntAt(index);
            actor->vtable->Migrate(actor, cf);
            eb->CombatGroup_RemoveMember(actor);
        }
    }

    return q;
}

struct WTSetting
{
    const char* String();
};

struct WTProcess
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44C();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45C();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46C();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47C();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48C();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49C();
    virtual void v4A0();
    virtual void v4A4();
    virtual void v4A8();
    virtual void v4AC();
    virtual void v4B0();
    virtual void v4B4();
    virtual void v4B8();
    virtual void v4BC();
    virtual void v4C0();
    virtual void v4C4();
    virtual void v4C8();
    virtual void v4CC();
    virtual void v4D0();
    virtual void v4D4();
    virtual void v4D8();
    virtual void v4DC();
    virtual void v4E0();
    virtual void v4E4();
    virtual void v4E8();
    virtual void v4EC();
    virtual void v4F0();
    virtual void v4F4();
    virtual void v4F8();
    virtual void v4FC();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50C();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51C();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52C();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53C();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54C();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55C();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56C();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57C();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58C();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59C();
    virtual void v5A0();
    virtual void v5A4();
    virtual void v5A8();
    virtual void v5AC();
    virtual void v5B0();
    virtual void v5B4();
    virtual void v5B8();
    virtual void v5BC();
    virtual void v5C0();
    virtual void v5C4();
    virtual void v5C8();
    virtual void v5CC();
    virtual void v5D0();
    virtual void v5D4();
    virtual void v5D8();
    virtual void v5DC();
    virtual void v5E0();
    virtual void v5E4();
    virtual void v5E8();
    virtual void v5EC();
    virtual void v5F0();
    virtual void v5F4();
    virtual void v5F8();
    virtual void v5FC();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60C();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61C();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62C();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63C();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64C();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65C();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66C();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67C();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68C();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69C();
    virtual void v6A0();
    virtual void v6A4();
    virtual void v6A8();
    virtual void v6AC();
    virtual void v6B0();
    virtual void v6B4();
    virtual void v6B8();
    virtual void v6BC();
    virtual void v6C0();
    virtual void v6C4();
    virtual void v6C8();
    virtual void v6CC();
    virtual void v6D0();
    virtual void v6D4();
    virtual void v6D8();
    virtual void v6DC();
    virtual void v6E0();
    virtual void v6E4();
    virtual void v6E8();
    virtual void v6EC();
    virtual void v6F0();
    virtual void v6F4();
    virtual void v6F8();
    virtual void v6FC();
    virtual void v700();
    virtual void v704();
    virtual void v708();
    virtual void v70C();
    virtual void v710();
    virtual void v714();
    virtual void v718();
    virtual void v71C();
    virtual void v720();
    virtual void v724();
    virtual void v728();
    virtual void v72C();
    virtual void v730();
    virtual void v734();
    virtual void v738();
    virtual void v73C();
    virtual void v740();
    virtual void v744();
    virtual void v748();
    virtual void v74C();
    virtual void v750();
    virtual void v754();
    virtual void v758();
    virtual void v75C();
    virtual void v760();
    virtual float v764();
};

struct WTCell;
struct WTWorld;

struct WTController
{
    int bhkCharacterController_GetState();
};

struct WTHighProcess
{
    bool TESObjectCELL_GetCantWaitHere();
};

struct WTPlayer
{
    WTController* FUN_009306d0();
    WTHighProcess* GetProcessData();
    bool TESObjectREFR_GetInterior();
    unsigned char GetByteAt66E();
};

struct WTPlayerBounds
{
    bool MagicTarget_HasDamageHealthEffect();
};

struct WTProcessLists
{
    bool HasNearbyDetectedActor(bool abFlag);
    bool IsFlagged();
};

bool __cdecl QueueUIMessage(const char* apMessage, int aiUnk, const char* apIcon, const char* apSound, float afTime,
                            bool abFlag);
void __cdecl Interface_CreateSleepMenu(bool abFlag);

extern WTSetting g_kWTMsgInCombat;
extern WTSetting g_kWTMsgUnk28b0;
extern WTSetting g_kWTMsgEnemies;
extern WTSetting g_kWTMsgUnk2e50;
extern WTSetting g_kWTMsgFalling;
extern WTSetting g_kWTMsgUnk20ac;
extern WTSetting g_kWTMsgUnk4b10;
extern WTSetting g_kWTMsgUnk47d4;
extern const float g_fWTMessageTime;
extern const float g_fWTEnemyRadiusMult;
extern const double g_dWTZero;
extern WTProcessLists g_kWTProcessLists;
extern WTPlayer* g_pWTPlayer;

struct WTActor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual WTWorld* GetWorld();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual bool v448();
    bool HasActorsByPackage();
    WTCell* GetParentCellData();
    bool Actor_IsPointDeepUnderWater(WTWorld* apWorld, WTCell* apCell, float afRadius);
    WTProcess* GetCurrentProcess();
    void PlayerCharacter_CanPassTime();
};

// Checks a chain of conditions and queues a sad vault-boy UI message for the first one that matches, otherwise calls FUN_007054f0(true).
// @fnv 0x00969fa0
// src: COMMUNITY 0x00969fa0
void WTActor::PlayerCharacter_CanPassTime()
{
    if (v448())
    {
        QueueUIMessage(g_kWTMsgInCombat.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                       0, g_fWTMessageTime, false);
    }
    else if (HasActorsByPackage())
    {
        QueueUIMessage(g_kWTMsgUnk28b0.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else if (Actor_IsPointDeepUnderWater(GetWorld(), GetParentCellData(), g_fWTEnemyRadiusMult))
    {
        QueueUIMessage(g_kWTMsgEnemies.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else if (g_kWTProcessLists.HasNearbyDetectedActor(g_pWTPlayer->TESObjectREFR_GetInterior()))
    {
        QueueUIMessage(g_kWTMsgUnk2e50.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else if (g_pWTPlayer->FUN_009306d0()->bhkCharacterController_GetState() == 1 || g_pWTPlayer->FUN_009306d0()->bhkCharacterController_GetState() == 2)
    {
        QueueUIMessage(g_kWTMsgFalling.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else if (g_pWTPlayer->GetProcessData()->TESObjectCELL_GetCantWaitHere() || !g_pWTPlayer->GetByteAt66E())
    {
        QueueUIMessage(g_kWTMsgUnk20ac.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else if (g_kWTProcessLists.IsFlagged())
    {
        QueueUIMessage(g_kWTMsgUnk4b10.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else if (GetCurrentProcess() && GetCurrentProcess()->v764() != g_dWTZero)
    {
        QueueUIMessage(g_kWTMsgUnk4b10.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else if (((WTPlayerBounds*)((char*)g_pWTPlayer + 0x94))->MagicTarget_HasDamageHealthEffect())
    {
        QueueUIMessage(g_kWTMsgUnk47d4.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                       g_fWTMessageTime, false);
    }
    else
    {
        Interface_CreateSleepMenu(true);
    }
}

struct PointerMapBaseStandIn
{
    void* m_pkHashTable;
    unsigned int m_uiHashSize;
    unsigned int m_uiCount;
    virtual void Unused0();
    ~PointerMapBaseStandIn();
};
struct FUN_0096a4b0 : PointerMapBaseStandIn
{
    virtual void Unused1();
    ~FUN_0096a4b0();
    void RemoveAll();
};
// Destructor that calls RemoveAll to clear the map's entries before base destruction.
// @fnv 0x0096a4b0
FUN_0096a4b0::~FUN_0096a4b0()
{
    RemoveAll();
}

class Extra979
{
  public:
    virtual ~Extra979();
};
class Base979 : public TESForm, public Extra979
{
  public:
    Base979(void* a, void* b, void* c, NiPoint3 kPos, float f1, float f2);
    virtual ~Base979();
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
};
class Solution979;
template <class T> class PathRef979
{
  public:
    PathRef979(T* pObject = 0);
    ~PathRef979();
    void Reset(T* pObject);
    T* m_pObject;
};
class FUN_00979070 : public Base979
{
  public:
    FUN_00979070(void* a, void* b, void* c, NiPoint3 kPos, float f1, float f2);
    virtual ~FUN_00979070();
    PathRef979<Solution979> m_spSolution;
};
// Constructs a solution form of type 0x3f, initializing its solution reference to null.
// @fnv 0x00979070
FUN_00979070::FUN_00979070(void* a, void* b, void* c, NiPoint3 kPos, float f1, float f2)
    : Base979(a, b, c, kPos, f1, f2), m_spSolution(0)
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x3f));
    m_spSolution.Reset(0);
}

struct MovePoint
{
    float x, y, z, w;
    double BGSWorldLocation_GetDistanceSquared(const MovePoint*);
    void BGSWorldLocation_BGSWorldLocation();
};
struct MoveTarget
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    MoveTarget* CombatLocation_CombatLocation();
    bool CombatLocation_GetFlag(int);
    void CombatLocation_SetTarget(void*);
    MovePoint* ref_006815c0();
    void AssignV4(MovePoint*);
};
struct MoveActor
{
    void* TESObjectREFR_GetLocationEncounterZone();
    MovePoint TESObjectREFR_GetWorldLocation();
    unsigned char IsPathing();
    void TESObjectREFR_SetAngleOnReferenceX(float);
};
struct MoveAction
{
    virtual void v0();
    virtual void Update();
    bool IsField8One();
};
struct MoveBrain
{
    void CombatState_Update();
    bool CombatState_CheckShouldFlee();
    bool GetHasBufferedDetection_0097ee90();
    bool IsElapsedTimeAtLeastSetting();
    unsigned char BSFaceGenNiNode_GetApplyRotToParent();
    void FUN_0097ce70(int);
    bool CombatState_FindBestFleeLocation(int, MoveTarget*, int);
    bool CombatState_CheckMovement_009a02a0(MovePoint*, int, int);
};
struct MoveManager
{
    MoveActor* SelectActor(MoveActor*);
    bool CombatGroup_IsSearching();
    bool GetDetectedTargetLocation(MoveActor*, MovePoint*);
};
struct MoveTimer
{
    int time;
    float limit;
    void FUN_008d7f40(float);
    bool FUN_008d7f80();
    float FUN_00435e00();
};
struct MoveSetting
{
    float* Float();
};
extern MoveSetting originalRuntimeFloatSetting498;
struct MoveBoolSetting
{
    bool* Bool();
};
extern MoveBoolSetting g_011f1840;
extern float DAT_011a56b4, DAT_011a5654;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct IdleAction
{
    int u00, u04, u08, u0c, u10, u14;
    IdleAction(int);
};
struct TravelAction
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    TravelAction(MoveTarget*, float, int);
};
struct SimpleAction
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    SimpleAction();
};
struct SpecialAction
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    SpecialAction();
};
struct CombatMove
{
    int u000;
    int u004;
    int u008;
    int u00c;
    int u010;
    int u014;
    int u018;
    int u01c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    int u048;
    int u04c;
    int u050;
    int u054;
    int u058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    MoveManager* manager;
    MoveAction* action84;
    MoveAction* action88;
    int u08c;
    int u090;
    int u094;
    int u098;
    MoveBrain* brain;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    MoveTimer timer;
    MoveActor* actor;
    MoveActor* target;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    bool initialized;
    unsigned char uE5;
    unsigned short uE6;
    int u0e8;
    int u0ec;
    int u0f0;
    int u0f4;
    int u0f8;
    int u0fc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int u114;
    int u118;
    int u11c;
    int u120;
    int u124;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    int u140;
    int state;
    float elapsed;

    void FirstUpdate();
    void SetTarget_00980830(MoveActor*);
    bool GetProcedureFailed();
    bool GetProcedureFinished();
    void ClearProcedures();
    void InitFromArg(MoveAction*);
    void SetMovementProcedure(void*);
    void SetActionProcedure(void*);
    void CombatController_UpdateLow();
};
// Updates the combat move state machine, selecting a new action (idle, travel, special) based on brain and target conditions.
// @fnv 0x0097e4b0
// src: COMMUNITY 0x0097e4b0
void CombatMove::CombatController_UpdateLow()
{
    if (!initialized)
    {
        FirstUpdate();
        initialized = true;
    }
    if (elapsed < 0.0)
    {
        timer.FUN_008d7f40(1.0f);
        elapsed = 0.0f;
        if (target && *g_011f1840.Bool() && target->TESObjectREFR_GetLocationEncounterZone() != actor->TESObjectREFR_GetLocationEncounterZone())
            SetTarget_00980830(0);
    }
    if (timer.FUN_008d7f80())
    {
        bool changed = false;
        if (GetProcedureFailed())
        {
            if (action84 && action84->IsField8One())
                InitFromArg(action84);
            if (action88 && action88->IsField8One())
                InitFromArg(action88);
            SetTarget_00980830(0);
        }
        else if (GetProcedureFinished())
        {
            ClearProcedures();
            state = 0;
            changed = true;
        }
        if (!target)
        {
            SetTarget_00980830(manager->SelectActor(actor));
            ClearProcedures();
            state = 0;
        }
        if (!target)
            return;
        brain->CombatState_Update();
        int next = 0;
        MovePoint origin_ = actor->TESObjectREFR_GetWorldLocation();
        MovePoint destination2 = target->TESObjectREFR_GetWorldLocation();
        if (brain->CombatState_CheckShouldFlee())
            next = 5;
        else if (brain->GetHasBufferedDetection_0097ee90())
        {
            if (origin_.BGSWorldLocation_GetDistanceSquared(&destination2) <
                *originalRuntimeFloatSetting498.Float() * *originalRuntimeFloatSetting498.Float())
                next = 1;
            else
                next = 2;
        }
        else if (!brain->IsElapsedTimeAtLeastSetting())
            next = 3;
        else if (manager->CombatGroup_IsSearching())
            next = 4;
        if (next != state)
        {
            ClearProcedures();
            unsigned char prior = brain->BSFaceGenNiNode_GetApplyRotToParent();
            brain->FUN_0097ce70(0);
            switch (next)
            {
            case 5:
                if (changed && prior)
                    brain->FUN_0097ce70(2);
                else if (origin_.BGSWorldLocation_GetDistanceSquared(&destination2) <
                         *originalRuntimeFloatSetting498.Float() * *originalRuntimeFloatSetting498.Float())
                {
                    brain->FUN_0097ce70(1);
                    MoveTarget goal;
                    goal.CombatLocation_CombatLocation();
                    if (brain->CombatState_FindBestFleeLocation(0, &goal, 12))
                    {
                        void* actionB;
                        if (goal.CombatLocation_GetFlag(1))
                            actionB = new IdleAction(12);
                        else
                            actionB = new TravelAction(&goal, DAT_011a56b4, 12);
                        SetMovementProcedure(actionB);
                    }
                }
                else
                    brain->FUN_0097ce70(2);
                break;
            case 1:
                SetActionProcedure(new SimpleAction);
                break;
            case 2: {
                MoveTarget goal;
                goal.CombatLocation_CombatLocation();
                goal.CombatLocation_SetTarget(target);
                if (brain->CombatState_CheckMovement_009a02a0(goal.ref_006815c0(), 1, 1))
                    SetMovementProcedure(new TravelAction(&goal, DAT_011a5654, 0));
                break;
            }
            case 3: {
                next = 0;
                MoveTarget goal;
                goal.CombatLocation_CombatLocation();
                MovePoint position7;
                position7.BGSWorldLocation_BGSWorldLocation();
                if (manager->GetDetectedTargetLocation(target, &position7) && brain->CombatState_CheckMovement_009a02a0(&position7, 1, 1))
                {
                    MovePoint current3 = actor->TESObjectREFR_GetWorldLocation();
                    if (current3.BGSWorldLocation_GetDistanceSquared(&position7) > 100.0)
                    {
                        goal.AssignV4(&position7);
                        SetMovementProcedure(new TravelAction(&goal, DAT_011a5654, 15));
                        next = 3;
                    }
                }
                break;
            }
            case 4:
                SetMovementProcedure(new SpecialAction);
                break;
            }
            state = next;
        }
        if (action88)
            action88->Update();
        if (action84)
            action84->Update();
        if (actor->IsPathing())
        {
            elapsed = timer.FUN_00435e00();
            actor->TESObjectREFR_SetAngleOnReferenceX(3.402823466e38f);
        }
        timer.FUN_008d7f40(1.0f);
    }
}

using ::memset;

extern void(__stdcall* DAT_00fdf0a4)(_RTL_CRITICAL_SECTION*);

struct FUN_0096a850
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    FUN_0096a850();
    ~FUN_0096a850();
};
struct GlobalObject_004ee810
{
    void* item;
    void* next;
    GlobalObject_004ee810();
    ~GlobalObject_004ee810();
};
struct PoolEntry96
{
    void* next;
    void* previous;
    void* data;
    unsigned int flags;
};
struct Pool96
{
    void* vtable;
    void* first;
    unsigned int count;
    PoolEntry96 entries[4096];
};
struct FUN_008c9330
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170;
    Pool96 pool;
    bool unk10180;
    FUN_008c9330();
    ~FUN_008c9330();
};
struct GlobalObject_0096a2d0
{
    unsigned int owner;
    unsigned int count;
    GlobalObject_0096a2d0();
    void Lock(const char*);
};
struct FUN_00905e30
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    FUN_00905e30();
    ~FUN_00905e30();
};
struct FUN_0086c6a0
{
    unsigned int initialCount;
    void* handle;
    unsigned int maximumCount;
    FUN_0086c6a0(unsigned int, unsigned int);
    ~FUN_0086c6a0();
};
struct SettingFloatHelper
{
    float* Float();
};
extern SettingFloatHelper originalRuntimeFloatSetting1024;
extern __int64 DAT_011e0e20;

struct FUN_0096d020
{
    int unk00000;
    FUN_0096a850 map;
    BSSimpleList<TESForm*>* lists[5];
    GlobalObject_004ee810 list58;
    GlobalObject_004ee810 list60;
    BSSimpleList<TESForm*> list68, list70, list78, list80;
    void* entries[50];
    int unk00150;
    float unk00154, unk00158;
    bool unk0015c, unk0015d;
    FUN_008c9330 pool;
    BSSimpleList<TESForm*> list102e4;
    int unk102ec, unk102f0, unk102f4, unk102f8, unk102fc;
    GlobalObject_0096a2d0 lock;
    int unk10308, unk1030c, unk10310, unk10314, unk10318, unk1031c;
    GlobalObject_0096a2d0 lock2;
    int unk10328, unk1032c, unk10330, unk10334, unk10338, unk1033c;
    int unk10340, unk10344, unk10348, unk1034c;
    int unk10350, unk10354, unk10358, unk1035c;
    FUN_00905e30 object;
    bool unk103a0, unk103a1, unk103a2;
    int unk103a4;
    bool unk103a8, unk103a9, unk103aa, unk103ab, unk103ac, unk103ad, unk103ae;
    int unk103b0;
    float unk103b4;
    int unk103b8;
    float unk103bc;
    FUN_0086c6a0 semaphore;
    FUN_0096d020();
};

// Constructor: sets flag bytes, zeroes lists and entries under lock, copies a float setting into unk103bc, and calls DAT_00fdf0a4 on DAT_011e0e20.
// @fnv 0x0096d020
FUN_0096d020::FUN_0096d020() : semaphore(0, 40)
{
    unk103a1 = true;
    unk103a0 = true;
    unk103a8 = true;
    unk103a9 = true;
    unk103aa = true;
    unk103ab = true;
    unk103ac = true;
    unk103a2 = false;
    unk0015c = false;
    unk0015d = false;
    unk103a4 = 0;
    unk10340 = 0;
    unk10344 = 0;
    memset(lists, 0, 4);
    unk103ad = false;
    unk103ae = false;
    unk103bc = *originalRuntimeFloatSetting1024.Float();
    unk103b0 = 0;
    unk00154 = 0.0f;
    unk00158 = 0.0f;
    unk103b8 = 0;
    unk103b4 = 0.0f;
    lock.Lock(0);
    memset(entries, 0, 200);
    unk00150 = 0;
    ((BSSpinLockUnlock_blk_00960000_od*)&lock)->Unlock();
    DAT_00fdf0a4((_RTL_CRITICAL_SECTION*)&DAT_011e0e20);
}
