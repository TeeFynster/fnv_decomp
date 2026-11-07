
// src/gamebryo2.2/corelibs/nimain/niintegersextradata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niintegersextradata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiIntegersExtraData.h"
extern int DAT_010a0c7c;

// Local until include/NiIntegersExtraData.h supplies the integer-array fields and methods:
// RTTI identifies vtable 0x010a0c7c as NiIntegersExtraData; the shared header's LoadBinary (0x00c540a0) belongs to BSFurnitureMarker (vtable 0x010c2a94).

extern char const* const g_012043a4_arg1;

// @fnv 0x00a99940
// src: COMMUNITY 0x00a99940
char const* const* __cdecl NiIntegersExtraData_GetRTTI()
{
    return &g_012043a4_arg1;
}

extern "C" void __cdecl NiFreeAlias(void* p);
// @fnv 0x00a99950
// src: GUESS 0x00a99950 (confidence: low)
void NiIntegersExtraData::SetVtableAndProcessState_00a99950()
{
    void* p = m_piValue;
    *(int*)this = (int)&DAT_010a0c7c;
    NiFreeAlias(p);
    m_piValue = 0;
    NiExtraData::DestroyFields_00a7b300();
}

// @fnv 0x00a99980
// src: EXE 0x00a99980
NiIntegersExtraData* NiIntegersExtraData::NiIntegersExtraData_00a99980(int a, int b)
{
    NiExtraData::FUN_00a7b2e0();
    *(int*)this = (int)&DAT_010a0c7c;
    m_piValue = 0;
    AssignPointerArray(a, b);
    return this;
}

// @fnv 0x00a99a10
// src: EXE 0x00a99a10
NiExtraData* NiIntegersExtraData_CreateObject()
{
    NiIntegersExtraData* data = static_cast<NiIntegersExtraData*>(NiIntegersExtraData::operator new(sizeof(NiIntegersExtraData)));
    if (data)
    {
        data->FUN_00a7b2e0();
        ((unsigned int*)data)[0] = reinterpret_cast<unsigned int>(&DAT_010a0c7c);
        data->m_piValue = 0;
        data->m_uiSize = 0;
        return data;
    }
    return 0;
}

// @fnv 0x00a99a50
NiIntegersExtraData* NiIntegersExtraData::FUN_00a99a50(int flag)
{
    *(int*)this = (int)&DAT_010a0c7c;
    NiFreeAlias(m_piValue);
    m_piValue = 0;
    NiExtraData::DestroyFields_00a7b300();
    if (flag & 1)
        operator delete(this, 0x14);
    return this;
}

// @fnv 0x00a998e0
// src: XBOX_PDB 0x00a998e0
bool NiIntegersExtraData::IsEqual_00a998e0(NiIntegersExtraData* pObject)
{
    NiIntegersExtraData* pExtra = pObject;
    unsigned int i;
    if (!pExtra)
        return false;
    if (m_uiSize != pExtra->m_uiSize)
        return false;
    if (m_piValue && !pExtra->m_piValue)
        return false;
    if (!m_piValue && pExtra->m_piValue)
        return false;
    if (m_piValue)
    {
        for (i = 0; i < m_uiSize; i++)
        {
            if (m_piValue[i] != pExtra->m_piValue[i])
                return false;
        }
    }
    return true;
}

void* __cdecl _NiMalloc(unsigned int);
// @fnv 0x00a99870
// src: XBOX_PDB 0x00a99870
void NiIntegersExtraData::CopyMembers_00a99870(NiIntegersExtraData* pDest, void* pCloning)
{
    NiExtraData::CopyMembers_00a7b330(pDest, pCloning);
    if (m_piValue && m_uiSize > 0)
    {
        pDest->m_uiSize = m_uiSize;
        pDest->m_piValue = (int*)_NiMalloc(m_uiSize * 4);
        for (unsigned int i = 0; i < m_uiSize; ++i)
            pDest->m_piValue[i] = m_piValue[i];
    }
    else
    {
        pDest->m_piValue = 0;
        pDest->m_uiSize = 0;
    }
}

// Gamebryo NiTArray.inl bodies this unit's original inlines (the shared NiTArray declares them):
template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element)
            m_usESize++;
    }
    else if (element)
    {
        if (!m_pBase[uiIndex])
            m_usESize++;
    }
    else
    {
        if (m_pBase[uiIndex])
            m_usESize--;
    }
    m_pBase[uiIndex] = element;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

char* CreateDebugString(const char* pcText);
char* CreateDebugString(const char* pcPrefix, unsigned int uiValue);
char* CreateDebugString(const char* pcPrefix, int iValue);

extern const char* g_011f5f24;

// @fnv 0x00a99b20
void NiIntegersExtraData::GetViewerStrings(NiViewerStringsArray* pkStrings)
{
    BaseGetViewerStrings(pkStrings);
    pkStrings->Add(CreateDebugString(g_011f5f24));
    pkStrings->Add(CreateDebugString("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
        pkStrings->Add(CreateDebugString("m_piValue[i]", m_piValue[i]));
}

// @fnv 0x00a999b0
// src: XBOX_PDB 0x00a999b0
NiExtraData* NiIntegersExtraData::CreateClone_00a999b0(void* pvProcess)
{
    NiIntegersExtraData* pkClone = new NiIntegersExtraData;
    CopyMembers_00a99870(pkClone, pvProcess);
    return pkClone;
}
