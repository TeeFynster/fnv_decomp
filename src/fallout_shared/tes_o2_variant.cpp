#include "../../include/BGSPlaceableWater.h"
#include "../../include/PlaceableWaterData.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/BSTempNodeManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/MemoryManager.h"
#include "../../include/NP.h"
#include "../../include/NiCamera.h"
#include "../../include/NiRTTI.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/NiTPointerMap.h"

// src/fallout_shared/tes_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tes.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

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
struct NiAVObject;
struct NiPoint3;
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
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESLandTexture;
struct TESLoadScreenType;
struct TESObject;
struct TESObjectANIO;
struct TESObjectCELL;
struct TESFormList;
struct TESObjectREFR;
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
struct TESForm;
struct TESObjectCELL;
struct TESObjectREFR;
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
struct NiAVObject;
struct NiControllerSequence;
struct NiNode;
struct QueuedFile;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESBoundObject;
struct TESModel;
struct TESNPC;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESObjectTREE;
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
struct TESObjectREFR;
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

struct ShaderBufferRecord;
// GetCacheDataMap (0x00b61170) uses unsigned-long keys in tallgrassshaderproperty.cpp; its GetAt (0x00a53c30) is NiTMapBase lookup.
typedef NiTPointerMap<unsigned long, ShaderBufferRecord*> GrassCacheMap;
struct ShaderBufferRecord
{
    char pad[0x30];
    GrassCacheMap map;
};
struct TallGrassShaderProperty
{
    static GrassCacheMap* __cdecl GetCacheDataMap();
};
// @fnv 0x00b617b0
// src: COMMUNITY 0x00b617b0
bool __cdecl _TallGrassShaderProperty_ContainsChunk(char const* a, char const* b)
{
    ShaderBufferRecord* pn = 0;
    if (!TallGrassShaderProperty::GetCacheDataMap()->GetAt(reinterpret_cast<unsigned long>(a), pn))
        return false;
    return pn->map.GetAt(reinterpret_cast<unsigned long>(b), pn);
}

// Release one update lock; when the last lock goes away, process (a budgeted part of) the pending queue
// or flush it, then run the post-update steps.

class C6B540Item;

extern bool g_bC6B540Processing;
extern unsigned int g_uiC6B540MaxPerFrame;

class C6B540Manager
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiLockCount;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    C6B540Item** m_ppkPending;
    unsigned int m_uiPendingCount;

    void ProcessPending(C6B540Item** ppkItems, unsigned int ItemUpdateArray);
    void FlushPending();
    void UpdateA();
    void UpdateB();
    void UpdateC();
    void bhkWorld_StopBatchingAdds(bool bProcess);
};

// @fnv 0x00c6b540
// src: XBOX_PDB 0x00c6b540
void C6B540Manager::bhkWorld_StopBatchingAdds(bool bProcess)
{
    if (m_uiLockCount > 0)
    {
        if (--m_uiLockCount == 0)
        {
            if (bProcess)
            {
                if (m_uiPendingCount > 0 && !g_bC6B540Processing)
                {
                    if (m_uiPendingCount >= 3000)
                        m_uiPendingCount = 3000;
                    unsigned int ItemUpdateArray =
                        m_uiPendingCount < g_uiC6B540MaxPerFrame ? m_uiPendingCount : g_uiC6B540MaxPerFrame;
                    unsigned int uiRemaining = m_uiPendingCount - ItemUpdateArray;
                    ProcessPending(&m_ppkPending[uiRemaining], ItemUpdateArray);
                    m_uiPendingCount = uiRemaining;
                    g_bC6B540Processing = true;
                }
            }
            else
            {
                FlushPending();
            }
            UpdateA();
            UpdateB();
            UpdateC();
        }
    }
    else if (m_uiPendingCount > 0 && !bProcess)
    {
        FlushPending();
    }
}

struct QueryStub
{
    unsigned char BSOcclusionQuery_GetResult(unsigned int* state, int flags);
};

void __fastcall ProcessState_00c4ed40(void* p);


extern MemoryManager DAT_011f6238;

struct SlotEntry
{
    void* item;
    unsigned char flag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
    int unk10;
};

struct HolderNode
{
    int unk00;
    int unk04;
    void* holder;
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* item;
};

inline void* const& NextHolder(HolderNode*& pos)
{
    void* const& element = pos->holder;
    pos = (HolderNode*)pos->unk00;
    return element;
}

struct FUN_00b631d0_cls
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
    unsigned char m_flag40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    SlotEntry m_entries[3];
    int unk84;
    unsigned short m_88;
    unsigned short m_uiItemCount;
    void** m_ppData;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    void* m_kNode;
    int unk144;
    int m_listCount;
    void BSShaderAccumulator_ClearAllQueries();
};

// @fnv 0x00b631d0
// src: XBOX_PDB 0x00b631d0
void FUN_00b631d0_cls::BSShaderAccumulator_ClearAllQueries()
{
    unsigned int state;
    int i = 0;
    while (i < m_uiItemCount)
    {
        if (m_ppData[i] != 0)
        {
            ((QueryStub*)m_ppData[i])->BSOcclusionQuery_GetResult(&state, 1);

            void* item = m_ppData[i];
            if (item != 0)
            {
                ProcessState_00c4ed40(item);
                DAT_011f6238.Deallocate(item);
            }

            m_ppData[i] = 0;
        }
        ++i;
    }

    SlotEntry* entry = m_entries;
    int remaining = 3;
    do
    {
        if (entry->item != 0)
        {
            ((QueryStub*)entry->item)->BSOcclusionQuery_GetResult(&state, 1);
            void* item = entry->item;
            if (item != 0)
            {
                ProcessState_00c4ed40(item);
                DAT_011f6238.Deallocate(item);
            }
            entry->item = 0;
            entry->flag = 0;
        }
        ++entry;
        --remaining;
    } while (remaining != 0);

    m_flag40 = 0;
    HolderNode* node = (HolderNode*)m_kNode;
    while (m_listCount != 0)
    {
        Holder* holder = (Holder*)NextHolder(node);
        if (holder != 0 && holder->item != 0)
        {
            ((QueryStub*)holder->item)->BSOcclusionQuery_GetResult(&state, 1);
            void* item = holder->item;
            if (item != 0)
            {
                ProcessState_00c4ed40(item);
                DAT_011f6238.Deallocate(item);
            }
            holder->item = 0;
        }
    }

    void** array = m_ppData;
    m_88 = 0;
    m_uiItemCount = 0;
    DAT_011f6238.Deallocate(array);
    m_ppData = 0;
}

struct Item
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
    int type;
};
struct Ref
{
    Item* ptr;
    Ref(Item*);
    ~Ref();
};
struct List
{
    int head;
    int tail;
    int count;
    void FUN_00c1b4a0(const Ref&);
    Ref FUN_00b9fcc0(const Ref&);
};
struct Node
{
    Node* next;
    Node* prev;
    Item** data;
};
struct S00b6da10_Other
{
    __declspec(noalias) void* NiTPointerListBase_AddTail(Item** const&);
};
struct Pending
{
    Node* head;
    Node* tail;
    int count;
    __declspec(noalias) void FUN_00e7d7f0(Node* const&);
    __forceinline void Find(Item* item, Node*& pos, Item**& found)
    {
        while (pos)
        {
            if (found)
                return;
            if (*pos->data == item)
                found = pos->data;
            else
                pos = pos->next;
        }
    }
};
struct Manager
{
    List list0;
    List list1;
    List list2;
    List list3;
    List list4;
    List dest0;
    List dest1;
    List dest2;
    List dest3;
    List dest4;
    S00b6da10_Other other;
    int o4;
    int o8;
    Pending pending;
    void BSTextureManager_ReturnRenderedTexture(Item* item);
    template <int N> static __forceinline void ProcT(List& l, List& d, Item* p)
    {
        {
            Ref tmp(p);
            l.FUN_00c1b4a0(tmp);
        }
        {
            Ref tmp(p);
            d.FUN_00b9fcc0(tmp);
        }
    }
    __forceinline void Purge(Item* item, Node* pos, Item** found)
    {
        pending.Find(item, pos, found);
        if (found)
        {
            other.NiTPointerListBase_AddTail(found);
            pending.FUN_00e7d7f0(pos);
        }
    }
    static __forceinline void Proc(List& l, List& d, Item* p)
    {
        {
            Ref tmp(p);
            l.FUN_00c1b4a0(tmp);
        }
        {
            Ref tmp(p);
            d.FUN_00b9fcc0(tmp);
        }
    }
};
// @fnv 0x00b6da10
// src: XBOX_PDB 0x00b6da10
void Manager::BSTextureManager_ReturnRenderedTexture(Item* item)
{
    if (item)
    {
        if (item->type > -1)
        {
            switch (item->type)
            {
            case 43: {
                {
                    Ref tmp(item);
                    list0.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest0.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 17: {
                {
                    Ref tmp(item);
                    list1.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest1.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 9: {
                {
                    Ref tmp(item);
                    list2.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest2.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 22: {
                {
                    Ref tmp(item);
                    list3.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest3.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 19: {
                {
                    Ref tmp(item);
                    list4.FUN_00c1b4a0(tmp);
                }
                {
                    Ref tmp(item);
                    dest4.FUN_00b9fcc0(tmp);
                }
                break;
            }
            }
        }
        else
        {
            Item** found = 0;
            Node* pos = pending.head;
            pending.Find(item, pos, found);
            if (found)
            {
                other.NiTPointerListBase_AddTail(found);
                pending.FUN_00e7d7f0(pos);
            }
        }
    }
}
