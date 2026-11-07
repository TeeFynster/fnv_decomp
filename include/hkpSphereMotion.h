#pragma once

#include "hkpMotion.h"

class hkpSphereMotion : public hkpMotion
{
public:
    hkpSphereMotion(void* pFirst, void* pSecond);

    virtual void GetInverseScaleMatrix(hkMatrix3& kInertia) const;
    virtual void GetInertiaLocal(hkMatrix3& kInertia) const;
    virtual void SetInertiaLocal(const hkMatrix3& kInertia);
    virtual void SetInertiaInvLocal(const hkMatrix3& kInverseInertia);
    virtual void GetInertiaInvLocal(hkMatrix3& kInverseInertia) const;
    virtual void GetLocalInverseInertia(hkMatrix3& kInverseInertia) const;
    virtual void GetProjectedPointVelocity(const hkVector4& kPosition, const hkVector4& kDirection,
                                          float& kVelocity, float& kInverseVirtualMass) const;
    virtual void ApplyImpulseAtPoint(const hkVector4& kImpulse, const hkVector4& kPoint);
    virtual void ApplyAngularImpulseToBodies(const hkVector4& kImpulse);
    virtual void vf58(float fTimestep, const hkVector4& kForce, const hkVector4& kPoint);
    virtual void vf5c(float fTimestep, const hkVector4& kForce);
    virtual void StepMotion(float fTimestep, const hkVector4& kTorque);

    void getInertiaLocal(int iOut);
    void hkpSphereMotion_getInertiaWorld(float* pOut);
    void setInertiaLocal(const hkMatrix3& kInertia);
    void SetInertiaAndMassInv(const float* pInverseInertia);
    void GetDiagonalInverseInertia_00d1e3d0(hkMatrix3& kInertiaInvOut);
    void GetDiagonalInverseInertia(hkMatrix3* pOut) const;
    void ApplyImpulse(const hkVector4& kImpulse, const hkVector4& kPosition);
    const hkVector4& AddAngularImpulse(const hkVector4& kImpulse);
    void ComputeVelocityAndInverseVirtualMass(const hkVector4& kPosition, const hkVector4& kNormal,
                                             float& kVelocity, float& kInverseVirtualMass) const;
};
