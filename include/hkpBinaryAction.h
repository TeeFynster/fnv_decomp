#pragma once

#include "hkpAction.h"

class hkpEntity;

class hkpBinaryAction : public hkpAction
{
public:
    void FUN_00cf4d80(int entityA, int entityB, int userData);

    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
};
