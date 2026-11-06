#pragma once

#include "BGSZoneTargetListener.h"
#include "bhkTrapListener.h"

class TESTrapListener : public BGSZoneTargetListener, public bhkTrapListener
{
public:
    virtual void* __thiscall Destroy(unsigned int flags);

    void DestroyContents();
    void FUN_0062d8a0();
    void* FUN_0062d870(unsigned int flags);
};
