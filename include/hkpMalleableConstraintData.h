#pragma once

#include "hkpConstraintData.h"
#include "hkpBridgeAtoms.h"

class hkpMalleableConstraintData : public hkpConstraintData
{
public:
    hkpMalleableConstraintData(hkpConstraintData* ref) throw();
    virtual ~hkpMalleableConstraintData() throw();

    hkpConstraintData* m_pConstraintData;
    hkpBridgeAtoms m_kBridgeAtoms;
    float m_fSpringStrength;
};
