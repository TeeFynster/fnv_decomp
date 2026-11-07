
// src/gamebryo2.2/corelibs/nimain/niobjectnet_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "niobjectnet_decls.h"
#pragma optimize("", off)
#pragma optimize("", on)
#pragma optimize("", off)
#pragma optimize("", on)
#pragma optimize("", off)
#pragma optimize("", on)

struct FUN_007408d0_Class
{
    char m_auiShapeKeys[0x24];
    int m_val;
    bool NiControllerSequence_SetCycleType(int a);
};
// @fnv 0x007408d0
// src: XBOX_PDB 0x007408d0
bool FUN_007408d0_Class::NiControllerSequence_SetCycleType(int a)
{
    if (a == 2 || a == 0)
    {
        m_val = a;
        return true;
    }
    return false;
}
