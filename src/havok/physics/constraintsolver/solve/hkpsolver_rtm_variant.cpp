#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/havok/physics/constraintsolver/solve/hkpsolver_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/solve/hkpsolver.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


#include "fnv_asm_helpers.h"
// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern unsigned char DAT_011b9434[128];
int __cdecl Hkpsolver_GetIndexedValue_00d921d0(const signed char* index);
typedef ::__m128 LocalM128;
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

extern "C" void _ReadWriteBarrier();
using ::_mm_load_ss;
using ::_mm_setzero_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_shuffle_ps;

struct SpawnedVec4 {
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

struct SpawnedOwner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SpawnedVec4 m_vec10;
};

struct ZeroVec { LocalM128 q; __forceinline void clear() { q = _mm_setzero_ps(); } };
struct SpawnedElem {
    unsigned char m_type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int unk04;
    float m_fl08;
    unsigned int unk0C;
    LocalM128 m_vec10;
    LocalM128 unk20;
    LocalM128 unk30;
    ZeroVec m_v40;
    ZeroVec m_v50;
    LocalM128 unk60;
    LocalM128 unk70;
};

struct BeginArg { SpawnedElem* p; BeginArg(SpawnedElem* q):p(q){} };
// @fnv 0x00d89ed0
// src: GUESS 0x00d89ed0 (confidence: low)
void __cdecl Hkpsolver_ProcessEntries_00d89ed0(SpawnedOwner* owner, BeginArg begin, SpawnedElem* limit)
{
    SpawnedVec4 scale = owner->m_vec10;
    SpawnedElem* p = begin.p;
    unsigned int end = (unsigned int)limit;
    if (end == 0) end = 0xffffffffu;
    if ((unsigned int)p >= end) return;
    for (;;) {
        switch (p->m_type) {
        case 1:
        case 2:
            p->m_v40.clear();
            p->m_v50.clear();
            ++p;
            break;
        case 0:
        {
            do {
                LocalM128 f = _mm_load_ss(&p->m_fl08);
                p->m_v40.clear();
                p->m_v50.clear();
                _ReadWriteBarrier();
                LocalM128 b = _mm_shuffle_ps(f, f, 0);
                p->m_vec10 = _mm_add_ps(_mm_mul_ps(b, *(const LocalM128*)&scale), p->m_vec10);
                ++p;
            } while (p->m_type == 0 && (unsigned int)p < end);
            break;
        }
        case 3:
            return;
        default:
            __debugbreak();
            break;
        }
        if ((unsigned int)p >= end) return;
    }
}

using ::_mm_load_ss;
using ::_mm_store_ss;
using ::_mm_set_ps1;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_and_ps;
using ::_mm_cmpeq_ps;
using ::_mm_cmplt_ps;
using ::_mm_cmple_ps;
using ::_mm_setzero_ps;
using ::_mm_movemask_ps;
using ::_mm_shuffle_ps;
using ::_mm_set_ss;
using ::_mm_mul_ss;
using ::_mm_cmpeq_ss;
using ::_mm_rsqrt_ss;
using ::_mm_andnot_ps;
struct __declspec(align(16)) Step_PlainQuad {
 float x,y,z,w;
 __forceinline operator LocalM128() const { return *(const LocalM128*)this; }
 __forceinline void operator=(const LocalM128& v) { *(LocalM128*)this = v; }
 __forceinline void operator=(const Step_PlainQuad& v) { *(LocalM128*)this = *(const LocalM128*)&v; }
};
class Step_SimdReal {
public:
    __forceinline Step_SimdReal(const LocalM128& x) { m_vValue=x; }
    __forceinline Step_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline Step_SimdReal() {}
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const LocalM128& getQuad() const { return *(const LocalM128*)&m_vValue; }
private:
    Step_PlainQuad m_vValue;
};
typedef const Step_SimdReal& Step_SimdRealParameter;
class Step_Comparison {
public:
    enum Mask { MASK_XYZ = 7 };
    __forceinline int allAreSet(Mask m) const { return (_mm_movemask_ps(m_uiMask) & m) == m; }
    __forceinline int GetLaneMask() const { return _mm_movemask_ps(m_uiMask); }
    Step_PlainQuad m_uiMask;
};
extern const unsigned int DAT_01017d10[4]; 
extern const unsigned int DAT_010d3da0[4]; 
class Step_Vector4 {
public:
    __forceinline void operator=(const Step_Vector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setAll3(float a) { m_vComponents = _mm_set_ps1(a); }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void add4(const Step_Vector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const Step_Vector4& v0, const Step_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    __forceinline void mul4(const Step_Vector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(Step_SimdRealParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void setMul4(Step_SimdRealParameter r, const Step_Vector4& v1) { m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents); }
    __forceinline void addMul4(Step_SimdRealParameter r, const Step_Vector4& v1) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents)); }
    __forceinline void setAbs4(const Step_Vector4& v) { m_vComponents = _mm_and_ps(v.m_vComponents, *(const LocalM128*)&DAT_01017d10); }
    __forceinline Step_Comparison compareLessThan4(const Step_Vector4& a) const { Step_Comparison m; m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline Step_Comparison compareEqual4(const Step_Vector4& a) const { Step_Comparison m; m.m_uiMask = _mm_cmpeq_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline Step_Comparison compareLessThanEqual4(const Step_Vector4& a) const { Step_Comparison m; m.m_uiMask = _mm_cmple_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline Step_SimdReal getSimdAt(int i) const { switch (i) { case 0: return m_vComponents; case 1: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55); case 2: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa); default: return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff); } }
    __forceinline void subMul4(Step_SimdRealParameter r, const Step_Vector4& v1) { m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents)); }
    __forceinline Step_SimdReal dot3(const Step_Vector4& a) const
    {
        LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline Step_SimdReal lengthInverse3() const
    {
        const LocalM128 half = _mm_set_ss(0.5f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 len2 = this->dot3(*this).getQuad();
        const LocalM128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const LocalM128 approx = _mm_rsqrt_ss(len2);
        const LocalM128 refined = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline Step_SimdReal normalizeWithLength3()
    {
        LocalM128 len2 = this->dot3(*this).getQuad();
        LocalM128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
        return _mm_mul_ss(len2, lenInv);
    }
    __forceinline float& operator()(int i) { return ((float*)&m_vComponents)[i]; }
    __forceinline const float& operator()(int i) const { return ((const float*)&m_vComponents)[i]; }
    __forceinline static const Step_Vector4& getZero();
    Step_PlainQuad m_vComponents;
};
extern Step_Vector4 DAT_01267e30; 
__forceinline const Step_Vector4& Step_Vector4::getZero() { return DAT_01267e30; }
// local form of hkMatrix3: 0x00d89f80 needs inline column access and original scalar aliases; shared form gives 1328 bytes vs exe 1044.
class Step_Matrix3 {
public:
    Step_Vector4 m_kColumn0, m_kColumn1, m_kColumn2;
    __forceinline Step_Vector4& getColumn(int x) { return (&m_kColumn0)[x]; }
    __forceinline const Step_Vector4& getColumn(int x) const { return (&m_kColumn0)[x]; }
};
class Step_Rotation : public Step_Matrix3 {
};
class Step_Transform {
public:
    Step_Rotation m_rotation;
    Step_Vector4 m_vTranslation;
    __forceinline const Step_Vector4& getColumn(int x) const { return m_rotation.getColumn(x); }
    __forceinline static const Step_Transform& GetIdentityTransform();
};
extern Step_Transform DAT_01268370; 
__forceinline const Step_Transform& Step_Transform::GetIdentityTransform() { return DAT_01268370; }
class Step_Bool {
public:
    __forceinline Step_Bool() {}
    __forceinline Step_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    __forceinline Step_Bool& operator=(bool e) { m_cBooleanValue = static_cast<char>(e); return *this; }
private:
    char m_cBooleanValue;
};
class Step_Accumulator {
public:
    enum Type { HK_RIGID_BODY, HK_KEYFRAMED_RIGID_BODY, HK_NO_GRAVITY_RIGID_BODY, HK_END };
    class TypeEnum {
    public:
        __forceinline operator Type() const { return static_cast<Type>(m_kStorage); }
        __forceinline Step_Bool operator==(Type e) const { return m_kStorage == static_cast<unsigned char>(e); }
    private:
        unsigned char m_kStorage;
    };
    TypeEnum m_type;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    int unk0c;
    Step_Vector4 m_vLinearVelocity;
    Step_Vector4 m_vAngularVelocity;
    Step_Vector4 m_vInverseInertiaAndMass;
    Step_Vector4 m_vCenterOfMass;
    Step_Rotation m_kCoreFromWorldMatrix;
    __forceinline Step_Vector4& getScratch0() { return m_vCenterOfMass; }
    __forceinline Step_Vector4& getScratch1() { return m_kCoreFromWorldMatrix.getColumn(0); }
    __forceinline Step_Vector4& getSumLinearVel() { return getScratch0(); }
    __forceinline Step_Vector4& getSumAngularVel() { return getScratch1(); }
};
struct Step_SolverInfo {
    struct FloatAndHalfRecord {
        float m_fFirstFloat;
        float m_fSecondFloat;
        float m_fThirdValue;
        float m_fFourthFloat;
        float m_maxDistSqrd0;
        float m_maxDistSqrd1;
        short m_maxRotSqrd0;
        short m_maxRotSqrd1;
    };
    float m_iCachedVertexCount;
    float m_fTau;
    float m_fMotorDamping;
    float m_fPostDampingParameter;
    Step_Vector4 m_kGravity;
    Step_Vector4 m_kSecondSolverVector;
    Step_Vector4 m_kTimeStep;
    Step_Vector4 GetTimeStepFactor;
    float m_fFirstTrailingParameter;
    float m_fSecondTrailingParameter;
    float m_fThirdTrailingParameter;
    float m_fFourthTrailingParameter;
    float m_fContactRestingVelocity;
    FloatAndHalfRecord m_kDeactivationClassInfo[6];
    float m_fTimeStep;
    float m_fInverseDeltaTime;
    int m_iToiEventCount;
    int m_iMicroStepCount;
    float m_fInverseMicroStepCount;
    float m_fInverseStepCount;
};
__forceinline float Step_min2(float x, float y) { return x < y ? x : y; }
__forceinline Step_Comparison eqRaw(LocalM128 x) { Step_Comparison r; r.m_uiMask=_mm_cmpeq_ps(x,x); return r; }
__forceinline Step_Comparison ltRaw(LocalM128 x,LocalM128 lim) { Step_Comparison r; r.m_uiMask=_mm_cmplt_ps(x,lim); return r; }

template<bool top> static __forceinline void Step_integrateVelocityAccumulator(const Step_SolverInfo& info, Step_Accumulator* accu)
{
    const Step_SolverInfo::FloatAndHalfRecord& di = info.m_kDeactivationClassInfo[accu->m_uiDeactivationClass];
    Step_Vector4 absLinVel; absLinVel.setAbs4(accu->m_vLinearVelocity);
    Step_Vector4 absAngVel; absAngVel.setAbs4(accu->m_vAngularVelocity);
    Step_Vector4 sum;
    sum.setMul4(di.m_fFirstFloat, absLinVel);
    sum.addMul4(di.m_fSecondFloat, absAngVel);
    Step_Vector4 one; one.setAll3(info.m_iCachedVertexCount);
    const Step_Vector4& maxVel = *(const Step_Vector4*)&DAT_010d3da0;
    int mask;
    if(top) {
    LocalM128 angCopy=accu->m_vAngularVelocity.m_vComponents;
mask=(int)((unsigned char)(eqRaw(angCopy).GetLaneMask()) & (unsigned char)(ltRaw(absAngVel.m_vComponents,maxVel.m_vComponents).GetLaneMask()) & (unsigned char)(accu->m_vLinearVelocity.compareEqual4(accu->m_vLinearVelocity).GetLaneMask()) & (short)(ltRaw(absLinVel.m_vComponents,maxVel.m_vComponents).GetLaneMask()));
    } else {
    mask = absLinVel.compareLessThan4(maxVel).GetLaneMask() & absAngVel.compareLessThan4(maxVel).GetLaneMask();
    mask &= accu->m_vLinearVelocity.compareEqual4(accu->m_vLinearVelocity).GetLaneMask() & accu->m_vAngularVelocity.compareEqual4(accu->m_vAngularVelocity).GetLaneMask();
    }
    if ((mask & 7) != 7)
    {
        accu->m_vLinearVelocity = Step_Transform::GetIdentityTransform().getColumn(0);
        accu->m_vAngularVelocity = Step_Transform::GetIdentityTransform().getColumn(0);
    }
    if (sum.compareLessThanEqual4(one).allAreSet(Step_Comparison::MASK_XYZ))
    {
        Step_Vector4 threshold; threshold.setAll3(di.m_fFourthFloat);
        if (sum.compareLessThanEqual4(threshold).allAreSet(Step_Comparison::MASK_XYZ))
        {
            accu->m_vAngularVelocity.setZero4();
            accu->m_vLinearVelocity.setZero4();
            return;
        }
        else if (1)
        {
            accu->m_vAngularVelocity.mul4(di.m_fThirdValue);
            accu->m_vLinearVelocity.mul4(di.m_fThirdValue);
        }
        else
        {
            Step_Vector4 linNorm = accu->m_vLinearVelocity;
            float linLen = linNorm.normalizeWithLength3();
            if (linLen > 1.1920929e-07)
            {
                linLen = Step_min2(0.001f, linLen);
                accu->m_vLinearVelocity.subMul4(linLen, linNorm);
            }
            else
            {
                accu->m_vLinearVelocity.setZero4();
            }
            Step_Vector4 angNorm = accu->m_vAngularVelocity;
            float angLen = angNorm.normalizeWithLength3();
            if (angLen > 1.1920929e-07)
            {
                angLen = Step_min2(0.01f, angLen);
                accu->m_vAngularVelocity.subMul4(angLen, angNorm);
            }
            else
            {
                accu->m_vAngularVelocity.setZero4();
            }
        }
    }
}
static __forceinline void Step_updateSumVelocities(const Step_SolverInfo& info, const Step_Vector4& gravityPerStep, bool lastStep, const Step_Vector4& damping, Step_Accumulator* accu)
{
    Step_SimdReal gravityFactor = accu->m_fGravityFactor;
    Step_Vector4 gravityVel; gravityVel.setMul4(gravityFactor, gravityPerStep);
    Step_Vector4 linVel; linVel.setSub4(accu->m_vLinearVelocity, accu->getSumLinearVel());
    Step_Vector4 angVel; angVel.setSub4(accu->m_vAngularVelocity, accu->getSumAngularVel());
    accu->getSumLinearVel().addMul4(info.m_kTimeStep.getSimdAt(0), linVel);
    accu->getSumAngularVel().addMul4(info.m_kTimeStep.getSimdAt(0), angVel);
    if (!lastStep)
    {
        linVel.add4(accu->getSumLinearVel());
        angVel.add4(accu->getSumAngularVel());
        linVel.add4(gravityVel);
    }
    else
    {
        accu->getSumLinearVel().mul4(damping);
        accu->getSumAngularVel().mul4(damping);
    }
    accu->m_vLinearVelocity = linVel;
    accu->m_vAngularVelocity = angVel;
}
static __forceinline void Step_integrateVelocities(const Step_SolverInfo& info, const Step_Vector4& gravityPerStep, bool lastStep, const Step_Vector4& damping, Step_Accumulator* accu, Step_Accumulator* accuEnd)
{
    if (!accuEnd)
    {
        accuEnd = (Step_Accumulator*)-1;
    }
    while (accu < accuEnd)
    {
        switch (accu->m_type)
        {
        case Step_Accumulator::HK_NO_GRAVITY_RIGID_BODY:
            Step_integrateVelocityAccumulator<true>(info, accu);
        case Step_Accumulator::HK_KEYFRAMED_RIGID_BODY:
            Step_updateSumVelocities(info, Step_Vector4::getZero(), lastStep, damping, accu);
            accu++;
            break;
        case Step_Accumulator::HK_RIGID_BODY:
            do
            {
                Step_integrateVelocityAccumulator<false>(info, accu);
                Step_updateSumVelocities(info, gravityPerStep, lastStep, damping, accu);
                accu++;
            } while (accu->m_type == Step_Accumulator::HK_RIGID_BODY && accu < accuEnd);
            break;
        case Step_Accumulator::HK_END:
            return;
        }
    }
}
static void Step_debugPrintfAccumulators(int mode, const Step_SolverInfo& info, Step_Accumulator* accumulators, Step_Accumulator* accumulatorsEnd)
{
}
struct Step_InArg { Step_Accumulator* value; Step_InArg() {} };
struct Step_OutArg { Step_Bool* value; Step_OutArg() {} };
// @fnv 0x00d89f80
// src: GUESS 0x00d89f80 (confidence: low)
extern "C" __declspec(noinline) int __cdecl Object_ProcessAndReturnValue_00d89f80(
    const Step_SolverInfo& info,
    int currentSolverStep,
    Step_InArg inputArg,
    Step_Accumulator* end,
    Step_OutArg outputArg)
{
 Step_Vector4 gravityPerStep=info.m_kGravity;
 Step_Vector4 damping; damping.setAll3(info.m_fInverseStepCount*info.GetTimeStepFactor(0));
 bool lastStep=false;
 {
  Step_Bool& out=*outputArg.value;
  out=false;
  int n=info.m_iToiEventCount-1;
  if(currentSolverStep>=n) { lastStep=true; out=true; }
 }
 Step_Accumulator* p=inputArg.value;
 Step_integrateVelocities(info,gravityPerStep,lastStep,damping,p,end);
 return 1;
}
