// src/fallout_shared/havok/teshavokutilities_o2_variant_od_oy_ob1_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- /Ob1 (unit src/fallout_shared/havok/teshavokutilities_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/teshavokutilities_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teshavokutilities.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/teshavokutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teshavokutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct __declspec(align(16)) V_0062b8d0
{
    char buf[16];

    V_0062b8d0();
};

extern "C" void __cdecl NI2HK(V_0062b8d0* out, const void* in);
extern "C" void __cdecl TESHavokUtilities_AddVelocity_0(void* object, V_0062b8d0* v, unsigned char flag);

// @fnv 0x0062b8d0
// src: XBOX_PDB 0x0062b8d0
void __cdecl TESHavokUtilities_AddVelocity(void* object, const void* in, unsigned char flag)
{
    V_0062b8d0 v;

    NI2HK(&v, in);
    TESHavokUtilities_AddVelocity_0(object, &v, flag);
}
