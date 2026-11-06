#pragma once

#include "hkVector4.h"
#include "hkQuaternion.h"
class hkTransform;

struct ClassMemberDescriptor;

typedef float hkReal;
typedef float hkTime;

class hkSweptTransform
{
public:
    static const ClassMemberDescriptor Members[];

    __forceinline void _approxTransformAt(hkTime time, hkTransform& transformOut) const;
    hkReal getInterpolationValue(hkTime t) const;
    hkTime getBaseTime() const;
    __forceinline hkReal getInvDeltaTime() const;

    hkVector4 m_vCenterOfMass0;
    hkVector4 m_vCenterOfMass1;
    hkQuaternion m_qRotation0;
    hkQuaternion m_qRotation1;
    hkVector4 m_vCenterOfMassLocal;
};
