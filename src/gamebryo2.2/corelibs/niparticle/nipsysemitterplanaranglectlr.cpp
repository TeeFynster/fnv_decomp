#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterplanaranglectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* g_01202738;

// @fnv 0x00c2b550
// src: COMMUNITY 0x00c2b550
void* __cdecl NiPSysEmitterPlanarAngleCtlr_GetRTTI()
{
    return &g_01202738;
}

struct NiPSysEmitterPlanarAngleCtlr : NiPSysModifierFloatCtlr
{
    void UpdateFields_00c2b560(float& fValue);
    void SetTargetFloatValue_00c2b570(float fValue);
    void* CreateTargetObj(void* arg);
};

// @fnv 0x00c2b560
// src: GUESS 0x00c2b560 (confidence: low)
void NiPSysEmitterPlanarAngleCtlr::UpdateFields_00c2b560(float& fValue)
{
    fValue = *(float*)((char*)m_pkTargetModifier + 0x28);
}

void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Grows pkStrings if full, then appends the string returned by _FUN_00a7d330(g_01202738) at index m_usSize.
// @fnv 0x00c2b5d0
// src: XBOX_PDB 0x00c2b5d0
void __stdcall NiPSysEmitterPlanarAngleCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* pcString = _FUN_00a7d330((const char*)g_01202738);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pcString);
}

// @fnv 0x00c2b570
// src: XBOX_PDB 0x00c2b570
void __thiscall NiPSysEmitterPlanarAngleCtlr::SetTargetFloatValue_00c2b570(float fValue)
{
    *(float*)((char*)m_pkTargetModifier + 0x28) = fValue;
}

void* __cdecl Object_DispatchCommandFour(unsigned int);

inline void* operator new(unsigned int, void* object) throw()
{
    return object;
}

extern char g_010bf854;
// The shared float-controller header does not yet declare its member-copy entry point.
void __cdecl FUN_00c32de0();

// Allocates a planar-angle controller, initializes it, and copies its members.
// @fnv 0x00c2b580
void* NiPSysEmitterPlanarAngleCtlr::CreateTargetObj(void* arg)
{
    NiPSysEmitterPlanarAngleCtlr* obj =
        (NiPSysEmitterPlanarAngleCtlr*)Object_DispatchCommandFour(sizeof(NiPSysEmitterPlanarAngleCtlr));
    if (obj)
    {
        ::new (obj) NiPSysModifierFloatCtlr;
        *(void**)obj = &g_010bf854;
    }
    else
    {
        obj = 0;
    }
    typedef void (__thiscall* CopyMembers)(NiPSysEmitterPlanarAngleCtlr*, void*, void*);
    ((CopyMembers)&FUN_00c32de0)(this, obj, arg);
    return obj;
}
