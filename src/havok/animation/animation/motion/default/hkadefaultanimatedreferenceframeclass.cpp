
// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
extern int DAT_0102e388;

struct FUN_00dfe520_cls
{
    int m_vptr00;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    FUN_00dfe520_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00dfe520
FUN_00dfe520_cls* FUN_00dfe520_cls::Destroy(unsigned char acFlags)
{
    hkMemoryRouter* pAudioHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pAudioHolder->m_heap);
    unsigned int uCapacityFlags = m_uCapBits;
    m_iArrayLength = 0;
    if ((uCapacityFlags & 0x80000000u) == 0)
    {
        (*reinterpret_cast<void (__thiscall***)(hkMemoryAllocator*, void*, unsigned int)>(pAllocator))[4](pAllocator, m_pData, (uCapacityFlags & 0x3fffffff) * 16);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = (int)&DAT_0102e388;
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        (*reinterpret_cast<void (__thiscall***)(hkMemoryAllocator*, void*, unsigned int)>(pAllocator2))[2](pAllocator2, this, m_uSize);
    }
    return this;
}
