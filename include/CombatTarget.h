#pragma once

class CombatPair;
class ObjectName;
class CombatWriter;
class SavedCombatState;

class CombatTarget
{
public:
    char m_data[0x68];

    void SetValue(unsigned int key, unsigned int x, unsigned int y);
    bool Lookup(unsigned int key, CombatPair* out);
    ObjectName* FUN_00413f40();
    void SaveGame_009856e0(CombatWriter*, SavedCombatState*);
};
