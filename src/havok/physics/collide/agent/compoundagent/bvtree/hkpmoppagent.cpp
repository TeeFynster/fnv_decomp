
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpmoppagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpmoppagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

extern int DAT_010ce8f4;
extern int DAT_0102e388;

struct FUN_00d2f380_cls
{
    int m_vptr00;
    int unk04;
    int unk08;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void DestroyArray();
};

// Resets the object's vtable pointers, frees m_pData through the allocator when the capacity flag is clear, then clears the data pointer and capacity.
// @fnv 0x00d2f380
void FUN_00d2f380_cls::DestroyArray()
{
    m_vptr00 = (int)&DAT_010ce8f4;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapBits = m_uCapBits;
    m_iArrayLength = 0;
    if ((uCapBits & 0x80000000u) == 0)
    {
        // The shared declaration is nonvirtual; this call uses the allocator's fifth vtable slot.
        typedef void (__thiscall* FreeArrayFn)(hkMemoryAllocator*, void*, unsigned int);
        (*reinterpret_cast<FreeArrayFn**>(pAllocator))[4](pAllocator, m_pData, (uCapBits & 0x3fffffffu) * 12);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = (int)&DAT_0102e388;
}
