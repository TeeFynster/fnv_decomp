#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;
typedef float hkReal;

class hkpConeLimitConstraintAtom : public hkpConstraintAtom
{
public:
    enum MeasurementMode
    {
        ZERO_WHEN_VECTORS_ALIGNED = 0,
        ZERO_WHEN_VECTORS_PERPENDICULAR = 1
    };

    hkUint8 m_bLimitEnabled;
    hkUint8 m_ucMemOffsetToAngleOffset;
    hkUint8 m_ucMemOffsetToOldAngleOffset;
    hkUint8 m_ucMemOffsetToFirstConstrainedDof;
    hkUint8 m_ucAngleMeasurementMode;
    char pad7[0x1];
    hkReal m_fMinAngle;
    hkReal m_fMaxAngle;
    hkReal m_fAngularLimitsTauFactor;
};
