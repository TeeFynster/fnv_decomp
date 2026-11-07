// gamebryo2.2/corelibs/nianimation/nicolorinterpolator.cpp: NiColorInterpolator (17 functions)

#include "../../../../include/NiColorData.h"
#include "../../../../include/NiColorInterpolator.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorA.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }

extern const NiColorA DAT_011a9430;

class ColorAnimationKey : public NiAnimationKey
{
  public:
    NiColorA m_kRgbaColor;
    static NiColorA InterpolatePosition(float, ColorAnimationKey*, KeyType, unsigned int, unsigned int&,
                                         unsigned char);
};
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

// @fnv 0x00a3bfb0
bool NiColorInterpolator::Update(float fTime, NiObjectNET*, NiColorA& kValue)
{
    if (m_fLastTime == fTime)
    {
        kValue = m_kColorValue;
        if (m_kColorValue.operator==(DAT_011a9430))
            return false;
        return true;
    }

    if (m_spColorData.m_pObject)
    {
        unsigned int uiNumKeys = m_spColorData.m_pObject->m_uiNumKeys;
        NiAnimationKey::KeyType eType = m_spColorData.m_pObject->m_eRequestType;
        unsigned char ucKeySize = m_spColorData.m_pObject->m_ucKeyDataSize;
        ColorAnimationKey* pkKeys = m_spColorData.m_pObject->m_pKeyArray;
        if (uiNumKeys > 0)
            m_kColorValue =
                ColorAnimationKey::InterpolatePosition(fTime, pkKeys, eType, uiNumKeys, m_uiLastKeyIndex, ucKeySize);
    }

    if (m_kColorValue.operator==(DAT_011a9430))
        return false;
    kValue = m_kColorValue;
    m_fLastTime = fTime;
    return true;
}

namespace fnv_00a3bd10 {
extern int DAT_01096e14;
extern NiColorA const DAT_011a9430;
extern int DAT_011a9434;
extern int DAT_011a9438;
extern int DAT_011a943c;


// @fnv 0x00a3bd10
NiColorInterpolator* __fastcall NiColorInterpolatorConstructor(NiColorInterpolator* pThis, int, void* pkColorData)
{
    reinterpret_cast<NiKeyBasedInterpolator*>(pThis)->NiKeyBasedInterpolator::NiKeyBasedInterpolator();
    *reinterpret_cast<int**>(pThis) = &DAT_01096e14;
    *reinterpret_cast<NiColorA*>(reinterpret_cast<char*>(pThis) + 0x0c) = DAT_011a9430;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(pThis) + 0x1c) = pkColorData;
    if (pkColorData)
    {
        InterlockedIncrement(reinterpret_cast<long*>(reinterpret_cast<char*>(pkColorData) + 4));
    }
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pThis) + 0x20) = 0;
    return pThis;
}
}  // namespace fnv_00a3bd10

extern "C" void* g_011f3730;

// @fnv 0x00a3bd70
const NiRTTI* NiColorInterpolator::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_011f3730);
}

// @fnv 0x00a487f0
NiAnimationKey* NiColorInterpolator::GetChannelKeys(unsigned short) const
{
    void* ptr = *(void**)((char*)this + 0x1c);
    if (!ptr)
        return 0;
    return *(NiAnimationKey**)((char*)ptr + 0xc);
}

// Clears m_spColorData and stores the given color value in m_kColorValue.
// @fnv 0x00a3bc60
void NiColorInterpolator::SetColorValue(NiColorA akColorValue)
{
    m_spColorData = 0;
    m_kColorValue = akColorValue;
}

struct ColorDataTimeRange
{
    void SetActiveTimeRange(float, float);
};
// If m_spColorData is set, forwards the two float arguments to its FUN_00a3d0e0 method.
// @fnv 0x00a3bcb0
void NiColorInterpolator::SetActiveTimeRange(float afArg1, float afArg2)
{
    if ((NiColorData*)m_spColorData)
        ((ColorDataTimeRange*)(NiColorData*)m_spColorData)->SetActiveTimeRange(afArg1, afArg2);
}

struct InterpolatorSaveBase
{
    void SaveBinary(NiStream*);
};
// @fnv 0x00a3bce0
void NiColorInterpolator::SaveBinary(NiStream& kStream)
{
    ((InterpolatorSaveBase*)this)->SaveBinary(&kStream);
    m_kColorValue.SaveBinary(kStream);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spColorData.m_pObject));
}

extern int DAT_01096e14;
extern int DAT_011a9434;
extern int DAT_011a9438;
extern int DAT_011a943c;
// @fnv 0x00a3c130
// src: EXE 0x00a3c130
NiColorInterpolator* NiColorInterpolator_CreateObject()
{
    NiColorInterpolator* p = (NiColorInterpolator*)NiColorInterpolator::operator new(0x24);
    if (p)
    {
        p->NiKeyBasedInterpolator::NiKeyBasedInterpolator();
        *(unsigned int*)p = (unsigned int)&DAT_01096e14;
        *(unsigned int*)((char*)p + 0xc) = *(unsigned int*)&DAT_011a9430;
        *(unsigned int*)((char*)p + 0x10) = DAT_011a9434;
        *(unsigned int*)((char*)p + 0x14) = DAT_011a9438;
        *(unsigned int*)((char*)p + 0x18) = DAT_011a943c;
        *(unsigned int*)((char*)p + 0x1c) = 0;
        *(unsigned int*)((char*)p + 0x20) = 0;
    }
    else
    {
        p = 0;
    }
    return p;
}

// Loads the base interpolator and color value from the stream, then stores the stream's next object as the color data pointer.
// @fnv 0x00a48990
void NiColorInterpolator::LoadBinary(NiStream& kStream)
{
    NiKeyBasedInterpolator::LoadBinary(kStream);
    m_kColorValue.LoadBinary(kStream);
    m_spColorData = (NiColorData*)kStream.DeserializeObject();
}

struct InterpolatorRegisterBase
{
    bool RegisterStreamables(NiStream*);
};
// @fnv 0x00a489f0
bool NiColorInterpolator::RegisterStreamables(NiStream& kStream)
{
    if (!((InterpolatorRegisterBase*)this)->RegisterStreamables(&kStream))
        return false;
    NiColorData* pkColorData = m_spColorData.m_pObject;
    if (pkColorData)
        pkColorData->RegisterStreamables(kStream);
    return true;
}


// Initializes a color interpolator from the four RGBA bit patterns.
// @fnv 0x00a3bd80
NiColorInterpolator* __fastcall ConstructColorValue(NiColorInterpolator* pThis, int,
    unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
    pThis->NiKeyBasedInterpolator::NiKeyBasedInterpolator();
    *(volatile unsigned int*)&pThis->m_kColorValue.r = r;
    *(volatile unsigned int*)&pThis->m_kColorValue.g = g;
    *(volatile unsigned int*)&pThis->m_kColorValue.b = b;
    *(volatile unsigned int*)&pThis->m_kColorValue.a = a;
    *(volatile unsigned int*)pThis = (unsigned int)&DAT_01096e14;
    *(NiColorData* volatile*)&pThis->m_spColorData.m_pObject = 0;
    *(volatile unsigned int*)&pThis->m_uiLastKeyIndex = 0;
    return pThis;
}

inline ColorAnimationKey* ComputePositionAtTime(NiColorData* d, unsigned int& n, NiAnimationKey::KeyType& t,
                                                unsigned char& s)
{
    n = d->m_uiNumKeys;
    t = d->m_eRequestType;
    s = d->m_ucKeyDataSize;
    return d->m_pKeyArray;
}

// If the color data has zero or one key, or all keys are equal for linear/step interpolation, clears m_spColorData and stores the single color value.
// @fnv 0x00a3bdc0
void NiColorInterpolator::Collapse()
{
    if (m_spColorData)
    {
        unsigned int uiNumKeys;
        NiAnimationKey::KeyType eType;
        unsigned char ucKeySize;
        ColorAnimationKey* pkKeys = ComputePositionAtTime(m_spColorData, uiNumKeys, eType, ucKeySize);
        if (uiNumKeys == 0)
        {
            m_spColorData = 0;
            m_kColorValue = DAT_011a9430;
        }
        else
        {
            NiColorA kValue = pkKeys->m_kRgbaColor;
            if (uiNumKeys != 1)
            {
                bool bAllEqual = false;
                if (eType == NiAnimationKey::LINKEY || eType == NiAnimationKey::STEPKEY)
                {
                    bAllEqual = true;
                    for (unsigned int uiIndex = 1; bAllEqual && uiIndex < uiNumKeys; uiIndex++)
                    {
                        ColorAnimationKey* pkKey = (ColorAnimationKey*)((char*)pkKeys + uiIndex * ucKeySize);
                        if (pkKey->m_kRgbaColor.operator!=(kValue))
                            bAllEqual = false;
                    }
                }
                if (!bAllEqual)
                    return;
            }
            m_spColorData = 0;
            m_kColorValue = kValue;
        }
    }
}

struct InterpolatorTimeRangeClone
{
    NiColorInterpolator* CloneForTimeRange(float startTime, float endTime);
};
struct ColorDataTimeRangeClone
{
    void BuildAndSetData(float startTime, float endTime, NiColorData** clippedData);
};
// Creates a color interpolator for the given time range and, if color data exists, clips it and assigns the clipped data to the new interpolator.
// @fnv 0x00a3bef0
NiInterpolator* NiColorInterpolator::CloneForTimeRange(float startTime, float endTime)
{
    NiColorInterpolator* interpolator = reinterpret_cast<InterpolatorTimeRangeClone*>(this)->CloneForTimeRange(startTime, endTime);
    if (m_spColorData.m_pObject)
    {
        NiColorData* clippedData = 0;
        reinterpret_cast<ColorDataTimeRangeClone*>(m_spColorData.m_pObject)
            ->BuildAndSetData(startTime, endTime, &clippedData);
        interpolator->m_spColorData = clippedData;
        interpolator->m_uiLastKeyIndex = 0;
        if (clippedData)
            clippedData->DecRefCount();
    }
    return interpolator;
}

struct ColorInterpolatorCopyBase
{
    void CopyMembers(NiObject*, CloningProcess&);
};
// @fnv 0x00a3c0a0
void __fastcall CopyColorMembers(NiColorInterpolator* pThis, int, NiColorInterpolator* apDest, void* proc)
{
    ((ColorInterpolatorCopyBase*)pThis)->CopyMembers(apDest, *(CloningProcess*)proc);
    unsigned int* d4 = (unsigned int*)&apDest->m_kColorValue;
    unsigned int* s4 = (unsigned int*)&pThis->m_kColorValue;
    d4[0] = s4[0];
    d4[1] = s4[1];
    d4[2] = s4[2];
    d4[3] = s4[3];
    apDest->m_spColorData = pThis->m_spColorData;
    apDest->m_uiLastKeyIndex = pThis->m_uiLastKeyIndex;
}

struct ViewerArray
{
    void* m_pBase;
    unsigned int m_unk04;
    unsigned short m_usMax;
    unsigned short m_usNext;
    unsigned short m_unk0c;
    unsigned short m_usGrow;
    void FUN_0096ad30(unsigned int newSize);
    void FUN_0096ae90(unsigned int index, void* elem);
};

void* NiViewerStrings_NiGetViewerString_Title(void* arg);
void* NiGetViewerString_00a7d5a0(const char* name, unsigned int value);

struct InterpolatorViewerBase
{
    void GetViewerStrings(ViewerArray*);
};

// @fnv 0x00a3c270
void NiColorInterpolator::GetViewerStrings(NiViewerStringsArray* strings)
{
    ViewerArray* out = reinterpret_cast<ViewerArray*>(strings);
    ((InterpolatorViewerBase*)this)->GetViewerStrings(out);
    void* pValue = NiViewerStrings_NiGetViewerString_Title(g_011f3730);
    unsigned int uiIndex = out->m_usNext;
    if (uiIndex >= out->m_usMax)
    {
        out->FUN_0096ad30(uiIndex + out->m_usGrow);
    }
    out->FUN_0096ae90(uiIndex, &pValue);

    void* r = m_kColorValue.GetViewerString("m_kColorValue");
    uiIndex = out->m_usNext;
    unsigned int uiMax = out->m_usMax;
    pValue = r;
    if (uiIndex >= uiMax)
    {
        out->FUN_0096ad30(uiIndex + out->m_usGrow);
    }
    out->FUN_0096ae90(uiIndex, &pValue);

    unsigned int v = reinterpret_cast<unsigned int>(m_spColorData.m_pObject);
    void* s = NiGetViewerString_00a7d5a0("m_spColorData", v);
    uiIndex = out->m_usNext;
    uiMax = out->m_usMax;
    pValue = s;
    if (uiIndex >= uiMax)
    {
        out->FUN_0096ad30(uiIndex + out->m_usGrow);
    }
    out->FUN_0096ae90(uiIndex, &pValue);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
inline NiColorInterpolator::NiColorInterpolator(NiColorData* data) throw()
    : m_kColorValue(DAT_011a9430), m_spColorData(data), m_uiLastKeyIndex(0)
{}
struct ColorInterpolatorCloneSource
{
    void CopyMembers(NiColorInterpolator*, int);
    NiColorInterpolator* CreateColorInterpolator(int);
};
// Allocates a NiColorInterpolator with null color data, initializes it via FUN_00a3c0a0 with arg, and returns it.
// @fnv 0x00a3c1f0
NiColorInterpolator* ColorInterpolatorCloneSource::CreateColorInterpolator(int arg)
{
    void* memory = Object_DispatchCommandFour(sizeof(NiColorInterpolator));
    NiColorInterpolator* interpolator = memory ? ::new (memory) NiColorInterpolator(0) : 0;
    CopyMembers(interpolator, arg);
    return interpolator;
}

// The shared interpolator does not yet declare its nonvirtual base comparison.
struct InterpolatorComparisonBase
{
    bool IsEqual(NiObject*);
};

// Returns false when the base check, color check, or color-data check fails.
// @fnv 0x00a3c190
bool NiColorInterpolator::IsEqual(NiObject* pkObject) const
{
    if (!((InterpolatorComparisonBase*)this)->IsEqual(pkObject))
        return false;

    NiColorInterpolator* pkDest = (NiColorInterpolator*)pkObject;
    if (m_kColorValue.operator!=(pkDest->m_kColorValue))
        return false;

    if ((m_spColorData && !pkDest->m_spColorData) || (!m_spColorData && pkDest->m_spColorData) ||
        (m_spColorData && !static_cast<const NiColorData*>(m_spColorData.operator->())->IsEqual(pkDest->m_spColorData)))
        return false;

    return true;
}
