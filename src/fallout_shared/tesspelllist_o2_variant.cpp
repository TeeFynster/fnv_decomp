// src/fallout_shared/tesspelllist_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesspelllist.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesspelllist.h"

// sub ecx,0x7c; jmp FUN_005f18c0
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x7c = vptr + thirty int fields).
struct ThunkPrimaryBase
{
    virtual void FUN_005fbf70();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct ThunkSecondaryBase
{
    virtual void FUN_005fbf70();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x005fbf70
    virtual void FUN_005fbf70();
};

ThunkDerived::ThunkDerived()
{}

// MSVC adjustor thunk: the primary base occupies 0x7c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005fbfe0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_005fbfe0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbfe0
// src: GUESS 0x005fbfe0 (confidence: low)
    virtual void AdjustThisAndForward_005fbfe0();
};

Derived::Derived()
{}

namespace fnv_005fc020 {
// Adjustor (this-adjusting) thunk for FUN_005fc020:
//     sub ecx, 0x7c ; jmp FUN_005f1b30
// MSVC emits such a thunk in the vftable of a class that inherits the same
// virtual from two bases: it converts the secondary base sub-object pointer
// back to the derived object pointer by subtracting the size of the primary
// base (0x7c = 4 byte vptr + 30 int members) and tail jumps to the
// implementation.  Both bases declare the virtual, the derived class
// redeclares it and only defines its constructor, which makes the compiler
// emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005fc020();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_005fc020();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fc020
// src: GUESS 0x005fc020 (confidence: low)
    virtual void AdjustThisAndForward_005fc020();
};

Derived::Derived()
{}
}  // namespace fnv_005fc020
