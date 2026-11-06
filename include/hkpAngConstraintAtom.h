#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;

class hkpAngConstraintAtom : public hkpConstraintAtom
{
public:
    hkUint8 m_ucFirstConstrainedAxis;
    hkUint8 m_ucNumConstrainedAxes;
};
