#pragma once

#include "hkpBridgeConstraintAtom.h"

class hkpBridgeAtoms
{
public:
    hkpBridgeConstraintAtom m_kBridgeAtom;

    // src: HAVOK_SRC (hkpBridgeAtoms: default and finish-loading constructors)
    hkpBridgeAtoms() {}
    hkpBridgeAtoms(FinishingFlag flag) : m_kBridgeAtom(flag) {}
};
