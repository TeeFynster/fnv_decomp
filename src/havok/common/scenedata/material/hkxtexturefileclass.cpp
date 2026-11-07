// src/havok/common/scenedata/material/hkxtexturefileclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxtexturefileclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Part
{
    unsigned int unk00;
    void Object_UpdateFields_00cb0c00();
};
struct FUN_00e01870_Class;
struct RetPart
{
    virtual void first();
    virtual void second();
    virtual void Release(FUN_00e01870_Class* owner, unsigned int count);
};
struct UnkRet
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    RetPart* part10;
};
struct FUN_00e01870_Class
{
    void* vptr;
    unsigned short refCount;
    unsigned short padding;
    Part part08;
    Part part0c;
    Part part10;
    FUN_00e01870_Class* FUN_00e01870(unsigned int);
};
void* DAT_0102e388;
UnkRet* hkMemoryRouter_getInstance();
// Calls FUN_00cb0c00 on part10, part0c and part08, sets vptr to DAT_0102e388, and if flags bit 0 is set releases this with refCount via object->part10.
// @fnv 0x00e01870
FUN_00e01870_Class* FUN_00e01870_Class::FUN_00e01870(unsigned int flags)
{
    part10.Object_UpdateFields_00cb0c00();
    part0c.Object_UpdateFields_00cb0c00();
    part08.Object_UpdateFields_00cb0c00();
    vptr = &DAT_0102e388;
    if (flags & 1)
    {
        UnkRet* object = hkMemoryRouter_getInstance();
        unsigned int count = refCount;
        RetPart* part = object->part10;
        part->Release(this, count);
    }
    return this;
}
