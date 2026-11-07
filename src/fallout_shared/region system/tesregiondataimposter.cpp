// fallout_shared/region system/tesregiondataimposter.cpp: Callees, ParamCls, TESRegionDataImposter (11 functions)

#include "tesregiondataimposter_decls.h"
#include "../../../include/TESRegionDataImposter.h"

// Exe 0x004f2390 tests membership via 0x005f65d0, then appends via 0x00905820 if absent.
// @fnv 0x004f2390
bool TESRegionDataImposter::AddImposter(TESObjectREFR* ref)
{
    if (!((BSSimpleList<TESForm*>*)((TESTopicInfoData*)this)->GetLinkToList())
             ->IsInList(reinterpret_cast<TESForm*&>(ref)))
    {
        ((BSSimpleList<QuantityData*>*)&imposters)->AddTail(reinterpret_cast<QuantityData*&>(ref));
        return true;
    }
    return false;
}

// @fnv 0x004f2190
bool TESRegionDataImposter::ReadRegionData(TESFile* file)
{
    if (!file)
        return false;
    switch (file->GetChunkID())
    {
    case 0x44494452: {
        unsigned int uiChunkSize = file->GetChunkSize();
        struct ImposterArrayCounts
        {
            unsigned int formIDSize;
            unsigned int count;
        } loadCounts;
        loadCounts.formIDSize = sizeof(unsigned int);
        loadCounts.count = uiChunkSize / loadCounts.formIDSize;
        unsigned int* formIDs = new unsigned int[loadCounts.count];
        file->GetChunkData(formIDs, uiChunkSize);
        for (unsigned int i = 0; i < loadCounts.count; i++)
        {
            unsigned int formID = formIDs[i];
            if (file->IsEndianConversionRequired())
                BSEndian(&formID, EndianSizeTag<4>());
            AddImposter(reinterpret_cast<TESObjectREFR*>(formID));
        }
        delete[] formIDs;
        break;
    }
    default:
        return false;
    }
    return true;
}

// Walks the imposter's reference list, resolving each stored form ID to a TESObjectREFR and removing entries that fail to resolve.
// @fnv 0x004f2290
void TESRegionDataImposter::InitItem(TESForm* form)
{
    struct ImposterResolution
    {
        TESObjectREFR* reference;
        unsigned int formID;
    } entry;
    entry.reference = 0;
    BSSimpleList<TESObjectREFR*>* pList = (BSSimpleList<TESObjectREFR*>*)((TESTopicInfoData*)this)->GetLinkToList();
    while (pList)
    {
        if (pList->GetItem())
        {
            entry.formID = reinterpret_cast<unsigned int>(pList->GetItem());
            TESFile* file = form ? form->GetFile(-1) : 0;
            TESForm::RemapFormIDForFile(entry.formID, file);
            entry.reference = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(entry.formID));
            pList->SetItem(entry.reference);
        }
        if (!entry.reference)
        {
            pList->RemoveHead();
            if (!pList->GetItem())
                break;
        }
        else
        {
            pList = pList->GetNext();
        }
    }
}

struct List_009e03e0
{
    void RemoveAll();
};

// @fnv 0x004f2370
bool TESRegionDataImposter::ClearList()
{
    ((List_009e03e0*)((TESTopicInfoData*)this)->GetLinkToList())->RemoveAll();
    return true;
}

// @fnv 0x004f2450
void TESRegionDataImposter::SetFromData(const TESRegionData* apRegionData, unsigned int aiTotalBlending)
{
    TESRegionDataImposter* pdataIn = (TESRegionDataImposter*)apRegionData;
    if (apRegionData != 0)
        const_cast<TESRegionData*>(apRegionData)->GetType();
}

// Allocates a copy of this region data.
// @fnv 0x004f23d0
TESRegionData* TESRegionDataImposter::Clone()
{
    TESRegionDataImposter* pdata = new TESRegionDataImposter(this);
    return pdata;
}

// @fnv 0x004f2040
TESRegionDataImposter::~TESRegionDataImposter()
{
    ClearList();
}

void __cdecl TESForm_AddChunkArray_00485710(unsigned int, unsigned int*, unsigned int);
struct FUN_004f20b0_elem
{
    unsigned int Probe();
};
struct FUN_004f20b0_node
{
    FUN_004f20b0_elem** GetItem();
    FUN_004f20b0_node* GetNext();
    int GetSize();
    FUN_004f20b0_elem* item;
    FUN_004f20b0_node* next;
};
// @fnv 0x004f20b0
void TESRegionDataImposter::Save()
{
    TESRegionData::Save();
    FUN_004f20b0_elem* pElem = 0;
    int count = ((FUN_004f20b0_node*)&imposters)->GetSize();
    if (count)
    {
        FUN_004f20b0_node* pNode = (FUN_004f20b0_node*)&imposters;
        unsigned int* pProbes = new unsigned int[count];
        for (unsigned int iIndex = 0; pNode && iIndex < (unsigned int)count; iIndex++)
        {
            pElem = *pNode->GetItem();
            unsigned int v2 = pElem->Probe();
            pProbes[iIndex] = v2;
            pNode = pNode->GetNext();
        }
        TESForm_AddChunkArray_00485710(0x44494452, pProbes, count);
        delete pProbes;
    }
}

struct ContNode;
ContNode* __fastcall FUN_00726070(ContNode*);
struct Item4f11
{
    bool TESRegionPointList_Validate(int);
};
struct Node4f11
{
    Item4f11** FUN_006815c0();
};
struct Head4f11
{
    bool CheckAllActionStates();
};

class Obj4f11
{
  public:
    char _pad[0x18];
    Head4f11* m_pHead;
    ContNode* m_pNext;
    bool TESRegion_Validate();
};

// Returns false if m_pNext or m_pHead is null, m_pHead->FUN_004f3610() fails, or any node's item fails FUN_004f81e0(1); otherwise true.
// @fnv 0x004f11e0
// src: XBOX_PDB 0x004f11e0
bool Obj4f11::TESRegion_Validate()
{
    ContNode* pNode = m_pNext;
    if (!m_pNext || !m_pHead)
        return false;
    if (!m_pHead->CheckAllActionStates())
        return false;
    while (pNode && *((Node4f11*)pNode)->FUN_006815c0())
    {
        if (!(*((Node4f11*)pNode)->FUN_006815c0())->TESRegionPointList_Validate(1))
            return false;
        pNode = FUN_00726070(pNode);
    }
    return true;
}

struct Callees
{
    void FUN_0096a2d0();
    void* FUN_00413f40();
    void FUN_00470470();
    void* FUN_006815c0();
    void FUN_00905820(void* item);
    void* FUN_00726070();
};

void Callees::FUN_0096a2d0()
{}
void* Callees::FUN_00413f40()
{
    return 0;
}
void Callees::FUN_00470470()
{}
void* Callees::FUN_006815c0()
{
    return 0;
}
void Callees::FUN_00905820(void* /*item*/)
{}
void* Callees::FUN_00726070()
{
    return 0;
}

// Calls FUN_00470470 on the result of this->FUN_00413f40(); if param's GetType() is 8, traverses its list and passes each node's item to imposters.
// @fnv 0x004f1f70
TESRegionDataImposter::TESRegionDataImposter(const TESRegionDataImposter* param) : TESRegionData(*param)
{
    ((Callees*)((Callees*)this)->FUN_00413f40())->FUN_00470470();

    const void* refr = param;
    if (((TESRegionData*)refr)->GetType() == 8)
    {
        void* node = ((Callees*)refr)->FUN_00413f40();
        while (node != 0)
        {
            ((Callees*)&imposters)->FUN_00905820(((Callees*)node)->FUN_006815c0());
            node = ((Callees*)node)->FUN_00726070();
        }
    }
}
