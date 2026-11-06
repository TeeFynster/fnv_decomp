#pragma once

#include "hkpBinaryAction.h"
#include "hkQuaternion.h"

typedef float hkReal;

class hkpAngularDashpotAction : public hkpBinaryAction
{
public:
    hkQuaternion m_rotation;
    hkReal m_fSpringStrength;
    hkReal m_fMotorDamping;
    char pad38[0x8];
};
