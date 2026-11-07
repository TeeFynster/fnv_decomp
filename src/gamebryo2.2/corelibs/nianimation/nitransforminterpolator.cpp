// gamebryo2.2/corelibs/nianimation/nitransforminterpolator.cpp: NiTransformInterpolator (26 functions)

#include "../../../../include/NiObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransformInterpolator.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BSRotAccumTransfInterpolator.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiTransformData.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;
struct TransformWords
{
    unsigned int words[8];
};
static inline void CopyTransformRotation(NiQuaternion& destination, const NiQuaternion& source)
{
    *(unsigned int*)&destination.m_fVectorX = *(const unsigned int*)&source.m_fVectorX;
    *(unsigned int*)&destination.m_fVectorY = *(const unsigned int*)&source.m_fVectorY;
    *(unsigned int*)&destination.m_fVectorZ = *(const unsigned int*)&source.m_fVectorZ;
    *(unsigned int*)&destination.m_fScalarPart = *(const unsigned int*)&source.m_fScalarPart;
}
inline NiQuatTransform::NiQuatTransform()
{
    *(NiPoint3*)&x = DAT_011a8400;
    CopyTransformRotation(*(NiQuaternion*)&qx, DAT_011f3704);
    scale = DAT_01096b8c;
}
inline NiQuatTransform& NiQuatTransform::operator=(const NiQuatTransform& rhs)
{
    *(TransformWords*)this = *(const TransformWords*)&rhs;
    return *this;
}

class PositionKeyInterpolator : public NiAnimationKey
{
  public:
    static NiPoint3 InterpolatePosition(float, PositionKeyInterpolator*, NiAnimationKey::KeyType, unsigned int,
                                        unsigned int&, unsigned char);
};
class TimedRotationKey : public NiAnimationKey
{
  public:
    static NiQuaternion InterpolatePosition(float, TimedRotationKey*, NiAnimationKey::KeyType, unsigned int,
                                            unsigned int&, unsigned char);
};
class TimedAnimationKey : public NiAnimationKey
{
  public:
    static float InterpolatePosition(float, TimedAnimationKey*, NiAnimationKey::KeyType, unsigned int, unsigned int&,
                                     unsigned char);
};

template <> inline NiPointer<NiTransformData>::NiPointer(NiTransformData* object) : m_pObject(object)
{
    if (m_pObject)
        InterlockedIncrement((volatile long*)((char*)m_pObject + 4));
}
template <> inline NiPointer<NiTransformData>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <> inline NiPointer<NiTransformData>& NiPointer<NiTransformData>::operator=(NiTransformData* object)
{
    if (m_pObject != object)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// Key-array convenience methods are absent from the shared interpolator header.
struct TransformInterpolatorKeys : NiTransformInterpolator
{
    PositionKeyInterpolator* FUN_00a3f990(unsigned int&, NiAnimationKey::KeyType&, unsigned char&);
    TimedRotationKey* NiTransformInterpolator_GetRotData(unsigned int&, NiAnimationKey::KeyType&, unsigned char&);
    TimedAnimationKey* NiTransformInterpolator_GetScaleData(unsigned int&, NiAnimationKey::KeyType&, unsigned char&);
};

// @fnv 0x00a3fae0
NiTransformInterpolator::NiTransformInterpolator(NiQuatTransform kTransform) throw()
    : m_kDefaultTransform(kTransform), m_spTransformData(0)
{
    m_usLastRotationKeyIndex = 0;
    m_usLastPositionKeyIndex = 0;
    m_usLastScaleKeyIndex = 0;
    m_bPoseValid = false;
}

static inline bool TransformIsValid(const NiQuatTransform& value)
{
    return value.scale != -3.4028234663852886e38 || value.qy != -3.4028234663852886e38 ||
           value.x != -3.4028234663852886e38;
}
static inline void SetTransformPosition(NiQuatTransform& transform, const NiPoint3& position)
{
    *(unsigned int*)&transform.x = *(const unsigned int*)&position.x;
    *(unsigned int*)&transform.y = *(const unsigned int*)&position.y;
    *(unsigned int*)&transform.z = *(const unsigned int*)&position.z;
}
// @fnv 0x00a3fdb0
bool NiTransformInterpolator::Update(float time, NiObjectNET* target, NiQuatTransform& value)
{
    if (m_bPoseValid)
    {
        m_fLastTime = time;
        value = m_kDefaultTransform;
        return true;
    }
    if (m_fLastTime == time)
    {
        value = m_kDefaultTransform;
        if (!TransformIsValid(m_kDefaultTransform))
            return false;
        return true;
    }
    unsigned int count;
    NiAnimationKey::KeyType eKeyType;
    unsigned char size;
    unsigned int last;
    PositionKeyInterpolator* pTranslateKeys = ((TransformInterpolatorKeys*)this)->FUN_00a3f990(count, eKeyType, size);
    if (count > 0)
    {
        last = m_usLastRotationKeyIndex;
        SetTransformPosition(m_kDefaultTransform,
            PositionKeyInterpolator::InterpolatePosition(time, pTranslateKeys, eKeyType, count, last, size));
        m_usLastRotationKeyIndex = (unsigned short)last;
    }
    TimedRotationKey* pRotateKeys = ((TransformInterpolatorKeys*)this)->NiTransformInterpolator_GetRotData(count, eKeyType, size);
    if (count > 0)
    {
        last = m_usLastPositionKeyIndex;
        CopyTransformRotation(*(NiQuaternion*)&m_kDefaultTransform.qx,
            TimedRotationKey::InterpolatePosition(time, pRotateKeys, eKeyType, count, last, size));
        m_usLastPositionKeyIndex = (unsigned short)last;
    }
    TimedAnimationKey* pScaleKeys = ((TransformInterpolatorKeys*)this)->NiTransformInterpolator_GetScaleData(count, eKeyType, size);
    if (count > 0)
    {
        last = m_usLastScaleKeyIndex;
        m_kDefaultTransform.scale =
            TimedAnimationKey::InterpolatePosition(time, pScaleKeys, eKeyType, count, last, size);
        m_usLastScaleKeyIndex = (unsigned short)last;
    }
    value = m_kDefaultTransform;
    if (!TransformIsValid(m_kDefaultTransform))
        return false;
    m_fLastTime = time;
    return true;
}

void __fastcall UpdateState_00a3ca30(void* pThis);
void __cdecl FUN_00aa1460(void* p, unsigned int s);

// @fnv 0x00a40410
void* __fastcall FUN_00a40410(NiTransformInterpolator* pThis, int, unsigned int flags)
{
    NiRefObject* pkData = *(NiRefObject**)((char*)pThis + 0x2c);
    if (pkData)
        pkData->DecRefCount();
    UpdateState_00a3ca30(pThis);
    if (flags & 1)
        FUN_00aa1460(pThis, 0x48);
    return pThis;
}

enum KeyContent
{
    KEY_CONTENT_NONE = 0,
    KEY_CONTENT_QUATERNION = 1,
    KEY_CONTENT_POSITION = 2,
    KEY_CONTENT_ROTATION = 3,
    KEY_CONTENT_SCALE = 4,
    KEY_CONTENT_NORMAL = 5,
    KEY_CONTENT_TANGENT = 6
};

// Maps a channel index to a KeyContent: 0 quaternion, 1 position, 2 none, otherwise tangent.
// @fnv 0x00a3f570
// src: XBOX_PDB 0x00a3f570
KeyContent __stdcall NiTransformInterpolator_GetKeyContent(unsigned short usChannel)
{
    if (usChannel == 0)
        return KEY_CONTENT_QUATERNION;
    if (usChannel == 1)
        return KEY_CONTENT_POSITION;
    if (usChannel == 2)
        return KEY_CONTENT_NONE;
    return KEY_CONTENT_TANGENT;
}

// Channel key types (data offsets 0x10-0x18) are not declared by the shared interpolator header.
struct TransformChannelTypeAccess : NiTransformInterpolator
{
    void* GetChannelType(short channel);
};

// Returns the pointer stored at offset 0x14, 0x10 or 0x18 of the object at this+0x2c depending on a (0, 1, 2), or null.
// @fnv 0x00a3f600
void* TransformChannelTypeAccess::GetChannelType(short aiIndex)
{
    if (aiIndex == 0)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(void**)((char*)p + 0x14);
    }
    else if (aiIndex == 1)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(void**)((char*)p + 0x10);
    }
    else if (aiIndex == 2)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(void**)((char*)p + 0x18);
    }
    return 0;
}

// Returns a field from the object at offset 0x2c based on arg (0, 1, or 2), or 0 if that pointer is null or arg is other.
// @fnv 0x00a3f650
NiAnimationKey* NiTransformInterpolator::GetChannelKeys(unsigned short aiIndex) const
{
    if (aiIndex == 0)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(NiAnimationKey**)((char*)p + 0x24);
    }
    else if (aiIndex == 1)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(NiAnimationKey**)((char*)p + 0x20);
    }
    else if (aiIndex == 2)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(NiAnimationKey**)((char*)p + 0x28);
    }
    return 0;
}

// Reads fields at offsets 0xa, 0x14, 0x1d and 0x24 from the object at this+0x2c into the out parameters and returns the last; zeroes them if that pointer is null.
// @fnv 0x00a3f990
// Pointer-based position-key accessor used by 0x00a3f990; the shared header lacks this overload.
struct PositionChannelAccess : NiTransformInterpolator
{
    int GetPositionKeys(unsigned int*, int*, unsigned char*);
};
int PositionChannelAccess::GetPositionKeys(unsigned int* puiValue, int* piValue, unsigned char* pucValue)
{
    void* p = m_spTransformData.m_pObject;
    if (p)
    {
        *puiValue = *(unsigned short*)((char*)p + 0xa);
        *piValue = *(int*)((char*)p + 0x14);
        *pucValue = *(unsigned char*)((char*)p + 0x1d);
        return *(int*)((char*)p + 0x24);
    }
    *puiValue = 0;
    *piValue = 0;
    *pucValue = 0;
    return 0;
}

extern "C" const char* g_011f3ee0_arg1;

// @fnv 0x00a3fad0
const NiRTTI* NiTransformInterpolator::GetRTTI() const
{
    return (const NiRTTI*)&g_011f3ee0_arg1;
}

// Time-range operations not yet declared by the shared header.
struct NiTransformDataTimeRange : NiTransformData
{
    void GetSequenceData(float, float, NiTransformData**);
    void GuaranteeTimeRange(float, float);
};
// The shared class has no transform-data setter; this adapter adds only its declaration.
struct TransformDataAssignment : NiTransformInterpolator
{
    void SetTransformData(NiTransformData* pkData);
};
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// @fnv 0x00a3fd10
NiInterpolator* NiTransformInterpolator::CloneForTimeRange(float m_fStartTime, float m_fMaximumDistance)
{
    NiTransformInterpolator* pkSeqInterp =
        (NiTransformInterpolator*)NiInterpolator::CloneForTimeRange(m_fStartTime, m_fMaximumDistance);
    if (pkSeqInterp && *(void**)((char*)this + 0x2c))
    {
        NiTransformData* spNewData = 0;
        ((NiTransformDataTimeRange*)m_spTransformData.m_pObject)->GetSequenceData(m_fStartTime, m_fMaximumDistance, &spNewData);
        ((TransformDataAssignment*)pkSeqInterp)->SetTransformData(spNewData);
        *(unsigned short*)((char*)pkSeqInterp + 0x30) = 0;
        *(unsigned short*)((char*)pkSeqInterp + 0x32) = 0;
        *(unsigned short*)((char*)pkSeqInterp + 0x34) = 0;
        if (spNewData)
        {
            spNewData->DecRefCount();
        }
    }
    return (NiInterpolator*)pkSeqInterp;
}

// Returns the unsigned short at offset 0xa, 0x8 or 0xc of the data pointer at this+0x2c for channel 0, 1 or 2, else 0.
// @fnv 0x00a3f5b0
unsigned int NiTransformInterpolator::GetColorKeyCount(unsigned short usChannel) const
{
    if (usChannel == 0)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned short*)(pkData + 0xa);
    }
    else if (usChannel == 1)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned short*)(pkData + 0x8);
    }
    else if (usChannel == 2)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned short*)(pkData + 0xc);
    }
    return 0;
}

// Returns the bool flag at offset 0x1d, 0x1c or 0x1e of the data pointer at this+0x2c for channel 0, 1 or 2; false otherwise.
// @fnv 0x00a3f6a0
unsigned char NiTransformInterpolator::GetColorKeySize(unsigned short usChannel) const
{
    if (usChannel == 0)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned char*)(pkData + 0x1d);
    }
    else if (usChannel == 1)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned char*)(pkData + 0x1c);
    }
    else if (usChannel == 2)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned char*)(pkData + 0x1e);
    }
    return false;
}

// @fnv 0x00a3f6f0
void NiTransformInterpolator::SetActiveTimeRange(float afArg1, float afArg2)
{
    NiTransformDataTimeRange* pkData = (NiTransformDataTimeRange*)m_spTransformData.m_pObject;
    if (pkData)
        pkData->GuaranteeTimeRange(afArg1, afArg2);
}

// Returns the scale key array from the interpolator's transform data, filling in key count, interpolation type and key size, or zeroes if no data exists.
// @fnv 0x00a3f9e0
// src: COMMUNITY 0x00a3f9e0
TimedAnimationKey* TransformInterpolatorKeys::NiTransformInterpolator_GetScaleData(unsigned int& uiNumScaleKeys,
                                                         NiAnimationKey::KeyType& eScaleKeyType,
                                                         unsigned char& ucScaleKeySize)
{
    NiTransformData* pkData = *(NiTransformData**)&m_spTransformData;
    if (pkData)
    {
        uiNumScaleKeys = pkData->m_usNumScaleKeys;
        eScaleKeyType = (NiAnimationKey::KeyType)pkData->m_eScaleKeyType;
        ucScaleKeySize = pkData->m_ucScaleKeySize;
        return pkData->m_pkScaleKeyArray;
    }
    uiNumScaleKeys = 0;
    eScaleKeyType = NiAnimationKey::NOINTERP;
    ucScaleKeySize = 0;
    return 0;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
inline void* operator new(unsigned int, void* pkMem)
{
    return pkMem;
}
// Allocates a new NiTransformInterpolator and copies this interpolator's data into it via FUN_00a40360, returning it as a NiObject.
// @fnv 0x00a40460
NiObject* NiTransformInterpolator::MakeClone(CloningProcess& kCloning)
{
    NiTransformInterpolator* pkObject = ::new (BSFadeNode::operator new(sizeof(NiTransformInterpolator))) NiTransformInterpolator((NiTransformData*)0);
    CopyMemberData(pkObject, kCloning);
    return (NiObject*)pkObject;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
// Replaces the held NiTransformData pointer with pkData, adjusting reference counts, and resets the three counters to zero.
// @fnv 0x00a3f930
void TransformDataAssignment::SetTransformData(NiTransformData* pkData)
{
    if (m_spTransformData.m_pObject != pkData)
    {
        if (m_spTransformData.m_pObject)
            m_spTransformData.m_pObject->DecRefCount();
        m_spTransformData.m_pObject = pkData;
        if (pkData)
            pkData->IncRefCount();
    }
    m_usLastPositionKeyIndex = 0;
    m_usLastScaleKeyIndex = 0;
    m_usLastRotationKeyIndex = 0;
}

// @fnv 0x00a3fa30
NiTransformInterpolator::NiTransformInterpolator(NiTransformData* pkData) : m_spTransformData(pkData)
{
    m_kDefaultTransform.x = -3.402823466e+38F;
    m_kDefaultTransform.qy = -3.402823466e+38F;
    m_kDefaultTransform.scale = -3.402823466e+38F;
    m_usLastRotationKeyIndex = 0;
    m_usLastPositionKeyIndex = 0;
    m_usLastScaleKeyIndex = 0;
    m_bPoseValid = false;
}

namespace fnv_00a3fb20 {
struct TransformAnimationData : public TimedRotationKey
{
    static int RegisterObjectLoader();
    static void RegisterSupportedFunctions(int, int);
    static NiAnimationKey* CreateObjectFromStream(NiStream*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveToStream(NiStream*, NiAnimationKey*, unsigned int);
    static void SaveBinary(NiStream*, NiAnimationKey*);
    static void Copy(NiAnimationKey*, void*);
    static NiAnimationKey* CreateArray(unsigned int);
    static void DeleteArray(NiAnimationKey*);
    static bool Insert(float, NiAnimationKey**, unsigned int*);
    static float ComputeMaxCurvature(NiAnimationKey*, unsigned int);
    static void Interpolate(float, void*, void*, void*);
    static void InterpolateD1(float, void*, void*, void*);
    static void InterpolateD2(float, void*, void*, void*);
    static bool Equal(void*, void*);
    static void FillDerivedVals(NiAnimationKey*, unsigned int, unsigned char);
    void Initialize(TimedAnimationKey*, unsigned int, int, TimedAnimationKey*, unsigned int, int, TimedAnimationKey*,
                    unsigned int, int);
    void CleanUp();
    void SetKeyData(unsigned char, TimedAnimationKey*);
    void SetNumKeys(unsigned char, unsigned int);
    void SetType(unsigned char, int);
    void SetAnimationKeys(unsigned char, unsigned int, TimedAnimationKey*);
    TimedAnimationKey* GetKeys(unsigned char);
    unsigned char GetKeySize(unsigned char);
    unsigned int GetNumKeys(unsigned char);
    int GetType(unsigned char);
    void* __vecDelDtor(unsigned int);
    char _pad_4[16];
    char m_uiNumKeys[12];
    char m_eRequestType[12];
    char m_ucKeyTypes[3];
    char _pad_2f[1];
    char m_ppKeyData[12];
    char m_uiLastKeyIndex[12];
};
typedef char _sizecheck_NiEulerRotKey[sizeof(TransformAnimationData) == 72 ? 1 : -1];
extern float DAT_01097308;
extern float _DAT_01015f5c;
struct EulerK
{
    char pad[0x14];
    unsigned int m_uiNumKeys[3];
    int m_eRequestType[3];
    unsigned char m_ucKeyTypes[3];
    char pad2f;
    char* m_ppKeyData[3];
};
static inline char* TI_GetPos(NiTransformData* d, unsigned int& n, int& t, unsigned char& s)
{
    char* pk = 0;
    if (d)
    {
        n = d->m_usNumPosKeys;
        t = d->m_ePositionKeyType;
        s = d->m_ucPositionKeySize;
        pk = (char*)d->m_pkPositionKeys;
    }
    else
    {
        n = 0;
    }
    return pk;
}
static inline char* TI_GetRot(NiTransformData* d, unsigned int& n, int& t, unsigned char& s)
{
    char* pk = 0;
    if (d)
    {
        n = d->m_usNumRotKeys;
        t = d->m_eRotationKeyType;
        s = d->m_ucRotationKeySize;
        pk = (char*)d->m_pkRotationKeys;
    }
    else
    {
        n = 0;
    }
    return pk;
}
static inline char* TI_GetScale(NiTransformData* d, unsigned int& n, int& t, unsigned char& s)
{
    char* pk = 0;
    if (d)
    {
        n = d->m_usNumScaleKeys;
        t = d->m_eScaleKeyType;
        s = d->m_ucScaleKeySize;
        pk = (char*)d->m_pkScaleKeyArray;
    }
    else
    {
        n = 0;
    }
    return pk;
}
static inline float TI_Time(char* keys, unsigned int i, unsigned char s)
{
    return *(float*)(keys + i * s);
}

}  // namespace fnv_00a3fb20

// Computes the first and last key times across the position, rotation and scale key arrays, defaulting both to 0 when no keys exist.
// @fnv 0x00a3fb20
void NiTransformInterpolator::GetInterpolatorTimeRange(float& begin, float& end) const
{
    using namespace fnv_00a3fb20;
    float* fBeginKeyTime = &begin;
    float* fEndKeyTime = &end;
    *fBeginKeyTime = DAT_01097308;
    *fEndKeyTime = _DAT_01015f5c;
    bool bHasKeys = false;

    unsigned int uiNumKeys;
    int eTransType;
    unsigned char ucSize;
    char* pkTransKeys = TI_GetPos(*(NiTransformData**)((char*)this + 0x2c), uiNumKeys, eTransType, ucSize);
    if (uiNumKeys > 0)
    {
        float fKeyTime = TI_Time(pkTransKeys, 0, ucSize);
        if (fKeyTime < *fBeginKeyTime)
            *fBeginKeyTime = fKeyTime;
        fKeyTime = TI_Time(pkTransKeys, uiNumKeys - 1, ucSize);
        if (fKeyTime > *fEndKeyTime)
            *fEndKeyTime = fKeyTime;
        bHasKeys = true;
    }

    int eRotType;
    char* pkRotKeys = TI_GetRot(*(NiTransformData**)((char*)this + 0x2c), uiNumKeys, eRotType, ucSize);
    if (uiNumKeys > 0)
    {
        if (eRotType == 4)
        {
            EulerK* pkEulerKey = (EulerK*)pkRotKeys;
            for (unsigned char ucAxis = 0; ucAxis < 3; ucAxis++)
            {
                unsigned int uiNumFloatKeys = pkEulerKey->m_uiNumKeys[ucAxis];
                if (uiNumFloatKeys > 0)
                {
                    char* pkFloatKeys = pkEulerKey->m_ppKeyData[ucAxis];
                    unsigned char ucFloatKeySize = pkEulerKey->m_ucKeyTypes[ucAxis];
                    float fKeyTime = TI_Time(pkFloatKeys, 0, ucFloatKeySize);
                    if (fKeyTime < *fBeginKeyTime)
                        *fBeginKeyTime = fKeyTime;
                    fKeyTime = TI_Time(pkFloatKeys, uiNumFloatKeys - 1, ucFloatKeySize);
                    if (fKeyTime > *fEndKeyTime)
                        *fEndKeyTime = fKeyTime;
                    bHasKeys = true;
                }
            }
        }
        else
        {
            float fKeyTime = TI_Time(pkRotKeys, 0, ucSize);
            if (fKeyTime < *fBeginKeyTime)
                *fBeginKeyTime = fKeyTime;
            fKeyTime = TI_Time(pkRotKeys, uiNumKeys - 1, ucSize);
            if (fKeyTime > *fEndKeyTime)
                *fEndKeyTime = fKeyTime;
            bHasKeys = true;
        }
    }

    int eScaleType;
    char* pkScaleKeys = TI_GetScale(*(NiTransformData**)((char*)this + 0x2c), uiNumKeys, eScaleType, ucSize);
    if (uiNumKeys > 0)
    {
        float fKeyTime = TI_Time(pkScaleKeys, 0, ucSize);
        if (fKeyTime < *fBeginKeyTime)
            *fBeginKeyTime = fKeyTime;
        fKeyTime = TI_Time(pkScaleKeys, uiNumKeys - 1, ucSize);
        if (fKeyTime > *fEndKeyTime)
            *fEndKeyTime = fKeyTime;
        bHasKeys = true;
    }

    if (!bHasKeys)
    {
        *fBeginKeyTime = 0.0f;
        *fEndKeyTime = 0.0f;
    }
}

namespace fnv_00a404b0 {
// Viewer helpers at 0x00a3cbf0 and 0x00a38cb0 are absent from the shared class declarations.
struct InterpolatorViewerBase : NiKeyBasedInterpolator
{
    void GetBaseViewerStrings(StrArr*);
};
struct TransformViewerFields : NiQuatTransform
{
    void GetTransformViewerStrings(StrArr*);
};
extern char* _FUN_00a7d330(char*);
extern char* g_011f3ee0_arg1;
}  // namespace fnv_00a404b0

// @fnv 0x00a404b0
void NiTransformInterpolator::GetViewerStrings(NiViewerStringsArray* pkStrings)
{
    using namespace fnv_00a404b0;
    ((InterpolatorViewerBase*)this)->GetBaseViewerStrings((StrArr*)pkStrings);
    char* pString = _FUN_00a7d330(fnv_00a404b0::g_011f3ee0_arg1);
    unsigned int count = ((StrArr*)pkStrings)->m_usSize;
    unsigned int size = ((StrArr*)pkStrings)->m_usMaxSize;
    if (count >= size)
        ((StrArr*)pkStrings)->SetSize(((StrArr*)pkStrings)->m_usGrowBy + count);
    ((StrArr*)pkStrings)->SetAt(count, pString);
    ((TransformViewerFields*)&m_kDefaultTransform)->GetTransformViewerStrings((StrArr*)pkStrings);
    void* pData = *(void**)((char*)this + 0x2c);
    if (pData)
        ((void(__thiscall*)(void*, StrArr*))(*(void***)pData)[24])(pData, (StrArr*)pkStrings);
}


extern double DAT_010241b0;

// The shared header lacks the channel pose query; reuse its layout and virtual key-count method.
struct TransformChannelPoseQuery : NiTransformInterpolator
{
    bool IsChannelPosed(unsigned short mode);
};

// For modes 0-2, rejects when m_2c is set and v56(mode) > 0, otherwise compares the mode's float field against DAT_010241b0.
// @fnv 0x00a3f720
bool TransformChannelPoseQuery::IsChannelPosed(unsigned short mode)
{
    double value;
    switch (mode)
    {
    case 0:
        if (m_spTransformData.m_pObject != 0 && GetColorKeyCount(mode) > 0)
        {
            return false;
        }
        value = m_kDefaultTransform.x;
        break;
    case 1:
        if (m_spTransformData.m_pObject != 0 && GetColorKeyCount(mode) > 0)
        {
            return false;
        }
        value = m_kDefaultTransform.qy;
        break;
    case 2:
        if (m_spTransformData.m_pObject != 0 && GetColorKeyCount(mode) > 0)
        {
            return false;
        }
        value = m_kDefaultTransform.scale;
        break;
    default:
        return false;
    }
    return DAT_010241b0 != value;
}


// The base registration stub at 0x00aa0ad0 is not declared by the shared base class.
struct InterpolatorRegistrationBase : NiKeyBasedInterpolator
{
    bool RegisterBase(NiStream& stream);
};

// Calls FUN_00aa0ad0(arg); if it succeeds, invokes v21(arg) on unk2c when non-null and returns true, otherwise returns false.
// @fnv 0x00a3f870
bool NiTransformInterpolator::RegisterStreamables(NiStream& stream)
{
    if (!((InterpolatorRegistrationBase*)this)->RegisterBase(stream))
        return false;

    NiTransformData* data = m_spTransformData.m_pObject;
    if (data)
        data->RegisterStreamables(stream);

    return true;
}

// Equality at 0x00a391c0 takes two NiQuatTransforms; its declaration is absent from the shared header.
struct TransformComparison : NiQuatTransform
{
    bool Equals(const NiQuatTransform& kOther) const;
};
template <> inline NiPointer<NiTransformData>::operator NiTransformData*() const
{
    return m_pObject;
}
template <> inline NiTransformData* NiPointer<NiTransformData>::operator->() const
{
    return m_pObject;
}

// The inherited NiObject::IsEqual is a different function; this unit calls the base stub at 0x00c85800.
struct InterpolatorComparisonBase : NiKeyBasedInterpolator
{
    bool BaseIsEqual(NiObject* pkObject) const;
};

// @fnv 0x00a3f8d0
bool NiTransformInterpolator::IsEqual(NiObject* pkObject) const
{
    if (!((const InterpolatorComparisonBase*)this)->BaseIsEqual(pkObject))
        return false;
    NiTransformInterpolator* pkOther = (NiTransformInterpolator*)pkObject;
    if (!((const TransformComparison*)&m_kDefaultTransform)->Equals(pkOther->m_kDefaultTransform))
        return false;
    if ((m_spTransformData && !pkOther->m_spTransformData) || (!m_spTransformData && pkOther->m_spTransformData))
        return false;
    if (m_spTransformData && !m_spTransformData->IsEqual(pkOther->m_spTransformData))
        return false;
    return true;
}

// Transform serialization at 0x00a38b60 is absent from NiQuatTransform's shared declarations.
struct TransformBinaryWriter : NiQuatTransform
{
    void SaveTransform(NiStream& stream);
};

// @fnv 0x00a3f8a0
void NiTransformInterpolator::SaveBinary(NiStream& stream)
{
    NiObject::SaveBinary(stream);
    ((TransformBinaryWriter*)&m_kDefaultTransform)->SaveTransform(stream);
    stream.SaveLinkID(m_spTransformData.m_pObject);
}

#include <string.h>

void __stdcall NiKeyBasedInterpolator_CopyMembers(NiTransformInterpolator* pkDest, CloningProcess* kCloning);

template <> inline NiPointer<NiTransformData>& NiPointer<NiTransformData>::operator=(const NiPointer& rhs)
{
    if (m_pObject != rhs.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = rhs.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// Calls FUN_00aa0ab0, then copies 32 bytes at offset 0x0c plus fields 0x38-0x40, the ref-counted pointer at 0x2c and the shorts at 0x30-0x34 into pkDest.
// @fnv 0x00a40360
void NiTransformInterpolator::CopyMemberData(NiTransformInterpolator* pkDest, CloningProcess& kCloning)
{
    NiKeyBasedInterpolator_CopyMembers(pkDest, &kCloning);

    memcpy(&pkDest->m_kDefaultTransform, &m_kDefaultTransform, 32);

    *(unsigned int*)&pkDest->m_kDefaultTranslation.x = *(unsigned int*)&m_kDefaultTranslation.x;
    *(unsigned int*)&pkDest->m_kDefaultTranslation.y = *(unsigned int*)&m_kDefaultTranslation.y;
    *(unsigned int*)&pkDest->m_kDefaultTranslation.z = *(unsigned int*)&m_kDefaultTranslation.z;
    pkDest->m_spTransformData = m_spTransformData;
    pkDest->m_usLastRotationKeyIndex = m_usLastRotationKeyIndex;
    pkDest->m_usLastPositionKeyIndex = m_usLastPositionKeyIndex;
    pkDest->m_usLastScaleKeyIndex = m_usLastScaleKeyIndex;
}

namespace fnv_00a403f0 {
void* __cdecl Object_DispatchCommandFour(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* address)
{
    return address;
}
// @fnv 0x00a403f0
// src: EXE 0x00a403f0
NiTransformInterpolator* __cdecl NiTransformInterpolator_CreateObject()
{
    void* storage = Object_DispatchCommandFour(sizeof(NiTransformInterpolator));
    if (storage)
        return ::new (storage) NiTransformInterpolator(static_cast<NiTransformData*>(0));
    return 0;
}
}  // namespace fnv_00a403f0

inline bool NiQuatTransform::IsTranslateValid()
{
    return x != -3.4028234663852886e+38;
}
inline bool NiQuatTransform::IsRotateValid()
{
    return qy != -3.4028234663852886e+38;
}
inline bool NiQuatTransform::IsScaleValid()
{
    return scale != -3.4028234663852886e+38;
}
inline bool NiQuatTransform::IsMarkedInvalid()
{
    return !IsScaleValid() && !IsRotateValid() && !IsTranslateValid();
}

// Deserializes the default transform, data object, and pose flag after loading the base class.
// @fnv 0x00a3f7b0
void NiTransformInterpolator::LoadBinary(NiStream& kStream)
{
    NiKeyBasedInterpolator::LoadBinary(kStream);
    m_kDefaultTransform.LoadBinary(kStream);
    m_kDefaultTranslation = *(NiPoint3*)&m_kDefaultTransform.x;
    m_spTransformData = (NiTransformData*)kStream.DeserializeObject();
    m_bPoseValid = !m_spTransformData.m_pObject && !m_kDefaultTransform.IsMarkedInvalid();
}

__declspec(noinline) bool NiPoint3::operator!=(const NiPoint3& p)
{
    return !(x == p.x && y == p.y && z == p.z);
}

struct S00a3ffd0_PosKey : NiAnimationKey
{
    NiPoint3 m_kPositionValue;
    S00a3ffd0_PosKey* GetKeyPointerByIndex(unsigned int ui, unsigned char ucSize)
    {
        return (S00a3ffd0_PosKey*)((char*)this + ui * ucSize);
    }
};
struct S00a3ffd0_RotKey : NiAnimationKey
{
    NiQuaternion m_kRotationValue;
    S00a3ffd0_RotKey* GetKeyPointerByIndex(unsigned int ui, unsigned char ucSize)
    {
        return (S00a3ffd0_RotKey*)((char*)this + ui * ucSize);
    }
};
struct S00a3ffd0_FloatKey : NiAnimationKey
{
    float m_fValue;
    S00a3ffd0_FloatKey* GetKeyPointerByIndex(unsigned int ui, unsigned char ucSize)
    {
        return (S00a3ffd0_FloatKey*)((char*)this + ui * ucSize);
    }
};
inline bool S00a3ffd0_QEq(const NiQuaternion& a, const NiQuaternion& q)
{
    return a.m_fVectorX == q.m_fVectorX && a.m_fVectorY == q.m_fVectorY && a.m_fVectorZ == q.m_fVectorZ &&
           a.m_fScalarPart == q.m_fScalarPart;
}
static inline S00a3ffd0_PosKey* GetTransformPositionKeys(const NiTransformData* data, unsigned int& n, int& t, unsigned char& s)
{
    n = data->m_usNumPosKeys;
    t = data->m_ePositionKeyType;
    s = data->m_ucPositionKeySize;
    return (S00a3ffd0_PosKey*)data->m_pkPositionKeys;
}
static inline S00a3ffd0_RotKey* GetTransformRotationKeys(const NiTransformData* data, unsigned int& n, int& t, unsigned char& s)
{
    n = data->m_usNumRotKeys;
    t = data->m_eRotationKeyType;
    s = data->m_ucRotationKeySize;
    return (S00a3ffd0_RotKey*)data->m_pkRotationKeys;
}
static inline S00a3ffd0_FloatKey* GetTransformScaleKeys(const NiTransformData* data, unsigned int& n, int& t, unsigned char& s)
{
    n = data->m_usNumScaleKeys;
    t = data->m_eScaleKeyType;
    s = data->m_ucScaleKeySize;
    return (S00a3ffd0_FloatKey*)data->m_pkScaleKeyArray;
}
// Evaluates position, rotation, and scale keys to determine if they are constant, updating m_kDefaultTransform and clearing m_spTransformData if all are absent.
// @fnv 0x00a3ffd0
void NiTransformInterpolator::Collapse()
{
    if (!m_spTransformData.m_pObject)
        return;
    NiQuatTransform kTransform;
    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    S00a3ffd0_PosKey* pkPosKeys = GetTransformPositionKeys(m_spTransformData.m_pObject, uiNumKeys, eType, ucSize);
    if (uiNumKeys == 0)
    {
        m_spTransformData.m_pObject->SetPositionKeys(0, 0, NiAnimationKey::NOINTERP);
        if (m_kDefaultTransform.x != -3.4028234663852886e38)
            (*(NiPoint3*)&kTransform.x) = (*(NiPoint3*)&m_kDefaultTransform.x);
    }
    else
    {
        NiPoint3 kValue = pkPosKeys->GetKeyPointerByIndex(0, ucSize)->m_kPositionValue;
        bool positionConstant = false;
        if (uiNumKeys == 1)
        {
            positionConstant = true;
        }
        else if (eType == 1 || eType == 5)
        {
            positionConstant = true;
            for (unsigned int ui = 1; positionConstant && ui < uiNumKeys; ui++)
            {
                if (pkPosKeys->GetKeyPointerByIndex(ui, ucSize)->m_kPositionValue != kValue)
                    positionConstant = false;
            }
        }
        if (positionConstant)
        {
            m_spTransformData.m_pObject->SetPositionKeys(0, 0, NiAnimationKey::NOINTERP);
            (*(NiPoint3*)&kTransform.x) = kValue;
        }
        else if (m_kDefaultTransform.x != -3.4028234663852886e38)
            (*(NiPoint3*)&kTransform.x) = (*(NiPoint3*)&m_kDefaultTransform.x);
    }
    S00a3ffd0_RotKey* pkRotKeys = GetTransformRotationKeys(m_spTransformData.m_pObject, uiNumKeys, eType, ucSize);
    if (uiNumKeys == 0)
    {
        m_spTransformData.m_pObject->SetRotationKeys((TimedRotationKey*)uiNumKeys, uiNumKeys, (NiAnimationKey::KeyType)uiNumKeys);
        if (m_kDefaultTransform.qy != -3.4028234663852886e38)
            CopyTransformRotation(*(NiQuaternion*)&kTransform.qx, *(NiQuaternion*)&m_kDefaultTransform.qx);
    }
    else
    {
        NiQuaternion kValue = pkRotKeys->GetKeyPointerByIndex(0, ucSize)->m_kRotationValue;
        bool rotationConstant;
        try
        {
            if (uiNumKeys == 1 && eType != 4)
                goto constant52;
            if (eType != 1 && eType != 5)
                goto fallback52;
        }
        catch (...)
        {
            throw;
        }
        rotationConstant = true;
        for (unsigned int ui = 1; rotationConstant && ui < uiNumKeys; ui++)
        {
            if (!S00a3ffd0_QEq(pkRotKeys->GetKeyPointerByIndex(ui, ucSize)->m_kRotationValue, kValue))
                rotationConstant = false;
        }
    done52:;
        if (rotationConstant)
        {
        constant52:
            m_spTransformData.m_pObject->SetRotationKeys(0, 0, NiAnimationKey::NOINTERP);
            CopyTransformRotation(*(NiQuaternion*)&kTransform.qx, kValue);
        }
        else
        {
        fallback52:
            if (m_kDefaultTransform.qy != -3.4028234663852886e38)
                CopyTransformRotation(*(NiQuaternion*)&kTransform.qx, *(NiQuaternion*)&m_kDefaultTransform.qx);
        }
    }
    S00a3ffd0_FloatKey* pkScaleKeys = GetTransformScaleKeys(m_spTransformData.m_pObject, uiNumKeys, eType, ucSize);
    if (uiNumKeys == 0)
    {
        m_spTransformData.m_pObject->SetScaleKeys(0, 0, NiAnimationKey::NOINTERP);
        if (m_kDefaultTransform.scale != -3.4028234663852886e38)
            kTransform.scale = m_kDefaultTransform.scale;
    }
    else
    {
        float kValue = pkScaleKeys->GetKeyPointerByIndex(0, ucSize)->m_fValue;
        bool scaleConstant = false;
        if (uiNumKeys == 1)
        {
            scaleConstant = true;
        }
        else if (eType == 1 || eType == 5)
        {
            scaleConstant = true;
            for (unsigned int ui = 1; scaleConstant && ui < uiNumKeys; ui++)
            {
                if (pkScaleKeys->GetKeyPointerByIndex(ui, ucSize)->m_fValue != kValue)
                    scaleConstant = false;
            }
        }
        if (scaleConstant)
        {
            m_spTransformData.m_pObject->SetScaleKeys(0, 0, NiAnimationKey::NOINTERP);
            kTransform.scale = kValue;
        }
        else if (m_kDefaultTransform.scale != -3.4028234663852886e38)
            kTransform.scale = m_kDefaultTransform.scale;
    }
    if (!m_spTransformData.m_pObject->m_usNumPosKeys && !m_spTransformData.m_pObject->m_usNumRotKeys && !m_spTransformData.m_pObject->m_usNumScaleKeys)
        m_spTransformData = 0;
    m_kDefaultTransform = kTransform;
}
