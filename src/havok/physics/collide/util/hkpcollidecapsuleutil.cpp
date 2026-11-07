#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/physics/collide/util/hkpcollidecapsuleutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/hkpcollidecapsuleutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original SIMD type: CRT byte-array lanes change /GS instrumentation.
#define _INCLUDED_MM2
// Exe 0x00cd58b0 FUN_00cd58b0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

extern "C"
{
    LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_rsqrt_ss(LocalM128 a);
    LocalM128 _mm_cmpeq_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_andnot_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_set_ss(float a);
    LocalM128 _mm_load_ss(float const* p);
    void _mm_store_ss(float* p, LocalM128 a);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    LocalM128 _mm_sqrt_ss(LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_set_ps1(float);
}

#include "../../../../../include/hkMatrix4.h"
#include "../../../../../include/hkContactPoint.h"

extern "C"
{
    double __cdecl sqrt(double);
    double __cdecl fabs(double);
}

inline float sqrt(float _X)
{
    return ((float)sqrt((double)(_X)));
}
inline float fabs(float _X)
{
    return ((float)fabs((double)(_X)));
}

extern float DAT_01011d78;
extern const float DAT_01017718;
extern float DAT_01016248;
extern float DAT_0104da4c;
extern const LocalM128 DAT_010c44d0;


inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline float& hkVector4::operator()(int i)
{
    return m_vComponents.m128_f32[i];
}
inline const float& hkVector4::operator()(int i) const
{
    return m_vComponents.m128_f32[i];
}

__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline float hkVector4::dot3scalar(const hkVector4& b) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, b.m_vComponents);
    const LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    const LocalM128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    float f;
    _mm_store_ss(&f, r);
    return f;
}
__forceinline LocalM128 hkVector4::lengthSquared3q() const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
    const LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
}
__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}
__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, float r)
{
    const LocalM128 rr = _mm_load_ss(&r);
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(rr, rr, 0), b.m_vComponents), a.m_vComponents);
}
__forceinline void hkVector4::normalize3()
{
    const LocalM128 q = m_vComponents;
    const LocalM128 x2 = _mm_mul_ps(q, q);
    const LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    const LocalM128 lenSq = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
    const LocalM128 e = _mm_rsqrt_ss(lenSq);
    const LocalM128 equalsZero = _mm_cmpeq_ss(lenSq, _mm_set_ss(DAT_01011d78));
    const LocalM128 ree = _mm_mul_ss(_mm_mul_ss(lenSq, e), e);
    const LocalM128 t = _mm_sub_ss(_mm_set_ss(DAT_01017718), ree);
    const LocalM128 he = _mm_mul_ss(_mm_set_ss(DAT_01016248), e);
    const LocalM128 inv = _mm_andnot_ps(equalsZero, _mm_mul_ss(he, t));
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), q);
}

struct VectorPairResult
{
    hkVector4 m_kFirstVector;
    hkVector4 m_kClosestPointOnSecond;
    float m_fValue;
    float m_t;
    float m_u;
    float unk2c;
};

int hkLineSegmentUtil_closestLineSegLineSeg(const hkVector4& A, const hkVector4& dA, const hkVector4& B, const hkVector4& dB,
                 VectorPairResult& result);

static __forceinline void calcPerpendicular(const hkVector4& vectorIn, hkVector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    float a0 = fabs(vectorIn(0));
    float a1 = fabs(vectorIn(1));
    float a2 = fabs(vectorIn(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

// Tests two capsules for collision using FUN_00d22e40, then fills cpOut with the separating normal and contact point.
// @fnv 0x00cd6260
// src: XBOX_PDB 0x00cd6260
int hkCollideCapsuleUtilClostestPointCapsVsCaps(const hkVector4* capsA, float capsARadius, const hkVector4* capsB, float capsBRadius,
                 float collisionTolerance, hkContactPoint* cpOut)
{
    hkVector4 dA;
    dA.setSub4(capsA[1], capsA[0]);
    hkVector4 dB;
    dB.setSub4(capsB[1], capsB[0]);

    VectorPairResult result;
    int res = hkLineSegmentUtil_closestLineSegLineSeg(capsA[0], dA, capsB[0], dB, result);

    float radiusSum = capsARadius + capsBRadius;
    float refDist = radiusSum + collisionTolerance;

    if (result.m_fValue > refDist * refDist)
    {
        return 1;
    }

    float distance = sqrt(result.m_fValue);

    if (res)
    {
        if (result.m_fValue > 0.0f)
        {
            cpOut->m_vSeparatingNormal = result.m_kClosestPointOnSecond;
            goto normalize;
        }
    }
    else
    {
        hkVector4 cross;
        cross.setCross(dA, dB);
        if (cross.dot3scalar(cross) > 1.192092896e-07f)
        {
            if (cross.dot3scalar(result.m_kClosestPointOnSecond) < 0.0f)
            {
                cross.setNeg4(cross);
            }
            cpOut->m_vSeparatingNormal = cross;
            goto normalize;
        }
    }
    calcPerpendicular(dA, cpOut->m_vSeparatingNormal);

normalize:
    cpOut->m_vSeparatingNormal.normalize3();
    cpOut->m_vContactPosition.setAddMul4(result.m_kFirstVector, cpOut->m_vSeparatingNormal, capsBRadius - distance);
    cpOut->m_vSeparatingNormal(3) = distance - radiusSum;
    return 0;
}

template <typename T> inline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

static __forceinline LocalM128 broadcastFloat(float f)
{
    LocalM128 r = _mm_load_ss(&f);
    return _mm_shuffle_ps(r, r, 0);
}

// Computes the triangle normal scaled by p[3], builds m from the edges scaled by p[0..2] crossed with the normal (transposed), and sets m's last column from p.
// @fnv 0x00cd6120
// src: GUESS 0x00cd6120 (confidence: low)
static __declspec(noinline) void hkVector4_UpdateFields_00cd6120(const float* apParams, const hkVector4* apVertices, hkVector4& normal,
                                              hkMatrix4& m)
{
    hkVector4 e1;
    e1.setSub4(apVertices[2], apVertices[1]);
    hkVector4 e2;
    e2.setSub4(apVertices[0], apVertices[2]);
    hkVector4 e0;
    e0.setSub4(apVertices[1], apVertices[0]);

    hkVector4 n;
    n.setCross(e1, e2);
    n.m_vComponents = _mm_mul_ps(n.m_vComponents, broadcastFloat(apParams[3]));
    normal.m_vComponents = n.m_vComponents;

    hkVector4 a;
    a.m_vComponents = _mm_mul_ps(broadcastFloat(apParams[0]), e1.m_vComponents);
    hkVector4 b;
    b.m_vComponents = _mm_mul_ps(broadcastFloat(apParams[1]), e2.m_vComponents);
    hkVector4 c;
    c.m_vComponents = _mm_mul_ps(broadcastFloat(apParams[2]), e0.m_vComponents);

    const LocalM128 n_c9 = _mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xc9);
    const LocalM128 n_d2 = _mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xd2);

    m.m_kColumn0.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9), n_d2),
                                            _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2), n_c9));
    m.m_kColumn1.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9), n_d2),
                                            _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2), n_c9));
    m.m_kColumn2.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(c.m_vComponents, c.m_vComponents, 0xc9), n_d2),
                                            _mm_mul_ps(_mm_shuffle_ps(c.m_vComponents, c.m_vComponents, 0xd2), n_c9));

    hkSwap(m.m_kColumn1(0), m.m_kColumn0(1));
    hkSwap(m.m_kColumn2(0), m.m_kColumn0(2));
    hkSwap(m.m_kColumn2(1), m.m_kColumn1(2));

    m.m_kColumn0(3) = normal(0);
    m.m_kColumn1(3) = normal(1);
    m.m_kColumn2(3) = normal(2);

    m.m_kColumn3.setZero4();
    m.m_kColumn3(0) = -apParams[0] * apParams[4];
}

volatile void* g_p;
volatile void* g_v;
volatile void* g_n;
volatile void* g_m;

void dummy_caller()
{
    hkVector4_UpdateFields_00cd6120((const float*)g_p, (const hkVector4*)g_v, *(hkVector4*)g_n, *(hkMatrix4*)g_m);
}

extern const double DAT_010c9300;
extern const double DAT_010cb420;

inline float capsuleAbs(float value)
{
    return fabs(value);
}
__forceinline float capsuleSqrt(float value)
{
    return (float)sqrt((double)value);
}

class ManifoldScalar
{
    LocalM128 value;

  public:
    ManifoldScalar(const LocalM128& x) : value(x)
    {}
    ManifoldScalar(float x)
    {
        value = _mm_load_ss(&x);
    }
    ManifoldScalar()
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const LocalM128& getQuad() const
    {
        return value;
    }
};

class ManifoldVector
{
    LocalM128 value;

  public:
    __forceinline void operator=(const ManifoldVector& source)
    {
        value = source.value;
    }
    __forceinline void operator=(const LocalM128& source)
    {
        value = source;
    }
    operator LocalM128() const
    {
        return value;
    }
    __forceinline LocalM128& getQuad()
    {
        return value;
    }
    __forceinline const LocalM128& getQuad() const
    {
        return value;
    }
    __forceinline float& operator()(int index)
    {
        return value.m128_f32[index];
    }
    __forceinline const float& operator()(int index) const
    {
        return value.m128_f32[index];
    }
    __forceinline void setSub4(const ManifoldVector& a, const ManifoldVector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setNeg4(const ManifoldVector& a)
    {
        value = _mm_xor_ps(a.value, DAT_010c44d0);
    }
    __forceinline void setZero4()
    {
        value = _mm_setzero_ps();
    }
    __forceinline ManifoldScalar dot3(const ManifoldVector& other) const
    {
        LocalM128 product = _mm_mul_ps(value, other.value);
        LocalM128 partial = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), partial);
    }
    __forceinline ManifoldScalar length3() const
    {
        return _mm_sqrt_ss(dot3(*this).getQuad());
    }
    __forceinline void setAddMul4(const ManifoldVector& base, const ManifoldVector& direction,
                                  const ManifoldScalar& factor)
    {
        value = _mm_add_ps(base.value, _mm_mul_ps(factor.broadcast(), direction.value));
    }
    __forceinline void addMul4(const ManifoldScalar& factor, const ManifoldVector& direction)
    {
        value = _mm_add_ps(value, _mm_mul_ps(factor.broadcast(), direction.value));
    }
    __forceinline void mul4(const ManifoldScalar& factor)
    {
        value = _mm_mul_ps(factor.broadcast(), value);
    }
    __forceinline ManifoldScalar lengthInverse3() const
    {
        const LocalM128 half = _mm_set_ss(0.5f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 square = dot3(*this).getQuad();
        const LocalM128 empty = _mm_cmpeq_ss(square, zero);
        const LocalM128 estimate = _mm_rsqrt_ss(square);
        const LocalM128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, estimate), estimate)));
        return _mm_andnot_ps(empty, refined);
    }
    __forceinline void normalize3()
    {
        LocalM128 inverse = lengthInverse3().broadcast();
        value = _mm_mul_ps(inverse, value);
    }
};
class ManifoldContact
{
    ManifoldVector position, normal;

  public:
    __forceinline const ManifoldVector& getNormal() const
    {
        return normal;
    }
    __forceinline ManifoldVector& getPosition()
    {
        return position;
    }
    __forceinline ManifoldVector& getSeparatingNormal()
    {
        return normal;
    }
    __forceinline float getDistance() const
    {
        return normal(3);
    }
    __forceinline void setDistance(float distance)
    {
        normal(3) = distance;
    }
};

inline float maxDistance(float a, float b)
{
    return a > b ? a : b;
}
struct RadiusInput
{
    float value;
};
inline float addRadii(const float& a, const float& b)
{
    return a + b;
}
// Computes the closest points between two capsules defined by endpoints and radii, writing contact normals and positions into points.
// @fnv 0x00cd58b0
// src: XBOX_PDB 0x00cd58b0
int __cdecl hkCollideCapsuleUtilManifoldCapsVsCaps(const ManifoldVector* apFirstSegment, RadiusInput firstRadius,
                         const ManifoldVector* apSecondSegment, RadiusInput secondRadius,
                         ManifoldContact* apContactPoints)
{

    LocalM128 q;

    ManifoldVector directionA;
    directionA.setSub4(apFirstSegment[1], apFirstSegment[0]);

    ManifoldVector directionB;
    directionB.setSub4(apSecondSegment[1], apSecondSegment[0]);

    float cosine = directionB.dot3(directionA);

    ManifoldVector endpointsA[2];

    if (cosine < 0.0f)
    {

        cosine = -cosine;
        directionA.setNeg4(directionA);

        endpointsA[0] = apFirstSegment[1];
        endpointsA[1] = apFirstSegment[0];
    }
    else
    {
        endpointsA[0] = apFirstSegment[0];
        endpointsA[1] = apFirstSegment[1];
    }

    ManifoldVector offset;
    offset.setSub4(apSecondSegment[0], endpointsA[0]);

    float projectionA = directionA.dot3(offset);

    float projectionB = offset.dot3(directionB);

    float lengthA = directionA.dot3(directionA);

    float lengthB = directionB.dot3(directionB);

    float determinant = capsuleAbs(lengthA * lengthB - cosine * cosine);

    float alongA = projectionA * lengthB - cosine * projectionB;

    int features;

    if (alongA * determinant >= determinant * determinant)
    {
        alongA = 1.0f;
        features = 1;
    }

    else if (alongA <= 0.0f)
    {
        alongA = 0.0f;
        features = 2;
    }

    else
    {
        float threshold = (capsuleAbs(lengthA * lengthB) + cosine * cosine) * DAT_010cb420;
        if (determinant > threshold)
        {
            alongA /= determinant;
            features = 0;
        }
        else
        {
            alongA = 1.0f;
            features = 1;
        }
    }

    float alongB = alongA * cosine - projectionB;

    if (lengthB <= alongB)
    {
        alongB = 1.0f;
        features = 4;
    }

    else if (alongB <= 0.0f)
    {
        alongB = 0.0f;
        features = 8;
    }

    else
    {
        alongB /= lengthB;
        goto closestReady;
    }

    alongA = cosine * alongB + projectionA;

    if (alongA <= 0.0f)
    {
        alongA = 0.0f;
        features |= 2;
    }

    else if (alongA >= lengthA)
    {
        alongA = 1.0f;
        features |= 1;
    }

    else
    {
        alongA /= lengthA;
    }

closestReady:

{

    ManifoldVector a;

    a.setAddMul4(endpointsA[0], directionA, alongA);

    ManifoldVector b;

    b.setAddMul4(apSecondSegment[0], directionB, alongB);

    ManifoldVector difference;
    difference.setSub4(a, b);

    const float radiusSum = addRadii(firstRadius.value, secondRadius.value);

    float referenceDistance = maxDistance(1.1920928955078125e-7f, apContactPoints->getDistance());

    float distance = difference.length3();

    float inverseDistance = 1.0f / distance;

    float contactDistance = distance - radiusSum;

    apContactPoints->getSeparatingNormal() = difference;

    if (contactDistance < referenceDistance)
    {

        if (distance < DAT_0104da4c)
        {

            distance = 0.0f;

            int least = 0, firstAxis = 1, secondAxis = 2;

            float x = capsuleAbs(directionA(0));

            float y = capsuleAbs(directionA(1));

            float z = capsuleAbs(directionA(2));

            if (y < x)
            {
                firstAxis = 0;
                least = 1;
                x = y;
            }

            if (z < x)
            {
                secondAxis = least;
                least = 2;
            }

            apContactPoints->getSeparatingNormal().setZero4();

            apContactPoints->getSeparatingNormal()(firstAxis) = directionA(secondAxis);

            apContactPoints->getSeparatingNormal()(secondAxis) = -directionA(firstAxis);

            apContactPoints->getSeparatingNormal().normalize3();
        }
        else
        {
            apContactPoints->getSeparatingNormal().mul4(inverseDistance);
        }

        {
            float offset = secondRadius.value - distance;
            q = _mm_load_ss(&offset);
            apContactPoints->getPosition().getQuad() = _mm_add_ps(
                a.getQuad(), _mm_mul_ps(_mm_shuffle_ps(q, q, 0), apContactPoints->getSeparatingNormal().getQuad()));
        }

        apContactPoints->getSeparatingNormal()(3) = contactDistance;
    }
    else
    {
        apContactPoints->getSeparatingNormal().mul4(inverseDistance);
        apContactPoints->getSeparatingNormal()(3) = contactDistance;
        return features;
    }
}

    if (determinant > double(0.2f) * lengthA * lengthB)
    {
        return features;
    }

    const float inverseProduct = 1.0f / (lengthA * lengthB);

    const float inverseA = lengthB * inverseProduct;

    const float inverseB = lengthA * inverseProduct;

    float onB = -projectionB;

    float onA = projectionA;

    ManifoldVector endpointA = endpointsA[0];

    ManifoldVector endpointB = apSecondSegment[0];

    ManifoldContact* pContactPoint = apContactPoints + 1;

    int pass = 0;

    int mask = 10;

    for (;;)
    {

        if (!(features & mask))
        {

            if (onB > 0.0f)
            {

                if (lengthB < onB)
                    goto nextEndpoint;

                if (onA > 0.0f)
                {

                    if (onA > lengthA)
                        goto nextEndpoint;

                    if (onB * onB * inverseB > onA * onA * inverseA)
                    {
                        endpointA.addMul4(onA * inverseA, directionA);
                    }

                    else
                    {
                        endpointB.addMul4(onB * inverseB, directionB);
                    }
                }
                else
                {
                    endpointB.addMul4(onB * inverseB, directionB);
                }
            }
            else if (onA > 0.0f)
            {

                if (lengthA < onA)
                    goto nextEndpoint;

                endpointA.addMul4(onA * inverseA, directionA);
            }

            ManifoldVector delta;
            delta.setSub4(endpointA, endpointB);

            const float radiusSumCopy = addRadii(firstRadius.value, secondRadius.value);

            const float limit = pContactPoint->getSeparatingNormal()(3) + radiusSumCopy;

            float squareDistance = delta.dot3(delta);

            if (squareDistance < limit * limit)
            {

                float d = sqrt(squareDistance);

                pContactPoint->getSeparatingNormal() = delta;

                if (squareDistance > 1.1920928955078125e-7f)
                {
                    pContactPoint->getSeparatingNormal().normalize3();
                }

                else
                {
                    pContactPoint->getSeparatingNormal() = apContactPoints->getSeparatingNormal();
                }

                {
                    float offset = secondRadius.value - d;
                    q = _mm_load_ss(&offset);
                    pContactPoint->getPosition().getQuad() =
                        _mm_add_ps(endpointA.getQuad(),
                                   _mm_mul_ps(_mm_shuffle_ps(q, q, 0), pContactPoint->getSeparatingNormal().getQuad()));
                }

                pContactPoint->getSeparatingNormal()(3) = d - radiusSumCopy;
            }
        }

    nextEndpoint:

        if (pass == 1)
            return features;

        endpointA = endpointsA[1];
        endpointB = apSecondSegment[1];

        onB = lengthB - onB - cosine;

        onA = lengthA - onA - cosine;

        directionA.setNeg4(directionA);
        directionB.setNeg4(directionB);

        ++pContactPoint;
        ++pass;
        mask = 5;
    }

    return features;
}

extern const LocalM128 DAT_010ec7f0, DAT_01267e30;
extern const signed char DAT_010cb440[3], DAT_010cb442[3];

class ContactScalar
{
    LocalM128 scalar;

  public:
    ContactScalar()
    {}
    ContactScalar(const LocalM128& v) : scalar(v)
    {}
    ContactScalar(float v)
    {
        scalar = _mm_load_ss(&v);
    }
    operator float() const
    {
        float v;
        _mm_store_ss(&v, scalar);
        return v;
    }
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(scalar, scalar, 0);
    }
    __forceinline const LocalM128& quad() const
    {
        return scalar;
    }
};
class ContactCompare
{
  public:
    enum
    {
        MASK_X = 1,
        MASK_Y = 2,
        MASK_Z = 4,
        MASK_W = 8
    };
    LocalM128 lanes;
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(lanes);
    }
    __forceinline int anyIsSet() const
    {
        return GetLaneMask();
    }
    __forceinline void setAnd(const ContactCompare& a, const ContactCompare& b)
    {
        lanes = _mm_and_ps(a.lanes, b.lanes);
    }
};
class ContactVector
{
    LocalM128 values;

  public:
    __forceinline void operator=(const ContactVector& a)
    {
        values = a.values;
    }
    __forceinline void operator=(const LocalM128& a)
    {
        values = a;
    }
    __forceinline operator LocalM128() const
    {
        return values;
    }
    __forceinline LocalM128& getQuad()
    {
        return values;
    }
    __forceinline const LocalM128& getQuad() const
    {
        return values;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&values)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&values)[i];
    }
    __forceinline void set(float x, float y, float z, float w = 0.0f)
    {
        values = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(float x)
    {
        values = _mm_set_ps1(x);
    }
    __forceinline void setZero4()
    {
        values = _mm_setzero_ps();
    }
    __forceinline void setSub4(const ContactVector& a, const ContactVector& b)
    {
        values = _mm_sub_ps(a.values, b.values);
    }
    __forceinline void setNeg4(const ContactVector& a)
    {
        values = _mm_xor_ps(a.values, DAT_010c44d0);
    }
    __forceinline void mul4(const ContactScalar& scale)
    {
        values = _mm_mul_ps(scale.splat(), values);
    }
    __forceinline void setAddMul4(const ContactVector& a, const ContactVector& b, const ContactScalar& scale)
    {
        values = _mm_add_ps(a.values, _mm_mul_ps(scale.splat(), b.values));
    }
    __forceinline void setCross(const ContactVector& a, const ContactVector& b)
    {
        LocalM128 left = _mm_mul_ps(_mm_shuffle_ps(a.values, a.values, 0xc9), _mm_shuffle_ps(b.values, b.values, 0xd2));
        LocalM128 right = _mm_mul_ps(_mm_shuffle_ps(a.values, a.values, 0xd2), _mm_shuffle_ps(b.values, b.values, 0xc9));
        values = _mm_sub_ps(left, right);
    }
    __forceinline void setInterpolate4(const ContactVector& a, const ContactVector& b, const ContactScalar& scale)
    {
        LocalM128 factor = scale.splat();
        LocalM128 other = _mm_sub_ps(DAT_010ec7f0, factor);
        values = _mm_add_ps(_mm_mul_ps(other, a.values), _mm_mul_ps(factor, b.values));
    }
    __forceinline ContactCompare compareLessThan4(const ContactVector& b) const
    {
        ContactCompare c;
        c.lanes = _mm_cmplt_ps(values, b.values);
        return c;
    }
    __forceinline ContactCompare compareLessThanZero4() const
    {
        ContactVector z;
        z.setZero4();
        return compareLessThan4(z);
    }
    __forceinline int allLessThan3(const ContactVector& b) const
    {
        return (_mm_movemask_ps(_mm_cmplt_ps(values, b.values)) & 7) == 7;
    }
    __forceinline static const ContactVector& getZero()
    {
        return reinterpret_cast<const ContactVector&>(DAT_01267e30);
    }
    __forceinline ContactScalar dot3(const ContactVector& b) const
    {
        LocalM128 product = _mm_mul_ps(values, b.values);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    }
    __forceinline ContactScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline ContactScalar inverseLength3() const
    {
        LocalM128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        LocalM128 square = dot3(*this).quad();
        LocalM128 empty = _mm_cmpeq_ss(square, zero);
        LocalM128 estimate = _mm_rsqrt_ss(square);
        LocalM128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, estimate), estimate));
        LocalM128 result = _mm_mul_ss(_mm_mul_ss(half, estimate), correction);
        return _mm_andnot_ps(empty, result);
    }
    __forceinline void normalize3()
    {
        LocalM128 inverse = inverseLength3().splat();
        values = _mm_mul_ps(inverse, values);
    }
};
class ContactMatrix
{
    ContactVector columns[3];

  public:
    __forceinline ContactVector& getColumn(int i)
    {
        return columns[i];
    }
    __forceinline const ContactVector& getColumn(int i) const
    {
        return columns[i];
    }
    __forceinline void getRow(int i, ContactVector& out) const
    {
        out.set(columns[0](i), columns[1](i), columns[2](i));
    }
};
class ContactRotation : public ContactMatrix
{
};
class ContactTransform
{
    ContactRotation rotation;
    ContactVector translation;

  public:
    ContactTransform()
    {}
    __forceinline ContactVector& getColumn(int i)
    {
        return i == 3 ? translation : rotation.getColumn(i);
    }
    __forceinline const ContactVector& getColumn(int i) const
    {
        return i == 3 ? translation : rotation.getColumn(i);
    }
    __forceinline ContactRotation& getRotation()
    {
        return rotation;
    }
    __forceinline const ContactRotation& getRotation() const
    {
        return rotation;
    }
    __forceinline const ContactVector& getTranslation() const
    {
        return translation;
    }
    __forceinline float& operator()(int row, int col)
    {
        return getColumn(col)(row);
    }
};
static __forceinline void projectOne(ContactVector& out, const ContactTransform& t, const ContactVector& in)
{
    const ContactRotation& r = t.getRotation();
    LocalM128 x = _mm_shuffle_ps(in.getQuad(), in.getQuad(), 0);
    LocalM128 a = _mm_mul_ps(r.getColumn(0).getQuad(), x);
    LocalM128 y = _mm_shuffle_ps(in.getQuad(), in.getQuad(), 0x55);
    LocalM128 b = _mm_mul_ps(r.getColumn(1).getQuad(), y);
    LocalM128 z = _mm_shuffle_ps(in.getQuad(), in.getQuad(), 0xaa);
    LocalM128 c = _mm_mul_ps(r.getColumn(2).getQuad(), z);
    out = _mm_add_ps(_mm_add_ps(a, b), _mm_add_ps(c, t.getTranslation().getQuad()));
}
static __forceinline void projectPoints(const ContactTransform& transform, const ContactVector* in, int count,
                                        ContactVector* out)
{
    ContactTransform local = transform;
    int i = count - 1;
    do
    {
        projectOne(out[i], local, in[i]);
    } while (--i >= 0);
}
class ContactRecord
{
    ContactVector position, normal;

  public:
    __forceinline ContactVector& getPosition()
    {
        return position;
    }
    __forceinline const ContactVector& getPosition() const
    {
        return position;
    }
    __forceinline ContactVector& getSeparatingNormal()
    {
        return normal;
    }
    __forceinline const ContactVector& getSeparatingNormal() const
    {
        return normal;
    }
    __forceinline const ContactVector& getNormal() const
    {
        return normal;
    }
    __forceinline float getDistance() const
    {
        return normal(3);
    }
    __forceinline void setDistance(float f)
    {
        normal(3) = f;
    }
};
template <class T> class ContactCell
{
    T value;

  public:
    ContactCell()
    {}
    ContactCell(T x) : value(x)
    {}
    __forceinline void operator=(T x)
    {
        value = x;
    }
    __forceinline operator T() const
    {
        return value;
    }
};
struct ContactClosest
{
    ContactVector m_kFirstVector, m_kClosestPointOnSecond;
    ContactCell<float> m_fValue;
};
struct Feature
{
    unsigned char count;
    unsigned short first, second, third;
};
int hkLineSegmentUtil_closestLineSegLineSeg(const ContactVector&, const ContactVector&, const ContactVector&, const ContactVector&,
                 ContactClosest&);
unsigned int hkCollideCapsuleUtilManifoldCapsVsCaps(const ContactVector*, float, const ContactVector*, float, ContactRecord*);
__forceinline float localAbs(float f)
{
    return fabs(f);
}
__forceinline float localSqrt(float f)
{
    return sqrt(f);
}

static __forceinline LocalM128 splatScalar(float f)
{
    LocalM128 t = _mm_load_ss(&f);
    return _mm_shuffle_ps(t, t, 0);
}
static __forceinline void makePlanes(const ContactVector* v, const float* cache, ContactTransform& t,
                                     ContactVector& normal)
{
    ContactVector e0, e1, e2, n;
    e0.setSub4(v[2], v[1]);
    e1.setSub4(v[0], v[2]);
    e2.setSub4(v[1], v[0]);
    n.setCross(e0, e1);
    n.mul4(cache[3]);
    normal = n;
    e0.mul4(cache[0]);
    e1.mul4(cache[1]);
    e2.mul4(cache[2]);
    t.getColumn(0).setCross(e0, n);
    t.getColumn(1).setCross(e1, n);
    t.getColumn(2).setCross(e2, n);
    {
        float tmp = t(0, 1);
        t(0, 1) = t(1, 0);
        t(1, 0) = tmp;
    }
    {
        float tmp = t(0, 2);
        t(0, 2) = t(2, 0);
        t(2, 0) = tmp;
    }
    {
        float tmp = t(1, 2);
        t(1, 2) = t(2, 1);
        t(2, 1) = tmp;
    }
    t(3, 0) = normal(0);
    t(3, 1) = normal(1);
    t(3, 2) = normal(2);
    t.getColumn(3).setZero4();
    t(0, 3) = -cache[0] * cache[4];
}
// Tests a capsule (two positions, radius, thickness) against a triangle, filling up to three ContactRecords and optional Feature data.
// @fnv 0x00cd6520
// src: XBOX_PDB 0x00cd6520
void __cdecl hkCollideCapsuleUtilCapsVsTri(const ContactVector* positions, float radius, const ContactVector* triangle, float thickness,
                          const float* orientation, float margin, int useFaces, ContactRecord* contacts,
                          Feature* feature)
{
    if (feature)
        for (int k = 0; k < 3; ++k)
            feature[k].count = 0;
    ContactTransform planes;
    ContactVector normal;
    makePlanes(triangle, orientation, planes, normal);
    ContactVector distances[2];
    distances[0].setSub4(positions[0], triangle[0]);
    distances[1].setSub4(positions[1], triangle[0]);
    projectPoints(planes, distances, 2, distances);
    float radiusSum = radius + thickness;
    float expanded = radiusSum + margin;
    const float largeDistance = 3.40282e38f;
    contacts[0].setDistance(largeDistance);
    contacts[1].setDistance(largeDistance);
    contacts[2].setDistance(largeDistance);
    {
        ContactVector limit;
        limit.SetAllComponents(expanded);
        ContactCompare c0 = limit.compareLessThan4(distances[0]);
        ContactCompare c1 = limit.compareLessThan4(distances[1]);
        ContactCompare both;
        both.setAnd(c0, c1);
        if (both.anyIsSet() || (distances[0](3) < -expanded && distances[1](3) < -expanded))
            return;
    }
    ContactCell<int> signs[2];
    signs[0] = distances[0].compareLessThanZero4().GetLaneMask();
    signs[1] = distances[1].compareLessThanZero4().GetLaneMask();
    if ((signs[0] ^ signs[1]) & ContactCompare::MASK_W)
    {
        float t = distances[0](3) / (distances[0](3) - distances[1](3));
        ContactVector hit;
        hit.setInterpolate4(distances[0], distances[1], t);
        if (hit.allLessThan3(ContactVector::getZero()))
        {
            ContactRecord* pContact = contacts + 1;
            pContact->setDistance(-3.40282e38f);
            for (int i = 0; i < 2; ++i)
            {
                if ((signs[i] & (ContactCompare::MASK_X | ContactCompare::MASK_Y | ContactCompare::MASK_Z)) ==
                    (ContactCompare::MASK_X | ContactCompare::MASK_Y | ContactCompare::MASK_Z))
                {
                    float d = -localAbs(distances[i](3)) - radiusSum;
                    if (d > pContact->getDistance())
                    {
                        if (signs[i] & ContactCompare::MASK_W)
                        {
                            pContact->getSeparatingNormal() = normal;
                            pContact->getPosition().setAddMul4(positions[i], normal, thickness - distances[i](3));
                        }
                        else
                        {
                            pContact->getSeparatingNormal().setNeg4(normal);
                            pContact->getPosition().setAddMul4(positions[i], normal, -thickness - distances[i](3));
                        }
                        pContact->setDistance(d);
                    }
                }
            }
            ContactVector direction;
            direction.setSub4(distances[1], distances[0]);
            for (int e = 0; e < 3; ++e)
            {
                float dw = direction(3), di = direction(e);
                float len = dw * dw + di * di;
                float inv = 1.0f / len;
                float d = di * distances[0](3) - dw * distances[0](e);
                float sq = d * d * inv;
                float maxDist = pContact->getDistance() + radiusSum;
                if (sq < maxDist * maxDist)
                {
                    float project = di * distances[0](e) + dw * distances[0](3);
                    project = -inv * project;
                    if (project > -0.0001f && project < 1.0001f)
                    {
                        ContactVector row;
                        planes.getRotation().getRow(e, row);
                        if (dw < 0)
                        {
                            dw = -dw;
                            di = -di;
                        }
                        pContact->getSeparatingNormal() = _mm_add_ps(_mm_mul_ps(splatScalar(-di), normal.getQuad()),
                                                                     _mm_mul_ps(splatScalar(dw), row.getQuad()));
                        pContact->getSeparatingNormal().normalize3();
                        ContactVector pos;
                        pos.setInterpolate4(positions[0], positions[1], project);
                        float depth = -localSqrt(sq);
                        pContact->getPosition().setAddMul4(pos, pContact->getNormal(), thickness - depth);
                        pContact->setDistance(depth - radiusSum);
                    }
                }
            }
            for (int k = 0; k < 3; ++k)
                if (feature)
                {
                    feature[k].count = 3;
                    feature[k].first = 0;
                    feature[k].second = 1;
                    feature[k].third = 2;
                }
            return;
        }
    }
    int endpoint = 0;
    ContactVector worldDirection;
    worldDirection.setSub4(positions[1], positions[0]);
    ContactRecord* pContact = contacts;
    bool segmentMode = false;
    if (((signs[0] | signs[1]) & (ContactCompare::MASK_X | ContactCompare::MASK_Y | ContactCompare::MASK_Z)) !=
        (ContactCompare::MASK_X | ContactCompare::MASK_Y | ContactCompare::MASK_Z))
    {
        if (useFaces)
        {
            int combined = signs[0] | signs[1];
            const float tolerance = margin;
            contacts[0].setDistance(tolerance);
            contacts[1].setDistance(tolerance);
            contacts[2].setDistance(tolerance);
            ContactRecord previous;
            previous.getSeparatingNormal()(3) = 3.40282e38f;
            ContactVector pair[2];
            int mask = ContactCompare::MASK_X;
            for (int j = 0; j < 3; mask = ContactCompare::MASK_X == 1 ? mask << 1 : mask >> 1, j++)
            {
                if (mask & combined)
                    continue;
                int left = DAT_010cb442[j], right = DAT_010cb440[j];
                pair[0] = triangle[left];
                pair[1] = triangle[right];
                int kind = hkCollideCapsuleUtilManifoldCapsVsCaps(positions, radius, pair, thickness, contacts);
                if (feature)
                    for (int k = 0; k < 3; ++k)
                    {
                        feature[k].first = (unsigned short)left;
                        if (kind & 12)
                            feature[k].count = 1;
                        else
                        {
                            feature[k].count = 2;
                            feature[k].second = (unsigned short)right;
                        }
                    }
                if (contacts[0].getSeparatingNormal()(3) > previous.getSeparatingNormal()(3))
                    contacts[0] = previous;
                else
                    previous = contacts[0];
            }
            return;
        }
        else
        {
            segmentMode = true;
            goto edges;
        }
    }
    for (; endpoint < 2; ++pContact, ++endpoint)
    {
        if ((signs[endpoint] & (ContactCompare::MASK_X | ContactCompare::MASK_Y | ContactCompare::MASK_Z)) ==
            (ContactCompare::MASK_X | ContactCompare::MASK_Y | ContactCompare::MASK_Z))
        {
            if (signs[endpoint] & ContactCompare::MASK_W)
            {
                pContact->getPosition().setAddMul4(positions[endpoint], normal, -thickness - distances[endpoint](3));
                pContact->getSeparatingNormal().setNeg4(normal);
                pContact->setDistance(-distances[endpoint](3) - radiusSum);
            }
            else
            {
                pContact->getPosition().setAddMul4(positions[endpoint], normal, thickness - distances[endpoint](3));
                pContact->getSeparatingNormal() = normal;
                pContact->setDistance(distances[endpoint](3) - radiusSum);
            }
            if (feature)
            {
                feature[endpoint].count = 3;
                feature[endpoint].first = 0;
                feature[endpoint].second = 1;
                feature[endpoint].third = 2;
            }
        }
        else
        {
        edges:
            int mask = ContactCompare::MASK_X;
            for (int e = 0; e < 3; mask = ContactCompare::MASK_X == 1 ? mask << 1 : mask >> 1, e++)
            {
                if (!segmentMode)
                {
                    if (signs[endpoint] & mask)
                        continue;
                }
                else
                {
                    if (signs[0] & signs[1] & mask)
                        continue;
                }
                int left = DAT_010cb440[e], right = DAT_010cb442[e];
                const ContactVector& trianglePoint = triangle[right];
                ContactVector edge;
                edge.setSub4(triangle[left], trianglePoint);
                ContactClosest closest;
                int kind = hkLineSegmentUtil_closestLineSegLineSeg(positions[0], worldDirection, trianglePoint, edge, closest);
                if (feature)
                {
                    feature[endpoint].first = (unsigned short)right;
                    if (kind & 12)
                        feature[endpoint].count = 1;
                    else
                    {
                        feature[endpoint].count = 2;
                        feature[endpoint].second = (unsigned short)left;
                    }
                }
                float limit = pContact->getDistance() + radiusSum;
                float squareLimit = limit * limit;
                if (closest.m_fValue < squareLimit)
                {
                    if ((1 << endpoint) & kind)
                    {
                        if (segmentMode)
                            endpoint = 1;
                        else
                            continue;
                    }
                    ContactVector n;
                    if (kind == 0)
                        n.setCross(worldDirection, edge);
                    else if (closest.m_fValue <= 1.4210854715202004e-14)
                    {
                        planes.getRotation().getRow(e, closest.m_kClosestPointOnSecond);
                        n.setCross(worldDirection, edge);
                        if (n.lengthSquared3() <= 1.4210854715202004e-14)
                            n = closest.m_kClosestPointOnSecond;
                    }
                    else
                        n = closest.m_kClosestPointOnSecond;
                    n.normalize3();
                    float d = closest.m_kClosestPointOnSecond.dot3(n);
                    if (d < 0)
                    {
                        d = -d;
                        n.setNeg4(n);
                    }
                    pContact->getPosition().setAddMul4(closest.m_kFirstVector, n, thickness - d);
                    pContact->getSeparatingNormal() = n;
                    pContact->setDistance(d - radiusSum);
                }
            }
        }
        if (segmentMode)
            break;
    }
}
