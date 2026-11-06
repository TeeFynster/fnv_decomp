
// src/fallout_shared/bgsprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSExplosion.h"
#include "../../include/BGSImpactData.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/BGSProjectile.h"
#include "../../include/EffectSetting.h"
#include "../../include/ProjectileProperties.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectLIGH.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESSound.h"

#include "bgsprojectile_decls.h"

// Adjustor thunk for FUN_004fe250: "sub ecx, 0x3c; jmp DestroyIfFlagged".
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
    virtual void FUN_004fe250();
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
    virtual void FUN_004fe250();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fe250
    virtual void FUN_004fe250();
};

Derived::Derived()
{}
