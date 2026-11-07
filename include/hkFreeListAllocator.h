#pragma once

#include "hkMemoryAllocator.h"
#include "hkFreeListAllocatorServer.h"
#include "hkBool.h"

class hkFreeListNode;
class hkFreeListW;
class hkPoolBucket;
class SizeClassPool;
class StringListNode;
class HkFLA_Stats;

typedef void (__cdecl* hkMemoryWalkCallback)(void* start, unsigned int size, hkBool allocated, int pool, void* param);

class hkFreeListAllocator : public hkMemoryAllocator
{
public:
    struct CriticalSection
    {
        void* DebugInfo;
        long LockCount;
        long RecursionCount;
        void* OwningThread;
        void* LockSemaphore;
        unsigned long SpinCount;
    };

    struct FreeList
    {
        void* m_free;
        unsigned int m_iFirstIndex;
        unsigned int unk08;
        hkFreeListNode* m_activeBlocks;
        hkFreeListNode* m_pFreeBlocks;
        unsigned int unk14;
        unsigned int m_alignment;
        unsigned int unk1C;
        char* m_fMinimumV;
        char* m_pSecondString;
        int m_iFreeCount;
        int unk2C;
        hkFreeListAllocatorServer* m_blockServer;

        void Init();
        void freeAllMemory();
        void hkFreeList_hkFreeList(int, int, int, void*);
    };

    virtual ~hkFreeListAllocator();
    virtual void* blockAlloc(int iNumBytes);
    virtual void blockFree(void* pItem, int iNumBytes);
  public:  // variable-size buffers (slots 3-5)
    virtual void* bufAlloc(int& kReqNumBytesInOut);
    virtual void bufFree(void* pItem, int iNumBytes);
    virtual void* bufRealloc(void* pPold, int iOldNumBytes, int& kReqNumBytesInOut);
  public:  // batches and capacity queries (slots 6-9)
    virtual void blockAllocBatch(void** pPtrsOut, int iNumPtrs, int iBlockSize);
    virtual void blockFreeBatch(void** pPtrsIn, int iNumPtrs, int iBlockSize);
    virtual bool canAllocSingleBlock(int iNumBytes);
    virtual bool canAllocTotal(int iNumBytes);
  public:  // statistics (slots 10-12)
    virtual void getMemoryStatistics(MemoryStatistics& kU);
    virtual int getAllocatedSize(const void* pObj, int iNbytes);
    virtual void resetPeakMemoryStatistics();
    virtual void quit_00d5ff50();
    virtual void __thiscall PrintStatistics(int);
    virtual void nullsub_80(int);
    virtual void garbageCollect();
    virtual void AllocateBlocks(int iCount);
    virtual void UpdateTotalSize();
    virtual void setMemorySoftLimit(int iValue);
    virtual int GetUnkA94_00d5fba0();
    virtual void releaseUnusedPagesToSystemMemory();
    virtual bool* __thiscall isOk_00d5f890(bool* __restrict pItem);
    virtual int walkMemory(hkMemoryWalkCallback kCallback, void* pParam);

    void unused1();
    void unused2();
    void freeBlock(hkFreeListNode* pNode);
    void _deleteFreeList(FreeList* pItem);
    void* AllocateBlock(int iUnused, int iNumBytes);
    void FreeBlocks(void** pBlocks, int iNumBlocks, int iBlockSize);
    void resetPeakMemoryStatistics_00d5f850();
    void blockAlloc_00d5f970(int iFirst);
    unsigned char HasRoomFor(unsigned int uLimit);
    hkFreeListAllocator* hkFreeListAllocator_00d60270(int iA1);
    void blockAllocBatch_00d5fd70(void** pOut, int iCount, int iSize);
    void blockFree_00d5f980(void* pBlock, int iNumBytes);
    void getMemoryStatistics_00d5f750(HkFLA_Stats* pOut);
    void* bufAlloc_00d5fca0(int* pItem);
    void SetVtableAndProcessState_00d5ffd0();
    FreeList* _newFreeList(int iA1, int iA2, int iA3);
    int Alloc(int iFirst, int iSecond, int iThird);
    void Reset(int iFirst);

    union
    {
        CriticalSection m_cs;
        CriticalSection m_04;
        CriticalSection m_kCriticalSection;
        int m_akCriticalSection[6];
        char m_lock[0x18];
        char m_kLock[0x18];
    };
    union
    {
        int m_1c;
        int m_iPoolBlockSize;
        int m_iTotalSize;
        int m_iTotal;
        unsigned int m_uiBufferCapacity;
        int unk1C;
    };
    union
    {
        int m_20;
        int f20;
        unsigned int m_maxFree;
        int unk20;
    };
    union
    {
        hkMemoryAllocator* m_blockAllocator;
        int m_24;
        int unk24;
    };
    unsigned char unk28[0xC0];
    union { int m_e8; unsigned int m_total; int unkE8; };
    union
    {
        hkFreeListW* m_pFreeBlockLists[41];
        hkPoolBucket* m_class[41];
        SizeClassPool* m_ec[41];
        FreeList* m_tab[41];
    };
    union
    {
        hkFreeListW* m_pFreeLists[41];
        hkPoolBucket* m_bucket[41];
        FreeList* m_apBlocks[41];
        FreeList* m_apkPools[41];
        FreeList* m_pElems[41];
    };
    union { int m_iFreeListCount; int m_uiItemCount; int m_iArrayLength; int m_iPoolCount; int m_234; int count234; };
    union { FreeList* m_238; FreeList* volatile cur238; void* m_kNode; };
    union { FreeList* m_23c; FreeList* end23c; };
    FreeList m_items[41];
    union { int unkA94; int m_a94; unsigned int m_pFreeList; };
    union { int m_a98; int m_iCur; };
    int unkA9C;
};
