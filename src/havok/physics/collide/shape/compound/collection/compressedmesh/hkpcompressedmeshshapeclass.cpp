// src/havok/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshapeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshapeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"

// The shared allocator declares FreeArray nonvirtual; these objects dispatch through slot 4.
static __forceinline void FreeAudioArray(hkMemoryAllocator* pAllocator, void* pMemory, unsigned int uiSize) throw()
{
    typedef void (__thiscall* FreeArrayFunction)(hkMemoryAllocator*, void*, unsigned int);
    (*reinterpret_cast<FreeArrayFunction**>(pAllocator))[4](pAllocator, pMemory, uiSize);
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dfd380_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pDataD;
    int m_iCountD;
    unsigned int m_uCapD;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void ReleaseFourArrays();
};

// Frees the four data arrays through the audio allocator when their capacity flag is clear, then resets each pointer, count and capacity.
// @fnv 0x00dfd380
// src: GUESS 0x00dfd380 (confidence: medium)
void FUN_00dfd380_cls::ReleaseFourArrays()
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, m_pDataA, (uCapA & 0x3fffffffu) * 2);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator2, m_pDataB, (uCapB & 0x3fffffffu) * 2);
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    hkMemoryRouter* pHolder3 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator3 = reinterpret_cast<hkMemoryAllocator*>(pHolder3->m_heap);
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator3, m_pDataC, (uCapC & 0x3fffffffu) * 2);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;

    hkMemoryRouter* pHolder4 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator4 = reinterpret_cast<hkMemoryAllocator*>(pHolder4->m_heap);
    unsigned int uCapD = m_uCapD;
    m_iCountD = 0;
    if ((uCapD & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator4, m_pDataD, (uCapD & 0x3fffffffu) * 2);
    }
    m_pDataD = 0;
    m_uCapD = 0x80000000u;
}

namespace fnv_00dfd440 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dfd440_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void ReleaseThreeArrays();
};

// Frees the three capacity-flagged data arrays through the audio allocator and resets each pointer, count and capacity to empty.
// @fnv 0x00dfd440
// src: GUESS 0x00dfd440 (confidence: medium)
void FUN_00dfd440_cls::ReleaseThreeArrays()
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, m_pDataA, (uCapA & 0x3fffffffu) * 2);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator2, m_pDataB, (uCapB & 0x3fffffffu));
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    hkMemoryRouter* pHolder3 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator3 = reinterpret_cast<hkMemoryAllocator*>(pHolder3->m_heap);
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator3, m_pDataC, (uCapC & 0x3fffffffu) * 2);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;
}
}  // namespace fnv_00dfd440
