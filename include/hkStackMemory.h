#pragma once

#include "hkPadSpu.h"

// Havok 7.1 Common/Base/Memory/Util/Stack/hkStackMemory.h: the per-thread stack allocator (hkMemoryRouter::m_stack),
// three hkPadSpu<void*> pointers, 12 bytes on PC. Declarations only: a unit whose original inlines a body defines it
// out of class (Havok makes all but allocateStack HK_FORCE_INLINE; the four getters are inline in its class).
// src: HAVOK_SRC (struct name, member names, layout and method list)
struct hkStackMemory
{
public:
    hkStackMemory();
    // ~hkStackMemory is HK_FORCE_INLINE and empty in Havok: not declared, so holders keep a trivial destructor
    static hkStackMemory& getInstance();

    void initMemory(void* p, int size);
    void* allocateStackRoundSizeTo128(int numBytes, const char* what);
    void* allocateStackRoundSizeTo128WithCriticalAssert(int numBytes, const char* what);
    void* allocateStack(int numBytes, const char* what);
    void shrinkAllocatedStack(void* p, int newSize);
    void deallocateStack(void* p);
    void deallocateStack(int numBytes);
    int getFreeStackSize();
    const void* getStackStart();
    const void* getStackEnd();
    const void* getStackNext();

    // src: HAVOK_SRC: data members; protected in Havok, public here because the units read and write them directly
    hkPadSpu<void*> m_next;
    hkPadSpu<void*> m_start;
    hkPadSpu<void*> m_end;
};
