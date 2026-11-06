#pragma once

#include "hkpConstraintAtom.h"
#include "hkRotation.h"

class hkpSetLocalRotationsConstraintAtom : public hkpConstraintAtom
{
public:
    hkpSetLocalRotationsConstraintAtom();
    hkpSetLocalRotationsConstraintAtom(FinishingFlag f);

    char pad2[0xE];
    hkRotation m_kRotationA;
    hkRotation m_kRotationB;
};
