
// src/gamebryo2.2/corelibs/nianimation/nipathcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nipathcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPathController.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPosData.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/StrArr.h"

extern NiRTTI* g_011f3f80;

// @fnv 0x00a49e00
// src: COMMUNITY 0x00a49e00
NiRTTI* __cdecl NiPathController_GetRTTI()
{
    return reinterpret_cast<NiRTTI*>(&g_011f3f80);
}

extern void(__cdecl* DAT_011f3ca8[])(float, NiAnimationKey const*, NiAnimationKey const*, void*);

// Interpolates between two path keys using the key type and stride from NiPosData.
// @fnv 0x00a49e10
void* NiPathController::InvokeIndexedCallback(void* a1, int iIndexA, int iIndexB, float fValue)
{
    NiPosData* pInner = reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject);
    int idx;
    NiAnimationKey const* base;
    unsigned char sz;
    if (pInner)
    {
        idx = pInner->m_eRequestType;
        sz = pInner->m_ucKeyDataSize;
        base = reinterpret_cast<NiAnimationKey const*>(pInner->m_pKeyArray);
    }
    else
    {
        idx = 0;
        base = 0;
        sz = 0;
    }
    DAT_011f3ca8[idx](fValue, (NiAnimationKey const*)((char const*)base + (unsigned)sz * (unsigned)iIndexA),
                      (NiAnimationKey const*)((char const*)base + (unsigned)sz * (unsigned)iIndexB), a1);
    return a1;
}

void __cdecl FUN_00a49d60();
void __cdecl _delete(void*, int);

// Calls FUN_00a49d60, then deletes this with size 100 if flags has bit 1 set, and returns this.
// @fnv 0x00a4a8c0
// Scalar deleting destructor: ECX is this and the unused EDX slot models the original __thiscall ABI.
void* __fastcall DeletePathController(NiPathController* controller, void*, unsigned int flags)
{
    FUN_00a49d60();
    if (flags & 1)
        _delete(controller, 100);
    return controller;
}

void __stdcall FUN_00a6d830(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);

// Appends a string obtained from g_011f3f80 to pkStrings, growing the array by its capacity step when it is full.
// @fnv 0x00a4b2e0
void NiPathController::AppendString(StrArr* pkStrings)
{
    FUN_00a6d830(pkStrings);
    char* pStr = _FUN_00a7d330((const char*)g_011f3f80);
    unsigned int nSize = pkStrings->m_usSize;
    if (nSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(nSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(nSize, pStr);
}

// @fnv 0x00a49c80
void NiPathController::ProcessClone(CloningProcess& kCloning)
{
    NiTimeController::ProcessClone(kCloning);
    NiTimeController* pkPathData = m_pPathObject.m_pObject;
    if (pkPathData)
        pkPathData->ProcessClone(kCloning);
    NiTimeController* pkPctData = m_pPathInterp.m_pObject;
    if (pkPctData)
        pkPctData->ProcessClone(kCloning);
}

// @fnv 0x00a49cc0
bool NiPathController::RegisterStreamables(NiStream& kStream)
{
    if (!NiTimeController::RegisterStreamables(kStream))
        return false;
    NiTimeController* pkPath = m_pPathObject.m_pObject;
    if (pkPath)
        pkPath->RegisterStreamables(kStream);
    NiTimeController* pkPct = m_pPathInterp.m_pObject;
    if (pkPct)
        pkPct->RegisterStreamables(kStream);
    return true;
}

extern float DAT_011a8b40[5];
extern float DAT_011a8b2c[5];

// Sums five weighted samples of GetKeyDerivativeLength at offsets scaled by a3, then multiplies the total by a3.
// @fnv 0x00a4a6a0
// src: XBOX_PDB 0x00a4a6a0
float NiPathController::PathLength(int a1, int a2, float afScale)
{
    float sum = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        float t = DAT_011a8b40[i] * afScale;
        sum += GetKeyDerivativeLength(a1, a2, t) * DAT_011a8b2c[i];
    }
    return sum * afScale;
}

void __stdcall FUN_00a6d730(StrArr*);

inline int WriteStreamComponent(NiBinaryStream* s, void* p, int n)
{
    int v = n;
    return s->m_pfnWrite(s, p, n, reinterpret_cast<unsigned int*>(&v), 1);
}
// @fnv 0x00a4aeb0
void NiPathController::LoadFromStream(NiStream& kStream)
{
    FUN_00a6d730(reinterpret_cast<StrArr*>(&kStream));
    {
        NiBinaryStream* src = kStream.m_pkOstr;
        src->m_uiAbsoluteCurrentPos += WriteStreamComponent(src, &m_usFlags, 2);
    }
    {
        NiBinaryStream* src = kStream.m_pkOstr;
        src->m_uiAbsoluteCurrentPos += WriteStreamComponent(src, &bankDirection, 4);
    }
    {
        NiBinaryStream* src = kStream.m_pkOstr;
        src->m_uiAbsoluteCurrentPos += WriteStreamComponent(src, &bankAngle, 4);
    }
    {
        NiBinaryStream* src = kStream.m_pkOstr;
        src->m_uiAbsoluteCurrentPos += WriteStreamComponent(src, &smoothing, 4);
    }
    {
        NiBinaryStream* src = kStream.m_pkOstr;
        src->m_uiAbsoluteCurrentPos += WriteStreamComponent(src, &axis, 2);
    }
    kStream.SaveLinkID(m_pPathObject.m_pObject);
    kStream.SaveLinkID(m_pPathInterp.m_pObject);
}

void* __cdecl Object_DispatchCommandFour(unsigned int size) throw();
extern int DAT_0109893c;
extern float DAT_01012054;

// Allocates a NiPathController, constructs its base, and initializes its fields; returns null on allocation failure.
// @fnv 0x00a4b270
// src: EXE 0x00a4b270
NiPathController* __cdecl NiPathController_CreateObject() throw()
{
    NiPathController* p = (NiPathController*)Object_DispatchCommandFour(0x64);
    if (p != 0)
    {
        p->NiTimeController::NiTimeController();
        *(void* volatile*)p = (void*)&DAT_0109893c;
        *(int volatile*)&p->m_pPathObject.m_pObject = 0;
        *(int volatile*)&p->m_pPathInterp.m_pObject = 0;
        *(float volatile*)&p->m50 = 0.0f;
        *(float volatile*)&p->m54 = 0.0f;
        *(float volatile*)&p->m5c = 0.0f;
        *(int volatile*)&p->m38 = 0;
        p->m4c = DAT_01012054;
        p->m3c = 0;
        p->m48 = 0;
        p->m58 = 0;
        p->m60 = 1;
        p->m34 = 3;
        return p;
    }
    return 0;
}

void __cdecl NiFree(void* p);
void* __cdecl _NiMalloc_00aa1070(unsigned int size);

// If totalLength is negative, rebuilds the lengths array from segment lengths and caches the total; returns totalLength.
// @fnv 0x00a4a8e0
float NiPathController::GetTotalLength()
{
    if (totalLength < 0.0f)
    {
        unsigned int count = m_pPathObject ? reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject)->m_uiNumKeys : 0;
        NiFree(lengths);
        lengths = (float*)_NiMalloc_00aa1070(count * sizeof(float));
        lengths[0] = 0.0f;
        for (unsigned int i = 0; i < count - 1; i++)
        {
            float fSegment = PathLength(i, i + 1, 1.0f);
            float* p = lengths;
            p[i + 1] = p[i] + fSegment;
        }
        totalLength = lengths[count - 1];
    }
    return totalLength;
}

void __stdcall func_0x00a6d5e0(NiStream* stream);
void __fastcall ReadLinkID(NiStream* stream);
inline void NiBinaryStream::ReadScalar(void* dst, unsigned int n)
{
    unsigned int bytes = n;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, dst, n, &bytes, 1);
}
template <class T> inline void StreamRead(NiStream& stream, T& dst)
{
    NiBinaryStream* reader = stream.m_pkIstr;
    reader->ReadScalar(&dst, sizeof(T));
}

// @fnv 0x00a4acb0
void NiPathController::ReadFromStream(NiStream* stream)
{
    func_0x00a6d5e0(stream);
    unsigned int mode;
    if (stream->m_uiNifFileVersion < 0x0a000102)
    {
        m_34 = stream->m_usNiTimeControllerFlags >> 5;
    }
    else
    {
        StreamRead(*stream, m_34);
    }
    StreamRead(*stream, mode);
    m_60 = mode;
    StreamRead(*stream, m_50);
    StreamRead(*stream, m_54);
    StreamRead(*stream, m_58);
    ReadLinkID(stream);
    ReadLinkID(stream);
}

extern "C" double __cdecl fmod(double, double);
extern "C" double __cdecl fabs(double);
extern double DAT_01032980;
inline float PathRemainder(float x, float y)
{
    return (float)fmod(x, y);
}

// Adjusts time to the unit interval, then finds the path segment and refines its local parameter for that distance.
// @fnv 0x00a4a980
// src: XBOX_PDB 0x00a4a980
void NiPathController::GetPercentLoc_00a4a980(float time, unsigned int* apFirstKey, unsigned int* apSecondKey, float* apLocalParam)
{
    unsigned int count = m_pPathObject ? reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject)->m_uiNumKeys : 0;
    if (time == 0.0f)
    {
        *apFirstKey = 0;
        *apSecondKey = 1;
        *apLocalParam = 0.0f;
        return;
    }
    if (time < 0.0f)
        time = PathRemainder(time, 1.0f) + 1.0f;
    if (time == 1.0f)
    {
        *apFirstKey = count - 2;
        *apSecondKey = count - 1;
        *apLocalParam = 1.0f;
        return;
    }
    if (time > 1.0f)
    {
        volatile float remainder = PathRemainder(time, 1.0f);
        time = remainder;
    }
    float distance = time * totalLength;
    unsigned int i = 0;
    unsigned int uiSecondKey = 1;
    float base = 0.0f;
    float t = 0.0f;
    for (; i < count - 1; ++i, ++uiSecondKey)
    {
        if (lengths[uiSecondKey] >= distance)
        {
            base = distance - lengths[i];
            t = base / (lengths[uiSecondKey] - lengths[i]);
            break;
        }
    }
    int iteration = 0;
    do
    {
        float error = PathLength((int)i, (int)uiSecondKey, t) - base;
        if ((float)fabs(error) <= DAT_01032980)
            break;
        t = t - (double)error / GetKeyDerivativeLength((int)i, (int)uiSecondKey, t);
        ++iteration;
    } while (iteration < 32);
    *apFirstKey = i;
    *apSecondKey = uiSecondKey;
    *apLocalParam = t;
}

struct PathIndices
{
    int first;
    int second;
};

inline void* GetKeyData(const NiPosData* data, unsigned int& count, int& type, unsigned char& size)
{
    count = data->m_uiNumKeys;
    type = data->m_eRequestType;
    size = data->m_ucKeyDataSize;
    return data->m_pKeyArray;
}
inline bool NiPathController::GetFollow() const
{
    return (m_usFlags >> 5) & 1;
}

float __cdecl InterpolateKey(float fTime, void* pkKeys, int eType, unsigned int uiNumKeys, unsigned int& uiLastIdx,
                             unsigned char ucSize);

// Evaluates the percent and path keys at controller time, writes translation to m_pkTarget, and writes rotation when follow is enabled.
// @fnv 0x00a4afa0
void NiPathController::UpdatePathTarget(float* apfTime)
{
    if (!m_pPathInterp)
        return;
    unsigned int uiNumPctKeys;
    int ePctType;
    unsigned char ucPctSize;
    void* pkPctKeys = GetKeyData(reinterpret_cast<NiPosData*>(m_pPathInterp.m_pObject), uiNumPctKeys, ePctType, ucPctSize);
    if (!pkPctKeys || !m_pPathObject)
        return;
    unsigned int uiNumPathKeys;
    int ePathType;
    unsigned char ucPathSize;
    void* pkPathKeys = GetKeyData(reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject), uiNumPathKeys, ePathType, ucPathSize);
    if (!pkPathKeys)
        return;
    if (DontDoUpdate(*apfTime))
        return;

    float fPct = InterpolateKey(m_fControllerTime, pkPctKeys, ePctType, uiNumPctKeys, m_uiPercentKeyCount, ucPathSize);
    {
        PathIndices stIndices;
        GetLoc(fPct, (int*)&stIndices.first, (int*)&stIndices.second, &fPct);
        int i2;
        if ((GetFollow() ? (i2 = stIndices.second, true) : (i2 = stIndices.second, false)))
        {
            NiMatrix3 kRot;
            CalcRefFrame(stIndices.first, i2, fPct, &kRot);
            static_cast<NiAVObject*>(m_pkTarget)->m_kLocal.m_Rotate = kRot;
        }
        NiPoint3 kPos;
        InvokeIndexedCallback(&kPos, stIndices.first, i2, fPct);
        static_cast<NiAVObject*>(m_pkTarget)->m_kLocal.m_Translate = kPos;
    }
}

#include <math.h>
extern void(__cdecl* DAT_011f3c18[])(float, NiAnimationKey const*, NiAnimationKey const*, void*);

// Computes the length of the derivative vector between two animation keys at a given time using a type-specific function pointer.
// @fnv 0x00a4a610
float NiPathController::GetKeyDerivativeLength(unsigned int uiKey1, unsigned int uiKey2, float fTime)
{
    unsigned int uiRequestType;
    unsigned char ucSize;
    NiAnimationKey* pkKeys;
    NiPosData* pkData = reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject);
    if (pkData)
    {
        uiRequestType = pkData->m_eRequestType;
        ucSize = pkData->m_ucKeyDataSize;
        pkKeys = reinterpret_cast<NiAnimationKey*>(pkData->m_pKeyArray);
    }
    else
    {
        uiRequestType = 0;
        pkKeys = 0;
        ucSize = 0;
    }

    NiPoint3 kDeriv;
    DAT_011f3c18[uiRequestType](fTime, (NiAnimationKey*)((char*)pkKeys + uiKey1 * ucSize),
                                (NiAnimationKey*)((char*)pkKeys + uiKey2 * ucSize), &kDeriv);
    float fLengthSquared = kDeriv.x * kDeriv.x + kDeriv.y * kDeriv.y + kDeriv.z * kDeriv.z;
    return (float)sqrt(fLengthSquared);
}

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
__forceinline NiPathController::NiPathController()
{
    m50 = 0.0f;
    m54 = 0.0f;
    m5c = 0.0f;
    m4c = DAT_01012054;
    m38 = 0;
    m3c = 0;
    m60 = 1;
    m58 = 0;
    m48 = 0;
    m34 = 3;
}

// Allocates and initializes a NiPathController, then copies this controller into it.
// @fnv 0x00a4b330
NiPathController* NiPathController::CreatePathObject(int value)
{
    NiPathController* object = (NiPathController*)Object_DispatchCommandFour(0x64);
    NiPathController* result;
    if (object)
    {
        object->NiPathController::NiPathController();
        result = object;
    }
    else
    {
        result = 0;
    }
    CopyMembers_00a4b0b0(result, value);
    return result;
}

#include <string.h>

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

// NiTimeController::IsEqual (0x00a6cc80) is absent from the shared declarations.
extern bool __cdecl TimeControllerIsEqual();

inline bool NiPathController::GetBit(int n) const
{
    return ((m_usFlags >> n) & 1) ? true : false;
}

// Compares this NiPathController with pkObject, checking path, interpolation, part lengths, and various flags and fields for equality.
// @fnv 0x00a4a710
// src: XBOX_PDB 0x00a4a710
bool NiPathController::IsEqual_00a4a710(NiObject* pkObject)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiTimeController*, NiObject*)>(&TimeControllerIsEqual)(this, pkObject))
        return false;

    NiPathController* pkOther = (NiPathController*)pkObject;

    if (!m_pPathObject->IsEqual(pkOther->m_pPathObject))
        return false;
    if (!m_pPathInterp->IsEqual(pkOther->m_pPathInterp))
        return false;

    if (m_pkPartLengths && !pkOther->m_pkPartLengths)
        return false;
    if (!m_pkPartLengths && pkOther->m_pkPartLengths)
        return false;

    if (m_pkPartLengths)
    {
        unsigned int* pkLengths = m_pkPartLengths;
        unsigned int a;
        unsigned int ItemUpdateArray;
        int c;
        unsigned char d;
        GetLengths(&a, &ItemUpdateArray, &c, &d);
        if (memcmp(pkLengths, pkOther->m_pkPartLengths, ItemUpdateArray * sizeof(unsigned int)) != 0)
            return false;
    }

    if (unk4c != pkOther->unk4c || pkOther->GetBit(0) != GetBit(0) || pkOther->GetBit(1) != GetBit(1) ||
        unk60 != pkOther->unk60 || pkOther->GetBit(2) != GetBit(2) || pkOther->GetBit(3) != GetBit(3) ||
        pkOther->GetBit(4) != GetBit(4) || pkOther->GetBit(5) != GetBit(5) || unk50 != pkOther->unk50 ||
        unk54 != pkOther->unk54 || unk58 != pkOther->unk58 || pkOther->GetBit(6) != GetBit(6))
    {
        return false;
    }
    return true;
}

#include <windows.h>

struct SampleData
{
    unsigned int index;
    const void* value;
};

extern float(__cdecl* DAT_011f3d38[])(const void*, unsigned int);

// Links the two key-data objects and updates the cached path length and curvature.
// @fnv 0x00a4adc0
void NiPathController::SetSpawnedArgs(SpawnedArg* apSpawnedArg)
{
    FUN_00a6d500(apSpawnedArg);

    NiPosData* p = static_cast<NiPosData*>(reinterpret_cast<NiStream*>(apSpawnedArg)->FUN_00a63430());
    NiPosData* old = reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject);
    if (old != p)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            {
                old->DeleteThis();
            }
        }
        m_pPathObject.m_pObject = reinterpret_cast<NiTimeController*>(p);
        if (p != 0)
        {
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
        }
    }

    p = static_cast<NiPosData*>(reinterpret_cast<NiStream*>(apSpawnedArg)->FUN_00a63430());
    old = reinterpret_cast<NiPosData*>(m_pPathInterp.m_pObject);
    if (old != p)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            {
                old->DeleteThis();
            }
        }
        m_pPathInterp.m_pObject = reinterpret_cast<NiTimeController*>(p);
        if (p != 0)
        {
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
        }
    }

    unsigned char bit = 1;
    m_34 |= bit;
    unsigned char hi = (unsigned char)(m_34 >> 4);
    if ((hi & bit) != 0 && ((unsigned char)m_34 & bit) != 0)
    {
        m_4c = GetTotalLength();
        m_34 &= ~bit;
    }

    NiPosData* t = reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject);
    if (t != 0)
    {
        unsigned int count = t->m_uiNumKeys;
        SampleData sample = {t->m_eRequestType, t->m_pKeyArray};
        if (count > 0)
        {
            float(__cdecl * pfnSample)(const void*, unsigned int) = DAT_011f3d38[sample.index];
            m_5c = pfnSample(sample.value, count);
        }
    }
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* NiMalloc(unsigned int);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

// NiTimeController::CopyMembers (0x00a6cfe0) has no shared member declaration.
extern void __cdecl CopyTimeController();
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    T* p = pkNew;
    if (m_pObject != p)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}
inline void NiPathController::SetBit(bool b, unsigned short mask)
{
    if (b)
        m_usFlags |= mask;
    else
        m_usFlags &= ~mask;
}
inline void NiPathController::SetConstVelocity(bool b)
{
    SetBit(b, 0x10);
    if (b && GetBit(0))
    {
        m_fTotalPathLength = GetTotalLength();
        m_usFlags &= ~1;
    }
}

// Copies controller state into pDest, cloning the key data and duplicating the path-length array.
// @fnv 0x00a4b0b0
// src: XBOX_PDB 0x00a4b0b0
void NiPathController::CopyMembers_00a4b0b0(NiPathController* pDest, void* kCloning)
{
    reinterpret_cast<void (__thiscall*)(NiTimeController*, NiTimeController*, void*)>(&CopyTimeController)(this, pDest, kCloning);
    pDest->m_uiObjectFlags = m_uiObjectFlags;

    if (m_pPathObject)
        pDest->m_pPathObject = static_cast<NiTimeController*>(m_pPathObject->MakeClone(*static_cast<CloningProcess*>(kCloning)));
    if (m_pPathInterp)
        pDest->m_pPathInterp = static_cast<NiTimeController*>(m_pPathInterp->MakeClone(*static_cast<CloningProcess*>(kCloning)));

    pDest->SetBit(GetBit(2), 4);
    pDest->SetBit(GetBit(3), 8);
    pDest->m60 = m60;
    pDest->SetConstVelocity(GetBit(4));
    pDest->SetBit(GetBit(5), 0x20);
    pDest->m50 = m50;
    pDest->m54 = m54;
    pDest->m58 = m58;
    pDest->SetBit(GetBit(6), 0x40);
    pDest->SetBit(GetBit(1), 2);

    if (m_pfPathLengths)
    {
        unsigned int uiSize = (m_pPathObject ? reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject)->m_uiNumKeys : 0) * sizeof(float);
        pDest->m_pfPathLengths = (float*)NiMalloc(uiSize);
        memcpy(pDest->m_pfPathLengths, m_pfPathLengths, uiSize);
    }
    pDest->m_fTotalPathLength = m_fTotalPathLength;
}

#include <math.h>
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
__declspec(noinline) NiPoint3 NiPoint3::FUN_0053d1a0(const NiPoint3& v) const
{
    NiPoint3 r(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    float len = (float)sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
    if (len != 0.0f) { r.x /= len; r.y /= len; r.z /= len; }
    return r;
}
inline NiPoint3 NiPoint3::operator-() const
{
    NiPoint3 r(-x, -y, -z);
    return r;
}
inline NiPoint3 NiPoint3::InlineCross(const NiPoint3& v) const
{
    NiPoint3 r(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    return r;
}
namespace fnv_00a49e70 {
// Refines the prior NiPathController draft, another contributor (2026-10-23).
extern "C" double __cdecl atan(double);
extern "C" double __cdecl sqrt(double);
NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);

struct PathMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    PathMatrix()
    {}
    PathMatrix(float, float, float, float);
    PathMatrix FUN_0043f8d0(const PathMatrix&) const;
    void Set0(const NiPoint3& v)
    {
        m00 = v.x;
        m10 = v.y;
        m20 = v.z;
    }
    void Set1(const NiPoint3& v)
    {
        m01 = v.x;
        m11 = v.y;
        m21 = v.z;
    }
    void Set2(const NiPoint3& v)
    {
        m02 = v.x;
        m12 = v.y;
        m22 = v.z;
    }
    void Get0(NiPoint3& v) const
    {
        v.x = m00;
        v.y = m10;
        v.z = m20;
    }
    NiPoint3 Get1() const
    {
        NiPoint3 v(m01, m11, m21);
        return v;
    }
    NiPoint3 Get2() const
    {
        NiPoint3 v(m02, m12, m22);
        return v;
    }
};
extern const PathMatrix DAT_011a9448;
extern const NiPoint3 DAT_011a9484;
extern float DAT_01097304;
void __cdecl ComputeFrenetFrame(float, const NiAnimationKey*, const NiAnimationKey*, int, NiPoint3*, NiPoint3*, NiPoint3*,
                                float*);
inline float& GetBankFactor()
{
    static float f = DAT_01097304;
    return f;
}

} // namespace fnv_00a49e70

inline bool NiPathController::IsFollow() const { return (m_usFlags & 4) >> 2; }
inline bool NiPathController::IsReverse() const { return (m_usFlags & 64) >> 6; }
inline bool NiPathController::IsBank() const { return (m_usFlags & 8) >> 3; }
inline bool NiPathController::IsFlag1() const { return (m_usFlags & 2) >> 1; }

// Evaluates the path at time t between keys first and second, applying smoothing, axis, reverse, and bank to produce the output matrix.
// @fnv 0x00a49e70
// src: XBOX_PDB 0x00a49e70
void NiPathController::CalcRefFrame(unsigned aiFirstKey, unsigned aiSecondKey, float afTime, NiMatrix3& outputMatrix)
{
    using namespace fnv_00a49e70;
    PathMatrix& output = reinterpret_cast<PathMatrix&>(outputMatrix);
    NiPosData* data = reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject);
    NiPoint3 vTangent;
    PathMatrix result;
    NiPoint3 position;
    NiPoint3 normal;
    result = DAT_011a9448;
    if (data)
    {
        unsigned count = data->m_uiNumKeys;
        int type = data->m_eRequestType;
        unsigned char size = data->m_ucKeyDataSize;
        const NiAnimationKey* base = reinterpret_cast<NiAnimationKey const*>(data->m_pKeyArray);
        if (count < 2)
        {
            output = result;
            return;
        }

        float curvature, w1;
        if (IsFollow())
        {
            float otherCurvature;
            ComputeFrenetFrame(afTime, (const NiAnimationKey*)((const char*)base + size * aiFirstKey),
                               (const NiAnimationKey*)((const char*)base + size * aiSecondKey), type, &position,
                               &vTangent, &normal, &curvature);
            if (smoothing != 0.0f)
            {
                unsigned adjacent;
                float w0;
                NiPoint3 vScratch, vOther;

                if (afTime >= 1.0f - smoothing)
                {
                    adjacent = !IsFlag1() && aiSecondKey == count - 1 ? 0 : aiSecondKey;
                    if (adjacent < count - 1)
                    {
                        w0 = (1.0f - afTime + smoothing) / (smoothing * 2.0f);
                        w1 = 1.0f - w0;
                        float u = 1.0f - smoothing;
                        ComputeFrenetFrame(u, (const NiAnimationKey*)((const char*)base + size * aiFirstKey),
                                           (const NiAnimationKey*)((const char*)base + size * aiSecondKey), type,
                                           &vScratch, &vTangent, &normal, &curvature);
                        ComputeFrenetFrame(smoothing, (const NiAnimationKey*)((const char*)base + size * adjacent),
                                           (const NiAnimationKey*)((const char*)base + size * (adjacent + 1)), type,
                                           &vScratch, &vOther, &normal, &otherCurvature);
                        vTangent = FUN_004a3760(w0, vTangent) + FUN_004a3760(w1, vOther);
                        vTangent.Unitize_004a0c10();
                        curvature = w1 * otherCurvature + w0 * curvature;
                        normal = position.Cross(vTangent);
                    }
                }
                else if (afTime <= smoothing)
                {
                    adjacent = !IsFlag1() && aiFirstKey == 0 ? count - 1 : aiFirstKey;
                    if (adjacent >= 1)
                    {
                        w1 = (smoothing - afTime) / (smoothing * 2.0f);
                        w0 = 1.0f - w1;
                        ComputeFrenetFrame(smoothing, (const NiAnimationKey*)((const char*)base + size * aiFirstKey),
                                           (const NiAnimationKey*)((const char*)base + size * aiSecondKey), type,
                                           &vScratch, &vTangent, &normal, &curvature);
                        float u = 1.0f - smoothing;
                        ComputeFrenetFrame(u, (const NiAnimationKey*)((const char*)base + size * (adjacent - 1)),
                                           (const NiAnimationKey*)((const char*)base + size * adjacent), type, &vScratch,
                                           &vOther, &normal, &otherCurvature);
                        vTangent = FUN_004a3760(w0, vTangent) + FUN_004a3760(w1, vOther);
                        vTangent.Unitize_004a0c10();
                        curvature = w1 * otherCurvature + w0 * curvature;
                        normal = position.Cross(vTangent);
                    }
                }
            }
            result.Set0(position);
            result.Set1(-vTangent);
            result.Set2(-normal);
        }
        else
        {
            ComputeFrenetFrame(afTime, (const NiAnimationKey*)((const char*)base + size * aiFirstKey),
                               (const NiAnimationKey*)((const char*)base + size * aiSecondKey), type, &position,
                               &vTangent, &normal, &curvature);
            result.Set0(position);
            NiPoint3 vUp = DAT_011a9484.FUN_0053d1a0(position);
            result.Set1(vUp);
            result.Set2(position.InlineCross(vUp));
        }
        if (IsReverse())
        {
            result.Set0(-position);
            result.Set1(-result.Get1());
        }
        NiPoint3 old;
        switch (axis)
        {
        case 1: {
            result.Get0(old);
            result.Set0(-result.Get1());
            result.Set1(old);
            break;
        }
        case 2: {
            result.Get0(old);
            result.Set0(-result.Get2());
            result.Set2(old);
            break;
        }
        }
        if (IsBank())
        {
            NiPoint3 vAxis;
            vAxis = position;
            float& factor = GetBankFactor();
            float angle = bankDirection * bankAngle;
            if (curvature < maxCurvature)
            {
                float ratio = curvature / maxCurvature;
                ratio = (float)atan(ratio);
                angle = ratio * factor * angle;
            }
            PathMatrix bank(angle, vAxis.x, vAxis.y, vAxis.z);
            result = bank.FUN_0043f8d0(result);
        }
    }
    output = result;
}

struct TimeKey
{
    float time;
    float Time() const
    {
        return time;
    }
    TimeKey* At(unsigned int i, unsigned char stride) const
    {
        return (TimeKey*)((char*)this + i * stride);
    }
};
struct PositionKey : TimeKey
{
    PositionKey* At(unsigned int i, unsigned char stride)
    {
        return (PositionKey*)TimeKey::At(i, stride);
    }
};

// Selects two key indices and a fraction for t, using path-distance lookup when follow is enabled.
// @fnv 0x00a4ab50
// src: XBOX_PDB 0x00a4ab50
void NiPathController::GetLoc(float afTime, unsigned int& aiKey0, unsigned int& aiKey1, float& frac)
{
    if (GetBit(4))
    {
        GetPercentLoc_00a4a980(afTime, aiKey0, aiKey1, frac);
        lastIdx = aiKey0;
        return;
    }
    unsigned int n;
    int kind;
    unsigned char sz;
    PositionKey* keys;
    NiPosData* d = reinterpret_cast<NiPosData*>(m_pPathObject.m_pObject);
    if (d)
    {
        keys = (PositionKey*)GetKeyData(d, n, kind, sz);
    }
    else
    {
        n = 0;
        kind = 0;
        keys = 0;
        sz = 0;
    }
    if (afTime <= keys->At(0, sz)->Time())
    {
        aiKey0 = 0;
        aiKey1 = 1;
        frac = 0.0f;
        return;
    }
    if (afTime >= keys->At(n - 1, sz)->Time())
    {
        aiKey0 = n - 2;
        aiKey1 = n - 1;
        frac = 1.0f;
        return;
    }
    bool found = false;
    unsigned int idx = lastIdx;
    bool first = true;
    unsigned int next = 0;
    while (idx < n - 1)
    {
        if (afTime == keys->At(idx, sz)->Time())
        {
            lastIdx = idx;
            next = idx + 1;
            found = true;
            break;
        }
        else if (keys->At(idx, sz)->Time() < afTime && afTime < keys->At(idx + 1, sz)->Time())
        {
            lastIdx = idx;
            next = idx + 1;
            found = true;
            break;
        }
        if (idx == n - 2 && first)
        {
            idx = 0;
            first = false;
        }
        else
        {
            idx++;
        }
    }
    frac = (afTime - keys->At(idx, sz)->Time()) / (keys->At(next, sz)->Time() - keys->At(idx, sz)->Time());
    aiKey0 = idx;
    aiKey1 = next;
}
