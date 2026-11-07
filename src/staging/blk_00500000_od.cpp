
// src/staging/blk_00500000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <stddef.h>
#include "../../include/Actor.h"
#include "../../include/BGSImpactData.h"
#include "../../include/BGSTerrainManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint4.h"
#include "../../include/PathingRequest.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectMISC.h"
#include "../../include/TESKey.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/GO.h"
#include "../../include/NiUpdateData.h"
#include "../../include/TESForm.h"
#include "../../include/TESObject.h"
#include "../../include/Setting.h"

struct FUN_00505c20_class
{
    unsigned char GetByteAtOffset9A();
};

// @fnv 0x00505c20
unsigned char FUN_00505c20_class::GetByteAtOffset9A()
{
    return ((unsigned char*)this)[0x9a];
}

struct FUN_00507550_Class
{
    void ParticleShaderProperty_SetTexture0x118(void* p);
};
// @fnv 0x00507550
// src: COMMUNITY 0x00507550
void FUN_00507550_Class::ParticleShaderProperty_SetTexture0x118(void* p)
{
    *(GO*)((char*)this + 0x118) = p;
}

struct FUN_00507570_Class
{
    void ParticleShaderProperty_SetLifetimeVar(float value);
};

// @fnv 0x00507570
// src: COMMUNITY 0x00507570
void FUN_00507570_Class::ParticleShaderProperty_SetLifetimeVar(float value)
{
    *(float*)((char*)this + 0x80) = value;
}


// @fnv 0x00507610
// src: XBOX_PDB 0x00507610
void PathingRequest::PathingRequestClosePoint_SetMinDistance(float value)
{
    *(float*)((char*)this + 0xb0) = value;
}

struct FUN_005076c0Class
{
    void __thiscall PathingRequestCoveredMove_SetAttackerHealth(float value);
};

// @fnv 0x005076c0
// src: XBOX_PDB 0x005076c0
void __thiscall FUN_005076c0Class::PathingRequestCoveredMove_SetAttackerHealth(float value)
{
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xC0) = value;
}

struct FUN_005076e0_Class
{
    void SetFieldAtOffsetF4_005076e0(float value);
};

// @fnv 0x005076e0
// src: GUESS 0x005076e0 (confidence: low)
void FUN_005076e0_Class::SetFieldAtOffsetF4_005076e0(float value)
{
    *(float*)((char*)this + 0xf4) = value;
}

struct FUN_00507720_Class
{
    void __thiscall SetFieldAtOffset100_00507720(float value);
};
// @fnv 0x00507720
// src: GUESS 0x00507720 (confidence: low)
void __thiscall FUN_00507720_Class::SetFieldAtOffset100_00507720(float value)
{
    *(float*)((char*)this + 0x100) = value;
}

struct FUN_00507740_Class
{
    void ParticleShaderProperty_SetBlendOp(int value);
};

// @fnv 0x00507740
// src: COMMUNITY 0x00507740
void FUN_00507740_Class::ParticleShaderProperty_SetBlendOp(int value)
{
    *(int*)((char*)this + 0x110) = value;
}

struct FUN_00507760_Class
{
    void ParticleShaderProperty_SetZTestFunc(int value);
};

// @fnv 0x00507760
// src: COMMUNITY 0x00507760
void FUN_00507760_Class::ParticleShaderProperty_SetZTestFunc(int value)
{
    *(int*)((char*)this + 0x114) = value;
}

struct FUN_00507780
{
    void SetBoltsRadiusStrength(float value);
};

// @fnv 0x00507780
void FUN_00507780::SetBoltsRadiusStrength(float afStrength)
{
    *(float*)((char*)this + 0x134) = afStrength;
}

struct FUN_005077a0_Class
{
    void BoltShaderProperty_SetSegmentVariance(float value);
};

// @fnv 0x005077a0
// src: XBOX_PDB 0x005077a0
void FUN_005077a0_Class::BoltShaderProperty_SetSegmentVariance(float value)
{
    *(float*)((char*)this + 0x148) = value;
}

struct Flt
{
    operator unsigned int();
};

struct FUN_00507d80_Class
{
    unsigned int FOPipboyManager_Get3rdPersonPipboyRoot();
};

// @fnv 0x00507d80
// src: XBOX_PDB 0x00507d80
unsigned int FUN_00507d80_Class::FOPipboyManager_Get3rdPersonPipboyRoot()
{
    return *(Flt*)((char*)this + 0xdc);
}

struct FUN_00508050_Class
{
    float GetFieldAtOffset44();
};

// @fnv 0x00508050
// src: GUESS 0x00508050 (confidence: low)
float FUN_00508050_Class::GetFieldAtOffset44()
{
    return *(float*)((char*)this + 0x44);
}

struct FUN_00508070_class
{
    float Projectile_GetDistanceMoved();
};

// @fnv 0x00508070
// src: XBOX_PDB 0x00508070
float FUN_00508070_class::Projectile_GetDistanceMoved()
{
    return *(float*)((char*)this + 0x110);
}

extern "C" void __cdecl _ref_006815c0();

struct FUN_00509890_class
{
    void __thiscall _ref_006815c0();
    void* __thiscall UpdateState_00509890(bool);
};

// Calls _ref_006815c0, zeroes the short at offset 0xc, stores flag at offset 0xe, and returns this.
// @fnv 0x00509890
// src: GUESS 0x00509890 (confidence: low)
void* __thiscall FUN_00509890_class::UpdateState_00509890(bool flag)
{
    _ref_006815c0();
    *reinterpret_cast<short*>(reinterpret_cast<char*>(this) + 0xc) = 0;
    *reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0xe) = flag;
    return this;
}

struct FUN_0050d1d0_class
{
    bool IsFlag8Set() const;
};

// @fnv 0x0050d1d0
bool FUN_0050d1d0_class::IsFlag8Set() const
{
    return (*(const int*)((const char*)this + 0xa8) & 8) ? true : false;
}

struct FUN_0050d1f0_Class
{
    bool __thiscall TESObjectLIGH_GetFlickerSlow() const;
};

// @fnv 0x0050d1f0
// src: COMMUNITY 0x0050d1f0
bool __thiscall FUN_0050d1f0_Class::TESObjectLIGH_GetFlickerSlow() const
{
    return (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xa8) & 0x40) ? true : false;
}

struct FUN_0050d210_Class
{
    bool IsFlag80Set() const;
};

// @fnv 0x0050d210
bool FUN_0050d210_Class::IsFlag80Set() const
{
    return (*(const int*)((const char*)this + 0xa8) & 0x80) ? true : false;
}

struct FUN_0050d230_class
{
    bool TESObjectLIGH_GetPulseSlow() const;
};

// @fnv 0x0050d230
// src: COMMUNITY 0x0050d230
bool FUN_0050d230_class::TESObjectLIGH_GetPulseSlow() const
{
    return (*(const unsigned int*)((char*)this + 0xa8) & 0x100) ? true : false;
}

struct FUN_00510110_class
{
    void ProcessEntries_005102e0();
    void ForwardCall_00510110();
};
// @fnv 0x00510110
// src: GUESS 0x00510110 (confidence: low)
void FUN_00510110_class::ForwardCall_00510110()
{
    ProcessEntries_005102e0();
}

struct FUN_00510360_Class
{
    void* TESObjectList_lnk_GetNext(TESObject* p);
};
// @fnv 0x00510360
// src: COMMUNITY 0x00510360
void* FUN_00510360_Class::TESObjectList_lnk_GetNext(TESObject* apObject)
{
    return apObject->GetNext();
}

struct FUN_00510380_Class
{
    unsigned int __thiscall GetTerrainMinLevel(BGSTerrainManager* a);
};
// @fnv 0x00510380
unsigned int __thiscall FUN_00510380_Class::GetTerrainMinLevel(BGSTerrainManager* apTerrainManager)
{
    return apTerrainManager->GetMinLevel();
}

extern "C" int __cdecl _BSStringLength(const char*);

struct FUN_005103a0_class
{
    void __thiscall FindSubstring(const char* a, const char* b, int c);
    void __thiscall ProcessState_005103a0(const char* a, const char* b);
};

// @fnv 0x005103a0
// src: GUESS 0x005103a0 (confidence: low)
void __thiscall FUN_005103a0_class::ProcessState_005103a0(const char* a, const char* b)
{
    FindSubstring(a, b, _BSStringLength(a));
}

extern "C" int __cdecl _memcmp(const void* s1, const void* s2, unsigned int n);

// @fnv 0x005104b0
// src: COMMUNITY 0x005104b0
void __cdecl std_char_traits_char_compare(const void* apFirst, const void* apSecond, unsigned int auiLength)
{
    _memcmp(apFirst, apSecond, auiLength);
}

extern "C" void* __cdecl FUN_00eca2e0(void* p, int c, size_t n);

// @fnv 0x005104d0
// src: COMMUNITY 0x005104d0
void __cdecl std_char_traits_char_assign_005104d0(void* p, size_t n, char* pcValue)
{
    FUN_00eca2e0(p, *pcValue, n);
}

// Exe 0x005113d0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BlkOffset08View
{
    unsigned int GetFlags();
    unsigned int HasFlag10000000();
};

// @fnv 0x005113d0
unsigned int BlkOffset08View::HasFlag10000000()
{
    return (GetFlags() & 0x10000000) != 0;
}

struct FUN_00519020_Class
{
    void SetField688(int value);
};

// @fnv 0x00519020
void FUN_00519020_Class::SetField688(int value)
{
    *(int*)((char*)this + 0x688) = value;
}



// @fnv 0x005194d0
// src: XBOX_PDB 0x005194d0
bool TESObjectDOOR::IsRandomDoor()
{
    if (!m_kRandomTeleportTargets.IsEmpty())
        return true;
    return false;
}

extern "C" void* DAT_0102b3d0;

struct FUN_00519b20_cls
{
    void* m_p;
    void __thiscall ConstructArray(void* arg);
    void* __thiscall InitializeFields_00519b20(void* arg);
};

// Calls ConstructArray with arg, sets m_p to the address of DAT_0102b3d0, and returns this.
// @fnv 0x00519b20
// src: GUESS 0x00519b20 (confidence: low)
void* __thiscall FUN_00519b20_cls::InitializeFields_00519b20(void* arg)
{
    ConstructArray(arg);
    m_p = &DAT_0102b3d0;
    return this;
}

namespace fnv_0051cee0 {
extern "C" void* __cdecl BSTreeManager_GetInstance(int);
struct Flt
{
    operator unsigned int();
};
// @fnv 0x0051cee0
unsigned int __cdecl GetFloatAsUInt()
{
    return ((Flt*)((char*)BSTreeManager_GetInstance(1) + 0xc))->operator unsigned int();
}
}  // namespace fnv_0051cee0

extern "C" unsigned int __cdecl UpdateFields_00c5faa0(void*);

struct Unk_00a5e930
{
    unsigned int __thiscall UpdateFields_00c5faa0();
};

struct FUN_0051cfe0_Class
{
    unsigned int __thiscall ForwardCall_0051cfe0();
};

// @fnv 0x0051cfe0
// src: GUESS 0x0051cfe0 (confidence: low)
unsigned int __thiscall FUN_0051cfe0_Class::ForwardCall_0051cfe0()
{
    return ((Unk_00a5e930*)this)->UpdateFields_00c5faa0();
}

struct FUN_0051f4d0_class
{
    unsigned int GetField1CC();
};

// @fnv 0x0051f4d0
unsigned int FUN_0051f4d0_class::GetField1CC()
{
    return *(unsigned int*)((char*)this + 0x1cc);
}

struct FUN_0051f4f0_Class
{
    void UpdateState_0051f4f0(int value);
};

// @fnv 0x0051f4f0
// src: GUESS 0x0051f4f0 (confidence: low)
void FUN_0051f4f0_Class::UpdateState_0051f4f0(int value)
{
    *(int*)((char*)this + 0x1cc) = value;
}

struct FUN_0051f530_class
{
    void __thiscall TESObjectWEAP_SetVATSEffect(int value);
};

// @fnv 0x0051f530
// src: COMMUNITY 0x0051f530
void __thiscall FUN_0051f530_class::TESObjectWEAP_SetVATSEffect(int value)
{
    *(int*)((char*)this + 0x370) = value;
}

extern "C" void* __cdecl _NiFreeAlias(void*);

extern void* DAT_0102b3f0;

struct FUN_00519c50_class
{
    void* pVft;
    int _0x4;
    void* _0x8;
    void __thiscall NiTPointerMap_RemoveAll();
    void __thiscall ReleaseStorage_00519c50();
};

// @fnv 0x00519c50
// src: GUESS 0x00519c50 (confidence: low)
void __thiscall FUN_00519c50_class::ReleaseStorage_00519c50()
{
    pVft = &DAT_0102b3f0;
    NiTPointerMap_RemoveAll();
    _NiFreeAlias(_0x8);
}

extern "C" void __cdecl _Deallocate(void*);
void __cdecl FUN_005010f0();
struct FUN_005010c0_class
{
    void __thiscall FUN_005010f0();
    void* __thiscall FUN_005010c0(unsigned int flags);
};
// Calls FUN_005010f0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x005010c0
void* __thiscall FUN_005010c0_class::FUN_005010c0(unsigned int flags)
{
    FUN_005010f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00507660_class
{
    void ParticleShaderProperty_SetColor2(NiPoint4 p);
};

// Stores the given NiPoint4 into the object at offset 0xd4.
// @fnv 0x00507660
// src: COMMUNITY 0x00507660
void FUN_00507660_class::ParticleShaderProperty_SetColor2(NiPoint4 aPoint)
{
    *(NiPoint4*)((char*)this + 0xd4) = aPoint;
}

void __cdecl Deallocate(void*);
struct FUN_00519b50_class
{
    void __thiscall FUN_00519bf0();
    void* __thiscall FUN_00519b50(unsigned int flags);
};
// Calls FUN_00519bf0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00519b50
void* __thiscall FUN_00519b50_class::FUN_00519b50(unsigned int flags)
{
    FUN_00519bf0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00519c50_class;
void __cdecl _Deallocate(void* p);

struct FUN_00519c80_class
{
    void* __thiscall FUN_00519c80(unsigned int flags);
};

// Calls FUN_00519c50 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00519c80
void* __thiscall FUN_00519c80_class::FUN_00519c80(unsigned int flags)
{
    ((FUN_00519c50_class*)this)->ReleaseStorage_00519c50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00501cd0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    unsigned int m_10;
    void* m_14;
    void* __thiscall DoorLock_DoorLock();
};
// @fnv 0x00501cd0
// src: XBOX_PDB 0x00501cd0
void* __thiscall FUN_00501cd0_class::DoorLock_DoorLock()
{
    m_00 = 0;
    m_04 = 0;
    m_0c = 0;
    m_10 = 0xffffffff;
    m_14 = 0;
    m_08 = 0;
    return this;
}

TESForm* __cdecl GetFormByID(unsigned int id);

// @fnv 0x00505000
// src: XBOX_PDB 0x00505000
TESForm* __cdecl TESCombatStyle_GetDefaultCombatStyle()
{
    return GetFormByID(0x3d);
}

struct FUN_00507590_Data
{
    float a;
    float b;
    float c;
};
struct FUN_00507590_Class
{
    void __thiscall SetData(FUN_00507590_Data v);
};
// Copies the passed three-float data value into the object at offset 0x90.
// @fnv 0x00507590
void __thiscall FUN_00507590_Class::SetData(FUN_00507590_Data aData)
{
    *(FUN_00507590_Data*)((char*)this + 0x90) = aData;
}

struct Vec12_5075c0
{
    int x;
    int y;
    int z;
};
struct S5075c0
{
    void __thiscall ParticleShaderProperty_SetAcceleration(Vec12_5075c0 v);
};
// Stores the three-int vector v into the object at offset 0x9c.
// @fnv 0x005075c0
// src: COMMUNITY 0x005075c0
void __thiscall S5075c0::ParticleShaderProperty_SetAcceleration(Vec12_5075c0 v)
{
    *(Vec12_5075c0*)((char*)this + 0x9c) = v;
}

struct FUN_00507630_Cls
{
    unsigned char _pad[0xC4];
    NiPoint4 fld;
    void __thiscall SetPoint(NiPoint4 p);
};
// Stores the passed NiPoint4 into the fld member.
// @fnv 0x00507630
void __thiscall FUN_00507630_Cls::SetPoint(NiPoint4 aPoint)
{
    fld = aPoint;
}

struct FUN_00507690_Class
{
    char _pad[0xe4];
    NiPoint4 m_0xe4;
    void __thiscall ParticleShaderProperty_SetColor3(NiPoint4 v);
};
// Stores the passed NiPoint4 value into the member at offset 0xe4.
// @fnv 0x00507690
// src: COMMUNITY 0x00507690
void __thiscall FUN_00507690_Class::ParticleShaderProperty_SetColor3(NiPoint4 aPoint)
{
    m_0xe4 = aPoint;
}

struct FUN_00508100_shell
{
    float GetEndKeyTime_00508100();
};
struct FUN_00759450_shell
{
    float NiPSysSpawnModifier_GetLifeSpan();
};
struct FUN_005082b0_shell
{
    void UpdateEnvelope(float, float, float, unsigned char, float, float, float, float, float);
};

struct FUN_00508090_shell
{
    float TESCombatStyle_GetWeaponMinRangeMult() const;
    float GetActorRadius();
    float GetEndKeyTime_00508100();
    float NiControllerSequence_GetLastTime();
    float NiPSysSpawnModifier_GetLifeSpan();
    void UpdateEnvelope(float, float, float, unsigned char, float, float, float, float, float);
    void TESEffectShader_AnimateFillEffectAlpha(float a, float b, float c, unsigned char d);
};

// Forwards a, b, c and d to UpdateEnvelope together with the results of FUN_009a9350, GetActorRadius, FUN_00508100, FUN_00508120 and FUN_00759450.
// @fnv 0x00508090
// src: COMMUNITY 0x00508090
void __thiscall FUN_00508090_shell::TESEffectShader_AnimateFillEffectAlpha(float a, float b, float c, unsigned char d)
{
    UpdateEnvelope(a, b, c, d, TESCombatStyle_GetWeaponMinRangeMult(), GetActorRadius(), GetEndKeyTime_00508100(), NiControllerSequence_GetLastTime(), NiPSysSpawnModifier_GetLifeSpan());
}

struct FUN_0050e640_Holder
{
    char _0[4];
    unsigned char _4;
    bool __thiscall MatchesValue(unsigned char v);
};
// Returns true when the holder's byte at offset 4 equals the given value, or false if the holder is null.
// @fnv 0x0050e640
bool __thiscall FUN_0050e640_Holder::MatchesValue(unsigned char v)
{
    return this ? _4 == v : false;
}

float __cdecl NiSqrt_004579e0(float);
// Returns the square root of the sum of squares of the three short components pointed to by p.
// @fnv 0x0050ec80
// src: XBOX_PDB 0x0050ec80
float __fastcall NiNPShortPoint3_Length(short* pComponents)
{
    return NiSqrt_004579e0(
        (float)(*pComponents * *pComponents + pComponents[1] * pComponents[1] + pComponents[2] * pComponents[2]));
}

struct AVH
{
    static int __cdecl GetActorValueForSectionIndex(int, unsigned char);
};
struct FUN_00514fd0_class
{
    int __thiscall TESObjectBOOK_GetTeaches();
};
// @fnv 0x00514fd0
// src: COMMUNITY 0x00514fd0
int __thiscall FUN_00514fd0_class::TESObjectBOOK_GetTeaches()
{
    if (reinterpret_cast<const signed char*>(this)[0xc1] == -1)
        return -1;
    return AVH::GetActorValueForSectionIndex(2, reinterpret_cast<const unsigned char*>(this)[0xc1]);
}

bool __cdecl TESObjectDOOR_CanBeRandomTeleport(int);
struct LH
{
    bool IsInList(int&);
};
struct FUN_00519500_class
{
    bool HasEntry(int a);
};
// Returns true if a is non-zero, passes FUN_00519570, and is contained in the list at this+0x88.
// @fnv 0x00519500
bool FUN_00519500_class::HasEntry(int aiValue)
{
    bool r = false;
    if (aiValue && TESObjectDOOR_CanBeRandomTeleport(aiValue) && ((LH*)((char*)this + 0x88))->IsInList(aiValue))
        r = true;
    return r;
}

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dst, int c, unsigned int n);
struct FUN_00519b20
{
    void* __thiscall ConstructArray(unsigned int n);
};
// Sets the vtable and count, allocates a zeroed array of n 4-byte elements, and returns this.
// @fnv 0x00519b80
void* __thiscall FUN_00519b20::ConstructArray(unsigned int n)
{
    unsigned int size;
    ((void**)this)[0] = &DAT_0102b3f0;
    ((unsigned int*)this)[1] = n;
    ((unsigned int*)this)[3] = 0;
    size = ((unsigned int*)this)[1] * 4;
    ((void**)this)[2] = NiMalloc(size);
    memset(((void**)this)[2], 0, ((unsigned int*)this)[1] * 4);
    return this;
}

struct TESGrassBase
{
    TESGrassBase();
    ~TESGrassBase();
    void SetFormType(int);
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
    unsigned char m_09;
    unsigned char m_0a;
    unsigned char m_0b;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    unsigned char m_10;
    unsigned char m_11;
    unsigned char m_12;
    unsigned char m_13;
    unsigned char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;
    unsigned char m_18;
    unsigned char m_19;
    unsigned char m_1a;
    unsigned char m_1b;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    unsigned char m_1f;
    unsigned char m_20;
    unsigned char m_21;
    unsigned char m_22;
    unsigned char m_23;
    unsigned char m_24;
    unsigned char m_25;
    unsigned char m_26;
    unsigned char m_27;
    unsigned char m_28;
    unsigned char m_29;
    unsigned char m_2a;
    unsigned char m_2b;
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned char m_2e;
    unsigned char m_2f;
};
struct TESGrassModel
{
    TESGrassModel();
    ~TESGrassModel();
    void* vft;
};
struct FUN_00509a10 : TESGrassBase
{
    TESGrassModel m_30;
    FUN_00509a10();
    void ResetFormData();
};
// @fnv 0x00509a10
FUN_00509a10::FUN_00509a10()
{
    ((void**)this)[0] = (void*)0x0102814c;
    ((void**)((char*)this + 0x30))[0] = (void*)0x01028128;
    SetFormType(0x24);
    ResetFormData();
}

// @fnv 0x0050a5a0
TESKey::TESKey()
{
    SetFormType(0x2e);
    SetInitializationState(true);
}

struct TESObjectREFR_Flags
{
    unsigned int GetFlags();
    void SetFlags(unsigned int flags);
    void MarkAsModified(int change);
    void __thiscall SetRefFlag40000000(bool set);
};

// @fnv 0x00511370
void __thiscall TESObjectREFR_Flags::SetRefFlag40000000(bool set)
{
    unsigned int flags = GetFlags();
    if (set)
        flags |= 0x40000000;
    else
        flags &= ~0x40000000;
    SetFlags(flags);
    MarkAsModified(1);
}

// Setting mutators at 0x004ed780 and 0x0050e620 are absent from the shared header; preserve their call ABIs locally.
extern "C" void AssignSettingFloat();
extern "C" void AssignSettingByte();
typedef Setting* (__thiscall *AssignSettingFloatFn)(Setting*, float);
typedef bool (__thiscall *AssignSettingByteFn)(Setting*, unsigned char);

extern unsigned char DAT_011c8fa0;
extern double _DAT_01012060;

extern Setting g_011c8fb0;
extern Setting g_011c8ff0;
extern Setting g_011c9028;
extern Setting g_011c9054;
extern Setting g_011c9060;
extern Setting g_011c906c;
extern Setting g_011c907c;

// @fnv 0x0050e6c0
bool __cdecl InitSettingsDefaults()
{
    DAT_011c8fa0 = 0;

    if (reinterpret_cast<AssignSettingByteFn>(AssignSettingByte)(&g_011c9060, 1))
        DAT_011c8fa0 |= 1;

    if (reinterpret_cast<AssignSettingByteFn>(AssignSettingByte)(&g_011c8ff0, 1))
        DAT_011c8fa0 |= 2;

    if (reinterpret_cast<AssignSettingByteFn>(AssignSettingByte)(&g_011c9028, 1))
        DAT_011c8fa0 |= 4;

    if (!DAT_011c8fa0)
        DAT_011c8fa0 |= 4;

    if (*g_011c9054.Int() != 0 && *g_011c9054.Int() != 1 && *g_011c9054.Int() != 2)
        g_011c9054.ProcessAndReturnValue_0045ce80(1);

    if (*g_011c907c.Int() != 0 && *g_011c907c.Int() != 1 && *g_011c907c.Int() != 2)
        g_011c907c.ProcessAndReturnValue_0045ce80(2);

    if (*g_011c8fb0.Float() == 0.0)
        reinterpret_cast<AssignSettingFloatFn>(AssignSettingFloat)(&g_011c8fb0, 1.0f);

    if (*g_011c906c.Float() == 0.0)
        reinterpret_cast<AssignSettingFloatFn>(AssignSettingFloat)(&g_011c906c, 1.0f);

    return true;
}


struct LockExtraData
{
    void* pVft;
    TESBoundObject* pKey;
    bool IsLocked();
};





extern Actor* g_thePlayer;
extern TESBoundObject* g_pLockpickItem;

struct FUN_00516cd0_class
{
    bool __thiscall CanUseLockedRef(TESObjectREFR* ref, Actor* actor, bool useLockpick);
};

// @fnv 0x00516cd0
bool __thiscall FUN_00516cd0_class::CanUseLockedRef(TESObjectREFR* ref, Actor* actor, bool useLockpick)
{
    int pLock;
    Actor* pActor;
    LockExtraData* iCount;

    if (actor == 0 || !actor->IsActor())
        return false;

    iCount = ref->GetLock();
    if (iCount == 0 || !iCount->IsLocked())
        return true;

    pActor = actor;
    if (actor != g_thePlayer && ref->CanBeUsed(pActor, true))
        return true;

    pLock = 0;
    if (iCount->pKey != 0 && pActor->Actor_HasObjects(iCount->pKey, 0, 1, 0, pLock))
    {
        return true;
    }
    else
    {
        if (useLockpick)
        {
            if (pActor->Actor_HasObjects(g_pLockpickItem, 0, 1, 0, pLock))
                return true;
        }
    }

    return false;
}

int DAT_011c6200;
// @fnv 0x005039e0
// src: COMMUNITY 0x005039e0
int FixedStrings_GetArrowQuiver()
{
    return DAT_011c6200;
}

struct FUN_00505b80_cls
{
    unsigned char DispatchByType(int aType);
    unsigned char FUN_0073cb80();
    unsigned char TESCombatStyle_GetPowerAttackF();
    unsigned char GetByteAtOffset9A();
    unsigned char GetByteAtOffset9B();
    unsigned char FUN_009e8670();
};

// Dispatches on aType (0x5c-0x60) to one of five member functions and returns its result, or 0 for other values.
// @fnv 0x00505b80
unsigned char FUN_00505b80_cls::DispatchByType(int aType)
{
    switch (aType)
    {
    case 0x5c:
        return FUN_0073cb80();
    case 0x5d:
        return TESCombatStyle_GetPowerAttackF();
    case 0x5e:
        return GetByteAtOffset9A();
    case 0x5f:
        return GetByteAtOffset9B();
    case 0x60:
        return FUN_009e8670();
    }
    return 0;
}

class ThisBase_c40
{
  public:
    virtual ~ThisBase_c40();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;

    ThisBase_c40();
};

class ThisMember18_c40
{
  public:
    ThisMember18_c40();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    int m_88;
    int m_8C;
    int m_90;
    int m_94;
    int m_98;
    int m_9C;
    int m_A0;
    int m_A4;
    int m_A8;
    int m_AC;
    int m_B0;
    int m_B4;
    int m_B8;
    int m_BC;
    int m_C0;
    int m_C4;
    int m_C8;
    int m_CC;
    int m_D0;
    int m_D4;
    int m_D8;
    int m_DC;
    int m_E0;
    int m_E4;
    int m_E8;
    int m_EC;
    int m_F0;
    int m_F4;
    int m_F8;
    int m_FC;
    int m_100;
    int m_104;
    int m_108;
    int m_10C;
    int m_110;
    int m_114;
    int m_118;
    int m_11C;
    int m_120;
    int m_124;
    int m_128;
    int m_12C;
    int m_130;
    int m_134;
};

class ThisMemberD_c40
{
  public:
    int m_00;
    int m_04;
    int m_08;

    ThisMemberD_c40();
    ~ThisMemberD_c40();
};

class FUN_00505c40 : public ThisBase_c40
{
  public:
    ThisMember18_c40 m_18;
    ThisMemberD_c40 m_14c;
    ThisMemberD_c40 m_158;
    ThisMemberD_c40 m_164;

    FUN_00505c40();
    virtual ~FUN_00505c40();
    virtual void unk00();
    void CallA_c40(int a1);
    void CallB_c40();
};

// Initializes the object by calling CallA_c40 with 0x4f and then CallB_c40.
// @fnv 0x00505c40
FUN_00505c40::FUN_00505c40()
{
    CallA_c40(0x4f);
    CallB_c40();
}

class FUN_00507da0_cls
{
  public:
    int unk00;
    float NiAVObject_GetWorldScale();
    float Explosion_GetRadius(float value);
    float BGSProjectile_GetMuzzleFlashDuration(float value);
    float GetField90Float(float value);
    float FUN_0051b8e0(float value);
    void UpdateEnvelope(float a, float b, float c, unsigned char flag, float value);
    void TESEffectShader_BirthParticles(float a, float b, float c, unsigned char flag);
};

// Computes a value by chaining FUN_008d01e0, FUN_00644930, FUN_00507e10, GetField90Float and FUN_0051b8e0, then passes it with a, b, c and flag to UpdateEnvelope.
// @fnv 0x00507da0
// src: COMMUNITY 0x00507da0
void FUN_00507da0_cls::TESEffectShader_BirthParticles(float a, float b, float c, unsigned char flag)
{
    UpdateEnvelope(a, b, c, flag, FUN_0051b8e0(GetField90Float(BGSProjectile_GetMuzzleFlashDuration(Explosion_GetRadius(NiAVObject_GetWorldScale())))));
}

extern "C" double gModifierZero;
extern float runtimeInitializationFloat2255;

float sin_004e44b0(float fValue);

class B5081D0Actor
{
  public:
    float GetFloatAt64();
    float GetFloatAtOffset68() const;

    float TESEffectShader_CalculateEdgeAlphaPulse(float fTime);
};

// @fnv 0x005081d0
// src: COMMUNITY 0x005081d0
float B5081D0Actor::TESEffectShader_CalculateEdgeAlphaPulse(float fTime)
{
    if (GetFloatAt64() > gModifierZero)
        return GetFloatAt64() * sin_004e44b0(fTime * runtimeInitializationFloat2255 * GetFloatAtOffset68());
    else
        return 1.0f;
}

extern "C" double gModifierZero;
extern float runtimeInitializationFloat2255;

float C508240Curve(float fValue);

class C508240Ref
{
  public:
    float GetScale();
    float GetHeight();

    float TESEffectShader_CalculateFillAlphaPulse(float fDistance);
};

// @fnv 0x00508240
// src: COMMUNITY 0x00508240
float C508240Ref::TESEffectShader_CalculateFillAlphaPulse(float afValue)
{
    if (GetScale() > gModifierZero)
        return GetScale() * C508240Curve(afValue * runtimeInitializationFloat2255 * GetHeight());
    else
        return 1.0f;
}

namespace std {
float abs(float);
}
float BSMAX_00404010(float, float);
float BSMIN(float, float);
unsigned int FUN_00ba52d0();
struct Envelope
{
    float UpdateEnvelope(float current, float rate, float elapsed, unsigned char releasing, float attack, float decay,
                         float hold, float maximum, float minimum);
};
// @fnv 0x005082b0
float Envelope::UpdateEnvelope(float current, float rate, float elapsed, unsigned char releasing, float attack,
                               float decay, float hold, float maximum, float minimum)
{
    if (releasing)
    {
        if (elapsed < attack + hold)
            releasing = 0;
        else
        {
            float scale = 0.0f;
            if (decay > 0.0 && maximum - minimum != 0.0)
                scale = (1.0 / decay) * std::abs(maximum - minimum);
            if (scale < 0.33f)
                scale = 0.33f;
            scale = FUN_00ba52d0() * rate * scale;
            current = BSMAX_00404010(0.0f, current - scale);
        }
    }
    if (!releasing)
    {
        if (elapsed < attack)
            current = BSMIN(maximum, current + rate / attack * maximum);
        else if (hold > elapsed - attack)
            current = maximum;
        else if (decay > elapsed - attack - hold)
            current = BSMAX_00404010(minimum, current - rate / decay * std::abs(maximum - minimum));
        else
            current = minimum;
    }
    return current;
}

extern char DAT_01026bd0;
extern char DAT_01026a4c;
extern char DAT_01026a34;
extern char DAT_01026a10;
extern char DAT_010269fc;
extern char DAT_010269e8;
extern char DAT_010269d8;

class ActorStateBase
{
  public:
    ActorStateBase();
    void* m_00;
    int m_04;
    int m_08;
};

class ActorStateSub
{
  public:
    ActorStateSub();
    ~ActorStateSub();
    void FUN_004f15a0(int a);
    void FUN_00484ab0(int a);
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
};

class FUN_00508450_cls : public ActorStateBase
{
  public:
    FUN_00508450_cls();
    ActorStateSub m_0c;
    void* m_3c;
    int m_40;
    int m_44;
    void* m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    void* m_68;
    int m_6c;
    int m_70;
    void* m_74;
    int m_78;
    void* m_7c;
};

// @fnv 0x00508450
FUN_00508450_cls::FUN_00508450_cls()
{
    this->m_00 = (void*)&DAT_01026bd0;
    this->m_0c.m_00 = (void*)&DAT_01026a4c;
    this->m_3c = (void*)&DAT_01026a34;
    this->m_48 = (void*)&DAT_01026a10;
    this->m_68 = (void*)&DAT_010269fc;
    this->m_74 = (void*)&DAT_010269e8;
    this->m_7c = (void*)&DAT_010269d8;
    this->m_0c.FUN_004f15a0(0x26);
    this->m_0c.FUN_00484ab0(1);
}

struct FUN_0050a850_Primary
{
    virtual ~FUN_0050a850_Primary();
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
};

struct FUN_0050a850_Secondary30
{
    virtual ~FUN_0050a850_Secondary30();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_0050a850_Secondary4c
{
    virtual ~FUN_0050a850_Secondary4c();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FUN_0050a850 : FUN_0050a850_Primary, FUN_0050a850_Secondary30, FUN_0050a850_Secondary4c
{
    virtual ~FUN_0050a850();
};

// @fnv 0x0050a850
FUN_0050a850::~FUN_0050a850()
{}

class B0B8F0Form
{
  public:
    B0B8F0Form();
    virtual ~B0B8F0Form();

    void SetFormType(int eType);
    void SetFlag(int iValue);

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
};

class B0B8F0Component
{
  public:
    B0B8F0Component();
    virtual ~B0B8F0Component();
};

class FUN_0050b8f0 : public B0B8F0Form, public B0B8F0Component
{
  public:
    FUN_0050b8f0();
    virtual ~FUN_0050b8f0();
};

// @fnv 0x0050b8f0
FUN_0050b8f0::FUN_0050b8f0()
{
    SetFormType(0x4c);
    SetFlag(1);
}

class Obj50DDB0
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
    unsigned int m_uiValue1;

    void TESObjectLIGH_SetDynamic(bool bSet);
};

// @fnv 0x0050ddb0
// src: COMMUNITY 0x0050ddb0
void Obj50DDB0::TESObjectLIGH_SetDynamic(bool bSet)
{
    bSet ? (m_uiValue1 |= 1) : (m_uiValue1 &= ~1);
}

extern int DAT_011c620c;

// @fnv 0x0050de10
// src: COMMUNITY 0x0050de10
int __cdecl FixedStrings_GetAttachLight()
{
    return DAT_011c620c;
}

struct S_0050de20_Obj
{
    int unk00;
    int unk04;
    void IncRefCount();
    void DecRefCount();
};
struct S_0050de20_A
{
    NiPointer<S_0050de20_Obj> unk00;
    int unk04;
};
struct S_0050de20_Class
{
    bool __thiscall TESObjectLIGH_Update_(NiPointer<S_0050de20_Obj> p, int* q, int b);
    bool __thiscall TESObjectLIGH_Update(S_0050de20_A* a, int b);
};
// Forwards the object pointer and the int field of the given entry to FUN_0050de60 along with b and returns its result.
// @fnv 0x0050de20
// src: COMMUNITY 0x0050de20
bool __thiscall S_0050de20_Class::TESObjectLIGH_Update(S_0050de20_A* a, int b)
{
    return TESObjectLIGH_Update_(a->unk00, &a->unk04, b);
}

extern int DAT_011f81dc;

// @fnv 0x0050f6e0
// src: COMMUNITY 0x0050f6e0
int FileFinder_GetSingleton()
{
    return DAT_011f81dc;
}

struct S_5102e0_Node
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual ~S_5102e0_Node();
    int unk04f;
    int unk08f;
    int unk0cf;
    int unk10f;
    int unk14f;
    int unk18f;
    S_5102e0_Node* FUN_00441110();
};
struct S_5102e0_List
{
    int unk00;
    int unk04;
    S_5102e0_Node* head;
    void ProcessEntries_005102e0();
};
// @fnv 0x005102e0
// src: GUESS 0x005102e0 (confidence: low)
void S_5102e0_List::ProcessEntries_005102e0()
{
    while (head)
    {
        S_5102e0_Node* next = head->FUN_00441110();
        delete head;
        head = next;
    }
    unk00 = 0;
    unk04 = 0;
    head = 0;
}

extern unsigned int g_010173f0;

extern "C" unsigned int __cdecl FindNextMatch(void* p, unsigned int n, char* c);
extern "C" unsigned int __cdecl CompareRun(unsigned int found, char* a1, unsigned int count);

struct FUN_005103d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
    unsigned int GetBase();
    unsigned int FindSubstring(char* a1, unsigned int start, unsigned int count);
};

// Searches the buffer from start for a match of a1 of length count, returning its offset from the base or g_010173f0 if not found.
// @fnv 0x005103d0
unsigned int FUN_005103d0_cls::FindSubstring(char* pPattern, unsigned int start, unsigned int count)
{
    unsigned int remaining;
    unsigned int pos;
    unsigned int found4;

    if (count == 0 && start <= m_14)
    {
        return start;
    }
    if (start < m_14)
    {
        remaining = m_14 - start;
        if (count <= remaining)
        {
            remaining = remaining - (count - 1);
            pos = GetBase() + start;
            for (; (found4 = FindNextMatch((void*)pos, remaining, pPattern)) != 0;
                 remaining -= found4 - pos + 1, pos = found4 + 1)
            {
                if (CompareRun(found4, pPattern, count) == 0)
                {
                    return found4 - GetBase();
                }
            }
        }
    }
    return g_010173f0;
}

struct NiTPointerMapBase
{
    virtual ~NiTPointerMapBase();
};

struct FUN_00519bf0 : NiTPointerMapBase
{
    virtual ~FUN_00519bf0();
};

// Destructor that calls NiTPointerMap_RemoveAll on this object to clear the map.
// @fnv 0x00519bf0
FUN_00519bf0::~FUN_00519bf0()
{
    ((FUN_00519c50_class*)this)->NiTPointerMap_RemoveAll();
}

// FUN_0051cf00 (132 bytes) - the constructor of NiBillboardNode.
//
//   0051cf00  55                    push ebp
//   0051cf01  8bec                  mov ebp, esp
//   0051cf03  6aff                  push -1
//   0051cf05  68e84bef00            push __ehhandler
//   0051cf0a  64a100000000          mov eax, dword ptr fs:[0]
//   0051cf10  50                    push eax
//   0051cf11  51                    push ecx            <- this home [ebp-0x10]
//   0051cf12  a1bc161c01            mov eax, __security_cookie
//   0051cf17  33c5                  xor eax, ebp
//   0051cf19  50                    push eax            <- cookie [ebp-0x14]
//   0051cf1a  8d45f4                lea eax, [ebp-0xc]
//   0051cf1d  64a300000000          mov dword ptr fs:[0], eax
//   0051cf23  894df0                mov dword ptr [ebp-0x10], ecx
//   0051cf26  6a00                  push 0
//   0051cf28  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf2b  e8801d5400            call 0xa5ecb0        <- base ctor
//   0051cf30  c745fc00000000        mov dword ptr [ebp-4], 0      <- EH state 0
//   0051cf37  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf3a  c70044bf0201          mov dword ptr [eax], 0x102bf44  <- own vftable
//   0051cf40  33c9                  xor ecx, ecx
//   0051cf42  8b55f0                mov edx, dword ptr [ebp-0x10]
//   0051cf45  66898aac000000        mov word ptr [edx+0xac], cx
//   0051cf4c  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf4f  d9ee                  fldz
//   0051cf51  d998b0000000          fstp dword ptr [eax+0xb0]
//   0051cf57  6a01                  push 1
//   0051cf59  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf5c  e89f000000            call 0x51d000
//   0051cf61  6a01                  push 1
//   0051cf63  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf66  e8f5000000            call 0x51d060
//   0051cf6b  c745fcffffffff        mov dword ptr [ebp-4], 0xffffffff
//   0051cf72  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf75  8b4df4                mov ecx, dword ptr [ebp-0xc]
//   0051cf78  64890d00000000        mov dword ptr fs:[0], ecx
//   0051cf7f  59                    pop ecx
//   0051cf80  8be5                  mov esp, ebp
//   0051cf82  5d                    pop ebp
//   0051cf83  c3                    ret
//
// The module is an unoptimised (/Od) build, and this is a constructor of a
// POLYMORPHIC class whose vftable lives at 0x102bf44
// (tools/pe.py rtti 0x102bf44 -> .?AVNiBillboardNode@@).  Three facts drive
// the shape:
//
//  * the class has a base class with a NON-TRIVIAL destructor, so the
//    constructor gets an exception-handling frame: the "push -1 / push
//    __ehhandler / mov eax,fs:[0]" prologue, the state word at [ebp-4] (0
//    right after the base ctor call, -1 at scope exit) and, because MSVC
//    2008 arms the /GS cookie for every function that carries an EH frame,
//    the "mov eax,__security_cookie / xor eax,ebp / push eax" trio;
//  * a constructor returns `this` in EAX, so the vptr store goes THROUGH
//    EAX ("mov eax,[ebp-0x10] / mov dword ptr [eax],<vftable>"); under /Od
//    the `this` home is reloaded from the frame for every use;
//  * /Od re-reads `this` from the frame for every use and materialises a
//    call argument into a scratch register, so the base ctor call and the
//    two member calls are all "push arg / mov ecx,[ebp-0x10] / call".
//
// The base class is a stand-in: only its SIZE matters (the derived members
// have to land on +0xac and +0xb0) and its constructor/destructor are
// declared but never defined, so the call target and the cleanup funclet
// are bound by the checker from the original's own bytes.

struct NiBillboardBase
{
    virtual void vfunc_base();
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    NiBillboardBase(int flags);
    ~NiBillboardBase();
};

struct FUN_0051cf00_NiBillboardNode : public NiBillboardBase
{
    unsigned short m_0ac;
    float m_0b0;
    virtual void vfunc_node();
    void SetMode_0051d000(int flags);
    void NiBillboardNode_SetUpdateControllers(int flags);
    FUN_0051cf00_NiBillboardNode();
    ~FUN_0051cf00_NiBillboardNode();
};

// Initializes the billboard node: clears m_0ac and m_0b0, then calls FUN_0051d000(1) and FUN_0051d060(1).
// @fnv 0x0051cf00
FUN_0051cf00_NiBillboardNode::FUN_0051cf00_NiBillboardNode() : NiBillboardBase(0)
{
    m_0ac = 0;
    m_0b0 = 0.0f;
    SetMode_0051d000(1);
    NiBillboardNode_SetUpdateControllers(1);
}

class FormPart508
{
  public:
    virtual void InitItem();
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
};

class ModelPart508
{
  public:
    virtual void GetModelFilePath();
    int unk04;
    int unk08;
};

class ScriptPart508
{
  public:
    virtual void GetScript();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class DestructPart508
{
  public:
    virtual void GetDestructible();
    int unk04;
    int unk08;
};

class SoundPart508
{
  public:
    virtual void GetSoundByEditorID();
    int unk04;
};

class WaterPart508
{
  public:
    virtual void GetWater();
    int unk04;
};

class ActivatorBase508 : public FormPart508,
                         public ModelPart508,
                         public ScriptPart508,
                         public DestructPart508,
                         public SoundPart508,
                         public WaterPart508
{
  public:
    virtual ~ActivatorBase508();

    void ClearData();
};

class ListPart508
{
  public:
    virtual void GetList();

    int unk04;
    int unk08;
};

class FUN_00508510_Activator : public ListPart508, public ActivatorBase508
{
  public:
    virtual ~FUN_00508510_Activator();
};

// @fnv 0x00508510
FUN_00508510_Activator::~FUN_00508510_Activator()
{
    ClearData();
}

struct Item;

struct List
{
    unsigned int __thiscall FUN_0043b480();
    Item* __thiscall FUN_0043b4a0(unsigned int index);
};

struct Item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    void* __thiscall FUN_00a59d30(int kind);
};

struct T
{
    void __thiscall NiMaterialProperty_SetEmittance(void* p);
};

extern void* DAT_011f4998;
void __cdecl ProcessListItems(List* list);

// Iterates the list, recursing into items whose v3() is nonzero and otherwise calling FUN_004bc450 on the result of FUN_00a59d30(2).
// @fnv 0x0050d640
void __cdecl ProcessListItems(List* list)
{
    for (unsigned int i = 0; i < list->FUN_0043b480(); i++)
    {
        Item* item = list->FUN_0043b4a0(i);
        if (item != 0)
        {
            if (item->v3() != 0)
                ProcessListItems((List*)item);
            else
            {
                void* t = item->FUN_00a59d30(2);
                if (t != 0)
                {
                    T* local = (T*)t;
                    local->NiMaterialProperty_SetEmittance(&DAT_011f4998);
                }
            }
        }
    }
}

extern double DAT_01011590;
extern double DAT_01029100;
extern double DAT_010290f8;
extern double DAT_010290f0;
extern double DAT_010290e8;
extern double DAT_010290e0;
extern double DAT_0101ff48;
extern double DAT_010290d8;
extern double DAT_01011588;
extern double DAT_010290d0;
extern double DAT_010290c8;
extern double DAT_01012060;
extern double DAT_01021928;
extern double DAT_01020998;
extern double DAT_01012070;
extern float DAT_01012054;
extern double DAT_010290c0;
extern double DAT_010290b8;
extern double DAT_010290b0;
extern double DAT_01016408;
extern float DAT_0101e2bc;
extern float DAT_010181bc;
unsigned int __cdecl FUN_00487f50();
float __cdecl sin_004e44b0(float v);
float __cdecl BSMIN(float a, float b);
float __cdecl BSMAX_00404010(float a, float b);
float __cdecl FUN_00408840(float v);
struct Obj
{
    float Projectile_GetSpreadLooking();
    float Sky_GetCurrentWeatherPct();
    float TESObjectWEAP_GetSpeed();
    void FUN_0050c630(float v);
    void FUN_0050c660(float v);
    void FUN_0050c690(float v);
    void NiAVObject_SetTranslate_004bc1f0(float a, float b, float c);
    void NiAVObject_Update(NiUpdateData& u);
    float TESCombatStyle_GetDodgeDuringAttackMult();
    void NiLight_SetDimmer(float v);
};
struct Ptr
{
    void* m_p;
    ~Ptr();
    Obj* Modelloader_GetReferencedThis();
};
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal DAT_011f6394;
extern Setting DAT_011c8fcc;
struct TQ
{
    void TaskQueueInterface_QueueObjectUpdate();
};
TQ* __stdcall FUN_004537b0(void* p);
bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
struct Host
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned int m_a8;
    int unkAC;
    int unkB0;
    float m_b4;
    bool TESObjectLIGH_Update_(Ptr p1, float* p2, NiPoint3* p3);
};
// @fnv 0x0050de60
// src: COMMUNITY 0x0050de60
bool Host::TESObjectLIGH_Update_(Ptr p1, float* apTime, NiPoint3* p3)
{
    Obj* s;
    s = p1.Modelloader_GetReferencedThis();
    {
        bool obj = false;
        if ((m_a8 & 8) || (m_a8 & 0x40))
        {
            float base;
            base = DAT_011f6394.FUN_0084d030();
            float b = 1.0f;
            float flag;
            flag = 0.0f;
            float x = 0.0f;
            if (s)
            {
                b = s->Projectile_GetSpreadLooking();
                flag = s->Sky_GetCurrentWeatherPct();
                x = s->TESObjectWEAP_GetSpeed();
            }
            if (m_a8 & 0x40)
                base = (float)(base / DAT_01011590);
            unsigned long curr = -1;
            b = (float)(((double)FUN_00487f50() / DAT_01029100 + DAT_010290f8) * base + b);
            flag = (float)(((double)FUN_00487f50() / DAT_01029100 + DAT_010290f0) * base + flag);
            x = (float)(((double)FUN_00487f50() / DAT_010290e8 + DAT_010290e0) * base + x);
            if (b > DAT_0101ff48)
                b = (float)(b - DAT_0101ff48);
            if (flag > DAT_0101ff48)
                flag = (float)(flag - DAT_0101ff48);
            if (DAT_0101ff48 < x)
                x = (float)(x - DAT_0101ff48);
            if (s)
            {
                s->FUN_0050c630(b);
                s->FUN_0050c660(flag);
                s->FUN_0050c690(x);
            }
            float idx;
            idx = sin_004e44b0((float)((b + DAT_010290d8) * 2.0));
            float a2;
            a2 = sin_004e44b0((float)((flag + DAT_01011588) * DAT_010290d8));
            float cost;
            cost = sin_004e44b0((float)((x + DAT_010290d0) * DAT_010290c8));
            float unk24;
            unk24 = *DAT_011c8fcc.Setting_Float_00403e20();
            float p;
            p = (float)(unk24 * idx * a2 / DAT_01011590);
            unk24 = (unk24 + p > DAT_01012060) ? p : 0.0f;
            p1.Modelloader_GetReferencedThis()->NiAVObject_SetTranslate_004bc1f0((float)(idx * unk24), (float)(a2 * unk24), (float)(cost * unk24));
            if (AILinearTaskThreadManager_ShouldQueue3DTask())
            {
                FUN_004537b0(p1.Modelloader_GetReferencedThis())->TaskQueueInterface_QueueObjectUpdate();
            }
            else
            {
                NiUpdateData upd(0.0f, false, 0);
                p1.Modelloader_GetReferencedThis()->NiAVObject_Update(upd);
            }
            float frac;
            frac =
                (float)((sin_004e44b0((float)((DAT_010290d0 + x) * DAT_01021928)) / DAT_01020998) +
                        (((sin_004e44b0((float)((flag + DAT_01011588) * DAT_010290e0)) + DAT_01012070) / DAT_01011590) *
                         (sin_004e44b0((float)((b + DAT_010290d8) * DAT_010290f8)) + DAT_01012070)) /
                            DAT_01011590 / DAT_01021928);
            frac = BSMAX_00404010(DAT_01012054, BSMIN(1.0f, frac));
            frac = (float)(frac * DAT_01011588 + DAT_01011588);
            p1.Modelloader_GetReferencedThis()->NiLight_SetDimmer((float)((frac * DAT_010290c0 + DAT_010290b8) * m_b4));
        }
        else
        {
            if ((m_a8 & 0x80) || (m_a8 & 0x100) || (p3 && *reinterpret_cast<const float*>(reinterpret_cast<const char*>(p3) + 0x0C) == 0.0))
            {
                float tim2;
                tim2 = p1.Modelloader_GetReferencedThis()->TESCombatStyle_GetDodgeDuringAttackMult();
                float cnt;
                cnt = DAT_011f6394.FUN_0084d030();
                float fin = DAT_0101e2bc;
                if ((m_a8 & 0x40) || (m_a8 & 0x100))
                    fin = DAT_010181bc;
                if (tim2 < *apTime)
                    tim2 = (float)(tim2 + fin * cnt);
                else
                    tim2 = (float)(tim2 - fin * cnt);
                p1.Modelloader_GetReferencedThis()->NiLight_SetDimmer(tim2);
                if (FUN_00408840((float)(tim2 - *apTime)) < fin)
                {
                    if (p3 && *reinterpret_cast<const float*>(reinterpret_cast<const char*>(p3) + 0x0C) == 0.0)
                    {
                        obj = true;
                    }
                    else if ((m_a8 & 8) || (m_a8 & 0x40))
                    {
                        *apTime = (float)(((FUN_00487f50() % 75) * DAT_01016408 + DAT_010290b0) * m_b4);
                    }
                    else if ((m_a8 & 0x80) || (m_a8 & 0x100))
                    {
                        if (*apTime > DAT_01011588)
                            *apTime = (float)(m_b4 * DAT_010290b0);
                        else
                            *apTime = m_b4;
                    }
                }
            }
        }
        return obj;
    }
}

struct Region
{
    bool IsInterior();
};
struct Reference
{
    Region* World();
    Region* Cell();
};
struct Node
{
    bool Empty();
    void** Item();
    Node* Next();
    unsigned int Size();
};
struct SelectionMap
{
    int vtable;
    int size;
    int table;
    int count;
    SelectionMap(unsigned int);
    ~SelectionMap();
    bool Lookup(unsigned int, bool*);
    void Set(unsigned int, bool);
};
struct Selector
{
    Node* List();
    void* FindRandomSelection(Reference*, int);
};
struct PlayerSelection
{
    unsigned char Previous(Selector*);
    void Record(Selector*, unsigned char);
};
extern PlayerSelection* selectionPlayer;
unsigned int DialogueRandom();
void* FindSelection(void*, Region*, void**);
// Picks a random unvisited entry from the selector's list, resolves it via FindSelection against the reference's region, and records the chosen index.
// @fnv 0x005195e0
void* Selector::FindRandomSelection(Reference* apReference, int unused)
{
    void* fallback = 0;
    void* result = 0;
    if (apReference)
    {
        Region* region = apReference->World();
        if (!region && apReference->Cell() && apReference->Cell()->IsInterior())
            region = apReference->Cell();
        if (region)
        {
            SelectionMap visitedMap(37);
            unsigned int attempts = 0;
            unsigned int uiListSize = List()->Size();
            unsigned int previous = -1;
            unsigned int index = -1;
            int size = selectionPlayer->Previous(this);
            while (attempts < uiListSize && !fallback)
            {
                attempts++;
                previous = DialogueRandom() % uiListSize;
                bool seen = false;
                while (visitedMap.Lookup(previous, &seen) && seen)
                {
                    previous = DialogueRandom() % uiListSize;
                    seen = false;
                }
                void* current = 0;
                unsigned int entry = 0;
                Node* node = List();
                while (node && !node->Empty())
                {
                    if (entry == previous)
                    {
                        current = *node->Item();
                        break;
                    }
                    else
                    {
                        entry++;
                        node = node->Next();
                    }
                }
                fallback = FindSelection(current, region, &result);
                if (result && index == -1)
                    index = previous;
                if (fallback && previous == size)
                {
                    result = fallback;
                    index = previous;
                    fallback = 0;
                }
                visitedMap.Set(entry, true);
            }
            if (previous != -1)
                selectionPlayer->Record(this, (unsigned char)previous);
        }
    }
    return fallback;
}

struct S_5010f0_Str
{
    int unk00;
    int unk04;
    ~S_5010f0_Str();
};

struct S_5010f0_Ptr
{
    int unk00;
    ~S_5010f0_Ptr();
};

struct S_5010f0_Cond
{
    int unk00;
    ~S_5010f0_Cond();
};

struct FUN_005010f0
{
    S_5010f0_Str m00;
    S_5010f0_Str m08;
    S_5010f0_Ptr m10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    S_5010f0_Cond m64;

    ~FUN_005010f0();
};

// Destructor for the FUN_005010f0 object; the body is empty and member destructors run implicitly.
// @fnv 0x005010f0
FUN_005010f0::~FUN_005010f0()
{}

struct FUN_005098e0_Object
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
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned char unk15C;
    unsigned char unk15D;

    bool IsFlagged() const;
};

// Returns true if unk15C or unk15D is nonzero.
// @fnv 0x005098e0
bool FUN_005098e0_Object::IsFlagged() const
{
    return unk15C || unk15D;
}


class NiPoint3Init : public NiPoint3
{
  public:
    NiPoint3Init(float afX, float afY, float afZ);
};



// These nonvirtual helpers are not yet declared by TESObjectREFR.h.
// Cast their external symbols to the original thiscall signatures at each use.
extern "C" void ReferenceGetDoorData();
extern "C" void ReferenceGetTeleportData();
extern "C" void ReferenceGetDoorMarker();
extern "C" void ReferenceGetDoorOffset();
extern "C" void ReferenceGetDoorRotation();
typedef void* (__thiscall *GetDoorDataFn)(TESObjectREFR*);
typedef TeleportableReference* (__thiscall *GetTeleportDataFn)(TESObjectREFR*);
typedef TESObjectREFR* (__thiscall *GetDoorMarkerFn)(TESObjectREFR*);
typedef NiPoint3* (__thiscall *GetDoorOffsetFn)(TESObjectREFR*, NiPoint3*, float);
typedef const NiPoint3& (__thiscall *GetDoorRotationFn)(const TESObjectREFR*);

struct TeleportableReference
{
    void FUN_00537e90(TESObjectREFR* apLinkedDoor);
    void FUN_006f4ed0(const NiPoint3& arPos);
    void SetVec(const NiPoint3& arRot);
};

float __cdecl BSMAX_00404010(float, float);
extern Setting g_011c9398;
extern Setting g_011c93c4;

// Links two door references by setting each door's teleport data to point at the other, using marker positions or computed offsets.
// @fnv 0x00519810
// src: XBOX_PDB 0x00519810
void __cdecl TESObjectDOOR_LinkRandomTeleportDoors(TESObjectREFR* apDoorA, TESObjectREFR* apDoorB)
{
    if (apDoorA && apDoorB && apDoorA != apDoorB)
    {
        TESObjectDOOR* pBaseA = dynamic_cast<TESObjectDOOR*>(apDoorA->BGSSaveFormBuffer_GetForm());
        TESObjectDOOR* pBaseDoorB = dynamic_cast<TESObjectDOOR*>(apDoorB->BGSSaveFormBuffer_GetForm());
        if (pBaseA && pBaseDoorB)
        {
            if (!reinterpret_cast<GetDoorDataFn>(ReferenceGetDoorData)(apDoorA) && !reinterpret_cast<GetDoorDataFn>(ReferenceGetDoorData)(apDoorB))
            {
                TeleportableReference* pTeleportDataA = reinterpret_cast<GetTeleportDataFn>(ReferenceGetTeleportData)(apDoorA);
                TeleportableReference* pTeleportDataB = reinterpret_cast<GetTeleportDataFn>(ReferenceGetTeleportData)(apDoorB);
                if (pTeleportDataA && pTeleportDataB)
                {
                    float fDist = *g_011c9398.Float();
                    float afValueAfterThirdFloat = BSMAX_00404010(fDist, *g_011c93c4.Float() + 100.0);
                    float fPi = 3.1415927f;

                    pTeleportDataA->FUN_00537e90(apDoorB);
                    TESObjectREFR* pMarkerB = reinterpret_cast<GetDoorMarkerFn>(ReferenceGetDoorMarker)(apDoorB);
                    if (pMarkerB)
                    {
                        pTeleportDataA->FUN_006f4ed0(*static_cast<const TESObjectREFR*>(pMarkerB)->GetPos());
                        pTeleportDataA->SetVec(reinterpret_cast<GetDoorRotationFn>(ReferenceGetDoorRotation)(pMarkerB));
                    }
                    else
                    {
                        float kOffsetB[3];
                        reinterpret_cast<GetDoorOffsetFn>(ReferenceGetDoorOffset)(apDoorB, reinterpret_cast<NiPoint3*>(kOffsetB), fPi);
                        if (pBaseDoorB->IsAutomaticDoor())
                            (*reinterpret_cast<NiPoint3*>(kOffsetB)) *= afValueAfterThirdFloat;
                        else
                            (*reinterpret_cast<NiPoint3*>(kOffsetB)) *= fDist;
                        pTeleportDataA->FUN_006f4ed0(*static_cast<const TESObjectREFR*>(apDoorB)->GetPos() + *reinterpret_cast<NiPoint3*>(kOffsetB));
                        pTeleportDataA->SetVec(NiPoint3Init(0.0f, 0.0f, reinterpret_cast<GetDoorRotationFn>(ReferenceGetDoorRotation)(apDoorB).z + fPi));
                    }

                    pTeleportDataB->FUN_00537e90(apDoorA);
                    pMarkerB = reinterpret_cast<GetDoorMarkerFn>(ReferenceGetDoorMarker)(apDoorA);
                    if (pMarkerB)
                    {
                        pTeleportDataB->FUN_006f4ed0(*static_cast<const TESObjectREFR*>(pMarkerB)->GetPos());
                        pTeleportDataB->SetVec(reinterpret_cast<GetDoorRotationFn>(ReferenceGetDoorRotation)(pMarkerB));
                    }
                    else
                    {
                        float kOffsetA[3];
                        reinterpret_cast<GetDoorOffsetFn>(ReferenceGetDoorOffset)(apDoorA, reinterpret_cast<NiPoint3*>(kOffsetA), fPi);
                        if (pBaseA->IsAutomaticDoor())
                            (*reinterpret_cast<NiPoint3*>(kOffsetA)) *= afValueAfterThirdFloat;
                        else
                            (*reinterpret_cast<NiPoint3*>(kOffsetA)) *= fDist;
                        pTeleportDataB->FUN_006f4ed0(*static_cast<const TESObjectREFR*>(apDoorA)->GetPos() + *reinterpret_cast<NiPoint3*>(kOffsetA));
                        pTeleportDataB->SetVec(NiPoint3Init(0.0f, 0.0f, reinterpret_cast<GetDoorRotationFn>(ReferenceGetDoorRotation)(apDoorA).z + fPi));
                    }
                }
            }
        }
    }
}

struct TESObjectCELL_Ext : TESForm
{
    bool IsInterior();
};
// Returns true if p is a cell (type 0x39) that is interior, or if p has form type 0x41.
// @fnv 0x00519570
// src: XBOX_PDB 0x00519570
bool TESObjectDOOR_CanBeRandomTeleport(TESForm* apForm)
{
    bool result = false;
    if (apForm)
    {
        switch (apForm->FNV_GetFormType())
        {
        case 0x39: {
            TESObjectCELL* cell = dynamic_cast<TESObjectCELL*>(apForm);
            if (cell && ((TESObjectCELL_Ext*)cell)->IsInterior())
                result = true;
        }
        break;
        case 0x41:
            result = true;
            break;
        }
    }
    return result;
}
