// fallout_shared/bsbipnode.cpp: AnimationInterpolatorNode (5 functions)

#include "bsbipnode_decls.h"
#include "../../include/NiUpdateData.h"

// @fnv 0x004f0380
void AnimationInterpolatorNode::UpdateInterpolatorsAtTime(float time, bool selective)
{
    if (!FUN_004f05a0() || !m_usNumInterps)
        return;

    int iIndex;
    NiAVObject* target;
    NiQuatTransform transform;
    // Cache the pass limit while the shared transform remains available.
    {
        const int lastIndex = m_usNumInterps - 1;
        for (iIndex = 0; iIndex < lastIndex; ++iIndex)
        {
            target = m_ppTargetObjects[iIndex];
            if (!target)
                continue;
            if (!selective && !target->FUN_004f0140())
                continue;
            else if (selective && target->FUN_004f0140())
                continue;

            if (m_pkBlendInterpolators[iIndex].UpdateTransform(time, target, transform))
            {
                if (transform.IsTranslateXNotNegatedConstant())
                    target->FUN_00440460(transform.GetTranslate());
                if (transform.IsRotateValid())
                    target->FUN_004f0160(transform.GetOffsetC());
                if (transform.IsScaleValid())
                    target->FUN_00440490(transform.GetFloatAtOffset1C());
            }
        }

        target = m_ppTargetObjects[iIndex];
        if (!target || (!selective && !target->FUN_004f0140()))
            return;
        if (m_pkBlendInterpolators[iIndex].UpdateTransform(time, target, transform))
        {
            if (transform.IsTranslateXNotNegatedConstant())
                target->FUN_00440460(transform.GetTranslate());
            if (transform.IsRotateValid())
                target->FUN_004f0160(transform.GetOffsetC());
            if (transform.IsScaleValid())
                target->FUN_00440490(transform.GetFloatAtOffset1C());
        }
    }
}

struct FUN_004f0000_shell : public NiAVObject
{
    bool FUN_004f0000();
};

struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
};

// @fnv 0x004f0000
bool FUN_004f0000_shell::FUN_004f0000()
{
    return ((FUN_00456630_helper*)this)->FUN_00456630(0x40000);
}

struct FUN_004f00e0_shell : public NiAVObject
{
    void FUN_004f00e0(void*);
};

// @fnv 0x004f00e0
void FUN_004f00e0_shell::FUN_004f00e0(void* kTrn)
{
    *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x8C) = *reinterpret_cast<const NiPoint3*>(kTrn);
}

extern int DAT_011f36bc;
extern int g_011f36e4;
struct FUN_004f0040_shell
{
    void UpdateControls(float afTime);
};

// @fnv 0x004f0040
void FUN_004f0040_shell::UpdateControls(float afTime)
{
    NiTimeController* pkControl;
    for (pkControl = ((NiObjectNET*)this)->GetControllers(); pkControl; pkControl = pkControl->GetNext())
    {
        if (pkControl->GetRTTI() == reinterpret_cast<const NiRTTI*>(&DAT_011f36bc))
        {
            ((AnimationInterpolatorNode*)pkControl)->UpdateInterpolatorsAtTime(afTime, false);
        }
        else if (pkControl->GetRTTI() == reinterpret_cast<const NiRTTI*>(&g_011f36e4))
        {
            NiUpdateData updateData(afTime, false, false);
            pkControl->Update(updateData);
        }
    }
}

__declspec(thread) int DAT_tls_0x2c0;

// @fnv 0x004f0020
void FUN_004f0020(int value)
{
    DAT_tls_0x2c0 = value;
}
