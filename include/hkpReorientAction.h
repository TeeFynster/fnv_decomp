#pragma once

#include "hkpUnaryAction.h"
#include "hkVector4.h"

class hkpPhantom;

typedef float hkReal;

class hkpReorientAction : public hkpUnaryAction
{
public:
    hkpReorientAction(hkpEntity* entity, const hkVector4& rotationAxis, const hkVector4& upAxis,
                      float strength, float damping) throw();
    virtual ~hkpReorientAction() throw();
    hkpReorientAction* Clone(const hkArray<hkpEntity*>& newEntities,
                            const hkArray<hkpPhantom*>& newPhantoms) const;

    char pad1C[0x4];
    hkVector4 m_vRotationAxis;
    hkVector4 m_vUpAxis;
    hkReal m_fSpringStrength;
    hkReal m_fMotorDamping;
    char pad48[0x8];
};
