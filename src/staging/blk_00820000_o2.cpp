
// src/staging/blk_00820000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct PrimaryBase
{
    virtual void __cdecl FUN_00831ff0();
};

struct SecondaryBase
{
    virtual void __cdecl FUN_00831ff0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00831ff0
    virtual void __cdecl FUN_00831ff0();
};

Derived::Derived()
{}

// FUN_00832000: __cdecl adjustor thunk (sub [esp+4],4; jmp target).
// Primary base is only the vptr (4 bytes); the secondary base sits at +4 inside Derived.
struct PrimaryBase_00832000
{
    virtual void __cdecl AdjustThisAndForward_00832000();
};

struct SecondaryBase_00832000
{
    virtual void __cdecl AdjustThisAndForward_00832000();
};

struct Derived_00832000 : PrimaryBase_00832000, SecondaryBase_00832000
{
    Derived_00832000();
// @fnv 0x00832000
// src: GUESS 0x00832000 (confidence: low)
    virtual void __cdecl AdjustThisAndForward_00832000();
};

Derived_00832000::Derived_00832000()
{}
