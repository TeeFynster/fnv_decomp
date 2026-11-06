#pragma once

#include "BSSimpleList.h"

class BGSPerkEntry;
class TESConditionItem;
class TESFile;
class TESForm;
class TESObjectREFR;

class PerkEntryConditionSet
{
public:
    // a list of conditions: the constructor 0x006808b0 constructs it (EH-framed list constructor call)
    BSSimpleList<TESConditionItem*> m_kConditionItems;

    PerkEntryConditionSet();
    ~PerkEntryConditionSet();

    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result, bool arg3);
    void InitItem(TESForm* form);
    bool Compare(PerkEntryConditionSet* other);
    void InitializeConditionItems();
    void Load(TESFile* file);
    BGSPerkEntry*& GetItem();
    void ProcessItems();
    void CopyConditions(PerkEntryConditionSet* source, PerkEntryConditionSet* other);
    TESConditionItem* GetItemByIndex(int index);
    void Destroy();
    void* DeleteConditions(unsigned int flags);
};
