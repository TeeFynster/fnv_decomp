// gamebryo2.2/corelibs/nianimation/niblendboolinterpolator.cpp: NiBlendBoolInterpolator (13 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBlendBoolInterpolator.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/NiInterpolator.h"
// NiStream.h defines BSStreamHeader itself; including BSStreamHeader.h as well causes C2011.
#include "../../../../include/NiStream.h"
#include "NiRefObject_inline.h"

extern float DAT_0109696c;
extern unsigned char DAT_0109a914;

// @fnv 0x00a56880
bool NiBlendBoolInterpolator::Update(float time, NiObjectNET* target, bool& value)
{
    bool updated = false;
    if (m_ucInterpCount == 1)
    {
        updated = UpdateAccumulatedTransform(time, target, value);
    }
    else if (m_ucInterpCount > 0)
    {
        NiBlendInterpolator::NormalizeWeights();
        updated = UpdateSingleInterpolator(time, target, value);
    }
    m_fLastTime = time;
    return updated;
}

// @fnv 0x00a565a0
bool __fastcall SupportsBoolInterpolator(NiBlendBoolInterpolator* self, int, NiInterpolator* interpolator)
{
    return interpolator->IsBoolValueSupported();
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void* pThis);
extern int DAT_0109a67c;

// @fnv 0x00a565c0
// src: EXE 0x00a565c0
void* __cdecl NiBlendBoolInterpolator_CreateObject()
{
    void* p = BSFadeNode::operator new(0x34);
    if (p)
    {
        NiBlendInterpolator_NiBlendInterpolator(p);
        *reinterpret_cast<void**>(p) = &DAT_0109a67c;
        reinterpret_cast<unsigned char*>(p)[0x30] = DAT_0109a914;
        return p;
    }
    return 0;
}

// @fnv 0x00a568e0
void NiBlendBoolInterpolator::LoadBinary(NiStream& stream)
{
    NiBlendInterpolator::LoadBinary(stream);
    NiBinaryStream* __restrict input = stream.m_pkIstr;
    unsigned int size = 1;
    input->m_uiAbsoluteCurrentPos += input->m_pfnRead(input, &m_bBoolValue, 1, &size, 1);
}

// Constructs a NiBlendInterpolator with the given arguments, installs the vtable at DAT_0109a67c and sets byte 0x30 from DAT_0109a914.
// @fnv 0x00a56560
NiBlendInterpolator* __fastcall ConstructBlendInterpolator(NiBlendInterpolator* self, int unused, bool a, float b,
                                                           unsigned char c)
{
    self->NiBlendInterpolator::NiBlendInterpolator(a, b, c);
    *(int**)self = &DAT_0109a67c;
    *((unsigned char*)self + 0x30) = DAT_0109a914;
    return self;
}

// @fnv 0x00a565f0
bool __fastcall IsBoolValueEqual(NiBlendBoolInterpolator* self, int, NiBlendBoolInterpolator* object)
{
    if (!self->NiBlendInterpolator::IsEqual(object))
        return false;
    return self->m_bBoolValue == object->m_bBoolValue ? true : false;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f407c;
// @fnv 0x00a56620
// src: COMMUNITY 0x00a56620
void* __cdecl NiBlendBoolInterpolator_GetRTTI()
{
    return &g_011f407c;
}

void __fastcall DestroyInterpolatorArray(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// Calls DestroyInterpolatorArray on self, then if flags has bit 0 set calls __Dummy_00b6fef0 with self and 0x34, and returns self.
// @fnv 0x00a56630
void* __fastcall FUN_00a56630(void* self, int, unsigned int flags)
{
    DestroyInterpolatorArray(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x34);
    return self;
}

// @fnv 0x00a56650
NiBlendBoolInterpolator* __fastcall CloneBoolInterpolator(NiBlendBoolInterpolator* self, int, void* cloning)
{
    NiBlendBoolInterpolator* object = static_cast<NiBlendBoolInterpolator*>(
        BSFadeNode::operator new(sizeof(NiBlendBoolInterpolator)));
    if (object)
    {
        NiBlendInterpolator_NiBlendInterpolator(object);
        *reinterpret_cast<void**>(object) = &DAT_0109a67c;
        object->m_bBoolValue = DAT_0109a914;
    }
    else
    {
        object = 0;
    }
    self->NiBlendInterpolator::CopyMembers(object, cloning);
    object->m_bBoolValue = self->m_bBoolValue;
    return object;
}

// @fnv 0x00a566a0
bool NiBlendBoolInterpolator::UpdateAccumulatedTransform(float time, NiObjectNET* target, bool& value)
{
    if (m_uiObjectFlags & 1)
        time = m_fSingleInterpolatorTime;
    if (time == DAT_0109696c)
        return false;
    if (m_pSingleInterpolator->UpdateBool(time, target, value))
    {
        m_bBoolValue = value;
        return true;
    }
    value = false;
    m_bBoolValue = DAT_0109a914;
    return false;
}

// @fnv 0x00a56920
void __fastcall SaveBoolInterpolator(NiBlendBoolInterpolator* self, int, NiStream* stream)
{
    self->NiBlendInterpolator::SaveBinary(*stream);
    NiBinaryStream* __restrict out = stream->m_pkOstr;
    unsigned int size = 1;
    out->m_uiAbsoluteCurrentPos += out->m_pfnWrite(out, &self->m_bBoolValue, 1, &size, 1);
}

namespace fnv_00a56960 {
struct M76Arr
{
    void* vtbl;
    void* data;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short pad0c;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* item)
    {
        unsigned int index = m_usESize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, item);
    }
};
struct M76Glob
{
    int pad;
};
extern M76Glob* g_011f407c;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(M76Glob*);
char* __cdecl NiGetViewerString_00a7d410(const char*, unsigned int);
// Calls FUN_00a38080, then appends the result of FUN_00a7d330 and the formatted "m_bBoolValue" string to pkStrings.
// @fnv 0x00a56960
void __fastcall AddBoolValueStrings(NiBlendBoolInterpolator* self, int, M76Arr* pkStrings)
{
    self->NiBlendInterpolator::AppendInterpolatorStrings(reinterpret_cast<StrArr*>(pkStrings));
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_011f407c));
    pkStrings->Add(NiGetViewerString_00a7d410("m_bBoolValue", self->m_bBoolValue));
}
}  // namespace fnv_00a56960

struct NiInterpolatorPtr
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
    NiInterpolatorPtr m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};

inline bool GetUpdateTimeForItem(NiBlendBoolInterpolator* self, float& time,
                                 NiBlendInterpolator__InterpArrayItem& item)
{
    NiInterpolator* interpolator = item.m_spControllerInterpolator;
    if (interpolator && item.m_fNormalizedWeight != 0.0f)
    {
        if (self->m_uiObjectFlags & 1)
            time = item.m_fLastEvaluationTime;
        if (time == DAT_0109696c)
            return false;
        return true;
    }
    return false;
}

// Accumulates successful interpolator updates by normalized weight; when any update succeeds, sets both boolean values using a 0.5 threshold.
// @fnv 0x00a56710
bool NiBlendBoolInterpolator::UpdateSingleInterpolator(float fTime, NiObjectNET* pkInterpTarget, bool& bValue)
{
    float fTotalValue = 0.0f;
    float fTotalWeight = 1.0f;
    bool bModifiedValue = false;
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        unsigned int uOff = uc * sizeof(NiBlendInterpolator__InterpArrayItem);
        NiBlendInterpolator__InterpArrayItem& kItem = m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator && m_pInterpArray[uc].m_fNormalizedWeight > 0.0f)
        {
            float fUpdateTime = fTime;
            if (!::GetUpdateTimeForItem(this, fUpdateTime, m_pInterpArray[uc]))
            {
                fTotalWeight -= kItem.m_fNormalizedWeight;
                continue;
            }
            unsigned char bInterpValue;
            if (kItem.m_spControllerInterpolator->UpdateBool(fUpdateTime, pkInterpTarget, reinterpret_cast<bool&>(bInterpValue)))
            {
                int iV;
                NiBlendInterpolator__InterpArrayItem* pA = m_pInterpArray;
                *(volatile int*)&iV = bInterpValue;
                fTotalValue += ((NiBlendInterpolator__InterpArrayItem*)((char*)pA + uOff))->m_fNormalizedWeight * iV;
                bModifiedValue = true;
            }
            else
            {
                fTotalWeight -= m_pInterpArray[uc].m_fNormalizedWeight;
            }
        }
    }
    if (!bModifiedValue)
    {
        bValue = false;
        m_bBoolValue = DAT_0109a914;
        return false;
    }
    float fValue = fTotalValue / fTotalWeight;
    if (fValue < 0.5f)
    {
        m_bBoolValue = false;
        bValue = false;
    }
    else
    {
        m_bBoolValue = true;
        bValue = true;
    }
    return true;
}
