#pragma once

#include "hkpConstraintAtom.h"

class hkpAngFrictionConstraintAtom : public hkpConstraintAtom
{
public:
    unsigned char m_bLimitEnabled;
    unsigned char m_ucFirstFrictionAxis;
    unsigned char m_ucNumFrictionAxes;
    char pad5[0x3];
    float m_fMaxFrictionTorque;
};
