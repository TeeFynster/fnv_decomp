#pragma once
#include <stddef.h>

class NiMemObject
{
  public:
    static void* operator new(size_t size);
    // Only the sized usual deallocation function exists (0x00aa1460): deleting destructors (NiRefObject 0x004968e0,
    // NiNode 0x00a5ece0, NiExtraData 0x00a7b400) and new-expression unwinds push the object size.
    static void operator delete(void* p, size_t stElementSize);
    static void* operator new[](size_t size);                       // 0x00aa1420
    static void operator delete[](void* p, size_t stElementSize);   // 0x00aa1490 (callers push two arguments)

    // Placement new (class-scope allocators hide the global one). No matching placement delete: placement
    // new-expressions in the exe (0x00a99f60, 0x00a81fb0, 0x00c285d0) have no cleanup for it.
    static void* operator new(size_t, void* p)
    {
        return p;
    }
    static void* operator new[](size_t, void* p)
    {
        return p;
    }
};
