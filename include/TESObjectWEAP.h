#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#include "TESEnchantableForm.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
#include "TESHealthForm.h"
#include "TESAttackDamageForm.h"
#include "BGSAmmoForm.h"
#include "BGSClipRoundsForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSRepairItemList.h"
#include "BGSEquipType.h"
#include "BGSPreloadable.h"
#include "BGSMessageIcon.h"
#include "BGSBipedModelList.h"
#include "BGSPickupPutdownSounds.h"
#include "TESModel.h"
#include "WeaponProperties.h"
#include "WeaponCriticalData.h"
#include "WeaponVATSData.h"

class Actor;
class BGSImpactDataSet;
class BGSProjectile;
class PlayerCharacter;
class QueuedFile;
class SpellItem;
class TESAmmo;
class TESEffectShader;
class TESObjectIMOD;
class TESObjectSTAT;
class TESSound;

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
    enum SOUND_LEVEL;

    TESObjectWEAP();
    virtual ~TESObjectWEAP();
    virtual void ClearData();
    virtual void InitItem();

    void ResetFormData();
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x102c51c slot 8 = 0x51f630)
    bool LoadForm(TESFile* file);
    void QueueResourceLoad(int priority, QueuedFile* file, bool flag);
    unsigned short GetShortAtOffset1C0();
    float GetField14C();
    float GetField150Float();
    float GetField154();
    bool IsRangedWeapon();
    bool GetIsAutomaticWeapon();
    unsigned int FUN_0051f5f0(); // 0x0051f5f0
    bool GetBurstShot();
    int GetClipRounds(bool extended);
    TESAmmo* GetCurrentAmmo(Actor* actor);
    BGSProjectile* GetProjectileData(Actor* actor);
    float GetProjectileData();
    unsigned char GetDamageForActor(bool split, bool unknown, Actor* actor);
    void SetModItem(unsigned int slot, TESObjectIMOD* item);
    void SetModItem(unsigned char slot, TESObjectIMOD* item);
    int GetWeaponType() const;
    int GetWeaponType();
    int GetCombatWeaponType();
    int TESObjectWEAP_GetCombatWeaponType();
    int GetReloadAnim(bool modded);
    int GetFlaggedValue(unsigned char value);
    int GetField19C();
    bool GetHideBackpack();
    bool GetHasScope();
    bool GetHasModScope();
    TESModel* GetWeaponModel();
    TESModel* GetModTESModel(unsigned char mods, bool flag);
    TESSound* GetField238();
    TESSound* GetField23C();
    void Fire(TESObjectREFR* reference);
    bool IsRanged();
    bool IsMelee();
    int GetModdedValue(bool flag);
    unsigned char GetAmmoPerShot();
    bool IsPlayable();
    void SetByteAtOffsetF4(int value);
    int GetUnk15C();
    ActorValue__Index GetResistance();
    float GetModdedWeaponValue(WEAPON_MOD_EFFECT effect, unsigned char value);
    float GetModdedWeaponValue(WEAPON_MOD_EFFECT effect, unsigned char value) const;
    SpellItem* GetField1CC();
    SpellItem* GetVATSSpecialEffect();
    TESEffectShader* GetScopeEffect();
    void SetEffectShader(TESEffectShader* shader);
    void SetNPCsUseAmmo(bool value);
    void SetModObject(unsigned char slot, TESObjectSTAT* object);
    TESSound* GetAttackSound(bool modded);
    void SetAttackSound(TESSound* sound);
    void SetDistantAttackSound(TESSound* sound);
    void SetModAttackSound(TESSound* sound);
    TESSound* GetModDistantAttackSound();
    void SetAttackFailSound(TESSound* sound);
    void SetMeleeBlockSound(TESSound* sound);
    void SetIdleSound(TESSound* sound);
    void SetEquipSound(TESSound* sound);
    void SetUnequipSound(TESSound* sound);
    void Set1stPersonObject(TESObjectSTAT* object);
    void SetAttackSound2(TESSound* sound);
    void SetModAttackSound2(TESSound* sound);
    void SetModDistantAttackSound2(TESSound* sound);
    void SetImpactDataSet(BGSImpactDataSet* dataSet);
    float GetWeightForForm(bool modded);

    int FUN_00446390();
    TESBoundObject* TESObjectWEAP_GetCurrentAmmo(PlayerCharacter* pc);
    void* TESObjectWEAP_GetCurrentAmmo(int value);
    int FUN_0051e2a0(unsigned char value);
    float GetAttackSpeed(bool modded);
    float GetAmmoRegenRate(bool modded);
    float GetAmmoRegenRate(int value);
    int FUN_00525b20(int first, int second, int third);
    TESModel* TESCasino_GetData();
    bool FUN_004c94d0();
    bool IsTwoHandedWeapon();
    bool TESObjectWEAP_IsThrownWeapon();
    bool FUN_004ad030();
    bool TESObjectWEAP_IsEmbeddedWeapon();
    void TESCreature_SetMaterialType(BGSProjectile* projectile);
    void UpdateState_0051f4f0(SpellItem* effect);
    void TESObjectWEAP_SetVATSEffect(SpellItem* effect);
    void TESObjectWEAP_SetNumProjectiles(unsigned char value);
    void TESObjectWEAP_SetAttackLoop(TESSound* sound);

    WeaponProperties data;
    WeaponCriticalData m_kCriticalData;
    TESModel m_kModel;
    TESModel m_kModel1stPerson;
    TESModel m_kModel3rdPerson;
    TESEffectShader* m_pWeaponEffectShader;
    TESSound* m_pWeaponSound1;
    TESSound* m_pWeaponSound2;
    TESSound* m_pWeaponSound3;
    TESSound* m_pWeaponSound4;
    TESSound* m_pWeaponSound5;
    TESSound* m_pWeaponSound6;
    TESSound* m_pWeaponSound7;
    TESSound* m_pWeaponSound8;
    TESSound* m_pWeaponUnequipSound;
    TESSound* m_pWeaponEquipSound;
    TESSound* m_pWeaponPickupSound;
    TESSound* m_pWeaponDropSound;
    BGSImpactDataSet* m_pImpactDataSet;
    TESObjectSTAT* p1stPersonObject;
    TESObjectSTAT* p1stPersonMod1Object;
    TESObjectSTAT* p1stPersonMod2Object;
    TESObjectSTAT* p1stPersonMod3Object;
    TESObjectSTAT* p1stPersonMod12Object;
    TESObjectSTAT* p1stPersonMod23Object;
    TESObjectSTAT* p1stPersonMod13Object;
    TESObjectSTAT* p1stPersonMod123Object;
    TESModelTextureSwap m_kWeaponModTextureSwap1;
    TESModelTextureSwap m_kWeaponModTextureSwap2;
    TESModelTextureSwap m_kWeaponModTextureSwap3;
    TESModelTextureSwap m_kWeaponModTextureSwap4;
    TESModelTextureSwap m_kWeaponModTextureSwap5;
    TESModelTextureSwap m_kWeaponModTextureSwap6;
    TESModelTextureSwap m_kWeaponModTextureSwap7;
    TESObjectIMOD* m_pWeaponMod1;
    TESObjectIMOD* m_pWeaponMod2;
    TESObjectIMOD* m_pWeaponMod3;
    BSStringT<char> m_kEmbeddedWeaponNodeName;
    SOUND_LEVEL m_eSoundLevel;
    BSStringT<char> VATSAttackName;
    WeaponVATSData m_kVATSData;
    bool m_bHasReloadAnimation;
    unsigned char layoutPadding385[3];
};
