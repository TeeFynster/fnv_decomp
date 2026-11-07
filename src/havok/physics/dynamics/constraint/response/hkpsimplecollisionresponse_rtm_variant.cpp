#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep this unit's float-only intrinsic packet: the SDK's byte-array lanes
// change VC9's /GS classification and generated parameter copies.
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_rcp_ps(LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_div_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_load_ps1(const float*);
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, LocalM128);
}

#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"

#include <math.h>

class Scalar
{
    LocalM128 value;

  public:
    Scalar()
    {}
    Scalar(const LocalM128& x) : value(x)
    {}
    Scalar(float x)
    {
        value = _mm_load_ss(&x);
    }
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const LocalM128& get() const
    {
        return value;
    }
};

extern const LocalM128 DAT_010ec7f0;
__forceinline float& hkVector4::operator()(int i)
{
    return reinterpret_cast<float*>(&m_vComponents)[i];
}

__forceinline const float& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[i];
}

__forceinline void hkVector4::zero()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void hkVector4::subtract(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::scale(const Scalar& a)
{
    m_vComponents = _mm_mul_ps(a.splat(), m_vComponents);
}

__forceinline void hkVector4::product(const Scalar& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.splat(), b.m_vComponents);
}

__forceinline void hkVector4::interpolate(const hkVector4& a, const hkVector4& b, const Scalar& t)
{
    LocalM128 f = t.splat();
    LocalM128 inv = _mm_sub_ps(DAT_010ec7f0, f);
    m_vComponents = _mm_add_ps(_mm_mul_ps(inv, a.m_vComponents), _mm_mul_ps(f, b.m_vComponents));
}

__forceinline Scalar hkVector4::dot(const hkVector4& b) const
{
    LocalM128 squares = _mm_mul_ps(m_vComponents, b.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    return _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), xy);
}

__forceinline Scalar hkVector4::inverseLength() const
{
    const LocalM128 half = _mm_set_ss(0.5f);
    const LocalM128 three = _mm_set_ss(3.0f);
    const LocalM128 zero = _mm_set_ss(0.0f);
    const LocalM128 squared = dot(*this).get();
    const LocalM128 mask = _mm_cmpeq_ss(squared, zero);
    const LocalM128 rough = _mm_rsqrt_ss(squared);
    const LocalM128 refined =
        _mm_mul_ss(_mm_mul_ss(half, rough), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, rough), rough)));
    return _mm_andnot_ps(mask, refined);
}

__forceinline void hkVector4::normalize()
{
    LocalM128 inv = inverseLength().splat();
    m_vComponents = _mm_mul_ps(inv, m_vComponents);
}

__forceinline void hkVector4::cross(const hkVector4& a, const hkVector4& b)
{
    const LocalM128 qa = a.m_vComponents;
    const LocalM128 qb = b.m_vComponents;
    LocalM128 forward = _mm_mul_ps(_mm_shuffle_ps(qa, qa, 0xc9), _mm_shuffle_ps(qb, qb, 0xd2));
    LocalM128 reverse = _mm_mul_ps(_mm_shuffle_ps(qa, qa, 0xd2), _mm_shuffle_ps(qb, qb, 0xc9));
    m_vComponents = _mm_sub_ps(forward, reverse);
}

struct Matrix
{
    hkVector4 col0, col1, col2;
    __forceinline hkVector4& column(int i)
    {
        return (&col0)[i];
    }
};

struct Sweep
{
    hkVector4 center0, center1, rotation0, rotation1, localCenter;
    __forceinline float inverseTime() const
    {
        return center1(3);
    }
    __forceinline float fraction(float t) const
    {
        float f = (t - center0(3)) * inverseTime();
        return f;
    }
};
struct MotionState
{
    Transform transform;
    Sweep swept;
    hkVector4 deltaAngle;
    float radius;
    unsigned short dampingLinear, dampingAngular;
    float timeFactor;
    unsigned int packedRotation;
};
struct Input
{
    hkVector4 relative;
    Matrix inertia;
    hkVector4 inverseMass;
    const Transform* transform;
};
struct Velocity
{
    hkVector4 linear, angular;
};
struct AlignedDynamicArray
{
    Matrix jacobian, inverseJacobian;
    hkVector4 inverseMass;
    float mass;
    const Transform* transform;
};
struct Constraint
{
    AlignedDynamicArray body0, body1;
    Matrix basis, inverseMass, mass;
};
// hkContactPoint (position, separating normal) over this unit's hkVector4; the shared hkContactPoint is built on
// hkVector4, which this unit does not use. Not the shared x,y,z Point.
struct SimpleContactPoint
{
    hkVector4 position, normal;
    __forceinline const hkVector4& pos() const
    {
        return position;
    }
    __forceinline const hkVector4& dir() const
    {
        return normal;
    }
};
struct Params
{
    float friction, restitution, maxImpulse, externalVelocity, extraVelocity, extraSlope;
    unsigned char breached;
};
struct Result
{
    float impulse, velocityA, velocityB;
};
struct RefObject
{
    virtual void slot00();
    unsigned short memorySize, referenceCount;
};
struct Motion : RefObject
{
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void inverseInertia(Matrix&) const;
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void setLinear(const hkVector4&);
    virtual void setAngular(const hkVector4&);
    unsigned char type, counter;
    unsigned short inactive0, inactive1;
    MotionState state;
    hkVector4 inverseMass, linear, angular;
    __forceinline const Transform& transform() const
    {
        return state.transform;
    }
    __forceinline MotionState* motionState()
    {
        return &state;
    }
    __forceinline const hkVector4& linearVelocity() const
    {
        return linear;
    }
    __forceinline const hkVector4& angularVelocity() const
    {
        return angular;
    }
};
struct Manager
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void begin(const SimpleContactPoint&, Input&, Velocity&, Input&, Velocity&);
    virtual void end(const SimpleContactPoint&, float, Input&, Velocity&, Input&, Velocity&);
};
extern "C" void __cdecl hkpCollision_BuildResponseMatrices(const Input&, const Input&, const Matrix&, Constraint&);
extern "C" float __cdecl Object_ProcessAndReturnValue_00df5f80(const Constraint&, Params&, Velocity&, Velocity&);
extern "C" void __cdecl hkVector4_UpdateFields_00df5e80(const Constraint&, Velocity&, Velocity&, hkVector4&);

static __forceinline void centerAt(const MotionState& ms, float time, hkVector4& center)
{
    float f = ms.swept.fraction(time);
    center.interpolate(ms.swept.center0, ms.swept.center1, f);
}
static __forceinline void velocityOf(const MotionState& ms, hkVector4& linear, hkVector4& angular)
{
    linear.subtract(ms.swept.center1, ms.swept.center0);
    linear.scale(ms.swept.inverseTime());
    angular.product(ms.swept.inverseTime(), ms.deltaAngle);
}
static __forceinline float absolute(float f)
{
    return fabsf(f);
}
static __forceinline void perpendicular(const hkVector4& normal, hkVector4& tangent)
{
    int smallest = 0, left = 1, right = 2;
    float x = absolute(normal(0));
    float y = absolute(normal(1));
    float z = absolute(normal(2));
    if (y < x)
    {
        left = 0;
        smallest = 1;
        x = y;
    }
    if (z < x)
    {
        right = smallest;
        smallest = 2;
    }
    tangent.zero();
    tangent(left) = normal(right);
    tangent(right) = -normal(left);
}
static __forceinline void makeBasis(const hkVector4& normal, Matrix& basis)
{
    basis.column(0) = normal;
    perpendicular(normal, basis.column(1));
    basis.column(1).normalize();
    basis.column(2).cross(normal, basis.column(1));
}

// @fnv 0x00d9f250
// src: GUESS 0x00d9f250 (confidence: medium)
extern "C" void __cdecl hkpCollision_ProcessBodyResponse(const SimpleContactPoint& point, float time, Params& params, Motion* a, Motion* b, Manager* mgr,
                                     Result& result)
{
    Input ia;
    {
        ia.inverseMass = a->inverseMass;
        hkVector4 center;
        centerAt(*a->motionState(), time, center);
        ia.relative.subtract(point.pos(), center);
        a->inverseInertia(ia.inertia);
        ia.transform = &a->transform();
    }
    Input ib;
    {
        ib.inverseMass = b->inverseMass;
        hkVector4 center;
        centerAt(*b->motionState(), time, center);
        ib.relative.subtract(point.pos(), center);
        b->inverseInertia(ib.inertia);
        ib.transform = &b->transform();
    }
    Velocity va, vb;
    va.linear = a->linearVelocity();
    va.angular = a->angularVelocity();
    vb.linear = b->linearVelocity();
    vb.angular = b->angularVelocity();
    Velocity oa, ob;
    velocityOf(*a->motionState(), oa.linear, oa.angular);
    velocityOf(*b->motionState(), ob.linear, ob.angular);
    Constraint info;
    Matrix basis;
    makeBasis(point.dir(), basis);
    mgr->begin(point, ia, va, ib, vb);
    hkpCollision_BuildResponseMatrices(ia, ib, basis, info);
    result.impulse = Object_ProcessAndReturnValue_00df5f80(info, params, va, vb);
    mgr->end(point, result.impulse, ia, va, ib, vb);
    {
        hkVector4 pa, pb;
        hkVector4_UpdateFields_00df5e80(info, oa, vb, pa);
        hkVector4_UpdateFields_00df5e80(info, va, ob, pb);
        result.velocityA = pa(0);
        result.velocityB = pb(0);
    }
    if (a->type != 5)
    {
        a->setLinear(va.linear);
        a->setAngular(va.angular);
    }
    if (b->type != 5)
    {
        b->setLinear(vb.linear);
        b->setAngular(vb.angular);
    }
}

extern "C" void _ReadWriteBarrier(void);
typedef LocalM128 hkQuadReal;
typedef float hkReal;
namespace MathUtilities {
template <typename T> inline T max2(T x, T y)
{
    return x > y ? x : y;
}
}
namespace AlgorithmUtilities {
template <typename T> inline void swap(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}
}

class RealLane
{
  public:
    hkQuadReal q;
    RealLane()
    {}
    RealLane(const hkQuadReal& v) : q(v)
    {}
    RealLane(float x)
    {
        q = _mm_load_ss(&x);
    }
    const hkQuadReal& quad() const
    {
        return q;
    }
    hkQuadReal spread() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
static __forceinline RealLane operator/(const RealLane& a, const RealLane& b)
{
    return _mm_div_ss(a.quad(), b.quad());
}
static __forceinline void maximumLane(const RealLane& a, const RealLane& b, RealLane& result)
{
    result = _mm_max_ps(a.quad(), b.quad());
}

inline hkVector4::hkVector4(const hkVector4& v) : m_vComponents(v.m_vComponents) {}
inline void hkVector4::cofactor(const hkVector4& b, const hkVector4& a)
{
    hkQuadReal p = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    hkQuadReal n = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(p, n);
}

inline RealLane hkVector4::inner3(const hkVector4& v) const
{
    hkQuadReal terms = _mm_mul_ps(m_vComponents, v.m_vComponents);
    hkQuadReal xy = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
    return _mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), xy);
}

inline void hkVector4::scaled(const hkQuadReal& scale, const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(scale, v.m_vComponents);
}





inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

inline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

inline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    const hkQuadReal b = v1.m_vComponents;
    const hkQuadReal a = v0.m_vComponents;
    m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                               _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}

inline hkMatrix3::hkMatrix3() {}
inline const hkVector4& hkMatrix3::getColumn(int iCol) const
{
    return (&m_kColumn0)[iCol];
}

inline hkVector4& hkMatrix3::getColumn(int iCol)
{
    return (&m_kColumn0)[iCol];
}

inline hkReal& hkMatrix3::operator()(int iRow, int iCol)
{
    return getColumn(iCol)(iRow);
}

inline void hkMatrix3::operator=(const hkMatrix3& kRhs)
{
    m_kColumn0 = kRhs.m_kColumn0;
    m_kColumn1 = kRhs.m_kColumn1;
    m_kColumn2 = kRhs.m_kColumn2;
}

inline void hkMatrix3::setZero()
{
    m_kColumn0.setZero4();
    m_kColumn1.setZero4();
    m_kColumn2.setZero4();
}

inline void hkMatrix3::addTo(hkMatrix3& dst) const
{
    dst.m_kColumn0.m_vComponents = _mm_add_ps(dst.m_kColumn0.m_vComponents, m_kColumn0.m_vComponents);
    dst.m_kColumn1.m_vComponents = _mm_add_ps(dst.m_kColumn1.m_vComponents, m_kColumn1.m_vComponents);
    dst.m_kColumn2.m_vComponents = _mm_add_ps(dst.m_kColumn2.m_vComponents, m_kColumn2.m_vComponents);
}

__forceinline void hkMatrix3::SetProduct(const hkMatrix3& a, const hkMatrix3& b) throw()
{
    const hkQuadReal c0 = a.m_kColumn0.m_vComponents;
    const hkQuadReal c1 = a.m_kColumn1.m_vComponents;
    const hkQuadReal c2 = a.m_kColumn2.m_vComponents;
    for (int i = 2; i >= 0; i--)
    {
        const hkQuadReal t = b.getColumn(i).m_vComponents;
        const hkQuadReal xb = _mm_shuffle_ps(t, t, 0x00);
        const hkQuadReal yb = _mm_shuffle_ps(t, t, 0x55);
        const hkQuadReal zb = _mm_shuffle_ps(t, t, 0xaa);
        getColumn(i).m_vComponents =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(xb, c0), _mm_mul_ps(yb, c1)), _mm_mul_ps(zb, c2));
    }
}

__forceinline void hkMatrix3::setMul2(const hkMatrix3& a, const hkMatrix3& b)
{
    const hkQuadReal& c1 = a.getColumn(1).m_vComponents;
    const hkQuadReal& c0 = a.getColumn(0).m_vComponents;
    const hkQuadReal& c2 = a.getColumn(2).m_vComponents;

    for (int i = 2; i >= 0; i--)
    {
        hkQuadReal t = b.getColumn(i).m_vComponents;
        hkQuadReal x = _mm_shuffle_ps(t, t, 0x00);
        hkQuadReal p = _mm_mul_ps(c0, x);
        hkQuadReal y = _mm_shuffle_ps(t, t, 0x55);
        hkQuadReal q = _mm_mul_ps(c1, y);
        hkQuadReal z = _mm_shuffle_ps(t, t, 0xaa);
        hkQuadReal w = _mm_mul_ps(c2, z);
        getColumn(i).m_vComponents = _mm_add_ps(_mm_add_ps(p, q), w);
    }
}

inline void hkMatrix3::transpose() throw()
{
    AlgorithmUtilities::swap(m_kColumn1(0), m_kColumn0(1));
    AlgorithmUtilities::swap(m_kColumn2(0), m_kColumn0(2));
    AlgorithmUtilities::swap(m_kColumn2(1), m_kColumn1(2));
}

inline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkQuadReal t = v.m_vComponents;
    hkQuadReal xb = _mm_shuffle_ps(t, t, 0x00);
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, xb);
    hkQuadReal yb = _mm_shuffle_ps(t, t, 0x55);
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, yb);
    hkQuadReal zb = _mm_shuffle_ps(t, t, 0xaa);
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, zb);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

namespace ConstraintInit {

static __forceinline hkQuadReal hkCross(const hkQuadReal& a, const hkQuadReal& b)
{
    const hkQuadReal cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    const hkQuadReal cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
extern hkQuadReal DAT_010c7170;
extern const double DAT_010da2b0;
extern const double DAT_010da2a8;
extern const float DAT_010da2a0;
struct BodyInput
{
    hkVector4 m_r;
    hkMatrix3 m_kInverseInertiaMatrix;
    hkVector4 m_vel;
    int m_50;
};
struct BodyResult
{
    hkMatrix3 m_pJacobian;
    hkMatrix3 m_ij;
    hkVector4 m_vel;
    hkReal m_fViscosityFriction;
    int m_74;
    int unk78;
    int unk7C;
};
struct SolverResult
{
    BodyResult m_apEntities[2];
    hkMatrix3 m_axes;
    hkMatrix3 m_kFirstMatrix;
    hkMatrix3 m_kSecondMatrix;
};
static __forceinline hkQuadReal hkDot3q(const hkQuadReal& a, const hkQuadReal& b)
{
    const hkQuadReal x2 = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
}
static __forceinline void inverseSymmetric(const hkMatrix3& m, float eps, hkMatrix3& inv)
{

    const hkVector4& central = m.getColumn(0);
    hkVector4 r0;
    r0.cofactor(m.getColumn(2), m.getColumn(1));
    hkVector4 r1;
    r1.cofactor(central, m.getColumn(2));
    hkVector4 r2;
    r2.cofactor(m.getColumn(1), central);
    RealLane minimum(eps * eps * eps);
    RealLane determinant = central.inner3(r0);
    maximumLane(determinant, minimum, determinant);
    RealLane inverse = reinterpret_cast<const RealLane&>(DAT_010c7170) / determinant;
    hkQuadReal factor = inverse.spread();
    inv.getColumn(0).scaled(factor, r0);
    inv.getColumn(1).scaled(factor, r1);
    inv.getColumn(2).scaled(factor, r2);
}
// @fnv 0x00df5950
// src: GUESS 0x00df5950 (confidence: medium)
extern "C" void __cdecl hkpCollision_BuildResponseMatrices(const BodyInput* bodyA, const BodyInput* bodyB, const hkMatrix3& axes,
                                     SolverResult* out)
{
    hkReal sumInvMass = bodyA->m_vel(3) + bodyB->m_vel(3);
    out->m_kFirstMatrix.setZero();
    out->m_kFirstMatrix(0, 0) = sumInvMass;
    out->m_kFirstMatrix(1, 1) = sumInvMass;
    out->m_kFirstMatrix(2, 2) = sumInvMass;
    out->m_axes = axes;
    const BodyInput* body = bodyA;
    for (int i = 0; i < 2; i++)
    {
        BodyResult& bo = out->m_apEntities[i];
        bo.m_pJacobian.m_kColumn0.setCross(body->m_r, axes.m_kColumn0);
        bo.m_pJacobian.m_kColumn1.setCross(body->m_r, axes.m_kColumn1);
        bo.m_pJacobian.m_kColumn2.setCross(body->m_r, axes.m_kColumn2);
        bo.m_ij.SetProduct(body->m_kInverseInertiaMatrix, bo.m_pJacobian);
        bo.m_pJacobian.transpose();
        hkMatrix3 tmp;
        tmp.setMul2(bo.m_pJacobian, bo.m_ij);
        tmp.addTo(out->m_kFirstMatrix);
        bo.m_vel = body->m_vel;
        bo.m_fViscosityFriction = 1.0f / MathUtilities::max2(body->m_vel(3), 1e-11f);
        bo.m_74 = body->m_50;
        body = bodyB;
    }
    hkMatrix3& m = out->m_kFirstMatrix;
    hkMatrix3& inv = out->m_kSecondMatrix;
    inverseSymmetric(m, 1e-11f, inv);
    _ReadWriteBarrier();
    hkMatrix3* __restrict mass = &m;
    hkReal a = (*mass)(0, 0);
    (*mass)(3, 0) = 1.0f / (a < DAT_010da2b0 ? 1e-11f : a);
    hkReal b = (*mass)(2, 2) * (*mass)(1, 1) - (*mass)(1, 2) * (*mass)(2, 1);
    (*mass)(3, 1) = 1.0f / (b < DAT_010da2a8 ? DAT_010da2a0 : b);
}

}
