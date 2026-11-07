
// src/fallout_shared/teslight_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teslight.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/TESSound.h"
#include "../../include/NiNode.h"
#include "../../include/NiSortAdjustNode.h"
#include "../../include/NiLight.h"
#include "teslight_scene.h"
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" const char DAT_01029064[];
extern int __cdecl Warning(const char* format, ...);
extern float DAT_010249d8;
NiLight* FindLightInNode(NiNode* node);

struct PrimaryBase
{
    virtual void AdjustThisAndForward_0050e680();
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
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_0050e680();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0050e680
// src: GUESS 0x0050e680 (confidence: low)
    virtual void AdjustThisAndForward_0050e680();
};

Derived::Derived()
{}

namespace fnv_0050e690 {
// Adjustor thunk for FUN_0050e690: "sub ecx, 0x3c; jmp DestroyIfFlagged".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function that a
// class inherits from a secondary base: the thunk converts the secondary base
// sub-object pointer (this + 0x3c) back into the derived object pointer
// (sub ecx, 0x3c) and then tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 14 int members (4 + 14 * 4 = 0x3c
// bytes).  Both bases declare the same virtual function, the derived class
// redeclares it and defines only its constructor, which is what makes the
// compiler emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0050e690();
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
    virtual void FUN_0050e690();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0050e690
    virtual void FUN_0050e690();
};

Derived::Derived()
{}
}  // namespace fnv_0050e690

// FUN_0050e6a0 is an MSVC this-adjusting (adjustor) thunk:
//     sub ecx, 0x8c ; jmp FUN_0050e580
// It is emitted for a virtual that lives in the first base of a multiply
// inherited class but is reached through the second base's vtable slot: the
// slot holds a thunk that walks `this` back to the derived object (the size of
// the primary base, 0x8c) and tail-jumps to the derived override.
struct ThunkPrimaryBase
{
    virtual void* FUN_0050e6a0(unsigned int flags);
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
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
};

struct ThunkSecondaryBase
{
    virtual void* FUN_0050e6a0(unsigned int flags);
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x0050e6a0
    virtual void* FUN_0050e6a0(unsigned int flags);
};

ThunkDerived::ThunkDerived()
{}

namespace fnv_0050e6b0 {
// sub ecx,0x8c; jmp FUN_0050e550
// MSVC this-adjusting (adjustor) thunk: a derived class declares a virtual that
// both of its bases declare, so the secondary base's vtable slot holds a thunk
// that walks `this` back to the secondary base subobject (the size of the
// primary base, 0x8c) and tail-jumps to the base implementation.
struct ThunkPrimaryBase
{
    virtual void FUN_0050e6b0();
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
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
};

struct ThunkSecondaryBase
{
    virtual void FUN_0050e6b0();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x0050e6b0
    virtual void FUN_0050e6b0();
};

ThunkDerived::ThunkDerived()
{}
}  // namespace fnv_0050e6b0
