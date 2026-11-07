#include "../../../../include/NiPathInterpolator.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPosData.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/nipathinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nipathinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f68;

// @fnv 0x00a3dab0
// src: COMMUNITY 0x00a3dab0
void* __cdecl NiPosData_GetRTTI()
{
    return &g_011f3f68;
}

// Returns the pointer stored at offset 8 of the object at this+0x18 for idx 0 or this+0x1c for idx 1, or null if absent.
// @fnv 0x00a3dae0
// src: GAMEBRYO_LIB 0x00a3dae0
void* __thiscall NiPathInterpolator::GetKeyCount(short idx)
{
    if (idx == 0)
    {
        void* p = m_pPathObject;
        if (p)
            return *(void**)((char*)p + 8);
    }
    else if (idx == 1)
    {
        void* p = m_pPathInterp;
        if (p)
            return *(void**)((char*)p + 8);
    }
    return 0;
}

// Returns the int at offset 0x10 of the pointer stored at this+0x18 for arg 0 or this+0x1c for arg 1, or 0 if that pointer is null or arg is other.
// @fnv 0x00a3db10
int __thiscall NiPathInterpolator::GetValueByIndex(short aiIndex)
{
    if (aiIndex == 0)
    {
        int* p = (int*)m_pPathObject;
        if (p)
            return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(p) + 0x10);
    }
    else if (aiIndex == 1)
    {
        int* p = (int*)m_pPathInterp;
        if (p)
            return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(p) + 0x10);
    }
    return 0;
}

// Returns the int at offset 0xC of the object stored at this+0x18 when arg is 0, or at this+0x1C when arg is 1; otherwise returns 0.
// @fnv 0x00a3db40
// src: GAMEBRYO_LIB 0x00a3db40
int __thiscall NiPathInterpolator::GetKeyArray(short aiSlot)
{
    if (aiSlot == 0)
    {
        int* p = (int*)m_pPathObject;
        if (p)
            return *(p + 3);
    }
    else if (aiSlot == 1)
    {
        int* p = (int*)m_pPathInterp;
        if (p)
            return *(p + 3);
    }
    return 0;
}

// Returns byte at offset 0x14 of the object stored at this+0x18 for arg 0 or this+0x1c for arg 1, otherwise 0.
// @fnv 0x00a3db70
// src: GAMEBRYO_LIB 0x00a3db70
char __thiscall NiPathInterpolator::GetKeyStride(unsigned short ausIndex)
{
    if (ausIndex == 0)
    {
        void* p = m_pPathObject;
        if (p)
            return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(p) + 0x14);
    }
    else if (ausIndex == 1)
    {
        void* p = m_pPathInterp;
        if (p)
            return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(p) + 0x14);
    }
    return 0;
}

extern "C" void* g_011f3e48;

// @fnv 0x00a3dde0
const NiRTTI* NiPathInterpolator::GetRTTI() const
{
    return (const NiRTTI*)&g_011f3e48;
}

// NiFloatData.h lacks the time-range method; this bridge declares only that call.
struct FloatDataHelper
{
    void __thiscall FUN_00a3cc40(float m_fStartTime, float m_fMaximumDistance);
};

// Forwards the two float arguments to the FloatDataHelper stored at offset 0x1c, if that pointer is non-null.
// @fnv 0x00a3dc50
// src: XBOX_PDB 0x00a3dc50
void __thiscall NiPathInterpolator::GuaranteeTimeRange_00a3dc50(float m_fStartTime, float m_fMaximumDistance)
{
    FloatDataHelper* p = (FloatDataHelper*)m_pPathInterp;
    if (p)
    {
        p->FUN_00a3cc40(m_fStartTime, m_fMaximumDistance);
    }
}

// Maps channel 0 to 1, channel 1 to 0, and any other channel to 6.
// @fnv 0x00a3da80
int NiPathInterpolator::GetChannelIndex(unsigned short usChannel)
{
    if (usChannel == 0)
        return 1;
    return usChannel == 1 ? 0 : 6;
}

extern "C" void __cdecl FUN_00a48fb0();
extern "C" void __cdecl _delete(void*, unsigned int);

struct FUN_00a3dac0_shell
{
    void* __thiscall DestroyIfOdd(short idx);
};

// Calls FUN_00a48fb0, then deletes this with size 24 when idx has bit 0 set, and returns this.
// @fnv 0x00a3dac0
void* __thiscall FUN_00a3dac0_shell::DestroyIfOdd(short idx)
{
    FUN_00a48fb0();
    if (idx & 1)
        _delete(this, 24);
    return this;
}

extern void* DAT_011f3ca8[];
// Reads a type index, element size and base pointer from this+0x18, then calls the DAT_011f3ca8 entry for that type with two element pointers and pData.
// @fnv 0x00a3ddf0
// src: GAMEBRYO_LIB 0x00a3ddf0
void* NiPathInterpolator::GenPathInterp(void* pData, int aiIndexA, int aiIndexB, float fTime)
{
    char* pcElementBase = 0;
    int iType;
    unsigned char ucSize;
    void* pkObj = m_pPathObject;
    if (pkObj)
    {
        iType = *(int*)((char*)pkObj + 0x10);
        ucSize = *(unsigned char*)((char*)pkObj + 0x14);
        pcElementBase = *(char**)((char*)pkObj + 0xC);
    }
    else
    {
        iType = 0;
        ucSize = 0;
    }
    ((void(__cdecl*)(float, void const*, void const*, void*))DAT_011f3ca8[iType])(
        fTime, pcElementBase + ucSize * aiIndexA, pcElementBase + ucSize * aiIndexB, pData);
    return pData;
}

// @fnv 0x00a3e980 is the compiler-generated scalar deleting destructor.

struct FUN_00a3cbf0_shell
{
    void __thiscall FUN_00a3cbf0(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
extern const char* _g_011f3e48;

// Appends the string returned by _FUN_00a7d330(_g_011f3e48) to pkStrings, growing the array if the size limit is reached.
// @fnv 0x00a3f4d0
void __thiscall NiPathInterpolator::AppendString(StrArr* pkStrings)
{
    ((FUN_00a3cbf0_shell*)this)->FUN_00a3cbf0(pkStrings);
    char* pcString = _FUN_00a7d330(_g_011f3e48);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}

class CloningProcess
{
  public:
    void* m_pCloneMap;
};

// Calls ProcessClone on this object and on the path and percentage objects if they are set.
// @fnv 0x00a3dc80
// src: XBOX_PDB 0x00a3dc80
void __thiscall NiPathInterpolator::ProcessClone_00a3dc80(CloningProcess& kCloning)
{
    ((NiObject*)this)->NiObject::ProcessClone(kCloning);
    NiObject* pkPath = m_pPathObject;
    if (pkPath)
        pkPath->ProcessClone(kCloning);
    NiObject* pkPct = (NiObject*)m_pPathInterp;
    if (pkPct)
        pkPct->ProcessClone(kCloning);
}

struct HC1Base
{
    bool __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(void*);
};

// @fnv 0x00a3dcc0
// src: XBOX_PDB 0x00a3dcc0
bool NiPathInterpolator::RegisterStreamables_00a3dcc0(void* pkStream)
{
    if (!((HC1Base*)this)->BSPackedAdditionalGeometryData_RegisterStreamables(pkStream))
        return false;
    NiObject* pPath = m_pPathObject;
    if (pPath)
        pPath->RegisterStreamables(*(NiStream*)pkStream);
    NiObject* pPct = (NiObject*)m_pPathInterp;
    if (pPct)
        pPct->RegisterStreamables(*(NiStream*)pkStream);
    return true;
}

inline void* operator new(unsigned int, void* p) { return p; }

// @fnv 0x00a3f4b0
void* __cdecl CreateA51BF0Base()
{
    void* p = NiObject::operator new(0x5c);
    if (p)
        return ::new (p) NiPathInterpolator(0, 0);
    return 0;
}

extern float DAT_01097170;
extern float DAT_01015f5c;
extern double DAT_010231b0;
extern double DAT_010241b0;

// NiKeyBasedInterpolator's key-access overloads are not shared yet.
struct KeyDataAccess
{
    float* FUN_00a3ca80(int index, int mode);
    float* FUN_00a3ca80(int index);
};

// @fnv 0x00a3dba0
void __thiscall NiPathInterpolator::GetRange(float* pfMin, float* pfMax)
{
    *pfMin = DAT_01097170;
    *pfMax = DAT_01015f5c;

    unsigned int count = ((unsigned int (__thiscall*)(NiPathInterpolator*, unsigned int))(*(void***)this)[56])(this, 1);

    if (count > 0)
    {
        float* first = ((KeyDataAccess*)this)->FUN_00a3ca80(0, 1);
        unsigned int index = ((unsigned int (__thiscall*)(NiPathInterpolator*, unsigned int, unsigned int))(*(void***)this)[56])(this, 1, 1) - 1;
        float* last = ((KeyDataAccess*)this)->FUN_00a3ca80(index);

        if (first != 0 && last != 0)
        {
            if (*first < *pfMin)
                *pfMin = *first;

            if (*last > *pfMax)
                *pfMax = *last;
        }
    }

    if ((double)*pfMin == DAT_010231b0 && (double)*pfMax == DAT_010241b0)
    {
        *pfMin = 0.0f;
        *pfMax = 0.0f;
    }
}

__forceinline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *(NiBinaryStream**)((char*)this + 0x24c);
}
__forceinline WriteStream* NiStream::GetWriter()
{
    return *(WriteStream**)((char*)this + 0x250);
}

struct Stream
{
    unsigned int flags, bytesRead;
    int(__cdecl* readProc)(Stream*, void*, unsigned int, unsigned int*, int);
    __forceinline int Read(void* dst, unsigned int count)
    {
        unsigned int actual = count;
        return readProc(this, dst, count, &actual, 1);
    }
};
void __stdcall NiKeyBasedInterpolator_LoadBinary(NiStream*);

// Reads channel, value38, value28, value2c and channel30 from the source's stream, accumulating bytesRead, then calls FUN_00a645b0 twice.
// @fnv 0x00a3ed90
void NiPathInterpolator::ReadFromStream(NiStream* source)
{
    NiKeyBasedInterpolator_LoadBinary(source);
    Stream* stream = (Stream*)source->GetBinaryStream();
    stream->bytesRead += stream->Read(&m_uiObjectFlags, 2);
    unsigned int value;
    stream = (Stream*)source->GetBinaryStream();
    stream->bytesRead += stream->Read(&value, 4);
    m_iPathPointCount = value;
    stream = (Stream*)source->GetBinaryStream();
    stream->bytesRead += stream->Read(&m_fPreviousTime, 4);
    stream = (Stream*)source->GetBinaryStream();
    stream->bytesRead += stream->Read(&m_fLastPercent, 4);
    stream = (Stream*)source->GetBinaryStream();
    stream->bytesRead += stream->Read(&m_sLastPathIndex, 2);
    source->ResetStreamState();
    source->ResetStreamState();
}

struct FNV_WriteStream;
typedef int(__cdecl* FNV_WriteFn)(FNV_WriteStream* stream, void* data, int size, int* written, int flag);

struct FNV_WriteStream
{
    int unk00;
    int m_uiItemCount;
    void* unk08;
    FNV_WriteFn m_pfn;
};

struct StreamBase { void NiKeyBasedInterpolator_LinkObject(NiStream*); void NiKeyBasedInterpolator_LinkObject(NiStream&); };

// The single write the record layout performs: hand the payload and its size
// to the stream's callback and accumulate the byte count it returns.
static __forceinline void FNV_WriteField(FNV_WriteStream* pWriter, void* pData, int nSize)
{
    int n = nSize;
    int r = pWriter->m_pfn(pWriter, pData, n, &n, 1);
    pWriter->m_uiItemCount += r;
}

// Writes unk0c, unk38, unk28, unk2c and unk30 to the stream's writer, then calls f12 with unk18 and unk1c after FUN_00a95ca0.
// @fnv 0x00a3ef70
void NiPathInterpolator::WriteToStream(NiStream* pStream)
{
    ((StreamBase*)this)->NiKeyBasedInterpolator_LinkObject(pStream);
    FNV_WriteField((FNV_WriteStream*)pStream->GetWriter(), &m_uiObjectFlags, 2);
    FNV_WriteField((FNV_WriteStream*)pStream->GetWriter(), &m_iPathPointCount, 4);
    FNV_WriteField((FNV_WriteStream*)pStream->GetWriter(), &m_fPreviousTime, 4);
    FNV_WriteField((FNV_WriteStream*)pStream->GetWriter(), &m_fLastPercent, 4);
    FNV_WriteField((FNV_WriteStream*)pStream->GetWriter(), &m_sLastPathIndex, 2);
    pStream->SaveLinkID(reinterpret_cast<const NiObject*>(m_pPathObject));
    pStream->SaveLinkID(reinterpret_cast<const NiObject*>(m_pPathInterp));
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long* p);
__declspec(dllimport) long __stdcall InterlockedDecrement(long* p);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl NiMalloc(unsigned int);

__forceinline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> __forceinline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> __forceinline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}
template <class T> __forceinline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

struct NiInterpolatorBase
{
    void CopyMemberData(NiInterpolatorBase* pDest, CloningProcess& kCloning);
};

// Preserve the ownership operations of the pointer fields represented as raw pointers in the shared layout.
template <class T> static __forceinline NiPointer<NiPosData>& NiPathPointer(T*& value)
{
    return (NiPointer<NiPosData>&)value;
}
template <class T> static __forceinline void IncrementPathPointer(T* value) throw()
{
    if (value)
        value->IncRefCount();
}
template <class T, class U> static __forceinline void AssignPathPointer(T*& slot, U* value)
{
    if (slot != value)
    {
        if (slot) ((NiObject*)slot)->DecRefCount();
        slot = (T*)value;
        if (slot) ((NiObject*)slot)->IncRefCount();
    }
}
inline void NiPathInterpolator::SetBit(bool value, unsigned short mask)
{
    if (value) m_uiObjectFlags |= mask;
    else m_uiObjectFlags &= ~mask;
}
inline bool NiPathInterpolator::GetBit(unsigned short mask) const { return (m_uiObjectFlags & mask) != 0; }
inline unsigned short NiPathInterpolator::GetField(unsigned short mask, unsigned short pos) const { return (m_uiObjectFlags & mask) >> pos; }
inline bool NiPathInterpolator::GetConstVelocity() const { return (GetField(0x10, 4) & 1) != 0; }
inline bool NiPathInterpolator::GetCVDataNeedsUpdate() const { return GetBit(1); }
inline void NiPathInterpolator::SetCVDataNeedsUpdate(bool value) { SetBit(value, 1); }
inline bool NiPathInterpolator::GetFollow() const { return (bool)GetField(0x20, 5); }
inline bool NiPathInterpolator::TimeHasChanged(float time) const { return m_fLastTime != time; }
inline void NiPathInterpolator::SetConstVelocity(bool b)
{
    SetBit(b, 0x10);
    if (b && GetBit(1)) { m_fTotalPathLength = CalcTotalLength(); SetBit(false, 1); }
}
inline PositionKeyInterpolator* NiPathInterpolator::GetPathKeys(unsigned int& count, unsigned int& type, unsigned char& stride) const
{
    NiPosData* data = m_pPathObject;
    if (data) { count = data->m_uiNumKeys; type = data->m_eRequestType; stride = data->m_ucKeyDataSize; return (PositionKeyInterpolator*)data->m_pKeyArray; }
    count = 0; type = 0; stride = 0; return 0;
}

// @fnv 0x00a3f2f0
// src: XBOX_PDB 0x00a3f2f0
void NiPathInterpolator::CopyMembers_00a3f2f0(NiPathInterpolator* pDest, CloningProcess& kCloning)
{
    ((NiInterpolatorBase*)this)->CopyMemberData((NiInterpolatorBase*)pDest, kCloning);
    pDest->m_uiObjectFlags = m_uiObjectFlags;
    if (NiPathPointer(m_pPathObject))
        NiPathPointer(pDest->m_pPathObject) = (NiPosData*)NiPathPointer(m_pPathObject)->MakeClone(kCloning);
    if (NiPathPointer(m_pPathInterp))
        NiPathPointer(pDest->m_pPathInterp) = (NiPosData*)NiPathPointer(m_pPathInterp)->MakeClone(kCloning);
    pDest->SetBit(GetBit(4), 4);
    pDest->SetBit(GetBit(8), 8);
    pDest->m_iPathPointCount = m_iPathPointCount;
    pDest->SetConstVelocity(GetBit(0x10));
    pDest->SetBit(GetBit(0x20), 0x20);
    pDest->m_fPreviousTime = m_fPreviousTime;
    pDest->m_fLastPercent = m_fLastPercent;
    pDest->m_sLastPathIndex = m_sLastPathIndex;
    pDest->SetBit(GetBit(0x40), 0x40);
    pDest->SetBit(GetBit(2), 2);
    if (m_pfPathLengths)
    {
        unsigned int uiNumKeys = m_pPathObject ? m_pPathObject->m_uiNumKeys : 0;
        unsigned int uiSize = uiNumKeys * sizeof(float);
        pDest->m_pfPathLengths = (float*)NiMalloc(uiSize);
        memcpy(pDest->m_pfPathLengths, m_pfPathLengths, uiSize);
    }
    pDest->m_fTotalPathLength = m_fTotalPathLength;
}

// @fnv 0x00a3f520
NiObject* NiPathInterpolator::MakeClone(CloningProcess& kCloning)
{
    void* memory = NiObject::operator new(sizeof(NiPathInterpolator));
    NiPathInterpolator* pkClone = memory ? ::new (memory) NiPathInterpolator(0, 0) : 0;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

struct MyPosKey
{
    float m_fTime;
};

static __forceinline MyPosKey* GetKey(MyPosKey* pkKeys, unsigned int uiIndex, unsigned char ucKeySize)
{
    return (MyPosKey*)((const char*)pkKeys + uiIndex * ucKeySize);
}

// @fnv 0x00a3ec30
void NiPathInterpolator::FindKeyPair(float fTime, unsigned int& ruiKey0, unsigned int& ruiKey1, float& rfNormTime)
{
    if (GetBit(0x10))
    {
        GetPercentLoc(fTime, ruiKey0, ruiKey1, rfNormTime);
        unk10 = ruiKey0;
        return;
    }

    NiPosData* pkPathData = (NiPosData*)m_pPathObject;
    unsigned int uiNumKeys;
    unsigned char ucKeySize;
    MyPosKey* pkKeys = 0;
    if (pkPathData)
    {
        uiNumKeys = pkPathData->m_uiNumKeys;
        ucKeySize = pkPathData->m_ucKeyDataSize;
        pkKeys = (MyPosKey*)pkPathData->m_pKeyArray;
    }
    else
    {
        uiNumKeys = 0;
        ucKeySize = 0;
    }

    if (fTime <= pkKeys->m_fTime)
    {
        ruiKey0 = 0;
        ruiKey1 = 1;
        rfNormTime = 0.0f;
        return;
    }

    MyPosKey* pkLastKey = GetKey(pkKeys, uiNumKeys - 1, ucKeySize);
    if (fTime >= pkLastKey->m_fTime)
    {
        ruiKey0 = uiNumKeys - 2;
        ruiKey1 = uiNumKeys - 1;
        rfNormTime = 1.0f;
        return;
    }

    unsigned int uiKey = unk10;
    unsigned int uiNextKey = 0;
    bool m_bIsBest = true;
    while (uiKey < uiNumKeys - 1)
    {
        if (fTime == GetKey(pkKeys, uiKey, ucKeySize)->m_fTime)
        {
            unk10 = uiKey;
            uiNextKey = uiKey + 1;
            break;
        }

        MyPosKey* pkKey = GetKey(pkKeys, uiKey, ucKeySize);
        if (pkKey->m_fTime < fTime && GetKey(pkKeys, uiKey + 1, ucKeySize)->m_fTime > fTime)
        {
            unk10 = uiKey;
            uiNextKey = uiKey + 1;
            break;
        }

        if (uiKey == uiNumKeys - 2 && m_bIsBest)
        {
            uiKey = 0;
            m_bIsBest = false;
        }
        else
        {
            uiKey++;
        }
    }

    MyPosKey* pkKey0 = GetKey(pkKeys, uiKey, ucKeySize);
    MyPosKey* pkKey1 = GetKey(pkKeys, uiNextKey, ucKeySize);
    rfNormTime = (fTime - pkKey0->m_fTime) / (pkKey1->m_fTime - pkKey0->m_fTime);
    ruiKey0 = uiKey;
    ruiKey1 = uiNextKey;
}

static const float kNegMax = -3.402823466e+38f;
extern const NiPoint3 DAT_011a9424;
extern NiQuaternion DAT_011f4208;

// @fnv 0x00a3f060
__declspec(noinline) NiPathInterpolator::NiPathInterpolator(NiPosData* pkPathData, NiFloatData* pkPctData)
    : m_pPathObject(pkPathData),
      m_pPathInterp((IncrementPathPointer(m_pPathObject), pkPctData)),
      m_kRotationMatrix((IncrementPathPointer((NiFloatData*)m_pPathInterp), DAT_011f4208)),
      m_kPathOffset()
{
    memcpy(&m_kPathOffset, &DAT_011a9424, sizeof(m_kPathOffset));
    m_fPreviousTime = 0.0f;
    m_fLastPercent = 0.0f;
    m_fPathLength = 0.0f;
    m_fTotalPathLength = -1.0f;
    m_fLast = kNegMax;
    m_uiPathKeyCount = 0;
    m_uiPercentKeyCount = 0;
    m_iPathPointCount = 1;
    m_sLastPathIndex = 0;
    m_pfPathLengths = 0;
    m_uiObjectFlags = 3;
}

#include <math.h>
extern double DAT_01032980;

// Normalizes fTime to [0,1], locates the path key segment containing the target distance, and refines the local parameter via Newton iteration.
// @fnv 0x00a3ea60
// src: GAMEBRYO_LIB 0x00a3ea60
void NiPathInterpolator::GetPercentLoc(float fTime, unsigned int& ri1, unsigned int& ri2, float& rfLocalTime)
{
    unsigned int uiNumKeys = m_pPathObject ? m_pPathObject->m_uiNumKeys : 0;
    if (fTime == 0.0f)
    {
        ri1 = 0;
        ri2 = 1;
        rfLocalTime = 0.0f;
        return;
    }
    if (fTime < 0.0f)
        fTime = (float)fmod(fTime, 1.0f) + 1.0f;
    if (fTime == 1.0f)
    {
        ri1 = uiNumKeys - 2;
        ri2 = uiNumKeys - 1;
        rfLocalTime = 1.0f;
        return;
    }
    if (fTime > 1.0f)
        fTime = (float)fmod(fTime, 1.0f);

    float fTargetDistance = fTime * m_fTotalPathLength;
    float fAccumulatedDistance = 0.0f;
    float fLocalTime = 0.0f;
    unsigned int i1 = 0, i2 = 1;
    for (; i1 < uiNumKeys - 1; i1++, i2++)
    {
        if (fTargetDistance <= m_pfPathLengths[i2])
        {
            fAccumulatedDistance = fTargetDistance - m_pfPathLengths[i1];
            fLocalTime = fAccumulatedDistance / (m_pfPathLengths[i2] - m_pfPathLengths[i1]);
            break;
        }
    }
    for (int it = 0; it < 32; it++)
    {
        float fError = NiPathInterpolator_PathLength(i1, i2, fLocalTime) - fAccumulatedDistance;
        if ((float)fabs(fError) <= DAT_01032980)
            break;
        fLocalTime = (float)(fLocalTime - fError / SampleLength(i1, i2, fLocalTime));
    }
    ri1 = i1;
    ri2 = i2;
    rfLocalTime = fLocalTime;
}

struct AnimInfo
{
    unsigned int count;
    int type;
    MyPosKey* keys;
};
static __forceinline AnimInfo ComputePositionAtTime(const NiPosData* data)
{
    AnimInfo info;
    info.count = data->m_uiNumKeys;
    info.type = data->m_eRequestType;
    info.keys = (MyPosKey*)data->m_pKeyArray;
    return info;
}
typedef float (*CurvatureFunction)(MyPosKey*, unsigned int);
extern CurvatureFunction DAT_011f3d38[];

// Reads path data from a stream, updates constant-velocity state, and computes curvature from the path object's position keys.
// @fnv 0x00a3ee80
// src: GAMEBRYO_LIB 0x00a3ee80
void NiPathInterpolator::LinkObject_00a3ee80(NiStream& stream)
{
    ((StreamBase*)this)->NiKeyBasedInterpolator_LinkObject(stream);
    AssignPathPointer(m_pPathObject, (NiPosData*)stream.GetLoadedObject());
    AssignPathPointer(m_pPathInterp, stream.GetLoadedObject());
    SetCVDataNeedsUpdate(true);
    if (GetConstVelocity() && GetCVDataNeedsUpdate())
    {
        m_fTotalPathLength = GetAccumulatedValue();
        SetCVDataNeedsUpdate(false);
    }
    if (m_pPathObject)
    {
        AnimInfo info = ComputePositionAtTime((NiPosData*)(NiPosData*)m_pPathObject);
        unsigned int count = info.count;
        int type = info.type;
        MyPosKey* keys = info.keys;
        if (count > 0)
        {
            CurvatureFunction curvature = DAT_011f3d38[type];
            *(float*)&unk34 = curvature(keys, count);
        }
    }
}

static const float kInvalidValue = -3.4028234663852886e+38F;
inline bool PointEquals(const NiPoint3& a, const NiPoint3& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

inline void NiQuatTransform::GetTransformScale(void* value)
{
    *reinterpret_cast<NiPoint3*>(&x) = *static_cast<const NiPoint3*>(value);
}

__forceinline void NiQuatTransform::SetLocalRotation(void* value)
{
    memcpy(&qx, value, sizeof(NiQuaternion));
}

inline void NiQuatTransform::MakeInvalid()
{
    scale = qy = x = kInvalidValue;
}

float InterpolateKey(float fTime, void* pkKeys, int eType, unsigned int uiNumKeys, unsigned int& uiLastIdx,
                     unsigned char ucSize);

// The shared declaration lacks the original no-alias call annotation.
struct PathKeySearch
{
    __declspec(noalias) void FindKeyPair(float, int&, int&, float&);
};

// Computes the path position and optional rotation at fTime, writes them into kValue, and returns whether the transform was updated.
// @fnv 0x00a3f120
bool NiPathInterpolator::UpdateTransform(float fTime, NiObjectNET* pkTarget, NiQuatTransform& arValue)

{
    NiQuatTransform& kValue = arValue;
    if (!TimeHasChanged(fTime))
    {
        if (PointEquals(m_kPathOffset, DAT_011a9424))
        {
            kValue.MakeInvalid();
            return false;
        }
        kValue.GetTransformScale(&m_kPathOffset);
        if (GetFollow())
            kValue.SetLocalRotation(&m_kRotationMatrix);
        return true;
    }

    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    void* pkKeys = 0;
    if (m_pPathInterp)
        {
        uiNumKeys = ((NiFloatData*)m_pPathInterp)->m_uiNumKeys;
        eType = ((NiFloatData*)m_pPathInterp)->m_eRequestType;
        ucSize = ((NiFloatData*)m_pPathInterp)->m_ucKeyDataSize;
        pkKeys = ((NiFloatData*)m_pPathInterp)->m_pKeyArray;
    }
    if (!pkKeys)
        return false;
    void* pkPathKeys = 0;
    if (m_pPathObject)
        pkPathKeys = m_pPathObject->m_pKeyArray;
    if (!pkPathKeys)
        return false;
    float fPct = InterpolateKey(fTime, pkKeys, eType, uiNumKeys, m_uiPercentKeyCount, ucSize);

    int iI1, iI2;
    ((PathKeySearch*)this)->FindKeyPair(fPct, iI1, iI2, fPct);

    if (GetFollow())
    {
        NiMatrix3 kRot;
        EvaluateBasis(iI1, iI2, fPct, kRot);
        m_kRotationMatrix.FromRotationMatrix(kRot);
    }

    m_kPathOffset = GenPathInterp(iI1, iI2, fPct);

    kValue.GetTransformScale(&m_kPathOffset);
    if (GetFollow())
        kValue.SetLocalRotation(&m_kRotationMatrix);

    m_fZValue = fTime;
    return true;
}

#include <string.h>
template <class T> static __forceinline NiPointer<NiObject>& EqualityPointer(T*& value)
{
    return (NiPointer<NiObject>&)value;
}

// Compares base equality, path objects and interpolator, path lengths, total length, point count, flags, and timing state.
// @fnv 0x00a3e7b0
// src: XBOX_PDB 0x00a3e7b0
bool NiPathInterpolator::IsEqual_00a3e7b0(NiObject* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;

    NiPathInterpolator* pkPath = (NiPathInterpolator*)pkObject;

    if ((EqualityPointer(m_pPathObject) && !EqualityPointer(pkPath->m_pPathObject)) || (!EqualityPointer(m_pPathObject) && EqualityPointer(pkPath->m_pPathObject)) ||
        (EqualityPointer(m_pPathObject) && !EqualityPointer(m_pPathObject)->IsEqual(EqualityPointer(pkPath->m_pPathObject))))
        return false;

    if ((EqualityPointer(m_pPathInterp) && !EqualityPointer(pkPath->m_pPathInterp)) || (!EqualityPointer(m_pPathInterp) && EqualityPointer(pkPath->m_pPathInterp)) ||
        (EqualityPointer(m_pPathInterp) && !EqualityPointer(m_pPathInterp)->IsEqual(EqualityPointer(pkPath->m_pPathInterp))))
        return false;

    int uiNumKeys;
    int eType;
    char ucSize;
    float* pfPartialLength = m_pfPathLengths;
    if ((m_pfPathLengths && !pkPath->m_pfPathLengths) || (!m_pfPathLengths && pkPath->m_pfPathLengths) ||
        (m_pfPathLengths && (GetPathKeys(uiNumKeys, eType, ucSize),
                             memcmp(pfPartialLength, pkPath->m_pfPathLengths, uiNumKeys * sizeof(float)) != 0)))
        return false;

    if (m_fTotalPathLength != pkPath->m_fTotalPathLength || GetBit(1) != pkPath->GetBit(1) ||
        GetBit(2) != pkPath->GetBit(2) || m_iPathPointCount != pkPath->m_iPathPointCount ||
        GetBit(4) != pkPath->GetBit(4) || GetBit(8) != pkPath->GetBit(8) || GetBit(16) != pkPath->GetBit(16) ||
        GetBit(32) != pkPath->GetBit(32) || m_fPreviousTime != pkPath->m_fPreviousTime ||
        m_fLastPercent != pkPath->m_fLastPercent || m_sLastPathIndex != pkPath->m_sLastPathIndex ||
        GetBit(64) != pkPath->GetBit(64))
        return false;

    return true;
}

inline void NiMatrix3::SetCol(unsigned int column, const NiPoint3& point)
{
    (&m_pEntry[0][0])[column] = point.x;
    (&m_pEntry[1][0])[column] = point.y;
    (&m_pEntry[2][0])[column] = point.z;
}

inline void NiMatrix3::GetCol(unsigned int column, NiPoint3& point) const
{
    point.x = (&m_pEntry[0][0])[column];
    point.y = (&m_pEntry[1][0])[column];
    point.z = (&m_pEntry[2][0])[column];
}

#include <math.h>
namespace fnv_00a3de50 {
struct FV3
{
    float x, y, z;
    FV3()
    {}
    FV3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    FV3 operator-() const
    {
        FV3 v;
        v.x = -x;
        v.y = -y;
        v.z = -z;
        return v;
    }
    void __thiscall Unitize_004a0c10();
    FV3 __thiscall FUN_004b3800(const FV3&) const;
    FV3 __thiscall FUN_00439e90(const FV3&) const;
};
struct PathBasis
{
    float x, y, z;
    FV3 __thiscall FUN_0053d1a0(const FV3&) const;
};
struct PathBlend
{
    FV3* __thiscall FUN_00439e90(FV3*, const FV3*);
};
extern char DAT_011a9448;
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern PathBasis DAT_011a9484;
extern float DAT_011f3e40;
extern unsigned int DAT_011f3e44;
extern float DAT_01097304;
extern unsigned int g_pathBankFactorInitialized;
extern float g_pathBankFactor;
extern "C" double __cdecl atan(double);
extern void __cdecl ComputeFrenetFrame(float, MyPosKey*, MyPosKey*, unsigned int, FV3*, FV3*, FV3*, float*);
extern FV3 __cdecl FUN_004a3760(float, const FV3&);

extern "C" double __cdecl sqrt(double);
extern double DAT_01017cf8;
__declspec(noinline) FV3 PathBasis::FUN_0053d1a0(const FV3& v) const
{
    FV3 cross(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    float length = float(sqrt(cross.x * cross.x + cross.y * cross.y + cross.z * cross.z));
    if (length > DAT_01017cf8)
    {
        float inv = 1.0f / length;
        return FV3(cross.x * inv, cross.y * inv, cross.z * inv);
    }
    return FV3(0.0f, 0.0f, 0.0f);
}

// Computes the path basis matrix at a given time by interpolating position, tangent, and curvature, applying m_fLastPercent, axis, and bank adjustments.
// @fnv 0x00a3de50
}  // namespace fnv_00a3de50
using namespace fnv_00a3de50;

void __thiscall NiPathInterpolator::EvaluateBasis(unsigned int aiFirstKey, unsigned int aiSecondKey, float time, NiMatrix3* apOut)
{
    NiMatrix3* out = apOut;
    NiMatrix3 transform;
    ::memcpy(&transform, &DAT_011a9448, 36);
    unsigned int count, type;
    unsigned char stride;
    MyPosKey* pKeys = (MyPosKey*)GetPathKeys(count, type, stride);
    if (count < 2)
    {
        *out = transform;
        return;
    }
    {
        FV3 vPosition, vTangent, normal;
        float curvature, otherCurvature;
        if (GetBit(4))
        {
            ComputeFrenetFrame(time, GetKey(pKeys, aiFirstKey, stride), GetKey(pKeys, aiSecondKey, stride), type,
                               &vPosition, &vTangent, &normal, &curvature);
            if (m_fLastPercent != 0.0f)
            {
                float firstWeight, secondWeight;
                unsigned int index;
                if (time >= 1.0f - m_fLastPercent)
                {
                    if (!GetBit(2) && aiSecondKey == count - 1)
                        index = 0;
                    else
                        index = aiSecondKey;
                    if (index < count - 1)
                    {
                        FV3 vOtherPos, vOtherTangent;
                        firstWeight = (m_fLastPercent + (1.0f - time)) / (2.0f * m_fLastPercent);
                        secondWeight = 1.0f - firstWeight;
                        ComputeFrenetFrame(1.0f - m_fLastPercent, GetKey(pKeys, aiFirstKey, stride),
                                           GetKey(pKeys, aiSecondKey, stride), type, &vOtherPos, &vTangent, &normal,
                                           &curvature);
                        ComputeFrenetFrame(m_fLastPercent, GetKey(pKeys, index, stride), GetKey(pKeys, index + 1, stride),
                                           type, &vOtherPos, &vOtherTangent, &normal, &otherCurvature);
                        vTangent =
                            FUN_004a3760(firstWeight, vTangent).FUN_00439e90(FUN_004a3760(secondWeight, vOtherTangent));
                        vTangent.Unitize_004a0c10();
                        curvature = firstWeight * curvature + secondWeight * otherCurvature;
                        normal = vPosition.FUN_004b3800(vTangent);
                    }
                }
                else if (time <= m_fLastPercent)
                {
                    if (!GetBit(2) && aiFirstKey == 0)
                        index = count - 1;
                    else
                        index = aiFirstKey;
                    if (index >= 1)
                    {
                        FV3 vOtherPos, vOtherTangent;
                        secondWeight = (m_fLastPercent - time) / (2.0f * m_fLastPercent);
                        firstWeight = 1.0f - secondWeight;
                        ComputeFrenetFrame(m_fLastPercent, GetKey(pKeys, aiFirstKey, stride),
                                           GetKey(pKeys, aiSecondKey, stride), type, &vOtherPos, &vTangent, &normal,
                                           &curvature);
                        ComputeFrenetFrame(1.0f - m_fLastPercent, GetKey(pKeys, index - 1, stride),
                                           GetKey(pKeys, index, stride), type, &vOtherPos, &vOtherTangent, &normal,
                                           &otherCurvature);
                        vTangent =
                            FUN_004a3760(firstWeight, vTangent).FUN_00439e90(FUN_004a3760(secondWeight, vOtherTangent));
                        vTangent.Unitize_004a0c10();
                        curvature = firstWeight * curvature + secondWeight * otherCurvature;
                        normal = vPosition.FUN_004b3800(vTangent);
                    }
                }
            }
            transform.SetCol(0, (const NiPoint3&)vPosition);
            transform.SetCol(1, (const NiPoint3&)-vTangent);
            transform.SetCol(2, (const NiPoint3&)-normal);
        }
        else
        {
            ComputeFrenetFrame(time, GetKey(pKeys, aiFirstKey, stride), GetKey(pKeys, aiSecondKey, stride), type,
                               &vPosition, &vTangent, &normal, &curvature);
            transform.SetCol(0, (const NiPoint3&)vPosition);
            FV3 vBasis = DAT_011a9484.FUN_0053d1a0(vPosition);
            transform.SetCol(1, (const NiPoint3&)vBasis);
            FV3 vBinormal;
            float fCrossPosY = vPosition.y;
            float fCrossPosX = vPosition.x;
            float fCrossBasisX = vBasis.x;
            vBinormal.x = fCrossPosY * vBasis.z - vPosition.z * vBasis.y;
            vBinormal.y = fCrossBasisX * vPosition.z - fCrossPosX * vBasis.z;
            vBinormal.z = vBasis.y * fCrossPosX - fCrossBasisX * fCrossPosY;
            transform.SetCol(2, (const NiPoint3&)vBinormal);
        }
        if (GetBit(64))
        {
            FV3 vCol;
            static_cast<const NiMatrix3&>(transform).GetCol(0, (NiPoint3&)vCol);
            transform.SetCol(0, (const NiPoint3&)-vCol);
            static_cast<const NiMatrix3&>(transform).GetCol(1, (NiPoint3&)vCol);
            transform.SetCol(1, (const NiPoint3&)-vCol);
        }
        FV3 vOld;
        switch (m_sLastPathIndex)
        {
        case 1: {
            FV3 vCol;
            static_cast<const NiMatrix3&>(transform).GetCol(0, (NiPoint3&)vOld);
            static_cast<const NiMatrix3&>(transform).GetCol(1, (NiPoint3&)vCol);
            transform.SetCol(0, (const NiPoint3&)-vCol);
            transform.SetCol(1, (const NiPoint3&)vOld);
            break;
        }
        case 2: {
            FV3 vCol;
            static_cast<const NiMatrix3&>(transform).GetCol(0, (NiPoint3&)vOld);
            static_cast<const NiMatrix3&>(transform).GetCol(2, (NiPoint3&)vCol);
            transform.SetCol(0, (const NiPoint3&)-vCol);
            transform.SetCol(2, (const NiPoint3&)vOld);
            break;
        }
        }
        if (GetBit(8))
        {
            if (!(g_pathBankFactorInitialized & 1))
            {
                g_pathBankFactorInitialized |= 1;
                g_pathBankFactor = DAT_01097304;
            }
            otherCurvature = float(m_iPathPointCount) * m_fPreviousTime;
            if (curvature < m_fPathLength)
            {
                float ratio = curvature / m_fPathLength;
                otherCurvature *= g_pathBankFactor * float(atan(ratio));
            }
            NiMatrix3 rotation;
            rotation.MakeRotation(otherCurvature, vPosition.x, vPosition.y, vPosition.z);
            transform = static_cast<const NiMatrix3&>(rotation).operator*(transform);
        }
    }
    *out = transform;
}
