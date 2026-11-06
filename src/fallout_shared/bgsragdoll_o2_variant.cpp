
// src/fallout_shared/bgsragdoll_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsragdoll.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BGSRagdoll.h"
#include "../../include/RagdollAnimationData.h"

// The shared layout does not yet declare the comparison member.
// This extension supplies only that member; all storage comes from the shared class.
class RagdollAnimationDataComparison : public RagdollAnimationData
{
public:
    bool Diff(const RagdollAnimationData& other) const;
};

// @fnv 0x00c74fb0
bool RagdollAnimationDataComparison::Diff(const RagdollAnimationData& other) const
{
    bool diff = false;
    if (m_kFootIndices.iSize != other.m_kFootIndices.iSize)
        goto fail;
    {
        unsigned int i = 0;
        while (i < m_kFootIndices.iSize)
        {
            if (diff)
                goto fail;
            diff = m_kFootIndices.pBuffer[i] != other.m_kFootIndices.pBuffer[i];
            i++;
        }
    }
    if (diff)
        goto fail;
    if (bEnabled != other.bEnabled)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter1 != other.m_kRagdollFeedbackData.m_fFeedbackParameter1)
        goto fail;
    if (m_kRagdollFeedbackData.fHeirGain != other.m_kRagdollFeedbackData.fHeirGain)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter3 != other.m_kRagdollFeedbackData.m_fFeedbackParameter3)
        goto fail;
    if (m_kRagdollFeedbackData.fVelGain != other.m_kRagdollFeedbackData.fVelGain)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter5 != other.m_kRagdollFeedbackData.m_fFeedbackParameter5)
        goto fail;
    if (m_kRagdollFeedbackData.fSnapGain != other.m_kRagdollFeedbackData.fSnapGain)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter7 != other.m_kRagdollFeedbackData.m_fFeedbackParameter7)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter8 != other.m_kRagdollFeedbackData.m_fFeedbackParameter8)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter9 != other.m_kRagdollFeedbackData.m_fFeedbackParameter9)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter10 != other.m_kRagdollFeedbackData.m_fFeedbackParameter10)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter11 != other.m_kRagdollFeedbackData.m_fFeedbackParameter11)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter12 != other.m_kRagdollFeedbackData.m_fFeedbackParameter12)
        goto fail;
    if (m_kRagdollFeedbackData.ThreeFloatsAndTwoIntegers != other.m_kRagdollFeedbackData.ThreeFloatsAndTwoIntegers)
        goto fail;
    if (m_kRagdollFeedbackData.m_uiFeedbackParameter14 != other.m_kRagdollFeedbackData.m_uiFeedbackParameter14)
        goto fail;
    if (m_kRagdollFeedbackData.m_fFeedbackParameter13 != other.m_kRagdollFeedbackData.m_fFeedbackParameter13)
        goto fail;
    goto done;
fail:
    diff = true;
done:
    return diff;
}

// Constructing the shared class emits its TESModel destructor adjustment thunk.
// @fnv 0x005effb0 (compiler-generated destructor thunk)
BGSRagdoll::BGSRagdoll()
{}
