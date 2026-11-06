#pragma once

#include "TESForm.h"
#include "HungerStageData.h"

class SpellItem;

class BGSHungerStage : public TESForm
{
public:
    HungerStageData data;

    BGSHungerStage();
    virtual ~BGSHungerStage();

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    SpellItem* GetSpell();
    HungerStageData* GetData();
    HungerStageData* FUN_00500940();
    void CopyFromForm(TESForm* source);
    void FUN_00401ac0();
    void* FUN_00401a90(unsigned int flags);

    static void ClearStageData(BGSHungerStage* stage);
};
