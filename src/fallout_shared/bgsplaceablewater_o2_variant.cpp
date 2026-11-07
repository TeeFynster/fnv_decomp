
// src/fallout_shared/bgsplaceablewater_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsplaceablewater.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgsplaceablewater_decls.h"
#include "bgsplaceablewater_types_BGSPlaceableWater.h"
#include <malloc.h>
struct FUN_004fc380_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetReflectsLand(bool);
};
struct FUN_004fc990_t
{
    void __thiscall BGSPlaceableWater_SetFlag(int, bool);
};
struct FUN_004fc790_shell
{
    unsigned short m0;
    unsigned int m4;
    FUN_004fc790_shell* Reset();
};
struct FUN_004fc420_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_SetUnderwaterFog(bool);
};
struct FUN_005e78f0_t
{
    void __thiscall TESForm_CopyAllComponents(TESForm*);
};
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_004fc860_shell : public BGSPlaceableWater
{
    void BGSPlaceableWater_Copy(TESForm* apCopy);
};

// sub ecx,0x30; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x30).
struct PrimaryBase
{
    virtual void FUN_004fcbf0();
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
    virtual void FUN_004fcbf0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fcbf0
    virtual void FUN_004fcbf0();
};

Derived::Derived()
{}
