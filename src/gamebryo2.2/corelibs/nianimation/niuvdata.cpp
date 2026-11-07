
// src/gamebryo2.2/corelibs/nianimation/niuvdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niuvdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiUVData.h"
#include "../../../../include/StrArr.h"

extern const void* g_011f3f10;

// @fnv 0x00a45010
// src: COMMUNITY 0x00a45010
const void* __cdecl NiUVData_GetRTTI()
{
    return &g_011f3f10;
}

void __cdecl _delete(void*, unsigned int);
// Calls Destructor, then frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a45200
void* NiUVData::FUN_00a45200(unsigned int flags)
{
    Destructor();
    if (flags & 1)
        _delete(this, 0x4C);
    return this;
}

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
// @fnv 0x00a45280
// src: XBOX_PDB 0x00a45280
void NiUVData::ReplaceVOffsetAnim(void* keys, unsigned int count, int type)
{
    void* oldKeys = m_pVOffsetKeys;
    if (oldKeys)
        DAT_011f38a0[m_uiVOffsetKeyStride](oldKeys);
    if (keys && count)
    {
        m_uiNumVOffsetKeys = count;
        m_pVOffsetKeys = reinterpret_cast<unsigned char*>(keys);
        m_uiVOffsetKeyStride = type;
        m_ucByte49 = DAT_011f3758[type];
    }
    else
    {
        m_uiNumVOffsetKeys = 0;
        m_pVOffsetKeys = 0;
        m_uiVOffsetKeyStride = 0;
        m_ucByte49 = 0;
    }
}


// Releases the previous key data, then stores the new keys, count and type (or clears them when keys or count is null/zero).
// @fnv 0x00a45340
// src: XBOX_PDB 0x00a45340
void NiUVData::ReplaceVTilingAnim(void* keys, unsigned int count, unsigned int type)
{
    if (m_pVTilingKeys)
        DAT_011f38a0[m_uiVTilingKeyStride](m_pVTilingKeys);
    if (keys && count)
    {
        m_uiNumVTilingKeys = count;
        m_pVTilingKeys = reinterpret_cast<unsigned char*>(keys);
        m_uiVTilingKeyStride = type;
        m_ucByte4B = DAT_011f3758[type];
    }
    else
    {
        m_uiNumVTilingKeys = 0;
        m_pVTilingKeys = 0;
        m_uiVTilingKeyStride = 0;
        m_ucByte4B = 0;
    }
}


// Releases the current key array, then stores the new keys, count and type (or clears them when keys or numKeys is null/zero).
// @fnv 0x00a45220
// src: XBOX_PDB 0x00a45220
void NiUVData::ReplaceUOffsetAnim(TimedAnimationKey* keys, unsigned int numKeys, unsigned int type)
{
    if (m_pUOffsetKeys)
        DAT_011f38a0[m_uiUOffsetKeyStride](m_pUOffsetKeys);
    if (keys && numKeys)
    {
        m_uiNumUOffsetKeys = numKeys;
        m_pUOffsetKeys = reinterpret_cast<unsigned char*>(keys);
        m_uiUOffsetKeyStride = type;
        m_ucByte48 = DAT_011f3758[type];
    }
    else
    {
        m_uiNumUOffsetKeys = 0;
        m_pUOffsetKeys = 0;
        m_uiUOffsetKeyStride = 0;
        m_ucByte48 = 0;
    }
}

// Releases the previous key array, then stores the new keys, count and type (or clears them when keys or count is null/zero).
// @fnv 0x00a452e0
// src: XBOX_PDB 0x00a452e0
void NiUVData::ReplaceUTilingAnim(void* keys, unsigned int count, unsigned int type)
{
    if (m_pUTilingKeys)
        DAT_011f38a0[m_uiUTilingKeyStride](m_pUTilingKeys);
    if (keys && count)
    {
        m_uiNumUTilingKeys = count;
        m_pUTilingKeys = reinterpret_cast<unsigned char*>(keys);
        m_uiUTilingKeyStride = type;
        m_ucByte4A = DAT_011f3758[type];
    }
    else
    {
        m_uiNumUTilingKeys = 0;
        m_pUTilingKeys = 0;
        m_uiUTilingKeyStride = 0;
        m_ucByte4A = 0;
    }
}

extern int DAT_01097f84;


// Sets the vtable, releases the four pointer members via DAT_011f38a0 if non-null, then calls the NiRefObject destructor.
// @fnv 0x00a45020
void NiUVData::Destructor()
{
    *(void**)this = (void*)&DAT_01097f84;
    void* p;
    p = m_pUOffsetKeys;
    if (p)
        DAT_011f38a0[m_uiUOffsetKeyStride](p);
    p = m_pVOffsetKeys;
    if (p)
        DAT_011f38a0[m_uiVOffsetKeyStride](p);
    p = m_pUTilingKeys;
    if (p)
        DAT_011f38a0[m_uiUTilingKeyStride](p);
    p = m_pVTilingKeys;
    if (p)
        DAT_011f38a0[m_uiVTilingKeyStride](p);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}


void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl _FUN_00a7d330(char*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);


// @fnv 0x00a457d0
void NiUVData::AppendKeyNames(StrArr* apViewerStrings)
{
    char* pString;
    unsigned int nIndex;

    AppendCameraPathEntries(apViewerStrings);

    pString = _FUN_00a7d330(const_cast<char*>(static_cast<const char*>(g_011f3f10)));
    nIndex = apViewerStrings->m_usSize;
    if (nIndex >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumUOffsetKeys", m_uiNumUOffsetKeys);
    nIndex = apViewerStrings->m_usSize;
    if (nIndex >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumUTilingKeys", m_uiNumUTilingKeys);
    nIndex = apViewerStrings->m_usSize;
    if (nIndex >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumVOffsetKeys", m_uiNumVOffsetKeys);
    nIndex = apViewerStrings->m_usSize;
    if (nIndex >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + nIndex);
    apViewerStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumVTilingKeys", m_uiNumVTilingKeys);
    nIndex = apViewerStrings->m_usSize;
    if (nIndex >= apViewerStrings->m_usMaxSize)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + nIndex);
    apViewerStrings->SetAt(nIndex, pString);
}

extern bool(__cdecl* DAT_011f3ae0[])(void*, void*);


inline unsigned char* NiUVData::GetKeyPointerByIndex(unsigned char* pk, unsigned int i, unsigned char uc)
{
    return pk + i * uc;
}

// @fnv 0x00a45090
// src: XBOX_PDB 0x00a45090
bool NiUVData::IsEqual_00a45090(NiUVData* pkOther)
{
    if (!NiObject::IsEqual(pkOther))
        return false;

    if (m_uiNumUOffsetKeys != pkOther->m_uiNumUOffsetKeys || m_uiUOffsetKeyStride != pkOther->m_uiUOffsetKeyStride ||
        m_uiNumVOffsetKeys != pkOther->m_uiNumVOffsetKeys || m_uiVOffsetKeyStride != pkOther->m_uiVOffsetKeyStride ||
        m_uiNumUTilingKeys != pkOther->m_uiNumUTilingKeys || m_uiUTilingKeyStride != pkOther->m_uiUTilingKeyStride ||
        m_uiNumVTilingKeys != pkOther->m_uiNumVTilingKeys || m_uiVTilingKeyStride != pkOther->m_uiVTilingKeyStride ||
        m_ucByte48 != pkOther->m_ucByte48 || m_ucByte49 != pkOther->m_ucByte49 || m_ucByte4A != pkOther->m_ucByte4A ||
        m_ucByte4B != pkOther->m_ucByte4B)
        return false;

    unsigned int i;
    bool(__cdecl * pfnKeyEqual)(void*, void*);

    pfnKeyEqual = DAT_011f3ae0[m_uiUOffsetKeyStride];
    for (i = 0; i < m_uiNumUOffsetKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pUOffsetKeys, i, m_ucByte48),
                         GetKeyPointerByIndex(pkOther->m_pUOffsetKeys, i, m_ucByte48)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_uiVOffsetKeyStride];
    for (i = 0; i < m_uiNumVOffsetKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pVOffsetKeys, i, m_ucByte49),
                         GetKeyPointerByIndex(pkOther->m_pVOffsetKeys, i, m_ucByte49)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_uiUTilingKeyStride];
    for (i = 0; i < m_uiNumUTilingKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pUTilingKeys, i, m_ucByte4A),
                         GetKeyPointerByIndex(pkOther->m_pUTilingKeys, i, m_ucByte4A)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_uiVTilingKeyStride];
    for (i = 0; i < m_uiNumVTilingKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pVTilingKeys, i, m_ucByte4B),
                         GetKeyPointerByIndex(pkOther->m_pVTilingKeys, i, m_ucByte4B)))
            return false;
    }

    return true;
}


// Keep these transfer operations inline, as in the original stream views.
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                               unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesRead = m_pfnRead(this, buffer, bytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += bytesRead;
    return bytesRead;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                                unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesWritten = m_pfnWrite(this, buffer, bytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += bytesWritten;
    return bytesWritten;
}


template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(kStream.m_pkIstr, &val, 1);
}

template <class T> inline void ReadStreamValue(NiStream& kStream, T& eValue)
{
    unsigned int uiValue;
    ReadBinaryValue(kStream, uiValue);
    eValue = (T)uiValue;
}

typedef NiUVKey*(__cdecl* NiUVKeyCreateFunction)(NiStream& kStream, unsigned int uiNumKeys);
typedef void(__cdecl* NiUVKeyFillFunction)(NiUVKey* pkKeys, unsigned int uiNumKeys, unsigned char ucSize);
extern unsigned char g_aucFloatKeySizes[];
extern NiUVKeyCreateFunction g_apfnFloatKeyCreate[];
extern NiUVKeyFillFunction g_apfnFloatKeyFill[];


// Loads the base object, then reads U/V offset and U/V tiling key blocks from the stream and replaces each key set.
// @fnv 0x00a453a0
void NiUVData::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);

    unsigned int uiNumKeys;
    NiUVKeyType eType;

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte48 = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte48);
        ReplaceUOffsetKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte49 = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte49);
        ReplaceVOffsetKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte4A = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte4A);
        ReplaceUTilingKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucByte4B = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucByte4B);
        ReplaceVTilingKeys(pkKeys, uiNumKeys, eType);
    }
}

// NiUVData::SaveBinary writes the four UV key groups through the per-type float-key saver table.



template <class T> inline unsigned int WriteBinaryValue(NiBinaryStream& kBinstream, T& value)
{
    unsigned int uiSize = sizeof(T);
    return kBinstream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
template <class T> inline unsigned int WriteBinaryValue(NiStream& kStream, T& value)
{
    return WriteBinaryValue(*kStream.m_pkOstr, value);
}

extern void(__cdecl* DAT_011f3a50[])(NiStream& kStream, void* pkKeys, unsigned int uiNumKeys);


// Saves the base object, then writes each UV key count and any key array via the key-type saver table.
// @fnv 0x00a45610
void NiUVData::SaveBinary(NiStream& kStream)
{
    NiObject::SaveBinary(kStream);
    WriteBinaryValue(kStream, m_uiNumUOffsetKeys);
    if (m_uiNumUOffsetKeys > 0)
    {
        WriteBinaryValue(kStream, m_uiUOffsetKeyStride);
        DAT_011f3a50[m_uiUOffsetKeyStride](kStream, m_pUOffsetKeys, m_uiNumUOffsetKeys);
    }
    WriteBinaryValue(kStream, m_uiNumVOffsetKeys);
    if (m_uiNumVOffsetKeys > 0)
    {
        WriteBinaryValue(kStream, m_uiVOffsetKeyStride);
        DAT_011f3a50[m_uiVOffsetKeyStride](kStream, m_pVOffsetKeys, m_uiNumVOffsetKeys);
    }
    WriteBinaryValue(kStream, m_uiNumUTilingKeys);
    if (m_uiNumUTilingKeys > 0)
    {
        WriteBinaryValue(kStream, m_uiUTilingKeyStride);
        DAT_011f3a50[m_uiUTilingKeyStride](kStream, m_pUTilingKeys, m_uiNumUTilingKeys);
    }
    WriteBinaryValue(kStream, m_uiNumVTilingKeys);
    if (m_uiNumVTilingKeys > 0)
    {
        WriteBinaryValue(kStream, m_uiVTilingKeyStride);
        DAT_011f3a50[m_uiVTilingKeyStride](kStream, m_pVTilingKeys, m_uiNumVTilingKeys);
    }
}
