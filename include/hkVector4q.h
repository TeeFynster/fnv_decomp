#pragma once

#include <xmmintrin.h>
#include "hkVector4.h"

extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_mul_ps(__m128, __m128);

class hkBool;
class hkVector4Comparisonq;
class hkSimdRealq;
class hkMatrix3q;
class hkRotationq;
class hkRotation;
class hkTransformq;
class hkTransform;

class hkVector4q
{
public:
    union
    {
        __m128 m_vComponents;
        struct
        {
            hkVector4 m_vec;
        };
    };

    __forceinline hkVector4q() {}
    __forceinline hkVector4q(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
#ifndef FNV64_HKVECTOR4Q_OWN_BODIES
    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
#else
    void operator=(const hkVector4q& v);
#endif
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    const float& operator()(int i) const;

#ifndef FNV64_HKVECTOR4Q_OWN_BODIES
    __forceinline void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
#else
    void set(float x, float y, float z, float w = 0.0f);
#endif
#ifndef FNV64_HKVECTOR4Q_OWN_BODIES
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
#else
    void setZero4();
#endif
#ifndef FNV64_HKVECTOR4Q_OWN_BODIES
    __forceinline void SetAllComponents(float x)
    {
        m_vComponents = _mm_set_ps1(x);
    }
#else
    void SetAllComponents(float x);
#endif
    void SetAllComponents(const float& x);
    void setXYZ(const hkVector4q& v);
    void setW(const hkSimdRealq& w);
    template <int I> void setBroadcast(const hkVector4q& v);
    void setBroadcast3(const hkVector4q& v);
    void setMul4(const hkVector4q& a, const hkVector4q& b);
    void setAdd4(const hkVector4q& a, const hkVector4q& b);
    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMin4(const hkVector4q& a, const hkVector4q& b);
    void setMax4(const hkVector4q& a, const hkVector4q& b);
    void add4(const hkVector4q& a);
    __forceinline void sub4(const hkVector4q& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
#ifndef FNV64_HKVECTOR4Q_OWN_BODIES
    __forceinline void mul4(const hkVector4q& a)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
    }
#else
    void mul4(const hkVector4q& a);
#endif
    void addMul4(const hkVector4q& a, const hkVector4q& b);
    void setAddMul4(const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& r);
    void setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t);
    void blendFrom(const hkVector4q& v0, const hkVector4q& t);
    void setCross(const hkVector4q& a, const hkVector4q& b);
    void setNeg4(const hkVector4q& v);
    void setNeg4b(const hkVector4q& v);
    void xor4(const hkVector4q& b);
    void setXor4(const hkVector4q& a, const hkVector4q& b);
    void normalize3();
    float dot3(const hkVector4q& v) const;
    hkSimdRealq dot4xyz1(const hkVector4q& a) const;
    float length3() const;
    // Havok 7.1 hkVector4::length3() returns hkSimdReal; units built on the float form above define it so, the
    // SIMD form is declared under this name (a free function instead changes 0x00d351c0's register colours).
    hkSimdRealq length3Simd() const;
    float lengthSquared3() const;
    hkSimdRealq getSimdAt3() const;
    int getInt24W() const;
    void setInt24W(int value);
    hkBool equals3(const hkVector4q& v, float epsilon) const;
    hkVector4Comparisonq compareLessThan4(const hkVector4q& a) const;
    int compareLessThanEqual4(const hkVector4q& v) const;
    void setSelect4(const hkVector4Comparisonq& comp, const hkVector4q& trueValue, const hkVector4q& falseValue);
    void _setRotatedInverseDir(const hkMatrix3q& r, const hkVector4q& b);
    void SetRotatedDirection(const hkMatrix3q& r, const hkVector4q& b) throw();
    void SetRotatedDirection(const hkMatrix3& r, const hkVector4q& b) throw(); // exe: 0x00c7f700
    void SetRotatedDirection(const hkRotationq& r, const hkVector4q& b);
    void SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn);
    void setTransformedPos_00c7f640(const hkTransform& t, const hkVector4q& v);
    void hkVector4_setRotatedInverseDir(const hkRotation& r, const hkVector4q& v);
    void hkVector4_setTransformedInversePos(const hkTransform& t, const hkVector4& v);
};

