#pragma once

#include <cstddef>
#include "hkMemoryAllocator.h"
#include "hkStackMemory.h"

class hkOstream;

// Havok 7.1 Common/Base/Memory/Router/hkMemoryRouter.h: the per-thread memory router, 0x24 bytes (m_stack, then the
// temp, heap, debug, solver and global allocators and m_userData). getInstance is 0x00c85750 (Xbox PDB), the
// constructor 0x00c85770. The accessors are inline in the class as in Havok.
// src: HAVOK_SRC (class name, member names, layout and method list; getInstance at 0x00c85750 per src: XBOX_PDB)
class hkMemoryRouter
{
public:
    typedef hkMemoryAllocator Allocator;
    static void* __cdecl operator new(std::size_t, void* pWhere);   // placement form only

    static hkMemoryRouter* __cdecl getInstancePtr();
    static hkMemoryRouter& __cdecl getInstance();
    static void __cdecl replaceInstance(hkMemoryRouter* pRouter);

    hkMemoryRouter();
    void resetPeakMemoryStatistics();

    // allocator slots: setters first, then the reference getters the units inline
    inline void setTemp(Allocator* pAlloc) { m_temp = pAlloc; }
    inline void setHeap(Allocator* pAlloc) { m_heap = pAlloc; }
    inline void setDebug(Allocator* pAlloc) { m_debug = pAlloc; }
    inline void setSolver(Allocator* pAlloc) { m_solver = pAlloc; }
    inline void setGlobal(Allocator* pAlloc) { m_global = pAlloc; }
    inline void setUserData(void* pData) { m_userData = pData; }
    inline hkStackMemory& stack() { return m_stack; }
    inline Allocator& heap() { return *m_heap; }
    inline Allocator& temp() { return *m_temp; }
    inline Allocator& debug() { return *m_debug; }
    inline Allocator& solver() { return *m_solver; }
    inline Allocator& global() { return *m_global; }
    inline void* getUserData() const { return m_userData; }

    // helpers over any allocator (aligned forms keep the offset in front of the block)
    static void* __cdecl easyAlloc(Allocator& kFrom, int iBytes);
    static void __cdecl easyFree(Allocator& kFrom, void* pMem);
    static void* __cdecl alignedAlloc(Allocator& kFrom, int iBytes, int iAlignment);
    static void __cdecl alignedFree(Allocator& kFrom, void* pMem);

    // src: HAVOK_SRC: data members and order; protected in Havok, public here because the units read the allocator
    // pointers directly
    hkStackMemory m_stack;   // +0x00
    Allocator* m_temp;       // +0x0c
    Allocator* m_heap;       // +0x10
    Allocator* m_debug;      // +0x14
    Allocator* m_solver;     // +0x18
    Allocator* m_global;     // +0x1c
    void* m_userData;        // +0x20
};
