#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form

// src/fallout/ai/actor_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/fallout/ai/actor.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "Actor.h"
#include "../../../include/hkSimdReal.h"
#include "../../../include/hkVector4.h"
#include "../../../include/hkQsTransform.h"
#include "../../../include/hkQuaternion.h"
#include "../../../include/hkaSkeleton.h"

#include <xmmintrin.h>
extern const __m128 DAT_010c71e0;


__forceinline hkSimdReal::hkSimdReal(const __m128& value)
{
    m_vValue = value;
}

__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::addMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline void hkVector4::setBroadcast3(const hkVector4& v)
{
    m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return hkSimdReal(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    const hkVector4& imag = reinterpret_cast<const hkVector4&>(quat);
    qreal.setBroadcast3(imag);
    hkVector4 q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(q2minus1, direction);
    hkVector4 imagDotDir;
    imagDotDir.m_vComponents = imag.dot3(direction).m_vValue;
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(imag, direction);
    ret.addMul4(imagDotDir, imag);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

// @fnv 0x00c7f7a0
void hkVector4::SetTransformedPoint(const hkQsTransform& a, const hkVector4& b)
{
    hkVector4 scaled;
    scaled.setMul4(a.m_vScale, b);
    SetRotatedDirection(a.m_rotation, scaled);
    setAdd4(a.m_vTranslation, *this);
}

namespace fnv_00cda340 {
extern hkVector4 DAT_010c71e0;

__forceinline void SetRotatedDirection(hkVector4& out, const hkQuaternion& quat, const hkVector4& direction)
{
    const hkVector4& imag = reinterpret_cast<const hkVector4&>(quat);
    const __m128 q = imag.m_vComponents;
    const __m128 d = direction.m_vComponents;
    __m128 qreal = _mm_shuffle_ps(q, q, 0xff);
    __m128 ret = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0.m_vComponents), d);
    const __m128 imagDotDir = imag.dot3(direction).m_vValue;
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), q));
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(d, d, 0xd2), _mm_shuffle_ps(q, q, 0xc9)),
                              _mm_mul_ps(_mm_shuffle_ps(d, d, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    ret = _mm_add_ps(ret, _mm_mul_ps(qreal, cross));
    out.m_vComponents = _mm_add_ps(ret, ret);
}

struct SkeletonPoseData
{
    hkaSkeleton* m_pSkeleton;
    hkQsTransform* m_pLocalPose;
    int m_localPoseSize;
    int m_localPoseCapacity;
    hkQsTransform* m_pModelPose;
    int m_modelPoseSize;
    int m_modelPoseCapacity;
    unsigned int* m_pBoneFlags;
    int m_boneFlagsSize;
    int m_boneFlagsCapacity;
    bool m_bPoseFlag;

    void hkaPose_syncModelSpace();
};

// @fnv 0x00cda340
// src: COMMUNITY 0x00cda340
void SkeletonPoseData::hkaPose_syncModelSpace()
{
    if (m_bPoseFlag)
        return;

    const int numBones = m_pSkeleton->m_kBones.m_iElementCount;
    for (int b = 0; b < numBones; b++)
    {
        if (m_pBoneFlags[b] & 2)
        {
            const short parentId = m_pSkeleton->m_kParentIndices.m_data[b];
            const hkQsTransform& local = m_pLocalPose[b];
            if (parentId != -1)
            {
                const hkQsTransform& parent = m_pModelPose[parentId];
                hkQsTransform& out = m_pModelPose[b];
                hkVector4 t;
                SetRotatedDirection(t, parent.m_rotation, local.m_vTranslation);
                out.m_vTranslation.m_vComponents = _mm_add_ps(t.m_vComponents, parent.m_vTranslation.m_vComponents);
                out.m_rotation.SetProduct(parent.m_rotation, local.m_rotation);
                out.m_vScale.m_vComponents = _mm_mul_ps(parent.m_vScale.m_vComponents, local.m_vScale.m_vComponents);
            }
            else
            {
                hkQsTransform& out = m_pModelPose[b];
                out.m_vTranslation.m_vComponents = local.m_vTranslation.m_vComponents;
                *reinterpret_cast<__m128*>(&out.m_rotation) = *reinterpret_cast<const __m128*>(&local.m_rotation);
                out.m_vScale.m_vComponents = local.m_vScale.m_vComponents;
            }
            m_pBoneFlags[b] &= ~2u;
        }
    }
    m_bPoseFlag = true;
}
}  // namespace fnv_00cda340
