#pragma once

#include <cstddef>
#include "hkSmallArray.h"
#include "hkMemoryAllocator.h"
#include "hkMemoryRouter.h"
#include "hkpEntity.h"

class hkpEntityActivationListener;
class hkpEntityListener;

// Havok 7.1 hkpEntity::ExtendedListeners (Physics/Dynamics/Entity/hkpEntity.h: "created to keep the
// entity size <= 512"), 16 bytes, hung off hkpEntity::m_pExtendedListeners (+0x214) and created on
// first use by hkpEntity::getEntityListeners() and the add/remove listener functions (0x00c9c5b0,
// 0x00c9c670 and 0x00c9c0f0 all inline the same `new` + two hkSmallArray constructors).
//
// HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR expands to an inline operator new/delete that use
// hkMemoryRouter::getInstance().heap().blockAlloc / blockFree. The shared hkMemoryRouter stand-in is
// hkMemoryRouter (GetMonitorStream() = 0x00c85750, the per-thread router; m_pStreamAllocator at
// +0x10 = the heap allocator, whose slot 1/2 are blockAlloc/blockFree, i.e.
// hkMemoryAllocator::AllocateMemoryBlock/ReleaseBlock). heap() is not used because the shared header
// only declares it (each unit supplies its own body); the router is held in a named reference, as
// getInstance() returns one: that keeps 0x00e46a30's register choice (a single expression does not).
class hkpEntityExtendedListeners
{
public:
    static __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        return router.m_heap->blockAlloc(static_cast<int>(nbytes));
    }
    static __forceinline void __cdecl operator delete(void* p)
    {
        if (p)
        {
            hkMemoryRouter& router = hkMemoryRouter::getInstance();
            router.m_heap->blockFree(p, sizeof(hkpEntityExtendedListeners));
        }
    }

    hkSmallArray<hkpEntityActivationListener*> m_activationListeners;
    hkSmallArray<hkpEntityListener*> m_entityListeners;
};

// hkpEntity.inl. Declared `inline` in hkpEntity.h as in Havok; defined __forceinline because the game
// inlines it into every caller seen (0x00e46900, 0x00e46a30 inline the whole lazy `new`), and with
// plain `inline` VC9 /O2 keeps it out of line in 0x00e46a30 (after an inlined hkArray push-back).
__forceinline const hkSmallArray<hkpEntityListener*>& hkpEntity::getEntityListeners() const
{
    if (!m_pExtendedListeners)
    {
        m_pExtendedListeners = new ExtendedListeners;
    }
    return m_pExtendedListeners->m_entityListeners;
}
