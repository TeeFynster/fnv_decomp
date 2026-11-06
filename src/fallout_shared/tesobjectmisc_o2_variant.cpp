
// src/fallout_shared/tesobjectmisc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectmisc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectmisc_decls.h"
#include "../../include/TESForm.h"
#include "../../include/TESValueForm.h"

// MSVC adjustor thunk: the primary base occupies 0x3c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0051b130();
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
};

struct SecondaryBase
{
    virtual void FUN_0051b130();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0051b130
    virtual void FUN_0051b130();
};

Derived::Derived()
{}
