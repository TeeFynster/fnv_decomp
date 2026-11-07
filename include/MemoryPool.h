#pragma once

#include "RecursiveSpinLock.h"

class MemoryPool__FreePoolBlock;

class MemoryPool
{
public:
    const char* pDescription;
    char* m_pPoolBase;
    MemoryPool__FreePoolBlock* m_pFreeBlockHead;
    unsigned int layoutPaddingC[5];
    RecursiveSpinLock m_kCriticalSection;
    unsigned int m_uiAllocationSize;
    unsigned int m_uiPeakPageCount;
    unsigned short* m_pPageBlockCounts;
    unsigned int m_uiPageCount;
    unsigned int m_uiPoolSize;
    unsigned int m_uiFreeBlockCount;
    unsigned int m_uiAllocatedPageCount;
    unsigned int layoutPadding5C[9];

    MemoryPool(unsigned int blockSize, unsigned int poolSize, const char* description);
    ~MemoryPool();

    bool IsHeapValid();
    bool PointerInPool(const void* pointer);
    unsigned int GetBlockSize();
    void PushFreeBlock(void* pointer);
    void Free(void* pointer);
    bool CommitPage(unsigned int pageIndex, char*& page);
    void __thiscall RegisterInPool(unsigned int index);
    void __thiscall ClearPoolSlot(unsigned int uiIndex);
    void BSSpinLock_Lock(char* name);
    void MemoryPool_SortFreeBlockList();
    void MemoryPool_CheckFreeBlocks();

    enum
    {
        kAddressRegionCount = 256
    };
    static MemoryPool* ms_pPoolAddressMap[kAddressRegionCount];
};
