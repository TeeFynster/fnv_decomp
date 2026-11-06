// Source layout: MemoryManager. PC corrections are in generate_headers.py.
#ifndef FNV_MEMORYMANAGER_H
#define FNV_MEMORYMANAGER_H

#include <stddef.h>
#include "../../include/MemoryPool.h"
#include "IMemoryHeap.h"
// the shared MemoryPool only declares these; the original inlines them here
__forceinline bool MemoryPool::IsHeapValid()
{
    return m_pPoolBase != 0;
}
__forceinline bool MemoryPool::PointerInPool(const void* pointer)
{
    return static_cast<const char*>(pointer) >= m_pPoolBase && static_cast<const char*>(pointer) < m_pPoolBase + m_uiPoolSize;
}
__forceinline unsigned int MemoryPool::GetBlockSize()
{
    return m_uiAllocationSize;
}
class ScrapHeapBuffer
{
  public:
    char data[16];
    ScrapHeapBuffer();
    static __forceinline void* operator new(size_t size);
    static __forceinline void operator delete(void* p);
};
template <class K, class V> class BSMapBase
{
  public:
    char data[16];
    bool GetAt(K, V&);
    void SetAt(K, V);
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

extern MemoryManager g_memoryManager;
enum
{
    kMinimumPoolBlockSize = 8,
    kPoolAddressRegionShift = 24
};
__forceinline MemoryManager& MemoryManager::Instance()
{
    return g_memoryManager;
}
__forceinline void* operator new(size_t size)
{
    return g_memoryManager.Allocate(size);
}
__forceinline void operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}

__forceinline void* ScrapHeapBuffer::operator new(size_t size)
{  // Preserve five unused allocator-local slots from the original PC build.
    struct Reserved
    {
        unsigned int slots[5];
    };
    Reserved reserved;
    return g_memoryManager.Allocate(size);
}
__forceinline void ScrapHeapBuffer::operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}


#endif
