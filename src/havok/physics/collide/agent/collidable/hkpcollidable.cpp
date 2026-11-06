// src/havok/physics/collide/agent/collidable/hkpcollidable.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/collidable/hkpcollidable.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkpCollidable.h"
#include "../../../../../../include/hkAabbUint32.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"

// The shared router's GetMonitorStream binds to 0x00c85750 in other units; its heap is at +0x10.

// @fnv 0x00d01a60
hkpCollidable::BoundingVolumeData_S::BoundingVolumeData_S()
{
    m_uiNumChildShapeAabbs = 0;
    m_uiCapacityChildShapeAabbs = 0;
    m_pChildShapeAabbs = 0;
    m_pChildShapeKeys = 0;
    m_kMinimumCorner[0] = 1;
    m_kMaximumCorner[0] = 0;
}

template <typename T> inline void hkDeallocateChunk(T* p, int n)
{
    hkMemoryRouter::getInstance().heap().blockFree(p, n * sizeof(T));
}

// The former 32-byte hkEntryD01A elements are child-shape AABBs, paired with the shape-key array below.
// @fnv 0x00d01a80
void hkpCollidable::BoundingVolumeData_S::deallocate()
{
    hkDeallocateChunk(m_pChildShapeAabbs, m_uiCapacityChildShapeAabbs);
    hkDeallocateChunk(m_pChildShapeKeys, (m_uiCapacityChildShapeAabbs + 3) & ~3);
    m_pChildShapeAabbs = 0;
    m_pChildShapeKeys = 0;
    m_uiNumChildShapeAabbs = 0;
    m_uiCapacityChildShapeAabbs = 0;
}

// @fnv 0x00d01ae0
void hkpCollidable::BoundingVolumeData_S::allocate(int n)
{
    m_uiNumChildShapeAabbs = (unsigned short)n;
    m_uiCapacityChildShapeAabbs = (unsigned short)n;
    if (n)
    {
        unsigned int bytes = m_uiNumChildShapeAabbs;
        hkMemoryAllocator& allocator = hkMemoryRouter::getInstance().heap();
        m_pChildShapeAabbs = static_cast<hkAabbUint32*>(allocator.blockAlloc(bytes << 5));
        unsigned int count = ((unsigned int)m_uiCapacityChildShapeAabbs + 3) & ~3u;
        hkMemoryAllocator& b = hkMemoryRouter::getInstance().heap();
        m_pChildShapeKeys = static_cast<unsigned int*>(b.blockAlloc(count * 4));
    }
}
