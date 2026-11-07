
// src/fallout_shared/bsclonepool.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bsclonepool.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/AutoMemHelper.h"

struct S_004b0aa0_Found;
struct S_004b0aa0_Cur
{
    bool FUN_008256d0();
    S_004b0aa0_Found** FUN_006815c0();
    S_004b0aa0_Cur* FUN_00726070();
};
struct S_004b0aa0_Sub
{
    bool BSSimpleList_NiRefObjectPtr_IsEmpty();
    void PopHead();
};
struct S_004b0aa0_Found
{
    int key;
    S_004b0aa0_Sub sub;
    void* BSClonePools_ClonePool_Destroy(int flag);
};
struct S_004b0aa0_Self : S_004b0aa0_Cur
{
    void RemoveMatchingItem(S_004b0aa0_Found** pp);
    void ProcessKeyedEntry(int key, unsigned count);
};
// @fnv 0x004b0aa0
void S_004b0aa0_Self::ProcessKeyedEntry(int key, unsigned count)
{
    if (!key)
        return;
    {
        S_004b0aa0_Found* found = 0;
        S_004b0aa0_Cur* cur = this;
        while (cur && !found && !cur->FUN_008256d0())
        {
            S_004b0aa0_Found* pEntry = *cur->FUN_006815c0();
            if (pEntry && pEntry->key == key)
                found = pEntry;
            cur = cur->FUN_00726070();
        }
        if (found)
        {
            unsigned uiStep;
            for (uiStep = 0; uiStep < count && !found->sub.BSSimpleList_NiRefObjectPtr_IsEmpty(); uiStep++)
                found->sub.PopHead();
            if (found->sub.BSSimpleList_NiRefObjectPtr_IsEmpty())
            {
                RemoveMatchingItem(&found);
                S_004b0aa0_Found* pFoundCopy = found;
                S_004b0aa0_Found* p3 = pFoundCopy;
                (void)(p3 ? p3->BSClonePools_ClonePool_Destroy(1) : 0);
            }
        }
    }
}

struct SpawnedObject
{
    bool FUN_008256d0();
    unsigned int* FUN_006815c0();
    unsigned int FUN_00726070();
    bool BSSimpleList_NiRefObjectPtr_IsEmpty();
    unsigned int Modelloader_GetReferencedThis();
};

class FUN_004b0ba0_cls
{
  public:
    unsigned int BSClonePools_RequestClone(unsigned int arg);
};

// @fnv 0x004b0ba0
// src: COMMUNITY 0x004b0ba0
unsigned int FUN_004b0ba0_cls::BSClonePools_RequestClone(unsigned int arg)
{
    unsigned int result2;
    unsigned int found8 = 0;
    unsigned int cur = (unsigned int)this;
    while (cur != 0 && found8 == 0 && !((SpawnedObject*)cur)->FUN_008256d0())
    {
        unsigned int tmp = *((SpawnedObject*)cur)->FUN_006815c0();
        if (tmp != 0 && *(unsigned int*)tmp == arg)
            found8 = tmp;
        cur = ((SpawnedObject*)cur)->FUN_00726070();
    }

    result2 = 0;
    if (found8 != 0)
    {
        unsigned int p3 = found8 + 4;
        while (result2 == 0 && p3 != 0 && !((SpawnedObject*)p3)->BSSimpleList_NiRefObjectPtr_IsEmpty())
        {
            unsigned int r = ((SpawnedObject*)((SpawnedObject*)p3)->FUN_006815c0())->Modelloader_GetReferencedThis();
            if (r != 0 && ((SpawnedObject*)r)->FUN_00726070() == 1)
                result2 = r;
            p3 = ((SpawnedObject*)p3)->FUN_00726070();
        }
    }
    return result2;
}

struct B0C80List
{
    B0C80List();
    ~B0C80List();

    void Init();

    int unk00;
    int unk04;
    int unk08;
};

struct FUN_004b0c80
{
    FUN_004b0c80();

    int m_iArrayLength;
    B0C80List m_kList;
};

// @fnv 0x004b0c80
FUN_004b0c80::FUN_004b0c80()
{
    m_iArrayLength = 0;
    m_kList.Init();
}

extern const char DAT_0101fca0[];

struct FUN_004ad270
{
    ~FUN_004ad270();
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
};

struct FUN_004ad050 : public FUN_004ad270
{
    FUN_004ad050(float fValue);
};

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int iObject);
    ~GlobalObject_00633c90();
    int m_pObject;
};

struct List4b0910_Ptrs
{
    void BSSimpleList_NiPointer_bhkAction_AddHead(const GlobalObject_00633c90& kItem);
    int m_pInventoryEntryData;
    List4b0910_Ptrs* m_pNext;
};

struct Key4b0910
{
    int FUN_00a5d2c0(FUN_004ad050* pkArg);
};

struct Entry4b0910
{
    Key4b0910* m_pkKey;
    List4b0910_Ptrs m_kList;
};

struct List4b0910
{
    bool FUN_008256d0();
    Entry4b0910** FUN_006815c0();
    List4b0910* FUN_00726070();
    void FUN_005ae3d0(Entry4b0910** ppkEntry);
    Entry4b0910* m_pkItem;
    List4b0910* m_pkNext;
};

namespace n4b0910 {
struct FUN_004b0c80
{
    FUN_004b0c80();
    Key4b0910* m_pkKey;
    List4b0910_Ptrs m_kList;
};
}

struct FUN_004b0910_cls : public List4b0910
{
    void AddKeyedItems(Key4b0910* pkKey, unsigned int ItemUpdateArray);
};

// @fnv 0x004b0910
void FUN_004b0910_cls::AddKeyedItems(Key4b0910* pkKey, unsigned int ItemUpdateArray)
{
    if (!pkKey)
        return;

    AutoMemHelper kMemVal(0x31, true, DAT_0101fca0, 0x38);
    Entry4b0910* pkFound4 = 0;
    List4b0910* pkIter = this;
    while (pkIter && !pkFound4 && !pkIter->FUN_008256d0())
    {
        Entry4b0910* pkEntry = *pkIter->FUN_006815c0();
        if (pkEntry && pkEntry->m_pkKey == pkKey)
            pkFound4 = pkEntry;
        pkIter = pkIter->FUN_00726070();
    }

    if (!pkFound4)
    {
        pkFound4 = (Entry4b0910*)new n4b0910::FUN_004b0c80;
        pkFound4->m_pkKey = pkKey;
        FUN_005ae3d0(&pkFound4);
    }

    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        FUN_004ad050 kArgTmp(1.0f);
        int iObject2 = pkKey->FUN_00a5d2c0(&kArgTmp);
        pkFound4->m_kList.BSSimpleList_NiPointer_bhkAction_AddHead(iObject2);
    }
}
