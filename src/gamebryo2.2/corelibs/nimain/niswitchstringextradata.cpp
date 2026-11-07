#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nimain/niswitchstringextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niswitchstringextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern NiRTTI g_011f5eac;

// @fnv 0x00a93740
// src: COMMUNITY 0x00a93740
NiRTTI* __cdecl NiSwitchStringExtraData_GetRTTI()
{
    return &g_011f5eac;
}

extern int DAT_0109ff64;

// @fnv 0x00a93870
// src: EXE 0x00a93870
void* __cdecl NiSwitchStringExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x18);
    if (p)
    {
        NiExtraData* pExtra = static_cast<NiExtraData*>(p);
        pExtra->FUN_00a7b2e0();
        *reinterpret_cast<int**>(p) = &DAT_0109ff64;
        reinterpret_cast<int*>(p)[4] = 0;
        reinterpret_cast<int*>(p)[3] = 0;
        reinterpret_cast<int*>(p)[5] = -1;
        return p;
    }
    return 0;
}

void __cdecl NiFreeAlias(void*);
struct NiFile;
struct FUN_00a93750_shell
{
    void* m_pData;
    NiRTTI* m_pRTTI;
    NiFile* m_pFile;
    unsigned int m_nCount;
    void** m_pEntryData;
    void ProcessEntries_00a93750();
};
// @fnv 0x00a93750
// src: GUESS 0x00a93750 (confidence: low)
void FUN_00a93750_shell::ProcessEntries_00a93750()
{
    m_pData = &DAT_0109ff64;
    for (unsigned int i = 0; i < m_nCount; ++i)
        NiFreeAlias(m_pEntryData[i]);
    NiFreeAlias(m_pEntryData);
    m_pEntryData = 0;
    reinterpret_cast<NiExtraData*>(this)->DestroyFields_00a7b300();
}

void __cdecl _delete(void* p, unsigned int);

struct NiSwitchStringExtraData
{
    void* __thiscall FUN_00a938b0(unsigned int flags);
};

void __cdecl ProcessEntries_00a93750();

// Calls FUN_00a93750, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a938b0
void* __thiscall NiSwitchStringExtraData::FUN_00a938b0(unsigned int flags)
{
    ProcessEntries_00a93750();
    if (flags & 1)
        _delete(this, 24);
    return this;
}

void __cdecl ReleaseObjectArray(void*);
extern int DAT_0109f9b4;
struct MM
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM g_memoryManager;
struct S_00a918e0
{
    void* f0;
    void* f4;
    void* __thiscall FUN_00a918e0(unsigned int);
};
// @fnv 0x00a918e0
void* __thiscall S_00a918e0::FUN_00a918e0(unsigned int auiFlags)
{
    void* v = f4;
    f0 = (void*)&DAT_0109f9b4;
    ReleaseObjectArray(v);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

// NiExtraData viewer strings are not yet declared by the shared header.
void __cdecl FUN_00a7b580();

char* __cdecl _FUN_00a7d330(void* object);
char* __cdecl NiGetViewerString_00a7d510(char const* name, char const* value);
char* __cdecl NiGetViewerString_00a7d5e0(char const* name, char const* value);
char* __cdecl NiGetViewerString_00a7d4d0(char const* name, int value);

struct FUN_00a93a60_shell
{
    void* m_pUnknown0;
    void* m_pUnknown1;
    void* m_pUnknown2;
    unsigned int m_uiSize;
    char** m_ppcValue;
    int m_iIndex;

    void NiSwitchStringExtraData_GetViewerStrings(StrArr* apViewerStrings);
};

// Appends viewer strings for the base object, m_uiSize, each m_ppcValue[i] and m_iIndex to the given string array.
// @fnv 0x00a93a60
// src: XBOX_PDB 0x00a93a60
void FUN_00a93a60_shell::NiSwitchStringExtraData_GetViewerStrings(StrArr* apViewerStrings)
{
    reinterpret_cast<void (__thiscall*)(NiExtraData*, StrArr*)>(FUN_00a7b580)(
        reinterpret_cast<NiExtraData*>(this), apViewerStrings);

    {
        char* value = _FUN_00a7d330(*(void**)&g_011f5eac);
        unsigned int index = apViewerStrings->m_usSize;
        if (index >= apViewerStrings->m_usMaxSize)
        {
            apViewerStrings->SetSize(index + apViewerStrings->m_usGrowBy);
        }
        apViewerStrings->SetAt(index, value);

        value = NiGetViewerString_00a7d510("m_uiSize", reinterpret_cast<char const*>(m_uiSize));
        index = apViewerStrings->m_usSize;
        if (index >= apViewerStrings->m_usMaxSize)
        {
            apViewerStrings->SetSize(index + apViewerStrings->m_usGrowBy);
        }
        apViewerStrings->SetAt(index, value);

        for (unsigned int i = 0; i < m_uiSize; ++i)
        {
            value = NiGetViewerString_00a7d5e0("m_ppcValue[i]", m_ppcValue[i]);
            index = apViewerStrings->m_usSize;
            if (index >= apViewerStrings->m_usMaxSize)
            {
                apViewerStrings->SetSize(index + apViewerStrings->m_usGrowBy);
            }

            if (index >= apViewerStrings->m_usSize)
            {
                apViewerStrings->m_usSize = static_cast<unsigned short>(index + 1);
                if (value)
                {
                    ++apViewerStrings->m_usESize;
                }
            }
            else
            {
                if (value)
                {
                    if (!apViewerStrings->m_pBase[index])
                    {
                        ++apViewerStrings->m_usESize;
                    }
                }
                else
                {
                    if (apViewerStrings->m_pBase[index])
                    {
                        apViewerStrings->m_usESize += static_cast<unsigned short>(0xffff);
                    }
                }
            }
            apViewerStrings->m_pBase[index] = value;
        }
    }

    {
        char* value = NiGetViewerString_00a7d4d0("m_iIndex", m_iIndex);
        unsigned int index = apViewerStrings->m_usSize;
        if (index >= apViewerStrings->m_usMaxSize)
        {
            apViewerStrings->SetSize(index + apViewerStrings->m_usGrowBy);
        }

        if (index >= apViewerStrings->m_usSize)
        {
            apViewerStrings->m_usSize = static_cast<unsigned short>(index + 1);
            if (value)
            {
                ++apViewerStrings->m_usESize;
            }
        }
        else
        {
            if (value)
            {
                if (!apViewerStrings->m_pBase[index])
                {
                    ++apViewerStrings->m_usESize;
                }
            }
            else
            {
                if (apViewerStrings->m_pBase[index])
                {
                    apViewerStrings->m_usESize += static_cast<unsigned short>(0xffff);
                }
            }
        }
        apViewerStrings->m_pBase[index] = value;
    }
}

extern "C" int __cdecl strcmp(const char*, const char*);

class A93680Strings
{
  public:
    bool Equals(A93680Strings* pkOther);

    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiSize;
    char** m_ppcStrings;
    int m_iType;
};

// @fnv 0x00a93680
bool A93680Strings::Equals(A93680Strings* pkOther)
{
    if (!pkOther)
        return false;
    if (m_uiSize != pkOther->m_uiSize)
        return false;
    if (m_iType != pkOther->m_iType)
        return false;
    if ((m_ppcStrings && !pkOther->m_ppcStrings) || (!m_ppcStrings && pkOther->m_ppcStrings))
        return false;
    if (m_ppcStrings)
    {
        for (unsigned int i = 0; i < m_uiSize; i++)
        {
            if ((m_ppcStrings[i] && !pkOther->m_ppcStrings[i]) || (!m_ppcStrings[i] && pkOther->m_ppcStrings[i]))
                return false;
            if (m_ppcStrings[i] && strcmp(m_ppcStrings[i], pkOther->m_ppcStrings[i]) != 0)
                return false;
        }
    }
    return true;
}

struct StrListObj
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    unsigned int m_uiCount;
    char** m_ppStrings;
    int m_iIndex;

    void CopyStringList(StrListObj* dst, void* arg2);
};

void* __cdecl _NiMalloc_00aa1070(unsigned int size);
void __cdecl FUN_00ec65a6(void* dst, unsigned int size, void* src);

// @fnv 0x00a937a0
void StrListObj::CopyStringList(StrListObj* dst, void* arg2)
{
    reinterpret_cast<NiExtraData*>(this)->CopyMembers_00a7b330(dst, arg2);
    if (m_ppStrings == 0 || m_uiCount <= 0)
    {
        dst->m_ppStrings = 0;
        dst->m_uiCount = 0;
        return;
    }
    dst->m_uiCount = m_uiCount;
    if (m_iIndex > -1 && m_iIndex < (int)m_uiCount)
    {
        dst->m_iIndex = m_iIndex;
    }
    else
    {
        dst->m_iIndex = -1;
    }
    dst->m_ppStrings = (char**)_NiMalloc_00aa1070(m_uiCount * 4);
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        if (m_ppStrings[i] != 0)
        {
            char* p = m_ppStrings[i];
            char* base = p + 1;
            char cChar;
            do
            {
                cChar = *p;
                p++;
            } while (cChar != 0);
            unsigned int uiLen = (unsigned int)(p - base);
            dst->m_ppStrings[i] = (char*)_NiMalloc_00aa1070(uiLen + 1);
            FUN_00ec65a6(dst->m_ppStrings[i], uiLen + 1, m_ppStrings[i]);
        }
        else
        {
            dst->m_ppStrings[i] = 0;
        }
    }
}

__forceinline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                                       unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

__forceinline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                                        unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesWritten;
    return uiBytesWritten;
}

// 0x00a939d0 saves the count at +0x0C, strings at +0x10 and index at +0x14.
struct SwitchStringSaveState : NiExtraData
{
    unsigned int m_uiSize;
    char** m_ppcValue;
    unsigned int m_uiIndex;
    void SaveToStream(NiStream& kStream);
};

template <class T> __forceinline void NiBinaryStreamSave(NiBinaryStream& os, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    os.BinaryWrite(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}

template <class T> __forceinline void WriteBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamSave(*kStream.m_pkOstr, &value, 1);
}

// @fnv 0x00a939d0
void SwitchStringSaveState::SaveToStream(NiStream& kStream)
{
    NiExtraData::SaveBinary(kStream);
    WriteBinaryValue(kStream, m_uiSize);
    for (unsigned int i = 0; i < m_uiSize; ++i)
        kStream.WriteStreamString(m_ppcValue[i]);
    WriteBinaryValue(kStream, m_uiIndex);
}

// Uses insights from unverified 2026-10-23 contributor attempt.
extern int DAT_0109ff64;
struct SSE_Node
{
    // Initialize the shared base through its original helper, without calling its default constructor.
    unsigned char m_extraData[sizeof(NiExtraData)];
    unsigned int unk0C, unk10;
    int unk14;
    static void* operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    SSE_Node() throw()
    {
        reinterpret_cast<NiExtraData*>(this)->FUN_00a7b2e0();
        *reinterpret_cast<void**>(this) = &DAT_0109ff64;
        unk10 = 0;
        unk0C = 0;
        unk14 = -1;
    }
};
struct SSE_Owner : NiSwitchStringExtraData
{
    SSE_Node* CreateNode(unsigned int);
    void CopyStringList(SSE_Node*, unsigned int);
};
// @fnv 0x00a938d0
SSE_Node* SSE_Owner::CreateNode(unsigned int arg)
{
    SSE_Node* obj = new SSE_Node;
    CopyStringList(obj, arg);
    return obj;
}

void* __cdecl NiMalloc(unsigned int stSizeInBytes);

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

// 0x00a93930 loads strings with NiStream::ReadStreamString (0x00a64ce0), not object links.
class SwitchStringLoadState : public NiExtraData
{
  public:
    unsigned int m_uiCount;
    char** m_ppcStrings;
    unsigned int m_uiIndex;

    void NiSwitchStringExtraData_LoadBinary(NiStream& kStream);
};

// Reads the count, allocates the string array and loads each string, then reads the index.
// @fnv 0x00a93930
// src: XBOX_PDB 0x00a93930
void SwitchStringLoadState::NiSwitchStringExtraData_LoadBinary(NiStream& kStream)
{
    NiExtraData::LoadBinary(kStream);
    NiBinaryStreamLoad(kStream.m_pkIstr, &m_uiCount, 1);
    if (m_uiCount > 0)
    {
        m_ppcStrings = (char**)NiMalloc(m_uiCount * sizeof(char*));
        for (unsigned int i = 0; i < m_uiCount; i++)
            kStream.ReadStreamString(m_ppcStrings[i]);
    }
    else
    {
        m_ppcStrings = 0;
    }
    NiBinaryStreamLoad(kStream.m_pkIstr, &m_uiIndex, 1);
}
