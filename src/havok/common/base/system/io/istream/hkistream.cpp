// src/havok/common/base/system/io/istream/hkistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/istream/hkistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Allocator
{
    virtual void first();
    virtual void second();
    virtual void Free(void* memory, unsigned short bytes);
};
struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
Manager* __cdecl hkMemoryRouter_getInstance();
struct Record
{
    void* vtable00;
    unsigned short unk04;
    void SetVirtualTable_00dcc160();
    Record* FUN_00dcca30(unsigned int flags);
};
// Calls FUN_00dcc160, then if bit 0 of flags is set frees this through the manager's allocator using unk04 as size, and returns this.
// @fnv 0x00dcca30
Record* Record::FUN_00dcca30(unsigned int flags)
{
    SetVirtualTable_00dcc160();
    if (flags & 1)
    {
        Manager* manager = hkMemoryRouter_getInstance();
        Allocator* allocator = manager->allocator;
        unsigned short size = unk04;
        allocator->Free(this, size);
    }
    return this;
}
