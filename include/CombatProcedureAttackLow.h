#pragma once

#include "CombatProcedure.h"
#include "IDebugText.h"

class TESObjectWEAP;

class CombatProcedureAttackLow : public CombatProcedure
{
public:
    virtual ~CombatProcedureAttackLow();
    virtual void Unk04() override;
    virtual void d05() override;
    virtual int GetType() override;
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer) override;
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer) override;

    void SetVtableAndProcessState_009cbb50();
    void* DestroyIfFlagged(unsigned int flags);
    void CombatProcedureAttackLow_Update();
    void DisplayAttackDebugText(IDebugText* apDebugText, DEBUGTEXT_LOCATION aeLocation,
                                DEBUGTEXT_JUSTIFY aeJustify);
    void SaveGame_009cbfd0(BGSSaveFormBuffer* apSaveGameBuffer);
    void CombatProcedureAttackLow_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    int m_10;
    int m_14;
    int m_18;
    TESObjectWEAP* pWeapon;
};
