
// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

void __cdecl hkAlgorithm_quickSortRecursive_hknpCollisionResult_hkAlgorithm_less_hknpCollisionResult(void* owner, int a2, int a3, int a4);

class FUN_00c855f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_10;
    int m_14;

    void hknpAllHitsCollector_sortHits();
};

// If m_14 exceeds 1, calls FUN_00c852c0 on m_10 with 0 and m_14 - 1.
// @fnv 0x00c855f0
// src: COMMUNITY 0x00c855f0
void FUN_00c855f0_cls::hknpAllHitsCollector_sortHits()
{
    union
    {
        volatile unsigned char b;
        int i;
    } flag;
    flag.b = 0;
    if (m_14 > 1)
    {
        hkAlgorithm_quickSortRecursive_hknpCollisionResult_hkAlgorithm_less_hknpCollisionResult(m_10, 0, m_14 - 1, flag.i);
    }
}

#include <xmmintrin.h>

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(hkMemoryAllocator* apAllocator, void* apContainer, unsigned int auiElemSize);
void __cdecl CollectValuesReversed(void* apDst, unsigned int auiSize, void* apOwner);

struct ChainNode
{
    int unk00;
    int unk04;
    int unk08;
    ChainNode* m_pNext;
};

struct ChainOwner
{
    int unk00;
    int unk04;
    int unk08;
    ChainNode* m_pHead;
};

struct SourceEntry
{
    __m128 m_v0;
    float m_f10;
    int m_i14;
    int m_i18;
    int m_i1C;
};

struct SpawnedEntry
{
    __m128 m_v0;
    float m_f10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    ChainNode* m_pReferencedNode;
    int m_i54;
    int m_i58;
    int m_i5C;
};

struct EntryListNode
{
    SpawnedEntry* m_pData;
    unsigned int m_uCount;
    unsigned int m_uCapFlags;
};

struct FUN_00c85520_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryListNode m_kNode;

    void AddEntry(ChainOwner* apOwner, SourceEntry* apSource);
};

// Grows the SpawnedEntry list if full, appends a new entry copying fields from apSource, and links it to the last ChainNode in apOwner.
// @fnv 0x00c85520
void FUN_00c85520_cls::AddEntry(ChainOwner* apOwner, SourceEntry* apSource)
{
    EntryListNode* pList = &m_kNode;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    if (pList->m_uCount == (pList->m_uCapFlags & 0x3fffffffu))
    {
        ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap), pList, sizeof(SpawnedEntry));
    }

    SpawnedEntry* pNew = pList->m_pData + pList->m_uCount;
    if (pNew != 0)
    {
        pNew->m_f10 = 1.0f;
        pNew->m_i14 = -1;
        pNew->m_i40 = 0;
        pNew->m_i20 = -1;
        pNew->m_pReferencedNode = 0;
    }

    SpawnedEntry* pDst = pList->m_pData + pList->m_uCount;
    pList->m_uCount++;

    pDst->m_v0 = apSource->m_v0;
    pDst->m_f10 = apSource->m_f10;
    pDst->m_i14 = apSource->m_i14;
    pDst->m_i18 = apSource->m_i18;
    pDst->m_i1C = apSource->m_i1C;
    CollectValuesReversed(&pDst->m_i20, 8, apOwner);

    ChainNode* pLast = (ChainNode*)apOwner;
    while (pLast->m_pNext != 0)
    {
        pLast = pLast->m_pNext;
    }
    pDst->m_pReferencedNode = pLast;
}
