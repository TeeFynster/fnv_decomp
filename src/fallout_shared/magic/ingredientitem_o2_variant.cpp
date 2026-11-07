
// src/fallout_shared/magic/ingredientitem_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/magic/ingredientitem.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "ingredientitem.h"
struct FUN_00409a30_shell
{
    bool IngredientItem_GetFlag(unsigned int aFlag);
};
struct BipedModelForm
{
    void __thiscall Endian(void);
};
struct FUN_0040a0f0_shell : BipedModelForm
{
    void __thiscall EndianAtOffset9C(void);
};

// sub ecx,0x30; jmp <target>  ==  MSVC adjustor thunk for a second base.
// PrimaryBase is vptr + 11 ints = 0x30 bytes. The shared virtual is named after the claim.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_0040a120();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_0040a120();
};

struct AdjustedDerived : PrimaryBase, SecondaryBase
{
    AdjustedDerived();
// @fnv 0x0040a120
// src: GUESS 0x0040a120 (confidence: low)
    virtual void AdjustThisAndForward_0040a120();
};

AdjustedDerived::AdjustedDerived()
{}
