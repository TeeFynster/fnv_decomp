#pragma once

#include "BSExtraData.h"

class TrespassPackage;

class ExtraTresPassPackage : public BSExtraData
{
public:
    ExtraTresPassPackage(TrespassPackage* pack);
    virtual ~ExtraTresPassPackage();

    void FUN_00432900();
    void* FUN_0042c890(unsigned int flags);

    union
    {
        TrespassPackage* package;
        TrespassPackage* pTargetPackage;
    };
};
