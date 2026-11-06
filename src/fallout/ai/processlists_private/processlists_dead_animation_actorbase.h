// and public JohnnyGuitar PC headers. No implementation bodies are imported.
#ifndef FNV_PROCESSLISTS_DEAD_ANIMATION_ACTORBASE_H
#define FNV_PROCESSLISTS_DEAD_ANIMATION_ACTORBASE_H

class TESLevItem;
class BGSVoiceType;
class FactionReaction;
class InventoryItemEntry;
class MagicItemForm;
class SpellItem;
class TESLevSpell;

class CollisionComponent;
class BGSBodyPartData;
class TESCombatStyle;

// Public JohnnyGuitar BSEnums.hpp's enum, expressed in C++03.
struct _ImpactMaterialType
{
    enum Type
    {
        NONE = 0xFFFFFFFFu,
        STONE = 0,
        DIRT = 1,
        GRASS = 2,
        GLASS = 3,
        METAL = 4,
        WOOD = 5,
        ORGANIC = 6,
        CLOTH = 7,
        WATER = 8,
        HOLLOW_METAL = 9,
        ORGANIC_BUG = 10,
        ORGANIC_GLOW = 11,
        COUNT = 12
    };
};
typedef _ImpactMaterialType::Type IMPACT_MATERIAL_TYPE;
FNV_STATIC_ASSERT(sizeof(IMPACT_MATERIAL_TYPE) == 4);

class PackedRecordData
{
  public:
    unsigned char m_ucField00;
    unsigned char m_ucField01;
    unsigned char m_ucField02;
    unsigned char m_ucField03;
    unsigned char m_ucField04;
    unsigned int m_uiField08;
    unsigned char m_ucField0C;
    unsigned char m_ucField0D;
    unsigned char m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
};
FNV_STATIC_ASSERT(sizeof(PackedRecordData) == 0x14);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField00) == 0x00);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField01) == 0x01);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField02) == 0x02);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField03) == 0x03);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField04) == 0x04);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField08) == 0x08);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0C) == 0x0C);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0D) == 0x0D);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0E) == 0x0E);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_bField0F) == 0x0F);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField10) == 0x10);

// The first member in each inherited data component verifies its base offset.

#endif
