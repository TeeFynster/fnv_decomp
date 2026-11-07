#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiBoolInterpController.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiSingleInterpController.h"
#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/niboolinterpcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niboolinterpcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

NiBlendInterpolator* __fastcall ConstructBlendInterpolator(NiBlendInterpolator*, int, int, float, int);
// @fnv 0x00a57750
// src: XBOX_PDB 0x00a57750
NiBlendInterpolator* __stdcall NiBoolInterpController_CreateBlendInterpolator(int aiUnused, int aiArg, int aiUnused2, float a4, int a5)
{
    void* pMemory = NiMemObject::operator new(0x34);
    if (pMemory)
        return ConstructBlendInterpolator((NiBlendInterpolator*)pMemory, aiArg, aiArg, a4, a5);
    return 0;
}

extern char const* const g_011f3f08_arg1;
void __stdcall FUN_00a390a0(StrArr*);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
// Appends the string returned by FUN_00a7d330(g_011f3f08_arg1) to the StrArr at index e, growing it by the value at offset 14 plus e when e >= c.
// @fnv 0x00a57800
// src: XBOX_PDB 0x00a57800
void __stdcall NiBoolInterpController_GetViewerStrings(StrArr* apStrings)
{
    FUN_00a390a0(apStrings);
    char* pString = NiViewerStrings_NiGetViewerString_Title(g_011f3f08_arg1);
    unsigned int e = apStrings->m_usSize;
    unsigned int c = apStrings->m_usMaxSize;
    if (e >= c)
        apStrings->SetSize(apStrings->m_usGrowBy + e);
    apStrings->SetAt(e, pString);
}

extern unsigned int DAT_011f404c;
// Casts pkInterp to a NiBoolInterpolator, reads the pose value and passes it to the interpolator's setter.
// @fnv 0x00a577c0
void NiBoolInterpController::SetBoolInterpolatorValue(NiInterpolator* pkInterp, unsigned short usIndex)
{
    bool bPoseValue;
    NiBoolInterpolator* pkBoolInterp;
    if (pkInterp == 0)
        pkBoolInterp = 0;
    else
        pkBoolInterp = (NiBoolInterpolator*)pkInterp->DynamicCast((const NiRTTI*)&DAT_011f404c);
    GetPoseValue(bPoseValue);
    pkBoolInterp->SetBoolValue(bPoseValue);
}

// @fnv 0x00a57710
NiInterpolator* NiBoolInterpController::GetInterpolatorAtIndex(unsigned short usIndex)
{
    bool bPoseValue;
    GetPoseValue(bPoseValue);
    return new NiBoolInterpolator(bPoseValue);
}

// @fnv 0x00a57c10
bool NiBoolInterpController::IsEqual(NiObject* object) const
{
    return NiSingleInterpController::IsEqual(object);
}
