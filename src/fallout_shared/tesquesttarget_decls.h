// fallout_shared/tesquesttarget_decls.h: declares quest target and stage data
#ifndef FNV_TESQUESTTARGET_DECLS_H
#define FNV_TESQUESTTARGET_DECLS_H

#include "layout_support.h"
#include "../../include/ExtraDataList.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/TESObjectREFR.h"

FNV_STATIC_ASSERT(sizeof(PerkEntryConditionSet) == 8);

// The target prefix accessed by these methods; the teleport path follows it.
class RegionObjectEntry
{
  public:
    unsigned char cFlags;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    TESObjectREFR* m_pReference;
    void InitItem(TESForm* form);
    PerkEntryConditionSet* GetConditions();
    TESObjectREFR* GetReference(bool resolveDeleted);
};
FNV_STATIC_ASSERT(offsetof(RegionObjectEntry, m_pReference) == 12);

class AnimationClipStatus
{
  public:
    unsigned char m_ucClipIdentifier;
    bool m_bCompleted;
};
FNV_STATIC_ASSERT(sizeof(AnimationClipStatus) == 2);

class PlayerQuestData;
class QuestStage
{
  public:
    AnimationClipStatus m_Data;
    BSSimpleList<PlayerQuestData*> m_kStageItems;
    void Load(TESFile* file);
};
FNV_STATIC_ASSERT(sizeof(QuestStage) == 12);
FNV_STATIC_ASSERT(offsetof(QuestStage, m_kStageItems) == 4);

// Older INDX chunks occupy eight bytes; the remaining payload is reserved.
struct TESQuestStageLegacyData
{
    AnimationClipStatus data;
    unsigned int reserved;
};
FNV_STATIC_ASSERT(sizeof(TESQuestStageLegacyData) == 8);

int __cdecl Warning(const char* format, ...);
#endif
