#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#define FNV64_HKENUM_INLINE_BODIES
#define FNV64_HKENUM_FORCEINLINE
#define FNV64_HKENUM_COMPARISONS
// src/havok/physics/constraintsolver/solve/hkpsolver_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/constraintsolver/solve/hkpsolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


#include "fnv_asm_helpers.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkSimdReal.h"
#define FNV64_HKVECTOR4_OWN_COPY
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMatrix3.h"
#include "../../../../../include/hkpVelocityAccumulator.h"

__forceinline const hkVector4& hkMatrix3::getColumn(int i) const { return (&m_kColumn0)[i]; }
// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern unsigned char DAT_011b9434[128];
int __cdecl Hkpsolver_GetIndexedValue_00d921d0(const signed char* index);
using ::_mm_add_ss;
// Adds the lowest single-precision float of b to that of a and stores the result in out.
// @fnv 0x00c6cce0
extern "C" void __cdecl AddScalarFloat(LocalM128* pResult, const LocalM128* pLeft, const LocalM128* pRight)
{
    *pResult = _mm_add_ss(*pLeft, *pRight);
}
char* __cdecl Object_ComputeValue_00d921c0(char* dst, const char* src);
using ::_mm_sub_ss;
// @fnv 0x00c6ccc0
extern "C" void __cdecl SubtractScalarFloat(LocalM128* pResult, const LocalM128* pLeft, const LocalM128* pRight)
{
    *pResult = _mm_sub_ss(*pLeft, *pRight);
}
void hkSolveUpload();

#include <math.h>
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_mul_ss;
using ::_mm_min_ps;
using ::_mm_max_ps;
using ::_mm_load_ss;
using ::_mm_store_ss;
using ::_mm_load_ps;
extern LocalM128 DAT_010c7160;
extern unsigned char DAT_01269204;
typedef float hkReal;
typedef LocalM128 hkQuadReal;
__forceinline hkSimdReal::hkSimdReal(const hkQuadReal& x) : m_vValue(x) {}
__forceinline hkSimdReal::hkSimdReal(hkReal x) { m_vValue = _mm_load_ss(&x); }
__forceinline hkSimdReal::hkSimdReal() {}
__forceinline hkSimdReal::operator hkReal() const
{
    hkReal s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline hkQuadReal hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
__forceinline const hkQuadReal& hkSimdReal::getQuad() const { return m_vValue; }
// The shared scalar SIMD class is named hkSimdReal in this tree.
typedef const hkSimdReal& hkSimdRealParameter;
__forceinline void hkSimdReal_setMax(hkSimdRealParameter a, hkSimdRealParameter b, hkSimdReal& result)
{
    result = hkSimdReal(_mm_max_ps(a.getQuad(), b.getQuad()));
}
__forceinline void hkSimdReal_setMin(hkSimdRealParameter a, hkSimdRealParameter b, hkSimdReal& result)
{
    result = hkSimdReal(_mm_min_ps(a.getQuad(), b.getQuad()));
}
__forceinline void hkSimdReal_store(hkSimdRealParameter a, float* f)
{
    _mm_store_ss(f, a.getQuad());
}
__forceinline hkSimdReal operator*(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_mul_ss(r.getQuad(), s.getQuad()); }
__forceinline hkSimdReal operator-(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_sub_ss(r.getQuad(), s.getQuad()); }
__forceinline hkSimdReal operator+(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
__forceinline hkSimdReal operator-(hkSimdRealParameter r) { return _mm_sub_ss(DAT_010c7160, r.getQuad()); }
hkSimdReal __cdecl SubtractScalarFloat(hkSimdRealParameter r, hkSimdRealParameter s);
hkSimdReal __cdecl Object_ProcessAndReturnValue_00891060(hkSimdRealParameter r, hkSimdRealParameter s);
__declspec(noinline) hkSimdReal __cdecl AddScalarFloat(hkSimdRealParameter r, hkSimdRealParameter s) { return _mm_add_ss(r.getQuad(),s.getQuad()); }
// Solver adapter: getSimdAtE(2) supplies zero rather than the vector's third lane.
class SolverVector4
{
public:
    __forceinline void commitIncrement(SolverVector4& dest) const { dest.add4(*this); }
    __forceinline operator hkQuadReal() const { return m_vComponents; }
    __forceinline void operator=(const hkQuadReal& q) { m_vComponents = q; }
    __forceinline void operator=(const SolverVector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline void add4(const SolverVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add3clobberW(const SolverVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const SolverVector4& a, const SolverVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub3clobberW(const SolverVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const SolverVector4& a, const SolverVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const SolverVector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const SolverVector4& a, const SolverVector4& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(hkSimdRealParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(hkSimdRealParameter r, const SolverVector4& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline hkSimdReal horizontalAdd3() const
    {
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    __forceinline hkReal& operator()(int a) { return reinterpret_cast<hkReal*>(&m_vComponents)[a]; }
    __forceinline const hkReal& operator()(int a) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[a]; }
    __forceinline hkSimdReal getSimdAtE(int i) const
    {
        switch (i)
        {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2: return (hkQuadReal)DAT_010c7160;
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline hkSimdReal getSimdAt(int i) const
    {
        switch (i)
        {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void setBroadcast(const SolverVector4& v, int i) {
        if (i == 0) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void setBroadcast3clobberW(const SolverVector4& v, int i) { setBroadcast(v, i); }
    void hkVector4_setMul3(const hkMatrix3& a, const SolverVector4& b);
    __forceinline void SetRotatedVector(const hkMatrix3& a, const SolverVector4& b) { hkVector4_setMul3(a, b); }
    hkQuadReal m_vComponents;
};

#include "../../../../../include/hkPadSpu.h"   // Havok 7.1 hkPadSpu (was a unit-local ValueWrapper copy)
struct ConstraintSolverInfo
{
    float unk00, m_fTau, m_fMotorDamping, m_fPostDampingParameter;
    SolverVector4 unk10, unk20;
    SolverVector4 m_kGravity;
    SolverVector4 m_kTimeStep;
};
struct FloatRecord { float m_fAccumulatedImpulse; };
class QuantizedBoundsData
{
public:
    int unk00;
    __forceinline const SolverVector4& getSumLinearVel() const { return m_sumLinearVel; }
    __forceinline SolverVector4& getSumLinearVel() { return m_sumLinearVel; }
    __forceinline const SolverVector4& getSumAngularVel() const { return m_sumAngularVel; }
    SolverVector4 m_vLinearVelocity;
    SolverVector4 m_vAngularVelocity;
    SolverVector4 m_vInverseInertiaAndMass;
    SolverVector4 m_sumLinearVel;
    SolverVector4 m_sumAngularVel;
    SolverVector4 unk60;
    SolverVector4 unk70;
};
template <class T> __forceinline T* hkSelect(int i, T* a, T* b)
{
    unsigned long ua = (unsigned long)a;
    unsigned long ub = (unsigned long)b;
    return reinterpret_cast<T*>(ua ^ ((ua ^ ub) & (-i)));
}
struct SolverStepInfo
{
    hkPadSpu<int> m_intStep;
    hkPadSpu<hkReal> m_stepFactor;
};
enum SolverSchemaType
{
    SCHEMA_TYPE_END = 0,
    SCHEMA_TYPE_HEADER = 1,
    SCHEMA_TYPE_GOTO = 2,
    SCHEMA_TYPE_NOP = 3,
    SCHEMA_TYPE_1D_BILATERAL = 5,
    SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT = 6,
    SCHEMA_TYPE_1D_BILATERAL_USER_TAU = 7,
    SCHEMA_TYPE_1D_LINEAR_LIMITS = 8,
    SCHEMA_TYPE_1D_FRICTION = 9,
    SCHEMA_TYPE_1D_LINEAR_MOTOR = 10,
    SCHEMA_TYPE_1D_PULLEY = 11,
    SCHEMA_TYPE_1D_ANGULAR = 12,
    SCHEMA_TYPE_1D_ANGULAR_LIMITS = 13,
    SCHEMA_TYPE_1D_ANGULAR_FRICTION = 14,
    SCHEMA_TYPE_1D_ANGULAR_MOTOR = 15,
    SCHEMA_TYPE_SINGLE_CONTACT = 16,
    SCHEMA_TYPE_SINGLE_CONTACT2 = 17,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT = 18,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2 = 19,
    SCHEMA_TYPE_PAIR_CONTACT = 20,
    SCHEMA_TYPE_PAIR_CONTACT2 = 21,
    SCHEMA_TYPE_2D_FRICTION = 22,
    SCHEMA_TYPE_3D_FRICTION = 23,
    SCHEMA_TYPE_2D_ROLLING_FRICTION = 24,
    SCHEMA_TYPE_SET_MASS = 25,
    SCHEMA_TYPE_ADD_VELOCITY = 26,
    SCHEMA_TYPE_SET_CENTER_OF_MASS = 27,
    SCHEMA_TYPE_STIFF_SPRING_CHAIN = 29,
    SCHEMA_TYPE_BALL_SOCKET_CHAIN = 30,
    SCHEMA_TYPE_POWERED_CHAIN = 31
};

#include "../../../../../include/hkEnum.h"
using ::hkEnum;
typedef hkEnum<SolverSchemaType, signed char> SchemaEnum;
class SolverSchemaHeader
{
public:
    SchemaEnum m_type;
};
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* base, long offset)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(base) + offset);
}
__forceinline SchemaEnum getType(const SolverSchemaHeader* s) { return *reinterpret_cast<const SchemaEnum*>(hkAddByteOffsetConst(s, 0)); }
__forceinline int getNumSolverElemTemps(const SolverSchemaHeader* s)
{
    const int numSolverElemTemps = DAT_011b9434[(SolverSchemaType)getType(s)];
    return numSolverElemTemps;
}
SchemaEnum __cdecl Object_ComputeValue_00d921c0(const SolverSchemaHeader* s);
// src: GUESS 0x00d921d0 (confidence: low)
inline int __cdecl Hkpsolver_GetIndexedValue_00d921d0(const SolverSchemaHeader* s) {return DAT_011b9434[(int)s->m_type];}
class __declspec(align(16)) ConstraintHeaderSchema : public SolverSchemaHeader
{
public:
    __forceinline QuantizedBoundsData* getBodyA(QuantizedBoundsData* base) const
    {
        return reinterpret_cast<QuantizedBoundsData*>(reinterpret_cast<char*>(base) + ((int)m_pBodyA << 7));
    }
    __forceinline QuantizedBoundsData* getBodyB(QuantizedBoundsData* base) const
    {
        return reinterpret_cast<QuantizedBoundsData*>(reinterpret_cast<char*>(base) + ((int)m_pBodyB << 7));
    }
    unsigned char unk01;
    unsigned short m_numTemps;
    unsigned short m_pBodyA;
    unsigned short m_pBodyB;
};
class SchemaJump : public SolverSchemaHeader
{
public:
    int m_offset;
};
class ConstraintJacobian
{
public:
    __forceinline const hkReal& getRHS() const { return m_kLinearJacobian(3); }
    __forceinline const hkSimdReal getRhsSr() const { return m_kLinearJacobian.getSimdAt(3); }
    __forceinline const hkSimdReal getRhsSrE() const { return m_kLinearJacobian.getSimdAtE(3); }
    __forceinline hkReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline hkSimdReal getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    __forceinline hkReal getUserValue() const { return m_kAngularVelocity[1](3); }
    __forceinline hkSimdReal getUserValueSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    SolverVector4 m_kLinearJacobian;
    SolverVector4 m_kAngularVelocity[2];
};
class AngularJacobianElement
{
public:
    __forceinline hkReal getAngularRhs() const { return m_kAngularVelocity[1](3); }
    __forceinline hkSimdReal getAngularRhsSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    __forceinline hkReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline hkSimdReal getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    SolverVector4 m_kAngularVelocity[2];
};
class JacobianElement
{
public:
    __forceinline hkSimdReal getRhsSr() const { return m_kTranslationalVelocity[0].getSimdAt(3); }
    __forceinline hkSimdReal getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    SolverVector4 m_kTranslationalVelocity[2];
    SolverVector4 m_kAngularVelocity[2];
};
class JacobianPair { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; hkReal m_offDiag; };
class Friction3DSchema { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; AngularJacobianElement m_kAngularVelocity; hkReal m_offDiag, m_maxFrictionImpulse, m_angularFactor; };
class TwoAxisFrictionInfo { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; hkReal m_offDiag, m_maxFrictionImpulse; };
class Friction2DSchema { public: AngularJacobianElement m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; hkReal m_maxFrictionImpulse; };
class JacobianPointerSchema : public ConstraintJacobian {};
class JacobianDataHolder : public ConstraintJacobian {};
class LinearSoftConstraintAtom : public ConstraintJacobian { public: hkReal m_userTau, m_userDamping; };
class FrictionImpulseLimitAtom : public ConstraintJacobian { public: hkReal m_maxFrictionImpulse; };
class LinearDistanceLimitAtom : public ConstraintJacobian { public: hkReal m_minLimit, m_maxLimit; };
struct hkpMotorInfo { hkReal m_minImpulse, m_usFlags, m_fVelocity, m_fTau, m_fMotorDamping; };
class MotorSolverSchema : public ConstraintJacobian { public: hkpMotorInfo m_pMotor; };
class JacobianHolder : public AngularJacobianElement {};
class FrictionImpulseLimitedJacobian : public AngularJacobianElement { public: hkReal m_maxFrictionImpulse; };
class AngularLimitJacobian : public AngularJacobianElement { public: hkReal m_minLimit, m_maxLimit, m_userTau; };
class MotorInfoRecord : public AngularJacobianElement { public: hkpMotorInfo m_pMotor; };
class SingleJacobianSchema : public JacobianElement {};
class SetInverseMassSchema { public: SolverVector4 m_invMassA, m_invMassB; };
class AddVelocitySchema { public: SolverVector4 m_fVelocity; int m_iBodyIndex; };
class hkpJacobianSetComSchema { public: hkMatrix3 m_angularA, m_angularB; };
void __cdecl ValidateHavokKeyCode(unsigned char*);
class hkpStiffChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpBallChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpPoweredChainSchema : public SolverSchemaHeader { public: unsigned char flags; unsigned short m_numTemps, m_pBodyA, m_pBodyB; int unk08, unk0c, m_nextOffset; };
void __cdecl Object_ProcessEntries_00d893a0(const ConstraintSolverInfo*, const SolverStepInfo*, QuantizedBoundsData*, const hkpStiffChainSchema*, FloatRecord*);
void __cdecl hkpSolverInfo_ProcessEntries_00d89690(const ConstraintSolverInfo*, const SolverStepInfo*, QuantizedBoundsData*, const hkpBallChainSchema*, FloatRecord*);
void __cdecl Object_ProcessEntries_00d8a3a0(const ConstraintSolverInfo*, const SolverStepInfo*, QuantizedBoundsData*, const hkpPoweredChainSchema*, FloatRecord*);
__forceinline void loadFixedRegisters() {}
struct FloatRecord;
__forceinline void storeDelayedResult(FloatRecord*) {}
__forceinline void prefetchVelocityAccumulators(QuantizedBoundsData& a, QuantizedBoundsData& b) {}
__forceinline void reserveRegisters(unsigned int) {}
__forceinline void loadVelocityAccumulators(const QuantizedBoundsData& a, const QuantizedBoundsData& b) { reserveRegisters(0xFFFF0000); }
__forceinline void releaseRegisters(unsigned int) {}
__forceinline void storeVelocityAccumulators(QuantizedBoundsData& a, QuantizedBoundsData& b) { releaseRegisters(0xFFFF0000); }
__forceinline hkReal hkMath_fabs(hkReal r) { return fabsf(r); }
__forceinline hkReal hkMath_sqrt(hkReal r) { return sqrtf(r); }
__forceinline hkReal hkMath_sqrtInverse(hkReal r) { return 1.0f / hkMath_sqrt(r); }
__forceinline hkSimdReal getLinearDv0(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    SolverVector4 a; a.setSub4(mA.m_vLinearVelocity, mB.m_vLinearVelocity);
    SolverVector4 b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    SolverVector4 c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const hkSimdReal vel = b.horizontalAdd3();
    const hkSimdReal dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline hkSimdReal getAngularDv0(const AngularJacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    SolverVector4 a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    SolverVector4 b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.add4(b);
    const hkSimdReal vel = a.horizontalAdd3();
    const hkSimdReal dv = jac.getAngularRhsSr() - vel;
    return dv;
}
__forceinline hkSimdReal getLinearDv0UserTauWithCustomRhs(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping, hkReal customRhs)
{
    SolverVector4 vel4;
    {
        SolverVector4 linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        SolverVector4 angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        SolverVector4 linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        SolverVector4 angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        SolverVector4 a; a.setSub4(linVelA, linVelB);
        SolverVector4 b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        SolverVector4 c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        vel4.setAdd4(b, a);
    }
    SolverVector4 svel4;
    {
        SolverVector4 linVelA = mA.getSumLinearVel();
        SolverVector4 angVelA = mA.getSumAngularVel();
        SolverVector4 linVelB = mB.getSumLinearVel();
        SolverVector4 angVelB = mB.getSumAngularVel();
        SolverVector4 a; a.setSub4(linVelA, linVelB);
        SolverVector4 b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        SolverVector4 c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        svel4.setAdd4(b, a);
    }
    const hkReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    SolverVector4 dv; dv.setAdd4(svel4, vel4);
    const hkReal rhsUpdate = dv.horizontalAdd3();
    return customRhs * tau - rhsUpdate;
}
__forceinline hkSimdReal getLinearDv0UserTau(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
__forceinline hkSimdReal getAngularDv0UserTauWithCustomRhs(const AngularJacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping, hkReal customAngularRhs)
{
    SolverVector4 vel4;
    {
        SolverVector4 angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        SolverVector4 angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        SolverVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        SolverVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        vel4.setAdd4(a, b);
    }
    SolverVector4 svel4;
    {
        SolverVector4 angVelA = mA.getSumAngularVel();
        SolverVector4 angVelB = mB.getSumAngularVel();
        SolverVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        SolverVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        svel4.setAdd4(a, b);
    }
    const hkReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    SolverVector4 dv; dv.setAdd4(svel4, vel4);
    const hkReal rhsUpdate = dv.horizontalAdd3();
    return customAngularRhs * tau - rhsUpdate;
}
__forceinline hkSimdReal getAngularDv0UserTau(const AngularJacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, hkReal tau, hkReal damping)
{
    return getAngularDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getAngularRhs());
}
__forceinline void applyImpulse(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    SolverVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    SolverVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    SolverVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyImpulseX(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    SolverVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    SolverVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    SolverVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    SolverVector4& oA = mA.m_vAngularVelocity;
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    oA.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    _mm_store_ss(&sr.m_fAccumulatedImpulse, s.m_vValue);
}
__forceinline void applyImpulse0X(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    applyImpulseX(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse0(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse1(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse01(hkSimdRealParameter imp0, hkSimdRealParameter imp1, const ConstraintJacobian* jacs, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* srs)
{
    applyImpulse0(imp0, jacs[0], mA, mB, *srs);
    applyImpulse1(imp1, jacs[1], mA, mB, srs[1]);
}
__forceinline void ApplyAngularImpulseToBodies(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    SolverVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulseSwappedMul(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    SolverVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulse0(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    ApplyAngularImpulseToBodies(imp, jac, mA, mB, sr);
}
__forceinline void getDv01(const ConstraintJacobian* jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, SolverVector4& velOut)
{
    velOut(0) = getLinearDv0(jac[0], mA, mB, info);
    velOut(1) = getLinearDv0(jac[1], mA, mB, info);
}
__forceinline void getDv012(const Friction3DSchema* jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, SolverVector4& velOut)
{
    velOut(0) = getLinearDv0(jac->m_kFirstFrictionJacobian, mA, mB, info);
    velOut(1) = getLinearDv0(jac->m_kSecondFrictionJacobian, mA, mB, info);
    velOut(2) = getAngularDv0(jac->m_kAngularVelocity, mA, mB, info);
}
__forceinline void SolveSingleContact(const ConstraintSolverInfo& info, const JacobianPointerSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    {
        hkSimdReal dv = getLinearDv0(schema, mA, mB, info);
        hkSimdReal impulse = dv * schema.getInvJacDiagSr();
        hkSimdReal negPreviousImpulse = hkSimdReal(DAT_010c7160) - hkSimdReal(sr->m_fAccumulatedImpulse);
        hkSimdReal_setMax(negPreviousImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solveSingleLimitContact(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianPointerSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    hkSimdReal dv = getLinearDv0(schema, mA, mB, info);
    {
        hkSimdReal impulse = dv * schema.getInvJacDiagSr();
        hkSimdReal maxImpulse = schema.getUserValueSr();
        hkSimdReal impulseApplied = sr->m_fAccumulatedImpulse;
        hkSimdReal negImpApplied = hkSimdReal(DAT_010c7160) - impulseApplied;
        maxImpulse = maxImpulse - impulseApplied;
        hkSimdReal_setMax(negImpApplied, impulse, impulse);
        hkSimdReal_setMin(maxImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solvePairContact(const ConstraintSolverInfo& info, const JacobianPair& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    SolverVector4 dv4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, dv4);
    const hkReal dv0 = dv4(0);
    const hkReal dv1 = dv4(1);
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    if (imp0 > -sr[0].m_fAccumulatedImpulse)
    {
        if (imp1 > -sr[1].m_fAccumulatedImpulse)
        {
            applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
        }
        else
        {
checkImp0:
            hkSimdReal imp01 = hkSimdReal(dv4(0)) * schema.m_kFirstFrictionJacobian.getInvJacDiagSr();
            hkSimdReal negImp = hkSimdReal(DAT_010c7160) - hkSimdReal(sr[0].m_fAccumulatedImpulse);
            hkSimdReal_setMax(negImp, imp01, imp01);
            applyImpulse0(imp01, schema.m_kFirstFrictionJacobian, mA, mB, *sr);
        }
    }
    else
    {
        hkReal imp10 = schema.m_kSecondFrictionJacobian.getInvJacDiag() * dv1;
        if (imp10 <= -sr[1].m_fAccumulatedImpulse)
        {
            goto checkImp0;
        }
        applyImpulse1(imp10, schema.m_kSecondFrictionJacobian, mA, mB, sr[1]);
    }
}
__forceinline hkSimdReal getLinearDv0B(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    hkQuadReal d = _mm_sub_ps(mA.m_vLinearVelocity.m_vComponents, mB.m_vLinearVelocity.m_vComponents);
    hkQuadReal bq = _mm_mul_ps(mA.m_vAngularVelocity.m_vComponents, jac.m_kAngularVelocity[0].m_vComponents);
    hkQuadReal cq = _mm_mul_ps(mB.m_vAngularVelocity.m_vComponents, jac.m_kAngularVelocity[1].m_vComponents);
    hkQuadReal m = _mm_mul_ps(_mm_load_ps((const float*)&jac.m_kLinearJacobian), d);
    SolverVector4 b; b.m_vComponents = _mm_add_ps(_mm_add_ps(bq, cq), m);
    return jac.getRhsSrE() - b.horizontalAdd3();
}
__forceinline void getDv01B(const ConstraintJacobian* jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, SolverVector4& velOut)
{
    velOut(0) = getLinearDv0(jac[0], mA, mB, info);
    velOut(1) = getLinearDv0B(jac[1], mA, mB, info);
}
__forceinline void solvePairContactB(const ConstraintSolverInfo& info, const JacobianPair& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    SolverVector4 dv4;
    getDv01B(&schema.m_kFirstFrictionJacobian, mA, mB, info, dv4);
    const hkReal dv0 = dv4(0);
    const hkReal dv1 = dv4(1);
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    if (imp0 > -sr[0].m_fAccumulatedImpulse)
    {
        if (imp1 > -sr[1].m_fAccumulatedImpulse)
        {
            applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
        }
        else
        {
checkImp0:
            hkSimdReal imp01 = hkSimdReal(dv4(0)) * schema.m_kFirstFrictionJacobian.getInvJacDiagSr();
            hkSimdReal negImp = hkSimdReal(DAT_010c7160) - hkSimdReal(sr[0].m_fAccumulatedImpulse);
            hkSimdReal_setMax(negImp, imp01, imp01);
            applyImpulse0(imp01, schema.m_kFirstFrictionJacobian, mA, mB, *sr);
        }
    }
    else
    {
        hkReal imp10 = schema.m_kSecondFrictionJacobian.getInvJacDiag() * dv1;
        if (imp10 <= -sr[1].m_fAccumulatedImpulse)
        {
            goto checkImp0;
        }
        applyImpulse1(imp10, schema.m_kSecondFrictionJacobian, mA, mB, sr[1]);
    }
}
__forceinline void solve3dFriction(const ConstraintSolverInfo& info, const Friction3DSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    SolverVector4 vel4;
    getDv012(&schema, mA, mB, info, vel4);
    const hkReal dv0 = vel4(0);
    const hkReal dv1 = vel4(1);
    const hkReal dva = vel4(2);
    hkReal angularImp = schema.m_kAngularVelocity.getInvJacDiag() * dva;
    const hkReal maxSquared = schema.m_maxFrictionImpulse * schema.m_maxFrictionImpulse;
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const hkReal impSquared = imp0 * imp0 + imp1 * imp1 + angularImp * angularImp;
    if (impSquared > maxSquared)
    {
        const hkReal factor = hkMath_sqrtInverse(impSquared) * schema.m_maxFrictionImpulse;
        imp0 *= factor;
        imp1 *= factor;
        angularImp *= factor;
        sr[3].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[3].m_fAccumulatedImpulse = 1.0f;
    }
    angularImp *= schema.m_angularFactor;
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
    applyAngularImpulse0(angularImp, schema.m_kAngularVelocity, mA, mB, sr[2]);
}
__forceinline void solve2dFriction(const ConstraintSolverInfo& info, const TwoAxisFrictionInfo& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    SolverVector4 vel4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, vel4);
    const hkReal dv0 = vel4(0);
    const hkReal dv1 = vel4(1);
    const hkReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const hkReal maxSquared = maxImpulseReg * maxImpulseReg;
    hkReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    hkReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const hkReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const hkReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
}
__forceinline void rollingFields(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, SolverVector4& field0, const SolverVector4& field2)
{
    SolverVector4 impA; impA.setMul4(imp, field2);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    field0.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void rollingSecond(hkSimdRealParameter imp, const SolverVector4& angularA, const SolverVector4& angularB, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const SolverVector4& field0, const SolverVector4& field1, SolverVector4& outputA)
{
    SolverVector4 impA; impA.setMul4(imp, field0);
    SolverVector4 impB; impB.setMul4(imp, field1);
    impA.mul4(angularA);
    impB.mul4(angularB);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    SolverVector4& oA = outputA;
    oA.m_vComponents = _mm_add_ps(oA.m_vComponents, impA.m_vComponents);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}

__forceinline void solve2dRollingFriction(const ConstraintSolverInfo& info, const Friction2DSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const AngularJacobianElement& jac0 = schema.m_kFirstFrictionJacobian;
    const hkReal dv0 = getAngularDv0(jac0, mA, mB, info);
    const AngularJacobianElement& jac1 = schema.m_kSecondFrictionJacobian;
    const hkReal dv1 = getAngularDv0(jac1, mA, mB, info);
    const hkReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const hkReal maxSquared = maxImpulseReg * maxImpulseReg;
    hkReal imp0 = jac0.getInvJacDiag() * dv0;
    hkReal imp1 = jac1.getInvJacDiag() * dv1;
    const hkReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const hkReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    rollingFields(imp0, jac0, mA, mB, sr[0], mA.m_vAngularVelocity, mA.m_vInverseInertiaAndMass);
    applyAngularImpulse0(imp1, jac1, mA, mB, sr[1]);
}
__forceinline void solve1dAngFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitedJacobian& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr)
{
    const hkReal dv0 = getAngularDv0(schema, mA, mB, info);
    hkReal imp0 = schema.getInvJacDiag() * dv0;
    const hkReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const hkReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyAngularImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void lowerApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const SolverVector4& massA, const SolverVector4& massB)
{
    SolverVector4 impA; impA.setMul4(imp, massA);
    SolverVector4 impB; impB.setMul4(imp, massB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void regionApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const SolverVector4& massA, const SolverVector4& massB, const SolverVector4& axisA, const SolverVector4& axisB);
__forceinline void nativeApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr);
__forceinline void solve1dAngLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const AngularLimitJacobian& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkReal dv = getAngularDv0UserTau(schema, mA, mB, info, schema.m_userTau, info.m_fMotorDamping);
    const hkReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        hkReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            rollingFields(impulse, schema, mA, mB, *sr, mA.m_vAngularVelocity, mA.m_vInverseInertiaAndMass);
            return;
        }
    }
    {
        hkReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            regionApplication(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass, schema.m_kAngularVelocity[0], schema.m_kAngularVelocity[1]);
        }
    }
}
__forceinline void regionApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const SolverVector4& massA, const SolverVector4& massB, const SolverVector4& axisA, const SolverVector4& axisB)
{
    SolverVector4 impA; impA.setMul4(imp, massA);
    SolverVector4 impB; impB.setMul4(imp, massB);
    impA.mul4(axisA);
    impB.mul4(axisB);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngularMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorInfoRecord& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const hkReal customAngularRhs = schema.getAngularRhs() + sr[2].m_fAccumulatedImpulse;
    const hkReal dv0 = getAngularDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customAngularRhs);
    hkReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyAngularImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void nativeApplication(hkSimdRealParameter imp, const AngularJacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    SolverVector4 impA; impA = _mm_mul_ps(imp.broadcast(), mA.m_vInverseInertiaAndMass);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngular(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianHolder& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    hkSimdReal dv = getAngularDv0(schema, mA, mB, info);
    hkSimdReal impulse = dv * schema.getInvJacDiagSr();
    nativeApplication(impulse, schema, mA, mB, *sr);
}
__forceinline void applyImpulseG(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, const SolverVector4& massA)
{
    SolverVector4 impA; impA = massA; impA.mul4(imp);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    SolverVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    SolverVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.setMul4(jac.m_kLinearJacobian, impLinA);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dBilateral(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    hkSimdReal vel = getLinearDv0(schema, mA, mB, info);
    hkSimdReal impulse = vel * schema.getInvJacDiagSr();
    applyImpulseG(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass);
}
__forceinline void linearApplication(hkSimdRealParameter imp, const ConstraintJacobian& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr, SolverVector4& linearA)
{
    SolverVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    SolverVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    SolverVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    linearA.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline hkSimdReal fieldProjection(const ConstraintJacobian& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info, const SolverVector4& linearA)
{
    SolverVector4 a; a.setSub4(linearA, mB.m_vLinearVelocity);
    SolverVector4 b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    SolverVector4 c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const hkSimdReal vel = b.horizontalAdd3();
    const hkSimdReal dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline void solve1dBilateralWithImpulseLimit(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    hkSimdReal vel = getLinearDv0(schema, mA, mB, info);
    hkSimdReal impulse = vel * schema.getInvJacDiagSr();
    hkSimdReal impulseApplied = sr->m_fAccumulatedImpulse;
    hkSimdReal maxImpulse = schema.getUserValueSr();
    hkSimdReal minImpulse = -maxImpulse;
    maxImpulse = maxImpulse - impulseApplied;
    minImpulse = minImpulse - impulseApplied;
    hkSimdReal_setMax(minImpulse, impulse, impulse);
    hkSimdReal_setMin(maxImpulse, impulse, impulse);
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void solve1dBilateralUserTau(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearSoftConstraintAtom& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    hkSimdReal dv = getLinearDv0UserTau(schema, mA, mB, info, schema.m_userTau, schema.m_userDamping);
    hkSimdReal impulse = dv * schema.getInvJacDiagSr();
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void solve1dFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitAtom& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkReal dv0 = getLinearDv0(schema, mA, mB, info);
    hkReal imp0 = schema.getInvJacDiag() * dv0;
    const hkReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const hkReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void solve1dLinLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearDistanceLimitAtom& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkReal dv = getLinearDv0(schema, mA, mB, info);
    const hkReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        hkReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
    {
        hkReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
}
__forceinline void solve1dLinearMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorSolverSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const hkReal customRhs = schema.getRHS() + sr[2].m_fAccumulatedImpulse;
    const hkReal dv0 = getLinearDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customRhs);
    hkReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline hkSimdReal getDv2Lin2Ang(const JacobianElement& jac, const QuantizedBoundsData& mA, const QuantizedBoundsData& mB, const ConstraintSolverInfo& info)
{
    SolverVector4 lA; lA.setMul4(mA.m_vLinearVelocity, jac.m_kTranslationalVelocity[0]);
    SolverVector4 lB; lB.setMul4(mB.m_vLinearVelocity, jac.m_kTranslationalVelocity[1]);
    SolverVector4 a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    SolverVector4 b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    SolverVector4 c; c.setSub4(lA, lB);
    a.add4(b);
    a.add4(c);
    const hkSimdReal vel = a.horizontalAdd3();
    const hkSimdReal dv = SubtractScalarFloat(jac.getRhsSr(), vel);
    return dv;
}
__forceinline void applyImpulse2Lin2Ang(hkSimdRealParameter imp, const JacobianElement& jac, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord& sr)
{
    SolverVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    SolverVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    SolverVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    SolverVector4 impLinB; impLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kTranslationalVelocity[0]);
    impLinB.mul4(jac.m_kTranslationalVelocity[1]);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(impLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    hkSimdReal sum; sum=AddScalarFloat(s,imp); s=sum;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solvePulley(const ConstraintSolverInfo& info, const SingleJacobianSchema& schema, QuantizedBoundsData& mA, QuantizedBoundsData& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    hkSimdReal dv = getDv2Lin2Ang(schema, mA, mB, info);
    {
        hkSimdReal impulse = Object_ProcessAndReturnValue_00891060(dv, schema.getInvJacDiagSr());
        applyImpulse2Lin2Ang(impulse, schema, mA, mB, sr[0]);
    }
}
__forceinline int stepJacobian(const ConstraintSolverInfo& info, SolverStepInfo& temp, const SolverSchemaHeader* schemas, QuantizedBoundsData* accums, FloatRecord* srIn)
{
    const SolverSchemaHeader* com = schemas;
    FloatRecord* sr = srIn;
    SolverSchemaType schemaType = getType(com);
    if (schemaType == SCHEMA_TYPE_END)
    {
        return 0;
    }
    QuantizedBoundsData* mA;
    QuantizedBoundsData* mB;
    FloatRecord* delayedResult = 0;
    goto headerNoStoreVelocity;
    while (1)
    {
        schemaType = getType(com);
        switch (schemaType)
        {
        case SCHEMA_TYPE_HEADER:
header:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                prefetchVelocityAccumulators(*sc->getBodyA(accums), *sc->getBodyB(accums));
                storeVelocityAccumulators(*mA, *mB);
headerNoStoreVelocity:
                {
                    const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                    mA = sc->getBodyA(accums);
                    mB = sc->getBodyB(accums);
                    loadVelocityAccumulators(*mA, *mB);
                    com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                }
                break;
            }
        case SCHEMA_TYPE_NOP:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SINGLE_CONTACT:
        case SCHEMA_TYPE_SINGLE_CONTACT2:
case_SINGLE_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                SolveSingleContact(info, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_CONTACT) goto case_SINGLE_CONTACT;
                break;
            }
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2:
case_SINGLE_LIMIT_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                solveSingleLimitContact(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_LIMIT_CONTACT) goto case_SINGLE_LIMIT_CONTACT;
                break;
            }
        case SCHEMA_TYPE_PAIR_CONTACT:
        case SCHEMA_TYPE_PAIR_CONTACT2:
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContact(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (getType(com) != SCHEMA_TYPE_PAIR_CONTACT) continue;
            }
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContactB(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (getType(com) != SCHEMA_TYPE_3D_FRICTION) break;
            }
        case SCHEMA_TYPE_3D_FRICTION:
friction3d:
            {
                const Friction3DSchema* sc = reinterpret_cast<const Friction3DSchema*>(com);
                solve3dFriction(info, *sc, *mA, *mB, sr);
                sr += 4;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_FRICTION:
friction2d:
            {
                const TwoAxisFrictionInfo* sc = reinterpret_cast<const TwoAxisFrictionInfo*>(com);
                solve2dFriction(info, *sc, *mA, *mB, sr);
                sr += 3;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_ROLLING_FRICTION:
            {
                const Friction2DSchema* schema = reinterpret_cast<const Friction2DSchema*>(com);
                solve2dRollingFriction(info, *schema, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(schema + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(schema + 1);
                if (comtype == SCHEMA_TYPE_3D_FRICTION) goto friction3d;
                if (comtype == SCHEMA_TYPE_2D_FRICTION) goto friction2d;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_FRICTION:
case_1D_ANGULAR_FRICTION:
            {
                const FrictionImpulseLimitedJacobian* sc = reinterpret_cast<const FrictionImpulseLimitedJacobian*>(com);
                solve1dAngFriction(info, temp, *sc, *mA, *mB, sr);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_FRICTION) goto case_1D_ANGULAR_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_LIMITS:
case_1D_ANGULAR_LIMITS:
            {
                const AngularLimitJacobian* sc = reinterpret_cast<const AngularLimitJacobian*>(com);
                solve1dAngLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_LIMITS) goto case_1D_ANGULAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_MOTOR:
case_1D_ANGULAR_MOTOR:
            {
                const MotorInfoRecord* sc = reinterpret_cast<const MotorInfoRecord*>(com);
                solve1dAngularMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_MOTOR) goto case_1D_ANGULAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR:
case_1D_ANGULAR:
            {
                const JacobianHolder* sc = reinterpret_cast<const JacobianHolder*>(com);
                solve1dAngular(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR) goto case_1D_ANGULAR;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL:
case_1D_BILATERAL:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateral(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL) goto case_1D_BILATERAL;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT:
case_1D_BILATERAL_WITH_IMPULSE_LIMIT:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateralWithImpulseLimit(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT) goto case_1D_BILATERAL_WITH_IMPULSE_LIMIT;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
case_1D_BILATERAL_USER_TAU:
            {
                const LinearSoftConstraintAtom* sc = reinterpret_cast<const LinearSoftConstraintAtom*>(com);
                solve1dBilateralUserTau(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_USER_TAU) goto case_1D_BILATERAL_USER_TAU;
                break;
            }
        case SCHEMA_TYPE_1D_FRICTION:
case_1D_FRICTION:
            {
                const FrictionImpulseLimitAtom* sc = reinterpret_cast<const FrictionImpulseLimitAtom*>(com);
                solve1dFriction(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_FRICTION) goto case_1D_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_LIMITS:
case_1D_LINEAR_LIMITS:
            {
                const LinearDistanceLimitAtom* sc = reinterpret_cast<const LinearDistanceLimitAtom*>(com);
                solve1dLinLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_LIMITS) goto case_1D_LINEAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_MOTOR:
case_1D_LINEAR_MOTOR:
            {
                const MotorSolverSchema* sc = reinterpret_cast<const MotorSolverSchema*>(com);
                solve1dLinearMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_MOTOR) goto case_1D_LINEAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_PULLEY:
            {
                const SingleJacobianSchema* sc = reinterpret_cast<const SingleJacobianSchema*>(com);
                solvePulley(info, *sc, *mA, *mB, sr, delayedResult);
                sr += 1;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SET_MASS:
            {
                const SetInverseMassSchema* sc = reinterpret_cast<const SetInverseMassSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                mA->m_vInverseInertiaAndMass = sc->m_invMassA;
                mB->m_vInverseInertiaAndMass = sc->m_invMassB;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_ADD_VELOCITY:
            {
                const AddVelocitySchema* sc = reinterpret_cast<const AddVelocitySchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                const int bodyIndex = sc->m_iBodyIndex;
                QuantizedBoundsData* accum = hkSelect(bodyIndex, mA, mB);
                const hkReal f = info.m_kGravity(0) * hkReal(int(temp.m_intStep));
                hkSimdReal fs;
                fs.FUN_005dbf20(f);
                SolverVector4 integratedVel; integratedVel.setMul4(fs, sc->m_fVelocity);
                sc->m_fVelocity.commitIncrement(accum->m_vLinearVelocity);
                accum->m_vLinearVelocity.add4(integratedVel);
                accum->getSumLinearVel().add4(integratedVel);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_SET_CENTER_OF_MASS:
            {
                const hkpJacobianSetComSchema* sc = reinterpret_cast<const hkpJacobianSetComSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                SolverVector4 deltaVelA; deltaVelA.hkVector4_setMul3(sc->m_angularA, mA->m_vAngularVelocity);
                SolverVector4 deltaVelB; deltaVelB.hkVector4_setMul3(sc->m_angularB, mB->m_vAngularVelocity);
                SolverVector4 deltaSumVelA; deltaSumVelA.hkVector4_setMul3(sc->m_angularA, mA->getSumAngularVel());
                SolverVector4 deltaSumVelB; deltaSumVelB.hkVector4_setMul3(sc->m_angularB, mB->getSumAngularVel());
                mA->m_vLinearVelocity.add4(deltaVelA);
                mA->getSumLinearVel().add4(deltaSumVelA);
                mB->m_vLinearVelocity.add4(deltaVelB);
                mB->getSumLinearVel().add4(deltaSumVelB);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_GOTO:
            {
                const SchemaJump* sc = reinterpret_cast<const SchemaJump*>(com);
                com = hkAddByteOffsetConst(com, sc->m_offset);
                break;
            }
        case SCHEMA_TYPE_END:
            storeDelayedResult(delayedResult);
            storeVelocityAccumulators(*mA, *mB);
            return 0;
        case SCHEMA_TYPE_STIFF_SPRING_CHAIN:
            {
                const hkpStiffChainSchema* chain = reinterpret_cast<const hkpStiffChainSchema*>(com);
                Object_ProcessEntries_00d893a0(&info, &temp, accums, chain, sr);
                sr += chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_BALL_SOCKET_CHAIN:
            {
                const hkpBallChainSchema* chain = reinterpret_cast<const hkpBallChainSchema*>(com);
                hkpSolverInfo_ProcessEntries_00d89690(&info, &temp, accums, chain, sr);
                sr += 3 * chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_POWERED_CHAIN:
            {
                const hkpPoweredChainSchema* chain = reinterpret_cast<const hkpPoweredChainSchema*>(com);
                Object_ProcessEntries_00d8a3a0(&info, &temp, accums, chain, sr);
                sr += 6 * chain->m_pBodyA;
                com = hkAddByteOffsetConst(com, chain->m_nextOffset);
                break;
            }
        default:
            fnv_Breakpoint();
            return 0;
        }
    }
}
// @fnv 0x00d8aac0
// src: GUESS 0x00d8aac0 (confidence: low)
extern "C" void __cdecl Object_UpdateFields_00d8aac0(const ConstraintSolverInfo& info, const SolverSchemaHeader* schemas, QuantizedBoundsData* accumulators, FloatRecord* elemTemp)
{
    loadFixedRegisters();
    SolverStepInfo temp;
    temp.m_intStep = 0;
    temp.m_stepFactor = 0.0f;
    stepJacobian(info, temp, schemas, accumulators, elemTemp);
}

using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_load_ss;
using ::_mm_store_ss;
class Scalar {
    union { LocalM128 q; float components[4]; };
public:
    Scalar() {}
    Scalar(const LocalM128& v):q(v) {}
    Scalar(float v):q(_mm_load_ss(&v)) {}
    operator float() const { float v; _mm_store_ss(&v,q); return v; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(q,q,0); }
    __forceinline const LocalM128& get() const { return q; }
};
inline Scalar operator+(const Scalar& a,const Scalar& b) {return _mm_add_ss(a.get(),b.get());}
inline void storeScalar(const Scalar& a,float* p) {_mm_store_ss(p,a.get());}
// SolverVector4 of the probe solver records (ProbeBody, ProbeRow) with the unit's own inline SIMD set (setSub4/setMul4/horizontalAdd3...) over components[4].
class ProbeVector4 {
    union { LocalM128 q; float components[4]; };
public:
    __forceinline LocalM128 get() const {return q;}
    __forceinline void set(LocalM128 v) {q=v;}
    __forceinline void operator=(const ProbeVector4& v) {q=v.q;}
    __forceinline void setSub4(const ProbeVector4& a,const ProbeVector4& b) {q=_mm_sub_ps(a.q,b.q);}
    __forceinline void setAdd4(const ProbeVector4& a,const ProbeVector4& b) {q=_mm_add_ps(a.q,b.q);}
    __forceinline void setMul4(const ProbeVector4& a,const ProbeVector4& b) {q=_mm_mul_ps(a.q,b.q);}
    __forceinline void setMul4(const Scalar& a,const ProbeVector4& b) {q=_mm_mul_ps(a.broadcast(),b.q);}
    __forceinline void add4(const ProbeVector4& b) {q=_mm_add_ps(q,b.q);}
    __forceinline void mul4(const ProbeVector4& b) {q=_mm_mul_ps(q,b.q);}
    __forceinline void mul4(const Scalar& b) {q=_mm_mul_ps(b.broadcast(),q);}
    __forceinline void add3clobberW(const ProbeVector4& b) {q=_mm_add_ps(q,b.q);}
    __forceinline void sub3clobberW(const ProbeVector4& b) {q=_mm_sub_ps(q,b.q);}
    __forceinline void setBroadcast3clobberW(const ProbeVector4& b,int component) {q=_mm_shuffle_ps(b.q,b.q,0xff);}
    __forceinline const float& operator()(int component) const {return q.m128_f32[component];}
    __forceinline Scalar horizontalAdd3() const {
        LocalM128 xy=_mm_add_ss(_mm_shuffle_ps(q,q,0x55),q);
        return _mm_add_ss(_mm_shuffle_ps(q,q,0xaa),xy);
    }
};

struct ProbeBody { ProbeVector4 reserved, linear, angular, mass, baseLinear, baseAngular; };
struct ProbeRow { ProbeVector4 axis, angularA, angularB; };
struct ProbeCoeff { float lower, diagonal, upper; };
struct ProbeSettings { ProbeVector4 a,b,c,d; float scale; };
struct ProbeHeader {
    unsigned short type, count; int flags; float strength, damping;
    ProbeRow* rows() { return (ProbeRow*)(this+1); }
    ProbeCoeff* coefficients() { return (ProbeCoeff*)(rows()+count); }
    float* values() { return (float*)(coefficients()+count)+1; }
    int* offsets() { return (int*)(values()+count); }
};
inline const ProbeSettings* settingsAt(unsigned int p) {return (const ProbeSettings*)p;}
static __forceinline Scalar calculateRhs(const ProbeRow& row, const ProbeBody& a, const ProbeBody& b, const ProbeSettings& settings, float strength, float damping, float rhs) {
    ProbeVector4 relative;
    {
        ProbeVector4 linA; linA.setSub4(a.linear,a.baseLinear);
        ProbeVector4 angA; angA.setSub4(a.angular,a.baseAngular);
        ProbeVector4 linB; linB.setSub4(b.linear,b.baseLinear);
        ProbeVector4 angB; angB.setSub4(b.angular,b.baseAngular);
        ProbeVector4 delta; delta.setSub4(linA,linB);
        ProbeVector4 termA; termA.setMul4(angA,row.angularA);
        ProbeVector4 termB; termB.setMul4(angB,row.angularB);
        delta.mul4(row.axis);
        termA.add4(termB);
        relative.setAdd4(termA,delta);
    }
    ProbeVector4 baseline;
    {
        ProbeVector4 linA = a.baseLinear;
        ProbeVector4 angA = a.baseAngular;
        ProbeVector4 linB = b.baseLinear;
        ProbeVector4 angB = b.baseAngular;
        ProbeVector4 delta; delta.setSub4(linA,linB);
        ProbeVector4 termA; termA.setMul4(angA,row.angularA);
        ProbeVector4 termB; termB.setMul4(angB,row.angularB);
        delta.mul4(row.axis);
        termA.add4(termB);
        baseline.setAdd4(termA,delta);
    }
    baseline.mul4(settings.scale*strength);
    relative.mul4(damping);
    ProbeVector4 total; total.setAdd4(baseline,relative);
    float reduction=total.horizontalAdd3();
    float result=rhs*strength-reduction;
    return result;
}
static __forceinline void applyDirect(float value,const ProbeRow* row,ProbeBody* a,ProbeBody* b,float* output) {
LocalM128 scalar=_mm_load_ss(&value);
LocalM128 factor=_mm_shuffle_ps(scalar,scalar,0);
LocalM128 massA=_mm_mul_ps(a->mass.get(),factor);
LocalM128 massB=_mm_mul_ps(b->mass.get(),factor);
ProbeVector4 linA; linA.set(_mm_shuffle_ps(massA,massA,0xff));
ProbeVector4 linB; linB.set(_mm_shuffle_ps(massB,massB,0xff));
linA.mul4(row->axis);
linB.mul4(row->axis);
a->linear.add3clobberW(linA);
b->linear.sub3clobberW(linB);
LocalM128 angA=_mm_mul_ps(row->angularA.get(),massA);
angA=_mm_add_ps(angA,a->angular.get());
LocalM128 angB=_mm_mul_ps(row->angularB.get(),massB);
a->angular.set(angA);
b->angular.set(_mm_add_ps(angB,b->angular.get()));
LocalM128 oldOutput=_mm_load_ss(output);
_mm_store_ss(output,_mm_add_ss(oldOutput,scalar));
}
// @fnv 0x00d893a0
// src: GUESS 0x00d893a0 (confidence: low)
void __cdecl Object_ProcessEntries_00d893a0(unsigned int settingsAddress, void* unused, unsigned int bodies, ProbeHeader* header, float* output)
{
    ProbeRow* rowData;
    long count;
    int* indices;
    float* values;
    ProbeCoeff* coeff;
    (void)rowData;
    (void)count;
    (void)indices;
    (void)values;
    (void)coeff;
    count = header->count;
    rowData = (ProbeRow*)((unsigned int)header + 16);
    indices = (int*)((char*)header+20+count*64);
    coeff = header->coefficients();
    values = (float*)((char*)header+20+60*count);
    values[-1] = 0.0f;
    for (int i=0; i<count; ++i) {
        ProbeBody* a = (ProbeBody*)(bodies+indices[i]);
        ProbeBody* b = (ProbeBody*)(bodies+indices[i+1]);
        Scalar rhs=calculateRhs(rowData[i],*a,*b,*settingsAt(settingsAddress),header->strength,header->damping,rowData[i].axis(3));
        values[i]=(float(rhs)-values[i-1]*coeff[i].lower)/coeff[i].diagonal;
    }
    float impulse=0.0f;
    for (int i=count-1; i>=0; --i) {
        impulse=values[i]-coeff[i].upper*impulse;
        ProbeBody* __restrict a = (ProbeBody*)(bodies+indices[i]);
        ProbeBody* b = (ProbeBody*)(bodies+indices[i+1]);
        applyDirect(impulse,rowData+i,a,b,output+i);
    }
}

using ::_mm_setzero_ps;





#include <string.h>
// The chain's original implicit SIMD copies used object copies, not SIMD assignments.
__forceinline hkVector4::hkVector4(const hkVector4& vector) { memcpy(&m_vComponents, &vector.m_vComponents, sizeof(m_vComponents)); }
__forceinline void hkVector4::operator=(const LocalM128& v) { m_vComponents = v; }
__forceinline float& hkVector4::operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
__forceinline const float& hkVector4::operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
__forceinline void hkVector4::add3clobberW(const hkVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
__forceinline void hkVector4::sub3clobberW(const hkVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
__forceinline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
__forceinline void hkVector4::mul4(const float& scalar) { mul4(hkSimdReal(scalar)); }
__forceinline void hkVector4::setBroadcast(const hkVector4& v, int i) {
    if (i == 0) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0);
    else if (i == 1) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 85);
    else if (i == 2) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 170);
    else if (i == 3) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 255);
}
__forceinline void hkVector4::setBroadcast3clobberW(const hkVector4& v, int i) { setBroadcast(v, i); }
__forceinline hkSimdReal hkVector4::horizontalAdd3() const {
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 85), m_vComponents);
    return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 170), xySum);
}
__forceinline hkSimdReal hkVector4::getSimdAt(int i) const {
    switch (i) {
    case 0: return m_vComponents;
    case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 85);
    case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 170);
    case 3:
    default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
    }
}

__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }

__forceinline void hkVector4::_setMul3(const hkMatrix3& a, const hkVector4& b) {
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const LocalM128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 85);
    const LocalM128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 170);
    const LocalM128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

template <class T> __forceinline T* hkAddByteOffsetQ(T* base, long offset) { return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset); }

// Local definition retained: include/hkpVelocityAccumulatorOffset.h is not available.
class hkpVelocityAccumulatorOffset {
public:
    __forceinline hkpVelocityAccumulator& getAccumulator(hkpVelocityAccumulator* base) { return *hkAddByteOffsetQ(base, m_offset); }
    int m_offset;
};
// Local definition retained: include/hkp1Lin2AngJacobian.h is not available.
class hkp1Lin2AngJacobian {
public:
    __forceinline const float& getRHS() const { return m_kLinearJacobian(3); }
    hkVector4 m_kLinearJacobian;
    hkVector4 m_kAngularVelocity[2];
};
// Local definition retained: include/hkpConstraintChainMatrixTriple.h is not available.
struct hkpConstraintChainMatrixTriple { hkMatrix3 m_lower, m_kMiddle, m_upper; };
// Local definition retained: include/hkpJacobianBallSocketChainSchema.h is not available.
struct hkpJacobianBallSocketChainSchema {
    __forceinline static hkp1Lin2AngJacobian* getJacobians(hkpJacobianBallSocketChainSchema* s) { return reinterpret_cast<hkp1Lin2AngJacobian*>(reinterpret_cast<char*>(s) + sizeof(hkpJacobianBallSocketChainSchema)); }
    __forceinline hkpConstraintChainMatrixTriple* getMatrixBuffer() { return reinterpret_cast<hkpConstraintChainMatrixTriple*>(hkAddByteOffsetQ(getJacobians(this), m_iConstraintCount * 3 * sizeof(hkp1Lin2AngJacobian))); }
    __forceinline hkVector4* getTempBuffer() { return reinterpret_cast<hkVector4*>(hkAddByteOffsetQ(getMatrixBuffer(), m_iConstraintCount * sizeof(hkpConstraintChainMatrixTriple))); }
    __forceinline hkpVelocityAccumulatorOffset* getAccumulatorOffsetsBase() { return reinterpret_cast<hkpVelocityAccumulatorOffset*>(hkAddByteOffsetQ(getTempBuffer(), (m_iConstraintCount + 1) * sizeof(hkVector4))); }
    short m_schemaType;
    unsigned short m_iConstraintCount;
    int m_iElementCount;
    float m_fTau;
    float m_fMotorDamping;
};
// Local definition retained: include/hkpSolverInfo.h is not available.
struct hkpSolverInfo { int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34,u38,u3c; hkVector4 GetTimeStepFactor; };
// Local definition retained: include/hkpSolverElemTemp.h is not available.
struct hkpSolverElemTemp { union { float m_fAccumulatedImpulse; float m_fSecondUnionFloat; float m_fAccumulatedMotorRhs; }; };

namespace hkVector4UtilQ { __forceinline void reserveRegisters(unsigned int) {} __forceinline void releaseRegisters(unsigned int) {} }
namespace hkSolverQ {
__forceinline void loadVelocityAccumulators(const hkpVelocityAccumulator&, const hkpVelocityAccumulator&) { hkVector4UtilQ::reserveRegisters(0xffff0000); }
__forceinline void storeVelocityAccumulators(hkpVelocityAccumulator&, hkpVelocityAccumulator&) { hkVector4UtilQ::releaseRegisters(0xffff0000); }
__forceinline void popVelocityAccumulators() { hkVector4UtilQ::releaseRegisters(0xffff0000); }
struct SolverStepInfo { int m_unused; };

static __forceinline hkSimdReal getLinearDv0UserTauWithCustomRhs(const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, float tau, float damping, float customRhs)
{
    hkVector4 vel4;
    {
        hkVector4 linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        hkVector4 angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getScratch1());
        hkVector4 linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        hkVector4 angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getScratch1());
        hkVector4 c; c.setSub4(linVelA, linVelB);
        hkVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        vel4.setAdd4(a, c);
    }
    hkVector4 svel4;
    {
        hkVector4 linVelA = mA.getSumLinearVel();
        hkVector4 angVelA = mA.getScratch1();
        hkVector4 linVelB = mB.getSumLinearVel();
        hkVector4 angVelB = mB.getScratch1();
        hkVector4 c; c.setSub4(linVelA, linVelB);
        hkVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        hkVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        svel4.setAdd4(a, c);
    }
    svel4.mul4(info.GetTimeStepFactor(0) * tau);
    vel4.mul4(damping);
    hkVector4 rhsUpdate; rhsUpdate.setAdd4(svel4, vel4);
    float ru = rhsUpdate.horizontalAdd3();
    float dv = customRhs * tau - ru;
    return dv;
}
static __forceinline hkSimdReal getLinearDv0UserTau(const hkp1Lin2AngJacobian& jac, const hkpVelocityAccumulator& mA, const hkpVelocityAccumulator& mB, const hkpSolverInfo& info, float tau, float damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
static __forceinline void applyImpulse(hkSimdRealParameter imp, const hkp1Lin2AngJacobian& jac, hkpVelocityAccumulator& mA, hkpVelocityAccumulator& mB, hkpSolverElemTemp& sr)
{
    hkVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    hkVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    hkVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    hkVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    hkSimdReal s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    hkSimdReal_store(s, &sr.m_fAccumulatedImpulse);
}
}

// @fnv 0x00d89690
// src: GUESS 0x00d89690 (confidence: low)
void __cdecl hkpSolverInfo_ProcessEntries_00d89690(const hkpSolverInfo& info, const hkSolverQ::SolverStepInfo& temp, hkpVelocityAccumulator* accums, hkpJacobianBallSocketChainSchema* chain, hkpSolverElemTemp* sr)
{
    int numConstraints = chain->m_iConstraintCount;
    hkp1Lin2AngJacobian* j = hkpJacobianBallSocketChainSchema::getJacobians(chain);
    hkpVelocityAccumulatorOffset* va = chain->getAccumulatorOffsetsBase();
    hkpConstraintChainMatrixTriple* triple = chain->getMatrixBuffer();
    hkVector4* g = chain->getTempBuffer() + 1;
    g[-1].setZero4();
    {
        for (int gi = 0; gi < numConstraints; j += 3, gi++)
        {
            hkpVelocityAccumulator* __restrict raA = &va[gi].getAccumulator(accums);
            hkpVelocityAccumulator* __restrict raB = &va[gi + 1].getAccumulator(accums);
            hkSolverQ::loadVelocityAccumulators(*raA, *raB);
            hkVector4 dv;
            dv(0) = hkSolverQ::getLinearDv0UserTau(j[0], *raA, *raB, info, chain->m_fTau, chain->m_fMotorDamping);
            dv(1) = hkSolverQ::getLinearDv0UserTau(j[1], *raA, *raB, info, chain->m_fTau, chain->m_fMotorDamping);
            dv(2) = hkSolverQ::getLinearDv0UserTau(j[2], *raA, *raB, info, chain->m_fTau, chain->m_fMotorDamping);
            dv(3) = 0.0f;
            hkSolverQ::popVelocityAccumulators();
            hkVector4 tmp;
            tmp._setMul3(triple[gi].m_lower, g[gi - 1]);
            tmp.setSub4(dv, tmp);
            g[gi]._setMul3(triple[gi].m_kMiddle, tmp);
        }
    }
    {
        hkVector4 imp; imp.setZero4();
        j = hkpJacobianBallSocketChainSchema::getJacobians(chain);
        for (int gi = numConstraints - 1; gi >= 0; gi--)
        {
            hkpVelocityAccumulator* __restrict raA = &va[gi].getAccumulator(accums);
            hkpVelocityAccumulator* __restrict raB = &va[gi + 1].getAccumulator(accums);
            int jIdx = gi * 3;
            hkVector4 tmp;
            tmp._setMul3(triple[gi].m_upper, imp);
            imp.setSub4(g[gi], tmp);
            hkSolverQ::loadVelocityAccumulators(*raA, *raB);
            hkSolverQ::applyImpulse(imp.getSimdAt(0), j[jIdx], *raA, *raB, sr[jIdx]);
            hkSolverQ::applyImpulse(imp.getSimdAt(1), j[jIdx + 1], *raA, *raB, sr[jIdx + 1]);
            hkSolverQ::applyImpulse(imp.getSimdAt(2), j[jIdx + 2], *raA, *raB, sr[jIdx + 2]);
            hkSolverQ::storeVelocityAccumulators(*raA, *raB);
        }
    }
}

using ::_mm_store_ss;
using ::_mm_mul_ps;
using ::_mm_sub_ps;
using ::_mm_add_ps;
using ::_mm_setzero_ps;

template <class TYPE> class PoweredChainCell {
public:
    __forceinline PoweredChainCell() {}
    __forceinline PoweredChainCell(TYPE e) : m_storage(e) {}
    __forceinline void operator=(TYPE e) { m_storage = e; }
    __forceinline TYPE val() const { return m_storage; }
    __forceinline TYPE operator->() const { return m_storage; }
    __forceinline operator TYPE() const { return m_storage; }
private:
    TYPE m_storage;
};


class PoweredChainScalar {
public:
    PoweredChainScalar(const hkQuadReal& x) : m_vValue(x) {}
    PoweredChainScalar(hkReal x) { m_vValue = _mm_load_ss(&x); }
    PoweredChainScalar() {}
    operator hkReal() const { hkReal s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline hkQuadReal broadcast() const { return _mm_shuffle_ps(getQuad(), getQuad(), 0); }
    __forceinline hkQuadReal getQuad() const { return m_vValue; }
private:
    hkQuadReal m_vValue;
};
typedef const PoweredChainScalar& PoweredChainScalarParameter;
inline PoweredChainScalar operator+(PoweredChainScalarParameter r, PoweredChainScalarParameter s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
__forceinline void poweredChainStoreScalar(PoweredChainScalarParameter a, hkReal* p) { _mm_store_ss(p, a.getQuad()); }

class PoweredChainVector4 {
public:
    __forceinline void operator=(const hkQuadReal& v) { m_vComponents = v; }
    __forceinline hkReal& operator()(int i) { return reinterpret_cast<hkReal*>(&m_vComponents)[i]; }
    __forceinline const hkReal& operator()(int i) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[i]; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void add4(const PoweredChainVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add3clobberW(const PoweredChainVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const PoweredChainVector4& a, const PoweredChainVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub3clobberW(const PoweredChainVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const PoweredChainVector4& a, const PoweredChainVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const PoweredChainVector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const PoweredChainVector4& a, const PoweredChainVector4& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(PoweredChainScalarParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(PoweredChainScalarParameter r, const PoweredChainVector4& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline void setBroadcast(const PoweredChainVector4& v, int i) {
        if (i == 0) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0); }
        else if (i == 1) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 85); }
        else if (i == 2) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 170); }
        else if (i == 3) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 255); }
    }
    __forceinline void setBroadcast3clobberW(const PoweredChainVector4& v, int i) { setBroadcast(v, i); }
    __forceinline PoweredChainScalar horizontalAdd3() const {
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 85), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 170), xySum);
    }
    __forceinline PoweredChainScalar getSimdAt(int i) const {
        switch (i) {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 85);
        case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 170);
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
        }
    }
    __forceinline void _setMul3(const hkMatrix3& a, const PoweredChainVector4& b);
    hkQuadReal m_vComponents;
};
__forceinline void PoweredChainVector4::_setMul3(const hkMatrix3& a, const PoweredChainVector4& b) {
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const hkQuadReal r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 85);
    const hkQuadReal r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 170);
    const hkQuadReal r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

template <class T> __forceinline T* poweredChainAddByteOffset(T* base, long offset) { return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset); }

class PoweredChainAccumulator {
public:
    __forceinline const PoweredChainVector4& getScratch0() const { return m_vCenterOfMass; }
    __forceinline const PoweredChainVector4& getScratch1() const { return reinterpret_cast<const PoweredChainVector4&>(m_kCoreFromWorldMatrix.getColumn(0)); }
    __forceinline const PoweredChainVector4& getSumLinearVel() const { return getScratch0(); }
    __forceinline const PoweredChainVector4& getSumAngularVel() const { return getScratch1(); }
    unsigned char m_type;
    unsigned int m_uiDeactivationClass;
    hkReal m_fGravityFactor;
    PoweredChainVector4 m_vLinearVelocity;
    PoweredChainVector4 m_vAngularVelocity;
    PoweredChainVector4 m_vInverseInertiaAndMass;
    PoweredChainVector4 m_vCenterOfMass;
    hkMatrix3 m_kCoreFromWorldMatrix;
};
class PoweredChainAccumulatorOffset {
public:
    __forceinline PoweredChainAccumulator& getAccumulator(PoweredChainAccumulator* base) { return *poweredChainAddByteOffset(base, m_offset); }
    int m_offset;
};
class PoweredChainLinearRow {
public:
    __forceinline const hkReal& getRHS() const { return m_kLinearJacobian(3); }
    PoweredChainVector4 m_kLinearJacobian;
    PoweredChainVector4 m_kAngularVelocity[2];
};
class PoweredChainAngularRow {
public:
    __forceinline void setAngularRhs(hkReal v) { m_kAngularVelocity[1](3) = v; }
    __forceinline hkReal getAngularRhs() const { return m_kAngularVelocity[1](3); }
    PoweredChainVector4 m_kAngularVelocity[2];
};
class PoweredChainMatrix6 {
public:
    hkMatrix3 m_iUnknownValue2[2][2];
};
class PoweredChainVector8 {
public:
    __forceinline void setZero8() { m_vLinearConstraint.setZero4(); m_vAngularConstraint.setZero4(); }
    __forceinline void setSub8(const PoweredChainVector8& a, const PoweredChainVector8& b) { m_vLinearConstraint.setSub4(a.m_vLinearConstraint, b.m_vLinearConstraint); m_vAngularConstraint.setSub4(a.m_vAngularConstraint, b.m_vAngularConstraint); }
    __forceinline void _setMul6(const PoweredChainMatrix6& a, const PoweredChainVector8& b)
    {
        PoweredChainVector4 tmp[2];
        tmp[0]._setMul3(a.m_iUnknownValue2[0][0], b.m_vLinearConstraint);
        m_vLinearConstraint._setMul3(a.m_iUnknownValue2[0][1], b.m_vAngularConstraint);
        tmp[1]._setMul3(a.m_iUnknownValue2[1][0], b.m_vLinearConstraint);
        m_vAngularConstraint._setMul3(a.m_iUnknownValue2[1][1], b.m_vAngularConstraint);
        m_vLinearConstraint.add4(tmp[0]);
        m_vAngularConstraint.add4(tmp[1]);
    }
    PoweredChainVector4 m_vLinearConstraint;
    PoweredChainVector4 m_vAngularConstraint;
};
struct PoweredChainMatrixTriple { PoweredChainMatrix6 m_lower, m_kMiddle, m_upper, m_gTranspose, m_gLower; };
struct PoweredChainMotorAxis { hkReal m_fMinimumForce; hkReal m_fMaximumForce; hkReal m_fVelocity; hkReal m_fTau; hkReal m_fMotorDamping; };
struct PoweredChainMotor {
    __forceinline int GetReferenceTimeStep(int idx) const { return (m_ucReferenceTimeSteps >> (2 * idx)) & 3; }
    unsigned char m_ucReferenceTimeSteps;
    PoweredChainMotorAxis m_kAngularMotors[3];
};
struct PoweredChainSettings { int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24,u28,u2c,u30,u34,u38,u3c; PoweredChainVector4 GetTimeStepFactor; };
struct PoweredChainResult { union { hkReal m_fAccumulatedImpulse; hkReal m_fSecondUnionFloat; hkReal m_fAccumulatedMotorRhs; }; };

namespace PoweredChainVectorUtil { __forceinline void reserveRegisters(unsigned int) {} __forceinline void releaseRegisters(unsigned int) {} }
namespace PoweredChainSolver {
__forceinline void loadVelocityAccumulators(const PoweredChainAccumulator&, const PoweredChainAccumulator&) { PoweredChainVectorUtil::reserveRegisters(0xffff0000); }
__forceinline void storeVelocityAccumulators(PoweredChainAccumulator&, PoweredChainAccumulator&) { PoweredChainVectorUtil::releaseRegisters(0xffff0000); }
__forceinline void popVelocityAccumulators() { PoweredChainVectorUtil::releaseRegisters(0xffff0000); }
struct PoweredChainStepTemp { PoweredChainCell<int> m_unused; PoweredChainCell<hkReal> m_velocityScale; };

static __forceinline PoweredChainScalar getLinearDv0UserTauWithCustomRhs(const PoweredChainLinearRow& jac, const PoweredChainAccumulator& mA, const PoweredChainAccumulator& mB, const PoweredChainSettings& info, hkReal tau, hkReal damping, hkReal customRhs)
{
    PoweredChainVector4 vel4;
    {
        PoweredChainVector4 linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        PoweredChainVector4 angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        PoweredChainVector4 linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        PoweredChainVector4 angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        PoweredChainVector4 c; c.setSub4(linVelA, linVelB);
        PoweredChainVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        PoweredChainVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        vel4.setAdd4(a, c);
    }
    PoweredChainVector4 svel4;
    {
        PoweredChainVector4 linVelA = mA.getSumLinearVel();
        PoweredChainVector4 angVelA = mA.getSumAngularVel();
        PoweredChainVector4 linVelB = mB.getSumLinearVel();
        PoweredChainVector4 angVelB = mB.getSumAngularVel();
        PoweredChainVector4 c; c.setSub4(linVelA, linVelB);
        PoweredChainVector4 a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        PoweredChainVector4 b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        c.mul4(jac.m_kLinearJacobian);
        a.add4(b);
        svel4.setAdd4(a, c);
    }
    svel4.mul4(info.GetTimeStepFactor(0) * tau);
    vel4.mul4(damping);
    PoweredChainVector4 rhsUpdate; rhsUpdate.setAdd4(svel4, vel4);
    hkReal ru = rhsUpdate.horizontalAdd3();
    hkReal dv = customRhs * tau - ru;
    return dv;
}
static __forceinline PoweredChainScalar getLinearDv0UserTau(const PoweredChainLinearRow& jac, const PoweredChainAccumulator& mA, const PoweredChainAccumulator& mB, const PoweredChainSettings& info, hkReal tau, hkReal damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
static __forceinline void applyImpulse(PoweredChainScalarParameter imp, const PoweredChainLinearRow& jac, PoweredChainAccumulator& mA, PoweredChainAccumulator& mB, PoweredChainResult& sr)
{
    PoweredChainVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    PoweredChainVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    PoweredChainVector4 impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    PoweredChainVector4 negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    PoweredChainScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    poweredChainStoreScalar(s, &sr.m_fAccumulatedImpulse);
}
static __forceinline void ApplyAngularImpulseToBodies(PoweredChainScalarParameter imp, const PoweredChainAngularRow& jac, PoweredChainAccumulator& mA, PoweredChainAccumulator& mB, PoweredChainResult& sr)
{
    PoweredChainVector4 impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    PoweredChainVector4 impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    PoweredChainScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    poweredChainStoreScalar(s, &sr.m_fAccumulatedImpulse);
}
}

struct PoweredChainSchema {
    __forceinline static PoweredChainLinearRow* getLinearJacobians(PoweredChainSchema* s) { return reinterpret_cast<PoweredChainLinearRow*>(reinterpret_cast<char*>(s) + sizeof(PoweredChainSchema)); }
    __forceinline static PoweredChainAngularRow* getAngularJacobians(PoweredChainSchema* s, int n) { return reinterpret_cast<PoweredChainAngularRow*>(getLinearJacobians(s) + n * 3); }
    __forceinline PoweredChainMatrixTriple* getMatrixBuffer() { return reinterpret_cast<PoweredChainMatrixTriple*>(poweredChainAddByteOffset(getAngularJacobians(this, m_iConstraintCount), m_iConstraintCount * 3 * sizeof(PoweredChainAngularRow))); }
    __forceinline PoweredChainVector8* getTempBuffer() { return reinterpret_cast<PoweredChainVector8*>(poweredChainAddByteOffset(getMatrixBuffer(), m_iConstraintCount * sizeof(PoweredChainMatrixTriple))); }
    __forceinline PoweredChainVector8* getVelocityBuffer() { return getTempBuffer() + m_iConstraintCount + 1; }
    __forceinline PoweredChainAccumulatorOffset* getAccumulatorOffsetsBase() { return reinterpret_cast<PoweredChainAccumulatorOffset*>(getVelocityBuffer() + m_iConstraintCount); }
    __forceinline PoweredChainMotor* getChildConstraintStatusBase() { return reinterpret_cast<PoweredChainMotor*>(getAccumulatorOffsetsBase() + m_iConstraintCount + 1); }
    int m_schemaType;
    unsigned short m_iConstraintCount;
    short m_unk06;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
};
struct PoweredChainContext {
    __forceinline PoweredChainContext(const PoweredChainSettings& info) : m_pSolverInfo(info) {}
    const PoweredChainSettings& m_pSolverInfo;
    PoweredChainCell<int> m_iConstraintCount;
    PoweredChainCell<hkReal> m_fTau;
    PoweredChainCell<hkReal> m_fMotorDamping;
    PoweredChainCell<PoweredChainLinearRow*> m_jacobians;
    PoweredChainCell<PoweredChainAngularRow*> m_angularJacobians;
    PoweredChainCell<PoweredChainAccumulatorOffset*> m_accumulatorOffsets;
    PoweredChainCell<PoweredChainAccumulator*> m_pVelocityAccumulatorA;
    PoweredChainCell<PoweredChainMatrixTriple*> m_kMatrices;
    PoweredChainCell<PoweredChainMotor*> m_kAngularMotors;
    PoweredChainCell<PoweredChainVector8*> m_tempBuffer;
    PoweredChainCell<PoweredChainVector8*> m_velocities;
};
void __cdecl hkpPoweredChain_ComputeLinkVelocityDeltas(const PoweredChainContext& info, PoweredChainVector8* velocities);
void __cdecl hkAabb_ProcessEntries_00df11a0(const PoweredChainContext& info, PoweredChainVector8* temp);
void __cdecl CopyChannelValue(int link, int axis, const PoweredChainMotor* motors, PoweredChainVector8* velocities);
void __cdecl hkChainInfo_ProcessEntries_00df1430(const PoweredChainContext& info, int& link, int& axis, hkReal& impulse, PoweredChainMotor* motors);
void __cdecl Object_ProcessEntries_00df1260(const PoweredChainContext& info, int& link, int& axis, hkReal& impulse, PoweredChainMotor* motors);
void __cdecl Object_ProcessEntries_00df2040(int link, int count, PoweredChainMotor* motors, PoweredChainMatrixTriple* matrices);
void __cdecl Object_UpdateFields_00df1060(int link, int axis, const PoweredChainContext& info, PoweredChainVector8* velocities);

// @fnv 0x00d8a3a0
// src: GUESS 0x00d8a3a0 (confidence: low)
void __cdecl Object_ProcessEntries_00d8a3a0(const PoweredChainSettings& info, const PoweredChainSolver::PoweredChainStepTemp& temp, PoweredChainAccumulator* accums, PoweredChainSchema* schema, PoweredChainResult* sr)
{
    PoweredChainContext chainInfo(info);
    chainInfo.m_iConstraintCount = schema->m_iConstraintCount;
    chainInfo.m_fTau = schema->m_fTau;
    chainInfo.m_fMotorDamping = schema->m_fMotorDamping;
    chainInfo.m_jacobians = PoweredChainSchema::getLinearJacobians(schema);
    chainInfo.m_angularJacobians = PoweredChainSchema::getAngularJacobians(schema, schema->m_iConstraintCount);
    chainInfo.m_accumulatorOffsets = schema->getAccumulatorOffsetsBase();
    chainInfo.m_pVelocityAccumulatorA = accums;
    chainInfo.m_kMatrices = schema->getMatrixBuffer();
    chainInfo.m_kAngularMotors = schema->getChildConstraintStatusBase();
    chainInfo.m_tempBuffer = schema->getTempBuffer();
    chainInfo.m_velocities = schema->getVelocityBuffer();

    {
        PoweredChainAngularRow* jac = chainInfo.m_angularJacobians;
        for (int i = 0; i < chainInfo.m_iConstraintCount; i++)
        {
            for (int a = 0; a < 3; a++)
            {
                hkReal rhs = jac->getAngularRhs();
                rhs += chainInfo.m_kAngularMotors.val()[i].m_kAngularMotors[a].m_fVelocity * temp.m_velocityScale;
                jac->setAngularRhs(rhs);
                jac++;
            }
        }
    }

    hkpPoweredChain_ComputeLinkVelocityDeltas(chainInfo, chainInfo.m_velocities);

    for (int i = 0; i < chainInfo.m_iConstraintCount; i++)
    {
        for (int a = 0; a < 3; a++)
        {
            if (chainInfo.m_kAngularMotors.val()[i].GetReferenceTimeStep(a) == 2)
            {
                PoweredChainVector8& v = chainInfo.m_velocities.val()[i];
                v.m_vAngularConstraint(a) = 0.0f;
            }
            else if (chainInfo.m_kAngularMotors.val()[i].GetReferenceTimeStep(a) != 0)
            {
                CopyChannelValue(i, a, chainInfo.m_kAngularMotors, chainInfo.m_velocities);
            }
        }
    }

    while (true)
    {
        hkAabb_ProcessEntries_00df11a0(chainInfo, chainInfo.m_tempBuffer);
        int link = -1;
        int axis = -1;
        hkReal impulse = 0.0f;
        hkChainInfo_ProcessEntries_00df1430(chainInfo, link, axis, impulse, chainInfo.m_kAngularMotors);
        if (link >= 0)
        {
            Object_ProcessEntries_00df2040(link, chainInfo.m_iConstraintCount, chainInfo.m_kAngularMotors, chainInfo.m_kMatrices);
            Object_UpdateFields_00df1060(link, axis, chainInfo, chainInfo.m_velocities);
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        hkAabb_ProcessEntries_00df11a0(chainInfo, chainInfo.m_tempBuffer);
        int link = -1;
        int axis = -1;
        hkReal impulse = 0.0f;
        Object_ProcessEntries_00df1260(chainInfo, link, axis, impulse, chainInfo.m_kAngularMotors);
        if (link >= 0)
        {
            Object_ProcessEntries_00df2040(link, chainInfo.m_iConstraintCount, chainInfo.m_kAngularMotors, chainInfo.m_kMatrices);
            CopyChannelValue(link, axis, chainInfo.m_kAngularMotors, chainInfo.m_velocities);
        }
        else
        {
            break;
        }
    }

    {
        PoweredChainVector8* g = chainInfo.m_tempBuffer.val() + 1;
        PoweredChainVector8 imp; imp.setZero8();
        for (int i = chainInfo.m_iConstraintCount - 1; i >= 0; i--)
        {
            int jIdx = i * 3;
            int srIdx = i * 6;
            PoweredChainVector8 tmp;
            tmp._setMul6(chainInfo.m_kMatrices.val()[i].m_upper, imp);
            imp.setSub8(g[i], tmp);
            PoweredChainAccumulator* __restrict raA = &chainInfo.m_accumulatorOffsets.val()[i].getAccumulator(accums);
            PoweredChainAccumulator* __restrict raB = &chainInfo.m_accumulatorOffsets.val()[i + 1].getAccumulator(accums);
            PoweredChainSolver::loadVelocityAccumulators(*raA, *raB);
            PoweredChainSolver::applyImpulse(imp.m_vLinearConstraint.getSimdAt(0), chainInfo.m_jacobians.val()[jIdx], *raA, *raB, sr[srIdx]);
            PoweredChainSolver::applyImpulse(imp.m_vLinearConstraint.getSimdAt(1), chainInfo.m_jacobians.val()[jIdx + 1], *raA, *raB, sr[srIdx + 1]);
            PoweredChainSolver::applyImpulse(imp.m_vLinearConstraint.getSimdAt(2), chainInfo.m_jacobians.val()[jIdx + 2], *raA, *raB, sr[srIdx + 2]);
            PoweredChainSolver::ApplyAngularImpulseToBodies(imp.m_vAngularConstraint.getSimdAt(0), chainInfo.m_angularJacobians.val()[jIdx], *raA, *raB, sr[srIdx + 3]);
            PoweredChainSolver::ApplyAngularImpulseToBodies(imp.m_vAngularConstraint.getSimdAt(1), chainInfo.m_angularJacobians.val()[jIdx + 1], *raA, *raB, sr[srIdx + 4]);
            PoweredChainSolver::ApplyAngularImpulseToBodies(imp.m_vAngularConstraint.getSimdAt(2), chainInfo.m_angularJacobians.val()[jIdx + 2], *raA, *raB, sr[srIdx + 5]);
            PoweredChainSolver::storeVelocityAccumulators(*raA, *raB);
        }
    }
}

namespace ConstraintStepImplementation {

namespace ConstraintStepStorage { typedef ::__m128 LocalM128;
}
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_min_ps;
using ::_mm_max_ps;
using ::_mm_shuffle_ps;
using ::_mm_load_ss;
using ::_mm_store_ss;
extern ConstraintStepStorage::LocalM128 DAT_010c7160;
extern unsigned char DAT_01269204;
typedef float ConstraintStepReal;
typedef ConstraintStepStorage::LocalM128 ConstraintStepQuad;
class ConstraintStepScalar
{
public:
    __forceinline ConstraintStepScalar(const ConstraintStepQuad& x) : m_vValue(x) {}
    __forceinline ConstraintStepScalar(ConstraintStepReal x) { m_vValue = _mm_load_ss(&x); }
    __forceinline ConstraintStepScalar() {}
    __forceinline operator ConstraintStepReal() const
    {
        ConstraintStepReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline ConstraintStepQuad broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const ConstraintStepQuad& getQuad() const { return m_vValue; }
    void FUN_005dbf20(ConstraintStepReal x);
    ConstraintStepQuad m_vValue;
};
typedef const ConstraintStepScalar& ConstraintStepScalarParameter;
__forceinline void constraintStepSetMax(ConstraintStepScalarParameter a, ConstraintStepScalarParameter b, ConstraintStepScalar& result)
{
    result = ConstraintStepScalar(_mm_max_ps(a.getQuad(), b.getQuad()));
}
__forceinline void constraintStepSetMin(ConstraintStepScalarParameter a, ConstraintStepScalarParameter b, ConstraintStepScalar& result)
{
    result = ConstraintStepScalar(_mm_min_ps(a.getQuad(), b.getQuad()));
}
__forceinline void constraintStepStore(ConstraintStepScalarParameter a, float* f)
{
    _mm_store_ss(f, a.getQuad());
}
__forceinline ConstraintStepScalar operator*(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_mul_ss(r.getQuad(), s.getQuad()); }
__forceinline ConstraintStepScalar operator-(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_sub_ss(r.getQuad(), s.getQuad()); }
__forceinline ConstraintStepScalar operator+(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
__forceinline ConstraintStepScalar operator-(ConstraintStepScalarParameter r) { return _mm_sub_ss(DAT_010c7160, r.getQuad()); }
ConstraintStepScalar __cdecl SubtractScalarFloat(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s);
ConstraintStepScalar __cdecl Object_ProcessAndReturnValue_00891060(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s);
__declspec(noinline) ConstraintStepScalar __cdecl AddScalarFloat(ConstraintStepScalarParameter r, ConstraintStepScalarParameter s) { return _mm_add_ss(r.getQuad(),s.getQuad()); }
class ConstraintStepVector
{
public:
    __forceinline void commitIncrement(ConstraintStepVector& dest) const { dest.add4(*this); }
    __forceinline operator ConstraintStepQuad() const { return m_vComponents; }
    __forceinline void operator=(const ConstraintStepQuad& q) { m_vComponents = q; }
    __forceinline void operator=(const ConstraintStepVector& v) { m_vComponents = v.m_vComponents; }
    __forceinline void add4(const ConstraintStepVector& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add3clobberW(const ConstraintStepVector& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const ConstraintStepVector& a, const ConstraintStepVector& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void sub3clobberW(const ConstraintStepVector& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const ConstraintStepVector& a, const ConstraintStepVector& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const ConstraintStepVector& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const ConstraintStepVector& a, const ConstraintStepVector& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(ConstraintStepScalarParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(ConstraintStepScalarParameter r, const ConstraintStepVector& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline ConstraintStepScalar horizontalAdd3() const
    {
        ConstraintStepQuad xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    __forceinline ConstraintStepReal& operator()(int a) { return reinterpret_cast<ConstraintStepReal*>(&m_vComponents)[a]; }
    __forceinline const ConstraintStepReal& operator()(int a) const { return reinterpret_cast<const ConstraintStepReal*>(&m_vComponents)[a]; }
    __forceinline ConstraintStepScalar getSimdAt(int i) const
    {
        switch (i)
        {
        case 0: return m_vComponents;
        case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void setBroadcast(const ConstraintStepVector& v, int i)
    {
        if (i == 0) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void setBroadcast3clobberW(const ConstraintStepVector& v, int i) { setBroadcast(v, i); }
    void hkVector4_setMul3(const hkMatrix3& a, const ConstraintStepVector& b);
    __forceinline void SetRotatedVector(const hkMatrix3& a, const ConstraintStepVector& b) { hkVector4_setMul3(a, b); }
    ConstraintStepQuad m_vComponents;
};
struct ConstraintSolverInfo
{
    float unk00, m_fTau, m_fMotorDamping, m_fPostDampingParameter;
    ConstraintStepVector unk10, unk20;
    ConstraintStepVector m_kGravity;
    ConstraintStepVector m_kTimeStep;
};
struct FloatRecord { float m_fAccumulatedImpulse; };
class ConstraintStepAccumulator
{
public:
    int unk00;
    __forceinline const ConstraintStepVector& getSumLinearVel() const { return m_sumLinearVel; }
    __forceinline ConstraintStepVector& getSumLinearVel() { return m_sumLinearVel; }
    __forceinline const ConstraintStepVector& getSumAngularVel() const { return m_sumAngularVel; }
    ConstraintStepVector m_vLinearVelocity;
    ConstraintStepVector m_vAngularVelocity;
    ConstraintStepVector m_vInverseInertiaAndMass;
    ConstraintStepVector m_sumLinearVel;
    ConstraintStepVector m_sumAngularVel;
    ConstraintStepVector unk60;
    ConstraintStepVector unk70;
};
template <class T> __forceinline T* hkSelect(int i, T* a, T* b)
{
    unsigned long ua = (unsigned long)a;
    unsigned long ub = (unsigned long)b;
    return reinterpret_cast<T*>(ua ^ ((ua ^ ub) & (-i)));
}
struct SolverStepInfo
{
    hkPadSpu<int> m_intStep;
    hkPadSpu<ConstraintStepReal> m_stepFactor;
};
enum SolverSchemaType
{
    SCHEMA_TYPE_END = 0,
    SCHEMA_TYPE_HEADER = 1,
    SCHEMA_TYPE_GOTO = 2,
    SCHEMA_TYPE_NOP = 3,
    SCHEMA_TYPE_1D_BILATERAL = 5,
    SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT = 6,
    SCHEMA_TYPE_1D_BILATERAL_USER_TAU = 7,
    SCHEMA_TYPE_1D_LINEAR_LIMITS = 8,
    SCHEMA_TYPE_1D_FRICTION = 9,
    SCHEMA_TYPE_1D_LINEAR_MOTOR = 10,
    SCHEMA_TYPE_1D_PULLEY = 11,
    SCHEMA_TYPE_1D_ANGULAR = 12,
    SCHEMA_TYPE_1D_ANGULAR_LIMITS = 13,
    SCHEMA_TYPE_1D_ANGULAR_FRICTION = 14,
    SCHEMA_TYPE_1D_ANGULAR_MOTOR = 15,
    SCHEMA_TYPE_SINGLE_CONTACT = 16,
    SCHEMA_TYPE_SINGLE_CONTACT2 = 17,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT = 18,
    SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2 = 19,
    SCHEMA_TYPE_PAIR_CONTACT = 20,
    SCHEMA_TYPE_PAIR_CONTACT2 = 21,
    SCHEMA_TYPE_2D_FRICTION = 22,
    SCHEMA_TYPE_3D_FRICTION = 23,
    SCHEMA_TYPE_2D_ROLLING_FRICTION = 24,
    SCHEMA_TYPE_SET_MASS = 25,
    SCHEMA_TYPE_ADD_VELOCITY = 26,
    SCHEMA_TYPE_SET_CENTER_OF_MASS = 27,
    SCHEMA_TYPE_STIFF_SPRING_CHAIN = 29,
    SCHEMA_TYPE_BALL_SOCKET_CHAIN = 30,
    SCHEMA_TYPE_POWERED_CHAIN = 31
};
using ::hkEnum;
typedef hkEnum<SolverSchemaType, signed char> SchemaEnum;
class SolverSchemaHeader
{
public:
    SchemaEnum m_type;
};
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* base, long offset)
{
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(base) + offset);
}
__forceinline SchemaEnum getType(const SolverSchemaHeader* s) { return *reinterpret_cast<const SchemaEnum*>(hkAddByteOffsetConst(s, 0)); }
__forceinline int getNumSolverElemTemps(const SolverSchemaHeader* s)
{
    const int numSolverElemTemps = DAT_011b9434[(SolverSchemaType)getType(s)];
    return numSolverElemTemps;
}
SchemaEnum __cdecl Object_ComputeValue_00d921c0(const SolverSchemaHeader* s);
// src: GUESS 0x00d921d0 (confidence: low)
inline int __cdecl Hkpsolver_GetIndexedValue_00d921d0(const SolverSchemaHeader* s) { return DAT_011b9434[static_cast<SolverSchemaType>(s->m_type)]; }
class __declspec(align(16)) ConstraintHeaderSchema : public SolverSchemaHeader
{
public:
    __forceinline ConstraintStepAccumulator* getBodyA(ConstraintStepAccumulator* base) const
    {
        return reinterpret_cast<ConstraintStepAccumulator*>(reinterpret_cast<char*>(base) + ((int)m_pBodyA << 7));
    }
    __forceinline ConstraintStepAccumulator* getBodyB(ConstraintStepAccumulator* base) const
    {
        return reinterpret_cast<ConstraintStepAccumulator*>(reinterpret_cast<char*>(base) + ((int)m_pBodyB << 7));
    }
    unsigned char unk01;
    unsigned short m_numTemps;
    unsigned short m_pBodyA;
    unsigned short m_pBodyB;
};
class SchemaJump : public SolverSchemaHeader
{
public:
    int m_offset;
};
class ConstraintJacobian
{
public:
    __forceinline const ConstraintStepReal& getRHS() const { return m_kLinearJacobian(3); }
    __forceinline const ConstraintStepScalar getRhsSr() const { return m_kLinearJacobian.getSimdAt(3); }
    __forceinline ConstraintStepReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline ConstraintStepScalar getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    __forceinline ConstraintStepReal getUserValue() const { return m_kAngularVelocity[1](3); }
    __forceinline ConstraintStepScalar getUserValueSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    ConstraintStepVector m_kLinearJacobian;
    ConstraintStepVector m_kAngularVelocity[2];
};
class AngularJacobianElement
{
public:
    __forceinline ConstraintStepReal getAngularRhs() const { return m_kAngularVelocity[1](3); }
    __forceinline ConstraintStepScalar getAngularRhsSr() const { return m_kAngularVelocity[1].getSimdAt(3); }
    __forceinline ConstraintStepReal getInvJacDiag() const { return m_kAngularVelocity[0](3); }
    __forceinline ConstraintStepScalar getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    ConstraintStepVector m_kAngularVelocity[2];
};
class JacobianElement
{
public:
    __forceinline ConstraintStepScalar getRhsSr() const { return m_kTranslationalVelocity[0].getSimdAt(3); }
    __forceinline ConstraintStepScalar getInvJacDiagSr() const { return m_kAngularVelocity[0].getSimdAt(3); }
    ConstraintStepVector m_kTranslationalVelocity[2];
    ConstraintStepVector m_kAngularVelocity[2];
};
class JacobianPair { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; ConstraintStepReal m_offDiag; };
class Friction3DSchema { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; AngularJacobianElement m_kAngularVelocity; ConstraintStepReal m_offDiag, m_maxFrictionImpulse, m_angularFactor; };
class TwoAxisFrictionInfo { public: ConstraintJacobian m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; ConstraintStepReal m_offDiag, m_maxFrictionImpulse; };
class Friction2DSchema { public: AngularJacobianElement m_kFirstFrictionJacobian, m_kSecondFrictionJacobian; ConstraintStepReal m_maxFrictionImpulse; };
class JacobianPointerSchema : public ConstraintJacobian {};
class JacobianDataHolder : public ConstraintJacobian {};
class LinearSoftConstraintAtom : public ConstraintJacobian { public: ConstraintStepReal m_userTau, m_userDamping; };
class FrictionImpulseLimitAtom : public ConstraintJacobian { public: ConstraintStepReal m_maxFrictionImpulse; };
class LinearDistanceLimitAtom : public ConstraintJacobian { public: ConstraintStepReal m_minLimit, m_maxLimit; };
struct hkpMotorInfo { ConstraintStepReal m_minImpulse, m_usFlags, m_fVelocity, m_fTau, m_fMotorDamping; };
class MotorSolverSchema : public ConstraintJacobian { public: hkpMotorInfo m_pMotor; };
class JacobianHolder : public AngularJacobianElement {};
class FrictionImpulseLimitedJacobian : public AngularJacobianElement { public: ConstraintStepReal m_maxFrictionImpulse; };
class AngularLimitJacobian : public AngularJacobianElement { public: ConstraintStepReal m_minLimit, m_maxLimit, m_userTau; };
class MotorInfoRecord : public AngularJacobianElement { public: hkpMotorInfo m_pMotor; };
class SingleJacobianSchema : public JacobianElement {};
class SetInverseMassSchema { public: ConstraintStepVector m_invMassA, m_invMassB; };
class AddVelocitySchema { public: ConstraintStepVector m_fVelocity; int m_iBodyIndex; };
class hkpJacobianSetComSchema { public: hkMatrix3 m_angularA, m_angularB; };
void __cdecl ValidateHavokKeyCode(unsigned char*);
class hkpStiffChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpBallChainSchema : public SolverSchemaHeader { public: unsigned char unk01; unsigned short m_iConstraintCount; int m_sizeOfNext; };
class hkpPoweredChainSchema : public SolverSchemaHeader { public: unsigned char flags; unsigned short m_numTemps, m_pBodyA, m_pBodyB; int unk08, unk0c, m_nextOffset; };
void __cdecl Object_ProcessEntries_00d893a0(const ConstraintSolverInfo*, const SolverStepInfo*, ConstraintStepAccumulator*, const hkpStiffChainSchema*, FloatRecord*);
void __cdecl hkpSolverInfo_ProcessEntries_00d89690(const ConstraintSolverInfo*, const SolverStepInfo*, ConstraintStepAccumulator*, const hkpBallChainSchema*, FloatRecord*);
void __cdecl Object_ProcessEntries_00d8a3a0(const ConstraintSolverInfo*, const SolverStepInfo*, ConstraintStepAccumulator*, const hkpPoweredChainSchema*, FloatRecord*);
__forceinline void loadFixedRegisters() {}
struct FloatRecord;
__forceinline void storeDelayedResult(FloatRecord*) {}
__forceinline void prefetchVelocityAccumulators(ConstraintStepAccumulator& a, ConstraintStepAccumulator& b) {}
__forceinline void reserveRegisters(unsigned int) {}
__forceinline void loadVelocityAccumulators(const ConstraintStepAccumulator& a, const ConstraintStepAccumulator& b) { reserveRegisters(0xFFFF0000); }
__forceinline void releaseRegisters(unsigned int) {}
__forceinline void storeVelocityAccumulators(ConstraintStepAccumulator& a, ConstraintStepAccumulator& b) { releaseRegisters(0xFFFF0000); }
__forceinline ConstraintStepReal hkMath_fabs(ConstraintStepReal r) { return fabsf(r); }
__forceinline ConstraintStepReal hkMath_sqrt(ConstraintStepReal r) { return sqrtf(r); }
__forceinline ConstraintStepReal hkMath_sqrtInverse(ConstraintStepReal r) { return 1.0f / hkMath_sqrt(r); }
__forceinline ConstraintStepScalar getLinearDv0(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info)
{
    ConstraintStepVector a; a.setSub4(mA.m_vLinearVelocity, mB.m_vLinearVelocity);
    ConstraintStepVector b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const ConstraintStepScalar vel = b.horizontalAdd3();
    const ConstraintStepScalar dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline ConstraintStepScalar getAngularDv0(const AngularJacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB)
{
    ConstraintStepVector a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.add4(b);
    const ConstraintStepScalar vel = a.horizontalAdd3();
    const ConstraintStepScalar dv = jac.getAngularRhsSr() - vel;
    return dv;
}
__forceinline ConstraintStepScalar getLinearDv0UserTauWithCustomRhs(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping, ConstraintStepReal customRhs)
{
    ConstraintStepVector vel4;
    {
        ConstraintStepVector linVelA; linVelA.setSub4(mA.m_vLinearVelocity, mA.getSumLinearVel());
        ConstraintStepVector angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        ConstraintStepVector linVelB; linVelB.setSub4(mB.m_vLinearVelocity, mB.getSumLinearVel());
        ConstraintStepVector angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        ConstraintStepVector a; a.setSub4(linVelA, linVelB);
        ConstraintStepVector b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        vel4.setAdd4(b, a);
    }
    ConstraintStepVector svel4;
    {
        ConstraintStepVector linVelA = mA.getSumLinearVel();
        ConstraintStepVector angVelA = mA.getSumAngularVel();
        ConstraintStepVector linVelB = mB.getSumLinearVel();
        ConstraintStepVector angVelB = mB.getSumAngularVel();
        ConstraintStepVector a; a.setSub4(linVelA, linVelB);
        ConstraintStepVector b; b.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector c; c.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        a.mul4(jac.m_kLinearJacobian);
        b.add4(c);
        svel4.setAdd4(b, a);
    }
    const ConstraintStepReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    ConstraintStepVector dv; dv.setAdd4(svel4, vel4);
    const ConstraintStepReal rhsUpdate = dv.horizontalAdd3();
    return customRhs * tau - rhsUpdate;
}
__forceinline ConstraintStepScalar getLinearDv0UserTau(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping)
{
    return getLinearDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getRHS());
}
__forceinline ConstraintStepScalar getAngularDv0UserTauWithCustomRhs(const AngularJacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping, ConstraintStepReal customAngularRhs)
{
    ConstraintStepVector vel4;
    {
        ConstraintStepVector angVelA; angVelA.setSub4(mA.m_vAngularVelocity, mA.getSumAngularVel());
        ConstraintStepVector angVelB; angVelB.setSub4(mB.m_vAngularVelocity, mB.getSumAngularVel());
        ConstraintStepVector a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        vel4.setAdd4(a, b);
    }
    ConstraintStepVector svel4;
    {
        ConstraintStepVector angVelA = mA.getSumAngularVel();
        ConstraintStepVector angVelB = mB.getSumAngularVel();
        ConstraintStepVector a; a.setMul4(angVelA, jac.m_kAngularVelocity[0]);
        ConstraintStepVector b; b.setMul4(angVelB, jac.m_kAngularVelocity[1]);
        svel4.setAdd4(a, b);
    }
    const ConstraintStepReal ru = info.m_kTimeStep(0) * tau;
    svel4.mul4(ru);
    vel4.mul4(damping);
    ConstraintStepVector dv; dv.setAdd4(svel4, vel4);
    const ConstraintStepReal rhsUpdate = dv.horizontalAdd3();
    return customAngularRhs * tau - rhsUpdate;
}
__forceinline ConstraintStepScalar getAngularDv0UserTau(const AngularJacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepReal tau, ConstraintStepReal damping)
{
    return getAngularDv0UserTauWithCustomRhs(jac, mA, mB, info, tau, damping, jac.getAngularRhs());
}
__forceinline void applyImpulse(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyImpulse0(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse1(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    applyImpulse(imp, jac, mA, mB, sr);
}
__forceinline void applyImpulse01(ConstraintStepScalarParameter imp0, ConstraintStepScalarParameter imp1, const ConstraintJacobian* jacs, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* srs)
{
    applyImpulse0(imp0, jacs[0], mA, mB, *srs);
    applyImpulse1(imp1, jacs[1], mA, mB, srs[1]);
}
__forceinline void ApplyAngularImpulseToBodies(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulseSwappedMul(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyAngularImpulse0(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ApplyAngularImpulseToBodies(imp, jac, mA, mB, sr);
}
__forceinline void getDv01(const ConstraintJacobian* jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepVector& velOut)
{
    velOut(0) = getLinearDv0(jac[0], mA, mB, info);
    velOut(1) = getLinearDv0(jac[1], mA, mB, info);
}
__forceinline void getDv012(const Friction3DSchema* jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info, ConstraintStepVector& velOut)
{
    velOut(0) = getLinearDv0(jac->m_kFirstFrictionJacobian, mA, mB, info);
    velOut(1) = getLinearDv0(jac->m_kSecondFrictionJacobian, mA, mB, info);
    velOut(2) = getAngularDv0(jac->m_kAngularVelocity, mA, mB);
}
__forceinline void SolveSingleContact(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianPointerSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    {
        ConstraintStepScalar dv = getLinearDv0(schema, mA, mB, info);
        ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
        ConstraintStepScalar negPreviousImpulse = ConstraintStepScalar(DAT_010c7160) - ConstraintStepScalar(sr->m_fAccumulatedImpulse);
        constraintStepSetMax(negPreviousImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solveSingleLimitContact(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianPointerSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getLinearDv0(schema, mA, mB, info);
    {
        ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
        ConstraintStepScalar maxImpulse = schema.getUserValueSr();
        ConstraintStepScalar impulseApplied = sr->m_fAccumulatedImpulse;
        ConstraintStepScalar negImpApplied = ConstraintStepScalar(DAT_010c7160) - impulseApplied;
        maxImpulse = maxImpulse - impulseApplied;
        constraintStepSetMax(negImpApplied, impulse, impulse);
        constraintStepSetMin(maxImpulse, impulse, impulse);
        applyImpulse0(impulse, schema, mA, mB, *sr);
    }
}
__forceinline void solvePairContact(const ConstraintSolverInfo& info, const JacobianPair& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    ConstraintStepVector dv4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, dv4);
    const ConstraintStepReal dv0 = dv4(0);
    const ConstraintStepReal dv1 = dv4(1);
    ConstraintStepReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    ConstraintStepReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    if (imp0 > -sr[0].m_fAccumulatedImpulse)
    {
        if (imp1 > -sr[1].m_fAccumulatedImpulse)
        {
            applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
        }
        else
        {
checkImp0:
            ConstraintStepScalar imp01 = ConstraintStepScalar(dv4(0)) * schema.m_kFirstFrictionJacobian.getInvJacDiagSr();
            ConstraintStepScalar negImp = ConstraintStepScalar(DAT_010c7160) - ConstraintStepScalar(sr[0].m_fAccumulatedImpulse);
            constraintStepSetMax(negImp, imp01, imp01);
            applyImpulse0(imp01, schema.m_kFirstFrictionJacobian, mA, mB, *sr);
        }
    }
    else
    {
        ConstraintStepReal imp10 = schema.m_kSecondFrictionJacobian.getInvJacDiag() * dv1;
        if (imp10 <= -sr[1].m_fAccumulatedImpulse)
        {
            goto checkImp0;
        }
        applyImpulse1(imp10, schema.m_kSecondFrictionJacobian, mA, mB, sr[1]);
    }
}
__forceinline void solve3dFriction(const ConstraintSolverInfo& info, const Friction3DSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    ConstraintStepVector vel4;
    getDv012(&schema, mA, mB, info, vel4);
    const ConstraintStepReal dv0 = vel4(0);
    const ConstraintStepReal dv1 = vel4(1);
    const ConstraintStepReal dva = vel4(2);
    ConstraintStepReal angularImp = schema.m_kAngularVelocity.getInvJacDiag() * dva;
    const ConstraintStepReal maxSquared = schema.m_maxFrictionImpulse * schema.m_maxFrictionImpulse;
    ConstraintStepReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    ConstraintStepReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const ConstraintStepReal impSquared = imp0 * imp0 + imp1 * imp1 + angularImp * angularImp;
    if (impSquared > maxSquared)
    {
        const ConstraintStepReal factor = hkMath_sqrtInverse(impSquared) * schema.m_maxFrictionImpulse;
        imp0 *= factor;
        imp1 *= factor;
        angularImp *= factor;
        sr[3].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[3].m_fAccumulatedImpulse = 1.0f;
    }
    angularImp *= schema.m_angularFactor;
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
    applyAngularImpulse0(angularImp, schema.m_kAngularVelocity, mA, mB, sr[2]);
}
__forceinline void solve2dFriction(const ConstraintSolverInfo& info, const TwoAxisFrictionInfo& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    ConstraintStepVector vel4;
    getDv01(&schema.m_kFirstFrictionJacobian, mA, mB, info, vel4);
    const ConstraintStepReal dv0 = vel4(0);
    const ConstraintStepReal dv1 = vel4(1);
    const ConstraintStepReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const ConstraintStepReal maxSquared = maxImpulseReg * maxImpulseReg;
    ConstraintStepReal imp0 = schema.m_kFirstFrictionJacobian.getUserValue() * dv0 + dv1 * schema.m_offDiag;
    ConstraintStepReal imp1 = schema.m_kSecondFrictionJacobian.getUserValue() * dv1 + dv0 * schema.m_offDiag;
    const ConstraintStepReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const ConstraintStepReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse01(imp0, imp1, &schema.m_kFirstFrictionJacobian, mA, mB, sr);
}
__forceinline void rollingFields(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, ConstraintStepQuad& field0, const ConstraintStepVector& field2)
{
    ConstraintStepVector impA; impA.setMul4(imp, field2);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    field0=_mm_add_ps(impA.m_vComponents,field0);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve2dRollingFriction( const Friction2DSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    const AngularJacobianElement& jac0 = schema.m_kFirstFrictionJacobian;
    const AngularJacobianElement& jac1 = schema.m_kSecondFrictionJacobian;
    const ConstraintStepReal dv0 = getAngularDv0(jac0, mA, mB);
    const ConstraintStepReal dv1 = getAngularDv0(jac1, mA, mB);
    const ConstraintStepReal maxImpulseReg = schema.m_maxFrictionImpulse;
    const ConstraintStepReal maxSquared = maxImpulseReg * maxImpulseReg;
    ConstraintStepReal imp0 = jac0.getInvJacDiag() * dv0;
    ConstraintStepReal imp1 = jac1.getInvJacDiag() * dv1;
    const ConstraintStepReal impSquared = imp0 * imp0 + imp1 * imp1;
    if (impSquared > maxSquared)
    {
        const ConstraintStepReal factor = hkMath_sqrt(maxSquared / impSquared);
        imp0 *= factor;
        imp1 *= factor;
        sr[2].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[2].m_fAccumulatedImpulse = 1.0f;
    }
    rollingFields(imp0, jac0, mA, mB, sr[0], mA.m_vAngularVelocity.m_vComponents, mA.m_vInverseInertiaAndMass);
    applyAngularImpulse0(imp1, jac1, mA, mB, sr[1]);
}
__forceinline void solve1dAngFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitedJacobian& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr)
{
    const ConstraintStepReal dv0 = getAngularDv0(schema, mA, mB);
    ConstraintStepReal imp0 = schema.getInvJacDiag() * dv0;
    const ConstraintStepReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const ConstraintStepReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyAngularImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void lowerApplication(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, const ConstraintStepVector& massA, const ConstraintStepVector& massB)
{
    ConstraintStepVector impA; impA.setMul4(imp, massA);
    ConstraintStepVector impB; impB.setMul4(imp, massB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const AngularLimitJacobian& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const ConstraintStepReal dv = getAngularDv0UserTau(schema, mA, mB, info, schema.m_userTau, info.m_fMotorDamping);
    const ConstraintStepReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        ConstraintStepReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            applyAngularImpulse0(impulse, schema, mA, mB, *sr);
            return;
        }
    }
    {
        ConstraintStepReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            lowerApplication(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass);
        }
    }
}
__forceinline void regionApplication(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, const ConstraintStepVector& massA, const ConstraintStepVector& massB, const ConstraintStepVector& axisA, const ConstraintStepVector& axisB)
{
    ConstraintStepVector impA; impA.setMul4(imp, massA);
    ConstraintStepVector impB; impB.setMul4(imp, massB);
    impA.mul4(axisA);
    impB.mul4(axisB);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngularMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorInfoRecord& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal customAngularRhs = schema.getAngularRhs() + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal dv0 = getAngularDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customAngularRhs);
    ConstraintStepReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    regionApplication(impulse, schema, mA, mB, *sr, mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass, schema.m_kAngularVelocity[0], schema.m_kAngularVelocity[1]);
}
__forceinline void nativeApplication(ConstraintStepScalarParameter imp, const AngularJacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA = _mm_mul_ps(imp.broadcast(), mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    impB.mul4(jac.m_kAngularVelocity[1]);
    impA.mul4(jac.m_kAngularVelocity[0]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dAngular(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianHolder& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getAngularDv0(schema, mA, mB);
    ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
    nativeApplication(impulse, schema, mA, mB, *sr);
}

__forceinline ConstraintStepScalar getLinearDv0B(const ConstraintJacobian& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB)
{
    ConstraintStepVector a; a.setSub4(mA.m_vLinearVelocity, mB.m_vLinearVelocity);
    ConstraintStepVector b; b.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector c; c.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    a.mul4(jac.m_kLinearJacobian);
    b.add4(c);
    b.add4(a);
    const ConstraintStepScalar vel = b.horizontalAdd3();
    const ConstraintStepScalar dv = jac.getRhsSr() - vel;
    return dv;
}
__forceinline ConstraintStepScalar addB(ConstraintStepScalarParameter r, ConstraintStepScalarParameter t, const FloatRecord& sr)
{
    return _mm_add_ss(r.getQuad(), t.getQuad());
}
__forceinline void applyImpulseB(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    impA.commitIncrement(mA.m_vAngularVelocity);
    impB.commitIncrement(mB.m_vAngularVelocity);
    s = addB(s, imp, sr);
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void applyImpulseB0(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    applyImpulseB(imp, jac, mA, mB, sr);
}

__forceinline void solve1dBilateral(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar vel = getLinearDv0B(schema, mA, mB);
    ConstraintStepScalar impulse = vel * schema.getInvJacDiagSr();
    applyImpulseB0(impulse, schema, mA, mB, *sr);
}
__forceinline void linearApplication(ConstraintStepScalarParameter imp, const ConstraintJacobian& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr, ConstraintStepVector& linearA)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector negImpLinB; negImpLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kLinearJacobian);
    negImpLinB.mul4(jac.m_kLinearJacobian);
    linearA.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(negImpLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    s = s + imp;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solve1dBilateralWithImpulseLimit(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const JacobianDataHolder& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar vel = getLinearDv0(schema, mA, mB, info);
    ConstraintStepScalar impulse = vel * schema.getInvJacDiagSr();
    ConstraintStepScalar impulseApplied = sr->m_fAccumulatedImpulse;
    ConstraintStepScalar maxImpulse = schema.getUserValueSr();
    ConstraintStepScalar minImpulse = -maxImpulse;
    maxImpulse = maxImpulse - impulseApplied;
    minImpulse = minImpulse - impulseApplied;
    constraintStepSetMax(minImpulse, impulse, impulse);
    constraintStepSetMin(maxImpulse, impulse, impulse);
    linearApplication(impulse, schema, mA, mB, *sr, mA.m_vLinearVelocity);
}
__forceinline void solve1dBilateralUserTau(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearSoftConstraintAtom& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getLinearDv0UserTau(schema, mA, mB, info, schema.m_userTau, schema.m_userDamping);
    ConstraintStepScalar impulse = dv * schema.getInvJacDiagSr();
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline void solve1dFriction(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const FrictionImpulseLimitAtom& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const ConstraintStepReal dv0 = getLinearDv0(schema, mA, mB, info);
    ConstraintStepReal imp0 = schema.getInvJacDiag() * dv0;
    const ConstraintStepReal fimp0 = hkMath_fabs(imp0);
    if (fimp0 > schema.m_maxFrictionImpulse)
    {
        const ConstraintStepReal factor = schema.m_maxFrictionImpulse / fimp0;
        imp0 *= factor;
        sr[1].m_fAccumulatedImpulse = factor;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(imp0, schema, mA, mB, *sr);
}
__forceinline void solve1dLinLimits(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const LinearDistanceLimitAtom& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const ConstraintStepReal dv = getLinearDv0(schema, mA, mB, info);
    const ConstraintStepReal negAppliedImpulse = -sr->m_fAccumulatedImpulse;
    {
        ConstraintStepReal impulse = dv - schema.m_minLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse > negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
    {
        ConstraintStepReal impulse = dv - schema.m_maxLimit;
        impulse = schema.getInvJacDiag() * impulse;
        if (impulse < negAppliedImpulse)
        {
            applyImpulse0(impulse, schema, mA, mB, *sr);
        }
    }
}
__forceinline void solve1dLinearMotor(const ConstraintSolverInfo& info, const SolverStepInfo& temp, const MotorSolverSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    const hkpMotorInfo& motorInfo = schema.m_pMotor;
    sr[2].m_fAccumulatedImpulse = temp.m_stepFactor * motorInfo.m_fVelocity + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal customRhs = schema.getRHS() + sr[2].m_fAccumulatedImpulse;
    const ConstraintStepReal dv0 = getLinearDv0UserTauWithCustomRhs(schema, mA, mB, info, motorInfo.m_fTau, motorInfo.m_fMotorDamping, customRhs);
    ConstraintStepReal impulse = schema.getInvJacDiag() * dv0;
    if (impulse > motorInfo.m_minImpulse)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_minImpulse / impulse;
        impulse = motorInfo.m_minImpulse;
    }
    else if (impulse < motorInfo.m_usFlags)
    {
        sr[1].m_fAccumulatedImpulse = motorInfo.m_usFlags / impulse;
        impulse = motorInfo.m_usFlags;
    }
    else
    {
        sr[1].m_fAccumulatedImpulse = 1.0f;
    }
    applyImpulse0(impulse, schema, mA, mB, *sr);
}
__forceinline ConstraintStepScalar getDv2Lin2Ang(const JacobianElement& jac, const ConstraintStepAccumulator& mA, const ConstraintStepAccumulator& mB, const ConstraintSolverInfo& info)
{
    ConstraintStepVector lA; lA.setMul4(mA.m_vLinearVelocity, jac.m_kTranslationalVelocity[0]);
    ConstraintStepVector lB; lB.setMul4(mB.m_vLinearVelocity, jac.m_kTranslationalVelocity[1]);
    ConstraintStepVector a; a.setMul4(mA.m_vAngularVelocity, jac.m_kAngularVelocity[0]);
    ConstraintStepVector b; b.setMul4(mB.m_vAngularVelocity, jac.m_kAngularVelocity[1]);
    ConstraintStepVector c; c.setSub4(lA, lB);
    a.add4(b);
    a.add4(c);
    const ConstraintStepScalar vel = a.horizontalAdd3();
    const ConstraintStepScalar dv = SubtractScalarFloat(jac.getRhsSr(), vel);
    return dv;
}
__forceinline void applyImpulse2Lin2Ang(ConstraintStepScalarParameter imp, const JacobianElement& jac, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord& sr)
{
    ConstraintStepVector impA; impA.setMul4(imp, mA.m_vInverseInertiaAndMass);
    ConstraintStepVector impB; impB.setMul4(imp, mB.m_vInverseInertiaAndMass);
    ConstraintStepVector impLinA; impLinA.setBroadcast3clobberW(impA, 3);
    ConstraintStepVector impLinB; impLinB.setBroadcast3clobberW(impB, 3);
    impLinA.mul4(jac.m_kTranslationalVelocity[0]);
    impLinB.mul4(jac.m_kTranslationalVelocity[1]);
    mA.m_vLinearVelocity.add3clobberW(impLinA);
    mB.m_vLinearVelocity.sub3clobberW(impLinB);
    impA.mul4(jac.m_kAngularVelocity[0]);
    impB.mul4(jac.m_kAngularVelocity[1]);
    ConstraintStepScalar s = sr.m_fAccumulatedImpulse;
    mA.m_vAngularVelocity.add3clobberW(impA);
    mB.m_vAngularVelocity.add3clobberW(impB);
    ConstraintStepScalar sum; sum=AddScalarFloat(s,imp); s=sum;
    constraintStepStore(s, &sr.m_fAccumulatedImpulse);
}
__forceinline void solvePulley(const ConstraintSolverInfo& info, const SingleJacobianSchema& schema, ConstraintStepAccumulator& mA, ConstraintStepAccumulator& mB, FloatRecord* sr, FloatRecord*& delayedResult)
{
    ConstraintStepScalar dv = getDv2Lin2Ang(schema, mA, mB, info);
    {
        ConstraintStepScalar impulse = Object_ProcessAndReturnValue_00891060(dv, schema.getInvJacDiagSr());
        applyImpulse2Lin2Ang(impulse, schema, mA, mB, sr[0]);
    }
}
__forceinline int stepJacobian(const ConstraintSolverInfo& info, SolverStepInfo& temp, const SolverSchemaHeader* schemas, ConstraintStepAccumulator* accums, FloatRecord* srIn)
{
    const SolverSchemaHeader* com = schemas;
    FloatRecord* sr = srIn;
    SolverSchemaType schemaType = getType(com);
    if (schemaType == SCHEMA_TYPE_END)
    {
        return 0;
    }
    ConstraintStepAccumulator* mA;
    ConstraintStepAccumulator* mB;
    FloatRecord* delayedResult = 0;
    goto headerNoStoreVelocity;
    while (1)
    {
        schemaType = getType(com);
        switch (schemaType)
        {
        case SCHEMA_TYPE_HEADER:
header:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                prefetchVelocityAccumulators(*sc->getBodyA(accums), *sc->getBodyB(accums));
                storeVelocityAccumulators(*mA, *mB);
headerNoStoreVelocity:
                {
                    const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                    mA = sc->getBodyA(accums);
                    mB = sc->getBodyB(accums);

                    com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                }
                break;
            }
        case SCHEMA_TYPE_NOP:
            {
                const ConstraintHeaderSchema* sc = reinterpret_cast<const ConstraintHeaderSchema*>(com);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SINGLE_CONTACT:
        case SCHEMA_TYPE_SINGLE_CONTACT2:
case_SINGLE_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                SolveSingleContact(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_CONTACT) goto case_SINGLE_CONTACT;
                break;
            }
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT:
        case SCHEMA_TYPE_SINGLE_LIMIT_CONTACT2:
case_SINGLE_LIMIT_CONTACT:
            {
                const JacobianPointerSchema* sc = reinterpret_cast<const JacobianPointerSchema*>(com);
                solveSingleLimitContact(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += getNumSolverElemTemps(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_SINGLE_LIMIT_CONTACT) goto case_SINGLE_LIMIT_CONTACT;
                break;
            }
        case SCHEMA_TYPE_PAIR_CONTACT:
        case SCHEMA_TYPE_PAIR_CONTACT2:
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContact(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (getType(com) != SCHEMA_TYPE_PAIR_CONTACT) continue;
            }
            {
                const JacobianPair* sc = reinterpret_cast<const JacobianPair*>(com);
                solvePairContact(info, *sc, *mA, *mB, sr);
                sr += 2;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (getType(com) != SCHEMA_TYPE_3D_FRICTION) break;
            }
        case SCHEMA_TYPE_3D_FRICTION:
friction3d:
            {
                const Friction3DSchema* sc = reinterpret_cast<const Friction3DSchema*>(com);
                solve3dFriction(info, *sc, *mA, *mB, sr);
                sr += 4;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_FRICTION:
friction2d:
            {
                const TwoAxisFrictionInfo* sc = reinterpret_cast<const TwoAxisFrictionInfo*>(com);
                solve2dFriction(info, *sc, *mA, *mB, sr);
                sr += 3;
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_HEADER) goto header;
                break;
            }
        case SCHEMA_TYPE_2D_ROLLING_FRICTION:
            {
                const Friction2DSchema* schema = reinterpret_cast<const Friction2DSchema*>(com);
                solve2dRollingFriction( *schema, *mA, *mB, sr);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(schema + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(schema + 1);
                if (comtype == SCHEMA_TYPE_3D_FRICTION) goto friction3d;
                if (comtype == SCHEMA_TYPE_2D_FRICTION) goto friction2d;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_FRICTION:
case_1D_ANGULAR_FRICTION:
            {
                const FrictionImpulseLimitedJacobian* sc = reinterpret_cast<const FrictionImpulseLimitedJacobian*>(com);
                solve1dAngFriction(info, temp, *sc, *mA, *mB, sr);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_FRICTION) goto case_1D_ANGULAR_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_LIMITS:
case_1D_ANGULAR_LIMITS:
            {
                const AngularLimitJacobian* sc = reinterpret_cast<const AngularLimitJacobian*>(com);
                solve1dAngLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_LIMITS) goto case_1D_ANGULAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR_MOTOR:
case_1D_ANGULAR_MOTOR:
            {
                const MotorInfoRecord* sc = reinterpret_cast<const MotorInfoRecord*>(com);
                solve1dAngularMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR_MOTOR) goto case_1D_ANGULAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_ANGULAR:
case_1D_ANGULAR:
            {
                const JacobianHolder* sc = reinterpret_cast<const JacobianHolder*>(com);
                solve1dAngular(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = getType(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_ANGULAR) goto case_1D_ANGULAR;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL:
case_1D_BILATERAL:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateral(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL) goto case_1D_BILATERAL;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT:
case_1D_BILATERAL_WITH_IMPULSE_LIMIT:
            {
                const JacobianDataHolder* sc = reinterpret_cast<const JacobianDataHolder*>(com);
                solve1dBilateralWithImpulseLimit(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_WITH_IMPULSE_LIMIT) goto case_1D_BILATERAL_WITH_IMPULSE_LIMIT;
                break;
            }
        case SCHEMA_TYPE_1D_BILATERAL_USER_TAU:
case_1D_BILATERAL_USER_TAU:
            {
                const LinearSoftConstraintAtom* sc = reinterpret_cast<const LinearSoftConstraintAtom*>(com);
                solve1dBilateralUserTau(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_BILATERAL_USER_TAU) goto case_1D_BILATERAL_USER_TAU;
                break;
            }
        case SCHEMA_TYPE_1D_FRICTION:
case_1D_FRICTION:
            {
                const FrictionImpulseLimitAtom* sc = reinterpret_cast<const FrictionImpulseLimitAtom*>(com);
                solve1dFriction(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_FRICTION) goto case_1D_FRICTION;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_LIMITS:
case_1D_LINEAR_LIMITS:
            {
                const LinearDistanceLimitAtom* sc = reinterpret_cast<const LinearDistanceLimitAtom*>(com);
                solve1dLinLimits(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_LIMITS) goto case_1D_LINEAR_LIMITS;
                break;
            }
        case SCHEMA_TYPE_1D_LINEAR_MOTOR:
case_1D_LINEAR_MOTOR:
            {
                const MotorSolverSchema* sc = reinterpret_cast<const MotorSolverSchema*>(com);
                solve1dLinearMotor(info, temp, *sc, *mA, *mB, sr, delayedResult);
                sr += Hkpsolver_GetIndexedValue_00d921d0(com);
                const SolverSchemaType comtype = Object_ComputeValue_00d921c0(reinterpret_cast<const SolverSchemaHeader*>(sc + 1));
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                if (comtype == SCHEMA_TYPE_1D_LINEAR_MOTOR) goto case_1D_LINEAR_MOTOR;
                break;
            }
        case SCHEMA_TYPE_1D_PULLEY:
            {
                const SingleJacobianSchema* sc = reinterpret_cast<const SingleJacobianSchema*>(com);
                solvePulley(info, *sc, *mA, *mB, sr, delayedResult);
                sr += 1;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                break;
            }
        case SCHEMA_TYPE_SET_MASS:
            {
                const SetInverseMassSchema* sc = reinterpret_cast<const SetInverseMassSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                mA->m_vInverseInertiaAndMass = sc->m_invMassA;
                mB->m_vInverseInertiaAndMass = sc->m_invMassB;
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_ADD_VELOCITY:
            {
                const AddVelocitySchema* sc = reinterpret_cast<const AddVelocitySchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                const int bodyIndex = sc->m_iBodyIndex;
                ConstraintStepAccumulator* accum = hkSelect(bodyIndex, mA, mB);
                const ConstraintStepReal f = info.m_kGravity(0) * ConstraintStepReal(int(temp.m_intStep));
                ConstraintStepScalar fs;
                fs.FUN_005dbf20(f);
                ConstraintStepVector integratedVel; integratedVel.setMul4(fs, sc->m_fVelocity);
                sc->m_fVelocity.commitIncrement(accum->m_vLinearVelocity);
                accum->m_vLinearVelocity.add4(integratedVel);
                accum->getSumLinearVel().add4(integratedVel);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_SET_CENTER_OF_MASS:
            {
                const hkpJacobianSetComSchema* sc = reinterpret_cast<const hkpJacobianSetComSchema*>(com);
                storeVelocityAccumulators(*mA, *mB);
                ConstraintStepVector deltaVelA; deltaVelA.hkVector4_setMul3(sc->m_angularA, mA->m_vAngularVelocity);
                ConstraintStepVector deltaVelB; deltaVelB.hkVector4_setMul3(sc->m_angularB, mB->m_vAngularVelocity);
                ConstraintStepVector deltaSumVelA; deltaSumVelA.hkVector4_setMul3(sc->m_angularA, mA->getSumAngularVel());
                ConstraintStepVector deltaSumVelB; deltaSumVelB.hkVector4_setMul3(sc->m_angularB, mB->getSumAngularVel());
                mA->m_vLinearVelocity.add4(deltaVelA);
                mA->getSumLinearVel().add4(deltaSumVelA);
                mB->m_vLinearVelocity.add4(deltaVelB);
                mB->getSumLinearVel().add4(deltaSumVelB);
                com = reinterpret_cast<const SolverSchemaHeader*>(sc + 1);
                loadVelocityAccumulators(*mA, *mB);
                break;
            }
        case SCHEMA_TYPE_GOTO:
            {
                const SchemaJump* sc = reinterpret_cast<const SchemaJump*>(com);
                com = hkAddByteOffsetConst(com, sc->m_offset);
                break;
            }
        case SCHEMA_TYPE_END:
            storeDelayedResult(delayedResult);
            storeVelocityAccumulators(*mA, *mB);
            return 0;
        case SCHEMA_TYPE_STIFF_SPRING_CHAIN:
            {
                const hkpStiffChainSchema* chain = reinterpret_cast<const hkpStiffChainSchema*>(com);
                Object_ProcessEntries_00d893a0(&info, &temp, accums, chain, sr);
                sr += chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_BALL_SOCKET_CHAIN:
            {
                const hkpBallChainSchema* chain = reinterpret_cast<const hkpBallChainSchema*>(com);
                hkpSolverInfo_ProcessEntries_00d89690(&info, &temp, accums, chain, sr);
                sr += 3 * chain->m_iConstraintCount;
                com = hkAddByteOffsetConst(com, chain->m_sizeOfNext);
                break;
            }
        case SCHEMA_TYPE_POWERED_CHAIN:
            {
                const hkpPoweredChainSchema* chain = reinterpret_cast<const hkpPoweredChainSchema*>(com);
                Object_ProcessEntries_00d8a3a0(&info, &temp, accums, chain, sr);
                sr += 6 * chain->m_pBodyA;
                com = hkAddByteOffsetConst(com, chain->m_nextOffset);
                break;
            }
        default:
            fnv_Breakpoint();
            return 0;
        }
    }
}
// @fnv 0x00d8fb70
// src: GUESS 0x00d8fb70 (confidence: low)
int __cdecl HkpsolverGsNogs_UpdateState_00d8fb70(const ConstraintSolverInfo& info, int currentSolverStep, int currentSolverMicroStep, const SolverSchemaHeader* schemas, ConstraintStepAccumulator* accumulators, FloatRecord* elemTemp)
{
    if (!DAT_01269204)
    {
        ValidateHavokKeyCode(&DAT_01269204);
        if (!DAT_01269204) return 0;
    }

    SolverStepInfo temp;
    temp.m_intStep = currentSolverStep;
    temp.m_stepFactor = currentSolverMicroStep ? 0.0f : 1.0f;
    stepJacobian(info, temp, schemas, accumulators, elemTemp);
    return 1;
}

}
