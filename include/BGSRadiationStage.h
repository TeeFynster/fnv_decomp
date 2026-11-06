#pragma once

#include "TESForm.h"
#include "SpellListEntry.h"

class SpellItem;

class BGSRadiationStage : public TESForm
{
public:
    SpellListEntry data;

    BGSRadiationStage();
    virtual ~BGSRadiationStage();
    void* Destroy(unsigned int flags);
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* apCompare);
    virtual void ClearData();
    virtual void InitItem();

    bool Load(TESFile* file);
    void ResetFormData();
    SpellItem* GetSpell();
    void* __RTDynamicCast(void* form);

    static void ClearStageData(BGSRadiationStage* stage);
    static BGSRadiationStage* __cdecl GetStageForLevel(float level);
};
