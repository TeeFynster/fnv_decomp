#pragma once

#include "hkpConstraintAtom.h"
#include "hkBool.h"
#include "hkMatrix3.h"

class hkpConstraintMotor;

typedef short hkInt16;

class hkpRagdollMotorConstraintAtom : public hkpConstraintAtom
{
public:
    hkBool m_bLimitEnabled;
    char pad3[0x1];
    hkInt16 m_iInitializedOffset;
    hkInt16 m_iPreviousTargetAnglesOffset;
    char pad8[0x8];
    hkMatrix3 m_kMotorAxes;
    hkpConstraintMotor* m_ppMotors[3];
    char pad4C[0x4];
};
