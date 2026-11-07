// gamebryo2.2/corelibs/nianimation/niblendfloatinterpolator.cpp: float blending (12 functions)

#include "NiRefObject_inline.h"

#include "../../../../include/BSStreamHeader.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBlendFloatInterpolator.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiStream.h"
#include "niblendfloatinterpolator_types_NiBlendFloatInterpolator.h"

extern float DAT_0109696c;
extern float DAT_0109a918;

// Updates the blend interpolator for the given time and target, delegating to single or multi-interpolator update paths and storing the last time.
// @fnv 0x00a40810
bool NiBlendFloatInterpolator::Update(float time, NiObjectNET* target, float& value)
{
    bool result = false;
    if (m_ucInterpCount == 1)
        result = NiBlendFloatInterpolator::UpdateAccumulatedTransform(time, target, value);
    else if (m_ucInterpCount > 0)
    {
        NiBlendInterpolator::NormalizeWeights();
        result = NiBlendFloatInterpolator::UpdateSingleInterpolator(time, target, value);
    }
    m_fLastTime = time;
    return result;
}

__forceinline void ReadFloat(NiBinaryStream* input, float* value)
{
    unsigned int size = 4;
    input->m_uiAbsoluteCurrentPos += input->m_pfnRead(input, value, 4, &size, 1);
}
// Calls the base NiBlendInterpolator::LoadBinary, then reads a float from the stream into m_fFloatValue.
// @fnv 0x00a40870
void NiBlendFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBlendInterpolator::LoadBinary(stream);
    ReadFloat(stream.m_pkIstr, &m_fFloatValue);
}

// @fnv 0x00a40640
bool NiBlendFloatInterpolator::UpdateAccumulatedTransform(float time, NiObjectNET* target, float& value)
{
    if (m_uiObjectFlags & 1)
        time = m_fSingleInterpolatorTime;
    if (time == DAT_0109696c)
        return false;
    if (m_pSingleInterpolator->UpdateFloat(time, target, m_fFloatValue))
    {
        value = m_fFloatValue;
        return true;
    }
    m_fFloatValue = DAT_0109a918;
    value = DAT_0109a918;
    return false;
}

__forceinline bool NiBlendInterpolator::GetBlendUpdateTime(float& time, NiBlendInterpolator__InterpArrayItem& item)
{
    if (!item.m_spControllerInterpolator || item.m_fNormalizedWeight == 0.0f)
        return false;
    if (m_uiObjectFlags & 1)
        time = item.m_fLastEvaluationTime;
    return time != DAT_0109696c;
}

// Blends weighted float values from the interpolator array into m_fFloatValue, normalizing by total weight, and writes the result to value.
// @fnv 0x00a406c0
bool NiBlendFloatInterpolator::UpdateSingleInterpolator(float time, NiObjectNET* target, float& value)
{
    m_fFloatValue = 0.0f;
    bool valid = false;
    float totalWeight = 1.0f;
    float currentValue;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiInterpolator* interpolator = m_pInterpArray[i].m_spControllerInterpolator;
        if (interpolator && m_pInterpArray[i].m_fNormalizedWeight > 0.0f)
        {
            NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[i];
            float updateTime = time;
            if (!GetBlendUpdateTime(updateTime, item))
                totalWeight -= item.m_fNormalizedWeight;
            else if (interpolator->UpdateFloat(updateTime, target, currentValue))
            {
                valid = true;
                m_fFloatValue += m_pInterpArray[i].m_fNormalizedWeight * currentValue;
            }
            else
                totalWeight -= m_pInterpArray[i].m_fNormalizedWeight;
        }
    }
    m_fFloatValue /= totalWeight;
    if (!valid)
    {
        value = DAT_0109a918;
        m_fFloatValue = DAT_0109a918;
        return false;
    }
    value = m_fFloatValue;
    return true;
}

// Returns whether the source interpolator supports float values.
// @fnv 0x00a40560
bool __fastcall ControlsFloatInterpolator(NiBlendFloatInterpolator*, int, NiInterpolator* interpolator)
{
    return interpolator->IsFloatValueSupported();
}

// Constructs the blend interpolator and initializes its float value.
// @fnv 0x00a40520
NiBlendFloatInterpolator::NiBlendFloatInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize)
    : NiBlendInterpolator(onlyUseHighestWeight, weightThreshold, arraySize)
{
    m_fFloatValue = DAT_0109a918;
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern const void* vftable_NiBlendFloatInterpolator[];

// @fnv 0x00a40580
void* __cdecl CreateNiBlendFloatInterpolator()
{
    void* pInterpolator = NiObject::operator new(0x34);
    if (pInterpolator)
    {
        NiBlendInterpolator_NiBlendInterpolator(pInterpolator);
        *(void**)pInterpolator = (void*)vftable_NiBlendFloatInterpolator;
        *(float*)((char*)pInterpolator + 0x30) = DAT_0109a918;
        return pInterpolator;
    }
    return 0;
}

// Compares the base interpolator and the float value.
// @fnv 0x00a405b0
bool __fastcall IsFloatValueEqual(NiBlendFloatInterpolator* self, int, NiObject* object)
{
    if (!self->NiBlendInterpolator::IsEqual(object))
        return false;
    NiBlendFloatInterpolator* destination = static_cast<NiBlendFloatInterpolator*>(object);
    if (self->m_fFloatValue != destination->m_fFloatValue)
        return false;
    return true;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f3e58;
// @fnv 0x00a405e0
// src: COMMUNITY 0x00a405e0
void* __cdecl NiBlendFloatInterpolator_GetRTTI()
{
    return &g_011f3e58;
}

// @fnv 0x00a408b0
void __fastcall SaveFloatBinary(NiBlendFloatInterpolator* self, int, NiStream* stream)
{
    self->NiBlendInterpolator::SaveBinary(*stream);
    NiBinaryStream* __restrict out = stream->m_pkOstr;
    unsigned int size = 4;
    out->m_uiAbsoluteCurrentPos += out->m_pfnWrite(out, &self->m_fFloatValue, 4, &size, 1);
}

namespace fnv_00a408f0 {
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
extern M76Glob* g_011f3e58;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(M76Glob*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
// Appends the base interpolator strings, type name, and formatted float value.
// @fnv 0x00a408f0
void __fastcall AppendFloatValueStrings(NiBlendFloatInterpolator* self, int, M76Arr* pkStrings)
{
    self->NiBlendInterpolator::AppendInterpolatorStrings(reinterpret_cast<StrArr*>(pkStrings));
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_011f3e58));
    pkStrings->Add(NiGetViewerString_00a7d550("m_fFloatValue", self->m_fFloatValue));
}
}  // namespace fnv_00a408f0

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct CopyMembersArguments
{
    NiBlendFloatInterpolator* destination;
    void* cloningProcess;
};
extern "C" void __fastcall NiBlendInterpolator_CopyMembers(void* source, CopyMembersArguments args);

// Allocates and initializes a clone, then copies the base and float members.
// @fnv 0x00a405f0
NiBlendFloatInterpolator* __fastcall CloneFloatInterpolator(NiBlendFloatInterpolator* self, int, void* pCloningProcess)
{
    NiBlendFloatInterpolator* copy =
        static_cast<NiBlendFloatInterpolator*>(Object_DispatchCommandFour(sizeof(NiBlendFloatInterpolator)));
    if (copy)
    {
        NiBlendInterpolator_NiBlendInterpolator(copy);
        *reinterpret_cast<const void***>(copy) = vftable_NiBlendFloatInterpolator;
        copy->m_fFloatValue = DAT_0109a918;
    }
    else
    {
        copy = 0;
    }
    CopyMembersArguments args = {copy, pCloningProcess};
    NiBlendInterpolator_CopyMembers(self, args);
    copy->m_fFloatValue = self->m_fFloatValue;
    return copy;
}
