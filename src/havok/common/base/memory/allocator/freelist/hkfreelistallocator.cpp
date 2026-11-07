
// src/havok/common/base/memory/allocator/freelist/hkfreelistallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hkfreelistallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkFreeListAllocator.h"

void __cdecl hkOstream_printf(int, const char*);

// @fnv 0x00d5f950
void __thiscall hkFreeListAllocator::PrintStatistics(int aiUnused)
{
    hkOstream_printf(aiUnused,
                 "printStatistics is not supported on hkFreeListAllocator - use hkDebugMemory or hkPoolMemory\n");
}

// Calls FUN_00dd7200 on p, then if p+0x34 is the pointer stored at this+0x238, subtracts 0x34 from that pointer.
// @fnv 0x00d5fc70
// Keep the original out-of-line calls from cleanup and free-list creation.
// src: HAVOK_LIB 0x00d5fc70
__declspec(noinline) void hkFreeListAllocator::_deleteFreeList(FreeList* p)
{
    p->freeAllMemory();
    if (p + 1 == m_238)
        --m_238;
}

struct FUN_00d5f910_elem
{
    void* unk00;
    void* m_pNext;
};

struct FUN_00d5f910_sub
{
    virtual void* v00(int, int);
    virtual void* v04(int, int);
    virtual void* v08(int, int);
    virtual void* v0c(int, int);
    virtual void* BlockAlloc(int aiUnused, int aiNumBytes);
};

// Returns a free block from the size-class list for requests up to 0x280 bytes, otherwise delegates to the embedded large allocator.
// @fnv 0x00d5f910
void* hkFreeListAllocator::AllocateBlock(int aiUnused, int aiNumBytes)
{
    if (aiNumBytes <= 0x280)
    {
        if (aiNumBytes == 0)
            return 0;
        FUN_00d5f910_elem* pElem = reinterpret_cast<FUN_00d5f910_elem*>(m_tab[(aiNumBytes + 15) >> 4]);
        if (pElem)
            return pElem->m_pNext;
    }
    return reinterpret_cast<FUN_00d5f910_sub*>(unk28)->BlockAlloc(aiUnused, aiNumBytes);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct FreeListEntry
{
    FreeListEntry* next;
};

struct StringListNode
{
    FreeListEntry* m_free;
    int m_iFirstIndex;
    char pad08[0x20];
    int m_iFreeCount;
};

class LargeAlloc
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void ReleaseBlock(void* p);
};

// @fnv 0x00d5f9f0
void hkFreeListAllocator::FreeBlocks(void** blocks, int numBlocks, int blockSize)
{
    CriticalSection* cs = &m_cs;
    EnterCriticalSection(cs);
    if (blockSize <= 0x280)
    {
        StringListNode* list = reinterpret_cast<StringListNode*>(m_tab[(blockSize + 15) >> 4]);
        int iOldCount = list->m_iFreeCount;
        void** p = blocks;
        FreeListEntry* head = list->m_free;
        list->m_iFreeCount = iOldCount + numBlocks;
        for (int i = numBlocks - 1; i >= 0; i--)
        {
            FreeListEntry* e = (FreeListEntry*)*p++;
            if (e)
            {
                e->next = head;
                head = e;
            }
            else
            {
                list->m_iFreeCount--;
            }
        }
        list->m_free = head;
        m_iPoolBlockSize += (list->m_iFreeCount - iOldCount) * list->m_iFirstIndex;
    }
    else
    {
        for (int i = 0; i < numBlocks; i++)
        {
            if (blocks[i])
                reinterpret_cast<LargeAlloc*>(unk28)->ReleaseBlock(blocks[i]);
        }
    }
    LeaveCriticalSection(cs);
}

// The shared class has no declaration for this return-this destruction wrapper.
// @fnv 0x00d603e0
// src: GUESS 0x00d603e0 (confidence: low)
hkFreeListAllocator* __fastcall hkFreeListAllocator_ProcessAndReturnValue_00d603e0(hkFreeListAllocator* self, void*, unsigned int uiFlags)
{
    self->hkFreeListAllocator::SetVtableAndProcessState_00d5ffd0();
    return self;
}

struct FUN_00d61f30_shell
{
    void FUN_00d61cc0();
    void AppendStrings(int a, int b, int c, int d, int e, int f);
    void AppendStringsAfterInitialization(int a, int b, int c, int d, int e, int f);
};

// Calls FUN_00d61cc0, then forwards the six arguments to AppendStrings.
// @fnv 0x00d61f30
// src: GUESS 0x00d61f30 (confidence: medium)
void FUN_00d61f30_shell::AppendStringsAfterInitialization(int a, int b, int c, int d, int e, int f)
{
    FUN_00d61cc0();
    AppendStrings(a, b, c, d, e, f);
}

// Zeroes a six-int buffer, fills it with memory statistics, then stores the second element into unk20.
// @fnv 0x00d5f850
// src: HAVOK_LIB 0x00d5f850
void hkFreeListAllocator::resetPeakMemoryStatistics_00d5f850()
{
    int buf[6];
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    this->getMemoryStatistics(reinterpret_cast<hkMemoryAllocator::MemoryStatistics&>(buf));
    this->unk20 = buf[1];
}

// @fnv 0x00d5f970
// src: HAVOK_LIB 0x00d5f970
void hkFreeListAllocator::blockAlloc_00d5f970(int a)
{
    bufAlloc(a);
}

// @fnv 0x00d5fba0
// src: GUESS 0x00d5fba0 (confidence: low)
int hkFreeListAllocator::GetUnkA94_00d5fba0()
{
    return unkA94;
}

// @fnv 0x00d5fc30
// src: HAVOK_SRC 0x00d5fc30
void hkFreeListAllocator::releaseUnusedPagesToSystemMemory()
{
    this->garbageCollect();
}

// Updates the peak of used minus base bytes and returns whether used is below the limit subtracted from the value at offset 0xa94.
// @fnv 0x00d5fc40
unsigned char hkFreeListAllocator::HasRoomFor(unsigned int limit)
{
    unsigned int used = m_total - m_uiBufferCapacity;
    unsigned int peak = m_maxFree;
    if (used > peak)
    {
        peak = used;
    }
    m_maxFree = peak;
    unsigned int room = m_pFreeList - limit;
    if (used < room)
    {
        return 1;
    }
    return 0;
}

// stand-in types for FUN_00d60270
struct Sub4
{
    void Init(int a1);
};

struct Sub28
{
    void Init(int a1);
};

extern char g_vtbl60270[];

// Initializes the object: sets the vtable, initializes sub-objects and item array, resets state, and allocates the size-class table slots.
// @fnv 0x00d60270
// src: HAVOK_LIB 0x00d60270
hkFreeListAllocator* hkFreeListAllocator::hkFreeListAllocator_00d60270(int a1)
{
    *reinterpret_cast<void**>(this) = g_vtbl60270;
    reinterpret_cast<Sub4*>(&m_cs)->Init(0xfa0);
    m_24 = a1;
    reinterpret_cast<Sub28*>(unk28)->Init(a1);
    FreeList* pItems = m_items;
    m_234 = 0;
    FreeList* e = pItems;
    for (int i = 0x28; i >= 0; --i)
    {
        e->Init();
        ++e;
    }
    m_a98 = 0;
    m_1c = 0;
    m_20 = 0;
    Reset(0x7fffffff);
    m_238 = pItems;
    pItems = (FreeList*)((char*)pItems + 0x854);
    m_23c = pItems;
    for (int i = 0; i < 0x29; ++i)
    {
        m_tab[i] = 0;
    }
    m_tab[0x20] = reinterpret_cast<FreeList*>(Alloc(0x200, 0x80, 0x10000));
    m_tab[0x10] = reinterpret_cast<FreeList*>(Alloc(0x100, 0x20, 0x8000));
    m_tab[0] = reinterpret_cast<FreeList*>(Alloc(0, 4, 0x100));
    int r4 = Alloc(0x220, 0x80, 0x5000);
    for (int i = 0x210; i <= 0x280; ++i)
    {
        m_tab[i >> 4] = reinterpret_cast<FreeList*>(r4);
    }
    int iSize = 0x280;
    do
    {
        FreeList** slot = &m_tab[iSize >> 4];
        if (*slot == 0)
        {
            int iCount = 0x10;
            int sz;
            if (iSize > 0)
            {
                sz = iSize << 4;
                if ((unsigned int)iSize < 0x100)
                {
                    sz = 0x1000;
                }
            }
            else
            {
                sz = 0x1000;
            }
            if (iSize >= 0x40)
            {
                iCount = 0x20;
            }
            *slot = reinterpret_cast<FreeList*>(Alloc(iSize, iCount, sz));
        }
        iSize -= 0x10;
    } while (iSize >= 0x10);
    return this;
}

extern void(__stdcall* DAT_00fdf05c)(int*);
extern void(__stdcall* DAT_00fdf100)(int*);
namespace d5f {
struct Res
{
    bool m_kPointB;
    Res()
    {}
};
struct Block
{
    int unk;
    int m_iWordAt04;
    char pad[0x28 - 8];
    int m_28;
    Res incrementalFindGarbage(int n, int* got);
    void freeAllFreeBlocks();
};

}

// Locks the pool, walks blocks from m_iCur allocating n units, updates m_1c and m_iCur, then unlocks.
// @fnv 0x00d5feb0
void hkFreeListAllocator::AllocateBlocks(int aiCount)
{
    int* cs = m_akCriticalSection;
    DAT_00fdf05c(cs);
    if (aiCount < 1)
        aiCount = 1;
    int start = m_iCur;
    int iIndex = start;
    do
    {
        d5f::Block* b = reinterpret_cast<d5f::Block*>(m_apBlocks[iIndex]);
        int before = b->m_28;
        int got;
        if (b->incrementalFindGarbage(aiCount, &got).m_kPointB)
        {
            iIndex++;
            if (iIndex >= m_iArrayLength)
                iIndex = 0;
        }
        b->freeAllFreeBlocks();
        aiCount -= got;
        m_1c += (b->m_28 - before) * b->m_iWordAt04;
    } while (aiCount > 0 && iIndex != start);
    m_iCur = iIndex;
    DAT_00fdf100(cs);
}

// @fnv 0x00d5fab0
// src: COMMUNITY 0x00d5fab0
void hkFreeListAllocator::nullsub_80(int)
{}

extern void(__stdcall* DAT_00fdf05c)(int* pkCriticalSection);
extern void(__stdcall* DAT_00fdf100)(int* pkCriticalSection);

class MemoryPoolW
{
  public:
    int Compact();
    void freeSmallFreeBlocks(unsigned int uiTarget);

    int m_iUnk00;
    int m_iBlockSize;
    char m_pad08[0xc];
    unsigned int m_uiFreeCount;
    char m_pad18[0x10];
    int m_iBlockCount;
};

// @fnv 0x00d5fbb0
void hkFreeListAllocator::UpdateTotalSize()
{
    int* pkCriticalSection = m_akCriticalSection;
    DAT_00fdf05c(pkCriticalSection);
    for (int i = 0; i < m_iPoolCount; i++)
    {
        MemoryPoolW* pkPool = reinterpret_cast<MemoryPoolW*>(m_apkPools[i]);
        int iOldCount = pkPool->m_iBlockCount;
        if (pkPool->Compact() > 0)
            pkPool->freeSmallFreeBlocks(pkPool->m_uiFreeCount - pkPool->m_uiFreeCount / 10);
        m_iTotalSize += (pkPool->m_iBlockCount - iOldCount) * pkPool->m_iBlockSize;
    }
    DAT_00fdf100(pkCriticalSection);
}

struct SubAllocator
{
    virtual void* v00();
    virtual void* v04(unsigned int aSize);
};

struct SizeClassPool
{
    void* m_00;
    unsigned int m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    volatile unsigned int m_20;
    unsigned int m_24;
    int m_28;

    void* AllocateElement();
};

void __cdecl hkSetOutOfMemoryState(int);

struct ScopedCs
{
    hkFreeListAllocator* owner;
    hkFreeListAllocator::CriticalSection* cs;
};

// @fnv 0x00d5fd70
// src: HAVOK_LIB 0x00d5fd70
void hkFreeListAllocator::blockAllocBatch_00d5fd70(void** apOut, int aCount, int aSize)
{
    ScopedCs guard;
    guard.owner = this;
    guard.cs = &m_04;
    EnterCriticalSection(&m_04);

    if (aSize <= 0x280)
    {
        SizeClassPool* pool = m_ec[(aSize + 15) >> 4];
        int iFreeCount = pool->m_28;
        void** cur = apOut;
        void** end = apOut + aCount;
        void* node = pool->m_00;
        while (cur < end)
        {
            if (node == 0)
            {
                break;
            }
            *cur = node;
            cur++;
            node = *(void**)node;
        }
        pool->m_00 = node;
        pool->m_28 -= (int)(cur - apOut);
        void** start = cur;
        while (cur < end)
        {
            if (pool->m_20 < pool->m_24)
            {
                do
                {
                    if (cur >= end)
                    {
                        break;
                    }
                    *cur = (void*)pool->m_20;
                    pool->m_20 += pool->m_04;
                    cur++;
                } while (pool->m_20 < pool->m_24);
                pool->m_28 -= (int)(cur - start);
            }
            else
            {
                *cur = pool->AllocateElement();
                cur++;
            }
            start = cur;
        }
        guard.owner->m_1c += (pool->m_28 - iFreeCount) * (int)pool->m_04;
    }
    else
    {
        for (int i = 0; i < aCount; i++)
        {
            apOut[i] = reinterpret_cast<SubAllocator*>(guard.owner->unk28)->v04(aSize);
        }
    }

    hkFreeListAllocator* self = guard.owner;
    unsigned int avail = (unsigned int)(self->m_e8 - self->m_1c);
    unsigned int grow = (unsigned int)self->m_20;
    if (avail > grow)
    {
        grow = avail;
    }
    self->m_20 = (int)grow;
    if (avail >= (unsigned int)self->m_a94)
    {
        hkSetOutOfMemoryState(1);
    }
    LeaveCriticalSection(guard.cs);
}

struct hkFreeListBlock
{
    hkFreeListBlock* m_next;
};

struct hkFreeListW
{
    void* m_free;
    unsigned int m_iFirstIndex;
    unsigned int m_unk08;
    hkFreeListBlock* m_activeBlocks;
    hkFreeListBlock* m_pFreeBlocks;

    static int _getNumBlocks(const hkFreeListBlock* blocks)
    {
        int num = 0;
        while (blocks)
        {
            num++;
            blocks = blocks->m_next;
        }
        return num;
    }
    int getTotalNumBlocks() const
    {
        return _getNumBlocks(m_pFreeBlocks) + _getNumBlocks(m_activeBlocks);
    }
    void CollectFreeNodes(hkFreeListBlock** blocks, int numBlocks);
    void walkMemory_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param);
};

struct hkMemoryAllocatorW
{
    virtual ~hkMemoryAllocatorW();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemChunkW
{
    unsigned int m_prevFoot;
    unsigned int m_pFirstNode;
};

struct hkLargeBlockIteratorW
{
    hkMemChunkW* m_pCurrentMemoryChunk;
    void* m_pHandlePage;
    void* m_kRayEnd;
    bool isValid() const
    {
        return m_pCurrentMemoryChunk != 0;
    }
    void* GetChunkPayload() const
    {
        return (char*)m_pCurrentMemoryChunk + 0x10;
    }
    unsigned int GetLogicalSize() const
    {
        return m_pCurrentMemoryChunk->m_pFirstNode & ~3u;
    }
    hkBool isInuse() const
    {
        return (m_pCurrentMemoryChunk->m_pFirstNode & 2) != 0;
    }
};

struct hkLargeBlockAllocatorW
{
    hkLargeBlockIteratorW getIterator();
    hkBool AdvanceState(hkLargeBlockIteratorW& iter);
};

bool __cdecl CompareLessThan(void* a, void* b);
void __cdecl hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(void** arr, int lo, int hi, bool(__cdecl* cmpLess)(void*, void*));

inline void quickSortPointers(void** arr, int numElem)
{
    if (numElem > 1)
    {
        hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(arr, 0, numElem - 1, CompareLessThan);
    }
}

// Collects free-list nodes, calls callback for other large-block chunks, then asks each free list to invoke its callback.
// @fnv 0x00d600c0
// src: HAVOK_LIB 0x00d600c0
int hkFreeListAllocator::walkMemory(hkMemoryWalkCallback callback, void* apContext)
{
    int numBlocks = 0;
    for (int i = 0; i < m_iFreeListCount; i++)
    {
        numBlocks += m_pFreeLists[i]->getTotalNumBlocks();
    }

    hkFreeListBlock** blocks =
        (hkFreeListBlock**)reinterpret_cast<hkMemoryAllocatorW*>(m_blockAllocator)->AllocateMemoryBlock(numBlocks * sizeof(hkFreeListBlock*));
    if (!blocks)
    {
        return 1;
    }

    {
        hkFreeListBlock** cur = blocks;
        for (int i = 0; i < m_iFreeListCount; i++)
        {
            hkFreeListW* freeList = m_pFreeLists[i];
            int numListBlocks = freeList->getTotalNumBlocks();
            freeList->CollectFreeNodes(cur, numListBlocks);
            cur += numListBlocks;
        }
    }

    quickSortPointers((void**)blocks, numBlocks);

    {
        hkFreeListBlock** curBlock = blocks;
        hkLargeBlockIteratorW iter = reinterpret_cast<hkLargeBlockAllocatorW*>(unk28)->getIterator();
        for (; iter.isValid(); reinterpret_cast<hkLargeBlockAllocatorW*>(unk28)->AdvanceState(iter))
        {
            void* block = iter.GetChunkPayload();
            if (block == (void*)*curBlock)
            {
                curBlock++;
                continue;
            }
            callback(block, iter.GetLogicalSize(), iter.isInuse(), 0, apContext);
        }
    }

    reinterpret_cast<hkMemoryAllocatorW*>(m_blockAllocator)->ReleaseBlock(blocks, numBlocks * sizeof(hkFreeListBlock*));

    for (int i = 0; i < m_iFreeListCount; i++)
    {
        m_pFreeLists[i]->walkMemory_00dd78f0(callback, i + 1, apContext);
    }
    return 0;
}

struct PoolFreeBlock
{
    PoolFreeBlock* m_pNext;
};

struct PoolFreeList
{
    PoolFreeBlock* m_pHead;
    int m_iBlockSize;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_iArrayLength;
};

struct PoolFallbackAlloc
{
    virtual void* v00();
    virtual void* v04();
    virtual void Free(void* apBlock);
};

// Returns apBlock to the pool free list for sizes up to 0x280 bytes, or to the embedded large allocator for larger sizes, updating m_iTotal.
// @fnv 0x00d5f980
// src: HAVOK_LIB 0x00d5f980
void hkFreeListAllocator::blockFree_00d5f980(void* apBlock, int aiNumBytes)
{
    if (apBlock == 0)
        return;

    EnterCriticalSection(&m_kLock);

    if (aiNumBytes <= 0x280)
    {
        PoolFreeList* pList = reinterpret_cast<PoolFreeList*>(m_tab[(aiNumBytes + 0xf) >> 4]);
        int iOldCount = pList->m_iArrayLength;
        pList->m_iArrayLength = iOldCount + 1;
        ((PoolFreeBlock*)apBlock)->m_pNext = pList->m_pHead;
        int iDelta = (pList->m_iArrayLength - iOldCount) * pList->m_iBlockSize;
        pList->m_pHead = (PoolFreeBlock*)apBlock;
        m_iTotal += iDelta;
    }
    else
    {
        reinterpret_cast<PoolFallbackAlloc*>(unk28)->Free(apBlock);
    }

    LeaveCriticalSection(&m_kLock);
}

// Sets unkA94 to value while holding m_kCriticalSection.
// @fnv 0x00d5fb70
// src: HAVOK_LIB 0x00d5fb70
void hkFreeListAllocator::setMemorySoftLimit(int value)
{
    EnterCriticalSection(&m_kCriticalSection);
    unkA94 = value;
    LeaveCriticalSection(&m_kCriticalSection);
}

struct HkFLA_Out
{  // the 24 byte result block of FUN_00dd7430
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
};

struct HkFLA_Elem
{  // one entry of the element array
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    void calculateStatistics(HkFLA_Out* out);
};

struct HkFLA_Poly
{  // the object at +0x24 (virtual at +0x18)
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

struct HkFLA_Stats
{  // the out parameter
    int unk00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
};

struct HkFLA_Sub
{                                         // the sub object at +0x28 (its size is only
    void hkLargeBlockAllocator_calculateStatistics(HkFLA_Stats* out);  // known from the layout below)
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    int unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    int unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c, unk110, unk114;
    int unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164;
    int unk168;
};

// Gathers aggregate statistics from all elements into out while holding the critical section.
// @fnv 0x00d5f750
// src: HAVOK_LIB 0x00d5f750
void hkFreeListAllocator::getMemoryStatistics_00d5f750(HkFLA_Stats* apStats)
{
    CriticalSection* cs = &m_cs;
    EnterCriticalSection((void*)cs);
    reinterpret_cast<HkFLA_Sub*>(unk28)->hkLargeBlockAllocator_calculateStatistics(apStats);
    // The original keeps a 24 byte block on the stack here and accumulates
    // into its first dword only; the dead members lose their stores but the
    // frame slot (and with it the frame size) stays.
    HkFLA_Out stTotals = {0, 0, 0, 0, 0, 0};
    int totalSize = 0;  // sum of the elements' f04
    int totalArea = 0;  // sum of the elements' f0c
    for (int i = 0; i < m_uiItemCount; i++)
    {
        HkFLA_Elem* e = reinterpret_cast<HkFLA_Elem*>(m_pElems[i]);
        HkFLA_Out s = {0, 0, 0, 0, 0, 0};
        e->calculateStatistics(&s);
        if (e->f00 != 0 || e->f20 < e->f24)
        {
            unsigned int uiValue = e->f04;
            if (uiValue > apStats->f14)
                apStats->f14 = uiValue;
        }
        totalArea += s.f0c;
        totalSize += s.f04;
        stTotals.f00 += s.f00;
    }
    apStats->f0c += totalArea;
    apStats->f04 += totalSize - stTotals.f00;
    apStats->f08 = f20;
    int iResult = reinterpret_cast<HkFLA_Poly*>(m_blockAllocator)->v6();
    if (iResult == -1)
        apStats->f10 = iResult;
    else
        apStats->f10 = apStats->f0c + iResult;
    LeaveCriticalSection((void*)cs);
}

struct ItemObj
{
    void __thiscall FUN_00dd7140_q(unsigned char* ok);
};

// Locks m_cs, sets *p to 1, calls each item's method until its output byte is zero, then returns p.
// @fnv 0x00d5f890
// src: HAVOK_LIB 0x00d5f890
bool* __thiscall hkFreeListAllocator::isOk_00d5f890(bool* __restrict pbSuccess)
{
    EnterCriticalSection(&m_cs);
    *pbSuccess = 1;
    for (int i = 0; i < m_uiItemCount; i++)
    {
        unsigned char ok;
        reinterpret_cast<ItemObj*>(m_apBlocks[i])->FUN_00dd7140_q(&ok);
        if (!ok)
        {
            *pbSuccess = 0;
            break;
        }
    }
    LeaveCriticalSection(&m_cs);
    return pbSuccess;
}

struct FUN_00d5fac0_item
{
    int unk00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;
    int Compact();
    void freeAllFreeBlocks();
};

struct FUN_00d5fac0_sub
{
    int unk00;
    void PurgeAndSelectBlock();
};

// Locks m_lock, compacts the free lists and updates m_1c, then purges the embedded large allocator.
// @fnv 0x00d5fac0
// src: HAVOK_LIB 0x00d5fac0
void hkFreeListAllocator::garbageCollect()
{
    void* cs = &m_lock;
    EnterCriticalSection(cs);
    bool retry = false;
    bool flag;
    do
    {
        flag = false;
        for (int i = 0; i < m_uiItemCount; ++i)
        {
            FUN_00d5fac0_item* p = reinterpret_cast<FUN_00d5fac0_item*>(m_apBlocks[i]);
            int saved = p->m_28;
            if (p->Compact() < 0)
            {
                retry = true;
            }
            if (p->m_10 != 0)
            {
                flag = true;
            }
            p->freeAllFreeBlocks();
            m_1c += (p->m_28 - saved) * p->m_04;
        }
    } while (flag && retry);
    reinterpret_cast<FUN_00d5fac0_sub*>(unk28)->PurgeAndSelectBlock();
    LeaveCriticalSection(cs);
}

// One unused element of a size class.
struct hkPoolNode
{
    hkPoolNode* next;
};

// One size class of the pool.
struct hkPoolBucket
{
    hkPoolNode* freeHead;  // +0x00 head of the list of unused elements
    int elemSize;          // +0x04 size of a single element
    int unk08;             // +0x08
    void* freeNodes;       // +0x0c
    void* blocks;          // +0x10
    void* block;           // +0x14
    unsigned int align;    // +0x18
    int maxCount;          // +0x1c
    char* bump;            // +0x20 next element inside the current block
    char* bumpEnd;         // +0x24 end of the current block
    int count;             // +0x28 number of elements handed out
    void* AllocateElement();  // carve a new element out of a fresh block
};

// Allocator used for requests that are too large for the size classes.
struct hkPoolLarge
{
    virtual void* FUN_00dd8790_v0();
    virtual void* FUN_00dd8790_v1(int size);
    virtual void* FUN_00dd8790_v2(int size);
    int unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034;
    int unk038, unk03c, unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c, unk060, unk064;
    int unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094;
    int unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
    int unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
};

// Allocates a block of the requested size from the pool's free list, bump allocator, or large allocator, and updates the high-water mark for free memory.
// @fnv 0x00d5fca0
// src: HAVOK_LIB 0x00d5fca0
void* hkFreeListAllocator::bufAlloc_00d5fca0(int* apSize)
{
    int size = *apSize;
    EnterCriticalSection(&this->m_lock);
    void* result;
    if (size <= 0x280)
    {
        hkPoolBucket* b = this->m_class[(size + 15) >> 4];
        hkPoolNode* node = b->freeHead;
        int oldCount = b->count;
        if (node)
        {
            b->count = oldCount - 1;
            b->freeHead = node->next;
            result = node;
        }
        else if (b->bump >= b->bumpEnd)
        {
            result = b->AllocateElement();
        }
        else
        {
            result = b->bump;
            b->count = oldCount - 1;
            b->bump += b->elemSize;
        }
        this->m_uiBufferCapacity += (b->count - oldCount) * b->elemSize;
        *apSize = b->elemSize;
    }
    else
    {
        result = reinterpret_cast<hkPoolLarge*>(this->unk28)->FUN_00dd8790_v1(size);
    }
    unsigned int free = this->m_total - this->m_uiBufferCapacity;
    unsigned int maxFree = this->m_maxFree;
    if (free > maxFree)
        maxFree = free;
    this->m_maxFree = maxFree;
    if (free >= this->m_pFreeList)
        hkSetOutOfMemoryState(1);
    LeaveCriticalSection(&this->m_lock);
    return result;
}

struct QuitLargeBlockView
{
    void ProcessAllItems();
};

// Frees each non-null free list, nulls later matching pointers, then calls the large-block allocator's cleanup.
// @fnv 0x00d5ff50
// src: HAVOK_LIB 0x00d5ff50
void hkFreeListAllocator::quit_00d5ff50()
{
    if (m_iFreeListCount > 0)
    {
        int index = 1;
        hkFreeListW** slot = m_pFreeLists;
        do
        {
            hkFreeListW* entry = *slot;
            if (entry)
            {
                _deleteFreeList(reinterpret_cast<FreeList*>(entry));
                int later = index;
                if (later < m_iFreeListCount)
                {
                    hkFreeListW** next = slot + 1;
                    do
                    {
                        if (*next == entry)
                        {
                            *next = 0;
                        }
                        ++next;
                        ++later;
                    } while (later < m_iFreeListCount);
                }
            }
            ++index;
            ++slot;
        } while (index - 1 < m_iFreeListCount);
    }
    reinterpret_cast<QuitLargeBlockView*>(unk28)->ProcessAllItems();
}

extern "C" int DAT_010d1464;
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);

struct EmbeddedMember
{
    void __thiscall ProcessEntries_00dd7ec0();
};

// Sets the vtable, calls cleanup and member functions, deletes the critical section, then calls another member function.
// @fnv 0x00d5ffd0
// src: GUESS 0x00d5ffd0 (confidence: low)
void hkFreeListAllocator::SetVtableAndProcessState_00d5ffd0()
{
    *reinterpret_cast<void**>(this) = &DAT_010d1464;
    hkFreeListAllocator::quit_00d5ff50();
    FreeList* end = m_items + 41;
    for (int i = 40; i >= 0; --i)
    {
        (--end)->freeAllMemory();
    }
    reinterpret_cast<EmbeddedMember*>(unk28)->ProcessEntries_00dd7ec0();
    DeleteCriticalSection(&m_cs);
    hkMemoryAllocator::~hkMemoryAllocator();
}

extern "C" void __debugbreak();

// Advances cur238, initializes s when nonnull, then returns a matching slot or registers and returns s.
// @fnv 0x00d60020
// src: HAVOK_LIB 0x00d60020
hkFreeListAllocator::FreeList* hkFreeListAllocator::_newFreeList(int aiParam1, int aiParam2, int aiParam3)
{
    if (cur238 >= end23c)
    {
        __debugbreak();
    }
    FreeList* s = cur238;
    cur238 = s + 1;
    if (s != 0)
    {
        s->hkFreeList_hkFreeList(aiParam1, aiParam2, aiParam3, &unk28);
    }
    for (int i = 0; i < count234; i++)
    {
        if (m_apBlocks[i]->m_iFirstIndex == s->m_iFirstIndex)
        {
            _deleteFreeList(s);
            return m_apBlocks[i];
        }
    }
    m_apBlocks[count234] = s;
    count234++;
    return s;
}
