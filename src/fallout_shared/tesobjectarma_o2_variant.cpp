
// src/fallout_shared/tesobjectarma_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectarma.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESObjectARMA.h"
#include "../../include/TESObjectARMO.h"

// MSVC adjustor thunk: the primary base occupies 0x58 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005129c0();
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
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_005129c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005129c0
// src: GUESS 0x005129c0 (confidence: low)
    virtual void AdjustThisAndForward_005129c0();
};

Derived::Derived()
{}

// FUN_005129d0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x58 ; jmp <final overrider>
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base: a vtable
// pointer plus 21 int members (4 + 84 = 0x58 bytes). Both bases declare the
// same virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct ArmaPrimaryBase
{
    virtual void FUN_005129d0();
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
    int m_4c;
    int m_50;
    int m_54;
};

struct ArmaSecondaryBase
{
    virtual void FUN_005129d0();
};

struct ArmaDerived : ArmaPrimaryBase, ArmaSecondaryBase
{
    ArmaDerived();
// @fnv 0x005129d0
    virtual void FUN_005129d0();
};

ArmaDerived::ArmaDerived()
{}

namespace fnv_005129e0 {
// FUN_005129e0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x58 ; jmp <final overrider>
//
// MSVC emits such a thunk in the vtable of a class that inherits the same
// virtual slot from two bases: the slot of the second base holds a small
// stub that moves `this` back onto the complete object (sub ecx, sizeof of
// the primary base)) and tail-jumps to the implementation.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 21 int members (4 + 84 = 0x58 bytes).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct ArmaPrimaryBase
{
    virtual void AdjustThisAndForward_005129e0();
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
    int m_4c;
    int m_50;
    int m_54;
};

struct ArmaSecondaryBase
{
    virtual void AdjustThisAndForward_005129e0();
};

struct ArmaDerived : ArmaPrimaryBase, ArmaSecondaryBase
{
    ArmaDerived();
// @fnv 0x005129e0
// src: GUESS 0x005129e0 (confidence: low)
    virtual void AdjustThisAndForward_005129e0();
};

ArmaDerived::ArmaDerived()
{}
}  // namespace fnv_005129e0
