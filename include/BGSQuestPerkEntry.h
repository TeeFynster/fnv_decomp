#pragma once

#include "BGSPerkEntry.h"

class TESQuest;

class BGSQuestPerkEntry : public BGSPerkEntry
{
public:
    BGSQuestPerkEntry();  // 0x005e9800: BGSPerkEntry(), vftable 0x01046b84, Data zeroed

    struct
    {
        TESQuest* pQuest;
        unsigned char stage;
        unsigned char padding[3];
    } Data;

    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
};
