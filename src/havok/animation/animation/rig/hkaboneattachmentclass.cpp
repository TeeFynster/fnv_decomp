// src/havok/animation/animation/rig/hkaboneattachmentclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkaboneattachmentclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cb0c00_class
{
    int unk00;
    void Object_UpdateFields_00cb0c00();
};
struct OwnedObject
{
    void FUN_00c905b0();
};
struct Callback
{
    virtual void V0();
    virtual void V1();
    virtual void Invoke(void* owner, unsigned short value);
};
struct CallbackManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Callback* callback;
};
CallbackManager* hkMemoryRouter_getInstance();
extern int DAT_0102e388;
struct Owner
{
    void* vtable;
    unsigned short unk04;
    unsigned short unk06;
    FUN_00cb0c00_class child08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    OwnedObject* owned50;
    FUN_00cb0c00_class child54;
    Owner* FUN_00dfe620(unsigned int flags);
};
// @fnv 0x00dfe620
Owner* Owner::FUN_00dfe620(unsigned int flags)
{
    child54.Object_UpdateFields_00cb0c00();
    if (owned50)
        owned50->FUN_00c905b0();
    owned50 = 0;
    child08.Object_UpdateFields_00cb0c00();
    vtable = &DAT_0102e388;
    if (flags & 1)
    {
        CallbackManager* manager = hkMemoryRouter_getInstance();
        manager->callback->Invoke(this, unk04);
    }
    return this;
}
