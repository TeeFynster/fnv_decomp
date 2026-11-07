#include "../../include/NiTListItem.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTPointerMap.h"

// src/staging/blk_004a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BGSBodyPart.h"
#include "../../include/BGSPrimitiveBox.h"
#include "../../include/BSAudio.h"
#include "../../include/GO.h"
#include "../../include/MapEntryCount.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}

inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}

inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../include/NiPoint3.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTriShape.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint3.h"
#include "../../include/RecursiveSpinLock.h"
#include "../../include/NiColorA.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESForm.h"
#include "../../include/TESSound.h"
#include "../../include/NiMatrix3.h"
#include "../../include/NiMemObject.h"

#include "../../include/BSShaderNoLightingProperty.h"

#pragma pack(push, 4)

#include "../../include/NiTMapItem.h"

template <> NiTPointerMap<NiObject*, NiObject*>::~NiTPointerMap();
template <> NiTPointerMap<NiObject*, bool>::~NiTPointerMap();

// The shared pointer exposes storage and lifetime operations; these comparison
// entry points preserve the game's out-of-line pointer comparisons.
template <class T> struct NiPointerComparisons
{
    bool Equals(T* object) const;
    bool Differs(const NiPointer<T>& other) const;
};

template <class T> NiPointer<T>::NiPointer(T* pkNew)
{
    m_pObject = pkNew;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> NiPointer<T>::NiPointer(const NiPointer<T>& kSrc)
{
    m_pObject = kSrc.m_pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class T> NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

extern int DAT_011c57e4;
extern int DAT_011c57e8;

// @fnv 0x004a0010
// src: COMMUNITY 0x004a0010
void __cdecl BGSDecalManager_ClearDecalsThisFrame()
{
    DAT_011c57e4 = 0;
    DAT_011c57e8 = 0;
}

struct FUN_004a0d60_Class
{
    char pad[0x40];
    NiPoint3 m_kPoint;
    NiPoint3& BSTempEffectSimpleDecal_GetDirection(NiPoint3& arDest);
};

// Copies the stored point into arDest and returns arDest.
// @fnv 0x004a0d60
// src: COMMUNITY 0x004a0d60
NiPoint3& FUN_004a0d60_Class::BSTempEffectSimpleDecal_GetDirection(NiPoint3& arDest)
{
    // Preserve the game's bitwise point copy independently of shared NiPoint3 assignment declarations.
    reinterpret_cast<NiPoint3&>(arDest) = reinterpret_cast<const NiPoint3&>(m_kPoint);
    return arDest;
}

struct FUN_004a0d90_Class
{
    float __thiscall GetField11C();
};

// @fnv 0x004a0d90
float __thiscall FUN_004a0d90_Class::GetField11C()
{
    return *(float*)((char*)this + 0x11c);
}

struct FUN_004a0db0_class
{
    float __thiscall GetFloatAt120();
};
// @fnv 0x004a0db0
float __thiscall FUN_004a0db0_class::GetFloatAt120()
{
    return *(float*)((char*)this + 0x120);
}

void* __fastcall hkpShapeRayCastOutput_hkpShapeRayCastOutput(void* self);

// Calls FUN_004a3d20 on self, sets the int at offset 0x50 to 0, and returns self.
// @fnv 0x004a3d00
// src: XBOX_PDB 0x004a3d00
void* __fastcall hkpWorldRayCastOutput_hkpWorldRayCastOutput(void* self)
{
    hkpShapeRayCastOutput_hkpShapeRayCastOutput(self);
    *(int*)((char*)self + 0x50) = 0;
    return self;
}

struct FUN_004a3d40_class
{
    void __thiscall _ref_006815c0();
    void __thiscall hkpShapeRayCastCollectorOutput_reset();
    FUN_004a3d40_class* __thiscall hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput();
};
// @fnv 0x004a3d40
// src: XBOX_PDB 0x004a3d40
FUN_004a3d40_class* __thiscall FUN_004a3d40_class::hkpShapeRayCastCollectorOutput_hkpShapeRayCastCollectorOutput()
{
    _ref_006815c0();
    hkpShapeRayCastCollectorOutput_reset();
    return this;
}

struct FUN_004a3d60_class
{
    void hkpShapeRayCastCollectorOutput_reset();
};

// @fnv 0x004a3d60
// src: XBOX_PDB 0x004a3d60
void FUN_004a3d60_class::hkpShapeRayCastCollectorOutput_reset()
{
    *(float*)((char*)this + 0x10) = 1.0f;
    *(int*)((char*)this + 0x14) = -1;
}

struct FUN_004a3d80_Class
{
    void __thiscall hkpShapeRayCastOutput__reset();
};

// @fnv 0x004a3d80
// src: XBOX_PDB 0x004a3d80
void __thiscall FUN_004a3d80_Class::hkpShapeRayCastOutput__reset()
{
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x20) = -1;
}

extern float runtimeInitializationFloat2123;

// @fnv 0x004a3e90
// src: XBOX_PDB 0x004a3e90
float NI2HK_004a3e90(float value)
{
    return runtimeInitializationFloat2123 * value;
}

struct RegionPoint
{
    float GetX();
};

struct FUN_004a40a0_Class
{
    float BGSImpactData_GetDecalMinWidth();
};

// @fnv 0x004a40a0
// src: XBOX_PDB 0x004a40a0
float FUN_004a40a0_Class::BGSImpactData_GetDecalMinWidth()
{
    return ((RegionPoint*)((char*)this + 0x54))->GetX();
}

struct Modifier
{
    float GetValue();
};
struct FUN_004a40c0_Class
{
    float GetModifierValue();
};
// @fnv 0x004a40c0
float FUN_004a40c0_Class::GetModifierValue()
{
    return ((Modifier*)((char*)this + 0x54))->GetValue();
}

struct FUN_004a4120_class
{
    char ImpactDecalData_GetIsParallax();
};

// @fnv 0x004a4120
// src: COMMUNITY 0x004a4120
char FUN_004a4120_class::ImpactDecalData_GetIsParallax()
{
    return (((const unsigned char*)this)[0x1d] & 1) != 0;
}

struct FUN_004a4160_Class
{
    bool ImpactDecalData_GetIsAlphaBlend();
};

// @fnv 0x004a4160
// src: COMMUNITY 0x004a4160
bool FUN_004a4160_Class::ImpactDecalData_GetIsAlphaBlend()
{
    return reinterpret_cast<unsigned char*>(this)[0x1d] & 2;
}

struct FUN_004a41a0_Class
{
    bool GetMaskedValue4();
};
// @fnv 0x004a41a0
// src: GUESS 0x004a41a0 (confidence: medium)
bool FUN_004a41a0_Class::GetMaskedValue4()
{
    return ((unsigned char*)this)[0x1d] & 4;
}

struct FUN_004a4200_class
{
    unsigned short DecalData_GetParallaxPasses();
};

// @fnv 0x004a4200
// src: COMMUNITY 0x004a4200
unsigned short FUN_004a4200_class::DecalData_GetParallaxPasses()
{
    return ((unsigned char*)this)[0x1c];
}

struct MersenneTwister
{
    static MersenneTwister* GetRandomGenerator();
    void* BSRandom_FloatTwoPi();
};

// @fnv 0x004a4240
// src: XBOX_PDB 0x004a4240
void* RandomFloatTwoPi()
{
    return MersenneTwister::GetRandomGenerator()->BSRandom_FloatTwoPi();
}

struct FUN_004a4440_Class
{
    void __thiscall FUN_004a46d0();
    void __thiscall ForwardCall_004a4440();
};

// @fnv 0x004a4440
// src: GUESS 0x004a4440 (confidence: low)
void __thiscall FUN_004a4440_Class::ForwardCall_004a4440()
{
    FUN_004a46d0();
}

extern "C" BSAudio* __cdecl hkMemoryRouter_getInstance();
struct FUN_004a4840_class
{
    void hkContainerHeapAllocator_get(int unused);
};
// @fnv 0x004a4840
// src: XBOX_PDB 0x004a4840
void FUN_004a4840_class::hkContainerHeapAllocator_get(int unused)
{
    hkMemoryRouter_getInstance()->GetAudioBackendData();
}

struct FUN_004a49e0_shell
{
    void __thiscall Deallocate(void* p);
    void __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSOcclusionPlane_DeleteItem(void* item);
};

// Clears the int at offset 8 of item, then calls Deallocate on the object at this+8 to free it.
// @fnv 0x004a49e0
// src: XBOX_PDB 0x004a49e0
void __thiscall FUN_004a49e0_shell::NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSOcclusionPlane_DeleteItem(void* item)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(item) + 8) = 0;
    reinterpret_cast<FUN_004a49e0_shell*>(reinterpret_cast<char*>(this) + 8)->Deallocate(item);
}

struct FUN_004a5250_shell
{
    void* AssignFromBound(void*);
};
struct FUN_004a5230_class
{
    void __thiscall ForwardToMember(void* arg);
};
// @fnv 0x004a5230
void __thiscall FUN_004a5230_class::ForwardToMember(void* arg)
{
    ((FUN_004a5250_shell*)((char*)this + 0x10))->AssignFromBound(arg);
}

struct Flt
{
    operator unsigned int();
};

struct FUN_004a8ab0_shell
{
    unsigned short GetActorBaseFatigue();
};
// Reads a float at offset 0xb8, converts it to an unsigned int, and returns GetFatigue() from the TESActorBaseData at that address.
// @fnv 0x004a8ab0
unsigned short FUN_004a8ab0_shell::GetActorBaseFatigue()
{
    unsigned int u = ((Flt*)((char*)this + 0xb8))->operator unsigned int();
    return ((TESActorBaseData*)u)->GetFatigue();
}

struct FUN_004a9950_Class
{
    void __thiscall SetValue(int a, int b, char c);
};
// @fnv 0x004a9950
void __thiscall FUN_004a9950_Class::SetValue(int a, int iValue, char c)
{
    *(int*)((char*)a + 4) = iValue;
    *(char*)((char*)a + 8) = c;
}

extern int DAT_0101ed6c;
struct FUN_004a9bf0_class
{
    void NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool_NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool(int);
    void* NiTMap_NiTexture_bool_NiTMap(int);
};
// Calls FUN_004a9c50 with a, stores the address of DAT_0101ed6c at this, and returns this.
// @fnv 0x004a9bf0
// src: EXE 0x004a9bf0
void* FUN_004a9bf0_class::NiTMap_NiTexture_bool_NiTMap(int a)
{
    NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool_NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool(a);
    *reinterpret_cast<void**>(this) = &DAT_0101ed6c;
    return this;
}

extern "C" void* DAT_0101edac;

struct FUN_004a9d80_class
{
    void* vtable;
    void UpdateFields_004a9e00(int, int);
    FUN_004a9d80_class* SetVirtualTableAndProcessState_004a9d80();
};

// Sets the vtable to DAT_0101edac, calls FUN_004a9e00 with 0, 0, and returns this.
// @fnv 0x004a9d80
// src: GUESS 0x004a9d80 (confidence: low)
FUN_004a9d80_class* FUN_004a9d80_class::SetVirtualTableAndProcessState_004a9d80()
{
    vtable = &DAT_0101edac;
    UpdateFields_004a9e00(0, 0);
    return this;
}

namespace fnv_004a9de0 {
extern int DAT_0101edac;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_004a9de0_class
{
    int* p;
    void ResetVirtualTableAndClear_004a9de0();
};
// @fnv 0x004a9de0
// src: GUESS 0x004a9de0 (confidence: medium)
void FUN_004a9de0_class::ResetVirtualTableAndClear_004a9de0()
{
    p = (int*)&DAT_0101edac;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_004a9de0

extern int DAT_0101edc0;
struct FUN_004a9e90_cls
{
    void* m_p;
    void NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool_NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool(int a);
    FUN_004a9e90_cls* NiTMap_TESActorBase_bool_NiTMap(int a);
};
// Calls FUN_004a9ef0 with a, sets m_p to DAT_0101edc0, and returns this.
// @fnv 0x004a9e90
// src: EXE 0x004a9e90
FUN_004a9e90_cls* FUN_004a9e90_cls::NiTMap_TESActorBase_bool_NiTMap(int a)
{
    NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool_NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool(a);
    m_p = &DAT_0101edc0;
    return this;
}

extern int DAT_0101ee00;
struct FUN_004aa020_class
{
    void NiTMapBase_DFALL_NiTMapItem_int_int_int_int_NiTMapBase_DFALL_NiTMapItem_int_int_int_int(int);
    int* m_p;
    FUN_004aa020_class* __thiscall NiTMap_int_int_NiTMap(int a);
};
// Calls FUN_004aa080 with a, sets m_p to point at DAT_0101ee00, and returns this.
// @fnv 0x004aa020
// src: EXE 0x004aa020
FUN_004aa020_class* __thiscall FUN_004aa020_class::NiTMap_int_int_NiTMap(int a)
{
    NiTMapBase_DFALL_NiTMapItem_int_int_int_int_NiTMapBase_DFALL_NiTMapItem_int_int_int_int(a);
    m_p = &DAT_0101ee00;
    return this;
}

extern int DAT_0101ee40;
void __cdecl NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int_NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int(int);

struct FUN_004aa1b0_class
{
    void __thiscall NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int_NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int(int);
    int* p;
    FUN_004aa1b0_class* __thiscall NiTMap_ShadowSceneLight_int_NiTMap(int a);
};

// Calls FUN_004aa210 with a, sets p to point at DAT_0101ee40, and returns this.
// @fnv 0x004aa1b0
// src: EXE 0x004aa1b0
FUN_004aa1b0_class* __thiscall FUN_004aa1b0_class::NiTMap_ShadowSceneLight_int_NiTMap(int a)
{
    NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int_NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int(a);
    p = &DAT_0101ee40;
    return this;
}

// RTTI at vftable 0x0101fb8c identifies the pointer-to-pointer map.
// @fnv 0x004afb20
template <>
NiTPointerMap<NiObject*, NiObject*>::NiTPointerMap(unsigned int uiHashSize)
    : NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*>(uiHashSize)
{}

// RTTI at vftable 0x0101fbac identifies the pointer-to-bool map.
// @fnv 0x004afb50
template <>
NiTPointerMap<NiObject*, bool>::NiTPointerMap(unsigned int uiHashSize)
    : NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>(uiHashSize)
{}

struct FUN_004afb80_shell
{
    void LockAtOffset();
};
// @fnv 0x004afb80
void FUN_004afb80_shell::LockAtOffset()
{
    ((RecursiveSpinLock*)((char*)this + 0x20))->Lock(0);
}

namespace fnv_004afba0 {

struct FUN_004afba0_class
{
    void UnlockAtOffset();
};

// @fnv 0x004afba0
void FUN_004afba0_class::UnlockAtOffset()
{
    ((RecursiveSpinLock*)((char*)this + 0x20))->BSSpinLock_Unlock();
}
}  // namespace fnv_004afba0

extern "C" void* DAT_0101fbcc;
void __cdecl j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(int);
struct FUN_004afc20
{
    void* vtbl;
    int data;
    void Init();
};
// Sets the object's vtbl to DAT_0101fbcc and calls FUN_004b0220 with data.
// @fnv 0x004afc20
void FUN_004afc20::Init()
{
    vtbl = &DAT_0101fbcc;
    j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(data);
}

struct FUN_004b0130_shell
{
    unsigned int vfn_00;
    unsigned int vfn_04;
    unsigned int vfn_08;
    unsigned int vfn_0c;
    unsigned int vfn_10;
    void __thiscall Deallocate(void*);
    void __thiscall ClearAndDeallocate(void* p);
};
// Clears the byte at offset 8 of p, then calls Deallocate on the object at this+0xc with p.
// @fnv 0x004b0130
void __thiscall FUN_004b0130_shell::ClearAndDeallocate(void* p)
{
    *(char*)((char*)p + 8) = 0;
    ((FUN_004b0130_shell*)((char*)this + 0xc))->Deallocate(p);
}

struct FUN_004b0460_class
{
    void* m_p;
    bool LightRefData_IsEqual(const void** other);
};

// @fnv 0x004b0460
// src: COMMUNITY 0x004b0460
bool FUN_004b0460_class::LightRefData_IsEqual(const void** other)
{
    return m_p == *other;
}

extern int DAT_0101fc80;

struct FUN_004b0530_Class
{
    void __thiscall SetVtableAndProcessState_004b0530();
};

// @fnv 0x004b0530
// src: GUESS 0x004b0530 (confidence: low)
void __thiscall FUN_004b0530_Class::SetVtableAndProcessState_004b0530()
{
    *(int*)this = (int)&DAT_0101fc80;
}

struct FUN_004b1030_Class
{
    unsigned short __thiscall Date_GetDate();
};

// @fnv 0x004b1030
// src: COMMUNITY 0x004b1030
unsigned short __thiscall FUN_004b1030_Class::Date_GetDate()
{
    return *(unsigned short*)this;
}

extern "C" const short DAT_01188ecc[];

// @fnv 0x004b10d0
short __cdecl GetShortFromTable(int index)
{
    if (index >= 0xc)
        return 0;
    return DAT_01188ecc[index];
}

float __cdecl fmodf(float, float);

// @fnv 0x004b1500
// src: XBOX_PDB 0x004b1500
float __cdecl fmod_004b1500(float a, float b)
{
    return fmodf(a, b);
}

extern int DAT_011aa050;

// @fnv 0x004b4a10
// src: COMMUNITY 0x004b4a10
int __cdecl NiProcessorSpecificCode_ms_pPointsTransform_(unsigned short a1, int a2, int a3, int a4)
{
    return ((int(__cdecl*)(unsigned short, int, int, int)) * (&DAT_011aa050))(a1, a2, a3, a4);
}

struct FUN_004b4ab0_Class
{
    void __thiscall hkVector4_setRotatedInverseDir(int a, int b);
    void __thiscall hkVector4__setRotatedInverseDir(int a, int b);
};

// @fnv 0x004b4ab0
// src: COMMUNITY 0x004b4ab0
void __thiscall FUN_004b4ab0_Class::hkVector4_setRotatedInverseDir(int a, int b)
{
    hkVector4__setRotatedInverseDir(a, b);
}

extern "C" double __cdecl atan2(double, double);

// Returns the atan2 of a and b, computed in double precision and cast back to float.
// @fnv 0x004b5590
// src: COMMUNITY 0x004b5590
float atan2f(float afY, float afX)
{
    return (float)atan2((double)afY, (double)afX);
}

// If p is non-null, calls p->Deallocate() and returns its result; otherwise returns 0.
// @fnv 0x004b5aa0
unsigned int DeallocateIfPresent(TESSound* apSound)
{
    unsigned int result;
    if (apSound)
    {
        result = apSound->Deallocate();
    }
    else
    {
        result = 0;
    }
    return result;
}

extern int DAT_010205b4;
struct FUN_004b9950_class
{
    int* p;
    void NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist(int arg);
    FUN_004b9950_class* NiTMap_unsigned_int_VertexDist_NiTMap(int arg);
};
// Calls FUN_004b99b0 with arg, sets p to point at DAT_010205b4, and returns this.
// @fnv 0x004b9950
// src: EXE 0x004b9950
FUN_004b9950_class* FUN_004b9950_class::NiTMap_unsigned_int_VertexDist_NiTMap(int arg)
{
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist(arg);
    p = &DAT_010205b4;
    return this;
}

struct FUN_004b9de0_class
{
    void FUN_004b9de0();
};

struct FUN_004b9d60_class
{
    void ForwardCall_004b9d60();
};

// @fnv 0x004b9d60
// src: GUESS 0x004b9d60 (confidence: low)
void FUN_004b9d60_class::ForwardCall_004b9d60()
{
    ((FUN_004b9de0_class*)((char*)this + 0xc))->FUN_004b9de0();
}

struct Unk65
{
    void FUN_0065de30(int);
};
struct Unk6b
{
    void FreeMemory(void*);
};

struct FUN_004b9d80_Class
{
    void ReleaseStorage_004b9d80(void* param);
};

// Calls FUN_0065de30(0) on the object at param+8, then FreeMemory(param) on the object at this+0xc.
// @fnv 0x004b9d80
// src: GUESS 0x004b9d80 (confidence: medium)
void FUN_004b9d80_Class::ReleaseStorage_004b9d80(void* pObject)
{
    ((Unk65*)((char*)pObject + 8))->FUN_0065de30(0);
    ((Unk6b*)((char*)this + 0xc))->FreeMemory(pObject);
}

void* __cdecl operator new(unsigned int);

struct FUN_004b9de0
{
    void* __thiscall Alloc();
};

// @fnv 0x004b9de0
void* __thiscall FUN_004b9de0::Alloc()
{
    void* p = operator new(0x14);
    return p;
}

extern "C" void* DAT_01020634;

struct FUN_004b9e00_cls
{
    void* m_vftable;
    void* GridArray_GridArray();
};

// @fnv 0x004b9e00
// src: EXE 0x004b9e00
void* FUN_004b9e00_cls::GridArray_GridArray()
{
    m_vftable = &DAT_01020634;
    return this;
}

extern double g_d100;

struct FUN_004be080_Class
{
    float TESObjectARMO_GetCalculatedArmorRating();
};

// Returns the unsigned short at offset 0x178 divided by g_d100, cast to float.
// @fnv 0x004be080
// src: XBOX_PDB 0x004be080
float FUN_004be080_Class::TESObjectARMO_GetCalculatedArmorRating()
{
    return (float)((double)*(unsigned short*)((char*)this + 0x178) / g_d100);
}

struct FUN_004be580_class
{
    unsigned char GetByteAt240();
};

// @fnv 0x004be580
unsigned char FUN_004be580_class::GetByteAt240()
{
    return ((unsigned char*)this)[0x240];
}

extern void* DAT_0101ed2c;
extern void NiFreeAlias(void*);

struct FUN_004a98b0_Class
{
    void* m_vtbl;
    int m_auiShapeKeys;
    void* m_p;
    void UpdateState_004a98b0();
};

// Resets the vtable pointer, clears the pointer map contents, and frees m_p.
// @fnv 0x004a98b0
// src: GUESS 0x004a98b0 (confidence: low)
void FUN_004a98b0_Class::UpdateState_004a98b0()
{
    m_vtbl = &DAT_0101ed2c;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(m_p);
}

extern int DAT_0101ed8c;
void __cdecl NiFreeAlias(void*);

struct FUN_004a9d20_Class
{
    void __thiscall ReleaseStorage_004a9d20();
};

// Resets the vtable pointer, clears the pointer map, and frees the pointer stored at offset 8.
// @fnv 0x004a9d20
// src: GUESS 0x004a9d20 (confidence: medium)
void __thiscall FUN_004a9d20_Class::ReleaseStorage_004a9d20()
{
    *(int*)this = (int)&DAT_0101ed8c;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(*(void**)((char*)this + 8));
}

namespace fnv_004aa150 {
extern int DAT_0101ee20;
void* __cdecl NiFreeAlias(void* p);

struct FUN_004aa150_class
{
    void* vtable;
    void* m_iWordAt04;
    void* m_8;
    void __thiscall SetVtableAndProcessState_004aa150();
};

// @fnv 0x004aa150
// src: GUESS 0x004aa150 (confidence: low)
void __thiscall FUN_004aa150_class::SetVtableAndProcessState_004aa150()
{
    *reinterpret_cast<void**>(this) = &DAT_0101ee20;
    reinterpret_cast<NiTPointerMap<int, int>*>(this)->RemoveAll();
    NiFreeAlias(m_8);
}
}  // namespace fnv_004aa150

extern int DAT_0101ee60;
void NiFreeAlias(void*);
struct FUN_004aa2e0_Class
{
    void __thiscall ReleaseStorage_004aa2e0();
};
// Sets the vtable pointer, clears the pointer map, and frees the pointer stored at offset 8.
// @fnv 0x004aa2e0
// src: GUESS 0x004aa2e0 (confidence: medium)
void __thiscall FUN_004aa2e0_Class::ReleaseStorage_004aa2e0()
{
    *reinterpret_cast<int**>(this) = &DAT_0101ee60;
    reinterpret_cast<NiTPointerMap<int, int>*>(this)->RemoveAll();
    NiFreeAlias(reinterpret_cast<void**>(this)[2]);
}

extern int DAT_0101fbdc;
void __cdecl NiFreeAlias(void* p);
struct FUN_004b0000_class
{
    void* vtable;
    char pad[4];
    void* m_ptr;
    void __thiscall ReleaseStorage_004b0000();
};
// Sets the vtable, clears the pointer map contents, and frees m_ptr.
// @fnv 0x004b0000
// src: GUESS 0x004b0000 (confidence: medium)
void __thiscall FUN_004b0000_class::ReleaseStorage_004b0000()
{
    vtable = (void*)&DAT_0101fbdc;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(m_ptr);
}

namespace fnv_004b0100 {
extern "C" void* __cdecl NiFreeAlias(void*);
extern void* DAT_0101fbfc;
struct FUN_004b0100_Class
{
    void* vtbl;
    void* p;
    void* q;
    void RemoveAll();
    void __thiscall ReleaseStorage_004b0100();
};
// Sets the vtable pointer, calls RemoveAll, then frees the q pointer via NiFreeAlias.
// @fnv 0x004b0100
// src: GUESS 0x004b0100 (confidence: medium)
void __thiscall FUN_004b0100_Class::ReleaseStorage_004b0100()
{
    vtbl = &DAT_0101fbfc;
    RemoveAll();
    NiFreeAlias(q);
}
}  // namespace fnv_004b0100

extern "C" void __cdecl _NiFreeAlias(void*);
extern int DAT_010205d4;

struct FUN_004b9d30 : NiTPointerMap<int, int>
{
    void Init();
};

// Sets the vtable pointer, clears all entries with RemoveAll, then frees the pointer stored at offset 8 via _NiFreeAlias.
// @fnv 0x004b9d30
void __thiscall FUN_004b9d30::Init()
{
    *(int**)((char*)this + 0) = &DAT_010205d4;
    RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}

void __fastcall ProcessState_00c4ed40(void*);
void __cdecl operator delete(void*);
struct FUN_004a4410_Class
{
    void* __thiscall FUN_004a4410(unsigned int flags);
};
// @fnv 0x004a4410
void* __thiscall FUN_004a4410_Class::FUN_004a4410(unsigned int flags)
{
    ProcessState_00c4ed40(this);
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_004a4bd0_shell
{
    void __thiscall FUN_004a4bd0();
    void* __thiscall FUN_004a4ba0(unsigned int flags);
};
// Calls FUN_004a4bd0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004a4ba0
void* __thiscall FUN_004a4bd0_shell::FUN_004a4ba0(unsigned int flags)
{
    FUN_004a4bd0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_004a99d0_Class
{
    void __thiscall SetVtableAndProcessState_004a99d0();
    void* __thiscall FUN_004a9a30(unsigned int flags);
};
// @fnv 0x004a9a30
void* FUN_004a99d0_Class::FUN_004a9a30(unsigned int flags)
{
    SetVtableAndProcessState_004a99d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_004a9c20 {
extern "C" void __cdecl Deallocate(void* p);
struct GlobalObject_004a9bf0
{
    void __thiscall dtor();
    GlobalObject_004a9bf0* FUN_004a9c20(unsigned int flags);
};
// Calls the object's destructor, frees the object with Deallocate when bit 0 of flags is set, and returns the object pointer.
// @fnv 0x004a9c20
GlobalObject_004a9bf0* GlobalObject_004a9bf0::FUN_004a9c20(unsigned int flags)
{
    this->dtor();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_004a9c20

void __cdecl ReleaseStorage_004a9fc0();
struct FUN_004a9ff0_Class
{
    void __thiscall ReleaseStorage_004a9fc0();
    void* __thiscall FUN_004a9ff0(unsigned int flags);
};
// Calls FUN_004a9fc0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004a9ff0
void* __thiscall FUN_004a9ff0_Class::FUN_004a9ff0(unsigned int flags)
{
    ReleaseStorage_004a9fc0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_004aa150_Class
{
    void __thiscall SetVtableAndProcessState_004aa150();
    void* __thiscall FUN_004aa180(unsigned int flags);
};

// Calls FUN_004aa150, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x004aa180
void* __thiscall FUN_004aa150_Class::FUN_004aa180(unsigned int flags)
{
    SetVtableAndProcessState_004aa150();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_004aa310_Class : FUN_004aa2e0_Class
{
    FUN_004aa310_Class* __thiscall FUN_004aa310(unsigned int flags);
};
// @fnv 0x004aa310
FUN_004aa310_Class* __thiscall FUN_004aa310_Class::FUN_004aa310(unsigned int flags)
{
    ReleaseStorage_004aa2e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __fastcall FUN_004afc20(void*);
void __cdecl operator delete(void*);
struct FUN_004b0160_class
{
    void __fastcall FUN_004afc20();
    void* __thiscall FUN_004b0160(unsigned int flags);
};
// Calls FUN_004afc20, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004b0160
void* __thiscall FUN_004b0160_class::FUN_004b0160(unsigned int flags)
{
    FUN_004afc20();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_004b01f0_Class
{
    void* ReleaseStorage_004b0100();
    void* FUN_004b01f0(unsigned int flags);
};

// Calls FUN_004b0100, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004b01f0
void* __thiscall FUN_004b01f0_Class::FUN_004b01f0(unsigned int flags)
{
    ReleaseStorage_004b0100();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_004b0850_Class
{
    void __thiscall SetVtableAndProcessState_004b07b0();
    FUN_004b0850_Class* __thiscall FUN_004b0850(unsigned int flags);
};
// Calls FUN_004b07b0, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x004b0850
FUN_004b0850_Class* __thiscall FUN_004b0850_Class::FUN_004b0850(unsigned int flags)
{
    SetVtableAndProcessState_004b07b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl FUN_004b0cf0();
struct FUN_004b08e0_Class
{
    void __thiscall FUN_004b0cf0();
    void* __thiscall BSClonePools_ClonePool_Destroy(unsigned int flags);
};
// Calls FUN_004b0cf0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x004b08e0
// src: COMMUNITY 0x004b08e0
void* __thiscall FUN_004b08e0_Class::BSClonePools_ClonePool_Destroy(unsigned int flags)
{
    FUN_004b0cf0();
    if (flags & 1)
        operator delete(this);
    return this;
}

// Destroys the NiFixedString and, if the flags bit 0 is set, frees the object's memory, returning this.
// @fnv 0x004b9900
void* NiFixedString::FUN_004b9900(unsigned int flags)
{
    NiFixedString::~NiFixedString();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

void __cdecl FUN_004b9cd0();

struct FUN_004b9980_Class
{
    void FUN_004b9cd0();
    void* __thiscall FUN_004b9980(unsigned int flags);
};

// @fnv 0x004b9980
void* __thiscall FUN_004b9980_Class::FUN_004b9980(unsigned int flags)
{
    FUN_004b9cd0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_004a0e50_Class
{
    bool __thiscall NiRenderer_GetInsideFrameState();
};
// Returns true when the int at offset 0x200 of this object equals 1 or 2.
// @fnv 0x004a0e50
// src: COMMUNITY 0x004a0e50
bool __thiscall FUN_004a0e50_Class::NiRenderer_GetInsideFrameState()
{
    return *(int*)((char*)this + 0x200) == 1 || *(int*)((char*)this + 0x200) == 2;
}

struct NiRenderer;
extern NiRenderer* DAT_011f9508;

// @fnv 0x004a0e90
// src: COMMUNITY 0x004a0e90
unsigned int BSShaderManager_GetRenderer()
{
    return *(Flt*)&DAT_011f9508;
}

struct CalleeObj
{
    int _m;
    void __thiscall UpdateState_00622570(bool);
};
struct Sub6815
{
    char pad[0x10];
    void __thiscall _ref_006815c0();
};
struct FUN_004a3cc0_Class
{
    Sub6815 a;
    Sub6815 b;
    CalleeObj c;
    int d;
    FUN_004a3cc0_Class* __thiscall hkpWorldRayCastInput_hkpWorldRayCastInput();
};
// @fnv 0x004a3cc0
// src: XBOX_PDB 0x004a3cc0
FUN_004a3cc0_Class* __thiscall FUN_004a3cc0_Class::hkpWorldRayCastInput_hkpWorldRayCastInput()
{
    a._ref_006815c0();
    b._ref_006815c0();
    c.UpdateState_00622570(false);
    d = 0;
    return this;
}

extern double DAT_0101e5a0;
struct UnsignedIntHelper
{
    unsigned int __thiscall GetRandomUInt();
};
struct BSRandomHelper
{
    float __thiscall BSRandom_FloatTwoPi();
};
// @fnv 0x004a4260
// src: XBOX_PDB 0x004a4260
float __thiscall BSRandomHelper::BSRandom_FloatTwoPi()
{
    unsigned int val = ((UnsignedIntHelper*)this)->GetRandomUInt();
    return (float)((double)val * DAT_0101e5a0);
}

struct ObstacleData;

struct FUN_004a4650_ListBase
{
    NiTListItem<NiPointer<ObstacleData> >* m_pItemHead;
    NiTListItem<NiPointer<ObstacleData> >* m_pItemPrev;
    NiTListItem<NiPointer<ObstacleData> >* m_pItemTail;
    void DeleteItem(NiTListItem<NiPointer<ObstacleData> >* item);
};
// Iterates the linked list from m_pItemHead, deleting each item via DeleteItem, then clears the head, prev and tail pointers.
// @fnv 0x004a4650
// src: XBOX_PDB 0x004a4650
void __fastcall NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll(FUN_004a4650_ListBase* self)
{
    NiTListItem<NiPointer<ObstacleData> >* item = self->m_pItemHead;
    while (item)
    {
        NiTListItem<NiPointer<ObstacleData> >* next = item;
        item = item->m_pkNext;
        self->DeleteItem(next);
    }
    self->m_pItemTail = 0;
    self->m_pItemHead = 0;
    self->m_pItemPrev = 0;
}

struct FUN_004a4930_class
{
    char _pad[8];
    FUN_004a49e0_shell _m;
    void __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_DeleteItem(void*);
};
// Clears the object at p+8 via assignment of 0, then calls _m.Deallocate(p).
// @fnv 0x004a4930
// src: XBOX_PDB 0x004a4930
void __thiscall FUN_004a4930_class::NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_DeleteItem(void* apObject)
{
    ((GO*)((char*)apObject + 8))->operator=(0);
    _m.Deallocate(apObject);
}

struct FUN_004a4960_class
{
    void* __thiscall hkArrayBase_hkpWorldRayCastOutput_hkArrayBase_hkpWorldRayCastOutput(void* a, void* b, unsigned int c);
};
// Stores a, b and c (with the high bit set) into the object's first three fields and returns this.
// @fnv 0x004a4960
// src: XBOX_PDB 0x004a4960
void* __thiscall FUN_004a4960_class::hkArrayBase_hkpWorldRayCastOutput_hkArrayBase_hkpWorldRayCastOutput(void* pFirst, void* pSecond, unsigned int c)
{
    *(void**)((char*)this) = pFirst;
    *(void**)((char*)this + 4) = pSecond;
    *(unsigned int*)((char*)this + 8) = c | 0x80000000;
    return this;
}

struct H_A100
{
    void* GetSizeMasked();
};
struct H_004a4a10
{
    void hkMemoryAllocator_bufFree_hkpWorldRayCastOutput(void* a, void* b);
};
struct FUN_004a4990_s
{
    void* p;
    int a;
    int b;
    void __fastcall hkArrayBase_hkpRootCdBodyPair_clear();
    void __thiscall hkArrayBase_hkpWorldRayCastOutput_clearAndDeallocate(int arg);
};
// @fnv 0x004a4990
// src: XBOX_PDB 0x004a4990
void __thiscall FUN_004a4990_s::hkArrayBase_hkpWorldRayCastOutput_clearAndDeallocate(int pTarget)
{
    hkArrayBase_hkpRootCdBodyPair_clear();
    if (!(b & 0x80000000))
        ((H_004a4a10*)pTarget)->hkMemoryAllocator_bufFree_hkpWorldRayCastOutput(p, ((H_A100*)this)->GetSizeMasked());
    p = 0;
    b = 0x80000000;
}

struct FUN_004a4a10_Holder
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void __thiscall vf10(int, int);
    void __thiscall hkMemoryAllocator_bufFree_hkpWorldRayCastOutput(int, int);
};
// Calls vf10 with a1 and a2 multiplied by 0x60.
// @fnv 0x004a4a10
// src: XBOX_PDB 0x004a4a10
void __thiscall FUN_004a4a10_Holder::hkMemoryAllocator_bufFree_hkpWorldRayCastOutput(int aiArg1, int aiArg2)
{
    int v = 0x60;
    vf10(aiArg1, aiArg2 * 0x60);
}

namespace fnv_004a4c50 {

struct FUN_004a4c50_Class
{
    char pad[0x24];
    GO m0;
    GO m1;
    GO m2;
    void __thiscall ClearSlots();
};
// Sets the three pointer slots at offsets 0x24, 0x28 and 0x2c of this object to null.
// @fnv 0x004a4c50
void __thiscall FUN_004a4c50_Class::ClearSlots()
{
    ((GO*)((char*)this + 0x24))->operator=(0);
    ((GO*)((char*)this + 0x28))->operator=(0);
    ((GO*)((char*)this + 0x2c))->operator=(0);
}
}  // namespace fnv_004a4c50

struct Mid
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual unsigned int v14();
};
// @fnv 0x004a8b00
// src: XBOX_PDB 0x004a8b00
unsigned int bhkNiCollisionObject_GetbhkNiCollisionObject(BGSBodyPart* apObject)
{
    const char* pc = apObject->GetPartName();
    return pc ? ((Mid*)pc)->v14() : 0;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_004a97e0_Class
{
    void* m_vtbl;
    unsigned int m_uiItemCount;
    void* m_p;
    unsigned int m_auiShapeKeys;
    void* __thiscall NiTMapBase_DFALL_NiTMapItem_NiTexture_TEX_USER_DATA_NiTexture_TEX_USER_DATA_NiTMapBase_DFALL_NiTMapItem_NiTexture_TEX_USER_DATA_NiTexture_TEX_USER_DATA(unsigned int a);
};
// Sets the vtable, stores a count, allocates count*4 bytes, zeroes them and stores the pointer in m_p.
// @fnv 0x004a97e0
// src: XBOX_PDB 0x004a97e0
void* __thiscall FUN_004a97e0_Class::NiTMapBase_DFALL_NiTMapItem_NiTexture_TEX_USER_DATA_NiTexture_TEX_USER_DATA_NiTMapBase_DFALL_NiTMapItem_NiTexture_TEX_USER_DATA_NiTexture_TEX_USER_DATA(unsigned int a)
{
    m_vtbl = &DAT_0101ed2c;
    m_uiItemCount = a;
    m_auiShapeKeys = 0;
    unsigned int size = m_uiItemCount * 4;
    m_p = NiMalloc(size);
    memset(m_p, 0, m_uiItemCount * 4);
    return this;
}

extern int DAT_0101ed4c;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_004a98e0_class
{
    int __thiscall NiTMapBase_DFALL_NiTMapItem_TESObjectCELL_bool_TESObjectCELL_bool_NiTMapBase_DFALL_NiTMapItem_TESObjectCELL_bool_TESObjectCELL_bool(int count);
};
// @fnv 0x004a98e0
// src: COMMUNITY 0x004a98e0
int __thiscall FUN_004a98e0_class::NiTMapBase_DFALL_NiTMapItem_TESObjectCELL_bool_TESObjectCELL_bool_NiTMapBase_DFALL_NiTMapItem_TESObjectCELL_bool_TESObjectCELL_bool(int count)
{
    *(int*)this = (int)&DAT_0101ed4c;
    *(int*)((char*)this + 4) = count;
    *(int*)((char*)this + 12) = 0;
    unsigned int size = *(int*)((char*)this + 4) * 4;
    *(void**)((char*)this + 8) = NiMalloc(size);
    memset(*(void**)((char*)this + 8), 0, *(int*)((char*)this + 4) * 4);
    return (int)this;
}

void __cdecl _Deallocate(void*);
struct FUN_004a9a00_Class
{
    void* __thiscall FUN_004a9a00(unsigned int);
};
// Calls FUN_004a98b0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x004a9a00
void* __thiscall FUN_004a9a00_Class::FUN_004a9a00(unsigned int flags)
{
    ((FUN_004a98b0_Class*)this)->UpdateState_004a98b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* p, int c, unsigned int n);
struct FUN_004a9c50_class
{
    void* vtbl;
    unsigned int count;
    void* data;
    unsigned int extra;
    FUN_004a9c50_class* NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool_NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool(unsigned int a);
};
// Sets the vtable, stores the count, allocates count*4 bytes for data, zeroes it, and returns this.
// @fnv 0x004a9c50
// src: COMMUNITY 0x004a9c50
FUN_004a9c50_class* FUN_004a9c50_class::NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool_NiTMapBase_DFALL_NiTMapItem_NiTexture_bool_NiTexture_bool(unsigned int a)
{
    vtbl = (void*)&DAT_0101ed8c;
    count = a;
    extra = 0;
    unsigned int size = count << 2;
    data = NiMalloc(size);
    memset(data, 0, count << 2);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_004a9d50_Self
{
    void* __thiscall FUN_004a9d50(unsigned int);
};
// @fnv 0x004a9d50
void* __thiscall FUN_004a9d50_Self::FUN_004a9d50(unsigned int flags)
{
    ((FUN_004a9d20_Class*)this)->ReleaseStorage_004a9d20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct GlobalObject_004a9d80
{
    ~GlobalObject_004a9d80();
    void* __thiscall FUN_004a9db0(unsigned int);
};
// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete; returns the object pointer.
// @fnv 0x004a9db0
void* __thiscall GlobalObject_004a9d80::FUN_004a9db0(unsigned int flags)
{
    ((GlobalObject_004a9d80*)this)->GlobalObject_004a9d80::~GlobalObject_004a9d80();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

struct FUN_004a9fc0_Class
{
    void* _00;
    int _04;
    void* _08;
    void __thiscall ReleaseStorage_004a9fc0();
};
extern int DAT_0101ede0;
void __cdecl _NiFree(void*);
// @fnv 0x004a9fc0
// src: GUESS 0x004a9fc0 (confidence: medium)
void __thiscall FUN_004a9fc0_Class::ReleaseStorage_004a9fc0()
{
    *(void**)this = (void*)&DAT_0101ede0;
    reinterpret_cast<NiTPointerMap<int, int>*>(this)->RemoveAll();
    _NiFree(_08);
}

namespace fnv_004aa210 {
extern "C" void* __cdecl NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dst, int value, unsigned int count);
struct FUN_004aa210_class
{
    int* vtbl;
    int count;
    void* data;
    int pad;
    FUN_004aa210_class* __thiscall NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int_NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int(int n);
};
// Sets the vtable, stores n as count, allocates count*4 bytes with NiMalloc, zeroes them with memset, and returns this.
// @fnv 0x004aa210
// src: COMMUNITY 0x004aa210
FUN_004aa210_class* __thiscall FUN_004aa210_class::NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int_NiTMapBase_DFALL_NiTMapItem_ShadowSceneLight_int_ShadowSceneLight_int(int aiCount)
{
    vtbl = &DAT_0101ee60;
    count = aiCount;
    pad = 0;
    unsigned int size = count * 4;
    data = NiMalloc(size);
    memset(data, 0, count * 4);
    return this;
}
}  // namespace fnv_004aa210

extern int DAT_0101fbfc;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct FUN_004b0030_Class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_004b0030_Class* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_NiObject_bool_NiTMapBase(int n);
};

// Sets the vtable, stores n as count, allocates count*4 zeroed bytes into data and returns this.
// @fnv 0x004b0030
// src: EXE 0x004b0030
FUN_004b0030_Class* __thiscall FUN_004b0030_Class::NiTMapBase_NiTPointerAllocator_unsigned_int_NiObject_bool_NiTMapBase(int aiCount)
{
    vtbl = &DAT_0101fbfc;
    count = aiCount;
    pad = 0;
    unsigned int size = count * 4;
    data = NiMalloc(size);
    memset(data, 0, count * 4);
    return this;
}

void __cdecl _Deallocate(void*);
struct StandIn004b01c0
{
    void* FUN_004b01c0(unsigned int);
};
// @fnv 0x004b01c0
void* StandIn004b01c0::FUN_004b01c0(unsigned int flags)
{
    ((FUN_004b0000_class*)this)->ReleaseStorage_004b0000();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S004b0220
{
    void* __thiscall FUN_00667120(unsigned int);
};
// If param_1 is non-null, calls FUN_00667120 with 3 on it.
// @fnv 0x004b0220
// src: COMMUNITY 0x004b0220
void __cdecl j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(int pObject)
{
    S004b0220* q;
    S004b0220* p;
    q = (S004b0220*)pObject;
    p = q;
    p ? p->FUN_00667120(3) : 0;
}

extern int DAT_0101fc8c;
#include "../../include/NiTMallocInterface.h"
struct FUN_004b07b0_Struct
{
    void* vtbl;
    void** ptr;
    void __thiscall SetVtableAndProcessState_004b07b0();
};
// Sets the object's vtbl to DAT_0101fc8c and deallocates the pointer member through NiTMallocInterface<void*>::Deallocate.
// @fnv 0x004b07b0
// src: GUESS 0x004b07b0 (confidence: low)
void __thiscall FUN_004b07b0_Struct::SetVtableAndProcessState_004b07b0()
{
    vtbl = (void*)&DAT_0101fc8c;
    NiTMallocInterface<void*>::Deallocate(ptr);
}

struct FUN_004b0da0_Class
{
    void* a;
    void* b;
    int c;
    void __thiscall BSCloneReserver_MakeClones();
    FUN_004b0da0_Class* __thiscall BSCloneReserver_BSCloneReserver(void* a, void* b);
};
// Stores the two given pointers into the object, resets the counter to zero, calls FUN_004b0eb0, and returns this.
// @fnv 0x004b0da0
// src: COMMUNITY 0x004b0da0
FUN_004b0da0_Class* __thiscall FUN_004b0da0_Class::BSCloneReserver_BSCloneReserver(void* pFirst, void* pSecond)
{
    this->a = pFirst;
    this->b = pSecond;
    this->c = 0;
    BSCloneReserver_MakeClones();
    return this;
}

struct Ret_004b0de0
{
    void __thiscall ProcessKeyedEntry(int a, int b);
};
extern Ret_004b0de0* __cdecl GetOrCreateInstance(int);
struct Holder_004b0de0
{
    int m0;
    int m1;
    void __thiscall ProcessState_004b0de0();
};
// If both m0 and m1 are non-zero, calls ProcessKeyedEntry on the object returned by GetOrCreateInstance(1) with m0 and m1.
// @fnv 0x004b0de0
// src: GUESS 0x004b0de0 (confidence: low)
void __thiscall Holder_004b0de0::ProcessState_004b0de0()
{
    if (m0 && m1)
        GetOrCreateInstance(1)->ProcessKeyedEntry(m0, m1);
}

struct FUN_004b0880
{
    FUN_004b0880();
    ~FUN_004b0880();
    int a;
    int b;
};
extern FUN_004b0880* DAT_011c5f40;

// Returns the global instance, allocating a new one first if it is null and create is true.
// @fnv 0x004b0e20
FUN_004b0880* GetOrCreateInstance(bool create)
{
    if (!DAT_011c5f40 && create)
        DAT_011c5f40 = new FUN_004b0880;
    return DAT_011c5f40;
}

namespace fnv_004b0eb0 {
int __cdecl GetOrCreateInstance(int);
struct FUN_004b0910_This
{
    void __thiscall AddKeyedItems(void* a, void* b);
};
struct FUN_004b0eb0_class
{
    void* f0;
    void* f4;
    void __thiscall BSCloneReserver_MakeClones();
};
// If both f0 and f4 are set, obtains an object via GetOrCreateInstance(1) and calls AddKeyedItems with f0 and f4.
// @fnv 0x004b0eb0
// src: COMMUNITY 0x004b0eb0
void __thiscall FUN_004b0eb0_class::BSCloneReserver_MakeClones()
{
    if (f0 && f4)
        ((FUN_004b0910_This*)GetOrCreateInstance(1))->AddKeyedItems(f0, f4);
}
}  // namespace fnv_004b0eb0

struct FUN_004b0de0_Holder
{
    void __thiscall ProcessState_004b0de0();
};
void __cdecl _Deallocate(void* p);
struct FUN_004b0f40_Holder
{
    void* vtbl;
    void* __thiscall FUN_004b0f40(unsigned int flags);
};
// Calls FUN_004b0de0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x004b0f40
void* __thiscall FUN_004b0f40_Holder::FUN_004b0f40(unsigned int flags)
{
    ((FUN_004b0de0_Holder*)this)->ProcessState_004b0de0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Helper62d0
{
    void* __thiscall operator=(void const*);
    void __thiscall AssignNodePointer(const NiPointer<NiNode>&);
};
// If other is non-null, assigns it to this object via operator=; otherwise returns without change.
// @fnv 0x004b0f70
void __thiscall Helper62d0::AssignNodePointer(const NiPointer<NiNode>& other)
{
    if (((const NiPointerComparisons<NiNode>*)&other)->Equals(0))
        return;
    operator=(reinterpret_cast<void const*>(&other));
}

unsigned short __cdecl Date_CalculateDate(unsigned short, unsigned short);
struct FUN_004b0fc0_Struct
{
    unsigned short m0;
    unsigned short m1;
    FUN_004b0fc0_Struct* __thiscall Date_Date(unsigned short a, unsigned short b, unsigned short c);
};
// Sets m0 to the result of FUN_004b10f0(a, b) and m1 to c, then returns this.
// @fnv 0x004b0fc0
// src: XBOX_PDB 0x004b0fc0
FUN_004b0fc0_Struct* __thiscall FUN_004b0fc0_Struct::Date_Date(unsigned short ausValue, unsigned short ausValue2,
                                                                  unsigned short c)
{
    m0 = Date_CalculateDate(ausValue, ausValue2);
    m1 = c;
    return this;
}

// @fnv 0x004b12d0
// src: XBOX_PDB 0x004b12d0
int __cdecl IsAFloat(char* pcString)
{
    char bDotSeen = 0;
    char c = *pcString;
    pcString++;
    if (c)
    {
        if ((c >= '0' && c <= '9') || c == '-' || c == '.')
        {
            if (pcString[0] == 0 && (c == '-' || c == '.'))
                return 0;
            if (c == '.')
                bDotSeen = 1;
            c = pcString[0];
            pcString++;
            while (c)
            {
                if ((c < '0' || c > '9') && (c != '.' || bDotSeen))
                    return 0;
                if (c == '.')
                    bDotSeen = 1;
                c = pcString[0];
                pcString++;
            }
            return 1;
        }
    }
    return 0;
}

// @fnv 0x004b45b0
NiMatrix3 NiMatrix3::Inverse() const
{
    NiMatrix3 tmp;
    if (!Inverse(tmp))
        tmp.MakeZero();
    return tmp;
}

// @fnv 0x004b4600
void NiMatrix3::MakeZero()
{
    SetCol(0, 0.0f, 0.0f, 0.0f);
    SetCol(1, 0.0f, 0.0f, 0.0f);
    SetCol(2, 0.0f, 0.0f, 0.0f);
}

extern const char* DAT_01188f84[];
// @fnv 0x004b7650
// src: COMMUNITY 0x004b7650
const char* __cdecl GetLanguageStr(int a1)
{
    return DAT_01188f84[a1];
}

struct Inner12
{
    int a;
    int b;
    int c;
};
struct Outer8
{
    int pad;
    int v;
    Inner12 inner;
};
struct Holder004b9ca0
{
    void __thiscall SetOuterValues(Outer8* p, int b, Inner12 v);
};
// Stores b into p->v and copies the Inner12 value v into p->inner.
// @fnv 0x004b9ca0
void __thiscall Holder004b9ca0::SetOuterValues(Outer8* pOuter, int iValue, Inner12 innerValue)
{
    pOuter->v = iValue;
    pOuter->inner = innerValue;
}

void __cdecl _Deallocate(void*);
struct Holder_004b9db0
{
    void* __thiscall FUN_004b9db0(unsigned int flags);
};
// Initializes the object via Init, then deallocates it if the flags bit 0 is set, and returns the object pointer.
// @fnv 0x004b9db0
void* __thiscall Holder_004b9db0::FUN_004b9db0(unsigned int flags)
{
    ((FUN_004b9d30*)this)->Init();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00418630_Class
{
    void* ExtraDataList_GetOriginalReference();
};
struct FUN_00418600_Class
{
    void ExtraDataList_RemoveOriginalReferenceExtra();
};
struct FUN_004bcbd0_Node
{
    int* __thiscall _ref_006815c0();
    FUN_004bcbd0_Node* __thiscall GetNext();
};
struct FUN_004bcbd0_Class
{
    FUN_004bcbd0_Node* m_pFirstNode;
    void __thiscall ProcessNodes();
};
// @fnv 0x004bcbd0
void __thiscall FUN_004bcbd0_Class::ProcessNodes()
{
    FUN_004bcbd0_Node* node = m_pFirstNode;
    while (node && *node->_ref_006815c0())
    {
        FUN_004bcbd0_Node* item = (FUN_004bcbd0_Node*)*node->_ref_006815c0();
        if (item && ((FUN_00418630_Class*)item)->ExtraDataList_GetOriginalReference())
            ((FUN_00418600_Class*)item)->ExtraDataList_RemoveOriginalReferenceExtra();
        node = node->GetNext();
    }
}

struct FUN_004be1a0_Class
{
    unsigned int GetFormTypeCategory();
};

// Reads the TESForm at offset 8, switches on its form type, and returns 3 for 0x28, 4 for 0x18/0x1a, otherwise 5.
// @fnv 0x004be1a0
unsigned int FUN_004be1a0_Class::GetFormTypeCategory()
{
    unsigned int result = 0;
    switch (((TESForm**)((char*)this + 8))[0]->FNV_GetFormType())
    {
    case 0x28:
        result = 3;
        break;
    case 0x18:
    case 0x1a:
        result = 4;
        break;
    default:
        result = 5;
        break;
    }
    return result;
}

struct FUN_004a5280
{
    virtual ~FUN_004a5280();
    virtual void vfn_04();
    virtual void vfn_08(unsigned int);
    unsigned int type;
    char pad[0x10];
    float fValue;
    float fMult;
    float fAdd;
    char pad2[0x10];
    FUN_004a5280();
};

// Allocates a FUN_004a5280, applies ui via vfn_08, sets fValue and fAdd to half of af[0] and af[1], fMult to 1.0 and type to 3, then returns it.
// @fnv 0x004a4f80
// src: COMMUNITY 0x004a4f80
FUN_004a5280* BGSPrimitivePlane_CreateObject(const float* afValues, unsigned int ui)
{
    FUN_004a5280* p = new FUN_004a5280;
    p->vfn_08(ui);
    p->fValue = afValues[0] * 0.5;
    p->fMult = 1.0;
    p->fAdd = afValues[1] * 0.5;
    p->type = 3;
    return p;
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);

struct FUN_004a9b50_Class
{
    void CopyBlocks(char* dst, char* src, unsigned int count);
};

// @fnv 0x004a9b50
void FUN_004a9b50_Class::CopyBlocks(char* apDest, char* apSource, unsigned int count)
{
    if (count <= 0)
        return;
    if (apDest < apSource)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(apDest + i * 64, apSource + i * 64, 64);
    }
    else if (apDest > apSource)
    {
        for (long i = (long)count - 1; i >= 0; --i)
            FUN_00ec7230(apDest + i * 64, apSource + i * 64, 64);
    }
}

char** __cdecl NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(unsigned int);
extern "C" void* DAT_0101fbcc;
struct FUN_004b0260_shell
{
    void* m_vtbl;
    char** m_p;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short m_iThirdValue;
    unsigned short m_usTrailingValue;
    FUN_004b0260_shell(unsigned short a, unsigned short b);
};
// @fnv 0x004b0260
FUN_004b0260_shell::FUN_004b0260_shell(unsigned short ausSize, unsigned short b)
{
    m_vtbl = &DAT_0101fbcc;
    m_8 = ausSize;
    m_usTrailingValue = b;
    m_kPointA = 0;
    m_iThirdValue = 0;
    if (m_8 > 0)
        m_p = NiTObjectArray_NiPointer_NiTexture_NiTObjectArray_NiPointer_NiTexture(m_8);
    else
        m_p = 0;
}

extern int _data_011c16bc;
struct Struct_004b0680
{
    float* p;
    float* q;
    Struct_004b0680(float* a, float* b);
    ~Struct_004b0680();
};

struct FUN_004b05d0_Class
{
    int FindPairIndex(float*, float*);
    char AddPairIfMissing(float* a, float* b);
};
// @fnv 0x004b05d0
char FUN_004b05d0_Class::AddPairIfMissing(float* pfFirst, float* pfSecond)
{
    char r = 0;
    if (FindPairIndex(pfFirst, pfSecond) == -1)
    {
        ((NiTPrimitiveArray<unsigned int>*)((char*)this + 8))
            ->AddFirstEmpty((unsigned int)new Struct_004b0680(pfFirst, pfSecond));
    }
    return r;
}

struct GOHelper
{
    void* m_pObject;
    unsigned char m_bIsOwned;
    int m_iRefCount;
    GOHelper(int);
    ~GOHelper();
    GOHelper& operator=(void*);
};
struct FUN_004a2c70
{
    void* m_pObject;
    unsigned char m_bIsOwned;
    int m_iRefCount;
    GOHelper m_helper;
    FUN_004a2c70(void* apObject, int aiRefCount, void* apObject2);
    ~FUN_004a2c70();
};
// Initialises the helper from apObject, stores aiRefCount and apObject2, and clears the owned flag.
// @fnv 0x004a2c70
FUN_004a2c70::FUN_004a2c70(void* apObject, int aiRefCount, void* apObject2) : m_helper(0)
{
    m_helper.operator=(apObject);
    m_iRefCount = aiRefCount;
    m_pObject = apObject2;
    m_bIsOwned = 0;
}

struct Date
{
    ~Date();
};
struct FUN_004a46d0 : Date
{
    void __thiscall hkArray_hkpWorldRayCastOutput_hkContainerHeapAllocator_clearAndDeallocate();
    ~FUN_004a46d0();
};
// Destructor that calls FUN_004a4810 before the base Date destructor runs.
// @fnv 0x004a46d0
FUN_004a46d0::~FUN_004a46d0()
{
    hkArray_hkpWorldRayCastOutput_hkContainerHeapAllocator_clearAndDeallocate();
}

struct FUN_004a9e00_Class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void ConstructScanItems(int, unsigned int);
    void UpdateFields_004a9e00(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x004a9e00
// src: GUESS 0x004a9e00 (confidence: low)
void FUN_004a9e00_Class::UpdateFields_004a9e00(unsigned int requested, unsigned int savedSize)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0xc) = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        *(int*)((char*)this + 4) = Write(requested);
        *(int*)((char*)this + 0xc) = requested;
    }
    if (savedSize > 0)
    {
        ConstructScanItems(*(int*)((char*)this + 4), savedSize);
        *(int*)((char*)this + 8) = savedSize;
    }
}

extern int DAT_0101ede0;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_004a9ef0_Class
{
    void* m_vtbl;
    int m_iElementCount;
    void* m_p;
    int m_auiShapeKeys;
    FUN_004a9ef0_Class* __thiscall NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool_NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool(int a);
};
// @fnv 0x004a9ef0
// src: COMMUNITY 0x004a9ef0
FUN_004a9ef0_Class* __thiscall FUN_004a9ef0_Class::NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool_NiTMapBase_DFALL_NiTMapItem_TESActorBase_bool_TESActorBase_bool(int aiCount)
{
    unsigned int uiSize;
    m_vtbl = (void*)&DAT_0101ede0;
    m_iElementCount = aiCount;
    m_auiShapeKeys = 0;
    uiSize = m_iElementCount << 2;
    m_p = NiMalloc(uiSize);
    memset(m_p, 0, m_iElementCount << 2);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_0101ee20;
struct FUN_004aa080_t
{
    void* __thiscall NiTMapBase_DFALL_NiTMapItem_int_int_int_int_NiTMapBase_DFALL_NiTMapItem_int_int_int_int(int a);
    void* m_vtbl;
    int m_i;
    void* m_p;
    int m_iUnknownValue;
};
// Sets the vtable, stores the count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x004aa080
// src: COMMUNITY 0x004aa080
void* FUN_004aa080_t::NiTMapBase_DFALL_NiTMapItem_int_int_int_int_NiTMapBase_DFALL_NiTMapItem_int_int_int_int(int aiCount)
{
    m_vtbl = &DAT_0101ee20;
    m_i = aiCount;
    m_iUnknownValue = 0;
    unsigned int sz = m_i << 2;
    m_p = NiMalloc(sz);
    memset(m_p, 0, m_i << 2);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_004aff30_Class
{
    void* m_vtbl;
    unsigned int m_iElementCount;
    void* m_data;
    unsigned int m_auiShapeKeys;
    FUN_004aff30_Class* __thiscall NiTMapBase_NiTPointerAllocator_unsigned_int_NiObject_NiObject_NiTMapBase(unsigned int aSize);
};
// Sets the vtable, stores aSize and allocates a zeroed array of aSize 4-byte elements into m_data.
// @fnv 0x004aff30
// src: EXE 0x004aff30
FUN_004aff30_Class* __thiscall FUN_004aff30_Class::NiTMapBase_NiTPointerAllocator_unsigned_int_NiObject_NiObject_NiTMapBase(unsigned int aSize)
{
    unsigned int uiByteCount;
    m_vtbl = &DAT_0101fbdc;
    m_iElementCount = aSize;
    m_auiShapeKeys = 0;
    uiByteCount = m_iElementCount * 4;
    m_data = NiMalloc(uiByteCount);
    memset(m_data, 0, m_iElementCount * 4);
    return this;
}

struct FUN_004b06b0_Class
{
    char pad[8];
    NiTPrimitiveArray<unsigned int> arr;
    int FindPairIndex(int a, int b);
};
// Scans arr for the last entry whose two leading ints equal a and b, returning its index or -1 if none match.
// @fnv 0x004b06b0
int FUN_004b06b0_Class::FindPairIndex(int aiFirst, int aiSecond)
{
    int result = -1;
    for (unsigned int i = 0; i < arr.GetSize(); ++i)
    {
        if ((int)*(int*)arr.GetAt(i) == aiFirst && (int)*(int*)((char*)arr.GetAt(i) + 4) == aiSecond)
            result = i;
    }
    return result;
}

struct FUN_004b07e0_Class
{
    void* vtbl;
    void** m_pElements;
    unsigned short m_uiSize;
    unsigned short m_uiCount;
    void* PopElement();
};

// @fnv 0x004b07e0
void* FUN_004b07e0_Class::PopElement()
{
    if (!*((unsigned short*)(this) + 5))
        return 0;
    --*((unsigned short*)(this) + 5);
    void* pElement = m_pElements[*((unsigned short*)(this) + 5)];
    m_pElements[*((unsigned short*)(this) + 5)] = 0;
    if (pElement)
        --*((unsigned short*)(this) + 6);
    return pElement;
}

extern "C" const short DAT_01188ecc[];
// @fnv 0x004b10f0
// src: XBOX_PDB 0x004b10f0
unsigned short Date_CalculateDate(unsigned short start, unsigned short count)
{
    unsigned short value = 0;
    unsigned short firstB = start;
    unsigned short last8 = count;
    if (last8 > 12)
        last8 = 11;
    if (firstB >= (unsigned short)DAT_01188ecc[last8])
        firstB = (unsigned short)DAT_01188ecc[last8] - 1;
    value = firstB;
    for (int i = 0; i < last8; i++)
        value += (unsigned short)DAT_01188ecc[i];
    return value;
}

struct GlobalObject_0045cfe0
{
    unsigned int* Int();
};
struct S0042fa20
{
    void ProcessAndReturnValue_0045ce80(int);
};
extern GlobalObject_0045cfe0 g_011c63cc;
// @fnv 0x004bc4c0
// src: COMMUNITY 0x004bc4c0
void GridCellArray_FixGridsToLoadINISetting()
{
    bool flag = false;
    if (flag && *reinterpret_cast<GlobalObject_0045cfe0*>(&g_011c63cc)->Int() < 3)
        reinterpret_cast<S0042fa20*>(&g_011c63cc)->ProcessAndReturnValue_0045ce80(3);
    else if (!flag && *reinterpret_cast<GlobalObject_0045cfe0*>(&g_011c63cc)->Int() < 5)
        reinterpret_cast<S0042fa20*>(&g_011c63cc)->ProcessAndReturnValue_0045ce80(5);
    else if ((*reinterpret_cast<GlobalObject_0045cfe0*>(&g_011c63cc)->Int() & 1) == 0)
        reinterpret_cast<S0042fa20*>(&g_011c63cc)
            ->ProcessAndReturnValue_0045ce80(*reinterpret_cast<GlobalObject_0045cfe0*>(&g_011c63cc)->Int() + 1);
}

struct FUN_004a46b0_class
{
    char* m_p;
    char* GetEntryAt(int i);
};

// @fnv 0x004a46b0
char* FUN_004a46b0_class::GetEntryAt(int aiIndex)
{
    return m_p + aiIndex * 0x60;
}

// Allocates a box, applies its color and half extents, and sets its primitive type.
// @fnv 0x004a5040
BGSPrimitiveBox* __cdecl CreatePrimitiveBox(NiPoint3* point, int iSize)
{
    BGSPrimitiveBox* box = new BGSPrimitiveBox;
    // BGSPrimitive still declares its shared color API with NiColorA.
    box->ApplyColor(*reinterpret_cast<NiColorA*>(iSize));

    NiPoint3 position = point->operator*(0.5f);
    box->vf03(*reinterpret_cast<NiPoint3*>(&position));

    box->eType = 1;
    return box;
}

struct FUN_004b05b0_Struct
{
    void SetVtableAndProcessState_004b07b0();
    void ForwardCall_004b05b0();
};

// @fnv 0x004b05b0
// src: GUESS 0x004b05b0 (confidence: low)
void FUN_004b05b0_Struct::ForwardCall_004b05b0()
{
    SetVtableAndProcessState_004b07b0();
}

struct FUN_004b55c0_class
{
    float GetFloatAt(int a1, int a2);
};

// @fnv 0x004b55c0
float FUN_004b55c0_class::GetFloatAt(int aiElement, int aiIndex)
{
    return ((float*)(this + aiElement * 0xc))[aiIndex];
}

struct FUN_004b9b20_result
{
    int a;
    int b;
    int c;
};

struct FUN_004b9b20_entry
{
    FUN_004b9b20_entry* next;
    int id;
    FUN_004b9b20_result value;
};

struct FUN_004b9b20_class
{
    // Empty virtual function stub that does nothing.
// @fnv 0x004b9b20
    virtual void FUN_004b9b20_unused()
    {}
    virtual int FUN_004b9b20_GetIndex(int arg);
    virtual bool FUN_004b9b20_Check(int arg, int id);

    int m_auiShapeKeys;
    FUN_004b9b20_entry** m_entries;

    bool NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_GetAt(int arg, FUN_004b9b20_result* result);
};

// src: XBOX_PDB 0x004b9b20
bool FUN_004b9b20_class::NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_GetAt(int arg, FUN_004b9b20_result* result)
{
    int index = this->FUN_004b9b20_GetIndex(arg);
    FUN_004b9b20_entry* entry = this->m_entries[index];

    while (entry)
    {
        if (this->FUN_004b9b20_Check(arg, entry->id))
        {
            *result = entry->value;
            return true;
        }
        entry = entry->next;
    }

    return false;
}

extern int DAT_011f91a8;
// @fnv 0x004a0ea0
// src: COMMUNITY 0x004a0ea0
int __cdecl BSShaderManager_GetTextureManager()
{
    return DAT_011f91a8;
}

extern "C" int DAT_011c61d0;

// @fnv 0x004a2c60
// src: XBOX_PDB 0x004a2c60
int __cdecl FixedStrings_QSkinnedDecalNode()
{
    return DAT_011c61d0;
}

struct FUN_004a2cf0_M
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_0066b0d0(int v);
    ~FUN_004a2cf0_M();
};
struct FUN_004a2cf0
{
    int pad[3];
    FUN_004a2cf0_M m_iThirdValue;
    ~FUN_004a2cf0();
};
// @fnv 0x004a2cf0
FUN_004a2cf0::~FUN_004a2cf0()
{
    m_iThirdValue.FUN_0066b0d0(0);
}

extern int DAT_011c57e4;
extern int DAT_011c57e8;
extern int DAT_011c57ec;
extern int DAT_011c57f0;

void* __cdecl FUN_0049fef0();

struct FUN_00559450_cls
{
    int __thiscall Modelloader_GetReferencedThis();
};
struct FUN_0057cbe0_cls
{
    int* __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(int* out);
};
struct FUN_004a0490_cls
{
    int __thiscall FUN_004a0490(int flag);
};
struct FUN_004ed900_cls
{
    void __thiscall FUN_004ed900();
};

// @fnv 0x004a42a0
// src: COMMUNITY 0x004a42a0
void __cdecl BGSDecalManager_RemoveAllDecals()
{
    DAT_011c57e4 = 0;
    DAT_011c57e8 = 0;
    DAT_011c57ec = 0;
    DAT_011c57f0 = 0;

    NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll((FUN_004a4650_ListBase*)((char*)FUN_0049fef0() + 8));
    char* kObj = (char*)FUN_0049fef0() + 0x14;

    int cur_2 = ((FUN_00559450_cls*)kObj)->Modelloader_GetReferencedThis();
    while (cur_2 != 0)
    {
        int a = *((FUN_0057cbe0_cls*)kObj)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&cur_2);
        int b = a;
        int c2 = b;
        int r;
        if (c2 != 0)
        {
            r = ((FUN_004a0490_cls*)c2)->FUN_004a0490(1);
        }
        else
        {
            r = 0;
        }
    }
    ((FUN_004ed900_cls*)kObj)->FUN_004ed900();
}

struct FUN_004a4650_ListBase;
void __fastcall NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll(FUN_004a4650_ListBase* self);
struct ObstacleBase
{
    ~ObstacleBase();
};
struct FUN_004a44a0 : ObstacleBase
{
    ~FUN_004a44a0();
};
// Destructor that forwards to FUN_004a4650, passing this as a list base.
// @fnv 0x004a44a0
FUN_004a44a0::~FUN_004a44a0()
{
    NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_RemoveAll(reinterpret_cast<FUN_004a4650_ListBase*>(this));
}

struct S_004a4730_Elem
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
    S_004a4730_Elem();
};

struct S_004a4730_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_004a4730_Base(void* buf, int a, int count);
    ~S_004a4730_Base();
};

struct FUN_004a4730 : S_004a4730_Base
{
    S_004a4730_Elem unk10[8];
    FUN_004a4730(int a);
};

// Constructs the object by initializing its base with the inline array of 8 elements and the given count.
// @fnv 0x004a4730
FUN_004a4730::FUN_004a4730(int a) : S_004a4730_Base(unk10, a, 8)
{}

// A tiny flag holder: one byte of state plus the query that asks the audio
// subsystem for a stream owned by the caller.
struct AudioSource
{
    bool m_bEnableState;
    void* __thiscall hkContainerHeapAllocator_get(void* pOwner);
};

// The object that owns the audio source.  The handle produced by the query is
// handed to the manager, which is called on this very object.
struct AudioOwner
{
    void* m_pObject;
    int m_iValue;
    int m_iFlags;
    void __thiscall hkArrayBase_hkpWorldRayCastOutput_clearAndDeallocate(void* pSource);
    void __thiscall hkArray_hkpWorldRayCastOutput_hkContainerHeapAllocator_clearAndDeallocate();
};

// Creates an empty AudioSource, obtains a source via FUN_004a4840 from this owner, and passes it to FUN_004a4990.
// @fnv 0x004a4810
// src: XBOX_PDB 0x004a4810
void AudioOwner::hkArray_hkpWorldRayCastOutput_hkContainerHeapAllocator_clearAndDeallocate()
{
    AudioSource source = {};
    hkArrayBase_hkpWorldRayCastOutput_clearAndDeallocate(source.hkContainerHeapAllocator_get(this));
}

class TESObjectREFR;

class RefBoolMap4A8
{
  public:
    bool GetAt(TESObjectREFR* pkRef, bool& bValue);
    void SetAt(TESObjectREFR* pkRef, bool bValue);
};

extern RefBoolMap4A8 g_kRefBoolMap4A8;

// If the reference's bool in g_kRefBoolMap4A8 is unset or false, adds iAmount to **ppiCount and sets the reference's bool to true.
// @fnv 0x004a8b40
void AddToRefCountIfNotFlagged(TESObjectREFR* pkRef, int iAmount, int** ppiCount)
{
    int** ppiTarget = ppiCount;
    bool bFlagged = false;
    if (!g_kRefBoolMap4A8.GetAt(pkRef, bFlagged) || !bFlagged)
    {
        bool bSkipA = false;
        bool bSkipB = false;
        if (!bSkipB || !bSkipA)
        {
            **ppiTarget += iAmount;
            g_kRefBoolMap4A8.SetAt(pkRef, true);
        }
    }
}

class FUN_004a9850_base
{
  public:
    virtual void unk00();
    ~FUN_004a9850_base();
    int unk04;
};

class FUN_004a9850 : public FUN_004a9850_base
{
  public:
    virtual ~FUN_004a9850();
    void unk08();
};

// Calls unk08() during destruction of the object.
// @fnv 0x004a9850
FUN_004a9850::~FUN_004a9850()
{
    this->unk08();
}

struct C4A9A60Entry
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
};

class C4A9A60Array
{
  public:
    int unk00;
    C4A9A60Entry* m_pUserData;

    int AllocIndex();
    void Construct(C4A9A60Entry* pkEntries, int iCount);
    int AddEntry(const C4A9A60Entry& kEntry);
};

// Allocates a slot in the entry array, constructs it, copies the given entry into it, and returns the slot index.
// @fnv 0x004a9a60
int C4A9A60Array::AddEntry(const C4A9A60Entry& kEntry)
{
    int iIndex = AllocIndex();
    Construct(&m_pUserData[iIndex], 1);
    m_pUserData[iIndex] = kEntry;
    return iIndex;
}

struct ScanItem64
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
    ScanItem64();
    int ClearToZero();
};

void* __cdecl operator new(unsigned int size, void* placement) throw();
void __cdecl operator delete(void* p, void* placement) throw();

struct FUN_004a9ab0_cls
{
    int unk00;

    void ConstructScanItems(int base, unsigned int count);
};

// Placement-constructs count ScanItem64 objects at base, each 64 bytes apart.
// @fnv 0x004a9ab0
void FUN_004a9ab0_cls::ConstructScanItems(int base, unsigned int count)
{

    for (unsigned int i = 0; i < count; ++i)
    {
        new ((char*)base + (i << 6)) ScanItem64();
    }
}

struct Base
{
    int a;
    virtual ~Base();
};
struct FUN_004a9cc0_cls : Base
{
    void Cleanup();
    virtual ~FUN_004a9cc0_cls();
};
// @fnv 0x004a9cc0
FUN_004a9cc0_cls::~FUN_004a9cc0_cls()
{
    Cleanup();
}

struct FUN_004a9fc0
{
    virtual ~FUN_004a9fc0();
};

struct FUN_004a9f60 : FUN_004a9fc0
{
    virtual ~FUN_004a9f60();
    void __thiscall FUN_00438af0();
};

// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x004a9f60
FUN_004a9f60::~FUN_004a9f60()
{
    FUN_00438af0();
}

class Ref_cls;
class Vt_cls
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a(Ref_cls* a);
};
class Ref_cls
{
  public:
    Vt_cls* NiAVObject_GetParent();
};
class Obj2_cls
{
  public:
    void RemoveObject_00b5b1c0(Ref_cls* p);
};
void __cdecl RecursivelyRemoveAllDecals(Ref_cls* p);
Obj2_cls* __cdecl FUN_00450b80(int a);
void __cdecl bhkWorld_RemoveObjects(Ref_cls* p, int a, int b);

// @fnv 0x004ab0c0
// src: XBOX_PDB 0x004ab0c0
void __cdecl BipedAnim_RunBiped3DDetach(Ref_cls* apRef)
{
    Vt_cls* v;
    if (apRef == 0)
        return;
    RecursivelyRemoveAllDecals(apRef);
    FUN_00450b80(0)->RemoveObject_00b5b1c0(apRef);
    if (apRef->NiAVObject_GetParent() != 0)
    {
        bhkWorld_RemoveObjects(apRef, 1, 0);
        v = (Vt_cls*)apRef->NiAVObject_GetParent();
        v->v3a(apRef);
    }
}

struct Pn4afe
{
    int unk00;
    NiPointer<NiAVObject>* unk04;
    unsigned short unk08;
    unsigned short unk0A;
    void TrimTrailingNullPointers();
};

// Decrements unk0A while the last entry of the unk04 pointer array is null, stopping at the first non-null entry or zero.
// @fnv 0x004afe50
void Pn4afe::TrimTrailingNullPointers()
{
    while (unk0A > 0)
    {
        if (((const NiPointerComparisons<NiAVObject>*)&unk04[unk0A - 1])->Differs(NiPointer<NiAVObject>(0)))
        {
            break;
        }
        unk0A--;
    }
}

// @fnv 0x004affa0
template <>
NiTPointerMap<NiObject*, NiObject*>::~NiTPointerMap()
{
    RemoveAll();
}

struct FUN_00658930_cls
{
    unsigned int GetShortAtOffsetA();
};

void __cdecl FormHeapFreeAndLog_00401030(void* p);

struct Guard_b9135
{
    ~Guard_b9135();
};

struct Base_b9135
{
    virtual ~Base_b9135();
};

class FUN_004b0480_cls : public Base_b9135
{
  public:
    virtual ~FUN_004b0480_cls();
    virtual void FUN_004b0480_vslot();

    char unk04[4];
    Guard_b9135 m_08;
};

// @fnv 0x004b0480
FUN_004b0480_cls::~FUN_004b0480_cls()
{
    unsigned int count = ((FUN_00658930_cls*)((char*)this + 8))->GetShortAtOffsetA();
    for (unsigned int i = 0; i < count; ++i)
    {
        void* p = ((FUN_004b07e0_Class*)((char*)this + 8))->PopElement();
        void* q = p;
        FormHeapFreeAndLog_00401030(q);
    }
}

struct S_004b0cf0_Obj
{
    void IncRefCount();
    void DecRefCount();
};
struct S_004b0cf0_Queue
{
    ~S_004b0cf0_Queue();
    bool IsEmpty();
    void Push(const NiPointer<S_004b0cf0_Obj>& p);
    void Pop();
};
struct FUN_004b0cf0
{
    int unk00;
    S_004b0cf0_Queue q;
    ~FUN_004b0cf0();
};
// Resets unk00 to 0, then repeatedly pushes a null NiPointer and pops until the queue q is empty.
// @fnv 0x004b0cf0
FUN_004b0cf0::~FUN_004b0cf0()
{
    unk00 = 0;
    while (!q.IsEmpty())
    {
        {
            NiPointer<S_004b0cf0_Obj> node(0);
            q.Push(node);
        }
        q.Pop();
    }
}

int __cdecl FUN_004019a0(void* p);

struct FUN_004b0ef0_cls
{
    int unk00;
    int unk04;
    int unk08;
    void BSCloneReserver_DecRefCount();
};

// Calls FUN_004019a0 on unk08; if it returns 0, calls FUN_004b0f40(1) on this as a FUN_004b0f40_Holder.
// @fnv 0x004b0ef0
// src: XBOX_PDB 0x004b0ef0
void FUN_004b0ef0_cls::BSCloneReserver_DecRefCount()
{
    if (FUN_004019a0(&unk08) == 0)
    {
        void* cur = this;
        FUN_004b0f40_Holder* holder = (FUN_004b0f40_Holder*)cur;
        (holder != 0) ? holder->FUN_004b0f40(1) : 0;
    }
}

namespace fnv_004b3570 {
void* __cdecl NiMalloc(unsigned int);

void __cdecl InitGeometryShader(NiAVObject* apObject, int a, int b);

// Builds a three-vertex NiTriShape from three points and a color, optionally attaching a lighting property and initializing the geometry shader.
// @fnv 0x004b3570
// src: COMMUNITY 0x004b3570
NiTriShape* __cdecl MakeTriangle(NiPoint3 kP0, NiPoint3 kP1, NiPoint3 kP2, const NiColorA& kColor,
                                 bool bEnableLighting)
{
    NiPoint3* aPVerts = new NiPoint3[3];
    aPVerts[0] = kP0;
    aPVerts[1] = kP1;
    aPVerts[2] = kP2;
    NiColorA* pColors2 = new NiColorA[3];
    pColors2[0] = kColor;
    pColors2[1] = kColor;
    pColors2[2] = kColor;
    unsigned short* pTris = (unsigned short*)NiMalloc(12);
    pTris[0] = 0;
    pTris[1] = 2;
    pTris[2] = 1;
    pTris[3] = 0;
    pTris[4] = 1;
    pTris[5] = 2;
    NiTriShape* pShape_ = new NiTriShape(3, (NiPoint3*)aPVerts, 0, (void*)pColors2, (NiPoint2*)0, 0, 0, 2, pTris);
    if (bEnableLighting)
    {
        BSShaderNoLightingProperty* pProp2 = new BSShaderNoLightingProperty;
        pShape_->AttachProperty(reinterpret_cast<NiObject*>(pProp2));
        InitGeometryShader(pShape_, 0, 0);
    }
    return pShape_;
}
}  // namespace fnv_004b3570

struct FUN_004b4910_Source
{
    unsigned short NiGeometry_GetVertexCount();
    int NiAVObject_GetWorldRotate();
    int FUN_0049ec60();
};

int __cdecl NiProcessorSpecificCode_ms_pPointsTransform_(unsigned short a1, int a2, int a3, int a4);

// Allocates an array of points sized by source->FUN_00456650() and fills it via FUN_004b4a10, returning null if source is null or its count is zero.
// @fnv 0x004b4910
NiPoint3* __cdecl CreateElementArray(FUN_004b4910_Source* source)
{
    NiPoint3* elements = 0;
    if (!source || !source->NiGeometry_GetVertexCount())
    {
        return 0;
    }
    elements = new NiPoint3[source->NiGeometry_GetVertexCount()];
    NiProcessorSpecificCode_ms_pPointsTransform_(source->NiGeometry_GetVertexCount(), source->FUN_0049ec60(), (int)elements, source->NiAVObject_GetWorldRotate());
    return elements;
}

// Log a heading and the machine's computer name.

extern "C" __declspec(dllimport) int __stdcall GetComputerNameA(char* lpBuffer, unsigned long* nSize);
extern "C" int __cdecl sprintf(char* pcBuffer, const char* pcFormat, ...);

void __cdecl B4A30Log(const char* pcFormat, ...);
const char* __cdecl PrepareScriptMessage(const char* pcText, bool bUnk);

extern char g_acB4A30ComputerName[];

// Retrieves the computer name, logs the heading, then logs a formatted "Computer Name: %s" line using the prepared script message.
// @fnv 0x004b4a30
// src: COMMUNITY 0x004b4a30
void __cdecl FillUserNameGlobal(const char* pcHeading)
{
    char acLine[264];
    unsigned long ulSize = 260;
    if (GetComputerNameA(g_acB4A30ComputerName, &ulSize))
    {
        B4A30Log("%s", pcHeading);
        sprintf(acLine, "Computer Name: %s", PrepareScriptMessage(g_acB4A30ComputerName, false));
        B4A30Log(acLine);
    }
}

struct FNVForm
{
    int __thiscall FUN_00441110();
};

extern void* __cdecl NiShadeProperty_GetType();

struct FNVNode
{
    virtual void R00();
    virtual void R04();
    virtual void R08();
    virtual int IsBranch();
    virtual void R10();
    virtual void R14();
    virtual int IsTerminalNode();

    unsigned int __thiscall FUN_0043b480();
    FNVNode* __thiscall FUN_0043b4a0(unsigned int index);
    FNVForm* __thiscall FUN_00a59d30(void* context);
};

// Recursively walks child nodes; for leaf nodes with a form whose FUN_00441110 value is 8-12, returns that form pointer as an unsigned int.
// @fnv 0x004b55e0
unsigned int __cdecl FindAcceptedForm(FNVNode* root)
{
    unsigned int found = 0;
    if (root->FUN_0043b480() == 0)
        return 0;

    unsigned int count = root->FUN_0043b480();
    for (unsigned int index = 0; index < count; ++index)
    {
        if (found != 0)
            return found;

        FNVNode* node = root->FUN_0043b4a0(index);
        if (node == 0)
            continue;

        if (node->IsBranch())
        {
            FNVNode* branch = node;
            found = FindAcceptedForm(branch);
        }
        else if (node->IsTerminalNode())
        {
            FNVNode* leaf = node;
            FNVForm* form = leaf->FUN_00a59d30(NiShadeProperty_GetType());
            if (form != 0)
            {
                unsigned int accepted =
                    (unsigned int)form &
                    ((form == 0 ? 0 : (form->FUN_00441110() >= 8 && form->FUN_00441110() <= 12)) ? ~0u : 0u);
                if (accepted)
                    return accepted;
            }
        }
    }

    return found;
}

void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl ourMemset(void* p, int fill, unsigned int size);
extern int DAT_010205d4;

struct FUN_004b99b0_cls
{
    int m_00;
    int m_04;
    void* m_08;
    unsigned int m_0C;
    FUN_004b99b0_cls* NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist(int count);
};

// Initialises the object: stores a global pointer and count, allocates count*4 bytes, zero-fills them and stores the pointer.
// @fnv 0x004b99b0
// src: XBOX_PDB 0x004b99b0
FUN_004b99b0_cls* FUN_004b99b0_cls::NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist(int count)
{
    m_00 = (int)&DAT_010205d4;
    m_04 = count;
    m_0C = 0;
    unsigned int size = m_04 << 2;
    m_08 = _NiMalloc_00aa1070(size);
    ourMemset(m_08, 0, m_04 << 2);
    return this;
}

struct S_004b9a20_Val
{
    int a;
    int b;
    int c;
};

struct S_004b9a20_Item;

struct S_004b9a20_cls
{
    virtual void vfn_00()
    {}
    virtual unsigned int vfn_04(unsigned int key)
    {
        return 0;
    }
    virtual bool vfn_08(unsigned int key, unsigned int itemKey)
    {
        return false;
    }
    virtual void vfn_0c(S_004b9a20_Item* item, unsigned int key, S_004b9a20_Val value)
    {}
    virtual void vfn_10()
    {}
    virtual S_004b9a20_Item* vfn_14()
    {
        return 0;
    }
    unsigned int m_uiHashSize;
    S_004b9a20_Item** m_ppkHashTable;
    unsigned int m_uiCount;
    void __thiscall SetOrInsert(unsigned int key, S_004b9a20_Val value);
};

struct S_004b9a20_Item
{
    S_004b9a20_Item* m_pkNext;
    unsigned int m_key;
    S_004b9a20_Val m_val;
};

// @fnv 0x004b9a20
void __thiscall S_004b9a20_cls::SetOrInsert(unsigned int key, S_004b9a20_Val value)
{
    unsigned int hash2 = this->vfn_04(key);
    S_004b9a20_Item* p2 = this->m_ppkHashTable[hash2];
    int i = 0;
    while (p2)
    {
        i = i + 1;
        if (this->vfn_08(key, p2->m_key))
        {
            p2->m_val = value;
            return;
        }
        p2 = p2->m_pkNext;
    }
    p2 = this->vfn_14();
    this->vfn_0c(p2, key, value);
    p2->m_pkNext = this->m_ppkHashTable[hash2];
    this->m_ppkHashTable[hash2] = p2;
    this->m_uiCount = this->m_uiCount + 1;
}

struct TableValue
{
    int first;
    int second;
    int third;
};
struct DataBufferInfo
{
    DataBufferInfo* next;
    int key;
    TableValue value;
};
struct HashTableBase
{
    virtual void Reserved();
    virtual unsigned int FindBucket(int key);
    unsigned int bucketCount;
    DataBufferInfo** buckets;
    void GetNextEntry(DataBufferInfo** iterator, int* keyOut, TableValue* valueOut);
};
// Reads the current node's key and value into the outputs, then advances the iterator to the next node or the next non-empty bucket.
// @fnv 0x004b9bf0
void HashTableBase::GetNextEntry(DataBufferInfo** iterator, int* keyOut, TableValue* valueOut)
{
    unsigned int bucketIndex;
    DataBufferInfo* node = *iterator;
    *keyOut = node->key;
    *valueOut = node->value;
    if (node->next != 0)
    {
        *iterator = node->next;
    }
    else
    {
        bucketIndex = FindBucket(node->key);
        ++bucketIndex;
        for (; bucketIndex < bucketCount; ++bucketIndex)
        {
            node = buckets[bucketIndex];
            if (node != 0)
            {
                *iterator = node;
                return;
            }
        }
        *iterator = 0;
    }
}

struct Base_b9225
{
    virtual ~Base_b9225();
    int unk04;
    int unk08;
    int unk0C;
};

struct FUN_004b9cd0 : Base_b9225
{
    void __thiscall FUN_00438af0();
    virtual ~FUN_004b9cd0();
};

// Destructor that calls FUN_00438af0 before destroying the base object.
// @fnv 0x004b9cd0
FUN_004b9cd0::~FUN_004b9cd0()
{
    FUN_00438af0();
}

struct NodePtr_4ba280
{
    void* m_pObject;
    NodePtr_4ba280(void* object);
    ~NodePtr_4ba280();
    NodePtr_4ba280& operator=(void* object);
};

struct Base_4ba280
{
    void* unk04;
    void* unk08;
    void* unk0C;
    Base_4ba280();
    virtual ~Base_4ba280();
    void SetType_4ba280(int value);
    unsigned int GetDim_4ba280();
};

void GridCellArray_FixGridsToLoadINISetting();
void* __cdecl memset(void*, int, unsigned int);
extern char DAT_01189184;

struct FUN_004ba280 : Base_4ba280
{
    int* grid;
    NiPoint3 origin;
    bool bFlag;
    NodePtr_4ba280 m_pController;
    FUN_004ba280();
    virtual ~FUN_004ba280();
};

// @fnv 0x004ba280
FUN_004ba280::FUN_004ba280() : m_pController(0)
{
    GridCellArray_FixGridsToLoadINISetting();
    SetType_4ba280(*g_011c63cc.Int());
    grid = new int[GetDim_4ba280() * GetDim_4ba280()];
    memset(grid, 0, GetDim_4ba280() * 4 * GetDim_4ba280());
    origin = NiPoint3(0.0f, 0.0f, 0.0f);
    DAT_01189184 = 1;
    m_pController = 0;
    bFlag = false;
}

extern const NiPoint3 NiPoint3_ZERO_v;

struct FUN_004a37b0
{
    NiPoint3 pos0;
    NiPoint3 pos1;
    NiPoint3 pos2;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    int unk48;
    float unk4C;
    int unk50;
    float unk54;
    float unk58;
    float unk5C;
    NiPoint3 scale;
    int unk6C;
    bool unk70;
    bool unk71;
    bool unk72;
    bool unk73;
    bool unk74;
    bool unk75;
    bool unk76;
    bool unk77;
    bool unk78;
    bool unk79;
    FUN_004a37b0();
};

// Initialises the object's positions to zero, sets default flags, numeric fields and a unit scale.
// @fnv 0x004a37b0
FUN_004a37b0::FUN_004a37b0() : scale(0.0f, 0.0f, 0.0f)
{
    pos0 = NiPoint3_ZERO_v;
    pos1 = NiPoint3_ZERO_v;
    pos2 = NiPoint3_ZERO_v;
    unk24 = 0;
    unk28 = 0;
    unk2C = 0;
    unk30 = 0;
    unk34 = -1;
    unk38 = 0.0f;
    unk3C = 0.0f;
    unk40 = 0.0f;
    unk44 = 0.0f;
    unk70 = false;
    unk71 = false;
    unk72 = true;
    unk48 = 0;
    unk73 = false;
    unk4C = 0.0f;
    unk76 = false;
    unk50 = 0;
    unk74 = true;
    unk75 = false;
    unk54 = 4.0f;
    unk58 = 15.0f;
    unk5C = 16.0f;
    scale = NiPoint3(1.0f, 1.0f, 1.0f);
    unk77 = false;
    unk78 = false;
    unk79 = false;
    unk6C = 0;
}

struct FUN_004a4860_node
{
    FUN_004a4860_node* m_pNext;
    FUN_004a4860_node* m_pListObject;
    NiPointer<NiNode> m_08;
};

class FUN_004a4860_cls
{
  public:
    FUN_004a4860_node* m_pHead;
    FUN_004a4860_node* m_pTail;
    unsigned int m_uiCount;

    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_DeleteItem(FUN_004a4860_node* node);
    NiPointer<NiNode> PopFront();
};

// @fnv 0x004a4860
NiPointer<NiNode> FUN_004a4860_cls::PopFront()
{
    FUN_004a4860_node* node = m_pHead;
    m_pHead = m_pHead->m_pNext;
    if (m_pHead != 0)
    {
        m_pHead->m_pListObject = 0;
    }
    else
    {
        m_pTail = 0;
    }
    NiPointer<NiNode> item(node->m_08);
    NiTPointerListBase_NiTPointerAllocator_unsigned_int_NiPointer_BSMultiBoundRoom_DeleteItem(node);
    m_uiCount--;
    return item;
}

// @fnv 0x004b00a0
template <>
NiTPointerMap<NiObject*, bool>::~NiTPointerMap()
{
    RemoveAll();
}

void __cdecl FUN_00b57e30(NiTriShape*, int, int);
// Builds an octahedron NiTriShape from six vertices and 24 indices around a given size and color, optionally attaching a lighting property.
// @fnv 0x004b29b0
NiTriShape* __cdecl CreateOctahedron(float size, const NiColorA* color, bool lighting)
{
    NiPoint3* indices = new NiPoint3[6];
    indices[0] = NiPoint3(0.0f, 0.0f, float(size * 1.4142135381698608));
    indices[1] = NiPoint3(-size, size, 0.0f);
    indices[2] = NiPoint3(size, size, 0.0f);
    indices[3] = NiPoint3(size, -size, 0.0f);
    indices[4] = NiPoint3(-size, -size, 0.0f);
    indices[5] = NiPoint3(0.0f, 0.0f, float(-size * 1.4142135381698608));
    NiColorA* colors = new NiColorA[6];
    colors[0] = *color;
    colors[1] = *color;
    colors[2] = *color;
    colors[3] = *color;
    colors[4] = *color;
    colors[5] = *color;
    unsigned short* shape = (unsigned short*)NiMalloc(48);
    shape[0] = 0;
    shape[1] = 2;
    shape[2] = 1;
    shape[3] = 0;
    shape[4] = 3;
    shape[5] = 2;
    shape[6] = 0;
    shape[7] = 4;
    shape[8] = 3;
    shape[9] = 0;
    shape[10] = 1;
    shape[11] = 4;
    shape[12] = 1;
    shape[13] = 2;
    shape[14] = 5;
    shape[15] = 2;
    shape[16] = 3;
    shape[17] = 5;
    shape[18] = 3;
    shape[19] = 4;
    shape[20] = 5;
    shape[21] = 4;
    shape[22] = 1;
    shape[23] = 5;
    NiTriShape* vertices = new NiTriShape(6, (NiPoint3*)indices, 0, (void*)colors, (NiPoint2*)0, 0, 0, 8, shape);
    if (lighting)
    {
        BSShaderNoLightingProperty* property = new BSShaderNoLightingProperty;
        vertices->NiAVObject_AttachProperty((NiObject*)property);
        FUN_00b57e30(vertices, 0, 0);
    }
    return vertices;
}

void* operator new[](unsigned int);
void operator delete[](void*);
void* _NiMalloc_00aa1070(unsigned int);
void FUN_00b57e30(NiTriShape*, int, int);
// Builds an 8-vertex box mesh from eight corner positions and a color, with 72 triangle indices, and optionally attaches extra data.
// @fnv 0x004b2eb0
NiTriShape* CreateBoxMesh(const NiPoint3& aCorner0, const NiPoint3& aCorner1, const NiPoint3& aCorner2, const NiPoint3& aCorner3,
                      const NiPoint3& aCorner4, const NiPoint3& aCorner5, const NiPoint3& aCorner6, const NiPoint3& aCorner7,
                      const NiColorA& color, bool extra)
{
    NiPoint3* vertices2 = new NiPoint3[8];
    vertices2[0] = aCorner0;
    vertices2[1] = aCorner1;
    vertices2[2] = aCorner2;
    vertices2[3] = aCorner3;
    vertices2[4] = aCorner4;
    vertices2[5] = aCorner5;
    vertices2[6] = aCorner6;
    vertices2[7] = aCorner7;
    NiColorA* colors73 = new NiColorA[8];
    colors73[0] = color;
    colors73[1] = color;
    colors73[2] = color;
    colors73[3] = color;
    colors73[4] = color;
    colors73[5] = color;
    colors73[6] = color;
    colors73[7] = color;
    unsigned short* indices21 = (unsigned short*)_NiMalloc_00aa1070(144);
    indices21[0] = 0;
    indices21[1] = 2;
    indices21[2] = 1;
    indices21[3] = 0;
    indices21[4] = 3;
    indices21[5] = 2;
    indices21[6] = 0;
    indices21[7] = 7;
    indices21[8] = 3;
    indices21[9] = 0;
    indices21[10] = 4;
    indices21[11] = 7;
    indices21[12] = 1;
    indices21[13] = 4;
    indices21[14] = 0;
    indices21[15] = 1;
    indices21[16] = 5;
    indices21[17] = 4;
    indices21[18] = 2;
    indices21[19] = 5;
    indices21[20] = 1;
    indices21[21] = 2;
    indices21[22] = 6;
    indices21[23] = 5;
    indices21[24] = 3;
    indices21[25] = 6;
    indices21[26] = 2;
    indices21[27] = 3;
    indices21[28] = 7;
    indices21[29] = 6;
    indices21[30] = 4;
    indices21[31] = 7;
    indices21[32] = 6;
    indices21[33] = 4;
    indices21[34] = 6;
    indices21[35] = 5;
    indices21[36] = 0;
    indices21[37] = 1;
    indices21[38] = 2;
    indices21[39] = 0;
    indices21[40] = 2;
    indices21[41] = 3;
    indices21[42] = 0;
    indices21[43] = 3;
    indices21[44] = 7;
    indices21[45] = 0;
    indices21[46] = 7;
    indices21[47] = 4;
    indices21[48] = 1;
    indices21[49] = 0;
    indices21[50] = 4;
    indices21[51] = 1;
    indices21[52] = 4;
    indices21[53] = 5;
    indices21[54] = 2;
    indices21[55] = 1;
    indices21[56] = 5;
    indices21[57] = 2;
    indices21[58] = 5;
    indices21[59] = 6;
    indices21[60] = 3;
    indices21[61] = 2;
    indices21[62] = 6;
    indices21[63] = 3;
    indices21[64] = 6;
    indices21[65] = 7;
    indices21[66] = 4;
    indices21[67] = 6;
    indices21[68] = 7;
    indices21[69] = 4;
    indices21[70] = 5;
    indices21[71] = 6;
    NiTriShape* mesh1 = new NiTriShape(8, (NiPoint3*)vertices2, 0, (void*)colors73, (NiPoint2*)0, 0, 0, 24, indices21);
    if (extra)
    {
        BSShaderNoLightingProperty* data = new BSShaderNoLightingProperty;
        mesh1->NiAVObject_AttachProperty(reinterpret_cast<NiObject*>(data));
        FUN_00b57e30(mesh1, 0, 0);
    }
    return mesh1;
}

namespace fnv_004b3890 {
// This geometry's construction cleanup passes its allocation size.
using ::NiMemObject;


struct FUN_00a746e0 : NiMemObject
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
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    FUN_00a746e0(unsigned short, NiPoint3*, NiColorA*, void*, unsigned int, unsigned int, bool*);
    void NiAVObject_AttachProperty(BSShaderNoLightingProperty*);
};
void FUN_00b57e30(FUN_00a746e0*, unsigned int, unsigned int);

// @fnv 0x004b3890
// src: XBOX_PDB 0x004b3890
FUN_00a746e0* __cdecl MakeLine(const NiPoint3& aStartVertex, const NiColorA& startColor,
                                   const NiPoint3& aEndVertex, const NiColorA& endColor, bool addShader)
{
    NiPoint3* vertices = new NiPoint3[2];
    vertices[0] = aStartVertex;
    vertices[1] = aEndVertex;
    NiColorA* colors = new NiColorA[2];
    colors[0] = startColor;
    colors[1] = endColor;
    // Each flag enables the outgoing segment from the corresponding vertex.
    bool* lines = new bool[2];
    lines[0] = true;
    lines[1] = false;
    // The geometry owns the vertex, color and segment buffers.
    FUN_00a746e0* connections = new FUN_00a746e0(2, vertices, colors, 0, 0, 0, lines);
    if (addShader)
    {
        BSShaderNoLightingProperty* shader = new BSShaderNoLightingProperty;
        connections->NiAVObject_AttachProperty(shader);
        FUN_00b57e30(connections, 0, 0);
    }
    return connections;
}
}  // namespace fnv_004b3890

struct Query4a4
{
    unsigned char BSOcclusionQuery_GetResult(unsigned int* puiOut, int iFlag);
    ~Query4a4();
};
struct Entry4a4
{
    char pad[0x1c];
    Query4a4* m_pQuery;
};
struct EntryPtr4a4
{
    Entry4a4* Modelloader_GetReferencedThis();
};
struct List4a4
{
    unsigned int FUN_0044ddc0();
    void* Modelloader_GetReferencedThis();
    EntryPtr4a4* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(void** ppPos);
};
struct Renderer4a4;
Renderer4a4* NiXenonRenderer_GetRenderer();
void __fastcall NiXenonRenderer_LockRenderer(Renderer4a4* p);
void __fastcall NiXenonRenderer_UnlockRenderer(Renderer4a4* p);
struct Owner4a4
{
    void* pad[2];
    List4a4 m_kNode;
    void BGSDecalManager_ClearPendingQueries();
};

// @fnv 0x004a4340
// src: COMMUNITY 0x004a4340
void Owner4a4::BGSDecalManager_ClearPendingQueries()
{
    if (m_kNode.FUN_0044ddc0() > 0)
    {
        NiXenonRenderer_LockRenderer(NiXenonRenderer_GetRenderer());
        void* pos = m_kNode.Modelloader_GetReferencedThis();
        while (pos)
        {
            void* pPrev = pos;
            Entry4a4* pkEntry = m_kNode.NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&pos)->Modelloader_GetReferencedThis();
            if (pkEntry && pkEntry->m_pQuery)
            {
                unsigned int uiOut = 0;
                pkEntry->m_pQuery->BSOcclusionQuery_GetResult(&uiOut, 1);
                delete pkEntry->m_pQuery;
                pkEntry->m_pQuery = 0;
            }
        }
        NiXenonRenderer_UnlockRenderer(NiXenonRenderer_GetRenderer());
    }
}

struct Target004a4d40
{
    int __thiscall FUN_00726070();
    NiPoint3 __thiscall FUN_00413fc0() const;
    NiColorA* __thiscall BGSPrimitive_GetColor(NiColorA* out);
    float __thiscall FUN_004a7bd0() const;
};

extern void* __cdecl BGSPrimitive_CreateSphere(float value, NiColorA* color);

// The game fills these aligned color buffers through its output routine;
// constructing NiColorA here would add initialization calls absent from the original.
// @fnv 0x004a4d40
// src: COMMUNITY 0x004a4d40
void* __cdecl BGSPrimitive_Copy(Target004a4d40* pTarget)
{
    {
        void* bResult = 0;

        if (3 == pTarget->FUN_00726070())
        {
            float colorA[sizeof(NiColorA) / sizeof(float)];
            {
                NiPoint3 w = pTarget->FUN_00413fc0() * 2.0f;
            }
            pTarget->BGSPrimitive_GetColor(reinterpret_cast<NiColorA*>(colorA));

            float kIter[sizeof(NiColorA) / sizeof(float)];
            {
                NiPoint2 point(pTarget->FUN_00413fc0().x * 2.0, pTarget->FUN_00413fc0().z * 2.0f);
                pTarget->BGSPrimitive_GetColor(reinterpret_cast<NiColorA*>(kIter));
                bResult = BGSPrimitivePlane_CreateObject((const float*)&point, (unsigned int)&kIter);
            }
        }

        if (pTarget->FUN_00726070() == 1)
        {
            float colorA[sizeof(NiColorA) / sizeof(float)];
            {
                NiPoint3 point = pTarget->FUN_00413fc0() * 2.0f;
                pTarget->BGSPrimitive_GetColor(reinterpret_cast<NiColorA*>(colorA));
                bResult = CreatePrimitiveBox(&point, (int)&colorA);
            }
        }

        if (pTarget->FUN_00726070() == 2)
        {
            float cnt[sizeof(NiColorA) / sizeof(float)];
            pTarget->BGSPrimitive_GetColor(reinterpret_cast<NiColorA*>(cnt));
            bResult = BGSPrimitive_CreateSphere(pTarget->FUN_004a7bd0(), reinterpret_cast<NiColorA*>(cnt));
        }

        return bResult;
    }
}

const NiFixedString& __cdecl FixedStrings_QDVPG();

struct NodeAB;
struct ExtraAB;

struct AVObjAB
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NodeAB* GetAsNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void* GetAsTriBasedGeom();
    ExtraAB* GetExtraData(const NiFixedString& kName);
    bool RemoveExtraDataByName(const NiFixedString& kName);
};

struct NodeAB : AVObjAB
{
    unsigned int FUN_0043b480();
    AVObjAB* FUN_0043b4a0(unsigned int uiIndex);
};

struct GeomAB : AVObjAB
{
    void* NiGeometry_GetSkinInstance();
};

struct ListAB
{
    void* Find(AVObjAB* const& rkKey, void* pvPos);
};

struct ExtraAB
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    ListAB m_kList;
};

struct BipedAB
{
    AVObjAB* FUN_004ab230(int iIndex);
    void BipedAnim_RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone(AVObjAB* pkObject);
};

// @fnv 0x004ab130
// src: XBOX_PDB 0x004ab130
void BipedAB::BipedAnim_RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone(AVObjAB* pkObject)
{
    if (!pkObject)
        return;
    AVObjAB* pkRootNode = FUN_004ab230(1);
    ExtraAB* pkExtra = pkRootNode->GetExtraData(FixedStrings_QDVPG());
    if (!pkExtra)
        return;
    if (pkObject->GetAsTriBasedGeom())
    {
        GeomAB* pkGeom = (GeomAB*)pkObject;
        ExtraAB* pkList = pkExtra;
        if (pkGeom->NiGeometry_GetSkinInstance())
        {
            if (pkList->m_kList.Find(pkGeom, 0))
                pkRootNode->RemoveExtraDataByName(FixedStrings_QDVPG());
        }
    }
    else
    {
        NodeAB* pkNode = pkObject->GetAsNode();
        if (pkNode)
        {
            for (unsigned int i = 0; i < pkNode->FUN_0043b480(); i++)
                BipedAnim_RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone(pkNode->FUN_0043b4a0(i));
        }
    }
}

struct AGItem
{
    void* GetExtraLeveledItem();
    void BaseExtraList_RemoveExtra(void* p, int n);
    bool FUN_004bca60();
};
struct AGNode
{
    AGItem** _ref_006815c0();
    AGNode* GetNext();
};
struct AGList : AGNode
{
    void RemoveMatchingItem(AGItem** ppItem);
};
struct AGOwner
{
    AGList* m_pEntries;
    void* ProcessEntries_004bcd10();
};

// @fnv 0x004bcd10
// src: GUESS 0x004bcd10 (confidence: low)
void* AGOwner::ProcessEntries_004bcd10()
{
    AGNode* pNode = m_pEntries;
    void* pResult = 0;
    while (pNode && *pNode->_ref_006815c0())
    {
        AGItem* pItem = *pNode->_ref_006815c0();
        if (pItem && pItem->GetExtraLeveledItem())
        {
            pResult = pItem->GetExtraLeveledItem();
            pItem->BaseExtraList_RemoveExtra(pResult, 0);
            if (pItem->FUN_004bca60())
                m_pEntries->RemoveMatchingItem(&pItem);
            pNode = m_pEntries;
        }
        pNode = pNode->GetNext();
    }
    return pResult;
}

class ListBase4A47B0
{
  public:
    ~ListBase4A47B0();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void RemoveAll();
};
class FUN_004a47b0 : public ListBase4A47B0
{
  public:
    ~FUN_004a47b0();
};

// Destructor that calls RemoveAll to clear the list before the object is destroyed.
// @fnv 0x004a47b0
FUN_004a47b0::~FUN_004a47b0()
{
    RemoveAll();
}

struct PointerMapBase4aa0f0
{
    virtual void Slot00();
    ~PointerMapBase4aa0f0();
};

struct FUN_004aa0f0 : PointerMapBase4aa0f0
{
    void FUN_00438af0();
    ~FUN_004aa0f0();
};

// Destructor that calls FUN_00438af0; the base destructor then runs implicitly.
// @fnv 0x004aa0f0
FUN_004aa0f0::~FUN_004aa0f0()
{
    FUN_00438af0();
}

class FUN_004aa2e0
{
  public:
    virtual ~FUN_004aa2e0();

    void FUN_00438af0();
};

class FUN_004aa280 : public FUN_004aa2e0
{
  public:
    virtual ~FUN_004aa280();
};

// @fnv 0x004aa280
FUN_004aa280::~FUN_004aa280()
{
    FUN_00438af0();
}

struct FUN_0045cec0
{
    unsigned int value;
    ~FUN_0045cec0();
};
struct FUN_004a4bd0
{
    virtual ~FUN_004a4bd0();
    int m_0004, m_0008, m_000c, m_0010;
    int m_0014, m_0018, m_001c, m_0020;
    FUN_0045cec0 m_0024;
    FUN_0045cec0 m_0028;
    FUN_0045cec0 m_002c;
    void __thiscall ClearSlots();
};
// Destructor that calls ClearSlots.
// @fnv 0x004a4bd0
FUN_004a4bd0::~FUN_004a4bd0()
{
    ClearSlots();
}

void __cdecl _NiFree(void*);
extern int DAT_0101ed4c;
struct S_004a99d0
{
    void* vtbl;
    int f04;
    void* p08;
    void __thiscall SetVtableAndProcessState_004a99d0();
};
// Stores &DAT_0101ed4c in the first member, calls RemoveAll treating this as an NiTPointerMap, then calls a function on p08.
// @fnv 0x004a99d0
// src: GUESS 0x004a99d0 (confidence: low)
void __thiscall S_004a99d0::SetVtableAndProcessState_004a99d0()
{
    *(void**)this = (void*)&DAT_0101ed4c;
    ((NiTPointerMap<void*, void*>*)(void*)this)->RemoveAll();
    _NiFree(p08);
}

struct GlobalObject_004a9e90
{
    virtual ~GlobalObject_004a9e90();
};
struct FUN_004a9ec0 : GlobalObject_004a9e90
{
    virtual ~FUN_004a9ec0();
};
// @fnv 0x004a9ec0
FUN_004a9ec0::~FUN_004a9ec0()
{}

struct FUN_004aa050
{
    virtual ~FUN_004aa050();
};
// @fnv 0x004aa050
FUN_004aa050::~FUN_004aa050()
{}

struct FUN_004aa1e0
{
    virtual ~FUN_004aa1e0();
};
// @fnv 0x004aa1e0
FUN_004aa1e0::~FUN_004aa1e0()
{}

struct GlobalObject_004aff00
{
    ~GlobalObject_004aff00();
};
struct FUN_004b0190 : GlobalObject_004aff00
{
    virtual ~FUN_004b0190();
};
// Destructor with an empty body; the base class destructor runs implicitly.
// @fnv 0x004b0190
FUN_004b0190::~FUN_004b0190()
{}

#pragma pack(pop)
