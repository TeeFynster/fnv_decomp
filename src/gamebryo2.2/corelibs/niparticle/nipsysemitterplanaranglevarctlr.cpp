// src/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglevarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglevarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiPSysEmitter.h"

extern "C" void* g_01202730;

// @fnv 0x00c2b460
// src: COMMUNITY 0x00c2b460
void* __cdecl NiPSysEmitterPlanarAngleVarCtlr_GetRTTI()
{
    return &g_01202730;
}

struct NiPSysEmitterPlanarAngleVarCtlr : NiPSysModifierFloatCtlr
{
    virtual ~NiPSysEmitterPlanarAngleVarCtlr() throw();
    void __thiscall SetPlanarAngleVariation(float fValue);
    void GetPlanarAngleVariation(float& rfValue);
    void FUN_00c32de0(NiPSysEmitterPlanarAngleVarCtlr*, void*);
    NiPSysEmitterPlanarAngleVarCtlr* CreateClone_00c2b480(void* volatile argument);
};

// @fnv 0x00c2b470
// src: GUESS 0x00c2b470 (confidence: high)
void __thiscall NiPSysEmitterPlanarAngleVarCtlr::SetPlanarAngleVariation(float fValue)
{
    static_cast<NiPSysEmitter*>(m_pkTargetModifier)->m_fPlanarAngleVariation = fValue;
}

// @fnv 0x00c2a8b0
// src: GUESS 0x00c2a8b0 (confidence: high)
void NiPSysEmitterPlanarAngleVarCtlr::GetPlanarAngleVariation(float& rfValue)
{
    rfValue = static_cast<NiPSysEmitter*>(m_pkTargetModifier)->m_fPlanarAngleVariation;
}

void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
// Appends the string returned by _FUN_00a7d330(g_01202730) to the end of pkStrings, growing the array if it is full.
// @fnv 0x00c2b4d0
// src: XBOX_PDB 0x00c2b4d0
void __stdcall NiPSysEmitterPlanarAngleVarCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* pcString = _FUN_00a7d330(g_01202730);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}

#include "../../../../include/NiMemObject.h"
inline void* __cdecl operator new(unsigned int, void* memory)
{
    return memory;
}
// Allocates and constructs a controller, copies its data, and returns the clone or null.
// @fnv 0x00c2b480
// src: XBOX_PDB 0x00c2b480
NiPSysEmitterPlanarAngleVarCtlr* NiPSysEmitterPlanarAngleVarCtlr::CreateClone_00c2b480(void* volatile argument)
{
    NiPSysEmitterPlanarAngleVarCtlr* clone = (NiPSysEmitterPlanarAngleVarCtlr*)NiMemObject::operator new(0x40);
    if (clone)
    {
        ::new ((void*)clone) NiPSysEmitterPlanarAngleVarCtlr;
        FUN_00c32de0(clone, argument);
    }
    else
    {
        void* processCopy = argument;
        clone = 0;
        FUN_00c32de0(clone, processCopy);
    }
    return clone;
}
