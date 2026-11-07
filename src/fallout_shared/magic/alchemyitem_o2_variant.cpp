
// src/fallout_shared/magic/alchemyitem_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/magic/alchemyitem.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


// sub ecx,0x30; jmp FUN_004029b0
// MSVC adjustor thunk: a derived class overrides a virtual declared by two bases;
// the secondary-base vtable entry is a thunk that moves 'this' back by the primary base size.
struct PrimaryBase
{
    virtual void FUN_00403a50();
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
    virtual void FUN_00403a50();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00403a50
    virtual void FUN_00403a50();
};

Derived::Derived()
{}

// sub ecx,0x4c; jmp target  ==  MSVC adjustor thunk: the derived class overrides a virtual that both
// bases declare, so the secondary base's vtable gets a thunk that moves `this` back by the primary base size (0x4c).
struct AdjustPrimaryBase
{
    virtual void AdjustThisAndForward_00403a60();
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
};

struct AdjustSecondaryBase
{
    virtual void AdjustThisAndForward_00403a60();
};

struct AdjustDerived : AdjustPrimaryBase, AdjustSecondaryBase
{
    AdjustDerived();
// @fnv 0x00403a60
// src: GUESS 0x00403a60 (confidence: low)
    virtual void AdjustThisAndForward_00403a60();
};

AdjustDerived::AdjustDerived()
{}
