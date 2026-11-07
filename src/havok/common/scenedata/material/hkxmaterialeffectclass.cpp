
// src/havok/common/scenedata/material/hkxmaterialeffectclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxmaterialeffectclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"

// This allocator uses virtual free operations; the shared declarations are nonvirtual.
static __forceinline void FreeAudioBlock(hkMemoryAllocator* pAllocator, void* pMemory, unsigned int uiSize) throw()
{
    typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
    reinterpret_cast<FreeFunction>((*reinterpret_cast<void***>(pAllocator))[2])(pAllocator, pMemory, uiSize);
}

static __forceinline void FreeAudioArray(hkMemoryAllocator* pAllocator, void* pMemory, int iSize) throw()
{
    typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, int);
    reinterpret_cast<FreeFunction>((*reinterpret_cast<void***>(pAllocator))[4])(pAllocator, pMemory, iSize);
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct SpawnedMember
{
    int unk00;
    int unk04;

    ~SpawnedMember() throw();
};

struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};

struct FUN_00e022d0_cls : SpawnedBase
{
    unsigned short m_uSize;
    unsigned short m_u06;
    SpawnedMember m_kMemberDescriptor;
    void* m_pData;
    int m_i14;
    unsigned int m_uiObjectFlags;

    FUN_00e022d0_cls* FUN_00e022d0(unsigned char acFlags);
};

// Frees the data array via the audio allocator, resets the members, destroys the base and optionally frees the object itself.
// @fnv 0x00e022d0
FUN_00e022d0_cls* FUN_00e022d0_cls::FUN_00e022d0(unsigned char acFlags)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uDataFlags = m_uiObjectFlags;
    m_i14 = 0;
    if ((uDataFlags & 0x80000000u) == 0)
    {
        FreeAudioArray(pAllocator, m_pData, uDataFlags & 0x3fffffff);
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000;
    m_kMemberDescriptor.~SpawnedMember();
    this->SpawnedBase::~SpawnedBase();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        FreeAudioBlock(pAllocator2, this, m_uSize);
    }
    return this;
}
