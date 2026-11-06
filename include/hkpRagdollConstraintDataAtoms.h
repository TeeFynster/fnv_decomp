#pragma once

#include "hkpSetLocalTransformsConstraintAtom.h"
#include "hkpRagdollMotorConstraintAtom.h"
#include "hkpAngFrictionConstraintAtom.h"
#include "hkpTwistLimitConstraintAtom.h"
#include "hkpConeLimitConstraintAtom.h"
#include "hkpBallSocketConstraintAtom.h"

class hkpRagdollConstraintDataAtoms
{
public:
    enum Axis
    {
        AXIS_TWIST = 0,
        AXIS_PLANES = 1,
        AXIS_CROSS_PRODUCT = 2
    };

    hkpSetLocalTransformsConstraintAtom m_kTransforms;
    hkpRagdollMotorConstraintAtom m_kMotor;
    hkpAngFrictionConstraintAtom m_kFriction;
    hkpTwistLimitConstraintAtom m_kTwistLimit;
    hkpConeLimitConstraintAtom m_kConeLimit;
    hkpConeLimitConstraintAtom m_kPlaneLimit;
    hkpBallSocketConstraintAtom m_kBallSocket;
};
