// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkQsTransform.h"
#include "../../../../../../include/hkaInterleavedUncompressedAnimation.h"

extern const __m128 DAT_010c7160;
extern const __m128 DAT_010ec7f0;

__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}
__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
__forceinline hkSimdReal::hkSimdReal()
{}
__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline const __m128& hkSimdReal::getQuad() const
{
    return m_vValue;
}

inline hkSimdReal operator-(const hkSimdReal& r)
{
    return _mm_sub_ss(DAT_010c7160, r.getQuad());
}

__forceinline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, const hkSimdReal& _t)
{
    __m128 t = _t.broadcast();
    __m128 s = _mm_sub_ps(DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(v1.m_vComponents, t));
}
inline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
    __m128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
    return _mm_add_ps(sum0, sum1);
}

inline hkQuaternion::hkQuaternion()
{}
inline void hkQuaternion::operator=(const hkQuaternion& q)
{
    reinterpret_cast<hkVector4&>(*this) = reinterpret_cast<const hkVector4&>(q);
}

__forceinline hkQsTransform::hkQsTransform(const hkQsTransform& t)
{
    m_vTranslation = t.m_vTranslation;
    m_rotation = t.m_rotation;
    m_vScale = t.m_vScale;
}
__forceinline void hkQsTransform::setInterpolate4(const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t)
{
    const __m128 ts = t.broadcast();
    m_vScale.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, ts), a.m_vScale.m_vComponents),
                                        _mm_mul_ps(ts, b.m_vScale.m_vComponents));
    m_vTranslation.setInterpolate4(a.m_vTranslation, b.m_vTranslation, t);

    const float oneMinusT = 1.0f - float(t);

    const float signedT = (reinterpret_cast<const hkVector4&>(a.m_rotation).dot4(
                              reinterpret_cast<const hkVector4&>(b.m_rotation)) < 0.0f) ? -t : t;

    __declspec(align(16)) hkQuaternion out;
    hkVector4 v;
    v.setMul4(hkSimdReal(signedT), reinterpret_cast<const hkVector4&>(b.m_rotation));
    v.addMul4(hkSimdReal(oneMinusT), reinterpret_cast<const hkVector4&>(a.m_rotation));
    reinterpret_cast<hkVector4&>(out) = v;
    out.normalize_005611c0();

    m_rotation = out;
}

struct S00e3f9b0_Anim : public hkaInterleavedUncompressedAnimation
{
    void hkaAnimation_getFrameAndDelta(float time, int& frame, float& delta) const;
    void hkaInterleavedUncompressedAnimation_sampleIndividualTransformTracks(float time, const short* tracks, unsigned int numTracks, hkQsTransform* transformsOut) const;
};

// @fnv 0x00e3f9b0
// src: HAVOK_SRC 0x00e3f9b0
void S00e3f9b0_Anim::hkaInterleavedUncompressedAnimation_sampleIndividualTransformTracks(float time, const short* tracks, unsigned int numTracks,
                                  hkQsTransform* transformsOut) const
{
    int frame;
    float delta;
    hkaAnimation_getFrameAndDelta(time, frame, delta);

    for (unsigned int i = 0; i < numTracks; ++i)
    {
        const short track = tracks[i];
        if (track < 0)
        {
            continue;
        }
        const int trackIndex = track;
        const int transformTrackCount = m_iNumTransformTracks;
        if (trackIndex >= transformTrackCount)
        {
            continue;
        }
        const hkQsTransform* base = m_kTransforms.m_data + transformTrackCount * frame;
        hkQsTransform a = base[trackIndex];
        hkQsTransform b = base[trackIndex + transformTrackCount];
        transformsOut[i].setInterpolate4(a, b, delta);
    }
}
