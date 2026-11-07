
// src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_od_variant_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp
// NiGeomMorpherController: morph-target interpolator management.
#include "NiRefObject_inline.h"
#include "nigeommorphercontroller.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/StrArr.h"

#include <string.h>
#include <stdio.h>
NiFixedString::operator const char*() const
{
    return m_kHandle;
}
char* NiViewerStrings_NiGetViewerString_Title(char*);
char* NiGetViewerString_00a7d510(const char*, unsigned int);
void* NiMalloc(unsigned int);
extern char* DAT_011f3728;
extern NiRTTI DAT_011f3e58, DAT_011f3738;
__forceinline void StrArr::append(char*& value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, value);
}
__declspec(noinline) void StrArr::SetAt(unsigned int index, char*& value)
{
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (value)
            ++m_usESize;
    }
    else if (value)
    {
        if (!m_pBase[index])
            ++m_usESize;
    }
    else if (m_pBase[index])
        m_usESize += 0xffff;
    m_pBase[index] = value;
}
struct InterpolatorView : NiInterpolator
{
    // GetRTTI is the shared NiObject virtual (slot 0x08)
    __forceinline bool IsKindOfType(const NiRTTI* wanted)
    {
        const NiRTTI* rtti = GetRTTI();
        while (rtti)
        {
            if (rtti == wanted)
                return true;
            rtti = rtti->m_pBaseRTTI;
        }
        return false;
    }
};
struct BlendValueView : InterpolatorView
{
    int u0c, u10, u14, u18, u1c, u20, u24, u28, u2c;
    float value;
};
struct FloatValueView : InterpolatorView
{
    float value;
};
struct MorphViewer : NiGeomMorpherController
{
    void NiGeomMorpherController_GetViewerStrings(StrArr*);
};
// @fnv 0x00a3b700
// src: XBOX_PDB 0x00a3b700
void MorphViewer::NiGeomMorpherController_GetViewerStrings(StrArr* array)
{
    union HeaderScratch
    {
        char* text;
        unsigned int count;
    } header;
    {
        header.text = NiViewerStrings_NiGetViewerString_Title(DAT_011f3728);
        array->append(header.text);
        header.text = NiGetViewerString_00a7d510("NumTargets",
                                   m_spMorphTargetData.m_pObject ? m_spMorphTargetData.m_pObject->m_uiNumTargets : 0);
        array->append(header.text);
        header.text =
            NiGetViewerString_00a7d510("NumVertsPerTarget",
                         m_spMorphTargetData.m_pObject ? m_spMorphTargetData.m_pObject->m_uiNumVertsPerTarget : 0);
        array->append(header.text);
    }
    header.count = m_spMorphTargetData.m_pObject ? m_spMorphTargetData.m_pObject->m_uiNumTargets : 0;
    float value;
    unsigned int i = 0;
    if (i < header.count)
    {
        unsigned int offset = 0;
        do
        {
            NiMorphData::MorphTarget* target =
                i < m_spMorphTargetData.m_pObject->m_uiNumTargets
                    ? reinterpret_cast<NiMorphData::MorphTarget*>(
                          reinterpret_cast<char*>(m_spMorphTargetData.m_pObject->m_pMorphTargets) + offset)
                    : 0;
            InterpolatorView* interpolator = static_cast<InterpolatorView*>(GetInterpolator((unsigned short)i));
            char buffer[256];
            if (interpolator)
            {
                BlendValueView* blend =
                    interpolator->IsKindOfType(&DAT_011f3e58) ? static_cast<BlendValueView*>(interpolator) : 0;
                FloatValueView* scalar =
                    interpolator->IsKindOfType(&DAT_011f3738) ? static_cast<FloatValueView*>(interpolator) : 0;
                if (blend)
                {
                    value = blend->value;
                    sprintf(buffer, "%d %s = %0.2f", i, static_cast<const char*>(target->GetName()), (double)value);
                }
                else if (scalar)
                {
                    value = scalar->value;
                    sprintf(buffer, "%d %s = %0.2f", i, static_cast<const char*>(target->GetName()), (double)value);
                }
                else
                    goto no_val;
            }
            else
            {
            no_val:
                sprintf(buffer, "%d %s", i, static_cast<const char*>(target->GetName()));
            }
            unsigned int bytes = strlen(buffer) + 3;
            char* copy = static_cast<char*>(NiMalloc(bytes));
            strcpy_s(copy, bytes, buffer);
            unsigned int index = array->m_usSize;
            if (index >= array->m_usMaxSize)
                array->SetSize(index + array->m_usGrowBy);
            if (index >= array->m_usSize)
            {
                array->m_usSize = index + 1;
                if (copy)
                    ++array->m_usESize;
            }
            else if (copy)
            {
                if (!array->m_pBase[index])
                    ++array->m_usESize;
            }
            else if (array->m_pBase[index])
                array->m_usESize += 0xffff;
            offset += sizeof(NiMorphData::MorphTarget);
            array->m_pBase[index] = copy;
            ++i;
        } while (i < header.count);
    }
}
