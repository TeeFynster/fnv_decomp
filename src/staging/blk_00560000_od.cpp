#include "../../include/PackageTargetRecord.h"
#include "../../include/NiTListItem.h"

// src/staging/blk_00560000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; with NiPoint3 (its in-class inline bodies, no stand-in constructor/operators), 0x00563380 does not match.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/NiMatrix3.h"
#include "../../include/NiQuaternion.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/hkVector4.h"
#include "../../include/ExtraDataList.h"
#include "../../include/InventoryChanges.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiNode.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESSound.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/bhkCharacterController.h"
#include "../../include/bhkCollisionObject.h"
#include "../../include/bhkRigidBody.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/hkRotation.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiObject.h"
#include "../../include/NiRTTI.h"
#include "../../include/WaterShaderSettings.h"
#include "../../include/TESObjectCELL.h"

class BGSPerk;

// Reference positions are copied as three raw words, preserving their float bit patterns.
struct PositionBits
{
    unsigned int words[3];
};

struct FUN_00560cf0_Class
{
    void MuzzleFlash_SetDurationTimer(float value);
};

// @fnv 0x00560cf0
// src: COMMUNITY 0x00560cf0
void FUN_00560cf0_Class::MuzzleFlash_SetDurationTimer(float value)
{
    *(float*)((char*)this + 8) = value;
}

struct BSFlags
{
    void Clear(unsigned int);
};

struct FormChangeRecord
{
    void BGSSaveFormBuffer_RemoveChange(unsigned int);
};

// @fnv 0x005621f0
// src: COMMUNITY 0x005621f0
void FormChangeRecord::BGSSaveFormBuffer_RemoveChange(unsigned int flags)
{
    ((BSFlags*)((char*)this + 0x17))->Clear(flags);
}

struct GlobalObject_00559cc0
{
    bool RemoveAt(unsigned int);
};
extern GlobalObject_00559cc0 g_011ca0e0;

// @fnv 0x00565670
// src: COMMUNITY 0x00565670
void TESObjectREFR_RemoveRefFromMultiboundTestMap(unsigned int index)
{
    g_011ca0e0.RemoveAt(index);
}

struct FUN_00566910_Class
{
    unsigned char NiControllerManager_IsCumulative();
};

// @fnv 0x00566910
// src: COMMUNITY 0x00566910
unsigned char FUN_00566910_Class::NiControllerManager_IsCumulative()
{
    return ((unsigned char*)this)[0x68];
}

struct TaskQueueInterface
{
    void SetTaskFlagWord(bool, unsigned short);
    void NiTimeController_SetComputeScaledTime(bool flag);
};

// @fnv 0x00566930
// src: COMMUNITY 0x00566930
void TaskQueueInterface::NiTimeController_SetComputeScaledTime(bool abSet)
{
    SetTaskFlagWord(abSet, 0x40);
}

// Returns the extra data of the given type by forwarding to the actor's extra data list lookup.
// @fnv 0x0056aa90
BSExtraData* TESObjectREFR::GetExtraData(unsigned char type) const
{
    return static_cast<BSExtraData*>(const_cast<ExtraDataList*>(GetExtra())->ExtraDataList_SetEnableStateInverse(type));
}

struct ABD_005f92d0
{
    bool GetFlag(unsigned int) const;
    bool GetFlag8();
};

// @fnv 0x0056af00
bool ABD_005f92d0::GetFlag8()
{
    return GetFlag(8);
}

struct FUN_0056af20_Class
{
    bool __thiscall IsFlag2Set();
};

// @fnv 0x0056af20
bool __thiscall FUN_0056af20_Class::IsFlag2Set()
{
    return (signed char)((char*)this)[0x98] & 2;
}

struct FUN_0056d360_Class
{
    void bhkRigidBodyCinfo_SetMotionType(int a);
};

struct FUN_005407b0_Class
{
    void UpdateState_005407b0(int a);
};

// @fnv 0x0056d360
// src: COMMUNITY 0x0056d360
void FUN_0056d360_Class::bhkRigidBodyCinfo_SetMotionType(int aiValue)
{
    ((FUN_005407b0_Class*)((char*)this + 0xd4))->UpdateState_005407b0(aiValue);
}

extern "C" void* DAT_01030534;

struct FUN_0056d610_base
{
    virtual ~FUN_0056d610_base();
};

struct FUN_0056d5f0_class : FUN_0056d610_base
{
    void SetVtableAndProcessState_0056d610();
    void* bhkWaterPhantomCallbackShape_bhkWaterPhantomCallbackShape();
};

// @fnv 0x0056d5f0
// src: EXE 0x0056d5f0
void* FUN_0056d5f0_class::bhkWaterPhantomCallbackShape_bhkWaterPhantomCallbackShape()
{
    SetVtableAndProcessState_0056d610();
    *reinterpret_cast<void**>(this) = &DAT_01030534;
    return this;
}

extern int DAT_01030570;

struct FUN_0056d610Class
{
    void __thiscall FUN_0056d640(int);
    FUN_0056d610Class* __thiscall SetVtableAndProcessState_0056d610();
};

// Calls FUN_0056d640 with 0x1d, stores the address of DAT_01030570 at the start of this, and returns this.
// @fnv 0x0056d610
// src: GUESS 0x0056d610 (confidence: low)
FUN_0056d610Class* __thiscall FUN_0056d610Class::SetVtableAndProcessState_0056d610()
{
    FUN_0056d640(0x1d);
    *reinterpret_cast<int**>(this) = &DAT_01030570;
    return this;
}

struct FUN_0056d6c0_class
{
    void __thiscall DestroyFields_0056d6c0();
};

struct FUN_0056d710_class : public FUN_0056d6c0_class
{
    void __thiscall ForwardCall_0056d710();
};

// @fnv 0x0056d710
// src: GUESS 0x0056d710 (confidence: low)
void __thiscall FUN_0056d710_class::ForwardCall_0056d710()
{
    DestroyFields_0056d6c0();
}

struct FUN_0056d780_class
{
    void ForwardCall_0056d7a0();
    void ForwardCall_0056d780();
};
// @fnv 0x0056d780
// src: GUESS 0x0056d780 (confidence: low)
void FUN_0056d780_class::ForwardCall_0056d780()
{
    ForwardCall_0056d7a0();
}

struct FUN_0057c530Class
{
    void FUN_0057c530();
};

struct FUN_0056d7a0Class
{
    void ForwardCall_0056d7a0();
};

// @fnv 0x0056d7a0
// src: GUESS 0x0056d7a0 (confidence: low)
void FUN_0056d7a0Class::ForwardCall_0056d7a0()
{
    ((FUN_0057c530Class*)((char*)this + 0xc))->FUN_0057c530();
}

struct FUN_0056d7c0_cls
{
    void ForwardCall_0056d710();
    void ForwardCall_0056d7c0();
};

// @fnv 0x0056d7c0
// src: GUESS 0x0056d7c0 (confidence: low)
void FUN_0056d7c0_cls::ForwardCall_0056d7c0()
{
    ForwardCall_0056d710();
}

struct FUN_0056ded0 : hkRotation
{
    hkVector4 m_kPointB;
    FUN_0056ded0();
};

// Constructs the object by running the base hkRotation constructor and default-constructing its embedded member.
// @fnv 0x0056ded0
FUN_0056ded0::FUN_0056ded0()
{}

struct FUN_0056df00_class
{
    void __thiscall hkMatrix3_hkMatrix3();
    FUN_0056df00_class* __thiscall hkRotation_hkRotation();
};

// @fnv 0x0056df00
// src: XBOX_PDB 0x0056df00
FUN_0056df00_class* __thiscall FUN_0056df00_class::hkRotation_hkRotation()
{
    hkMatrix3_hkMatrix3();
    return this;
}

extern int DAT_01030dc0;
struct FUN_0056d610
{
    void __thiscall Init();
};
struct FUN_0056f690
{
    FUN_0056f690();
};
// @fnv 0x0056f690
FUN_0056f690::FUN_0056f690()
{
    ((FUN_0056d610*)this)->Init();
    *(int*)this = (int)&DAT_01030dc0;
}

struct FUN_00456630_helper
{
    bool NiAVObject_GetBit(unsigned int);
    bool NiAVObject_GetHasMovingSound();
};

// @fnv 0x00570ea0
// src: COMMUNITY 0x00570ea0
bool FUN_00456630_helper::NiAVObject_GetHasMovingSound()
{
    return NiAVObject_GetBit(0x20000);
}

int __fastcall GetByteAtOffset38(void*);
struct FUN_00570ec0
{
    int __thiscall Get();
};
// @fnv 0x00570ec0
int __thiscall FUN_00570ec0::Get()
{
    return !(GetByteAtOffset38(this) - 1);
}

struct FUN_00570ee0_class
{
    void NiAVObject_GetHasMovingSound();
    void BSFadeNode_HasMovingSound();
};

// @fnv 0x00570ee0
// src: COMMUNITY 0x00570ee0
void FUN_00570ee0_class::BSFadeNode_HasMovingSound()
{
    NiAVObject_GetHasMovingSound();
}

struct FUN_00570f40_Class
{
    bool BGSSaveLoadGame_GetGlobalAllowChanges() const;
};

// @fnv 0x00570f40
// src: COMMUNITY 0x00570f40
bool FUN_00570f40_Class::BGSSaveLoadGame_GetGlobalAllowChanges() const
{
    return (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x244)) & 1) == 0) ? true
                                                                                                              : false;
}

struct BSOcclusionPlane;
struct FUN_006205e0_shell
{
    void __thiscall RemoveNode(void*);
};
struct FUN_00576830_shell
{
    void* BGSZoneTargetListener_GetZoneEntry(BSOcclusionPlane*);
    void BGSZoneTargetListener_RemoveZone(BSOcclusionPlane* p);
};
// Calls FUN_00576830 on the occlusion plane, then passes the result to RemoveNode on this object.
// @fnv 0x00576800
// src: COMMUNITY 0x00576800
void FUN_00576830_shell::BGSZoneTargetListener_RemoveZone(BSOcclusionPlane* apPlane)
{
    ((FUN_006205e0_shell*)this)->RemoveNode(BGSZoneTargetListener_GetZoneEntry(apPlane));
}

struct V4_538f40
{
    void hkVector4_setZero4();
};
struct FUN_00577070_class
{
    void UpdateState_00577090();
    void hkTransform_setIdentity();
};
// @fnv 0x00577070
// src: COMMUNITY 0x00577070
void FUN_00577070_class::hkTransform_setIdentity()
{
    UpdateState_00577090();
    ((V4_538f40*)((char*)this + 0x30))->hkVector4_setZero4();
}

struct FUN_004b4cf0_shell
{
    void* FUN_004b4cf0(unsigned int);
};
struct FUN_005770e0_shell : FUN_004b4cf0_shell
{
    float& GetCharacterControllerValue(unsigned int a, unsigned int b);
};
// @fnv 0x005770e0
float& FUN_005770e0_shell::GetCharacterControllerValue(unsigned int a, unsigned int b)
{
    return ((bhkCharacterController*)FUN_004b4cf0(b))->GetVectorElement(a);
}

extern int DAT_01030f6c;
struct FUN_0057c470Class
{
    int m;
    void __thiscall InitArray(int);
    int* __thiscall NiTPointerMap_TESObjectREFR_bool_NiTPointerMap(int);
};
// Calls InitArray with a, stores the address of DAT_01030f6c in m, and returns &m.
// @fnv 0x0057c470
// src: EXE 0x0057c470
int* __thiscall FUN_0057c470Class::NiTPointerMap_TESObjectREFR_bool_NiTPointerMap(int a)
{
    InitArray(a);
    m = (int)&DAT_01030f6c;
    return &m;
}


struct FUN_0057e9a0
{
    FUN_0057e9a0();
};

// @fnv 0x0057e9a0
FUN_0057e9a0::FUN_0057e9a0()
{
    ((WaterShaderSettings*)this)->Initialize();
}

extern void* DAT_01030fd4;
void _NiFreeAlias(void*);

struct FUN_0057ca30_Class
{
    void NiTPointerMap_RemoveAll();
    void SetVtableAndProcessState_0057ca30();
};

// Sets the vtable pointer, clears the pointer map, and frees the object at offset 8.
// @fnv 0x0057ca30
// src: GUESS 0x0057ca30 (confidence: low)
void FUN_0057ca30_Class::SetVtableAndProcessState_0057ca30()
{
    *(void**)this = &DAT_01030fd4;
    NiTPointerMap_RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}

void __cdecl Tesland_UpdateState_00538eb0(void*);

struct FUN_0056d6e0_Class
{
    void* HavokStreambufFactory_Destroy(unsigned int flags);
};

// @fnv 0x0056d6e0
// src: COMMUNITY 0x0056d6e0
void* FUN_0056d6e0_Class::HavokStreambufFactory_Destroy(unsigned int flags)
{
    reinterpret_cast<FUN_0056d7c0_cls*>(this)->ForwardCall_0056d710();
    if (flags & 1)
        Tesland_UpdateState_00538eb0(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_0057c370_Class
{
    void __thiscall FUN_0057c3a0();
    void* __thiscall FUN_0057c370(unsigned int flags);
};
// Calls FUN_0057c3a0, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0057c370
void* __thiscall FUN_0057c370_Class::FUN_0057c370(unsigned int flags)
{
    FUN_0057c3a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0057c4a0_Class
{
    void __thiscall FUN_0057c780();
    void* __thiscall FUN_0057c4a0(unsigned int flags);
};
// Calls FUN_0057c780, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0057c4a0
void* FUN_0057c4a0_Class::FUN_0057c4a0(unsigned int flags)
{
    FUN_0057c780();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0057c500_Class
{
    void FUN_0057c9d0();
    void* __thiscall FUN_0057c500(unsigned int flags);
};
// @fnv 0x0057c500
void* FUN_0057c500_Class::FUN_0057c500(unsigned int flags)
{
    FUN_0057c9d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0057ca60_Class
{
    void ForwardCall_004b05b0();
    void* FUN_0057ca60(unsigned int flags);
};
// Calls FUN_004b05b0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0057ca60
void* FUN_0057ca60_Class::FUN_0057ca60(unsigned int flags)
{
    ForwardCall_004b05b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" void _Deallocate(void*);
struct FUN_0057c930_class
{
    void __thiscall SetVtableAndProcessState_0057c930();
};
struct FUN_0057ca90_Class
{
    void* __thiscall FUN_0057ca90(unsigned int flags);
};
// @fnv 0x0057ca90
void* FUN_0057ca90_Class::FUN_0057ca90(unsigned int flags)
{
    reinterpret_cast<FUN_0057c930_class*>(this)->SetVtableAndProcessState_0057c930();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00560d10_shell
{
    float& __thiscall GetVectorElement_Thunk(unsigned int);
};
struct Modifier
{
    void SetValue(float);
};

struct AlphaColor
{
    void TESRegionPoint_SetX(float);
};
// Copies four float values from b into a via SetValue, FUN_00560cf0, SetTargAcquireRadius and FUN_0052ce20, then returns a.
// @fnv 0x00560c80
Modifier* CopyModifierSettings(Modifier* apModifier, FUN_00560d10_shell* apSource)
{
    apModifier->SetValue(apSource->GetVectorElement_Thunk(0));
    ((FUN_00560cf0_Class*)apModifier)->MuzzleFlash_SetDurationTimer(apSource->GetVectorElement_Thunk(1));
    ((PackageTargetRecord*)apModifier)->SetTargAcquireRadius(apSource->GetVectorElement_Thunk(2));
    ((AlphaColor*)apModifier)->TESRegionPoint_SetX(apSource->GetVectorElement_Thunk(3));
    return apModifier;
}

void __cdecl SetNiPoint3FromHkVector4(hkVector4 const&, void*);
struct FUN_00560d50_Struct
{
    void* __thiscall bhkRigidBody_GetLinearVelocity_00560d80();
    void __thiscall bhkRigidBody_GetLinearVelocity(hkVector4 const&);
};
// @fnv 0x00560d50
// src: XBOX_PDB 0x00560d50
void __thiscall FUN_00560d50_Struct::bhkRigidBody_GetLinearVelocity(hkVector4 const& aVector)
{
    SetNiPoint3FromHkVector4(aVector, bhkRigidBody_GetLinearVelocity_00560d80());
}

struct ReferenceFlags : TESObjectREFR
{
    void __thiscall SetFlag100000(unsigned char flag);
};

// @fnv 0x00564d20
void __thiscall ReferenceFlags::SetFlag100000(unsigned char abSet)
{
    if (!((bool(__thiscall*)(void*))(*reinterpret_cast<void***>(this))[0x40])(this))
    {
        unsigned int flags = GetFlags();
        if (abSet)
            flags |= 0x100000;
        else
            flags &= 0xffefffff;
        SetFlags(flags);
    }
}

// @fnv 0x00564d80
// src: COMMUNITY 0x00564d80
bool TESObjectREFR::GetTargeted()
{
    unsigned int flags = GetFlags();
    if (flags & 0x40000)
        return true;
    else
        return false;
}

struct BGSEncounterZone;
// The +0x40 cell and GetParentWorldSpace (0x00575d70) identify a reference; 0x00567d90 is absent from its shared header.
struct ReferenceEncounterZoneAccess : TESObjectREFR
{
    BGSEncounterZone* __thiscall TESObjectREFR_GetLocationEncounterZone();
};
// @fnv 0x00567d90
// src: XBOX_PDB 0x00567d90
BGSEncounterZone* __thiscall ReferenceEncounterZoneAccess::TESObjectREFR_GetLocationEncounterZone()
{
    if (m_pOwningCell != 0)
        return (m_pOwningCell)->FindEncounterZone();
    TESWorldSpace* ws = GetParentWorldSpace();
    if (ws != 0)
        return (BGSEncounterZone*)ws->GetFieldD0();
    return 0;
}

struct Data12_569620
{
    int a;
    int b;
    int c;
};
struct Param_569620
{
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void Use_8c(Data12_569620*) = 0;
};
struct S_00569620
{
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void d35() = 0;
    virtual void d36() = 0;
    virtual void d37() = 0;
    virtual void d38() = 0;
    virtual void d39() = 0;
    virtual void d40() = 0;
    virtual void d41() = 0;
    virtual void d42() = 0;
    virtual void d43() = 0;
    virtual void d44() = 0;
    virtual void d45() = 0;
    virtual void d46() = 0;
    virtual void d47() = 0;
    virtual void d48() = 0;
    virtual void d49() = 0;
    virtual void d50() = 0;
    virtual void d51() = 0;
    virtual void d52() = 0;
    virtual void d53() = 0;
    virtual void d54() = 0;
    virtual void d55() = 0;
    virtual void d56() = 0;
    virtual void d57() = 0;
    virtual void d58() = 0;
    virtual void d59() = 0;
    virtual void d60() = 0;
    virtual void d61() = 0;
    virtual void d62() = 0;
    virtual void d63() = 0;
    virtual void d64() = 0;
    virtual void d65() = 0;
    virtual void d66() = 0;
    virtual void d67() = 0;
    virtual void d68() = 0;
    virtual void d69() = 0;
    virtual void d70() = 0;
    virtual void d71() = 0;
    virtual void d72() = 0;
    virtual void d73() = 0;
    virtual void d74() = 0;
    virtual void d75() = 0;
    virtual void d76() = 0;
    virtual void d77() = 0;
    virtual void d78() = 0;
    virtual void d79() = 0;
    virtual void d80() = 0;
    virtual void d81() = 0;
    virtual void d82() = 0;
    virtual void d83() = 0;
    virtual void d84() = 0;
    virtual void d85() = 0;
    virtual void d86() = 0;
    virtual void d87() = 0;
    virtual void d88() = 0;
    virtual void d89() = 0;
    virtual void d90() = 0;
    virtual void d91() = 0;
    virtual void d92() = 0;
    virtual void d93() = 0;
    virtual void d94() = 0;
    virtual void d95() = 0;
    virtual void d96() = 0;
    virtual void d97() = 0;
    virtual void d98() = 0;
    virtual void d99() = 0;
    virtual void d100() = 0;
    virtual void d101() = 0;
    virtual void d102() = 0;
    virtual void d103() = 0;
    virtual void d104() = 0;
    virtual void d105() = 0;
    virtual void d106() = 0;
    virtual void d107() = 0;
    virtual void d108() = 0;
    virtual void d109() = 0;
    virtual void d110() = 0;
    virtual void d111() = 0;
    virtual void d112() = 0;
    virtual void d113() = 0;
    virtual void d114() = 0;
    virtual void d115() = 0;
    virtual void d116() = 0;
    virtual void d117() = 0;
    virtual void d118() = 0;
    virtual void d119() = 0;
    virtual void d120() = 0;
    virtual void d121() = 0;
    virtual void d122() = 0;
    virtual void d123() = 0;
    virtual void d124() = 0;
    virtual Data12_569620* Get1f4() = 0;
    void CopyDataAndUse(Param_569620* p);
};
// Copies the object returned by Get1f4() into a local and passes its address to p->Use_8c.
// @fnv 0x00569620
void S_00569620::CopyDataAndUse(Param_569620* apParam)
{
    Data12_569620 tmp = *Get1f4();
    apParam->Use_8c(&tmp);
}

extern "C" void* DAT_010302bc;
extern "C" int DAT_012681fc;
struct FUN_0056d410_Class
{
    void __thiscall FUN_0056d440();
    void* __thiscall bhkEntity_bhkEntity();
};
// @fnv 0x0056d410
// src: EXE 0x0056d410
void* __thiscall FUN_0056d410_Class::bhkEntity_bhkEntity()
{
    FUN_0056d440();
    *(void**)(this) = &DAT_010302bc;
    DAT_012681fc = DAT_012681fc + 1;
    return this;
}

struct FUN_004b5120
{
    unsigned char pad[0x10];
    FUN_004b5120();
};
extern int DAT_01030394;
extern int DAT_0126810c;
struct FUN_0056d440 : FUN_004b5120
{
    int m_10;
    FUN_0056d440();
};
// @fnv 0x0056d440
FUN_0056d440::FUN_0056d440()
{
    *(void**)this = (void*)&DAT_01030394;
    m_10 = 0;
    DAT_0126810c++;
}

struct FUN_0066d410_shell
{
    void ForwardCall_0066d410();
};
void __cdecl operator delete(void* p, unsigned int flags);
struct FUN_0056d5c0_Class
{
    void* __thiscall FUN_0056d5c0(unsigned int flags);
};
// @fnv 0x0056d5c0
void* __thiscall FUN_0056d5c0_Class::FUN_0056d5c0(unsigned int flags)
{
    ((FUN_0066d410_shell*)this)->ForwardCall_0066d410();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

struct FUN_0056d750_holder
{
    void* __thiscall FUN_0056d750(unsigned int);
};
// Calls FUN_0056d7c0 on this, then if bit 0 of flags is set calls FUN_00538eb0(this), and returns this.
// @fnv 0x0056d750
void* __thiscall FUN_0056d750_holder::FUN_0056d750(unsigned int flags)
{
    ((FUN_0056d7c0_cls*)this)->ForwardCall_0056d7c0();
    if (flags & 1)
        Tesland_UpdateState_00538eb0(this);
    return this;
}

// 0x00a29680 is the empty physics access hook; Script::GetLocalData is 0x005533c0.
struct PhysicsAccessHook
{
    void __thiscall CheckAccess();
};
struct FUN_00c9e910_Class
{
    void __thiscall hkpShapePhantom_setTransform(int a);
};
struct FUN_0056e050_Class
{
    void __thiscall bhkShapePhantom_setTransform(int a);
};
// @fnv 0x0056e050
// src: COMMUNITY 0x0056e050
void __thiscall FUN_0056e050_Class::bhkShapePhantom_setTransform(int a)
{
    void* p = ((bhkWorldObject*)this)->Bipedanim_GetReferenceFlagsOrZero();
    if (p)
    {
        ((PhysicsAccessHook*)this)->CheckAccess();
        ((FUN_00c9e910_Class*)p)->hkpShapePhantom_setTransform(a);
        ((PhysicsAccessHook*)this)->CheckAccess();
    }
}

extern unsigned char DAT_011dcfa7;

// @fnv 0x00572220
// src: XBOX_PDB 0x00572220
void FalloutAudio_LockAcousticSpace(unsigned char value)
{
    DAT_011dcfa7 = value;
}

// Copies the NiPoint3 at offset 0x30, replaces its z with scale, and calls SetLocationOnReference with it.
struct ReferencePositionAccess : TESObjectREFR
{
    void __thiscall SetZ(float);
};

// @fnv 0x00575b70
void __thiscall ReferencePositionAccess::SetZ(float afZ)
{
    PositionBits p = *(const PositionBits*)((const char*)this + 0x30);
    *(float*)&p.words[2] = afZ;
    SetLocationOnReference(reinterpret_cast<const NiPoint3&>(p));
}

struct FUN_00577110_shell
{
    void ProcessState_00577110();
};
struct FUN_00577090_shell : FUN_005770e0_shell
{
    void UpdateState_00577090();
};
// Calls FUN_00577110 on this, then sets the base-class elements at indices 0, 1 and 2 to 1.0f.
// @fnv 0x00577090
// src: GUESS 0x00577090 (confidence: low)
void FUN_00577090_shell::UpdateState_00577090()
{
    ((FUN_00577110_shell*)this)->ProcessState_00577110();
    float f = 1.0f;
    FUN_005770e0_shell::GetCharacterControllerValue(0, 0) = f;
    FUN_005770e0_shell::GetCharacterControllerValue(1, 1) = f;
    FUN_005770e0_shell::GetCharacterControllerValue(2, 2) = f;
}

struct Holder0057c400
{
    void* __thiscall bhkTTNode_TESObjectREFR_GetEntry(unsigned int);
};
// Walks the list starting at this, calling Deallocate on each node, and returns the first node whose result equals id, or null.
// @fnv 0x0057c400
// src: XBOX_PDB 0x0057c400
void* __thiscall Holder0057c400::bhkTTNode_TESObjectREFR_GetEntry(unsigned int id)
{
    TESSound* cur = (TESSound*)this;
    while (cur)
    {
        if (cur->Deallocate() == id)
            break;
        cur = (TESSound*)((BSSimpleList<void*>*)cur)->GetNext();
    }
    return cur;
}

struct FUN_00559b40
{
    FUN_00559b40(int);
};
extern int DAT_01030f4c;
struct FUN_0057c440 : FUN_00559b40
{
    FUN_0057c440(int);
};
// @fnv 0x0057c440
FUN_0057c440::FUN_0057c440(int aiValue) : FUN_00559b40(aiValue)
{
    *(int*)this = (int)&DAT_01030f4c;
}

struct Node
{
    int a;
    int b;
};
struct ScriptPool
{
    Node* __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
};
struct Helper62d0
{
    void* operator=(const void*);
};
struct FUN_004ed8c0_shell
{
    void NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(Node*);
};
struct FUN_0057c590_Class : public FUN_004ed8c0_shell
{
    void __thiscall DecalManager_AppendList08(Node* p);
};
// Gets a node from the script pool, stores p into the node's field at offset 8, then passes the node to FUN_00559a70.
// @fnv 0x0057c590
// src: COMMUNITY 0x0057c590
void __thiscall FUN_0057c590_Class::DecalManager_AppendList08(Node* apNode)
{
    Node* pNode = ((ScriptPool*)this)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
    ((Helper62d0*)((char*)pNode + 8))->operator=(apNode);
    NiTListBase_NiTPointerAllocator_unsigned_int_BSFaceGenKeyframe_AddNodeTail(pNode);
}

struct ScenePointerListAccess
{
    void* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(void*&);
};
struct FUN_0057c6a0Class
{
    void* Modelloader_GetReferencedThis();
    void* NiTPointerListBase_NiPropertyPtr_FindPos(void* a, void* b);
};
// Walks the list starting at b (or the default from FUN_00559450) and returns the first element equal to a, or 0 if none matches.
// @fnv 0x0057c6a0
// src: COMMUNITY 0x0057c6a0
void* FUN_0057c6a0Class::NiTPointerListBase_NiPropertyPtr_FindPos(void* apTarget, void* apStart)
{
    if (!apStart)
        apStart = Modelloader_GetReferencedThis();
    while (apStart)
    {
        void* c = apStart;
        if (((NiPointer<NiAVObject>*)apTarget)->operator==(*((NiPointer<NiAVObject>*)((ScenePointerListAccess*)this)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(apStart))))
            return c;
    }
    return 0;
}

extern int DAT_01030fac;
struct Base5700
{
    void __thiscall FUN_0057cb70(unsigned int, unsigned int);
};
struct FUN_0057c700
{
    FUN_0057c700(unsigned int, unsigned int);
};
// @fnv 0x0057c700
FUN_0057c700::FUN_0057c700(unsigned int a, unsigned int b)
{
    ((Base5700*)this)->FUN_0057cb70(a, b);
    *(void**)this = (void*)&DAT_01030fac;
}

void* __cdecl _NiMalloc(unsigned int size);
void* __cdecl _memset(void* dst, unsigned int value, unsigned int count);
extern int DAT_01030fb4;
struct FUN_0057c7e0_Class
{
    int* __thiscall InitArray(int count);
};
// @fnv 0x0057c7e0
int* FUN_0057c7e0_Class::InitArray(int count)
{
    unsigned int uiByteCount;
    *(int**)((char*)this + 0) = &DAT_01030fb4;
    *(int*)((char*)this + 4) = count;
    *(int*)((char*)this + 0xc) = 0;
    uiByteCount = *(unsigned int*)((char*)this + 4) << 2;
    *(int*)((char*)this + 8) = (int)_NiMalloc(uiByteCount);
    _memset(*(void**)((char*)this + 8), 0, *(unsigned int*)((char*)this + 4) << 2);
    return (int*)this;
}

extern int DAT_01030fb4;
void _NiFree(void*);
// @fnv 0x0057c930
// src: GUESS 0x0057c930 (confidence: low)
void __thiscall FUN_0057c930_class::SetVtableAndProcessState_0057c930()
{
    *(int*)this = (int)&DAT_01030fb4;
    ((FUN_0057ca30_Class*)this)->NiTPointerMap_RemoveAll();
    _NiFree(((void**)this)[2]);
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_0057c960
{
    void* vtable;
    int count;
    void* data;
    int pad;
    FUN_0057c960(int c);
};
// Sets the vtable, stores the count, allocates count*4 bytes with NiMalloc and zeroes them with memset.
// @fnv 0x0057c960
FUN_0057c960::FUN_0057c960(int aiCount)
{
    vtable = &DAT_01030fd4;
    count = aiCount;
    pad = 0;
    unsigned int size = count * 4;
    data = NiMalloc(size);
    memset(data, 0, count * 4);
}

struct FUN_0057cac0_Holder : FUN_0057ca30_Class
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls the base constructor, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0057cac0
void* __thiscall FUN_0057cac0_Holder::DestroyIfFlagged(unsigned int flags)
{
    SetVtableAndProcessState_0057ca30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct H_A100
{
    void* GetSizeMasked();
};
void __fastcall hkArrayBase_hkpRootCdBodyPair_clear(void*);
struct FUN_0057cc10_Class
{
    void __thiscall UpdateState_0057cc10(void* a, void* b);
};
struct FUN_0057cb20_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    unsigned int m_8;
    void __thiscall UpdateFields_0057cb20(int a);
};
// @fnv 0x0057cb20
// src: GUESS 0x0057cb20 (confidence: low)
void __thiscall FUN_0057cb20_Class::UpdateFields_0057cb20(int pTarget)
{
    hkArrayBase_hkpRootCdBodyPair_clear(this);
    if (!(m_8 & 0x80000000))
    {
        ((FUN_0057cc10_Class*)pTarget)->UpdateState_0057cc10(m_iWordAt00, ((H_A100*)this)->GetSizeMasked());
    }
    m_iWordAt00 = 0;
    m_8 = 0x80000000;
}

struct FUN_0057cc10_Cls
{
    virtual void F0()
    {}
    virtual void F1()
    {}
    virtual void F2()
    {}
    virtual void F3()
    {}
    virtual void F4(int, int)
    {}
    void __thiscall UpdateState_0057cc10(int, int);
};
// Calls F4 with a and b shifted left by 3, using a local x initialized to 8.
// @fnv 0x0057cc10
// src: GUESS 0x0057cc10 (confidence: low)
void __thiscall FUN_0057cc10_Cls::UpdateState_0057cc10(int a, int b)
{
    int x = 8;
    F4(a, b << 3);
}

extern float runtimeInitializationFloat2400;
extern float DAT_011f4ae0[];
// Maps an input float to a 512-entry table index using 512.0 divided by runtimeInitializationFloat2400, then returns the table value.
// @fnv 0x0057e960
// src: COMMUNITY 0x0057e960
float __cdecl NiCosQ(float a)
{
    int v = (int)((512.0 / runtimeInitializationFloat2400) * a) & 0x1ff;
    return DAT_011f4ae0[v];
    return 0.0f;
}

struct FUN_0042dec0_shell
{
    void RemoveExtraType43();
    void ExtraDataList_RemoveNavMeshPortal();
};
struct FUN_0042e2a0_shell
{
    void* GetExtraNavMeshPortal();
};
struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int);
};
struct ReferenceNavMeshAccess : TESObjectREFR
{
    void TESObjectREFR_RemoveTeleport();
};
// @fnv 0x00568f30
// src: COMMUNITY 0x00568f30
void ReferenceNavMeshAccess::TESObjectREFR_RemoveTeleport()
{
    ((FUN_0042dec0_shell*)static_cast<const TESObjectREFR*>(this)->GetExtra())->RemoveExtraType43();
    void* portal = ((FUN_0042e2a0_shell*)static_cast<const TESObjectREFR*>(this)->GetExtra())->GetExtraNavMeshPortal();
    if (portal)
    {
        FUN_004534f0_shell* form = *(FUN_004534f0_shell**)((char*)portal + 0xc);
        if (form)
            form->FUN_004534f0((unsigned int)this);
        ((FUN_0042dec0_shell*)static_cast<const TESObjectREFR*>(this)->GetExtra())->ExtraDataList_RemoveNavMeshPortal();
    }
    (*(void(__thiscall**)(void*, unsigned int))(*(void***)this + 0x13))(this, 0x20000);
}

int DAT_0101fc8c;
struct ActorCombatGroup;
struct NiTMallocInterface_CombatGroup
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short size);
};
struct FUN_0057cb70_Class
{
    int* vtable;
    ActorCombatGroup** data;
    unsigned short m_iElementCount;
    unsigned short m_auiShapeKeys;
    unsigned short m_uiItemCount;
    unsigned short m_maxSize;
    FUN_0057cb70_Class(unsigned short size, unsigned short maxSize);
};
// @fnv 0x0057cb70
FUN_0057cb70_Class::FUN_0057cb70_Class(unsigned short size, unsigned short maxSize)
{
    vtable = &DAT_0101fc8c;
    m_iElementCount = size;
    m_maxSize = maxSize;
    m_auiShapeKeys = 0;
    m_uiItemCount = 0;
    if (m_iElementCount > 0)
        data = NiTMallocInterface_CombatGroup::Allocate(m_iElementCount);
    else
        data = 0;
}

struct RefH
{
    bool GetDisabled();
    void TESForm_SetDisabled(bool);
};
struct Fn56ac90
{
    BSSimpleList<BGSPerk*>* TESObjectREFR_GetEnableStateChildList();
};
struct FUN_0056ac00Class : RefH
{
    void TESObjectREFR_UpdateEnableStateChildrenFlagsRecursive();
};

// @fnv 0x0056ac00
// src: COMMUNITY 0x0056ac00
void FUN_0056ac00Class::TESObjectREFR_UpdateEnableStateChildrenFlagsRecursive()
{
    BSSimpleList<BGSPerk*>* list = ((Fn56ac90*)this)->TESObjectREFR_GetEnableStateChildList();
    while (list)
    {
        RefH* item = (RefH*)list->GetItem();
        if (item)
        {
            bool disabled = GetDisabled();
            if ((unsigned char)(unsigned int)((InventoryChanges*)item)->CreateForReference())
                disabled = !disabled;
            if (item->GetDisabled() != disabled)
            {
                item->TESForm_SetDisabled(disabled);
                ((FUN_0056ac00Class*)item)->TESObjectREFR_UpdateEnableStateChildrenFlagsRecursive();
            }
        }
        list = list->GetNext();
    }
}

extern NiRTTI DAT_012681c0;

bhkRigidBody* NiDynCast_S(const NiRTTI* rtti, bhkWorldObject* obj);

struct Counters_S
{
    unsigned char flags;
    int count04;
    int count08;
    int count0C;
    int unk10;
    int unk14;
    void* target;
};

struct Arg2_S
{
    int unk00;
    int unk04;
    int unk08;
    Counters_S* counters;
};

// Casts the object's world object to a rigid body and updates the counters' flags and counts based on its state.
// @fnv 0x00563120
// src: COMMUNITY 0x00563120
void TESObjectREFR_GatherHavokSaveDataForCollisionObject(bhkCollisionObject* pCollObj, Arg2_S* arg)
{
    Counters_S* counters3 = arg->counters;
    bhkWorldObject* world = pCollObj->bhkNiCollisionObject_GetWorldObject();
    if (world)
    {
        bhkRigidBody* body = NiDynCast_S(&DAT_012681c0, world);
        if (body)
        {
            if (pCollObj == counters3->target)
                counters3->flags |= 2;
            if (body->IsActive_005609b0())
                counters3->count04++;
            else
                counters3->count08++;
            if (body->bhkRigidBody_GetMotionType() == 4)
            {
                if (!body->IsNonZero(0x200))
                    counters3->count0C++;
            }
        }
    }
}

namespace fnv_00563220 {
struct Pt_S
{
    float x, y, z;
    Pt_S();
};
extern NiRTTI DAT_012681c0;
bhkRigidBody* NiObject_DynamicCast(const NiRTTI*, bhkWorldObject*);
struct SaveState
{
    unsigned char moving;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    bhkCollisionObject* object;
    BGSSaveFormBuffer* world;
};
struct SaveRequest
{
    int unk00;
    int unk04;
    int unk08;
    SaveState* buffer;
};
// @fnv 0x00563220
// src: XBOX_PDB 0x00563220
void TESObjectREFR_SaveHavokDataForCollisionObject(bhkCollisionObject* apCollisionObject, SaveRequest* request)
{
    SaveState* buffer = request->buffer;
    BGSSaveFormBuffer* world = buffer->world;
    bhkWorldObject* state = apCollisionObject->bhkNiCollisionObject_GetWorldObject();
    if (state)
    {
        bhkRigidBody* body = NiObject_DynamicCast(&DAT_012681c0, state);
        if (body)
        {
            if (apCollisionObject == buffer->object)
            {
            }
            else
            {
                Pt_S position;
                // The save record stores this vector with four-byte alignment.
                float rotation[4];
                reinterpret_cast<hkVector4*>(rotation)->hkVector4::hkVector4();
                body->bhkRigidBody_GetPosition(reinterpret_cast<NiPoint3&>(position));
                body->bhkRigidBody_GetRotation(reinterpret_cast<hkVector4&>(rotation));
                world->SaveData(&position, 12u, 0);
                world->SaveData(&rotation, 16u, 0);
            }
            unsigned char moving = 0;
            bool flags = body->IsActive_005609b0();
            if (buffer->moving & 4)
            {
                if (flags)
                    moving |= 1;
                if (body->bhkRigidBody_GetMotionType() == 4 && !body->IsNonZero(0x200))
                    moving |= 2;
                world->SaveData(&moving, 1u, 0);
            }
            if (flags)
            {
                Pt_S angular;
                Pt_S linear;
                body->bhkRigidBody_GetLinearVelocity(reinterpret_cast<NiPoint3&>(angular));
                body->bhkRigidBody_GetAngularVelocityNi(reinterpret_cast<NiPoint3&>(linear));
                world->SaveData(&angular, 12u, 0);
                world->SaveData(&linear, 12u, 0);
            }
        }
    }
}
}  // namespace fnv_00563220

extern NiRTTI g_rtti_bhkRigidBody_563380;

// Additional state operations used by this unit; layout and virtual slots come from the shared base.
struct RigidBodyStateAccess : bhkRigidBody
{
    void SetRotation(const NiQuaternion& q);
    void SetPosition(const LocalVec3& p);
    void SetLinearVelocity(const LocalVec3& v);
    void SetAngularVelocity(const LocalVec3& v);
    void Activate(bool active);
};
RigidBodyStateAccess* NiDynamicCast_563380(const NiRTTI* rtti, bhkWorldObject* obj);

struct LoadBuffer_563380
{
    void Read(void* dst, unsigned int size);
};
// Physics-load callback state: flags at +0x00, reference at +0x10, buffer at +0x1C (32 bytes); Data is 16 bytes.
struct PhysicsLoadState
{
    unsigned char flags;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0c;
    TESObjectREFR* ref;
    int unk14;
    int unk18;
    LoadBuffer_563380* buffer;
};
struct Param_563380
{
    int unk00;
    int unk04;
    int unk08;
    PhysicsLoadState* data;
};

// @fnv 0x00563380
// src: XBOX_PDB 0x00563380
void __cdecl TESObjectREFR_LoadHavokDataForCollisionObject_00563380(bhkCollisionObject* collObj, Param_563380* param)
{
    PhysicsLoadState* data7 = param->data;
    LoadBuffer_563380* buffer2 = data7->buffer;
    bhkWorldObject* worldObj2 = collObj->bhkNiCollisionObject_GetWorldObject();
    collObj->bhkNiCollisionObject_SetReset(false);
    if (worldObj2)
    {
        RigidBodyStateAccess* aBody = NiDynamicCast_563380(&g_rtti_bhkRigidBody_563380, worldObj2);
        if (aBody)
        {
            LocalVec3 pos4;
            NiQuaternion rot2;
            if (data7->flags & 2)
            {
                data7->flags &= ~2;
                reinterpret_cast<PositionBits&>(pos4) = *reinterpret_cast<const PositionBits*>(static_cast<const TESObjectREFR*>(data7->ref)->GetPos());
                rot2.FromRotationMatrix(data7->ref->GetRotation());
            }
            else
            {
                buffer2->Read(&pos4, 0xc);
                buffer2->Read(&rot2, 0x10);
            }
            aBody->RigidBodyStateAccess::SetRotation(rot2);
            aBody->SetPosition(pos4);
            bool setVel4 = false;
            if (data7->flags & 1)
                setVel4 = true;
            if (data7->flags & 4)
            {
                unsigned char extra5 = 0;
                buffer2->Read(&extra5, 1);
                if (extra5 & 1)
                    setVel4 = true;
                if (extra5 & 2)
                    aBody->vf57(hkpMotion::MOTION_KEYFRAMED);
            }
            if (setVel4)
            {
                LocalVec3 linVel;
                LocalVec3 angularVelocity;
                buffer2->Read(&linVel, 0xc);
                buffer2->Read(&angularVelocity, 0xc);
                aBody->SetLinearVelocity(linVel);
                aBody->SetAngularVelocity(angularVelocity);
                aBody->Activate(true);
            }
        }
    }
}

struct LoadedModel
{
    NiObject* GetObject3D();
};
struct ModelHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    NiPointer<LoadedModel> m_pRenderedNodeEntry;
};
struct HandleData
{
    char* ExtraDataList_GetLastFinishedSequence();
};
extern NiRTTI DAT_011f36ac;
extern const char* DAT_011977d8;
extern const char* DAT_01197820;
NiObject* NiDynamicCast(const NiRTTI* rtti, NiObject* obj);
int __cdecl _stricmp(const char*, const char*);

struct ReferenceAnimationAccess : TESObjectREFR
{
    bool TESObjectREFR_CheckSaveAnimation();
};

// @fnv 0x00563530
// src: COMMUNITY 0x00563530
bool ReferenceAnimationAccess::TESObjectREFR_CheckSaveAnimation()
{
    if (reinterpret_cast<HandleData*>(BSFile_GetDevice())->ExtraDataList_GetLastFinishedSequence())
        return true;
    if (!reinterpret_cast<ModelHolder*>(m_pRenderData))
        return false;
    if (!(LoadedModel*)reinterpret_cast<ModelHolder*>(m_pRenderData)->m_pRenderedNodeEntry)
        return false;
    NiControllerManager* pManager =
        (NiControllerManager*)NiDynamicCast(&DAT_011f36ac, ((LoadedModel*)reinterpret_cast<ModelHolder*>(m_pRenderData)->m_pRenderedNodeEntry)->GetObject3D());
    if (!pManager || !pManager->NiTimeController_GetActive())
        return false;
    unsigned int ItemUpdateArray = pManager->GetSequenceCount();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        NiControllerSequence* pForwardSequence = pManager->GetSequenceAt(i);
        if (pForwardSequence->GetState())
        {
            if (_stricmp(pForwardSequence->GetName(), DAT_011977d8) && _stricmp(pForwardSequence->GetName(), DAT_01197820))
                return true;
        }
    }
    return false;
}

struct SceneObject : FUN_0056af20_Class
{
    int FUN_00401170();
};
struct FUN_0056ae60_Class
{
    bool TESObjectREFR_GetRespawn();
    bool TESObjectREFR_IsLeveledCreature();
    SceneObject* BGSSaveFormBuffer_GetForm();
};
// Returns false if FUN_0056af40 is true; otherwise switches on the type from FUN_007af430 and calls GetFlag8 or IsFlag2Set on the object.
// @fnv 0x0056ae60
// src: XBOX_PDB 0x0056ae60
bool FUN_0056ae60_Class::TESObjectREFR_GetRespawn()
{
    bool result = false;
    if (!TESObjectREFR_IsLeveledCreature())
    {
        if (BGSSaveFormBuffer_GetForm())
        {
            switch (BGSSaveFormBuffer_GetForm()->FUN_00401170())
            {
            case 0x2a:
            case 0x2b: {
                SceneObject* object = BGSSaveFormBuffer_GetForm();
                if (object)
                {
                    result = reinterpret_cast<ABD_005f92d0*>(reinterpret_cast<char*>(object) + 0x30)->GetFlag8();
                }
            }
            break;
            case 0x1b: {
                SceneObject* object = BGSSaveFormBuffer_GetForm();
                if (object)
                {
                    result = object->IsFlag2Set();
                }
            }
            break;
            }
        }
    }
    return result;
}

struct Obj8
{
    void Init();
    unsigned int m_u00;
    unsigned int m_u04;
};

struct VisitorB
{
    void Visit(unsigned int index, Obj8* obj);
};

struct FetcherC
{
    void* Fetch(unsigned int index);
};

void FUN_00553fc0_sink(void* value, Obj8* obj);

// Initializes an Obj8, then for indices 0..2 calls Visit on the visitor and passes Fetch's result with the object to a sink; returns the fetcher.
// @fnv 0x0056dff0
void* VisitAndFetchThree(FetcherC* pFetcher, VisitorB* pVisitor)
{
    char guard[4];
    Obj8 obj;
    obj.Init();
    for (unsigned int i = 0; i < 3; i++)
    {
        pVisitor->Visit(i, &obj);
        FUN_00553fc0_sink(pFetcher->Fetch(i), &obj);
    }
    return pFetcher;
}

// Sets flag A and flag B to 1, then calls Reset with 0, 0.
struct ReferenceReset : TESObjectREFR
{
    void TESObjectREFR_MarkAsDeleted();
};

// @fnv 0x00572270
// src: XBOX_PDB 0x00572270
void ReferenceReset::TESObjectREFR_MarkAsDeleted()
{
    MarkForDeletion(true);
    SetAltered(true);
    Set3D(0, false);
}

// Stand-in base with a trivial destructor, 0x14 bytes.
struct FUN_0057c3a0_BaseA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// Stand-in base with a non-trivial destructor, 4 bytes.
struct FUN_0057c3a0_BaseB
{
    int unk00;
    ~FUN_0057c3a0_BaseB();
};

struct FUN_0057c3a0_cls : FUN_0057c3a0_BaseA, FUN_0057c3a0_BaseB
{
    FUN_0057c3a0_BaseB m_kMemberDescriptor;
    ~FUN_0057c3a0_cls();
};

// Destructor for the class; destroys its base subobjects and the embedded base member.
// @fnv 0x0057c3a0
FUN_0057c3a0_cls::~FUN_0057c3a0_cls()
{}

struct DtorBase_57c930 : FUN_0057c930_class
{
    virtual __forceinline ~DtorBase_57c930()
    {
        SetVtableAndProcessState_0057c930();
    }
};
struct FUN_0057c8d0 : DtorBase_57c930
{
    virtual ~FUN_0057c8d0();
    void __thiscall FUN_00438af0();
};
// Destructor that calls FUN_00438af0 before the base destructor runs.
// @fnv 0x0057c8d0
FUN_0057c8d0::~FUN_0057c8d0()
{
    FUN_00438af0();
}

struct Base_57c9d0
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;

    ~Base_57c9d0();
};

class FUN_0057c9d0_cls : public Base_57c9d0
{
  public:
    virtual ~FUN_0057c9d0_cls();
    void Body();
};

// @fnv 0x0057c9d0
FUN_0057c9d0_cls::~FUN_0057c9d0_cls()
{
    Body();
}

struct FlagCls
{
    bool m_kPointB;
    int Get(void* owner);
};
struct SinkCls
{
    void Put(int v);
};
struct FUN_0057caf0_cls
{
    void hkArray_hkWorldObjectCinfo_Property_hkContainerHeapAllocator_clearAndDeallocate();
};
// @fnv 0x0057caf0
// src: XBOX_PDB 0x0057caf0
void FUN_0057caf0_cls::hkArray_hkWorldObjectCinfo_Property_hkContainerHeapAllocator_clearAndDeallocate()
{
    FlagCls flag = {};
    reinterpret_cast<SinkCls*>(this)->Put(flag.Get(this));
}

struct PSPoint3
{
    float x;
    float y;
    float z;

    PSPoint3();
};

struct PSForm
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
    virtual bool IsActorBase();
};

// The shared collision type has no declaration for this scene-object getter.
struct CollisionSceneAccess : bhkCollisionObject
{
    NiAVObject* GetSceneObject();
};
struct PSSaveInfo
{
    unsigned char m_ucEntryType;
    unsigned char pad01[3];
    int unk04;
    PSForm* pBaseForm;
    int unk0C;
    bhkCollisionObject* pRef;
};

struct PSSaveContext
{
    int unk00;
    int unk04;
    int unk08;
    PSSaveInfo* pInfo;
};

struct PSSaveLoadGame
{
    void Write(void* apData, int aiSize);
};

extern PSSaveLoadGame* g_pPSSaveLoadGame;
extern NiRTTI g_kPSRTTI_Excluded;
extern NiRTTI g_kPSRTTI_RigidBody;

int __cdecl PSStricmp(const char* apString1, const char* apString2);
bool __cdecl PSIsKindOf(const NiRTTI* apRTTI, NiAVObject* apObject);
bhkRigidBody* __cdecl PSDynamicCast(const NiRTTI* apRTTI, bhkWorldObject* apObject);

// @fnv 0x00560a10
// src: XBOX_PDB 0x00560a10
void __cdecl TESObjectREFR_SaveHavokDataForCollisionObjectOld(bhkCollisionObject* apRef, PSSaveContext* apContext)
{
    PSSaveInfo* pInfo = apContext->pInfo;
    NiAVObject* p3D = reinterpret_cast<CollisionSceneAccess*>(apRef)->GetSceneObject();
    if (apRef != pInfo->pRef && p3D && (const char*)p3D->GetName() && !PSStricmp(p3D->GetName(), "Arrow"))
        return;
    if (pInfo->pBaseForm->IsActorBase() && PSIsKindOf(&g_kPSRTTI_Excluded, p3D))
        return;

    bhkWorldObject* pCollision_ = apRef->bhkNiCollisionObject_GetWorldObject();
    if (pCollision_)
    {
        bhkRigidBody* pBody6 = PSDynamicCast(&g_kPSRTTI_RigidBody, pCollision_);
        if (pBody6)
        {

            if (apRef == pInfo->pRef)
            {
            }
            else
            {
                PSPoint3 kPosition3;
                float kRotationBasis[4];
                reinterpret_cast<hkVector4*>(kRotationBasis)->hkVector4::hkVector4();
                pBody6->bhkRigidBody_GetPosition(reinterpret_cast<NiPoint3&>(kPosition3));
                pBody6->bhkRigidBody_GetRotation(reinterpret_cast<hkVector4&>(kRotationBasis));
                g_pPSSaveLoadGame->Write(&kPosition3, 0xc);
                g_pPSSaveLoadGame->Write(&kRotationBasis, 0x10);
            }

            bool bActive2 = pBody6->IsActive_005609b0();
            if (pInfo->m_ucEntryType & 4)
                g_pPSSaveLoadGame->Write(&bActive2, 1);
            if (bActive2)
            {
                PSPoint3 kLinearVelocity5;
                PSPoint3 kAngularVelocity4;
                pBody6->bhkRigidBody_GetLinearVelocity(reinterpret_cast<NiPoint3&>(kLinearVelocity5));
                pBody6->bhkRigidBody_GetAngularVelocityNi(reinterpret_cast<NiPoint3&>(kAngularVelocity4));
                g_pPSSaveLoadGame->Write(&kLinearVelocity5, 0xc);
                g_pPSSaveLoadGame->Write(&kAngularVelocity4, 0xc);
            }
        }
    }
}



class B5695A0Culler
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual int TestBound(const NiBound& kBound);
};

class B5695A0Camera
{
  public:
    B5695A0Culler* GetCuller();
};

struct ReferenceVisibility : TESObjectREFR
{
    bool TESObjectREFR_CheckBound(B5695A0Camera* pkCamera);
};

// @fnv 0x005695a0
// src: COMMUNITY 0x005695a0
bool ReferenceVisibility::TESObjectREFR_CheckBound(B5695A0Camera* pkCamera)
{
    NiAVObject* pk3D = GetNiNode();
    if (!pk3D->IsVisualObject())
        return false;
    bool bVisible9 = pk3D ? pkCamera->GetCuller()->TestBound(pk3D->GetBoundingVolume()) == 2 : false;
    return bVisible9;
}

struct SoundData57
{
    unsigned int frequency, flags, minDistance, maxDistance, staticAttenuation;
    unsigned int startTime, endTime, attenuation, priority;
};
struct Sound57
{
    SoundData57 CopyBig();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct SoundRecord57
{
    Sound57* GetField54();
};
struct SoundLookup57
{
    SoundRecord57* FUN_004617e0(const char*);
};
extern SoundLookup57* g_dataHandler;
struct Audio57
{
    BSSoundHandle GetSoundHandleByFormID_00ad73b0(unsigned int, unsigned int);
};
Audio57* BSAudio_QInstance();
unsigned int GetFlagMask(unsigned int);
struct FUN_004f91b0
{
    unsigned int vtable, refCount, name;
    BSSoundHandle handle;
    FUN_004f91b0();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void IncRefCount();
    void DecRefCount();
};
extern NiRTTI g_01202de8;
bool NiObject_IsKindOf(const NiRTTI*, NiAVObject*);
const NiFixedString& BGSAddonNodeSoundHandleExtra_Tag();
struct SceneSounds57
{
    void TESObjectREFR_UpdateAddonNodeSoundsRecursive(NiAVObject*, bool);
};
// @fnv 0x0057a410
// src: XBOX_PDB 0x0057a410
void SceneSounds57::TESObjectREFR_UpdateAddonNodeSoundsRecursive(NiAVObject* object, bool stop)
{
    if (!object)
        return;
    if (object->GetAppCulled_00456610())
        stop = true;
    if (NiObject_IsKindOf(&g_01202de8, object))
    {
        NiAVObject* soundObject = object;
        SoundRecord57* record = g_dataHandler->FUN_004617e0(soundObject->DialoguePackage_GetActorStartedConversation());
        if (record && record->GetField54())
        {
            NiPointer<FUN_004f91b0> extra(reinterpret_cast<FUN_004f91b0*>(object->FUN_00a5bdd0(BGSAddonNodeSoundHandleExtra_Tag())));
            if (stop)
            {
                if (extra.operator->())
                {
                    object->DeleteExtraDataByKey(BGSAddonNodeSoundHandleExtra_Tag());
                    extra->handle.Stop();
                    extra->handle.Release();
                }
            }
            else if (!extra.operator->())
            {
                extra = new FUN_004f91b0;
                PositionBits position;
                unsigned int flags = GetFlagMask(record->GetField54()->CopyBig().flags)
                                         ? (GetFlagMask(record->GetField54()->CopyBig().flags) | 2)
                                         : 0x102;
                extra->handle.operator=(BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0(record->GetField54()->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), flags));
                extra->handle.SetObjectToFollow(object);
                position = reinterpret_cast<const PositionBits&>(object->NiAVObject_GetWorldTranslate());
                extra->handle.SetPosition(*(float*)&position.words[0], *(float*)&position.words[1], *(float*)&position.words[2]);
                extra->handle.Play(false);
                object->SetExtraDataName(reinterpret_cast<NiExtraData*>(extra.operator->()));
            }
        }
    }
    NiNode* node = object->IsSceneNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
        {
            NiAVObject* child = node->GetAt(i);
            if (child)
                TESObjectREFR_UpdateAddonNodeSoundsRecursive(child, stop);
        }
    }
}

struct SmartPointer
{
    void* object;
    SmartPointer(const SmartPointer&);
    ~SmartPointer();
};
struct PointerList : FUN_0057c6a0Class
{
    SmartPointer RemovePos(void*& position);
    SmartPointer NiTPointerListBase_NiPropertyPtr_Remove(const SmartPointer& key);
};
// @fnv 0x0057c5d0
// src: COMMUNITY 0x0057c5d0
SmartPointer PointerList::NiTPointerListBase_NiPropertyPtr_Remove(const SmartPointer& key)
{
    void* position = NiTPointerListBase_NiPropertyPtr_FindPos((void*)&key, 0);
    return position ? RemovePos(position) : key;
}

struct FUN_00483710
{
    ~FUN_00483710();
};
struct FUN_0057c530 : FUN_00483710
{
    void hkArray_hkWorldObjectCinfo_Property_hkContainerHeapAllocator_clearAndDeallocate();
    ~FUN_0057c530();
};
// @fnv 0x0057c530
FUN_0057c530::~FUN_0057c530()
{
    hkArray_hkWorldObjectCinfo_Property_hkContainerHeapAllocator_clearAndDeallocate();
}

class QueueValue
{
  public:
    QueueValue(const QueueValue& src);
    ~QueueValue();
    void* m_pObject;
};

typedef NiTListItem<QueueValue > QueueItem;

class FUN_0057cc40_cls
{
  public:
    QueueItem* m_pkHead;
    QueueItem* m_pkTail;
    unsigned int m_uiCount;
    void DeleteItem(QueueItem* item);
    QueueValue PopBack();
};

// Removes the tail item from the queue, copies its element, deletes the item, decrements the count and returns the copied element.
// @fnv 0x0057cc40
QueueValue FUN_0057cc40_cls::PopBack()
{
    QueueItem* item = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail != 0)
    {
        m_pkTail->m_pkNext = 0;
    }
    else
    {
        m_pkHead = 0;
    }
    QueueValue element(item->m_element);
    DeleteItem(item);
    m_uiCount = m_uiCount - 1;
    return element;
}

struct ExtraFlagAccess : ExtraDataList
{
    void ExtraDataList_SetLeveledCreature(int, int);
};
struct ReferenceStateAccess : TESObjectREFR
{
    void FUN_00484b90(unsigned int);
    void TESObjectREFR_SetLeveledCreature(int, int);
};

// @fnv 0x0056b020
// src: COMMUNITY 0x0056b020
void ReferenceStateAccess::TESObjectREFR_SetLeveledCreature(int iA, int iB)
{
    if (BGSSaveFormBuffer_GetForm() && BGSSaveFormBuffer_GetForm()->Unk_3E())
    {
        if (iA && iB)
        {
            FUN_00484b90(0x40000);
        }
        else
        {
            MarkAsUnmodified(0x40000);
        }
        reinterpret_cast<ExtraFlagAccess*>(BSFile_GetDevice())->ExtraDataList_SetLeveledCreature(iA, iB);
    }
}

struct PointerMapBase57c780
{
    virtual void Slot00();
    ~PointerMapBase57c780();
};

struct FUN_0057c780 : PointerMapBase57c780
{
    void FUN_00438af0();
    ~FUN_0057c780();
};

// Destructor that calls FUN_00438af0.
// @fnv 0x0057c780
FUN_0057c780::~FUN_0057c780()
{
    FUN_00438af0();
}

struct Scene
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
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
    virtual void v60();
    virtual void v61();
    virtual bool vf();
};

struct Sub
{
    bool ExtraDataList_HasLevCreaCalced();
};

struct Thing
{
    Scene* BGSSaveFormBuffer_GetForm();
    Sub* BSFile_GetDevice();
    bool TESObjectREFR_HasLeveledCreatureCalced();
};

// Returns true if the scene pointer is valid, its vf() check passes, and the Sub object's FUN_004216d0() returns true.
// @fnv 0x0056afc0
// src: XBOX_PDB 0x0056afc0
bool Thing::TESObjectREFR_HasLeveledCreatureCalced()
{
    bool result = false;
    if (BGSSaveFormBuffer_GetForm() != 0 && BGSSaveFormBuffer_GetForm()->vf())
    {
        result = BSFile_GetDevice()->ExtraDataList_HasLevCreaCalced();
    }
    return result;
}

#include <xmmintrin.h>
extern float DAT_010c71b0;

struct Base_56d250
{
    void* FUN_006815c0();
};
void* Base_56d250::FUN_006815c0()
{
    return this;
}

struct C_56d250 : Base_56d250
{
    __m128 m_vComponents;
    void ForwardCall_0056d250();
};
// Copies the 16 bytes at DAT_010c71b0 to the address returned by FUN_006815c0().
// @fnv 0x0056d250
// src: GUESS 0x0056d250 (confidence: low)
void C_56d250::ForwardCall_0056d250()
{
    *(__m128*)FUN_006815c0() = *(const __m128*)&DAT_010c71b0;
}

// @fnv 0x00560d10
// src: GUESS 0x00560d10 (confidence: medium)
float& FUN_00560d10_shell::GetVectorElement_Thunk(unsigned int i)
{
    return reinterpret_cast<bhkCharacterController*>(this)->GetVectorElement(i);
}

struct FUN_00576870_class
{
    void* __thiscall ZoneEntry_GetZoneEntry_0(void*);
};
// Calls FUN_00576870 on the object at offset 4 when that pointer is non-null, passing p, and returns the result or 0.
// @fnv 0x00576830
// src: COMMUNITY 0x00576830
void* FUN_00576830_shell::BGSZoneTargetListener_GetZoneEntry(BSOcclusionPlane* apOcclusionPlane)
{
    return *(FUN_00576870_class**)((char*)this + 4)
               ? (*(FUN_00576870_class**)((char*)this + 4))->ZoneEntry_GetZoneEntry_0(apOcclusionPlane)
               : 0;
}

struct FUN_0057c4d0
{
    virtual ~FUN_0057c4d0();
};
typedef FUN_0057c4d0 FUN_0056aac0_map;
// @fnv 0x0057c4d0
FUN_0057c4d0::~FUN_0057c4d0()
{}
