// bscore/memorymanager.cpp: MemoryManager, TESQuest, TESActorBaseData, Actor and more (21 functions)

#include "memorymanager_identity.h"
#include "../../include/MemoryManager.h"
#include "../../include/MemoryPool.h"
#include "memorymanager_memory.h"
#include "../../include/Actor.h"
#include "../../include/BSExtraData.h"
#include "../../include/BaseExtraList.h"
#include "../../include/ExtraDataList.h"
#include "../../include/ExtraHealth.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESFile.h"
#include "../../include/TESQuest.h"
#include "../../include/AutoMemContext.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// @fnv 0x00aa4150
void* MemoryManager::Reallocate(void* apBlock, unsigned int size)
{
    void* allocation = 0;
    unsigned int copySize = Size(apBlock);
    if (copySize)
    {
        allocation = Allocate(size);
        if (copySize > size)
            copySize = size;
        memmove(allocation, apBlock, copySize);
        Deallocate(apBlock);
    }
    else
    {
        void* resized = apBlock;
        resized = realloc(resized, size);
        allocation = resized;
    }
    return allocation;
}

// Returns the allocation size of a pointer by checking the owning MemoryPool, then the heap for the pointer or its physical address, falling back to _msize.
// @fnv 0x00aa44c0
unsigned int MemoryManager::Size(const void* pointer)
{
    unsigned int size;
    MemoryPool* pool = MemoryPool::ms_pPoolAddressMap[reinterpret_cast<size_t>(pointer) >> kPoolAddressRegionShift];
    if (pool && pool->PointerInPool(pointer))
        size = pool->GetBlockSize();
    else
    {
        IMemoryHeap* heap = GetHeapForPointer(pointer);
        if (heap)
            size = heap->Size(pointer, 0);
        else
        {
            heap = GetHeapForPhysicalPointer(pointer);
            if (heap)
                size = heap->Size(pointer, 0);
            else
            {
                unsigned int systemSize = 0;
                systemSize = _msize(const_cast<void*>(pointer));
                size = systemSize;
            }
        }
    }
    return size;
}

// @fnv 0x005f5760
PerkEntryConditionSet* TESQuest::GetConditions()
{
    return &m_kInfoConditions;
}

// @fnv 0x00461580
bool TESActorBaseData::GetFlag(unsigned int flag) const
{
    return actorData.m_uiActorFlags & flag;
}

// @fnv 0x0087f4c0
SEX Actor::GetSex()
{
    return GetActorBase()->GetSex();
}

// Sets the ExtraHealth extra data value to health, creating and adding a new ExtraHealth if none exists.
// @fnv 0x00419970
void ExtraDataList::SetExtraHealth(float health)
{
    ExtraHealth* extra = static_cast<ExtraHealth*>(BaseExtraList::GetExtraData(0x25));
    if (extra)
        extra->fHealthPercent = health;
    else
    {
        extra = new ExtraHealth(health);
        AddExtra(extra);
    }
}

MemoryManager* MemoryManager_Instance();
// @fnv 0x0042f5d0
void* Reallocate(void* pointer, unsigned int size)
{
    return MemoryManager_Instance()->Reallocate(pointer, size);
}

// Looks up the scrap heap for the current thread ID, creating and storing a new one if none exists, and returns it.
// @fnv 0x00aa42e0
ScrapHeapBuffer* MemoryManager::GetGeneralAllocator()
{
    unsigned long threadID = GetCurrentThreadId();
    ScrapHeapBuffer* heap = 0;
    reinterpret_cast<BSMapBase<unsigned long, ScrapHeapBuffer*>*>(&kThreadScrapHeapMap)->GetAt(threadID, heap);
    if (!heap)
    {
        heap = new ScrapHeapBuffer;
        reinterpret_cast<BSMapBase<unsigned long, ScrapHeapBuffer*>*>(&kThreadScrapHeapMap)->SetAt(threadID, heap);
    }
    return heap;
}

void __cdecl Deallocate(void*);

// If the pointer at offset 0x420 is non-null, deallocates it and clears the pointer and the count at offset 0x424.
// @fnv 0x00473960
void TESFile::ClearDecompressedFormBuffer()
{
    if (m_pDecompressedFormBuffer != 0)
    {
        Deallocate(m_pDecompressedFormBuffer);
        m_pDecompressedFormBuffer = 0;
        m_uiAuxBufferSize = 0;
    }
}

extern __declspec(thread) int g_tlsMemContext;
struct MemCtxGuard
{
    int iOld;
    static int GetCtx()
    {
        return g_tlsMemContext;
    }
    static void SetCtx(int c)
    {
        g_tlsMemContext = c;
    }
    MemCtxGuard(int c)
    {
        iOld = GetCtx();
        SetCtx(c);
    }
    ~MemCtxGuard()
    {
        SetCtx(iOld);
    }
};
// Creates a MemoryPool with the given block and pool sizes and description, deleting it if it has no memory; returns early when aiBlockSize is below 8.
// @fnv 0x00aa3cc0
void MemoryManager::CreateMemoryPool(unsigned int aiBlockSize, unsigned int aiPoolSize, const char* apDesc)
{
    MemCtxGuard tempMemContext(3);
    if (aiBlockSize < 8)
        return;
    m_bPoolAllocationEnabled = false;
    MemoryPool* pnewPool = new MemoryPool(aiBlockSize, aiPoolSize, apDesc);
    if (!pnewPool->IsHeapValid())
    {
        delete pnewPool;
    }
    m_bPoolAllocationEnabled = true;
}

struct FUN_00aa3a10_tls_struct
{
    unsigned char pad[0x2b4];
    unsigned int flag;
};

__declspec(thread) FUN_00aa3a10_tls_struct g_fun_tls;

// Clears the TLS flag and sets the first byte of this object to 1.
// @fnv 0x00aa3a10
void MemoryManager::InitializeStandard()
{
    g_fun_tls.flag = 0;
    bInitialized = true;
}

// These APIs use this unit's alternate import slots in the game image.
namespace memorymanager_imports {
__declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
}
extern _RTL_CRITICAL_SECTION DAT_011f6234;
// @fnv 0x00aa4460
// src: COMMUNITY 0x00aa4460
void MemoryManager_EnableDelayedFree()
{
    memorymanager_imports::EnterCriticalSection(&DAT_011f6234);
}

// @fnv 0x00aa4470
// src: COMMUNITY 0x00aa4470
void MemoryManager_DisableDelayedFree()
{
    memorymanager_imports::LeaveCriticalSection(&DAT_011f6234);
}

extern char DAT_011f6230;

// @fnv 0x00aa4480
// src: COMMUNITY 0x00aa4480
void MemoryManager_SetCheckMemOnFree(unsigned char value)
{
    DAT_011f6230 = value;
}

namespace fnv_00aa4490 {
extern unsigned int DAT_011f6234;

// @fnv 0x00aa4490
// src: COMMUNITY 0x00aa4490
bool MemoryManager_GetDelayedFreeEnabled()
{
    if (DAT_011f6234 > 0)
        return true;
    return false;
}
}  // namespace fnv_00aa4490

extern char DAT_011f6230;

// @fnv 0x00aa44b0
// src: COMMUNITY 0x00aa44b0
char __cdecl MemoryManager_GetCheckMemOnFree()
{
    return DAT_011f6230;
}

// Returns the entry at index from tableA if index < iNumHeaps, otherwise from tableB at index - countA when that offset is < countB; returns 0 otherwise.
// @fnv 0x00aa46a0
void* MemoryManager::GetEntryAt(unsigned int index)
{
    void* pEntry = 0;
    if (index < iNumHeaps)
    {
        pEntry = ppHeaps[index];
    }
    else if (index - iNumHeaps < iNumPhysicalHeaps)
    {
        pEntry = ppPhysicalHeaps[index - iNumHeaps];
    }
    return pEntry;
}

extern "C" int _tls_index;
struct FUN_00aa39c0_tls
{
    unsigned char unk0000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00aa39c0_tls g_tls;

void ClearMemoryPoolTables();

// Calls ClearMemoryPoolTables, InitializeHeaps, FUN_00866770 and FUN_00483710, sets m_00 to 1 and clears g_tls.m_2b4.
// @fnv 0x00aa39c0
void MemoryManager::Initialize()
{
    ClearMemoryPoolTables();
    InitializeHeaps();
    bInitialized = true;
    SpecifyPools();
    FUN_00483710();
    g_tls.m_2b4 = 0;
}

extern MemoryManager DAT_011f6238;
extern unsigned short DAT_011f623a;
extern unsigned short DAT_011f623c;
struct S_00aa4400_Obj
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
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
};
inline int S_Sum(int a, int b)
{
    return a + b;
}
inline int S_Sum(unsigned short a, unsigned short b)
{
    return a + b;
}
// Sums DAT_011f623a and DAT_011f623c, then for each index up to that sum fetches an object from DAT_011f6238 and calls its v0b virtual method.
// @fnv 0x00aa4400
void CallVirtualOnEachElement()
{
    int iTotal = S_Sum(DAT_011f623a, DAT_011f623c);
    S_00aa4400_Obj* pElement;
    for (int i = 0; i < iTotal; i++)
    {
        pElement = (S_00aa4400_Obj*)DAT_011f6238.GetEntryAt(i);
        pElement->v0b();
    }
}

__forceinline void operator delete[](void* p)
{
    g_memoryManager.Deallocate(p);
}
struct ScrapView
{
    ~ScrapView();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct HeapView
{
    virtual ~HeapView();
};
struct WeightedMapNode
{
    WeightedMapNode* unk00;
};
struct MapView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(WeightedMapNode*);
    virtual void slot5();
    virtual void slot6(WeightedMapNode*);
    unsigned int unk04;
    WeightedMapNode** unk08;
    void* unk0C;
    ~MapView();
    __forceinline WeightedMapNode* First()
    {
        for (unsigned int i = 0; i < unk04; ++i)
        {
            if (unk08[i])
                return unk08[i];
        }
        return 0;
    }
    void FUN_00a0c850(WeightedMapNode*&, unsigned long&, ScrapView*&);
    inline void ClearAll()
    {
        for (unsigned int bucket = 0; bucket < unk04; ++bucket)
        {
            while (unk08[bucket])
            {
                WeightedMapNode* node = unk08[bucket];
                unk08[bucket] = unk08[bucket]->unk00;
                slot4(node);
                slot6(node);
            }
        }
        unk0C = 0;
    }
};
inline void FreeArray(void* p)
{
    g_memoryManager.Deallocate(p);
}
struct FUN_00aa5950_s
{
    ~FUN_00aa5950_s();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
extern FUN_00aa5950_s* DAT_011f63b4;
// src: COMMUNITY 0x00aa5950
inline void ScrapHeapManager_Shutdown()
{
    delete DAT_011f63b4;
    DAT_011f63b4 = 0;
}
extern MemoryPool* DAT_011f67b8[256];
inline void DestroyMemoryPools()
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        delete DAT_011f67b8[i];
        DAT_011f67b8[i] = 0;
    }
}
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
// @fnv 0x00aa3a40
MemoryManager::~MemoryManager()
{
    WeightedMapNode* position = reinterpret_cast<MapView*>(&kThreadScrapHeapMap)->First();
    unsigned long key;
    ScrapView* heap;
    while (position)
    {
        reinterpret_cast<MapView*>(&kThreadScrapHeapMap)->FUN_00a0c850(position, key, heap);
        delete heap;
    }
    reinterpret_cast<MapView*>(&kThreadScrapHeapMap)->ClearAll();
    ScrapHeapManager_Shutdown();
    FUN_00483710();
    DestroyMemoryPools();
    fnv_zlib_memset(pHeapsByContextA, 0, 0x108);
    bInitialized = false;
    if (ppHeaps)
    {
        for (unsigned short i = 0; i < iNumHeaps; ++i)
        {
            delete ppHeaps[i];
            ppHeaps[i] = 0;
        }
        delete[] ppHeaps;
    }
    if (ppPhysicalHeaps)
    {
        for (unsigned short j = 0; j < iNumPhysicalHeaps; ++j)
        {
            delete ppPhysicalHeaps[j];
            ppPhysicalHeaps[j] = 0;
        }
        delete[] ppPhysicalHeaps;
    }
}

namespace fnv_00aa43a0 {
void __cdecl MemoryPool_CheckPools();

class ItemAA43
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void Update();
};

}  // namespace fnv_00aa43a0

// Calls FUN_00aa7370, then iterates over all entries and calls Update on each ItemAA43.
// @fnv 0x00aa43a0
// src: COMMUNITY 0x00aa43a0
void MemoryManager::CheckMemoryIntegrity_00aa43a0(int unused)
{
    fnv_00aa43a0::MemoryPool_CheckPools();
    fnv_00aa43a0::ItemAA43* pkItem;
    int ItemUpdateArray = GetCount();
    for (int i = 0; i < ItemUpdateArray; i++)
    {
        pkItem = (fnv_00aa43a0::ItemAA43*)GetEntryAt(i);
        pkItem->Update();
    }
}
