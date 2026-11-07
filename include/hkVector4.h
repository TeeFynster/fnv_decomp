#pragma once
#include <stddef.h>
__if_not_exists(__m128)   // a unit that declares its own __m128 and intrinsics keeps them (as hkSimdReal.h)
{
#include <xmmintrin.h>
}
#include "hkSimdReal.h"

extern "C" __m128 _mm_rcp_ps(__m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);

class hkTransform;
class hkRotation;
class hkMatrix3;
class Vector4Comparison;
class hkQuaternion;
class GeometryQuaternionLocal_00da16d0;
class Scalar;
class SimdReal;
class SimdScalar;
class ScalarValue;
class NiPoint3;
class Transform;
class Comparison;
class Matrix;
struct hkQsTransform;
class MassVec;
class RealLane;
class ScalarLane;
class Scalar4;
class CompareBits;
template <bool N> struct BooleanTypeConstant;
typedef BooleanTypeConstant<true> hkTypeIsPod;

// Havok 7.1 declares the default and copy constructors and operator= HK_FORCE_INLINE (hkVector4.h:35-49).
// A unit whose matched code needs another copy form defines FNV64_HKVECTOR4_OWN_COPY / _ASSIGN and its own body.
class hkVector4
{
  public:
    typedef __m128 Components;
    union
    {
        __m128 m_vComponents;
        __m128 v;
        __m128 quad;
        __m128 bits;
        __m128 m;
        __m128 values;
        float elements[4];
        float m_fComponents[4];
        __m128 value;
        __m128 m_quadS;
        float m_f[4];
        float m_q[4];
        float lanes[4];
        float f[4];
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };

#ifndef FNV64_HKVECTOR4_OWN_DEFAULT
    __forceinline hkVector4() {}
#else
    hkVector4();
#endif
#ifndef FNV64_HKVECTOR4_OWN_COPY
    __forceinline hkVector4(const hkVector4& vector) { m_vComponents = vector.m_vComponents; }
#else
    hkVector4(const hkVector4& vector);   // the unit defines its own form
#endif
    hkVector4(float x, float y, float z, float w);
#ifndef FNV64_HKVECTOR4_OWN_ASSIGN
    __forceinline void operator=(const hkVector4& vector) { m_vComponents = vector.m_vComponents; }
#else
    void operator=(const hkVector4& vector);   // the unit defines its own form
#endif
    char operator==(const hkTypeIsPod&) const;
#ifdef FNV64_HKVECTOR4_OWN_CONVERSION
    operator __m128() const;
#else
    operator __m128() const
    {
        return m_vComponents;
    }
#endif
    __forceinline float& operator()(int index);
    const float& operator()(int index) const;
    __forceinline __m128& getQuad();
    __forceinline const __m128& getQuad() const;
    float getW() const;
    hkSimdReal getComponent(int index) const;

    void set(float x, float y, float z, float w = 0.0f);
    void setZero4();
    void SetAllComponents(float value);
    __forceinline void SetAllComponents(const hkSimdReal& value);
    void broadcast(int index);
    void setBroadcast(const hkVector4& vector, int index);
    void setBroadcast3(const hkVector4& vector);
    void setXYZW(const hkVector4& xyz, const hkVector4& w);
    void setXYZ0(const hkVector4& vector);
#ifndef FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
#else
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
#endif
#ifndef FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
#else
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b);
#endif
#ifndef FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
#else
    void setMul4(const hkVector4& a, const hkVector4& b);
#endif
    void setMul4(const hkSimdReal& scalar, const hkVector4& vector);
    void setMul4(__m128 scalar, const hkVector4& vector);
    void setMul4(float scalar, const hkVector4& vector);
    void setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& c);
    void setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& scalar);
    void setAddMul4a(const hkVector4& a, const hkVector4& b, float scalar);
    void setAddMul4b(const hkVector4& a, const hkVector4& b, float scalar);
#ifndef FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
    __forceinline void add4(const hkVector4& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
#else
    __forceinline void add4(const hkVector4& vector);
#endif
#ifndef FNV64_HKVECTOR4_OWN_SUB4_consthkVector4
    __forceinline void sub4(const hkVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
#else
    void sub4(const hkVector4& vector);
#endif
#ifndef FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
    __forceinline void mul4(const hkVector4& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
#else
    __forceinline void mul4(const hkVector4& vector);
#endif
#ifndef FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal
    __forceinline void mul4(const hkSimdReal& s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
#else
    __forceinline void mul4(const hkSimdReal& scalar);
#endif
#ifndef FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4
    __forceinline void addMul4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents)); }
#else
    void addMul4(const hkVector4& a, const hkVector4& b);
#endif
    __forceinline void addMul4(const hkSimdReal& scalar, const hkVector4& vector);
    void addMul4(__m128 scalar, const hkVector4& vector);
    void Mul(const MassVec& scalar);
    void setCross(const hkVector4& a, const hkVector4& b);
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b);
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b);
    void setNeg4(const hkVector4& vector);
    void negateSelf();
    void setAbs4(const hkVector4& vector);
    void setXYZ(const hkVector4& vector);
    Vector4Comparison compareLessThanZero4() const;
    void _setRotatedDir(const hkRotation& rotation, const hkVector4& vector);
    void SetTransformedPosition(const hkTransform& transform, const hkVector4& vector);
    void hkVector4_setTransformedInversePos(const hkTransform& transform, const hkVector4& vector);
    void hkVector4_setTransformedInversePos(const hkTransform* transform, const hkVector4* vector);
    hkSimdReal normalizeWithLength3();
    __forceinline void setNeg3(const hkVector4& vector);
    void setReciprocal3(const hkVector4& vector);
    __forceinline void setReciprocal4(const hkVector4& vector)
    {
        m_vComponents = _mm_rcp_ps(vector.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(m_vComponents, vector.m_vComponents), m_vComponents);
        m_vComponents = _mm_sub_ps(_mm_add_ps(m_vComponents, m_vComponents), rr);
    }
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, const hkSimdReal& t);
    void SetRotatedDirection(const hkQuaternion& quaternion, const hkVector4& direction);
    void SetRotatedDirection(const hkVector4& quaternion, const hkVector4& direction);
    void setRotatedInverseDir(const hkQuaternion& quaternion, const hkVector4& direction);
    void SetTransformedPoint(const hkQsTransform& transform, const hkVector4& vector);
    __forceinline hkSimdReal dot3(const hkVector4& vector) const;
    hkSimdReal dot4xyz1(const hkVector4& vector) const;
    float dot3scalar(const hkVector4& vector) const;
    hkSimdReal lengthSquared3() const;
    float lengthSquared4() const;
    __forceinline hkSimdReal length3() const;
#ifdef FNV64_HKVECTOR4_LENGTHINVERSE4   // the unit defining it (0x005612a0); a member would hide Havok units' free lengthInverse4
    hkSimdReal lengthInverse4() const; // src: HAVOK_SRC (name)
#endif
    void normalize3();
    void normalize4();
    int lessZeroXYZ() const;
    int lessZero3() const;

    hkVector4 FUN_00630b40() const;
    float EvaluateValue_004586d0() const;
    void normalize3_0062aea0();
    void hkVector4_mul4(const hkSimdReal& scalar);
    void ComputeValues_00630df0(const hkVector4& a, const hkVector4& b);
    hkSimdReal& hkVector4_getSimdAt(hkSimdReal& value, int index) const;
    int GetTriangleEdgeSignMask(const hkVector4& vector, const hkVector4* vectors, void* data);

#ifdef FNV64_HKVECTOR4_PACKET_BODIES
    __forceinline hkVector4(__m128 value) : m_vComponents(value) {}
#else
    hkVector4(__m128 value);
#endif
    void operator=(const __m128& value);
    float& component(int index);
    const float& component(int index) const;
    __m128& q();
    const __m128& q() const;
    float getX() const;
    int getInt24W() const;
    __forceinline hkSimdReal getSimdAt(int index) const;
    hkSimdReal getSimdAt0() const;
    hkSimdReal getSimdAt3() const;
    hkSimdReal getSimdAtE(int index) const;
    hkSimdReal dot4(const hkVector4& vector) const;
    hkSimdReal horizontalAdd3() const;
    hkSimdReal horizontalAdd4() const;
    __m128 lengthSquared3q() const;
    RealLane inner3(const hkVector4& vector) const;
    Vector4Comparison compareLessThan4(const hkVector4& vector) const;
    Vector4Comparison compareEqual4(const hkVector4& vector) const;
    CompareBits compareLessThanEqual4(const hkVector4& vector) const;
    int equals4(const hkVector4& vector, float epsilon) const;
#ifdef FNV64_HKVECTOR4_PACKET_BODIES
    __forceinline void set(__m128 value) { m_vComponents = value; }
#else
    void set(__m128 value);
#endif
    void load3(const float* values);
    void zeroElement(int index);
    void setAll3(float value);
    void broadcast0();
    void setBroadcast3clobberW(const hkVector4& vector, int index);
    void setW(const hkVector4& vector);
    void add(__m128 value);
    void add4(const __m128& value);
    void add3clobberW(const hkVector4& vector);
    void sub3clobberW(const hkVector4& vector);
    void mul4(const float& scalar);
    void mul4(const __m128& scalar);
    void mul4(const ScalarLane& scalar);
    void mul4(const Scalar4& scalar);
    void mul4s(const hkSimdReal& scalar);
    void scale(const __m128& scalar);
    void scaled(const __m128& scalar, const hkVector4& vector);
    void setMul4_b(float scalar, const hkVector4& vector);
    void setAddMul4(const hkVector4& a, const hkVector4& b, float scalar);
    void subMul4(const hkSimdReal& scalar, const hkVector4& vector);
    void setSubMul(const hkVector4& a, const hkVector4& b, const hkSimdReal& scalar);
    void setInterpolate4(const hkVector4& a, const hkVector4& b, const Scalar4& scalar);
    void cofactor(const hkVector4& a, const hkVector4& b);
    void setFlipSign(const hkVector4& vector, const hkVector4& sign);
    void setFlipSign(const hkVector4& vector, const hkSimdReal& sign);
    void neg();
    void neg4();
    static void setNeg4(hkVector4& result, const hkVector4& vector, const __m128& sign);
    void commitIncrement(hkVector4& result) const;
    void _setMul3(const hkRotation& rotation, const hkVector4& vector);
    void _setMul3(const hkMatrix3& matrix, const hkVector4& vector);
    void _setMul4(const hkMatrix3& matrix, const hkVector4& vector);
    void SetRotatedVector(const hkMatrix3& matrix, const hkVector4& vector);
    void _setRotatedInverseDir(const hkRotation& rotation, const hkVector4& vector);
    __forceinline void _setTransformedPos(const hkTransform& transform, const hkVector4& vector);
    void _setTransformedPos(const hkQsTransform& transform, const hkVector4& vector);
    void _setTransformedInversePos(const hkTransform& transform, const hkVector4& vector);
    void SetRotatedDirection(const hkRotation& rotation, const hkVector4& vector);
    void SetRotatedDirection(const hkTransform& transform, const hkVector4& vector);
    void setRotatedInverseDir(const hkRotation& rotation, const hkVector4& vector);
    void SetTransformedPoint(const hkTransform& transform, const hkVector4& vector);
    void setRotatedCached(const hkQuaternion& quaternion, const hkVector4& vector,
                          const __m128& yz, const __m128& zx) throw();
    void hkVector4_setRotatedInverseDir(const hkRotation& rotation, const hkVector4& vector);
    void normalize_005611c0();
    void FUN_006815c0();
    void setTransformedPos_00c7f640(const hkTransform& transform, const hkVector4& vector);
    void hkVector4_setRotatedDir(const hkRotation& rotation, const hkVector4& vector);
    void hkVector4_setRotatedDir(const hkRotation* rotation, const hkVector4* vector);
    void hkVector4_setMul3(const hkMatrix3& matrix, const hkVector4& vector);

    static void* __cdecl operator new(size_t size);
    __forceinline static const hkVector4& __cdecl getZero();
    // Explicit local quaternion call form used by the byte-matched geometry utility.
    void SetRotatedDirection(const GeometryQuaternionLocal_00da16d0&, const hkVector4&);
    void setRotatedCached(const GeometryQuaternionLocal_00da16d0&, const hkVector4&,
                          const __m128&, const __m128&) throw();
    // Alternate unit spellings of the same SIMD packet helpers; data and alignment are unchanged.
    __forceinline __m128 get() const { return m_vComponents; }
    void xyz(const __m128& packet);
    void interpolate(const hkVector4&, const hkVector4&, const Scalar&);
    void add(const hkVector4&, const hkVector4&);
    void sub(const hkVector4&, const hkVector4&);
    void scale(const Scalar&);
    void hkVector4_setMul3(const void*, const hkVector4*);
    void setTransformedPos_00c7f640(const Matrix*, const hkVector4*);
    void hkVector4_setRotatedDir(const void*, const hkVector4*);
    // Typed scalar and transform call surfaces retained from the matched hkVector4 units.
    hkVector4(float x, float y, float z);
    hkVector4 operator*(float value) const;
    hkVector4 operator+(const hkVector4& vector) const;
    hkVector4 operator-() const;
    __m128& packet();
    const __m128& packet() const;
    void zero();
    void subtract(const hkVector4& a, const hkVector4& b);
    void setSub(const hkVector4& a, const hkVector4& b);
    void setAdd(const hkVector4& a, const hkVector4& b);
    void mul(const hkVector4& a, const hkVector4& b);
    void mul4(const Scalar& scalar);
    void multiply(const Scalar& scalar);
    void product(const Scalar& scalar, const hkVector4& vector);
    void cross(const hkVector4& a, const hkVector4& b);
    void negate(const hkVector4& vector);
    void addMul(const hkVector4& a, __m128 scale, const hkVector4& b);
    void setAddMul4(const hkVector4& a, const hkVector4& b, const Scalar& scalar);
    void setInterpolate4(const hkVector4& a, const hkVector4& b, const Scalar& t);
    void Interpolate(const hkVector4& oldValue, const hkVector4& newValue, float factor);
    void SetTransformedPoint(const Transform& transform, const hkVector4& point);
    Scalar getSimdAtScalarCall(int index) const;
    Scalar dot(const hkVector4& vector) const;
    Scalar dot3ScalarCall(const hkVector4& vector) const;
    float DotProduct(const hkVector4& vector);
    Scalar sum() const;
    Scalar norm() const;
    Scalar lengthSquared3ScalarCall() const;
    Scalar length3ScalarCall() const;
    float length() const;
    Scalar inverseLength() const;
    void normalize();
    Comparison compareLessThanZero4ScalarCall() const;
    int getMajorAxis() const;
    int maxAxisSecond() const;
    int maxAxis() const;
    float GetAngle();
    void SetComponents(float x, float y, float z);
    hkVector4 SubtractIntoVector(const hkVector4& vector);
    hkVector4 FUN_00439e90(const hkVector4& vector);
    void ScaleComponents(float value);
    void Unitize_004a0c10();
    void setMul(const hkVector4* a, const hkVector4* b);
    void setMulInverse(const hkVector4* a, const hkVector4* b);
    void hkQuaternion_getAxis(hkVector4* vector);
    void setTransformedPos_00c7f640(const Transform& transform, const hkVector4& point);
    void hkQuaternion_setAxisAngle(const hkVector4* vector, float value);
    void FUN_00cb26e0(const hkRotation* rotation);
    template <int I> void splat(const hkVector4& vector);
    // Typed vector calls recovered from the former FourFloatVector declarations.
    hkVector4* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(hkVector4* vector);
    void __thiscall SetQuaternionComponentsFromVector(const hkVector4* vector);
    hkVector4& ComputeValue_00e531a0(int parameter);
    hkVector4 ProcessAndReturnValue_00e53260(int parameter);
    float& At(int index);
    const float& At(int index) const;
    __m128 length3PacketCall() const;
    ScalarValue Dot(const hkVector4& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const hkVector4& vector);
    void Sub(const hkVector4& vector);
    void Cross(const hkVector4& a, const hkVector4& b);
    void setMul4(const SimdReal& scalar, const hkVector4& vector);
    void addMul4(const SimdReal& scalar, const hkVector4& vector);
    void setAddMul4(const hkVector4& a, const hkVector4& b, const SimdReal& scalar);
    SimdReal getSimdAt3SimdCall() const;
    SimdReal lengthSquared3SimdCall() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const hkVector4& vector);
    void setAddMul(const hkVector4& a, const hkVector4& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const hkVector4& vector);
    void transformed(const Transform& transform, const hkVector4& vector);
    void addScaled(const hkVector4& base, const hkVector4& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

typedef char hkVector4_size_check[(sizeof(hkVector4) == 16) ? 1 : -1];
typedef char hkVector4_components_offset_check[(offsetof(hkVector4, m_vComponents) == 0) ? 1 : -1];
typedef char hkVector4_quad_offset_check[(offsetof(hkVector4, quad) == 0) ? 1 : -1];
typedef char hkVector4_x_offset_check[(offsetof(hkVector4, x) == 0) ? 1 : -1];
typedef char hkVector4_y_offset_check[(offsetof(hkVector4, y) == 4) ? 1 : -1];
typedef char hkVector4_z_offset_check[(offsetof(hkVector4, z) == 8) ? 1 : -1];
typedef char hkVector4_w_offset_check[(offsetof(hkVector4, w) == 12) ? 1 : -1];
typedef char hkVector4_lanes_offset_check[(offsetof(hkVector4, lanes) == 0) ? 1 : -1];
