
// src/fallout_shared/tesflora_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesflora.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/tesflora.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesflora.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00477f20
{
    void FUN_00477f20();
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct S_00487010
{
    void Save_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct S_0048cca0
{
    void Save_0048cca0();
};
struct FUN_0048b5c0_shell
{
    void FUN_0048b5c0();
};
struct FUN_00508920_obj
{
    void TESFlora_Save();
};

struct Prim_508db0
{
    virtual void FUN_00508db0();
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    int p34;
    int p38;
    int p3c;
    int p40;
    int p44;
};

struct B1_508db0
{
    virtual void FUN_00508db0();
};

struct TO_508db0 : Prim_508db0, B1_508db0
{
// @fnv 0x00508db0
    virtual void FUN_00508db0();
};

static TO_508db0 g_thunk;

// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00508df0();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00508df0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00508df0
    virtual void FUN_00508df0();
};

Derived::Derived()
{}
