#include "../../../../include/NiBoxBV.h"
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
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
#include "../../../../include/NiPoint3.h"
#include <stddef.h>
// This unit needs the constructor-enabled Point3 definition. Include the
// standard header first, then mask the legacy aggregate-only version test.
#pragma push_macro("_MSC_VER")
#undef _MSC_VER
// PodPoint3: unit-local copy of the former shared stand-in Point3. Same layout as NiPoint3 but constructor-free (an aggregate under VC9): with NiPoint3, 0x00ea0ad0 does not match (POD construction/return; NiPoint3's user constructors change the code).
#include <stddef.h>
class PodPoint3
{
public:
    float x;
    float y;
    float z;

    // Legacy compilers require an aggregate for brace initialization.
#if !defined(_MSC_VER) || _MSC_VER >= 1800
    PodPoint3()
    {}
    PodPoint3(float fX, float fY, float fZ)
        : x(fX), y(fY), z(fZ)
    {}
#endif

    PodPoint3 operator+(const PodPoint3& other) const;
    PodPoint3 operator-(const PodPoint3& other) const;
    PodPoint3 operator-() const;
    PodPoint3 operator*(float scalar) const;
    float operator*(const PodPoint3& other) const;
    PodPoint3& operator+=(const PodPoint3& other);
    friend PodPoint3 operator*(float scalar, const PodPoint3& point);

    float DotPart(float value, const PodPoint3& point) const;
    float DotProduct(const PodPoint3& point) const;
    double DotProduct(const PodPoint3& point);
    float Length() const;

    PodPoint3& ScaleComponents(float scalar);
    PodPoint3 FUN_00439e90(const PodPoint3& shift) const;
    PodPoint3* FUN_00439e90(PodPoint3* output, const PodPoint3* other) const;
    PodPoint3 SubtractIntoVector(const PodPoint3& other) const;
    void SubtractIntoVector();
    PodPoint3 FUN_004b3800(const PodPoint3& axis) const;
    void Unitize_004a0c10();
    float FUN_00457910();
    float FUN_00457990() const;
    double FUN_004a7290();
    PodPoint3* FUN_006815c0();
    PodPoint3* SetComponents(float x, float y, float z);
    void FUN_0043d410(float x, int y, int z);
    char* GetViewerString_00a59af0(const char* text);

    static void* operator new[](size_t size);
    static void operator delete[](void* memory);
    static const PodPoint3 ZERO;
};
#pragma pop_macro("_MSC_VER")
#include "../../../../include/NiPoint3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../../../include/NiPoint3.h"
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
#include <string.h>

inline PodPoint3 PodPoint3::operator+(const PodPoint3& pt) const
{
    return PodPoint3(x + pt.x, y + pt.y, z + pt.z);
}

inline PodPoint3 PodPoint3::operator-(const PodPoint3& pt) const
{
    return PodPoint3(x - pt.x, y - pt.y, z - pt.z);
}

inline PodPoint3 PodPoint3::operator*(float fScalar) const
{
    PodPoint3 kRes = PodPoint3(fScalar * x, fScalar * y, fScalar * z);
    return kRes;
}

inline PodPoint3 operator*(float fScalar, const PodPoint3& pt)
{
    return PodPoint3(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z);
}

__forceinline float PodPoint3::DotPart(float v, const PodPoint3& pt) const
{
    return v * pt.x + y * pt.y + z * pt.z;
}

inline float PodPoint3::DotProduct(const PodPoint3& pt) const
{
    return x * pt.x + y * pt.y + z * pt.z;
}

inline PodPoint3 PodPoint3::FUN_004b3800(const PodPoint3& pt) const
{
    return PodPoint3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}

inline LocalVec3::LocalVec3()
{}

inline LocalVec3::LocalVec3(float a, float b, float c) : x(a), y(b), z(c)
{}

inline LocalVec3 LocalVec3::operator-(const LocalVec3& o) const
{
    return LocalVec3(x - o.x, y - o.y, z - o.z);
}

inline LocalVec3 LocalVec3::operator*(float s) const
{
    return LocalVec3(x * s, y * s, z * s);
}

inline float LocalVec3::Dot(const LocalVec3& o) const
{
    return x * o.x + y * o.y + z * o.z;
}

inline bool LocalVec3::operator==(const LocalVec3& o) const
{
    return x == o.x && y == o.y && z == o.z;
}

inline bool LocalVec3::operator!=(const LocalVec3& o) const
{
    return !(*this == o);
}

// src/gamebryo2.2/corelibs/nicollision/niboxbv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niboxbv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Returns the constant value 1.
// @fnv 0x00b6f470
// src: COMMUNITY 0x00b6f470
int __cdecl _return1()
{
    return 1;
}

struct OrientedBoxBound
{
    void __thiscall SaveBinary(NiStream& kStream);
};

// @fnv 0x00ea0800
void __thiscall NiBoxBV::SaveBinary(NiStream& kStream)
{
    NiBoundingVolume::SaveBinary(kStream);
    ((OrientedBoxBound*)((char*)this + 4))->SaveBinary(kStream);
}

struct FakeBox
{
    bool __thiscall HasEqualBoxComponents(const FakeBox&) const;
};
struct StandIn
{
    int __thiscall ProcessAndReturnValue_00ea07a0(const NiBoundingVolume&);
};
// @fnv 0x00ea07a0
// src: GUESS 0x00ea07a0 (confidence: low)
int __thiscall StandIn::ProcessAndReturnValue_00ea07a0(const NiBoundingVolume& kABV)
{
    if (kABV.F3() == 1)
    {
        if (reinterpret_cast<const FakeBox*>(reinterpret_cast<const char*>(&kABV) + 4)
                ->HasEqualBoxComponents(*reinterpret_cast<const FakeBox*>(reinterpret_cast<const char*>(this) + 4)))
            return 1;
    }
    return 0;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern NiPoint3 DAT_011a946c;
extern NiPoint3 DAT_011a9478;
extern const NiPoint3 DAT_011a9484;
extern NiPoint3 DAT_011a9490;
extern NiPoint3 _NiPoint3_ZERO;
struct Helper
{
    NiBoundingVolume* FUN_00ea0820(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);
};
// Allocates 0x40 bytes and, if successful, builds a NiBoundingVolume from five NiPoint3 constants; returns it or null.
// @fnv 0x00ea74f0
NiBoundingVolume* CreateBoundingVolume()
{
    void* p = g_memoryManager.Allocate(0x40);
    if (p != 0)
        return ((Helper*)p)->FUN_00ea0820(DAT_011a9490, _NiPoint3_ZERO, DAT_011a946c, DAT_011a9478, DAT_011a9484);
    return 0;
}

namespace fnv_00ea7d10 {
struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
extern P03MM g_memoryManager;
extern int DAT_010f1814;
// Shared NiBoxBV lacks a Clone override and box storage; retain this local form.
struct FUN_00ea7d10_shell
{
    void* vfptr;
    struct Payload
    {
        int v[15];
    } data;
    NiBoundingVolume* __thiscall Clone();
};
// Allocates a 0x40-byte clone, copies the vfptr and data payload into it, and returns it as a NiBoundingVolume, or returns 0 on failure.
// @fnv 0x00ea7d10
NiBoundingVolume* FUN_00ea7d10_shell::Clone()
{
    FUN_00ea7d10_shell* pkClone = (FUN_00ea7d10_shell*)g_memoryManager.Allocate(0x40);
    if (pkClone)
    {
        pkClone->vfptr = (void*)&DAT_010f1814;
        pkClone->data = data;
        return (NiBoundingVolume*)pkClone;
    }
    return 0;
}
}  // namespace fnv_00ea7d10

extern const float g_011c5aa8_arg1;

inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}

inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
struct Isect
{
    int pad[0x14];
    void __thiscall InitRegion(const void* a, const void* b, float c, float d, float e, int f);
    void __thiscall Solve(const void* a, const void* b);
    float __thiscall NiIntersector_GetContactTime();
    int __thiscall FUN_00be0aa0();
    const NiPoint3& __thiscall NiIntersector_GetContactPoint();
    const NiPoint3& __thiscall NiIntersector_GetContactNormal();
    void __thiscall SetVtbl();
};
// @fnv 0x00ea3950
// src: XBOX_PDB 0x00ea3950
bool NiBoxBV_BoxSphereFindIntersect(float afLength, const void* pA, const void* pB, const void* pC, const void* pD, float* pfTime,
                  NiPoint3* pPoint, bool bNormal, NiPoint3* pNormal, NiPoint3* pNegNormal)
{
    Isect k;
    k.InitRegion(pA, pC, afLength, 0.001f, g_011c5aa8_arg1, 0x20);
    k.Solve(pB, pD);
    *pfTime = k.NiIntersector_GetContactTime();
    if (k.FUN_00be0aa0() != 3 && k.FUN_00be0aa0() != 2)
    {
        k.SetVtbl();
        return false;
    }
    *pPoint = k.NiIntersector_GetContactPoint();
    if (bNormal)
    {
        *pNormal = k.NiIntersector_GetContactNormal();
        *pNegNormal = -*pNormal;
    }
    k.SetVtbl();
    return true;
}

extern int DAT_010f1814;
// Shared NiBoxBV lacks the five-point constructor and box storage; retain this local form.
struct FUN_00ea0820
{
    int v0, v1, v2, v3;
    int v10, v11, v12, v13, v14, v15, v16, v17, v18;
    float f34, f38, f3c;
    FUN_00ea0820(const NiPoint3& b, const NiPoint3& a, const NiPoint3& c, const NiPoint3& d, const NiPoint3& e);
};
// Stores a global address and copies the components of five NiPoint3 arguments into the object's fields.
// @fnv 0x00ea0820
FUN_00ea0820::FUN_00ea0820(const NiPoint3& aPoint1, const NiPoint3& aPoint2, const NiPoint3& aPoint3,
                           const NiPoint3& aPoint4, const NiPoint3& aPoint5)
{
    v0 = (int)&DAT_010f1814;
    v1 = *(int*)&aPoint2;
    v2 = *(int*)((char*)&aPoint2 + 4);
    v3 = *(int*)((char*)&aPoint2 + 8);
    f34 = *(float*)&aPoint1;
    f38 = *(float*)((char*)&aPoint1 + 4);
    f3c = *(float*)((char*)&aPoint1 + 8);
    v10 = *(int*)&aPoint3;
    v11 = *(int*)((char*)&aPoint3 + 4);
    v12 = *(int*)((char*)&aPoint3 + 8);
    v13 = *(int*)&aPoint4;
    v14 = *(int*)((char*)&aPoint4 + 4);
    v15 = *(int*)((char*)&aPoint4 + 8);
    v16 = *(int*)&aPoint5;
    v17 = *(int*)((char*)&aPoint5 + 4);
    v18 = *(int*)((char*)&aPoint5 + 8);
}

struct Ea07Sub
{
    void __thiscall WriteToStream(int a);
};

struct Ea07Owner
{
    int m_00;
    Ea07Sub m_04;
    void __thiscall nullsub_3(int a);
    void __thiscall NiBoxBV_LoadBinary(int a);
};

// @fnv 0x00ea07e0
// src: GAMEBRYO_SRC 0x00ea07e0
void Ea07Owner::NiBoxBV_LoadBinary(int a)
{
    this->nullsub_3(a);
    m_04.WriteToStream(a);
}

extern const float DAT_010141cc;
extern const float DAT_01017d00;
struct PointPairState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    void FUN_00eb3890(const void*, const void*, float, float, float, int);
    void Solve(const void*, const void*);
    float NiIntersector_GetContactTime();
    int FUN_00be0aa0();
    const NiPoint3& NiIntersector_GetContactPoint();
    const NiPoint3& NiIntersector_GetContactNormal();
    void SetVtbl();
};
// @fnv 0x00ea3c50
// src: XBOX_PDB 0x00ea3c50
bool NiBoxBV_BoxCapsuleFindIntersect(float length, const void* a, const void* b, const void* c, const void* d, float* pfTime, NiPoint3* point,
                  bool normals, NiPoint3* normal, NiPoint3* negative)
{
    PointPairState isect;
    isect.FUN_00eb3890(a, c, length, DAT_01017d00, DAT_010141cc, 32);
    isect.Solve(b, d);
    *pfTime = isect.NiIntersector_GetContactTime();
    if (isect.FUN_00be0aa0() != 3 && isect.FUN_00be0aa0() != 2)
    {
        isect.SetVtbl();
        return false;
    }
    *point = isect.NiIntersector_GetContactPoint();
    if (normals)
    {
        *normal = isect.NiIntersector_GetContactNormal();
        *negative = -*normal;
    }
    isect.SetVtbl();
    return true;
}

extern "C" double __cdecl fabs(double);
struct V3
{
    float x, y, z;
    V3()
    {}
    V3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    V3 operator-(const V3& v) const
    {
        return V3(x - v.x, y - v.y, z - v.z);
    }
    V3 operator^(const V3& v) const
    {
        return V3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
    float Dot(const V3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
    V3 Cross(const V3& v) const
    {
        return V3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
};
struct CenteredPointBounds
{
    V3 m_kCenter;
    V3 m_akAxes[3];
    float m_afExtents[3];
};
struct BoxVolume
{
    void* m_pVtbl;
    CenteredPointBounds m_kBoundsBox;
};
inline float AbsF(float f)
{
    return (float)fabs(f);
}
// Tests whether a triangle moving by (kV1-kV0)*fTime intersects the oriented bounding box using projection tests.
// @fnv 0x00ea2190
bool IntersectsTriangle(float fTime, const BoxVolume& kBV0, const V3& kV0, const V3& kVert0, const V3& kVert1,
                        const V3& kVert2, const V3& kV1)
{
    const BoxVolume& kBBV = (const BoxVolume&)kBV0;

    // convenience variables
    const V3* A = kBBV.m_kBoundsBox.m_akAxes;
    const float* extA = kBBV.m_kBoundsBox.m_afExtents;

    // Compute relative velocity of triangle with respect to box so that box
    // may as well be stationary.
    V3 W = kV1 - kV0;

    V3 D;
    V3 E[2];
    V3 N;
    E[0] = kVert1 - kVert0;
    E[1] = kVert2 - kVert0;
    N = E[0].Cross(E[1]);
    D = kVert0 - kBBV.m_kBoundsBox.m_kCenter;

    // axis C + t*N
    float A0dN = A[0].Dot(N);
    float A1dN = A[1].Dot(N);
    float A2dN = A[2].Dot(N);
    float R = AbsF(kBBV.m_kBoundsBox.m_afExtents[0] * A0dN) + AbsF(extA[1] * A1dN) + AbsF(extA[2] * A2dN);
    float NdD = N.Dot(D);
    {
        if ((NdD) > (R))
        {
            if ((NdD) + ((fTime) * (N).Dot(W)) > (R))
                return false;
        }
        else if ((NdD) < -(R))
        {
            if ((NdD) + ((fTime) * (N).Dot(W)) < -(R))
                return false;
        }
    };

    // axis C + t*A0
    float A0dD = A[0].Dot(D);
    float A0dE0 = A[0].Dot(E[0]);
    float A0dE1 = A[0].Dot(E[1]);
    float A0dW = A[0].Dot(W);
    {
        if ((A0dD) > (kBBV.m_kBoundsBox.m_afExtents[0]))
        {
            float min;
            if ((A0dE0) > 0.0f)
            {
                if ((A0dE1) >= 0.0f)
                {
                    if ((A0dD) + ((fTime) * (A0dW)) > (kBBV.m_kBoundsBox.m_afExtents[0]))
                        return false;
                }
                else
                {
                    min = (A0dD) + (A0dE1);
                    if ((min > (extA[0])) && (min + ((fTime) * (A0dW)) > (extA[0])))
                        return false;
                }
            }
            else if ((A0dE1) <= (A0dE0))
            {
                min = (A0dD) + (A0dE1);
                if ((min > (kBBV.m_kBoundsBox.m_afExtents[0])) && (min + ((fTime) * (A0dW)) > (extA[0])))
                    return false;
            }
            else
            {
                min = (A0dD) + (A0dE0);
                if ((min > (kBBV.m_kBoundsBox.m_afExtents[0])) && (min + ((fTime) * (A0dW)) > (extA[0])))
                    return false;
            }
        }
        else if ((A0dD) < -(extA[0]))
        {
            float max;
            if ((A0dE0) <= 0.0f)
            {
                if ((A0dE1) <= 0.0f)
                {
                    if ((A0dD) + ((fTime) * (A0dW)) < -(extA[0]))
                        return false;
                }
                else
                {
                    max = (A0dD) + (A0dE1);
                    if ((max < -(extA[0])) && (max + ((fTime) * (A0dW)) < -(extA[0])))
                        return false;
                }
            }
            else if ((A0dE1) >= (A0dE0))
            {
                max = (A0dD) + (A0dE1);
                if ((max < -(extA[0])) && (max + ((fTime) * (A0dW)) < -(extA[0])))
                    return false;
            }
            else
            {
                max = (A0dD) + (A0dE0);
                if ((max < -(extA[0])) && (max + ((fTime) * (A0dW)) < -(extA[0])))
                    return false;
            }
        }
    };

    // axis C + t*A1
    float A1dD = A[1].Dot(D);
    float A1dE0 = A[1].Dot(E[0]);
    float A1dE1 = A[1].Dot(E[1]);
    float A1dW = A[1].Dot(W);
    {
        if ((A1dD) > (extA[1]))
        {
            float min;
            if ((A1dE0) > 0.0f)
            {
                if ((A1dE1) >= 0.0f)
                {
                    if ((A1dD) + ((fTime) * (A1dW)) > (extA[1]))
                        return false;
                }
                else
                {
                    min = (A1dD) + (A1dE1);
                    if ((min > (kBBV.m_kBoundsBox.m_afExtents[1])) && (min + ((fTime) * (A1dW)) > (extA[1])))
                        return false;
                }
            }
            else if ((A1dE1) <= (A1dE0))
            {
                min = (A1dD) + (A1dE1);
                if ((min > (kBBV.m_kBoundsBox.m_afExtents[1])) &&
                    (min + ((fTime) * (A1dW)) > (kBBV.m_kBoundsBox.m_afExtents[1])))
                    return false;
            }
            else
            {
                min = (A1dD) + (A1dE0);
                if ((min > (kBBV.m_kBoundsBox.m_afExtents[1])) &&
                    (min + ((fTime) * (A1dW)) > (kBBV.m_kBoundsBox.m_afExtents[1])))
                    return false;
            }
        }
        else if ((A1dD) < -(extA[1]))
        {
            float max;
            if ((A1dE0) <= 0.0f)
            {
                if ((A1dE1) <= 0.0f)
                {
                    if ((A1dD) + ((fTime) * (A1dW)) < -(extA[1]))
                        return false;
                }
                else
                {
                    max = (A1dD) + (A1dE1);
                    if ((max < -(extA[1])) && (max + ((fTime) * (A1dW)) < -(extA[1])))
                        return false;
                }
            }
            else if ((A1dE1) >= (A1dE0))
            {
                max = (A1dD) + (A1dE1);
                if ((max < -(extA[1])) && (max + ((fTime) * (A1dW)) < -(extA[1])))
                    return false;
            }
            else
            {
                max = (A1dD) + (A1dE0);
                if ((max < -(extA[1])) && (max + ((fTime) * (A1dW)) < -(extA[1])))
                    return false;
            }
        }
    };

    // axis C + t*A2
    float A2dD = A[2].Dot(D);
    float A2dE0 = A[2].Dot(E[0]);
    float A2dE1 = A[2].Dot(E[1]);
    float A2dW = A[2].Dot(W);
    {
        if ((A2dD) > (extA[2]))
        {
            float min;
            if ((A2dE0) > 0.0f)
            {
                if ((A2dE1) >= 0.0f)
                {
                    if ((A2dD) + ((fTime) * (A2dW)) > (extA[2]))
                        return false;
                }
                else
                {
                    min = (A2dD) + (A2dE1);
                    if ((min > (kBBV.m_kBoundsBox.m_afExtents[2])) && (min + ((fTime) * (A2dW)) > (extA[2])))
                        return false;
                }
            }
            else if ((A2dE1) <= (A2dE0))
            {
                min = (A2dD) + (A2dE1);
                if ((min > (extA[2])) && (min + ((fTime) * (A2dW)) > (extA[2])))
                    return false;
            }
            else
            {
                min = (A2dD) + (A2dE0);
                if ((min > (extA[2])) && (min + ((fTime) * (A2dW)) > (kBBV.m_kBoundsBox.m_afExtents[2])))
                    return false;
            }
        }
        else if ((A2dD) < -(extA[2]))
        {
            float max;
            if ((A2dE0) <= 0.0f)
            {
                if ((A2dE1) <= 0.0f)
                {
                    if ((A2dD) + ((fTime) * (A2dW)) < -(extA[2]))
                        return false;
                }
                else
                {
                    max = (A2dD) + (A2dE1);
                    if ((max < -(extA[2])) && (max + ((fTime) * (A2dW)) < -(extA[2])))
                        return false;
                }
            }
            else if ((A2dE1) >= (A2dE0))
            {
                max = (A2dD) + (A2dE1);
                if ((max < -(extA[2])) && (max + ((fTime) * (A2dW)) < -(extA[2])))
                    return false;
            }
            else
            {
                max = (A2dD) + (A2dE0);
                if ((max < -(extA[2])) && (max + ((fTime) * (A2dW)) < -(extA[2])))
                    return false;
            }
        }
    };

    // axis C + t*A0xE0
    V3 A0xE0;
    A0xE0 = A[0].Cross(E[0]);
    float A0xE0dD = A0xE0.Dot(D);
    float A0xE0dW = A0xE0.Dot(W);
    R = AbsF(extA[1] * A2dE0) + AbsF(extA[2] * A1dE0);
    {
        if ((A0xE0dD) > (R))
        {
            if ((A0dN) >= 0.0f)
            {
                if ((A0xE0dD) + ((fTime) * (A0xE0dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A0xE0dD) + (A0dN);
                if ((min > (R)) && (min + ((fTime) * (A0xE0dW)) > (R)))
                    return false;
            }
        }
        else if ((A0xE0dD) < -(R))
        {
            if ((A0dN) <= 0.0f)
            {
                if ((A0xE0dD) + ((fTime) * (A0xE0dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A0xE0dD) + (A0dN);
                if ((max < -(R)) && (max + ((fTime) * (A0xE0dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A0xE1
    V3 A0xE1;
    A0xE1 = A[0].Cross(E[1]);
    float A0xE1dD = A0xE1.Dot(D);
    float A0xE1dW = A0xE1.Dot(W);
    R = AbsF(extA[2] * A1dE1) + AbsF(kBBV.m_kBoundsBox.m_afExtents[1] * A2dE1);
    {
        if ((A0xE1dD) > (R))
        {
            if ((-A0dN) >= 0.0f)
            {
                if ((A0xE1dD) + ((fTime) * (A0xE1dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A0xE1dD) + (-A0dN);
                if ((min > (R)) && (min + ((fTime) * (A0xE1dW)) > (R)))
                    return false;
            }
        }
        else if ((A0xE1dD) < -(R))
        {
            if ((-A0dN) <= 0.0f)
            {
                if ((A0xE1dD) + ((fTime) * (A0xE1dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A0xE1dD) + (-A0dN);
                if ((max < -(R)) && (max + ((fTime) * (A0xE1dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A0xE2
    float A1dE2 = A1dE1 - A1dE0;
    float A2dE2 = A2dE1 - A2dE0;
    float A0xE2dD = A0xE1dD - A0xE0dD;
    float A0xE2dW = A0xE1dW - A0xE0dW;
    R = AbsF(extA[1] * A2dE2) + AbsF(extA[2] * A1dE2);
    {
        if ((A0xE2dD) > (R))
        {
            if ((-A0dN) >= 0.0f)
            {
                if ((A0xE2dD) + ((fTime) * (A0xE2dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A0xE2dD) + (-A0dN);
                if ((min > (R)) && (min + ((fTime) * (A0xE2dW)) > (R)))
                    return false;
            }
        }
        else if ((A0xE2dD) < -(R))
        {
            if ((-A0dN) <= 0.0f)
            {
                if ((A0xE2dD) + ((fTime) * (A0xE2dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A0xE2dD) + (-A0dN);
                if ((max < -(R)) && (max + ((fTime) * (A0xE2dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A1xE0
    V3 A1xE0;
    A1xE0 = A[1].Cross(E[0]);
    float A1xE0dD = A1xE0.Dot(D);
    float A1xE0dW = A1xE0.Dot(W);
    R = AbsF(kBBV.m_kBoundsBox.m_afExtents[0] * A2dE0) + AbsF(extA[2] * A0dE0);
    {
        if ((A1xE0dD) > (R))
        {
            if ((A1dN) >= 0.0f)
            {
                if ((A1xE0dD) + ((fTime) * (A1xE0dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A1xE0dD) + (A1dN);
                if ((min > (R)) && (min + ((fTime) * (A1xE0dW)) > (R)))
                    return false;
            }
        }
        else if ((A1xE0dD) < -(R))
        {
            if ((A1dN) <= 0.0f)
            {
                if ((A1xE0dD) + ((fTime) * (A1xE0dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A1xE0dD) + (A1dN);
                if ((max < -(R)) && (max + ((fTime) * (A1xE0dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A1xE1
    V3 A1xE1;
    A1xE1 = A[1].Cross(E[1]);
    float A1xE1dD = A1xE1.Dot(D);
    float A1xE1dW = A1xE1.Dot(W);
    R = AbsF(kBBV.m_kBoundsBox.m_afExtents[0] * A2dE1) + AbsF(extA[2] * A0dE1);
    {
        if ((A1xE1dD) > (R))
        {
            if ((-A1dN) >= 0.0f)
            {
                if ((A1xE1dD) + ((fTime) * (A1xE1dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A1xE1dD) + (-A1dN);
                if ((min > (R)) && (min + ((fTime) * (A1xE1dW)) > (R)))
                    return false;
            }
        }
        else if ((A1xE1dD) < -(R))
        {
            if ((-A1dN) <= 0.0f)
            {
                if ((A1xE1dD) + ((fTime) * (A1xE1dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A1xE1dD) + (-A1dN);
                if ((max < -(R)) && (max + ((fTime) * (A1xE1dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A1xE2
    float A0dE2 = A0dE1 - A0dE0;
    float A1xE2dD = A1xE1dD - A1xE0dD;
    float A1xE2dW = A1xE1dW - A1xE0dW;
    R = AbsF(kBBV.m_kBoundsBox.m_afExtents[0] * A2dE2) + AbsF(extA[2] * A0dE2);
    {
        if ((A1xE2dD) > (R))
        {
            if ((-A1dN) >= 0.0f)
            {
                if ((A1xE2dD) + ((fTime) * (A1xE2dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A1xE2dD) + (-A1dN);
                if ((min > (R)) && (min + ((fTime) * (A1xE2dW)) > (R)))
                    return false;
            }
        }
        else if ((A1xE2dD) < -(R))
        {
            if ((-A1dN) <= 0.0f)
            {
                if ((A1xE2dD) + ((fTime) * (A1xE2dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A1xE2dD) + (-A1dN);
                if ((max < -(R)) && (max + ((fTime) * (A1xE2dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A2xE0
    V3 A2xE0;
    A2xE0 = A[2].Cross(E[0]);
    float A2xE0dD = A2xE0.Dot(D);
    float A2xE0dW = A2xE0.Dot(W);
    R = AbsF(extA[0] * A1dE0) + AbsF(extA[1] * A0dE0);
    {
        if ((A2xE0dD) > (R))
        {
            if ((A2dN) >= 0.0f)
            {
                if ((A2xE0dD) + ((fTime) * (A2xE0dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A2xE0dD) + (A2dN);
                if ((min > (R)) && (min + ((fTime) * (A2xE0dW)) > (R)))
                    return false;
            }
        }
        else if ((A2xE0dD) < -(R))
        {
            if ((A2dN) <= 0.0f)
            {
                if ((A2xE0dD) + ((fTime) * (A2xE0dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A2xE0dD) + (A2dN);
                if ((max < -(R)) && (max + ((fTime) * (A2xE0dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A2xE1
    V3 A2xE1;
    A2xE1 = A[2].Cross(E[1]);
    float A2xE1dD = A2xE1.Dot(D);
    float A2xE1dW = A2xE1.Dot(W);
    R = AbsF(extA[0] * A1dE1) + AbsF(extA[1] * A0dE1);
    {
        if ((A2xE1dD) > (R))
        {
            if ((-A2dN) >= 0.0f)
            {
                if ((A2xE1dD) + ((fTime) * (A2xE1dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A2xE1dD) + (-A2dN);
                if ((min > (R)) && (min + ((fTime) * (A2xE1dW)) > (R)))
                    return false;
            }
        }
        else if ((A2xE1dD) < -(R))
        {
            if ((-A2dN) <= 0.0f)
            {
                if ((A2xE1dD) + ((fTime) * (A2xE1dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A2xE1dD) + (-A2dN);
                if ((max < -(R)) && (max + ((fTime) * (A2xE1dW)) < -(R)))
                    return false;
            }
        }
    };

    // axis C + t*A2xE2
    float A2xE2dD = A2xE1dD - A2xE0dD;
    float A2xE2dW = A2xE1dW - A2xE0dW;
    R = AbsF(kBBV.m_kBoundsBox.m_afExtents[0] * A1dE2) + AbsF(extA[1] * A0dE2);
    {
        if ((A2xE2dD) > (R))
        {
            if ((-A2dN) >= 0.0f)
            {
                if ((A2xE2dD) + ((fTime) * (A2xE2dW)) > (R))
                    return false;
            }
            else
            {
                float min = (A2xE2dD) + (-A2dN);
                if ((min > (R)) && (min + ((fTime) * (A2xE2dW)) > (R)))
                    return false;
            }
        }
        else if ((A2xE2dD) < -(R))
        {
            if ((-A2dN) <= 0.0f)
            {
                if ((A2xE2dD) + ((fTime) * (A2xE2dW)) < -(R))
                    return false;
            }
            else
            {
                float max = (A2xE2dD) + (-A2dN);
                if ((max < -(R)) && (max + ((fTime) * (A2xE2dW)) < -(R)))
                    return false;
            }
        }
    };

    return true;  // PointPairState occurs.
}

struct CollisionBox
{
    void* vtable;
    NiPoint3 center;
    NiPoint3 axisX;
    NiPoint3 axisY;
    NiPoint3 axisZ;
    NiPoint3 halfExtents;
};
struct ProjectionQuery
{
    float radius;
    NiPoint3 base;
    float allowance;
    void InitFromParams(float radius, const NiPoint3* anchor);
};
extern const NiPoint3 DAT_011f426c;
extern const float DAT_01013ea4;
extern const double DAT_0106d508;
bool __cdecl IntersectsSphereAndBox(float threshold, const CollisionBox* box, const NiPoint3* direction,
                                    const ProjectionQuery* query, const NiPoint3* anchor);

static __forceinline float Round(float v)
{
    return v;
}
static __forceinline float Dot(const NiPoint3& a, const NiPoint3& b)
{
    volatile float rounded = b.x * a.x + a.y * b.y + a.z * b.z;
    return rounded;
}
static __forceinline float DotSecond(const NiPoint3& a, const NiPoint3& b)
{
    volatile float rounded = b.y * a.y + b.x * a.x + b.z * a.z;
    return rounded;
}
static __forceinline float DotSecondF(const NiPoint3& a, float bx, float by, float bz)
{
    volatile float rounded = by * a.y + bx * a.x + bz * a.z;
    return rounded;
}
static __forceinline float Negate(float v)
{
    return -v;
}
static __forceinline NiPoint3 Add(const NiPoint3& a, const NiPoint3& b)
{
    return NiPoint3(a.x + b.x, a.y + b.y, a.z + b.z);
}
static __forceinline void ClampToOrientedBox(const CollisionBox& box, const NiPoint3& direction, float distance,
                                             NiPoint3& position, double tolerance)
{
    NiPoint3 scaledDirection;
    scaledDirection.x = direction.x * distance;
    scaledDirection.y = direction.y * distance;
    scaledDirection.z = direction.z * distance;
    NiPoint3 projectedCenter = Add(scaledDirection, box.center);

    NiPoint3 displacement;
    displacement.x = position.x - projectedCenter.x;
    displacement.y = position.y - projectedCenter.y;
    displacement.z = position.z - projectedCenter.z;

    NiPoint3 local;
    local.x = Round(Dot(box.axisX, displacement));
    local.y = Round(Dot(box.axisY, displacement));
    local.z = Round(Dot(box.axisZ, displacement));

    if (local.x > box.halfExtents.x * tolerance)
        local.x = box.halfExtents.x;
    else if (local.x < Negate(box.halfExtents.x) * tolerance)
        local.x = Negate(box.halfExtents.x);

    if (local.y > box.halfExtents.y * tolerance)
        local.y = box.halfExtents.y;
    else if (local.y < Negate(box.halfExtents.y) * tolerance)
        local.y = Negate(box.halfExtents.y);

    if (local.z > box.halfExtents.z * tolerance)
        local.z = box.halfExtents.z;
    else if (local.z < Negate(box.halfExtents.z) * tolerance)
        local.z = Negate(box.halfExtents.z);

    NiPoint3 boundedZ;
    boundedZ.x = box.axisZ.x * local.z;
    boundedZ.y = box.axisZ.y * local.z;
    boundedZ.z = box.axisZ.z * local.z;
    NiPoint3 boundedY;
    boundedY.x = *(volatile float*)&box.axisY.x * local.y;
    boundedY.y = box.axisY.y * local.y;
    boundedY.z = box.axisY.z * local.y;
    NiPoint3 boundedX;
    boundedX.x = box.axisX.x * local.x;
    boundedX.y = box.axisX.y * local.x;
    boundedX.z = box.axisX.z * local.x;
    NiPoint3 sumX;
    sumX.x = projectedCenter.x + boundedX.x;
    sumX.y = projectedCenter.y + boundedX.y;
    sumX.z = projectedCenter.z + boundedX.z;
    NiPoint3 sumY;
    sumY.x = sumX.x + boundedY.x;
    sumY.y = sumX.y + boundedY.y;
    sumY.z = sumX.z + boundedY.z;
    NiPoint3 answer;
    answer.x = sumY.x + boundedZ.x;
    answer.y = sumY.y + boundedZ.y;
    answer.z = sumY.z + boundedZ.z;
    position = answer;
}

static __forceinline void ClampSecondBox(const CollisionBox& box, const NiPoint3& direction, float distance, NiPoint3& position)
{
    NiPoint3 scaledDirection;
    scaledDirection.x = direction.x * distance;
    scaledDirection.y = direction.y * distance;
    scaledDirection.z = direction.z * distance;
    NiPoint3 projectedCenter = Add(scaledDirection, box.center);

    NiPoint3 displacement;
    displacement.x = position.x - projectedCenter.x;
    displacement.y = position.y - projectedCenter.y;
    displacement.z = position.z - projectedCenter.z;

    NiPoint3 local;
    local.x = Round(DotSecondF(box.axisX, displacement.x, displacement.y, displacement.z));
    local.y = Round(DotSecondF(box.axisY, displacement.x, displacement.y, displacement.z));
    local.z = Round(DotSecondF(box.axisZ, displacement.x, displacement.y, displacement.z));

    if (local.x > box.halfExtents.x * DAT_0106d508)
        local.x = box.halfExtents.x;
    else if (local.x < Negate(box.halfExtents.x) * DAT_0106d508)
        local.x = Negate(box.halfExtents.x);

    if (local.y > box.halfExtents.y * DAT_0106d508)
        local.y = box.halfExtents.y;
    else if (local.y < Negate(box.halfExtents.y) * DAT_0106d508)
        local.y = Negate(box.halfExtents.y);

    if (local.z > box.halfExtents.z * DAT_0106d508)
        local.z = box.halfExtents.z;
    else if (local.z < Negate(box.halfExtents.z) * DAT_0106d508)
        local.z = Negate(box.halfExtents.z);

    NiPoint3 boundedZ;
    boundedZ.x = box.axisZ.x * local.z;
    boundedZ.y = box.axisZ.y * local.z;
    boundedZ.z = box.axisZ.z * local.z;
    NiPoint3 boundedY;
    boundedY.x = local.y * box.axisY.x;
    boundedY.y = box.axisY.y * local.y;
    boundedY.z = box.axisY.z * local.y;
    NiPoint3 boundedX;
    boundedX.x = box.axisX.x * local.x;
    boundedX.y = box.axisX.y * local.x;
    boundedX.z = box.axisX.z * local.x;
    NiPoint3 sumX;
    sumX.x = projectedCenter.x + boundedX.x;
    sumX.y = projectedCenter.y + boundedX.y;
    sumX.z = projectedCenter.z + boundedX.z;
    NiPoint3 sumY;
    sumY.x = sumX.x + boundedY.x;
    sumY.y = sumX.y + boundedY.y;
    sumY.z = sumX.z + boundedY.z;
    NiPoint3 answer;
    answer.x = sumY.x + boundedZ.x;
    answer.y = sumY.y + boundedZ.y;
    answer.z = sumY.z + boundedZ.z;
    position = answer;
}

// Clamps a position to two oriented collision boxes along given directions when a projection query reports no intersection.
// @fnv 0x00ea7730
void __cdecl ClampPositionToBoxes(float threshold, const CollisionBox* firstBox, const NiPoint3* firstDirection,
                                  const CollisionBox* secondBox, const NiPoint3* secondDirection, const float* distance,
                                  NiPoint3* position)
{
    ProjectionQuery query;
    query.InitFromParams(1.0f, &DAT_011f426c);
    query.allowance = DAT_01013ea4;
    query.base = *position;

    bool firstIntersects = IntersectsSphereAndBox(threshold, firstBox, firstDirection, &query, &DAT_011f426c);
    double tolerance = DAT_0106d508;
    if (!firstIntersects)
        ClampToOrientedBox(*firstBox, *firstDirection, *distance, *position, tolerance);
    if (!IntersectsSphereAndBox(threshold, secondBox, secondDirection, &query, &DAT_011f426c))
        ClampSecondBox(*secondBox, *secondDirection, *distance, *position);
}

#include <math.h>
inline float SatAbsF(float fValue)
{
    float fAbs = (float)fabs(fValue);
    return fAbs;
}

inline float SatRoundedAbs(float v)
{
    v = (float)fabs(v);
    return v;
}
class OBox
{
  public:
    PodPoint3 m_kCenter;
    PodPoint3 m_akAxes[3];
    float m_afExtents[3];
    float GetExtent(unsigned int axis) const
    {
        return m_afExtents[axis];
    }
};
class OBoxBV
{
  public:
    virtual void LoadBinary(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual ~OBoxBV();
    OBox m_kBoundsBox;
};

// @fnv 0x00ea0ad0
// src: GAMEBRYO_LIB 0x00ea0ad0
bool __cdecl NiBoxBV_BoxBoxTestIntersect(float fTime, const OBoxBV& kBV0, const PodPoint3& kV0, const OBoxBV& kBV1, const PodPoint3& kV1)
{
    const OBox& kBox0 = kBV0.m_kBoundsBox;
    const OBox& kBox1 = kBV1.m_kBoundsBox;

    // convenience variables
    const PodPoint3* akA = kBox0.m_akAxes;
    const PodPoint3* akB = kBox1.m_akAxes;
    const float* afEA = kBox0.m_afExtents;
    const float* afEB = kBox1.m_afExtents;

    unsigned char extentIndex = 2;
    // Compute relative velocity of box1 with respect to box0 so that box0
    // may as well be stationary.
    PodPoint3 kW;
    kW = kV1 - kV0;

    // Compute difference of box centers at time 0 and time 'fTime'.
    PodPoint3 kD0;
    kD0 = kBox1.m_kCenter - kBox0.m_kCenter;
    PodPoint3 kD1;
    kD1 = kD0 + kW * fTime;

    // matrix C = A^T B, c_{ij} = DotProduct(A_i,B_j)
    float aafC[3][3];

    // |c_{ij}|
    float aafAbsC[3][3];

    // DotProduct(A_i,D0)
    float afAD0[3];

    // DotProduct(A_i,D1)
    float afAD1[3];

    // interval radii and distance between centers
    float fR0, fR1, fR;

    // radius sum and difference
    float fR01;

    // axis C0+t*A0
    aafC[0][0] = akA[0].DotProduct(akB[0]);
    aafC[0][1] = akA[0].DotProduct(akB[1]);
    aafC[0][2] = akA[0].DotProduct(akB[2]);
    afAD0[0] = akA[0].DotProduct(kD0);
    afAD1[0] = akA[0].DotProduct(kD1);
    aafAbsC[0][0] = SatAbsF(aafC[0][0]);
    aafAbsC[0][1] = SatAbsF(aafC[0][1]);
    aafAbsC[0][2] = SatAbsF(aafC[0][2]);
    fR1 = afEB[0] * aafAbsC[0][0] + afEB[1] * aafAbsC[0][1] + aafAbsC[0][2] * kBox1.m_afExtents[extentIndex];
    fR01 = afEA[0] + fR1;
    if (afAD0[0] > fR01)
    {
        if (afAD1[0] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (afAD0[0] < fR01 && afAD1[0] < fR01)
            return false;
    }

    // axis C0+t*A1
    aafC[1][0] = akA[1].DotProduct(akB[0]);
    aafC[1][1] = akA[1].DotProduct(akB[1]);
    aafC[1][2] = akA[1].DotProduct(akB[2]);
    afAD0[1] = akA[1].DotProduct(kD0);
    afAD1[1] = static_cast<const PodPoint3&>(kD1).DotProduct(akA[1]);
    aafAbsC[1][0] = SatAbsF(aafC[1][0]);
    aafAbsC[1][1] = SatAbsF(aafC[1][1]);
    aafAbsC[1][2] = SatAbsF(aafC[1][2]);
    fR1 = afEB[0] * aafAbsC[1][0] + afEB[1] * aafAbsC[1][1] + aafAbsC[1][2] * kBox1.m_afExtents[extentIndex];
    fR01 = kBox0.GetExtent(1) + fR1;
    if (afAD0[1] > fR01)
    {
        if (afAD1[1] > fR01)
            return false;
    }
    else
    {
        fR01 = (float)(-fR01);
        if (afAD0[1] < fR01 && afAD1[1] < fR01)
            return false;
    }

    // axis C0+t*A2
    aafC[2][0] = akA[2].DotProduct(akB[0]);
    aafC[2][1] = akA[2].DotProduct(akB[1]);
    aafC[2][2] = akA[2].DotProduct(akB[2]);
    afAD0[2] = akA[2].DotProduct(kD0);
    afAD1[2] = kD1.DotPart(kD1.x, akA[2]);
    aafAbsC[2][0] = SatAbsF(aafC[2][0]);
    aafAbsC[2][1] = SatAbsF(aafC[2][1]);
    aafAbsC[2][2] = SatAbsF(aafC[2][2]);
    fR1 = (double)(afEB[0] * aafAbsC[2][0] + afEB[1] * aafAbsC[2][1] + aafAbsC[2][2] * kBox1.m_afExtents[2]);
    fR01 = kBox0.GetExtent(2) + fR1;
    if (afAD0[2] > fR01)
    {
        if (afAD1[2] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (afAD0[2] < fR01 && afAD1[2] < fR01)
            return false;
    }

    // axis C0+t*B0
    fR = akB[0].DotProduct(kD0);
    fR0 = afEA[0] * aafAbsC[0][0] + kBox0.m_afExtents[1] * aafAbsC[1][0] + kBox0.GetExtent(2) * aafAbsC[2][0];
    fR01 = fR0 + afEB[0];
    if (fR > fR01)
    {
        if (akB[0].DotProduct(kD1) > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && akB[0].DotProduct(kD1) < fR01)
            return false;
    }

    // axis C0+t*B1
    fR = akB[1].DotProduct(kD0);
    fR0 =
        afEA[0] * aafAbsC[0][1] + kBV0.m_kBoundsBox.m_afExtents[1] * aafAbsC[1][1] + kBox0.GetExtent(2) * aafAbsC[2][1];
    fR01 = fR0 + afEB[1];
    if (fR > fR01)
    {
        if (akB[1].DotProduct(kD1) > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && akB[1].DotProduct(kD1) < fR01)
            return false;
    }

    // axis C0+t*B2
    fR = akB[2].DotProduct(kD0);
    fR0 = afEA[0] * aafAbsC[0][2] + kBox0.GetExtent(1) * aafAbsC[1][2] + kBox0.GetExtent(2) * aafAbsC[2][2];
    fR01 = fR0 + kBox1.m_afExtents[2];
    if (fR > fR01)
    {
        if (akB[2].DotProduct(kD1) > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && akB[2].DotProduct(kD1) < fR01)
            return false;
    }

    // axis C0+t*A0xB0
    fR = afAD0[2] * aafC[1][0] - afAD0[1] * aafC[2][0];
    fR0 = kBox0.GetExtent(1) * aafAbsC[2][0] + kBV0.m_kBoundsBox.m_afExtents[2] * aafAbsC[1][0];
    fR1 = (double)(afEB[1] * aafAbsC[0][2] + aafAbsC[0][1] * kBox1.GetExtent(2));
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[2] * aafC[1][0] - afAD1[1] * aafC[2][0] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[2] * aafC[1][0] - afAD1[1] * aafC[2][0] < fR01)
            return false;
    }

    // axis C0+t*A0xB1
    fR = afAD0[2] * aafC[1][1] - afAD0[1] * aafC[2][1];
    fR0 = kBox0.GetExtent(1) * aafAbsC[2][1] + kBox0.GetExtent(2) * aafAbsC[1][1];
    fR1 = aafAbsC[0][0] * kBox1.m_afExtents[2] + kBV1.m_kBoundsBox.m_afExtents[0] * aafAbsC[0][2];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[2] * aafC[1][1] - afAD1[1] * aafC[2][1] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[2] * aafC[1][1] - afAD1[1] * aafC[2][1] < fR01)
            return false;
    }

    // axis C0+t*A0xB2
    fR = afAD0[2] * aafC[1][2] - afAD0[1] * aafC[2][2];
    fR0 = kBox0.GetExtent(1) * aafAbsC[2][2] + afEA[2] * aafAbsC[1][2];
    fR1 = afEB[0] * aafAbsC[0][1] + afEB[1] * aafAbsC[0][0];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[2] * aafC[1][2] - afAD1[1] * aafC[2][2] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[2] * aafC[1][2] - afAD1[1] * aafC[2][2] < fR01)
            return false;
    }

    // axis C0+t*A1xB0
    fR = afAD0[0] * aafC[2][0] - afAD0[2] * aafC[0][0];
    fR0 = kBox0.GetExtent(2) * aafAbsC[0][0] + afEA[0] * aafAbsC[2][0];
    fR1 = kBox1.m_afExtents[1] * aafAbsC[1][2] + aafAbsC[1][1] * kBox1.m_afExtents[2];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[0] * aafC[2][0] - afAD1[2] * aafC[0][0] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[0] * aafC[2][0] - afAD1[2] * aafC[0][0] < fR01)
            return false;
    }

    // axis C0+t*A1xB1
    fR = afAD0[0] * aafC[2][1] - afAD0[2] * aafC[0][1];
    fR0 = kBox0.GetExtent(2) * aafAbsC[0][1] + afEA[0] * aafAbsC[2][1];
    fR1 = aafAbsC[1][0] * kBox1.m_afExtents[2] + afEB[0] * aafAbsC[1][2];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[0] * aafC[2][1] - afAD1[2] * aafC[0][1] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[0] * aafC[2][1] - afAD1[2] * aafC[0][1] < fR01)
            return false;
    }

    // axis C0+t*A1xB2
    fR = afAD0[0] * aafC[2][2] - afAD0[2] * aafC[0][2];
    fR0 = kBox0.GetExtent(2) * aafAbsC[0][2] + afEA[0] * aafAbsC[2][2];
    fR1 = afEB[0] * aafAbsC[1][1] + afEB[1] * aafAbsC[1][0];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[0] * aafC[2][2] - afAD1[2] * aafC[0][2] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[0] * aafC[2][2] - afAD1[2] * aafC[0][2] < fR01)
            return false;
    }

    // axis C0+t*A2xB0
    fR = afAD0[1] * aafC[0][0] - afAD0[0] * aafC[1][0];
    fR0 = afEA[0] * aafAbsC[1][0] + kBox0.GetExtent(1) * aafAbsC[0][0];
    fR1 = kBV1.m_kBoundsBox.m_afExtents[1] * aafAbsC[2][2] + aafAbsC[2][1] * kBox1.m_afExtents[2];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[1] * aafC[0][0] - afAD1[0] * aafC[1][0] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[1] * aafC[0][0] - afAD1[0] * aafC[1][0] < fR01)
            return false;
    }

    // axis C0+t*A2xB1
    fR = afAD0[1] * aafC[0][1] - afAD0[0] * aafC[1][1];
    fR0 = afEA[0] * aafAbsC[1][1] + kBox0.GetExtent(1) * aafAbsC[0][1];
    fR1 = aafAbsC[2][0] * kBox1.m_afExtents[2] + afEB[0] * aafAbsC[2][2];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[1] * aafC[0][1] - afAD1[0] * aafC[1][1] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[1] * aafC[0][1] - afAD1[0] * aafC[1][1] < fR01)
            return false;
    }

    // axis C0+t*A2xB2
    fR = afAD0[1] * aafC[0][2] - afAD0[0] * aafC[1][2];
    fR0 = afEA[0] * aafAbsC[1][2] + kBox0.GetExtent(1) * aafAbsC[0][2];
    fR1 = afEB[0] * aafAbsC[2][1] + afEB[1] * aafAbsC[2][0];
    fR01 = fR0 + fR1;
    if (fR > fR01)
    {
        if (afAD1[1] * aafC[0][2] - afAD1[0] * aafC[1][2] > fR01)
            return false;
    }
    else
    {
        fR01 = -fR01;
        if (fR < fR01 && afAD1[1] * aafC[0][2] - afAD1[0] * aafC[1][2] < fR01)
            return false;
    }

    PodPoint3 kWxD0 = kW.FUN_004b3800(kD0);
    float afWA[3], afWB[3];

    // axis C0+t*WxA0
    afWA[1] = static_cast<const PodPoint3&>(kW).DotProduct(akA[1]);
    afWA[2] = static_cast<const PodPoint3&>(kW).DotProduct(akA[2]);
    fR = SatAbsF(akA[0].DotProduct(kWxD0));
    fR0 = kBox0.GetExtent(1) * SatAbsF(afWA[2]) + kBox0.GetExtent(2) * SatAbsF(afWA[1]);
    fR1 = afEB[0] * SatAbsF(aafC[1][0] * afWA[2] - aafC[2][0] * afWA[1]) +
          afEB[1] * SatAbsF(aafC[1][1] * afWA[2] - aafC[2][1] * afWA[1]) +
          kBox1.m_afExtents[2] * SatAbsF(aafC[1][2] * afWA[2] - aafC[2][2] * afWA[1]);
    fR01 = fR0 + fR1;
    if (fR > fR01)
        return false;

    // axis C0+t*WxA1
    afWA[0] = static_cast<const PodPoint3&>(kW).DotProduct(akA[0]);
    fR = SatAbsF(akA[1].DotProduct(kWxD0));
    fR0 = kBox0.GetExtent(2) * SatAbsF(afWA[0]) + afEA[0] * SatAbsF(afWA[2]);
    fR1 = afEB[0] * SatAbsF(aafC[2][0] * afWA[0] - aafC[0][0] * afWA[2]) +
          afEB[1] * SatAbsF(aafC[2][1] * afWA[0] - aafC[0][1] * afWA[2]) +
          kBox1.m_afExtents[2] * SatAbsF(aafC[2][2] * afWA[0] - aafC[0][2] * afWA[2]);
    fR01 = fR0 + fR1;
    if (fR > fR01)
        return false;

    // axis C0+t*WxA2
    fR = SatAbsF(akA[2].DotProduct(kWxD0));
    fR0 = afEA[0] * SatAbsF(afWA[1]) + kBox0.GetExtent(1) * SatAbsF(afWA[0]);
    fR1 = afEB[0] * SatAbsF(aafC[0][0] * afWA[1] - aafC[1][0] * afWA[0]) +
          afEB[1] * SatAbsF(aafC[0][1] * afWA[1] - aafC[1][1] * afWA[0]) +
          kBox1.m_afExtents[2] * SatAbsF(aafC[0][2] * afWA[1] - aafC[1][2] * afWA[0]);
    fR01 = fR0 + fR1;
    if (fR > fR01)
        return false;

    // axis C0+t*WxB0
    afWB[1] = static_cast<const PodPoint3&>(kW).DotProduct(akB[1]);
    afWB[2] = static_cast<const PodPoint3&>(kW).DotProduct(akB[2]);
    fR = SatAbsF(akB[0].DotProduct(kWxD0));
    fR0 = afEA[0] * SatAbsF(aafC[0][1] * afWB[2] - aafC[0][2] * afWB[1]) +
          kBox0.GetExtent(1) * SatRoundedAbs(aafC[1][1] * afWB[2] - aafC[1][2] * afWB[1]) +
          kBox0.GetExtent(2) * SatAbsF(aafC[2][1] * afWB[2] - aafC[2][2] * afWB[1]);
    fR1 = afEB[1] * SatAbsF(afWB[2]) + kBox1.m_afExtents[2] * SatAbsF(afWB[1]);
    fR01 = fR0 + fR1;
    if (fR > fR01)
        return false;

    // axis C0+t*WxB1
    afWB[0] = static_cast<const PodPoint3&>(kW).DotProduct(akB[0]);
    fR = SatAbsF(akB[1].DotProduct(kWxD0));
    fR0 = afEA[0] * SatAbsF(aafC[0][2] * afWB[0] - aafC[0][0] * afWB[2]) +
          kBox0.GetExtent(1) * SatRoundedAbs(aafC[1][2] * afWB[0] - aafC[1][0] * afWB[2]) +
          kBox0.GetExtent(2) * SatAbsF(aafC[2][2] * afWB[0] - aafC[2][0] * afWB[2]);
    fR1 = kBox1.m_afExtents[2] * SatAbsF(afWB[0]) + afEB[0] * SatAbsF(afWB[2]);
    fR01 = fR0 + fR1;
    if (fR > fR01)
        return false;

    // axis C0+t*WxB2
    fR = SatAbsF(akB[2].DotProduct(kWxD0));
    fR0 = afEA[0] * SatAbsF(aafC[0][0] * afWB[1] - aafC[0][1] * afWB[0]) +
          kBox0.GetExtent(1) * SatRoundedAbs(aafC[1][0] * afWB[1] - aafC[1][1] * afWB[0]) +
          kBox0.GetExtent(2) * SatAbsF(aafC[2][0] * afWB[1] - aafC[2][1] * afWB[0]);
    fR1 = afEB[0] * SatAbsF(afWB[1]) + afEB[1] * SatAbsF(afWB[0]);
    fR01 = fR0 + fR1;
    if (fR > fR01)
        return false;

    return true;
}

namespace fnv_00ea7530 {
extern const LocalVec3 NiPoint3_ZERO;

struct CenteredPointBounds
{
    LocalVec3 m_kCenter;
    LocalVec3 m_akAxes[3];
    float m_afExtents[3];
};

struct SphereShape
{
    LocalVec3 m_kCenter;
    float m_fBoundRadius;
};

struct SegmentShape
{
    LocalVec3 m_kStartPoint;
    LocalVec3 m_kLightVector;
};

struct BoxBVStub
{
    int unk00;
    CenteredPointBounds m_kBoundsBox;
};

struct SphereBVStub
{
    int unk00;
    SphereShape m_kBoundingSphere;
};

float SqrDistSegBox(const SegmentShape& kSeg, const CenteredPointBounds& kBox, float& fT, float& fB0, float& fB1, float& fB2);
float SqrDistPtBox(const LocalVec3& kPt, const CenteredPointBounds& kBox, float& fB0, float& fB1, float& fB2);

// @fnv 0x00ea7530
bool IntersectsSphereAndBox(float fTime, const BoxBVStub& kBV0, const LocalVec3& kV0, const SphereBVStub& kBV1,
                            const LocalVec3& kV1)
{
    LocalVec3 kDiff = kBV1.m_kBoundingSphere.m_kCenter - kBV0.m_kBoundsBox.m_kCenter;
    if (fabsf(kDiff.Dot(kBV0.m_kBoundsBox.m_akAxes[0])) <= kBV0.m_kBoundsBox.m_afExtents[0] &&
        fabsf(kDiff.Dot(kBV0.m_kBoundsBox.m_akAxes[1])) <= kBV0.m_kBoundsBox.m_afExtents[1] &&
        fabsf(kDiff.Dot(kBV0.m_kBoundsBox.m_akAxes[2])) <= kBV0.m_kBoundsBox.m_afExtents[2])
    {
        return true;
    }

    LocalVec3 kV = kV1 - kV0;
    float fT, fB0, fB1, fB2;
    float fSqrDist;
    if (kV != NiPoint3_ZERO)
    {
        SegmentShape kSeg;
        // Preserve the original trivial copies instead of LocalVec3 float assignment.
        memcpy(&kSeg.m_kStartPoint, &kBV1.m_kBoundingSphere.m_kCenter, sizeof(LocalVec3));
        LocalVec3 kLightVector = kV * fTime;
        memcpy(&kSeg.m_kLightVector, &kLightVector, sizeof(LocalVec3));
        fSqrDist = SqrDistSegBox(kSeg, kBV0.m_kBoundsBox, fT, fB0, fB1, fB2);
    }
    else
    {
        fSqrDist = SqrDistPtBox(kBV1.m_kBoundingSphere.m_kCenter, kBV0.m_kBoundsBox, fB0, fB1, fB2);
    }
    return fSqrDist <= (double)kBV1.m_kBoundingSphere.m_fBoundRadius * kBV1.m_kBoundingSphere.m_fBoundRadius;
}
}  // namespace fnv_00ea7530

// @fnv 0x00ea08a0
void NiBoxBV::Copy(const NiBoundingVolume& kABV)
{
    NiBoxBV* kBBV = this;
    memcpy((char*)kBBV + 4, (const char*)&kABV + 4, 60);
}

struct NormalVec
{
    float x, y, z;
    int operator==(const NormalVec& a) const
    {
        return x == a.x && y == a.y && z == a.z;
    }
    float Dot(const NormalVec& a) const
    {
        return x * a.x + y * a.y + z * a.z;
    }
    NormalVec& operator+=(const NormalVec& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }
    NormalVec& operator-=(const NormalVec& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }
    void Unitize_004a0c10();
};
extern "C" NormalVec FNV_NiPoint3Zero;
extern const float DAT_0104da4c;
struct BoxNormal
{
    int unk00, unk04, unk08, unk0c;
    NormalVec axis0, axis1, axis2;
    NormalVec CopyData_00ea3a60(int, int, int, NormalVec);
};
// Builds a vector from side-selected box axes, including an axis when velocity is zero or its axis dot velocity exceeds the threshold.
// @fnv 0x00ea3a60
// src: GUESS 0x00ea3a60 (confidence: low)
NormalVec BoxNormal::CopyData_00ea3a60(int iXSide, int iYSide, int iZSide, NormalVec kMotionVelocity)
{
    int iNumAxes = 0;
    NormalVec kNormal;
    memcpy(&kNormal, &FNV_NiPoint3Zero, sizeof(kNormal));
    bool bZeroVelocity = (unsigned char)(kMotionVelocity == FNV_NiPoint3Zero) != 0;
    if (bZeroVelocity || fabs(axis0.Dot(kMotionVelocity)) > 1.1920928955078125e-7f)
    {
        if (iXSide == 1)
        {
            kNormal += axis0;
            ++iNumAxes;
        }
        else if (iXSide == -1)
        {
            kNormal -= axis0;
            ++iNumAxes;
        }
    }
    if (bZeroVelocity || fabs(kMotionVelocity.Dot(axis1)) > 1.1920928955078125e-7f)
    {
        if (iYSide == 1)
        {
            kNormal += axis1;
            ++iNumAxes;
        }
        else if (iYSide == -1)
        {
            kNormal -= axis1;
            ++iNumAxes;
        }
    }
    if (bZeroVelocity || fabs(axis2.Dot(kMotionVelocity)) > 1.1920928955078125e-7f)
    {
        if (iZSide == 1)
        {
            kNormal += axis2;
            ++iNumAxes;
        }
        else if (iZSide == -1)
        {
            kNormal -= axis2;
            ++iNumAxes;
        }
    }
    if (iNumAxes != 1)
        kNormal.Unitize_004a0c10();
    return kNormal;
}

extern char DAT_010f1844;
void* __cdecl _NiMalloc_00aa1070(unsigned int length);
int __cdecl FUN_00a305b0(char* output, unsigned int outputSize, const char* format, const char* value);
struct FnvStringArray
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short capacity;
    unsigned short count;
    unsigned short unk0c;
    unsigned short growth;
    void FUN_0096ad30(unsigned int newCapacity);
    void FUN_0096ae90(unsigned int index, const char** value);
};
struct FnvTextProcessor
{
    void AddString(const char* text, FnvStringArray* array);
};
// Formats text into a new buffer, grows the array if needed, and appends the buffer pointer at the current count index.
// @fnv 0x00eab7b0
void FnvTextProcessor::AddString(const char* text, FnvStringArray* array)
{
    unsigned int length = (unsigned int)strlen(text) + 10;
    const char* q = text;
    text = (const char*)_NiMalloc_00aa1070(length);
    FUN_00a305b0((char*)text, length, &DAT_010f1844, q);
    unsigned int index = array->count;
    if (index >= array->capacity)
        array->FUN_0096ad30(index + array->growth);
    array->FUN_0096ae90(index, &text);
}

struct SolPoint
{
    float x, y, z;
    SolPoint()
    {}
    SolPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    SolPoint operator+(const SolPoint& right) const
    {
        return SolPoint(x + right.x, y + right.y, z + right.z);
    }
};
struct SolShape
{
    SolPoint m_kCenter;
    SolPoint m_akAxes[3];
    float m_afExtents[3];
};
inline SolPoint operator*(float factor, const SolPoint& input)
{
    return SolPoint(factor * input.x, factor * input.y, factor * input.z);
}
struct Rotation
{
    float entry[3][3];
    SolPoint operator*(const SolPoint& input) const
    {
        return SolPoint(entry[0][0] * input.x + entry[0][1] * input.y + entry[0][2] * input.z,
                        entry[1][0] * input.x + entry[1][1] * input.y + entry[1][2] * input.z,
                        entry[2][0] * input.x + entry[2][1] * input.y + entry[2][2] * input.z);
    }
};
struct WorldTransform
{
    Rotation rotation;
    SolPoint translation;
    float scale;
};
struct SolBoxVolume : NiBoundingVolume
{
    SolShape m_kBoundsBox;
    const SolPoint& Center() const
    {
        return m_kBoundsBox.m_kCenter;
    }
    const SolPoint& Axis(int index) const
    {
        return m_kBoundsBox.m_akAxes[index];
    }
    float Extent(int index) const
    {
        return m_kBoundsBox.m_afExtents[index];
    }
    void PutCenter(const SolPoint& value)
    {
        m_kBoundsBox.m_kCenter = value;
    }
    void PutAxis(int index, const SolPoint& value)
    {
        m_kBoundsBox.m_akAxes[index] = value;
    }
    void PutExtent(int index, float value)
    {
        m_kBoundsBox.m_afExtents[index] = value;
    }
    void TransformFrom(const NiBoundingVolume& source, const WorldTransform& transform);
};
// Applies a WorldTransform to a source SolBoxVolume, updating this box's center, axes, and extents.
// @fnv 0x00ea08c0
void SolBoxVolume::TransformFrom(const NiBoundingVolume& source, const WorldTransform& transform)
{
    const SolBoxVolume& input = static_cast<const SolBoxVolume&>(source);
    PutCenter(transform.scale * (transform.rotation * input.Center()) + transform.translation);
    PutAxis(0, transform.rotation * input.Axis(0));
    PutExtent(0, transform.scale * input.Extent(0));
    PutAxis(1, transform.rotation * input.Axis(1));
    PutExtent(1, transform.scale * input.Extent(1));
    PutAxis(2, transform.rotation * input.Axis(2));
    PutExtent(2, transform.scale * input.Extent(2));
}

#include <math.h>
namespace fnv_00ea2030 {
extern "C" double __cdecl fabs(double);

struct BoxPt
{
    float x, y, z;
    BoxPt operator-(const BoxPt& o) const
    {
        BoxPt r;
        r.x = x - o.x;
        r.y = y - o.y;
        r.z = z - o.z;
        return r;
    }
    float Dot(const BoxPt& o) const
    {
        return x * o.x + y * o.y + z * o.z;
    }
};

struct CenteredPointBounds
{
    int unk00;
    BoxPt center;
    BoxPt axis0;
    BoxPt axis1;
    BoxPt axis2;
    float extent0;
    float extent1;
    float extent2;
};

struct SphereShape
{
    int unk00;
    BoxPt center;
};

struct BoxSphereIsect
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
    void Init(const CenteredPointBounds* a, const SphereShape* b, float c, float d, float e, int f);
    void SetVelocities(const void* a, const void* b);
    int GetType();
    void Release();
};

extern const float DAT_01017d00;
extern const float g_011c5aa8_arg1;

static inline float AbsF(float f)
{
    return (float)fabs(f);
}

// Checks if a sphere overlaps a box via axis projections, or if their velocities cause a collision within the given time step.
// @fnv 0x00ea2030
// src: XBOX_PDB 0x00ea2030
bool NiBoxBV_BoxCapsuleTestIntersect(float fTime, const CenteredPointBounds* pBox, const void* pVel0, const SphereShape* pSphere, const void* pVel1)
{
    BoxPt d = pSphere->center - pBox->center;

    if (AbsF(pBox->axis0.Dot(d)) <= pBox->extent0 &&
        AbsF(d.x * pBox->axis1.x + d.y * pBox->axis1.y + d.z * pBox->axis1.z) <= pBox->extent1 &&
        AbsF(pBox->axis2.Dot(d)) <= pBox->extent2)
        return true;

    BoxSphereIsect kIsect;
    kIsect.Init(pBox, pSphere, fTime, DAT_01017d00, g_011c5aa8_arg1, 0x20);
    kIsect.SetVelocities(pVel0, pVel1);
    bool bIntersecting;
    if (kIsect.GetType() == 3 || kIsect.GetType() == 2)
        bIntersecting = true;
    else
        bIntersecting = false;
    kIsect.Release();
    return bIntersecting;
}
}  // namespace fnv_00ea2030

class ReworkPoint
{
  public:
    float x, y, z;
    ReworkPoint()
    {}
    ReworkPoint(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    ReworkPoint operator-(const ReworkPoint& o) const
    {
        return ReworkPoint(x - o.x, y - o.y, z - o.z);
    }
    ReworkPoint Cross(const ReworkPoint& o) const
    {
        return ReworkPoint(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x);
    }
    ReworkPoint EdgeCross(const ReworkPoint& o) const
    {
        ReworkPoint r;
        r.x = y * o.z - z * o.y;
        r.y = z * o.x - x * o.z;
        r.z = x * o.y - y * o.x;
        return r;
    }
    float Dot(const ReworkPoint& o) const;
    ReworkPoint __thiscall operator+(const ReworkPoint& o) const
    {
        return ReworkPoint(x + o.x, y + o.y, z + o.z);
    }
    ReworkPoint& __thiscall operator+=(const ReworkPoint& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
    ReworkPoint operator-() const
    {
        return ReworkPoint(-x, -y, -z);
    }
// src: XBOX_PDB 0x004a0c10
    void __thiscall Unitize_004a0c10()
    {
        float length = (float)sqrt(x * x + y * y + z * z);
        if (length > 1e-6)
        {
            float inv = 1.0f / length;
            x *= inv;
            y *= inv;
            z *= inv;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
    float& operator[](int i)
    {
        float* base = &x;
        return (float&)base[i];
    }
    const float& operator[](int i) const
    {
        const float* base = &x;
        return (float&)base[i];
    }
};
inline float ReworkPoint::Dot(const ReworkPoint& o) const
{
    return x * o.x + y * o.y + z * o.z;
}
inline ReworkPoint __cdecl FUN_004a3760(float f, const ReworkPoint& v)
{
    return ReworkPoint(f * v.x, f * v.y, f * v.z);
}
struct ReworkGeometry
{
    ReworkPoint center;
    ReworkPoint axes[3];
    float extents[3];
};
struct ReworkBox
{
    void* vtable;
    ReworkGeometry geometry;
    const ReworkPoint& GetNavMeshData() const
    {
        return geometry.center;
    }
    const ReworkPoint* GetAxes() const
    {
        return geometry.axes;
    }
    const float* GetExtents() const
    {
        return geometry.extents;
    }
};
extern "C" double __cdecl fabs(double);
inline float ReworkAbs(float fValue)
{
    return float(fabs(fValue));
}

// Tests a moving triangle against an oriented bounding box, returning the earliest hit time, point, and optional normals.
// @fnv 0x00ea3d60
// src: COMMUNITY 0x00ea3d60
bool __cdecl NiBoxBV_BoxTriFindIntersect(float maxTime, const ReworkBox& box, const ReworkPoint& vel0, const ReworkPoint& p0,
                          const ReworkPoint& p1, const ReworkPoint& p2, const ReworkPoint& vel1, float& hitTime,
                          ReworkPoint& hitPoint, bool wantNormals, ReworkPoint& normal0, ReworkPoint& normal1)
{
    const ReworkBox& bv = box;

    const ReworkPoint* axes = bv.GetAxes();
    const float* pExtents = bv.GetExtents();

    ReworkPoint vRelVel = vel1 - vel0;

    ReworkPoint vDelta;
    ReworkPoint vEdge[3];
    ReworkPoint vTriNormal;
    vEdge[0] = p1 - p0;
    vEdge[1] = p2 - p0;
    vTriNormal = vEdge[0].Cross(vEdge[1]);
    vDelta = p0 - bv.GetNavMeshData();

    unsigned int hitAxis = 0;
    unsigned int hitEdge = 0;
    int side = 0;
    hitTime = 0.0f;
    int i;

    float axN[3];
    axN[0] = axes[0].Dot(vTriNormal);
    axN[1] = axes[1].Dot(vTriNormal);
    axN[2] = axes[2].Dot(vTriNormal);
    float radius =
        (pExtents[0] * ReworkAbs(axN[0])) + (pExtents[1] * ReworkAbs(axN[1])) + (pExtents[2] * ReworkAbs(axN[2]));
    float fNDot = vTriNormal.Dot(vDelta);
    {
        float t, nW;
        if ((fNDot) > (radius))
        {
            nW = (vTriNormal).Dot(vRelVel);
            if ((fNDot) + ((maxTime)*nW) > (radius))
                return false;
            t = ((radius) - (fNDot)) / nW;
            if (t > (hitTime))
            {
                (hitTime) = t;
                (hitAxis) = (1);
                (side) = 1;
            }
        }
        else if ((fNDot) < -(radius))
        {
            nW = (vTriNormal).Dot(vRelVel);
            if ((fNDot) + ((maxTime)*nW) < -(radius))
                return false;
            t = -((radius) + (fNDot)) / nW;
            if (t > (hitTime))
            {
                (hitTime) = t;
                (hitAxis) = (1);
                (side) = -1;
            }
        }
    }
    float axD[3];
    float axE[3][3];

    for (i = 0; i < 3; i++)
    {

        axD[i] = axes[i].Dot(vDelta);
        axE[i][0] = axes[i].Dot(vEdge[0]);
        axE[i][1] = axes[i].Dot(vEdge[1]);
        float axW = axes[i].Dot(vRelVel);
        {
            float t;
            if ((axD[i]) > (pExtents[i]))
            {
                float lo;
                if ((axE[i][0]) > 0.0f)
                {
                    if ((axE[i][1]) >= 0.0f)
                    {
                        if ((axD[i]) + ((maxTime) * (axW)) > (pExtents[i]))
                            return false;
                        t = ((pExtents[i]) - (axD[i])) / (axW);
                        if (t > (hitTime))
                        {
                            (hitTime) = t;
                            (hitAxis) = (i + 2);
                            (hitEdge) = 0;
                            (side) = 1;
                        }
                    }
                    else
                    {
                        lo = (axD[i]) + (axE[i][1]);
                        if (lo > (pExtents[i]))
                        {
                            if (lo + ((maxTime) * (axW)) > (pExtents[i]))
                                return false;
                            t = ((pExtents[i]) - lo) / (axW);
                            if (t > (hitTime))
                            {
                                (hitTime) = t;
                                (hitAxis) = (i + 2);
                                (hitEdge) = 2;
                                (side) = 1;
                            }
                        }
                    }
                }
                else if ((axE[i][1]) <= (axE[i][0]))
                {
                    lo = (axD[i]) + (axE[i][1]);
                    if (lo > (pExtents[i]))
                    {
                        if (lo + ((maxTime) * (axW)) > (pExtents[i]))
                            return false;
                        t = ((pExtents[i]) - lo) / (axW);
                        if (t > (hitTime))
                        {
                            (hitTime) = t;
                            (hitAxis) = (i + 2);
                            (hitEdge) = 2;
                            (side) = 1;
                        }
                    }
                }
                else
                {
                    lo = (axD[i]) + (axE[i][0]);
                    if (lo > (pExtents[i]))
                    {
                        if (lo + ((maxTime) * (axW)) > (pExtents[i]))
                            return false;
                        t = ((pExtents[i]) - lo) / (axW);
                        if (t > (hitTime))
                        {
                            (hitTime) = t;
                            (hitAxis) = (i + 2);
                            (hitEdge) = 1;
                            (side) = 1;
                        }
                    }
                }
            }
            else if ((axD[i]) < -(pExtents[i]))
            {
                float hi;
                if ((axE[i][0]) <= 0.0f)
                {
                    if ((axE[i][1]) <= 0.0f)
                    {
                        if ((axD[i]) + ((maxTime) * (axW)) < -(pExtents[i]))
                            return false;
                        t = -((pExtents[i]) + (axD[i])) / (axW);
                        if (t > (hitTime))
                        {
                            (hitTime) = t;
                            (hitAxis) = (i + 2);
                            (hitEdge) = 0;
                            (side) = -1;
                        }
                    }
                    else
                    {
                        hi = (axD[i]) + (axE[i][1]);
                        if (hi < -(pExtents[i]))
                        {
                            if (hi + ((maxTime) * (axW)) < -(pExtents[i]))
                                return false;
                            t = -((pExtents[i]) + hi) / (axW);
                            if (t > (hitTime))
                            {
                                (hitTime) = t;
                                (hitAxis) = (i + 2);
                                (hitEdge) = 2;
                                (side) = -1;
                            }
                        }
                    }
                }
                else if ((axE[i][1]) >= (axE[i][0]))
                {
                    hi = (axD[i]) + (axE[i][1]);
                    if (hi < -(pExtents[i]))
                    {
                        if (hi + ((maxTime) * (axW)) < -(pExtents[i]))
                            return false;
                        t = -((pExtents[i]) + hi) / (axW);
                        if (t > (hitTime))
                        {
                            (hitTime) = t;
                            (hitAxis) = (i + 2);
                            (hitEdge) = 2;
                            (side) = -1;
                        }
                    }
                }
                else
                {
                    hi = (axD[i]) + (axE[i][0]);
                    if (hi < -(pExtents[i]))
                    {
                        if (hi + ((maxTime) * (axW)) < -(pExtents[i]))
                            return false;
                        t = -((pExtents[i]) + hi) / (axW);
                        if (t > (hitTime))
                        {
                            (hitTime) = t;
                            (hitAxis) = (i + 2);
                            (hitEdge) = 1;
                            (side) = -1;
                        }
                    }
                }
            }
        }
    }

    ReworkPoint vC00;
    vC00 = axes[0].Cross(vEdge[0]);
    float fC00Dot = vC00.Dot(vDelta);
    float fC00Vel = vC00.Dot(vRelVel);
    radius = (pExtents[1] * (float)fabs(axE[2][0])) + (pExtents[2] * ReworkAbs(axE[1][0]));
    {
        float t;
        if ((fC00Dot) > (radius))
        {
            if ((axN[0]) >= 0.0f)
            {
                if ((fC00Dot) + ((maxTime) * (fC00Vel)) > (radius))
                    return false;
                t = ((radius) - (fC00Dot)) / (fC00Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (5);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC00Dot) + (axN[0]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC00Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC00Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (5);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC00Dot) < -(radius))
        {
            if ((axN[0]) <= 0.0f)
            {
                if ((fC00Dot) + ((maxTime) * (fC00Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC00Dot)) / (fC00Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (5);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC00Dot) + (axN[0]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC00Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC00Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (5);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    ReworkPoint vC01;
    vC01 = axes[0].Cross(vEdge[1]);
    float fC01Dot = vC01.Dot(vDelta);
    float fC01Vel = vC01.Dot(vRelVel);
    radius = (pExtents[1] * (float)fabs(axE[2][1])) + (pExtents[2] * ReworkAbs(axE[1][1]));
    {
        float t;
        if ((fC01Dot) > (radius))
        {
            if ((-axN[0]) >= 0.0f)
            {
                if ((fC01Dot) + ((maxTime) * (fC01Vel)) > (radius))
                    return false;
                t = ((radius) - (fC01Dot)) / (fC01Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (6);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC01Dot) + (-axN[0]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC01Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC01Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (6);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC01Dot) < -(radius))
        {
            if ((-axN[0]) <= 0.0f)
            {
                if ((fC01Dot) + ((maxTime) * (fC01Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC01Dot)) / (fC01Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (6);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC01Dot) + (-axN[0]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC01Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC01Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (6);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    axE[1][2] = axE[1][1] - axE[1][0];
    axE[2][2] = axE[2][1] - axE[2][0];
    float fC02Dot = fC01Dot - fC00Dot;
    float fC02Vel = fC01Vel - fC00Vel;
    radius = (pExtents[1] * (float)fabs(axE[2][2])) + (pExtents[2] * ReworkAbs(axE[1][2]));
    {
        float t;
        if ((fC02Dot) > (radius))
        {
            if ((-axN[0]) >= 0.0f)
            {
                if ((fC02Dot) + ((maxTime) * (fC02Vel)) > (radius))
                    return false;
                t = ((radius) - (fC02Dot)) / (fC02Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (7);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC02Dot) + (-axN[0]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC02Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC02Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (7);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC02Dot) < -(radius))
        {
            if ((-axN[0]) <= 0.0f)
            {
                if ((fC02Dot) + ((maxTime) * (fC02Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC02Dot)) / (fC02Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (7);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC02Dot) + (-axN[0]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC02Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC02Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (7);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    ReworkPoint vC10;
    vC10 = axes[1].Cross(vEdge[0]);
    float fC10Dot = vC10.Dot(vDelta);
    float fC10Vel = vC10.Dot(vRelVel);
    radius = (pExtents[0] * (float)fabs(axE[2][0])) + (pExtents[2] * ReworkAbs(axE[0][0]));
    {
        float t;
        if ((fC10Dot) > (radius))
        {
            if ((axN[1]) >= 0.0f)
            {
                if ((fC10Dot) + ((maxTime) * (fC10Vel)) > (radius))
                    return false;
                t = ((radius) - (fC10Dot)) / (fC10Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (8);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC10Dot) + (axN[1]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC10Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC10Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (8);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC10Dot) < -(radius))
        {
            if ((axN[1]) <= 0.0f)
            {
                if ((fC10Dot) + ((maxTime) * (fC10Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC10Dot)) / (fC10Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (8);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC10Dot) + (axN[1]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC10Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC10Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (8);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    ReworkPoint vC11;
    vC11 = axes[1].Cross(vEdge[1]);
    float fC11Dot = vC11.Dot(vDelta);
    float fC11Vel = vC11.Dot(vRelVel);
    radius = (pExtents[0] * (float)fabs(axE[2][1])) + (pExtents[2] * ReworkAbs(axE[0][1]));
    {
        float t;
        if ((fC11Dot) > (radius))
        {
            if ((-axN[1]) >= 0.0f)
            {
                if ((fC11Dot) + ((maxTime) * (fC11Vel)) > (radius))
                    return false;
                t = ((radius) - (fC11Dot)) / (fC11Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (9);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC11Dot) + (-axN[1]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC11Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC11Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (9);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC11Dot) < -(radius))
        {
            if ((-axN[1]) <= 0.0f)
            {
                if ((fC11Dot) + ((maxTime) * (fC11Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC11Dot)) / (fC11Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (9);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC11Dot) + (-axN[1]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC11Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC11Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (9);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    axE[0][2] = axE[0][1] - axE[0][0];
    float fC12Dot = fC11Dot - fC10Dot;
    float fC12Vel = fC11Vel - fC10Vel;
    radius = (pExtents[0] * (float)fabs(axE[2][2])) + (pExtents[2] * ReworkAbs(axE[0][2]));
    {
        float t;
        if ((fC12Dot) > (radius))
        {
            if ((-axN[1]) >= 0.0f)
            {
                if ((fC12Dot) + ((maxTime) * (fC12Vel)) > (radius))
                    return false;
                t = ((radius) - (fC12Dot)) / (fC12Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (10);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC12Dot) + (-axN[1]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC12Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC12Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (10);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC12Dot) < -(radius))
        {
            if ((-axN[1]) <= 0.0f)
            {
                if ((fC12Dot) + ((maxTime) * (fC12Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC12Dot)) / (fC12Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (10);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC12Dot) + (-axN[1]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC12Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC12Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (10);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    ReworkPoint vC20;
    vC20 = axes[2].Cross(vEdge[0]);
    float fC20Dot = vC20.Dot(vDelta);
    float fC20Vel = vC20.Dot(vRelVel);
    radius = (pExtents[0] * (float)fabs(axE[1][0])) + (pExtents[1] * ReworkAbs(axE[0][0]));
    {
        float t;
        if ((fC20Dot) > (radius))
        {
            if ((axN[2]) >= 0.0f)
            {
                if ((fC20Dot) + ((maxTime) * (fC20Vel)) > (radius))
                    return false;
                t = ((radius) - (fC20Dot)) / (fC20Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (11);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC20Dot) + (axN[2]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC20Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC20Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (11);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC20Dot) < -(radius))
        {
            if ((axN[2]) <= 0.0f)
            {
                if ((fC20Dot) + ((maxTime) * (fC20Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC20Dot)) / (fC20Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (11);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC20Dot) + (axN[2]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC20Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC20Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (11);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    ReworkPoint vC21;
    vC21 = axes[2].EdgeCross(vEdge[1]);
    float fC21Dot = vC21.Dot(vDelta);
    float fC21Vel = vC21.Dot(vRelVel);
    radius = (pExtents[0] * (float)fabs(axE[1][1])) + (pExtents[1] * ReworkAbs(axE[0][1]));
    {
        float t;
        if ((fC21Dot) > (radius))
        {
            if ((-axN[2]) >= 0.0f)
            {
                if ((fC21Dot) + ((maxTime) * (fC21Vel)) > (radius))
                    return false;
                t = ((radius) - (fC21Dot)) / (fC21Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (12);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC21Dot) + (-axN[2]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC21Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC21Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (12);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC21Dot) < -(radius))
        {
            if ((-axN[2]) <= 0.0f)
            {
                if ((fC21Dot) + ((maxTime) * (fC21Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC21Dot)) / (fC21Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (12);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC21Dot) + (-axN[2]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC21Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC21Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (12);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    float fC22Dot = fC21Dot - fC20Dot;
    float fC22Vel = fC21Vel - fC20Vel;
    radius = (pExtents[0] * (float)fabs(axE[1][2])) + (pExtents[1] * ReworkAbs(axE[0][2]));
    {
        float t;
        if ((fC22Dot) > (radius))
        {
            if ((-axN[2]) >= 0.0f)
            {
                if ((fC22Dot) + ((maxTime) * (fC22Vel)) > (radius))
                    return false;
                t = ((radius) - (fC22Dot)) / (fC22Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (13);
                    (hitEdge) = 0;
                    (side) = 1;
                }
            }
            else
            {
                float lo = (fC22Dot) + (-axN[2]);
                if (lo > (radius))
                {
                    if (lo + ((maxTime) * (fC22Vel)) > (radius))
                        return false;
                    t = ((radius)-lo) / (fC22Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (13);
                        (hitEdge) = 1;
                        (side) = 1;
                    }
                }
            }
        }
        else if ((fC22Dot) < -(radius))
        {
            if ((-axN[2]) <= 0.0f)
            {
                if ((fC22Dot) + ((maxTime) * (fC22Vel)) < -(radius))
                    return false;
                t = -((radius) + (fC22Dot)) / (fC22Vel);
                if (t > (hitTime))
                {
                    (hitTime) = t;
                    (hitAxis) = (13);
                    (hitEdge) = 0;
                    (side) = -1;
                }
            }
            else
            {
                float hi = (fC22Dot) + (-axN[2]);
                if (hi < -(radius))
                {
                    if (hi + ((maxTime) * (fC22Vel)) < -(radius))
                        return false;
                    t = -((radius) + hi) / (fC22Vel);
                    if (t > (hitTime))
                    {
                        (hitTime) = t;
                        (hitAxis) = (13);
                        (hitEdge) = 1;
                        (side) = -1;
                    }
                }
            }
        }
    }
    float x[3];
    float fNumerator;
    float nDotDE[3];
    float nDotAE[3][3];
    ReworkPoint vDCrossE[3];
    ReworkPoint vC02;
    ReworkPoint vC12;
    ReworkPoint vC22;

    switch (hitAxis)
    {
    case 0: {

        static float fOneThird = 1.0f / 3.0f;
        hitPoint = FUN_004a3760(0.5f, FUN_004a3760(fOneThird, p0 + p1 + p2) + bv.GetNavMeshData());
        break;
    }
    case 1: {
        {
            if ((axN[0]) > 0.0f)
                (x[0]) = (side) * (pExtents[0]);
            else if ((axN[0]) < 0.0f)
                (x[0]) = -(side) * (pExtents[0]);
            else
                (x[0]) = 0.0f;
        }
        {
            if ((axN[1]) > 0.0f)
                (x[1]) = (side) * (pExtents[1]);
            else if ((axN[1]) < 0.0f)
                (x[1]) = -(side) * (pExtents[1]);
            else
                (x[1]) = 0.0f;
        }
        {
            if ((axN[2]) > 0.0f)
                (x[2]) = (side) * (pExtents[2]);
            else if ((axN[2]) < 0.0f)
                (x[2]) = -(side) * (pExtents[2]);
            else
                (x[2]) = 0.0f;
        }
        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 2:
    case 3:
    case 4: {
        if (hitEdge == 0)
            hitPoint = p0 + FUN_004a3760(hitTime, vel1);
        else if (hitEdge == 1)
            hitPoint = p0 + FUN_004a3760(hitTime, vel1) + vEdge[0];
        else
            hitPoint = p0 + FUN_004a3760(hitTime, vel1) + vEdge[1];
        break;
    }
    case 5: {
        {
            if ((axE[2][0]) > 0.0f)
                (x[1]) = -(side) * (pExtents[1]);
            else if ((axE[2][0]) < 0.0f)
                (x[1]) = (side) * (pExtents[1]);
            else
                (x[1]) = 0.0f;
        }
        {
            if ((axE[1][0]) > 0.0f)
                (x[2]) = (side) * (pExtents[2]);
            else if ((axE[1][0]) < 0.0f)
                (x[2]) = -(side) * (pExtents[2]);
            else
                (x[2]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[0] = vDelta.Cross(vEdge[0]);
        nDotDE[0] = vC00.Dot(vDCrossE[0]);
        nDotAE[0][0] = vC00.Dot(vC00);
        nDotAE[1][0] = vC00.Dot(vC10);
        nDotAE[2][0] = vC00.Dot(vC20);
        fNumerator = nDotDE[0] - (nDotAE[1][0] * x[1]) - (nDotAE[2][0] * x[2]);
        if (hitEdge == 0)
            x[0] = fNumerator / nDotAE[0][0];
        else
            x[0] = (fNumerator - vC00.Dot(vTriNormal)) / nDotAE[0][0];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 6: {
        {
            if ((axE[2][1]) > 0.0f)
                (x[1]) = -(side) * (pExtents[1]);
            else if ((axE[2][1]) < 0.0f)
                (x[1]) = (side) * (pExtents[1]);
            else
                (x[1]) = 0.0f;
        }
        {
            if ((axE[1][1]) > 0.0f)
                (x[2]) = (side) * (pExtents[2]);
            else if ((axE[1][1]) < 0.0f)
                (x[2]) = -(side) * (pExtents[2]);
            else
                (x[2]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[1] = vDelta.Cross(vEdge[1]);
        nDotDE[1] = vC01.Dot(vDCrossE[1]);
        nDotAE[0][1] = vC01.Dot(vC01);
        nDotAE[1][1] = vC01.Dot(vC11);
        nDotAE[2][1] = vC01.Dot(vC21);
        fNumerator = nDotDE[1] - (nDotAE[1][1] * x[1]) - (nDotAE[2][1] * x[2]);
        if (hitEdge == 0)
            x[0] = fNumerator / nDotAE[0][1];
        else
            x[0] = (fNumerator + vC01.Dot(vTriNormal)) / nDotAE[0][1];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 7: {
        vEdge[2] = vEdge[1] - vEdge[0];
        vC02 = axes[0].Cross(vEdge[2]);
        vC12 = axes[1].Cross(vEdge[2]);
        vC22 = axes[2].Cross(vEdge[2]);

        {
            if ((axE[2][2]) > 0.0f)
                (x[1]) = -(side) * (pExtents[1]);
            else if ((axE[2][2]) < 0.0f)
                (x[1]) = (side) * (pExtents[1]);
            else
                (x[1]) = 0.0f;
        }
        {
            if ((axE[1][2]) > 0.0f)
                (x[2]) = (side) * (pExtents[2]);
            else if ((axE[1][2]) < 0.0f)
                (x[2]) = -(side) * (pExtents[2]);
            else
                (x[2]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[2] = vDelta.Cross(vEdge[2]);
        nDotDE[2] = vC02.Dot(vDCrossE[2]);
        nDotAE[0][2] = vC02.Dot(vC02);
        nDotAE[1][2] = vC02.Dot(vC12);
        nDotAE[2][2] = vC02.Dot(vC22);
        fNumerator = nDotDE[2] - (nDotAE[1][2] * x[1]) - (nDotAE[2][2] * x[2]);
        if (hitEdge == 0)
            x[0] = fNumerator / nDotAE[0][2];
        else
            x[0] = (fNumerator + vC02.Dot(vTriNormal)) / nDotAE[0][2];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 8: {
        {
            if ((axE[2][0]) > 0.0f)
                (x[0]) = (side) * (pExtents[0]);
            else if ((axE[2][0]) < 0.0f)
                (x[0]) = -(side) * (pExtents[0]);
            else
                (x[0]) = 0.0f;
        }
        {
            if ((axE[0][0]) > 0.0f)
                (x[2]) = -(side) * (pExtents[2]);
            else if ((axE[0][0]) < 0.0f)
                (x[2]) = (side) * (pExtents[2]);
            else
                (x[2]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[0] = vDelta.Cross(vEdge[0]);
        nDotDE[0] = vC10.Dot(vDCrossE[0]);
        nDotAE[0][0] = vC10.Dot(vC00);
        nDotAE[1][0] = vC10.Dot(vC10);
        nDotAE[2][0] = vC10.Dot(vC20);
        fNumerator = nDotDE[0] - (nDotAE[0][0] * x[0]) - (nDotAE[2][0] * x[2]);
        if (hitEdge == 0)
            x[1] = fNumerator / nDotAE[1][0];
        else
            x[1] = (fNumerator - vC10.Dot(vTriNormal)) / nDotAE[1][0];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 9: {
        {
            if ((axE[2][1]) > 0.0f)
                (x[0]) = (side) * (pExtents[0]);
            else if ((axE[2][1]) < 0.0f)
                (x[0]) = -(side) * (pExtents[0]);
            else
                (x[0]) = 0.0f;
        }
        {
            if ((axE[0][1]) > 0.0f)
                (x[2]) = -(side) * (pExtents[2]);
            else if ((axE[0][1]) < 0.0f)
                (x[2]) = (side) * (pExtents[2]);
            else
                (x[2]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[1] = vDelta.Cross(vEdge[1]);
        nDotDE[1] = vC11.Dot(vDCrossE[1]);
        nDotAE[0][1] = vC11.Dot(vC01);
        nDotAE[1][1] = vC11.Dot(vC11);
        nDotAE[2][1] = vC11.Dot(vC21);
        fNumerator = nDotDE[1] - (nDotAE[0][1] * x[0]) - (nDotAE[2][1] * x[2]);
        if (hitEdge == 0)
            x[1] = fNumerator / nDotAE[1][1];
        else
            x[1] = (fNumerator + vC11.Dot(vTriNormal)) / nDotAE[1][1];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 10: {
        vEdge[2] = vEdge[1] - vEdge[0];
        vC02 = axes[0].Cross(vEdge[2]);
        vC12 = axes[1].Cross(vEdge[2]);
        vC22 = axes[2].Cross(vEdge[2]);

        {
            if ((axE[2][2]) > 0.0f)
                (x[0]) = (side) * (pExtents[0]);
            else if ((axE[2][2]) < 0.0f)
                (x[0]) = -(side) * (pExtents[0]);
            else
                (x[0]) = 0.0f;
        }
        {
            if ((axE[0][2]) > 0.0f)
                (x[2]) = -(side) * (pExtents[2]);
            else if ((axE[0][2]) < 0.0f)
                (x[2]) = (side) * (pExtents[2]);
            else
                (x[2]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[2] = vDelta.Cross(vEdge[2]);
        nDotDE[2] = vC12.Dot(vDCrossE[2]);
        nDotAE[0][2] = vC12.Dot(vC02);
        nDotAE[1][2] = vC12.Dot(vC12);
        nDotAE[2][2] = vC12.Dot(vC22);
        fNumerator = nDotDE[2] - (nDotAE[0][2] * x[0]) - (nDotAE[2][2] * x[2]);
        if (hitEdge == 0)
            x[1] = fNumerator / nDotAE[1][2];
        else
            x[1] = (fNumerator + vC12.Dot(vTriNormal)) / nDotAE[1][2];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 11: {
        {
            if ((axE[1][0]) > 0.0f)
                (x[0]) = -(side) * (pExtents[0]);
            else if ((axE[1][0]) < 0.0f)
                (x[0]) = (side) * (pExtents[0]);
            else
                (x[0]) = 0.0f;
        }
        {
            if ((axE[0][0]) > 0.0f)
                (x[1]) = (side) * (pExtents[1]);
            else if ((axE[0][0]) < 0.0f)
                (x[1]) = -(side) * (pExtents[1]);
            else
                (x[1]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[0] = vDelta.Cross(vEdge[0]);
        nDotDE[0] = vC20.Dot(vDCrossE[0]);
        nDotAE[0][0] = vC20.Dot(vC00);
        nDotAE[1][0] = vC20.Dot(vC10);
        nDotAE[2][0] = vC20.Dot(vC20);
        fNumerator = nDotDE[0] - (nDotAE[0][0] * x[0]) - (nDotAE[1][0] * x[1]);
        if (hitEdge == 0)
            x[2] = fNumerator / nDotAE[2][0];
        else
            x[2] = (fNumerator - vC20.Dot(vTriNormal)) / nDotAE[2][0];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 12: {
        {
            if ((axE[1][1]) > 0.0f)
                (x[0]) = -(side) * (pExtents[0]);
            else if ((axE[1][1]) < 0.0f)
                (x[0]) = (side) * (pExtents[0]);
            else
                (x[0]) = 0.0f;
        }
        {
            if ((axE[0][1]) > 0.0f)
                (x[1]) = (side) * (pExtents[1]);
            else if ((axE[0][1]) < 0.0f)
                (x[1]) = -(side) * (pExtents[1]);
            else
                (x[1]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[1] = vDelta.Cross(vEdge[1]);
        nDotDE[1] = vC21.Dot(vDCrossE[1]);
        nDotAE[0][1] = vC21.Dot(vC01);
        nDotAE[1][1] = vC21.Dot(vC11);
        nDotAE[2][1] = vC21.Dot(vC21);
        fNumerator = nDotDE[1] - (nDotAE[0][1] * x[0]) - (nDotAE[1][1] * x[1]);
        if (hitEdge == 0)
            x[2] = fNumerator / nDotAE[2][1];
        else
            x[2] = (fNumerator + vC21.Dot(vTriNormal)) / nDotAE[2][1];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    case 13: {
        vEdge[2] = vEdge[1] - vEdge[0];
        vC02 = axes[0].Cross(vEdge[2]);
        vC12 = axes[1].Cross(vEdge[2]);
        vC22 = axes[2].Cross(vEdge[2]);

        {
            if ((axE[1][2]) > 0.0f)
                (x[0]) = -(side) * (pExtents[0]);
            else if ((axE[1][2]) < 0.0f)
                (x[0]) = (side) * (pExtents[0]);
            else
                (x[0]) = 0.0f;
        }
        {
            if ((axE[0][2]) > 0.0f)
                (x[1]) = (side) * (pExtents[1]);
            else if ((axE[0][2]) < 0.0f)
                (x[1]) = -(side) * (pExtents[1]);
            else
                (x[1]) = 0.0f;
        }
        vDelta += FUN_004a3760(hitTime, vRelVel);
        vDCrossE[2] = vDelta.Cross(vEdge[2]);
        nDotDE[2] = vC22.Dot(vDCrossE[2]);
        nDotAE[0][2] = vC22.Dot(vC02);
        nDotAE[1][2] = vC22.Dot(vC12);
        nDotAE[2][2] = vC22.Dot(vC22);
        fNumerator = nDotDE[2] - (nDotAE[0][2] * x[0]) - (nDotAE[1][2] * x[1]);
        if (hitEdge == 0)
            x[2] = fNumerator / nDotAE[2][2];
        else
            x[2] = (fNumerator + vC22.Dot(vTriNormal)) / nDotAE[2][2];

        {
            const ReworkPoint& center = (bv).GetNavMeshData();
            const ReworkPoint* axis = (bv).GetAxes();
            for (int k = 0; k < 3; k++)
            {
                (hitPoint)[k] =
                    center[k] + (hitTime) * (vel0)[k] + (x)[0] * axis[0][k] + (x)[1] * axis[1][k] + (x)[2] * axis[2][k];
            }
        }
        break;
    }
    }

    if (wantNormals)
    {

        normal1 = vTriNormal;
        normal1.Unitize_004a0c10();
        normal0 = -normal1;
    }

    return true;
}

#include <float.h>
class SweepPoint
{
  public:
    float x, y, z;
    SweepPoint()
    {}
    SweepPoint(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    SweepPoint FUN_00439e90(const SweepPoint& o) const
    {
        return SweepPoint(x + o.x, y + o.y, z + o.z);
    }
// src: GUESS 0x00439ef0 (confidence: high)
    SweepPoint SubtractIntoVector(const SweepPoint& o) const
    {
        return SweepPoint(x - o.x, y - o.y, z - o.z);
    }
    SweepPoint operator-() const
    {
        return SweepPoint(-x, -y, -z);
    }
    float DotProduct(const SweepPoint& o) const;
    SweepPoint FUN_004b3800(const SweepPoint& o) const
    {
        return SweepPoint(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x);
    }
    float FUN_004a7290() const
    {
        return x * x + y * y + z * z;
    }
    void Unitize_004a0c10();
    float& operator[](int i)
    {
        float* base = &x;
        return (float&)base[i];
    }
    const float& operator[](int i) const
    {
        const float* base = &x;
        return (float&)base[i];
    }
};
inline float SweepPoint::DotProduct(const SweepPoint& o) const
{
    return x * o.x + y * o.y + z * o.z;
}
inline SweepPoint __cdecl FUN_004a3760(float f, const SweepPoint& v)
{
    return SweepPoint(f * v.x, f * v.y, f * v.z);
}
extern const float DAT_0104da4c;
struct BoxGeometry
{
    SweepPoint center;
    SweepPoint axes[3];
    float extents[3];
};
struct SweepBox
{
    void* vtable;
    BoxGeometry geometry;
    const SweepPoint& GetNavMeshData() const
    {
        return geometry.center;
    }
    const SweepPoint* GetAxes() const
    {
        return geometry.axes;
    }
    const SweepPoint& GetAxis(int i) const
    {
        return geometry.axes[i];
    }
    const float* GetExtents() const
    {
        return geometry.extents;
    }
};
extern "C" double __cdecl fabs(double);
inline float NiAbs(float fValue)
{
    return float(fabs(fValue));
}
void __cdecl ClampPositionToBoxes(float fTime, const SweepBox* pkBox0, const SweepPoint* pkV0, const SweepBox* pkBox1,
                                  const SweepPoint* pkV1, float& fIntrTime, SweepPoint& kPoint);

// Tests two moving boxes over maxTime and writes hitTime and hitPoint, with normal outputs when requested.
// @fnv 0x00ea7d40
// src: XBOX_PDB 0x00ea7d40
bool __cdecl NiBoxBV_BoxBoxFindIntersect(float maxTime, const SweepBox& box0, const SweepPoint& vel0, const SweepBox& box1,
                          const SweepPoint& vel1, float& hitTime, SweepPoint& hitPoint, bool wantNormals,
                          SweepPoint& normal0, SweepPoint& normal1)
{
    const float fEpsilon = 1e-06f;
    const SweepBox& b0 = box0;
    const SweepBox& b1 = box1;
    const SweepPoint* A = b0.GetAxes();
    const SweepPoint* pkAxes1 = b1.GetAxes();
    const float* extA = b0.GetExtents();
    const float* pfExtents1 = b1.GetExtents();
    SweepPoint W;
    SweepPoint vRelPos0;
    SweepPoint vRelPos1;
    float afAxisDot[3][3];
    float afAbsAxisDot[3][3];
    float afAxisDotRel0[3];
    float afAxisDotRel1[3];
    float afAxisBDotRel0[3];
    float afAxisBDotRel1[3];
    float AR1[3];
    float BR0[3];
    float R0;
    float R1;
    float R;
    float Rsum;
    W = vel1.SubtractIntoVector(vel0);
    vRelPos0 = b1.GetNavMeshData().SubtractIntoVector(b0.GetNavMeshData());
    vRelPos1 = vRelPos0.FUN_00439e90(FUN_004a3760(maxTime, W));
    unsigned int hitAxis = 0;
    int side = 0;
    hitTime = 0.0f;
    afAxisDot[0][0] = A[0].DotProduct(pkAxes1[0]);
    afAxisDot[0][1] = A[0].DotProduct(pkAxes1[1]);
    afAxisDot[0][2] = A[0].DotProduct(pkAxes1[2]);
    afAxisDotRel0[0] = A[0].DotProduct(vRelPos0);
    afAxisDotRel1[0] = A[0].DotProduct(vRelPos1);
    afAbsAxisDot[0][0] = NiAbs(afAxisDot[0][0]);
    afAbsAxisDot[0][1] = NiAbs(afAxisDot[0][1]);
    afAbsAxisDot[0][2] = NiAbs(afAxisDot[0][2]);
    AR1[0] = (pfExtents1[0] * afAbsAxisDot[0][0]) + (pfExtents1[1] * afAbsAxisDot[0][1]) +
             (pfExtents1[2] * afAbsAxisDot[0][2]);
    Rsum = extA[0] + AR1[0];
    {
        float tmp;
        if (afAxisDotRel0[0] > Rsum)
        {
            if (afAxisDotRel1[0] > Rsum)
                return false;
            tmp = maxTime * (Rsum - afAxisDotRel0[0]) / (afAxisDotRel1[0] - afAxisDotRel0[0]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 1;
                side = 1;
            }
        }
        else if (afAxisDotRel0[0] < -Rsum)
        {
            if (afAxisDotRel1[0] < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + afAxisDotRel0[0]) / (afAxisDotRel1[0] - afAxisDotRel0[0]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 1;
                side = -1;
            }
        }
    }
    afAxisDot[1][0] = A[1].DotProduct(pkAxes1[0]);
    afAxisDot[1][1] = A[1].DotProduct(pkAxes1[1]);
    afAxisDot[1][2] = A[1].DotProduct(pkAxes1[2]);
    afAxisDotRel0[1] = A[1].DotProduct(vRelPos0);
    afAxisDotRel1[1] = A[1].DotProduct(vRelPos1);
    afAbsAxisDot[1][0] = NiAbs(afAxisDot[1][0]);
    afAbsAxisDot[1][1] = NiAbs(afAxisDot[1][1]);
    afAbsAxisDot[1][2] = NiAbs(afAxisDot[1][2]);
    AR1[1] = (pfExtents1[0] * afAbsAxisDot[1][0]) + (pfExtents1[1] * afAbsAxisDot[1][1]) +
             (pfExtents1[2] * afAbsAxisDot[1][2]);
    Rsum = extA[1] + AR1[1];
    {
        float tmp;
        if (afAxisDotRel0[1] > Rsum)
        {
            if (afAxisDotRel1[1] > Rsum)
                return false;
            tmp = maxTime * (Rsum - afAxisDotRel0[1]) / (afAxisDotRel1[1] - afAxisDotRel0[1]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 2;
                side = 1;
            }
        }
        else if (afAxisDotRel0[1] < -Rsum)
        {
            if (afAxisDotRel1[1] < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + afAxisDotRel0[1]) / (afAxisDotRel1[1] - afAxisDotRel0[1]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 2;
                side = -1;
            }
        }
    }
    afAxisDot[2][0] = A[2].DotProduct(pkAxes1[0]);
    afAxisDot[2][1] = A[2].DotProduct(pkAxes1[1]);
    afAxisDot[2][2] = A[2].DotProduct(pkAxes1[2]);
    afAxisDotRel0[2] = A[2].DotProduct(vRelPos0);
    afAxisDotRel1[2] = A[2].DotProduct(vRelPos1);
    afAbsAxisDot[2][0] = NiAbs(afAxisDot[2][0]);
    afAbsAxisDot[2][1] = NiAbs(afAxisDot[2][1]);
    afAbsAxisDot[2][2] = NiAbs(afAxisDot[2][2]);
    AR1[2] = (pfExtents1[0] * afAbsAxisDot[2][0]) + (pfExtents1[1] * afAbsAxisDot[2][1]) +
             (pfExtents1[2] * afAbsAxisDot[2][2]);
    Rsum = extA[2] + AR1[2];
    {
        float tmp;
        if (afAxisDotRel0[2] > Rsum)
        {
            if (afAxisDotRel1[2] > Rsum)
                return false;
            tmp = maxTime * (Rsum - afAxisDotRel0[2]) / (afAxisDotRel1[2] - afAxisDotRel0[2]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 3;
                side = 1;
            }
        }
        else if (afAxisDotRel0[2] < -Rsum)
        {
            if (afAxisDotRel1[2] < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + afAxisDotRel0[2]) / (afAxisDotRel1[2] - afAxisDotRel0[2]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 3;
                side = -1;
            }
        }
    }
    afAxisBDotRel0[0] = pkAxes1[0].DotProduct(vRelPos0);
    afAxisBDotRel1[0] = pkAxes1[0].DotProduct(vRelPos1);
    BR0[0] = (extA[0] * afAbsAxisDot[0][0]) + (extA[1] * afAbsAxisDot[1][0]) + (extA[2] * afAbsAxisDot[2][0]);
    Rsum = BR0[0] + pfExtents1[0];
    {
        float tmp;
        if (afAxisBDotRel0[0] > Rsum)
        {
            if (afAxisBDotRel1[0] > Rsum)
                return false;
            tmp = maxTime * (Rsum - afAxisBDotRel0[0]) / (afAxisBDotRel1[0] - afAxisBDotRel0[0]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 4;
                side = 1;
            }
        }
        else if (afAxisBDotRel0[0] < -Rsum)
        {
            if (afAxisBDotRel1[0] < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + afAxisBDotRel0[0]) / (afAxisBDotRel1[0] - afAxisBDotRel0[0]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 4;
                side = -1;
            }
        }
    }
    afAxisBDotRel0[1] = pkAxes1[1].DotProduct(vRelPos0);
    afAxisBDotRel1[1] = pkAxes1[1].DotProduct(vRelPos1);
    BR0[1] = (extA[0] * afAbsAxisDot[0][1]) + (extA[1] * afAbsAxisDot[1][1]) + (extA[2] * afAbsAxisDot[2][1]);
    Rsum = BR0[1] + pfExtents1[1];
    {
        float tmp;
        if (afAxisBDotRel0[1] > Rsum)
        {
            if (afAxisBDotRel1[1] > Rsum)
                return false;
            tmp = maxTime * (Rsum - afAxisBDotRel0[1]) / (afAxisBDotRel1[1] - afAxisBDotRel0[1]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 5;
                side = 1;
            }
        }
        else if (afAxisBDotRel0[1] < -Rsum)
        {
            if (afAxisBDotRel1[1] < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + afAxisBDotRel0[1]) / (afAxisBDotRel1[1] - afAxisBDotRel0[1]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 5;
                side = -1;
            }
        }
    }
    afAxisBDotRel0[2] = pkAxes1[2].DotProduct(vRelPos0);
    afAxisBDotRel1[2] = pkAxes1[2].DotProduct(vRelPos1);
    BR0[2] = (extA[0] * afAbsAxisDot[0][2]) + (extA[1] * afAbsAxisDot[1][2]) + (extA[2] * afAbsAxisDot[2][2]);
    Rsum = BR0[2] + pfExtents1[2];
    {
        float tmp;
        if (afAxisBDotRel0[2] > Rsum)
        {
            if (afAxisBDotRel1[2] > Rsum)
                return false;
            tmp = maxTime * (Rsum - afAxisBDotRel0[2]) / (afAxisBDotRel1[2] - afAxisBDotRel0[2]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 6;
                side = 1;
            }
        }
        else if (afAxisBDotRel0[2] < -Rsum)
        {
            if (afAxisBDotRel1[2] < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + afAxisBDotRel0[2]) / (afAxisBDotRel1[2] - afAxisBDotRel0[2]);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 6;
                side = -1;
            }
        }
    }
    R0 = (extA[1] * afAbsAxisDot[2][0]) + (extA[2] * afAbsAxisDot[1][0]);
    R1 = (pfExtents1[1] * afAbsAxisDot[0][2]) + (pfExtents1[2] * afAbsAxisDot[0][1]);
    R = (afAxisDotRel0[2] * afAxisDot[1][0]) - (afAxisDotRel0[1] * afAxisDot[2][0]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[2] * afAxisDot[1][0]) - (afAxisDotRel1[1] * afAxisDot[2][0]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 7;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[2] * afAxisDot[1][0]) - (afAxisDotRel1[1] * afAxisDot[2][0]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 7;
                side = -1;
            }
        }
    }
    R0 = (extA[1] * afAbsAxisDot[2][1]) + (extA[2] * afAbsAxisDot[1][1]);
    R1 = (pfExtents1[0] * afAbsAxisDot[0][2]) + (pfExtents1[2] * afAbsAxisDot[0][0]);
    R = (afAxisDotRel0[2] * afAxisDot[1][1]) - (afAxisDotRel0[1] * afAxisDot[2][1]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[2] * afAxisDot[1][1]) - (afAxisDotRel1[1] * afAxisDot[2][1]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 8;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[2] * afAxisDot[1][1]) - (afAxisDotRel1[1] * afAxisDot[2][1]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 8;
                side = -1;
            }
        }
    }
    R0 = (extA[1] * afAbsAxisDot[2][2]) + (extA[2] * afAbsAxisDot[1][2]);
    R1 = (pfExtents1[0] * afAbsAxisDot[0][1]) + (pfExtents1[1] * afAbsAxisDot[0][0]);
    R = (afAxisDotRel0[2] * afAxisDot[1][2]) - (afAxisDotRel0[1] * afAxisDot[2][2]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[2] * afAxisDot[1][2]) - (afAxisDotRel1[1] * afAxisDot[2][2]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 9;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[2] * afAxisDot[1][2]) - (afAxisDotRel1[1] * afAxisDot[2][2]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 9;
                side = -1;
            }
        }
    }
    R0 = (extA[0] * afAbsAxisDot[2][0]) + (extA[2] * afAbsAxisDot[0][0]);
    R1 = (pfExtents1[1] * afAbsAxisDot[1][2]) + (pfExtents1[2] * afAbsAxisDot[1][1]);
    R = (afAxisDotRel0[0] * afAxisDot[2][0]) - (afAxisDotRel0[2] * afAxisDot[0][0]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[0] * afAxisDot[2][0]) - (afAxisDotRel1[2] * afAxisDot[0][0]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 10;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[0] * afAxisDot[2][0]) - (afAxisDotRel1[2] * afAxisDot[0][0]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 10;
                side = -1;
            }
        }
    }
    R0 = (extA[0] * afAbsAxisDot[2][1]) + (extA[2] * afAbsAxisDot[0][1]);
    R1 = (pfExtents1[0] * afAbsAxisDot[1][2]) + (pfExtents1[2] * afAbsAxisDot[1][0]);
    R = (afAxisDotRel0[0] * afAxisDot[2][1]) - (afAxisDotRel0[2] * afAxisDot[0][1]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[0] * afAxisDot[2][1]) - (afAxisDotRel1[2] * afAxisDot[0][1]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 11;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[0] * afAxisDot[2][1]) - (afAxisDotRel1[2] * afAxisDot[0][1]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 11;
                side = -1;
            }
        }
    }
    R0 = (extA[0] * afAbsAxisDot[2][2]) + (extA[2] * afAbsAxisDot[0][2]);
    R1 = (pfExtents1[0] * afAbsAxisDot[1][1]) + (pfExtents1[1] * afAbsAxisDot[1][0]);
    R = (afAxisDotRel0[0] * afAxisDot[2][2]) - (afAxisDotRel0[2] * afAxisDot[0][2]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[0] * afAxisDot[2][2]) - (afAxisDotRel1[2] * afAxisDot[0][2]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 12;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[0] * afAxisDot[2][2]) - (afAxisDotRel1[2] * afAxisDot[0][2]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 12;
                side = -1;
            }
        }
    }
    R0 = (extA[0] * afAbsAxisDot[1][0]) + (extA[1] * afAbsAxisDot[0][0]);
    R1 = (pfExtents1[1] * afAbsAxisDot[2][2]) + (pfExtents1[2] * afAbsAxisDot[2][1]);
    R = (afAxisDotRel0[1] * afAxisDot[0][0]) - (afAxisDotRel0[0] * afAxisDot[1][0]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[1] * afAxisDot[0][0]) - (afAxisDotRel1[0] * afAxisDot[1][0]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 13;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[1] * afAxisDot[0][0]) - (afAxisDotRel1[0] * afAxisDot[1][0]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 13;
                side = -1;
            }
        }
    }
    R0 = (extA[0] * afAbsAxisDot[1][1]) + (extA[1] * afAbsAxisDot[0][1]);
    R1 = (pfExtents1[0] * afAbsAxisDot[2][2]) + (pfExtents1[2] * afAbsAxisDot[2][0]);
    R = (afAxisDotRel0[1] * afAxisDot[0][1]) - (afAxisDotRel0[0] * afAxisDot[1][1]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[1] * afAxisDot[0][1]) - (afAxisDotRel1[0] * afAxisDot[1][1]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 14;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[1] * afAxisDot[0][1]) - (afAxisDotRel1[0] * afAxisDot[1][1]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 14;
                side = -1;
            }
        }
    }
    R0 = (extA[0] * afAbsAxisDot[1][2]) + (extA[1] * afAbsAxisDot[0][2]);
    R1 = (pfExtents1[0] * afAbsAxisDot[2][1]) + (pfExtents1[1] * afAbsAxisDot[2][0]);
    R = (afAxisDotRel0[1] * afAxisDot[0][2]) - (afAxisDotRel0[0] * afAxisDot[1][2]);
    Rsum = R0 + R1;
    {
        float q, tmp;
        if (R > Rsum)
        {
            q = (afAxisDotRel1[1] * afAxisDot[0][2]) - (afAxisDotRel1[0] * afAxisDot[1][2]);
            if (q > Rsum)
                return false;
            tmp = maxTime * (Rsum - R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 15;
                side = 1;
            }
        }
        else if (R < -Rsum)
        {
            q = (afAxisDotRel1[1] * afAxisDot[0][2]) - (afAxisDotRel1[0] * afAxisDot[1][2]);
            if (q < -Rsum)
                return false;
            tmp = -maxTime * (Rsum + R) / (q - R);
            if (tmp > hitTime + FLT_EPSILON)
            {
                hitTime = tmp;
                hitAxis = 15;
                side = -1;
            }
        }
    }
    int i, iAxisB;
    float x[3], y[3], fDotA, fDotB, fDivisor, tmp;
    SweepPoint D;
    switch (hitAxis)
    {
    case 0: {
        hitPoint = FUN_004a3760(0.5f, b0.GetNavMeshData().FUN_00439e90(b1.GetNavMeshData()));
        if (wantNormals)
            normal0 = hitPoint.SubtractIntoVector(b0.GetNavMeshData());
        break;
    }
    case 1:
    case 2:
    case 3: {
        i = hitAxis - 1;
        if (afAxisDot[i][0] > 0.0f)
            y[0] = -side * pfExtents1[0];
        else if (afAxisDot[i][0] < 0.0f)
            y[0] = side * pfExtents1[0];
        else
            y[0] = 0.0f;
        if (afAxisDot[i][1] > 0.0f)
            y[1] = -side * pfExtents1[1];
        else if (afAxisDot[i][1] < 0.0f)
            y[1] = side * pfExtents1[1];
        else
            y[1] = 0.0f;
        if (afAxisDot[i][2] > 0.0f)
            y[2] = -side * pfExtents1[2];
        else if (afAxisDot[i][2] < 0.0f)
            y[2] = side * pfExtents1[2];
        else
            y[2] = 0.0f;
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b1.GetNavMeshData()[k] + (hitTime * vel1[k]) + y[0] * b1.GetAxis(0)[k] +
                          y[1] * b1.GetAxis(1)[k] + y[2] * b1.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b1, &vel1, &b0, &vel0, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[i];
            else
                normal0 = A[i];
            normal1 = -normal0;
        }
        return true;
    }
    case 4:
    case 5:
    case 6: {
        iAxisB = hitAxis - 4;
        if (afAxisDot[0][iAxisB] > 0.0f)
            x[0] = side * extA[0];
        else if (afAxisDot[0][iAxisB] < 0.0f)
            x[0] = -side * extA[0];
        else
            x[0] = 0.0f;
        if (afAxisDot[1][iAxisB] > 0.0f)
            x[1] = side * extA[1];
        else if (afAxisDot[1][iAxisB] < 0.0f)
            x[1] = -side * extA[1];
        else
            x[1] = 0.0f;
        if (afAxisDot[2][iAxisB] > 0.0f)
            x[2] = side * extA[2];
        else if (afAxisDot[2][iAxisB] < 0.0f)
            x[2] = -side * extA[2];
        else
            x[2] = 0.0f;
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -pkAxes1[iAxisB];
            else
                normal0 = pkAxes1[iAxisB];
            normal1 = -normal0;
        }
        return true;
    }
    case 7: {
        if (afAxisDot[2][0] > 0.0f)
            x[1] = -side * extA[1];
        else if (afAxisDot[2][0] < 0.0f)
            x[1] = side * extA[1];
        else
            x[1] = 0.0f;
        if (afAxisDot[1][0] > 0.0f)
            x[2] = side * extA[2];
        else if (afAxisDot[1][0] < 0.0f)
            x[2] = -side * extA[2];
        else
            x[2] = 0.0f;
        if (afAxisDot[0][2] > 0.0f)
            y[1] = -side * pfExtents1[1];
        else if (afAxisDot[0][2] < 0.0f)
            y[1] = side * pfExtents1[1];
        else
            y[1] = 0.0f;
        if (afAxisDot[0][1] > 0.0f)
            y[2] = side * pfExtents1[2];
        else if (afAxisDot[0][1] < 0.0f)
            y[2] = -side * pfExtents1[2];
        else
            y[2] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[0][0] * afAxisDot[0][0]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[0].DotProduct(D);
            fDotB = pkAxes1[0].DotProduct(D);
            tmp = (afAxisDot[1][0] * x[1]) + (afAxisDot[2][0] * x[2]) - fDotB;
            x[0] = (fDotA + (afAxisDot[0][0] * tmp) + (afAxisDot[0][1] * y[1]) + (afAxisDot[0][2] * y[2])) / fDivisor;
        }
        else
        {
            x[0] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[0].FUN_004b3800(pkAxes1[0]);
            else
                normal0 = A[0].FUN_004b3800(pkAxes1[0]);
        }
        break;
    }
    case 8: {
        if (afAxisDot[2][1] > 0.0f)
            x[1] = -side * extA[1];
        else if (afAxisDot[2][1] < 0.0f)
            x[1] = side * extA[1];
        else
            x[1] = 0.0f;
        if (afAxisDot[1][1] > 0.0f)
            x[2] = side * extA[2];
        else if (afAxisDot[1][1] < 0.0f)
            x[2] = -side * extA[2];
        else
            x[2] = 0.0f;
        if (afAxisDot[0][2] > 0.0f)
            y[0] = side * pfExtents1[0];
        else if (afAxisDot[0][2] < 0.0f)
            y[0] = -side * pfExtents1[0];
        else
            y[0] = 0.0f;
        if (afAxisDot[0][0] > 0.0f)
            y[2] = -side * pfExtents1[2];
        else if (afAxisDot[0][0] < 0.0f)
            y[2] = side * pfExtents1[2];
        else
            y[2] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[0][1] * afAxisDot[0][1]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[0].DotProduct(D);
            fDotB = pkAxes1[1].DotProduct(D);
            tmp = (afAxisDot[1][1] * x[1]) + (afAxisDot[2][1] * x[2]) - fDotB;
            x[0] = (fDotA + (afAxisDot[0][1] * tmp) + (afAxisDot[0][0] * y[0]) + (afAxisDot[0][2] * y[2])) / fDivisor;
        }
        else
        {
            x[0] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[0].FUN_004b3800(pkAxes1[1]);
            else
                normal0 = A[0].FUN_004b3800(pkAxes1[1]);
        }
        break;
    }
    case 9: {
        if (afAxisDot[2][2] > 0.0f)
            x[1] = -side * extA[1];
        else if (afAxisDot[2][2] < 0.0f)
            x[1] = side * extA[1];
        else
            x[1] = 0.0f;
        if (afAxisDot[1][2] > 0.0f)
            x[2] = side * extA[2];
        else if (afAxisDot[1][2] < 0.0f)
            x[2] = -side * extA[2];
        else
            x[2] = 0.0f;
        if (afAxisDot[0][1] > 0.0f)
            y[0] = -side * pfExtents1[0];
        else if (afAxisDot[0][1] < 0.0f)
            y[0] = side * pfExtents1[0];
        else
            y[0] = 0.0f;
        if (afAxisDot[0][0] > 0.0f)
            y[1] = side * pfExtents1[1];
        else if (afAxisDot[0][0] < 0.0f)
            y[1] = -side * pfExtents1[1];
        else
            y[1] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[0][2] * afAxisDot[0][2]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[0].DotProduct(D);
            fDotB = pkAxes1[2].DotProduct(D);
            tmp = (afAxisDot[1][2] * x[1]) + (afAxisDot[2][2] * x[2]) - fDotB;
            x[0] = (fDotA + (afAxisDot[0][2] * tmp) + (afAxisDot[0][0] * y[0]) + (afAxisDot[0][1] * y[1])) / fDivisor;
        }
        else
        {
            x[0] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[0].FUN_004b3800(pkAxes1[2]);
            else
                normal0 = A[0].FUN_004b3800(pkAxes1[2]);
        }
        break;
    }
    case 10: {
        if (afAxisDot[2][0] > 0.0f)
            x[0] = side * extA[0];
        else if (afAxisDot[2][0] < 0.0f)
            x[0] = -side * extA[0];
        else
            x[0] = 0.0f;
        if (afAxisDot[0][0] > 0.0f)
            x[2] = -side * extA[2];
        else if (afAxisDot[0][0] < 0.0f)
            x[2] = side * extA[2];
        else
            x[2] = 0.0f;
        if (afAxisDot[1][2] > 0.0f)
            y[1] = -side * pfExtents1[1];
        else if (afAxisDot[1][2] < 0.0f)
            y[1] = side * pfExtents1[1];
        else
            y[1] = 0.0f;
        if (afAxisDot[1][1] > 0.0f)
            y[2] = side * pfExtents1[2];
        else if (afAxisDot[1][1] < 0.0f)
            y[2] = -side * pfExtents1[2];
        else
            y[2] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[1][0] * afAxisDot[1][0]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[1].DotProduct(D);
            fDotB = pkAxes1[0].DotProduct(D);
            tmp = (afAxisDot[0][0] * x[0]) + (afAxisDot[2][0] * x[2]) - fDotB;
            x[1] = (fDotA + (afAxisDot[1][0] * tmp) + (afAxisDot[1][1] * y[1]) + (afAxisDot[1][2] * y[2])) / fDivisor;
        }
        else
        {
            x[1] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[1].FUN_004b3800(pkAxes1[0]);
            else
                normal0 = A[1].FUN_004b3800(pkAxes1[0]);
        }
        break;
    }
    case 11: {
        if (afAxisDot[2][1] > 0.0f)
            x[0] = side * extA[0];
        else if (afAxisDot[2][1] < 0.0f)
            x[0] = -side * extA[0];
        else
            x[0] = 0.0f;
        if (afAxisDot[0][1] > 0.0f)
            x[2] = -side * extA[2];
        else if (afAxisDot[0][1] < 0.0f)
            x[2] = side * extA[2];
        else
            x[2] = 0.0f;
        if (afAxisDot[1][2] > 0.0f)
            y[0] = side * pfExtents1[0];
        else if (afAxisDot[1][2] < 0.0f)
            y[0] = -side * pfExtents1[0];
        else
            y[0] = 0.0f;
        if (afAxisDot[1][0] > 0.0f)
            y[2] = -side * pfExtents1[2];
        else if (afAxisDot[1][0] < 0.0f)
            y[2] = side * pfExtents1[2];
        else
            y[2] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[1][1] * afAxisDot[1][1]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[1].DotProduct(D);
            fDotB = pkAxes1[1].DotProduct(D);
            tmp = (afAxisDot[0][1] * x[0]) + (afAxisDot[2][1] * x[2]) - fDotB;
            x[1] = (fDotA + (afAxisDot[1][1] * tmp) + (afAxisDot[1][0] * y[0]) + (afAxisDot[1][2] * y[2])) / fDivisor;
        }
        else
        {
            x[1] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[1].FUN_004b3800(pkAxes1[1]);
            else
                normal0 = A[1].FUN_004b3800(pkAxes1[1]);
        }
        break;
    }
    case 12: {
        if (afAxisDot[2][2] > 0.0f)
            x[0] = side * extA[0];
        else if (afAxisDot[2][2] < 0.0f)
            x[0] = -side * extA[0];
        else
            x[0] = 0.0f;
        if (afAxisDot[0][2] > 0.0f)
            x[2] = -side * extA[2];
        else if (afAxisDot[0][2] < 0.0f)
            x[2] = side * extA[2];
        else
            x[2] = 0.0f;
        if (afAxisDot[1][1] > 0.0f)
            y[0] = -side * pfExtents1[0];
        else if (afAxisDot[1][1] < 0.0f)
            y[0] = side * pfExtents1[0];
        else
            y[0] = 0.0f;
        if (afAxisDot[1][0] > 0.0f)
            y[1] = side * pfExtents1[1];
        else if (afAxisDot[1][0] < 0.0f)
            y[1] = -side * pfExtents1[1];
        else
            y[1] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[1][2] * afAxisDot[1][2]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[1].DotProduct(D);
            fDotB = pkAxes1[2].DotProduct(D);
            tmp = (afAxisDot[0][2] * x[0]) + (afAxisDot[2][2] * x[2]) - fDotB;
            x[1] = (fDotA + (afAxisDot[1][2] * tmp) + (afAxisDot[1][0] * y[0]) + (afAxisDot[1][1] * y[1])) / fDivisor;
        }
        else
        {
            x[1] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[1].FUN_004b3800(pkAxes1[2]);
            else
                normal0 = A[1].FUN_004b3800(pkAxes1[2]);
        }
        break;
    }
    case 13: {
        if (afAxisDot[1][0] > 0.0f)
            x[0] = -side * extA[0];
        else if (afAxisDot[1][0] < 0.0f)
            x[0] = side * extA[0];
        else
            x[0] = 0.0f;
        if (afAxisDot[0][0] > 0.0f)
            x[1] = side * extA[1];
        else if (afAxisDot[0][0] < 0.0f)
            x[1] = -side * extA[1];
        else
            x[1] = 0.0f;
        if (afAxisDot[2][2] > 0.0f)
            y[1] = -side * pfExtents1[1];
        else if (afAxisDot[2][2] < 0.0f)
            y[1] = side * pfExtents1[1];
        else
            y[1] = 0.0f;
        if (afAxisDot[2][1] > 0.0f)
            y[2] = side * pfExtents1[2];
        else if (afAxisDot[2][1] < 0.0f)
            y[2] = -side * pfExtents1[2];
        else
            y[2] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[2][0] * afAxisDot[2][0]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[2].DotProduct(D);
            fDotB = pkAxes1[0].DotProduct(D);
            tmp = (afAxisDot[0][0] * x[0]) + (afAxisDot[1][0] * x[1]) - fDotB;
            x[2] = (fDotA + (afAxisDot[2][0] * tmp) + (afAxisDot[2][1] * y[1]) + (afAxisDot[2][2] * y[2])) / fDivisor;
        }
        else
        {
            x[2] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[2].FUN_004b3800(pkAxes1[0]);
            else
                normal0 = A[2].FUN_004b3800(pkAxes1[0]);
        }
        break;
    }
    case 14: {
        if (afAxisDot[1][1] > 0.0f)
            x[0] = -side * extA[0];
        else if (afAxisDot[1][1] < 0.0f)
            x[0] = side * extA[0];
        else
            x[0] = 0.0f;
        if (afAxisDot[0][1] > 0.0f)
            x[1] = side * extA[1];
        else if (afAxisDot[0][1] < 0.0f)
            x[1] = -side * extA[1];
        else
            x[1] = 0.0f;
        if (afAxisDot[2][2] > 0.0f)
            y[0] = side * pfExtents1[0];
        else if (afAxisDot[2][2] < 0.0f)
            y[0] = -side * pfExtents1[0];
        else
            y[0] = 0.0f;
        if (afAxisDot[2][0] > 0.0f)
            y[2] = -side * pfExtents1[2];
        else if (afAxisDot[2][0] < 0.0f)
            y[2] = side * pfExtents1[2];
        else
            y[2] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[2][1] * afAxisDot[2][1]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[2].DotProduct(D);
            fDotB = pkAxes1[1].DotProduct(D);
            tmp = (afAxisDot[0][1] * x[0]) + (afAxisDot[1][1] * x[1]) - fDotB;
            x[2] = (fDotA + (afAxisDot[2][1] * tmp) + (afAxisDot[2][0] * y[0]) + (afAxisDot[2][2] * y[2])) / fDivisor;
        }
        else
        {
            x[2] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[2].FUN_004b3800(pkAxes1[1]);
            else
                normal0 = A[2].FUN_004b3800(pkAxes1[1]);
        }
        break;
    }
    case 15: {
        if (afAxisDot[1][2] > 0.0f)
            x[0] = -side * extA[0];
        else if (afAxisDot[1][2] < 0.0f)
            x[0] = side * extA[0];
        else
            x[0] = 0.0f;
        if (afAxisDot[0][2] > 0.0f)
            x[1] = side * extA[1];
        else if (afAxisDot[0][2] < 0.0f)
            x[1] = -side * extA[1];
        else
            x[1] = 0.0f;
        if (afAxisDot[2][1] > 0.0f)
            y[0] = -side * pfExtents1[0];
        else if (afAxisDot[2][1] < 0.0f)
            y[0] = side * pfExtents1[0];
        else
            y[0] = 0.0f;
        if (afAxisDot[2][0] > 0.0f)
            y[1] = side * pfExtents1[1];
        else if (afAxisDot[2][0] < 0.0f)
            y[1] = -side * pfExtents1[1];
        else
            y[1] = 0.0f;
        fDivisor = 1.0f - (afAxisDot[2][2] * afAxisDot[2][2]);
        if (NiAbs(fDivisor) > fEpsilon)
        {
            D = vRelPos0.FUN_00439e90(FUN_004a3760(hitTime, W));
            fDotA = A[2].DotProduct(D);
            fDotB = pkAxes1[2].DotProduct(D);
            tmp = (afAxisDot[0][2] * x[0]) + (afAxisDot[1][2] * x[1]) - fDotB;
            x[2] = (fDotA + (afAxisDot[2][2] * tmp) + (afAxisDot[2][0] * y[0]) + (afAxisDot[2][1] * y[1])) / fDivisor;
        }
        else
        {
            x[2] = 0.0f;
        }
        for (int k = 0; k < 3; k++)
        {
            hitPoint[k] = b0.GetNavMeshData()[k] + (hitTime * vel0[k]) + x[0] * b0.GetAxis(0)[k] +
                          x[1] * b0.GetAxis(1)[k] + x[2] * b0.GetAxis(2)[k];
        }
        ClampPositionToBoxes(maxTime, &b0, &vel0, &b1, &vel1, hitTime, hitPoint);
        if (wantNormals)
        {
            if (side < 0)
                normal0 = -A[2].FUN_004b3800(pkAxes1[2]);
            else
                normal0 = A[2].FUN_004b3800(pkAxes1[2]);
        }
        break;
    }
    }
    if (wantNormals)
    {
        const float fNormalSqrLength = normal0.FUN_004a7290();
        if (NiAbs(fNormalSqrLength - 1.0) > DAT_0104da4c)
        {
            if (fNormalSqrLength > DAT_0104da4c)
                normal0.Unitize_004a0c10();
            else
                normal0 = reinterpret_cast<const SweepPoint&>(DAT_011a946c);
        }
        normal1 = -normal0;
    }
    return true;
}
