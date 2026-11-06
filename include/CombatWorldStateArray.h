#pragma once

// CombatWorldStateArray: real name (was CombatStateArray). Its 3 bound methods are CombatWorldStateArray::* in the names DB; ctor 0x009aa470.

class CombatWorldStateArray
{
public:
    char _00[0x50];
    char _50[0x0C];

    void __thiscall CopyFrom(CombatWorldStateArray* apWorldStateArray);
    CombatWorldStateArray* FUN_009aa490(CombatWorldStateArray*);
    bool FUN_009aadc0(unsigned int, int);
};
