// src/gamebryo2.2/corelibs/niparticle/nipsysemitterspeedctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterspeedctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/NiPSysEmitter.h"
#include "../../../../include/StrArr.h"
#include <stddef.h>

inline void* operator new(size_t, NiPSysModifierFloatCtlr* object)
{
    return object;
}

extern const void* g_01202728;

// @fnv 0x00c2b360
// src: COMMUNITY 0x00c2b360
const void* __cdecl NiPSysEmitterSpeedCtlr_GetRTTI()
{
    return &g_01202728;
}

struct NiPSysEmitterSpeedCtlr : NiPSysModifierFloatCtlr
{
    void GetEmissionSpeed(float& rfValue);
    void UpdateFields_00c29fa0(float fValue);
    void FUN_00c32de0(void* obj, unsigned int a1);
    void* CreateClone_00c2b380(unsigned int a1);
};

// @fnv 0x00c2b370
// src: GUESS 0x00c2b370 (confidence: high)
void NiPSysEmitterSpeedCtlr::GetEmissionSpeed(float& rfValue)
{
    NiPSysEmitter* pkTarget = static_cast<NiPSysEmitter*>(m_pkTargetModifier);
    rfValue = pkTarget->m_fEmissionSpeed;
}

// @fnv 0x00c29fa0
// src: GUESS 0x00c29fa0 (confidence: low)
void NiPSysEmitterSpeedCtlr::UpdateFields_00c29fa0(float fValue)
{
    static_cast<NiPSysEmitter*>(m_pkTargetModifier)->m_fEmissionSpeed = fValue;
}
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const void*);
// @fnv 0x00c2b3d0
// src: XBOX_PDB 0x00c2b3d0
void __stdcall NiPSysEmitterSpeedCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* psz = _FUN_00a7d330(g_01202728);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, psz);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern char DAT_010bf654[];

// Allocates a 0x40-byte object, runs its base constructor and sets its vtable, then passes it to FUN_00c32de0 with a1 and returns it.
// @fnv 0x00c2b380
// src: XBOX_PDB 0x00c2b380
void* NiPSysEmitterSpeedCtlr::CreateClone_00c2b380(unsigned int a1)
{
    NiPSysEmitterSpeedCtlr* p = (NiPSysEmitterSpeedCtlr*)Object_DispatchCommandFour(0x40);
    if (p != 0)
    {
        ::new (static_cast<NiPSysModifierFloatCtlr*>(p)) NiPSysModifierFloatCtlr;
        *(void**)p = (void*)&DAT_010bf654;
    }
    else
    {
        p = 0;
    }
    this->FUN_00c32de0(p, a1);
    return p;
}
