#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/physics/internal/collide/gjk/hkpgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/hkpgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the original intrinsic type; the SDK union changes alias analysis.
#ifndef _INCLUDED_MM2
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_setzero_ps();
    int _mm_movemask_ps(__m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_load_ps(const float*);
}
#define _INCLUDED_MM2
#endif

#include "../../../../../../include/hkVector4.h"
// local form of hkVector4: 0x00da8500 needs separate packet aliasing to preserve instruction scheduling.


// Define FNV_VECTOR_USE_LOCAL_SSE when __m128 and intrinsics are already declared.
#if !defined(FNV_VECTOR_USE_LOCAL_SSE)
#include <xmmintrin.h>
#endif

class Scalar;
class Comparison;
class Transform;
class hkRotation;

class GskVectorCallLocal_00da8500
{
public:
    union
    {
        __m128 q;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };

    __forceinline GskVectorCallLocal_00da8500() {}
    __forceinline GskVectorCallLocal_00da8500(const GskVectorCallLocal_00da8500& vector) : q(vector.q) {}
    __forceinline GskVectorCallLocal_00da8500(const __m128& vector) : q(vector) {}
    GskVectorCallLocal_00da8500(float x, float y, float z);
    __forceinline GskVectorCallLocal_00da8500& operator=(const GskVectorCallLocal_00da8500& vector)
    {
        q = vector.q;
        return *this;
    }
    __forceinline void operator=(const __m128& vector)
    {
        q = vector;
    }
    operator __m128() const;
    GskVectorCallLocal_00da8500 operator*(float value) const;
    GskVectorCallLocal_00da8500 operator+(const GskVectorCallLocal_00da8500& vector) const;
    GskVectorCallLocal_00da8500 operator-() const;
    float& operator()(int index);
    const float& operator()(int index) const;
    __m128& packet();
    const __m128& packet() const;

    void set(float x, float y, float z, float w = 0.0f);
    void zero();
    void setZero4();
    void subtract(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void sub(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void setSub(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void setSub4(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void add(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void setAdd(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void setAdd4(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void add4(const GskVectorCallLocal_00da8500& vector);
    void mul(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void mul4(const GskVectorCallLocal_00da8500& vector);
    void mul4(const Scalar& scalar);
    void multiply(const Scalar& scalar);
    void scale(const Scalar& scalar);
    void product(const Scalar& scalar, const GskVectorCallLocal_00da8500& vector);
    void cross(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void setCross(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b);
    void negate(const GskVectorCallLocal_00da8500& vector);
    void setNeg4(const GskVectorCallLocal_00da8500& vector);
    void addMul(const GskVectorCallLocal_00da8500& a, __m128 scale, const GskVectorCallLocal_00da8500& b);
    void setAddMul4(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b, const Scalar& scalar);
    void interpolate(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b, const Scalar& t);
    void setInterpolate4(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b, const Scalar& t);
    void Interpolate(const GskVectorCallLocal_00da8500& oldValue, const GskVectorCallLocal_00da8500& newValue, float factor);
    void SetTransformedPoint(const Transform& transform, const GskVectorCallLocal_00da8500& point);

    Scalar getSimdAt(int index) const;
    Scalar dot(const GskVectorCallLocal_00da8500& vector) const;
    Scalar dot3(const GskVectorCallLocal_00da8500& vector) const;
    float DotProduct(const GskVectorCallLocal_00da8500& vector);
    Scalar sum() const;
    Scalar norm() const;
    Scalar lengthSquared3() const;
    Scalar length3() const;
    float length() const;
    Scalar inverseLength() const;
    void normalize();
    void normalize3();
    Comparison compareLessThanZero4() const;
    int getMajorAxis() const;
    int maxAxisSecond() const;
    int maxAxis() const;
    float GetAngle();

    void SetComponents(float x, float y, float z);
    GskVectorCallLocal_00da8500 SubtractIntoVector(const GskVectorCallLocal_00da8500& vector);
    GskVectorCallLocal_00da8500 FUN_00439e90(const GskVectorCallLocal_00da8500& vector);
    void ScaleComponents(float value);
    void Unitize_004a0c10();
    void normalize_005611c0();
    void setMul(const GskVectorCallLocal_00da8500* a, const GskVectorCallLocal_00da8500* b);
    void setMulInverse(const GskVectorCallLocal_00da8500* a, const GskVectorCallLocal_00da8500* b);
    void hkQuaternion_getAxis(GskVectorCallLocal_00da8500* vector);
    void setTransformedPos_00c7f640(const Transform& transform, const GskVectorCallLocal_00da8500& point);
    void hkQuaternion_setAxisAngle(const GskVectorCallLocal_00da8500* vector, float value);
    void FUN_00cb26e0(const hkRotation* rotation);

    template <int I> void splat(const GskVectorCallLocal_00da8500& vector);

    static const GskVectorCallLocal_00da8500& getZero();
};


__forceinline hkSimdReal::hkSimdReal()
{}

__forceinline hkSimdReal::hkSimdReal(const __m128& input) : m_vValue(input)
{}

__forceinline hkSimdReal::operator float() const
{
    float scalar;
    _mm_store_ss(&scalar, m_vValue);
    return scalar;
}

__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline const __m128& hkSimdReal::getQuad() const
{
    return m_vValue;
}


__forceinline hkVector4::hkVector4(const hkVector4& vector) : m_vComponents(vector.m_vComponents)
{}


__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& vector) const
{
    __m128 p = _mm_mul_ps(m_vComponents, vector.m_vComponents);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
}

__forceinline hkSimdReal hkVector4::horizontalAdd3() const
{
    __m128 s = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
    return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), s);
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return dot3(*this);
}

// The shared class has no inverse-length member; keep the calculation local.
static __forceinline hkSimdReal vectorLengthInverse3(const hkVector4& vector)
{
    __m128 len2 = vector.dot3(vector).getQuad();
    __m128 e = _mm_rsqrt_ss(len2);
    __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                          _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    return _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
}

extern const __m128 DAT_010c44d0;
__forceinline void hkVector4::setFlipSign(const hkVector4& vector, const hkSimdReal& sign)
{
    m_vComponents = _mm_xor_ps(_mm_and_ps(sign.broadcast(), DAT_010c44d0), vector.m_vComponents);
}

__forceinline void hkVector4::mul4(const hkSimdReal& scalar)
{
    m_vComponents = _mm_mul_ps(m_vComponents, scalar.broadcast());
}

__forceinline void hkVector4::normalize3()
{
    __m128 scale = vectorLengthInverse3(*this).broadcast();
    m_vComponents = _mm_mul_ps(scale, m_vComponents);
}

__forceinline void hkVector4::SetAllComponents(const hkSimdReal& scalar)
{
    m_vComponents = scalar.broadcast();
}

__forceinline void hkVector4::setW(const hkVector4& vector)
{
    m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, vector.m_vComponents), 0xc4);
}

struct Entry
{
    char pad[12];
    unsigned short val;
    char pad2[2];
};

struct Dest
{
    unsigned short words[4];
    unsigned char count1;
    unsigned char count2;
};

struct ThisClass
{
    int count1;
    int count2;
    char pad[0x18];
    Entry entries1[3];
    char pad2[0x90];
    Entry entries2[3];

    void hkpGsk_exitAndExportCacheImpl(Dest* out);
};

// @fnv 0x00da9790
// src: HAVOK_LIB 0x00da9790
void ThisClass::hkpGsk_exitAndExportCacheImpl(Dest* pDest)
{
    pDest->count1 = (unsigned char)this->count1;
    pDest->count2 = (unsigned char)this->count2;

    int iCount1 = this->count1;
    unsigned short v0 = this->entries1[0].val;
    if (iCount1 >= 2)
    {
        unsigned short v1 = this->entries1[1].val;
        int iSwaps1 = 0;
        if (v1 > v0)
        {
            unsigned short tmp = v1;
            v1 = v0;
            v0 = tmp;
            iSwaps1 = 1;
        }
        if (iCount1 > 2)
        {
            unsigned short v2 = this->entries1[2].val;
            if (v2 > v0)
            {
                unsigned short tmp = v2;
                v2 = v0;
                v0 = tmp;
                iSwaps1++;
            }
            if (iSwaps1 == 1)
            {
                unsigned short tmp = v2;
                v2 = v1;
                v1 = tmp;
            }
            pDest->words[2] = v2;
        }
        pDest->words[1] = v1;
    }
    pDest->words[0] = v0;

    int iCount2 = this->count2;
    unsigned short u0 = this->entries2[0].val;
    if (iCount2 >= 2)
    {
        unsigned short u1 = this->entries2[1].val;
        int iSwaps2 = 0;
        if (u1 > u0)
        {
            unsigned short tmp = u1;
            u1 = u0;
            u0 = tmp;
            iSwaps2 = 1;
        }
        if (iCount2 > 2)
        {
            unsigned short u2 = this->entries2[2].val;
            if (u2 > u0)
            {
                unsigned short tmp = u2;
                u2 = u0;
                u0 = tmp;
                iSwaps2++;
            }
            if (iSwaps2 == 1)
            {
                unsigned short tmp = u2;
                u2 = u1;
                u1 = tmp;
            }
            pDest->words[this->count1 + 2] = u2;
        }
        pDest->words[this->count1 + 1] = u1;
    }
    pDest->words[this->count1] = u0;
}

struct PlainVector
{
    float x, y, z, w;
};
extern const __m128 signMask;

struct Simplex
{
    int countA, countB, unk08, unk0c, unk10, status, unk18, unk1c;
    GskVectorCallLocal_00da8500 a[4];
    GskVectorCallLocal_00da8500 unk60, unk70, unk80, unk90;
    GskVectorCallLocal_00da8500 verticesB[8];
    GskVectorCallLocal_00da8500 result, axis, unk140, unk150, weights;
    int TestTriangleOrientationAndSwapVertices(const GskVectorCallLocal_00da8500* point, GskVectorCallLocal_00da8500* vertices, int orient);
};

static __forceinline __m128 cross(__m128 a, __m128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __forceinline void swapFloat(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}
static __forceinline GskVectorCallLocal_00da8500 copyVector(const PlainVector& p)
{
    GskVectorCallLocal_00da8500 v;
    reinterpret_cast<PlainVector&>(v.q) = p;
    return v;
}

static __forceinline __m128 triangleSideTests(const GskVectorCallLocal_00da8500* point, GskVectorCallLocal_00da8500* vertices, GskVectorCallLocal_00da8500& normal, GskVectorCallLocal_00da8500& weights)
{
    __m128 edgeA = _mm_sub_ps(vertices[2].q, vertices[1].q);
    __m128 edgeB = _mm_sub_ps(vertices[0].q, vertices[2].q);
    __m128 edgeC = _mm_sub_ps(vertices[1].q, vertices[0].q);
    normal.q = cross(edgeA, edgeB);
    __m128 pa = _mm_sub_ps(point->q, vertices[1].q);
    __m128 pb = _mm_sub_ps(point->q, vertices[2].q);
    __m128 pc = _mm_sub_ps(point->q, vertices[0].q);
    __m128 da = _mm_mul_ps(cross(pa, edgeA), normal.q);
    __m128 db = _mm_mul_ps(cross(pb, edgeB), normal.q);
    __m128 dc = _mm_mul_ps(cross(pc, edgeC), normal.q);
    __m128 tmp0 = _mm_unpacklo_ps(da, db);
    __m128 tmp1 = _mm_unpackhi_ps(da, db);
    da = _mm_movelh_ps(tmp0, dc);
    db = _mm_shuffle_ps(_mm_movehl_ps(da, tmp0), dc, 0xd4);
    dc = _mm_shuffle_ps(tmp1, dc, 0xe4);
    weights.q = _mm_add_ps(_mm_add_ps(da, db), dc);
    return weights.q;
}

// Computes barycentric side tests for point against a triangle, optionally flips orientation and swaps vertices if the point is behind the face.
// @fnv 0x00da8500
// src: GUESS 0x00da8500 (confidence: medium)
int Simplex::TestTriangleOrientationAndSwapVertices(const GskVectorCallLocal_00da8500* point, GskVectorCallLocal_00da8500* vertices, int orient)
{
    GskVectorCallLocal_00da8500 normalVector;
    __m128& normal = normalVector.q;
    __m128 tested = triangleSideTests(point, vertices, normalVector, weights);
    int bits = _mm_movemask_ps(_mm_cmplt_ps(tested, _mm_setzero_ps())) & 7;
    if (orient)
    {
        result.q = normal;
        if (bits == 7)
        {
            __m128 d = _mm_mul_ps(_mm_sub_ps(a[0].q, verticesB[0].q), normal);
            __m128 dy = _mm_shuffle_ps(d, d, 0x55);
            __m128 dz = _mm_shuffle_ps(d, d, 0xaa);
            __m128 dot = _mm_add_ss(dz, _mm_add_ss(dy, d));
            if (_mm_movemask_ps(dot) & 1)
            {
                normal = _mm_xor_ps(normal, signMask);
                result.q = normal;
                GskVectorCallLocal_00da8500 tmp = copyVector(reinterpret_cast<const PlainVector&>(vertices[0].q));
                vertices[0] = vertices[1];
                vertices[1] = tmp;
                tmp = copyVector(reinterpret_cast<const PlainVector&>(vertices[4].q));
                vertices[4] = vertices[5];
                vertices[5] = tmp;
                swapFloat(weights.q.m128_f32[0], weights.q.m128_f32[1]);
                status = 1;
            }
        }
    }
    return bits;
}

namespace fnv_00da8700 {

struct Tri
{
    hkVector4 m_v0;
    hkVector4 m_v1;
    hkVector4 m_v2;
};

// Computes the signed distance from point to the plane of the triangle defined by tri, using ref to orient the normal.
// @fnv 0x00da8700
// src: GUESS 0x00da8700 (confidence: medium)
static __declspec(noinline) hkSimdReal
    hkVector4_ComputeSignedTrianglePlaneDistance(const Tri* tri, hkVector4* normal, const hkVector4* ref, const hkVector4* point)
{
    hkVector4 e0;
    e0.setSub4(tri->m_v2, tri->m_v1);
    hkVector4 e1;
    e1.setSub4(tri->m_v0, tri->m_v2);
    normal->setCross(e0, e1);
    hkSimdReal inv = vectorLengthInverse3(*normal);
    normal->setFlipSign(*normal, normal->dot3(*ref));
    normal->mul4(inv);
    hkVector4 d;
    d.m_vComponents = _mm_sub_ps(_mm_load_ps((const float*)point), tri->m_v0.m_vComponents);
    return d.dot3(*normal);
}

void Caller00da(const Tri* tri, hkVector4* normal, const hkVector4* ref, hkSimdReal* dist,
                const hkVector4* point)
{
    *dist = hkVector4_ComputeSignedTrianglePlaneDistance(tri, normal, ref, point);
}
}  // namespace fnv_00da8700

struct SpawnedSrc
{
    __m128 m_v;
};

struct SpawnedDst
{
    __m128 m_v00;
    __m128 m_v10;
    float m_f20;
};

struct __declspec(align(16)) FUN_00da9880_cls
{
    int m_i00;
    int m_i04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_v20;
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
    __m128 m_va0;
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
    __m128 m_v130;

    void hkpGsk_convertFeatureToClosestDistance(const SpawnedSrc* apSrc, SpawnedDst* apDst);
};

// Copies apSrc's vector and float into apDst, then sets m_v10 to m_v20 if m_i00 is 1, to a w-scaled blend with m_va0 if m_i04 is 1, else to m_v130.
// @fnv 0x00da9880
// src: XBOX_PDB 0x00da9880
void FUN_00da9880_cls::hkpGsk_convertFeatureToClosestDistance(const SpawnedSrc* apSrc, SpawnedDst* apDst)
{
    apDst->m_f20 = *(const volatile float*)((const char*)apSrc + 0xc);
    apDst->m_v00 = apSrc->m_v;
    if (m_i00 == 1)
    {
        apDst->m_v10 = m_v20;
    }
    else if (m_i04 == 1)
    {
        __m128 vW = _mm_shuffle_ps(apSrc->m_v, apSrc->m_v, 0xff);
        __m128 vB = _mm_shuffle_ps(vW, vW, 0);
        apDst->m_v10 = _mm_add_ps(_mm_mul_ps(vB, apDst->m_v00), m_va0);
    }
    else
    {
        apDst->m_v10 = m_v130;
    }
}

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" int _mm_movemask_ps(__m128);

extern const signed char DAT_010cb440[];

// For each i, when dist[a] and dist[b] are both non-negative, sets one to -1 from a dot-product test with p and v[3]; returns first index with dist > 0, else -1.
// @fnv 0x00da8390
// src: GUESS 0x00da8390 (confidence: low)
static __declspec(noinline) int __cdecl hkVector4_ProcessEntries_00da8390(const hkVector4* apVertices, const hkVector4* apPoint,
                                                     float* apDistances)
{
    for (int i = 0; i < 3; ++i)
    {
        int a = DAT_010cb440[i + 2];
        int b = DAT_010cb440[i];
        if (apDistances[a] >= 0.0f && apDistances[b] >= 0.0f)
        {
            hkVector4 ea;
            ea.setSub4(apVertices[a], apVertices[i]);
            hkVector4 eb;
            eb.setSub4(apVertices[b], apVertices[i]);
            hkVector4 d;
            d.setSub4(*apPoint, apVertices[i]);
            hkVector4 n;
            n.setSub4(apVertices[3], apVertices[i]);
            hkVector4 m_dea;
            m_dea.setMul4(d, ea);
            hkVector4 m_deb;
            m_deb.setMul4(d, eb);
            hkVector4 m_nea;
            m_nea.setMul4(n, ea);
            hkVector4 m_neb;
            m_neb.setMul4(n, eb);
            hkSimdReal nb = m_neb.horizontalAdd3();
            hkSimdReal da = m_dea.horizontalAdd3();
            hkSimdReal db = m_deb.horizontalAdd3();
            hkSimdReal na = m_nea.horizontalAdd3();
            hkSimdReal s;
            s.m_vValue = _mm_sub_ss(_mm_mul_ss(da.m_vValue, nb.m_vValue), _mm_mul_ss(db.m_vValue, na.m_vValue));
            if (_mm_movemask_ps(s.m_vValue) & 1)
                apDistances[b] = -1.0f;
            else
                apDistances[a] = -1.0f;
        }
    }
    if (apDistances[0] > 0.0f)
        return 0;
    if (apDistances[1] > 0.0f)
        return 1;
    if (apDistances[2] > 0.0f)
        return 2;
    return -1;
}

int S00da8390_Call(const hkVector4* p, float* dist, const hkVector4* v)
{
    return hkVector4_ProcessEntries_00da8390(v, p, dist);
}

extern "C"
{
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
}

extern const __m128 DAT_010c44d0;

struct S00da8820_Result
{
    hkVector4 m_kFirstVector;
    hkVector4 m_kClosestPointOnSecond;
    float m_fValue;
};

int __cdecl hkLineSegmentUtil_closestLineSegLineSeg(const hkVector4& A, const hkVector4& dA, const hkVector4& B,
                         const hkVector4& dB, S00da8820_Result& result);

// Finds the closest points of two edges, builds a plane from their cross product (using oldNormal if near-parallel), and stores the point and plane.
// @fnv 0x00da8820
// src: GUESS 0x00da8820 (confidence: medium)
static __declspec(noinline) void __cdecl hkVector4_ComputeEdgeContactPlane(hkVector4* edgeA, hkVector4* edgeB,
                                                      const hkVector4& oldNormal, hkVector4& pointOut,
                                                      hkVector4& planeOut)
{
    hkVector4 dA;
    dA.setSub4(edgeA[1], edgeA[0]);
    hkVector4 dB;
    dB.setSub4(edgeB[1], edgeB[0]);

    S00da8820_Result result;
    hkLineSegmentUtil_closestLineSegLineSeg(edgeA[0], dA, edgeB[0], dB, result);

    planeOut.setCross(dA, dB);

    hkVector4 vDeltaASquared;
    vDeltaASquared.setMul4(dA, dA);
    hkVector4 b2;
    b2.setMul4(dB, dB);
    hkVector4 sum;
    sum.setAdd4(vDeltaASquared, b2);
    float lenSq = sum.horizontalAdd3();
    float crossLenSq = planeOut.lengthSquared3();
    if (crossLenSq * 0.001f > lenSq * lenSq)
    {
        planeOut.setFlipSign(planeOut, planeOut.dot3(oldNormal));
        planeOut.normalize3();
    }
    else
    {
        planeOut = oldNormal;
    }

    hkVector4 d;
    d.setSub4(edgeA[0], edgeB[0]);
    hkSimdReal dist = d.dot3(planeOut);
    pointOut = result.m_kFirstVector;
    hkVector4 w;
    w.SetAllComponents(dist);
    planeOut.setW(w);
}

void __cdecl S00da8820_RecalcContact(hkVector4* vA, hkVector4* vB, const hkVector4& n, hkVector4& p,
                                     hkVector4& plane)
{
    hkVector4_ComputeEdgeContactPlane(vA, vB, n, p, plane);
}

#include <math.h>
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ps1(const float*);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_setzero_ps();
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    void _mm_store_ss(float*, __m128);
}

struct __declspec(align(16)) Collision_vector
{
    float x, y, z, w;
    __forceinline __m128& simd()
    {
        return (__m128&)*this;
    }
    __forceinline const __m128& simd() const
    {
        return (const __m128&)*this;
    }
    __forceinline void normalize3(const __m128&, const __m128&, const __m128&);
    __forceinline Collision_vector& operator=(const Collision_vector& v)
    {
        simd() = v.simd();
        return *this;
    }
};
struct Collision_vcls
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void support(Collision_vector* direction, Collision_vector* out);
    virtual void vertices(void* indices, int count, Collision_vector* out);
    int unk04;
    int unk08;
    int unk0c;
    float m_10;
    __forceinline float radius() const
    {
        return m_10;
    }
};
struct Collision_mat
{
    __m128 m_00, m_10, m_20, m_30;
};
struct Collision_hit
{
    Collision_vector normal;
    float fraction;
};
extern const float DAT_01017718, DAT_01016248, DAT_01011d78;
extern const double DAT_01016978;
extern const float DAT_010d51b0;
extern const double DAT_010d51a8;
extern const float DAT_01012054;
extern const double DAT_0109cc78;
extern const __m128 DAT_010c44d0;
extern const signed char DAT_010cb438[], DAT_010cb440[], DAT_010cb442[];
struct Transform_result : Collision_vector
{
    void hkVector4_setRotatedDir(Collision_mat*, Collision_vector*);
};
extern int hkLineSegmentUtil_closestLineSegLineSeg(Collision_vector*, Collision_vector*, Collision_vector*, Collision_vector*, Collision_vector*);
struct SmallBool
{
    char value;
    __forceinline SmallBool(bool v) : value(v)
    {}
    __forceinline SmallBool(const SmallBool& v) : value(v.value)
    {}
};
struct Collision_workspace
{
    int countA, countB, low, high, unk10, changed, unk18, unk1c;
    __forceinline void append(Collision_vector& value, int index)
    {
        a[index] = value;
        int next = countA;
        next++;
        countA = next;
    }
    Collision_vector a[4];
    Collision_vector sourceA[4];
    Collision_vector b[4];
    Collision_vector sourceB[4];
    Collision_vector axis;
    Collision_vector witnesses[4];
    int oldCountB, unk174, unk178, unk17c;
    int TestTriangleOrientationAndSwapVertices(Collision_vector*, Collision_vector*, int);
    int ClipPolygonAgainstSegment(Collision_vector*, Collision_vector*, int*, int*, SmallBool, int);
    __forceinline int updateSimplex(Collision_vector& edgeB);
    SmallBool ProcessEntries_00da9b30(Collision_vcls*, Collision_vcls*, Collision_mat*, Collision_vector*, Collision_hit*);
};
static __forceinline __m128 broadcast(const float* value)
{
    __m128 scalar = _mm_load_ss(value);
    return _mm_shuffle_ps(scalar, scalar, 0);
}
static __forceinline __m128 sum3(__m128 v)
{
    __m128 y = _mm_shuffle_ps(v, v, 0x55);
    __m128 s = _mm_add_ss(y, v);
    __m128 z = _mm_shuffle_ps(v, v, 0xaa);
    return _mm_add_ss(z, s);
}
static __forceinline float real(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
static __forceinline __m128 dot(__m128 a, __m128 b)
{
    return sum3(_mm_mul_ps(a, b));
}
static __forceinline void flipSign(Collision_vector& v, __m128 d)
{
    v.simd() = _mm_xor_ps(_mm_and_ps(_mm_shuffle_ps(d, d, 0), DAT_010c44d0), v.simd());
}
static __forceinline void flipSignC(Collision_vector& v, const Collision_vector& d)
{
    v.simd() = _mm_xor_ps(_mm_and_ps(_mm_shuffle_ps(d.simd(), d.simd(), 0), DAT_010c44d0), v.simd());
}
static __forceinline int sign(__m128 v)
{
    return _mm_movemask_ps(v) & 1;
}
extern const __m128 DAT_01017d10;
extern const float DAT_0104da48, DAT_010c6090;
extern const double DAT_010290f8;
extern int __cdecl hkVector4_ProcessEntries_00da8390(const Collision_vector*, const Collision_vector*);
// src: GUESS 0x00da8fb0 (confidence: low)
static int Hkpgsk_ProcessEntries_00da8fb0(const Collision_vector* vertices, const Collision_vector* point, float orientation)
{
    __m128 v0 = vertices[0].simd(), v1 = vertices[1].simd(), v2 = vertices[2].simd(), v3 = vertices[3].simd();
    Collision_vector normals[3];
    normals[0].simd() = cross(_mm_sub_ps(v2, v1), _mm_sub_ps(v3, v1));
    normals[1].simd() = cross(_mm_sub_ps(v0, v2), _mm_sub_ps(v3, v2));
    normals[2].simd() = cross(_mm_sub_ps(v1, v0), _mm_sub_ps(v3, v0));
    __m128 rel = _mm_mul_ps(broadcast(&orientation), _mm_sub_ps(point->simd(), vertices[3].simd()));
    __m128 lo = _mm_unpacklo_ps(normals[0].simd(), normals[1].simd());
    __m128 hi = _mm_unpackhi_ps(normals[0].simd(), normals[1].simd());
    __m128 cx = _mm_movelh_ps(lo, normals[2].simd());
    __m128 cy = _mm_shuffle_ps(_mm_movehl_ps(cx, lo), normals[2].simd(), 0xd4);
    __m128 cz = _mm_shuffle_ps(hi, normals[2].simd(), 0xe4);
    Collision_vector dots;
    dots.simd() = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(rel, rel, 0x55), cy), _mm_mul_ps(_mm_shuffle_ps(rel, rel, 0), cx)),
        _mm_mul_ps(_mm_shuffle_ps(rel, rel, 0xaa), cz));
    Collision_vector weighted;
    weighted.simd() = _mm_mul_ps(_mm_and_ps(dots.simd(), DAT_01017d10), dots.simd());
    float dist[3];
    for (int i = 0; i < 3; i++)
    {
        float lengthSquared = real(dot(normals[i].simd(), normals[i].simd()));
        if (lengthSquared != 0.0f)
            dist[i] = (&weighted.x)[i] / lengthSquared;
        else
            dist[i] = DAT_0104da48;
    }
    int index = 1;
    if (dist[1] < dist[0])
    {
        float t = dist[0];
        dist[0] = dist[1];
        dist[1] = t;
        index = 0;
    }
    if (dist[2] < dist[1])
    {
        float t = dist[1];
        dist[1] = dist[2];
        dist[2] = t;
        if (dist[1] < dist[0])
        {
            float u = dist[0];
            dist[0] = dist[1];
            dist[1] = u;
        }
    }
    else
        index = 2;
    if (dist[2] < DAT_010c6090)
        return -1;
    if (dist[1] * DAT_010290f8 < dist[2])
        return index;
    Collision_vector projected = dots;
    return hkVector4_ProcessEntries_00da8390(point, &projected);
}
__forceinline void Collision_vector::normalize3(const __m128& zero, const __m128& three, const __m128& half)
{
    __m128 v = simd();
    __m128 len = dot(v, v);
    __m128 eq = _mm_cmpeq_ss(len, zero);
    __m128 inv = _mm_rsqrt_ss(len);
    __m128 refined = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, inv), inv)));
    __m128 scale = _mm_andnot_ps(eq, refined);
    simd() = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), v);
}

__forceinline int Collision_workspace::updateSimplex(Collision_vector& edgeB)
{
redispatch:
    int sizeB = countB;
    switch ((countA * 8) | sizeB)
    {
    case 19: {
        int old = oldCountB;
        int result = ClipPolygonAgainstSegment(a, b, &countA, &countB, SmallBool(old == 2), 1);
        switch (result)
        {
        case 1:
            goto finish;
        case 2:
            goto edgeEdge;
        default:
            goto nextAxis;
        }
    }
    case 26: {
        int old = oldCountB;
        int result = ClipPolygonAgainstSegment(b, a, &countB, &countA, SmallBool(old == 2), -1);
        switch (result)
        {
        case 1:
            goto finish;
        case 2:
            goto edgeEdge;
        default:
            goto nextAxis;
        }
    }
    case 18:
    edgeEdge: {
        Collision_vector edgeA;
        edgeA.simd() = _mm_sub_ps(a[1].simd(), a[0].simd());
        Collision_vector& eb = edgeB;
        eb.simd() = b[1].simd();
        eb.simd() = _mm_sub_ps(eb.simd(), b[0].simd());
        int result = hkLineSegmentUtil_closestLineSegLineSeg(a, &edgeA, b, &edgeB, witnesses);
        if (!result)
        {
            axis.simd() = cross(edgeA.simd(), edgeB.simd());
            __m128 d = dot(_mm_sub_ps(a[0].simd(), b[0].simd()), axis.simd());
            flipSign(axis, d);
            goto nextAxis;
        }
        if (result & 1)
        {
            a[0].simd() = a[1].simd();
            countA = 1;
        }
        else if (result & 2)
            countA = 1;
        if (result & 4)
        {
            b[0].simd() = b[1].simd();
            sourceB[0].simd() = sourceB[1].simd();
            countB = 1;
        }
        else if (result & 8)
            countB = 1;
        goto redispatch;
    }
    case 12: {
        int index = Hkpgsk_ProcessEntries_00da8fb0(b, a, 1.0f);
        if (index < 0)
            goto finish;
        countB--;
        b[index].simd() = b[3].simd();
        sourceB[index].simd() = sourceB[3].simd();
    }
    case 11: {
        int result = TestTriangleOrientationAndSwapVertices(a, b, 1);
        if (result == 7)
            goto nextAxis;
        int index = DAT_010cb438[result];
        if (index < 0)
        {
            index += 8;
            if (index > 3)
                index = 1;
            countB--;
            b[index].simd() = b[2].simd();
            sourceB[index].simd() = sourceB[2].simd();
            goto edgeB;
        }
        int s = DAT_010cb440[index];
        int c = DAT_010cb442[index];
        __m128 base = b[index].simd();
        __m128 toward = _mm_sub_ps(a[0].simd(), base);
        __m128 ds = _mm_sub_ps(b[s].simd(), base);
        __m128 dc = _mm_sub_ps(b[c].simd(), base);
        int sg = sign(dot(ds, toward));
        countB = 2;
        if (sg)
        {
            b[s].simd() = b[2].simd();
            sourceB[s].simd() = sourceB[2].simd();
            if (sign(dot(dc, toward)))
            {
                if (c == countB)
                    c = s;
                countB--;
                b[c].simd() = b[countB].simd();
                sourceB[c].simd() = sourceB[countB].simd();
            }
        }
        else
        {
            b[c].simd() = b[2].simd();
            sourceB[c].simd() = sourceB[2].simd();
        }
        goto redispatch;
    }
    case 10:
    edgeB: {
        Collision_vector* points = b;
        __m128 end = points[1].simd();
        __m128 start = points[0].simd();
        __m128 target = a[0].simd();
        __m128 edge = _mm_sub_ps(end, start);
        __m128 fromEnd = _mm_sub_ps(end, target);
        __m128 fromStart = _mm_sub_ps(start, target);
        __m128 endDot = dot(fromEnd, edge);
        __m128 startDot = dot(fromStart, edge);
        int sg1 = sign(endDot);
        int sg2 = sign(startDot);
        if (sg1 != sg2)
        {
            __m128 len = dot(edge, edge);
            __m128 inv = _mm_rsqrt_ss(len);
            __m128 unit = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), edge);
            axis.simd() = cross(unit, cross(fromEnd, fromStart));
            goto nextAxis;
        }
        if (sg1)
        {
            __m128 source = points[5].simd();
            points[0].simd() = end;
            points[4].simd() = source;
        }
        countB--;
        axis.simd() = _mm_sub_ps(a[0].simd(), b[0].simd());
        return 0;
    }
    case 33: {
        int index = Hkpgsk_ProcessEntries_00da8fb0(a, b, DAT_01012054);
        if (index < 0)
            goto finish;
        countA--;
        a[index].simd() = a[3].simd();
    }
    case 25: {
        int result = TestTriangleOrientationAndSwapVertices(b, a, -1);
        if (result == 7)
            goto nextAxis;
        int index = DAT_010cb438[result];
        if (index < 0)
        {
            index += 8;
            if (index > 3)
                index = 1;
            countA--;
            a[index].simd() = a[2].simd();
            goto edgeA;
        }
        int s = DAT_010cb440[index];
        int c = DAT_010cb442[index];
        __m128 base = a[index].simd();
        __m128 toward = _mm_sub_ps(b[0].simd(), base);
        __m128 ds = _mm_sub_ps(a[s].simd(), base);
        __m128 dc = _mm_sub_ps(a[c].simd(), base);
        int sg = sign(dot(ds, toward));
        countA = 2;
        if (sg)
        {
            a[s].simd() = a[2].simd();
            if (sign(dot(dc, toward)))
            {
                if (c == countA)
                    c = s;
                countA--;
                a[c].simd() = a[countA].simd();
            }
        }
        else
            a[c].simd() = a[2].simd();
        goto redispatch;
    }
    case 17:
        goto edgeA;
    case 9:
        goto pointPoint;
    default:
        goto finish;
    }

edgeA: {
    __m128 end = a[1].simd();
    __m128 start = a[0].simd();
    __m128 target = b[0].simd();
    __m128 edge = _mm_sub_ps(end, start);
    __m128 fromEnd = _mm_sub_ps(end, target);
    __m128 fromStart = _mm_sub_ps(start, target);
    __m128 endDot = dot(fromEnd, edge);
    __m128 startDot = dot(fromStart, edge);
    int sg1 = sign(endDot);
    int sg2 = sign(startDot);
    if (sg1 != sg2)
    {
        __m128 len = dot(edge, edge);
        __m128 inv = _mm_rsqrt_ss(len);
        __m128 unit = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), edge);
        axis.simd() = cross(cross(fromEnd, fromStart), unit);
        goto nextAxis;
    }
    if (sg1)
    {
        __m128 source = sourceA[1].simd();
        a[0].simd() = end;
        sourceA[0].simd() = source;
    }
    countA--;
}
pointPoint:
    axis.simd() = _mm_sub_ps(a[0].simd(), b[0].simd());
nextAxis:
    return 0;
finish:
    return 1;
}

// GJK-style cast of path against shapeA (or shapeA minus transformed shapeB); returns true and updates hit's fraction and normal when it hits sooner.
// @fnv 0x00da9b30
// src: GUESS 0x00da9b30 (confidence: low)
SmallBool Collision_workspace::ProcessEntries_00da9b30(Collision_vcls* shapeA, Collision_vcls* shapeB, Collision_mat* transform,
                                            Collision_vector* path, Collision_hit* hit)
{
    Collision_vector displacement;
    displacement.simd() = _mm_sub_ps(path[1].simd(), path[0].simd());
    float initialSupport = shapeB ? shapeA->radius() + shapeB->radius() : shapeA->radius();
    float radiusSquared = float((initialSupport + DAT_01016978) * (DAT_01016978 + initialSupport));
    float r = 0.0f;
    Collision_vector w = path[0];
    Collision_vector denominator;
    Collision_vector x;
    x.simd() = _mm_setzero_ps();
    float pForm;
    {
        Collision_vector initialPoint;
        int seed = 0;
        shapeA->vertices(&seed, 1, &initialPoint);
        pForm = DAT_010d51b0;
        axis.simd() = _mm_sub_ps(w.simd(), initialPoint.simd());
    }
    Collision_vector direction = axis;
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 magnitude = _mm_set_ss(3.0f);
    __m128 q = _mm_set_ss(DAT_01011d78);
    direction.normalize3(q, magnitude, half);
    countA = 0;
    countB = 1;
    Collision_vector support;
    support = x;
    Collision_vector supportB;
    supportB = x;
    double threshold = radiusSquared;
    int iterations = 0;
    if (!(threshold < DAT_010d51a8))
        goto finish;

    for (;;)
    {
        shapeA->support(&axis, &support);
        if (shapeB)
        {
            __m128 axisValue = axis.simd();
            __m128 signMask = DAT_010c44d0;
            __m128 v = _mm_xor_ps(signMask, axisValue);
            __m128 r0 = transform->m_00;
            __m128 r1 = transform->m_10;
            __m128 b = transform->m_20;
            __m128 best = _mm_unpacklo_ps(r0, r1);
            __m128 h = _mm_unpackhi_ps(r0, r1);
            __m128 n = _mm_shuffle_ps(h, b, 0xe4);
            __m128 scaledAxis = _mm_movelh_ps(best, b);
            __m128 y = _mm_movehl_ps(scaledAxis, best);
            y = _mm_shuffle_ps(y, b, 0xd4);
            __m128 t = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), scaledAxis);
            Collision_vector localDirection;
            __m128 zero = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), y);
            __m128 u = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), n);
            localDirection.simd() = _mm_add_ps(_mm_add_ps(zero, t), u);
            shapeB->support(&localDirection, &supportB);
            Transform_result transformed;
            transformed.hkVector4_setRotatedDir(transform, &supportB);
            support.simd() = _mm_sub_ps(support.simd(), transformed.simd());
        }
        int z = countA;
        for (int i = 0; i < countA; i++)
        {
            if (a[i].x == support.x && a[i].y == support.y && a[i].z == support.z)
                goto existingSupport;
        }
        append(support, z);
    existingSupport:
        __m128 normal = _mm_load_ps1(&initialSupport);
        normal = _mm_mul_ps(normal, direction.simd());
        normal = _mm_add_ps(normal, support.simd());
        float distance = real(dot(axis.simd(), _mm_sub_ps(w.simd(), normal)));
        if (distance > 0.0f)
        {
            float c = real(dot(axis.simd(), displacement.simd()));
            if (c >= 0.0f)
            {
                return SmallBool(false);
            }
            r -= distance / c;
            if (r >= 1.0f)
            {
                return SmallBool(false);
            }
            __m128 scaled = _mm_load_ps1(&r);
            scaled = _mm_mul_ps(scaled, displacement.simd());
            w.simd() = _mm_add_ps(scaled, path[0].simd());
            x.simd() = direction.simd();
        }
        Collision_vector previousAxis = axis;
        sourceB[0] = w;
        b[0].simd() = sourceB[0].simd();
        unk174 = 0;

        if (updateSimplex(denominator))
            goto finish;
        oldCountB = countB;
        __m128 point = _mm_mul_ps(broadcast(&DAT_01012054), axis.simd());
        direction.simd() = point;
        axis.simd() = point;
        direction.normalize3(q, magnitude, half);
        for (int k = 0; countA > k; k++)
        {
            float separation = real(dot(_mm_sub_ps(b[0].simd(), a[0].simd()), direction.simd()));
            float three = float(fabs(separation));
            float rounded = three;
            if (rounded < pForm)
                pForm = rounded;
        }
        __m128 change = _mm_sub_ps(axis.simd(), previousAxis.simd());
        float changeSquared;
        changeSquared = real(dot(change, change));
        if (changeSquared < DAT_0109cc78)
        {
            ++iterations;
            if (iterations >= 3)
                goto finish;
        }
        if (!(pForm * pForm > threshold))
            goto finish;
    }
finish:
    if (r < hit->fraction)
    {
        hit->fraction = r;
        float length = real(dot(x.simd(), x.simd()));
        hit->normal.simd() = x.simd();
        return SmallBool(true);
    }
    else
        return SmallBool(false);
}

extern const __m128 DAT_010c7160;

class ContactScalar
{
  public:
    ContactScalar()
    {}
    ContactScalar(const __m128& input) : value(input)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }

  private:
    __m128 value;
};
__forceinline ContactScalar operator-(const ContactScalar& scalar)
{
    return _mm_sub_ss(DAT_010c7160, scalar.getQuad());
}

class ContactVector
{
  public:
    __forceinline void operator=(const ContactVector& source)
    {
        value = source.value;
    }
    __forceinline __m128& getQuad()
    {
        return value;
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
    __forceinline float& operator()(int index)
    {
        return value.m128_f32[index];
    }
    __forceinline void setSub4(const ContactVector& lhs, const ContactVector& rhs)
    {
        value = _mm_sub_ps(lhs.value, rhs.value);
    }
    __forceinline void setAdd4(const ContactVector& lhs, const ContactVector& rhs)
    {
        value = _mm_add_ps(lhs.value, rhs.value);
    }
    __forceinline void setMul4(const ContactVector& lhs, const ContactVector& rhs)
    {
        value = _mm_mul_ps(lhs.value, rhs.value);
    }
    __forceinline void mul4(const ContactScalar& scale)
    {
        value = _mm_mul_ps(scale.broadcast(), value);
    }
    __forceinline void subMul4(const ContactScalar& scale, const ContactVector& rhs)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(scale.broadcast(), rhs.value));
    }
    __forceinline void SetAllComponents(const ContactScalar& scalar)
    {
        value = scalar.broadcast();
    }
    __forceinline void setW(const ContactVector& rhs)
    {
        value = _mm_shuffle_ps(value, _mm_unpackhi_ps(value, rhs.value), 0xc4);
    }
    __forceinline void setCross(const ContactVector& lhs, const ContactVector& rhs)
    {
        __m128 positive =
            _mm_mul_ps(_mm_shuffle_ps(lhs.value, lhs.value, 0xc9), _mm_shuffle_ps(rhs.value, rhs.value, 0xd2));
        __m128 negative =
            _mm_mul_ps(_mm_shuffle_ps(lhs.value, lhs.value, 0xd2), _mm_shuffle_ps(rhs.value, rhs.value, 0xc9));
        value = _mm_sub_ps(positive, negative);
    }
    __forceinline ContactScalar dot3(const ContactVector& rhs) const
    {
        __m128 products = _mm_mul_ps(value, rhs.value);
        __m128 partial = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), partial);
    }
    __forceinline ContactScalar horizontalAdd3() const
    {
        __m128 partial = _mm_add_ss(_mm_shuffle_ps(value, value, 0x55), value);
        return _mm_add_ss(_mm_shuffle_ps(value, value, 0xaa), partial);
    }
    __forceinline ContactScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline ContactScalar lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 squared = dot3(*this).getQuad();
        const __m128 mask = _mm_cmpeq_ss(squared, zero);
        const __m128 estimate = _mm_rsqrt_ss(squared);
        const __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate));
        const __m128 inverse = _mm_mul_ss(_mm_mul_ss(half, estimate), correction);
        return _mm_andnot_ps(mask, inverse);
    }
    __forceinline void normalize3()
    {
        __m128 scale = lengthInverse3().broadcast();
        value = _mm_mul_ps(scale, value);
    }
    __forceinline ContactScalar normalizeWithLength3()
    {
        __m128 squared = dot3(*this).getQuad();
        __m128 scale = lengthInverse3().broadcast();
        value = _mm_mul_ps(scale, value);
        return _mm_mul_ss(squared, scale);
    }

  private:
    __m128 value;
};

class StoredDistance
{
  public:
    StoredDistance()
    {}
    operator float() const
    {
        return value;
    }
    void operator=(float input)
    {
        value = input;
    }

  private:
    float value;
};
struct ContactClosest
{
    ContactVector point;
    ContactVector delta;
    StoredDistance distanceSquared;
};
int hkLineSegmentUtil_closestLineSegLineSeg(const ContactVector&, const ContactVector&, const ContactVector&, const ContactVector&,
                 ContactClosest&);

static __forceinline void orient(ContactVector& out, const ContactVector& axis)
{
    ContactScalar alignment = out.dot3(axis);
    out.getQuad() = _mm_xor_ps(_mm_and_ps(alignment.broadcast(), DAT_010c44d0), out.getQuad());
}

static __forceinline ContactScalar pointToEdge(ContactVector* first, ContactVector* second, const ContactVector& axis,
                                               ContactVector& out)
{
    ContactVector separation;
    separation.setSub4(first[0], second[0]);
    out = axis;
    return separation.dot3(out);
}
static __forceinline ContactScalar pointToTriangle(const ContactVector& point, ContactVector* triangle,
                                                   const ContactVector& axis, ContactVector& out)
{
    ContactVector edge0, edge1, edge2;
    edge1.setSub4(triangle[2], triangle[1]);
    edge2.setSub4(triangle[0], triangle[2]);
    out.setCross(edge1, edge2);
    ContactScalar inverse = out.lengthInverse3();
    orient(out, axis);
    out.mul4(inverse);
    ContactVector separation;
    separation.setSub4(point, triangle[0]);
    return separation.dot3(out);
}
static __forceinline void edgeToEdge(ContactVector* first, ContactVector* second, const ContactVector& axis,
                                     ContactVector& point, ContactVector& out)
{
    ContactVector edgeA, edgeB;
    edgeA.setSub4(first[1], first[0]);
    edgeB.setSub4(second[1], second[0]);
    ContactClosest closest;
    hkLineSegmentUtil_closestLineSegLineSeg(first[0], edgeA, second[0], edgeB, closest);
    out.setCross(edgeA, edgeB);
    float combinedLength;
    {
        ContactVector squareA, squareB, sum;
        squareA.setMul4(edgeA, edgeA);
        squareB.setMul4(edgeB, edgeB);
        sum.setAdd4(squareA, squareB);
        combinedLength = sum.horizontalAdd3();
    }
    float crossLength = out.lengthSquared3();
    if (crossLength * (double)0.001f > combinedLength * combinedLength)
    {
        orient(out, axis);
        out.normalize3();
    }
    else
    {
        out = axis;
    }
    ContactVector separation;
    separation.setSub4(first[0], second[0]);
    ContactScalar distance = separation.dot3(out);
    point = closest.point;
    ContactVector splat;
    splat.SetAllComponents(distance);
    out.setW(splat);
}
// Dispatches on contact shape pair to compute the contact normal and closest point via point-to-point, point-to-edge, point-to-triangle, or edge-to-edge routines.
// @fnv 0x00da8a00
// src: GUESS 0x00da8a00 (confidence: medium)
void Object_ComputeContactPointAndNormal(ContactVector* first, ContactVector* second, int countA, int countB, const ContactVector& axis,
                  ContactVector& point, ContactVector& out)
{
    int pair = (countA << 3) | countB;
    switch (pair)
    {
    case 9: {
        out.setSub4(first[0], second[0]);
        float alignment = axis.dot3(out);
        float squared = out.lengthSquared3();
        float distance;
        if (alignment * 1000.0 < squared)
        {
            distance = out.dot3(axis);
            out = axis;
        }
        else
            distance = out.normalizeWithLength3();
        out(3) = distance;
        point = first[0];
        break;
    }
    case 10: {
        ContactScalar distance = pointToEdge(first, second, axis, out);
        out(3) = distance;
        point = first[0];
        break;
    }
    case 17: {
        ContactScalar distance = pointToEdge(second, first, axis, out);
        point = second[0];
        point.subMul4(distance, out);
        out(3) = -distance;
        break;
    }
    case 25: {
        ContactVector* swap = first;
        first = second;
        second = swap;
    }
    case 11: {
        ContactScalar distance = pointToTriangle(first[0], second, axis, out);
        if (pair == 11)
        {
            point = first[0];
            out(3) = distance;
        }
        else
        {
            point = first[0];
            point.subMul4(distance, out);
            out(3) = -distance;
        }
        break;
    }
    case 18:
        edgeToEdge(first, second, axis, point, out);
        break;
    }
}

extern const __m128 DAT_01017d10;
extern const float DAT_010c6090;
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);

struct Int4
{
    int i[4];
};

// Weights the point against three face normals of a 4-vertex shape; returns -1, a face index, or the FUN_00da8390 result when two best distances are close.
// @fnv 0x00da8fb0
// src: GUESS 0x00da8fb0 (confidence: low)
static __declspec(noinline) int Hkpgsk_ProcessEntries_00da8fb0(const hkVector4* vertices, const hkVector4* point, float orient)
{
    __m128 e21 = _mm_sub_ps(vertices[2].m_vComponents, vertices[1].m_vComponents);
    __m128 e02 = _mm_sub_ps(vertices[0].m_vComponents, vertices[2].m_vComponents);
    __m128 e10 = _mm_sub_ps(vertices[1].m_vComponents, vertices[0].m_vComponents);
    __m128 e30 = _mm_sub_ps(vertices[3].m_vComponents, vertices[0].m_vComponents);
    __m128 e31 = _mm_sub_ps(vertices[3].m_vComponents, vertices[1].m_vComponents);
    __m128 e32 = _mm_sub_ps(vertices[3].m_vComponents, vertices[2].m_vComponents);

    __m128 normals[3];
    normals[0] = cross(e21, e31);
    normals[1] = cross(e02, e32);
    normals[2] = cross(e10, e30);

    __m128 diff = _mm_sub_ps(point->m_vComponents, vertices[3].m_vComponents);
    __m128 orientVec = _mm_shuffle_ps(_mm_load_ss(&orient), _mm_load_ss(&orient), 0);
    __m128 dir = _mm_mul_ps(diff, orientVec);

    __m128 c0 = normals[0];
    __m128 c1 = normals[1];
    __m128 c2 = normals[2];
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, tmp), c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);

    __m128 x = _mm_shuffle_ps(dir, dir, 0x00);
    __m128 y = _mm_shuffle_ps(dir, dir, 0x55);
    __m128 z = _mm_shuffle_ps(dir, dir, 0xaa);

    GskVectorCallLocal_00da8500 weights;
    weights.q = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, c1), _mm_mul_ps(x, c0)),
                              _mm_mul_ps(z, c2));

    GskVectorCallLocal_00da8500 dotsSqr;
    dotsSqr.q = _mm_mul_ps(_mm_and_ps(weights.q, DAT_01017d10), weights.q);

    float dist[4];
    for (int i = 0; i < 3; ++i)
    {
        __m128 n = normals[i];
        __m128 sq = _mm_mul_ps(n, n);
        __m128 s1 = _mm_shuffle_ps(sq, sq, 0x55);
        __m128 s2 = _mm_shuffle_ps(sq, sq, 0xaa);
        float lenSq;
        _mm_store_ss(&lenSq, _mm_add_ss(s2, _mm_add_ss(s1, sq)));
        if (lenSq != 0.0f)
        {
            dist[i] = dotsSqr.q.m128_f32[i] / lenSq;
        }
        else
        {
            dist[i] = 3.402820018375656e+38f;
        }
    }

    int bestIdx = 1;
    if (dist[0] > dist[1])
    {
        swapFloat(dist[0], dist[1]);
        bestIdx = 0;
    }
    if (dist[1] > dist[2])
    {
        swapFloat(dist[1], dist[2]);
        if (dist[0] > dist[1])
        {
            swapFloat(dist[0], dist[1]);
        }
    }
    else
    {
        bestIdx = 2;
    }

    if (dist[2] < DAT_010c6090)
    {
        return -1;
    }
    if (dist[1] * 1.1f < dist[2])
    {
        return bestIdx;
    }
    *(Int4*)dist = *(const Int4*)&weights;
    return hkVector4_ProcessEntries_00da8390((const hkVector4*)vertices, (const hkVector4*)point, dist);
}

hkVector4* g_v;
hkVector4* g_p;
float g_f;
int g_out;

void dummy()
{
    g_out = Hkpgsk_ProcessEntries_00da8fb0(g_v, g_p, g_f);
}

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern const float DAT_010d51c4;

class GapScalar
{
    __m128 data;

  public:
    GapScalar(const __m128& v) : data(v)
    {}
    GapScalar(float f) : data(_mm_load_ss(&f))
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, data);
        return f;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(data, data, 0);
    }
    __forceinline const __m128& bits() const
    {
        return data;
    }
};
class GapVector;
class GapRotation;
class GapTransform;
class GapVector
{
    __m128 data;

  public:
    __forceinline void operator=(const GapVector& v)
    {
        data = v.data;
    }
    __forceinline __m128& bits()
    {
        return data;
    }
    __forceinline const __m128& bits() const
    {
        return data;
    }
    operator __m128() const
    {
        return data;
    }
    __forceinline void edgeSubtract(const GapVector& a, const GapVector& b)
    {
        __m128 anchor = b.data;
        __m128& root = anchor;
        data = _mm_sub_ps(a.data, root);
    }
    __forceinline void fill(const GapScalar& f)
    {
        data = f.splat();
    }
    __forceinline void subtract(const GapVector& a, const GapVector& b)
    {
        data = _mm_sub_ps(a.data, b.data);
    }
    __forceinline void scale(const GapScalar& f)
    {
        data = _mm_mul_ps(data, f.splat());
    }
    __forceinline void cross(const GapVector& a, const GapVector& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 0xc9), _mm_shuffle_ps(b.data, b.data, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 0xd2), _mm_shuffle_ps(b.data, b.data, 0xc9));
        data = _mm_sub_ps(first, second);
    }
    __forceinline void negate(const GapVector& v)
    {
        static __declspec(align(16)) const unsigned mask[4] = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
        data = _mm_xor_ps(v.data, *reinterpret_cast<const __m128*>(mask));
    }
    __forceinline void inverseDirection(const GapRotation&, const GapVector&);
    __forceinline void transformPosition(const GapTransform&, const GapVector&);
    __forceinline GapScalar dot(const GapVector& b) const
    {
        __m128 p = _mm_mul_ps(data, b.data);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), sum);
    }
    __forceinline GapScalar squaredLength() const
    {
        return dot(*this);
    }
    __forceinline GapScalar inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        __m128 len = dot(*this).bits();
        __m128 eq = _mm_cmpeq_ss(len, zero), inv = _mm_rsqrt_ss(len);
        __m128 refined = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, inv), inv)));
        return _mm_andnot_ps(eq, refined);
    }
    __forceinline void normalize()
    {
        __m128 factor = inverseLength().splat();
        data = _mm_mul_ps(factor, data);
    }
    __forceinline void fastNormalize()
    {
        __m128 len = dot(*this).bits();
        GapScalar inv = _mm_rsqrt_ss(len);
        data = _mm_mul_ps(data, inv.splat());
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&data)[i];
    }
};
class GapRotation
{
    GapVector x, y, z;

  public:
    __forceinline GapVector& column(int i)
    {
        return (&x)[i];
    }
    __forceinline const GapVector& column(int i) const
    {
        return (&x)[i];
    }
};
class GapTransform
{
    GapRotation rotation;
    GapVector translation;

  public:
    __forceinline GapTransform(const GapTransform& t)
    {
        const GapVector a = t.rotation.column(0), b = t.rotation.column(1), c = t.rotation.column(2),
                        d = t.rotation.column(3);
        rotation.column(0) = a;
        rotation.column(1) = b;
        rotation.column(2) = c;
        rotation.column(3) = d;
    }
    __forceinline const GapRotation& orientation() const
    {
        return rotation;
    }
    __forceinline const GapVector& offset() const
    {
        return translation;
    }
};
__forceinline void GapVector::inverseDirection(const GapRotation& r, const GapVector& b)
{
    __m128 c0 = r.column(0).bits(), c1 = r.column(1).bits(), c2 = r.column(2).bits();
    {
        __m128 lo, hi;
        lo = _mm_unpacklo_ps(c0, c1);
        hi = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(lo, c2);
        __m128& rowY = c1;
        rowY = _mm_shuffle_ps(_mm_movehl_ps(c0, lo), c2, 0xd4);
        c2 = hi;
    }
    const __m128 b0 = _mm_shuffle_ps(b.data, b.data, 0), r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(b.data, b.data, 0x55), r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(b.data, b.data, 0xaa), r2 = _mm_mul_ps(c2, b2);
    data = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void GapVector::transformPosition(const GapTransform& t, const GapVector& b)
{
    const GapRotation& r = t.orientation();
    __m128 b0 = _mm_shuffle_ps(b.data, b.data, 0), r0 = _mm_mul_ps(r.column(0).bits(), b0);
    __m128 b1 = _mm_shuffle_ps(b.data, b.data, 0x55), r1 = _mm_mul_ps(r.column(1).bits(), b1);
    __m128 b2 = _mm_shuffle_ps(b.data, b.data, 0xaa), r2 = _mm_mul_ps(r.column(2).bits(), b2);
    data = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.offset().bits()));
}
template <class T> class GapValue
{
    T value;

  public:
    __forceinline GapValue()
    {}
    __forceinline void operator=(T v)
    {
        value = v;
    }
    __forceinline T val() const
    {
        return value;
    }
    __forceinline operator T() const
    {
        return val();
    }
};
struct GapBool
{
    char value;
    GapBool(bool b) : value(static_cast<char>(b))
    {}
};
class GapVertex : public GapVector
{
};
struct GapShape
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void support(const GapVector&, GapVertex&) const;
};
struct GapLineResult
{
    GapVector point, difference;
    GapValue<float> distance;
};
int __cdecl hkLineSegmentUtil_closestLineSegLineSeg(const GapVector&, const GapVector&, const GapVector&, const GapVector&, GapLineResult&);
namespace GapMath {
inline int negative(const GapScalar& v)
{
    return _mm_movemask_ps(v.bits()) & 1;
}
inline float absolute(float v)
{
    return ::fabsf(v);
}
}
extern const signed char DAT_010cb438[], DAT_010cb440[];
namespace GapUtil {
__forceinline void signs(GapVector& out, const GapVector& v)
{
    static __declspec(align(16)) const unsigned mask[4] = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
    out.bits() = _mm_xor_ps(out.bits(), _mm_and_ps(v.bits(), *reinterpret_cast<const __m128*>(mask)));
}
__forceinline void points(const GapTransform& t, const GapVector* in, int count, GapVector* out)
{
    GapTransform transform(t);
    int i = count - 1;
    do
    {
        out[i].transformPosition(transform, in[i]);
    } while (--i >= 0);
}
}
enum GapStatus
{
    GAP_OK,
    GAP_SAMPLED,
    GAP_NO_MEMORY,
    GAP_UNSOLVABLE,
    GAP_PENETRATING
};
class GapSolver
{
  public:
    enum
    {
        GSK_NONE_NONE = 0,
        GSK_POINT_POINT = 9,
        GSK_POINT_EDGE = 10,
        GSK_POINT_TRIANGLE = 11,
        GSK_POINT_TETRA = 12,
        GSK_EDGE_POINT = 17,
        GSK_EDGE_EDGE = 18,
        GSK_EDGE_TRIANGLE = 19,
        GSK_TRIANGLE_POINT = 25,
        GSK_TRIANGLE_EDGE = 26,
        GSK_TETRA_POINT = 33
    };
    enum NextCase
    {
        NEXT_IS_BREAK,
        NEXT_IS_PENETRATION,
        NEXT_IS_EDGE_EDGE
    };
    enum SupportTypes
    {
        BUILD_NEG_SUPPORT = -1,
        BUILD_NO_SUPPORT = 0,
        BUILD_POS_SUPPORT = 1
    };
    enum SupportState
    {
        SUPPORT_CHANGED = 0,
        DONT_CALL_GET_SUPPORTING_VERTEX_A = 1,
        DONT_CALL_GET_SUPPORTING_VERTEX_B = -1
    };
    enum ReduceDimensionResult
    {
        REDUCE_DIMENSION_OK,
        REDUCE_DIMENSION_PENETRATION
    };
    GapValue<int> countA, countB, limitA, limitB;
    GapValue<unsigned> skipPenetration;
    GapValue<int> changed;
    GapVertex verticesA[4];
    GapVector sourceA[4], verticesB[4];
    GapVertex sourceB[4];
    GapVector axis;
    GapLineResult closest;
    GapVector dots;
    GapValue<int> previousB;
    SupportState supportState;
    __forceinline ReduceDimensionResult reduce();
    __forceinline void mark(int f)
    {
        changed = f;
    }
    void hkpGsk_processEdgeTriangle(const GapShape*, const GapShape*, const GapTransform&);
    int TestTriangleOrientationAndSwapVertices(const GapVector&, GapVector*, SupportTypes);
    NextCase ClipPolygonAgainstSegment(GapVector*, GapVector*, GapValue<int>&, GapValue<int>&, GapBool, SupportTypes);
    GapStatus hkpGsk_getClosestFeature(const GapShape*, const GapShape*, const GapTransform&, GapVector&);
};

// src: GUESS 0x00da8390 (confidence: low)
static __declspec(noinline) int hkVector4_ProcessEntries_00da8390(const GapVector& point, const GapVector* tetra, GapVector& weights)
{
    for (int i = 0; i < 3; ++i)
    {
        int next = DAT_010cb440[i + 2], prev = DAT_010cb440[i];
        if (weights(next) >= 0.0f && weights(prev) >= 0.0f)
        {
            GapVector e0, e1, d0, d3;
            e0.subtract(tetra[next], tetra[i]);
            e1.subtract(tetra[prev], tetra[i]);
            d0.subtract(point, tetra[i]);
            d3.subtract(tetra[3], tetra[i]);
            float a = d0.dot(e0), b = d0.dot(e1), c = d3.dot(e0), d = d3.dot(e1);
            if (GapMath::negative(a * d - b * c))
                weights(prev) = -1.0f;
            else
                weights(next) = -1.0f;
        }
    }
    if (weights(0) > 0.0f)
        return 0;
    if (weights(1) > 0.0f)
        return 1;
    if (weights(2) > 0.0f)
        return 2;
    return -1;
}
// src: GUESS 0x00da8fb0 (confidence: low)
static __declspec(noinline) int Hkpgsk_ProcessEntries_00da8fb0(const GapVector& point, const GapVector* tetra, float sign)
{
    GapRotation normals;
    GapVector e0, e1, e2;
    e0.subtract(tetra[2], tetra[1]);
    e1.subtract(tetra[0], tetra[2]);
    e2.subtract(tetra[3], tetra[2]);
    GapVector n0, n1, n2;
    n0.cross(e0, e2);
    n1.cross(e1, e2);
    e0.subtract(tetra[1], tetra[0]);
    e1.subtract(tetra[3], tetra[0]);
    n2.cross(e0, e1);
    normals.column(0) = n0;
    normals.column(1) = n1;
    normals.column(2) = n2;
    GapVector relative;
    relative.subtract(point, tetra[3]);
    relative.scale(sign);
    GapVector distances;
    distances.inverseDirection(normals, relative);
    GapVector squared;
    squared.bits() = _mm_mul_ps(_mm_and_ps(distances.bits(), DAT_01017d10), distances.bits());
    float scores[3];
    for (int i = 0; i < 3; ++i)
    {
        float denominator = normals.column(i).squaredLength();
        scores[i] = denominator != 0.0f ? squared(i) / denominator : DAT_0104da48;
    }
    int selected = 1;
    if (scores[1] >= scores[0])
    {
        float t = scores[0];
        scores[0] = scores[1];
        scores[1] = t;
        selected = 0;
    }
    if (scores[2] >= scores[1])
    {
        float t = scores[1];
        scores[1] = scores[2];
        scores[2] = t;
        if (scores[1] >= scores[0])
        {
            scores[1] = scores[0];
            selected = 2;
        }
    }
    if (DAT_010c6090 > scores[0])
        return -1;
    if (scores[1] * DAT_010290f8 >= scores[0])
        return selected;
    GapVector fallback = distances;
    return hkVector4_ProcessEntries_00da8390(point, tetra, fallback);
}
static __forceinline void process_point_edge(GapVector* __restrict vertexA, GapVector* __restrict vertexB,
                                             GapValue<int>& dimB, GapVector& support, GapSolver::SupportTypes stype)
{
    GapVector edge;
    edge.subtract(vertexB[1], vertexB[0]);
    GapVector a;
    a.subtract(vertexB[1], vertexA[0]);
    GapVector b;
    b.subtract(vertexB[0], vertexA[0]);
    GapScalar adot = a.dot(edge);
    GapScalar bdot = b.dot(edge);
    int aneg = GapMath::negative(adot);
    int bneg = GapMath::negative(bdot);
    if (aneg != bneg)
    {
        edge.fastNormalize();
        GapVector c;
        c.cross(a, b);
        if (stype == GapSolver::BUILD_POS_SUPPORT)
        {
            support.cross(edge, c);
        }
        else
        {
            support.cross(c, edge);
        }
    }
    else
    {
        if (aneg)
        {
            vertexB[0] = vertexB[1];
            vertexB[4] = vertexB[5];
        }
        dimB = dimB - 1;
        if (stype == GapSolver::BUILD_POS_SUPPORT)
        {
            support.subtract(vertexA[0], vertexB[0]);
        }
        else
        {
            support.subtract(vertexB[0], vertexA[0]);
        }
    }
}
static __forceinline void process_point_edge_pos(GapVector* __restrict vertexA, GapVector* __restrict vertexB,
                                                 GapValue<int>& dimB, GapVector& support, GapSolver::SupportTypes stype)
{
    GapVector edge;
    edge.subtract(vertexB[1], vertexB[0]);
    GapVector b;
    b.subtract(vertexB[0], vertexA[0]);
    GapVector a;
    a.subtract(vertexB[1], vertexA[0]);
    GapScalar adot = a.dot(edge);
    GapScalar bdot = b.dot(edge);
    int aneg = GapMath::negative(adot);
    int bneg = GapMath::negative(bdot);
    if (aneg != bneg)
    {
        edge.fastNormalize();
        GapVector c;
        c.cross(a, b);
        if (stype == GapSolver::BUILD_POS_SUPPORT)
        {
            support.cross(edge, c);
        }
        else
        {
            support.cross(c, edge);
        }
    }
    else
    {
        if (aneg)
        {
            vertexB[0] = vertexB[1];
            vertexB[4] = vertexB[5];
        }
        dimB = dimB - 1;
        if (stype == GapSolver::BUILD_POS_SUPPORT)
        {
            support.subtract(vertexA[0], vertexB[0]);
        }
        else
        {
            support.subtract(vertexB[0], vertexA[0]);
        }
    }
}
__forceinline GapSolver::ReduceDimensionResult GapSolver::reduce()
{
    supportState = SUPPORT_CHANGED;
    while (1)
    {
        switch ((countA << 3) | countB)
        {
        case GSK_POINT_EDGE:
        case_point_edge: {
            process_point_edge_pos(verticesA, verticesB, countB, axis, BUILD_POS_SUPPORT);
            break;
        }
        case GSK_EDGE_POINT:
        case_edge_point: {
            process_point_edge(verticesB, verticesA, countA, axis, BUILD_NEG_SUPPORT);
            break;
        }
        case GSK_POINT_TRIANGLE:
        case_point_triangle: {
            int mask = TestTriangleOrientationAndSwapVertices(verticesA[0], verticesB, BUILD_POS_SUPPORT);
            if (mask == 7)
            {
                break;
            }
            int CI = DAT_010cb438[mask];
            ;
            if (CI < 0)
            {
                CI += 8;
                if (CI > 3)
                {
                    CI = 1;
                }
                countB = countB - 1;
                verticesB[CI] = verticesB[2];
                sourceB[CI] = sourceB[2];
                goto case_point_edge;
            }
            int LI = DAT_010cb440[CI];
            int UI = DAT_010cb440[CI + 2];
            GapVector diff;
            diff.subtract(verticesA[0], verticesB[CI]);
            GapVector ledge;
            ledge.subtract(verticesB[LI], verticesB[CI]);
            GapVector uedge;
            uedge.subtract(verticesB[UI], verticesB[CI]);
            if (GapMath::negative(diff.dot(ledge)))
            {
                countB = 2;
                verticesB[LI] = verticesB[2];
                sourceB[LI] = sourceB[2];
            }
            else
            {
                countB = 2;
                verticesB[UI] = verticesB[2];
                sourceB[UI] = sourceB[2];
                continue;
            }
            if (GapMath::negative(diff.dot(uedge)))
            {
                if (UI == countB)
                {
                    UI = LI;
                }
                countB = countB - 1;
                verticesB[UI] = verticesB[countB];
                sourceB[UI] = sourceB[countB];
            }
            continue;
        }
        case GSK_TRIANGLE_POINT:
        case_triangle_point: {
            int mask = TestTriangleOrientationAndSwapVertices(verticesB[0], verticesA, BUILD_NEG_SUPPORT);
            if (mask == 7)
            {
                break;
            }
            int CI = DAT_010cb438[mask];
            ;
            if (CI < 0)
            {
                CI += 8;
                if (CI > 3)
                {
                    CI = 1;
                }
                countA = countA - 1;
                verticesA[CI] = verticesA[2];
                goto case_edge_point;
            }
            int LI = DAT_010cb440[CI];
            int UI = DAT_010cb440[CI + 2];
            GapVector diff;
            diff.subtract(verticesB[0], verticesA[CI]);
            GapVector ledge;
            ledge.subtract(verticesA[LI], verticesA[CI]);
            GapVector uedge;
            uedge.subtract(verticesA[UI], verticesA[CI]);
            if (GapMath::negative(diff.dot(ledge)))
            {
                ;
                countA = 2;
                verticesA[LI] = verticesA[2];
            }
            else
            {
                countA = 2;
                verticesA[UI] = verticesA[countA];
                continue;
            }
            if (GapMath::negative(diff.dot(uedge)))
            {
                if (UI == countA)
                {
                    UI = LI;
                }
                countA = countA - 1;
                verticesA[UI] = verticesA[countA];
            }
            continue;
        }
        case GSK_EDGE_TRIANGLE: {
            NextCase nextcase = ClipPolygonAgainstSegment(verticesA, verticesB, countA, countB, previousB == 2, BUILD_POS_SUPPORT);
            switch (nextcase)
            {
            case NEXT_IS_EDGE_EDGE:
                goto case_edge_edge;
            case NEXT_IS_PENETRATION:
                goto penetration;
            default:
                break;
            }
            break;
        }
        case GSK_TRIANGLE_EDGE: {
            NextCase nextcase = ClipPolygonAgainstSegment(verticesB, verticesA, countB, countA, previousB == 2, BUILD_NEG_SUPPORT);
            switch (nextcase)
            {
            case NEXT_IS_EDGE_EDGE:
                goto case_edge_edge;
            case NEXT_IS_PENETRATION:
                goto penetration;
            default:
                break;
            }
            break;
        }
        case GSK_EDGE_EDGE:
        case_edge_edge: {
            GapVector edgeA;
            edgeA.subtract(verticesA[1], verticesA[0]);
            GapVector edgeB;
            edgeB.edgeSubtract(verticesB[1], verticesB[0]);
            int result = hkLineSegmentUtil_closestLineSegLineSeg(verticesA[0], edgeA, verticesB[0], edgeB, closest);
            if (result == 0)
            {
                axis.cross(edgeA, edgeB);
                GapVector pt0;
                pt0.subtract(verticesA[0], verticesB[0]);
                GapVector dots;
                dots.fill(axis.dot(pt0));
                GapUtil::signs(axis, dots);
                break;
            }
            if (result & 1)
            {
                verticesA[0] = verticesA[1];
                countA = 1;
            }
            else if (result & 2)
            {
                countA = 1;
            }
            if (result & 4)
            {
                verticesB[0] = verticesB[1];
                sourceB[0] = sourceB[1];
                countB = 1;
            }
            else if (result & 8)
            {
                countB = 1;
            }
            continue;
        }
        case GSK_POINT_TETRA: {
            int maxIndex = Hkpgsk_ProcessEntries_00da8fb0(verticesA[0], verticesB, 1.0f);
            if (maxIndex >= 0)
            {
                ;
                countB = countB - 1;
                verticesB[maxIndex] = verticesB[3];
                sourceB[maxIndex] = sourceB[3];
                goto case_point_triangle;
            }
            goto penetration;
        }
        case GSK_TETRA_POINT: {
            int maxIndex = Hkpgsk_ProcessEntries_00da8fb0(verticesB[0], verticesA, -1.0f);
            if (maxIndex >= 0)
            {
                ;
                countA = countA - 1;
                verticesA[maxIndex] = verticesA[3];
                goto case_triangle_point;
            }
            goto penetration;
        }
        case GSK_POINT_POINT: {
            axis.subtract(verticesA[0], verticesB[0]);
            break;
        }
        case GSK_NONE_NONE:;
        default:
        penetration:
            return REDUCE_DIMENSION_PENETRATION;
        }
        break;
    }
    previousB = countB;
    return REDUCE_DIMENSION_OK;
}
__forceinline float hkGskCalcSupportDistSquared(const GapVector& support, const GapVector& newPoint,
                                                const GapVector& oldPoint)
{
    GapVector diff0;
    diff0.subtract(newPoint, oldPoint);
    const float dot0 = diff0.dot(support);
    return GapMath::absolute(dot0) * dot0;
}
// @fnv 0x00daad40
// src: XBOX_PDB 0x00daad40
GapStatus GapSolver::hkpGsk_getClosestFeature(const GapShape* shapeA, const GapShape* shapeB, const GapTransform& aTb,
                                  GapVector& separatingNormalOut)
{
    GapUtil::points(aTb, &sourceB[0], countB, &verticesB[0]);
    int loopCounter = 0;
    float terminationEpsSquared = 1e-10f;
    while (1)
    {
        loopCounter++;
        terminationEpsSquared *= 2.0f;
        int dim = countA + countB;
        ReduceDimensionResult result = reduce();
        const float supportLengthSquared = axis.squaredLength();
        changed = changed | (countA + countB - dim);
        {
            GapVector diff;
            diff.subtract(verticesA[0], verticesB[0]);
            float distUnscaled = diff.dot(axis);
            if (result != REDUCE_DIMENSION_OK ||
                GapMath::absolute(distUnscaled) * distUnscaled <= terminationEpsSquared * supportLengthSquared ||
                supportLengthSquared < terminationEpsSquared)
            {
                if (!skipPenetration.val())
                {
                    hkpGsk_processEdgeTriangle(shapeA, shapeB, aTb);
                    break;
                }
                else
                {
                    if (countA + countB > 4)
                    {
                        if (countA > countB)
                        {
                            countA = 3;
                            countB = 1;
                        }
                        else
                        {
                            countA = 1;
                            countB = 3;
                        }
                    }
                    return GAP_PENETRATING;
                }
            }
        }
        const float eps = terminationEpsSquared * supportLengthSquared;
        if (loopCounter & 1)
        {
            if (countA != limitA && supportState != DONT_CALL_GET_SUPPORTING_VERTEX_A)
            {
                GapVector supportA;
                supportA.negate(axis);
                shapeA->support(supportA, verticesA[countA]);
                if (hkGskCalcSupportDistSquared(supportA, verticesA[countA], verticesA[0]) > eps)
                {
                    switch (countA)
                    {
                    case 3:
                        if (hkGskCalcSupportDistSquared(supportA, verticesA[countA], verticesA[2]) < eps)
                            break;
                    case 2:
                        if (hkGskCalcSupportDistSquared(supportA, verticesA[countA], verticesA[1]) < eps)
                            break;
                    default:
                        for (int i = 0; i < countA - 1; i++)
                        {
                            ;
                        }
                        countA = countA + 1;
                        mark(1);
                        continue;
                    }
                }
            }
        }
        if (countB != limitB && supportState != DONT_CALL_GET_SUPPORTING_VERTEX_B)
        {
            GapVector supportB;
            supportB.inverseDirection(aTb.orientation(), axis);
            shapeB->support(supportB, sourceB[countB]);
            if (hkGskCalcSupportDistSquared(supportB, sourceB[countB], sourceB[0]) > eps)
            {
                switch (countB)
                {
                case 3:
                    if (hkGskCalcSupportDistSquared(supportB, sourceB[countB], sourceB[2]) < eps)
                        break;
                case 2:
                    if (hkGskCalcSupportDistSquared(supportB, sourceB[countB], sourceB[1]) < eps)
                        break;
                default:
                    for (int i = 0; i < countB; i++)
                    {
                        ;
                    }
                    verticesB[countB].transformPosition(aTb, sourceB[countB]);
                    countB = countB + 1;
                    mark(1);
                    continue;
                }
            }
        }
        if (!(loopCounter & 1))
        {
            if (countA != limitA && supportState != DONT_CALL_GET_SUPPORTING_VERTEX_A)
            {
                GapVector supportA;
                supportA.negate(axis);
                shapeA->support(supportA, verticesA[countA]);
                if (hkGskCalcSupportDistSquared(supportA, verticesA[countA], verticesA[0]) > eps)
                {
                    switch (countA)
                    {
                    case 3:
                        if (hkGskCalcSupportDistSquared(supportA, verticesA[countA], verticesA[2]) < eps)
                            break;
                    case 2:
                        if (hkGskCalcSupportDistSquared(supportA, verticesA[countA], verticesA[1]) < eps)
                            break;
                    default:
                        for (int i = 0; i < countA; i++)
                        {
                            ;
                        }
                        countA = countA + 1;
                        mark(1);
                        continue;
                    }
                }
            }
        }
        break;
    }
    {
        GapVector diff;
        diff.subtract(verticesA[0], verticesB[0]);
        axis.normalize();
        separatingNormalOut = axis;
        float dist = diff.dot(axis);
        separatingNormalOut(3) = dist;
        axis(3) = dist;
    }
    return GAP_OK;
}

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_rsqrt_ss(__m128 a);
extern "C" int _mm_movemask_ps(__m128 a);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, int imm);

static inline __m128 dot3DA(__m128 dx, __m128 dy)
{
    __m128 dm = _mm_mul_ps(dx, dy);
    __m128 ds = _mm_add_ss(_mm_shuffle_ps(dm, dm, 0x55), dm);
    return _mm_add_ss(_mm_shuffle_ps(dm, dm, 0xaa), ds);
}
static inline __m128 crossDA(__m128 cx, __m128 cy)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(cx, cx, 0xc9), _mm_shuffle_ps(cy, cy, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(cx, cx, 0xd2), _mm_shuffle_ps(cy, cy, 0xc9)));
}
struct SimplexDA
{
    GskVectorCallLocal_00da8500 m_kPointA[4];
    GskVectorCallLocal_00da8500 m_kPointB[4];
};
static __forceinline GskVectorCallLocal_00da8500 subV(const GskVectorCallLocal_00da8500& a, const GskVectorCallLocal_00da8500& b)
{
    GskVectorCallLocal_00da8500 r(a);
    r.q = _mm_sub_ps(r.q, b.q);
    return r;
}
// @fnv 0x00da9210
// src: GUESS 0x00da9210 (confidence: low)
static void Hkpgsk_ComputeValues_00da9210(SimplexDA* apSimplex, int* apCount, int flag, GskVectorCallLocal_00da8500* out, const GskVectorCallLocal_00da8500* apPoint)
{
    GskVectorCallLocal_00da8500 vPoint;
    vPoint.q = apPoint->q;
    GskVectorCallLocal_00da8500 vDir = subV(apSimplex->m_kPointA[1], apSimplex->m_kPointA[0]);
    GskVectorCallLocal_00da8500 vA = subV(apSimplex->m_kPointA[1], vPoint);
    GskVectorCallLocal_00da8500 vB = subV(apSimplex->m_kPointA[0], vPoint);
    __m128 d1 = dot3DA(vA.q, vDir.q);
    __m128 d2 = dot3DA(vB.q, vDir.q);
    int sg1 = _mm_movemask_ps(d1) & 1;
    int sg2 = _mm_movemask_ps(d2) & 1;
    if (sg1 != sg2)
    {
        __m128 vInvLen = _mm_rsqrt_ss(dot3DA(vDir.q, vDir.q));
        __m128 vNorm = _mm_mul_ps(_mm_shuffle_ps(vInvLen, vInvLen, 0), vDir.q);
        __m128 vCross = crossDA(vA.q, vB.q);
        if (flag == 1)
            out->q = crossDA(vNorm, vCross);
        else
            out->q = crossDA(vCross, vNorm);
        return;
    }
    if (sg1)
    {
        int ii = 0;
        apSimplex->m_kPointA[ii] = apSimplex->m_kPointA[ii + 1];
        apSimplex->m_kPointB[ii] = apSimplex->m_kPointB[ii + 1];
    }
    (*apCount)--;
    if (flag == 1)
        out->q = _mm_sub_ps(vPoint.q, apSimplex->m_kPointA[0].q);
    else
        out->q = _mm_sub_ps(apSimplex->m_kPointA[0].q, vPoint.q);
}

static SimplexDA g_sxDA;
static int g_numDA;
static GskVectorCallLocal_00da8500 g_outDA;
static GskVectorCallLocal_00da8500 g_ppDA;
void CallerDA()
{
    Hkpgsk_ComputeValues_00da9210(&g_sxDA, &g_numDA, 1, &g_outDA, &g_ppDA);
}

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_div_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_set_ps1(float);
    __m128 _mm_setzero_ps();
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
}

struct AlignedPoint
{
    __m128 quad;
    AlignedPoint()
    {}
    AlignedPoint& operator=(const AlignedPoint& v)
    {
        quad = v.quad;
        return *this;
    }
};
static __forceinline AlignedPoint copyAlignedPoint(const PlainVector& p)
{
    AlignedPoint v;
    reinterpret_cast<PlainVector&>(v.quad) = p;
    return v;
}
static __forceinline void swapPoints(AlignedPoint& a, AlignedPoint& b)
{
    AlignedPoint t(a);
    a = b;
    b = t;
}
static __forceinline void assignCounted(AlignedPoint& dest, __m128 value, int* count)
{
    --*count;
    dest.quad = value;
}
struct SolverOutput
{
    AlignedPoint normal, point;
    float distance;
};
extern void __cdecl hkLineSegmentUtil_closestLineSegLineSeg(const AlignedPoint* polygon, const AlignedPoint* direction, const AlignedPoint* vertex,
                                 const AlignedPoint* edge, SolverOutput* result);
static __forceinline __m128 dotThree(__m128 vector, __m128 normal)
{
    __m128 products = _mm_mul_ps(vector, normal);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
    return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), xy);
}
extern const __m128 DAT_010ec7f0;
static __forceinline __m128 blendPoints(__m128 start, __m128 end, __m128 proportion)
{
    __m128 amount = _mm_shuffle_ps(proportion, proportion, 0);
    return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, amount), start), _mm_mul_ps(end, amount));
}
struct CollisionPlanes
{
    __m128 unk000, unk010, unk020, unk030, unk040, unk050;
    __m128 unk060, unk070, unk080, unk090, unk0a0, unk0b0;
    __m128 unk0c0, unk0d0, unk0e0, unk0f0, unk100, unk110;
    __m128 faceNormal120;
    __m128 unk130, unk140, unk150;
    __m128 reference160;
    int unk170;
    int lastSegment174;
    __declspec(noinline) int TestTriangleOrientationAndSwapVertices(const AlignedPoint* point, AlignedPoint* triangle, int mode);
    int __thiscall ClipPolygonAgainstSegment(AlignedPoint* segment, AlignedPoint* polygon, int* volatile segmentCount,
                                int* polygonCount, char recomputeNormal, int segmentIndex);
};

static __forceinline __m128 crossThree(__m128 a, __m128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
// src: GUESS 0x00da8500 (confidence: medium)
int CollisionPlanes::TestTriangleOrientationAndSwapVertices(const AlignedPoint* point, AlignedPoint* triangle, int mode)
{
    __m128 bc = _mm_sub_ps(triangle[2].quad, triangle[1].quad);
    __m128 ca = _mm_sub_ps(triangle[0].quad, triangle[2].quad);
    __m128 ab = _mm_sub_ps(triangle[1].quad, triangle[0].quad);
    __m128 normal = crossThree(bc, ca);
    __m128 d0 = _mm_mul_ps(crossThree(_mm_sub_ps(point->quad, triangle[1].quad), bc), normal);
    __m128 d1 = _mm_mul_ps(crossThree(_mm_sub_ps(point->quad, triangle[2].quad), ca), normal);
    __m128 d2 = _mm_mul_ps(crossThree(_mm_sub_ps(point->quad, triangle[0].quad), ab), normal);
    __m128 lo = _mm_unpacklo_ps(d0, d1), hi = _mm_unpackhi_ps(d0, d1);
    __m128 x = _mm_movelh_ps(lo, d2);
    __m128 y = _mm_shuffle_ps(_mm_movehl_ps(x, lo), d2, 0xd4);
    __m128 z = _mm_shuffle_ps(hi, d2, 0xe4);
    reference160 = _mm_add_ps(z, _mm_add_ps(y, x));
    int mask = _mm_movemask_ps(_mm_cmplt_ps(reference160, _mm_setzero_ps())) & 7;
    if (mode)
    {
        faceNormal120 = normal;
        if (mask == 7 && (_mm_movemask_ps(dotThree(_mm_sub_ps(unk020, unk0a0), normal)) & 1))
        {
            faceNormal120 = _mm_sub_ps(_mm_setzero_ps(), normal);
            AlignedPoint tmp = copyAlignedPoint(reinterpret_cast<const PlainVector&>(triangle[0].quad));
            triangle[0] = triangle[1];
            triangle[1] = tmp;
            tmp = copyAlignedPoint(reinterpret_cast<const PlainVector&>(triangle[4].quad));
            triangle[4] = triangle[5];
            triangle[5] = tmp;
            float old = reference160.m128_f32[0];
            reference160.m128_f32[0] = reference160.m128_f32[1];
            reference160.m128_f32[1] = old;
            unk010.m128_f32[1] = 1;
        }
    }
    return mask;
}
// Tests a segment against a polygon plane, clipping or collapsing the polygon and updating counts based on the intersection mask.
// @fnv 0x00da9340
// src: GUESS 0x00da9340 (confidence: medium)
int __thiscall CollisionPlanes::ClipPolygonAgainstSegment(AlignedPoint* segment, AlignedPoint* polygon, int* volatile segmentCount,
                                             int* polygonCount, char recomputeNormal, int segmentIndex)
{
    AlignedPoint edgeA;
    if (recomputeNormal)
    {
        AlignedPoint scratch;
        __m128 anchor = polygon[0].quad;
        __m128 c = polygon[2].quad;
        __m128 b = polygon[1].quad;
        __m128 normal;
        __m128 firstDistance, secondDistance;
        AlignedPoint edgeB;
        edgeB.quad = _mm_sub_ps(b, c);
        edgeA.quad = _mm_sub_ps(anchor, c);
        __m128 ab = edgeA.quad;
        __m128 bb = edgeB.quad;
        normal = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(bb, bb, 0xc9), _mm_shuffle_ps(ab, ab, 0xd2)),
                            _mm_mul_ps(_mm_shuffle_ps(bb, bb, 0xd2), _mm_shuffle_ps(ab, ab, 0xc9)));
        firstDistance = dotThree(_mm_sub_ps(segment[0].quad, anchor), normal);
        secondDistance = dotThree(_mm_sub_ps(segment[1].quad, anchor), normal);
        if ((_mm_movemask_ps(firstDistance) ^ _mm_movemask_ps(secondDistance)) & 1)
        {
            __m128 proportion = _mm_div_ss(firstDistance, _mm_sub_ss(firstDistance, secondDistance));
            scratch.quad = (blendPoints(segment[0].quad, segment[1].quad, proportion));
            if (TestTriangleOrientationAndSwapVertices(&scratch, polygon, 0) == 7)
                return 1;
        }
        else
        {
            float d0, d1;
            _mm_store_ss(&d0, firstDistance);
            _mm_store_ss(&d1, secondDistance);
            if (fabsf(d0) > fabsf(d1))
            {
                swapPoints(segment[0], segment[1]);
                swapPoints(segment[4], segment[5]);
            }
            if (TestTriangleOrientationAndSwapVertices(segment, polygon, 1) == 7)
            {
                --*segmentCount;
                return 0;
            }
        }
        scratch.quad = (_mm_sub_ps(segment[1].quad, segment[0].quad));
        SolverOutput sampleB, sampleA;
        hkLineSegmentUtil_closestLineSegLineSeg(segment, &scratch, polygon + 2, &edgeB, &sampleA);
        hkLineSegmentUtil_closestLineSegLineSeg(segment, &scratch, polygon + 2, &edgeA, &sampleB);
        int selection = sampleA.distance > sampleB.distance ? 1 : 0;
        polygon[selection] = polygon[2];
        polygon[selection + 4] = polygon[6];
        --*polygonCount;
        return 2;
    }
    __m128 anchor = polygon[0].quad;
    __m128 normal = faceNormal120;
    __m128 firstDistance = dotThree(_mm_sub_ps(segment[1].quad, anchor), normal);
    __m128 secondDistance = dotThree(_mm_sub_ps(segment[0].quad, anchor), normal);
    AlignedPoint position0 = copyAlignedPoint(reinterpret_cast<const PlainVector&>(reference160));
    if (_mm_movemask_ps(_mm_mul_ss(secondDistance, firstDistance)) & 1)
    {
        __m128 proportion = _mm_div_ss(secondDistance, _mm_sub_ss(secondDistance, firstDistance));
        edgeA.quad = (blendPoints(segment[0].quad, segment[1].quad, proportion));
        if (TestTriangleOrientationAndSwapVertices(&edgeA, polygon, 0) == 7)
            return 1;
    }
    int result = TestTriangleOrientationAndSwapVertices(segment + 1, polygon, 0);
    if (result == 7)
    {
        assignCounted(segment[0], segment[1].quad, segmentCount);
        segment[4] = segment[5];
        lastSegment174 = segmentIndex;
        return 0;
    }
    if (result == 6)
        goto collapse0;
    if (result == 5)
        goto collapse1;
    if (result == 3)
        goto finish;
    if (result == 1)
    {
        float y = position0.quad.m128_f32[1];
        float z = position0.quad.m128_f32[2];
        if (z * (float)(reference160.m128_f32[1] - y) > (float)(reference160.m128_f32[2] - z) * y)
            goto finish;
        goto collapse1;
    }
    if (result == 2)
    {
        float z = position0.quad.m128_f32[2];
        float x = position0.quad.m128_f32[0];
        if (!(x * (float)(reference160.m128_f32[2] - z) > (float)(reference160.m128_f32[0] - x) * z))
            goto finish;
        goto collapse0;
    }
    if (result == 4)
    {
        float x = position0.quad.m128_f32[0];
        float y = position0.quad.m128_f32[1];
        if (y * (float)(reference160.m128_f32[0] - x) > (float)(reference160.m128_f32[1] - y) * x)
            goto collapse1;
    }
collapse0:
    polygon[0] = polygon[2];
    polygon[4] = polygon[6];
finish:
    --*polygonCount;
    return 2;
collapse1:
    __m128 vertex = polygon[2].quad;
    --*polygonCount;
    polygon[1].quad = vertex;
    polygon[5] = polygon[6];
    return 2;
}

extern "C" void _mm_store_ps(float* _V, __m128 _A);
template <class T> struct S00daac40_RayArgument
{
    T value;
    __forceinline operator T() const
    {
        return value;
    }
};
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;

extern "C" unsigned __int64 __rdtsc(void);

struct S00daac40_ProfRec
{
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};

struct S00daac40_ProfBuf
{
    unsigned long unk00;
    S00daac40_ProfRec* m_pCur;
    unsigned long unk08;
    S00daac40_ProfRec* m_pRecordEnd;
};

struct S00daac40_Mat3
{
    hkVector4 r0;
    hkVector4 r1;
    hkVector4 r2;
};

struct S00daac40_RayParams
{
    unsigned long unk00;
    unsigned long unk04;
    // These scalar fields begin at an unaligned offset in the ray parameters.
    float m_x08;
    float m_y0C;
    float m_z10;
    float m_w14;
    unsigned long unk18;
    unsigned long unk1C;
    unsigned long unk20;
    unsigned long unk24;
    unsigned long unk28;
    unsigned long unk2C;
    unsigned long unk30;
    unsigned long unk34;
    unsigned long unk38;
    unsigned long unk3C;
    unsigned long unk40;
    unsigned long unk44;
    unsigned long unk48;
    unsigned long unk4C;
};

class S00daac40_RayCastTarget
{
  public:
    void ProcessEntries_009c1aa0(S00daac40_RayParams* p);
};

class S00daac40_FUN_00daac40_cls
{
  public:
    bool* ProcessAndReturnValue_00daac40(S00daac40_RayArgument<bool*> out, int p2, int p3,
                       S00daac40_RayArgument<S00daac40_RayParams*> p4);
    void ProcessEntries_00da9b30(bool* hit, int p2, int zero, S00daac40_Mat3* m, int p3, S00daac40_RayParams* p);
};

// Records a GJK ray-cast profile tick, runs FUN_00da9b30 with an identity matrix, and sets out true when hit and local.m_z10 is non-zero.
// @fnv 0x00daac40
// src: GUESS 0x00daac40 (confidence: low)
bool* S00daac40_FUN_00daac40_cls::ProcessAndReturnValue_00daac40(S00daac40_RayArgument<bool*> out, int p2, int p3,
                                               S00daac40_RayArgument<S00daac40_RayParams*> apRayParams)
{
    volatile unsigned long ticks;
    __declspec(align(16)) S00daac40_Mat3 m;
    __declspec(align(16)) S00daac40_RayParams rayParams;
    bool hit;

    S00daac40_ProfBuf* pProfBuf = (S00daac40_ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pProfBuf->m_pCur < pProfBuf->m_pRecordEnd)
    {
        S00daac40_ProfRec* pProfRec = pProfBuf->m_pCur;
        pProfRec->m_pName = "TtGJK Ray Cast";
        _ReadWriteBarrier();
        ticks = (unsigned long)__rdtsc();
        pProfRec->m_iTick = ticks;
        pProfBuf->m_pCur = pProfRec + 1;
    }

    rayParams = *apRayParams;
    float one = 1.0f;
    _mm_store_ps((float*)&m.r0, _mm_setzero_ps());
    m.r0.x = one;
    _mm_store_ps((float*)&m.r1, _mm_setzero_ps());
    m.r1.y = one;
    _mm_store_ps((float*)&m.r2, _mm_setzero_ps());
    m.r2.z = one;

    this->ProcessEntries_00da9b30(&hit, p2, 0, &m, p3, &rayParams);

    pProfBuf = (S00daac40_ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pProfBuf->m_pCur < pProfBuf->m_pRecordEnd)
    {
        S00daac40_ProfRec* pProfRec = pProfBuf->m_pCur;
        pProfRec->m_pName = "Et";
        _ReadWriteBarrier();
        ticks = (unsigned long)__rdtsc();
        pProfRec->m_iTick = ticks;
        pProfBuf->m_pCur = pProfRec + 1;
    }

    if (hit && rayParams.m_z10 != 0.0f)
    {
        reinterpret_cast<S00daac40_RayCastTarget*>((S00daac40_RayParams*)apRayParams)->ProcessEntries_009c1aa0(&rayParams);
        bool* destination = out;
        *destination = true;
        return destination;
    }
    bool* destination = out;
    *destination = false;
    return destination;
}
