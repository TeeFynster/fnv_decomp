#pragma once

#include "hkVector4.h"
#include "hkMatrix3.h"

typedef float hkReal;

class hkpMassProperties
{
public:
    hkReal m_iBufferSize;
    hkReal m_fViscosityFriction;
    hkVector4 m_kCenterOfMass1;
    hkMatrix3 m_kInertiaTensor;

    hkpMassProperties();
};
