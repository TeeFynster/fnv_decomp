#include "../../include/TESForm.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/NavMeshInfoMap.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}

// ProcessTarget_tes_ob1_variant: local type (was include/ProcessTarget.h, which had no evidence of one real class); its methods are 0x008d0430 BaseProcess::GetCurrentPackageInstanceData, 0x0091ab30 MiddleHighProcess::GetTargetForPackage, 0x0091ae00 MiddleHighProcess::SetTargetData, 0x009611e0 NiAVObject::GetParent
class Actor;
class PackageRuntime;
class PackageTargetData;
class TargetOwner;
class TESPackage;

class TESPackage;

class ProcessTarget_tes_ob1_variant
{
public:
    TESObjectREFR* MiddleHighProcess_SetTargetData(Actor*, TESPackage*, PackageTargetData*);
    PackageRuntime* FUN_008d0430();
    TESObjectREFR* MiddleHighProcess_GetTargetForPackage(Actor*, TESPackage*);
    TargetOwner* GetOwner();
};
#include "../../include/AutoMemContext.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/GO.h"
#include "../../include/GridCellArray.h"
#include "../../include/NP.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiUpdateData.h"
#include "../../include/PlaceableWaterData.h"
#include "../../include/Setting.h"
#include "../../include/TESModel.h"
#include "../../include/TESObjectLAND.h"
#include "../../include/BGSAddonNode.h"
#include "../../include/TESBoundObject.h"
#include "../../include/BGSPlaceableWater.h"
#include "../../include/NiPoint3.h"
#include "../../include/TES.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/NiObject.h"
#include "../../include/TESDataHandler.h"
#include "../../include/BSTempNodeManager.h"
#include "../../include/BSTempNode.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiAdditionalGeometryData.h"
#include "../../include/NiCamera.h"
#include "../../include/NiNode.h"
#include "../../include/QueuedFile.h"
#include "../../include/Sky.h"
#include "../../include/TESObjectTREE.h"
#include "../../include/TESWaterForm.h"
#include "../../include/TESSaveLoadGame.h"

// src/fallout_shared/tes_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/tes.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct GlobalObject_00a7b610
{
};
extern GlobalObject_00a7b610 g_01202df8;
struct FUN_00450620_shell
{
    const NiRTTI* GetNiRTTI() const;
};
extern "C" void __cdecl FUN_00c44e20(BSTempNodeManager*);
extern void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct FUN_004512a0_shell
{
    unsigned char m_ucState;
    void SetState(unsigned char ucState);
};
extern char DAT_01189184;
void GridCellArray_SetRecreateCanopyShadowMaskTexture(unsigned char value);
extern NP DAT_011f95e8;
void BSShaderManager_SetProjectedShadowMaskTexture(void* arg);
extern unsigned char DAT_011ad86c;
void TallGrassShaderProperty_SetUseBackgroundLoading(unsigned char value);
struct AlchemyItem;
struct BGSAddonNode;
struct BGSDebris;
struct BGSExplosion;
struct BGSMessage;
struct BGSPerk;
struct BGSPrimitive;
struct BGSProjectile;
struct BGSVoiceType;
struct FormRecordHeader;
struct InventoryChanges;
struct InventoryStackRecord;
struct NiTriBasedGeom;
struct Script;
struct TESAmmoEffect;
struct TESBoundObject;
struct TESCaravanDeck;
struct TESCasino;
struct TESChallenge;
struct TESClass;
struct TESCombatStyle;
struct TESEffectShader;
struct TESFaction;
struct TESFile;
struct TESGlobal;
struct TESIdleForm;
struct TESLandTexture;
struct TESLoadScreenType;
struct TESObject;
struct TESObjectANIO;
struct TESObjectCELL;
struct TESFormList;
struct TESQuest;
struct TESRace;
struct TESRecipe;
struct TESRecipeCategory;
struct TESRegionDataManager;
struct TESRegionList;
struct TESReputation;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
typedef char _sizecheck_TESDataHandler[sizeof(TESDataHandler) == 1596 ? 1 : -1];
struct FUN_004516b0_shell : public TESDataHandler
{
    bool FUN_004516b0();
};
struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESObjectCELL;
struct blob4
{
    char b[4];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct FUN_004523c0_shell : public BGSSaveLoadGame
{
    bool TESObjectCELL_GetAttaching();
};
int __fastcall GetByteAtOffset38(void*);
struct FUN_00452420_shell
{
    unsigned int pad0;   // +0x00
    unsigned int pad1;   // +0x04
    unsigned int pad2;   // +0x08
    unsigned int pad3;   // +0x0C
    unsigned int flags;  // +0x10
    bool GetFlag(unsigned int aiFlags) const;
};
struct FUN_00452440_shell
{
    bool __thiscall BGSPlaceableWater_IsAutomaticWater();
};
struct FUN_004e32c0_shell
{
    bool __thiscall HasFlags(int arg);
};
extern unsigned char DAT_0119b8c8;
unsigned char BSTreeManager_GetUseCanopyShadows();
int __fastcall NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(void*);
struct FUN_00453470_shell
{
    int __thiscall NiNode_GetChildCount(void);
};
struct FUN_004534f0_shell
{
    void __thiscall FUN_004534f0(unsigned int);
};
struct FUN_00453500_shell
{
    void BGSSaveLoadGame_SetDeferInitForms(bool set);
};
struct BSAudio;
BSAudio* DAT_011f6d98;
BSAudio* BSAudio_QInstance();
extern unsigned char DAT_011f9427;
void BSShaderManager_SetInterior(unsigned char value);
struct FNStub
{
    char const* GetFullName() const;
};
char const* FNStub::GetFullName() const
{
    return 0;
}
struct FUN_00454b50_shell
{
    char const* TESWorldSpace_GetWaterNoiseTextureName() const;
};
struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList(void);
    bool TESQuest_GetEnabled(void);
};
extern int DAT_011c56e8;
void ClearAnimationCloneCount();
struct FUN_004565f0_shell
{
    float m_f;
    float GetFloat();
};
extern const void* const g_01202e00;
struct FUN_00458f20_shell
{
    const void* const* BSTempNode_GetRTTI() const;
};
extern "C" void __fastcall UpdateFields_00c5faa0(void*);
extern int DAT_01017d24;
struct FUN_00458f70_shell
{
    void __thiscall SetVtableAndProcessState_00458f70();
};
struct AnimIdle;
struct Animation;
struct AttachDistant3DTask;
struct BSFile;
struct BSFileEntry;
struct BackgroundCloneThread;
struct BipedAnim;
struct EffectSetting;
struct KFModel;
struct LoadedFile;
struct MagicItem;
struct Model;
struct NiControllerSequence;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESBoundObject;
struct TESModel;
struct TESNPC;
struct TESObjectCELL;
struct FileEntryList;
struct FileEntryListCollection;
struct ModelLoadData;
struct ModelLoader
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void QueueModelLoad(char*, bool, unsigned int);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    NiNode* LoadFile(char*, int, bool, bool, bool, bool);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};
typedef char _sizecheck_ModelLoader[sizeof(ModelLoader) == 48 ? 1 : -1];
struct FUN_0045a5e0_shell : public ModelLoader
{
    void ModelLoader_ReleaseFile(char*);
};
void __cdecl CreateCSDFadeNode(void);
void __cdecl CreateSpdFadeNode(void);
void __cdecl BGSAddonNodeSoundHandleExtra_InitTag(void);
void __cdecl BSFaceGenAnimationData_InitTag(void);
void __cdecl BSFaceGenModelExtraData_InitTag(void);
void __cdecl BSFaceGenBaseMorphExtraData_InitTag(void);
void __cdecl TES_InitSDM(void);
struct FUN_0045c650_shell
{
    void* hkpMotion_getLinearVelocity();
};
struct Flt
{
    operator unsigned int(void) const;
};
extern Flt g_011deb7c;
unsigned int Main_GetWorldSceneGraph();
void TESObjectREFR_AddMasterParticleAddonNodes(TESObjectREFR* self);
void TESObjectREFR_RemoveMasterParticleAddonNodes(TESObjectREFR* self);
void TES_RangedNodeVisibilityChangedCB(TESObjectREFR* arg, bool flag);
extern "C" double _gModifierZero;
struct FUN_00451cd0_shell
{
    unsigned char TESClimate_GetVolatilityIndex();
};
struct TESObjectCELL_AddToInteriorBuffer
{
    void AddCellToInteriorBuffer(TESObjectCELL* cell);
};
struct TESObjectCELL_AddToExteriorBuffer
{
    void AddCellToExteriorBuffer(TESObjectCELL* cell);
};
struct FUN_00454b90_shell
{
    void AddCellToBuffer(TESObjectCELL* cell);
};
struct FUN_00458f30_shell
{
    void SetVtableAndProcessState_00458f70();
    void* DestroyIfFlagged(unsigned int flags);
};
void _delete(void* obj, unsigned int size);
struct FUN_00459840_shell
{
    void TES_ClearDeadCountList();
    void TES_Revert(unsigned int a);
};
struct FUN_0045a730_shell
{
    char* TESDataHandler_GetWaterForms();
};
extern "C" void __cdecl _Deallocate(void*);
struct FUN_0045ae20_shell
{
    void FUN_0045ae50();
    void* FUN_0045ae20(unsigned int flags);
};
struct FUN_00451250_shell
{
    unsigned char bFlags;
    void SetFlag2(bool value);
};
struct FUN_00401280_shell
{
    void retn_empty_string();
};
struct FUN_00451cb0_shell
{
    void TESObjectCELL_GetCellName();
};
struct RefH
{
    bool IsDeleted() const;
    bool GetDisabled();
};
struct FNVHelper
{
    FNVHelper* _FNV_GetObjectReference();
    unsigned char _FNV_GetFormType();
};
extern int DAT_01000000;
struct FUN_00452370_shell
{
    bool TESForm_GetDestructible() const;
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 DAT_011c3c90;
struct FUN_00453980_shell
{
    int GetGlobalInt();
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct FUN_00454400_shell
{
    int GetRaceListSize();
};
void __cdecl ClearAnimationCloneCount(void);
struct FUN_004baba0_shell
{
    void RunAnimations_004baba0();
};
struct FUN_00553820_shell
{
    void TESObjectCELL_RunAnimations();
};
struct CP_008c48d0
{
    void* GetPrevPath();
};
struct FUN_00455640_shell
{
    void* m0;
    void* m4;
    void* m8;
    void TES_RunAnimations();
};
struct TESObjectCELLHelper
{
    NiAVObject* GetCellChildAt(int);
};
struct FUN_0045c9a0_shell : public TESObjectCELL
{
    NiAVObject* GetCellNodeAt(unsigned int index);
};
struct FUN_00557090_shell
{
    void TESObjectCELL_IsRefListLocked();
};
struct FUN_005570b0_shell
{
    void __thiscall IsSet();
};
struct FUN_00452390_shell
{
    char _pad[0xaa];
    unsigned short _0xaa;
    void TESObjectCELL_IncLoadedRefsWithVisibleDistantCount();
};
struct Holder4523e0
{
    char _pad[0x64];
    FUN_00452420_shell* pLoaded;
    bool TESObjectREFR_GetLoadedDataFlag(unsigned int aiFlag);
};
struct FUN_0045aee0_shell
{
    char pad_0045aee0[0xb5];
    char m_0045aee0_b5;  // at offset 0xb5
    void SetByteB5(char v);
};
struct FUN_00454fc0_cls
{
    void CompactQueuedCells();
};
struct FUN_004ba5a0_cell_helper
{
    bool IsOutdoorCell();
};
struct FUN_00452e50_class
{
    void TES_SetUpdateGridString();
};
struct CellStand
{
    int GetCellStandValue();
};
struct DH
{
    void DeleteObject(TESObjectCELL*);
};
extern DH* g_dataHandler;
extern GlobalObject_0045cfe0 g_011c63cc;
struct FUN_00454e70_shell
{
    char _pad[0x3c];
    TESObjectCELL** m_ppCellBufferB;
    void MoveCellToFront(TESObjectCELL* apCell);
};
struct TESObjectLAND;
struct L_GetHitSound
{
    TESWorldSpace* GetHitSound();
};
struct W_00585b30
{
    TESObjectCELL* TESWorldSpace_LoadCell(int, int);
};
struct W_00588150
{
    void AddCellReferences(TESObjectCELL*);
};
struct FUN_00461c20_Holder
{
    TESObjectCELL* GetOrCreateCell(int, int, TESWorldSpace*, bool);
};
struct S00551440
{
    void TESObjectCELL_SetHasTempData(bool);
};
struct FUN_004ba5a0_shell
{
    bool IsOutdoorCell(unsigned int, unsigned int);
};
struct GridCellArray_Target
{
    void AttachToWorld(NiNode*, unsigned int, unsigned int);
};
struct S454b90
{
    void AddCellToBuffer(TESObjectCELL*);
};
struct C_0084e3a0
{
    unsigned int _ref_0084e3a0();
};
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct S451cb0
{
    const char* TESObjectCELL_GetCellName();
};
struct FakeCell
{
    TESObjectLAND* GetLandscape();
};
struct LAND_x
{
    bool TESObjectLAND_LoadVertices(bool);
    void TESObjectLAND_UpdateMesh(int, int);
    void TESObjectLAND_GetMinMaxLandHeight(NiPoint2*);
    void TESObjectLAND_DrawLandBorder(bool);
};
float __fastcall TESObjectCELL_GetWaterHeight(void*);
struct S451250
{
    void SetFlag2(bool);
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011c7adc;
struct S451cd0
{
    unsigned char TESClimate_GetVolatilityIndex();
};
void __cdecl BGSAutoWater_GeneratePlaceableWaterForCell(TESObjectCELL*);
int _sprintf(char*, const char*, ...);
struct TES_00451a50
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pGridCells;
    NiNode* m_pLandRootNode;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    bool m_bHasCurrentRegion;
    void TES_LoadGridCell(int aiGridX, int aiGridY, int aiCellX, int aiCellY);
};
struct Animation
{
    float FUN_00453700();
};
struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
};
struct FUN_0087aa90_shell
{
    void TaskQueueInterface_QueueParallelTaskProcessing();
};
struct DialogH
{
    static bool __cdecl IsInDialog();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct Zt5Cell
{
    void TESObjectCELL_UpdateManagedNodes(float, bool);
};
struct Zt5Grid
{
    void UpdateCellGrid(float);
};
struct Zt5Listener
{
    void ProcessRequests();
};
Zt5Listener* FOCollisionListener_GetSingleton();
void __cdecl BSWindModifier_SetWind(float, float);
void __cdecl bhkWindListener_SetWind(float, float);
void __fastcall ProcessLists_PostProcessProjectiles(char*);
extern float DAT_011c3c08;
extern GlobalObject_0045cfe0 g_011c3ea4;
extern Setting g_011c5724;
extern int DAT_011e0e80;
extern Twin_0084d030 g_timeGlobal;
struct Zt5TES
{
    void* pVtbl;
    void* m_pGridDistantArray;
    Zt5Grid* m_pGridCells;
    void* m_pLandRootNode;
    void* m_pWaterRootNode;
    void* m_pDistantLandRootNode;
    void* m_pObjectRootNode;
    void* m_pDirectionalLight;
    void* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    void* m_pReferenceCell;
    void* m_ppCellBufferA;
    void* m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    void* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    void* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    void* m_pCurrentClimate;
    Sky* pWeatherSky;
    void TES_LockHavokUpdateMT(bool);
    void TES_UpdateCellMainThread();
    void TES_UpdateCellAnimations(float afTime);
};
int TES_GetLODMult(TESForm* apObj);
struct FUN_00453490_shell
{
    bool ContainsCell(TESObjectCELL*);
    bool TES_IsExteriorBuffered(TESObjectCELL*);
    bool TES_IsBuffered(TESObjectCELL* cell);
};
struct FUN_00455400_cell : TESObjectCELL
{
    bool FUN_00454b10();
};
struct FUN_00455400_tes
{
    Sky* GetLogDate();
    void UpdateSkyModeForCell(TESObjectCELL* apCell);
};
struct FUN_0045ab30_shell : GO
{
    FUN_0045ab30_shell();
};
struct FUN_00b5ddb0_self
{
    void FUN_00b5ddb0(bool, bool);
};
struct CellExt
{
    bool IsOutdoorCell();
    void TESObjectCELL_AttachLights(bool);
};
struct FUN_00451cf0_shell
{
    char pad[8];
    GridCellArray* cells;
    void TES_UpdateGridLights();
};
struct LLD_Cell;
struct LLD_DataHandler
{
    LLD_Cell* GetOrCreateCell(int, int, TESWorldSpace*, bool);
};
struct FUN_00451900_shell
{
    TESObjectCELL* FUN_00451900(int aiCellX, int aiCellY);
};
void* __cdecl _FUN_00ec7230(void*, void*, unsigned int);
struct FUN_00454fc0_shell
{
    void* vftable;
    void* m_pGridDistantArray;
    unsigned char padding[0x1c];
    int iFirstValue;
    int unknown_28;
    int m_iGridWidth;
    int m_iGridHeight;
    int unknown_34;
    int unknown_38;
    TESObjectCELL** m_ppCellBufferB;

    void CompactQueuedCells();
};
struct Calendar : NiAVObject
{
    Calendar* GetDaysPassed();
};
Calendar* Calendar::GetDaysPassed()
{
    return this;
}
struct FUN_00458e20_shell : Calendar
{
    void FUN_00458e20(NiAVObject*, float);
};
void* __cdecl operator new(unsigned int);
struct G2
{
    int** _ref_006815c0();
    void* _ref_00726070();
    void AddHead(int*);
};
struct FUN_00459060_item
{
    unsigned int key;
    short value;
};
struct FUN_00459060_shell
{
    void AddOrAccumulateItem(unsigned int key, short value);
};
struct FUN_0045c780_sound
{
    unsigned int _ref_0084e3a0();
};
struct FUN_0045c780_shell
{
    unsigned char unknown_0045c780[8];
    FUN_0045c780_sound* sound;

    void InitSoundGrid();
    void TES_SetHideLandBlendPassForGridCell(unsigned int index1, unsigned int index2, unsigned char value);
};
extern bool DAT_011c3c0c;
extern const unsigned char DAT_01017830[5][5];
struct FUN_0045c840_shell
{
    void* field_00;
    void* field_04;
    void* field_08;

    void TES_SetSkipNormalMapsForGridCell(unsigned int index1, unsigned int index2, unsigned char value);
    void InitFromMatrix();
};
extern unsigned char DAT_0101784c[];
unsigned int __fastcall _ref_0084e3a0(void* object);
struct FUN_004572e0_shell : public TES
{
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    bool GetLandHeightAt(const NiPoint3& coord, float& height);
};
struct TESCallHelper
{
    bool IsCellBuffered(TESObjectCELL* cell, bool force);
};
int _TruncateFloatToInt(float value);
extern float DAT_01017824;
extern int g_TES;
bool TESCallHelper::IsCellBuffered(TESObjectCELL* cell, bool force)
{
    return false;
}
struct FUN_00451020_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    int m_28;
    void FUN_00451020(int* out, float f);
};
int __fastcall GetByteAtOffset38(void*);
struct FUN_004511e0_cls
{
    bool FUN_004511e0(void* pObj, unsigned char bFlag);
};
// Clear an actor's pending state: if it is flagged, has a current process target and is active,
// notify the target's owner, then reset two state flags.
class TargetOwner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void OnTargetCleared(ProcessTarget_tes_ob1_variant* pTarget);
};
class ActorStateHandler
{
  public:
    void TES_CleanTemp3D(TESObjectREFR* pActor);
};
extern "C" int __fastcall FUN_004503f0(void*);
extern "C" unsigned char __fastcall TESObjectCELL_GetAttached(void*);
struct TESBuffer45130 : Zt5TES
{
    void TES_MoveToEndOfExteriorBuffer(TESObjectCELL* apCell);
};
struct ExtCell : TESObjectCELL
{
    bool GetCellStandValue();
    TESWorldSpace* GetParentWorldSpace();
};
struct BufferSizeSetting
{
    unsigned int GetUInt();
};
struct ResettableState
{
    void Reset();
};
struct WorldSpaceView
{
    ResettableState* GetMapData();
};
struct TES_ExteriorBuffer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    ExtCell** m_ppCellBufferB;

    bool IsCellBuffered(ExtCell* apCell, bool abCheck);
    WorldSpaceView* GetParentWorldSpace();
    unsigned int TES_FreeExteriorBuffer(bool abSkipLoaded, TESWorldSpace* apWorld);
};
struct FUN_0043d4d0_cls
{
    unsigned int* Setting_Int();
};
extern FUN_0043d4d0_cls DAT_011c3e38;
extern DH* DAT_011c3f2c;
struct FUN_00455330_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int* m_38;

    void RemoveEntry(unsigned int value);
};
struct LookupEntry
{
    unsigned int FUN_00726070();
};
struct LookupResult
{
    LookupEntry* entry;
    LookupResult(int initialState);
    ~LookupResult();
    LookupEntry* Modelloader_GetReferencedThis();
};
void __cdecl FindTextureByPath(void* object, LookupResult* result);
void __cdecl BSTexturePalette_RemoveTexture(LookupEntry* entry);
struct LookupHandler
{
    bool TES_FreeTexture(void* object, unsigned int limit);
};
struct FUN_004570d0_node;
struct FUN_004570d0_mgr
{
    FUN_004570d0_node* FUN_005f36f0();
};
struct FUN_004570d0_lst
{
    unsigned int* Setting_Int();
};
struct FUN_004570d0_node
{
    bool TESObjectCELL_PickWater(void* a1, int a2, int a3, float f);
};
extern FUN_004570d0_mgr* DAT_011dea10;
extern FUN_004570d0_lst DAT_011c63cc;
struct FUN_004570d0_cls
{
    FUN_004570d0_node** GetGridCell_00457050(unsigned int i, unsigned int j);
    bool TES_PickWaterOnly(void* a1, int a2, int a3, float f);
};
struct FUN_00458f90_shell
{
    void TES_ClearDeadCountList();
};
struct G2List : G2
{
    void FUN_00470470();
};
struct SaveFormRecord
{
    unsigned int formId;
    unsigned char formType;
    unsigned char flags[4];
};
struct SaveState
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    unsigned char FUN_008df040();
    SaveFormRecord* FUN_004fd3e0();
};
extern SaveState* DAT_011de45c;
struct SaveLogSetting
{
    bool* FUN_00408d60();
};
extern SaveLogSetting DAT_011de4e8;
struct SaveForm
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual const char* GetDebugName();
};
SaveForm* LookupSaveForm(unsigned int);
void ProgramFlow(const char*, ...);
extern const char DAT_01017874[];
extern const char DAT_01012cb0[];
extern const char DAT_01012c78[];
struct SaveItemList
{
    unsigned int FUN_005ae380();
};
struct SaveSizeOwner
{
    SaveItemList* FUN_0050d100();
    unsigned short TES_GetSaveSize();
};
struct FUN_00459920_reference
{
    bool TESObjectCELL_GetAttached();
    void QueueReferences(int changeFlag);
};
struct FUN_00459920_grid
{
    FUN_00459920_reference** FUN_004ba490(unsigned int column, unsigned int row);
};
struct FUN_00459920_shell
{
    void* unk00;
    void* unk04;
    FUN_00459920_grid* referenceGrid;
    FUN_00459920_reference* FUN_005f36f0();
    void TES_QueueReferencesForAttachedCells();
};
unsigned int __fastcall DetailedActorPathHandler_GetCurrentNodeIndex(char* apName);
extern GlobalObject_0045cf30 g_011c7b98;
struct NiSourceTexture;
struct WaterFormNode
{
    bool IsEmpty();
    TESWaterForm** GetItem();
    WaterFormNode* GetNext();
};
struct WaterDataHandler
{
    WaterFormNode* GetTESWaterFormList();
};
struct WaterTES
{
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};
struct WaterTextureLoader
{
    void LoadWaterTextures();
};
struct ModelPtr
{
    NiObject* m_pObject;
    ModelPtr();
    ~ModelPtr();
    ModelPtr& operator=(NiObject* pObject);
    bool operator==(NiObject* pObject) const;
};
struct ModelCloneNode
{
    ModelPtr m_pRenderedNodeEntry;
    ModelPtr* pClones;
    ModelCloneNode* pNext;
    ModelCloneNode();
    ModelCloneNode* GetNext();
    void SetNext(ModelCloneNode* pNode);
};
struct ModelCloneOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    ModelCloneNode* pCloneList;
    void AddCloneEntry(NiObject* m_kModelObjectsItem);
};
struct ListNodeB;
struct SlotB;
struct ObjC;
struct ObjD;
struct ListNodeB
{
    bool Matches(void* key);
    ListNodeB* NextNode();
    unsigned int unk00;
    SlotB* m_slots;
};
struct SlotB
{
    unsigned int unk00;
    ObjD* Resolve();
};
struct ObjD
{
    int Check();
};
struct ObjC
{
    void Release(SlotB* slot);
    void Attach(SlotB* slot);
};
struct FUN_0045aba0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    ListNodeB* m_b0;
    int FindMatchingNode(void* a1, ObjC* a2);
};
struct NavMeshHolder
{
    virtual void unkV0();
    virtual void unkV1();
    virtual void unkV2();
    virtual void unkV3();
    virtual void* unkV4(unsigned int flags);
};
extern "C" void __cdecl Warning_005b5e40(const char*);
struct FUN_0045afb0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    NavMeshHolder* m_pNavMeshMaps;

    void SetNavMeshMaps(NavMeshHolder* arg);
};
struct S_0045c8d0_Obj;
struct S_0045c8d0_Tgt
{
    void BSShaderProperty_SetFlag(unsigned int a, unsigned char b);
};
struct S_0045c8d0_Obj
{
    S_0045c8d0_Tgt* FUN_00a59d30(int a);
};
struct S_0045c8d0_Virt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual S_0045c8d0_Obj* v6();
};
struct S_0045c8d0_Child
{
    int NiNode_GetAtChecked(int a);
    S_0045c8d0_Virt* FUN_0043b4a0(int a);
};
struct S_0045c8d0_Cell
{
    S_0045c8d0_Child* GetCellNodeAt(int a);
};
struct S_0045c8d0_R
{
    S_0045c8d0_Cell* unk0;
};
struct S_0045c8d0_A
{
    S_0045c8d0_R* FUN_004ba490(unsigned int a, unsigned int b);
};
int NiShadeProperty_GetType();
struct S_0045c8d0
{
    int unk0;
    int unk4;
    S_0045c8d0_A* unk8;
    void TES_SetHideLandBlendPassForGridCell(unsigned int a, unsigned int b, unsigned char c);
};
struct FUN_0045cb90_inner
{
    unsigned int m_00;
    unsigned int m_04;
};
struct FUN_0045cb90_cls
{
    char unk00[0x28];
    FUN_0045cb90_inner* m_28;

    bool TESObjectLAND_HasVertices();
};
class B45CDA0Cell
{
  public:
    void ActivateAllSubmergedReferencesIslands();
};
struct B45CDA0GridCell
{
    B45CDA0Cell* m_pkCell;
};
class B45CDA0GridCellArray
{
  public:
    B45CDA0GridCell* Get(unsigned int uiX, unsigned int uiY);
};
class B45CDA0TES
{
  public:
    int unk00;
    int unk04;
    B45CDA0GridCellArray* m_pkGridCells;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    B45CDA0Cell* m_pkInteriorCell;

    void TES_ActivateAllSubmergedReferencesIslands();
};
struct Grid4512
{
    virtual void v0();
    virtual void v1();
    virtual void Reset();
    virtual void v3();
    virtual void SetGridPosition(int x, int y);
};
struct Terrain4512
{
    void UnloadAll_006fce00();
    void Update_006fca90(void* position);
};
struct World4512
{
    Terrain4512* FUN_00586170();
};
struct Player4512
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* GetPosition(int which);
};
extern Player4512* g_thePlayer;
struct FUN_00c3dfa0_Class
{
    void LoadQueuedPriority(int);
};
extern FUN_00c3dfa0_Class* DAT_01202d98;
extern NiPoint3 DAT_011a9478;
void TESTerrainLODManager_UpdateGrass(NiPoint3 position, NiPoint3 direction, float scale);
extern Setting originalRuntimeFloatSetting16;
// Exe 0x00452ff0: unit-local Interface view; declarations and layout are preserved.
struct TesInterfaceView
{
    void FUN_00700960(int, float, bool);
};
extern TesInterfaceView* DAT_011d8804;
struct Process4512
{
    void ProcessLists_PlaceActorsinBedsOrChairs();
    void FUN_00972bb0();
};
struct Node4512
{
    void NiAVObject_Update(NiUpdateData&);
};
extern bool DAT_011c3ed0;
struct TES4512
{
    int unk00;
    int unk04;
    Grid4512* grid;
    int unk0c;
    Node4512* root;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int gridX;
    int gridY;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    World4512* world;
    TESObjectCELL* FUN_005f36f0();
    void TES_FreeExteriorBuffer(bool, TESWorldSpace*);
    void FUN_00452490(bool);
    void TES_InitModelsToLoad(bool);
    void RefreshGrid();
    bool GetLandHeightAt(const NiPoint3&, float&);
    bool TES_CellTestRunning();
    void ProcessItemNodes();
    void TES_RunScripts();
    void TES_ReloadGridCells(const NiPoint3* position, bool reload);
};
struct FUN_004516d0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    GridCellArray* cells;
    TESObjectCELL** TES_FindFirstGridCellWithWater();
};
extern const double DAT_010179e0;
struct TreeDimensions
{
    float x;
    float y;
};
struct AttachNode;
struct AttachRoot
{
    void FUN_00b5eeb0(AttachNode*);
    void FUN_00b5cbd0(AttachNode*);
    void FUN_00b5d9f0(AttachNode*, int);
};
AttachRoot* __cdecl FUN_00450b80(int);
struct AttachNode
{
    struct NodeOwner* NiAVObject_GetParent();
};
struct NodeOwner
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Release(AttachNode*);
};
struct AttachRef
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual bool IsActor();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual void Reserved111();
    virtual void Reserved112();
    virtual void Reserved113();
    virtual AttachNode* GetNode(int);
    virtual void Reserved115();
    virtual void Reserved116();
    virtual void Reserved117();
    virtual void Reserved118();
    virtual void Reserved119();
    virtual void Reserved120();
    virtual void Reserved121();
    virtual void Reserved122();
    virtual void Reserved123();
    virtual void Reserved124();
    virtual NiPoint3* GetPoint(unsigned int);
    virtual void Reserved126();
    virtual void Reserved127();
    virtual void Reserved128();
    virtual void Reserved129();
    virtual void Reserved130();
    virtual void Reserved131();
    virtual void Reserved132();
    virtual void Reserved133();
    virtual void Reserved134();
    virtual void Reserved135();
    virtual bool IsSpecialA();
    virtual bool IsSpecialB();
    virtual void Reserved138();
    virtual void Reserved139();
    virtual void Reserved140();
    virtual void Reserved141();
    virtual void Reserved142();
    virtual void Reserved143();
    virtual void Reserved144();
    virtual void Reserved145();
    virtual void Reserved146();
    virtual void Reserved147();
    virtual void Reserved148();
    virtual void Reserved149();
    virtual void Reserved150();
    virtual void Reserved151();
    virtual void Reserved152();
    virtual void Reserved153();
    virtual void Reserved154();
    virtual void Reserved155();
    virtual void Reserved156();
    virtual void Reserved157();
    virtual void Reserved158();
    virtual void Reserved159();
    virtual void Reserved160();
    virtual void Reserved161();
    virtual void Reserved162();
    virtual void Reserved163();
    virtual void Reserved164();
    virtual void Reserved165();
    virtual void Reserved166();
    virtual void Reserved167();
    virtual void Reserved168();
    virtual void Reserved169();
    virtual void Reserved170();
    virtual void Reserved171();
    virtual void Reserved172();
    virtual void Reserved173();
    virtual void Reserved174();
    virtual void Reserved175();
    virtual void Reserved176();
    virtual void Reserved177();
    virtual void Reserved178();
    virtual void Reserved179();
    virtual void Reserved180();
    virtual void Reserved181();
    virtual void Reserved182();
    virtual void Reserved183();
    virtual void Reserved184();
    virtual void Reserved185();
    virtual void Reserved186();
    virtual void Reserved187();
    virtual void Reserved188();
    virtual void Reserved189();
    virtual void Reserved190();
    virtual void Reserved191();
    virtual void Reserved192();
    virtual void HandleA();
    virtual void HandleB();
    AttachNode* VATS_GetVATSLight();
    TESBoundObject* BGSSaveFormBuffer_GetForm();
    void* TESObjectREFR_Get3D();
    void TESObjectREFR_Set3DSimple(AttachNode*);
    bool TESObjectREFR_GetVisibleDistant();
    void TESObjectREFR_UpdateReference3D();
    bool TESForm_GetDestructible();
    bool TESObjectREFR_QUnderwater();
    bool TESObjectREFR_GetLoadedDataFlag(int);
    void FUN_00483710();
    void* FUN_00430830();
    void TESObjectREFR_InitScript();
    void* BSFile_GetDevice();
    double TESObjectREFR_GetScale_00567400();
    void FUN_008c4640();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct AttachCell
{
    void GetOrCreateWidget();
    void TESObjectCELL_IncLoadedRefsWithVisibleDistantCount();
    void TESObjectCELL_AttachReference3D(AttachRef*, int);
    bool TESObjectCELL_GetAttached();
    bool TESObjectCELL_GetAttaching();
    void TESObjectCELL_PlaceCanopyShadow(NiPoint3);
};
struct AttachContext
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
};
extern AttachContext* DAT_011ddf38;
extern AttachRef* DAT_011dea3c;
void __cdecl Script_InitActionList(AttachRef*, void*);
void __cdecl Script_SetActionFlag(AttachRef*, void*, unsigned int);
void __cdecl FUN_004b6dc0(void*, unsigned int);
struct AttachmentHandler
{
    void TES_CleanTemp3D(AttachRef*);
    bool IsRefUsable(AttachRef*);
    void FUN_00451ea0(AttachRef*);
    void TES_AttachModel(AttachRef*, AttachCell*, AttachRef*, bool);
};
namespace GridRefresh {
struct Profile
{
    int unk00;
    Profile(int, int, const char*, int);
    ~Profile();
};
extern const char DAT_01017874[];
extern Setting DAT_011c63cc;
struct Update
{
    float time;
    int flags, unk08;
    Update(float, int, int);
};
struct Node
{
    void UpdateProperties();
    int NiNode_GetChildCount();
    void NiAVObject_Update(const Update&);
};
struct Cell
{
    int GetByteAtOffset38();
    void TESObjectCELL_AttachModels(bool);
    Node* GetOrCreateWidget();
};
struct Game
{
    void FUN_004534f0(bool);
    bool FUN_0047c850();
    void TESSaveLoadGame_StartLoadingSequence();
    bool TESSaveLoadGame_GetInitArrayExists();
    void TESSaveLoadGame_InitForms(int, int, int);
    void FUN_0085f850(int);
};
extern Game* DAT_011de45c;
struct Loader
{
    void BGSSaveLoadGame_SetDeferInitForms(bool);
    bool BGSSaveLoadGame_GetSaveGameLoading();
    void ResetLoadBuffers(int);
};
extern Loader* DAT_011ddf38;
struct Main
{
    bool TES_IsBuffered(Cell*);
};
extern Main* DAT_011dea10;
struct World
{
};
struct Cells
{
    Cell* GetOrCreateCell(int, int, World*, int);
};
extern Cells* DAT_011c3f2c;
struct Queue
{
    void bhkWorld_StartBatchingAdds();
    void bhkWorld_StopBatchingAdds(int);
};
Queue* TESObjectCELL_ExteriorWorld();
struct CellHandle
{
    void FUN_005ae3d0();
};
struct Grid
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int centerX, centerY;
    void TES_LoadGridCell(unsigned int, unsigned int, int, int);
    World* FUN_004fd3e0();
    void AddCellToBuffer(Cell*);
    CellHandle* NiAVObject_GetWorldTranslate(Cell**);
    void RefreshGrid();
};
bool FUN_00705e80();
void BSShaderManager_SetProjectedShadowMaskTexture(void*);
void GridCellArray_SetRecreateCanopyShadowMaskTexture(unsigned char);
extern const double DAT_01017a40;
// @fnv 0x00452ff0
void Grid::RefreshGrid()
{
    Profile profile3(26, 1, DAT_01017874, 2262);
    int originX = centerX - (*DAT_011c63cc.Setting_Int() >> 1);
    int originY = centerY - (*DAT_011c63cc.Setting_Int() >> 1);
    int count = 0;
    bool defer = false;
    if (FUN_00705e80())
        defer = true;
    bool loading4 = FUN_00705e80();
    DAT_011de45c->FUN_004534f0(true);
    DAT_011ddf38->BGSSaveLoadGame_SetDeferInitForms(true);
    if (TESObjectCELL_ExteriorWorld())
        TESObjectCELL_ExteriorWorld()->bhkWorld_StartBatchingAdds();
    for (unsigned int x = 0; x < *DAT_011c63cc.Setting_Int(); ++x)
    {
        for (unsigned int y = 0; y < *DAT_011c63cc.Setting_Int(); ++y)
        {
            TES_LoadGridCell(x, y, originX + x, originY + y);
            Cell* cell = DAT_011c3f2c->GetOrCreateCell(originX + x, originY + y, FUN_004fd3e0(), 0);
            if (DAT_011dea10->TES_IsBuffered(cell))
                AddCellToBuffer(cell);
            if (loading4 || (DAT_011de45c->FUN_0047c850() && DAT_011de45c->FUN_0047c850()))
            {
                ++count;
                float percent =
                    (double)count / (*DAT_011c63cc.Setting_Int() * *DAT_011c63cc.Setting_Int()) * DAT_01017a40;
                if (DAT_011de45c->FUN_0047c850() && DAT_011de45c->FUN_0047c850())
                    DAT_011de45c->TESSaveLoadGame_StartLoadingSequence();
            }
        }
    }
    if (TESObjectCELL_ExteriorWorld())
        TESObjectCELL_ExteriorWorld()->bhkWorld_StopBatchingAdds(0);
    DAT_011de45c->FUN_004534f0(false);
    if (DAT_011de45c->TESSaveLoadGame_GetInitArrayExists())
    {
        bool first = DAT_011de45c->FUN_0047c850();
        bool second6 = DAT_011de45c->FUN_0047c850();
        DAT_011de45c->FUN_004534f0(true);
        DAT_011de45c->FUN_004534f0(true);
        DAT_011de45c->TESSaveLoadGame_InitForms(0, 0, 0);
        DAT_011de45c->FUN_0085f850(0);
        DAT_011de45c->FUN_004534f0(second6);
        DAT_011de45c->FUN_004534f0(first);
    }
    DAT_011ddf38->BGSSaveLoadGame_SetDeferInitForms(false);
    if (!DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading())
        DAT_011ddf38->ResetLoadBuffers(0);
    if (TESObjectCELL_ExteriorWorld())
        TESObjectCELL_ExteriorWorld()->bhkWorld_StartBatchingAdds();
    for (unsigned int x2 = 0; x2 < *DAT_011c63cc.Setting_Int(); ++x2)
    {
        for (unsigned int y2 = 0; y2 < *DAT_011c63cc.Setting_Int(); ++y2)
        {
            if (FUN_004fd3e0())
            {
                Cell* cell2 = DAT_011c3f2c->GetOrCreateCell(originX + x2, originY + y2, FUN_004fd3e0(), 0);
                if (cell2)
                {
                    if (cell2->GetByteAtOffset38() == 5)
                    {
                        cell2->TESObjectCELL_AttachModels(!defer);
                        AddCellToBuffer(cell2);
                        Node* node = cell2->GetOrCreateWidget();
                        node->UpdateProperties();
                        if (!node->NiNode_GetChildCount())
                        {
                            Update update(0.0f, 0, 0);
                            node->NiAVObject_Update(update);
                        }
                    }
                    NiAVObject_GetWorldTranslate(&cell2)->FUN_005ae3d0();
                }
            }
        }
    }
    if (TESObjectCELL_ExteriorWorld())
        TESObjectCELL_ExteriorWorld()->bhkWorld_StopBatchingAdds(0);
    BSShaderManager_SetProjectedShadowMaskTexture(0);
    GridCellArray_SetRecreateCanopyShadowMaskTexture(1);
}
}

struct S_004537c0_Mgr
{
    void NiAVObject_Update(void* p);
};
struct S_004537c0_Tes : Zt5TES
{
    S_004537c0_Mgr* NiAVObject_GetParent();
};
struct S_004537c0_Fade
{
    float unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    void FUN_0043d410(float f, unsigned char a, unsigned char b);
};
bool Interface_InDialog();
float Main_QFrameAnimTime();
struct FUN_004539a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    unsigned char unkB4;
    FUN_004539a0_cls* NiAVObject_GetWorldTranslate();
    TESObjectCELL* FUN_005f36f0();
    void TES_DetachGridCells();
    void TES_FreeExteriorBuffer(unsigned char a, int b);
    bool ContainsCell(TESObjectCELL* cell);
    void FUN_00454d50(unsigned char a);
    void FUN_008d7dc0(int b);
    void TES_ClearAllCells(unsigned char a1, unsigned char a2);
};
struct FUN_004539a0_helperA
{
    void FUN_00470470();
};
struct FUN_004539a0_helperB
{
    void FUN_00483710();
};
struct BufferedCell : TESObjectCELL
{
    bool TESObjectCELL_IsRefListLocked();
};
struct BufferMap
{
    void UnloadAll_006fce00();
};
struct BufferWorld
{
    BufferMap* FUN_00586170();
};
struct CellBufferManager
{
    void* vtable;
    void* distantGrid;
    C_0084e3a0* grid;
    void* objectRoot;
    void* landRoot;
    void* waterRoot;
    void* tempNodeManager;
    void* light;
    void* fog;
    int currentGridX;
    int currentGridY;
    int queuedGridX;
    int queuedGridY;
    BufferedCell* interiorCell;
    BufferedCell** interiorBuffer;
    BufferedCell** exteriorBuffer;

    BufferedCell* FUN_005f36f0();
    void CompactQueuedCells();
    bool FUN_004511e0(BufferedCell*, bool);
    void TES_DetachGridCells();
    BufferWorld* FUN_004fd3e0();
    bool TES_ClearOldestBufferedCell();
};
struct ReloadPoint
{
    float x, y, z;
    ReloadPoint(float, int, int);
};
struct ReloadPair
{
    float x, y;
    ReloadPair(float, float);
};
struct ReloadGrid;
struct ReloadCell;
struct ReloadScene;
struct ReloadHandler
{
    void Update_006fca90(ReloadPoint*, int);
    void FUN_006fcdb0(ReloadPoint*);
    bool FUN_00454b70();
};
struct ReloadWorld
{
    ReloadHandler* FUN_00586170();
};
struct ReloadGrid
{
    bool FUN_00447a00();
    void FUN_00450f90(int);
};
struct ReloadTexture
{
    void* TESMain_GetThread();
    void* FUN_00825c00();
    void Sky_ActivateWeatherSounds(void*);
};
struct ReloadInterior;
struct ReloadRoot;
struct ReloadObject;
struct ReloadInterior
{
    ReloadGrid* NiAVObject_GetParent();
    void DetermineLevel();
};
struct ReloadInterior;
struct ReloadRoot;
struct ReloadObject;
struct ReloadScene
{
    void* GetPortalGraph_009d9f20();
    void TESObjectCELL_Detach(bool);
    void ChangeProcessLevel(bool);
    bool FUN_00454b10();
    ReloadInterior* FUN_00546c20();
    void* GetImpactSwap();
    void LoadAllTempData();
    int GetRaceListSize();
    bool TESObjectCELL_GetLoaded();
    void UpdateCellScene(ReloadObject*);
    ReloadRoot* TESObjectCELL_GetbhkWorld();
    void TESObjectCELL_AttachModels(bool);
    ReloadObject* GetOrCreateWidget();
    void TESObjectCELL_AttachLights(bool);
    const char* TESObjectCELL_GetWaterNoiseTextureName();
};
struct ReloadName
{
    void* FUN_006733e0();
    const char* TESWorldSpace_GetWaterNoiseTextureName();
};
struct ReloadRoot
{
    void bhkWorld_SetEnabled(int);
    void* ShadowSceneNode_QPortalGraph();
    void FUN_00b5ddf0(int);
    void RemoveAllLights();
    void ShadowSceneNode_ProcessQueuedLights();
    void FUN_00b5cbd0(void*);
    void SetProcessEnabled(bool);
    void bhkWorld_StartBatchingAdds();
    void bhkWorld_StopBatchingAdds(int);
};
ReloadRoot* ReloadGetRoot();
ReloadRoot* ReloadGetRootCreate(int);
ReloadRoot* ReloadGetMain(int);
void ReloadDisableRendering(int);
void ReloadDropResources(int);
void ReloadAttachManager(void*);
void ReloadGlobalUpdate(int);
struct ReloadPlayer
{
    void* PlayerCharacter_Get3D_00950bb0(int);
};
struct ReloadData
{
    void DeleteObject(ReloadScene*);
    void ProcessAllFiles();
};
struct ReloadMode
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
};
struct ReloadState
{
    bool FUN_0047c850();
};
struct ReloadCells
{
    bool ModelLoader_IsFileQueuedForCell(ReloadCell*);
};
struct ReloadAudio
{
    void LoadQueuedPriority(int);
};
struct ReloadObject
{
    void UpdateProperties();
    int NiNode_GetChildCount();
    void NiAVObject_Update(ReloadPoint*);
};
struct ReloadShader
{
    void AttachAllLand3D();
};
struct ReloadSetting
{
    float* Setting_Float_00403e20(int);
};
struct ReloadFade
{
    void FUN_00700960(bool, float, int);
};
struct ReloadTerrain
{
    void ClearMobileObjectData();
    void ProcessLists_PlaceActorsinBedsOrChairs();
    void FUN_00972bb0();
};
struct ReloadZone
{
    void SetColorData(void*);
};
struct ReloadNode
{
    unsigned object;
    ReloadNode(int);
    ~ReloadNode();
    void* Modelloader_GetReferencedThis();
};
struct TileReloadContext
{
    void TES_ActivateAllSubmergedReferencesIslands();
    void FUN_004568c0(const char*, ReloadNode&, int, int);
    ReloadZone* DetailedActorPathHandler_GetCurrentNodeIndex();
};
struct ReloadContext
{
    int old;
    ReloadContext(int, bool, const char*, int);
    ~ReloadContext();
};
struct ReloadPathing
{
    void NavMeshObstacleManager_ForceUpdate();
};
ReloadPathing* ReloadPathingGet();
extern ReloadPlayer* reloadPlayer;
extern ReloadData* reloadData;
extern ReloadMode* reloadMode;
extern ReloadState* reloadState;
extern ReloadCells* reloadCells;
extern ReloadAudio* reloadAudio;
extern ReloadSetting reloadSetting;
extern ReloadFade* reloadFade;
extern ReloadTerrain reloadTerrain;
extern TileReloadContext* reloadMenu;
extern bool reloadFinished, reloadFlagA, reloadFlagB, reloadHasWorld, reloadFlagC;
extern ReloadPoint reloadRotation;
extern ReloadPair reloadCurrent, reloadPrevious;
extern float reloadHeight;
float ReloadHeight(int);
void ReloadMovePoint(ReloadPoint, ReloadPoint, float);
bool ReloadDropFlag();
struct ReloadCamera
{
    void ClearCanopyShadowMaskTexture();
};
struct ReloadManager
{
    unsigned unk00;
    unsigned unk04;
    ReloadCamera* camera;
    ReloadObject* object;
    ReloadInterior* interior;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    int gridX;
    int gridY;
    int oldX;
    int oldY;
    unsigned unk34;
    unsigned unk38;
    int* loaded;
    unsigned unk40;
    unsigned unk44;
    int savedX;
    int savedY;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    ReloadTexture* texture;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    ReloadName* name;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    ReloadNode loadedNode;
    int TES_FreeExteriorBuffer(int, int);
    void TES_DetachGridCells();
    ReloadScene* GetEntry(int);
    void RemoveEntry(ReloadScene*);
    void FUN_008d7dc0(ReloadScene*);
    void Pause(int, int);
    void UpdateSkyModeForCell(ReloadScene*);
    void TES_AddToInteriorBuffer(ReloadScene*);
    void AttachScene(ReloadScene*, ReloadPoint*);
    ReloadWorld* FUN_004fd3e0();
    ReloadScene* FUN_005f36f0();
    bool ContainsCell(ReloadScene*);
    void FUN_008d7dc0(int);
    void Pause(int, ReloadPoint*);
    int TES_GetLandGeometry(ReloadPoint*);
    void FUN_00452580(ReloadPoint*, bool);
    ReloadCell* FUN_00451900(int, int);
    void TES_ShowLoadingMenu(int, ReloadCell*, int);
    ReloadShader* FUN_0044ddc0();
    void InitFromMatrix();
    void InitSoundGrid();
    void TES_ActivateAllSubmergedReferencesIslands();
    void GetLandHeightAt(ReloadPoint*, float&);
    bool TES_CellTestRunning();
    void ProcessItemNodes();
    void TES_UpdateGridLights();
    void UpdateSkyModeForCell(int);
    void FUN_00452490(int);
    void TES_LeaveInterior(ReloadPoint*);
};
struct ReloadInterface
{
    void BSShaderLightingProperty_ClearLights_Thunk();
    void BSShaderAccumulator_ClearAllQueries();
};
ReloadInterface* ReloadGetInterface();
void ReloadInterfaceReset();
void ReloadInterfaceRefresh();
struct ReloadStreaming
{
    void Main_RenderMenuBackground();
    void Main_Swap();
};
extern ReloadStreaming* reloadStreaming;
struct ReloadBoolSetting
{
    bool* FUN_00408d60();
};
extern ReloadBoolSetting reloadBoolSetting;
struct ReloadRuntime
{
    bool MoviePlayer_GetPlayingSequence();
};
extern ReloadRuntime* reloadRuntime;
bool ReloadMenuActive(int, int);
struct ReloadGridSetting
{
    int* Setting_Int();
};
extern ReloadGridSetting reloadGridSetting;
int ReloadRound(float);
struct ReloadLoaded
{
    void FUN_00628da0();
};
struct ReloadPlayerCheck
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
    virtual void v048();
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
    virtual void v100();
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
    virtual int CheckState();
};
extern ReloadPlayerCheck* reloadPlayerCheck;
struct NiSourceTexture;
struct NiTextureFormatPrefs
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};
extern NiTextureFormatPrefs g_kTexturePrefs;
template <class T> struct TexPtr
{
    T* m_pObject;
    TexPtr(T* apObject);
    ~TexPtr();
    TexPtr& operator=(T* apObject);
    operator T*() const;
};
struct FixedStr
{
    const char* m_kHandle;
    FixedStr(const char* apString);
    ~FixedStr();
};
struct SourceTextureStub
{
    static NiSourceTexture* Create(const FixedStr& arName, NiTextureFormatPrefs& arPrefs, bool abA, bool abB);
};
bool StreamGetTexture(const char* apPath, TexPtr<NiSourceTexture>* apTexture);
void TextureLoaded(NiSourceTexture* apTexture, int aiUnk);
void ModelWarning(const char* apFormat, ...);
struct TESTexLoader
{
    void FUN_004568c0(const char* apPath, TexPtr<NiSourceTexture>& arTexture, bool abNoWarning, bool abArchiveOnly);
};
struct FUN_00450f90_obj
{
    void FUN_00450f90(bool abFlag);
};
FUN_00450f90_obj* __cdecl TESWaterSystem_GetWaterRoot();
void __cdecl TESObjectCELL_SetNodeCulled(int aiType, bool abFlag);
struct FUN_00456fc0_ref
{
    FUN_00450f90_obj* FUN_00456fc0(int aiType);
    void TESObjectCELL_CullChildrenOfMultibounds(bool abFlag, int aiType);
};
struct FUN_00456d00_cnt
{
    int* Setting_Int();
};
struct FUN_00456d00_tes
{
    FUN_00456fc0_ref* FUN_005f36f0();
    FUN_00456fc0_ref** GetGridCell_00457050(unsigned int i, unsigned int j);
};
struct FUN_00456d00_shell
{
    char pad[0x38];
    FUN_00456fc0_ref** ppRefs;
    FUN_00456fc0_ref** ppOthers;
    FUN_00456fc0_ref* FUN_005f36f0();
    void TES_ShowCellNode(int aiType, bool abShow, bool abGrid);
};
extern const NiPoint3 NiPoint3_ZERO;
struct FUN_004571c0_obj
{
    void SetFlag(void* p);
    void SetTransforms(const NiPoint3* a, const NiPoint3* b, int c);
};
struct FUN_004571c0_cell : FUN_004570d0_node
{
    bool Apply(FUN_004571c0_obj* obj, int a2, int a3, float f, unsigned char b);
};
struct FUN_004571c0_cls : FUN_004570d0_cls
{
    bool ApplyToObject(FUN_004571c0_obj* obj, int a2, int a3, float f, char b);
};
struct WS458200_Obj
{
    void DetermineLevel();
};
struct WS458200_Quest;
struct WS458200_World
{
    WS458200_Obj* GetFieldD0();
    WS458200_Quest* FUN_006733e0();
    const char* TESWorldSpace_GetWaterNoiseTextureName() const;
    bool IsFlag4C20Set();
};
struct WS458200_Sky
{
    void SetColorData(NiSourceTexture* apTexture);
};
struct WS458200_TES
{
    WS458200_Sky* GetSky();
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};
extern WS458200_TES* g_pWS458200TES;
extern GlobalObject_0045cf30 g_011c3d40;
void __cdecl FUN_0058eeb0(WS458200_Quest*);
void __cdecl FUN_007043c0();
void __cdecl Interface_SetRootMapSpace(WS458200_World*);
void __cdecl BSShaderManager_SetUseNoiseMap(bool);
struct WS458200_Shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    WS458200_World* m_pContainingWorldspace;

    void* FUN_005f36f0();
    void TES_DetachGridCells();
    int TES_FreeExteriorBuffer(bool abSkipLoaded, WS458200_World* apWorld);
    int FUN_00454d50(bool abArg);
    void FUN_00452490(bool abArg);
    void FUN_00450d80();
    void TES_SetWorldSpace(WS458200_World* apWorld);
};
class Ref458
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual bool PlaySound(int iSound, NiPoint3 kPos);
};
class Manager458
{
  public:
    Ref458* GetDefaultRef();
    bool PlaySoundOnRef(int iSound, NiPoint3 kPos, Ref458* pkRef);
};
struct SaveWriter : SaveState
{
    unsigned char* FUN_00825c00();
    void TESSaveLoadGame_SaveGameDataOLD(void*, unsigned int);
    void TESSaveLoadGame_SaveNumericID(void*, unsigned int);
};
struct ValueReferencePair
{
    C_0084e3a0* form;
    unsigned short value;
};
struct SaveEntryNode
{
    ValueReferencePair** FUN_006815c0();
    SaveEntryNode* FUN_00726070();
};
struct SaveBlockOwner : SaveSizeOwner
{
    void WriteSaveBlock();
};
void FNV_Warning(const char*, ...);
extern const char DAT_01017e24[];
struct EmptyStructPlaceholder
{
};
struct TestWorldString
{
    const char* TESModel_GetModel();
};
struct TestWorld
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
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
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* DebugName();
    int unk04, unk08, unk0c, unk10, unk14;
    TestWorldString name;
    float FUN_004565f0();
    float GetUnka4();
    float FUN_009b88a0();
    float LowProcess_GetPlayerDamageDealt();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    EmptyStructPlaceholder* FUN_005875a0(int, int);
    EmptyStructPlaceholder* TESWorldSpace_LoadCell(int, int);
};
struct TestWorldList
{
    bool FUN_008256d0();
    TestWorld** FUN_006815c0();
    TestWorldList* FUN_00726070();
};
struct TestDataHandler
{
    TestWorldList* TESDataHandler_GetWorldSpaceList();
    void TESDataHandler_SortInteriorCells();
    unsigned int FUN_00461960();
    EmptyStructPlaceholder* GetCameraPathAt(unsigned int);
};
extern TestDataHandler* testDataHandler;
struct TestStep
{
    int* Setting_Int();
};
extern TestStep testStep;
void PlayerCharacter_SetGodMode(bool);
void ProgramFlow(const char*, ...);
void Interface_EmergencyCloseAllMenusAndBreakStuff();
int Cmd_GetSessionTime_Execute();
unsigned int BSstrlen(const char*);
struct CellTest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned char unk50;
    bool running, finished;
    void TES_SetWorldSpace(TestWorld*);
    void MoveToCell(EmptyStructPlaceholder*, unsigned int, int);
    void TES_RunCellTest(unsigned int);
};
struct AddonQueuePointer
{
    QueuedFile* object;
    QueuedFile* Modelloader_GetReferencedThis();
    AddonQueuePointer& AssignTaskReference(QueuedFile* file);
};
struct AddonFormBase
{
    virtual void ReservedForm0();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct AddonParticleNode : NiNode
{
    void SetSound(unsigned int index);
    void FUN_00705b10(int value);
    void SetShortAtOffsetBC(unsigned short value);
};
struct AddonParticleManager
{
    void BSParticleSystemManager_AddMasterParticleSystem(AddonParticleNode* node);
};
AddonParticleManager* Main_GetMasterParticleSystemManager();
extern ModelLoader* g_modelLoader;
struct AddonOwner
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    AddonQueuePointer queuedFile;
    void TES_PreloadAddonNodes();
};
struct ModelSetting
{
    char* String();
};
extern bool DAT_011c3f08;
extern ModelLoader* g_modelLoader;
struct PreloadOwner : ModelCloneOwner
{
    void PreloadModelSettings();
};
extern ModelSetting g_011ce0c0;
extern ModelSetting g_011cfa28;
extern ModelSetting g_011d12c0;
extern ModelSetting g_011ce1a0;
extern ModelSetting g_011cfa64;
extern ModelSetting g_011cf3a4;
extern ModelSetting g_011cf54c;
extern ModelSetting g_011cebb0;
struct FUN_0045ae20
{
    ~FUN_0045ae20();
    FUN_0045ae20* FUN_0044ddc0();
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern FUN_0045a5e0_shell* DAT_011c3b3c;
extern InventoryMenuSetting DAT_011cebb0;
extern InventoryMenuSetting DAT_011d12c0;
extern InventoryMenuSetting DAT_011ce1a0;
extern InventoryMenuSetting DAT_011cf3a4;
extern InventoryMenuSetting DAT_011cf54c;
extern InventoryMenuSetting DAT_011cfa64;
extern InventoryMenuSetting DAT_011ce0c0;
extern InventoryMenuSetting DAT_011cfa28;
struct Target
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    FUN_0045ae20* head;
    void TES_CleanupTemporaryParticleCache();
};
extern TESDataHandler* g_pkDataHandler45A;
class Owner45A
{
  public:
    NavMeshInfoMap* TES_GetNavMeshInfoMap();

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    NavMeshInfoMap* m_pkNavMeshInfoMap;
};
extern float DAT_01015f5c;
struct CellView : public TESObjectCELL
{
    bool CheckWaterHeight(const NiPoint3* apPos, float* apfHeight);
    int FUN_00544c30();
    int FUN_00544c60();
};
bool __fastcall FUN_00425fd0(TESObjectCELL* apCell);
struct FUN_0045cbc0_Grid
{
    CellView* GetCellFromWorldCoord(const NiPoint3* apPos);
    float FUN_0045cd80();
    CellView* FUN_005875a0(int aiX, int aiY);
};
struct FUN_0045cbc0_TES
{
    FUN_0045cbc0_Grid* FUN_004fd3e0();
    int FUN_0059bb30();
    int FUN_0045cd60();
};
struct FUN_0045cbc0_shell
{
    CellView* FUN_005f36f0();
    float GetCellHeightAtPosition(const NiPoint3* apPos, CellView* apCell);
};
// Register this reference with its cell's world occlusion manager (planes, lists and bounds).
class C6760Base
{
  public:
    virtual ~C6760Base();
    int unk04;
};
class C6760ManagerBase
{
  public:
    virtual ~C6760ManagerBase();
};
class C6760Ref;
class C6760Manager : public C6760Base, public C6760ManagerBase
{
  public:
    void AddPlanes(C6760Ref* pkRef);
    void AddToLists(C6760Ref* pkRef);
    void UpdateBounds(C6760Ref* pkRef);
};
class C6760World
{
  public:
    C6760ManagerBase* GetOcclusionManager();
};
class C6760Cell
{
  public:
    C6760World* GetWorld();
};
class C6760Ref
{
  public:
    C6760Cell* GetParentCell();
    void TESObjectREFR_CleanUpTraps();
};
int __cdecl FloatToInt(float f);
namespace n451 {
struct Pt
{
    float iMinY, nX, z;
};
struct Grid
{
    char pad[0x24];
    int m_24;
    int m_28;
    void* FUN_005f36f0();
    bool ContainsPoint(const Pt& pt);
};
}
// @fnv 0x00451110
bool n451::Grid::ContainsPoint(const Pt& pt)
{
    if (FUN_005f36f0())
        return true;
    int iMinY = FloatToInt(pt.iMinY) >> 12;
    int nX = FloatToInt(pt.nX) >> 12;
    int ix = m_24 - (*DAT_011c63cc.Setting_Int() >> 1);
    int px = m_28 - (*DAT_011c63cc.Setting_Int() >> 1);
    if (iMinY < ix || iMinY >= ix + (int)*DAT_011c63cc.Setting_Int() || nX < px ||
        nX >= px + (int)*DAT_011c63cc.Setting_Int())
        return false;
    return true;
}

struct FUN_005400e0_obj : FUN_0045cb90_cls
{
    void TESObjectLAND_InitDistantTextureBlending();
};
struct FUN_00546fb0_cell : B45CDA0Cell
{
    FUN_005400e0_obj* TESObjectCELL_GetLand();
};
struct FUN_0045cac0_tes : B45CDA0TES
{
    void TES_InitDistantTextureBlending();
};
struct CellHit
{
    bool TESObjectLAND_GetLandNormal();
};
struct CellProbe
{
    CellHit* TESObjectCELL_GetLand(const NiPoint3* pos, NiPoint3* normal, int flags);
};
struct TESCellLookup
{
    bool FUN_004511e0(void* cell, unsigned char flag);
};
struct FUN_004573f0_shell : public TES
{
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    bool TES_GetLandNormal(const NiPoint3* pos, NiPoint3* normal, int flags);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern const double DAT_01012060;

inline void NiAVObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<long volatile*>(&m_uiRefCount));
}
inline void NiAVObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
inline float BSTempNode::UpdateTime(float f)
{
    float delta = time != DAT_01012060 ? f - time : time;
    time = f;
    return delta;
}
inline NiAVObject* BSTempNode::GetChild(unsigned int i)
{
    NiAVObject* const& entry = m_kChildren.m_pBase[i].m_pObject;
    {
        NiAVObject* item = entry;
        return item;
    }
}
inline void BSTempNode::SetTime(float f)
{
    time = f;
    if (time < DAT_01012060)
        time = 0.0f;
}
inline bool BSTempNode::Expired() const
{
    return time == DAT_01012060;
}
__forceinline bool IsKindOfType(const NiRTTI* target, const NiAVObject* object)
{
    const NiRTTI* rtti = object->GetRTTI();
    while (rtti)
    {
        if (rtti == target)
            return true;
        rtti = rtti->m_pBaseRTTI;
    }
    return false;
}
__forceinline BSTempNode* CastNode(NiAVObject* object)
{
    if (!object)
        return 0;
    return IsKindOfType(reinterpret_cast<const NiRTTI*>(&g_01202e00), object) ? static_cast<BSTempNode*>(object) : 0;
}
// @fnv 0x00c44ed0
// src: XBOX_PDB 0x00c44ed0
void BSTempNode::BSTempNodeManager_RemoveExpired(float f)
{
    NiPointer<NiAVObject> spRemoved;
    float delta = UpdateTime(f);
    {
        unsigned int i = m_kChildren.m_usSize;
        while (i--)
        {
            NiAVObject* object = GetChild(i);
            BSTempNode* child = CastNode(object);
            if (child)
            {
                child->SetTime(child->time - delta);
                if (child->Expired())
                    RemoveNthObject2(i, &spRemoved.m_pObject);
            }
        }
    }
}
