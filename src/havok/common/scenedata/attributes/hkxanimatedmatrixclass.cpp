
// src/havok/common/scenedata/attributes/hkxanimatedmatrixclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxanimatedmatrixclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"


extern "C" int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00e02650_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_08;
    int m_0c;
    unsigned int m_10;

    FUN_00e02650_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00e02650
FUN_00e02650_cls* FUN_00e02650_cls::Destroy(unsigned char acFlags)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    m_0c = 0;
    unsigned int uFlags = m_10;
    if ((uFlags & 0x80000000u) == 0)
    {
        unsigned int uCount = uFlags & 0x3fffffffu;
        pAllocator->bufFree((void*)m_08, uCount * 64u);
    }
    bool bFree = (acFlags & 1) != 0;
    m_08 = 0;
    m_10 = 0x80000000u;
    m_vptr = (int)&DAT_0102e388;
    if (bFree)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}
