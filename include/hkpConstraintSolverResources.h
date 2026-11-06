#pragma once

#include "hkStepInfo.h"

class hkpSolverInfo;
class hkpConstraintQueryIn;
class hkpVelocityAccumulator;
class hkpSolverSumVelocities;

class hkpConstraintSolverResources
{
public:
    struct BufferState
    {
        char* m_pRayStart;
        char* m_kRayEnd;
        char* m_pTileTemplate;
        char* m_pValues;
    };

    const hkStepInfo* m_pStepInfo;
    hkpSolverInfo* m_pSolverInfo;
    hkpConstraintQueryIn* m_pConstraintQueryIn;
    hkpVelocityAccumulator* m_pVelocityAccumulatorA;
    hkpVelocityAccumulator* m_pVelocityAccumulatorB;
    hkpVelocityAccumulator* m_pVelocityAccumulatorC;
    union
    {
        char* m_pBufferA;
        hkpSolverSumVelocities* m_sumVelocities;
    };
    char* m_pBufferB;
    BufferState m_akBufferStates[3];
};
