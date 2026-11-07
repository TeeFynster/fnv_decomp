#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiQuaternionInterpolator.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiRotData.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/niquaternioninterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niquaternioninterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a487e0
// src: GUESS 0x00a487e0 (confidence: low)
NiAnimationKey::KeyContent __stdcall NiQuaternionInterpolator::ComputeValue_00a487e0()
{
    return NiAnimationKey::ROTKEY;
}

// @fnv 0x00a48960
// src: XBOX_PDB 0x00a48960
void NiQuaternionInterpolator::GuaranteeTimeRange_00a48960(float m_fStartTime, float m_fMaximumDistance)
{
    NiRotData* p = m_spQuaternionData.m_pObject;
    if (p)
        p->GuaranteeKeysAtStartAndEnd(m_fStartTime, m_fMaximumDistance);
}

extern "C" const void* g_011f3f60;

// @fnv 0x00a48ab0
// src: COMMUNITY 0x00a48ab0
const void* __cdecl NiQuaternionInterpolator_GetRTTI()
{
    return &g_011f3f60;
}

extern int DAT_010986f4;
extern int DAT_011f4208;
extern int DAT_011f420c;
extern int DAT_011f4210;
extern int DAT_011f4214;

// @fnv 0x00a48d70
NiQuaternionInterpolator* __cdecl CreateNiQuaternionInterpolator()
{
    NiQuaternionInterpolator* p = (NiQuaternionInterpolator*)BSFadeNode::operator new(sizeof(NiQuaternionInterpolator));
    if (p)
    {
        p->NiKeyBasedInterpolator::NiKeyBasedInterpolator();
        *(int*)(p) = (int)&DAT_010986f4;
        *reinterpret_cast<int*>(&p->m_kQuaternionValue.m_fVectorX) = DAT_011f4208;
        *reinterpret_cast<int*>(&p->m_kQuaternionValue.m_fVectorY) = DAT_011f420c;
        *reinterpret_cast<int*>(&p->m_kQuaternionValue.m_fVectorZ) = DAT_011f4210;
        *reinterpret_cast<int*>(&p->m_kQuaternionValue.m_fScalarPart) = DAT_011f4214;
        p->m_spQuaternionData.m_pObject = 0;
        p->m_uiLastKeyIndex = 0;
        return p;
    }
    return 0;
}

// These adapters retain the original calling conventions where the shared
// headers do not provide the exact declarations (including the stream class key).
void SaveInterpolatorBase();
void SaveQuaternionValue();

// @fnv 0x00a48a20
void __fastcall SaveQuaternionInterpolator(NiQuaternionInterpolator* self, void*, void* stream)
{
    NiStream* kStream = (NiStream*)stream;
    reinterpret_cast<void (__thiscall*)(NiInterpolator*, NiStream*)>(&SaveInterpolatorBase)(self, kStream);
    reinterpret_cast<void (__thiscall*)(NiQuaternion*, NiStream*)>(&SaveQuaternionValue)(&self->m_kQuaternionValue, kStream);
    kStream->SaveLinkID(reinterpret_cast<const NiObject*>(self->m_spQuaternionData.m_pObject));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void __cdecl _delete(void*, unsigned int);

// @fnv 0x00a48dd0
void* __fastcall ReleaseQuaternionInterpolator(NiQuaternionInterpolator* self, void*, unsigned int uiDeleteFlags)
{
    NiRefObject* p = self->m_spQuaternionData.m_pObject;
    if (p)
    {
        if (InterlockedDecrement((long volatile*)&p->m_uiRefCount) == 0)
            p->DeleteThis();
    }
    self->NiKeyBasedInterpolator::~NiKeyBasedInterpolator();
    if (uiDeleteFlags & 1)
        _delete(self, sizeof(NiQuaternionInterpolator));
    return self;
}

// The original pose test has an unused channel argument.
extern NiBound g_NiBoundDefault;

// @fnv 0x00a48800
bool __fastcall IsQuaternionPose(NiQuaternionInterpolator* self, void*, unsigned int nTime)
{
    if (self->m_spQuaternionData.m_pObject != 0)
        return false;
    bool bIsDefault = !((NiBound*)&self->m_kQuaternionValue)->Object_HasEqualFloatComponents(g_NiBoundDefault);
    return bIsDefault;
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)

inline void CopyQuaternionValue(NiQuaternion& dst, const NiQuaternion& src)
{
    memcpy(&dst, &src, sizeof(dst));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

inline TimedRotationKey* NiRotData::ComputePositionAtTime(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
{
    uiNumKeys = m_uiNumKeys;
    eType = m_eRequestType;
    ucSize = m_ucKeyDataSize;
    return m_pKeyArray;
}

inline bool QuaternionEqual(const NiQuaternion& a, const NiQuaternion& b)
{
    // The original equality routine is declared by the shared NiBound header.
    return ((NiBound*)&a)->Object_HasEqualFloatComponents((const NiBound&)b);
}

struct TimedRotationKey
{
    float m_fTime;
    NiQuaternion m_kRotationValue;
};

extern NiQuaternion g_kInvalidQuat;

inline void ClearQuaternionData(NiPointer<NiRotData>& data)
{
    if (data.m_pObject)
    {
        data.m_pObject->NiRefObject::DecRefCount();
        data.m_pObject = 0;
    }
}

// @fnv 0x00a48820
void NiQuaternionInterpolator::CollapseQuatInterp()
{
    if (m_spQuaternionData.m_pObject)
    {
        unsigned int uiNumKeys;
        int eType;
        unsigned char ucSize;
        TimedRotationKey* pkKeys = m_spQuaternionData.m_pObject->ComputePositionAtTime(uiNumKeys, eType, ucSize);
        if (uiNumKeys == 0)
        {
            ClearQuaternionData(m_spQuaternionData);
            CopyQuaternionValue(m_kQuaternionValue, g_kInvalidQuat);
        }
        else
        {
            NiQuaternion kValue = pkKeys->m_kRotationValue;
            if (uiNumKeys != 1 || eType == 4)
            {
                if (eType != 1 && eType != 5)
                    return;
                bool bAllEqual = true;
                for (unsigned int i = 1; bAllEqual && i < uiNumKeys; i++)
                {
                    TimedRotationKey* pk = (TimedRotationKey*)((char*)pkKeys + i * ucSize);
                    if (pk->m_kRotationValue != kValue)
                        bAllEqual = false;
                }
                if (!bAllEqual)
                    return;
            }
            ClearQuaternionData(m_spQuaternionData);
            CopyQuaternionValue(m_kQuaternionValue, kValue);
        }
    }
}

// The original base equality stub is not declared by the shared header.
void InterpolatorBaseIsEqual();

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

// @fnv 0x00a48a50
bool NiQuaternionInterpolator::IsEqual(NiObject* pkObject) const
{
    if (!reinterpret_cast<bool (__thiscall*)(const NiKeyBasedInterpolator*, NiObject*)>(&InterpolatorBaseIsEqual)(this, pkObject))
        return false;

    NiQuaternionInterpolator* pkOther = (NiQuaternionInterpolator*)pkObject;

    if (m_kQuaternionValue != pkOther->m_kQuaternionValue)
        return false;

    if ((m_spQuaternionData && !pkOther->m_spQuaternionData) || (!m_spQuaternionData && pkOther->m_spQuaternionData))
        return false;

    if (m_spQuaternionData && !static_cast<const NiObject*>(m_spQuaternionData.operator->())->IsEqual(pkOther->m_spQuaternionData))
        return false;

    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);

// NiRotData's range-copy helper is not declared by the shared header.
void CopyRotationData();

inline void DecRef(NiRefObject* p)
{
    if (InterlockedDecrement((long volatile*)&p->m_uiRefCount) == 0)
        p->DeleteThis();
}

inline void Assign(NiRefObject*& dst, NiRefObject* src)
{
    if (dst != src)
    {
        if (dst)
            DecRef(dst);
        dst = src;
        if (dst)
            InterlockedIncrement((long volatile*)&dst->m_uiRefCount);
    }
}

// @fnv 0x00a48bc0
NiInterpolator* NiQuaternionInterpolator::CloneForTimeRange(float a, float b)
{
    NiQuaternionInterpolator* pResult = (NiQuaternionInterpolator*)NiInterpolator::CloneForTimeRange(a, b);
    if (m_spQuaternionData.m_pObject)
    {
        NiRefObject* pInterp = 0;
        reinterpret_cast<void (__thiscall*)(NiRotData*, float, float, NiRefObject**)>(&CopyRotationData)(
            m_spQuaternionData.m_pObject, a, b, &pInterp);
        Assign(reinterpret_cast<NiRefObject*&>(pResult->m_spQuaternionData.m_pObject), pInterp);
        pResult->m_uiLastKeyIndex = 0;
        if (pInterp)
            ::DecRef(pInterp);
    }
    return pResult;
}

extern "C" char DAT_01098800;
extern "C" char DAT_010987ec;

struct Stream
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;

    void __thiscall FUN_0096ad30(unsigned int index);
    void __thiscall FUN_0096ae90(unsigned int index, void** value);
};

void* __cdecl NiViewerStrings_NiGetViewerString_Title(const void* value);
void* __cdecl NiGetViewerString_00a7d5a0(const void* key, void* value);

// The shared base does not declare its viewer-string override.
void GetKeyBasedViewerStrings();

// @fnv 0x00a48ea0
void NiQuaternionInterpolator::GetViewerStrings(NiViewerStringsArray* strings)
{
    Stream* stream = (Stream*)strings;
    reinterpret_cast<void (__thiscall*)(NiKeyBasedInterpolator*, NiViewerStringsArray*)>(&GetKeyBasedViewerStrings)(this, strings);
    void* value = NiViewerStrings_NiGetViewerString_Title(g_011f3f60);
    unsigned int index = stream->unk0a;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0e);
    stream->FUN_0096ae90(index, &value);

    value = m_kQuaternionValue.FormatToBuffer(&DAT_01098800);
    index = stream->unk0a;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0e);
    stream->FUN_0096ae90(index, &value);

    void* payload = m_spQuaternionData.m_pObject;
    value = NiGetViewerString_00a7d5a0(&DAT_010987ec, payload);
    index = stream->unk0a;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0e);
    stream->FUN_0096ae90(index, &value);
}

NiQuaternion __cdecl FUN_00a28740(float fTime, TimedRotationKey* pkKeys, int eType, unsigned int uiNumKeys,
                             unsigned int* puiLastIdx, unsigned char ucSize);

inline bool NiQuaternionInterpolator::TimeHasChanged(float fTime)
{
    return m_fLastTime != fTime;
}

inline TimedRotationKey* NiQuaternionInterpolator::GetKeys(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
{
    if (m_spQuaternionData.m_pObject)
        return m_spQuaternionData.m_pObject->ComputePositionAtTime(uiNumKeys, eType, ucSize);
    uiNumKeys = 0;
    eType = 0;
    ucSize = 0;
    return 0;
}

// @fnv 0x00a48c80
bool NiQuaternionInterpolator::GetQuaternionAtTime(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue)
{
    if (!TimeHasChanged(fTime))
    {
        CopyQuaternionValue(kValue, m_kQuaternionValue);
        if (QuaternionEqual(m_kQuaternionValue, (*(const NiQuaternion*)&DAT_011f4208)))
            return false;
        return true;
    }

    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    TimedRotationKey* pkKeys = GetKeys(uiNumKeys, eType, ucSize);
    if (uiNumKeys > 0)
    {
        CopyQuaternionValue(m_kQuaternionValue, FUN_00a28740(fTime, pkKeys, eType, uiNumKeys, &m_uiLastKeyIndex, ucSize));
    }

    if (QuaternionEqual(m_kQuaternionValue, (*(const NiQuaternion*)&DAT_011f4208)))
        return false;

    CopyQuaternionValue(kValue, m_kQuaternionValue);
    m_fLastTime = fTime;
    return true;
}

extern const float DAT_010986e8;
extern const float DAT_01015f5c;
struct KeyTrackData
{
    float m_00;
    int unk04, unk08, unk0c, unk10, m_14, m_18, m_1c, unk20, unk24, unk28;
    unsigned char m_2c, m_2d, m_2e;
    float* m_30;
    float* m_34;
    float* m_38;
};

// @fnv 0x00a48ac0
void NiQuaternionInterpolator::GetInterpolatorTimeRange(float& begin, float& end) const
{
    float* outLo = &begin;
    float* outHi = &end;
    NiRotData* p = m_spQuaternionData.m_pObject;
    if (p)
    {
        unsigned int count = p->m_uiNumKeys;
        // Preserve the original volatile read of the interpolation type.
        int type = *(volatile int*)&p->m_eRequestType;
        unsigned char stride = p->m_ucKeyDataSize;
        KeyTrackData* base = (KeyTrackData*)p->m_pKeyArray;
        if (count > 0)
        {
            if (type == 4)
            {
                float fKey;
                float lo = DAT_010986e8;
                float hi = DAT_01015f5c;
                unsigned char* pucStride = &base->m_2c;
                float** pk = &base->m_30;
                int iTrack = 3;
                do
                {
                    float* key = *pk;
                    fKey = key[0];
                    int iKeyCount = *(int*)((char*)pk - 0x1c);
                    unsigned char ucKeyStride = *pucStride;
                    if (fKey < lo)
                        lo = fKey;
                    fKey = *(float*)((char*)key + (iKeyCount - 1) * ucKeyStride);
                    if (fKey > hi)
                        hi = fKey;
                    pk++;
                    pucStride++;
                } while (--iTrack);
                *outLo = lo;
                *outHi = hi;
                return;
            }
            *outLo = base->m_00;
            *outHi = *(float*)((char*)base + (count - 1) * stride);
            return;
        }
    }
    *outLo = 0.0f;
    *outHi = 0.0f;
}

// The shared interpolator does not declare the original clone-copy helper.
void CopyQuaternionInterpolator();

inline NiQuaternionInterpolator* InitializeQuaternionInterpolator(NiQuaternionInterpolator* object)
{
    object->NiKeyBasedInterpolator::NiKeyBasedInterpolator();
    *(void**)object = &DAT_010986f4;
    CopyQuaternionValue(object->m_kQuaternionValue, *reinterpret_cast<const NiQuaternion*>(&DAT_011f4208));
    object->m_spQuaternionData.m_pObject = 0;
    *(volatile unsigned int*)&object->m_uiLastKeyIndex = 0;
    return object;
}

// @fnv 0x00a48e20
NiObject* NiQuaternionInterpolator::MakeClone(CloningProcess& cloning)
{
    NiQuaternionInterpolator* storage = (NiQuaternionInterpolator*)BSFadeNode::operator new(sizeof(NiQuaternionInterpolator));
    NiQuaternionInterpolator* clone = storage ? InitializeQuaternionInterpolator(storage) : 0;
    reinterpret_cast<void (__thiscall*)(NiQuaternionInterpolator*, NiQuaternionInterpolator*, CloningProcess*)>(
        &CopyQuaternionInterpolator)(this, clone, &cloning);
    return clone;
}
