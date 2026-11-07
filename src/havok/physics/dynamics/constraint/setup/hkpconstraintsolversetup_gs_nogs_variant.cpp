
// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkpWorld.h"
#include "../../../../../../include/hkpVelocityAccumulator.h"

// The copied declarations for the parent unit's 0x00d88670 are unused in this variant.

void __cdecl hkRigidMotionUtilApplyAccumulators(void* a0, void* a1, hkpVelocityAccumulator* acc, hkpMotion** sub, int a4, int a5);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(void* world78, hkpEntity** ent, int count);

// @fnv 0x00d88580
// src: COMMUNITY 0x00d88580
void __cdecl hkpConstraintSolverSetup_oneStepIntegrate(void* a0, void* a1, int offset, hkpEntity** entities, int count)
{
    for (int i = 0; i < count; ++i)
    {
        hkpEntity* entity = entities[i];
        hkpMotion* sub = &entity->m_pMotionState;
        const hkpVelocityAccumulator* source = (hkpVelocityAccumulator*)((char*)entity->m_uiFilterInfo + offset);
        hkpVelocityAccumulator acc;
        acc.m_type = source->m_type;
        acc.m_uiDeactivationClass = source->m_uiDeactivationClass;
        acc.m_fGravityFactor = source->m_fGravityFactor;
        acc.m_vLinearVelocity = source->m_vLinearVelocity;
        acc.m_vAngularVelocity = source->m_vAngularVelocity;
        acc.m_vInverseInertiaAndMass = source->m_vInverseInertiaAndMass;
        acc.m_vCenterOfMass = source->m_vCenterOfMass;
        acc.m_scratch1 = source->m_scratch1;
        acc.m_scratch2 = source->m_scratch2;
        acc.m_scratch3 = source->m_scratch3;
        acc.m_vCenterOfMass = acc.m_vLinearVelocity;
        acc.m_scratch1 = acc.m_vAngularVelocity;
        unsigned char saved = sub->m_ucDeactivationIntegrateCounter;
        sub->m_ucDeactivationIntegrateCounter = 0xff;
        hkRigidMotionUtilApplyAccumulators(a0, a1, &acc, &sub, 1, 0);
        hkpEntityAabbUtil_entityBatchRecalcAabb(((hkpWorld*)entity->m_pOwningWorld)->m_pCollisionInput, &entity, 1);
        sub->m_ucDeactivationIntegrateCounter = saved;
    }
}
