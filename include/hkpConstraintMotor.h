#pragma once

#include "hkReferencedObject.h"

class hkpConstraintMotor : public hkReferencedObject
{
public:
    enum MotorType
    {
        TYPE_INVALID = 0,
        TYPE_POSITION = 1,
        TYPE_VELOCITY = 2,
        TYPE_SPRING_DAMPER = 3,
        TYPE_CALLBACK = 4,
        TYPE_MAX = 5
    };

    __forceinline hkpConstraintMotor(const hkpConstraintMotor& o) throw()
        : hkReferencedObject(), m_type(o.m_type)
    {}

    virtual void vf03();

    signed char m_type;
    char pad9[0x3];
};
