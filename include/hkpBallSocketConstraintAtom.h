#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;
typedef float hkReal;

class hkpBallSocketConstraintAtom : public hkpConstraintAtom
{
public:
    hkUint8 m_ucBodiesToNotify;
    hkUint8 m_solvingMethod;
    hkReal m_usFlags;
};
