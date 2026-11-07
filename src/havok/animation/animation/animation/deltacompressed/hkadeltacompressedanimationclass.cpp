
// src/havok/animation/animation/animation/deltacompressed/hkadeltacompressedanimationclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/deltacompressed/hkadeltacompressedanimationclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dfbb80_cls
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    char* m_pData;
    int m_iArrayLength;
    int m_iCap;

    void BaseRelease();

    FUN_00dfbb80_cls* ReleaseBuffer(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Frees the data buffer through the allocator, resets the data pointer and capacity, calls BaseRelease, and optionally frees the object itself.
// @fnv 0x00dfbb80
FUN_00dfbb80_cls* FUN_00dfbb80_cls::ReleaseBuffer(unsigned char acFlags)
{
    hkMemoryRouter* pAudioHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pAudioHolder->m_heap);
    unsigned int uiCap = m_iCap;
    m_iArrayLength = 0;
    if ((uiCap & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pData, uiCap & 0x3fffffff);
    }
    m_pData = 0;
    m_iCap = 0x80000000;
    BaseRelease();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}
