// bscore/abstractheap.cpp: AbstractHeap and heap diagnostics (19 functions)

#include "../../include/AbstractHeap.h"
#include "abstractheap_decls.h"
#include "../../include/IMemoryManagerFile.h"
#include "../../include/MemoryManager.h"

// Helpers absent from the shared API; inherit the shared layout without copying it.
struct AbstractHeapDiagnostics : AbstractHeap
{
    int CountLinkedNodes(int node);
    AbstractHeap* DestroyIfFlagged(unsigned int flags);
    void CheckFreeBlock(HeapFreeBlock* block);
    void LogFreeBlockStats(unsigned int blockSize, HeapFreeList* list);
};

__forceinline void AddHeapFreeBlock(HeapFreeList* list, HeapFreeBlock* block)
{
    if (list->pTail)
    {
        HeapFreeBlock* tail = list->pTail;
        block->m_pNextFree = tail;
        HeapFreeBlock* previous = tail->m_pPrevFree;
        block->m_pPrevFree = previous;
        if (previous)
            previous->m_pNextFree = block;
        tail->m_pPrevFree = block;
        list->pTail = block;
    }
    else
    {
        list->pHead = block;
        list->pTail = block;
    }
}

// @fnv 0x00aa9bd0
void AbstractHeap::InsertFreeBlock(HeapFreeBlock* freeBlock)
{
    HeapFreeBlock* block = freeBlock;
    if (block)
    {
        for (;;)
        {
            HeapFreeBlock* previous = (HeapFreeBlock*)block->GetPrevious();
            if (previous && previous->IsFree())
            {
                CoalesceFreeBlocks(previous, block);
                block = previous;
            }
            else
            {
                break;
            }
        }
    }
    if (block)
    {
        while (block != pBlockTail && block->GetNext()->IsFree())
        {
            CoalesceFreeBlocks(block, (HeapFreeBlock*)block->GetNext());
        }
    }
    RebuildFreeLists();
}

// @fnv 0x00aa8f50
void* AbstractHeap::BaseAllocate(unsigned int size)
{
    fnv_EnterCriticalSection(&CriticalSectionO);
    if (size <= 8)
        size = 8;
    else
        size = (size + iDefaultAlignment - 1) & ~(iDefaultAlignment - 1);
    unsigned int uiBlockSize;
    void* pMemory = 0;
    HeapFreeList* pSizeClassFreeList = GetFreeList(size);
    if (!pSizeClassFreeList->pTail && pSizeClassFreeList != &LargeFreeList)
    {
        pSizeClassFreeList += MinFreeBlockSize / iDefaultAlignment;
        if (pSizeClassFreeList > pLastSmallList)
        {
            pSizeClassFreeList = &LargeFreeList;
        }
        else
        {
            int iSubBucketIndex = 0;
            int iFirstBucket = GetSubBucket(size + MinFreeBlockSize);
            for (iSubBucketIndex = iFirstBucket; iSubBucketIndex < 16 && !pSizeClassFreeList->pTail; ++iSubBucketIndex)
            {
                if (pSubBuckets[iSubBucketIndex].iCount)
                {
                    if (pSubBuckets[iSubBucketIndex].pFirst > pSizeClassFreeList)
                        pSizeClassFreeList = pSubBuckets[iSubBucketIndex].pFirst;
                    while (!pSizeClassFreeList->pTail && !IsLastInSubBucket(iSubBucketIndex, pSizeClassFreeList))
                        ++pSizeClassFreeList;
                }
            }
            if (iSubBucketIndex == 16)
                pSizeClassFreeList = &LargeFreeList;
        }
    }
    if (pSizeClassFreeList->pTail)
    {
        HeapFreeBlock* pBlock = pSizeClassFreeList->pHead;
        while (pBlock)
        {
            uiBlockSize = pBlock->GetSize();
            int iExtra = uiBlockSize - size;
            if (iExtra == 0 || iExtra >= (int)MinFreeBlockSize)
            {
                HeapFreeBlock* pNewBlock = 0;
                bool bDecommitted = pBlock->IsDecommitted();
                RemoveBlockFromFreeList_00aa9e50(pSizeClassFreeList, pBlock);
                if (iExtra)
                {
                    if (bDecommitted)
                    {
                        unsigned int iCommitSize = size + 24;
                        bool bCommitted = VirtualAlloc(pBlock, iCommitSize, 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            AddBlockToFreeList(pBlock);
                            fnv_LeaveCriticalSection(&CriticalSectionO);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                        char szMessage[256];
                        sprintf_s(szMessage, 256, "Committing Entire Free Block: %08X, %08X\r\n", pBlock, iCommitSize);
                        if (AbstractHeapHasLog())
                        {
                            AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                        }
                    }
                    pNewBlock = (HeapFreeBlock*)((char*)pBlock + size + sizeof(MemoryBlockHeader));
                    unsigned int iRemainingSize = uiBlockSize - (size + sizeof(MemoryBlockHeader));
                    pNewBlock->m_pNextFree = 0;
                    pNewBlock->m_pPrevFree = 0;
                    pNewBlock->SetFlags(iRemainingSize, 0);
                    pNewBlock->SetPrevious(pBlock);
                    if (pBlock == pBlockTail)
                        pBlockTail = pNewBlock;
                    else
                    {
                        MemoryBlockHeader* pNext = pBlock->GetNext();
                        pNext->SetPrevious(pNewBlock);
                    }
                    ++iNumBlocks;
                    AddBlockToFreeList(pNewBlock);
                    InsertFreeBlock(pNewBlock);
                }
                else
                {
                    if (bDecommitted)
                    {
                        bool bCommitted = VirtualAlloc(pBlock, size + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            AddBlockToFreeList(pBlock);
                            fnv_LeaveCriticalSection(&CriticalSectionO);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                        char szMessage[256];
                        sprintf_s(szMessage, 256, "Committing perfectly matched Free Block: %08X, %08X\r\n", pBlock,
                                  size + sizeof(MemoryBlockHeader));
                        if (AbstractHeapHasLog())
                        {
                            AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                        }
                    }
                }
                pBlock->SetSize(size);
                pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
                iBlockMemAllocated += pBlock->GetTotalSize();
                break;
            }
            pBlock = pBlock->m_pPrevFree;
        }
    }
    if (!pMemory)
    {
        unsigned int uiBlockAllocationSizeItem = size + sizeof(MemoryBlockHeader);
        unsigned int iNeededSize = iMemAllocated + uiBlockAllocationSizeItem;
        if (iPageSize && iNeededSize > iCurrentSize && iNeededSize <= MemHeapSize)
            iCurrentSize += CreateMorePages(pMemHeap, iCurrentSize, uiBlockAllocationSizeItem);
        if (iNeededSize <= iCurrentSize)
        {
            MemoryBlockHeader* pBlock = (MemoryBlockHeader*)(pMemHeap + iMemAllocated);
            if (iPageSize)
            {
                bool bCommitted = VirtualAlloc(pBlock, size + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                if (!bCommitted)
                {
                    fnv_LeaveCriticalSection(&CriticalSectionO);
                    return 0;
                }
                char szMessage[256];
                sprintf_s(szMessage, 256, "Committing memory on end of heap: %08X, %08X\r\n", pBlock,
                          size + sizeof(MemoryBlockHeader));
                if (AbstractHeapHasLog())
                {
                    AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                }
            }
            pBlock->SetFlags(size, 0);
            PushBlock(pBlock);
            iMemAllocated += uiBlockAllocationSizeItem;
            if (iMemAllocated > iMemAllocatedHigh)
                iMemAllocatedHigh = iMemAllocated;
            pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
            iBlockMemAllocated += uiBlockAllocationSizeItem;
        }
    }
    fnv_LeaveCriticalSection(&CriticalSectionO);
    return pMemory;
}

// @fnv 0x00aa9a70
void AbstractHeap::RebuildFreeLists()
{
    MemoryBlockHeader* block = pBlockTail;
    while (block && block->IsFree() && block->GetNext() == (MemoryBlockHeader*)(pMemHeap + iMemAllocated))
    {
        RemoveBlockFromFreeList((HeapFreeBlock*)block);
        iMemAllocated -= block->GetTotalSize();
        --iNumBlocks;
        if (pBlockHead == pBlockTail)
        {
            pBlockTail = 0;
            pBlockHead = 0;
            break;
        }
        else
        {
            pBlockTail = block->GetPrevious();
        }
        block = pBlockTail;
    }
    if (iPageSize)
    {
        unsigned int unused = iCurrentSize - iMemAllocated;
        if (iCurrentSize - unused < iInitialSize)
            unused = iCurrentSize - iInitialSize;
        if (unused >= iPageSize)
            iCurrentSize -= CleanExtraPages(pMemHeap, iCurrentSize, unused);
    }
}

// @fnv 0x00aa9970
void AbstractHeap::CoalesceFreeBlocks(HeapFreeBlock* pFirstBlock, HeapFreeBlock* pSecondBlock)
{
    RemoveBlockFromFreeList(pFirstBlock);
    RemoveBlockFromFreeList(pSecondBlock);
    if (pSecondBlock->IsDecommitted())
        pFirstBlock->SetDecommitted(true);
    pFirstBlock->SetSize(pFirstBlock->GetSize() + pSecondBlock->GetTotalSize());
    if (pSecondBlock == pBlockTail)
        pBlockTail = pFirstBlock;
    else
        pSecondBlock->GetNext()->SetPrevious(pFirstBlock);
    --iNumBlocks;
    AddBlockToFreeList(pFirstBlock);
}

// @fnv 0x00aa98f0
void AbstractHeap::BaseFree(void* pointer)
{
    if (!pointer)
        return;
    fnv_EnterCriticalSection(&CriticalSectionO);
    HeapFreeBlock* block = (HeapFreeBlock*)((char*)pointer - sizeof(MemoryBlockHeader));
    iBlockMemAllocated -= block->GetTotalSize();
    AddBlockToFreeList(block);
    InsertFreeBlock(block);
    fnv_LeaveCriticalSection(&CriticalSectionO);
}

// Removes the given block from the free list corresponding to its size by calling FUN_00aa9e50.
// @fnv 0x00aaa660
inline void AbstractHeap::RemoveBlockFromFreeList(HeapFreeBlock* block)
{
    RemoveBlockFromFreeList_00aa9e50(GetFreeList(block->GetSize()), block);
}

// Clears the block's fields, marks it free, adds it to the free list for its size, and updates the free-block and sub-bucket counters.
// @fnv 0x00aa9d30
// src: COMMUNITY 0x00aa9d30
void AbstractHeap::AddBlockToFreeList(HeapFreeBlock* block)
{
    block->m_pPrevFree = 0;
    block->m_pNextFree = 0;
    block->SetFree(true);
    HeapFreeList* list = GetFreeList(block->GetSize());
    AddHeapFreeBlock(list, block);
    ++iNumFreeBlocks;
    IncrementSubBucket(block->GetSize());
}
// @fnv 0x00aa9e50
// src: XBOX_PDB 0x00aa9e50
void AbstractHeap::RemoveBlockFromFreeList_00aa9e50(HeapFreeList* apFreeList, HeapFreeBlock* block)
{
    HeapFreeBlock* pPrev = block->m_pPrevFree;
    HeapFreeBlock* pNext = block->m_pNextFree;
    block->RemoveFromFreeList();
    block->SetFree(false);
    if (block == apFreeList->pHead)
        apFreeList->pHead = pPrev;
    if (block == apFreeList->pTail)
        apFreeList->pTail = pNext;
    DecrementSubBucket(block->GetSize());
    --iNumFreeBlocks;
}
// Unlinks this node from the free list by patching its neighbours' free-list links, then clears the previous and next free pointers.
// @fnv 0x00aaa5e0
inline void HeapFreeBlock::RemoveFromFreeList()
{
    if (m_pNextFree)
        m_pNextFree->SetPrevFree(m_pPrevFree);
    if (m_pPrevFree)
        m_pPrevFree->SetNextFree(m_pNextFree);
    m_pPrevFree = 0;
    m_pNextFree = 0;
}
// Computes the sub-bucket index for size and, if valid, increments that bucket's iCount.
// @fnv 0x00aa9ef0
void AbstractHeap::IncrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        ++pSubBuckets[bucket].iCount;
}
// Looks up the sub-bucket for size and decrements its iCount if a bucket was found.
// @fnv 0x00aa9f50
void AbstractHeap::DecrementSubBucket(int size)
{
    int bucket = GetSubBucket(size);
    if (bucket != -1)
        --pSubBuckets[bucket].iCount;
}
// Links block into the heap's block list, setting its previous pointer and updating the head/tail and count.
// @fnv 0x00aa9ca0
void AbstractHeap::PushBlock(MemoryBlockHeader* block)
{
    if (pBlockTail)
    {
        block->SetPrevious(pBlockTail);
        pBlockTail = block;
    }
    else
    {
        pBlockHead = block;
        pBlockTail = pBlockHead;
    }
    ++iNumBlocks;
}

// Returns -1 if arg is null, otherwise counts nodes by following the pointer at offset 0x4C until it is null.
// @fnv 0x00aaa560
int AbstractHeapDiagnostics::CountLinkedNodes(int pNode)
{
    if (!pNode)
        return -1;
    int count = 0;
    while (*(int*)(pNode + 0x4C))
    {
        ++count;
        pNode = *(int*)(pNode + 0x4C);
    }
    return count;
}

extern MemoryManager g_memoryManager;
// Calls the heap destructor, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00aaa5b0
AbstractHeap* AbstractHeapDiagnostics::DestroyIfFlagged(unsigned int flags)
{
    AbstractHeap::~AbstractHeap();
    if (flags & 1)
    {
        g_memoryManager.Deallocate(this);
    }
    return this;
}

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
// @fnv 0x00aa9fb0
void AbstractHeap::CheckHeapIntegrity()
{
    HeapFreeBlock* pblock;
    MemoryBlockHeader* pfreeCur;
    int i2;
    int isub;
    EnterCriticalSection((_RTL_CRITICAL_SECTION*)CriticalSectionO);
    pblock = 0;
    for (isub = 0; isub < 16; isub++)
    {
        if (pSubBuckets[isub].iCount)
        {
            pblock = pSubBuckets[isub].pFirst->pHead;
            while (pblock)
            {
                ((AbstractHeapDiagnostics*)this)->CheckFreeBlock(pblock);
                pblock = pblock->m_pPrevFree;
            }
        }
    }
    for (i2 = 0; i2 < 0x400; i2++)
    {
        pblock = pSmallFreeList[i2].pHead;
        while (pblock)
        {
            ((AbstractHeapDiagnostics*)this)->CheckFreeBlock(pblock);
            pblock = pblock->m_pPrevFree;
        }
    }
    pblock = LargeFreeList.pHead;
    while (pblock)
    {
        ((AbstractHeapDiagnostics*)this)->CheckFreeBlock(pblock);
        pblock = pblock->m_pPrevFree;
    }
    pfreeCur = pBlockTail;
    while (pfreeCur)
    {
        pfreeCur = pfreeCur->m_pPreviousBlock;
    }
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)CriticalSectionO);
}

struct _MEMORYSTATUS
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(_MEMORYSTATUS*);

// If heap logging is enabled, logs the block size, then counts free blocks in list and reports count, largest, total and available physical memory.
// @fnv 0x00aa9760
void AbstractHeapDiagnostics::LogFreeBlockStats(unsigned int blockSize, HeapFreeList* list)
{
    if (AbstractHeapHasLog())
    {
        unsigned int numBlocks4 = 0;
        unsigned int largest = 0;
        unsigned int total = 0;
        _MEMORYSTATUS status3;
        char buffer[256];
        sprintf_s(buffer, 256, "AbstractHeap: Checking list for block size %u\n", blockSize);
        AbstractHeapLogger::Get()->vfn_14(2, buffer, 0, 0, 0);
        if (list)
        {
            MemoryBlockHeader* block = list->pHead;
            while (block)
            {
                numBlocks4++;
                unsigned int size = block->GetSize();
                total += size;
                if (size > largest)
                    largest = size;
                block = block->GetNext();
            }
        }
        GlobalMemoryStatus(&status3);
        sprintf_s(
            buffer, 256,
            "\tNumber of blocks free: %u\n\tLargest free block: %u\n\tTotal space in free blocks: %u\n\tAvailable global memory: %u\n",
            numBlocks4, largest, total, status3.dwAvailPhys);
        AbstractHeapLogger::Get()->vfn_14(2, buffer, 0, 0, 0);
    }
}

struct BucketInfo
{
    unsigned int iSize;
    int iCount;
};

// Writes the bucket count and, for each bucket size, the number of free blocks to the given file, returning the total bytes written.
// @fnv 0x00aaa310
int AbstractHeap::OutputBucketInfo(IMemoryManagerFile* file)
{
    if (!file)
        return 0;
    fnv_EnterCriticalSection(CriticalSectionO);
    BucketInfo bucketInfo;
    int numBuckets;
    int total;
    int i4;
    HeapFreeBlock* block;
    {
        HeapFreeList* list;
        total = 0;
        numBuckets = 0x401;
        total += file->Write(&numBuckets, 4);
        for (i4 = 0; i4 < numBuckets; i4++)
        {
            bucketInfo.iSize = (i4 + 1) * iDefaultAlignment;
            bucketInfo.iCount = 0;
            list = GetFreeList(bucketInfo.iSize);
            block = list->pHead;
            while (block)
            {
                bucketInfo.iCount++;
                block = block->m_pPrevFree;
            }
            total += file->Write(&bucketInfo, 8);
        }
    }
    fnv_LeaveCriticalSection(CriticalSectionO);
    return total;
}

struct HeapBlockInfo
{
    int iType;
    unsigned int iSize;
    int bFree;
    int unk0C;
    int unk10;
    int iOwner;
};

// Writes the heap block count and, when full is set, each block's size, free flag and owner to the file, returning bytes written.
// @fnv 0x00aaa430
int AbstractHeap::OutputBlockInfo(IMemoryManagerFile* file, bool full)
{
    if (!file)
        return 0;
    fnv_EnterCriticalSection(CriticalSectionO);
    int total2 = 0;
    if (full)
    {
        total2 += file->Write(&iNumBlocks, 4);
        int i;
        HeapBlockInfo info2;
        info2.iType = 8;
        MemoryBlockHeader* block7 = pBlockHead;
        for (i = 0; i < iNumBlocks; block7 = block7->GetNext(), i++)
        {
            info2.iSize = block7->GetSize();
            info2.bFree = block7->IsFree() != 0;
            info2.iOwner = -1;
            total2 += file->Write(&info2, sizeof(info2));
        }
    }
    else
    {
        int zero4 = 0;
        total2 += file->Write(&zero4, 4);
    }
    fnv_LeaveCriticalSection(CriticalSectionO);
    return total2;
}

class MemoryHeapStats
{
  public:
    const char* pName;
    unsigned int iMemHeapSize;
    unsigned int iCurrentSize;
    int iMemAllocated;
    unsigned int iNumBlocks;
    unsigned int iNumFreeBlocks;
    int iFreeSize;
    int iUsedSize;
    int iMinFreeBlock;
    int iMaxFreeBlock;
    unsigned int iHeapStructSize;
    unsigned int iFreeListBytes;
    int iBlockTableBytes;
    int iUnusedBytes;
    unsigned int m_uiTrailingStatsValue;
};

// @fnv 0x00aaa0e0
void AbstractHeap::GetHeapStats(MemoryHeapStats* stats, bool full)
{
    fnv_EnterCriticalSection(&this->CriticalSectionO);
    stats->pName = this->pName;
    stats->iMemHeapSize = this->MemHeapSize;
    stats->iCurrentSize = this->iCurrentSize;
    stats->iMemAllocated = this->iMemAllocated;
    stats->iNumBlocks = this->iNumBlocks;
    stats->iNumFreeBlocks = this->iNumFreeBlocks;
    int iZero4 = 0;
    int iBlockBytes2 = stats->iNumBlocks * iZero4;
    int iHeaderSize3 = sizeof(MemoryBlockHeader) - iZero4;
    stats->iHeapStructSize = sizeof(AbstractHeap);
    stats->iFreeListBytes = 0x2000;
    stats->iFreeListBytes += 0x80;
    stats->iBlockTableBytes = this->iNumBlocks * iHeaderSize3;
    stats->iUnusedBytes = iBlockBytes2;
    MemoryBlockHeader* aBlock = this->pBlockHead;
    stats->iFreeSize = this->iMemAllocated - this->iBlockMemAllocated;
    stats->iUsedSize = this->iBlockMemAllocated;
    stats->iMinFreeBlock = 0xfffffff;
    stats->iMaxFreeBlock = 0;
    if (full)
    {
        stats->iFreeSize = 0;
        stats->iUsedSize = 0;
        while (aBlock)
        {
            if (aBlock->IsFree())
            {
                int freeSize = aBlock->GetSize();
                stats->iFreeSize += freeSize + iHeaderSize3;
                if (freeSize < stats->iMinFreeBlock)
                    stats->iMinFreeBlock = freeSize;
                if (freeSize > stats->iMaxFreeBlock)
                    stats->iMaxFreeBlock = freeSize;
            }
            else
            {
                int usedSize_ = aBlock->GetSize();
                stats->iUsedSize += usedSize_ + iHeaderSize3;
            }
            aBlock = (aBlock == this->pBlockTail) ? 0 : aBlock->GetNext();
        }
        if (stats->iNumFreeBlocks == 0)
            stats->iMinFreeBlock = 0;
    }
    stats->m_uiTrailingStatsValue = stats->iMemHeapSize - stats->iMemAllocated + stats->iFreeSize;
    fnv_LeaveCriticalSection(&this->CriticalSectionO);
}
