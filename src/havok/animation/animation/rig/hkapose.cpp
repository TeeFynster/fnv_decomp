#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form

// src/havok/animation/animation/rig/hkapose.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkapose.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Retain the original intrinsic layout: the CRT's extra __m128 byte arrays
// change VC9's stack-slot ordering. This unit supplies its required intrinsics.
#define _INCLUDED_MM2
// Exe 0x00cda180 FUN_00cda180: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}

#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkQsTransform.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkaSkeleton.h"

typedef short hkInt16;
typedef unsigned int hkUint32;

extern "C" LocalM128 DAT_010c71e0;

__forceinline hkSimdReal::hkSimdReal()
{
}


__forceinline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}
__forceinline void hkVector4::addMul4(const hkSimdReal& s, const hkVector4& b)
{
    m_vComponents =
        _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), b.m_vComponents));
}
__forceinline void hkVector4::setBroadcast3(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    const LocalM128 z = _mm_shuffle_ps(x2, x2, 0xaa);
    hkSimdReal r;
    r.m_vValue = _mm_add_ss(z, xySum);
    return r;
}
__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    *reinterpret_cast<hkVector4*>(this) = *reinterpret_cast<const hkVector4*>(&q);
}

__forceinline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(this);
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.setBroadcast3(quat.getImag());
    hkVector4 q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    hkSimdReal imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    setAdd4(ret, ret);
}

__forceinline void hkQsTransform::operator=(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}

__forceinline void hkQsTransform::SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 rotated;
    rotated.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(rotated, t1.m_vTranslation);
    m_rotation.setMul(t1.m_rotation, t2.m_rotation);
    m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
}

template <class T> __forceinline T& arrayElement(hkArray<T>& a, int i)
{
    return a.m_data[i];
}
template <class T> __forceinline const T& arrayElement(const hkArray<T>& a, int i)
{
    return a.m_data[i];
}
struct SkeletonPoseData
{
    enum
    {
        F_BONE_MODEL_DIRTY = 0x2,
        F_BONE_INTERNAL_FLAG1 = 0x8
    };
    const hkaSkeleton* m_pSkeleton;
    hkArray<hkQsTransform> m_pLocalPose;
    hkArray<hkQsTransform> m_pModelPose;
    hkArray<hkUint32> m_pBoneFlags;
    __forceinline int isFlagOn(int i, hkUint32 f) const
    {
        return arrayElement(m_pBoneFlags, i) & f;
    }
    __forceinline void setFlag(int i, hkUint32 f)
    {
        arrayElement(m_pBoneFlags, i) |= f;
    }
    __forceinline void clearFlag(int i, hkUint32 f)
    {
        arrayElement(m_pBoneFlags, i) &= ~f;
    }
    const hkQsTransform& hkaPose_calculateBoneModelSpace(int boneIdx);
};

// @fnv 0x00cda180
// src: COMMUNITY 0x00cda180
const hkQsTransform& SkeletonPoseData::hkaPose_calculateBoneModelSpace(int boneIdx)
{
    int ancestorIdx = boneIdx;
    while (isFlagOn(ancestorIdx, F_BONE_MODEL_DIRTY))
    {
        const hkInt16 parentIdx = arrayElement(m_pSkeleton->m_kParentIndices, ancestorIdx);
        if (parentIdx == -1)
        {
            arrayElement(m_pModelPose, ancestorIdx) = arrayElement(m_pLocalPose, ancestorIdx);
            clearFlag(ancestorIdx, F_BONE_MODEL_DIRTY);
            break;
        }
        setFlag(ancestorIdx, F_BONE_INTERNAL_FLAG1);
        ancestorIdx = parentIdx;
    }

    for (int i = ancestorIdx + 1; i <= boneIdx; ++i)
    {
        if (isFlagOn(i, F_BONE_INTERNAL_FLAG1))
        {
            const hkInt16 parentIdx = arrayElement(m_pSkeleton->m_kParentIndices, i);
            arrayElement(m_pModelPose, i).SetProduct(arrayElement(m_pModelPose, parentIdx), arrayElement(m_pLocalPose, i));
            clearFlag(i, F_BONE_MODEL_DIRTY | F_BONE_INTERNAL_FLAG1);
        }
    }
    return arrayElement(m_pModelPose, boneIdx);
}
