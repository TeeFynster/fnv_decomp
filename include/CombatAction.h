#pragma once

#include "CombatWorldStateListNode.h"

struct CombatController;
struct CombatWorldStateArray;
class CombatWriter;
class SavedCombatState;

class CombatAction
{
public:
    enum COMBAT_ACTION
    {
        COMBAT_ACTION_NONE = -1,
        COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE = 0,
        COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE_FROM_COVER = 1,
        COMBAT_ACTION_ATTACK_RANGED = 2,
        COMBAT_ACTION_ATTACK_RANGED_FROM_COVER = 3,
        COMBAT_ACTION_ATTACK_GRENADE = 4,
        COMBAT_ACTION_ATTACK_GRENADE_FLUSH_TARGET = 5,
        COMBAT_ACTION_ATTACK_GRENADE_FROM_COVER = 6,
        COMBAT_ACTION_ATTACK_MELEE = 7,
        COMBAT_ACTION_ATTACK_HAND_TO_HAND = 8,
        COMBAT_ACTION_MOVE = 9,
        COMBAT_ACTION_MOVE_AND_SWITCH_TO_MELEE = 10,
        COMBAT_ACTION_MOVE_AND_ATTACK_RANGED = 11,
        COMBAT_ACTION_MOVE_AND_ATTACK_RANGED_EXPLOSIVE = 12,
        COMBAT_ACTION_MOVE_AND_ATTACK_GRENADE = 13,
        COMBAT_ACTION_DRAW_WEAPON = 14,
        COMBAT_ACTION_SWITCH_WEAPON = 15,
        COMBAT_ACTION_AVOID_THREAT = 16,
        COMBAT_ACTION_SEARCH = 17,
        COMBAT_ACTION_INVESTIGATE = 18,
        COMBAT_ACTION_DODGE = 19,
        COMBAT_ACTION_IGNORE_BLOCKED_TARGET = 20,
        COMBAT_ACTION_FLEE = 21,
        COMBAT_ACTION_ACTIVATE_COMBAT_ITEM = 22,
        COMBAT_ACTION_USE_COMBAT_ITEM = 23,
        COMBAT_ACTION_ACQUIRE_LINE_OF_SIGHT = 24,
        COMBAT_ACTION_HIDE = 25,
        COMBAT_ACTION_APPROACH_TARGET = 26,
        COMBAT_ACTION_COUNT = 27
    };

    CombatAction(COMBAT_ACTION);
    ~CombatAction();

    virtual void vfn_0();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();

    static CombatAction* CreateAction(COMBAT_ACTION type);
    static CombatAction* __cdecl CreateAction(int type);

    char* GetCombatActionName();
    void FUN_00979c80();
    float GetCost_00979e40(CombatController* apCombatController, int aiActionValue);
    void GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
    bool CanExecute(CombatController* apCombatController, CombatWorldStateArray* apWorldStateArray, int aiActionValue);
    bool HasRequirement(int state, int* value);
    void HasRequirement(int aiArg1, int aiArg2);

    void AddEffect(int state, int value);
    void AddFirstSoundEntry(int state, int value);
    void AddSecondSoundEntry(int state, int value);
    void AddActionWorldState(int state, int value);
    void RemoveActionWorldStateByOwner(int state);
    void RemoveEffectByOwner(int state);
    void RemoveFirstSoundEntryByOwner(int state);
    void SaveGame(CombatWriter* writer, SavedCombatState* state);

    CombatWorldStateListNode m_kFirstSoundEntryNode;
    CombatWorldStateListNode m_kActionWorldStateNode;
    CombatWorldStateListNode Effects;
    CombatWorldStateListNode m_kSecondSoundEntryNode;
    COMBAT_ACTION eType;
    unsigned int iFlags;
};
