
// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkQsTransform.h"

extern __m128 DAT_010c71e0;

__forceinline hkQuaternion::hkQuaternion() {}
__forceinline hkQsTransform::hkQsTransform() {}

__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    reinterpret_cast<hkVector4&>(*this) = reinterpret_cast<const hkVector4&>(q);
}

// src: COMMUNITY 0x00c66320
inline __declspec(noinline) void hkQuaternion::setMul(const hkQuaternion& q0, const hkQuaternion& q1)
{
    __m128 a = reinterpret_cast<const hkVector4&>(q0).m_vComponents;
    __m128 b = reinterpret_cast<const hkVector4&>(q1).m_vComponents;
    __m128 cross = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
        _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
    __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
    __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
    __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
    __m128 prod = _mm_mul_ps(b, a);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                            _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
    __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
    reinterpret_cast<hkVector4&>(*this).m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
}

__forceinline void hkQsTransform::operator=(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}

__forceinline void hkVector4::addMul4(__m128 s, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
}

__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& v) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    return hkSimdReal(_mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum));
}

__forceinline hkSimdReal::hkSimdReal(const __m128& v)
{
    m_vValue = v;
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    const hkVector4& imag = reinterpret_cast<const hkVector4&>(quat);
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(imag.m_vComponents, imag.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = imag.dot3(direction).m_vValue;
    ret.addMul4(imagDotDir, imag);
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(imag, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkQsTransform::SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    // The original call targets hkQuaternion's product implementation at 0x00c66320.
    m_rotation.setMul(t1.m_rotation, t2.m_rotation);
    m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
}

class FUN_00e401d0Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iNumTracks;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    hkQsTransform* m_pkTransforms;
    int m_iNumTransforms;

    void ProcessEntries_00e401d0(int iTrack, const hkQsTransform& kTransform);
};

// @fnv 0x00e401d0
// src: GUESS 0x00e401d0 (confidence: low)
void FUN_00e401d0Owner::ProcessEntries_00e401d0(int iTrack, const hkQsTransform& kTransform)
{
    int iTransformCountPerTrack = m_iNumTransforms / m_iNumTracks;
    for (int i = 0; i < iTransformCountPerTrack; i++)
    {
        int iIndex = m_iNumTracks * i + iTrack;
        hkQsTransform kOld;
        kOld = m_pkTransforms[iIndex];
        m_pkTransforms[iIndex].SetProduct(kTransform, kOld);
    }
}
