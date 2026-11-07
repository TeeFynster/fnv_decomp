#include "../../include/ImageSpaceTexture.h"
#include "../../include/NiTArray.h"
// staging/blk_00ba0000_o2.cpp: GeomList_S, Owner, BSFogProperty, FnvOdbObject and more (245 functions)

#include <windows.h>
// src/staging/blk_00ba0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BSStringT.h"
#include "../../include/BSFogProperty.h"
#include "../../include/TileShaderProperty.h"

#include "../../include/BSString.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTransform.h"
#include "../../include/ShadowSceneLight.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiTPrimitiveArray.h"
// NiMemObjectAllocation_blk_00ba0000_o2: local type (was include/NiMemObjectAllocation.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiMemObjectAllocation_blk_00ba0000_o2
{
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer);
    static void operator delete(void* pointer, unsigned int size);
};
#include "../../include/NiRTTI.h"
#include "../../include/StrArr.h"
#include "../../include/Bound.h"
#include "../../include/NiGeometryData.h"
#include "../../include/BSFaceGenMorphData.h"
#include "../../include/BSShaderNoLightingProperty.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/NiBound.h"
#include "../../include/NiColor.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiProperty.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiStream.h"
#include "../../include/NiTexture.h"
#include "../../include/NiColorA.h"
#include "../../include/ShadowSceneNode.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
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
#include "../../include/Vec4.h"
#include "../../include/ImageSpaceEffectParam.h"

void __cdecl operator delete(void*);

// Bodies kept here so shared declarations retain the original inlining.
inline NiAlphaProperty::NiAlphaProperty() : NiProperty()
{
    m_usAlphaArg = 0x00EC;
    m_ucAlphaArg2 = 0;
}
__forceinline NiRefObject::~NiRefObject()
{
    InterlockedDecrement((volatile long*)&ms_lObjectCount);
}
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiAVObject::IncRefCount() { NiRefObject::IncRefCount(); }
inline void NiAVObject::DecRefCount() { NiRefObject::DecRefCount(); }
inline NiPoint3::NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
inline NiColorA::NiColorA(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
inline NiColor::NiColor() : r(0), g(0), b(0) {}
inline LocalVec3::LocalVec3() {}
inline LocalVec3::LocalVec3(float fA, float fB, float fC) : x(fA), y(fB), z(fC) {}
inline Vec4::Vec4(float fA, float fB, float fC, float fD) : x(fA), y(fB), z(fC), w(fD) {}
inline Vec4::Vec4(const Vec4& kSrc) : x(kSrc.x), y(kSrc.y), z(kSrc.z), w(kSrc.w) {}
inline NiBound::NiBound() {}
inline const NiBound& NiBound::operator=(const NiBound& other)
{
    unsigned int* __restrict dest = reinterpret_cast<unsigned int*>(this);
    const unsigned int* __restrict source = reinterpret_cast<const unsigned int*>(&other);
    dest[0] = source[0];
    dest[1] = source[1];
    dest[2] = source[2];
    dest[3] = source[3];
    return *this;
}
template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}

inline void CopyPointBits(NiPoint3& output, const NiPoint3& input)
{
    unsigned int* __restrict dest = reinterpret_cast<unsigned int*>(&output);
    const unsigned int* __restrict source = reinterpret_cast<const unsigned int*>(&input);
    dest[0] = source[0];
    dest[1] = source[1];
    dest[2] = source[2];
}

struct FUN_00bb0e90_Class
{
    void* __thiscall PrecipitationShaderProperty_GetBaseTexture();
};

// @fnv 0x00bb0e90
// src: XBOX_PDB 0x00bb0e90
void* __thiscall FUN_00bb0e90_Class::PrecipitationShaderProperty_GetBaseTexture()
{
    return reinterpret_cast<void**>(this)[0x90 / 4];
}

extern const char* const g_01200788_arg1;

// @fnv 0x00bb35a0
// src: COMMUNITY 0x00bb35a0
const char* const* __cdecl SpeedTreeShaderPPLightingProperty_GetRTTI()
{
    return &g_01200788_arg1;
}

extern MemoryManager g_memoryManager;
void __cdecl FUN_00ba0400();
struct FUN_00ba1230_Class
{
    void* __thiscall FUN_00ba1230(bool flag);
};
// @fnv 0x00ba1230
void* __thiscall FUN_00ba1230_Class::FUN_00ba1230(bool flag)
{
    void* p = this;
    FUN_00ba0400();
    if (flag & 1)
        g_memoryManager.Deallocate(p);
    return p;
}

namespace fnv_00ba1750 {
extern MemoryManager g_memoryManager;
void __cdecl FUN_00ba12d0();
struct FUN_00ba1750_Class
{
    void* __thiscall FUN_00ba1750(char flag);
};
// @fnv 0x00ba1750
void* __thiscall FUN_00ba1750_Class::FUN_00ba1750(char flag)
{
    FUN_00ba12d0();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00ba1750

extern "C" void NiFreeAlias(void*);
extern int DAT_010b9d24;
struct FUN_00ba3d10_Class
{
    int m0;
    void* m1;
    void __thiscall UpdateState_00ba3d10();
};
// @fnv 0x00ba3d10
// src: GUESS 0x00ba3d10 (confidence: low)
void __thiscall FUN_00ba3d10_Class::UpdateState_00ba3d10()
{
    void* p = m1;
    m0 = (int)&DAT_010b9d24;
    NiFreeAlias(p);
}

namespace fnv_00ba4170 {
extern MemoryManager g_memoryManager;
void __cdecl FUN_00ba3d30();
struct FUN_00ba4170_Class
{
    void* __thiscall FUN_00ba4170(int);
};
// @fnv 0x00ba4170
void* __thiscall FUN_00ba4170_Class::FUN_00ba4170(int flag)
{
    FUN_00ba3d30();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00ba4170

namespace fnv_00ba46a0 {
extern MemoryManager g_memoryManager;
void __cdecl FUN_00ba4190();
struct FUN_00ba46a0_Class
{
    FUN_00ba46a0_Class* __thiscall FUN_00ba46a0(unsigned char flags);
};
// @fnv 0x00ba46a0
FUN_00ba46a0_Class* __thiscall FUN_00ba46a0_Class::FUN_00ba46a0(unsigned char flags)
{
    FUN_00ba4190();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00ba46a0

namespace fnv_00ba4920 {
extern MemoryManager g_memoryManager;
struct FUN_00ba4480_Class
{
    void __thiscall FUN_00ba4480();
};
struct FUN_00ba4920_Class
{
    void* __thiscall FUN_00ba4920(int);
};
// @fnv 0x00ba4920
void* __thiscall FUN_00ba4920_Class::FUN_00ba4920(int a)
{
    ((FUN_00ba4480_Class*)this)->FUN_00ba4480();
    if (a & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00ba4920

void __cdecl FUN_00ba7df0();
void __cdecl operator delete(void*);
void __cdecl operator delete(void*, unsigned int);

struct FUN_00ba8270_Class
{
    void* __thiscall FUN_00ba8270(bool);
};

// @fnv 0x00ba8270
void* __thiscall FUN_00ba8270_Class::FUN_00ba8270(bool b)
{
    FUN_00ba7df0();
    if (b & 1)
        operator delete(this, 0x14c);
    return this;
}

extern const void* DAT_010b895c;

struct ImageSpaceEffect
{
    ImageSpaceEffect();
};

struct FUN_00baa160_Class : ImageSpaceEffect
{
    FUN_00baa160_Class();
};

// @fnv 0x00baa160
FUN_00baa160_Class::FUN_00baa160_Class()
{
    *(const void**)this = &DAT_010b895c;
}

namespace fnv_00baa220 {
extern MemoryManager g_memoryManager;
void* __cdecl FUN_00baa180();
struct FUN_00baa220_Class
{
    void* __thiscall FUN_00baa220(int flag);
};
// @fnv 0x00baa220
void* __thiscall FUN_00baa220_Class::FUN_00baa220(int flag)
{
    void* r = FUN_00baa180();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00baa220

struct FUN_00baa640_Class
{
    void __thiscall TallGrassShader_SetCurrentPass(int a, char b);
};

// @fnv 0x00baa640
// src: XBOX_PDB 0x00baa640
void __thiscall FUN_00baa640_Class::TallGrassShader_SetCurrentPass(int aiValue, char b)
{
    *(int*)((char*)this + 0x120) = aiValue;
    *(char*)((char*)this + 0x124) = b;
}

extern char DAT_011F941E;
struct FUN_00bad4d0_Class
{
    int ImageSpaceEffectHDR_IsEnabled();
};
// @fnv 0x00bad4d0
// src: COMMUNITY 0x00bad4d0
int FUN_00bad4d0_Class::ImageSpaceEffectHDR_IsEnabled()
{
    if (DAT_011F941E && *(int*)((char*)this + 0x6c))
        return 1;
    return 0;
}

extern char DAT_011F941E;
struct FUN_00bae780_Class
{
    char __thiscall SkyShaderProperty_SetupGeometry(NiAVObject* obj);
};
// @fnv 0x00bae780
// src: XBOX_PDB 0x00bae780
char __thiscall FUN_00bae780_Class::SkyShaderProperty_SetupGeometry(NiAVObject* apObject)
{
    if (DAT_011F941E && !((char*)apObject + 0x9c))
        apObject->UpdateSceneObject();
    return 1;
}

void __cdecl FUN_00bb0de0();
void __cdecl operator delete(void*, unsigned int);

struct FUN_00bb0ea0_Class
{
    void* __thiscall FUN_00bb0ea0(bool);
};

// Calls FUN_00bb0de0, then deletes this with size 0xa0 when flag bit 0 is set, and returns this.
// @fnv 0x00bb0ea0
void* __thiscall FUN_00bb0ea0_Class::FUN_00bb0ea0(bool abDelete)
{
    FUN_00bb0de0();
    if (abDelete & 1)
        operator delete(this, 0xa0);
    return this;
}

namespace fnv_00bb3140 {
extern int DAT_010b9338;
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00bb3140_Class
{
    int m_vtbl;
    void __thiscall FUN_00bb35b0();
    void* __thiscall FUN_00bb3140(bool del);
};
// Resets the vtable pointer, calls FUN_00bb35b0, and if del has bit 0 set, frees this with operator delete before returning this.
// @fnv 0x00bb3140
void* __thiscall FUN_00bb3140_Class::FUN_00bb3140(bool abDelete)
{
    m_vtbl = (int)&DAT_010b9338;
    FUN_00bb35b0();
    if (abDelete & 1)
        operator delete(this, 0x108);
    return this;
}
}  // namespace fnv_00bb3140

struct FUN_00bb3220_Class
{
    void* __thiscall GetEntryValue();
};

// @fnv 0x00bb3220
void* __thiscall FUN_00bb3220_Class::GetEntryValue()
{
    void* entry = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x104);
    if (entry)
        return *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(entry) + 8);
    return 0;
}

struct FUN_00bb3240_Class
{
    unsigned int __thiscall ComputeValue_00bb3240();
};

// @fnv 0x00bb3240
// src: GUESS 0x00bb3240 (confidence: low)
unsigned int __thiscall FUN_00bb3240_Class::ComputeValue_00bb3240()
{
    void* p = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x104);
    if (p)
        return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p) + 0xc);
    return 0;
}

struct FUN_00bb3260_Class
{
    void* __thiscall ComputeValue_00bb3260(void* a, unsigned short b);
};

// @fnv 0x00bb3260
// src: GUESS 0x00bb3260 (confidence: low)
void* __thiscall FUN_00bb3260_Class::ComputeValue_00bb3260(void* apData, unsigned short ausValue)
{
    void* p = *(void**)((char*)this + 0x104);
    if (p)
    {
        *(void**)((char*)p + 8) = apData;
        *(unsigned short*)((char*)p + 0xc) = ausValue;
    }
    return p;
}

struct FUN_00bb36d0_Class
{
    void* __thiscall GetThirdElement();
};
// @fnv 0x00bb36d0
void* __thiscall FUN_00bb36d0_Class::GetThirdElement()
{
    void** p = *reinterpret_cast<void***>(reinterpret_cast<char*>(this) + 0x84);
    if (p)
        return p[2];
    return 0;
}

struct FUN_00bb36f0_Class
{
    int __thiscall SpeedTreeShaderLightingProperty_GetVertexCount();
};

// @fnv 0x00bb36f0
// src: XBOX_PDB 0x00bb36f0
int __thiscall FUN_00bb36f0_Class::SpeedTreeShaderLightingProperty_GetVertexCount()
{
    void* p = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x84);
    if (p)
        return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p) + 0xc);
    return 0;
}

struct FUN_00bb3710_Class
{
    void* __thiscall SpeedTreeShaderLightingProperty_SetData(void* a, short b);
};
// @fnv 0x00bb3710
// src: XBOX_PDB 0x00bb3710
void* __thiscall FUN_00bb3710_Class::SpeedTreeShaderLightingProperty_SetData(void* apValue, short asValue)
{
    void* p = *(void**)((char*)this + 0x84);
    if (p)
    {
        *(void**)((char*)p + 8) = apValue;
        *(short*)((char*)p + 12) = asValue;
    }
    return p;
}

void __cdecl FUN_00bb35b0();
void __cdecl operator delete(void*, unsigned int);

struct FUN_00bb38e0_Class
{
    void* __thiscall FUN_00bb38e0(int);
};

// Calls FUN_00bb35b0, then deletes this with size 0x108 when flags has bit 0 set, and returns this.
// @fnv 0x00bb38e0
void* __thiscall FUN_00bb38e0_Class::FUN_00bb38e0(int flags)
{
    FUN_00bb35b0();
    if (flags & 1)
        operator delete(this, 0x108);
    return this;
}

struct FUN_00bb3c90_Class
{
    void* __thiscall SpeedTreeLeafShaderProperty_GetLeafMaps();
};

// @fnv 0x00bb3c90
// src: XBOX_PDB 0x00bb3c90
void* __thiscall FUN_00bb3c90_Class::SpeedTreeLeafShaderProperty_GetLeafMaps()
{
    void* p = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x88);
    if (p)
        return *reinterpret_cast<void**>(reinterpret_cast<char*>(p) + 8);
    return 0;
}

extern "C" void __cdecl operator_delete_sized(void*, unsigned int);

struct FUN_00bb4470_Class
{
    void* __thiscall FUN_00bb40c0();
    void* __thiscall FUN_00bb4470(int flags);
};
// @fnv 0x00bb4470
void* __thiscall FUN_00bb4470_Class::FUN_00bb4470(int flags)
{
    FUN_00bb40c0();
    if (flags & 1)
        operator_delete_sized(this, 0xd4);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
extern int DAT_010b9910;
void __fastcall FUN_00b67380(void*);

struct FUN_00bb4650_Class
{
    void* m_vft;
    void* __thiscall FUN_00bb4650(unsigned char flags);
};

// Sets the vtable pointer, calls FUN_00b67380 on this, and if flags bit 0 is set frees this with size 0x108; returns this.
// @fnv 0x00bb4650
void* __thiscall FUN_00bb4650_Class::FUN_00bb4650(unsigned char flags)
{
    m_vft = &DAT_010b9910;
    FUN_00b67380(this);
    if (flags & 1)
        _delete(this, 0x108);
    return this;
}

void __cdecl FUN_00bb7d70();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00bb7f60_Class
{
    void __thiscall FUN_00bb7d70();
    FUN_00bb7f60_Class* __thiscall FUN_00bb7f60(unsigned char flags);
};
// @fnv 0x00bb7f60
FUN_00bb7f60_Class* __thiscall FUN_00bb7f60_Class::FUN_00bb7f60(unsigned char flags)
{
    FUN_00bb7d70();
    if (flags & 1)
        operator delete(this, 0xb0);
    return this;
}

namespace fnv_00bb8990 {
struct MM
{
    void* p;
};
extern MM g_memoryManager;
void __cdecl FUN_00bb83d0();
struct FUN_00bb8990_Class
{
    void* __thiscall FUN_00bb8990(int);
};
// Calls FUN_00bb83d0, then deallocates this via the memory manager when bit 0 of a is set, and returns this.
// @fnv 0x00bb8990
void* __thiscall FUN_00bb8990_Class::FUN_00bb8990(int aiFlags)
{
    FUN_00bb83d0();
    if (aiFlags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}
}  // namespace fnv_00bb8990

struct FUN_00bb9540_Class
{
    void* m_ppVirtualMethodTable;
    void __thiscall CallVirtualSlots83And84();
};
// @fnv 0x00bb9540
void __thiscall FUN_00bb9540_Class::CallVirtualSlots83And84()
{
    typedef void(__thiscall * Fn)(FUN_00bb9540_Class*);
    ((Fn*)m_ppVirtualMethodTable)[83](this);
    ((Fn*)m_ppVirtualMethodTable)[84](this);
}

struct BeamStage
{
    void __thiscall ApplyPairToState(unsigned int);
};
// @fnv 0x00bb9640
// src: COMMUNITY 0x00bb9640
void __stdcall Lighting30Shader_SetTextureMode(unsigned int pTarget, unsigned int pSource)
{
    unsigned int r = ((unsigned int(__thiscall*)(void*))(*(void***)pSource)[0xe0 / 4])((void*)pSource);
    ((BeamStage*)pTarget)->ApplyPairToState(r);
}

struct FUN_00baa3c0_Class
{
    void __thiscall TallGrassShader_ClearPassStages();
};

// @fnv 0x00baa3c0
// src: XBOX_PDB 0x00baa3c0
void __thiscall FUN_00baa3c0_Class::TallGrassShader_ClearPassStages()
{
    for (int i = 0; i < 44; ++i)
        ((void(__thiscall*)(FUN_00baa3c0_Class*, void*))(*(void***)this)[74])(this, *(void**)(this + 0x6c + i * 4));
}

extern int DAT_0126f74c;
struct FUN_00bb1b20_Class
{
    void __thiscall SpeedTreeLeafShader_InitPass(int a);
};
// If a is 0x3e or 0x3f, copies the int at this+0x384 or this+0x388 into DAT_0126f74c.
// @fnv 0x00bb1b20
// src: XBOX_PDB 0x00bb1b20
void __thiscall FUN_00bb1b20_Class::SpeedTreeLeafShader_InitPass(int a)
{
    if (a == 0x3e)
        DAT_0126f74c = *(int*)((char*)this + 0x384);
    else if (a == 0x3f)
        DAT_0126f74c = *(int*)((char*)this + 0x388);
}

extern "C" void __cdecl NiFree(void*);
extern MemoryManager g_memoryManager;
struct FUN_00ba3ce0_Class
{
    void* m0;
    void* m1;
    void* __thiscall FUN_00ba3ce0(bool flag);
};
// Sets m0 to DAT_010b9d24, frees m1 with NiFree, and if flag bit 0 is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00ba3ce0
void* __thiscall FUN_00ba3ce0_Class::FUN_00ba3ce0(bool abFree)
{
    m0 = &DAT_010b9d24;
    NiFree(m1);
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

// Returns the element of a fixed lookup table at index a - 1.
// @fnv 0x00ba5060
int __cdecl GetTableValue(int aiIndex)
{
    int table[] = {1, 0, 2, 3, 6, 7, 8, 9, 4, 5, 10};
    return table[aiIndex - 1];
}

struct LodShaderBase
{
    void __thiscall FUN_00e814b0();
};
struct FUN_00ba5100_Class
{
    char m_0x28[0x28];
    int m_0x28_flag;
    char m_0x2c[0x7c - 0x2c];
    void* m_0x7c;
    void* m_0x80;
    void __thiscall ParticleShader_RecreateRendererData();
};
// If m_0x28_flag is set, calls virtual methods 40 and 34 on m_0x7c and m_0x80, then calls FUN_00e814b0 on this.
// @fnv 0x00ba5100
// src: XBOX_PDB 0x00ba5100
void __thiscall FUN_00ba5100_Class::ParticleShader_RecreateRendererData()
{
    if (m_0x28_flag)
    {
        ((void(__thiscall*)(void*))(void*)((*reinterpret_cast<void***>(m_0x7c))[40]))(m_0x7c);
        ((void(__thiscall*)(void*))(void*)((*reinterpret_cast<void***>(m_0x80))[34]))(m_0x80);
    }
    ((LodShaderBase*)this)->FUN_00e814b0();
}

struct FUN_00ba63a0_Class
{
    char b[0x74];
    NiD3DPass* m0;
    NiD3DPass* m1;
    void __thiscall UpdateFields_00ba59e0();
    bool __thiscall ParticleShader_Func_80();
};
// @fnv 0x00ba63a0
// src: COMMUNITY 0x00ba63a0
bool __thiscall FUN_00ba63a0_Class::ParticleShader_Func_80()
{
    if (!m0)
        NiD3DPass::CreateD3DPass(m0);
    if (!m1)
        NiD3DPass::CreateD3DPass(m1);
    UpdateFields_00ba59e0();
    return true;
}

struct FUN_00bad4f0_Class
{
    void __thiscall ImageSpaceEffectHDR_SetParams(int a);
};

// @fnv 0x00bad4f0
// src: COMMUNITY 0x00bad4f0
void __thiscall FUN_00bad4f0_Class::ImageSpaceEffectHDR_SetParams(int a)
{
    *(char*)((char*)this + 5) = 1;
    *(int*)((char*)this + 0x6c) = a;
}

struct NiObjectNET_stub
{
    void NiObjectNET_PostLinkObject(int);
};

struct NiPointer_NiTexture
{
    NiTexture* p;
};

struct FUN_00bae740_Class : NiObjectNET_stub
{
    void SkyShaderProperty_PostLinkObject(int a);
};
// @fnv 0x00bae740
// src: XBOX_PDB 0x00bae740
void FUN_00bae740_Class::SkyShaderProperty_PostLinkObject(int aiArg)
{
    NiObjectNET_PostLinkObject(aiArg);
    const char* name = *(const char**)((char*)this + 0x74);
    if (name && *(int*)((char*)this + 0x8c) != 3)
        BSShaderManager::GetTexture(name, true, *(NiPointer_NiTexture*)((char*)this + 0x70), true, false);
}

struct FUN_00b66700_Class
{
    void __thiscall SetClamped(float);
};
struct FUN_00baf520_Class
{
    float m58;
    int m60;
    int m64;
    int m68;
    float m70;
    float m74;
    void __thiscall CopyTo(FUN_00b66700_Class* dest);
};
// @fnv 0x00baf520
void __thiscall FUN_00baf520_Class::CopyTo(FUN_00b66700_Class* dest)
{
    dest->SetClamped(*(float*)((char*)this + 0x58));
    *(int*)((char*)dest + 0xe4) = *(int*)((char*)this + 0x60);
    *(float*)((char*)dest + 0xe8) = *(float*)((char*)this + 0x74);
    *(float*)((char*)dest + 0xec) = *(float*)((char*)this + 0x70);
    if (*(int*)((char*)this + 0x64))
        ((void(__thiscall*)(void*, FUN_00b66700_Class*))(*(void***)*(int*)((char*)this + 0x64))[0x26])(
            (void*)*(int*)((char*)this + 0x64), dest);
    if (*(int*)((char*)this + 0x68))
        ((void(__thiscall*)(void*, FUN_00b66700_Class*))(*(void***)*(int*)((char*)this + 0x68))[0x26])(
            (void*)*(int*)((char*)this + 0x68), dest);
}

extern "C" void __cdecl operator_delete_sized(void*, unsigned int);
extern float DAT_01200608;
extern float DAT_0120060c;
extern float DAT_01200658;
extern float DAT_01200668;
// Stores a and b into DAT_01200658 and DAT_01200668, and adds c and d to DAT_01200608 and DAT_0120060c.
// @fnv 0x00bb1390
// src: GUESS 0x00bb1390 (confidence: low)
void __cdecl Runtime_UpdateState_00bb1390(float afValue1, float afValue2, float afDelta1, float afDelta2)
{
    DAT_01200658 = afValue1;
    DAT_01200668 = afValue2;
    DAT_01200608 += afDelta1;
    DAT_0120060c += afDelta2;
}

struct FUN_00bb36b0_Class
{
    void __thiscall SpeedTreeShaderLightingProperty_SetClampNI(int a);
};
// @fnv 0x00bb36b0
// src: XBOX_PDB 0x00bb36b0
void __thiscall FUN_00bb36b0_Class::SpeedTreeShaderLightingProperty_SetClampNI(int a)
{
    *(int*)((char*)this + 0x80) = a;
}

namespace fnv_00bb79e0 {
struct NiObjectNET_stub
{
    void __thiscall NiObjectNET_PostLinkObject(int);
};

struct FUN_00bb79e0_Class
{
    void __thiscall TileShaderProperty_PostLinkObject(int arg);
};
// Calls FUN_00a5c6a0 on this, then if the pointer at offset 0x94 is set, calls BSShaderManager::GetTexture with it and the texture at offset 0x60.
// @fnv 0x00bb79e0
// src: XBOX_PDB 0x00bb79e0
void __thiscall FUN_00bb79e0_Class::TileShaderProperty_PostLinkObject(int arg)
{
    NiObjectNET_stub* p = (NiObjectNET_stub*)this;
    p->NiObjectNET_PostLinkObject(arg);
    int tex = *(int*)((char*)p + 0x94);
    if (tex)
        BSShaderManager::GetTexture((const char*)tex, true, *(NiTexture**)((char*)p + 0x60), false, false);
}
}  // namespace fnv_00bb79e0


struct FUN_00bb9010_Class
{
    void __thiscall ImageSpaceEffectTV_ReturnTextures();
};
// @fnv 0x00bb9010
// src: COMMUNITY 0x00bb9010
void __thiscall FUN_00bb9010_Class::ImageSpaceEffectTV_ReturnTextures()
{
    void* p = *(void**)((char*)this + 0x2c);
    ((ImageSpaceTexture*)*(NiTexture**)((char*)p + 4))->SetTexture(0);
}

namespace fnv_00bb9560 {
extern int DAT_01200ec0;

struct FUN_00c072c0_Class
{
    void __thiscall ConfigureAllPasses();
};
struct FUN_00bb9560_Class
{
    char __thiscall Lighting30Shader_LoadStagesAndPasses();
};
// @fnv 0x00bb9560
// src: COMMUNITY 0x00bb9560
char __thiscall FUN_00bb9560_Class::Lighting30Shader_LoadStagesAndPasses()
{
    for (int i = 0; i < 0x70; ++i)
        NiD3DPass::CreateD3DPass(reinterpret_cast<void**>(&DAT_01200ec0) + i);
    reinterpret_cast<FUN_00c072c0_Class*>(this)->ConfigureAllPasses();
    return 1;
}
}  // namespace fnv_00bb9560

struct RefCounted
{
    volatile long m_uiRefCount;
    virtual void v0();
    virtual void v1();
};
struct FUN_00bae930_Class
{
    char m0[0x80];
    RefCounted* m_0x80;
    void __thiscall NiPhysXProp_SetSnapshot(RefCounted* apTexture);
};
// Releases the previous texture reference, stores apTexture in m_0x80 and increments its reference count if non-null.
// @fnv 0x00bae930
// src: GAMEBRYO_LIB 0x00bae930
void __thiscall FUN_00bae930_Class::NiPhysXProp_SetSnapshot(RefCounted* apTexture)
{
    RefCounted* pOld = m_0x80;
    if (pOld != apTexture)
    {
        if (pOld)
        {
            if (InterlockedDecrement(&pOld->m_uiRefCount) == 0)
                pOld->v1();
        }
        m_0x80 = apTexture;
        if (m_0x80)
            InterlockedIncrement(&m_0x80->m_uiRefCount);
    }
}

struct FUN_00bb7170_Class
{
    char m0[0x68];
    FUN_00bb7170_Class();
    static void* operator new(unsigned int);
};
struct FUN_00bb7300_Class
{
    FUN_00bb7170_Class* __thiscall CreateInstance();
};
// Allocates and constructs a new FUN_00bb7170_Class object, returning the pointer.
// @fnv 0x00bb7300
FUN_00bb7170_Class* FUN_00bb7300_Class::CreateInstance()
{
    return new FUN_00bb7170_Class;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011fa05c;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
void __stdcall WriteToSettingArray(StrArr*);

// @fnv 0x00bb74e0
// src: XBOX_PDB 0x00bb74e0
void __stdcall BSDistantTreeShaderProperty_GetViewerStrings(StrArr* a)
{
    WriteToSettingArray(a);
    char* p = NiViewerStrings_NiGetViewerString_Title(*(void**)&g_011fa05c);
    unsigned int i = *(unsigned short*)((char*)a + 0xa);
    unsigned int c = *(unsigned short*)((char*)a + 0x8);
    if (i >= c)
        a->SetSize(i + *(unsigned short*)((char*)a + 0xe));
    a->SetAt(i, p);
}

void __cdecl NiFreeAlias(void*);
struct FUN_00ba4050_Class
{
    int m_vft;
    void* m_obj;
    void* __thiscall FUN_00ba4050(bool);
};
// Resets the vtable, frees m_obj via NiFreeAlias, and deallocates this when del is set.
// @fnv 0x00ba4050
void* FUN_00ba4050_Class::FUN_00ba4050(bool del)
{
    m_vft = (int)&DAT_010b9d24;
    NiFreeAlias(m_obj);
    if (del & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00ba4580_Class
{
    void __thiscall ImageSpaceEffectGetHit_ReturnTextures();
};
struct ImageSpaceTexture_ReturnRenderedTexture_H
{
    void __thiscall AddRenderedTexture();
};

// @fnv 0x00ba4580
// src: COMMUNITY 0x00ba4580
void FUN_00ba4580_Class::ImageSpaceEffectGetHit_ReturnTextures()
{
    char* p = (char*)this;
    int* a = (int*)(p + 0x2c);
    void* t0 = *(void**)(*(char**)a + 8);
    ((ImageSpaceTexture_ReturnRenderedTexture_H*)t0)->AddRenderedTexture();
    int tmp = 0;
    ((NiTPrimitiveArray<int>*)(p + 0x28))->SetAt(2, tmp);
    void* t1 = *(void**)(*(char**)a + 0xc);
    ((ImageSpaceTexture_ReturnRenderedTexture_H*)t1)->AddRenderedTexture();
    tmp = 0;
    ((NiTPrimitiveArray<int>*)(p + 0x28))->SetAt(3, tmp);
}

struct FUN_00ba52b0_Class
{
    char m0[0x74];
    void* m_0x74;
    void* m_0x78;
    void __thiscall ParticleShader_InitPass(int a);
};
// @fnv 0x00ba52b0
// src: XBOX_PDB 0x00ba52b0
void __thiscall FUN_00ba52b0_Class::ParticleShader_InitPass(int a)
{
    if (a == 0x41)
        DAT_0126f74c = (int)m_0x78;
    else
        DAT_0126f74c = (int)m_0x74;
}

struct FUN_00ba6370_Class
{
    void __thiscall FUN_00ba5740();
    void* __thiscall FUN_00ba6370(bool flag);
};
// Calls FUN_00ba5740, then deletes this with size 0x12c if flag bit 0 is set, and returns this.
// @fnv 0x00ba6370
void* FUN_00ba6370_Class::FUN_00ba6370(bool abDelete)
{
    FUN_00ba5740();
    if (abDelete & 1)
        _delete(this, 0x12c);
    return this;
}

extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00baa140_Class
{
    void __fastcall FUN_00baa0e0();
    FUN_00baa140_Class* __thiscall FUN_00baa140(unsigned char flags);
};
// Calls FUN_00baa0e0, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00baa140
FUN_00baa140_Class* FUN_00baa140_Class::FUN_00baa140(unsigned char flags)
{
    FUN_00baa0e0();
    if (flags & 1)
        _delete(this, 0x60);
    return this;
}

struct FUN_00bad560_Class
{
    void FUN_00bad400();
    FUN_00bad560_Class* FUN_00bad560(char flag);
};
// Calls FUN_00bad400, then deallocates this via g_memoryManager when flag has bit 0 set, and returns this.
// @fnv 0x00bad560
FUN_00bad560_Class* FUN_00bad560_Class::FUN_00bad560(char flag)
{
    FUN_00bad400();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern const char* const DAT_012005b8;

// @fnv 0x00baec70
// src: XBOX_PDB 0x00baec70
const char* const* __cdecl SkyShaderProperty_GetRTTI()
{
    return &DAT_012005b8;
}

extern "C" void __cdecl _delete(void*, unsigned int);
struct FUN_00baec90_Class
{
    void __thiscall FUN_00baec90();
};
struct FUN_00baeeb0_Class : FUN_00baec90_Class
{
    void* __thiscall FUN_00baeeb0(unsigned char a);
};
// @fnv 0x00baeeb0
void* FUN_00baeeb0_Class::FUN_00baeeb0(unsigned char a)
{
    FUN_00baec90();
    if (a & 1)
        _delete(this, 0x90);
    return this;
}

struct FUN_00bb1a70_Class
{
    void* m_vft;
    void __thiscall CallVirtualMethodWithField();
};
// @fnv 0x00bb1a70
void __thiscall FUN_00bb1a70_Class::CallVirtualMethodWithField()
{
    typedef void(__thiscall * Fn)(void*, void*);
    void* arg = *(void**)((char*)this + 0x384);
    Fn fn = (Fn)(*(void**)((char*)*(void**)((char*)this + 0) + 0x128));
    fn(this, arg);
}

extern int DAT_010b9338;
struct FUN_00bb3070_Class
{
    void* m_vft;
    char m_04[0x1c - 4];
    int m_0x1c;
    char m_0x20[0x58 - 0x20];
    int m_0x58;
    void __thiscall FUN_00bb3500(int a);
    void* __thiscall SpeedTreeBranchShaderProperty_SpeedTreeBranchShaderProperty(int a);
};
// Calls FUN_00bb3500, sets the vtable to DAT_010b9338 and initializes m_0x58 to 4 and m_0x1c to 10, then returns this.
// @fnv 0x00bb3070
// src: COMMUNITY 0x00bb3070
void* __thiscall FUN_00bb3070_Class::SpeedTreeBranchShaderProperty_SpeedTreeBranchShaderProperty(int a)
{
    FUN_00bb3500(a);
    m_vft = (void*)&DAT_010b9338;
    m_0x58 = 4;
    m_0x1c = 10;
    return this;
}

struct FUN_00bb3400_Class
{
    char m_iWordAt00[0x58];
    int m_58;
    char m_5c[0x50];
    int* m_ac;
    int* m_b0;

    int __thiscall ProcessAndReturnValue_00bb3400(NiAVObject* a, int b, int c);
};

// @fnv 0x00bb3400
// src: GUESS 0x00bb3400 (confidence: low)
int FUN_00bb3400_Class::ProcessAndReturnValue_00bb3400(NiAVObject* apObject, int b, int c)
{
    if (reinterpret_cast<char*>(apObject) + 0x9c == 0)
        apObject->UpdateSceneObject();

    if (*m_ac == 0 || *m_b0 == 0)
        m_58 = 0;

    return 0;
}

struct FUN_00bb3790_Class
{
    void __thiscall FUN_00bb3790();
};
struct FUN_00bb3910_Class
{
    void __thiscall FUN_00bb3790();
    FUN_00bb3910_Class* __thiscall FUN_00bb3910(unsigned char a);
};
// @fnv 0x00bb3910
FUN_00bb3910_Class* __thiscall FUN_00bb3910_Class::FUN_00bb3910(unsigned char a)
{
    ((FUN_00bb3790_Class*)this)->FUN_00bb3790();
    if (a & 1)
        _delete(this, 0x88);
    return this;
}

struct FUN_00bb39e0_shell
{
    void UpdateFields_00bb39e0(const void*, unsigned int);
};
struct FUN_00bb3cb0_Class
{
    char m0[0x88];
    FUN_00bb39e0_shell* m_0x88;
    void __thiscall SpeedTreeLeafShaderProperty_SetLeafMaps(const void* a, unsigned int b);
};
// @fnv 0x00bb3cb0
// src: XBOX_PDB 0x00bb3cb0
void __thiscall FUN_00bb3cb0_Class::SpeedTreeLeafShaderProperty_SetLeafMaps(const void* apData, unsigned int b)
{
    if (m_0x88)
        m_0x88->UpdateFields_00bb39e0(apData, b);
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00bb3ba0 : A51BF0Base
{
    char m_auiShapeKeys[0x8c];

    FUN_00bb3ba0(unsigned short, void*, void*);

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
    virtual void* v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(void*);
};

struct FUN_00bb3e30_Class
{
    char m_auiShapeKeys[0x78];
    void* m_0x7c;

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
    virtual void* v51();
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
    virtual unsigned short v62();
    virtual void* v63();

    FUN_00bb3ba0* __thiscall SpeedTreeLeafShaderProperty_CreateCopy();
};

// Allocates a FUN_00bb3ba0 from v62(), v51() and v63(), passes m_0x7c to its v55, and returns it.
// @fnv 0x00bb3e30
// src: XBOX_PDB 0x00bb3e30
FUN_00bb3ba0* __thiscall FUN_00bb3e30_Class::SpeedTreeLeafShaderProperty_CreateCopy()
{
    FUN_00bb3ba0* result = new FUN_00bb3ba0(v62(), v51(), v63());
    result->v55(m_0x7c);
    return result;
}

struct FUN_00bb3ee0_Class
{
    void* m0[0x90 / 4];
    void* __thiscall FUN_00bb3cd0();
    void* __thiscall FUN_00bb3ee0(bool a);
};

// Calls FUN_00bb3cd0, then deletes this with size 0x90 if the low bit of a is set, and returns this.
// @fnv 0x00bb3ee0
void* __thiscall FUN_00bb3ee0_Class::FUN_00bb3ee0(bool abDelete)
{
    FUN_00bb3cd0();
    if (abDelete & 1)
        _delete(this, 0x90);
    return this;
}

struct NewObj
{
    NewObj();
};
struct FUN_00bb4520_Class : NewObj
{
    FUN_00bb4520_Class();
};
// @fnv 0x00bb4520
FUN_00bb4520_Class::FUN_00bb4520_Class()
{
    *(int*)this = (int)&DAT_010b9910;
    *(int*)((char*)this + 0x100) = 0;
}

void __fastcall DestroyFogProperty(void*);
extern "C" void __cdecl _delete(void*, unsigned int);
extern const void* vftable_BSFogProperty;
// Sets the vftable, calls DestroyFogProperty on this, and if flags bit 0 is set deletes this with size 0x64, returning this.
// @fnv 0x00bb8250
BSFogProperty* BSFogProperty::FUN_00bb8250(unsigned char flags)
{
    unk00 = (int)&vftable_BSFogProperty;
    DestroyFogProperty(this);
    if (flags & 1)
        _delete(this, 0x64);
    return this;
}

// This by-value member is a declaration-only shim: the shared
// NiTPrimitiveArray<ImageSpaceTexture*> adds an implicit member constructor.
// Rebind measured 0x00bb8900 at 151 bytes instead of the original 136 bytes.
// Keep the original empty layout and external destructor until the owning
// effect can be represented without changing its constructor code.
struct LocalTextureArrayMember
{
    void __thiscall SetSize(unsigned int);
    ~LocalTextureArrayMember();
};

extern int DAT_010b9f04;
extern int DAT_011a9be0;
extern int DAT_011a9be4;
extern int DAT_011a9be8;
extern int DAT_011a9bec;
extern int DAT_01200800;
extern int DAT_01200804;
extern int DAT_01200808;
extern int DAT_0120080c;

struct FUN_00bb8900_Class : ImageSpaceEffect
{
    void* m_vft;
    unsigned char m_flag;
    char m_auiShapeKeys[0x23];
    LocalTextureArrayMember m_ppData;

    FUN_00bb8900_Class();
};

// Initializes the vtable pointer, sizes the texture array to 5, clears m_flag, and copies four globals into DAT_01200800..0c.
// @fnv 0x00bb8900
FUN_00bb8900_Class::FUN_00bb8900_Class()
{
    m_vft = &DAT_010b9f04;

    m_ppData.SetSize(5);

    m_flag = 0;

    DAT_01200800 = DAT_011a9be0;
    DAT_01200804 = DAT_011a9be4;
    DAT_01200808 = DAT_011a9be8;
    DAT_0120080c = DAT_011a9bec;
}

struct FUN_00bb8ea0_Class
{
    void __thiscall FUN_00bb8ea0();
};
struct FUN_00bb91e0_Class
{
    void* __thiscall FUN_00bb91e0(unsigned char flags);
};
// @fnv 0x00bb91e0
void* __thiscall FUN_00bb91e0_Class::FUN_00bb91e0(unsigned char flags)
{
    FUN_00bb8ea0_Class* obj = (FUN_00bb8ea0_Class*)this;
    obj->FUN_00bb8ea0();
    if (flags & 1)
        g_memoryManager.Deallocate(obj);
    return this;
}

struct FUN_00bb9590_Class
{
    void* m_vft;
    void __thiscall Lighting30Shader_ReloadShaders();
    void __thiscall ConfigureAllPasses();
};

// @fnv 0x00bb9590
// src: XBOX_PDB 0x00bb9590
void __thiscall FUN_00bb9590_Class::Lighting30Shader_ReloadShaders()
{
    ((void(__thiscall*)(void*))(*(void***)((char*)m_vft + 0x148)))(this);
    ConfigureAllPasses();
}

struct FUN_00bb9660_Class : LodShaderBase
{
    char m0[0x28];
    void Lighting30Shader_RecreateRendererData();
};

extern void* DAT_01200dd8[0x39];
extern void* DAT_01200c48[0x32];
extern void* DAT_01200d10[0x32];

// @fnv 0x00bb9660
// src: XBOX_PDB 0x00bb9660
void FUN_00bb9660_Class::Lighting30Shader_RecreateRendererData()
{
    if (*(int*)((char*)this + 0x28) != 0)
    {
        for (unsigned int i = 0; i < 0xe4; i += 4)
        {
            void* p = *(void**)((char*)DAT_01200dd8 + i);
            if (p)
                (*(void(__thiscall**)(void*))(*(int*)p + 0xa0))(p);
        }
    }
    for (unsigned int i = 0; i < 0xc8; i += 4)
    {
        void* p = *(void**)((char*)DAT_01200c48 + i);
        if (p)
            (*(void(__thiscall**)(void*))(*(int*)p + 0x88))(p);
        p = *(void**)((char*)DAT_01200d10 + i);
        if (p)
            (*(void(__thiscall**)(void*))(*(int*)p + 0x88))(p);
    }
    FUN_00e814b0();
}

extern char DAT_01200863;
extern char* DAT_012010bc;

// @fnv 0x00bb96d0
// src: COMMUNITY 0x00bb96d0
void __stdcall Lighting30Shader_DisableNonVolatileConstantsForPass(unsigned int)
{
    DAT_01200863 = 0;
    DAT_012010bc[8] = 0;
}

struct FUN_00baff20_Class
{
    unsigned char m_0x00[0x38];
    unsigned char m_0x38;
    unsigned char m_0x39[3];
    unsigned short m_0x3c;
    unsigned char m_0x3e[2];
    unsigned short m_0x40;
    unsigned char m_0x42[2];
    unsigned char m_0x44;
    unsigned char m_0x45[3];
    unsigned short m_0x48;
    unsigned char m_0x4a[2];
    unsigned char m_0x4c;
    unsigned char m_0x4d[0x0a];
    unsigned char m_0x57;

    void __thiscall AttachAlphaProperty(NiAVObject* target);
};

// @fnv 0x00baff20
void __thiscall FUN_00baff20_Class::AttachAlphaProperty(NiAVObject* target)
{
    if ((m_0x38 != 0 || m_0x44 != 0) && m_0x57 == 0)
    {
        NiAlphaProperty* property = new NiAlphaProperty;

        if (m_0x38)
            property->m_usAlphaArg |= 0x0001;
        else
            property->m_usAlphaArg &= 0xFFFE;

        property->m_usAlphaArg = (property->m_usAlphaArg & 0xFFE1) | (m_0x3c << 1);
        property->m_usAlphaArg = (property->m_usAlphaArg & 0xFE1F) | (m_0x40 << 5);

        if (m_0x44)
            property->m_usAlphaArg |= 0x0200;
        else
            property->m_usAlphaArg &= 0xFDFF;

        property->m_ucAlphaArg2 = m_0x4c;
        property->m_usAlphaArg = (property->m_usAlphaArg & 0xE3FF) | (m_0x48 << 10);

        target->AttachProperty(static_cast<NiObject*>(property));
    }
}

struct FUN_00ba02b0_Node
{
    FUN_00ba02b0_Node* next;
    char pad4[4];
    void* elem;
};

struct FUN_00ba02b0_Class
{
    char pad0[0x138];
    FUN_00ba02b0_Node* head;

    void ShadowSceneLight_RemoveTriGeom(void* elem, FUN_00ba02b0_Node* node);
    void ShadowSceneLight_RemoveUnusedGeom();
};
// Walks the linked list from head, calling FUN_00ba01a0 for each node with a non-null elem, then sets head to null.
// @fnv 0x00ba02b0
// src: COMMUNITY 0x00ba02b0
void FUN_00ba02b0_Class::ShadowSceneLight_RemoveUnusedGeom()
{
    FUN_00ba02b0_Node* node = head;
    while (node)
    {
        FUN_00ba02b0_Node* cur = node;
        void* const& elem = node->elem;
        node = node->next;
        if (elem)
            ShadowSceneLight_RemoveTriGeom(elem, cur);
    }
    head = 0;
}

extern float DAT_011f940c;
extern double DAT_0104f2f0;
extern float DAT_0120005c;

struct FUN_00ba13b0_Class
{
    bool __thiscall UpdateScaledValue(int unused);
};

// @fnv 0x00ba13b0
bool FUN_00ba13b0_Class::UpdateScaledValue(int unused)
{
    *(float*)((char*)this + 0xB0) = (DAT_011f940c / DAT_0104f2f0) * DAT_0120005c;
    return true;
}

extern "C" int __cdecl rand();

struct BBA13D0CurvePoint
{
    float m_fValue;
    float m_fCumulative;
};

extern double g_dBA13D0RandMax;
extern BBA13D0CurvePoint g_akBA13D0Curve[];

// Draws a uniform random value, maps it through the cumulative curve table, and returns the scaled and offset result.
// @fnv 0x00ba13d0
// src: COMMUNITY 0x00ba13d0
float __cdecl randnormal(float fMean, float fDeviation)
{
    int i = 0;
    float fRand = (float)(rand() / g_dBA13D0RandMax);
    float fValue;
    if (fRand >= 0.5f)
    {
        while (g_akBA13D0Curve[i].m_fCumulative < fRand)
            i++;
        fValue = g_akBA13D0Curve[i - 1].m_fValue;
    }
    else
    {
        fRand = 1.0f - fRand;
        while (g_akBA13D0Curve[i].m_fCumulative < fRand)
            i++;
        fValue = 1.0f - g_akBA13D0Curve[i - 1].m_fValue;
    }
    return fValue * fDeviation + fMean;
}

struct ISArray
{
    void* m_vft;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int size);
};

struct ISEffectBase
{
    char unk04;
    char unk05;
    ISArray arr08;
    ISArray arr18;
    ISArray arr28;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;

    ISEffectBase();
    virtual ~ISEffectBase();
};

struct TexPtr
{
    void* p;
    TexPtr() : p(0)
    {}
    ~TexPtr();
};

struct ISTexSlot
{
    bool b0;
    bool b1;
    bool b2;
    TexPtr pTexture;
    int unk08;
    int unk0C;

    ISTexSlot() : b0(false), b1(false), b2(false), unk08(0), unk0C(0)
    {}
};

extern float DAT_0120004c;
extern int DAT_01200050;
extern int DAT_01200054;
extern bool DAT_01200058;
extern bool DAT_01200059;
extern float DAT_0120005c;
extern float DAT_01200060;
extern float DAT_01200064;
extern float DAT_01200068;
extern void* DAT_0120006c;

struct FUN_00ba15e0 : ISEffectBase
{
    ISTexSlot tex58;
    ISTexSlot tex68;
    ISTexSlot tex78;
    ISTexSlot tex88;
    ISTexSlot tex98;
    int unkA8;
    int unkAC;
    float unkB0;
    float unkB4;

    FUN_00ba15e0();
    virtual ~FUN_00ba15e0();
};

// @fnv 0x00ba15e0
FUN_00ba15e0::FUN_00ba15e0()
{
    arr28.SetSize(10);
    DAT_01200068 = 5.0f;
    DAT_0120006c = this;
    DAT_01200064 = 90.0f;
    DAT_01200060 = 0.5f;
    DAT_0120005c = 1.0f;
    unkB4 = unkB0 = 0.0f;
    if (DAT_01200059)
    {
        DAT_01200054 = 0x100;
        DAT_01200050 = 8;
    }
    else
    {
        DAT_01200054 = 0x80;
        DAT_01200050 = 7;
    }
    DAT_01200058 = true;
    DAT_0120004c = 1.0f / (float)DAT_01200054;
}

// FUN_00ba2d30: thiscall; tail-calls the function pointer stored at +0x4c if non-null.
class FUN_00ba2d30_cls
{
  public:
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
    void (*m_4c)();
    void RenderingTaskThread_RunLinearTasks();
};

// @fnv 0x00ba2d30
// src: COMMUNITY 0x00ba2d30
void FUN_00ba2d30_cls::RenderingTaskThread_RunLinearTasks()
{
    if (m_4c != 0)
    {
        m_4c();
    }
}

struct FUN_00ba3750_Class
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char state02;
    void __thiscall ImageSpaceTexture_SetBorrowed(unsigned char state);
};
// @fnv 0x00ba3750
// src: COMMUNITY 0x00ba3750
void FUN_00ba3750_Class::ImageSpaceTexture_SetBorrowed(unsigned char state)
{
    state02 = state;
}

// Stand-in model of the ODB record object that owns the handler table and of
// the per-entry object that the record drives.
struct FnvOdbValue
{
    int v;
};

struct FnvOdbEntry
{
    virtual void v0();
    virtual void v1(void* a, void* b, int c, FnvOdbValue d);
};

struct FnvOdbObject
{
    int unk04;
    int unk08;
    FnvOdbEntry** m_ppEntries;
    unsigned short unk10;
    unsigned short m_nCount;
    unsigned short unk14;
    int unk18;
    int* m_ppOther;
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
    unsigned char* m_pFlags;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* a);
    virtual void v5();
    virtual void v6();
    virtual void v7(void* a);
    void __thiscall SetEffectParams(int index);
    void __thiscall ProcessEntries(void* arg1, void* arg2, void* arg3, FnvOdbValue arg4);
};

// Calls v4(arg3), then for each flagged entry calls SetEffectParams, v7(arg3) and the entry's v1 with arg1, arg2, m_ppOther[i] and arg4, then v5().
// @fnv 0x00ba3fd0
void FnvOdbObject::ProcessEntries(void* arg1, void* arg2, void* arg3, FnvOdbValue aValue)
{
    v4(arg3);
    for (unsigned int i = 0; i < m_nCount; i++)
    {
        if (m_pFlags[i])
        {
            SetEffectParams(i);
            v7(arg3);
            m_ppEntries[i]->v1(arg1, arg2, m_ppOther[i], aValue);
        }
    }
    v5();
}

void* BA4080Alloc(unsigned int uiSize);

template <class T, class TAlloc>
inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = (T*)BA4080Alloc(m_usMaxSize * sizeof(T));
    else
        m_pBase = 0;
}

template <class T>
inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{}

struct BA4080Pass;
struct BA4080PendingPass;
struct BA4080Stage;
struct BA4080PendingStage;
struct BA4080FreeStage;

class FUN_00ba4080
{
  public:
    FUN_00ba4080();
    virtual ~FUN_00ba4080();

    bool m_bEnableState;
    bool m_bVisible;
    NiTPrimitiveArray<BA4080Pass*> m_kPasses;
    NiTPrimitiveArray<BA4080PendingPass*> m_kPendingPasses;
    NiTPrimitiveArray<BA4080Stage*> m_kStageArray;
    NiTPrimitiveArray<BA4080PendingStage*> m_kPendingStages;
    NiTPrimitiveArray<BA4080FreeStage*> m_kFreeStages;
};

// @fnv 0x00ba4080
FUN_00ba4080::FUN_00ba4080() : m_bEnableState(false), m_bVisible(true)
{}

class BA4190Object
{
  public:
    virtual ~BA4190Object();
};

template <class T, class TAlloc>
inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return m_usSize;
}

template <class T, class TAlloc>
inline T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}

class BA4190Base
{
  public:
    virtual ~BA4190Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NiTPrimitiveArray<BA4190Object*> m_kThirdFollowingStreamField;
};

class FUN_00ba4190 : public BA4190Base
{
  public:
    virtual ~FUN_00ba4190();
};

// @fnv 0x00ba4190
FUN_00ba4190::~FUN_00ba4190()
{
    if (m_kThirdFollowingStreamField.GetAt(0))
    {
        delete m_kThirdFollowingStreamField.GetAt(0);
        m_kThirdFollowingStreamField.SetAt(0, 0);
    }
    if (m_kThirdFollowingStreamField.GetAt(1))
    {
        delete m_kThirdFollowingStreamField.GetAt(1);
        m_kThirdFollowingStreamField.SetAt(1, 0);
    }
}

// FUN_00ba4250: thiscall setter, stores its single stack argument at this+0x58.
class FUN_00ba4250_cls
{
  public:
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
    void ImageSpaceEffectBlur_SetRadius(int value);
};

// @fnv 0x00ba4250
// src: COMMUNITY 0x00ba4250
void FUN_00ba4250_cls::ImageSpaceEffectBlur_SetRadius(int value)
{
    unk58 = value;
}

struct FUN_00ba4260_Class
{
    void __thiscall ImageSpaceEffectBlur_SetBrightPass(unsigned char value);
};

// @fnv 0x00ba4260
// src: COMMUNITY 0x00ba4260
void __thiscall FUN_00ba4260_Class::ImageSpaceEffectBlur_SetBrightPass(unsigned char value)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<int>(this) + 0x5c) = value;
}

extern float DAT_012003d4;
extern float DAT_011a9490;
extern float DAT_012003d8;
extern float DAT_011a9494;
extern float DAT_012003dc;
extern float DAT_011a9498;
extern char DAT_012003cc;
extern char DAT_011f94a9;
extern float DAT_012003d0;

// @fnv 0x00ba45d0
// src: COMMUNITY 0x00ba45d0
int ImageSpaceEffectFullScreenBlur_IsActive()
{
    if (DAT_012003d4 == DAT_011a9490 && DAT_012003d8 == DAT_011a9494 && DAT_012003dc == DAT_011a9498)
    {
        goto threshold;
    }
    if (DAT_012003cc == 0)
    {
        goto threshold;
    }
    if (DAT_011f94a9 != 0)
    {
        return 1;
    }
threshold:
    if (!(DAT_012003d0 > 0))
    {
        return 0;
    }
    return 1;
}

struct SpawnBaseA
{
    SpawnBaseA();
    virtual ~SpawnBaseA();
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

struct SpawnMember
{
    SpawnMember(int a1);
    ~SpawnMember();
    int unk00[12];
};

struct FUN_00ba4640 : SpawnBaseA
{
    SpawnMember m_28;
    int m_58;

    FUN_00ba4640();
    virtual ~FUN_00ba4640();
};

// Constructs the object, initializing m_28 with 4 and setting m_58 to -1.
// @fnv 0x00ba4640
FUN_00ba4640::FUN_00ba4640() : m_28(4)
{
    m_58 = -1;
}

namespace fnv_00ba4880 {
struct SpawnedBase
{
    SpawnedBase();
    virtual ~SpawnedBase();
};

struct SpawnedElem
{
    SpawnedElem();
    ~SpawnedElem();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};

struct SpawnedSub
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    void Init(int value);
};

extern unsigned int DAT_011a9490;
extern unsigned int DAT_011a9494;
extern unsigned int DAT_011a9498;
extern unsigned int DAT_012003d4;
extern unsigned int DAT_012003d8;
extern unsigned int DAT_012003dc;

struct FUN_00ba4880 : SpawnedBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    SpawnedSub m_28;
    SpawnedElem m_58[3];
    FUN_00ba4880();
    virtual ~FUN_00ba4880();
};

// Initializes m_28 with 4 and copies three global values into DAT_012003dc, DAT_012003d4 and DAT_012003d8.
// @fnv 0x00ba4880
FUN_00ba4880::FUN_00ba4880()
{
    m_28.Init(4);
    DAT_012003dc = DAT_011a9498;
    DAT_012003d4 = DAT_011a9490;
    DAT_012003d8 = DAT_011a9494;
}
}  // namespace fnv_00ba4880

struct ScreenTexture
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual unsigned Width();
    virtual unsigned Height();
};
struct RenderBuffer
{
    virtual void r00();
    virtual void r04();
    virtual void r08();
    virtual void r0c();
    virtual void r10();
    virtual void r14();
    virtual void r18();
    virtual void r1c();
    virtual void r20();
    virtual void r24();
    virtual void r28();
    virtual void r2c();
    virtual void r30();
    virtual void r34();
    virtual void r38();
    virtual void r3c();
    virtual void r40();
    virtual void r44();
    virtual void r48();
    virtual void r4c();
    virtual void r50();
    virtual void r54();
    virtual void r58();
    virtual void r5c();
    virtual void r60();
    virtual void r64();
    virtual void r68();
    virtual void r6c();
    virtual void r70();
    virtual void r74();
    virtual void r78();
    virtual void r7c();
    virtual void r80();
    virtual void r84();
    virtual void r88();
    virtual unsigned Width(int);
    virtual unsigned Height(int);
};
struct RenderHost
{
    virtual void h00();
    virtual void h04();
    virtual void h08();
    virtual void h0c();
    virtual void h10();
    virtual void h14();
    virtual void h18();
    virtual void h1c();
    virtual void h20();
    virtual void h24();
    virtual void h28();
    virtual void h2c();
    virtual void h30();
    virtual void h34();
    virtual void h38();
    virtual void h3c();
    virtual void h40();
    virtual void h44();
    virtual void h48();
    virtual void h4c();
    virtual void h50();
    virtual void h54();
    virtual void h58();
    virtual void h5c();
    virtual void h60();
    virtual void h64();
    virtual void h68();
    virtual void h6c();
    virtual void h70();
    virtual void h74();
    virtual void h78();
    virtual void h7c();
    virtual void h80();
    virtual void h84();
    virtual void h88();
    virtual void h8c();
    virtual void h90();
    virtual void h94();
    virtual void h98();
    virtual void h9c();
    virtual void ha0();
    virtual void ha4();
    virtual void ha8();
    virtual void hac();
    virtual void hb0();
    virtual void hb4();
    virtual void hb8();
    virtual void hbc();
    virtual void hc0();
    virtual void hc4();
    virtual RenderBuffer* GetBuffer();
};
extern RenderHost* DAT_011f9508;
struct TextureSource
{
    ScreenTexture* ImageSpaceTexture_GetTexture();
};
struct ShaderParameter
{
    void FUN_00b8a790(int, float, float, float, float);
};
struct ParameterSet
{
    ShaderParameter* p0;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ShaderParameter* p20;
    ShaderParameter* p24;
};
extern float DAT_012003d0;
extern float DAT_012003c4;
struct ScreenEffect
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ParameterSet* parameters;
    int unk20;
    int unk24;
    int unk28;
    TextureSource** texture;
    TextureSource*& GetSource() const
    {
        return *texture;
    }
    bool UpdateTexelSize(int);
};
// @fnv 0x00ba4ee0
bool ScreenEffect::UpdateTexelSize(int)
{
    float width, height;
    if (*texture && GetSource()->ImageSpaceTexture_GetTexture())
    {
        width = (float)GetSource()->ImageSpaceTexture_GetTexture()->Width();
        height = (float)GetSource()->ImageSpaceTexture_GetTexture()->Height();
    }
    else
    {
        width = (float)DAT_011f9508->GetBuffer()->Width(0);
        height = (float)DAT_011f9508->GetBuffer()->Height(0);
    }
    float y = 1.0f / height;
    float x = 1.0f / width;
    parameters->p0->FUN_00b8a790(2, x, y, 0.0f, 0.0f);
    parameters->p20->FUN_00b8a790(2, x, y, 0.0f, 0.0f);
    parameters->p24->FUN_00b8a790(2, x, y, DAT_012003d0, 0.0f);
    DAT_012003c4 = DAT_012003d0;
    return false;
}

// FUN_00ba50d0
//
// Releases the globally held reference-counted object: the reference count of
// the object is dropped and, when the last reference disappears, the object's
// second virtual (the "delete this" slot) is invoked.  The global slot is
// cleared afterwards.

extern RefCounted* DAT_012003f4;

// If the global RefCounted pointer is set, decrements its reference count, calls v1() when it reaches zero, and clears the global pointer.
// @fnv 0x00ba50d0
// src: COMMUNITY 0x00ba50d0
void ParticleShader_Free()
{
    if (DAT_012003f4 != 0)
    {
        RefCounted* pRefCounted = DAT_012003f4;
        if (InterlockedDecrement(&DAT_012003f4->m_uiRefCount) == 0)
        {
            pRefCounted->v1();
        }
        DAT_012003f4 = 0;
    }
}

extern "C" void* FUN_00ec61c0(void*, int, unsigned int);
struct ShaderProgram
{
    virtual void Reserved();
    virtual void Destroy();
    volatile long references;
    void IncRefCount()
    {
        InterlockedIncrement(&references);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&references))
            Destroy();
    }
};
struct ShaderOptions
{
    unsigned int unk00;
    unsigned int unk04;
    char parameters[64];
};
struct ShaderRequest
{
    const char* source;
    ShaderOptions options;
    ShaderRequest(const char* path) : source(path)
    {
        options.unk00 = 0;
        options.unk04 = 0;
        FUN_00ec61c0(options.parameters, 0, 64);
    }
};
void FUN_00be0c00(const char* path, char* output);
void BSsprintf(char* dest, unsigned int capacity, const char* source);
const char* FUN_00b4f380(unsigned int type);
struct ParticleShader
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
    NiPointer<ShaderProgram> vertexProgram;
    NiPointer<ShaderProgram> pixelProgram;
    ShaderProgram* FUN_00be0fe0(const char*, ShaderOptions*, const char*, const char*);
    ShaderProgram* FUN_00be1750(const char*, ShaderOptions*, const char*, const char*);
    void CompileParticleShaders();
};
// Builds source and binary paths for the particle vertex and pixel shaders and compiles both programs into vertexProgram and pixelProgram.
// @fnv 0x00ba5130
void ParticleShader::CompileParticleShaders()
{
    char sourcePath[260];
    char binaryPath[260];
    ShaderRequest vertex("particle\\v\\particle.v.hlsl");
    FUN_00be0c00(vertex.source, sourcePath);
    BSsprintf(binaryPath, 260, "PARTICLE.vso");
    vertexProgram = FUN_00be0fe0(sourcePath, &vertex.options, "vs_2_0", binaryPath);
    const char* profile = FUN_00b4f380(1);
    ShaderRequest pixel("particle\\p\\particle.p.hlsl");
    FUN_00be0c00(pixel.source, sourcePath);
    BSsprintf(binaryPath, 260, "PARTICLE.pso");
    pixelProgram = FUN_00be1750(sourcePath, &pixel.options, profile, binaryPath);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct Obj_b10008
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    Obj_b10008();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00ba82a0_cls
{
    void __thiscall BSShaderProperty_CopyMembers(Obj_b10008* o, int arg);
    Obj_b10008* __thiscall ParticleShaderProperty_CreateClone(int arg);
};

// Allocates an Obj_b10008, initializes it via FUN_00ba8b10 with arg, and returns the new object.
// @fnv 0x00ba82a0
// src: XBOX_PDB 0x00ba82a0
Obj_b10008* FUN_00ba82a0_cls::ParticleShaderProperty_CreateClone(int arg)
{
    Obj_b10008* p = new Obj_b10008();
    BSShaderProperty_CopyMembers(p, arg);
    return p;
}

extern "C" int __cdecl strncmp(const char*, const char*, unsigned int);

extern NiRTTI g_GeomRTTI_S;
extern NiRTTI g_ShaderPropRTTI_S;
extern const char* g_SkipName_S;

template <class T> struct NiPtr_S
{
    T* m_pObject;
    NiPtr_S(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPtr_S()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    NiPtr_S& operator=(const NiPtr_S& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct GeomList_S
{
    void* m_vtbl;
    NiPtr_S<NiAVObject>* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, const NiPtr_S<NiAVObject>& e);
    unsigned int AddFirstEmpty(const NiPtr_S<NiAVObject>& e);
};

void GeomList_S::SetSize(unsigned int n)
{
    NiPtr_S<NiAVObject>* p = new NiPtr_S<NiAVObject>[n];
    for (unsigned int i = 0; i < m_usSize; i++)
        p[i] = m_pBase[i];
    delete[] m_pBase;
    m_pBase = p;
    m_usMaxSize = (unsigned short)n;
}

void GeomList_S::SetAt(unsigned int i, const NiPtr_S<NiAVObject>& e)
{
    if (i >= m_usSize)
        m_usSize = (unsigned short)(i + 1);
    if (e.m_pObject)
        m_usESize++;
    m_pBase[i] = e;
}

unsigned int GeomList_S::AddFirstEmpty(const NiPtr_S<NiAVObject>& e)
{
    if (e.m_pObject == 0)
        return 0xffffffff;
    unsigned short n = m_usSize;
    for (unsigned short i = 0; i < n; i++)
    {
        if (m_pBase[i].m_pObject == 0)
        {
            m_pBase[i] = e;
            m_usESize++;
            return i;
        }
    }
    if (n >= m_usMaxSize)
        SetSize(n + m_usGrowBy);
    SetAt(n, e);
    return n;
}

static inline bool IsKind_S(const NiRTTI* target, const NiObject* obj)
{
    for (const NiRTTI* r = obj->GetRTTI(); r; r = r->m_pBaseRTTI)
        if (r == target)
            return true;
    return false;
}

struct GeomCollector_S
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
    GeomList_S m_geomList;
    void CollectShaderGeometries(NiAVObject* obj);
};

// @fnv 0x00ba8320
void GeomCollector_S::CollectShaderGeometries(NiAVObject* obj)
{
    if (!obj)
        return;
    if (IsKind_S(&g_GeomRTTI_S, obj))
    {
        NiProperty* prop = obj->GetProperty(3);
        if (prop && IsKind_S(&g_ShaderPropRTTI_S, prop))
        {
            NiPtr_S<NiAVObject> sp(obj);
            m_geomList.AddFirstEmpty(sp);
        }
        return;
    }
    NiNode* node = obj->IsSceneNode();
    if (!node)
        return;
    if (node->m_kName.m_kHandle != g_SkipName_S && strncmp(node->m_kName.m_kHandle, "Bip", 3) == 0)
        return;
    for (unsigned int i = 0; i < node->m_kChildren.m_usSize; i++)
        CollectShaderGeometries(node->m_kChildren.m_pBase[i].m_pObject);
}

class ImgRef
{
  public:
    volatile long m_iObjectReferenceCount;
    virtual void v0();
    virtual void v1();
};

class ImgLock
{
  public:
    void Enter();
    void Leave();
    __declspec(noinline) void Track(const class ImgRefHold& item);
    void Other(ImgRef* p);
};

class ImgRefHold
{
  public:
    ImgRef* m_p;
    ImgRefHold(ImgRef* p)
    {
        m_p = p;
        if (m_p)
            InterlockedIncrement(&m_p->m_iObjectReferenceCount);
    }
    ~ImgRefHold()
    {
        if (m_p)
        {
            if (InterlockedDecrement(&m_p->m_iObjectReferenceCount) == 0)
                m_p->v1();
        }
    }
};

__declspec(noinline) void ImgLock::Track(const ImgRefHold& item)
{
    Other(item.m_p);
}

class FUN_00ba8560_cls
{
  public:
    char m0[0x64];
    int m_uiContentCount;
    char m68[0x11c - 0x68];
    ImgLock m_lock;
    void CollectShaderGeometries(ImgRef* p);
    void CollectGeometry(ImgRef* p);
    void DispatchRefOp(ImgRef* p);
};

// @fnv 0x00ba8560
void FUN_00ba8560_cls::DispatchRefOp(ImgRef* pRef)
{
    m_lock.Enter();
    switch (m_uiContentCount)
    {
    case 0:
        CollectShaderGeometries(pRef);
        break;
    case 1:
        CollectGeometry(pRef);
        break;
    case 2: {
        m_lock.Track(ImgRefHold(pRef));
        break;
    }
    }
    m_lock.Leave();
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedObject
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    SpawnedObject();
};

// Allocates a SpawnedObject via its operator new and returns the new instance.
// @fnv 0x00ba8a00
// src: EXE 0x00ba8a00
SpawnedObject* __cdecl BSShaderTextureSet_CreateObject()
{
    SpawnedObject* obj = new SpawnedObject();
    return obj;
}

// FUN_00ba8aa0 : the last virtual of the shader-property class.  It forwards its
// single 4-byte argument, unchanged and in place, to the virtual that sits at
// vtable offset 0x98 of the very same object, so the whole body is
//     mov eax,[ecx] / mov eax,[eax+0x98] / jmp eax
// The forwarded virtual takes one 4-byte argument (it ends in `ret 4`), which is
// why the argument travels in the caller's own stack slot and the tail-jump
// target ends up in EAX instead of EDX.

// The class that owns the virtual at vtable offset 0x98 (slot 38).
struct FnvShaderPropertyBase
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98(void* arg);
};

// The owner: it derives from the class that declares the forwarded virtual and
// adds this one as the next slot (vtable offset 0x9c).
struct FnvShaderProperty : FnvShaderPropertyBase
{
    virtual void BSShaderProperty_CopyTo(void* arg);
};

// @fnv 0x00ba8aa0
// src: XBOX_PDB 0x00ba8aa0
void FnvShaderProperty::BSShaderProperty_CopyTo(void* arg)
{
    v98(arg);
}

class FUN_00ba8f60_cls;
class RefCountedObject
{
  public:
    virtual void v00();
    virtual void Release();
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98(FUN_00ba8f60_cls* other);
    long m_04;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_04);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_04) == 0)
            Release();
    }
};

class FUN_00ba8f60_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    NiPointer<RefCountedObject> m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    float m_28;
    float m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    float m_5c;

    void __thiscall CopyStateTo(FUN_00ba8f60_cls* dst);
};

// Copies selected fields into dst, zeroes dst->m_38, and if m_0c is set copies it and calls v98 on the copy.
// @fnv 0x00ba8f60
void FUN_00ba8f60_cls::CopyStateTo(FUN_00ba8f60_cls* dst)
{
    dst->m_20 = m_20;
    dst->m_24 = m_24;
    dst->m_28 = m_28;
    dst->m_2c = m_2c;
    dst->m_38 = 0;
    dst->m_58 = m_58;
    dst->m_5c = m_5c;
    if (m_0c.m_pObject != 0)
    {
        dst->m_0c = m_0c;
        dst->m_0c->v98(dst);
    }
}

// ---------------------------------------------------------------------------
// EnsureAllocated
//
//   if (m_48 == 0) {
//       m_48 = new FUN_00ba94b0(a);
//   }
//
// The allocation goes through the global memory manager (g_memoryManager) and
// the freshly allocated object is constructed with the incoming argument.
// ---------------------------------------------------------------------------

// The memory manager's allocator lives in another translation unit; only the
// allocation entry point is needed here.
struct MemoryManagerAllocator
{
    void* __thiscall Allocate(unsigned int size);
};

// The object that is created: 0x14 bytes, a vtable pointer plus four words.
struct FUN_00ba94b0
{
    void* m_vft;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    FUN_00ba94b0(unsigned int a);

    static void* __cdecl operator new(unsigned int size);
};

void* FUN_00ba94b0::operator new(unsigned int size)
{
    MemoryManagerAllocator* pAllocator = (MemoryManagerAllocator*)&g_memoryManager;
    return pAllocator->Allocate(size);
}

struct FUN_00ba96d0Owner
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
    void* m_48;

    void __thiscall EnsureAllocated(unsigned int a);
};

// If m_48 is null, allocates a new FUN_00ba94b0 with a and stores it in m_48.
// @fnv 0x00ba96d0
void FUN_00ba96d0Owner::EnsureAllocated(unsigned int uiValue)
{
    if (m_48 == 0)
    {
        m_48 = new FUN_00ba94b0(uiValue);
    }
}

struct PoolHolder
{
    void* Allocate(unsigned int sz);
};
extern PoolHolder DAT_011f6238;

struct Ba9740Obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    Ba9740Obj* FUN_00ba94b0(unsigned int a1);
};

struct Ba9740Guard
{
    void* m_raw;
    Ba9740Guard(void* p)
    {
        m_raw = p;
    }
    ~Ba9740Guard()
    {
        m_raw = 0;
    }
};

struct FUN_00ba9740_cls
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
    Ba9740Obj* m_p44;
    void EnsureBa9740Obj(unsigned int a1);
};

// If m_p44 is null, allocates 0x14 bytes from DAT_011f6238 and stores the object built by FUN_00ba94b0(a1) into m_p44.
// @fnv 0x00ba9740
void FUN_00ba9740_cls::EnsureBa9740Obj(unsigned int uiValue)
{
    if (m_p44 == 0)
    {
        void* raw = DAT_011f6238.Allocate(0x14);
        Ba9740Obj* made = 0;
        {
            Ba9740Guard guard(raw);
            if (raw != 0)
            {
                made = reinterpret_cast<Ba9740Obj*>(raw)->FUN_00ba94b0(uiValue);
            }
            else
            {
                made = 0;
            }
        }
        m_p44 = made;
    }
}

struct BA97B0Heap
{
    void* Game_DoHeapAlloc(unsigned int uiSize);
};

static inline BA97B0Heap& BA97B0GetHeap()
{
    return reinterpret_cast<BA97B0Heap&>(g_memoryManager);
}

class BA97B0Child
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    BA97B0Child(unsigned int uiValue);

    static void* operator new(unsigned int uiSize)
    {
        return BA97B0GetHeap().Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
};

class BA97B0Owner
{
  public:
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
    BA97B0Child* m_pkChild;

    void CreateChildIfMissing(unsigned int uiValue);
};

// Allocates a BA97B0Child with uiValue and stores it in m_pkChild when m_pkChild is null.
// @fnv 0x00ba97b0
void BA97B0Owner::CreateChildIfMissing(unsigned int uiValue)
{
    if (!m_pkChild)
        m_pkChild = new BA97B0Child(uiValue);
}

namespace fnv_00ba9820 {
struct NiMemoryManager
{
    void* Game_DoHeapAlloc(unsigned int size);
};
extern char DAT_011f6238;

struct SpawnedObject_b7307
{
    char m0[0x14];
    SpawnedObject_b7307(int a);
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<NiMemoryManager*>(&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
};

struct FUN_00ba9820_cls
{
    char m0[0x54];
    SpawnedObject_b7307* m_54;
    void CreateSpawnedObjectIfMissing(int a);
};

// If m_54 is null, allocates a SpawnedObject_b7307 with the given value and stores it in m_54.
// @fnv 0x00ba9820
void FUN_00ba9820_cls::CreateSpawnedObjectIfMissing(int aiValue)
{
    if (m_54 == 0)
    {
        m_54 = new SpawnedObject_b7307(aiValue);
    }
}
}  // namespace fnv_00ba9820

class BAA0E0Base
{
  public:
    virtual ~BAA0E0Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class FUN_00baa0e0 : public BAA0E0Base
{
  public:
    virtual ~FUN_00baa0e0();

    void Shutdown();

    int m_iFirst;
    int m_iSecond;
};

// Resets m_iFirst and m_iSecond to zero, then calls Shutdown.
// @fnv 0x00baa0e0
FUN_00baa0e0::~FUN_00baa0e0()
{
    m_iFirst = 0;
    m_iSecond = 0;
    Shutdown();
}

// Forwarder: this->m_0c->m_pFlagTarget->virtual slot 0x18, tail-jumped.
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
};

struct Holder
{
    Target* m_pFlagTarget;
};

struct FUN_00baa210_cls
{
    int unk00;
    int unk04;
    int unk08;
    Holder* m_0c;
    void ImageSpaceEffectMap_IsActive();
};

// @fnv 0x00baa210
// src: COMMUNITY 0x00baa210
void FUN_00baa210_cls::ImageSpaceEffectMap_IsActive()
{
    m_0c->m_pFlagTarget->v06();
}

struct S_00baa3f0_Class
{
    void __thiscall TallGrassShader_InitPass(unsigned int idx);
};

// If idx is in 0x16..0x3d or 0x25c..0x287, stores the corresponding slot value into DAT_0126f74c.
// @fnv 0x00baa3f0
// src: XBOX_PDB 0x00baa3f0
void S_00baa3f0_Class::TallGrassShader_InitPass(unsigned int uiIndex)
{
    const int* slots = (const int*)this;
    if (uiIndex >= 0x16 && uiIndex <= 0x3d)
    {
        DAT_0126f74c = slots[uiIndex + 5];
    }
    else if (uiIndex >= 0x25c && uiIndex <= 0x287)
    {
        DAT_0126f74c = slots[uiIndex - 0x241];
    }
}

namespace fnv_00baa570 {
struct FUN_00b79930
{
    int reference;
    ~FUN_00b79930();
};
struct FUN_00b66f20
{
    int reference;
    ~FUN_00b66f20();
};
struct FUN_00be0f10
{
    virtual ~FUN_00be0f10();
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
};
struct Global_011f6238
{
    void MemoryManager_Deallocate(void* p);
};
extern Global_011f6238 DAT_011f6238;
struct FUN_00baa570 : FUN_00be0f10
{
    FUN_00b79930 firstArray[44];
    int unk11c;
    int unk120;
    int unk124;
    FUN_00b66f20 secondArray[24];
    FUN_00b66f20 thirdArray[7];
    void* current;
    int connected;
    virtual ~FUN_00baa570();
};
// Clears connected, then passes the stored current pointer to DAT_011f6238.FUN_00aa4060 before destruction.
// @fnv 0x00baa570
FUN_00baa570::~FUN_00baa570()
{
    void* old = current;
    connected = 0;
    DAT_011f6238.MemoryManager_Deallocate(old);
}
}  // namespace fnv_00baa570

extern int DAT_01200508;

// @fnv 0x00baa630
// src: XBOX_PDB 0x00baa630
int* TallGrassShader_GetRTTI()
{
    return &DAT_01200508;
}

// Target object reached through the member at +0x1c; its virtual at vtable slot
// +0x24 (the tenth virtual) is the one invoked.
struct FUN_00baa700_target
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
    virtual void v09(int value);
};

// Fourth stack argument: only the member at +0x10 is used.
struct FUN_00baa700_param
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_00baa700_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FUN_00baa700_target* m_1c;

    int __thiscall TallGrassShader_PreProcessPipeline(int a1, int a2, int a3, FUN_00baa700_param* a4, int a5, int a6, int a7);
};

// @fnv 0x00baa700
// src: XBOX_PDB 0x00baa700
int __thiscall FUN_00baa700_cls::TallGrassShader_PreProcessPipeline(int a1, int a2, int a3, FUN_00baa700_param* pParam, int a5, int a6,
                                              int a7)
{
    m_1c->v09(pParam->m_10);
    return 0;
}

struct BAA720_Matrix;

NiPoint3* __stdcall D3DXVec3TransformCoord_00ee6df8(NiPoint3* out, const NiPoint3* in, const BAA720_Matrix* m);
bool __cdecl BSShaderAccumulator_IsShadowPass(unsigned int);

struct BAA720_Light
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
    NiPoint3 worldTranslate;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    NiPoint3 diffuse;
    float dimmer;
    NiPoint3 GetWorldTranslate() const
    {
        return worldTranslate;
    }
    NiPoint3 GetDiffuse() const
    {
        return diffuse;
    }
};

struct BAA720_Entry
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    BAA720_Light* light;
};

struct BAA720_Node;

struct BAA720_List
{
    BAA720_Entry* GetAt(BAA720_Node** iter);
};

extern NiPoint3 DAT_01200540;
extern float DAT_0120054c;

struct BAA720_Effect
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    NiColorA lightColor;
    void ApplyLightToEffect(BAA720_List* list, const BAA720_Matrix* mat, float scale, unsigned int flags);
};

// @fnv 0x00baa720
void BAA720_Effect::ApplyLightToEffect(BAA720_List* list, const BAA720_Matrix* apMatrix, float scale,
                                       unsigned int flags)
{
    BAA720_Node* iter = 0;
    BAA720_Light* light = list->GetAt(&iter)->light;
    NiPoint3 diffuse;
    CopyPointBits(diffuse, light->diffuse);
    lightColor = NiColorA(diffuse.x, diffuse.y, diffuse.z, 1.0f);
    NiPoint3 kWorldTranslate;
    CopyPointBits(kWorldTranslate, light->worldTranslate);
    NiPoint3 pos(kWorldTranslate.x, kWorldTranslate.y, kWorldTranslate.z);
    NiPoint3 viewPos;
    D3DXVec3TransformCoord_00ee6df8(&viewPos, &pos, apMatrix);
    float dimmer = light->dimmer;
    if (!BSShaderAccumulator_IsShadowPass(flags))
        dimmer = dimmer / scale;
    DAT_01200540.x = viewPos.x;
    DAT_01200540.y = viewPos.y;
    DAT_01200540.z = viewPos.z;
    DAT_0120054c = dimmer;
}

struct FUN_00bae720_Class
{
    void SkyShaderProperty_SetClampD3D(int a1);
};

// @fnv 0x00bae720
// src: XBOX_PDB 0x00bae720
void FUN_00bae720_Class::SkyShaderProperty_SetClampD3D(int a1)
{
    *(int*)((char*)this + 0x7c) = (a1 != 3) ? 3 : 0;
}

extern "C" void _ReadWriteBarrier(void);

class FUN_00bae980_cls
{
  public:
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
    NiRefObject* m_070;
    int unk74;
    int unk78;
    unsigned int m_07c;
    NiRefObject* m_080;
    float m_084;
    unsigned int m_088;
    unsigned int m_08c;

    void BSShaderProperty_CopyMembers(FUN_00bae980_cls* arg1, unsigned int arg2);
    void __thiscall SkyShaderProperty_CopyMembers(FUN_00bae980_cls* arg1, unsigned int arg2);
};

// Copies ref-counted pointers m_080 and m_070, m_084, m_08c and m_07c from this object into arg1 after calling FUN_00ba8b10.
// @fnv 0x00bae980
// src: XBOX_PDB 0x00bae980
void FUN_00bae980_cls::SkyShaderProperty_CopyMembers(FUN_00bae980_cls* apTarget, unsigned int arg2)
{
    BSShaderProperty_CopyMembers(apTarget, arg2);

    NiRefObject* old = apTarget->m_080;
    if (old != m_080)
    {
        if (old != 0)
        {
            old->DecRefCount();
        }
        apTarget->m_080 = m_080;
        if (apTarget->m_080 != 0)
        {
            apTarget->m_080->IncRefCount();
        }
    }
    *(volatile float*)&apTarget->m_084 = m_084;
    *(volatile unsigned int*)&apTarget->m_08c = m_08c;
    _ReadWriteBarrier();

    NiRefObject* old70 = apTarget->m_070;
    if (old70 != m_070)
    {
        if (old70 != 0)
        {
            old70->DecRefCount();
        }
        apTarget->m_070 = m_070;
        if (apTarget->m_070 != 0)
        {
            apTarget->m_070->IncRefCount();
        }
    }
    apTarget->m_07c = m_07c;
}

struct S_baeb00_Stream;
struct S_baeb00_BinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(S_baeb00_BinStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(S_baeb00_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct S_baeb00_Stream
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
    S_baeb00_BinStream* m_pBackingStream;
    void SaveCString(int);
};
template <class T> inline void WriteBinaryArray(S_baeb00_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.Write(pkValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void SerializeValue(S_baeb00_Stream& kStream, const T& kValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &kValue, 1);
}
struct S_baeb00_Base
{
    void BSShaderProperty_SaveBinary(S_baeb00_Stream& kStream);
};
struct S_baeb00_Obj : S_baeb00_Base
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
    void Serialize(S_baeb00_Stream& kStream);
};
// @fnv 0x00baeb00
void S_baeb00_Obj::Serialize(S_baeb00_Stream& kStream)
{
    S_baeb00_Base::BSShaderProperty_SaveBinary(kStream);
    SerializeValue(kStream, unk7c);
    kStream.SaveCString(unk74);
    SerializeValue(kStream, unk8c);
}

struct FUN_00baec80_cls
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
    int m_iValue7C;
    void SkyShaderProperty_SetClampNI(int value);
};

// @fnv 0x00baec80
// src: XBOX_PDB 0x00baec80
void FUN_00baec80_cls::SkyShaderProperty_SetClampNI(int value)
{
    m_iValue7C = value;
}

struct SpawnedObject90
{
    SpawnedObject90();
    static void* operator new(unsigned int size);
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
};

void* __cdecl Object_DispatchCommandFour(unsigned int aiSize);

struct SpawnFactory
{
    void __thiscall SkyShaderProperty_CopyMembers(SpawnedObject90* pNew, int aiArg);
    SpawnedObject90* __thiscall SkyShaderProperty_CreateClone(int aiArg);
};

// @fnv 0x00baedc0
// src: XBOX_PDB 0x00baedc0
SpawnedObject90* SpawnFactory::SkyShaderProperty_CreateClone(int aiArg)
{
    SpawnedObject90* pNew = new SpawnedObject90();
    SkyShaderProperty_CopyMembers(pNew, aiArg);
    return pNew;
}

namespace fnv_00baee40 {
struct SpawnedObject90
{
    SpawnedObject90();
    static void* operator new(unsigned int size);
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
};

void* __cdecl Object_DispatchCommandFour(unsigned int aiSize);

// Allocates and constructs a SpawnedObject90, returning the new object.
// @fnv 0x00baee40
SpawnedObject90* __cdecl CreateSpawnedObject90()
{
    return new SpawnedObject90();
}
}  // namespace fnv_00baee40

namespace fnv_00baf3c0 {

extern NiColor DAT_011f4998;

struct FUN_00baf3c0
{
    int unk00;
    NiColor color04;
    NiColor color10;
    float unk1c;
    float unk20;
    float unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    bool unk38;
    int unk3c;
    int unk40;
    bool unk44;
    int unk48;
    bool unk4c;
    bool unk4d;
    bool unk4e;
    bool unk4f;
    bool unk50;
    bool unk51;
    bool unk52;
    bool unk53;
    bool unk54;
    bool unk55;
    bool unk56;
    bool unk57;
    float unk58;
    bool unk5c;
    int unk60;
    int unk64;
    int unk68;
    bool unk6c;
    bool unk6d;
    float unk70;
    float unk74;
    NiColor color78;
    float unk84;
    bool unk88;
    bool unk89;
    bool unk8a;
    float unk8c;
    int unk90;
    int unk94;
    NiColorA color98;
    int unka8;
    int unkac;
    short unkb0;
    int unkb4;

    FUN_00baf3c0();
};

// Initializes the object's fields: colors from DAT_011f4998, numeric defaults, and boolean flags.
// @fnv 0x00baf3c0
FUN_00baf3c0::FUN_00baf3c0()
{
    unk00 = 0;
    color04 = DAT_011f4998;
    color10 = DAT_011f4998;
    unk1c = 10.0f;
    unk20 = 1.0f;
    unk24 = 1.0f;
    unk28 = 0;
    unk2c = 0;
    unk30 = 0;
    unk34 = 0;
    unk38 = false;
    unk3c = 6;
    unk40 = 7;
    unk44 = false;
    unk48 = 4;
    unk4c = false;
    unk4d = false;
    unk4e = false;
    unk4f = false;
    unk50 = false;
    unk51 = false;
    unk52 = false;
    unk53 = false;
    unk54 = false;
    unk55 = true;
    unk56 = true;
    unk57 = false;
    unk58 = 0.0f;
    unk5c = false;
    unk60 = 0;
    unk64 = 0;
    unk68 = 0;
    unk6c = false;
    unk6d = false;
    unk70 = 1.0f;
    unk74 = 4.0f;
    color78 = DAT_011f4998;
    unk84 = 10.0f;
    unk88 = false;
    unk89 = false;
    unk8a = false;
    unk8c = 1.0f;
    unka8 = 0;
    unkac = 0;
    unkb0 = 0;
    unkb4 = 3;
}
}  // namespace fnv_00baf3c0

namespace fnv_00baf580 {
struct NiVariant
{
    int unk00;
    int m_04;
};

struct NiBase24
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    NiVariant m_14;
};

struct FUN_00baf580_iface
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
    virtual void v36(int index, NiPointer<NiRefObject>& out);
};

struct FUN_00baf580_cls
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
    int unka0;
    int unka4;
    FUN_00baf580_iface* m_a8;
    char m_ac;
    void BSShaderData_CheckTextureAlphas();
};

// @fnv 0x00baf580
// src: COMMUNITY 0x00baf580
void FUN_00baf580_cls::BSShaderData_CheckTextureAlphas()
{
    if (m_a8 == 0)
    {
        return;
    }
    for (int i = 0; i < 6; ++i)
    {
        NiPointer<NiRefObject> pObjectPtr;
        m_a8->v36(i, pObjectPtr);
        if (pObjectPtr.m_pObject != 0)
        {
            NiBase24* h = reinterpret_cast<NiBase24*>(reinterpret_cast<NiTexture*>(pObjectPtr.m_pObject)->m_pkRendererData);
            NiVariant* v = h ? &h->m_14 : 0;
            if (v->m_04 == 5 || v->m_04 == 6)
            {
                *((char*)&m_ac + i) = 1;
            }
        }
    }
}
}  // namespace fnv_00baf580

namespace fnv_00bafa80 {

class TargetObject_cls
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
    virtual void v57(int value);
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
    NiRefObject* m_a4;
};

class FUN_00bafa80_cls
{
  public:
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
    NiRefObject* m_a8;
    int unkAC;
    int unkB0;
    int m_b4;

    void BSShaderData_SetupTexturesLightingShader(TargetObject_cls* a1);
};

// Replaces a1->m_a4 with m_a8, releasing the old reference and retaining the new one, then calls a1->v57 with m_b4.
// @fnv 0x00bafa80
// src: COMMUNITY 0x00bafa80
void FUN_00bafa80_cls::BSShaderData_SetupTexturesLightingShader(TargetObject_cls* apTarget)
{
    NiRefObject* pNewRef = m_a8;
    NiRefObject* old = apTarget->m_a4;
    if (old != pNewRef)
    {
        if (old != 0)
        {
            old->DecRefCount();
        }
        apTarget->m_a4 = pNewRef;
        if (pNewRef != 0)
        {
            pNewRef->IncRefCount();
        }
    }
    apTarget->v57(m_b4);
}
}  // namespace fnv_00bafa80

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);


class TargetBAF
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084;
    BSString m_kName;
};

class SourceBAF
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual const char* GetName(int iIndex);
};

class OwnerBAF
{
  public:
    void SetTargetName(TargetBAF* pkTarget);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4;
    SourceBAF* m_pkSource;
};

// If m_pkSource is set, copies the source's name at index 0 into pkTarget->m_kName via BSString::Set.
// @fnv 0x00bafcb0
void OwnerBAF::SetTargetName(TargetBAF* pkTarget)
{
    if (m_pkSource)
    {
        NiFixedString kName(m_pkSource->GetName(0));
        pkTarget->m_kName.Set(kName.m_kHandle, 0);
    }
}

namespace fnv_00bafe10 {

struct MatProp
{
    void* m_vft;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiColor m_amb;
    NiColor m_diff;
    int unk34;
    float m_f38;
    float m_f3c;
    float m_f40;
    unsigned int m_rev;
    int unk48;
    MatProp();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void SetAmb(const NiColor& c)
    {
        m_amb = c;
        m_rev++;
    }
    void SetDiff(const NiColor& c)
    {
        m_diff = c;
        m_rev++;
    }
    void SetF38(float f)
    {
        m_f38 = f;
        m_rev++;
    }
    void SetF3C(float f)
    {
        m_f3c = f;
        m_rev++;
    }
    void SetF40(float f)
    {
        m_f40 = f;
        m_rev++;
    }
};

struct Target
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
    virtual void v38(MatProp*);
};

struct Src
{
    void* m_vft;
    NiColor m_amb;
    NiColor m_diff;
    float m_f1c;
    float m_f20;
    float m_f24;
    Target* m_t28;
    Target* m_t2c;
    Target* m_t30;
    Target* m_t34;
    void CreateAndAttachMaterialProperty(NiAVObject* obj);
};

// Allocates a MatProp, copies the ambient/diffuse colors and three floats into it, notifies up to four targets, then attaches it to obj.
// @fnv 0x00bafe10
void Src::CreateAndAttachMaterialProperty(NiAVObject* obj)
{
    MatProp* p = new MatProp;
    p->SetAmb(m_amb);
    p->SetDiff(m_diff);
    p->SetF38(m_f1c);
    p->SetF3C(m_f20);
    p->SetF40(m_f24);
    if (m_t28)
        m_t28->v38(p);
    if (m_t2c)
        m_t2c->v38(p);
    if (m_t30)
        m_t30->v38(p);
    if (m_t34)
        m_t34->v38(p);
    obj->AttachProperty(reinterpret_cast<NiObject*>(p));
}
}  // namespace fnv_00bafe10

struct Triple3
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};

struct SpawnBase
{
    virtual void v0();
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
    SpawnBase();
};

struct FUN_00bb0d40 : SpawnBase
{
    virtual void v0();
    int m_60;
    int unk64;
    float m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    FUN_00bb0d40(int a1, float a2, Triple3* a3, Triple3* a4, Triple3* a5, int a6, int a7);
};

// @fnv 0x00bb0d40
FUN_00bb0d40::FUN_00bb0d40(int a1, float a2, Triple3* a3, Triple3* a4, Triple3* a5, int a6, int abFlag) : SpawnBase()
{
    m_68 = a2;
    m_60 = a1;
    m_6c = a4->m_uiX;
    m_70 = a4->m_uiY;
    m_74 = a4->m_uiZ;
    m_78 = a5->m_uiX;
    m_7c = a5->m_uiY;
    m_80 = a5->m_uiZ;
    m_84 = a3->m_uiX;
    m_88 = a3->m_uiY;
    m_8c = a3->m_uiZ;
    m_90 = 0;
    m_94 = 0;
    m_9c = a6;
    m_98 = abFlag != 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class BB0DE0Ptr
{
  public:
    ~BB0DE0Ptr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    BB0DE0Ptr& operator=(NiRefObject* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }

    NiRefObject* m_pObject;
};

class BB0DE0Base
{
  public:
    virtual ~BB0DE0Base();

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
};

class FUN_00bb0de0 : public BB0DE0Base
{
  public:
    virtual ~FUN_00bb0de0();

    int m_iFadeIndex;
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
    BB0DE0Ptr m_pReferencedObject;
};

// @fnv 0x00bb0de0
FUN_00bb0de0::~FUN_00bb0de0()
{
    m_iFadeIndex = 0;
    m_pReferencedObject = 0;
}

struct BB0ED0CloningProcess;

struct BB0ED0Values
{
    int m_aiData0;
    int m_aiData1;
    int m_aiData2;
    int m_aiData3;
    int m_aiData4;
    int m_aiData5;
    int m_aiData6;
    int m_aiData7;
    int m_aiData8;
};

class BB0ED0Base
{
  public:
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

    void CopyMemberData(BB0ED0Base* pkDest, BB0ED0CloningProcess& kCloning);
};

class BB0ED0Property : public BB0ED0Base
{
  public:
    int m_iFlags;
    int unk64;
    int unk68;
    int m_iValue0;
    int m_iValue1;
    int m_iValue2;
    int m_iValue3;
    int m_iValue4;
    int m_iValue5;
    int m_iValue6;
    int m_iValue7;
    int m_iValue8;
    NiPointer<NiRefObject> m_spTexture;
    int m_iMode;

    void CloneTo(BB0ED0Property* pkDest, BB0ED0CloningProcess& kCloning);
};

// Copies the base part and then the flags, the nine values, the texture pointer and the mode into pkDest.
// @fnv 0x00bb0ed0
void BB0ED0Property::CloneTo(BB0ED0Property* pkDest, BB0ED0CloningProcess& kCloning)
{
    BB0ED0Base::CopyMemberData(pkDest, kCloning);
    pkDest->m_iFlags = m_iFlags;
    pkDest->m_iValue0 = m_iValue0;
    pkDest->m_iValue1 = m_iValue1;
    pkDest->m_iValue2 = m_iValue2;
    pkDest->m_iValue3 = m_iValue3;
    pkDest->m_iValue4 = m_iValue4;
    pkDest->m_iValue5 = m_iValue5;
    pkDest->m_iValue6 = m_iValue6;
    pkDest->m_iValue7 = m_iValue7;
    pkDest->m_iValue8 = m_iValue8;
    pkDest->m_spTexture = m_spTexture;
    pkDest->m_iMode = m_iMode;
}

extern "C" __declspec(thread) unsigned int gShaderThreadMarker;

struct ShaderThreadMarkerScope
{
    unsigned int previous;
    ShaderThreadMarkerScope() : previous(gShaderThreadMarker)
    {
        gShaderThreadMarker = 0x29;
    }
    ~ShaderThreadMarkerScope()
    {
        gShaderThreadMarker = previous;
    }
};

struct ShaderRenderCommand
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int dirty;
    void __thiscall FUN_00ba9ee0(void* source, unsigned int code, int active, int a, int b, int c, int d, int e);
};

struct ShaderRenderState
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
    unsigned int packedVersion;
    ShaderRenderCommand* command;

    void __thiscall FUN_00ba95e0(int enable);
    ShaderRenderCommand* __thiscall PrecipitationShaderProperty_GetRenderPasses(void* data, unsigned int version, int unused1, unsigned int variant,
                                                 int unused2, int FlushUsageData);
};

// @fnv 0x00bb0fc0
// src: XBOX_PDB 0x00bb0fc0
ShaderRenderCommand* __thiscall ShaderRenderState::PrecipitationShaderProperty_GetRenderPasses(void* data, unsigned int version, int unused1,
                                                                unsigned int variant, int unused2, int FlushUsageData)
{
    ShaderThreadMarkerScope marker;
    if (packedVersion != version)
    {
        FUN_00ba95e0(1);
        command->dirty = 0;
        command->FUN_00ba9ee0(data, 0x2cf, 1, 0, 0, 0, 0, 0);
        packedVersion = (variant << 8) | version;
    }
    return command;
}

namespace fnv_00bb1080 {
extern "C" char DAT_010b9008[];
extern "C" void* Object_DispatchCommandFour(unsigned int);
struct FUN_00bb1080_tls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00bb1080_tls g_tls;

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x29;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};

class SpawnedObject
{
  public:
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
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
    unsigned int m_60;
    unsigned int unk64;
    float m_68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int m_90;
    unsigned int unk94;
    unsigned int m_98;
    unsigned int m_9c;
    void ctorBase();
    SpawnedObject()
    {
        ctorBase();
        m_68 = 0.0f;
        m_vtbl = (void*)DAT_010b9008;
        m_60 = 0;
        m_90 = 0;
        m_98 = 1;
        m_9c = 0;
        m_1c = 0x12;
    }
    void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

class FUN_00bb1080_cls
{
  public:
    void unk_bb0ed0(SpawnedObject* p, int a1);
    SpawnedObject* PrecipitationShaderProperty_CreateClone(int a1);
};

// Allocates a SpawnedObject, initializes it via unk_bb0ed0 with a1, and returns it while a TLS flag guard is active.
// @fnv 0x00bb1080
// src: XBOX_PDB 0x00bb1080
SpawnedObject* FUN_00bb1080_cls::PrecipitationShaderProperty_CreateClone(int a1)
{
    TlsFlagGuard guard;
    SpawnedObject* p = new SpawnedObject();
    this->unk_bb0ed0(p, a1);
    return p;
}
}  // namespace fnv_00bb1080

struct Matrix44;

LocalVec3* __stdcall D3DXVec3TransformCoord(LocalVec3* out, const LocalVec3* v, const Matrix44* m);
LocalVec3* __stdcall D3DXVec3Normalize(LocalVec3* out, const LocalVec3* v);
LocalVec3* __stdcall D3DXVec3TransformNormal(LocalVec3* out, const LocalVec3* v, const Matrix44* m);

struct LightOwner
{
    unsigned short __thiscall InitializeTESResources();
};

extern LocalVec3 DAT_011fa1f0;
extern LocalVec3 DAT_011fa180;
extern float DAT_011fa200;
extern Vec4 DAT_01200618;
extern LocalVec3 DAT_01200628;
extern float DAT_01200634;

// @fnv 0x00bb1960
void __stdcall UpdateLightDirection(LightOwner* owner, const Matrix44* matrix, float scale)
{
    LocalVec3 dir;
    dir.x = -DAT_011fa1f0.x;
    dir.y = -DAT_011fa1f0.y;
    dir.z = -DAT_011fa1f0.z;
    LocalVec3 tmp;
    D3DXVec3TransformCoord(&tmp, &dir, matrix);
    D3DXVec3Normalize(&dir, &tmp);
    DAT_01200618 = Vec4(dir.x, dir.y, dir.z, 0.0f);
    if (owner->InitializeTESResources() > 0)
    {
        LocalVec3 v;
        v.x = DAT_011fa180.x;
        v.y = DAT_011fa180.y;
        v.z = DAT_011fa180.z;
        LocalVec3 out;
        D3DXVec3TransformNormal(&out, &v, matrix);
        DAT_01200628.x = out.x;
        DAT_01200628.y = out.y;
        DAT_01200628.z = out.z;
        DAT_01200634 = DAT_011fa200 / scale;
    }
}

struct FUN_00bb1a90_Camera
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
    float unk6C;
    float unk70;
    float unk74;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    float unk88;
};

extern FUN_00bb1a90_Camera* DAT_011f917c;
extern float DAT_01200638;
extern float DAT_0120063C;
extern float DAT_01200640;
extern float DAT_01200644;
extern float DAT_01200648;
extern float DAT_0120064C;
extern float DAT_01200650;
extern float DAT_01200654;

// @fnv 0x00bb1a90
// src: COMMUNITY 0x00bb1a90
void __cdecl SpeedTreeLeafShader_UpdateScaleAdjustment()
{
    float values[6];

    values[0] = DAT_011f917c->unk6C;
    values[1] = DAT_011f917c->unk78;
    values[2] = DAT_011f917c->unk84;
    values[3] = DAT_011f917c->unk70;
    values[4] = DAT_011f917c->unk7C;
    values[5] = DAT_011f917c->unk88;

    DAT_01200648 = values[0];
    DAT_0120064C = values[1];
    DAT_01200650 = values[2];
    DAT_01200654 = 0.0f;
    DAT_01200638 = values[3];
    DAT_0120063C = values[4];
    DAT_01200640 = values[5];
    DAT_01200644 = 0.0f;
}

extern int DAT_01200610;

// @fnv 0x00bb1d30
// src: XBOX_PDB 0x00bb1d30
void* __cdecl SpeedTreeLeafShader_GetRTTI()
{
    return &DAT_01200610;
}

extern int DAT_0126f74c;
class FUN_00bb2580_cls
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int m_384;
    void UpdateFields_00bb1f60(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    int SpeedTreeLeafShader_UpdatePipeline(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

// Calls v59, then FUN_00bb1f60 with the seven arguments, stores m_384 into DAT_0126f74c and returns 0.
// @fnv 0x00bb2580
// src: XBOX_PDB 0x00bb2580
int FUN_00bb2580_cls::SpeedTreeLeafShader_UpdatePipeline(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    v59();
    UpdateFields_00bb1f60(a1, a2, a3, a4, a5, a6, a7);
    DAT_0126f74c = m_384;
    return 0;
}

extern "C" D3DXMATRIX* __stdcall D3DXMatrixInverseBB2(D3DXMATRIX* pOut, float* pDeterminant,
                                                         const D3DXMATRIX* pM);

__forceinline void GetD3DFromNiBB2(D3DXMATRIX& kD3D, const NiTransform& kNi)
{
    kD3D._11 = kNi.m_Rotate.m_pEntry[0][0] * kNi.m_fScale;
    kD3D._12 = kNi.m_Rotate.m_pEntry[1][0] * kNi.m_fScale;
    kD3D._13 = kNi.m_Rotate.m_pEntry[2][0] * kNi.m_fScale;
    kD3D._21 = kNi.m_Rotate.m_pEntry[0][1] * kNi.m_fScale;
    kD3D._22 = kNi.m_Rotate.m_pEntry[1][1] * kNi.m_fScale;
    kD3D._23 = kNi.m_Rotate.m_pEntry[2][1] * kNi.m_fScale;
    kD3D._31 = kNi.m_Rotate.m_pEntry[0][2] * kNi.m_fScale;
    kD3D._32 = kNi.m_Rotate.m_pEntry[1][2] * kNi.m_fScale;
    kD3D._33 = kNi.m_Rotate.m_pEntry[2][2] * kNi.m_fScale;
    kD3D._41 = kNi.m_Translate.x;
    kD3D._42 = kNi.m_Translate.y;
    kD3D._43 = kNi.m_Translate.z;
    kD3D._14 = 0.0f;
    kD3D._24 = 0.0f;
    kD3D._34 = 0.0f;
    kD3D._44 = 1.0f;
}

class GeometryBB2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iType;
};

inline int IsSkinnedBB2(const GeometryBB2* pkGeom)
{
    return pkGeom ? pkGeom->m_iType == 6 : 0;
}

class RenderObjBB2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    GeometryBB2* m_pkRenderableGeometry;
};

class SetterBB2
{
  public:
    void SetWorldTransform(const NiTransform* pkXform, int iUnk);
};

void __cdecl SpeedTreeLeafShader_UpdateScaleAdjustment();

class ShaderBB2
{
  public:
    void Apply(GeometryBB2* pkGeom, const D3DXMATRIX* pkInvWorld, float fScale);
    int RenderGeometry(int iA, int iB, int iC, int iD, RenderObjBB2* pkObj, int iF, const NiTransform* pkXform,
                       int iH);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    SetterBB2* m_pkSetter;
};

// @fnv 0x00bb25d0
int ShaderBB2::RenderGeometry(int iA, int iB, int iC, int iD, RenderObjBB2* pkObj, int iF,
                              const NiTransform* pkXform, int iH)
{
    m_pkSetter->SetWorldTransform(pkXform, 0);

    D3DXMATRIX kWorld;
    D3DXMATRIX kInvWorld;
    GetD3DFromNiBB2(kWorld, *pkXform);
    D3DXMatrixInverseBB2(&kInvWorld, 0, &kWorld);

    GeometryBB2* pkGeom = pkObj->m_pkRenderableGeometry;
    Apply(IsSkinnedBB2(pkGeom) ? pkGeom : 0, &kInvWorld, pkXform->m_fScale);
    SpeedTreeLeafShader_UpdateScaleAdjustment();
    return 0;
}

struct RenderObject
{
    void* unk00;
    void* unk04;
    void* imageResource;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    int referenceCount;
    void IncRefCount()
    {
        ++referenceCount;
    }
    void DecRefCount()
    {
        if (--referenceCount == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
    void NiD3DTextureStage_ReturnStageToPool();
};
struct RendererManager
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    RenderObject** currentRenderObject;
};
struct InputObject
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
    virtual void* GetResource();
};
struct SourceInput
{
    void* unk00;
    void* unk04;
    void* unk08;
    InputObject* source;
};
struct RenderController
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void Update();
    void SetImageResourceAndUpdate(SourceInput* input);
};
// Gets the resource from the input's source, stores it as the current render object's imageResource, then calls Update().
// @fnv 0x00bb26d0
void RenderController::SetImageResourceAndUpdate(SourceInput* input)
{
    InputObject* inputObject = input->source;
    RendererManager* manager = reinterpret_cast<RendererManager*>(DAT_0126f74c);
    NiPointer<RenderObject> renderObject(*manager->currentRenderObject);
    renderObject->imageResource = inputObject->GetResource();
    Update();
}

struct S_00bb2fc0_Mat
{
    float _11;
    float _12;
    float _13;
    float _14;
    float _21;
    float _22;
    float _23;
    float _24;
    float _31;
    float _32;
    float _33;
    float _34;
    float _41;
    float _42;
    float _43;
    float _44;
    S_00bb2fc0_Mat()
    {
        _43 = 0.0f;
        _42 = 0.0f;
        _41 = 0.0f;
        _34 = 0.0f;
        _32 = 0.0f;
        _31 = 0.0f;
        _24 = 0.0f;
        _23 = 0.0f;
        _21 = 0.0f;
        _14 = 0.0f;
        _13 = 0.0f;
        _12 = 0.0f;
        _44 = 1.0f;
        _33 = 1.0f;
        _22 = 1.0f;
        _11 = 1.0f;
    }
};
extern S_00bb2fc0_Mat DAT_01200688[];
S_00bb2fc0_Mat* __stdcall D3DXMatrixRotationYawPitchRoll_00ee6e04(S_00bb2fc0_Mat* m, float x, float y, float z);
S_00bb2fc0_Mat* __stdcall D3DXMatrixTranspose_00ee6dd4(S_00bb2fc0_Mat* out, const S_00bb2fc0_Mat* in);

// @fnv 0x00bb2fc0
// src: GUESS 0x00bb2fc0 (confidence: low)
bool __cdecl Object_ProcessAndReturnValue_00bb2fc0(unsigned int index, float x, float y)
{
    if (index >= 4)
    {
        return false;
    }
    S_00bb2fc0_Mat m;
    D3DXMatrixRotationYawPitchRoll_00ee6e04(&m, x, y, 0.0f);
    D3DXMatrixTranspose_00ee6dd4(&m, &m);
    DAT_01200688[index] = m;
    return true;
}

struct GlobalObjectO2_00bb3130
{
    int unk00;
};
extern GlobalObjectO2_00bb3130 g_01200788;

// @fnv 0x00bb3130
// src: XBOX_PDB 0x00bb3130
GlobalObjectO2_00bb3130* __cdecl SpeedTreeBranchShaderProperty_GetRTTI()
{
    return &g_01200788;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct BaseObj_b9933
{
    BaseObj_b9933(int arg);
    virtual void b00();
};

struct Obj_b9933 : public BaseObj_b9933
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
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
    int m_58;
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    Obj_b9933(int arg) : BaseObj_b9933(arg)
    {
        m_58 = 4;
        m_1c = 0xa;
    }
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00bb3170_cls
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual int GetArg();
    void Attach(Obj_b9933* o, int arg);
    Obj_b9933* CreateAndAttach(int arg);
};

// Allocates an Obj_b9933 with GetArg(), attaches it with arg, and returns the new object.
// @fnv 0x00bb3170
Obj_b9933* FUN_00bb3170_cls::CreateAndAttach(int arg)
{
    Obj_b9933* p = new Obj_b9933(GetArg());
    Attach(p, arg);
    return p;
}

struct FUN_00bb3210_cls
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    void* m_104;

    void* GetField104();
};

// @fnv 0x00bb3210
// src: GUESS 0x00bb3210 (confidence: low)
void* FUN_00bb3210_cls::GetField104()
{
    return m_104;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
__forceinline void* __cdecl operator new(unsigned int size)
{
    return Object_DispatchCommandFour(size);
}
struct ImageSpaceTextureDescriptor
{
    unsigned int format;
    unsigned int flags;
    unsigned short layerCount;
};
struct ImageSource
{
    ImageSpaceTextureDescriptor* descriptor() const
    {
        return *reinterpret_cast<ImageSpaceTextureDescriptor* const*>(reinterpret_cast<const char*>(this) + 0xb8);
    }
};
struct ImageBuffer
{
    void* pixels;
    void* pixelFormat;
    unsigned int width, height, stride, sliceSize, layers, options, resourceId;
    void* owner;
    unsigned int referenceCount;
    ImageBuffer(unsigned int layerCount, bool allocateStorage);
    void __thiscall SetSize_Thunk(bool enabled);
    void __thiscall NiAdditionalGeometryData_SetDataBlock(bool owned, void* input);
    void __thiscall NiAdditionalGeometryData_SetDataStream(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int layers,
                                 unsigned int width, unsigned int height);
};
struct DataSize
{
    unsigned int length;
};
struct ImageProvider
{
    typedef unsigned short(__thiscall* CountGetter)(ImageProvider*);
    typedef void*(__thiscall* DataGetter)(ImageProvider*, DataSize, unsigned int);
    unsigned short getMaxLayers()
    {
        return reinterpret_cast<CountGetter>((*reinterpret_cast<void***>(this))[0x124 / 4])(this);
    }
    void* getLayerData(unsigned int length, unsigned int first)
    {
        void** functions = *reinterpret_cast<void***>(this);
        DataSize size = {length};
        return reinterpret_cast<DataGetter>(functions[0x120 / 4])(this, size, first);
    }
    ImageBuffer* __thiscall SpeedTreeBranchShaderProperty_SetupGeometryData(ImageSource* source);
};
// @fnv 0x00bb3280
// src: COMMUNITY 0x00bb3280
ImageBuffer* __thiscall ImageProvider::SpeedTreeBranchShaderProperty_SetupGeometryData(ImageSource* source)
{
    if (source != 0)
    {
        const unsigned short usRequestedLayers = source->descriptor()->layerCount;
        if (usRequestedLayers <= getMaxLayers())
        {
            const unsigned int uiLayerCount = source->descriptor()->layerCount;
            ImageBuffer* buffer = new ImageBuffer(uiLayerCount, true);
            buffer->SetSize_Thunk(true);
            buffer->NiAdditionalGeometryData_SetDataBlock(false, getLayerData(static_cast<unsigned short>(uiLayerCount) << 4, 0));
            buffer->NiAdditionalGeometryData_SetDataStream(0, 0, 0, 4, uiLayerCount, 16, 16);
            return buffer;
        }
    }
    return 0;
}

struct FUN_00bb33a0_Class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;

    void __thiscall SpeedTreeShaderLightingProperty_SetClampD3D(int parameter);
};

// @fnv 0x00bb33a0
// src: XBOX_PDB 0x00bb33a0
void FUN_00bb33a0_Class::SpeedTreeShaderLightingProperty_SetClampD3D(int parameter)
{
    unk80 = (parameter != 3) ? 3 : 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

template <class T> class BBB3500Pointer
{
  public:
    BBB3500Pointer(T* pObject = 0) : m_pObject(pObject)
    {}
    ~BBB3500Pointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    BBB3500Pointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    T* m_pObject;
};

class BBB3500Base
{
  public:
    BBB3500Base();
    virtual ~BBB3500Base();

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
};

class FUN_00bb3500_cls : public BBB3500Base
{
  public:
    FUN_00bb3500_cls(NiRefObject* pkObject);
    virtual ~FUN_00bb3500_cls();

    BBB3500Pointer<NiRefObject> m_pReferencedObject;
};

// Stores pkObject into the reference-counted pointer member, incrementing its reference count.
// @fnv 0x00bb3500
FUN_00bb3500_cls::FUN_00bb3500_cls(NiRefObject* pkObject)
{
    m_pReferencedObject = pkObject;
}

struct SmartReference
{
    RefCounted* m_pObject;

    static void Release(RefCounted* ref)
    {
        if (InterlockedDecrement(&ref->m_uiRefCount) == 0)
            ref->v1();
    }

    SmartReference& operator=(RefCounted* replacement)
    {
        if (m_pObject != replacement)
        {
            if (m_pObject)
                Release(m_pObject);
            m_pObject = replacement;
        }
        return *this;
    }

    ~SmartReference()
    {
        if (m_pObject)
            Release(m_pObject);
    }
};

struct ResourceBase
{
    virtual ~ResourceBase();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
};

struct FUN_00bb35b0 : ResourceBase
{
    SmartReference m_kSmartReference;
    virtual ~FUN_00bb35b0();
};

// Destructor that clears the SmartReference member by assigning a null RefCounted pointer.
// @fnv 0x00bb35b0
FUN_00bb35b0::~FUN_00bb35b0()
{
    m_kSmartReference = static_cast<RefCounted*>(0);
}

class BB3660Base
{
  public:
    BB3660Base();
    virtual ~BB3660Base();
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
};

class FUN_00bb3660 : public BB3660Base
{
  public:
    int m_iFadeIndex;
    int m_iMode;
    NiPointer<NiRefObject> m_spTexture;

    FUN_00bb3660(NiRefObject* pkTexture);
    virtual ~FUN_00bb3660();
};

// @fnv 0x00bb3660
FUN_00bb3660::FUN_00bb3660(NiRefObject* pkTexture) : m_iFadeIndex(0), m_iMode(3), m_spTexture(pkTexture)
{}

extern int DAT_01200798;

// @fnv 0x00bb36a0
// src: XBOX_PDB 0x00bb36a0
int* __cdecl SpeedTreeShaderLightingProperty_GetRTTI()
{
    return &DAT_01200798;
}

struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    int value;
    int SpeedTreeShaderLightingProperty_GetData();
};
// @fnv 0x00bb36c0
// src: XBOX_PDB 0x00bb36c0
int CpuObject::SpeedTreeShaderLightingProperty_GetData()
{
    return value;
}

namespace fnv_00bb3740 {

class FUN_00bb3740_cls
{
  public:
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
    NiPointer<NiRefObject> m_pReferencedObject;

    void NiPhysXFluidEmitterDesc_SetFrameShape(NiRefObject* obj);
};

// @fnv 0x00bb3740
// src: GAMEBRYO_LIB 0x00bb3740
void FUN_00bb3740_cls::NiPhysXFluidEmitterDesc_SetFrameShape(NiRefObject* obj)
{
    m_pReferencedObject = obj;
}
}  // namespace fnv_00bb3740

class BB3880Object
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual const NiRTTI* GetRTTI() const;
};

extern const NiRTTI g_kBB3880RTTIA;
extern const NiRTTI g_kBB3880RTTIB;

inline bool BB3880IsKindOf(const NiRTTI& kRTTI, const BB3880Object* pkObject)
{
    if (!pkObject)
        return false;
    for (const NiRTTI* pkRTTI = pkObject->GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
    {
        if (pkRTTI == &kRTTI)
            return true;
    }
    return false;
}

typedef void(__cdecl* BB3880Callback)(BB3880Object* pkObject, void* pvParent, void* pvData);

class BB3880Owner
{
  public:
    virtual void unk00();
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
    BB3880Object* m_pPointer;

    void NotifyObject(BB3880Callback pfnCallback, void* pvData);
};

// If the owner holds an object, checks its RTTI against two known types and invokes pfnCallback with that object, a null parent and pvData.
// @fnv 0x00bb3880
void BB3880Owner::NotifyObject(BB3880Callback pfnCallback, void* pvData)
{
    if (m_pPointer)
    {
        bool bKnown = BB3880IsKindOf(g_kBB3880RTTIA, m_pPointer) || BB3880IsKindOf(g_kBB3880RTTIB, m_pPointer);
        pfnCallback(m_pPointer, 0, pvData);
    }
}

namespace fnv_00bb3950 {
extern long DAT_011f4400;
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned);

struct S_00bb3950_Pool
{
    void* Alloc(unsigned int size);
};
extern S_00bb3950_Pool DAT_011f6238;

struct S_00bb3950_Base
{
    long refs;
    S_00bb3950_Base() throw()
    {
        refs = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
    virtual ~S_00bb3950_Base() throw()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
};

struct FUN_00bb3950 : S_00bb3950_Base
{
    void* unk08;
    float unk0c;
    float unk10;
    float unk14;
    FUN_00bb3950();
    virtual ~FUN_00bb3950();
};

// @fnv 0x00bb3950
FUN_00bb3950::FUN_00bb3950()
{
    unk08 = DAT_011f6238.Alloc(0x300);
    FUN_00ec61c0(unk08, 0, 0x300);
    unk0c = 0.0f;
    unk10 = 0.0f;
    unk14 = 0.0f;
}
}  // namespace fnv_00bb3950

struct FUN_00bb3a50_sub;
struct FUN_00bb3a50_mgr;
struct FUN_00bb3a50_env;

struct FUN_00bb3a50_mgr
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
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    int m_e0;
};

struct FUN_00bb3a50_env
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
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    FUN_00bb3a50_mgr* m_194;
};

FUN_00bb3a50_env* __cdecl BSShaderManager_GetAccumulator();

struct FUN_00bb3a50_sub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_10;
    void __thiscall FUN_00ba9ee0(int a, int b, int c, int d, int e, int f, int g, int h);
};

struct FUN_00bb3a50_cls
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
    int m_38;
    FUN_00bb3a50_sub* m_3c;
    unsigned int unk40;
    unsigned int unk44;
    int m_48;
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
    unsigned char m_74;
    void __thiscall FUN_00ba95e0(int a);
    short __thiscall BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
    int __thiscall BSShaderLightingProperty_GetFirstActiveNonShadowLight(int* out);
    void* __thiscall SpeedTreeLeafShaderProperty_GetRenderPasses(int a1, int a2, unsigned short* a3, int a4, int a5, int a6);
};

// @fnv 0x00bb3a50
// src: XBOX_PDB 0x00bb3a50
void* FUN_00bb3a50_cls::SpeedTreeLeafShaderProperty_GetRenderPasses(int a1, int aiKeyLow, unsigned short* apOutFlag, int aiKeyHigh, int a5, int a6)
{
    int key = (aiKeyHigh << 8) | aiKeyLow;
    if (aiKeyHigh == 9)
    {
        return (void*)m_48;
    }
    if (m_38 != aiKeyLow || m_74 != 0)
    {
        FUN_00ba95e0(-1);
        m_3c->m_10 = 0;
        int edi = (int)BSShaderManager_GetAccumulator()->m_194->m_e0;
        if (BSShaderLightingProperty_GetNumberofActiveNonShadowLights() == 0)
        {
            m_3c->FUN_00ba9ee0(a1, 0x3e, 1, 1, edi, 0, 0, 0);
        }
        else
        {
            aiKeyHigh = 0;
            int r = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&aiKeyHigh);
            m_3c->FUN_00ba9ee0(a1, 0x3f, 1, 2, edi, r, 0, 0);
        }
        m_38 = key;
    }
    *apOutFlag = 1;
    return (void*)m_3c;
}

extern int DAT_012007a0;

// @fnv 0x00bb3c60
// src: XBOX_PDB 0x00bb3c60
int* __cdecl SpeedTreeLeafShaderProperty_GetRTTI()
{
    return &DAT_012007a0;
}

struct FUN_00bb3c70_cls
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
    unsigned short m_8C;
    unsigned short SpeedTreeLeafShaderProperty_GetLevel();
};

// @fnv 0x00bb3c70
// src: XBOX_PDB 0x00bb3c70
unsigned short FUN_00bb3c70_cls::SpeedTreeLeafShaderProperty_GetLevel()
{
    return m_8C;
}

// FUN_00bb3c80: thiscall getter returning the int member at +0x88.
struct FUN_00bb3c80_cls
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
    int m_88;
    int SpeedTreeLeafShaderProperty_GetLeafData();
};

// @fnv 0x00bb3c80
// src: XBOX_PDB 0x00bb3c80
int FUN_00bb3c80_cls::SpeedTreeLeafShaderProperty_GetLeafData()
{
    return m_88;
}

class BB3CD0Base
{
  public:
    virtual ~BB3CD0Base();
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
};

class FUN_00bb3cd0 : public BB3CD0Base
{
  public:
    NiPointer<NiRefObject> m_spTexture;

    virtual ~FUN_00bb3cd0();
};

// Destructor that releases the texture smart pointer by setting m_spTexture to null.
// @fnv 0x00bb3cd0
FUN_00bb3cd0::~FUN_00bb3cd0()
{
    m_spTexture = 0;
}

extern char DAT_010b9828;

void* Object_InitializeFields_00b71720();

struct FUN_00bb4080_Class
{
    void* unk00;
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

    void* GeometryDecalShaderProperty_GeometryDecalShaderProperty();
};

// Calls FUN_00b71720, sets unk00 to &DAT_010b9828 and initializes unk7C, unk58 and unk1C, then returns this.
// @fnv 0x00bb4080
// src: COMMUNITY 0x00bb4080
void* FUN_00bb4080_Class::GeometryDecalShaderProperty_GeometryDecalShaderProperty()
{
    Object_InitializeFields_00b71720();
    this->unk00 = &DAT_010b9828;
    this->unk7C = 0;
    this->unk58 = 0x10;
    this->unk1C = 3;
    return this;
}

extern int DAT_012007a8;

// @fnv 0x00bb40b0
// src: XBOX_PDB 0x00bb40b0
int* __cdecl GeometryDecalShaderProperty_GetRTTI()
{
    return &DAT_012007a8;
}

namespace fnv_00bb40c0 {

class SpawnedBase_bb40
{
  public:
    virtual void Vslot00();
    ~SpawnedBase_bb40();
};

class FUN_00bb40c0_cls : public SpawnedBase_bb40
{
  public:
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    int unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48;
    int unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78;
    NiPointer<NiRefObject> m_7c;
    virtual void Vslot00();
    ~FUN_00bb40c0_cls();
};

// @fnv 0x00bb40c0
FUN_00bb40c0_cls::~FUN_00bb40c0_cls()
{}
}  // namespace fnv_00bb40c0

struct SpawnBaseObj
{
    SpawnBaseObj();
    virtual ~SpawnBaseObj();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct SpawnArgIface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC(void* obj);
};

struct FUN_00bb4540 : SpawnBaseObj
{
    int m_1c;
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
    int m_58;
    virtual ~FUN_00bb4540();
    FUN_00bb4540(SpawnArgIface* arg);
};

// Calls arg->vCC(this), then sets m_58 to 0x1d and m_1c to 0xc.
// @fnv 0x00bb4540
FUN_00bb4540::FUN_00bb4540(SpawnArgIface* pSpawnArg) : SpawnBaseObj()
{
    pSpawnArg->vCC(this);
    m_58 = 0x1d;
    m_1c = 0xc;
}

extern int DAT_010b9910;

// @fnv 0x00bb45b0
// src: GUESS 0x00bb45b0 (confidence: low)
void __fastcall Runtime_UpdateState_00bb45b0(unsigned int* param_1)
{
    *param_1 = reinterpret_cast<unsigned int>(&DAT_010b9910);
    FUN_00b67380(param_1);
}

// FUN_00bb45c0 : a one-line function - getter
extern int g_target_00bb45c0;
// @fnv 0x00bb45c0
// src: COMMUNITY 0x00bb45c0
void* Lighting30ShaderProperty_GetRTTI()
{
    return &g_target_00bb45c0;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

class ObjectBase_b9105
{
  public:
    ObjectBase_b9105();
    virtual void v00();
    char m04[0xfc];
};

class ObjectDerived_b9105 : public ObjectBase_b9105
{
  public:
    ObjectDerived_b9105()
    {
        m100 = 0;
    }
    virtual void v00();
    int m100;
    int m104;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

// Allocates and constructs a new ObjectDerived_b9105 via its custom operator new and returns it.
// @fnv 0x00bb45d0
ObjectDerived_b9105* CreateObjectDerived()
{
    return new ObjectDerived_b9105();
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct ThreadState
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
};
extern __declspec(thread) ThreadState s_tlsData;

struct ThreadStateGuard
{
    int previous;
    ThreadStateGuard() : previous(s_tlsData.unk2B4)
    {
        s_tlsData.unk2B4 = 0x28;
    }
    ~ThreadStateGuard()
    {
        s_tlsData.unk2B4 = previous;
    }
};

struct BaseObj_b9974
{
    BaseObj_b9974();
    virtual void v00();
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};

struct Obj_b9974 : public BaseObj_b9974
{
    Obj_b9974()
    {
        m100 = 0;
    }
    virtual void v00();
    int m100;
    int m104;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00bb4680_cls
{
    void Lighting30ShaderProperty_CopyMembers(Obj_b9974* p, int arg);
    Obj_b9974* Lighting30ShaderProperty_CreateClone(int arg);
};

// @fnv 0x00bb4680
// src: COMMUNITY 0x00bb4680
Obj_b9974* FUN_00bb4680_cls::Lighting30ShaderProperty_CreateClone(int arg)
{
    ThreadStateGuard guard;
    Obj_b9974* p = new Obj_b9974();
    this->Lighting30ShaderProperty_CopyMembers(p, arg);
    return p;
}


struct BSShaderProperty__RenderPassArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void Add(NiGeometry* geom, unsigned short passType, bool enabled, unsigned char a, ShadowSceneLight* light,
             ShadowSceneLight* b, ShadowSceneLight* c, ShadowSceneLight* d);
};

struct ShaderStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;
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
    BSShaderProperty__RenderPassArray* unk50;
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    float unkE0;

    void ClearPassTextureSlots(int a);
    BSShaderProperty__RenderPassArray* GetRenderPassArray(NiGeometry* geom);
};

// @fnv 0x00bb5c90
BSShaderProperty__RenderPassArray* ShaderStub::GetRenderPassArray(NiGeometry* apGeometry)
{
    if (unkE0 > 0.0f)
        return 0;

    bool bFlag = false;
    if (apGeometry->m_PropertyState.m_aspProps[0])
        bFlag = (static_cast<NiAlphaProperty*>(apGeometry->m_PropertyState.m_aspProps[0])->m_usAlphaArg >> 9) & 1;
    bool bHasData = false;
    if (apGeometry->m_spModelData.m_pObject->m_pkColor)
        bHasData = true;

    ClearPassTextureSlots(1);
    if (unk50->unk10 == 0)
    {
        if (bHasData)
        {
            if (bFlag)
            {
                if ((unk20 & 2) > 0)
                    unk50->Add(apGeometry, 0x2ed, true, 0, 0, 0, 0, 0);
                else
                    unk50->Add(apGeometry, 0x2ec, true, 0, 0, 0, 0, 0);
            }
            else
            {
                if ((unk20 & 2) > 0)
                    unk50->Add(apGeometry, 0x2e7, true, 0, 0, 0, 0, 0);
                else
                    unk50->Add(apGeometry, 0x2e6, true, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            if (bFlag)
            {
                if ((unk20 & 2) > 0)
                    unk50->Add(apGeometry, 0x2e1, true, 0, 0, 0, 0, 0);
                else
                    unk50->Add(apGeometry, 0x2e0, true, 0, 0, 0, 0, 0);
            }
            else
            {
                if ((unk20 & 2) > 0)
                    unk50->Add(apGeometry, 0x2db, true, 0, 0, 0, 0, 0);
                else
                    unk50->Add(apGeometry, 0x2da, true, 0, 0, 0, 0, 0);
            }
        }
    }
    return unk50;
}

struct FUN_00bb5fa0_cls
{
    int unk00;
    int unk04;
    unsigned short m_08;
    unsigned short m_0A;
    unsigned short unk0C;
    unsigned short m_0E;
    void SubA(unsigned int n);
    void SubB(unsigned int n, char** out);
};

void __stdcall BSShaderPPLightingProperty_GetViewerStrings(void* p);

extern void* DAT_012007b0;

// @fnv 0x00bb5fa0
// src: XBOX_PDB 0x00bb5fa0
void __stdcall Lighting30ShaderProperty_GetViewerStrings(FUN_00bb5fa0_cls* self)
{
    BSShaderPPLightingProperty_GetViewerStrings(self);
    char* local = NiViewerStrings_NiGetViewerString_Title(DAT_012007b0);
    unsigned int edi = self->m_0A;
    if (edi >= self->m_08)
    {
        self->SubA(self->m_0E + edi);
    }
    self->SubB(edi, &local);
}

struct FUN_00a59d30_Class
{
    void* __thiscall FUN_00a59d30(int);
    void __thiscall ForwardToSubobject(void*);
};

struct FUN_00bb5ff0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;
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
    float unk5C;

    bool __thiscall BSShaderPPLightingProperty_SetupGeometry(FUN_00a59d30_Class* a1);
    bool __thiscall Lighting30ShaderProperty_SetupGeometry(FUN_00a59d30_Class* a1);
};

// @fnv 0x00bb5ff0
// src: XBOX_PDB 0x00bb5ff0
bool FUN_00bb5ff0_Class::Lighting30ShaderProperty_SetupGeometry(FUN_00a59d30_Class* a1)
{
    bool result = BSShaderPPLightingProperty_SetupGeometry(a1);
    if ((unk20 & 0x80000) > 0)
    {
        unk5C = 1.0f;
    }
    void* prop = a1->FUN_00a59d30(10);
    if (prop)
    {
        a1->ForwardToSubobject(prop);
    }
    return result;
}

// FUN_00bb7200 : a one-line function - getter
extern int g_target_00bb7200;
// @fnv 0x00bb7200
// src: XBOX_PDB 0x00bb7200
void* BSDistantTreeShaderProperty_GetRTTI()
{
    return &g_target_00bb7200;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct FUN_00bb7170_Node
{
    FUN_00bb7170_Node();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
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
};

struct FUN_00bb7210_Class
{
    void __thiscall BSShaderProperty_CopyMembers(FUN_00bb7170_Node* node, int a1);
    FUN_00bb7170_Node* CreateNode(int a1);
};

// @fnv 0x00bb7210
FUN_00bb7170_Node* FUN_00bb7210_Class::CreateNode(int a1)
{
    FUN_00bb7170_Node* node = new FUN_00bb7170_Node();
    BSShaderProperty_CopyMembers(node, a1);
    return node;
}

namespace fnv_00bb7370 {
struct S_00bb7370_Mm
{
    void MemoryManager_Deallocate(int p);
};
extern S_00bb7370_Mm DAT_011f6238;
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct S_00bb7370_Base
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
    int unk60;
    int unk64;
    virtual ~S_00bb7370_Base();
};
struct S_00bb7370_Obj : S_00bb7370_Base
{
    __forceinline ~S_00bb7370_Obj()
    {
        DAT_011f6238.MemoryManager_Deallocate(unk64);
    }
    S_00bb7370_Obj* FUN_00bb7370(unsigned int flags);
};
// Runs the object's destructor and, when flags has bit 0 set, frees the 0x68-byte object, then returns this.
// @fnv 0x00bb7370
S_00bb7370_Obj* S_00bb7370_Obj::FUN_00bb7370(unsigned int flags)
{
    this->S_00bb7370_Obj::~S_00bb7370_Obj();
    if (flags & 1)
        FUN_00aa1460(this, 0x68);
    return this;
}
}  // namespace fnv_00bb7370

void* __cdecl Object_DispatchCommandFour(unsigned int);
// Allocates a 0xb0-byte TileShaderProperty with flag false, returning the pointer.
// @fnv 0x00bb7ef0
// src: EXE 0x00bb7ef0
TileShaderProperty* __cdecl TileShaderProperty_CreateObject()
{
    return new TileShaderProperty(false);
}

extern void* DAT_012007d8;
extern const char DAT_010b9e1c[];
extern const char DAT_010b9e0c[];
extern const char DAT_010b9dfc[];
extern const char DAT_010b9df4[];
extern const char DAT_010b9dec[];
extern char DAT_011f444c;
extern char* __cdecl NiGetViewerString_00a7d550(const char*, float);
extern char* __cdecl NiGetViewerString_00a7d5e0(const char*, unsigned int);
struct GameGraphicsObject
{
    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
    virtual void Method3();
    virtual void Method4();
    virtual void Method5();
    virtual void Method6();
    virtual void Method7();
    virtual void Method8();
    virtual void Method9();
    virtual void Method10();
    virtual void Method11();
    virtual void Method12();
    virtual void Method13();
    virtual void Method14();
    virtual void Method15();
    virtual void Method16();
    virtual void Method17();
    virtual void Method18();
    virtual void Method19();
    virtual void Method20();
    virtual void Method21();
    virtual void Method22();
    virtual void Method23();
    virtual void Method24();
    virtual void Method25();
    virtual void Method26();
    virtual void Method27();
    virtual void Method28();
    virtual void Method29();
    virtual void Method30();
    virtual void Method31();
    virtual void Method32();
    virtual void Method33();
    virtual void Method34();
    virtual void Method35();
    virtual void Method36();
    virtual void Method37();
    virtual void Method38();
    virtual unsigned int* GetGraphicsValue();
};
extern GameGraphicsObject* __stdcall FUN_00653290(const void*);
struct ShaderPassParameters
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    void* volatile enabledData;
    unsigned int unknown64;
    float parameter68;
    float parameter6c;
    float parameter70;
    float parameter74;
    void AppendShaderParameters(StrArr*);
};
// @fnv 0x00bb7f90
void ShaderPassParameters::AppendShaderParameters(StrArr* array)
{
    WriteToSettingArray(array);
    char* value = NiViewerStrings_NiGetViewerString_Title(DAT_012007d8);
    {
        unsigned int at = array->m_usSize;
        if (at >= array->m_usMaxSize)
            array->SetSize(at + array->m_usGrowBy);
        array->SetAt(at, value);
    }
    value = NiGetViewerString_00a7d550(DAT_010b9e1c, parameter68);
    {
        unsigned int at = array->m_usSize;
        if (at >= array->m_usMaxSize)
            array->SetSize(at + array->m_usGrowBy);
        array->SetAt(at, value);
    }
    value = NiGetViewerString_00a7d550(DAT_010b9e0c, parameter6c);
    {
        unsigned int at = array->m_usSize;
        if (at >= array->m_usMaxSize)
            array->SetSize(at + array->m_usGrowBy);
        array->SetAt(at, value);
    }
    value = NiGetViewerString_00a7d550(DAT_010b9dfc, parameter70);
    {
        unsigned int at = array->m_usSize;
        if (at >= array->m_usMaxSize)
            array->SetSize(at + array->m_usGrowBy);
        array->SetAt(at, value);
    }
    value = NiGetViewerString_00a7d550(DAT_010b9df4, parameter74);
    {
        unsigned int at = array->m_usSize;
        if (at >= array->m_usMaxSize)
            array->SetSize(at + array->m_usGrowBy);
        array->SetAt(at, value);
    }
    if (enabledData)
    {
        GameGraphicsObject* object = FUN_00653290(&DAT_011f444c);
        if (object)
        {
            unsigned int graphicalValue = *object->GetGraphicsValue();
            value = NiGetViewerString_00a7d5e0(DAT_010b9dec, graphicalValue);
            {
                unsigned int at = array->m_usSize;
                if (at >= array->m_usMaxSize)
                    array->SetSize(at + array->m_usGrowBy);
                array->SetAt(at, value);
            }
        }
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int);
void __cdecl FUN_00aa1460(void*, unsigned int);

struct FogProp_bb8280
{
    int unk[25];
    FogProp_bb8280();
    void CopyMemberData(FogProp_bb8280* pDest, void* pCloning);
    FogProp_bb8280* Clone(void* pCloning);
    static void* __cdecl operator new(unsigned int s)
    {
        return Object_DispatchCommandFour(s);
    }
    static void __cdecl operator delete(void* p, unsigned int s)
    {
        FUN_00aa1460(p, s);
    }
};

// @fnv 0x00bb8280
FogProp_bb8280* FogProp_bb8280::Clone(void* pCloning)
{
    FogProp_bb8280* pNewInstance = new FogProp_bb8280();
    CopyMemberData(pNewInstance, pCloning);
    return pNewInstance;
}

struct FNVArray
{
    void* vtable;
    void* elements;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growth;

    void Reserve(unsigned int newCapacity);
    void Insert(unsigned int index, char* const* value);

    void Append(char* value)
    {
        const unsigned int insertionIndex = count;
        if (insertionIndex >= capacity)
            Reserve(insertionIndex + growth);
        Insert(insertionIndex, &value);
    }
};

extern void* gSetting;
extern char* NiGetViewerString_00a7d550(const char* name, float value);
extern const char gFirstName[];
extern const char gSecondName[];

struct FNVCaller
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
    float value2c;
    float value30;
    void Initialize(FNVArray* destination);
    void BSFogProperty_GetViewerStrings(FNVArray* destination);
};

// @fnv 0x00bb8300
// src: XBOX_PDB 0x00bb8300
void FNVCaller::BSFogProperty_GetViewerStrings(FNVArray* destination)
{
    Initialize(destination);
    destination->Append(NiViewerStrings_NiGetViewerString_Title(gSetting));
    destination->Append(NiGetViewerString_00a7d550(gFirstName, value2c));
    destination->Append(NiGetViewerString_00a7d550(gSecondName, value30));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefTexture
{
    virtual void unused();
    virtual void Release();
    volatile long count;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&count))
            Release();
    }
};
extern RefTexture* DAT_01200810;
extern RefTexture* DAT_01200814;
extern RefTexture* DAT_01200818;
struct EffectParam
{
    virtual ~EffectParam();
};
class TextureOwned
{
  public:
    ~TextureOwned();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct EffectArray
{
    int unk00;
    EffectParam** data;
    int unk08, unk0c;
    void FUN_00ba3aa0(unsigned, EffectParam* const&);
};
struct TextureArray
{
    int unk00;
    TextureOwned** data;
    int unk08, unk0c;
    void FUN_00ba3aa0(unsigned, TextureOwned* const&);
};
struct BaseEffect
{
    virtual void unused();
    int unk04, unk08, unk0c, unk10, unk14;
    EffectArray effects;
    TextureArray textures;
    ~BaseEffect();
};
struct FUN_00bb83d0 : BaseEffect
{
    virtual void unused();
    ~FUN_00bb83d0();
};
// @fnv 0x00bb83d0
FUN_00bb83d0::~FUN_00bb83d0()
{
    if (DAT_01200810)
    {
        DAT_01200810->DecRefCount();
        DAT_01200810 = 0;
    }
    if (DAT_01200814)
    {
        DAT_01200814->DecRefCount();
        DAT_01200814 = 0;
    }
    if (DAT_01200818)
    {
        DAT_01200818->DecRefCount();
        DAT_01200818 = 0;
    }
    if (effects.data[0])
    {
        delete effects.data[0];
        effects.FUN_00ba3aa0(0, (EffectParam*)0);
    }
    if (effects.data[1])
    {
        delete effects.data[1];
        effects.FUN_00ba3aa0(1, (EffectParam*)0);
    }
    if (textures.data[3])
    {
        delete textures.data[3];
        textures.FUN_00ba3aa0(3, (TextureOwned*)0);
    }
    if (textures.data[4])
    {
        delete textures.data[4];
        textures.FUN_00ba3aa0(4, (TextureOwned*)0);
    }
    if (textures.data[2])
    {
        delete textures.data[2];
        textures.FUN_00ba3aa0(2, (TextureOwned*)0);
    }
}

extern NiPointer<NiRefObject> g_spBB8590Shared;

class BB8590Effect
{
  public:
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
    ImageSpaceTexture** m_ppTextures;

    void ClearTextures();
};

// Clears the shared reference and, for each of the 5 textures, resets it to null via SetTexture(0).
// @fnv 0x00bb8590
void BB8590Effect::ClearTextures()
{
    g_spBB8590Shared = 0;
    for (int i = 0; i < 5; i++)
    {
        ImageSpaceTexture* pkTexture = m_ppTextures[i];
        if (pkTexture)
            pkTexture->SetTexture(0);
    }
}

extern int DAT_012007fc;

class B5270Item;

struct B5270Obj
{
    virtual void v0();
    virtual void v1(int a, int b, B5270Item* c, int d);
};

struct B5270Holder
{
    B5270Obj* m_f0;
    B5270Obj* m_f4;
};

class FUN_00bb8890_cls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a);
    virtual void v5();
    virtual void v6();
    virtual void v7(B5270Item* item);
    int unk04;
    int unk08;
    B5270Holder* m_0c;
    int unk10;
    int unk14;
    int unk18;
    B5270Item** m_1c;
    void SetEffectParams(int index);
    void ProcessItem(int a1, int a2, int a3, int a4);
};

// @fnv 0x00bb8890
void FUN_00bb8890_cls::ProcessItem(int a1, int a2, int a3, int a4)
{
    v4(a3);
    B5270Item* item = m_1c[DAT_012007fc];
    SetEffectParams(DAT_012007fc);
    v7(item);
    B5270Obj* obj;
    switch (DAT_012007fc)
    {
    case 1:
        obj = m_0c->m_f4;
        break;
    default:
        obj = m_0c->m_f0;
        break;
    }
    obj->v1(a1, a2, item, a4);
    v5();
}

struct SpawnedBase
{
    virtual void unk00();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;

    SpawnedBase();
    ~SpawnedBase();
};

struct SpawnedSub
{
    int m_00;

    SpawnedSub(int value);
};

struct FUN_00bb9180_cls : SpawnedBase
{
    SpawnedSub m_28;

    FUN_00bb9180_cls();
    virtual void unk00();
};

// Constructs a SpawnedBase-derived object, initializing its SpawnedSub member m_28 with the value 4.
// @fnv 0x00bb9180
FUN_00bb9180_cls::FUN_00bb9180_cls() : m_28(4)
{}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

struct BA02F0TexArray
{
    void* m_ppVirtualMethodTable;
    void* m_data;
    unsigned short m_maxSize;
    unsigned short m_iElementCount;
    unsigned short m_free;
    unsigned short m_growBy;
    void __thiscall SetSize(unsigned int);
    ~BA02F0TexArray();
};

struct BA02F0EffectBase
{
    BA02F0EffectBase();
    virtual ~BA02F0EffectBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    BA02F0TexArray m_textures;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
};

struct FUN_00ba02f0;
extern FUN_00ba02f0* g_pBA02F0Instance;
extern bool g_bBA02F0Flag;
extern float g_ISParam0;
extern float g_ISParam1;
extern float g_ISParam2;
extern float g_ISParam3;
extern float g_ISParam4;
extern float g_ISParam5;
extern float g_ISParam6;
extern float g_ISParam7;
extern float g_ISParam8;

struct FUN_00ba02f0 : BA02F0EffectBase
{
    NiPointer<NiRefObject> m_pReferencedObject;
    float m_5c;
    float m_60;
    float m_64;
    float m_68;
    float m_6c;
    float m_70;

    FUN_00ba02f0();
    virtual ~FUN_00ba02f0();
};

// @fnv 0x00ba02f0
FUN_00ba02f0::FUN_00ba02f0()
{
    m_textures.SetSize(2);
    g_pBA02F0Instance = this;
    g_bBA02F0Flag = false;
    m_5c = 0.0f;
    m_60 = 0.0f;
    m_64 = 0.1f;
    m_68 = 0.1f;
    m_6c = 1.0f;
    m_70 = 0.0f;
    g_ISParam0 = 0.0f;
    g_ISParam1 = 0.1f;
    g_ISParam2 = 0.6f;
    g_ISParam3 = 0.985f;
    g_ISParam4 = 0.01f;
    g_ISParam5 = 0.4f;
    g_ISParam6 = 0.6f;
    g_ISParam7 = 0.985f;
    g_ISParam8 = 0.05f;
    m_pReferencedObject = 0;
}

inline void* __cdecl operator new[](unsigned int uiSize)
{
    return ((MemoryManagerAllocator*)&g_memoryManager)->Allocate(uiSize);
}

inline void __cdecl operator delete[](void* pvMem)
{
    g_memoryManager.Deallocate(pvMem);
}

class ISKernelEffect
{
  public:
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
    float** m_ppfWeightsA;
    float** m_ppfWeightsB;
    float fUnkB0;
    float fUnkB4;
    bool m_bDecalsEnabled;

    void ImageSpaceEffectWaterFFT_FillWaterUtilityBuffers();
    void ImageSpaceEffectWaterFFT_FillFFTUtilityTextures(int iSize, int iSamples);
    void AllocateStorage_00ba2590();
};

// @fnv 0x00ba2590
// src: GUESS 0x00ba2590 (confidence: low)
void ISKernelEffect::AllocateStorage_00ba2590()
{
    int i;
    m_ppfWeightsA = new float*[DAT_01200054 + 1];
    m_ppfWeightsB = new float*[DAT_01200054 + 1];
    for (i = 0; i < DAT_01200054 + 1; i++)
    {
        m_ppfWeightsA[i] = new float[DAT_01200054 + 1];
        m_ppfWeightsB[i] = new float[DAT_01200054 + 1];
    }
    ImageSpaceEffectWaterFFT_FillWaterUtilityBuffers();
    ImageSpaceEffectWaterFFT_FillFFTUtilityTextures(DAT_01200054, DAT_01200050);
    for (i = 0; i < DAT_01200054 + 1; i++)
    {
        delete[] m_ppfWeightsA[i];
        delete[] m_ppfWeightsB[i];
    }
    delete[] m_ppfWeightsA;
    delete[] m_ppfWeightsB;
    m_ppfWeightsA = 0;
    m_ppfWeightsB = 0;
    m_bDecalsEnabled = true;
}

namespace fnv_00ba63e0 {
struct S_00ba63e0_MM
{
    void* __thiscall Allocate(unsigned int);
    void __thiscall Deallocate(void*);
};
extern S_00ba63e0_MM DAT_011f6238;

struct S_00ba63e0_Elem
{
    char unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00ba63e0_Elem();
    static void* operator new[](unsigned int n)
    {
        return DAT_011f6238.Allocate(n);
    }
    static void operator delete[](void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
};
struct S_00ba63e0_ArrBase
{
    virtual ~S_00ba63e0_ArrBase();
    void** unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
    S_00ba63e0_ArrBase()
    {
        unk08 = 0;
        unk0e = 1;
        unk0a = 0;
        unk0c = 0;
        unk04 = 0;
    }
};
struct S_00ba63e0_Arr : S_00ba63e0_ArrBase
{
    virtual ~S_00ba63e0_Arr();
    void RemoveAll()
    {
        for (unsigned short i = 0; i < unk0a; i++)
            unk04[i] = 0;
        unk0a = 0;
        unk0c = 0;
    }
};
struct FUN_00ba63e0 : NiObject
{
    int unk08;
    unsigned short unk0c;
    int unk10;
    S_00ba63e0_Elem* unk14;
    int unk18;
    S_00ba63e0_Arr unk1c;
    FUN_00ba63e0(unsigned short a, unsigned int n);
    virtual ~FUN_00ba63e0();
};
// Initializes the object: stores a in unk0c and n in unk10, allocates an array of n elements into unk14, clears unk1c and zeroes unk08 and unk18.
// @fnv 0x00ba63e0
FUN_00ba63e0::FUN_00ba63e0(unsigned short a, unsigned int auiCount)
{
    unk08 = 0;
    unk0c = a;
    unk10 = auiCount;
    unk14 = new S_00ba63e0_Elem[auiCount];
    unk1c.RemoveAll();
    unk18 = 0;
}
}  // namespace fnv_00ba63e0

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

struct ListItemBA8
{
    ListItemBA8* m_pkNext;
    ListItemBA8* m_pkPrev;
    NiAVObject* m_pkElement;
};
ListItemBA8* __cdecl NewListItemBA8(NiAVObject* pkObject);
class GeometryListBA8
{
  public:
    __declspec(noinline) void AddTail(const NiPointer<NiAVObject>& spRetainedObject)
    {
        ListItemBA8* pkItem = NewListItemBA8(spRetainedObject.m_pObject);
        pkItem->m_pkNext = 0;
        pkItem->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkItem;
        else
            m_pkHead = pkItem;
        m_pkTail = pkItem;
        m_uiCount++;
    }

    ListItemBA8* m_pkHead;
    ListItemBA8* m_pkTail;
    unsigned int m_uiCount;
};
class GeometryCollectorBA8
{
  public:
    void CollectGeometry(NiAVObject* pkObject);

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
    GeometryListBA8 m_kGeometry;
};
// Recursively walks the node tree, adding objects that have both geometry data and a node to m_kGeometry.
// @fnv 0x00ba8480
void GeometryCollectorBA8::CollectGeometry(NiAVObject* pkObject)
{
    if (!pkObject)
        return;
    void* pvGeometryData = pkObject->m_spCollisionObject.m_pObject;
    NiNode* pkNode = pkObject->IsSceneNode();
    if (pvGeometryData && pkNode)
        m_kGeometry.AddTail(pkObject);
    if (pkNode)
    {
        for (unsigned int i = 0; i < pkNode->m_kChildren.m_usSize; i++)
            CollectGeometry(pkNode->m_kChildren.m_pBase[i].m_pObject);
    }
}

namespace fnv_00ba9660 {
#include <windows.h>

struct PoolHolder
{
    void* Allocate(unsigned int sz);
};
extern PoolHolder DAT_011f6238;

struct NewObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    NewObj(int a1);
    static void* operator new(unsigned int sz) throw()
    {
        return DAT_011f6238.Allocate(sz);
    }
    static void operator delete(void* p) throw()
    {}
};

struct FUN_00ba9660_cls
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
    NewObj* m_40;

    void EnsureNewObj(int a1);
};

// Allocates a NewObj with a1 and stores it in m_40 if m_40 is null.
// @fnv 0x00ba9660
void FUN_00ba9660_cls::EnsureNewObj(int aiValue)
{
    if (m_40 == 0)
    {
        m_40 = new NewObj(aiValue);
    }
}
}  // namespace fnv_00ba9660

struct FogVector4
{
    float x, y, z, w;
    FogVector4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct FogColor3
{
    float r, g, b;
};
struct FogInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FogColor3 color;
    float nearDistance;
    float farDistance;
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
    float density;
};
extern unsigned char DAT_011f91c4;
extern FogVector4 DAT_011fa280;
extern FogVector4 DAT_011fa290;
extern FogVector4 DAT_011a9bd0;
extern const float DAT_0108cb00;
FogInfo* BSShaderManager_GetFogProperty(unsigned int);
// @fnv 0x00baa430
// src: XBOX_PDB 0x00baa430
void __stdcall TallGrassShader_SetupPassConstants(int unused)
{
    FogInfo* fog = BSShaderManager_GetFogProperty(DAT_011f91c4);
    if (fog)
    {
        float farDistance = fog->farDistance;
        FogColor3 color = fog->color;
        DAT_011fa280 = FogVector4(farDistance, farDistance - fog->nearDistance, fog->density, 0.0f);
        DAT_011fa290 = FogVector4(color.r, color.g, color.b, 0.0f);
    }
    else
    {
        DAT_011fa280 = FogVector4(DAT_0108cb00, 0.0f, 0.0f, 0.0f);
        DAT_011fa290 = DAT_011a9bd0;
    }
}

// Prelude helper whose body the unit prelude omits.
// Image space effect constructor: point at the shared shader and reserve three texture slots.
class AD500TextureArray
{
  public:
    void SetSize(unsigned int uiMaxSize);
};
class AD500Shader;
extern AD500Shader g_kAD500Shader;
class AD500ImageSpaceEffect
{
  public:
    AD500ImageSpaceEffect();
    virtual ~AD500ImageSpaceEffect();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    AD500TextureArray m_kTextureSwapList;
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
};
class FUN_00bad500 : public AD500ImageSpaceEffect
{
  public:
    FUN_00bad500();
    virtual ~FUN_00bad500();

    AD500Shader* m_pShaderHandle;
};
// Initializes the effect by pointing its shader field at g_kAD500Shader and setting the texture array size to 3.
// @fnv 0x00bad500
FUN_00bad500::FUN_00bad500()
{
    m_pShaderHandle = &g_kAD500Shader;
    m_kTextureSwapList.SetSize(3);
}

extern char DAT_011ff8c4;

struct RenderPassShader_bae7b0
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
    BSShaderProperty__RenderPassArray* m_passes;
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
    int m_type;

    void ClearPassTextureSlots(int a);
    bool HasExtraPass() const
    {
        return m_type == 0 || m_type == 4 || m_type == 3;
    }
    bool IsType24() const
    {
        return m_type == 2 || m_type == 4;
    }
    BSShaderProperty__RenderPassArray* BuildRenderPasses(NiGeometry* geom, int a2, int a3, int a4, int a5, int a6);
};

// Selects and adds render passes to m_passes based on m_type and global flags, returning the pass array.
// @fnv 0x00bae7b0
BSShaderProperty__RenderPassArray* RenderPassShader_bae7b0::BuildRenderPasses(NiGeometry* geom, int aiUnused2,
                                                                              int aiUnused3, int aiUnused4,
                                                                              int aiUnused5, int aiUnused6)
{
    ClearPassTextureSlots(2);
    BSShaderProperty__RenderPassArray* passes = m_passes;
    if (passes->unk10 == 0)
    {
        switch (m_type)
        {
        case 1:
            m_passes->Add(geom, 0x2d2, true, 0, 0, 0, 0, 0);
            break;
        case 7:
            m_passes->Add(geom, 0x23a, true, 0, 0, 0, 0, 0);
            break;
        case 5:
            m_passes->Add(geom, 0x23b, true, 0, 0, 0, 0, 0);
            break;
        case 3:
            if (DAT_011ff8c4)
                m_passes->Add(geom, 0x23e, true, 0, 0, 0, 0, 0);
            else
                m_passes->Add(geom, 0x23d, true, 0, 0, 0, 0, 0);
            break;
        default:
            if (IsType24())
                m_passes->Add(geom, 0x239, true, 0, 0, 0, 0, 0);
            else
                m_passes->Add(geom, 0x23c, true, 0, 0, 0, 0, 0);
            break;
        }

        if (!DAT_011F941E && HasExtraPass())
        {
            switch (m_type)
            {
            case 0:
                m_passes->Add(geom, 0x2d3, true, 0, 0, 0, 0, 0);
                return m_passes;
            case 3:
                m_passes->Add(geom, 0x2d4, true, 0, 0, 0, 0, 0);
                return m_passes;
            case 4:
                m_passes->Add(geom, 0x2d5, true, 0, 0, 0, 0, 0);
                return m_passes;
            }
        }
        return m_passes;
    }
    return passes;
}

struct RefObj
{
    virtual void Destroy();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct RefPtr
{
    RefObj* m_pObject;
    ~RefPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    RefPtr& operator=(RefObj* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
        }
        return *this;
    }
};

struct SimpleBuf
{
    void* m_pData;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    ~SimpleBuf()
    {
        if (m_pData)
            g_memoryManager.Deallocate(m_pData);
        m_pData = 0;
        m_usElementCount = 0;
        m_usSize = 0;
    }
};

struct ISEffectBaseStub
{
    virtual ~ISEffectBaseStub();
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
};

struct FUN_00baec90 : ISEffectBaseStub
{
    RefPtr m_spTex70;
    SimpleBuf m_kBuf74;
    int unk7c;
    RefPtr m_spTex80;
    float m_fVal84;
    unsigned short m_usVal88;
    int m_iVal8c;

    virtual ~FUN_00baec90();
};

// @fnv 0x00baec90
FUN_00baec90::~FUN_00baec90()
{
    m_spTex80 = 0;
    m_fVal84 = 0.0f;
    m_iVal8c = 8;
    m_usVal88 = 0;
    m_spTex70 = 0;
}

struct FUN_00b6abb0 : NiMemObjectAllocation_blk_00ba0000_o2
{
    FUN_00b6abb0();
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

struct FUN_00bc37b0 : NiMemObjectAllocation_blk_00ba0000_o2
{
    FUN_00bc37b0();
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
};
struct FUN_00baeb80 : NiMemObjectAllocation_blk_00ba0000_o2
{
    FUN_00baeb80();
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
};
struct FUN_00b60cb0 : NiMemObjectAllocation_blk_00ba0000_o2
{
    FUN_00b60cb0();
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
};

struct FUN_00c05880 : NiMemObjectAllocation_blk_00ba0000_o2
{
    FUN_00c05880();
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
};
inline void* operator new(unsigned int, int bytes)
{
    return NiMemObjectAllocation_blk_00ba0000_o2::operator new(bytes);
}
inline void operator delete(void* p, int bytes)
{
    NiMemObjectAllocation_blk_00ba0000_o2::operator delete(p, bytes);
}
struct FactorySelector
{
    unsigned int kind;
    void* BSShaderData_GetShaderProperty();
};
// @fnv 0x00baf120
// src: COMMUNITY 0x00baf120
void* FactorySelector::BSShaderData_GetShaderProperty()
{
    void* result = 0;
    switch (kind)
    {
    case 0:
        result = new (0x104) NewObj;
        break;
    case 1:
        result = new (0x104) NewObj;
        break;
    case 2:
        result = new (0x104) NewObj;
        break;
    case 3:
        result = new FUN_00b6abb0;
        break;
    case 4:
        result = new BSShaderNoLightingProperty;
        break;
    case 5:
        result = new FUN_00bc37b0;
        break;
    case 6:
        result = new FUN_00baeb80;
        break;
    case 7:
        result = new FUN_00b60cb0;
        break;
    case 8:
        result = new TileShaderProperty(false);
        break;
    case 9:
        result = new FUN_00c05880;
        break;
    }
    return result;
}

struct FlagState
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    float field30;
    unsigned int field34;
    unsigned int field38;
};
struct RenderInput
{
    virtual int method0();
    virtual int method1();
    virtual int method2();
    virtual int method3();
    virtual int method4();
    virtual int method5();
    virtual int method6();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    unsigned int fieldb0;
    unsigned int fieldb4;
    unsigned int fieldb8;
    unsigned int fieldbc;
};
struct FUN_00baf640_Class
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned char field4c;
    unsigned char field4d;
    unsigned char field4e;
    unsigned char field4f;
    unsigned char field50;
    unsigned char field51;
    unsigned char field52;
    unsigned char field53;
    unsigned char field54;
    unsigned char field55;
    unsigned char field56;
    unsigned char field57;
    unsigned int field58;
    unsigned char field5c;
    unsigned char field5d;
    unsigned char field5e;
    unsigned char field5f;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned char field6c;
    unsigned char field6d;
    unsigned char field6e;
    unsigned char field6f;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned char field88;
    unsigned char field89;
    unsigned char field8a;
    unsigned char field8b;
    float field8c;
    unsigned int field90;
    unsigned char field94;
    unsigned char field95;
    unsigned char field96;
    unsigned char field97;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned char fieldac;
    unsigned char fieldad;
    unsigned char fieldae;
    unsigned char fieldaf;
    void __thiscall UpdateRenderFlags(FlagState* a, RenderInput* b);
};

// Sets or clears bits in the flag words from the object's byte fields and copies field8c into the float field.
// @fnv 0x00baf640
void FUN_00baf640_Class::UpdateRenderFlags(FlagState* a, RenderInput* b)
{
    int uiZero = 0;

    if (b->method6() != 0 && b->fieldbc != 0)
    {
        unsigned int* flags = &a->field20;
        unsigned int* val38 = &a->field38;
        float* pfValue = &a->field30;
        unsigned int* flags2 = &a->field24;

        if ((*flags & 2) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 2;
    }
    else
    {
        unsigned int* flags = &a->field20;
        unsigned int* val38 = &a->field38;
        float* pfValue = &a->field30;
        unsigned int* flags2 = &a->field24;

        if (*flags & 2)
            *val38 = (unsigned int)uiZero;
        *flags &= ~2u;
    }

    unsigned int* flags = &a->field20;
    unsigned int* val38 = &a->field38;
    float* pfValue = &a->field30;
    unsigned int* flags2 = &a->field24;

    if (field4d)
    {
        if ((*flags & 0x8) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x8;
    }
    else
    {
        if (*flags & 0x8)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffffff7u;
    }

    if (field88)
    {
        if ((*flags & 0x80) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x80;
    }
    else
    {
        if (*flags & 0x80)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xffffff7fu;
    }

    if (field30 != 0)
    {
        if ((*flags & 0x80000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x80000;
    }
    else
    {
        if (*flags & 0x80000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfff7ffffu;
    }

    if (fieldac)
    {
        if ((*flags & 0x100) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x100;
    }
    else
    {
        if (*flags & 0x100)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffffeffu;
    }

    if (field00 == 1)
    {
        if ((*flags & 0x400) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x400;
    }
    else
    {
        if (*flags & 0x400)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffffbffu;
    }

    if (field6c)
    {
        if ((*flags & 0x800) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x800;
    }
    else
    {
        if (*flags & 0x800)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffff7ffu;
    }

    if (field6d)
    {
        if ((*flags & 0x10000000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x10000000;
    }
    else
    {
        if (*flags & 0x10000000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xefffffffu;
    }

    if (field4e)
    {
        if ((*flags & 0x1000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x1000;
    }
    else
    {
        if (*flags & 0x1000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xffffefffu;
    }

    if (field57)
    {
        if ((*flags & 0x8000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x8000;
    }
    else
    {
        if (*flags & 0x8000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xffff7fffu;
    }

    if (field5c)
    {
        if ((*flags & 0x10000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x10000;
    }
    else
    {
        if (*flags & 0x10000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffeffffu;
    }

    if (field00 == 2)
    {
        if ((*flags & 0x40000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x40000;
    }
    else
    {
        if (*flags & 0x40000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffbffffu;
    }

    if (field4f)
    {
        if ((*flags & 0x2000000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x2000000;
    }
    else
    {
        if (*flags & 0x2000000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfdffffffu;
    }

    if (field50)
    {
        if ((*flags & 0x4000000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x4000000;
    }
    else
    {
        if (*flags & 0x4000000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfbffffffu;
    }

    if (field50)
    {
        if ((*flags & 0x8000000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x8000000;
    }
    else
    {
        if (*flags & 0x8000000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xf7ffffffu;
    }

    if (field56)
    {
        if ((*flags & 0x80000000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x80000000;
    }
    else
    {
        if (*flags & 0x80000000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0x7fffffffu;
    }

    if (field55)
    {
        if ((*flags2 & 0x1) == 0)
            *val38 = (unsigned int)uiZero;
        *flags2 |= 0x1;
    }
    else
    {
        if (*flags2 & 0x1)
            *val38 = (unsigned int)uiZero;
        *flags2 &= 0xfffffffeu;
    }

    if (field52)
    {
        if ((*flags & 0x100000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x100000;
    }
    else
    {
        if (*flags & 0x100000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xffefffffu;
    }

    if (field53)
    {
        if ((*flags2 & 0x8) == 0)
            *val38 = (unsigned int)uiZero;
        *flags2 |= 0x8;
    }
    else
    {
        if (*flags2 & 0x8)
            *val38 = (unsigned int)uiZero;
        *flags2 &= 0xfffffff7u;
    }

    if (field54)
    {
        if ((*flags2 & 0x8000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags2 |= 0x8000;
    }
    else
    {
        if (*flags2 & 0x8000)
            *val38 = (unsigned int)uiZero;
        *flags2 &= 0xffff7fffu;
    }

    if (field94)
    {
        if ((*flags & 0x40) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x40;
    }
    else
    {
        if (*flags & 0x40)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xffffffbfu;
    }

    if (fieldad)
    {
        if ((*flags & 0x1) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x1;
    }
    else
    {
        if (*flags & 0x1)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffffffeu;
    }

    if (field89)
    {
        if ((*flags & 0x20000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x20000;
    }
    else
    {
        if (*flags & 0x20000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xfffdffffu;
    }

    if (field8a)
    {
        if ((*flags & 0x200000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x200000;
    }
    else
    {
        if (*flags & 0x200000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xffdfffffu;
    }

    if (field51)
    {
        if ((*flags & 0x20000000) == 0)
            *val38 = (unsigned int)uiZero;
        *flags |= 0x20000000;
    }
    else
    {
        if (*flags & 0x20000000)
            *val38 = (unsigned int)uiZero;
        *flags &= 0xdfffffffu;
    }

    *pfValue = field8c;
}

extern const float DAT_01012054;
struct Getter08
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual const char* get(int);
};
struct Target08
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void set(int);
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
    BSStringT<char> name;
    int unk6c;
    float f70, f74, f78, f7c;
    void SetName(const char* s)
    {
        name.Set(s, 0);
    }
};
struct Source08
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
    float f98, f9c, fa0, fa4;
    Getter08* getter;
    int unkac, unkb0;
    int value;
    void CopyToTarget(Target08*);
};
// Copies the getter's first string into target->name, calls target->set(value), and copies f98..fa4 into target->f70..f7c when those are not -1.0f.
// @fnv 0x00bafaf0
void Source08::CopyToTarget(Target08* target)
{
    if (getter)
    {
        {

            NiFixedString fixedName(getter->get(0));

            BSStringT<char>* output = &target->name;

            output->Set(fixedName.m_kHandle, 0);
        }
        target->set(value);
    }
    if (target->f70 != -1.0f)
        target->f70 = f98;
    if (target->f74 != -1.0f)
        target->f74 = f9c;
    if (target->f78 != -1.0f)
        target->f78 = fa0;
    if (target->f7c != -1.0f)
        target->f7c = fa4;
}

struct LeafVertexShader : NiRefObject
{
};
struct LeafPixelShader : NiRefObject
{
};
struct LeafPass : NiRefObject
{
};

struct SpeedTreeShaderBase
{
    virtual ~SpeedTreeShaderBase();
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
};

struct FUN_00bb1c10 : SpeedTreeShaderBase
{
    NiPointer<LeafVertexShader> m_spVertexShaders[4];
    NiPointer<LeafPixelShader> m_spPixelShaders[2];
    NiPointer<LeafPass> m_spPasses[2];
    virtual ~FUN_00bb1c10();
};

// Destructor that releases the four vertex shader and two pixel shader smart pointers by setting them to null.
// @fnv 0x00bb1c10
FUN_00bb1c10::~FUN_00bb1c10()
{
    for (int i = 0; i < 4; i++)
        m_spVertexShaders[i] = 0;
    for (int i = 0; i < 2; i++)
        m_spPixelShaders[i] = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Resource
{
    virtual void unused();
    virtual void destroy();
    volatile long refs;
};
struct StageReturn
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
    int refs;
    void ReturnToPool();
    void DecRef()
    {
        --refs;
        if (refs == 0)
            ReturnToPool();
    }
};
struct StagePtr
{
    StageReturn* ptr;
    StagePtr() : ptr(0)
    {}
    ~StagePtr()
    {
        if (ptr)
            ptr->DecRef();
    }
};
void __cdecl AssignStageFromPool(StageReturn*&);
void __cdecl CreatePass(void*);
void __cdecl SetupStage(StageReturn*, int, int, int, int);
void* __cdecl GetState();
void __cdecl ReleaseState(void*);
struct Pass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* stageList;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    void* state;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    Resource* resource44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    Resource* resource5C;
    void BindStage(void*, StageReturn*);
    void attach(StageReturn* stage)
    {
        BindStage(stageList, stage);
    }
    void set5C(Resource* value)
    {
        Resource* old = resource5C;
        if (old != value)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->destroy();
            resource5C = value;
            if (value)
                InterlockedIncrement(&value->refs);
        }
    }
    void set44(Resource* value)
    {
        Resource* old = resource44;
        if (old != value)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->destroy();
            resource44 = value;
            if (value)
                InterlockedIncrement(&value->refs);
        }
    }
};
struct ShaderSetup
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    Resource* resource370;
    int unk374;
    Resource* resource378;
    int unk37C;
    Resource* resource380;
    Pass* pass384;
    Pass* pass388;
    void CreatePasses();
};
// Creates two passes, each with a new stage configured by SetupStage, attaches the stage, assigns the current state, and sets resources.
// @fnv 0x00bb1d40
void ShaderSetup::CreatePasses()
{
    CreatePass(&pass384);
    StagePtr stage;
    AssignStageFromPool(stage.ptr);
    SetupStage(stage.ptr, 0, 1, 2, 1);
    pass384->attach(stage.ptr);
    {
        Pass* pass = pass384;
        void* state = GetState();
        if (pass->state != state)
            ReleaseState(pass->state);
        pass->state = state;
    }
    pass384->set5C(resource370);
    pass384->set44(resource380);
    CreatePass(&pass388);
    AssignStageFromPool(stage.ptr);
    SetupStage(stage.ptr, 0, 1, 2, 1);
    pass388->attach(stage.ptr);
    {
        Pass* pass = pass388;
        void* state = GetState();
        if (pass->state != state)
            ReleaseState(pass->state);
        pass->state = state;
    }
    pass388->set5C(resource378);
    pass388->set44(resource380);
}

// Prelude helper whose body the unit prelude omits.
// Create a new pass object for this shader's current state with default pass count and priority.
class B30B0Pass
{
  public:
    B30B0Pass(void* pvState);
    virtual ~B30B0Pass();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iValueAt14;
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
    int m_iPassCount;
};
class B30B0DefaultPass : public B30B0Pass
{
  public:
    B30B0DefaultPass(void* pvState) : B30B0Pass(pvState)
    {
        m_iPassCount = 4;
        m_iValueAt14 = 0xa;
    }
    virtual ~B30B0DefaultPass();

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
};
class B30B0Shader
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void* GetState();

    B30B0Pass* CreateDefaultPass();
};
// Allocates a B30B0DefaultPass with the shader's state and returns it as a B30B0Pass pointer.
// @fnv 0x00bb30b0
B30B0Pass* B30B0Shader::CreateDefaultPass()
{
    return new B30B0DefaultPass(GetState());
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plAddend);
class CBB3B10MemoryManager
{
  public:
    void Deallocate(void* pvMem);
};
extern CBB3B10MemoryManager g_kBB3B10MemoryManager;
inline void CBB3B10Free(void* pvMem)
{
    if (pvMem)
        g_kBB3B10MemoryManager.Deallocate(pvMem);
}

class CBB3B10Object : public NiRefObject
{
  public:
    static void operator delete(void* memory, unsigned int size);
    virtual __forceinline ~CBB3B10Object()
    {
        CBB3B10Free(m_pResource);
    }

    CBB3B10Object* DestroyObject(unsigned int uiFlags);

    void* m_pResource;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
// Runs the CBB3B10Object destructor and, when bit 0 of uiFlags is set, frees the object's memory, then returns this.
// @fnv 0x00bb3b10
CBB3B10Object* CBB3B10Object::DestroyObject(unsigned int uiFlags)
{
    this->CBB3B10Object::~CBB3B10Object();
    if (uiFlags & 1)
        CBB3B10Object::operator delete(this, sizeof(CBB3B10Object));
    return this;
}

class FUN_00bb3d80_cls
{
  public:
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
    virtual void v55(void* p);
    void __thiscall BSShaderLightingProperty_CopyMembers(void* a, unsigned int b);
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
    void* m_07c;
    int unk80;
    int unk84;
    NiRefObject* m_088;
    unsigned short m_08c;
    void __thiscall SpeedTreeLeafShaderProperty_CopyMembers(FUN_00bb3d80_cls* arg1, unsigned int arg2);
};
// @fnv 0x00bb3d80
// src: XBOX_PDB 0x00bb3d80
void FUN_00bb3d80_cls::SpeedTreeLeafShaderProperty_CopyMembers(FUN_00bb3d80_cls* arg1, unsigned int arg2)
{
    this->BSShaderLightingProperty_CopyMembers(arg1, arg2);
    arg1->v55(m_07c);
    NiRefObject* old = arg1->m_088;
    if (old != m_088)
    {
        if (old != 0 && InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
        {
            old->DeleteThis();
        }
        NiRefObject* n = m_088;
        arg1->m_088 = n;
        if (n != 0)
        {
            InterlockedIncrement((volatile long*)&n->m_uiRefCount);
        }
    }
    arg1->m_08c = m_08c;
}

namespace nsbb {
struct FUN_00bb3ba0 : BSFaceGenMorphData
{
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA();
    virtual void vACur();
    virtual void vAValue();
    virtual void vAC();
    virtual void vB();
    virtual void vBCur();
    virtual void vBValue();
    virtual void vBC();
    virtual void vC();
    virtual void vCCur();
    virtual void vCValue();
    virtual void* vCC();
    virtual void vD();
    virtual void vDCur();
    virtual void vDValue();
    virtual void vDC();
    virtual void vE();
    virtual void vECur();
    virtual void vEValue();
    virtual void vEC();
    virtual void vF();
    virtual void vFCur();
    virtual unsigned short vFValue();
    virtual void* vFC();
    int unkCur;
    int unk0C;
    int unkValue;
    int uNewnk;
    int uTmpnk;
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

    FUN_00bb3ba0(unsigned short a1, void* a2, void* a3);
    void SpeedTreeLeafShaderProperty_CopyMembers(FUN_00bb3ba0* clone, void* process);
    FUN_00bb3ba0* CloneMorphData(void* process);
};
}

// Allocates a copy of this morph data object, copies it via FUN_00bb3d80, and returns the clone.
// @fnv 0x00bb3f10
nsbb::FUN_00bb3ba0* nsbb::FUN_00bb3ba0::CloneMorphData(void* process)
{
    FUN_00bb3ba0* clone = new FUN_00bb3ba0(vFValue(), vCC(), vFC());
    SpeedTreeLeafShaderProperty_CopyMembers(clone, process);
    return clone;
}

struct BB5DD0Heap
{
    void* Game_DoHeapAlloc(unsigned int uiSize);
};

struct BB5DD0Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BB5DD0Obj(NiGeometry* pRef, int iType, ...);
    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<BB5DD0Heap&>(g_memoryManager).Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager.Deallocate(pvMem);
    }
};

struct BB5DD0Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiValue1;
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    BB5DD0Obj* m_pEntryObject;

    BB5DD0Obj* CreateObject(NiGeometry* pRef);
};

// @fnv 0x00bb5dd0
BB5DD0Obj* BB5DD0Owner::CreateObject(NiGeometry* pRef)
{
    if ((m_uiValue1 & 0x4000000) > 0 || (m_uiValue1 & 0x8000000) > 0)
        return 0;
    bool bHas = false;
    void* pData = pRef->m_spModelData.m_pObject->m_pkColor;
    if (pData)
        bHas = true;
    if (m_pEntryObject == 0)
    {
        if ((m_uiValue1 & 2) > 0)
        {
            if (bHas)
                m_pEntryObject = new BB5DD0Obj(pRef, 0x1da, true, 0, 0);
            else
                m_pEntryObject = new BB5DD0Obj(pRef, 0x1d9, true, 0, 0);
        }
        else
        {
            if (bHas)
                m_pEntryObject = new BB5DD0Obj(pRef, 0x1d8, true, 0, 0);
            else
                m_pEntryObject = new BB5DD0Obj(pRef, 0x1d7, true, 0, 0);
        }
    }
    return m_pEntryObject;
}

extern float DAT_011ae600;
extern float DAT_011ae604;
extern float DAT_011ae608;
extern float DAT_0120081c;
extern float DAT_01200820;
extern float DAT_01200824;
extern float DAT_01200828;
extern float DAT_0120082c;
extern float DAT_01200830;
extern float DAT_01200834;

struct Effect_bb9020
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ParameterSet* parameters;
    int unk20;
    int unk24;
    int unk28;
    TextureSource** textures;
    bool ImageSpaceEffectTV_UpdateParams(int unused);
};

// Computes inverse texture dimensions from textures[1] and writes five parameter vectors into parameters->p0, then returns false.
// @fnv 0x00bb9020
// src: COMMUNITY 0x00bb9020
bool Effect_bb9020::ImageSpaceEffectTV_UpdateParams(int unused)
{
    float invWidth = 0.0f;
    float invHeight = 0.0f;
    if (textures[1])
    {
        ScreenTexture* tex = textures[1]->ImageSpaceTexture_GetTexture();
        invWidth = 1.0f / (float)tex->Width();
        invHeight = 1.0f / (float)tex->Height();
    }
    ShaderParameter* param = parameters->p0;
    param->FUN_00b8a790(0, invWidth, invHeight, 0.0f, 0.0f);
    param->FUN_00b8a790(1, DAT_011ae600, 0.0f, 0.0f, 0.0f);
    param->FUN_00b8a790(2, DAT_0120081c, DAT_01200820, DAT_011ae604, 0.0f);
    param->FUN_00b8a790(3, DAT_01200824, DAT_01200828, DAT_011ae608, 0.0f);
    param->FUN_00b8a790(4, DAT_0120082c, DAT_01200830, DAT_01200834, 1.0f);
    return false;
}

struct FUN_00ba3d30
{
    virtual void unused();
    int unk04, unk08, unk0c, unk10, unk14;
    EffectArray effects;
    ~FUN_00ba3d30();
};
struct FUN_00ba3a00
{
    int unk00, unk04, unk08, unk0c;
    ~FUN_00ba3a00();
};
struct FUN_00ba12d0 : FUN_00ba3d30
{
    virtual void unused();
    int unk28[12];
    FUN_00ba3a00 m_58;
    FUN_00ba3a00 m_68;
    FUN_00ba3a00 m_78;
    FUN_00ba3a00 m_88;
    FUN_00ba3a00 m_98;
    ~FUN_00ba12d0();
};
// Deletes each non-null entry in effects.data for indices 0-11 and clears the slot via FUN_00ba3aa0.
// @fnv 0x00ba12d0
FUN_00ba12d0::~FUN_00ba12d0()
{
    for (unsigned int i = 0; i < 12; ++i)
    {
        if (effects.data[i])
        {
            delete effects.data[i];
            effects.FUN_00ba3aa0(i, 0);
        }
    }
}

class TgtC00
{
  public:
    int pad[0x8c / 4];
    int m_8c;
    int padCur;
    BSString m_kName;
};
class OwnC00
{
  public:
    void CopySourceNameToTarget(TgtC00* pkTarget);
    int pad[0xa8 / 4];
    SourceBAF* m_pkSource;
    int padac, padb;
    int m_b4;
};
// If m_pkSource is set, copies its name into pkTarget->m_kName and stores m_b4 into pkTarget->m_8c.
// @fnv 0x00bafc00
void OwnC00::CopySourceNameToTarget(TgtC00* pkTarget)
{
    if (m_pkSource)
    {
        {
            NiFixedString kName(m_pkSource->GetName(0));
            pkTarget->m_kName.Set(kName.m_kHandle, 0);
        }
        pkTarget->m_8c = m_b4;
    }
}

struct WorkerObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int type;
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
    int shader;
    int unk5c;
    float x, y, z, w;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int extra;
    int IsRange()
    {
        return type >= 8 && type <= 12;
    }
    WorkerObject* Range()
    {
        return IsRange() ? this : 0;
    }
    int Is21()
    {
        if (type == 21)
            return 1;
        return 0;
    }
    WorkerObject* As21()
    {
        return Is21() ? this : 0;
    }
    int Is22()
    {
        if (type == 22)
            return 1;
        return 0;
    }
    WorkerObject* As22()
    {
        return Is22() ? this : 0;
    }
    int Is4()
    {
        if (type == 4)
            return 1;
        return 0;
    }
    WorkerObject* As4()
    {
        return Is4() ? this : 0;
    }
    int Is13()
    {
        if (type == 13)
            return 1;
        return 0;
    }
    WorkerObject* As13()
    {
        return Is13() ? this : 0;
    }
    int Is19()
    {
        if (type == 19)
            return 1;
        return 0;
    }
    WorkerObject* As19()
    {
        return Is19() ? this : 0;
    }
    int Is7()
    {
        if (type == 7)
            return 1;
        return 0;
    }
    WorkerObject* As7()
    {
        return Is7() ? this : 0;
    }
};

struct WorkerTarget
{
    void NiAVObject_AttachProperty(WorkerObject*);
};
extern int DAT_011ae5a8[];

struct WorkerSource
{
    int type;
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
    float x, y, z, w;
    int unk88;
    int unk8c;
    int extra;
    WorkerObject* BSShaderData_GetShaderProperty();
    void BSShaderData_CheckTextureAlphas();
    void UpdateRenderFlags(WorkerObject*, WorkerTarget*);
    void BSShaderData_SetupTexturesLightingShader(WorkerObject*);
    void CopyTo(WorkerObject*);
    void CopyToTarget(WorkerObject*);
    void SetTargetName(WorkerObject*);
    void BSShaderData_SetupTexturesSkyShader(WorkerObject*);
    void CopySourceNameToTarget(WorkerObject*);
    void UpdateWorkerObject(WorkerTarget*);
};

// Gets a worker object, runs per-type setup on it (range, 21/22/4/13/19/7 variants), sets its shader from DAT_011ae5a8[type], and passes it to target.
// @fnv 0x00bb0040
void WorkerSource::UpdateWorkerObject(WorkerTarget* target)
{
    WorkerObject* object = BSShaderData_GetShaderProperty();
    if (object)
    {
        BSShaderData_CheckTextureAlphas();
        UpdateRenderFlags(object, target);
        WorkerObject* range = object->Range();
        if (range)
        {
            BSShaderData_SetupTexturesLightingShader(range);
            CopyTo(range);
        }
        WorkerObject* pAs21 = object->As21();
        if (pAs21)
            CopyToTarget(pAs21);
        WorkerObject* values = object->As22();
        if (values)
        {
            values->x = x;
            values->y = y;
            values->z = z;
            values->w = w;
        }
        WorkerObject* pAs4 = object->As4();
        if (pAs4)
            SetTargetName(pAs4);
        WorkerObject* pAs13 = object->As13();
        if (pAs13)
        {
            BSShaderData_SetupTexturesSkyShader(pAs13);
            pAs13->extra = extra;
        }
        WorkerObject* pAs19 = object->As19();
        if (pAs19)
            CopySourceNameToTarget(pAs19);
        WorkerObject* pAs7 = object->As7();
        if (pAs7)
        {
            BSShaderData_SetupTexturesLightingShader(pAs7);
            CopyTo(pAs7);
        }
        object->shader = DAT_011ae5a8[type];
        target->NiAVObject_AttachProperty(object);
    }
}

struct BB3FC0ImageProvider
{
    typedef unsigned int(__thiscall* CountGetter)(BB3FC0ImageProvider*);
    typedef void*(__thiscall* DataGetter)(BB3FC0ImageProvider*, DataSize, unsigned int);
    unsigned int getLayerCount()
    {
        return reinterpret_cast<CountGetter>((*reinterpret_cast<void***>(this))[0xd4 / 4])(this);
    }
    void* getLayerData(unsigned int length, unsigned int first)
    {
        void** functions = *reinterpret_cast<void***>(this);
        DataSize size = {length};
        return reinterpret_cast<DataGetter>(functions[0xd0 / 4])(this, size, first);
    }
    ImageBuffer* SpeedTreeLeafShaderProperty_CreateRendererSpecificProperty(int unused);
};

// Allocates an ImageBuffer sized to the layer count, configures it, fills it with the layer data, and returns it.
// @fnv 0x00bb3fc0
// src: XBOX_PDB 0x00bb3fc0
ImageBuffer* BB3FC0ImageProvider::SpeedTreeLeafShaderProperty_CreateRendererSpecificProperty(int unused)
{
    unsigned int count = getLayerCount();
    ImageBuffer* buffer = new ImageBuffer(count, true);
    buffer->SetSize_Thunk(true);
    buffer->NiAdditionalGeometryData_SetDataBlock(false, getLayerData(count << 4, 0));
    buffer->NiAdditionalGeometryData_SetDataStream(0, 0, 0, 4, count, 0x10, 0x10);
    return buffer;
}

struct Obj
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v0a();
    virtual int v0b();
    virtual int v0c();
    virtual int v0d();
    virtual int v0e();
    virtual int v0f();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v1a();
    virtual int v1b();
    virtual int v1c();
    virtual int v1d();
    virtual int v1e();
    virtual int v1f();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual unsigned int v25();
    virtual unsigned int v26();
};

struct TextureHolder
{
    void __thiscall ImageSpaceTexture_SetTexture_00ba37f0(void*);
};
struct TextureSource131
{
    void* __thiscall ImageSpaceTexture_GetTexture();
};
struct ShaderParameter131
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int mask;
    void __thiscall FUN_00b8a790(int, float, float, float, float);
};
struct UnknownD47A40
{
    void __thiscall FUN_00d47a40(int);
};
struct ShaderHolder
{
    ShaderParameter131* p0;
    ShaderParameter131* p4;
};

struct EffectCtx
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    ShaderHolder* m_pShaderHolder;
    int unk20, unk24, unk28;
    void** m_ppTextures;
    short unk30;
    unsigned short m_uiItemCount;
    bool __thiscall ImageSpaceEffectInterface_UpdateParams(int a1);
};

extern float DAT_012007e8;
extern float DAT_012007f0;
extern float DAT_012007f4;
extern char DAT_012007f8;
extern int DAT_012007fc;
extern int DAT_012007ec;
extern float DAT_011ae5e8;
extern float DAT_011ae5ec;
extern float DAT_011ae5f0;
extern float DAT_011ae5f4;
extern float DAT_011ae5f8;
extern float DAT_011ae5fc;
extern float DAT_01099378;

// @fnv 0x00bb85e0
// src: COMMUNITY 0x00bb85e0
bool EffectCtx::ImageSpaceEffectInterface_UpdateParams(int aiUnused)
{
    ((TextureHolder*)m_ppTextures[3])->ImageSpaceTexture_SetTexture_00ba37f0((void*)DAT_01200810);
    ((TextureHolder*)m_ppTextures[4])->ImageSpaceTexture_SetTexture_00ba37f0((void*)DAT_01200814);

    if (DAT_01200818)
    {
        ((TextureHolder*)m_ppTextures[2])->ImageSpaceTexture_SetTexture_00ba37f0((void*)DAT_01200818);
    }
    else
    {
        void** textures = m_ppTextures;
        void* texture = ((TextureSource131*)textures[1])->ImageSpaceTexture_GetTexture();
        ((TextureHolder*)textures[2])->ImageSpaceTexture_SetTexture_00ba37f0(texture);
    }

    float fa = 0.0f;
    float fb = 0.0f;
    if (m_ppTextures[2] != 0)
    {
        Obj* o = (Obj*)((TextureSource131*)m_ppTextures[2])->ImageSpaceTexture_GetTexture();
        fa = DAT_011ae5e8 * (1.0f / o->v25());
        fb = DAT_011ae5e8 * (1.0f / o->v26());
    }

    ShaderParameter131* edi;
    if (DAT_012007fc == 0)
    {
        edi = m_pShaderHolder->p0;
        edi->FUN_00b8a790(0, DAT_011ae5ec, DAT_012007e8, DAT_011ae5f4, DAT_011ae5f0);
        float t = DAT_012007f8 ? 1.0f : 0.0f;
        edi->FUN_00b8a790(1, DAT_012007f0, DAT_012007f4, DAT_011ae5f8, t);
        edi->FUN_00b8a790(2, *(float*)&DAT_01200800, *(float*)&DAT_01200804, *(float*)&DAT_01200808,
                          *(float*)&DAT_0120080c);
        edi->FUN_00b8a790(3, fa, fb, 0.0f, 0.0f);
    }
    else
    {
        edi = m_pShaderHolder->p4;
        edi->FUN_00b8a790(0, DAT_011ae5ec, DAT_012007e8, DAT_011ae5f4, DAT_011ae5f0);
        float t = DAT_012007f8 ? 1.0f : 0.0f;
        edi->FUN_00b8a790(1, DAT_012007f0, DAT_012007f4, DAT_011ae5f8, t);
        edi->FUN_00b8a790(2, *(float*)&DAT_01200800, *(float*)&DAT_01200804, *(float*)&DAT_01200808,
                          *(float*)&DAT_0120080c);
        edi->FUN_00b8a790(3, fa, fb, 0.0f, 0.0f);
        edi->FUN_00b8a790(4, DAT_011ae5fc, 0.0f, 0.0f, 0.0f);
    }

    edi->mask = DAT_012007ec;

    for (unsigned int i = 0; i < m_uiItemCount; i++)
    {
        ((UnknownD47A40*)m_ppTextures[i])->FUN_00d47a40(1);
    }

    return false;
}


struct FUN_00b6f460_class
{
    void LoadAndSetAdditional(NiStream* stream);
};

struct FUN_00ba8630_Class : FUN_00b6f460_class
{
    void _BSShaderPPLightingProperty_LinkObject(NiStream* stream);
};

// @fnv 0x00ba8650
// src: COMMUNITY 0x00ba8650
void FUN_00ba8630_Class::_BSShaderPPLightingProperty_LinkObject(NiStream* stream)
{
    LoadAndSetAdditional(stream);
}

struct NiObj_s
{
    bool IsEqual(NiObj_s*);
};
struct FUN_00ba87d0_Class
{
    bool BSAnimNotes_IsEqual(NiObj_s* a);
};
// @fnv 0x00ba87d0
// src: XBOX_PDB 0x00ba87d0
bool FUN_00ba87d0_Class::BSAnimNotes_IsEqual(NiObj_s* a)
{
    return ((NiObj_s*)this)->IsEqual(a);
}

void __cdecl NiAlphaProperty_LinkObject();
// @fnv 0x00ba8a70
// src: XBOX_PDB 0x00ba8a70
void __cdecl BSShaderProperty_LinkObject()
{
    NiAlphaProperty_LinkObject();
}

void __cdecl NiAlphaProperty_RegisterStreamables();

// @fnv 0x00ba8a80
// src: XBOX_PDB 0x00ba8a80
void __cdecl BSShaderProperty_RegisterStreamables()
{
    NiAlphaProperty_RegisterStreamables();
}

// @fnv 0x00ba8a90
// src: COMMUNITY 0x00ba8a90
int __stdcall NiDX9TextureManager_GetTexture(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    return 0;
}

// The pack names the two 16-bit count pairs as integer storage words.
// Decode/update those words without accessing a different scalar type.
__declspec(noinline) void EffectArray::FUN_00ba3aa0(unsigned index, EffectParam* const& value)
{
    unsigned size = static_cast<unsigned>(unk08) >> 16;
    if (index >= size)
    {
        unk08 = (static_cast<unsigned>(unk08) & 0xffffu) | ((index + 1) << 16);
        if (value)
            unk0c = (static_cast<unsigned>(unk0c) & 0xffff0000u) | ((static_cast<unsigned>(unk0c) + 1) & 0xffffu);
    }
    else if (value)
    {
        if (!data[index])
            unk0c = (static_cast<unsigned>(unk0c) & 0xffff0000u) | ((static_cast<unsigned>(unk0c) + 1) & 0xffffu);
    }
    else if (data[index])
    {
        unk0c = (static_cast<unsigned>(unk0c) & 0xffff0000u) | ((static_cast<unsigned>(unk0c) - 1) & 0xffffu);
    }
    data[index] = value;
}
struct FUN_00baa180 : BaseEffect
{
    virtual void unused();
    ~FUN_00baa180();
};
// Destructor: if the first entry in effects is non-null, deletes it and clears that slot via FUN_00ba3aa0(0, 0).
// @fnv 0x00baa180
FUN_00baa180::~FUN_00baa180()
{
    if (effects.data[0] != 0)
    {
        delete effects.data[0];
        effects.FUN_00ba3aa0(0, 0);
    }
}

extern "C" void __cdecl BSShaderTextureSet_IsEqual();
// @fnv 0x00bae710
// src: XBOX_PDB 0x00bae710
void __cdecl SkyShaderProperty_IsEqual()
{
    BSShaderTextureSet_IsEqual();
}

char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
char* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
unsigned int __cdecl BSUtilities_GetTextureName(void*);
int __cdecl BSsprintf(char*, unsigned int, const char*, ...);

struct TexName
{
    int t0;
    int t4;
    const char* name;
};

struct FUN_00baeee0_shell
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
    float col60;
    float col64;
    float col68;
    float col6c;
    void* baseTex;
    int unk74;
    int unk78;
    int unk7c;
    TexName* tex;
    float blendValue;
    int unk88;
    int soType;
    void __thiscall AppendToStringArray(StrArr* arr);
};

// Appends formatted entries for SOType, blend texture, blend value, base texture and, when soType is 3, the blend color to the string array.
// @fnv 0x00baeee0
void __thiscall FUN_00baeee0_shell::AppendToStringArray(StrArr* arr)
{
    char buf[256];

    WriteToSettingArray(arr);

    {
        char* val = NiViewerStrings_NiGetViewerString_Title((void*)DAT_012005b8);
        unsigned int idx = arr->m_usSize;
        if (idx >= arr->m_usMaxSize)
            arr->SetSize(arr->m_usGrowBy + idx);
        arr->SetAt(idx, val);
    }

    {
        char* val = NiGetViewerString_00a7d4d0("SOType", soType);
        unsigned int idx = arr->m_usSize;
        if (idx >= arr->m_usMaxSize)
            arr->SetSize(arr->m_usGrowBy + idx);
        arr->SetAt(idx, val);
    }

    {
        const char* name = tex ? tex->name : "";
        if (!name)
            name = "";
        char* val = NiGetViewerString_00a7d5e0("Blend Texture", (unsigned int)name);
        unsigned int idx = arr->m_usSize;
        if (idx >= arr->m_usMaxSize)
            arr->SetSize(arr->m_usGrowBy + idx);
        arr->SetAt(idx, val);
    }

    {
        char* val = NiGetViewerString_00a7d550("Blend Value", blendValue);
        unsigned int idx = arr->m_usSize;
        if (idx >= arr->m_usMaxSize)
            arr->SetSize(arr->m_usGrowBy + idx);
        arr->SetAt(idx, val);
    }

    {
        void* bt = baseTex;
        unsigned int r = BSUtilities_GetTextureName(bt);
        if (r)
        {
            char* val = NiGetViewerString_00a7d5e0("base texture", r);
            unsigned int idx = arr->m_usSize;
            if (idx >= arr->m_usMaxSize)
                arr->SetSize(arr->m_usGrowBy + idx);
            arr->SetAt(idx, val);
        }
        else
        {
            void* bt2 = baseTex;
            char* val = NiGetViewerString_00a7d5a0("base texture", bt2);
            unsigned int idx = arr->m_usSize;
            if (idx >= arr->m_usMaxSize)
                arr->SetSize(arr->m_usGrowBy + idx);
            arr->SetAt(idx, val);
        }
    }

    if (soType == 3)
    {
        BSsprintf(buf, 256, "%d %d %d %d", (int)(col60 * 255.0), (int)(col64 * 255.0), (int)(col68 * 255.0),
                     (int)(col6c * 255.0));
        char* val = NiGetViewerString_00a7d5e0("Blend Color", (unsigned int)buf);
        unsigned int idx = arr->m_usSize;
        if (idx >= arr->m_usMaxSize)
            arr->SetSize(arr->m_usGrowBy + idx);
        arr->SetAt(idx, val);
    }
}

namespace fnv_00bb1160 {
extern void* DAT_012005fc;
extern char DAT_010b90ec;
extern char DAT_010ae79c;
extern char DAT_010ae344;
extern char DAT_010b90dc;
char* NiGetViewerString_00a7d4d0(const char*, int);
char* NiGetViewerString_00a7d5a0(const char*, void*);
const char* BSUtilities_GetTextureName(void*);
char* NiGetViewerString(const char*, bool);
char* NiBillboardNode_GetViewerString(const char*, unsigned int);
struct FUN_00bb1160_Class
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual int IsEnabled();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    void* field90;
    unsigned int field94;
    unsigned int field98;
    void __thiscall PrecipitationShaderProperty_GetViewerStrings(StrArr* array);
};
// Appends formatted entries for DAT_012005fc, field60, field90 (via FUN_00c4bb40 or FUN_00a7d5a0), a disabled flag, and field98 to the array.
// @fnv 0x00bb1160
// src: XBOX_PDB 0x00bb1160
void __thiscall FUN_00bb1160_Class::PrecipitationShaderProperty_GetViewerStrings(StrArr* array)
{
    WriteToSettingArray(array);
    ((FNVArray*)array)->Append(NiViewerStrings_NiGetViewerString_Title(DAT_012005fc));
    ((FNVArray*)array)->Append(NiGetViewerString_00a7d4d0(&DAT_010b90ec, field60));
    if (field90)
    {
        void* name = (void*)BSUtilities_GetTextureName(field90);
        char* value;
        if (name)
        {
            value = NiGetViewerString_00a7d5e0(&DAT_010ae79c, (unsigned int)name);
            ((FNVArray*)array)->Append(value);
        }
        else
        {
            name = field90;
            value = NiGetViewerString_00a7d5a0(&DAT_010ae79c, name);
            ((FNVArray*)array)->Append(value);
        }
    }
    if (!IsEnabled())
    {
        ((FNVArray*)array)->Append(NiGetViewerString(&DAT_010ae344, 1));
    }
    ((FNVArray*)array)->Append(NiBillboardNode_GetViewerString(&DAT_010b90dc, field98));
}
}  // namespace fnv_00bb1160

union FogSlots_00bb1b50
{
    float f[8];
    unsigned int u[8];
};
// Reads the current FogInfo and stores its far/near distance, color and density into the two global FogVector4 values.
// @fnv 0x00bb1b50
// src: XBOX_PDB 0x00bb1b50
void __stdcall SpeedTreeLeafShader_SetupPassConstants(int unused)
{
    FogInfo* src = BSShaderManager_GetFogProperty(DAT_011f91c4);
    if (src != 0)
    {
        FogSlots_00bb1b50 t;
        t.f[0] = src->farDistance;
        t.u[1] = *(unsigned int*)&src->color.r;
        t.u[2] = *(unsigned int*)&src->color.g;
        t.u[3] = *(unsigned int*)&src->color.b;
        t.f[4] = t.f[0];
        t.f[5] = t.f[4] - src->nearDistance;
        t.f[6] = src->density;
        t.f[7] = 0.0f;
        DAT_011fa280 = *(FogVector4*)&t.f[4];
        t.f[4] = t.f[1];
        t.f[5] = t.f[2];
        t.f[6] = t.f[3];
        t.f[7] = 0.0f;
        DAT_011fa290 = *(FogVector4*)&t.f[4];
    }
}

void __cdecl SpeedTreeShaderPPLightingProperty_GetViewerStrings();
// @fnv 0x00bb30a0
// src: XBOX_PDB 0x00bb30a0
void __cdecl SpeedTreeBranchShaderProperty_GetViewerStrings()
{
    SpeedTreeShaderPPLightingProperty_GetViewerStrings();
}

struct StrArray;
struct ShaderBase_00b690d0
{
    void GetDebugInfo_b690d0(StrArray*);
};
struct FUN_00bb3380_Class : ShaderBase_00b690d0
{
    void SpeedTreeShaderPPLightingProperty_GetViewerStrings(StrArray* a);
};
// @fnv 0x00bb3380
// src: COMMUNITY 0x00bb3380
void FUN_00bb3380_Class::SpeedTreeShaderPPLightingProperty_GetViewerStrings(StrArray* a)
{
    GetDebugInfo_b690d0(a);
}

void __cdecl BSShaderLightingProperty_GetViewerStrings();
// @fnv 0x00bb3390
// src: XBOX_PDB 0x00bb3390
void __cdecl SpeedTreeShaderLightingProperty_GetViewerStrings()
{
    BSShaderLightingProperty_GetViewerStrings();
}

struct FnvCpu_FUN_00bb3730_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    int value;
    int SkyShaderProperty_GetClampMode();
};
// @fnv 0x00bb3730
// src: COMMUNITY 0x00bb3730
int FnvCpu_FUN_00bb3730_CpuObject::SkyShaderProperty_GetClampMode()
{
    return value;
}

namespace fnv_00bb3940 {
void SpeedTreeShaderLightingProperty_GetViewerStrings();

// @fnv 0x00bb3940
// src: XBOX_PDB 0x00bb3940
void SpeedTreeLeafShaderProperty_GetViewerStrings()
{
    SpeedTreeShaderLightingProperty_GetViewerStrings();
}
}  // namespace fnv_00bb3940

struct FUN_00b68dc0_class
{
    void LoadFromStream(NiStream&);
};
struct FUN_00bb44f0_class : FUN_00b68dc0_class
{
    void _BSShaderPPLightingProperty_LoadBinary(NiStream&);
};
// @fnv 0x00bb44f0
// src: COMMUNITY 0x00bb44f0
void FUN_00bb44f0_class::_BSShaderPPLightingProperty_LoadBinary(NiStream& a)
{
    LoadFromStream(a);
}

void __cdecl CheckAndNotify();
// @fnv 0x00bb4500
// src: COMMUNITY 0x00bb4500
void __cdecl SpeedTreeBillboardShaderProperty_RegisterStreamables()
{
    CheckAndNotify();
}

void __cdecl BSShaderPPLightingProperty_PostLinkObject();
// @fnv 0x00bb4510
// src: XBOX_PDB 0x00bb4510
void __cdecl Lighting30ShaderProperty_PostLinkObject()
{
    return BSShaderPPLightingProperty_PostLinkObject();
}

extern int DAT_0126f74c;
extern void* DAT_012007c4;
struct FUN_00e7de90_Class
{
    void* m0;
    int m4;
    int m8;
    void __thiscall ApplyPairToState(unsigned int);
    void __thiscall NiD3DTextureStage_SetFilterMode(unsigned int);
    void __thiscall FUN_00e7eb00(unsigned int);
};
// @fnv 0x00bb66c0
// src: XBOX_PDB 0x00bb66c0
void __stdcall BSDistantTreeShader_SetupPassTextures(unsigned int)
{
    if (DAT_012007c4)
    {
        FUN_00e7de90_Class* p = *(FUN_00e7de90_Class**)((char*)*(int*)(DAT_0126f74c + 0x24));
        p->m8 = (int)DAT_012007c4;
        p->ApplyPairToState(0);
        p->NiD3DTextureStage_SetFilterMode(5);
        p->FUN_00e7eb00(0);
    }
}


struct FUN_00bc3780_Class
{
    void BSShaderProperty_SaveBinary(NiStream& kStream);
};

struct NiMapBase : FUN_00bc3780_Class
{
    void BSShaderLightingProperty_SaveBinary(NiStream* pkStream);
};

// @fnv 0x00bb7160
// src: XBOX_PDB 0x00bb7160
void NiMapBase::BSShaderLightingProperty_SaveBinary(NiStream* pkStream)
{
    BSShaderProperty_SaveBinary(*pkStream);
}

extern int DAT_011f91e4;

class FUN_00bbe650_Class
{
  public:
    void __thiscall Lighting30Shader_SetupGeometryTextures(int* args);
};

// Reads DAT_011f91e4 and, unless it is 0x1e0, 0x1e1, 0xe or 0xf, calls virtual slots 79 and 80 with that value and args[3], then slot 67.
// @fnv 0x00bbe650
// src: XBOX_PDB 0x00bbe650
void __thiscall FUN_00bbe650_Class::Lighting30Shader_SetupGeometryTextures(int* args)
{
    int arg_c = args[3];
    int val = DAT_011f91e4;
    if (val != 0x1e0 && val != 0x1e1 && val != 0xe && val != 0xf)
    {
        ((void(__thiscall*)(void*, int, int))(*(void***)this)[79])(this, val, arg_c);
        ((void(__thiscall*)(void*, int, int))(*(void***)this)[80])(this, val, arg_c);
        ((void(__thiscall*)(void*))(*(void***)this)[67])(this);
    }
}

extern __declspec(thread) int DAT_012722b4;

struct S00baa660_Obj
{
    bool NiD3DShader_Initialize();
    bool TallGrassShader_Initialize();
};

struct S00baa660_Tls
{
    int saved;
    S00baa660_Tls()
    {
        saved = DAT_012722b4;
        DAT_012722b4 = 0x1c;
    }
    ~S00baa660_Tls()
    {
        DAT_012722b4 = saved;
    }
};

typedef void(__thiscall* S00baa660_VFn)(S00baa660_Obj*);

// If FUN_00e80570 returns true, calls virtual functions at offsets 0x12c, 0x134, and 0x130 on this object.
// @fnv 0x00baa660
// src: XBOX_PDB 0x00baa660
bool S00baa660_Obj::TallGrassShader_Initialize()
{
    S00baa660_Tls tls;
    bool result = NiD3DShader_Initialize();
    if (result)
    {
        void** vt = *(void***)this;
        ((S00baa660_VFn)vt[0x12c / 4])(this);
        vt = *(void***)this;
        ((S00baa660_VFn)vt[0x134 / 4])(this);
        vt = *(void***)this;
        ((S00baa660_VFn)vt[0x130 / 4])(this);
        result = true;
    }
    return result;
}

extern int DAT_011f91e4;
extern bool DAT_011f9ef0;
extern float DAT_01200550, DAT_01200554;
extern NiColorA DAT_01200570, DAT_01200520, DAT_01200510;
D3DXMATRIX* __stdcall D3DXMatrixInverse_00ee6dda(D3DXMATRIX*, float*, const D3DXMATRIX*);
NiPoint3* __stdcall D3DXVec3TransformNormal_00ee6df2(NiPoint3*, const NiPoint3*, const D3DXMATRIX*);
NiPoint3* __stdcall D3DXVec3Normalize_00ee6dec(NiPoint3*, const NiPoint3*);
struct ACList
{
    unsigned short BSShaderLightingProperty_GetNumberofActiveNonShadowLights();
};
struct ACGeometry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int kind;
};
inline int ACIsGeometry(const ACGeometry* g)
{
    return g ? g->kind == 4 : 0;
}
struct ACObject
{
    int unk00, unk04, unk08;
    ACGeometry* geometry;
};
struct ACSetter
{
    void NiDX9Renderer_SetModelTransform(const NiTransform*, int);
};
struct ACDirection
{
    float x, y, z;
    void Unitize_004a0c10();
};
struct ACLight
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    NiPoint3 ambient;
    NiPoint3 diffuse;
    int unke0, unke4, unke8, unkec;
    ACDirection direction;
    NiPoint3 GetAmbient() const
    {
        return ambient;
    }
    NiPoint3 GetDiffuse() const
    {
        return diffuse;
    }
};
struct ACLightOwner
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    ACLight* light;
};
struct ACShader
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ACSetter* setter;
    void TallGrassShader_SetupShadowData(int, const NiTransform*);
    void ApplyLightToEffect(ACList*, const D3DXMATRIX*, float, unsigned int);
    int FUN_00e807d0(int, int, int, int, ACObject*, int, const NiTransform*, int);
    int TallGrassShader_SetupTransformations(int, int, int, int, ACObject*, int, const NiTransform*, int);
};
struct UpPair
{
    ACDirection dir;
    NiPoint3 up;
};
// @fnv 0x00baac10
// src: XBOX_PDB 0x00baac10
int ACShader::TallGrassShader_SetupTransformations(int a, int b, int c, int d, ACObject* object, int f, const NiTransform* transform, int h)
{
    setter->NiDX9Renderer_SetModelTransform(transform, 0);
    D3DXMATRIX world, inverse;
    GetD3DFromNiBB2(world, *transform);
    unsigned int flags = DAT_011f91e4;
    D3DXMatrixInverse_00ee6dda(&inverse, 0, &world);
    UpPair upPair;
    upPair.up.x = 0.0f;
    upPair.up.y = 1.0f;
    upPair.up.z = 0.0f;
    NiPoint3& up = upPair.up;
    NiPoint3 transformedUp;
    D3DXVec3TransformNormal_00ee6df2(&transformedUp, &up, &inverse);
    D3DXVec3Normalize_00ee6dec(&up, &transformedUp);
    DAT_01200550 = up.x;
    DAT_01200554 = up.y;
    ACGeometry* geometry = object->geometry;
    ACList* list = reinterpret_cast<ACList*>(ACIsGeometry(geometry) ? geometry : 0);
    if (list)
    {
        ACLight* light = reinterpret_cast<ACLightOwner*>(BSShaderManager_GetAccumulator()->m_194->m_e0)->light;
        if (light)
        {
            int* __restrict pDestDir = reinterpret_cast<int*>(&upPair.dir);
            const int* __restrict pSrcDir = reinterpret_cast<const int*>(&light->direction);
            pDestDir[0] = pSrcDir[0];
            pDestDir[1] = pSrcDir[1];
            pDestDir[2] = pSrcDir[2];
            ACDirection& direction = upPair.dir;
            direction.Unitize_004a0c10();
            NiPoint3 color;
            CopyPointBits(color, light->ambient);
            DAT_01200570 = NiColorA(color.x, color.y, color.z, 1.0f);
            NiPoint3 diffuse;
            CopyPointBits(diffuse, light->diffuse);
            DAT_01200520 = NiColorA(diffuse.x, diffuse.y, diffuse.z, 1.0f);
            DAT_01200510 = NiColorA(-direction.x, -direction.y, -direction.z, 1.0f);
        }
        if (BSShaderAccumulator_IsShadowPass(flags))
            TallGrassShader_SetupShadowData(b, transform);
        else if (DAT_011f9ef0 && list->BSShaderLightingProperty_GetNumberofActiveNonShadowLights() > 0)
            ApplyLightToEffect(list, &inverse, transform->m_fScale, flags);
    }
    return FUN_00e807d0(a, b, c, d, object, f, transform, h);
}

struct S00bafd50_Sub
{
    void __thiscall FUN_004037f0(void* value, int flag);
};
struct S00bafd50_Arg
{
    void** m_vft;
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
    S00bafd50_Sub m_74;
};
struct S00bafd50_Obj
{
    void** m_vft;
};
struct S00bafd50_Cls
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
    S00bafd50_Obj* m_a8;
    int unkAC;
    int unkB0;
    void* m_b4;
    void __thiscall BSShaderData_SetupTexturesSkyShader(S00bafd50_Arg* argument);
};
typedef int(__thiscall* S00bafd50_GetFn)(void*, int);
typedef void(__thiscall* S00bafd50_FinishFn)(void*, void*);

// If m_a8 is set, passes the result of its vtable slot 35 (via NiGlobalStringTable::AddString) to argument->m_74, then calls argument's vtable slot 52 with m_b4.
// @fnv 0x00bafd50
// src: COMMUNITY 0x00bafd50
void S00bafd50_Cls::BSShaderData_SetupTexturesSkyShader(S00bafd50_Arg* argument)
{
    if (m_a8 != 0)
    {
        int value = ((S00bafd50_GetFn)m_a8->m_vft[35])(m_a8, 0);
        {
            NiFixedString result((const char*)value);
            S00bafd50_Sub& sub = argument->m_74;
            sub.FUN_004037f0(result.m_kHandle, 0);
        }
        ((S00bafd50_FinishFn)argument->m_vft[52])(argument, m_b4);
    }
}

struct S00ba1770_Heap
{
    void* Game_DoHeapAlloc(unsigned int size);
};

struct S00ba1770_Param : EffectParam
{
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
    char unk54;
    bool unk55;
    short unk56;
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
    S00ba1770_Param();
    void FUN_00b8ab10(int a1, int a2);
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<S00ba1770_Heap&>(g_memoryManager).Game_DoHeapAlloc(size);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct S00ba1770_Tex
{
    unsigned int FUN_00a90180(unsigned int size);
};

struct S00ba1770_Src
{
    int unk00;
    int GetAt(int i)
    {
        return (&unk00)[0x174 / 4 + i];
    }
};
struct S00ba1770_Data
{
    int unk00;
    int unk04;
    S00ba1770_Src* unk08;
};

struct S00ba1770_Effect : BaseEffect
{
    void SetTextureArraySize(int count);
    void FUN_00ba3c70(int index, int a2, S00ba1770_Param* param, int a4);
    void ImageSpaceEffectWaterFFT_Setup(S00ba1770_Data* data, int unused);
};

// Sets the texture array size to 12, then creates seven S00ba1770_Param objects, adds each to effects, and calls FUN_00ba3c70 with data->unk08->GetAt(i).
// @fnv 0x00ba1770
// src: COMMUNITY 0x00ba1770
void S00ba1770_Effect::ImageSpaceEffectWaterFFT_Setup(S00ba1770_Data* data, int unused)
{
    SetTextureArraySize(12);
    reinterpret_cast<S00ba1770_Tex&>(textures).FUN_00a90180(10);
    S00ba1770_Param* p;

    p = new S00ba1770_Param;
    p->FUN_00b8ab10(2, 3);
    p->unk55 = false;
    effects.FUN_00ba3aa0(0, p);
    FUN_00ba3c70(0, data->unk08->GetAt(0), p, 0);

    p = new S00ba1770_Param;
    p->FUN_00b8ab10(2, 3);
    p->unk55 = false;
    effects.FUN_00ba3aa0(1, p);
    FUN_00ba3c70(1, data->unk08->GetAt(1), p, 0);

    p = new S00ba1770_Param;
    p->FUN_00b8ab10(2, 3);
    p->unk55 = false;
    effects.FUN_00ba3aa0(2, p);
    FUN_00ba3c70(2, data->unk08->GetAt(2), p, 0);

    p = new S00ba1770_Param;
    p->FUN_00b8ab10(2, 3);
    p->unk55 = false;
    effects.FUN_00ba3aa0(3, p);
    FUN_00ba3c70(3, data->unk08->GetAt(3), p, 0);

    p = new S00ba1770_Param;
    p->FUN_00b8ab10(2, 3);
    p->unk55 = false;
    effects.FUN_00ba3aa0(4, p);
    FUN_00ba3c70(4, data->unk08->GetAt(4), p, 0);

    p = new S00ba1770_Param;
    p->FUN_00b8ab10(2, 3);
    p->unk55 = false;
    effects.FUN_00ba3aa0(5, p);
    FUN_00ba3c70(5, data->unk08->GetAt(5), p, 0);

    p = new S00ba1770_Param;
    p->FUN_00b8ab10(2, 3);
    p->unk55 = false;
    effects.FUN_00ba3aa0(6, p);
    FUN_00ba3c70(6, data->unk08->GetAt(6), p, 0);
}

struct Fn6290Result
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
};

struct Fn6290Item
{
    Fn6290Result* FUN_00a59d30(int value);
};

struct Fn6290Owner
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void Slot3c(unsigned int index);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    Fn6290Item** m_a0;
    unsigned short m_a4;
    unsigned short m_a6;
};

struct Fn6290Object
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Fn6290Owner* v0c();
};

extern int DAT_012003f0;
static __forceinline void DecRefCount(RefCounted* p)
{
    if (InterlockedDecrement(&p->m_uiRefCount) == 0)
        p->v1();
}

// Calls Slot3c(i) on pObject's owner for each item whose FUN_00a59d30(3) result has m_1c 0x11 and equals pWanted, then decrements DAT_012003f0.
// @fnv 0x00ba6290
// src: COMMUNITY 0x00ba6290
void __cdecl ParticleShader_Stop(Fn6290Object* pObject, Fn6290Result* pWanted)
{
    if (pObject == 0)
    {
        return;
    }
    Fn6290Owner* pOwner = pObject->v0c();
    if (pOwner == 0 || pWanted == 0)
    {
        return;
    }
    unsigned int i = 0;
    if (0 < pOwner->m_a6)
    {
        do
        {
            Fn6290Item* item = pOwner->m_a0[i];
            Fn6290Result* r;
            if (item != 0)
            {
                r = item->FUN_00a59d30(3);
            }
            else
            {
                r = 0;
            }
            unsigned int hit;
            if (r == 0)
            {
                hit = 0;
            }
            else
            {
                hit = (r->m_1c == 0x11);
            }
            Fn6290Result* v = hit ? r : 0;
            if (v != 0 && v == pWanted)
            {
                pOwner->Slot3c(i);
            }
            i++;
        } while (i < pOwner->m_a6);
    }
    if (--DAT_012003f0 > 0)
    {
        return;
    }
    if (DAT_012003f4 != 0)
    {
        DecRefCount(DAT_012003f4);
        DAT_012003f4 = 0;
    }
    DAT_012003f0 = 0;
}

struct FUN_00bae560_sp
{
    void FUN_00b8a790(int, float, float, float, float);
    void CopyParamData(int, int);
};

struct FUN_00bae560_v
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int v20(int);
};

struct FUN_00bae560_tex
{
    void* ImageSpaceTexture_GetTexture();
    void ImageSpaceTexture_ReturnRenderedTexture();
    void ImageSpaceTexture_ClearTexture();
};

struct FUN_00bae560_h
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00bae560_v* m_0c;
};

struct FUN_00bae560_g
{
    int unk00;
    int unk04;
    FUN_00bae560_h* m_08;
};

struct FUN_00bae560_p
{
    float m_00;
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
    float m_14;
};

struct FUN_00bae560_q
{
    int unk00;
    int unk04;
    FUN_00bae560_sp* m_08;
    FUN_00bae560_sp* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    FUN_00bae560_sp* m_2c;
    FUN_00bae560_sp* m_30;
};

extern FUN_00bae560_g* DAT_011f91ac;
extern FUN_00bae560_tex DAT_012005a4;
extern unsigned char DAT_012005a1;
extern unsigned char DAT_012005a2;
extern float DAT_011f9410;
extern float DAT_011add08;
extern double DAT_01015a38;
extern double DAT_01012060;
extern double DAT_01012070;

struct FUN_00bae560_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00bae560_q* m_1c;
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
    FUN_00bae560_p* m_6c;
    bool ImageSpaceEffectHDR_UpdateParams(int);
};

static float bae560_minf(float x, double d)
{
    if (x < d)
    {
        return 0.0f;
    }
    return x;
}

static float bae560_maxf(float x, double d)
{
    if (x > d)
    {
        return 1.0f;
    }
    return x;
}

// Returns false if m_6c is null; else calls FUN_00b8a790 on the m_1c entries m_08, m_2c, m_30, m_0c with values from m_6c and globals, and returns true.
// @fnv 0x00bae560
// src: COMMUNITY 0x00bae560
bool FUN_00bae560_cls::ImageSpaceEffectHDR_UpdateParams(int)
{
    if (m_6c == 0)
    {
        return false;
    }
    if (DAT_012005a1 != 0)
    {
        if (DAT_012005a4.ImageSpaceTexture_GetTexture() != 0)
        {
            DAT_012005a4.ImageSpaceTexture_ReturnRenderedTexture();
            DAT_012005a4.ImageSpaceTexture_ClearTexture();
        }
    }
    FUN_00bae560_h* h = DAT_011f91ac->m_08;
    FUN_00bae560_v* e = h->m_0c;
    FUN_00bae560_sp* r = m_1c->m_08;
    r->FUN_00b8a790(1, m_6c->m_10, 0.0f, 0.0f, 0.0f);
    int v = e->v20(0x40);
    r->CopyParamData(0x13, v);
    FUN_00bae560_sp* tt = m_1c->m_2c;
    float t = (float)(DAT_011f9410 * DAT_01015a38);
    t = bae560_maxf(bae560_minf(t, DAT_01012060), DAT_01012070);
    tt->FUN_00b8a790(0, 0.0f, 0.0f, t, 0.0f);
    tt->FUN_00b8a790(1, 0.0f, 0.0f, m_6c->m_00, m_6c->m_14);
    m_1c->m_30->FUN_00b8a790(1, m_6c->m_14, 0.0f, 0.0f, 0.0f);
    float flag = 0.0f;
    if (DAT_012005a2 != 0)
    {
        flag = 1.0f;
    }
    m_1c->m_0c->FUN_00b8a790(0x17, flag, 0.0f, 0.0f, 0.0f);
    m_1c->m_08->FUN_00b8a790(0x17, flag, 0.0f, 0.0f, DAT_011add08);
    return true;
}

// FUN_00baea50: /MT /O2 /GS /EHsc /Gy, 175 bytes, __thiscall with one stack argument.
// Generated layout; see levers.md.

struct FUN_00baea50_cls;
struct FUN_00baea50_arg;

struct StreamObj
{
    int unk00;
    int m_04;
    int(__cdecl* m_08)(StreamObj* self, void* p, int size, int* cb, int flag);
    void Read(void* p, int size)
    {
        int cb = size;
        m_04 += m_08(this, p, size, &cb, 1);
    }
    int Read2(void* p, int size)
    {
        int cb = size;
        return m_08(this, p, size, &cb, 1);
    }
};

struct FUN_00baea50_sub
{
    int unk00;
    int unk04;
    void FUN_004037f0(int a, int b);
};

struct FUN_00baea50_arg
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    StreamObj* m_24C;
    void FUN_00a64ce0(int* out);
};

struct FUN_00baea50_cls
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
    FUN_00baea50_sub m_74;
    int m_7C;
    int unk80;
    int unk84;
    unsigned short m_88;
    unsigned short unk8A;
    int m_8C;
    void BSShaderProperty_LoadBinary(FUN_00baea50_arg* a);
    void SkyShaderProperty_LoadBinary(FUN_00baea50_arg* a1);
};

static unsigned short DAT_012005b4;
void __cdecl _NiFree_00aa10f0(int a);

// Calls FUN_00ba92c0, reads m_7C and m_8C from a1's stream, updates m_74 from a1's value, and takes m_88 from a global counter when m_8C is 3.
// @fnv 0x00baea50
// src: XBOX_PDB 0x00baea50
void FUN_00baea50_cls::SkyShaderProperty_LoadBinary(FUN_00baea50_arg* a1)
{
    BSShaderProperty_LoadBinary(a1);
    a1->m_24C->Read(&m_7C, 4);
    int out = 0;
    a1->FUN_00a64ce0(&out);
    m_74.FUN_004037f0(out, 0);
    _NiFree_00aa10f0(out);
    a1->m_24C->Read(&m_8C, 4);
    if (m_8C == 3)
    {
        m_88 = DAT_012005b4++;
    }
}

namespace nbb {
struct RefObj
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_refs;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_refs) == 0)
            DeleteThis();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&m_refs);
    }
};
struct Ptr
{
    RefObj* m_p;
    Ptr& operator=(RefObj* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};
// NiTexturingProperty::Map: m_usFlags +0x04 (bits 12-13 = clamp mode passed to SetMode), m_spTexture +0x08;
// the shared NiTexturingProperty.h only forward-declares Map.
struct TexturingPropertyMap
{
    int unk00;
    unsigned short m_04;
    short pad;
    RefObj* m_08;
};
struct Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TexturingPropertyMap** m_20;
};
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Item* m_14;
};
struct Root248
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
    Holder holder;
    void UpdateProperties();
    void ForwardToSubobject(void*);
};
inline Holder* GetHolder(Root248* p)
{
    return &p->holder;
}
struct Owner
{
    virtual void m00();
    virtual void m01();
    virtual void m02();
    virtual void m03();
    virtual void m04();
    virtual void m05();
    virtual void m06();
    virtual void m07();
    virtual void m08();
    virtual void m09();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void SetMode(unsigned int mode);
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
    Ptr m_90;
    bool PrecipitationShaderProperty_SetupGeometry(Root248* param_2);
};
}
// Gets the holder's item; if present, stores its data's m_08 in m_90, calls SetMode from bits 12-13 of m_04 (3 if none), forwards the item, and returns true.
// @fnv 0x00bb12e0
// src: XBOX_PDB 0x00bb12e0
bool nbb::Owner::PrecipitationShaderProperty_SetupGeometry(Root248* apRoot)
{
    Holder* h = GetHolder(apRoot);
    if (!h)
    {
        apRoot->UpdateProperties();
        h = GetHolder(apRoot);
    }
    Item* item = h->m_14;
    if (item)
    {
        TexturingPropertyMap* d = *item->m_20;
        m_90 = d ? d->m_08 : 0;
        d = *item->m_20;
        SetMode(d ? (d->m_04 >> 12) & 3 : 3);
        apRoot->ForwardToSubobject(item);
        return true;
    }
    return false;
}

namespace ShaderInit {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" void* FUN_00ec61c0(void*, int, unsigned int);
extern const char DAT_010b9178[], DAT_010aece0[], DAT_01011584[], DAT_010b9174[], DAT_010b915c[], DAT_010b914c[],
    DAT_010a93e4[], DAT_010b9138[], DAT_010b9128[], DAT_010b9118[], DAT_010b8afc[];
extern int DAT_011f91c0;
extern bool DAT_011f948b, DAT_011f9421;
struct Macro
{
    const char* name;
    const char* value;
};
struct VertexShaderRequest
{
    const char* values[7];
    char parameters[48];
    operator const char**()
    {
        return values;
    }
};
void Initialize(const char** row, const char* path)
{
    row[0] = path;
    row[1] = 0;
    row[2] = 0;
    FUN_00ec61c0(row + 3, 0, 64);
}
void Initialize(const char** row, const char* path, const char* a)
{
    row[0] = path;
    row[1] = a;
    row[2] = DAT_01011584;
    row[3] = 0;
    row[4] = 0;
    FUN_00ec61c0(row + 5, 0, 56);
}
void Initialize(VertexShaderRequest& row, const char* path, const char* a, const char* b)
{
    row.values[0] = path;
    row.values[1] = a;
    row.values[2] = DAT_01011584;
    row.values[3] = b;
    row.values[4] = DAT_01011584;
    row.values[5] = 0;
    row.values[6] = 0;
    FUN_00ec61c0(row.parameters, 0, 48);
}
struct Program
{
    virtual void v0();
    virtual void Destroy();
    volatile long references;
};
struct Pointer
{
    Program* object;
    __forceinline void operator=(Program* value)
    {
        Program* old = object;
        if (old != value)
        {
            if (old && !InterlockedDecrement(&old->references))
                old->Destroy();
            object = value;
            if (value)
                InterlockedIncrement(&value->references);
        }
    }
};
void FUN_00be0c00(const char*, char*);
void BSsprintf(char*, unsigned int, const char*, ...);
const char* FUN_00b4f380(int);
struct Owner
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
    Pointer vertex[4], pixel[2];
    Program* FUN_00be0fe0(const char*, const char**, const char*, const char*);
    Program* FUN_00be1750(const char*, const char**, const char*, const char*);
    void SpeedTreeLeafShader_LoadShaders();
};
// Builds vertex and pixel shader requests, then compiles them into vertex[] and pixel[] programs using the active profile.
// @fnv 0x00bb13d0
// src: COMMUNITY 0x00bb13d0
void Owner::SpeedTreeLeafShader_LoadShaders()
{
    const char* apixels[2][19];
    VertexShaderRequest zvertices[4];
    Initialize(zvertices[0], DAT_010b9178);
    Initialize(zvertices[1], DAT_010b9178, DAT_010aece0);
    Initialize(zvertices[2], DAT_010b9178, DAT_010b9174);
    Initialize(zvertices[3], DAT_010b9178, DAT_010b9174, DAT_010aece0);
    Initialize(apixels[0], DAT_010b915c);
    Initialize(apixels[1], DAT_010b915c, DAT_010aece0);
    char name[260];
    char path[260];
    for (int i = 0; i < 4; i++)
    {
        if (zvertices[i][0])
        {
            FUN_00be0c00(zvertices[i][0], path);
            BSsprintf(name, 260, DAT_010b914c, i);
            vertex[i] = FUN_00be0fe0(path, (zvertices[i] + 1), DAT_010a93e4, name);
        }
        else
            vertex[i] = 0;
    }
    const char* profile = FUN_00b4f380(1);
    if (DAT_011f91c0 >= 2)
    {
        for (int i = 0; i < 2; i++)
        {
            const char** macros = apixels[i] + 1;
            if (apixels[i][0])
            {
                if (DAT_011f948b)
                {
                    DAT_011f9421 = true;
                    for (int pass = 0; pass < 2; pass++)
                    {
                        DAT_011f9421 = !DAT_011f9421;
                        if (DAT_011f9421)
                        {
                            const char** macro = apixels[i] + 1;
                            for (int j = 1; *macro; j++)
                            {
                                macro = &apixels[i][j * 2 + 1];
                            }
                            macro[0] = DAT_010b8afc;
                            macro[1] = DAT_01011584;
                            BSsprintf(name, 260, DAT_010b9138, i);
                        }
                        else
                            BSsprintf(name, 260, DAT_010b9128, i);
                        FUN_00be0c00(apixels[i][0], path);
                        pixel[i] = FUN_00be1750(path, macros, profile, name);
                    }
                }
                else
                {
                    if (DAT_011f9421)
                    {
                        const char** macro = apixels[i] + 1;
                        for (int j = 1; *macro; j++)
                        {
                            macro = &apixels[i][j * 2 + 1];
                        }
                        macro[0] = DAT_010b8afc;
                        macro[1] = DAT_01011584;
                        BSsprintf(name, 260, DAT_010b9138, i);
                    }
                    else
                        BSsprintf(name, 260, DAT_010b9128, i);
                    FUN_00be0c00(apixels[i][0], path);
                    pixel[i] = FUN_00be1750(path, macros, profile, name);
                }
            }
            else
                pixel[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            if (apixels[i][0])
            {
                FUN_00be0c00(apixels[i][0], path);
                BSsprintf(name, 260, DAT_010b9118, i);
                pixel[i] = FUN_00be1750(path, (apixels[i] + 1), profile, name);
            }
            else
                pixel[i] = 0;
        }
    }
}
}

struct FUN_00a5a040_Class
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
    void __thiscall UpdateProperties();
};

struct FUN_00bb3440_Class
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
    int m_58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int m_7c;
    int __thiscall SpeedTreeShaderLightingProperty_ClarifyShader(FUN_00a5a040_Class* a1, int a2, int a3);
};

// Calls FUN_00a5a040 on a1 if &a1->unk9c is null, sets m_58 to 0 when m_7c is 0, and returns 0.
// @fnv 0x00bb3440
// src: XBOX_PDB 0x00bb3440
int FUN_00bb3440_Class::SpeedTreeShaderLightingProperty_ClarifyShader(FUN_00a5a040_Class* a1, int, int)
{
    int v = 0;
    if (&a1->unk9c == 0)
        a1->UpdateProperties();
    if (m_7c == v)
        m_58 = v;
    return 0;
}

extern long DAT_011f4400;

namespace bb3470 {

class BBRefObj : public NiRefObject
{
  public:
    virtual __forceinline ~BBRefObj()
    {
        if (m_pResource != 0 && m_us0C > 0)
            ((MemoryManager*)&DAT_011f6238)->Deallocate(m_pResource);
    }

    BBRefObj* FUN_00bb3470(unsigned int uiFlags);

    void* m_pResource;
    unsigned short m_us0C;
    unsigned short m_us0E;
};

// Runs the BBRefObj destructor (frees m_pResource if m_us0C > 0, decrements a global counter) and frees the object if uiFlags bit 0 is set; returns this.
// @fnv 0x00bb3470
BBRefObj* BBRefObj::FUN_00bb3470(unsigned int uiFlags)
{
    this->BBRefObj::~BBRefObj();
    if (uiFlags & 1)
        operator delete(this, 0x10);
    return this;
}
}

template <class T> class Pointer_bb37
{
  public:
    ~Pointer_bb37()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    Pointer_bb37& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

class ShaderBase_bb37
{
  public:
    virtual void v00();
    ~ShaderBase_bb37();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
};

class FUN_00bb3790 : public ShaderBase_bb37
{
  public:
    virtual void v00();
    ~FUN_00bb3790();
    Pointer_bb37<NiRefObject> m_spTexture0;
    int unk80;
    Pointer_bb37<NiRefObject> m_spTexture1;
};

// Destructor: clears m_spTexture1 then m_spTexture0, releasing their references, after which the ShaderBase_bb37 base destructor runs.
// @fnv 0x00bb3790
FUN_00bb3790::~FUN_00bb3790()
{
    m_spTexture1 = 0;
    m_spTexture0 = 0;
}

class BaseObj_ba
{
  public:
    int unk04;
    virtual ~BaseObj_ba();
};

class Elem_ba
{
  public:
    virtual ~Elem_ba();
};

class Sub_ba
{
  public:
    int unk00;
    void Remove(unsigned int aiIndex, Elem_ba** ppOut);
};

class Lock_ba
{
  public:
    virtual void v00();
    virtual void v04();
    CRITICAL_SECTION cs;
};

class LockMember_ba
{
  public:
    Lock_ba* m_pLock;
    ~LockMember_ba()
    {
        Lock_ba* pLock = m_pLock;
        if (pLock != 0 && !TryEnterCriticalSection(&pLock->cs))
        {
            pLock->v04();
        }
    }
};

class FUN_00ba0400 : public BaseObj_ba
{
  public:
    int unk08, unk0c, unk10, unk14;
    Sub_ba m_18;
    Elem_ba** m_pArr;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    LockMember_ba m_58;
    virtual ~FUN_00ba0400();
};

// Deletes each non-null element of m_pArr and removes it from m_18 for all 9 slots.
// @fnv 0x00ba0400
FUN_00ba0400::~FUN_00ba0400()
{
    for (unsigned int i = 0; i < 9; i++)
    {
        if (m_pArr[i] != 0)
        {
            delete m_pArr[i];
            Elem_ba* pOut = 0;
            m_18.Remove(i, &pOut);
        }
    }
}

#include <math.h>
extern __declspec(thread) int DAT_012722b4;
struct MemoryContext
{
    int previous;
    MemoryContext(int value)
    {
        previous = DAT_012722b4;
        DAT_012722b4 = value;
    }
    ~MemoryContext()
    {
        DAT_012722b4 = previous;
    }
};
struct Locked
{
    int pitch;
    void* data;
};
struct BufferDevice
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual int __stdcall Lock(unsigned int, Locked*, unsigned int, unsigned int);
    virtual int __stdcall Unlock(unsigned int);
};
struct TextureObject
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual BufferDevice* device();
};
struct TextureView
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    TextureObject* object;
    TextureObject* GetObject()
    {
        return object;
    }
};
struct TextureHandle
{
    int unk00, unk04, unk08, unk0c;
    TextureView* ImageSpaceTexture_GetTexture();
};
struct FFTBuffers
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    TextureHandle coefficients;
    TextureHandle permutation;
    void ImageSpaceEffectWaterFFT_FillFFTUtilityTextures(int, int);
};
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
inline float LocalSin(float x)
{
    return (float)sin(x);
}
// Builds a bit-reversed index table and a per-stage twiddle table, then locks and fills the permutation and coefficients buffers with them.
// @fnv 0x00ba1ac0
// src: COMMUNITY 0x00ba1ac0
void FFTBuffers::ImageSpaceEffectWaterFFT_FillFFTUtilityTextures(int count, int stages)
{
    MemoryContext a(29);
    Locked z;
    float* order = new float[count];
    short* indices = new short[count];
    int i;
    int j = 0;
    FUN_00ec61c0(order, 0, count * sizeof(float));
    BufferDevice* device = permutation.ImageSpaceTexture_GetTexture()->GetObject()->device();
    for (i = 0; i < count; i++)
        order[i] = (float)(i + 0.5) / count;
    for (i = 0; i < count; i++)
    {
        if (i > j)
        {
            float temp = order[j];
            order[j] = order[i];
            order[i] = temp;
        }
        int half = count >> 1;
        while ((j >= half) & (half >= 2))
        {
            j -= half;
            half >>= 1;
        }
        j += half;
    }
    for (i = 0; i < count; i++)
        indices[i] = (short)(order[i] * 65535.0);
    device->Lock(0, &z, 0, 0);
    FUN_00ec44d0(z.data, indices, count * 2);
    device->Unlock(0);
    delete[] order;
    delete[] indices;
    device = coefficients.ImageSpaceTexture_GetTexture()->GetObject()->device();
    float* table = new float[count << 6];
    FUN_00ec61c0(table, 0, count << 8);
    int span = 1;
    for (int stage = 0; stage < stages; stage++)
    {
        int half = span;
        span <<= 1;
        float theta = (float)(-6.2831854820251465 / -span);
        float sine = LocalSin((float)(0.5 * theta));
        float wpr = (float)(-2.0 * sine * sine);
        float wpi = LocalSin(theta);
        float wr = 1.0f;
        float wi = 0.0f;
        for (int j = 0; j < half; j++)
        {
            for (i = j; i < count; i += span)
            {
                int l = half + i;
                double a = (l + 0.5) / (float)count;
                table[(stage * count + l) * 4] = -a;
                float b = (float)((i + 0.5) / (float)count);
                table[(stage * count + i) * 4 + 1] = table[(stage * count + l) * 4 + 1] = b;
                table[(stage * count + i) * 4] = a;
                table[(stage * count + l) * 4 + 2] = wr;
                table[(stage * count + l) * 4 + 3] = wi;
                table[(stage * count + i) * 4 + 2] = wr;
                table[(stage * count + i) * 4 + 3] = wi;
            }
            sine = wr;
            wr += wr * wpr - wi * wpi;
            wi += sine * wpi + wi * wpr;
        }
    }
    device->Lock(0, &z, 0, 0);
    FUN_00ec44d0(z.data, table, count << 8);
    device->Unlock(0);
    delete[] table;
}

class FUN_00ba2d40_cls
{
  public:
    int m_00;
    HANDLE m_04;
    int m_08;

    FUN_00ba2d40_cls* Semaphore_Create();
};

// Initializes m_00 and m_08, creates a semaphore with initial count 0 and maximum 0x14 into m_04, and returns this.
// @fnv 0x00ba2d40
// src: COMMUNITY 0x00ba2d40
FUN_00ba2d40_cls* FUN_00ba2d40_cls::Semaphore_Create()
{
    m_00 = 0;
    m_08 = 0x14;
    m_04 = CreateSemaphoreA(NULL, *(volatile int*)&m_00, 0x14, NULL);
    return this;
}

class FUN_00ba2d70_cls
{
  public:
    void ForwardCall_00ba2d70();

    int unk00;
    HANDLE m_hHandle;
};

// @fnv 0x00ba2d70
// src: GUESS 0x00ba2d70 (confidence: low)
void FUN_00ba2d70_cls::ForwardCall_00ba2d70()
{
    CloseHandle(m_hHandle);
}

struct AAF40Geometry
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void vfunc40();
    virtual void vfunc44();
    virtual void vfunc48();
    virtual void vfunc4C();
    virtual void vfunc50();
    virtual void vfunc54();
    virtual void vfunc58();
    virtual void vfunc5C();
    virtual void vfunc60();
    virtual void vfunc64();
    virtual void vfunc68();
    virtual void vfunc6C();
    virtual void vfunc70();
    virtual void vfunc74();
    virtual void vfunc78();
    virtual void vfunc7C();
    virtual void vfunc80();
    virtual void vfunc84();
    virtual void vfunc88();
    virtual void vfunc8C();
    virtual void vfunc90();
    virtual void vfunc94();
    virtual void vfunc98();
    virtual void vfunc9C();
    virtual void vfuncA0();
    virtual void SetActiveVertexQuantity(unsigned short m_usPassCountLocal);

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
    unsigned short m_usTotal;
};

struct AAF40Owner
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    AAF40Geometry* m_pkRenderableGeometry;
};

struct AAF40Model
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
    unsigned short m_usVertsPerParticle;
};

struct AAF40Data
{
    AAF40Owner* m_pkOwnerManager;
    int unk04;
    AAF40Model* m_pkModel;
    int unk0C;
    unsigned short m_usNumParticles;
    unsigned short m_usActive;
    void* m_pkParticles;
};

struct AAF40Object
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
    AAF40Data* m_pUserData;
};

struct AAF40Counter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_iActive;
};

struct AAF40Updater
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
    void* m_pCacheEntry;
    AAF40Counter* m_pkCounter;

    void TallGrassShader_SetupInstanceSize(void* pUnused, AAF40Object* pkObject);
};

// Copies particle data into m_pCacheEntry, sets the active vertex count on the geometry, and updates m_pkCounter->m_iActive.
// @fnv 0x00baaf40
// src: COMMUNITY 0x00baaf40
void AAF40Updater::TallGrassShader_SetupInstanceSize(void* pUnused, AAF40Object* pkObject)
{
    AAF40Data* pkData = pkObject->m_pUserData;
    int iEntryIndex = pkData->m_usNumParticles;
    memmove(m_pCacheEntry, pkData->m_pkParticles, iEntryIndex * 16);
    unsigned short usActive = pkData->m_usActive;
    AAF40Geometry* pkGeom = pkData->m_pkOwnerManager->m_pkRenderableGeometry;
    pkGeom->SetActiveVertexQuantity(usActive == iEntryIndex
                                        ? pkGeom->m_usTotal
                                        : (unsigned short)(pkData->m_pkModel->m_usVertsPerParticle * usActive));
    if (m_pkCounter)
        m_pkCounter->m_iActive = pkData->m_usActive;
}

namespace ShaderDraw {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern LocalVec3 DAT_011fa2a0;
extern Vec4 DAT_011fa280, DAT_011fa290, DAT_011fa0c0, DAT_011fa0d0;
extern unsigned char DAT_011f91c4, DAT_011f941c;
extern bool DAT_011f91a7;
extern int DAT_011f91b8;
extern const float DAT_010231a8;
extern float DAT_01200608, DAT_0120060c, DAT_0120065c, DAT_0120066c, DAT_01200660, DAT_01200670, DAT_01200678,
    DAT_0120067c, DAT_01200680, DAT_01200684;
struct Fog
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    LocalVec3 color;
    float farDistance, nearDistance;
};
Fog* BSShaderManager_GetFogProperty(unsigned char);
struct Geometry
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
    LocalVec3 position;
};
struct MaterialValues
{
    float unk00, unk04, unk08, alpha, emissive, ambient, u, v;
};
struct Material
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
    virtual unsigned int Texture();
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
    virtual void v62();
    virtual MaterialValues* Values();
    virtual const void* Constants();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int type;
    unsigned int BSShaderLightingProperty_GetNumberofActiveLights();
    __forceinline float U()
    {
        return Values()->u;
    }
    __forceinline float V()
    {
        return Values()->v;
    }
};
__forceinline unsigned int IsMaterial(Material* p)
{
    if (!p)
        return 0;
    unsigned int type = p->type;
    return type == 6;
}
struct PassInfo
{
    unsigned int mode;
    int unk04, unk08;
    Material* material;
};
struct RefObject
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long count;
};
struct RefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->count) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->count);
        }
    }
};
struct RenderState
{
    void SetNodeValue(unsigned int, unsigned int, bool);
};
RenderState* FUN_00e7f5d0();
struct Stage
{
    int unk00, unk04;
    unsigned int texture;
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
    int references;
    void NiD3DTextureStage_ReturnStageToPool();
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            NiD3DTextureStage_ReturnStageToPool();
    }
};
struct StagePointer
{
    Stage* object;
    StagePointer(Stage* p) : object(p)
    {
        if (object)
            ++object->references;
    }
    ~StagePointer()
    {
        if (object)
            object->Release();
    }
};
struct Pass
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
    Stage** stages;
    int unk28, unk2c;
    RenderState* state;
    int unk34, unk38, unk3c, unk40;
    RefPointer pixel;
    int unk48, unk4c, unk50, unk54, unk58;
    RefPointer vertex;
    void NiD3DPass_SetVertexShader(RefObject*);
    void NiD3DPass_SetPixelShader(RefObject*);
    __forceinline void SetState(unsigned int key, unsigned int value, bool save)
    {
        if (!state)
            state = FUN_00e7f5d0();
        state->SetNodeValue(key, value, save);
    }
};
struct Renderer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Select(unsigned int);
};
void* FUN_00ec44d0(void*, const void*, unsigned int);
struct Shader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Renderer* renderer;
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
    float constants[192];
    RefObject* normalVertex;
    RefObject* fogVertex;
    RefObject* alternateVertex;
    RefObject* alternateFogVertex;
    RefObject* normalPixel;
    RefObject* fogPixel;
    Pass* pass;
    __forceinline RefObject* Get_normalVertex() const
    {
        return normalVertex;
    }
    __forceinline RefObject* Get_fogVertex() const
    {
        return fogVertex;
    }
    __forceinline RefObject* Get_alternateVertex() const
    {
        return alternateVertex;
    }
    __forceinline RefObject* Get_alternateFogVertex() const
    {
        return alternateFogVertex;
    }
    __forceinline RefObject* Get_normalPixel() const
    {
        return normalPixel;
    }
    __forceinline RefObject* Get_fogPixel() const
    {
        return fogPixel;
    }
    void UpdateFields_00bb1f60(Geometry*, int, int, PassInfo*, int, int, Bound*);
};
// @fnv 0x00bb1f60
// src: GUESS 0x00bb1f60 (confidence: low)
void Shader::UpdateFields_00bb1f60(Geometry* geometry, int unused1, int unused2, PassInfo* info, int FlushUsageData, int unused4,
                          Bound* bound)
{
    unsigned int mode = info->mode;
    renderer->Select(mode);
    bool useFog = false;
    Fog* fog = BSShaderManager_GetFogProperty(DAT_011f91c4);
    if (fog)
    {
        float farDistance = fog->farDistance;
        float nearDistance = fog->nearDistance;
        LocalVec3 camera;
        camera.x = DAT_011fa2a0.x;
        camera.y = DAT_011fa2a0.y;
        camera.z = DAT_011fa2a0.z;
        const float& dx = geometry->position.x - camera.x;
        const float& dy = geometry->position.y - camera.y;
        const float& dz = geometry->position.z - camera.z;
        float distance = (float)sqrt(dy * dy + dx * dx + dz * dz);
        if (distance > farDistance || distance + bound->Radius() > farDistance)
        {
            float interval = nearDistance - farDistance;
            LocalVec3 color = fog->color;
            useFog = true;
            DAT_011fa280 = Vec4(nearDistance, interval, 0.0f, 0.0f);
            DAT_011fa290 = Vec4(color.x, color.y, color.z, 0.0f);
        }
    }
    if (DAT_011f91a7)
    {
        DAT_011fa0c0 = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
        if (DAT_011f91b8 == 9)
            DAT_011fa0d0 = Vec4(0.0f, DAT_010231a8, 0.0f, 0.0f);
        else
            DAT_011fa0d0 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    Material* material = info->material;
    int isMaterial = IsMaterial(material);
    material = isMaterial ? material : 0;
    const void* materialConstants = material->Constants();
    FUN_00ec44d0(constants, materialConstants, 768);
    DAT_0120065c = material->U() * DAT_01200608;
    DAT_0120066c = material->V() * DAT_0120060c;
    DAT_01200660 = material->Values()->ambient;
    DAT_01200670 = material->Values()->emissive;
    DAT_01200678 = 0.0f;
    DAT_0120067c = 0.0f;
    DAT_01200680 = 0.0f;
    DAT_01200684 = 0.0f;
    DAT_0120067c = material->Values()->alpha;
    Pass* currentPass = pass;
    Stage**& stages = currentPass->stages;
    StagePointer stage(stages[0]);
    stage.object->texture = material->Texture();
    if (DAT_011f91a7)
    {
        {
            Pass* active = pass;
            RefObject* incoming = normalVertex;
            RefObject* old = active->vertex.object;
            if (old != incoming)
            {
                if (old && InterlockedDecrement(&old->count) == 0)
                    old->DeleteThis();
                active->vertex.object = incoming;
                if (incoming)
                    InterlockedIncrement(&incoming->count);
            }
        }
        {
            Pass* active = pass;
            RefObject* incoming = normalPixel;
            RefObject* old = active->pixel.object;
            if (old != incoming)
            {
                if (old && InterlockedDecrement(&old->count) == 0)
                    old->DeleteThis();
                active->pixel.object = incoming;
                if (incoming)
                    InterlockedIncrement(&incoming->count);
            }
        }
    }
    else
    {
        unsigned int alternate = material->BSShaderLightingProperty_GetNumberofActiveLights();
        Pass* active = pass;
        if ((unsigned short)alternate == 0)
        {
            if (useFog)
            {
                active->NiD3DPass_SetVertexShader(Get_fogVertex());
                pass->NiD3DPass_SetPixelShader(Get_fogPixel());
            }
            else
            {
                active->NiD3DPass_SetVertexShader(Get_normalVertex());
                pass->NiD3DPass_SetPixelShader(Get_normalPixel());
            }
        }
        else if (useFog)
        {
            active->NiD3DPass_SetVertexShader(Get_alternateFogVertex());
            pass->NiD3DPass_SetPixelShader(Get_fogPixel());
        }
        else
        {
            active->NiD3DPass_SetVertexShader(Get_alternateVertex());
            pass->NiD3DPass_SetPixelShader(Get_normalPixel());
        }
    }
    if (DAT_011f91b8 == 6)
    {
        pass->SetState(52, 1, true);
        pass->SetState(56, 8, true);
        pass->SetState(55, 7, true);
        pass->SetState(53, 1, true);
        pass->SetState(54, 1, true);
    }
    else
        pass->SetState(52, 0, true);
    if ((DAT_011f941c & 1) > 0)
        pass->SetState(168, 0, true);
    else
        pass->SetState(168, 7, true);
    pass->SetState(28, 0, true);
}
}

extern NiBound DAT_011f4288;
extern float DAT_011f9470;
extern float DAT_011f9474;
extern float DAT_011f9478;
extern "C" float __cdecl LinearInterpolate(float, float, float, float, float);

extern ShadowSceneNode* DAT_011f91c8;

struct DecalMaterialProp
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
    float m_fAlpha;
};

struct DecalPropertyList
{
    int unk00;
    int unk04;
    DecalMaterialProp* m_pMaterial;
};

struct DecalShaderProperty
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
    float m_fHitDistance;
    unsigned int m_uiPass;
    BSShaderProperty__RenderPassArray* m_pRenderPassArray;

    void SetAlpha(float alpha);
    void InitRenderPasses(int count);

    BSShaderProperty__RenderPassArray* __thiscall UpdateRenderPasses(NiGeometry* geom, unsigned int pass, int a3,
                                                                     int passType, int a5, int a6);
};

// Computes camera distance to the decal, updates m_fHitDistance and alpha, and rebuilds the render pass array when the pass state changes.
// @fnv 0x00bb41e0
BSShaderProperty__RenderPassArray* DecalShaderProperty::UpdateRenderPasses(NiGeometry* geom, unsigned int pass, int a3,
                                                                           int passType, int a5, int a6)
{
    if (passType == 7)
        return 0;

    bool bRender = true;

    float fOldHitDistance;
    fOldHitDistance = m_fHitDistance;
    NiPoint3 camPos;
    CopyPointBits(camPos, DAT_011f91c8->kEyePosition);

    NiGeometry* pDecalGeom = geom;
    NiBound kBound;
    const NiBound& sourceBound = reinterpret_cast<NiBound*>(pDecalGeom->m_kWorldBound) ? *reinterpret_cast<NiBound*>(pDecalGeom->m_kWorldBound) : DAT_011f4288;
    unsigned int* __restrict boundDest = reinterpret_cast<unsigned int*>(&kBound);
    const unsigned int* __restrict boundSource = reinterpret_cast<const unsigned int*>(&sourceBound);
    boundDest[0] = boundSource[0];
    boundDest[1] = boundSource[1];
    boundDest[2] = boundSource[2];
    boundDest[3] = boundSource[3];

    NiPoint3 diff;
    diff.x = kBound.m_kCenter.x - camPos.x;
    diff.y = kBound.m_kCenter.y - camPos.y;
    diff.z = kBound.m_kCenter.z - camPos.z;

    float lenSq = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
    float len = sqrt(lenSq);
    float fDist;
    fDist = len - kBound.m_fRadius;
    m_fHitDistance = fDist;

    if (fDist != fOldHitDistance)
    {
        if ((DAT_011f9478 > fDist && DAT_011f9478 <= fOldHitDistance) ||
            (fDist >= DAT_011f9478 && fOldHitDistance < DAT_011f9478))
        {
            m_uiPass = 0;
        }
    }

    DecalPropertyList* pPropList = reinterpret_cast<DecalPropertyList*>(&pDecalGeom->m_PropertyState);
    if (pPropList)
    {
        DecalMaterialProp* bound;
        bound = pPropList->m_pMaterial;
        float z;
        z = 1.0f;
        if (bound)
        {
            z = bound->m_fAlpha;
            if (DAT_011f9470 != 0.0f && DAT_011f9470 <= fDist)
            {
                bRender = false;
            }
            else if (DAT_011f9474 != 0.0f && DAT_011f9478 != 0.0f && DAT_011f9474 <= fDist && fDist < DAT_011f9478)
            {
                z = LinearInterpolate(0.0f, 1.0f, DAT_011f9478, DAT_011f9474, fDist);
            }
        }
        SetAlpha(z);
    }

    if (m_uiPass != pass)
    {
        InitRenderPasses(1);
        m_pRenderPassArray->unk10 = 0;
        if (!bRender)
            return 0;

        if (!!pDecalGeom->m_spSkinInstance.m_pObject)
            m_pRenderPassArray->Add(geom, 0x24d, 1, 0, 0, 0, 0, 0);
        else
            m_pRenderPassArray->Add(geom, 0x24c, 1, 0, 0, 0, 0, 0);

        m_uiPass = (passType << 8) | pass;
    }

    return m_pRenderPassArray;
}

namespace fnv_00bb7170 {
extern int DAT_010b9c40;

struct PoolHeap
{
    int unk00;
    void* Game_DoHeapAlloc(unsigned int size);
};

extern "C" PoolHeap DAT_011f6238;

unsigned int __cdecl BSDistantTreeShader_GetMaxInstances();

struct BaseShim
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    BaseShim();
    ~BaseShim();
};

struct PoolElement20
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
};

struct FUN_00bb7170 : BaseShim
{
    int m_01c;
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
    int m_058;
    int unk5c;
    unsigned int m_060;
    PoolElement20* m_064;
    FUN_00bb7170();
};

// Sets the vtable pointer, m_058 to 8, m_060 from FUN_00bb6030, allocates m_064 as m_060 PoolElement20 entries, and sets m_01c to 0x18.
// @fnv 0x00bb7170
FUN_00bb7170::FUN_00bb7170()
{
    m_vptr = (int)&DAT_010b9c40;
    m_058 = 8;
    m_060 = BSDistantTreeShader_GetMaxInstances();
    m_064 = new PoolElement20[m_060];
    m_01c = 0x18;
}
}  // namespace fnv_00bb7170

struct GameHeap
{
    void* Allocate(unsigned int size);
};

extern GameHeap g_gameHeap;


struct ImageSpaceShaderParam : ImageSpaceEffectParam
{
    ImageSpaceShaderParam();
    static void* operator new(unsigned int size)
    {
        return g_gameHeap.Allocate(size);
    }
    static void operator delete(void* p);
    void SetParamCount(int a, int b);
    void SetParam(int index, const float* data, unsigned int size);
    void Finish();

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
};

struct ParamArray
{
    __declspec(noalias) void SetAt(unsigned int index, ImageSpaceEffectParam* const& value);
};

struct TexArray
{
    void SetSize(unsigned int size);
};

struct ImageSpaceTexture;

struct TexSource
{
    int unk00;
    int unk04;
    ImageSpaceTexture** unk08;
};

struct BlurVec
{
    float x;
    float y;
    float z;
    float w;
};

extern BlurVec DAT_011adc28[];

struct ISBlurEffect
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ParamArray params;
    int unk1c;
    int unk20;
    int unk24;
    TexArray textures;
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
    int radius;
    bool bFlag;

    void SetPassCount(int count);
    void SetPassFive(int a, int b, int c, int d, int e);
    void SetPassThree(int a, int b, int c);
    void SetPassTexture(int pass, ImageSpaceTexture* tex, ImageSpaceShaderParam* param, int mode);
    void SetupBlurPasses(TexSource* src, int unused);
};

// Configures two blur passes with shader params and textures based on radius and bFlag.
// @fnv 0x00ba46c0
void ISBlurEffect::SetupBlurPasses(TexSource* apTexSource, int unused)
{
    SetPassCount(2);
    if (bFlag)
        textures.SetSize(4);
    else
        textures.SetSize(3);
    int idx = radius - 1;
    const float* data = &DAT_011adc28[-idx].x;
    int iBaseOffset = bFlag ? 0x55 : 0x4e;
    int texIndex = idx + iBaseOffset;

    ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
    param->SetParamCount(0, 0x12);
    param->SetParam(1, data, idx * 32 + 0x10);
    param->Finish();
    {
        ImageSpaceEffectParam* p = param;
        params.SetAt(0, p);
    }
    if (bFlag)
        SetPassFive(0, 1, 3, 0, 0);
    else
        SetPassThree(0, 1, 0);
    ImageSpaceTexture* pBlurTexture = apTexSource->unk08[texIndex];
    SetPassTexture(0, pBlurTexture, param, 2);

    param = new ImageSpaceShaderParam;
    param->SetParamCount(0, 0x12);
    unsigned int size = idx * 32 + 0x10;
    param->SetParam(1, data, size);
    param->Finish();
    params.SetAt(1, param);
    SetPassThree(1, 2, 0);
    SetPassTexture(1, apTexSource->unk08[idx + 0x4e], param, 0);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct BA01A0Owner;

struct BA01A0Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int uiType;
    int IsKind() const
    {
        return (uiType - 1 <= 11) ? -1 : 0;
    }
    void AddWatcher(BA01A0Owner* owner) throw();
};

struct BA01A0Item : NiRefObject
{
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
    BA01A0Target* pTarget;
};

struct RefPtr_b9fcc0
{
    NiRefObject* m_p;
    RefPtr_b9fcc0(NiRefObject* p) : m_p(p)
    {
        m_p->IncRefCount();
    }
    RefPtr_b9fcc0(const RefPtr_b9fcc0& other) : m_p(other.m_p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    ~RefPtr_b9fcc0()
    {
        if (m_p)
            m_p->DecRefCount();
    }
};

struct SessionNode
{
    SessionNode* next;
    SessionNode* prev;
    RefPtr_b9fcc0 value;
};
struct List_b9fcc0
{
    SessionNode* head;
    SessionNode* tail;
    unsigned int count;
    RefPtr_b9fcc0 PopFront();
    RefPtr_b9fcc0 PopBack();
    void ReleaseRefCountedNode(SessionNode*);

    RefPtr_b9fcc0 FUN_00b9efa0(void*& key);
    RefPtr_b9fcc0 FUN_00b9fcc0(const RefPtr_b9fcc0& item);
};

struct BA01A0Owner
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    List_b9fcc0 kList;

    void ShadowSceneLight_RemoveTriGeom(BA01A0Item* item, void* key);
};

// If the item's target type is 1 to 12, calls its AddWatcher with this; then calls kList.FUN_00b9efa0 with key, or FUN_00b9fcc0 with the item when key is null.
// @fnv 0x00ba01a0
// src: COMMUNITY 0x00ba01a0
void BA01A0Owner::ShadowSceneLight_RemoveTriGeom(BA01A0Item* item, void* key)
{
    BA01A0Item* p = item;
    BA01A0Target* target = p->pTarget;
    if (target)
    {
        int b = target->uiType - 1 <= 11;
        BA01A0Target* t = (BA01A0Target*)((b != 0 ? -1 : 0) & (int)target);
        if (t)
            t->AddWatcher(this);
    }
    if (key)
    {
        kList.FUN_00b9efa0(key);
    }
    else
    {
        RefPtr_b9fcc0 temp(p);
        kList.FUN_00b9fcc0(temp);
    }
}

__declspec(noinline) RefPtr_b9fcc0 List_b9fcc0::FUN_00b9efa0(void*& key)
{
    SessionNode* node = (SessionNode*)key;
    if (node == head)
    {
        key = node->next;
        return PopFront();
    }
    if (node == tail)
    {
        key = 0;
        return PopBack();
    }
    SessionNode* previous = node->prev;
    SessionNode* following = node->next;
    key = following;
    if (previous)
        previous->next = following;
    if (following)
        following->prev = previous;
    RefPtr_b9fcc0 result = node->value;
    ReleaseRefCountedNode(node);
    --count;
    return result;
}

__declspec(noinline) RefPtr_b9fcc0 List_b9fcc0::FUN_00b9fcc0(const RefPtr_b9fcc0& item)
{
    SessionNode* node = head;
    while (node)
    {
        SessionNode* current = node;
        node = node->next;
        if (current->value.m_p == item.m_p)
        {
            node = current;
            break;
        }
    }
    void* cursor = node;
    return cursor ? FUN_00b9efa0(cursor) : item;
}

struct S2760_Xf
{
    float m00;
    float m01;
};

extern NiBound DAT_011f4288;

struct FUN_00b71360_water;
void __cdecl BSShaderLightingProperty_SetLight(unsigned int, FUN_00b71360_water*, float);

struct RenderGroup2760
{
    NiGeometry* geometry;
    int unk04;
    unsigned char unk08;
    unsigned char count;
    unsigned short unk0A;
    FUN_00b71360_water** waters;
};
extern NiGeometry** DAT_011f91e0;

struct CameraData2760
{
    int unk00;
    int unk04;
    int unk08;
    float value0C;
    float value10;
    float value14;
    float value18;
    float value1C;
};

struct Camera2760
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
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual CameraData2760* GetData();
    virtual const void* GetMatrix();
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
    float scale;
};

struct Input2760
{
    int unk00;
    int unk04;
    int unk08;
    Camera2760* camera;
};

struct Pass2760
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
    virtual void Submit(void*, NiGeometry*, void*, int, void*, Input2760*, int, const S2760_Xf&, NiBound*, int,
                        int);
};

struct PassManager2760
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
    NiPointer<NiD3DPass> pass44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    NiPointer<NiD3DPass> pass5C;
};

struct Shader2760
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
    virtual void Setup(NiGeometry*, int, int, void*, Input2760*, int, const S2760_Xf&, NiBound*);
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
    NiPointer<Pass2760> pass30;
    NiPointer<Pass2760> pass34;
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
    D3DXMATRIX matrix[12];  // Complete768-byte transform data block copied by this pass.
    void SpeedTreeLeafShader_SetupGeometryConstants(Input2760* input);
};

extern unsigned char DAT_011f91a7;
extern unsigned int DAT_011f91b8;
extern float DAT_010231a8;
extern float DAT_01200608;
extern float DAT_0120060c;
extern "C" Vec4 DAT_011FA0C0, DAT_011FA0D0;
extern "C" float DAT_0120065C, DAT_0120066C;
extern "C" float DAT_01200660, DAT_01200670, DAT_01200678, DAT_0120067C, DAT_01200680, DAT_01200684;
void* __cdecl _memmove(void*, const void*, unsigned int);

// Sets up shader state from input camera and geometry, then submits the geometry to the active render passes.
// @fnv 0x00bb2760
// src: XBOX_PDB 0x00bb2760
void Shader2760::SpeedTreeLeafShader_SetupGeometryConstants(Input2760* input)
{
    RenderGroup2760* group = (RenderGroup2760*)DAT_011f91e0;
    NiGeometry* geometry = group->geometry;
    const S2760_Xf& world = reinterpret_cast<const S2760_Xf&>(geometry->m_kWorld);
    NiBound* bound = reinterpret_cast<NiBound*>(geometry->m_kWorldBound);
    if (!bound)
        bound = (NiBound*)&DAT_011f4288;
    void* buffer = geometry->m_spModelData.m_pObject->m_pkBuffData;
    void* skin = geometry->m_spSkinInstance.m_pObject;
    Camera2760* camera = input->camera;
    float scale = camera->scale;
    for (unsigned char i = 0; i < group->count; i++)
        BSShaderLightingProperty_SetLight(i, group->waters[i], scale);
    Setup(geometry, 0, 0, buffer, input, 0, world, bound);
    if (DAT_011f91a7)
    {
        DAT_011FA0C0 = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
        if (DAT_011f91b8 == 9)
            DAT_011FA0D0 = Vec4(0.0f, DAT_010231a8, 0.0f, 0.0f);
        else
            DAT_011FA0D0 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    const void* m = camera->GetMatrix();
    _memmove(&matrix, m, 0x300);
    DAT_0120065C = camera->GetData()->value18 * DAT_01200608;
    DAT_0120066C = camera->GetData()->value1C * DAT_0120060c;
    DAT_01200660 = camera->GetData()->value14;
    DAT_01200670 = camera->GetData()->value10;
    DAT_01200678 = 0.0f;
    DAT_0120067C = 0.0f;
    DAT_01200680 = 0.0f;
    DAT_01200684 = 0.0f;
    DAT_0120067C = camera->GetData()->value0C;
    if (pass34 && ((PassManager2760*)DAT_0126f74c)->pass5C)
        pass34->Submit(((PassManager2760*)DAT_0126f74c)->pass5C, geometry, skin, 0, buffer, input, 0, world, bound, 0,
                       1);
    if (pass30 && ((PassManager2760*)DAT_0126f74c)->pass44)
        pass30->Submit(((PassManager2760*)DAT_0126f74c)->pass44, geometry, skin, 0, buffer, input, 0, world, bound, 0,
                       1);
}

extern int DAT_01200054;

extern bool DAT_01200059;

extern double DAT_010b7f40;

extern double DAT_010b7f30;

extern double DAT_01029790;

extern "C" int __cdecl rand();

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

extern float __cdecl Gaussian(float, float);

extern __declspec(thread) int DAT_012722b4;

struct S00ba20e0_Guard
{

    int previous;

    S00ba20e0_Guard() : previous(DAT_012722b4)
    {
        DAT_012722b4 = 29;
    }

    ~S00ba20e0_Guard()
    {
        DAT_012722b4 = previous;
    }
};

struct Spectrum
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

    float** radius;

    float** amplitude;

    float Evaluate(float, float);

    void Finish(bool*);

    void ImageSpaceEffectWaterFFT_FillWaterUtilityBuffers();
};

// Fills the radius and amplitude grids with computed distances and Gaussian-sampled values, then calls Finish.
// @fnv 0x00ba20e0
// src: COMMUNITY 0x00ba20e0
void Spectrum::ImageSpaceEffectWaterFFT_FillWaterUtilityBuffers()
{
    S00ba20e0_Guard guard;
    bool ready = true;
    float sample;
    float scale;
    float x;
    float y;
    int row;
    int col;
    int iOffset;
    for (int row = 0; row < DAT_01200054 + 1; ++row)
    {
        fnv_zlib_memset(radius[row], 0, DAT_01200054 * 4 + 1);
        fnv_zlib_memset(amplitude[row], 0, DAT_01200054 * 4 + 1);
        if (row < DAT_01200054)
            fnv_zlib_memset(radius[row], 0, DAT_01200054 * 4);
    }
    if (DAT_01200059)
    {
        for (row = 0; row <= DAT_01200054; ++row)
        {
            x = (row - DAT_01200054 * 0.5) * DAT_010b7f40;
            for (col = 0; col <= DAT_01200054; ++col)
            {
                y = (col - DAT_01200054 * 0.5) * DAT_010b7f40;
                float rv = x * x + y * y;
                rv = sqrt(rv);
                rv *= DAT_010b7f30;
                rv = sqrt(rv);
                radius[row][col] = rv;
                if (row < 32 && col < 32)
                    continue;
                if (row > DAT_01200054 - 32 && col < 32)
                    amplitude[row][col] = amplitude[row - DAT_01200054 + 64][col];
                else if (row < 32 && col > DAT_01200054 - 32)
                    amplitude[row][col] = amplitude[row][col - DAT_01200054 + 64];
                else if (row > DAT_01200054 - 32 && col > DAT_01200054 - 32)
                {
                    iOffset = 64 - DAT_01200054;
                    amplitude[row][col] = amplitude[iOffset + row][iOffset + col];
                }
                else
                {
                    scale = (x == 0 && y == 0) ? 0 : sqrt(Evaluate(x, y));
                    sample = Gaussian(0, 1);
                    float phase = rand() / DAT_01029790;
                    phase = phase * 2 * 3.1415927410125732;
                    phase = sin(phase);
                    amplitude[row][col] = sample * scale * phase;
                }
            }
        }
    }
    else
    {
        for (row = 0; row <= DAT_01200054; ++row)
        {
            x = (row - DAT_01200054 * 0.5) * DAT_010b7f40;
            for (col = 0; col <= DAT_01200054; ++col)
            {
                y = (col - DAT_01200054 * 0.5) * DAT_010b7f40;
                float rv = x * x + y * y;
                rv = sqrt(rv);
                rv *= DAT_010b7f30;
                rv = sqrt(rv);
                radius[row][col] = rv;
                scale = (x == 0 && y == 0) ? 0 : sqrt(Evaluate(x, y));
                sample = Gaussian(0, 1);
                float phase = rand() / DAT_01029790;
                phase = phase * 2 * 3.1415927410125732;
                phase = sin(phase);
                amplitude[row][col] = sample * scale * phase;
            }
        }
    }
    Finish(&ready);
}

struct Tex
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual int GetW37();
    virtual int GetH38();
};
struct IST
{
    bool unk00;
    bool unk01;
    bool unk02;
    void* unk04;
    void* unk08;
    void* unk0c;
    IST()
    {
        unk00 = 0;
        unk01 = 0;
        unk02 = 0;
        unk04 = 0;
        unk08 = 0;
        unk0c = 0;
    }
    ~IST();
    void __thiscall ImageSpaceTexture_BorrowRenderedTexture(unsigned int a);
    Tex* __thiscall ImageSpaceTexture_GetTexture();
    void* __thiscall ImageSpaceTexture_GetRenderedTexture();
    void __thiscall ImageSpaceTexture_SetTexture(void* a);
    void __thiscall ImageSpaceTexture_SetBorrowed(int a);
    void __thiscall ImageSpaceTexture_ReturnRenderedTexture();
    IST* __thiscall InitializeFields_00ba3940(IST* a);
};
struct Node
{
    virtual void nv00();
    virtual void Draw4(int a, int b, Node* c, int d);
    Node* m_04;
    Node* m_08;
    Node* m_0c;
    Node* m_10;
    Node* m_14;
    int m_18;
    Node* m_1c;
    int m_20;
    int m_24;
    int m_28;
    Node* m_2c;
    Node* m_30;
    void __thiscall SetAccumulatorAt(int a, void* b, int c);
    void __thiscall ImageSpaceShaderParam_SetTextureOffsets(int a, int b, int c);
    void __thiscall FUN_00b8a790(int a, float b, float c, float d, float e);
};
struct Ctx
{
    IST* textures[2];
    IST*& At(unsigned int i)
    {
        return textures[i];
    }
};
struct FPair
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
};
struct MgrInner
{
    virtual void mv00();
    virtual void mv01();
    virtual void mv02();
    virtual void mv03();
    virtual void mv04();
    virtual void mv05();
    virtual void mv06();
    virtual void mv07();
    virtual void mv08();
    virtual void mv09();
    virtual void mv10();
    virtual void mv11();
    virtual void mv12();
    virtual void mv13();
    virtual void mv14();
    virtual void mv15();
    virtual void mv16();
    virtual void mv17();
    virtual void mv18();
    virtual void mv19();
    virtual void mv20();
    virtual void mv21();
    virtual void mv22();
    virtual void mv23();
    virtual void mv24();
    virtual void mv25();
    virtual void mv26();
    virtual void mv27();
    virtual void mv28();
    virtual void mv29();
    virtual void mv30();
    virtual void mv31();
    virtual void mv32();
    virtual void mv33();
    virtual void mv34();
    virtual void mv35();
    virtual void mv36();
    virtual void mv37();
    virtual void mv38();
    virtual void mv39();
    virtual void mv40();
    virtual void mv41();
    virtual void mv42();
    virtual void mv43();
    virtual void mv44();
    virtual void mv45();
    virtual void mv46();
    virtual void mv47();
    virtual void mv48();
    virtual void mv49();
    virtual void mv50();
    virtual void mv51();
    virtual void mv52();
    virtual void mv53();
    virtual void mv54();
    virtual void mv55();
    virtual void mv56();
    virtual void mv57();
    virtual void mv58();
    virtual void mv59();
    virtual void mv60();
    virtual void mv61();
    virtual void mv62();
    virtual void mv63();
    virtual void mv64();
    virtual void mv65();
    virtual void mv66();
    virtual void mv67();
    virtual void mv68();
    virtual void __stdcall Call69(int, int, int);
};
struct Mgr2 : MgrInner
{
};
struct Mgr
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    Mgr2* m_288;
};
struct TexMgr
{
    void* __thiscall BSTextureManager_BorrowRenderedTexture_0(void* a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
};
struct ISMArr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    Node* m_5c[8];
};
struct ISM
{
    int m_00;
    int m_04;
    ISMArr* m_08;
};
struct TexRefObj : RefObj
{
    void __thiscall AddTexture(void* a);
};
TexRefObj* __cdecl BSShaderManager_GetShader(int a);
extern bool DAT_011f941f;
extern bool DAT_012005a0;
extern Mgr* DAT_011f4748;
extern TexMgr* DAT_011f91a8;
extern float DAT_012003c8;
extern float DAT_012003c4;
extern float DAT_011adbd4;
static __forceinline IST& GlobalTex()
{
    return *(IST*)&DAT_012005a4;
}
static __forceinline ISM* GlobalISM()
{
    return (ISM*)DAT_011f91ac;
}
struct PassArray
{
    Node* entries[13];
    Node*& At(unsigned int i)
    {
        return entries[i];
    }
};
struct Badb90This
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual bool Call7(int);
    char m_04;
    bool m_05;
    char m_06;
    char m_07;
    int m_08;
    PassArray* m_0c;
    int m_10;
    int m_14;
    int m_18;
    PassArray* m_1c;
    int m_20;
    int m_24;
    int m_28;
    Ctx* m_2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    bool m_68;
    char m_69;
    char m_6a;
    char m_6b;
    FPair* m_6c;
    void __thiscall ImageSpaceEffectHDR_Render(int a0, int a1, int a2, int a3);
};

static __forceinline Node* PreparePass(PassArray*& renderSet, PassArray*& parameterSet, unsigned int index, IST* output,
                                       Node*& argNode)
{
    Node* holder = renderSet->At(index);
    argNode = parameterSet->At(index);
    holder->SetAccumulatorAt(0, output, 0);
    return holder;
}
static __forceinline void ClampUpper(int& x, int hi)
{
    if (x > hi)
        x = hi;
}
static __forceinline int ClampLower(int x, int lo)
{
    if (x < lo)
        return lo;
    return x;
}
// Draws passes from the m_0c and m_1c node sets, repeatedly rendering to textures with width and height divided by 4 until both are 1, then draws final passes.
// @fnv 0x00badb90
// src: COMMUNITY 0x00badb90
void __thiscall Badb90This::ImageSpaceEffectHDR_Render(int a0, int a1, int a2, int a3)
{
    IST texA;
    IST texB;
    IST texC;
    IST texE;
    int w;
    int flag;
    Node* argNode;
    if (m_05)
        m_05 = Call7(a2);
    texB.ImageSpaceTexture_BorrowRenderedTexture(0);
    texA.ImageSpaceTexture_SetTexture(m_2c->At(1)->ImageSpaceTexture_GetRenderedTexture());
    w = texB.ImageSpaceTexture_GetTexture()->GetW37();
    a2 = texB.ImageSpaceTexture_GetTexture()->GetH38();
    flag = DAT_011f941f ? 1 : 0;

    if (m_68)
    {
        IST texD;
        Node* pRenderNode = m_0c->At(7);
        Node* pParamNode = m_1c->At(7);
        texD.ImageSpaceTexture_BorrowRenderedTexture(1);
        pRenderNode->SetAccumulatorAt(0, &texD, 0);
        pRenderNode->SetAccumulatorAt(1, &texA, 7);
        DAT_011f4748->m_288->Call69(0, 10, 8);
        {
            Tex* rt1 = texA.ImageSpaceTexture_GetTexture();
            Tex* rt2 = texA.ImageSpaceTexture_GetTexture();
            pParamNode->ImageSpaceShaderParam_SetTextureOffsets(0, rt2->GetW37(), rt1->GetH38());
        }
        pRenderNode->Draw4(a0, a1, pParamNode, 1);
        pRenderNode->SetAccumulatorAt(0, &texB, 0);
        pRenderNode->SetAccumulatorAt(1, &texD, 0);
        {
            Tex* rt1 = texB.ImageSpaceTexture_GetTexture();
            Tex* rt2 = texA.ImageSpaceTexture_GetTexture();
            pParamNode->ImageSpaceShaderParam_SetTextureOffsets(0, rt2->GetW37(), rt1->GetH38());
        }
        char* enabled = (char*)pRenderNode->m_2c->m_04;
        *enabled = 1;
        pRenderNode->Draw4(a0, a1, pParamNode, 1);
        DAT_011f4748->m_288->Call69(0, 10, 1);
        texD.ImageSpaceTexture_ReturnRenderedTexture();
    }
    else
    {
        Node* pRenderNode = m_0c->At(5);
        Node* pParamNode = m_1c->At(5);
        pRenderNode->SetAccumulatorAt(0, &texB, 0);
        pRenderNode->SetAccumulatorAt(1, &texA, flag);
        {
            Tex* rt1 = texA.ImageSpaceTexture_GetTexture();
            Tex* rt2 = texA.ImageSpaceTexture_GetTexture();
            pParamNode->FUN_00b8a790(2, 1.0f / (float)(unsigned int)rt2->GetW37(),
                                     1.0f / (float)(unsigned int)rt1->GetH38(), 0.0f, 0.0f);
        }
        pRenderNode->Draw4(a0, a1, pParamNode, 1);
    }
    if (DAT_012005a0)
    {
        Tex* t = texA.ImageSpaceTexture_GetTexture();
        TexRefObj* r = BSShaderManager_GetShader(9);
        r->AddTexture(t);
    }
    texC.InitializeFields_00ba3940(texA.InitializeFields_00ba3940(&texB));

    while (w > 1 || a2 > 1)
    {
        w /= 4;
        if (w < 1)
            w = 1;
        a2 /= 4;
        if (a2 < 1)
            a2 = 1;
        int nw = w;
        int nh = a2;
        texB.ImageSpaceTexture_SetTexture(DAT_011f91a8->BSTextureManager_BorrowRenderedTexture_0(DAT_011f9508, nw, nh, 4, 0x71, 0, 0, 0, 0, 0));
        texB.ImageSpaceTexture_SetBorrowed(1);
        if (nh > 1 || nw > 1)
        {
            Node* edi2 = m_0c->At(5);
            Node* ebp2 = m_1c->At(5);
            edi2->SetAccumulatorAt(0, &texB, 0);
            edi2->SetAccumulatorAt(1, &texA, flag);
            {
                Tex* t1 = texA.ImageSpaceTexture_GetTexture();
                Tex* t2 = texA.ImageSpaceTexture_GetTexture();
                ebp2->FUN_00b8a790(2, 1.0f / (float)(unsigned int)t2->GetW37(),
                                   1.0f / (float)(unsigned int)t1->GetH38(), 0.0f, 0.0f);
            }
            edi2->Draw4(a0, a1, ebp2, 1);
            {
                Tex* tr = m_2c->At(1)->ImageSpaceTexture_GetTexture();
                if (texA.ImageSpaceTexture_GetTexture() != tr)
                {
                    Tex* savedTexture = texC.ImageSpaceTexture_GetTexture();
                    if (texA.ImageSpaceTexture_GetTexture() != savedTexture)
                        texA.ImageSpaceTexture_ReturnRenderedTexture();
                }
            }
            texA.InitializeFields_00ba3940(&texB);
        }
    }
    {
        Tex* pGlobalTex = GlobalTex().ImageSpaceTexture_GetTexture();

        if (pGlobalTex == 0)
        {
            Node* holder = PreparePass(m_0c, m_1c, 12, &texB, argNode);
            holder->SetAccumulatorAt(1, &texA, flag);
            {
                Tex* rt1 = texB.ImageSpaceTexture_GetTexture();
                Tex* rt2 = texB.ImageSpaceTexture_GetTexture();
                argNode->FUN_00b8a790(2, 1.0f / (float)(unsigned int)rt2->GetW37(),
                                      1.0f / (float)(unsigned int)rt1->GetH38(), 0.0f, 0.0f);
            }
            holder->Draw4(a0, a1, argNode, 1);
            GlobalTex().InitializeFields_00ba3940(&texB);
        }
        else
        {
            Node* holder = PreparePass(m_0c, m_1c, 11, &texB, argNode);
            holder->SetAccumulatorAt(1, &texA, flag);
            holder->SetAccumulatorAt(2, &GlobalTex(), 0);
            {
                Tex* rt1 = texB.ImageSpaceTexture_GetTexture();
                Tex* rt2 = texB.ImageSpaceTexture_GetTexture();
                argNode->FUN_00b8a790(2, 1.0f / (float)(unsigned int)rt2->GetW37(),
                                      1.0f / (float)(unsigned int)rt1->GetH38(), 0.0f, 0.0f);
            }
            holder->Draw4(a0, a1, argNode, 1);
            GlobalTex().ImageSpaceTexture_ReturnRenderedTexture();
            GlobalTex().InitializeFields_00ba3940(&texB);
        }
    }
    texE.ImageSpaceTexture_BorrowRenderedTexture(2);
    {
        int t = (int)m_6c->m_04 - 1;
        ClampUpper(t, 6);
        int ebx = ClampLower(t, 0);
        DAT_012003c8 = m_6c->m_1c;
        DAT_011adbd4 = m_6c->m_18;
        DAT_012003c4 = (float)(ebx + 1);
        Node* holder = GlobalISM()->m_08->m_5c[ebx];
        holder->SetAccumulatorAt(0, &texC, 0);
        holder->SetAccumulatorAt(1, &texC, 0);
        holder->SetAccumulatorAt(2, &texE, 0);
        if ((unsigned int)ebx <= 6)
            holder->SetAccumulatorAt(3, &GlobalTex(), 0);
        holder->Draw4(a0, a1, argNode, 1);
        Node* fholder;
        if (DAT_012005a2)
            fholder = m_0c->At(4);
        else
            fholder = m_0c->At(3);
        Node* ebxNode = m_1c->At(2);
        fholder->SetAccumulatorAt(0, m_2c->At(0), 0);
        fholder->SetAccumulatorAt(1, &texC, flag);
        fholder->SetAccumulatorAt(2, m_2c->At(1), 0);
        fholder->SetAccumulatorAt(3, &GlobalTex(), 0);
        fholder->Draw4(a0, a1, ebxNode, 1);
    }
    if (DAT_012005a0)
    {
        Tex* t;
        TexRefObj* r;
        t = texC.ImageSpaceTexture_GetTexture();
        r = BSShaderManager_GetShader(9);
        r->AddTexture(t);
        t = GlobalTex().ImageSpaceTexture_GetTexture();
        r = BSShaderManager_GetShader(9);
        r->AddTexture(t);
        t = texE.ImageSpaceTexture_GetTexture();
        r = BSShaderManager_GetShader(9);
        r->AddTexture(t);
    }
    texC.ImageSpaceTexture_ReturnRenderedTexture();
    texE.ImageSpaceTexture_ReturnRenderedTexture();
    if (texA.ImageSpaceTexture_GetTexture() != GlobalTex().ImageSpaceTexture_GetTexture())
        texA.ImageSpaceTexture_ReturnRenderedTexture();
}

namespace fnv_00baeb80 {
namespace nb {
struct Ref
{
    virtual void vf();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct P
{
    int x;
    short a, b;
    P() : x(0), a(0), b(0)
    {}
    ~P();
};
struct Color
{
    float r, g, b, a;
    Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
};
}

class FUN_00ba8e50
{
  public:
    char pad[0x5c];
    FUN_00ba8e50();
    virtual ~FUN_00ba8e50();
};
class FUN_00baeb80 : public FUN_00ba8e50
{
  public:
    nb::Color m_60;
    NiPointer<nb::Ref> m_70;
    nb::P m_78;
    int m_7c;
    NiPointer<nb::Ref> m_80;
    float m_84;
    short m_88;
    int m_8c;
    FUN_00baeb80();
    virtual ~FUN_00baeb80();
};
// Constructor: sets m_7c to 3, clears m_80, m_84 and m_88, sets m_8c to 8, copies a color from DAT_011a9be0 into m_60, and writes 13 at offset 0x1c.
// @fnv 0x00baeb80
FUN_00baeb80::FUN_00baeb80() : m_7c(3)
{
    m_80 = 0;
    m_84 = 0.0f;
    m_88 = 0;
    m_8c = 8;
    m_60 = *(nb::Color*)&DAT_011a9be0;
    *(int*)((char*)this + 0x1c) = 13;
}
}  // namespace fnv_00baeb80

namespace fnv_00bb8ea0 {
struct ISRefObject
{
    virtual ~ISRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

struct ISTexture
{
    int unk00;
    ~ISTexture();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct ISEffectParam
{
    virtual ~ISEffectParam();
};



struct ISEffectBase
{
    virtual ~ISEffectBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NiTArray<ISEffectParam*, NiTMallocInterface<ISEffectParam*> > m_kParams;
    NiTArray<ISTexture*, NiTMallocInterface<ISTexture*> > m_kTextureSwapList;
};

struct FUN_00bb8ea0 : ISEffectBase
{
    static NiPointer<ISRefObject> spObjA;
    static NiPointer<ISRefObject> spObjB;
    virtual ~FUN_00bb8ea0();
};

// Destructor that nulls spObjA and spObjB, then deletes and clears texture swap list entries 1-3 and the first effect param.
// @fnv 0x00bb8ea0
FUN_00bb8ea0::~FUN_00bb8ea0()
{
    spObjA = 0;
    spObjB = 0;
    if (m_kTextureSwapList.m_pBase[1])
    {
        delete m_kTextureSwapList.m_pBase[1];
        m_kTextureSwapList.SetAt(1, 0);
    }
    if (m_kTextureSwapList.m_pBase[2])
    {
        delete m_kTextureSwapList.m_pBase[2];
        m_kTextureSwapList.SetAt(2, 0);
    }
    if (m_kTextureSwapList.m_pBase[3])
    {
        delete m_kTextureSwapList.m_pBase[3];
        m_kTextureSwapList.SetAt(3, 0);
    }
    if (m_kParams.m_pBase[0])
    {
        delete m_kParams.m_pBase[0];
        m_kParams.SetAt(0, 0);
    }
}
}  // namespace fnv_00bb8ea0

// Releases the slot's texture reference when the destructor ends (the member smart pointer of the original).
struct BA3A00RefRelease
{
    IST* m_pSlot;

    ~BA3A00RefRelease()
    {
        NiRefObject* object = static_cast<NiRefObject*>(m_pSlot->unk04);
        if (object)
            object->DecRefCount();
    }
};

// Destructor that calls FUN_00ba39a0 if unk02 is set, then decrements the reference count of the NiRefObject in unk04 and nulls it.
// @fnv 0x00ba3a00
FUN_00ba3a00::~FUN_00ba3a00()
{
    IST* slot = reinterpret_cast<IST*>(this);
    BA3A00RefRelease release = {slot};

    if (slot->unk02)
        slot->ImageSpaceTexture_ReturnRenderedTexture();

    NiRefObject* object = static_cast<NiRefObject*>(slot->unk04);
    if (object)
    {
        object->DecRefCount();
        slot->unk04 = 0;
    }
}

struct FFTUploadEffect
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
    TextureHandle tex58;
    TextureHandle tex68;
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
    float** tableA8;
    float** tableAC;

    void ImageSpaceEffectWaterFFT_FillWaterUtilityTextures(bool* pDirty);
};

// If *pDirty, copies tableA8 into tex58's locked buffer and clears it; always writes tableAC values, mirrored and plain, into tex68's locked buffer.
// @fnv 0x00ba1f20
// src: COMMUNITY 0x00ba1f20
void FFTUploadEffect::ImageSpaceEffectWaterFFT_FillWaterUtilityTextures(bool* pDirty)
{
    MemoryContext tag(0x1d);
    Locked lr;
    BufferDevice* tex;
    float* p;
    int i, j;
    if (*pDirty)
    {
        tex = tex58.ImageSpaceTexture_GetTexture()->GetObject()->device();
        tex->Lock(0, &lr, 0, 0);
        p = (float*)lr.data;
        for (i = 0; i < DAT_01200054; i++)
            for (j = 0; j < DAT_01200054; j++)
                *p++ = tableA8[i][j];
        tex->Unlock(0);
        *pDirty = false;
    }
    tex = tex68.ImageSpaceTexture_GetTexture()->GetObject()->device();
    tex->Lock(0, &lr, 0, 0);
    p = (float*)lr.data;
    for (i = 0; i < DAT_01200054; i++)
        for (j = 0; j < DAT_01200054; j++)
        {
            *p++ = tableAC[DAT_01200054 - i][DAT_01200054 - j];
            *p++ = tableAC[DAT_01200054 - i][DAT_01200054 - j];
            *p++ = tableAC[i][j];
            *p++ = tableAC[i][j];
        }
    tex->Unlock(0);
}

extern "C" void _ReadWriteBarrier();

enum P368Enum
{
    S6_ENUM_MIN = 0,
    S6_ENUM_MAX = 0x1e1
};

// Based on an unverified contribution attributed to another contributor (2026-10-23).

struct P368Light
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

    unsigned char unk74;
    unsigned char unk75;
    unsigned short unk76;

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

    unsigned int unkC4;

    unsigned int unkC8;

    unsigned int unkCC;

    unsigned int unkD0;

    unsigned int unkD4;

    unsigned int unkD8;

    unsigned int unkDC;

    unsigned int unkE0;

    unsigned int unkE4;

    unsigned int unkE8;

    bool special;

    unsigned int unkF0;

    unsigned int unkF4;

    P368Light* source;
};

struct P368Pass
{
    void* unk00;
    unsigned short type;
    unsigned char blend;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char count;
    unsigned char capacity;
    unsigned char unk0B;
    P368Light** lights;
    void BSShaderProperty_RenderPass_ClearSceneLights();
    void AllocateElemArray(unsigned char);
};

struct P368PassArray
{
    unsigned int unk00;
    P368Pass** data;
    unsigned int unk08, unk0C, size;
    void FUN_00ba9ee0(void*, unsigned int, bool, unsigned char, P368Light*, P368Light*, P368Light*, P368Light*);
};

struct P368Camera
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

    unsigned char unk74;
    unsigned char unk75;
    unsigned short unk76;

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

    unsigned int unkC4;

    unsigned int unkC8;

    unsigned int unkCC;

    unsigned int unkD0;

    unsigned int unkD4;

    unsigned int unkD8;

    unsigned int unkDC;

    unsigned int unkE0;

    unsigned int unkE4;

    unsigned int unkE8;

    unsigned int unkEC;

    unsigned int unkF0;

    unsigned int unkF4;

    unsigned int unkF8;

    unsigned int unkFC;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10C;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11C;

    unsigned int mode;

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

    unsigned int unk15C;

    unsigned int unk160;

    unsigned int unk164;

    unsigned int unk168;

    unsigned int unk16C;

    unsigned int unk170;

    unsigned int unk174;

    unsigned int unk178;

    unsigned int unk17C;

    unsigned int unk180;

    unsigned int unk184;

    unsigned int unk188;

    unsigned int unk18C;

    unsigned int unk190;

    unsigned int unk194;

    unsigned int unk198;

    unsigned int unk19C;

    unsigned int unk1A0;

    unsigned int unk1A4;

    unsigned int unk1A8;

    unsigned int unk1AC;

    unsigned int unk1B0;

    unsigned int unk1B4;

    unsigned int unk1B8;

    unsigned int unk1BC;

    unsigned int unk1C0;

    unsigned int unk1C4;

    unsigned int unk1C8;

    unsigned int unk1CC;

    unsigned int unk1D0;

    unsigned int unk1D4;

    unsigned int unk1D8;

    unsigned int unk1DC;

    unsigned int unk1E0;

    unsigned int unk1E4;

    unsigned int unk1E8;

    unsigned int unk1EC;

    LocalVec3 eye;

    unsigned int unk1FC;
};

struct P368Context
{

    unsigned int unk00;

    unsigned int unk04;

    P368Context* state;

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

    unsigned char unk74;
    unsigned char unk75;
    unsigned short unk76;

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

    unsigned int unkC4;

    unsigned int unkC8;

    unsigned int unkCC;

    unsigned int unkD0;

    unsigned int unkD4;

    unsigned int unkD8;

    unsigned int unkDC;

    unsigned int unkE0;

    unsigned int unkE4;

    unsigned int unkE8;

    unsigned int unkEC;

    unsigned int unkF0;

    unsigned int unkF4;

    unsigned int unkF8;

    unsigned int unkFC;

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

    unsigned int unk15C;

    unsigned int unk160;

    unsigned int unk164;

    unsigned int unk168;

    unsigned int unk16C;

    unsigned int unk170;

    unsigned int unk174;

    unsigned int unk178;

    unsigned int unk17C;

    unsigned int unk180;

    unsigned int unk184;

    unsigned int unk188;

    unsigned int unk18C;

    unsigned int unk190;

    P368Camera* camera;

    unsigned int unk198, unk19C, unk1A0;
};

extern NiBound DAT_011f4288;
extern const float DAT_011f9458;
extern float DAT_011f9460, DAT_011f9468, DAT_011f946c;
extern float DAT_011f9470;

bool IsParticleShaderRendererEnabled();
int GetGlobalFloatAsUInt();
bool BSShaderManager_GetShadows();
float LinearInterpolate(float, float, float, float, float);

struct P368Shader
{

    unsigned int unk00;

    unsigned int unk04;

    unsigned int unk08;

    unsigned int unk0C;

    unsigned int unk10;

    unsigned int unk14;

    unsigned int unk18;

    unsigned int unk1C;

    union
    {
        struct
        {
            unsigned int unk20, unk24;
        };
        unsigned int shaderFlagWords[2];
    };

    float alpha;

    float fade;

    unsigned int unk30;

    float distance;

    unsigned int key;

    P368PassArray* passes;

    P368PassArray* depth;

    P368PassArray* shadow;

    P368PassArray* normal;

    unsigned int unk4C;

    unsigned int unk50;

    P368PassArray* velocity;

    unsigned int unk58;

    unsigned int unk5C;

    unsigned int unk60;

    unsigned int unk64;

    unsigned int unk68;

    unsigned int unk6C;

    unsigned int unk70;

    unsigned char unk74;
    unsigned char unk75;
    unsigned short unk76;

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

    unsigned int* texture;

    unsigned int unkB8;

    unsigned int unkBC;

    unsigned int unkC0;

    unsigned int unkC4;

    unsigned int unkC8;

    unsigned int unkCC;

    unsigned int unkD0;

    unsigned int unkD4;

    unsigned int unkD8;

    P368Shader* extra;

    unsigned int unkE0;

    bool FUN_004a2020(int);
    void EnsureNewObj(bool);
    void EnsureBa9740Obj(bool);
    void EnsureAllocated(bool);
    void CreateSpawnedObjectIfMissing(bool);
    void FUN_00ba95e0(int);
    void BSShaderProperty_SetAlpha(float);
    void SortShadowSceneLights(NiBound*);
    P368Light* BSShaderLightingProperty_GetFirstActiveNonShadowLight(void**);
    P368Light* BSShaderLightingProperty_GetNextActiveNonShadowLight(void**);
    P368Light* FUN_00b70590(void**);
    P368Light* BSShaderLightingProperty_GetNextActiveLight(void**);
    void BSShaderProperty_SetFlag(int, int);
    P368PassArray* Lighting30ShaderProperty_GetRenderPasses(NiGeometry*, unsigned int, bool, unsigned int, P368Context*, bool);
};

__declspec(noinline) bool P368Shader::FUN_004a2020(int n)
{
    return double(shaderFlagWords[unsigned(n) >> 5] & (1u << (unsigned(n) % 32))) > 0.0;
}
// Selects and builds the P368PassArray for a given pass index, updating lights, distance, and blend state based on shader flags and context.
// @fnv 0x00bb4740
// src: XBOX_PDB 0x00bb4740
P368PassArray* P368Shader::Lighting30ShaderProperty_GetRenderPasses(NiGeometry* geom, unsigned int auFlags, bool unused, unsigned int pass,
                                        P368Context* context, bool unused2)

{

    NiProperty** ppProperties = geom->m_PropertyState.m_aspProps;

    unsigned int requested = (pass << 8) | auFlags;

    bool skipDistance = (unk24 & 0x800000) > 0;

    bool hasAlpha = true, hasFade = true, hasExtra = false;

    if (pass == 7)
    {

        if ((unk20 & 0x8000) > 0 || (unk20 & 0x10000) > 0)
            return 0;

        EnsureNewObj(true);

        P368PassArray* a = depth;

        if (a->size)
        {

            P368Pass* p = a->data[0];

            if (p->count > 0)
                p->lights[0] = (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0;
        }
        else
        {

            if (geom->m_spModelData.m_pObject->m_pkColor)
            {

                if (!FUN_004a2020(1))
                    a->FUN_00ba9ee0(geom, 0x1c9, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);

                else
                    a->FUN_00ba9ee0(geom, 0x1cb, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);
            }
            else
            {

                if (!FUN_004a2020(1))
                    a->FUN_00ba9ee0(geom, 0x1c8, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);

                else
                    a->FUN_00ba9ee0(geom, 0x1ca, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);
            }
        }

        return depth;
    }

    if (pass == 8)
    {

        if ((unk20 & 0x8000) > 0 || (unk20 & 0x10000) > 0 || (unk24 & 0x10) > 0)
            return shadow;

        EnsureBa9740Obj(true);

        P368PassArray* a = shadow;

        if (a->size)
        {

            P368Pass* p = a->data[0];

            if (p->count > 0)
                p->lights[0] = (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0;
        }
        else
        {

            bool skinned = false;
            if (geom->m_spModelData.m_pObject->m_pkColor)
                skinned = true;

            if (!FUN_004a2020(1))
            {

                if (skinned)
                    a->FUN_00ba9ee0(geom, 0x1d4, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);

                else
                    a->FUN_00ba9ee0(geom, 0x1d3, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);
            }
            else
            {

                if (skinned)
                    a->FUN_00ba9ee0(geom, 0x1d6, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);

                else
                    a->FUN_00ba9ee0(geom, 0x1d5, true, 1, (P368Light*)((P368Context*)DAT_011f4748)->state->unk1A0, 0, 0,
                                    0);
            }
        }

        return shadow;
    }

    if (pass == 9)
    {

        EnsureAllocated(true);

        P368PassArray* a = normal;

        if (!a->size)
        {

            if ((unk20 & 0x100000) > 0)
                a->FUN_00ba9ee0(geom, 0x1df, true, 0, 0, 0, 0, 0);

            else if (!FUN_004a2020(1))
                a->FUN_00ba9ee0(geom, 0x1dd, true, 0, 0, 0, 0, 0);

            else
                a->FUN_00ba9ee0(geom, 0x1de, true, 0, 0, 0, 0, 0);
        }

        return normal;
    }

    if (pass == 15)
    {

        CreateSpawnedObjectIfMissing(true);

        P368PassArray* a = velocity;

        if (!a->size && !geom->m_spSkinInstance.m_pObject)
        {

            if (FUN_004a2020(0x25))
                a->FUN_00ba9ee0(geom, 0x1bc, true, 0, 0, 0, 0, 0);

            else
                a->FUN_00ba9ee0(geom, 0x1bb, true, 0, 0, 0, 0, 0);
        }

        return velocity;
    }

    NiBound bound;

    float previous = distance;

    unsigned int shaderFlags = unk20;

    bool rangeA = (shaderFlags & 0x80) > 0 && DAT_011f9460 > 0.0f;

    bool rangeB = (shaderFlags & 0x20000) > 0 && DAT_011f9468 > 0.0f;

    bool rangeC =
        ((shaderFlags & 0x4000000) > 0 || FUN_004a2020(0x1b) == true) && DAT_011f9470 > 0.0f && !FUN_004a2020(0x23);

    bool rangeD = (shaderFlags & 1) > 0 && DAT_011f9458 > 0.0f;

    if (rangeB || rangeA || rangeC || rangeD)
    {

        P368Camera* camera = context->camera;
        LocalVec3 eye;
        eye.xb = camera->eye.xb;
        eye.yb = camera->eye.yb;
        eye.zb = camera->eye.zb;

        {
            NiBound* src = reinterpret_cast<NiBound*>(geom->m_kWorldBound) ? reinterpret_cast<NiBound*>(geom->m_kWorldBound) : (NiBound*)&DAT_011f4288;
            unsigned int x = reinterpret_cast<unsigned int&>(src->m_kCenter.x), y = reinterpret_cast<unsigned int&>(src->m_kCenter.y);
            _ReadWriteBarrier();
            reinterpret_cast<unsigned int&>(bound.m_kCenter.x) = x;
            unsigned int z = reinterpret_cast<unsigned int&>(src->m_kCenter.z);
            reinterpret_cast<unsigned int&>(bound.m_kCenter.y) = y;
            reinterpret_cast<unsigned int&>(bound.m_fRadius) = reinterpret_cast<unsigned int&>(src->m_fRadius);
            reinterpret_cast<unsigned int&>(bound.m_kCenter.z) = z;
        }

        LocalVec3 delta(bound.m_kCenter.x - eye.x, bound.m_kCenter.y - eye.y, bound.m_kCenter.z - eye.z);

        distance = delta.FUN_00457990() - bound.m_fRadius;

        if (((P368Context*)BSShaderManager_GetAccumulator())->state)
            distance *= *(float*)&((P368Context*)BSShaderManager_GetAccumulator())->state->unk110;

        if (distance != previous)
        {

            if (rangeB)
            {

                if ((distance < DAT_011f9468 && previous >= DAT_011f9468) ||
                    (distance >= DAT_011f9468 && previous < DAT_011f9468))
                    key = 0;
            }
            else if (rangeA)
            {

                if ((distance < DAT_011f9460 && previous >= DAT_011f9460) ||
                    (distance >= DAT_011f9460 && previous < DAT_011f9460))
                    key = 0;
            }

            if (rangeC && ((distance < DAT_011f9470 && previous >= DAT_011f9470) ||
                           (distance >= DAT_011f9470 && previous < DAT_011f9470)))
                key = 0;

            if (rangeD && !skipDistance)
            {

                if ((distance < DAT_011f9458 && previous >= DAT_011f9458) ||
                    (distance >= DAT_011f9458 && previous < DAT_011f9458))
                    key = 0;

                if (distance >= DAT_011f9458)
                    rangeD = false;
            }
        }
    }

    if (!skipDistance && DAT_011f9460 != 0.0f && distance >= DAT_011f9460)
        hasAlpha = false;

    if (ppProperties)
    {

        float factor = 1.0f;

        P368Context* fadeProperty = (P368Context*)ppProperties[2];

        if (fadeProperty)
        {

            if (rangeC)
            {

                if (DAT_011f9470 != 0.0f && distance >= DAT_011f9470)
                    hasFade = false;

                else if (DAT_011f946c != 0.0f && DAT_011f9470 != 0.0f && distance >= DAT_011f946c &&
                         distance < DAT_011f9470)

                    factor = LinearInterpolate(0.0f, 1.0f, DAT_011f9470, DAT_011f946c, distance);

                else
                    factor = *(float*)&fadeProperty->unk3C * fade;
            }
            else
                factor = *(float*)&fadeProperty->unk3C * fade;
        }
        else
            factor = fade;

        BSShaderProperty_SetAlpha(factor);

        if (factor < 1.0f)
            hasExtra = true;
    }

    if ((unsigned char)unk74)
    {

        bound = *(reinterpret_cast<NiBound*>(geom->m_kWorldBound) ? reinterpret_cast<NiBound*>(geom->m_kWorldBound) : (NiBound*)&DAT_011f4288);

        SortShadowSceneLights(&bound);
    }

    void* cursor;

    void* singleCursor;

    void* extraCursor;

    if (key == requested && (unsigned char)unk74)
    {

        P368Light* defaultLight = (P368Light*)((P368Context*)BSShaderManager_GetAccumulator())->camera->unkE0;

        for (unsigned int i = 0; i < passes->size; ++i)
        {

            P368Pass* p = passes->data[i];

            if (p->type >= 0x17f && p->type <= 0x1ba)
            {

                unsigned char count = 1;

                P368Light* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor);

                if (light)
                    do
                    {
                        ++count;
                        light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
                    } while (light);

                if (count > 0)
                {

                    if (p->capacity < count)
                    {
                        p->BSShaderProperty_RenderPass_ClearSceneLights();
                        p->AllocateElemArray(count);
                        p->capacity = count;
                    }

                    light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&cursor);

                    p->lights[0] = defaultLight;

                    int j = 1;

                    while (light && j < count)
                    {
                        p->lights[j++] = light;
                        light = BSShaderLightingProperty_GetNextActiveNonShadowLight(&cursor);
                    }

                    p->count = (unsigned char)j;
                }
                else
                    p->count = 0;
            }
            else if (p->type >= 0x1bd && p->type <= 0x1c3)
            {

                if (p->count == 1)
                {
                    P368Light* light = BSShaderLightingProperty_GetFirstActiveNonShadowLight(&singleCursor);
                    if (light)
                        p->lights[0] = light;
                    else
                        p->lights[0] = defaultLight;
                }
            }
            else if (p->type >= 0x1c4 && p->type <= 0x1c7 && p->count == 1)
            {

                P368Light* light = FUN_00b70590(&extraCursor);

                if (light && light->special && !(light->source->unk30 & 1))
                    p->lights[0] = light;

                else
                {
                    key = 0;
                    break;
                }
            }
        }

        unk74 = 0;
    }

    if (key == requested)
        return passes;

    FUN_00ba95e0(-1);
    passes->size = 0;
    unk74 = 0;
    _ReadWriteBarrier();

    bool allowed = !((unk20 & 0x100000) > 0 && !DAT_011f91a7);

    bool specialFade = hasFade && (FUN_004a2020(0x1a) || FUN_004a2020(0x1b));

    if (alpha == 0.0f || !allowed || (rangeC && !specialFade))
        return passes;

    bool skin = FUN_004a2020(1);

    bool extraPass = hasAlpha && FUN_004a2020(7);

    bool bFlag11 = FUN_004a2020(0x11);

    bool bFlag15 = FUN_004a2020(0x15);

    bool bFlag0F = FUN_004a2020(0xf);

    bool bFlag10 = FUN_004a2020(0x10);

    bool bFlag0B = FUN_004a2020(0xb);

    bool bFlag1C = FUN_004a2020(0x1c);

    bool bFlag0A = FUN_004a2020(0xa);

    bool textured = *texture != 0;

    rangeC = false;

    bool rangeDLater = FUN_004a2020(0) && (((char*)&requested)[0] & 8) > 0 && rangeD;

    bool skipDistanceLater = hasExtra || (static_cast<NiAlphaProperty*>(geom->m_PropertyState.m_aspProps[0])->m_usAlphaArg & 1) != 0;

    bool scene = IsParticleShaderRendererEnabled() && !FUN_004a2020(0xd) && GetGlobalFloatAsUInt() &&
                 (unsigned char)((P368Context*)BSShaderManager_GetAccumulator())->camera->mode != 1 &&
                 (unsigned char)((P368Context*)BSShaderManager_GetAccumulator())->camera->mode != 3;

    if (geom->m_spModelData.m_pObject->m_pkColor || FUN_004a2020(0x25))
        rangeC = true;

    if (extra)
        scene = false;

    if (bFlag0F)
    {

        if (bFlag10)
        {

            passes->FUN_00ba9ee0(geom, 0x1d0, true, 0, 0, 0, 0, 0);

            passes->data[passes->size - 1]->blend = 6;

            goto savedPass;
        }
        else
        {

            if (!rangeC)
                passes->FUN_00ba9ee0(geom, (skin ? 0x1ce : 0x1cc), true, 0, 0, 0, 0, 0);

            else
                passes->FUN_00ba9ee0(geom, (skin ? 0x1cf : 0x1cd), true, 0, 0, 0, 0, 0);

            passes->data[passes->size - 1]->blend = 6;

        savedPass:

            goto done21;
        }
    }

    if ((unk24 & 0x40) > 0)
    {

        passes->FUN_00ba9ee0(geom, 0x1d1 + (skin != false), true, 0, 0, 0, 0, 0);

        passes->data[passes->size - 1]->blend = 7;
    }

    P368Light* defaultLight = (P368Light*)((P368Context*)BSShaderManager_GetAccumulator())->camera->unkE0;

    passes->FUN_00ba9ee0(geom, 0, true, 0, 0, 0, 0, 0);

    P368Pass* p = passes->data[passes->size - 1];

    p->count = 1;

    P368Light* light = FUN_00b70590(&cursor);

    while (light)
    {
        if (!light->special)
            ++p->count;
        light = BSShaderLightingProperty_GetNextActiveLight(&cursor);
    }

    if (p->count > 0)
    {

        if (p->capacity < p->count)
        {
            p->BSShaderProperty_RenderPass_ClearSceneLights();
            p->AllocateElemArray(p->count);
            p->capacity = p->count;
        }

        light = FUN_00b70590(&cursor);
        p->lights[0] = defaultLight;

        unsigned char j = 1;

        while (light)
        {
            if (!light->special)
                p->lights[j++] = light;
            light = BSShaderLightingProperty_GetNextActiveLight(&cursor);
        }

        p->count = j;
    }
    else
        p->lights = 0;

    BSShaderProperty_SetFlag(0x1e, 0);

    if (FUN_004a2020(0x12))
    {

        if (rangeDLater)
        {
            if (scene)
                p->type = 0x1ae;
            else
                p->type = 0x190;
        }

        else
        {
            if (scene)
                p->type = 0x19f;
            else
                p->type = 0x181;
        }
    }
    else if (rangeDLater)
    {

        if (!skin)
        {

            if (bFlag0B)
            {

                if (rangeC)
                {

                    if (scene)
                    {
                        if (bFlag1C)
                            p->type = 0x1b8;
                        else
                            p->type = 0x1b7;
                    }

                    else
                    {
                        if (bFlag1C)
                            p->type = 0x19a;
                        else
                            p->type = 0x199;
                    }
                }
                else
                {

                    if (scene)
                    {
                        if (bFlag1C)
                            p->type = 0x1b0;
                        else
                            p->type = 0x1af;
                    }

                    else
                    {
                        if (bFlag1C)
                            p->type = 0x192;
                        else
                            p->type = 0x191;
                    }
                }
            }
            else if (bFlag0A)
            {
                if (scene)
                    p->type = 0x1b1;
                else
                    p->type = 0x193;
            }

            else if (textured)
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1b9;
                    else
                        p->type = 0x19b;
                }

                else
                {
                    if (scene)
                        p->type = 0x1b3;
                    else
                        p->type = 0x195;
                }
            }
            else
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1b5;
                    else
                        p->type = 0x197;
                }

                else
                {
                    if (scene)
                        p->type = 0x1ac;
                    else
                        p->type = 0x18e;
                }
            }
        }
        else if (!bFlag0B)
        {

            if (bFlag0A)
            {
                if (scene)
                    p->type = 0x1b2;
                else
                    p->type = 0x194;
            }

            else if (textured)
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1ba;
                    else
                        p->type = 0x19c;
                }

                else
                {
                    if (scene)
                        p->type = 0x1b4;
                    else
                        p->type = 0x196;
                }
            }
            else
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1b6;
                    else
                        p->type = 0x198;
                }

                else
                {
                    if (scene)
                        p->type = 0x1ad;
                    else
                        p->type = 0x18f;
                }
            }
        }
    }
    else
    {

        if (!skin)
        {

            if (bFlag0B)
            {

                if (rangeC)
                {

                    if (scene)
                    {
                        if (bFlag1C)
                            p->type = 0x1a9;
                        else
                            p->type = 0x1a8;
                    }

                    else
                    {
                        if (bFlag1C)
                            p->type = 0x18b;
                        else
                            p->type = 0x18a;
                    }
                }
                else
                {

                    if (scene)
                    {
                        if (bFlag1C)
                            p->type = 0x1a1;
                        else
                            p->type = 0x1a0;
                    }

                    else
                    {
                        if (bFlag1C)
                            p->type = 0x183;
                        else
                            p->type = 0x182;
                    }
                }
            }
            else if (bFlag0A)
            {
                if (scene)
                    p->type = 0x1a2;
                else
                    p->type = 0x184;
            }

            else if (textured)
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1aa;
                    else
                        p->type = 0x18c;
                }

                else
                {
                    if (scene)
                        p->type = 0x1a4;
                    else
                        p->type = 0x186;
                }
            }
            else
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1a6;
                    else
                        p->type = 0x188;
                }

                else
                {
                    if (scene)
                        p->type = 0x19d;
                    else
                        p->type = 0x17f;
                }
            }
        }
        else if (!bFlag0B)
        {

            if (bFlag0A)
            {
                if (scene)
                    p->type = 0x1a3;
                else
                    p->type = 0x185;
            }

            else if (textured)
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1ab;
                    else
                        p->type = 0x18d;
                }

                else
                {
                    if (scene)
                        p->type = 0x1a5;
                    else
                        p->type = 0x187;
                }
            }
            else
            {

                if (rangeC)
                {
                    if (scene)
                        p->type = 0x1a7;
                    else
                        p->type = 0x189;
                }

                else
                {
                    if (scene)
                        p->type = 0x19e;
                    else
                        p->type = 0x180;
                }
            }
        }
    }

    unsigned char blend = 14;

    if (FUN_004a2020(0x1a))
        p->blend = FUN_004a2020(0x35) ? 1 : 4;

    else if (FUN_004a2020(0x1b))
        p->blend = FUN_004a2020(0x35) ? 1 : 5;

    else if (skipDistanceLater)
        p->blend = fade < 1.0f ? 14 : 1;

    else if (context->unk34 == 2 || FUN_004a2020(0x22) || FUN_004a2020(0x21))
        p->blend = 10;

    if (BSShaderManager_GetShadows())
    {

        light = FUN_00b70590(&cursor);

        while (light)
        {

            if (light->special)
            {

                passes->FUN_00ba9ee0(geom, 0, false, 1, light, 0, 0, 0);

                p = passes->data[passes->size - 1];

                if (rangeC)
                    p->type = (P368Enum)(skin ? 0x1c7 : 0x1c5);

                else
                    p->type = (P368Enum)(skin ? 0x1c6 : 0x1c4);

                if (FUN_004a2020(0x1a))
                    p->blend = FUN_004a2020(0x35) ? 1 : 4;

                else if (FUN_004a2020(0x1b))
                    p->blend = FUN_004a2020(0x35) ? 1 : 5;
            }

            light = BSShaderLightingProperty_GetNextActiveLight(&cursor);
        }
    }

    if (extra && extra->unk6C)
    {

        passes->FUN_00ba9ee0(geom, (blend + (skin ? 1 : 0)), true, 0, 0, 0, 0, 0);

        passes->data[passes->size - 1]->blend = blend;
    }
    else if (FUN_004a2020(9) || fade < 1.0f)
    {

        if (!geom->m_PropertyState.m_aspProps[0] || !(static_cast<NiAlphaProperty*>(geom->m_PropertyState.m_aspProps[0])->m_usAlphaArg & 1))
        {

            if (rangeC)
                passes->FUN_00ba9ee0(geom, skin ? 0xd : 0xc, true, 0, 0, 0, 0, 0);

            else
                passes->FUN_00ba9ee0(geom, skin ? 0xb : 0xa, true, 0, 0, 0, 0, 0);

            p = passes->data[passes->size - 1];

            p->blend = FUN_004a2020(9) ? (unsigned char)1 : blend;

            if (fade < 1.0f || alpha < 1.0f)
                p->blend = blend;
        }
    }

    if (extra)
    {

        passes->FUN_00ba9ee0(geom, (0x1e0 + (skin ? 1 : 0)), true, 0, 0, 0, 0, 0);

        passes->data[passes->size - 1]->blend = 1;
    }

    if (extraPass)
    {

        P368Enum type;

        if (bFlag15)
            type = (P368Enum)(rangeC ? 0x1c0 : 0x1be);

        else if (!bFlag11)
        {

            if (skin)
                type = (P368Enum)(0x1c1 + (rangeC != false));

            else
                type = (P368Enum)(rangeC ? 0x1bf : 0x1bd);
        }

        if (!bFlag15 && bFlag11)
        {

            light = FUN_00b70590(&cursor);

            if (light)
            {
                passes->FUN_00ba9ee0(geom, 0, false, 1, light, 0, 0, 0);
                p = passes->data[passes->size - 1];
            }

            else
            {
                passes->FUN_00ba9ee0(geom, 0, false, 1, defaultLight, 0, 0, 0);
                p = passes->data[passes->size - 1];
            }

            p->type = 0x1c3;
        }
        else
        {

            passes->FUN_00ba9ee0(geom, 0, false, 0, 0, 0, 0, 0);

            p = passes->data[passes->size - 1];
            p->type = type;
        }

        if (skipDistanceLater)
            p->blend = 1;
    }

done21:

    key = requested;

return21:

    return passes;
}

extern int DAT_010b7f00;
extern HLOCAL(__stdcall* DAT_010b7f08)(HLOCAL);

namespace LocalHeapCleanup {

struct Buffer
{
    int m_vptr;
    int m_04;
    int unk08;
    int unk0c;
};

// @fnv 0x00ba11e0
extern "C" Buffer* __fastcall FUN_00ba11e0(Buffer* buffer, void*, unsigned char acFlags)
{
    int value = buffer->m_04;
    buffer->m_vptr = (int)&DAT_010b7f00;
    if (value != 0)
    {
        DAT_010b7f08((HLOCAL)value);
        buffer->m_04 = 0;
        buffer->unk0c = 0;
        buffer->unk08 = 0;
    }
    if (acFlags & 1)
    {
        g_memoryManager.Deallocate(buffer);
    }
    return buffer;
}

}

extern int DAT_010b9700;

namespace leaf_rework {

struct LeafLightingCall
{
    void FUN_00bb3660(void* texture);
};

struct LeafLightingBase
{
    LeafLightingBase(void* texture)
    {
        reinterpret_cast<LeafLightingCall*>(this)->FUN_00bb3660(texture);
    }
    ~LeafLightingBase();
};

struct FUN_00bb3ba0 : LeafLightingBase
{
    void* vtable;
    int unk04, unk08, unk0C, unk10, unk14, unk18;
    int shaderType;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54;
    int lightingType;
    int unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78;
    int unk7C, unk80, unk84;
    NiPointer<NiRefObject> leafData;
    unsigned short level;

    FUN_00bb3ba0(unsigned short value, void* texture, NiRefObject* data);
};

// Constructs the LeafLightingBase from texture, sets the vtable, stores data in leafData and value in level, and sets lightingType and shaderType to 6.
// @fnv 0x00bb3ba0
FUN_00bb3ba0::FUN_00bb3ba0(unsigned short value, void* texture, NiRefObject* data)
    : LeafLightingBase(texture), vtable(&DAT_010b9700), leafData()
{
    leafData = data;
    lightingType = 6;
    shaderType = 6;
    level = value;
}

}
