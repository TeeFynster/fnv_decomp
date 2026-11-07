#include "../../include/Interface.h"
#include "../../include/SettingT.h"
#include "../../include/TESSaveLoadGame.h"
#include "../../include/SETTING_VALUE.h"
// fallout_shared/bipedanim_decls.h: declares NiPoint3, CloningProcess, NiFixedString, NiMemObject, NiObject and more
#include "../../include/Actor.h"
#include "../../include/ActorTaskManager.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSQuestObjective.h"
#include "../../include/BSFaceGenModel.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShaderManager.h"
#include "../../include/BSShaderPPLightingProperty.h"
#include "../../include/BaseProcess.h"
#include "../../include/ExtraDataList.h"
#include "../../include/ExtraDismemberedLimbs.h"
#include "../../include/InventoryChanges.h"
#include "../../include/InventoryStackRecord.h"
#include "../../include/LowProcess.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiNode.h"
#include "../../include/NiObject.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiSkinData.h"
#include "../../include/NiSkinInstance.h"
#include "../../include/NiSkinPartition.h"
#include "../../include/NiSourceTexture.h"
#include "../../include/NiStringExtraData.h"
#include "../../include/NiTexture.h"
#include "../../include/NiTimeController.h"
#include "../../include/NiTriBasedGeom.h"
#include "../../include/NiUpdateData.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/ShadowSceneNode.h"
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
// The two texture setters ApplySkinTextures (0x004af490) calls through BSShaderPPLightingProperty's vtable, slots 63
// and 64 (+0xfc/+0x100). include/BSShaderProperty.h declares no virtuals past NiShadeProperty's 37 yet (the class
// has no RTTI to check against), so this view reaches them by slot until the shared chain spells them out.
struct PPLightingTextureSlots
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void SetTexture(int slot, NiTexture* texture);        // slot 63
    virtual void SetNormalTexture(int slot, NiTexture* texture);  // slot 64
};

// The bone-list extra data that BipedAnim attaches to bone nodes: an NiExtraData-derived block whose node list
// (TileWorkList, FUN_004700d0 appends) sits at +0x34; its real class is not identified yet.
struct BoneListExtraView
{
    unsigned char prefix[0x34];
    TileWorkList children;
};
#include "../../include/bhkCollisionObject.h"
#include "../../include/bhkFilter.h"
#include "../../include/bhkShape.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/NiTNewInterface.h"
#include "../../include/NiTArray.h"
#ifndef BIPEDANIM_DECLS_H
#define BIPEDANIM_DECLS_H

class NiUpdateData;
class BSShaderPPLightingProperty;
class NiTexture;
class NiSourceTexture;
class QueuedFile;
class QueuedHelmet;
class TESBipedModelForm;
class NiNode;
class NiAVObject;
class BSFadeNode;
class NiTriBasedGeom;
class NiProperty;
class NiExtraData;
class NiSkinData;
class NiSkinPartition;
class NiGeometryData;
class NiSkinInstance;
class TESObjectREFR;
class TESObjectWEAP;
class BSFaceGenModel;
class BipedAnim;
class TESModel;
class TESModelTextureSwap;
class TESBoundObject;
class TESRace;
class TESNPC;
class ExtraDataList;
class ExtraDismemberedLimbs;
class Animation;
class InventoryStackRecord;
class BaseProcess;
class BGSBipedModelList;
#include "../../include/NiMatrix3.h"
#include "../../include/BIPED_BONE.h"
#include "../../include/BIPED_OBJECT.h"
#include "../../include/SEX.h"
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/IO_TASK_PRIORITY.h"
class CloningProcess
{
  public:
    void* cloneMap;
    void* processMap;
    int copyType;
    char appendChar;
    NiPoint3 scale;
    CloningProcess(float);
    ~CloningProcess();
};
namespace oldstd {
template <class T> struct vector
{
    unsigned int unk00;
    void* unk04;
    unsigned int unk08;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
};
}
#include "../../include/NiMemObject.h"
class NiTimeController;
class InventoryChanges;
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

class INISettingCollection;


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
extern TES* g_TES;
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern bool DAT_011c5cb4;
extern SettingT<INISettingCollection> DAT_011c5ef0;
extern int DAT_01188be8[20];
extern const char* DAT_01188b98[20];
extern NiMatrix3 DAT_011a9448;
bool BSFaceGenManager_GetUseFaceGenHeads();
void BSFaceGenManager_ClearBodyTexturesFromPalette(TESBoundObject*);
bool IsObjectProcessable(NiObject*);
bool UpdateObjectVisibility(NiAVObject*);
int __cdecl Warning(const char*, ...);
void AddNodeEntries(int, NiAVObject*);
class DialogMenuInterfaceCalls
{
  public:
    static void SetHUDVisible(bool);
};

extern "C" void* __cdecl memset(void*, int, unsigned int);

const NiFixedString& FixedStrings_QDVPG();
NiAVObject* BSUtilities_GetObjectByName_004ade00(NiNode*, const NiFixedString&);
void BSstrncpy(char*, const char*, unsigned int);
int BSstricmp(const char*, const char*);
extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
template <class T> unsigned int BSStringLength(const T*);

class SceneObjectLookup
{
  public:
    static NiAVObject* GetObjectByName(NiAVObject*, const char*);
};
ShadowSceneNode* FUN_00450b80(int);
// ShadowSceneNode::RemoveObject (0x00b5b1c0) as AttachFaceGenNode (0x00571b50) calls it: the argument is pushed before
// FUN_00450b80 runs, the order VC9 /Od gives a non-polymorphic receiver (the shared, polymorphic ShadowSceneNode
// evaluates the receiver first).
struct SceneObjectRemover
{
    void RemoveObject(NiAVObject* object);
};
void FalloutAudio_LockAcousticSpace(bool);
int BSstrcmp(const char*, const char*);
class VATS
{
  public:
    void QuitVATSPlayback(bool abForceQuit, bool abFinishCommandPlayback);
};
extern VATS DAT_011f2250;
extern TESDataHandler* g_dataHandler;
class BGSListForm;

class SkyShaderProperty;
extern NiRTTI DAT_011f4a38, DAT_011f9140, DAT_011f444c;
SkyShaderProperty* NiObject_DynamicCast(const NiRTTI*, NiProperty*);
const NiFixedString& FixedStrings_QPrn();
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;
bool HandleUnparentedObjectNode(NiNode*);
void SetCollisionRefFlag(NiNode*, bool);
void bhkWorld_KillHavok(NiNode*, bool, bool);
void bhkWorld_SetMotion(NiNode*, int, bool, bool, bool);
const char* ConvertFromUni(const char*, bool);
extern const char* DAT_01199e8c[2];
void FUN_00b4f5e0(char*, const char*, const char*, bool);
void FUN_00b55840(const char*, bool, NiPointer<NiTexture>&, bool, bool);
NiTexture* BSFaceGenUtils_GetDefaultDetailModulationTexture();
extern int DAT_01188b88[3];
extern const char* DAT_01188c38[5];
extern TESModel DAT_011c5d10[20];
extern SettingT<INISettingCollection> DAT_011d5a10, DAT_011d5a44;
bool Animation_FindSkinnedNode(NiNode*);
unsigned int NiMaterialProperty_GetType();
int NiTexturingProperty_GetType();
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
char* strrchr_0040ab30(char*, int);
int strcat_s(char*, unsigned int, const char*);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_MISSING = 0
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
extern ActorTaskManager DAT_011c5cf0;
const NiFixedString& BSXFlags_Tag();
void TESObjectREFR_AddAddonNodes(NiNode*);
struct BipedSkinNameMatch
{
    const char* name;
    BIPED_OBJECT slot;
};
struct BipedRenderProperties
{
    NiProperty* material;
    NiProperty* alpha;
    BSShaderPPLightingProperty* shader;
};
struct BipedAttachmentTarget
{
    NiExtraData* metadata;
    NiNode* parent;
};
class TESTopic;
extern "C" const char kMeshesFolder[];
class Animation
{
  public:
    static bool RemoveKeyframeControllers(NiAVObject*);
};
struct BipedWeaponEntry
{
    float value;
    TESObjectWEAP* weapon;
    InventoryStackRecord* entry;
};
struct BipedModelClone
{
    NiNode* model;
    NiObject* copy;
    NiNode* pNode;
};
struct BipedSkinAttachment
{
    NiNode* attachNode;
    BSFaceGenModel* face;
};
struct BipedSkinBoneMetadata
{
    NiExtraData* extra;
    NiExtraData* bones;
};
struct BipedSkinnedChild
{
    NiTriBasedGeom* geom;
    NiAVObject* child;
    NiSkinInstance* skin;
};
struct BipedSkinBoneBinding
{
    NiAVObject** boneArray;
    unsigned int count;
    NiAVObject* pBone;
};
#endif

struct BipedWeaponOwner
{
    BipedAnim* biped;
    Actor* actor;
    BaseProcess* process;
};
struct BipedEquippedWeapon
{
    TESObjectWEAP* weapon;
    InventoryChanges* changes;
};
struct BipedWeaponSearch
{
    NiNode* search;
    NiNode* found;
    NiNode* root;
};

struct BipedGeometryChild
{
    NiTriBasedGeom* geometry;
    NiAVObject* child;
};

class TESQuest;
class TESHairRaceResult;
class BGSPerkEntry;
class TESHairCanBeNPCData
{
  public:
    TESHairRaceResult* TESNPC_GetRace();
};

// These object and string getters are identical folded functions in the PC executable.
#define BIPED_OBJECT_NAME(object) (*(const NiFixedString*)((TESTopicInfoData*)(object))->GetLinkToList())
#define BIPED_STRING_TEXT(value) ((const char*)((BSFadeNode*)&(value))->FUN_0043b1b0())
#define BIPED_OBJECT_TEXT(object) BIPED_STRING_TEXT(BIPED_OBJECT_NAME(object))
#define BIPED_EXTRA_STRING(extra) (*(const NiFixedString*)((TESSpellList*)(extra))->GetOffsetC())

struct BipedSkinTextureTarget
{
    TESNPC* npc;
    BIPED_OBJECT slot;
};

class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d5a10, g_011d5a44;
class GlobalObject_0044fae0
{
};
extern GlobalObject_0044fae0 g_011c5cf0;
// The canonical initializer name denotes the same 16-byte child array.
class GlobalObject_004aff00
{
  public:
    void* vtable;
    NiPointer<NiAVObject>* data;
    unsigned short capacity, size, count, grow;
    GlobalObject_004aff00(int, int);
    ~GlobalObject_004aff00();
};

typedef NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > > BipedChildArray;

// Canonical RTTI alias bound to the NPC descriptor used by this cast.
