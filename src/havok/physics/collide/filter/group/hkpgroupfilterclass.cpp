
// src/havok/physics/collide/filter/group/hkpgroupfilterclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/group/hkpgroupfilterclass.cpp).
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
    void InitGroupFilterPointers();
    CpuObject* hkpGroupFilter_Destroy(unsigned int flags);
};
// @fnv 0x00e00c40
// src: COMMUNITY 0x00e00c40
CpuObject* CpuObject::hkpGroupFilter_Destroy(unsigned int flags)
{
    InitGroupFilterPointers();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
