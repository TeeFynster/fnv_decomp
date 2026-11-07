
// src/gamebryo2.2/corelibs/nimain/nistringsextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nistringsextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiStringsExtraData.h"

extern "C" void* g_011f5ebc;

// @fnv 0x00a94820
// src: COMMUNITY 0x00a94820
void* __cdecl NiStringsExtraData_GetRTTI()
{
    return &g_011f5ebc;
}

extern int DAT_010a0134;

// @fnv 0x00a94930
// src: EXE 0x00a94930
void* __cdecl NiStringsExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p)
    {
        NiExtraData* pExtraData = static_cast<NiExtraData*>(p);
        pExtraData->FUN_00a7b2e0();
        *static_cast<void**>(p) = &DAT_010a0134;
        *(static_cast<int*>(p) + 4) = 0;
        *(static_cast<int*>(p) + 3) = 0;
        return p;
    }
    return 0;
}

void __cdecl NiFreeAlias(void*);
// @fnv 0x00a94830
void __thiscall NiStringsExtraData::FreeStrings()
{
    *reinterpret_cast<void**>(this) = &DAT_010a0134;
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
        NiFreeAlias(m_ppData[i]);
    NiFreeAlias(m_ppData);
    m_ppData = 0;
    DestroyFields_00a7b300();
}

// Calls FreeStrings, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00a94970
void* __thiscall NiStringsExtraData::FUN_00a94970(unsigned int flags)
{
    FreeStrings();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);

// @fnv 0x00a94880
void __thiscall NiStringsExtraData::CopyStringsExtraData(NiStringsExtraData* pDest, void* pCloning)
{
    unsigned int i;
    unsigned int uiLen;

    NiExtraData::CopyMembers_00a7b330(pDest, pCloning);

    if (m_ppcValue && m_uiSize > 0)
    {
        pDest->m_uiItemCount = m_uiSize;
        pDest->m_ppData = (void**)_NiMalloc(m_uiSize * 4);

        for (i = 0; i < m_uiSize; ++i)
        {
            if (m_ppcValue[i])
            {
                uiLen = strlen(m_ppcValue[i]) + 1;
                ((char**)pDest->m_ppData)[i] = (char*)_NiMalloc(uiLen);
                _strcpy_s(((char**)pDest->m_ppData)[i], uiLen, m_ppcValue[i]);
            }
            else
            {
                ((char**)pDest->m_ppData)[i] = 0;
            }
        }
    }
    else
    {
        pDest->m_ppData = 0;
        pDest->m_uiItemCount = 0;
    }
}

void* __cdecl _NiMalloc_00aa1070(unsigned int size);

static __forceinline void BinRead(NiBinaryStream* b, void* v, unsigned int bytes, unsigned int n)
{
    unsigned int sz = 4;
    b->m_uiAbsoluteCurrentPos += b->m_pfnRead(b, v, bytes, &sz, n);
}
static __forceinline void LoadU32(NiStream* s, unsigned int* v, unsigned int n)
{
    BinRead(s->m_pkIstr, v, 4, n);
}

// @fnv 0x00a94a50
void NiStringsExtraData::LoadStringArray(NiStream* stream)
{
    NiExtraData::LoadBinary(*stream);
    LoadU32(stream, &m_uiItemCount, 1);
    if (m_uiItemCount > 0)
    {
        m_ppData = (void**)_NiMalloc_00aa1070(m_uiItemCount * 4);
        for (unsigned int i = 0; i < m_uiItemCount; i++)
        {
            m_ppData[i] = 0;
            stream->ReadStreamString(m_ppcValue[i]);
        }
    }
    else
    {
        m_ppData = 0;
    }
}

extern "C" void* g_011f5ebc;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* __cdecl NiGetViewerString_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* __cdecl ViewerStringStr(const char* pcPrefix, const char* pcValue);

struct ViewerStringArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);

    inline unsigned int Add(char* const& element)
    {
        unsigned int i = m_usSize;
        if (i >= m_usMaxSize)
            SetSize(m_usGrowBy + i);
        SetAt(i, element);
        return i;
    }
};

struct ExtraDataViewerBase : NiExtraData
{
    // The shared base does not yet declare this viewer-string overload.
    void GetViewerStrings(ViewerStringArray* apViewerStrings);
};

// Appends the base viewer strings, the m_uiSize value and one formatted string per m_ppcValue entry to the viewer string array.
// @fnv 0x00a94ae0
// src: XBOX_PDB 0x00a94ae0
void NiStringsExtraData::GetViewerStrings_00a94ae0(ViewerStringArray* pViewerStrings)
{
    reinterpret_cast<ExtraDataViewerBase*>(this)->ExtraDataViewerBase::GetViewerStrings(pViewerStrings);
    pViewerStrings->Add(NiViewerStrings_NiGetViewerString_Title((const char*)g_011f5ebc));
    pViewerStrings->Add(NiGetViewerString_00a7d510("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        char* pcValue = ViewerStringStr("m_ppcValue[i]", m_ppcValue[i]);
        unsigned int uiIndex = pViewerStrings->m_usSize;
        if (uiIndex >= pViewerStrings->m_usMaxSize)
            pViewerStrings->SetSize(pViewerStrings->m_usGrowBy + uiIndex);
        if (uiIndex >= pViewerStrings->m_usSize)
        {
            pViewerStrings->m_usSize = (unsigned short)(uiIndex + 1);
            if (pcValue)
                pViewerStrings->m_usESize++;
        }
        else if (pcValue)
        {
            if (!pViewerStrings->m_pBase[uiIndex])
                pViewerStrings->m_usESize++;
        }
        else
        {
            if (pViewerStrings->m_pBase[uiIndex])
                pViewerStrings->m_usESize--;
        }
        pViewerStrings->m_pBase[uiIndex] = pcValue;
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_010a0134;

static __forceinline NiStringsExtraData* InitializeStringsExtraData(void* memory) throw()
{
    NiStringsExtraData* p = static_cast<NiStringsExtraData*>(memory);
    p->NiExtraData::FUN_00a7b2e0();
    *reinterpret_cast<void**>(p) = &DAT_010a0134;
    p->m_ppData = 0;
    p->m_uiItemCount = 0;
    return p;
}

// @fnv 0x00a94990
// src: XBOX_PDB 0x00a94990
NiStringsExtraData* NiStringsExtraData::CreateClone_00a94990(void* pCloning)
{
    void* memory = Object_DispatchCommandFour(0x14);
    NiStringsExtraData* p = memory ? InitializeStringsExtraData(memory) : 0;
    CopyStringsExtraData(p, pCloning);
    return p;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

template <class T> inline void BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void SaveBinaryValue(NiStream& kStream, const T& value)
{
    BinaryStreamSave(*kStream.m_pkOstr, &value);
}

// @fnv 0x00a949f0
// src: XBOX_PDB 0x00a949f0
void NiStringsExtraData::SaveBinary_00a949f0(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    SaveBinaryValue(stream, m_uiSize);
    for (unsigned int i = 0; i < m_uiSize; i++)
        stream.WriteStreamString(m_ppcValue[i]);
}

extern "C" int __cdecl strcmp(const char* pcA, const char* pcB);

// Compares two NiStringsExtraData objects for equality by checking m_uiSize and each m_ppcValue string via strcmp.
// @fnv 0x00a94760
bool NiStringsExtraData::IsEqual(NiObject* pkObject) const
{
    if (!pkObject)
        return false;

    NiStringsExtraData* pkExtra = static_cast<NiStringsExtraData*>(pkObject);

    if (m_uiSize != pkExtra->m_uiSize)
        return false;

    if ((m_ppcValue && !pkExtra->m_ppcValue) || (!m_ppcValue && pkExtra->m_ppcValue))
        return false;

    if (m_ppcValue)
    {
        for (unsigned int i = 0; i < m_uiSize; i++)
        {
            if ((m_ppcValue[i] && !pkExtra->m_ppcValue[i]) || (!m_ppcValue[i] && pkExtra->m_ppcValue[i]))
            {
                return false;
            }

            if (m_ppcValue[i] && strcmp(m_ppcValue[i], pkExtra->m_ppcValue[i]) != 0)
                return false;
        }
    }

    return true;
}
