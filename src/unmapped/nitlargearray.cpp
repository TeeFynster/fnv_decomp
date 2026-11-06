#include "../../include/NiTLargeArray.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/NiFixedString.h"
#include "../../include/NiGlobalStringTable.h"

inline NiFixedString& NiFixedString::operator=(const NiFixedString& kString)
{
    if (m_kHandle != kString.m_kHandle)
    {
        GlobalStringHandle kHandle = kString.m_kHandle;
        NiGlobalStringTable::IncRefCount(kHandle);
        NiGlobalStringTable::DecRefCount(m_kHandle);
        m_kHandle = kHandle;
    }
    return *this;
}

typedef NiTLargeArray<NiFixedString, NiTNewInterface<NiFixedString> > NiFixedStringArray;


// Assigns an empty NiFixedString to every element, then resets m_uiSize and m_uiESize to zero.
// @fnv 0x00a637d0
template <> void NiTLargeArray<NiFixedString, NiTNewInterface<NiFixedString> >::RemoveAll()
{
    for (unsigned int uiIndex = 0; uiIndex < m_uiSize; uiIndex++)
        m_pBase[uiIndex] = NiFixedString(static_cast<const char*>(0));
    m_uiSize = 0;
    m_uiESize = 0;
}
