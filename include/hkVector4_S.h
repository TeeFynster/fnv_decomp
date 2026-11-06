#pragma once

#include <stddef.h>
#include <xmmintrin.h>
#include "hkSimdReal.h"

class Vector4Comparison;
class hkQuaternion_S;
class hkQsTransform_S;
class hkMatrix3_S;
class hkRotation;
class hkTransform;

class hkVector4_S
{
public:
    __m128 m_vComponents;

    static void* __cdecl operator new(size_t nbytes);
    void operator=(const hkVector4_S& v);
    operator __m128() const;
    float& operator()(int i);
    const float& operator()(int i) const;
    __m128& getQuad();
    const __m128& getQuad() const;

    void set(float x, float y, float z, float w = 0.0f);
    void SetAllComponents(const hkSimdReal& x);
    void setZero4();
    void add4(const hkVector4_S& a);
    void setAdd4(const hkVector4_S& a, const hkVector4_S& b);
    void sub4(const hkVector4_S& a);
    void setSub4(const hkVector4_S& a, const hkVector4_S& b);
    void mul4(const hkVector4_S& a);
    void mul4(const hkSimdReal& a);
    void setMul4(const hkVector4_S& a, const hkVector4_S& b);
    void setMul4(const hkSimdReal& r, const hkVector4_S& a);
    void addMul4(const hkSimdReal& r, const hkVector4_S& a);
    void addMul4(const hkVector4_S& a, const hkVector4_S& b);
    void setAddMul4(const hkVector4_S& a, const hkVector4_S& x, const hkVector4_S& y);
    void setAddMul4(const hkVector4_S& a, const hkVector4_S& b, const hkSimdReal& r);
    void setCross(const hkVector4_S& a, const hkVector4_S& b);
    void setInterpolate4(const hkVector4_S& a, const hkVector4_S& b, const hkSimdReal& t);
    Vector4Comparison compareLessThan4(const hkVector4_S& a) const;
    Vector4Comparison compareEqual4(const hkVector4_S& a) const;
    Vector4Comparison compareLessThanEqual4(const hkVector4_S& a) const;
    Vector4Comparison compareGreaterThanEqual4(const hkVector4_S& a) const;
    hkSimdReal dot3(const hkVector4_S& a) const;
    hkSimdReal length3() const;
    hkSimdReal lengthSquared3() const;
    hkSimdReal lengthInverse3() const;
    void normalize3();
    hkSimdReal normalizeWithLength3();
    void setReciprocal4(const hkVector4_S& v);
    hkSimdReal getSimdAt(int i) const;
    void setXYZW(const hkVector4_S& xyz, const hkVector4_S& w);
    void broadcast(int i);
    void setBroadcast(const hkVector4_S& v, int i);
    void SetRotatedDirection(const hkQuaternion_S& q, const hkVector4_S& b);
    void SetTransformedPoint(const hkQsTransform_S& a, const hkVector4_S& b);
    void _setMul3(const hkMatrix3_S& a, const hkVector4_S& b);
    void _setRotatedDir(const hkRotation& a, const hkVector4_S& b);
    void _setRotatedInverseDir(const hkRotation& a, const hkVector4_S& b);
    void _setTransformedInversePos(const hkTransform& a, const hkVector4_S& b);
    void _setTransformedPos(const hkTransform& a, const hkVector4_S& b);
};
