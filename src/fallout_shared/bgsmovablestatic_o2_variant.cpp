
// src/fallout_shared/bgsmovablestatic_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsmovablestatic.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


// sub ecx,0x44; jmp <target>  ==  MSVC adjustor thunk for a second base.
// PrimaryBase is vptr (4) + 16 int fields (64) = 0x44 bytes; the shared virtual
// is named after the claimed function so the compiler emits the thunk symbol
// ?FUN_004fc1a0@...@WGI@AEX_v@Z.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_004fc1a0();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_004fc1a0();
};

struct AdjustedDerived : PrimaryBase, SecondaryBase
{
    AdjustedDerived();
// @fnv 0x004fc1a0
// src: GUESS 0x004fc1a0 (confidence: low)
    virtual void AdjustThisAndForward_004fc1a0();
};

AdjustedDerived::AdjustedDerived()
{}
