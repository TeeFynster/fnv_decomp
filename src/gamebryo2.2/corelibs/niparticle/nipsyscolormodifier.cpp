// gamebryo2.2/corelibs/niparticle/nipsyscolormodifier.cpp: NiPSysColorModifier (10 functions)

#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorData.h"
#include "../../../../include/StrArr.h"

#include "NiPSysColorModifier.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer(T* pObject)
{
    m_pObject = pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

// @fnv 0x00C2CF90
void NiPSysColorModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    kStream.ResetStreamState();
}

extern "C" void* g_01202778;

// @fnv 0x00c2d170
// src: COMMUNITY 0x00c2d170
void* __cdecl NiPSysColorModifier_GetRTTI()
{
    return &g_01202778;
}

// @fnv 0x00c2d0d0
bool NiPSysColorModifier::IsEqual(NiObject* pkObject) const
{
    NiPSysColorModifier* pkDest;
    const NiColorData* pSrc;
    NiColorData* pDst;
    if (!NiPSysModifier::IsEqual(pkObject))
        return false;
    pkDest = (NiPSysColorModifier*)pkObject;
    pSrc = m_spColorData.m_pObject;
    pDst = pkDest->m_spColorData.m_pObject;
    // The original caller normalizes the byte returned by virtual IsEqual.
    void** vtable = *reinterpret_cast<void***>(const_cast<NiColorData*>(pSrc));
    typedef unsigned char (__thiscall *IsEqualFunction)(const NiColorData*, NiObject*);
    return reinterpret_cast<IsEqualFunction>(vtable[23])(pSrc, pDst);
}

// The shared base does not declare its out-of-line destructor entry.
void DestroyPSysModifier();
void __cdecl _delete(void*, unsigned int);
// Scalar deleting-destructor ABI entry: releases color data, destroys the base, then optionally frees the object.
// @fnv 0x00c2d1f0
void* __fastcall DestroyColorModifier(NiPSysColorModifier* pkModifier, void*, unsigned int auiFlags)
{
    NiObject* pkColorData = *reinterpret_cast<NiObject**>(reinterpret_cast<char*>(pkModifier) + 0x18);
    if (pkColorData)
        pkColorData->DecRefCount();
    typedef void (__thiscall *DestroyModifierFunction)(NiPSysModifier*);
    reinterpret_cast<DestroyModifierFunction>(DestroyPSysModifier)(pkModifier);
    if (auiFlags & 1)
        _delete(pkModifier, 0x24);
    return pkModifier;
}

// @fnv 0x00c2d1c0
void NiPSysColorModifier::LinkObject(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
    SetColorData(static_cast<NiColorData*>(kStream.FUN_00a63430()));
}

char* _FUN_00a7d330(void*);

// The shared base does not declare its viewer-string override.
void GetPSysModifierViewerStrings();

extern void* _g_01202778;

// @fnv 0x00c2d2a0
void NiPSysColorModifier::GetViewerStrings(NiViewerStringsArray* pkViewerStrings)
{
    StrArr* pkStrings = reinterpret_cast<StrArr*>(pkViewerStrings);
    typedef void (__thiscall *GetViewerStringsFunction)(NiPSysModifier*, StrArr*);
    reinterpret_cast<GetViewerStringsFunction>(GetPSysModifierViewerStrings)(this, pkStrings);
    char* str = _FUN_00a7d330(_g_01202778);
    unsigned int idx = pkStrings->m_usSize;
    unsigned int size = pkStrings->m_usMaxSize;
    if (idx >= size)
    {
        unsigned int grow = pkStrings->m_usGrowBy;
        pkStrings->SetSize(grow + idx);
    }
    pkStrings->SetAt(idx, str);
    NiObject* obj = m_spColorData.m_pObject;
    void** vt = *(void***)obj;
    void(__thiscall * fn)(NiObject*, StrArr*) = (void(__thiscall*)(NiObject*, StrArr*))vt[0x60 / 4];
    fn(obj, pkStrings);
}

// Replaces the stored color data with pkColorData, updating reference counts and recomputing the low and high key times from its key times.
// @fnv 0x00c2d100
void NiPSysColorModifier::SetColorData(NiColorData* pkColorData)
{
    if (m_spColorData.m_pObject != pkColorData)
    {
        NiColorData* pOldColorData = m_spColorData.m_pObject;
        if (pOldColorData != 0)
        {
            pOldColorData->DecRefCount();
        }

        m_spColorData.m_pObject = pkColorData;
        if (pkColorData != 0)
        {
            pkColorData->IncRefCount();
        }
    }

    m_fLoKeyTime = 0.0f;
    m_fHiKeyTime = 0.0f;

    NiColorData* pColorData = m_spColorData.m_pObject;
    if (pColorData != 0)
    {
        unsigned int uiNumKeys = pColorData->m_uiNumKeys;
        unsigned char ucKeyStride = pColorData->m_ucKeyDataSize;
        char* pKeyTimeArray = reinterpret_cast<char*>(pColorData->m_pKeyArray);
        if (uiNumKeys != 0)
        {
            m_fLoKeyTime = *(float*)pKeyTimeArray;
            unsigned int uiLastKeyOffset = (uiNumKeys - 1) * ucKeyStride;
            m_fHiKeyTime = *(float*)(pKeyTimeArray + uiLastKeyOffset);
        }
    }
}

// @fnv 0x00c2d240
NiObject* NiPSysColorModifier::MakeClone(CloningProcess& kCloning)
{
    void* pObject = new NiPSysColorModifier;
    CopyMemberData(static_cast<NiPSysModifier*>(static_cast<NiPSysColorModifier*>(pObject)),
                   kCloning);
    NiColorData* tmp = m_spColorData.m_pObject;
    static_cast<NiPSysColorModifier*>(pObject)->SetColorData(static_cast<NiColorData*>(tmp));
    return static_cast<NiPSysColorModifier*>(pObject);
}

inline NiPSysColorModifier::NiPSysColorModifier() throw()
    : m_spColorData(0), m_fLoKeyTime(0.0f), m_fHiKeyTime(0.0f)
{}

// Allocates and returns a new color modifier instance.
// @fnv 0x00c2d180
void* __cdecl CreateColorModifier()
{
    return new NiPSysColorModifier;
}

struct FnvColorAView
{
    float r;
    float g;
    float b;
    float a;
};

struct PInfo
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    unsigned int unk18;
};

struct PData
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    FnvColorAView* m_pkParticleColors;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned short m_usActive;
    unsigned short unk52;
    unsigned short unk54;
    unsigned short unk56;
    unsigned short unk58;
    unsigned short unk5a;
    unsigned short unk5c;
    unsigned short unk5e;
    unsigned short unk60;
    unsigned short unk62;
    unsigned short unk64;
    unsigned short unk66;
    unsigned short unk68;
    unsigned short unk6a;
    unsigned short unk6c;
    unsigned short unk6e;
    PInfo* m_pkInfo;
};

void __cdecl InterpolateColor(FnvColorAView* out, float t, char* keys, unsigned int typeBits, unsigned int n,
                              unsigned int* idx, unsigned char stride);

inline float Mx(float a, float b)
{
    return (a > b) ? a : b;
}
inline float Mn(float a, float b)
{
    return (a < b) ? a : b;
}

// For each active particle, computes a clamped time from PInfo values and samples the color key data to update the particle color array.
// @fnv 0x00c2cfb0
void NiPSysColorModifier::Update(float fTime, NiPSysData* pkData)
{
    PData* d = (PData*)pkData;
    FnvColorAView* pParticleColors = d->m_pkParticleColors;
    PInfo* pParticleInfo = d->m_pkInfo;
    if (!pParticleColors)
        return;

    unsigned short usActiveCount = d->m_usActive;
    NiColorData* pColorData = m_spColorData.m_pObject;
    unsigned int idx = 0;
    unsigned int n = pColorData->m_uiNumKeys;
    unsigned int uiTypeBits = pColorData->m_eRequestType;
    unsigned char ucStride = pColorData->m_ucKeyDataSize;
    char* keys = reinterpret_cast<char*>(pColorData->m_pKeyArray);

    for (unsigned short iIndex = 0; iIndex < usActiveCount; iIndex++)
    {
        FnvColorAView& r = pParticleColors[iIndex];
        float t = pParticleInfo[iIndex].m_fXValue / pParticleInfo[iIndex].m_fYValue;
        t = Mx(t, m_fLoKeyTime);
        t = Mn(t, m_fHiKeyTime);

        FnvColorAView cColor;
        idx = 0;
        InterpolateColor(&cColor, t, keys, uiTypeBits, n, &idx, ucStride);
        r = cColor;
    }
}
