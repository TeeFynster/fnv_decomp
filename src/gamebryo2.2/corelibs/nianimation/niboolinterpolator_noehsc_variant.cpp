#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/NiBoolData.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiRefObject.h"

// src/gamebryo2.2/corelibs/nianimation/niboolinterpolator_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp lists /MT /O2 /GS /EHsc /Gy).

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline NiPointer<NiBoolData>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

inline NiPointer<NiBoolData>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

inline NiPointer<NiBoolData>& NiPointer<NiBoolData>::operator=(const NiPointer& ptr)
{
    NiBoolData* pObject = ptr.m_pObject;
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

// NiBoolData's range-cloning operation at 0x00a53910 is not yet declared by its shared header.
void __fastcall CloneBoolDataForTimeRange(NiBoolData*, void*, float, float, NiPointer<NiBoolData>&);

// @fnv 0x00a53300
NiInterpolator* NiBoolInterpolator::CloneForTimeRange(float fA, float fB)
{
    NiBoolInterpolator* pkCopy = static_cast<NiBoolInterpolator*>(NiInterpolator::CloneForTimeRange(fA, fB));
    if (m_spBoolData.m_pObject)
    {
        NiPointer<NiBoolData> spData;
        typedef void (__thiscall* CloneRangeFunction)(NiBoolData*, float, float, NiPointer<NiBoolData>&);
        reinterpret_cast<CloneRangeFunction>(&CloneBoolDataForTimeRange)(m_spBoolData.m_pObject, fA, fB, spData);
        pkCopy->m_spBoolData = spData;
        pkCopy->m_uiLastKeyIndex = 0;
    }
    return pkCopy;
}
