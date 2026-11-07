#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiFloatInterpController.h"
#include "../../../../include/NiFloatInterpolator.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiSingleInterpController.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/nifloatinterpcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatinterpcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __stdcall FUN_00a390a0(StrArr*);
extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
extern "C" const char* const g_011f3ec8_arg1;
extern const NiRTTI g_011f3738;

// These entry points supply the float constructor and pose setter that are
// not yet declared by the shared NiFloatInterpolator header.
extern "C" void FUN_00a3c390();
extern "C" void FUN_00a3c500();

// @fnv 0x00a576c0
// src: XBOX_PDB 0x00a576c0
void __stdcall NiFloatInterpController_GetViewerStrings(StrArr* pkStrings)
{
    FUN_00a390a0(pkStrings);
    char* pStr = NiViewerStrings_NiGetViewerString_Title(g_011f3ec8_arg1);
    unsigned int idx = pkStrings->m_usSize;
    unsigned int cnt = pkStrings->m_usMaxSize;
    if (idx >= cnt)
    {
        unsigned int extra = pkStrings->m_usGrowBy;
        pkStrings->SetSize(idx + extra);
    }
    pkStrings->SetAt(idx, pStr);
}

// Reads the controller's float value and constructs a pose interpolator.
// @fnv 0x00a575e0
NiFloatInterpolator* NiFloatInterpController::CreateFadeNodeFromValue(unsigned short usIndex)
{
    float fValue;
    UpdateFloatValue(&fValue);
    NiFloatInterpolator* pkInterp = static_cast<NiFloatInterpolator*>(BSFadeNode::operator new(sizeof(NiFloatInterpolator)));
    if (pkInterp)
        return reinterpret_cast<NiFloatInterpolator* (__thiscall*)(NiFloatInterpolator*, float)>(&FUN_00a3c390)(pkInterp, fValue);
    return 0;
}

// Casts the interpolator, reads the controller value and sets the float pose.
// @fnv 0x00a57670
void NiFloatInterpController::SetInterpolatorValue(NiInterpolator* pkInterp, unsigned short usIndex)
{
    NiFloatInterpolator* pkFloatInterp;
    float fValue;
    if (!pkInterp)
        pkFloatInterp = 0;
    else
        pkFloatInterp = static_cast<NiFloatInterpolator*>(pkInterp->DynamicCast(&g_011f3738));
    UpdateFloatValue(&fValue);
    reinterpret_cast<void (__thiscall*)(NiFloatInterpolator*, float)>(&FUN_00a3c500)(pkFloatInterp, fValue);
}

// @fnv 0x00a57630
void NiFloatInterpController::LinkObject(NiStream& kStream)
{
    NiSingleInterpController::LinkObject(kStream);
}

// @fnv 0x00a57c70
void NiFloatInterpController::LoadBinary(NiStream& kStream)
{
    NiSingleInterpController::LoadBinary(kStream);
}
