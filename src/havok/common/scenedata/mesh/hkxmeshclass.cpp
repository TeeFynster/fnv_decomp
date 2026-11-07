
// src/havok/common/scenedata/mesh/hkxmeshclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxmeshclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cb0c00_class
{
    int unk00;
    void Object_UpdateFields_00cb0c00();
};
struct Allocator
{
    virtual void A();
    virtual void B();
    virtual void Free(void*, unsigned short);
};
struct Manager
{
    int unk00, unk04, unk08, unk0C;
    Allocator* unk10;
};
extern Manager* __cdecl hkMemoryRouter_getInstance();
struct Owner
{
    virtual void V();
    unsigned short unk04, unk06;
    int unk08, unk0C, unk10;
    FUN_00cb0c00_class unk14;
    FUN_00cb0c00_class unk18;
    void FUN_00e3eaa0();
    void* Destroy(unsigned int flags);
};
// @fnv 0x00e01ef0
void* Owner::Destroy(unsigned int flags)
{
    unk18.Object_UpdateFields_00cb0c00();
    unk14.Object_UpdateFields_00cb0c00();
    FUN_00e3eaa0();
    if (flags & 1)
    {
        Manager* manager = hkMemoryRouter_getInstance();
        Allocator* allocator = manager->unk10;
        unsigned short size = unk04;
        allocator->Free(this, size);
    }
    return this;
}
