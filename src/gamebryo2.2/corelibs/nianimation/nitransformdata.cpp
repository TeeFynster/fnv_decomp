#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/StrArr.h"

#include "../../../../include/MapEntryCount.h"
#include "../../../../include/NiExtraDataController.h"
#include "../../../../include/NiFloatsExtraDataController.h"
#include "../../../../include/NiFloatsExtraDataPoint3Controller.h"
#include "../../../../include/NiInterpController.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiSingleInterpController.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiTransformData.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESObjectCELL.h"

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
#include "nitransformdata_accepted_decls.h"

// These unit-only operations use the shared layout; they add no storage or virtual slots.
class TransformDataOperations : public NiTransformData
{
public:
    TransformDataOperations() throw();
    void DestroyTransformData();
    void SetPositionKeyStorage(PositionKeyInterpolator*, unsigned int, NiAnimationKey::KeyType);
    void SetScaleKeyStorage(TimedAnimationKey*, unsigned int, NiAnimationKey::KeyType);
    void AppendTransformKeyCounts(void*);
    void RestrictKeyRange(float, float);
    bool CompareTransformData(NiObject*);
    void ExtractKeyRange(float, float, NiPointer<NiTransformData>&);
    void SaveTransformData(NiStream&);
    void LoadTransformData(NiStream&);
};

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)))
        DeleteThis();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// The PC member offsets and the Euler-key cleanup identify this as rotation
// replacement in the opposite order.
// Releases the previous rotation keys via the per-type deleter, then stores the new keys, count and interpolation type, or clears them.
// @fnv 0x00a4e2e0
void NiTransformData::SetRotationKeys(TimedRotationKey* keys, unsigned int count, NiAnimationKey::KeyType type)
{
    TimedRotationKey* oldKeys = m_pkRotationKeys;
    if (oldKeys)
    {
        if (m_eRotationKeyType == NiAnimationKey::EULERKEY)
            oldKeys->ClearFloatKeys();
        DAT_011f38d0[m_eRotationKeyType](oldKeys);
    }
    if (keys && count)
    {
        m_usNumRotKeys = (unsigned short)count;
        m_pkRotationKeys = keys;
        m_eRotationKeyType = type;
        m_ucRotationKeySize = DAT_011f3764[type];
    }
    else
    {
        m_usNumRotKeys = 0;
        m_pkRotationKeys = 0;
        m_eRotationKeyType = NiAnimationKey::NOINTERP;
        m_ucRotationKeySize = 0;
    }
}

// @fnv 0x00a4e350
void NiTransformData::SetPositionKeys(PositionKeyInterpolator* keys, unsigned int count, NiAnimationKey::KeyType eKeyType)
{
    if (m_pkPositionKeys)
        DAT_011f38b8[m_ePositionKeyType](m_pkPositionKeys);
    if (keys && count)
    {
        m_usNumPosKeys = (unsigned short)count;
        m_pkPositionKeys = keys;
        m_ePositionKeyType = eKeyType;
        m_ucPositionKeySize = DAT_011f375e[eKeyType];
    }
    else
    {
        m_usNumPosKeys = 0;
        m_pkPositionKeys = 0;
        m_ePositionKeyType = NiAnimationKey::NOINTERP;
        m_ucPositionKeySize = 0;
    }
}

// Releases the previous scale keys and stores the new key array, count and interpolation type, or clears them when keys or count is zero.
// @fnv 0x00a4e3b0
void NiTransformData::SetScaleKeys(TimedAnimationKey* keys, unsigned int count, NiAnimationKey::KeyType type)
{
    if (m_pkScaleKeyArray)
        DAT_011f38a0[m_eScaleKeyType](m_pkScaleKeyArray);
    if (keys && count)
    {
        m_usNumScaleKeys = (unsigned short)count;
        m_pkScaleKeyArray = keys;
        m_eScaleKeyType = type;
        m_ucScaleKeySize = DAT_011f3758[type];
    }
    else
    {
        m_usNumScaleKeys = 0;
        m_pkScaleKeyArray = 0;
        m_ucScaleKeySize = 0;
        m_eScaleKeyType = NiAnimationKey::NOINTERP;
    }
}

// @fnv 0x00a4ead0
bool NiFloatsExtraDataPoint3Controller::ControlsTransform(NiInterpolator* interpolator, unsigned short index) const
{
    return interpolator->IsPoint3ValueSupported();
}

// Returns true if the base controller and the floats extra data index both match the given object's.
// @fnv 0x00a4eb10
bool NiFloatsExtraDataController::IsEqual(NiObject* object) const
{
    if (!NiExtraDataController::IsEqual(object))
        return false;
    if (m_iFloatsExtraDataIndex != static_cast<NiFloatsExtraDataController*>(object)->m_iFloatsExtraDataIndex)
        return false;
    return true;
}

// @fnv 0x00a4eb40
const NiRTTI* NiFloatsExtraDataPoint3Controller::GetRTTI() const
{
    return &ms_kRTTI;
}

extern int DAT_01099004;

// @fnv 0x00a4e270
void TransformDataOperations::DestroyTransformData()
{
    *reinterpret_cast<int**>(this) = &DAT_01099004;
    TimedRotationKey* pkRotKeys = m_pkRotationKeys;
    if (pkRotKeys)
    {
        if (m_eRotationKeyType == NiAnimationKey::EULERKEY)
            pkRotKeys->ClearFloatKeys();
        DAT_011f38d0[m_eRotationKeyType](pkRotKeys);
    }
    PositionKeyInterpolator* pkPosKeys = m_pkPositionKeys;
    if (pkPosKeys)
    {
        NiPosKeyDeleteFunction pfnPosDeleteFunc = DAT_011f38b8[m_ePositionKeyType];
        pfnPosDeleteFunc(pkPosKeys);
    }
    TimedAnimationKey* pkScaleKeys = m_pkScaleKeyArray;
    if (pkScaleKeys)
    {
        NiFloatKeyDeleteFunction pfnScaleDeleteFunc = DAT_011f38a0[m_eScaleKeyType];
        pfnScaleDeleteFunc(pkScaleKeys);
    }
    NiObject::FUN_00a5d3d0();
}

void __fastcall DestroyTransformData(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);

// Calls DestroyTransformData on pThis, then if flags has bit 1 set calls FUN_00aa1460 with 0x2c, and returns pThis.
// @fnv 0x00a4e5b0
void* __fastcall FUN_00a4e5b0(void* pThis, int, unsigned int flags)
{
    DestroyTransformData(pThis);
    if (flags & 1)
        FUN_00aa1460(pThis, 0x2c);
    return pThis;
}

extern "C" const NiRTTI g_011f3fbc;

// @fnv 0x00a4e0a0
// src: COMMUNITY 0x00a4e0a0
const NiRTTI* __cdecl NiTransformData_GetRTTI()
{
    return &g_011f3fbc;
}

struct BlendPoint3Stub
{
    BlendPoint3Stub* FUN_00a55a10(bool, float, unsigned char);
};
// @fnv 0x00a4eaa0
NiBlendInterpolator* NiFloatsExtraDataPoint3Controller::GetBlendInterpolator(unsigned short usIndex, bool bManagerControlled,
                                                      bool bAccumulateAnimations, float fWeightThreshold,
                                                      unsigned char ucArraySize)
{
    BlendPoint3Stub* p = (BlendPoint3Stub*)BSFadeNode::operator new(0x40);
    if (p)
        return (NiBlendInterpolator*)p->FUN_00a55a10(bManagerControlled, fWeightThreshold, ucArraySize);
    return 0;
}

inline TransformDataOperations::TransformDataOperations() throw()
{
    m_usNumRotKeys = 0;
    m_pkRotationKeys = 0;
    m_eRotationKeyType = NiAnimationKey::NOINTERP;
    m_ucRotationKeySize = 0;
    m_pkPositionKeys = 0;
    m_ePositionKeyType = NiAnimationKey::NOINTERP;
    m_ucPositionKeySize = 0;
    m_pkScaleKeyArray = 0;
    m_eScaleKeyType = NiAnimationKey::NOINTERP;
    m_ucScaleKeySize = 0;
    *reinterpret_cast<int**>(this) = &DAT_01099004;
    m_usNumPosKeys = 0;
    m_usNumScaleKeys = 0;
}

// @fnv 0x00a4e040
NiTransformData* CreateTransformData()
{
    return new TransformDataOperations;
}

// Iterates three slots, deletes each non-null key via the function at DAT_011f38a0 indexed by the slot's index, then zeroes the key, index and count fields.
// @fnv 0x00a29ad0
void TimedRotationKey::ClearFloatKeys()
{
    int* p = (int*)((char*)this + 0x30);
    for (int i = 0; i < 3; ++i)
    {
        int key = *p;
        if (key != 0)
        {
            int iDeleteFuncIndex = *(p - 4);
            NiFloatKeyDeleteFunction pDeleteFunc = DAT_011f38a0[iDeleteFuncIndex];
            pDeleteFunc((TimedAnimationKey*)key);
        }
        *p = 0;
        *(p - 7) = 0;
        *(p - 4) = 0;
        ++p;
    }
}

// Stores a1, a2 and a3 into fields at offsets 0x24, 0xa and 0x14, plus a byte from a3, or clears them when a1 or a2 is null.
// @fnv 0x00a4e0b0
void TransformDataOperations::SetPositionKeyStorage(PositionKeyInterpolator* keys, unsigned int count,
                                                    NiAnimationKey::KeyType type)
{
    if (keys && count)
    {
        m_usNumPosKeys = static_cast<unsigned short>(count);
        m_pkPositionKeys = keys;
        m_ePositionKeyType = type;
        m_ucPositionKeySize = DAT_011f375e[type];
    }
    else
    {
        m_usNumPosKeys = 0;
        m_pkPositionKeys = 0;
        m_ePositionKeyType = NiAnimationKey::NOINTERP;
        m_ucPositionKeySize = 0;
    }
}

// @fnv 0x00a4e0f0
void TransformDataOperations::SetScaleKeyStorage(TimedAnimationKey* keys, unsigned int count,
                                                 NiAnimationKey::KeyType type)
{
    if (keys && count)
    {
        m_usNumScaleKeys = static_cast<unsigned short>(count);
        m_pkScaleKeyArray = keys;
        m_eScaleKeyType = type;
        m_ucScaleKeySize = DAT_011f3758[type];
    }
    else
    {
        m_usNumScaleKeys = 0;
        m_pkScaleKeyArray = 0;
        m_ucScaleKeySize = 0;
        m_eScaleKeyType = NiAnimationKey::NOINTERP;
    }
}

inline unsigned int StrArr::SetAtGrow(unsigned int uiIndex, char*& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}

inline unsigned int StrArr::AddInline(char* element)
{
    return SetAtGrow(m_usSize, element);
}

char* NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d490(const char*, unsigned short);

// @fnv 0x00a4e990
void TransformDataOperations::AppendTransformKeyCounts(void* pStrArr)
{
    StrArr* apViewerStrings = (StrArr*)pStrArr;
    NiObject::AddViewerStrings(reinterpret_cast<NiViewerStringsArray*>(apViewerStrings));
    apViewerStrings->AddInline(NiViewerStrings_NiGetViewerString_Title(g_011f3fbc.m_pcName));
    apViewerStrings->AddInline(NiGetViewerString_00a7d490("m_usNumRotKeys", m_usNumRotKeys));
    apViewerStrings->AddInline(NiGetViewerString_00a7d490("m_usNumPosKeys", m_usNumPosKeys));
    apViewerStrings->AddInline(NiGetViewerString_00a7d490("m_usNumScaleKeys", m_usNumScaleKeys));
}

void UpdateSlotStates(unsigned int content, NiAnimationKey::KeyType type, NiAnimationKey*& keys, unsigned int& count,
                      float start, float end);

// @fnv 0x00a4df40
void TransformDataOperations::RestrictKeyRange(float start, float end)
{
    unsigned int count;
    NiAnimationKey* keys;
    if (m_usNumRotKeys)
    {
        count = m_usNumRotKeys;
        keys = reinterpret_cast<NiAnimationKey*>(m_pkRotationKeys);
        UpdateSlotStates(2, m_eRotationKeyType, keys, count, start, end);
        m_usNumRotKeys = static_cast<unsigned short>(count);
        m_pkRotationKeys = reinterpret_cast<TimedRotationKey*>(keys);
    }
    if (m_usNumPosKeys)
    {
        count = m_usNumPosKeys;
        keys = reinterpret_cast<NiAnimationKey*>(m_pkPositionKeys);
        UpdateSlotStates(1, m_ePositionKeyType, keys, count, start, end);
        m_usNumPosKeys = static_cast<unsigned short>(count);
        m_pkPositionKeys = reinterpret_cast<PositionKeyInterpolator*>(keys);
    }
    if (m_usNumScaleKeys)
    {
        count = m_usNumScaleKeys;
        keys = reinterpret_cast<NiAnimationKey*>(m_pkScaleKeyArray);
        UpdateSlotStates(0, m_eScaleKeyType, keys, count, start, end);
        m_usNumScaleKeys = static_cast<unsigned short>(count);
        m_pkScaleKeyArray = reinterpret_cast<TimedAnimationKey*>(keys);
    }
}

typedef bool(__cdecl* NiAnimKeyEqualFunction)(void*, void*);
extern NiAnimKeyEqualFunction DAT_011f3b10[NiAnimationKey::NUMKEYTYPES];
extern NiAnimKeyEqualFunction DAT_011f3af8[NiAnimationKey::NUMKEYTYPES];
extern NiAnimKeyEqualFunction DAT_011f3ae0[NiAnimationKey::NUMKEYTYPES];

// @fnv 0x00a4e130
bool TransformDataOperations::CompareTransformData(NiObject* pkObject)
{
    if (!NiObject::IsSameAs(pkObject))
        return false;

    NiTransformData* pkData = (NiTransformData*)pkObject;
    if (m_usNumRotKeys != pkData->m_usNumRotKeys || m_eRotationKeyType != pkData->m_eRotationKeyType ||
        m_usNumPosKeys != pkData->m_usNumPosKeys || m_ePositionKeyType != pkData->m_ePositionKeyType ||
        m_usNumScaleKeys != pkData->m_usNumScaleKeys || m_eScaleKeyType != pkData->m_eScaleKeyType ||
        m_ucRotationKeySize != pkData->m_ucRotationKeySize || m_ucPositionKeySize != pkData->m_ucPositionKeySize ||
        m_ucScaleKeySize != pkData->m_ucScaleKeySize)
        return false;

    NiAnimKeyEqualFunction pfnKeyEqual = DAT_011f3b10[m_eRotationKeyType];
    unsigned int i;
    for (i = 0; i < m_usNumRotKeys; i++)
    {
        char* pKeyB = (char*)pkData->m_pkRotationKeys + i * m_ucRotationKeySize;
        char* pKeyA = (char*)m_pkRotationKeys + i * m_ucRotationKeySize;
        if (!pfnKeyEqual(pKeyA, pKeyB))
            return false;
    }

    pfnKeyEqual = DAT_011f3af8[m_ePositionKeyType];
    for (i = 0; i < m_usNumPosKeys; i++)
    {
        char* pKeyB = (char*)pkData->m_pkPositionKeys + i * m_ucPositionKeySize;
        char* pKeyA = (char*)m_pkPositionKeys + i * m_ucPositionKeySize;
        if (!pfnKeyEqual(pKeyA, pKeyB))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_eScaleKeyType];
    for (i = 0; i < m_usNumScaleKeys; i++)
    {
        char* pKeyB = (char*)pkData->m_pkScaleKeyArray + i * m_ucScaleKeySize;
        char* pKeyA = (char*)m_pkScaleKeyArray + i * m_ucScaleKeySize;
        if (!pfnKeyEqual(pKeyA, pKeyB))
            return false;
    }

    return true;
}

void __cdecl NiAnimationKey_CopySequence(int iKind, NiAnimationKey::KeyType keyType, void* pvExtra, unsigned int ItemUpdateArray, float fA, float fB, int* piOutA,
                          int* piOutB);

// @fnv 0x00a4e410
void TransformDataOperations::ExtractKeyRange(float fA, float fB, NiPointer<NiTransformData>& spOut)
{
    NiTransformData* pkData = 0;
    NiObject::ResolveObjectPointer(reinterpret_cast<NiPointer<NiObject>&>(pkData));
    NiTransformData* pkResult = pkData;
    if (pkResult)
        pkResult->IncRefCount();
    int iOutA = 0;
    int iOutB = 0;
    if (m_usNumRotKeys > 0)
    {
        NiAnimationKey_CopySequence(2, m_eRotationKeyType, m_pkRotationKeys, m_usNumRotKeys, fA, fB, &iOutA, &iOutB);
        pkResult->SetRotationKeys(reinterpret_cast<TimedRotationKey*>(iOutA), iOutB, m_eRotationKeyType);
    }
    if (m_usNumPosKeys > 0)
    {
        NiAnimationKey_CopySequence(1, m_ePositionKeyType, m_pkPositionKeys, m_usNumPosKeys, fA, fB, &iOutA, &iOutB);
        pkResult->SetPositionKeys(reinterpret_cast<PositionKeyInterpolator*>(iOutA), iOutB, m_ePositionKeyType);
    }
    if (m_usNumScaleKeys > 0)
    {
        NiAnimationKey_CopySequence(0, m_eScaleKeyType, m_pkScaleKeyArray, m_usNumScaleKeys, fA, fB, &iOutA, &iOutB);
        pkResult->SetScaleKeys(reinterpret_cast<TimedAnimationKey*>(iOutA), iOutB, m_eScaleKeyType);
    }
    spOut = pkResult;
    if (pkResult)
        pkResult->DecRefCount();
    if (pkData)
        pkData->DecRefCount();
}

// The shared stream declarations leave storage opaque. Preserve the original
// inline transfers and the input/output pointer offsets used by this unit.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline unsigned int NiBinaryStream::Write(const void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    unsigned int written = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(
        this, data, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}

inline unsigned int NiBinaryStream::Read(void* destination, unsigned int bytes)
{
    unsigned int componentSize = bytes;
    unsigned int read = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
        this, destination, bytes, &componentSize, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += read;
    return read;
}

template <class T> inline void SaveAnimationValue(NiStream& stream, const T& value)
{
    stream.GetBinaryStream()->Write(&value, sizeof(T));
}
typedef void(__cdecl* RotationSave)(NiStream&, TimedRotationKey*, unsigned int);
typedef void(__cdecl* PositionSave)(NiStream&, PositionKeyInterpolator*, unsigned int);
typedef void(__cdecl* ScaleSave)(NiStream&, TimedAnimationKey*, unsigned int);
extern RotationSave g_011f3a80[];
extern PositionSave g_011f3a68[];
extern ScaleSave g_011f3a50[];

// Saves the transform data's rotation, position and scale key counts and key arrays to the stream via the per-type save function tables.
// @fnv 0x00a4e810
void TransformDataOperations::SaveTransformData(NiStream& stream)
{
    NiObject::SaveBinary(stream);
    unsigned int count = m_usNumRotKeys;
    SaveAnimationValue(stream, count);
    if (m_usNumRotKeys > 0)
    {
        SaveAnimationValue(stream, m_eRotationKeyType);
        count = m_usNumRotKeys;
        g_011f3a80[m_eRotationKeyType](stream, m_pkRotationKeys, count);
    }
    count = m_usNumPosKeys;
    SaveAnimationValue(stream, count);
    if (m_usNumPosKeys > 0)
    {
        SaveAnimationValue(stream, m_ePositionKeyType);
        count = m_usNumPosKeys;
        g_011f3a68[m_ePositionKeyType](stream, m_pkPositionKeys, count);
    }
    count = m_usNumScaleKeys;
    SaveAnimationValue(stream, count);
    if (m_usNumScaleKeys > 0)
    {
        SaveAnimationValue(stream, m_eScaleKeyType);
        count = m_usNumScaleKeys;
        g_011f3a50[m_eScaleKeyType](stream, m_pkScaleKeyArray, count);
    }
}

extern void FUN_00a57630();

// @fnv 0x00a4eaf0
// src: XBOX_PDB 0x00a4eaf0
void NiFloatsExtraDataPoint3Controller_LinkObject()
{
    FUN_00a57630();
}

// @fnv 0x00a4eb00
bool __fastcall RegisterPoint3Controller(NiFloatsExtraDataPoint3Controller* controller, int, NiStream& stream)
{
    return controller->NiSingleInterpController::RegisterStreamables(stream);
}

template <class T> inline void TransformDataReadEnum(NiStream& stream, T& value)
{
    unsigned int serialized;
    stream.Istr().Read(&serialized, sizeof(serialized));
    value = static_cast<T>(serialized);
}
extern TimedRotationKey*(__cdecl* DAT_011f3de0[])(NiStream&, unsigned int);
extern PositionKeyInterpolator*(__cdecl* DAT_011f3dc8[])(NiStream&, unsigned int);
extern TimedAnimationKey*(__cdecl* DAT_011f3db0[])(NiStream&, unsigned int);
extern void(__cdecl* DAT_011f37b0[])(TimedRotationKey*, unsigned int, unsigned char);
extern void(__cdecl* DAT_011f3798[])(PositionKeyInterpolator*, unsigned int, unsigned char);
extern void(__cdecl* DAT_011f3780[])(TimedAnimationKey*, unsigned int, unsigned char);
typedef TimedRotationKey*(__cdecl* RotCreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* RotLoadFunction)(TimedRotationKey*, unsigned int, unsigned char);
inline unsigned char GetRotKeySize(NiAnimationKey::KeyType type)
{
    return DAT_011f3764[type];
}
inline RotCreateFunction GetRotCreateFunction(NiAnimationKey::KeyType type)
{
    return DAT_011f3de0[type];
}
inline RotLoadFunction GetRotLoadFunction(NiAnimationKey::KeyType type)
{
    return DAT_011f37b0[type];
}
typedef PositionKeyInterpolator*(__cdecl* PosCreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* PosLoadFunction)(PositionKeyInterpolator*, unsigned int, unsigned char);
inline unsigned char GetPosKeySize(NiAnimationKey::KeyType type)
{
    return DAT_011f375e[type];
}
inline PosCreateFunction GetPosCreateFunction(NiAnimationKey::KeyType type)
{
    return DAT_011f3dc8[type];
}
inline PosLoadFunction GetPosLoadFunction(NiAnimationKey::KeyType type)
{
    return DAT_011f3798[type];
}
typedef TimedAnimationKey*(__cdecl* ScaleCreateFunction)(NiStream&, unsigned int);
typedef void(__cdecl* ScaleLoadFunction)(TimedAnimationKey*, unsigned int, unsigned char);
inline unsigned char GetScaleKeySize(NiAnimationKey::KeyType type)
{
    return DAT_011f3758[type];
}
inline ScaleCreateFunction GetScaleCreateFunction(NiAnimationKey::KeyType type)
{
    return DAT_011f3db0[type];
}
inline ScaleLoadFunction GetScaleLoadFunction(NiAnimationKey::KeyType type)
{
    return DAT_011f3780[type];
}
void __cdecl Object_DoNothing(const char* message);

// Reads rotation, position, and scale key data from a NiStream, creating and loading each key set via type-specific factory and load functions.
// @fnv 0x00a4e5d0
void TransformDataOperations::LoadTransformData(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    unsigned int numKeys;
    stream.Istr().Read(&numKeys, 4);
    if (numKeys > 0)
    {
        NiAnimationKey::KeyType type;
        TransformDataReadEnum(stream, type);
        unsigned char keySize = GetRotKeySize(type);
        TimedRotationKey* keys = GetRotCreateFunction(type)(stream, numKeys);
        GetRotLoadFunction(type)(keys, numKeys, keySize);
        if (numKeys > 65535)
        {
            numKeys = 65535;
            Object_DoNothing("Transform data loading has more than 65535 rotation keys!");
        }
        SetRotationKeys(keys, numKeys, type);
    }
    stream.Istr().Read(&numKeys, 4);
    if (numKeys > 0)
    {
        NiAnimationKey::KeyType type;
        TransformDataReadEnum(stream, type);
        unsigned char keySize = GetPosKeySize(type);
        PositionKeyInterpolator* keys = GetPosCreateFunction(type)(stream, numKeys);
        GetPosLoadFunction(type)(keys, numKeys, keySize);
        if (numKeys > 65535)
        {
            numKeys = 65535;
            Object_DoNothing("Transform data loading has more than 65535 position keys!");
        }
        SetPositionKeys(keys, numKeys, type);
    }
    stream.Istr().Read(&numKeys, 4);
    if (numKeys > 0)
    {
        NiAnimationKey::KeyType type;
        TransformDataReadEnum(stream, type);
        unsigned char keySize = GetScaleKeySize(type);
        TimedAnimationKey* keys = GetScaleCreateFunction(type)(stream, numKeys);
        GetScaleLoadFunction(type)(keys, numKeys, keySize);
        if (numKeys > 65535)
        {
            numKeys = 65535;
            Object_DoNothing("Transform data loading has more than 65535 scale keys!");
        }
        SetScaleKeys(keys, numKeys, type);
    }
}
