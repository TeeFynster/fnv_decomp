// fallout_shared/facegen/bsfacegenanimationdata.h: face generation animation accessors
#ifndef FNV_BSFACEGENANIMATIONDATA_H
#define FNV_BSFACEGENANIMATIONDATA_H

#include "../../../include/MiddleHighProcess.h"
#include "../../../include/BSFaceGenAnimationData.h"
#include "../../../include/BSFaceGenKeyframeMultiple.h"

#include "bsfacegenanimationdata_types_BS_FACEGEN_EXPRESSION.h"
#include "bsfacegenanimationdata_types_BS_FACEGEN_PHONEME.h"
#include "bsfacegenanimationdata_types_BS_FACEGEN_CUSTOM_MORPH.h"


// @fnv 0x00649b80
bool MiddleHighProcess::BeginIdleAnimation() const
{
    return m_bFourthStateFlag;
}
// @fnv 0x00649bc0
bool BSFaceGenAnimationData::GetDead()
{
    return dead;
}
// @fnv 0x008d87e0
bool BSFaceGenAnimationData::GetChanged()
{
    return p18c;
}
// @fnv 0x00649ba0
void BSFaceGenAnimationData::SetModified(bool value)
{
    p18c = value;
}
// @fnv 0x006499e0
float BSFaceGenAnimationData::GetExpressionWeight(BS_FACEGEN_EXPRESSION expression)
{
    return expression < BS_FACEGEN_EXPRESSION_BS_FG_EXPRESSION_COUNT ? reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x74)->BSFaceGenKeyframeMultiple_GetQuantity(expression) : 0.0f;
}
// @fnv 0x00649aa0
float BSFaceGenAnimationData::GetPhonemeWeight(BS_FACEGEN_PHONEME phoneme)
{
    return phoneme < BS_FACEGEN_PHONEME_BS_FG_PHONEME_COUNT ? reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xDC)->BSFaceGenKeyframeMultiple_GetQuantity(phoneme) : 0.0f;
}
// @fnv 0x00649b10
float BSFaceGenAnimationData::GetCustomMorphWeight(BS_FACEGEN_CUSTOM_MORPH morph)
{
    return morph < BS_FACEGEN_CUSTOM_MORPH_BS_FG_CUSTOM_MORPH_COUNT ? reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x110)->BSFaceGenKeyframeMultiple_GetQuantity(morph) : 0.0f;
}
#endif
