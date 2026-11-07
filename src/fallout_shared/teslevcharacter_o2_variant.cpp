
// src/fallout_shared/teslevcharacter_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teslevcharacter.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "teslevcharacter_unit.h"

// Adjustor thunk for FUN_0050ade0: sub ecx,0x4c; jmp FUN_0050a820.
// The derived class overrides a virtual that both of its bases declare, so the
// secondary base's vtable slot holds a thunk that moves `this` back by the size
// of the primary base.
// sizeof(PrimaryBase) = vptr (4) + 18 int fields (72) = 0x4c.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_0050ade0();
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

struct SecondaryBase
{
    virtual void AdjustThisAndForward_0050ade0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0050ade0
// src: GUESS 0x0050ade0 (confidence: low)
    virtual void AdjustThisAndForward_0050ade0();
};

Derived::Derived()
{}

// FUN_0050b3f0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x4c ; jmp FUN_0050aea0
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is the size of the primary base: a vtable pointer plus
// 18 int members (4 + 72 = 0x4c bytes).  Both bases declare the same virtual
// function; the derived class redeclares it and defines only its constructor,
// which is what makes the compiler emit the vtables and the adjusting thunk.
struct LevCharPrimaryBase
{
    virtual void FUN_0050b3f0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
};

struct LevCharSecondaryBase
{
    virtual void FUN_0050b3f0();
};

struct LevCharDerived : LevCharPrimaryBase, LevCharSecondaryBase
{
    LevCharDerived();
// @fnv 0x0050b3f0
    virtual void FUN_0050b3f0();
};

LevCharDerived::LevCharDerived()
{}
