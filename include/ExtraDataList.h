#pragma once

#include "BaseExtraList.h"

class Actor;
class BGSEncounterZone;
class BGSLoadFormBuffer;
class BSExtraData;
class ExtraContainerChanges;
class ExtraDismemberedLimbs;
class ExtraNavMeshPortal;
class ExtraRadioData;
class ExtraRefractionProperty;
class FleePackage;
class InventoryChanges;
class LockExtraData;
class NavMeshPortalData;
class NiAVObject;
class RegionPoint;
class Script;
class TrespassPackage;
class ScriptLocals;
class SeenData;
class BSSoundHandle;
class TESForm;
class TESModel;
class TESObjectCELL;
class TESObjectREFR;
class TESPackage;
class TextureReceiver;
class bhkWorld;

class BGSAcousticSpace;
class BGSMusicType;
class BGSPrimitive;
class BSMultiBoundNode;
class BSOcclusionShapeNode;
class BSPortalNode;
class BSRoomNode;
class ExtraFactionChanges;
class ExtraFollowerSwimBreadcrumbs;
class NiCanopyTexture;
class NiCell3DNode;
class NiPoint3;
class RagDollData;
class TESClimate;
class TESGlobal;
class TESImageSpace;
class TESTopicInfo;
class TESWaterForm;
class TESWorldSpace;
// Match the canonical class keys: VC9 encodes class/struct in pointer symbols.
struct CanopyShadowMaskData;
class CollisionData;
class ImpactSwap;
// Existing exports encode this pointer as PAV (class), e.g. 0x00569060.
class MapMarkerData;
class MediaLocation;
class PatrolRefData;
class PatrolReferenceData;
class Point3Offset;
// Existing exports encode this pointer as PAV (class), e.g. 0x00418460.
class TeleportableReference;
struct TwoIntegerValues;

class ExtraDataList : public BaseExtraList
{
public:
    ~ExtraDataList();

    ExtraDataList();
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
    bool HasExtraDataType0x2F();
    bool HasOnlyAllowedExtraData(int type);
    bool CheckExtraByType(int type);
    void RemoveExtraDataType0x15();
    LockExtraData* GetLock();
    TESForm* GetOwnerForm();
    bool IsEmpty();
    ExtraDismemberedLimbs* GetDismemberedLimbs();
    short GetCount();
    void CopyFrom(ExtraDataList* source);
    void SetCount(int count);
    void SetExtraHealth(float health);
    ScriptLocals* GetScriptLocalData();
    RegionPoint* GetStartingPositionData();
    TESObjectREFR* GetReplacementReference();
    void AddGuardingActor(Actor* actor);
    void AddOrCreateExtraItem(void* crime, float stamp);
    void InitLoadGame(BGSLoadFormBuffer* buffer, TESForm* form);
    // 0x0041cd70 / 0x0041cda0 / 0x0041cc90: the package of the ExtraTresPassPackage extra (type 0x1a, +0xc)
    TrespassPackage* GetTrespassPackage();
    void ClearTrespassPackage();
    void SetTrespassPackage(TrespassPackage* package);
    ExtraRefractionProperty* GetAlphaExtra();
    TESPackage* GetPackageOverride();
    Actor* GetTalkingActor();
    void SetPackageOverride(TESPackage*, int, Actor*, bool, bool, bool);
    void RemoveNonPersistentCellData();
    BGSEncounterZone* FindEncounterZone() const;
    TESForm* GetOwner();
    ExtraDataList const* GetExtra() const;
    bhkWorld* GetRoomId();
    bool CanReachPackageLocation(TESPackage* package);
    void AddFollowerActor(Actor* actor);
    ExtraRadioData* GetExtraRadioData();
    void SetSavedAnimation(char* animation);
    void SetSavedHavokData(char* data);
    unsigned char GetWeaponModIndex();
    void SetLeveledItemIndex(int index);
    void GetLeveledItemData(float& multiplier, int& count);
    void CallExtraDataListMethod35(TESObjectCELL* cell);
    void CallExtraDataListMethod36(TESObjectREFR* reference);
    float GetRadius();
    NavMeshPortalData* GetExtraNavMeshPortal();
    TESObjectREFR* GetTargetObjectReference();
    TextureReceiver* GetStartingAngle(void* data);
    void Set3DObject(NiAVObject* object);
    BSExtraData* GetExtraData(unsigned char type);

    unsigned int BaseExtraList_ItemsInList();
    void RemoveExtra24();

    void BaseExtraList_RemoveAll(bool flag);
    InventoryChanges* ExtraDataList_IsEnableStateInverse();
    bool ExtraDataList_HasOnlyOwnershipNonDefault();
    void* ExtraDataList_SetEnableStateInverse(unsigned char type);
    void TESObjectCELL_SetCollisionGeometryDisplay(bool flag);
    bool TESObjectCELL_ToggleCollisionGeometry();

    ExtraContainerChanges* FUN_00418520();
    SeenData* ExtraDataList_GetSeenData();
    short ExtraDataList_GetCount();
    void ExtraDataList_DuplicateExtraListForContainer(ExtraDataList* source);
    void ExtraDataList_SetCount(int count);
    void ExtraDataList_SetCount(unsigned short count);
    bool ExtraDataList_CompareListForContainer(ExtraDataList* other, bool first, bool second);
    bool ExtraDataList_CompareListForContainer(ExtraDataList* other, int first, int second);
    void ExtraDataList_SetScriptLocals(void* data);
    void ExtraDataList_SetScriptLocals(int data);
    void ExtraDataList_SetScriptLocals(ScriptLocals* locals);
    TESObjectREFR* ExtraDataList_GetReferencePointer();
    Script* ExtraDataList_GetScript();
    void ExtraDataList_SetScript(Script* script);
    ScriptLocals* ExtraDataList_GetScriptLocals();
    void ExtraDataList_GetCreatureAwakeSound(BSSoundHandle* handle);
    void ExtraDataList_SetCreatureAwakeSound(BSSoundHandle* handle);
    void ExtraDataList_SetReflectsRef(TESForm* form, bool flag);
    void ExtraDataList_SetRefractsRef(TESForm* form, bool flag);
    TESModel* ExtraDataList_GetModelSwap();
    float FUN_00422450();
    void FUN_0041f840();
    bool ExtraDataList_GetWorn(bool flag);
    void ExtraDataList_SetCanNotWear(bool flag);

    // 0x004103d0 calls each helper with its list this in ECX; addresses checked in the exe.
    // 0x00411f20
    bool AttachExtraData(BSExtraData* apExtra);
    // 0x0041b3d0
    void GetLocalData(unsigned int auiFlags);
    // 0x00419700
    void SetOwnership(TESForm* apOwner);
    // 0x004197d0
    void SetGlobalForm(TESGlobal* apGlobal);
    // 0x004198a0
    void SetRank(int aiRank);
    // 0x00419ad0
    void SetCount(short asCount);
    // 0x0042eb60
    void SetAmmoExtra(TESForm* apAmmo, int aiCount);
    // 0x0041aa20
    void SetEquippedState(bool abWorn, bool abLeft);
    // 0x0042dde0
    void SetHotKey(unsigned char acKey);
    // 0x0041ac30
    void SetSeedIndex(unsigned char acSeed);
    // 0x0041d280
    void SetLeveledItem(int aiLevelItem);
    // 0x0041d330
    void SetLevelItemExtraFlag(unsigned char acFlag);
    // 0x00419970
    void SetHealth(float afHealth);
    // 0x0041b580
    void SetHealthPerc(float afHealthPerc);
    // 0x00419a20
    void SetUses(unsigned char acUses);
    // 0x00419bb0
    void SetTimeLeft(float afTimeLeft);
    // 0x00419c60
    void SetCharge(float afCharge);
    // 0x00419ed0
    void SetScript(Script* apScript);
    // 0x00419f80
    void AssignScriptLocals(ScriptLocals* apLocals);
    // 0x00419fb0
    void SetScale(float afScale);
    // 0x00419050
    void SetLockData(LockExtraData* apLock);
    // 0x00418310
    void SetRadioData(int* apRadioData);
    // 0x00419120
    void SetTeleportData(TeleportableReference* apData);
    // 0x00419250
    void SetMapMarkerPtr(MapMarkerData* apData);
    // 0x00419380
    void SetAudioMarkerPtr(MediaLocation* apData);
    // 0x004194b0
    void SetAudioBuoyMarkerPtr(TwoIntegerValues* apData);
    // 0x0041ad00
    void RelocateTo(TESWorldSpace* apWorld, TESObjectCELL* apCell, NiPoint3* apPos, float afAngle);
    // 0x0041d5b0
    void SetRagDollDataFromCopy(RagDollData* apData);
    // 0x0041d950
    void SetWeaponModFlags(int* apData);
    // 0x00422480
    void SetCombatOpponent(Actor* apFollower);
    // 0x00419dc0
    void SetHeadTrackTargetExtra(TESObjectREFR* apTarget);
    // 0x00419d10
    void SetPoison(TESForm* apPoison);
    // 0x0041b7e0
    void SetCell3D(NiCell3DNode* apNode);
    // 0x0041e160
    void SetWaterType(TESWaterForm* apWater);
    // 0x0041bd10
    void SetMusicType(BGSMusicType* apMusic);
    // 0x0041c090
    void SetAcousticSpace(BGSAcousticSpace* apSpace);
    // 0x0041c490
    void SetCanopyShadowMaskData(int aiMask, NiCanopyTexture* apTexture, CanopyShadowMaskData** appData);
    // 0x0041c190
    void SetClimate(TESClimate* apClimate);
    // 0x0041c290
    void SetImageSpace(TESImageSpace* apImageSpace);
    // 0x0041c390
    void SetImpactSwapData(ImpactSwap* apSwap);
    // 0x0041c7f0
    void SetActivateRef(TESObjectREFR* apRef);
    // 0x0041c930
    void SetPackageOverride(TESPackage* apPackage, int aiFlags, int aiTime, unsigned char acA, unsigned char acB,
                            unsigned char acC);
    // 0x0041cc90
    void SetActivePackage(TESPackage* apPackage);
    // 0x0041d700
    void SetPackageDoneState(TESPackage* apPackage, unsigned char acDone);
    // 0x00418550
    void SetEnableStateChildren(TESObjectREFR* apRef);
    // 0x0041da40
    void SetEnableStateParentRef(TESObjectREFR* apParent);
    // 0x0041dc70
    void SetEnableStateParentFlags(unsigned char acFlags);
    // 0x0041e250
    void SetRandomTeleportMarker(TESObjectREFR* apMarker);
    // 0x0041e440
    void SetLinkedRef(TESObjectREFR* apRef);
    // 0x00421430
    void SetMerchantContainer(TESObjectREFR* apContainer);
    // 0x00421b70
    void SetXTarget(TESObjectREFR* apTarget);
    // 0x00421c60
    void SetEncounterZone(BGSEncounterZone* apZone);
    // 0x00421d50
    void SetEmittanceSource(TESForm* apSource);
    // 0x00421e40
    void SetMultiBoundRef(TESObjectREFR* apRef);
    // 0x00421f30
    void SetExtraRecord(Point3Offset* apData);
    // 0x00421540
    void SetLevCreaModifier(int aiModifier);
    // 0x00422750
    void SetRefractionAmount(bool abSet, float afRefraction);
    // 0x0041ab70
    void SetCannotWear(bool abCanNotWear);
    // 0x00422220
    void SetRadius(float afRadius);
    // 0x00422350
    void SetRadiation(float afRadiation);
    // 0x0042e760
    void UpdateExtraDataListExtension();
    // 0x0042e800
    ExtraFactionChanges* GetFactionChangesExtra();
    // 0x0042e2c0
    void SetPortalRefData(BSExtraData* apPortal);
    // 0x0041fa60
    void AddPrimitive(BGSPrimitive* apPrimitive);
    // 0x00422050
    void SetMultiBound(BSMultiBoundNode* apMultiBound);
    // 0x00420f00
    void SetRoomNode(BSRoomNode* apRoom);
    // 0x0041fc10
    void SetPatrolRefData(PatrolRefData* apData);
    // 0x00422150
    void SetOcclusionShape(BSOcclusionShapeNode* apShape);
    // 0x0041fec0
    void SetRoomRefData(PatrolReferenceData* apData);
    // 0x00420a60
    void SetRoomLinkedRoomRef(int aiIndex, TESObjectREFR* apRoom);
    // 0x00420c10
    void AddRoomLinkedRoomRef(TESObjectREFR* apRoom);
    // 0x00420870
    void SetRoomIsMaster(bool abMaster);
    // 0x00420fd0
    void SetCollisionData(CollisionData* apData);
    // 0x0042ef20
    void SetExtraSayTopicInfoOnceADayExtra(TESTopicInfo* apInfo);
    // 0x00420e00
    void SetPortalNode(BSPortalNode* apPortal);
    // 0x0042f200
    void SetIgnoredBySandbox(bool abIgnored);
    // 0x0042f420
    ExtraFollowerSwimBreadcrumbs* GetFollowerSwimBreadcrumbsExtra();
    // 0x0042e380
    void RemoveExtraByType(unsigned char acSlot);
    // 0x004103d0
    void AddExtraCopy(BSExtraData* apExtra);
};
