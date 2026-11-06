#pragma once

#include "TESObjectMISC.h"

class TESKey : public TESObjectMISC
{
public:
    TESKey();
    virtual ~TESKey();

    void* Destroy(unsigned int flags);
    void FUN_0050a6a0();
};
