// gamebryo2.2/corelibs/niparticle/nipsysmodifierfloatctlr.cpp: NiPSysModifierFloatCtlr (7 functions)

#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/NiStream.h"
#include "nipsysmodifierfloatctlr_decls.h"
#include "../../../../include/StrArr.h"
// @fnv 0x00c32e10
void NiPSysModifierFloatCtlr::LinkObject(NiStream& stream)
{
    NiPSysModifierCtlr::LinkObject(stream);
    if (stream.m_uiNifFileVersion < 0x0a010068)
    {
        NiFloatData* pFloatData = (NiFloatData*)stream.GetLoadedObject();
        NiObject* pNewInterpolator = new LocalNiFloatInterpolator(pFloatData);
        NiObject* pOldInterpolator = m_spControllerInterpolator.m_pObject;
        if (pOldInterpolator != pNewInterpolator)
        {
            if (pOldInterpolator && !InterlockedDecrement((volatile long*)&pOldInterpolator->m_uiRefCount))
                pOldInterpolator->DeleteThis();
            m_spControllerInterpolator.m_pObject = (NiInterpolator*)pNewInterpolator;
            if (pNewInterpolator)
                InterlockedIncrement((volatile long*)&pNewInterpolator->m_uiRefCount);
        }
    }
}

extern const char* const g_012026d8_arg1;

// @fnv 0x00c32e00
// src: COMMUNITY 0x00c32e00
const char* const* __cdecl NiPSysModifierFloatCtlr_GetRTTI()
{
    return &g_012026d8_arg1;
}

struct FUN_00a3a710_shell
{
    void __thiscall CallVirtualMethodAtOffsetA8(void* arg, void* dummy);
};

// @fnv 0x00a3a710
void __thiscall FUN_00a3a710_shell::CallVirtualMethodAtOffsetA8(void* pObject, void* pUnused)
{
    typedef void(__thiscall * fp)(void*);
    fp f = *(fp*)((char*)(*(void**)pObject) + 0xa8);
    f(pObject);
}

char* __cdecl _FUN_00a7d330(const char*);
void __stdcall AppendModifierInfo(StrArr*);
// Appends the string returned by _FUN_00a7d330(g_012026d8_arg1) to pkStrings, growing the array if its count reaches capacity.
// @fnv 0x00c32f60
// src: XBOX_PDB 0x00c32f60
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr* pkStrings)
{
    AppendModifierInfo(pkStrings);
    char* pString = _FUN_00a7d330(g_012026d8_arg1);
    unsigned int n = pkStrings->m_usSize;
    if (n >= pkStrings->m_usMaxSize)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + n);
    }
    pkStrings->SetAt(n, pString);
}

extern int g_011f3738;
// @fnv 0x00c32e90
// src: XBOX_PDB 0x00c32e90
void __thiscall NiPSysModifierFloatCtlr::SynchronizePoseInterpolator_00c32e90(NiObject* pkInterp, unsigned short usIndex)
{
    NiObject* pkFloatInterp;
    float fValue;
    if (pkInterp == 0)
        pkFloatInterp = 0;
    else
        pkFloatInterp = pkInterp->DynamicCast(&g_011f3738);
    GetValue(&fValue);
    ((LocalNiFloatInterpolator*)pkFloatInterp)->SetFloatValue(fValue);
}

extern const float DAT_01096324;

// @fnv 0x00c32ee0
void NiPSysModifierFloatCtlr::UpdateController(float& fTime)
{
    bool b = (m_uiObjectFlags & 0x20) != 0;
    if ((unsigned char)b & 1)
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (AdvanceController(fTime))
    {
        if (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->AlwaysUpdate())
            return;
    }
    if (m_spControllerInterpolator.m_pObject)
    {
        float fVal;
        if (m_spControllerInterpolator.m_pObject->UpdateFloat(m_fControllerTime, m_pkTarget, fVal))
        {
            SetTargetVal61(fVal);
        }
    }
}

void __cdecl FUN_00a57780();
// @fnv 0x00a44cd0
// src: XBOX_PDB 0x00a44cd0
void __cdecl BSFrustumFOVController_RegisterStreamables()
{
    FUN_00a57780();
}
