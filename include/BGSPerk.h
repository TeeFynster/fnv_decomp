#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "TESIcon.h"
#include "PerkData.h"
#include "PerkEntryConditionSet.h"
#include "MagicTarget.h"
#include "BGSPerkEntry.h"

class Actor;
class PlayerCharacter;
class TESFile;

class BGSPerk : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
public:
    PerkData Data;
    PerkEntryConditionSet m_kConditions;
    BSSimpleList<BGSPerkEntry*> m_kEntryList;

    BGSPerk();
    virtual ~BGSPerk();
    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();

    void ResetFormData();
    bool AppendPerkEntry(BGSPerkEntry* entry);
    bool Load(TESFile* file);
    void ApplyPerkEntries(Actor* actor, unsigned char rank, bool alternate);
    bool IsPerkHidden() const;
    unsigned char BGSPerk_GetNumRanks();
    signed char Level();
    signed char GetByteAt39();
    bool GetByteAtOffset56();
    bool IsPerkAttainable(PlayerCharacter* player);
    bool CheckPlayerConditions();
    bool BGSPerk_IsPerkAvailable(PlayerCharacter* player);
    void GetDescription(char* buffer, unsigned int size);
};
