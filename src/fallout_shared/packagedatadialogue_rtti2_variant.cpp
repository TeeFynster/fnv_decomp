// src/fallout_shared/packagedatadialogue_rtti2_variant.cpp - dialogue package RTTI comparison.

#include "../../include/TESDialoguePackageData.h"

struct DialogueTargetComparison
{
    bool IsDifferentFrom(DialogueTargetComparison*);
};

// The shared class supplies the entire layout; this adapter declares only the
// comparison method that is not yet declared by the shared header.
struct DialoguePackageComparison : TESDialoguePackageData
{
    bool TESDialoguePackageData_Compare(void*);
};

// @fnv 0x0067b470
// src: XBOX_PDB 0x0067b470
bool DialoguePackageComparison::TESDialoguePackageData_Compare(void* object)
{
    DialoguePackageComparison* other = reinterpret_cast<DialoguePackageComparison*>(
        dynamic_cast< ::TESDialoguePackageData*>(static_cast< ::TESPackageData*>(object)));

    if (other == 0)
        return true;

    if (m_fFirstFloat != other->m_fFirstFloat)
        return true;

    if (m_fFloatValue != other->m_fFloatValue)
        return true;

    if (m_bFirstFlag != other->m_bFirstFlag)
        return true;

    if (pMenuTopicEntry != other->pMenuTopicEntry)
        return true;

    if (m_pTargetLocation != 0)
    {
        if (reinterpret_cast<DialogueTargetComparison*>(m_pTargetLocation)->IsDifferentFrom(
                reinterpret_cast<DialogueTargetComparison*>(other->m_pTargetLocation)))
            return true;
    }
    else if (other->m_pTargetLocation != 0)
    {
        return true;
    }

    if (m_bFollowingFlag != other->m_bFollowingFlag)
        return true;

    if (m_bThirdFlag != other->m_bThirdFlag)
        return true;

    if (m_iTrailingValue != other->m_iTrailingValue)
        return true;

    return false;
}
