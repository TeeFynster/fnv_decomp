
// src/fallout_shared/pathfinding/pathingrequest_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/pathfinding/pathingrequest.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "pathingrequest_types_PathingRequest.h"
#include "pathingrequest_types_TESPackage.h"
#include "TESObjectREFR.h"
#include "pathingrequest_decls.h"

// sub ecx,0x10; jmp FUN_006e3880  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_006e3f20();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_006e3f20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x006e3f20
// src: GUESS 0x006e3f20 (confidence: low)
    virtual void AdjustThisAndForward_006e3f20();
};

Derived::Derived()
{}
