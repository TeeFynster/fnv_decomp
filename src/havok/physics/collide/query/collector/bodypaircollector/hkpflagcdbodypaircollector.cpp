// src/havok/physics/collide/query/collector/bodypaircollector/hkpflagcdbodypaircollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/bodypaircollector/hkpflagcdbodypaircollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

struct DAFc80
{
    int unk00;
    unsigned char unk04;
    void FUN_00dafc80(int a, int b);
};
// @fnv 0x00dafc80
void DAFc80::FUN_00dafc80(int a, int b)
{
    unk04 = 1;
}

hkMemoryRouter* __cdecl FUN_00c85750();

struct FUN_00d34900
{
    int m_i04;

    FUN_00d34900();

// @fnv 0x00d34900
    virtual ~FUN_00d34900()
    {}

    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = FUN_00c85750();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        FreeFunction pFree = reinterpret_cast<FreeFunction>((*reinterpret_cast<void***>(pAllocator))[2]);
        pFree(pAllocator, apMemory, sizeof(FUN_00d34900));
    }
};

FUN_00d34900::FUN_00d34900()
{
    m_i04 = 0;
}
