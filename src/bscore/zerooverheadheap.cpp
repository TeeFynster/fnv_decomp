// bscore/zerooverheadheap.cpp: ZeroOverheadHeap (5 functions)

#include "ZeroOverheadHeap.h"

// @fnv 0x00aa7530
void* ZeroOverheadHeap::Allocate(unsigned int size, unsigned int alignment)
{
    if (!m_pPoolBase)
        return 0;

    struct
    {
        void* reserved1;
        void* reserved2;
        void* allocation;
    } local;
    RecursiveSpinLock* pLock;
    local.allocation = 0;
    if (static_cast<char*>(m_pCurrent) + size + sizeof(unsigned int) < static_cast<char*>(m_pPoolBase) + iSize)
    {
        lock.Lock(0);
        *static_cast<unsigned int*>(m_pCurrent) = size;
        local.allocation = static_cast<char*>(m_pCurrent) + sizeof(unsigned int);
        m_pCurrent = static_cast<char*>(local.allocation) + size;
        ++m_iAllocationCount;
        pLock = &lock;
        --pLock->m_uiRecursionCount;
        if (pLock->m_uiRecursionCount == 0)
            pLock->m_uiOwningThreadID = 0;
    }
    return local.allocation;
}

// @fnv 0x00aa75e0
void ZeroOverheadHeap::Deallocate(void* pointer, unsigned int alignment)
{}

// @fnv 0x00aa75f0
bool ZeroOverheadHeap::ContainsBlockImpl(const void* pointer)
{
    return static_cast<const char*>(pointer) > static_cast<const char*>(m_pPoolBase) &&
           static_cast<const char*>(pointer) < static_cast<const char*>(m_pPoolBase) + iSize;
}

struct MemoryHeapStats
{
    const char* m_pHeapName;
    unsigned int m_uiMaximumHeapSize;
    unsigned int m_uiHeapCommitted;
    int m_iAllocatedToBlocks;
    int m_iFreeBlockCount;
    int m_uiFreeBlockCount;
    int m_iFreeInBlocks;
    int m_iUsedInBlocks;
    int m_iSmallestFreeBlock;
    int m_iLargestFreeBlock;
    int m_iHeapOverhead;
    int m_iFreeListOverhead;
    int m_iBlockOverhead;
    int m_iTotalFree;
};
struct FUN_00aa7630_t
{
    virtual void v0();
    virtual const char* GetName();
    unsigned int iSize;
    const char* pName;
    void* m_pPoolBase;
    void* m_pCurrent;
    int m_iAllocationCount;
    void ZeroOverheadHeap_GetHeapStats(MemoryHeapStats* apStats, bool abFullBlockInfo);
};
// @fnv 0x00aa7630
// src: XBOX_PDB 0x00aa7630
void FUN_00aa7630_t::ZeroOverheadHeap_GetHeapStats(MemoryHeapStats* apStats, bool abFullBlockInfo)
{
    if (!apStats)
        return;
    apStats->m_pHeapName = GetName();
    apStats->m_uiMaximumHeapSize = iSize;
    apStats->m_uiHeapCommitted = iSize;
    apStats->m_iAllocatedToBlocks = (int)m_pCurrent - (int)m_pPoolBase;
    apStats->m_iFreeBlockCount = m_iAllocationCount;
    apStats->m_uiFreeBlockCount = 0;
    apStats->m_iFreeInBlocks = 0;
    apStats->m_iUsedInBlocks = (int)m_pCurrent - (int)m_pPoolBase;
    apStats->m_iSmallestFreeBlock = 0;
    apStats->m_iLargestFreeBlock = 0;
    apStats->m_iHeapOverhead = 0x40;
    apStats->m_iFreeListOverhead = 0;
    apStats->m_iBlockOverhead = m_iAllocationCount << 2;
    apStats->m_iTotalFree = 0;
}

struct Reader
{
    virtual void v0();
    virtual void v1();
    virtual int Read(void* buf, int size);
};
struct FUN_00aa7700_t
{
    int ReadInt(Reader* reader);
};
// Returns 0 if reader is null, otherwise reads a 4-byte int through reader->Read and returns its result.
// @fnv 0x00aa7700
int FUN_00aa7700_t::ReadInt(Reader* reader)
{
    if (!reader)
        return 0;
    int value = 0;
    return reader->Read(&value, 4);
}
