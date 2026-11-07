
// src/gamebryo2.2/corelibs/nianimation/niblendcolorinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niblendcolorinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBlendColorInterpolator.h"

struct FUN_00a37ec0_tgt
{
    void NiBlendInterpolator_SaveBinary(NiStream& kStream);
};

// @fnv 0x00a56040
// src: XBOX_PDB 0x00a56040
void NiBlendColorInterpolator::SaveBinary_00a56040(NiStream& kStream)
{
    ((FUN_00a37ec0_tgt*)this)->NiBlendInterpolator_SaveBinary(kStream);
    m_kColorValue.SaveBinary(kStream);
}

extern "C" void* g_011f4074;

// @fnv 0x00a56060
// src: COMMUNITY 0x00a56060
void* __cdecl NiBlendColorInterpolator_GetRTTI()
{
    return &g_011f4074;
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern NiColorA const DAT_011a9430;
extern int DAT_011a9434;
extern int DAT_011a9438;
extern int DAT_011a943c;
extern int DAT_0109a58c;

// @fnv 0x00a55ff0
NiBlendColorInterpolator* __cdecl CreateBlendColorInterpolator()
{
    NiBlendColorInterpolator* pInterpolator = (NiBlendColorInterpolator*)BSFadeNode::operator new(0x44);
    if (pInterpolator)
    {
        NiBlendInterpolator_NiBlendInterpolator(pInterpolator);
        *(int*)pInterpolator = (int)&DAT_0109a58c;
        *(int*)((char*)pInterpolator + 0x30) = *(int*)&DAT_011a9430;
        *(int*)((char*)pInterpolator + 0x34) = DAT_011a9434;
        *(int*)((char*)pInterpolator + 0x38) = DAT_011a9438;
        *(int*)((char*)pInterpolator + 0x3c) = DAT_011a943c;
        *(char*)((char*)pInterpolator + 0x40) = 0;
    }
    else
    {
        pInterpolator = 0;
    }
    return pInterpolator;
}

// Constructs the object: installs the vtable, copies four ints from DAT_011a9430 into offset 0x30, and clears the flag at the end.
// @fnv 0x00a55f80
NiBlendColorInterpolator::NiBlendColorInterpolator(bool a, float b, unsigned char c)
    : NiBlendInterpolator(a, b, c), m_kColorValue(DAT_011a9430)
{
    m_bValueValid = 0;
}

void __fastcall DestroyInterpolatorArray(void*);
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a56070
void* NiBlendColorInterpolator::FUN_00a56070(unsigned int flags)
{
    DestroyInterpolatorArray(this);
    if (flags & 1)
        _delete(this, 0x44);
    return this;
}

// @fnv 0x00a56460
// src: GAMEBRYO_LIB 0x00a56460
void NiBlendColorInterpolator::LoadBinary_00a56460(NiStream& kStream)
{
    NiBlendInterpolator::LoadBinary(kStream);
    m_kColorValue.LoadBinary(kStream);
    if (m_kColorValue != DAT_011a9430)
        m_bValueValid = true;
}

// Tests whether the interpolator supports color values.
// @fnv 0x00a55fd0
// src: XBOX_PDB 0x00a55fd0
bool __stdcall NiBlendColorInterpolator_InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->IsColorAValueSupported();
}

struct CloningProcess
{
    void* m_pCloneMap;
};
struct CloneOwner
{
    void NiBlendInterpolator_CopyMembers(void*, void*);
};
// Allocates a NiBlendColorInterpolator, initialises it from DAT_011a9430, copies color fields from this, and returns the clone.
// @fnv 0x00a56090
// src: XBOX_PDB 0x00a56090
void* NiBlendColorInterpolator::CreateClone_00a56090(CloningProcess& kCloning)
{
    NiBlendColorInterpolator* pkObject = (NiBlendColorInterpolator*)BSFadeNode::operator new(0x44);
    if (pkObject)
    {
        NiBlendInterpolator_NiBlendInterpolator(pkObject);
        *(void**)pkObject = &DAT_0109a58c;
        *(int*)((char*)pkObject + 0x30) = *(int*)&DAT_011a9430;
        *(int*)((char*)pkObject + 0x34) = DAT_011a9434;
        *(int*)((char*)pkObject + 0x38) = DAT_011a9438;
        *(int*)((char*)pkObject + 0x3c) = DAT_011a943c;
        ((char*)pkObject)[0x40] = 0;
    }
    else
    {
        pkObject = 0;
    }
    ((CloneOwner*)this)->NiBlendInterpolator_CopyMembers(pkObject, &kCloning);
    {
        char* pDest = (char*)pkObject;
        char* pSrc = (char*)this;
        *(int*)(pDest + 0x30) = *(int*)(pSrc + 0x30);
        *(int*)(pDest + 0x34) = *(int*)(pSrc + 0x34);
        *(int*)(pDest + 0x38) = *(int*)(pSrc + 0x38);
        *(int*)(pDest + 0x3c) = *(int*)(pSrc + 0x3c);
        pDest[0x40] = pSrc[0x40];
    }
    return pkObject;
}

// @fnv 0x00a56400
bool NiBlendColorInterpolator::InterpolateValue(float fTime, NiObjectNET* pkInterpTarget, NiColorA& kValue)
{
    bool bReturnValue = false;
    unsigned char ucInterpCount = m_ucInterpCount;
    if (ucInterpCount == 1)
    {
        bReturnValue = GetColorAtTime(fTime, pkInterpTarget, &kValue);
    }
    else if (ucInterpCount > 0)
    {
        NiBlendInterpolator::NormalizeWeights();
        bReturnValue = UpdateBlend(fTime, pkInterpTarget, &kValue);
    }
    m_fLastTime = fTime;
    return bReturnValue;
}

extern float DAT_0109696c;

// @fnv 0x00a56110
bool NiBlendColorInterpolator::GetColorAtTime(float fTime, NiObjectNET* pkTarget, NiColorA* kOut)
{
    if (m_uiObjectFlags & 1)
    {
        fTime = m_fSingleInterpolatorTime;
    }
    if (fTime == DAT_0109696c)
    {
        return false;
    }
    if (m_pSingleInterpolator->UpdateColorA(fTime, pkTarget, m_kColorValue))
    {
        *kOut = m_kColorValue;
        return true;
    }
    const int* piDefaultColor = reinterpret_cast<const int*>(&DAT_011a9430);
    reinterpret_cast<int*>(kOut)[0] = piDefaultColor[0];
    reinterpret_cast<int*>(kOut)[1] = piDefaultColor[1];
    reinterpret_cast<int*>(kOut)[2] = piDefaultColor[2];
    reinterpret_cast<int*>(kOut)[3] = piDefaultColor[3];
    m_kColorValue = *kOut;
    return false;
}

bool __stdcall NiBlendInterpolator_IsEqual(void* pkObject);

// @fnv 0x00a564a0
// src: XBOX_PDB 0x00a564a0
bool NiBlendColorInterpolator::IsEqual_00a564a0(void* pkOther)
{
    if (!NiBlendInterpolator_IsEqual(pkOther))
    {
        return false;
    }
    void* pkSub = (char*)pkOther + 0x30;
    unsigned char bOk = m_kColorValue.operator!=(*static_cast<NiColorA*>(pkSub)) == 0;
    return bOk;
}

extern "C" void* g_011f4074;
extern int DAT_01096f1c;
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);

struct ArraySource
{
    virtual ~ArraySource();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int newSize);
    void FUN_0096ae90(unsigned int index, void** result);
};
struct BlendViewerStrings
{
    void AppendInterpolatorStrings(ArraySource* source);
};
struct AssignmentMember
{
    void* ToString(const int*);
};
// Calls FUN_00a38080, then appends the result of FUN_00a7d330 and a member lookup from offset 0x30 into the array source, growing it as needed.
// @fnv 0x00a564d0
void NiBlendColorInterpolator::AppendTwoEntries(ArraySource* pArraySource)
{
    reinterpret_cast<BlendViewerStrings*>(this)->AppendInterpolatorStrings(pArraySource);
    void* result = NiViewerStrings_NiGetViewerString_Title(g_011f4074);
    unsigned int index = pArraySource->m_usSize;
    if (index >= pArraySource->m_usMaxSize)
        pArraySource->FUN_0096ad30(index + pArraySource->m_usGrowBy);
    pArraySource->FUN_0096ae90(index, &result);
    result = reinterpret_cast<AssignmentMember*>(reinterpret_cast<char*>(this) + 0x30)->ToString(&DAT_01096f1c);
    index = pArraySource->m_usSize;
    if (index >= pArraySource->m_usMaxSize)
        pArraySource->FUN_0096ad30(index + pArraySource->m_usGrowBy);
    pArraySource->FUN_0096ae90(index, &result);
}

inline NiColorA::NiColorA(float r0, float g0, float b0, float a0)
{
    r = r0;
    g = g0;
    b = b0;
    a = a0;
}

inline NiColorA NiColorA::operator*(float f) const
{
    NiColorA res = *this;
    res.r *= f;
    res.g *= f;
    res.b *= f;
    res.a *= f;
    return res;
}

// Out-of-class body as this unit's original inlines it: c is added from a private copy and this is named two ways
// (t for r and b, this for g and a), which keeps every component of this loaded before its add.
__forceinline NiColorA& NiColorA::operator+=(const NiColorA& c)
{
    NiColorA k = c;
    NiColorA& t = *this;
    t.r += k.r;
    g += k.g;
    t.b += k.b;
    a += k.a;
    return t;
}

inline NiColorA& NiColorA::operator/=(float fScalar)
{
    r /= fScalar;
    g /= fScalar;
    b /= fScalar;
    a /= fScalar;
    return *this;
}

struct ColorInterpolatorPointer
{
    NiInterpolator* m_pObject;
    operator NiInterpolator*() const
    {
        return m_pObject;
    }
    NiInterpolator* operator->() const
    {
        return m_pObject;
    }
};
class NiBlendInterpolator__InterpArrayItem
{
public:
    ColorInterpolatorPointer m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
inline bool NiBlendColorInterpolator::GetUpdateTimeForItem(float& fTime, NiBlendInterpolator__InterpArrayItem& kItem)
{
    NiInterpolator* pkInterpolator = kItem.m_spControllerInterpolator;
    if (pkInterpolator && kItem.m_fNormalizedWeight != 0.0f)
    {
        if (m_uiObjectFlags & 1)
            fTime = kItem.m_fLastEvaluationTime;
        if (fTime == DAT_0109696c)
            return false;
        return true;
    }
    return false;
}

// @fnv 0x00a561c0
bool NiBlendColorInterpolator::UpdateBlend(float fTime, NiObjectNET* pkInterpTarget, NiColorA& kValue)
{
    m_bValueValid = false;
    m_kColorValue = NiColorA(0.0f, 0.0f, 0.0f, 0.0f);
    float fTotalWeight = 1.0f;
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        NiBlendInterpolator__InterpArrayItem& kItem = m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator && kItem.m_fNormalizedWeight > 0.0f)
        {
            NiColorA kTempValue(0.0f, 0.0f, 0.0f, 0.0f);
            float fUpdateTime = fTime;
            NiBlendInterpolator__InterpArrayItem& kItem2 = m_pInterpArray[uc];
            if (!GetUpdateTimeForItem(fUpdateTime, kItem2))
            {
                fTotalWeight -= kItem.m_fNormalizedWeight;
                continue;
            }
            bool bSuccess = kItem.m_spControllerInterpolator->UpdateColorA(fUpdateTime, pkInterpTarget, kTempValue);
            if (bSuccess)
            {
                m_kColorValue += kTempValue * m_pInterpArray[uc].m_fNormalizedWeight;
                m_bValueValid = true;
            }
            else
            {
                fTotalWeight -= m_pInterpArray[uc].m_fNormalizedWeight;
            }
        }
    }
    if (!m_bValueValid)
    {
        m_kColorValue = DAT_011a9430;
        kValue = m_kColorValue;
        return false;
    }
    m_kColorValue /= fTotalWeight;
    kValue = m_kColorValue;
    return true;
}
