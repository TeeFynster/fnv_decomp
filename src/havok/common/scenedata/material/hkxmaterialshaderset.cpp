
// src/havok/common/scenedata/material/hkxmaterialshaderset.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxmaterialshaderset.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxMaterialShaderSet.h"

struct FnvCpu_FUN_00e4af10_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00e4af10_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00e4af10_CpuAllocator* allocator;
};
FnvCpu_FUN_00e4af10_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00e4af10_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void ProcessEntries_00e4ae90();
    FnvCpu_FUN_00e4af10_CpuObject* FUN_00e4af10(unsigned int flags);
};
// @fnv 0x00e4af10
FnvCpu_FUN_00e4af10_CpuObject* FnvCpu_FUN_00e4af10_CpuObject::FUN_00e4af10(unsigned int flags)
{
    ProcessEntries_00e4ae90();
    if (flags & 1)
    {
        FnvCpu_FUN_00e4af10_CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
