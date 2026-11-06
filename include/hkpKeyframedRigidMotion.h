#pragma once

#include "hkpMotion.h"

class hkpKeyframedRigidMotion : public hkpMotion
{
public:
    static const ClassMemberDescriptor Members[];

    hkpKeyframedRigidMotion(FinishingFlag flag);
    hkpKeyframedRigidMotion(const hkVector4& kPosition, const hkQuaternion& kRotationBasis) throw();
    virtual ~hkpKeyframedRigidMotion() throw();

    virtual void SetStepPosition(hkReal position, hkReal timestep);
    virtual void vf6c();

protected:
    hkpKeyframedRigidMotion();
};
