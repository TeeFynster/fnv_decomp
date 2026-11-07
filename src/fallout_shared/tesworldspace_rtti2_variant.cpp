// src/fallout_shared/tesworldspace_rtti2_variant.cpp - world-space comparison.

#include "../../include/BGSAcousticSpace.h"
#include "../../include/EffectSetting.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESRegion.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/TESImageSpace.h"

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

// Method-only extensions for declarations not yet exposed by the shared headers.
struct WorldImageSpaceComparison : TESImageSpace
{
    bool Different(TESImageSpace*);
};

struct WorldSpaceComparison : TESWorldSpace
{
    void* ImageSpace();
    void* Water();
    float Height();
    void* Map();
    bool TESWorldSpace_Compare(TESForm*);
};
// @fnv 0x00585250
// src: XBOX_PDB 0x00585250
bool WorldSpaceComparison::TESWorldSpace_Compare(TESForm* form)
{
    WorldSpaceComparison* other = (WorldSpaceComparison*)dynamic_cast< ::TESWorldSpace*>(form);
    if (!other)
        return true;
    if (TESForm::Compare(other))
        return true;
    if (flags4C != other->flags4C)
        return true;
    if (field4E != other->field4E)
        return true;
    if (parent != other->parent)
        return true;
    if (fieldD0 != other->fieldD0)
        return true;
    if (GetClimate() != other->GetClimate())
        return true;
    if (ImageSpace() != other->ImageSpace())
        return true;
    if (data && other->data)
    {
        if (((WorldImageSpaceComparison*)data)->Different(other->data))
            return true;
    }
    else if (data || other->data)
        return true;
    if (Water() != other->Water())
        return true;
    if (GetLODWaterType() != other->GetLODWaterType())
        return true;
    if (Height() != other->Height())
        return true;
    if (fC8 != other->fC8 || fCC != other->fCC)
        return true;
    if (memcmp(&unk80, &other->unk80, 16))
        return true;
    if (memcmp(unk80 + 0x10, other->unk80 + 0x10, 12))
        return true;
    if (Map() != other->Map())
        return true;
    if (CanopyShadowTexture.CompareWithBase((BaseFormComponent*)&other->CanopyShadowTexture))
        return true;
    if (m_kLeafShadowTexture.CompareWithBase((BaseFormComponent*)&other->m_kLeafShadowTexture))
        return true;
    return false;
}
