#pragma once

#include "hkpSetLocalTransformsConstraintAtom.h"
#include "hkpAngFrictionConstraintAtom.h"
#include "hkpBallSocketConstraintAtom.h"
#include "hkBool.h"

class hkpAngMotorConstraintAtom : public hkpConstraintAtom
{
public:
    hkpAngMotorConstraintAtom() : hkpConstraintAtom(FinishingFlag()) {}

    hkBool m_bLimitEnabled;
    unsigned char m_ucMotorAxis;
    short m_iInitializedOffset;
    short m_iPreviousTargetAngleOffset;
    short m_iCorrespondingAngLimitSolverResultOffset;
    char unk0A[2];
    float m_fTargetAngle;
    void* m_pMotor;
};

#include "hkpAngLimitConstraintAtom.h"

#include "hkp2dAngConstraintAtom.h"

class __declspec(align(16)) hkpLimitedHingeConstraintDataAtoms
{
public:
    enum Axis
    {
        AXIS_AXLE = 0,
        AXIS_PERP_TO_AXLE_1 = 1,
        AXIS_PERP_TO_AXLE_2 = 2
    };

    hkpLimitedHingeConstraintDataAtoms() throw();

    char pad0[0xD0];

    __forceinline hkpSetLocalTransformsConstraintAtom& getTransforms()
    {
        return *reinterpret_cast<hkpSetLocalTransformsConstraintAtom*>(pad0);
    }
    __forceinline hkpAngMotorConstraintAtom& getAngularMotor()
    {
        return *reinterpret_cast<hkpAngMotorConstraintAtom*>(pad0 + 0x90);
    }
    __forceinline hkpAngFrictionConstraintAtom& getFriction()
    {
        return *reinterpret_cast<hkpAngFrictionConstraintAtom*>(pad0 + 0xA4);
    }
    __forceinline hkpAngLimitConstraintAtom& getAngularLimit()
    {
        return *reinterpret_cast<hkpAngLimitConstraintAtom*>(pad0 + 0xB0);
    }
    __forceinline hkp2dAngConstraintAtom& getTwoDimensionalAngular()
    {
        return *reinterpret_cast<hkp2dAngConstraintAtom*>(pad0 + 0xC0);
    }
    __forceinline hkpBallSocketConstraintAtom& getBallSocket()
    {
        return *reinterpret_cast<hkpBallSocketConstraintAtom*>(pad0 + 0xC4);
    }

    __declspec(property(get = getTransforms)) hkpSetLocalTransformsConstraintAtom m_kTransforms;
    __declspec(property(get = getAngularMotor)) hkpAngMotorConstraintAtom m_kAngularMotor;
    __declspec(property(get = getFriction)) hkpAngFrictionConstraintAtom m_kFriction;
    __declspec(property(get = getAngularLimit)) hkpAngLimitConstraintAtom m_kAngularLimit;
    __declspec(property(get = getTwoDimensionalAngular)) hkp2dAngConstraintAtom m_kTwoDimensionalAngular;
    __declspec(property(get = getBallSocket)) hkpBallSocketConstraintAtom m_kBallSocket;
};
