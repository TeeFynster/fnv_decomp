
// src/gamebryo2.2/corelibs/nimain/nigeometrydata_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nigeometrydata.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nigeometrydata_decls.h"
#pragma optimize("", off)
#pragma optimize("", on)

extern unsigned int* DAT_011f4aa8;
// @fnv 0x00525340
// src: XBOX_PDB 0x00525340
void NiPoint3_UnitizeVector(float* v)
{
    float len2;
    unsigned int* bits = (unsigned int*)&len2;
    short e;
    len2 = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    if (*bits == 0)
    {
        len2 = 0.0f;
    }
    else
    {
        e = (short)((*bits >> 23) - 0x7f);
        *bits &= 0x7fffff;
        if (e & 1)
        {
            *bits |= 0x800000;
        }
        e >>= 1;
        *bits = DAT_011f4aa8[*bits >> 16] | ((e + 0x7f) << 23);
        len2 = 1.0f / len2;
    }
    v[0] = v[0] * len2;
    v[1] = v[1] * len2;
    v[2] = v[2] * len2;
}
