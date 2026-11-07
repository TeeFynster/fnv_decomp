
// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's float-only intrinsic representation: the CRT's integer lanes
// otherwise change alias analysis and introduce a stack-security buffer.
#define _INCLUDED_MM2
// Exe 0x00d22370 GetSupportVertex: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ps(float const*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_load_ss(float const*);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_set_ps1(float);

#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4q.h"


extern char const* const g_01268970_arg1;
void __cdecl hkReferencedObject_calcContentStatistics(char const* const* arg1, char const* const* arg2);

// @fnv 0x00d22360
// src: XBOX_PDB 0x00d22360
void __cdecl hkpCapsuleShape_calcContentStatistics(char const* const* arg1, char const* const* arg2)
{
    hkReferencedObject_calcContentStatistics(arg1, &g_01268970_arg1);
}

// @fnv 0x00d22350
int hkpCapsuleShape::GetNumCollisionSpheres() const
{
    return 2;
}

// @fnv 0x00d22d60
int hkpCapsuleShape::CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const
{
    return 0x40;
}


// @fnv 0x00d223f0
void hkpCapsuleShape::GetVerticesFromIds(const hkpVertexId* indices, int count, Vector4WithInt24W* out) const
{
    int iRemaining = count - 1;
    if (iRemaining < 0)
    {
        return;
    }
    hkVector4* pOut = reinterpret_cast<hkVector4*>(out);
    unsigned short const* p = indices;
    do
    {
        unsigned int uiIndex = *p;
        LocalM128 v = _mm_load_ps(reinterpret_cast<float const*>(reinterpret_cast<const char*>(this) + uiIndex + 0x20));
        _mm_store_ps(reinterpret_cast<float*>(pOut), v);
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pOut) + 0xc) = uiIndex | 0x3f000000;
        pOut++;
        p++;
        iRemaining--;
    } while (iRemaining >= 0);
}

// @fnv 0x00d22480
void hkpCapsuleShape::GetFirstVertex(hkVector4& out) const
{
    out = m_kVertexB;
}

// @fnv 0x00d224a0
const hkSphere* hkpCapsuleShape::GetCollisionSpheres(hkSphere* sphereBuffer) const
{
    LocalM128* result = reinterpret_cast<LocalM128*>(sphereBuffer);
    result[0] = m_kVertexA.m_vComponents;
    result[1] = m_kVertexB.m_vComponents;
    return sphereBuffer;
}

extern int DAT_010ce25c;


template <typename ENUM, typename STORAGE>
__forceinline hkEnum<ENUM, STORAGE>::hkEnum()
{}

__forceinline hkpShape::hkpShape()
{
    m_ulUserData = 0;
}

__forceinline hkpConvexShape::hkpConvexShape(hkpShapeType type, hkReal radius)
{
    m_fSphereRadius = radius;
    *reinterpret_cast<unsigned int*>(&m_type) = type;
}

// Initializes a capsule shape from two points and a radius, storing the radius in both endpoints' w components and setting the type to 5.
// @fnv 0x00d22590
hkpCapsuleShape::hkpCapsuleShape(const hkVector4& first, const hkVector4& second, hkReal radius)
    : hkpConvexShape(HK_SHAPE_CAPSULE, radius)
{
    m_fSphereRadius = radius;
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    *reinterpret_cast<unsigned int*>(&m_type) = 5;
    *reinterpret_cast<void**>(this) = &DAT_010ce25c;
    m_kVertexA.m_vComponents = first.m_vComponents;
    m_kVertexB.m_vComponents = second.m_vComponents;
    *reinterpret_cast<volatile float*>(&m_kVertexA.w) = radius;
    *reinterpret_cast<volatile float*>(&m_kVertexB.w) = radius;
}

struct __declspec(align(16)) Point4
{
    float x, y, z, w;
};
struct ClosestLineResult
{
    float distance;
    float fractionA;
    float fractionB;
    float extraValue;
    Point4 pointA;
    Point4 pointB;
};
void __cdecl hkLineSegmentUtil_closestPointInfLineInfLine(const Point4& a, const Point4& b, const Point4& c, const Point4& d, ClosestLineResult* out);
// Calls FUN_00d231b0 to compute the closest points between two lines and writes the points, fractions and distance to the output pointers.
// @fnv 0x00d22700
void __cdecl GetClosestLinePoints(const Point4& aLineAStart, const Point4& aLineAEnd, const Point4& aLineBStart,
                                  const Point4& aLineBEnd, float* pfDistance, float* pfFractionA, float* pfFractionB,
                                  Point4* pointA, Point4* pointB)
{
    ClosestLineResult result;
    hkLineSegmentUtil_closestPointInfLineInfLine(aLineAStart, aLineAEnd, aLineBStart, aLineBEnd, &result);
    *reinterpret_cast<LocalM128*>(pointA) = *reinterpret_cast<const LocalM128*>(&result.pointA);
    *reinterpret_cast<LocalM128*>(pointB) = *reinterpret_cast<const LocalM128*>(&result.pointB);
    *pfFractionA = result.fractionA;
    *pfFractionB = result.fractionB;
    *pfDistance = result.distance;
}

extern float DAT_01016248;

// Stores (m_kMax + m_kMin) scaled by the float at DAT_01016248 into pkCenter.
// @fnv 0x00d22440
void hkpCapsuleShape::GetCentre(hkVector4& centreOut) const
{
    LocalM128* pkCenter = &centreOut.m_vComponents;
    LocalM128 sum = _mm_add_ps(m_kVertexB.m_vComponents, m_kVertexA.m_vComponents);
    *pkCenter = sum;
    LocalM128 kHalf = _mm_load_ss(&DAT_01016248);
    kHalf = _mm_shuffle_ps(kHalf, kHalf, 0);
    *pkCenter = _mm_mul_ps(kHalf, sum);
}


// Projects a point onto a line segment defined by two endpoints, clamping the result to the segment bounds and writing it to out.
// @fnv 0x00d224c0
// src: XBOX_PDB 0x00d224c0
void __cdecl hkpCapsuleShape_closestPointLineSeg(float* apPoint, float* apStart, float* apEnd, float* out)
{
    LocalM128 vStart = _mm_load_ps(apStart);
    LocalM128 vEnd = _mm_load_ps(apEnd);
    LocalM128 vPoint = _mm_load_ps(apPoint);

    LocalM128 xmm2 = vStart;
    LocalM128 xmm3 = vEnd;
    LocalM128 xmm4 = vPoint;

    LocalM128 xmm1 = _mm_sub_ps(xmm3, xmm2);
    LocalM128 xmm0 = _mm_sub_ps(xmm2, xmm4);

    xmm0 = _mm_mul_ps(xmm0, xmm1);

    LocalM128 temp4 = xmm0;
    temp4 = _mm_shuffle_ps(temp4, xmm0, 0x55);
    temp4 = _mm_add_ss(temp4, xmm0);

    LocalM128 temp5 = xmm0;
    temp5 = _mm_shuffle_ps(temp5, xmm0, 0xaa);
    temp5 = _mm_add_ss(temp5, temp4);

    float negDot;
    float lenSq;

    _mm_store_ss(&negDot, temp5);
    negDot = -negDot;

    LocalM128 l0 = _mm_mul_ps(xmm1, xmm1);
    LocalM128 ls1 = _mm_shuffle_ps(l0, l0, 0x55);
    ls1 = _mm_add_ss(ls1, l0);
    LocalM128 ls2 = _mm_shuffle_ps(l0, l0, 0xaa);
    ls2 = _mm_add_ss(ls2, ls1);

    _mm_store_ss(&lenSq, ls2);

    if (negDot <= 0.0f)
    {
        _mm_store_ps(out, vStart);
        return;
    }

    if (lenSq <= negDot)
    {
        _mm_store_ps(out, vEnd);
        return;
    }

    negDot /= lenSq;

    LocalM128 tVec = _mm_load_ss(&negDot);
    LocalM128 tBroadcast = _mm_shuffle_ps(tVec, tVec, 0);
    LocalM128 scaledDiff = _mm_mul_ps(xmm1, tBroadcast);
    LocalM128 result = _mm_add_ps(vStart, scaledDiff);

    _mm_store_ps(out, result);
}

__forceinline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x)
{}

__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
}

// Picks vertex A or B by the sign of (B - A) dot kDirection, writes it to kSupportingVertexOut, and stores the vertex id (0 or 16) in W.
// @fnv 0x00d22370
void hkpCapsuleShape::GetSupportVertex(const hkVector4& kDirection, Vector4WithInt24W& supportingVertexOut) const
{
    hkVector4& kSupportingVertexOut = reinterpret_cast<hkVector4&>(supportingVertexOut);
    hkVector4 kDelta;
    kDelta.setSub4(m_kVertexB, m_kVertexA);
    const float fDot = kDelta.dot3(kDirection);
    int iVertexId;
    if (fDot < 0.0f)
    {
        kSupportingVertexOut = m_kVertexA;
        iVertexId = 0;
    }
    else
    {
        kSupportingVertexOut = m_kVertexB;
        iVertexId = sizeof(hkVector4);
    }
    reinterpret_cast<int*>(&kSupportingVertexOut.m_vComponents)[3] = iVertexId | 0x3f000000;
}



__forceinline void hkVector4q::setMin4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4q::setMax4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4q::add4(const hkVector4q& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

__forceinline void hkVector4q::SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn)
{
    const LocalM128 b = bIn.m_vComponents;
    const LocalM128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const LocalM128 r0 = _mm_mul_ps(a.m_kColumn0.m_vComponents, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const LocalM128 r1 = _mm_mul_ps(a.m_kColumn1.m_vComponents, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(a.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, a.m_vTranslation.m_vComponents));
}

static __forceinline void hkTransformPoints(const hkTransform& t, const hkVector4q* vectorsIn, int numVectors,
                                            hkVector4q* vectorsOut)
{
    struct ColumnBits
    {
        float x, y, z, w;
    };
    union Column
    {
        ColumnBits bits;
        LocalM128 simd;
    };
    Column c0;
    c0.bits = *reinterpret_cast<const ColumnBits*>(&static_cast<const LocalM128&>(t.m_row0));
    Column c1;
    c1.bits = *reinterpret_cast<const ColumnBits*>(&static_cast<const LocalM128&>(t.m_row1));
    Column c2;
    c2.bits = *reinterpret_cast<const ColumnBits*>(&static_cast<const LocalM128&>(t.m_row2));
    Column trans;
    trans.bits = *reinterpret_cast<const ColumnBits*>(&static_cast<const LocalM128&>(t.m_row3));
    int i = numVectors - 1;
    do
    {
        const LocalM128 b = vectorsIn[i].m_vComponents;
        const LocalM128 b0 = _mm_shuffle_ps(b, b, 0x00);
        const LocalM128 r0 = _mm_mul_ps(c0.simd, b0);
        const LocalM128 b1 = _mm_shuffle_ps(b, b, 0x55);
        const LocalM128 r1 = _mm_mul_ps(c1.simd, b1);
        const LocalM128 b2 = _mm_shuffle_ps(b, b, 0xaa);
        const LocalM128 r2 = _mm_mul_ps(c2.simd, b2);
        vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, trans.simd));
    } while (--i >= 0);
}

// Computes the world-space AABB of the capsule by transforming its two vertices and expanding by the sphere radius plus tolerance.
// @fnv 0x00d225e0
void hkpCapsuleShape::CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    LocalM128 tol4;
    (reinterpret_cast<hkVector4q&>(tol4).*static_cast<void (hkVector4q::*)(float)>(&hkVector4q::SetAllComponents))(m_fSphereRadius + tolerance);

    LocalM128 obj[2];
    hkTransformPoints(localToWorld, reinterpret_cast<const hkVector4q*>(&m_kVertexA), 2, reinterpret_cast<hkVector4q*>(obj));

    reinterpret_cast<hkVector4q&>(out.m_kMinimumCorner).setMin4(reinterpret_cast<const hkVector4q&>(obj[0]), reinterpret_cast<const hkVector4q&>(obj[1]));
    reinterpret_cast<hkVector4q&>(out.m_kMinimumCorner).sub4(reinterpret_cast<const hkVector4q&>(tol4));
    reinterpret_cast<hkVector4q&>(out.m_kMaximumCorner).setMax4(reinterpret_cast<const hkVector4q&>(obj[0]), reinterpret_cast<const hkVector4q&>(obj[1]));
    reinterpret_cast<hkVector4q&>(out.m_kMaximumCorner).add4(reinterpret_cast<const hkVector4q&>(tol4));
}

