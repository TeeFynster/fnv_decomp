// fallout_shared/tesdatahandler.cpp: TESDataHandler, TESFormInitFlag, BSFlags, EnchantmentItem and more (121 functions)

#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTPointerList.h"
#include "../../include/TESSaveLoadGame.h"
#include "../../include/NiTArray.h"
template <class T> class NiTMallocInterface;
#include "../../include/NiTArray.h"

#include "../../include/BaseFormComponent.h"
#include "../../include/InventoryChanges.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiNode.h"
#include "../../include/Actor.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"
#include "../../include/StartMenu.h"

// PathfindQueueStorage_tesdatahandler: local type (was include/PathfindQueueStorage.h, which had no evidence of one real class); its methods are 0x0096aaf0 ProcessArray::RemoveActor (Xbox PDB)
class MobileObject;

class PathfindQueueStorage_tesdatahandler
{
public:
    void ProcessArray_RemoveActor_0096aaf0(MobileObject* apObject, int aeLevel);
};
// ActorDeletionQueue_tesdatahandler: local type (was include/ActorDeletionQueue.h, which had no evidence of one real class); its methods are 0x0096d450 ProcessLists::AddReference, 0x0096d470 ProcessLists::RemoveReference, 0x0096d490 ProcessLists::GetSystemTimeClock (Xbox PDB)

class MobileObject;
class ActorSV;
struct ReferenceView;

class ActorDeletionQueue_tesdatahandler
{
public:
    unsigned int pad;
    PathfindQueueStorage_tesdatahandler storage;
    unsigned char unk05[3];

    void ProcessLists_RemoveReference(MobileObject*, int);
    void ProcessLists_RemoveReference(ActorSV*, int);
    void ProcessLists_RemoveReference(ReferenceView*, int);
    float ProcessLists_GetSystemTimeClock();
    void ProcessLists_AddReference(MobileObject*, int, bool, bool, bool);
    void ProcessLists_AddReference(ActorSV*, int, bool, bool, ActorSV*);
};
#include "../../include/ActorValueInfo.h"
#include "../../include/AlchemyItem.h"
#include "../../include/AutoMemContext.h"
#include "../../include/BGSAcousticSpace.h"
#include "../../include/BGSAddonNode.h"
#include "../../include/BGSBodyPartData.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSCameraShot.h"
#include "../../include/BGSConstructibleObject.h"
#include "../../include/BGSDebris.h"
#include "../../include/BGSDefaultObjectManager.h"
#include "../../include/BGSDehydrationStage.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSEncounterZone.h"
#include "../../include/BGSExplosion.h"
#include "../../include/BGSHeadPart.h"
#include "../../include/BGSHungerStage.h"
#include "../../include/BGSIdleMarker.h"
#include "../../include/BGSImpactData.h"
#include "../../include/BGSImpactDataSet.h"
#include "../../include/BGSLightingTemplate.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSMenuIcon.h"
#include "../../include/BGSMessage.h"
#include "../../include/BGSMovableStatic.h"
#include "../../include/BGSMusicType.h"
#include "../../include/BGSNote.h"
#include "../../include/BGSPerk.h"
#include "../../include/BGSPlaceableWater.h"
#include "../../include/BGSProjectile.h"
#include "../../include/BGSRadiationStage.h"
#include "../../include/BGSRagdoll.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/BGSStaticCollection.h"
#include "../../include/BGSTalkingActivator.h"
#include "../../include/BGSTerminal.h"
#include "../../include/BGSTextureSet.h"
#include "../../include/BGSVoiceType.h"
#include "../../include/BSThread.h"
#include "../../include/EffectItemList.h"
#include "../../include/EffectSetting.h"
#include "../../include/EnchantmentItem.h"
#include "../../include/ExtraDataList.h"
#include "../../include/GameSettingCollection.h"
#include "../../include/IngredientItem.h"
#include "../../include/MediaLocationController.h"
#include "../../include/MediaSet.h"
#include "../../include/MobileObject.h"
#include "../../include/NavMesh.h"
#include "../../include/NavMeshCollection.h"
#include "../../include/NavMeshInfoMap.h"
#include "../../include/NiPoint3.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/Script.h"
#include "../../include/Sky.h"
#include "../../include/SpellItem.h"
#include "../../include/TES.h"
#include "../../include/TESAmmo.h"
#include "../../include/TESAmmoEffect.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESCaravanCard.h"
#include "../../include/TESCaravanDeck.h"
#include "../../include/TESCaravanMoney.h"
#include "../../include/TESCasino.h"
#include "../../include/TESCasinoChips.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESClass.h"
#include "../../include/TESClimate.h"
#include "../../include/TESCombatStyle.h"
#include "../../include/TESCreature.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESEffectShader.h"
#include "../../include/TESEyes.h"
#include "../../include/TESFaction.h"
#include "../../include/TESFile.h"
#include "../../include/TESFlora.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESFurniture.h"
#include "../../include/TESGlobal.h"
#include "../../include/TESGrass.h"
#include "../../include/TESHair.h"
#include "../../include/TESIdleForm.h"
#include "../../include/TESImageSpace.h"
#include "../../include/TESImageSpaceModifier.h"
#include "../../include/TESKey.h"
#include "../../include/TESLandTexture.h"
#include "../../include/TESLevCharacter.h"
#include "../../include/TESLevCreature.h"
#include "../../include/TESLevItem.h"
#include "../../include/TESLevSpell.h"
#include "../../include/TESLoadScreen.h"
#include "../../include/TESLoadScreenType.h"
#include "../../include/TESModel.h"
#include "../../include/TESNPC.h"
#include "../../include/TESObject.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectANIO.h"
#include "../../include/TESObjectARMA.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESObjectBOOK.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectCLOT.h"
#include "../../include/TESObjectCONT.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectIMOD.h"
#include "../../include/TESObjectLAND.h"
#include "../../include/TESObjectLIGH.h"
#include "../../include/TESObjectMISC.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectSTAT.h"
#include "../../include/TESObjectTREE.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESPackage.h"
#include "../../include/TESProduceForm.h"
#include "../../include/TESQuest.h"
#include "../../include/TESRace.h"
#include "../../include/TESReactionForm.h"
#include "../../include/TESRegion.h"
#include "../../include/TESRegionList.h"
#include "../../include/TESReputation.h"
#include "../../include/TESSkill.h"
#include "../../include/TESSound.h"
#include "../../include/TESTopic.h"
#include "../../include/TESTopicInfo.h"
#include "../../include/TESWaterForm.h"
#include "../../include/TESWeather.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/BSSimpleList.h"
#include "../../include/NiPointer.h"
#include "../../include/NiMemObject.h"
#include "../../include/BSFile.h"

#include "tesdatahandler_decls.h"
struct FNVFile;
struct TESDataHandlerUnitOperations : public TESDataHandler
{
    void InitializeCellData();
    TESObjectCELL* CreateExteriorCell(const char*, int, int, TESWorldSpace*);
    TESForm* FindFormByEditorID(const char*);
    void SetCellQueueProcessing(bool);
    void ClearPendingReferences();
    void ValidateFormIcons();
    void UpdateInventoryForReference(int);
    void ProcessInventoryRecords(FNVFile*, int, int);
};

int __fastcall GetSimpleListSize(const void*);
int __fastcall GetTESFileForm(TESFile*);
NavMesh* __fastcall GetNavMeshPointer(NiPointer<NavMesh>*);
int CopyStringChecked(char*, unsigned int, const char*);
int AppendStringChecked(char*, unsigned int, const char*);
// Allocates and returns a new TESForm subclass instance matching the given type code, warning on unknown types.
// @fnv 0x00465110
TESForm* TESDataHandler::CreateFormForType(unsigned char type)
{
    TESForm* form;
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TES_FORMS, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 7192);
    form = 0;
    switch (type)
    {
    case 21:
        form = new TESObjectACTI;
        break;
    case 22:
        form = new BGSTalkingActivator;
        break;
    case 23:
        form = new BGSTerminal;
        break;
    case 24:
        form = new TESObjectARMO;
        break;
    case 96:
        form = new TESObjectARMA;
        break;
    case 25:
        form = new TESObjectBOOK;
        break;
    case 26:
        form = new TESObjectCLOT;
        break;
    case 27:
        form = new TESObjectCONT;
        break;
    case 28:
        form = new TESObjectDOOR;
        break;
    case 29:
        form = new IngredientItem;
        break;
    case 30:
        form = new TESObjectLIGH;
        break;
    case 31:
        form = new TESObjectMISC;
        break;
    case 103:
        form = new TESObjectIMOD;
        break;
    case 50:
        form = new BGSConstructibleObject;
        break;
    case 46:
        form = new TESKey;
        break;
    case 32:
        form = new TESObjectSTAT;
        break;
    case 33:
        form = new BGSStaticCollection;
        break;
    case 34:
        form = new BGSMovableStatic;
        break;
    case 35:
        form = new BGSPlaceableWater;
        break;
    case 36:
        form = new TESGrass;
        break;
    case 72:
        form = new TESIdleForm;
        break;
    case 92:
        form = new BGSCameraPath;
        break;
    case 48:
        form = new BGSIdleMarker;
        break;
    case 73:
        form = new TESPackage;
        break;
    case 37:
        form = new TESObjectTREE;
        break;
    case 38:
        form = new TESFlora;
        break;
    case 39:
        form = new TESFurniture;
        break;
    case 40:
        form = new TESObjectWEAP;
        break;
    case 41:
        form = new TESAmmo;
        break;
    case 42:
        form = new TESNPC;
        break;
    case 43:
        form = new TESCreature;
        break;
    case 44:
        form = new TESLevCreature;
        break;
    case 45:
        form = new TESLevCharacter;
        break;
    case 20:
        form = new SpellItem;
        break;
    case 19:
        form = new EnchantmentItem;
        break;
    case 47:
        form = new AlchemyItem;
        break;
    case 52:
        form = new TESLevItem;
        break;
    case 58:
        form = new TESObjectREFR;
        break;
    case 49:
        form = new BGSNote;
        break;
    case 5:
        form = new BGSMenuIcon;
        break;
    case 85:
        form = new BGSListForm;
        break;
    case 9:
        form = new BGSHeadPart;
        break;
    case 10:
        form = new TESHair;
        break;
    case 11:
        form = new TESEyes;
        break;
    case 12:
        form = new TESRace;
        break;
    case 97:
        form = new BGSEncounterZone;
        break;
    case 7:
        form = new TESClass;
        break;
    case 8:
        form = new TESFaction;
        break;
    case 104:
        form = new TESReputation;
        break;
    case 113:
        form = new TESChallenge;
        break;
    case 13:
        form = new TESSound;
        break;
    case 14:
        form = new BGSAcousticSpace;
        break;
    case 6:
        form = new TESGlobal;
        break;
    case 93:
        form = new BGSVoiceType;
        break;
    case 94:
        form = new BGSImpactData;
        break;
    case 95:
        form = new BGSImpactDataSet;
        break;
    case 16:
        form = new EffectSetting;
        break;
    case 54:
        form = new TESClimate;
        break;
    case 83:
        form = new TESImageSpace;
        break;
    case 84:
        form = new TESImageSpaceModifier;
        break;
    case 53:
        form = new TESWeather;
        break;
    case 65:
        form = new TESWorldSpace;
        break;
    case 57:
        form = new TESObjectCELL;
        break;
    case 15:
        form = new TESSkill;
        break;
    case 18:
        form = new TESLandTexture;
        break;
    case 91:
        form = new BGSCameraShot;
        break;
    case 71:
        form = new TESQuest;
        break;
    case 55:
        form = new TESRegion;
        break;
    case 17:
        form = new Script;
        break;
    case 74:
        form = new TESCombatStyle;
        break;
    case 75:
        form = new TESLoadScreen;
        break;
    case 78:
        form = new TESWaterForm;
        break;
    case 76:
        form = new TESLevSpell;
        break;
    case 77:
        form = new TESObjectANIO;
        break;
    case 66:
        form = new TESObjectLAND;
        break;
    case 79:
        form = new TESEffectShader;
        break;
    case 51:
        form = new BGSProjectile;
        break;
    case 81:
        form = new BGSExplosion;
        break;
    case 82:
        form = new BGSDebris;
        break;
    case 4:
        form = new BGSTextureSet;
        break;
    case 67:
        form = new NavMesh;
        break;
    case 86:
        form = new BGSPerk;
        break;
    case 87:
        form = new BGSBodyPartData;
        break;
    case 88:
        form = new BGSAddonNode;
        break;
    case 89:
        form = new ActorValueInfo(-1, 0);
        break;
    case 90:
        form = new BGSRadiationStage;
        break;
    case 118:
        form = new BGSDehydrationStage;
        break;
    case 119:
        form = new BGSHungerStage;
        break;
    case 120:
        form = new BGSSleepDeprivationStage;
        break;
    case 98:
        form = new BGSMessage;
        break;
    case 99:
        form = new BGSRagdoll;
        break;
    case 101:
        form = new BGSLightingTemplate;
        break;
    case 102:
        form = new BGSMusicType;
        break;
    case 106:
        form = new BGSRecipe;
        break;
    case 107:
        form = new BGSRecipeCategory;
        break;
    case 114:
        form = new TESAmmoEffect;
        break;
    case 108:
        form = new TESCasinoChips;
        break;
    case 110:
        form = new TESLoadScreenType;
        break;
    case 109:
        form = new TESCasino;
        break;
    case 111:
        form = new MediaSet;
        break;
    case 112:
        form = new MediaLocationController;
        break;
    case 115:
        form = new TESCaravanCard;
        break;
    case 116:
        form = new TESCaravanMoney;
        break;
    case 117:
        form = new TESCaravanDeck;
        break;
    default:
        Warning("FORMS: TESDataHandler trying to create TESForm for unknown type '%s'.", GetStringForByte(type));
        break;
    }
    return form;
}

// Dispatches a TESForm by form type into the matching list or cell, adding references to their parent cell and warning on unknown types.
// @fnv 0x004603b0
bool TESDataHandler::AddFormToDataHandler(TESForm* form)
{
    if (!form)
        return false;
    TESObjectCELL* pCell;
    TESObjectREFR* ref;
    TESObjectCELL* parentCell;
    EffectSetting* effectSetting;
    TESObject* pObject;
    switch (form->GetFormType())
    {
    case 57:
        pCell = static_cast<TESObjectCELL*>(form);
        if (pCell->IsInterior())
            (*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)).SetAt((*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)).GetSize(), pCell);
        break;
    case 55: {
        TESRegion* entry = static_cast<TESRegion*>(form);
        GetRegionList()->AddHead(entry);
        break;
    }
    case 8: {
        TESFaction* entry = static_cast<TESFaction*>(form);
        GetTESFactionList()->AddHead(entry);
        break;
    }
    case 104: {
        TESReputation* entry = static_cast<TESReputation*>(form);
        GetTESReputationList()->AddHead(entry);
        break;
    }
    case 113: {
        TESChallenge* entry = static_cast<TESChallenge*>(form);
        GetTESChallengeList()->AddHead(entry);
        break;
    }
    case 106: {
        BGSRecipe* entry = static_cast<BGSRecipe*>(form);
        GetBGSRecipeList()->AddHead(entry);
        break;
    }
    case 107: {
        BGSRecipeCategory* entry = static_cast<BGSRecipeCategory*>(form);
        GetBGSRecipeCategoryList()->AddHead(entry);
        break;
    }
    case 114: {
        TESAmmoEffect* entry = static_cast<TESAmmoEffect*>(form);
        GetTESAmmoEffectList()->AddHead(entry);
        break;
    }
    case 109: {
        TESCasino* entry = static_cast<TESCasino*>(form);
        GetTESCasinoList()->AddHead(entry);
        break;
    }
    case 117: {
        TESCaravanDeck* entry = static_cast<TESCaravanDeck*>(form);
        GetTESCaravanDeckList()->AddHead(entry);
        break;
    }
    case 7: {
        TESClass* entry = static_cast<TESClass*>(form);
        GetTESClassList()->AddHead(entry);
        break;
    }
    case 49: {
        BGSNote* entry = static_cast<BGSNote*>(form);
        GetBGSNoteList()->AddHead(entry);
        break;
    }
    case 9: {
        BGSHeadPart* entry = static_cast<BGSHeadPart*>(form);
        GetBGSHeadPartList()->AddHead(entry);
        break;
    }
    case 10: {
        TESHair* entry = static_cast<TESHair*>(form);
        GetTESHairList()->AddHead(entry);
        break;
    }
    case 11: {
        TESEyes* entry = static_cast<TESEyes*>(form);
        GetTESEyesList()->AddHead(entry);
        break;
    }
    case 12: {
        TESRace* entry = static_cast<TESRace*>(form);
        GetTESRaceList()->AddHead(entry);
        break;
    }
    case 97: {
        BGSEncounterZone* entry = static_cast<BGSEncounterZone*>(form);
        GetBGSEncounterZoneList()->AddHead(entry);
        break;
    }
    case 71: {
        TESQuest* entry = static_cast<TESQuest*>(form);
        GetTESQuestList()->AddHead(entry);
        break;
    }
    case 13: {
        TESSound* entry = static_cast<TESSound*>(form);
        GetTESSoundList()->AddHead(entry);
        break;
    }
    case 14: {
        BGSAcousticSpace* entry = static_cast<BGSAcousticSpace*>(form);
        GetBGSAcousticSpaceList()->AddHead(entry);
        break;
    }
    case 18: {
        TESLandTexture* entry = static_cast<TESLandTexture*>(form);
        GetTESLandTextureList()->AddHead(entry);
        break;
    }
    case 91: {
        BGSCameraShot* entry = static_cast<BGSCameraShot*>(form);
        GetBGSCameraShotList()->AddHead(entry);
        break;
    }
    case 17: {
        Script* entry = static_cast<Script*>(form);
        GetScriptList()->AddHead(entry);
        break;
    }
    case 54: {
        TESClimate* entry = static_cast<TESClimate*>(form);
        GetTESClimateList()->AddHead(entry);
        break;
    }
    case 83: {
        TESImageSpace* entry = static_cast<TESImageSpace*>(form);
        GetTESImageSpaceList()->AddHead(entry);
        break;
    }
    case 84: {
        TESImageSpaceModifier* entry = static_cast<TESImageSpaceModifier*>(form);
        GetTESImageSpaceModifierList()->AddHead(entry);
        break;
    }
    case 53: {
        TESWeather* entry = static_cast<TESWeather*>(form);
        GetTESWeatherList()->AddHead(entry);
        break;
    }
    case 65: {
        TESWorldSpace* entry = static_cast<TESWorldSpace*>(form);
        GetTESWorldSpaceList()->AddHead(entry);
        break;
    }
    case 73: {
        TESPackage* entry = static_cast<TESPackage*>(form);
        GetTESPackageList()->AddHead(entry);
        break;
    }
    case 6: {
        TESGlobal* entry = static_cast<TESGlobal*>(form);
        GetTESGlobalList()->AddHead(entry);
        break;
    }
    case 93: {
        BGSVoiceType* entry = static_cast<BGSVoiceType*>(form);
        GetBGSVoiceTypeList()->AddHead(entry);
        break;
    }
    case 94: {
        BGSImpactData* entry = static_cast<BGSImpactData*>(form);
        GetBGSImpactDataList()->AddHead(entry);
        break;
    }
    case 95: {
        BGSImpactDataSet* entry = static_cast<BGSImpactDataSet*>(form);
        GetBGSImpactDataSetList()->AddHead(entry);
        break;
    }
    case 5: {
        BGSMenuIcon* entry = static_cast<BGSMenuIcon*>(form);
        GetBGSMenuIconList()->AddHead(entry);
        break;
    }
    case 85: {
        BGSListForm* entry = static_cast<BGSListForm*>(form);
        GetBGSListFormList()->AddHead(entry);
        break;
    }
    case 20: {
        SpellItem* entry = static_cast<SpellItem*>(form);
        GetSpellItemList()->AddHead(entry);
        break;
    }
    case 19: {
        EnchantmentItem* entry = static_cast<EnchantmentItem*>(form);
        GetEnchantmentItemList()->AddHead(entry);
        break;
    }
    case 74: {
        TESCombatStyle* entry = static_cast<TESCombatStyle*>(form);
        GetTESCombatStyleList()->AddHead(entry);
        break;
    }
    case 75: {
        TESLoadScreen* entry = static_cast<TESLoadScreen*>(form);
        GetTESLoadScreenList()->AddHead(entry);
        break;
    }
    case 78: {
        TESWaterForm* entry = static_cast<TESWaterForm*>(form);
        GetTESWaterFormList()->AddHead(entry);
        break;
    }
    case 77: {
        TESObjectANIO* entry = static_cast<TESObjectANIO*>(form);
        GetTESObjectANIOList()->AddHead(entry);
        break;
    }
    case 79: {
        TESEffectShader* entry = static_cast<TESEffectShader*>(form);
        GetTESEffectShaderList()->AddHead(entry);
        break;
    }
    case 51: {
        BGSProjectile* entry = static_cast<BGSProjectile*>(form);
        GetBGSProjectileList()->AddHead(entry);
        break;
    }
    case 81: {
        BGSExplosion* entry = static_cast<BGSExplosion*>(form);
        GetBGSExplosionList()->AddHead(entry);
        break;
    }
    case 82: {
        BGSDebris* entry = static_cast<BGSDebris*>(form);
        GetBGSDebrisList()->AddHead(entry);
        break;
    }
    case 86: {
        BGSPerk* entry = static_cast<BGSPerk*>(form);
        GetBGSPerkList()->AddHead(entry);
        break;
    }
    case 87: {
        BGSBodyPartData* entry = static_cast<BGSBodyPartData*>(form);
        GetBGSBodyPartDataList()->AddHead(entry);
        break;
    }
    case 58:
    case 61:
    case 62:
    case 63:
    case 64:
    case 105:
        ref = dynamic_cast<TESObjectREFR*>(form);
        if (ref)
        {
            parentCell = ref->GetParentCell();
            if (!parentCell)
            {
                parentCell = g_TES->GetPrevPath();
                if (!parentCell)
                    parentCell = GetCellByWorldPosition(static_cast<const TESObjectREFR*>(ref)->GetPos()->x, static_cast<const TESObjectREFR*>(ref)->GetPos()->y,
                                                        g_TES->GetHitSound(), true);
            }
            else if (!parentCell->IsInterior())
            {
                parentCell =
                    GetCellByWorldPosition(static_cast<const TESObjectREFR*>(ref)->GetPos()->x, static_cast<const TESObjectREFR*>(ref)->GetPos()->y, g_TES->GetHitSound(), true);
            }
            if (parentCell)
            {
                parentCell->AddReference(ref, false);
                if (ref->IsPersistentFlagSet())
                    ref->SetPersistentFlag(true);
                if (ref->MustBeVisibleDistant())
                    ref->TESObjectREFR_SetVisibleDistant(true);
            }
        }
        break;
    case 16:
        effectSetting = dynamic_cast<EffectSetting*>(form);
        if (effectSetting)
            RegisterEffectSetting(effectSetting);
        break;
    case 90: {
        BGSRadiationStage* entry = static_cast<BGSRadiationStage*>(form);
        GetBGSRadiationStageList()->AddHead(entry);
        break;
    }
    case 118: {
        BGSDehydrationStage* entry = static_cast<BGSDehydrationStage*>(form);
        GetBGSDehydrationStageList()->AddHead(entry);
        break;
    }
    case 119: {
        BGSHungerStage* entry = static_cast<BGSHungerStage*>(form);
        GetBGSHungerStageList()->AddHead(entry);
        break;
    }
    case 120: {
        BGSSleepDeprivationStage* entry = static_cast<BGSSleepDeprivationStage*>(form);
        GetBGSSleepDeprivationStageList()->AddHead(entry);
        break;
    }
    case 98: {
        BGSMessage* entry = static_cast<BGSMessage*>(form);
        GetBGSMessageList()->AddHead(entry);
        break;
    }
    case 99: {
        BGSRagdoll* entry = static_cast<BGSRagdoll*>(form);
        GetBGSRagdollList()->AddHead(entry);
        break;
    }
    case 101: {
        BGSLightingTemplate* entry = static_cast<BGSLightingTemplate*>(form);
        GetBGSLightingTemplateList()->AddHead(entry);
        break;
    }
    case 102: {
        BGSMusicType* entry = static_cast<BGSMusicType*>(form);
        GetBGSMusicTypeList()->AddHead(entry);
        break;
    }
    case 110: {
        TESLoadScreenType* entry = static_cast<TESLoadScreenType*>(form);
        GetTESLoadScreenTypeList()->AddHead(entry);
        break;
    }
    case 111: {
        MediaSet* entry = static_cast<MediaSet*>(form);
        GetMediaSetList()->AddHead(entry);
        break;
    }
    case 112: {
        MediaLocationController* entry = static_cast<MediaLocationController*>(form);
        GetMediaLocationControllerList()->AddHead(entry);
        break;
    }
    case 88:
        RegisterAddonNode(static_cast<BGSAddonNode*>(form));
    default:
        pObject = dynamic_cast<TESObject*>(form);
        if (pObject)
            reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(pObject);
        else
        {
            Warning("FORMS: Unknown form type '%s' encountered in AddFormToDataHandler.",
                    GetStringForByte(form->GetFormType()));
            return false;
        }
        break;
    }
    return true;
}

// @fnv 0x00467bd0
bool TESDataHandler::ConstructObject(TESFile* file, bool skipExisting, TESForm* supplied, bool allowOrphan)
{
    AutoMemContext kMemContext(MEM_CONTEXT_MEM_CONTEXT_TES_FORMS, true,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 7833);
    char buffer[260];
    TESObject* pObject;
    bool bAddObject = true;
    int m_eReferenceTypeInfo = GetTESFileForm(file);
    TESForm* pOldForm = supplied;
    if (!ucGameSettingsLoadState && m_eReferenceTypeInfo == 3)
        ucGameSettingsLoadState = 1;
    else if (ucGameSettingsLoadState = (1 && m_eReferenceTypeInfo != 3))
        ucGameSettingsLoadState = 2;
    if (!skipExisting || FUN_00484b40(file->GetFormID()))
    {
        if (!pOldForm)
            pOldForm = TESFormInitFlag::GetFormByID(file->GetFormID());
        if (pOldForm)
        {
            bool wrongType = false;
            if (pOldForm->GetFormType() != m_eReferenceTypeInfo &&
                ((m_eReferenceTypeInfo != 24 && m_eReferenceTypeInfo != 96) ||
                 (pOldForm->GetFormType() != 24 && pOldForm->GetFormType() != 96)))
                wrongType = true;
            if (wrongType)
            {
                Warning("FORMS: Form (%08X) in file \"%s\" has wrong type.\n\nShould be:\t%s\nIs:\t\t%s",
                        file->GetFormID(), file->GetName(), pOldForm->TESForm_GetFormTypeString(), DAT_01187004[m_eReferenceTypeInfo].name);
                return false;
            }
        }
    }
    bool bPartialForm = false;
    if (!file->IsMasterFile() || !file->GetMasterList_00464df0()->IsEmpty())
    {
        if (pOldForm && pOldForm->Unk_46() && (file->GetRecordHeader()->flags & 0x4000))
            bPartialForm = true;
    }
    if (bPartialForm)
    {
        switch (pOldForm->GetFormType())
        {
        case 65:
            DAT_011c3f34 = static_cast<TESWorldSpace*>(pOldForm);
            break;
        case 57:
            DAT_011c3f30 = static_cast<TESObjectCELL*>(pOldForm);
            break;
        case 69:
            g_loadingTopic = static_cast<TESTopic*>(pOldForm);
            break;
        }
        pOldForm->Unk_09(file);
        pOldForm->SetFile(file);
        pOldForm->SetInitializationState(false);
        if (file->GetActive())
            pOldForm->SetAltered(true);
        return true;
    }
    else
    {
        if (!pOldForm && (file->GetRecordHeader()->flags & 0x4000))
        {
            Warning("FORMS: Partial form (%08X) found with no matching original data.", file->GetFormID());
            if ((file->GetFormID() >> 24) == file->GetFileCompileIndex())
            {
                Warning("FORMS: Partial form originated in current file. Clearing erroneous partial data flag.");
                file->GetRecordHeader()->flags &= ~0x4000;
            }
            else
                return false;
        }
        if (pOldForm && !(file->GetRecordHeader()->flags & 0x20))
        {
            pOldForm->TESForm_ClearDataAllComponents();
            pOldForm->ClearData();
            pOldForm->ClearFormData();
            pOldForm->InitializeComponent();
        }
    }
    switch (m_eReferenceTypeInfo)
    {
    case 1: {
        unsigned int chunk = file->GetChunkID();
        while (chunk)
        {
            if (chunk == 0x4d414e4f)
            {
                AutoMemContext ownedMemory(MEM_CONTEXT_MEM_CONTEXT_MASTER_FILE, true,
                                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp",
                                           8160);
                unsigned int size = file->GetChunkSize();
                unsigned int ItemUpdateArray = size >> 2;
                unsigned int* pFormIDArray = new unsigned int[ItemUpdateArray];
                file->GetChunkData(pFormIDArray, size);
                for (unsigned int i = 0; i < ItemUpdateArray; ++i)
                {
                    unsigned int auiFormId = pFormIDArray[i];
                    if (file->IsEndianConversionRequired())
                        BSEndian(&auiFormId, EndianSizeTag<3>());
                    unsigned int index = auiFormId >> 24;
                    TESFile* pFile = file->GetMasterFile(index + 1);
                    if (!pFile)
                        pFile = file;
                    auiFormId &= 0xffffff;
                    auiFormId |= pFile->GetFileCompileIndex() << 24;
                    TESFile::SetTempIDOwnerForForm(auiFormId, file);
                }
                delete[] pFormIDArray;
                chunk = 0;
            }
            else
            {
                if (!file->GetNextChunk())
                    chunk = 0;
                else
                    chunk = file->GetChunkID();
            }
        }
        return true;
    }
    case 100:
        LoadForm(BGSDefaultObjectManager::Instance(), file);
        return true;
    case 57: {
        TESObjectCELL* cell = static_cast<TESObjectCELL*>(pOldForm);
        bool created = false;
        if (!cell)
        {
            cell = new TESObjectCELL;
            created = true;
        }
        LoadForm(cell, file);
        if (bSaveLoadGame)
            cell->SetAltered(true);
        cell->SetMasterFile(true);
        if (created)
        {
            if (cell->IsInterior())
                (*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)).SetAt((*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)).GetSize(), cell);
            else
            {
                if (!DAT_011c3f34)
                    DAT_011c3f34 = GetTESWorldSpaceList()->GetItem();
                if (!DAT_011c3f34->HasCell(cell))
                {
                    TESObjectCELL* existingCell =
                        DAT_011c3f34->GetCellAtGridPosition(cell->GetCellGridX(), cell->GetCellGridY());
                    Warning("CELLS: Error adding %scell (%08X) to world space (%08X). Cell will be destroyed.",
                            cell->IsCellPersistent() ? "Persistent " : "", cell->GetFormID(),
                            DAT_011c3f34->GetFormID());
                    delete cell;
                    cell = existingCell;
                }
            }
        }
        DAT_011c3f30 = cell;
        return true;
    }
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 105: {
        if (!DAT_011c3f30 && !allowOrphan)
            return false;
        TESObjectCELL* previousCell = 0;
        TESBoundObject* pBaseObject = 0;
        TESObjectREFR* pRef;
        if (pOldForm)
        {
            pRef = static_cast<TESObjectREFR*>(pOldForm);
            pBaseObject = pRef->GetObjectReference();
            previousCell = pRef->GetSaveParentCell();
            if (previousCell == DAT_011c3f30)
                bAddObject = false;
            else if (previousCell)
                previousCell->RemoveReference(pRef);
        }
        else
            pRef = TESObjectREFR::CreateReference((unsigned char)m_eReferenceTypeInfo, true);
        if (!LoadForm(pRef, file))
        {
            if (!pRef->GetObjectReference())
                pRef->SetFormType((ENUM_FORM_ID)m_eReferenceTypeInfo);
            if (pRef->GetParentCell())
                pRef->GetParentCell()->RemoveReference(pRef);
            if (DAT_011c3f30 && DAT_011c3f30->IsCellPersistent())
                pRef->GetExtraData()->CallExtraDataListMethod35(DAT_011c3f30);
            else
                pRef->SetParentCell(DAT_011c3f30);
            if (!(*reinterpret_cast<NiTPointerList<TESForm*>*>(listBadForms)).FindPos(pRef, 0))
                (*reinterpret_cast<NiTPointerList<TESForm*>*>(listBadForms)).AddTail(pRef);
            bAddObject = false;
            MobileObject* actor = dynamic_cast<MobileObject*>(pRef);
            if (actor)
                DAT_011e0e80.ProcessLists_RemoveReference(actor, 3);
        }
        if (pRef->GetObjectReference())
        {
            if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetLoadingMovedRefs())
                bAddObject = false;
            if (bAddObject)
            {
                if (DAT_011c3f30)
                {
                    DAT_011c3f30->AddReference(pRef, false);
                    if (DAT_011c3f30->IsCellPersistent())
                    {
                        TESObjectCELL* parent = pRef->GetParentCell();
                        if (parent)
                        {
                            TESObjectCELL* actualCell =
                                DAT_011c3f30->GetParentWorldSpace()->GetCellByWorldPosition(*static_cast<const TESObjectREFR*>(pRef)->GetPos());
                            if (parent != actualCell)
                            {
                                if (actualCell)
                                    actualCell->AddReference(pRef, false);
                                else
                                    parent->RemoveReference(pRef);
                            }
                        }
                    }
                }
                if (!pRef->IsDeleted())
                    pRef->GetObjectReference()->AcquireReference();
            }
            else if (pRef->IsDeleted())
                pRef->GetObjectReference()->DecRef();
            if (g_TESSaveLoadGame && g_TESSaveLoadGame->FUN_0047c850() && pRef->GetReferenceType())
                pRef->Set3D(0, true);
            if (pRef->GetReferencePersistence() && file->GetFileVersion() < 0.2f)
            {
                TESBoundObject* pObjectBase = pRef->GetObjectReference();
                Warning(
                    "CELLS: ref (%08X) to base object %s (%08X) in cell %s (%i, %i) (%08X) is persistent in the non-persistent file %s.",
                    pRef->GetFormID(), PrepareScriptMessage(pObjectBase->GetName(), false),
                    pObjectBase->GetFormID(), PrepareScriptMessage(DAT_011c3f30->GetName(), true),
                    DAT_011c3f30->GetCellGridX(), DAT_011c3f30->GetCellGridY(), DAT_011c3f30->GetFormID(),
                    file->GetName());
                unsigned int uiFlags = pRef->GetFlags();
                uiFlags &= ~0x400;
                pRef->SetFlags(uiFlags);
            }
        }
        return true;
    }
    case 66: {
        if (DAT_011c3f30)
        {
            TESObjectLAND* land = DAT_011c3f30->GetLandscape();
            if (!land)
            {
                land = new TESObjectLAND;
                land->InitializeForCell(DAT_011c3f30);
                DAT_011c3f30->SetLandscape(land);
            }
            LoadForm(land, file);
        }
        return true;
    }
    case 3: {
        AutoMemContext settingsMemory(
            (MEM_CONTEXT)9, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 8465);
        if (file->GetChunkID() == 0x44494445)
        {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0);
            GameSettingCollection::Instance()->ReadSetting(file, editorID);
        }
        return true;
    }
    case 65: {
        if (!pOldForm)
        {
            TESWorldSpace* world = new TESWorldSpace;
            LoadForm(world, file);
            (*reinterpret_cast<BSSimpleList<TESWorldSpace*>*>(listWorldSpaces)).AddTail(world);
            DAT_011c3f34 = world;
        }
        else
        {
            LoadForm(pOldForm, file);
            DAT_011c3f34 = static_cast<TESWorldSpace*>(pOldForm);
        }
        return true;
    }
    case 69: {
        AutoMemContext dialogueMemory(
            (MEM_CONTEXT)53, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 8507);
        if (!pOldForm)
        {
            TESTopic* topic = new TESTopic(0);
            LoadForm(topic, file);
            AddTopic(topic);
        }
        else
            LoadForm(pOldForm, file);
    }
        return true;
    case 70: {
        bool existing = false;
        {
            AutoMemContext memContext((MEM_CONTEXT)53, true,
                                      "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp",
                                      8530);
            if (pOldForm)
                existing = true;
            else
                pOldForm = new TESTopicInfo(0);
            DAT_011c3f38 = static_cast<TESTopicInfo*>(pOldForm);
            bool bResult = LoadForm(pOldForm, file);
            if (!existing)
                AddTopicInfo(DAT_011c3f38);
            return bResult;
        }
    }
    case 15: {
        if (pOldForm)
        {
            TESSkill* skill = dynamic_cast<TESSkill*>(pOldForm);
            if (skill)
            {
                skill->ResetData();
                LoadForm(skill, file);
            }
        }
        return true;
    }
    case 72:
    case 92: {
        TESForm* result;
        if (!pOldForm)
        {
            TESForm* created = CreateFormForType((unsigned char)m_eReferenceTypeInfo);
            LoadForm(created, file);
            result = created;
        }
        else
        {
            LoadForm(pOldForm, file);
            result = pOldForm;
        }
        return true;
    }
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 22:
    case 23:
    case 35:
    case 48:
    case 49:
    case 51:
    case 53:
    case 54:
    case 55:
    case 71:
    case 73:
    case 74:
    case 75:
    case 77:
    case 78:
    case 79:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 90:
    case 91:
    case 93:
    case 94:
    case 95:
    case 97:
    case 98:
    case 99:
    case 101:
    case 102:
    case 104:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120: {
        TESForm* result;
        if (!pOldForm)
        {
            TESForm* created = CreateFormForType((unsigned char)m_eReferenceTypeInfo);
            LoadForm(created, file);
            AddFormToDataHandler(created);
            result = created;
        }
        else
        {
            LoadForm(pOldForm, file);
            result = pOldForm;
        }
        return true;
    }
    case 67: {
        AutoMemContext navMemory((MEM_CONTEXT)46, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 9999);
        if (!pOldForm)
        {
            NiPointer<NavMesh> mesh = MakeNavMeshPointer(new NavMesh);
            LoadForm(GetNavMeshPointer(&mesh), file);
            if (GetNavMeshPointer(&mesh)->GetParentCell())
            {
                if (!GetNavMeshPointer(&mesh)->GetParentCell()->GetNavMeshArray())
                    GetNavMeshPointer(&mesh)->GetParentCell()->SetNavMeshArray(new NavMeshCollection);
                GetNavMeshPointer(&mesh)->GetParentCell()->GetNavMeshArray()->AppendNavMesh(mesh);
            }
        }
        else
            LoadForm(pOldForm, file);
    }
        return true;
    case 56: {
        AutoMemContext navMemory((MEM_CONTEXT)46, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 10029);
        if (!pOldForm)
        {
            NavMeshInfoMap* map = new NavMeshInfoMap;
            g_TES->IsCellAttached(map);
            LoadForm(map, file);
        }
        else
            LoadForm(pOldForm, file);
    }
        return true;
    case 89:
        LoadForm(pOldForm, file);
        return true;
    }
    MessageHandler_IncDisableWarningCount(true);
    if (pOldForm)
    {
        bAddObject = false;
        pObject = static_cast<TESObject*>(pOldForm);
    }
    else
        pObject = static_cast<TESObject*>(CreateFormForType((unsigned char)m_eReferenceTypeInfo));
    if (!pObject)
    {
        TESRecordHeader* record = file->GetRecordHeader();
        if (record->type)
        {
            buffer[0] = record->type & 0xff;
            buffer[1] = (record->type & 0xff00) >> 8;
            buffer[2] = (record->type & 0xff0000) >> 16;
            buffer[3] = (record->type & 0xff000000) >> 24;
            buffer[4] = 0;
            Warning("FORMS: Unknown %s_ID in ConstructObject.", buffer);
        }
        else if (!m_eReferenceTypeInfo)
            Warning("FORMS: NO_FORM trying to load in ConstructObject.");
        MessageHandler_IncDisableWarningCount(false);
        return false;
    }
    MessageHandler_IncDisableWarningCount(false);
    if (LoadForm(pObject, file))
    {
        if (bAddObject)
            pObject = reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(pObject);
        return true;
    }
    else
        delete pObject;
    return false;
}

// Bubble-sorts the TESClass and TESRace lists in place by comparing fullName with _mbsicmp, swapping adjacent items out of order.
// @fnv 0x0046fb50
void TESDataHandler::MarkGameSettingsLoaded()
{
    BSSimpleList<TESClass*>* pClassList = GetTESClassList();
    int nCount = GetSimpleListSize(pClassList);
    for (int i = 0; i < nCount - 1; ++i)
    {
        BSSimpleList<TESClass*>* node = pClassList;
        while (node && node->GetItem())
        {
            if (node->GetNext())
            {
                TESClass* first = node->GetItem();
                TESClass* second = node->GetNext()->GetItem();
                if (first && second &&
                    _mbsicmp((const unsigned char*)first->GetFullName(),
                             (const unsigned char*)second->GetFullName()) > 0)
                {
                    node->SetItem(second);
                    node->GetNext()->SetItem(first);
                }
            }
            node = node->GetNext();
        }
    }
    BSSimpleList<TESRace*>* pRaceList = GetTESRaceList();
    nCount = GetSimpleListSize(pRaceList);
    for (int i = 0; i < nCount - 1; ++i)
    {
        BSSimpleList<TESRace*>* node = pRaceList;
        while (node && node->GetItem())
        {
            if (node->GetNext())
            {
                TESRace* pRace = node->GetItem();
                TESRace* second = node->GetNext()->GetItem();
                if (pRace && second &&
                    _mbsicmp((const unsigned char*)pRace->GetFullName(),
                             (const unsigned char*)second->GetFullName()) > 0)
                {
                    node->SetItem(second);
                    node->GetNext()->SetItem(pRace);
                }
            }
            node = node->GetNext();
        }
    }
}

// Registers an addon node at its index, remapping to a new index with a warning if another node already occupies it.
// @fnv 0x00461820
void TESDataHandler::RegisterAddonNode(BGSAddonNode* node)
{
    if (!node)
        return;
    unsigned int index = node->GetIndex();
    if (index < (*reinterpret_cast<NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >*>(arrayAddonNodes)).GetSize())
    {
        BGSAddonNode* old = (*reinterpret_cast<NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >*>(arrayAddonNodes)).GetAt(index);
        if (old && old != node)
        {
            Warning(
                "FORMS: Addon Node %08X \"%s\" is trying to use index %i, but Addon Node %08X \"%s\" already uses that index.  Addon Node %08X \"%s\" will be remapped to a new index.",
                node->GetFormID(), node->GetName(), index, old->GetFormID(), old->GetName(), node->GetFormID(),
                node->GetName());
            index = (unsigned int)-1;
        }
    }
    if (index == (unsigned int)-1)
    {
        index = (*reinterpret_cast<NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >*>(arrayAddonNodes)).Add(node);
        node->SetIndex(index);
    }
    else
        (*reinterpret_cast<NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >*>(arrayAddonNodes)).SetAt(node->GetIndex(), node);
}

// @fnv 0x0046feb0
int TESDataHandler::GetDLCIndex(const char* name)
{
    if (BSStringLength(name) < 2)
        return 0;
    switch (name[0])
    {
    case 'D':
        if (!_mbsnicmp((const unsigned char*)name, (const unsigned char*)"DeadMoney", 9))
            return 1;
        break;
    case 'H':
        if (!_mbsnicmp((const unsigned char*)name, (const unsigned char*)"HonestHearts", 12))
            return 2;
        break;
    case 'O':
        if (!_mbsnicmp((const unsigned char*)name, (const unsigned char*)"OldWorldBlues", 12))
            return 3;
        break;
    case 'L':
        if (!_mbsnicmp((const unsigned char*)name, (const unsigned char*)"LonesomeRoad", 12))
            return 4;
        break;
    }
    return 0;
}

// @fnv 0x0046f280
void TESDataHandler::GetReferencesInArea(TESObjectCELL* cell, const NiPoint3& point, float radius,
                                         const NiPoint3& direction, float angle,
                                         bool(__cdecl* callback)(TESObjectREFR*, long), long data)
{
    if (!cell || !callback)
        return;
    if (!cell->IsInterior())
    {
        TESWorldSpace* world = cell->GetParentWorldSpace();
        if (world)
            world->GetReferencesInArea(point, radius, direction, angle, callback, data);
    }
    else
        cell->GetReferencesInArea(point, radius, direction, angle, callback, data);
}

// @fnv 0x004601d0
bool TESDataHandler::LoadForm(TESForm* form, TESFile* file)
{
    bool master = form->GetMaster();
    bool result = form->LoadForm(file);
    if (!master)
        form->SetMasterFile(file->IsMasterFile());
    else
        form->SetMasterFile(true);
    if (file->GetActive())
        form->SetAltered(true);
    return result;
}

// Iterates the object list, and for each TESNPC whose FUN_00461560 returns true, calls AutoCalcStats(false).
// @fnv 0x004614e0
void TESDataHandler::GetRegions()
{
    TESObject* object = GetObjectList()->GetFirst();
    while (object)
    {
        TESNPC* npc = dynamic_cast<TESNPC*>(object);
        if (npc && npc->GetMatchesPCLevel())
            npc->AutoCalcStats(false);
        object = object->GetNext();
    }
}

// @fnv 0x00462f40
TESFile* TESDataHandler::LookupTESFile(const char* name)
{
    BSSimpleList<TESFile*>* list = GetFileList();
    if (name)
    {
        while (list && list->GetItem())
        {
            TESFile* file = list->GetItem();
            if (!BSstricmp(name, file->GetName()))
                return file;
            list = list->GetNext();
        }
    }
    return 0;
}

// @fnv 0x004650a0
void TESDataHandler::SetSaveLoadGameState(int size)
{
    BSSimpleList<TESFile*>* pList = GetFileList();
    TESFile* file = 0;
    while (pList && pList->GetItem())
    {
        file = pList->GetItem();
        if (file->IsMasterFile())
            file->SetBufferSize(size);
        pList = pList->GetNext();
    }
}

// Locks the ID mutex, skips IDs already in use, returns the current iNextID and increments it before unlocking.
// @fnv 0x00469800
unsigned int TESDataHandler::GetNextID()
{
    DAT_011c4000.Lock("TESDataHandler::GetNextID");
    while (IsIDUsed(iNextID))
        IncrementID();
    unsigned int result = iNextID;
    IncrementID();
    DAT_011c4000.Unlock();
    return result;
}

// @fnv 0x00462ee0
void TESDataHandler::BuildCompiledFileList()
{
    BSSimpleList<TESFile*>* list = GetFileList();
    while (list && !list->IsEmpty())
    {
        TESFile* file = list->GetItem();
        if (file->GetIsChecked())
            file->GetParentTESFile();
        list = list->GetNext();
    }
}

template <>

// Scans the list from position (or the head) and returns the position whose next element equals item, or 0.
// @fnv 0x0049c680
void* NiTPointerListBase<NiTPointerAllocator<unsigned int>, TESForm*>::FindPos(TESForm* const& item, void* position) const
{
    if (!position)
        position = GetHeadPos();
    while (position)
    {
        void* old = position;
        if (item == GetNext(position))
            return old;
    }
    return 0;
}

// @fnv 0x004616c0
TESSound* TESDataHandler::GetSoundByEditorID(const char* name)
{
    TESForm* form = TESFormInitFlag::LookupFormByEditorID(name);
    if (form && form->GetFormType() == 13)
        return static_cast<TESSound*>(form);
    else
        return 0;
}

// Returns the addon node at the given index, or null if the index is out of range.
// @fnv 0x004617e0
BGSAddonNode* TESDataHandler::GetAddonNodeByIndex(unsigned int index)
{
    if (index >= (*reinterpret_cast<NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >*>(arrayAddonNodes)).GetSize())
        return 0;
    return (*reinterpret_cast<NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >*>(arrayAddonNodes)).GetAt(index);
}

// @fnv 0x00461630
TESReputation* TESDataHandler::GetReputation(unsigned int id)
{
    return dynamic_cast<TESReputation*>(TESFormInitFlag::GetFormByID(id));
}

// @fnv 0x00461660
TESLoadScreenType* TESDataHandler::GetLoadScreenType(unsigned int id)
{
    return dynamic_cast<TESLoadScreenType*>(TESFormInitFlag::GetFormByID(id));
}

// @fnv 0x00461600
TESFaction* TESDataHandler::GetFactionByFormID(unsigned int id)
{
    return dynamic_cast<TESFaction*>(TESFormInitFlag::GetFormByID(id));
}

// Returns the loaded file at the given index, or null if the index is outside 0-254.
// @fnv 0x00465010
TESFile* TESDataHandler::GetCompiledFileByIndex(int index)
{
    if (index < 0 || (unsigned int)index > 254)
        return 0;
    return pFileIndex[index];
}

// @fnv 0x00562210
void BSFlags::Clear(unsigned int mask)
{
    flags &= ~mask;
}

// @fnv 0x0051f550
unsigned int TESDataHandler::GetCompiledFileCount()
{
    return iNumCompile;
}

// Checks whether a TESForm is a valid target for this enchantment by form type and enchantment type, returning true or false.
// @fnv 0x004094f0
bool EnchantmentItem::IsValidObject(TESForm* form)
{
    TESObject* object = dynamic_cast<TESObject*>(form);
    if (!object)
        return false;
    switch (object->GetFormType())
    {
    case 41:
        return GetEnchantmentType() == 2;
        break;
    case 40: {
        TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(object);
        if (weapon)
            return GetEnchantmentType() == 2;
    }
    break;
    case 24:
        return !HasNonDetrimentalEffectWithFlag(0x20000) && GetEnchantmentType() == 3;
        break;
    case 26: {
        TESBipedModelForm* biped = dynamic_cast<TESBipedModelForm*>(form);
        if (!biped)
            return false;
        if (!biped->FUN_0047c850() && HasNonDetrimentalEffectWithFlag(0x20000))
            return false;
        return GetEnchantmentType() == 3;
    }
    break;
    case 25:
        if (object->TESObjectBOOK_GetScroll())
            return GetEnchantmentType() == 0;
        break;
    case 42:
    case 43:
        return GetEnchantmentType() == 2;
        break;
    case 81:
        return true;
    }
    return false;
}

// Initializes the FAMThread: creates its event, clears work and result, and stores the current thread ID.
// @fnv 0x0082f610
FAMThread::FAMThread() : state(1)
{
    event = CreateEventA(0, 0, 0, 0);
    work = 0;
    result = 0;
    threadID = GetThreadID();
}

// Clears default-object globals, then creates and registers the built-in default forms (markers, voices, water, globals, weather, messages, effects) if missing.
// @fnv 0x0046a370
void TESDataHandler::InitializeMagicSystem()
{
    TESNPC* pNPC;
    AutoMemContext memContext(MEM_CONTEXT_MEM_CONTEXT_TES_DEFAULT_OBJECTS, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 10895);
    DAT_011ca220 = 0;
    DAT_011ca230 = 0;
    DAT_011ca244 = 0;
    DAT_011ca248 = 0;
    DAT_011ca224 = 0;
    DAT_011ca228 = 0;
    DAT_011ca22c = 0;
    DAT_011ca254 = 0;
    DAT_011ca258 = 0;
    DAT_011ca25c = 0;
    DAT_011ca260 = 0;
    DAT_011ca250 = 0;
    DAT_011cb550 = 0;
    g_pLockpickItem = 0;
    DAT_011ca26c = 0;
    DAT_011ca53c = 0;
    DAT_011cb96c = 0;
    DAT_011cb600 = 0;
    DAT_011ca278 = 0;
    DAT_011cb298 = 0;
    DAT_011cb29c = 0;
    DAT_011ca27c = 0;
    DAT_011ca280 = 0;
    DAT_011ca284 = 0;
    DAT_011ca288 = 0;
    ActorValue::LoadActorValueDefinitions();
    DAT_011ca700->InitializeCameraPaths();
    DAT_011ca284 = dynamic_cast<BGSExplosion*>(TESFormInitFlag::GetFormByID(0x1f5));
    if (!DAT_011ca284)
    {
        DAT_011ca284 = new BGSExplosion;
        DAT_011ca284->SetRefID(0x1f5, true);
        DAT_011ca284->SetEditorID_AtRuntime("Default Water Explosion");
        DAT_011ca284->SetFullName("Water Explosion");
        GetBGSExplosionList()->AddHead(DAT_011ca284);
        DAT_011ca284->SetAltered(false);
    }
    DAT_011ca288 = dynamic_cast<TESObjectWEAP*>(TESFormInitFlag::GetFormByID(0x1f6));
    if (!DAT_011ca288)
    {
        DAT_011ca288 = new TESObjectWEAP;
        DAT_011ca288->SetRefID(0x1f6, true);
        DAT_011ca288->SetEditorID_AtRuntime("GasTrap Dummy");
        DAT_011ca288->SetFullName("GasTrap Dummy");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca288);
        DAT_011ca288->SetAltered(false);
    }
    DAT_011cb600 = dynamic_cast<TESEyes*>(TESFormInitFlag::GetFormByID(0x1a));
    if (!DAT_011cb600)
    {
        DAT_011cb600 = new TESEyes;
        DAT_011cb600->SetRefID(0x1a, true);
        DAT_011cb600->SetEditorID_AtRuntime("eyeReanimate");
        DAT_011cb600->SetFullName("Reanimate Eyes");
        GetTESEyesList()->AddHead(DAT_011cb600);
        DAT_011cb600->SetAltered(false);
    }
    DAT_011ca27c = dynamic_cast<TESObjectACTI*>(TESFormInitFlag::GetFormByID(0x1b));
    if (!DAT_011ca27c)
    {
        DAT_011ca27c = new TESObjectACTI;
        DAT_011ca27c->SetRefID(0x1b, true);
        DAT_011ca27c->SetEditorID_AtRuntime("DefaultAshPile1");
        DAT_011ca27c->SetFullName("Ash Pile 1");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca27c);
        DAT_011ca27c->SetAltered(false);
    }
    DAT_011ca280 = dynamic_cast<TESObjectACTI*>(TESFormInitFlag::GetFormByID(0x22));
    if (!DAT_011ca280)
    {
        DAT_011ca280 = new TESObjectACTI;
        DAT_011ca280->SetRefID(0x22, true);
        DAT_011ca280->SetEditorID_AtRuntime("DefaultAshPile2");
        DAT_011ca280->SetFullName("Ash Pile 2");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca280);
        DAT_011ca280->SetAltered(false);
    }
    DAT_011cb298 = dynamic_cast<BGSVoiceType*>(TESFormInitFlag::GetFormByID(0x2d));
    if (!DAT_011cb298)
    {
        DAT_011cb298 = new BGSVoiceType;
        DAT_011cb298->SetRefID(0x2d, true);
        DAT_011cb298->SetEditorID_AtRuntime("AdultMaleVoice1");
        GetBGSVoiceTypeList()->AddHead(DAT_011cb298);
        DAT_011cb298->SetAltered(false);
    }
    DAT_011cb29c = dynamic_cast<BGSVoiceType*>(TESFormInitFlag::GetFormByID(0x2e));
    if (!DAT_011cb29c)
    {
        DAT_011cb29c = new BGSVoiceType;
        DAT_011cb29c->SetRefID(0x2e, true);
        DAT_011cb29c->SetEditorID_AtRuntime("AdultFemaleVoice1");
        GetBGSVoiceTypeList()->AddHead(DAT_011cb29c);
        DAT_011cb29c->SetAltered(false);
    }
    DAT_011ca53c = dynamic_cast<TESWaterForm*>(TESFormInitFlag::GetFormByID(0x18));
    if (!DAT_011ca53c)
    {
        DAT_011ca53c = new TESWaterForm;
        DAT_011ca53c->SetRefID(0x18, true);
        DAT_011ca53c->SetEditorID_AtRuntime("DefaultWater");
        GetTESWaterFormList()->AddHead(DAT_011ca53c);
        DAT_011ca53c->SetAltered(false);
    }
    DAT_011ca26c = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x12));
    if (!DAT_011ca26c)
    {
        DAT_011ca26c = new TESObjectSTAT;
        DAT_011ca26c->SetRefID(0x12, true);
        DAT_011ca26c->SetEditorID_AtRuntime("HorseMarker");
        DAT_011ca26c->SetModelFilePath("Marker_Horse.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca26c);
        DAT_011ca26c->SetAltered(false);
    }
    g_pLockpickItem = dynamic_cast<TESObjectMISC*>(TESFormInitFlag::GetFormByID(0xa));
    if (!g_pLockpickItem)
    {
        g_pLockpickItem = new TESObjectMISC;
        g_pLockpickItem->SetRefID(0xa, true);
        g_pLockpickItem->SetEditorID_AtRuntime("BobbyPin");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(g_pLockpickItem);
        g_pLockpickItem->SetAltered(false);
    }
    DAT_011ca220 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x1));
    if (!DAT_011ca220)
    {
        DAT_011ca220 = new TESObjectSTAT;
        DAT_011ca220->SetRefID(0x1, true);
        DAT_011ca220->SetEditorID_AtRuntime("DoorMarker");
        DAT_011ca220->SetModelFilePath("MarkerTeleport.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca220);
        DAT_011ca220->SetAltered(false);
    }
    TESWorldSpace* pDefaultWorld = dynamic_cast<TESWorldSpace*>(TESFormInitFlag::GetFormByID(0x3c));
    if (!pDefaultWorld)
    {
    }
    else if (GetTESWorldSpaceList()->GetItem() != pDefaultWorld)
    {
        GetTESWorldSpaceList()->Remove(pDefaultWorld);
        GetTESWorldSpaceList()->AddHead(pDefaultWorld);
    }
    DAT_011ca230 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x15));
    if (!DAT_011ca230)
    {
        DAT_011ca230 = new TESObjectSTAT;
        DAT_011ca230->SetRefID(0x15, true);
        DAT_011ca230->SetEditorID_AtRuntime("MultiBoundMarker");
        DAT_011ca230->SetModelFilePath("");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca230);
        DAT_011ca230->SetAltered(false);
    }
    DAT_011ca234 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x17));
    if (!DAT_011ca234)
    {
        DAT_011ca234 = new TESObjectSTAT;
        DAT_011ca234->SetRefID(0x17, true);
        DAT_011ca234->SetEditorID_AtRuntime("PlaneMarker");
        DAT_011ca234->SetModelFilePath("");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca234);
        DAT_011ca234->SetAltered(false);
    }
    DAT_011ca238 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x1f));
    if (!DAT_011ca238)
    {
        DAT_011ca238 = new TESObjectSTAT;
        DAT_011ca238->SetRefID(0x1f, true);
        DAT_011ca238->SetEditorID_AtRuntime("RoomMarker");
        DAT_011ca238->SetModelFilePath("");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca238);
        DAT_011ca238->SetAltered(false);
    }
    DAT_011ca23c = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x20));
    if (!DAT_011ca23c)
    {
        DAT_011ca23c = new TESObjectSTAT;
        DAT_011ca23c->SetRefID(0x20, true);
        DAT_011ca23c->SetEditorID_AtRuntime("PortalMarker");
        DAT_011ca23c->SetModelFilePath("");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca23c);
        DAT_011ca23c->SetAltered(false);
    }
    DAT_011ca240 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x21));
    if (!DAT_011ca240)
    {
        DAT_011ca240 = new TESObjectSTAT;
        DAT_011ca240->SetRefID(0x21, true);
        DAT_011ca240->SetEditorID_AtRuntime("CollisionMarker");
        DAT_011ca240->SetModelFilePath("");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca240);
        DAT_011ca240->SetAltered(false);
    }
    DAT_011ca244 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x3b));
    if (!DAT_011ca244)
    {
        DAT_011ca244 = new TESObjectSTAT;
        DAT_011ca244->SetRefID(0x3b, true);
        DAT_011ca244->SetEditorID_AtRuntime("XMarker");
        DAT_011ca244->SetModelFilePath("MarkerX.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca244);
        DAT_011ca244->SetAltered(false);
    }
    DAT_011ca248 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x34));
    if (!DAT_011ca248)
    {
        DAT_011ca248 = new TESObjectSTAT;
        DAT_011ca248->SetRefID(0x34, true);
        DAT_011ca248->SetEditorID_AtRuntime("XMarkerHeading");
        DAT_011ca248->SetModelFilePath("MarkerXHeading.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca248);
        DAT_011ca248->SetAltered(false);
    }
    DAT_011ca24c = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x32));
    if (!DAT_011ca24c)
    {
        DAT_011ca24c = new TESObjectSTAT;
        DAT_011ca24c->SetRefID(0x32, true);
        DAT_011ca24c->SetEditorID_AtRuntime("COCMarkerHeading");
        DAT_011ca24c->SetModelFilePath("MarkerCOCHeading.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca24c);
        DAT_011ca24c->SetAltered(false);
    }
    DAT_011ca224 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x10));
    if (!DAT_011ca224)
    {
        DAT_011ca224 = new TESObjectSTAT;
        DAT_011ca224->SetRefID(0x10, true);
        DAT_011ca224->SetEditorID_AtRuntime("MapMarker");
        DAT_011ca224->SetModelFilePath("Marker_Map.NIF");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca224);
        DAT_011ca224->SetAltered(false);
    }
    DAT_011ca228 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x23));
    if (!DAT_011ca228)
    {
        DAT_011ca228 = new TESObjectSTAT;
        DAT_011ca228->SetRefID(0x23, true);
        DAT_011ca228->SetEditorID_AtRuntime("AudioMarker");
        DAT_011ca228->SetModelFilePath("Marker_Audio.NIF");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca228);
        DAT_011ca228->SetAltered(false);
    }
    DAT_011ca22c = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x24));
    if (!DAT_011ca22c)
    {
        DAT_011ca22c = new TESObjectSTAT;
        DAT_011ca22c->SetRefID(0x24, true);
        DAT_011ca22c->SetEditorID_AtRuntime("AudioBuoyMarker");
        DAT_011ca22c->SetModelFilePath("Marker_Audio.NIF");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca22c);
        DAT_011ca22c->SetAltered(false);
    }
    DAT_011ca250 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x2));
    if (!DAT_011ca250)
    {
        DAT_011ca250 = new TESObjectSTAT;
        DAT_011ca250->SetRefID(0x2, true);
        DAT_011ca250->SetEditorID_AtRuntime("TravelMarker");
        DAT_011ca250->SetModelFilePath("Marker_Travel.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca250);
        DAT_011ca250->SetAltered(false);
    }
    DAT_011ca254 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x3));
    if (!DAT_011ca254)
    {
        DAT_011ca254 = new TESObjectSTAT;
        DAT_011ca254->SetRefID(0x3, true);
        DAT_011ca254->SetEditorID_AtRuntime("NorthMarker");
        DAT_011ca254->SetModelFilePath("Marker_North.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca254);
        DAT_011ca254->SetAltered(false);
    }
    DAT_011ca258 = dynamic_cast<TESObjectDOOR*>(TESFormInitFlag::GetFormByID(0x4));
    if (!DAT_011ca258)
    {
        DAT_011ca258 = new TESObjectDOOR;
        DAT_011ca258->SetRefID(0x4, true);
        DAT_011ca258->SetEditorID_AtRuntime("PrisonMarker");
        DAT_011ca258->SetModelFilePath("Marker_Prison.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca258);
        DAT_011ca258->SetAltered(false);
    }
    DAT_011ca25c = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x6));
    if (!DAT_011ca25c)
    {
        DAT_011ca25c = new TESObjectSTAT;
        DAT_011ca25c->SetRefID(0x6, true);
        DAT_011ca25c->SetEditorID_AtRuntime("TempleMarker");
        DAT_011ca25c->SetModelFilePath("Marker_Temple.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca25c);
        DAT_011ca25c->SetAltered(false);
    }
    DAT_011ca260 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x5));
    if (!DAT_011ca260)
    {
        DAT_011ca260 = new TESObjectSTAT;
        DAT_011ca260->SetRefID(0x5, true);
        DAT_011ca260->SetEditorID_AtRuntime("DivineMarker");
        DAT_011ca260->SetModelFilePath("Marker_Divine.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca260);
        DAT_011ca260->SetAltered(false);
    }
    DAT_011ca264 = dynamic_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(0x33));
    if (!DAT_011ca264)
    {
        DAT_011ca264 = new TESObjectSTAT;
        DAT_011ca264->SetRefID(0x33, true);
        DAT_011ca264->SetEditorID_AtRuntime("Radiation Marker");
        DAT_011ca264->SetModelFilePath("Marker_Radiation.nif");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca264);
        DAT_011ca264->SetAltered(false);
    }
    DAT_011cb550 = dynamic_cast<TESFaction*>(TESFormInitFlag::GetFormByID(0x13));
    if (!DAT_011cb550)
    {
        DAT_011cb550 = new TESFaction;
        DAT_011cb550->SetRefID(0x13, true);
        DAT_011cb550->SetEditorID_AtRuntime("CreatureFaction");
        GetTESFactionList()->AddHead(DAT_011cb550);
        DAT_011cb550->SetReactionValue(DAT_011cb550, 100);
        DAT_011cb550->InitializeFaction();
        DAT_011cb550->SetInitializationState(true);
        DAT_011cb550->SetAltered(false);
    }
    if (!TESFormInitFlag::GetFormByID(0xf))
    {
        TESObjectMISC* pMisc = new TESObjectMISC;
        pMisc->SetRefID(0xf, true);
        pMisc->SetEditorID_AtRuntime("Caps001");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(pMisc);
        pMisc->SetAltered(false);
    }
    DAT_011c3f40 = static_cast<TESObjectCONT*>(TESFormInitFlag::GetFormByID(0xe));
    if (!DAT_011c3f40)
    {
        DAT_011c3f40 = new TESObjectCONT;
        DAT_011c3f40->SetRefID(0xe, true);
        DAT_011c3f40->SetEditorID_AtRuntime("LootBag");
        if (!DAT_011c3f40->GetModelFilePath() || !BSStringLength(DAT_011c3f40->GetModelFilePath()))
            DAT_011c3f40->SetModelFilePath("Clutter\\Sack01.NIF");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011c3f40);
        DAT_011c3f40->SetAltered(false);
    }
    DAT_011ca278 = static_cast<TESObjectWEAP*>(TESFormInitFlag::GetFormByID(0x1f4));
    if (!DAT_011ca278)
    {
        DAT_011ca278 = new TESObjectWEAP;
        DAT_011ca278->SetRefID(0x1f4, true);
        DAT_011ca278->SetEditorID_AtRuntime("Fists");
        DAT_011ca278->SetByteAtOffsetF4(0);
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(DAT_011ca278);
        DAT_011ca278->SetAltered(false);
    }
    unsigned int pFurnitureMarkerIDs[40] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
                                            114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
                                            128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139};
    const char* iFurnitureMarkerIDs[40] = {
        "FurnitureMarker01", "FurnitureMarker02", "FurnitureMarker03", "FurnitureMarker04", "FurnitureMarker05",
        "FurnitureMarker06", "FurnitureMarker07", "FurnitureMarker08", "FurnitureMarker09", "FurnitureMarker10",
        "FurnitureMarker11", "FurnitureMarker12", "FurnitureMarker13", "FurnitureMarker14", "FurnitureMarker15",
        "FurnitureMarker16", "FurnitureMarker17", "FurnitureMarker18", "FurnitureMarker19", "FurnitureMarker20",
        "FurnitureMarker21", "FurnitureMarker22", "FurnitureMarker23", "FurnitureMarker24", "FurnitureMarker25",
        "FurnitureMarker26", "FurnitureMarker27", "FurnitureMarker28", "FurnitureMarker29", "FurnitureMarker30",
        "FurnitureMarker31", "FurnitureMarker32", "FurnitureMarker33", "FurnitureMarker34", "FurnitureMarker35",
        "FurnitureMarker36", "FurnitureMarker37", "FurnitureMarker38", "FurnitureMarker39", "FurnitureMarker40"};
    for (int i = 0; i < 40; ++i)
    {
        TESObjectSTAT* marker =
            static_cast<TESObjectSTAT*>(TESFormInitFlag::GetFormByID(pFurnitureMarkerIDs[i]));
        if (!marker)
        {
            marker = new TESObjectSTAT;
            marker->SetRefID(pFurnitureMarkerIDs[i], true);
            marker->SetEditorID_AtRuntime(iFurnitureMarkerIDs[i]);
            reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(marker);
            marker->SetAltered(false);
        }
    }
    CreateDefaultTopics();
    if (!TESFormInitFlag::GetFormByID(53))
    {
        TESGlobal* global = new TESGlobal;
        global->SetRefID(53, true);
        global->SetEditorID_AtRuntime("GameYear");
        global->SetValue(77.0f);
        GetTESGlobalList()->AddHead(global);
        DAT_011c54c8->SetAt("GameYear", global);
    }
    if (!TESFormInitFlag::GetFormByID(54))
    {
        TESGlobal* global = new TESGlobal;
        global->SetRefID(54, true);
        global->SetEditorID_AtRuntime("GameMonth");
        global->SetValue(7.0f);
        GetTESGlobalList()->AddHead(global);
        DAT_011c54c8->SetAt("GameMonth", global);
    }
    if (!TESFormInitFlag::GetFormByID(55))
    {
        TESGlobal* global = new TESGlobal;
        global->SetRefID(55, true);
        global->SetEditorID_AtRuntime("GameDay");
        global->SetValue(17.0f);
        GetTESGlobalList()->AddHead(global);
        DAT_011c54c8->SetAt("GameDay", global);
    }
    if (!TESFormInitFlag::GetFormByID(56))
    {
        TESGlobal* global = new TESGlobal;
        global->SetRefID(56, true);
        global->SetEditorID_AtRuntime("GameHour");
        global->SetValue(12.0f);
        GetTESGlobalList()->AddHead(global);
        DAT_011c54c8->SetAt("GameHour", global);
    }
    if (!TESFormInitFlag::GetFormByID(57))
    {
        TESGlobal* global = new TESGlobal;
        global->SetRefID(57, true);
        global->SetEditorID_AtRuntime("GameDaysPassed");
        global->SetValue(1.0f);
        GetTESGlobalList()->AddHead(global);
        DAT_011c54c8->SetAt("GameDaysPassed", global);
    }
    if (!TESFormInitFlag::GetFormByID(58))
    {
        TESGlobal* global = new TESGlobal;
        global->SetRefID(58, true);
        global->SetEditorID_AtRuntime("TimeScale");
        global->SetValue(30.0f);
        GetTESGlobalList()->AddHead(global);
        DAT_011c54c8->SetAt("TimeScale", global);
    }
    pNPC = dynamic_cast<TESNPC*>(TESFormInitFlag::GetFormByID(7));
    if (!pNPC)
    {
        pNPC = new TESNPC;
        pNPC->SetRefID(7, true);
        pNPC->SetEditorID_AtRuntime("Player");
        reinterpret_cast<TESFormList*>(pObjectList)->AddToObjectList(pNPC);
        pNPC->SetAltered(false);
    }
    if (!TESFormInitFlag::GetFormByID(350))
    {
        TESWeather* form = new TESWeather;
        form->SetRefID(350, true);
        form->SetEditorID_AtRuntime("DefaultWeather");
        form->MakeDefault();
        GetTESWeatherList()->AddHead(form);
    }
    if (!TESFormInitFlag::GetFormByID(351))
    {
        TESClimate* form = new TESClimate;
        form->SetRefID(351, true);
        form->SetEditorID_AtRuntime("DefaultClimate");
        form->MakeDefault();
        GetTESClimateList()->AddHead(form);
    }
    Sky::GetInstance()->SetCurrentClimate(0, true);
    if (!TESFormInitFlag::GetFormByID(355))
    {
        BGSListForm* form = new BGSListForm;
        form->SetRefID(355, true);
        form->SetEditorID_AtRuntime("HelpManualPC");
        GetBGSListFormList()->AddHead(form);
    }
    if (!TESFormInitFlag::GetFormByID(357))
    {
        BGSListForm* form = new BGSListForm;
        form->SetRefID(357, true);
        form->SetEditorID_AtRuntime("HelpManualXBox");
        GetBGSListFormList()->AddHead(form);
    }
    const char* helpMessages[64] = {0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    "HelpPipBoyItems",
                                    "HelpPipBoyRepair",
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    "HelpChargenTagSkills",
                                    "HelpChargenRace",
                                    "HelpLeveling",
                                    "HelpDialogue",
                                    0,
                                    "HelpHacking",
                                    "HelpLockpickingPC",
                                    "HelpVATSPC",
                                    "HelpContainer",
                                    "HelpBarter",
                                    "HelpTerminal",
                                    "HelpPipBoyStats",
                                    "HelpPipBoyData",
                                    "HelpVATSXBox",
                                    "HelpLockpickingXBox",
                                    "HelpItemMod",
                                    "HelpCaravanBetting",
                                    "HelpCaravanDeckBuilding",
                                    "HelpCaravanStartingCaravans",
                                    "HelpCaravanContractWar",
                                    "HelpWeapons",
                                    "HelpApparel",
                                    "HelpAmmo",
                                    "HelpAmmoXbox",
                                    "HelpCrafting",
                                    "HelpReputation",
                                    "HelpHardcoreNeeds",
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0};
    for (unsigned int i = 0; i < 64; ++i)
    {
        if (helpMessages[i])
        {
            BGSMessage* message = new BGSMessage;
            message->SetRefID(i + 360, true);
            message->SetEditorID_AtRuntime(helpMessages[i]);
            GetBGSMessageList()->AddHead(message);
        }
    }
    if (!TESFormInitFlag::GetFormByID(352))
    {
        TESImageSpace* image = new TESImageSpace;
        image->SetRefID(352, true);
        image->SetEditorID_AtRuntime("DefaultImageSpaceInterior");
        image->InitDefaults();
        GetTESImageSpaceList()->AddHead(image);
        image = new TESImageSpace;
        image->SetRefID(353, true);
        image->SetEditorID_AtRuntime("DefaultImageSpaceExterior");
        image->InitDefaults();
        GetTESImageSpaceList()->AddHead(image);
    }
    if (!TESFormInitFlag::GetFormByID(354))
    {
        TESImageSpaceModifier* modifier = new TESImageSpaceModifier;
        modifier->SetRefID(354, true);
        modifier->SetEditorID_AtRuntime("GetHit");
        modifier->InitializeModifierData();
        GetTESImageSpaceModifierList()->AddHead(modifier);
    }
    if (!TESFormInitFlag::GetFormByID(358))
    {
        TESImageSpaceModifier* modifier = new TESImageSpaceModifier;
        modifier->SetRefID(358, true);
        modifier->SetEditorID_AtRuntime("ExplosionInFace");
        modifier->InitializeModifierData();
        GetTESImageSpaceModifierList()->AddHead(modifier);
    }
    if (!TESFormInitFlag::GetFormByID(356))
    {
        TESImageSpaceModifier* modifier = new TESImageSpaceModifier;
        modifier->SetRefID(356, true);
        modifier->SetEditorID_AtRuntime("ImageSpaceConcussion");
        modifier->InitializeModifierData();
        GetTESImageSpaceModifierList()->AddHead(modifier);
    }
    MagicSystem::InitializeMagicSystem();
    if (!TESFormInitFlag::GetFormByID(330))
    {
        EffectSetting* effect = new EffectSetting;
        effect->SetRefID(330, true);
        effect->SetEditorID_AtRuntime("ScriptEffect");
        effect->SetFullName("Script Effect");
        RegisterEffectSetting(effect);
    }
    TESSound::InitializeMagicSystem();
    BGSImpactDataSet::CacheImpactDataSet();
    BGSEquipType_GenerateDefaultMenuIcons();
    BGSBodyPartData::InitializeBodyPartData();
    BGSTextureSet::InitializeNullTextureSet();
    BGSEncounterZone::CreateDefaultEncounterZone();
    if (!TESFormInitFlag::GetFormByID(61))
    {
        TESCombatStyle* style = new TESCombatStyle;
        style->SetRefID(61, true);
        style->SetEditorID_AtRuntime("Default Combatstyle");
        GetTESCombatStyleList()->AddHead(style);
    }
    DAT_011c3f3c = static_cast<TESGlobal*>(TESFormInitFlag::GetFormByID(99));
    if (!DAT_011c3f3c)
    {
        DAT_011c3f3c = new TESGlobal;
        DAT_011c3f3c->SetRefID(99, true);
        DAT_011c3f3c->SetEditorID_AtRuntime("PlayCredits");
        DAT_011c3f3c->SetValue(0.0f);
        GetTESGlobalList()->AddHead(DAT_011c3f3c);
        DAT_011c54c8->SetAt("PlayCredits", DAT_011c3f3c);
    }
    BGSDefaultObjectManager::Instance()->InitializeComponent();
}


// @fnv 0x00460090
void* TESDataHandler::GetMusicTypeList()
{
    return reinterpret_cast<void*>(listMusicTypes);
}


// @fnv 0x004600b0
BSSimpleList<MediaSet*>* TESDataHandler::GetMediaSetList()
{
    return reinterpret_cast<BSSimpleList<MediaSet*>*>(listMediaSets);
}


// @fnv 0x004600d0
BSSimpleList<MediaLocationController*>* TESDataHandler::GetMediaLocationControllerList()
{
    return reinterpret_cast<BSSimpleList<MediaLocationController*>*>(listMediaLocationControllers);
}


// @fnv 0x00460170
void TES::ClearField88()
{
    m_pContainingWorldspace = 0;
}


// @fnv 0x00460250
// src: XBOX_PDB 0x00460250
bool TESForm::GetMaster()
{
    return (iFormFlags & 1) ? true : false;
}


// @fnv 0x00460340
bool TESForm::GetDeleted() const
{
    return (iFormFlags & 2) ? true : false;
}


void __fastcall FUN_00471130(TESFile*);

// Iterates the data handler's file list and calls FUN_00471130 on each TESFile.
// @fnv 0x00460360
void TESDataHandler::CloseAllTES()
{
    BSSimpleList<TESFile*>* pList = GetFileList();
    while (pList && pList->GetItem())
    {
        TESFile* pfile = pList->GetItem();
        FUN_00471130(pfile);
        pList = pList->GetNext();
    }
}


// @fnv 0x00461070
void* TESDataHandler::GetLoadScreenList()
{
    return reinterpret_cast<void*>(listLoadScreens);
}


// @fnv 0x00461150
void* TESDataHandler::GetChallengeList()
{
    return reinterpret_cast<char*>(this) + 0x98;
}

// @fnv 0x00461190
// src: XBOX_PDB 0x00461190
int __fastcall TESDataHandler_GetGlobalList(int param_1)
{
    return param_1 + 0xE8;
}


// @fnv 0x004612e0
void* TESDataHandler::GetTopicList()
{
    return reinterpret_cast<char*>(this) + 0x108;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESActorBase;
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESActorBaseData[sizeof(TESActorBaseData) == 52 ? 1 : -1];

// @fnv 0x00461560

bool TESActorBaseData::GetMatchesPCLevel()
{
    return GetFlagBit(0x80);
}


void __cdecl AddTopicToList(int, char*, int);


// Calls AddTopicToList with the argument, the object's field at offset 0x108 and 1.
// @fnv 0x00461780
void TESDataHandler::AddTopic(TESTopic* aiValue)
{
    AddTopicToList((int)aiValue, (char*)this + 0x108, 1);
}


void __cdecl Object_ProcessEntries_0061f360(TESTopicInfo*, void*);

// Passes pNewTopicInfo and the object at offset 0x110 of this TESDataHandler to FUN_0061f360.
// @fnv 0x004617b0
void TESDataHandler::AddTopicInfo(TESTopicInfo* pNewTopicInfo)
{
    Object_ProcessEntries_0061f360(pNewTopicInfo, (char*)this + 0x110);
}


bool __fastcall BGSSaveLoadGame_GetThreadAllowChanges(void*);


struct TLS_004623f0
{
    char pad[0x294];
    unsigned int val;
};
__declspec(thread) TLS_004623f0 g_tls_004623f0;


// Calls FUN_00462480 on this, sets or clears bit 0 of g_tls_004623f0.val based on abValue, and returns the call's result.
// @fnv 0x004623f0
bool BGSSaveLoadGame::SetThreadAllowChanges(bool abValue)
{
    bool bret = BGSSaveLoadGame_GetThreadAllowChanges(this);
    if (!abValue)
    {
        g_tls_004623f0.val |= 1;
    }
    else
    {
        g_tls_004623f0.val &= ~1u;
    }
    return bret;
}


// @fnv 0x00462e80
const char* TESFile::GetPath()
{
    return reinterpret_cast<const char*>(reinterpret_cast<char*>(this) + 0x124);
}


// @fnv 0x00464d30
// src: COMMUNITY 0x00464d30
void TESDataHandler::DataHandler_DisableAssignFormIDs(bool abNewbool)
{
    bLoadingFiles = abNewbool;
}


// @fnv 0x00464d50
void TESDataHandler::SetSpotterShader(TESEffectShader* apEffectShader)
{
    pSpotterShader = apEffectShader;
}


// @fnv 0x00464d70
void TESDataHandler::SetItemDetectedShader(TESEffectShader* apEffectShader)
{
    pItemDetectedShader = apEffectShader;
}


// @fnv 0x00464df0
// src: XBOX_PDB 0x00464df0
BSSimpleList<TESFile*>* TESFile::GetMasterList_00464df0()
{
    return reinterpret_cast<BSSimpleList<TESFile*>*>(reinterpret_cast<char*>(this) + 0x3ec);
}


// @fnv 0x00464e10
// src: XBOX_PDB 0x00464e10
PlayerBase* PlayerCharacter::GetCharacterProgressionInfo()
{
    return reinterpret_cast<PlayerBase*>(reinterpret_cast<char*>(this) + 0x878);
}


void __fastcall FUN_00462fb0(TESDataHandler*);

// Iterates the script list, calling InitItem on each script, then calls FUN_00462fb0 on this TESDataHandler.
// @fnv 0x00465040
void TESDataHandler::FixAllScriptIDs()
{
    BSSimpleList<Script*>* pList = GetScriptList();
    Script* pScript;
    while (pList && (pScript = pList->GetItem()) != 0)
    {
        pScript->InitItem();
        pList = (BSSimpleList<Script*>*)((TESFormList*)pList)->GetFirst();
    }
    FUN_00462fb0(this);
}

struct PathBuilderDetailedPathMeshes
{
    PathBuilderDetailedPathMeshes();
};

// @fnv 0x004694e0
void* __fastcall ConstructPathBuilderDetailedPathMeshes(PathBuilderDetailedPathMeshes* pThis)
{
    pThis->PathBuilderDetailedPathMeshes::PathBuilderDetailedPathMeshes();
    return pThis;
}


class SaveLoadChangeHistory
{
  public:
    bool MatchesHistory(SaveLoadChangeHistory*);
};

// @fnv 0x00469760
bool TESDataHandler::IsIDUsed(unsigned int aiFormID)
{
    if (TESFormInitFlag::GetFormByID(aiFormID))
        return true;
    if (((SaveLoadChangeHistory*)g_BGSSaveLoadGame)->MatchesHistory((SaveLoadChangeHistory*)aiFormID))
        return true;
    return false;
}


// @fnv 0x004697a0
void TESDataHandler::IncrementID()
{
    ++*(unsigned int*)((char*)this + 0x208);
    if ((*(unsigned int*)((char*)this + 0x208) & 0x00ffffff) >= 0x007fffff)
    {
        *(unsigned int*)((char*)this + 0x208) = (*(unsigned int*)((char*)this + 0x208) & 0xff000000) + 0x800;
    }
}


// @fnv 0x0046a010
struct TESFormLoadState : public TESForm
{
    void SetInitializationFlag(bool);
};

void TESFormLoadState::SetInitializationFlag(bool abVal)
{
    abVal ? *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 8) |= 0x200000
          : *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 8) &= ~0x200000;
}

struct BSMultiBoundNode;
struct BSParticleSystemManager;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct Controls;
struct EngineGraphicsType;
struct HINSTANCE__;
struct HWND__;
struct ImageSpaceManager;
struct NiAVObject;
struct NiCamera;
struct NiGeometry;
struct NiRenderedTexture;
struct GraphicsRenderer;
struct SceneGraph;
struct Sun;
struct Main
{
    void Main_AudioInit();
    void SetSceneRoot(NiNode*);
    void InitRenderer();
    void PreSwapProcess();
    void Swap();
    void PostSwapProcess();
    void DrawWorld_BeginRenderTarget(BSRenderedTexture*, bool, bool);
    void DrawWorld_ClearRenderTarget(BSRenderedTexture*, bool);
    void DrawWorld_CopyRenderTarget(BSRenderedTexture*, bool);
    void DrawWorld_ResolveRenderTarget(BSRenderedTexture*, bool);
    void DrawWorld_EndRenderTarget(BSRenderedTexture*);
    void DrawWorld_DoSunShafts(BSRenderedTexture*, ImageSpaceManager*, GraphicsRenderer*, Sun*);
    void DrawWorld_StopRenderTarget(bool, BSRenderedTexture*);
    void DrawWorld_RenderGeometry(NiGeometry*, GraphicsRenderer*);
    void DrawWorld_CopyDepth(bool, BSRenderedTexture*, GraphicsRenderer*, BSRenderedTexture*);
    void DrawWorld_DoDepth(BSShaderAccumulator*, BSRenderedTexture*);
    void DrawWorld_DoVolumetricFog(BSShaderAccumulator*, BSRenderedTexture*);
    void DrawWorld_FinishRender();
    void DrawWorld_PrepareRender();
    void DrawWorld_RenderSunGeometry(GraphicsRenderer*, NiGeometry*, Sun*, BSRenderedTexture*);
    void DrawWorld_DoVelocity(ImageSpaceManager*, GraphicsRenderer*, BSRenderedTexture*);
    void DrawWorld_DoImageSpace(ImageSpaceManager*, GraphicsRenderer*, bool, BSRenderedTexture*);
    void DrawWorld_Navmesh();
    void DrawWorld_RestartRenderTexture(BSRenderedTexture*, bool, unsigned int);
    void DrawWorld_VATS(bool);
    void DrawWorld_RenderAccumulator(BSShaderAccumulator*, BSRenderedTexture*);
    void DrawWorld_ResolveColor(BSRenderedTexture*);
    void DrawWorld_ResolveDepth(BSRenderedTexture*);
    void DrawWorld_ClearRenderState();
    void DrawWorld_WaitForParallelUpdate();
    Sun* DrawWorld_Init();
    bool DrawWorld_VATSOcclusionQuery();
    void DrawWorld_PrepareScreenSplatter();
    BSRenderedTexture* DrawWorld_GetRenderTarget(GraphicsRenderer*, BSRenderedTexture*, bool, bool);
    void DrawWorld_RenderSun(Sun*, bool, bool, bool);
    void DrawWorld_ScreenSplatter(GraphicsRenderer*);
    void DrawWorld_PostScreenSplatter();
    void DrawWorld_Finalize();
    void OnIdle_ScaleLOD();
    void OnIdle_FixActorBones();
    void OnIdle_UpdateMessageBox();
    void OnIdle_UpdateTimer();
    void OnIdle_ProcessPostTimerTask();
    void OnIdle_ProcessTaskBeforeGridA();
    void OnIdle_ProcessTaskBeforeGridB();
    void OnIdle_ProcessTaskBeforeGridC();
    void OnIdle_ProcessTaskBeforeGridD();
    void OnIdle_UpdateCurrentGridCell();
    void OnIdle_ProcessTaskBeforeInterface();
    void OnIdle_DoInterfaceIdle();
    void OnIdle_UpdateImageSpace(bool);
    void OnIdle_ProcessPostImageSpaceTask();
    bool UpdateTextures(float);
    bool IsLocationHighDetail(void*);
    void ForceUpdateTextures();
    void RestoreTextureRangeDefaults();
    void RunCameraPath();
    void OnGameLoaded();
    void RunScripts();
    void DrawDebugText();
    static TESObjectREFR* GetDebugTextRef();
    static void ClearDebugTextRef();
    void QuitGame();
    void ResetGame();
    void SetGame();
    bool GameReset();
    bool GameOver();
    void GameInitialize();
    bool GameReload();
    bool IsSaveLoadActive();
    void ChangeSignedInPlayer();
    void SetSignedInState(bool);
    static void ForceFileCacheCallback(bool);
    static void ClearCustomLaunchData();
    void SetCustomLaunchData(EngineGraphicsType*);
    bool IsThisAReboot();
    void SetActive(bool);
    bool GetActive();
    void SetOnIdle(bool);
    bool GetOnIdle();
    HWND__* GetWindow();
    HINSTANCE__* GetInstance();
    unsigned long GetThread();
    void* GetThreadHandle();
    Controls* GetInputControls();
    bool WmMouseMove(int, int);
    void RefreshAfterSave();
    static NiAVObject* GetSceneGraph(int);
    static SceneGraph* GetWorldSceneGraph();
    static NiNode* WorldRootNode();
    static NiCamera* WorldRootCamera();
    static BSMultiBoundNode* SkyRootNode();
    static NiNode* WeatherRootNode();
    static SceneGraph* MenuRootNode();
    static NiCamera* MenuRootCamera();
    static SceneGraph* MenuRootNode3D();
    static NiCamera* MenuRootCamera3D();
    static void FreeMenuRootNode();
    static void FreeMenuRootNode3D();
    static void CreateMenuRootNode();
    static void CreateMenuSceneGraph();
    static NiNode* LandLODNode();
    static NiNode* ObjectLODNode();
    static NiNode* WaterLODNode();
    static void SetSceneIsComplex(bool);
    static bool GetSceneIsComplex();
    static BSParticleSystemManager* GetMasterParticleSystemManager();
    void RunFrame();
    bool QQuit();
    static unsigned int QFrameCount();
    bool GetFreezeTime();
    void SetFreezeTime(bool);
    bool GetFlyCamera();
    void SetFlyCamera(bool);
    NiRenderedTexture* GetMenuBGTexture();
    static float QFrameAnimTime();
    static bool QFaderToBlackVisible();
    static bool GetOpenConsole();
    static void SetOpenConsole(bool);
    BSShaderAccumulator* QDrawWorldAccum();
    void TakeMenuBackgroundPicture();
    bool ArePathsEqual(char*, char*);
    void* __vecDelDtor(unsigned int);
    bool m_bStateFlag;
    bool m_bSecondaryStateFlag;
    bool m_bTertiaryStateFlag;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    bool m_bSeventhStateFlag;
    bool m_bEighthStateFlag;
    EngineGraphicsType* m_pAssociatedObject;
    bool m_bWindowActive;
    char _pad_d[3];
    HWND__* hWnd;
    HINSTANCE__* hInstance;
    unsigned long m_uiThreadId;
    void* m_pUserData;
    char m_cBuffer20A[20];
    char TaskProcessor[40];
    char m_cBuffer20B[20];
    char m_cBuffer40A[40];
    char m_acDataA[4];
    char m_acDataB[4];
    char m_acDataC[4];
    char m_acDataD[4];
    char m_acStateData[4];
    bool m_bStateDataFlag;
    char _pad_ad[3];
    char m_acTrailingData[4];
};
typedef char _sizecheck_Main[sizeof(Main) == 180 ? 1 : -1];
struct FUN_004f6de0_shell : public Main
{
    bool _GetByte05();
};

// @fnv 0x004f6de0
// src: COMMUNITY 0x004f6de0
bool FUN_004f6de0_shell::_GetByte05()
{
    return m_bSixthStateFlag;
}

struct ExteriorData
{
    void Endian();
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    char m_cGridFlag;
    char _pad_9[3];
};
typedef char _sizecheck_EXTERIOR_DATA[sizeof(ExteriorData) == 12 ? 1 : -1];
struct FUN_00540720_shell : public ExteriorData
{
    void EXTERIOR_DATA_EXTERIOR_DATA();
};

// Sets the three fields of the object to zero and returns the object pointer.
// @fnv 0x00540720
// src: XBOX_PDB 0x00540720
ExteriorData* __fastcall EXTERIOR_DATA_EXTERIOR_DATA(ExteriorData* pThis)
{
    pThis->m_iGridPositionX = 0;
    pThis->m_iGridCoordinateY = 0;
    pThis->m_cGridFlag = 0;
    return pThis;
}


// @fnv 0x00620b80
unsigned int __fastcall GetNavMeshCollectionFlags(NavMeshCollection* self)
{
    return reinterpret_cast<TESObjectREFR*>(self)->GetFlags();
}


// @fnv 0x009c1a50
void* TESDataHandler::GetReputationList()
{
    return reinterpret_cast<char*>(this) + 0x90;
}

class PerkEntryConditionSet;
class TESRecipeCategory;
namespace fnv_00463070 {
struct RecipeCraftingInfo;
struct TESDataHandlerThread : public BSThread
{
    virtual void __vslot_0();
    virtual unsigned int ThreadProc();
    bool WaitFinished();
    char _pad_30[16];
    char m_acThreadData[12];
    TESDataHandler* pThis;
};
typedef char _sizecheck_CompileFilesTask[sizeof(TESDataHandlerThread) == 80 ? 1 : -1];

struct LC3_Node : public TESFormList
{
    void** _ref_006815c0();
    bool _ref_008256d0();
    void _ref_00905330(void**);
    void _ref_0063f7b0();
};
struct LC3_VBase
{
    virtual ~LC3_VBase();
};
struct LC3_RegionList : public LC3_VBase, public LC3_Node
{
};
struct GlobalObject_004aff00
{
    unsigned int GetSize();
};
struct Arr : public GlobalObject_004aff00
{
    unsigned int* GetAt(int);
};
struct LC3_DH
{
    char lc3_p000[4];
    TESFormList* m_pBoundObjectList;
    char lc3_p008[0x1d4];
    Arr arr1dc;
    char lc3_p1dd[0x2b];
    unsigned int u208;
    TESFile* m_pActiveFile;
    char lc3_p210[8];
    unsigned int uiCompiledCount;
    TESFile* compiledFiles[255];
    bool b618;
    bool b619;
    bool b61a;
};
struct LC3_Pad30
{
    virtual void lc3_v0();
    char lc3_pad[0x2c];
};
struct LC3_Comp
{
    virtual void lc3_c0();
    virtual void lc3_c1();
    virtual void lc3_c2();
    virtual void lc3_c3();
    virtual void lc3_c4(int);
};
struct LC3_Actor : public LC3_Pad30, public LC3_Comp
{
};
// Exe 0x00463070: unit-local Interface view; declarations and layout are preserved.
struct TesdatahandlerInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};
struct EffectSettingCollection
{
    void InitializeCollection(bool);
};
bool __fastcall CheckTESFileVersion(TESFile*);
int __fastcall FUN_00471400(void*);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl CheckTopicsForQuest(int);
void __cdecl SortTopicList(int, int);
int __cdecl FindArchiveByName(char*);
void __cdecl LoadBSAFileHook(char*, int, int);
extern StartMenu g_011c4024;
extern StartMenu g_011c4048;
struct LC3_FindData
{
    unsigned int dwFileAttributes;
    unsigned int ftTimes[6];
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

// @fnv 0x00463070
} // namespace fnv_00463070
bool TESDataHandler::LoadPluginFiles(bool abDownloadedContentOnly)
{
    using namespace fnv_00463070;
    TESFile* pfile;
    TESForm* pheadpart;
    LC3_Node* pweatherlist;
    LC3_Node* pRepList;
    LC3_Node* pRecipeCatList;
    LC3_Node* pperkList;
    LC3_RegionList* preglist;
    LC3_Node* penchantList;
    LC3_Node* pprojList;
    TESForm* pRace;
    int pfileList;
    bool badmaster;
    TESForm* pFaction;
    LC3_Node* pFactList;
    TESForm* pCasinoObjectCur;
    TESForm* pCS;
    LC3_Node* pCasinoEntries;
    LC3_Node* pRadiationList;
    TESForm* pperk;
    LC3_Node* paoList;
    LC3_Node* pcamshotlist;
    TESForm* pReputationData;
    TESForm* m_pCardListHeadCur;
    TESForm* ppartData;
    LC3_Node* pimpdatalist;
    LC3_Node* pWorldList;
    LC3_Node* plastList;
    TESForm* pweather;
    TESForm* pChallenge;
    TESForm* pNote;
    TESForm* pRadiation;
    LC3_Node* pSleepDeprevationList;
    LC3_Node* pLSList;
    LC3_Node* pmaster;
    LC3_Node* pspellList;
    TESForm* pcamshot;
    TESForm* pRecipe;
    LC3_Node* pnoteList;
    LC3_Node* pDehydrationList;
    LC3_Node* pacousticSpaceList;
    LC3_Node* pmusicList;
    TESForm* pmediasetList;
    TESForm* pform;
    TESForm* ppartDataList;
    TESForm* pLSType;
    LC3_Node* pLSTypeList;
    LC3_Node* pChallengeList;
    LC3_Node* pragdollList;
    TESForm* pimpdataset;
    LC3_Node* pltex;
    LC3_Node* pSleepDeprevation;
    LC3_Node* pHunger;
    TESForm* pexplosionList;
    LC3_Node* pmessageList;
    TESForm* pltexList;
    LC3_Node* pwaterList;
    LC3_Node* pshader;
    LC3_Node* pzoneList;
    TESObject* i;
    LC3_Node* pragdoll;
    TESForm* pdefobj;
    LC3_Node* m_pRegionObjectListObj;
    unsigned int pDeckList;
    LC3_Node* pzone;
    LC3_Node* pimpdatasetlist;
    TESForm* pLS;
    TESForm* pHungerList;
    TESForm* plight;
    TESForm* pimpdata;
    LC3_Node* pDehydration;
    LC3_Node* pheadpartList;
    LC3_Node* pRaceList;
    AutoMemContext pRecipeCat((MEM_CONTEXT)0x16, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 0x13ba);
    TESForm* pwater;
    TESForm* pshaderList;
    LC3_Node* pRecipeList;
    LC3_Node* pCasinoList;
    TESForm* pQuest;
    LC3_Node* plistformList;
    LC3_Node* plistform;
    TESForm* pmessage;
    LC3_Node* ppackageList;
    LC3_Node* g;
    TESForm* b;
    TESFile* E;
    LC3_Node* w;
    LC3_Node* p;
    TESForm* H;
    unsigned int v;
    TESForm* h;
    TESForm* y;
    TESForm* x;
    TESForm* a;
    TESForm* n;
    ((LC3_DH*)this)->b61a = true;
    if (abDownloadedContentOnly)
        ((LC3_DH*)this)->uiCompiledCount = 0;
    ((TES*)g_TES)->TES_ClearAllCells(0, 0);
    if (!abDownloadedContentOnly)
        g_TES->ClearField88();
    g_TES->SetDawnSound(0);
    ((Calendar*)g_TES)->ResetCachedValues();
    DAT_011c54b9 = 0;

    pheadpartList = (LC3_Node*)GetFileList();
    pfile = 0;
    if (((LC3_DH*)this)->b619)
    {
        FUN_00471400(((LC3_DH*)this)->m_pActiveFile);
        ((LC3_DH*)this)->m_pActiveFile->CheckMasterFiles(GetFileList(), true);
    }
    while (pheadpartList && *pheadpartList->_ref_006815c0())
    {
        pfile = (TESFile*)*pheadpartList->_ref_006815c0();
        if (pfile->GetIsChecked())
        {
            FUN_00471400(pfile);
            pfile->CheckMasterFiles(GetFileList(), true);
            if (!CheckTESFileVersion(pfile))
            {
                v = pfile->GetIndexCount();
                for (pDeckList = 0; pDeckList < v; pDeckList++)
                {
                    E = pfile->GetMasterFile(pDeckList + 1);
                    bool bloaded = false;
                    if (E && !CheckTESFileVersion(E))
                    {
                        ((EffectSettingCollection*)E)->InitializeCollection(true);
                        bloaded = true;
                    }
                    if (!bloaded)
                    {
                        if (pfile->GetIndexName(pDeckList + 1))
                            fnv_00463070::TesdatahandlerInterfaceView::PrintDebugMessage("Unable to find masterfile: %s",
                                                         pfile->GetIndexName(pDeckList + 1));
                        else
                            fnv_00463070::TesdatahandlerInterfaceView::PrintDebugMessage("Unable to find masterfile: <unknown>");
                        ((LC3_DH*)this)->b61a = false;
                        return false;
                    }
                }
            }
            else
            {
                ((EffectSettingCollection*)pfile)->InitializeCollection(false);
            }
        }
        pheadpartList = (LC3_Node*)pheadpartList->GetFirst();
    }

    badmaster = false;
    MessageHandler_IncDisableWarningCount(true);
    pheadpartList = (LC3_Node*)GetFileList();
    plastList = 0;
    while (pheadpartList && *pheadpartList->_ref_006815c0())
    {
        pfile = (TESFile*)*pheadpartList->_ref_006815c0();
        bool bremove = false;
        if (pfile->GetIsChecked())
        {
            if (!pfile->IsMasterFile() && !((LC3_DH*)this)->b618 && pfile->HasMasterFileChanged())
            {
                badmaster = true;
                Warning(static_cast<const StartMenu&>(g_011c4024).GetMenuTitle(), PrepareScriptMessage(pfile->GetName(), false));
            }
            if (pfile->GetActive())
            {
                ((LC3_DH*)this)->m_pActiveFile = pfile;
                pheadpartList = (LC3_Node*)pheadpartList->GetFirst();
                continue;
            }
            ((LC3_DH*)this)->compiledFiles[((LC3_DH*)this)->uiCompiledCount] = pfile;
            pfile->SetCompileIndex(((LC3_DH*)this)->uiCompiledCount++);
            if (((LC3_DH*)this)->uiCompiledCount >= 0xff)
                fnv_00463070::TesdatahandlerInterfaceView::PrintDebugMessage("Too many selected files to compile!");
        }
        else
        {
            bremove = true;
        }
        if (bremove)
        {
            delete pfile;
            if (plastList)
            {
                plastList->_ref_00905330(pheadpartList->_ref_006815c0());
                pheadpartList = (LC3_Node*)plastList->GetFirst();
            }
            else
            {
                pheadpartList->_ref_0063f7b0();
            }
        }
        else
        {
            plastList = pheadpartList;
            pheadpartList = (LC3_Node*)pheadpartList->GetFirst();
        }
    }
    ((LC3_DH*)this)->u208 = 0xff000800;
    if (badmaster)
        Warning(static_cast<const StartMenu&>(g_011c4048).GetMenuTitle());
    MessageHandler_IncDisableWarningCount(false);
    if (((LC3_DH*)this)->m_pActiveFile)
    {
        ((LC3_DH*)this)->compiledFiles[((LC3_DH*)this)->uiCompiledCount] = ((LC3_DH*)this)->m_pActiveFile;
        ((LC3_DH*)this)->m_pActiveFile->SetCompileIndex(((LC3_DH*)this)->uiCompiledCount++);
        if (((LC3_DH*)this)->uiCompiledCount >= 0xff)
            fnv_00463070::TesdatahandlerInterfaceView::PrintDebugMessage("Too many selected files to compile!");
    }

    DAT_011c3f24 = 0;
    for (pDeckList = 0; pDeckList < ((LC3_DH*)this)->uiCompiledCount; pDeckList++)
    {
        if (!((LC3_DH*)this)->compiledFiles[pDeckList]->OpenTESFile((NiFile::OpenMode)0, false))
            ((TESDataHandler*)this)->ReportDataHandlerError(4);
        else
            DAT_011c3f24 += ((LC3_DH*)this)->compiledFiles[pDeckList]->GetFieldAt3E0();
    }
    for (pDeckList = 0; pDeckList < ((LC3_DH*)this)->uiCompiledCount; pDeckList++)
    {
        void* F;
        char* A;
        AutoMemContext C((MEM_CONTEXT)0x13, true,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 0x1532);
        if (!((LC3_Node*)((LC3_DH*)this)->compiledFiles[pDeckList]->GetMasterList_00464df0())->_ref_008256d0())
        {
            char D[260];
            LC3_FindData G;
            char o[260];
            TaskQueueInterface::CopyStringToBuffer(D, 0x104, ((LC3_DH*)this)->compiledFiles[pDeckList]->GetName());
            A = strrchr_0040ab30(D, 0x2e);
            if (A)
                *A = 0;
            _sprintf_s(o, 0x104, "Data\\%s*.bsa", D);
            F = FindFirstFileA(o, (WIN32_FIND_DATAA*)&G);
            if (F != (void*)-1)
            {
                do
                {
                    if (G.nFileSizeHigh != 0 || G.nFileSizeLow != 0)
                    {
                        char r[260];
                        _sprintf_s(r, 0x104, "DATA\\%s", G.cFileName);
                        if (!FindArchiveByName(r))
                            LoadBSAFileHook(r, 0, 0);
                    }
                } while (FindNextFileA(F, (WIN32_FIND_DATAA*)&G));
                FindClose(F);
            }
        }
    }
    DataHandler_DisableAssignFormIDs(true);
    if (!abDownloadedContentOnly)
        InitializeMagicSystem();
    DAT_011c3f28 = 0;
    SetSaveLoadGameState(-3);
    for (pDeckList = 0; pDeckList < ((LC3_DH*)this)->uiCompiledCount; pDeckList++)
    {
        bool bfirst = false;
        if (pDeckList == 0)
            bfirst = true;
        if (abDownloadedContentOnly && (!((LC3_DH*)this)->compiledFiles[pDeckList]->TESMain_GetThread() ||
                                        !((LC3_DH*)this)->compiledFiles[pDeckList]->GetByteAt428()))
            continue;
        if (!((TESDataHandler*)this)->TESDataHandler_ConstructObjectList(((LC3_DH*)this)->compiledFiles[pDeckList], bfirst))
            ((TESDataHandler*)this)->ReportDataHandlerError(3);
    }
    g_dataHandler->SetSaveLoadGameState(-1);
    DataHandler_DisableAssignFormIDs(false);

    pweatherlist = (LC3_Node*)GetTESWeatherList();
    while (pweatherlist && (pweather = (TESForm*)*pweatherlist->_ref_006815c0()) != 0)
    {
        pweather->InitItem();
        pweatherlist = (LC3_Node*)pweatherlist->GetFirst();
    }
    pcamshotlist = (LC3_Node*)GetBGSCameraShotList();
    while (pcamshotlist && (pcamshot = (TESForm*)*pcamshotlist->_ref_006815c0()) != 0)
    {
        pcamshot->InitItem();
        pcamshotlist = (LC3_Node*)pcamshotlist->GetFirst();
    }
    pRaceList = (LC3_Node*)GetTESRaceList();
    while (pRaceList && (pRace = (TESForm*)*pRaceList->_ref_006815c0()) != 0)
    {
        pRace->InitItem();
        pRaceList = (LC3_Node*)pRaceList->GetFirst();
    }
    pimpdatasetlist = (LC3_Node*)GetBGSHeadPartList();
    while (pimpdatasetlist && (pheadpart = (TESForm*)*pimpdatasetlist->_ref_006815c0()) != 0)
    {
        pheadpart->InitItem();
        pimpdatasetlist = (LC3_Node*)pimpdatasetlist->GetFirst();
    }
    pzone = (LC3_Node*)GetBGSEncounterZoneList();
    while (pzone && (n = (TESForm*)*pzone->_ref_006815c0()) != 0)
    {
        n->InitItem();
        pzone = (LC3_Node*)pzone->GetFirst();
    }
    pFactList = (LC3_Node*)GetTESFactionList();
    while (pFactList && (pFaction = (TESForm*)*pFactList->_ref_006815c0()) != 0)
    {
        pFaction->InitItem();
        pFactList = (LC3_Node*)pFactList->GetFirst();
    }
    pRepList = (LC3_Node*)GetTESReputationList();
    while (pRepList && (pReputationData = (TESForm*)*pRepList->_ref_006815c0()) != 0)
    {
        pReputationData->InitItem();
        pRepList = (LC3_Node*)pRepList->GetFirst();
    }
    ppackageList = (LC3_Node*)GetBGSRecipeList();
    while (ppackageList && (pRecipe = (TESForm*)*ppackageList->_ref_006815c0()) != 0)
    {
        pRecipe->InitItem();
        ppackageList = (LC3_Node*)ppackageList->GetFirst();
    }
    w = (LC3_Node*)GetTESChallengeList();
    while (w && (pChallenge = (TESForm*)*w->_ref_006815c0()) != 0)
    {
        pChallenge->InitItem();
        w = (LC3_Node*)w->GetFirst();
    }
    pRecipeCatList = (LC3_Node*)GetBGSRecipeCategoryList();
    while (pRecipeCatList && (plight = (TESForm*)*pRecipeCatList->_ref_006815c0()) != 0)
    {
        plight->InitItem();
        pRecipeCatList = (LC3_Node*)pRecipeCatList->GetFirst();
    }
    pCasinoList = (LC3_Node*)GetTESCasinoList();
    while (pCasinoList && (pCasinoObjectCur = (TESForm*)*pCasinoList->_ref_006815c0()) != 0)
    {
        pCasinoObjectCur->InitItem();
        pCasinoList = (LC3_Node*)pCasinoList->GetFirst();
    }
    pltex = (LC3_Node*)GetTESCaravanDeckList();
    while (pltex && (m_pCardListHeadCur = (TESForm*)*pltex->_ref_006815c0()) != 0)
    {
        m_pCardListHeadCur->InitItem();
        pltex = (LC3_Node*)pltex->GetFirst();
    }
    pSleepDeprevation = (LC3_Node*)GetTESQuestList();
    while (pSleepDeprevation && (pQuest = (TESForm*)*pSleepDeprevation->_ref_006815c0()) != 0)
    {
        pQuest->InitItem();
        pSleepDeprevation = (LC3_Node*)pSleepDeprevation->GetFirst();
    }
    pCasinoEntries = (LC3_Node*)GetTESCombatStyleList();
    while (pCasinoEntries && (pCS = (TESForm*)*pCasinoEntries->_ref_006815c0()) != 0)
    {
        pCS->InitItem();
        pCasinoEntries = (LC3_Node*)pCasinoEntries->GetFirst();
    }
    p = (LC3_Node*)GetTESEffectShaderList();
    while (p && (pexplosionList = (TESForm*)*p->_ref_006815c0()) != 0)
    {
        pexplosionList->InitItem();
        p = (LC3_Node*)p->GetFirst();
    }
    g = (LC3_Node*)GetBGSProjectileList();
    while (g && (h = (TESForm*)*g->_ref_006815c0()) != 0)
    {
        h->InitItem();
        g = (LC3_Node*)g->GetFirst();
    }
    pnoteList = (LC3_Node*)GetBGSNoteList();
    while (pnoteList && (pNote = (TESForm*)*pnoteList->_ref_006815c0()) != 0)
    {
        pNote->InitItem();
        pnoteList = (LC3_Node*)pnoteList->GetFirst();
    }
    plistformList = (LC3_Node*)GetBGSExplosionList();
    while (plistformList && (y = (TESForm*)*plistformList->_ref_006815c0()) != 0)
    {
        y->InitItem();
        plistformList = (LC3_Node*)plistformList->GetFirst();
    }
    pRadiationList = (LC3_Node*)GetBGSRadiationStageList();
    while (pRadiationList && (pRadiation = (TESForm*)*pRadiationList->_ref_006815c0()) != 0)
    {
        pRadiation->InitItem();
        pRadiationList = (LC3_Node*)pRadiationList->GetFirst();
    }
    pDehydrationList = (LC3_Node*)GetBGSDehydrationStageList();
    while (pDehydrationList && (pLS = (TESForm*)*pDehydrationList->_ref_006815c0()) != 0)
    {
        pLS->InitItem();
        pDehydrationList = (LC3_Node*)pDehydrationList->GetFirst();
    }
    pmessageList = (LC3_Node*)GetBGSHungerStageList();
    while (pmessageList && (x = (TESForm*)*pmessageList->_ref_006815c0()) != 0)
    {
        x->InitItem();
        pmessageList = (LC3_Node*)pmessageList->GetFirst();
    }
    pSleepDeprevationList = (LC3_Node*)GetBGSSleepDeprivationStageList();
    while (pSleepDeprevationList && (a = (TESForm*)*pSleepDeprevationList->_ref_006815c0()) != 0)
    {
        a->InitItem();
        pSleepDeprevationList = (LC3_Node*)pSleepDeprevationList->GetFirst();
    }
    pperkList = (LC3_Node*)GetBGSPerkList();
    while (pperkList && (pperk = (TESForm*)*pperkList->_ref_006815c0()) != 0)
    {
        pperk->InitItem();
        pperkList = (LC3_Node*)pperkList->GetFirst();
    }
    pLSList = (LC3_Node*)GetTESLoadScreenList();
    while (pLSList && (pltexList = (TESForm*)*pLSList->_ref_006815c0()) != 0)
    {
        pltexList->InitItem();
        pLSList = (LC3_Node*)pLSList->GetFirst();
    }
    pragdollList = (LC3_Node*)GetTESLoadScreenTypeList();
    while (pragdollList && (pimpdata = (TESForm*)*pragdollList->_ref_006815c0()) != 0)
    {
        pimpdata->InitItem();
        pragdollList = (LC3_Node*)pragdollList->GetFirst();
    }
    paoList = (LC3_Node*)GetTESObjectANIOList();
    while (paoList && (pimpdataset = (TESForm*)*paoList->_ref_006815c0()) != 0)
    {
        pimpdataset->InitItem();
        paoList = (LC3_Node*)paoList->GetFirst();
    }
    pHunger = (LC3_Node*)GetTESWaterFormList();
    while (pHunger && (b = (TESForm*)*pHunger->_ref_006815c0()) != 0)
    {
        b->InitItem();
        pHunger = (LC3_Node*)pHunger->GetFirst();
    }
    pwaterList = (LC3_Node*)GetTESLandTextureList();
    while (pwaterList && (pmediasetList = (TESForm*)*pwaterList->_ref_006815c0()) != 0)
    {
        pmediasetList->InitItem();
        pwaterList = (LC3_Node*)pwaterList->GetFirst();
    }
    H = 0;
    pshader = (LC3_Node*)GetBGSListFormList();
    while (pshader && (H = (TESForm*)*pshader->_ref_006815c0()) != 0)
    {
        H->InitItem();
        pshader = (LC3_Node*)pshader->GetFirst();
    }
    ppartData = 0;
    plistform = (LC3_Node*)GetBGSBodyPartDataList();
    while (plistform && (ppartData = (TESForm*)*plistform->_ref_006815c0()) != 0)
    {
        ppartData->InitItem();
        plistform = (LC3_Node*)plistform->GetFirst();
    }
    pimpdatalist = (LC3_Node*)GetBGSImpactDataList();
    while (pimpdatalist && (pHungerList = (TESForm*)*pimpdatalist->_ref_006815c0()) != 0)
    {
        pHungerList->InitItem();
        pimpdatalist = (LC3_Node*)pimpdatalist->GetFirst();
    }
    pzoneList = (LC3_Node*)GetBGSImpactDataSetList();
    while (pzoneList && (pform = (TESForm*)*pzoneList->_ref_006815c0()) != 0)
    {
        pform->InitItem();
        pzoneList = (LC3_Node*)pzoneList->GetFirst();
    }
    g_calendar.Calendar_InitGlobals();
    pmaster = (LC3_Node*)FUN_004612e0();
    while (pmaster && (pwater = (TESForm*)*pmaster->_ref_006815c0()) != 0)
    {
        pwater->InitItem();
        pmaster = (LC3_Node*)pmaster->GetFirst();
    }
    CheckTopicsForQuest(0);
    SortTopicList(1, (int)((::PlayerCharacter*)g_thePlayer)->GetSelfOffset6A8());
    i = ((LC3_DH*)this)->m_pBoundObjectList->GetFirst();
    while (i)
    {
        i->InitItem();
        i = i->GetNext();
    }
    i = ((LC3_DH*)this)->m_pBoundObjectList->GetFirst();
    while (i)
    {
        switch ((int)i->GetFormType())
        {
        case 0x2a:
        case 0x2b: {
            LC3_Actor* m = (LC3_Actor*)i;
            LC3_Comp* t = m;
            t->lc3_c4(0);
        }
        }
        i = i->GetNext();
    }
    preglist = (LC3_RegionList*)GetRegionList();
    while (preglist && !preglist->_ref_008256d0())
    {
        TESForm* pregion = (TESForm*)*preglist->_ref_006815c0();
        pregion->InitItem();
        preglist = (LC3_RegionList*)(LC3_Node*)preglist->GetFirst();
    }
    pWorldList = (LC3_Node*)GetTESWorldSpaceList();
    while (pWorldList)
    {
        TESForm* pworld = (TESForm*)*pWorldList->_ref_006815c0();
        pWorldList = (LC3_Node*)pWorldList->GetFirst();
    }
    if (g_TES->GetActiveCell())
        g_TES->GetActiveCell()->InitItem();
    pfileList = ((LC3_DH*)this)->arr1dc.GetSize();
    for (int j = 0; j < pfileList; j++)
    {
        TESForm* pnavinfo = (TESForm*)*((LC3_DH*)this)->arr1dc.GetAt(j);
        if (pnavinfo)
            pnavinfo->InitItem();
    }
    pWorldList = (LC3_Node*)GetTESWorldSpaceList();
    while (pWorldList)
    {
        TESForm* pworldspace = (TESForm*)*pWorldList->_ref_006815c0();
        if (pworldspace)
            pworldspace->InitItem();
        pWorldList = (LC3_Node*)pWorldList->GetFirst();
    }
    pmessage = 0;
    pragdoll = (LC3_Node*)GetBGSMessageList();
    while (pragdoll && (pmessage = (TESForm*)*pragdoll->_ref_006815c0()) != 0)
    {
        pmessage->InitItem();
        pragdoll = (LC3_Node*)pragdoll->GetFirst();
    }
    BGSDefaultObjectManager::Instance()->InitItem();
    pdefobj = BGSDefaultObjectManager::Instance()->GetDefaultObjectByIndex(0x1f);
    pshaderList = 0;
    if (pdefobj)
    {
        pshaderList = pdefobj;
        g_dataHandler->FUN_00464d50(pshaderList);
    }
    pdefobj = BGSDefaultObjectManager::Instance()->GetDefaultObjectByIndex(0x20);
    if (pdefobj)
    {
        pshaderList = pdefobj;
        g_dataHandler->FUN_00464d70(pshaderList);
    }
    pdefobj = BGSDefaultObjectManager::Instance()->GetDefaultObjectByIndex(0x21);
    if (pdefobj)
    {
        pshaderList = pdefobj;
        ((TESDataHandler*)g_dataHandler)->SetField638(pshaderList);
    }
    pRecipeList = (LC3_Node*)GetBGSRagdollList();
    while (pRecipeList && (ppartDataList = (TESForm*)*pRecipeList->_ref_006815c0()) != 0)
    {
        ppartDataList->InitItem();
        pRecipeList = (LC3_Node*)pRecipeList->GetFirst();
    }
    pLSTypeList = (LC3_Node*)GetBGSLightingTemplateList();
    while (pLSTypeList && (pLSType = (TESForm*)*pLSTypeList->_ref_006815c0()) != 0)
    {
        pLSType->InitItem();
        pLSTypeList = (LC3_Node*)pLSTypeList->GetFirst();
    }
    DAT_011cb6a0->InitializeIdleAnimations();
    DAT_011ca700->UpdateCameraPaths();
    EffectSettingCollection_InitItems();
    penchantList = (LC3_Node*)GetEnchantmentItemList();
    while (penchantList)
    {
        TESForm* penchant = (TESForm*)*penchantList->_ref_006815c0();
        if (penchant)
            penchant->InitItem();
        penchantList = (LC3_Node*)penchantList->GetFirst();
    }
    pspellList = (LC3_Node*)GetSpellItemList();
    while (pspellList)
    {
        TESForm* pspell = (TESForm*)*pspellList->_ref_006815c0();
        if (pspell)
            pspell->InitItem();
        pspellList = (LC3_Node*)pspellList->GetFirst();
    }
    pacousticSpaceList = (LC3_Node*)GetBGSAcousticSpaceList();
    while (pacousticSpaceList)
    {
        TESForm* pacoustic = (TESForm*)*pacousticSpaceList->_ref_006815c0();
        if (pacoustic)
            pacoustic->InitItem();
        pacousticSpaceList = (LC3_Node*)pacousticSpaceList->GetFirst();
    }
    pDehydration = (LC3_Node*)GetTESImageSpaceModifierList();
    while (pDehydration)
    {
        TESForm* pimod = (TESForm*)*pDehydration->_ref_006815c0();
        if (pimod)
            pimod->InitItem();
        pDehydration = (LC3_Node*)pDehydration->GetFirst();
    }
    pmusicList = (LC3_Node*)GetBGSMusicTypeList();
    while (pmusicList)
    {
        TESForm* pmusic = (TESForm*)*pmusicList->_ref_006815c0();
        if (pmusic)
            pmusic->InitItem();
        pmusicList = (LC3_Node*)pmusicList->GetFirst();
    }
    m_pRegionObjectListObj = (LC3_Node*)GetMediaSetList();
    while (m_pRegionObjectListObj)
    {
        TESForm* pmediaset = (TESForm*)*m_pRegionObjectListObj->_ref_006815c0();
        if (pmediaset)
            pmediaset->InitItem();
        m_pRegionObjectListObj = (LC3_Node*)m_pRegionObjectListObj->GetFirst();
    }
    pChallengeList = (LC3_Node*)GetMediaLocationControllerList();
    while (pChallengeList)
    {
        TESForm* pmediaLoc = (TESForm*)*pChallengeList->_ref_006815c0();
        if (pmediaLoc)
            pmediaLoc->InitItem();
        pChallengeList = (LC3_Node*)pChallengeList->GetFirst();
    }
    pprojList = (LC3_Node*)GetTESPackageList();
    while (pprojList)
    {
        TESForm* ppackage = (TESForm*)*pprojList->_ref_006815c0();
        if (ppackage)
            ppackage->InitItem();
        pprojList = (LC3_Node*)pprojList->GetFirst();
    }
    ValidateFactionReactions();
    MarkGameSettingsLoaded();
    DAT_011c3f30 = 0;
    ((::PlayerCharacter*)g_thePlayer)->GetCharacterProgressionInfo()->CharacterProgression_InitializeData();
    ((LC3_DH*)this)->b61a = false;
    return true;
}


struct PrevHelper
{
    BGSCameraPath* GetPrevPath();
};
struct ArrHelper
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
struct ListNodeHelper
{
    void** FUN_006815c0();
};
// Calls FUN_0054c740(1, 1) on each camera path in the array at this+0x1dc and on the previous path of each world space in the TESWorldSpaceList.
// @fnv 0x00462fb0
void TESDataHandlerUnitOperations::InitializeCellData()
{
    int count2;
    TESFormList* pWorldNode;
    BGSCameraPath* pObj8 = 0;
    count2 = ((ArrHelper*)((char*)this + 0x1dc))->GetSize();
    for (int iIndex = 0; iIndex < count2; ++iIndex)
    {
        pObj8 = (BGSCameraPath*)*((ArrHelper*)((char*)this + 0x1dc))->GetAt(iIndex);
        if (pObj8)
            ((TESObjectCELL*)pObj8)->RunScripts_0054c740(true, true);
    }
    pWorldNode = (TESFormList*)GetTESWorldSpaceList();
    while (pWorldNode)
    {
        BGSCameraPath* world = (BGSCameraPath*)*((ListNodeHelper*)pWorldNode)->FUN_006815c0();
        if (world)
        {
            pObj8 = ((PrevHelper*)world)->GetPrevPath();
            if (pObj8)
                ((TESObjectCELL*)pObj8)->RunScripts_0054c740(true, true);
        }
        pWorldNode = (TESFormList*)pWorldNode->GetFirst();
    }
}

struct FormArray
{
    void* vtbl;
    void** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int SetAtGrow(unsigned int, void**);
    unsigned int AddElement(void** element);
};
// @fnv 0x00470140
unsigned int FormArray::AddElement(void** element)
{
    if (*element == 0)
        return 0xffffffff;
    for (unsigned int i = 0; i < m_uiSize; i++)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = *element;
            m_uiESize++;
            return i;
        }
    }
    return SetAtGrow(m_uiSize, element);
}

struct MapItem
{
    MapItem* m_pkNext;
    unsigned int m_key;
    void* m_val;
};
struct MapNewItemHelper;
struct TMapStandIn
{
    virtual void Reserved0();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int a, unsigned int b);
    virtual void SetValue(MapItem* item, unsigned int key, void* val);
    virtual void ClearValue(MapItem* item);
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    unsigned int m_uiCount;
    bool m_bFlag;
    MapItem* NewItem();
    void InsertOrUpdate(unsigned int key, void* val);
};
// Looks up the key in the hash bucket, updates the matching item's value, or inserts a new item at the bucket head and increments the count.
// @fnv 0x00470200
void TMapStandIn::InsertOrUpdate(unsigned int key, void* val)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    MapItem* pkItem = m_ppkHashTable[uiIndex];
    unsigned int uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (IsKeysEqual(key, pkItem->m_key))
        {
            if (!m_bFlag)
                pkItem->m_key = key;
            pkItem->m_val = val;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }
    pkItem = NewItem();
    SetValue(pkItem, key, val);
    pkItem->m_pkNext = m_ppkHashTable[uiIndex];
    m_ppkHashTable[uiIndex] = pkItem;
    m_uiCount++;
}


// @fnv 0x0045dfc0
BSSimpleList<TESFile*>* TESDataHandler::GetFileList()
{
    return reinterpret_cast<BSSimpleList<TESFile*>*>(listFiles);
}


// @fnv 0x00461010
void* TESDataHandler::GetProjectileList()
{
    return reinterpret_cast<void*>(listProjectiles);
}


// @fnv 0x00461030
void* TESDataHandler::GetRadiationStageList()
{
    return reinterpret_cast<void*>(listRadiation);
}


// @fnv 0x00461050
void* TESDataHandler::GetSleepDeprevationStageList()
{
    return reinterpret_cast<void*>(listSleepDeprevation);
}


// @fnv 0x00461090
void* TESDataHandler::GetAnimObjectList()
{
    return reinterpret_cast<void*>(animObjects);
}


// @fnv 0x00461170
void* TESDataHandler::GetAcousticSpaceList()
{
    return reinterpret_cast<void*>(listAcousticSpaces);
}


// @fnv 0x004611b0
void* TESDataHandler::GetVoiceTypeList()
{
    return reinterpret_cast<void*>(listVoiceTypes);
}


// @fnv 0x004611d0
void* TESDataHandler::GetImpactDataList()
{
    return reinterpret_cast<void*>(listImpactData);
}

// @fnv 0x004611f0
void* TESDataHandler::GetNoteList()
{
    return reinterpret_cast<char*>(this) + 0x188;
}


// @fnv 0x00461210
void* TESDataHandler::GetMenuIconList()
{
    return reinterpret_cast<void*>(listMenuIcons);
}


// @fnv 0x00461230
void* TESDataHandler::GetListFormList()
{
    return reinterpret_cast<char*>(this) + 0x190;
}


// @fnv 0x00461250
void* TESDataHandler::GetMessageList()
{
    return reinterpret_cast<char*>(this) + 0x1A8;
}


// @fnv 0x00461290
void* TESDataHandler::GetLoadScreenTypeList()
{
    return reinterpret_cast<void*>(listLoadScreenTypes);
}

extern "C" unsigned char DAT_01202d63;

// @fnv 0x00461300
// src: XBOX_PDB 0x00461300
void MessageHandler_ForceNextWarningToDisplay()
{
    DAT_01202d63 = 1;
}

struct FUN_00461310_shell
{
    unsigned char m_0024;  // +0x24
    void SetByteAt24(unsigned char a);
};

// @fnv 0x00461310
void FUN_00461310_shell::SetByteAt24(unsigned char a)
{
    *reinterpret_cast<unsigned char*>(this + 0x24) = a;
}

extern TESForm* __cdecl GetFormByID(unsigned int);
extern TESForm* _DAT_01183028;


// @fnv 0x004615d0
TESSound* TESDataHandler::GetSoundByEditorID(unsigned int id)
{
    return dynamic_cast<TESSound*>(GetFormByID(id));
}

struct GlobalObject_00869b10
{
    void RemoveAt(unsigned int);
};


// If node is non-null, removes it from member_0x1ec at the index returned by node->GetIndex().
// @fnv 0x00461930
void TESDataHandler::RemoveAddonNode(BGSAddonNode* node)
{
    if (!node)
        return;
    reinterpret_cast<GlobalObject_00869b10*>(arrayAddonNodes)->RemoveAt(node->GetIndex());
}


// @fnv 0x00462ea0
WIN32_FIND_DATAA* TESFile::GetFileData()
{
    return reinterpret_cast<WIN32_FIND_DATAA*>(reinterpret_cast<char*>(this) + 0x29C);
}

struct Str6a70
{
    Str6a70& operator=(char const*);
};

struct TESFileSummaryWriter : public TESFile
{
    void AssignString(const char*);
};

// @fnv 0x00462ec0
void TESFileSummaryWriter::AssignString(char const* apString)
{
    *reinterpret_cast<Str6a70*>(&m_kSummary) = apString;
}


// @fnv 0x00464db0
bool TESFile::GetByteAt428()
{
    return *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x428);
}


// @fnv 0x00464dd0
unsigned int __thiscall TESFile::GetFieldAt3E0()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x3e0);
}


// @fnv 0x00464e30
BSSimpleList<TESTopic*>* PlayerCharacter::GetSelfOffset6A8()
{
    return reinterpret_cast<BSSimpleList<TESTopic*>*>(reinterpret_cast<char*>(this) + 0x6A8);
}


// @fnv 0x0046a060
bool __fastcall HasLightFlag20(const TESObjectLIGH* self)
{
    return (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(self) + 0xa8) & 0x20) ? true : false;
}



void InventoryChanges::ResetEntryList()
{}



// @fnv 0x0046faf0
void TESDataHandler::ClearBarterContainer()
{
    if (pBarterContainer)
    {
        pBarterContainer->ResetEntryList();
    }
}

TESObject* __fastcall GetReferenceBaseObject(TESObjectREFR*);
bool __fastcall TESForm_GetMustBeVisibleDistant(unsigned int*);


// @fnv 0x00564e00
// src: XBOX_PDB 0x00564e00
bool TESObjectREFR::MustBeVisibleDistant()
{
    bool result = false;
    if (GetReferenceBaseObject(this) && TESForm_GetMustBeVisibleDistant(reinterpret_cast<unsigned int*>(GetReferenceBaseObject(this))))
        result = true;
    return result;
}


// @fnv 0x00984250
void* __fastcall GetObjectDataAtB8(void* self)
{
    return reinterpret_cast<char*>(self) + 0xB8;
}


// @fnv 0x004610b0
void* TESDataHandler::GetCombatStyleList()
{
    return reinterpret_cast<void*>(listCombatStyles);
}

int __fastcall NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(void*);


// @fnv 0x00461960
int __fastcall GetInteriorCellCount(TESDataHandler* self)
{
    return NiTArray_char_NiTMallocInterface_char_GetEffectiveSize((char*)self + 0x1dc);
}


// @fnv 0x00464d90
void TESDataHandler::SetField638(TESForm* value)
{
    *(TESForm**)((char*)this + 0x638) = value;
}


// @fnv 0x0046f070
// src: XBOX_PDB 0x0046f070
bool TESObjectLIGH::GetCanCarry()
{
    return (reinterpret_cast<const unsigned int*>(this)[0x2a] & 2) ? true : false;
}




// @fnv 0x0046fb20
void TESDataHandler::ClearRecipeContainer()
{
    if (pRecipeContainer)
        pRecipeContainer->ResetEntryList();
}


struct FUN_008c6920_shell
{
    unsigned int m_0x00, m_0x04, m_0x08, m_0x0c, m_0x10;
    unsigned int m_0x14;
    void SetFlag(unsigned int auMode, bool abSet);
};

// Sets or clears bit auMode in the m_0x14 bitfield according to abSet.
// @fnv 0x008c6920
void FUN_008c6920_shell::SetFlag(unsigned int auiBitIndex, bool abSet)
{
    if (abSet)
        m_0x14 |= (1u << auiBitIndex);
    else
        m_0x14 &= ~(1u << auiBitIndex);
}


// @fnv 0x00461270
void* TESDataHandler::GetLightingTemplateList()
{
    return reinterpret_cast<void*>(listLightingTemplates);
}

extern char $SG4382[];
// Returns a string pointer from a table indexed by a if a is below 0x79, otherwise returns $SG4382.
// @fnv 0x004612b0
const char* GetStringForByte(unsigned char a)
{
    const char* p;
    if (a < 0x79)
        p = *(const char**)&DAT_01187004[a];
    else
        p = $SG4382;
    return p;
}

TESForm* _GetFormByNumericID(unsigned int);
// Looks up the form with the given numeric ID and returns it cast to TESClass, or null if it is not one.
// @fnv 0x004615a0
TESClass* TESDataHandler::GetClass(unsigned int auiFormID)
{
    return dynamic_cast<TESClass*>(_GetFormByNumericID(auiFormID));
}

struct Arr
{
    unsigned int* GetAt(int);
};
struct InteriorCellLookup : public TESDataHandler
{
    unsigned int GetCameraPathAt(unsigned int);
};
// Compacts the camera path array, then returns the element at aiIndex.
// @fnv 0x00461980
unsigned int InteriorCellLookup::GetCameraPathAt(unsigned int aiIndex)
{
    reinterpret_cast<NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*>(arrayInteriorCells)->Compact();
    return (unsigned int)reinterpret_cast<NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*>(arrayInteriorCells)->GetAt(aiIndex);
}

namespace fnv_00461ae0 {
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
struct WorldSpaceEntry
{
    TESWorldSpace* ws;
};
struct TESDataHandlerCell
{
    TESObjectCELL* cell;
};
struct TESWorldSpaceCell
{
    TESObjectCELL* __thiscall FindEntryByName(const char*);
};
// @fnv 0x00461ae0
} // namespace fnv_00461ae0
TESObjectCELL* TESDataHandler::LookupCellByEditorID(char* pcEditorID)
{
    using namespace fnv_00461ae0;
    if (!pcEditorID)
        return 0;
    int iSize = ((fnv_00461ae0::Arr*)((char*)this + 0x1dc))->GetSize();
    for (int i = 0; i < iSize; ++i)
    {
        TESForm* form = *(TESForm**)((fnv_00461ae0::Arr*)((char*)this + 0x1dc))->GetAt(i);
        if (!BSstricmp(form->GetName(), pcEditorID))
            return (TESObjectCELL*)form;
    }
    BSSimpleList<TESWorldSpace*>* pWorldList = GetTESWorldSpaceList();
    while (pWorldList)
    {
        TESWorldSpace* pspace = pWorldList->GetItem();
        if (pspace)
        {
            TESObjectCELL* pCell = ((TESWorldSpaceCell*)pspace)->FindEntryByName(pcEditorID);
            if (pCell)
                return pCell;
        }
        pWorldList = pWorldList->GetNext();
    }
    return 0;
}


int __cdecl _TruncateFloatToInt(float);
// @fnv 0x00461bc0
TESObjectCELL* __thiscall TESDataHandler::GetCellByWorldPosition(float afX, float afY, TESWorldSpace* apWorldSpace,
                                                         bool abCreateCell)
{
    int m_iGridCoordinateY;
    int m_iGridPositionX;
    m_iGridPositionX = _TruncateFloatToInt(afX) >> 12;
    m_iGridCoordinateY = _TruncateFloatToInt(afY) >> 12;
    return ((TESDataHandler*)this)->GetCellAtGridPosition(m_iGridPositionX, m_iGridCoordinateY, apWorldSpace, abCreateCell);
}

int* __cdecl MessageHandler_GetWarningFileName();
// @fnv 0x0046a330
void TESDataHandler::ReportDataHandlerError(int aiErrorCode)
{
    switch (aiErrorCode)
    {
    case 3:
        Warning("DataHandler: unrecognized form\r\nLook in the %s file for more info.\r\n", MessageHandler_GetWarningFileName());
        break;
    default:
        Warning("DataHandler: internal error");
    }
}

// Invokes the seventh virtual function (f6) on the inner object.
// @fnv 0x0046f090
char* __fastcall GetMaleBipedIconPath(TESBipedModelForm* self)
{
    return self->icon[0].GetTextureResourcePath();
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

extern "C" __declspec(dllimport) int __stdcall FindClose(void*);
// This unit imports lstrcpy through its original IAT entry.
#undef lstrcpy
extern "C" __declspec(dllimport) char* __stdcall lstrcpy(char*, const char*);
extern "C" __declspec(dllimport) char* __stdcall lstrcatA(char*, const char*);

int strcpy_s(char*, unsigned int, const char*);
bool __fastcall TESAnimGroup_GetDecal(BSFile*);
int* __cdecl FUN_00ec85e3();
extern double DAT_01019de8;
extern const float runtimeFloatSettingDefault40;

struct TESFile_Helper
{
    void ResetFileState(bool);
};

// Opens the file at ppath+pfilename, falling back to a .tes file, updating fileData/fileFlags and the stream, and returns whether opening succeeded.
// @fnv 0x00470ca0
bool TESFile::OpenTESFile(char* ppath, char* pfilename, int accessmode, bool lock)
{
    WIN32_FIND_DATAA Data;
    char* pExt;
    WIN32_FIND_DATAA Temp;
    char szFilename[260];
    void* filehandle;
    unsigned int sharemode;
    bool bretval;

    if (!ppath || !pfilename)
        return false;

    sharemode = 1;
    filehandle = 0;
    if (lock)
    {
        sharemode = 0;
        accessmode = NiFile::WRITE_ONLY;
    }

    CopyStringChecked(szFilename, 260, ppath);
    CopyStringChecked(m_acPath, 260, ppath);
    AppendStringChecked(szFilename, 260, pfilename);
    CopyStringChecked(m_acFilename, 260, pfilename);

    if (!m_pFile)
    {
        filehandle = FindFirstFileA(szFilename, &Data);
        if (filehandle == (void*)-1)
        {
            lstrcpy(szFilename, m_acPath);
            pExt = strchr(m_acFilename, '.');
            if (pExt)
            {
                *pExt = 0;
                lstrcatA(szFilename, m_acFilename);
                lstrcatA(szFilename, ".tes");
                *pExt = '.';
            }
            else
            {
                lstrcatA(szFilename, m_acFilename);
                lstrcatA(szFilename, ".tes");
            }
            filehandle = FindFirstFileA(szFilename, &Temp);
            if (filehandle == (void*)-1)
            {
                m_eReturnCode = (TES_RETURN_CODE)2;
            }
            else
            {
                m_eReturnCode = (TES_RETURN_CODE)0xc;
                FindClose(filehandle);
            }
            filehandle = 0;
            return false;
        }
        else
        {
            FindClose(filehandle);
            filehandle = 0;
        }

        if (memcmp(&m_kFindData, &Data, sizeof(Data)))
        {
            m_uiFileCount |= 2;
            memcpy(&m_kFindData, &Data, sizeof(Data));
        }

        m_pFile = new BSFile(szFilename, (NiFile::OpenMode)accessmode, m_uiBufferAllocSize, false);
        if (!m_pFile)
            return false;

        m_pFile->Open(true, false);
        if (!TESAnimGroup_GetDecal(m_pFile))
        {
            switch (*FUN_00ec85e3())
            {
            case 2:
                m_eReturnCode = (TES_RETURN_CODE)2;
                return false;
            case 13:
                m_eReturnCode = (TES_RETURN_CODE)9;
                return false;
            default:
                return false;
            }
        }
    }

    if (TESAnimGroup_GetDecal(m_pFile) && lock)
        GetZeroByte();

    m_uiChunkOffset = m_pFile->GetSize();
    if (!accessmode)
        LoadFormAndUpdateFlag();
    ((TESFile_Helper*)this)->ResetFileState(accessmode == 0);

    bretval = true;
    if ((unsigned int)m_eChunkID != 0x52444548 && GetFileVersion() != DAT_01019de8)
    {
        SetField3DC(runtimeFloatSettingDefault40);
        bretval = OpenTESFile((const char*)ppath, (const char*)pfilename, (NiFile::OpenMode)accessmode, false);
    }
    return bretval;
}


int __cdecl _TruncateFloatToInt(float);
int __cdecl CreateProjectile(TESObjectREFR*, int, int, int, NiPoint3, float, float, int, int, int, int, float, float,
                             TESObjectCELL*);

// @fnv 0x0046a080
TESObjectREFR* TESDataHandler::CreateProjectileAtLocation(TESBoundObject* pProjectile, void* pPosition, void* pDirection,
                                        TESObjectCELL* pCellArg, TESWorldSpace* m_pContainingWorldspace)
{
    int pCell = 0;
    TESObjectCELL* cellX;
    TESObjectREFR* result;
    int pActor;
    int cellY;

    if (pProjectile != 0 && pProjectile->GetFormType() == 0x33)
    {
        result = reinterpret_cast<TESObjectREFR*>(pProjectile);
        cellX = 0;

        if (m_pContainingWorldspace != 0)
        {
            pActor = _TruncateFloatToInt(static_cast<NiPoint3*>(pPosition)->x) >> 12;
            cellY = _TruncateFloatToInt(static_cast<NiPoint3*>(pPosition)->y) >> 12;
            cellX = m_pContainingWorldspace->GetCellAtGridPosition(pActor, cellY);

            if (cellX == 0)
                Warning("CELLS: Trying to create an explosion in an unloaded cell: %i, %i.", pActor, cellY);
        }
        else
        {
            cellX = pCellArg;
        }

        if (cellX != 0)
        {
            pCell = CreateProjectile(result, 0, 0, 0, *static_cast<NiPoint3*>(pPosition), static_cast<NiPoint3*>(pDirection)->z, static_cast<NiPoint3*>(pDirection)->x, 0, 0, 0, 0, 0.0f, 0.0f,
                                     cellX);
        }
    }

    return reinterpret_cast<TESObjectREFR*>(pCell);
}

struct FUN_0087d4a0
{
    FUN_0087d4a0(bool);
    ~FUN_0087d4a0();
};

FUN_0087d4a0::FUN_0087d4a0(bool)
{}

FUN_0087d4a0::~FUN_0087d4a0()
{}

extern int DAT_01086f9c;
extern int DAT_01086fe4;
extern int DAT_01087014;
extern int DAT_0108704c;
extern int DAT_010870a0;
extern int vftable_FUN_008d4500;

struct FUN_008d43a0 : public FUN_0087d4a0
{
    FUN_008d43a0();
};

// @fnv 0x008d43a0
FUN_008d43a0::FUN_008d43a0() : FUN_0087d4a0(true)
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&vftable_FUN_008d4500);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) = reinterpret_cast<int>(&DAT_010870a0);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x88) = reinterpret_cast<int>(&DAT_0108704c);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x94) = reinterpret_cast<int>(&DAT_01087014);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xa4) = reinterpret_cast<int>(&DAT_01086fe4);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xa8) = reinterpret_cast<int>(&DAT_01086f9c);

    reinterpret_cast<TESForm*>(this)->SetFormType(static_cast<ENUM_FORM_ID>(0x3c));

    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1b4) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1b8) = -1.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1bc) = -1.0f;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x140) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x13c) = 0;
}


struct Arr86
{
    void* m_pUnknown;
    BGSAddonNode** m_pBase;
    unsigned short m_usUnknown;
    unsigned short m_usSize;
    unsigned short m_usESize;

    void SetAt(unsigned int, BGSAddonNode*&);
    unsigned int AddAtFirstFreeSlot(BGSAddonNode*&);
};

// Returns -1 for a null element, otherwise fills the first null slot in m_pBase and returns its index, or appends via SetAt when full.
// @fnv 0x009938d0
unsigned int Arr86::AddAtFirstFreeSlot(BGSAddonNode*& element)
{
    if (element == 0)
        return -1;

    unsigned short i = 0;
    for (; i < m_usSize; ++i)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = element;
            ++m_usESize;
            return i;
        }
    }

    SetAt(m_usSize, element);
}

struct FileX
{
    const char* GetName();
};
typedef TESForm FormX;
void __fastcall ClearFormSourceFiles(TESForm*);
template <class T> struct ListX
{
    T item;
    ListX* next;
    T& GetItem();
    void RemoveHead();
};
struct ArrayX
{
    void* pData;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiGrow;
    int GetSize();
    FormX** GetAt(int aiIndex);
    void SetSize(unsigned int auiSize);
};
struct SubX
{
    void ClearItems();
    void TES_ClearAllCells(int a1, int a2);
    void ClearField88();
    SubX* FUN_0043b5d0();
    void BSSimpleList_NiPointer_bhkAction_RemoveAll();
    void ClearHelper();
    void ProcessEntries_005102e0();
    void RemoveAll();
    void TESRegionList_Clear();
    void NavMeshObstacleManager_ClearAllObstacles();
    int TES_GetNavMeshInfoMap();
    void SetNavMeshMaps(int a1);
    bool _GetByte05();
    void DeleteAllOwnedForms();
    void ReleaseStorage_00600030();
    void DestroyCameraPaths();
    void TESFile_SetActive(bool a1);
};
struct FormMapX
{
    void* GetFirstPos();
    void GetNext(void*& arPos, unsigned int& aruiKey, FormX*& arForm);
    void SetAt(unsigned int auiKey, FormX* apForm);
};
extern SubX* xDAT_011c54c4;
extern SubX* xDAT_011dea10;
extern FormX* xDAT_011dea3c;
extern SubX* xDAT_011dea0c;
extern SubX* xDAT_011cb6a0;
extern SubX* xDAT_011ca700;
extern FormMapX* xDAT_011c54c0;
extern void* xDAT_011cb96c;
extern void* xDAT_011ca53c;
extern void* xDAT_011ca220;
extern void* xDAT_011ca224;
extern void* xDAT_011ca228;
extern void* xDAT_011ca22c;
extern void* xDAT_011ca230;
extern void* xDAT_011ca234;
extern void* xDAT_011ca238;
extern void* xDAT_011ca23c;
extern void* xDAT_011ca240;
extern void* xDAT_011ca244;
extern void* xDAT_011ca248;
extern void* xDAT_011ca250;
extern void* xDAT_011ca254;
extern void* xDAT_011ca258;
extern void* xDAT_011ca25c;
extern void* xDAT_011ca260;
extern void* xDAT_011ca268;
extern void* xDAT_011ca26c;
extern const char xDAT_01015890[];
void xFUN_00868d70(int a1);
void xFUN_004ff190();
void xFUN_004c1c40();
void xFUN_00593210();
void xFUN_0058d710();
void xFUN_00460190();
void xFUN_0061a270();
SubX* xFUN_006c0720();
void xFUN_00408de0();
void xFUN_0066f110();
void xFUN_0043b2b0(bool a1);
const char* xFUN_00464f30(const char* apText, bool a2);
void xFUN_005b5e40(const char* apFormat, ...);
void xFUN_00460160();

struct DataHandlerX : public TESDataHandler
{
    void FUN_00464e50();
    ListX<FormX*>* GetBGSMusicTypeList();
    ListX<FormX*>* GetMediaSetList();
    ListX<FormX*>* GetMediaLocationControllerList();
    bool GetByteAt618();
    bool TESDataHandler_ClearData();
};

// @fnv 0x0045dfe0
// src: XBOX_PDB 0x0045dfe0
bool DataHandlerX::TESDataHandler_ClearData()
{
    FormX* pKMmGLv;
    FormX* pWgu;
    FormX* pjmlhnl;
    FormX* pEHugmA;
    FormX* peIDA;
    FormX* pqTbwG;
    FormX* ptPYKb;
    FormX* pVTzq;
    int pAeKOmX;
    FormX* pzgs;
    FormX* pXDu;
    FormX* pkksu;
    FormX* pykMMqV;
    FormX* pFqAbu;
    FormX* pFsjEb;
    FormX* pBXZ;
    FormX* paBfu;
    FormX* pzegc;
    FormX* pXXq;
    FormX* pZZy;
    FormX* pbhd;
    FormX* pkLN;
    FormX* pZAxL;
    FormX* psseb;
    FormX* ppgnst;
    FormX* pnbA;
    FormX* pvXnjs;
    FormX* pTLMyy;
    FormX* pdVf;
    FormX* plOvUXq;
    FormX* pitd;
    FormX* pkPfU;
    FormX* pLeVG;
    FormX* pjBd;
    FormX* pSdMost;
    FormX* pctYxA;
    FormX* pYvOhy;
    FormX* pcovY;
    FormX* poxDbc;
    unsigned int pyQKg;
    FormX* pQPLnsU;
    FormX* pMlL;
    FormX* pZIPgRV;
    FormX* pPYty;
    FormX* pmCJJ;
    FormX* pMor;
    FormX* pFEHUlW;
    FormX* pFSN;
    FormX* pBCl;
    FormX* phIHOr;
    FormX* ptJDiU;
    FormX* pXHB;
    FormX* pPNgxiF;
    FormX* piUewsi;
    FormX* pJFMx;
    FormX* pemFB;
    FormX* pqZjhC;
    FormX* pIkqW;
    FormX* phJJslb;
    FormX* ptkE;
    bClearingData = 1;
    FUN_00464e50();
    xDAT_011c54c4->ClearItems();
    xDAT_011dea10->TES_ClearAllCells(0, 0);
    xDAT_011dea10->ClearField88();
    xDAT_011dea10->FUN_0043b5d0()->BSSimpleList_NiPointer_bhkAction_RemoveAll();
    xFUN_00868d70(0);
    xFUN_004ff190();
    ((SubX*)xDAT_011dea3c)->ClearHelper();
    xFUN_004c1c40();
    xFUN_00593210();
    xFUN_0058d710();
    xFUN_00460190();
    while ((pzegc = (*reinterpret_cast<ListX<FormX*>*>(listScripts)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listScripts)).RemoveHead();
        delete pzegc;
    }
    while ((pkLN = (*reinterpret_cast<ListX<FormX*>*>(listListForms)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listListForms)).RemoveHead();
        delete pkLN;
    }
    while ((pMor = (*reinterpret_cast<ListX<FormX*>*>(listMenuIcons)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listMenuIcons)).RemoveHead();
        delete pMor;
    }
    while ((pPNgxiF = (*reinterpret_cast<ListX<FormX*>*>(listHeadParts)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listHeadParts)).RemoveHead();
        delete pPNgxiF;
    }
    while ((pXXq = (*reinterpret_cast<ListX<FormX*>*>(listHair)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listHair)).RemoveHead();
        delete pXXq;
    }
    while ((pZIPgRV = (*reinterpret_cast<ListX<FormX*>*>(listEyes)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listEyes)).RemoveHead();
        delete pZIPgRV;
    }
    while ((pBXZ = (*reinterpret_cast<ListX<FormX*>*>(listRaces)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listRaces)).RemoveHead();
        delete pBXZ;
    }
    xDAT_011cb96c = 0;
    while ((pPYty = (*reinterpret_cast<ListX<FormX*>*>(listZones)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listZones)).RemoveHead();
        delete pPYty;
    }
    while ((pVTzq = (*reinterpret_cast<ListX<FormX*>*>(listClimates)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listClimates)).RemoveHead();
        delete pVTzq;
    }
    while ((phIHOr = (*reinterpret_cast<ListX<FormX*>*>(listWeather)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listWeather)).RemoveHead();
        delete phIHOr;
    }
    while ((pZAxL = (*reinterpret_cast<ListX<FormX*>*>(listClasses)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listClasses)).RemoveHead();
        delete pZAxL;
    }
    while ((pkksu = (*reinterpret_cast<ListX<FormX*>*>(listFactions)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listFactions)).RemoveHead();
        delete pkksu;
    }
    while ((peIDA = (*reinterpret_cast<ListX<FormX*>*>(listChallenges)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listChallenges)).RemoveHead();
        delete peIDA;
    }
    while ((piUewsi = (*reinterpret_cast<ListX<FormX*>*>(listReputations)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listReputations)).RemoveHead();
        delete piUewsi;
    }
    while ((pKMmGLv = (*reinterpret_cast<ListX<FormX*>*>(listRecipes)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listRecipes)).RemoveHead();
        delete pKMmGLv;
    }
    while ((pykMMqV = (*reinterpret_cast<ListX<FormX*>*>(listCasinos)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listCasinos)).RemoveHead();
        delete pykMMqV;
    }
    while ((pkPfU = (*reinterpret_cast<ListX<FormX*>*>(listRecipeCategories)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listRecipeCategories)).RemoveHead();
        delete pkPfU;
    }
    while ((pZZy = (*reinterpret_cast<ListX<FormX*>*>(listAmmoEffects)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listAmmoEffects)).RemoveHead();
        delete pZZy;
    }
    while ((pFEHUlW = (*reinterpret_cast<ListX<FormX*>*>(listGlobals)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listGlobals)).RemoveHead();
        delete pFEHUlW;
    }
    while ((pWgu = (*reinterpret_cast<ListX<FormX*>*>(listVoiceTypes)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listVoiceTypes)).RemoveHead();
        delete pWgu;
    }
    while ((pctYxA = (*reinterpret_cast<ListX<FormX*>*>(listImpactData)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listImpactData)).RemoveHead();
        delete pctYxA;
    }
    while ((pJFMx = (*reinterpret_cast<ListX<FormX*>*>(listImpactDataSet)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listImpactDataSet)).RemoveHead();
        delete pJFMx;
    }
    while ((psseb = (*reinterpret_cast<ListX<FormX*>*>(listQuests)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listQuests)).RemoveHead();
        delete psseb;
    }
    while ((pvXnjs = (*reinterpret_cast<ListX<FormX*>*>(listTopics)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listTopics)).RemoveHead();
        delete pvXnjs;
    }
    xFUN_0061a270();
    while ((ppgnst = (*reinterpret_cast<ListX<FormX*>*>(listTopicInfos)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listTopicInfos)).RemoveHead();
    }
    pAeKOmX = (*reinterpret_cast<ArrayX*>(arrayInteriorCells)).GetSize();
    for (int i = 0; i < pAeKOmX; i++)
    {
        FormX* pElement = *(*reinterpret_cast<ArrayX*>(arrayInteriorCells)).GetAt(i);
        if (pElement)
        {
            delete pElement;
        }
    }
    (*reinterpret_cast<ArrayX*>(arrayInteriorCells)).SetSize(0);
    while ((pemFB = (*reinterpret_cast<ListX<FormX*>*>(listWorldSpaces)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listWorldSpaces)).RemoveHead();
        delete pemFB;
    }
    xFUN_00868d70(0);
    while ((pqTbwG = (*reinterpret_cast<ListX<FormX*>*>(listSounds)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listSounds)).RemoveHead();
        delete pqTbwG;
    }
    while ((pQPLnsU = GetBGSMusicTypeList()->GetItem()) != 0)
    {
        GetBGSMusicTypeList()->RemoveHead();
        delete pQPLnsU;
    }
    while ((pYvOhy = GetMediaSetList()->GetItem()) != 0)
    {
        GetMediaSetList()->RemoveHead();
        delete pYvOhy;
    }
    while ((pqZjhC = GetMediaLocationControllerList()->GetItem()) != 0)
    {
        GetMediaLocationControllerList()->RemoveHead();
        delete pqZjhC;
    }
    while ((pLeVG = (*reinterpret_cast<ListX<FormX*>*>(listAcousticSpaces)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listAcousticSpaces)).RemoveHead();
        delete pLeVG;
    }
    while ((ptJDiU = (*reinterpret_cast<ListX<FormX*>*>(listLandTexts)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listLandTexts)).RemoveHead();
        delete ptJDiU;
    }
    while ((pnbA = (*reinterpret_cast<ListX<FormX*>*>(listMessages)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listMessages)).RemoveHead();
        delete pnbA;
    }
    delete xDAT_011dea3c;
    xDAT_011dea3c = 0;
    while ((pcovY = (*reinterpret_cast<ListX<FormX*>*>(listImageSpaces)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listImageSpaces)).RemoveHead();
        delete pcovY;
    }
    while ((pFSN = (*reinterpret_cast<ListX<FormX*>*>(listImageSpaceModifiers)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listImageSpaceModifiers)).RemoveHead();
        delete pFSN;
    }
    reinterpret_cast<SubX*&>(pObjectList)->ProcessEntries_005102e0();
    (*reinterpret_cast<SubX*>(arrayAddonNodes)).RemoveAll();
    while ((pBCl = (*reinterpret_cast<ListX<FormX*>*>(listSpellItems)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listSpellItems)).RemoveHead();
        delete pBCl;
    }
    while ((poxDbc = (*reinterpret_cast<ListX<FormX*>*>(listEnchantmentItems)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listEnchantmentItems)).RemoveHead();
        delete poxDbc;
    }
    while ((phJJslb = (*reinterpret_cast<ListX<FormX*>*>(listPackages)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listPackages)).RemoveHead();
        delete phJJslb;
    }
    while ((pjmlhnl = (*reinterpret_cast<ListX<FormX*>*>(listCombatStyles)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listCombatStyles)).RemoveHead();
        delete pjmlhnl;
    }
    while ((pTLMyy = (*reinterpret_cast<ListX<FormX*>*>(listLoadScreens)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listLoadScreens)).RemoveHead();
        delete pTLMyy;
    }
    while ((pjBd = (*reinterpret_cast<ListX<FormX*>*>(listLoadScreenTypes)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listLoadScreenTypes)).RemoveHead();
        delete pjBd;
    }
    while ((pdVf = (*reinterpret_cast<ListX<FormX*>*>(listWater)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listWater)).RemoveHead();
        delete pdVf;
    }
    xDAT_011ca53c = 0;
    while ((pXHB = (*reinterpret_cast<ListX<FormX*>*>(animObjects)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(animObjects)).RemoveHead();
        delete pXHB;
    }
    while ((plOvUXq = (*reinterpret_cast<ListX<FormX*>*>(listEffectShaders)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listEffectShaders)).RemoveHead();
        delete plOvUXq;
    }
    while ((pEHugmA = (*reinterpret_cast<ListX<FormX*>*>(listProjectiles)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listProjectiles)).RemoveHead();
        delete pEHugmA;
    }
    while ((pFqAbu = (*reinterpret_cast<ListX<FormX*>*>(listExplosions)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listExplosions)).RemoveHead();
        delete pFqAbu;
    }
    while ((pbhd = (*reinterpret_cast<ListX<FormX*>*>(listDebris)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listDebris)).RemoveHead();
        delete pbhd;
    }
    while ((pFsjEb = (*reinterpret_cast<ListX<FormX*>*>(listPerks)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listPerks)).RemoveHead();
        delete pFsjEb;
    }
    while ((pitd = (*reinterpret_cast<ListX<FormX*>*>(listRadiation)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listRadiation)).RemoveHead();
        delete pitd;
    }
    while ((paBfu = (*reinterpret_cast<ListX<FormX*>*>(listDehydration)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listDehydration)).RemoveHead();
        delete paBfu;
    }
    while ((ptPYKb = (*reinterpret_cast<ListX<FormX*>*>(listHunger)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listHunger)).RemoveHead();
        delete ptPYKb;
    }
    while ((ptkE = (*reinterpret_cast<ListX<FormX*>*>(listSleepDeprevation)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listSleepDeprevation)).RemoveHead();
        delete ptkE;
    }
    while ((pIkqW = (*reinterpret_cast<ListX<FormX*>*>(listPartData)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listPartData)).RemoveHead();
        delete pIkqW;
    }
    reinterpret_cast<SubX*&>(pRegionList)->TESRegionList_Clear();
    xFUN_006c0720()->NavMeshObstacleManager_ClearAllObstacles();
    if (xDAT_011dea10->TES_GetNavMeshInfoMap())
    {
        xDAT_011dea10->SetNavMeshMaps(0);
    }
    if (!xDAT_011dea0c || !xDAT_011dea0c->_GetByte05())
    {
        xDAT_011cb6a0->DeleteAllOwnedForms();
    }
    else
    {
        xDAT_011cb6a0->ReleaseStorage_00600030();
    }
    xDAT_011ca700->DestroyCameraPaths();
    while ((pzgs = (*reinterpret_cast<ListX<FormX*>*>(listCameraShots)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listCameraShots)).RemoveHead();
        delete pzgs;
    }
    while ((pSdMost = (*reinterpret_cast<ListX<FormX*>*>(listLightingTemplates)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listLightingTemplates)).RemoveHead();
        delete pSdMost;
    }
    xFUN_00408de0();
    xFUN_0066f110();
    while ((pMlL = (*reinterpret_cast<ListX<FormX*>*>(listNotes)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listNotes)).RemoveHead();
        delete pMlL;
    }
    while ((pmCJJ = (*reinterpret_cast<ListX<FormX*>*>(listRagdolls)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listRagdolls)).RemoveHead();
        delete pmCJJ;
    }
    while ((pXDu = (*reinterpret_cast<ListX<FormX*>*>(listCaravanDecks)).GetItem()) != 0)
    {
        (*reinterpret_cast<ListX<FormX*>*>(listCaravanDecks)).RemoveHead();
        delete pXDu;
    }
    if (xDAT_011c54c0)
    {
        xFUN_0043b2b0(1);
        bool bLeakedIn = false;
        FormX* pLeakedNum = 0;
        unsigned int uiKeyNum80 = 0;
        void* pPosQ = xDAT_011c54c0->GetFirstPos();
        while (pPosQ)
        {
            xDAT_011c54c0->GetNext(pPosQ, uiKeyNum80, pLeakedNum);
            if (pLeakedNum)
            {
                switch (pLeakedNum->GetFormType())
                {
                case 3:
                    ClearFormSourceFiles(pLeakedNum);
                    pLeakedNum->SetRefID(0, true);
                    break;
                default:
                    xFUN_005b5e40(
                        "FORMS: Form '%s' (%08X) of type %s in file '%s' was not freed.",
                        xFUN_00464f30(pLeakedNum->GetName(), 0), pLeakedNum->GetFormID(), pLeakedNum->TESForm_GetFormTypeString(),
                        pLeakedNum->GetFile(-1) ? xFUN_00464f30(pLeakedNum->GetFile(-1)->GetName(), 0) : xDAT_01015890);
                    xDAT_011c54c0->SetAt(uiKeyNum80, 0);
                    bLeakedIn = true;
                    break;
                }
            }
        }
        xFUN_0043b2b0(0);
        if (bLeakedIn)
        {
            xFUN_005b5e40("FORMS: Forms were leaked during ClearData. Check Warnings file for more info.");
        }
    }
    for (pyQKg = 0; pyQKg < iNumCompile; pyQKg++)
    {
        reinterpret_cast<int*>(pFileIndex)[pyQKg] = 0;
    }
    iNumCompile = 0;
    if (!bSaveLoadGame && pActiveFile)
    {
        if (!GetByteAt618())
        {
            ((SubX*)pActiveFile)->TESFile_SetActive(0);
        }
        if (pActiveFile)
        {
            delete pActiveFile;
        }
        pActiveFile = 0;
        iNextID = 0x800;
    }
    xFUN_00460160();
    xDAT_011ca220 = 0;
    xDAT_011ca224 = 0;
    xDAT_011ca228 = 0;
    xDAT_011ca22c = 0;
    xDAT_011ca230 = 0;
    xDAT_011ca234 = 0;
    xDAT_011ca238 = 0;
    xDAT_011ca23c = 0;
    xDAT_011ca240 = 0;
    xDAT_011ca244 = 0;
    xDAT_011ca248 = 0;
    xDAT_011ca250 = 0;
    xDAT_011ca254 = 0;
    xDAT_011ca258 = 0;
    xDAT_011ca25c = 0;
    xDAT_011ca260 = 0;
    xDAT_011ca268 = 0;
    xDAT_011ca26c = 0;
    bClearingData = 0;
    reinterpret_cast<int&>(pItemDetectedShader) = 0;
    reinterpret_cast<int&>(pSpotterShader) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x638) = 0;
    return true;
}




typedef bool(__thiscall* FUN_00460270_vfn)(void*, unsigned int);

// Returns false if reinterpret_cast<unsigned int>(pActiveFile) is zero; otherwise compares the form's id with reinterpret_cast<unsigned int>(pActiveFile) and dispatches a virtual call on the form based on its checks.
// @fnv 0x00460270
bool TESDataHandler::SaveForm(TESForm* pForm, bool unused)
{
    unsigned int id;
    bool flagTmp;
    if (reinterpret_cast<unsigned int>(pActiveFile) == 0)
    {
        return false;
    }
    id = reinterpret_cast<unsigned int>(pForm->FUN_00484e60(-1));
    flagTmp = false;
    if ((!(id != reinterpret_cast<unsigned int>(pActiveFile) || pActiveFile->IsMasterFile()) ||
         pForm->GetDeleted()) ||
        flagTmp)
    {
        if (pForm->GetMaster())
        {
            return ((FUN_00460270_vfn)(*(void***)pForm)[13])(pForm, reinterpret_cast<unsigned int>(pActiveFile));
        }
        else
        {
            if (pForm->IsDeleted())
            {
                return false;
            }
            return ((FUN_00460270_vfn)(*(void***)pForm)[10])(pForm, reinterpret_cast<unsigned int>(pActiveFile));
        }
    }
    return false;
}

struct CellCoordHelper
{
    unsigned int GetCellKey(int x, int y);
};
// The shared header does not yet declare this unit's cell-ID lookup entry point.
struct TESSaveLoadGameUnitOperations : TESSaveLoadGame
{
    unsigned int LookupCellID(unsigned int key);
};
struct CellSetupHelper
{
    void SetupA(bool b);
    void SetupB();
    void SetupCoords(int x, int y);
    void SetFlagsByte(unsigned char f);
};
struct CellWorldHelper
{
    bool AddCellToWorld(TESObjectCELL* cell);
};


// Creates a TESObjectCELL for the given editorID and coordinates, assigns its ref ID and flags, adds it to the world, and returns it or null on failure.
// @fnv 0x00461330
TESObjectCELL* TESDataHandlerUnitOperations::CreateExteriorCell(const char* editorID, int x, int y, TESWorldSpace* world)
{
    if (!world)
        return 0;
    AutoMemContext memContext3((MEM_CONTEXT)0x1a, true,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESDataHandler.cpp", 0x7dd);
    TESObjectCELL* pCell = new TESObjectCELL;
    unsigned int uiID = 0;
    uiID = ((TESSaveLoadGameUnitOperations*)g_TESSaveLoadGame)->LookupCellID(((CellCoordHelper*)world)->GetCellKey(x, y));
    if (uiID)
        pCell->SetRefID(uiID, true);
    if (editorID)
        pCell->SetEditorID_AtRuntime(editorID);
    char cFlags = 0;
    ((CellSetupHelper*)pCell)->SetupA(false);
    cFlags |= 2;
    ((CellSetupHelper*)pCell)->SetFlagsByte(cFlags);
    ((CellSetupHelper*)pCell)->SetupB();
    ((CellSetupHelper*)pCell)->SetupCoords(x, y);
    if (!world->HasCell(pCell))
    {
        delete pCell;
        pCell = 0;
    }
    else
    {
        pCell->InitItem();
    }
    return pCell;
}

extern "C" unsigned char __fastcall FUN_008256d0(void*);
extern "C" TESForm** __fastcall FUN_006815c0(void*);
extern "C" void* __fastcall FUN_00726070(void*);
int __cdecl BSstricmp(const char*, const char*);
// Walks the list at this+0xe8 and returns the first TESForm whose editor ID matches editorID, or 0 if none matches.
// @fnv 0x00461700
TESForm* TESDataHandlerUnitOperations::FindFormByEditorID(const char* editorID)
{
    if (!FUN_008256d0((char*)this + 0xe8))
    {
        TESForm* form;
        void* node = (char*)this + 0xe8;
        while (node != 0)
        {
            form = *FUN_006815c0(node);
            if (form != 0)
            {
                if (BSstricmp(form->GetName(), editorID) == 0)
                {
                    return form;
                }
            }
            node = FUN_00726070(node);
        }
    }
    return 0;
}

struct SortPath
{
    const char* Name();
};
struct SortPathArray
{
    void Compact();
    int GetSize();
    SortPath*& GetAt(unsigned int);
    void SetAt(unsigned int, SortPath*&);
};
int __cdecl BSstricmp(const char*, const char*);
struct SortHandler : TESDataHandler
{
    void TESDataHandler_SortInteriorCells();
};
// Compacts the (*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)) array and selection-sorts it by SortPath::Name() using FUN_00404dc0 as the comparator.
// @fnv 0x004619b0
// src: XBOX_PDB 0x004619b0
void SortHandler::TESDataHandler_SortInteriorCells()
{
    reinterpret_cast<SortPathArray*>(&(*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)))->Compact();
    int count = reinterpret_cast<SortPathArray*>(&(*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)))->GetSize();
    for (int i = 0; i < count - 1; i++)
    {
        SortPath* first = reinterpret_cast<SortPathArray*>(&(*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)))->GetAt(i);
        SortPath* best = first;
        int index = i;
        for (int j = i + 1; j < count; j++)
        {
            SortPath* next = reinterpret_cast<SortPathArray*>(&(*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)))->GetAt(j);
            if (best && next)
            {
                if (BSstricmp(next->Name(), best->Name()) < 0)
                {
                    best = next;
                    index = j;
                }
            }
            else if (!best)
            {
                best = next;
                index = j;
            }
        }
        if (best && best != first)
        {
            reinterpret_cast<SortPathArray*>(&(*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)))->SetAt(i, best);
            reinterpret_cast<SortPathArray*>(&(*reinterpret_cast<NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> >*>(arrayInteriorCells)))->SetAt(index, first);
        }
    }
}

struct DeletionObject;
struct ReferenceOwner
{
    void TESObjectLAND_UnLoadVertices();
};
struct ReferenceManager
{
    void TESWorldSpace_UnLoadCell(DeletionObject*);
};
struct DeletionObject
{
    bool FUN_00440d80();
    void TESObjectCELL_Detach(bool);
    void SetState(bool);
    void RemoveNonPersistentRefs();
    void ProcessRefrList();
    bool FUN_00551620();
    void TESObjectCELL_SetLowestProcessToMiddleLow(bool);
    void ChangeProcessLevel(bool);
    bool FUN_00425fd0();
    ReferenceOwner* TESObjectCELL_GetLand();
    void TESObjectCELL_Clear3D();
    void SetByteAt54(bool);
    ReferenceManager* FUN_0054ddd0();
};
struct DeletionSaveState
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
    bool FUN_004623f0(bool);
};
extern DeletionSaveState* DAT_011ddf38;
struct DeletionGameState
{
    bool FUN_0094df60();
};
extern DeletionGameState* DAT_011dea3c;
struct DeletionDataHandler
{
    bool TESDataHandler_GetClearingData();
    void DeleteObject(DeletionObject* object);
};
struct DeletionQueueMethods
{
    void ProcessLists_RemoveTempEffectsForCell(DeletionObject*);
};
void __cdecl BSTaskThread_SetPauseSleepEnabled(bool);
// @fnv 0x00462290
void DeletionDataHandler::DeleteObject(DeletionObject* object)
{
    if (!object || object->FUN_00440d80())
        return;
    BSTaskThread_SetPauseSleepEnabled(true);
    bool bPreviousSaveState = false;
    if (DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading())
        bPreviousSaveState = DAT_011ddf38->FUN_004623f0(false);
    object->TESObjectCELL_Detach(true);
    reinterpret_cast<DeletionQueueMethods*>(&DAT_011e0e80)->ProcessLists_RemoveTempEffectsForCell(object);
    object->SetState(true);
    object->RemoveNonPersistentRefs();
    object->ProcessRefrList();
    while (object->FUN_00551620())
        object->TESObjectCELL_SetLowestProcessToMiddleLow(false);
    if (!reinterpret_cast<DeletionDataHandler*>(g_dataHandler)->TESDataHandler_GetClearingData())
    {
        object->ChangeProcessLevel(!DAT_011dea3c->FUN_0094df60());
    }
    if (!object->FUN_00425fd0())
        object->TESObjectCELL_GetLand()->TESObjectLAND_UnLoadVertices();
    object->TESObjectCELL_Clear3D();
    object->SetByteAt54(false);
    if (!object->FUN_00425fd0())
        object->FUN_0054ddd0()->TESWorldSpace_UnLoadCell(object);
    if (DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading())
        DAT_011ddf38->FUN_004623f0(bPreviousSaveState);
    BSTaskThread_SetPauseSleepEnabled(false);
}

struct FUN_00464e50_list
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    void* Modelloader_GetReferencedThis();
    void NiTPointerListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_RemoveAll();
    void* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(void**);
};


void MessageHandler_ForceNextWarningToDisplay();
void Warning_005b5e40(const char*);


// @fnv 0x00464e50
void TESDataHandlerUnitOperations::ClearPendingReferences()
{
    if (!((FUN_00464e50_list*)((char*)this + 0x1fc))->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() && DAT_011c54b9)
    {
        MessageHandler_ForceNextWarningToDisplay();
        Warning_005b5e40(
            "MASTERFILE: Invalid forms were encountered on load and need to be removed from the master file. Contact a programmer immediately to fix any problems in the file.");
        return;
    }
    bool flagTmp = TESDataHandler_GetClearingData();
    SetCellQueueProcessing(true);
    TESForm* cur_2 = (TESForm*)((FUN_00464e50_list*)((char*)this + 0x1fc))->Modelloader_GetReferencedThis();
    TESForm* a;
    TESForm* t;
    TESForm* b;
    while (cur_2 != 0)
    {
        a = *(TESForm**)((FUN_00464e50_list*)((char*)this + 0x1fc))->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext((void**)&cur_2);
        t = a;
        b = t;
        b != 0 ? (reinterpret_cast<unsigned int (__thiscall*)(TESForm*, int)>((*reinterpret_cast<void***>(b))[4]))(b, 1) : 0;
    }
    ((FUN_00464e50_list*)((char*)this + 0x1fc))->NiTPointerListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_RemoveAll();
    SetCellQueueProcessing(flagTmp);
}

typedef void* HANDLE;
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) DWORD __stdcall GetFileSize(HANDLE, DWORD*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(HANDLE);
void __cdecl FNV_Warning(const char*, ...);
struct TextureScanner
{
    void CheckTextureFileForEmbeddedData(const char* path);
};
// Opens the file at path, reads it, and warns if the bytes contain the "NiRawImageData" marker, then closes the handle.
// @fnv 0x0046f0c0
void TextureScanner::CheckTextureFileForEmbeddedData(const char* path)
{
    HANDLE hFile = CreateFileA(path, 0x80000000, 1, 0, 3, 0x08000001, 0);
    if (hFile != (HANDLE)-1)
    {
        DWORD size = GetFileSize(hFile, 0);
        if (size)
        {
            char* buffer = new char[size];
            DWORD uiBytesRead;
            ReadFile(hFile, buffer, size, &uiBytesRead, 0);
            if (uiBytesRead == size && size > 15)
            {
                for (unsigned int index = 0; index < size - 15; index++)
                {
                    if (buffer[index] == 'N' && buffer[index + 1] == 'i' && buffer[index + 2] == 'R' &&
                        buffer[index + 3] == 'a' && buffer[index + 4] == 'w' && buffer[index + 5] == 'I' &&
                        buffer[index + 6] == 'm' && buffer[index + 7] == 'a' && buffer[index + 8] == 'g' &&
                        buffer[index + 9] == 'e' && buffer[index + 10] == 'D' && buffer[index + 11] == 'a' &&
                        buffer[index + 12] == 't' && buffer[index + 13] == 'a')
                    {
                        FNV_Warning("TEXTURES: Export \"%s\" again without textures embedded.\r\n", path);
                        break;
                    }
                }
            }
        }
        CloseHandle(hFile);
    }
}

struct Helper_cls
{
    unsigned int m_00;
    unsigned int FUN_00541a30(int flag);
};

struct ReferenceHelperOwner : public TESObjectREFR
{
    void SetHelper(Helper_cls*);
};

// @fnv 0x00557760
void ReferenceHelperOwner::SetHelper(Helper_cls* pHelper)
{
    if (reinterpret_cast<Helper_cls*&>(m_pRenderData) != 0)
    {
        Helper_cls* b = reinterpret_cast<Helper_cls*&>(m_pRenderData);
        Helper_cls* a = b;
        (a != 0) ? a->FUN_00541a30(1) : 0;
    }
    reinterpret_cast<Helper_cls*&>(m_pRenderData) = pHelper;
}

struct HandlerOperations
{
    ListNodeHelper* TESDataHandler_GetWorldSpaceList();
    unsigned char FUN_004516b0();
    TESObjectCELL* FUN_00461330(void* initializer, int x, int y, TESWorldSpace* space);
};
struct WorldOperations
{
    TESObjectCELL* FUN_005875a0(int x, int y);
};
extern "C" void __cdecl Warning_005b5e40(const void*, int, int);
extern char UNK_010187a0;
extern char UNK_01011584;
// Returns the cell at grid coordinates x,y in world, creating it when missing if allowed; rejects coordinates outside -32768..32767.
// @fnv 0x00461c20
TESObjectCELL* TESDataHandler::GetCellAtGridPosition(int x, int y, TESWorldSpace* world, bool createMissing)
{
    if (!world)
    {
        world = (TESWorldSpace*)*(((HandlerOperations*)this)->TESDataHandler_GetWorldSpaceList()->FUN_006815c0());
        if (!world)
            return 0;
    }
    if (x > 32767 || y > 32767 || x < -32768 || y < -32768)
    {
        Warning_005b5e40(&UNK_010187a0, -32768, 32767);
        return 0;
    }
    TESObjectCELL* cell = ((WorldOperations*)world)->FUN_005875a0(x, y);
    if (cell)
        return cell;
    if (!((HandlerOperations*)this)->FUN_004516b0() && createMissing)
        return ((HandlerOperations*)this)->FUN_00461330(&UNK_01011584, x, y, world);
    else
        return 0;
}

struct ExtraEditor
{
    int unk00, unk04, unk08, unk0c;
    ExtraEditor(const char*);
};
struct ExtraOps
{
    void ExtraDataList_SetPortalLinkedRoomRef(int, TESForm*);
    void AddExtra(ExtraEditor*);
    void FUN_0041aeb0();
};
struct FloatMatrix3
{
    float values[9];
};
struct RefOps
{
    void TESObjectREFR_SetObjectReference(TESBoundObject*);
    bool TESObjectREFR_GetRefPersists_005653d0();
    void TESObjectREFR_SetRefPersists(bool);
    bool TESObjectREFR_MustRefPersist();
    ExtraOps* GetExtra();
    void TESForm_SetFireOff(bool);
    void FUN_004846a0(bool);
    void TESObjectREFR_SetLocationOnReference(NiPoint3*);
    void TESObjectREFR_SetAngleOnReference(NiPoint3);
    void* TESObjectREFR_HasContainer();
    void TESObjectREFR_SetDroppedRef(bool);
    FloatMatrix3 TESObjectREFR_GetOrientation();
};
struct WorldOps
{
    void FUN_00587ff0(TESObjectREFR*);
};
struct WorldStateManager
{
    bool FUN_004511e0(TESObjectCELL*, bool);
};
extern WorldStateManager* DAT_011dea10;
bool __cdecl BGSDestructibleObjectForm_IsDestructible(TESBoundObject*);
struct InventoryView
{
    void InventoryChanges_InitLeveledItems();
    void InventoryChanges_InitFromContainerExtra();
    void InventoryChanges_InitScripts();
    bool InventoryChanges_IsEmpty();
};
InventoryView* __cdecl FUN_004bf220(TESObjectREFR*);
void __cdecl bhkNiCollisionObject_ResetSim(NiNode*, bool);
struct ShadowView
{
    void FUN_00b5eeb0(NiNode*);
};
ShadowView* __cdecl FUN_00450b80(int);
struct RefVirtualView
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void FUN_48(int);
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual NiNode* Get3D();
};
class FUN_008d1d30 : public TESObjectREFR
{
  public:
    FUN_008d1d30();
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
};
class CreatureRef : public TESObjectREFR
{
  public:
    CreatureRef();
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
};
struct HandlerView : TESDataHandler
{
    bool FUN_00469860(unsigned int);
    TESObjectREFR* TESDataHandler_CreateExplosionAtLocation(TESBoundObject*, NiPoint3*, NiPoint3*, TESObjectCELL*, TESWorldSpace*);
    TESObjectREFR* CreateExplosion(TESBoundObject*, NiPoint3*, NiPoint3*, TESObjectCELL*, TESWorldSpace*);
    TESObjectREFR* PlaceObjectReference(TESBoundObject*, NiPoint3*, NiPoint3*, TESObjectCELL*, TESWorldSpace*,
                                        TESObjectREFR*, const char*, TESForm*);
};
// @fnv 0x004698a0
TESObjectREFR* HandlerView::PlaceObjectReference(TESBoundObject* base, NiPoint3* position, NiPoint3* rotation,
                                                 TESObjectCELL* apInteriorCell, TESWorldSpace* apWorldSpace,
                                                 TESObjectREFR* apExistingRef, const char* editorID, TESForm* owner)
{
    TESObjectREFR* b = 0;
    Actor* a;
    if (apInteriorCell && !apInteriorCell->IsInterior())
        apInteriorCell = 0;
    if (apInteriorCell)
        apWorldSpace = 0;
    if (base && (apInteriorCell || apWorldSpace))
    {
        bool d = false;
        TESObjectCELL* c;
        if (apExistingRef)
        {
            d = ((RefOps*)apExistingRef)->TESObjectREFR_GetRefPersists_005653d0();
            ((RefOps*)apExistingRef)->TESObjectREFR_SetRefPersists(false);
            TESObjectCELL* parent = apExistingRef->GetParentCell();
            if (parent)
                parent->RemoveReference(apExistingRef);
            b = apExistingRef;
            if (!b->GetObjectReference())
                ((RefOps*)b)->TESObjectREFR_SetObjectReference(base);
            if (((RefOps*)b)->TESObjectREFR_MustRefPersist())
                d = true;
        }
        else
        {
            switch ((int)base->GetFormType())
            {
            case 42:
                b = new FUN_008d1d30;
                break;
            case 43:
                b = new CreatureRef;
                break;
            case 81:
                return TESDataHandler_CreateExplosionAtLocation(base, position, rotation, apInteriorCell, apWorldSpace);
                break;
            case 51:
                return CreateExplosion(base, position, rotation, apInteriorCell, apWorldSpace);
                break;
            default:
                b = new TESObjectREFR;
                break;
            }
            if (base == DAT_011ca23c && owner)
                ((RefOps*)b)->GetExtra()->ExtraDataList_SetPortalLinkedRoomRef(0, owner);
            ((RefOps*)b)->TESObjectREFR_SetObjectReference(base);
            if (editorID)
                ((RefOps*)b)->GetExtra()->AddExtra(new ExtraEditor(editorID));
            if (b->MustBeVisibleDistant())
                b->TESObjectREFR_SetVisibleDistant(true);
            d = ((RefOps*)b)->TESObjectREFR_MustRefPersist();
            TESObjectLIGH* light = dynamic_cast<TESObjectLIGH*>(base);
            if (light)
                ((RefOps*)b)->TESForm_SetFireOff(HasLightFlag20(light));
        }
        if (((RefVirtualView*)b)->IsActor())
        {
            ::Actor* actor = (::Actor*)b;
            if (actor->GetActorBase()->GetUsesLeveledTemplate())
                actor->GetActorBase()->SetTemplateReference(actor);
        }
        if (FUN_00469860(b->GetFormID()))
            ((RefVirtualView*)b)->FUN_48(0);
        if (BGSDestructibleObjectForm_IsDestructible(b->GetObjectReference()))
            ((RefOps*)b)->FUN_004846a0(true);
        ((RefOps*)b)->TESObjectREFR_SetLocationOnReference(position);
        ((RefOps*)b)->TESObjectREFR_SetAngleOnReference(*rotation);
        c = 0;
        if (apWorldSpace)
        {
            int b = _TruncateFloatToInt(position->x) >> 12;
            int a = _TruncateFloatToInt(position->y) >> 12;
            c = apWorldSpace->GetCellAtGridPosition(b, a);
        }
        else
            c = apInteriorCell;
        if (!c)
        {
            b->Set3D(0, false);
            ((RefOps*)b)->TESObjectREFR_SetRefPersists(true);
            ((WorldOps*)apWorldSpace)->FUN_00587ff0(b);
        }
        else
        {
            NiNode* node = 0;
            if (DAT_011dea10->FUN_004511e0(c, false))
            {
                if (base == DAT_011ca230 || base == DAT_011ca234 || base == DAT_011ca220 || base == DAT_011ca250 ||
                    base == DAT_011ca244 || base == DAT_011ca248 || base == DAT_011ca224 || base == DAT_011ca228 ||
                    base == DAT_011ca22c)
                {
                    node = new NiNode(0);
                    b->Set3D(node, true);
                }
                b->SetParentCell(c);
                void* container = ((RefOps*)b)->TESObjectREFR_HasContainer();
                if (container)
                {
                    InventoryView* changes = FUN_004bf220(b);
                    changes->InventoryChanges_InitLeveledItems();
                    changes->InventoryChanges_InitFromContainerExtra();
                    changes->InventoryChanges_InitScripts();
                    if (changes->InventoryChanges_IsEmpty())
                        ((RefOps*)b)->GetExtra()->FUN_0041aeb0();
                }
                b->SetParentCell(0);
            }
            ((RefOps*)b)->TESObjectREFR_SetDroppedRef(true);
            c->AddReference(b, false);
            ((RefOps*)b)->TESObjectREFR_SetRefPersists(d);
            node = ((RefVirtualView*)b)->Get3D();
            if (node)
            {
                node->NiAVObject_SetTranslate(reinterpret_cast<const ::NiPoint3*>(static_cast<const TESObjectREFR*>(b)->GetPos()));
                node->SetRotate_0043fa80(reinterpret_cast<const ::FloatMatrix3&>(((RefOps*)b)->TESObjectREFR_GetOrientation()));
                bhkNiCollisionObject_ResetSim(node, true);
                FUN_00450b80(0)->FUN_00b5eeb0(node);
                node->UpdateProperties();
                NiUpdateData updateData(0.0f, false, false);
                node->NiAVObject_Update(updateData);
            }
        }
    }
    a = dynamic_cast<Actor*>(b);
    if (a && !reinterpret_cast<bool (__thiscall*)(::Actor*)>((*reinterpret_cast<void***>(a))[0x290 / 4])(a))
        a->Unk_11B();
    if (a && !apExistingRef)
        a->FUN_0046a010(false);
    return b;
}

namespace fnv_0046a190 {
struct MatrixA
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_006815c0();
    void FUN_00a59780(float, float, float);
};
struct ExtraA
{
    void ExtraDataList_SetPersistentCell(TESObjectCELL*);
};
struct RefA
{
    void TESObjectREFR_SetRefPersists(bool);
    ExtraA* BSFile_GetDevice();
    TESWorldSpace* TESObjectREFR_GetWorldSpace();
};
struct WorldA
{
    TESObjectCELL* FUN_005f36f0();
};
extern RefA* DAT_011dea3c;
extern char DAT_01018c08;
void __cdecl Warning_005b5e40(const char*, ...);
RefA* __cdecl CreateProjectileRef(TESForm*, RefA*, int, TESObjectCELL*, NiPoint3, MatrixA);
struct SelfA
{
    RefA* TESDataHandler_CreateExplosionAtLocation(TESForm*, NiPoint3*, NiPoint3*, TESObjectCELL*, TESWorldSpace*);
};
// @fnv 0x0046a190
// src: XBOX_PDB 0x0046a190
RefA* SelfA::TESDataHandler_CreateExplosionAtLocation(TESForm* form, NiPoint3* pos, NiPoint3* angles, TESObjectCELL* suppliedCell,
                          TESWorldSpace* world)
{
    RefA* result = 0;
    if (form && form->GetFormType() == 0x51)
    {
        TESForm* cell = form;
        TESObjectCELL* placedObject = 0;
        if (world)
        {
            int cellY = _TruncateFloatToInt(pos->x) >> 12;
            int cellX = _TruncateFloatToInt(pos->y) >> 12;
            placedObject = world->GetCellAtGridPosition(cellY, cellX);
            if (!placedObject && world != DAT_011dea3c->TESObjectREFR_GetWorldSpace())
                Warning_005b5e40(&DAT_01018c08, cellY, cellX);
        }
        else
            placedObject = suppliedCell;
        MatrixA rotation;
        rotation.FUN_006815c0();
        rotation.FUN_00a59780(angles->z, angles->y, angles->x);
        RefA* parent = 0;
        switch (form->GetFormID())
        {
        case 0xcdef0:
        case 0x16af00:
        case 0x172fbd:
            parent = DAT_011dea3c;
            break;
        }
        result = CreateProjectileRef(cell, parent, 0, placedObject, *pos, rotation);
        if (!placedObject && world)
        {
            result->TESObjectREFR_SetRefPersists(true);
            result->BSFile_GetDevice()->ExtraDataList_SetPersistentCell(((WorldA*)world)->FUN_005f36f0());
        }
    }
    return result;
}
}  // namespace fnv_0046a190

class GlobalObject_0045cf30
{
  public:
    unsigned char* FUN_00408d60();
};
extern GlobalObject_0045cf30 g_011c3f98;
extern GlobalObject_0045cf30 g_011c3f80;
extern GlobalObject_0045cf30 g_011c4060;

struct FormMap_46ec10
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& key, unsigned int& pos, void*& val);
};
extern FormMap_46ec10* DAT_011c54c0;

int __cdecl Warning_005b5e40(const char* fmt, ...);
const char* __cdecl FormIDToString(int type);
int __cdecl FUN_00456a20(const char* path, char* a2, int a3, unsigned int a4);

struct BipedHelper_46ec10
{
    const char* FUN_00481230(int a);
};

extern const char str_01019974[];
extern const char str_01019944[];
extern const char str_0101996c[];
extern const char str_0101991c[];
extern const char str_0101990c[];
extern const char str_010198e0[];
extern const char str_010198b8[];


// Iterates the form map and reports TESIcon, TESTexture and TESBipedModelForm entries whose icon path is missing or fails to resolve.
// @fnv 0x0046ec10
void TESDataHandlerUnitOperations::ValidateFormIcons()
{
    if (*g_011c3f98.FUN_00408d60())
        return;
    if (DAT_011c54c0 == 0)
        return;
    TESForm* form = 0;
    void* key = DAT_011c54c0->FUN_004b9ba0();
    unsigned int pos = 0;
    while (key)
    {
        DAT_011c54c0->FUN_006b7f20(key, pos, (void*&)form);
        if (form)
        {
            TESIcon* tex = dynamic_cast<TESIcon*>(form);
            TESTexture* icon = dynamic_cast<TESTexture*>(form);
            TESBipedModelForm* biped = dynamic_cast<TESBipedModelForm*>(form);
            if (tex)
            {
                if (*g_011c3f80.FUN_00408d60())
                {
                    if (form->GetFormType() != 0x1e || ((TESObjectLIGH*)form)->GetCanCarry())
                    {
                        if (tex->GetTextureNameLength() == 0)
                        {
                            Warning_005b5e40(str_01019974, FormIDToString(form->GetFormType()), form->GetName());
                        }
                        else
                        {
                            char buf1[0x104];
                            sprintf_s(buf1, 0x104, str_0101996c, tex->GetTextureResourcePath(), reinterpret_cast<TESFullName*>(tex)->GetFullName());
                            if (FUN_00456a20(buf1, 0, 0, -1) == 0)
                                Warning_005b5e40(str_01019944, reinterpret_cast<TESFullName*>(tex)->GetFullName(), FormIDToString(form->GetFormType()),
                                             form->GetName());
                        }
                    }
                }
            }
            else if (icon)
            {
                if (*g_011c4060.FUN_00408d60())
                {
                    if (icon->GetTextureNameLength() == 0)
                    {
                        unsigned char flag = 1;
                        switch (form->GetFormType())
                        {
                        case 0x41:
                            flag = 0;
                            break;
                        case 7:
                            flag = 0;
                            break;
                        }
                        if (flag)
                            Warning_005b5e40(str_0101991c, FormIDToString(form->GetFormType()), form->GetName());
                    }
                    else
                    {
                        char buf2[0x104];
                        switch (form->GetFormType())
                        {
                        case 0x12:
                            sprintf_s(buf2, 0x104, str_0101990c, icon->GetTextureResourcePath(), reinterpret_cast<TESFullName*>(icon)->GetFullName());
                            break;
                        default:
                            sprintf_s(buf2, 0x104, str_0101996c, icon->GetTextureResourcePath(), reinterpret_cast<TESFullName*>(icon)->GetFullName());
                            break;
                        }
                        if (FUN_00456a20(buf2, 0, 0, -1) == 0)
                            Warning_005b5e40(str_010198e0, reinterpret_cast<TESFullName*>(icon)->GetFullName(), FormIDToString(form->GetFormType()),
                                         form->GetName());
                    }
                }
            }
            else if (biped)
            {
                if (*g_011c3f80.FUN_00408d60())
                {
                    const char* iconPath = ((BipedHelper_46ec10*)biped)->FUN_00481230(0);
                    if (BSStringLength(iconPath) == 0)
                    {
                        Warning_005b5e40(str_01019974, FormIDToString(form->GetFormType()), form->GetName());
                    }
                    else
                    {
                        char buf3[0x104];
                        sprintf_s(buf3, 0x104, str_0101996c, GetMaleBipedIconPath(biped),
                                  iconPath);
                        if (FUN_00456a20(buf3, 0, 0, -1) == 0)
                            Warning_005b5e40(str_010198b8, iconPath, FormIDToString(form->GetFormType()),
                                         form->GetName());
                    }
                }
            }
        }
    }
}

struct ChangeEntry;
struct ChangeExtra;
struct ChangeNode
{
    ChangeEntry*& FUN_006815c0();
    ChangeNode* FUN_00726070();
};
struct ExtraNode
{
    ChangeExtra*& FUN_006815c0();
    ExtraNode* FUN_00726070();
    void RemoveMatchingItem(ChangeExtra* const&);
    bool FUN_008256d0();
};
struct ChangeEntry
{
    TESForm* FUN_0044ddc0();
    ExtraNode* Modelloader_GetReferencedThis();
    int FUN_00726070();
    void FUN_006ecd40(int);
    bool ItemChange_GetWorn(bool);
};
struct ChangeExtra
{
    TESObjectREFR* ExtraDataList_GetOriginalReference();
    short ExtraDataList_GetCount();
};
struct ChangeList : ChangeNode
{
    void RemoveMatchingItem(ChangeEntry* const&);
};
struct FUN_004befb0
{
    ChangeList* entries;
    TESObjectREFR* owner;
    float totalWeight;
    float cachedWeight;
    bool changed;
    FUN_004befb0(TESObjectREFR*);
    void InventoryChanges_RunScripts(TESObjectREFR*);
    void InventoryChanges_CreateCopyofList(FUN_004befb0*, TESObjectREFR*, bool);
};
struct ExtraInventoryView
{
    FUN_004befb0* FUN_00418520();
    TESObjectREFR* FUN_00421400();
};
struct ParentInventoryView
{
    void FillBarterContainer(TESObjectREFR*, FUN_004befb0*);
};
struct WeaponInventoryView
{
    TESForm* TESObjectWEAP_GetCurrentAmmo(TESObjectREFR*);
};
struct InventoryHandler : TESDataHandler
{
    void FUN_0046faf0();
    void UpdateInventoryForReference(TESObjectREFR* reference);
};
// @fnv 0x0046f310
void InventoryHandler::UpdateInventoryForReference(TESObjectREFR* reference)
{
    if (!reinterpret_cast<FUN_004befb0*&>(pBarterContainer))
        reinterpret_cast<FUN_004befb0*&>(pBarterContainer) = new FUN_004befb0(0);
    else
        FUN_0046faf0();
    FUN_004befb0* pOtherInventory = ((ExtraInventoryView*)reference->GetExtraData())->FUN_00418520();
    if (pOtherInventory)
        pOtherInventory->InventoryChanges_CreateCopyofList(reinterpret_cast<FUN_004befb0*&>(pBarterContainer), reference, false);
    TESObjectREFR* changes = ((ExtraInventoryView*)reference->GetExtraData())->FUN_00421400();
    if (changes)
    {
        pOtherInventory = ((ExtraInventoryView*)changes->GetExtraData())->FUN_00418520();
        if (pOtherInventory)
            pOtherInventory->InventoryChanges_RunScripts(changes);
        else
            pOtherInventory = new FUN_004befb0(changes);
        pOtherInventory->InventoryChanges_CreateCopyofList(reinterpret_cast<FUN_004befb0*&>(pBarterContainer), changes, false);
    }
    TESObjectCELL* cell = reference->GetParentCell();
    if (!cell)
        return;
    ((ParentInventoryView*)cell)->FillBarterContainer(reference, reinterpret_cast<FUN_004befb0*&>(pBarterContainer));
    if (((::Actor*)reference)->IsActor())
    {
        TESObjectREFR* entry = reference;
        ChangeEntry* actor = 0;
        ChangeNode* node = reinterpret_cast<FUN_004befb0*&>(pBarterContainer)->entries;
        while (node && node->FUN_006815c0())
        {
            actor = node->FUN_006815c0();
            TESForm* object = actor->FUN_0044ddc0();
            if (object->GetFormType() == 0x29 && ((::Actor*)entry)->Actor_GetCurrentWeapon() &&
                ((WeaponInventoryView*)((::Actor*)entry)->Actor_GetCurrentWeapon())->TESObjectWEAP_GetCurrentAmmo(entry) == object)
            {
                ExtraNode* count = actor->Modelloader_GetReferencedThis();
                int iExtraCount = 0;
                while (count && count->FUN_006815c0())
                {
                    ChangeExtra* extra = count->FUN_006815c0();
                    if (extra->ExtraDataList_GetOriginalReference() && extra->ExtraDataList_GetOriginalReference() == entry)
                    {
                        iExtraCount = extra->ExtraDataList_GetCount();
                        actor->Modelloader_GetReferencedThis()->RemoveMatchingItem(extra);
                        break;
                    }
                    count = count->FUN_00726070();
                }
                actor->FUN_006ecd40(actor->FUN_00726070() - iExtraCount);
                if (actor->FUN_00726070() <= 0 || !actor->Modelloader_GetReferencedThis() || actor->Modelloader_GetReferencedThis()->FUN_008256d0() ||
                    actor->ItemChange_GetWorn(false))
                    reinterpret_cast<FUN_004befb0*&>(pBarterContainer)->entries->RemoveMatchingItem(actor);
                break;
            }
            node = node->FUN_00726070();
        }
    }
}

// If FUN_00425fd0 is false and m_4c differs from value, deletes the old m_4c and stores value.
// @fnv 0x005470a0
void TESObjectCELL::SetLandscape(TESObjectLAND* apObj)
{
    if (IsInterior())
        return;
    if ((*reinterpret_cast<TESObjectLAND**>(formData + 0x28)) != apObj)
    {
        if ((*reinterpret_cast<TESObjectLAND**>(formData + 0x28)))
            delete (*reinterpret_cast<TESObjectLAND**>(formData + 0x28));
        (*reinterpret_cast<TESObjectLAND**>(formData + 0x28)) = apObj;
    }
}

namespace fnv_0046ddb0 {
struct BipedView : TESBipedModelForm
{
    TESModel* World(int);
    TESModel* Biped(int);
};
struct ObjectView
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual const char* Editor();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual bool Skip();
    bool Special();
};
struct NodeView
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* GetNode();
};
struct RefView
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual ~RefView();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void Load(int);
    virtual void slot1cc();
    virtual NodeView* Get3D();
    void SetBase(TESBoundObject*);
};
struct NPCRef : RefView
{
    NPCRef();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
};
struct CreatureRef : RefView
{
    CreatureRef();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
};
struct PlainRef : RefView
{
    PlainRef();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
};
struct TestSetting
{
    bool* Bool();
};
extern TestSetting g_011c408c, g_011c3fa8, g_011c4080, g_011c3fd4, g_011c4054;
struct TestAudio
{
    void Begin();
    void Flush();
};
extern TestAudio* g_osGlobals;
struct TestLoader
{
    void Queue(RefView*, int, int);
};
extern TestLoader* g_modelLoader;
struct TestIO
{
    void Finish();
};
extern TestIO* DAT_01202d98;
struct WorldView : TES
{
    int Count(void*, int);
    void Purge(int);
};
extern unsigned char modelTypes[];
extern const char* modelNames[];
int _sprintf_s(char*, unsigned int, const char*, ...);
int strcpy_s(char*, unsigned int, const char*);
extern "C" int sprintf(char*, const char*, ...);
void LogFile(const char*, const char*, ...);
void DebugLog(const char*, ...);
void FNV_Warning(const char*, ...);
int FileExists(const char*, char*, unsigned int, unsigned int);
void SplitPath(const char*, char*, int, char*, int, char*, int, char*, int);
void BuildPath(char*, unsigned int, const char*, const char*, const char*, const char*);
TESForm* FindTemplate(TESBoundObject*, unsigned short*);
int WarningCount();
void CountGeometry(NodeView*, int*, int*);
struct ModelTest : TESDataHandler
{
    void SetTesting(int);
    void RecordPath(const char*);
    void CheckNode(NodeView*, const char*);
    void TESDataHandler_CheckModels(bool);
};
// Iterates all TESObject forms, checks each model file exists or loads it, logs geometry stats and warnings, then resets testing.
// @fnv 0x0046ddb0
// src: COMMUNITY 0x0046ddb0
void ModelTest::TESDataHandler_CheckModels(bool force)
{
    if (*g_011c408c.Bool())
        return;
    SetTesting(1);
    if (*g_011c3fa8.Bool())
        g_osGlobals->Begin();
    if (*g_011c4080.Bool())
        LogFile(
            "TestModels - Collision Info.xls",
            "Model\tModel Bound\tDisplay Triangle Count\tConvex Vertices Count\tConvex Vertices / Size Ratio\tConvex Vertices / Display Geometry Ratio\tTriangle Collection Count\tTriangle Collection / Size Ratio\tTriangle Collection / Display Geometry Ratio");
    TESObject* object = reinterpret_cast<TESFormList*>(pObjectList)->GetFirst();
    int count = 0;
    while (object)
    {
        if (!object->IsDeleted())
        {
            unsigned char iType = object->GetFormType();
            int index;
            for (index = 0; index < 87; index++)
            {
                if (modelTypes[index] == iType)
                    break;
            }
            if (index < 87)
            {
                bool skip = false;
                if (((ObjectView*)object)->Skip())
                    skip = true;
                TESModel* model = dynamic_cast<TESModel*>(object);
                TESBoundObject* bound = dynamic_cast<TESBoundObject*>(object);
                TESBipedModelForm* bipedForm = dynamic_cast<TESBipedModelForm*>(object);
                int pass = model ? 1 : bipedForm ? 4 : 0;
                while (pass)
                {
                    const char* label = "";
                    if (bipedForm)
                    {
                        switch (pass)
                        {
                        case 1:
                            model = ((BipedView*)bipedForm)->World(0);
                            label = "Male World ";
                            break;
                        case 2:
                            model = ((BipedView*)bipedForm)->World(1);
                            label = "Female World ";
                            break;
                        case 3:
                            model = ((BipedView*)bipedForm)->Biped(0);
                            label = "Male Biped ";
                            break;
                        case 4:
                            model = ((BipedView*)bipedForm)->Biped(1);
                            label = "Female Biped ";
                            break;
                        }
                    }
                    if (!skip)
                    {
                        if (model->GetModelLength())
                        {
                            char path[260];
                            if (index == 10)
                                _sprintf_s(path, 260, "Trees\\%s", model->GetModelFilePath());
                            else
                                _sprintf_s(path, 260, "Meshes\\%s", model->GetModelFilePath());
                            if (!FileExists(path, 0, 0, -1))
                            {
                                if (*g_011c3fd4.Bool())
                                {
                                    char extn[256];
                                    char szDir[260];
                                    char fn[512];
                                    char drive[3];
                                    SplitPath(model->GetModelFilePath(), drive, 3, szDir, 260, fn, 512, extn, 256);
                                    _sprintf_s(path, 260, "x%s", fn);
                                    strcpy_s(fn, 512, path);
                                    _sprintf_s(path, 260, "Meshes\\%s", szDir);
                                    strcpy_s(szDir, 260, path);
                                    BuildPath(path, 260, drive, szDir, fn, extn);
                                    if (!FileExists(path, 0, 0, -1))
                                        FNV_Warning("MODELS: %sModel \"%s\" not found for %s \"%s\".", label,
                                                    model->GetModelFilePath(), modelNames[index],
                                                    object->GetName());
                                    else
                                        RecordPath(path);
                                }
                            }
                            else if (bound && (*g_011c3fa8.Bool() || force || *g_011c4080.Bool()))
                            {
                                char message[260];
                                sprintf(message, "Loading %smodel \"%s\" for %s \"%s\".", label,
                                        model->GetModelFilePath(), modelNames[index], bound->GetName());
                                DebugLog(message);
                                g_osGlobals->Flush();
                                RefView* ref;
                                if (bound->GetFormType() == 42)
                                    ref = new NPCRef;
                                else if (bound->GetFormType() == 43)
                                    ref = new CreatureRef;
                                else
                                    ref = new PlainRef;
                                ref->SetBase(bound);
                                switch (bound->GetFormType())
                                {
                                case 42: {
                                }
                                case 43:
                                    if (*g_011c4080.Bool() && !*g_011c3fa8.Bool() && !force)
                                        break;
                                    {
                                        unsigned short flags = 0;
                                        if (FindTemplate(bound, &flags) && (flags & 6))
                                            break;
                                        g_modelLoader->Queue(ref, 0, 0);
                                        DAT_01202d98->Finish();
                                    }
                                default: {
                                    int warnings = WarningCount();
                                    ref->Load(0);
                                    if (warnings != WarningCount())
                                    {
                                        FNV_Warning("Warnings were encountered loading %smodel '%s' for %s %s.", label,
                                                    model->GetModelFilePath(), modelNames[index], bound->GetName());
                                        FNV_Warning("");
                                    }
                                }
                                }
                                if (ref->Get3D())
                                    CheckNode(ref->Get3D(), model->GetModelFilePath());
                                if (*g_011c4080.Bool() && bound->GetFormType() != 42 && bound->GetFormType() != 43)
                                {
                                    int nConvex = 0;
                                    int triangles = 0;
                                    CountGeometry(ref->Get3D(), &nConvex, &triangles);
                                    float size = bound->GetBoundSize();
                                    int nGeom = 0;
                                    if (g_TES)
                                    {
                                        NodeView* node = ref->Get3D();
                                        nGeom = ((WorldView*)g_TES)->Count(node ? node->GetNode() : 0, 1);
                                    }
                                    LogFile("TestModels - Collision Info.xls",
                                            "%s\t%.2f\t%i\t%i\t%.2f\t%.2f\t%i\t%.2f\t%.2f", model->GetModelFilePath(),
                                            size, nGeom, nConvex, nConvex / size, (double)nConvex / nGeom, triangles,
                                            triangles / size, (double)triangles / nGeom);
                                }
                                delete ref;
                                if (count++ > 20)
                                {
                                    ((WorldView*)g_TES)->Purge(0);
                                    count = 0;
                                }
                            }
                        }
                        else if (index != 12 && index != 6 && *g_011c4054.Bool())
                        {
                            switch (index)
                            {
                            case 0:
                            case 6:
                            case 12:
                                break;
                            case 11:
                                if (((ObjectView*)object)->Special())
                                    break;
                            default:
                                FNV_Warning("MODELS: No model selected for %smodel %s \"%s\".", label,
                                            modelNames[index], object->GetName());
                                break;
                            }
                        }
                    }
                    pass--;
                }
            }
            else
                FNV_Warning("MODELS: Object \"%s\" invalid type.", object->GetName());
        }
        object = object->GetNext();
    }
    SetTesting(0);
}
}  // namespace fnv_0046ddb0

struct FNVObject
{
    virtual ~FNVObject();
    short ExtraDataList_GetCount();
    void* ExtraDataList_GetOriginalReference();
    void ExtraDataList_RemoveOriginalReferenceExtra();
    int TESObjectREFR_HasContainer();
    unsigned int BaseExtraList_ItemsInList();
    int BaseExtraList_GetExtraData(int mode);
    int ExtraDataList_GetScript();
    struct FNVCursor* BSFile_GetDevice();
};

struct FNVRecordManager;
struct FNVCursor
{
    FNVRecordManager* FUN_00418520();
    void ExtraDataList_RemoveOwnership();
    void ExtraDataList_RemoveOriginalReferenceExtra();
};

struct FNVListNode
{
    FNVObject** FUN_006815c0();
    FNVListNode* FUN_00726070();
};

struct FNVRecordGroup
{
    FNVRecordManager* owner;
    FNVListNode* Modelloader_GetReferencedThis();
    FNVRecordGroup* FUN_0044ddc0(int, int);
    FNVRecordGroup* FUN_0044ddc0(FNVObject*, int, int, int, void*, int, int, int, int);
};

struct FNVFile
{
    FNVRecordGroup* FUN_0044ddc0(int selected, int all);
    FNVRecordGroup* FUN_0044ddc0(FNVObject*, int, int, int, void*, int, int, int, int);
};

struct FNVRecordManager
{
    void RemoveMatchingItem(FNVObject**);
    FNVRecordGroup* FUN_004bfba0(FNVRecordGroup*);
};

extern void* _DAT_011dea3c;


// Iterates FNV inventory records from a file group, dispatches each to a virtual handler, and removes or updates entries based on reference counts and uniqueness.
// @fnv 0x0046f640
void TESDataHandlerUnitOperations::ProcessInventoryRecords(FNVFile* file, int remaining, int source)
{
    FNVObject* current = 0;
    bool retrying;
    FNVRecordGroup* group = (*reinterpret_cast<FNVRecordManager**>(reinterpret_cast<unsigned char*>(this) + 0x628))
                                ->FUN_004bfba0(file->FUN_0044ddc0(1, 0));
    if (!group)
        return;

    FNVListNode* node = group->Modelloader_GetReferencedThis();
    if (node)
        current = *node->FUN_006815c0();

    retrying = false;
    while (remaining)
    {
        bool unique;
        void* processed = 0;
        int count = 1;
        if (!node && retrying)
            return;

        if (node)
        {
            current = *node->FUN_006815c0();
            node = node->FUN_00726070();
            if (current)
            {
                count = current->ExtraDataList_GetCount();
                if (count > 0)
                {
                    processed = current->ExtraDataList_GetOriginalReference();
                    if (remaining >= count)
                        current->ExtraDataList_RemoveOriginalReferenceExtra();
                    if (remaining < count)
                        count = remaining;
                }
                else
                {
                    processed = 0;
                }
            }
            if (processed)
            {
                if (reinterpret_cast<FNVObject*>(processed)->TESObjectREFR_HasContainer())
                {
                    FNVObject* input = 0;
                    if (current->BaseExtraList_ItemsInList())
                    {
                        if (current->BaseExtraList_ItemsInList() != 1 || !current->BaseExtraList_GetExtraData(0x24))
                            input = current;
                    }
                    typedef void(__thiscall * SendFunc)(void*, FNVRecordGroup*);
                    reinterpret_cast<SendFunc>((*reinterpret_cast<void***>(processed))[0x17c / 4])(
                        processed, group->FUN_0044ddc0(input, count, 0, 0, _DAT_011dea3c, 0, 0, 1, 0));
                    FNVRecordManager* firstRef =
                        reinterpret_cast<FNVObject*>(processed)->BSFile_GetDevice()->FUN_00418520();
                    unique = true;
                    if (firstRef)
                    {
                        FNVRecordGroup* matching = firstRef->FUN_004bfba0(group->FUN_0044ddc0(1, 0));
                        if (matching && matching->Modelloader_GetReferencedThis())
                        {
                            FNVListNode* scan = matching->Modelloader_GetReferencedThis();
                            while (scan && *scan->FUN_006815c0() && unique)
                            {
                                if (*scan->FUN_006815c0() == current)
                                    unique = false;
                                else
                                    scan = scan->FUN_00726070();
                            }
                        }
                    }
                    firstRef = reinterpret_cast<FNVObject*>(_DAT_011dea3c)->BSFile_GetDevice()->FUN_00418520();
                    if (firstRef)
                    {
                        FNVRecordGroup* matching = firstRef->FUN_004bfba0(group->FUN_0044ddc0(1, 0));
                        if (matching && matching->Modelloader_GetReferencedThis())
                        {
                            FNVListNode* scan = matching->Modelloader_GetReferencedThis();
                            while (scan && *scan->FUN_006815c0() && unique)
                            {
                                if (*scan->FUN_006815c0() == current)
                                    unique = false;
                                else
                                    scan = scan->FUN_00726070();
                            }
                        }
                    }
                    if (unique && current && current->BaseExtraList_ItemsInList() < 2 && current->ExtraDataList_GetCount() <= 1 &&
                        !current->ExtraDataList_GetScript())
                    {
                        group->owner->RemoveMatchingItem(&current);
                        node = group->Modelloader_GetReferencedThis();
                        delete current;
                        current = 0;
                    }
                    if (current &&
                        ((current->ExtraDataList_GetCount() > 1 && current->BaseExtraList_ItemsInList() < 2) || current->BaseExtraList_ItemsInList() < 1))
                        current = 0;
                }
                else
                {
                    reinterpret_cast<FNVObject*>(processed)->BSFile_GetDevice()->ExtraDataList_RemoveOwnership();
                    reinterpret_cast<FNVObject*>(processed)->BSFile_GetDevice()->ExtraDataList_RemoveOriginalReferenceExtra();
                    typedef void(__thiscall * ProcessFunc)(void*, void*, int, int);
                    reinterpret_cast<ProcessFunc>((*reinterpret_cast<void***>(_DAT_011dea3c))[0x3d0 / 4])(
                        _DAT_011dea3c, processed, count, 0);
                    group->owner->RemoveMatchingItem(&current);
                    node = group->Modelloader_GetReferencedThis();
                    if (current->BaseExtraList_ItemsInList() < 2 && current->ExtraDataList_GetCount() <= 1 && !current->ExtraDataList_GetScript())
                    {
                        delete current;
                    }
                    current = 0;
                }
                remaining -= count;
                if (node)
                    current = *node->FUN_006815c0();
                else
                    current = 0;
            }
            else
            {
                if (!node)
                    remaining = 0;
                else
                    current = *node->FUN_006815c0();
            }
        }
        else
        {
            UpdateInventoryForReference(source);
            current = 0;
            processed = 0;
            retrying = true;
            group = (*reinterpret_cast<FNVRecordManager**>(reinterpret_cast<unsigned char*>(this) + 0x628))
                        ->FUN_004bfba0(file->FUN_0044ddc0(1, 0));
            if (!group)
                return;
            node = group->Modelloader_GetReferencedThis();
            if (node)
                current = *node->FUN_006815c0();
        }
    }
}

struct TopicLookup : public TESDataHandler
{
    TESTopic* __thiscall TESDataHandler_GetTopic(unsigned int id);
};

// @fnv 0x00461690
// src: XBOX_PDB 0x00461690
TESTopic* __thiscall TopicLookup::TESDataHandler_GetTopic(unsigned int id)
{
    return dynamic_cast<TESTopic*>(TESFormInitFlag::GetFormByID(id));
}

