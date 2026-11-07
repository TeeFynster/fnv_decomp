#pragma once

#include "TESForm.h"
#include "SpellItemValueEntry.h"

class SpellItem;

class BGSSleepDeprevationStage : public TESForm
{
public:
    SpellItemValueEntry data;

    BGSSleepDeprevationStage();
    virtual ~BGSSleepDeprevationStage();

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    SpellItem* GetSpell();
    unsigned int GetSpellFormID();
    void SetSpell(SpellItem* sickness);
    void* GetData();
    void CopyFromSleepDeprivationStage(TESForm* apCopy);
    unsigned int FUN_00441110();
    void FUN_0050f9a0(SpellItem* sickness);
    void* FUN_00500940();
    void FUN_004021a0();
    void* FUN_00402170(unsigned int flags);
    bool Compare_00402310(TESForm* pkForm);

    static void ClearStageData(BGSSleepDeprevationStage* stage);
};
