
// src/fallout_shared/tesgrass_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesgrass.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesgrass_decls.h"
#include <malloc.h>
struct FUN_005081b0_shell
{
    float GetFloatAtOffset58();
};
struct FUN_00509aa0_shell : TESGrass
{
    unsigned char TESGrass_GetMaxSlopeDegrees();
};
struct TESGrass_shell
{
    char m_auiShapeKeys[0x4c];
    unsigned short m_4c;
    void TESGrass_SetDistanceFromWaterLevel(unsigned short state);
};
struct FUN_00509bb0_shell
{
    char _pad[0x64];
    char m_flags;
    bool IsFlag2Set();
};
struct FUN_00509bd0_shell
{
    char pad[0x64];
    char m_64;  // +0x64
    void __thiscall SetFlag2(bool value);
};
struct FUN_00509c20_shell
{
    bool IsFlag4Set();
};
struct FUN_00509c90_shell
{
    void FUN_00509cc0();
    void* DestroyIfFlagged(unsigned int flags);
};
struct FUN_00509d30_shell
{
    char field_48;
    bool TESGrass_SetDensity(unsigned char a);
};
struct FUN_00509d60_class
{
    bool TESGrass_SetMinSlopeDegrees(unsigned char value);
};
struct FUN_00509da0_shell
{
    char pad_49[0x49];
    unsigned char byte_49;
    unsigned char byte_4a;
    bool SetSlope(unsigned char slope);
};
struct FUN_0068a830_shell
{
    TESGrass* GetGrass();
};
struct FUN_006fe520_shell
{
    char GetByteAtOffset48();
};
struct FUN_009cdac0_shell
{
    float GetField60Float();
};
struct FUN_009d1b50_shell
{
    float GetField54Float();
};

// sub ecx,0x30; jmp DestroyIfFlagged
// This is an MSVC this-adjusting (adjustor) thunk: a derived class overrides a
// virtual that both of its bases declare, so the secondary base's vtable slot
// holds a thunk that walks `this` back to the derived object (the size of the
// primary base, 0x30) and tail-jumps to the derived override.
struct PrimaryBase
{
    virtual void* FUN_0050a590(unsigned int flags);
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
    virtual void* FUN_0050a590(unsigned int flags);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0050a590
    virtual void* FUN_0050a590(unsigned int flags);
};

Derived::Derived()
{}
