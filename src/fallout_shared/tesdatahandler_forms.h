// Unit form utilities, container support, and layout checks.
#ifndef FNV_TESDATAHANDLER_FORMS_H
#define FNV_TESDATAHANDLER_FORMS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class NiNode;
#include "../../include/ENUM_FORM_ID.h"

class TESFormInitFlag
{
  public:
    static TESForm* LookupFormByEditorID(const char*);
    static TESForm* GetFormByID(unsigned int);
};
class TESFormList
{
  public:
    TESObject* AddToObjectList(TESObject*);
    TESObject* GetFirst();
};

typedef char check_TESObjectACTI_size[(sizeof(TESObjectACTI) == 0x90) ? 1 : -1];
typedef char check_BGSTalkingActivator_size[(sizeof(BGSTalkingActivator) == 0x98) ? 1 : -1];
typedef char check_BGSTerminal_size[(sizeof(BGSTerminal) == 0xa8) ? 1 : -1];
typedef char check_TESObjectARMO_size[(sizeof(TESObjectARMO) == 0x190) ? 1 : -1];
typedef char check_TESObjectARMA_size[(sizeof(TESObjectARMA) == 0x190) ? 1 : -1];
typedef char check_TESObjectBOOK_size[(sizeof(TESObjectBOOK) == 0xc4) ? 1 : -1];
typedef char check_TESObjectCLOT_size[(sizeof(TESObjectCLOT) == 0x154) ? 1 : -1];
typedef char check_TESObjectCONT_size[(sizeof(TESObjectCONT) == 0x9c) ? 1 : -1];
typedef char check_TESObjectDOOR_size[(sizeof(TESObjectDOOR) == 0x90) ? 1 : -1];
typedef char check_IngredientItem_size[(sizeof(IngredientItem) == 0xa4) ? 1 : -1];
typedef char check_TESObjectLIGH_size[(sizeof(TESObjectLIGH) == 0xc8) ? 1 : -1];
typedef char check_TESObjectMISC_size[(sizeof(TESObjectMISC) == 0xac) ? 1 : -1];
typedef char check_TESObjectIMOD_size[(sizeof(TESObjectIMOD) == 0xb0) ? 1 : -1];
typedef char check_BGSConstructibleObject_size[(sizeof(BGSConstructibleObject) == 0xb4) ? 1 : -1];
typedef char check_TESKey_size[(sizeof(TESKey) == 0xac) ? 1 : -1];
typedef char check_TESObjectSTAT_size[(sizeof(TESObjectSTAT) == 0x58) ? 1 : -1];
typedef char check_BGSStaticCollection_size[(sizeof(BGSStaticCollection) == 0x50) ? 1 : -1];
typedef char check_BGSPlaceableWater_size[(sizeof(BGSPlaceableWater) == 0x50) ? 1 : -1];
typedef char check_TESGrass_size[(sizeof(TESGrass) == 0x68) ? 1 : -1];
typedef char check_TESIdleForm_size[(sizeof(TESIdleForm) == 0x54) ? 1 : -1];
typedef char check_BGSCameraPath_size[(sizeof(BGSCameraPath) == 0x38) ? 1 : -1];
typedef char check_BGSIdleMarker_size[(sizeof(BGSIdleMarker) == 0x40) ? 1 : -1];
typedef char check_TESPackage_size[(sizeof(TESPackage) == 0x80) ? 1 : -1];
typedef char check_TESObjectTREE_size[(sizeof(TESObjectTREE) == 0x94) ? 1 : -1];
typedef char check_TESFurniture_size[(sizeof(TESFurniture) == 0x94) ? 1 : -1];
typedef char check_TESObjectWEAP_size[(sizeof(TESObjectWEAP) == 0x388) ? 1 : -1];
typedef char check_TESAmmo_size[(sizeof(TESAmmo) == 0xdc) ? 1 : -1];
class ActorBaseData
{
  public:
    bool FUN_00461560();
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10(bool);
};
typedef char check_TESNPC_size[(sizeof(TESNPC) == 0x20c) ? 1 : -1];
typedef char check_TESCreature_size[(sizeof(TESCreature) == 0x160) ? 1 : -1];
typedef char check_TESLevCreature_size[(sizeof(TESLevCreature) == 0x70) ? 1 : -1];
typedef char check_TESLevCharacter_size[(sizeof(TESLevCharacter) == 0x70) ? 1 : -1];
typedef char check_SpellItem_size[(sizeof(SpellItem) == 0x44) ? 1 : -1];
typedef char check_EnchantmentItem_size[(sizeof(EnchantmentItem) == 0x44) ? 1 : -1];
typedef char check_AlchemyItem_size[(sizeof(AlchemyItem) == 0xd8) ? 1 : -1];
typedef char check_TESLevItem_size[(sizeof(TESLevItem) == 0x4c) ? 1 : -1];
typedef char check_TESObjectREFR_size[(sizeof(TESObjectREFR) == 0x68) ? 1 : -1];
typedef char check_BGSNote_size[(sizeof(BGSNote) == 0x80) ? 1 : -1];
typedef char check_BGSMenuIcon_size[(sizeof(BGSMenuIcon) == 0x24) ? 1 : -1];
typedef char check_BGSListForm_size[(sizeof(BGSListForm) == 0x24) ? 1 : -1];
typedef char check_BGSHeadPart_size[(sizeof(BGSHeadPart) == 0x50) ? 1 : -1];
typedef char check_TESHair_size[(sizeof(TESHair) == 0x4c) ? 1 : -1];
typedef char check_TESEyes_size[(sizeof(TESEyes) == 0x34) ? 1 : -1];
typedef char check_TESRace_size[(sizeof(TESRace) == 0x524) ? 1 : -1];
typedef char check_BGSEncounterZone_size[(sizeof(BGSEncounterZone) == 0x30) ? 1 : -1];
typedef char check_TESClass_size[(sizeof(TESClass) == 0x60) ? 1 : -1];
typedef char check_TESFaction_size[(sizeof(TESFaction) == 0x4c) ? 1 : -1];
typedef char check_TESReputation_size[(sizeof(TESReputation) == 0x50) ? 1 : -1];
typedef char check_TESChallenge_size[(sizeof(TESChallenge) == 0x7c) ? 1 : -1];
typedef char check_TESSound_size[(sizeof(TESSound) == 0x6c) ? 1 : -1];
typedef char check_BGSAcousticSpace_size[(sizeof(BGSAcousticSpace) == 0x54) ? 1 : -1];
typedef char check_TESGlobal_size[(sizeof(TESGlobal) == 0x28) ? 1 : -1];
typedef char check_BGSVoiceType_size[(sizeof(BGSVoiceType) == 0x24) ? 1 : -1];
typedef char check_BGSImpactData_size[(sizeof(BGSImpactData) == 0x78) ? 1 : -1];
typedef char check_BGSImpactDataSet_size[(sizeof(BGSImpactDataSet) == 0x4c) ? 1 : -1];
typedef char check_EffectSetting_size[(sizeof(EffectSetting) == 0xb0) ? 1 : -1];
typedef char check_TESClimate_size[(sizeof(TESClimate) == 0x58) ? 1 : -1];
typedef char check_TESImageSpace_size[(sizeof(TESImageSpace) == 0xb0) ? 1 : -1];
typedef char check_TESImageSpaceModifier_size[(sizeof(TESImageSpaceModifier) == 0x730) ? 1 : -1];
typedef char check_TESWeather_size[(sizeof(TESWeather) == 0x36c) ? 1 : -1];
typedef char check_TESWorldSpace_size[(sizeof(TESWorldSpace) == 0xec) ? 1 : -1];
typedef char check_TESObjectCELL_size[(sizeof(TESObjectCELL) == 0xe0) ? 1 : -1];
typedef char check_TESSkill_size[(sizeof(TESSkill) == 0x60) ? 1 : -1];
typedef char check_TESLandTexture_size[(sizeof(TESLandTexture) == 0x28) ? 1 : -1];
typedef char check_BGSCameraShot_size[(sizeof(BGSCameraShot) == 0x78) ? 1 : -1];
typedef char check_TESQuest_size[(sizeof(TESQuest) == 0x6c) ? 1 : -1];
typedef char check_TESRegion_size[(sizeof(TESRegion) == 0x38) ? 1 : -1];
typedef char check_Script_size[(sizeof(Script) == 0x54) ? 1 : -1];
typedef char check_TESCombatStyle_size[(sizeof(TESCombatStyle) == 0x108) ? 1 : -1];
typedef char check_TESLoadScreen_size[(sizeof(TESLoadScreen) == 0x40) ? 1 : -1];
typedef char check_TESWaterForm_size[(sizeof(TESWaterForm) == 0x194) ? 1 : -1];
typedef char check_TESLevSpell_size[(sizeof(TESLevSpell) == 0x4c) ? 1 : -1];
typedef char check_TESObjectANIO_size[(sizeof(TESObjectANIO) == 0x3c) ? 1 : -1];
typedef char check_TESObjectLAND_size[(sizeof(TESObjectLAND) == 0x2c) ? 1 : -1];
typedef char check_TESEffectShader_size[(sizeof(TESEffectShader) == 0x170) ? 1 : -1];
typedef char check_BGSProjectile_size[(sizeof(BGSProjectile) == 0xd0) ? 1 : -1];
typedef char check_BGSExplosion_size[(sizeof(BGSExplosion) == 0xa8) ? 1 : -1];
typedef char check_BGSDebris_size[(sizeof(BGSDebris) == 0x24) ? 1 : -1];
typedef char check_BGSTextureSet_size[(sizeof(BGSTextureSet) == 0xa0) ? 1 : -1];
typedef char check_NavMesh_size[(sizeof(NavMesh) == 0x108) ? 1 : -1];
typedef char check_BGSPerk_size[(sizeof(BGSPerk) == 0x50) ? 1 : -1];
typedef char check_BGSBodyPartData_size[(sizeof(BGSBodyPartData) == 0x74) ? 1 : -1];
typedef char check_BGSAddonNode_size[(sizeof(BGSAddonNode) == 0x60) ? 1 : -1];
typedef char check_ActorValueInfo_size[(sizeof(ActorValueInfo) == 0xc4) ? 1 : -1];
typedef char check_BGSRadiationStage_size[(sizeof(BGSRadiationStage) == 0x20) ? 1 : -1];
typedef char check_BGSDehydrationStage_size[(sizeof(BGSDehydrationStage) == 0x20) ? 1 : -1];
typedef char check_BGSHungerStage_size[(sizeof(BGSHungerStage) == 0x20) ? 1 : -1];
class BGSSleepDeprivationStage : public TESForm
{
  public:
    BGSSleepDeprivationStage();
    unsigned char formData[0x8];
};
typedef char check_BGSSleepDeprivationStage_size[(sizeof(BGSSleepDeprivationStage) == 0x20) ? 1 : -1];
typedef char check_BGSMessage_size[(sizeof(BGSMessage) == 0x40) ? 1 : -1];
typedef char check_BGSRagdoll_size[(sizeof(BGSRagdoll) == 0x148) ? 1 : -1];
typedef char check_BGSLightingTemplate_size[(sizeof(BGSLightingTemplate) == 0x44) ? 1 : -1];
typedef char check_BGSMusicType_size[(sizeof(BGSMusicType) == 0x34) ? 1 : -1];
class BGSRecipe : public TESForm
{
  public:
    BGSRecipe();
    unsigned char formData[0x44];
};
typedef char check_BGSRecipe_size[(sizeof(BGSRecipe) == 0x5c) ? 1 : -1];
class BGSRecipeCategory : public TESForm
{
  public:
    BGSRecipeCategory();
    unsigned char formData[0x10];
};
typedef char check_BGSRecipeCategory_size[(sizeof(BGSRecipeCategory) == 0x28) ? 1 : -1];
typedef char check_TESAmmoEffect_size[(sizeof(TESAmmoEffect) == 0x30) ? 1 : -1];
typedef char check_TESCasinoChips_size[(sizeof(TESCasinoChips) == 0x9c) ? 1 : -1];
typedef char check_TESLoadScreenType_size[(sizeof(TESLoadScreenType) == 0x70) ? 1 : -1];
typedef char check_TESCasino_size[(sizeof(TESCasino) == 0x220) ? 1 : -1];
typedef char check_MediaSet_size[(sizeof(MediaSet) == 0xc4) ? 1 : -1];
typedef char check_MediaLocationController_size[(sizeof(MediaLocationController) == 0xb8) ? 1 : -1];
typedef char check_TESCaravanCard_size[(sizeof(TESCaravanCard) == 0xbc) ? 1 : -1];
typedef char check_TESCaravanMoney_size[(sizeof(TESCaravanMoney) == 0xcc) ? 1 : -1];
typedef char check_TESCaravanDeck_size[(sizeof(TESCaravanDeck) == 0x2c) ? 1 : -1];
typedef char check_BGSMovableStatic_size[(sizeof(BGSMovableStatic) == 0x74) ? 1 : -1];
typedef char check_TESFlora_size[(sizeof(TESFlora) == 0x9c) ? 1 : -1];
const char* GetStringForByte(unsigned char);
int Warning(const char*, ...);
#include "../../include/NiTMallocInterface.h"


extern TES* g_TES;
void RegisterEffectSetting(EffectSetting*);
#endif
