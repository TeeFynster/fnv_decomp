// src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkpAngularDashpotAction.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkStepInfo.h"

namespace AngularDashpotApplyD4DCB0 {

// Exe 0x00d4dcb0 applyAction: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    } lanes;
} __m128, LocalM128;
typedef LocalM128 DashpotQuadD4DCB0;

extern "C" DashpotQuadD4DCB0 _mm_xor_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);
extern "C" DashpotQuadD4DCB0 _mm_load_ss(const float* x);
extern "C" DashpotQuadD4DCB0 _mm_shuffle_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b, int n);
static __forceinline DashpotQuadD4DCB0 splat(const float& x)
{
    DashpotQuadD4DCB0 t = AngularDashpotApplyD4DCB0::_mm_load_ss(&x);
    return AngularDashpotApplyD4DCB0::_mm_shuffle_ps(t, t, 0);
}
extern "C" DashpotQuadD4DCB0 _mm_setzero_ps();
extern "C" DashpotQuadD4DCB0 _mm_mul_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);
extern "C" DashpotQuadD4DCB0 _mm_add_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);
extern "C" DashpotQuadD4DCB0 _mm_sub_ps(DashpotQuadD4DCB0 a, DashpotQuadD4DCB0 b);

extern "C" double DAT_010179e0;
extern const float DAT_01017d00 = 0.001f;

static const DashpotQuadD4DCB0 DashpotNegXY = {{-0.0f, -0.0f, -0.0f, 0.0f}};
static const DashpotQuadD4DCB0 DashpotNegAll = {{-0.0f, -0.0f, -0.0f, -0.0f}};

// hkQuaternion fallback: product at 0x00c66320 needs noalias; the shared declaration changes applyAction from 323 to 326 bytes.
struct DashpotQuaternionMath
{
    DashpotQuadD4DCB0 m_vec;
    __declspec(noalias) void setMul(const DashpotQuadD4DCB0* a, const DashpotQuadD4DCB0* b);
    float FUN_00c74c20();
};

class AngularDashpotApplyAction : public hkpAngularDashpotAction
{
  public:
    void applyAction(const hkStepInfo& input);
};

// @fnv 0x00d4dcb0
void AngularDashpotApplyAction::applyAction(const hkStepInfo& input)
{
    float w = input.m_fTimeStep * DAT_010179e0;
    hkpEntity* aEnt = m_pEntityA;
    hkpEntity* bEnt = m_pEntityB;
    struct AngularDashpotVectors
    {
        DashpotQuaternionMath qprod;
        DashpotQuadD4DCB0 tmp;
    } v;
    DashpotQuaternionMath* __restrict quat = &v.qprod;
    quat->setMul((const DashpotQuadD4DCB0*)&bEnt->m_pMotionState.m_kMotionState.m_kSweptTransform.m_qRotation1, (DashpotQuadD4DCB0*)&m_rotation);

    v.tmp = AngularDashpotApplyD4DCB0::_mm_xor_ps(v.qprod.m_vec, DashpotNegXY);
    quat->setMul((const DashpotQuadD4DCB0*)&aEnt->m_pMotionState.m_kMotionState.m_kSweptTransform.m_qRotation1, &v.tmp);
    v.tmp = AngularDashpotApplyD4DCB0::_mm_sub_ps(reinterpret_cast<const DashpotQuadD4DCB0&>(aEnt->m_pMotionState.m_kAngularVelocity), reinterpret_cast<const DashpotQuadD4DCB0&>(bEnt->m_pMotionState.m_kAngularVelocity));

    float t = quat->FUN_00c74c20();

    DashpotQuadD4DCB0 corr = AngularDashpotApplyD4DCB0::_mm_setzero_ps();
    if (t > DAT_01017d00)
        corr = AngularDashpotApplyD4DCB0::_mm_mul_ps(splat(t), quat->m_vec);

    DashpotQuadD4DCB0 strength, damping;
    {
        float ws0 = w * m_fSpringStrength;
        strength = AngularDashpotApplyD4DCB0::_mm_load_ss(&ws0);
    }
    {
        float ws1 = w * m_fMotorDamping;
        damping = AngularDashpotApplyD4DCB0::_mm_load_ss(&ws1);
    }
    union AngularDashpotImpulse
    {
        DashpotQuadD4DCB0 v;
    };
    AngularDashpotImpulse impulse;
    DashpotQuadD4DCB0& sum = impulse.v;
    sum = AngularDashpotApplyD4DCB0::_mm_add_ps(AngularDashpotApplyD4DCB0::_mm_mul_ps(AngularDashpotApplyD4DCB0::_mm_shuffle_ps(damping, damping, 0), v.tmp),
                     AngularDashpotApplyD4DCB0::_mm_mul_ps(AngularDashpotApplyD4DCB0::_mm_shuffle_ps(strength, strength, 0), corr));

    bEnt->activate_00c9c1d0();
    bEnt->m_pMotionState.ApplyAngularImpulseToBodies(reinterpret_cast<const hkVector4&>(sum));
    sum = AngularDashpotApplyD4DCB0::_mm_xor_ps(sum, DashpotNegAll);
    aEnt->activate_00c9c1d0();
    aEnt->m_pMotionState.ApplyAngularImpulseToBodies(reinterpret_cast<const hkVector4&>(sum));
}

}
