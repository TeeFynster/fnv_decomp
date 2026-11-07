#include "../../../../include/NiObject.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiParticleSystem.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglectlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglectlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern NiRTTI g_012026f0;

// @fnv 0x00c2a1a0
// src: COMMUNITY 0x00c2a1a0
const NiRTTI* __cdecl NiPSysInitialRotAngleCtlr_GetRTTI()
{
    return &g_012026f0;
}

extern NiRTTI _g_01202528;
inline bool NiObject::IsKindOfType(const NiRTTI* pkRTTI) const
{
    const NiRTTI* pkMy = GetRTTI();
    while (pkMy)
    {
        if (pkMy == pkRTTI)
            return true;
        pkMy = pkMy->m_pBaseRTTI;
    }
    return false;
}

struct BaseStandIn
{
    bool IsTargetParticleSystem(NiObjectNET*);
};
struct NiPSysInitialRotAngleCtlr : BaseStandIn
{
    bool IsModifierOfType(NiObjectNET*);
};
// @fnv 0x00c2a210
bool NiPSysInitialRotAngleCtlr::IsModifierOfType(NiObjectNET* pkTarget)
{
    if (!BaseStandIn::IsTargetParticleSystem(pkTarget))
        return false;
    NiPSysModifier* pkModifier = static_cast<NiParticleSystem*>(pkTarget)->GetModifier(
        *reinterpret_cast<const NiFixedString*>((char*)this + 0x38));
    if (!pkModifier)
        return false;
    return pkModifier->IsKindOfType(&_g_01202528);
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
// @fnv 0x00c2a260
// src: XBOX_PDB 0x00c2a260
void __stdcall NiPSysInitialRotAngleCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* pStr = NiViewerStrings_NiGetViewerString_Title(g_012026f0.m_pcName);
    unsigned int iCount = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int iSize = *(unsigned short*)((char*)pkStrings + 8);
    if (iCount >= iSize)
        pkStrings->SetSize(iCount + *(unsigned short*)((char*)pkStrings + 14));
    pkStrings->SetAt(iCount, pStr);
}

extern char DAT_010befbc;
void* __cdecl Object_DispatchCommandFour(unsigned int);

struct SpawnedObject
{
    void FUN_00c32d80();
};

struct SpawnedCtlr
{
    void FUN_00c32de0(SpawnedObject* pkObj, void* pArg);
    SpawnedObject* CreateSpawnedObject(void* pArg);
};

// Allocates a 0x40-byte SpawnedObject, initialises it, passes it to FUN_00c32de0 with pArg, and returns it (or null on allocation failure).
// @fnv 0x00c2a1c0
SpawnedObject* SpawnedCtlr::CreateSpawnedObject(void* pArg)
{
    SpawnedObject* pkObj = (SpawnedObject*)Object_DispatchCommandFour(0x40);
    if (pkObj != 0)
    {
        pkObj->FUN_00c32d80();
        *(char**)pkObj = &DAT_010befbc;
    }
    else
    {
        pkObj = 0;
    }
    FUN_00c32de0(pkObj, pArg);
    return pkObj;
}
