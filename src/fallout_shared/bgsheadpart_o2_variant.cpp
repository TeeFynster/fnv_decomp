
// src/fallout_shared/bgsheadpart_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsheadpart.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSHeadPart.h"

extern "C" void ref_004013e0();
extern "C" void ref_0048aa80();
extern "C" void ref_00624700();
extern "C" void ref_008256d0();
extern "C" void ref_006815c0();
extern "C" void ref_00484e60();
extern "C" void ref_00485d50();
extern "C" void ref_004839c0();
extern "C" void ref_00ec43fb();
extern "C" void ref_0084e3a0();
extern "C" void ref_005b5e40();
extern "C" void ref_00905330();
extern "C" void ref_00726070();
extern "C" void ref_0063f7b0();
extern "C" void ref_00726c60();
extern "C" void ref_00484ab0();
extern "C" void ref_00472660();
extern "C" void ref_00485110();
extern "C" void ref_004726b0();
extern "C" void ref_00401660();
extern "C" void ref_00ec5ec0();
extern "C" void ref_00472890();
extern "C" void ref_00487050();
extern "C" void ref_004892d0();
extern "C" void ref_00403570();
extern "C" void ref_0048a7b0();
extern "C" void ref_004727f0();
extern "C" void ref_005e7790();
extern "C" void ref_004726f0();
extern "C" void ref_00ec408c();
extern "C" unsigned char data_011863b8[];
extern "C" unsigned char data_01183028[];
extern "C" unsigned char data_010465ec[];
extern "C" unsigned char data_011c16bc[];
#include "../../include/ENUM_FORM_ID.h"
// sub ecx,0x24; jmp target == MSVC adjustor thunk: Derived overrides a virtual that both of its
// bases declare, so the second base's vtable gets a thunk that moves `this` back by the size of
// the first base (vptr + 8 ints = 0x24).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_005e7a80();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_005e7a80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005e7a80
// src: GUESS 0x005e7a80 (confidence: low)
    virtual void AdjustThisAndForward_005e7a80();
};

Derived::Derived()
{}
