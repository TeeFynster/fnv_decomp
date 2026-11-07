
// src/havok/common/scenedata/material/hkxmaterialclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxmaterialclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void Destroy();
    CpuObject* FUN_00dfd9e0(unsigned int flags);
};
// @fnv 0x00dfd9e0
CpuObject* CpuObject::FUN_00dfd9e0(unsigned int flags)
{
    Destroy();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
