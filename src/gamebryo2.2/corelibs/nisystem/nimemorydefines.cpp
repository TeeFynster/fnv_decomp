// gamebryo2.2/corelibs/nisystem/nimemorydefines.cpp: NiFixedAllocator (8 functions)

#include "../../../../include/NiAllocator.h"
#include "nimemorydefines_decls.h"

void* NiAlignedAlloc(unsigned int size, unsigned int alignment);

void* _NiMalloc(unsigned int size);

// @fnv 0x00aa1170
void FreeAlignedBlock(void* apBlock)
{
    if (apBlock)
    {
        NiAllocator* a = DAT_011f6080->allocator;
        a->Free(apBlock, 0xf, -1);
    }
}

namespace fnv_00aa1190 {
// @fnv 0x00aa1190
void FreeAllocatorBlock(void* apBlock)
{
    if (apBlock)
    {
        NiAllocator* a = DAT_011f6080->allocator;
        a->Free(apBlock, 0x10, -1);
    }
}
}  // namespace fnv_00aa1190

extern NiMemoryManagerState* DAT_011f6080;

// @fnv 0x00aa1070
// src: XBOX_PDB 0x00aa1070
void* _NiMalloc_00aa1070(unsigned int uiSize)
{
    unsigned int size;
    *(volatile unsigned int*)&size = uiSize != 0 ? uiSize : 1;
    NiAllocator* alloc = DAT_011f6080->allocator;
    uiSize = 4;
    return alloc->vfn_04(size, uiSize, 5, false, 0, -1, 0);
}


// Allocates a block of at least uiSize bytes with uiAlignment through the global allocator.
// @fnv 0x00aa1130
// src: COMMUNITY 0x00aa1130
void* __cdecl NiExternalAlignedMalloc(unsigned int uiSize, unsigned int uiAlignment)
{
    unsigned int size = uiSize != 0 ? uiSize : 1;
    uiSize = uiAlignment;
    NiAllocator* alloc = DAT_011f6080->allocator;
    uiAlignment = size;

    return alloc->Allocate(uiAlignment, uiSize, 13, false, 0, -1, 0);
}


// @fnv 0x00aa1250
// src: COMMUNITY 0x00aa1250
void* NiExternalAlignedRealloc(void* apMemory, unsigned int size, unsigned int alignment)
{
    unsigned int uiOldSize;
    NiAllocator* pAllocator;
    if (size == 0 && apMemory != 0)
    {
        pAllocator = DAT_011f6080->allocator;
        pAllocator->Free(apMemory, 0x10, -1);
        return 0;
    }
    if (apMemory == 0)
    {
        unsigned int r = size;
        if (r == 0)
            r = 1;
        size = alignment;
        pAllocator = DAT_011f6080->allocator;
        uiOldSize = r;
        return pAllocator->Allocate(uiOldSize, size, 0xd, false, 0, -1, 0);
    }
    uiOldSize = size;
    size = alignment;
    pAllocator = DAT_011f6080->allocator;
    return pAllocator->Realloc(apMemory, uiOldSize, size, 0xe, 0, -1, 0, -1, 0);
}

struct MemoryAllocationManager
{
    NiAllocator* m_pHeapAllocator;
    static MemoryAllocationManager* GetMemManager()
    {
        return (MemoryAllocationManager*)DAT_011f6080;
    }
    void* Allocate(unsigned int stSizeInBytes, unsigned int stAlignment, int aiAllocationType,
                   bool bProvideAccurateSizeOnDeallocate, const char* pcSourceFile, int iSourceLine,
                   const char* pcFunction)
    {
        return m_pHeapAllocator->vfn_04(stSizeInBytes, stAlignment, aiAllocationType, bProvideAccurateSizeOnDeallocate,
                                        pcSourceFile, iSourceLine, pcFunction);
    }
};

// Allocates stSizeInBytes (minimum 1) with stAlignment via the global memory manager, using allocation type 7.
// @fnv 0x00aa10b0
// src: COMMUNITY 0x00aa10b0
void* NiAlignedAlloc_00aa10b0(unsigned int stSizeInBytes, unsigned int stAlignment)
{
    if (stSizeInBytes == 0)
        stSizeInBytes = 1;
    return MemoryAllocationManager::GetMemManager()->Allocate(stSizeInBytes, stAlignment, 7, false, 0, -1, 0);
}

struct ReallocMemMgr
{
    NiAllocator* m_pHeapAllocator;
    static ReallocMemMgr* Get()
    {
        return (ReallocMemMgr*)DAT_011f6080;
    }
    void* Allocate(unsigned int stSizeInBytes, unsigned int stAlignment, int aiAllocationType, bool bAccurate,
                   const char* pcFile, int iLine, const char* pcFunction)
    {
        return m_pHeapAllocator->Allocate(stSizeInBytes, stAlignment, aiAllocationType, bAccurate, pcFile, iLine,
                                       pcFunction);
    }
    void* Reallocate(void* pvMem, unsigned int stSizeInBytes, unsigned int stAlignment, int aiAllocationType,
                     bool bAccurate, unsigned int stSizeCurrent, const char* pcFile, int iLine, const char* pcFunction)
    {
        return m_pHeapAllocator->Realloc(pvMem, stSizeInBytes, stAlignment, aiAllocationType, bAccurate, stSizeCurrent,
                                         (int)pcFile, iLine, (int)pcFunction);
    }
    void Deallocate(void* pvMem, int aiAllocationType, unsigned int stSizeinBytes)
    {
        m_pHeapAllocator->Free(pvMem, aiAllocationType, stSizeinBytes);
    }
};

static inline void InlFree(void* pvMem)
{
    if (pvMem == 0)
        return;
    ReallocMemMgr::Get()->Deallocate(pvMem, 0xf, (unsigned int)-1);
}
static inline void* InlMalloc(unsigned int stSizeInBytes)
{
    if (stSizeInBytes == 0)
        stSizeInBytes = 1;
    return ReallocMemMgr::Get()->Allocate(stSizeInBytes, 4, 0xb, false, 0, -1, 0);
}

// Frees a nonnull pvMem when size is zero, allocates when pvMem is null, otherwise reallocates it to the requested size.
// @fnv 0x00aa11b0
void* __cdecl InlRealloc(void* pvMem, unsigned int stSizeInBytes)
{
    if (stSizeInBytes == 0 && pvMem != 0)
    {
        InlFree(pvMem);
        return 0;
    }
    else if (pvMem == 0)
    {
        return InlMalloc(stSizeInBytes);
    }
    return ReallocMemMgr::Get()->Reallocate(pvMem, stSizeInBytes, 4, 0xc, false, (unsigned int)-1, 0, -1, 0);
}

#include <windows.h>
void* ChunkAlignedAlloc(unsigned int size, unsigned int alignment);
void* ChunkRealloc(void* p, unsigned int size);

struct FixedChunk
{
    unsigned char* pData;
    unsigned char firstAvailable;
    unsigned char blocksAvailable;

    void Init(unsigned int blockSize, unsigned char blocks)
    {
        pData = (unsigned char*)ChunkAlignedAlloc(blockSize * blocks, 4);
        firstAvailable = 0;
        blocksAvailable = blocks;
        unsigned char i = 0;
        unsigned char* p = pData;
        for (; i != blocks; p += blockSize)
            *p = ++i;
    }

    void* Allocate(unsigned int blockSize)
    {
        if (!blocksAvailable)
            return 0;
        unsigned char* result = pData + firstAvailable * blockSize;
        firstAvailable = *result;
        --blocksAvailable;
        return result;
    }
};

// 0x00aa35a0 is NiFixedAllocator::Allocate; retain its local layout until include/NiFixedAllocator.h exists.
struct NiFixedAllocator
{
    unsigned int blockSize;
    unsigned char numBlocks;
    FixedChunk* chunks_data;
    unsigned int chunks_count;
    unsigned int chunks_capacity;
    FixedChunk* allocChunk;
    FixedChunk* deallocChunk;
    FixedChunk* emptyChunk;
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
    CRITICAL_SECTION cs;

    void* Allocate();
};

// Locks cs, picks or creates a FixedChunk with free blocks, allocates one block from it, and returns the block pointer.
// @fnv 0x00aa35a0
void* NiFixedAllocator::Allocate()
{
    EnterCriticalSection(&cs);
    if (allocChunk && allocChunk->blocksAvailable == 0)
        allocChunk = 0;
    if (emptyChunk)
    {
        allocChunk = emptyChunk;
        emptyChunk = 0;
    }
    if (allocChunk == 0)
    {
        for (unsigned int i = 0; i < chunks_count; ++i)
        {
            if (chunks_data[i].blocksAvailable)
            {
                allocChunk = &chunks_data[i];
                break;
            }
        }
        if (allocChunk == 0)
        {
            unsigned int idx = chunks_count;
            unsigned int n = idx + 1;
            if (n > chunks_capacity)
            {
                chunks_data = (FixedChunk*)ChunkRealloc(chunks_data, n * sizeof(FixedChunk));
                chunks_capacity = n;
            }
            FixedChunk c;
            c.Init(blockSize, numBlocks);
            idx = chunks_count;
            n = idx + 1;
            if (n > chunks_capacity)
            {
                chunks_data = (FixedChunk*)ChunkRealloc(chunks_data, n * sizeof(FixedChunk));
                chunks_capacity = n;
            }
            chunks_data[idx] = c;
            ++chunks_count;
            allocChunk = &chunks_data[chunks_count - 1];
            deallocChunk = &chunks_data[0];
        }
    }
    void* result = allocChunk->Allocate(blockSize);
    LeaveCriticalSection(&cs);
    return result;
}
