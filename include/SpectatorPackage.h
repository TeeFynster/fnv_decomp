#pragma once

#include "TESPackage.h"

class SpectatorPackage : public TESPackage
{
public:
    int IsComplete(const SpectatorPackage& other);
    void __thiscall ProcessEntries_009f8420(Actor& aActor);
};
