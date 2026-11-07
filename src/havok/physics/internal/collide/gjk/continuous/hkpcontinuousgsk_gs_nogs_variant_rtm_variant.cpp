#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpAgent3Input.h"
#include <xmmintrin.h>
#include <math.h>
#include <string.h>
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/QuantizedFloat8.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkContactPointMaterial.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../include/hkSweptTransform.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"

// Havok-style bisection: find the sample time t where the support distance along the target plane reaches target.
struct __declspec(align(16)) Sample
{
    unsigned int d[76];
};
struct Out
{
    float t;
    float u[3];
    __m128 pos;
};
void hkTransform_setMulInverseMul_UpdateState_00db4b50(void* a, float t, Sample* out);
extern const double DAT_010290b0;
// 0.5
extern const double DAT_0101ffa0;
// 0.1
extern const float DAT_0101e2bc;
// 0.1f
extern const double DAT_0106b9e8;
// 0.9
extern const float DAT_010177e8;
float Object_ProcessEntries_00db4ca0(void* a, const float* target, const __m128* origin, float A, float B, float C, float D, int unused,
                   Out* res);

// Preserve the original forced-inline wrapper used by this unit. The shared
// hkStackMemory header supplies a separate hkPadSpu template.
template <typename TYPE> class GskValue
{
  public:
    __forceinline GskValue()
    {}
    __forceinline GskValue(TYPE e) : m_kStorage(e)
    {}
    __forceinline void operator=(TYPE e)
    {
        m_kStorage = e;
    }
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }
    __forceinline TYPE operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE m_kStorage;
};

typedef float hkReal;
typedef float hkTime;
typedef __m128 hkQuadReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef hkUint16 hkpVertexId;

extern "C" __declspec(align(16)) const hkUint32 DAT_010c4c00[4];
extern "C" __declspec(align(16)) const hkUint32 DAT_010c44d0[4];
extern "C" __declspec(align(16)) const float DAT_010ec7f0[4];
extern "C" const float DAT_010d5384;

extern void* __cdecl hkMemoryRouter_getInstance();





__forceinline hkSimdReal::hkSimdReal(const hkQuadReal& x) : m_vValue(x)
{}

__forceinline hkSimdReal::hkSimdReal(hkReal x)
{
    m_vValue = _mm_load_ss(&x);
}

__forceinline hkSimdReal::hkSimdReal()
{}

__forceinline hkSimdReal::operator hkReal() const
{
    hkReal s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

__forceinline hkQuadReal hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline const hkQuadReal& hkSimdReal::getQuad() const
{
    return m_vValue;
}
typedef const hkSimdReal& hkSimdRealParameter;

namespace MathUtilities {
template <typename T> __forceinline T min2(T x, T y)
{
    return x < y ? x : y;
}
template <typename T> __forceinline T max2(T x, T y)
{
    return x > y ? x : y;
}
__forceinline hkReal fabs(hkReal r)
{
    return ::fabsf(r);
}
__forceinline hkBool equal(hkReal x, hkReal y, hkReal tolerance2)
{
    return MathUtilities::fabs(x - y) < tolerance2;
}
}



__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::sub4(const hkVector4& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void hkVector4::setNeg3(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const hkQuadReal*)&DAT_010c4c00);
}

__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const hkQuadReal*)&DAT_010c44d0);
}

__forceinline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}

__forceinline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}

__forceinline void hkVector4::subMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, hkSimdRealParameter r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}

__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    hkQuadReal cross0;
    cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
    hkQuadReal cross1;
    cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter _t)
{
    hkQuadReal t = _t.broadcast();
    hkQuadReal s = _mm_sub_ps(*(const hkQuadReal*)&DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}

__forceinline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    else if (i == 3)
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
}

__forceinline hkSimdReal hkVector4::getSimdAt(int i) const
{
    switch (i)
    {
    case 0:
        return m_vComponents;
    case 1:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    case 2:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    case 3:
    default:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    }
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
}

__forceinline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    hkQuadReal zwSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)),
                                  _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3)));
    return _mm_add_ps(xySum, zwSum);
}

__forceinline hkSimdReal hkVector4::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}

__forceinline hkReal& hkVector4::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}

__forceinline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}

__forceinline int hkVector4::getInt24W() const
{
    return (reinterpret_cast<const hkUint32*>(this))[3] & ~0x3f000000;
}

__forceinline void hkVector4::SetTransformedPoint(const hkTransform& a, const hkVector4& b)
{
    setTransformedPos_00c7f640(a, b);
}

__forceinline void hkVector4::SetRotatedDirection(const hkRotation& a, const hkVector4& b)
{
    hkVector4_setRotatedDir(a, b);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkRotation& a, const hkVector4& b)
{
    hkVector4_setRotatedInverseDir(a, b);
}

__forceinline hkMatrix3::hkMatrix3()
{}

__forceinline hkVector4& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}

__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
__forceinline hkRotation::hkRotation()
{}
__forceinline const hkVector4& hkRotation::getColumn(int i) const
{
    return (&m_kColumn0)[i];
}

__forceinline hkTransform::hkTransform()
{}

__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    // Copy all four contiguous columns with the original inlined column access.
    const hkVector4 r0 = reinterpret_cast<const hkMatrix3&>(t).getColumn(0);
    const hkVector4 r1 = reinterpret_cast<const hkMatrix3&>(t).getColumn(1);
    const hkVector4 r2 = reinterpret_cast<const hkMatrix3&>(t).getColumn(2);
    const hkVector4 r3 = reinterpret_cast<const hkMatrix3&>(t).getColumn(3);
    reinterpret_cast<hkMatrix3&>(*this).getColumn(0) = r0;
    reinterpret_cast<hkMatrix3&>(*this).getColumn(1) = r1;
    reinterpret_cast<hkMatrix3&>(*this).getColumn(2) = r2;
    reinterpret_cast<hkMatrix3&>(*this).getColumn(3) = r3;
}

__forceinline hkRotation& hkTransform::getRotation()
{
    return *reinterpret_cast<hkRotation*>(this);
}

__forceinline const hkRotation& hkTransform::getRotation() const
{
    return *reinterpret_cast<const hkRotation*>(this);
}

__forceinline const hkVector4& hkTransform::getTranslation() const
{
    return reinterpret_cast<const hkVector4*>(this)[3];
}

__forceinline void hkTransform::SetMulInverse(const hkTransform& a, const hkTransform& b)
{
    hkTransform_setMulInverseMul(a, b);
}

__forceinline void hkVector4::_setMul3(const hkRotation& a, const hkVector4& b)
{
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    const hkQuadReal r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    const hkQuadReal r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    const hkQuadReal r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    hkQuadReal c0 = r.getColumn(0).m_vComponents;
    hkQuadReal c1 = r.getColumn(1).m_vComponents;
    hkQuadReal c2 = r.getColumn(2).m_vComponents;
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, _MM_SHUFFLE(3, 1, 1, 0));
        c2 = _ctmp;
    }
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}
__forceinline void hkVector4::_setTransformedInversePos(const hkTransform& a, const hkVector4& b)
{
    hkVector4 t0;
    t0.setSub4(b, a.getTranslation());
    _setRotatedInverseDir(a.getRotation(), t0);
}

// Keep the original inlined operations for overloads exposed by the shared API.
__forceinline hkVector4::hkVector4(const hkVector4& v)
{
    memcpy(this, &v, sizeof(*this));
}

__forceinline hkContactPoint& hkContactPoint::operator=(const hkContactPoint& p)
{
    m_vContactPosition = p.m_vContactPosition;
    m_vSeparatingNormal = p.m_vSeparatingNormal;
    return *this;
}

class Vector4WithInt24W : public hkVector4
{
  public:
    __forceinline int GetValueForType() const
    {
        return getInt24W();
    }
};

__forceinline hkReal hkSweptTransform::getBaseTime() const
{
    return m_vCenterOfMass0(3);
}

__forceinline hkReal hkSweptTransform::getInvDeltaTime() const
{
    return m_vCenterOfMass1(3);
}

__forceinline hkReal hkSweptTransform::getInterpolationValue(hkTime t) const
{
    hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
    return dt;
}
__forceinline const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}

namespace MotionUtilities {
__forceinline void calcAngularTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                      hkVector4* __restrict deltaAngleOut0, hkVector4* __restrict deltaAngleOut1)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    hkVector4 ang0;
    ang0.setMul4(hkSimdReal(f0), ms0.m_kDeltaAngle);
    hkVector4 ang1;
    ang1.setMul4(hkSimdReal(f1), ms1.m_kDeltaAngle);
    deltaAngleOut0[0] = ang0;
    deltaAngleOut1[0] = ang1;
}
}
void hkSweptTransform_ComputeValues_00cf1710(const hkSweptTransform& a, hkTime b, hkReal c, hkTransform& out);

__forceinline int hkpConvexShape::getNumCollisionSpheres() const
{
    return GetNumCollisionSpheres();
}

__forceinline const hkSphere* hkpConvexShape::getCollisionSpheres(hkSphere* sphereBuffer) const
{
    return GetCollisionSpheres(sphereBuffer);
}

__forceinline void hkpConvexShape::GetVerticesForIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* vertices) const
{
    GetVerticesFromIds(ids, numIds, vertices);
}

__forceinline hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                                              hkVector4& contactPointWs, const hkTransform* thisObjTransform,
                                              const hkpConvexShape* collidingShape,
                                              const hkTransform* collidingTransform,
                                              hkVector4& separatingNormalInOut) const
{
    return (WeldResult)WeldContactPoint(featurePoints, numFeaturePoints, contactPointWs, thisObjTransform,
                                        collidingShape, collidingTransform, separatingNormalInOut);
}

__forceinline const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}

__forceinline const hkMotionState* hkpCdBody::GetMotionState() const
{
    return reinterpret_cast<const hkMotionState*>(m_pMotionState);
}

#include "../../../../../../../include/hkpCollisionQualityInfo.h"
struct GskAgentInput
{
    int m_unk00, m_unk04, m_unk08, m_unk0c;
    int m_unk10, m_unk14, m_unk18, m_unk1c;
    int m_unk20, m_unk24, m_unk28, m_unk2c;
    int m_unk30, m_unk34, m_unk38, m_unk3c;
    int m_unk40, m_unk44, m_unk48, m_unk4c;
    hkStepInfo m_pStepInfo;
    GskValue<hkpCollisionQualityInfo*> m_pCollisionQualityInfo;
};

__forceinline const hkVector4& hkContactPoint::getPosition() const
{
    return m_vContactPosition;
}

__forceinline const hkVector4& hkContactPoint::getNormal() const
{
    return m_vSeparatingNormal;
}

__forceinline hkVector4& hkContactPoint::getPosition()
{
    return m_vContactPosition;
}

__forceinline const hkVector4& hkContactPoint::getSeparatingNormal() const
{
    return m_vSeparatingNormal;
}

__forceinline hkVector4& hkContactPoint::getSeparatingNormal()
{
    return m_vSeparatingNormal;
}

__forceinline void hkContactPoint::setSeparatingNormal(const hkVector4& separatingNormal)
{
    m_vSeparatingNormal = separatingNormal;
}

__forceinline void hkContactPoint::setDistance(hkReal d)
{
    m_vSeparatingNormal(3) = d;
}

class ConvexFeaturePairCache
{
  public:
    hkUint16 m_kVertices[4];
    hkUint8 m_ucDimensionA;
    hkUint8 m_ucDimensionB;
    hkUint8 m_ucFeatureTypePair;
    hkUint8 m_unk0b;
    int m_unk0c;
};
class HeapContactFeatureCache : public ConvexFeaturePairCache
{
  public:
    __forceinline void set(const HeapContactFeatureCache& o)
    {
        *this = o;
    }
};

__forceinline QuantizedFloat8::QuantizedFloat8()
{}
__forceinline hkContactPointMaterial::hkContactPointMaterial()
{}
class ContactImpulseInfo
{
  public:
    __forceinline ContactImpulseInfo()
    {
        init();
    }
    __forceinline void init()
    {
        m_fAccumulatedImpulse = 0.0f;
        m_fImpulseLimit = 0.0f;
    }
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;
};
class PhysicsMaterial : public ContactImpulseInfo, public hkContactPointMaterial
{
  public:
    __forceinline PhysicsMaterial()
    {}
};
class ContactDataPhysicsMaterial : public PhysicsMaterial
{
  public:
    __forceinline ContactDataPhysicsMaterial()
    {}
    __forceinline void set(const ContactDataPhysicsMaterial& o)
    {
        *this = o;
    }
    hkReal m_uiUserData;
    int m_internal14, m_internal18, m_internal1c;
    int m_extended0, m_extended1, m_extended2, m_extended3;
};

struct ContactPointWithId
{
    hkContactPoint m_kPoint;
    hkVector4 m_unweldedNormal;
};
struct ContactPointRecord
{
    hkContactPoint m_vContactPoint;
    GskValue<hkReal> m_uiCommandId;
    GskValue<hkReal> m_pfSeparatingVelocity;
    int m_unk08, m_unk0c;
    HeapContactFeatureCache m_kGskCache;
    ContactDataPhysicsMaterial m_kProperties;
};
struct WorldOperationEntry
{
    __forceinline hkBool hasToi() const
    {
        return m_fTimeOfImpact.m_uiCommandId != 3.402820018375656e38;
    }
    int m_pAlignedPairData;
    GskValue<hkpConstraintOwner*> m_pConstraintOwner;
    ContactPointWithId m_akContactPoints[256];
    ContactPointRecord m_fTimeOfImpact;
};

// Preserve the contact-manager dispatch slots used by the original inlined wrappers.
__forceinline int hkpContactMgr::addToi(const hkpCdBody& a, const hkpCdBody& b,
    const GskAgentInput& input, WorldOperationEntry& output, hkTime toi,
    hkContactPoint& cp, const HeapContactFeatureCache* gskCache,
    hkReal& projectedVelocity, ContactDataPhysicsMaterial& propertiesOut)
{
    typedef int (__thiscall *AddToi)(hkpContactMgr*, const hkpCdBody&, const hkpCdBody&,
        const GskAgentInput&, WorldOperationEntry&, hkTime, hkContactPoint&,
        const HeapContactFeatureCache*, hkReal&, ContactDataPhysicsMaterial&);
    return reinterpret_cast<AddToi>((*reinterpret_cast<void***>(this))[7])(
        this, a, b, input, output, toi, cp, gskCache, projectedVelocity, propertiesOut);
}
__forceinline void hkpContactMgr::removeToi(hkpConstraintOwner& owner,
    ContactDataPhysicsMaterial& properties)
{
    typedef void (__thiscall *RemoveToi)(hkpContactMgr*, hkpConstraintOwner&,
        ContactDataPhysicsMaterial&);
    reinterpret_cast<RemoveToi>((*reinterpret_cast<void***>(this))[8])(this, owner, properties);
}
__forceinline hkpShapeType hkpShape::getType() const
{
    return *reinterpret_cast<const hkpShapeType*>(&m_type);
}


struct AgentSubtypeMarker : public hkpAgent3Input
{
    GskValue<hkReal> m_fSubtypeValue;
    hkVector4 m_vSubtypePosition;
};

class hkLineSegmentResult
{
  public:
    hkVector4 m_kFirstVector;
    hkVector4 m_kClosestPointOnSecond;
    GskValue<hkReal> m_t;
};

class ConvexShapePairCache
{
  public:
    __forceinline ConvexShapePairCache() : m_uiCacheFlags(0)
    {}
    __forceinline void setFeatureChange(int f)
    {
        m_iFeatureChange = f;
    }
    __forceinline void init(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const ConvexFeaturePairCache& cache)
    {
        m_ucDimensionA = cache.m_ucDimensionA;
        m_ucDimensionB = cache.m_ucDimensionB;
        m_ucFeatureTypeA = cache.m_ucFeatureTypePair & 0xf;
        m_ucFeatureTypeB = (cache.m_ucFeatureTypePair >> 4) & 0xf;
        setFeatureChange(0);
        shapeA->GetVerticesForIds(cache.m_kVertices, m_ucDimensionA, &m_akPackedVerticesA[0]);
        shapeB->GetVerticesForIds(cache.m_kVertices + m_ucDimensionA, m_ucDimensionB, &m_akPackedVerticesB[0]);
    }
    int hkpGsk_getClosestFeature(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb,
                     hkVector4& separatingNormal);
    __forceinline int GetClosestPoint(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB,
                                        const hkTransform& aTb, hkVector4& separatingNormal)
    {
        return hkpGsk_getClosestFeature(shapeA, shapeB, aTb, separatingNormal);
    }
    void hkpGsk_exitAndExportCacheImpl(ConvexFeaturePairCache& cache) const;
    __forceinline void WriteContactFeatureCache(ConvexFeaturePairCache& cache) const
    {
        hkpGsk_exitAndExportCacheImpl(cache);
    }
    __forceinline void checkForChangesAndUpdateCache(ConvexFeaturePairCache& cache) const
    {
        if (!m_iFeatureChange)
            return;
        WriteContactFeatureCache(cache);
    }
    __forceinline void getClosestPointAinA(const hkVector4& separatingNormal, hkVector4& pointOnAinA)
    {
        if (m_ucDimensionA == 1)
        {
            pointOnAinA = m_akPackedVerticesA[0];
        }
        else if (m_ucDimensionB == 1)
        {
            pointOnAinA = m_akCachedVectors[0];
            pointOnAinA.addMul4(separatingNormal.getSimdAt(3), separatingNormal);
        }
        else
        {
            pointOnAinA = m_closestLineSegResult.m_kFirstVector;
        }
    }
    GskValue<int> m_ucDimensionA, m_ucDimensionB, m_ucFeatureTypeA, m_ucFeatureTypeB;
    GskValue<hkUint32> m_uiCacheFlags;
    GskValue<int> m_iFeatureChange;
    Vector4WithInt24W m_akPackedVerticesA[4];
    hkVector4 m_verticesAinB[4];
    hkVector4 m_akCachedVectors[4];
    Vector4WithInt24W m_akPackedVerticesB[4];
    hkVector4 m_lastDimB2;
    hkLineSegmentResult m_closestLineSegResult;
    hkVector4 m_unk160;
    GskValue<int> m_lastFeature;
};

void Object_ComputeContactPointAndNormal(const hkVector4* verticesA, const hkVector4* verticesB, int dimA, int dimB,
                  const hkVector4& separatingNormal, hkVector4& pointOnA, hkVector4& normalOut);
__forceinline void hkGskRecalcContact(const ConvexShapePairCache& gsk, const hkVector4& separatingNormal,
                                      hkVector4& pointOnA, hkVector4& normalOut)
{
    Object_ComputeContactPointAndNormal(gsk.m_akPackedVerticesA, gsk.m_akCachedVectors, gsk.m_ucDimensionA, gsk.m_ucDimensionB,
                 separatingNormal, pointOnA, normalOut);
}

template <typename T> __forceinline T* hkAddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
__forceinline void* hkStackMemory::allocateStack(int numBytes, const char* what)
{
    void* current = m_next;
    m_next = hkAddByteOffset(current, numBytes);
    return current;
}

__forceinline void hkStackMemory::deallocateStack(void* p)
{
    m_next = p;
}
__forceinline hkMemoryRouter& hkMemoryRouter::getInstance()
{
    return *static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
}

template <typename T> __forceinline T* hkAllocateStack(int n, const char* what = 0)
{
    hkMemoryRouter& mem = hkMemoryRouter::getInstance();
    return static_cast<T*>(mem.stack().allocateStack((n * sizeof(T) + 127) & ~127, what));
}
template <typename T> __forceinline void hkDeallocateStack(T* ptr)
{
    hkMemoryRouter::getInstance().stack().deallocateStack(ptr);
}

namespace MemoryUtils {
__forceinline void memClear16(void* dst, int numQuads)
{
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    {
        for (int i = 0; i < numQuads; i++)
        {
            dst32[0] = 0;
            dst32[1] = 0;
            dst32[2] = 0;
            dst32[3] = 0;
            dst32 += 4;
        }
    }
}
}
namespace hkVector4Util_S {
__forceinline void checkRegisters(hkUint32 registerMask)
{}
__forceinline void TransformPointArray(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                       hkVector4* vectorsOut)
{
    checkRegisters(0xf0000000);
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}

struct ContactPointWeldingParameters
{
    GskValue<hkReal> m_fMinimumTimeOfImpactDelta;
    GskValue<hkReal> m_fCreateContactThreshold;
    GskValue<hkReal> m_fMinimumSafeDeltaTime;
    GskValue<hkReal> m_fMaximumAngularVelocity;
    GskValue<hkReal> m_fMaximumConstraintViolation;
};
struct ConvexCollisionQueryData
{
    __forceinline ConvexCollisionQueryData()
    {}
    GskValue<const hkMotionState*> m_pFirstQueryData;
    GskValue<const hkMotionState*> m_pSecondQueryData;
    GskValue<hkVector4*> m_akPackedVerticesA;
    GskValue<int> m_iStridedVertexCount;
    GskValue<int> m_iSecondPackedVertexCount;
    GskValue<hkReal> m_kFourthBasisVector;
    GskValue<hkReal> m_fSecondBasisScalar;
    GskValue<hkReal> m_fThirdBasisScalar;
    hkVector4 m_vFirstStoredVector;
    hkVector4 m_vSecondStoredVector;
    GskValue<const hkStepInfo*> m_pStepInfo;
    GskValue<hkReal> m_fStepTimeParameter;
    hkVector4 m_vSubtypePosition;
    hkVector4 m_avSubtypeVectors[2];
    GskValue<hkReal> m_fFinalQueryParameter;
};
struct ScalarVectorData
{
    __forceinline ScalarVectorData() : m_Rt(1.0f)
    {}
    GskValue<hkReal> m_Rt;
    hkVector4 m_collidePoint;
};

struct CollisionSolverInput
{
    __forceinline CollisionSolverInput()
    {}
    hkTransform m_pTransformB;
    hkTransform m_pTransformA;
    hkTransform m_kTransform;
    hkVector4 m_vPointOnPlaneB;
    hkVector4 m_pointOnPlaneA;
    hkVector4 m_linearTimInfoA;
    hkVector4 m_deltaAnglesA[2];
    hkVector4 m_massCenterA;
    hkVector4 m_vMassCenterB;
};
void hkTransform_setMulInverseMul_UpdateState_00db4b50(const ConvexCollisionQueryData& input, hkReal Rt, CollisionSolverInput& mat);

static hkReal hk4dGskCollidePointWithPlaneFinal(const ConvexCollisionQueryData& input,
                                                const ContactPointWeldingParameters& tol, const hkVector4& vertex, hkReal startRt,
                                                hkReal endRt, hkReal distance0, hkReal distance1, hkReal velocity,
                                                ScalarVectorData& out)
{
    CollisionSolverInput mat;
    hkReal Rt = startRt;
    hkReal distance = distance0;
    const hkReal accuracy = tol.m_fMaximumConstraintViolation * 0.25;
    for (int iteration = 0; iteration < 10; iteration++)
    {
        if (distance0 <= tol.m_fMinimumTimeOfImpactDelta)
            break;
        hkReal delta = distance1 - distance0;
        if (delta <= -accuracy)
            break;
        hkReal rel = (tol.m_fMinimumTimeOfImpactDelta - distance0) / delta;
        if ((iteration & 1) == 0)
        {
            rel = MathUtilities::max2(rel, 0.1f);
            rel = MathUtilities::min2(rel, 0.9f);
        }
        Rt = (1.0f - rel) * startRt + endRt * rel;
        hkTransform_setMulInverseMul_UpdateState_00db4b50(input, Rt, mat);
        hkVector4 diff;
        diff.setSub4(vertex, mat.m_pointOnPlaneA);
        distance = diff.dot4xyz1(mat.m_vPointOnPlaneB);
        if (MathUtilities::equal(distance, tol.m_fMinimumTimeOfImpactDelta, accuracy))
            break;
        if (distance < tol.m_fMinimumTimeOfImpactDelta)
        {
            endRt = Rt;
            distance1 = distance;
        }
        else
        {
            startRt = Rt;
            distance0 = distance;
        }
    }
    if (Rt < out.m_Rt)
    {
        out.m_Rt = Rt;
        out.m_collidePoint = vertex;
    }
    return out.m_Rt;
}

// src: GUESS 0x00db4e40 (confidence: low)
void __cdecl Object_ProcessEntries_00db4e40(const ConvexCollisionQueryData& input, const ContactPointWeldingParameters& tol,
                          ScalarVectorData& out)
{
    hkReal maxRt = 1.0f;
    hkReal currentRt = input.m_fFinalQueryParameter;
    hkReal previousRt = currentRt;
    int numVertices = input.m_iStridedVertexCount;
    while (numVertices)
    {
        CollisionSolverInput mat;
        hkTransform_setMulInverseMul_UpdateState_00db4b50(input, currentRt, mat);
        hkVector4* vertex = input.m_akPackedVerticesA;
        hkVector4* insert = vertex;
        const hkReal restRt = 1.0f - currentRt;
        const hkReal maxTravel = input.m_fStepTimeParameter * restRt;
        hkReal nextRt = 1.0f;
        int i = numVertices;
        numVertices = 0;
        for (i = i - 1; i >= 0; vertex += 1, i--)
        {
            hkVector4 toPlane;
            toPlane.setSub4(*vertex, mat.m_pointOnPlaneA);
            const hkReal distance = toPlane.dot4xyz1(mat.m_vPointOnPlaneB);
            if (distance >= tol.m_fCreateContactThreshold + maxTravel)
                continue;
            hkVector4 relA;
            relA.setSub4(*vertex, mat.m_massCenterA);
            hkVector4 relB;
            relB.setSub4(*vertex, mat.m_vMassCenterB);
            hkVector4 crossA;
            crossA.setCross(mat.m_deltaAnglesA[0], relA);
            hkVector4 crossB;
            crossB.setCross(mat.m_deltaAnglesA[1], relB);
            hkVector4 velocity;
            velocity.setSub4(crossA, mat.m_linearTimInfoA);
            velocity.sub4(crossB);
            const hkReal approach = velocity.dot3(mat.m_vPointOnPlaneB);
            const hkReal gap = distance - tol.m_fCreateContactThreshold;
            const hkReal atEnd = approach * restRt + gap;
            const hkReal accelTerm = restRt * 0.5 * restRt * input.m_fSecondBasisScalar;
            if (atEnd > accelTerm)
                continue;
            if (distance < tol.m_fCreateContactThreshold)
            {
                if (currentRt == input.m_fFinalQueryParameter)
                {
                    out.m_Rt = currentRt;
                    out.m_collidePoint = *vertex;
                    maxRt = currentRt;
                }
                else
                {
                    maxRt = hk4dGskCollidePointWithPlaneFinal(input, tol, *vertex, previousRt, currentRt, (*vertex)(3),
                                                              distance, approach, out);
                }
                continue;
            }
            hkVector4 swapTemp = *vertex;
            *vertex = *insert;
            *insert = swapTemp;
            (*insert)(3) = distance;
            insert += 1;
            numVertices++;
            const hkReal safeDist = distance - tol.m_fMinimumTimeOfImpactDelta;
            const hkReal minDist = tol.m_fCreateContactThreshold - tol.m_fMinimumTimeOfImpactDelta;
            const hkReal d2 = safeDist * 2.0 * input.m_fThirdBasisScalar;
            if (restRt * restRt <= d2)
                continue;
            const hkReal d3 = minDist * 2.0 * input.m_fThirdBasisScalar;
            hkReal step = sqrtf(d2);
            if (approach < 0.0f)
            {
                step += input.m_fThirdBasisScalar * approach + input.m_fThirdBasisScalar * approach;
            }
            else
            {
                step = MathUtilities::max2(step, -approach * input.m_fThirdBasisScalar);
            }
            if (step >= restRt)
                continue;
            hkReal candidate = step + sqrtf(d3);
            candidate = MathUtilities::max2(candidate, tol.m_fMinimumSafeDeltaTime.val());
            nextRt = MathUtilities::min2(nextRt, currentRt + candidate);
        }
        if (maxRt <= currentRt)
            break;
        if (nextRt == currentRt && maxRt > currentRt)
            break;
        previousRt = currentRt;
        currentRt = nextRt;
        nextRt = maxRt;
    }
}

static __forceinline void hk4dGskCalcSeparatingNormal(const hkTransform& tA, const hkTransform& tB,
                                                      const hkpConvexShape* shapeA, const hkpConvexShape* shapeB,
                                                      ConvexShapePairCache& gsk, hkVector4& separatingNormalOut,
                                                      hkVector4& pointOnBInB)
{
    hkTransform aTb;
    aTb.SetMulInverse(tA, tB);
    hkVector4 separatingNormalA;
    gsk.GetClosestPoint(shapeA, shapeB, aTb, separatingNormalA);
    separatingNormalOut._setRotatedDir(tA.getRotation(), separatingNormalA);
    hkVector4 pointInA;
    gsk.getClosestPointAinA(separatingNormalA, pointInA);
    pointInA.subMul4(separatingNormalA.getSimdAt(3), separatingNormalA);
    pointOnBInB._setTransformedInversePos(aTb, pointInA);
    separatingNormalOut(3) = separatingNormalA(3) - shapeA->getRadius() - shapeB->getRadius();
}

static __forceinline void hk4dGskCalcWorstCaseProjectedVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                                const hkVector4& separatingNormal,
                                                                const hkVector4& linearTimInfo,
                                                                const hkVector4* deltaAngles,
                                                                hkReal& realProjectedLinearDelta,
                                                                hkReal& projectedAngularDelta)
{
    hkVector4 crossAngleA;
    crossAngleA.setCross(deltaAngles[0], separatingNormal);
    hkVector4 crossAngleB;
    crossAngleB.setCross(deltaAngles[1], separatingNormal);
    hkReal lenA = crossAngleA.length3() * msA->m_fObjectRadius;
    hkReal lenB = crossAngleB.length3() * msB->m_fObjectRadius;
    projectedAngularDelta = lenA + lenB;
    realProjectedLinearDelta = linearTimInfo.dot3(separatingNormal);
}

static __forceinline void hk4dGskCollPInputInitialize(const AgentSubtypeMarker& in3,
                                                      ConvexCollisionQueryData& input)
{
    const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
    const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
    const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
    const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
    input.m_pFirstQueryData = msA;
    input.m_pSecondQueryData = msB;
    input.m_kFourthBasisVector = shapeA->getRadius() + shapeB->getRadius();
    input.m_vSubtypePosition = in3.m_vSubtypePosition;
    input.m_pStepInfo = &reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo;
    int numVertices = shapeA->getNumCollisionSpheres();
    input.m_iSecondPackedVertexCount = numVertices;
    input.m_iStridedVertexCount = numVertices;
    input.m_akPackedVerticesA = hkAllocateStack<hkVector4>(numVertices);
    shapeA->getCollisionSpheres(reinterpret_cast<hkSphere*>(input.m_akPackedVerticesA.val()));
    const hkReal a = msA->m_fObjectRadius * input.m_avSubtypeVectors[0](3) * input.m_avSubtypeVectors[0](3);
    const hkReal b = msB->m_fObjectRadius * input.m_avSubtypeVectors[1].w * input.m_avSubtypeVectors[1].w;
    input.m_fSecondBasisScalar = a + b;
    input.m_fThirdBasisScalar = 1.0f / (input.m_fSecondBasisScalar + 1.1920928955078125e-07);
}

static __forceinline hkReal hk4dGskCalcPointVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                     const hkVector4& separatingPoint,
                                                     const hkVector4& separatingNormal, const hkVector4& linearTimInfo,
                                                     const hkVector4* deltaAngles, hkTime t)
{
    hkVector4 relVel;
    relVel.setNeg4(linearTimInfo);
    {
        const hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[0], relPos);
        relVel.add4(arm);
    }
    {
        const hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[1], relPos);
        relVel.sub4(arm);
    }
    const hkReal separatingVelocity = relVel.dot3(separatingNormal);
    return separatingVelocity;
}

// src: GUESS 0x00db49b0 (confidence: low)
static __declspec(noinline) hkReal HkpcontinuousgskGsEhscNogsNoehsc_ComputeValues_00db49b0(const hkMotionState* msA, const hkMotionState* msB,
                                                const hkVector4& separatingPoint, const hkVector4& separatingNormal,
                                                const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkTime t)
{
    const hkReal angularVelocityFactor = 1.2f;
    hkVector4 relVel;
    relVel.setNeg4(linearTimInfo);
    hkReal separatingVelocity = relVel.dot3(separatingNormal);
    {
        const hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[0], relPos);
        const hkReal angVelPart = arm.dot3(separatingNormal);
        if (angVelPart <= 0.0f)
            separatingVelocity += angVelPart * angularVelocityFactor;
        else
            separatingVelocity += angVelPart / angularVelocityFactor;
    }
    {
        const hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[1], relPos);
        const hkReal angVelPart = arm.dot3(separatingNormal);
        if (angVelPart >= 0.0f)
            separatingVelocity -= angVelPart * angularVelocityFactor;
        else
            separatingVelocity -= angVelPart / angularVelocityFactor;
    }
    return separatingVelocity;
}

static __forceinline void UpdateConvexShapePairCache(const AgentSubtypeMarker& in3, ContactPointWeldingParameters& tol,
                                              ConvexShapePairCache& gsk, int featureChange,
                                              const hkVector4& oldMasterNormal, const hkVector4* deltaAngles,
                                              hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1,
                                              WorldOperationEntry& out)
{
    CollisionSolverInput mat;
    hkVector4 normalA;
    hkVector4 pointA;
    hkReal Rt = startRt;
    hkReal distance = distance0;
    hkTransform wTa;
    hkTransform wTb;
    hkTransform aTb;
    hkReal radiusSum;
    {
        const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
        const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
        radiusSum = shapeA->getRadius();
        radiusSum += shapeB->getRadius();
    }
    const hkReal velocityBasedOnDistance = (distance1 - distance0) / (endRt - startRt);
    for (int iteration = 0; iteration < 10; iteration++)
    {
        hkReal delta = distance1 - distance0;
        if (delta > -tol.m_fMaximumConstraintViolation)
        {
            endRt = startRt;
            delta = 0.5f;
        }
        hkBool earlyOut;
        if (MathUtilities::equal(distance1, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation))
        {
            earlyOut = true;
            featureChange = 0;
            Rt = endRt;
        }
        else
        {
            earlyOut = false;
            hkReal rel = (tol.m_fMinimumTimeOfImpactDelta - distance0) / delta;
            rel = MathUtilities::max2(rel, 0.1f);
            rel = MathUtilities::min2(rel, 0.9f);
            Rt = (1.0f - rel) * startRt + endRt * rel;
        }
        {
            const hkStepInfo& stepInfo = reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo;
            const hkReal timeAddon = stepInfo.m_fTimeStep * Rt;
            hkSweptTransform_ComputeValues_00cf1710(in3.m_pBodyA->GetMotionState()->getSweptTransform(), stepInfo.m_uiStartTime, timeAddon, wTa);
            hkSweptTransform_ComputeValues_00cf1710(in3.m_pBodyB->GetMotionState()->getSweptTransform(), stepInfo.m_uiStartTime, timeAddon, wTb);
        }
        aTb.SetMulInverse(wTa, wTb);
        if (featureChange)
        {
            const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
            const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
            gsk.GetClosestPoint(shapeA, shapeB, aTb, normalA);
            gsk.getClosestPointAinA(normalA, pointA);
        }
        else
        {
            hkVector4Util_S::TransformPointArray(aTb, gsk.m_akPackedVerticesB, gsk.m_ucDimensionB,
                                                 gsk.m_akCachedVectors);
            hkVector4 oldMasterNormalInA;
            oldMasterNormalInA._setRotatedInverseDir(wTa.getRotation(), oldMasterNormal);
            hkGskRecalcContact(gsk, oldMasterNormalInA, pointA, normalA);
        }
        distance = normalA(3) - radiusSum;
        if (MathUtilities::equal(distance, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation) ||
            earlyOut)
        {
            break;
        }
        if (startRt == endRt)
        {
            break;
        }
        if (distance < tol.m_fMinimumTimeOfImpactDelta)
        {
            endRt = Rt;
            distance1 = distance;
        }
        else
        {
            startRt = Rt;
            distance0 = distance;
        }
    }
    const hkStepInfo& stepInfo = reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo;
    const hkReal deltaTime = MathUtilities::max2(stepInfo.m_fTimeStep.val() * Rt, tol.m_fMaximumAngularVelocity.val());
    hkTime toi = stepInfo.m_uiStartTime + deltaTime;
    if (toi < out.m_fTimeOfImpact.m_uiCommandId && toi < (stepInfo.m_fEndTime - tol.m_fMaximumAngularVelocity))
    {
        const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
        hkContactPoint cp;
        hkReal separatingVelocity;
        {
            hkVector4 pointWs;
            pointWs.SetTransformedPoint(wTa, pointA);
            cp.getSeparatingNormal().SetRotatedDirection(wTa.getRotation(), normalA);
            cp.getPosition().setAddMul4(pointWs, cp.getSeparatingNormal(), hkSimdReal(-shapeA->getRadius() - distance));
            cp.setDistance(distance);
            hkpConvexShape::WeldResult weldResult = hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
            hkVector4 weldedNormal = cp.getSeparatingNormal();
            if (in3.m_pBodyB->getShape()->getType() == HK_SHAPE_TRIANGLE)
            {
                hkUint8 numFeaturePoints = (hkUint8)gsk.m_ucDimensionB.val();
                hkpVertexId featurePoints[3];
                featurePoints[0] = (hkpVertexId)gsk.m_akPackedVerticesB[0].GetValueForType();
                featurePoints[1] =
                    (hkpVertexId)(numFeaturePoints < 2 ? 0xffff : gsk.m_akPackedVerticesB[1].GetValueForType());
                featurePoints[2] =
                    (hkpVertexId)(numFeaturePoints < 3 ? 0xffff : gsk.m_akPackedVerticesB[2].GetValueForType());
                const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
                weldResult = shapeB->weldContactPoint(featurePoints, numFeaturePoints, cp.getPosition(), &wTb, shapeA,
                                                      &wTa, weldedNormal);
                cp.setSeparatingNormal(weldedNormal);
            EXAMINE_WELD_RESULTS:
                if (weldResult == hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT &&
                    reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pCollisionQualityInfo->m_bEnableToiWeldRejection)
                {
                    return;
                }
            }
            else if (in3.m_pBodyA->getShape()->getType() == HK_SHAPE_TRIANGLE)
            {
                hkUint8 numFeaturePoints = (hkUint8)gsk.m_ucDimensionA.val();
                hkpVertexId featurePoints[3];
                featurePoints[0] = (hkpVertexId)gsk.m_akPackedVerticesA[0].GetValueForType();
                featurePoints[1] =
                    (hkpVertexId)(numFeaturePoints < 2 ? 0xffff : gsk.m_akPackedVerticesA[1].GetValueForType());
                featurePoints[2] =
                    (hkpVertexId)(numFeaturePoints < 3 ? 0xffff : gsk.m_akPackedVerticesA[2].GetValueForType());
                hkVector4 dist;
                dist.setBroadcast(weldedNormal, 3);
                hkVector4 pointOnA;
                pointOnA.setAddMul4(cp.getPosition(), weldedNormal, dist);
                weldedNormal.setNeg3(weldedNormal);
                const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
                weldResult = shapeA->weldContactPoint(featurePoints, numFeaturePoints, pointOnA, &wTa, shapeB, &wTb,
                                                      weldedNormal);
                weldedNormal.setNeg3(weldedNormal);
                cp.setSeparatingNormal(weldedNormal);
                goto EXAMINE_WELD_RESULTS;
            }
            const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
            const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
            separatingVelocity = hk4dGskCalcPointVelocity(msA, msB, cp.getPosition(), cp.getNormal(),
                                                          in3.m_vSubtypePosition, deltaAngles, toi);
            if (weldResult == hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED &&
                separatingVelocity > -1.1920929e-07f)
            {
                ConvexCollisionQueryData collPInput;
                collPInput.m_fFinalQueryParameter = Rt;
                {
                    MotionUtilities::calcAngularTimInfo(*msA, *msB, reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo.m_fTimeStep,
                                                        &collPInput.m_avSubtypeVectors[0], &collPInput.m_avSubtypeVectors[1]);
                    hkReal realProjectedLinearDelta, projectedAngularDelta;
                    hk4dGskCalcWorstCaseProjectedVelocity(msA, msB, cp.getNormal(), in3.m_vSubtypePosition,
                                                          collPInput.m_avSubtypeVectors, realProjectedLinearDelta,
                                                          projectedAngularDelta);
                    collPInput.m_fStepTimeParameter = realProjectedLinearDelta + projectedAngularDelta;
                    hk4dGskCollPInputInitialize(in3, collPInput);
                    collPInput.m_vFirstStoredVector.setRotatedInverseDir(wTb.getRotation(), cp.getNormal());
                    collPInput.m_vSecondStoredVector = gsk.m_akPackedVerticesB[0];
                }
                if (collPInput.m_akPackedVerticesA.val())
                {
                    ScalarVectorData collidePointsOut;
                    Object_ProcessEntries_00db4e40(collPInput, tol, collidePointsOut);
                    hkDeallocateStack(collPInput.m_akPackedVerticesA.val());
                    if (collidePointsOut.m_Rt < 1.0f)
                    {
                        hkVector4 newPos;
                        newPos.SetTransformedPoint(wTa, collidePointsOut.m_collidePoint);
                        cp.getPosition() = newPos;
                    }
                }
            }
            if (velocityBasedOnDistance < separatingVelocity)
            {
                if (velocityBasedOnDistance > separatingVelocity * 1.2000000476837158)
                {
                    separatingVelocity = velocityBasedOnDistance;
                }
                else
                {
                    separatingVelocity =
                        HkpcontinuousgskGsEhscNogsNoehsc_ComputeValues_00db49b0(in3.m_pBodyA->GetMotionState(), in3.m_pBodyB->GetMotionState(), cp.getPosition(),
                                     cp.getNormal(), in3.m_vSubtypePosition, deltaAngles, toi);
                    separatingVelocity = MathUtilities::min2(0.0f, separatingVelocity);
                }
            }
            separatingVelocity *= stepInfo.m_fInverseDeltaTime;
        }
        ContactDataPhysicsMaterial properties;
        MemoryUtils::memClear16(&properties, 3);
        properties.m_uiUserData = DAT_010d5384;
        HeapContactFeatureCache cache;
        gsk.WriteContactFeatureCache(cache);
        int cbResult =
            in3.m_pContactManager->addToi(*in3.m_pBodyA.val(), *in3.m_pBodyB.val(), *reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val()), out,
                                          toi, cp, &cache, separatingVelocity, properties);
        if (cbResult == 0)
        {
            if (out.hasToi())
            {
                in3.m_pContactManager->removeToi(*out.m_pConstraintOwner.val(), out.m_fTimeOfImpact.m_kProperties);
            }
            out.m_fTimeOfImpact.m_pfSeparatingVelocity = separatingVelocity;
            out.m_fTimeOfImpact.m_vContactPoint = cp;
            out.m_fTimeOfImpact.m_uiCommandId = toi;
            out.m_fTimeOfImpact.m_kProperties.set(properties);
            out.m_fTimeOfImpact.m_kGskCache.set(cache);
        }
    }
}

// @fnv 0x00db60c0
// src: COMMUNITY 0x00db60c0
__declspec(noinline) void __cdecl hk4dGskCollideCalcToi(const AgentSubtypeMarker& in3, const hkReal allowedPenetrationDepth,
                                               const hkReal minSeparation, const hkReal toiSeparation,
                                               ConvexFeaturePairCache& gskCache, hkVector4& separatingNormal,
                                               WorldOperationEntry& out)
{
    ContactPointWeldingParameters tol;
    {
        const hkpCollisionQualityInfo& qi = *reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pCollisionQualityInfo.val();
        tol.m_fCreateContactThreshold = minSeparation;
        tol.m_fMinimumTimeOfImpactDelta = toiSeparation;
        tol.m_fMaximumConstraintViolation = qi.m_fMaximumConstraintViolation * allowedPenetrationDepth;
        tol.m_fMinimumSafeDeltaTime = MathUtilities::max2(qi.m_fMinimumSafeDeltaTime * allowedPenetrationDepth,
                                                          qi.m_fMinimumAbsoluteTimeOfImpact) *
                                      reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo.m_fInverseDeltaTime;
        tol.m_fMaximumAngularVelocity = qi.m_fMaximumAngularVelocity;
    }
    const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
    const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
    const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
    const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
    ConvexCollisionQueryData collPInput;
    collPInput.m_akPackedVerticesA = 0;
    hkBool collPInputNormalInitialized = false;
    hkBool collPIgnore = false;
    MotionUtilities::calcAngularTimInfo(*msA, *msB, reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo.m_fTimeStep,
                                        &collPInput.m_avSubtypeVectors[0], &collPInput.m_avSubtypeVectors[1]);
    {
        int numIter = 0;
        ConvexShapePairCache gsk;
        gsk.init(shapeA, shapeB, gskCache);
        hkVector4 lastMasterNormal;
        lastMasterNormal.setZero4();
        hkReal lastDistance = separatingNormal(3);
        int featureChange = 1;
        hkReal Rt = 0.0f;
        hkReal endRt = 1.0f;
        hkReal lastRt = 0.0f;
        while (1)
        {
            const hkReal currentDistance = separatingNormal(3);
            if (currentDistance <= tol.m_fMinimumTimeOfImpactDelta + tol.m_fMaximumConstraintViolation)
            {
                UpdateConvexShapePairCache(in3, tol, gsk, featureChange, lastMasterNormal, collPInput.m_avSubtypeVectors, lastRt,
                                    Rt, lastDistance, currentDistance, out);
                goto END;
            }
            const hkReal restRt = endRt - Rt;
            if (restRt <= 0.0f)
            {
                goto END;
            }
            hkReal realProjectedLinearDelta, projectedAngularDelta;
            hk4dGskCalcWorstCaseProjectedVelocity(msA, msB, separatingNormal, in3.m_vSubtypePosition,
                                                  collPInput.m_avSubtypeVectors, realProjectedLinearDelta,
                                                  projectedAngularDelta);
            const hkReal worstCaseApproachingDelta = realProjectedLinearDelta + projectedAngularDelta;
            const hkReal distAtT1 = separatingNormal(3) - worstCaseApproachingDelta * restRt;
            if (worstCaseApproachingDelta <= 0.0f || distAtT1 > tol.m_fCreateContactThreshold)
            {
                goto END;
            }
            const hkReal maxAllowedTravelDistance = separatingNormal(3) - tol.m_fCreateContactThreshold;
            hkReal safeTimeStep = maxAllowedTravelDistance / worstCaseApproachingDelta;
            if (safeTimeStep < 0.2f && !collPIgnore && collPInputNormalInitialized &&
                realProjectedLinearDelta * 1.0 < projectedAngularDelta)
            {
                if (!collPInput.m_akPackedVerticesA)
                {
                    hk4dGskCollPInputInitialize(in3, collPInput);
                    if (!collPInput.m_akPackedVerticesA.val())
                    {
                        collPIgnore = true;
                        goto skipPointPlaneOptimization;
                    }
                }
                collPInput.m_fFinalQueryParameter = Rt;
                collPInput.m_fStepTimeParameter = worstCaseApproachingDelta;
                ScalarVectorData collidePointsOut;
                Object_ProcessEntries_00db4e40(collPInput, tol, collidePointsOut);
                const hkReal newSafeTimeStep = collidePointsOut.m_Rt - Rt;
                if (newSafeTimeStep < safeTimeStep * 2.0)
                {
                    collPIgnore = true;
                }
                safeTimeStep = MathUtilities::max2(safeTimeStep, newSafeTimeStep);
            }
        skipPointPlaneOptimization:
            if (Rt + safeTimeStep >= endRt)
            {
                goto END;
            }
            lastRt = Rt;
            safeTimeStep = MathUtilities::max2(tol.m_fMinimumSafeDeltaTime.val(), safeTimeStep);
            Rt += safeTimeStep;
            Rt = MathUtilities::min2(Rt, endRt);
            lastMasterNormal = separatingNormal;
            lastDistance = separatingNormal(3);
            {
                numIter++;
                const hkStepInfo& stepInfo = reinterpret_cast<const GskAgentInput*>(in3.m_pRayCastInput.val())->m_pStepInfo;
                const hkReal timeAddon = stepInfo.m_fTimeStep * Rt;
                hkTransform tA;
                hkSweptTransform_ComputeValues_00cf1710(msA->getSweptTransform(), stepInfo.m_uiStartTime, timeAddon, tA);
                hkTransform tB;
                hkSweptTransform_ComputeValues_00cf1710(msB->getSweptTransform(), stepInfo.m_uiStartTime, timeAddon, tB);
                hk4dGskCalcSeparatingNormal(tA, tB, shapeA, shapeB, gsk, separatingNormal, collPInput.m_vSecondStoredVector);
                featureChange = gsk.m_iFeatureChange;
                collPInputNormalInitialized = true;
                collPInput.m_vFirstStoredVector._setRotatedInverseDir(tB.getRotation(), separatingNormal);
            }
        }
    END:
        if (collPInput.m_akPackedVerticesA)
        {
            hkDeallocateStack(collPInput.m_akPackedVerticesA.val());
        }
        gsk.checkForChangesAndUpdateCache(gskCache);
    }
}
