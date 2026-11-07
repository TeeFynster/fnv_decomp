
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurveclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurveclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Allocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void freeBlock(void*, unsigned int);
};
struct ThreadState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
ThreadState* __cdecl hkMemoryRouter_getInstance();
struct Object
{
    void* vtable;
    unsigned short allocationSize;
    void ReleaseBothArrays();
    Object* FUN_00e00070(unsigned int flags);
};
// @fnv 0x00e00070
Object* Object::FUN_00e00070(unsigned int flags)
{
    ReleaseBothArrays();
    if (flags & 1)
    {
        ThreadState* state = hkMemoryRouter_getInstance();
        unsigned int size = allocationSize;
        state->allocator->freeBlock(this, size);
    }
    return this;
}
