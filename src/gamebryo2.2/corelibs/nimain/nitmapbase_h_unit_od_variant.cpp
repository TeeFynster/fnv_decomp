
// src/gamebryo2.2/corelibs/nimain/nitmapbase_h_unit_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitmapbase_h_unit.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nitmapbase.inl"

struct FUN_00404cd0_Class
{
    void __thiscall UpdateFields_00404c80();
    void* __thiscall FUN_00404cd0(unsigned int flags);
};

// @fnv 0x00404cd0
void* __thiscall FUN_00404cd0_Class::FUN_00404cd0(unsigned int flags)
{
    UpdateFields_00404c80();
    if (flags & 1)
        operator delete(this);
    return this;
}
