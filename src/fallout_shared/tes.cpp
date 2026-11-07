// MSVC reserves this spelling for its generated constructor thunk.
#include "../../include/MEM_CONTEXT.h"
#define __local_vftable_ctor_closure LocalVftableConstructorClosure
#include "../../include/TESObject.h"
#include "../../include/TESBoundObject.h"
#undef __local_vftable_ctor_closure

// Load NiNode first: newer headers share its array template with the texture header.
#include "../../include/NiNode.h"

#include "../../include/NiTexturingProperty.h"

#include "../../include/Actor.h"
#include "../../include/BGSAddonNode.h"
#include "../../include/BGSPlaceableWater.h"
#include "../../include/BSTempNodeManager.h"
#include "../../include/MagicItem.h"
#include "../../include/QueuedFile.h"
#include "../../include/SpellItem.h"
#include "../../include/StartMenu.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESObjectTREE.h"
#include "../../include/TESSound.h"

#include "../../include/AutoMemContext.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/BSAudio.h"
#include "../../include/EffectSetting.h"
#include "../../include/ExtraDataList.h"
#include "../../include/GO.h"
#include "../../include/GridCellArray.h"
#include "../../include/IOManager.h"
#include "../../include/InventoryChanges.h"
#include "../../include/LoadedAreaBound.h"
#include "../../include/MagicTarget.h"
#include "../../include/MobileObject.h"
#include "../../include/NP.h"
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
#include "../../include/NiAVObject.h"
#include "../../include/NiAdditionalGeometryData.h"
#include "../../include/NiCamera.h"
#include "../../include/NiColorA.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiUpdateData.h"
#include "../../include/PlaceableWaterData.h"
// ProcessTarget_tes: local type (was include/ProcessTarget.h, which had no evidence of one real class); its methods are 0x008d0430 BaseProcess::GetCurrentPackageInstanceData, 0x0091ab30 MiddleHighProcess::GetTargetForPackage, 0x0091ae00 MiddleHighProcess::SetTargetData, 0x009611e0 NiAVObject::GetParent
class PackageRuntime;
class PackageTargetData;
class TESPackage;

class TESPackage;

class ProcessTarget_tes
{
public:
    TESObjectREFR* MiddleHighProcess_SetTargetData(Actor*, TESPackage*, PackageTargetData*);
    PackageRuntime* FUN_008d0430();
    TESObjectREFR* MiddleHighProcess_GetTargetForPackage(Actor*, TESPackage*);
};
#include "../../include/SceneGraph.h"
#include "../../include/Setting.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/Sky.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/TES.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectLAND.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESBoundTreeObject.h"
#include "../../include/TESModelTree.h"
#include "../../include/TESIconTree.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiPointer.h"
#include "../../include/ProcessLists.h"
#include "../../include/TreeRecordData.h"
#include "../../include/TESWaterForm.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/BSTempNode.h"

#undef interface
#undef lst2

// Local subclasses add declarations absent from the shared headers without copying storage.
// TESDataHandler.h does not yet declare icon validation.
struct TESDataHandlerIconValidation : TESDataHandler
{
    void ValidateFormIcons();
};

// This lookup is absent from TES.h; keep only its declaration here.
struct TESCoordinateLookup : TES
{
    TESObjectCELL* FindCell(int aiCellX, int aiCellY);
};

// src/fallout_shared/tes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


struct GlobalObject_00a7b610
{
};
extern GlobalObject_00a7b610 g_01202df8;


struct TemporaryNodeManagerRTTI : BSTempNodeManager
{
    virtual const NiRTTI* GetNiRTTI() const;
};

// @fnv 0x00450620
const NiRTTI* TemporaryNodeManagerRTTI::GetNiRTTI() const
{
    return (const NiRTTI*)&g_01202df8;
}


extern "C" void __cdecl FUN_00c44e20(BSTempNodeManager*);
extern void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x00450630
void* BSTempNodeManager::FUN_00450630(unsigned int flags)
{
    this->BSTempNodeManager::~BSTempNodeManager();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0xb0);
    return this;
}

struct FUN_004512a0_shell
{
    unsigned char m_ucState;
    void SetState(unsigned char ucState);
};

// @fnv 0x004512a0
void FUN_004512a0_shell::SetState(unsigned char ucState)
{
    *reinterpret_cast<unsigned char*>(this + 0x26) = ucState;
}

extern char DAT_01189184;

// @fnv 0x00451520
// src: XBOX_PDB 0x00451520
void GridCellArray_SetRecreateCanopyShadowMaskTexture(unsigned char value)
{
    DAT_01189184 = value;
}


extern NP DAT_011f95e8;

// @fnv 0x00451570
// src: XBOX_PDB 0x00451570
void BSShaderManager_SetProjectedShadowMaskTexture(void* apValue)
{
    DAT_011f95e8 = apValue;
}

extern unsigned char DAT_011ad86c;

// @fnv 0x00451590
// src: XBOX_PDB 0x00451590
void TallGrassShaderProperty_SetUseBackgroundLoading(unsigned char value)
{
    DAT_011ad86c = value;
}

struct blob12
{
    char b[12];
};

// @fnv 0x004516b0
bool TESDataHandler::GetSaveLoad()
{
    return bSaveLoad;
}

struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct blob4
{
    char b[4];
};

typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct SaveLoadStateQuery : BGSSaveLoadGame
{
    bool TESObjectCELL_GetAttaching();
};

int __fastcall GetByteAtOffset38(void*);

// @fnv 0x004523c0
// src: XBOX_PDB 0x004523c0
bool SaveLoadStateQuery::TESObjectCELL_GetAttaching()
{
    return GetByteAtOffset38(this) == 5;
}

struct FUN_00452420_shell
{
    unsigned int pad0;   // +0x00
    unsigned int pad1;   // +0x04
    unsigned int pad2;   // +0x08
    unsigned int pad3;   // +0x0C
    unsigned int flags;  // +0x10
    bool GetFlag(unsigned int aiFlags) const;
};

// @fnv 0x00452420
bool FUN_00452420_shell::GetFlag(unsigned int aiFlags) const
{
    return (flags & aiFlags) ? true : false;
}

struct FormCollisionQuery : TESForm
{
    bool __thiscall BGSPlaceableWater_IsAutomaticWater();
};

struct FormFlagQuery : TESForm
{
    bool __thiscall HasFlags(int arg);
};

// @fnv 0x00452440
// src: XBOX_PDB 0x00452440
bool __thiscall FormCollisionQuery::BGSPlaceableWater_IsAutomaticWater()
{
    return reinterpret_cast<FormFlagQuery*>(this)->HasFlags(0x40000000);
}


// @fnv 0x00452460
bool __thiscall BGSPlaceableWater::HasFlags(unsigned int flags)
{
    return (this->GetExtraPartList()->flags & flags) ? true : false;
}

extern unsigned char DAT_0119b8c8;

// @fnv 0x00452480
// src: XBOX_PDB 0x00452480
unsigned char BSTreeManager_GetUseCanopyShadows()
{
    return DAT_0119b8c8;
}

int __fastcall NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(void*);

struct FUN_00453470_shell
{
    int __thiscall NiNode_GetChildCount(void);
};

// @fnv 0x00453470
// src: XBOX_PDB 0x00453470
int __thiscall FUN_00453470_shell::NiNode_GetChildCount(void)
{
    return NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(reinterpret_cast<char*>(this) + 0x9c);
}


// @fnv 0x004534f0
void __thiscall TESForm::Revert(unsigned int)
{}

struct FUN_00453500_shell
{
    void BGSSaveLoadGame_SetDeferInitForms(bool set);
};

// @fnv 0x00453500
// src: XBOX_PDB 0x00453500
void FUN_00453500_shell::BGSSaveLoadGame_SetDeferInitForms(bool set)
{
    if (set)
    {
        *(unsigned int*)(this + 0x244) |= 0x10;
    }
    else
    {
        *(unsigned int*)(this + 0x244) &= ~0x10;
    }
}


BSAudio* DAT_011f6d98;

// @fnv 0x00453a70
// src: XBOX_PDB 0x00453a70
BSAudio* BSAudio_QInstance()
{
    return DAT_011f6d98;
}

extern unsigned char DAT_011f9427;

// @fnv 0x00454440
// src: XBOX_PDB 0x00454440
void BSShaderManager_SetInterior(unsigned char value)
{
    DAT_011f9427 = value;
}

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

// @fnv 0x00454b50
// src: XBOX_PDB 0x00454b50
char const* FUN_00454b50_shell::TESWorldSpace_GetWaterNoiseTextureName() const
{
    return ((FNStub*)((char*)this + 0xe0))->GetFullName();
}

// @fnv 0x00455600
void* TESDataHandler::GetQuestList()
{
    return listQuests;
}


struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList(void);
    bool TESQuest_GetEnabled(void);
};

// @fnv 0x00455620
// src: XBOX_PDB 0x00455620
bool TESFaction_RankDataView::TESQuest_GetEnabled()
{
    return (*GetRankDataList() & 1) != 0;
}

extern int DAT_011c56e8;

// @fnv 0x00455680
// src: COMMUNITY 0x00455680
void ClearAnimationCloneCount()
{
    DAT_011c56e8 = 0;
}

struct FUN_004565f0_shell
{
    float m_f;
    float GetFloat();
};

// @fnv 0x004565f0
float FUN_004565f0_shell::GetFloat()
{
    return *(float*)((char*)this + 0xa0);
}

extern const void* const g_01202e00;

struct FUN_00458f20_shell
{
    const void* const* BSTempNode_GetRTTI() const;
};

// @fnv 0x00458f20
// src: COMMUNITY 0x00458f20
const void* const* __thiscall FUN_00458f20_shell::BSTempNode_GetRTTI() const
{
    return &g_01202e00;
}

extern "C" void __fastcall UpdateFields_00c5faa0(void*);
extern int DAT_01017d24;

struct FUN_00458f70_shell
{
    void __thiscall SetVtableAndProcessState_00458f70();
};

// @fnv 0x00458f70
// src: GUESS 0x00458f70 (confidence: low)
void __thiscall FUN_00458f70_shell::SetVtableAndProcessState_00458f70()
{
    *(int*)this = (int)&DAT_01017d24;
    UpdateFields_00c5faa0(this);
}

namespace fnv_0045a520 {

struct ModelLoader
{
    void ModelLoader_ReleaseFile(char const*);
};


extern ModelLoader* g_modelLoader;
extern StartMenu g_011cebb0;
extern StartMenu g_011d0ce4;
extern StartMenu g_011d12c0;
extern StartMenu g_011d14c4;

struct FUN_0045a520_shell
{
    void LoadStartMenuModels();
};

// @fnv 0x0045a520
void __thiscall FUN_0045a520_shell::LoadStartMenuModels()
{
    if (static_cast<const StartMenu&>(g_011d14c4).GetMenuTitle()[0])
        g_modelLoader->ModelLoader_ReleaseFile(static_cast<const StartMenu&>(g_011d14c4).GetMenuTitle());

    if (static_cast<const StartMenu&>(g_011cebb0).GetMenuTitle()[0])
        g_modelLoader->ModelLoader_ReleaseFile(static_cast<const StartMenu&>(g_011cebb0).GetMenuTitle());

    if (static_cast<const StartMenu&>(g_011d12c0).GetMenuTitle()[0])
        g_modelLoader->ModelLoader_ReleaseFile(static_cast<const StartMenu&>(g_011d12c0).GetMenuTitle());

    if (static_cast<const StartMenu&>(g_011d0ce4).GetMenuTitle()[0])
        g_modelLoader->ModelLoader_ReleaseFile(static_cast<const StartMenu&>(g_011d0ce4).GetMenuTitle());

    ((NP*)((char*)this + 0xa8))->operator=((void*)0);
}
}  // namespace fnv_0045a520

struct AnimIdle;
struct Animation;
struct AttachDistant3DTask;
struct BSFile;
struct BSFileEntry;
struct BackgroundCloneThread;
struct BipedAnim;
struct KFModel;
struct LoadedFile;
struct Model;
struct NiControllerSequence;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESNPC;
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

// @fnv 0x0045a5e0
// src: XBOX_PDB 0x0045a5e0
void FUN_0045a5e0_shell::ModelLoader_ReleaseFile(char* apModelFileName)
{
    QueueModelLoad(apModelFileName, true, 1);
}

void __cdecl CreateCSDFadeNode(void);
void __cdecl CreateSpdFadeNode(void);
void __cdecl BGSAddonNodeSoundHandleExtra_InitTag(void);
void __cdecl BSFaceGenAnimationData_InitTag(void);
void __cdecl BSFaceGenModelExtraData_InitTag(void);
void __cdecl BSFaceGenBaseMorphExtraData_InitTag(void);

// @fnv 0x0045b020
// src: COMMUNITY 0x0045b020
void __cdecl TES_InitSDM(void)
{
    BSFaceGenAnimationData_InitTag();
    BSFaceGenModelExtraData_InitTag();
    BSFaceGenBaseMorphExtraData_InitTag();
    BGSAddonNodeSoundHandleExtra_InitTag();
    CreateSpdFadeNode();
    CreateCSDFadeNode();
}

struct FUN_0045c650_shell
{
    void* hkpMotion_getLinearVelocity();
};

// @fnv 0x0045c650
// src: XBOX_PDB 0x0045c650
void* FUN_0045c650_shell::hkpMotion_getLinearVelocity()
{
    return reinterpret_cast<char*>(this) + 0xD0;
}

struct Flt
{
    operator unsigned int(void) const;
};

extern Flt g_011deb7c;

// @fnv 0x0045c670
// src: XBOX_PDB 0x0045c670
unsigned int Main_GetWorldSceneGraph()
{
    return g_011deb7c;
}


void TESObjectREFR_AddMasterParticleAddonNodes(TESObjectREFR* self);
void TESObjectREFR_RemoveMasterParticleAddonNodes(TESObjectREFR* self);

// Calls FUN_00578060 on arg when flag is true, otherwise calls FUN_00578170 on arg.
// @fnv 0x0045c680
// src: COMMUNITY 0x0045c680
void TES_RangedNodeVisibilityChangedCB(TESObjectREFR* apRefr, bool flag)
{
    if (flag)
    {
        TESObjectREFR_AddMasterParticleAddonNodes(apRefr);
    }
    else
    {
        TESObjectREFR_RemoveMasterParticleAddonNodes(apRefr);
    }
}

extern "C" double _gModifierZero;


// Computes the dot product of this camera's xyz with other minus w and returns 2 if negative, 1 if positive, else 0.
// @fnv 0x0049da80
int __thiscall NiCamera::ClassifyPoint(const NiPoint3* apPoint)
{
    float result = ((float*)this)[0] * apPoint->x + ((float*)this)[1] * apPoint->y + ((float*)this)[2] * apPoint->z - ((float*)this)[3];
    if (result < 0.0)
        return 2;
    else if (result > 0.0)
        return 1;
    else
        return 0;
}

struct FUN_00451cd0_shell
{
    unsigned char TESClimate_GetVolatilityIndex();
};

// @fnv 0x00451cd0
// src: XBOX_PDB 0x00451cd0
unsigned char FUN_00451cd0_shell::TESClimate_GetVolatilityIndex()
{
    return *(unsigned char*)((char*)this + 0x54);
}

class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class NiDirectionalLight;
class NiFogProperty;
class NiGeometry;
class NiPick;
class NiTexture;
class QueuedReference;
class TESLandTexture;
class TESRegion;
class TESWaterSystem;
namespace fnv_00452490 {
struct GridCellData;
struct GridCell;
struct GridDistantArray;
struct GridLand;
struct TESFormList;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};


struct Renderer
{
    static bool __cdecl CanRender(void);
};
void __cdecl LockSpinLock(void);
void __cdecl BSTreeManager_ClearModelCache(unsigned int);
struct TESActivityQuery : TES
{
    bool __thiscall GetByteB5(void);
};
void __cdecl BSTexturePalette_PurgeUnusedTextures(void);
void __cdecl BSTexturePalette_Unlock(void);

// @fnv 0x00452490
} // namespace fnv_00452490
void TES::SetTESActive(bool abWaitForCompletion)
{
    using namespace fnv_00452490;
    if (!Renderer::CanRender())
        return;
    LockSpinLock();
    BSTreeManager_ClearModelCache(1);
    if (reinterpret_cast<TESActivityQuery*>(this)->GetByteB5() || abWaitForCompletion)
    {
        BSTexturePalette_PurgeUnusedTextures();
    }
    BSTreeManager_ClearModelCache(1);
    BSTexturePalette_Unlock();
}
namespace fnv_00452490 {

}  // namespace fnv_00452490


// If cell is non-null, adds it to the interior buffer when it is interior, otherwise to the exterior buffer.
// @fnv 0x00454b90
void TES::AddToBuffer(TESObjectCELL* cell)
{
    if (cell)
    {
        if (cell->IsInterior())
        {
            ((TES*)this)->AddCellToInteriorBuffer(cell);
        }
        else
        {
            ((TES*)this)->AddCellToExteriorBuffer(cell);
        }
    }
}

struct FUN_00458f30_shell
{
    void SetVtableAndProcessState_00458f70();
    void* DestroyIfFlagged(unsigned int flags);
};

void _delete(void* obj, unsigned int size);

// Calls FUN_00458f70, then deletes this with size 0xb0 when bit 0 of flags is set, and returns this.
// @fnv 0x00458f30
void* FUN_00458f30_shell::DestroyIfFlagged(unsigned int flags)
{
    this->SetVtableAndProcessState_00458f70();
    if (flags & 1)
        _delete(this, 0xb0);
    return this;
}

struct CellLoadFinalizer : TES
{
    void TES_ClearDeadCountList();
    void TES_Revert(unsigned int a);
};

// @fnv 0x00459840
// src: XBOX_PDB 0x00459840
void __thiscall CellLoadFinalizer::TES_Revert(unsigned int a)
{
    this->TES_ClearDeadCountList();
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48) = 0x7fffffff;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x4c) = 0x7fffffff;
}

struct FUN_0045a730_shell
{
    char* TESDataHandler_GetWaterForms();
};
// @fnv 0x0045a730
// src: COMMUNITY 0x0045a730
char* FUN_0045a730_shell::TESDataHandler_GetWaterForms()
{
    return reinterpret_cast<char*>(this) + 0x130;
}

extern "C" void __cdecl _Deallocate(void*);

struct FUN_0045ae20_shell
{
    void FUN_0045ae50();
    void* FUN_0045ae20(unsigned int flags);
};

// Calls FUN_0045ae50, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0045ae20
void* FUN_0045ae20_shell::FUN_0045ae20(unsigned int flags)
{
    FUN_0045ae50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00451250_shell
{
    unsigned char bFlags;
    void SetFlag2(bool value);
};

// @fnv 0x00451250
void FUN_00451250_shell::SetFlag2(bool abSet)
{
    abSet ? ((unsigned char*)this)[0x24] |= 2 : ((unsigned char*)this)[0x24] &= ~2;
}

class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class NiDirectionalLight;
class NiFogProperty;
class NiGeometry;
class NiPick;
class NiTexture;
class QueuedReference;
class TESLandTexture;
class TESRegion;
class TESWaterSystem;
namespace fnv_00451530 {
struct GridCellData;
struct GridCell;
struct GridDistantArray;
struct GridLand;
struct TESFormList;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};

struct PendingCellState : TES
{
    bool TES_CellTestRunning();
};

// @fnv 0x00451530
// src: XBOX_PDB 0x00451530
bool PendingCellState::TES_CellTestRunning()
{
    return *(bool*)((char*)this + 0x51) || *(bool*)((char*)this + 0x52);
}
}  // namespace fnv_00451530

struct FUN_00401280_shell
{
    void retn_empty_string();
};
struct FUN_00451cb0_shell
{
    void TESObjectCELL_GetCellName();
};
// @fnv 0x00451cb0
// src: COMMUNITY 0x00451cb0
void FUN_00451cb0_shell::TESObjectCELL_GetCellName()
{
    ((FUN_00401280_shell*)this)->retn_empty_string();
}

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

// Gets the form type of apRef's object reference and returns true only if apRef is neither deleted nor disabled.
// @fnv 0x00451e40
bool TES::IsRefUsable(TESObjectREFR* apRef)
{
    unsigned char type = ((FNVHelper*)apRef)->_FNV_GetObjectReference()->_FNV_GetFormType();
    return !((RefH*)apRef)->IsDeleted() && !((RefH*)apRef)->GetDisabled();
}

extern int DAT_01000000;

struct FUN_00452370_shell
{
    bool TESForm_GetDestructible() const;
};

// @fnv 0x00452370
// src: XBOX_PDB 0x00452370
bool FUN_00452370_shell::TESForm_GetDestructible() const
{
    return (*(const unsigned int*)((const char*)this + 8) & (unsigned int)&DAT_01000000) ? true : false;
}

class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class NiDirectionalLight;
class NiFogProperty;
class NiGeometry;
class NiPick;
class NiTexture;
class QueuedReference;
class TESLandTexture;
class TESRegion;
class TESWaterSystem;
namespace fnv_00453940 {
struct GridCellData;
struct GridCell;
struct GridDistantArray;
struct GridLand;
struct TESFormList;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};

struct ExteriorCellReset : TES
{
    void TES_DetachGridCells();
};


extern TESDataHandler* g_dataHandler;
// If g_dataHandler is set, clears the grid cell array and calls FUN_00451570(0) and FUN_00451520(1).
// @fnv 0x00453940
// src: XBOX_PDB 0x00453940
void ExteriorCellReset::TES_DetachGridCells()
{
    if (!g_dataHandler)
        return;
    (*(GridCellArray**)((char*)this + 8))->DetachAllCells();
    BSShaderManager_SetProjectedShadowMaskTexture(0);
    GridCellArray_SetRecreateCanopyShadowMaskTexture(1);
}
}  // namespace fnv_00453940

struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 DAT_011c3c90;
struct FUN_00453980_shell
{
    int GetGlobalInt();
};
// @fnv 0x00453980
int FUN_00453980_shell::GetGlobalInt()
{
    return *DAT_011c3c90.Int();
}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};

struct FUN_00454400_shell
{
    int GetRaceListSize();
};

// @fnv 0x00454400
int FUN_00454400_shell::GetRaceListSize()
{
    return ((BSSimpleListTESRaceSize*)((char*)this + 0xac))->GetSize();
}

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
// Calls FUN_00455680, then invokes FUN_00553820 on the previous path if one exists, otherwise calls FUN_004baba0 on m8.
// @fnv 0x00455640
// src: COMMUNITY 0x00455640
void FUN_00455640_shell::TES_RunAnimations()
{
    ClearAnimationCloneCount();
    if (((CP_008c48d0*)this)->GetPrevPath())
    {
        ((FUN_00553820_shell*)((CP_008c48d0*)this)->GetPrevPath())->TESObjectCELL_RunAnimations();
    }
    else
    {
        ((FUN_004baba0_shell*)m8)->RunAnimations_004baba0();
    }
}

class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class NiDirectionalLight;
class NiFogProperty;
class NiGeometry;
class NiPick;
class NiTexture;
class QueuedReference;
class TESLandTexture;
class TESRegion;
class TESWaterSystem;
namespace fnv_00455690 {
struct GridCellData;
struct GridCell;
struct GridDistantArray;
struct GridLand;
struct TESFormList;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};

struct CellSoundUpdate : TES
{
    void TES_UpdateRefSounds();
};

struct CP_008c48d0
{
    int GetPrevPath();
};
struct S_005538e0
{
    void PlayCellSoundEffects();
};
struct CellGridSoundUpdate : GridCellArray
{
    void UpdateRefSounds_004bac20();
};
// @fnv 0x00455690
// src: COMMUNITY 0x00455690
void CellSoundUpdate::TES_UpdateRefSounds()
{
    if (((CP_008c48d0*)this)->GetPrevPath())
        ((S_005538e0*)((CP_008c48d0*)this)->GetPrevPath())->PlayCellSoundEffects();
    else
        ((CellGridSoundUpdate*)*(void**)((char*)this + 8))->UpdateRefSounds_004bac20();
}
}  // namespace fnv_00455690

class bhkWorld;
namespace fnv_00456be0 {
struct FUN_00454380_shell
{
    void bhkWorld_SetEnabled(bool);
};

struct CP_008c48d0
{
    int GetPrevPath();
};
extern int g_TES;
extern unsigned char TES_QCollisionDisableFlag();
extern void TES_SetCollisionDisableFlag(bool);
extern void bhkRagdollController_SetRagdollAnim(bool);
extern bhkWorld* __cdecl GetExteriorbhkWorld();
struct FUN_00456be0_shell
{
    void TES_ToggleCollision();
};
// @fnv 0x00456be0
// src: XBOX_PDB 0x00456be0
void FUN_00456be0_shell::TES_ToggleCollision()
{
    bool bcol = !TES_QCollisionDisableFlag();
    TES_SetCollisionDisableFlag(bcol);
    bhkWorld* pw = 0;
    TESObjectCELL* pcell = reinterpret_cast<TESObjectCELL*>(reinterpret_cast<CP_008c48d0*>(g_TES)->GetPrevPath());
    if (pcell)
        pw = reinterpret_cast<bhkWorld*>(reinterpret_cast<ExtraDataList*>(pcell)->GetRoomId());
    else
        pw = GetExteriorbhkWorld();
    if (pw)
        reinterpret_cast<FUN_00454380_shell*>(pw)->bhkWorld_SetEnabled(!bcol);
    bhkRagdollController_SetRagdollAnim(!bcol);
}
}  // namespace fnv_00456be0

namespace fnv_00456cb0 {
extern void* g_dataHandler;
struct CP_008c48d0
{
    int GetPrevPath();
};
struct CellGridLandBorders : GridCellArray
{
    void ShowLandBorders(bool);
};

// @fnv 0x00456cb0
} // namespace fnv_00456cb0
void TES::SetShowLandBorders(bool abShow)
{
    using namespace fnv_00456cb0;
    if (*(bool*)((char*)this + 0x60) != abShow)
    {
        *(bool*)((char*)this + 0x60) = abShow;
        if (!g_dataHandler || ((fnv_00456cb0::CP_008c48d0*)this)->GetPrevPath())
            return;
        (*(CellGridLandBorders**)((char*)this + 8))->ShowLandBorders(abShow);
    }
}


class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class NiDirectionalLight;
class NiFogProperty;
class NiGeometry;
class NiPick;
class NiTexture;
class QueuedReference;
class TESLandTexture;
class TESRegion;
class TESWaterSystem;
namespace fnv_00457070 {
struct GridCellData;
struct GridCell;
struct GridDistantArray;
struct GridLand;
struct TESFormList;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};


// @fnv 0x00457070
} // namespace fnv_00457070
TESObjectCELL* TES::GetDetailedActorPathHandler()
{
    using namespace fnv_00457070;
    if (IsCellInterior())
        return IsCellInterior();
    if (*(int*)((char*)this + 0x24) == 0x7fffffff || *(int*)((char*)this + 0x28) == 0x7fffffff)
        return 0;
    return ((TESCoordinateLookup*)this)->FindCell(*(int*)((char*)this + 0x24), *(int*)((char*)this + 0x28));
}
namespace fnv_00457070 {

}  // namespace fnv_00457070


struct CellSceneAccess : public TESObjectCELL
{
    NiAVObject* GetCellNodeAt(unsigned int index);
};
// @fnv 0x0045c9a0
NiAVObject* CellSceneAccess::GetCellNodeAt(unsigned int index)
{
    NiAVObject* node = ((TESObjectCELL*)this)->GetCellChildAt(2);
    return node ? ((NiNode*)node)->GetAt(index) : 0;
}

struct FUN_00557090_shell
{
    void TESObjectCELL_IsRefListLocked();
};
struct FUN_005570b0_shell
{
    void __thiscall IsSet();
};
// @fnv 0x00557090
// src: COMMUNITY 0x00557090
void FUN_00557090_shell::TESObjectCELL_IsRefListLocked()
{
    ((FUN_005570b0_shell*)((char*)this + 0x80))->IsSet();
}

// @fnv 0x00c44e40
void BSTempNode::UpdateDownwardPass(NiUpdateData& data, unsigned int flags)
{
    BSTempNodeManager_RemoveExpired(*(float*)&data);
    NiNode::UpdateDownwardPass(data, flags);
}

// @fnv 0x00c44e70
void BSTempNode::UpdateSelectedDownwardPass(NiUpdateData& data, unsigned int flags)
{
    BSTempNodeManager_RemoveExpired(*(float*)&data);
    NiNode::UpdateSelectedDownwardPass(data, flags);
}

// @fnv 0x00c44ea0
void BSTempNode::UpdateRigidDownwardPass(NiUpdateData& data, unsigned int flags)
{
    BSTempNodeManager_RemoveExpired(*(float*)&data);
    NiNode::UpdateRigidDownwardPass(data, flags);
}


// @fnv 0x004518e0
bool TESObjectCELL::IsOutdoorCell()
{
    return *((unsigned char*)this + 0x24) & 0x2;
}


namespace fnv_00451ea0 {
extern int DAT_011e0e80;

// @fnv 0x00451ea0
} // namespace fnv_00451ea0
void TES::DetachModel(TESObjectREFR* apRef)
{
    using namespace fnv_00451ea0;
    Actor* pactor;
    if (apRef->IsActor())
    {
        pactor = (Actor*)apRef;
        if (pactor)
        {
            pactor->Unk_98();
            ((ProcessLists*)&DAT_011e0e80)->RemoveMobileObjectFromList(pactor);
        }
    }
}


struct FUN_00452390_shell
{
    char _pad[0xaa];
    unsigned short _0xaa;
    void TESObjectCELL_IncLoadedRefsWithVisibleDistantCount();
};

// Increments the unsigned short field at offset 0xaa of this object.
// @fnv 0x00452390
// src: XBOX_PDB 0x00452390
void FUN_00452390_shell::TESObjectCELL_IncLoadedRefsWithVisibleDistantCount()
{
    _0xaa++;
}

struct Holder4523e0
{
    char _pad[0x64];
    FUN_00452420_shell* pLoaded;
    bool TESObjectREFR_GetLoadedDataFlag(unsigned int aiFlag);
};
// Returns the loaded object's flag for aiFlag when pLoaded is set, otherwise false.
// @fnv 0x004523e0
// src: XBOX_PDB 0x004523e0
bool Holder4523e0::TESObjectREFR_GetLoadedDataFlag(unsigned int aiFlag)
{
    return pLoaded ? pLoaded->GetFlag(aiFlag) : false;
}

namespace fnv_00454bd0 {
struct CellStand
{
    int GetCellStandValue();
};
struct GlobalObject_0045cfe0 : CellStand
{
};
extern GlobalObject_0045cfe0 g_011c3e38;

// @fnv 0x00454bd0
} // namespace fnv_00454bd0
bool TES::ContainsCell(TESObjectCELL* apCell)
{
    using namespace fnv_00454bd0;
    unsigned int n = 0;
    for (; n < g_011c3e38.GetCellStandValue(); n++)
    {
        if ((*(TESObjectCELL***)((char*)this + 0x38))[n] == apCell)
            return true;
    }
    return false;
}


namespace fnv_00454e20 {
struct CellStand
{
    char _pad[60];
    void** _arr;
    int GetCellStandValue();
    bool TES_IsExteriorBuffered(void*);
};
extern CellStand DAT_011c3c90;
// @fnv 0x00454e20
// src: XBOX_PDB 0x00454e20
bool CellStand::TES_IsExteriorBuffered(void* pElement)
{
    for (unsigned int i = 0; i < (unsigned int)DAT_011c3c90.GetCellStandValue(); ++i)
    {
        if (_arr[i] == pElement)
            return true;
    }
    return false;
}
}  // namespace fnv_00454e20

// @fnv 0x00458ef0
BSTempNode::BSTempNode(float value) : NiNode(0)
{
    fTime = value;
}

namespace fnv_00459000 {
struct LeveledActorEntry
{
    TESActorBase* m_pActorBaseFormItem;
    short m_sLevel;
};
struct FakeList
{
    LeveledActorEntry** _ref_006815c0();
    FakeList* _ref_00726070();
};

// Searches the list for an entry whose TESActorBase pointer matches apObject and returns its short value, or 0 if not found.
// @fnv 0x00459000
} // namespace fnv_00459000
short TES::FindActorBaseValue(TESActorBase* apObject)
{
    fnv_00459000::FakeList* pCurrentElementNext = (fnv_00459000::FakeList*)((char*)this + 0x9c);
    while (pCurrentElementNext != 0 && *pCurrentElementNext->_ref_006815c0() != 0)
    {
        fnv_00459000::LeveledActorEntry* pEntry = *pCurrentElementNext->_ref_006815c0();
        if ((void*)pEntry->m_pActorBaseFormItem == apObject)
            return pEntry->m_sLevel;
        pCurrentElementNext = pCurrentElementNext->_ref_00726070();
    }
    return 0;
}


struct FUN_0045aee0_shell
{
    char pad_0045aee0[0xb5];
    char m_0045aee0_b5;  // at offset 0xb5
    void SetByteB5(char v);
};

// @fnv 0x0045aee0
void FUN_0045aee0_shell::SetByteB5(char acValue)
{
    m_0045aee0_b5 = acValue;
}

namespace fnv_00628da0 {


// Clears _pad_2, sets all six entries of arr to null, and calls RemoveAll on map.
// @fnv 0x00628da0
struct LoadedAreaBoundReset : LoadedAreaBound
{
    void Reset();
};
void LoadedAreaBoundReset::Reset()
{
    *(int*)((char*)this + 0x20) = 0;
    for (int i = 0; i < 6; ++i)
    {
        *(NP*)((char*)this + 8 + i * 4) = (void*)0;
    }
    ((NiTPointerMap<void*, void*>*)((char*)this + 0x24))->RemoveAll();
}
}  // namespace fnv_00628da0


struct CellOutdoorQuery : TESObjectCELL
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
extern TESDataHandler* g_dataHandler;
extern GlobalObject_0045cfe0 g_011c63cc;

struct ExteriorBufferPromoter : TES
{
    void MoveCellToFront(TESObjectCELL*);
};

// Moves apCell to the front of the cell list, shifting entries, and unloads the displaced cell via g_dataHandler if one remains.
// @fnv 0x00454e70
void ExteriorBufferPromoter::MoveCellToFront(TESObjectCELL* apCell)
{
    TESObjectCELL* pmoveCell;
    UpdateExteriorCellBuffer();
    bool bvisible = ((CellOutdoorQuery*)apCell)->IsOutdoorCell() || ((SaveLoadStateQuery*)apCell)->TESObjectCELL_GetAttaching();
    if (!(*(TESObjectCELL***)((char*)this + 0x3c))[*g_011c63cc.Int() * *g_011c63cc.Int() - 1])
        bvisible = true;
    pmoveCell = apCell;
    unsigned int n;
    TESObjectCELL* ptempCell;
    for (n = (!bvisible && (unsigned int)((CellStand*)&DAT_011c3c90)->GetCellStandValue() >
                               (unsigned int)(*g_011c63cc.Int() * *g_011c63cc.Int()))
                 ? *g_011c63cc.Int() * *g_011c63cc.Int()
                 : 0;
         n < (unsigned int)((CellStand*)&DAT_011c3c90)->GetCellStandValue(); n++)
    {
        ptempCell = (*(TESObjectCELL***)((char*)this + 0x3c))[n];
        (*(TESObjectCELL***)((char*)this + 0x3c))[n] = pmoveCell;
        if (ptempCell == apCell)
            return;
        pmoveCell = ptempCell;
    }
    if (pmoveCell)
    {
        g_dataHandler->RemoveCell(pmoveCell);
        ((FUN_00452e50_class*)this)->TES_SetUpdateGridString();
    }
}


struct WorldSpaceQuery : TES
{
    TESWorldSpace* GetHitSound();
};
struct WorldGridCellQuery : TESWorldSpace
{
    TESObjectCELL* TESWorldSpace_LoadCell(int, int);
};
struct WorldCellRegistration : TESWorldSpace
{
    void AddCellReferences(TESObjectCELL*);
};
struct CellReferenceInit : TESObjectCELL
{
    void TESObjectCELL_SetHasTempData(bool);
};
struct ExteriorGridOccupancy : GridCellArray
{
    bool IsOutdoorCell(unsigned int, unsigned int);
};
struct ExteriorGridAssignment : GridCellArray
{
    void SetCellAt(unsigned int, unsigned int, TESObjectCELL*);
};
struct ExteriorGridAttachment : GridCellArray
{
    void AttachToWorld(NiNode*, unsigned int, unsigned int);
};
struct S454b90
{
    void AddCellToBuffer(TESObjectCELL*);
};


struct CellDisplayNameQuery : TESObjectCELL
{
    const char* TESObjectCELL_GetCellName();
};

struct LAND_x
{
    bool TESObjectLAND_LoadVertices(bool);
    void TESObjectLAND_UpdateMesh(int, int);
    void TESObjectLAND_GetMinMaxLandHeight(NiPoint2*);
    void TESObjectLAND_DrawLandBorder(bool);
};
float __fastcall TESObjectCELL_GetWaterHeight(void*);
struct CellWaterFlagUpdate : TESObjectCELL
{
    void SetFlag2(bool);
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011c7adc;
struct CellFlagQuery : TESObjectCELL
{
    unsigned char TESClimate_GetVolatilityIndex();
};
void __cdecl BGSAutoWater_GeneratePlaceableWaterForCell(TESObjectCELL*);
int _sprintf(char*, const char*, ...);

struct ExteriorGridLoader : TES
{
    void TES_LoadGridCell(int, int, int, int);
};

// @fnv 0x00451a50
// src: COMMUNITY 0x00451a50
void ExteriorGridLoader::TES_LoadGridCell(int aiGridX, int aiGridY, int aiCellX, int aiCellY)
{
    if (!((WorldSpaceQuery*)this)->GetHitSound())
        return;
    TESObjectCELL* pcell = 0;
    float extents[2];
    TESObjectLAND* pLand;
    char pmessage[260];
    pcell = ((WorldGridCellQuery*)((WorldSpaceQuery*)this)->GetHitSound())->TESWorldSpace_LoadCell(aiCellX, aiCellY);
    if (!pcell)
    {
        pcell = g_dataHandler->GetCellAtGridPosition(
            aiCellX, aiCellY, ((WorldSpaceQuery*)this)->GetHitSound(), true);
        ((WorldCellRegistration*)((WorldSpaceQuery*)this)->GetHitSound())->AddCellReferences(pcell);
        ((CellReferenceInit*)pcell)->TESObjectCELL_SetHasTempData(true);
    }
    if (((ExteriorGridOccupancy*)(*(void**)((char*)this + 0x8)))->IsOutdoorCell(aiGridX, aiGridY))
    {
        ((S454b90*)this)->AddCellToBuffer(pcell);
        return;
    }
    _sprintf(pmessage, "Loading cell...%s (%i, %i) (%08X)", ((CellDisplayNameQuery*)pcell)->TESObjectCELL_GetCellName(),
             ((TESObjectCELL*)pcell)->GetCellGridX(), ((TESObjectCELL*)pcell)->GetCellGridY(), ((TESForm*)pcell)->GetFormID());
    ((ExteriorGridAssignment*)(*(void**)((char*)this + 0x8)))->SetCellAt(aiGridX, aiGridY, pcell);
    ((ExteriorGridAttachment*)(*(void**)((char*)this + 0x8)))->AttachToWorld((*(NiNode**)((char*)this + 0xc)), aiGridX, aiGridY);
    pLand = ((TESObjectCELL*)pcell)->GetLandscape();
    if (!((LAND_x*)pLand)->TESObjectLAND_LoadVertices(true))
        ((LAND_x*)pLand)->TESObjectLAND_UpdateMesh(0, 0);
    ((LAND_x*)((TESObjectCELL*)pcell)->GetLandscape())->TESObjectLAND_GetMinMaxLandHeight((NiPoint2*)extents);
    ((CellWaterFlagUpdate*)pcell)->SetFlag2(TESObjectCELL_GetWaterHeight(pcell) > extents[0]);
    if (*g_011c7adc.Bool() && ((TESObjectCELL*)pcell)->HasWater() && !((CellFlagQuery*)pcell)->TESClimate_GetVolatilityIndex())
        BGSAutoWater_GeneratePlaceableWaterForCell(pcell);
    ((LAND_x*)pLand)->TESObjectLAND_DrawLandBorder((*(bool*)((char*)this + 0x60)));
}


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

// Advances the global time, updates wind and cell/grid state, runs queued tasks and the sky, then processes the listener and DAT_011e0e80.
// @fnv 0x00453550
// src: XBOX_PDB 0x00453550
void Zt5TES::TES_UpdateCellAnimations(float afTime)
{
    Zt5Cell* pcell = (Zt5Cell*)((CP_008c48d0*)this)->GetPrevPath();
    if (pcell)
    {
        BSWindModifier_SetWind(0, 0);
        bhkWindListener_SetWind(0, 0);
    }
    else
    {
        float fwindSpeed = pWeatherSky->GetFieldCC();
        float fwindAngle = ((Animation*)pWeatherSky)->FUN_00453700();
        BSWindModifier_SetWind(fwindSpeed, fwindAngle);
        bhkWindListener_SetWind(fwindSpeed, fwindAngle);
    }
    DAT_011c3c08 += afTime;
    TES_LockHavokUpdateMT(true);
    if (pcell)
        pcell->TESObjectCELL_UpdateManagedNodes(DAT_011c3c08, false);
    else
        m_pGridCells->UpdateCellGrid(DAT_011c3c08);
    TES_LockHavokUpdateMT(false);
    if (*g_011c3ea4.Int() > 1)
    {
        TaskQueueInterface* pTaskQueue = TaskQueueInterface::GetInstance();
        ((FUN_0087aa90_shell*)pTaskQueue)->TaskQueueInterface_QueueParallelTaskProcessing();
    }
    FOCollisionListener_GetSingleton()->ProcessRequests();
    if (*g_011c3ea4.Int() == 1)
        pWeatherSky->Update(DialogH::IsInDialog() ? g_timeGlobal.GetStoredFloatValue() * *g_011c5724.Float() : afTime);
    if (*g_011c3ea4.Int() == 1)
        TES_UpdateCellMainThread();
    ProcessLists_PostProcessProjectiles((char*)&DAT_011e0e80);
}


// Calls the object's virtual method and maps its returned type code to 3, 2, or 1 depending on which case group it falls into.
// @fnv 0x0045c6b0
// src: XBOX_PDB 0x0045c6b0
int TES_GetLODMult(TESForm* apObj)
{
    int iResult = 0;
    switch (apObj->FNV_GetFormType())
    {
    case 0x2a:
    case 0x2b:
        iResult = 3;
        break;
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1f:
    case 0x28:
    case 0x29:
    case 0x2e:
    case 0x2f:
    case 0x32:
    case 0x67:
    case 0x6c:
    case 0x73:
    case 0x74:
        iResult = 2;
        break;
    default:
        iResult = 1;
        break;
    }
    return iResult;
}

struct FUN_00453490_shell
{
    bool ContainsCell(TESObjectCELL*);
    bool TES_IsExteriorBuffered(TESObjectCELL*);
    bool TES_IsBuffered(TESObjectCELL* cell);
};
// Returns false for a null cell, otherwise dispatches to ContainsCell for interior cells or FUN_00454e20 for exterior cells.
// @fnv 0x00453490
// src: XBOX_PDB 0x00453490
bool FUN_00453490_shell::TES_IsBuffered(TESObjectCELL* cell)
{
    return cell ? ((bool)(unsigned char)(cell->IsInterior() ? ContainsCell(cell) : TES_IsExteriorBuffered(cell))) : false;
}

struct SkyModeAccess : Sky
{
    int Sky_GetMode();
    void SetMode(int mode);
};
struct CellSkyAccess : TESObjectCELL
{
    bool FUN_00454b10();
};
struct CellAtmosphereUpdate : TES
{
    SkyModeAccess* GetLogDate();
    void UpdateSkyModeForCell(TESObjectCELL*);
};
// @fnv 0x00455400
void CellAtmosphereUpdate::UpdateSkyModeForCell(TESObjectCELL* apCell)
{
    if (!GetLogDate()->Sky_GetMode())
        return;
    if (apCell)
    {
        if (((CellSkyAccess*)apCell)->IsInterior())
        {
            if (((CellSkyAccess*)apCell)->FUN_00454b10())
                GetLogDate()->SetMode(2);
            else
                GetLogDate()->SetMode(1);
        }
        else
            GetLogDate()->SetMode(3);
    }
    else
        GetLogDate()->SetMode(3);
}


struct ParticleCacheEntry : GO
{
    ParticleCacheEntry();
};
// Initializes the object by assigning 0 to the base GO and setting mObject2 and mObject3 to 0.
// @fnv 0x0045ab30
ParticleCacheEntry::ParticleCacheEntry() : GO(0)
{
    ((GO*)this)->operator=((void*)0);
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
}


struct FUN_00b5ddb0_self
{
    void FUN_00b5ddb0(bool, bool);
};
struct CellExt
{
    bool IsOutdoorCell();
    void TESObjectCELL_AttachLights(bool);
};
struct CellCollisionUpdate : TES
{
    void TES_UpdateGridLights();
};
// @fnv 0x00451cf0
// src: COMMUNITY 0x00451cf0
void CellCollisionUpdate::TES_UpdateGridLights()
{
    for (unsigned int x = 0; x < *g_011c63cc.Int(); x++)
    {
        for (unsigned int y = 0; y < *g_011c63cc.Int(); y++)
        {
            CellExt* cell = (CellExt*)*(void**)(*(GridCellArray**)((char*)this + 0x8))->Get(x, y);
            if (cell && cell->IsOutdoorCell())
                cell->TESObjectCELL_AttachLights(true);
        }
    }
    ((FUN_00b5ddb0_self*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))->FUN_00b5ddb0(true, true);
}

struct LLD_Cell;

// Converts cell coordinates to grid indices, returns the grid cell if in range, otherwise falls back to the data handler lookup.
// @fnv 0x00451900
TESObjectCELL* TESCoordinateLookup::FindCell(int aiCellX, int aiCellY)
{
    TESObjectCELL* pcell;
    int igridX;
    int igridY;

    igridX = aiCellX - (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x24) -
                        (static_cast<unsigned int>(*g_011c63cc.Int()) >> 1));
    igridY = aiCellY - (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x28) -
                        (static_cast<unsigned int>(*g_011c63cc.Int()) >> 1));
    pcell = 0;

    if (static_cast<unsigned int>(igridX) < static_cast<unsigned int>(*g_011c63cc.Int()) &&
        static_cast<unsigned int>(igridY) < static_cast<unsigned int>(*g_011c63cc.Int()) && igridX >= 0 && igridY >= 0)
    {
        pcell = *reinterpret_cast<TESObjectCELL**>(
            reinterpret_cast<GridCellArray*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x08))
                ->Get(static_cast<unsigned int>(igridX), static_cast<unsigned int>(igridY)));
    }

    if (pcell == 0 && reinterpret_cast<TES*>(this)->GetParentWorldSpace() != 0)
    {
        pcell = g_dataHandler->GetCellAtGridPosition(
            aiCellX, aiCellY,
            reinterpret_cast<TESWorldSpace*>(reinterpret_cast<TES*>(this)->GetParentWorldSpace()), false);
    }

    return pcell;
}

namespace fnv_00452ed0 {
struct GridCell
{
    TESObjectCELL* pCell;
};

extern int g_TES;


// @fnv 0x00452ed0
} // namespace fnv_00452ed0
bool TES::IsCellBuffering()
{
    using namespace fnv_00452ed0;
    using fnv_00452ed0::GridCell;
    int pgc;
    int ix;
    int icellY;
    unsigned int iy;
    GridCell* pcell;
    TESObjectCELL* icellX;

    if (!reinterpret_cast<TES*>(g_TES)->GetParentWorldSpace())
        return false;

    pgc = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x24) -
          (static_cast<unsigned int>(*g_011c63cc.Int()) >> 1);
    ix = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x28) -
         (static_cast<unsigned int>(*g_011c63cc.Int()) >> 1);

    for (icellY = 0; static_cast<unsigned int>(icellY) < static_cast<unsigned int>(*g_011c63cc.Int()); ++icellY)
    {
        for (iy = 0; iy < static_cast<unsigned int>(*g_011c63cc.Int()); ++iy)
        {
            pcell = reinterpret_cast<GridCell*>((*reinterpret_cast<GridCellArray**>(reinterpret_cast<char*>(this) + 8))
                                               ->Get(static_cast<unsigned int>(icellY), iy));

            if (pcell)
            {
                icellX = pcell->pCell;
                if (!icellX)
                {
                    icellX = reinterpret_cast<TES*>(g_TES)->GetParentWorldSpace()->GetCellAtGridPosition(
                        pgc + static_cast<unsigned int>(icellY), ix + static_cast<unsigned int>(iy));
                }

                if (!icellX || !reinterpret_cast<FUN_00453490_shell*>(this)->TES_IsExteriorBuffered(icellX))
                    return false;
            }
        }
    }

    return true;
}
namespace fnv_00452ed0 {

}  // namespace fnv_00452ed0

void* __cdecl _FUN_00ec7230(void*, void*, unsigned int);


// @fnv 0x00454fc0
void TES::UpdateExteriorCellBuffer()
{
    unsigned int iattachedCount;
    unsigned int ilastNonQueuedPos;
    int ihalfgrid;

    if ((*(int*)((char*)this + 0x24)) == (*(int*)((char*)this + 0x2c)) && (*(int*)((char*)this + 0x30)) == (*(int*)((char*)this + 0x30)))
        return;

    iattachedCount = *g_011c63cc.Int() * *g_011c63cc.Int();
    ihalfgrid = static_cast<unsigned int>(*g_011c63cc.Int()) >> 1;
    ilastNonQueuedPos = 0;

    {
        unsigned int i;
        int icellX;
        TESObjectCELL* pcell;
        bool bqueuedArea;
        int ideltaY;
        int icellY;
        int ideltaX;

        for (i = iattachedCount; i < *DAT_011c3c90.Int() - 1; ++i)
        {
            pcell = (*(TESObjectCELL***)((char*)this + 0x3c))[i];
            if (!pcell)
                break;

            icellX = reinterpret_cast<TESObjectCELL*>(pcell)->GetCellGridX();
            icellY = reinterpret_cast<TESObjectCELL*>(pcell)->GetCellGridY();
            ideltaX = (*(int*)((char*)this + 0x2c)) - icellX;
            ideltaY = (*(int*)((char*)this + 0x30)) - icellY;
            bqueuedArea = false;

            if (ideltaX >= -ihalfgrid)
            {
                if (ideltaX <= ihalfgrid)
                {
                    if (ideltaY >= -ihalfgrid)
                    {
                        if (ideltaY <= ihalfgrid)
                            bqueuedArea = true;
                    }
                }
            }

            if (bqueuedArea && ilastNonQueuedPos != 0)
            {
                _FUN_00ec7230(&(*(TESObjectCELL***)((char*)this + 0x3c))[ilastNonQueuedPos + 1], &(*(TESObjectCELL***)((char*)this + 0x3c))[ilastNonQueuedPos],
                              (i - ilastNonQueuedPos) * 4);
                (*(TESObjectCELL***)((char*)this + 0x3c))[ilastNonQueuedPos] = pcell;
                i = ilastNonQueuedPos + 1;
                ilastNonQueuedPos = 0;
            }
            else
            {
                ilastNonQueuedPos = i;
            }
        }
    }
}

struct TemporarySceneGraph : SceneGraph
{
    void AttachTemporaryNode(NiAVObject*, float);
};
// @fnv 0x00458e20
void TemporarySceneGraph::AttachTemporaryNode(NiAVObject* apObject, float afTime)
{
    if (apObject)
    {
        BSTempNode* pTempNode = new BSTempNode(afTime);
        pTempNode->AttachChildInAvailableSlot(apObject, true);
        ((NiNode*)GetCamera())->AttachChildInAvailableSlot((NiAVObject*)pTempNode, true);
        pTempNode->UpdateSceneObject();
    }
}
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

// Walks the list at this+0x9c for an item with the given key, adds value to it if found, otherwise allocates a new item and adds it to the head.
// @fnv 0x00459060
void FUN_00459060_shell::AddOrAccumulateItem(unsigned int key, short sValue)
{
    G2* node = reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x9c);

    while (node && *node->_ref_006815c0())
    {
        FUN_00459060_item* item = reinterpret_cast<FUN_00459060_item*>(*node->_ref_006815c0());

        if (item->key == key)
        {
            item->value += sValue;
            return;
        }

        node = reinterpret_cast<G2*>(node->_ref_00726070());
    }

    FUN_00459060_item* item = new FUN_00459060_item;
    item->key = key;
    item->value = sValue;

    reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x9c)->AddHead(reinterpret_cast<int*>(&item));
}

namespace fnv_00459d20 {
// Exe 0x00459d20: unit-local Interface view; declarations and layout are preserved.
struct TesInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};

struct CellLoadIOManager : IOManager
{
    void WaitForCellLoad();
};


struct Calendar
{
    void Update(float);
};

struct LLD_Cell
{
};

struct LLD_PlayerCharacter
{
    void PlayerCharacter_CenterOnCell(int, LLD_Cell*);
};

struct SaveManager
{
    void FUN_00861f20(unsigned int);
};


struct FUN_00459d20_shell
{
    void MoveToCell(TESObjectCELL*, unsigned int, unsigned int);
};

unsigned int __cdecl gm_GetTickCount();
void __fastcall ProcessLists_UpdateProcessLists(void*);
void __fastcall ProcessLists_ChangeProcessLevelTempList(void*);

extern IOManager* DAT_01202d98;
extern Calendar DAT_011de7b8;
extern SaveManager* DAT_011de45c;
extern LLD_PlayerCharacter* _g_thePlayer;
extern float runtimeFloatSettingDefault175;

// Logs the target cell, moves the player into it, times the load, updates the calendar and handles save options.
// @fnv 0x00459d20
void FUN_00459d20_shell::MoveToCell(TESObjectCELL* apCell, unsigned int aiOptions, unsigned int aiTestStartTime)
{
    unsigned int itime;
    unsigned int inumSeconds;
    unsigned int icenterOnCellStartTime;
    unsigned int icenterOnCellStopTime;
    unsigned int inumMinutes;
    unsigned int inumHours;

    if (apCell)
    {
        if (apCell->IsInterior())
        {
            TesInterfaceView::PrintDebugMessage(
                "Moving to interior cell %08X %s", reinterpret_cast<TESForm*>(apCell)->GetFormID(),
                reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(apCell) + 0x18)->GetFullName());
        }
        else
        {
            TesInterfaceView::PrintDebugMessage(
                "Moving to exterior cell %08X (%i,%i) %s",
                reinterpret_cast<TESForm*>(apCell)->GetFormID(),
                reinterpret_cast<TESObjectCELL*>(apCell)->GetCellGridX(), reinterpret_cast<TESObjectCELL*>(apCell)->GetCellGridY(),
                reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(apCell) + 0x18)->GetFullName());
        }

        icenterOnCellStartTime = gm_GetTickCount();
        _g_thePlayer->PlayerCharacter_CenterOnCell(0, reinterpret_cast<LLD_Cell*>(apCell));
        ((CellLoadIOManager*)DAT_01202d98)->WaitForCellLoad();
        icenterOnCellStopTime = gm_GetTickCount();

        itime = gm_GetTickCount() - aiTestStartTime;
        inumHours = itime / 3600000;
        itime = itime - inumHours * 3600000;
        inumMinutes = itime / 60000;
        itime = itime - inumMinutes * 60000;
        inumSeconds = itime / 1000;

        if (apCell->IsInterior())
        {
            TesInterfaceView::PrintDebugMessage(
                "Interior cell finished loading in %.02f seconds.  Total test time: %02i:%02i:%02i",
                (icenterOnCellStopTime - icenterOnCellStartTime) / 1000.0, inumHours, inumMinutes, inumSeconds);
        }
        else
        {
            TesInterfaceView::PrintDebugMessage(
                "Exterior cell (%i,%i) finished loading in %.02f seconds.  Total test time: %02i:%02i:%02i",
                reinterpret_cast<TESObjectCELL*>(apCell)->GetCellGridX(), reinterpret_cast<TESObjectCELL*>(apCell)->GetCellGridY(),
                (icenterOnCellStopTime - icenterOnCellStartTime) / 1000.0, inumHours, inumMinutes, inumSeconds);
        }

        DAT_011de7b8.Update(runtimeFloatSettingDefault175);
        ProcessLists_ChangeProcessLevelTempList(&DAT_011e0e80);
        ProcessLists_UpdateProcessLists(&DAT_011e0e80);
        ProcessLists_ChangeProcessLevelTempList(&DAT_011e0e80);

        switch (aiOptions)
        {
        case 4:
        case 5:
            DAT_011de45c->FUN_00861f20(aiOptions);
            break;
        }
    }
}
}  // namespace fnv_00459d20


struct FUN_0045c780_shell
{
    unsigned char unknown_0045c780[8];
    TESForm* sound;

    void InitSoundGrid();
    void TES_SetHideLandBlendPassForGridCell(unsigned int index1, unsigned int index2, unsigned char value);
};

extern bool DAT_011c3c0c;
extern const unsigned char DAT_01017830[5][5];

// @fnv 0x0045c780
void FUN_0045c780_shell::InitSoundGrid()
{
    if (*g_011c63cc.Int() == 5)
    {
        unsigned int index1;
        for (index1 = 0; index1 < this->sound->GetFormID(); ++index1)
        {
            unsigned int index2;
            for (index2 = 0; index2 < this->sound->GetFormID(); ++index2)
            {
                unsigned char value = 0;
                if (DAT_011c3c0c)
                {
                    if (index1 == 2 && index2 == 2)
                        value = 1;
                }
                else
                {
                    value = DAT_01017830[index1][index2];
                }

                this->TES_SetHideLandBlendPassForGridCell(index1, index2, value);
            }
        }
    }
}

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

// @fnv 0x0045c840
void FUN_0045c840_shell::InitFromMatrix()
{
    if (*g_011c63cc.Int() == 5)
    {
        for (unsigned int index1 = 0; index1 < _ref_0084e3a0(this->field_08); ++index1)
        {
            for (unsigned int index2 = 0; index2 < _ref_0084e3a0(this->field_08); ++index2)
            {
                unsigned char value = DAT_0101784c[index1 * 5 + index2];
                this->TES_SetSkipNormalMapsForGridCell(index1, index2, value);
            }
        }
    }
}


struct LandscapeHeightQuery : TES
{
    TESObjectCELL* FUN_00451900(int, int);
    bool GetLandHeightAt(const NiPoint3&, float&);
};


int _TruncateFloatToInt(float value);
extern float DAT_01017824;
extern int g_TES;


// @fnv 0x004572e0
bool LandscapeHeightQuery::GetLandHeightAt(const NiPoint3& coord, float& height)
{
    int icellX = _TruncateFloatToInt(coord.x);
    int icellY = _TruncateFloatToInt(coord.y);

    if (icellX % 4096 == 0 && coord.x < icellX)
        --icellX;

    if (icellY % 4096 == 0 && coord.y < icellY)
        --icellY;

    icellX >>= 12;
    icellY >>= 12;

    height = DAT_01017824;

    TESObjectCELL* ptestcell = this->FUN_00451900(icellX, icellY);
    if (ptestcell && ((TES*)g_TES)->IsCellBuffered(ptestcell, false))
        return ((TESObjectCELL*)ptestcell)->GetLandscape()->GetLandHeightAtPosition(coord, height);

    return false;
}


// Writes four fixed-point bounds around m_24/m_28 expanded by half of g_011c63cc, offset by f.
// @fnv 0x00451020
void TES::GetLoadedAreaBounds(tagRECT* out, float f)
{
    int iMinX = (*(int*)((char*)this + 0x24)) - (int)((unsigned int)*g_011c63cc.Int() >> 1);
    int cellY = (*(int*)((char*)this + 0x28)) - (int)((unsigned int)*g_011c63cc.Int() >> 1);
    int iMaxX = (*(int*)((char*)this + 0x24)) + (int)((unsigned int)*g_011c63cc.Int() >> 1);
    int top = (*(int*)((char*)this + 0x28)) + (int)((unsigned int)*g_011c63cc.Int() >> 1);

    ((int*)out)[0] = (int)((float)(iMinX << 12) + f);
    ((int*)out)[3] = (int)((float)(cellY << 12) + f);
    ((int*)out)[2] = (int)((float)((iMaxX << 12) + 0x1000) - f);
    ((int*)out)[1] = (int)((float)((top << 12) + 0x1000) - f);
}

int __fastcall GetByteAtOffset38(void*);


// Returns true if pObj is non-null and its state from GetByteAtOffset38 is 5 or 6, or is 2-4 when bFlag is zero.
// @fnv 0x004511e0
bool TES::IsCellBuffered(TESObjectCELL* pObj, bool bFlag)
{
    if (pObj == 0)
    {
        return false;
    }
    switch (GetByteAtOffset38(pObj))
    {
    case 2:
    case 3:
    case 4:
        if (bFlag == 0)
        {
            return true;
        }
        break;
    case 5:
    case 6:
        return true;
    }
    return false;
}

// Clear an actor's pending state: if it is flagged, has a current process target and is active,
// notify the target's owner, then reset two state flags.


// TESObjectREFR scene operations: 0x00564e60/0x00570f70/0x00565210 lack shared declarations; slot 0x74 is GetNiNode, not an Actor process.
class ReferenceSceneStateAccess : public TESObjectREFR
{
  public:
    bool IsFlagged();
    void SetPending(int iValue);
    void SetActive(bool bActive);
};

class ActorStateHandler
{
  public:
    void TES_CleanTemp3D(ReferenceSceneStateAccess* pActor);
};

// Detaches a flagged reference's scene node from its parent, then clears its 3D and active state.
// @fnv 0x00451da0
// src: XBOX_PDB 0x00451da0
void ActorStateHandler::TES_CleanTemp3D(ReferenceSceneStateAccess* pActor)
{
    if (pActor->IsFlagged() && pActor->GetNiNode() && pActor->TESObjectREFR_HasTemp3D())
    {
        NiNode* pOwner = pActor->GetNiNode()->GetParent();
        if (pOwner)
            pOwner->RemoveObject(pActor->GetNiNode());
        pActor->SetPending(0);
        pActor->SetActive(false);
    }
}

extern "C" int __fastcall FUN_004503f0(void*);
extern "C" unsigned char __fastcall TESObjectCELL_GetAttached(void*);

struct TESBuffer45130 : Zt5TES
{
    void TES_MoveToEndOfExteriorBuffer(TESObjectCELL* apCell);
};

// @fnv 0x00455130
// src: XBOX_PDB 0x00455130
void TESBuffer45130::TES_MoveToEndOfExteriorBuffer(TESObjectCELL* apCell)
{
    if (apCell == 0)
        return;

    int index = 0;
    int last = FUN_004503f0(&DAT_011c3c90) - 1;
    for (; index < last; ++index)
    {
        if (apCell == ((TESObjectCELL**)m_ppCellBufferB)[index])
        {
            TESObjectCELL* nextCell;
            for (; index < last; ++index)
            {
                nextCell = ((TESObjectCELL**)m_ppCellBufferB)[index + 1];
                if (!(nextCell != 0 && TESObjectCELL_GetAttached(nextCell)))
                    break;
                ((TESObjectCELL**)m_ppCellBufferB)[index] = nextCell;
            }
            ((TESObjectCELL**)m_ppCellBufferB)[index] = apCell;
            return;
        }
        else
        {
            if (((TESObjectCELL**)m_ppCellBufferB)[index] == 0)
                return;
        }
    }
}

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

// @fnv 0x00455200
// src: XBOX_PDB 0x00455200
unsigned int TES_ExteriorBuffer::TES_FreeExteriorBuffer(bool abSkipLoaded, TESWorldSpace* apWorld)
{
    unsigned int ItemUpdateArray = 0;
    for (unsigned int i = 0; i < ((BufferSizeSetting*)&DAT_011c3c90)->GetUInt(); i++)
    {
        if (m_ppCellBufferB[i])
        {
            if (!abSkipLoaded || !IsCellBuffered(m_ppCellBufferB[i], true))
            {
                if (!m_ppCellBufferB[i]->GetCellStandValue())
                {
                    if (apWorld && m_ppCellBufferB[i]->GetParentWorldSpace() != apWorld)
                        continue;
                    g_dataHandler->RemoveCell(m_ppCellBufferB[i]);
                    m_ppCellBufferB[i] = 0;
                    ItemUpdateArray++;
                }
            }
        }
    }
    if (!m_ppCellBufferB[0] && GetParentWorldSpace() && GetParentWorldSpace()->GetMapData())
        GetParentWorldSpace()->GetMapData()->Reset();
    return ItemUpdateArray;
}

struct FUN_0043d4d0_cls
{
    unsigned int* Setting_Int();
};
extern FUN_0043d4d0_cls DAT_011c3e38;
extern TESDataHandler* DAT_011c3f2c;

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

// @fnv 0x00455330
void FUN_00455330_cls::RemoveEntry(unsigned int value)
{
    unsigned int i;
    for (i = 0; i < *DAT_011c3e38.Setting_Int(); i++)
    {
        if (value == m_38[i])
        {
            DAT_011c3f2c->RemoveCell(reinterpret_cast<TESObjectCELL*>(value));
            m_38[i] = 0;
            break;
        }
    }
    for (; i < *DAT_011c3e38.Setting_Int() - 1; i++)
    {
        m_38[i] = m_38[i + 1];
    }
    m_38[*DAT_011c3e38.Setting_Int() - 1] = 0;
    reinterpret_cast<FUN_00452e50_class*>(this)->TES_SetUpdateGridString();
}

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
// @fnv 0x00456800
// src: COMMUNITY 0x00456800
bool LookupHandler::TES_FreeTexture(void* object, unsigned int limit)
{
    LookupResult result(0);
    FindTextureByPath(object, &result);
    if (result.Modelloader_GetReferencedThis() != 0)
    {
        if (result.Modelloader_GetReferencedThis()->FUN_00726070() <= limit + 2)
        {
            BSTexturePalette_RemoveTexture(result.Modelloader_GetReferencedThis());
            return true;
        }
    }
    return false;
}

struct FUN_004570d0_node;

struct InteriorCellQuery : TES
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

extern InteriorCellQuery* DAT_011dea10;
extern FUN_004570d0_lst DAT_011c63cc;

struct CellObjectQuery : TES
{
    FUN_004570d0_node** GetGridCell_00457050(unsigned int i, unsigned int j);
    bool TES_PickWaterOnly(void* a1, int a2, int a3, float f);
};

// If a1 is non-null, forwards it to the manager's node or, failing that, to every node in the grid, returning whether any call succeeded.
// @fnv 0x004570d0
// src: COMMUNITY 0x004570d0
bool CellObjectQuery::TES_PickWaterOnly(void* a1, int aiArg2, int aiArg3, float afValue)
{
    bool result = false;
    if (a1 != 0)
    {
        if (DAT_011dea10->FUN_005f36f0() != 0)
        {
            result = DAT_011dea10->FUN_005f36f0()->TESObjectCELL_PickWater(a1, aiArg2, aiArg3, afValue);
        }
        else
        {
            for (unsigned int i = 0; i < *DAT_011c63cc.Setting_Int(); i++)
            {
                for (unsigned int j = 0; j < *DAT_011c63cc.Setting_Int(); j++)
                {
                    FUN_004570d0_node* n = *this->GetGridCell_00457050(i, j);
                    if (n != 0)
                    {
                        if (n->TESObjectCELL_PickWater(a1, aiArg2, aiArg3, afValue))
                        {
                            result = true;
                        }
                    }
                }
            }
        }
    }
    return result;
}

namespace fnv_00457620 {
extern int __cdecl FloatToInt(float value);

struct CellAvailabilityQuery : TES
{
    unsigned char FUN_004511e0(TESObjectCELL* cell, bool flag);
};
extern CellAvailabilityQuery* DAT_011dea10;

struct FUN_00457620_nodeowner
{
    int GetGeometry_0053f0e0();
};

struct FUN_00457620_cellhost
{
    FUN_00457620_nodeowner* TESObjectCELL_GetLand(const float* pos);
};

struct TerrainMaterialQuery : TES
{
    int TES_GetLandGeometry(const float* pos);
};

// @fnv 0x00457620
// src: XBOX_PDB 0x00457620
int TerrainMaterialQuery::TES_GetLandGeometry(const float* pos)
{
    int cellX = FloatToInt(pos[0]);
    int cellY2 = FloatToInt(pos[1]);
    if (cellX % 4096 == 0 && (float)cellX > pos[0])
    {
        cellX--;
    }
    if (cellY2 % 4096 == 0 && (float)cellY2 > pos[1])
    {
        cellY2--;
    }
    cellX >>= 12;
    cellY2 >>= 12;
    TESObjectCELL* cell5 = ((TESCoordinateLookup*)this)->FindCell(cellX, cellY2);
    if (cell5 != 0)
    {
        if (DAT_011dea10->FUN_004511e0(cell5, false))
        {
            return ((FUN_00457620_cellhost*)cell5)->TESObjectCELL_GetLand(pos)->GetGeometry_0053f0e0();
        }
    }
    return 0;
}
}  // namespace fnv_00457620

namespace fnv_00457be0 {
struct CellProxy
{
    bool TESObjectCELL_GetLoaded();
    int GetRaceListSize();
};
struct GridProxy
{
    bool FUN_004ba5a0(unsigned int, unsigned int);
    CellProxy* FUN_004ba490(unsigned int, unsigned int);
};
struct WorldProxy
{
    CellProxy* TESWorldSpace_LoadCell(int, int);
};
extern TESDataHandler* DAT_011c3f2c;
struct OwnerProxy
{
    int unk00;
    int unk04;
    GridProxy* grid;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int x;
    int y;
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
    WorldProxy* world;
    WorldProxy* FUN_004fd3e0();
    void TES_ShowLoadingMenu(int, WorldProxy*, int);
    void TES_InitModelsToLoad(int);
};
// Scans a grid-sized area around x/y, skipping cells by mode, and sums cell values into a total that triggers FUN_00457d70 when nonzero.
// @fnv 0x00457be0
// src: XBOX_PDB 0x00457be0
void OwnerProxy::TES_InitModelsToLoad(int mode)
{
    unsigned int h, p;
    int a = 0;
    int s = x - ((unsigned int)*g_011c63cc.Int() >> 1);
    int i = y - ((unsigned int)*g_011c63cc.Int() >> 1);
    for (h = 0; h < (unsigned int)*g_011c63cc.Int(); ++h)
    {
        for (p = 0; p < (unsigned int)*g_011c63cc.Int(); ++p)
        {
            switch (mode)
            {
            case 0:
                if (grid->FUN_004ba5a0(h, p))
                    continue;
                break;
            case 1:
                if (grid->FUN_004ba490(h, p))
                    continue;
                break;
            }
            if (FUN_004fd3e0())
            {
                CellProxy* f = 0;
                f = world->TESWorldSpace_LoadCell(s + h, i + p);
                if (!f)
                    f = (CellProxy*)DAT_011c3f2c->GetCellAtGridPosition(s + h, i + p, (TESWorldSpace*)FUN_004fd3e0(), true);
                if (f && !f->TESObjectCELL_GetLoaded())
                    a += f->GetRaceListSize();
            }
        }
    }
    if (a)
        TES_ShowLoadingMenu(1, world, 0);
}
}  // namespace fnv_00457be0

struct FUN_00458f90_shell
{
    void TES_ClearDeadCountList();
};
struct G2List : G2
{
    void FUN_00470470();
};

// Walks the list at this+0x9c, deleting each referenced object, then calls FUN_00470470 on the list.
// @fnv 0x00458f90
// src: XBOX_PDB 0x00458f90
void FUN_00458f90_shell::TES_ClearDeadCountList()
{
    G2* entry = (G2*)((char*)this + 0x9c);
    while (entry != 0 && *entry->_ref_006815c0() != 0)
    {
        int* object = *entry->_ref_006815c0();
        delete object;
        entry = (G2*)entry->_ref_00726070();
    }
    ((G2List*)((char*)this + 0x9c))->FUN_00470470();
}

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
// @fnv 0x00459100
// src: XBOX_PDB 0x00459100
unsigned short SaveSizeOwner::TES_GetSaveSize()
{
    unsigned short size = 0;
    unsigned short originalSize = size;
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        size += 4;
        size += 2;
    }
    SaveItemList* items3 = FUN_0050d100();
    size += 4;
    size += items3->FUN_005ae380() * 6;
    if (DAT_011de45c->FUN_008df040() >= 50)
        size += 4;
    if (*DAT_011de4e8.FUN_00408d60())
    {
        SaveFormRecord* record6 = DAT_011de45c->FUN_004fd3e0();
        if (record6)
        {
            SaveForm* form = LookupSaveForm(record6->formId);
            ProgramFlow(DAT_01012cb0, size - originalSize, record6->formId, form->GetDebugName(),
                         *reinterpret_cast<unsigned int*>(record6->flags), 6274, DAT_01017874);
        }
        else
        {
            ProgramFlow(DAT_01012c78, size - originalSize, 6274, DAT_01017874);
        }
    }
    return size;
}

namespace fnv_00459750 {
struct ArrHead
{
    int count;
};
struct ArrAccessor
{
    ArrHead* Setting_Int();
};
extern char DAT_011c3e38;
extern unsigned int DAT_011dea10;
struct ItemX
{
    void TESObjectCELL_UpdateSounds();
};
struct MgrX
{
    bool FUN_004511e0(ItemX* item, int flag);
};
struct ResX
{
    void FUN_00628da0();
};
struct SubX
{
    ResX* Modelloader_GetReferencedThis();
};

// Iterates m_38 and m_3C, calling FUN_0054ba00 on non-null entries accepted by FUN_004511e0, then calls FUN_00628da0 on the result of m_C0.FUN_00559450().
// @fnv 0x00459750
} // namespace fnv_00459750
void TES::ProcessItems(BGSLoadGameBuffer* unused)
{
    using namespace fnv_00459750;
    for (int i = 0; i < reinterpret_cast<ArrAccessor*>(&fnv_00459750::DAT_011c3e38)->Setting_Int()->count; i++)
    {
        if ((*(fnv_00459750::ItemX***)((char*)this + 0x38))[i] != 0)
        {
            if (reinterpret_cast<MgrX*>(fnv_00459750::DAT_011dea10)->FUN_004511e0((*(fnv_00459750::ItemX***)((char*)this + 0x38))[i], 1))
            {
                (*(fnv_00459750::ItemX***)((char*)this + 0x38))[i]->TESObjectCELL_UpdateSounds();
            }
        }
    }
    for (int j = 0; j < reinterpret_cast<ArrAccessor*>(&::DAT_011c3c90)->Setting_Int()->count; j++)
    {
        if ((*(fnv_00459750::ItemX***)((char*)this + 0x3c))[j] != 0)
        {
            if (reinterpret_cast<MgrX*>(fnv_00459750::DAT_011dea10)->FUN_004511e0((*(fnv_00459750::ItemX***)((char*)this + 0x3c))[j], 1))
            {
                (*(fnv_00459750::ItemX***)((char*)this + 0x3c))[j]->TESObjectCELL_UpdateSounds();
            }
        }
    }
    (*(fnv_00459750::SubX*)((char*)this + 0xc0)).Modelloader_GetReferencedThis()->FUN_00628da0();
}
namespace fnv_00459750 {

}  // namespace fnv_00459750

namespace fnv_00459870 {
struct ArrHead
{
    unsigned int count;
};
struct ArrAccessor
{
    ArrHead* Setting_Int();
};
extern char DAT_011c63cc;
struct ItemNode
{
    void AddFurnitureToList(void* p);
};
struct Lookup
{
    ItemNode** FUN_004ba490(unsigned int a, unsigned int b);
};

// If m_34 is set, calls FUN_0054ca00 on it with &m_94; otherwise iterates all index pairs via m_08->FUN_004ba490 and calls FUN_0054ca00 on each node.
// @fnv 0x00459870
} // namespace fnv_00459870
void TES::ProcessItemNodes()
{
    using namespace fnv_00459870;
    if ((*(fnv_00459870::ItemNode**)((char*)this + 0x34)) != 0)
    {
        (*(fnv_00459870::ItemNode**)((char*)this + 0x34))->AddFurnitureToList(&(*(int*)((char*)this + 0x94)));
    }
    else
    {
        for (unsigned int i = 0; i < reinterpret_cast<ArrAccessor*>(&fnv_00459870::DAT_011c63cc)->Setting_Int()->count; i++)
        {
            for (unsigned int j = 0; j < reinterpret_cast<ArrAccessor*>(&fnv_00459870::DAT_011c63cc)->Setting_Int()->count; j++)
            {
                ItemNode** tmp = (*(fnv_00459870::Lookup**)((char*)this + 0x8))->FUN_004ba490(i, j);
                ItemNode* val = *tmp;
                val->AddFurnitureToList(&(*(int*)((char*)this + 0x94)));
            }
        }
    }
}
namespace fnv_00459870 {

}  // namespace fnv_00459870

struct FUN_00459920_reference
{
    bool TESObjectCELL_GetAttached();
    void QueueReferences(int changeFlag);
};
struct ReferenceSoundGrid : GridCellArray
{
    FUN_00459920_reference** FUN_004ba490(unsigned int column, unsigned int row);
};
struct ReferenceSoundReset : TES
{
    FUN_00459920_reference* FUN_005f36f0();
    void TES_QueueReferencesForAttachedCells();
};
// @fnv 0x00459920
// src: XBOX_PDB 0x00459920
void ReferenceSoundReset::TES_QueueReferencesForAttachedCells()
{
    if (!g_dataHandler)
        return;

    if (FUN_005f36f0() && FUN_005f36f0()->TESObjectCELL_GetAttached())
        FUN_005f36f0()->QueueReferences(0);

    for (unsigned int column = 0; column < static_cast<unsigned int>(*g_011c63cc.Int()); ++column)
    {
        for (unsigned int row = 0; row < static_cast<unsigned int>(*g_011c63cc.Int()); ++row)
        {
            FUN_00459920_reference* object;
            FUN_00459920_reference** entry = (*(ReferenceSoundGrid**)((char*)this + 0x8))->FUN_004ba490(column, row);
            object = *entry;
            if (object && object->TESObjectCELL_GetAttached())
                object->QueueReferences(0);
        }
    }
}


unsigned int __fastcall DetailedActorPathHandler_GetCurrentNodeIndex(char* apName);

extern GlobalObject_0045cf30 g_011c7b98;

struct NiSourceTexture;

struct WaterFormNode
{
    bool IsEmpty();
    TESWaterForm** GetItem();
    WaterFormNode* GetNext();
};


// TES.h lacks the typed texture overload; add its declaration without duplicating TES storage.
struct TESTextureImageAccess : TES
{
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};

struct WaterTextureLoader
{
    void LoadWaterTextures();
};

// Iterates the water form list and, unless g_011c7b98.Bool() is set, creates and assigns a texture image for each form that has a texture.
// @fnv 0x0045a600
void WaterTextureLoader::LoadWaterTextures()
{
    AutoMemContext kMemContext(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 7207);
    DetailedActorPathHandler_GetCurrentNodeIndex((char*)this);
    if (*g_011c7b98.Bool())
        return;
    WaterFormNode* pNode = (WaterFormNode*)g_dataHandler->GetTESWaterFormList();
    while (pNode && !pNode->IsEmpty())
    {
        TESWaterForm* m_pWaterForm = *pNode->GetItem();
        if (m_pWaterForm->HasTexture())
        {
            NiPointer<NiSourceTexture> spTexture(0);
            ((TESTextureImageAccess*)g_TES)->CreateTextureImage(m_pWaterForm->GetTexturePath(), spTexture, true, false);
            m_pWaterForm->SetTexture(spTexture);
        }
        pNode = pNode->GetNext();
    }
}


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

// @fnv 0x0045a9a0
void ModelCloneOwner::AddCloneEntry(NiObject* apObject)
{
    if (!apObject)
        return;
    ModelCloneNode* pIter6 = pCloneList;
    while (pIter6)
    {
        if (pIter6->m_pRenderedNodeEntry == apObject)
            return;
        pIter6 = pIter6->GetNext();
    }
    ModelCloneNode* pNode2 = new ModelCloneNode;
    pNode2->m_pRenderedNodeEntry = apObject;
    pNode2->SetNext(pCloneList);
    pCloneList = pNode2;
    pNode2->pClones = new ModelPtr[3];
    pNode2->pClones[0] = apObject;
    for (int i = 1; i < 3; i++)
    {
        pNode2->pClones[i] = apObject->Clone();
    }
}

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

struct CachedParticleSearch : TES
{
    int FindMatchingNode(void*, ObjC*);
};

// @fnv 0x0045aba0
int CachedParticleSearch::FindMatchingNode(void* pKey, ObjC* pObj)
{
    int result;
    ListNodeB* node;
    {
        int i;
        pObj->Release(0);
        result = 0;
        node = (*(ListNodeB**)((char*)this + 0xb0));
        while (node != 0)
        {
            if (node->Matches(pKey))
            {
                result = 1;
                break;
            }
            node = node->NextNode();
        }
        if (node != 0 && node->m_slots != 0)
        {
            for (i = 0; i < 3; i++)
            {
                if (node->m_slots[i].Resolve() != 0)
                {
                    if (node->m_slots[i].Resolve()->Check() == 0)
                    {
                        pObj->Attach(&node->m_slots[i]);
                        result = 2;
                        break;
                    }
                }
            }
        }
        return result;
    }
}

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

// @fnv 0x0045afb0
void FUN_0045afb0_cls::SetNavMeshMaps(NavMeshHolder* pNavMeshMaps)
{
    if (m_pNavMeshMaps != 0)
    {
        if (pNavMeshMaps != 0)
        {
            Warning_005b5e40("AI: Multiple NavMeshInfoMaps loaded");
        }
        NavMeshHolder* pOldMaps = m_pNavMeshMaps;
        NavMeshHolder* first = pOldMaps;
        (first != 0) ? first->unkV4(1) : 0;
    }
    m_pNavMeshMaps = pNavMeshMaps;
}

namespace fnv_0045bc80 {
struct Obj;
struct BigV
{
    virtual Obj* v0();
    virtual Obj* v1();
    virtual Obj* v2();
    virtual Obj* v3ret();
    virtual Obj* v4();
    virtual Obj* v5();
    virtual Obj* v6();
    virtual Obj* v7();
    virtual Obj* v8();
    virtual Obj* v9();
    virtual Obj* v10();
    virtual Obj* v11();
    virtual Obj* v12();
    virtual Obj* v13();
    virtual Obj* v14();
    virtual Obj* v15();
    virtual Obj* v16();
    virtual Obj* v17();
    virtual Obj* v18();
    virtual Obj* v19();
    virtual Obj* v20();
    virtual Obj* v21();
    virtual Obj* v22();
    virtual Obj* v23();
    virtual Obj* v24();
    virtual Obj* v25();
    virtual Obj* v26();
    virtual Obj* v27();
    virtual Obj* v28();
    virtual Obj* v29();
    virtual Obj* v30();
    virtual Obj* v31();
    virtual Obj* v32();
    virtual Obj* v33();
    virtual Obj* v34();
    virtual Obj* v35();
    virtual Obj* v36();
    virtual Obj* v37();
    virtual Obj* v38();
    virtual Obj* v39();
    virtual Obj* v40();
    virtual Obj* v41();
    virtual Obj* v42();
    virtual Obj* v43();
    virtual Obj* v44();
    virtual Obj* v45();
    virtual Obj* v46();
    virtual Obj* v47bc();
    virtual Obj* v48();
    virtual Obj* v49();
    virtual Obj* v50();
    virtual Obj* v51();
    virtual Obj* v52();
    virtual Obj* v53();
    virtual Obj* v54();
    virtual Obj* v55();
    virtual Obj* v56();
    virtual Obj* v57();
    virtual Obj* v58();
    virtual Obj* v59();
    virtual Obj* v60();
    virtual Obj* v61();
    virtual Obj* v62();
    virtual Obj* v63();
    virtual Obj* v64();
    virtual int v65chk();
    virtual Obj* v66();
    virtual Obj* v67();
    virtual Obj* v68();
    virtual Obj* v69();
    virtual Obj* v70();
    virtual Obj* v71();
    virtual Obj* v72();
    virtual Obj* v73();
    virtual Obj* v74();
    virtual Obj* v75();
    virtual Obj* v76();
    virtual Obj* v77();
    virtual Obj* v78();
    virtual Obj* v79();
    virtual Obj* v80();
    virtual Obj* v81();
    virtual Obj* v82();
    virtual Obj* v83();
    virtual Obj* v84();
    virtual Obj* v85();
    virtual Obj* v86();
    virtual Obj* v87();
    virtual Obj* v88();
    virtual Obj* v89();
    virtual Obj* v90();
    virtual Obj* v91();
    virtual Obj* v92();
    virtual Obj* v93();
    virtual Obj* v94();
    virtual Obj* v95();
    virtual Obj* v96();
    virtual Obj* v97();
    virtual Obj* v98();
    virtual Obj* v99();
    virtual Obj* v100();
    virtual Obj* v101();
    virtual Obj* v102();
    virtual Obj* v103();
    virtual Obj* v104();
    virtual Obj* v105();
    virtual Obj* v106();
    virtual Obj* v107();
    virtual Obj* v108();
    virtual Obj* v109();
    virtual Obj* v110();
    virtual Obj* v111();
    virtual Obj* v112();
    virtual Obj* v113();
    virtual Obj* v114();
    virtual Obj* v115();
    virtual Obj* v116ret();
};
struct Obj
{
    Obj* FUN_00456fc0(int);
    unsigned int FUN_0043b480();
    Obj* FUN_0043b4a0(unsigned int);
    Obj* FUN_006629f0();
    Obj* NiObjectNET_GetControllers();
    void ClearField();
    Obj* FUN_00586170();
    void FUN_006fd130();
    Obj* FUN_004ba490(int, int);
    Obj* ShadowSceneNode_QPortalGraph();
    Obj* FUN_00413f40();
    Obj* FUN_00891170();
    unsigned char NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    Obj* Modelloader_GetReferencedThis();
    Obj* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(Obj**);
    void ClearField40();
    Obj* BSMultiBoundRoom_SetCullResult(int);
    Obj* SetFieldCC(int);
    Obj* TESCombatStyle_GetAdvancedData();
    Obj* Sky_GetSunLightSpecularColor();
    Obj* ComputeValue_005a8080();
    int DereferenceIfNotNull(Obj*);
    Obj* AddEight(Obj*);
    int BGSSaveFormBuffer_GetForm();
    Obj* FUN_006733e0();
    Obj* BSPortal_GetSharedGeometry();
    Obj* FUN_004f9bf0();
    void InitFromArg(int);
    Obj* NiNode_GetAtChecked(int);
};



extern SettingT_GameSettingCollection_ DAT_011c63cc;

extern char DAT_01202e74;
Obj* __cdecl FUN_00450b80(int);
unsigned int __fastcall DetailedActorPathHandler_GetCurrentNodeIndex(char*);
bool __cdecl NiObject_IsExactKindOf(char*, Obj*);
struct ThisC
{
    unsigned int unk00;
    unsigned int unk04;
    Obj* m_08;
    char pad0c[0x28];
    Obj* m_34;
    void TES_ResetAllMultiBoundNodes(unsigned char a1, unsigned char a2);
};
// @fnv 0x0045bc80
// src: COMMUNITY 0x0045bc80
void ThisC::TES_ResetAllMultiBoundNodes(unsigned char a1, unsigned char a2)
{
    Obj* list;
    Obj* formPtr;
    unsigned int ii;
    {
        Obj* head;
        if (!!m_34)
        {
            list = m_34->FUN_00456fc0(7);
            if (list != 0)
            {
                for (ii = 0; ii < list->FUN_0043b480(); ii++)
                {
                    formPtr = list->FUN_0043b4a0(ii);
                    if (formPtr != 0)
                    {
                        head = formPtr;
                        if (((BigV*)head)->v65chk() == 0)
                        {
                            head->FUN_006629f0()->NiObjectNET_GetControllers()->ClearField();
                        }
                    }
                }
            }
        }
        else
        {
            Obj* ptr =
                ((EffectSetting*)this)->GetHitSound() ? reinterpret_cast<Obj*>(((TESSound*)((EffectSetting*)this)->GetHitSound())->FUN_00586170()) : 0;
            if (ptr != 0)
                ptr->FUN_006fd130();
            unsigned int j;
            for (j = 0; j < (unsigned int)*DAT_011c63cc.Setting_Int(); j++)
            {
                unsigned int k;
                for (k = 0; k < (unsigned int)*DAT_011c63cc.Setting_Int(); k++)
                {
                    Obj* e4 = m_08->FUN_004ba490(j, k);
                    Obj* discB = *(Obj**)e4;
                    if (discB != 0)
                    {
                        Obj* c = discB->FUN_00456fc0(7);
                        if (c != 0)
                        {
                            unsigned int l;
                            for (l = 0; l < c->FUN_0043b480(); l++)
                            {
                                Obj* e2 = c->FUN_0043b4a0(l);
                                if (e2 != 0)
                                {
                                    Obj* m = e2;
                                    ((BigV*)m)->v47bc();
                                    m->FUN_006629f0()->NiObjectNET_GetControllers()->ClearField();
                                }
                            }
                        }
                        if (a1 != 0)
                        {
                            c = discB->FUN_00456fc0(2);
                            unsigned int nxtBase;
                            for (nxtBase = 0; nxtBase < c->FUN_0043b480(); nxtBase++)
                            {
                                Obj* e3 = c->FUN_0043b4a0(nxtBase);
                                if (e3 != 0)
                                {
                                    Obj* h3 = e3;
                                    h3->FUN_006629f0()->NiObjectNET_GetControllers()->ClearField();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    Obj* it2 = FUN_00450b80(0)->NiNode_GetAtChecked(6);
    Obj* pList = it2 ? ((BigV*)it2)->v3ret() : 0;
    if (pList != 0)
    {
        unsigned int i2;
        for (i2 = 0; i2 < pList->FUN_0043b480(); i2++)
        {
            Obj* cell = pList->FUN_0043b4a0(i2);
            if (cell != 0)
            {
                Obj* h4 = cell;
                h4->FUN_006629f0()->NiObjectNET_GetControllers()->ClearField();
            }
        }
    }
    if (FUN_00450b80(0)->ShadowSceneNode_QPortalGraph() != 0)
    {
        Obj* z = FUN_00450b80(0)->ShadowSceneNode_QPortalGraph()->FUN_00413f40()->Modelloader_GetReferencedThis();
        while (z != 0)
        {
            Obj* next6c = *(Obj**)FUN_00450b80(0)->ShadowSceneNode_QPortalGraph()->FUN_00413f40()->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&z);
            if (next6c != 0)
                next6c->ClearField40();
        }
        Obj* obj2 = FUN_00450b80(0)->ShadowSceneNode_QPortalGraph()->FUN_00891170();
        if (obj2->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() == 0)
        {
            if (a2 != 0)
            {
                Obj* temp68 = obj2->Modelloader_GetReferencedThis();
                while (temp68 != 0)
                {
                    NiPointer<NiAVObject> smart(*(NiPointer<NiAVObject>*)obj2->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&temp68));
                    if (((Obj*)(void*)&smart)->Modelloader_GetReferencedThis() != 0)
                    {
                        ((BigV*)((Obj*)(void*)&smart)->Modelloader_GetReferencedThis())->v47bc();
                        ((Obj*)(void*)&smart)->Modelloader_GetReferencedThis()->BSMultiBoundRoom_SetCullResult(3);
                        ((Obj*)(void*)&smart)->Modelloader_GetReferencedThis()->SetFieldCC(0);
                        Obj* v = ((Obj*)(void*)&smart)->Modelloader_GetReferencedThis()->TESCombatStyle_GetAdvancedData()->Modelloader_GetReferencedThis();
                        while (!!v)
                        {
                            Obj* nxt = *(Obj**)((Obj*)(void*)&smart)->Modelloader_GetReferencedThis()->TESCombatStyle_GetAdvancedData()->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&v);
                            if (nxt != 0)
                            {
                                nxt->ClearField40();
                                if (nxt->BSPortal_GetSharedGeometry()->FUN_004f9bf0() != 0)
                                {
                                    nxt->BSPortal_GetSharedGeometry()->FUN_004f9bf0()->InitFromArg(0);
                                }
                            }
                        }
                        Obj* inner = ((Obj*)(void*)&smart)->Modelloader_GetReferencedThis()->Sky_GetSunLightSpecularColor()->Modelloader_GetReferencedThis();
                        while (inner != 0)
                        {
                            Obj* nxt2 =
                                *(Obj**)((Obj*)(void*)&smart)->Modelloader_GetReferencedThis()->Sky_GetSunLightSpecularColor()->NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetNext(&inner);
                            if (nxt2 != 0)
                                nxt2->ClearField40();
                        }
                    }
                }
            }
        }
    }
    {
        Obj* base;
        int ret;
        Obj* node;
        if (((Obj*)DetailedActorPathHandler_GetCurrentNodeIndex((char*)this)) != 0)
        {
            node = 0;
            base = ((Obj*)DetailedActorPathHandler_GetCurrentNodeIndex((char*)this))->ComputeValue_005a8080()->Modelloader_GetReferencedThis();
            ret = 0;
            while (0 != base)
            {
                ret = ((Obj*)DetailedActorPathHandler_GetCurrentNodeIndex((char*)this))->ComputeValue_005a8080()->DereferenceIfNotNull(base);
                if (base != 0)
                {
                    node = *(Obj**)((Obj*)DetailedActorPathHandler_GetCurrentNodeIndex((char*)this))->ComputeValue_005a8080()->AddEight(base);
                    Obj* lst = ((Obj*)((char*)node + 0x24))->Modelloader_GetReferencedThis();
                    unsigned int nxtL = 0;
                    while (lst != 0)
                    {
                        nxtL = ((Obj*)((char*)node + 0x24))->DereferenceIfNotNull(lst);
                        if (lst != 0)
                        {
                            Obj* theItem = *(Obj**)((Obj*)((char*)node + 0x24))->AddEight(lst);
                            int pass = theItem->BGSSaveFormBuffer_GetForm();
                            Obj* vTmp = ((BigV*)theItem)->v116ret();
                            if (NiObject_IsExactKindOf(&DAT_01202e74, vTmp->FUN_0043b4a0(0)))
                            {
                                Obj* res = vTmp->FUN_0043b4a0(0);
                                res->FUN_006629f0()->NiObjectNET_GetControllers()->ClearField();
                            }
                        }
                        lst = (Obj*)nxtL;
                    }
                }
                base = (Obj*)ret;
            }
            node = ((Obj*)DetailedActorPathHandler_GetCurrentNodeIndex((char*)this))->FUN_006733e0();
            if (node != 0)
            {
                Obj* lst2 = ((Obj*)((char*)node + 0x24))->Modelloader_GetReferencedThis();
                int nxt2 = 0;
                while (lst2 != 0)
                {
                    nxt2 = ((Obj*)((char*)node + 0x24))->DereferenceIfNotNull(lst2);
                    if (lst2 != 0)
                    {
                        Obj* itemB = *(Obj**)((Obj*)((char*)node + 0x24))->AddEight(lst2);
                        int has = itemB->BGSSaveFormBuffer_GetForm();
                        Obj* top = ((BigV*)itemB)->v116ret();
                        if (NiObject_IsExactKindOf(&DAT_01202e74, top->FUN_0043b4a0(0)))
                        {
                            Obj* sub = top->FUN_0043b4a0(0);
                            sub->FUN_006629f0()->NiObjectNET_GetControllers()->ClearField();
                        }
                    }
                    lst2 = (Obj*)nxt2;
                }
            }
        }
    }
}
}  // namespace fnv_0045bc80

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
// @fnv 0x0045c8d0
// src: COMMUNITY 0x0045c8d0
void S_0045c8d0::TES_SetHideLandBlendPassForGridCell(unsigned int a, unsigned int b, unsigned char c)
{
    S_0045c8d0_R* r7 = unk8->FUN_004ba490(a, b);
    if (r7 && r7->unk0)
    {
        for (int i = 0; i < 4; i++)
        {
            S_0045c8d0_Child* child = r7->unk0->GetCellNodeAt(i);
            S_0045c8d0_Obj* objVal = child->NiNode_GetAtChecked(0) ? child->FUN_0043b4a0(0)->v6() : 0;
            if (objVal)
            {
                S_0045c8d0_Tgt* t = objVal->FUN_00a59d30(NiShadeProperty_GetType());
                t->BSShaderProperty_SetFlag(0x2e, c);
            }
        }
    }
}

namespace fnv_0045c9e0 {
struct FUN_0043b4a0_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual struct FUN_00a59d30_shell* FUN_Virtual0x18();
};

struct FUN_0045bc00_shell
{
    int NiNode_GetAtChecked(int);
    FUN_0043b4a0_Target* FUN_0043b4a0(int);
};

void* NiShadeProperty_GetType();

struct FUN_00441130_shell
{
    void BSShaderProperty_SetFlag(int, bool);
};

struct FUN_00a59d30_shell
{
    FUN_00441130_shell* FUN_00a59d30(void*);
};

struct FUN_0045c9e0_shell
{
    void* unk00;
    void* unk04;
    GridCellArray* cells;
    void TES_SetSkipNormalMapsForGridCell(int x, int y, bool flag);
};

// @fnv 0x0045c9e0
// src: COMMUNITY 0x0045c9e0
void FUN_0045c9e0_shell::TES_SetSkipNormalMapsForGridCell(int x, int y, bool flag)
{
    TESObjectCELL** cell = (TESObjectCELL**)cells->Get(x, y);
    if (cell && *cell)
    {
        int i;
        FUN_00a59d30_shell* obj;
        for (i = 0; i < 4; i++)
        {
            NiAVObject* node = ((CellSceneAccess*)*cell)->GetCellNodeAt(i);
            obj = ((FUN_0045bc00_shell*)node)->NiNode_GetAtChecked(0)
                      ? ((FUN_0045bc00_shell*)node)->FUN_0043b4a0(0)->FUN_Virtual0x18()
                      : 0;
            if (obj)
            {
                FUN_00441130_shell* target = obj->FUN_00a59d30(NiShadeProperty_GetType());
                target->BSShaderProperty_SetFlag(0x34, !flag);
            }
        }
    }
}
}  // namespace fnv_0045c9e0

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

// Returns true when m_28 is non-null and its m_04 field is non-zero.
// @fnv 0x0045cb90
// src: XBOX_PDB 0x0045cb90
bool FUN_0045cb90_cls::TESObjectLAND_HasVertices()
{
    return (m_28 != 0 && m_28->m_04 != 0) ? true : false;
}

class B45CDA0Cell
{
  public:
    void ActivateAllSubmergedReferencesIslands();
};

struct B45CDA0GridCell
{
    B45CDA0Cell* m_pkCell;
};

class LandscapeCellGrid : GridCellArray
{
  public:
    B45CDA0GridCell* Get(unsigned int uiX, unsigned int uiY);
};

struct LandscapeReset : TES
{
    void TES_ActivateAllSubmergedReferencesIslands();
};

// Calls FUN_00558c90 on the interior cell if set, otherwise on every non-null cell in the grid cell array.
// @fnv 0x0045cda0
// src: XBOX_PDB 0x0045cda0
void LandscapeReset::TES_ActivateAllSubmergedReferencesIslands()
{
    if ((*(B45CDA0Cell**)((char*)this + 0x34)))
    {
        (*(B45CDA0Cell**)((char*)this + 0x34))->ActivateAllSubmergedReferencesIslands();
    }
    else
    {
        for (unsigned int uiX = 0; uiX < (unsigned int)*g_011c63cc.Int(); uiX++)
        {
            for (unsigned int uiY = 0; uiY < (unsigned int)*g_011c63cc.Int(); uiY++)
            {
                B45CDA0GridCell* pkGridCell = (*(LandscapeCellGrid**)((char*)this + 0x8))->Get(uiX, uiY);
                B45CDA0Cell* pkCell = pkGridCell->m_pkCell;
                if (pkCell)
                    pkCell->ActivateAllSubmergedReferencesIslands();
            }
        }
    }
}

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
struct CellQueueIOManager : IOManager
{
    void LoadQueuedPriority(int);
};
extern CellQueueIOManager* DAT_01202d98;

extern NiPoint3 DAT_011a9478;
void TESTerrainLODManager_UpdateGrass(blob12 position, blob12 direction, float scale);
extern Setting originalRuntimeFloatSetting16;
struct FadeInterface
{
    void FUN_00700960(int, float, bool);
};
extern FadeInterface* DAT_011d8804;
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
// @fnv 0x004512c0
// src: XBOX_PDB 0x004512c0
void TES4512::TES_ReloadGridCells(const NiPoint3* position, bool reload)
{
    if (!DAT_011c3f2c || FUN_005f36f0())
        return;
    if (DAT_011c3ed0)
        return;
    DAT_011c3ed0 = true;
    if (reload)
    {
        grid->Reset();
        GridCellArray_SetRecreateCanopyShadowMaskTexture(1);
        BSShaderManager_SetProjectedShadowMaskTexture(0);
        world->FUN_00586170()->UnloadAll_006fce00();
        world->FUN_00586170()->Update_006fca90(g_thePlayer->GetPosition(15));
        grid->SetGridPosition(gridX, gridY);
        TES_FreeExteriorBuffer(false, 0);
        FUN_00452490(false);
        TES_InitModelsToLoad(false);
        RefreshGrid();
        DAT_01202d98->LoadQueuedPriority(4);
        NiPoint3 point(position->x, position->y, 0.0f);
        GetLandHeightAt(*position, point.z);
        TallGrassShaderProperty_SetUseBackgroundLoading(0);
        TESTerrainLODManager_UpdateGrass(*(blob12*)&point, *(blob12*)&DAT_011a9478, 1.0f);
        TallGrassShaderProperty_SetUseBackgroundLoading(1);
        if (!TES_CellTestRunning())
            DAT_011d8804->FUN_00700960(1, *originalRuntimeFloatSetting16.Setting_Float_00403e20(), false);
        ProcessItemNodes();
        ((Process4512*)&DAT_011e0e80)->ProcessLists_PlaceActorsinBedsOrChairs();
        ((Process4512*)&DAT_011e0e80)->FUN_00972bb0();
    }
    else
    {
        grid->SetGridPosition(gridX, gridY);
        TES_InitModelsToLoad(true);
        RefreshGrid();
    }
    TES_RunScripts();
    NiUpdateData update(0.0f, false, false);
    root->NiAVObject_Update(update);
    FUN_00452490(false);
    DAT_011c3f2c->CloseAllTES();
    DAT_011c3ed0 = false;
}

struct WaterCellSearch : TES
{
    TESObjectCELL** TES_FindFirstGridCellWithWater();
};

// @fnv 0x004516d0
// src: XBOX_PDB 0x004516d0
TESObjectCELL** WaterCellSearch::TES_FindFirstGridCellWithWater()
{
    TESObjectCELL** foundCell = 0;
    unsigned int gridSize = *g_011c63cc.Int();
    unsigned int center = gridSize >> 1;
    unsigned int centerCoordinate = center;
    for (unsigned int radius = 0; radius < center; ++radius)
    {
        if (radius == 0)
        {
            TESObjectCELL** cell = (TESObjectCELL**)(*(GridCellArray**)((char*)this + 0x8))->Get(centerCoordinate, centerCoordinate);
            if (cell && *cell && (*cell)->HasWater())
                foundCell = cell;
        }
        else
        {
            unsigned int yMax = centerCoordinate + radius;
            unsigned int xMax = yMax;
            unsigned int yMin = centerCoordinate - radius;
            unsigned int xMin = yMin;
            for (unsigned int x = xMin; x <= xMax; ++x)
            {
                TESObjectCELL** cell = (TESObjectCELL**)(*(GridCellArray**)((char*)this + 0x8))->Get(x, yMax);
                if (cell && *cell && (*cell)->HasWater())
                {
                    foundCell = cell;
                    break;
                }
                else
                {
                    cell = (TESObjectCELL**)(*(GridCellArray**)((char*)this + 0x8))->Get(x, yMin);
                    if (cell && *cell && (*cell)->HasWater())
                    {
                        foundCell = cell;
                        break;
                    }
                }
            }
            if (!foundCell)
            {
                for (unsigned int y = yMin + 1; y < yMax; ++y)
                {
                    TESObjectCELL** cell = (TESObjectCELL**)(*(GridCellArray**)((char*)this + 0x8))->Get(xMin, y);
                    if (cell && *cell && (*cell)->HasWater())
                    {
                        foundCell = cell;
                        break;
                    }
                    else
                    {
                        cell = (TESObjectCELL**)(*(GridCellArray**)((char*)this + 0x8))->Get(xMax, y);
                        if (cell && *cell && (*cell)->HasWater())
                        {
                            foundCell = cell;
                            break;
                        }
                    }
                }
            }
        }
        if (foundCell)
            break;
    }
    return foundCell;
}

extern const double DAT_010179e0;

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
    void TESObjectCELL_PlaceCanopyShadow(blob12);
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
// Attaches ref to cell: handles special cases, picks a node from other or ref, adds ref to the cell, and updates actor/tree state.
// @fnv 0x00451ef0
// src: XBOX_PDB 0x00451ef0
void AttachmentHandler::TES_AttachModel(AttachRef* ref, AttachCell* cell, AttachRef* other, bool skip)
{
    if (!ref)
        return;
    if (ref->IsSpecialB())
    {
        AttachRef* specialB = ref;
        specialB->HandleB();
        return;
    }
    if (ref->IsSpecialA())
    {
        AttachRef* specialA = ref;
        specialA->HandleA();
        return;
    }
    TES_CleanTemp3D(ref);
    unsigned char type = ref->BGSSaveFormBuffer_GetForm()->FUN_00401170();
    if (IsRefUsable(ref))
    {
        if (!skip)
            FUN_00451ea0(ref);
        AttachNode* node = 0;
        if (other && other->VATS_GetVATSLight())
        {
            node = other->VATS_GetVATSLight();
            if (!ref->TESObjectREFR_Get3D())
                ref->TESObjectREFR_Set3DSimple(node);
        }
        else
            node = ref->GetNode(0);
        AttachNode* chosen = node;
        if (other)
            other->FinalizeAttach();
        if (chosen)
        {
            if (type == 44 || type == 45)
            {
                if (chosen->NiAVObject_GetParent())
                    chosen->NiAVObject_GetParent()->Release(chosen);
            }
            else
            {
                cell->GetOrCreateWidget();
                FUN_00450b80(0)->FUN_00b5eeb0(chosen);
                if (ref->IsActor())
                    FUN_00450b80(0)->FUN_00b5cbd0(chosen);
                if (ref->TESObjectREFR_GetVisibleDistant())
                    cell->TESObjectCELL_IncLoadedRefsWithVisibleDistantCount();
                bool add = true;
                if (ref->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 35)
                {
                    TESBoundObject* base = ref->BGSSaveFormBuffer_GetForm();
                    if (reinterpret_cast<FormCollisionQuery*>(base)->BGSPlaceableWater_IsAutomaticWater())
                        add = false;
                }
                if (add)
                {
                    cell->TESObjectCELL_AttachReference3D(ref, 0);
                    ref->TESObjectREFR_UpdateReference3D();
                }
                if (ref->TESForm_GetDestructible() && ref->TESObjectREFR_QUnderwater())
                    TESObjectREFR_RemoveMasterParticleAddonNodes((TESObjectREFR*)chosen);
                else if (ref->TESObjectREFR_GetLoadedDataFlag(2))
                {
                    if (cell->TESObjectCELL_GetAttached() || cell->TESObjectCELL_GetAttaching())
                        TESObjectREFR_AddMasterParticleAddonNodes((TESObjectREFR*)chosen);
                }
                if (ref->IsActor())
                {
                    AttachRef* actor = ref;
                    if (actor)
                        actor->FUN_00483710();
                }
                if (type == 30)
                    ref->BGSSaveFormBuffer_GetForm()->Revert(reinterpret_cast<unsigned int>(ref->FUN_00430830()));
                else
                    FUN_00450b80(0)->FUN_00b5d9f0(chosen, 0);
            }
        }
        ref->TESObjectREFR_InitScript();
        if (!DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading())
        {
            Script_InitActionList(ref, ref->BSFile_GetDevice());
            Script_SetActionFlag(ref, ref->BSFile_GetDevice(), 4096);
        }
        if (type == 37)
        {
            TESObjectTREE* tree = dynamic_cast<TESObjectTREE*>(ref->BGSSaveFormBuffer_GetForm());
            if (tree && BSTreeManager_GetUseCanopyShadows())
            {
                NiPoint2 treeDimensions = *tree->GetDimensions();
                if (reinterpret_cast<const float*>(&treeDimensions)[0] > DAT_010179e0 &&
                    reinterpret_cast<const float*>(&treeDimensions)[1] > DAT_010179e0)
                {
                    cell->TESObjectCELL_PlaceCanopyShadow(*(blob12*)ref->GetPoint((unsigned int)(tree->GetTreeScale(1.0f) * ref->TESObjectREFR_GetScale_00567400())));
                }
            }
        }
        if (ref->IsActor())
        {
            AttachRef* actor2 = ref;
            actor2->FUN_008c4640();
            if (ref != DAT_011dea3c)
                FUN_004b6dc0(actor2->TESObjectREFR_Get3D(), ref->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        }
    }
}

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
extern TESDataHandler* DAT_011c3f2c;
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
    int originX = centerX - (*DAT_011c63cc.GetPtr() >> 1);
    int originY = centerY - (*DAT_011c63cc.GetPtr() >> 1);
    int count = 0;
    bool defer = false;
    if (FUN_00705e80())
        defer = true;
    bool loading4 = FUN_00705e80();
    DAT_011de45c->FUN_004534f0(true);
    DAT_011ddf38->BGSSaveLoadGame_SetDeferInitForms(true);
    if (TESObjectCELL_ExteriorWorld())
        TESObjectCELL_ExteriorWorld()->bhkWorld_StartBatchingAdds();
    for (unsigned int x = 0; x < *DAT_011c63cc.GetPtr(); ++x)
    {
        for (unsigned int y = 0; y < *DAT_011c63cc.GetPtr(); ++y)
        {
            TES_LoadGridCell(x, y, originX + x, originY + y);
            Cell* cell = (Cell*)DAT_011c3f2c->GetCellAtGridPosition(originX + x, originY + y, (TESWorldSpace*)FUN_004fd3e0(), false);
            if (DAT_011dea10->TES_IsBuffered(cell))
                AddCellToBuffer(cell);
            if (loading4 || (DAT_011de45c->FUN_0047c850() && DAT_011de45c->FUN_0047c850()))
            {
                ++count;
                float percent =
                    (double)count / (*DAT_011c63cc.GetPtr() * *DAT_011c63cc.GetPtr()) * DAT_01017a40;
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
    for (unsigned int x2 = 0; x2 < *DAT_011c63cc.GetPtr(); ++x2)
    {
        for (unsigned int y2 = 0; y2 < *DAT_011c63cc.GetPtr(); ++y2)
        {
            if (FUN_004fd3e0())
            {
                Cell* cell2 = (Cell*)DAT_011c3f2c->GetCellAtGridPosition(originX + x2, originY + y2, (TESWorldSpace*)FUN_004fd3e0(), false);
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

struct S_004537c0_Sky : Sky
{
    void Update_0063ac70(float f);
};
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

// Updates the sky with a time-based or fallback value, builds a fade from DAT_011c3c08, and passes it to the manager obtained via FUN_009611e0.
// @fnv 0x004537c0
// src: XBOX_PDB 0x004537c0
void Zt5TES::TES_UpdateCellMainThread()
{
    S_004537c0_Fade fadeData;
    ((S_004537c0_Sky*)pWeatherSky)
        ->Update_0063ac70(Interface_InDialog() ? g_timeGlobal.GetStoredFloatValue() * *g_011c5724.Float() : Main_QFrameAnimTime());
    fadeData.FUN_0043d410(DAT_011c3c08, 0, 0);
    ((S_004537c0_Tes*)this)->NiAVObject_GetParent()->NiAVObject_Update(&fadeData);
}

struct CellBufferPurge : TES
{
    CellBufferPurge* NiAVObject_GetWorldTranslate();
    TESObjectCELL* FUN_005f36f0();
    void TES_DetachGridCells();
    void TES_FreeExteriorBuffer(unsigned char, int);
    bool ContainsCell(TESObjectCELL*);
    void FUN_00454d50(unsigned char);
    void FUN_008d7dc0(int);
    void TES_ClearAllCells(unsigned char, unsigned char);
};

struct FUN_004539a0_helperA
{
    void FUN_00470470();
};
struct FUN_004539a0_helperB
{
    void FUN_00483710();
};

// @fnv 0x004539a0
// src: XBOX_PDB 0x004539a0
void CellBufferPurge::TES_ClearAllCells(unsigned char a1, unsigned char a2)
{
    ((FUN_004539a0_helperA*)NiAVObject_GetWorldTranslate())->FUN_00470470();
    if (a1 == 0 || FUN_005f36f0() != 0)
    {
        TES_DetachGridCells();
    }
    ((FUN_004539a0_helperB*)BSAudio_QInstance())->FUN_00483710();
    TES_FreeExteriorBuffer(a1, 0);
    if (FUN_005f36f0() != 0 && a1 == 0)
    {
        if (!ContainsCell(FUN_005f36f0()))
        {
            g_dataHandler->RemoveCell(FUN_005f36f0());
        }
    }
    FUN_00454d50(a1);
    if (a1 == 0 && a2 == 0)
    {
        FUN_008d7dc0(0);
    }
    (*(unsigned char*)((char*)this + 0xb4)) = 1;
}

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
    TESForm* grid;
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

// @fnv 0x00453a80
// src: XBOX_PDB 0x00453a80
bool CellBufferManager::TES_ClearOldestBufferedCell()
{
    BufferedCell* cell = 0;
    if (!FUN_005f36f0())
    {
        for (int i = *DAT_011c3e38.Setting_Int() - 1; i >= 0; --i)
        {
            if (interiorBuffer[i])
            {
                cell = interiorBuffer[i];
                interiorBuffer[i] = 0;
                break;
            }
        }
        if (!cell)
        {
            CompactQueuedCells();
            unsigned int count = grid->GetFormID() * grid->GetFormID();
            for (unsigned int i = *DAT_011c3c90.Int() - 1; i >= count; --i)
            {
                if (exteriorBuffer[i])
                {
                    if (!FUN_004511e0(exteriorBuffer[i], true) && !exteriorBuffer[i]->TESObjectCELL_IsRefListLocked())
                    {
                        cell = exteriorBuffer[i];
                        exteriorBuffer[i] = 0;
                    }
                    break;
                }
            }
        }
    }
    else
    {
        unsigned int count = grid->GetFormID() * grid->GetFormID();
        for (unsigned int i = *DAT_011c3c90.Int() - 1; i >= count; --i)
        {
            if (exteriorBuffer[i] && !FUN_004511e0(exteriorBuffer[i], true) && !exteriorBuffer[i]->TESObjectCELL_IsRefListLocked())
            {
                cell = exteriorBuffer[i];
                exteriorBuffer[i] = 0;
                break;
            }
        }
        if (!cell)
        {
            for (int i = *DAT_011c3e38.Setting_Int() - 1; i >= 0; --i)
            {
                if (interiorBuffer[i] && interiorBuffer[i] != FUN_005f36f0())
                {
                    cell = interiorBuffer[i];
                    interiorBuffer[i] = 0;
                    break;
                }
            }
        }
        if (!cell)
        {
            for (unsigned int i = 0; i < count; ++i)
            {
                if (exteriorBuffer[i] && !FUN_004511e0(exteriorBuffer[i], true) && !exteriorBuffer[i]->TESObjectCELL_IsRefListLocked())
                {
                    cell = exteriorBuffer[i];
                    exteriorBuffer[i] = 0;
                    TES_DetachGridCells();
                    break;
                }
            }
        }
    }
    if (cell)
    {
        g_dataHandler->RemoveCell(cell);
        if (!exteriorBuffer[0] && FUN_004fd3e0())
            FUN_004fd3e0()->FUN_00586170()->UnloadAll_006fce00();
        return true;
    }
    return false;
}

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
extern TESDataHandler* reloadData;
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
// Switches the active scene to destination at position, resetting interfaces, streaming, terrain and audio, then updates the menu and pathing.
// @fnv 0x00453dc0
void ReloadManager::AttachScene(ReloadScene* destination, ReloadPoint* position)
{
    if (!TES_CellTestRunning())
        reloadStreaming->Main_RenderMenuBackground();
    ReloadGetRoot()->bhkWorld_SetEnabled(0);
    ReloadGetRoot()->SetProcessEnabled(false);
    ReloadInterior* interiorData5;
    ReloadScene* cellB = FUN_005f36f0();
    if (cellB == destination)
    {
        FUN_00452580(position, false);
    }
    else
    {
        if (ReloadGetInterface())
            ReloadGetInterface()->BSShaderLightingProperty_ClearLights_Thunk();
        if (*reloadBoolSetting.FUN_00408d60())
        {
            if (!cellB)
            {
                if (TES_FreeExteriorBuffer(1, 0))
                    FUN_00452490(0);
            }
            else
            {
                TES_DetachGridCells();
                if (TES_FreeExteriorBuffer(1, 0))
                    FUN_00452490(0);
            }
        }
        if (!reloadMode->BGSSaveLoadGame_GetSaveGameLoading() && !ReloadMenuActive(1007, 0) && !reloadRuntime->MoviePlayer_GetPlayingSequence())
            reloadStreaming->Main_Swap();
        interiorData5 = destination->FUN_00546c20();
        if (interiorData5)
            interiorData5->DetermineLevel();
        ReloadAttachManager(destination->GetImpactSwap());
        ReloadGetMain(0)->FUN_00b5ddf0(0);
        ReloadGetMain(0)->ShadowSceneNode_ProcessQueuedLights();
        ReloadGetMain(0)->RemoveAllLights();
        bool hadCell = false;
        if (cellB)
        {
            hadCell = true;
            cellB->TESObjectCELL_Detach(true);
            ReloadInterfaceReset();
            ReloadGetMain(0)->FUN_00b5cbd0(reloadPlayer->PlayerCharacter_Get3D_00950bb0(0));
        }
        if (!ContainsCell(destination))
        {
            ReloadScene* discard = GetEntry(*reloadGridSetting.Setting_Int() - 1);
            if (discard)
                RemoveEntry(discard);
        }
        cellB = destination;
        FUN_008d7dc0(destination);
        BSShaderManager_SetInterior(1);
        if (cellB)
        {
            if (savedX == 0x7fffffff && !hadCell)
            {
                savedX = gridX;
                savedY = gridY;
                Pause(1, 0);
            }
            gridX = ReloadRound(position->x) >> 12;
            gridY = ReloadRound(position->y) >> 12;
            cellB->LoadAllTempData();
            bool modeA = false;
            bool _state = false;
            modeA = reloadMode->BGSSaveLoadGame_GetSaveGameLoading();
            _state = reloadState->FUN_0047c850();
            if (cellB->GetRaceListSize() && !cellB->TESObjectCELL_GetLoaded())
                TES_ShowLoadingMenu(1, reinterpret_cast<ReloadCell*>(cellB), 0);
            cellB->UpdateCellScene(object);
            ReloadRoot* root = cellB->TESObjectCELL_GetbhkWorld();
            if (loadedNode.Modelloader_GetReferencedThis())
                reinterpret_cast<ReloadLoaded*>(loadedNode.Modelloader_GetReferencedThis())->FUN_00628da0();
            if (root)
                root->bhkWorld_StartBatchingAdds();
            cellB->TESObjectCELL_AttachModels(true);
            if (reloadCells->ModelLoader_IsFileQueuedForCell(reinterpret_cast<ReloadCell*>(cellB)))
                TES_ShowLoadingMenu(1, reinterpret_cast<ReloadCell*>(cellB), 0);
            UpdateSkyModeForCell(cellB);
            if (!modeA)
                reloadAudio->LoadQueuedPriority(1);
            if (root)
                root->bhkWorld_StopBatchingAdds(0);
            reloadMenu->TES_ActivateAllSubmergedReferencesIslands();
            if (!TES_CellTestRunning() && !modeA && reloadPlayerCheck->CheckState())
                reloadFade->FUN_00700960(true, 0.0f, 0);
            if (!modeA)
            {
                reloadTerrain.ClearMobileObjectData();
                ProcessItemNodes();
                reloadTerrain.ProcessLists_PlaceActorsinBedsOrChairs();
                reloadTerrain.FUN_00972bb0();
            }
            FUN_00452490(0);
            reloadData->CloseAllTES();
            ReloadObject* cellObject7 = cellB->GetOrCreateWidget();
            cellObject7->UpdateProperties();
            if (!cellObject7->NiNode_GetChildCount())
            {
                ReloadPoint zero8(0.0f, 0, 0);
                cellObject7->NiAVObject_Update(&zero8);
            }
            cellB->TESObjectCELL_AttachLights(true);
            TES_AddToInteriorBuffer(destination);
        }
        if (!hadCell)
        {
            ReloadInterface* interface = ReloadGetInterface();
            if (interface)
                interface->BSShaderAccumulator_ClearAllQueries();
            ReloadInterfaceRefresh();
            camera->ClearCanopyShadowMaskTexture();
        }
        if (TES_CellTestRunning())
            TES_ShowLoadingMenu(0, 0, 0);
        FUN_00452490(0);
        ReloadDropResources(0);
        if (*cellB->TESObjectCELL_GetWaterNoiseTextureName())
        {
            ReloadContext context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 3188);
            ReloadNode node3(0);
            reloadMenu->FUN_004568c0(cellB->TESObjectCELL_GetWaterNoiseTextureName(), node3, 1, 0);
            reloadMenu->DetailedActorPathHandler_GetCurrentNodeIndex()->SetColorData(node3.Modelloader_GetReferencedThis());
        }
        else
            reloadMenu->DetailedActorPathHandler_GetCurrentNodeIndex()->SetColorData(0);
        if (!reloadMode->BGSSaveLoadGame_GetSaveGameLoading())
            ReloadPathingGet()->NavMeshObstacleManager_ForceUpdate();
    }
}

namespace fnv_00454450 {
struct ReloadPoint
{
    float x, y, z;
    ReloadPoint(float, float, float);
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
struct ReloadInterior
{
    ReloadGrid* NiAVObject_GetParent();
};
struct ReloadScene
{
    void* GetPortalGraph_009d9f20();
    void TESObjectCELL_Detach(bool);
    void ChangeProcessLevel(bool);
    bool FUN_00454b10();
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
    void FUN_00700960(bool, float);
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
extern TESDataHandler* reloadData;
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
struct ReloadManager
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
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
// @fnv 0x00454450
// src: XBOX_PDB 0x00454450
void ReloadManager::TES_LeaveInterior(ReloadPoint* point)
{
    ReloadWorld* world = FUN_004fd3e0();
    if (world)
    {
        world->FUN_00586170()->Update_006fca90(point, 15);
        world->FUN_00586170()->FUN_006fcdb0(point);
    }
    BSShaderManager_SetInterior(0);
    if (name)
        ReloadAttachManager(name->FUN_006733e0());
    ReloadDisableRendering(0);
    ReloadGetRoot()->bhkWorld_SetEnabled(1);
    ReloadScene* sceneTmp = FUN_005f36f0();
    if (sceneTmp)
    {
        if (ReloadGetMain(0)->ShadowSceneNode_QPortalGraph() == sceneTmp->GetPortalGraph_009d9f20())
            ReloadGetMain(0)->FUN_00b5ddf0(0);
        sceneTmp->TESObjectCELL_Detach(true);
        if (!ContainsCell(sceneTmp))
            reloadData->RemoveCell((TESObjectCELL*)sceneTmp);
        else
            sceneTmp->ChangeProcessLevel(true);
        FUN_008d7dc0(0);
        if (!reloadMode->BGSSaveLoadGame_GetSaveGameLoading())
        {
            if (savedX != 0x7fffffff)
            {
                if (*loaded)
                {
                    gridX = savedX;
                    gridY = savedY;
                    Pause(0, point);
                }
                else
                {
                    gridX = 0x7fffffff;
                    gridY = 0x7fffffff;
                    oldX = gridX;
                    oldY = gridY;
                }
                savedX = 0x7fffffff;
                savedY = 0x7fffffff;
            }
            else if (!TES_GetLandGeometry(point))
            {
                gridX = 0x7fffffff;
                gridY = 0x7fffffff;
                oldX = gridX;
                oldY = gridY;
            }
        }
        ReloadGetMain(0)->RemoveAllLights();
        ReloadGetMain(0)->FUN_00b5cbd0(reloadPlayer->PlayerCharacter_Get3D_00950bb0(0));
    }
    if (interior)
    {
        ReloadGrid* grid6 = interior->NiAVObject_GetParent();
        if (grid6)
            grid6->FUN_00450f90(0);
        ReloadGlobalUpdate(1);
    }
    ReloadGetRoot();
    ReloadGetRoot()->SetProcessEnabled(ReloadDropFlag());
    bool mode = false;
    bool stateB = false;
    mode = reloadMode->BGSSaveLoadGame_GetSaveGameLoading();
    stateB = reloadState->FUN_0047c850();
    FUN_00452580(point, !stateB);
    ReloadCell* cellA = FUN_00451900(gridX, gridY);
    if (reloadCells->ModelLoader_IsFileQueuedForCell(cellA))
        TES_ShowLoadingMenu(1, cellA, 0);
    if (ReloadGetRoot())
        ReloadGetRoot()->bhkWorld_StartBatchingAdds();
    if (!mode)
        reloadAudio->LoadQueuedPriority(4);
    FUN_0044ddc0()->AttachAllLand3D();
    InitFromMatrix();
    InitSoundGrid();
    if (ReloadGetRoot())
        ReloadGetRoot()->bhkWorld_StopBatchingAdds(0);
    TES_ActivateAllSubmergedReferencesIslands();
    ReloadPoint position6(point->x, point->y, 0.0f);
    GetLandHeightAt(point, position6.z);
    TallGrassShaderProperty_SetUseBackgroundLoading(0);
    ReloadMovePoint(position6, reloadRotation, 1.0f);
    TallGrassShaderProperty_SetUseBackgroundLoading(1);
    if (!TES_CellTestRunning() && !mode)
        reloadFade->FUN_00700960(true, *reloadSetting.Setting_Float_00403e20(1));
    if (!mode)
    {
        reloadTerrain.ClearMobileObjectData();
        ProcessItemNodes();
        reloadTerrain.ProcessLists_PlaceActorsinBedsOrChairs();
        reloadTerrain.FUN_00972bb0();
    }
    if (sceneTmp && !sceneTmp->FUN_00454b10())
    {
        texture->Sky_ActivateWeatherSounds(texture->TESMain_GetThread());
        texture->Sky_ActivateWeatherSounds(texture->FUN_00825c00());
    }
    TES_UpdateGridLights();
    UpdateSkyModeForCell(0);
    object->UpdateProperties();
    ReloadDropResources(0);
    if (TES_CellTestRunning())
        TES_ShowLoadingMenu(0, 0, 0);
    FUN_00452490(0);
    if (name && *name->TESWorldSpace_GetWaterNoiseTextureName())
    {
        ReloadContext context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 3434);
        ReloadNode node3(0);
        reloadMenu->FUN_004568c0(name->TESWorldSpace_GetWaterNoiseTextureName(), node3, 1, 0);
        reloadMenu->DetailedActorPathHandler_GetCurrentNodeIndex()->SetColorData(node3.Modelloader_GetReferencedThis());
    }
    else
        reloadMenu->DetailedActorPathHandler_GetCurrentNodeIndex()->SetColorData(0);
    reloadFinished = true;
    reloadCurrent = ReloadPair((gridX + 0.5) * 4096.0, (gridY + 0.5) * 4096.0);
    reloadPrevious = reloadCurrent;
    reloadHeight = ReloadHeight(0);
    reloadFlagA = false;
    reloadFlagB = reloadFlagA;
    if (FUN_004fd3e0()->FUN_00586170()->FUN_00454b70())
        reloadHasWorld = true;
    else
        reloadHasWorld = false;
    if (!reloadMode->BGSSaveLoadGame_GetSaveGameLoading())
        ReloadPathingGet()->NavMeshObstacleManager_ForceUpdate();
}
}  // namespace fnv_00454450

namespace fnv_00454d50 {
struct FUN_004503f0_obj
{
    unsigned int FUN_004503f0(void);
};
struct FUN_00557090_obj
{
    bool TESObjectCELL_IsRefListLocked(void);
};
extern int DAT_011c3e38;
extern TESDataHandler* DAT_011c3f2c;


// @fnv 0x00454d50
} // namespace fnv_00454d50
unsigned int TES::GetInteriorBufferCount(bool abSkipCurrent)
{
    using namespace fnv_00454d50;
    unsigned int count = 0;
    unsigned int i;
    for (i = 0; i < ((FUN_004503f0_obj*)&fnv_00454d50::DAT_011c3e38)->FUN_004503f0(); i++)
    {
        if ((*(TESObjectCELL***)((char*)this + 0x38))[i] != 0)
        {
            if (!(abSkipCurrent && GetInteriorCell() != 0 && (*(TESObjectCELL***)((char*)this + 0x38))[i] == GetInteriorCell()))
            {
                if (!((FUN_00557090_obj*)(*(TESObjectCELL***)((char*)this + 0x38))[i])->TESObjectCELL_IsRefListLocked())
                {
                    fnv_00454d50::DAT_011c3f2c->RemoveCell((*(TESObjectCELL***)((char*)this + 0x38))[i]);
                    (*(TESObjectCELL***)((char*)this + 0x38))[i] = 0;
                    count++;
                }
            }
        }
    }
    return count;
}
namespace fnv_00454d50 {

}  // namespace fnv_00454d50

namespace fnv_00455490 {
struct Q455490Quest
{
    bool GetEnabled();
    void RunScript();
};
struct Q455490List
{
    Q455490Quest** Item();
    Q455490List* Next();
};
struct Q455490Cell
{
    bool RunScripts_0054c740(int, int);
};
struct QuestCellGrid : GridCellArray
{
    Q455490Cell** Get(unsigned int, unsigned int);
};
struct Q455490Setting
{
    int* Int();
};
struct Q455490Lock
{
    void Lock(const char*);
    void Unlock();
};
struct Q455490Player
{
    void TESObjectREFR_RunScript();
};
bool FUN_005ac740();
bool __fastcall TESObjectCELL_GetAttached(void*);

extern bool g_455490_busy;
extern Q455490Lock g_455490_lock;
extern TESDataHandler* g_dataHandler455490;
extern Q455490Setting g_011c63cc_455490;
extern Q455490Player* g_thePlayer455490;

struct QuestCellUpdate : TES
{
    Q455490Cell* GetInteriorCell();
    void TES_RunScripts();
};

// Under a lock, runs scripts of all enabled quests, updates the interior cell or scans the grid for a matching cell, then updates the player.
// @fnv 0x00455490
// src: XBOX_PDB 0x00455490
void QuestCellUpdate::TES_RunScripts()
{
    if (g_455490_busy || !FUN_005ac740())
        return;
    {
        g_455490_busy = true;
        g_455490_lock.Lock(0);
        Q455490List* pIter6;
        Q455490Quest* kPQuest = 0;
        pIter6 = (Q455490List*)g_dataHandler455490->GetQuestList();
        while (pIter6)
        {
            kPQuest = *pIter6->Item();
            pIter6 = pIter6->Next();
            if (kPQuest && kPQuest->GetEnabled())
                kPQuest->RunScript();
        }
        if (GetInteriorCell())
        {
            GetInteriorCell()->RunScripts_0054c740(0, 0);
        }
        else
        {
            bool bCellFound = false;
            for (unsigned int uiX = 0; uiX < *g_011c63cc_455490.Int(); uiX++)
            {
                for (unsigned int uiY = 0; uiY < *g_011c63cc_455490.Int(); uiY++)
                {
                    Q455490Cell* pCell = *(*(QuestCellGrid**)((char*)this + 0x8))->Get(uiX, uiY);
                    if (pCell && TESObjectCELL_GetAttached(pCell) && pCell->RunScripts_0054c740(0, 0))
                    {
                        bCellFound = true;
                        break;
                    }
                }
                if (bCellFound)
                    break;
            }
        }
        g_thePlayer455490->TESObjectREFR_RunScript();
        g_455490_lock.Unlock();
        g_455490_busy = false;
    }
}
}  // namespace fnv_00455490

struct NiSourceTexture;
struct NiTextureFormatPrefs
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};
extern NiTextureFormatPrefs g_kTexturePrefs;

struct FixedStr
{
    const char* m_kHandle;
    FixedStr(const char* apString);
    ~FixedStr();
};

// FileFinder::Exist is 0x00456a20 (also bound by bipedanim.cpp); no shared FileFinder.h exists yet.
int __cdecl FindFileLocation(const char* apPath, char* apOut, unsigned int auiFlags, unsigned int auiMask);

struct SourceTextureStub
{
    static NiSourceTexture* Create(const FixedStr& arName, NiTextureFormatPrefs& arPrefs, bool abA, bool abB);
};

bool StreamGetTexture(const char* apPath, NiPointer<NiSourceTexture>* apTexture);
void TextureLoaded(NiSourceTexture* apTexture, int aiUnk);
void ModelWarning(const char* apFormat, ...);

// @fnv 0x004568c0
void TESTextureImageAccess::CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abNoWarning,
                                bool abArchiveOnly)
{
    unsigned int uiFlags = 0;
    unsigned int uiMask = 0xffff;
    arTexture = 0;
    StreamGetTexture(apPath, &arTexture);
    if (arTexture)
        return;
    NiPointer<NiSourceTexture> spTexture(0);
    if (abArchiveOnly)
    {
        uiFlags = 6;
        uiMask = 2;
    }
    if (!FindFileLocation(apPath, 0, uiFlags, uiMask) && abNoWarning)
        return;
    arTexture = SourceTextureStub::Create(FixedStr(apPath), g_kTexturePrefs, true, false);
    if (arTexture)
        TextureLoaded(arTexture, 0);
    else if (!abNoWarning)
        ModelWarning("MODELS: TES::CreateTextureImage unable to create image for \"%s\".\r\n", apPath);
}

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

struct GridCellQuery : TES
{
    FUN_00456fc0_ref* FUN_005f36f0();
    FUN_00456fc0_ref** GetGridCell_00457050(unsigned int i, unsigned int j);
};

struct CellDebugUpdate : TES
{
    FUN_00456fc0_ref* FUN_005f36f0();
    void TES_ShowCellNode(int, bool, bool);
};

// @fnv 0x00456d00
// src: XBOX_PDB 0x00456d00
void CellDebugUpdate::TES_ShowCellNode(int aiType, bool abShow, bool abGrid)
{
    TESObjectCELL_SetNodeCulled(aiType, !abShow);
    if (aiType == 0xb)
    {
        if (!((GridCellQuery*)DAT_011dea10)->FUN_005f36f0() ||
            !((TESObjectCELL*)((GridCellQuery*)DAT_011dea10)->FUN_005f36f0())->HasWater())
            TESWaterSystem_GetWaterRoot()->FUN_00450f90(!abShow);
        return;
    }

    int iCount = abGrid ? 0 : *((FUN_00456d00_cnt*)&DAT_011c3e38)->Setting_Int();
    for (int i = -1; i < iCount; i++)
    {
        FUN_00456fc0_ref* pRef = i == -1 ? FUN_005f36f0() : (*(FUN_00456fc0_ref***)((char*)this + 0x38))[i];
        if (pRef)
        {
            switch (aiType)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                FUN_00450f90_obj* pNode = pRef->FUN_00456fc0(aiType);
                if (pNode)
                    pNode->FUN_00450f90(!abShow);
                pRef->TESObjectCELL_CullChildrenOfMultibounds(!abShow, aiType);
                break;
            }
        }
    }

    if (!abGrid)
    {
        for (int j = 0; j < *((FUN_00456d00_cnt*)&DAT_011c3c90)->Setting_Int(); j++)
        {
            FUN_00456fc0_ref* pOther = (*(FUN_00456fc0_ref***)((char*)this + 0x3c))[j];
            if (pOther)
            {
                switch (aiType)
                {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                case 8:
                    FUN_00450f90_obj* pNode2 = pOther->FUN_00456fc0(aiType);
                    if (pNode2)
                        pNode2->FUN_00450f90(!abShow);
                    break;
                }
            }
        }
    }
    else
    {
        for (unsigned int x = 0; x < *DAT_011c63cc.Setting_Int(); x++)
        {
            for (unsigned int y = 0; y < *DAT_011c63cc.Setting_Int(); y++)
            {
                FUN_00456fc0_ref** ppGrid = ((GridCellQuery*)DAT_011dea10)->GetGridCell_00457050(x, y);
                FUN_00456fc0_ref* pGridRef = *ppGrid;
                if (pGridRef)
                {
                    switch (aiType)
                    {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 7:
                    case 8:
                        FUN_00450f90_obj* pNode3 = pGridRef->FUN_00456fc0(aiType);
                        if (pNode3)
                            pNode3->FUN_00450f90(!abShow);
                        break;
                    }
                }
            }
        }
    }
}

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

struct ObjectPlacementQuery : CellObjectQuery
{
    bool ApplyToObject(FUN_004571c0_obj* obj, int a2, int a3, float f, char b);
};

// If obj and b are set, resets obj's flag and transforms, then applies the current cell or every grid cell to obj, returning whether any applied.
// @fnv 0x004571c0
bool ObjectPlacementQuery::ApplyToObject(FUN_004571c0_obj* pObject, int a2, int a3, float f, char b)
{
    bool result = false;
    if (pObject && b)
    {
        pObject->SetFlag(0);
        pObject->SetTransforms(&NiPoint3_ZERO, &NiPoint3_ZERO, 0);
        if (DAT_011dea10->FUN_005f36f0())
        {
            result = ((FUN_004571c0_cell*)DAT_011dea10->FUN_005f36f0())->Apply(pObject, a2, a3, f, b);
        }
        else
        {
            for (unsigned int i = 0; i < *DAT_011c63cc.Setting_Int(); i++)
            {
                for (unsigned int j = 0; j < *DAT_011c63cc.Setting_Int(); j++)
                {
                    FUN_004571c0_cell* cell = (FUN_004571c0_cell*)*GetGridCell_00457050(i, j);
                    if (cell)
                    {
                        if (cell->Apply(pObject, a2, a3, f, b))
                            result = true;
                    }
                }
            }
        }
    }
    return result;
}

struct WS458200_Obj
{
    void DetermineLevel();
};
struct WS458200_Quest;
struct WorldTextureSource : TESWorldSpace
{
    WS458200_Obj* GetFieldD0();
    WS458200_Quest* FUN_006733e0();
    const char* TESWorldSpace_GetWaterNoiseTextureName() const;
    bool IsFlag4C20Set();
};
struct CanopySky : Sky
{
    void SetColorData(NiSourceTexture* apTexture);
};
struct WorldTextureUpdate : TES
{
    CanopySky* GetSky();
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};
extern WorldTextureUpdate* g_pWS458200TES;
extern GlobalObject_0045cf30 g_011c3d40;
void __cdecl FUN_0058eeb0(WS458200_Quest*);
void __cdecl FUN_007043c0();
void __cdecl Interface_SetRootMapSpace(WorldTextureSource*);
void __cdecl BSShaderManager_SetUseNoiseMap(bool);

struct WorldSpaceAssignment : TES
{
    void* FUN_005f36f0();
    void TES_DetachGridCells();
    int TES_FreeExteriorBuffer(bool, WorldTextureSource*);
    int FUN_00454d50(bool);
    void FUN_00452490(bool);
    void FUN_00450d80();
    void TES_SetWorldSpace(WorldTextureSource*);
};

// @fnv 0x00458200
// src: XBOX_PDB 0x00458200
void WorldSpaceAssignment::TES_SetWorldSpace(WorldTextureSource* apWorld)
{
    if (apWorld && (*(WorldTextureSource**)((char*)this + 0x88)) != apWorld)
    {
        if (*g_011c3d40.Bool())
        {
            if (FUN_005f36f0())
                TES_DetachGridCells();
            int iCount = 0;
            iCount += TES_FreeExteriorBuffer(true, (*(WorldTextureSource**)((char*)this + 0x88)));
            if (!FUN_005f36f0())
                iCount += FUN_00454d50(true);
            if (iCount)
                FUN_00452490(false);
        }
        (*(WorldTextureSource**)((char*)this + 0x88)) = apWorld;
        WS458200_Obj* pObj = (*(WorldTextureSource**)((char*)this + 0x88))->GetFieldD0();
        if (pObj)
            pObj->DetermineLevel();
        FUN_0058eeb0((*(WorldTextureSource**)((char*)this + 0x88))->FUN_006733e0());
        TES_DetachGridCells();
        FUN_00450d80();
        FUN_007043c0();
        Interface_SetRootMapSpace(apWorld);
        if (*apWorld->TESWorldSpace_GetWaterNoiseTextureName())
        {
            AutoMemContext kMemContext(0x1d, true, DAT_01017874, 0x1751);
            NiPointer<NiSourceTexture> spTexture(0);
            g_pWS458200TES->CreateTextureImage(apWorld->TESWorldSpace_GetWaterNoiseTextureName(), spTexture, true, true);
            g_pWS458200TES->GetSky()->SetColorData(spTexture);
        }
        else
        {
            g_pWS458200TES->GetSky()->SetColorData(0);
        }
        BSShaderManager_SetUseNoiseMap(!apWorld->IsFlag4C20Set());
    }
}


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

// Resolves the given ref or the default ref, then calls PlaySound on it with the sound id and position, returning false if no ref exists.
// @fnv 0x00458b70
bool Manager458::PlaySoundOnRef(int iSound, NiPoint3 kPos, Ref458* pkRef)
{
    Ref458* pkTarget = pkRef ? pkRef : GetDefaultRef();
    if (!pkTarget)
        return false;
    return pkTarget->PlaySound(iSound, kPos);
}

struct SaveWriter : SaveState
{
    unsigned char* FUN_00825c00();
    void TESSaveLoadGame_SaveGameDataOLD(void*, unsigned int);
    void TESSaveLoadGame_SaveNumericID(void*, unsigned int);
};
struct ValueReferencePair
{
    TESForm* form;
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

// @fnv 0x00459230
void SaveBlockOwner::WriteSaveBlock()
{
    SaveEntryNode* node;
    // Local names and declaration order preserve the original MSVC9 stack layout.
    unsigned short count = 0;            // Serialized 16-bit block length placeholder.
    unsigned char* initialPosition = 0;  // Location where the block length is backfilled.
    // Beginning of the range measured for diagnostic logging.
    unsigned char* blockSizePosition = static_cast<SaveWriter*>(DAT_011de45c)->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
        blockSizePosition = static_cast<SaveWriter*>(DAT_011de45c)->FUN_00825c00();
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int blockType = 0x424c4f4b;
        static_cast<SaveWriter*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&blockType, 4);
        initialPosition = static_cast<SaveWriter*>(DAT_011de45c)->FUN_00825c00();
        static_cast<SaveWriter*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&count, 2);
    }
    node = reinterpret_cast<SaveEntryNode*>(FUN_0050d100());
    // Number of entries written before the entry data.
    unsigned int blockSize = reinterpret_cast<SaveItemList*>(node)->FUN_005ae380();
    static_cast<SaveWriter*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&blockSize, 4);
    while (node)
    {
        ValueReferencePair* entry = *node->FUN_006815c0();
        if (entry)
        {
            unsigned int formId = 0;
            if (entry->form)
                formId = entry->form->GetFormID();
            static_cast<SaveWriter*>(DAT_011de45c)->TESSaveLoadGame_SaveNumericID(&formId, 4);
            static_cast<SaveWriter*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&entry->value, 2);
        }
        node = node->FUN_00726070();
    }
    if (DAT_011de45c->FUN_008df040() >= 50)
        static_cast<SaveWriter*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&DAT_011c3c08, 4);
    if (*DAT_011de4e8.FUN_00408d60())
    {
        unsigned char* finalPosition = static_cast<SaveWriter*>(DAT_011de45c)->FUN_00825c00();
        SaveFormRecord* record = DAT_011de45c->FUN_004fd3e0();
        if (record)
        {
            SaveForm* form = LookupSaveForm(record->formId);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         finalPosition - blockSizePosition, record->formId, form->GetDebugName(),
                         *reinterpret_cast<unsigned int*>(record->flags), 6369, DAT_01017874);
        }
        else
        {
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", finalPosition - blockSizePosition, 6369,
                         DAT_01017874);
        }
    }
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned char* uiTimestamp;
        unsigned char* endPosition = static_cast<SaveWriter*>(DAT_011de45c)->FUN_00825c00();
        uiTimestamp = initialPosition;
        if (endPosition > uiTimestamp + 65535)
            FNV_Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        DAT_01017874, 6369);
        *reinterpret_cast<unsigned short*>(initialPosition) = static_cast<unsigned short>(endPosition - uiTimestamp);
    }
}

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
extern TESDataHandler* testDataHandler;
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
// Marks the test running, iterates world cells within bounds and interior cells, invoking the per-cell test, then clears finished.
// @fnv 0x00459ae0
// src: XBOX_PDB 0x00459ae0
void CellTest::TES_RunCellTest(unsigned int flags)
{
    running = true;
    PlayerCharacter_SetGodMode(true);
    ProgramFlow("Running Cell Test");
    Interface_EmergencyCloseAllMenusAndBreakStuff();
    int state3 = Cmd_GetSessionTime_Execute();
    TestWorldList* worlds5 = (TestWorldList*)testDataHandler->GetTESWorldSpaceList();
    while (worlds5 && !worlds5->FUN_008256d0())
    {
        TestWorld* world = *worlds5->FUN_006815c0();
        if (world)
        {
            TES_SetWorldSpace(world);
            int minX = ((int)world->FUN_004565f0()) >> 12;
            int minY5 = ((int)world->GetUnka4()) >> 12;
            int maxX6 = ((int)world->FUN_009b88a0()) >> 12;
            int maxY6 = ((int)world->LowProcess_GetPlayerDamageDealt()) >> 12;
            const char* name3 = world->name.TESModel_GetModel();
            if (!name3 || !BSstrlen(name3))
                name3 = world->DebugName();
            ProgramFlow(DAT_01017e24, world->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), name3, minX, minY5, maxX6, maxY6);
            for (int x7 = minX; x7 < maxX6; x7 += *testStep.Setting_Int())
            {
                for (int y4 = minY5; y4 < maxY6; y4 += *testStep.Setting_Int())
                {
                    EmptyStructPlaceholder* cellTmp = world->FUN_005875a0(x7, y4);
                    if (!cellTmp)
                        cellTmp = world->TESWorldSpace_LoadCell(x7, y4);
                    if (cellTmp)
                        MoveToCell(cellTmp, flags, state3);
                }
            }
        }
        worlds5 = worlds5->FUN_00726070();
    }
    testDataHandler->RefreshCellList();
    unsigned int count2 = testDataHandler->GetInteriorCellCount();
    for (unsigned int index7 = 0; index7 < count2; index7++)
    {
        EmptyStructPlaceholder* interior4 = (EmptyStructPlaceholder*)testDataHandler->GetCellByInteriorIndex(index7);
        MoveToCell(interior4, flags, state3);
    }
    finished = false;
}

struct AddonQueuePointer
{
    QueuedFile* object;
    QueuedFile* Modelloader_GetReferencedThis();
    AddonQueuePointer& AssignTaskReference(QueuedFile* file);
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
// Queues a priority-5 file, then for each addon node loads its model, configures the particle node and registers it, or queues the model for loading.
// @fnv 0x00459f10
// src: COMMUNITY 0x00459f10
void AddonOwner::TES_PreloadAddonNodes()
{
    if (queuedFile.Modelloader_GetReferencedThis())
        return;
    AutoMemContext count(7, true, DAT_01017874, 7054);
    queuedFile.AssignTaskReference(new QueuedFile(5));
    unsigned int context = g_dataHandler->GetAddonNodeCount();
    for (unsigned int i = 0; i < context; ++i)
    {
        BGSAddonNode* addon = g_dataHandler->GetAddonNodeByIndex(i);
        if (addon)
        {
            if (addon->FUN_00448bf0())
            {
                NiNode* model = g_modelLoader->LoadFile((char*)addon->GetModelFilePath(), 0, true, false, false, false);
                if (model)
                {
                    AddonParticleNode* particle = static_cast<AddonParticleNode*>(model);
                    particle->SetSound(addon->GetGrass());
                    particle->FUN_00705b10(addon->FUN_0059e300());
                    particle->SetShortAtOffsetBC(addon->GetShortAtOffset58());
                    Main_GetMasterParticleSystemManager()->BSParticleSystemManager_AddMasterParticleSystem(particle);
                }
                g_modelLoader->QueueModelLoad((char*)addon->GetModelFilePath(), true, 1);
            }
            else
            {
                g_modelLoader->ProcessModelRequest(static_cast<TESModel*>(addon), 5, queuedFile.Modelloader_GetReferencedThis(), 0, true,
                                                   false, false);
            }
        }
    }
}

namespace fnv_0045a1e0 {

struct QueuePtr45
{
    QueuedFile* ptr;
    QueuedFile* Modelloader_GetReferencedThis();
    void AssignTaskReference(QueuedFile*);
};
struct Component45
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Queue(int, QueuedFile*);
};
struct Body45
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
    Component45 component;
};
struct List45
{
    bool FUN_008256d0();
    Body45** FUN_006815c0();
    List45* FUN_00726070();
};
struct Manager45
{
    void FUN_00525510(int, QueuedFile*, bool);
};
extern TESDataHandler* DAT_011c3f2c;
extern Manager45* DAT_011ca278;
struct Target45
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
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    QueuePtr45 queued;
    void QueueLoadForAll();
};
// @fnv 0x0045a1e0
void Target45::QueueLoadForAll()
{
    if (queued.Modelloader_GetReferencedThis())
        return;
    AutoMemContext list(MEM_CONTEXT_MEM_CONTEXT_EFFECTS_OVERHEAD, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp",
                        0x1bd0);
    queued.AssignTaskReference(new QueuedFile(5));
    List45* memory = (List45*)DAT_011c3f2c->GetBGSBodyPartDataList();
    while (memory && !memory->FUN_008256d0())
    {
        Body45* body = *memory->FUN_006815c0();
        memory = memory->FUN_00726070();
        if (body)
            body->component.Queue(5, queued.Modelloader_GetReferencedThis());
    }
    if (DAT_011ca278)
        DAT_011ca278->FUN_00525510(5, queued.Modelloader_GetReferencedThis(), false);
}
}  // namespace fnv_0045a1e0

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
// If not already done, marks the flag and loads each non-empty model setting string via g_modelLoader, passing the result to AddCloneEntry.
// @fnv 0x0045a750
void PreloadOwner::PreloadModelSettings()
{
    if (DAT_011c3f08)
        return;
    AutoMemContext context(0x32, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 0x1c66);
    DAT_011c3f08 = true;
    if (*g_011ce0c0.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011ce0c0.String(), 0, true, false, false, false));
    if (*g_011cfa28.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011cfa28.String(), 0, true, false, false, false));
    if (*g_011d12c0.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011d12c0.String(), 0, true, false, false, false));
    if (*g_011ce1a0.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011ce1a0.String(), 0, true, false, false, false));
    if (*g_011cfa64.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011cfa64.String(), 0, true, false, false, false));
    if (*g_011cf3a4.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011cf3a4.String(), 0, true, false, false, false));
    if (*g_011cf54c.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011cf54c.String(), 0, true, false, false, false));
    if (*g_011cebb0.String())
        AddCloneEntry((NiObject*)g_modelLoader->LoadFile(g_011cebb0.String(), 0, true, false, false, false));
}

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
// @fnv 0x0045ac80
// src: XBOX_PDB 0x0045ac80
void Target::TES_CleanupTemporaryParticleCache()
{
    FUN_0045ae20* current = head;
    while (current)
    {
        FUN_0045ae20* next = current->FUN_0044ddc0();
        delete current;
        current = next;
    }
    head = 0;
    if (*DAT_011cebb0.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011cebb0.FUN_00403df0());
    if (*DAT_011d12c0.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011d12c0.FUN_00403df0());
    if (*DAT_011ce1a0.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011ce1a0.FUN_00403df0());
    if (*DAT_011cf3a4.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011cf3a4.FUN_00403df0());
    if (*DAT_011cf54c.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011cf54c.FUN_00403df0());
    if (*DAT_011cfa64.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011cfa64.FUN_00403df0());
    if (*DAT_011ce0c0.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011ce0c0.FUN_00403df0());
    if (*DAT_011cfa28.FUN_00403df0())
        DAT_011c3b3c->ModelLoader_ReleaseFile((char*)DAT_011cfa28.FUN_00403df0());
}


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

// Lazily creates m_pkNavMeshInfoMap when it is null, the data handler exists and is not loading, then returns it.
// @fnv 0x0045af00
// src: XBOX_PDB 0x0045af00
NavMeshInfoMap* Owner45A::TES_GetNavMeshInfoMap()
{
    if (!m_pkNavMeshInfoMap && g_pkDataHandler45A && !g_pkDataHandler45A->GetSaveLoad())
        m_pkNavMeshInfoMap = new NavMeshInfoMap;
    return m_pkNavMeshInfoMap;
}

extern float DAT_01015f5c;
struct CellView : public TESObjectCELL
{
    bool CheckWaterHeight(const NiPoint3* apPos, float* apfHeight);
    int FUN_00544c30();
    int FUN_00544c60();
};
bool __fastcall FUN_00425fd0(TESObjectCELL* apCell);
struct WorldWaterCellQuery : TESWorldSpace
{
    CellView* GetCellFromWorldCoord(const NiPoint3* apPos);
    float FUN_0045cd80();
    CellView* FUN_005875a0(int aiX, int aiY);
};
struct WorldCellCoordinateQuery : TES
{
    WorldWaterCellQuery* FUN_004fd3e0();
    int FUN_0059bb30();
    int FUN_0045cd60();
};
struct CellWaterHeightQuery : TES
{
    CellView* FUN_005f36f0();
    float GetCellHeightAtPosition(const NiPoint3*, CellView*);
};
// @fnv 0x0045cbc0
float CellWaterHeightQuery::GetCellHeightAtPosition(const NiPoint3* apPos, CellView* apCell)
{
    float fRate = DAT_01015f5c;
    if (apCell)
    {
        float fCellHeight;
        if (apCell->CheckWaterHeight(apPos, &fCellHeight))
            return fCellHeight;
        else if (FUN_00425fd0(apCell))
            return DAT_01015f5c;
        fRate = TESObjectCELL_GetWaterHeight(apCell);
    }
    else
    {
        if (FUN_005f36f0())
        {
            float fCurrentHeight;
            FUN_005f36f0()->CheckWaterHeight(apPos, &fCurrentHeight);
            return fCurrentHeight;
        }
        apCell = ((WorldCellCoordinateQuery*)g_TES)->FUN_004fd3e0()->GetCellFromWorldCoord(apPos);
        if (apCell)
            fRate = TESObjectCELL_GetWaterHeight(apCell);
        else
            return ((WorldCellCoordinateQuery*)g_TES)->FUN_004fd3e0()->FUN_0045cd80();
    }
    int iWorldX;
    int iBaseY;
    if (apCell)
    {
        iWorldX = apCell->FUN_00544c30();
        iBaseY = apCell->FUN_00544c60();
    }
    else
    {
        iWorldX = ((WorldCellCoordinateQuery*)g_TES)->FUN_0059bb30();
        iBaseY = ((WorldCellCoordinateQuery*)g_TES)->FUN_0045cd60();
    }
    float fOtherHeight = 0.0f;
    for (int iX = iWorldX - 1; iX < iWorldX + 2; iX++)
    {
        for (int iY = iBaseY - 1; iY < iBaseY + 2; iY++)
        {
            CellView* pCell = ((WorldCellCoordinateQuery*)g_TES)->FUN_004fd3e0()->FUN_005875a0(iX, iY);
            if (pCell && pCell != apCell && pCell->CheckWaterHeight(apPos, &fOtherHeight))
                return fOtherHeight;
        }
    }
    return fRate;
}

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

// Gets the parent cell's world, then registers this ref with its occlusion manager via AddPlanes, AddToLists and UpdateBounds.
// @fnv 0x00576760
// src: XBOX_PDB 0x00576760
void C6760Ref::TESObjectREFR_CleanUpTraps()
{
    C6760Cell* pkCell = GetParentCell();
    C6760World* pkWorld = pkCell ? pkCell->GetWorld() : 0;
    if (pkWorld)
    {
        C6760Manager* pkManager = static_cast<C6760Manager*>(pkWorld->GetOcclusionManager());
        if (pkManager)
        {
            pkManager->AddPlanes(this);
            pkManager->AddToLists(this);
            pkManager->UpdateBounds(this);
        }
    }
}

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
// Returns true if FUN_005f36f0 succeeds, otherwise checks whether the scaled point coordinates fall inside the grid cell range derived from m_24 and m_28.
// @fnv 0x00451110
bool n451::Grid::ContainsPoint(const Pt& aPoint)
{
    if (FUN_005f36f0())
        return true;
    int iMinY = FloatToInt(aPoint.iMinY) >> 12;
    int nX = FloatToInt(aPoint.nX) >> 12;
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

struct LandscapeUpdate : LandscapeReset
{
    void TES_InitDistantTextureBlending();
};

// Iterates the grid cells, and for each cell with an entry object that passes FUN_0045cb90, calls FUN_005400e0 on it.
// @fnv 0x0045cac0
// src: COMMUNITY 0x0045cac0
void LandscapeUpdate::TES_InitDistantTextureBlending()
{
    FUN_00546fb0_cell* pCell = 0;
    FUN_005400e0_obj* pEntryObj;
    unsigned int i;
    unsigned int j;
    for (i = 0; i < *DAT_011c63cc.Setting_Int(); i++)
    {
        for (j = 0; j < *DAT_011c63cc.Setting_Int(); j++)
        {
            pCell = static_cast<FUN_00546fb0_cell*>((*(LandscapeCellGrid**)((char*)this + 0x8))->Get(i, j)->m_pkCell);
            pEntryObj = pCell ? pCell->TESObjectCELL_GetLand() : 0;
            if (pCell && pEntryObj && pEntryObj->TESObjectLAND_HasVertices())
                pCell->TESObjectCELL_GetLand()->TESObjectLAND_InitDistantTextureBlending();
        }
    }
}

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

struct SurfaceNormalQuery : TES
{
    TESObjectCELL* FUN_00451900(int, int);
    bool TES_GetLandNormal(const NiPoint3*, NiPoint3*, int);
};

// Computes the cell coordinates from pos, sets normal to (0,0,1), and if the cell passes a lookup test returns the result of a probe hit test.
// @fnv 0x004573f0
// src: COMMUNITY 0x004573f0
bool SurfaceNormalQuery::TES_GetLandNormal(const NiPoint3* pos, NiPoint3* normal, int flags)
{
    int cellX = _TruncateFloatToInt(pos->x);
    int cellY2 = _TruncateFloatToInt(pos->y);
    if (cellX % 4096 == 0 && (float)cellX > pos->x)
        cellX = cellX - 1;
    if (cellY2 % 4096 == 0 && (float)cellY2 > pos->y)
        cellY2 = cellY2 - 1;
    cellX >>= 12;
    cellY2 >>= 12;
    *(blob12*)normal = *(const blob12*)&NiPoint3_ZERO;
    normal->z = 1.0f;
    TESObjectCELL* cell5 = FUN_00451900(cellX, cellY2);
    if (cell5 && ((TESCellLookup*)g_TES)->FUN_004511e0(cell5, 0))
        return ((CellProbe*)cell5)->TESObjectCELL_GetLand(pos, normal, flags)->TESObjectLAND_GetLandNormal();
    return false;
}

struct xPt3C
{
    float x, y, z;
};
struct xChk
{
    bool Test();
};
struct xCellC
{
    xChk* GetAt(const xPt3C* pPos, int i);
};
struct xTESC
{
    bool IsLoaded(xCellC* pCell, int i);
};
extern xTESC* xTheTES;
int xTruncate(float f);
class xWorldC
{
  public:
    xCellC* GetContainingCell(int x, int y);
    bool TES_GetLandColor(const xPt3C* pPos, int i);
};

// Truncates pPos to cell coordinates, checks if the containing cell is loaded, and returns whether the cell's test at pPos passes.
// @fnv 0x00457520
// src: COMMUNITY 0x00457520
bool xWorldC::TES_GetLandColor(const xPt3C* pPos, int i)
{
    int qrEZrs = xTruncate(pPos->x);
    int qsSDDgz = xTruncate(pPos->y);
    if (qrEZrs % 4096 == 0 && qrEZrs > pPos->x)
        qrEZrs--;
    if (qsSDDgz % 4096 == 0 && qsSDDgz > pPos->y)
        qsSDDgz--;
    qrEZrs >>= 12;
    qsSDDgz >>= 12;
    xCellC* qfTOqo = GetContainingCell(qrEZrs, qsSDDgz);
    if (qfTOqo && xTheTES->IsLoaded(qfTOqo, 0))
        return qfTOqo->GetAt(pPos, i)->Test();
    return false;
}

class PathingSolution;

// Exe 0x0066b0d0 / 0x0045cec0: shared retain/release and destructor; scene references use an erased NiRefObject pointee.
#include "../../include/NiRefObject.h"
#include "../../include/NiPointer.h"
template <> NiPointer<NiRefObject>::NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;
template <> NiPointer<NiRefObject>::~NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;
template <> NiPointer<NiRefObject>& NiPointer<NiRefObject>::operator=(NiRefObject*) FNV64_NIPOINTER_EXCEPTION_SPEC;


typedef NiPointer<NiRefObject> FUN_0045cec0;

class FUN_00667120
{
  public:
    ~FUN_00667120();
    int unk00;
};

class FUN_0045ae50 : public FUN_0045cec0
{
  public:
    ~FUN_0045ae50();
    FUN_00667120* m_pkArray;
};

// Destructor that resets the shared reference and deletes the m_pkArray array if it is not null.
// @fnv 0x0045ae50
FUN_0045ae50::~FUN_0045ae50()
{
    NiPointer<NiRefObject>::operator=(static_cast<NiRefObject*>(0));
    if (m_pkArray)
        delete[] m_pkArray;
}

namespace s450dd0 {

struct Cell
{
    bool TESObjectCELL_GetLoaded();
    bool TESObjectCELL_GetAttached();
    void TESObjectCELL_AttachModels(int iArg);
    void TESObjectCELL_Detach(int iArg);
};

struct CellGrid
{
    Cell** FUN_004ba490(unsigned int uiX, unsigned int uiY);
    void AttachToWorld(int iWorld, unsigned int uiX, unsigned int uiY);
};

struct GridSettings
{
    unsigned int* Setting_Int();
};

struct Scheduler
{
    void bhkWorld_StartBatchingAdds();
    void bhkWorld_StartBatchingRemovals();
    void FUN_00c68f00(int iArg);
    void bhkWorld_StopBatchingAdds(int iArg);
};

struct Audio
{
    void ClearMobileObjectData();
};

struct Camera
{
    void FUN_00450f90(bool bPause);
};

struct Params
{
    Params(float fValue, int iArg0, int iArg1);

    float m_fValue;
    int m_iArg0;
    int m_iArg1;
};


extern int DAT_011c3f2c;
extern GridSettings DAT_011c63cc;
extern Audio DAT_011e0e80;

Scheduler* TESObjectCELL_ExteriorWorld();
void BGSTerrainManager_EnableLODWaterProcessing(bool bEnable);

struct World
{
    int unk00;
    int unk04;
    CellGrid* m_pkGrid;
    int m_iWorldSpace;
    SceneGraph* m_pkScene;

    void Pause(bool bPause, int iUnused);
};

// Updates the scheduler and cells based on bPause, clears mobile object data when resuming, updates the camera, and applies a zero fade.
// @fnv 0x00450dd0
void World::Pause(bool bPause, int iUnused)
{
    if (!DAT_011c3f2c)
        return;
    if (TESObjectCELL_ExteriorWorld())
    {
        if (bPause)
            TESObjectCELL_ExteriorWorld()->bhkWorld_StartBatchingRemovals();
        else
            TESObjectCELL_ExteriorWorld()->bhkWorld_StartBatchingAdds();
    }
    for (unsigned int uiRow = 0; uiRow < *DAT_011c63cc.Setting_Int(); uiRow++)
    {
        for (unsigned int j = 0; j < *DAT_011c63cc.Setting_Int(); j++)
        {
            Cell** ppCell = m_pkGrid->FUN_004ba490(uiRow, j);
            Cell* pkCell = *ppCell;
            if (bPause)
            {
                if (pkCell && pkCell->TESObjectCELL_GetAttached())
                    pkCell->TESObjectCELL_Detach(0);
            }
            else
            {
                if (pkCell && pkCell->TESObjectCELL_GetLoaded())
                {
                    m_pkGrid->AttachToWorld(m_iWorldSpace, uiRow, j);
                    pkCell->TESObjectCELL_AttachModels(0);
                }
            }
        }
    }
    if (TESObjectCELL_ExteriorWorld())
    {
        if (bPause)
            TESObjectCELL_ExteriorWorld()->FUN_00c68f00(0);
        else
            TESObjectCELL_ExteriorWorld()->bhkWorld_StopBatchingAdds(0);
    }
    if (!bPause)
        DAT_011e0e80.ClearMobileObjectData();
    Camera* pkView = (Camera*)m_pkScene->GetCamera();
    if (pkView)
    {
        pkView->FUN_00450f90(bPause);
        BGSTerrainManager_EnableLODWaterProcessing(!bPause);
    }
    Params kFade(0.0f, 0, 0);
    m_pkScene->Update(*(NiUpdateData*)&kFade);
}

}


struct FnCls
{
    void* FUN_005f36f0();
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    TESObjectCELL* TES_GetCellForPoint(float f1, float f2, int a3);
};

// Returns a non-null result from FUN_005f36f0; otherwise looks up a cell using shifted coordinates and checks it with FUN_004511e0.
// @fnv 0x004519d0
// src: XBOX_PDB 0x004519d0
TESObjectCELL* FnCls::TES_GetCellForPoint(float afX, float afY, int a3)
{
    if (FUN_005f36f0())
        return (TESObjectCELL*)FUN_005f36f0();
    int cellX = ((int)afX) >> 12;
    int cellY8 = ((int)afY) >> 12;
    TESObjectCELL* pCell = FUN_00451900(cellX, cellY8);
    if (pCell != 0 && ((TES*)g_TES)->IsCellBuffered(pCell, 1))
        return pCell;
    return 0;
}

bool __cdecl FUN_00705e80();
bool __cdecl LoadingMenu_GetResetFlagged();
void __cdecl UpdateIfEnabled(void*);
void __cdecl FUN_00705e00(void*, bool);
bool __cdecl LoadingMenu_IsInScriptMode();
void __cdecl LoadingMenu_SetScriptMode(int);
void __cdecl Interface_CloseLoadingMenu();
int __cdecl HUDMainMenu_GetMenuMode();
void __cdecl HUDMainMenu_UpdateVisibilityState(int);
extern unsigned int DAT_011c3efc;


struct Tex457
{
    void Sky_StopPlayingAllWeatherSounds();
};

struct Mgr457
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    void BSFileCache_ResumeFileCaching();
    void BSFileCache_PauseFileCaching();
};
Mgr457* __cdecl FUN_00aff100();

struct Form457
{
    unsigned int FUN_00401170();
    bool FUN_00425fd0();
    Form457* FUN_0054ddd0();
    Form457* FUN_008d6f30();
    Form457* TESObjectREFR_GetWorldSpace();
};

struct S457d70
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    int u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c;
    int u60, u64;
    Tex457* pTex68;
    bool TES_CellTestRunning();
    bool TES_ShowLoadingMenu(bool abFlag1, Form457* apForm, bool abFlag2);
};

// On the abFlag1 path, may pass apForm to FUN_00705e00 and call manager methods; otherwise updates DAT_011c3efc and may run cleanup calls.
// @fnv 0x00457d70
// src: COMMUNITY 0x00457d70
bool S457d70::TES_ShowLoadingMenu(bool abFlag1, Form457* apForm, bool abFlag2)
{
    if (abFlag1)
    {
        if (FUN_00705e80() && !LoadingMenu_GetResetFlagged())
        {
            UpdateIfEnabled(apForm);
            return false;
        }
        if (TES_CellTestRunning())
        {
            return false;
        }
        pTex68->Sky_StopPlayingAllWeatherSounds();
        BSAudio_QInstance()->SetAudioState(0x14);
        Form457* v8 = 0;
        Form457* v4 = 0;
        if (apForm)
        {
            switch (apForm->FUN_00401170())
            {
            case 0x41:
                v4 = apForm;
                break;
            case 0x39:
                v8 = apForm;
                if (v8 && !v8->FUN_00425fd0())
                {
                    v4 = v8->FUN_0054ddd0();
                    apForm = v4;
                    v8 = 0;
                }
                break;
            case 0x3a:
            case 0x3b:
            case 0x3c:
            case 0x3d:
            case 0x3e:
            case 0x3f:
            case 0x40:
            case 0x69:
                v8 = apForm->FUN_008d6f30();
                if (v8 && !v8->FUN_00425fd0())
                {
                    v4 = v8->FUN_0054ddd0();
                    v8 = 0;
                }
                else if (!v8)
                {
                    v4 = apForm->TESObjectREFR_GetWorldSpace();
                }
                break;
            }
        }
        FUN_00705e00(apForm, abFlag2);
        FUN_00aff100()->BSFileCache_ResumeFileCaching();
        FUN_00aff100()->v30();
        FUN_00aff100()->BSFileCache_PauseFileCaching();
        return true;
    }
    else
    {
        if (!LoadingMenu_IsInScriptMode() || (LoadingMenu_IsInScriptMode() && abFlag2))
        {
            DAT_011c3efc = 0;
            LoadingMenu_SetScriptMode(0);
            Interface_CloseLoadingMenu();
            if (HUDMainMenu_GetMenuMode() != 0x18)
            {
                HUDMainMenu_UpdateVisibilityState(2);
            }
        }
        else
        {
            if (DAT_011c3efc == 0)
            {
                DAT_011c3efc = Cmd_GetSessionTime_Execute() + 0x1388;
            }
            if (Cmd_GetSessionTime_Execute() > DAT_011c3efc)
            {
                DAT_011c3efc = 0;
                LoadingMenu_SetScriptMode(0);
                Interface_CloseLoadingMenu();
                if (HUDMainMenu_GetMenuMode() != 0x18)
                {
                    HUDMainMenu_UpdateVisibilityState(2);
                }
            }
        }
    }
    return false;
}

#include <windows.h>
struct BatchPoint
{
    float x, y, z;
    BatchPoint();
    BatchPoint(float, float, float);
    void Reset();
};
struct BatchString
{
    char* data;
    unsigned short length, capacity;
    BatchString();
    ~BatchString();
    operator const char*() const;
};
struct BatchSettings
{
    bool flag0, flag1, flag2, flag3, flag4, flag5;
    char unk06, unk07;
    int savedPriority;
};
struct BatchPortalList
{
    bool Empty();
};
struct BatchPortal
{
    BatchPortalList* GetList();
};
struct BatchRegionList
{
    bool Contains(void*&);
};
struct BatchRegions
{
    int unk00;
    BatchRegionList list;
};
struct BatchTerrain
{
    void Sample();
};
struct BatchWorld;
struct BatchCell
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void FunctionAtSlot4();
    virtual void FunctionAtSlot5();
    virtual void FunctionAtSlot6();
    virtual void VirtualFunction7();
    virtual void VirtualFunction8();
    virtual void VirtualFunction9();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void VirtualFunction24();
    virtual void VirtualFunction25();
    virtual void VirtualFunction26();
    virtual void VirtualFunction27();
    virtual void VirtualFunction28();
    virtual void VirtualFunction29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void reserved35();
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void reserved47();
    virtual void reserved48();
    virtual void reserved49();
    virtual void reserved50();
    virtual void reserved51();
    virtual void reserved52();
    virtual void reserved53();
    virtual void reserved54();
    virtual void reserved55();
    virtual void reserved56();
    virtual void reserved57();
    virtual void reserved58();
    virtual void reserved59();
    virtual void reserved60();
    virtual void reserved61();
    virtual void reserved62();
    virtual void reserved63();
    virtual void reserved64();
    virtual void reserved65();
    virtual void reserved66();
    virtual void reserved67();
    virtual void reserved68();
    virtual void reserved69();
    virtual void reserved70();
    virtual void reserved71();
    virtual void reserved72();
    virtual void reserved73();
    virtual void reserved74();
    virtual void reserved75();
    virtual const char* Name();
    bool Deleted();
    int Ready();
    BatchRegions* Regions(bool);
    bool Interior();
    int GridX();
    int GridY();
    void Prepare();
    void InteriorPosition(BatchPoint*, BatchPoint*);
    BatchTerrain* Terrain(BatchPoint*, float*);
    BatchWorld* World();
    BatchPortal* Portals();
    int Lights();
};
struct BatchWorld
{
    float GetMinX();
    float GetMinY();
    float GetMaxX();
    float GetMaxWorldY();
    BatchCell* Cell(int, int);
};
struct BatchWorldNode
{
    BatchWorld** Data();
    BatchWorldNode* Next();
};
struct BatchDestination
{
    BatchWorld* world;
    BatchCell* cell;
    BatchPoint position;
    BatchPoint angle;
    bool enabled;
    char unk21, unk22, unk23;
    int unk24, unk28, unk2c, unk30;
    BatchDestination();
};
struct BatchPlayer
{
    const BatchPoint& Angle();
    BatchWorld* World();
    void Move(BatchDestination*);
    void FinishMove();
};
struct BatchIO
{
    void Wait();
};
struct BatchCalendar
{
    void Update(float);
};
struct BatchSave
{
    void Update(int);
};
struct BatchProcess
{
    unsigned int Count();
};
struct BatchMemory
{
    unsigned int Size();
    BatchMemory* Next();
};
struct BatchTES
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
    char unk50;
    bool active;
    char unk52, unk53;
    void(__cdecl* callback)(BatchCell*, void*);
    void* callbackArg;
    void* region;
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
    BatchWorld* currentWorld;
    void SetCategory(void(__cdecl*)());
    void SetWorld(BatchWorld*);
    void BufferCell(BatchCell*);
    void InteriorMove(BatchCell*, BatchPoint*);
    BatchCell* IsCellInterior();
    void InteriorExit(BatchPoint*);
    void ExteriorMove(BatchPoint*, bool);
    void Refresh(bool, bool);
    void TES_TestAllCells(int mode);
};
extern bool batchInitialized, batchNewWorld, batchLog;
extern int batchMode, batchInputDirection, batchX, batchY, batchExteriorCount;
extern unsigned int batchCellIndex, batchCellCount;
extern const char* batchLogFile;
extern BatchWorldNode* batchWorlds;
extern TESDataHandler* batchHandler;
extern BatchPlayer* batchPlayer;
extern BatchIO* batchIO;
extern BatchTES* batchTES;
extern BatchSave* batchSave;
extern BatchCalendar batchCalendar;
extern BatchProcess batchProcess;
extern BatchPoint batchZero;
void __cdecl BatchCategory();
void __cdecl BatchActive(bool);
int __cdecl BatchOpenLog(const char*);
int __cdecl BatchPrint(const char*, ...);
int __cdecl BatchCompare(const char*, const char*, unsigned int);
int __cdecl BatchClock();
void __cdecl BatchSaveSettings(char*, bool, bool, bool);
void __cdecl BatchSetting(bool);
void __cdecl BatchRestoreSettings(unsigned char*);
void __cdecl BatchStats(float*, float*, bool, bool);
void __cdecl BatchFormat(float, BatchString*, int);
BatchMemory* __cdecl BatchMemoryHead();
int __cdecl BatchMemorySize(BatchMemory*);
void __cdecl BatchFilePrint(const char*, const char*, ...);

// Iterates through batch worlds and cells, moving the player to each and logging performance stats based on the specified mode.
// @fnv 0x004556d0
// src: XBOX_PDB 0x004556d0
void BatchTES::TES_TestAllCells(int mode)
{
    if (mode == 4 || mode == 5 || mode == 9)
        batchInitialized = true;
    switch (mode)
    {
    case 6:
    case 7:
        mode -= 5;
        batchInitialized = true;
        SetCategory(BatchCategory);
        break;
    }
    switch (mode)
    {
    default:
        batchMode = mode;
        active = true;
        BatchActive(true);
        BatchOpenLog(batchLogFile);
        if (!batchInitialized)
        {
            BatchPrint("CELLS: \r\n\r\n**************** Base Object Models ****************");
            batchHandler->SetModelSizeOutputEnabled(false);
            BatchPrint("CELLS: \r\n\r\n**************** Base Object Icons/Textures ****************");
            static_cast<TESDataHandlerIconValidation*>(batchHandler)->ValidateFormIcons();
            batchInitialized = true;
        }
        if ((mode == 1 || mode == 4 || mode == 5 || mode == 9) && !batchWorlds && !batchCellCount)
        {
            batchWorlds = (BatchWorldNode*)batchHandler->GetTESWorldSpaceList();
            batchNewWorld = true;
            batchHandler->RefreshCellList();
            batchCellCount = batchHandler->GetInteriorCellCount();
            batchCellIndex = 0;
        }
        else if (mode == 3)
        {
            if (!batchWorlds || *batchWorlds->Data() != currentWorld)
            {
                batchWorlds = (BatchWorldNode*)batchHandler->GetTESWorldSpaceList();
                while (batchWorlds)
                {
                    BatchWorld* world = *batchWorlds->Data();
                    if (world && world == currentWorld)
                        break;
                    batchWorlds = batchWorlds->Next();
                }
            }
            if (batchWorlds)
            {
                batchNewWorld = true;
                batchHandler->RefreshCellList();
                batchCellCount = batchHandler->GetInteriorCellCount();
                batchCellIndex = 0;
            }
        }
        else if (mode == 2)
        {
            bool changed = false;
            if (batchWorlds)
            {
                batchWorlds = 0;
                batchNewWorld = false;
                changed = true;
            }
            if (!batchCellCount)
            {
                batchHandler->RefreshCellList();
                batchCellCount = batchHandler->GetInteriorCellCount();
                batchCellIndex = 0;
                changed = true;
            }
        }
        break;
    case -1:
        active = false;
        BatchActive(false);
        region = 0;
        break;
    case 0:
        break;
    }
    bool again = true;
    while (again)
    {
        again = false;
        if (active)
        {
            if (mode == 9)
                again = true;
            BatchCell* cell = 0;
            int start = BatchClock();
            INPUT input;
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_MOVE;
            input.mi.time = 0;
            input.mi.dy = 0;
            input.mi.mouseData = 0;
            input.mi.dwExtraInfo = 0;
            if (batchInputDirection > 0)
                input.mi.dx = 2;
            else
                input.mi.dx = -1;
            SendInput(1, &input, sizeof(INPUT));
            batchInputDirection = -batchInputDirection;
            if (batchNewWorld)
            {
                if (batchWorlds)
                {
                    BatchWorld* world = *batchWorlds->Data();
                    while (world && !BatchCompare(((BatchCell*)world)->Name(), "test", 4))
                    {
                        batchWorlds = batchWorlds->Next();
                        if (batchWorlds)
                            world = *batchWorlds->Data();
                        else
                            world = 0;
                    }
                    if (world)
                    {
                        SetWorld(world);
                        batchX = ((int)currentWorld->GetMinX()) >> 12;
                        batchY = ((int)currentWorld->GetMinY()) >> 12;
                        int maxX = ((int)currentWorld->GetMaxX()) >> 12;
                        int maxY = ((int)currentWorld->GetMaxWorldY()) >> 12;
                        BatchPrint("CELLS: \r\n\r\n**************** %s (%d,%d) - (%d,%d) ****************",
                                   ((BatchCell*)currentWorld)->Name(), batchX, batchY, maxX, maxY);
                    }
                }
                batchNewWorld = false;
            }
            bool found = false;
            bool done = false;
            while (!found && !batchNewWorld && !done)
            {
                if (batchWorlds)
                {
                    cell = currentWorld->Cell(batchX, batchY);
                    if (cell)
                        BufferCell(cell);
                    batchY++;
                    if (batchY > (((int)currentWorld->GetMaxWorldY()) >> 12))
                    {
                        batchY = ((int)currentWorld->GetMinY()) >> 12;
                        batchX++;
                        if (batchX > (((int)currentWorld->GetMaxX()) >> 12))
                        {
                            batchWorlds = batchWorlds->Next();
                            if (batchWorlds)
                                batchNewWorld = true;
                        }
                    }
                }
                else
                {
                    if (!batchCellIndex)
                        BatchPrint("CELLS: \r\n\r\n**************** Interiors ****************");
                    cell = (BatchCell*)batchHandler->GetCellByInteriorIndex(batchCellIndex);
                    batchCellIndex++;
                    while (cell && !BatchCompare(cell->Name(), "test", 4))
                    {
                        cell = (BatchCell*)batchHandler->GetCellByInteriorIndex(batchCellIndex);
                        batchCellIndex++;
                    }
                    if (!cell)
                        done = true;
                }
                if (cell && !cell->Deleted() && cell->Ready())
                    found = true;
            }
            if (cell && found)
            {
                BatchRegions* regions = cell->Regions(true);
                if (region)
                {
                    if (!regions || !regions->list.Contains(region))
                        found = false;
                }
            }
            else if (batchNewWorld)
            {
                if (batchPlayer->World() != currentWorld)
                    again = true;
            }
            if (found)
            {
                batchCalendar.Update(10.0f);
                BatchPoint position4 = batchZero;
                if (!cell->Interior())
                    position4 = BatchPoint((cell->GridX() << 12) + 2048.0, (cell->GridY() << 12) + 2048.0, 0.0f);
                if (cell->Interior())
                {
                    cell->Prepare();
                    BatchPoint rotation;
                    cell->InteriorPosition(&position4, &rotation);
                    InteriorMove(cell, &position4);
                }
                else if (IsCellInterior())
                {
                    InteriorExit(&position4);
                    float height;
                    cell->Terrain(&position4, &height)->Sample();
                    if (height >= 0.0)
                        position4.z = height;
                }
                else
                {
                    ExteriorMove(&position4, false);
                    float height;
                    cell->Terrain(&position4, &height)->Sample();
                    if (height >= 0.0)
                        position4.z = height;
                }
                BatchDestination* destination5 = new BatchDestination;
                destination5->position = position4;
                destination5->angle = batchPlayer->Angle();
                destination5->enabled = true;
                if (cell->Interior())
                    destination5->cell = cell;
                else
                    destination5->world = cell->World();
                batchPlayer->Move(destination5);
                batchPlayer->FinishMove();
                batchIO->Wait();
                int finish3 = BatchClock();
                float elapsed = (finish3 - start) / 1000.0;
                BatchSettings settings8;
                BatchSaveSettings((char*)&settings8, true, true, true);
                batchTES->Refresh(true, false);
                BatchSetting(settings8.flag5);
                BatchRestoreSettings((unsigned char*)&settings8);
                if (batchLog)
                {
                    float textureCount9 = 0.0f;
                    float modelCountTmp = 0.0f;
                    BatchString modelString2;
                    BatchStats(&textureCount9, &modelCountTmp, true, true);
                    BatchFormat(modelCountTmp, &modelString2, 0);
                    bool portalsVal = false;
                    BatchPortal* graphTmp = cell->Portals();
                    if (graphTmp && !graphTmp->GetList()->Empty())
                        portalsVal = true;
                    unsigned int memory2 = 0;
                    BatchMemory* entry30 = BatchMemoryHead();
                    while (entry30)
                    {
                        if (entry30->Size())
                            memory2 += BatchMemorySize(entry30);
                        entry30 = entry30->Next();
                    }
                    memory2 >>= 20;
                    // The original initializes three diagnostic counters without reading them.
                    int count13 = 0;
                    int numA2 = 0;
                    int numB9 = 0;
                    unsigned int actors3 = batchProcess.Count();
                    if (cell->Interior())
                    {
                        BatchPrint(
                            "CELLS: Cell \"%s\" (Interior) M#: %s T#: %.0f Time: %.1f Lights: %d Portals: %s TexTotal: %i MB Actors: %i",
                            cell->Name(), (const char*)modelString2, textureCount9, elapsed, cell->Lights(),
                            portalsVal ? "Y" : "N", memory2, actors3);
                        BatchFilePrint(batchLogFile, "%s\tInterior\t%s\t%.0f\t%.1f\t%d\t%s\t%d\t%i\r\n", cell->Name(),
                                       (const char*)modelString2, textureCount9, elapsed, cell->Lights(),
                                       portalsVal ? "Y" : "N", memory2, actors3);
                    }
                    else
                    {
                        batchExteriorCount++;
                        BatchPrint(
                            "CELLS: Cell \"%s\" (%d, %d) M#: %s T#: %.0f Time: %.1f Portals: %s TexTotal: %i MB Actors: %i",
                            cell->Name(), cell->GridX(), cell->GridY(), (const char*)modelString2, textureCount9,
                            elapsed, portalsVal ? "Y" : "N", memory2, actors3);
                        BatchFilePrint(batchLogFile, "%s\t%d, %d\t%s\t%.0f\t%.1f\t%s\t%d\t%i\r\n", cell->Name(),
                                       cell->GridX(), cell->GridY(), (const char*)modelString2, textureCount9, elapsed,
                                       portalsVal ? "Y" : "N", memory2, actors3);
                    }
                }
                if (callback)
                    callback(cell, callbackArg);
                if (batchMode == 4 || batchMode == 5)
                    batchSave->Update(batchMode);
            }
            if (batchCellIndex >= batchCellCount)
            {
                batchCellCount = 0;
                active = false;
                BatchActive(false);
                region = 0;
            }
        }
    }
    switch (mode)
    {}
}


struct SpellNode
{
    SpellItem** FUN_006815c0();
    SpellNode* FUN_00726070();
};
struct SpellList
{
    SpellNode* FUN_00717e50();
};
struct RaceView
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
    SpellList spells;
};

struct ItemEntry
{
    TESBoundObject* FUN_0044ddc0();
    void* FUN_004459e0(bool);
};

TESForm* FUN_0058db10(int);
// These two operations are absent from Actor.h; inherit its shared storage.
struct ActorSpellView : public Actor
{
    bool HandleRef(ItemEntry*);
    void UpdateSpells(bool equipped);
};
// Adds actor and race spells when unequipped, applies qualifying inventory enchantments when equipped, and adds the default spell if absent.
// @fnv 0x008c26e0
void ActorSpellView::UpdateSpells(bool equipped)
{
    ItemEntry* released7;
    ItemEntry* releasedA;
    SpellItem* defaultSpell2;
    int previous9;
    bool found5;
    ItemEntry* pEntry7;
    SpellItem* enchantment4;
    TESEnchantableForm* enchantable5;
    int clearIndexA;
    int clearIndex6;
    InventoryChanges* _pChangeNode;
    TESBoundObject* seen8[20];
    SpellItem* spell4;
    SpellItem* pSpell;
    SpellNode* node;
    TESForm* aDefaultForm5;

    if (!equipped)
    {
        node = reinterpret_cast<SpellList*>(reinterpret_cast<char*>(GetActorBase()) +
            (offsetof(TESActorBase, spellList) - offsetof(TESSpellList, spellList)))->FUN_00717e50();
        while (node)
        {
            pSpell = *node->FUN_006815c0();
            if (pSpell)
            {
                CastSpellOnCaster(pSpell, true);
                CastSpellAtTarget(pSpell, this, true);
            }
            node = node->FUN_00726070();
        }
        node = GetRace() ? reinterpret_cast<RaceView*>(GetRace())->spells.FUN_00717e50() : 0;
        while (node)
        {
            spell4 = *node->FUN_006815c0();
            if (spell4)
            {
                CastSpellOnCaster(spell4, true);
                CastSpellAtTarget(spell4, this, true);
            }
            node = node->FUN_00726070();
        }
    }
    else
    {
        _pChangeNode = InventoryChanges::GetOrAddInventoryChanges(this);

        for (clearIndex6 = 0; clearIndex6 < 20; ++clearIndex6)
            seen8[clearIndex6] = 0;
        for (clearIndexA = 0; clearIndexA < 20; ++clearIndexA)
        {
            pEntry7 = (ItemEntry*)_pChangeNode->GetInventoryEntryData(clearIndexA, false);
            enchantable5 = pEntry7 ? dynamic_cast<TESEnchantableForm*>(pEntry7->FUN_0044ddc0()) : 0;
            enchantment4 = enchantable5 ? (SpellItem*)enchantable5->GetEnchantment() : 0;
            if (enchantment4)
            {
                found5 = false;
                for (previous9 = 0; previous9 < clearIndexA && !found5; ++previous9)
                    found5 = seen8[previous9] && seen8[previous9] == pEntry7->FUN_0044ddc0();
                if (!found5 && HandleRef(pEntry7))
                {
                    CastMagicItemOnObject(enchantment4, pEntry7->FUN_0044ddc0(), true);
                    seen8[clearIndexA] = pEntry7->FUN_0044ddc0();
                }
            }
            {
                released7 = pEntry7;
                releasedA = released7;
                releasedA ? releasedA->FUN_004459e0(true) : 0;
            }
        }
    }
    aDefaultForm5 = FUN_0058db10(19);
    if (aDefaultForm5)
    {
        defaultSpell2 = dynamic_cast<SpellItem*>(aDefaultForm5);
        if (defaultSpell2 && !HasSpell(defaultSpell2, true))
            CastSpellOnCaster(defaultSpell2, true);
    }
}

namespace fnv_0045a370 {


extern "C" SettingT_GameSettingCollection_ DAT_011d14c4;
extern "C" SettingT_GameSettingCollection_ DAT_011cebb0;
extern "C" SettingT_GameSettingCollection_ DAT_011d12c0;
extern "C" SettingT_GameSettingCollection_ DAT_011d0ce4;
extern "C" SettingT_GameSettingCollection_ DAT_011cfd40;
struct QueueHelper
{
    void ModelLoader_QueueModel_00444040(const char*, int, int, int, bool, bool, bool);
};
extern "C" QueueHelper* DAT_011c3b3c;
int __cdecl BSsprintf(char*, int, const char*, ...);
struct TextureLoader
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
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    void* texture;
    void FUN_004568c0(const char*, void**, bool, bool);
    void TES_PreloadDefaultModels();
};
// Queues each nonempty setting string and loads a texture using a path built under Data\Textures.
// @fnv 0x0045a370
// src: COMMUNITY 0x0045a370
void TextureLoader::TES_PreloadDefaultModels()
{
    AutoMemHelper context(7, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 7152);
    if (*DAT_011d14c4.String())
        DAT_011c3b3c->ModelLoader_QueueModel_00444040(DAT_011d14c4.String(), 5, 0, 0, true, true, false);
    if (*DAT_011cebb0.String())
        DAT_011c3b3c->ModelLoader_QueueModel_00444040(DAT_011cebb0.String(), 5, 0, 0, true, true, false);
    if (*DAT_011d12c0.String())
        DAT_011c3b3c->ModelLoader_QueueModel_00444040(DAT_011d12c0.String(), 5, 0, 0, true, true, false);
    if (*DAT_011d0ce4.String())
        DAT_011c3b3c->ModelLoader_QueueModel_00444040(DAT_011d0ce4.String(), 5, 0, 0, true, true, false);
    if (*DAT_011cfd40.String())
    {
        char path[260];
        BSsprintf(path, 260, "%s\\%s\\%s", "Data", "Textures", DAT_011cfd40.String());
        FUN_004568c0(path, &texture, false, false);
    }
}
}  // namespace fnv_0045a370

namespace fnv_00454c20 {
struct RecentLimit
{
    unsigned int FUN_004503f0();
};
extern RecentLimit DAT_011c3e38;
extern TESDataHandler* DAT_011c3f2c;
struct RecentItems
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
    void** items;
    bool ContainsCell(void*);
    void TES_AddToInteriorBuffer(void*);
};
// Moves item to the front of items, shifting entries down and releasing the last entry when it is non-null.
// @fnv 0x00454c20
// src: XBOX_PDB 0x00454c20
void RecentItems::TES_AddToInteriorBuffer(void* item)
{
    int last;
    if (ContainsCell(item))
    {
        for (unsigned int index = 0; index < DAT_011c3e38.FUN_004503f0(); index++)
        {
            if (items[index] == item)
            {
                while (index != 0)
                {
                    items[index] = items[index - 1];
                    index--;
                }
                items[0] = item;
                break;
            }
        }
    }
    else
    {
        last = DAT_011c3e38.FUN_004503f0() - 1;
        for (int slot = last; slot >= 0; slot--)
        {
            if (slot == last && items[slot])
            {
                DAT_011c3f2c->RemoveCell((TESObjectCELL*)items[slot]);
            }
            if (slot != 0)
            {
                items[slot] = items[slot - 1];
            }
            else
            {
                items[slot] = 0;
            }
        }
        items[0] = item;
    }
}
}  // namespace fnv_00454c20

namespace fnv_0062f460 {
struct FUN_0062e780_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    float maximum;
    int dimension;
    int originX, originY;
};
FUN_0062e780_Class* __cdecl TESWaterListener_GetExteriorListener();
struct GridCell
{
    TESObjectCELL* cell;
};
struct GridCalls
{
    GridCell* GetGridCell_00457050(int, int);
};
extern TES* g_TES;
struct FUN_0062e710_shell
{
    void SetValueAt(float, int, int);
};
struct FUN_005471e0_shell
{
    float TESObjectCELL_GetWaterHeight();
};
struct CellCoords
{
    int FUN_00544c30();
    int FUN_00544c60();
};
struct FUN_004036b0_Class
{
    unsigned int TES_QPlaceableWaterCount();
};
struct bhkEntityListener_shell
{
    void ModifierList_SetZeroValuesAllowed(bool);
};
extern const float DAT_01015f5c;
extern double DAT_010241b0;
// @fnv 0x0062f460
// src: XBOX_PDB 0x0062f460
void __cdecl TESWaterListener_RefreshExteriorWaterHeights()
{
    FUN_0062e780_Class* width = TESWaterListener_GetExteriorListener();
    width->maximum = DAT_01015f5c;
    int height = width->dimension;
    int first = width->dimension;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < first; y++)
        {
            float value = DAT_01015f5c;
            TESObjectCELL* cell = ((GridCalls*)g_TES)->GetGridCell_00457050(x, y)->cell;
            if (cell && ((TESObjectCELL*)cell)->HasWater())
                value = ((FUN_005471e0_shell*)cell)->TESObjectCELL_GetWaterHeight();
            ((FUN_0062e710_shell*)width)->SetValueAt(value, x, y);
            if (width->maximum < value)
                width->maximum = value;
        }
    }
    TESObjectCELL* data = ((GridCalls*)g_TES)->GetGridCell_00457050(0, 0)->cell;
    if (data)
    {
        width->originX = ((CellCoords*)data)->FUN_00544c30();
        width->originY = ((CellCoords*)data)->FUN_00544c60();
    }
    if (!((FUN_004036b0_Class*)g_TES)->TES_QPlaceableWaterCount() && width->maximum == DAT_010241b0)
        ((bhkEntityListener_shell*)width)->ModifierList_SetZeroValuesAllowed(false);
}
}  // namespace fnv_0062f460

struct FadeAttachedCell
{
    void TESObjectCELL_UpdateFadeNodes();
};

struct FadeAttachedTES
{
    void* unk00;
    void* unk04;
    GridCellArray* m_pGridCells;

    void TES_UpdateFadeNodesForAttachedCells();
};

// @fnv 0x00459a00
// src: XBOX_PDB 0x00459a00
void FadeAttachedTES::TES_UpdateFadeNodesForAttachedCells()
{
    if (!g_dataHandler)
    {
        return;
    }

    if (reinterpret_cast<CP_008c48d0*>(this)->GetPrevPath() != 0)
    {
        if (reinterpret_cast<CellExt*>(reinterpret_cast<CP_008c48d0*>(this)->GetPrevPath())->IsOutdoorCell())
        {
            reinterpret_cast<FadeAttachedCell*>(reinterpret_cast<CP_008c48d0*>(this)->GetPrevPath())->TESObjectCELL_UpdateFadeNodes();
        }
    }

    unsigned int x = 0;
    for (; x < *g_011c63cc.Int(); ++x)
    {
        unsigned int y = 0;
        for (; y < *g_011c63cc.Int(); ++y)
        {
            void* pgridcell = (m_pGridCells->Get(x, y));
            TESObjectCELL* pcell = reinterpret_cast<TESObjectCELL*>(*reinterpret_cast<void**>(pgridcell));

            if (pcell != 0)
            {
                if (reinterpret_cast<CellExt*>(pcell)->IsOutdoorCell())
                {
                    reinterpret_cast<FadeAttachedCell*>(pcell)->TESObjectCELL_UpdateFadeNodes();
                }
            }
        }
    }
}
