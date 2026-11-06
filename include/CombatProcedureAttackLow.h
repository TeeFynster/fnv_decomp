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

    void FUN_009cbb50();
    void* DestroyIfFlagged(unsigned int flags);
    void FUN_009cbb70();
    void DisplayAttackDebugText(IDebugText* apDebugText, DEBUGTEXT_LOCATION aeLocation,
                                DEBUGTEXT_JUSTIFY aeJustify);
    void FUN_009cbfd0(BGSSaveFormBuffer* apSaveGameBuffer);
    void FUN_009cc040(BGSLoadFormBuffer* apLoadGameBuffer);

    int m_10;
    int m_14;
    int m_18;
    TESObjectWEAP* pWeapon;
};
