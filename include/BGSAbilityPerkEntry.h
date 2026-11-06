#pragma once

#include "BGSPerkEntry.h"

class SpellItem;

class BGSAbilityPerkEntry : public BGSPerkEntry
{
public:
    SpellItem* m_pSpell;

    BGSAbilityPerkEntry();
    BGSAbilityPerkEntry* Initialize();

    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void RemoveEntryPointEffect(Actor* actor, bool remove);
};
