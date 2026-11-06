#pragma once

#include "hkpConstraintMotor.h"

typedef float hkReal;

class hkpLimitedForceConstraintMotor : public hkpConstraintMotor
{
public:
    __forceinline hkpLimitedForceConstraintMotor(const hkpLimitedForceConstraintMotor& o) throw()
        : hkpConstraintMotor(o), m_fMinForce(o.m_fMinForce), m_fMaxForce(o.m_fMaxForce)
    {}

    hkReal m_fMinForce;
    hkReal m_fMaxForce;
};
