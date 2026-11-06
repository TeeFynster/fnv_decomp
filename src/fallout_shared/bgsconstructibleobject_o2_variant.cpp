
// src/fallout_shared/bgsconstructibleobject_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsconstructibleobject.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/bgsconstructibleobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsconstructibleobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/BGSConstructibleObject.h"

// sub ecx,0x3c; jmp target: MSVC adjustor thunk from multiple inheritance (Derived overrides a virtual both bases declare).
struct PrimaryBase
{
    virtual void FUN_004f9cb0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
};

struct SecondaryBase
{
    virtual void FUN_004f9cb0();
};

struct AdjustedDerived : PrimaryBase, SecondaryBase
{
    AdjustedDerived();
// @fnv 0x004f9cb0
    virtual void FUN_004f9cb0();
};

AdjustedDerived::AdjustedDerived()
{}
