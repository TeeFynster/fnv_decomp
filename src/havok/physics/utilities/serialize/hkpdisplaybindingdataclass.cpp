
// src/havok/physics/utilities/serialize/hkpdisplaybindingdataclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpdisplaybindingdataclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/BSAudio.h"


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct RefElem_t
{
    void FUN_00c905b0();
};

struct RefBase_cls
{
    virtual void a00();
    virtual ~RefBase_cls() throw()
    {}
};

class FUN_00dff640_cls : public RefBase_cls
{
  public:
    unsigned short m_uSize;
    unsigned short m_u06;
    RefElem_t* m_pA;
    RefElem_t* m_pB;

    FUN_00dff640_cls* FUN_00dff640(unsigned char acFlags);
};

// Releases m_pB and m_pA, destroys the base, and if acFlags bit 0 is set frees this through the allocator with m_uSize.
// @fnv 0x00dff640
FUN_00dff640_cls* FUN_00dff640_cls::FUN_00dff640(unsigned char acFlags)
{
    if (m_pB != 0)
    {
        m_pB->FUN_00c905b0();
    }
    *(RefElem_t* volatile*)&m_pB = 0;
    RefElem_t* pElemA = *(RefElem_t* volatile*)&m_pA;
    if (pElemA != 0)
    {
        pElemA->FUN_00c905b0();
    }
    bool bShouldFree = (acFlags & 1) != 0;
    m_pA = 0;
    this->RefBase_cls::~RefBase_cls();
    if (bShouldFree)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}

namespace fnv_00dff730 {
BSAudio* __cdecl hkMemoryRouter_getInstance();

struct PtrElem
{
    int unk00;
    void Release();
};

extern int DAT_0102e388;

struct FUN_00dff730_cls
{
    int m_vptr;
    int unk04;
    void** m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    PtrElem** m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void ClearArrays();
};

// Releases and nulls every element of both pointer arrays, frees their storage via the audio allocator, and resets the vtable pointer.
// @fnv 0x00dff730
void FUN_00dff730_cls::ClearArrays()
{
    hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    PtrElem** pData1 = m_pData1;
    int iCount1 = m_iCount1;
    for (int i = 0; i < iCount1; i++)
    {
        if (pData1[i] != 0)
        {
            pData1[i]->Release();
        }
        pData1[i] = 0;
    }
    unsigned int uCapBits1 = m_uCapBits1;
    m_iCount1 = 0;
    if ((uCapBits1 & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pData1, (uCapBits1 & 0x3fffffffu) * 4);
    }
    m_pData1 = 0;
    m_uCapBits1 = 0x80000000u;

    hkMemoryRouter* pHolder2 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    PtrElem** pData2 = (PtrElem**)m_pData2;
    int iCount2 = m_iCount2;
    for (int j = 0; j < iCount2; j++)
    {
        if (pData2[j] != 0)
        {
            pData2[j]->Release();
        }
        pData2[j] = 0;
    }
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((m_uCapBits2 & 0x80000000u) == 0)
    {
        pAllocator2->bufFree(m_pData2, (uCapBits2 & 0x3fffffffu) * 4);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
    m_vptr = (int)&DAT_0102e388;
}
}  // namespace fnv_00dff730

namespace fnv_00dff810 {
BSAudio* hkMemoryRouter_getInstance();
struct Owner
{
    unsigned int unk00;
    unsigned short size4, unk06;
    void FUN_00dff6a0();
    Owner* FUN_00dff810(unsigned int flags);
};
// Calls FUN_00dff6a0, and if flags has bit 0 set, releases this via the BSAudio allocator with size4 bytes, then returns this.
// @fnv 0x00dff810
Owner* Owner::FUN_00dff810(unsigned int flags)
{
    FUN_00dff6a0();
    if (flags & 1u)
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        unsigned int bytes = size4;
        reinterpret_cast<hkMemoryAllocator*>(((hkMemoryRouter*)audio)->m_heap)->blockFree(this, bytes);
    }
    return this;
}
}  // namespace fnv_00dff810

namespace fnv_00dff840 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void ClearArrays();
    CpuObject* FUN_00dff840(unsigned int flags);
};
// @fnv 0x00dff840
CpuObject* CpuObject::FUN_00dff840(unsigned int flags)
{
    ClearArrays();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00dff840
