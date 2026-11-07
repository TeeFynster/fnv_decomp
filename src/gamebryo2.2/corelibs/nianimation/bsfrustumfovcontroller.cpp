#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BSFrustumFOVController.h"
#include "../../../../include/NiCamera.h"
#include "../../../../include/NiFloatInterpController.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiFloatInterpolator.h"
#include "../../../../include/NiUpdateData.h"
#include <math.h>


// src/gamebryo2.2/corelibs/nianimation/bsfrustumfovcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsfrustumfovcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3ec8;

// @fnv 0x00a42e80
// src: COMMUNITY 0x00a42e80
void* __cdecl BSFrustumFOVController_GetRTTI()
{
    return &g_011f3ec8;
}

extern int DAT_0109780c;

// @fnv 0x00a42ee0
// src: EXE 0x00a42ee0
void* __cdecl BSFrustumFOVController_CreateObject()
{
    void* p = BSFadeNode::operator new(0x38);
    if (p)
    {
        NiFloatInterpController* pController = static_cast<NiFloatInterpController*>(p);
        pController->Init();
        *reinterpret_cast<int**>(pController) = &DAT_0109780c;
        return pController;
    }
    return 0;
}

extern const char* const g_011f5e6c_arg1;
// Walks pkTarget's NiRTTI chain and returns true if any entry matches g_011f5e6c_arg1, false otherwise or when pkTarget is null.
// @fnv 0x00a42d90
// src: XBOX_PDB 0x00a42d90
bool __stdcall BSFrustumFOVController_InterpTargetIsCorrectType(NiObjectNET* pkTarget)
{
    if (!pkTarget)
        return false;
    const NiRTTI* pkRTTI = pkTarget->GetRTTI();
    while (pkRTTI)
    {
        if (pkRTTI == (const NiRTTI*)&g_011f5e6c_arg1)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}

void __stdcall NiFloatInterpController_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(void*);

// @fnv 0x00a42f10
// src: XBOX_PDB 0x00a42f10
void __stdcall BSFrustumFOVController_GetViewerStrings(StrArr* pkStrings)
{
    NiFloatInterpController_GetViewerStrings(pkStrings);
    char* pcString = _FUN_00a7d330(g_011f3ec8);
    unsigned int uiIndex = pkStrings->m_usSize;
    unsigned int uiSize = pkStrings->m_usMaxSize;
    if (uiIndex >= uiSize)
    {
        unsigned int uiGrow = pkStrings->m_usGrowBy;
        pkStrings->SetSize(uiGrow + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcString);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

// Inline reference operations used by the controller's interpolator pointer.
inline void NiInterpolator::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T>
inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T>
inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

// 0x00a42d00 BSFrustumFOVController::LinkObject is in src/staging/blk_00a40000_o2_noehsc_variant.cpp (built without /EHsc).

struct Base840
{
    void NiBoolInterpController_SaveBinary(NiStream& kStream);
    void BSFrustumFOVController_SaveBinary(NiStream& kStream);
};

// @fnv 0x00a44ce0
// src: XBOX_PDB 0x00a44ce0
void Base840::BSFrustumFOVController_SaveBinary(NiStream& kStream)
{
    NiBoolInterpController_SaveBinary(kStream);
}

extern const float DAT_01096324;

// Updates the camera controller time and, if not skipped, applies the interpolator's value to the target's view frustum bounds.
// @fnv 0x00a42dc0
void BSFrustumFOVController::Update(NiUpdateData& kUpdateData)
{
    if ((bool)((m_uiObjectFlags >> 5) & 1))
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (DontDoUpdate(kUpdateData.fTime) &&
             (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator.m_pObject)
    {
        float fValue;
        if (m_spControllerInterpolator.m_pObject->UpdateFloat(m_fControllerTime, m_pkTarget, fValue))
        {
            NiCamera* pkCamera = static_cast<NiCamera*>(m_pkTarget);
            NiFrustum kFrustum = pkCamera->m_kViewFrustum;
            kFrustum.m_fLeftBound = -fValue;
            kFrustum.m_fRightBound = fValue;
            kFrustum.m_fTopBound = fValue * 0.75;
            kFrustum.m_fBottomBound = fValue * -0.75;
            pkCamera->FUN_00a6faf0(kFrustum);
        }
    }
}

// Allocates a controller, copies the base controller members, and returns it.
// 0x00a42e90 BSFrustumFOVController::MakeClone is in src/staging/blk_00a40000_o2_noehsc_variant.cpp (built without /EHsc).

extern void FUN_00a57c10();

// @fnv 0x00a44cf0
// src: XBOX_PDB 0x00a44cf0
void BSFrustumFOVController_IsEqual()
{
    FUN_00a57c10();
}

// Reads the camera's field-of-view angle and writes its arctangent doubled into fValue.
// @fnv 0x00a42cd0
void BSFrustumFOVController::GetFieldOfView(float& afOutValue)
{
    NiCamera* pCamera = static_cast<NiCamera*>(m_pkTarget);
    float v = pCamera->m_kViewFrustum.m_fRightBound;
    afOutValue = atan(v) * 2.0f;
}
