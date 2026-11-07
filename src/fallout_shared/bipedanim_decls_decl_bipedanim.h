#include "../../include/SettingT.h"
// Private declarations for bipedanim_decl_variant.cpp.
#pragma once

#include "../../include/Actor.h"
#include "../../include/ActorTaskManager.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSQuestObjective.h"
#include "../../include/BSShaderManager.h"
#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/BaseProcess.h"
#include "../../include/ExtraDataList.h"
#include "../../include/ExtraDismemberedLimbs.h"
#include "../../include/LowProcess.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiNode.h"
#include "../../include/NiObject.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiSkinData.h"
#include "../../include/NiSkinInstance.h"
#include "../../include/NiSkinPartition.h"
#include "../../include/NiStringExtraData.h"
#include "../../include/NiTimeController.h"
#include "../../include/NiTriBasedGeom.h"
#include "../../include/NiUpdateData.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/SettingT.h"
#include "../../include/TES.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFaction.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESNPC.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESRace.h"
#include "../../include/TESSpellList.h"
#include "../../include/TESTopicInfoData.h"
#include "../../include/TileWorkList.h"
#include "../../include/bhkCollisionObject.h"
#include "../../include/bhkFilter.h"
#include "../../include/bhkShape.h"
#include "../../include/bhkWorldObject.h"

class QueuedFile;
class QueuedHelmet;
class BSFaceGenModel;
class INISettingCollection;
#include "../../include/BIPED_BONE.h"
#include "../../include/BIPED_OBJECT.h"
#include "../../include/SEX.h"
#include "../../include/IO_TASK_PRIORITY.h"

class ModelLoader
{
  public:
    void CallContainedObject();
    void ModelLoader_UnlockModelMap();
    void QueueModelFilePath(const char*, IO_TASK_PRIORITY, QueuedFile*);
    void ProcessModelRequest(TESModel*, IO_TASK_PRIORITY, QueuedFile*, int, bool, bool, bool);
    void QueueFile(const char*, IO_TASK_PRIORITY, QueuedFile*, int, bool, bool, bool);
    void ModelLoader_ReleaseFile(const char*);
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
};

class BipedAnimBone
{
  public:
    unsigned char cFlags;
    NiNode* pParent;
};

class BipedAnimObject
{
  public:
    TESForm* pParent;
    TESModel* m_pModel;
    NiAVObject* m_pSceneObject;
    bool bHasAnimation;
};

class BipedAnim
{
  public:
    void QueueBipedParts(IO_TASK_PRIORITY priority, NiPointer<QueuedHelmet>& queuedHelmet,
                      QueuedFile* file);  // declared for the original code (decl_variants.py) public:
    NiNode* root;
    BipedAnimBone bone[5];
    BipedAnimObject object[20];
    BipedAnimObject m_kPreviousObjects[20];
    float m_fFadeAlpha;
    TESObjectREFR* m_pActor;
    void ProcessQueuedHelmet(IO_TASK_PRIORITY, NiPointer<QueuedHelmet>&, QueuedFile*);
    void QueueBipedObjectLoads(unsigned int, IO_TASK_PRIORITY, QueuedFile*);
    void LoadBipedObject(TESNPC*, BIPED_OBJECT, IO_TASK_PRIORITY, QueuedFile*);
    void RequestModelLoad(IO_TASK_PRIORITY, QueuedFile*, NiPointer<QueuedHelmet>&, BIPED_OBJECT);
    void CompleteModelLoadTask();
    NiNode* GetBoneNode(BIPED_BONE);
    void AttachFaceGenNode();
    void RemoveBipedWeapon();
    void SetBipedVisibility(bool);
    NiAVObject* PrepareBipedModel(NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*);
    NiAVObject* AttachBipedModel(NiNode*, NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*);
    static void AttachFaceGenNode(NiNode*, NiNode*, NiNode*, BipedAnim*, BIPED_OBJECT, BSFaceGenModel*);
    void UpdateSkinInstance(NiAVObject*, bool);
    bool IsSlotHidden(BIPED_OBJECT);
    BSFaceGenModel* GetFaceGenModelForSlot(BIPED_OBJECT);
    void UpdateBipedWeapon(TESObjectWEAP*, unsigned char);
    void ClearBipedObject(BipedAnimObject*, bool, TESForm*);
    void QueueItem(IO_TASK_PRIORITY, void*, BIPED_OBJECT);
    static bool CanLoadHiddenBipedObjects();
    static void ApplyReferenceExtraData(NiNode*, NiNode*, BIPED_OBJECT, TESObjectREFR*);
    static BSShaderPPLightingProperty* FindLightingShaderProperty(NiAVObject*);
    static BIPED_OBJECT GetBipedObjectFromShaderProperty(NiAVObject*, BSShaderPPLightingProperty*);
    bool IsModelPathMatch(TESModel*, char*);
    TESModel* GetModelForSlot(BIPED_OBJECT, TESModel*);
    TESModel* BipedAnim_Store1stPersonModel(BIPED_OBJECT, char*);
    void RemovePart(BIPED_OBJECT, bool, TESForm*);
    void RemovePartsByParent(TESForm*);
    void SetBipedObject(TESForm*, TESModel*, BIPED_OBJECT);
    void UpdateRaceSex(TESRace*, SEX);
};

extern PlayerCharacter* g_thePlayer;
extern ModelLoader* g_modelLoader;
extern SettingT<INISettingCollection> DAT_011c5ef0;
bool BSFaceGenManager_GetUseFaceGenHeads();
