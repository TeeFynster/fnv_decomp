#pragma once

#include "BGSPerkEntry.h"
#include "PerkEntryPointData.h"

class BGSEntryPointFunctionData;
class PerkEntryConditionSet;

class BGSEntryPointPerkEntry : public BGSPerkEntry
{
public:
    PerkEntryPointData Data;
    unsigned char layoutPaddingB[1];
    BGSEntryPointFunctionData* m_pFunctionData;
    PerkEntryConditionSet* m_pConditions;

    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual ~BGSEntryPointPerkEntry();
    virtual void ClearData();
    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual unsigned char GetEntryPoint();
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void RemoveEntryPointEffect(Actor* actor, bool remove);

    BGSEntryPointPerkEntry();
    void* Destroy(unsigned int flags);
    BGSEntryPointPerkEntry& operator=(const BGSEntryPointPerkEntry& entry);
};
