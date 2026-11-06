#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's original SSE intrinsic representation. The SDK's extra byte
// arrays change VC9's /GS analysis even though they have the same layout.
#define _INCLUDED_MM2
// Exe 0x00db15a0 TestEdgeEdgeContact: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkBool.h"

// RemoveValueAt - drops slot <index> of the eight-slot table held by
// FUN_00db0920: the last slot in use is moved into the hole and the used-slot
// counter goes down by one.
struct FUN_00db0920
{
    int values[8];        // +0x00: eight four-byte slots, low half holds the key
    unsigned char unk20;  // +0x20
    unsigned char count;  // +0x21: number of slots in use
    unsigned char flag;   // +0x22
    void RemoveValueAt(int index);
};

// @fnv 0x00db0900
void FUN_00db0920::RemoveValueAt(int index)
{
    // Stored through an alias on purpose: with a direct member store the
    // compiler hoists the count load above the store, the original does not.
    unsigned char* pFlag = &flag;
    *pFlag = 0;
    values[index] = values[count - 1];
    count--;
}

extern "C"
{
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}

extern "C"
{
    double __cdecl fabs(double _X);
}
extern "C++"
{
    inline float __cdecl fabs(float _X)
    {
        return ((float)fabs((double)(_X)));
    }
}



inline LocalM128& hkVector4::q()
{
    return m_vComponents;
}

inline const LocalM128& hkVector4::q() const
{
    return m_vComponents;
}

inline void hkVector4::set(LocalM128 v)
{
    m_vComponents = v;
}

inline float& hkVector4::operator()(int i)
{
    return reinterpret_cast<float*>(this)[i];
}

inline const float& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const float*>(this)[i];
}

struct BoxBoxEdgeContact
{
    hkVector4 m_vContactPosition;                  // 0x00
    hkVector4 unk10;                       // 0x10
    hkVector4 m_vHitNormal;                    // 0x20
    float unk30;                           // 0x30
    float m_fClosestPointDistanceSquared;  // 0x34
    int m_featureA;                        // 0x38
    int m_featureB;                        // 0x3c
};

extern const hkVector4 g_boxVertexSigns[8];
extern const LocalM128 g_negateMask;

struct BoxBoxCollisionDetection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_rotation[3];        // 0x20
    hkVector4 m_vTranslation;       // 0x50
    hkVector4 m_kBoxBasisVector;            // 0x60
    hkVector4 m_kThirdBasisVector;  // 0x70
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unkA0;
    float m_fScalar;          // 0xb0
    float m_minNormalLength;  // 0xb4

    hkBool TestEdgeEdgeContact(BoxBoxEdgeContact* contact);
};

static __forceinline LocalM128 splat(const float& f)
{
    return _mm_set_ps1(f);
}

// feature ids keep the vertex sign bits pre-scaled to a byte offset into the sign table
static __forceinline const hkVector4& boxVertexSign(int byteOffset)
{
    return *reinterpret_cast<const hkVector4*>(reinterpret_cast<const char*>(g_boxVertexSigns) + byteOffset);
}

static inline float hkFabs(float r)
{
    return fabs(r);
}

static __forceinline LocalM128 dot3v(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
}

static __forceinline float toReal(LocalM128 v)
{
    float r;
    _mm_store_ss(&r, v);
    return r;
}

static __forceinline float dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}

// Tests edge-edge contact between two boxes, computing closest points, normal.q(), and distance, returning true if a valid contact is found.
// @fnv 0x00db15a0
hkBool BoxBoxCollisionDetection::TestEdgeEdgeContact(BoxBoxEdgeContact* contact)
{
    int axisA = contact->m_featureA & 0xf;
    hkVector4 vertexSignA;
    vertexSignA.set(boxVertexSign((unsigned short)contact->m_featureA & 0x70).q());
    hkVector4 vertexA;
    vertexA.set(_mm_mul_ps(m_kBoxBasisVector.q(), vertexSignA.q()));
    int axisB = contact->m_featureB & 0xf;
    float edgeLenB = m_kThirdBasisVector(axisB) + m_kThirdBasisVector(axisB);
    LocalM128 vertexBLocal =
        _mm_mul_ps(boxVertexSign((unsigned short)contact->m_featureB & 0x70).q(), m_kThirdBasisVector.q());
    hkVector4 edgeB;
    edgeB.set(_mm_mul_ps(splat(edgeLenB), m_rotation[axisB].q()));
    float edgeLenA = (float)(m_kBoxBasisVector(axisA) * -2.0);

    LocalM128 vertexB =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(vertexBLocal, vertexBLocal, 0x55), m_rotation[1].q()),
                              _mm_mul_ps(_mm_shuffle_ps(vertexBLocal, vertexBLocal, 0x00), m_rotation[0].q())),
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(vertexBLocal, vertexBLocal, 0xaa), m_rotation[2].q()),
                              m_vTranslation.q()));
    hkVector4 diff;
    diff.set(_mm_sub_ps(vertexB, vertexA.q()));

    float ab = edgeB(axisA) * edgeLenA;
    float bb = (float)(m_kThirdBasisVector(axisB) * m_kThirdBasisVector(axisB) * 4.0);
    float aa = edgeLenA * edgeLenA;
    float db = dot3(diff.q(), edgeB.q());
    float denom = bb * aa - ab * ab;
    float absDenom = hkFabs(denom);
    float da = diff(axisA) * edgeLenA;
    float t = da * bb - db * ab;

    if (t <= (float)(absDenom * 1.1920928955078125e-07) || t >= absDenom * 0.99999988079071044921875)
        return hkBool(false);
    t = t / absDenom;
    float u = t * ab - db;
    if (u <= bb * 1.1920928955078125e-07 || u >= (float)(bb * 0.99999988079071044921875))
        return hkBool(false);

    vertexA(axisA) = t * edgeLenA + vertexA(axisA);
    hkVector4 edgeA;
    edgeA.set(_mm_setzero_ps());
    edgeA(axisA) = (float)(edgeLenA * 0.5);

    const LocalM128 cross0 =
        _mm_mul_ps(_mm_shuffle_ps(edgeA.q(), edgeA.q(), 0xc9), _mm_shuffle_ps(edgeB.q(), edgeB.q(), 0xd2));
    const LocalM128 cross1 =
        _mm_mul_ps(_mm_shuffle_ps(edgeA.q(), edgeA.q(), 0xd2), _mm_shuffle_ps(edgeB.q(), edgeB.q(), 0xc9));
    LocalM128 cross = _mm_sub_ps(cross0, cross1);

    LocalM128 sq = _mm_mul_ps(cross, cross);
    LocalM128 lenSq = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    LocalM128 r = _mm_rsqrt_ss(lenSq);
    LocalM128 isZero = _mm_cmpeq_ss(lenSq, _mm_set_ss(0.0f));
    LocalM128 nr =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(lenSq, r), r)));
    LocalM128 invLen = _mm_andnot_ps(isZero, nr);
    invLen = _mm_shuffle_ps(invLen, invLen, 0);
    hkVector4 normal;
    normal.set(_mm_mul_ps(invLen, cross));
    LocalM128 sq2 = _mm_mul_ps(cross, cross);
    LocalM128 len =
        _mm_mul_ss(_mm_add_ss(_mm_shuffle_ps(sq2, sq2, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq2, sq2, 0x55), sq2)), invLen);
    float length;
    _mm_store_ss(&length, len);

    if (length < m_minNormalLength)
        return hkBool(false);

    if (dot3(_mm_load_ps(reinterpret_cast<const float*>(&vertexSignA)), normal.q()) < 0.0f)
        normal.set(_mm_xor_ps(normal.q(), g_negateMask));

    float dist = dot3(normal.q(), diff.q());
    if (dist > m_fScalar)
        return hkBool(false);

    contact->m_vContactPosition.set(vertexA.q());
    contact->m_vHitNormal.set(_mm_xor_ps(normal.q(), g_negateMask));
    contact->m_fClosestPointDistanceSquared = dist;
    return hkBool(true);
}
