// bscore/abstractheap_decls.h: block helpers, logging and platform imports
#ifndef ABSTRACTHEAP_DECLS_H
#define ABSTRACTHEAP_DECLS_H

#include "layout_support.h"
#include "../../include/AbstractHeap.h"

class MemoryHeapType;
class MemoryBlockHeader
{
  public:
    MemoryBlockHeader* m_pPreviousBlock;
    unsigned int m_uiSizeAndFlags;
    __forceinline unsigned int GetSize()
    {
        return m_uiSizeAndFlags & 0x0fffffff;
    }
    __forceinline unsigned int GetTotalSize()
    {
        unsigned int size = GetSize();
        return size + sizeof(MemoryBlockHeader);
    }
    __forceinline void SetSize(unsigned int size)
    {
        m_uiSizeAndFlags = size | (m_uiSizeAndFlags & 0xf0000000);
    }
    __forceinline bool IsDecommitted()
    {
        return (m_uiSizeAndFlags & 0x20000000) != 0;
    }
    __forceinline void SetDecommitted(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x20000000;
        else
            m_uiSizeAndFlags &= ~0x20000000;
    }
    __forceinline void SetPrevious(MemoryBlockHeader* previous)
    {
        m_pPreviousBlock = previous;
    }
    void SetFlags(unsigned int, MemoryHeapType*);
    __forceinline void SetFree(bool value)
    {
        if (value)
            m_uiSizeAndFlags |= 0x40000000;
        else
            m_uiSizeAndFlags &= ~0x40000000;
    }
    __forceinline bool IsFree()
    {
        return (m_uiSizeAndFlags & 0x40000000) != 0;
    }
    __forceinline MemoryBlockHeader* GetPrevious()
    {
        return m_pPreviousBlock;
    }
    __forceinline MemoryBlockHeader* GetNext()
    {
        unsigned int size = GetSize();
        return (MemoryBlockHeader*)((char*)this + size + sizeof(MemoryBlockHeader));
    }
};
class HeapFreeBlock : public MemoryBlockHeader
{
  public:
    HeapFreeBlock* m_pNextFree;
    HeapFreeBlock* m_pPrevFree;
    __forceinline void SetNextFree(HeapFreeBlock* block)
    {
        m_pNextFree = block;
    }
    __forceinline void SetPrevFree(HeapFreeBlock* block)
    {
        m_pPrevFree = block;
    }
    void RemoveFromFreeList();
};

class AbstractHeapLogger;
extern AbstractHeapLogger* DAT_011f6388;
class AbstractHeapLogger
{
  public:
    static __forceinline AbstractHeapLogger* Get()
    {
        return DAT_011f6388;
    }
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(int, const char*, int, int, int);
};
__forceinline bool AbstractHeapHasLog()
{
    return DAT_011f6388 != 0;
}
extern "C"
{
    extern void(__stdcall* fnv_EnterCriticalSection)(void*);
    extern void(__stdcall* fnv_LeaveCriticalSection)(void*);
    __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned int, unsigned int, unsigned int);
    int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
}

FNV_STATIC_ASSERT(sizeof(MemoryBlockHeader) == 8);
FNV_STATIC_ASSERT(offsetof(MemoryBlockHeader, m_uiSizeAndFlags) == 4);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, pBlockTail) == 0x3c);
FNV_STATIC_ASSERT(sizeof(HeapFreeBlock) == 16);
FNV_STATIC_ASSERT(sizeof(HeapFreeList) == 8);
FNV_STATIC_ASSERT(sizeof(HeapBlockList) == 8);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, pSmallFreeList) == 0x44);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, LargeFreeList) == 0x2048);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, pSubBuckets) == 0x2058);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, CriticalSectionO) == 0x20d8);
#endif
