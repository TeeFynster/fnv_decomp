#include "../../include/NiTLargeArray.h"

// src/unmapped/nitlargearray_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/unmapped/nitlargearray.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/MemoryManager.h"
#include "../../include/NiFixedString.h"

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


extern MemoryManager _g_memoryManager;

void operator delete[](void* p)
{
    _g_memoryManager.Deallocate(p);
}

inline bool NiFixedString::operator!=(const NiFixedString& b) const
{
    return m_kHandle != b.m_kHandle;
}

NiFixedString* __cdecl FUN_00a63ae0(unsigned int auiCount);

struct MyNiFixedStringArray : public NiFixedStringArray
{
    void FUN_00a65140(unsigned int uiMaxSize);
};

// @fnv 0x00a65140
void MyNiFixedStringArray::FUN_00a65140(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_uiMaxSize)
    {
        return;
    }

    unsigned int i;
    if (uiMaxSize < m_uiSize)
    {
        for (i = uiMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != NiFixedString(static_cast<const char*>(0)))
            {
                m_pBase[i] = NiFixedString(static_cast<const char*>(0));
                m_uiESize--;
            }
        }

        m_uiSize = uiMaxSize;
    }

    NiFixedString* pSaveBase = m_pBase;
    m_uiMaxSize = uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = FUN_00a63ae0(m_uiMaxSize);

        for (i = 0; i < m_uiSize; i++)
        {
            m_pBase[i] = pSaveBase[i];
        }

        for (i = m_uiSize; i < m_uiMaxSize; i++)
        {
            m_pBase[i] = NiFixedString(static_cast<const char*>(0));
        }
    }
    else
    {
        m_pBase = 0;
    }

    delete[] pSaveBase;
}
