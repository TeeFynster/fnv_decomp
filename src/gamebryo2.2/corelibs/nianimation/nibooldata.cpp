// gamebryo2.2/corelibs/nianimation/nibooldata.cpp: NiBoolData (7 functions)
#include "NiRefObject_inline.h"

#include "nibooldata_decls.h"
#include "../../../../include/StrArr.h"

// @fnv 0x00a53a50
void NiBoolData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    NiAnimationKey::KeyType type = NiAnimationKey::STEPKEY;
    unsigned int numKeys;
    ReadBinaryValue(stream, numKeys);
    if (numKeys > 0)
    {
        if (stream.m_uiNifFileVersion >= 0x0a010068)
            ReadBinaryValue(stream, type);
        m_ucKeyDataSize = BooleanKey::GetKeySize(type);
        BooleanKey* keys = static_cast<BooleanKey*>(BooleanKey::GetLoadFunction(type)(stream, numKeys));
        BooleanKey::GetFillDerivedFunction(type)(keys, numKeys, m_ucKeyDataSize);
        SetColorKeys(keys, numKeys, type);
    }
}

// Replaces the stored key array: frees the old keys, then stores the new keys, count, key type and key size, or clears them when keys is null or numKeys is zero.
// @fnv 0x00a538b0
void NiBoolData::SetColorKeys(BooleanKey* keys, unsigned int numKeys, NiAnimationKey::KeyType eKeyType)
{
    if (m_pKeyArray)
        BooleanKey::GetDeleteFunction(m_eRequestType)(m_pKeyArray);
    if (keys && numKeys)
    {
        m_ucKeyDataSize = BooleanKey::GetKeySize(eKeyType);
        m_pKeyArray = keys;
        m_uiNumKeys = numKeys;
        m_eRequestType = eKeyType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = NiAnimationKey::NOINTERP;
        m_ucKeyDataSize = 0;
    }
}

void __cdecl UpdateSlotStates(unsigned int, unsigned int, void*&, unsigned int&, float, float);
// These entry points use ECX for the shared object and retain the original stack arguments.
// The shared class does not yet declare these NiBoolData operations.
// @fnv 0x00a537a0
void __fastcall GuaranteeBoolKeys(NiBoolData* data, void*, float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = data->m_pKeyArray;
    UpdateSlotStates(5, data->m_eRequestType, pkKeys, data->m_uiNumKeys, m_fStartTime, m_fMaximumDistance);
    data->m_pKeyArray = static_cast<BooleanKey*>(pkKeys);
}

struct GlobalObjectO2_00a7b610
{
    void* pObject;
};

extern GlobalObjectO2_00a7b610 g_011f4054;

void __stdcall AppendCameraPathEntries(StrArr*);
void* __cdecl _FUN_00a7d330(void*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);

// @fnv 0x00a53ba0
void __fastcall GetBoolViewerStrings(NiBoolData* data, void*, StrArr* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);

    char* pString = static_cast<char*>(_FUN_00a7d330(g_011f4054.pObject));
    unsigned int uiIndex = apViewerStrings->m_usSize;
    unsigned int uiCapacity = apViewerStrings->m_usMaxSize;

    if (uiIndex >= uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + uiIndex);

    apViewerStrings->SetAt(uiIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumKeys", data->m_uiNumKeys);
    uiIndex = apViewerStrings->m_usSize;
    uiCapacity = apViewerStrings->m_usMaxSize;

    if (uiIndex >= uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + uiIndex);

    apViewerStrings->SetAt(uiIndex, pString);
}

typedef bool(__cdecl* FUN_00a53830_elemcmp)(void* a, void* b);
extern FUN_00a53830_elemcmp DAT_011f3b58[];

// Compares the base object, key count, type and stride, then compares each key with the type-specific function.
// @fnv 0x00a53830
bool __fastcall EqualsBoolData(NiBoolData* data, void*, NiBoolData* other)
{
    if (!data->IsSameAs(other))
    {
        return false;
    }
    if (data->m_uiNumKeys != other->m_uiNumKeys)
    {
        return false;
    }
    if (data->m_eRequestType != other->m_eRequestType)
    {
        return false;
    }
    if (data->m_ucKeyDataSize != other->m_ucKeyDataSize)
    {
        return false;
    }
    FUN_00a53830_elemcmp pElemCmp = DAT_011f3b58[data->m_eRequestType];
    for (unsigned int uiIndex = 0; uiIndex < data->m_uiNumKeys; ++uiIndex)
    {
        unsigned int off = (unsigned int)data->m_ucKeyDataSize * uiIndex;
        unsigned char* pOtherData = reinterpret_cast<unsigned char*>(other->m_pKeyArray) + off;
        unsigned char* pThisData = reinterpret_cast<unsigned char*>(data->m_pKeyArray) + off;
        if (!pElemCmp(pThisData, pOtherData))
        {
            return false;
        }
    }
    return true;
}

typedef void(__cdecl* NiBoolSaveKeysFunction)(NiStream&, BooleanKey*, unsigned int);
extern "C" NiBoolSaveKeysFunction DAT_011f3ac8[NiAnimationKey::NUMKEYTYPES];
template <class T> inline void BinaryWriteValue(NiBinaryStream* output, const T& value)
{
    unsigned int size = sizeof(T);
    output->m_uiAbsoluteCurrentPos += output->m_pfnWrite(output, &value, size, &size, 1);
}
template <class T> inline void WriteValue(NiStream& stream, const T& value)
{
    BinaryWriteValue(stream.m_pkOstr, value);
}
// @fnv 0x00a53b20
void __fastcall SaveBoolData(NiBoolData* data, void*, NiStream& stream)
{
    data->NiObject::SaveBinary(stream);
    WriteValue(stream, data->m_uiNumKeys);
    if (data->m_uiNumKeys > 0)
    {
        WriteValue(stream, data->m_eRequestType);
        DAT_011f3ac8[data->m_eRequestType](stream, data->m_pKeyArray, data->m_uiNumKeys);
    }
}

void __cdecl NiAnimationKey_CopySequence(unsigned int mode, NiAnimationKey::KeyType type, BooleanKey* sourceKeys,
                          unsigned int sourceCount, float startTime, float endTime, BooleanKey** outputKeys,
                          unsigned int* outputCount);

// Clones this NiBoolData, processes its keys with the requested time range when present, and assigns the result to output.
// @fnv 0x00a53910
void __fastcall CloneBoolDataForTimeRange(NiBoolData* data, void*, float startTime, float endTime, NiPointer<NiBoolData>& output)
{
    NiBoolData* original = 0;
    data->ResolveObjectPointer(reinterpret_cast<NiPointer<NiObject>&>(original));

    NiBoolData* copy = original;
    if (copy != 0)
        copy->IncRefCount();

    if (data->m_uiNumKeys > 0)
    {
        BooleanKey* keys = 0;
        unsigned int count = 0;
        NiAnimationKey_CopySequence(5, data->m_eRequestType, data->m_pKeyArray, data->m_uiNumKeys, startTime, endTime, &keys, &count);
        copy->SetColorKeys(keys, count, data->m_eRequestType);
    }

    NiBoolData* previous = output.m_pObject;
    if (previous != copy)
    {
        if (previous != 0)
            previous->DecRefCount();

        output.m_pObject = copy;
        if (copy != 0)
            copy->IncRefCount();
    }
    if (copy != 0)
        copy->DecRefCount();
    if (original != 0)
        original->DecRefCount();
}
