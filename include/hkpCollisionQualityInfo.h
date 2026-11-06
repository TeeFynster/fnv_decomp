#pragma once
#include "hkBool.h"
#include "hkPadSpu.h"

typedef float hkReal;
typedef int hkBool32;

// src: XBOX_PDB; hkpCollisionQualityInfo is 0x40 bytes. Exe continuous GSK reads TOI fields through +0x3e.
struct hkpCollisionQualityInfo
{
    __declspec(align(16)) hkReal m_fMinimumCollisionSeparation;
    hkReal m_fMinimumExtraSeparation;
    hkReal m_fMaximumExtraSeparation;
    hkReal m_fTimeOfImpactSeparation;
    hkPadSpu<hkBool32> m_iQualityInfoValue10;
    hkBool m_bUseContinuousPhysics;
    hkReal m_fCreateContactThreshold;
    hkReal m_fManifoldTimeDistance;
    hkReal m_fMinimumSafeDeltaTime;
    hkReal m_fMinimumAbsoluteTimeOfImpact;
    hkReal m_fMinimumTimeOfImpactDelta;
    hkReal m_fMaximumTimeOfImpactDelta;
    hkReal m_fMaximumConstraintViolation;
    hkReal m_fMaximumLinearVelocity;
    hkReal m_fMaximumAngularVelocity;
    unsigned short m_usValueAtOffset3C;
    hkBool m_bEnableToiWeldRejection;
};
