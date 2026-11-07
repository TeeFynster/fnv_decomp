
// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/dashpot/hkpdashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkpAction.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"

// The shared hkpBinaryAction lacks the initialization entry at 0x00cf4d80
// (also called by hkpAngularDashpotAction and hkpSpringAction).

// The shared hkpDashpotAction has this 0x60-byte layout but lacks declarations
// for its initialization (0x00d4d980) and clone (0x00d4d9d0) entries.

#include <xmmintrin.h>
#include "../../../../../../include/hkpBinaryAction.h"
#include "../../../../../../include/hkpDashpotAction.h"
extern float DAT_0101e2bc;
extern float DAT_01013ea4;
extern int DAT_010d0994;
// Calls FUN_00cf4d80, sets m_fSpringStrength and m_fMotorDamping from globals, sets the vtable pointer, zeroes both m_kPoint entries and returns this.
// @fnv 0x00d4d980
// src: GUESS 0x00d4d980 (confidence: medium)
hkpDashpotAction* hkpDashpotAction::InitializeSpringMotorFields(int entityA, int entityB, int userData)
{
    FUN_00cf4d80(entityA, entityB, userData);
    m_fSpringStrength = DAT_0101e2bc;
    m_fMotorDamping = DAT_01013ea4;
    *reinterpret_cast<int**>(this) = &DAT_010d0994;
    *reinterpret_cast<__m128*>(&m_kPoint[0]) = _mm_setzero_ps();
    *reinterpret_cast<__m128*>(&m_kPoint[1]) = _mm_setzero_ps();
    return this;
}

// FUN_00d4d9d0 - hkpDashpotAction clone-style factory (Havok)

__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

unsigned long g_tlsIdx = 0;

// src: XBOX_PDB 0x00c85750
__declspec(noinline) void* hkMemoryRouter_getInstance()
{
    unsigned long idx = g_tlsIdx;
    return TlsGetValue(idx);
}

// Clones the dashpot action when exactly two entities are added and none removed, copying points, spring strength, damping, and contact impulse.
// @fnv 0x00d4d9d0
// src: HAVOK_SRC 0x00d4d9d0
hkpAction* hkpDashpotAction::clone_00d4d9d0(const hkArray<hkpEntity*>& newEntities,
                                           const hkArray<hkpEntity*>& removedEntities)
{
    if (newEntities.m_iElementCount != 2)
        return 0;
    if (removedEntities.m_iElementCount != 0)
        return 0;

    hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkpDashpotAction* pDashpot = (hkpDashpotAction*)router->m_heap->blockAlloc(0x60);
    pDashpot->m_usMemSizeAndFlags = 0x60;
    pDashpot = pDashpot->InitializeSpringMotorFields(reinterpret_cast<int>(newEntities.m_data[0]),
                                    reinterpret_cast<int>(newEntities.m_data[1]), m_ulUserData);

    *(__m128*)&pDashpot->m_kPoint[0] = *(__m128*)&m_kPoint[0];
    *(__m128*)&pDashpot->m_kPoint[1] = *(__m128*)&m_kPoint[1];
    pDashpot->m_fSpringStrength = m_fSpringStrength;
    pDashpot->m_fMotorDamping = m_fMotorDamping;
    *(__m128*)&pDashpot->m_fContactImpulse = *(__m128*)&m_fContactImpulse;
    return pDashpot;
}
