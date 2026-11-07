// src/gamebryo2.2/corelibs/niparticle/nipsysfieldmaxdistancectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldmaxdistancectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

extern const void* g_01202710;

// @fnv 0x00c2b040
// src: COMMUNITY 0x00c2b040
const void* __cdecl NiPSysFieldMaxDistanceCtlr_GetRTTI()
{
    return &g_01202710;
}

struct NiPSysFieldMaxDistanceCtlr : NiPSysModifierFloatCtlr
{
    void SetTargetFloatValue(float fValue);
    void* CreateClone_00c2b070(unsigned int a1);
};

// @fnv 0x00c2b050
// src: XBOX_PDB 0x00c2b050
void NiPSysFieldMaxDistanceCtlr::SetTargetFloatValue(float fValue)
{
    float* p = reinterpret_cast<float*>(m_pkTargetModifier);
    p[0xA] = fValue;
    p[0xB] = fValue * fValue;
}

void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// @fnv 0x00c2b0c0
// src: XBOX_PDB 0x00c2b0c0
void __stdcall NiPSysFieldMaxDistanceCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* psz = _FUN_00a7d330((const char*)g_01202710);
    unsigned int uSize = pkStrings->m_usSize;
    if (uSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uSize, psz);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern char DAT_010bf354[];

inline void* operator new(unsigned int, void* location)
{
    return location;
}

// The shared base has no declaration for its copy helper at 0x00c32de0.
void __cdecl FUN_00c32de0();

// Allocates a 0x40-byte object, runs its base constructor and sets its vtable, then passes it with a1 to FUN_00c32de0 and returns it.
// @fnv 0x00c2b070
// src: XBOX_PDB 0x00c2b070
void* NiPSysFieldMaxDistanceCtlr::CreateClone_00c2b070(unsigned int a1)
{
    NiPSysFieldMaxDistanceCtlr* p = (NiPSysFieldMaxDistanceCtlr*)Object_DispatchCommandFour(0x40);
    if (p != 0)
    {
        ::new (p) NiPSysModifierFloatCtlr;
        *reinterpret_cast<void**>(p) = (void*)&DAT_010bf354;
    }
    else
    {
        p = 0;
    }
    typedef void (__thiscall* CopyMemberData)(NiPSysFieldMaxDistanceCtlr*, NiPSysFieldMaxDistanceCtlr*, unsigned int);
    reinterpret_cast<CopyMemberData>(&FUN_00c32de0)(this, p, a1);
    return p;
}
