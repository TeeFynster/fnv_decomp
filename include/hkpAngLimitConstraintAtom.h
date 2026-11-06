#pragma once

#include "hkpConstraintAtom.h"

class hkpAngLimitConstraintAtom : public hkpConstraintAtom
{
public:
    hkpAngLimitConstraintAtom(FinishingFlag f);
    hkpAngLimitConstraintAtom() : hkpConstraintAtom(FinishingFlag()) {}

    unsigned char m_bLimitEnabled;
    unsigned char m_ucLimitAxis;
    float m_fMinAngle;
    float m_fMaxAngle;
    float m_fAngularLimitsTauFactor;
};
