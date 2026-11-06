#include "../../include/TESDialoguePackageData.h"

struct TargetLocation
{
    unsigned char type;
    unsigned char unk01, unk02, unk03;
    unsigned int data;
    float radius;
    TargetLocation();
    ~TargetLocation();
    void FUN_0067f4d0(TargetLocation*, int);
};
// The shared class does not declare this copy overload. Keep its implementation
// in a fieldless derived helper so all data layout comes from the shared class.
struct DialoguePackageDataCopy : TESDialoguePackageData
{
    void Copy(TESPackageData*);
};
// @fnv 0x0067b310
void DialoguePackageDataCopy::Copy(TESPackageData* input)
{
    TESDialoguePackageData* source = dynamic_cast<TESDialoguePackageData*>(input);
    if (source)
    {
        m_fFirstFloat = source->m_fFirstFloat;
        m_fFloatValue = source->m_fFloatValue;
        m_bFirstFlag = source->m_bFirstFlag;
        if (m_pTargetLocation)
        {
            delete m_pTargetLocation;
            m_pTargetLocation = 0;
        }
        if (source->m_pTargetLocation)
        {
            m_pTargetLocation = new TargetLocation;
            m_pTargetLocation->FUN_0067f4d0(source->m_pTargetLocation, 0);
        }
        pMenuTopicEntry = source->pMenuTopicEntry;
        m_bFollowingFlag = source->m_bFollowingFlag;
        m_bThirdFlag = source->m_bThirdFlag;
        m_iTrailingValue = source->m_iTrailingValue;
    }
}
