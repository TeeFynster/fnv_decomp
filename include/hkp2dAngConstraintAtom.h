#pragma once

#include "hkpConstraintAtom.h"

class hkp2dAngConstraintAtom : public hkpConstraintAtom
{
public:
    hkp2dAngConstraintAtom(FinishingFlag f);
    hkp2dAngConstraintAtom() : hkpConstraintAtom(FinishingFlag()) {}

    unsigned char m_ucFreeRotationAxis;
    char unk03;
};
