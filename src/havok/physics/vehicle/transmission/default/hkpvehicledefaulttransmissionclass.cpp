// src/havok/physics/vehicle/transmission/default/hkpvehicledefaulttransmissionclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/transmission/default/hkpvehicledefaulttransmissionclass.cpp).
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
    void SetVtableAndProcessState_00dfed30();
    CpuObject* FUN_00dfedb0(unsigned int flags);
};
// Calls FUN_00dfed30, then if bit 0 of flags is set, invokes the allocator's Invoke on this with size, and returns this.
// @fnv 0x00dfedb0
CpuObject* CpuObject::FUN_00dfedb0(unsigned int flags)
{
    SetVtableAndProcessState_00dfed30();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
