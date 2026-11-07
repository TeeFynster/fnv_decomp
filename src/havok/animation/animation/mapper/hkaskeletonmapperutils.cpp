#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
// Keep the original SIMD lane layout: VC9's CRT adds byte arrays that
// change /GS parameter handling for functions with vector locals.
#define _INCLUDED_MM2
// Exe 0x00ce55d0 FUN_00ce55d0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C"
{
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sqrt_ss(LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    void _mm_store_ss(float*, LocalM128);
}


// src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapperutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkQsTransform.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkMemoryRouter.h"

void __cdecl hkaSkeletonMapperUtils_computeMappingTransform(hkQsTransform* out, const hkQsTransform* a, const hkQsTransform* b, int mode,
                          float weightA, float weightB);

// @fnv 0x00ce5f90
// src: HAVOK_LIB 0x00ce5f90
void __cdecl hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(hkQsTransform* out, const hkQsTransform* poseA, short boneA,
                          const hkQsTransform* poseB, short boneB, int mode, float weightA, float weightB)
{
    hkaSkeletonMapperUtils_computeMappingTransform(out, &poseA[boneA], &poseB[boneB], mode, weightA, weightB);
}

#include <xmmintrin.h>
extern const float DAT_0104da48;
extern const float DAT_0104e148;

struct __declspec(align(16)) VertexRecord
{
    LocalM128 m_kPathOffset;
    int m_ai10;
    int m_ai14;
    int m_ai18;
    int m_ai1c;
    int m_ai20;
    int m_ai24;
    int m_ai28;
    int m_ai2c;
};

// Computes the min and max of m_kPathOffset across aiCount VertexRecord entries, storing results in apMin and apMax.
// @fnv 0x00ce5560
// src: GUESS 0x00ce5560 (confidence: medium)
void __cdecl Object_GetPathOffsetBounds(const VertexRecord* apVertices, int aiCount, LocalM128* apMin, LocalM128* apMax)
{
    *apMin = _mm_set_ps1(DAT_0104da48);
    *apMax = _mm_set_ps1(DAT_0104e148);

    for (int i = 0; i < aiCount; i++)
    {
        LocalM128 kForMin = apVertices[i].m_kPathOffset;
        *apMin = _mm_min_ps(*apMin, kForMin);
        LocalM128 kForMax = apVertices[i].m_kPathOffset;
        *apMax = _mm_max_ps(*apMax, kForMax);
    }
}

__forceinline hkQuaternion::hkQuaternion() {}



__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void hkVector4::SetAllComponents(float r)
{
    m_vComponents = _mm_set_ps1(r);
}

__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline hkSimdReal::hkSimdReal(const LocalM128& v)
{
    m_vValue = v;
}

__forceinline hkSimdReal::operator float() const
{
    float r;
    _mm_store_ss(&r, m_vValue);
    return r;
}

__forceinline hkSimdReal hkVector4::length3() const
{
    LocalM128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    return hkSimdReal(_mm_sqrt_ss(len2));
}

__forceinline void hkVector4::normalize3()
{
    LocalM128 p = _mm_mul_ps(m_vComponents, m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                          _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
}

namespace fnv_00ce55d0 {
typedef float hkReal;

extern LocalM128 DAT_010c71b0;

static __forceinline void setIdentity(hkQsTransform& t)
{
    t.m_vTranslation.setZero4();
    *reinterpret_cast<LocalM128*>(&t.m_rotation) = DAT_010c71b0;
    t.m_vScale.SetAllComponents(1.0f);
}

struct ScaleParams
{
    int m_iValueAfterFlags;
    int m_sBoneA;
    int m_sBoneB;
    hkReal m_scaleA;
    hkReal m_scaleB;
};

void __cdecl Object_GetPathOffsetBounds(const hkQsTransform* pose, int numBones, hkVector4& minOut, hkVector4& maxOut);

// Computes scale factors for two poses based on ScaleParams mode, storing results in outA and outB.
// @fnv 0x00ce55d0
// src: GUESS 0x00ce55d0 (confidence: medium)
void __cdecl hkQsTransform_ComputePoseScaleFactors(const ScaleParams* params, int unused, const hkQsTransform* poseA, int numBonesA,
                          const hkQsTransform* poseB, int numBonesB, hkQsTransform* outA, hkQsTransform* outB)
{
    setIdentity(*outA);
    setIdentity(*outB);

    if (params->m_iValueAfterFlags == 0)
    {
        hkVector4 minA, maxA, minB, maxB;
        Object_GetPathOffsetBounds(poseA, numBonesA, minA, maxA);
        Object_GetPathOffsetBounds(poseB, numBonesB, minB, maxB);
        hkVector4 extA;
        extA.setSub4(maxA, minA);
        hkVector4 extB;
        extB.setSub4(maxB, minB);
        hkReal lenA = extA.length3();
        hkReal lenB = extB.length3();
        hkReal fScaleA = lenB / lenA * params->m_scaleB / params->m_scaleA;
        hkReal fScaleB = lenA / lenB * params->m_scaleA / params->m_scaleB;
        outA->m_vScale.SetAllComponents(fScaleA);
        outB->m_vScale.SetAllComponents(fScaleB);
    }
    else if (params->m_iValueAfterFlags == 1)
    {
        hkReal lenA = poseA[params->m_sBoneA].m_vTranslation.length3();
        hkReal lenB = poseB[params->m_sBoneB].m_vTranslation.length3();
        hkReal fScaleA = lenB / lenA * params->m_scaleB / params->m_scaleA;
        hkReal fScaleB = lenA / lenB * params->m_scaleA / params->m_scaleB;
        outA->m_vScale.SetAllComponents(fScaleA);
        outB->m_vScale.SetAllComponents(fScaleB);
    }
    else
    {
        outA->m_vScale.SetAllComponents(params->m_scaleB / params->m_scaleA);
        outB->m_vScale.SetAllComponents(params->m_scaleA / params->m_scaleB);
    }
}
}  // namespace fnv_00ce55d0

#include <math.h>
struct ThresholdState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float threshold;
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
    int mode;
};

struct ValueSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

extern "C" float __cdecl GetAngle();
typedef float(__thiscall* ReadValue)(void*);

// Returns 1 if state->mode is not 1, otherwise returns whether the larger absolute angle of first or second is at most state->threshold.
// @fnv 0x00ce57c0
// src: HAVOK_LIB 0x00ce57c0
unsigned char __cdecl hkaSkeletonMapperUtils_checkRotation(ThresholdState* state, void* unused1, void* unused2, ValueSource* first,
                                   ValueSource* second)
{
    if (state->mode != 1)
        return 1;

    float a = fabs(reinterpret_cast<ReadValue>(GetAngle)(reinterpret_cast<char*>(first) + 0x10));
    float b = fabs(reinterpret_cast<ReadValue>(GetAngle)(reinterpret_cast<char*>(second) + 0x10));
    float fMaxAngle = a > b ? a : b;
    return static_cast<unsigned char>(fMaxAngle <= state->threshold);
}

namespace fnv_00ce5e60 {
typedef float hkReal;
typedef short hkInt16;

struct hkaSkeletonq
{
    int m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    const char* m_name;
    hkInt16* m_kParentIndices;
};

extern hkVector4 DAT_010c71e0;

static __forceinline LocalM128 hkDot3v(LocalM128 a, LocalM128 b)
{
    LocalM128 x2 = _mm_mul_ps(a, b);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy);
}

static __forceinline LocalM128 hkCross(LocalM128 a, LocalM128 b)
{
    LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}

static __forceinline void hkSetRotatedDir(hkVector4& out, const hkVector4& quat, const hkVector4& dir)
{
    LocalM128 q = quat.m_vComponents;
    LocalM128 d = dir.m_vComponents;
    LocalM128 qreal = _mm_shuffle_ps(q, q, 0xff);
    LocalM128 q2minus1 = _mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0.m_vComponents);
    LocalM128 ret = _mm_mul_ps(d, q2minus1);
    LocalM128 imagDotDir = hkDot3v(quat.m_vComponents, dir.m_vComponents);
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), q));
    LocalM128 imagCrossDir = hkCross(q, d);
    ret = _mm_add_ps(ret, _mm_mul_ps(imagCrossDir, qreal));
    out.m_vComponents = _mm_add_ps(ret, ret);
}

static __forceinline hkReal hkLength3(const hkVector4& v)
{
    LocalM128 l2 = hkDot3v(v.m_vComponents, v.m_vComponents);
    hkReal r;
    _mm_store_ss(&r, _mm_sqrt_ss(l2));
    return r;
}

// Walks the parent chain from bone to ancestor, rotating the accumulated position, adding translations, and summing their lengths.
// @fnv 0x00ce5e60
// src: GUESS 0x00ce5e60 (confidence: medium)
void Object_AccumulateBoneChainLength(const hkaSkeletonq* apSkeleton, const hkQsTransform* poses, hkInt16 ancestor, hkInt16 bone,
                  hkReal* pfLengthOut, hkVector4* posOut)
{
    *pfLengthOut = 0.0f;
    posOut->m_vComponents = _mm_setzero_ps();
    for (hkInt16 b = bone; b > ancestor; b = apSkeleton->m_kParentIndices[b])
    {
        const hkQsTransform& t = poses[b];
        hkVector4 tmp;
        // Copy the four lanes as words, preserving their bits and the original scalar copy.
        reinterpret_cast<unsigned int*>(tmp.m_f)[0] = reinterpret_cast<const unsigned int*>(posOut->m_f)[0];
        reinterpret_cast<unsigned int*>(tmp.m_f)[1] = reinterpret_cast<const unsigned int*>(posOut->m_f)[1];
        reinterpret_cast<unsigned int*>(tmp.m_f)[2] = reinterpret_cast<const unsigned int*>(posOut->m_f)[2];
        reinterpret_cast<unsigned int*>(tmp.m_f)[3] = reinterpret_cast<const unsigned int*>(posOut->m_f)[3];
        hkSetRotatedDir(*posOut, reinterpret_cast<const hkVector4&>(t.m_rotation), tmp);
        posOut->m_vComponents = _mm_add_ps(posOut->m_vComponents, t.m_vTranslation.m_vComponents);
        *pfLengthOut += hkLength3(t.m_vTranslation);
    }
}
}  // namespace fnv_00ce5e60

class hkaSkeleton;
namespace fnv_00ce5fe0 {
typedef float hkReal;
typedef short hkInt16;


struct BonePairInfo
{
    hkInt16 m_boneA0;
    hkInt16 m_boneA1;
    hkInt16 m_boneB0;
    hkInt16 m_boneB1;
    int unk08;
    int unk0C;
    hkVector4 m_offset;
    hkVector4 unk20;
    hkVector4 unk30;
    hkQuaternion m_rotation;
    hkQuaternion m_relRotation;
    hkVector4 m_vScale;
};

void hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(const void* data, const hkQsTransform* poseA, hkInt16 boneA, const hkQsTransform* poseB,
                  hkInt16 boneB, hkVector4* out, hkReal eps, hkReal weight);
void Object_AccumulateBoneChainLength(const hkaSkeleton* skel, const hkQsTransform* poses, hkInt16 ancestor, hkInt16 bone,
                  hkReal* lengthOut, hkVector4* posOut);

// Fills out with bone indices, offset, rotation, scale, and relative rotation derived from two skeleton bone pairs.
// @fnv 0x00ce5fe0
// src: GUESS 0x00ce5fe0 (confidence: medium)
void Object_BuildBonePairMapping(const void* data, const hkaSkeleton* skelA, const hkQsTransform* poseA, hkInt16 boneA0,
                  hkInt16 boneA1, const hkaSkeleton* skelB, const hkQsTransform* poseB, hkInt16 boneB0, hkInt16 boneB1,
                  BonePairInfo* out)
{
    out->m_boneA0 = boneA0;
    out->m_boneA1 = boneA1;
    out->m_boneB0 = boneB0;
    out->m_boneB1 = boneB1;
    hkaSkeletonMapperUtils_computeMappingTransform_00ce5f90(data, poseA, boneA0, poseB, boneB0, &out->m_offset, 1e-5f, 1.0f);

    hkReal lenA;
    hkReal lenB;
    hkVector4 dirA;
    hkVector4 dirB;
    Object_AccumulateBoneChainLength(skelA, poseA, boneA0, boneA1, &lenA, &dirA);
    Object_AccumulateBoneChainLength(skelB, poseB, boneB0, boneB1, &lenB, &dirB);

    dirA.normalize3();
    dirB.normalize3();

    __declspec(align(16)) hkQuaternion rot;
    rot.ComputeValues_00cd9d10(dirB, dirA);
    *reinterpret_cast<LocalM128*>(&out->m_rotation) = *reinterpret_cast<const LocalM128*>(&rot);
    lenA = 1.0f / lenA;
    out->m_vScale.m_vComponents = _mm_set_ps1(lenA);
    out->m_relRotation.hkQuaternion_setInverseMul(poseA[boneA1].m_rotation, poseB[boneB1].m_rotation);
}
}  // namespace fnv_00ce5fe0

typedef unsigned int size_t;

inline void* operator new(size_t, void* p)
{
    return p;
}

// hkMemoryRouter is the shared router: GetMonitorStream binds to 0x00c85750, with the heap at +0x10.
extern "C" void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* mem, void* array, int numElems, int elemSize);

struct HkElem8
{
    int a;
    int b;
};

template <typename T> struct HkArrayLocalForm
{ // local form of hkArray: 0x00ce9580 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HkArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            dst[i] = src[i];
        }
    }

    __forceinline void constructWithCopy(T* dst, int n, const T* src)
    {
        for (int i = 0; i < n; i++)
        {
            new (dst + i) T(src[i]);
        }
    }

    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newCap = n < cap2 ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline void copyFromArray(hkMemoryAllocator& alloc, const HkArrayLocalForm& a)
    {
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        copy(m_data, a.m_data, copiedSize);
        constructWithCopy(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline HkArrayLocalForm& operator=(const HkArrayLocalForm& other)
    {
        copyFromArray(hkMemoryRouter::getInstance().heap(), other);
        return *this;
    }
};

struct FUN_00ce9580
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    float unk10;
    HkArrayLocalForm<HkElem8> arr14;
    HkArrayLocalForm<HkElem8> arr20;
    HkArrayLocalForm<HkElem8> arr2C;
    char unk38;
    char unk39;
    struct Tail
    {
        int unk3C;
        int unk40;
        int unk44;
        int unk48;
        int unk4C;
        int unk50;
    } tail;

    FUN_00ce9580(const FUN_00ce9580& other);
};

// Copies scalar fields and tail from other, then deep-copies the three HkArrayLocalForm<HkElem8> members via their operator=.
// @fnv 0x00ce9580
FUN_00ce9580::FUN_00ce9580(const FUN_00ce9580& other)
    : unk00(other.unk00), unk04(other.unk04), unk08(other.unk08), unk0C(other.unk0C), unk10(other.unk10), arr14(),
      arr20(), arr2C(), unk38(other.unk38), unk39(other.unk39), tail(other.tail)
{
    arr14 = other.arr14;
    arr20 = other.arr20;
    arr2C = other.arr2C;
}
