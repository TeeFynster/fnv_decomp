// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESOBJECTWEAP_H
#define FNV_TESOBJECTWEAP_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "TESHealthForm.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#include "layout_support.h"
class BGSAmmoForm;
class BGSBipedModelList;
class BGSClipRoundsForm;
class BGSDestructibleObjectForm;
class BGSEquipType;
class BGSImpactDataSet;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BGSPreloadable;
class BGSProjectile;
class BGSRepairItemList;
class BSFileEntry;
class CollisionComponent;
class EnchantmentItem;
class ShortPoint3;
class WeaponProperties;
class WeaponCriticalData;
class WeaponVATSData;
class TESAttackDamageForm;
class TESBoundObject__BOUND_DATA;
class TESEffectShader;
class TESEnchantableForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectIMOD;
class TESFormList;
class TESObjectSTAT;
class TESObjectWEAP;
class FileEntryList;
class TESValueForm;
class TESWeightForm;
class DistantTreeTextureInfo;
enum MagicSystem__CastingType
{
    MagicSystem__CastingType_CAST_ONCE = 0,
    MagicSystem__CastingType_WHEN_USED = 1,
    MagicSystem__CastingType_WHEN_STRIKES = 2,
    MagicSystem__CastingType_CONSTANT_EFFECT = 3,
    MagicSystem__CastingType_CASTING_COUNT = 4
};
enum BGSEquipType__EQUIP_TYPE
{
    BGSEquipType__EQUIP_TYPE_ET_NONE = -1,
    BGSEquipType__EQUIP_TYPE_ET_BIG_GUN = 0,
    BGSEquipType__EQUIP_TYPE_ET_ENERGY_WEAPON = 1,
    BGSEquipType__EQUIP_TYPE_ET_SMALL_GUN = 2,
    BGSEquipType__EQUIP_TYPE_ET_MELEE_WEAPON = 3,
    BGSEquipType__EQUIP_TYPE_ET_UNARMED_WEAPON = 4,
    BGSEquipType__EQUIP_TYPE_ET_THROWN_WEAPON = 5,
    BGSEquipType__EQUIP_TYPE_ET_MINE = 6,
    BGSEquipType__EQUIP_TYPE_ET_BODY_WEAR = 7,
    BGSEquipType__EQUIP_TYPE_ET_HEAD_WEAR = 8,
    BGSEquipType__EQUIP_TYPE_ET_HAND_WEAR = 9,
    BGSEquipType__EQUIP_TYPE_ET_CHEMS = 10,
    BGSEquipType__EQUIP_TYPE_ET_STIMPACK = 11,
    BGSEquipType__EQUIP_TYPE_ET_FOOD = 12,
    BGSEquipType__EQUIP_TYPE_ET_ALCOHOL = 13,
    BGSEquipType__EQUIP_TYPE_ET_COUNT = 14
};
enum WEAPONHITBEHAVIOR
{
    WEAPONHITBEHAVIOR_WHB_NORMAL = 0,
    WEAPONHITBEHAVIOR_WHB_DISMEMBER_ONLY = 1,
    WEAPONHITBEHAVIOR_WHB_EXPLODE_ONLY = 2,
    WEAPONHITBEHAVIOR_WHB_NO_DISMEMBER_OR_EXPLODE = 3
};
enum WEAPON_RUMBLE_PATTERN
{
    WEAPON_RUMBLE_PATTERN_RUMBLE_CONSTANT = 0,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SQUARE = 1,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_TRIANGLE = 2,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SAWTOOTH = 3,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PATTERN_COUNT = 4
};
enum WEAPON_MOD_EFFECT
{
    WEAPON_MOD_EFFECT_WEAPON_MOD_NONE = 0,
    WEAPON_MOD_EFFECT_WEAPON_MOD_INCREASE_WEAPON_DAMAGE = 1,
    WEAPON_MOD_EFFECT_WEAPON_MOD_INCREASE_CLIP_SIZE = 2,
    WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_SPREAD = 3,
    WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_WEIGHT = 4,
    WEAPON_MOD_EFFECT_WEAPON_MOD_AMMO_REGEN_SHOT = 5,
    WEAPON_MOD_EFFECT_WEAPON_MOD_AMMO_REGEN_SECONDS = 6,
    WEAPON_MOD_EFFECT_WEAPON_MOD_EQUIP_SPEED = 7,
    WEAPON_MOD_EFFECT_WEAPON_MOD_FIRE_SPEED = 8,
    WEAPON_MOD_EFFECT_WEAPON_MOD_PROJECTILE_SPEED = 9,
    WEAPON_MOD_EFFECT_WEAPON_MOD_MAX_HEALTH = 10,
    WEAPON_MOD_EFFECT_WEAPON_MOD_SILENCE = 11,
    WEAPON_MOD_EFFECT_WEAPON_MOD_SPLIT_BEAM = 12,
    WEAPON_MOD_EFFECT_WEAPON_MOD_VATS_BONUS = 13,
    WEAPON_MOD_EFFECT_WEAPON_MOD_IRON_SITES = 14,
    WEAPON_MOD_EFFECT_WEAPON_MOD_VATS_SPECIAL_ATTACK = 15,
    WEAPON_MOD_EFFECT_WEAPON_MOD_EFFECT_COUNT = 16
};
enum SOUND_LEVEL
{
    SOUND_LEVEL_SOUND_LEVEL_LOUD = 0,
    SOUND_LEVEL_SOUND_LEVEL_NORMAL = 1,
    SOUND_LEVEL_SOUND_LEVEL_SILENT = 2,
    SOUND_LEVEL_SOUND_LEVEL_COUNT = 3
};
#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
    // TESObject
    // void __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // TESFormList* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // bool __cdecl TESObject::*()
    // char* __cdecl TESObject::*()
    // void __cdecl TESObject::*(TESFormList*)
    // void __cdecl TESObject::*(TESObject*)
    // void __cdecl TESObject::*(TESObject*)
    // TESObject* __cdecl TESObject::*()
    // TESObject* __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*(NiAVObject*, const char*)
    // const char* __cdecl TESObject::*(TESObjectREFR*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // TESObject& __cdecl TESObject::*(const TESObject&)
    // void __cdecl TESObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
    // ShortPoint3
    // short& __cdecl ShortPoint3::*(int)
    // operator=
    // operator==
    // operator!=
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // operator-
    // operator*
    // ShortPoint3 __cdecl ShortPoint3::*(float)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&, const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // float __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(NiStream&)
    // void __cdecl ShortPoint3::*(NiStream&)
    // char* __cdecl ShortPoint3::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
    // TESBoundObject
    // void __cdecl TESBoundObject::*()
    // bool __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(NiAVObject*)
    // void __cdecl TESBoundObject::*(TESBoundObject*)
    // NiPoint3 __cdecl TESBoundObject::*()
    // NiPoint3 __cdecl TESBoundObject::*()
    // float __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(TESFile*)
    // bool __cdecl TESBoundObject::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // bool __cdecl TESBoundObject::*(bool)
    // TESBoundObject& __cdecl TESBoundObject::*(const TESBoundObject&)
    // void __cdecl TESBoundObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class TESModelTextureSwap : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    // TESModelTextureSwap
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(CHUNK_ID, CHUNK_ID, CHUNK_ID)
    // bool __cdecl TESModelTextureSwap::*(void*&, unsigned int&)
    // bool __cdecl TESModelTextureSwap::*(void*, unsigned int, unsigned int)
    // void __cdecl TESModelTextureSwap::*(TESModelTextureSwap*, TESFile*)
    // void __cdecl TESModelTextureSwap::*(TESForm*)
    // void __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // bool __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // BSSimpleList<DistantTreeTextureInfo *>* __cdecl TESModelTextureSwap::*()
    // DistantTreeTextureInfo* __cdecl TESModelTextureSwap::*(int)
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(const char*, int, BGSTextureSet*)
    // void __cdecl TESModelTextureSwap::*(int)
    // int __cdecl TESModelTextureSwap::*(NiAVObject*, const NiFixedString&)
    // void __cdecl TESModelTextureSwap::*(NiAVObject*)
    // bool __cdecl TESModelTextureSwap::*(NiAVObject*, BSMap<int,DistantTreeTextureInfo *>*, int&)
    // bool __cdecl TESModelTextureSwap::*(TESForm*, TESObjectREFR*)
    // TESModelTextureSwap* __cdecl TESModelTextureSwap::*()
    // TESModelTextureSwap& __cdecl TESModelTextureSwap::*(const TESModelTextureSwap&)
    // void __cdecl TESModelTextureSwap::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);
#pragma pack(push, 4)
class TESEnchantableForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    EnchantmentItem* m_pEnchantment;       // +0x4, 4 bytes
    unsigned short m_usEnchantmentAmount;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    MagicSystem__CastingType m_eCastingType;  // +0xC, 4 bytes
    // TESEnchantableForm
    // void __cdecl TESEnchantableForm::*(MagicSystem::CastingType)
    // void __cdecl TESEnchantableForm::*()
    // void __cdecl TESEnchantableForm::*()
    // void __cdecl TESEnchantableForm::*()
    // void __cdecl TESEnchantableForm::*(TESForm*)
    // void __cdecl TESEnchantableForm::*(BaseFormComponent*)
    // bool __cdecl TESEnchantableForm::*(BaseFormComponent*)
    // void __cdecl TESEnchantableForm::*(EnchantmentItem*)
    // GetFormEnchantmentAmount
    // void __cdecl TESEnchantableForm::*(unsigned short)
    // TESEnchantableForm& __cdecl TESEnchantableForm::*(const TESEnchantableForm&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESEnchantableForm) == 16);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_pEnchantment) == 4);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_usEnchantmentAmount) == 8);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_eCastingType) == 12);
#pragma pack(push, 4)
class TESValueForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned int iValue;  // +0x4, 4 bytes
    // TESValueForm
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*(BaseFormComponent*)
    // bool __cdecl TESValueForm::*(BaseFormComponent*)
    // void __cdecl TESValueForm::*(int)
    // SaveGame
    // LoadGame
    // TESValueForm& __cdecl TESValueForm::*(const TESValueForm&)
    // void* __cdecl TESValueForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESValueForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESValueForm, iValue) == 4);
#pragma pack(push, 4)
class TESWeightForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    float fWeight;  // +0x4, 4 bytes
    // TESWeightForm
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*()
    // void __cdecl TESWeightForm::*(BaseFormComponent*)
    // bool __cdecl TESWeightForm::*(BaseFormComponent*)
    // void __cdecl TESWeightForm::*(float)
    // TESWeightForm& __cdecl TESWeightForm::*(const TESWeightForm&)
    // void* __cdecl TESWeightForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESWeightForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESWeightForm, fWeight) == 4);
#pragma pack(push, 4)
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned short m_usAttackDamage;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // TESAttackDamageForm
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*()
    // void __cdecl TESAttackDamageForm::*(BaseFormComponent*)
    // bool __cdecl TESAttackDamageForm::*(BaseFormComponent*)
    virtual unsigned short GetAttackDamage();
    // void __cdecl TESAttackDamageForm::*(unsigned short)
    // TESAttackDamageForm& __cdecl TESAttackDamageForm::*(const TESAttackDamageForm&)
    // void* __cdecl TESAttackDamageForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAttackDamageForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESAttackDamageForm, m_usAttackDamage) == 4);
#pragma pack(push, 4)
class BGSAmmoForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESForm* m_pAmmo;  // +0x4, 4 bytes
    // BGSAmmoForm
    // void __cdecl BGSAmmoForm::*()
    // void __cdecl BGSAmmoForm::*()
    // void __cdecl BGSAmmoForm::*()
    // void __cdecl BGSAmmoForm::*(BaseFormComponent*)
    // bool __cdecl BGSAmmoForm::*(BaseFormComponent*)
    // void __cdecl BGSAmmoForm::*(TESForm*)
    // TESAmmo* __cdecl BGSAmmoForm::*()
    // TESAmmo* __cdecl BGSAmmoForm::*()
    // BGSListForm* __cdecl BGSAmmoForm::*()
    // const char* __cdecl BGSAmmoForm::*()
    // bool __cdecl BGSAmmoForm::*()
    // void __cdecl BGSAmmoForm::*(TESForm*)
    // BGSAmmoForm& __cdecl BGSAmmoForm::*(const BGSAmmoForm&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSAmmoForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSAmmoForm, m_pAmmo) == 4);
#pragma pack(push, 4)
class BGSClipRoundsForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned char m_ucClipRounds;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    // BGSClipRoundsForm
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*()
    // void __cdecl BGSClipRoundsForm::*(BaseFormComponent*)
    // bool __cdecl BGSClipRoundsForm::*(BaseFormComponent*)
    // GetClipRounds
    // void __cdecl BGSClipRoundsForm::*(int)
    // BGSClipRoundsForm& __cdecl BGSClipRoundsForm::*(const BGSClipRoundsForm&)
    // void* __cdecl BGSClipRoundsForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSClipRoundsForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSClipRoundsForm, m_ucClipRounds) == 4);
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    // BGSDestructibleObjectForm
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(BGSDestructibleObjectForm*, TESFile*)
    // void __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // bool __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // void __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CollisionComponent* __cdecl BGSDestructibleObjectForm::*()
    // unsigned char __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(unsigned int)
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // int __cdecl BGSDestructibleObjectForm::*(TESForm*, TESModel*)
    // TESModel* __cdecl BGSDestructibleObjectForm::*(TESForm*, int)
    // bool __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float, bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSExplosion*, unsigned int, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSDebris*, unsigned int, TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // bool __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, bool)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // bool __cdecl BGSDestructibleObjectForm::*(NiAVObject*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*)
    // void __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CalculateDangerousExplosionHealth
    // float __cdecl BGSDestructibleObjectForm::*(unsigned char, float, float, BGSExplosion**)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // NiTMap<TESObjectREFR *,unsigned int>* __cdecl BGSDestructibleObjectForm::*()
    // float __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(float)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // BGSDestructibleObjectForm& __cdecl BGSDestructibleObjectForm::*(const BGSDestructibleObjectForm&)
    // void* __cdecl BGSDestructibleObjectForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
#pragma pack(push, 4)
class BGSRepairItemList : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BGSListForm* pListForm;  // +0x4, 4 bytes
    // BGSRepairItemList
    // void __cdecl BGSRepairItemList::*()
    // void __cdecl BGSRepairItemList::*()
    // void __cdecl BGSRepairItemList::*()
    // void __cdecl BGSRepairItemList::*()
    // void __cdecl BGSRepairItemList::*(BaseFormComponent*)
    // bool __cdecl BGSRepairItemList::*(BaseFormComponent*)
    // void __cdecl BGSRepairItemList::*(TESForm*)
    // bool __cdecl BGSRepairItemList::*(TESForm*)
    // BSSimpleList<TESForm *>* __cdecl BGSRepairItemList::*(TESForm*)
    // BGSRepairItemList* __cdecl BGSRepairItemList::*(TESForm*)
    // bool __cdecl BGSRepairItemList::*(TESForm*, TESForm*)
    // BGSListForm* __cdecl BGSRepairItemList::*()
    // void __cdecl BGSRepairItemList::*(BGSListForm*)
    // BGSRepairItemList& __cdecl BGSRepairItemList::*(const BGSRepairItemList&)
    // void* __cdecl BGSRepairItemList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSRepairItemList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSRepairItemList, pListForm) == 4);
#pragma pack(push, 4)
class BGSEquipType : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BGSEquipType__EQUIP_TYPE m_eEquipType;  // +0x4, 4 bytes
    // BGSEquipType
    // void __cdecl BGSEquipType::*()
    // void __cdecl BGSEquipType::*()
    // void __cdecl BGSEquipType::*()
    // void __cdecl BGSEquipType::*(BaseFormComponent*)
    // bool __cdecl BGSEquipType::*(BaseFormComponent*)
    // GetEquipType
    // void __cdecl BGSEquipType::*(BGSEquipType::EQUIP_TYPE)
    // BGSMenuIcon* __cdecl BGSEquipType::*(BGSEquipType::EQUIP_TYPE)
    // const char* __cdecl BGSEquipType::*(BGSEquipType::EQUIP_TYPE)
    // void __cdecl BGSEquipType::*()
    // BGSEquipType& __cdecl BGSEquipType::*(const BGSEquipType&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEquipType) == 8);
FNV_STATIC_ASSERT(offsetof(BGSEquipType, m_eEquipType) == 4);
#pragma pack(push, 4)
class BGSPreloadable : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*(BaseFormComponent*)
    // bool __cdecl BGSPreloadable::*(BaseFormComponent*)
    // BGSPreloadable
    // BGSPreloadable& __cdecl BGSPreloadable::*(const BGSPreloadable&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPreloadable) == 4);
#pragma pack(push, 4)
class BGSMessageIcon : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESIcon Icon;  // +0x4, 12 bytes
    // BGSMessageIcon
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(CHUNK_ID)
    // void __cdecl BGSMessageIcon::*(BGSMessageIcon*, TESFile*)
    // void __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // bool __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // TESIcon* __cdecl BGSMessageIcon::*()
    // const char* __cdecl BGSMessageIcon::*()
    // unsigned int __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(const char*)
    // BGSMessageIcon& __cdecl BGSMessageIcon::*(const BGSMessageIcon&)
    // void* __cdecl BGSMessageIcon::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);
#pragma pack(push, 4)
class BGSBipedModelList : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BGSListForm* pListForm;  // +0x4, 4 bytes
    // BGSBipedModelList
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*(BaseFormComponent*)
    // bool __cdecl BGSBipedModelList::*(BaseFormComponent*)
    // void __cdecl BGSBipedModelList::*(TESForm*)
    // bool __cdecl BGSBipedModelList::*(TESForm*)
    // BGSBipedModelList* __cdecl BGSBipedModelList::*(TESForm*)
    // BGSListForm* __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*(BGSListForm*)
    // BGSBipedModelList& __cdecl BGSBipedModelList::*(const BGSBipedModelList&)
    // void* __cdecl BGSBipedModelList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSBipedModelList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSBipedModelList, pListForm) == 4);
#pragma pack(push, 4)
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
    // BGSPickupPutdownSounds
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*(TESFile*)
    // void __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // bool __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // void __cdecl BGSPickupPutdownSounds::*(TESForm*)
    // GetPickupSound
    // GetPutdownSound
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // BGSPickupPutdownSounds& __cdecl BGSPickupPutdownSounds::*(const BGSPickupPutdownSounds&)
    // void* __cdecl BGSPickupPutdownSounds::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 12);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPickupSound) == 4);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPutdownSound) == 8);
#pragma pack(push, 4)
class WeaponProperties
{
  public:
    char eType;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    float fSpeed;                       // +0x4, 4 bytes
    float ActorTypeValueEntry;          // +0x8, 4 bytes
    unsigned char cFlags;               // +0xC, 1 bytes
    unsigned char m_ucGripAnimation;    // +0xD, 1 bytes
    unsigned char m_ucAmmoUse;          // +0xE, 1 bytes
    unsigned char m_ucReloadAnimation;  // +0xF, 1 bytes
    float m_fMinimumSpread;             // +0x10, 4 bytes
    float fBodyPartChance;              // +0x14, 4 bytes
    float m_fUnknownFloat;              // +0x18, 4 bytes
    float AmmunitionData;               // +0x1C, 4 bytes
    unsigned char m_ucSubtype;          // +0x20, 1 bytes
    unsigned char layoutPadding21[3];
    BGSProjectile* pProjectile;                      // +0x24, 4 bytes
    unsigned char m_ucBaseVATSChance;                // +0x28, 1 bytes
    unsigned char m_ucAttackAnimation;               // +0x29, 1 bytes
    unsigned char m_ucProjectileCount;               // +0x2A, 1 bytes
    unsigned char m_ucFourthByte;                    // +0x2B, 1 bytes
    float m_fMinimumRange;                           // +0x2C, 4 bytes
    float m_fMaximumRange;                           // +0x30, 4 bytes
    WEAPONHITBEHAVIOR m_eHitBehavior;                // +0x34, 4 bytes
    unsigned int WeaponAttackData;                   // +0x38, 4 bytes
    float m_fAnimationAttackMultiplier;              // +0x3C, 4 bytes
    float fWeaponDamageMultiplier;                   // +0x40, 4 bytes
    float m_fOverrideActionPoints;                   // +0x44, 4 bytes
    float m_fLeftRumbleMotorStrength;                // +0x48, 4 bytes
    float m_fRightRumbleMotorStrength;               // +0x4C, 4 bytes
    float m_fRumbleDuration;                         // +0x50, 4 bytes
    float m_fOverrideDamageToWeaponMultiplier;       // +0x54, 4 bytes
    float m_fAttackShotsPerSecond;                   // +0x58, 4 bytes
    float WeaponCombatData;                          // +0x5C, 4 bytes
    float WeaponHandlingData;                        // +0x60, 4 bytes
    float WeaponFiringData;                          // +0x64, 4 bytes
    ActorValue__Index m_eWeaponSkill;                // +0x68, 4 bytes
    WEAPON_RUMBLE_PATTERN m_eRumblePattern;          // +0x6C, 4 bytes
    float WeaponFiringParameters;                    // +0x70, 4 bytes
    float m_fLimbDamageMultiplier;                   // +0x74, 4 bytes
    ActorValue__Index m_eResistanceType;             // +0x78, 4 bytes
    float m_fSightUsage;                             // +0x7C, 4 bytes
    float m_fMinimumSemiAutomaticFireDelay;          // +0x80, 4 bytes
    float m_fMaximumSemiAutomaticFireDelay;          // +0x84, 4 bytes
    float m_fFourthModifierValue;                    // +0x88, 4 bytes
    WEAPON_MOD_EFFECT m_eFirstWeaponModEffect;       // +0x8C, 4 bytes
    WEAPON_MOD_EFFECT m_eSecondWeaponModEffect;      // +0x90, 4 bytes
    WEAPON_MOD_EFFECT m_eThirdWeaponModEffect;       // +0x94, 4 bytes
    float m_fModValueA1;                             // +0x98, 4 bytes
    float m_fModValueA2;                             // +0x9C, 4 bytes
    float m_fModValueA3;                             // +0xA0, 4 bytes
    unsigned char m_ucPowerAttackAnimationOverride;  // +0xA4, 1 bytes
    unsigned char layoutPaddingA5[3];
    unsigned int m_uiStrengthRequirement;  // +0xA8, 4 bytes
    char m_cUnknownByte;                   // +0xAC, 1 bytes
    char m_cReloadAnimationMod;            // +0xAD, 1 bytes
    unsigned char layoutPaddingAE[2];
    float FlaggedFloatData;              // +0xB0, 4 bytes
    float m_fKillImpulse;                // +0xB4, 4 bytes
    float m_fModValueB1;                 // +0xB8, 4 bytes
    float m_fModValueB2;                 // +0xBC, 4 bytes
    float m_fModValueB3;                 // +0xC0, 4 bytes
    float FourFloatsAndUnsignedInteger;  // +0xC4, 4 bytes
    unsigned int m_uiSkillRequirement;   // +0xC8, 4 bytes
    // void __cdecl WeaponProperties::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WeaponProperties) == 204);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, eType) == 0);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, fSpeed) == 4);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, ActorTypeValueEntry) == 8);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, cFlags) == 12);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucGripAnimation) == 13);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucAmmoUse) == 14);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucReloadAnimation) == 15);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMinimumSpread) == 16);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, fBodyPartChance) == 20);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fUnknownFloat) == 24);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, AmmunitionData) == 28);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucSubtype) == 32);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, pProjectile) == 36);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucBaseVATSChance) == 40);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucAttackAnimation) == 41);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucProjectileCount) == 42);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucFourthByte) == 43);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMinimumRange) == 44);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMaximumRange) == 48);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eHitBehavior) == 52);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponAttackData) == 56);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fAnimationAttackMultiplier) == 60);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, fWeaponDamageMultiplier) == 64);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fOverrideActionPoints) == 68);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fLeftRumbleMotorStrength) == 72);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fRightRumbleMotorStrength) == 76);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fRumbleDuration) == 80);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fOverrideDamageToWeaponMultiplier) == 84);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fAttackShotsPerSecond) == 88);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponCombatData) == 92);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponHandlingData) == 96);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponFiringData) == 100);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eWeaponSkill) == 104);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eRumblePattern) == 108);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponFiringParameters) == 112);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fLimbDamageMultiplier) == 116);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eResistanceType) == 120);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fSightUsage) == 124);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMinimumSemiAutomaticFireDelay) == 128);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMaximumSemiAutomaticFireDelay) == 132);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fFourthModifierValue) == 136);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eFirstWeaponModEffect) == 140);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eSecondWeaponModEffect) == 144);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eThirdWeaponModEffect) == 148);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueA1) == 152);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueA2) == 156);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueA3) == 160);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucPowerAttackAnimationOverride) == 164);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_uiStrengthRequirement) == 168);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_cUnknownByte) == 172);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_cReloadAnimationMod) == 173);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, FlaggedFloatData) == 176);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fKillImpulse) == 180);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueB1) == 184);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueB2) == 188);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueB3) == 192);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, FourFloatsAndUnsignedInteger) == 196);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_uiSkillRequirement) == 200);
#pragma pack(push, 4)
class WeaponCriticalData
{
  public:
    unsigned short m_usCriticalDamage;  // +0x0, 2 bytes
    unsigned char layoutPadding2[2];
    float m_fCriticalChanceMultiplier;  // +0x4, 4 bytes
    bool m_bEffectOnDeath;              // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    SpellItem* pEffect;  // +0xC, 4 bytes
    // void __cdecl WeaponCriticalData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WeaponCriticalData) == 16);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, m_usCriticalDamage) == 0);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, m_fCriticalChanceMultiplier) == 4);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, m_bEffectOnDeath) == 8);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, pEffect) == 12);
#pragma pack(push, 4)
class WeaponVATSData
{
  public:
    SpellItem* m_pVATSAttackSpell;  // +0x0, 4 bytes
    float m_fSkill;                 // +0x4, 4 bytes
    float m_fDamageMultiplier;      // +0x8, 4 bytes
    float m_fActionPointCost;       // +0xC, 4 bytes
    bool bSilent;                   // +0x10, 1 bytes
    bool m_bModRequired;            // +0x11, 1 bytes
    unsigned char cFlags;           // +0x12, 1 bytes
    unsigned char layoutPadding13[1];
    // void __cdecl WeaponVATSData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WeaponVATSData) == 20);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_pVATSAttackSpell) == 0);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_fSkill) == 4);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_fDamageMultiplier) == 8);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_fActionPointCost) == 12);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, bSilent) == 16);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_bModRequired) == 17);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, cFlags) == 18);
#pragma pack(push, 4)
class TESObjectWEAP : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESAttackDamageForm,
                      public BGSAmmoForm,
                      public BGSClipRoundsForm,
                      public BGSDestructibleObjectForm,
                      public BGSRepairItemList,
                      public BGSEquipType,
                      public BGSPreloadable,
                      public BGSMessageIcon,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESIcon at +0x5C, size 12
    // base TESScriptableForm at +0x68, size 12
    // base TESEnchantableForm at +0x74, size 16
    // base TESValueForm at +0x84, size 8
    // base TESWeightForm at +0x8C, size 8
    // base TESHealthForm at +0x94, size 8
    // base TESAttackDamageForm at +0x9C, size 8
    // base BGSAmmoForm at +0xA4, size 8
    // base BGSClipRoundsForm at +0xAC, size 8
    // base BGSDestructibleObjectForm at +0xB4, size 8
    // base BGSRepairItemList at +0xBC, size 8
    // base BGSEquipType at +0xC4, size 8
    // base BGSPreloadable at +0xCC, size 4
    // base BGSMessageIcon at +0xD0, size 16
    // base BGSBipedModelList at +0xE0, size 8
    // base BGSPickupPutdownSounds at +0xE8, size 12
    int FUN_00446390();
    unsigned short GetShortAtOffset1C0();
    float GetField14C();
    float GetField150Float();
    float GetField154();
    bool IsRangedWeapon();
    bool GetIsAutomaticWeapon();
    bool GetBurstShot();
    int GetClipRounds(bool extended);
    TESAmmo* GetCurrentAmmo(Actor* actor);
    BGSProjectile* GetProjectileData(Actor* actor);
    float GetProjectileData();
    unsigned char GetDamageForActor(bool split, bool unknown, Actor* actor);
    WeaponProperties data;                         // +0xF4, 204 bytes
    WeaponCriticalData m_kCriticalData;            // +0x1C0, 16 bytes
    TESModel m_kModel;                             // +0x1D0, 24 bytes
    TESModel m_kModel1stPerson;                    // +0x1E8, 24 bytes
    TESModel m_kModel3rdPerson;                    // +0x200, 24 bytes
    TESEffectShader* m_pWeaponEffectShader;        // +0x218, 4 bytes
    TESSound* m_pWeaponSound1;                     // +0x21C, 4 bytes
    TESSound* m_pWeaponSound2;                     // +0x220, 4 bytes
    TESSound* m_pWeaponSound3;                     // +0x224, 4 bytes
    TESSound* m_pWeaponSound4;                     // +0x228, 4 bytes
    TESSound* m_pWeaponSound5;                     // +0x22C, 4 bytes
    TESSound* m_pWeaponSound6;                     // +0x230, 4 bytes
    TESSound* m_pWeaponSound7;                     // +0x234, 4 bytes
    TESSound* m_pWeaponSound8;                     // +0x238, 4 bytes
    TESSound* m_pWeaponUnequipSound;               // +0x23C, 4 bytes
    TESSound* m_pWeaponEquipSound;                 // +0x240, 4 bytes
    TESSound* m_pWeaponPickupSound;                // +0x244, 4 bytes
    TESSound* m_pWeaponDropSound;                  // +0x248, 4 bytes
    BGSImpactDataSet* m_pImpactDataSet;            // +0x24C, 4 bytes
    TESObjectSTAT* p1stPersonObject;               // +0x250, 4 bytes
    TESObjectSTAT* p1stPersonMod1Object;           // +0x254, 4 bytes
    TESObjectSTAT* p1stPersonMod2Object;           // +0x258, 4 bytes
    TESObjectSTAT* p1stPersonMod3Object;           // +0x25C, 4 bytes
    TESObjectSTAT* p1stPersonMod12Object;          // +0x260, 4 bytes
    TESObjectSTAT* p1stPersonMod23Object;          // +0x264, 4 bytes
    TESObjectSTAT* p1stPersonMod13Object;          // +0x268, 4 bytes
    TESObjectSTAT* p1stPersonMod123Object;         // +0x26C, 4 bytes
    TESModelTextureSwap m_kWeaponModTextureSwap1;  // +0x270, 32 bytes
    TESModelTextureSwap m_kWeaponModTextureSwap2;  // +0x290, 32 bytes
    TESModelTextureSwap m_kWeaponModTextureSwap3;  // +0x2B0, 32 bytes
    TESModelTextureSwap m_kWeaponModTextureSwap4;  // +0x2D0, 32 bytes
    TESModelTextureSwap m_kWeaponModTextureSwap5;  // +0x2F0, 32 bytes
    TESModelTextureSwap m_kWeaponModTextureSwap6;  // +0x310, 32 bytes
    TESModelTextureSwap m_kWeaponModTextureSwap7;  // +0x330, 32 bytes
    TESObjectIMOD* m_pWeaponMod1;                  // +0x350, 4 bytes
    TESObjectIMOD* m_pWeaponMod2;                  // +0x354, 4 bytes
    TESObjectIMOD* m_pWeaponMod3;                  // +0x358, 4 bytes
    BSStringT<char> m_kEmbeddedWeaponNodeName;     // +0x35C, 8 bytes
    SOUND_LEVEL m_eSoundLevel;                     // +0x364, 4 bytes
    BSStringT<char> VATSAttackName;                // +0x368, 8 bytes
    WeaponVATSData m_kVATSData;                    // +0x370, 20 bytes
    bool m_bHasReloadAnimation;                    // +0x384, 1 bytes
    unsigned char layoutPadding385[3];
    // TESObjectWEAP
    // void __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*()
    // bool __cdecl TESObjectWEAP::*(TESFile*)
    // void __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESForm*)
    // bool __cdecl TESObjectWEAP::*(TESForm*)
    // void __cdecl TESObjectWEAP::*()
    // WeaponProperties* __cdecl TESObjectWEAP::*()
    // float __cdecl TESObjectWEAP::*(unsigned int, unsigned char)
    // void __cdecl TESObjectWEAP::*(unsigned int, float, unsigned char)
    // WEAPON_MOD_EFFECT __cdecl TESObjectWEAP::*(unsigned int)
    // void __cdecl TESObjectWEAP::*(unsigned int, WEAPON_MOD_EFFECT)
    // TESObjectIMOD* __cdecl TESObjectWEAP::*(unsigned int)
    // void __cdecl TESObjectWEAP::*(unsigned int, TESObjectIMOD*)
    // TESObjectSTAT* __cdecl TESObjectWEAP::*(unsigned char)
    // void __cdecl TESObjectWEAP::*(unsigned char, TESObjectSTAT*)
    // float __cdecl TESObjectWEAP::*(WEAPON_MOD_EFFECT, unsigned char)
    // ANIM_GROUP_ENUM __cdecl TESObjectWEAP::*()
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(ANIM_GROUP_ENUM)
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // int __cdecl TESObjectWEAP::*(bool)
    // float __cdecl TESObjectWEAP::*(bool)
    // int __cdecl TESObjectWEAP::*(bool)
    // float __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(float)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // const char* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(const char*)
    // const char* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(const char*)
    // ActorValue::Index __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(ActorValue::Index)
    // unsigned char __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(unsigned char)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // unsigned char __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(unsigned char)
    // unsigned char __cdecl TESObjectWEAP::*(bool, bool, Actor*)
    // void __cdecl TESObjectWEAP::*(unsigned char)
    // float __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // ANIM_GROUP_ENUM __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(ANIM_GROUP_ENUM)
    // ANIM_GROUP_ENUM __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(ANIM_GROUP_ENUM)
    // ANIM_GROUP_ENUM __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(ANIM_GROUP_ENUM)
    // ANIM_GROUP_ENUM __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(ANIM_GROUP_ENUM)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // unsigned char __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(unsigned char)
    // GetProjectileData
    // void __cdecl TESObjectWEAP::*(BGSProjectile*)
    // unsigned short __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(unsigned short)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // SpellItem* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(SpellItem*)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // SpellItem* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(SpellItem*)
    // TESSound* __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // TESSound* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESSound*)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // BGSImpactDataSet* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(BGSImpactDataSet*)
    // WEAPONHITBEHAVIOR __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(WEAPONHITBEHAVIOR)
    // TESObjectSTAT* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESObjectSTAT*)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // int __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(int)
    // bool __cdecl TESObjectWEAP::*(unsigned int)
    // int __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(int)
    // bool __cdecl TESObjectWEAP::*(unsigned int)
    // WEAPON_RUMBLE_PATTERN __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(WEAPON_RUMBLE_PATTERN)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // BGSTextureSet* __cdecl TESObjectWEAP::*(MATERIAL_TYPE)
    // BGSImpactData* __cdecl TESObjectWEAP::*(MATERIAL_TYPE)
    // TESModel& __cdecl TESObjectWEAP::*()
    // TESModel* __cdecl TESObjectWEAP::*()
    // TESEffectShader* __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(TESEffectShader*)
    // TESModel* __cdecl TESObjectWEAP::*()
    // TESModel* __cdecl TESObjectWEAP::*(unsigned char)
    // int __cdecl TESObjectWEAP::*(float, bool, bool, int, float, float, bool, bool)
    // ActorValue::Index __cdecl TESObjectWEAP::*()
    // float __cdecl TESObjectWEAP::*(Animation*)
    // float __cdecl TESObjectWEAP::*(Animation*)
    // float __cdecl TESObjectWEAP::*(Animation*)
    // ActorValue::Index __cdecl TESObjectWEAP::*()
    // WEAPON_TYPE __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(WEAPON_TYPE)
    // bool __cdecl TESObjectWEAP::*()
    // bool __cdecl TESObjectWEAP::*()
    // bool __cdecl TESObjectWEAP::*()
    // bool __cdecl TESObjectWEAP::*()
    // bool __cdecl TESObjectWEAP::*()
    // MagicSystem::CastingType __cdecl TESObjectWEAP::*()
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // bool __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(bool)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // float __cdecl TESObjectWEAP::*()
    // void __cdecl TESObjectWEAP::*(float)
    // SOUND_LEVEL __cdecl TESObjectWEAP::*(bool)
    // int __cdecl TESObjectWEAP::*(bool)
    // void __cdecl TESObjectWEAP::*(SOUND_LEVEL)
    // COMBAT_WEAPON_TYPE __cdecl TESObjectWEAP::*()
    // const char* __cdecl TESObjectWEAP::*()
    // NiAVObject* __cdecl TESObjectWEAP::*(NiAVObject*)
    // char* __cdecl TESObjectWEAP::*()
    // NiPoint3 __cdecl TESObjectWEAP::*(TESObjectREFR*)
    // TESAmmo* __cdecl TESObjectWEAP::*(Actor*)
    // bool __cdecl TESObjectWEAP::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // void __cdecl TESObjectWEAP::*(TESObjectREFR*)
    // void __cdecl TESObjectWEAP::*(TESObjectREFR*)
    // unsigned short __cdecl TESObjectWEAP::*(unsigned int)
    // SaveGame
    // LoadGame
    // TESObjectWEAP& __cdecl TESObjectWEAP::*(const TESObjectWEAP&)
    // void __cdecl TESObjectWEAP::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObjectWEAP) == 904);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, data) == 244);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kCriticalData) == 448);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kModel) == 464);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kModel1stPerson) == 488);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kModel3rdPerson) == 512);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponEffectShader) == 536);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound1) == 540);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound2) == 544);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound3) == 548);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound4) == 552);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound5) == 556);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound6) == 560);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound7) == 564);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound8) == 568);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponUnequipSound) == 572);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponEquipSound) == 576);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponPickupSound) == 580);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponDropSound) == 584);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pImpactDataSet) == 588);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonObject) == 592);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod1Object) == 596);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod2Object) == 600);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod3Object) == 604);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod12Object) == 608);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod23Object) == 612);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod13Object) == 616);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod123Object) == 620);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap1) == 624);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap2) == 656);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap3) == 688);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap4) == 720);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap5) == 752);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap6) == 784);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap7) == 816);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponMod1) == 848);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponMod2) == 852);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponMod3) == 856);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kEmbeddedWeaponNodeName) == 860);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_eSoundLevel) == 868);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, VATSAttackName) == 872);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kVATSData) == 880);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_bHasReloadAnimation) == 900);
#endif
