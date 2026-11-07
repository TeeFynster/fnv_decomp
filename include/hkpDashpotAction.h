#pragma once

#include "hkpBinaryAction.h"
#include "hkArray.h"
#include "hkStepInfo.h"
#include "hkVector4.h"

typedef float hkReal;

class hkpDashpotAction : public hkpBinaryAction
{
public:
    __declspec(noinline) hkpDashpotAction* InitializeSpringMotorFields(int entityA, int entityB, int userData);
    hkpAction* clone_00d4d9d0(const hkArray<hkpEntity*>& newEntities, const hkArray<hkpEntity*>& removedEntities);
    void applyAction_00d4da60(hkPadSpu<const hkStepInfo*> stepInfo);

    hkVector4 m_kPoint[2];
    hkReal m_fSpringStrength;
    hkReal m_fMotorDamping;
    char pad48[0x8];
    hkVector4 m_fContactImpulse;
};
