#pragma once

class CombatController;
class TESObjectREFR;
class TESBoundObject;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class NiPoint3;

class CombatProcedure
{
public:
    enum COMBAT_PROCEDURE_STATUS
    {
        ACTIVE = 0,
        FAILED = 1,
        FINISHED = 2,
        COMBAT_PROCEDURE_STATUS_COUNT = 3,
    };

    enum COMBAT_PROCEDURES  // values: Xbox PDB CombatProcedure::COMBAT_PROCEDURES
    {
        NONE = -1,
        ATTACK_RANGED = 0,
        ATTACK_MELEE = 1,
        ATTACK_GRENADE = 2,
        ATTACK_LOW = 3,
        EVADE = 4,
        SWITCH_WEAPON = 5,
        MOVE_TO_LOCATION = 6,
        BE_IN_COVER = 7,
        ACTIVATE_OBJECT = 8,
        HIDE_FROM_TARGET = 9,
        SEARCH = 10,
        USE_COMBAT_ITEM = 11
    };

    CombatController* m_pCombatController;
    int eStatus;
    const char* m_pcProcedureName;

    CombatProcedure();

    virtual ~CombatProcedure();
    virtual void Unk04();
    virtual void Unk08(CombatController*);
    virtual void Unk0c();
    virtual void Unk10(int);
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void OnInventoryItemChanged(TESObjectREFR* apRef, TESBoundObject* apObject,
                                        int aiCount, bool abActivatedScriptOnly);
    virtual void d11();
    virtual void d12();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    void Initialize(CombatController*);
    void RunProcedure();
    void* DestroyIfFlagged(unsigned int flags);
    void SetVirtualTable_009ca6c0();
    void* GetTarget_00996e00();
    void SetMoveMode_00996e20(int aiCombatMoveMode);
    void ClearMoveMode();
    void SetLookAtPoint(const NiPoint3& arLookAtPoint, unsigned char acPriority);
    void ClearLookAtTarget_00996ea0();
    void SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
    void LoadGame_00996ef0(BGSLoadFormBuffer* buffer);
};
