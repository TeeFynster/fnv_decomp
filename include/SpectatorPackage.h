#pragma once

#include "TESPackage.h"

class SpectatorPackage : public TESPackage
{
public:
    int IsComplete(const SpectatorPackage& other);
    void __thiscall FUN_009f8420(Actor& aActor);
};
