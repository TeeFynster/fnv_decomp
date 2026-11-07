// src/havok/common/visualize/hkdebugdisplay.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkdebugdisplay.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00c99fb0_Interface
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void FreeObject(void* object, unsigned int size);
    virtual void Slot3();
    virtual void FreeBuffer(void* buffer, unsigned int bytes);
};
struct FUN_00c99fb0_Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00c99fb0_Interface* allocator;
};
extern FUN_00c99fb0_Manager* __cdecl hkMemoryRouter_getInstance();
extern "C" void __stdcall DeleteCriticalSection(void* section);
struct FUN_00c99fb0
{
    virtual ~FUN_00c99fb0();
    unsigned short unk04;
    void* field08;
    int field0c;
    int field10;
    void* field14;
    static void operator delete(void* object);
};
// Deletes and frees the critical section when present, frees the buffer when count is nonnegative, then resets field0c, field08, and field10.
// @fnv 0x00c99fb0
FUN_00c99fb0::~FUN_00c99fb0()
{
    if (field14)
    {
        DeleteCriticalSection(field14);
        hkMemoryRouter_getInstance()->allocator->FreeObject(field14, 0x18);
    }
    int count = field10;
    FUN_00c99fb0_Manager* manager = hkMemoryRouter_getInstance();
    field0c = 0;
    if (count >= 0)
        manager->allocator->FreeBuffer(field08, (count & 0x3fffffff) * 4);
    field08 = 0;
    field10 = (int)0x80000000;
}
void FUN_00c99fb0::operator delete(void* object)
{
    FUN_00c99fb0* self = (FUN_00c99fb0*)object;
    FUN_00c99fb0_Manager* manager = hkMemoryRouter_getInstance();
    unsigned short size = self->unk04;
    manager->allocator->FreeObject(object, size);
}
