
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterinitialradiusctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterinitialradiusctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

extern "C" void* g_01202748;

// @fnv 0x00c2b750
// src: COMMUNITY 0x00c2b750
void* __cdecl NiPSysEmitterInitialRadiusCtlr_GetRTTI()
{
    return &g_01202748;
}

struct NiPSysEmitterInitialRadiusCtlr : NiPSysModifierFloatCtlr
{
    NiPSysEmitterInitialRadiusCtlr() throw()
    {}
    virtual ~NiPSysEmitterInitialRadiusCtlr();

    void GetTargetFloatValue_00c2b760(float& fOut) const;
    void SetTargetFloatValue_00c2b770(float value);
    NiPSysEmitterInitialRadiusCtlr* CreateClone_00c2b780(void* pvProcess);
};

// @fnv 0x00c2b760
// src: XBOX_PDB 0x00c2b760
void NiPSysEmitterInitialRadiusCtlr::GetTargetFloatValue_00c2b760(float& fOut) const
{
    fOut = *(float*)((const char*)m_pkTargetModifier + 0x40);
}

// @fnv 0x00c2b770
// src: XBOX_PDB 0x00c2b770
void __thiscall NiPSysEmitterInitialRadiusCtlr::SetTargetFloatValue_00c2b770(float value)
{
    float* p = reinterpret_cast<float*>(m_pkTargetModifier);
    p[0x10] = value;
}

void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330(g_01202748) to pkStrings, growing it via SetSize when full and storing it with SetAt.
// @fnv 0x00c2b820
// src: XBOX_PDB 0x00c2b820
void __stdcall NiPSysEmitterInitialRadiusCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* psz = _FUN_00a7d330((const char*)g_01202748);
    unsigned int uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIdx + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIdx, psz);
}

// The shared base does not declare its copy helper at 0x00c32de0.
void __cdecl FUN_00c32de0();

// @fnv 0x00c2b780
// src: XBOX_PDB 0x00c2b780
NiPSysEmitterInitialRadiusCtlr* NiPSysEmitterInitialRadiusCtlr::CreateClone_00c2b780(void* pvProcess)
{
    NiPSysEmitterInitialRadiusCtlr* pkClone = new NiPSysEmitterInitialRadiusCtlr;
    typedef void (__thiscall* CopyModifierData)(NiPSysModifierFloatCtlr*, NiPSysModifierFloatCtlr*, void*);
    reinterpret_cast<CopyModifierData>(&FUN_00c32de0)(this, pkClone, pvProcess);
    return pkClone;
}
