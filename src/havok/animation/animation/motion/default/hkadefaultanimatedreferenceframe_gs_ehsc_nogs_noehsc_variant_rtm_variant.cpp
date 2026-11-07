#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkTransform.h"
#include <string.h>
#include "../../../../../../include/hkSimdReal.h"

inline hkSimdReal::hkSimdReal(const __m128& v) : value(v)
{}

inline const __m128& hkSimdReal::getQuad() const
{
    return value;
}

// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00e41080_Obj
{
    int unk00;
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
    float unk30;

    float __thiscall GetUnk30();
};
#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);
template <class T, class U> __forceinline void fnv_vstore(T& d, U v)
{
    *(volatile T*)&d = (T)v;
}
struct __declspec(align(16)) Projection363_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char flag10;
    unsigned char flag11;
    unsigned char flag12;
    unsigned char flag13;
    int unk14;
    int unk18;
    int unk1C;
    __m128 vec20;
    __m128 vec30;
};
struct Projection363_Input
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};
__forceinline __m128 Dot363(const __m128& a, const __m128& b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 p = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 q = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), p);
    return _mm_shuffle_ps(q, q, 0);
}
__forceinline __m128 Project363(const __m128& v, const __m128& axis)
{
    return _mm_mul_ps(Dot363(v, axis), axis);
}
__forceinline __m128 Cross363(const __m128& v1, const __m128& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xc9), _mm_shuffle_ps(v2, v2, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xd2), _mm_shuffle_ps(v2, v2, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
struct Motion363
{
    __m128 vector;
    hkQuaternion angular;
};
void hkaDefaultAnimatedReferenceFrame_project(Projection363_Owner* a, Motion363* __restrict b, Projection363_Input* c, hkVector4* out);
inline hkVector4::hkVector4(const hkVector4& a)
{
    memcpy(m_f, a.m_f, sizeof(m_f));
}
inline void hkVector4::operator=(const hkVector4& a)
{
    m_vComponents = a.m_vComponents;
}
inline __m128& hkVector4::getQuad()
{
    return m_vComponents;
}
inline const __m128& hkVector4::getQuad() const
{
    return m_vComponents;
}
inline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& c)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(b.m_vComponents, c.m_vComponents));
}
inline void hkVector4::addMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
}
inline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}
inline void hkVector4::sub4(const hkVector4& a)
{
    m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
}
inline void hkVector4::SetAllComponents(float a)
{
    m_vComponents = _mm_set1_ps(a);
}
inline void hkVector4::SetAllComponents(const hkSimdReal& a)
{
    m_vComponents = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
}
inline void hkVector4::broadcast(int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
    else if (i == 3)
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
}
inline void hkVector4::setBroadcast(const hkVector4& a, int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0x55);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xaa);
    else if (i == 3)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xff);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    __m128 prod = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
    return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), xy);
}
inline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(first, second);
}
inline void hkVector4::setXYZW(const hkVector4& a, const hkVector4& b)
{
    __m128 high = _mm_unpackhi_ps(a.m_vComponents, b.m_vComponents);
    m_vComponents = _mm_shuffle_ps(a.m_vComponents, high, 0xc4);
}

extern const hkVector4 DAT_010c71e0, DAT_010c7170;
extern const hkVector4 DAT_010c4c10, DAT_010c4c00, DAT_010c44d0;
inline __m128 reciprocal(__m128 x)
{
    __m128 r = _mm_rcp_ps(x);
    return _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, x), r));
}
inline void hkVector4::setReciprocal3(const hkVector4& a)
{
    hkVector4 one;
    one.getQuad() = DAT_010c7170.getQuad();
    hkVector4 joined;
    joined.setXYZW(a, one);
    m_vComponents = reciprocal(joined.m_vComponents);
}
inline void hkVector4::setXYZ0(const hkVector4& a)
{
    m_vComponents = _mm_and_ps(a, DAT_010c4c10.m_vComponents);
}
inline void hkVector4::setNeg4(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0.m_vComponents);
}
inline void hkVector4::setNeg3(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c4c00.m_vComponents);
}
inline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(&unk00);
}
inline void hkQuaternion::SetConjugate(const hkQuaternion& q)
{
    reinterpret_cast<hkVector4*>(&unk00)->setNeg3(q.getImag());
}
// src: COMMUNITY 0x00c66320
inline void hkQuaternion::setMul(const hkQuaternion& a, const hkQuaternion& b)
{
    hkVector4 imaginary;
    imaginary.setCross(a.getImag(), b.getImag());
    hkVector4 aw;
    aw.setBroadcast(a.getImag(), 3);
    hkVector4 bw;
    bw.setBroadcast(b.getImag(), 3);
    imaginary.addMul4(aw, b.getImag());
    imaginary.addMul4(bw, a.getImag());
    hkVector4 dot;
    dot.SetAllComponents(a.getImag().dot3(b.getImag()));
    hkVector4 product;
    product.setMul4(a.getImag(), b.getImag());
    product.sub4(dot);
    reinterpret_cast<hkVector4*>(&unk00)->setXYZW(imaginary, product);
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& q, const hkVector4& direction)
{
    hkVector4 half;
    half.getQuad() = DAT_010c71e0.getQuad();
    hkVector4 real;
    real.setBroadcast(q.getImag(), 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 sum;
    sum.setMul4(direction, factor);
    hkVector4 dot;
    dot.getQuad() = q.getImag().dot3(direction).getQuad();
    dot.broadcast(0);
    sum.addMul4(dot, q.getImag());
    hkVector4 cross;
    cross.setCross(q.getImag(), direction);
    sum.addMul4(real, cross);
    setAdd4(sum, sum);
}
__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& q, const hkVector4& direction)
{
    hkVector4 half;
    half.getQuad() = DAT_010c71e0.getQuad();
    hkVector4 real;
    real.setBroadcast(q.getImag(), 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 sum;
    sum.setMul4(direction, factor);
    hkVector4 dot;
    dot.getQuad() = q.getImag().dot3(direction).getQuad();
    dot.broadcast(0);
    sum.addMul4(dot, q.getImag());
    hkVector4 cross;
    cross.setCross(direction, q.getImag());
    sum.addMul4(real, cross);
    setAdd4(sum, sum);
}
struct AnimatedFrame
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void EvaluateTransform(float time, hkTransform& out) const;
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    float m_fAnimationDuration;
    void hkaDefaultAnimatedReferenceFrame_getDeltaReferenceFrame(float time, float nextTime, int loops, hkTransform& output) const;
};

extern __m128 DAT_010ec7f0;


#include "../../../../../../include/hkQsTransform.h"


struct S00e41100_LinearKeyTrack
{
    virtual ~S00e41100_LinearKeyTrack();
    hkVector4 m_kAxisEndPoints;
    hkVector4 m_unk20;
    float m_fAnimationDuration;
    hkVector4* m_keys;
    int m_numKeys;
    int m_iCapacityState;

    void hkaDefaultAnimatedReferenceFrame_getReferenceFrame(float time, hkQsTransform& out);
};

// @fnv 0x00e41100
// src: HAVOK_SRC 0x00e41100
void S00e41100_LinearKeyTrack::hkaDefaultAnimatedReferenceFrame_getReferenceFrame(float time, hkQsTransform& out)
{
    int last = m_numKeys - 1;
    float dt = m_fAnimationDuration / last;
    __m128 v;
    if (time >= m_fAnimationDuration)
    {
        v = m_keys[m_numKeys - 1].getQuad();
    }
    else if (time < 0.0f)
    {
        v = m_keys[0].getQuad();
    }
    else
    {
        int i = (int)(time / dt);
        if (i == last)
        {
            i--;
        }
        float f = time / dt - i;
        hkVector4 a = m_keys[i];
        hkVector4 b = m_keys[i + 1];
        __m128 t = _mm_load_ss(&f);
        t = _mm_shuffle_ps(t, t, 0);
        v = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), a.getQuad()), _mm_mul_ps(b.getQuad(), t));
    }
    out.m_vTranslation.getQuad() = v;
    out.m_rotation.hkQuaternion_setAxisAngle(m_kAxisEndPoints, v.m128_f32[3]);
    out.m_vScale.getQuad() = _mm_set_ps1(1.0f);
}
