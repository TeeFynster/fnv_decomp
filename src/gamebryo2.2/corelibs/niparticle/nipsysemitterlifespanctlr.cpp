
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterlifespanctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterlifespanctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

extern "C" void* g_01202740;

// @fnv 0x00c2b650
void* __cdecl FUN_00c2b650()
{
    return &g_01202740;
}

class NiPSysEmitterLifeSpanCtlr : public NiPSysModifierFloatCtlr
{
public:
    NiPSysEmitterLifeSpanCtlr() throw()
    {}
    virtual ~NiPSysEmitterLifeSpanCtlr();

    void __thiscall FUN_00c2b660(float& fValue);
    void FUN_00c2b670(float fValue);
    void CopyMemberData(NiPSysEmitterLifeSpanCtlr* pkDest, void* pvCloning);
    NiPSysEmitterLifeSpanCtlr* FUN_00c2b680(void* pvCloning);
};

// @fnv 0x00c2b660
void __thiscall NiPSysEmitterLifeSpanCtlr::FUN_00c2b660(float& fValue)
{
    NiPSysModifier* p = m_pkTargetModifier;
    fValue = *(float*)((char*)p + 0x48);
}

// @fnv 0x00c2b670
void NiPSysEmitterLifeSpanCtlr::FUN_00c2b670(float fValue)
{
    NiPSysModifier* p = m_pkTargetModifier;
    float* f = (float*)((char*)p + 0x48);
    *f = fValue;
}
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
// Appends the string returned by _FUN_00a7d330(g_01202740) to pkStrings, growing the array by its growth step when it is full.
// @fnv 0x00c2b6d0
void __stdcall FUN_00c2b6d0(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pszStr = _FUN_00a7d330(g_01202740);
    unsigned int uSize = pkStrings->m_usSize;
    unsigned int uCap = pkStrings->m_usMaxSize;
    if (uSize >= uCap)
    {
        pkStrings->SetSize(uSize + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(uSize, pszStr);
}

// @fnv 0x00c2b680
NiPSysEmitterLifeSpanCtlr* NiPSysEmitterLifeSpanCtlr::FUN_00c2b680(void* pvCloning)
{
    NiPSysEmitterLifeSpanCtlr* pkClone = new NiPSysEmitterLifeSpanCtlr;
    CopyMemberData(pkClone, pvCloning);
    return pkClone;
}
