#pragma once

#include <stddef.h>
#include <xmmintrin.h>
#include "hkSimdReal.h"

class hkVector4_X
{
public:
    __m128 m_vComponents;

    static void* __cdecl operator new(size_t nbytes);
    void operator=(const hkVector4_X& v);
    void set(float x, float y, float z, float w = 0.0f);
    void setAll3(float x);
    void setZero4();
    void setAdd4(const hkVector4_X& a, const hkVector4_X& b);
    void sub4(const hkVector4_X& a);
    void setSub4(const hkVector4_X& a, const hkVector4_X& b);
    void mul4(const hkVector4_X& a);
    void setMul4(const hkVector4_X& a, const hkVector4_X& b);
    void mul4(const hkSimdReal& a);
    void setInterpolate4(const hkVector4_X& a, const hkVector4_X& b, const hkSimdReal& t);
    float& operator()(int i);
    const float& operator()(int i) const;
    operator __m128() const;
};
