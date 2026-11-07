
// src/fallout_shared/tesfurniture_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesfurniture.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesfurniture_tesfurniture.h"

// Adjustor (this-adjusting) thunk for FUN_00509a00: "sub ecx, 0x3c; jmp Destroy".
// PrimaryBase is a vtable pointer plus 14 int members (4 + 56 = 0x3c), so the secondary
// base sub-object is moved back by 0x3c before tail-jumping to the final overrider.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00509a00();
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
    virtual void AdjustThisAndForward_00509a00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00509a00
// src: GUESS 0x00509a00 (confidence: low)
    virtual void AdjustThisAndForward_00509a00();
};

Derived::Derived()
{}
