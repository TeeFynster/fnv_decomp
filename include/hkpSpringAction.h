#pragma once

#include "hkpBinaryAction.h"
#include "hkVector4.h"
#include "hkBool.h"

typedef float hkReal;

class hkpSpringAction : public hkpBinaryAction
{
public:
    hkVector4 m_kLastForce;
    hkVector4 m_kPositionA;
    hkVector4 m_kPositionB;
    hkReal m_fRestLength;
    hkReal m_fSpringStrength;
    hkReal m_fMotorDamping;
    hkBool m_bSpringEnabled;
    hkBool m_bElastic;
    char pad5E[0x2];
};
