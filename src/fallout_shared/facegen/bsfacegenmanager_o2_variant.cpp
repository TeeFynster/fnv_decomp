
// src/fallout_shared/facegen/bsfacegenmanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/facegen/bsfacegenmanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../include/BSFaceGenMorphData.h"
#include "../../../include/NiAdditionalGeometryData.h"
#include "../../../include/RecursiveSpinLock.h"


struct S00a67410
{
    char _pad0[0x20];
    void* m_pDefaultData;  // +0x20
    char _pad24[0xc];
    NiAdditionalGeometryData* m_pAdditionalData;  // +0x30 (vtable slot 0x8c = IsPacked, 0x00a72720 = its stream query)
    char _pad34[6];
    unsigned char m_bModifierActive;  // +0x3a

    void NiGeometryData_GetVerticesIterator(BSFaceGenMorphData::Buffers* outData);
};

// @fnv 0x00a67410
// src: COMMUNITY 0x00a67410
void S00a67410::NiGeometryData_GetVerticesIterator(BSFaceGenMorphData::Buffers* outData)
{
    if (!m_bModifierActive)
        return;

    NiAdditionalGeometryData* model = m_pAdditionalData;
    void* vars[6];
    vars[1] = 0;
    vars[3] = 0;
    vars[0] = 0;

    if (model && model->IsPacked())
    {
        vars[2] = 0;
        model->NiAdditionalGeometryData_GetDataStream(0, reinterpret_cast<char**>(&vars[0]), &vars[5], reinterpret_cast<unsigned short*>(&vars[3]),
                            reinterpret_cast<int*>(&vars[4]), reinterpret_cast<int*>(&vars[2]), reinterpret_cast<int*>(&vars[1]));
    }

    void* data;
    unsigned int size;
    if (!vars[0])
    {
        data = m_pDefaultData;
        size = 12;
    }
    else
    {
        data = vars[0];
        size = (unsigned int)vars[1];
    }

    outData->vertices = data;
    outData->normals = reinterpret_cast<void*>(size);
    *reinterpret_cast<unsigned char*>(&outData->tangents) = 0;
}

extern RecursiveSpinLock g_011c5f80;  // the pool allocator's lock (recursion count at 0x011c5f84)

template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* next;
        LinkedListEntry* prev;
        void* data;
    };

    static LinkedListEntry* ms_pFreeList;
};

struct FUN_00a68e30_shell
{
    char m_auiShapeKeys[0xb8];
    PoolAllocatorBase<unsigned int>::LinkedListEntry* m_pkHead;
    PoolAllocatorBase<unsigned int>::LinkedListEntry* m_pkTail;
    unsigned int m_uiCount;

    void NiDynamicEffect_DetachAllUnaffectedNodes();
};

// @fnv 0x00a68e30
// src: XBOX_PDB 0x00a68e30
void FUN_00a68e30_shell::NiDynamicEffect_DetachAllUnaffectedNodes()
{
    while (m_uiCount)
    {
        PoolAllocatorBase<unsigned int>::LinkedListEntry* node = m_pkHead;
        m_pkHead = node->next;
        if (m_pkHead)
            m_pkHead->prev = 0;
        else
            m_pkTail = 0;

        node->data = 0;
        g_011c5f80.Lock(0);
        node->prev = 0;
        node->next = PoolAllocatorBase<unsigned int>::ms_pFreeList;
        PoolAllocatorBase<unsigned int>::ms_pFreeList = node;
        g_011c5f80.Unlock();

        --m_uiCount;
    }
}

struct A72720Buffer
{
    int unk00;
    unsigned int m_uiSize;
    char* m_pcData;
};

struct A72720Record
{
    int unk00;
    void* m_pvStream;
    int m_iArrayCapacity;
    int m_iFormat;
    int m_iUsage;
    unsigned int m_uiBuffer;
    unsigned int m_uiValueBeforeCount;
};

class A72720StreamSet
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usVertexCount;
    unsigned short unk0E;
    unsigned int m_uiRecordCount;
    A72720Record* m_pkRecords;
    int unk18;
    int unk1C;
    A72720Buffer** m_ppkBuffers;
    unsigned short unk24;
    unsigned short m_usBufferCount;

    bool NiAdditionalGeometryData_GetDataStream(unsigned int uiIndex, char** ppcData, void** ppvStream, unsigned short* pusVertexCount,
                      int* piFormat, int* piStride, int* piUsage);
};

// @fnv 0x00a72720
// src: COMMUNITY 0x00a72720
bool A72720StreamSet::NiAdditionalGeometryData_GetDataStream(unsigned int uiIndex, char** ppcData, void** ppvStream,
                                   unsigned short* pusVertexCount, int* piFormat, int* piStride, int* piUsage)
{
    if (uiIndex >= m_uiRecordCount)
        return false;
    if (!m_pkRecords)
        return false;

    A72720Record& kRecord = m_pkRecords[uiIndex];
    void* pvStream = kRecord.m_pvStream;
    *ppvStream = pvStream;
    if (!pvStream)
        return false;

    *pusVertexCount = m_usVertexCount;
    *piFormat = kRecord.m_iFormat;
    *piStride = kRecord.m_iArrayCapacity;
    *piUsage = kRecord.m_iUsage;

    if (kRecord.m_uiBuffer > m_usBufferCount)
        return false;
    A72720Buffer* pkBuffer = m_ppkBuffers[kRecord.m_uiBuffer];
    if (!pkBuffer || pkBuffer->m_uiSize < kRecord.m_uiValueBeforeCount)
        return false;

    *ppcData = pkBuffer->m_pcData + kRecord.m_uiValueBeforeCount;
    return true;
}
