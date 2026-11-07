#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class ContainerItemExtra;
class LeveledObject;
class TESContainer;
class TESForm;
class TESGlobal;
class TESObjectREFR;

class TESLeveledList : public BaseFormComponent
{
public:
    ~TESLeveledList();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned char vfn_10();
    virtual bool vfn_14();
    virtual int vfn_18();

    unsigned char GetChanceNone();
    bool UsesAllEntries();
    int GetMaxLevelDifference();

    void ErrorCheckList();
    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void SetChanceNone(unsigned char chance);
    void ExtraWeaponModFlags_SetWeaponModFlags(unsigned char chance);
    bool GetCalcAllBelow();
    bool GetAllBelow();
    bool FUN_004877e0();
    void SetCalcAllBelow(bool value);
    void SetMultCalc(bool value);
    bool GetUseAll();
    bool FUN_004878a0();
    void SetUseAll(bool value);
    TESGlobal* GetChanceGlobal();
    void SetChanceGlobal(TESGlobal* global);
    void InitializeLeveledList();
    void SortLeveledList();
    LeveledObject* CreateLeveledObject(unsigned short level, unsigned short count, TESForm* form, ContainerItemExtra* extra);
    void DeleteLeveledObject(LeveledObject* object);
    void SelectLeveledObject(unsigned short level, TESForm** form, unsigned short* count, ContainerItemExtra** extra, bool recurse, int mode);
    void SelectLeveledObject(unsigned short level, TESForm*& form, unsigned short& count, ContainerItemExtra*& extra, bool recurse, int mode);
    void PopulateContainerWithLeveledItems(unsigned short level, unsigned short count, TESContainer* container, int mode);
    void PopulateContainerFromReference(TESObjectREFR* reference, TESContainer* container);
    void PopulateContainerFromReference(void* reference, TESContainer* container);
    void ClearScriptAddedLeveledObjects();
    void AddScriptAddedLeveledObject(TESForm* form, unsigned short level, unsigned short count, TESForm* owner, ContainerItemExtra* extra);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    void Save();
    void InitItem(TESForm* form);
    static TESLeveledList* GetFormAsLeveledList(TESForm* form);
    void* GetLeveledList();
    // The compiler supplies __vecDelDtor(unsigned int).

    BSSimpleList<LeveledObject*> leveledList;
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    unsigned char layoutPaddingE[2];
    TESGlobal* m_pLevelGlobal;
    BSSimpleList<LeveledObject*> m_kLeveledObjects;
};
