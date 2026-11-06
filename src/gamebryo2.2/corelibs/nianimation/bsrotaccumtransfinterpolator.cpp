
// src/gamebryo2.2/corelibs/nianimation/bsrotaccumtransfinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsrotaccumtransfinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BSRotAccumTransfInterpolator.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiTransformData.h"
#include "../../../../include/NiTransformInterpolator.h"
#include <string.h>
#include <windows.h>

extern NiRTTI g_011f3ee0;

// @fnv 0x00a43ab0
NiRTTI* __cdecl FUN_00a43ab0()
{
    return &g_011f3ee0;
}

extern int DAT_01097af4;
extern int DAT_011a9ea8;
extern int DAT_011a9eac;
extern int DAT_011a9eb0;

// Allocates a 0x58-byte BSRotAccumTransfInterpolator, initializes its vtable and quaternion fields from NiQuaternion::IDENTITY and globals, and returns it.
// @fnv 0x00a43e40
BSRotAccumTransfInterpolator* CreateRotAccumTransfInterpolator()
{
    BSRotAccumTransfInterpolator* pInterpolator = (BSRotAccumTransfInterpolator*)BSFadeNode::operator new(0x58);
    if (pInterpolator)
    {
        pInterpolator->NiTransformInterpolator::CopyMemberData(0);
        *(void**)pInterpolator = (void*)&DAT_01097af4;
        *(int*)&pInterpolator->m_kAccumulatedRotation.m_fVectorX = *(int*)&NiQuaternion::IDENTITY;
        *(int*)&pInterpolator->m_kAccumulatedRotation.m_fVectorY = DAT_011a9ea8;
        *(int*)&pInterpolator->m_kAccumulatedRotation.m_fVectorZ = DAT_011a9eac;
        *(int*)&pInterpolator->m_kAccumulatedRotation.m_fScalarPart = DAT_011a9eb0;
        return pInterpolator;
    }
    return 0;
}

extern int DAT_011a9ea4;

void* __cdecl FUN_00aa13e0(unsigned int size);

// @fnv 0x00a43e90
BSRotAccumTransfInterpolator* BSRotAccumTransfInterpolator::CreateInterpolator(int a)
{
    BSRotAccumTransfInterpolator* obj = (BSRotAccumTransfInterpolator*)FUN_00aa13e0(0x58);
    if (obj != 0)
    {
        obj->NiTransformInterpolator::CopyMemberData(0);
        *(void**)obj = (void*)&DAT_01097af4;
        *(int*)&obj->m_kAccumulatedRotation.m_fVectorX = DAT_011a9ea4;
        *(int*)&obj->m_kAccumulatedRotation.m_fVectorY = DAT_011a9ea8;
        *(int*)&obj->m_kAccumulatedRotation.m_fVectorZ = DAT_011a9eac;
        *(int*)&obj->m_kAccumulatedRotation.m_fScalarPart = DAT_011a9eb0;
    }
    else
    {
        obj = 0;
    }
    FUN_00a40360(obj, a);
    memcpy(&obj->m_kAccumulatedRotation, &m_kAccumulatedRotation, sizeof(NiQuaternion));
    return obj;
}

// The shared headers only forward-declare this key type.
struct TimedRotationKey
{
    float m_fTime;
    NiQuaternion m_kRotationValue;
};

inline TimedRotationKey* BSRotAccumTransfInterpolator::GetRotData(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
{
    if (m_spTransformData.m_pObject)
    {
        uiNumKeys = m_spTransformData.m_pObject->m_usNumRotKeys;
        eType = m_spTransformData.m_pObject->m_eRotationKeyType;
        ucSize = m_spTransformData.m_pObject->m_ucRotationKeySize;
        return m_spTransformData.m_pObject->m_pkRotationKeys;
    }
    uiNumKeys = 0;
    eType = 0;
    ucSize = 0;
    return 0;
}

// Calls FUN_00a43330, then copies the first rotation key's quaternion into the accumulated rotation when rotation keys exist.
// @fnv 0x00a43ac0
void BSRotAccumTransfInterpolator::UpdateRotValue(int a)
{
    FUN_00a43330(a);
    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    TimedRotationKey* pkKeys = GetRotData(uiNumKeys, eType, ucSize);
    if (uiNumKeys != 0)
    {
        memcpy(&m_kAccumulatedRotation, &pkKeys[0].m_kRotationValue, sizeof(NiQuaternion));
    }
}

void __cdecl FUN_00a3f7b0();
// @fnv 0x00a43a70
void __cdecl FUN_00a43a70()
{
    FUN_00a3f7b0();
}

extern void __cdecl FUN_00a3f870();

// @fnv 0x00a43a80
void __cdecl FUN_00a43a80()
{
    FUN_00a3f870();
}

void __cdecl FUN_00a3f8a0();
// @fnv 0x00a43a90
void __cdecl FUN_00a43a90()
{
    FUN_00a3f8a0();
}

extern void FUN_00a3f8d0();

// @fnv 0x00a43aa0
void FUN_00a43aa0()
{
    FUN_00a3f8d0();
}

inline NiPoint3& AssignPosition(NiPoint3& target, const NiPoint3& source)
{
    memcpy(&target, &source, sizeof(target));
    return target;
}

// NiQuaternion does not yet declare the quaternion product and matrix conversion
// used here; retain these value adapters until those declarations are shared.
struct QuaternionValue
{
    float x, y, z, w;
    __declspec(noinline) QuaternionValue FUN_00a2bcf0(const QuaternionValue& q) const
    {
        QuaternionValue r;
        r.w = w * q.w - x * q.x - y * q.y - z * q.z;
        r.x = w * q.x + x * q.w + y * q.z - z * q.y;
        r.y = w * q.y + y * q.w + z * q.x - x * q.z;
        r.z = w * q.z + z * q.w + x * q.y - y * q.x;
        return r;
    }
    void FUN_00a38560();
    void FUN_00a6df40(const void*);
};
struct QQuatOps : QuaternionValue
{
    QQuatOps()
    {}
    QQuatOps(const QuaternionValue& r)
    {
        memcpy(this, &r, sizeof(r));
    }
};
struct ConjugateValue : QuaternionValue
{
    ConjugateValue(const ConjugateValue& r)
    {
        memcpy(this, &r, sizeof(*this));
    }
};

inline NiQuatTransform& NiQuatTransform::operator=(const NiQuatTransform& r)
{
    memcpy(this, &r, sizeof(*this));
    return *this;
}

__forceinline bool HasValidTransform(const NiQuatTransform& value)
{
    if (value.scale == -3.4028234663852886e38 && value.qy == -3.4028234663852886e38 &&
        value.x == -3.4028234663852886e38)
        return false;
    return true;
}
ConjugateValue __cdecl FUN_00a6dc00(const QuaternionValue&);
NiPoint3 __cdecl FUN_00a27490(float, void*, int, unsigned int, unsigned int&, unsigned char);
QuaternionValue __cdecl FUN_00a28740(float, void*, int, unsigned int, unsigned int&, unsigned char);
float __cdecl InterpolateKey(float, void*, int, unsigned int, unsigned int&, unsigned char);
void* FUN_00a3f990(unsigned int*, int*, unsigned char*);
void* FUN_0058cb00(unsigned int*, int*, unsigned char*);
void* FUN_00a3f9e0(unsigned int*, int*, unsigned char*);
typedef void* (__thiscall *GetTransformKeys)(NiTransformInterpolator*, unsigned int*, int*, unsigned char*);
// Evaluates position, rotation and scale keys at time, applies rotation delta to object matrix, and stores the result in result.
// @fnv 0x00a43b00
bool BSRotAccumTransfInterpolator::UpdateTransform(float time, NiObjectNET* target, NiQuatTransform& output)
{
    NiAVObject* object = (NiAVObject*)target;
    NiQuatTransform& result = output;
    if (m_bPoseValid)
    {
        m_fLastTime = time;
        result = m_kDefaultTransform;
        return true;
    }
    if (m_fLastTime == time)
    {
        result = m_kDefaultTransform;
        return HasValidTransform(m_kDefaultTransform);
    }
    unsigned int count;
    int type;
    unsigned char stride;
    unsigned int index;
    void* keys = ((GetTransformKeys)FUN_00a3f990)(this, &count, &type, &stride);
    if (count > 0)
    {
        index = m_usLastRotationKeyIndex;
        AssignPosition(*(NiPoint3*)&m_kDefaultTransform.x, FUN_00a27490(time, keys, type, count, index, stride));
        m_usLastRotationKeyIndex = (unsigned short)index;
    }
    keys = ((GetTransformKeys)FUN_0058cb00)(this, &count, &type, &stride);
    if (count > 0)
    {
        index = m_usLastPositionKeyIndex;
        QuaternionValue rotation = FUN_00a28740(time, keys, type, count, index, stride);
        if (object)
        {
            QQuatOps delta = rotation.FUN_00a2bcf0(FUN_00a6dc00((QuaternionValue&)m_kAccumulatedRotation));
            QQuatOps objectRotation;
            objectRotation.FUN_00a6df40(&object->m_kLocal.m_Rotate);
            (QuaternionValue&)objectRotation = objectRotation.FUN_00a2bcf0(delta);
            objectRotation.FUN_00a38560();
            *(QuaternionValue*)&m_kDefaultTransform.qx = objectRotation;
        }
        else
        {
            *(QuaternionValue*)&m_kDefaultTransform.qx = rotation;
        }
        (QuaternionValue&)m_kAccumulatedRotation = rotation;
        m_usLastPositionKeyIndex = (unsigned short)index;
    }
    {
        int scaleType;
        keys = ((GetTransformKeys)FUN_00a3f9e0)(this, &count, &scaleType, &stride);
        if (count > 0)
        {
            index = m_usLastScaleKeyIndex;
            m_kDefaultTransform.scale = InterpolateKey(time, keys, scaleType, count, index, stride);
            m_usLastScaleKeyIndex = (unsigned short)index;
        }
    }
    result = m_kDefaultTransform;
    if (!HasValidTransform(m_kDefaultTransform))
        return false;
    m_fLastTime = time;
    return true;
}


void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

// Decrements the referenced object's count and calls DeleteThis at zero, then calls BaseCleanup and FUN_00aa1460 when bit 0 is set.
// @fnv 0x00a43df0
BSRotAccumTransfInterpolator* BSRotAccumTransfInterpolator::FUN_00a43df0(unsigned char acFlags)
{
    *(volatile int*)this = (int)&DAT_01097af4;
    NiRefObject* pCounted = *(NiRefObject* volatile*)&m_spTransformData.m_pObject;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->m_uiRefCount) == 0)
        {
            pCounted->DeleteThis();
        }
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x58);
    }
    return this;
}
