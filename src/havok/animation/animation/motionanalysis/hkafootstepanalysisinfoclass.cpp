
// src/havok/animation/animation/motionanalysis/hkafootstepanalysisinfoclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motionanalysis/hkafootstepanalysisinfoclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Allocator
{
    virtual void first();
    virtual void second();
    virtual void deallocate(void* object, unsigned short size);
};
struct Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
extern "C" Global* __cdecl hkMemoryRouter_getInstance();
struct FUN_00dfe4b0_Class
{
    int vtable;
    unsigned short size;
    int unk08;
    int unk0c;
    int unk10;
    void ClearItems();
    void* DestroyOrReturnSelf(unsigned char flags);
};
// Calls ClearItems, and if bit 0 of flags is set, deallocates this through the global allocator; returns this.
// @fnv 0x00dfe4b0
void* FUN_00dfe4b0_Class::DestroyOrReturnSelf(unsigned char flags)
{
    ClearItems();
    if (flags & 1)
    {
        Global* global = hkMemoryRouter_getInstance();
        global->allocator->deallocate(this, size);
    }
    return this;
}
