
// src/tesobjecttree_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/tesobjecttree.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// include/TESFile.h needs the Windows types before layout_support.h stubs them.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "../include/TESObjectTREE.h"
#include "TESFile.h"
#include <malloc.h>
#include <string.h>
template <int size> struct EndianSizeTag
{
};
void BSEndian(unsigned int* value, EndianSizeTag<4>);
void BSEndian(float* value, EndianSizeTag<4>);

// MSVC adjustor thunk: the primary base occupies 0x30 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void AdjustThisAndForward_0051d760();
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
    virtual void AdjustThisAndForward_0051d760();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0051d760
// src: GUESS 0x0051d760 (confidence: low)
    virtual void AdjustThisAndForward_0051d760();
};

Derived::Derived()
{}
