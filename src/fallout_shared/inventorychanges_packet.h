// fallout_shared/inventorychanges_packet.h: declares InventoryChanges, ExtraDataList, TESBipedModelForm
#ifndef FNV_INVENTORYCHANGES_PACKET_H
#define FNV_INVENTORYCHANGES_PACKET_H

// Canonical layouts come from include/ (src/fallout_shared has same-named local headers, so the shadowed ones are
// headers do not declare yet, so those three classes are declared here as layout-identical supersets of
#include "../../include/layout_support.h"
#include "BaseExtraList.h"
class BGSLoadFormBuffer;

#define FNV_INVENTORYCHANGES_H
#pragma pack(push, 4)
class InventoryChanges
{
  public:
    BSSimpleList<InventoryStackRecord*>* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight, m_fArmorWeight;
    bool m_bChanged;
    unsigned char pad[3];
    InventoryChanges(TESObjectREFR*);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    InventoryChanges* CreateForReference();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(InventoryChanges) == 0x14);

#define FNV_ITEMCHANGE_H
#pragma pack(push, 4)
class InventoryStackRecord
{
  public:
    BSSimpleList<ExtraDataList*>* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    InventoryStackRecord();
    ~InventoryStackRecord();
    void* GetPayloadAddress();
    static float GetConditionPercent(float);
    static float RoundToNearestStep(float, float);
    void InitLoadGame(BGSLoadFormBuffer*);
    bool HasPerkEntry();
    bool HasApplicablePerkEntry();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(InventoryStackRecord) == 0xC);

#include "../../include/ExtraDataList.h"

// No canonical header yet: API-only stub for the one flag this unit reads.
class TESBipedModelForm
{
  public:
    unsigned int pad[2];
    unsigned char flags;
    bool GetIsHeavyArmor() const;
};
float TruncateToInt(float);
#endif
