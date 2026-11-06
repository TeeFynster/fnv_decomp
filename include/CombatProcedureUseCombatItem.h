#pragma once

#include "CombatProcedure.h"
#include "TESBoundObject.h"

class CombatItemDebugOutput;
class UCIActor;
class UCIController;

class CombatProcedureUseCombatItem : public CombatProcedure
{
public:
    CombatProcedureUseCombatItem(TESBoundObject* apItem);

    virtual ~CombatProcedureUseCombatItem();
    virtual void Unk04();
    virtual void d05();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    COMBAT_PROCEDURES GetProcedureType();
    void SetVtableAndInit();
    void* DestroyIfFlagged(unsigned int flags);
    void UpdateCombatItemUse();
    void PrintDebugInfo(CombatItemDebugOutput* pPrinter, unsigned int a2, unsigned int a3);
    void FUN_009dac80(BGSLoadFormBuffer* apLoadGameBuffer);
    UCIActor* FUN_00996de0();
    void SetState();

    TESBoundObject* pItem;
    bool m_bItemFlag;
};
