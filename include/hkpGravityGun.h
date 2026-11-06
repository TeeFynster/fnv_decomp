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

    hkpRigidBody* FUN_00e45e60(int);
    hkpRigidBody* FUN_00e45a60(int, int, int);
    GGRigidBody* FUN_00e45a60(const GGTransform&, const GGRigidBody*, const GGWorld*);
    bool isGrabbed(const GGRigidBody*) const;
    void FUN_00e45ee0(int dirSlot, int viewSlot, int p3Slot);
    void FUN_00e45ee0(GunTransform*, GunArg3*, hkpWorld*);
    void FUN_00e45fb0(int, int, int);
    void FUN_00e45fb0(GunTransform*, GunArg3*, hkpWorld*);
    void RemoveAllReferences(int);
    __declspec(noinline) void FUN_00e45c90(float dTime, const hkTransform& transform, hkpRigidBody* otherRb);
    void FUN_00e45c90(hkReal, GunTransform*, GunArg3*);
    void FUN_00e46000(hkpRigidBody*);
    void FUN_00e46080(hkTransform*, hkpRigidBody*, hkpWorld*);
    void FUN_00e46080(GunTransform*, GunArg3*, hkpWorld*);
    void FUN_00e46140(hkReal, hkpWorld*, GunArg3*, GunTransform*, bool, bool);
};
