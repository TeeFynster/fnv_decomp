#pragma once

#include "hkpUnaryAction.h"
#include "hkVector4.h"
#include "hkBool.h"

typedef float hkReal;

class hkpMotorAction : public hkpUnaryAction
{
public:
    char pad1C[0x4];
    hkVector4 m_kAxisEndPoints;
    hkReal m_fSpinRate;
    hkReal m_fGain;
    hkBool m_bSlotEnabled;
    char pad39[0x7];
};
