#pragma once

#include "IMemoryHeap.h"

class MemoryBlockHeader;
class HeapFreeBlock;

class HeapFreeList
{
public:
    HeapFreeBlock* pHead;
    HeapFreeBlock* pTail;
};

class HeapBlockList
{
public:
    int iCount;
    HeapFreeList* pFirst;
};

class AbstractHeap : public IMemoryHeap
{
public:
    virtual ~AbstractHeap();
    virtual const char* GetName();
    virtual void* Allocate(unsigned int size, unsigned int alignment);
    virtual void Deallocate(void* pointer, unsigned int alignment);
    virtual bool ContainsBlockImpl(const void* pointer);
    virtual void CheckHeapIntegrity();
    virtual void GetHeapStats(MemoryHeapStats* stats, bool full);
    virtual int OutputBucketInfo(IMemoryManagerFile* file);
    virtual int OutputBlockInfo(IMemoryManagerFile* file, bool full);
    virtual unsigned int Size(const void* pointer, unsigned int alignment);
    virtual void vf10();
    virtual void vf11();
    virtual void* AllocateHeapMemory(unsigned int size, unsigned int alignment);
    virtual void FreeHeapMemory(void* pointer);
    virtual unsigned int CreateMorePages(void* pointer, unsigned int size, unsigned int alignment);
    virtual unsigned int CleanExtraPages(void* pointer, unsigned int size, unsigned int alignment);
    virtual void DecommitPages(HeapFreeBlock* block);
    virtual void CommitPages(HeapFreeBlock* block, unsigned int size);

    union
    {
        const char* pName;
        MemoryBlockHeader* m_pLastBlock;
    };
    union
    {
        int iDefaultAlignment;
        MemoryBlockHeader* m_pFirstBlock;
    };
    union
    {
        unsigned int MinFreeBlockSize;
        int m_iFreeBlockCount;
    };
    unsigned int iPageSize;
    unsigned int MemHeapSize;
    unsigned int iInitialSize;
    unsigned int iCurrentSize;
    unsigned int iWastedMemory;
    int iMemAllocated;
    int iMemAllocatedHigh;
    int iBlockMemAllocated;
    char* pMemHeap;
    int iNumBlocks;
    MemoryBlockHeader* pBlockHead;
    MemoryBlockHeader* pBlockTail;
    int iNumFreeBlocks;
    HeapFreeList pSmallFreeList[1024];
    HeapFreeList* pLastSmallList;
    HeapFreeList LargeFreeList;
    MemoryBlockHeader** pDelayedFreeBlocksA;
    unsigned int iNextDelayedFreeIndex;
    HeapBlockList pSubBuckets[16];
    unsigned char CriticalSectionO[24];

    unsigned int TotalSize(const void* pointer);
    void ResetHeap();
    __forceinline HeapFreeList* GetFreeList(unsigned int size)
    {
        int bucket = size / iDefaultAlignment - 1;
        return bucket >= 1024 ? &LargeFreeList : &pSmallFreeList[bucket];
    }
    __forceinline int GetSubBucket(int size)
    {
        if (size > 4096)
            return -1;
        return (size / iDefaultAlignment - 1) / 64;
    }
    __forceinline bool IsLastInSubBucket(int bucket, HeapFreeList* list)
    {
        return bucket < 16 ? list >= pSubBuckets[bucket + 1].pFirst : list >= pLastSmallList;
    }
    void* BaseAllocate(unsigned int size);
    void BaseFree(void* pointer);
    void RemoveBlockFromFreeList(HeapFreeBlock* block);
    void PushBlock(MemoryBlockHeader* block);
    void AddBlockToFreeList(HeapFreeBlock* block);
    void RemoveBlockFromFreeList_00aa9e50(HeapFreeList* list, HeapFreeBlock* block);
    void IncrementSubBucket(int size);
    void DecrementSubBucket(int size);
    void RebuildFreeLists();
    void InsertFreeBlock(HeapFreeBlock* block);
    void CoalesceFreeBlocks(HeapFreeBlock* first, HeapFreeBlock* second);
    void Clear();
    void AppendBlock(MemoryBlockHeader* block);
};
