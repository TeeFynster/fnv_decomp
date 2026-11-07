
// src/havok/common/base/memory/allocator/thread/hkthreadmemory.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/thread/hkthreadmemory.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d2c3a0_class
{
    void* m0;
    void* m4;
    void* m8;
    void hkThreadMemory_setMemory(void* a, void* b);
};

// @fnv 0x00d2c3a0
// src: HAVOK_LIB 0x00d2c3a0
void FUN_00d2c3a0_class::hkThreadMemory_setMemory(void* pFirst, void* pSecond)
{
    if (pFirst)
    {
        m4 = pFirst;
        m8 = pSecond;
    }
    else
        m4 = 0;
}

struct SlowPath
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void process(int* output, int count, int value);
};
struct FUNClass
{
    virtual void unused();
    virtual unsigned int generate(int value);
    SlowPath* unk04;
    void hkThreadMemory_blockAllocBatch(int* output, int count, int value);
};
// If value is at most 0x2000, fills output with count values from generate(value); otherwise delegates to unk04->process.
// @fnv 0x00d2c030
// src: HAVOK_LIB 0x00d2c030
void FUNClass::hkThreadMemory_blockAllocBatch(int* output, int count, int value)
{
    if (value <= 0x2000)
    {
        for (int i = 0; i < count; ++i)
            output[i] = generate(value);
        return;
    }
    unk04->process(output, count, value);
}

struct Helper
{
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void dispatch(unsigned int* values, int count, int threshold);
};
struct Owner
{
    virtual void v0();
    virtual void v1();
    virtual void check(unsigned int value, int threshold);
    Helper* helper;
    void ProcessValues(unsigned int* values, int count, int threshold);
};
// If threshold is at most 0x2000, calls check on each value; otherwise forwards values, count and threshold to helper->dispatch.
// @fnv 0x00d2c090
void Owner::ProcessValues(unsigned int* values, int count, int threshold)
{
    if (threshold <= 0x2000)
    {
        for (int i = 0; i < count; ++i)
            check(values[i], threshold);
    }
    else
        helper->dispatch(values, count, threshold);
}

struct ComponentValue
{
    int value;
    int unk04;
};

struct Target : FUN_00d2c3a0_class
{
    int unk0C;
    ComponentValue values[16];
    int terminal;
    volatile int weights[17];
    int ComputeWeightedSum();
};

// Accumulates products of weights and values over 8 iterations, adds terminal*weights[16], and returns the total.
// @fnv 0x00d2c350
int Target::ComputeWeightedSum()
{
    int firstSum = 0;
    int secondSum = 0;
    int* firstValue = &values[1].value;
    volatile int* secondWeight = &weights[1];
    int remaining = 8;
    do
    {
        firstSum += secondWeight[-1] * firstValue[-2];
        secondSum += secondWeight[0] * firstValue[0];
        secondWeight += 2;
        firstValue += 4;
        --remaining;
    } while (remaining != 0);
    int result = firstSum;
    result += secondSum;
    result += terminal * weights[16];
    return result;
}

struct Block
{
    Block* next;
};
struct Allocator
{
    virtual void v0();
    virtual void* Allocate(int size);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void AllocateBatch(Block** output, int count, int size);
};
struct Cache
{
    Block* head;
    volatile int count;
};
struct CachedBlockAllocator
{
    void* owner;
    Allocator* allocator;
    int batchCount;
    Cache caches[17];
    int blockSizes[17];
    void* AllocateBlock(int index);
    __forceinline void* AllocateBatchCached(int index, int count)
    {
        Block* blocks[4];
        if (count >= 4)
            count = 4;
        allocator->AllocateBatch(blocks, count, blockSizes[index]);
        for (int i = 1; i < count; ++i)
        {
            Block* block = blocks[i];
            Block* previous = caches[index].head;
            ++caches[index].count;
            block->next = previous;
            caches[index].head = block;
        }
        return blocks[0];
    }
};
// @fnv 0x00d2c3c0
void* CachedBlockAllocator::AllocateBlock(int index)
{
    int count = batchCount;
    if (!count)
        return allocator->Allocate(blockSizes[index]);
    return AllocateBatchCached(index, count);
}

struct D2C520Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void AllocateFixedSizeBlocks(void** blocks, int numBlocks, int blockSize);
};

struct D2C520Block
{
    D2C520Block* m_next;
};

struct D2C520FreeList
{
    D2C520Block* m_pFirstNode;
    int m_iBlockCount;

    void* pop()
    {
        D2C520Block* block = m_pFirstNode;
        if (block)
        {
            m_iBlockCount--;
            m_pFirstNode = block->m_next;
            return block;
        }
        return 0;
    }
};

inline int D2C520Min2(int a, int b)
{
    return (a < b) ? a : b;
}

struct D2C520ThreadMemory
{
    int unk00;
    D2C520Allocator* m_pThreadAllocator;
    int unk08;
    D2C520FreeList m_kFreeListEntries[17];
    int m_iDofCount[17];

    void hkThreadMemory_clearRow(int rowIndex);
};

// @fnv 0x00d2c520
// src: HAVOK_LIB 0x00d2c520
void D2C520ThreadMemory::hkThreadMemory_clearRow(int rowIndex)
{
    int numElem = m_kFreeListEntries[rowIndex].m_iBlockCount;
    int blockSize = m_iDofCount[rowIndex];
    while (numElem > 0)
    {
        void* blocks[4];
        int batch = D2C520Min2(4, numElem);
        for (int i = 0; i < batch; i++)
            blocks[i] = m_kFreeListEntries[rowIndex].pop();
        numElem -= batch;
        m_pThreadAllocator->AllocateFixedSizeBlocks(blocks, batch, blockSize);
    }
}

namespace fnv_00d2c5a0 {
struct FreeNode
{
    FreeNode* next;
};
struct FreeBlock
{
    FreeNode* head;
    int count;
};
struct OverflowHandler
{
    virtual void f0();
    virtual FreeNode* f1(int);
};
struct Allocator : FUN_00d2c3a0_class
{
    FreeBlock blocks[25];
    int unkD4;
    signed char bucketForSmallSize[44];
    int bucketForLargeSize[8];
    FreeNode* hkThreadMemory_blockAlloc(int size);
};
// The target helper ignores EDX; this ABI-compatible signature keeps its this pointer in ECX and bucket on the stack.
extern "C" FreeNode* __fastcall AllocateBlock(Allocator* self, int unused, int bucket);
// @fnv 0x00d2c5a0
// src: HAVOK_LIB 0x00d2c5a0
FreeNode* Allocator::hkThreadMemory_blockAlloc(int size)
{
    if (size <= 0x2000)
    {
        int bucket;
        if (size <= 0x280)
            bucket = bucketForSmallSize[(size + 0xf) >> 4];
        else
            bucket = bucketForLargeSize[(size - 1) >> 10];
        FreeBlock* block = &blocks[bucket];
        if (block->head)
        {
            FreeNode* node = block->head;
            --block->count;
            block->head = node->next;
            return node;
        }
        return AllocateBlock(this, bucket, bucket);
    }
    return ((OverflowHandler*)m4)->f1(size);
}
}  // namespace fnv_00d2c5a0

extern void hkMemUtil_memCpy_00d2caa0(void* res, int a1, int n);

struct SelfCls
{
    virtual void vslot0();
    virtual void* vslot1(void* p);
    virtual void vslot2(int a, int b);

    void* hkThreadMemory_bufRealloc(int a1, int a2, FUN_00d2c3a0_class* a3);
};

// @fnv 0x00d2c6d0
// src: HAVOK_LIB 0x00d2c6d0
void* SelfCls::hkThreadMemory_bufRealloc(int a1, int a2, FUN_00d2c3a0_class* a3)
{
    void* res = this->vslot1(a3->m0);
    int n = (int)a3->m0 < a2 ? (int)a3->m0 : a2;
    hkMemUtil_memCpy_00d2caa0(res, a1, n);
    this->vslot2(a1, a2);
    return res;
}

struct FUN_00d2c7a0_Slot
{
    void* object;
    int unk04;
};

struct FUN_00d2c7a0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d2c7a0_Slot slots[17];
    void __thiscall hkThreadMemory_clearRow(int index);
    void __thiscall hkThreadMemory_releaseCachedMemory();
};

// Iterates the 17 slots backwards and calls FUN_00d2c520 on each index whose slot holds an object.
// @fnv 0x00d2c7a0
// src: HAVOK_LIB 0x00d2c7a0
void FUN_00d2c7a0_class::hkThreadMemory_releaseCachedMemory()
{
    int index = 16;
    FUN_00d2c7a0_Slot* slot = slots + 16;
    while (index >= 0)
    {
        if (slot->object)
            hkThreadMemory_clearRow(index);
        --index;
        --slot;
    }
}

struct FUN_00d60500
{
    virtual void placeholder();
    unsigned int capacity;
    unsigned int count;
    void* storage;
    void* owner;
    FUN_00d60500(void* parent, unsigned int requested);
};
// @fnv 0x00d60500
FUN_00d60500::FUN_00d60500(void* apOwner, unsigned int requested) : owner(apOwner), count(0), storage(0)
{
    if (!requested)
    {
        capacity = 0x20000;
        return;
    }
    capacity = requested;
}

class DispatchInterface
{
  public:
    virtual void Unknown0() = 0;
    virtual int Dispatch(void*) = 0;
    int DispatchValue(void* const& value);
};
// @fnv 0x00d2c000
int DispatchInterface::DispatchValue(void* const& value)
{
    return Dispatch(value);
}

struct FUN_00d2c020_class
{
    virtual void __fastcall slot00(unsigned int value);
    virtual void __fastcall slot04(unsigned int value);
    virtual void __fastcall slot08(unsigned int value);

    void __fastcall hkThreadMemory_bufFree(unsigned int value);
};

// @fnv 0x00d2c020
// src: HAVOK_SRC 0x00d2c020
void __fastcall FUN_00d2c020_class::hkThreadMemory_bufFree(unsigned int value)
{
    slot08(value);
}

struct FnvCpu_FUN_00d2c0f0_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d2c0f0_CpuOwner
{
    unsigned int unk00;
    FnvCpu_FUN_00d2c0f0_CpuInterface* target;
    void hkThreadMemory_getMemoryStatistics(int arg0);
};
// @fnv 0x00d2c0f0
// src: HAVOK_SRC 0x00d2c0f0
void FnvCpu_FUN_00d2c0f0_CpuOwner::hkThreadMemory_getMemoryStatistics(int arg0)
{
    target->Invoke(arg0);
}

extern "C" void __debugbreak();

__forceinline int GetSizeClass(int aiSize)
{
    if (aiSize <= 0x10)
        return 1;
    if (aiSize <= 0x20)
        return 2;
    if (aiSize <= 0x30)
        return 3;
    if (aiSize <= 0x40)
        return 4;
    if (aiSize <= 0x60)
        return 5;
    if (aiSize <= 0x80)
        return 6;
    if (aiSize <= 0xA0)
        return 7;
    if (aiSize <= 0xC0)
        return 8;
    if (aiSize <= 0x100)
        return 9;
    if (aiSize <= 0x140)
        return 10;
    if (aiSize <= 0x200)
        return 11;
    if (aiSize <= 0x280)
        return 12;
    if (aiSize <= 0x400)
        return 13;
    if (aiSize <= 0x800)
        return 14;
    if (aiSize <= 0x1000)
        return 15;
    if (aiSize <= 0x2000)
        return 16;
    __debugbreak();
    return -1;
}

struct SizeClassTable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int iClassSize[17];
    unsigned char ucSmallClass[41];
    int iLargeClass[8];

    void InitSizeClasses();
};

// @fnv 0x00d2c100
void SizeClassTable::InitSizeClasses()
{
    for (int i = 0; i <= 40; i++)
    {
        int iSize = i << 4;
        int m_iMenuId = GetSizeClass(iSize);
        ucSmallClass[i] = m_iMenuId;
        iClassSize[m_iMenuId] = iSize;
    }
    for (int i = 0; i < 8; i++)
    {
        int iSize = (i + 1) << 10;
        int m_iMenuId = GetSizeClass(iSize);
        iLargeClass[i] = m_iMenuId;
        iClassSize[m_iMenuId] = iSize;
    }
}

struct FUN_00d2c600_bucket
{
    void* m_pFirstNode;
    volatile int m_uiItemCount;
};

struct FUN_00d2c600_obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* p, int size);
};

struct FUN_00d2c600_cls
{
    int unk00;
    FUN_00d2c600_obj* m_04;
    int m_08;

    void hkThreadMemory_onRowFull(int index, void* p);
    void Free(void* p, int size);
};

// @fnv 0x00d2c600
void FUN_00d2c600_cls::Free(void* apBlock, int size)
{
    if (apBlock != 0)
    {
        if (size <= 0x2000)
        {
            int idx;
            if (size <= 0x280)
            {
                idx = *(signed char*)((char*)this + 0xd8 + ((size + 0xf) >> 4));
            }
            else
            {
                idx = *(int*)((char*)this + 0x104 + (((size - 1) >> 10) * 4));
            }
            FUN_00d2c600_bucket* bucket = (FUN_00d2c600_bucket*)((char*)this + 0xc + idx * 8);
            if (bucket->m_uiItemCount >= m_08)
            {
                hkThreadMemory_onRowFull(idx, apBlock);
            }
            else
            {
                void** node = (void**)apBlock;
                void* head = bucket->m_pFirstNode;
                bucket->m_uiItemCount++;
                *node = head;
                bucket->m_pFirstNode = node;
            }
        }
        else
        {
            m_04->unk08(apBlock, size);
        }
    }
}

struct FUN_00d2c670_inner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void Forward(int a);
};

struct FUN_00d2c670_cls
{
    void* m_00;
    FUN_00d2c670_inner* m_04;

    void hkThreadMemory_canAllocTotal(int a);
};

// @fnv 0x00d2c670
// src: HAVOK_LIB 0x00d2c670
void FUN_00d2c670_cls::hkThreadMemory_canAllocTotal(int a)
{
    m_04->Forward(a);
}

struct S_00d2c680_Inner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int v2c(int a0, int a1);
};

struct S_00d2c680_Cls
{
    int unk00;
    S_00d2c680_Inner* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int m_94[0x10];
    int unkd4;
    signed char m_d8[0x2c];
    int m_104[8];
    int hkThreadMemory_getAllocatedSize(int a0, int a1);
};

// @fnv 0x00d2c680
// src: HAVOK_LIB 0x00d2c680
int S_00d2c680_Cls::hkThreadMemory_getAllocatedSize(int aiArg, int a1)
{
    if (a1 <= 0x2000)
    {
        int idx;
        if (a1 <= 0x280)
            idx = m_d8[(a1 + 0xf) >> 4];
        else
            idx = m_104[(a1 - 1) >> 10];
        a1 = m_94[idx];
    }
    return unk04->v2c(aiArg, a1);
}

struct Allocator219
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* out, int blockSize);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(void** batch, int count, int blockSize);
};

struct Node219
{
    Node219* next;
};

struct CacheSlot219
{
    Node219* head;
    int count;
    inline Node219* Pop()
    {
        if (head)
        {
            Node219* p = head;
            --count;
            head = p->next;
            return p;
        }
        return 0;
    }
};

struct Owner219
{
    void* owner;
    Allocator219* allocator;
    int batchThreshold;
    CacheSlot219 caches[17];
    int blockSizes[17];

    void hkThreadMemory_onRowFull(int index, Node219* out);
};
// Uses blockSizes[index] to release out directly when batchThreshold is zero; otherwise trims cache batches and pushes out onto its head.
// @fnv 0x00d2c450
// src: HAVOK_LIB 0x00d2c450
void Owner219::hkThreadMemory_onRowFull(int aiSizeIndex, Node219* apBlock)
{
    int blockSize = blockSizes[aiSizeIndex];
    int threshold = batchThreshold;
    if (threshold == 0)
    {
        allocator->v2(apBlock, blockSize);
        return;
    }
    CacheSlot219* slot = caches + aiSizeIndex;
    int count = slot->count;
    int half = threshold / 2;
    while (count > half)
    {
        int n = count - half <= 4 ? count - half : 4;
        Node219* batch[4];
        for (int i = 0; i < n; i++)
            batch[i] = slot->Pop();
        count -= n;
        allocator->v7((void**)batch, n, blockSize);
    }
    Node219* head = caches[aiSizeIndex].head;
    caches[aiSizeIndex].count++;
    apBlock->next = head;
    caches[aiSizeIndex].head = apBlock;
}

extern "C" char DAT_010cacd0;

struct BlockEntry
{
    void* block;
    void* size;
};

struct ThreadMemoryBase
{
    void* m0;
    void* m4;
    void* m8;
    void hkThreadMemory_setMemory(void* a, void* b);
};

struct HKThreadMemory : ThreadMemoryBase
{
    BlockEntry blocks[17];
    int blockTable[17];
    unsigned char freeList[0x29];
    int bigBlocks[8];
    void InitSizeClasses();
    HKThreadMemory* hkThreadMemory_hkThreadMemory();
};

// src: HAVOK_LIB 0x00d2c3a0
__declspec(noinline) void ThreadMemoryBase::hkThreadMemory_setMemory(void* a, void* b)
{
    if (a)
    {
        m4 = a;
        m8 = b;
    }
    else
    {
        m4 = 0;
    }
}

__declspec(noinline) void HKThreadMemory::InitSizeClasses()
{
    for (int i = 0; i <= 0x28; i++)
    {
        int size = i << 4;
        int cls;
        if (size <= 0x10)
            cls = 1;
        else if (size <= 0x20)
            cls = 2;
        else if (size <= 0x30)
            cls = 3;
        else if (size <= 0x40)
            cls = 4;
        else if (size <= 0x60)
            cls = 5;
        else if (size <= 0x80)
            cls = 6;
        else if (size <= 0xa0)
            cls = 7;
        else if (size <= 0xc0)
            cls = 8;
        else if (size <= 0x100)
            cls = 9;
        else if (size <= 0x140)
            cls = 10;
        else if (size <= 0x200)
            cls = 11;
        else if (size <= 0x280)
            cls = 12;
        else if (size <= 0x400)
            cls = 13;
        else if (size <= 0x800)
            cls = 14;
        else if (size <= 0x1000)
            cls = 15;
        else
            cls = 16;
        freeList[i] = (unsigned char)cls;
        blockTable[cls] = size;
    }
    for (int i = 0; i < 8; i++)
    {
        int size = 0x400 + i * 0x400;
        int cls;
        if (size <= 0x10)
            cls = 1;
        else if (size <= 0x20)
            cls = 2;
        else if (size <= 0x30)
            cls = 3;
        else if (size <= 0x40)
            cls = 4;
        else if (size <= 0x60)
            cls = 5;
        else if (size <= 0x80)
            cls = 6;
        else if (size <= 0xa0)
            cls = 7;
        else if (size <= 0xc0)
            cls = 8;
        else if (size <= 0x100)
            cls = 9;
        else if (size <= 0x140)
            cls = 10;
        else if (size <= 0x200)
            cls = 11;
        else if (size <= 0x280)
            cls = 12;
        else if (size <= 0x400)
            cls = 13;
        else if (size <= 0x800)
            cls = 14;
        else if (size <= 0x1000)
            cls = 15;
        else
            cls = 16;
        bigBlocks[i] = cls;
        blockTable[cls] = size;
    }
}

// Sets m0, clears 17 block entries, calls FUN_00d2c100 and FUN_00d2c3a0(0, 8), then returns this.
// @fnv 0x00d2c720
// src: HAVOK_LIB 0x00d2c720
HKThreadMemory* HKThreadMemory::hkThreadMemory_hkThreadMemory()
{
    m0 = &DAT_010cacd0;
    BlockEntry* p = blocks;
    int n = 16;
    while (n >= 0)
    {
        p->block = 0;
        p->size = 0;
        ++p;
        --n;
    }
    InitSizeClasses();
    hkThreadMemory_setMemory(0, (void*)8);
    return this;
}

namespace fnv_00d2c760 {
extern "C" char DAT_010cacd0;

struct BlockEntry
{
    void* block;
    int count;
    BlockEntry() : block(0), count(0)
    {}
};

struct ThreadMemoryView : FUN_00d2c3a0_class
{
    BlockEntry blocks[17];
    int blockTable[17];
    unsigned char freeList[41];
    int bigBlocks[8];
    void InitSizeClasses();
    void hkThreadMemory_setMemory(void* allocator, int limit);
    ThreadMemoryView* hkThreadMemory_hkThreadMemory_00d2c760(void* allocator);
};

// src: HAVOK_LIB 0x00d2c3a0
__declspec(noinline) void ThreadMemoryView::hkThreadMemory_setMemory(void* allocator, int limit)
{
    FUN_00d2c3a0_class::hkThreadMemory_setMemory(allocator, (void*)limit);
}

__declspec(noinline) void ThreadMemoryView::InitSizeClasses()
{
    ((SizeClassTable*)this)->InitSizeClasses();
}

// Zeroes the 17 BlockEntry slots, calls FUN_00d2c100 and FUN_00d2c3a0(allocator, 8), then returns this.
// @fnv 0x00d2c760
// src: HAVOK_LIB 0x00d2c760
ThreadMemoryView* ThreadMemoryView::hkThreadMemory_hkThreadMemory_00d2c760(void* allocator)
{
    m0 = &DAT_010cacd0;
    BlockEntry* entry = blocks;
    int remaining = 16;
    do
    {
        entry->block = 0;
        entry->count = 0;
        ++entry;
    } while (--remaining >= 0);
    InitSizeClasses();
    hkThreadMemory_setMemory(allocator, 8);
    return this;
}
}  // namespace fnv_00d2c760
