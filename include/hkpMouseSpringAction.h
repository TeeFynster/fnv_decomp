#pragma once

#include "hkpUnaryAction.h"
#include "hkVector4.h"
#include "hkaAnimation.h"

typedef unsigned int hkUint32;

class hkpMouseSpringAction : public hkpUnaryAction
{
public:
    void ApplySpringForce(void*);

    char pad1C[0x4];
    hkVector4 m_kMousePositionInWorld;
    hkVector4 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    hkUint32 m_uiCollisionShapeKey;
    hkArray<char> m_kAppliedCallbacks;
};
