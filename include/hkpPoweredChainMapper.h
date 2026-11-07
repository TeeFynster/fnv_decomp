#pragma once

#include <xmmintrin.h>
#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkpConstraintChainInstance;
class hkpConstraintMotor;
class hkpPoweredChainMapperLinkInfo;
class hkpPoweredChainMapperTarget;

class hkpPoweredChainMapper : public hkReferencedObject
{
public:
    virtual ~hkpPoweredChainMapper() throw();

    void setMotors(int linkIndex, int motorIndex, hkpConstraintMotor* motor);
    void CollectSlotValues(int range, int slot, hkArray<int>& out);
    void SetLinkVector(int chainIndex, const __m128& vec);

    hkArray<hkpPoweredChainMapperLinkInfo> m_ppLinks;
    hkArray<hkpPoweredChainMapperTarget> m_kTargets;
    hkArray<hkpConstraintChainInstance*> m_kChainInstances;
};
