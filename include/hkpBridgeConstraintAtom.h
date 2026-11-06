#pragma once

#include "hkpConstraintAtom.h"

class hkpConstraintData;

class hkpBridgeConstraintAtom : public hkpConstraintAtom
{
public:
    hkpBridgeConstraintAtom();
    hkpBridgeConstraintAtom(FinishingFlag flag);
    void FUN_00d21ce0(void* constraintData) throw();

    char pad2[0x2];
    void* m_pBridge;
    hkpConstraintData* m_pConstraintData;
};
