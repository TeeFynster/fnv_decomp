#ifndef FNV_MOBILEOBJECT_UNIT_H
#define FNV_MOBILEOBJECT_UNIT_H

#include "mobileobject_topicinfo.h"  // first: its shared headers include <windows.h> before layout_support.h
#include "mobileobject_decls.h"

// @fnv 0x008ae4c0
NiPoint3* MobileObject::GetPos() const
{
    if (!IsSwimming_005a2030())
        return reinterpret_cast<NiPoint3*>(
            reinterpret_cast<TESTopicInfo*>(const_cast<MobileObject*>(this))->GetAddTopicList());
    if (GetRelevantWaterHeight() == DAT_010241b0)
        return reinterpret_cast<NiPoint3*>(
            reinterpret_cast<TESTopicInfo*>(const_cast<MobileObject*>(this))->GetAddTopicList());
    ++DAT_011df880;
    if (DAT_011df880 >= 5)
        DAT_011df880 = 0;
    DAT_011df7a0[DAT_011df880] = *reinterpret_cast<NiPoint3*>(
        reinterpret_cast<TESTopicInfo*>(const_cast<MobileObject*>(this))->GetAddTopicList());
    TESObjectCELL* cell = const_cast<MobileObject*>(this)->GetParentCell();
    if (cell && reinterpret_cast<MobileObjectCellAccess*>(cell)->FUN_004518e0())
    {
        MobileObjectWaterPositionHeight heights;
        heights.waterHeight = GetRelevantWaterHeight() - DAT_01020998;
        heights.heightOffset = GetActorHeight() * DAT_0101de30;
        if (heights.waterHeight > DAT_011df7a0[DAT_011df880].z + heights.heightOffset)
            DAT_011df7a0[DAT_011df880].z += heights.heightOffset;
        else
            DAT_011df7a0[DAT_011df880].z = heights.waterHeight;
    }
    return &DAT_011df7a0[DAT_011df880];
}
// The original linker folded the position-address accessor with this getter.
// Use the decorated name already bound by canonical source.
// @fnv 0x00436aa0
BSSimpleList<TESTopic*>* TESTopicInfo::GetAddTopicList()
{
    return &m_kAddTopicList;
}
#endif
