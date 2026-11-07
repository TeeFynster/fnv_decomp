
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlrdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterctlrdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/StrArr.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiObject.h"

extern "C" void* g_01202760;

// @fnv 0x00c2baa0
// src: COMMUNITY 0x00c2baa0
void* __cdecl NiPSysEmitterCtlrData_GetRTTI()
{
    return &g_01202760;
}

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
// No shared NiPSysEmitterCtlrData header is available yet; all emitter methods use
// this single layout (birth-rate keys at 0x08 and emitter-active keys at 0x18).
class NiPSysEmitterCtlrData : public NiObject
{
  public:
    unsigned int m_uiNumBirthRateKeys;
    unsigned char* m_pkBirthRateKeys;
    int m_eBirthRateKeyType;
    unsigned char m_ucBirthRateKeySize;
    unsigned int m_uiNumEmitterActiveKeys;
    unsigned char* m_pkEmitterActiveKeys;
    unsigned int m_eEmitterActiveKeyType;
    unsigned char m_ucEmitterActiveKeySize;

    void ReplaceBirthRateKeys(void* keys, unsigned int numKeys, int type);
    void ReplaceEmitterActiveKeys(void* keys, unsigned int numKeys, int type);
    void* Destroy(unsigned int);
    void AppendBirthRateKeys(StrArr* pkStrings);
    bool Equals(NiPSysEmitterCtlrData* other);
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
};
// @fnv 0x00c2bb70
void NiPSysEmitterCtlrData::ReplaceBirthRateKeys(void* keys, unsigned int numKeys, int type)
{
    if (m_pkBirthRateKeys)
        DAT_011f38a0[m_eBirthRateKeyType](m_pkBirthRateKeys);
    if (keys && numKeys)
    {
        m_ucBirthRateKeySize = DAT_011f3758[type];
        m_pkBirthRateKeys = (unsigned char*)keys;
        m_uiNumBirthRateKeys = numKeys;
        m_eBirthRateKeyType = type;
    }
    else
    {
        m_uiNumBirthRateKeys = 0;
        m_pkBirthRateKeys = 0;
        m_eBirthRateKeyType = 0;
        m_ucBirthRateKeySize = 0;
    }
}

struct NiAnimationKey;
extern int DAT_010bfd54;
extern void(__cdecl* DAT_011f38a0[])(void*);
extern void(__cdecl* DAT_011f3918[])(NiAnimationKey*);
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00c2bc30
void* NiPSysEmitterCtlrData::Destroy(unsigned int flags)
{
    void* pkKeys = *(void**)((char*)this + 0xc);
    *(void**)this = (void*)&DAT_010bfd54;
    if (pkKeys)
        DAT_011f38a0[*(int*)((char*)this + 0x10)](pkKeys);
    pkKeys = *(void**)((char*)this + 0x1c);
    if (pkKeys)
        DAT_011f3918[*(int*)((char*)this + 0x20)]((NiAnimationKey*)pkKeys);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
    if (flags & 1)
        _delete(this, 0x28);
    return this;
}

void __stdcall AppendCameraPathEntries(StrArr*);
void* __cdecl _FUN_00a7d330(void*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);
char* __cdecl NiGetViewerString_00a7d5e0(char const*, char const*);

// @fnv 0x00c2bf00
void NiPSysEmitterCtlrData::AppendBirthRateKeys(StrArr* pkStrings)
{
    unsigned int uiIndex;
    char* pcValue;
    char* pcKeyTypeName;

    AppendCameraPathEntries(pkStrings);

    pcValue = (char*)_FUN_00a7d330(g_01202760);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);

    pcValue = NiGetViewerString_00a7d510("Num Birth Rate Keys", m_uiNumBirthRateKeys);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);

    switch (m_eBirthRateKeyType)
    {
    case 1:
        pcKeyTypeName = (char*)"LINKEY";
        break;
    case 2:
        pcKeyTypeName = (char*)"BEZKEY";
        break;
    case 3:
        pcKeyTypeName = (char*)"TCBKEY";
        break;
    default:
        pcKeyTypeName = (char*)"Unknown";
        break;
    }

    pcValue = NiGetViewerString_00a7d5e0("Birth Rate Key Type", pcKeyTypeName);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);

    pcValue = NiGetViewerString_00a7d510("Num Emitter Active Keys", m_uiNumEmitterActiveKeys);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
    {
        pkStrings->SetSize(pkStrings->m_usGrowBy + uiIndex);
    }
    pkStrings->SetAt(uiIndex, pcValue);
}

extern bool(__cdecl* DAT_011f3ae0[])(unsigned char*, unsigned char*);

// @fnv 0x00c2bab0
bool NiPSysEmitterCtlrData::Equals(NiPSysEmitterCtlrData* other)
{
    if (!NiObject::IsSameAs(other))
        return false;

    if (other->m_uiNumBirthRateKeys != m_uiNumBirthRateKeys)
        return false;

    if (other->m_eBirthRateKeyType != m_eBirthRateKeyType)
        return false;

    if (other->m_uiNumEmitterActiveKeys != m_uiNumEmitterActiveKeys)
        return false;

    if (other->m_ucBirthRateKeySize != m_ucBirthRateKeySize)
        return false;

    bool(__cdecl * pfnCompare)(unsigned char*, unsigned char*) = DAT_011f3ae0[m_eBirthRateKeyType];

    for (unsigned int i = 0; i < m_uiNumBirthRateKeys; ++i)
    {
        unsigned char* key = m_pkBirthRateKeys + i * m_ucBirthRateKeySize;
        unsigned char* otherKey = other->m_pkBirthRateKeys + i * m_ucBirthRateKeySize;

        if (!pfnCompare(otherKey, key))
            return false;
    }

    for (unsigned int i = 0; i < m_uiNumEmitterActiveKeys; ++i)
    {
        unsigned char* key = m_pkEmitterActiveKeys + i * m_ucEmitterActiveKeySize;
        unsigned char* otherKey = other->m_pkEmitterActiveKeys + i * m_ucEmitterActiveKeySize;

        if (!pfnCompare(otherKey, key))
            return false;
    }

    return true;
}

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
// @fnv 0x00c2bbd0
void NiPSysEmitterCtlrData::ReplaceEmitterActiveKeys(void* keys, unsigned int numKeys, int type)
{
    if (m_pkEmitterActiveKeys)
        DAT_011f38a0[m_eEmitterActiveKeyType](m_pkEmitterActiveKeys);
    if (keys && numKeys)
    {
        unsigned char size = DAT_011f3758[type + 30];
        m_ucEmitterActiveKeySize = size;
        m_pkEmitterActiveKeys = (unsigned char*)keys;
        m_uiNumEmitterActiveKeys = numKeys;
        m_eEmitterActiveKeyType = type;
    }
    else
    {
        m_uiNumEmitterActiveKeys = 0;
        m_pkEmitterActiveKeys = 0;
        m_ucEmitterActiveKeySize = 0;
    }
}

// The shared header declares these operations; retain their inline implementation
// here because the original callers inline the transfer and position update.
inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                                unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiWritten = (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 0xc))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *(unsigned int*)((char*)this + 4) += uiWritten;
    return uiWritten;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiRead = (*(NIBINARYSTREAM_READFN*)((char*)this + 8))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *(unsigned int*)((char*)this + 4) += uiRead;
    return uiRead;
}

// Preserve the original inline accesses through the shared stream declarations.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return pkIstr->BinaryWrite(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.GetBinaryStream(), &value, 1);
}

typedef void(__cdecl* KeyLoadFn)(NiStream& kStream, void* pkKeys, unsigned int uiNumKeys);
extern KeyLoadFn DAT_011f3a50[];
extern KeyLoadFn DAT_011f3ac8[];

// Saves the emitter controller key groups through the original stream callbacks.
// @fnv 0x00c2bdf0
void NiPSysEmitterCtlrData::SaveBinary(NiStream& kStream)
{
    NiObject::SaveBinary(kStream);

    ReadBinaryValue(kStream, m_uiNumBirthRateKeys);
    if (m_uiNumBirthRateKeys > 0)
    {
        ReadBinaryValue(kStream, m_eBirthRateKeyType);
        DAT_011f3a50[m_eBirthRateKeyType](kStream, m_pkBirthRateKeys, m_uiNumBirthRateKeys);
    }

    ReadBinaryValue(kStream, m_uiNumEmitterActiveKeys);
    for (unsigned int ui = 0; ui < m_uiNumEmitterActiveKeys; ui++)
    {
        if (m_uiNumEmitterActiveKeys > 0)
        {
            ReadBinaryValue(kStream, m_eEmitterActiveKeyType);
            DAT_011f3ac8[m_eEmitterActiveKeyType](kStream, m_pkEmitterActiveKeys, m_uiNumEmitterActiveKeys);
        }
    }
}


template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}



template <class T> inline void ReadInputValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.Istr(), &value, 1);
}

template <class T> inline void ReadStreamValue(NiStream& kStream, T& value)
{
    unsigned int uiValue;
    ReadInputValue(kStream, uiValue);
    value = (T)uiValue;
}

enum KeyType
{
    NOINTERP,
    LINKEY,
    BEZKEY,
    TCBKEY,
    EULERKEY,
    STEPKEY,
    NUMKEYTYPES
};

struct NiAnimationKey;
struct TimedAnimationKey;

extern void*(__cdecl* DAT_011f3db0[])(NiStream&, unsigned int);
extern void(__cdecl* DAT_011f3780[])(void*, unsigned int, unsigned char);
extern unsigned char DAT_011f3758[];
extern void*(__cdecl* DAT_011f3e28[])(NiStream&, unsigned int);
extern void(__cdecl* DAT_011f37f8[])(void*, unsigned int, unsigned char);
extern unsigned char DAT_011f3776[];

typedef void*(__cdecl* CreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* FillDerivedValsFunction)(void*, unsigned int, unsigned char);
inline CreateFunction GetCreate1(KeyType e)
{
    return DAT_011f3db0[e];
}
inline FillDerivedValsFunction GetFill1(KeyType e)
{
    return DAT_011f3780[e];
}
inline unsigned char GetKeySize1(KeyType e)
{
    return DAT_011f3758[e];
}
inline CreateFunction GetCreate2(KeyType e)
{
    return DAT_011f3e28[e];
}
inline FillDerivedValsFunction GetFill2(KeyType e)
{
    return DAT_011f37f8[e];
}
inline unsigned char GetKeySize2(KeyType e)
{
    return DAT_011f3776[e];
}
// Reads birth rate and emitter active key groups from the stream, creating and filling keys based on the key type and format version.
// @fnv 0x00c2bc90
void NiPSysEmitterCtlrData::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);

    unsigned int uiNumBirthRateKeys;
    ReadInputValue(kStream, uiNumBirthRateKeys);

    if (uiNumBirthRateKeys > 0)
    {
        KeyType eType;
        ReadStreamValue(kStream, eType);
        unsigned char ucSize = GetKeySize1(eType);
        CreateFunction cf = GetCreate1(eType);
        void* pkKeys = cf(kStream, uiNumBirthRateKeys);
        FillDerivedValsFunction pfnFill = GetFill1(eType);
        pfnFill(pkKeys, uiNumBirthRateKeys, ucSize);
        ReplaceBirthRateKeys(pkKeys, uiNumBirthRateKeys, eType);
    }

    unsigned int uiNumEmitterActiveKeys;
    ReadInputValue(kStream, uiNumEmitterActiveKeys);

    if (uiNumEmitterActiveKeys > 0)
    {
        KeyType eType = STEPKEY;
        if (kStream.GetFileVersion() >= 0x0a010068)
        {
            ReadStreamValue(kStream, eType);
        }
        unsigned char ucSize = GetKeySize2(eType);
        CreateFunction cf = GetCreate2(eType);
        void* pkKeys = cf(kStream, uiNumEmitterActiveKeys);
        FillDerivedValsFunction pfnFill = GetFill2(eType);
        pfnFill(pkKeys, uiNumEmitterActiveKeys, ucSize);
        ReplaceEmitterActiveKeys(pkKeys, uiNumEmitterActiveKeys, eType);
    }
}
