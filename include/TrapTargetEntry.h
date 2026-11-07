#pragma once

#include "TargetEntry.h"
#include "CombatWorldStateListNode.h"

class ZoneEntry;

class TrapTargetEntry : public TargetEntry
{
public:
    virtual void Run_0062c600(ZoneEntry* apTrap);

    unsigned char unk0C[4];
    CombatWorldStateListNode _list;
};
