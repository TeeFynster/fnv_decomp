#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiLookAtInterpolator.h"

// This destructor matches under /MT /O2 /GS /Gy, without /EHsc.
extern "C" char* g_StaticFixedString_011f49e0;


inline NiFixedString& NiFixedString::operator=(const NiFixedString& kString)
{
    char* h = kString.m_kHandle;
    if (m_kHandle != h)
    {
        NiGlobalStringTable::IncRefCount(h);
        NiGlobalStringTable::DecRefCount(m_kHandle);
        m_kHandle = h;
    }
    return *this;
}

inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

// @fnv 0x00a4be20
NiLookAtInterpolator::~NiLookAtInterpolator()
{
    m_kTargetNodeName = *(NiFixedString*)&g_StaticFixedString_011f49e0;
    NiInterpolator** pItem = m_pItems + 3;
    for (int i = 2; i >= 0; --i)
    {
        NiInterpolator* pObject = *--pItem;
        if (pObject != 0)
            pObject->DecRefCount();
    }
}
