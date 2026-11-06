#pragma once

class UnsignedIdHandle;

class CombatWorldStateListNode
{
public:
    UnsignedIdHandle* item;
    CombatWorldStateListNode* next;

    void AddSoundEntry(int, int);
    void RemoveItemByOwner(int);
    CombatWorldStateListNode* GetNext();
    CombatWorldStateListNode* operator->();
};
