#pragma once

#include "hkpFirstPersonGun.h"
#include "hkaAnimation.h"
#include "hkVector4.h"

class hkTransform;
class hkpRigidBody;
class hkpWorld;
class GGRigidBody;
class GGTransform;
class GGWorld;
class GunTransform;
class GunArg3;

class hkpGravityGun : public hkpFirstPersonGun
{
public:
    hkArray<void*> m_kPickedBodies;
    hkInt32 m_iMaxPickedBodies;
    hkReal m_fMaxPickMass;
    hkReal m_fMaxPickDistance;
    hkReal m_fPickAngle;
    hkReal m_fHoldDistance;
    hkVector4 m_kGrabPosition;
    hkVector4 m_kTargetPosition;

    hkpGravityGun() throw();
    hkpGravityGun(FinishingFlag);
    hkpGravityGun* DestroyAndFree(unsigned int) throw();

    hkpRigidBody* hkpGravityGun_dropObject(int);
    hkpRigidBody* FindVisibleRigidBodyToGrab(int, int, int);
    GGRigidBody* FindVisibleRigidBodyToGrab(const GGTransform&, const GGRigidBody*, const GGWorld*);
    bool isGrabbed(const GGRigidBody*) const;
    void gravityGunPush(int dirSlot, int viewSlot, int p3Slot);
    void gravityGunPush(GunTransform*, GunArg3*, hkpWorld*);
    void DropPickedObjectIfPresent(int, int, int);
    void DropPickedObjectIfPresent(GunTransform*, GunArg3*, hkpWorld*);
    void RemoveAllReferences(int);
    __declspec(noinline) void gravityGunStep(float dTime, const hkTransform& transform, hkpRigidBody* otherRb);
    void gravityGunStep(hkReal, GunTransform*, GunArg3*);
    void takeObject(hkpRigidBody*);
    void gravityGunPull(hkTransform*, hkpRigidBody*, hkpWorld*);
    void gravityGunPull(GunTransform*, GunArg3*, hkpWorld*);
    void stepGun(hkReal, hkpWorld*, GunArg3*, GunTransform*, bool, bool);
};
