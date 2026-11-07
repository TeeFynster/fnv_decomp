#include "../../include/BSStringT.h"

// src/staging/blk_005e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

// Isolate overlapping legacy support declarations from the checked headers.
#include "../../include/NiPointer.h"
#include "../../include/layout_support.h"
#include "../../include/BSSimpleList.h"
#include "../../include/NiTMallocInterface.h"
#define __local_vftable_ctor_closure SharedVtableConstructorClosure
#include "../../include/BSSimpleArray.h"
#include "../../include/Actor.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/NavMeshPtr.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/Script.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESForm.h"
#include "../../include/TESSound.h"

#include "../../include/hkMemoryAllocator.h"
// AudioMgr_BSAudio: this unit's view of BSAudio (0x00453a70 BSAudio::QInstance; 0x00ad73b0 GetSoundHandleByFormID,
// 0x00ad7480 GetSoundHandleByFilename, 0x00ad7550 GetSoundHandleByEditorName, 0x00ad8570 per the community PDB). It
// returns this unit's own sound-handle copy, so it stays local until that copy moves onto BSSoundHandle.
class AudioPlaybackHandle;
class Snd;
class SndForm;
class SndSrc;
class AudioMgr_BSAudio
{
public:
    static AudioMgr_BSAudio* Get();
    AudioPlaybackHandle Make(int id, SndForm* form);
    AudioPlaybackHandle Make2(int id);
    bool PlayAt(void* node, float f, int flags);
    AudioPlaybackHandle GetHandle(const char* name, int flags, int a);
    AudioPlaybackHandle GetSoundByEditorID(const char* editorID, int flags, int a);
    AudioPlaybackHandle GetSoundByEditorID(const char* editorID, int flags);
    Snd Make(void* a, SndSrc* b);
};
#include "../../include/GO.h"
#include "../../include/NiBound.h"
#include "../../include/NiPoint3.h"
#include "../../include/TESModel.h"
#include "../../include/TESSoundFile.h"
#include "../../include/TESSound__SOUND_DATA.h"
#include "../../include/BGSBodyPartData.h"
#include "../../include/TESSaveLoadGame.h"
#undef __local_vftable_ctor_closure

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct FUN_00851d70_shell
{
    void SetFlagByte();
};
extern GlobalObject_0045cf30 g_011de29c;
extern void* DAT_011de134;
// If the global bool is set, calls SetFlagByte on the object at DAT_011de134, then returns true.
// @fnv 0x005e0160
// src: EXE 0x005e0160
bool Cmd_SystemSave_Execute()
{
    if (*g_011de29c.Bool())
        reinterpret_cast<FUN_00851d70_shell*>(DAT_011de134)->SetFlagByte();
    return true;
}

extern "C" void __cdecl j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(int);
extern int DAT_0103d3e8;

struct FUN_005e02e0
{
    int m0;
    int m4;
    void Init();
};

// Stores the address of DAT_0103d3e8 into m0 and calls FUN_004b0220 with m4.
// @fnv 0x005e02e0
void FUN_005e02e0::Init()
{
    m0 = (int)&DAT_0103d3e8;
    j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(m4);
}

extern "C" void* DAT_0103d3f0;
struct FUN_005e0310_class
{
    void* vtbl;
    void __thiscall NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture_NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture(void* a, void* b);
    FUN_005e0310_class* __thiscall NiTObjectArray_NiPointer_NiTexture_NiTObjectArray(void* a, void* b);
};

// Calls FUN_005e08e0 with the two arguments, sets vtbl to DAT_0103d3f0, and returns this.
// @fnv 0x005e0310
// src: EXE 0x005e0310
FUN_005e0310_class* __thiscall FUN_005e0310_class::NiTObjectArray_NiPointer_NiTexture_NiTObjectArray(void* apArg, void* apArg2)
{
    NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture_NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture(apArg, apArg2);
    vtbl = &DAT_0103d3f0;
    return this;
}

struct ActorCombatGroup;

struct FUN_005e0340Class
{
    int m_vtbl;
    ActorCombatGroup** m_ptr;
    void ReleaseStorage_005e0340();
};

extern int DAT_0103d3f8;

// Sets the vtable pointer to DAT_0103d3f8 and deallocates m_ptr through NiTMallocInterface<ActorCombatGroup*>::Deallocate.
// @fnv 0x005e0340
// src: GUESS 0x005e0340 (confidence: medium)
void FUN_005e0340Class::ReleaseStorage_005e0340()
{
    m_vtbl = (int)&DAT_0103d3f8;
    NiTMallocInterface<ActorCombatGroup*>::Deallocate(m_ptr);
}

extern int DAT_0103d400;
struct FUN_005e0370_Class
{
    void* vtbl;
    void FUN_005e0950(int a, int b);
    void* NiTPrimitiveArray_TESModel_NiTPrimitiveArray(int a, int b);
};
// Calls FUN_005e0950 with the two arguments, sets vtbl to &DAT_0103d400, and returns this.
// @fnv 0x005e0370
// src: EXE 0x005e0370
void* FUN_005e0370_Class::NiTPrimitiveArray_TESModel_NiTPrimitiveArray(int aiArg1, int aiArg2)
{
    FUN_005e0950(aiArg1, aiArg2);
    vtbl = &DAT_0103d400;
    return this;
}

// @fnv 0x005e05b0
// src: GUESS 0x005e05b0 (confidence: medium)
void* NavMeshPtr::GetTextElementPointer512(int index)
{
    return (char*)AnimatingText_GetFullText() + (index << 9);
}

struct QuantityData
{
    void SetQuantity(unsigned int);
    void hkStackMemory_deallocateStack(unsigned int quantity);
};

// @fnv 0x005e0b80
// src: XBOX_PDB 0x005e0b80
void QuantityData::hkStackMemory_deallocateStack(unsigned int quantity)
{
    SetQuantity(quantity);
}

// Script.h has no profiling-time mutator; keep the operation here using its layout.
struct ScriptRuntimeOperations
{
    void AddProfileTime(float value);
};

// @fnv 0x005e1140
void ScriptRuntimeOperations::AddProfileTime(float value)
{
    reinterpret_cast<Script*>(this)->m_fValueAtOffset34 += value;
}

struct FUN_005e2850_class
{
    bool ScriptRunner_IsRunning();
};

// @fnv 0x005e2850
// src: XBOX_PDB 0x005e2850
bool FUN_005e2850_class::ScriptRunner_IsRunning()
{
    return *(int*)((char*)this + 0x14) != 0;
}

struct Stub
{
    void FUN_005e9590();
    void ForwardCall_005e9860();
};

// @fnv 0x005e9860
// src: GUESS 0x005e9860 (confidence: low)
void Stub::ForwardCall_005e9860()
{
    FUN_005e9590();
}

struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
    bool HasFlag20();
};

// @fnv 0x005ec6e0
bool TESFaction_RankDataView::HasFlag20()
{
    return (*reinterpret_cast<unsigned char*>(GetRankDataList()) & 0x20) != 0;
}

struct FUN_005ec8f0_class
{
    bool __thiscall ComputeValue_005ec760(int a);
    bool __thiscall ForwardCall_005ec8f0(int a);
};

// Returns the logical negation of FUN_005ec760(a).
// @fnv 0x005ec8f0
// src: GUESS 0x005ec8f0 (confidence: low)
bool __thiscall FUN_005ec8f0_class::ForwardCall_005ec8f0(int a)
{
    return !ComputeValue_005ec760(a);
}

struct FUN_005ecd10_cls
{
    unsigned char IsEqual(int);
    bool IsUnequal(int a);
};

// Returns true when IsEqual returns zero for the given index.
// @fnv 0x005ece20
// src: GUESS 0x005ece20 (confidence: medium)
bool FUN_005ecd10_cls::IsUnequal(int a)
{
    return !IsEqual(a);
}

struct FUN_005ed1b0_Class
{
    bool Equals(int);
    bool IsNotEqual(int arg);
};

// Returns the logical negation of Equals(arg).
// @fnv 0x005ed1b0
// src: GUESS 0x005ed1b0 (confidence: high)
bool FUN_005ed1b0_Class::IsNotEqual(int arg)
{
    return !Equals(arg);
}

extern int DAT_010472e4;

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void ResetToGlobal();
};

// @fnv 0x005eee60
void GlobalObject_00869f00::ResetToGlobal()
{
    p = &DAT_010472e4;
    Clear(true);
}

class FootIK_DATA__FootIK_Leg_DATA;

// @fnv 0x005eefc0
template <>
BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// @fnv 0x005eeff0
template <>
BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::~BSSimpleArray()
{
    Clear(true);
}

void* __cdecl operator new(unsigned int);

// @fnv 0x005ef150
template <>
FootIK_DATA__FootIK_Leg_DATA* BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::_Allocate(unsigned int a)
{
    void* p = operator new(a * 0x38);
    return static_cast<FootIK_DATA__FootIK_Leg_DATA*>(p);
}

extern "C" void* __cdecl _Reallocate(void* p, size_t size);

// @fnv 0x005ef180
template <>
FootIK_DATA__FootIK_Leg_DATA* BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::_Reallocate(
    FootIK_DATA__FootIK_Leg_DATA* n, unsigned int iCount)
{
    return static_cast<FootIK_DATA__FootIK_Leg_DATA*>(::_Reallocate(n, iCount * 0x38));
}

extern int DAT_0104730c;
void BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_InitialSetup(int, int);

struct FUN_005ef1a0_Class
{
    void BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_InitialSetup(int, int);
    FUN_005ef1a0_Class* BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024();
};

// @fnv 0x005ef1a0
// src: COMMUNITY 0x005ef1a0
FUN_005ef1a0_Class* FUN_005ef1a0_Class::BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0104730c);
    BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_InitialSetup(0, 0);
    return this;
}

namespace fnv_005ef1d0 {
extern int DAT_0104730c;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_005ef1d0
{
    void Init();
};
// @fnv 0x005ef1d0
void FUN_005ef1d0::Init()
{
    *(int*)this = (int)&DAT_0104730c;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_005ef1d0

struct FUN_005ef330_Class
{
    void* __thiscall BSSimpleArray_PathingLocation_1024_Allocate(int param_2);
};

// Allocates param_2 blocks of 0x28 bytes via operator new and returns the pointer.
// @fnv 0x005ef330
// src: COMMUNITY 0x005ef330
void* __thiscall FUN_005ef330_Class::BSSimpleArray_PathingLocation_1024_Allocate(int aiCount)
{
    void* result = operator new(aiCount * 0x28);
    return result;
}

void* __cdecl Reallocate(void* p, unsigned int n);

struct FUN_005ef360_class
{
    void* __thiscall BSSimpleArray_PathingLocation_1024_Reallocate(unsigned int n, unsigned int m);
};

// @fnv 0x005ef360
// src: COMMUNITY 0x005ef360
void* __thiscall FUN_005ef360_class::BSSimpleArray_PathingLocation_1024_Reallocate(unsigned int n, unsigned int m)
{
    return Reallocate((void*)n, m * 0x28);
}

// RTTI at 0x01047320 identifies BSSimpleArray<GrabIK_DATA::GrabIK_Arm_DATA, 1024>.
class GrabIK_DATA__GrabIK_Arm_DATA;

// @fnv 0x005ef380
template <>
BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::BSSimpleArray()
{
    _InitialSetup(0, 0);
}

// Allocates n * 6 bytes with operator new and returns the pointer.
// @fnv 0x005ef510
template <>
GrabIK_DATA__GrabIK_Arm_DATA* BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::_Allocate(unsigned int n)
{
    void* p = operator new(n * 6);
    return static_cast<GrabIK_DATA__GrabIK_Arm_DATA*>(p);
}

extern "C" void* __cdecl _Reallocate(void* p, size_t n);

// @fnv 0x005ef540
template <>
GrabIK_DATA__GrabIK_Arm_DATA* BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::_Reallocate(
    GrabIK_DATA__GrabIK_Arm_DATA* a, unsigned int b)
{
    return static_cast<GrabIK_DATA__GrabIK_Arm_DATA*>(::_Reallocate(a, b * 6));
}

// @fnv 0x005f1210
unsigned char TESAttributes::GetPerception()
{
    return GetAttributeValue(6);
}

// @fnv 0x005f1250
unsigned char TESAttributes::GetCharisma()
{
    return GetAttributeValue(8);
}

// @fnv 0x005f1270
unsigned char TESAttributes::GetIntelligence()
{
    return GetAttributeValue(9);
}

// @fnv 0x005f12b0
unsigned char TESAttributes::GetLuck()
{
    return GetAttributeValue(0xb);
}

void TESAttributes::SetAttributeValue(unsigned int index, unsigned char value, bool flag)
{}

// @fnv 0x005f14b0
void TESAttributes::SetStrength(unsigned char value)
{
    SetAttributeValue(5U, value, true);
}

void TESAttributes::SetAttributeValue(unsigned char index, unsigned char value, bool force)
{}

// @fnv 0x005f14d0
void TESAttributes::SetPerception(unsigned char index)
{
    SetAttributeValue((unsigned char)6, index, true);
}

// @fnv 0x005f14f0
void TESAttributes::SetEndurance(unsigned char abValue)
{
    SetAttributeValue(static_cast<ActorValue::Index>(7), static_cast<unsigned char>(abValue), true);
}

// @fnv 0x005f1510
void TESAttributes::SetCharisma(unsigned char flag)
{
    SetAttributeValue(8U, flag, true);
}

// @fnv 0x005f1530
void TESAttributes::SetIntelligence(unsigned char value)
{
    SetAttributeValue(9U, value, true);
}

// @fnv 0x005f1550
void __thiscall TESAttributes::SetAttribute(unsigned char index)
{
    SetAttributeValue((unsigned char)10, index, true);
}

// @fnv 0x005f1570
void TESAttributes::SetLuck(unsigned char index)
{
    SetAttributeValue((unsigned char)0xb, index, true);
}

struct FUN_005f3710_Class
{
    int __thiscall GetEntryAt(int index);
};

// @fnv 0x005f3710
int __thiscall FUN_005f3710_Class::GetEntryAt(int index)
{
    if ((unsigned int)index < *(unsigned int*)((char*)this + 0x34))
    {
        return index * 16 + *(int*)((char*)this + 0x38);
    }
    return 0;
}

struct FUN_005f4b70_Class
{
    void TESAnimGroup_SetBlend(unsigned char aucLevel);
};

// @fnv 0x005f4b70
// src: COMMUNITY 0x005f4b70
void FUN_005f4b70_Class::TESAnimGroup_SetBlend(unsigned char aucLevel)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x29) = aucLevel;
}

struct FUN_005f4b90_Class
{
    void SetByteAtOffset2B(unsigned char v);
};
// @fnv 0x005f4b90
void FUN_005f4b90_Class::SetByteAtOffset2B(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x2b) = aucValue;
}

struct FUN_005f5f60_class
{
    int TESChallenge_GetRecurring();
};

// @fnv 0x005f5f60
// src: XBOX_PDB 0x005f5f60
int FUN_005f5f60_class::TESChallenge_GetRecurring()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x5c) & 2;
}

struct FUN_005f5fa0_cls
{
    unsigned int GetShortAtOffset64();
};

// @fnv 0x005f5fa0
unsigned int FUN_005f5fa0_cls::GetShortAtOffset64()
{
    return *(unsigned short*)((char*)this + 0x64);
}

struct FUN_005f5fc0_class
{
    unsigned int GetShortAtOffset66();
};

// @fnv 0x005f5fc0
unsigned int FUN_005f5fc0_class::GetShortAtOffset66()
{
    return *(unsigned short*)((char*)this + 0x66);
}

struct FUN_005f5fe0_class
{
    unsigned int __thiscall GetShortAtOffset68();
};

// @fnv 0x005f5fe0
unsigned int __thiscall FUN_005f5fe0_class::GetShortAtOffset68()
{
    return *(unsigned short*)((char*)this + 0x68);
}

struct FUN_005f60c0_Class
{
    int HasFlag8();
};

// @fnv 0x005f60c0
int FUN_005f60c0_Class::HasFlag8()
{
    return ((int*)this)[0x1c] & 8;
}

// Adds amount to the int at offset 0x6c of this object and calls MarkForSave.
// @fnv 0x005f60e0
// src: COMMUNITY 0x005f60e0
void TESChallenge::IncrementProgress_005f60e0(int amount)
{
    *(int*)((char*)this + 0x6c) += amount;
    MarkForSave();
}

// @fnv 0x005f9010
// src: COMMUNITY 0x005f9010
void TESActorBaseData::TESCreature_SetNoBloodSpray(bool set)
{
    UpdateFlagBit(0x800, set, true);
}

void __cdecl ReleaseMemberStorage();

struct FUN_005ffbd0_cls
{
    void __thiscall ForwardCall_005ffbd0();
    void __thiscall ReleaseMemberStorage();
};

// @fnv 0x005ffbd0
// src: GUESS 0x005ffbd0 (confidence: low)
void __thiscall FUN_005ffbd0_cls::ForwardCall_005ffbd0()
{
    this->ReleaseMemberStorage();
}

struct FUN_005e0830
{
    void __thiscall SettingCollection_SetIniPath(const char*);
    void __thiscall Open(const char* apFileName, bool abWrite);
};
// Calls FUN_004f8ac0 with apFileName, then invokes the object's vtable slot 6 with abWrite.
// @fnv 0x005e0830
void __thiscall FUN_005e0830::Open(const char* apFileName, bool abWrite)
{
    SettingCollection_SetIniPath(apFileName);
    ((void(__thiscall*)(void*, bool))(*reinterpret_cast<void***>(this))[6])(this, abWrite);
}

struct FUN_005efc60_class
{
    void* __thiscall InitToMinusOne();
};

// Sets the three shorts at offsets 0, 2 and 4 of this object to -1 and returns this.
// @fnv 0x005efc60
void* __thiscall FUN_005efc60_class::InitToMinusOne()
{
    *(short*)this = -1;
    *(short*)(this + 2) = -1;
    *(short*)(this + 4) = -1;
    return this;
}

struct FUN_005f4bd0_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    void SetEntryByte(unsigned int index, unsigned char value);
};
// If index is below the count in mc, writes value to byte 13 of the 16-byte entry at m14 + index*16.
// @fnv 0x005f4bd0
void FUN_005f4bd0_class::SetEntryByte(unsigned int index, unsigned char value)
{
    if (index < (unsigned int)mc)
        *(unsigned char*)((char*)m14 + index * 16 + 13) = value;
}

extern int DAT_0103d408;
void __cdecl NiTMallocInterface_unsigned_int_Deallocate(void*);
struct Standin005e03a0
{
    void* vtbl;
    void* m4;
    void __thiscall SetVirtualTable_005e03a0();
};
// Sets the object's vtbl to DAT_0103d408 and passes m4 to FUN_004ede70.
// @fnv 0x005e03a0
// src: GUESS 0x005e03a0 (confidence: low)
void __thiscall Standin005e03a0::SetVirtualTable_005e03a0()
{
    vtbl = (void*)&DAT_0103d408;
    NiTMallocInterface_unsigned_int_Deallocate(m4);
}

int __cdecl Object_UpdateFields_005e0aa0(void* a, int b);
struct FUN_005e05d0 : NiBound
{
    FUN_005e05d0(void* a, int b);
};
// Constructs the object by calling FUN_005e0aa0 with a and 0, then passing the result to SetQuantity.
// @fnv 0x005e05d0
FUN_005e05d0::FUN_005e05d0(void* a, int b)
{
    ((QuantityData*)this)->SetQuantity((unsigned int)Object_UpdateFields_005e0aa0(a, 0));
}

void __cdecl _Deallocate(void*);
struct Holder005e0620
{
    void* __thiscall InitAndMaybeFree(unsigned int);
};
// Calls Init on this, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x005e0620
void* __thiscall Holder005e0620::InitAndMaybeFree(unsigned int flags)
{
    ((FUN_005e02e0*)this)->Init();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005dd810_Class
{
    void NiTObjectArray_NiPointer_NiTexture_Free();
    void* __thiscall NiTObjectArray_NiPointer_NiTexture_Destroy(unsigned int flags);
};
void __cdecl Deallocate(void* p);
// @fnv 0x005e0650
// src: COMMUNITY 0x005e0650
void* __thiscall FUN_005dd810_Class::NiTObjectArray_NiPointer_NiTexture_Destroy(unsigned int flags)
{
    NiTObjectArray_NiPointer_NiTexture_Free();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void* p);
struct FUN_005e0680_Class : FUN_005e0340Class
{
    void* __thiscall FUN_005e0680(unsigned int flags);
};
// Calls the base destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005e0680
void* __thiscall FUN_005e0680_Class::FUN_005e0680(unsigned int flags)
{
    ReleaseStorage_005e0340();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_005dd7b0_class
{
    void __thiscall ForwardCall_005dd7b0();
    void* __thiscall NiTPrimitiveArray_TESModel_Destroy(unsigned int flags);
};
// @fnv 0x005e06b0
// src: COMMUNITY 0x005e06b0
void* __thiscall FUN_005dd7b0_class::NiTPrimitiveArray_TESModel_Destroy(unsigned int flags)
{
    ForwardCall_005dd7b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_005e03a0_Class
{
    void __thiscall SetVirtualTable_005e03a0();
};
void __cdecl operator delete(void*);
struct FUN_005e06e0_Class
{
    void* __thiscall FUN_005e06e0(unsigned int flags);
};
// Calls FUN_005e03a0 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x005e06e0
void* __thiscall FUN_005e06e0_Class::FUN_005e06e0(unsigned int flags)
{
    ((FUN_005e03a0_Class*)this)->SetVirtualTable_005e03a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_005dd7d0_Class
{
    void ForwardCall_005dd7d0();
};
void __cdecl Deallocate(void* p);
struct FUN_005e0710_Class
{
    void* __thiscall NiTPrimitiveArray_TESTexture_Destroy(unsigned int flags);
};
// @fnv 0x005e0710
// src: COMMUNITY 0x005e0710
void* __thiscall FUN_005e0710_Class::NiTPrimitiveArray_TESTexture_Destroy(unsigned int flags)
{
    ((FUN_005dd7d0_Class*)this)->ForwardCall_005dd7d0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_005e0460_class
{
    void UpdateFields_005e0460();
};
struct FUN_005e0740_class : FUN_005e0460_class
{
    void* __thiscall FUN_005e0740(unsigned int flags);
};
// @fnv 0x005e0740
void* __thiscall FUN_005e0740_class::FUN_005e0740(unsigned int flags)
{
    UpdateFields_005e0460();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_005dd7f0_class
{
    void NiTPrimitiveArray_char_const_Free();
};
struct FUN_005e0770_class
{
    FUN_005e0770_class* NiTPrimitiveArray_char_const_Destroy(unsigned int flags);
};
// @fnv 0x005e0770
// src: COMMUNITY 0x005e0770
FUN_005e0770_class* FUN_005e0770_class::NiTPrimitiveArray_char_const_Destroy(unsigned int flags)
{
    ((FUN_005dd7f0_class*)this)->NiTPrimitiveArray_char_const_Free();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct _Mem_20a4
{
    ~_Mem_20a4();
    _Mem_20a4* __thiscall FUN_005e07a0(unsigned int flags);
};

// Destructs the object and, when bit 0 of flags is set, frees its memory, then returns the pointer.
// @fnv 0x005e07a0
_Mem_20a4* __thiscall _Mem_20a4::FUN_005e07a0(unsigned int flags)
{
    this->_Mem_20a4::~_Mem_20a4();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);

struct FUN_005e0590_shell
{
    void UpdateState_005e0590();
};

struct FUN_005e0800_class
{
    void* __thiscall FUN_005e0800(unsigned int flags);
};

// Calls FUN_005e0590 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005e0800
void* __thiscall FUN_005e0800_class::FUN_005e0800(unsigned int flags)
{
    ((FUN_005e0590_shell*)this)->UpdateState_005e0590();
    if (flags & 1)
        operator delete(this);
    return this;
}

void* __cdecl hkMemoryRouter_getInstance();
struct ref_006815c0_class
{
    ref_006815c0_class* ref_006815c0(void* a, void* b);
    void hkStackMemory_allocateStack();
};
// @fnv 0x005e0aa0
// src: GUESS 0x005e0aa0 (confidence: low)
void Object_UpdateFields_005e0aa0(int a, int b)
{
    ref_006815c0_class* obj = reinterpret_cast<ref_006815c0_class*>(hkMemoryRouter_getInstance());
    reinterpret_cast<ref_006815c0_class*>(
        obj->ref_006815c0(reinterpret_cast<void*>((a << 9) + 0x7f & 0xffffff80), reinterpret_cast<void*>(b)))
        ->hkStackMemory_allocateStack();
}

struct FUN_005e0b10_holder
{
    void __thiscall hkStackMemory_getFreeStackSize();
};
unsigned int __cdecl hkAddByteOffset_005e0b50(void*, int);
struct S_005e0ad0
{
    void* __thiscall hkStackMemory_allocateStack(int a, int b);
};
// @fnv 0x005e0ad0
// src: XBOX_PDB 0x005e0ad0
void* __thiscall S_005e0ad0::hkStackMemory_allocateStack(int aiValue, int aiUnused)
{
    void* p;
    ((FUN_005e0b10_holder*)this)->hkStackMemory_getFreeStackSize();
    p = ((NavMeshPtr*)this)->AnimatingText_GetFullText();
    ((QuantityData*)this)->SetQuantity(hkAddByteOffset_005e0b50(p, aiValue));
    return p;
}

void __cdecl Object_ComputeValue_005e0b40(void*, void*);
struct FUN_005e0b10_Cls
{
    NavMeshPtr m0;
    char _pad[4];
    NavMeshPtr m8;
    void __thiscall hkStackMemory_getFreeStackSize();
};
// Calls FUN_005e0b40 with the results of FUN_00458b50 on m0 and m8.
// @fnv 0x005e0b10
// src: COMMUNITY 0x005e0b10
void __thiscall FUN_005e0b10_Cls::hkStackMemory_getFreeStackSize()
{
    Object_ComputeValue_005e0b40(m0.AnimatingText_GetFullText(), m8.AnimatingText_GetFullText());
}

template <int N> struct EndianSizeTag
{
    unsigned char v;
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl TESFile_TransformReferencedInt64(void*, EndianSizeTag<0>);
struct T2870
{
    void __thiscall ProcessState_005e2870();
};
// @fnv 0x005e2870
// src: GUESS 0x005e2870 (confidence: low)
void __thiscall T2870::ProcessState_005e2870()
{
    BSEndian((unsigned char*)this, EndianSizeTag<0>());
    TESFile_TransformReferencedInt64((char*)this + 8, EndianSizeTag<0>());
}

struct FUN_005ec700_shell : TESFaction_RankDataView
{
    void SetFlag20(bool b);
};

// @fnv 0x005ec700
void FUN_005ec700_shell::SetFlag20(bool abSet)
{
    abSet ? *GetRankDataList() |= 0x20 : *GetRankDataList() &= ~0x20;
}

struct FUN_005ed160_Class
{
    bool Equals(int arg);
};

// Compares three consecutive 16-bit values at this and arg, returning true only if all three pairs match.
// @fnv 0x005ed160
bool FUN_005ed160_Class::Equals(int arg)
{
    bool equal = false;
    if (*(short*)this == *(short*)arg && *(short*)(this + 2) == *(short*)(arg + 2) &&
        *(short*)(this + 4) == *(short*)(arg + 4))
        equal = true;
    return equal;
}

struct FUN_00692290_class
{
    void __thiscall BSSimpleArray_unsigned_short_1024_InitialSetup(unsigned int, unsigned int);
};
struct FUN_005eee30_class
{
    void* vtbl;
    FUN_005eee30_class* __thiscall BSSimpleArray_short_1024_BSSimpleArray_short_1024();
};
// Sets the vtable pointer and calls FUN_00692290 with 0, 0, then returns this.
// @fnv 0x005eee30
// src: COMMUNITY 0x005eee30
FUN_005eee30_class* __thiscall FUN_005eee30_class::BSSimpleArray_short_1024_BSSimpleArray_short_1024()
{
    vtbl = (void*)&DAT_010472e4;
    ((FUN_00692290_class*)this)->BSSimpleArray_unsigned_short_1024_InitialSetup(0, 0);
    return this;
}

struct GlobalObject_00869f00_Deleting : GlobalObject_00869f00
{
    GlobalObject_00869f00* __thiscall FUN_005ef590(unsigned int flags);
};

// Calls ResetToGlobal, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x005ef590
GlobalObject_00869f00* __thiscall GlobalObject_00869f00_Deleting::FUN_005ef590(unsigned int flags)
{
    ResetToGlobal();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_005ef1d0_class
{
    void __thiscall FUN_005ef1d0();
};
void __cdecl operator delete(void*);

struct FUN_005ef5f0_class
{
    void* __thiscall FUN_005ef5f0(unsigned int flags);
};

// @fnv 0x005ef5f0
void* __thiscall FUN_005ef5f0_class::FUN_005ef5f0(unsigned int flags)
{
    reinterpret_cast<FUN_005ef1d0_class*>(this)->FUN_005ef1d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);

// The virtual destructor emits the scalar deleting destructor at 0x005ef620.

// The common array storage-release helper calls virtual slot 2 and clears pBuffer.
void __fastcall FreeSimpleArrayStorage(void* array);
// @fnv 0x005ef860
template <>
void BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::ReallocateStorage(unsigned int a, unsigned int b)
{
    if (pBuffer)
    {
        if (b == SimpleArrayStorage)
        {
            pBuffer = _Reallocate(pBuffer, a);
        }
        else
        {
            FootIK_DATA__FootIK_Leg_DATA* r = _Allocate(a);
            UpdateEntryValue(r, pBuffer, b);
            FreeSimpleArrayStorage(this);
            pBuffer = r;
        }
    }
    else
    {
        pBuffer = _Allocate(a);
        SimpleArrayStorage = a;
    }
}

struct FUN_005efa40_class
{
    short m0;
    short m2;
    char pad4[24];
    float m1C;
    float m20;
    float m24;
    FUN_005efa40_class* __thiscall LookIK_DATA_LookIK_Head_DATA_LookIK_Head_DATA();
};
// Initializes the object: sets m0 and m2 to -1, zeroes m1C, m20 and m24, and returns this.
// @fnv 0x005efa40
// src: COMMUNITY 0x005efa40
FUN_005efa40_class* __thiscall FUN_005efa40_class::LookIK_DATA_LookIK_Head_DATA_LookIK_Head_DATA()
{
    m0 = -1;
    m2 = -1;
    m1C = 0.0f;
    m20 = 0.0f;
    m24 = 0.0f;
    return this;
}

struct FUN_005f29f0_Class
{
    void __thiscall SetValueAtIndex(unsigned int index, float value);
};
// If index is below the count at offset 0x34 and the pointer at 0x38 is non-null, writes value into the float slot at index*16 of that array.
// @fnv 0x005f29f0
void __thiscall FUN_005f29f0_Class::SetValueAtIndex(unsigned int index, float value)
{
    if (index >= *(unsigned int*)((char*)this + 0x34))
        return;
    if (!*(void**)((char*)this + 0x38))
        return;
    *(float*)((char*)*(void**)((char*)this + 0x38) + index * 16) = value;
}

struct FUN_005f2a30_Class
{
    char _pad0[0x34];
    unsigned int m34;
    void* m38;
    void __thiscall SetEntryValue(unsigned int index, unsigned int value);
};
// If index is below m34 and m38 is non-null, writes value into the 16-byte entry at m38 + index*16, offset 12.
// @fnv 0x005f2a30
void __thiscall FUN_005f2a30_Class::SetEntryValue(unsigned int index, unsigned int value)
{
    if (index >= m34)
        return;
    if (m38 == 0)
        return;
    *(unsigned int*)((char*)m38 + index * 16 + 12) = value;
}

struct FUN_005f2b20_Class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    unsigned int m34;
    int m38;
    void __thiscall SetEntryFloat(unsigned int a, float b);
};
// If index a is below m34 and m38 is set, writes float b at offset 8 of the 16-byte entry at m38 + a*16.
// @fnv 0x005f2b20
void __thiscall FUN_005f2b20_Class::SetEntryFloat(unsigned int uiIndex, float fValue)
{
    if (uiIndex >= m34)
        return;
    if (!m38)
        return;
    *(float*)(m38 + uiIndex * 16 + 8) = fValue;
}

// @fnv 0x005f6000
void TESChallenge::SetCompletedRecurring(bool abSet)
{
    !abSet ? *(int*)((char*)this + 0x70) &= ~2 : *(int*)((char*)this + 0x70) |= 2;
    MarkForSave();
}

// @fnv 0x005f6060
void TESChallenge::SetShowZero(bool show)
{
    !show ? nFlags &= ~4 : nFlags |= 4;
    MarkForSave();
}

// Sets or clears bit 0 of the flags at offset 0x70 based on set, then calls MarkForSave.
// @fnv 0x005f6570
void TESChallenge::MarkCompleted(bool set)
{
    !set ? *(int*)((char*)this + 0x70) &= ~1 : *(int*)((char*)this + 0x70) |= 1;
    MarkForSave();
}

struct FUN_005f74b0_cls
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void Target(int, int);
    void __thiscall TargetWithFloatArg(int a, float b);
};
// Calls the virtual Target method, converting the float argument to int.
// @fnv 0x005f74b0
void __thiscall FUN_005f74b0_cls::TargetWithFloatArg(int aiValue, float afValue)
{
    Target(aiValue, (int)afValue);
}

struct Inner74e0
{
    virtual void i0();
    virtual void i1();
    virtual int __thiscall i2(int);
};
struct Outer74e0
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
    virtual void u12();
    virtual void u13();
    virtual void u14();
    virtual void u15();
    virtual void u16();
    virtual void u17();
    virtual void u18();
    virtual void u19();
    virtual void u20();
    virtual void u21();
    virtual void u22();
    virtual void u23();
    virtual void u24();
    virtual void u25();
    virtual void u26();
    virtual void u27();
    virtual void u28();
    virtual void u29();
    virtual void u30();
    virtual void u31();
    virtual void u32();
    virtual void u33();
    virtual void u34();
    virtual void u35();
    virtual void u36();
    virtual void u37();
    virtual void u38();
    virtual void u39();
    virtual void u40();
    virtual void u41();
    virtual void u42();
    virtual void u43();
    virtual void u44();
    virtual void u45();
    virtual void u46();
    virtual void u47();
    virtual void u48();
    virtual void u49();
    virtual void u50();
    virtual void u51();
    virtual void u52();
    virtual void u53();
    virtual void u54();
    virtual void u55();
    virtual void u56();
    virtual void u57();
    virtual void u58();
    virtual void u59();
    virtual void u60();
    virtual void u61();
    virtual void u62();
    virtual void u63();
    virtual void u64();
    virtual void u65();
    virtual void u66();
    virtual void u67();
    virtual void u68();
    virtual void u69();
    virtual void u70();
    virtual void u71();
    virtual void u72();
    virtual void u73();
    virtual void u74();
    virtual void u75();
    virtual void u76();
    virtual void u77();
    virtual void u78();
    virtual void u79();
    virtual void u80();
    virtual void u81();
    virtual void u82();
    virtual void u83();
    virtual void u84();
    virtual void u85();
    virtual void u86();
    virtual void u87();
    virtual void u88();
    virtual void u89();
    virtual void u90();
    virtual void u91();
    virtual void u92();
    virtual void u93();
    virtual void u94();
    virtual void u95();
    virtual void u96();
    virtual void u97();
    virtual void u98();
    virtual void u99();
    virtual void u100();
    virtual void __thiscall targ(int, int);
    char _pad[252];
    Inner74e0 fld100;
    void __thiscall ForwardToTarget(int, int);
};
// Calls targ with a and the sum of fld100.i2(a) and b.
// @fnv 0x005f74e0
void __thiscall Outer74e0::ForwardToTarget(int aiValue, int b)
{
    targ(aiValue, fld100.i2(aiValue) + b);
}

struct GlobalObject_0045cfe0
{
    int** Int();
};
extern GlobalObject_0045cfe0 g_011cd3b4;
extern GlobalObject_0045cfe0 g_011cd538;
extern GlobalObject_0045cfe0 g_011cdde0;
struct FUN_005fbeb0_shell
{
    int* TESCreature_GetSoundLevelValue();
};
// Returns the int pointed to by one of three global objects, chosen by the value at this+0x154 (2, 1 or 0); otherwise returns null.
// @fnv 0x005fbeb0
// src: COMMUNITY 0x005fbeb0
int* FUN_005fbeb0_shell::TESCreature_GetSoundLevelValue()
{
    int* result = 0;
    switch (*(int*)((char*)this + 0x154))
    {
    case 2:
        result = *g_011cd3b4.Int();
        break;
    case 1:
        result = *g_011cd538.Int();
        break;
    case 0:
        result = *g_011cdde0.Int();
        break;
    }
    return result;
}

struct FUN_005ff520_shell
{
    unsigned int TESIdleForm_GetIndexForChild(unsigned int);
};
struct FUN_005ff560_shell
{
    void RemoveChildAndRelinkNeighbors(unsigned int);
};
struct FUN_005ff5d0_class
{
    void TESIdleForm_RemoveChild(unsigned int a);
};
// If a is nonzero and the object's field at offset 0x40 is set, calls FUN_005ff520(a) and passes its result to RemoveChildAndRelinkNeighbors.
// @fnv 0x005ff5d0
// src: COMMUNITY 0x005ff5d0
void FUN_005ff5d0_class::TESIdleForm_RemoveChild(unsigned int uiValue)
{
    if (uiValue && *(unsigned int*)((char*)this + 0x40))
    {
        unsigned int r = ((FUN_005ff520_shell*)this)->TESIdleForm_GetIndexForChild(uiValue);
        ((FUN_005ff560_shell*)this)->RemoveChildAndRelinkNeighbors(r);
    }
}

char** __cdecl NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(unsigned int);

struct FUN_005e08e0_class
{
    int* vtbl;
    char** data;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    unsigned short e;
    FUN_005e08e0_class* __thiscall NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture_NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture(unsigned short x, unsigned short y);
};

// @fnv 0x005e08e0
// src: COMMUNITY 0x005e08e0
FUN_005e08e0_class* __thiscall FUN_005e08e0_class::NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture_NiTArray_NiPointer_NiTexture_NiTNewInterface_NiPointer_NiTexture(unsigned short x, unsigned short y)
{
    vtbl = &DAT_0103d3e8;
    a = x;
    d = y;
    b = 0;
    c = 0;
    if (a > 0)
        data = NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(a);
    else
        data = 0;
    return this;
}

struct FUN_005ef9a0_shell
{
    virtual void v0();
    virtual int v1(unsigned int);
    void ConstructEntries(int, unsigned int);
};
struct FUN_005efb30_class
{
    void* vtbl;
    unsigned int m4;
    unsigned int m8;
    unsigned int mc;
    void BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_InitialSetup(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x005efb30
// src: COMMUNITY 0x005efb30
void FUN_005efb30_class::BSSimpleArray_LookIK_DATA_LookIK_Head_DATA_1024_InitialSetup(unsigned int requested, unsigned int savedSize)
{
    m4 = 0;
    m8 = 0;
    mc = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m4 = ((FUN_005ef9a0_shell*)this)->v1(requested);
        mc = requested;
    }
    if (savedSize > 0)
    {
        ((FUN_005ef9a0_shell*)this)->ConstructEntries(m4, savedSize);
        m8 = savedSize;
    }
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_005efdd0_class
{
    void __thiscall BSSimpleArray_MoveItems_0(char* a, char* b, unsigned int count);
};
// Copies count 2-byte elements from b to a, iterating forward when a < b and backward when a > b to handle overlap.
// @fnv 0x005efdd0
// src: COMMUNITY 0x005efdd0
void __thiscall FUN_005efdd0_class::BSSimpleArray_MoveItems_0(char* pDest, char* pSrc, unsigned int count)
{
    if (count <= 0)
        return;
    if (pDest < pSrc)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(pDest + i * 2, pSrc + i * 2, 2);
    }
    else if (pDest > pSrc)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            FUN_00ec7230(pDest + i * 2, pSrc + i * 2, 2);
    }
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);

// @fnv 0x005efe70
template <>
void BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::UpdateEntryValue(
    FootIK_DATA__FootIK_Leg_DATA* destination, FootIK_DATA__FootIK_Leg_DATA* source, unsigned int c)
{
    if (c <= 0)
        return;
    if (destination < source)
    {
        for (unsigned int i = 0; i < c; ++i)
            FUN_00ec7230(reinterpret_cast<char*>(destination) + i * 0x38, reinterpret_cast<char*>(source) + i * 0x38, 0x38);
    }
    else if (destination > source)
    {
        for (int i = c - 1; i >= 0; --i)
            FUN_00ec7230(reinterpret_cast<char*>(destination) + i * 0x38, reinterpret_cast<char*>(source) + i * 0x38, 0x38);
    }
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int count);
// Copies count 6-byte elements from src to dst, iterating forward when dst<src and backward when dst>src to handle overlap.
// @fnv 0x005eff10
template <>
void BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::UpdateEntryValue(
    GrabIK_DATA__GrabIK_Arm_DATA* destination, GrabIK_DATA__GrabIK_Arm_DATA* source, unsigned int count)
{
    if (count <= 0)
        return;
    if (destination < source)
    {
        for (unsigned int i = 0; i < count; i++)
            FUN_00ec7230(reinterpret_cast<char*>(destination) + i * 6, reinterpret_cast<const char*>(source) + i * 6, 6);
    }
    else if (destination > source)
    {
        for (int i = (int)count - 1; i >= 0; i--)
            FUN_00ec7230(reinterpret_cast<char*>(destination) + i * 6, reinterpret_cast<const char*>(source) + i * 6, 6);
    }
}

struct FNStub
{
    char* __thiscall GetFullName();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_005f6f70_Class
{
    void TESClass_SaveGameTES();
};

// @fnv 0x005f6f70
// src: COMMUNITY 0x005f6f70
void FUN_005f6f70_Class::TESClass_SaveGameTES()
{
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 0x44, 0x1c);
    unsigned char a;
    a = 0;
    if (((FNStub*)((char*)this + 0x18))->GetFullName())
        a = BSStringLength(((FNStub*)((char*)this + 0x18))->GetFullName());
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&a, 1);
    if (a)
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(((FNStub*)((char*)this + 0x18))->GetFullName(), a);
    a = 0;
    if (((FNStub*)((char*)this + 0x2c))->GetFullName())
        a = BSStringLength(((FNStub*)((char*)this + 0x2c))->GetFullName());
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&a, 1);
    if (a)
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(((FNStub*)((char*)this + 0x2c))->GetFullName(), a);
}

struct FUN_005e0950
{
    int m0;
    int m4;
    unsigned short m8;
    unsigned short ma;
    unsigned short mc;
    unsigned short me;
    FUN_005e0950(unsigned short, unsigned short);
};
// @fnv 0x005e0950
FUN_005e0950::FUN_005e0950(unsigned short ausSize, unsigned short b)
{
    m0 = (int)&DAT_0103d3f8;
    m8 = ausSize;
    me = b;
    ma = 0;
    mc = 0;
    if (m8 > 0)
        m4 = (int)NiTMallocInterface<ActorCombatGroup*>::Allocate(m8);
    else
        m4 = 0;
}

namespace fnv_005e09c0 {
struct FUN_005e09c0
{
    int* vtbl;
    ActorCombatGroup** data;
    unsigned short count;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short capacity;
    FUN_005e09c0(unsigned short a, unsigned short b);
};
// @fnv 0x005e09c0
FUN_005e09c0::FUN_005e09c0(unsigned short ausCount, unsigned short ausCapacity)
{
    vtbl = (int*)&DAT_0103d408;
    count = ausCount;
    capacity = ausCapacity;
    m0a = 0;
    m0c = 0;
    if (count > 0)
        data = NiTMallocInterface<ActorCombatGroup*>::Allocate(count);
    else
        data = 0;
}
}  // namespace fnv_005e09c0

namespace fnv_005e0a30 {
extern int DAT_0103d418;
struct FUN_005e0a30_t
{
    void* __thiscall NiTArray_char_const_NiTMallocInterface_char_const_Init(unsigned short a, unsigned short b);
};
// @fnv 0x005e0a30
// src: COMMUNITY 0x005e0a30
void* FUN_005e0a30_t::NiTArray_char_const_NiTMallocInterface_char_const_Init(unsigned short ausCapacity, unsigned short b)
{
    *(int*)this = (int)&DAT_0103d418;
    *(unsigned short*)((char*)this + 8) = ausCapacity;
    *(unsigned short*)((char*)this + 14) = b;
    *(unsigned short*)((char*)this + 10) = 0;
    *(unsigned short*)((char*)this + 12) = 0;
    if (*(unsigned short*)((char*)this + 8) > 0)
        *(void**)((char*)this + 4) = (void*)NiTMallocInterface<ActorCombatGroup*>::Allocate(*(unsigned short*)((char*)this + 8));
    else
        *(void**)((char*)this + 4) = 0;
    return this;
}
}  // namespace fnv_005e0a30


struct FUN_005ef6a0Class
{
    virtual void v0();
    virtual void* v4(int);
    virtual void v8();
    virtual void* v12(void*, int);
    void* p;
    int pad;
    int idx;
    void SetOrReplace(int a, int b);
};
// @fnv 0x005ef6a0
void FUN_005ef6a0Class::SetOrReplace(int a, int b)
{
    if (p)
    {
        if (b == idx)
        {
            p = v12(p, a);
        }
        else
        {
            void* pNew = v4(a);
            ((FUN_005efdd0_class*)this)->BSSimpleArray_MoveItems_0((char*)pNew, (char*)p, (unsigned int)b);
            FreeSimpleArrayStorage(this);
            p = pNew;
        }
    }
    else
    {
        p = v4(a);
        idx = a;
    }
}

struct FUN_005ef7f0_Data
{
    short x0;
    short x2;
    short x4;
    char x6;
    float x8;
    float xc;
    float x10;
    float x14;
    float x18;
    float x1c;
    void* __thiscall FootIK_DATA_FootIK_Leg_DATA_FootIK_Leg_DATA();
};

// Initialises all fields of the object: shorts to -1, byte to 0, floats to 0.0, and returns this.
// @fnv 0x005ef7f0
// src: COMMUNITY 0x005ef7f0
void* __thiscall FUN_005ef7f0_Data::FootIK_DATA_FootIK_Leg_DATA_FootIK_Leg_DATA()
{
    x0 = -1;
    x2 = -1;
    x4 = -1;
    x6 = 0;
    x8 = 0.0f;
    xc = 0.0f;
    x10 = 0.0f;
    x14 = 0.0f;
    x18 = 0.0f;
    x1c = 0.0f;
    return this;
}

// @fnv 0x005ef910
template <>
void BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::_InitialSetup(unsigned int requested, unsigned int savedSize)
{
    pBuffer = 0;
    iSize = 0;
    SimpleArrayStorage = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        pBuffer = _Allocate(requested);
        SimpleArrayStorage = requested;
    }
    if (savedSize > 0)
    {
        InitializeItems(pBuffer, savedSize);
        iSize = savedSize;
    }
}

// @fnv 0x005efc90
template <>
void BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::ReallocateStorage(unsigned int a, unsigned int b)
{
    if (pBuffer)
    {
        if (b == SimpleArrayStorage)
        {
            pBuffer = _Reallocate(pBuffer, a);
        }
        else
        {
            GrabIK_DATA__GrabIK_Arm_DATA* t = _Allocate(a);
            UpdateEntryValue(t, pBuffer, b);
            FreeSimpleArrayStorage(this);
            pBuffer = t;
        }
    }
    else
    {
        pBuffer = _Allocate(a);
        SimpleArrayStorage = a;
    }
}

void __cdecl hkDeallocateStack_char(void*);
struct FUN_005e0600_Class
{
    void ProcessAndTransformResult_005e0600();
};
// @fnv 0x005e0600
// src: GUESS 0x005e0600 (confidence: low)
void FUN_005e0600_Class::ProcessAndTransformResult_005e0600()
{
    hkDeallocateStack_char((void*)(unsigned int)*(GO*)this);
}

void* __cdecl FUN_00885750();
// @fnv 0x005e0b60
// src: XBOX_PDB 0x005e0b60
void hkDeallocateStack_char(void* p)
{
    reinterpret_cast<QuantityData*>(&reinterpret_cast<BSSimpleList<unsigned int>*>(FUN_00885750())->GetItem())
        ->hkStackMemory_deallocateStack((unsigned int)p);
}

struct FUN_005e3fe0_class
{
    void __thiscall SwapEndianFields();
};

// Byte-swaps the fields at offsets 0x0, 0x14, 0x18, 0x28 through 0x40 and 0x50 of this object via BSEndian.
// @fnv 0x005e3fe0
void FUN_005e3fe0_class::SwapEndianFields()
{
    BSEndian(reinterpret_cast<unsigned char*>(this), EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x14, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x18, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x28, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x2c, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x30, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x34, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x38, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x3c, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x40, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x50, EndianSizeTag<0>());
}

struct FUN_005eee10
{
    ~FUN_005eee10();
};

struct FUN_005ef560_Class : public FUN_005eee10
{
    void* FUN_005ef560(unsigned int flags);
};

FUN_005eee10::~FUN_005eee10()
{}

// Runs the base destructor, then frees this with _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x005ef560
void* FUN_005ef560_Class::FUN_005ef560(unsigned int flags)
{
    FUN_005eee10::~FUN_005eee10();
    if (flags & 1U)
        _Deallocate(this);
    return this;
}

// @fnv 0x005f11f0
unsigned char TESAttributes::GetAttributeValue5()
{
    return GetAttributeValue(5);
}

// @fnv 0x005f1290
unsigned char TESAttributes::GetAttributeValue10()
{
    return GetAttributeValue(10);
}

// FindByKey: list search over a cursor list at this+0x10c.
class FNVCursor
{
  public:
    bool IsEnd();
    void** Value();
    FNVCursor* Next();
};
class FNVObject
{
  public:
    void* Key();
};
int __cdecl FNVCompare(void* key, void* a1);

class FUN_005e0860_cls
{
  public:
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
    FNVCursor m_kNode;
    bool FindByKey(void* a1, FNVObject** a2);
};

// Searches the cursor list for an object whose key matches a1, stores it in a2 and returns true, otherwise returns false.
// @fnv 0x005e0860
bool FUN_005e0860_cls::FindByKey(void* pKey, FNVObject** ppFound)
{
    if (pKey == 0)
    {
        return false;
    }
    FNVCursor* cur = &m_kNode;
    while (cur != 0 && !cur->IsEnd())
    {
        FNVObject* v = (FNVObject*)*cur->Value();
        if (FNVCompare(v->Key(), pKey) == 0)
        {
            *ppFound = v;
            return true;
        }
        cur = cur->Next();
    }
    return false;
}

// @fnv 0x005e0b40
// src: GUESS 0x005e0b40 (confidence: low)
int __cdecl Object_ComputeValue_005e0b40(unsigned int arg0, unsigned int arg1)
{
    return (int)(arg1 - arg0);
}

// @fnv 0x005e0b50
// src: COMMUNITY 0x005e0b50
unsigned int __cdecl hkAddByteOffset_005e0b50(void* base, int offset)
{
    return (unsigned int)base + offset;
}

struct ObjectHeader
{
    unsigned int flags;
};
struct Component
{
    unsigned int state;
};
struct CompleteObject : ObjectHeader, Component
{
};
struct VirtualReader
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual Component* readEntry(bool* success);
    CompleteObject* ReadCompleteObject();
};
// Reads an entry via readEntry and returns it cast to CompleteObject, ignoring the success flag.
// @fnv 0x005e4ab0
CompleteObject* VirtualReader::ReadCompleteObject()
{
    bool success;
    return static_cast<CompleteObject*>(readEntry(&success));
}

struct LightingDataCmp
{
    short s00;
    short s02;
    short s04;
    unsigned char b06;
    unsigned char unk07;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;

    bool ComputeValue_005ec760(const LightingDataCmp* other);
};

// @fnv 0x005ec760
// src: GUESS 0x005ec760 (confidence: low)
bool LightingDataCmp::ComputeValue_005ec760(const LightingDataCmp* other)
{
    bool result = false;
    if (s00 == other->s00 && s02 == other->s02 && s04 == other->s04 && b06 == other->b06 && f08 == other->f08 &&
        f0C == other->f0C && f10 == other->f10 && f14 == other->f14 && f18 == other->f18 && f1C == other->f1C &&
        f20 == other->f20 && f24 == other->f24 && f28 == other->f28 && f2C == other->f2C && f30 == other->f30 &&
        f34 == other->f34)
    {
        result = true;
    }
    return result;
}

struct Entry38
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
};

struct StrArray
{
    void* vtbl;
    char** data;
    int unk08;
    int unk0C;
    unsigned int GetSize();
    char*& GetAt(unsigned int index);
    void Clear(bool);
    void SetSize(unsigned int, bool);
};

struct EntryArray
{
    void* vtbl;
    Entry38* data;
    int unk08;
    int unk0C;
    unsigned int GetSize();
    Entry38* GetEntry(unsigned int index);
    void Clear(bool);
    void SetEntryCount(unsigned int, bool);
};

int strcpy_s(char* dst, unsigned int size, const char* src);

// 0x005ecb30 also binds FootIKOperations::CopyData; its flag, seven floats and two arrays differ from Data.h.
struct FootIKConfiguration
{
    unsigned char flag;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    StrArray strings;
    EntryArray entries;
    void AssignEntriesStringsAndFloats(FootIKConfiguration* other);
};

// Clears entries and strings, copies the other object's entry array and deep-copies its strings, then copies the float fields and flag.
// @fnv 0x005ecb30
// src: GUESS 0x005ecb30 (confidence: medium)
void FootIKConfiguration::AssignEntriesStringsAndFloats(FootIKConfiguration* other)
{
    entries.Clear(true);
    for (unsigned int i = 0; i < strings.GetSize(); i++)
    {
        delete strings.GetAt(i);
    }
    strings.Clear(true);
    entries.SetEntryCount(other->entries.GetSize(), true);
    strings.SetSize(other->strings.GetSize(), true);
    for (unsigned int j = 0; j < other->entries.GetSize(); j++)
    {
        *entries.GetEntry(j) = *other->entries.GetEntry(j);
    }
    for (unsigned int k = 0; k < other->strings.GetSize(); k++)
    {
        unsigned int len = BSStringLength(other->strings.GetAt(k)) + 1;
        char* str = new char[len];
        strcpy_s(str, len, other->strings.GetAt(k));
        strings.GetAt(k) = str;
    }
    f04 = other->f04;
    f08 = other->f08;
    f0C = other->f0C;
    f10 = other->f10;
    f14 = other->f14;
    f18 = other->f18;
    f1C = other->f1C;
    flag = other->flag;
}

namespace fnv_005ecfd0 {
int strcpy_s(char* dst, unsigned int size, const char* src);

struct Entry28
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct StringArray
{
    void* m_ppVirtualMethodTable;
    char** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    char*& GetAt(unsigned int index);
    void Clear(bool freeMemory);
    void SetSize(unsigned int size, bool freeMemory);
};

struct EntryArray
{
    void* m_ppVirtualMethodTable;
    Entry28* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    Entry28& GetAt(unsigned int index);
    void Clear(bool freeMemory);
    void Resize(unsigned int size, bool freeMemory);
};

struct StringEntryData
{
    unsigned char flag;
    StringArray strings;
    EntryArray entries;
    void AssignEntriesAndStrings(StringEntryData* other);
};

// Clears entries and strings, then deep-copies the other object's entries, duplicated strings and flag into this object.
// @fnv 0x005ecfd0
// src: GUESS 0x005ecfd0 (confidence: medium)
void StringEntryData::AssignEntriesAndStrings(StringEntryData* other)
{
    unsigned int i;
    unsigned int j3;
    unsigned int k;
    unsigned int len3;
    char* str;

    entries.Clear(true);
    for (i = 0; i < strings.GetSize(); i++)
    {
        delete strings.GetAt(i);
    }
    strings.Clear(true);
    entries.Resize(other->entries.GetSize(), true);
    strings.SetSize(other->strings.GetSize(), true);
    for (j3 = 0; j3 < other->entries.GetSize(); j3++)
    {
        entries.GetAt(j3) = other->entries.GetAt(j3);
    }
    for (k = 0; k < other->strings.GetSize(); k++)
    {
        len3 = BSStringLength(other->strings.GetAt(k)) + 1;
        str = new char[len3];
        strcpy_s(str, len3, other->strings.GetAt(k));
        strings.GetAt(k) = str;
    }
    flag = other->flag;
}
}  // namespace fnv_005ecfd0

// FUN_005eedc0 : returns &m_pEntries[index] (element size 0x38)
struct FUN_005eedc0_item
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
};

struct FUN_005eedc0_cls
{
    int m_unk00;
    FUN_005eedc0_item* m_pEntries;
    FUN_005eedc0_item* GetIndexedValue_005eedc0(int index);
};

// @fnv 0x005eedc0
// src: GUESS 0x005eedc0 (confidence: low)
FUN_005eedc0_item* FUN_005eedc0_cls::GetIndexedValue_005eedc0(int index)
{
    return &m_pEntries[index];
}

struct FUN_005efa80_cls
{
    virtual void v0();
    virtual void* v4(void* a);
    virtual void v8();
    virtual void* vC(void* a, void* b);
    void* m_04;
    unsigned int m_08;
    void* m_0c;
    void Helper(void* a, void* b, unsigned int c);
    void Finish();
    void BSSimpleArray_PathingLocation_1024_ReallocateBuffer(void* a1, unsigned int a2);
};

// @fnv 0x005efa80
// src: XBOX_PDB 0x005efa80
void FUN_005efa80_cls::BSSimpleArray_PathingLocation_1024_ReallocateBuffer(void* a1, unsigned int a2)
{
    if (m_04 != 0)
    {
        if (a2 == (unsigned int)m_0c)
        {
            m_04 = vC(m_04, a1);
        }
        else
        {
            void* tmp = v4(a1);
            Helper(tmp, m_04, a2);
            Finish();
            m_04 = tmp;
        }
    }
    else
    {
        m_04 = v4(a1);
        m_0c = a1;
    }
}

void* operator new(unsigned int uiSize, void* pvMem);
void operator delete(void* pvMem, void* pvPlace);

struct EFBC0Item
{
    EFBC0Item();

    short m_sValue0;
    short m_sValue1;
    short m_sValue2;
};

// Default-constructs each of the given number of EFBC0Item elements in place.
// @fnv 0x005efbc0
template <>
void BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::InitializeItems(
    GrabIK_DATA__GrabIK_Arm_DATA* base, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&reinterpret_cast<EFBC0Item*>(base)[i]) EFBC0Item;
}

struct Vec3Sub
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    Vec3Sub();
};

extern Vec3Sub DAT_011f426c;

struct RootCls_b9637
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    RootCls_b9637();
    ~RootCls_b9637();
};

class FUN_005f21c0_cls : public RootCls_b9637
{
  public:
    virtual void unk00();
    int unk18;
    Vec3Sub m_1c;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    int unk30;
    int unk34;
    int unk38;

    FUN_005f21c0_cls(unsigned short a);
    void SetAnimGroupType(unsigned short a);
};

// @fnv 0x005f21c0
FUN_005f21c0_cls::FUN_005f21c0_cls(unsigned short a) : RootCls_b9637(), m_1c()
{
    unk18 = 0;
    unk28 = 0;
    unk29 = 0;
    unk2a = 0;
    unk2b = 0;
    unk2c = 0;
    m_1c = DAT_011f426c;
    unk30 = 0;
    SetAnimGroupType(a);
    unk38 = 0;
    unk34 = 0;
}

struct PairRecord16
{
    unsigned int unk00;
    unsigned char m_flag;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int m_uiFilterValue;
    unsigned int unk0C;
};

class FUN_005f2a70_cls
{
  public:
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
    unsigned int m_uiItemCount;
    PairRecord16* m_pRecords;

    void SetRecordFlagAndValue(unsigned int index, unsigned char flag, unsigned int value);
};

// @fnv 0x005f2a70
void FUN_005f2a70_cls::SetRecordFlagAndValue(unsigned int index, unsigned char flag, unsigned int value)
{
    if (index > m_uiItemCount)
    {
    }
    else
    {
        if (m_pRecords == 0)
        {
        }
        else
        {
            m_pRecords[index].m_flag = flag;
            m_pRecords[index].m_uiFilterValue = value;
        }
    }
}

extern double DAT_010484f0;

struct FUN_005f2ac0_rec
{
    unsigned char m_00[4];
    unsigned char m_04;
    unsigned char m_05[11];
};

struct FUN_005f2ac0_cls
{
    char m_000[0x34];
    unsigned int m_34;
    FUN_005f2ac0_rec* m_38;
    void __thiscall SetRecordValue(unsigned int idx, float f);
};

// If idx is within m_34 and m_38 is set, stores f scaled by DAT_010484f0 as a byte into m_38[idx].m_04.
// @fnv 0x005f2ac0
void __thiscall FUN_005f2ac0_cls::SetRecordValue(unsigned int uiIndex, float afValue)
{
    if (!(uiIndex < m_34))
    {
        return;
    }
    if (!m_38)
    {
        return;
    }
    m_38[uiIndex].m_04 = (unsigned char)(afValue * DAT_010484f0);
}

struct Ext
{
    float GetMult();
};

struct Ref;

struct SndInfo
{
    int m00;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

struct SndForm
{
    SndInfo GetInfo();
    int GetSoundId(int flags);
    int GetId2(int flags);
};

struct AudioPlaybackHandle
{
    int m0;
    int m4;
    int m8;
    AudioPlaybackHandle();
    ~AudioPlaybackHandle();
    AudioPlaybackHandle& operator=(const AudioPlaybackHandle& o);
    void SetPos(float x, float y, float z);
    void SetVolume(float v);
    void SetNode(void* node);
    void SetFreq(float f);
    void Play(bool b);
};

struct SndList
{
    SndForm* GetSoundByEditorID(int idx);
};

struct SndTable
{
    SndForm* GetSoundByEditorID(int idx);
};

struct Holder
{
    ~Holder();
    SndTable* GetTable();
};

struct StrHolder
{
    char* GetStr();
};

struct StrElem
{
    int m0;
    int m4;
    StrHolder* Get();
};

struct ArrHolder
{
    StrElem* GetArr();
};

struct Proc
{
    SndForm* GetSoundByEditorID();
};

struct Ref
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void* GetNode();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual Ext* GetExt();
    virtual void v7A();
    virtual void v7B();
    virtual void v7C();
    virtual NiPoint3* GetPos();
    virtual void v7E();
    virtual void v7F();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual bool IsAlive();
    bool IsSomething();
    void HandleRef(Ref* r);
    SndList* GetSndList();
    Holder* GetHolder(int n);
    Proc* GetProc();
};

union EntryData
{
    float f;
    unsigned int u;
};

struct Entry
{
    float fTime_2;
    unsigned char ucType;
    EntryData data;
    SndForm* pForm;
};

extern Ref* g_pPlayer;
extern double g_dPercent;
extern float g_fVolume;
extern double g_dZero;

int __cdecl GetFlagBits(int v);
bool __cdecl CheckDist(SndForm* form, NiPoint3 pos3, float f);
void __cdecl DoTypeA(Ref* r, int type);
void __cdecl DoTypeB(Ref* r, int n);
void __cdecl DoShake(float f, NiPoint3* pos3);
double __cdecl StrToD(const char* s);

struct FUN_005f2b60_cls
{
    unsigned int GetCount();
    Entry* GetAt(unsigned int i);
    int GetKind();
    void ProcessSoundEntries(Ref* ref, float fFrom, float fTo, Script* script);
};

// Iterates the entry list, firing entries whose time falls in the range and dispatching sound, effect, shake and ref handling by entry type.
// @fnv 0x005f2b60
void FUN_005f2b60_cls::ProcessSoundEntries(Ref* ref, float fFrom, float fTo, Script* script)
{
    bool bWrap5 = false;
    float fMultVal = 1.0f;
    Ext* pExt6 = ref->GetExt();
    if (fTo < fFrom)
        bWrap5 = true;
    for (unsigned int i = 0; i < GetCount(); i++)
    {
        Entry* pEntry7 = GetAt(i);
        float fTime_2 = pEntry7->fTime_2;
        bool bFire = false;
        if (bWrap5 && (fTime_2 > fFrom || fTime_2 <= fTo))
            bFire = true;
        else if (fTime_2 > fFrom && fTime_2 <= fTo)
            bFire = true;
        if (bFire)
        {
            if (pEntry7->pForm != 0)
            {
                bool bLoopTmp = (pEntry7->pForm->GetInfo().m04 & 0x40) ? true : false;
                int iBits7 = GetFlagBits(pEntry7->pForm->GetInfo().m04);
                NiPoint3 pos3 = *ref->GetPos();
                if (iBits7 != 0 || CheckDist(pEntry7->pForm, pos3, 1.0f))
                {
                    if (pExt6 != 0 && GetKind() >= 0xb1 && GetKind() <= 0xc7)
                        fMultVal *= ref->GetExt()->GetMult();
                    AudioPlaybackHandle snd = AudioMgr_BSAudio::Get()->Make(
                        pEntry7->pForm->GetSoundId((bLoopTmp ? 1 : 2) | 0x100 |
                                                   ((ref == g_pPlayer && !g_pPlayer->IsSomething()) ? 0x40000 : 0) |
                                                   (ref != g_pPlayer ? 0 : 0x200000) | iBits7 | 0x40000000),
                        pEntry7->pForm);
                    snd.SetPos(pos3.x, pos3.y, pos3.z);
                    snd.SetVolume((float)(pEntry7->ucType / g_dPercent));
                    snd.SetNode(ref->GetNode());
                    snd.SetFreq(pEntry7->data.f * fMultVal);
                    snd.Play(GetFlagBits(pEntry7->pForm->GetInfo().m04) != 0);
                }
            }
            else
            {
                switch (pEntry7->ucType)
                {
                case 0xd:
                    g_pPlayer->HandleRef(ref);
                    break;
                case 0xc: {
                    int iFoundB;
                    StrElem* pArrVal = script->GetData(&iFoundB)->GetArr();
                    float fVal8 = 1.0f;
                    if (iFoundB != 0)
                    {
                        char* pStr7 = pArrVal[pEntry7->data.u & 0xff].Get()->GetStr();
                        unsigned int uOff_2 = (pEntry7->data.u & 0xffffff00) >> 8;
                        fVal8 = (float)StrToD(pStr7 + uOff_2 + 0x11);
                    }
                    AudioMgr_BSAudio::Get()->PlayAt(ref->GetNode(), fVal8, 0x40000000);
                    break;
                }
                case 0:
                case 1:
                case 2:
                case 3:
                    DoTypeA(ref, pEntry7->ucType);
                    break;
                case 4:
                case 5:
                case 6:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                    if (ref->IsActor())
                    {
                        Ref* pActorA = ref;
                        if (pActorA != 0 && pActorA->IsAlive())
                        {
                            SndList* pList5 = ref->GetSndList();
                            SndForm* pSnd2 =
                                pList5->GetSoundByEditorID(pEntry7->ucType < 0x16 ? pEntry7->ucType : pEntry7->ucType - 0xb);
                            NiPoint3 pos7 = *ref->GetPos();
                            if (pSnd2 != 0 && CheckDist(pSnd2, pos7, 1.0f))
                            {
                                AudioPlaybackHandle snd2 = AudioMgr_BSAudio::Get()->Make2(
                                    pSnd2->GetId2((ref != g_pPlayer ? 0 : 0x200000) | 0x40000102));
                                if (pExt6 != 0 && GetKind() >= 0xb1 && GetKind() <= 0xc7)
                                    fMultVal *= ref->GetExt()->GetMult();
                                snd2.SetPos(pos7.x, pos7.y, pos7.z);
                                snd2.SetNode(ref->GetNode());
                                snd2.SetVolume(g_fVolume);
                                snd2.SetFreq(1.0f * fMultVal);
                                snd2.Play(0);
                            }
                        }
                    }
                    break;
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x14:
                case 0x15:
                case 0x16:
                    if (ref->IsActor())
                    {
                        Ref* pActor = ref;
                        Holder* pHolder3 = pActor->GetHolder(2);
                        if (pHolder3 != 0)
                        {
                            SndTable* pSearchEntries = pHolder3->GetTable();
                            SndForm* pSnd3 = pSearchEntries->GetSoundByEditorID(pEntry7->ucType);
                            NiPoint3 pos = *ref->GetPos();
                            if (pSnd3 != 0 && CheckDist(pSnd3, pos, 1.0f))
                            {
                                AudioPlaybackHandle snd3;
                                if (ref == g_pPlayer)
                                {
                                    snd3 = AudioMgr_BSAudio::Get()->Make2(pSnd3->GetId2(0x40200101));
                                }
                                else
                                {
                                    snd3 = AudioMgr_BSAudio::Get()->Make2(pSnd3->GetId2(0x40000102));
                                    snd3.SetPos(pos.x, pos.y, pos.z);
                                    snd3.SetNode(ref->GetNode());
                                }
                                snd3.SetVolume(g_fVolume);
                                snd3.SetFreq(1.0f * fMultVal);
                                snd3.Play(0);
                            }
                            delete pHolder3;
                        }
                    }
                    break;
                case 9:
                    DoTypeB(ref, 9);
                    break;
                case 0xa:
                    DoTypeB(ref, 10);
                    break;
                case 0x10:
                    if (ref->IsActor())
                    {
                        Ref* pActor7 = ref;
                        Proc* pProc5 = pActor7->GetProc();
                        if (pProc5 != 0)
                        {
                            SndForm* pSnd4 = pProc5->GetSoundByEditorID();
                            if (pSnd4 != 0)
                            {
                                AudioPlaybackHandle snd5 = AudioMgr_BSAudio::Get()->Make2(
                                    pSnd4->GetId2((ref != g_pPlayer ? 0 : 0x200000) | 0x40000102));
                                NiPoint3 pos_ = *ref->GetPos();
                                snd5.SetPos(pos_.x, pos_.y, pos_.z);
                                snd5.SetNode(ref->GetNode());
                                snd5.SetVolume(g_fVolume);
                                snd5.SetFreq(1.0f * fMultVal);
                                snd5.Play(0);
                            }
                        }
                    }
                    break;
                case 0xb:
                    if (script != 0)
                    {
                        int iFoundTmp;
                        StrElem* pArr2 = script->GetData(&iFoundTmp)->GetArr();
                        if (iFoundTmp != 0)
                        {
                            char* pStr6 = pArr2[pEntry7->data.u & 0xff].Get()->GetStr();
                            unsigned int uOff5 = (pEntry7->data.u & 0xffffff00) >> 8;
                            float fShake3 = (float)StrToD(pStr6 + uOff5 + 0x12);
                            if (fShake3 > g_dZero)
                                DoShake(fShake3, ref->GetPos());
                        }
                    }
                    break;
                }
            }
        }
    }
}

// GetEntryByte0d: lookup of a per-entry byte value by index.
// The class holds a count of entries at +0x0c and a pointer to a table of
// 16-byte entries at +0x14; the byte read from each entry sits at +0x0d.
struct F4c00Entry
{
    int m_i00;
    int m_i04;
    int m_i08;
    unsigned char m_uc0c;
    unsigned char m_uc0d;
    unsigned char m_uc0e;
    unsigned char m_uc0f;
};

struct FUN_005f4c00_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    unsigned int m_uCount;
    int m_i10;
    F4c00Entry* m_pEntries;
    unsigned char GetEntryByte0d(unsigned int index);
};

// Returns byte 0x0d of the entry at index if index is below m_uCount, otherwise 0xff.
// @fnv 0x005f4c00
unsigned char FUN_005f4c00_cls::GetEntryByte0d(unsigned int index)
{
    return index < m_uCount ? m_pEntries[index].m_uc0d : 0xff;
}

struct FUN_005f4db0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m10;
    bool TESAnimGroup_IsJumpingLandAnim();
};

extern "C" int __cdecl FUN_005f2440(unsigned short value);

// Returns true if FUN_005f2440(m10) yields one of the codes 0xe5, 0xf1, 0xf2, 0xf3 or 0xf4, otherwise false.
// @fnv 0x005f4db0
// src: COMMUNITY 0x005f4db0
bool FUN_005f4db0_cls::TESAnimGroup_IsJumpingLandAnim()
{
    switch (FUN_005f2440(this->m10))
    {
    case 0xe5:
    case 0xf1:
    case 0xf2:
    case 0xf3:
    case 0xf4:
        return true;
    default:
        return false;
    }
}

class B5FA120Form
{
  public:
    int GetFormType();
    bool TESObjectWEAP_IsEmbeddedWeapon();
};

class B5FA120Checker
{
  public:
    bool TESCreature_CanWearItem(B5FA120Form* pkForm);
};

// Returns true if the form's type is 0x1e, 0x28 or 0x29, or if it is type 0x28 and FUN_0046e8c0 succeeds; otherwise false.
// @fnv 0x005fa120
// src: COMMUNITY 0x005fa120
bool B5FA120Checker::TESCreature_CanWearItem(B5FA120Form* pkForm)
{
    switch (pkForm->GetFormType())
    {
    case 0x1e:
    case 0x28:
    case 0x29:
        return true;
    }
    if (pkForm->GetFormType() == 0x28 && pkForm->TESObjectWEAP_IsEmbeddedWeapon())
        return true;
    return false;
}

struct FUN_005fbdd0_cls
{
    void TESCreature_CheckEmbeddedWeaponNodes(int a1);
    void* FUN_00717e50();
    void* FUN_006815c0();
    int FUN_00401170();
    unsigned char TESObjectWEAP_IsEmbeddedWeapon();
    int TESObjectWEAP_GetEmbeddedWeaponNode();
    void FUN_00481790(void* item);
    void* FUN_00726070();
};

int __cdecl BSUtilities_GetObjectByName(int a, int b);

// @fnv 0x005fbdd0
// src: COMMUNITY 0x005fbdd0
void FUN_005fbdd0_cls::TESCreature_CheckEmbeddedWeaponNodes(int a1)
{
    void* node2;
    void* ptr;
    void* tmp;
    unsigned char flag_;

    if (*(unsigned char*)((char*)this + 0x150) != 0 || a1 == 0)
    {
        return;
    }
    node2 = ((FUN_005fbdd0_cls*)((char*)this + 0x64))->FUN_00717e50();
    while (node2 != 0)
    {
        ptr = *(void**)((FUN_005fbdd0_cls*)node2)->FUN_006815c0();
        flag_ = 0;
        if (ptr != 0 && ((FUN_005fbdd0_cls*)((void**)ptr)[1])->FUN_00401170() == 0x28)
        {
            tmp = ((void**)ptr)[1];
            if (((FUN_005fbdd0_cls*)tmp)->TESObjectWEAP_IsEmbeddedWeapon() &&
                BSUtilities_GetObjectByName(a1, ((FUN_005fbdd0_cls*)tmp)->TESObjectWEAP_GetEmbeddedWeaponNode()) == 0)
            {
                ((FUN_005fbdd0_cls*)((char*)this + 0x64))->FUN_00481790(ptr);
                node2 = ((FUN_005fbdd0_cls*)((char*)this + 0x64))->FUN_00717e50();
                flag_ = 1;
            }
        }
        if (!flag_)
        {
            node2 = ((FUN_005fbdd0_cls*)node2)->FUN_00726070();
        }
    }
    *(unsigned char*)((char*)this + 0x150) = 1;
}

class B5FC120Form
{
  public:
    virtual ~B5FC120Form();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class B5FC120FullName
{
  public:
    virtual ~B5FC120FullName();
    int unk04;
    int unk08;
};

class B5FC120Texture
{
  public:
    virtual ~B5FC120Texture();
    int unk04;
    int unk08;
};

// TESEyes destructor
class FUN_005fc120 : public B5FC120Form, public B5FC120FullName, public B5FC120Texture
{
  public:
    virtual ~FUN_005fc120();
};

// Destructor for a class that inherits from B5FC120Form, B5FC120FullName and B5FC120Texture; it has an empty body.
// @fnv 0x005fc120
FUN_005fc120::~FUN_005fc120()
{}

class C5FDB90Form
{
  public:
    virtual ~C5FDB90Form();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class C5FDB90FullName
{
  public:
    virtual ~C5FDB90FullName();

    int unk04;
    int unk08;
};

class C5FDB90Model
{
  public:
    virtual ~C5FDB90Model();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class C5FDB90Texture
{
  public:
    virtual ~C5FDB90Texture();

    int unk04;
    int unk08;
};

// TESHair
class FUN_005fdb90 : public C5FDB90Form, public C5FDB90FullName, public C5FDB90Model, public C5FDB90Texture
{
  public:
    virtual ~FUN_005fdb90();
};

// @fnv 0x005fdb90
FUN_005fdb90::~FUN_005fdb90()
{}

class FUN_005fe040_baseA
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_005fe040_baseA();
    ~FUN_005fe040_baseA();
};

class FUN_005fe040_baseB
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_005fe040_baseB();
    ~FUN_005fe040_baseB();
};

class FUN_005fe040_memberC
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_005fe040_memberC();
    ~FUN_005fe040_memberC();
};

class FUN_005fe040_memberD
{
  public:
    unsigned int unk00;
    FUN_005fe040_memberD();
    ~FUN_005fe040_memberD();
};

class FUN_005fe040 : public FUN_005fe040_baseA, public FUN_005fe040_baseB
{
  public:
    FUN_005fe040_memberC m_30;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    FUN_005fe040_memberD m_4c;

    FUN_005fe040();
    virtual void unk_Vfn();
    void unk_Init(unsigned int aSize);
    void unk_Finish();
};

// Initializes the object by calling unk_Init with size 0x48, sets m_40 to 0, then calls unk_Finish.
// @fnv 0x005fe040
FUN_005fe040::FUN_005fe040()
{
    unk_Init(0x48);
    m_40 = 0;
    unk_Finish();
}

class ThisBase_b3969
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    ThisBase_b3969(int aValue, bool aFlag);
    ~ThisBase_b3969();
};

class ThisMember_b3969
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b3969(unsigned int aValue, bool aFlag);
    ~ThisMember_b3969();
};

class FUN_005ffaf0 : public ThisBase_b3969
{
  public:
    unsigned char m_14;
    ThisMember_b3969 m_18;

    FUN_005ffaf0();
};

// Initialises the base with value 0x25 and flag true, constructs m_18 with 0 and true, and sets m_14 to 0.
// @fnv 0x005ffaf0
FUN_005ffaf0::FUN_005ffaf0() : ThisBase_b3969(0x25, true), m_18(0, true)
{
    m_14 = 0;
}

// Thiscall dtor, 98 bytes /MT /Od /GS /EHsc: body call on this (state 1),
// member sub-object at +0x18 released (state 0), then base sub-object dtor on this (state -1).
class FUN_005ffb60_base
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ~FUN_005ffb60_base();
};

class FUN_005ffb60_child
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    ~FUN_005ffb60_child();
};

class FUN_005ffb60_cls : public FUN_005ffb60_base
{
  public:
    FUN_005ffb60_child m_18;
    void Tidy();
    ~FUN_005ffb60_cls();
};

// @fnv 0x005ffb60
FUN_005ffb60_cls::~FUN_005ffb60_cls()
{
    Tidy();
}

struct C5E0200AutoMemHelper
{
    C5E0200AutoMemHelper(int iType, bool bFlag, const char* pcFile, int iLine);
    ~C5E0200AutoMemHelper();

    int m_uiLogicalSize;
};

extern const char g_ac5E0200SourceFile[];

class C5E0200File
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void Process();
    virtual void VFunc20();
    virtual void Prepare();

    bool Open(const char* pcFileName, bool bWrite);
    bool j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(const char* pcFileName);
};

// Opens pcFileName for reading; if that succeeds, calls Prepare and Process and returns whether the open succeeded.
// @fnv 0x005e0200
// src: COMMUNITY 0x005e0200
bool C5E0200File::j_ReadSettingsFromFile_SettingCollection_VSetting_QEAA_NPEBD_Z(const char* pcFileName)
{
    C5E0200AutoMemHelper kMemHelper(9, true, g_ac5E0200SourceFile, 0x19d);
    bool bResult = Open(pcFileName, false);
    if (bResult)
    {
        Prepare();
        Process();
    }
    return bResult;
}

struct NiRTTI_S;
struct SkinInst_S;
struct TriGeom_S;
struct Node_S;

struct AVObj_S
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node_S* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual TriGeom_S* IsTriBasedGeom();
};

struct Node_S : AVObj_S
{
    unsigned int GetChildCount();
    AVObj_S* GetAt(unsigned int);
};

struct TriGeom_S : AVObj_S
{
    SkinInst_S* GetSkinInstance();
};

struct SkinPartObj_S
{
    void SetPartitionVisible(unsigned int partId, bool show);
};

SkinPartObj_S* NiDynamicCast(const NiRTTI_S* rtti, SkinInst_S* obj);
extern const NiRTTI_S g_011f49d8;

// @fnv 0x005e4970
void SetPartitionVisibility(int partition, AVObj_S* root)
{
    Node_S* nodeB = root->IsSceneNode();
    unsigned int i = 0;
    while (nodeB && i < nodeB->GetChildCount())
    {
        TriGeom_S* geom8 = nodeB->GetAt(i) ? nodeB->GetAt(i)->IsTriBasedGeom() : root->IsTriBasedGeom();
        i++;
        SkinInst_S* aSkin = geom8 ? geom8->GetSkinInstance() : 0;
        SkinPartObj_S* part = NiDynamicCast(&g_011f49d8, aSkin);
        if (part)
        {
            for (int j = 0; j < 15; j++)
            {
                if (j == partition)
                {
                    part->SetPartitionVisible(partition + 100, true);
                }
                else
                {
                    part->SetPartitionVisible((unsigned short)j, false);
                    part->SetPartitionVisible(j + 200, false);
                }
                part->SetPartitionVisible(j * 1000, false);
            }
        }
    }
}

struct CompareEntry
{
    bool Differs(CompareEntry*);
};
struct CompareArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int Size();
    CompareEntry* At(unsigned int);
};
struct CompareStrings
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int Size();
    const char*& At(unsigned int);
};
int CompareText(const char*, const char*);
struct CompareData
{
    unsigned char flag;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    CompareStrings strings;
    CompareArray entries;
    bool BGSRagdoll_FootIK_Compare(CompareData* other);
};
// Compares entry and string arrays plus flag and float fields against another CompareData, returning whether any differ.
// @fnv 0x005ec920
// src: COMMUNITY 0x005ec920
bool CompareData::BGSRagdoll_FootIK_Compare(CompareData* other)
{
    bool different = false;
    if (entries.Size() != other->entries.Size())
        different = true;
    if (!different)
    {
        for (unsigned int index = 0; index < entries.Size() && !different; ++index)
            different = different || entries.At(index)->Differs(other->entries.At(index));
    }
    if (strings.Size() != other->strings.Size())
        different = true;
    if (!different)
    {
        for (unsigned int textIndex = 0; textIndex < strings.Size() && !different; ++textIndex)
            different = different || CompareText(strings.At(textIndex), other->strings.At(textIndex)) != 0;
    }
    if (different || flag != other->flag || f04 != other->f04 || f08 != other->f08 || f0C != other->f0C ||
        f10 != other->f10 || f14 != other->f14 || f18 != other->f18 || f1C != other->f1C)
        different = true;
    return different;
}

struct Entry005ed1e0
{
    bool IsNotEqual(Entry005ed1e0* other);
};
struct Array005ed1e0
{
    void* unknown_00;
    void* unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int FUN_0044ddc0();
};
struct EntryArray005ed1e0 : Array005ed1e0
{
    Entry005ed1e0* FUN_0069ccf0(unsigned int index);
};
struct StringArray005ed1e0 : Array005ed1e0
{
    const char*& FUN_00877a30(unsigned int index);
};
int __cdecl BSstrcmp(const char*, const char*);
struct Target005ed1e0
{
    unsigned char unknown_00;
    unsigned char unknown_01;
    unsigned short unknown_02;
    StringArray005ed1e0 strings_04;
    EntryArray005ed1e0 entries_14;
    bool BGSRagdoll_GrabIK_Compare(Target005ed1e0* other);
};
// Compares entry and string array counts and elements plus unknown_00 against another object, returning whether any differ.
// @fnv 0x005ed1e0
// src: COMMUNITY 0x005ed1e0
bool Target005ed1e0::BGSRagdoll_GrabIK_Compare(Target005ed1e0* other)
{
    bool different = false;
    if (entries_14.FUN_0044ddc0() != other->entries_14.FUN_0044ddc0())
        different = true;
    if (!different)
    {
        for (unsigned int i = 0; i < entries_14.FUN_0044ddc0() && !different; ++i)
            different = different || entries_14.FUN_0069ccf0(i)->IsNotEqual(other->entries_14.FUN_0069ccf0(i));
    }
    if (strings_04.FUN_0044ddc0() != other->strings_04.FUN_0044ddc0())
        different = true;
    if (!different)
    {
        for (unsigned int j = 0; j < strings_04.FUN_0044ddc0() && !different; ++j)
            different = different || BSstrcmp(strings_04.FUN_00877a30(j), other->strings_04.FUN_00877a30(j));
    }
    if (different || unknown_00 != other->unknown_00)
        different = true;
    return different;
}

void* __cdecl operator new(unsigned int, void*);

struct SpawnItem : FUN_005ef7f0_Data
{
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    SpawnItem();
};

// Constructs count SpawnItem objects in place at base + i * 0x38 for each i from 0 to count-1.
// @fnv 0x005ef750
template <>
void BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024>::InitializeItems(FootIK_DATA__FootIK_Leg_DATA* base, unsigned int count)
{
    unsigned int i;

    for (i = 0; i < count; ++i)
    {
        new ((void*)(reinterpret_cast<char*>(base) + i * 0x38)) SpawnItem;
    }
}

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct E5EF9A0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    E5EF9A0Entry();
};

class E5EF9A0Allocator
{
  public:
    void ConstructEntries(E5EF9A0Entry* pkArray, unsigned int ItemUpdateArray);
};

// Constructs each E5EF9A0Entry in the given array by placement new, for the given count.
// @fnv 0x005ef9a0
void E5EF9A0Allocator::ConstructEntries(E5EF9A0Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) E5EF9A0Entry;
}

struct ChallengeView;
struct ChallengeNode
{
    ChallengeView** FUN_006815c0();
    ChallengeNode* FUN_00726070();
};
struct ChallengeName
{
    const char* TESModel_GetModel();
    int unk00;
    int unk04;
    int unk08;
};
struct ChallengeDescription
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual const char* GetText(int, unsigned int);
    int unk04;
};
struct ChallengeView : TESChallenge
{
    int TESChallenge_GetCompleted();
    int TESChallenge_GetRecurring();
    int FUN_005f5930();
    int TESChallenge_GetUnlocked();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    int FUN_005e3fa0();
    int FUN_006286d0();
    int GetField54();
    unsigned int GetShortAtOffset64();
    int HasFlag8();
    void ClearField6C();
    void FUN_005f6060(bool);
    void SetFlagAndMarkForSave(bool);
    int FUN_005f5f80();
};
struct ChallengeReward
{
    void RunScriptOnTarget(void*, int);
};
extern ChallengeNode DAT_011cb448;
extern GlobalObject_0045cf30 g_011cb4d4;
extern void* DAT_011dea3c;
void __cdecl FUN_004d5c60(int);
int __cdecl BSsprintf(char*, int, const char*, ...);
const char* __cdecl TESTexture_GetTextureName(ChallengeView*, int);
bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void __cdecl Interface_PlayMenuSound(int);
void __cdecl FUN_005f5880();

// @fnv 0x005f6110
// src: COMMUNITY 0x005f6110
bool __cdecl IncrementScriptedChallenge(ChallengeView* pSourceChallenge, int amount)
{
    ChallengeNode* pNode = &DAT_011cb448;
    bool result = false;
    ChallengeView* found = 0;
    while (pNode)
    {
        found = *pNode->FUN_006815c0();
        bool sameType = true;
        if (found)
        {
            if (found->TESChallenge_GetCompleted() && !found->TESChallenge_GetRecurring())
            {
                pNode = pNode->FUN_00726070();
                continue;
            }
            if (found->FUN_005f5930() && !found->TESChallenge_GetUnlocked())
            {
                pNode = pNode->FUN_00726070();
                continue;
            }
            if (pSourceChallenge->GetHavokWorldObjectCountInSceneGraph_0084e3a0() != found->GetHavokWorldObjectCountInSceneGraph_0084e3a0())
            {
                sameType = false;
                pNode = pNode->FUN_00726070();
                continue;
            }
            found->IncrementProgress_005f60e0(amount);
            if (found->FUN_005e3fa0() >= found->FUN_006286d0())
            {
                if (reinterpret_cast<ChallengeNode*>(reinterpret_cast<char*>(found) + sizeof(TESForm) + sizeof(TESFullName) + sizeof(TESDescription))->FUN_00726070())
                    ((ChallengeReward*)reinterpret_cast<ChallengeNode*>(reinterpret_cast<char*>(found) + sizeof(TESForm) + sizeof(TESFullName) + sizeof(TESDescription))->FUN_00726070())->RunScriptOnTarget(DAT_011dea3c, 0);
                if (found->GetField54() != 11 || found->GetShortAtOffset64() != 27)
                    FUN_004d5c60(27);
                if (reinterpret_cast<ChallengeName*>(reinterpret_cast<char*>(found) + sizeof(TESForm))->TESModel_GetModel() && reinterpret_cast<ChallengeDescription*>(reinterpret_cast<char*>(found) + sizeof(TESForm) + sizeof(TESFullName))->GetText(0, 0x43534544) && *g_011cb4d4.Bool())
                {
                    char message[512];
                    BSsprintf(message, 512, "%s   %d\\%d\n%s", reinterpret_cast<ChallengeName*>(reinterpret_cast<char*>(found) + sizeof(TESForm))->TESModel_GetModel(), found->FUN_006286d0(),
                                 found->FUN_006286d0(), reinterpret_cast<ChallengeDescription*>(reinterpret_cast<char*>(found) + sizeof(TESForm) + sizeof(TESFullName))->GetText(0, 0x43534544));
                    QueueUIMessage(message, 0, TESTexture_GetTextureName(found, 0), 0, 2.0f, false);
                    Interface_PlayMenuSound(21);
                }
                if (found->TESChallenge_GetRecurring() && !found->HasFlag8())
                {
                    int remainder = found->FUN_005e3fa0() - found->FUN_006286d0();
                    found->ClearField6C();
                    found->FUN_005f6060(true);
                    found->IncrementProgress_005f60e0(remainder);
                }
                else
                {
                    found->SetFlagAndMarkForSave(true);
                    result = true;
                }
            }
            else
            {
                int value = found->FUN_005e3fa0();
                int item = found->FUN_005f5f80() ? found->FUN_005f5f80() : 100;
                for (int current = value; current >= 0; current -= item)
                {
                    if (current == 0)
                    {
                        if (reinterpret_cast<ChallengeName*>(reinterpret_cast<char*>(found) + sizeof(TESForm))->TESModel_GetModel() && reinterpret_cast<ChallengeDescription*>(reinterpret_cast<char*>(found) + sizeof(TESForm) + sizeof(TESFullName))->GetText(0, 0x43534544) &&
                            *g_011cb4d4.Bool())
                        {
                            char message[512];
                            BSsprintf(message, 512, "%s   %d\\%d\n%s", reinterpret_cast<ChallengeName*>(reinterpret_cast<char*>(found) + sizeof(TESForm))->TESModel_GetModel(),
                                         found->FUN_005e3fa0(), found->FUN_006286d0(),
                                         reinterpret_cast<ChallengeDescription*>(reinterpret_cast<char*>(found) + sizeof(TESForm) + sizeof(TESFullName))->GetText(0, 0x43534544));
                            QueueUIMessage(message, 0, TESTexture_GetTextureName(found, 0), 0, 2.0f, false);
                        }
                    }
                }
            }
        }
        pNode = pNode->FUN_00726070();
    }
    if (result)
        FUN_005f5880();
    return true;
}

int __cdecl BSstrcmp(const char*, const char*);
#include "../../include/NavMeshStaticAvoidNode.h"
struct NodeArray : BSSimpleArray<NavMeshStaticAvoidNode*, 1024>
{
    NavMeshStaticAvoidNode* FUN_00691750(int index);
};
struct FUN_005ece50_class
{
    unsigned char m0;
    BSSimpleArray<const char*, 1024> m4;
    NodeArray m14;
    unsigned char BGSRagdoll_LookIK_Compare(FUN_005ece50_class* other);
};
// Compares two instances by node-array size and per-node equality, string-array size and per-string comparison, and the m0 byte; returns 1 if any differ.
// @fnv 0x005ece50
// src: COMMUNITY 0x005ece50
unsigned char FUN_005ece50_class::BGSRagdoll_LookIK_Compare(FUN_005ece50_class* other)
{
    unsigned char bStack_5 = 0;
    unsigned int uStack_18;
    {
        unsigned int uStack_c;
        if (m14.GetSize() != other->m14.GetSize())
            bStack_5 = 1;
        if (bStack_5 == 0)
        {
            for (uStack_18 = 0; uStack_18 < m14.GetSize() && bStack_5 == 0; ++uStack_18)
            {
                bStack_5 =
                    (bStack_5 == 0 &&
                     reinterpret_cast<FUN_005ecd10_cls*>(m14.FUN_00691750((int)uStack_18))->IsUnequal((int)other->m14.FUN_00691750((int)uStack_18)) == 0)
                        ? 0
                        : 1;
            }
        }
        if (m4.GetSize() != other->m4.GetSize())
            bStack_5 = 1;
        if (bStack_5 == 0)
        {
            for (uStack_c = 0; uStack_c < m4.GetSize() && bStack_5 == 0; ++uStack_c)
            {
                bStack_5 = (bStack_5 == 0 && BSstrcmp(m4.GetAt((int)uStack_c), other->m4.GetAt((int)uStack_c)) == 0)
                               ? 0
                               : 1;
            }
        }
    }
    if (bStack_5 != 0 || m0 != other->m0)
        bStack_5 = 1;
    return bStack_5;
}

struct SoundDataHandler
{
    TESSound* GetSoundByEditorID(const char*);
};
extern PlayerCharacter* g_thePlayer;
extern SoundDataHandler* DAT_011c3f2c;
const char* __cdecl GetStringByIndex(const char*);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// Builds a "BRUSH<prefix><Sneak|Run|Walk>" sound name from the player's state and looks it up via the sound data handler.
// @fnv 0x005e2a70
TESSound* GetBrushSound(const char* apPrefix)
{
    char soundName[40];
    char fallbackName[40];
    if (g_thePlayer)
    {
        const char* pcMotion;
        if (g_thePlayer->IsSneaking())
            pcMotion = "Sneak";
        else
        {
            const char* pcRegularMotion;
            if (g_thePlayer->MovingCheck())
                pcRegularMotion = "Run";
            else
                pcRegularMotion = "Walk";
            pcMotion = pcRegularMotion;
        }
        _sprintf_s(soundName, 40, "BRUSH%s%s", GetStringByIndex(apPrefix), pcMotion);
        return DAT_011c3f2c->GetSoundByEditorID(soundName);
    }
    else
    {
        _sprintf_s(fallbackName, 40, "BRUSH%sWalk", GetStringByIndex(apPrefix));
        return DAT_011c3f2c->GetSoundByEditorID(fallbackName);
    }
    return 0;
}

extern const char* DAT_01196d40[10];

// @fnv 0x005e2b50
const char* __cdecl GetStringByIndex(int index)
{
    if (index >= 0 && index < 10)
    {
        return DAT_01196d40[index];
    }
    return 0;
}


struct FUN_005e2c10_shell
{
    ::BSStringT<char> m3c;
    bool SetString(const char* a);
};
// Calls Set on the ::BSStringT<char> at offset 0x3c with the given string and a zero argument, then returns true.
// @fnv 0x005e2c10
bool FUN_005e2c10_shell::SetString(const char* apString)
{
    ((::BSStringT<char>*)((char*)this + 0x3c))->Set(apString, 0);
    return true;
}

extern const char $SG3295[];
struct FUN_005e2c30_class
{
    char m0[0x3c];
    GO m3c;
    const char* __thiscall TESSound_GetFormEditorID();
};
// Returns m3c as a string pointer if it is non-null, otherwise returns the fallback string $SG3295.
// @fnv 0x005e2c30
// src: COMMUNITY 0x005e2c30
const char* FUN_005e2c30_class::TESSound_GetFormEditorID()
{
    return (const char*)(unsigned int)m3c ? (const char*)(unsigned int)m3c : $SG3295;
}

struct FUN_005e2ca0_s
{
    void FUN_005e2ca0();
};
struct FUN_005e2c70_s : FUN_005e2ca0_s
{
    void* FUN_005e2c70(unsigned int flags);
};
// Calls FUN_005e2ca0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005e2c70
void* FUN_005e2c70_s::FUN_005e2c70(unsigned int flags)
{
    FUN_005e2ca0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Copies the sound flag, base form data, and playback parameters.
// @fnv 0x005e2d20
void TESSound::CopyFromSound(TESForm* form)
{
    TESSound* sound = dynamic_cast<TESSound*>(form);
    if (!sound)
    {
        return;
    }
    m_cSoundFlag = sound->m_cSoundFlag;
    TESForm_CopyAllComponents(form);
    reinterpret_cast<SoundPlaybackParameters&>(data) = sound->CopyBig();
}

void __cdecl TESForm_AddChunk_3(unsigned int chunkId, unsigned char value);
void __cdecl AppendChunk(unsigned int chunkId, void* data, unsigned int size);
unsigned char __cdecl TESForm_QEndianSwapOnSave();

// The shared sound header has no save/compare declarations. This method-only
// adapter supplies those operations without duplicating the sound layout.
class SoundRecordOperations
{
public:
    void Save();
    bool Compare(TESForm* other);
    bool CompareBase(TESForm* other);
};

// @fnv 0x005e2fa0
void SoundRecordOperations::Save()
{
    reinterpret_cast<TESSound*>(this)->BeginFormRecord();
    reinterpret_cast<TESSound*>(this)->TESSoundFile::Save();
    TESForm_AddChunk_3(0x4d414e52, reinterpret_cast<TESSound*>(this)->m_cSoundFlag);

    if (TESForm_QEndianSwapOnSave() != 0)
    {
        reinterpret_cast<TESSound*>(this)->data.SwapEndian();
    }

    AppendChunk(0x44444e53, &reinterpret_cast<TESSound*>(this)->data, 0x24);

    if (TESForm_QEndianSwapOnSave() != 0)
    {
        reinterpret_cast<TESSound*>(this)->data.SwapEndian();
    }

    reinterpret_cast<TESSound*>(this)->FinishFormRecord();
}

struct ContNode;
int __cdecl BSstricmp(char const* a, char const* b);
bool __fastcall FUN_008256d0(ContNode* node);
ContNode* __fastcall FUN_00726070(ContNode* node);
struct FUN_00408da0_Class
{
    int* TESModel_GetModel();
};
struct ListNodeHelper
{
    void** FUN_006815c0();
};
class DataHandler
{
  public:
    BSSimpleList<TESSound*>* hkpMotion_getLinearVelocity();
};
extern DataHandler* g_dataHandler;

// Searches the data handler's sound list for a TESSound whose stored name matches filename, returning the first match or null.
// @fnv 0x005e3570
// src: XBOX_PDB 0x005e3570
TESSound* __cdecl TESSound_FindSoundByFilename(char const* filename)
{
    TESSound* result = 0;
    if (filename != 0)
    {
        ContNode* node = reinterpret_cast<ContNode*>(g_dataHandler->hkpMotion_getLinearVelocity());
        while (node != 0 && !FUN_008256d0(node))
        {
            TESSound* sound = reinterpret_cast<TESSound*>(*reinterpret_cast<ListNodeHelper*>(node)->FUN_006815c0());
            if (reinterpret_cast<FUN_00408da0_Class*>(reinterpret_cast<char*>(sound) + 0x30)->TESModel_GetModel() != 0)
            {
                if (BSstricmp(reinterpret_cast<char const*>(
                                     reinterpret_cast<FUN_00408da0_Class*>(reinterpret_cast<char*>(sound) + 0x30)
                                         ->TESModel_GetModel()),
                                 filename) == 0)
                {
                    result = sound;
                    break;
                }
            }
            node = FUN_00726070(node);
        }
    }
    return result;
}

int strcpy_s(char* dst, unsigned int size, const char* src);
int strcat_s(char* dst, unsigned int size, const char* src);

bool __cdecl ArchiveManager_GetInvalidateOlderFiles();
bool __cdecl ResolveArchivePath(const char*, char*, int);
BSSimpleList<char*>* __cdecl FileFinder_BuildFileList(const char*, char*, int, int);
unsigned int __cdecl DialogueRandom();
unsigned int __cdecl FUN_00ae9d80(const char*);
unsigned int __cdecl RandomUnsignedInt(unsigned int);

extern unsigned int DAT_011caf04[10];
extern char DAT_011caf2c[10];
extern char DAT_011caf36;

// Searches a directory for a .wav or .ogg file, picks one at random avoiding recent repeats, writes its path into a1 and returns whether one was found.
// @fnv 0x005e3630
bool FindDialogueFile(char* apPath)
{
    char oggPattern3[260];
    char basePath8[260];
    char wavPattern[260];

    strcpy_s(wavPattern, 260, apPath);
    strcpy_s(basePath8, 260, apPath);
    strcat_s(wavPattern, 260, "*.wav");
    strcpy_s(oggPattern3, 260, apPath);
    strcat_s(oggPattern3, 260, "*.ogg");

    if (!ArchiveManager_GetInvalidateOlderFiles())
    {
        bool found7 = false;
        found7 = ResolveArchivePath(wavPattern, basePath8, 8);
        if (found7)
        {
            strcpy_s(apPath, 260, basePath8);
        }
        return found7;
    }

    BSSimpleList<char*>* pFileList = FileFinder_BuildFileList(oggPattern3, basePath8, 8, 0);
    if (!pFileList)
    {
        pFileList = FileFinder_BuildFileList(wavPattern, basePath8, 8, 0);
    }

    if (pFileList != NULL)
    {
        unsigned int aCount = pFileList->ItemsInList();
        if (aCount != 0)
        {
            unsigned int uiChosen = DialogueRandom() % aCount;
            if (aCount > 1)
            {
                unsigned int uiHash = FUN_00ae9d80(apPath);
                for (int iIndex = 0; iIndex < 10; ++iIndex)
                {
                    if (DAT_011caf04[iIndex] == uiHash)
                    {
                        while (uiChosen == (unsigned int)DAT_011caf2c[iIndex])
                        {
                            uiChosen = RandomUnsignedInt(aCount);
                        }
                        break;
                    }
                }
                DAT_011caf04[DAT_011caf36] = uiHash;
                DAT_011caf2c[DAT_011caf36] = (char)uiChosen;
                DAT_011caf36 %= 10;
            }

            BSSimpleList<char*>* pNode = pFileList;
            while (pNode != NULL)
            {
                if (pNode->GetItem() != NULL)
                {
                    if (uiChosen == 0)
                    {
                        strcpy_s(apPath, 260, pNode->GetItem());
                    }
                    void* item = pNode->GetItem();
                    operator delete(item);
                }
                uiChosen--;
                pNode = pNode->GetNext();
            }

            pFileList->RemoveAll();
            delete pFileList;
            return true;
        }
        delete pFileList;
    }
    return false;
}

extern bool DAT_011acdf9;
// @fnv 0x005e39a0
// src: COMMUNITY 0x005e39a0
bool ArchiveManager_GetInvalidateOlderFiles()
{
    return DAT_011acdf9;
}

// @fnv 0x005e39b0
int __cdecl GetFlagMask(unsigned int flags)
{
    int result = 0;
    if (flags & 0x10)
        result = 0x10;
    else if (flags & 0x200)
        result = 0x2000000;
    else if (flags & 0x400)
        result = 0x4000000;
    return result;
}

struct FUN_005e50f0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34[16];
    int GetValueByIndex(int index);
};

// Returns unk34[index] when index is between 0 and 14, otherwise returns 0.
// @fnv 0x005e50f0
int FUN_005e50f0_Obj::GetValueByIndex(int index)
{
    int result = 0;
    if (index > -1 && index < 15)
        result = unk34[index];
    return result;
}

struct FUN_005e5190_Class
{
    unsigned char GetByte63();
};

// @fnv 0x005e5190
unsigned char FUN_005e5190_Class::GetByte63()
{
    return reinterpret_cast<unsigned char*>(this)[0x63];
}

struct Obj5e5300
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned char unk60;
    unsigned char unk61;

    unsigned int GetByte61();
};

// @fnv 0x005e5300
unsigned int Obj5e5300::GetByte61()
{
    return unk61;
}

struct FUN_005e5380_shell
{
    bool __thiscall IsFlag2Set();
};
struct FUN_0066e010_entry
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
};
struct G2
{
    void AddHead(int*);
};
struct FUN_005e5320_class
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    FUN_0066e010_entry m34;
    FUN_0066e010_entry m54;
    FUN_0066e010_entry m74;
    FUN_0066e010_entry m94;
    FUN_0066e010_entry mb4;
    FUN_0066e010_entry md4;
    FUN_0066e010_entry mf4;
    FUN_0066e010_entry m114;
    FUN_0066e010_entry m134;
    FUN_0066e010_entry m154;
    FUN_0066e010_entry m174;
    FUN_0066e010_entry m194;
    FUN_0066e010_entry m1b4;
    FUN_0066e010_entry m1d4;
    FUN_0066e010_entry m1f4;
    void __thiscall BGSBodyPartData_BuildIKPartList(G2* list);
};

// @fnv 0x005e5320
// src: COMMUNITY 0x005e5320
void __thiscall FUN_005e5320_class::BGSBodyPartData_BuildIKPartList(G2* list)
{
    if (list)
    {
        for (int i = 0; i < 15; ++i)
        {
            int* entry = *(int**)((char*)this + 0x34 + i * 4);
            if (!entry)
                continue;
            if (((FUN_005e5380_shell*)entry)->IsFlag2Set())
            {
                list->AddHead((int*)&entry);
            }
        }
    }
}

struct FUN_005e5380_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    unsigned char unk60;

    bool __thiscall IsFlag2Set();
};

// @fnv 0x005e5380
bool FUN_005e5380_Class::IsFlag2Set()
{
    return this->unk60 & 2;
}

// 0x005e0d20 - ScriptRunner::Run-like: nested-run guard, climate-list loop,
// per-run expression object (ctor 0x593490 / dtor 0x483710), optional timing.

extern "C" __int64 DAT_011caec8;
extern "C" char g_nestedScriptRunFormat[];
extern "C" void* __fastcall FNV_GetObjectReference(void*);
__declspec(dllimport) long __stdcall QueryPerformanceCounter(__int64*);
__declspec(dllimport) long __stdcall QueryPerformanceFrequency(__int64*);

bool Interface_IsDebugTextVisible();
void Warning_005b5e40(const char* fmt, int a, int b);

struct Clist
{
    char m0[8];
    unsigned int m8;
    char mC[5];
    unsigned char m11;
};

struct CL8
{
    unsigned char b0;
    unsigned char b1;
    float f4;
};

struct SLoc
{
    ~SLoc();
    char p0[0x10];
    CL8* m10;
    void FUN_005a8ea0();
};

struct Vt130
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual int v130();
};

struct A8 : Vt130
{
    bool FUN_004013e0();
    SLoc* FUN_005abf60();
    Clist* FUN_00500940();
    void AddProfileTime(float value);
};

struct Big79
{
    Big79();
    ~Big79();
    char m[0x710];
};

struct Runner
{
    int m0;
    void* m4;
    SLoc* m8;
    int mC;
    int m10;
    A8* m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    char pad28[0xa1 - 0x28];
    bool m_a1;

    bool FUN_005e13a0(A8* a1, int* pv24, unsigned int* pi, int* pv14, int* pv20, bool b);
    bool FUN_005e1550(A8* a1, int v24, void* v20, int* pv14, unsigned int i, int* pv10, int count, int zero1,
                      int zero2);
    bool RunScript(A8* a1, void* a2, SLoc* a3, int a4, bool a5, char a6, char a7, float a8);
};

// Executes a script on a1, iterating its Clist entries via FUN_005e13a0/FUN_005e1550, and records elapsed time when profiling is enabled.
// @fnv 0x005e0d20
bool Runner::RunScript(A8* apScript, void* apObject, SLoc* a3, int a4, bool a5, char a6, char a7, float a8)
{
    bool vf = Interface_IsDebugTextVisible();
    __int64 ve = 0;
    __int64 vo;
    if (vf)
    {
        if (DAT_011caec8 == 0)
            QueryPerformanceFrequency(&DAT_011caec8);
        QueryPerformanceCounter(&ve);
    }

    this->m_a1 = false;
    if (!apScript || !apScript->FUN_004013e0())
        return this->m_a1;

    if (this->m14)
    {
        Warning_005b5e40(g_nestedScriptRunFormat, this->m14->v130(), apScript->v130());
        return this->m_a1;
    }
    this->m14 = apScript;

    Big79 vb;
    SLoc* vg = 0;
    this->m24 = 0;
    this->m20 = 0;
    int va = 0xffff;
    unsigned int vd = 0;
    this->m0 = a4;
    if (apObject)
        this->m4 = FNV_GetObjectReference(apObject);
    else
        this->m4 = 0;
    if (a3)
    {
        this->m8 = a3;
    }
    else
    {
        vg = apScript->FUN_005abf60();
        this->m8 = vg;
    }

    if (apScript->FUN_00500940()->m11)
    {
        if (!this->m8->m10)
            this->m8->m10 = new CL8;
        this->m8->m10->b0 = a6;
        this->m8->m10->b1 = a7;
        this->m8->m10->f4 = a8;
    }

    int vk = 0;
    int vi = 0;
    int vl = 0;
    bool vw = false;
    int vc = 0;
    while (vd < apScript->FUN_00500940()->m8)
    {
        vc++;
        this->m10 = 0;
        vk = 0;
        if (!this->FUN_005e13a0(apScript, &va, &vd, &vk, &vi, vl != 0))
        {
            apScript->FUN_00500940()->m8 = 0;
            break;
        }
        if (vl)
        {
            vl--;
        }
        else
        {
            if (va == 0x1e)
                break;
            if (!vi)
                vi = (int)apObject;
            if (!this->FUN_005e1550(apScript, va, (void*)vi, &vk, vd, &vl, vc, 0, 0))
            {
                vw = true;
                break;
            }
        }
        vd += vk;
    }

    if (!a5 && !vw)
        this->m8->FUN_005a8ea0();

    if (vg)
        delete vg;

    this->m14 = 0;

    if (vf)
    {
        QueryPerformanceCounter(&vo);
        float elapsed = (float)((double)(vo - ve) / (double)DAT_011caec8);
        reinterpret_cast<ScriptRuntimeOperations*>(apScript)->AddProfileTime(elapsed);
    }

    return this->m_a1;
}

// Stand-in for the native TESBoundAnimObject base subobject (size 0x30).

// Native TESSound destructor; both bases and the string member own their lifetimes.

// The sound bases and filename member own their lifetimes.
// @fnv 0x005e2ca0
TESSound::~TESSound()
{}

void BSEndian(unsigned int*, EndianSizeTag<0>);
void BSEndian(unsigned short*, EndianSizeTag<0>);
// Swaps the byte order of the multi-byte fields in the TESSound__SOUND_DATA structure using BSEndian.
// @fnv 0x005e3020
void TESSound__SOUND_DATA::SwapEndian()
{
    BSEndian(&soundFlags, EndianSizeTag<0>());
    BSEndian(&staticAttenuation, EndianSizeTag<0>());
    BSEndian(&stopTime, EndianSizeTag<0>());
    BSEndian(&attenuationCurve[0], EndianSizeTag<0>());
    BSEndian(&attenuationCurve[1], EndianSizeTag<0>());
    BSEndian(&attenuationCurve[2], EndianSizeTag<0>());
    BSEndian(&attenuationCurve[3], EndianSizeTag<0>());
    BSEndian(&attenuationCurve[4], EndianSizeTag<0>());
    BSEndian(&reverbAttenuation, EndianSizeTag<0>());
    BSEndian(&unk18, EndianSizeTag<0>());
    BSEndian(&unk1c, EndianSizeTag<0>());
    BSEndian(&unk20, EndianSizeTag<0>());
}

struct InitTag5E35
{
};

void __cdecl BSEndian_00401080(int* p, InitTag5E35 tag);
void __cdecl BSEndian_00407a90(short* p, InitTag5E35 tag);

// 0x005e3510 also binds TESSound__SOUND_DATA2::Endian; it swaps a word and two shorts at 0x04/0x08/0x0a, unlike Data.h.
struct SoundConversionFields
{
    int unk00;
    int m_04;
    short m_08;
    short m_0A;

    void SwapMemberByteOrder();
};

// Initializes m_04, m_08, and m_0A by calling FUN_00401080 and FUN_00407a90 with InitTag5E35.
// @fnv 0x005e3510
// src: GUESS 0x005e3510 (confidence: medium)
void SoundConversionFields::SwapMemberByteOrder()
{
    BSEndian_00401080(&m_04, InitTag5E35());
    BSEndian_00407a90(&m_08, InitTag5E35());
    BSEndian_00407a90(&m_0A, InitTag5E35());
}

void __cdecl operator delete(void*);
struct DeletingObject
{
    void FUN_005e4bc0();
    void* FUN_005e4b90(unsigned int flags);
};
// Calls FUN_005e4bc0, then deletes this via operator delete if the low bit of flags is set, and returns this.
// @fnv 0x005e4b90
void* DeletingObject::FUN_005e4b90(unsigned int flags)
{
    FUN_005e4bc0();
    if (flags & 1)
        ::operator delete(this);
    return this;
}


// @fnv 0x005e4bc0
BGSBodyPartData::~BGSBodyPartData()
{
    reinterpret_cast<BGSBodyPartData*>(this)->BGSBodyPartData::ClearData();
}

struct Skin55;
struct Part55
{
    void SetEntryStateByKey(unsigned short partition, bool visible);
};
struct Node55;
struct BaseObject55
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node55* IsSceneNode();
};
struct Object55 : BaseObject55
{
    Object55* NiAVObject_GetParent();
};
struct Skin55 : BaseObject55
{
};
struct Node55 : Object55
{
    Object55* FUN_0043b4a0(unsigned int index);
    unsigned int FUN_0043b480();
};
struct Geometry55 : Object55
{
    Skin55* NiGeometry_GetSkinInstance();
};
struct Name55
{
    const char* SkyObject_GetNiNode();
};
extern const NiRTTI_S DAT_011f4acc;
extern "C" void* __cdecl NiObject_DynamicCast(const NiRTTI_S*, BaseObject55*);
extern "C" Object55* __cdecl BSUtilities_GetObjectByName(Object55*, const char*);
struct Body55
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    Name55* names[15];
    void HidePartitionsUnderAncestor(Object55* ancestor, Object55* root, int excluded, Object55* object);
};

// For each named entry other than excluded, if the object found under root has ancestor as a parent, sets partition i of object's geometry skins not visible.
// @fnv 0x005e55e0
void Body55::HidePartitionsUnderAncestor(Object55* ancestor, Object55* root, int excluded, Object55* object)
{
    Node55* node2 = object->IsSceneNode();
    for (int i = 0; i < 15; ++i)
    {
        if (i == excluded || !names[i])
            continue;
        Object55* found7 = BSUtilities_GetObjectByName(root, names[i]->SkyObject_GetNiNode());
        if (!found7)
            continue;
        while (found7 != root)
        {
            if (found7 == ancestor)
            {
                unsigned int index = 0;
                do
                {
                    Skin55* skin5;
                    Geometry55* geometry = node2
                                               ? (Geometry55*)NiObject_DynamicCast(&DAT_011f4acc, node2->FUN_0043b4a0(index++))
                                               : (Geometry55*)NiObject_DynamicCast(&DAT_011f4acc, object);
                    skin5 = geometry ? geometry->NiGeometry_GetSkinInstance() : 0;
                    Part55* partition2 = (Part55*)NiObject_DynamicCast(&g_011f49d8, skin5);
                    if (partition2)
                        partition2->SetEntryStateByKey((unsigned short)i, false);
                } while (node2 && index < node2->FUN_0043b480());
                break;
            }
            found7 = found7->NiAVObject_GetParent();
        }
    }
}

namespace fnv_005e5750 {
struct SceneNode;
struct SceneBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual SceneNode* IsSceneNode();
};
struct SceneObject : SceneBase
{
    SceneObject* NiAVObject_GetParent();
};
struct SceneNode : SceneObject
{
    SceneObject* NiNode_GetAtChecked(unsigned int);
    unsigned int FUN_0043b480();
};
struct Geometry : SceneObject
{
    SkinInst_S* NiGeometry_GetSkinInstance();
};
struct PartitionSkin
{
    void SetEntryStateByKey(unsigned short, bool);
};
struct ObjectName
{
    const char* SkyObject_GetNiNode();
};
extern "C" SceneObject* __cdecl BSUtilities_GetObjectByName(SceneObject*, const char*);
extern "C" void* __cdecl NiObject_DynamicCast(const NiRTTI_S*, SceneBase*);
extern const NiRTTI_S DAT_011f4acc;
struct PartitionOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    ObjectName* names[15];
    void ApplyPartitionState(SceneObject* target, SceneObject* root, int excluded, SceneObject* source);
};
// For each non-excluded name, if its node under root has target as an ancestor, enables that partition entry on the skin of each geometry in source.
// @fnv 0x005e5750
void PartitionOwner::ApplyPartitionState(SceneObject* target, SceneObject* root, int excluded, SceneObject* source)
{
    SceneNode* node = source->IsSceneNode();
    for (int i = 0; i < 15; ++i)
    {
        if (i == excluded || !names[i])
            continue;
        SceneObject* found = BSUtilities_GetObjectByName(root, names[i]->SkyObject_GetNiNode());
        if (!found)
            continue;
        while (found != root)
        {
            if (found == target)
            {
                int childIndex = 0;
                SkinInst_S* skin;
                do
                {
                    Geometry* geom = node ? (Geometry*)NiObject_DynamicCast(&DAT_011f4acc, node->NiNode_GetAtChecked(childIndex++))
                                          : (Geometry*)NiObject_DynamicCast(&DAT_011f4acc, source);
                    skin = geom ? geom->NiGeometry_GetSkinInstance() : 0;
                    PartitionSkin* partitions = (PartitionSkin*)NiObject_DynamicCast(&g_011f49d8, (SceneBase*)skin);
                    if (partitions)
                    {
                        for (int j = 0; j < 15; ++j)
                        {
                            if (j == i)
                                partitions->SetEntryStateByKey((unsigned short)i, true);
                        }
                    }
                } while (node && childIndex < node->FUN_0043b480());
                break;
            }
            found = found->NiAVObject_GetParent();
        }
    }
}
}  // namespace fnv_005e5750

namespace s5e5d20 {

bool BGSEntryPointFunction_CheckFunctionArguments(int iArg0, int iArg1, void* pvArg2, void* pvArg3, unsigned char ucArg4, float** ppfValue,
                  Actor* pkActor);

// Scales the value pointed to by ppfValue by the result of pkActor->FUN_006b9130() if FUN_005e5b80 succeeds.
// @fnv 0x005e5d20
// src: COMMUNITY 0x005e5d20
void EntryPointFunction_MultiplyValue(void* pvArg0, void* pvArg1, unsigned char ucArg2, float** ppfValue, Actor* pkActor)
{
    if (!BGSEntryPointFunction_CheckFunctionArguments(0, 1, pvArg0, pvArg1, ucArg2, ppfValue, pkActor))
        return;
    float* pfValue = *ppfValue;
    Actor* pkTarget = pkActor;
    *pfValue = pkTarget->CombatTimer_GetTargetTime() * *pfValue;
}

}

namespace s5e63f0 {

extern "C" const char DAT_010462c0[];

struct Base
{
    const char* m_pVtbl;

    Base* BGSEntryPointFunctionData_BGSEntryPointFunctionData();
};

struct Derived : Base
{
    float m_fValue;

    Derived* UpdateState_005e63f0();
};

// Calls FUN_005e6420, stores DAT_010462c0 in m_pVtbl, zeroes m_fValue and returns this.
// @fnv 0x005e63f0
// src: GUESS 0x005e63f0 (confidence: low)
Derived* Derived::UpdateState_005e63f0()
{
    BGSEntryPointFunctionData_BGSEntryPointFunctionData();
    m_pVtbl = DAT_010462c0;
    m_fValue = 0.0f;
    return this;
}

}

namespace s5e6420 {

extern "C" const char DAT_010462e0[];

struct Holder
{
    const char* m_pTable;

    Holder* BGSEntryPointFunctionData_BGSEntryPointFunctionData();
};

// @fnv 0x005e6420
// src: EXE 0x005e6420
Holder* Holder::BGSEntryPointFunctionData_BGSEntryPointFunctionData()
{
    m_pTable = DAT_010462e0;
    return this;
}

}

extern void* DAT_01046320;

struct FUN_005e6510_cls
{
    void* vtbl;
    int m4;
    void BGSEntryPointFunctionData_BGSEntryPointFunctionData();
    FUN_005e6510_cls* InitializeFields_005e6510();
};

// Initializes the object by calling FUN_005e6420, setting the vtable to DAT_01046320, and zeroing m4.
// @fnv 0x005e6510
// src: GUESS 0x005e6510 (confidence: low)
FUN_005e6510_cls* FUN_005e6510_cls::InitializeFields_005e6510()
{
    BGSEntryPointFunctionData_BGSEntryPointFunctionData();
    vtbl = &DAT_01046320;
    m4 = 0;
    return this;
}

extern int DAT_01048bb4, DAT_01048ba0, DAT_01048b88, DAT_01048b68, DAT_01048b54;
struct FUN_00483370
{
    void* table_00;
    unsigned int unknown_04, unknown_08, unknown_0c, unknown_10, unknown_14;
    FUN_00483370();
    ~FUN_00483370();
};
struct FUN_00402d00
{
    void* table_18;
    unsigned int unknown_1c, unknown_20;
    FUN_00402d00();
    ~FUN_00402d00();
};
struct FUN_00482c50
{
    void* table_24;
    unsigned int unknown_28;
    FUN_00482c50();
};
struct FUN_0048e270
{
    void* table_2c;
    unsigned int unknown_30, unknown_34;
    FUN_0048e270();
    ~FUN_0048e270();
};
struct FUN_0047ff70
{
    void* table_38;
    FUN_0047ff70();
    ~FUN_0047ff70();
};
struct FUN_005f6610 : FUN_00483370, FUN_00402d00, FUN_00482c50, FUN_0048e270, FUN_0047ff70
{
    FUN_005f6610();
    void FUN_004f15a0(int);
    void FUN_005f67c0();
};
// Sets the five table pointers at offsets 0x00, 0x18, 0x24, 0x2c and 0x38 after the base constructors, then calls FUN_004f15a0(7) and FUN_005f67c0().
// @fnv 0x005f6610
FUN_005f6610::FUN_005f6610()
{
    table_00 = &DAT_01048bb4;
    table_18 = &DAT_01048ba0;
    table_24 = &DAT_01048b88;
    table_2c = &DAT_01048b68;
    table_38 = &DAT_01048b54;
    FUN_004f15a0(7);
    FUN_005f67c0();
}

struct FUN_005e07d0
{
    virtual ~FUN_005e07d0();
};
// @fnv 0x005e07d0
FUN_005e07d0::~FUN_005e07d0()
{}

struct FUN_005e9830 : Stub
{
    virtual ~FUN_005e9830();
};
// @fnv 0x005e9830
FUN_005e9830::~FUN_005e9830()
{
    this->ForwardCall_005e9860();
}

struct EquivData_5ecd10
{
    short sValue00;
    short sValue02;
    float fValue04;
    float fValue08;
    float fValue0C;
    float fValue10;
    float fValue14;
    float fValue18;
    float fValue1C;
    float fValue20;
    float fValue24;

    bool IsEqual(const EquivData_5ecd10& other);
};

// Returns true when every member of this EquivData_5ecd10 matches the corresponding member of other.
// @fnv 0x005ecd10
bool EquivData_5ecd10::IsEqual(const EquivData_5ecd10& other)
{
    bool bEqual = false;
    if (sValue00 == other.sValue00 && sValue02 == other.sValue02 && fValue1C == other.fValue1C &&
        fValue20 == other.fValue20 && fValue24 == other.fValue24 && fValue10 == other.fValue10 &&
        fValue14 == other.fValue14 && fValue18 == other.fValue18 && fValue04 == other.fValue04 &&
        fValue08 == other.fValue08 && fValue0C == other.fValue0C)
    {
        bEqual = true;
    }
    return bEqual;
}

// @fnv 0x005ef3b0
template <>
BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::~BSSimpleArray()
{
    Clear(true);
}

// @fnv 0x005efd40
template <>
void BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>::_InitialSetup(
    unsigned int requested, unsigned int savedSize)
{
    pBuffer = 0;
    iSize = 0;
    SimpleArrayStorage = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        pBuffer = _Allocate(requested);
        SimpleArrayStorage = requested;
    }
    if (savedSize > 0)
    {
        InitializeItems(pBuffer, savedSize);
        iSize = savedSize;
    }
}

// Returns true if other is not a TESSound, any compared field differs, or FUN_00485270 reports a difference; otherwise false.
// @fnv 0x005e2d90
bool SoundRecordOperations::Compare(TESForm* other)
{
    TESSound* sound = dynamic_cast<TESSound*>(other);
    if (!sound)
        return true;
    if (sound->data.frequencyVariance != reinterpret_cast<TESSound*>(this)->data.frequencyVariance)
        return true;
    for (int index = 0; index < 5; index++)
    {
        if (sound->data.attenuationCurve[index] != reinterpret_cast<TESSound*>(this)->data.attenuationCurve[index])
            return true;
    }
    if (sound->data.soundFlags != reinterpret_cast<TESSound*>(this)->data.soundFlags || sound->data.maxAttenuation != reinterpret_cast<TESSound*>(this)->data.maxAttenuation ||
        sound->data.minAttenuation != reinterpret_cast<TESSound*>(this)->data.minAttenuation || sound->data.frequencyAdjustment != reinterpret_cast<TESSound*>(this)->data.frequencyAdjustment ||
        sound->data.staticAttenuation != reinterpret_cast<TESSound*>(this)->data.staticAttenuation || sound->data.stopTime != reinterpret_cast<TESSound*>(this)->data.stopTime ||
        sound->data.reverbAttenuation != reinterpret_cast<TESSound*>(this)->data.reverbAttenuation || sound->data.unk18 != reinterpret_cast<TESSound*>(this)->data.unk18 || sound->data.unk1c != reinterpret_cast<TESSound*>(this)->data.unk1c ||
        sound->data.unk20 != reinterpret_cast<TESSound*>(this)->data.unk20)
        return true;
    if (CompareBase(sound))
        return true;
    return false;
}

void* __cdecl operator new(unsigned int);

struct FUN_005e63f0 : s5e63f0::Derived
{
    FUN_005e63f0();
};
struct FUN_005e64b0 : s5e63f0::Base
{
    float value04;
    float value08;
    FUN_005e64b0();
};
struct FUN_005e6510 : FUN_005e6510_cls
{
    FUN_005e6510();
};
struct FUN_005e6540 : s5e63f0::Base
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    FUN_005e6540();
};

// Allocates and returns a new variant object of the type indicated by n, or null for an unknown type.
// @fnv 0x005e6280
// src: XBOX_PDB 0x005e6280
void* __cdecl BGSEntryPointFunctionData_CreateFunctionDataOfType(int aiType)
{
    switch (aiType)
    {
    case 1:
        return new FUN_005e63f0;
    case 2:
        return new FUN_005e64b0;
    case 3:
        return new FUN_005e6510;
    case 4:
        return new FUN_005e6540;
    default:
        return 0;
    }
}

class AnimIdle;

// Allocates an array of NiPointer<AnimIdle> of the given count and returns it as a char pointer.
// @fnv 0x005e0ba0
// src: XBOX_PDB 0x005e0ba0
char** NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(unsigned int count)
{
    return reinterpret_cast<char**>(new NiPointer<AnimIdle>[count]);
}

void* __cdecl memset(void*, int, unsigned int);

struct SaveManager
{
    void __thiscall ReadTypedData(void*, unsigned int);
};
struct FullNameEx
{
    void* vtable;
    int unk04;
    int unk08;
    void SetFullName(const char*);
};
extern SaveManager* DAT_011de45c;

struct ClassDataLoad5F
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

struct ClassLoad5F : TESForm
{
    FullNameEx fullName;
    unsigned int unk24;
    unsigned int unk28;
    FullNameEx alternateName;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    ClassDataLoad5F classData;
    void TESClass_LoadGameTES();
};

// Reads classData, fullName and alternateName from the save stream via SaveManager::ReadTypedData, using a length byte to gate each name read.
// @fnv 0x005f7050
// src: COMMUNITY 0x005f7050
void ClassLoad5F::TESClass_LoadGameTES()
{
    DAT_011de45c->ReadTypedData(&classData, 0x1c);

    unsigned char present;
    DAT_011de45c->ReadTypedData(&present, 1);
    if (present)
    {
        char szFullName[260];
        memset(szFullName, 0, 260);
        DAT_011de45c->ReadTypedData(szFullName, present);
        fullName.SetFullName(szFullName);
    }

    DAT_011de45c->ReadTypedData(&present, 1);
    if (present)
    {
        char szAlternateName[260];
        memset(szAlternateName, 0, 260);
        DAT_011de45c->ReadTypedData(szAlternateName, present);
        alternateName.SetFullName(szAlternateName);
    }
}

