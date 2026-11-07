#pragma once

#include "BaseFormComponent.h"

#if !defined(FNV64_BSSIMPLELIST_DEFINED) && !defined(FNV_LAYOUT_SUPPORT_H) && !defined(FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H)
#include "BSSimpleList.h"
#endif
class ContainerChanges;
class ContainerItem;
class ContainerItemExtra;
class InventoryChanges;
class InventoryItemEntry;
class InventoryStackRecord;
class ListShell;
class TESActorBase;
class TESAmmo;
class TESBoundObject;
class TESForm;
class TESObject;
class TESObjectARMO;
class TESObjectCLOT;
class TESObjectREFR;
class TESObjectWEAP;
class TickPlayer;

class TESContainer : public BaseFormComponent
{
public:
    TESContainer();
    ~TESContainer();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void InitItem(TESForm* form);
    void ClearObjects();
    InventoryItemEntry* AddObject(ContainerChanges* changes);
    InventoryItemEntry* AddObject(TESObject* object, int count, ContainerItemExtra* extra);
    void AddObject(TESForm* form, int count, ContainerItemExtra* extra);
    void AddObject(InventoryItemEntry* object);
    void FUN_004818e0(void* object, int count, int extra);
    void FUN_004818e0(void* object, int count, void* extra);
    void* AddContainerObject(void* object);
    InventoryItemEntry* AddContainerObject(ContainerItem* item);
    void AddDuplicateObject(InventoryItemEntry* object);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry* object);
    void ReplaceObject(TESObject* object, TESObject* replacement);
    bool HasObjectOfType(TESObject* object);
    float GetContainerWeight(bool value);
    int GetObjectCount(TESObject* object);
    char Compare(InventoryItemEntry* first, InventoryItemEntry* second);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char type);
    static bool IsValidContainerObject(TESObject* object);
    void MergeContainer(TESContainer* container);
    void MultiplyContainerCounts(int multiplier);
    void ScaleEntryCounts(int multiplier);
    void SetClothingModifier(float modifier);
    void ApplyHealthPercentToContainer(float modifier);
    void AddContentsFromReference(TESObjectREFR* reference, bool value);
    void AddContainerToReference(TESObjectREFR* reference, bool value);
    void AddContainerToReference(TickPlayer* reference, int value);
    void AddContainerToReference(void* reference, bool value);
    void AddInventoryChangesToContainer(int value, InventoryChanges* changes);
    TESAmmo* GetBestAmmoForActor(TESActorBase* actor);
    TESObjectWEAP* GetBestWeapon(TESActorBase* actor);
    TESObjectARMO* FindBestArmor(TESActorBase* actor, int slot);
    TESObjectCLOT* GetBestClothing(TESActorBase* actor, int slot);
    TESBoundObject* GetInventoryEntryData(int slot);
    BSSimpleList<InventoryStackRecord*>* GetObjectList();
    void* GetObjectListEnd();
    ListShell* FUN_00717e50();

    union
    {
        struct
        {
            unsigned int count;
            InventoryItemEntry** objects;
        };
        struct
        {
            BSSimpleList<InventoryStackRecord*> objectList;
        };
    };
};
