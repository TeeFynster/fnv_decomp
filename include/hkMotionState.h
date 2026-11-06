#pragma once

#include "hkTransform.h"
#include "hkSweptTransform.h"
#include "hkVector4.h"
#include "QuantizedFloat8.h"

struct ClassMemberDescriptor;
typedef unsigned char hkUint8;

class hkMotionState
{
public:
    hkTransform m_kMotionTransform;
    hkSweptTransform m_kSweptTransform;
    hkVector4 m_kDeltaAngle;
    hkReal m_fObjectRadius;
    hkReal m_fLinearDamping;
    hkReal m_fAngularDamping;
    QuantizedFloat8 m_fSurfaceFriction;
    QuantizedFloat8 m_fRestitution;
    hkUint8 m_uiDeactivationClass;
    char padAF[1];

    hkMotionState();
    hkMotionState(const hkMotionState& o);
    hkTransform& getTransform();
    const hkTransform& getTransform() const;
    hkSweptTransform& getSweptTransform();
    const hkSweptTransform& getSweptTransform() const;

    static const ClassMemberDescriptor Members[];
};
