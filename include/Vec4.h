#pragma once

#if defined(FNV_VEC4_NO_SSE) || defined(FNV_VEC4_SCALAR)
__if_not_exists(__m128) { union __m128; }
#else
#include <xmmintrin.h>
#endif

class Elem12;
class ScalarLane;
class SReal;
class SimdReal;
class ScalarValue;
class VComp;
class VecCompare;
class Quat;
class Rot;
class Xform;
class Mat4Like;
class Matrix;
class Buf40;
class RotationColumns;

// Define FNV_VEC4_SIMD for aligned SIMD storage with uninitialized construction.
// Define FNV_VEC4_SCALAR for integer zeroing and trivial, unaligned by-value copies.
struct Vec4
{
public:
    union
    {
        struct
        {
            union { float x; unsigned int xb; };
            union { float y; unsigned int yb; };
            union { float z; unsigned int zb; };
            union { float w; unsigned int wb; };
        };
#if defined(FNV_VEC4_SIMD) && !defined(FNV_VEC4_SCALAR)
        __m128 m_vComponents;
        __m128 v;
        float elements[4];
#endif
        struct
        {
            Elem12* m_pData;
            int m_iArrayLength;
            int m_iCapacity;
        };
    };

    enum Initialization { Uninitialized };
    typedef __declspec(align(16)) Vec4 Aligned;

#if defined(FNV_VEC4_SIMD) && !defined(FNV_VEC4_SCALAR)
    __forceinline Vec4() {}
#elif defined(FNV_VEC4_SCALAR)
    Vec4() : xb(0), yb(0), zb(0), wb(0) {}
#else
    Vec4() : x(0), y(0), z(0), w(0) {}
#endif
    __forceinline explicit Vec4(Initialization) {}
    Vec4(const __m128& q);
#if !defined(FNV_VEC4_SIMD) && !defined(FNV_VEC4_SCALAR)
    Vec4(const Vec4& q);
#endif
    Vec4(float a, float b, float c, float d);
    void operator=(const __m128& q);
#if defined(FNV_VEC4_SIMD) && !defined(FNV_VEC4_SCALAR)
    operator __m128() const { return m_vComponents; }
    __forceinline void operator=(const Vec4& q);
#else
    operator __m128() const;
#endif
    Vec4 operator+(const Vec4& q) const;
    float& operator()(int index);
    const float& operator()(int index) const;
    __m128& getQuad();
    const __m128& getQuad() const;
    __m128 get() const;
#if defined(FNV_VEC4_SIMD) && !defined(FNV_VEC4_SCALAR)
    __forceinline SReal getSimdAt(int index) const;
#else
    float getSimdAt(int index) const;
#endif
    SimdReal getSimdAt0() const;
    ScalarLane lane(int index) const;
    int getInt24W() const;
    float delta() const;

    void set(float x, float y, float z, float w = 0.0f);
    void set(float start, float end);
    void set(__m128 value);
    void SetAllComponents(const SReal& value);
    void setZero4();
    void zero();
    void setCross(const Vec4& a, const Vec4& b);
    void orderedCross(const Vec4& left, const Vec4& right);
    void setBroadcast3(const Vec4& value);
    void setMul4(const Vec4& a, const Vec4& b);
    void setMul4(const SimdReal& scalar, const Vec4& value);
    void setMul4(float scalar, const Vec4& value);
    void setAdd4(const Vec4& a, const Vec4& b);
    void setSub4(const Vec4& a, const Vec4& b);
    void setAddMul4(const Vec4& a, const Vec4& b, const SReal& scalar);
    void add4(const Vec4& value);
    void sub4(const Vec4& value);
    void mul4(const Vec4& value);
    void mul4(float scalar);
    void addMul4(__m128 scalar, const Vec4& value);
    void addMul4(const Vec4& a, const Vec4& b);
    void setInterpolate4(const Vec4& a, const Vec4& b, const SReal& t);
    void setInterpolate4(const Vec4& a, const Vec4& b, const SimdReal& t);
    void setInterpolate4(const Vec4& a, const Vec4& b, float t);
    void setNeg4(const Vec4& value);
    void setAbs4(const Vec4& value);
    void setXYZW(const Vec4& xyz, const Vec4& w);
    void setReciprocal4(const Vec4& value);
    void setMin(const Vec4& a, const Vec4& b);
    void setMax(const Vec4& a, const Vec4& b);
    VComp compareLessThan4(const Vec4& value) const;
    VComp compareLessThanZero4() const;
    VComp compareGreaterThan4(const Vec4& value) const;
    VecCompare compareLessThanEqual4(const Vec4& value) const;

#if defined(FNV_VEC4_SIMD) && !defined(FNV_VEC4_SCALAR)
    __forceinline SReal dot3(const Vec4& value) const;
#else
    ScalarLane dot3(const Vec4& value) const;
#endif
    SimdReal dot4xyz1(const Vec4& value) const;
    ScalarValue Dot(const Vec4& value) const;
    ScalarLane inverseLength3() const;
    SReal length3() const;
    SReal lengthInverse3() const;
    SReal normalizeWithLength3();
    void normalize3();
    void fastNormalize3NonZero();
    void SetRotatedDirection(const Quat& quaternion, const Vec4& direction);
    void setRotatedInverseDir(const void* rotation, const void* value);
    void rotInvDir(const Rot& rotation, const Vec4& value);
    void xformPos(const Xform& transform, const Vec4& value);
    void convert(Matrix* matrix);
    void __thiscall setTransformedPos_00c7f640(const Buf40*, const void*);
    void __thiscall hkVector4_setRotatedDir(const RotationColumns& rotation, const Vec4& value);
    void hkVector4_setRotatedDir(const Rot& rotation, const Vec4& value);
    void hkVector4_setRotatedDir(const void* rotation, const Vec4& value);
    void hkVector4_setRotatedInverseDir(const Rot& rotation, const Vec4& value);
    void hkVector4_setMul3(const void* matrix, const Vec4& value);
    void hkVector4_fastNormalize3();

    void difference(const Vec4& left, const Vec4& right);
    void sum(const Vec4& left, const Vec4& right);
    void add(const Vec4& value);
    void multiply(const ScalarLane& value);
    void multiply(const Vec4& value);
    void lower(const Vec4& left, const Vec4& right);
    void upper(const Vec4& left, const Vec4& right);
    void blend(const Vec4& left, const Vec4& right, const ScalarLane& ratio);
    void transform(const Mat4Like& matrix, const Vec4& value);
    ScalarLane radius() const;
    void fill(const ScalarLane& value);
    void addScaled(const ScalarLane& scale, const Vec4& value);
};
