
// src/havok/physics/collide/filter/list/hkpcollisionfilterlistclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/list/hkpcollisionfilterlistclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00e012f0_class;

struct NotifyTarget
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Notify(void*, unsigned short);
};

struct NotifyRoot
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NotifyTarget* target;
};

struct FUN_00e012f0_class
{
    int unk00;
    unsigned short m4;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00e012f0_class* InitialiseAndNotify(unsigned int flags);
};

extern "C" void __cdecl FUN_00e49f40();
typedef void(__thiscall* InitialiseFunction)(FUN_00e012f0_class*);
extern "C" NotifyRoot* __cdecl hkMemoryRouter_getInstance();

// Calls FUN_00e49f40 on this, then if flags has bit 0 set, notifies the target from FUN_00c85750 with this and m4, and returns this.
// @fnv 0x00e012f0
FUN_00e012f0_class* FUN_00e012f0_class::InitialiseAndNotify(unsigned int flags)
{
    reinterpret_cast<InitialiseFunction>(FUN_00e49f40)(this);
    if (flags & 1)
    {
        NotifyRoot* root = hkMemoryRouter_getInstance();
        root->target->Notify(this, m4);
    }
    return this;
}
