#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;

class hkpLinConstraintAtom : public hkpConstraintAtom
{
public:
    hkUint8 m_ucAxisIndex;
    char pad3[0x1];
};
