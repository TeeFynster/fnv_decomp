#define FNV64_HKENUM_INLINE_BODIES
#define FNV64_HKENUM_FORCEINLINE
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#include "../../../../../../include/QuantizedFloat8.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkContactPointMaterial.h"
#include "../../../../../../include/hkTransform.h"
#include <xmmintrin.h>

#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkpSimpleContactConstraintAtom.h"


// src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct StateD72090
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
};
void _hkSimpleContactConstraintDataAddALittleSurfaceViscosity(StateD72090* out);
#include <string.h>
struct __declspec(align(16)) Buffer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};
extern "C" void __cdecl _hkSimpleContactConstraintDataAddALittleSurfaceViscosity(void*);
extern "C" void __cdecl hkSimpleContactConstraintDataBuildJacobian(hkpSimpleContactConstraintAtom*, Buffer*, int, int*);
extern "C" void __cdecl hkSolverBuildJacobianFromAtomsNotContact(hkpSimpleContactConstraintAtom*, unsigned short, Buffer*, int*);
extern "C" Buffer* __cdecl GetSharedBuffer();
static void __cdecl Object_CopyData_00d6c5a0(hkpSimpleContactConstraintAtom* self, int* counter, Buffer* source);
void __cdecl Caller(hkpSimpleContactConstraintAtom* self, int* counter);

#include <xmmintrin.h>

typedef float hkReal;
typedef __m128 hkQuadReal;
typedef unsigned short hkUint16;
typedef unsigned char hkUint8;
typedef signed char hkInt8;
typedef unsigned int hkUint32;

#include "../../../../../../include/hkPadSpu.h"   // Havok 7.1 hkPadSpu (was a unit-local ValueWrapper copy)


#include "../../../../../../include/hkEnum.h"
using ::hkEnum;

template <typename TYPE> __forceinline TYPE* hkAddByteOffset(TYPE* base, long offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

template <typename TYPE> __forceinline const TYPE* hkAddByteOffsetConst(const TYPE* base, long offset)
{
    return reinterpret_cast<const TYPE*>(reinterpret_cast<const char*>(base) + offset);
}

namespace MathUtilities {
template <typename T> __forceinline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

typedef const hkSimdReal& hkSimdRealParameter;

extern const hkQuadReal DAT_010c44d0;
extern const hkReal DAT_010c7948[];




__forceinline hkSimdReal::hkSimdReal(const hkQuadReal& x) : m_vValue(x)
{}

__forceinline hkSimdReal::hkSimdReal(hkReal x)
{
    m_vValue = _mm_load_ss(&x);
}

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



__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void hkVector4::mul4(const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4::mul4(hkSimdRealParameter s)
{
    m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
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

__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}

__forceinline void hkVector4::setAbs4(const hkVector4& v)
{
    static __declspec(align(16)) const hkUint32 absMask[4] = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};
    m_vComponents = _mm_and_ps(v.m_vComponents, *(const hkQuadReal*)&absMask);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
}

__forceinline hkSimdReal hkVector4::horizontalAdd3() const
{
    hkQuadReal vSum01 =
        _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(1, 1, 1, 1)), m_vComponents);
    return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(2, 2, 2, 2)), vSum01);
}

__forceinline hkSimdReal hkVector4::horizontalAdd4() const
{
    hkQuadReal vPairs =
        _mm_add_ps(_mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(1, 0, 3, 2)), m_vComponents);
    hkQuadReal vSwapped = _mm_shuffle_ps(vPairs, vPairs, _MM_SHUFFLE(2, 3, 0, 1));
    return _mm_add_ps(vPairs, vSwapped);
}

__forceinline hkSimdReal hkVector4::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}

// The shared vector declares normalize3 but has no lengthInverse3 member.
__forceinline hkQuadReal contactLengthInverse3(const hkVector4& vector)
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = vector.dot3(vector).getQuad();
    const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal approx = _mm_rsqrt_ss(len2);
    const hkQuadReal refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}

__forceinline void hkVector4::normalize3()
{
    hkQuadReal lenInv = hkSimdReal(contactLengthInverse3(*this)).broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}

__forceinline hkReal& hkVector4::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}

__forceinline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}

__forceinline void hkVector4::setW(const hkVector4& w)
{
    m_vComponents =
        _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, w.m_vComponents), _MM_SHUFFLE(3, 0, 1, 0));
}

__forceinline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    }
    else if (i == 1)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    }
    else if (i == 2)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    }
    else if (i == 3)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    }
}

__forceinline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i)
{
    setBroadcast(v, i);
}

__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

__forceinline const hkVector4& hkRotation::getColumn(int x) const
{
return (&m_kColumn0)[x];
}

__forceinline const hkVector4& hkTransform::getColumn(int x) const
{
    return reinterpret_cast<const hkRotation*>(&m_row0)->getColumn(x);
}

__forceinline const hkVector4& hkContactPoint::getPosition() const
{
    return m_vContactPosition;
}

__forceinline const hkVector4& hkContactPoint::getNormal() const
{
    return m_vSeparatingNormal;
}

__forceinline hkReal hkContactPoint::getDistance() const
{
    return m_vSeparatingNormal(3);
}

__forceinline QuantizedFloat8::operator hkReal() const
{
    // QuantizedFloat8 exposes its byte storage only through the conversion operator.
    return DAT_010c7948[*reinterpret_cast<const hkUint8*>(this)];
}

__forceinline hkReal hkContactPointMaterial::getFriction() const
{
    return m_fSlipAngle;
}

extern const hkTransform DAT_01268370;
__forceinline const hkTransform& __cdecl hkTransform::GetIdentityTransform()
{
    return DAT_01268370;
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

class ContactImpulseInfo
{
  public:
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;
};

class PhysicsMaterial : public ContactImpulseInfo, public hkContactPointMaterial
{
  public:
    hkReal m_uiUserData;
};

class UInt32Value
{
  public:
    __forceinline PhysicsMaterial* asProperties()
    {
        return reinterpret_cast<PhysicsMaterial*>(this);
    }
};

class ContactImpulseState
{
  public:
    hkUint16 m_flags;
    hkUint16 m_uiEdgeIndex;
    hkReal m_fAngularImpulseFactor;
    ContactImpulseInfo m_kContactImpulseInfos[3];
};

__forceinline hkContactPoint* hkpSimpleContactConstraintAtom::getContactPoints() const
{
    return const_cast<hkContactPoint*>(reinterpret_cast<const hkContactPoint*>(this + 1));
}

__forceinline int hkpSimpleContactConstraintAtom::getContactPointPropertiesStriding() const
{
    return m_ucContactPointPropertiesStriding;
}

__forceinline UInt32Value* hkpSimpleContactConstraintAtom::getContactPointPropertiesStream() const
{
    const hkContactPoint* endContactPoint =
        hkAddByteOffsetConst(getContactPoints(), sizeof(hkContactPoint) * m_usMaxNumContactPoints);
    const UInt32Value* beginningOfProperties = reinterpret_cast<const UInt32Value*>(endContactPoint);
    return const_cast<UInt32Value*>(hkAddByteOffsetConst(beginningOfProperties, 0));
}

class QuantizedBoundsData
{
  public:
    __forceinline const hkVector4& getScratch0() const
    {
        return m_vCenterOfMass;
    }
    __forceinline const hkVector4& getCenterOfMassInWorld() const
    {
        return getScratch0();
    }
    __forceinline const hkRotation& getCoreFromWorldMatrix() const
    {
        return m_scratch1;
    }

    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_uiDeactivationClass;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_vCenterOfMass;
    hkRotation m_scratch1;
};

class hkpConstraintInstance;

class ConstraintQueryData
{
  public:
    hkPadSpu<float> m_fQueryInputValue;
    hkPadSpu<float> m_iBeforeFourthQueryValue;
    hkPadSpu<float> m_kThirdChainValue;
    hkPadSpu<float> m_fFirstQueryValue;
    hkPadSpu<float> m_fSecondQueryValue;
    hkPadSpu<float> m_fInverseStepCount;
    hkPadSpu<float> m_fMaxConstraintViolation;
    hkPadSpu<float> m_maxConstraintViolationSqrdStep;
    hkPadSpu<float> m_fThirdQueryValue;
    hkPadSpu<float> m_fFourthQueryValue;
    hkPadSpu<float> m_fFifthQueryValue;
};

class __declspec(align(16)) SixteenWordFloatRecord : public ConstraintQueryData
{
  public:
    __declspec(align(16)) hkPadSpu<const QuantizedBoundsData*> m_pBodyA;
    hkPadSpu<const QuantizedBoundsData*> m_pBodyB;
    hkPadSpu<const hkTransform*> m_kBodyALocalFrame;
    hkPadSpu<const hkTransform*> m_kBodyBLocalFrame;
    hkPadSpu<hkReal> m_fTau;
    hkPadSpu<hkReal> m_fMotorDamping;
    hkSimdReal m_fMaxConstraintViolationSquared;
    hkPadSpu<hkpConstraintInstance*> m_pConstraintChainInstance;
    hkPadSpu<void*> m_pByteBuffer;
    hkPadSpu<void*> m_pOpaqueData;
    hkPadSpu<hkUint32> m_uiParameterA;
    hkPadSpu<hkUint32> m_uiParameterB;
};

class SolverSchemaHeader
{
  public:
    enum SolverSchemaType
    {
        SCHEMA_TYPE_HEADER = 1,
        SCHEMA_TYPE_SINGLE_CONTACT = 0x10,
        SCHEMA_TYPE_PAIR_CONTACT = 0x14,
        SCHEMA_TYPE_2D_FRICTION = 0x16,
        SCHEMA_TYPE_3D_FRICTION = 0x17
    };
    __forceinline static void setType(SolverSchemaHeader* schema, hkEnum<SolverSchemaType, hkInt8> type)
    {
        *reinterpret_cast<hkReal*>(schema) = *reinterpret_cast<hkReal*>(schema) + 1.192092896e-07f;
        *reinterpret_cast<hkEnum<SolverSchemaType, hkInt8>*>(hkAddByteOffset(schema, 0)) = type;
    }
};

class QueryResultSchema
{
  public:
    hkPadSpu<SolverSchemaHeader*> m_pQueryResultSchema;
};

class AngularJacobianElement
{
  public:
    __forceinline void setInvJacDiag(hkReal v)
    {
        m_kAngularVelocity[0](3) = v;
    }
    __forceinline hkReal getInvJacDiag() const
    {
        return m_kAngularVelocity[0](3);
    }
    __forceinline void setAngularRhs(hkReal v)
    {
        m_kAngularVelocity[1](3) = v;
    }
    __forceinline hkReal getAngularDiag(const QuantizedBoundsData& mA, const QuantizedBoundsData& mB) const
    {
        hkVector4 ang0;
        ang0.setMul4(m_kAngularVelocity[0], m_kAngularVelocity[0]);
        hkVector4 ang1;
        ang1.setMul4(m_kAngularVelocity[1], m_kAngularVelocity[1]);
        ang0.mul4(mA.m_vInverseInertiaAndMass);
        ang1.mul4(mB.m_vInverseInertiaAndMass);
        ang0.add4(ang1);
        const hkReal eps = 1.192092896e-07f;
        const hkReal diag = ang0.horizontalAdd3();
        return diag + eps;
    }
    hkVector4 m_kAngularVelocity[2];
};

class ConstraintJacobian
{
  public:
    __forceinline void setRHS(hkReal v)
    {
        m_kLinearJacobian(3) = v;
    }
    __forceinline void setInvJacDiag(hkReal v)
    {
        m_kAngularVelocity[0](3) = v;
    }
    __forceinline void setUserValue(hkReal v)
    {
        m_kAngularVelocity[1](3) = v;
    }
    __forceinline hkReal getUserValue() const
    {
        return m_kAngularVelocity[1](3);
    }
    __forceinline hkReal getDiag(const QuantizedBoundsData& mA, const QuantizedBoundsData& mB) const
    {
        const ConstraintJacobian& jac = *this;
        hkVector4 ang0;
        ang0.setMul4(jac.m_kAngularVelocity[0], jac.m_kAngularVelocity[0]);
        hkVector4 ang1;
        ang1.setMul4(jac.m_kAngularVelocity[1], jac.m_kAngularVelocity[1]);
        ang0.mul4(mA.m_vInverseInertiaAndMass);
        ang1.mul4(mB.m_vInverseInertiaAndMass);
        ang0.add4(ang1);
        hkVector4 sm;
        sm.setAdd4(mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass);
        ang0.setW(sm);
        hkReal dot = ang0.horizontalAdd4();
        return dot + 1.192092896e-07f;
    }
    __forceinline hkReal getNonDiagOptimized(const QuantizedBoundsData& mA, const QuantizedBoundsData& mB,
                                             const ConstraintJacobian& jacB) const
    {
        const ConstraintJacobian& jacA = *this;
        hkVector4 lin;
        const hkVector4& firstLinear = jacA.m_kLinearJacobian;
        lin.setMul4(firstLinear, jacB.m_kLinearJacobian);
        hkVector4 ang0;
        ang0.setMul4(jacA.m_kAngularVelocity[0], jacB.m_kAngularVelocity[0]);
        hkVector4 ang1;
        ang1.setMul4(jacA.m_kAngularVelocity[1], jacB.m_kAngularVelocity[1]);
        hkVector4 mA3;
        mA3.setBroadcast3clobberW(mA.m_vInverseInertiaAndMass, 3);
        hkVector4 mB3;
        mB3.setBroadcast3clobberW(mB.m_vInverseInertiaAndMass, 3);
        hkVector4 lin0;
        lin0.setMul4(mA3, lin);
        hkVector4 lin1;
        lin1.setMul4(mB3, lin);
        ang0.mul4(mA.m_vInverseInertiaAndMass);
        ang1.mul4(mB.m_vInverseInertiaAndMass);
        lin0.add4(lin1);
        ang0.add4(ang1);
        ang0.add4(lin0);
        hkReal d = ang0.horizontalAdd3();
        return d;
    }

    hkVector4 m_kLinearJacobian;
    hkVector4 m_kAngularVelocity[2];
};

class SolverRecordPair
{
  public:
    ConstraintJacobian m_kFirstFrictionJacobian;
    ConstraintJacobian m_kSecondFrictionJacobian;
};

class FrictionJacobianTriple
{
  public:
    ConstraintJacobian m_kFirstFrictionJacobian;
    ConstraintJacobian m_kSecondFrictionJacobian;
    AngularJacobianElement m_kAngularJacobian;
};

class QuantizedBoundsData;

class ConstraintHeaderSchema : public SolverSchemaHeader
{
  public:
    __forceinline void initHeader(hkpConstraintInstance* instance, int bodyA, int bodyB, ContactImpulseInfo* results,
                                  int solverResultStriding)
    {
        SolverSchemaHeader::setType(this, SCHEMA_TYPE_HEADER);
        m_pBodyA = (hkUint16)bodyA;
        m_pBodyB = (hkUint16)bodyB;
        m_solverResultInMainMemory = results;
        m_pConstraintChainInstance = instance;
        m_ucSecondHeaderByte = (hkUint8)solverResultStriding;
    }
    hkInt8 m_schemaType;
    hkUint8 m_ucSecondHeaderByte;
    hkUint16 m_auiShapeKeys;
    hkUint16 m_pBodyA;
    hkUint16 m_pBodyB;
    ContactImpulseInfo* m_solverResultInMainMemory;
    hkpConstraintInstance* m_pConstraintChainInstance;
};

class JacobianPointerSchema : public SolverSchemaHeader
{
  public:
    __forceinline void initSingleContact(const ConstraintJacobian& jac, int jacIdx)
    {
        const int type = SCHEMA_TYPE_SINGLE_CONTACT + jacIdx;
        SolverSchemaHeader::setType(this, (SolverSchemaType)type);
    }
    ConstraintJacobian m_pJacobian;
};

class JacobianPair : public SolverSchemaHeader
{
  public:
    __forceinline void initPairContact(const SolverRecordPair& jac, hkReal invJac01, int jacIdx)
    {
        m_fOffDiagonal = invJac01;
        const int type = SCHEMA_TYPE_PAIR_CONTACT + jacIdx;
        SolverSchemaHeader::setType(this, (SolverSchemaType)type);
    }
    SolverRecordPair m_pJacobian;
    hkReal m_fOffDiagonal;
};

class TwoAxisFrictionInfo : public SolverSchemaHeader
{
  public:
    __forceinline void init2dFriction(const SolverRecordPair& jac, hkReal maxFrictionForce, hkReal invJac01,
                                      ContactImpulseInfo* results)
    {
        m_fOffDiagonal = invJac01;
        m_fFriction = maxFrictionForce;
        m_pSolverResults = results;
        SolverSchemaHeader::setType(this, SCHEMA_TYPE_2D_FRICTION);
    }
    SolverRecordPair m_pJacobian;
    hkReal m_fOffDiagonal;
    hkReal m_fFriction;
    ContactImpulseInfo* m_pSolverResults;
    hkReal m_auiShapeKeys;
};

class Friction3DSchema : public SolverSchemaHeader
{
  public:
    __forceinline void init3dFriction(const FrictionJacobianTriple& jac, hkReal maxFrictionForce, hkReal invJac01,
                                      hkReal radius, ContactImpulseInfo* results)
    {
        m_fOffDiagonal = invJac01;
        m_fFriction = maxFrictionForce;
        m_fSphereRadius = radius;
        m_pSolverResults = results;
        SolverSchemaHeader::setType(this, SCHEMA_TYPE_3D_FRICTION);
    }
    FrictionJacobianTriple m_pJacobian;
    hkReal m_fOffDiagonal;
    hkReal m_fFriction;
    hkReal m_fSphereRadius;
    ContactImpulseInfo* m_pSolverResults;
};

namespace hkVector4Util_S {
__forceinline void reserveRegisters(hkUint32 r)
{}
__forceinline void releaseRegisters(hkUint32 r)
{}
}

namespace QuantizedBoundsBuilder {
__forceinline void initBuilder(const QuantizedBoundsData* opaA, const QuantizedBoundsData* opaB, hkReal invDt)
{
    hkVector4Util_S::reserveRegisters(0x0fff0000);
}

__forceinline void exitBuilder()
{
    hkVector4Util_S::releaseRegisters(0x0fff0000);
}

__forceinline void copyJacRegToJac1Reg()
{}

__forceinline hkQuadReal contactRotate(const hkRotation& rotation, const hkVector4& direction)
{
    hkVector4 rotated;
    rotated._setMul3(rotation, direction);
    return rotated.m_vComponents;
}
__forceinline void buildContactBegin(const QuantizedBoundsData* opaA, const QuantizedBoundsData* opaB,
                                     const hkVector4& position, const hkVector4& direction, hkReal invJacFactor,
                                     ConstraintJacobian& jac)
{
    jac.m_kLinearJacobian = direction;
    hkVector4 massCenterRelative0;
    massCenterRelative0.setSub4(position, opaA->getCenterOfMassInWorld());
    hkVector4 massCenterRelative1;
    massCenterRelative1.setSub4(position, opaB->getCenterOfMassInWorld());
    hkVector4 cross0;
    cross0.setCross(massCenterRelative0, direction);
    hkVector4 cross1;
    cross1.setCross(direction, massCenterRelative1);
    jac.m_kAngularVelocity[0].m_vComponents = contactRotate(opaA->getCoreFromWorldMatrix(), cross0);
    jac.m_kAngularVelocity[1]._setRotatedDir(opaB->getCoreFromWorldMatrix(), cross1);
    hkReal a = jac.getDiag(*opaA, *opaB);
    jac.setUserValue(a);
    jac.setInvJacDiag(invJacFactor / a);
}

__forceinline void buildLinearBegin(const QuantizedBoundsData* opaA, const QuantizedBoundsData* opaB,
                                    const hkVector4& position, const hkVector4& direction, hkReal invJacFactor,
                                    ConstraintJacobian& jac)
{
    jac.m_kLinearJacobian = direction;
    hkVector4 massCenterRelative0;
    massCenterRelative0.setSub4(position, opaA->getCenterOfMassInWorld());
    hkVector4 massCenterRelative1;
    massCenterRelative1.setSub4(position, opaB->getCenterOfMassInWorld());
    hkVector4 cross0;
    cross0.setCross(massCenterRelative0, direction);
    hkVector4 cross1;
    cross1.setCross(direction, massCenterRelative1);
    jac.m_kAngularVelocity[0]._setRotatedDir(opaA->getCoreFromWorldMatrix(), cross0);
    jac.m_kAngularVelocity[1]._setRotatedDir(opaB->getCoreFromWorldMatrix(), cross1);
    hkReal a = jac.getDiag(*opaA, *opaB);
    jac.setUserValue(a);
    jac.setInvJacDiag(invJacFactor / a);
}

__forceinline void buildLinearEnd(ConstraintJacobian& jac, hkReal rhs, hkReal factor)
{
    jac.setRHS(rhs * factor);
}

__forceinline void buildAngularBegin(const QuantizedBoundsData* opaA, const QuantizedBoundsData* opaB,
                                     const hkVector4& direction, hkReal virtMassFactor, AngularJacobianElement& jac)
{
    hkVector4Util_S::reserveRegisters(0xf0000000);
    hkVector4 negDir;
    negDir.setNeg4(direction);
    jac.m_kAngularVelocity[0]._setRotatedDir(opaA->getCoreFromWorldMatrix(), direction);
    jac.m_kAngularVelocity[1]._setRotatedDir(opaB->getCoreFromWorldMatrix(), negDir);
    hkReal diag = jac.getAngularDiag(*opaA, *opaB);
    jac.setInvJacDiag(virtMassFactor / diag);
}

__forceinline void mulInvJacDiag(AngularJacobianElement* jac, hkReal m)
{
    jac->setInvJacDiag(jac->getInvJacDiag() * m);
}

__forceinline void buildAngularEnd(AngularJacobianElement& jac, hkReal rhs, hkReal factor)
{
    jac.setAngularRhs(rhs * factor);
    hkVector4Util_S::releaseRegisters(0xf0000000);
}

__forceinline hkReal getInvJac01Optimized(const QuantizedBoundsData* opaA, const QuantizedBoundsData* opaB,
                                          ConstraintJacobian* jac, hkReal virtMassFactor, hkReal nonDiagFactor)
{
    hkReal nonDiag = jac[1].getNonDiagOptimized(*opaA, *opaB, jac[0]);
    hkReal a = jac[0].getUserValue();
    hkReal b = jac[1].getUserValue();
    nonDiag *= nonDiagFactor;
    const hkReal invDet = virtMassFactor / (a * b - nonDiag * nonDiag);
    jac[0].setUserValue(b * invDet);
    jac[1].setUserValue(a * invDet);
    return -nonDiag * invDet;
}

__forceinline void addLastPosition(const hkVector4& pos, const hkVector4& dir, hkVector4& sumPos, hkVector4& sumDir)
{
    sumPos.add4(pos);
    sumDir.add4(dir);
}
}

extern hkReal DAT_011b6924;
extern hkReal DAT_011b6928;

__forceinline hkReal calculateRhs(const hkContactPoint* ccp, PhysicsMaterial& sr, hkReal distance, hkReal dt,
                                  int& solverResultsModified)
{
    hkReal distanceOffset = sr.m_uiUserData;
    hkReal RHS = distance - distanceOffset;
    const hkReal estimatedRHS = -sr.m_fImpulseLimit;
    const hkReal secondOrderError = estimatedRHS - RHS;
    const hkReal maxDiff = dt * DAT_011b6924;
    hkReal distanceOffsetRelaxation = MathUtilities::min2(-DAT_011b6928 * distanceOffset, maxDiff);
    distanceOffset += distanceOffsetRelaxation;
    RHS -= distanceOffsetRelaxation;
    if (secondOrderError > 2.0 * distanceOffsetRelaxation + maxDiff)
    {
        distanceOffset -= secondOrderError;
        RHS += secondOrderError;
    }
    sr.m_uiUserData = MathUtilities::min2(distanceOffset, -1.192092896e-07f);
    return RHS;
}

// @fnv 0x00d72190
// src: XBOX_PDB 0x00d72190
extern "C" void __cdecl hkSimpleContactConstraintDataBuildJacobian(hkpSimpleContactConstraintAtom* atomNode, Buffer* queryIn, int writeHeader, int* queryOut)
{
    int modified = 0;
    const hkContactPoint* __restrict contacts =
        static_cast<const hkpSimpleContactConstraintAtom*>(atomNode)->getContactPoints();
    const int numContacts = static_cast<const hkpSimpleContactConstraintAtom*>(atomNode)->m_usNumContactPoints;
    UInt32Value* properties =
        static_cast<const hkpSimpleContactConstraintAtom*>(atomNode)->getContactPointPropertiesStream();
    int propertiesStriding =
        static_cast<const hkpSimpleContactConstraintAtom*>(atomNode)->getContactPointPropertiesStriding();
    UInt32Value* propertiesInMainMemory = properties;
    ContactImpulseState& info = *reinterpret_cast<ContactImpulseState*>(
        &atomNode->m_infoFlags);

    hkVector4 avgPosition;
    avgPosition.setZero4();
    hkVector4 avgNormal;
    avgNormal.setZero4();
    hkReal sumImpulse = 0.0f;
    hkReal invNum = 1.0f / numContacts;
    hkReal sumFriction = 0.0f;

    SolverSchemaHeader* com = reinterpret_cast<QueryResultSchema*>(queryOut)->m_pQueryResultSchema;
    const QuantizedBoundsData* opaA = reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_pBodyA;
    const QuantizedBoundsData* opaB = reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_pBodyB;

    if ((char)writeHeader)
    {
        ConstraintHeaderSchema* header = reinterpret_cast<ConstraintHeaderSchema*>(com);
        header->initHeader(
            reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_pConstraintChainInstance,
            reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_uiParameterA,
            reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_uiParameterB,
            reinterpret_cast<ContactImpulseInfo*>(propertiesInMainMemory->asProperties()),
            static_cast<const hkpSimpleContactConstraintAtom*>(atomNode)->getContactPointPropertiesStriding());
        com = reinterpret_cast<SolverSchemaHeader*>(header + 1);
    }

    QuantizedBoundsBuilder::initBuilder(opaA, opaB,
                                        reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_kThirdChainValue);

    {
        hkBool jac0Initialized(false);
        const hkContactPoint* contact = contacts;
        UInt32Value* sr = properties;
        int srStriding = propertiesStriding;
        int i = 0;
        do
        {
            const int contactUsesSolverPath2 = sr->asProperties()->m_flags & 2;
            ConstraintJacobian* __restrict jac1Lin2Ang = reinterpret_cast<ConstraintJacobian*>(com);
            const int jacIdx = 0;

            QuantizedBoundsBuilder::buildContactBegin(
                opaA, opaB, contact->getPosition(), contact->getNormal(),
                reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFourthQueryValue, *jac1Lin2Ang);

            sumFriction += sr->asProperties()->getFriction();
            sumImpulse += sr->asProperties()->m_fAccumulatedImpulse;

            const hkReal rhs =
                -calculateRhs(contact, *sr->asProperties(), contact->getDistance(),
                              reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFirstQueryValue, modified);
            QuantizedBoundsBuilder::buildLinearEnd(
                *jac1Lin2Ang, rhs, reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fThirdQueryValue);

            QuantizedBoundsBuilder::addLastPosition(contact->getPosition(), contact->getNormal(), avgPosition,
                                                    avgNormal);

            if (!contactUsesSolverPath2)
            {
                int maxImpulse = *reinterpret_cast<const hkUint8*>(&sr->asProperties()->m_usFlags);
                JacobianPointerSchema* sc = reinterpret_cast<JacobianPointerSchema*>(com);
                QuantizedBoundsBuilder::copyJacRegToJac1Reg();
                sc->initSingleContact(*jac1Lin2Ang, 0);
                com = reinterpret_cast<SolverSchemaHeader*>(sc + 1);
                jac0Initialized = true;
                if (maxImpulse != 0)
                {
                    const int typeAddon = 2;
                    sc->initSingleContact(*jac1Lin2Ang, typeAddon);
                    jac1Lin2Ang->setUserValue(DAT_010c7948[maxImpulse]);
                }
            }
            else
            {
                JacobianPointerSchema* single = reinterpret_cast<JacobianPointerSchema*>(com);
                JacobianPair* sc = reinterpret_cast<JacobianPair*>(single - 1);
                const hkReal jacNonDiagFactor = 0.99f;
                const int jacIdx2 = 0;
                const hkReal invJac01 = QuantizedBoundsBuilder::getInvJac01Optimized(
                    opaA, opaB, jac1Lin2Ang - 1,
                    reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFourthQueryValue, jacNonDiagFactor);
                sc->initPairContact(*reinterpret_cast<const SolverRecordPair*>(jac1Lin2Ang - 1), invJac01, 0);
                com = reinterpret_cast<SolverSchemaHeader*>(sc + 1);
                jac0Initialized = false;
            }

            sr = hkAddByteOffset(sr, srStriding);
            contact = contact + 1;
            i++;
        } while (i < numContacts);
    }

    hkVector4 biNormal;
    hkVector4 biNormal2;
    hkReal maxImp = sumImpulse * sumFriction * invNum;
    if (maxImp > 0.0f)
    {
        {
            hkReal invNum2 = invNum * invNum;
            hkReal nl = avgNormal.lengthSquared3();
            if (nl * invNum2 > 0.9999f)
            {
                avgNormal = contacts->getNormal();
            }
            else if (nl > 0.1f)
            {
                avgNormal.normalize3();
            }
            else
            {
                avgNormal = contacts->getNormal();
                nl = avgNormal.dot3(avgNormal);
                if (nl < 0.9f)
                {
                    maxImp = 0.0f;
                    avgNormal.setZero4();
                    avgNormal(1) = 1.0f;
                }
            }

            biNormal = hkTransform::GetIdentityTransform().getColumn(info.m_uiEdgeIndex);
            biNormal2.setCross(biNormal, avgNormal);
            hkReal d = biNormal2.dot3(biNormal2);
            if (d > 0.1f)
            {
            }
            else
            {
                hkVector4 absNormal;
                absNormal.setAbs4(avgNormal);
                if (absNormal(0) < absNormal(1))
                {
                    info.m_uiEdgeIndex = (absNormal(0) < absNormal(2)) ? hkUint16(0) : hkUint16(2);
                }
                else
                {
                    info.m_uiEdgeIndex = (absNormal(1) < absNormal(2)) ? hkUint16(1) : hkUint16(2);
                }
                info.m_kContactImpulseInfos[0].m_fImpulseLimit = 0.0f;
                info.m_kContactImpulseInfos[1].m_fImpulseLimit = 0.0f;
                biNormal = hkTransform::GetIdentityTransform().getColumn(info.m_uiEdgeIndex);
                biNormal2.setCross(biNormal, avgNormal);
            }
            biNormal2.normalize3();
            biNormal.setCross(avgNormal, biNormal2);
        }
        avgPosition.mul4(hkSimdReal(invNum));

        ContactImpulseInfo* solverResults = &info.m_kContactImpulseInfos[0];
        FrictionJacobianTriple& tripleJac = *reinterpret_cast<FrictionJacobianTriple*>(com);

        QuantizedBoundsBuilder::buildLinearBegin(
            opaA, opaB, avgPosition, biNormal,
            reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFourthQueryValue,
            tripleJac.m_kFirstFrictionJacobian);
        {
            hkReal rhs = info.m_kContactImpulseInfos[0].m_fImpulseLimit;
            QuantizedBoundsBuilder::buildLinearEnd(
                tripleJac.m_kFirstFrictionJacobian, rhs,
                reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFifthQueryValue);
        }

        QuantizedBoundsBuilder::copyJacRegToJac1Reg();
        QuantizedBoundsBuilder::buildLinearBegin(
            opaA, opaB, avgPosition, biNormal2,
            reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFourthQueryValue,
            tripleJac.m_kSecondFrictionJacobian);
        {
            hkReal rhs = info.m_kContactImpulseInfos[1].m_fImpulseLimit;
            QuantizedBoundsBuilder::buildLinearEnd(
                tripleJac.m_kSecondFrictionJacobian, rhs,
                reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFifthQueryValue);
        }

        TwoAxisFrictionInfo* frictionSchema = reinterpret_cast<TwoAxisFrictionInfo*>(com);
        hkReal invJac01 = QuantizedBoundsBuilder::getInvJac01Optimized(
            opaA, opaB, &tripleJac.m_kFirstFrictionJacobian,
            reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFourthQueryValue, 1.0f);
        hkReal corrMaxImpulse =
            reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fMaxConstraintViolation * maxImp;
        frictionSchema->init2dFriction(*reinterpret_cast<const SolverRecordPair*>(&tripleJac), corrMaxImpulse, invJac01,
                                       solverResults);
        com = reinterpret_cast<SolverSchemaHeader*>(frictionSchema + 1);

        if (numContacts > 1)
        {
            while (true)
            {
                if ((info.m_flags & 4) == 0)
                {
                    const hkReal radius = info.m_fAngularImpulseFactor;
                    const hkReal f = 1.0f / radius;
                    QuantizedBoundsBuilder::buildAngularBegin(
                        opaA, opaB, avgNormal,
                        reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFourthQueryValue,
                        tripleJac.m_kAngularJacobian);
                    QuantizedBoundsBuilder::buildAngularEnd(
                        tripleJac.m_kAngularJacobian, info.m_kContactImpulseInfos[2].m_fImpulseLimit,
                        reinterpret_cast<const SixteenWordFloatRecord*>(queryIn)->m_fFifthQueryValue);
                    QuantizedBoundsBuilder::mulInvJacDiag(&tripleJac.m_kAngularJacobian, f);
                    Friction3DSchema* sc = reinterpret_cast<Friction3DSchema*>(frictionSchema);
                    sc->init3dFriction(tripleJac, corrMaxImpulse, invJac01, info.m_fAngularImpulseFactor,
                                       solverResults);
                    com = reinterpret_cast<SolverSchemaHeader*>(sc + 1);
                    break;
                }
                info.m_fAngularImpulseFactor = 0.0f;
                hkReal& radius = info.m_fAngularImpulseFactor;
                const hkContactPoint* cp = contacts;
                for (int j = numContacts - 1; j >= 0; j--)
                {
                    hkVector4 diff;
                    diff.setSub4(cp->getPosition(), avgPosition);
                    info.m_fAngularImpulseFactor = hkReal(diff.length3()) + info.m_fAngularImpulseFactor;
                    cp = cp + 1;
                }
                radius = radius * invNum;
                if (radius < 1e-6f)
                {
                    break;
                }
                info.m_flags &= 0xfffb;
            }
        }
    }
    reinterpret_cast<QueryResultSchema*>(queryOut)->m_pQueryResultSchema = com;
    QuantizedBoundsBuilder::exitBuilder();
}
