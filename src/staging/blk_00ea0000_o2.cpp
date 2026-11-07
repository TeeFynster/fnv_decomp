
// src/staging/blk_00ea0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiBoundingVolume.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}

__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}

inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../include/Pair.h"
#include "../../include/NiPoint3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3/CVec3; this unit's code depends on the stand-in's own overload set and inline bodies (its own NiPoint3/CVec3 bodies differ), so the shared class cannot replace it.
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
// LocalVector3: unit-local copy of the former shared stand-in Vector3. Same layout as NiPoint3 but with the stand-in's inline bodies (constructor, operator-, SquaredLength); with NiPoint3, DistanceSquaredToSegment (0x00eaf1f0) does not match.
class FloatMatrix3;

class LocalVector3
{
public:
    float x;
    float y;
    float z;

    LocalVector3()
    {
    }
    LocalVector3(float x, float y, float z) : x(x), y(y), z(z)
    {}
    LocalVector3(float x, int y, int z);

    LocalVector3 AddVector(const LocalVector3& other) const;
    LocalVector3 ScaleSwizzled(float scale) const;
    LocalVector3 operator*(double multiplier) const;
    LocalVector3 operator*(float multiplier) const;
    LocalVector3 operator+(const LocalVector3& right) const;
    LocalVector3 operator-(const LocalVector3& right) const
    {
        return LocalVector3(x - right.x, y - right.y, z - right.z);
    }
    LocalVector3& operator-=(const LocalVector3& right);
    LocalVector3& operator+=(const LocalVector3& right);
    float& operator[](int index);
    float Dot(const LocalVector3& right) const;
    float SquaredLength() const
    {
        return x * x + y * y + z * z;
    }
    void Normalize();
    float Length() const;

    LocalVector3 Diff_00b13040(const LocalVector3& other) const;
    LocalVector3 FUN_00b12890(const FloatMatrix3& matrix) const;
    LocalVector3 FUN_00b12810(const LocalVector3& other) const;
    void Normalize_00b12790();
    void __thiscall SubtractIntoVector(LocalVector3* dest, void* context);
    void __thiscall Unitize_004a0c10();
// src: GUESS 0x00439ef0 (confidence: high)
    LocalVector3 SubtractIntoVector(const LocalVector3& other) const
    {
        return LocalVector3(x - other.x, y - other.y, z - other.z);
    }
    float FUN_004a7290() const
    {
        return x * x + y * y + z * z;
    }
};
#include <math.h>
#include <string.h>

// Preserve the arithmetic implementations used by this unit with the shared types.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& pt) const
{
    return NiPoint3(pt.x + x, pt.y + y, pt.z + z);
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    NiPoint3 kResult;
    kResult.x = x - pt.x;
    kResult.y = y - pt.y;
    kResult.z = z - pt.z;
    return kResult;
}
inline NiPoint3 NiPoint3::Sub(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}
inline NiPoint3 NiPoint3::CrossProduct(const NiPoint3& pt) const
{
    return NiPoint3(y * pt.z - pt.y * z, z * pt.x - x * pt.z, x * pt.y - pt.x * y);
}
inline float NiPoint3::operator*(const NiPoint3& pt) const
{
    return x * pt.x + y * pt.y + z * pt.z;
}
inline float NiPoint3::DotProduct(const NiPoint3& pt)
{
    float fDot = x * pt.x + y * pt.y + z * pt.z;
    return fDot;
}
inline float NiPoint3::DotProduct(const NiPoint3& pt) const
{
    float fDot = x * pt.x + y * pt.y + z * pt.z;
    return fDot;
}
inline float NiPoint3::SqrLength() const
{
    return x * x + y * y + z * z;
}
inline float NiPoint3::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}
inline NiPoint3 NiPoint3::Cross(const NiPoint3& pt) const
{
    return NiPoint3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}
inline LocalVector3& LocalVector3::operator-=(const LocalVector3& r)
{
    x -= r.x;
    y -= r.y;
    z -= r.z;
    return *this;
}
inline LocalVector3 LocalVector3::operator*(float s) const
{
    return LocalVector3(x * s, y * s, z * s);
}
inline float LocalVector3::Dot(const LocalVector3& r) const
{
    return x * r.x + y * r.y + z * r.z;
}
inline float& NiPoint3::operator[](int i)
{
    return components[i];
}
inline const float& NiPoint3::operator[](int i) const
{
    return components[i];
}
inline LocalVec3::LocalVec3()
{}
inline Pair::Pair() throw()
{}

static inline NiPoint3 AddPointCoordinates(const NiPoint3& a, const NiPoint3& b)
{
    // Preserve the original operand loads using the vector view without a union.
    const LocalVector3& left = reinterpret_cast<const LocalVector3&>(a);
    const LocalVector3& right = reinterpret_cast<const LocalVector3&>(b);
    return NiPoint3(left.x + right.x, left.y + right.y, left.z + right.z);
}
static inline NiPoint3 AddTriangleVertices(const NiPoint3& a, const NiPoint3& b)
{
    NiPoint3 r;
    r.x = a.x;
    r.x += b.x;
    r.y = a.y;
    r.y += b.y;
    r.z = a.z;
    r.z += b.z;
    return r;
}

struct FUN_00eae690_Class
{
    char pad[0x18];
    float m_f;
    char Object_HasEqualSixFloats(const FUN_00eae690_Class& o);
    int IsEquivalentWithEqualFloat(const FUN_00eae690_Class& o);
};

// Returns 1 when FUN_00eb60e0(o) succeeds and m_f equals o.m_f, otherwise 0.
// @fnv 0x00eae690
// src: GUESS 0x00eae690 (confidence: medium)
int FUN_00eae690_Class::IsEquivalentWithEqualFloat(const FUN_00eae690_Class& aOther)
{
    if (Object_HasEqualSixFloats(aOther) && !(m_f != aOther.m_f))
        return 1;
    return 0;
}

struct FUN_00eb60e0_t
{
    float a[6];
};

// Compares the six floats of p and q and returns 1 if all are equal, otherwise 0.
// @fnv 0x00eb60e0
// src: GUESS 0x00eb60e0 (confidence: high)
int __fastcall Object_HasEqualSixFloats(FUN_00eb60e0_t* p, int, FUN_00eb60e0_t* q)
{
    if (!(p->a[0] != q->a[0] || p->a[1] != q->a[1] || p->a[2] != q->a[2] || p->a[3] != q->a[3] || p->a[4] != q->a[4] ||
          p->a[5] != q->a[5]))
        return 1;
    return 0;
}

extern MemoryManager _g_memoryManager;
struct Isect
{
    void SetVtbl();
    Isect* FUN_00eaee30(char);
};
// Calls FUN_00eae6d0, then deallocates this via _g_memoryManager if flag has bit 1 set, and returns this.
// @fnv 0x00eaee30
Isect* Isect::FUN_00eaee30(char flag)
{
    SetVtbl();
    if (flag & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

struct S_00eae9e0_P1
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
    float unk38;
};

struct S_00eae9e0_P2
{
    int unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
};

extern char DAT_010f1aa0;
extern float DAT_010f1a98;

struct FUN_00eae9e0_cls
{
    void* unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    int unk14;
    int unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    S_00eae9e0_P1* unk38;
    S_00eae9e0_P2* unk3c;
    float unk40;
    float unk44;

    void FUN_00eae720(float a1, float a2, float a3, int a4);
    FUN_00eae9e0_cls* InitFromParams(S_00eae9e0_P1* a1, S_00eae9e0_P2* a2, float a3, float a4, float a5, int a6);
};

// @fnv 0x00eae9e0
FUN_00eae9e0_cls* FUN_00eae9e0_cls::InitFromParams(S_00eae9e0_P1* a1, S_00eae9e0_P2* a2, float a3, float a4, float a5,
                                                   int a6)
{
    FUN_00eae720(a3, a4, a5, a6);
    unk38 = a1;
    unk00 = (void*)&DAT_010f1aa0;
    unk3c = a2;
    float s = a1->unk38 + a2->unk10;
    unk40 = 1.0f / (s * s);
    unk44 = DAT_010f1a98;
    return this;
}

struct FNVVectorParameter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float extent10;
};
extern "C" int FUN_00eb3c40_VTable;
extern "C" float FUN_00eb3c40_Default;
struct FNVRegion
{
    void* vtable;
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
    void* owner38;
    FNVVectorParameter* bounds3c;
    float inverseSquare40;
    float axis44;
    float axis48;
    float axis4c;
    void FUN_00eae720(float x, float y, float z, void* userdata);
    FNVRegion* InitRegion(void* owner, FNVVectorParameter* bounds, float x, float y, float z, void* userdata);
};
// @fnv 0x00eb3c40
FNVRegion* FNVRegion::InitRegion(void* owner, FNVVectorParameter* bounds, float x, float y, float z, void* userdata)
{
    FUN_00eae720(x, y, z, userdata);
    bounds3c = bounds;
    vtable = &FUN_00eb3c40_VTable;
    owner38 = owner;
    inverseSquare40 = 1.0f / (bounds->extent10 * bounds->extent10);
    FNVRegion* __restrict p = this;
    p->axis44 = FUN_00eb3c40_Default;
    p->axis48 = FUN_00eb3c40_Default;
    p->axis4c = FUN_00eb3c40_Default;
    return this;
}

struct BoxVec3
{
    float x;
    float y;
    float z;
};

struct OrientedBox
{
    BoxVec3 center;
    BoxVec3 axis0;
    BoxVec3 axis1;
    BoxVec3 axis2;
    float extent0;
    float extent1;
    float extent2;
};

// @fnv 0x00eb42e0
float __cdecl GetSqrDistanceToOrientedBox(const BoxVec3* point, const OrientedBox* box, float* outT0, float* outT1,
                                          float* outT2)
{
    float sqrDist = 0.0f;
    BoxVec3 vDiff;
    vDiff.x = point->x - box->center.x;
    vDiff.y = point->y - box->center.y;
    vDiff.z = point->z - box->center.z;

    float delta;
    BoxVec3 vClosest;
    vClosest.x = vDiff.x * box->axis0.x + vDiff.y * box->axis0.y + vDiff.z * box->axis0.z;
    if (vClosest.x < -box->extent0)
    {
        delta = vClosest.x + box->extent0;
        sqrDist += delta * delta;
        vClosest.x = -box->extent0;
    }
    else if (vClosest.x > box->extent0)
    {
        delta = vClosest.x - box->extent0;
        sqrDist += delta * delta;
        vClosest.x = box->extent0;
    }

    vClosest.y = vDiff.x * box->axis1.x + vDiff.y * box->axis1.y + vDiff.z * box->axis1.z;
    if (vClosest.y < -box->extent1)
    {
        delta = vClosest.y + box->extent1;
        sqrDist += delta * delta;
        vClosest.y = -box->extent1;
    }
    else if (vClosest.y > box->extent1)
    {
        delta = vClosest.y - box->extent1;
        sqrDist += delta * delta;
        vClosest.y = box->extent1;
    }

    vClosest.z = vDiff.x * box->axis2.x + vDiff.y * box->axis2.y + vDiff.z * box->axis2.z;
    if (vClosest.z < -box->extent2)
    {
        delta = vClosest.z + box->extent2;
        sqrDist += delta * delta;
        vClosest.z = -box->extent2;
    }
    else if (vClosest.z > box->extent2)
    {
        delta = vClosest.z - box->extent2;
        sqrDist += delta * delta;
        vClosest.z = box->extent2;
    }

    *outT0 = vClosest.x;
    *outT1 = vClosest.y;
    *outT2 = vClosest.z;
    return sqrDist;
}

struct S_00eb5e30_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
};
struct S_00eb5e30_Base
{
    virtual void v00();
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
    S_00eb5e30_Base(float a, float b, float c, int d);
};
struct FUN_00eb5e30 : S_00eb5e30_Base
{
    S_00eb5e30_Obj* unk38;
    NiPoint3 unk3c;
    NiPoint3 unk48;
    NiPoint3 unk54;
    float unk60;
    float unk64;
    float unk68;
    FUN_00eb5e30(S_00eb5e30_Obj* o, const NiPoint3* p0, const NiPoint3* p1, const NiPoint3* p2, float a,
                 float b, float c, int d);
};
static float DAT_010f1b24 = 3.4028234663852886e+38f;
// @fnv 0x00eb5e30
FUN_00eb5e30::FUN_00eb5e30(S_00eb5e30_Obj* pObj, const NiPoint3* pOrigin, const NiPoint3* pPoint1,
                           const NiPoint3* pPoint2, float a, float b, float c, int d)
    : S_00eb5e30_Base(a, b, c, d)
{
    unk38 = pObj;
    unk3c = *pOrigin;
    NiPoint3 vEdge1;
    vEdge1.x = pPoint1->x - pOrigin->x;
    vEdge1.y = pPoint1->y - pOrigin->y;
    vEdge1.z = pPoint1->z - pOrigin->z;
    unk48 = vEdge1;
    NiPoint3 vEdge2;
    vEdge2.x = pPoint2->x - pOrigin->x;
    vEdge2.y = pPoint2->y - pOrigin->y;
    vEdge2.z = pPoint2->z - pOrigin->z;
    unk54 = vEdge2;
    unk60 = 1.0f / (pObj->unk10 * pObj->unk10);
    unk68 = unk64 = DAT_010f1b24;
}

struct FUN_00aa4060_Class
{
    void* __thiscall MemoryManager_Deallocate(void* object);
};

extern FUN_00aa4060_Class DAT_011f6238;

struct FUN_00eb6b50_Class
{
    void __thiscall FUN_00eb8ab0();
    int __thiscall FUN_00eb6b50(unsigned char flags);
};

// Calls FUN_00eb8ab0, and if bit 0 of flags is set passes this to DAT_011f6238.FUN_00aa4060; returns this as int.
// @fnv 0x00eb6b50
int __thiscall FUN_00eb6b50_Class::FUN_00eb6b50(unsigned char flags)
{
    this->FUN_00eb8ab0();
    if ((flags & 1) != 0)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return reinterpret_cast<int>(this);
}

class EB8AB0Object
{
  public:
    virtual ~EB8AB0Object();
};

class FUN_00eb8ab0
{
  public:
    virtual ~FUN_00eb8ab0();

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
    EB8AB0Object* m_pkPrimary;
    EB8AB0Object* m_pkSecondary;
};

// Destructor that deletes m_pkPrimary and, if it was non-null, also deletes m_pkSecondary.
// @fnv 0x00eb8ab0
FUN_00eb8ab0::~FUN_00eb8ab0()
{
    if (m_pkPrimary)
    {
        delete m_pkPrimary;
        delete m_pkSecondary;
    }
}

// 0x00eae520 uses center +0x00, axes +0x0C and three extents +0x30; shared Transform starts with rotation and has one scale.
class OrientedBoxBounds
{
  public:
    NiPoint3 m_kCenter;
    float m_afAxes[3][3];
    float m_afExtents[3];

    bool HasEqualBoxComponents(const OrientedBoxBounds& kOther) const;
};

// Compares center, axes and extents against kOther and returns true only if all components match.
// @fnv 0x00eae520
// src: GUESS 0x00eae520 (confidence: medium)
bool OrientedBoxBounds::HasEqualBoxComponents(const OrientedBoxBounds& kOther) const
{
    if (!(kOther.m_kCenter == m_kCenter))
        return false;

    for (int i = 0; i < 3; i++)
    {
        const float* pfOtherRow = kOther.m_afAxes[i];
        const float* pfRow = m_afAxes[i];
        if (pfRow[0] != pfOtherRow[0] || pfRow[1] != pfOtherRow[1] || pfRow[2] != pfOtherRow[2] ||
            m_afExtents[i] != kOther.m_afExtents[i])
            return false;
    }
    return true;
}

namespace fnv_00eae6d0 {
// FUN_00eae6d0 (7 bytes):  mov dword ptr [ecx], 0x010f1a84 ; ret
//
// The game's `Isect` class (RTTI name .?AVNiIntersector@@) keeps its vtable
// pointer as an ordinary first member at offset +0x00 instead of a real vptr,
// and FUN_00eae6d0 simply points that member at the class' vftable
// (0x010f1a84 - the NiIntersector vftable whose slot 0 is the destructor
//  0x00eae770, which resets the very same pointer again).
//
// 0x010f1a84 has no symbol in the checker's symbol database, so declaring it as
// an undefined extern makes the store a plain DIR32 relocation with addend 0;
// the checker then binds it to 0x010f1a84 from the original's own bytes.

extern int DAT_010f1a84;

struct Isect
{
    int* m_pVtbl;         // +0x00 : the object's vtable pointer
    void SetVtbl();  // reset the object's vtable pointer
};

// @fnv 0x00eae6d0
// src: GUESS 0x00eae6d0 (confidence: low)
void Isect::SetVtbl()
{
    m_pVtbl = &DAT_010f1a84;
}
}  // namespace fnv_00eae6d0

struct Segment3
{
    LocalVector3 Origin;
    LocalVector3 Direction;
};

// Projects a point onto a segment, clamps the parameter to [0,1] in pfT, and returns the squared distance from the point to the closest segment point.
// @fnv 0x00eaf1f0
float __cdecl DistanceSquaredToSegment(const LocalVector3& rkPoint, const Segment3& rkSegment, float* pfT)
{
    LocalVector3 kDiff = rkPoint - rkSegment.Origin;
    *pfT = rkSegment.Direction.Dot(kDiff);
    if (*pfT <= 0.0f)
    {
        *pfT = 0.0f;
    }
    else
    {
        float fA00 = rkSegment.Direction.SquaredLength();
        if (*pfT >= fA00)
        {
            *pfT = 1.0f;
            kDiff -= rkSegment.Direction;
        }
        else
        {
            *pfT /= fA00;
            kDiff -= rkSegment.Direction * (*pfT);
        }
    }
    return kDiff.SquaredLength();
}

namespace fnv_00eb3230 {
static __forceinline void assignVec(LocalVec3& target, const LocalVec3& source)
{
    memcpy(&target, &source, sizeof(LocalVec3));
}

static __forceinline LocalVec3 sumVec(const LocalVec3& a, const LocalVec3& b)
{
    LocalVec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}
static __forceinline LocalVec3 diffVec(const LocalVec3& a, const LocalVec3& b)
{
    LocalVec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
static __forceinline LocalVec3 sumVecB(const LocalVec3& a, const LocalVec3& b)
{
    LocalVec3 r;
    const volatile float& first = a.x;
    r.x = first + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}
struct Triangle3
{
    LocalVec3 origin, edge0, edge1;
};
struct Segment3
{
    LocalVec3 origin, direction;
};
extern float __cdecl NiSqrDistance_Compute_00eaff20(const Segment3*, const Triangle3*, float*, float*, float*);
extern float __cdecl NiSqrDistance_Compute_00eb1d20(const Segment3*, const Triangle3*, float*, float*, float*);
// @fnv 0x00eb3230
float __cdecl TriangleTriangleDistance(const Triangle3* aTriA, const Triangle3* aTriB, float* aU, float* aV, float* bU,
                                       float* bV)
{
    Segment3 segEdge;
    assignVec(segEdge.origin, aTriA->origin);
    assignVec(segEdge.direction, aTriA->edge0);
    float fBestDist = NiSqrDistance_Compute_00eaff20(&segEdge, aTriB, aU, bU, bV);
    *aV = 0.0f;

    float av, au;
    // Barycentric coordinates use the two Pair slots as float storage.
    Pair baryB;
    assignVec(segEdge.direction, aTriA->edge1);
    float candidate = NiSqrDistance_Compute_00eaff20(&segEdge, aTriB, &av, &reinterpret_cast<float&>(baryB.b), &reinterpret_cast<float&>(baryB.a));
    au = 0.0f;
    if (candidate < fBestDist)
    {
        fBestDist = candidate;
        *aU = au;
        *aV = av;
        *bU = reinterpret_cast<float&>(baryB.b);
        *bV = reinterpret_cast<float&>(baryB.a);
    }
    assignVec(segEdge.origin, sumVec(aTriA->edge0, segEdge.origin));
    assignVec(segEdge.direction, diffVec(segEdge.direction, aTriA->edge0));
    candidate = NiSqrDistance_Compute_00eaff20(&segEdge, aTriB, &av, &reinterpret_cast<float&>(baryB.b), &reinterpret_cast<float&>(baryB.a));
    au = 1.0f - av;
    if (candidate < fBestDist)
    {
        fBestDist = candidate;
        *aU = au;
        *aV = av;
        *bU = reinterpret_cast<float&>(baryB.b);
        *bV = reinterpret_cast<float&>(baryB.a);
    }

    assignVec(segEdge.origin, aTriB->origin);
    assignVec(segEdge.direction, aTriB->edge0);
    candidate = NiSqrDistance_Compute_00eb1d20(&segEdge, aTriA, &reinterpret_cast<float&>(baryB.b), &au, &av);
    reinterpret_cast<float&>(baryB.a) = 0.0f;
    if (candidate < fBestDist)
    {
        fBestDist = candidate;
        *aU = au;
        *aV = av;
        *bU = reinterpret_cast<float&>(baryB.b);
        *bV = reinterpret_cast<float&>(baryB.a);
    }
    assignVec(segEdge.direction, aTriB->edge1);
    candidate = NiSqrDistance_Compute_00eb1d20(&segEdge, aTriA, &reinterpret_cast<float&>(baryB.a), &au, &av);
    reinterpret_cast<float&>(baryB.b) = 0.0f;
    if (candidate < fBestDist)
    {
        fBestDist = candidate;
        *aU = au;
        *aV = av;
        *bU = reinterpret_cast<float&>(baryB.b);
        *bV = reinterpret_cast<float&>(baryB.a);
    }
    assignVec(segEdge.origin, sumVecB(aTriB->edge1, aTriB->origin));
    assignVec(segEdge.direction, aTriB->edge0);
    candidate = NiSqrDistance_Compute_00eb1d20(&segEdge, aTriA, &reinterpret_cast<float&>(baryB.b), &au, &av);
    reinterpret_cast<float&>(baryB.a) = 1.0f;
    if (candidate < fBestDist)
    {
        fBestDist = candidate;
        *aU = au;
        *aV = av;
        *bU = reinterpret_cast<float&>(baryB.b);
        *bV = reinterpret_cast<float&>(baryB.a);
    }
    assignVec(segEdge.origin, sumVec(aTriB->origin, aTriB->edge0));
    assignVec(segEdge.direction, aTriB->edge1);
    candidate = NiSqrDistance_Compute_00eb1d20(&segEdge, aTriA, &reinterpret_cast<float&>(baryB.a), &au, &av);
    if (candidate < fBestDist)
    {
        fBestDist = candidate;
        *aU = au;
        *aV = av;
        *bU = 1.0f;
        *bV = reinterpret_cast<float&>(baryB.a);
    }
    return fBestDist;
}
}  // namespace fnv_00eb3230

struct FUN_00eb5f10_Tail
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
    void FUN_00a86bf0();
};
struct FUN_00eb5f10_Small
{
    FUN_00eb5f10_Small* FUN_00eb6b90(void*, int, int, int, int);
};
struct FUN_00eb5f10_Large
{
    void* FUN_00eba1b0(void*, unsigned short, int, int, int, int);
};
struct FUN_00eb5f10_Manager
{
    void* Game_DoHeapAlloc(unsigned int);
};
extern int _DAT_011f426c;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
extern char UNK_010f1b44;
struct FUN_00eb5f10_Class
{
    void** vtable;
    float unk04;
    void* unk08;
    unsigned char unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00eb5f10_Tail unk1c;
    int unk50;
    FUN_00eb5f10_Class* InitFromKind(unsigned short kind, int arg2, int arg3, int arg4, int arg5);
};
// Allocates an object sized by kind, stores it in unk08, initialises unk04/unk10/unk14/unk18/unk0c/unk50 and calls unk1c.FUN_00a86bf0.
// @fnv 0x00eb5f10
FUN_00eb5f10_Class* FUN_00eb5f10_Class::InitFromKind(unsigned short kind, int arg2, int arg3, int arg4, int arg5)
{
    vtable = (void**)&UNK_010f1b44;
    FUN_00eb5f10_Manager* manager = (FUN_00eb5f10_Manager*)&_g_memoryManager;
    void* object;
    if (kind > 1)
    {
        object = manager->Game_DoHeapAlloc(0x8c);
        object = object ? ((FUN_00eb5f10_Large*)object)->FUN_00eba1b0(this, kind, arg2, arg3, arg4, arg5) : 0;
    }
    else
    {
        object = manager->Game_DoHeapAlloc(0x98);
        object = object ? ((FUN_00eb5f10_Small*)object)->FUN_00eb6b90(this, arg2, arg3, arg4, 0) : 0;
    }
    unk08 = object;
    unk04 = 0.0f;
    unk10 = _DAT_011f426c;
    unk14 = _DAT_011f4270;
    unk18 = _DAT_011f4274;
    unk1c.FUN_00a86bf0();
    unk0c = 0;
    unk50 = 0;
    return this;
}

struct SphereBound
{
    LocalVector3 center;
    float radius;
};
extern SphereBound DAT_011f4288;
struct BoundedObject
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    SphereBound* bound;
};
inline float my_dot(const LocalVector3& a, const LocalVector3& b)
{
    double x = a.x * b.x;
    return (float)(x + a.y * b.y + a.z * b.z);
}
// Tests whether a ray from origin along direction hits the object's sphere bound, returning true if the origin is inside or the ray intersects it.
// @fnv 0x00eada70
bool RayIntersectsBound(BoundedObject* object, const LocalVector3& origin, const LocalVector3& direction)
{
    SphereBound bound = object->bound ? *object->bound : DAT_011f4288;
    LocalVector3 delta = origin - bound.center;
    float deltaSquared = delta.SquaredLength();
    float distance = deltaSquared - bound.radius * bound.radius;
    if (distance <= 0.0f)
        return true;
    float projection = my_dot(direction, delta);
    if (projection >= 0.0f)
        return false;
    float directionSquared = direction.x * direction.x + direction.y * direction.y + direction.z * direction.z;
    return projection * projection >= distance * directionSquared;
}

namespace sead090 {

class Node
{
  public:
    static void* operator new(unsigned int uiSize);

    Node() throw();

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
    int unk4c;
};

// Allocates a new Node object on the heap and returns its pointer.
// @fnv 0x00ead090
// src: GUESS 0x00ead090 (confidence: high)
Node* Runtime_CreateNode()
{
    return new Node;
}

}

extern int DAT_010f1abc;
static const float DAT_010f1ab4 = 3.402823466e+38f;

extern "C" void __stdcall FUN_00eae720(float a3, float a4, float a5, int a6);

struct S_00eaedc0_Class
{
    void* m_00;
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
    int m_38;
    int m_3c;
    float m_40;
    float m_44;
    float m_48;

    S_00eaedc0_Class* Initialize(int a1, int a2, float a3, float a4, float a5, int a6);
};

// Sets m_38 and m_3c from a1/a2, computes m_40 as the inverse squared sum of their 0x38 fields, and initializes m_44/m_48 to FLT_MAX.
// @fnv 0x00eaedc0
S_00eaedc0_Class* S_00eaedc0_Class::Initialize(int a1, int a2, float a3, float a4, float a5, int a6)
{
    FUN_00eae720(a3, a4, a5, a6);
    m_38 = a1;
    m_00 = (void*)&DAT_010f1abc;
    m_3c = a2;

    float s = *reinterpret_cast<float*>(m_38 + 0x38) + *reinterpret_cast<float*>(m_3c + 0x38);
    m_40 = 1.0f / (s * s);

    float c = DAT_010f1ab4;
    m_44 = c;
    m_48 = c;
    return this;
}

class OriginDirectionPair
{
  public:
    NiPoint3& Origin()
    {
        return m_kStartPoint;
    }
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kLightVector;
};
struct TrianglePointSet
{
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kPoint1;
    NiPoint3 m_kPoint2;
};
float __cdecl NiSqrDistance_Compute(const OriginDirectionPair& kSeg0, const OriginDirectionPair& kSeg1, float& fSeg0Param,
                           float& fSeg1Param);
float __cdecl NiSqrDistance_Compute_00eb6150(const NiPoint3& kPnt, const TrianglePointSet& kPgm, float& fPgmParam0, float& fPgmParam1);
// @fnv 0x00eaff20
// src: GAMEBRYO_LIB 0x00eaff20
float __cdecl NiSqrDistance_Compute_00eaff20(const OriginDirectionPair& kSeg, const TrianglePointSet& kPgm, float& fR, float& fS,
                           float& fT)
{
    NiPoint3 kNormal = kPgm.m_kPoint1.Cross(kPgm.m_kPoint2);
    double dDirY = kSeg.m_kLightVector.y;
    double dDirX = kSeg.m_kLightVector.x;
    double dDirZ = kSeg.m_kLightVector.z;
    float fNormalLength = sqrtf(kNormal.x * kNormal.x + kNormal.y * kNormal.y + kNormal.z * kNormal.z);
    float fThreshold =
        (float)(sqrtf((float)(dDirX * dDirX + dDirY * dDirY + dDirZ * dDirZ)) * fNormalLength * (double)1e-05f);
    OriginDirectionPair kSegPgm;
    NiPoint3 kPnt;
    float fSqrDist, fSqrDist0, fR0, fS0, fT0;
    if ((float)fabs(kNormal.Dot(kSeg.m_kLightVector)) > fThreshold)
    {
        NiPoint3 kDiff = kPgm.m_kStartPoint - kSeg.m_kStartPoint;
        float fA00 = kSeg.m_kLightVector.Dot(kSeg.m_kLightVector);
        float fA01 = -kSeg.m_kLightVector.Dot(kPgm.m_kPoint1);
        float fA02 = -kSeg.m_kLightVector.Dot(kPgm.m_kPoint2);
        float fA11 = kPgm.m_kPoint1.Dot(kPgm.m_kPoint1);
        float fA12 = kPgm.m_kPoint1.Dot(kPgm.m_kPoint2);
        float fA22 = kPgm.m_kPoint2.Dot(kPgm.m_kPoint2);
        float fB0 = -kDiff.Dot(kSeg.m_kLightVector);
        float fB1 = kDiff.Dot(kPgm.m_kPoint1);
        float fB2 = kDiff.Dot(kPgm.m_kPoint2);
        float fCof00 = fA11 * fA22 - fA12 * fA12;
        float fCof01 = fA02 * fA12 - fA01 * fA22;
        float fCof02 = fA01 * fA12 - fA02 * fA11;
        float fDet = fA00 * fCof00 + fA01 * fCof01 + fA02 * fCof02;
        if ((float)fabs(fDet) >= 1e-05f)
        {
            float fCof11 = fA00 * fA22 - fA02 * fA02;
            float fCof12 = fA02 * fA01 - fA00 * fA12;
            float fCof22 = fA00 * fA11 - fA01 * fA01;
            float fInvDet = 1.0f / fDet;
            float fRhs0 = -fB0 * fInvDet;
            float fRhs1 = -fB1 * fInvDet;
            float fRhs2 = -fB2 * fInvDet;
            fR = fCof00 * fRhs0 + fCof01 * fRhs1 + fCof02 * fRhs2;
            fS = fCof01 * fRhs0 + fCof11 * fRhs1 + fCof12 * fRhs2;
            fT = fCof02 * fRhs0 + fCof12 * fRhs1 + fCof22 * fRhs2;
            if (fR < 0.0f)
            {
                if (fS < 0.0f)
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
                else if (fS <= 1.0f)
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fS);
                        fT = 0.0f;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        fSqrDist = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS, fT);
                        fR = 0.0f;
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fS);
                        fT = 1.0f;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
                else
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
            }
            else if (fR <= 1.0f)
            {
                if (fS < 0.0f)
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
                else if (fS <= 1.0f)
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fS);
                        fT = 0.0f;
                    }
                    else if (fT <= 1.0f)
                    {
                        // global minimum is interior
                        fSqrDist = fR * (fA00 * fR + fA01 * fS + fA02 * fT + 2.0 * fB0) +
                                   fS * (fA01 * fR + fA11 * fS + fA12 * fT + 2.0 * fB1) +
                                   fT * (fA02 * fR + fA12 * fS + fA22 * fT + 2.0 * fB2) + kDiff.Dot(kDiff);
                        fSqrDist = (float)fabs(fSqrDist);
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fS);
                        fT = 1.0f;
                    }
                }
                else
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
            }
            else
            {
                if (fS < 0.0f)
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 0.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
                else if (fS <= 1.0f)
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fS);
                        fT = 0.0f;
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS, fT);
                        fR = 1.0f;
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fS);
                        fT = 1.0f;
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
                else
                {
                    if (fT < 0.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else if (fT <= 1.0f)
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else
                    {
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fT);
                        fS = 1.0f;
                        kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
                        kSegPgm.m_kLightVector = kPgm.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
                        fT0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        kPnt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
            }
            return fSqrDist;
        }
    }
    // segment and parallelogram are parallel
    kSegPgm.Origin() = kPgm.m_kStartPoint;
    kSegPgm.m_kLightVector = kPgm.m_kPoint1;
    fSqrDist = NiSqrDistance_Compute(kSeg, kSegPgm, fR, fS);
    fT = 0.0f;
    kSegPgm.m_kLightVector = kPgm.m_kPoint2;
    fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fT0);
    fS0 = 0.0f;
    if (fSqrDist0 < fSqrDist)
    {
        fSqrDist = fSqrDist0;
        fR = fR0;
        fS = fS0;
        fT = fT0;
    }
    kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint2;
    kSegPgm.m_kLightVector = kPgm.m_kPoint1;
    fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fS0);
    fT0 = 1.0f;
    if (fSqrDist0 < fSqrDist)
    {
        fSqrDist = fSqrDist0;
        fR = fR0;
        fS = fS0;
        fT = fT0;
    }
    kSegPgm.Origin() = kPgm.m_kStartPoint + kPgm.m_kPoint1;
    kSegPgm.m_kLightVector = kPgm.m_kPoint2;
    fSqrDist0 = NiSqrDistance_Compute(kSeg, kSegPgm, fR0, fT0);
    fS0 = 1.0f;
    if (fSqrDist0 < fSqrDist)
    {
        fSqrDist = fSqrDist0;
        fR = fR0;
        fS = fS0;
        fT = fT0;
    }
    fSqrDist0 = NiSqrDistance_Compute_00eb6150(kSeg.m_kStartPoint, kPgm, fS0, fT0);
    fR0 = 0.0f;
    if (fSqrDist0 < fSqrDist)
    {
        fSqrDist = fSqrDist0;
        fR = fR0;
        fS = fS0;
        fT = fT0;
    }
    kPnt = AddPointCoordinates(kSeg.m_kStartPoint, kSeg.m_kLightVector);
    fSqrDist0 = NiSqrDistance_Compute_00eb6150(kPnt, kPgm, fS0, fT0);
    fR0 = 1.0f;
    if (fSqrDist0 < fSqrDist)
    {
        fSqrDist = fSqrDist0;
        fR = fR0;
        fS = fS0;
        fT = fT0;
    }
    return fSqrDist;
}

namespace fnv_00eb1d20 {
// FUN_00eb1d20: squared distance between a segment and a triangle (Eberly's
// Segment3/Triangle3 SqrDistance), returning the segment and triangle params.

struct OriginDirectionPair
{
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kLightVector;
};

struct Triangle3D
{
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kPoint1;
    NiPoint3 m_kPoint2;
};

extern double DAT_0101dae8;
float NiSqrDistance_Compute(const OriginDirectionPair& kSeg0, const OriginDirectionPair& kSeg1, float& fSeg0Param,
                   float& fSeg1Param);
float GetSquaredDistanceToTriangle(const NiPoint3& kPnt, const Triangle3D& kTri, float& fTriParam0, float& fTriParam1);

// Returns the squared distance between segment kSeg and triangle kTri, writing segment parameter fR and triangle parameters fS and fT at the closest points.
// @fnv 0x00eb1d20
// src: GAMEBRYO_LIB 0x00eb1d20
float NiSqrDistance_Compute_00eb1d20(const OriginDirectionPair& kSeg, const Triangle3D& kTri, float& fR, float& fS, float& fT)
{
    NiPoint3 kDiff = kTri.m_kStartPoint.Sub(kSeg.m_kStartPoint);
    float fA00 = kSeg.m_kLightVector * kSeg.m_kLightVector;
    float fA01 = -(kSeg.m_kLightVector * kTri.m_kPoint1);
    float fA02 = -(kSeg.m_kLightVector * kTri.m_kPoint2);
    float fA11 = kTri.m_kPoint1 * kTri.m_kPoint1;
    float fA12 = kTri.m_kPoint1 * kTri.m_kPoint2;
    float fA22 = kTri.m_kPoint2 * kTri.m_kPoint2;
    float fB0 = -(kDiff * kSeg.m_kLightVector);
    float fB1 = kDiff * kTri.m_kPoint1;
    float fB2 = kDiff * kTri.m_kPoint2;

    OriginDirectionPair kTriSeg;
    NiPoint3 kPt;
    float fSqrDist, fSqrDist0, fR0, fS0, fT0;

    NiPoint3 kN(kTri.m_kPoint1.CrossProduct(kTri.m_kPoint2));
    double dY = kSeg.m_kLightVector.y;
    double dX = kSeg.m_kLightVector.x;
    double dZ = kSeg.m_kLightVector.z;
    float fDot = fabsf(kN * kSeg.m_kLightVector);
    float fNLen = static_cast<const NiPoint3&>(kN).Length();
    float fDLen = sqrtf((float)(dX * dX + dY * dY + dZ * dZ));
    float fTol = (float)(fDLen * fNLen * DAT_0101dae8);

    if (fDot > fTol)
    {

        float fCof00 = fA11 * fA22 - fA12 * fA12;
        float fCof01 = fA02 * fA12 - fA01 * fA22;
        float fCof02 = fA01 * fA12 - fA02 * fA11;
        float fCof11 = fA00 * fA22 - fA02 * fA02;
        float fCof12 = fA02 * fA01 - fA00 * fA12;
        float fCof22 = fA00 * fA11 - fA01 * fA01;
        float fDet = fA00 * fCof00 + fA01 * fCof01 + fA02 * fCof02;
        float fInvDet = 1.0f / fDet;
        float fRhs0 = -fB0 * fInvDet;
        float fRhs1 = -fB1 * fInvDet;
        float fRhs2 = -fB2 * fInvDet;

        fR = fCof00 * fRhs0 + fCof01 * fRhs1 + fCof02 * fRhs2;
        fS = fCof01 * fRhs0 + fCof11 * fRhs1 + fCof12 * fRhs2;
        fT = fCof02 * fRhs0 + fCof12 * fRhs1 + fCof22 * fRhs2;

        if (fR < 0.0f)
        {
            if (fS + fT <= 1.0)
            {
                if (fS < 0.0f)
                {
                    if (fT < 0.0f)  // region 4m
                    {
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                        fS = 0.0f;
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        fSqrDist0 = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else  // region 3m
                    {
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                        fS = 0.0f;
                        fSqrDist0 = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS0, fT0);
                        fR0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
                else if (fT < 0.0f)  // region 5m
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fS);
                    fT = 0.0f;
                    fSqrDist0 = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS0, fT0);
                    fR0 = 0.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 0m
                {
                    fSqrDist = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS, fT);
                    fR = 0.0f;
                }
            }
            else
            {
                if (fS < 0.0f)  // region 2m
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                    fS = 0.0f;
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fT0);
                    fS0 = 1.0f - fT0;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS0, fT0);
                    fR0 = 0.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if (fT < 0.0f)  // region 6m
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fS);
                    fT = 0.0f;
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fT0);
                    fS0 = 1.0f - fT0;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    fSqrDist0 = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS0, fT0);
                    fR0 = 0.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 1m
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                    fS = 1.0f - fT;
                    fSqrDist0 = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS0, fT0);
                    fR0 = 0.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
        }
        else if (fR <= 1.0f)
        {
            if (fS + fT <= 1.0)
            {
                if (fS < 0.0f)
                {
                    if (fT < 0.0f)  // region 4
                    {
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                        fS = 0.0f;
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else  // region 3
                    {
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                        fS = 0.0f;
                    }
                }
                else if (fT < 0.0f)  // region 5
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fS);
                    fT = 0.0f;
                }
                else  // region 0
                {
                    fSqrDist = 0.0f;
                }
            }
            else
            {
                if (fS < 0.0f)  // region 2
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                    fS = 0.0f;
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fT0);
                    fS0 = 1.0f - fT0;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if (fT < 0.0f)  // region 6
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fS);
                    fT = 0.0f;
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fT0);
                    fS0 = 1.0f - fT0;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 1
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                    fS = 1.0f - fT;
                }
            }
        }
        else
        {
            if (fS + fT <= 1.0)
            {
                if (fS < 0.0f)
                {
                    if (fT < 0.0f)  // region 4p
                    {
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                        fS = 0.0f;
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint1;
                        fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fS0);
                        fT0 = 0.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                        kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = GetSquaredDistanceToTriangle(kPt, kTri, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                    else  // region 3p
                    {
                        kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                        kTriSeg.m_kLightVector = kTri.m_kPoint2;
                        fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                        fS = 0.0f;
                        kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                        fSqrDist0 = GetSquaredDistanceToTriangle(kPt, kTri, fS0, fT0);
                        fR0 = 1.0f;
                        if (fSqrDist0 < fSqrDist)
                        {
                            fSqrDist = fSqrDist0;
                            fR = fR0;
                            fS = fS0;
                            fT = fT0;
                        }
                    }
                }
                else if (fT < 0.0f)  // region 5p
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fS);
                    fT = 0.0f;
                    kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                    fSqrDist0 = GetSquaredDistanceToTriangle(kPt, kTri, fS0, fT0);
                    fR0 = 1.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 0p
                {
                    kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                    fSqrDist = GetSquaredDistanceToTriangle(kPt, kTri, fS, fT);
                    fR = 1.0f;
                }
            }
            else
            {
                if (fS < 0.0f)  // region 2p
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                    fS = 0.0f;
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fT0);
                    fS0 = 1.0f - fT0;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                    fSqrDist0 = GetSquaredDistanceToTriangle(kPt, kTri, fS0, fT0);
                    fR0 = 1.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else if (fT < 0.0f)  // region 6p
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint;
                    kTriSeg.m_kLightVector = kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fS);
                    fT = 0.0f;
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist0 = NiSqrDistance_Compute(kSeg, kTriSeg, fR0, fT0);
                    fS0 = 1.0f - fT0;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                    kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                    fSqrDist0 = GetSquaredDistanceToTriangle(kPt, kTri, fS0, fT0);
                    fR0 = 1.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
                else  // region 1p
                {
                    kTriSeg.m_kStartPoint = kTri.m_kStartPoint + kTri.m_kPoint1;
                    kTriSeg.m_kLightVector = kTri.m_kPoint2 - kTri.m_kPoint1;
                    fSqrDist = NiSqrDistance_Compute(kSeg, kTriSeg, fR, fT);
                    fS = 1.0f - fT;
                    kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
                    fSqrDist0 = GetSquaredDistanceToTriangle(kPt, kTri, fS0, fT0);
                    fR0 = 1.0f;
                    if (fSqrDist0 < fSqrDist)
                    {
                        fSqrDist = fSqrDist0;
                        fR = fR0;
                        fS = fS0;
                        fT = fT0;
                    }
                }
            }
        }
        return fSqrDist;
    }
    else
    {
        // segment and triangle are parallel
        NiPoint3& edgeOrigin = kTriSeg.m_kStartPoint;
        OriginDirectionPair& triangleEdge = kTriSeg;
        edgeOrigin = kTri.m_kStartPoint;
        triangleEdge.m_kLightVector = kTri.m_kPoint1;
        fSqrDist = NiSqrDistance_Compute(kSeg, triangleEdge, fR, fS);
        fT = 0.0f;

        triangleEdge.m_kLightVector = kTri.m_kPoint2;
        fSqrDist0 = NiSqrDistance_Compute(kSeg, triangleEdge, fR0, fT0);
        fS0 = 0.0f;
        if (fSqrDist0 < fSqrDist)
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        edgeOrigin = kTri.m_kPoint1 + edgeOrigin;
        triangleEdge.m_kLightVector = triangleEdge.m_kLightVector - kTri.m_kPoint1;
        fSqrDist0 = NiSqrDistance_Compute(kSeg, triangleEdge, fR0, fT0);
        fS0 = 1.0f - fT0;
        if (fSqrDist0 < fSqrDist)
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        fSqrDist0 = GetSquaredDistanceToTriangle(kSeg.m_kStartPoint, kTri, fS0, fT0);
        fR0 = 0.0f;
        if (fSqrDist0 < fSqrDist)
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }

        kPt = kSeg.m_kStartPoint + kSeg.m_kLightVector;
        fSqrDist0 = GetSquaredDistanceToTriangle(kPt, kTri, fS0, fT0);
        fR0 = 1.0f;
        if (fSqrDist0 < fSqrDist)
        {
            fSqrDist = fSqrDist0;
            fR = fR0;
            fS = fS0;
            fT = fT0;
        }
    }

    return fSqrDist;
}
}  // namespace fnv_00eb1d20

struct ClampPoint
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
};

struct ClampBox
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    float m_fSecondFloatOfFirstPair;
    float m_fSecondFloatOfSecondPair;
    float m_fThirdValue;
};

// Clamps each axis of self to the range defined by other and accumulates the squared deviation into out.
// @fnv 0x00eb4490
static __declspec(noinline) void ClampPointToBox(ClampBox* apBox, ClampPoint* apPoint, float* afSquaredDistance)
{
    float d;

    if (apPoint->m_uiX < -apBox->m_fSecondFloatOfFirstPair)
    {
        d = apBox->m_fSecondFloatOfFirstPair + apPoint->m_uiX;
        *afSquaredDistance = *afSquaredDistance + d * d;
        apPoint->m_uiX = -apBox->m_fSecondFloatOfFirstPair;
    }
    else if (apPoint->m_uiX > apBox->m_fSecondFloatOfFirstPair)
    {
        d = apPoint->m_uiX - apBox->m_fSecondFloatOfFirstPair;
        *afSquaredDistance = *afSquaredDistance + d * d;
        apPoint->m_uiX = apBox->m_fSecondFloatOfFirstPair;
    }

    if (apPoint->m_uiY < -apBox->m_fSecondFloatOfSecondPair)
    {
        d = apBox->m_fSecondFloatOfSecondPair + apPoint->m_uiY;
        *afSquaredDistance = *afSquaredDistance + d * d;
        apPoint->m_uiY = -apBox->m_fSecondFloatOfSecondPair;
    }
    else if (apPoint->m_uiY > apBox->m_fSecondFloatOfSecondPair)
    {
        d = apPoint->m_uiY - apBox->m_fSecondFloatOfSecondPair;
        *afSquaredDistance = *afSquaredDistance + d * d;
        apPoint->m_uiY = apBox->m_fSecondFloatOfSecondPair;
    }

    if (apPoint->m_uiZ < -apBox->m_fThirdValue)
    {
        d = apBox->m_fThirdValue + apPoint->m_uiZ;
        *afSquaredDistance = *afSquaredDistance + d * d;
        apPoint->m_uiZ = -apBox->m_fThirdValue;
    }
    else if (apPoint->m_uiZ > apBox->m_fThirdValue)
    {
        d = apPoint->m_uiZ - apBox->m_fThirdValue;
        *afSquaredDistance = *afSquaredDistance + d * d;
        apPoint->m_uiZ = apBox->m_fThirdValue;
    }
}

float ClampDist(ClampPoint* p, ClampBox* b)
{
    float s = 0.0f;
    ClampPointToBox(b, p, &s);
    return s;
}

struct S00eb4de0_Box
{
    NiPoint3 center;
    NiPoint3 axis[3];
    float extent[3];
    const float& Extent(int i) const
    {
        return extent[i];
    }
};

// Clamps a point into a box along a direction, accumulating squared distance and computing the line parameter.
// @fnv 0x00eb4de0
// src: GAMEBRYO_LIB 0x00eb4de0
static __declspec(noinline) void Case0(const S00eb4de0_Box& rkBox, int aiAxis0, int aiAxis1, int aiAxis2,
                                              NiPoint3& rkPnt, const NiPoint3& rkDir, float* pfLParam,
                                              float& rfSqrDistance)
{
    float fPmE0 = rkPnt[aiAxis0] - rkBox.extent[aiAxis0];
    float fPmE1 = rkPnt[aiAxis1] - rkBox.extent[aiAxis1];
    float fProd0 = rkDir.components[aiAxis1] * fPmE0;
    float fProd1 = rkDir[aiAxis0] * fPmE1;
    float fTimeSinceScaleStart, fInvLSqr, fInv;

    if (fProd0 >= fProd1)
    {
        rkPnt[aiAxis0] = rkBox.extent[aiAxis0];

        float fPpE1 = rkPnt[aiAxis1] + rkBox.extent[aiAxis1];
        fTimeSinceScaleStart = fProd0 - rkDir[aiAxis0] * fPpE1;
        if (fTimeSinceScaleStart >= 0.0f)
        {
            double fScaleMultiplier = rkDir[aiAxis0] * rkDir[aiAxis0];
            fScaleMultiplier += rkDir[aiAxis1] * rkDir[aiAxis1];
            fInvLSqr = 1.0f / fScaleMultiplier;
            rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart * fInvLSqr;
            rkPnt[aiAxis1] = -rkBox.extent[aiAxis1];
            *pfLParam = -(rkDir[aiAxis0] * fPmE0 + rkDir[aiAxis1] * fPpE1) * fInvLSqr;
        }
        else
        {
            fInv = 1.0f / rkDir[aiAxis0];
            rkPnt[aiAxis1] -= fProd0 * fInv;
            *pfLParam = -fPmE0 * fInv;
        }
    }
    else
    {
        rkPnt[aiAxis1] = rkBox.extent[aiAxis1];

        float fPpE0 = rkPnt[aiAxis0] + rkBox.extent[aiAxis0];
        fTimeSinceScaleStart = fProd1 - rkDir[aiAxis1] * fPpE0;
        if (fTimeSinceScaleStart >= 0.0f)
        {
            double fScaleMultiplier = rkDir[aiAxis0] * rkDir[aiAxis0];
            fScaleMultiplier += rkDir[aiAxis1] * rkDir[aiAxis1];
            fInvLSqr = 1.0f / fScaleMultiplier;
            rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart * fInvLSqr;
            rkPnt[aiAxis0] = -rkBox.extent[aiAxis0];
            double fProjection = rkDir[aiAxis1] * fPmE1;
            fProjection += rkDir[aiAxis0] * fPpE0;
            *pfLParam = -fProjection * fInvLSqr;
        }
        else
        {
            fInv = 1.0f / rkDir[aiAxis1];
            rkPnt[aiAxis0] -= fProd1 * fInv;
            *pfLParam = -fPmE1 * fInv;
        }
    }

    if (rkPnt[aiAxis2] < -rkBox.extent[aiAxis2])
    {
        fTimeSinceScaleStart = rkPnt[aiAxis2] + rkBox.extent[aiAxis2];
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt[aiAxis2] = -rkBox.extent[aiAxis2];
    }
    else if (rkPnt[aiAxis2] > rkBox.extent[aiAxis2])
    {
        fTimeSinceScaleStart = rkPnt[aiAxis2] - rkBox.extent[aiAxis2];
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt[aiAxis2] = rkBox.extent[aiAxis2];
    }
}

struct S00eb4de0_Line
{
    NiPoint3 origin;
    NiPoint3 direction;
};
static inline float S00eb4de0_Dot(const NiPoint3& a, const NiPoint3& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
float S00eb4de0_Caller(const S00eb4de0_Line& rkLine, const S00eb4de0_Box& rkBox, float* pfLParam)
{
    NiPoint3 kDiff;
    for (int k = 0; k < 3; k++)
        kDiff[k] = rkLine.origin[k] - rkBox.center[k];
    NiPoint3 kPnt, kWorldPosition;
    kPnt[0] = S00eb4de0_Dot(kDiff, rkBox.axis[0]);
    kPnt[1] = S00eb4de0_Dot(kDiff, rkBox.axis[1]);
    kPnt[2] = S00eb4de0_Dot(kDiff, rkBox.axis[2]);
    kWorldPosition[0] = S00eb4de0_Dot(rkLine.direction, rkBox.axis[0]);
    kWorldPosition[1] = S00eb4de0_Dot(rkLine.direction, rkBox.axis[1]);
    kWorldPosition[2] = S00eb4de0_Dot(rkLine.direction, rkBox.axis[2]);
    bool bReflect[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        if (kWorldPosition[i] < 0.0f)
        {
            kPnt[i] = -kPnt[i];
            kWorldPosition[i] = -kWorldPosition[i];
            bReflect[i] = true;
        }
        else
            bReflect[i] = false;
    }
    float fSqrDistance = 0.0f;
    if (kWorldPosition[0] > 0.0f)
    {
        if (kWorldPosition[1] > 0.0f)
        {
            if (kWorldPosition[2] > 0.0f)
                fSqrDistance = 1.0f;
            else
                Case0(rkBox, 0, 1, 2, kPnt, kWorldPosition, pfLParam, fSqrDistance);
        }
        else
        {
            if (kWorldPosition[2] > 0.0f)
                Case0(rkBox, 0, 2, 1, kPnt, kWorldPosition, pfLParam, fSqrDistance);
            else
                fSqrDistance = 2.0f;
        }
    }
    else
    {
        if (kWorldPosition[1] > 0.0f)
        {
            if (kWorldPosition[2] > 0.0f)
                Case0(rkBox, 1, 2, 0, kPnt, kWorldPosition, pfLParam, fSqrDistance);
            else
                fSqrDistance = 3.0f;
        }
    }
    for (i = 0; i < 3; i++)
        if (bReflect[i])
            kPnt[i] = -kPnt[i];
    return fSqrDistance + kPnt[0];
}

struct AxisValues
{
    float value[3];
};
struct ExtentBox
{
    BoxVec3 center, axis0, axis1, axis2;
    float extent[3];
    float extentAt(int i) const
    {
        return extent[i];
    }
};
struct BoxInput
{
    const ExtentBox* value;
};
union AxisIndex
{
    int value;
    float delta;
};
// Clamps a point to an oriented box on two axes, accumulating squared distance, and stores the parameter along the first axis.
// @fnv 0x00eb5010
// src: GAMEBRYO_LIB 0x00eb5010
static __declspec(noinline) void Case00(AxisValues* point, int axis1, int axis2, float* pfSqrDistance,
                                              BoxInput boxArg, AxisIndex axisArg, const AxisValues* direction,
                                              float* pfParam)
{
    int axis0 = axisArg.value;
    const ExtentBox* box = boxArg.value;
    *pfParam = (box->extent[axis0] - point->value[axis0]) / direction->value[axis0];
    point->value[axis0] = box->extent[axis0];
    if (point->value[axis1] < -box->extentAt(axis1))
    {
        axisArg.delta = point->value[axis1] + box->extent[axis1];
        *pfSqrDistance += axisArg.delta * axisArg.delta;
        point->value[axis1] = -box->extent[axis1];
    }
    else if (point->value[axis1] > box->extent[axis1])
    {
        axisArg.delta = point->value[axis1] - box->extent[axis1];
        *pfSqrDistance += axisArg.delta * axisArg.delta;
        point->value[axis1] = box->extent[axis1];
    }
    if (point->value[axis2] < -box->extent[axis2])
    {
        axisArg.delta = point->value[axis2] + box->extent[axis2];
        *pfSqrDistance += axisArg.delta * axisArg.delta;
        point->value[axis2] = -box->extent[axis2];
    }
    else if (point->value[axis2] > box->extent[axis2])
    {
        axisArg.delta = point->value[axis2] - box->extent[axis2];
        *pfSqrDistance += axisArg.delta * axisArg.delta;
        point->value[axis2] = box->extent[axis2];
    }
}
extern AxisValues* volatile probePoint;
extern int volatile probeAxis0, probeAxis1, probeAxis2;
extern float* volatile probeSquared;
extern float* volatile probeParameter;
extern const ExtentBox* volatile probeBox;
extern const AxisValues* volatile probeDirection;
void probeCaller()
{
    BoxInput b = {probeBox};
    AxisIndex a = {probeAxis0};
    Case00(probePoint, probeAxis1, probeAxis2, probeSquared, b, a, probeDirection, probeParameter);
}

struct Alloc139
{
    void* Game_DoHeapAlloc(unsigned int);
    void MemoryManager_Deallocate(void*);
};

void* NiMalloc(unsigned int);
void NiFreeAlias(void*);
inline void* __cdecl operator new[](size_t n)
{
    return ((Alloc139&)DAT_011f6238).Game_DoHeapAlloc(n);
}
inline NiPoint3 NiPoint3::operator*(double f) const
{
    return NiPoint3(x * f, y * f, z * f);
}

struct FUN_00eba1b0
{
    virtual ~FUN_00eba1b0();
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
    volatile int unk7c;
    int unk80;
    int unk84;
    int unk88;
    FUN_00eba1b0(int, unsigned short, const unsigned short*, const NiPoint3*, int, int);
    void BuildNode(int, const unsigned short*, const NiPoint3*, int, float*, NiPoint3*, int, int, int*, int*, int);
};
// Computes each triangle's area and centroid from indices and vertices, then calls BuildNode with them plus temporary order and scratch arrays.
// @fnv 0x00eba1b0
FUN_00eba1b0::FUN_00eba1b0(int arg1, unsigned short count, const unsigned short* indices, const NiPoint3* vertices,
                           int arg5, int arg6)
{
    unk7c = 0;
    float* areas = (float*)NiMalloc(count * sizeof(float));
    NiPoint3* centers = new NiPoint3[count];
    unsigned short cursor = 0;
    for (unsigned short i = 0; i < count; i++)
    {
        unsigned short i0 = indices[cursor++];
        unsigned short i1 = indices[cursor++];
        unsigned short i2 = indices[cursor++];
        const NiPoint3& a = vertices[i0];
        const NiPoint3& b = vertices[i1];
        const NiPoint3& c = vertices[i2];
        NiPoint3 edge0 = b - a;
        NiPoint3 edge1 = c - a;
        NiPoint3 normal = edge0.Cross(edge1);
        float length = static_cast<const NiPoint3&>(normal).Length();
        areas[i] = 0.5 * length;
        centers[i] = AddTriangleVertices(AddTriangleVertices(vertices[i0], vertices[i1]), vertices[i2]) *
                     static_cast<double>(1.0f / 3.0f);
    }
    int* order = (int*)NiMalloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        order[i] = i;
    int* scratch = (int*)NiMalloc(count * sizeof(int));
    BuildNode(arg1, indices, vertices, arg5, areas, centers, 0, count - 1, order, scratch, arg6);
    NiFreeAlias(scratch);
    NiFreeAlias(order);
    DAT_011f6238.MemoryManager_Deallocate(centers);
    NiFreeAlias(areas);
    unk88 = 0;
}

struct LBPoint3
{
    float x, y, z;
    float& operator[](int i)
    {
        return (&x)[i];
    }
    float operator[](int i) const
    {
        return (&x)[i];
    }
};

struct LBBox
{
    LBPoint3 m_kCenter;
    LBPoint3 m_akAxes[3];
    float m_afExtents[3];
};

// src: GAMEBRYO_LIB 0x00eb4590
static void Face_00eb4590(const LBBox& rkBox, int i0, int i1, int i2, LBPoint3& rkPnt, const LBPoint3& rkDir,
                         const LBPoint3& rkPmE, float* pfLParam, float& rfSqrDistance)
{
    LBPoint3 kPpE;
    float fPmE0 = rkPmE[i0];
    float fDir0 = rkDir[i0];
    float fPmEExtra = rkPmE[i2];
    float fLSqr, fInv, fTmp, fParam, fT, fTimeSinceScaleStart;

    kPpE[i1] = rkPnt[i1] + rkBox.m_afExtents[i1];
    kPpE[i2] = rkPnt[i2] + rkBox.m_afExtents[i2];
    if (rkDir[i0] * kPpE[i1] >= rkDir[i1] * fPmE0)
    {
        if (rkDir[i0] * kPpE[i2] >= rkDir[i2] * fPmE0)
        {
            rkPnt[i0] = rkBox.m_afExtents[i0];
            fInv = 1.0f / rkDir[i0];
            rkPnt[i1] -= rkDir[i1] * fPmE0 * fInv;
            rkPnt[i2] -= rkDir[i2] * fPmE0 * fInv;
            *pfLParam = -fPmE0 * fInv;
        }
        else
        {
            fLSqr = rkDir[i0] * rkDir[i0] + rkDir[i2] * rkDir[i2];
            fTmp = fLSqr * kPpE[i1] - rkDir[i1] * (rkDir[i0] * fPmE0 + rkDir[i2] * kPpE[i2]);
            if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i1])
            {
                fT = fTmp / fLSqr;
                fLSqr += rkDir[i1] * rkDir[i1];
                fTmp = kPpE[i1] - fT;
                fTimeSinceScaleStart = rkDir[i0] * rkPmE[i0] + rkDir[i1] * fTmp + rkDir[i2] * kPpE[i2];
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance +=
                    rkPmE[i0] * rkPmE[i0] + fTmp * fTmp + kPpE[i2] * kPpE[i2] + fTimeSinceScaleStart * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = fT - rkBox.m_afExtents[i1];
                rkPnt[i2] = -rkBox.m_afExtents[i2];
            }
            else
            {
                fLSqr += rkDir[i1] * rkDir[i1];
                fTimeSinceScaleStart = rkDir[i0] * rkPmE[i0] + rkDir[i1] * rkPmE[i1] + rkDir[i2] * kPpE[i2];
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance +=
                    rkPmE[i0] * rkPmE[i0] + rkPmE[i1] * rkPmE[i1] + kPpE[i2] * kPpE[i2] + fTimeSinceScaleStart * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = rkBox.m_afExtents[i1];
                rkPnt[i2] = -rkBox.m_afExtents[i2];
            }
        }
    }
    else
    {
        if (fDir0 * kPpE[i2] >= rkDir[i2] * rkPmE[i0])
        {
            fLSqr = fDir0 * fDir0 + rkDir[i1] * rkDir[i1];
            fTmp = fLSqr * kPpE[i2] - rkDir[i2] * (fDir0 * rkPmE[i0] + rkDir[i1] * kPpE[i1]);
            if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i2])
            {
                fT = fTmp / fLSqr;
                fLSqr += rkDir[i2] * rkDir[i2];
                fTmp = kPpE[i2] - fT;
                fTimeSinceScaleStart = fDir0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + rkDir[i2] * fTmp;
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance +=
                    rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + fTmp * fTmp + fTimeSinceScaleStart * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = -rkBox.m_afExtents[i1];
                rkPnt[i2] = fT - rkBox.m_afExtents[i2];
            }
            else
            {
                fLSqr += rkDir[i2] * rkDir[i2];
                fTimeSinceScaleStart = fDir0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + rkDir[i2] * fPmEExtra;
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance +=
                    rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + fPmEExtra * fPmEExtra + fTimeSinceScaleStart * fParam;
                *pfLParam = fParam;
                rkPnt[i0] = rkBox.m_afExtents[i0];
                rkPnt[i1] = -rkBox.m_afExtents[i1];
                rkPnt[i2] = rkBox.m_afExtents[i2];
            }
        }
        else
        {
            fLSqr = fDir0 * fDir0 + rkDir[i2] * rkDir[i2];
            fTmp = fLSqr * kPpE[i1] - rkDir[i1] * (fDir0 * rkPmE[i0] + rkDir[i2] * kPpE[i2]);
            if (fTmp >= 0.0f)
            {
                if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i1])
                {
                    fT = fTmp / fLSqr;
                    fLSqr += rkDir[i1] * rkDir[i1];
                    fTmp = kPpE[i1] - fT;
                    fTimeSinceScaleStart = fDir0 * rkPmE[i0] + rkDir[i1] * fTmp + rkDir[i2] * kPpE[i2];
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance +=
                        rkPmE[i0] * rkPmE[i0] + fTmp * fTmp + kPpE[i2] * kPpE[i2] + fTimeSinceScaleStart * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = fT - rkBox.m_afExtents[i1];
                    rkPnt[i2] = -rkBox.m_afExtents[i2];
                }
                else
                {
                    fLSqr += rkDir[i1] * rkDir[i1];
                    fTimeSinceScaleStart = fDir0 * rkPmE[i0] + rkDir[i1] * rkPmE[i1] + rkDir[i2] * kPpE[i2];
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance += rkPmE[i0] * rkPmE[i0] + rkPmE[i1] * rkPmE[i1] + kPpE[i2] * kPpE[i2] +
                                     fTimeSinceScaleStart * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = rkBox.m_afExtents[i1];
                    rkPnt[i2] = -rkBox.m_afExtents[i2];
                }
                return;
            }

            fLSqr = fDir0 * fDir0 + rkDir[i1] * rkDir[i1];
            fTmp = fLSqr * kPpE[i2] - rkDir[i2] * (fDir0 * rkPmE[i0] + rkDir[i1] * kPpE[i1]);
            if (fTmp >= 0.0f)
            {
                if (fTmp <= 2.0f * fLSqr * rkBox.m_afExtents[i2])
                {
                    fT = fTmp / fLSqr;
                    fLSqr += rkDir[i2] * rkDir[i2];
                    fTmp = kPpE[i2] - fT;
                    fTimeSinceScaleStart = fDir0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + rkDir[i2] * fTmp;
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance +=
                        rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + fTmp * fTmp + fTimeSinceScaleStart * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = -rkBox.m_afExtents[i1];
                    rkPnt[i2] = fT - rkBox.m_afExtents[i2];
                }
                else
                {
                    fLSqr += rkDir[i2] * rkDir[i2];
                    fTimeSinceScaleStart = fDir0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + rkDir[i2] * fPmEExtra;
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance += rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + fPmEExtra * fPmEExtra +
                                     fTimeSinceScaleStart * fParam;
                    *pfLParam = fParam;
                    rkPnt[i0] = rkBox.m_afExtents[i0];
                    rkPnt[i1] = -rkBox.m_afExtents[i1];
                    rkPnt[i2] = rkBox.m_afExtents[i2];
                }
                return;
            }

            fLSqr += rkDir[i2] * rkDir[i2];
            fTimeSinceScaleStart = fDir0 * rkPmE[i0] + rkDir[i1] * kPpE[i1] + rkDir[i2] * kPpE[i2];
            fParam = -fTimeSinceScaleStart / fLSqr;
            rfSqrDistance +=
                rkPmE[i0] * rkPmE[i0] + kPpE[i1] * kPpE[i1] + kPpE[i2] * kPpE[i2] + fTimeSinceScaleStart * fParam;
            *pfLParam = fParam;
            rkPnt[i0] = rkBox.m_afExtents[i0];
            rkPnt[i1] = -rkBox.m_afExtents[i1];
            rkPnt[i2] = -rkBox.m_afExtents[i2];
        }
    }
}

// Compares products of rkDir and rkPnt minus box extents to choose an axis order, then calls FUN_00eb4590 with it.
// @fnv 0x00eb4cd0
// src: GAMEBRYO_LIB 0x00eb4cd0
static void CaseNoZeros(LBPoint3& rkPnt, const LBPoint3& rkDir, const LBBox& rkBox, float* pfLParam,
                         float& rfSqrDistance)
{
    LBPoint3 kPmE;
    kPmE.x = rkPnt.x - rkBox.m_afExtents[0];
    kPmE.y = rkPnt.y - rkBox.m_afExtents[1];
    kPmE.z = rkPnt.z - rkBox.m_afExtents[2];

    float fProdDxPy = rkDir.x * kPmE.y;
    float fProdDyPx = rkDir.y * kPmE.x;
    float fProdDzPx, fProdDxPz, fProdDzPy, fProdDyPz;

    if (fProdDyPx >= fProdDxPy)
    {
        fProdDzPx = rkDir.z * kPmE.x;
        fProdDxPz = rkDir.x * kPmE.z;
        if (fProdDzPx >= fProdDxPz)
            Face_00eb4590(rkBox, 0, 1, 2, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
        else
            Face_00eb4590(rkBox, 2, 0, 1, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
    }
    else
    {
        fProdDzPy = rkDir.z * kPmE.y;
        fProdDyPz = rkDir.y * kPmE.z;
        if (fProdDzPy >= fProdDyPz)
            Face_00eb4590(rkBox, 1, 2, 0, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
        else
            Face_00eb4590(rkBox, 2, 0, 1, rkPnt, rkDir, kPmE, pfLParam, rfSqrDistance);
    }
}

struct LBLine3
{
    LBPoint3 m_kStartPoint;
    LBPoint3 m_kLightVector;
};

void LBCase0(int i0, int i1, int i2, LBPoint3& rkPnt, const LBPoint3& rkDir, const LBBox& rkBox, float* pfLParam,
             float& rfSqrDistance);
void LBCase00(int i0, int i1, int i2, LBPoint3& rkPnt, const LBPoint3& rkDir, const LBBox& rkBox, float* pfLParam,
              float& rfSqrDistance);
void LBCase000(LBPoint3& rkPnt, const LBBox& rkBox, float& rfSqrDistance);

static float Dot(const LBPoint3& a, const LBPoint3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float LBSqrDistance(const LBLine3& rkLine, const LBBox& rkBox, float* pfLParam, float* pfBParam0, float* pfBParam1,
                    float* pfBParam2)
{
    LBPoint3 kDiff;
    kDiff.x = rkLine.m_kStartPoint.x - rkBox.m_kCenter.x;
    kDiff.y = rkLine.m_kStartPoint.y - rkBox.m_kCenter.y;
    kDiff.z = rkLine.m_kStartPoint.z - rkBox.m_kCenter.z;
    LBPoint3 kPnt, kWorldPosition;
    kPnt.x = Dot(kDiff, rkBox.m_akAxes[0]);
    kPnt.y = Dot(kDiff, rkBox.m_akAxes[1]);
    kPnt.z = Dot(kDiff, rkBox.m_akAxes[2]);
    kWorldPosition.x = Dot(rkLine.m_kLightVector, rkBox.m_akAxes[0]);
    kWorldPosition.y = Dot(rkLine.m_kLightVector, rkBox.m_akAxes[1]);
    kWorldPosition.z = Dot(rkLine.m_kLightVector, rkBox.m_akAxes[2]);

    bool bReflect[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        if (kWorldPosition[i] < 0.0f)
        {
            kPnt[i] = -kPnt[i];
            kWorldPosition[i] = -kWorldPosition[i];
            bReflect[i] = true;
        }
        else
        {
            bReflect[i] = false;
        }
    }

    float fSqrDistance = 0.0f;

    if (kWorldPosition.x > 0.0f)
    {
        if (kWorldPosition.y > 0.0f)
        {
            if (kWorldPosition.z > 0.0f)
                CaseNoZeros(kPnt, kWorldPosition, rkBox, pfLParam, fSqrDistance);
            else
                LBCase0(0, 1, 2, kPnt, kWorldPosition, rkBox, pfLParam, fSqrDistance);
        }
        else
        {
            if (kWorldPosition.z > 0.0f)
                LBCase0(0, 2, 1, kPnt, kWorldPosition, rkBox, pfLParam, fSqrDistance);
            else
                LBCase00(0, 1, 2, kPnt, kWorldPosition, rkBox, pfLParam, fSqrDistance);
        }
    }
    else
    {
        if (kWorldPosition.y > 0.0f)
        {
            if (kWorldPosition.z > 0.0f)
                LBCase0(1, 2, 0, kPnt, kWorldPosition, rkBox, pfLParam, fSqrDistance);
            else
                LBCase00(1, 0, 2, kPnt, kWorldPosition, rkBox, pfLParam, fSqrDistance);
        }
        else
        {
            if (kWorldPosition.z > 0.0f)
                LBCase00(2, 0, 1, kPnt, kWorldPosition, rkBox, pfLParam, fSqrDistance);
            else
            {
                LBCase000(kPnt, rkBox, fSqrDistance);
                if (pfLParam)
                    *pfLParam = 0.0f;
            }
        }
    }

    if (pfBParam0)
    {
        for (i = 0; i < 3; i++)
        {
            if (bReflect[i])
                kPnt[i] = -kPnt[i];
        }
        *pfBParam0 = kPnt.x;
        *pfBParam1 = kPnt.y;
        *pfBParam2 = kPnt.z;
    }

    return fSqrDistance;
}

float __cdecl DistanceSquaredToSegment(const NiPoint3&, const OriginDirectionPair&, float&);

// Returns the squared distance from kPnt to the region spanned from m_kStartPoint by m_kPoint1 and m_kPoint2, writing the clamped parameters to fS and fT.
// @fnv 0x00eb6150
// src: GAMEBRYO_LIB 0x00eb6150
float __cdecl NiSqrDistance_Compute_00eb6150(const NiPoint3& kPnt, const TrianglePointSet& kPgm, float& fS, float& fT)
{
    NiPoint3 kDiff = kPgm.m_kStartPoint - kPnt;
    float fA00 = kPgm.m_kPoint1.DotProduct(kPgm.m_kPoint1);
    float fA01 = kPgm.m_kPoint1.DotProduct(kPgm.m_kPoint2);
    float fA11 = kPgm.m_kPoint2.DotProduct(kPgm.m_kPoint2);
    float fB0 = kPgm.m_kPoint1.DotProduct(kDiff);
    float fB1 = kPgm.m_kPoint2.DotProduct(kDiff);
    float fC = kDiff.DotProduct(kDiff);
    float fDet = fA00 * fA11 - fA01 * fA01;
    fDet = (float)fabs(fDet);
    float fTmp;
    if (fDet >= 1e-05f)
    {
        fS = fA01 * fB1 - fA11 * fB0;
        fT = fA01 * fB0 - fA00 * fB1;
        if (fS < 0.0f)
        {
            if (fT < 0.0f)
            {
                if (fB0 < 0.0f)
                {
                    fT = 0.0f;
                    if (-fB0 >= fA00)
                    {
                        fS = 1.0f;
                        float fSqrDist = fA00 + 2.0 * fB0 + fC;
                        return fabsf(fSqrDist);
                    }
                    else
                    {
                        fS = -fB0 / fA00;
                        float fSqrDist = fB0 * fS + fC;
                        return fabsf(fSqrDist);
                    }
                }
                else
                {
                    fS = 0.0f;
                    if (fB1 >= 0.0f)
                    {
                        fT = 0.0f;
                        return fabsf(fC);
                    }
                    else if (-fB1 >= fA11)
                    {
                        fT = 1.0f;
                        float fSqrDist = fA11 + 2.0 * fB1 + fC;
                        return fabsf(fSqrDist);
                    }
                    else
                    {
                        fT = -fB1 / fA11;
                        float fSqrDist = fB1 * fT + fC;
                        return fabsf(fSqrDist);
                    }
                }
            }
            else if (fT <= fDet)
            {
                fS = 0.0f;
                if (fB1 >= 0.0f)
                {
                    fT = 0.0f;
                    return fabsf(fC);
                }
                else if (-fB1 >= fA11)
                {
                    fT = 1.0f;
                    float fSqrDist = fA11 + 2.0 * fB1 + fC;
                    return fabsf(fSqrDist);
                }
                else
                {
                    fT = -fB1 / fA11;
                    float fSqrDist = fB1 * fT + fC;
                    return fabsf(fSqrDist);
                }
            }
            else
            {
                fTmp = fA01 + fB0;
                if (fTmp < 0.0f)
                {
                    fT = 1.0f;
                    if (-fTmp >= fA00)
                    {
                        fS = 1.0f;
                        float fSqrDist = fA00 + fA11 + fC + 2.0 * (fA01 + fB0 + fB1);
                        return fabsf(fSqrDist);
                    }
                    else
                    {
                        fS = -fTmp / fA00;
                        float fSqrDist = fTmp * fS + fA11 + 2.0 * fB1 + fC;
                        return fabsf(fSqrDist);
                    }
                }
                else
                {
                    fS = 0.0f;
                    if (fB1 >= 0.0f)
                    {
                        fT = 0.0f;
                        return fabsf(fC);
                    }
                    else if (-fB1 >= fA11)
                    {
                        fT = 1.0f;
                        float fSqrDist = fA11 + 2.0 * fB1 + fC;
                        return fabsf(fSqrDist);
                    }
                    else
                    {
                        fT = -fB1 / fA11;
                        float fSqrDist = fB1 * fT + fC;
                        return fabsf(fSqrDist);
                    }
                }
            }
        }
        else if (fS <= fDet)
        {
            if (fT < 0.0f)
            {
                fT = 0.0f;
                if (fB0 >= 0.0f)
                {
                    fS = 0.0f;
                    return fabsf(fC);
                }
                else if (-fB0 >= fA00)
                {
                    fS = 1.0f;
                    float fSqrDist = fA00 + 2.0 * fB0 + fC;
                    return fabsf(fSqrDist);
                }
                else
                {
                    fS = -fB0 / fA00;
                    float fSqrDist = fB0 * fS + fC;
                    return fabsf(fSqrDist);
                }
            }
            else if (fT <= fDet)
            {
                float fInvDet = 1.0f / fDet;
                fS *= fInvDet;
                fT *= fInvDet;
                float fSqrDist =
                    fS * (fA00 * fS + fA01 * fT + 2.0 * fB0) + fT * (fA01 * fS + fA11 * fT + 2.0 * fB1) + fC;
                return fabsf(fSqrDist);
            }
            else
            {
                fT = 1.0f;
                fTmp = fA01 + fB0;
                if (fTmp >= 0.0f)
                {
                    fS = 0.0f;
                    float fSqrDist = fA11 + 2.0 * fB1 + fC;
                    return fabsf(fSqrDist);
                }
                else if (-fTmp >= fA00)
                {
                    fS = 1.0f;
                    float fSqrDist = fA00 + fA11 + fC + 2.0 * (fA01 + fB0 + fB1);
                    return fabsf(fSqrDist);
                }
                else
                {
                    fS = -fTmp / fA00;
                    float fSqrDist = fTmp * fS + fA11 + 2.0 * fB1 + fC;
                    return fabsf(fSqrDist);
                }
            }
        }
        else
        {
            if (fT < 0.0f)
            {
                if (-fB0 < fA00)
                {
                    fT = 0.0f;
                    if (fB0 >= 0.0f)
                    {
                        fS = 0.0f;
                        return fabsf(fC);
                    }
                    else
                    {
                        fS = -fB0 / fA00;
                        float fSqrDist = fB0 * fS + fC;
                        return fabsf(fSqrDist);
                    }
                }
                else
                {
                    fS = 1.0f;
                    fTmp = fA01 + fB1;
                    if (fTmp >= 0.0f)
                    {
                        fT = 0.0f;
                        float fSqrDist = fA00 + 2.0 * fB0 + fC;
                        return fabsf(fSqrDist);
                    }
                    else if (-fTmp >= fA11)
                    {
                        fT = 1.0f;
                        float fSqrDist = fA00 + fA11 + fC + 2.0 * (fA01 + fB0 + fB1);
                        return fabsf(fSqrDist);
                    }
                    else
                    {
                        fT = -fTmp / fA11;
                        float fSqrDist = fA00 + fTmp * fT + 2.0 * fB0 + fC;
                        return fabsf(fSqrDist);
                    }
                }
            }
            else if (fT <= fDet)
            {
                fS = 1.0f;
                fTmp = fA01 + fB1;
                if (fTmp >= 0.0f)
                {
                    fT = 0.0f;
                    float fSqrDist = fA00 + 2.0 * fB0 + fC;
                    return fabsf(fSqrDist);
                }
                else if (-fTmp >= fA11)
                {
                    fT = 1.0f;
                    float fSqrDist = fA00 + fA11 + fC + 2.0 * (fA01 + fB0 + fB1);
                    return fabsf(fSqrDist);
                }
                else
                {
                    fT = -fTmp / fA11;
                    float fSqrDist = fA00 + fTmp * fT + 2.0 * fB0 + fC;
                    return fabsf(fSqrDist);
                }
            }
            else
            {
                fTmp = fA01 + fB0;
                if (-fTmp < fA00)
                {
                    fT = 1.0f;
                    if (fTmp >= 0.0f)
                    {
                        fS = 0.0f;
                        float fSqrDist = fA11 + 2.0 * fB1 + fC;
                        return fabsf(fSqrDist);
                    }
                    else
                    {
                        fS = -fTmp / fA00;
                        float fSqrDist = fTmp * fS + fA11 + 2.0 * fB1 + fC;
                        return fabsf(fSqrDist);
                    }
                }
                else
                {
                    fS = 1.0f;
                    fTmp = fA01 + fB1;
                    if (fTmp >= 0.0f)
                    {
                        fT = 0.0f;
                        float fSqrDist = fA00 + 2.0 * fB0 + fC;
                        return fabsf(fSqrDist);
                    }
                    else if (-fTmp >= fA11)
                    {
                        fT = 1.0f;
                        float fSqrDist = fA00 + fA11 + fC + 2.0 * (fA01 + fB0 + fB1);
                        return fabsf(fSqrDist);
                    }
                    else
                    {
                        fT = -fTmp / fA11;
                        float fSqrDist = fA00 + fTmp * fT + 2.0 * fB0 + fC;
                        return fabsf(fSqrDist);
                    }
                }
            }
        }
    }
    OriginDirectionPair kSeg;
    kSeg.Origin() = kPgm.m_kStartPoint;
    if (fA00 >= fA11)
    {
        kSeg.m_kLightVector = kPgm.m_kPoint1;
        fT = 0.0f;
        return DistanceSquaredToSegment(kPnt, kSeg, fS);
    }
    else
    {
        kSeg.m_kLightVector = kPgm.m_kPoint2;
        fS = 0.0f;
        return DistanceSquaredToSegment(kPnt, kSeg, fT);
    }
}

extern double DAT_01012060;
struct S00eb50f0_Seg
{
    BoxVec3 origin;
    BoxVec3 dir;
};

static inline float& S00eb50f0_At(BoxVec3& v, int i)
{
    return (&v.x)[i];
}
static inline const float& S00eb50f0_At(const BoxVec3& v, int i)
{
    return (&v.x)[i];
}
static inline const float& S00eb50f0_Ext(const OrientedBox& b, int i)
{
    return (&b.extent0)[i];
}

static inline BoxVec3 S00eb50f0_Sub(const BoxVec3& a, const BoxVec3& b)
{
    BoxVec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}
static inline float S00eb50f0_Dot(const BoxVec3& a, const BoxVec3& b)
{
    return b.x * a.x + b.y * a.y + b.z * a.z;
}

struct SArg1
{
    int value;
};
static inline SArg1 MakeSArg1(int x)
{
    SArg1 r = {x};
    return r;
}
// src: GAMEBRYO_LIB 0x00eb4590
static void Face_00eb4590(const OrientedBox& rkBox, SArg1 arg1, int i1, int i2, BoxVec3& rkPnt, const BoxVec3& rkDir,
                         const BoxVec3& rkPmE, float& rfLParam, float& rfSqrDistance)
{
    int i0 = arg1.value;
    BoxVec3 kPpE;
    float fLSqr, fInv, fTmp, fParam, fT, fTimeSinceScaleStart;

    S00eb50f0_At(kPpE, i1) = S00eb50f0_At(rkPnt, i1) + S00eb50f0_Ext(rkBox, i1);
    S00eb50f0_At(kPpE, i2) = S00eb50f0_At(rkPnt, i2) + S00eb50f0_Ext(rkBox, i2);
    if (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(kPpE, i1) >= S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkPmE, i0))
    {
        if (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(kPpE, i2) >= S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkPmE, i0))
        {
            S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
            fInv = 1.0f / S00eb50f0_At(rkDir, i0);
            S00eb50f0_At(rkPnt, i1) -= S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkPmE, i0) * fInv;
            S00eb50f0_At(rkPnt, i2) -= S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkPmE, i0) * fInv;
            rfLParam = -S00eb50f0_At(rkPmE, i0) * fInv;
        }
        else
        {
            fLSqr =
                S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkDir, i0) + S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkDir, i2);
            fTmp = fLSqr * S00eb50f0_At(kPpE, i1) -
                   S00eb50f0_At(rkDir, i1) * (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                              S00eb50f0_At(rkDir, i2) * S00eb50f0_At(kPpE, i2));
            if (fTmp <= 2.0f * fLSqr * S00eb50f0_Ext(rkBox, i1))
            {
                fT = fTmp / fLSqr;
                fLSqr += S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1);
                fTmp = S00eb50f0_At(kPpE, i1) - fT;
                fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                       S00eb50f0_At(rkDir, i1) * fTmp +
                                       S00eb50f0_At(rkDir, i2) * S00eb50f0_At(kPpE, i2);
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) + fTmp * fTmp +
                                 S00eb50f0_At(kPpE, i2) * S00eb50f0_At(kPpE, i2) + fTimeSinceScaleStart * fParam;
                rfLParam = fParam;
                S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                S00eb50f0_At(rkPnt, i1) = fT - S00eb50f0_Ext(rkBox, i1);
                S00eb50f0_At(rkPnt, i2) = -S00eb50f0_Ext(rkBox, i2);
            }
            else
            {
                fLSqr += S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1);
                fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                       S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkPmE, i1) +
                                       S00eb50f0_At(rkDir, i2) * S00eb50f0_At(kPpE, i2);
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) +
                                 S00eb50f0_At(rkPmE, i1) * S00eb50f0_At(rkPmE, i1) +
                                 S00eb50f0_At(kPpE, i2) * S00eb50f0_At(kPpE, i2) + fTimeSinceScaleStart * fParam;
                rfLParam = fParam;
                S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                S00eb50f0_At(rkPnt, i1) = S00eb50f0_Ext(rkBox, i1);
                S00eb50f0_At(rkPnt, i2) = -S00eb50f0_Ext(rkBox, i2);
            }
        }
    }
    else
    {
        if (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(kPpE, i2) >= S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkPmE, i0))
        {
            fLSqr =
                S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkDir, i0) + S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1);
            fTmp = fLSqr * S00eb50f0_At(kPpE, i2) -
                   S00eb50f0_At(rkDir, i2) * (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                              S00eb50f0_At(rkDir, i1) * S00eb50f0_At(kPpE, i1));
            if (fTmp <= 2.0f * fLSqr * S00eb50f0_Ext(rkBox, i2))
            {
                fT = fTmp / fLSqr;
                fLSqr += S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkDir, i2);
                fTmp = S00eb50f0_At(kPpE, i2) - fT;
                fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                       S00eb50f0_At(rkDir, i1) * S00eb50f0_At(kPpE, i1) +
                                       S00eb50f0_At(rkDir, i2) * fTmp;
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) +
                                 S00eb50f0_At(kPpE, i1) * S00eb50f0_At(kPpE, i1) + fTmp * fTmp +
                                 fTimeSinceScaleStart * fParam;
                rfLParam = fParam;
                S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                S00eb50f0_At(rkPnt, i1) = -S00eb50f0_Ext(rkBox, i1);
                S00eb50f0_At(rkPnt, i2) = fT - S00eb50f0_Ext(rkBox, i2);
            }
            else
            {
                fLSqr += S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkDir, i2);
                fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                       S00eb50f0_At(rkDir, i1) * S00eb50f0_At(kPpE, i1) +
                                       S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkPmE, i2);
                fParam = -fTimeSinceScaleStart / fLSqr;
                rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) +
                                 S00eb50f0_At(kPpE, i1) * S00eb50f0_At(kPpE, i1) +
                                 S00eb50f0_At(rkPmE, i2) * S00eb50f0_At(rkPmE, i2) + fTimeSinceScaleStart * fParam;
                rfLParam = fParam;
                S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                S00eb50f0_At(rkPnt, i1) = -S00eb50f0_Ext(rkBox, i1);
                S00eb50f0_At(rkPnt, i2) = S00eb50f0_Ext(rkBox, i2);
            }
        }
        else
        {
            fLSqr =
                S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkDir, i0) + S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkDir, i2);
            fTmp = fLSqr * S00eb50f0_At(kPpE, i1) -
                   S00eb50f0_At(rkDir, i1) * (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                              S00eb50f0_At(rkDir, i2) * S00eb50f0_At(kPpE, i2));
            if (fTmp >= 0.0f)
            {
                if (fTmp <= 2.0f * fLSqr * S00eb50f0_Ext(rkBox, i1))
                {
                    fT = fTmp / fLSqr;
                    fLSqr += S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1);
                    fTmp = S00eb50f0_At(kPpE, i1) - fT;
                    fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                           S00eb50f0_At(rkDir, i1) * fTmp +
                                           S00eb50f0_At(rkDir, i2) * S00eb50f0_At(kPpE, i2);
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) + fTmp * fTmp +
                                     S00eb50f0_At(kPpE, i2) * S00eb50f0_At(kPpE, i2) + fTimeSinceScaleStart * fParam;
                    rfLParam = fParam;
                    S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                    S00eb50f0_At(rkPnt, i1) = fT - S00eb50f0_Ext(rkBox, i1);
                    S00eb50f0_At(rkPnt, i2) = -S00eb50f0_Ext(rkBox, i2);
                }
                else
                {
                    fLSqr += S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1);
                    fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                           S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkPmE, i1) +
                                           S00eb50f0_At(rkDir, i2) * S00eb50f0_At(kPpE, i2);
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) +
                                     S00eb50f0_At(rkPmE, i1) * S00eb50f0_At(rkPmE, i1) +
                                     S00eb50f0_At(kPpE, i2) * S00eb50f0_At(kPpE, i2) + fTimeSinceScaleStart * fParam;
                    rfLParam = fParam;
                    S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                    S00eb50f0_At(rkPnt, i1) = S00eb50f0_Ext(rkBox, i1);
                    S00eb50f0_At(rkPnt, i2) = -S00eb50f0_Ext(rkBox, i2);
                }
                return;
            }
            fLSqr =
                S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkDir, i0) + S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1);
            fTmp = fLSqr * S00eb50f0_At(kPpE, i2) -
                   S00eb50f0_At(rkDir, i2) * (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                              S00eb50f0_At(rkDir, i1) * S00eb50f0_At(kPpE, i1));
            if (fTmp >= 0.0f)
            {
                if (fTmp <= 2.0f * fLSqr * S00eb50f0_Ext(rkBox, i2))
                {
                    fT = fTmp / fLSqr;
                    fLSqr += S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkDir, i2);
                    fTmp = S00eb50f0_At(kPpE, i2) - fT;
                    fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                           S00eb50f0_At(rkDir, i1) * S00eb50f0_At(kPpE, i1) +
                                           S00eb50f0_At(rkDir, i2) * fTmp;
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) +
                                     S00eb50f0_At(kPpE, i1) * S00eb50f0_At(kPpE, i1) + fTmp * fTmp +
                                     fTimeSinceScaleStart * fParam;
                    rfLParam = fParam;
                    S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                    S00eb50f0_At(rkPnt, i1) = -S00eb50f0_Ext(rkBox, i1);
                    S00eb50f0_At(rkPnt, i2) = fT - S00eb50f0_Ext(rkBox, i2);
                }
                else
                {
                    fLSqr += S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkDir, i2);
                    fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                           S00eb50f0_At(rkDir, i1) * S00eb50f0_At(kPpE, i1) +
                                           S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkPmE, i2);
                    fParam = -fTimeSinceScaleStart / fLSqr;
                    rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) +
                                     S00eb50f0_At(kPpE, i1) * S00eb50f0_At(kPpE, i1) +
                                     S00eb50f0_At(rkPmE, i2) * S00eb50f0_At(rkPmE, i2) + fTimeSinceScaleStart * fParam;
                    rfLParam = fParam;
                    S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
                    S00eb50f0_At(rkPnt, i1) = -S00eb50f0_Ext(rkBox, i1);
                    S00eb50f0_At(rkPnt, i2) = S00eb50f0_Ext(rkBox, i2);
                }
                return;
            }
            fLSqr += S00eb50f0_At(rkDir, i2) * S00eb50f0_At(rkDir, i2);
            fTimeSinceScaleStart = S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkPmE, i0) +
                                   S00eb50f0_At(rkDir, i1) * S00eb50f0_At(kPpE, i1) +
                                   S00eb50f0_At(rkDir, i2) * S00eb50f0_At(kPpE, i2);
            fParam = -fTimeSinceScaleStart / fLSqr;
            rfSqrDistance += S00eb50f0_At(rkPmE, i0) * S00eb50f0_At(rkPmE, i0) +
                             S00eb50f0_At(kPpE, i1) * S00eb50f0_At(kPpE, i1) +
                             S00eb50f0_At(kPpE, i2) * S00eb50f0_At(kPpE, i2) + fTimeSinceScaleStart * fParam;
            rfLParam = fParam;
            S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
            S00eb50f0_At(rkPnt, i1) = -S00eb50f0_Ext(rkBox, i1);
            S00eb50f0_At(rkPnt, i2) = -S00eb50f0_Ext(rkBox, i2);
        }
    }
}

struct PointArg
{
    BoxVec3* p;
};
struct DirArg
{
    const BoxVec3* p;
};
// src: GAMEBRYO_LIB 0x00eb4cd0
static void CaseNoZeros(const OrientedBox& rkBox, PointArg pArg, DirArg dArg, float& rfLParam, float& rfSqrDistance)
{
    BoxVec3& rkPnt = *pArg.p;
    const BoxVec3& rkDir = *dArg.p;
    BoxVec3 kPmE;
    kPmE.x = rkPnt.x - rkBox.extent0;
    kPmE.y = rkPnt.y - rkBox.extent1;
    kPmE.z = rkPnt.z - rkBox.extent2;

    float fProdDxPy = rkDir.x * kPmE.y;
    float fProdDyPx = rkDir.y * kPmE.x;
    float fProdDzPx, fProdDxPz, fProdDzPy, fProdDyPz;

    if (fProdDyPx >= fProdDxPy)
    {
        fProdDzPx = rkDir.z * kPmE.x;
        fProdDxPz = rkDir.x * kPmE.z;
        if (fProdDzPx >= fProdDxPz)
            Face_00eb4590(rkBox, MakeSArg1(0), 1, 2, rkPnt, rkDir, kPmE, rfLParam, rfSqrDistance);
        else
            Face_00eb4590(rkBox, MakeSArg1(2), 0, 1, rkPnt, rkDir, kPmE, rfLParam, rfSqrDistance);
    }
    else
    {
        fProdDzPy = rkDir.z * kPmE.y;
        fProdDyPz = rkDir.y * kPmE.z;
        if (fProdDzPy >= fProdDyPz)
            Face_00eb4590(rkBox, MakeSArg1(1), 2, 0, rkPnt, rkDir, kPmE, rfLParam, rfSqrDistance);
        else
            Face_00eb4590(rkBox, MakeSArg1(2), 0, 1, rkPnt, rkDir, kPmE, rfLParam, rfSqrDistance);
    }
}

// src: GAMEBRYO_LIB 0x00eb4de0
static void Case0(const OrientedBox& rkBox, int i0, int i1, int i2, BoxVec3& rkPnt, const BoxVec3& rkDir,
                         float& rfLParam, float& rfSqrDistance)
{
    float fPmE0 = S00eb50f0_At(rkPnt, i0) - S00eb50f0_Ext(rkBox, i0);
    float fPmE1 = S00eb50f0_At(rkPnt, i1) - S00eb50f0_Ext(rkBox, i1);
    float fProd0 = S00eb50f0_At(rkDir, i1) * fPmE0;
    float fProd1 = S00eb50f0_At(rkDir, i0) * fPmE1;
    float fTimeSinceScaleStart, fInvLSqr, fInv;

    if (fProd0 >= fProd1)
    {
        S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);
        float fPpE1 = S00eb50f0_At(rkPnt, i1) + S00eb50f0_Ext(rkBox, i1);
        fTimeSinceScaleStart = fProd0 - S00eb50f0_At(rkDir, i0) * fPpE1;
        if (fTimeSinceScaleStart >= 0.0f)
        {
            fInvLSqr = 1.0f / (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkDir, i0) +
                               S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1));
            rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart * fInvLSqr;
            {
                S00eb50f0_At(rkPnt, i1) = -S00eb50f0_Ext(rkBox, i1);
                rfLParam = -(S00eb50f0_At(rkDir, i0) * fPmE0 + S00eb50f0_At(rkDir, i1) * fPpE1) * fInvLSqr;
            }
        }
        else
        {
            {
                fInv = 1.0f / S00eb50f0_At(rkDir, i0);
                S00eb50f0_At(rkPnt, i1) -= fProd0 * fInv;
                rfLParam = -fPmE0 * fInv;
            }
        }
    }
    else
    {
        S00eb50f0_At(rkPnt, i1) = S00eb50f0_Ext(rkBox, i1);
        float fPpE0 = S00eb50f0_At(rkPnt, i0) + S00eb50f0_Ext(rkBox, i0);
        fTimeSinceScaleStart = fProd1 - S00eb50f0_At(rkDir, i1) * fPpE0;
        if (fTimeSinceScaleStart >= 0.0f)
        {
            fInvLSqr = 1.0f / (S00eb50f0_At(rkDir, i0) * S00eb50f0_At(rkDir, i0) +
                               S00eb50f0_At(rkDir, i1) * S00eb50f0_At(rkDir, i1));
            rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart * fInvLSqr;
            {
                S00eb50f0_At(rkPnt, i0) = -S00eb50f0_Ext(rkBox, i0);
                rfLParam = -(S00eb50f0_At(rkDir, i0) * fPpE0 + S00eb50f0_At(rkDir, i1) * fPmE1) * fInvLSqr;
            }
        }
        else
        {
            {
                fInv = 1.0f / S00eb50f0_At(rkDir, i1);
                S00eb50f0_At(rkPnt, i0) -= fProd1 * fInv;
                rfLParam = -fPmE1 * fInv;
            }
        }
    }

    if (S00eb50f0_At(rkPnt, i2) < -S00eb50f0_Ext(rkBox, i2))
    {
        fTimeSinceScaleStart = S00eb50f0_At(rkPnt, i2) + S00eb50f0_Ext(rkBox, i2);
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        S00eb50f0_At(rkPnt, i2) = -S00eb50f0_Ext(rkBox, i2);
    }
    else if (S00eb50f0_At(rkPnt, i2) > S00eb50f0_Ext(rkBox, i2))
    {
        fTimeSinceScaleStart = S00eb50f0_At(rkPnt, i2) - S00eb50f0_Ext(rkBox, i2);
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        S00eb50f0_At(rkPnt, i2) = S00eb50f0_Ext(rkBox, i2);
    }
}

// src: GAMEBRYO_LIB 0x00eb5010
static void Case00(const OrientedBox& rkBox, int i0, int i1, int i2, BoxVec3& rkPnt, const BoxVec3& rkDir,
                         float& rfLParam, float& rfSqrDistance)
{
    float fTimeSinceScaleStart;

    rfLParam = (S00eb50f0_Ext(rkBox, i0) - S00eb50f0_At(rkPnt, i0)) / S00eb50f0_At(rkDir, i0);

    S00eb50f0_At(rkPnt, i0) = S00eb50f0_Ext(rkBox, i0);

    if (S00eb50f0_At(rkPnt, i1) < -S00eb50f0_Ext(rkBox, i1))
    {
        fTimeSinceScaleStart = S00eb50f0_At(rkPnt, i1) + S00eb50f0_Ext(rkBox, i1);
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        S00eb50f0_At(rkPnt, i1) = -S00eb50f0_Ext(rkBox, i1);
    }
    else if (S00eb50f0_At(rkPnt, i1) > S00eb50f0_Ext(rkBox, i1))
    {
        fTimeSinceScaleStart = S00eb50f0_At(rkPnt, i1) - S00eb50f0_Ext(rkBox, i1);
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        S00eb50f0_At(rkPnt, i1) = S00eb50f0_Ext(rkBox, i1);
    }

    if (S00eb50f0_At(rkPnt, i2) < -S00eb50f0_Ext(rkBox, i2))
    {
        fTimeSinceScaleStart = S00eb50f0_At(rkPnt, i2) + S00eb50f0_Ext(rkBox, i2);
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        S00eb50f0_At(rkPnt, i2) = -S00eb50f0_Ext(rkBox, i2);
    }
    else if (S00eb50f0_At(rkPnt, i2) > S00eb50f0_Ext(rkBox, i2))
    {
        fTimeSinceScaleStart = S00eb50f0_At(rkPnt, i2) - S00eb50f0_Ext(rkBox, i2);
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        S00eb50f0_At(rkPnt, i2) = S00eb50f0_Ext(rkBox, i2);
    }
}

static void ClampPointToBox(const OrientedBox& rkBox, BoxVec3& rkPnt, float& rfSqrDistance)
{
    float fTimeSinceScaleStart;

    if (rkPnt.x < -rkBox.extent0)
    {
        fTimeSinceScaleStart = rkPnt.x + rkBox.extent0;
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt.x = -rkBox.extent0;
    }
    else if (rkPnt.x > rkBox.extent0)
    {
        fTimeSinceScaleStart = rkPnt.x - rkBox.extent0;
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt.x = rkBox.extent0;
    }

    if (rkPnt.y < -rkBox.extent1)
    {
        fTimeSinceScaleStart = rkPnt.y + rkBox.extent1;
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt.y = -rkBox.extent1;
    }
    else if (rkPnt.y > rkBox.extent1)
    {
        fTimeSinceScaleStart = rkPnt.y - rkBox.extent1;
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt.y = rkBox.extent1;
    }

    if (rkPnt.z < -rkBox.extent2)
    {
        fTimeSinceScaleStart = rkPnt.z + rkBox.extent2;
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt.z = -rkBox.extent2;
    }
    else if (rkPnt.z > rkBox.extent2)
    {
        fTimeSinceScaleStart = rkPnt.z - rkBox.extent2;
        rfSqrDistance += fTimeSinceScaleStart * fTimeSinceScaleStart;
        rkPnt.z = rkBox.extent2;
    }
}

// Moves the segment into the box frame, finds the squared distance from it to the box, writes segment and box parameters through the pointers, and returns it.
// @fnv 0x00eb50f0
// src: GAMEBRYO_LIB 0x00eb50f0
float __cdecl NiSqrDistance_Compute_00eb50f0(const S00eb50f0_Seg* apSegment, const OrientedBox* box, float* pfLParam, float* pfBParam0,
                           float* pfBParam1, float* pfBParam2)
{
    BoxVec3 kDiff = S00eb50f0_Sub(apSegment->origin, box->center);
    BoxVec3 kPnt;
    kPnt.x = S00eb50f0_Dot(box->axis0, kDiff);
    kPnt.y = S00eb50f0_Dot(box->axis1, kDiff);
    kPnt.z = S00eb50f0_Dot(kDiff, box->axis2);
    bool bReflect[3];
    int i;
    float fSqrDistance;
    {
        BoxVec3 kWorldPosition;
        kWorldPosition.x = S00eb50f0_Dot(box->axis0, apSegment->dir);
        kWorldPosition.y = S00eb50f0_Dot(box->axis1, apSegment->dir);
        kWorldPosition.z = S00eb50f0_Dot(box->axis2, apSegment->dir);

        for (i = 0; i < 3; i++)
        {
            if (S00eb50f0_At(kWorldPosition, i) < 0.0f)
            {
                S00eb50f0_At(kPnt, i) = -S00eb50f0_At(kPnt, i);
                S00eb50f0_At(kWorldPosition, i) = -S00eb50f0_At(kWorldPosition, i);
                bReflect[i] = true;
            }
            else
            {
                bReflect[i] = false;
            }
        }

        fSqrDistance = 0.0f;
        *pfLParam = 0.0f;

        if (kWorldPosition.x > 0.0f)
        {
            if (kWorldPosition.y > 0.0f)
            {
                if (kWorldPosition.z > 0.0f)
                {
                    PointArg pa = {&kPnt};
                    DirArg da = {&kWorldPosition};
                    CaseNoZeros(*box, pa, da, *pfLParam, fSqrDistance);
                }
                else
                    Case0(*box, 0, 1, 2, kPnt, kWorldPosition, *pfLParam, fSqrDistance);
            }
            else
            {
                if (kWorldPosition.z > 0.0f)
                    Case0(*box, 0, 2, 1, kPnt, kWorldPosition, *pfLParam, fSqrDistance);
                else
                    Case00(*box, 0, 1, 2, kPnt, kWorldPosition, *pfLParam, fSqrDistance);
            }
        }
        else
        {
            if (kWorldPosition.y > 0.0f)
            {
                if (kWorldPosition.z > 0.0f)
                    Case0(*box, 1, 2, 0, kPnt, kWorldPosition, *pfLParam, fSqrDistance);
                else
                    Case00(*box, 1, 0, 2, kPnt, kWorldPosition, *pfLParam, fSqrDistance);
            }
            else
            {
                if (kWorldPosition.z > 0.0f)
                    Case00(*box, 2, 0, 1, kPnt, kWorldPosition, *pfLParam, fSqrDistance);
                else
                    ClampPointToBox(*box, kPnt, fSqrDistance);
            }
        }
    }

    if (*pfLParam >= DAT_01012060)
    {
        if (*pfLParam <= 1.0f)
        {
            for (i = 0; i < 3; i++)
            {
                if (bReflect[i])
                    S00eb50f0_At(kPnt, i) = -S00eb50f0_At(kPnt, i);
            }
            *pfBParam0 = kPnt.x;
            *pfBParam1 = kPnt.y;
            *pfBParam2 = kPnt.z;
        }
        else
        {
            *pfLParam = 1.0f;
            BoxVec3 kEnd;
            kEnd.x = apSegment->origin.x + apSegment->dir.x;
            kEnd.y = apSegment->origin.y + apSegment->dir.y;
            kEnd.z = apSegment->origin.z + apSegment->dir.z;
            fSqrDistance = GetSqrDistanceToOrientedBox(&kEnd, box, pfBParam0, pfBParam1, pfBParam2);
        }
    }
    else
    {
        *pfLParam = 0.0f;
        fSqrDistance = GetSqrDistanceToOrientedBox(&apSegment->origin, box, pfBParam0, pfBParam1, pfBParam2);
    }
    return fSqrDistance;
}

class PortPoint
{
  public:
    float x, y, z;
    PortPoint()
    {}
    PortPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    const float& operator[](int i) const
    {
        const float* base = &x;
        return (float&)base[i];
    }
    float& operator[](int i)
    {
        float* base = &x;
        return (float&)base[i];
    }
};
class PortBox
{
  public:
    PortPoint center, axis[3];
    float m_afExtents[3];
};

// For axis order i0,i1,i2, moves origin to a box point and updates lineParam and sqrDistance from direction, PmE and the box extents.
// @fnv 0x00eb4590
// src: GAMEBRYO_LIB 0x00eb4590
static __declspec(noinline) void Face_00eb4590(const PortBox& box, int aiAxis0, int aiAxis1, int aiAxis2,
                                              PortPoint& origin, const PortPoint& direction, const PortPoint& PmE,
                                              float& lineParam, float& sqrDistance)
{

    float inv;
    PortPoint PpE;
    PpE[aiAxis1] = origin[aiAxis1] + box.m_afExtents[aiAxis1];
    PpE[aiAxis2] = origin[aiAxis2] + box.m_afExtents[aiAxis2];

    float lenSqr, tmp, t, delta, param;
    if (direction[aiAxis0] * PpE[aiAxis1] >= direction[aiAxis1] * PmE[aiAxis0])
    {
        if (direction[aiAxis0] * PpE[aiAxis2] >= direction[aiAxis2] * PmE[aiAxis0])
        {
            origin[aiAxis0] = box.m_afExtents[aiAxis0];
            inv = 1.0f / direction[aiAxis0];
            origin[aiAxis1] -= direction[aiAxis1] * PmE[aiAxis0] * inv;
            origin[aiAxis2] -= direction[aiAxis2] * PmE[aiAxis0] * inv;
            lineParam = -PmE[aiAxis0] * inv;
        }
        else
        {
            lenSqr = direction[aiAxis0] * direction[aiAxis0] + direction[aiAxis2] * direction[aiAxis2];
            tmp = lenSqr * PpE[aiAxis1] -
                  direction[aiAxis1] * (direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis2] * PpE[aiAxis2]);
            if (tmp <= 2.0f * lenSqr * box.m_afExtents[aiAxis1])
            {
                t = tmp / lenSqr;
                lenSqr += direction[aiAxis1] * direction[aiAxis1];
                tmp = PpE[aiAxis1] - t;
                delta =
                    direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * tmp + direction[aiAxis2] * PpE[aiAxis2];
                param = -delta / lenSqr;
                sqrDistance += PmE[aiAxis0] * PmE[aiAxis0] + tmp * tmp + PpE[aiAxis2] * PpE[aiAxis2] + delta * param;
                lineParam = param;
                origin[aiAxis0] = box.m_afExtents[aiAxis0];
                origin[aiAxis1] = t - box.m_afExtents[aiAxis1];
                origin[aiAxis2] = -box.m_afExtents[aiAxis2];
            }
            else
            {
                lenSqr += direction[aiAxis1] * direction[aiAxis1];
                delta = direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PmE[aiAxis1] +
                        direction[aiAxis2] * PpE[aiAxis2];
                param = -delta / lenSqr;
                sqrDistance += PmE[aiAxis0] * PmE[aiAxis0] + PmE[aiAxis1] * PmE[aiAxis1] + PpE[aiAxis2] * PpE[aiAxis2] +
                               delta * param;
                lineParam = param;
                origin[aiAxis0] = box.m_afExtents[aiAxis0];
                origin[aiAxis1] = box.m_afExtents[aiAxis1];
                origin[aiAxis2] = -box.m_afExtents[aiAxis2];
            }
        }
    }
    else
    {
        if (direction[aiAxis0] * PpE[aiAxis2] >= direction[aiAxis2] * PmE[aiAxis0])
        {
            lenSqr = direction[aiAxis0] * direction[aiAxis0] + direction[aiAxis1] * direction[aiAxis1];
            tmp = lenSqr * PpE[aiAxis2] -
                  direction[aiAxis2] * (direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PpE[aiAxis1]);
            if (tmp <= 2.0f * lenSqr * box.m_afExtents[aiAxis2])
            {
                t = tmp / lenSqr;
                lenSqr += direction[aiAxis2] * direction[aiAxis2];
                tmp = PpE[aiAxis2] - t;
                delta =
                    direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PpE[aiAxis1] + direction[aiAxis2] * tmp;
                param = -delta / lenSqr;
                sqrDistance += PmE[aiAxis0] * PmE[aiAxis0] + PpE[aiAxis1] * PpE[aiAxis1] + tmp * tmp + delta * param;
                lineParam = param;
                origin[aiAxis0] = box.m_afExtents[aiAxis0];
                origin[aiAxis1] = -box.m_afExtents[aiAxis1];
                origin[aiAxis2] = t - box.m_afExtents[aiAxis2];
            }
            else
            {
                lenSqr += direction[aiAxis2] * direction[aiAxis2];
                delta = direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PpE[aiAxis1] +
                        ((const PortPoint&)direction)[aiAxis2] * PmE[aiAxis2];
                param = -delta / lenSqr;
                sqrDistance += PmE[aiAxis0] * PmE[aiAxis0] + PpE[aiAxis1] * PpE[aiAxis1] + PmE[aiAxis2] * PmE[aiAxis2] +
                               delta * param;
                lineParam = param;
                origin[aiAxis0] = box.m_afExtents[aiAxis0];
                origin[aiAxis1] = -box.m_afExtents[aiAxis1];
                origin[aiAxis2] = box.m_afExtents[aiAxis2];
            }
        }
        else
        {
            lenSqr = direction[aiAxis0] * direction[aiAxis0] + direction[aiAxis2] * direction[aiAxis2];
            tmp = lenSqr * PpE[aiAxis1] -
                  direction[aiAxis1] * (direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis2] * PpE[aiAxis2]);
            if (tmp >= 0.0f)
            {
                if (tmp <= 2.0f * lenSqr * box.m_afExtents[aiAxis1])
                {
                    t = tmp / lenSqr;
                    lenSqr += direction[aiAxis1] * direction[aiAxis1];
                    tmp = PpE[aiAxis1] - t;
                    delta = direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * tmp +
                            direction[aiAxis2] * PpE[aiAxis2];
                    param = -delta / lenSqr;
                    sqrDistance +=
                        PmE[aiAxis0] * PmE[aiAxis0] + tmp * tmp + PpE[aiAxis2] * PpE[aiAxis2] + delta * param;
                    lineParam = param;
                    origin[aiAxis0] = box.m_afExtents[aiAxis0];
                    origin[aiAxis1] = t - box.m_afExtents[aiAxis1];
                    origin[aiAxis2] = -box.m_afExtents[aiAxis2];
                }
                else
                {
                    lenSqr += direction[aiAxis1] * direction[aiAxis1];
                    delta = direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PmE[aiAxis1] +
                            direction[aiAxis2] * PpE[aiAxis2];
                    param = -delta / lenSqr;
                    sqrDistance += PmE[aiAxis0] * PmE[aiAxis0] + PmE[aiAxis1] * PmE[aiAxis1] +
                                   PpE[aiAxis2] * PpE[aiAxis2] + delta * param;
                    lineParam = param;
                    origin[aiAxis0] = box.m_afExtents[aiAxis0];
                    origin[aiAxis1] = box.m_afExtents[aiAxis1];
                    origin[aiAxis2] = -box.m_afExtents[aiAxis2];
                }
                return;
            }
            lenSqr = direction[aiAxis0] * direction[aiAxis0] + direction[aiAxis1] * direction[aiAxis1];
            tmp = lenSqr * PpE[aiAxis2] -
                  direction[aiAxis2] * (direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PpE[aiAxis1]);
            if (tmp >= 0.0f)
            {
                if (tmp <= 2.0f * lenSqr * box.m_afExtents[aiAxis2])
                {
                    t = tmp / lenSqr;
                    lenSqr += direction[aiAxis2] * direction[aiAxis2];
                    tmp = PpE[aiAxis2] - t;
                    delta = direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PpE[aiAxis1] +
                            direction[aiAxis2] * tmp;
                    param = -delta / lenSqr;
                    sqrDistance +=
                        PmE[aiAxis0] * PmE[aiAxis0] + PpE[aiAxis1] * PpE[aiAxis1] + tmp * tmp + delta * param;
                    lineParam = param;
                    origin[aiAxis0] = box.m_afExtents[aiAxis0];
                    origin[aiAxis1] = -box.m_afExtents[aiAxis1];
                    origin[aiAxis2] = t - box.m_afExtents[aiAxis2];
                }
                else
                {
                    lenSqr += direction[aiAxis2] * direction[aiAxis2];
                    delta = direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PpE[aiAxis1] +
                            ((const PortPoint&)direction)[aiAxis2] * PmE[aiAxis2];
                    param = -delta / lenSqr;
                    sqrDistance += PmE[aiAxis0] * PmE[aiAxis0] + PpE[aiAxis1] * PpE[aiAxis1] +
                                   PmE[aiAxis2] * PmE[aiAxis2] + delta * param;
                    lineParam = param;
                    origin[aiAxis0] = box.m_afExtents[aiAxis0];
                    origin[aiAxis1] = -box.m_afExtents[aiAxis1];
                    origin[aiAxis2] = box.m_afExtents[aiAxis2];
                }
                return;
            }
            lenSqr += direction[aiAxis2] * direction[aiAxis2];
            delta = direction[aiAxis0] * PmE[aiAxis0] + direction[aiAxis1] * PpE[aiAxis1] +
                    direction[aiAxis2] * PpE[aiAxis2];
            param = -delta / lenSqr;
            sqrDistance +=
                PmE[aiAxis0] * PmE[aiAxis0] + PpE[aiAxis1] * PpE[aiAxis1] + PpE[aiAxis2] * PpE[aiAxis2] + delta * param;
            lineParam = param;
            origin[aiAxis0] = box.m_afExtents[aiAxis0];
            origin[aiAxis1] = -box.m_afExtents[aiAxis1];
            origin[aiAxis2] = -box.m_afExtents[aiAxis2];
        }
    }
}
extern "C" __declspec(noinline) void face_public_entry(const PortBox* box, int axis0, int axis1, int axis2,
                                                       PortPoint* origin, const PortPoint* direction,
                                                       const PortPoint* difference, float* line, float* distance)
{
    Face_00eb4590(*box, axis0, axis1, axis2, *origin, *(const PortPoint*)direction, *difference, *line, *distance);
}

namespace fltmax_eb3750 {
static float DAT_010f1ad0 = 3.402823466e+38f;
}

struct FloatVec3Local
{
    float x;
    float y;
    float z;
};

class SpawnedBase
{
  public:
    virtual void Update();
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
    int m_30;
    int m_34;
    SpawnedBase(float a, float b, float c, void* d);
};

class FUN_00eb3750 : public SpawnedBase
{
  public:
    float* m_38;
    FloatVec3Local m_3c;
    FloatVec3Local m_48;
    FloatVec3Local m_54;
    float m_60;
    float m_64;
    float m_68;
    FUN_00eb3750(float* a1, FloatVec3Local* a2, FloatVec3Local* a3, FloatVec3Local* a4, float a5, float a6, float a7,
                 void* a8);
};

// Stores a1 and *a2, stores a3-a2 and a4-a2, sets m_60 to 1/(a1[14]*a1[14]) and sets m_64 and m_68 to the float max constant.
// @fnv 0x00eb3750
FUN_00eb3750::FUN_00eb3750(float* apFloats, FloatVec3Local* apVecA, FloatVec3Local* apVecB, FloatVec3Local* apVecC,
                           float a5, float a6, float a7, void* a8)
    : SpawnedBase(a5, a6, a7, a8)
{
    m_38 = apFloats;
    m_3c = *apVecA;
    {
        FloatVec3Local d;
        d.x = apVecB->x - apVecA->x;
        d.y = apVecB->y - apVecA->y;
        d.z = apVecB->z - apVecA->z;
        m_48 = d;
    }
    {
        FloatVec3Local d;
        d.x = apVecC->x - apVecA->x;
        d.y = apVecC->y - apVecA->y;
        d.z = apVecC->z - apVecA->z;
        m_54 = d;
    }
    m_60 = 1.0f / (apFloats[14] * apFloats[14]);
    m_68 = m_64 = fltmax_eb3750::DAT_010f1ad0;
}

extern NiPoint3 DAT_011a9490;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 DAT_011a946c;
extern NiPoint3 DAT_011a9478;
extern NiPoint3 DAT_011a9484;

class Helper
{
  public:
    NiBoundingVolume* __thiscall FUN_00ea0820(const NiPoint3& akExtents, const NiPoint3& akCenter,
                                              const NiPoint3& akAxis0, const NiPoint3& akAxis1,
                                              const NiPoint3& akAxis2);
};

struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int auiSize);
};

// Allocates 0x40 bytes, builds a NiBoundingVolume via FUN_00ea0820 from five global NiPoint3 values, calls LoadBinary(apStream) and returns it.
// @fnv 0x00ea7490
// src: COMMUNITY 0x00ea7490
NiBoundingVolume* __cdecl NiRegisterBVStream(void* apStream)
{
    Helper* pkHelper = (Helper*)((MemoryManagerAllocHelper*)&_g_memoryManager)->Allocate(0x40);
    NiBoundingVolume* pkVolume =
        pkHelper ? pkHelper->FUN_00ea0820(DAT_011a9490, DAT_011f426c, DAT_011a946c, DAT_011a9478, DAT_011a9484) : 0;
    pkVolume->LoadBinary(*static_cast<NiStream*>(apStream));
    return pkVolume;
}
