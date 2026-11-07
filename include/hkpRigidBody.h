#pragma once

#include "hkpEntity.h"

class hkMatrix3;
class hkMotionState;
class hkQuaternion;
class hkTransform;
class hkVector4H;
class NiPoint3;
class NiQuaternion;

class hkpRigidBody : public hkpEntity
{
public:
    static const ClassMemberDescriptor Members[];

    hkpRigidBody(FinishingFlag flag);

    virtual hkMotionState* GetMotionState();

    hkpMotion* getRigidMotion();
    hkpMotion* getRigidMotion() const;
    const hkTransform& getTransform() const;
    void GetInertiaInvLocal(hkMatrix3& m);
    float getMassInv();
    const hkVector4& getCenterOfMassLocal();
    const hkVector4& getCenterOfMassLocal() const;
    const hkVector4& getCenterOfMassInWorld() const;
    const hkVector4& getPosition() const;
    const hkQuaternion& getRotation() const;
    const hkVector4& getLinearVelocity() const;
    const hkVector4& getAngularVelocity() const;
    void getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
    void SetTranslationalVelocity(const hkVector4& vel);
    void SetRotationalVelocity(const hkVector4& vel);
    void OnTrigger(const hkVector4&);
    void hkpRigidBody_setAngularVelocity(const hkVector4&);
    void SetWorldPosition(const NiPoint3&);
    void SetBodyOrientation(const NiQuaternion&);
    void SetPositionAndRotation(const NiPoint3&, const NiQuaternion&);
    void SetCollisionShape(void* p);
    void hkpRigidBody_setMassInv(float f);

    static void __cdecl createDynamicRigidMotion(
        hkpMotion::MotionType motionType,
        const hkVector4& position, const hkQuaternion& rotation,
        hkReal mass, const hkMatrix3& inertiaLocal,
        const hkVector4& centreOfMassLocal,
        hkReal maxLinearVelocity, hkReal maxAngularVelocity,
        hkpMaxSizeMotion* motionBufferOut);
    static void __cdecl createDynamicRigidMotion(
        hkpMotion::MotionType motionType,
        const hkVector4H& position, const hkQuaternion& rotation,
        hkReal mass, const hkMatrix3& inertiaLocal,
        const hkVector4H& centreOfMassLocal,
        hkReal maxLinearVelocity, hkReal maxAngularVelocity,
        hkpMaxSizeMotion* motionBufferOut);
};
