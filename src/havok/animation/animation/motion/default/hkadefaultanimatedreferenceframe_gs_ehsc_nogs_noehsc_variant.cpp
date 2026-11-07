#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkQsTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkSimdReal.h"

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
inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline void hkVector4::add4(const __m128& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v);
}

struct Motion363
{
    __m128 vector;
    hkQuaternion angular;
};

// @fnv 0x00e41220
// src: XBOX_PDB 0x00e41220
void hkaDefaultAnimatedReferenceFrame_project(Projection363_Owner* a, Motion363* __restrict b, Projection363_Input* c, hkVector4* out)
{
    __m128 A = a->vec20;
    const __m128& v = b->vector;
    __m128 T2 = Project363(v, A);
    __m128 T4 = Project363(v, (Cross363(a->vec20, a->vec30)));
    __m128 T1 = Project363(v, a->vec30);
    out->setZero4();
    if (a->flag11 != 0)
    {
        out->add4(T1);
    }
    if (a->flag10 != 0)
    {
        out->add4(T2);
    }
    if (a->flag12 != 0)
    {
        out->add4(T4);
    }
    if (a->flag13 != 0)
    {
        float f1;
        hkVector4 f2;
        hkQuaternion* h = &b->angular;
        h->hkQuaternion_decomposeRestAxis(&a->vec20, &f2, &f1);
        float target = c->unk0C;
        const double PI = 3.14159265358979323846f;
        const double TWO_PI = 6.28318530717958647692f;
        while (f1 - target > PI)
        {
            f1 -= TWO_PI;
        }
        while (f1 - target < -PI)
        {
            f1 += TWO_PI;
        }
        out->m_vComponents.m128_f32[3] = f1;
    }
    else
    {
        out->m_vComponents.m128_f32[3] = 0.0f;
    }
}

inline hkSimdReal::hkSimdReal(const __m128& v) : m_vValue(v)
{}

inline const __m128& hkSimdReal::getQuad() const
{
    return m_vValue;
}
inline hkVector4::hkVector4(const hkVector4& a) : m_vComponents(a.m_vComponents)
{}
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
inline hkQuaternion::hkQuaternion()
{}
inline void hkQuaternion::operator=(const hkQuaternion& q)
{
    *reinterpret_cast<hkVector4*>(this) = q.getImag();
}
inline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(this);
}
inline void hkQuaternion::SetConjugate(const hkQuaternion& q)
{
    reinterpret_cast<hkVector4*>(this)->setNeg3(q.getImag());
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
    reinterpret_cast<hkVector4*>(this)->setXYZW(imaginary, product);
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
__forceinline hkQsTransform::hkQsTransform()
{}
__forceinline void hkQsTransform::operator=(const hkQsTransform& a)
{
    m_vTranslation = a.m_vTranslation;
    m_rotation = a.m_rotation;
    m_vScale = a.m_vScale;
}
__forceinline void hkQsTransform::SetConjugate(const hkQsTransform& a)
{
    m_vTranslation.setRotatedInverseDir(a.m_rotation, a.m_vTranslation);
    m_vTranslation.setNeg4(m_vTranslation);
    m_rotation.SetConjugate(a.m_rotation);
    hkVector4 scale;
    scale.setReciprocal3(a.m_vScale);
    m_vScale.setXYZ0(scale);
}
__forceinline void hkQsTransform::SetProduct(const hkQsTransform& a, const hkQsTransform& b)
{
    hkVector4 shift;
    shift.SetRotatedDirection(a.m_rotation, b.m_vTranslation);
    m_vTranslation.setAdd4(a.m_vTranslation, shift);
    m_rotation.setMul(a.m_rotation, b.m_rotation);
    m_vScale.setMul4(a.m_vScale, b.m_vScale);
}
__forceinline void hkQsTransform::SetMulInverse(const hkQsTransform& a, const hkQsTransform& b)
{
    hkQsTransform inv;
    inv.SetConjugate(a);
    SetProduct(inv, b);
}
struct AnimatedFrame
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void EvaluateTransform(float time, hkQsTransform& out) const;
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    float m_fAnimationDuration;
    void hkaDefaultAnimatedReferenceFrame_getDeltaReferenceFrame(float time, float nextTime, int loops, hkQsTransform& output) const;
};
// @fnv 0x00e413d0
// src: HAVOK_SRC 0x00e413d0
void AnimatedFrame::hkaDefaultAnimatedReferenceFrame_getDeltaReferenceFrame(float time, float nextTime, int loops, hkQsTransform& output) const
{
    hkQsTransform start;
    EvaluateTransform(time, start);
    hkQsTransform next;
    EvaluateTransform(nextTime, next);
    if (loops != 0)
    {
        hkQsTransform cycle;
        EvaluateTransform(m_fAnimationDuration, cycle);
        const unsigned count = loops < 0 ? -loops : loops;
        for (unsigned i = 0; i < count; ++i)
        {
            if (loops < 0)
            {
                hkQsTransform temp;
                temp.SetMulInverse(cycle, next);
                next = temp;
            }
            else
            {
                hkQsTransform temp;
                temp.SetProduct(cycle, next);
                next = temp;
            }
        }
    }
    output.SetMulInverse(start, next);
    output.m_vScale.SetAllComponents(1.0f);
}
