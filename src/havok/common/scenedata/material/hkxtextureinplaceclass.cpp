
// src/havok/common/scenedata/material/hkxtextureinplaceclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxtextureinplaceclass.cpp).
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
    void FUN_00e01750();
    CpuObject* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x00e017a0
CpuObject* CpuObject::DestroyIfFlagged(unsigned int flags)
{
    FUN_00e01750();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
