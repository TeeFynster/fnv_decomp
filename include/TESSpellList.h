#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"

class BGSLoadFormBuffer;
class BSFileEntry;
class InventoryStackRecord;
class SpellItem;
class TESForm;
class TESLevSpell;

class TESSpellList : public BaseFormComponent
{
public:
    TESSpellList();
    ~TESSpellList();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned int GetSaveSizeTES(unsigned int flags);
    virtual void SaveGameTES(unsigned int flags);
    virtual void LoadGameTES(unsigned int flags);

    void InitializeComponent();
    void ClearComponent();
    void ClearSpells();
    void BaseFormRecord(BaseFormComponent* component);
    void InitItem(TESForm* form);
    void Save();
    void TESSpellList_AddSpell_0048d210(TESLevSpell* spell);
    void TESSpellList_AddSpell_0048d290(unsigned int spellID);
    void TESSpellList_SaveSubRecord();
    BSSimpleList<InventoryStackRecord*>* GetOffsetC();
    void LoadGame(BGSLoadFormBuffer* buffer);
    static bool RemoveSpell(BSFileEntry* spell);

    BSSimpleList<SpellItem*> spellList;
    BSSimpleList<TESLevSpell*> leveledSpellList;
};
