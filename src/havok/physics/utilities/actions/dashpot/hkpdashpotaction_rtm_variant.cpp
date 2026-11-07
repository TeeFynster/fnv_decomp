
// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/dashpot/hkpdashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkpDashpotAction.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkStepInfo.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include <xmmintrin.h>

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern unsigned long DAT_0126835c;
extern double DAT_010d09b8;
extern float DAT_01012054;

typedef void* (__stdcall *DashpotApplyTlsGetter)(unsigned long dwTlsIndex);

static inline __m128 dashpotApplyBroadcast(float f) { __m128 t = _mm_load_ss(&f); return _mm_shuffle_ps(t,t,0); }

// @fnv 0x00d4da60
// src: HAVOK_SRC 0x00d4da60
void hkpDashpotAction::applyAction_00d4da60(hkPadSpu<const hkStepInfo*> stepInfo)
{
    DashpotApplyTlsGetter pfnTls = TlsGetValue;

    {
        hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
            pRec->m_commandAndMonitor = "TtDashpot";
            _ReadWriteBarrier();
            unsigned int tick;
            __asm {
                rdtsc
                mov dword ptr[tick], eax
            }
            pRec->m_time0 = tick;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
    }

    float dt = stepInfo->m_fTimeStep * DAT_010d09b8;

    hkpEntity* entityA = m_pEntityA;
    hkpEntity* entityB = m_pEntityB;

    struct DashpotScratch { hkVector4 points[2]; hkVector4 opposite; } scratch;
    scratch.points[1].setTransformedPos_00c7f640(entityA->m_pMotionState.m_kMotionState.m_kMotionTransform, m_kPoint[0]);
    scratch.points[0].setTransformedPos_00c7f640(entityB->m_pMotionState.m_kMotionState.m_kMotionTransform, m_kPoint[1]);

    __m128 relVel = _mm_sub_ps(entityA->m_pMotionState.m_kTranslationalVelocity.m_vComponents, entityB->m_pMotionState.m_kTranslationalVelocity.m_vComponents);
    __m128 dir = _mm_sub_ps(scratch.points[1].m_vComponents, scratch.points[0].m_vComponents);
    hkVector4* impulse = &m_fContactImpulse;
    float factor = m_fSpringStrength * dt;
    __m128 strength = _mm_load_ss(&factor);
    __m128 strengthVec = _mm_shuffle_ps(strength,strength,0);
    factor = dt * m_fMotorDamping;
    _mm_store_ps(&impulse->x, _mm_mul_ps(strengthVec, dir));
    __m128 damping = _mm_load_ss(&factor);
    __m128 dampingVec = _mm_shuffle_ps(damping,damping,0);
    _mm_store_ps(&impulse->x, _mm_add_ps(_mm_mul_ps(dampingVec, relVel), impulse->m_vComponents));
    _ReadWriteBarrier();
    _mm_store_ps(&scratch.opposite.x, _mm_mul_ps(dashpotApplyBroadcast(DAT_01012054), impulse->m_vComponents));
    entityA->activate_00c9c1d0();
    entityA->m_pMotionState.ApplyImpulseAtPoint(scratch.opposite, scratch.points[1]);
    entityB->activate_00c9c1d0();
    entityB->m_pMotionState.ApplyImpulseAtPoint(*impulse, scratch.points[0]);

    {
        hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
            pRec->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            unsigned int tick;
            __asm {
                rdtsc
                mov dword ptr[tick], eax
            }
            pRec->m_time0 = tick;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
    }
}
