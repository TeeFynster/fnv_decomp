
// src/staging/blk_00420000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <windows.h>
#include "../../include/BSStringT.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTMap.h"
// The legacy layout helpers overlap the shared scene-object templates.
#include "../../include/layout_support.h"
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../include/GO.h"
#include "../../include/NavMeshPtr.h"
#include "../../include/TESForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESSound.h"
#include "../../include/BSExtraData.h"
#include "../../include/BaseExtraList.h"
#include "../../include/Bound.h"
#include "../../include/ExtraDataList.h"
#include "../../include/ExtraLock.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiInterpController.h"
#include "../../include/NiObjectNET.h"
#include "../../include/TESLeveledList.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectTREE.h"
#include "../../include/BSMultiBoundAABB.h"
#include "../../include/BSMultiBoundOBB.h"
#include "../../include/BSMultiBound.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/CombatTargetTimestamp.h"
#include "../../include/TESSaveLoadGame.h"

// The shared timestamp declares only its float constructor. This adapter
// names the game's default constructor without copying the timestamp layout.
struct DefaultTimestamp : CombatTargetTimestamp
{
    DefaultTimestamp();
};

struct FUN_004216d0_shell
{
    bool ExtraDataList_HasLevCreaCalced();
};

// @fnv 0x004216d0
// src: COMMUNITY 0x004216d0
bool FUN_004216d0_shell::ExtraDataList_HasLevCreaCalced()
{
    return ((BaseExtraList*)this)->HasExtraData(0x2e);
}

struct FUN_0042ce90_class
{
    bool BGSLoadFormBuffer_GetReconstructedForm() const;
};

// @fnv 0x0042ce90
// src: COMMUNITY 0x0042ce90
bool FUN_0042ce90_class::BGSLoadFormBuffer_GetReconstructedForm() const
{
    return (*(const int*)((const char*)this + 0x28) & 8) ? true : false;
}

namespace fnv_0042e040 {
struct FUN_0042e040_shell
{
    void ExtraDataList_RemoveInfoGeneral();
};

// @fnv 0x0042e040
// src: XBOX_PDB 0x0042e040
void FUN_0042e040_shell::ExtraDataList_RemoveInfoGeneral()
{
    ((BaseExtraList*)this)->RemoveExtra((unsigned char)0x4d);
}
}  // namespace fnv_0042e040

namespace fnv_0042e110 {
struct FUN_0042e110 : BaseExtraList
{
    BSExtraData* GetExtraData();
};
// @fnv 0x0042e110
BSExtraData* FUN_0042e110::GetExtraData()
{
    BSExtraData* result = BaseExtraList::GetExtraData(0x55);
    return result;
}
}  // namespace fnv_0042e110

extern "C" void* __cdecl DAT_010159e8;

struct FUN_0042f4e0_class
{
    void* m_vtbl;
    void __thiscall NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool_NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool(void* arg);
    void* __thiscall SetVirtualTable_0042f4e0(void* arg);
};

// Calls FUN_0042fe10 on arg, sets m_vtbl to &DAT_010159e8, and returns this.
// @fnv 0x0042f4e0
// src: GUESS 0x0042f4e0 (confidence: low)
void* __thiscall FUN_0042f4e0_class::SetVirtualTable_0042f4e0(void* arg)
{
    NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool_NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool(arg);
    m_vtbl = &DAT_010159e8;
    return this;
}

struct FUN_0042ff10_cls
{
    void Helper_0042ff30(int);
};

// @fnv 0x0042ff10
// src: COMMUNITY 0x0042ff10
void BSSimpleArray_NavMeshPtr_1024_DefaultEqualFunction_NavMeshPtr(FUN_0042ff10_cls* pTarget, int b)
{
    pTarget->Helper_0042ff30(b);
}

extern int DAT_01015a08;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void ResetVirtualTableAndClear();
};
// @fnv 0x0042ff80
// src: GUESS 0x0042ff80 (confidence: medium)
void GlobalObject_00869f00::ResetVirtualTableAndClear()
{
    *(int*)this = (int)&DAT_01015a08;
    Clear(true);
}

extern void* DAT_01015968;

struct FUN_00435ef0 : public BSExtraData
{
    void SetVtableAndProcessState_00435ef0();
};

// Sets the vtable pointer, zeroes the field at offset 0xc, then calls the BSExtraData destructor.
// @fnv 0x00435ef0
// src: GUESS 0x00435ef0 (confidence: low)
void FUN_00435ef0::SetVtableAndProcessState_00435ef0()
{
    *reinterpret_cast<void**>(this) = &DAT_01015968;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) = 0;
    this->BSExtraData::~BSExtraData();
}

struct FUN_00437dd0_Class
{
    void* ExtraFollowerSwimBreadcrumbs_GetFirstCrumb();
};

// @fnv 0x00437dd0
// src: COMMUNITY 0x00437dd0
void* FUN_00437dd0_Class::ExtraFollowerSwimBreadcrumbs_GetFirstCrumb()
{
    return *(void**)&((Bound*)((char*)this + 0x20))->FUN_006815c0();
}

extern int DAT_01015fbc;
struct FUN_004383b0_Class
{
    void* p;
    void NiTMapBase_DFALL_NiTMapItem_WaterZone_int_WaterZone_int_NiTMapBase(void*);
    void* NiTMap_WaterZone_int_NiTMap(void* a);
};
// Calls FUN_004386b0 with a, sets p to the address of DAT_01015fbc, and returns this.
// @fnv 0x004383b0
// src: EXE 0x004383b0
void* FUN_004383b0_Class::NiTMap_WaterZone_int_NiTMap(void* apArg)
{
    NiTMapBase_DFALL_NiTMapItem_WaterZone_int_WaterZone_int_NiTMapBase(apArg);
    p = &DAT_01015fbc;
    return this;
}

extern "C" void __cdecl FUN_00438820(void*);
extern char DAT_01015fdc;

struct FUN_004383e0_class
{
    void* p;
    void* __thiscall BSMap_TESFaction_bool_BSMap(void* a);
};

// Calls FUN_00438820 with this and a, sets p to the address of DAT_01015fdc, and returns this.
// @fnv 0x004383e0
// src: EXE 0x004383e0
void* __thiscall FUN_004383e0_class::BSMap_TESFaction_bool_BSMap(void* apArg)
{
    ((void(__thiscall*)(void*, void*))FUN_00438820)(this, apArg);
    p = &DAT_01015fdc;
    return this;
}

extern int DAT_01015ffc;

struct AX
{
    void BSSimpleArray_float_1024_InitialSetup(unsigned int, unsigned int);
    AX* BSSimpleArray_DismemberedLimb_1024_BSSimpleArray();
};

// @fnv 0x00438570
// src: EXE 0x00438570
AX* AX::BSSimpleArray_DismemberedLimb_1024_BSSimpleArray()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_01015ffc;
    BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

namespace fnv_004385a0 {
extern int DAT_01015ffc;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_004385a0Class
{
    void ResetVirtualTableAndClear_004385a0();
};
// @fnv 0x004385a0
// src: GUESS 0x004385a0 (confidence: medium)
void FUN_004385a0Class::ResetVirtualTableAndClear_004385a0()
{
    *(int*)this = (int)&DAT_01015ffc;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_004385a0

// @fnv 0x004385c0
template <>
BSSimpleArray<CombatTargetTimestamp, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

namespace fnv_00438690 {
extern int DAT_01016024;

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void UpdateState_00438690();
};

// @fnv 0x00438690
// src: GUESS 0x00438690 (confidence: low)
void GlobalObject_00869f00::UpdateState_00438690()
{
    p = &DAT_01016024;
    Clear(true);
}
}  // namespace fnv_00438690

void __cdecl Deallocate(void*);

struct FUN_00438940_Class
{
    void __thiscall BSMap_DWORD_bool_DeleteItem(void* p);
};

// Sets byte 8 of p to 0, then passes p to Deallocate.
// @fnv 0x00438940
// src: COMMUNITY 0x00438940
void __thiscall FUN_00438940_Class::BSMap_DWORD_bool_DeleteItem(void* p)
{
    ((char*)p)[8] = 0;
    void* tmp = p;
    Deallocate(tmp);
}

struct FUN_00438b90_class
{
    char BSSimpleArray_NavMeshInfo_1024_ShouldGrow();
};

// @fnv 0x00438b90
// src: XBOX_PDB 0x00438b90
char FUN_00438b90_class::BSSimpleArray_NavMeshInfo_1024_ShouldGrow()
{
    if (*(int*)((char*)this + 8) == *(int*)((char*)this + 12))
        return 1;
    return 0;
}

struct FUN_00591300_shell
{
    void BSStringT_Thunk();
};

struct FUN_00438bf0_shell : FUN_00591300_shell
{
    void ForwardCall_00438bf0();
};

// @fnv 0x00438bf0
// src: GUESS 0x00438bf0 (confidence: low)
void FUN_00438bf0_shell::ForwardCall_00438bf0()
{
    BSStringT_Thunk();
}

struct FUN_00438f10_Class
{
    bool EvaluateValue_00438f10();
};

// @fnv 0x00438f10
// src: GUESS 0x00438f10 (confidence: low)
bool FUN_00438f10_Class::EvaluateValue_00438f10()
{
    if (*(unsigned char*)((char*)this + 0xc) & 4)
        return true;
    else
        return false;
}

struct FUN_00438f30_Class
{
    unsigned int MapMarkerData_GetMarkerType();
};

// @fnv 0x00438f30
// src: XBOX_PDB 0x00438f30
unsigned int FUN_00438f30_Class::MapMarkerData_GetMarkerType()
{
    return *(unsigned short*)(this + 0xe);
}

struct FUN_004392c0_shell
{
    void FUN_004392c0();
    void ForwardCall_00439320();
};

// @fnv 0x00439320
// src: GUESS 0x00439320 (confidence: low)
void FUN_004392c0_shell::ForwardCall_00439320()
{
    FUN_004392c0();
}

// @fnv 0x00439340
// src: COMMUNITY 0x00439340
void NiObjectNET::NiAlphaProperty_SetSrcBlendMode(unsigned short a)
{
    SetField_00439360(a, 0x1e, 1);
}

// Calls FUN_00439360 with the given unsigned short and the constants 0x1e0 and 5.
// @fnv 0x00439390
// src: COMMUNITY 0x00439390
void NiObjectNET::NiAlphaProperty_SetDestBlendMode(unsigned short ausValue)
{
    SetField_00439360(ausValue, 0x1e0, 5);
}

// Stores the given NiPoint3 into the object at offset 0x18.
// @fnv 0x00439680
// src: COMMUNITY 0x00439680
void Bound::BSMultiBound_SetHalfExtents(const NiPoint3& aPoint)
{
    struct PointWords { unsigned int x, y, z; };
    *(PointWords*)((char*)this + 0x18) = *(const PointWords*)&aPoint;
}

struct FUN_0043b260_Class
{
    unsigned short m_0018;
    bool __thiscall NiZBufferProperty_IsEqualFast(unsigned short* pArg);
};

// Compares the 16-bit value at offset 0x18 of this object with the same field of pArg and returns whether they are equal.
// @fnv 0x0043b260
// src: COMMUNITY 0x0043b260
bool __thiscall FUN_0043b260_Class::NiZBufferProperty_IsEqualFast(unsigned short* pOther)
{
    return *(unsigned short*)((char*)this + 0x18) == *(unsigned short*)((char*)pOther + 0x18);
}

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void NiAVObject_SetSelectiveUpdateTransformsOverride(bool enabled);
};

// @fnv 0x0043b350
// src: COMMUNITY 0x0043b350
void TaskQueueInterface::NiAVObject_SetSelectiveUpdateTransformsOverride(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x80);
}


struct FUN_0043b5b0_shell
{
    void hkpWorldObject_markForRead();
};

// @fnv 0x0043b5b0
// src: COMMUNITY 0x0043b5b0
void FUN_0043b5b0_shell::hkpWorldObject_markForRead()
{
    ((TESForm*)((TESObjectTREE*)this)->GetData())->Revert(1);
}

struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* AssignInternedString(FUN_0043ba10_shell*);
};

struct FUN_0043b9f0_shell
{
    void NiControllerSequence_SetName(FUN_0043ba10_shell* p);
};

// @fnv 0x0043b9f0
// src: COMMUNITY 0x0043b9f0
void FUN_0043b9f0_shell::NiControllerSequence_SetName(FUN_0043ba10_shell* p)
{
    ((FUN_0043ba10_shell*)((char*)this + 8))->AssignInternedString(p);
}


struct FUN_0043baa0_class
{
    void BSAnimGroupSequence_SetAnimGroup(void* p);
};

// @fnv 0x0043baa0
// src: COMMUNITY 0x0043baa0
void FUN_0043baa0_class::BSAnimGroupSequence_SetAnimGroup(void* p)
{
    *(GO*)((char*)this + 0x74) = p;
}

bool __cdecl MLGetFlag_1(unsigned char);

struct FUN_0043fab0_class
{
    bool __thiscall QueuedHelmet_GetFinishedQueuing();
};

// @fnv 0x0043fab0
// src: XBOX_PDB 0x0043fab0
bool __thiscall FUN_0043fab0_class::QueuedHelmet_GetFinishedQueuing()
{
    return MLGetFlag_1(reinterpret_cast<unsigned char*>(this)[0x120]);
}

extern "C" void* __cdecl _NiFreeAlias(void*);
extern int DAT_01015a1c;

// @fnv 0x0042fee0
template <>
NiTMapBase<DFALL<NiTMapItem<TESObjectREFR*, bool> >, TESObjectREFR*, bool>::~NiTMapBase()
{
    RemoveAll();
    _NiFreeAlias(m_ppkHashTable);
}

extern int DAT_01015f24;

struct FUN_00436ac0 : BSExtraData
{
    FUN_00436ac0();
};

// Initialises the base with tag 0x55, installs the vtable pointer from DAT_01015f24, and zeroes the field at offset 0xc.
// @fnv 0x00436ac0
FUN_00436ac0::FUN_00436ac0() : BSExtraData(0x55)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) = 0;
}

class WaterZone;
// RTTI at vtable 0x01016038 identifies NiTMapBase<DFALL<NiTMapItem<WaterZone*, int> >, WaterZone*, int>.
// @fnv 0x00438780
template <>
NiTMapBase<DFALL<NiTMapItem<WaterZone*, int> >, WaterZone*, int>::~NiTMapBase()
{
    RemoveAll();
    _NiFreeAlias(m_ppkHashTable);
}


void __cdecl Deallocate(void*);
// Calls FUN_0042fa40, then deallocates this if the flags bit 0 is set, and returns this.
// @fnv 0x0042ffa0
void* __thiscall NavMeshPtr::FUN_0042ffa0(unsigned int flags)
{
    this->Object_ForwardCall_0042fa40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0042ffd0_cls
{
    void* __thiscall FUN_0042ffd0(unsigned int flags);
};

// Calls the base cleanup, then frees this object when the flags bit 0 is set, and returns this.
// @fnv 0x0042ffd0
void* __thiscall FUN_0042ffd0_cls::FUN_0042ffd0(unsigned int flags)
{
    ((NiTMapBase<DFALL<NiTMapItem<TESObjectREFR*, bool> >, TESObjectREFR*, bool>*)this)->NiTMapBase::~NiTMapBase();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00435ec0 : public BSExtraData
{
    void* p;
    FUN_00435ec0(void* a);
};
// Initialises the object with base value 0x46, sets its vtable to DAT_01015968 and stores the passed pointer in p.
// @fnv 0x00435ec0
FUN_00435ec0::FUN_00435ec0(void* a) : BSExtraData(0x46)
{
    p = a;
}

struct FUN_00435f20_class : public BSExtraData
{
    float m_fValue;
    FUN_00435f20_class(float f);
};
// @fnv 0x00435f20
FUN_00435f20_class::FUN_00435f20_class(float f) : BSExtraData(0x48)
{
    m_fValue = f;
}

void __cdecl Deallocate(void*);
struct FUN_00435f80_shell
{
    void __thiscall FUN_00435f80();
};
struct FUN_00435f50_class : FUN_00435f80_shell
{
    void* __thiscall FUN_00435f50(unsigned int flags);
};
// Calls FUN_00435f80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00435f50
void* __thiscall FUN_00435f50_class::FUN_00435f50(unsigned int flags)
{
    FUN_00435f80();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void* DAT_01015974;
struct FUN_00436090 : public BSExtraData
{
    unsigned char c;
    FUN_00436090(unsigned char);
};
// @fnv 0x00436090
FUN_00436090::FUN_00436090(unsigned char x) : BSExtraData(0x4e)
{
    c = x;
}

void __cdecl Deallocate(void*);
struct FUN_00436150_Class
{
    void __thiscall FUN_00436180();
    void* __thiscall FUN_00436150(unsigned int flags);
};
// @fnv 0x00436150
void* __thiscall FUN_00436150_Class::FUN_00436150(unsigned int flags)
{
    FUN_00436180();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00436390_Class
{
    void __thiscall FUN_004363c0();
    void* __thiscall FUN_00436390(unsigned int flags);
};

// @fnv 0x00436390
void* FUN_00436390_Class::FUN_00436390(unsigned int flags)
{
    FUN_004363c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_004364b0_Class
{
    void __thiscall FUN_004364e0();
    void* __thiscall FUN_004364b0(unsigned int flags);
};
// Calls FUN_004364e0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x004364b0
void* FUN_004364b0_Class::FUN_004364b0(unsigned int flags)
{
    FUN_004364e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_004365d0_class
{
    void* __thiscall FUN_00436600();
    void* __thiscall FUN_004365d0(unsigned int flags);
};
// Calls FUN_00436600, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004365d0
void* __thiscall FUN_004365d0_class::FUN_004365d0(unsigned int flags)
{
    FUN_00436600();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void FUN_00436720();
void __cdecl Deallocate(void*);

struct FUN_004366f0_class
{
    void __thiscall FUN_00436720();
    void* __thiscall FUN_004366f0(unsigned int flags);
};

// Calls FUN_00436720, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004366f0
void* __thiscall FUN_004366f0_class::FUN_004366f0(unsigned int flags)
{
    FUN_00436720();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void Deallocate(void*);
void FUN_00436bb0();
struct FUN_00436af0_Class
{
    void FUN_00436bb0();
    void* FUN_00436af0(unsigned int flags);
};
// @fnv 0x00436af0
void* FUN_00436af0_Class::FUN_00436af0(unsigned int flags)
{
    FUN_00436bb0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl FUN_00438720(FUN_004383b0_Class*);
struct FUN_00438410_Class
{
    void* __thiscall FUN_00438410(unsigned int flags);
};
// Calls FUN_00438720, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00438410
void* __thiscall FUN_00438410_Class::FUN_00438410(unsigned int flags)
{
    ((NiTMap<WaterZone*, int>*)this)->NiTMap::~NiTMap();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// RTTI at vtable 0x01016058 identifies BSMapBase<TESFaction*, bool>.
class FactionMembershipMapBase
{
  public:
    virtual ~FactionMembershipMapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FactionMembershipMap : public FactionMembershipMapBase
{
  public:
    virtual ~FactionMembershipMap();
};

struct FUN_00438440_Class
{
    void* __thiscall FUN_00438440(unsigned int flags);
};
// @fnv 0x00438440
void* __thiscall FUN_00438440_Class::FUN_00438440(unsigned int flags)
{
    ((FactionMembershipMap*)this)->FactionMembershipMap::~FactionMembershipMap();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void Deallocate(void*);
void ResetVirtualTableAndClear_004385a0();
struct FUN_00438970_class
{
    void __thiscall ResetVirtualTableAndClear_004385a0();
    void* __thiscall FUN_00438970(unsigned int flags);
};
// @fnv 0x00438970
void* __thiscall FUN_00438970_class::FUN_00438970(unsigned int flags)
{
    ResetVirtualTableAndClear_004385a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

// Entry-point adapter for the scalar deleting destructor; it carries no map layout.
struct WaterZoneMapBaseDeletion
{
    void* FUN_00438a00(unsigned int flags);
};
// @fnv 0x00438a00
void* WaterZoneMapBaseDeletion::FUN_00438a00(unsigned int flags)
{
    ((NiTMapBase<DFALL<NiTMapItem<WaterZone*, int> >, WaterZone*, int>*)this)->NiTMapBase::~NiTMapBase();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00438900_class
{
    void __thiscall ReleaseStorage_00438900();
};

struct FUN_00438a30_class
{
    void* __thiscall FUN_00438a30(unsigned int flags);
};

// Calls FUN_00438900 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00438a30
void* __thiscall FUN_00438a30_class::FUN_00438a30(unsigned int flags)
{
    ((FUN_00438900_class*)this)->ReleaseStorage_00438900();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct PointerFlagNode
{
    void _ref_00905330(const unsigned int&);
};
struct FUN_004207e0Class
{
    PointerFlagNode* ExtraDataList_GetRoomLinkedRefData();
    void ExtraDataList_RemovePortalLinkedRoomRef(unsigned int);
};
// @fnv 0x00420da0
// src: COMMUNITY 0x00420da0
void FUN_004207e0Class::ExtraDataList_RemovePortalLinkedRoomRef(unsigned int a1)
{
    PointerFlagNode* p = ExtraDataList_GetRoomLinkedRefData();
    if (p)
        p->_ref_00905330(a1);
}

struct Flt
{
    operator unsigned int();
};
struct Holder00420dd0 : BaseExtraList
{
    unsigned int __thiscall ExtraDataList_GetPortal();
};
// @fnv 0x00420dd0
// src: XBOX_PDB 0x00420dd0
unsigned int __thiscall Holder00420dd0::ExtraDataList_GetPortal()
{
    BSExtraData* e = GetExtraData(0x78);
    if (e)
        return (unsigned int)(*(Flt*)((char*)e + 0xc));
    return 0;
}

extern int DAT_01015998;

struct FUN_0042cba0_class : public BSExtraData
{
    int c;
    int d;
    FUN_0042cba0_class();
};

// Initialises the object with base value 0x6e, sets its vtbl to DAT_01015998, and zeroes fields c and d.
// @fnv 0x0042cba0
FUN_0042cba0_class::FUN_0042cba0_class() : BSExtraData(0x6e)
{
    c = 0;
    d = 0;
}

struct FHolder_42cbe0 : BSExtraData
{
    void* __thiscall ExtraPackageData_ExtraPackageData();
};
extern int DAT_010151fc;
// Initialises the object with BSExtraData(0x70), installs the vtable pointer DAT_010151fc, zeroes the field at offset 0xc, and returns this.
// @fnv 0x0042cbe0
// src: EXE 0x0042cbe0
void* __thiscall FHolder_42cbe0::ExtraPackageData_ExtraPackageData()
{
    this->BSExtraData::BSExtraData(0x70);
    *(void**)this = (void*)&DAT_010151fc;
    *(int*)((char*)this + 0xc) = 0;
    return this;
}

struct FUN_0042cc10_class
{
    int m0;
    int m4;
    float m8;
    FUN_0042cc10_class* __thiscall SayOnceTopicInfos_SayOnceTopicInfos_0();
};
// Initialises the object's fields to zero, -1 and -1.0f, then returns this.
// @fnv 0x0042cc10
// src: COMMUNITY 0x0042cc10
FUN_0042cc10_class* __thiscall FUN_0042cc10_class::SayOnceTopicInfos_SayOnceTopicInfos_0()
{
    m0 = 0;
    m4 = -1;
    m8 = -1.0f;
    return this;
}

struct FUN_00432470 : public BSExtraData
{
    int x;
    FUN_00432470(int v);
    ~FUN_00432470();
};
struct FUN_0042dee0_shell
{
    void __thiscall ExtraDataList_SetInfoGeneralTopic(int v);
};
// Looks up extra data of type 0x4d; if absent, creates a new FUN_00432470 with v and adds it, otherwise stores v at offset 0xc.
// @fnv 0x0042dee0
// src: XBOX_PDB 0x0042dee0
void __thiscall FUN_0042dee0_shell::ExtraDataList_SetInfoGeneralTopic(int aiValue)
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(0x4d);
    if (!extra)
    {
        extra = new FUN_00432470(aiValue);
        ((BaseExtraList*)this)->AddExtra(extra);
    }
    else
    {
        *(int*)((char*)extra + 0xc) = aiValue;
    }
}

struct FUN_0042df90_shell
{
    ExtraLock* ExtraDataList_GetInfoGeneralTopic(int a);
};
// @fnv 0x0042df90
// src: XBOX_PDB 0x0042df90
ExtraLock* FUN_0042df90_shell::ExtraDataList_GetInfoGeneralTopic(int a)
{
    ExtraLock* p = 0;
    ExtraDataList* e = (ExtraDataList*)((ExtraDataList*)this)->GetExtraData(0x4d);
    if (e && (p = (ExtraLock*)*(void**)((char*)e + 0xc)) && p->MenuTopic_GetResponseListEmpty())
        p->MenuTopic_FillResponseList(a);
    return p;
}

extern int DAT_01015980;
struct FUN_0042e210_Class : public BSExtraData
{
    int c;
    int d;
    FUN_0042e210_Class(int x, int y);
};
// Initializes the object with base BSExtraData(0x5b), sets vtbl to DAT_01015980, and stores x into c and y into d.
// @fnv 0x0042e210
FUN_0042e210_Class::FUN_0042e210_Class(int x, int y) : BSExtraData(0x5b)
{
    c = x;
    d = y;
}

extern void* DAT_010159bc;
struct FUN_0042e650_class : BSExtraData
{
    unsigned char c;
    FUN_0042e650_class(unsigned char c);
};
// Initialises the object with base value 0x8e, sets its vtbl to DAT_010159bc and stores c in field c.
// @fnv 0x0042e650
FUN_0042e650_class::FUN_0042e650_class(unsigned char aucValue) : BSExtraData(0x8e)
{
    this->c = aucValue;
}

struct G00559a40
{
    void NiRefObject_IncRefCount();
};
struct FUN_0042fdc0_class
{
    NiAVObject* m_pObject;
    NiAVObject* __thiscall AssignRetainedObject_0042fdc0(NiAVObject** arg);
};
// @fnv 0x0042fdc0
// src: GUESS 0x0042fdc0 (confidence: medium)
NiAVObject* __thiscall FUN_0042fdc0_class::AssignRetainedObject_0042fdc0(NiAVObject** apObject)
{
    if (m_pObject != *apObject)
    {
        if (m_pObject)
            ((NiAVObject*)((char*)m_pObject + 0x1c))->NiRefObject_DecRefCount();
        m_pObject = *apObject;
        if (m_pObject)
            ((G00559a40*)((char*)m_pObject + 0x1c))->NiRefObject_IncRefCount();
    }
    return (NiAVObject*)this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int c, unsigned int count);

struct FUN_0042fe10_class
{
    void* m_pName;
    unsigned int m_uiCount;
    void* m_pData;
    unsigned int m_uiSize;
    void* __thiscall NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool_NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool(unsigned int count);
};

// @fnv 0x0042fe10
// src: COMMUNITY 0x0042fe10
void* FUN_0042fe10_class::NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool_NiTMapBase_DFALL_NiTMapItem_TESObjectREFR_bool_TESObjectREFR_bool(unsigned int count)
{
    m_pName = &DAT_01015a1c;
    m_uiCount = count;
    m_uiSize = 0;
    unsigned int size = m_uiCount * 4;
    m_pData = NiMalloc(size);
    memset(m_pData, 0, m_uiCount * 4);
    return this;
}

struct FUN_0042ff80_s
{
    void __thiscall ResetVirtualTableAndClear();
};
void __cdecl _Deallocate(void*);
struct FUN_0042ff50_host : FUN_0042ff80_s
{
    void* __thiscall FUN_0042ff50(unsigned int flags);
};
// Calls FUN_0042ff80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0042ff50
void* __thiscall FUN_0042ff50_host::FUN_0042ff50(unsigned int flags)
{
    ResetVirtualTableAndClear();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern void* _EmptyFS;
void* __cdecl NiGlobalStringTable_GetRealBufferStart(void*);
void __cdecl FinishScriptRunLock(void*);

// If the object at p is not _EmptyFS, obtains a value via FUN_00438210 and passes it to FinishScriptRunLock.
// @fnv 0x004381d0
// src: XBOX_PDB 0x004381d0
void NiGlobalStringTable_DecRefCount(void* p)
{
    if (*(void**)p == _EmptyFS)
        return;
    void* r = NiGlobalStringTable_GetRealBufferStart(p);
    FinishScriptRunLock(r);
}

// @fnv 0x00438210
// src: COMMUNITY 0x00438210
int __cdecl NiGlobalStringTable_GetRealBufferStart(int* p)
{
    return *p - 8;
}

extern int DAT_01016024;
struct FUN_00438660_class
{
    void* vtable;
    FUN_00438660_class* SetVirtualTableAndProcessState_00438660();
};
// Sets the vtable to DAT_01016024, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00438660
// src: GUESS 0x00438660 (confidence: low)
FUN_00438660_class* FUN_00438660_class::SetVirtualTableAndProcessState_00438660()
{
    vtable = &DAT_01016024;
    reinterpret_cast<AX*>(this)->BSSimpleArray_float_1024_InitialSetup(0, 0);
    return this;
}

extern void* DAT_01016058;
void __cdecl Deallocate(void*);

// @fnv 0x00438900
// src: GUESS 0x00438900 (confidence: medium)
void __thiscall FUN_00438900_class::ReleaseStorage_00438900()
{
    *reinterpret_cast<void**>(this) = &DAT_01016058;
    if (*(void**)((char*)this + 8))
    {
        void* p = *(void**)((char*)this + 8);
        Deallocate(p);
    }
}

struct FNStub
{
    const char* GetFullName();
};
void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
void __cdecl TESForm_AddChunk_00485950(unsigned int, unsigned int);
struct FUN_00438c10_Class : public FNStub
{
    void __thiscall ReleaseStorage_00438c10();
};
// @fnv 0x00438c10
// src: GUESS 0x00438c10 (confidence: low)
void __thiscall FUN_00438c10_Class::ReleaseStorage_00438c10()
{
    TESForm_AddChunk_3(0x4d414e46, *(unsigned char*)((char*)this + 0xc));
    TESForm_AddChunkArray(0x4c4c5546, (void*)GetFullName(), ((TESModel*)this)->GetModelLength() + 1);
    TESForm_AddChunk_00485950(0x4d414e54, *(unsigned short*)((char*)this + 0xe));
    if (*(void**)((char*)this + 0x10))
    {
        unsigned int r = ((TESSound*)*(void**)((char*)this + 0x10))->Deallocate();
        TESForm_AddChunk_00485910(0x31494d57, r);
    }
}

extern "C" void TESForm_AddChunkArray_00485710(unsigned int, unsigned int*, unsigned int);
struct FUN_00438f90_Class
{
    bool EvaluateValue_00439150();
    void EvaluateValue_00438f90();
};
// @fnv 0x00438f90
// src: GUESS 0x00438f90 (confidence: low)
void FUN_00438f90_Class::EvaluateValue_00438f90()
{
    if (EvaluateValue_00439150())
        return;
    TESForm_AddChunkArray_00485710(0x4f424d58, (unsigned int*)this, 3);
}

struct Unk_00439120
{
    int m0;
    int m4;
    int m8;
    void MultiBoundMarkerData_Copy(Unk_00439120* p);
};
// Copies the contents of the object pointed to by p into this object when p is non-null.
// @fnv 0x00439120
// src: COMMUNITY 0x00439120
void Unk_00439120::MultiBoundMarkerData_Copy(Unk_00439120* apSource)
{
    if (apSource)
        *this = *apSource;
}

struct S_00439150
{
    bool __thiscall _Call_439090(const NiPoint3&);
    bool __thiscall EvaluateValue_00439150();
};
extern int DAT_011c3ae4;
// @fnv 0x00439150
// src: GUESS 0x00439150 (confidence: low)
bool __thiscall S_00439150::EvaluateValue_00439150()
{
    if (_Call_439090(*(const NiPoint3*)&DAT_011c3ae4))
    {
        return false;
    }
    return true;
}

struct MyPoint439180
{
    float x;
    float y;
    float z;
    MyPoint439180* __thiscall ScaleComponents(float);
};
// Multiplies x, y and z by fScalar and returns this.
// @fnv 0x00439180
// src: GUESS 0x00439180 (confidence: medium)
MyPoint439180* __thiscall MyPoint439180::ScaleComponents(float fScalar)
{
    x *= fScalar;
    y *= fScalar;
    z *= fScalar;
    return this;
}

struct Mat9
{
    int v[9];
};
// Copies the 9-element matrix src into the object's m field.
// @fnv 0x004396b0
// src: COMMUNITY 0x004396b0
void __thiscall Bound::BSMultiBoundAABB_SetAxis(const Matrix& aMatrix)
{
    *(Mat9*)((char*)this + 0x24) = *(const Mat9*)&aMatrix;
}

struct FUN_00439f50_class
{
    void NiMatrix3_GetCol(unsigned int col, NiPoint3* out);
};
// Reads three floats at offsets col*4, col*4+0xc and col*4+0x18 from this into out as x, y and z.
// @fnv 0x00439f50
// src: XBOX_PDB 0x00439f50
void FUN_00439f50_class::NiMatrix3_GetCol(unsigned int uiColumn, NiPoint3* out)
{
    out->x = *(float*)((char*)this + uiColumn * 4);
    out->y = *(float*)((char*)this + uiColumn * 4 + 0xc);
    out->z = *(float*)((char*)this + uiColumn * 4 + 0x18);
}

struct Node
{
    void* p;
};
struct Helper62d0
{
    void* operator=(const void*);
};
struct ScriptPool
{
    Node* NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
    void NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(Node* p);
    void NiAVObject_AttachProperty_00439fd0(const void* arg);
};
// Gets a node from the pool, assigns arg to the node's field at offset 8, then releases the node back to the pool.
// @fnv 0x00439fd0
// src: XBOX_PDB 0x00439fd0
void __thiscall ScriptPool::NiAVObject_AttachProperty_00439fd0(const void* arg)
{
    Node* p = NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
    ((Helper62d0*)((char*)p + 8))->operator=(arg);
    NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(p);
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0043a9a0_class
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    unsigned int l;
    unsigned int m;
    unsigned int n;
    unsigned int o;
    unsigned int p;
    unsigned int q;
    unsigned int r;
    unsigned int s;
    unsigned int t;
    unsigned int u;
    unsigned int v;
    unsigned int w;
    unsigned int x;
    unsigned int y;
    unsigned int z;
    void __thiscall LoadFields();
};

// @fnv 0x0043a9a0
// src: GUESS 0x0043a9a0 (confidence: medium)
void __thiscall FUN_0043a9a0_class::LoadFields()
{
    g_TESSaveLoadGame->ReadTypedData((char*)this + 4, 0xc);
    g_TESSaveLoadGame->ReadTypedData((char*)this + 0x10, 0xc);
    unsigned int v;
    g_TESSaveLoadGame->FUN_00857aa0(&v, 4);
    a = v;
}

namespace fnv_0043b250 {
struct Flt
{
    operator unsigned int();
};
extern Flt DAT_011f4438;
// @fnv 0x0043b250
// src: COMMUNITY 0x0043b250
unsigned int __cdecl NiVertexColorProperty_GetDefault()
{
    return DAT_011f4438;
}
}  // namespace fnv_0043b250

namespace fnv_0043b2a0 {
struct Flt
{
    operator unsigned int();
};
extern Flt DAT_011f4444;

// @fnv 0x0043b2a0
// src: COMMUNITY 0x0043b2a0
unsigned int __cdecl NiZBufferProperty_GetDefault()
{
    return DAT_011f4444;
}
}  // namespace fnv_0043b2a0

struct S_0043b320
{
    char _pad0[0x38];
    TaskQueueInterface** arr;
    void __thiscall NiMultiTargetTransformController_SetInterpolatorTarget(unsigned short a, TaskQueueInterface* b);
};
// Stores b in arr[a] and, when b is non-null, calls b->FUN_0043b350(true).
// @fnv 0x0043b320
// src: COMMUNITY 0x0043b320
void __thiscall S_0043b320::NiMultiTargetTransformController_SetInterpolatorTarget(unsigned short usIndex, TaskQueueInterface* pTaskQueue)
{
    arr[usIndex] = pTaskQueue;
    if (pTaskQueue)
        pTaskQueue->NiAVObject_SetSelectiveUpdateTransformsOverride(true);
}

namespace fnv_0043ba60 {
extern int _EmptyFS;
void* __cdecl NiGlobalStringTable_GetRealBufferStart(void*);
int __cdecl InitScriptRunLock(void*);
// @fnv 0x0043ba60
// src: XBOX_PDB 0x0043ba60
void __cdecl NiGlobalStringTable_IncRefCount(int* p)
{
    void* v;
    if (*p == _EmptyFS)
    {
    }
    else
    {
        v = NiGlobalStringTable_GetRealBufferStart(p);
        InitScriptRunLock(v);
    }
}
}  // namespace fnv_0043ba60

struct FUN_00435820 : public BSExtraData
{
    FUN_00435820();
    ~FUN_00435820();
    char m_data[4];
};
struct FUN_00420e00_cls : public BaseExtraList
{
    void ExtraDataList_SetPortal(void* p);
};
// Stores p in the extra data of type 0x78, creating and adding it if absent, or removes that extra data when p is null.
// @fnv 0x00420e00
// src: COMMUNITY 0x00420e00
void FUN_00420e00_cls::ExtraDataList_SetPortal(void* apData)
{
    if (apData)
    {
        FUN_00435820* e = (FUN_00435820*)GetExtraData(0x78);
        if (e)
        {
            ((GO*)((char*)e + 0xc))->operator=(apData);
        }
        else
        {
            e = new FUN_00435820;
            ((GO*)((char*)e + 0xc))->operator=(apData);
            AddExtra(e);
        }
    }
    else
    {
        RemoveExtra((unsigned char)0x78);
    }
}

struct FUN_00421600_Class : BaseExtraList
{
    void ExtraDataList_SetNoRumors(unsigned char val);
};
// Stores val in the byte at offset 0xc of extra data 0x4e, creating a new FUN_00436090 extra if none exists.
// @fnv 0x00421600
// src: XBOX_PDB 0x00421600
void FUN_00421600_Class::ExtraDataList_SetNoRumors(unsigned char aucValue)
{
    BSExtraData* extra = GetExtraData(0x4e);
    if (extra)
        *(unsigned char*)((char*)extra + 0xc) = aucValue;
    else
    {
        extra = (BSExtraData*)new FUN_00436090(aucValue);
        AddExtra(extra);
    }
}

extern int DAT_01015cd8;
struct ListX
{
    void* m_pInventoryEntryData;
    void* m_pNext;
    void* m_pListObject;
    ~ListX();
};
struct FUN_00433830 : public BSExtraData
{
    ListX m_kEntryList;
    ~FUN_00433830();
};
void __cdecl FreeActivateList(ListX*);
// @fnv 0x00433830
FUN_00433830::~FUN_00433830()
{
    FreeActivateList(&m_kEntryList);
}

extern "C" void _fnv_zlib_memset(void* p, int c, unsigned int n);
struct FUN_00438820_Class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00438820_Class(int c);
};
// Sets the vtable, stores the count, and, when count is nonzero, allocates count*4 zeroed bytes into data.
// @fnv 0x00438820
FUN_00438820_Class::FUN_00438820_Class(int aiCount)
{
    vtbl = &DAT_01016058;
    count = aiCount;
    pad = 0;
    if (aiCount)
    {
        unsigned int size = count * 4;
        void* p3 = operator new(size);
        data = p3;
        _fnv_zlib_memset(data, 0, count * 4);
    }
}

struct FUN_0042e5a0_class
{
    void ExtraDataList_SetIsModding(unsigned char type);
};
// @fnv 0x0042e5a0
// src: COMMUNITY 0x0042e5a0
void FUN_0042e5a0_class::ExtraDataList_SetIsModding(unsigned char type)
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(0x8e);
    if (!extra)
    {
        extra = (BSExtraData*)new FUN_0042e650_class(type);
        ((BaseExtraList*)this)->AddExtra(extra);
    }
    else
    {
        ((TESLeveledList*)extra)->ExtraWeaponModFlags_SetWeaponModFlags(type);
    }
}

extern int DAT_01016038;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int c, unsigned int count);
struct FUN_004386b0_Class
{
    void* p;
    void* __thiscall NiTMapBase_DFALL_NiTMapItem_WaterZone_int_WaterZone_int_NiTMapBase(void* a);
};
// Stores a pointer and a count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x004386b0
// src: EXE 0x004386b0
void* FUN_004386b0_Class::NiTMapBase_DFALL_NiTMapItem_WaterZone_int_WaterZone_int_NiTMapBase(void* auiCount)
{
    p = &DAT_01016038;
    *(void**)((char*)this + 4) = auiCount;
    *(int*)((char*)this + 0xc) = 0;
    unsigned int size = *(int*)((char*)this + 4) << 2;
    *(void**)((char*)this + 8) = NiMalloc(size);
    memset(*(void**)((char*)this + 8), 0, *(int*)((char*)this + 4) << 2);
    return this;
}

struct NiPoint3Set
{
    void Set(float x, float y, float z);
};
struct FUN_00439ef0_class : public NiPoint3
{
    NiPoint3* SubtractIntoVector(NiPoint3* a, const NiPoint3& b);
};
// Subtracts b from this NiPoint3, stores the result in a, and returns a.
// @fnv 0x00439ef0
// src: GUESS 0x00439ef0 (confidence: high)
NiPoint3* FUN_00439ef0_class::SubtractIntoVector(NiPoint3* apResult, const NiPoint3& arSubtrahend)
{
    ((NiPoint3Set*)apResult)->Set(x - arSubtrahend.x, y - arSubtrahend.y, z - arSubtrahend.z);
    return apResult;
}

struct FUN_0043b3b0_class
{
    unsigned short NiMultiTargetTransformController_HasTarget(unsigned int value);
};
// Scans the array at offset 0x38 up to the count at 0x3c and returns the index of the first element equal to value, or INVALID_INDEX if none matches.
// @fnv 0x0043b3b0
// src: COMMUNITY 0x0043b3b0
unsigned short FUN_0043b3b0_class::NiMultiTargetTransformController_HasTarget(unsigned int value)
{
    unsigned short i = 0;
    for (; i < *(unsigned short*)((char*)this + 0x3c); ++i)
    {
        if (*(unsigned int*)(*(unsigned int*)((char*)this + 0x38) + i * 4) == value)
            return i;
    }
    return NiInterpController::INVALID_INDEX;
}

struct G2
{
    void AddHead(int* pValue);
};

struct LH
{
    bool IsInList(int& value);
};

struct FUN_00420440_Class
{
    void ExtraDataList_SetRoomLinkedRefData(void* pObject);
};

struct FUN_00416b80
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;

    FUN_00416b80();
};

struct FUN_00420c10_Class : public FUN_004207e0Class
{
    void ExtraDataList_AddRoomLinkedRoomRef(int value);
};

void* __cdecl operator new(unsigned int size);

// Ensures the object exists when value is nonzero, then adds value to the list at offset 8 if it is not already present.
// @fnv 0x00420c10
// src: COMMUNITY 0x00420c10
void FUN_00420c10_Class::ExtraDataList_AddRoomLinkedRoomRef(int value)
{
    if (!this->ExtraDataList_GetRoomLinkedRefData() && value)
    {
        ((FUN_00420440_Class*)this)->ExtraDataList_SetRoomLinkedRefData(new FUN_00416b80());
    }

    void* m_pLinkedReference = this->ExtraDataList_GetRoomLinkedRefData();
    if (!((LH*)((char*)m_pLinkedReference + 8))->IsInList(value))
    {
        ((G2*)((char*)m_pLinkedReference + 8))->AddHead(&value);
    }
}

struct FUN_0042cca0 : public BSExtraData
{
    virtual ~FUN_0042cca0();
};
// @fnv 0x0042cca0
FUN_0042cca0::~FUN_0042cca0()
{}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct FUN_0042dff0_shell
{
    int MenuTopic_GetResponseListEmpty();
};
// @fnv 0x0042dff0
// src: XBOX_PDB 0x0042dff0
int FUN_0042dff0_shell::MenuTopic_GetResponseListEmpty()
{
    return ((BSSimpleListTESRaceSize*)((char*)this + 0xc))->GetSize() == 0 ? 1 : 0;
}

struct FUN_0042e130_shell : BaseExtraList
{
    void ExtraDataList_RemoveTalkingActor();
};

// @fnv 0x0042e130
// src: COMMUNITY 0x0042e130
void FUN_0042e130_shell::ExtraDataList_RemoveTalkingActor()
{
    BaseExtraList::RemoveExtra((unsigned char)0x55);
}

struct FUN_0042e6d0 : public BSExtraData
{
    virtual ~FUN_0042e6d0();
};
// @fnv 0x0042e6d0
FUN_0042e6d0::~FUN_0042e6d0()
{}

struct NavMeshArr
{
    ~NavMeshArr();
    void* __thiscall FUN_0042f510(unsigned int flags);
};

NavMeshArr::~NavMeshArr()
{}

// Runs the destructor and, when flags has bit 0 set, deallocates the object; returns this.
// @fnv 0x0042f510
void* NavMeshArr::FUN_0042f510(unsigned int flags)
{
    this->NavMeshArr::~NavMeshArr();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x0042f5f0
template <>
void BSSimpleArray<CombatTargetTimestamp, 1024>::SetSize(unsigned int count, bool clear)
{
    if (count == 0)
    {
        Clear(clear);
    }
    else if (count > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(count);
            SimpleArrayStorage = count;
        }
        else
        {
            ReallocateStorage(count, iSize);
            SimpleArrayStorage = count;
        }

        InitializeItems(pBuffer + iSize, count - iSize);
        iSize = count;
    }
    else if (count < iSize)
    {
        ReleaseElements(pBuffer + count, iSize - count);
        iSize = count;

        if (clear && count <= SimpleArrayStorage / 4)
        {
            ReallocateStorage(count, count);
            SimpleArrayStorage = count;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, count - iSize);
        iSize = count;
    }
}

struct AC_0042f730
{
    void* vtbl;
    void __fastcall ActorCause_DecRefCount();
    void __fastcall ReleaseReferencedObject();
};

// @fnv 0x0042f760
// src: GUESS 0x0042f760 (confidence: medium)
void __fastcall AC_0042f730::ReleaseReferencedObject()
{
    if (vtbl)
        ((AC_0042f730*)vtbl)->ActorCause_DecRefCount();
}

// @fnv 0x0042ff30
// src: GUESS 0x0042ff30 (confidence: low)
void FUN_0042ff10_cls::Helper_0042ff30(int aiValue)
{
    ((NiPointer<NiAVObject>*)this)->operator==(*reinterpret_cast<const NiPointer<NiAVObject>*>(aiValue));
}

struct FUN_00435f80 : public BSExtraData
{
    virtual ~FUN_00435f80();
};
// @fnv 0x00435f80
FUN_00435f80::~FUN_00435f80()
{}

struct FUN_004362a0
{
    ~FUN_004362a0();
    void* __thiscall FUN_00436270(unsigned int flags);
};

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00436270
void* FUN_004362a0::FUN_00436270(unsigned int flags)
{
    FUN_004362a0::~FUN_004362a0();

    if (flags & 1)
        _Deallocate(this);

    return this;
}

struct FUN_00436bb0 : public BSExtraData
{
    virtual ~FUN_00436bb0();
};
// @fnv 0x00436bb0
FUN_00436bb0::~FUN_00436bb0()
{}

// @fnv 0x004385f0
template <>
BSSimpleArray<CombatTargetTimestamp, 1024>::~BSSimpleArray()
{
    Clear(true);
}

struct FUN_0043a080_Node
{
    FUN_0043a080_Node* next;
    int field2;
    int field3;
};

extern int DAT_01188f7c;
extern void* DAT_011c5f54;
extern void* DAT_011c5f58;

// @fnv 0x0043a080
// src: XBOX_PDB 0x0043a080
void NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem()
{
    DAT_011c5f58 = new FUN_0043a080_Node[DAT_01188f7c];

    FUN_0043a080_Node* index = (FUN_0043a080_Node*)DAT_011c5f58 + DAT_01188f7c - 1;
    index->next = 0;

    unsigned int uiIndex = 1;
    do
    {
        index = (FUN_0043a080_Node*)DAT_011c5f58 + uiIndex;
        index->next = index + 1;
    } while (uiIndex++ < DAT_01188f7c - 2);

    if (DAT_011c5f54 != 0)
    {
        ((FUN_0043a080_Node*)DAT_011c5f58)->next = (FUN_0043a080_Node*)DAT_011c5f54;
        DAT_011c5f54 = DAT_011c5f58;
    }
    else
    {
        DAT_011c5f54 = DAT_011c5f58;
        ((FUN_0043a080_Node*)DAT_011c5f54)->next = 0;
    }

    DAT_011c5f58 = (char*)DAT_011c5f58 + 12;
}

struct Date
{
    ~Date();
};
struct FUN_0043b5f0_cls : TESObjectTREE
{
    void hkpWorldObject_unmarkForRead();
};
// @fnv 0x0043b5f0
// src: COMMUNITY 0x0043b5f0
void FUN_0043b5f0_cls::hkpWorldObject_unmarkForRead()
{
    ((Date*)GetData())->Date::~Date();
}

struct ExtraListShell
{
    void BaseExtraList_RemoveExtra_00410140(unsigned char type);
    void ExtraDataList_ClearRumorsExtra();
};
// @fnv 0x004216b0
// src: XBOX_PDB 0x004216b0
void ExtraListShell::ExtraDataList_ClearRumorsExtra()
{
    BaseExtraList_RemoveExtra_00410140(0x4E);
}

extern "C" void* DAT_0101598c;

struct FUN_0042f780
{
    int unk00;
    int unk04;
    int unk08;

    void Init(int value);
    ~FUN_0042f780();
};

struct FUN_0042cb30 : public BSExtraData
{
    FUN_0042f780 unk0c;

    virtual ~FUN_0042cb30();
};

// Destructor for FUN_0042cb30 that resets its unk0c member by calling Init(0).
// @fnv 0x0042cb30
FUN_0042cb30::~FUN_0042cb30()
{
    unk0c.Init(0);
}

// The two strings call BSStringT<char>::BSStringT at 0x004037b0.
class FUN_0042ccc0 : public BSExtraData
{
  public:
    FUN_0042ccc0();
    virtual ~FUN_0042ccc0();

    BSStringT<char> m_kFirst;
    BSStringT<char> m_kSecond;
};

// Constructs a BSExtraData-derived extra-data object of type 0x8f holding two BSStringT<char> members.
// @fnv 0x0042ccc0
FUN_0042ccc0::FUN_0042ccc0() : BSExtraData(0x8f)
{}

struct FUN_00436b20
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00436b20(unsigned int a, unsigned int b);
};
struct FUN_0042e060_class
{
    void* __thiscall BaseExtraList_GetExtraData(unsigned char type);
    void __thiscall BaseExtraList_RemoveExtra(void* extra, bool remove);
    void __thiscall BaseExtraList_AddExtra(void* extra);
    void __thiscall ExtraDataList_SetTalkingActorExtra(unsigned int a, unsigned int b);
};
// Removes the existing 0x55-type entry, allocates a new FUN_00436b20 from a and b, and installs it via FUN_0040ff60.
// @fnv 0x0042e060
// src: XBOX_PDB 0x0042e060
void FUN_0042e060_class::ExtraDataList_SetTalkingActorExtra(unsigned int a, unsigned int b)
{
    void* pEntry = BaseExtraList_GetExtraData(0x55);
    if (pEntry)
        BaseExtraList_RemoveExtra(pEntry, true);
    pEntry = new FUN_00436b20(a, b);
    BaseExtraList_AddExtra(pEntry);
}

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct B42FA60Entry
{
    int unk00;

    B42FA60Entry();
};

class B42FA60Allocator
{
  public:
    void BSSimpleArray_NavMeshPtr_1024_ConstructItems(B42FA60Entry* pkArray, unsigned int ItemUpdateArray);
};

// Constructs each B42FA60Entry in the array in place using placement new.
// @fnv 0x0042fa60
// src: XBOX_PDB 0x0042fa60
void B42FA60Allocator::BSSimpleArray_NavMeshPtr_1024_ConstructItems(B42FA60Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) B42FA60Entry;
}

// @fnv 0x0042fe80
template <>
NiTMap<TESObjectREFR*, bool>::~NiTMap()
{
    RemoveAll();
}

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
// Default-constructs count timestamps in place at data.
// @fnv 0x00430000
template <>
void BSSimpleArray<CombatTargetTimestamp, 1024>::InitializeItems(CombatTargetTimestamp* data, unsigned int count)
{
    for (unsigned int index = 0; index < count; ++index)
    {
        new (&data[index]) DefaultTimestamp;
    }
}

struct SpawnedSub
{
    ~SpawnedSub();
};

struct FUN_00435ce0_cls : public BSExtraData
{
    SpawnedSub m_0c;
    ~FUN_00435ce0_cls();
};

// Destructor for FUN_00435ce0_cls that destroys its SpawnedSub member and base BSExtraData.
// @fnv 0x00435ce0
FUN_00435ce0_cls::~FUN_00435ce0_cls()
{}

struct FloatSlot
{
    unsigned int m_bits;
    float FUN_00435e00();
};

struct FloatHolder
{
    float m_f;
    void FUN_00435de0(float v);
};

struct FloatList
{
    int unk00;
    int FUN_0044ddc0();
    unsigned int* BSSimpleArray_NiAVObject_1024_GetAt(int idx);
    void BSSimpleArray_CombatTimeStamp_1024_Add(FloatHolder* p);
};

struct FloatGlobal
{
    int unk00;
    float* Setting_Float_00403e20();
};

extern FloatGlobal DAT_011cd78c;
float CombatTimer_GetTimer();

class FUN_00435d40_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FloatList m_0c;

    void Reset();
    void ExtraFriendHits_AddHit();
};

// @fnv 0x00435d40
// src: COMMUNITY 0x00435d40
void FUN_00435d40_cls::ExtraFriendHits_AddHit()
{
    Reset();
    int n = m_0c.FUN_0044ddc0();
    if (n > 0)
    {
        FloatSlot v;
        v.m_bits = *m_0c.BSSimpleArray_NiAVObject_1024_GetAt(n - 1);
        if (v.FUN_00435e00() < *DAT_011cd78c.Setting_Float_00403e20())
            return;
    }
    FloatHolder h;
    h.FUN_00435de0(CombatTimer_GetTimer());
    m_0c.BSSimpleArray_CombatTimeStamp_1024_Add(&h);
}

struct FUN_00435e40_key
{
    unsigned int m_v;
    double Eval();
};
struct FUN_00435e40_arr
{
    unsigned int Count();
    unsigned int* GetAt(unsigned int i);
    void RemoveAt(unsigned int i, unsigned int n);
};
struct FUN_00435e40_flt
{
    float* Get();
};
extern "C" char DAT_011cd580;
struct FUN_00435e40_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00435e40_arr m_0c;
    void ExtraFriendHits_RemoveOldHits();
};
// Iterates m_0c, evaluates each entry's key and removes entries whose Eval() exceeds the float at DAT_011cd580.
// @fnv 0x00435e40
// src: XBOX_PDB 0x00435e40
void FUN_00435e40_cls::ExtraFriendHits_RemoveOldHits()
{
    for (unsigned int i = 0; i < m_0c.Count(); i++)
    {
        FUN_00435e40_key key;
        key.m_v = *m_0c.GetAt(i);
        if (key.Eval() > *((FUN_00435e40_flt*)&DAT_011cd580)->Get())
        {
            m_0c.RemoveAt(i, 1);
            i--;
        }
    }
}

struct Vec3Sub
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    Vec3Sub();
};
struct SlottedSource
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Vec3Sub* GetVariedData();
    Vec3Sub* GetFixedData();
};
struct FUN_00435fa0_cls : BSExtraData
{
    Vec3Sub m_kPointA;
    Vec3Sub m_kPointB;
    Vec3Sub m_iThirdValue;
    FUN_00435fa0_cls(SlottedSource* pSrc);
};

// @fnv 0x00435fa0
FUN_00435fa0_cls::FUN_00435fa0_cls(SlottedSource* apSource) : BSExtraData(0x4c)
{
    if (apSource != 0)
    {
        m_kPointA = *apSource->GetFixedData();
        m_kPointB = *apSource->GetVariedData();
        m_iThirdValue = m_kPointB;
    }
}

struct Arg12
{
    int unk00;
    int unk04;
    int unk08;
    ~Arg12();
    void Release();
};

struct EhGuard
{
    ~EhGuard()
    {}
};

struct ExtraValue004360c0
{
    ExtraValue004360c0();
    ~ExtraValue004360c0();
    void Assign(const Arg12& value);
};

struct FUN_004360c0_cls : public BSExtraData
{
    virtual void Update();
    ExtraValue004360c0 m_0c;

    FUN_004360c0_cls(Arg12 value);
};

// Initializes the base with flags 0x4f and assigns the given Arg12 value to m_0c.
// @fnv 0x004360c0
FUN_004360c0_cls::FUN_004360c0_cls(Arg12 value) : BSExtraData(0x4f), m_0c()
{
    m_0c.Assign(value);
}

struct Arg12_004361e0
{
    int unk00;
    int unk04;
    int unk08;

    ~Arg12_004361e0();
};

struct Member_004361e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    Member_004361e0();
    ~Member_004361e0();
    void Add(Arg12_004361e0* pArg);
};

struct FUN_004361e0 : BSExtraData
{
    Member_004361e0 m_0C;

    FUN_004361e0(Arg12_004361e0 aArg);
    virtual void v00();
};

// Initializes the base with 0x7d and adds the passed argument to the member at offset 0x0C.
// @fnv 0x004361e0
FUN_004361e0::FUN_004361e0(Arg12_004361e0 aArg) : BSExtraData(0x7d)
{
    m_0C.Add(&aArg);
}

struct ParamBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Release();
    ~ParamBlock();
};

class ChildMember
{
  public:
    ChildMember();
    ~ChildMember();
    void Attach(ParamBlock* p);
};

class FUN_00436660 : public BSExtraData
{
  public:
    FUN_00436660(ParamBlock p);
    virtual void v00();
    ChildMember m_pChildAtom;
};

// Constructs a BSExtraData of kind 0x87 and attaches the given ParamBlock to its ChildMember.
// @fnv 0x00436660
FUN_00436660::FUN_00436660(ParamBlock aParamBlock) : BSExtraData(0x87)
{
    m_pChildAtom.Attach(&aParamBlock);
}

struct CloneCell;
struct CloneSound;

struct CloneChildCell
{
    virtual CloneCell* GetPersistentCell();
};

struct CloneCell
{
    bool FUN_00425fd0();
};

struct CloneExtraList
{
    void ExtraDataList_SetPersistentCell(CloneCell* pCell);
};

struct CloneSource
{
    char pad00[0x18];
    CloneChildCell kChildCell;

    bool TESObjectREFR_GetRefPersists_005653d0();
    NiPoint3* FUN_00436aa0();
    const NiPoint3& FUN_00430830();
    CloneCell* FUN_008d6f30();
};

struct CloneProcess
{
    int FUN_0045cd60();
};

struct CloneRef
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void SetParentCell(CloneCell* pCell);

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

    CloneRef();
    void TESObjectREFR_SetObjectReference(void* pBase);
    void TESObjectREFR_SetRefPersists(bool b);
    void TESObjectREFR_SetLocationOnReference(const NiPoint3& kPos);
    struct AngleWords { unsigned int x, y, z; };
    void TESObjectREFR_SetAngleOnReference(AngleWords kAngle);
    void MobileObject_SetTalkingActivatorRef(CloneSource* pSource);
    void FUN_00898280(bool b);
    void MobileObject_UpdateTopicInfoSayOnce();
    CloneExtraList* BSFile_GetDevice();
    CloneProcess* FUN_008d8520();
    void FUN_00407800(CloneProcess* pProcess);
};

struct CloneLowProcess : CloneProcess
{
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
    CloneLowProcess();
};
struct CloneMiddleLowProcess : CloneLowProcess
{
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    CloneMiddleLowProcess();
};
struct CloneMiddleHighProcess : CloneMiddleLowProcess
{
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
    CloneMiddleHighProcess();
};
struct CloneHighProcess : CloneMiddleHighProcess
{
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
    CloneHighProcess();
};

struct CloneProcessLists
{
    void ProcessLists_AddReference(CloneRef* pRef, int iLevel, bool a, bool b, bool c);
};
extern CloneProcessLists DAT_011e0e80;
extern "C" CloneRef* g_thePlayer;

struct CloneFactory
{
    CloneRef* ExtraTalkingActor_CreateLocalMobileObjectCopy(void* pBase, CloneSource* pSource);
};

// Allocates a CloneRef from pSource, copies its data, sets its parent cell, and attaches a process matching the player's process level.
// @fnv 0x00436780
// src: XBOX_PDB 0x00436780
CloneRef* CloneFactory::ExtraTalkingActor_CreateLocalMobileObjectCopy(void* pBase, CloneSource* pSource)
{
    CloneRef* pRef = 0;
    if (pSource)
    {
        pRef = new CloneRef;
        pRef->TESObjectREFR_SetObjectReference(pBase);
        pRef->TESObjectREFR_SetRefPersists(pSource->TESObjectREFR_GetRefPersists_005653d0());
        pRef->TESObjectREFR_SetLocationOnReference(*pSource->FUN_00436aa0());
        pRef->TESObjectREFR_SetAngleOnReference(*(const CloneRef::AngleWords*)&pSource->FUN_00430830());
        pRef->MobileObject_SetTalkingActivatorRef(pSource);
        pRef->FUN_00898280(true);
        pRef->MobileObject_UpdateTopicInfoSayOnce();
        if (pSource->FUN_008d6f30() && pSource->FUN_008d6f30()->FUN_00425fd0())
        {
            pRef->SetParentCell(pSource->FUN_008d6f30());
        }
        else
        {
            CloneCell* pCell = pSource->kChildCell.GetPersistentCell();
            if (pCell)
                pRef->BSFile_GetDevice()->ExtraDataList_SetPersistentCell(pCell);
            else
                pRef->SetParentCell(pSource->FUN_008d6f30());
        }
        CloneProcess* pPlayerProcess = g_thePlayer->FUN_008d8520();
        if (pPlayerProcess)
        {
            CloneProcess* pProcess = 0;
            switch (pPlayerProcess->FUN_0045cd60())
            {
            case 3:
                pProcess = new CloneLowProcess;
                break;
            case 2:
                pProcess = new CloneMiddleLowProcess;
                break;
            case 1:
                pProcess = new CloneMiddleHighProcess;
                break;
            case 0:
                pProcess = new CloneHighProcess;
                break;
            }
            pRef->FUN_00407800(pProcess);
            DAT_011e0e80.ProcessLists_AddReference(pRef, pProcess->FUN_0045cd60(), false, false, false);
        }
    }
    return pRef;
}

struct GcItem
{
    unsigned int Remove(unsigned int flag);
};

struct GcNode
{
    GcNode* Next();
    GcItem** GetItem();
    ~GcNode();
};

struct GcBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    virtual ~GcBase();
};

class FUN_00437d10 : public GcBase
{
  public:
    GcNode m_pChildAtom;
    virtual ~FUN_00437d10();
};

// @fnv 0x00437d10
FUN_00437d10::~FUN_00437d10()
{
    for (GcNode* pos = &m_pChildAtom; pos != 0; pos = pos->Next())
    {
        GcItem* val = *pos->GetItem();
        GcItem* cur = val;
        cur ? cur->Remove(1) : 0;
        *pos->GetItem() = 0;
    }
}

class FUN_00438610_cls
{
  public:
    unsigned int m_unk00;
    unsigned int* m_pData;
    unsigned int GetCount();
    void Reserve(unsigned int* slot, int count);
    int BSSimpleArray_CombatTimeStamp_1024_Add(unsigned int* value);
};

// Appends the value to the end of the array, growing it by one, and returns the index where it was stored.
// @fnv 0x00438610
// src: COMMUNITY 0x00438610
int FUN_00438610_cls::BSSimpleArray_CombatTimeStamp_1024_Add(unsigned int* value)
{
    unsigned int index = GetCount();
    Reserve(m_pData + index, 1);
    m_pData[index] = *(volatile unsigned int*)value;
    return index;
}

// @fnv 0x00438720
template <>
NiTMap<WaterZone*, int>::~NiTMap()
{
    RemoveAll();
}

struct NiSpawnBase
{
    NiSpawnBase();
    ~NiSpawnBase()
    {}
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

NiSpawnBase::NiSpawnBase()
{}

class FUN_004391c0 : public NiSpawnBase
{
  public:
    FUN_004391c0();
    virtual void v00();
    void Init0(unsigned int a);
    void Init1(unsigned int a);
    void Init2(unsigned int a);
    void Init3(unsigned int a);
    void Init4(unsigned int a);
    void Init5(unsigned short a);
    void Init6(unsigned int a);
    unsigned short m_0018;
};

// @fnv 0x004391c0
FUN_004391c0::FUN_004391c0()
{
    m_0018 = 0;
    Init0(0);
    Init5(6);
    Init6(7);
    Init1(0);
    Init2(0);
    Init3(0);
}

// NiProperty's constructor: calls the primary base constructor, installs the
// class vtable pointer, then returns `this`.
struct NiPropertyBase
{
    NiPropertyBase();
    virtual void v00();
};

struct FUN_00439260 : public NiPropertyBase
{
    FUN_00439260();
};

// @fnv 0x00439260
FUN_00439260::FUN_00439260()
{}

namespace std {
double __cdecl abs(float);
}
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
// The shared BSMultiBound declares unsized delete as well as sized delete.
// MSVC selects unsized delete for constructor failure in FUN_00439490,
// changing its EH cleanup at 0x00eebbe0. Keep this definition until the
// shared allocation API supports the original sized-delete cleanup.
#include "../../include/NiMemObject.h"
// @fnv 0x00439490
// src: COMMUNITY 0x00439490
BSMultiBound* __cdecl MultiBoundMarkerData_CreateMultiBoundForRef(TESObjectREFR* reference)
{
    BSMultiBound* result = 0;
    if (reference)
    {
        BSMultiBoundShape* pBound = 0;
        if (std::abs(reference->GetAngleOnReference().x) < 0.01f &&
            std::abs(reference->GetAngleOnReference().y) < 0.01f &&
            std::abs(reference->GetAngleOnReference().z) < 0.01f)
        {
            pBound = new BSMultiBoundAABB;
            ((Bound*)pBound)->BSMultiBound_SetHalfExtents(reference->TESObjectREFR_GetMultiBoundHalfExtent());
        }
        else
        {
            pBound = new BSMultiBoundOBB;
            ((Bound*)pBound)->BSMultiBoundAABB_SetAxis(reference->TESObjectREFR_GetOrientation());
            ((Bound*)pBound)->BSMultiBound_SetHalfExtents(reference->TESObjectREFR_GetMultiBoundHalfExtent());
        }
        pBound->SetGridPosition(*static_cast<const TESObjectREFR*>(reference)->GetPos());
        result = new BSMultiBound;
        result->BSMultiBound_SetShape((Bound*)pBound);
    }
    return result;
}

// @fnv 0x0043b290
// src: COMMUNITY 0x0043b290
int __cdecl NiZBufferProperty_GetType()
{
    return (int)11u;
}

extern "C" long __stdcall InterlockedCompareExchange(long volatile* Destination, long Exchange, long Comparand);

typedef long(__stdcall* InterlockedCompareExchange_t)(long volatile*, long, long);

InterlockedCompareExchange_t DAT_00fdf1bc = InterlockedCompareExchange;

// @fnv 0x0043b460
// src: XBOX_PDB 0x0043b460
void __cdecl BSAtomicCompareExchange(void* apDestination, void* pSrc, unsigned int n)
{
    DAT_00fdf1bc(static_cast<long volatile*>(apDestination), n, reinterpret_cast<long>(pSrc));
}

struct ObjB4037
{
    void* __thiscall FUN_007b3fa0(bool a);
};

struct Sub4037
{
    ObjB4037** __thiscall FUN_006815c0();
    void __thiscall FUN_00726c60(int* a);
    void __thiscall FUN_0063f7b0();
};

struct Host00437df0
{
    char m_auiShapeKeys[0x20];
    Sub4037 m_sub;
    void ExtraFollowerSwimBreadcrumbs_RemoveFirstCrumb();
};

// Calls FUN_007b3fa0(true) on the object returned by m_sub.FUN_006815c0 if non-null, then FUN_00726c60(&d) and FUN_0063f7b0 on m_sub.
// @fnv 0x00437df0
// src: COMMUNITY 0x00437df0
void Host00437df0::ExtraFollowerSwimBreadcrumbs_RemoveFirstCrumb()
{
    ObjB4037* a = *m_sub.FUN_006815c0();
    ObjB4037* b5;
    int d;
    b5 = a;
    (void)(b5 != 0 ? (void*)b5->FUN_007b3fa0(true) : 0);
    d = 0;
    m_sub.FUN_00726c60(&d);
    m_sub.FUN_0063f7b0();
}

// @fnv 0x004388a0
FactionMembershipMap::~FactionMembershipMap()
{
    RemoveAll();
}

struct AnimPoint3
{
    float x, y, z;
};
struct AnimMatrix3
{
    float m[9];
};

struct AnimMemObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};

struct AnimSource
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
    virtual void* GetSourceData();
    const AnimPoint3& GetAngleOnReference() const;
    const AnimPoint3& TESObjectREFR_GetMultiBoundHalfExtent();
    AnimMatrix3 TESObjectREFR_GetOrientation();
};

struct AnimInterpolator : AnimMemObject
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
    virtual void SetSource(void* apData);
    void SetPosition(const AnimPoint3& kPos);
    void SetRotation(const AnimMatrix3& kRot);
};

struct AnimPointInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    AnimPointInterpolator();
};

struct AnimTransformInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44;
    AnimTransformInterpolator();
};

struct AnimBlendData : AnimMemObject
{
    int unk00, unk04, unk08, unk0C;
    AnimBlendData();
    void SetInterpolator(AnimInterpolator* apInterp);
};

struct AnimController : AnimMemObject
{
    int unk00;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    int unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
    int unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0;
    int unkE4, unkE8;
    AnimController();
    void SetData(AnimBlendData* apData);
};

// @fnv 0x004396e0
// src: COMMUNITY 0x004396e0
AnimController* __cdecl MultiBoundMarkerData_CreateRoomForRef(AnimSource* apSource)
{
    AnimController* pController = 0;
    if (apSource)
    {
        AnimBlendData* pData;
        AnimInterpolator* pInterp = 0;
        if (std::abs(apSource->GetAngleOnReference().x) < 0.01f &&
            std::abs(apSource->GetAngleOnReference().y) < 0.01f && std::abs(apSource->GetAngleOnReference().z) < 0.01f)
        {
            pInterp = new AnimPointInterpolator;
            pInterp->SetPosition(apSource->TESObjectREFR_GetMultiBoundHalfExtent());
        }
        else
        {
            pInterp = new AnimTransformInterpolator;
            pInterp->SetRotation(apSource->TESObjectREFR_GetOrientation());
            pInterp->SetPosition(apSource->TESObjectREFR_GetMultiBoundHalfExtent());
        }
        pInterp->SetSource(apSource->GetSourceData());
        pController = new AnimController;
        pData = new AnimBlendData;
        pData->SetInterpolator(pInterp);
        pController->SetData(pData);
    }
    return pController;
}

struct RefCountedObject
{
    void IncRefCount();
    void DecRefCount();
};

struct FUN_0043b750
{
    void* m_pBuffer;
    NiPointer<RefCountedObject> m_pHeadNode;
    NiPointer<RefCountedObject> m_iSecondInteger;
    int m_unk0c;
    int m_unk10;

    ~FUN_0043b750();
};

// Frees m_pBuffer and clears the two reference-counted pointers.
// @fnv 0x0043b750
FUN_0043b750::~FUN_0043b750()
{
    void* pBuffer = m_pBuffer;
    operator delete(pBuffer);
    m_pHeadNode = 0;
    m_iSecondInteger = 0;
}

class NameSource
{
  public:
    const char* FUN_0043b1b0();
};
class NamedObject
{
  public:
    NameSource* FUN_00413f40();
    void NiControllerSequence_SetName(const NiFixedString& kName);
};
class AttachedNode
{
};
class AttachTarget
{
  public:
    void BSAnimGroupSequence_SetAnimGroup(AttachedNode* pkNode);
};

class NamedObjectPtr
{
  public:
    NamedObject* m_pObject;
    NamedObject* Modelloader_GetReferencedThis() const;  // NiPointer<T>::operator T*
};
class AttachedNodePtr
{
  public:
    AttachedNode* m_pObject;
    AttachedNode* Modelloader_GetReferencedThis() const;                   // NiPointer<T>::operator T*
    AttachedNodePtr& FUN_0066b0d0(AttachedNode* pkNode);  // NiPointer<T>::operator=
};

extern int DAT_011c7d74;
const char* __cdecl FUN_0043b9d0(const char* pcString, int iChar);
char* __cdecl FUN_00401460(char* pcDest, const char* pcSrc, int iCount);
AttachedNode* __cdecl TESAnimGroup_LoadAnimGroup(NamedObject* pkObject, const char* pcName);
bool __cdecl NiObject_IsKindOf(const void* pvKey, NamedObject* pkObject);

class NamedObjectLoader
{
  public:
    int unk00;
    NamedObjectPtr m_pReferencedObject;  // +0x04
    AttachedNodePtr m_spNode;            // +0x08

    AttachTarget* SkyObject_GetNiNode();
    void KFModel_InitSequence(const char* pcName);
};

// @fnv 0x0043b7e0
// src: COMMUNITY 0x0043b7e0
void NamedObjectLoader::KFModel_InitSequence(const char* pcName)
{
    if (!m_pReferencedObject.Modelloader_GetReferencedThis())
        return;
    const char* pcPath = m_pReferencedObject.Modelloader_GetReferencedThis()->FUN_00413f40()->FUN_0043b1b0();
    if (pcPath)
    {
        const char* pcSep = FUN_0043b9d0(pcPath, '_');
        if (pcSep)
        {
            char acBuffer[260];
            FUN_00401460(acBuffer, pcPath, pcSep - pcPath);
            acBuffer[pcSep - pcPath] = 0;
            m_pReferencedObject.Modelloader_GetReferencedThis()->NiControllerSequence_SetName(NiFixedString((const char*)acBuffer));
        }
    }
    m_spNode.FUN_0066b0d0(TESAnimGroup_LoadAnimGroup(m_pReferencedObject.Modelloader_GetReferencedThis(), pcName));
    if (NiObject_IsKindOf(&DAT_011c7d74, m_pReferencedObject.Modelloader_GetReferencedThis()))
        SkyObject_GetNiNode()->BSAnimGroupSequence_SetAnimGroup(m_spNode.Modelloader_GetReferencedThis());
    m_pReferencedObject.Modelloader_GetReferencedThis()->NiControllerSequence_SetName(NiFixedString(pcName));
}

class MenuTopic;

class FUN_00437510 : public BSExtraData
{
  public:
    BSSimpleList<BSSimpleList<MenuTopic*>*>* m_pTopics;
    FUN_00437510(BSSimpleList<MenuTopic*>* topics);
    ~FUN_00437510();
};

// Constructs an extra of type 0x73 holding a new list and adds the given topics list to it.
// @fnv 0x00437510
FUN_00437510::FUN_00437510(BSSimpleList<MenuTopic*>* topics) : BSExtraData(0x73)
{
    m_pTopics = new BSSimpleList<BSSimpleList<MenuTopic*>*>;
    m_pTopics->AddHead(topics);
}

struct FUN_00438df0
{
    void* vtbl;
    int unk4;
    int unk8;
    void __thiscall UpdateState_00438df0(FUN_00438df0* src);
};

// @fnv 0x00438df0
// src: GUESS 0x00438df0 (confidence: low)
void __thiscall FUN_00438df0::UpdateState_00438df0(FUN_00438df0* apSource)
{
    ((void(__thiscall*)(void*, FUN_00438df0*))(*((void***)this))[2])(this, apSource);
    *(char*)((char*)this + 0xc) = *(char*)((char*)apSource + 0xc);
    *(unsigned short*)((unsigned char*)this + 0xe) = *(unsigned short*)((unsigned char*)apSource + 0xe);
    *(int*)((char*)this + 0x10) = *(int*)((char*)apSource + 0x10);
}

struct ListArg436
{
    void* m_pFirstNode;
    void* m_pTail;
    int m_uiItemCount;
    ~ListArg436();
};

struct ExtraList436
{
    ExtraList436();
    ~ExtraList436();
    void Copy(const void* pkSource);
    int m_data;
};

class FUN_00436300 : public BSExtraData
{
  public:
    FUN_00436300(ListArg436 kList);
    virtual ~FUN_00436300();
    ExtraList436 m_kList;
};

// Constructs an BSExtraData with type 0x8a and copies the supplied ListArg436 into m_kList.
// @fnv 0x00436300
FUN_00436300::FUN_00436300(ListArg436 kList) : BSExtraData(0x8a)
{
    m_kList.Copy(&kList);
}

struct Value436540
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Value436540();
    ~Value436540();
    Value436540& operator=(const Value436540& other);
};

struct FUN_00436540 : BSExtraData
{
    Value436540 m_uiFilterValue;
    FUN_00436540(Value436540 value);
};

// @fnv 0x00436540
FUN_00436540::FUN_00436540(Value436540 value) : BSExtraData(0x86)
{
    m_uiFilterValue = value;
}

struct Val42CE30
{
    void* p;
    Val42CE30();
};

struct C42CE30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    Val42CE30 m_kValue;

    Val42CE30 BGSLoadFormBuffer_GetOldChangeFlags();
};

// @fnv 0x0042ce30
// src: COMMUNITY 0x0042ce30
Val42CE30 C42CE30::BGSLoadFormBuffer_GetOldChangeFlags()
{
    return m_kValue;
}

namespace FNV {
struct FUN_00436b20 : BSExtraData
{
    CloneRef* unk0c;
    FUN_00436b20(unsigned int first, unsigned int second);
};
// Sets the vtable pointer, stores the result of FUN_00436780(first, second) in unk0c, then calls FUN_00575830 on it with second's v125() point.
// @fnv 0x00436b20
FUN_00436b20::FUN_00436b20(unsigned int first, unsigned int second) : BSExtraData(0x55)
{
    unk0c = ((CloneFactory*)this)->ExtraTalkingActor_CreateLocalMobileObjectCopy((void*)first, (CloneSource*)second);
    unk0c->TESObjectREFR_SetLocationOnReference(*((const TESObjectREFR*)second)->GetPos());
}
}

struct FUN_00438690
{
    ~FUN_00438690();
};
struct FUN_004389d0 : FUN_00438690
{
    virtual ~FUN_004389d0();
};
// Empty destructor for FUN_004389d0, inheriting from FUN_00438690.
// @fnv 0x004389d0
FUN_004389d0::~FUN_004389d0()
{}

namespace fnv_00436420 {
struct Arg
{
    int a;
    ~Arg();
};
struct Member
{
    int x, y, z;
    Member();
    ~Member();
    void Assign(const Arg& a);
};
struct FUN_00436420 : BSExtraData
{
    Member m;
    FUN_00436420(Arg a, int b, int c);
    virtual void v0();
};
// Constructs the object by calling the Base constructor with 0x83 and assigning the Arg parameter to the Member field m.
// @fnv 0x00436420
FUN_00436420::FUN_00436420(Arg a, int aiUnused1, int aiUnused2) : BSExtraData(0x83)
{
    m.Assign(a);
}
}  // namespace fnv_00436420
