// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"

struct FUN_00e4dd90_shell
{
    void __thiscall hkKdTreeCpuBroadphaseBundleCastCollector_getHitFractions(float* output);
};
// If the object at offset 0x0c is set, writes four floats from its nested structure at offsets 0x10, 0x70, 0xd0 and 0x130 into output.
// @fnv 0x00e4dd90
// src: HAVOK_LIB 0x00e4dd90
void __thiscall FUN_00e4dd90_shell::hkKdTreeCpuBroadphaseBundleCastCollector_getHitFractions(float* output)
{
    if (*(int*)((unsigned char*)this + 0x0c) != 0)
    {
        output[0] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0x10);
        output[1] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0x70);
        output[2] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0xd0);
        output[3] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0x130);
    }
}

struct FUN_00e4dde0
{
    virtual void Vfn0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    FUN_00e4dde0();
};
// Constructor that zeroes unk0C, unk70, unk74, unk80, unk84, unk88 and unk8C.
// @fnv 0x00e4dde0
FUN_00e4dde0::FUN_00e4dde0()
{
    unk0C = 0;
    unk70 = 0;
    unk74 = 0;
    unk80 = 0;
    unk84 = 0;
    unk88 = 0;
    unk8C = 0;
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00e4e3c0
{
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;

    FUN_00e4e3c0();

// @fnv 0x00e4e3c0
    virtual ~FUN_00e4e3c0()
    {}

    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        // Free occupies vtable slot 2 in this allocator interface.
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        (*reinterpret_cast<FreeFunction**>(pAllocator))[2](pAllocator, apMemory, sizeof(FUN_00e4e3c0));
    }
};

FUN_00e4e3c0::FUN_00e4e3c0()
{
    m_i04 = 0;
}
