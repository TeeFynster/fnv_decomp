// fallout_shared/containeritemextra_leveledlist.h: declares TESLeveledList
#ifndef FNV_CONTAINERITEMEXTRA_LEVELEDLIST_H
#define FNV_CONTAINERITEMEXTRA_LEVELEDLIST_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class LeveledObject;
class TESGlobal;
#pragma pack(push, 4)
class TESLeveledList : public BaseFormComponent
{
  public:
    BSSimpleList<LeveledObject*> leveledList;
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    unsigned char layoutPaddingE[2];
    TESGlobal* m_pLevelGlobal;
    BSSimpleList<LeveledObject*> m_kLeveledObjects;
    void ExtraWeaponModFlags_SetWeaponModFlags(unsigned char chance);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(offsetof(TESLeveledList, m_pChanceGlobal) == 12);
FNV_STATIC_ASSERT(sizeof(TESLeveledList) == 28);
#endif
