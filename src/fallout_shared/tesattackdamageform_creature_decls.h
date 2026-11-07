// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESATTACKDAMAGEFORM_CREATURE_DECLS_H
#define FNV_TESATTACKDAMAGEFORM_CREATURE_DECLS_H

#include "layout_support.h"
#include "../../include/ActorBaseAttributes.h"
#include "../../include/ActorMover.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSTouchSpellForm.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/FileEntryList.h"
#include "../../include/FileEntryListCollection.h"
#include "../../include/NiTimeController.h"
#include "../../include/PackageList.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESContainer.h"
#include "../../include/TESCreature.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelList.h"
#include "../../include/TESObject.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSpellList.h"
#include "../../include/TypedData.h"
class PackedRecordData;
class BGSBodyPartData;
class BGSImpactDataSet;
class BGSVoiceType;
class BSFileEntry;
class InventoryItemEntry;
class CollisionComponent;
class FactionReaction;
class MagicItemForm;
class TESLevItem;
class TESPackage;
class SpellItem;
class BGSListForm;
class BGSBodyPartData;
class TESCombatStyle;
class TESCombatStyle;
class TESLevSpell;
class TESFormList;
enum BGSImpactDataSet__IMPACT_MATERIAL_TYPE
{
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_STONE = 0,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_DIRT = 1,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_GRASS = 2,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_GLASS = 3,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_METAL = 4,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_WOOD = 5,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC = 6,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_CLOTH = 7,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_WATER = 8,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_HOLLOW_METAL = 9,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC_BUG = 10,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_ORGANIC_GLOW = 11,
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE_IMP_MAT_COUNT = 12
};

#pragma pack(push, 4)
class PackedRecordData
{
  public:
    unsigned char m_ucField00;  // +0x0, 1 bytes
    unsigned char m_ucField01;  // +0x1, 1 bytes
    unsigned char m_ucField02;  // +0x2, 1 bytes
    unsigned char m_ucField03;  // +0x3, 1 bytes
    unsigned char m_ucField04;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    unsigned int m_uiField08;   // +0x8, 4 bytes
    unsigned char m_ucField0C;  // +0xC, 1 bytes
    unsigned char m_ucField0D;  // +0xD, 1 bytes
    unsigned char m_ucField0E;  // +0xE, 1 bytes
    bool m_bField0F;            // +0xF, 1 bytes
    unsigned int m_uiField10;   // +0x10, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackedRecordData) == 20);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField00) == 0);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField01) == 1);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField02) == 2);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField03) == 3);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField04) == 4);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField08) == 8);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0C) == 12);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0D) == 13);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0E) == 14);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_bField0F) == 15);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField10) == 16);

class PerkEntryConditionSet;
class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
};
TESCombatStyle* TESCombatStyle_GetDefaultCombatStyle();
#endif
