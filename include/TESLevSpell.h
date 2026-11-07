#pragma once

#include "TESBoundObject.h"
#include "TESLeveledList.h"

class SpellItem;

class TESLevSpell : public TESBoundObject, public TESLeveledList
{
public:
    TESLevSpell();
    virtual ~TESLevSpell();

    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm();
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void Copy_0050bcd0(TESForm* apCopy);
    bool Compare_0050bd10(TESForm* apCompare);
    SpellItem* GetLeveledSpell(void* actor, unsigned short level);
    void SelectLeveledSpell(void* desiredForm, unsigned short level,
                           unsigned int* outForm, unsigned short* outCount,
                           unsigned char recurse);
};
