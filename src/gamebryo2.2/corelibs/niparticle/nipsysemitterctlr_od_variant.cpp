
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiPSysEmitterCtlr.h"
#include "../../../../include/NiBlendBoolInterpolator.h"

struct GlobalObjectO2_00a7b610;

// Emitter update 0x00c1c630 calls this lookup at 0x00639b60; the shared header lacks its declaration.
struct EmitterRateLookup : NiPSysEmitterCtlr
{
    NiBoolInterpolator* NiPSysEmitterCtlr_GetBirthRateInterpolator();
};

void* __cdecl _UseSaveGameBlocks(void* table, unsigned int key);
extern unsigned char DAT_01096968;
extern int g_011f3738;
extern GlobalObjectO2_00a7b610 g_011f3e58;

// @fnv 0x00639b60
// src: XBOX_PDB 0x00639b60
NiBoolInterpolator* EmitterRateLookup::NiPSysEmitterCtlr_GetBirthRateInterpolator()
{
    NiBoolInterpolator* pkBoolInterp;
    NiBlendBoolInterpolator* pkBlendInterp;

    pkBoolInterp = reinterpret_cast<NiBoolInterpolator*>(_UseSaveGameBlocks(
        &g_011f3738, reinterpret_cast<unsigned int>(
            static_cast<const NiPointer<NiInterpolator>&>(m_spControllerInterpolator).operator NiInterpolator*())));

    if (pkBoolInterp)
        return pkBoolInterp;

    pkBlendInterp =
        reinterpret_cast<NiBlendBoolInterpolator*>(_UseSaveGameBlocks(
            &g_011f3e58, reinterpret_cast<unsigned int>(
                static_cast<const NiPointer<NiInterpolator>&>(m_spControllerInterpolator).operator NiInterpolator*())));

    if (pkBlendInterp)
    {
        unsigned char m_ucClipIdentifier = pkBlendInterp->FindHighestWeightIndex();
        if (m_ucClipIdentifier != DAT_01096968)
            return pkBlendInterp->GetValueForIndex(m_ucClipIdentifier);
    }

    return 0;
}
