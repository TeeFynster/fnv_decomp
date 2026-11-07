// fallout_shared/modelloader.cpp: DelStandIn, QueuedTreeModel, ModelLoader, QueuedHelmet and more (493 functions)

#include "../../include/BSFileEntry.h"
#include "../../include/BSFaceGenManager.h"
#include "../../include/BSTreeManager.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/Archive.h"
#include "../../include/Setting.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSEquipType.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/BGSRepairItemList.h"
#include "../../include/BGSTerrainChunkLoadTask.h"
#include "../../include/IOManager.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESModelRDT.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectARMA.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESObjectCLOT.h"
#include "../../include/TESObjectWEAP.h"

// Avoid a shared declaration colliding with MSVC's generated constructor helper.
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/IOTask.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiNode.h"
#include "../../include/NiObject.h"
#include "../../include/TESObjectANIO.h"
#include "../../include/QueuedFile.h"
#include "../../include/QueuedKF.h"
#include "../../include/QueuedModel.h"
#include "../../include/QueuedReference.h"
#include "../../include/QueuedTexture.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESIcon.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObject.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSpellList.h"
#include "../../include/TESTexture.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"
#include "../../include/BIPED_OBJECT.h"
#include "../../include/MEM_CONTEXT.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/AutoMemContext.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/BSAudio.h"
#include "../../include/BSAudioManager.h"
#include "../../include/FormChangeMask.h"
#include "../../include/BSFaceGenModel.h"
#include "../../include/BSFile.h"
#include "../../include/FileEntryList.h"
#include "../../include/GridArray.h"
#include "../../include/GO.h"
#include "../../include/InventoryChanges.h"
#include "../../include/InterfacedClass.h"
#include "../../include/NP.h"
#include "../../include/NiFile.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiStream.h"
#include "../../include/BSStream.h"
#include "../../include/NiRefObject.h"
#include "../../include/RecursiveLock.h"
#include "../../include/RecursiveSpinLock.h"
#include "../../include/hkpTypedBroadPhaseHandle.h"
#include "../../include/NiMemObject.h"
#include "../../include/BGSTouchSpellForm.h"
#include "../../include/CountingSemaphore.h"
#include "../../include/ProcessLists.h"
#include "../../include/InterfaceManager.h"
#include "../../include/BSXFlags.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/BGSAddonNode.h"
#include "../../include/TESPackage.h"
#include "../../include/BSSimpleList.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/BSStringT.h"

#include "../../include/BSFaceGenModelExtraData.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSOcclusionPlane.h"

#include "../../include/EffectSetting.h"
#include "../../include/ExtraDataList.h"
#include "../../include/ExtraDismemberedLimbs.h"
#include "../../include/MiddleHighProcess.h"
#include "../../include/NiSortAdjustNode.h"
#include "../../include/QueuedChildren.h"
#include "../../include/TES.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESContainer.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFile.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESRaceForm.h"
#include "../../include/Tile.h"
#include "../../include/Actor.h"
#include "../../include/Creature.h"
#include "../../include/TESCreature.h"
#include "../../include/AttachDistant3DTask.h"
#include "../../include/BGSTextureSet.h"
#include "../../include/QueuedActor.h"
#include "../../include/QueuedFaceGenFile.h"
#include "../../include/QueuedFileEntry.h"
#include "../../include/QueuedFileLoad.h"
#include "../../include/QueuedHelmet.h"
#include "../../include/QueuedMagicItem.h"
#include "../../include/QueuedReplacementKF.h"
#include "../../include/QueuedReplacementKFList.h"
#include "../../include/QueuedTreeBillboard.h"
#include "../../include/QueuedTreeModel.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESNPC.h"
#include "../../include/TESObjectTREE.h"

#include "../../include/TESRace.h"


// Keep this unit's partial support declarations distinct from shared dependencies.

// The unit's own declarations (formerly the modelloader_verified_packet.h text): ModelLoader, Model, ArchiveManager and more
#ifndef FNV_MODELLOADER_VERIFIED_PACKET_H
#define FNV_MODELLOADER_VERIFIED_PACKET_H




class BGSPerkEntry;
class BSStream;

struct NiPoint3;


#include "../../include/ARCHIVE_TYPE.h"

#include "../../include/IO_TASK_PRIORITY.h"

class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
};

class ArchiveManager
{
  public:
    // External archive-index helper (0x0043c030), not yet declared by Archive.h.
    unsigned int FindArchiveForFileEntry();
    static Archive* FindArchiveForFileEntry(BSFileEntry*, ARCHIVE_TYPE);
};






class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};

// Retained: include/ModelLoader.h does not exist. External operations share this receiver.
class Model;
template <class T> struct NiPointer;
namespace fnv_0043baf0 { struct FUN_0043baf0; }
class Task43E;
class ModelLoader
{
  public:
    bool EnqueueFile(const char*, IO_TASK_PRIORITY, QueuedFile*);
    bool DispatchVirtualCall(char*, fnv_0043baf0::FUN_0043baf0*);
    void ForwardToVTableSlot(BSFileEntry*);
    bool GetModel(char*, NiPointer<Model>&);
    void LoadModel(const char*, NiPointer<Model>&);
    void ProcessModelRequest(TESModel*, int, Task43E*, int, bool, int, int);
    void QueueFileList(BSSimpleList<const char*>*, IO_TASK_PRIORITY, QueuedFile*, const char*);
    void ProcessQueuedFile();
    static void UpdateLoadingStatusCallback();
    void UpdateLoadingStatus();
    void DispatchAnimIdle(QueuedFile*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    void ForwardCall_004431d0();
    void ForwardCall_00443220();
    void Object_SetVirtualTable_00449940();
    void Object_SetVirtualTable_004499a0();
};


// Retained: include/Model.h does not exist.
class Model
{
  public:
    void* owned;
    char prefix[8];
    NiPointer<NiNode> node;
    Model(const char*, BSStream*, bool, bool);
    ~Model();
    void LoadModelFromStream(const char*, BSStream*, bool, bool);
    void ReleaseScriptRunLock();
    void AtomicAdd(int);
    NiObject* GetObject3D();
};


struct QueueKFListLocals
{
    void* deletePointer;
    const char* pathToQueue;
    char path[260];
};

// The game's C++-linkage strcat_s wrapper (0x00406d50); named apart from the CRT declaration.
extern int __cdecl ModelLoaderStrcatS(char*, unsigned int, const char*);
extern void __cdecl operator delete(void*);

class InventoryStackRecord;


// IOManager.h does not yet declare these external operations. This declaration-only
// adapter supplies their member-call ABI without duplicating IOManager's layout or vtable.
struct ModelLoaderIOOperations
{
    void IOManager_RequeueTask(void*, int);
    void BSTaskManager_int64_ForceSignal();
    void EffectSetting_SetLight(void*);
    void FUN_004febb0(void*);
    void FUN_00442a80(void*);
    void MobileObject_SetTalkingActivatorRef(void*);
    void FUN_004febd0(void*);
    void SetWaterForm(void*);
};

extern IOManager* DAT_01202d98;
extern ModelLoader* g_modelLoader;

class KFModel;
class NiFixedString;


const NiFixedString& BSXFlags_Tag();
extern NiFixedString* DAT_01202ddc;


// REVIEW PROPOSAL ONLY. Include within the existing modelloader.cpp TU if approved.
// New declaration-only PC types; no existing packet declaration is changed.
// Every data field is sourced in EVIDENCE.md; no community implementation is copied.
#ifndef FNV_MODELLOADER_SELECTOR_SAME_TU_DECLARATIONS_H
#define FNV_MODELLOADER_SELECTOR_SAME_TU_DECLARATIONS_H
#include <stddef.h>

struct ModInfo;
class BoundObjectListHead;
class Script;
class EnchantmentItem;
class TESSound;
class BGSListForm;
struct DestructibleData;
// Existing NiNode and TESObjectREFR declarations come from modelloader_packet.h.


#include "../../include/ENUM_FORM_ID.h"





















// C++03 compile-time layout checks. No pragma or packing override.
typedef char selector_size_check_3[(sizeof(BaseFormComponent) == 0x4) ? 1 : -1];
typedef char selector_size_check_4[(sizeof(TESForm) == 0x18) ? 1 : -1];
typedef char selector_size_check_5[(sizeof(TESObject) == 0x18) ? 1 : -1];
typedef char selector_size_check_6[(sizeof(TESBoundObject) == 0x30) ? 1 : -1];
typedef char selector_size_check_7[(sizeof(TESFullName) == 0xc) ? 1 : -1];
typedef char selector_size_check_8[(sizeof(TESTexture) == 0xc) ? 1 : -1];
typedef char selector_size_check_9[(sizeof(TESIcon) == 0xc) ? 1 : -1];
typedef char selector_size_check_10[(sizeof(TESScriptableForm) == 0xc) ? 1 : -1];
typedef char selector_size_check_11[(sizeof(BGSMessageIcon) == 0x10) ? 1 : -1];
typedef char selector_size_check_12[(sizeof(TESValueForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_13[(sizeof(TESEnchantableForm) == 0x10) ? 1 : -1];
typedef char selector_size_check_14[(sizeof(TESWeightForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_15[(sizeof(TESHealthForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_16[(sizeof(TESModel) == 0x18) ? 1 : -1];
typedef char selector_size_check_17[(sizeof(TESModelTextureSwap) == 0x20) ? 1 : -1];
typedef char selector_size_check_18[(sizeof(BGSDestructibleObjectForm) == 0x8) ? 1 : -1];
typedef char selector_size_check_19[(sizeof(BGSPickupPutdownSounds) == 0xc) ? 1 : -1];
typedef char selector_size_check_20[(sizeof(BGSRepairItemList) == 0x8) ? 1 : -1];
typedef char selector_size_check_21[(sizeof(BGSEquipType) == 0x8) ? 1 : -1];
typedef char selector_size_check_22[(sizeof(BGSBipedModelList) == 0x8) ? 1 : -1];
typedef char selector_size_check_23[(sizeof(TESModelRDT) == 0x18) ? 1 : -1];
typedef char selector_size_check_24[(sizeof(TESBipedModelForm) == 0xdc) ? 1 : -1];
typedef char selector_size_check_25[(sizeof(TESObjectARMO) == 0x190) ? 1 : -1];
typedef char selector_size_check_26[(sizeof(TESObjectARMA) == 0x190) ? 1 : -1];
typedef char selector_size_check_27[(sizeof(TESObjectCLOT) == 0x154) ? 1 : -1];
typedef char selector_offset_check_0[(offsetof(TESForm, cFormType) == 0x4) ? 1 : -1];
typedef char selector_offset_check_1[(offsetof(TESForm, iFormFlags) == 0x8) ? 1 : -1];
typedef char selector_offset_check_2[(offsetof(TESForm, iFormID) == 0xc) ? 1 : -1];
typedef char selector_offset_check_3[(offsetof(TESForm, m_kSourceFiles) == 0x10) ? 1 : -1];
typedef char selector_offset_check_4[((offsetof(TESBoundObject, unk18) + 0) == 0x18) ? 1 : -1];
typedef char selector_offset_check_5[((offsetof(TESBoundObject, unk18) + 4) == 0x1c) ? 1 : -1];
typedef char selector_offset_check_6[((offsetof(TESBoundObject, unk18) + 8) == 0x20) ? 1 : -1];
typedef char selector_offset_check_7[(offsetof(TESBoundObject, TESBoundObjectBounds) == 0x24) ? 1 : -1];
typedef char selector_offset_check_8[(offsetof(TESModelTextureSwap, textureList) == 0x18) ? 1 : -1];
typedef char selector_offset_check_9[(offsetof(TESBipedModelForm, partMask) == 0x4) ? 1 : -1];
typedef char selector_offset_check_10[(offsetof(TESBipedModelForm, bipedFlags) == 0x8) ? 1 : -1];
typedef char selector_offset_check_11[(offsetof(TESBipedModelForm, bipedModel) == 0xc) ? 1 : -1];
typedef char selector_offset_check_12[(offsetof(TESBipedModelForm, groundModel) == 0x4c) ? 1 : -1];
typedef char selector_offset_check_13[(offsetof(TESBipedModelForm, icon) == 0x8c) ? 1 : -1];
typedef char selector_offset_check_14[(offsetof(TESBipedModelForm, messageIcon) == 0xa4) ? 1 : -1];
typedef char selector_offset_check_15[(offsetof(TESBipedModelForm, modelRDT) == 0xc4) ? 1 : -1];
typedef char selector_offset_check_16[((offsetof(TESObjectARMO, partMask) - offsetof(TESBipedModelForm, partMask)) == 0x70) ? 1 : -1];
typedef char selector_offset_check_17[((offsetof(TESObjectARMO, pData) - offsetof(BGSDestructibleObjectForm, pData)) == 0x14c) ? 1 : -1];
typedef char selector_offset_check_18[((offsetof(TESObjectARMO, data) + offsetof(ArmorData, cFlags)) == 0x180) ? 1 : -1];
typedef char selector_offset_check_19[((offsetof(TESObjectARMO, flags)) == 0x184) ? 1 : -1];
typedef char selector_offset_check_20[((offsetof(TESObjectARMA, partMask) - offsetof(TESBipedModelForm, partMask)) == 0x70) ? 1 : -1];
typedef char selector_offset_check_21[((offsetof(TESObjectARMA, data)) == 0x178) ? 1 : -1];
typedef char selector_offset_check_22[((offsetof(TESObjectARMA, data) + offsetof(ArmorData, fArmorProtectionValue)) == 0x17c) ? 1 : -1];
typedef char selector_offset_check_23[((offsetof(TESObjectCLOT, partMask) - offsetof(TESBipedModelForm, partMask)) == 0x68) ? 1 : -1];
typedef char selector_offset_check_24[((offsetof(TESObjectCLOT, pData) - offsetof(BGSDestructibleObjectForm, pData)) == 0x144) ? 1 : -1];
typedef char selector_offset_check_25[((offsetof(TESObjectCLOT, m_eEquipType) - offsetof(BGSEquipType, m_eEquipType)) == 0x14c) ? 1 : -1];

typedef char modelloader_selector_damage_threshold_offset[((offsetof(TESObjectARMO, data) + offsetof(ArmorData, fArmorProtectionValue)) == 0x17C) ? 1 : -1];
typedef char modelloader_selector_texture_size[(sizeof(TESModelTextureSwap::Texture) == 0x88) ? 1 : -1];
#endif


#include "../../include/AnimIdle.h"
#include "../../include/BGSAmmoForm.h"
#include "../../include/BGSClipRoundsForm.h"
#include "../../include/BGSOpenCloseForm.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/NiRenderer.h"
#include "../../include/QueuedAnimIdle.h"
#include "../../include/QueuedHead.h"
#include "../../include/QueuedCharacter.h"
#include "../../include/QueuedPlayer.h"


#endif


#include "../../include/BackgroundCloneThread.h"

// @fnv 0x00441800
void QueuedCharacter::Attach()
{
    QueuedReference::Attach();
}

// @fnv 0x00441c30
void QueuedPlayer::Attach()
{
    QueuedCharacter::Attach();
}

// Returns the archive's file index plus 4 when the queued texture's archive is found, otherwise 0.
// @fnv 0x0043bfe0
unsigned char QueuedTexture::GetFileIndex()
{
    if (GetFileEntry())
    {
        Archive* archive = ArchiveManager::FindArchiveForFileEntry(GetFileEntry(), static_cast<ARCHIVE_TYPE>(2));
        if (archive)
            return reinterpret_cast<ArchiveManager*>(archive)->FindArchiveForFileEntry() + 4;
    }
    return 0;
}

// Returns the archive's file index plus 4 when the archive is found, otherwise returns 1.
// @fnv 0x006fc440
unsigned char BGSTerrainChunkLoadTask::GetFileIndex()
{
    if (GetFileEntry())
    {
        Archive* archive = ArchiveManager::FindArchiveForFileEntry(GetFileEntry(), static_cast<ARCHIVE_TYPE>(1));
        if (archive)
            return reinterpret_cast<ArchiveManager*>(archive)->FindArchiveForFileEntry() + 4;
    }
    return 1;
}

// @fnv 0x00446500
void ModelLoader::QueueFileList(BSSimpleList<const char*>* pFileList, IO_TASK_PRIORITY priority, QueuedFile* queuedFile,
                                const char* prefix)
{
    BSSimpleList<const char*>* current = pFileList;
    while (current)
    {
        const char* fileName = current->GetItem();
        if (fileName)
        {
            QueueKFListLocals locals;
            locals.pathToQueue = fileName;
            if (prefix)
            {
                TaskQueueInterface::CopyStringToBuffer(locals.path, sizeof(locals.path), prefix);
                ModelLoaderStrcatS(locals.path, sizeof(locals.path), fileName);
                locals.pathToQueue = locals.path;
            }
            EnqueueFile(locals.pathToQueue, priority, queuedFile);
            locals.deletePointer = const_cast<char*>(fileName);
            operator delete(locals.deletePointer);
            current->RemoveHead();
        }
        else
        {
            current = reinterpret_cast<BSSimpleList<const char*>*>(
                reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(current)->GetNext());
        }
    }
}

// If the NiPointer<QueuedFile> at offset 0xC is null, calls Signal on the object at that offset.
// @fnv 0x00442600
void ModelLoader::ProcessQueuedFile()
{
    if (!reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0xC)->operator QueuedFile*())
        reinterpret_cast<CountingSemaphore*>(reinterpret_cast<char*>(this) + 0xC)->Signal();
}

// @fnv 0x0043aaf0
Model::Model(const char* fileName, BSStream* stream, bool firstFlag, bool secondFlag) : node(0)
{
    node = 0;
    LoadModelFromStream(fileName, stream, firstFlag, secondFlag);
}

// Clears node, then deletes the owned data pointer and leaves owned unchanged.
// @fnv 0x0043ab70
Model::~Model()
{
    node = 0;
    void* pOwnedData = owned;
    operator delete(pOwnedData);
}

// @fnv 0x00446e30
void ModelLoader::UpdateLoadingStatusCallback()
{
    g_modelLoader->UpdateLoadingStatus();
}

// @fnv 0x0043ca10
void QueuedModel::GenerateKey()
{
    QueuedFileEntry_GenerateKey();
}

// Submits this task through IOManager virtual slot 0x48.
// @fnv 0x00441e10
void QueuedKF::DispatchToManager()
{
    DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(this));
}

// @fnv 0x0043e770
void QueuedAnimIdle::OnChildCompletion()
{
    if (BSTask_int64_GetTaskFinished() && QueuedFile_GetAllChildrenFinished())
        AddToPostProcessQueue();
}

// @fnv 0x0043ec20
void QueuedHead::DispatchToManager()
{
    BSFaceGenManager::QueueHeadModelLoad(*reinterpret_cast<TESNPC**>(reinterpret_cast<char*>(this) + 0x28),
                                         IOTask_GetIOTaskPriority(), this);
    OnChildCompletion();
}

// Retrieves the spell list from the TESSpellList at offset 0x34 and passes it to vfn_30.
// @fnv 0x0043cb10
void QueuedModel::DispatchToManager()
{
    BSSimpleList<InventoryStackRecord*>* list = 0;
    if (*reinterpret_cast<TESSpellList**>(reinterpret_cast<char*>(this) + 0x34))
        list = (*reinterpret_cast<TESSpellList**>(reinterpret_cast<char*>(this) + 0x34))->GetOffsetC();
    reinterpret_cast<void (__thiscall**)(QueuedModel*, BSSimpleList<InventoryStackRecord*>*)>(*reinterpret_cast<void***>(this))[12](this, list);
}

// @fnv 0x0043ec60
void QueuedHead::OnChildCompletion()
{
    if (QueuedFile_GetAllChildrenFinished())
    {
        if (reinterpret_cast<NiTPointerMap<unsigned int, BSSoundHandle*>*>(this)->IsEmpty())
            DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(this));
        else
            NotifyParents();
    }
}

// @fnv 0x0043e7b0
void QueuedAnimIdle::ProcessLoadedAnimIdle()
{
    if (reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x30)->operator QueuedFile*() &&
        !BSTask_int64_GetTaskCanceled())
        reinterpret_cast<AnimIdle*>(
            reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x3c)->operator QueuedFile*())
            ->Loaded(reinterpret_cast<KFModel*>(
                reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x30)
                    ->
                    operator QueuedFile*()));
    g_modelLoader->DispatchAnimIdle(
        reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x3c)->operator QueuedFile*());
}

// @fnv 0x004489b0
void ModelLoader::UpdateReferenceNode(TESObjectREFR* reference, NiNode* node)
{
    if (node)
    {
        NiExtraData* extra = node->GetExtraData(BSXFlags_Tag());
        if (extra && reference)
        {
            NiExtraData* addon = extra;
            if (addon->FUN_00448a40() && !reference->TESForm_GetFireOff())
                UpdateModelNode(node);
        }
    }
}

// @fnv 0x0043ca30
void QueuedModel::OnChildCompletion()
{
    if (!QueuedModel_GetFinishedQueuing())
        NotifyParents();
    else if (QueuedFile_GetAllChildrenFinished())
    {
        if (reinterpret_cast<NiTPointerMap<unsigned int, BSSoundHandle*>*>(this)->IsEmpty())
            DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(this));
        else
            NotifyParents();
    }
}

// @fnv 0x0043c4b0
// src: XBOX_PDB 0x0043c4b0
NiRenderer* NiXenonRenderer_GetRenderer()
{
    return NiRenderer::ms_pRenderer;
}

// @fnv 0x00448a80
// src: XBOX_PDB 0x00448a80
const NiFixedString& BSXFlags_Tag()
{
    return *DAT_01202ddc;
}

// @fnv 0x0043c490
// src: XBOX_PDB 0x0043c490
NiPoint3& NiAVObject::GetTranslate_0043c490()
{
    return *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x58);
}

// @fnv 0x0043c470
// src: GUESS 0x0043c470 (confidence: low)
int NiAVObject::EvaluateValue_0043c470()
{
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3);
}

// @fnv 0x00441b80
// src: GUESS 0x00441b80 (confidence: low)
void QueuedReference::ForwardCall_00441b80()
{
    FUN_004414f0();
}

// @fnv 0x004431d0
// src: GUESS 0x004431d0 (confidence: low)
void ModelLoader::ForwardCall_004431d0()
{
    Object_SetVirtualTable_00449940();
}

// @fnv 0x00443220
// src: GUESS 0x00443220 (confidence: low)
void ModelLoader::ForwardCall_00443220()
{
    Object_SetVirtualTable_004499a0();
}

// @fnv 0x004491f0
NiNode* NiAVObject::GetParentNode()
{
    return GetParent();
}

// @fnv 0x0043cca0
unsigned char IOTask::GetPriorityFromKey(__int64& key)
{
    return static_cast<unsigned char>(key >> 16);
}

// @fnv 0x00448a40
bool BSXFlags::GetAddon() const
{
    return GetFlags(0x10) != 0;
}

// @fnv 0x00444d20
bool BGSSaveLoadGame::GetInitingForms() const
{
    return (iGlobalFlags & 8) ? true : false;
}

// Returns the TESBipedModelForm for an ARMO, ARMA or CLOT form, or null for other or null forms.
// @fnv 0x00480db0
TESBipedModelForm* TESBipedModelForm::GetFormAsBipedModel(const TESForm* form)
{
    TESBipedModelForm* biped = 0;
    if (form)
    {
        switch (form->GetFormType())
        {
        case ENUM_FORM_ID_ARMO_ID: {
            TESObjectARMO* armor = static_cast<TESObjectARMO*>(const_cast<TESForm*>(form));
            biped = static_cast<TESBipedModelForm*>(armor);
            break;
        }
        case ENUM_FORM_ID_ARMA_ID: {
            TESObjectARMA* addon = static_cast<TESObjectARMA*>(const_cast<TESForm*>(form));
            biped = static_cast<TESBipedModelForm*>(addon);
            break;
        }
        case ENUM_FORM_ID_CLOT_ID: {
            TESObjectCLOT* clothing = static_cast<TESObjectCLOT*>(const_cast<TESForm*>(form));
            biped = static_cast<TESBipedModelForm*>(clothing);
            break;
        }
        }
    }
    return biped;
}

// @fnv 0x00448bf0
bool BGSAddonNode::IsMasterParticleSystem() const
{
    // Character-type inspection of the real one-byte bitfield object.
    return (*reinterpret_cast<const unsigned char*>(&kData.m_ucEntryType) & _AddonNodeFlags::IS_MASTER_PARTICLE_SYSTEM)
               ? true
               : false;
}

// @fnv 0x00441b00
bool TESPackage::GetForceUnequipWeapon() const
{
    return (packageFlags & kPackageFlag_WeaponsUnequipped) ? true : false;
}

// @fnv 0x00446390
int TESObjectWEAP::GetWeaponType() const
{
    return static_cast<int>(static_cast<signed char>(data.eType));
}

// @fnv 0x00442a80
void TESObjectACTI::SetActivateSound(TESSound* sound)
{
    m_pLoopSound = sound;
}


int __cdecl BSvsprintf(char*, const char*, char*);


// Formats fmt with args into a 1024-byte buffer via FUN_00407000, stores the result in the string, and returns the formatting result.
// @fnv 0x00406f90
// src: XBOX_PDB 0x00406f90
template <> int BSStringT<char>::VSPrintF(const char* pcFormat, va_list args)
{
    int res = 0;
    char buf[1024];

    res = BSvsprintf(buf, pcFormat, args);
    Set(buf, 0);
    return res;
}

struct FUN_0043acb0_shell : public Model
{
    void ReleaseScriptRunLock();
};

void __cdecl FinishScriptRunLock(void*);

// If the reference count at offset 8 is positive, calls FinishScriptRunLock with that field's address.
// @fnv 0x0043acb0
void FUN_0043acb0_shell::ReleaseScriptRunLock()
{
    if (*(int*)((char*)this + 8) > 0)
        FinishScriptRunLock((char*)this + 8);
}

namespace fnv_0043b1b0 {

typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];

const char* __cdecl NiGlobalStringTable_GetString(const void*);
}  // namespace fnv_0043b1b0

// @fnv 0x0043b1b0
NiFixedString::operator const char*() const
{
    return fnv_0043b1b0::NiGlobalStringTable_GetString(this);
}

int __fastcall _ref_0084e3a0(const void*);

// @fnv 0x0043b1e0
unsigned int BSStream::GetRefAt21C()
{
    return _ref_0084e3a0(reinterpret_cast<const char*>(this) + 0x21c);
}

// Returns the string stored at index i in the arr array.
// @fnv 0x0043b200
NiNode* BSStream::GetStringAt(unsigned int auiIndex)
{
    return reinterpret_cast<NiNode*>(const_cast<char*>(
        static_cast<const char*>(reinterpret_cast<BSSimpleArray<BSStringT<char>, 1024>*>(reinterpret_cast<char*>(this) + 0x21c)->GetAt(auiIndex))));
}

namespace fnv_0043b230 {

// @fnv 0x0043b230
// src: COMMUNITY 0x0043b230
const char* __fastcall NiObjectNET_GetControllers(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x0c);
}
}  // namespace fnv_0043b230

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_0043b4d0_shell : public CFilter
{
    int CFilter_GetLayer();
};

// @fnv 0x0043b4d0
// src: XBOX_PDB 0x0043b4d0
int FUN_0043b4d0_shell::CFilter_GetLayer()
{
    return iFilter & 0x7f;
}

struct Col_0043b4f0
{
    int hkpCollidable_getCollisionFilterInfo();
};
struct W_0043b4f0
{
    Col_0043b4f0* GetSourceFilesFromObject();
    FormChangeMask* bhkWorldObject_GetCollisionFilter(FormChangeMask* result);
};
// @fnv 0x0043b4f0
// Use explicit return storage to preserve the original ABI with the shared mask destructor.
// src: COMMUNITY 0x0043b4f0
FormChangeMask* W_0043b4f0::bhkWorldObject_GetCollisionFilter(FormChangeMask* result)
{
    Col_0043b4f0* pc = GetSourceFilesFromObject();
    result->FormChangeMask::FormChangeMask(pc ? pc->hkpCollidable_getCollisionFilterInfo() : 0);
    return result;
}

unsigned int __fastcall FUN_0044ddc0(void*);

// @fnv 0x0043b540
// src: XBOX_PDB 0x0043b540
unsigned int __fastcall hkpCollidable_getCollisionFilterInfo(char* pThis)
{
    return FUN_0044ddc0((hkpTypedBroadPhaseHandle*)(pThis + 0x14));
}

struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    volatile long iRefCount;  // +0: IncRefCount (0x0044b0f0) increments it under the loader lock
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
typedef char _sizecheck_LoadedFile[sizeof(LoadedFile) == 16 ? 1 : -1];
struct FUN_0043bb80_shell : public LoadedFile
{
    void DestroyLoadedFile();
};

struct _ModelLoaderStub00448370
{
    void ModelLoader_RemoveLoadedFileFromMap(char*);
};

struct _LogStub0043bd00
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(int, const char*, int, int, int);
};

void __cdecl _FNV_Warning(const char*, ...);
int __cdecl _sprintf(char*, const char*, ...);
bool __cdecl IsHeapLoggerPresent();
_LogStub0043bd00* __cdecl BSCoreMessage_GetInstance();

// @fnv 0x0043bb80
void FUN_0043bb80_shell::DestroyLoadedFile()
{
    if (!m_bFileFlagAtOffsetD && m_bFirstFlag)
    {
        _FNV_Warning("LoadedFile %s was loaded at %i and added to the map, but is being thrown away without being used",
                     pFileName, this);
    }
    if (m_bFirstFlag)
    {
        reinterpret_cast<_ModelLoaderStub00448370*>(g_modelLoader)->ModelLoader_RemoveLoadedFileFromMap(pFileName);
    }
    if (*reinterpret_cast<int*>(this) != 0)
    {
        char szMessage[260];
        _sprintf(szMessage, "%s ref object at mem %i being destroyed with %i references\r\n", pFileName, this,
                 *reinterpret_cast<int*>(this));
        if (IsHeapLoggerPresent())
        {
            BSCoreMessage_GetInstance()->vfn_14(4, szMessage, 0, 0, 0);
        }
    }
    delete pFileName;
    delete pFile;
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0043be10
// src: XBOX_PDB 0x0043be10
int __fastcall QueuedChildren_AddFinishedChild(char* pThis)
{
    return InitScriptRunLock(pThis + 0x10);
}

struct FUN_0043bef0 : QueuedFileEntry
{
    GO g;
    char flag;
    FUN_0043bef0(NiNode* n, int a);
    virtual ~FUN_0043bef0();
    void SetFieldCToFive();
};
// @fnv 0x0043bef0
FUN_0043bef0::FUN_0043bef0(NiNode* apNode, int aiArg) : QueuedFileEntry(aiArg), g(0)
{
    flag = 0;
    ((NiPointer<NiNode>*)&g)->operator=(apNode);
    SetFieldCToFive();
}

struct ML_0043c050
{
    bool InsertQueuedTexture(BSFileEntry*, void*);
    bool IsLoadTexturesDegraded();
};
struct Q_0043c050 : public QueuedTexture
{
    bool ForwardByteToMember(bool);
    void QueuedTexture_SetInQueuedTextureMap(bool);
    void QueuedTexture_QueueMe();
};
// @fnv 0x0043c050
// src: XBOX_PDB 0x0043c050
void Q_0043c050::QueuedTexture_QueueMe()
{
    if (GetFileEntry())
    {
        bool bresult = reinterpret_cast<ML_0043c050*>(g_modelLoader)->InsertQueuedTexture(GetFileEntry(), this);
        QueuedTexture_SetInQueuedTextureMap(bresult);
    }
    if (reinterpret_cast<ML_0043c050*>(g_modelLoader)->IsLoadTexturesDegraded())
        ForwardByteToMember(true);
    DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(this));
}

struct FUN_0043c100_shell : public QueuedTexture
{
    void QueuedTexture_SetInQueuedTextureMap(bool);
};

void __cdecl MLSetFlag_4(bool, void*);

// Forwards abValue and the object's field at offset 0x34 to FUN_0044aea0.
// @fnv 0x0043c100
// src: COMMUNITY 0x0043c100
void FUN_0043c100_shell::QueuedTexture_SetInQueuedTextureMap(bool abValue)
{
    MLSetFlag_4(abValue, reinterpret_cast<char*>(this) + 0x34);
}

struct FUN_0043c130_shell : public ModelLoader
{
    bool IsLoadTexturesDegraded();
};

struct TLSData
{
    char _pad[0x25c];
    bool bLoadTexturesDegraded;
};

__declspec(thread) TLSData g_tlsData;

// Returns the thread-local flag that indicates whether textures are being loaded in degraded mode.
// @fnv 0x0043c130
bool FUN_0043c130_shell::IsLoadTexturesDegraded()
{
    return g_tlsData.bLoadTexturesDegraded;
}

struct FUN_0043c3d0_shell : public QueuedTexture
{
    bool QueuedTexture_GetLoadDegraded();
};

bool __cdecl MLGetFlag_2(unsigned char);

// @fnv 0x0043c3d0
// src: COMMUNITY 0x0043c3d0
bool FUN_0043c3d0_shell::QueuedTexture_GetLoadDegraded()
{
    return MLGetFlag_2(*(unsigned char*)((char*)this + 0x34));
}

struct _TLS_0043c3f0
{
    char _pad[0x29c];
    unsigned int val;
};
extern __declspec(thread) _TLS_0043c3f0 _tls_0043c3f0;

// @fnv 0x0043c3f0
// src: COMMUNITY 0x0043c3f0
void __cdecl NiTexture_SetLoadMethod(unsigned int aiLoadMethod)
{
    _tls_0043c3f0.val = aiLoadMethod;
}

// @fnv 0x0043c410
// src: COMMUNITY 0x0043c410
int NiTexture_GetLoadMethod()
{
    static __declspec(thread) int tls_data[0x29c / 4 + 1];
    return tls_data[0x29c / 4];
}

class BSFileEntryMap
{
  public:
    void BSEntryMap_GetAt(NiNode*, NiPointer<NiNode>&);
};
BSFileEntryMap* DAT_011f4468;

// @fnv 0x0043c4c0
void GetNodePointer(NiNode* apNode, NiPointer<NiNode>& apNodePtr)
{
    apNodePtr = 0;
    DAT_011f4468->BSEntryMap_GetAt(apNode, apNodePtr);
}

int __cdecl BSEntryMap_KeyToHashIndex(int);

struct FUN_0043c4f0_shell
{
    void GetByKey(int, int, int);
    void BSEntryMap_GetAt(int a1, int a2);
};

// Computes a value from a1 via FUN_0043c530, then calls GetByKey with that value, a1 and a2.
// @fnv 0x0043c4f0
// src: COMMUNITY 0x0043c4f0
void FUN_0043c4f0_shell::BSEntryMap_GetAt(int a1, int aiArg)
{
    int v = BSEntryMap_KeyToHashIndex(a1);
    GetByKey(v, a1, aiArg);
}

// @fnv 0x0043c530
// src: COMMUNITY 0x0043c530
unsigned int __cdecl BSEntryMap_KeyToHashIndex(unsigned int uiValue)
{
    return (uiValue >> 4) % 1001;
}

struct FUN_0043c610_shell : public QueuedFile
{
    void RunVirtualMethod28();
};

// @fnv 0x0043c610
void FUN_0043c610_shell::RunVirtualMethod28()
{
    (*(void(__thiscall**)(QueuedFile*))(*(int*)this + 0x28))(this);
}

struct FUN_0043c630_shell : public QueuedTexture
{
    bool QueuedTexture_GetInQueuedTextureMap();
};

bool __cdecl MLGetFlag_4(unsigned char);

// @fnv 0x0043c630
// src: COMMUNITY 0x0043c630
bool FUN_0043c630_shell::QueuedTexture_GetInQueuedTextureMap()
{
    return MLGetFlag_4(*((unsigned char*)this + 0x34));
}

void __cdecl SetFlagBit0(unsigned char, void*);

struct FUN_0043c7a0_arg
{
    unsigned char val;
};

// Passes arg.val and the address pThis+0x3c to SetFlagBit0.
// @fnv 0x0043c7a0
// src: XBOX_PDB 0x0043c7a0
void __fastcall QueuedModel_SetPrepareAfterLoad(char* pThis, FUN_0043c7a0_arg aByteArg)
{
    SetFlagBit0(aByteArg.val, pThis + 0x3c);
}

void __cdecl MLSetFlag_2(unsigned char, void*);

struct FUN_0043c7d0_shell
{
    void QueuedModel_SetAddRefCount(unsigned char param_1);
};

// @fnv 0x0043c7d0
// src: XBOX_PDB 0x0043c7d0
void FUN_0043c7d0_shell::QueuedModel_SetAddRefCount(unsigned char aByte)
{
    MLSetFlag_2(aByte, (char*)this + 0x3c);
}

void __fastcall Object_ReleaseReferencedObject_0044b160(void*);

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        Object_ReleaseReferencedObject_0044b160(this);
    }
};

struct FUN_0043c830 : QueuedFileEntry
{
    _Mem_00441d20 m;
    int b;
    ~FUN_0043c830();
};

// Destructor for FUN_0043c830; destroys its _Mem_00441d20 member and QueuedFileEntry base.
// @fnv 0x0043c830
FUN_0043c830::~FUN_0043c830()
{}

struct FUN_0043caa0_shell : public QueuedFile
{
    bool QueuedFile_GetAllChildrenFinished();
};

unsigned int __fastcall FUN_0044ddc0(void*);
unsigned int __fastcall TESMain_GetThread(void*);

// @fnv 0x0043caa0
// src: XBOX_PDB 0x0043caa0
bool FUN_0043caa0_shell::QueuedFile_GetAllChildrenFinished()
{
    return *(void**)((char*)this + 0x20)
               ? FUN_0044ddc0(*(void**)((char*)this + 0x20)) == TESMain_GetThread(*(void**)((char*)this + 0x20))
               : true;
}

struct FUN_0043caf0_shell : public QueuedModel
{
    bool QueuedModel_GetFinishedQueuing();
};

bool __cdecl MLGetFlag_4(unsigned char);

// @fnv 0x0043caf0
// src: XBOX_PDB 0x0043caf0
bool FUN_0043caf0_shell::QueuedModel_GetFinishedQueuing()
{
    return MLGetFlag_4(*((unsigned char*)this + 0x3c));
}

struct FUN_0043cc60_shell : public IOTask
{
    int IOTask_GetIOTaskPriority();
};

unsigned char __fastcall IOTask_GetPriority(void*);

// @fnv 0x0043cc60
// src: XBOX_PDB 0x0043cc60
int FUN_0043cc60_shell::IOTask_GetIOTaskPriority()
{
    return IOTask_GetPriority(this);
}

struct FUN_0043cc80_shell : public IOTask
{
    unsigned char IOTask_GetPriority();
};

// @fnv 0x0043cc80
// src: XBOX_PDB 0x0043cc80
unsigned char FUN_0043cc80_shell::IOTask_GetPriority()
{
    return GetPriorityFromKey(*(__int64*)((char*)this + 0x10));
}

struct FUN_0043ccc0_shell : public QueuedModel
{
    void QueuedModel_SetFinishedQueuing(bool);
};

void __cdecl MLSetFlag_4(bool, void*);

// Passes abValue and the address of the object's 0x3c offset to FUN_0044aea0.
// @fnv 0x0043ccc0
// src: XBOX_PDB 0x0043ccc0
void FUN_0043ccc0_shell::QueuedModel_SetFinishedQueuing(bool abValue)
{
    MLSetFlag_4(abValue, (char*)this + 0x3c);
}

struct FUN_0043cf40_shell : public QueuedModel
{
    bool QueuedModel_GetPrepareAfterLoad();
};

bool __cdecl MLGetFlag_1(unsigned char);

// @fnv 0x0043cf40
// src: COMMUNITY 0x0043cf40
bool FUN_0043cf40_shell::QueuedModel_GetPrepareAfterLoad()
{
    return MLGetFlag_1(*((unsigned char*)this + 0x3c));
}

struct FUN_0043cf60_shell : public QueuedModel
{
    void QueuedModel_SetAlreadyInModelMap(bool);
};

void __cdecl SetFlag8(bool, void*);

// @fnv 0x0043cf60
// src: COMMUNITY 0x0043cf60
void FUN_0043cf60_shell::QueuedModel_SetAlreadyInModelMap(bool abValue)
{
    SetFlag8(abValue, (char*)this + 0x3c);
}

struct FUN_0043cf90_shell : public QueuedModel
{
    bool QueuedModel_GetForceLoad();
};

bool __cdecl Object_IsMask0x10Set(unsigned char);

// @fnv 0x0043cf90
// src: COMMUNITY 0x0043cf90
bool FUN_0043cf90_shell::QueuedModel_GetForceLoad()
{
    return Object_IsMask0x10Set(*((unsigned char*)this + 0x3c));
}

struct FUN_0043cfb0_shell : public QueuedModel
{
    bool QueuedModel_GetFaceGenModel();
};

bool __cdecl Object_IsMask0x20Set(unsigned char);

// @fnv 0x0043cfb0
// src: COMMUNITY 0x0043cfb0
bool FUN_0043cfb0_shell::QueuedModel_GetFaceGenModel()
{
    return Object_IsMask0x20Set(*((unsigned char*)this + 0x3c));
}

struct FUN_0043d490_shell : public QueuedModel
{
    bool QueuedModel_GetAddRefCount();
};

bool __cdecl MLGetFlag_2(unsigned char);

// @fnv 0x0043d490
// src: XBOX_PDB 0x0043d490
bool FUN_0043d490_shell::QueuedModel_GetAddRefCount()
{
    return MLGetFlag_2(*((unsigned char*)this + 0x3c));
}

struct FUN_0043d4b0_shell : public QueuedModel
{
    bool QueuedModel_GetCachedModel();
};

bool __cdecl HasFlag8_0044af20(unsigned char);

// @fnv 0x0043d4b0
// src: COMMUNITY 0x0043d4b0
bool FUN_0043d4b0_shell::QueuedModel_GetCachedModel()
{
    return HasFlag8_0044af20(*((unsigned char*)this + 0x3c));
}

struct FUN_0043dbb0_shell : public IOTask
{
    void SetRequestParams(char, unsigned int, unsigned char, unsigned short);
};

// Packs file index, offset, priority and counter into a 64-bit value stored at offset 0x10 of this object.
// @fnv 0x0043dbb0
void FUN_0043dbb0_shell::SetRequestParams(char acFileIndex, unsigned int aiOffset, unsigned char acPriority,
                                          unsigned short asCounter)
{
    *reinterpret_cast<__int64*>(reinterpret_cast<char*>(this) + 0x10) =
        (static_cast<__int64>(acFileIndex) << 56) | (static_cast<unsigned __int64>(aiOffset) << 24) |
        (static_cast<__int64>(acPriority) << 16) | static_cast<__int64>(asCounter);
}

namespace fnv_0043dc10 {
struct FUN_0043dc10_shell : public IOTask
{
    unsigned short IOTask_GetNextCounter();
};

unsigned short __cdecl InitScriptRunLock(void*);
extern int DAT_01202d9c;

// @fnv 0x0043dc10
// src: XBOX_PDB 0x0043dc10
unsigned short FUN_0043dc10_shell::IOTask_GetNextCounter()
{
    return InitScriptRunLock(&DAT_01202d9c);
}
}  // namespace fnv_0043dc10

struct FUN_0043dc30_shell : public IOTask
{
    unsigned int InitScriptRunLockTask();
};

extern int DAT_01202da0;
int __cdecl InitScriptRunLock(void*);

// @fnv 0x0043dc30
unsigned int FUN_0043dc30_shell::InitScriptRunLockTask()
{
    return InitScriptRunLock(&DAT_01202da0);
}

struct MagicItem;

typedef char _sizecheck_QueuedMagicItem[sizeof(QueuedMagicItem) == 48 ? 1 : -1];

void __fastcall PreloadModels(MagicItem*);
unsigned int __fastcall FUN_0044ddc0(void*);

// @fnv 0x0043e080
void QueuedMagicItem::OnChildCompletion()
{
    if (reinterpret_cast<IOTask*>(this)->BSTask_int64_GetTaskFinished() && reinterpret_cast<IOTask*>(this)->QueuedFile_GetAllChildrenFinished())
    {
        PreloadModels(pMagicItem);
        if (FUN_0044ddc0(this) == 0)
        {
            delete this;
        }
    }
}

namespace fnv_0043e1b0 {
void __fastcall Object_ReleaseReferencedObject_0044b160(void*);

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        Object_ReleaseReferencedObject_0044b160(this);
    }
};

struct FUN_0043e1b0 : QueuedFileEntry
{
    _Mem_00441d20 m;
    int b;
    ~FUN_0043e1b0();
};

// @fnv 0x0043e1b0
FUN_0043e1b0::~FUN_0043e1b0()
{}
}  // namespace fnv_0043e1b0

struct FUN_0043e480_shell : public QueuedKF
{
    void QueuedKF_SetAlreadyInKFMap(bool);
};

void __cdecl SetFlagBit0(bool, void*);

// @fnv 0x0043e480
// src: XBOX_PDB 0x0043e480
void FUN_0043e480_shell::QueuedKF_SetAlreadyInKFMap(bool abValue)
{
    SetFlagBit0(abValue, (char*)this + 0x34);
}

namespace fnv_0043e4b0 {
struct KFModelLookup
{
    KFModel* Lookup(const char*);
};

struct LoaderStandIn : KFModelLookup
{
    unsigned char CallVirtWithLocal(Tile*, const char*);
};
struct QK_0043e4b0
{
    char pad[0x30];
    BSStringT<char> name;
    unsigned char QueuedKF_GetAlreadyInKFMap();
    void RunVirtualMethod28();
    void QueuedKF_Finish();
};
// @fnv 0x0043e4b0
// src: XBOX_PDB 0x0043e4b0
void QK_0043e4b0::QueuedKF_Finish()
{
    if (name && !QueuedKF_GetAlreadyInKFMap() &&
        !reinterpret_cast<LoaderStandIn*>(g_modelLoader)->CallVirtWithLocal(reinterpret_cast<const Tile*>(this)->GetParent(), name))
    {
        reinterpret_cast<NiPointer<KFModel>*>(&name)->operator=(
            reinterpret_cast<LoaderStandIn*>(g_modelLoader)->Lookup(reinterpret_cast<const char*>(reinterpret_cast<const Tile*>(this)->GetParent())));
    }
    RunVirtualMethod28();
}
}  // namespace fnv_0043e4b0

struct FUN_0043e530_shell : public QueuedTexture
{
    bool QueuedKF_GetAlreadyInKFMap();
};

bool __cdecl MLGetFlag_1(unsigned char);

// @fnv 0x0043e530
// src: XBOX_PDB 0x0043e530
bool FUN_0043e530_shell::QueuedKF_GetAlreadyInKFMap()
{
    return MLGetFlag_1(*((unsigned char*)this + 0x34));
}

struct TESObjectANIO;
struct FUN_0043e750_shell : public AnimIdle
{
    TESObjectANIO* GetObjectANIO(int);
};

// @fnv 0x0043e750
TESObjectANIO* FUN_0043e750_shell::GetObjectANIO(int aiIndex)
{
    return ((TESObjectANIO**)((char*)this + 0x1c))[aiIndex];
}

struct FUN_0043e810_shell : public ModelLoader
{
    void DispatchAnimIdle(AnimIdle*);
};

struct Vtbl0043e810
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(AnimIdle*);
};

// Forwards apAnimIdle to the virtual v5 method of the object stored at this+0x10.
// @fnv 0x0043e810
void FUN_0043e810_shell::DispatchAnimIdle(AnimIdle* apAnimIdle)
{
    (*reinterpret_cast<Vtbl0043e810**>(reinterpret_cast<char*>(this) + 0x10))->v5(apAnimIdle);
}

namespace fnv_0043fad0 {

// @fnv 0x0043fad0
// src: XBOX_PDB 0x0043fad0
const char* __fastcall NiGeometry_GetSkinInstance(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0xbc);
}
}  // namespace fnv_0043fad0

extern ProcessLists g_011d5a44;

// @fnv 0x0043faf0
// src: XBOX_PDB 0x0043faf0
unsigned char BSFaceGenManager_GetUseFaceGenHeads()
{
    return *g_011d5a44.GetLifeStateControlFlag();
}

struct FUN_00440490_shell : public NiAVObject
{
    void NiAVObject_SetScale(float);
};

float __cdecl NiAbs_00408820(float);

// Stores the result of FUN_00408820(fScale) into the float at offset 0x64 of this object.
// @fnv 0x00440490
// src: XBOX_PDB 0x00440490
void FUN_00440490_shell::NiAVObject_SetScale(float fScale)
{
    *(float*)((char*)this + 0x64) = NiAbs_00408820(fScale);
}

struct FUN_004405b0_S
{
    void IOTask_SetPriority(unsigned char);
    void IOTask_SetIOTaskPriority(unsigned char p);
};
// @fnv 0x004405b0
// src: COMMUNITY 0x004405b0
void FUN_004405b0_S::IOTask_SetIOTaskPriority(unsigned char p)
{
    IOTask_SetPriority(p);
}

struct QR2;
struct BCT
{
    void BackgroundCloneThread_AddQueuedReference(QR2*);
};
struct FUN_004408d0_S
{
    char pad[0x28];
    BCT* t;
    void ForwardToBCT(QR2* q);
};
// @fnv 0x004408d0
void FUN_004408d0_S::ForwardToBCT(QR2* q)
{
    t->BackgroundCloneThread_AddQueuedReference(q);
}

void __cdecl FinishScriptRunLock(void*);

// @fnv 0x00440a10
void __fastcall FinishScriptRunLockAndReset(char* pThis)
{
    FinishScriptRunLock(pThis + 0xa4);
    if (*reinterpret_cast<int*>(pThis + 0xa4) < 0)
        *reinterpret_cast<int*>(pThis + 0xa4) = 0;
}

void __cdecl FinishScriptRunLock(void*);

// Calls FinishScriptRunLock on pThis+0xa0, then clamps the int at pThis+0xa0 to 0 if it is negative.
// @fnv 0x00440a50
void __fastcall FinishScriptRun(char* pThis)
{
    FinishScriptRunLock(pThis + 0xa0);
    if (*(int*)(pThis + 0xa0) < 0)
    {
        *(int*)(pThis + 0xa0) = 0;
    }
}

extern int DAT_01016ca4;
struct S4411
{
    void FUN_0043fd40(int, int);
    S4411* SetVtableAndProcessState_004411d0(int a, int b);
};
// Calls FUN_0043fd40 with the two arguments, sets the object's first field to point at DAT_01016ca4, and returns this.
// @fnv 0x004411d0
// src: GUESS 0x004411d0 (confidence: low)
S4411* S4411::SetVtableAndProcessState_004411d0(int aiArg1, int aiArg2)
{
    FUN_0043fd40(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &DAT_01016ca4;
    return this;
}

__declspec(thread) char _tls_pad_00441290[0x25c];
__declspec(thread) bool _tls_var_00441290;

struct _FUN_00441290_shell
{
    bool SetTlsFlag(bool bVal);
};

// Stores bVal into the thread-local flag and returns its previous value.
// @fnv 0x00441290
bool _FUN_00441290_shell::SetTlsFlag(bool abValue)
{
    bool bOld = _tls_var_00441290;
    _tls_var_00441290 = abValue;
    return bOld;
}

extern int DAT_01016cec;

struct FUN_004411d0
{
    FUN_004411d0(int, int);
    ~FUN_004411d0();
};

struct GlobalObject_00528cb0
{
    int m_val;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};

struct FUN_00441440 : public FUN_004411d0
{
    void* vftable;
    char pad[0x3c];
    GlobalObject_00528cb0 m_40;
    GlobalObject_00528cb0 m_44;

    FUN_00441440(int a, int b);
};

// Constructs the object: calls the base constructor, sets the vftable to DAT_01016cec, and initializes m_40 and m_44 to 0.
// @fnv 0x00441440
FUN_00441440::FUN_00441440(int a, int b) : FUN_004411d0(a, b), vftable(&DAT_01016cec), m_40(0), m_44(0)
{}

extern __declspec(thread) void* DAT_00441780_264;
extern __declspec(thread) void* DAT_00441780_260;

// Stores apRef and ap3D into the thread-local pointers DAT_00441780_264 and DAT_00441780_260.
// @fnv 0x00441780
// src: COMMUNITY 0x00441780
void __cdecl TESObjectREFR_SetBackgroundLoadingRef(void* apRef, void* ap3D)
{
    DAT_00441780_264 = apRef;
    DAT_00441780_260 = ap3D;
}

struct _TLS_Pad_004417c0
{
    char pad[0x260];
    int v260;
    int v264;
};

__declspec(thread) _TLS_Pad_004417c0 tls_004417c0;

// Clears the two int fields at offsets 0x260 and 0x264 in the thread-local block.
// @fnv 0x004417c0
// src: COMMUNITY 0x004417c0
void TESObjectREFR_ClearBackgroundLoadingRef()
{
    tls_004417c0.v264 = 0;
    tls_004417c0.v260 = 0;
}

#include "../../include/MEM_CONTEXT.h"
struct LightTarget;
struct VATS
{
    LightTarget* VATS_GetVATSLight(void);
};

struct TESAttackDamageForm_1
{
    virtual void Free(void);
};

void __fastcall AttachHeadAndFaceParts(void* pThis);

// Frees the object under a memory context, then calls AttachHeadAndFaceParts if FUN_005d8710 returns null.
// @fnv 0x00441820
// src: XBOX_PDB 0x00441820
void __fastcall QueuedCharacter_FinishAttach(char* apObject)
{
    AutoMemContext tempMemContext(*(MEM_CONTEXT*)(apObject + 0x18), true,
                                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8ff);
    ((TESAttackDamageForm_1*)apObject)->TESAttackDamageForm_1::Free();
    if (!((VATS*)apObject)->VATS_GetVATSLight())
    {
        AttachHeadAndFaceParts(apObject);
    }
}

class ActiveEffect;
class ActorMover;
class AlchemyItem;
struct BGSImpactDataSet;
class BGSLoadFormBuffer;
class BGSPerk;
class BGSPerkEntry;
class BGSSaveFormBuffer;
class BSAnimGroupSequence;
class BSAnimNote;
class BSFaceGenAnimationData;
class BSShaderPPLightingProperty;
class BaseProcess;
class CombatController;
class ActorCombatGroup;
class ContinuousBeamProjectile;
class EffectItem;
class FurnitureMark;
class IDebugText;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class MobileObject;
class PathingAvoidNodeArray;
class PathingLocation;
class PathingRequest;
class Projectile;
class SpellItem;
class TESActorBase;
class TESAmmo;
class TESClass;
class TESCombatStyle;
class TESFaction;
class TESIdleForm;
class TESObjectBOOK;
class TESObjectLIGH;
class TESSkill;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
class TargetEntry;
class TrespassPackage;
class WeaponObject;
class bhkCharacterController;
class bhkRagdollController;
class bhkRigidBody;
class hkpRigidBody;
namespace fnv_004418b0 {


struct Animation;

struct BipedAnimObject;

struct BipedAnim;
struct CombatGroupCollection;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;

struct BooleanFloatQuery;
struct MagicEffectCollection;




struct TrapEntry;
struct bhkRagdollPenetrationUtil;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_004418b0_shell : public QueuedCharacter
{
    void AttachHeadAndFaceParts();
};

struct Biped;


struct TESObjectREFR_Helper
{
    Biped* GetBipedComponent();
};

struct HeadPart_Helper
{
    void Attach(TESObjectREFR* pRefr, Biped* pBiped);
};

struct FacePart_Helper
{
    void Attach();
};

void __fastcall QueuedHead_Attach(const char* pHead, int unused, TESObjectREFR* pRefr, Biped* pBiped);
void __fastcall ApplyQueuedModels(const char* pFace);

// @fnv 0x004418b0
void FUN_004418b0_shell::AttachHeadAndFaceParts()
{
    TESObjectREFR* pcharacter = *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0x28);
    Biped* pbiped = reinterpret_cast<TESObjectREFR_Helper*>(pcharacter)->GetBipedComponent();

    if (static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x40)))
    {
        reinterpret_cast<HeadPart_Helper*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x40))))
            ->Attach(*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0x28), pbiped);
    }

    if (static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x44)))
    {
        reinterpret_cast<FacePart_Helper*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x44))))
            ->Attach();
    }
}
}  // namespace fnv_004418b0

extern int DAT_01016d7c;
struct PlayerCharacter;
extern PlayerCharacter* pPlayer;
struct S1b20
{
    void FUN_00441440(PlayerCharacter*, int);
    S1b20* InitWithPlayer(int a);
};
// Calls FUN_00441440 with pPlayer and a, sets the first field of this to point at DAT_01016d7c, and returns this.
// @fnv 0x00441b20
S1b20* S1b20::InitWithPlayer(int a)
{
    FUN_00441440(pPlayer, a);
    *reinterpret_cast<int**>(this) = &DAT_01016d7c;
    return this;
}

namespace fnv_00441d20 {
void __fastcall Object_ReleaseReferencedObject_0044b160(void*);

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        Object_ReleaseReferencedObject_0044b160(this);
    }
};

struct FUN_00441d20 : QueuedFileEntry
{
    _Mem_00441d20 m;
    int b;
    ~FUN_00441d20();
};

// Destructor: destroys the embedded member and then the base subobject.
// @fnv 0x00441d20
FUN_00441d20::~FUN_00441d20()
{}
}  // namespace fnv_00441d20

struct BSSemaphore_
{
    void Wait();
};

// @fnv 0x004424c0
// src: COMMUNITY 0x004424c0
void __fastcall BSTaskThread_WaitTask(char* this_ptr)
{
    ((BSSemaphore_*)(this_ptr + 0xc))->Wait();
}

struct FUN_00442510_Cl
{
    char pad[0x18];
    CountingSemaphore sem;
    void Wait();
};

// @fnv 0x00442510
// src: COMMUNITY 0x00442510
void __fastcall BSTaskThread_WaitPause(FUN_00442510_Cl* pThis)
{
    reinterpret_cast<void (CountingSemaphore::*)()>(&FUN_00442510_Cl::Wait);
    ((FUN_00442510_Cl*)((char*)pThis + 0x18))->Wait();
}

// @fnv 0x00442530
void __fastcall SignalAtOffset18(char* this_ptr)
{
    ((CountingSemaphore*)(this_ptr + 0x18))->Signal();
}

struct FUN_00442550_shell : public CountingSemaphore
{
    int ReleaseAndInitScriptRunLock();
};

int __cdecl InitScriptRunLock(void*);
__declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount, long* lpPreviousCount);

// Releases the semaphore stored at this+4 by one count, then calls InitScriptRunLock with this and returns its result.
// @fnv 0x00442550
int FUN_00442550_shell::ReleaseAndInitScriptRunLock()
{
    ReleaseSemaphore(*(void**)((char*)this + 4), 1, 0);
    return InitScriptRunLock(this);
}

namespace fnv_00442580 {
struct GlobalObject_00528cb0
{
    int v;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};
struct Sub
{
    void LockFreeQueue_NiPointer_IOTask_Push(GlobalObject_00528cb0*);
};
struct ML2
{
    char pad[0x38];
    Sub* p;
    void ProcessQueuedFile();
    void BackgroundCloneThread_AddQueuedReference(int a);
};
// @fnv 0x00442580
// src: XBOX_PDB 0x00442580
void ML2::BackgroundCloneThread_AddQueuedReference(int a)
{
    {
        GlobalObject_00528cb0 g(a);
        p->LockFreeQueue_NiPointer_IOTask_Push(&g);
    }
    ProcessQueuedFile();
}
}  // namespace fnv_00442580

struct FUN_00443190_shell : public Model
{
    int GetCombinedValue();
};

// @fnv 0x00443190
int FUN_00443190_shell::GetCombinedValue()
{
    return *(int*)((char*)this + 4) + *(int*)((char*)this + 8);
}

// @fnv 0x004431b0
// src: XBOX_PDB 0x004431b0
int __fastcall KFModel_GetRefCount(int* p)
{
    return p[3] + p[4];
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x00444cc0
void __fastcall InitScriptRunLockForObject(char* pThis)
{
    InitScriptRunLock(pThis + 0xa4);
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x00444ce0
// src: COMMUNITY 0x00444ce0
void __fastcall TESObjectCELL_IncCriticalQueuedRefCount(char* pThis)
{
    InitScriptRunLock(pThis + 0xa0);
}

struct FUN_00444ed0_shell : public TESObjectREFR
{
    bool TESObjectREFR_IsMarker();
};

// Reads a TESObject pointer from the file name and, if non-null, calls its virtual function at offset 0x154, returning the result or false.
// @fnv 0x00444ed0
// src: XBOX_PDB 0x00444ed0
bool FUN_00444ed0_shell::TESObjectREFR_IsMarker()
{
    TESObject* pObject = *reinterpret_cast<TESObject* const*>(reinterpret_cast<TESFile*>(this)->GetName());
    return pObject ? (reinterpret_cast<bool(__thiscall**)(TESObject*)>(*reinterpret_cast<void***>(pObject))[0x154 / 4])(
                         pObject)
                   : false;
}

struct FUN_00445300_shell : public ModelLoader
{
    void ModelLoader_ReleaseModel(char*, bool, unsigned int);
};


struct LoaderStub
{
    void ModelLoader_TryAndRemoveModel(Model*, const char*);
};
struct ModelMapStub
{
    virtual void a();
    virtual void b();
    virtual bool Lookup(const char*, Model**);
};
struct ModelMapHolder
{
    ModelMapStub* m_pLoadedModelMap;
};
// @fnv 0x00445300
// src: XBOX_PDB 0x00445300
void FUN_00445300_shell::ModelLoader_ReleaseModel(char* apModelFileName, bool abDeleteIfUnreferenced, unsigned int aiNumDecrements)
{
    Model* pmodel = 0;
    if (((ModelMapHolder*)this)->m_pLoadedModelMap->Lookup(apModelFileName, &pmodel))
    {
        if (aiNumDecrements == 1)
            pmodel->ReleaseScriptRunLock();
        else
            pmodel->AtomicAdd(-(short)aiNumDecrements);
        if (abDeleteIfUnreferenced)
            ((LoaderStub*)this)->ModelLoader_TryAndRemoveModel(pmodel, apModelFileName);
    }
}

void __cdecl MLSetFlag_16(unsigned char, void*);

struct FUN_00447190_dummy
{
    void QueuedModel_SetForceLoad(unsigned char arg1);
};

// Calls FUN_0044af70 with arg1 and a pointer to this object at offset 0x3c.
// @fnv 0x00447190
// src: XBOX_PDB 0x00447190
void FUN_00447190_dummy::QueuedModel_SetForceLoad(unsigned char aByte)
{
    MLSetFlag_16(aByte, (char*)this + 0x3c);
}

struct FUN_004472a0_shell : public ModelLoader
{
    bool ModelLoader_FindModel(char*, void*);
};

struct VHelper
{
    virtual ~VHelper()
    {}
    virtual void _v1()
    {}
    virtual bool Get(char*, void**)
    {
        return 0;
    }
};

struct ModelLoaderAccess
{
    VHelper* m_pLoadedModelMap;
};

// Clears output, asks the loader for the model named by filename, and stores it in output if found; returns whether it succeeded.
// @fnv 0x004472a0
// src: XBOX_PDB 0x004472a0
bool FUN_004472a0_shell::ModelLoader_FindModel(char* filename, void* output)
{
    ((GO*)output)->FUN_0044aed0(0);
    void* pmodel = 0;
    if (((ModelLoaderAccess*)this)->m_pLoadedModelMap->Get(filename, &pmodel))
    {
        ((GO*)output)->FUN_0044aed0(pmodel);
        return true;
    }
    return false;
}

struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;

struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;

struct FormRecordHeader;
struct TESFileGroup;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;

struct LoadedCellData;
struct NavMeshCollection;
struct NiCamera;
struct NiColor;
struct NiPick;

struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESClimate;

struct TESGlobal;
struct TESImageSpace;

struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
struct FUN_00447950_shell : public ModelLoader
{
    bool ModelLoader_IsFileQueuedForCell(TESObjectCELL*);
};


// Returns true if apCell is non-null and its InterfaceManager FUN_004fd400 result is greater than zero.
// @fnv 0x00447950
// src: XBOX_PDB 0x00447950
bool FUN_00447950_shell::ModelLoader_IsFileQueuedForCell(TESObjectCELL* apCell)
{
    if (apCell && reinterpret_cast<int>(reinterpret_cast<InterfaceManager*>(apCell)->GetAVEffect()) > 0)
        return true;
    return false;
}

namespace fnv_00448920 {
struct FUN_00448920_shell : public ModelLoader
{
    void ModelLoader_TryAndRemoveModel(Model*, char*);
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

int __fastcall GetCombinedValue(Model*);

struct ModelDeleteStub
{
    void* FUN_004431f0(unsigned int);
};

struct ModelMapStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Remove(char*);
};

struct BGSSaveLoadGameAccess : public BGSSaveLoadGame
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
};

// @fnv 0x00448920
// src: XBOX_PDB 0x00448920
void FUN_00448920_shell::ModelLoader_TryAndRemoveModel(Model* apModel, char* apModelFileName)
{
    if (GetCombinedValue(apModel) == 0)
    {
        bool bremoveFromMap = true;
        if (g_BGSSaveLoadGame && ((BGSSaveLoadGameAccess*)g_BGSSaveLoadGame)->BGSSaveLoadGame_GetSaveGameLoading())
        {
            bremoveFromMap = false;
            *((bool*)((char*)this + 0x2c)) = true;
        }
        if (bremoveFromMap)
        {
            (*(ModelMapStub**)this)->Remove(apModelFileName);
            ModelDeleteStub* tmp1 = (ModelDeleteStub*)apModel;
            ModelDeleteStub* tmp2 = tmp1;
            tmp2 ? tmp2->FUN_004431f0(1) : 0;
        }
    }
}
}  // namespace fnv_00448920

struct FUN_00448a60_struct
{
    unsigned int pad[3];
    unsigned int val;
    unsigned int GetMaskedValue(unsigned int mask);
};

// @fnv 0x00448a60
unsigned int FUN_00448a60_struct::GetMaskedValue(unsigned int mask)
{
    return val & mask;
}

// @fnv 0x00448de0
bool __fastcall IsNotStateSix(int param_1)
{
    return *(int*)(param_1 + 0x68) != 6;
}

// Sets both 64-bit elements of the given array to zero and returns the array pointer.
// @fnv 0x00448e00
__int64* __fastcall ClearPair(__int64* param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    return param_1;
}

__int64 __cdecl BSPrecisionTimer_GetTimer();
extern float DAT_011ac39c;

struct FUN_00448e30_this
{
    __int64 a;
    __int64 b;
    void init(float f);
};

// Stores the result of FUN_00aa4d80 in a and f multiplied by DAT_011ac39c in b.
// @fnv 0x00448e30
void FUN_00448e30_this::init(float afValue)
{
    a = BSPrecisionTimer_GetTimer();
    b = (__int64)(afValue * DAT_011ac39c);
}

__int64 __cdecl BSPrecisionTimer_GetTimer();

// @fnv 0x00448e70
// src: COMMUNITY 0x00448e70
bool __fastcall BSPrecisionTimer_Check(__int64* pThis)
{
    return (BSPrecisionTimer_GetTimer() - pThis[0]) > pThis[1];
}

namespace fnv_00448f50 {
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct FUN_00448f50_shell : public ModelLoader
{
    void ForwardToVTableSlot(BSFileEntry*);
};

struct _DummyVTable_00448f50
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(BSFileEntry*);
};

// Calls the virtual method at vtable slot 5 on the object stored at this+0x20, passing apFileEntry.
// @fnv 0x00448f50
void FUN_00448f50_shell::ForwardToVTableSlot(BSFileEntry* apFileEntry)
{
    (*reinterpret_cast<_DummyVTable_00448f50**>(reinterpret_cast<char*>(this) + 0x20))->v5(apFileEntry);
}
}  // namespace fnv_00448f50

// @fnv 0x00449050
// src: COMMUNITY 0x00449050
int __cdecl ModelLoader_GetArchiveTypeIndexForIOFileIndex(int aeIOFileIndex)
{
    switch (aeIOFileIndex)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    default:
        return 8;
    }
}

extern int DAT_01017138;
extern int DAT_011c3b38;
int __cdecl InitScriptRunLock(void*);

// @fnv 0x00449090
// src: EXE 0x00449090
void* __fastcall BSTask_int64_BSTask(void* apObject)
{
    *((void**)apObject) = &DAT_01017138;
    *((int*)((char*)apObject + 8)) = 0;
    *((int*)((char*)apObject + 0xc)) = 0;
    *((__int64*)((char*)apObject + 0x10)) = 0;
    InitScriptRunLock(&DAT_011c3b38);
    return apObject;
}

// @fnv 0x00449110
// src: XBOX_PDB 0x00449110
bool __fastcall BSTask_int64_GetTaskFinished(int* piValues)
{
    return piValues[3] >= 4;
}

// @fnv 0x00449130
// src: XBOX_PDB 0x00449130
bool __fastcall BSTask_int64_GetTaskCanceled(int* pThis)
{
    return pThis[3] == 6;
}

// @fnv 0x00449150
void __fastcall SetFieldCToFive(char* pObject)
{
    *reinterpret_cast<int*>(pObject + 0xc) = 5;
}

bool __cdecl CompareAndSwapEx(void*, int, int);

struct FUN_00449190_cls
{
    bool SetState(int eCurrentState, int eNewState);
};

// Calls FUN_004491c0 with a pointer to this object's field at offset 0xc, passing the new state and current state.
// @fnv 0x00449190
bool FUN_00449190_cls::SetState(int eCurrentState, int eNewState)
{
    return CompareAndSwapEx((char*)this + 0xc, eNewState, eCurrentState);
}

int __cdecl BSAtomicCompareExchange(long volatile*, long, long);

// Exe 0x004491c0: unit-local Interface view; declarations and layout are preserved.
class ModelloaderInterfaceView
{
  public:
    static void __cdecl PrintDebugMessage();
};

// @fnv 0x004491c0
// src: XBOX_PDB 0x004491c0
bool __cdecl CompareAndSwapEx(long volatile* pVolatile, long param_2, long param_3)
{
    bool res = BSAtomicCompareExchange(pVolatile, param_3, param_2) == param_3;
    ModelloaderInterfaceView::PrintDebugMessage();
    return res;
}

struct E_00449210
{
    void LockFreeQueue_NiPointer_IOTask_Push(int);
};
struct C_00449210
{
    virtual void v0();
    virtual void v1();
    E_00449210** arr;
    void LockFreePriorityQueue_NiPointer_IOTask_Push(int idx, int val);
};
// Calls FUN_00449240 on the element at idx with val, then calls v1().
// @fnv 0x00449210
// src: XBOX_PDB 0x00449210
void C_00449210::LockFreePriorityQueue_NiPointer_IOTask_Push(int aiIndex, int val)
{
    arr[aiIndex]->LockFreeQueue_NiPointer_IOTask_Push(val);
    v1();
}

struct R449
{
    bool Pop();
};
struct Q449
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449* LockFreeMap_GetInterface_0(void*);
    bool LockFreeQueue_NiPointer_IOTask_Pop(void*);
};
// Locks the object, calls Pop on the result of FUN_00449f80(arData), unlocks, and returns that bool.
// @fnv 0x00449280
// src: COMMUNITY 0x00449280
bool Q449::LockFreeQueue_NiPointer_IOTask_Pop(void* arData)
{
    lock.Lock(0);
    bool bResult = LockFreeMap_GetInterface_0(arData)->Pop();
    lock.Unlock();
    return bResult;
}

extern int DAT_0101732c;

struct FUN_004492c0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004492c0_shell* LockFreeCaseInsensitiveStringMap_Model_LockFreeCaseInsensitiveStringMap(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004492c0
// src: EXE 0x004492c0
FUN_004492c0_shell* FUN_004492c0_shell::LockFreeCaseInsensitiveStringMap_Model_LockFreeCaseInsensitiveStringMap(int a, int b, int c)
{
    FUN_0044c270(a, b, c);
    vtbl = (int)&DAT_0101732c;
    return this;
}

struct FUN_00449500_shell
{
    void LockFreeStringMap_Model_CopyKey(const char* param_1, char** param_2);
};

// @fnv 0x00449500
// src: COMMUNITY 0x00449500
void FUN_00449500_shell::LockFreeStringMap_Model_CopyKey(const char* param_1, char** param_2)
{
    TaskQueueInterface::CopyStringToBuffer(*param_2, 0x100, param_1);
}

namespace fnv_00449530 {

struct R530
{
    bool InvokeWithArgs();
};
struct FUN_00449530_S
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R530* LockFreeMap_GetInterface_0(int, int);
    bool LockFreeMap_char_const_T_Data_Lookup(int a, int b);
};
// @fnv 0x00449530
// src: COMMUNITY 0x00449530
bool FUN_00449530_S::LockFreeMap_char_const_T_Data_Lookup(int a, int b)
{
    lock.Lock(0);
    bool r = LockFreeMap_GetInterface_0(a, b)->InvokeWithArgs();
    lock.Unlock();
    return r;
}
}  // namespace fnv_00449530

namespace fnv_00449580 {

struct R449b
{
    bool LockFreeMapInterface_SetAt_0();
};
struct Q449b
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449b* LockFreeMap_GetInterface_0(void*, void*, bool);
    bool LockFreeMap_char_const_T_Data_SetAtAlt(void*, void*, bool);
};
// @fnv 0x00449580
// src: COMMUNITY 0x00449580
bool Q449b::LockFreeMap_char_const_T_Data_SetAtAlt(void* a, void* b, bool c)
{
    lock.Lock(0);
    bool bResult = LockFreeMap_GetInterface_0(a, b, c)->LockFreeMapInterface_SetAt_0();
    lock.Unlock();
    return bResult;
}
}  // namespace fnv_00449580

namespace fnv_004495d0 {

struct R449
{
    bool Pop();
};
struct Q449
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449* LockFreeMap_GetInterface_0(void*);
    bool LockFreeMap_char_const_T_Data_RemoveAt(void*);
};
// @fnv 0x004495d0
// src: COMMUNITY 0x004495d0
bool Q449::LockFreeMap_char_const_T_Data_RemoveAt(void* arData)
{
    lock.Lock(0);
    bool bResult = LockFreeMap_GetInterface_0(arData)->Pop();
    lock.Unlock();
    return bResult;
}
}  // namespace fnv_004495d0

void __fastcall FUN_0044a040(void*);

// @fnv 0x00449680
// src: GUESS 0x00449680 (confidence: low)
void __fastcall Object_ForwardCall_00449680(void* p)
{
    FUN_0044a040(p);
}

namespace fnv_004496a0 {
extern int DAT_0101732c;

struct FUN_004496a0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004496a0_shell* LockFreeCaseInsensitiveStringMap_KFModel_LockFreeCaseInsensitiveStringMap(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004496a0
// src: EXE 0x004496a0
FUN_004496a0_shell* FUN_004496a0_shell::LockFreeCaseInsensitiveStringMap_KFModel_LockFreeCaseInsensitiveStringMap(int a, int b, int c)
{
    FUN_0044c270(a, b, c);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_004496a0

int __cdecl FUN_00ec6da0(const char*, const char*);

struct FUN_004496d0_shell
{
    bool IsGreaterOrEqual(const char* a, const char* b);
};

// Returns whether the result of FUN_00ec6da0(a, b) is greater than or equal to zero.
// @fnv 0x004496d0
bool FUN_004496d0_shell::IsGreaterOrEqual(const char* pcLeft, const char* pcRight)
{
    return FUN_00ec6da0(pcLeft, pcRight) >= 0;
}

namespace fnv_004497c0 {
extern int DAT_0101732c;

struct FUN_004497c0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004497c0_shell* LockFreeCaseInsensitiveStringMap_LoadedFile_LockFreeCaseInsensitiveStringMap(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004497c0
// src: EXE 0x004497c0
FUN_004497c0_shell* FUN_004497c0_shell::LockFreeCaseInsensitiveStringMap_LoadedFile_LockFreeCaseInsensitiveStringMap(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_004497c0

int __cdecl FUN_00ec6da0(const char* a, const char* b);

struct FUN_00449880_Class
{
    bool LockFreeStringMap_Model_IsKeyEqual(const char* a, const char* b);
};

// Returns true when the comparison of the two strings via FUN_00ec6da0 yields zero.
// @fnv 0x00449880
// src: COMMUNITY 0x00449880
bool FUN_00449880_Class::LockFreeStringMap_Model_IsKeyEqual(const char* pcStringA, const char* pcStringB)
{
    return FUN_00ec6da0(pcStringA, pcStringB) == 0;
}

extern int DAT_01017288;
void __fastcall LockFreeMap_char_const_Model_LockFreeMapIterator_LockFreeMapIterator(void*);

// @fnv 0x004498e0
// src: GUESS 0x004498e0 (confidence: low)
void* __fastcall Object_ProcessAndReturnValue_004498e0(void* apObject)
{
    LockFreeMap_char_const_Model_LockFreeMapIterator_LockFreeMapIterator(apObject);
    *reinterpret_cast<void**>(apObject) = &DAT_01017288;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(apObject) + 8) =
        reinterpret_cast<void*>(reinterpret_cast<char*>(apObject) + 0x10);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(apObject) + 0x10) = 0;
    return apObject;
}

extern int DAT_01017294;

// @fnv 0x00449940
// src: GUESS 0x00449940 (confidence: low)
void __fastcall Object_SetVirtualTable_00449940(void** apOut)
{
    *apOut = &DAT_01017294;
}

void __fastcall FUN_0044cbb0(void* pThis);
extern int DAT_010172a0;

// @fnv 0x00449960
// src: GUESS 0x00449960 (confidence: low)
void* __fastcall Object_InitializeFields_00449960(char* pThis)
{
    FUN_0044cbb0(pThis);
    *reinterpret_cast<int**>(pThis) = &DAT_010172a0;
    *reinterpret_cast<char**>(pThis + 8) = pThis + 0x10;
    pThis[0x10] = 0;
    return pThis;
}

extern int DAT_010172ac;

// @fnv 0x004499a0
// src: GUESS 0x004499a0 (confidence: low)
void __fastcall Object_SetVirtualTable_004499a0(int** ppTarget)
{
    *ppTarget = &DAT_010172ac;
}

extern int DAT_010172b8;

// @fnv 0x004499c0
// src: GUESS 0x004499c0 (confidence: low)
void __fastcall Object_SetVirtualTable_004499c0(void* pThis)
{
    *(int**)pThis = &DAT_010172b8;
}

extern int DAT_010172c4;

// @fnv 0x004499e0
// src: GUESS 0x004499e0 (confidence: low)
void __fastcall Object_SetVirtualTable_004499e0(void* pThis)
{
    *(int**)pThis = &DAT_010172c4;
}

extern int DAT_010172d0;

// @fnv 0x00449a00
// src: GUESS 0x00449a00 (confidence: low)
void __fastcall Object_SetVirtualTable_00449a00(int** appTarget)
{
    *appTarget = &DAT_010172d0;
}

namespace fnv_00449f50 {
extern int DAT_0101732c;

struct FUN_00449f50_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_00449f50_shell* LockFreeStringMap_Model_LockFreeStringMap(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x00449f50
// src: EXE 0x00449f50
FUN_00449f50_shell* FUN_00449f50_shell::LockFreeStringMap_Model_LockFreeStringMap(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_00449f50

void __fastcall ThreadSpecificInterfaceManager_GetInterface(int pThis, int edx, void* pArg);

// @fnv 0x00449f80
// src: COMMUNITY 0x00449f80
void __fastcall LockFreeMap_GetInterface_0(int* pThis)
{
    reinterpret_cast<void(__thiscall*)(int, void*)>(&ThreadSpecificInterfaceManager_GetInterface)(pThis[5], pThis);
}

namespace fnv_00449fa0 {
extern int DAT_0101732c;

struct FUN_00449fa0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_00449fa0_shell* ConstructWithVtbl(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x00449fa0
FUN_00449fa0_shell* FUN_00449fa0_shell::ConstructWithVtbl(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_00449fa0

namespace fnv_0044a100 {
extern int DAT_0101732c;

struct FUN_0044a100_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_0044a100_shell* LockFreeStringMap_LoadedFile_LockFreeStringMap(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x0044a100
// src: EXE 0x0044a100
FUN_0044a100_shell* FUN_0044a100_shell::LockFreeStringMap_LoadedFile_LockFreeStringMap(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_0044a100

struct V130
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
    virtual int v9(int, int, int, unsigned char);
};
struct S130
{
    V130* p;
    void InsertOrReplaceNode(int);
    void LockFreeMapInterface_SetAt_0(int a, int b, unsigned char c);
};
// Calls the virtual method v9 on p with a, a, b and c, then passes the result to InsertOrReplaceNode.
// @fnv 0x0044a130
// src: COMMUNITY 0x0044a130
void S130::LockFreeMapInterface_SetAt_0(int a, int aiArg, unsigned char c)
{
    InsertOrReplaceNode(p->v9(a, a, aiArg, c));
}

struct _Out_0044a170
{
    void FaceGenData_Iterator_Set(int d, void* self);
};

struct _Dummy_0044a170
{
    int a, b, c, d;
    _Out_0044a170* SetIteratorDataAndOwner(_Out_0044a170* out);
};

// @fnv 0x0044a170
// src: GUESS 0x0044a170 (confidence: medium)
_Out_0044a170* _Dummy_0044a170::SetIteratorDataAndOwner(_Out_0044a170* out)
{
    out->FaceGenData_Iterator_Set(this->d, this);
    return out;
}

void __cdecl CallWithScaledArg(NiAVObject*, int, int);

// @fnv 0x0044adf0
// src: XBOX_PDB 0x0044adf0
void __cdecl NiStreamSaveBinary_unsigned_int(MiddleHighProcess* pProcess, int a2)
{
    CallWithScaledArg(reinterpret_cast<NiAVObject*>(pProcess->MiddleHighProcess::GetAnimationObject()), a2, 1);
}

struct WaitableObject
{
    void NiRefObject_IncRefCount();
    void Model_DecRefCount();
};

// @fnv 0x0044aed0
template <> NiPointer<WaitableObject>& NiPointer<WaitableObject>::operator=(WaitableObject* pObject)
{
    if ((*reinterpret_cast<WaitableObject**>(this)) != pObject)
    {
        if ((*reinterpret_cast<WaitableObject**>(this)))
            (*reinterpret_cast<WaitableObject**>(this))->Model_DecRefCount();
        (*reinterpret_cast<WaitableObject**>(this)) = pObject;
        if ((*reinterpret_cast<WaitableObject**>(this)))
            (*reinterpret_cast<WaitableObject**>(this))->NiRefObject_IncRefCount();
    }
    return *this;
}

class NiControllerSequence;
class TESAnimGroup;
namespace fnv_0044b010 {
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_0044b010_shell : public KFModel
{
    void KFModel_IncRefCount();
};

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0044b010
// src: XBOX_PDB 0x0044b010
void FUN_0044b010_shell::KFModel_IncRefCount()
{
    InitScriptRunLock(&pListSequence);
}
}  // namespace fnv_0044b010

class NiControllerSequence;
class TESAnimGroup;
namespace fnv_0044b050 {
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_0044b050_shell : public KFModel
{
    void KFModel_DecRefCount();
};

void __cdecl FinishScriptRunLock(void*);

// @fnv 0x0044b050
// src: XBOX_PDB 0x0044b050
void FUN_0044b050_shell::KFModel_DecRefCount()
{
    FinishScriptRunLock(&this->pListSequence);
}
}  // namespace fnv_0044b050

struct FUN_0044b0c0_holder
{
    LoadedFile* m_pObject;
    FUN_0044b0c0_holder* SetObject(LoadedFile* pObject);
};

// Stores pObject in m_pObject and increments its reference count when non-null, then returns this.
// @fnv 0x0044b0c0
FUN_0044b0c0_holder* FUN_0044b0c0_holder::SetObject(LoadedFile* pObject)
{
    m_pObject = pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
    return this;
}

namespace fnv_0044b0f0 {

struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    volatile long iRefCount;  // +0: IncRefCount (0x0044b0f0) increments it under the loader lock
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
typedef char _sizecheck_LoadedFile[sizeof(LoadedFile) == 16 ? 1 : -1];
struct FUN_0044b0f0_shell : public LoadedFile
{
    void LoadedFile_IncRefCount();
};

extern RecursiveLock g_011c3b6c;
bool __fastcall BSCriticalSection_TryLock(RecursiveLock*);

// @fnv 0x0044b0f0
// src: COMMUNITY 0x0044b0f0
void FUN_0044b0f0_shell::LoadedFile_IncRefCount()
{
    while (!BSCriticalSection_TryLock(&g_011c3b6c))
    {
    }
    InitScriptRunLock(this);
    g_011c3b6c.Leave();
}
}  // namespace fnv_0044b0f0

struct FUN_0044b160_obj
{
    void Model_DecRefCount();
};
void __fastcall Model_DecRefCount(void*);

struct FUN_0044b160_ptr
{
    struct Target
    {
        void Release();
    }* m_pObject;
};

void __fastcall Model_DecRefCount(FUN_0044b160_ptr::Target*);

// @fnv 0x0044b160
// src: GUESS 0x0044b160 (confidence: medium)
void __fastcall Object_ReleaseReferencedObject_0044b160(FUN_0044b160_ptr* _this)
{
    if (_this->m_pObject)
        Model_DecRefCount(_this->m_pObject);
}

namespace fnv_0044b180 {

struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    volatile long iRefCount;  // +0: IncRefCount (0x0044b0f0) increments it under the loader lock
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
typedef char _sizecheck_LoadedFile[sizeof(LoadedFile) == 16 ? 1 : -1];
struct FUN_0044b180_shell : public LoadedFile
{
    void LoadedFile_DecRefCount();
};

struct GlobalObject_0044fae0
{
    bool BSCriticalSection_TryLock();
    void Leave();
};
extern GlobalObject_0044fae0 g_011c3b6c;
struct Del44b
{
    int FUN_0044b1f0(int);
};
// @fnv 0x0044b180
// src: XBOX_PDB 0x0044b180
void FUN_0044b180_shell::LoadedFile_DecRefCount()
{
    while (!g_011c3b6c.BSCriticalSection_TryLock())
    {
    }
    FinishScriptRunLock(this);
    g_011c3b6c.Leave();
    if (*(int*)this == 0)
    {
        struct D
        {
            Del44b* doomed;
            Del44b* object;
        } d;
        d.doomed = (Del44b*)this;
        d.object = d.doomed;
        d.object ? d.object->FUN_0044b1f0(1) : 0;
    }
}
}  // namespace fnv_0044b180

void __fastcall FUN_0044b2e0(void* pThis);

// @fnv 0x0044b2c0
// src: GUESS 0x0044b2c0 (confidence: low)
void __fastcall Object_ProcessState_0044b2c0(void** pThis)
{
    if (*pThis)
    {
        FUN_0044b2e0(*pThis);
    }
}

void __fastcall BSTask_int64_DecRefCount(void* pThis);

// @fnv 0x0044cbf0
// src: GUESS 0x0044cbf0 (confidence: high)
void __fastcall BSTask_int64_DecRefCount_ReleaseTaskReference(void** apObject)
{
    if (*apObject)
    {
        BSTask_int64_DecRefCount(*apObject);
    }
}

namespace fnv_0044dd60 {
int __cdecl FinishScriptRunLock(void*);

struct VirtualDeletable
{
    virtual ~VirtualDeletable();
};

// Calls FinishScriptRunLock on the object at offset 8 and deletes the object if the returned count is zero.
// @fnv 0x0044dd60
// src: XBOX_PDB 0x0044dd60
void __fastcall BSTask_int64_DecRefCount(VirtualDeletable* apObject)
{
    int count = FinishScriptRunLock((char*)apObject + 8);
    if (count == 0)
    {
        delete apObject;
    }
}
}  // namespace fnv_0044dd60

// @fnv 0x0044faa0
// src: XBOX_PDB 0x0044faa0
void* __fastcall SettingCollectionList_Setting_Head(char* this_ptr)
{
    return this_ptr + 0x10C;
}

struct RefT
{
    void _ref_00726070();
};
struct FUN_0044fac0_S
{
    void SettingCollectionList_Setting_Next(RefT* p);
};
// @fnv 0x0044fac0
// src: XBOX_PDB 0x0044fac0
void FUN_0044fac0_S::SettingCollectionList_Setting_Next(RefT* apRef)
{
    apRef->_ref_00726070();
}

__declspec(dllimport) void __stdcall InitializeCriticalSection(void*);

// @fnv 0x0044fae0
// src: GUESS 0x0044fae0 (confidence: high)
void* __fastcall Object_InitializeCriticalSection_Thunk(void* apCriticalSection)
{
    InitializeCriticalSection(apCriticalSection);
    return apCriticalSection;
}

class NiObject;
namespace fnv_0045bad0 {

typedef char _sizecheck_NiRTTI[sizeof(NiRTTI) == 8 ? 1 : -1];

struct FUN_0045baf0_helper
{
    bool IsEqual(const NiRTTI*) const;
};

// @fnv 0x0045bad0
// src: XBOX_PDB 0x0045bad0
bool __cdecl NiObject_IsExactKindOf(const NiRTTI* pkRTTI, const NiObject* pkObject)
{
    if (!pkObject)
        return false;
    return ((const FUN_0045baf0_helper*)pkObject)->IsEqual(pkRTTI);
}
}  // namespace fnv_0045bad0

struct Item
{
    bool IsFieldEqual(void* a);
};
struct LNode
{
    Item** _ref_006815c0();
    LNode* _ref_00726070();
};

// Walks the TESObjectANIO list and returns the item matching a, skipping the first n matches; returns 0 if none found.
// @fnv 0x0046fd50
Item* TESDataHandler::FindNthMatchingItem(void* a, int aiSkipCount)
{
    Item* item = 0;
    LNode* node = reinterpret_cast<LNode*>(GetTESObjectANIOList());
    while (node && (item = *node->_ref_006815c0()))
    {
        if (item->IsFieldEqual(a))
        {
            if (aiSkipCount == 0)
                return item;
            else
                aiSkipCount = aiSkipCount - 1;
        }
        node = node->_ref_00726070();
    }
    return 0;
}

struct S_004a0e10
{
    char pad[0x208];
    unsigned char f208;
    bool NiRenderer_GetInsideFrameState();
    bool NiRenderer_Check_RenderTargetGroupActive(int a, unsigned char b);
};
// Returns false if FUN_004a0e50 fails; otherwise returns whether f208 equals b.
// @fnv 0x004a0e10
// src: COMMUNITY 0x004a0e10
bool S_004a0e10::NiRenderer_Check_RenderTargetGroupActive(int aiUnused, unsigned char b)
{
    if (!NiRenderer_GetInsideFrameState())
        return false;
    if (f208 == b)
        return true;
    return false;
}

namespace fnv_004a8a90 {

// @fnv 0x004a8a90
// src: XBOX_PDB 0x004a8a90
const char* __fastcall NiTimeController_GetNext(char* apObject)
{
    return *(const BSStringT<char>*)(apObject + 0x30);
}
}  // namespace fnv_004a8a90

struct AC_0042f730
{
    void ActorCause_IncRefCount();
};
struct S_0042f730
{
    AC_0042f730* m_pObject;
    S_0042f730* SetObjectAndAddReference(AC_0042f730* pObject);
};
// Stores pObject in m_pObject and, if it is non-null, calls FUN_0044bbc0 on it; returns this.
// @fnv 0x00528cb0
// src: GUESS 0x00528cb0 (confidence: high)
S_0042f730* S_0042f730::SetObjectAndAddReference(AC_0042f730* pObject)
{
    m_pObject = pObject;
    if (m_pObject)
        m_pObject->ActorCause_IncRefCount();
    return this;
}

namespace fnv_00537bd0 {

// @fnv 0x00537bd0
const char* __fastcall GetStringAtOffset(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x78);
}
}  // namespace fnv_00537bd0

namespace fnv_005495f0 {

// @fnv 0x005495f0
// src: XBOX_PDB 0x005495f0
const char* __fastcall NiGeometry_GetModelData(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0xb8);
}
}  // namespace fnv_005495f0

// @fnv 0x00559450
// src: GUESS 0x00559450 (confidence: low)
int __fastcall Modelloader_GetReferencedThis(int* pThis)
{
    return *pThis;
}

struct FUN_005d8710_shell : public QueuedReference
{
    NiAVObject* VATS_GetVATSLight();
};

// @fnv 0x005d8710
// src: XBOX_PDB 0x005d8710
NiAVObject* FUN_005d8710_shell::VATS_GetVATSLight()
{
    return *(NiPointer<NiAVObject>*)((char*)this + 0x34);
}

// @fnv 0x0062a100
unsigned int BSFileEntry::Size()
{
    return iSize & 0x3fffffff;
}

NiRTTI* __fastcall _ref_00726070(NiRTTI*);
struct NiObject_b
{
    virtual void v0();
    virtual void v1();
    virtual NiRTTI* GetRTTI();
    bool NiObject_IsKindOf_006532c0(const NiRTTI* pkRTTI);
};
// Walks the RTTI chain from GetRTTI() and returns true if pkRTTI is found, otherwise false.
// @fnv 0x006532c0
// src: XBOX_PDB 0x006532c0
bool NiObject_b::NiObject_IsKindOf_006532c0(const NiRTTI* pkRTTI)
{
    const NiRTTI* pkThis = GetRTTI();
    while (pkThis)
    {
        if (pkThis == pkRTTI)
            return true;
        pkThis = _ref_00726070(const_cast<NiRTTI*>(pkThis));
    }
    return false;
}

class NiCollisionObject;
namespace fnv_006838b0 {
struct FUN_006838b0_shell : public NiAVObject
{
    NiCollisionObject* NiAVObject_GetCollisionObject();
};


// @fnv 0x006838b0
// src: COMMUNITY 0x006838b0
NiCollisionObject* FUN_006838b0_shell::NiAVObject_GetCollisionObject()
{
    return (NiCollisionObject*)((const BSStringT<char>*)((const char*)this + 0x1c))->operator const char*();
}
}  // namespace fnv_006838b0

struct Dummy_0069b080
{
    int pad0;
    int pad1;
    int pad2;
    int field_c;
    bool IsFieldCZero();
};

// @fnv 0x0069b080
bool __fastcall IsFieldCZero(Dummy_0069b080* pThis)
{
    return pThis->field_c == 0;
}

namespace fnv_006fa820 {

// @fnv 0x006fa820
// src: XBOX_PDB 0x006fa820
const char* __fastcall bhkNiCollisionObject_GetWorldObject(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x10);
}
}  // namespace fnv_006fa820

struct QH_0092c820
{
    void BSTask_int64_DecRefCount();
    void Model_IncManualRefCount();
};

// @fnv 0x0092c820
NP& NP::operator=(const NP& aOther)
{
    if (p != aOther.p)
    {
        if (p)
            reinterpret_cast<QH_0092c820*>(p)->BSTask_int64_DecRefCount();
        p = aOther.p;
        if (p)
            reinterpret_cast<QH_0092c820*>(p)->Model_IncManualRefCount();
    }
    return *this;
}

struct FUN_0092c870_shell : public Model
{
    void Model_IncManualRefCount();
};

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0092c870
// src: XBOX_PDB 0x0092c870
void FUN_0092c870_shell::Model_IncManualRefCount()
{
    InitScriptRunLock((char*)this + 8);
}

struct FUN_00ad8570_S
{
    void BSAudio_StopMovingSounds(int a, float b, int c);
};
// @fnv 0x00ad8570
// src: XBOX_PDB 0x00ad8570
void FUN_00ad8570_S::BSAudio_StopMovingSounds(int a, float b, int c)
{
    BSAudioManager::GetRandomGenerator().BSAudioManager_StopMovingSounds(a, b, c);
}

void __cdecl WildCard_MakeString(void*, int);
int __cdecl WildcardMatch(void*, void*);

// @fnv 0x00af3bd0
// src: COMMUNITY 0x00af3bd0
int WildCard_Match(int param1, int param2)
{
    char buf1[0x108];
    char buf2[0x108];
    WildCard_MakeString(buf2, param1);
    WildCard_MakeString(buf1, param2);
    return WildcardMatch(buf2, buf1) == 1;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// @fnv 0x00c3f8a0
// src: COMMUNITY 0x00c3f8a0
long __fastcall LockFreeMap_int64_NiPointer_BSTask_int64_DecrementCount(char* pObject)
{
    return InterlockedDecrement((volatile long*)(pObject + 0x18));
}

namespace fnv_0043c550 {
struct FUN_0043c550_shell : public QueuedTexture
{
    void ApplyQueuedTexture();
};

struct TextureFileEntrySetter
{
    static void SetTexture(const char*, const BSFileEntry*);
};
struct H0 : public LocationDescriptor
{
    bool QueuedKF_GetAlreadyInKFMap();
    bool QueuedTexture_GetInQueuedTextureMap();
    void QueuedTexture_SetInQueuedTextureMap(int);
    void RunVirtualMethod28();
};
struct HM
{
    void ForwardToVTableSlot(BSFileEntry*);
};
// @fnv 0x0043c550
void FUN_0043c550_shell::ApplyQueuedTexture()
{
    if (!((H0*)this)->QueuedKF_GetAlreadyInKFMap() && (const char*)(*(BSStringT<char>*)((char*)this + 0x30)))
    {
        if (((H0*)this)->SetLocRef())
            TextureFileEntrySetter::SetTexture((const char*)(*(BSStringT<char>*)((char*)this + 0x30)),
                                               ((H0*)this)->SetLocRef());
        else if (((Tile*)this)->GetParent())
            TextureFileEntrySetter::SetTexture((const char*)(*(BSStringT<char>*)((char*)this + 0x30)), 0);
    }
    if (((H0*)this)->SetLocRef() && ((H0*)this)->QueuedTexture_GetInQueuedTextureMap())
    {
        ((H0*)this)->QueuedTexture_SetInQueuedTextureMap(0);
        ((HM*)g_modelLoader)->ForwardToVTableSlot(((H0*)this)->SetLocRef());
    }
    ((H0*)this)->RunVirtualMethod28();
}
}  // namespace fnv_0043c550

struct UW
{
    unsigned int v;
};
struct BW
{
    bool v;
};
// Sets or clears bit f.v in the bit array at self+0x20 and resets the value at self+0x38 when the bit changes.
// @fnv 0x00441130
// src: XBOX_PDB 0x00441130
void __fastcall BSShaderProperty_SetFlag(char* self, UW auiFlag, BW abSet)
{
    unsigned int uiindex = auiFlag.v >> 5;
    unsigned int uibit = auiFlag.v % 32;
    unsigned int uimask = 1 << uibit;
    if (abSet.v)
    {
        if (!(((unsigned int*)(self + 0x20))[uiindex] & uimask))
            *(unsigned int*)(self + 0x38) = 0;
        ((unsigned int*)(self + 0x20))[uiindex] |= uimask;
    }
    else
    {
        if (((unsigned int*)(self + 0x20))[uiindex] & uimask)
            *(unsigned int*)(self + 0x38) = 0;
        ((unsigned int*)(self + 0x20))[uiindex] &= ~uimask;
    }
}

struct Struct_008b7b70;
bool __fastcall Actor_IsCrippled(Struct_008b7b70*);
struct PC7d;
extern PC7d* g_thePlayer;
struct A9
{
    int Actor_CheckHighDetail();
    void Actor_QueueReplacementLocomotion(int, void*);
};
struct Hx
{
    void QueuedReference_QueueMe();
};
struct MLa
{
    bool IsLoadTexturesDegraded();
    bool SetTlsFlag(bool);
};
// @fnv 0x00441200
// src: XBOX_PDB 0x00441200
void __fastcall QueuedActor_QueueMe(char* self)
{
    void** a = *(void***)(self + 0x28);
    bool b;
    ((void(__thiscall*)(void*))(*(void***)a)[0x260 / 4])(a);
    b = ((MLa*)g_modelLoader)->IsLoadTexturesDegraded();
    if ((void*)a != g_thePlayer && !((A9*)a)->Actor_CheckHighDetail())
        ((MLa*)g_modelLoader)->SetTlsFlag(true);
    if (Actor_IsCrippled((Struct_008b7b70*)a))
        ((A9*)a)->Actor_QueueReplacementLocomotion(1, self);
    ((Hx*)self)->QueuedReference_QueueMe();
    ((MLa*)g_modelLoader)->SetTlsFlag(b);
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043be30(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x0043be30
void* DelStandIn::FUN_0043be30(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace p07 {
struct FUN_0043bf80 : QueuedFileEntry
{
    NP np;
    virtual ~FUN_0043bf80();
};
// Destructor for the object; destroys the embedded NP member and the base subobject.
// @fnv 0x0043bf80
FUN_0043bf80::~FUN_0043bf80()
{}
}

namespace fnv_0043c800 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043c800(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0043c800
void* DelStandIn::FUN_0043c800(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043c800

// Destructor that calls DestroyObject before destroying the stream object.
// @fnv 0x0043d090
BSStream::~BSStream()
{
    DestroyObject();
}

namespace fnv_0043e180 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043e180(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0043e180
void* DelStandIn::FUN_0043e180(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043e180

namespace fnv_0043e600 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043e600(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0043e600
void* DelStandIn::FUN_0043e600(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043e600

namespace fnv_0043e630 {

namespace p07 {
struct FUN_0043e1b0
{
    char pad[0x3c];
    ~FUN_0043e1b0();
};
struct FUN_0043e630 : FUN_0043e1b0
{
    NP np;
    ~FUN_0043e630();
};
// @fnv 0x0043e630
FUN_0043e630::~FUN_0043e630()
{}
}
}  // namespace fnv_0043e630

namespace fnv_0043eb80 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043eb80(unsigned int flags);
};
// Calls the destructor on this, then frees this when bit 0 of flags is set, and returns this.
// @fnv 0x0043eb80
void* DelStandIn::FUN_0043eb80(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0043eb80

namespace fnv_004414c0 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_004414c0(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x004414c0
void* DelStandIn::FUN_004414c0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_004414c0

namespace fnv_004414f0 {
struct GlobalObject_00528cb0
{
    ~GlobalObject_00528cb0();
    void* p;
};
struct FUN_00440eb0
{
    ~FUN_00440eb0();
    char pad[0x40];
};
struct FUN_004414f0 : public FUN_00440eb0
{
    GlobalObject_00528cb0 a;
    GlobalObject_00528cb0 b;
    ~FUN_004414f0();
};

// @fnv 0x004414f0
FUN_004414f0::~FUN_004414f0()
{}
}  // namespace fnv_004414f0

namespace fnv_00441b50 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00441b50(unsigned int flags);
};
// Runs the destructor on this object, then frees it via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00441b50
void* DelStandIn::FUN_00441b50(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00441b50

namespace fnv_00442010 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00442010(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00442010
void* DelStandIn::FUN_00442010(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00442010

namespace fnv_00442040 {
struct NiPtrNode_S
{
    ~NiPtrNode_S();
    void* m_pObject;
};
struct FUN_0044b2c0
{
    ~FUN_0044b2c0();
    void* p;
};
struct FUN_00441d20
{
    ~FUN_00441d20();
    char pad[0x38];
};
struct FUN_00442040 : public FUN_00441d20
{
    NiPtrNode_S a;
    FUN_0044b2c0 b;
    ~FUN_00442040();
};

// Destructor for the object; the compiler-generated member destructors run for the embedded NiPtrNode_S and FUN_0044b2c0 members.
// @fnv 0x00442040
FUN_00442040::~FUN_00442040()
{}
}  // namespace fnv_00442040

namespace fnv_004431f0 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_004431f0(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x004431f0
void* DelStandIn::FUN_004431f0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_004431f0

namespace fnv_00443240 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00443240(unsigned int flags);
};
// Runs the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00443240
void* DelStandIn::FUN_00443240(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00443240

struct FUN_00449fd0
{
    FUN_00449fd0();
    ~FUN_00449fd0();
    char pad[0x18];
};
struct FUN_00449610 : public FUN_00449fd0
{
    void* p18;
    void* p1c;
    FUN_00449610();
    void std_vector_float_std_allocator_float_clear();
};

// Initializes p18 and p1c to null, then calls FUN_0044a0a0.
// @fnv 0x00449610
FUN_00449610::FUN_00449610()
{
    p18 = 0;
    p1c = 0;
    std_vector_float_std_allocator_float_clear();
}

namespace fnv_00449fd0 {
struct _ref_006815c0
{
    void* p;
    _ref_006815c0();
    _ref_006815c0(const _ref_006815c0&);
};
struct FUN_0065d3a0
{
    void* data[4];
    FUN_0065d3a0(_ref_006815c0 arg);
    ~FUN_0065d3a0();
};
struct FUN_00449fd0 : public FUN_0065d3a0
{
    FUN_00449fd0();
    void InitializeElementStorage(int);
};

// Constructs the base with a default reference and initializes the object by calling FUN_0044a240 with 0.
// @fnv 0x00449fd0
FUN_00449fd0::FUN_00449fd0() : FUN_0065d3a0(_ref_006815c0())
{
    InitializeElementStorage(0);
}
}  // namespace fnv_00449fd0

struct ConstIterStandIn
{
    int a;
    int b;
};
struct FaceGenImageView : ConstIterStandIn
{
};
struct FaceGenImage
{
    FaceGenImageView _Doraise();
};
struct VecStandIn
{
    FaceGenImageView CallWithSelf();
    FaceGenImageView std_vector_float_std_allocator_float_erase(ConstIterStandIn, ConstIterStandIn);
    void std_vector_float_std_allocator_float_clear();
};
// Calls FUN_0044a1a0 with the results of _Doraise and CallWithSelf, discarding the returned iterator.
// @fnv 0x0044a0a0
// src: COMMUNITY 0x0044a0a0
void VecStandIn::std_vector_float_std_allocator_float_clear()
{
    std_vector_float_std_allocator_float_erase(((FaceGenImage*)this)->_Doraise(), CallWithSelf());
}

// 0x0065ded0 constructs a container iterator; 0x0065dfd0 compares iterators, unlike Pair.h.
struct EraseRangeIterator
{
    int first;
    int second;
    bool IsNotIdentical(const EraseRangeIterator&);
};
int __cdecl std_Move_float_float(int, int, int);
// 0x0044a1a0 erases an iterator range and updates the container end at 0x10; this is not ModelLoader.
struct IteratorRangeStorage
{
    char pad[0x10];
    int field10;
    EraseRangeIterator std_vector_float_std_allocator_float_Make_iter(int, int);
    void std_vector_float_std_allocator_float_Destroy(int, int);
    EraseRangeIterator std_vector_float_std_allocator_float_erase(int, int, int, int);
};
// @fnv 0x0044a1a0
// src: COMMUNITY 0x0044a1a0
EraseRangeIterator IteratorRangeStorage::std_vector_float_std_allocator_float_erase(int aiFirstA, int aiFirstB, int aiSecondA, int aiSecondB)
{
    EraseRangeIterator r1 = std_vector_float_std_allocator_float_Make_iter(aiFirstA, aiFirstB);
    EraseRangeIterator r2 = std_vector_float_std_allocator_float_Make_iter(aiSecondA, aiSecondB);
    if (r1.IsNotIdentical(r2))
    {
        int tmp = std_Move_float_float(r2.second, field10, r1.second);
        std_vector_float_std_allocator_float_Destroy(tmp, field10);
        field10 = tmp;
    }
    return r1;
}

namespace fnv_0043abf0 {
void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSStringLength(char const*);

struct FUN_0043abf0
{
    char* m_str;
    int m_iWordAt04;
    int m_8;
    NP m_ptr;

    FUN_0043abf0(const char* apStr, void* apPtr);
};

// @fnv 0x0043abf0
FUN_0043abf0::FUN_0043abf0(const char* apStr, void* apPtr) : m_ptr(0)
{
    unsigned int len = BSStringLength(apStr) + 1;
    m_str = new char[len];
    TaskQueueInterface::CopyStringToBuffer(m_str, len, apStr);
    m_ptr = apPtr;
    m_iWordAt04 = 0;
    m_8 = 0;
}
}  // namespace fnv_0043abf0

namespace fnv_0043baf0 {
void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSStringLength(const char*);
struct FUN_0043baf0;

struct FUN_0043baf0
{
    int field0;
    char* pName;
    int arg;
    char flag;
    char flag2;
    FUN_0043baf0(const char*, int);
};
// @fnv 0x0043baf0
FUN_0043baf0::FUN_0043baf0(const char* name, int aiArg)
{
    unsigned int len;
    char* buf;
    arg = aiArg;
    len = BSStringLength(name) + 1;
    buf = (char*)operator new(len);
    pName = buf;
    TaskQueueInterface::CopyStringToBuffer(pName, len, name);
    flag = ((ModelLoader*)g_modelLoader)->DispatchVirtualCall(pName, this);
    flag2 = 0;
    field0 = 0;
}
}  // namespace fnv_0043baf0

namespace fnv_0043bd10 {
bool __cdecl CleanPath(const char*, char*, unsigned int);

struct FUN_0043bd10 : public QueuedFileEntry
{
    GO go;
    bool flag;
    FUN_0043bd10(const char* apFileName, int aePriority);
    virtual ~FUN_0043bd10();
};
// @fnv 0x0043bd10
FUN_0043bd10::FUN_0043bd10(const char* apFileName, int aePriority) : QueuedFileEntry(aePriority), go(0)
{
    char szStandardPath[260];
    flag = false;
    CleanPath(apFileName, szStandardPath, 260);
    SetFileName_00c3cee0(szStandardPath);
    LookupFileEntryByArchive(1);
}
}  // namespace fnv_0043bd10

namespace fnv_0043be60 {
struct GeometryRelatedType;

struct FUN_0043be60 : public QueuedFileEntry
{
    GO go;
    char flag;
    FUN_0043be60(GeometryRelatedType*, int);
};
// @fnv 0x0043be60
FUN_0043be60::FUN_0043be60(GeometryRelatedType* shader, int arg) : QueuedFileEntry(arg), go(0)
{
    flag = 0;
    SetFileEntry(reinterpret_cast<::BSFileEntry*>(shader));
}
}  // namespace fnv_0043be60

namespace fnv_0043c6e0 {
// Use the model pointer so exception unwinding releases Model, not NiAVObject.
extern int DAT_01016890;

struct FUN_0043c7d0_shell
{
    void QueuedModel_SetAddRefCount(unsigned char);
};

struct FUN_0043c7a0_arg
{
    unsigned char b;
};

void __fastcall QueuedModel_SetPrepareAfterLoad(char*, FUN_0043c7a0_arg);

struct FUN_0043c6e0 : QueuedFileEntry
{
    NiPointer<Model> m_go;
    int m_34;
    int m_38;
    char m_3c;
    float m_40;

    FUN_0043c6e0(const char* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5);
    virtual ~FUN_0043c6e0();
};

// @fnv 0x0043c6e0
FUN_0043c6e0::FUN_0043c6e0(const char* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5) : QueuedFileEntry(a2), m_go(0)
{
    m_34 = 0;
    m_38 = a3;
    m_3c = 0;
    SetFileName_00c3cee0(a1);
    LookupFileEntryByArchive(0);
    QueuedModel_SetPrepareAfterLoad((char*)this, a4);
    ((FUN_0043c7d0_shell*)this)->QueuedModel_SetAddRefCount(a5);
    m_40 = 0.0f;
}
}  // namespace fnv_0043c6e0

namespace fnv_0043c890 {
// Use the model pointer so exception unwinding releases Model, not NiAVObject.
extern int DAT_01016890;

struct FUN_0043c7d0_shell
{
    void QueuedModel_SetAddRefCount(unsigned char);
};

struct FUN_0043c7a0_arg
{
    unsigned char b;
};

void __fastcall QueuedModel_SetPrepareAfterLoad(char*, FUN_0043c7a0_arg);

struct QueuedModelParam
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual const char* vfn5();
};

struct FUN_0043c890 : QueuedFileEntry
{
    NiPointer<Model> m_go;
    QueuedModelParam* m_34;
    int m_38;
    char m_3c;
    float m_40;

    FUN_0043c890(QueuedModelParam* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5);
    virtual ~FUN_0043c890();
};

// @fnv 0x0043c890
FUN_0043c890::FUN_0043c890(QueuedModelParam* apModelParam, int aiBaseArg, int a3, FUN_0043c7a0_arg aByteArg,
                           unsigned char a5)
    : QueuedFileEntry(aiBaseArg), m_go(0)
{
    m_34 = apModelParam;
    m_38 = a3;
    m_3c = 0;
    SetFileName_00c3cee0(apModelParam->vfn5());
    LookupFileEntryByArchive(0);
    QueuedModel_SetPrepareAfterLoad((char*)this, aByteArg);
    ((FUN_0043c7d0_shell*)this)->QueuedModel_SetAddRefCount(a5);
    m_40 = 0.0f;
}
}  // namespace fnv_0043c890

namespace fnv_0043e0f0 {
extern int _data_011c16bc;
struct FUN_0044afe0
{
    int v;
    FUN_0044afe0(int);
    ~FUN_0044afe0();
};

struct FUN_0043e0f0 : public QueuedFileEntry
{
    FUN_0044afe0 m;
    bool flag;
    FUN_0043e0f0(const char* apFileName, int aePriority);
};

// @fnv 0x0043e0f0
FUN_0043e0f0::FUN_0043e0f0(const char* apFileName, int aePriority) : QueuedFileEntry(aePriority), m(0)
{
    flag = false;
    SetFileName_00c3cee0(apFileName);
    LookupFileEntryByArchive(0);
}
}  // namespace fnv_0043e0f0

namespace fnv_0043e210 {
extern int _data_011c16bc;
void __fastcall SetFieldCToFive(char*);
struct FUN_0044afe0
{
    int v;
    FUN_0044afe0(int);
    ~FUN_0044afe0();
};

struct FUN_0043e210 : public QueuedFileEntry
{
    FUN_0044afe0 m;
    bool flag;
    FUN_0043e210(KFModel* apKF, int aePriority);
};

// Initializes the base with aePriority, clears m and flag, stores apKF into m, then calls SetFieldCToFive on this.
// @fnv 0x0043e210
FUN_0043e210::FUN_0043e210(KFModel* apKF, int aePriority) : QueuedFileEntry(aePriority), m(0)
{
    flag = false;
    ((NiPointer<KFModel>*)&m)->operator=(apKF);
    SetFieldCToFive((char*)this);
}
}  // namespace fnv_0043e210

namespace fnv_0043eaf0 {
struct QueuedFileBase
{
    char pad[0x24];
    QueuedFileBase(int);
    ~QueuedFileBase();
    virtual void vf();
};

struct FUN_0043eaf0 : public QueuedFileBase
{
    int owner;
    GO spA;
    GO spB;
    FUN_0043eaf0(int, int);
};
// Constructs a QueuedFileBase from b, stores a in owner, and default-constructs spA and spB with 0.
// @fnv 0x0043eaf0
FUN_0043eaf0::FUN_0043eaf0(int aiOwner, int aiBaseArg) : QueuedFileBase(aiBaseArg), owner(aiOwner), spA(0), spB(0)
{}
}  // namespace fnv_0043eaf0

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class NiCullingProcess;
class NiObject;
class NiUpdateData;
namespace fnv_0043ecb0 {

struct IncompleteStruct;
struct ReactionInfo;
struct CloningProcess;

struct blob48
{
    char b[48];
};

typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 4 ? 1 : -1];
struct FUN_0043ecb0_shell : public QueuedHead
{
    void QueuedHead_Run();
};

int __fastcall GetHavokWorldObjectCountInSceneGraph_0084e3a0(const void*);
void* __fastcall FUN_00726070(void*);
void __cdecl BSFaceGenManager_LockFaceGenAccess();
void __cdecl BSFaceGenManager_UnlockFaceGenAccess();

struct HeadLayout
{
    char pad[0x28];
    TESNPC* npc;
    NP skinned;
    NP biped;
};
// @fnv 0x0043ecb0
// src: XBOX_PDB 0x0043ecb0
void FUN_0043ecb0_shell::QueuedHead_Run()
{
    BSFaceGenManager_LockFaceGenAccess();
    AutoMemHelper tempMemContext(0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x5f9);
    unsigned int pbipedNode3;
    unsigned int pskinnedNode;
    pskinnedNode = 0;
    pbipedNode3 = 0;
    ((HeadLayout*)this)->npc->GetFaceGenNodes(&pskinnedNode, &pbipedNode3);
    ((HeadLayout*)this)->skinned = (void*)pskinnedNode;
    ((HeadLayout*)this)->biped = (void*)pbipedNode3;
    if (GetHavokWorldObjectCountInSceneGraph_0084e3a0(((HeadLayout*)this)->npc) == 7)
    {
        TESRace* prace = (TESRace*)FUN_00726070((char*)((HeadLayout*)this)->npc + 0x10c);
        prace->ClearFaceGenUndo();
    }
    BSFaceGenManager_UnlockFaceGenAccess();
}
}  // namespace fnv_0043ecb0

typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 4 ? 1 : -1];
struct FUN_00441ba0_shell : public QueuedPlayer
{
    void QueuedPlayer_QueueModels();
};

struct PC7d
{
    void LoadIdleAnimations(IO_TASK_PRIORITY, FUN_00441ba0_shell*);
};
extern PC7d* g_thePlayer;
extern int _data_011c16bc;

struct Q441560
{
    void LoadBipedModel();
};

// @fnv 0x00441ba0
// src: XBOX_PDB 0x00441ba0
void FUN_00441ba0_shell::QueuedPlayer_QueueModels()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x94e);
    g_thePlayer->LoadIdleAnimations(((IOTask*)this)->IOTask_GetIOTaskPriority(), this);
    ((Q441560*)this)->LoadBipedModel();
}

namespace fnv_00441d80 {
extern int _data_011c16bc;
void __fastcall SetFieldCToFive(char*);

struct FUN_00441d80 : public QueuedFileEntry
{
    NiPointer<LoadedFile> m_pLoadedFile;
    int m_iLoadPriority;
    FUN_00441d80(LoadedFile* apFile, int aePriority);
};

// @fnv 0x00441d80
FUN_00441d80::FUN_00441d80(LoadedFile* apFile, int aePriority) : QueuedFileEntry(aePriority), m_pLoadedFile(0)
{
    m_iLoadPriority = 3;
    m_pLoadedFile = apFile;
    SetFieldCToFive((char*)this);
}
}  // namespace fnv_00441d80

namespace fnv_00441f80 {
struct QueuedFileLoadBase
{
    char pad[0x34];
    QueuedFileLoadBase(int, int, int);
    ~QueuedFileLoadBase();
    virtual void vf();
};

struct MeshPtr
{
    int p;
    MeshPtr(int);
};
// Retained: QueuedFaceGenFile.h lacks the file-name/priority/index constructor
// and uses byte arrays instead of the owning object/mesh members.
struct FUN_00441f80 : public QueuedFileLoadBase
{
    GO m_kObject;
    MeshPtr m_pMesh;
    FUN_00441f80(int, int, int);
};
// Constructs a QueuedFileLoadBase with the given arguments and initialises its two member objects to zero.
// @fnv 0x00441f80
FUN_00441f80::FUN_00441f80(int a, int b, int c) : QueuedFileLoadBase(a, b, c), m_kObject(0), m_pMesh(0)
{}
}  // namespace fnv_00441f80

extern int DAT_01016e50;

void* __cdecl operator new(unsigned int);

#include "../../include/LockFreeQueue.h"

// Constructs a BackgroundCloneThread task manager thread, initializing its state and allocating a lock-free queue sized by aiMaxThreads.
// @fnv 0x004421d0
BackgroundCloneThread::BackgroundCloneThread(unsigned int aiMaxThreads) : BSTaskThread(3, "BackgroundCloneThread")
{
    m_iState = 0;
    m_bThirdThreadFlag = false;
    m_pCloneQueue = (Q449*)new LockFreeQueue<NiPointer<QueuedReference> >(aiMaxThreads, 8);
}

extern int _data_011c16bc;
struct QueueObj
{
    int state;
    QueueObj(int);
    ~QueueObj();
};
struct QueueModelHolder
{
    void ModelLoader_QueueModel_00443dc0(int, QueueObj*, int, int, int, bool, bool, bool, float);
    void ModelLoader_QueueModel(int apModel, int a, int b, int c, bool d, bool e, bool f);
};

// Constructs a QueueObj with state 0 and forwards it with the model and flags to FUN_00443dc0 using a zero float.
// @fnv 0x00443d30
// src: XBOX_PDB 0x00443d30
void QueueModelHolder::ModelLoader_QueueModel(int apModel, int aiArg1, int aiArg2, int aiArg3, bool abFlag1, bool abFlag2,
                                    bool abFlag3)
{
    QueueObj spqueuedModel(0);
    ModelLoader_QueueModel_00443dc0(apModel, &spqueuedModel, aiArg1, aiArg2, aiArg3, abFlag1, abFlag2, abFlag3, 0.0f);
}

class MagicItem;
class TESEffectShader;
class TESObjectLIGH;
class TESSound;
namespace fnv_00444f10 {

struct blob8
{
    char b[8];
};

typedef char _sizecheck_TESDescription[sizeof(TESDescription) == 8 ? 1 : -1];

typedef char _sizecheck_EffectSetting[sizeof(EffectSetting) == 176 ? 1 : -1];
struct FUN_00444f10_shell : public ModelLoader
{
    void ModelLoader_QueueMagicItem(MagicItem*, EffectSetting*, int);
};

struct GlobalObject_00528cb0Ptr
{
    GlobalObject_00528cb0Ptr(QueuedMagicItem*);
    ~GlobalObject_00528cb0Ptr();
    operator QueuedMagicItem*() const;
    QueuedMagicItem* p;
};

// @fnv 0x00444f10
// src: COMMUNITY 0x00444f10
void FUN_00444f10_shell::ModelLoader_QueueMagicItem(MagicItem* apMagicItem, EffectSetting* apAVEffectSetting, int aePriority)
{
    if (!apMagicItem || !apAVEffectSetting)
        return;
    GlobalObject_00528cb0Ptr spqueuedMagicItem(
        new QueuedMagicItem(reinterpret_cast<::MagicItem*>(apMagicItem), apAVEffectSetting, (IO_TASK_PRIORITY)aePriority));
    ((QueuedMagicItem*)spqueuedMagicItem)->DispatchToManager();
}
}  // namespace fnv_00444f10

struct PackedRecordData;

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;

struct MagicItemForm;
struct PackageList;
struct TESActorBase;
struct TESAmmo;
struct TESFaction;

struct TESLevItem;

typedef char _sizecheck_TESActorBaseData[sizeof(TESActorBaseData) == 52 ? 1 : -1];

typedef char _sizecheck_TESContainer[sizeof(TESContainer) == 12 ? 1 : -1];

typedef char _sizecheck_BGSTouchSpellForm[sizeof(BGSTouchSpellForm) == 12 ? 1 : -1];

typedef char _sizecheck_TESAIForm[sizeof(TESAIForm) == 32 ? 1 : -1];

typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];

typedef char _sizecheck_TESAnimation[sizeof(TESAnimation) == 12 ? 1 : -1];

typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];

typedef char _sizecheck_TESRaceForm[sizeof(TESRaceForm) == 8 ? 1 : -1];
struct FUN_00444fe0_shell : public ModelLoader
{
    void ModelLoader_QueueHead(TESNPC*, void*, int, QueuedFile*);
};

struct QHeadLocal
{
    QHeadLocal(TESNPC*, int);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    void SetParent(QueuedFile*);
    int pad[13];
};
struct QHeadPtr
{
    QHeadPtr(QHeadLocal*);
    ~QHeadPtr();
    operator QHeadLocal*() const;
    int p;
};
struct QHeadPtrDest
{
    QHeadPtrDest& Assign(const QHeadPtr&);
};
// Creates a QHeadLocal for apNPC at aePriority, sets its parent to apParent, runs its vfn_20, and assigns it into aspQueuedHead.
// @fnv 0x00444fe0
// src: XBOX_PDB 0x00444fe0
void FUN_00444fe0_shell::ModelLoader_QueueHead(TESNPC* apNPC, void* aspQueuedHead, int aePriority, QueuedFile* apParent)
{
    QHeadPtr spqueuedHead(new QHeadLocal(apNPC, aePriority));
    ((QHeadLocal*)spqueuedHead)->SetParent(apParent);
    ((QHeadLocal*)spqueuedHead)->vfn_20();
    ((QHeadPtrDest*)aspQueuedHead)->Assign(spqueuedHead);
}

void* __cdecl operator new(unsigned int);
struct QIdle
{
    QIdle(void*, int, void*, void*);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    int pad[15];
};
struct QIdlePtr
{
    QIdlePtr(QIdle*);
    ~QIdlePtr();
    operator QIdle*() const;
    QIdlePtr& operator=(QIdle*);
    int p;
};
struct IdleMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(void*, QIdlePtr*, int);
};
struct FUN_00445200_holder : public ModelLoader
{
    void* a;
    void* b;
    void* c;
    void* d;
    IdleMap* m_pQueuedAnimIdleMap;
    void* InsertIdle(void* apIdle, void* apKey, int aePriority, void* apParent);
};
// Allocates a QIdle from the given arguments, inserts it into the idle map by key, and calls its virtual slot 20 on success.
// @fnv 0x00445200
void* FUN_00445200_holder::InsertIdle(void* apIdle, void* apKey, int aePriority, void* apParent)
{
    QIdlePtr spqueuedIdle(new QIdle(apIdle, aePriority, apKey, apParent));
    if (m_pQueuedAnimIdleMap->Insert(apKey, &spqueuedIdle, 0))
        ((QIdle*)spqueuedIdle)->vfn_20();
    else
        spqueuedIdle = 0;
    return 0;
}

class NiControllerSequence;
class TESAnimGroup;
namespace fnv_004471c0 {
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_004471c0_shell : public ModelLoader
{
    KFModel* LoadKFModel(char*);
};

void __cdecl _FNV_Warning(const char*, ...);

struct Flt
{
    operator unsigned int() const;
    int pad[3];
};
struct KFMap
{
    virtual void Slot0();
    virtual void Slot1();
    virtual bool Get(const char*, KFModel**);
};
int __fastcall KFModel_GetRefCount(KFModel*);
// @fnv 0x004471c0
KFModel* FUN_004471c0_shell::LoadKFModel(char* apFilename)
{
    Flt autoEvent3;
    KFModel* pkfModel2 = 0;
    if (!((KFMap**)this)[1]->Get(apFilename, &pkfModel2))
    {
        QueuedKF queuedKF(apFilename, 0);
        queuedKF.QueuedKF_Run();
        queuedKF.QueuedKF_Finish();
        pkfModel2 = (KFModel*)(unsigned int)autoEvent3;
    }
    else
    {
        if (!KFModel_GetRefCount(pkfModel2))
            _FNV_Warning("MODELS: LoadKF retrieved animation %s with a zero ref count", apFilename);
    }
    if (pkfModel2)
        ((QueuedChildren*)pkfModel2)->AddFinishedChild();
    return pkfModel2;
}
}  // namespace fnv_004471c0

struct FUN_00447850_shell : public ModelLoader
{
    void* ModelLoader_CopyFilenameList(void*, void*);
};

void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSStringLength(const char*);
struct StrList
{
    StrList();
    void AddHead(char**);
    const char** FUN_006815c0();
    StrList* FUN_00726070();
    int pad[2];
};
// @fnv 0x00447850
// src: COMMUNITY 0x00447850
void* FUN_00447850_shell::ModelLoader_CopyFilenameList(void* apList, void* apDestList)
{
    StrList* pList = (StrList*)apList;
    StrList* pBaseList = (StrList*)apDestList;
    if (!pBaseList)
        pBaseList = new StrList;
    while (pList)
    {
        const char* pfilename = *pList->FUN_006815c0();
        int ifilenameLen = BSStringLength(pfilename) + 1;
        char* ptmpFilename = new char[ifilenameLen];
        TaskQueueInterface::CopyStringToBuffer(ptmpFilename, ifilenameLen, pfilename);
        pBaseList->AddHead(&ptmpFilename);
        pList = pList->FUN_00726070();
    }
    return pBaseList;
}

namespace fnv_00448c10 {
struct Flt
{
    operator unsigned int() const;
};
struct GlobalObject_00528cb0 : public Flt
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    void* pObj;
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release();
};

// Iterates the container at self+0x1c via FUN_00449280, calling Release on each object until the iterator is empty, then returns true.
// @fnv 0x00448c10
bool __fastcall ReleaseAllObjects(char* self)
{
    GlobalObject_00528cb0 iter(0);
    ((Q449*)*(void**)(self + 0x1c))->LockFreeQueue_NiPointer_IOTask_Pop(&iter);
    while (iter)
    {
        ((Obj*)(unsigned int)iter)->Release();
        ((Q449*)*(void**)(self + 0x1c))->LockFreeQueue_NiPointer_IOTask_Pop(&iter);
    }
    return true;
}
}  // namespace fnv_00448c10

namespace fnv_00448ed0 {
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct FUN_00448ed0_shell : public ModelLoader
{
    bool InsertQueuedTexture(BSFileEntry*, QueuedTexture*);
};

struct GlobalObject_00528cb0
{
    int value;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};
struct QueuedTextureMapStandIn
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(BSFileEntry*, GlobalObject_00528cb0*, int);
};
// Wraps apQueuedTexture in a GlobalObject_00528cb0 and inserts apFileEntry with it into the map at this+0x20, returning the insert result.
// @fnv 0x00448ed0
bool FUN_00448ed0_shell::InsertQueuedTexture(BSFileEntry* apFileEntry, QueuedTexture* apQueuedTexture)
{
    bool bresult;
    {
        GlobalObject_00528cb0 obj((int)apQueuedTexture);
        bresult = (*(QueuedTextureMapStandIn**)((char*)this + 0x20))->Insert(apFileEntry, &obj, 0);
    }
    return bresult;
}
}  // namespace fnv_00448ed0

namespace fnv_00448f80 {
struct Flt
{
    operator unsigned int() const;
};
struct GlobalObject_00528cb0 : public Flt
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    void* pObj;
};
struct Target
{
    virtual void v0();
    virtual void v1();
    virtual bool Test(void*, void*);
};
struct Holder
{
    unsigned int ModelLoader_GetQueuedTextureFromMap(void* arg);
    char pad[0x20];
    Target* pTarget;
};

// @fnv 0x00448f80
// src: COMMUNITY 0x00448f80
unsigned int Holder::ModelLoader_GetQueuedTextureFromMap(void* arg)
{
    GlobalObject_00528cb0 iter(0);
    if (pTarget->Test(arg, &iter))
    {
        return iter;
    }
    return 0;
}
}  // namespace fnv_00448f80

struct VecAllocBase
{
    int* ForwardCall_0044abd0(unsigned int);
};
void __cdecl ThrowVectorTooLong();
struct VecAlloc
{
    char pad[0xc];
    int* pBegin;
    int* pCur;
    int* pEnd;
    unsigned int FaceGenData_Return1();
    bool InitializeElementStorage(unsigned int);
};
// Resets the vector to empty, then allocates space for n elements if n is nonzero and the capacity allows; returns true on success.
// @fnv 0x0044a240
// src: GUESS 0x0044a240 (confidence: medium)
bool VecAlloc::InitializeElementStorage(unsigned int n)
{
    pBegin = 0;
    pCur = 0;
    pEnd = 0;
    if (n == 0)
    {
        return false;
    }
    else
    {
        if (FaceGenData_Return1() < n)
        {
            ThrowVectorTooLong();
        }
        else
        {
            pBegin = ((VecAllocBase*)((char*)this + 8))->ForwardCall_0044abd0(n);
            pCur = pBegin;
            pEnd = pBegin + n;
        }
    }
    return true;
}

namespace fnv_006502f0 {

struct Flt
{
    operator unsigned int() const;
};
struct Helper62d0
{
    Helper62d0& operator=(void*);
};
struct Map62d0
{
    bool NiTMapBase_DFALL_NiTMapItem_bhkRigidBody_NiPointer_ObstacleData_bhkRigidBody_NiPointer_ObstacleData_GetAt(unsigned int, NP&);
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int GetFlags();
};
struct FlagSink
{
    void ProcessAndReturnValue_0044b300(unsigned int);
};
void __cdecl BSFaceGenManager_LockFaceGenAccess();
void __cdecl BSFaceGenManager_UnlockFaceGenAccess();
struct GetAtArgs
{
    const char* apcKey;
    Helper62d0* aspModel;
    FlagSink* out;
};

// Looks up args.apcKey in the map at self+4, stores the found entry's model pointer and passes its flags to args.out, returning whether the lookup succeeded.
// @fnv 0x006502f0
bool __fastcall LookupModelAndGetFlags(Map62d0* self, GetAtArgs aLookupArgs)
{
    BSFaceGenManager_LockFaceGenAccess();
    NP entry(0);
    bool bFound = false;
    if (((Map62d0*)((char*)self + 4))->NiTMapBase_DFALL_NiTMapItem_bhkRigidBody_NiPointer_ObstacleData_bhkRigidBody_NiPointer_ObstacleData_GetAt((unsigned int)aLookupArgs.apcKey, entry))
    {
        *aLookupArgs.aspModel = (void*)((unsigned int)*(Flt*)&entry + 8);
        aLookupArgs.out->ProcessAndReturnValue_0044b300(
            ((TESObjectREFR_GetFlags_Helper*)(unsigned int)*(Flt*)aLookupArgs.aspModel)->GetFlags());
        bFound = true;
    }
    BSFaceGenManager_UnlockFaceGenAccess();
    return bFound;
}
}  // namespace fnv_006502f0

// @fnv 0x0043b1d0
// src: XBOX_PDB 0x0043b1d0
int __cdecl NiGlobalStringTable_GetString(int* param_1)
{
    return *param_1;
}

struct AbstractHeapLogger;
extern AbstractHeapLogger* DAT_011f6388;

// @fnv 0x0043bce0
bool IsHeapLoggerPresent()
{
    return DAT_011f6388 != 0;
}

namespace fnv_0043bd00 {
struct AbstractHeapLogger;
extern AbstractHeapLogger* DAT_011f6388;

// @fnv 0x0043bd00
// src: COMMUNITY 0x0043bd00
AbstractHeapLogger* BSCoreMessage_GetInstance()
{
    return DAT_011f6388;
}
}  // namespace fnv_0043bd00

void _Deallocate(void*);

struct FUN_0051d400_shell
{
    void ReleaseStorage_0051d400();
    void* DeleteIfFlagged(unsigned int flags);
};

// @fnv 0x0043d640
void* FUN_0051d400_shell::DeleteIfFlagged(unsigned int flags)
{
    ReleaseStorage_0051d400();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void QueuedTreeBillboard::ApplyQueuedTexture()
{}

// @fnv 0x0043d670
void QueuedTreeBillboard::QueueForPostProcess()
{
    ApplyQueuedTexture();
    AddToPostProcessQueue();
}

struct FaceGenPaletteBase
{
    ~FaceGenPaletteBase();
    void ForwardCall_0043dc50();
};

// @fnv 0x0043dc50
// src: GUESS 0x0043dc50 (confidence: low)
void FaceGenPaletteBase::ForwardCall_0043dc50()
{
    FaceGenPaletteBase::~FaceGenPaletteBase();
}

// @fnv 0x0043eff0
// src: XBOX_PDB 0x0043eff0
void QueuedHelmet::PostProcess()
{
    ApplyQueuedModels();
}

struct FUN_0043f010
{
    char m_auiShapeKeys[0x2b0];
    NiRenderer* m_field;
    NiRenderer* Get();
};

// @fnv 0x0043f010
NiRenderer* FUN_0043f010::Get()
{
    return m_field;
}

namespace fnv_0043f1f0 {
extern "C"
{
    void __cdecl SetFlagBit0(unsigned char, void*);
}

struct FUN_0043f1f0_class
{
    void __thiscall QueuedHelmet_SetFinishedQueuing(unsigned char arg);
};

// @fnv 0x0043f1f0
// src: XBOX_PDB 0x0043f1f0
void __thiscall FUN_0043f1f0_class::QueuedHelmet_SetFinishedQueuing(unsigned char arg)
{
    SetFlagBit0(arg, (void*)((char*)this + 0x120));
}
}  // namespace fnv_0043f1f0

void __cdecl _Deallocate(void*);

// Calls FUN_004406b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00440680
void* AttachDistant3DTask::FUN_00440680(unsigned int flags)
{
    FUN_004406b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00441980_Class
{
    void ForwardCall_00440eb0();
    void DoNothing_00441980();
};

// @fnv 0x00441980
// src: GUESS 0x00441980 (confidence: high)
void FUN_00441980_Class::DoNothing_00441980()
{
    ForwardCall_00440eb0();
}

// Calls FUN_004422c0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00442290
void* BackgroundCloneThread::FUN_00442290(unsigned int flags)
{
    this->BackgroundCloneThread::~BackgroundCloneThread();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00442630Class
{
    char m_auiShapeKeys[0x30];
    char m_flag;
    void BackgroundCloneThread_SetExiting();
};
// @fnv 0x00442630
// src: COMMUNITY 0x00442630
void FUN_00442630Class::BackgroundCloneThread_SetExiting()
{
    m_flag = 1;
}

// @fnv 0x00446a40
// src: XBOX_PDB 0x00446a40
void QueuedReplacementKFList::CheckFinished()
{
    IOTask::NotifyParents();
}

struct FUN_00449170_Class
{
    void BSTask_int64_SetTaskCanceled();
};

// @fnv 0x00449170
// src: XBOX_PDB 0x00449170
void FUN_00449170_Class::BSTask_int64_SetTaskCanceled()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xC) = 6;
}

struct FUN_00449a20_cls
{
    void DoNothing_004490e0();
    void* FUN_00449a20(unsigned int flags);
};

void _Deallocate(void* p);

// Calls FUN_004490e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00449a20
void* FUN_00449a20_cls::FUN_00449a20(unsigned int flags)
{
    DoNothing_004490e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
void __fastcall Object_SetVirtualTable_004499c0(void*);

struct FUN_00449ba0Class
{
    void* FUN_00449ba0(unsigned int flags);
};

// @fnv 0x00449ba0
void* FUN_00449ba0Class::FUN_00449ba0(unsigned int flags)
{
    Object_SetVirtualTable_004499c0(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __fastcall Object_SetVirtualTable_004499e0(void*);
void __cdecl _Deallocate(void*);

struct FUN_00449bd0_Class
{
    void* FUN_00449bd0(unsigned int flags);
};

// Calls FUN_004499e0 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00449bd0
void* FUN_00449bd0_Class::FUN_00449bd0(unsigned int flags)
{
    Object_SetVirtualTable_004499e0(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __fastcall Object_SetVirtualTable_00449a00(int**);
void __cdecl _Deallocate(void*);

struct FUN_00449c00_class
{
    void* FUN_00449c00(unsigned int flags);
};

// @fnv 0x00449c00
void* FUN_00449c00_class::FUN_00449c00(unsigned int flags)
{
    Object_SetVirtualTable_00449a00((int**)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

NiRenderer* NiXenonRenderer_GetRenderer();
const NiFixedString& BSXFlags_Tag();

struct FUN_00449d40_class
{
    void __thiscall FUN_00449d60();
    void __thiscall ForwardCall_00449d40();
};

// @fnv 0x00449d40
// src: GUESS 0x00449d40 (confidence: low)
void __thiscall FUN_00449d40_class::ForwardCall_00449d40()
{
    FUN_00449d60();
}

NiRenderer* NiXenonRenderer_GetRenderer();
const NiFixedString& BSXFlags_Tag();

struct FUN_00449ea0_cls
{
    void FUN_00449ec0();
    void ForwardCall_00449ea0();
};

// @fnv 0x00449ea0
// src: GUESS 0x00449ea0 (confidence: low)
void FUN_00449ea0_cls::ForwardCall_00449ea0()
{
    FUN_00449ec0();
}

extern unsigned char DAT_01202df0;

// @fnv 0x0044ada0
// src: COMMUNITY 0x0044ada0
void BSTaskThread_SetPauseSleepEnabled(unsigned char value)
{
    DAT_01202df0 = value;
}

namespace fnv_0044ae10 {
// @fnv 0x0044ae10
// src: XBOX_PDB 0x0044ae10
unsigned char MLGetFlag_1(unsigned char a)
{
    return (a & 1) != 0;
}
}  // namespace fnv_0044ae10

// Sets or clears bit 0 of the byte pointed to by p according to flag.
// @fnv 0x0044ae20
void SetFlagBit0(bool abSet, unsigned char* p)
{
    if (abSet)
        *p |= 1;
    else
        *p &= 0xfffffffe;
}

namespace fnv_0044ae50 {
// @fnv 0x0044ae50
// src: XBOX_PDB 0x0044ae50
unsigned char __cdecl MLGetFlag_2(unsigned char a)
{
    return (a & 2) != 0;
}
}  // namespace fnv_0044ae50

// @fnv 0x0044ae60
// src: XBOX_PDB 0x0044ae60
void MLSetFlag_2(bool bSet, unsigned char* pFlags)
{
    if (bSet)
        *pFlags |= 2;
    else
        *pFlags &= 0xfffffffd;
}

namespace fnv_0044ae90 {
// @fnv 0x0044ae90
// src: XBOX_PDB 0x0044ae90
char MLGetFlag_4(unsigned char param_1)
{
    return (param_1 & 4) != 0;
}
}  // namespace fnv_0044ae90

// @fnv 0x0044aea0
// src: XBOX_PDB 0x0044aea0
void MLSetFlag_4(bool abSet, unsigned char* flags)
{
    if (abSet)
        *flags = *flags | 4;
    else
        *flags = *flags & 0xfffffffb;
}

namespace fnv_0044af20 {
// @fnv 0x0044af20
// src: COMMUNITY 0x0044af20
char HasFlag8_0044af20(unsigned char a)
{
    return (a & 8) != 0;
}
}  // namespace fnv_0044af20

// Sets or clears bit 3 (0x8) in the byte pointed to by param2 according to param1.
// @fnv 0x0044af30
void SetFlag8(unsigned char param1, unsigned char* param2)
{
    if (param1)
        *param2 |= 8;
    else
        *param2 &= 0xfffffff7;
}

namespace fnv_0044af60 {
// @fnv 0x0044af60
// src: GUESS 0x0044af60 (confidence: medium)
char Object_IsMask0x10Set(unsigned char a)
{
    return (a & 0x10) != 0;
}
}  // namespace fnv_0044af60

// Sets or clears bit 0x10 in the byte pointed to by pByte according to bFlag.
// @fnv 0x0044af70
// src: XBOX_PDB 0x0044af70
void MLSetFlag_16(bool bFlag, unsigned char* pByte)
{
    if (bFlag)
        *pByte = *pByte | 0x10;
    else
        *pByte = *pByte & 0xFFFFFFEF;
}

// Sets or clears bit 0x20 in the byte pointed to by param2 according to param1.
// @fnv 0x0044afb0
void SetFlag20(unsigned char abSet, unsigned char* pFlags)
{
    if (abSet)
        *pFlags |= 0x20;
    else
        *pFlags &= 0xFFFFFFDF;
}

namespace fnv_0044b030 {
struct KFModel
{
    KFModel* vtable;
    void ReleaseKFModelReference();
    void KFModel_DecRefCount();
};

// @fnv 0x0044b030
// src: GUESS 0x0044b030 (confidence: high)
void KFModel::ReleaseKFModelReference()
{
    if (vtable)
        vtable->KFModel_DecRefCount();
}
}  // namespace fnv_0044b030

int __cdecl InitScriptRunLock(void*);

struct FUN_0044b2a0_Class
{
    void __thiscall InitScriptRunLock_Thunk();
};

// @fnv 0x0044b2a0
// src: GUESS 0x0044b2a0 (confidence: medium)
void __thiscall FUN_0044b2a0_Class::InitScriptRunLock_Thunk()
{
    InitScriptRunLock((char*)this + 0x20);
}

void __cdecl FinishScriptRunLock(void*);

struct FUN_0044b2e0
{
    void Method(void);
};

// @fnv 0x0044b2e0
void __thiscall FUN_0044b2e0::Method(void)
{
    FinishScriptRunLock((char*)this + 0x20);
}

// @fnv 0x0044dff0
// src: COMMUNITY 0x0044dff0
bool __fastcall LockFreeMap_MarkedPointer_GetMark(int* piValue)
{
    return (*piValue & 1) ? true : false;
}

extern unsigned char DAT_011dea2a;

// @fnv 0x00525420
// src: XBOX_PDB 0x00525420
unsigned char Main_GetSceneIsComplex()
{
    return DAT_011dea2a;
}

void __cdecl BSSleep(unsigned long);
int __cdecl BSAtomicCompareExchange(long volatile*, long, long);
struct FUN_0043b410_class
{
    void AtomicAdd(int a);
};
// Atomically adds a to the pointer stored at this+8, retrying with FUN_0040fca0(0) until the compare-and-swap succeeds.
// @fnv 0x0043b410
void FUN_0043b410_class::AtomicAdd(int aiDelta)
{
    long volatile* p = *(long volatile**)((char*)this + 8);
    while (BSAtomicCompareExchange((long volatile*)((char*)this + 8), (long)p, (long)p + aiDelta) != (long)p)
    {
        BSSleep(0);
        p = *(long volatile**)((char*)this + 8);
    }
}

// @fnv 0x0043c3b0
unsigned int BSFileEntry::Offset()
{
    return iOffset & 0x7fffffff;
}

// @fnv 0x0043db00
bool QueuedTreeModel::GetTreeModelDescription(char* apDescription, unsigned int aiBufferSize)
{
    return QueuedFileEntry_GetDescription(apDescription, aiBufferSize, "tree model");
}

class Flt
{
  public:
    operator unsigned int();
};

// @fnv 0x0043e940
// src: XBOX_PDB 0x0043e940
void QueuedReplacementKF::Finish_0043e940()
{
    QueuedKF_Finish();
    if (((Flt*)((char*)this + 0x30))->operator unsigned int())
    {
        if (!BSTask_int64_GetTaskCanceled())
        {
            if (*(QueuedReplacementKF**)((char*)this + 0x3c))
            {
                (*(QueuedReplacementKF**)((char*)this + 0x3c))->IncrementCounter();
            }
            ((IOTask*)this)->AddToPostProcessQueue();
        }
    }
}

namespace fnv_0043ea00 {

}  // namespace fnv_0043ea00

struct FUN_00440640_shell
{
    void ForwardCall_00440640();
    void* FUN_00440610(unsigned int flags);
};

void _Deallocate(void*);

// Calls FUN_00440640, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00440610
void* FUN_00440640_shell::FUN_00440610(unsigned int flags)
{
    ForwardCall_00440640();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00440e30_This
{
    NiNode* TESForm_GetFormTypeString();
};

extern unsigned char DAT_1187004[];

// @fnv 0x00440e30
// src: XBOX_PDB 0x00440e30
NiNode* FUN_00440e30_This::TESForm_GetFormTypeString()
{
    return *(NiNode**)(DAT_1187004 + (*(unsigned char*)((char*)this + 4)) * 0xc);
}

namespace fnv_00440e80 {
struct FUN_00441980_Class
{
    void ForwardCall_00440eb0(void);
    void* FUN_00440e80(unsigned int flags);
};
void _Deallocate(void* p);
// Calls FUN_00440eb0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00440e80
void* FUN_00441980_Class::FUN_00440e80(unsigned int flags)
{
    ForwardCall_00440eb0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00440e80

namespace fnv_00441950 {
struct FUN_00441980_Class
{
    void DoNothing_00441980(void);
    void* FUN_00441950(unsigned int flags);
};

// src: GUESS 0x00441980 (confidence: high)
void FUN_00441980_Class::DoNothing_00441980(void)
{}

extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00441980, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00441950
void* FUN_00441980_Class::FUN_00441950(unsigned int flags)
{
    DoNothing_00441980();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00441950

void __cdecl SetFlag20(unsigned char, unsigned char*);

struct FUN_00443ff0Class
{
    void __thiscall QueuedModel_SetFaceGenModel(unsigned char arg);
};

// Calls SetFlag20 with arg and the byte pointer at offset 0x3c of this object.
// @fnv 0x00443ff0
// src: XBOX_PDB 0x00443ff0
void __thiscall FUN_00443ff0Class::QueuedModel_SetFaceGenModel(unsigned char aucValue)
{
    SetFlag20(aucValue, (unsigned char*)this + 0x3c);
}

namespace fnv_00446a10 {
struct FaceGenPaletteBase
{
    void ForwardCall_0043dc50(void);
    void* FUN_00446a10(unsigned int flags);
};

void _Deallocate(void* p);

// Calls FUN_0043dc50, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00446a10
void* FaceGenPaletteBase::FUN_00446a10(unsigned int flags)
{
    ForwardCall_0043dc50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00446a10

struct FUN_00449920Class
{
    void UpdateFields_00449920();
};

// @fnv 0x00449920
// src: GUESS 0x00449920 (confidence: low)
void FUN_00449920Class::UpdateFields_00449920()
{
    ((char*)this)[0x10] = 0;
}

NiRenderer* NiXenonRenderer_GetRenderer();
const NiFixedString& BSXFlags_Tag();

extern void _Deallocate(void*);

struct FUN_00449a50_StandIn
{
    void CallBaseMethod();
    void* FUN_00449a50(unsigned int flags);
};

// Calls CallBaseMethod, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449a50
void* FUN_00449a50_StandIn::FUN_00449a50(unsigned int flags)
{
    CallBaseMethod();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00449a80 {
struct FUN_00449d40_class
{
    void ForwardCall_00449d40();
    void* LockFreeCaseInsensitiveStringMap_KFModel_Destroy(unsigned int flags);
};
void _Deallocate(void*);

// Calls FUN_00449d40, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449a80
// src: COMMUNITY 0x00449a80
void* FUN_00449d40_class::LockFreeCaseInsensitiveStringMap_KFModel_Destroy(unsigned int flags)
{
    ForwardCall_00449d40();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449a80

namespace fnv_00449ae0 {
extern void* __cdecl _Deallocate(void*);

struct FUN_00449ae0_Class
{
    void* __thiscall DestroyModelLoader(unsigned int flags);
};

// @fnv 0x00449ae0
void* __thiscall FUN_00449ae0_Class::DestroyModelLoader(unsigned int flags)
{
    ((ModelLoader*)this)->ForwardCall_004431d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449ae0

void __fastcall Object_SetVirtualTable_00449940(void**);

struct FUN_00449b10_Class
{
    void* __thiscall FUN_00449b10(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x00449b10
void* __thiscall FUN_00449b10_Class::FUN_00449b10(unsigned int flags)
{
    Object_SetVirtualTable_00449940((void**)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00449c50_class
{
    int __thiscall FUN_00449c50();
};

struct FUN_00449c30_class : FUN_00449c50_class
{
    int __thiscall CallBaseMethod();
};

// @fnv 0x00449c30
int __thiscall FUN_00449c30_class::CallBaseMethod()
{
    return FUN_00449c50();
}

namespace fnv_00449f20 {
struct FUN_00449ea0_cls
{
    void FUN_00449ec0();
    void* __thiscall FUN_00449f20(unsigned int flags);
};

extern "C" void* __cdecl _Deallocate(void*);

// @fnv 0x00449f20
void* __thiscall FUN_00449ea0_cls::FUN_00449f20(unsigned int flags)
{
    FUN_00449ea0_cls::FUN_00449ec0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449f20

namespace fnv_0044afa0 {
// @fnv 0x0044afa0
// src: GUESS 0x0044afa0 (confidence: medium)
char Object_IsMask0x20Set(unsigned char param_1)
{
    return (param_1 & 0x20) != 0;
}
}  // namespace fnv_0044afa0

namespace fnv_0044b270 {
struct FUN_0044b2a0_Class
{
    void InitScriptRunLock_Thunk(void);
};

class FUN_0044b270_Class
{
  public:
    FUN_0044b2a0_Class* m_pData;
    FUN_0044b270_Class* SetDataAndNotify(FUN_0044b2a0_Class* a);
};

// Stores the given object in m_pData and, if it is non-null, calls its FUN_0044b2a0 method; returns this.
// @fnv 0x0044b270
// src: GUESS 0x0044b270 (confidence: medium)
FUN_0044b270_Class* FUN_0044b270_Class::SetDataAndNotify(FUN_0044b2a0_Class* apData)
{
    m_pData = apData;
    if (m_pData != 0)
    {
        m_pData->InitScriptRunLock_Thunk();
    }
    return this;
}
}  // namespace fnv_0044b270

extern int DAT_010172b8;

struct FUN_0044cc10
{
    int* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    char m_iThirdValue;
    FUN_0044cc10();
};

// @fnv 0x0044cc10
FUN_0044cc10::FUN_0044cc10()
{
    m_iWordAt00 = &DAT_010172b8;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

// @fnv 0x0044dec0
int __fastcall ClearLowBit(int* piValue)
{
    return *piValue & 0xfffffffe;
}

struct FUN_0044df00Class
{
    void __thiscall ClearLowBit();
    void __thiscall ClearLowBit_Thunk();
};

// @fnv 0x0044df00
// src: GUESS 0x0044df00 (confidence: medium)
void __thiscall FUN_0044df00Class::ClearLowBit_Thunk()
{
    ClearLowBit();
}

void __cdecl MLSetFlag_2(unsigned char, void*);
struct FUN_0043c0d0_class
{
    void __thiscall ForwardByteToMember(unsigned char);
};
// Passes a to FUN_0044ae60 together with the pointer at this+0x34.
// @fnv 0x0043c0d0
void __thiscall FUN_0043c0d0_class::ForwardByteToMember(unsigned char aByte)
{
    MLSetFlag_2(aByte, reinterpret_cast<char*>(this) + 0x34);
}

namespace fnv_0043c960 {
// Use the model pointer so exception unwinding releases Model, not NiAVObject.

void __fastcall SetFieldCToFive(char*);

struct FUN_0043c960 : QueuedFileEntry
{
    NiPointer<Model> m_go;
    int m_field34;
    int m_field38;
    char m_field3c;
    float m_field40;

    FUN_0043c960(void* param1, int param2);
    virtual ~FUN_0043c960();
};

// @fnv 0x0043c960
FUN_0043c960::FUN_0043c960(void* param1, int param2) : QueuedFileEntry(param2), m_go(0), m_field34(0), m_field38(0), m_field3c(0)
{
    reinterpret_cast<::GO*>(&m_go)->FUN_0044aed0(param1);
    SetFieldCToFive((char*)this);
    m_field40 = 0.0f;
}
}  // namespace fnv_0043c960

namespace fnv_0043e880 {

struct FUN_0043e880_Class
{
    bool QueuedAnimIdle_GetDescription(char* apDescription, unsigned int aiBufferSize);
};

// Forwards the description and buffer size to FUN_00c3d0e0 with the "AnimIdle" tag and returns its result.
// @fnv 0x0043e880
// src: XBOX_PDB 0x0043e880
bool FUN_0043e880_Class::QueuedAnimIdle_GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<QueuedTreeModel*>(this)->QueuedFileEntry_GetDescription(apDescription, aiBufferSize, "AnimIdle");
}
}  // namespace fnv_0043e880

struct FUN_0043e920_class
{
    void FUN_0043e1b0();
    void DoNothing_0043e920();
};

// @fnv 0x0043e920
// src: GUESS 0x0043e920 (confidence: high)
void FUN_0043e920_class::DoNothing_0043e920()
{
    FUN_0043e1b0();
}

// @fnv 0x0043e990
void QueuedReplacementKF::IncrementCounter()
{
    *(int*)((char*)this + 0x2c) = *(int*)((char*)this + 0x2c) + 1;
}

namespace fnv_0043fc10 {

extern "C" int __cdecl _sprintf_s(char* apDest, unsigned int aiSize, const char* apFormat, ...);

// Writes a formatted "Queued helmet for biped anim %08X" string using m_28 into apDescription and returns true.

}  // namespace fnv_0043fc10

namespace fnv_00440e50 {
extern int DAT_01016c5c;
struct S4411
{
    void FUN_0043fd40(int a, int b);
    void* InitWithGlobal(int a, int b);
};
// Calls FUN_0043fd40 with the two arguments, stores the address of DAT_01016c5c at the start of this, and returns this.
// @fnv 0x00440e50
void* S4411::InitWithGlobal(int aiArg1, int aiArg2)
{
    FUN_0043fd40(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &DAT_01016c5c;
    return this;
}
}  // namespace fnv_00440e50

struct FUN_00440eb0_class
{
    void FUN_0043fe40();
    void ForwardCall_00440eb0();
};

// @fnv 0x00440eb0
// src: GUESS 0x00440eb0 (confidence: low)
void FUN_00440eb0_class::ForwardCall_00440eb0()
{
    FUN_0043fe40();
}

namespace fnv_00441920 {
extern int DAT_01016d34;
struct FUN_004411d0
{
    int* m_vft;
    int m_kPointA;
    int m_kPointB;
    FUN_004411d0(int a, int b);
};
struct FUN_00441920 : FUN_004411d0
{
    FUN_00441920(int a, int b);
};
// Constructs the object by forwarding a and b to the base constructor and setting m_vft to DAT_01016d34.
// @fnv 0x00441920
FUN_00441920::FUN_00441920(int a, int b) : FUN_004411d0(a, b)
{
    m_vft = &DAT_01016d34;
}
}  // namespace fnv_00441920

namespace fnv_00441c50 {

struct LoadedFile;
typedef char _sizecheck_QueuedFileEntry[sizeof(QueuedFileEntry) == 48 ? 1 : -1];

typedef char _sizecheck_QueuedFileLoad[sizeof(QueuedFileLoad) == 56 ? 1 : -1];

int __cdecl ModelLoader_GetArchiveTypeIndexForIOFileIndex(int);
// Retained: QueuedFileLoad.h lacks the file-name/priority/index constructor
// and an owning loaded-file member for its constructor/destructor unwind paths.
struct FUN_00441c50 : QueuedFileEntry
{
    NiPointer<LoadedFile> sp;
    int m_iLoadPriority;
    FUN_00441c50(char const*, int, int);
};
// @fnv 0x00441c50
FUN_00441c50::FUN_00441c50(char const* a, int b, int c)
    : QueuedFileEntry(b), sp((LoadedFile*)0), m_iLoadPriority(c)
{
    SetFileName_00c3cee0(a);
    LookupFileEntryByArchive(ModelLoader_GetArchiveTypeIndexForIOFileIndex(m_iLoadPriority));
}
}  // namespace fnv_00441c50

namespace fnv_00442130 {
struct FUN_00441d80
{
    FUN_00441d80(int, int);
    ~FUN_00441d80();
    virtual void vfunc();
    char pad[0x34];
};

struct FUN_0044b270
{
    FUN_0044b270(int);
    ~FUN_0044b270();
    void ProcessAndReturnValue_0044b300(void*);
};

struct FUN_00442130 : FUN_00441d80
{
    GO m_model;
    FUN_0044b270 m_meshData;

    FUN_00442130(void* apModel, void* apMeshData);
    virtual ~FUN_00442130();
};

// Constructs the object with base parameters 0 and 5, assigns apModel to m_model and passes apMeshData to m_meshData.FUN_0044b300.
// @fnv 0x00442130
FUN_00442130::FUN_00442130(void* apModel, void* apMeshData) : FUN_00441d80(0, 5), m_model(0), m_meshData(0)
{
    m_model = apModel;
    m_meshData.ProcessAndReturnValue_0044b300(apMeshData);
}
}  // namespace fnv_00442130

struct FUN_00444d00_Class
{
    bool __thiscall Projectile_IsFlagSet(int mask);
};

// @fnv 0x00444d00
// src: XBOX_PDB 0x00444d00
bool __thiscall FUN_00444d00_Class::Projectile_IsFlagSet(int mask)
{
    return (*(int*)((char*)this + 0xC8) & mask) ? true : false;
}

namespace fnv_00446f70 {
struct FUN_00442510_Cl
{
    void BSTaskThread_WaitPause();
};

struct FUN_00446f70_Cl : ModelLoader
{
    void BSTaskThread_Sleep();
};

// @fnv 0x00446f70
// src: COMMUNITY 0x00446f70
void FUN_00446f70_Cl::BSTaskThread_Sleep()
{
    ProcessQueuedFile();
    ((FUN_00442510_Cl*)this)->BSTaskThread_WaitPause();
}
}  // namespace fnv_00446f70

void __fastcall SignalAtOffset18(char*);

struct FUN_00446ff0 : ModelLoader
{
    void ProcessQueuedFileAndSignal();
};

// @fnv 0x00446ff0
// src: GUESS 0x00446ff0 (confidence: high)
void FUN_00446ff0::ProcessQueuedFileAndSignal()
{
    ProcessQueuedFile();
    SignalAtOffset18(reinterpret_cast<char*>(this));
}

struct FUN_00448a20_class
{
    int a;
    int b;
    int c;
    bool TESForm_GetFireOff() const;
};
// @fnv 0x00448a20
// src: XBOX_PDB 0x00448a20
bool FUN_00448a20_class::TESForm_GetFireOff() const
{
    return (c & 0x80) ? true : false;
}

namespace fnv_00449030 {
struct FUN_00442630Class
{
    void BackgroundCloneThread_SetExiting(void);
};

struct FUN_00449030Class
{
    char pad[0x28];
    FUN_00442630Class* m_p;
    void CallMemberFunction(void);
};

// @fnv 0x00449030
void FUN_00449030Class::CallMemberFunction(void)
{
    m_p->BackgroundCloneThread_SetExiting();
}
}  // namespace fnv_00449030

namespace fnv_004490e0 {
extern int DAT_01017138;
extern int DAT_011c3b38;
int __cdecl FinishScriptRunLock(void*);

struct FUN_004490e0_Class
{
    void* m_p;
    void DoNothing_004490e0();
};

// Points m_p at DAT_01017138 and calls FinishScriptRunLock on DAT_011c3b38.
// @fnv 0x004490e0
// src: GUESS 0x004490e0 (confidence: high)
void FUN_004490e0_Class::DoNothing_004490e0()
{
    m_p = &DAT_01017138;
    FinishScriptRunLock(&DAT_011c3b38);
}
}  // namespace fnv_004490e0

struct FUN_0044ee20_class
{
    int GetElementAddress(int index);
};

// @fnv 0x0044ee20
int FUN_0044ee20_class::GetElementAddress(int index)
{
    return *(int*)((char*)this + 0xc) + index * 4;
}

struct FUN_00905330
{
    void __thiscall Remove(void*);
};
struct FUN_0044f870
{
    void __thiscall Remove_Thunk(void* ap);
};
// @fnv 0x0044f870
// src: GUESS 0x0044f870 (confidence: medium)
void __thiscall FUN_0044f870::Remove_Thunk(void* ap)
{
    ((FUN_00905330*)((char*)this + 0x10c))->Remove(&ap);
}

// Stores the tagged pointer, updates its flag, and returns this.
// @fnv 0x006ecba0
// src: GUESS 0x006ecba0 (confidence: medium)
void* GO::SetTaggedPointer(bool abFlag, void* apValue)
{
    p = apValue;
    LockFreeMap_MarkedPointer_SetMark(abFlag);
    return this;
}

namespace fnv_0043b640 {

struct Flt
{
    operator unsigned int();
};
unsigned int __cdecl _BSStringLength(const char*);
void __cdecl _FNV_Warning(const char*, ...);
void __cdecl AssignNewObjectFromValue(void*, int, GO*);

struct FUN_0043b640
{
    char* pFilename;
    GO pListSequence;
    GO m_spAnimGroup;
    int BackgroundTask;
    int m_iActualRefCount;
    FUN_0043b640(const char* apFilename, void* apStream);
    void KFModel_InitSequence(const char*);
};

// @fnv 0x0043b640
FUN_0043b640::FUN_0043b640(const char* apFilename, void* apStream)
    : pListSequence(0), m_spAnimGroup(0), BackgroundTask(0), m_iActualRefCount(0)
{
    m_spAnimGroup = 0;
    unsigned int uiLength = _BSStringLength(apFilename);
    pFilename = new char[uiLength + 1];
    TaskQueueInterface::CopyStringToBuffer(pFilename, uiLength + 1, apFilename);
    AssignNewObjectFromValue(apStream, 0, &pListSequence);
    if (*(Flt*)&pListSequence)
    {
        KFModel_InitSequence(apFilename);
    }
    else
    {
        _FNV_Warning("ANIMATION: Could not create ControllerManager Sequence for \"%s\".\r\n", pFilename);
    }
}
}  // namespace fnv_0043b640

namespace fnv_0043cb50 {

struct FileFormCollection;

typedef char _sizecheck_TESTextureList[sizeof(FileEntryList) == 8 ? 1 : -1];
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct DistantTreeTextureInfo
{
    BGSTextureSet* m_pTextureSet;
    int m_iTextureSetIndex;
    char m_cTexturePath[128];
};
typedef char _sizecheck_TEX_SWAP[sizeof(DistantTreeTextureInfo) == 136 ? 1 : -1];
struct FUN_0043cb50_shell : public QueuedModel
{
    void QueueTextureFiles(FileEntryList*);
};

struct FUN_00978890_m
{
    unsigned char GetKey();
    BSFileEntry** _ref_00726070();
};
struct Loader_S
{
    void QueueTextureFile(BSFileEntry*, int, QueuedFile*);
};

struct SwapNode_0043cb50
{
    DistantTreeTextureInfo** _ref_006815c0();
    SwapNode_0043cb50* _ref_00726070();
};
// 0x00500940 returns this+0x18; this receiver is the texture-swap component returned by model slot 0x1C.
struct TextureSwapListAccess
{
    SwapNode_0043cb50* GetHeader();
};
struct ModelV_0043cb50
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual TextureSwapListAccess* GetTextureSwap();
};
struct FUN_0043ccc0_shell
{
    void QueuedModel_SetFinishedQueuing(bool);
};

// @fnv 0x0043cb50
void FUN_0043cb50_shell::QueueTextureFiles(FileEntryList* apTextureList)
{
    if (apTextureList)
    {
        unsigned int itextureCount = ((FUN_00978890_m*)apTextureList)->GetKey();
        if (itextureCount)
        {
            BSFileEntry** papFileEntries = ((FUN_00978890_m*)apTextureList)->_ref_00726070();
            for (unsigned int i = 0; i < itextureCount; i++)
            {
                if (papFileEntries[i])
                    ((Loader_S*)g_modelLoader)->QueueTextureFile(papFileEntries[i], IOTask_GetIOTaskPriority(), this);
            }
        }
    }
    if (*(ModelV_0043cb50**)((char*)this + 0x34))
    {
        TextureSwapListAccess* ptextureSwap = (*(ModelV_0043cb50**)((char*)this + 0x34))->GetTextureSwap();
        if (ptextureSwap)
        {
            SwapNode_0043cb50* pSwapNode = ptextureSwap->GetHeader();
            while (pSwapNode)
            {
                DistantTreeTextureInfo* pswap = *pSwapNode->_ref_006815c0();
                if (pswap && pswap->m_pTextureSet)
                    pswap->m_pTextureSet->LoadTextures(IOTask_GetIOTaskPriority(), this, false);
                pSwapNode = pSwapNode->_ref_00726070();
            }
        }
    }
    ((FUN_0043ccc0_shell*)this)->QueuedModel_SetFinishedQueuing(true);
    OnChildCompletion();
}
}  // namespace fnv_0043cb50

class NiBinaryStream;
class NiObject;
class NiObjectNET;
class NiPoint2;
class NiSearchPath;
class NiTexture;
namespace fnv_0043e2a0 {


struct NiObjectGroup;

struct NiThread;
struct SaveContentDescriptor;
struct _iobuf;
struct blob16
{
    char b[16];
};
struct blob308
{
    char b[308];
};
struct FUN_0043e2a0_shell : public QueuedKF
{
    void QueuedKF_Run();
};

struct Proc_S
{
    void* GetNext();
};
struct Flt
{
    operator unsigned int();
};
struct KFModelLookup
{
    KFModel* Lookup(const char*);
};
struct FUN_0043e480_shell
{
    void QueuedKF_SetAlreadyInKFMap(bool);
};
struct FUN_0043b640
{
    char data[0x14];
    FUN_0043b640(void*, BSStream*);
};
void _FNV_Warning(const char*, ...);

// Looks up a KFModel by name; if not found, opens the file and loads it into a new KFModel, warning on failure.
// @fnv 0x0043e2a0
// src: XBOX_PDB 0x0043e2a0
void FUN_0043e2a0_shell::QueuedKF_Run()
{
    AutoMemHelper tempMemContext(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                                 0x529);
    *(NiPointer<KFModel>*)((char*)this + 0x30) =
        ((KFModelLookup*)g_modelLoader)->Lookup((const char*)((Proc_S*)this)->GetNext());
    if (*(Flt*)((char*)this + 0x30))
    {
        ((FUN_0043e480_shell*)this)->QueuedKF_SetAlreadyInKFMap(true);
        return;
    }
    BSFile* pfile = reinterpret_cast<QueuedFileEntry*>(this)->GetFile(0, 1);
    BSStream kstream;
    if (pfile && ((NiStream*)&kstream)->BSStream_Load((const char*)((Proc_S*)this)->GetNext(), pfile))
        *(NiPointer<KFModel>*)((char*)this + 0x30) = (KFModel*)new FUN_0043b640(((Proc_S*)this)->GetNext(), &kstream);
    else
        _FNV_Warning("MODEL ERROR: Could not %s file '%s'.", pfile ? "load" : "find", ((Proc_S*)this)->GetNext());
}
}  // namespace fnv_0043e2a0

struct Inner5
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Holder14
{
    char _pad[0x14];
    Inner5* p;
    void ForwardToInner(int);
};
// Calls f5 on the Inner5 object stored in p, passing a through.
// @fnv 0x0043ea90
void Holder14::ForwardToInner(int aiValue)
{
    p->f5(aiValue);
}

struct VirtObj0043fb50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Standin0043fb50
{
    char _pad[0x18];
    VirtObj0043fb50* m_18;
    void DispatchToVirtual(int);
};
// Forwards the integer argument to the virtual method f5 of the object stored at m_18.
// @fnv 0x0043fb50
void Standin0043fb50::DispatchToVirtual(int aiValue)
{
    m_18->f5(aiValue);
}

namespace fnv_0043fed0 {

typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 4 ? 1 : -1];
struct ReferenceIntersectionData
{
    void Endian();
    TESObjectREFR* m_pHitReference;
    char Intersect[12];
    char Normal[12];
};
typedef char _sizecheck_REF_DECAL_DATA[sizeof(ReferenceIntersectionData) == 28 ? 1 : -1];
struct FUN_0043fed0_shell : public QueuedReference
{
    void QueuedReference_QueueMe();
};

struct RefV
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
    virtual int v116();
    bool TESObjectREFR_GetVisibleDistant();
    void* BSFile_GetDevice();
};
struct QRV
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
};

struct DecalList
{
    bool FUN_008256d0();
    ReferenceIntersectionData** FUN_006815c0();
    DecalList* FUN_00726070();
};
struct FUN_0041f050_shell
{
    DecalList* ExtraDataList_GetDecalRefs();
};

struct FUN_0043cc80_shell
{
    unsigned char IOTask_GetPriority();
};
struct Dummy_0069b080;
bool __fastcall IsFieldCZero(Dummy_0069b080*);
void __fastcall SetFieldCToFive(char*);

// @fnv 0x0043fed0
// src: XBOX_PDB 0x0043fed0
void FUN_0043fed0_shell::QueuedReference_QueueMe()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x72a);
    DecalList* pdecallist;
    if ((*(RefV**)((char*)this + 0x28)) && (*(RefV**)((char*)this + 0x28))->TESObjectREFR_GetVisibleDistant() &&
        !(*(RefV**)((char*)this + 0x28))->v116())
        ((QRV*)this)->v12();
    if ((*(RefV**)((char*)this + 0x28)))
    {
        pdecallist = ((FUN_0041f050_shell*)(*(RefV**)((char*)this + 0x28))->BSFile_GetDevice())->ExtraDataList_GetDecalRefs();
        while (pdecallist && !pdecallist->FUN_008256d0())
        {
            ReferenceIntersectionData* pdata = *pdecallist->FUN_006815c0();
            pdecallist = pdecallist->FUN_00726070();
            if (pdata->m_pHitReference && reinterpret_cast<TESObjectREFR*>(pdata->m_pHitReference)->GetObjectReference()->GetFormType() == 4)
            {
                BGSTextureSet* ptexset = (BGSTextureSet*)reinterpret_cast<TESObjectREFR*>(pdata->m_pHitReference)->GetObjectReference();
                ptexset->LoadTextures(((FUN_0043cc80_shell*)this)->IOTask_GetPriority(), this, false);
            }
        }
    }
    ((QRV*)this)->v11();
    if (IsFieldCZero((Dummy_0069b080*)this))
        SetFieldCToFive((char*)this);
    ((QRV*)this)->v10();
}
}  // namespace fnv_0043fed0

namespace fnv_00440050 {

typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 4 ? 1 : -1];

struct Flt
{
    operator unsigned int();
};

struct TESModelV
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual char* GetModelFileName();
};

struct FUN_00571630_shell
{
    TESModelV* FUN_00571630();
};
struct FUN_007af430_shell
{
    void* BGSSaveFormBuffer_GetForm();
};
struct FUN_00444dc0_shell
{
    void QueueModelForObject(void*, void*, int, void*, void*);
};
struct FUN_004472a0_shell
{
    bool ModelLoader_FindModel(char*, void*);
};
struct FUN_00477640_shell
{
    void FUN_00477640(void*, int, void*);
};
FUN_00477640_shell* BGSDestructibleObjectForm_GetDestructionForm(void*);

// Loads the model via g_modelLoader, resolves the model file name, and runs the destructor task if present.

}  // namespace fnv_00440050

struct IOTaskHack
{
    void IOTask_Requeue(int a1);
};
// Forwards this task and a1 to the IOManager at DAT_01202d98 via FUN_00c3df40.
// @fnv 0x00440660
// src: XBOX_PDB 0x00440660
void IOTaskHack::IOTask_Requeue(int a1)
{
    ((ModelLoaderIOOperations*)DAT_01202d98)->IOManager_RequeueTask(this, a1);
}

namespace fnv_00440780 {
struct FUN_00440780_shell : public QueuedReference
{
    void QueuedReference_CheckFinished();
};

extern TES* g_TES;
extern TESObjectREFR* g_thePlayer;
struct Flt
{
    operator unsigned int();
};
struct CtlV
{
    CtlV* GetNext() const;
};

struct RefA
{
    NiAVObject* GetReferenceType();
};
struct FUN_004408d0_S
{
    void ForwardToBCT(void*);
};
bool __fastcall BSTask_int64_GetTaskFinished(int*);
bool __fastcall BSTask_int64_GetTaskCanceled(int*);
struct VRef_00440780
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual bool v136();
    virtual bool v137();
};
// @fnv 0x00440780
// src: XBOX_PDB 0x00440780
void FUN_00440780_shell::QueuedReference_CheckFinished()
{
    if (fnv_00440780::BSTask_int64_GetTaskFinished((int*)this) && ((IOTask*)this)->QueuedFile_GetAllChildrenFinished() && !fnv_00440780::BSTask_int64_GetTaskCanceled((int*)this))
    {
        if (*(Flt*)((char*)this + 0x2c) && !*(Flt*)((char*)this + 0x30))
            ((GO*)((char*)this + 0x30))
                ->FUN_0044aed0(((CtlV*)(unsigned int)*(Flt*)((char*)this + 0x2c))->GetNext());
        bool bbackgroundClone = false;
        if (*(Flt*)((char*)this + 0x30) && *(TESObjectREFR**)((char*)this + 0x28) != g_thePlayer &&
            g_TES->IsCellBuffered(((::TESObjectREFR*)*(TESObjectREFR**)((char*)this + 0x28))->GetParentCell(), false) &&
            g_TES->IsRefUsable((TESObjectREFR*)*(TESObjectREFR**)((char*)this + 0x28)) &&
            !((RefA*)*(TESObjectREFR**)((char*)this + 0x28))->GetReferenceType())
            bbackgroundClone = true;
        if ((*(VRef_00440780**)((char*)this + 0x28))->v137() || (*(VRef_00440780**)((char*)this + 0x28))->v136())
            bbackgroundClone = false;
        if (bbackgroundClone)
            ((FUN_004408d0_S*)g_modelLoader)->ForwardToBCT(this);
        else
            ((IOTask*)this)->AddToPostProcessQueue();
    }
}
}  // namespace fnv_00440780

namespace fnv_00440a90 {
struct FUN_00440a90_shell : public QueuedReference
{
    bool QueuedReference_BackgroundClone();
};


extern TES* g_TES;

struct RefA
{
    NiAVObject* GetReferenceType();
};
struct SeqObj
{
    void NiRefObject_DecRefCount();
};
struct Flt
{
    operator unsigned int();
};

struct VRef
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
    virtual void* Get3DObject(bool);
};
struct QRView
{
    char pad[0x18];
    int iMemCtx;
    char pad2[0xc];
    TESObjectREFR* pRef;
    char pad3[8];
    GO spClone;
};
// @fnv 0x00440a90
// src: XBOX_PDB 0x00440a90
bool FUN_00440a90_shell::QueuedReference_BackgroundClone()
{
    bool bresult = false;
    AutoMemHelper tempMemContext(((QRView*)this)->iMemCtx, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x7ea);
    if (g_TES->IsCellBuffered(((::TESObjectREFR*)((QRView*)this)->pRef)->GetParentCell(), false))
    {
        if (g_TES->IsRefUsable((TESObjectREFR*)((QRView*)this)->pRef))
        {
            if (!((RefA*)((QRView*)this)->pRef)->GetReferenceType())
            {
                ((QRView*)this)->spClone = ((VRef*)((QRView*)this)->pRef)->Get3DObject(true);
                if (*(Flt*)&((QRView*)this)->spClone)
                    ((SeqObj*)(unsigned int)*(Flt*)&((QRView*)this)->spClone)->NiRefObject_DecRefCount();
            }
        }
        bresult = true;
    }
    return bresult;
}
}  // namespace fnv_00440a90

namespace fnv_00440ba0 {
struct FUN_00440ba0_shell : public QueuedReference
{
    void QueuedReference_Attach();
};

struct RefH
{
    bool IsDeleted() const;
    bool GetDisabled();
};

extern TES* g_TES;
struct Flt
{
    operator unsigned int();
};

struct FUN_004409e0_shell
{
    void ModelLoader_RemoveReferenceFromMap(TESObjectREFR* ref);
};
struct FUN_00572350_shell
{
    bool TESObjectREFR_Is3DCritical();
};
void __fastcall FinishScriptRunLockAndReset(char* p);
void __fastcall FinishScriptRun(char* p);
bool __fastcall BSTask_int64_GetTaskCanceled(int* p);

// Processes a queued reference: skips deleted/disabled refs, updates the model loader and cell reference lock, then releases the cell lock.
// @fnv 0x00440ba0
// src: XBOX_PDB 0x00440ba0
void FUN_00440ba0_shell::QueuedReference_Attach()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x804);
    if (fnv_00440ba0::BSTask_int64_GetTaskCanceled((int*)this))
        return;
    bool bdisabled = false;
    bdisabled = ((RefH*)*(TESObjectREFR**)((char*)this + 0x28))->GetDisabled() ||
                ((RefH*)*(TESObjectREFR**)((char*)this + 0x28))->IsDeleted();
    if (((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
        ((TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
            ->CellRefLockEnter();
    if (!bdisabled &&
        g_TES->IsCellBuffered(
            (TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult(), false))
    {
        if ((unsigned int)*(Flt*)((char*)this + 0x30))
            g_modelLoader->UpdateReferenceNode(
                *(TESObjectREFR**)((char*)this + 0x28),
                (NiNode*)((BSFaceGenModelExtraData*)(unsigned int)*(Flt*)((char*)this + 0x30))->GetModelFilePath());
        g_TES->AttachModel(
            (TESObjectREFR*)*(TESObjectREFR**)((char*)this + 0x28),
            (TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult(), reinterpret_cast<QueuedReference*>(this), false);
    }
    ((FUN_004409e0_shell*)g_modelLoader)->ModelLoader_RemoveReferenceFromMap(*(TESObjectREFR**)((char*)this + 0x28));
    if (((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
    {
        FinishScriptRunLockAndReset(
            (char*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult());
        if (((FUN_00572350_shell*)*(TESObjectREFR**)((char*)this + 0x28))->TESObjectREFR_Is3DCritical())
            FinishScriptRun((char*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult());
        ((TESObjectCELL*)((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))->GetCullResult())
            ->CellRefLockLeave();
    }
}
}  // namespace fnv_00440ba0

namespace fnv_004412e0 {

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct FUN_006a7ad0_shell
{
    unsigned int& BSSimpleArray_NiAVObject_1024_GetAt(int);
};
struct DismembermentPart
{
    int unk0;
    BSSimpleArray<unsigned int, 1024> parts;
};

ExtraDataList* __fastcall BSFile_GetDevice(TESObjectREFR*);

struct FUN_00444d40_shell
{
    void ModelLoader_QueueBoundObject(unsigned int, IO_TASK_PRIORITY, QueuedActor*, Actor*);
};

// Queues model-loader tasks for each dismembered limb part of the actor's extra data, then calls FUN_00440050.

}  // namespace fnv_004412e0

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class BGSVoiceType;
class BSShaderPPLightingProperty;
class MagicItemForm;
class PackageList;
class TESActorBase;
class TESAmmo;
class TESFaction;
class TESLevItem;
class TESObjectLIGH;
namespace fnv_00441560 {
struct PackedRecordData;

struct BipedAnimObject;

struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;




struct BipedAnim
{
    void InitRoot(NiNode*);
    NiNode* GetRoot();
    void RemoveClothingAndArmor();
    void CompleteModelLoadTask();
    static void SetNodeTranslation(NiAVObject*);
    void RemovePart(TESForm*);
    void RemovePart(int, bool, int);
    void RemovePart(BipedAnimObject*, bool, int);
    void RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone(NiAVObject*);
    NiNode* GetBoneNode(int);
    TESForm* GetParent(int);
    TESForm* FindPart(NiAVObject*);
    bool FindObject(TESForm*);
    BipedAnimObject* FindBipObject(TESForm*);
    BipedAnimObject* GetBipObject(int);
    void UpdateRaceSex(TESRace*, int);
    void SetBipedObject(TESForm*, TESModel*, int);
    void SetBipedVisibility(bool);
    void ProcessQueuedHelmet(int, void*, QueuedFile*);
    void QueueBipedObjectLoads(unsigned int, int, QueuedFile*);
    void LoadBipedObject(TESNPC*, int, int, QueuedFile*);
    BipedAnimObject* QBufferedObjects();
    void AddBipedWeapon(TESObjectWEAP*, unsigned char);
    void UpdateBipedWeapon(TESObjectWEAP*, unsigned char);
    void RemoveBipedWeapon();
    TESObjectWEAP* GetBipedWeapon();
    void AddWeaponOffset(float);
    static void RecursiveWeaponOffset(NiNode*, float);
    void SetBipedAmmo(TESAmmo*);
    void AttachBipedAmmo(TESAmmo*);
    void RemoveBipedAmmo();
    void AttachBipedShield(TESObjectARMO*);
    void RemoveBipedShield();
    void AttachBipedRing(TESObjectCLOT*, bool);
    void RemoveBipedRing(bool);
    void AttachBipedAmulet(TESObjectCLOT*);
    void RemoveBipedAmulet();
    void SetBipedTorch(TESObjectLIGH*);
    void AttachBipedTorch(TESObjectLIGH*);
    void RemoveBipedTorch();
    TESObjectLIGH* GetBipedTorch();
    NiNode* GetBipedTorchClone();
    BSFaceGenModel* GetFaceGenModelForSlot(int);
    void CanLoadHiddenBipedObjects(int, QueuedFile*, void*, int);
    void CanLoadHiddenBipedObjects(int, QueuedFile*, int);
    NiNode* GetFaceGenNode(BSFaceGenModel*, NiNode*, int);
    void SetFaceGenNode(BSFaceGenModel*, NiNode*, int);
    static void AttachObjectToNode(NiNode*, NiAVObject*, NiNode*, bool);
    static void AttachFaceGenNode(NiNode*, NiNode*, NiNode*, BipedAnim*, int, BSFaceGenModel*);
    static NiAVObject* LoadFormModel(TESForm*, TESModel*, int, TESObjectREFR*, NiAVObject*);
    static void ApplyReferenceExtraData(NiNode*, NiNode*, int, TESObjectREFR*);
    TESObjectREFR* GetRequester();
    bool IsSlotHidden(int);
    static BSShaderPPLightingProperty* FindLightingShaderProperty(NiAVObject*);
    static int GetBipedObjectFromShaderProperty(NiAVObject*, BSShaderPPLightingProperty*);
    static unsigned int GetSkinModelFlags(NiAVObject*);
    NiAVObject* PrepareBipedModel(NiNode*, int, bool, bool, BSFaceGenModel*);
    NiAVObject* AttachBipedModel(NiNode*, NiNode*, int, bool, bool, BSFaceGenModel*);
    void UpdateSkinInstance(NiAVObject*, bool);
    bool GetSlotHidden(int);
    bool IsModelPathMatch(TESModel*, char*);
    TESModel* Store1stPersonModel(int, char*);
    TESModel* GetModelForSlot(int, TESModel*);
    void* __vecDelDtor(unsigned int);
    NiNode* root;
    char bone[40];
    char object[320];
    char m_kPreviousObjects[320];
    float m_fFadeAlpha;
    TESObjectREFR* m_pActor;
};
typedef char _sizecheck_BipedAnim[sizeof(BipedAnim) == 692 ? 1 : -1];

typedef char _sizecheck_TESActorBaseData[sizeof(TESActorBaseData) == 52 ? 1 : -1];

typedef char _sizecheck_TESContainer[sizeof(TESContainer) == 12 ? 1 : -1];

typedef char _sizecheck_BGSTouchSpellForm[sizeof(BGSTouchSpellForm) == 12 ? 1 : -1];

typedef char _sizecheck_TESAIForm[sizeof(TESAIForm) == 32 ? 1 : -1];

typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];

typedef char _sizecheck_TESAnimation[sizeof(TESAnimation) == 12 ? 1 : -1];

typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];

typedef char _sizecheck_TESRaceForm[sizeof(TESRaceForm) == 8 ? 1 : -1];

typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 4 ? 1 : -1];
struct FUN_00441560_shell : public QueuedCharacter
{
    void LoadBipedModel();
};

struct N_008c48d0
{
    void* GetNext();
};
struct FUN_006055f0_shell
{
    BipedAnim* GetOrCreateBipedAnim(TESObjectREFR*);
};
struct FUN_004abd30_shell
{
    void QueueBipedParts(int, void*, void*);
};
struct FUN_00444fe0_shell
{
    void ModelLoader_QueueHead(TESNPC*, void*, int, QueuedFile*);
};
struct FUN_00445a10_shell
{
    void QueueModelAnimations(TESModel*, int, void*, TESObjectREFR*, int, int);
};
struct RefVtbl
{

    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual BipedAnim* GetBipedAnim();
};

// Loads the queued character's biped anim and NPC model via the model loader, then finishes the task.
// @fnv 0x00441560
void FUN_00441560_shell::LoadBipedModel()
{
    BipedAnim* pbipedAnim;
    TESNPC* pnpc;
    TESModel* pmodel;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8ca);
    pnpc = (TESNPC*)(*(N_008c48d0**)((char*)this + 0x28))->GetNext();
    pbipedAnim = (*(RefVtbl**)((char*)this + 0x28))->GetBipedAnim();
    if (!pbipedAnim)
    {
        pbipedAnim = ((FUN_006055f0_shell*)pnpc)->GetOrCreateBipedAnim(*(TESObjectREFR**)((char*)this + 0x28));
    }
    if (pbipedAnim)
    {
        pnpc->RebuildHeadModel(*(TESObjectREFR**)((char*)this + 0x28), static_cast<void*>(pbipedAnim), 0);
        ((FUN_004abd30_shell*)pbipedAnim)->QueueBipedParts(((IOTask*)this)->IOTask_GetIOTaskPriority(), (char*)this + 0x44, this);
        ((FUN_00444fe0_shell*)g_modelLoader)
            ->ModelLoader_QueueHead(pnpc, (char*)this + 0x40, ((IOTask*)this)->IOTask_GetIOTaskPriority(), (QueuedFile*)this);
    }
    pmodel = reinterpret_cast<TESModel*>(static_cast<TESModel*>(pnpc));
    ((FUN_00445a10_shell*)g_modelLoader)
        ->QueueModelAnimations(pmodel, ((IOTask*)this)->IOTask_GetIOTaskPriority(), this, *(TESObjectREFR**)((char*)this + 0x28), 0,
                               0);
    reinterpret_cast<QueuedActor*>(this)->QueueDismemberedLimbLoads();
}
}  // namespace fnv_00441560

class NiBinaryStream;
namespace fnv_00441e40 {

struct LoadedFile;

struct SaveContentDescriptor;
struct _iobuf;
struct blob16
{
    char b[16];
};
struct blob308
{
    char b[308];
};
typedef char _sizecheck_QueuedFileEntry[sizeof(QueuedFileEntry) == 48 ? 1 : -1];

typedef char _sizecheck_QueuedFileLoad[sizeof(QueuedFileLoad) == 56 ? 1 : -1];

typedef char _sizecheck_QueuedFaceGenFile[sizeof(QueuedFaceGenFile) == 64 ? 1 : -1];

struct Proc_S
{
    void* GetNext();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_004483a0_t
{
    LoadedFile* GetHolderValue(void*);
};

struct LoadedFile
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    char data[0x10];
    LoadedFile(void*, BSFile*);
};
int ModelLoader_GetArchiveTypeIndexForIOFileIndex(int);
void _FNV_Warning(const char*, ...);

// Loads the next queued file via the model loader; if none, opens the file by index and creates a LoadedFile, otherwise warns.

}  // namespace fnv_00441e40

namespace fnv_00442350 {
int __cdecl InitScriptRunLock(void*);
int __cdecl FinishScriptRunLock(void*);
// Exe 0x00442350: unit-local Interface view; declarations and layout are preserved.
struct ModelloaderInterfaceView
{
    static void __cdecl PrintDebugMessage();
};
void __fastcall BSTaskThread_WaitTask(char*);
struct FUN_00442510_Cl;
void __fastcall BSTaskThread_WaitPause(FUN_00442510_Cl*);
void __fastcall SignalAtOffset18(char*);
bool __fastcall BSTask_int64_GetTaskCanceled(int*);
int __fastcall _ref_0084e3a0(void*);
struct FUN_00449190_cls
{
    bool SetState(int, int);
};
struct QHeadPtr
{
    void* p;
    QHeadPtr(int);
    ~QHeadPtr();
};
struct Flt
{
    operator unsigned int();
};
struct VTask
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
    virtual bool NeedsPostProcess();
};

}  // namespace fnv_00442350

// @fnv 0x00442350
void BackgroundCloneThread::RunBackgroundClone()
{
    while (m_bThirdThreadFlag != true)
    {
        fnv_00442350::BSTaskThread_WaitTask((char*)this);
        fnv_00442350::InitScriptRunLock((char*)this + 0x34);
        fnv_00442350::QHeadPtr spqueuedReference(0);
        m_pCloneQueue->LockFreeQueue_NiPointer_IOTask_Pop(&spqueuedReference);
        if (*(fnv_00442350::Flt*)&spqueuedReference)
        {
            while (*(fnv_00442350::Flt*)&spqueuedReference)
            {
                fnv_00442350::BSTaskThread_WaitPause((fnv_00442350::FUN_00442510_Cl*)this);
                fnv_00442350::ModelloaderInterfaceView::PrintDebugMessage();
                QueuedReference* pqueuedRef = (QueuedReference*)(unsigned int)*(fnv_00442350::Flt*)&spqueuedReference;
                int estate = fnv_00442350::_ref_0084e3a0(pqueuedRef);
                if (!fnv_00442350::BSTask_int64_GetTaskCanceled((int*)pqueuedRef) && ((fnv_00442350::FUN_00449190_cls*)pqueuedRef)->SetState(estate, 3))
                {
                    if (((fnv_00442350::VTask*)pqueuedRef)->NeedsPostProcess())
                        ((IOTask*)pqueuedRef)->AddToPostProcessQueue();
                    ((fnv_00442350::FUN_00449190_cls*)pqueuedRef)->SetState(3, 5);
                }
                m_pCloneQueue->LockFreeQueue_NiPointer_IOTask_Pop(&spqueuedReference);
                fnv_00442350::ModelloaderInterfaceView::PrintDebugMessage();
                fnv_00442350::SignalAtOffset18((char*)this);
            }
        }
        else
        {
            fnv_00442350::BSTaskThread_WaitPause((fnv_00442350::FUN_00442510_Cl*)this);
            fnv_00442350::SignalAtOffset18((char*)this);
        }
        fnv_00442350::FinishScriptRunLock((char*)this + 0x34);
    }
}

namespace fnv_00443540 {
typedef char _sizecheck_BSFileEntry[sizeof(BSFileEntry) == 16 ? 1 : -1];
struct FUN_00443540_shell : public ModelLoader
{
    bool ModelLoader_ReuseQueuedTexture(BSFileEntry*, int, QueuedFile*);
};

struct QHeadPtr
{
    ~QHeadPtr();
    void* m_pObject;
};
struct Flt : QHeadPtr
{
    operator unsigned int();
};
struct QueueObj : Flt
{
    QueueObj(int);
};
struct S_00448f80
{
    int ModelLoader_GetQueuedTextureFromMap(BSFileEntry*);
};
struct S_0084e3a0
{
    int _ref_0084e3a0();
};
struct FUN_00449190_cls
{
    bool SetState(int, int);
};
struct FUN_0043c3d0_shell
{
    bool QueuedTexture_GetLoadDegraded();
};
struct MLa
{
    bool IsLoadTexturesDegraded();
};
struct Q_0043c050
{
    bool ForwardByteToMember(bool);
};
struct S_00c3c7e0
{
    void QueuedFile_AddAdditionalParent(QueuedFile*);
};
struct V_00443540
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetPriority(int);
};

// @fnv 0x00443540
// src: COMMUNITY 0x00443540
bool FUN_00443540_shell::ModelLoader_ReuseQueuedTexture(BSFileEntry* apTextureFileEntry, int aePriority, QueuedFile* apParent)
{
    QueueObj spexistingQueuedTexture(((S_00448f80*)this)->ModelLoader_GetQueuedTextureFromMap(apTextureFileEntry));
    if (spexistingQueuedTexture)
    {
        int estate = ((S_0084e3a0*)(unsigned int)spexistingQueuedTexture)->_ref_0084e3a0();
        if (estate < 3 && ((FUN_00449190_cls*)(unsigned int)spexistingQueuedTexture)->SetState(estate, 2))
        {
            if (((FUN_0043c3d0_shell*)(unsigned int)spexistingQueuedTexture)->QueuedTexture_GetLoadDegraded() &&
                !((MLa*)this)->IsLoadTexturesDegraded())
                ((Q_0043c050*)(unsigned int)spexistingQueuedTexture)->ForwardByteToMember(false);
            if (apParent)
                ((S_00c3c7e0*)(unsigned int)spexistingQueuedTexture)->QueuedFile_AddAdditionalParent(apParent);
            if (((FUN_00449190_cls*)(unsigned int)spexistingQueuedTexture)->SetState(2, estate))
            {
                if (((IOTask*)(unsigned int)spexistingQueuedTexture)->IOTask_GetIOTaskPriority() > aePriority)
                    ((V_00443540*)(unsigned int)spexistingQueuedTexture)->SetPriority(aePriority);
                else
                    ((ModelLoaderIOOperations*)DAT_01202d98)->BSTaskManager_int64_ForceSignal();
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_00443540

class NiControllerSequence;
class TESAnimGroup;
namespace fnv_004446a0 {
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
typedef char _sizecheck_KFModel[sizeof(KFModel) == 28 ? 1 : -1];
struct FUN_004446a0_shell : public ModelLoader
{
    bool QueueKFModelLoad(char*, int, QueuedFile*);
};

struct Flt
{
    operator unsigned int();
};
struct QHeadLocal
{
    void SetParent(QueuedFile*);
};
namespace FUN_00528cb0 {
struct FUN_0044cbf0
{
    void* p;
    FUN_0044cbf0(void*);
    ~FUN_0044cbf0();
};
}
struct FUN_0043e210
{
    unsigned int pad[14];
    FUN_0043e210(KFModel*, int);
};
struct FUN_0043e0f0
{
    unsigned int pad[14];
    FUN_0043e0f0(char*, int);
};
struct KFMapStand
{
    virtual void v0();
    virtual void v1();
    virtual bool Get(char*, KFModel**);
};
// @fnv 0x004446a0
bool FUN_004446a0_shell::QueueKFModelLoad(char* apKFFileName, int aePriority, QueuedFile* apParent)
{
    KFModel* pkfModel = 0;
    if (((KFMapStand**)this)[1]->Get(apKFFileName, &pkfModel))
    {
        if (apParent)
        {
            FUN_00528cb0::FUN_0044cbf0 spqueuedKF(new FUN_0043e210(pkfModel, aePriority));
            ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedKF)->SetParent(apParent);
            ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedKF)->OnChildCompletion();
            return true;
        }
        return false;
    }
    FUN_00528cb0::FUN_0044cbf0 spqueuedKF(new FUN_0043e0f0(apKFFileName, aePriority));
    ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedKF)->SetParent(apParent);
    ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedKF)->DispatchToManager();
    return true;
}
}  // namespace fnv_004446a0

namespace fnv_00444dc0 {

struct QHeadPtr
{
    void* p;
    ~QHeadPtr();
};
struct QueueObj : QHeadPtr
{
    QueueObj(int);
};
struct QHeadPtrDest
{
    QHeadPtrDest& Assign(const QHeadPtr&);
};
struct QueueModelHolder
{
    void ModelLoader_QueueModel_00443dc0(int, QueueObj*, int, int, int, bool, bool, bool, float);
};
struct FUN_00444dc0_ref
{
    bool TESObjectREFR_GetVisibleDistant();
    bool TESObjectREFR_IsMarker();
    bool TESObjectREFR_GetIsImposter();
};
struct FUN_00444dc0_t
{
    int ModelLoader_GetModelForBoundObject(TESObject*, FUN_00444dc0_ref*);
    void QueueModelForObject(TESObject* apObject, QHeadPtrDest* apDest, int a3, int a4, FUN_00444dc0_ref* apRef);
};
// Computes a handle and LOD for apObject, queues a model load with fade distance, and assigns the queued handle to apDest.
// @fnv 0x00444dc0
void FUN_00444dc0_t::QueueModelForObject(TESObject* apObject, QHeadPtrDest* apDest, int a3, int a4,
                                         FUN_00444dc0_ref* apRef)
{
    int iHandle = ModelLoader_GetModelForBoundObject(apObject, apRef);
    int iLOD = TES::GetModelResourceType(reinterpret_cast<TESObject*>(apObject));
    if (apRef && (apRef->TESObjectREFR_GetVisibleDistant() || apRef->TESObjectREFR_IsMarker()))
        iLOD = 6;
    QueueObj kQueued(0);
    float fFadeDist = 0.0f;
    if (apRef && apRef->TESObjectREFR_GetIsImposter())
        fFadeDist = 3.402823466e+38F;
    ((QueueModelHolder*)g_modelLoader)->ModelLoader_QueueModel_00443dc0(iHandle, &kQueued, a3, a4, iLOD, true, false, false, fFadeDist);
    apDest->Assign(kQueued);
}
}  // namespace fnv_00444dc0

namespace fnv_00447080 {
struct FUN_00447080_shell : public ModelLoader
{
    NiNode* ModelLoader_LoadFile(char*, int, bool, bool, bool, bool);
};

struct Flt
{
    operator unsigned int();
};
namespace FUN_0043c6e0 {
struct FUN_0043c830
{
    unsigned int pad[0xc];
    Flt model;
    unsigned int pad2[5];
    FUN_0043c830(char*, int, int, bool, int);
    ~FUN_0043c830();
};
}
struct FUN_00443ff0Class
{
    void QueuedModel_SetFaceGenModel(unsigned char);
};
struct FUN_00447190_dummy
{
    void QueuedModel_SetForceLoad(unsigned char);
};
struct FUN_0043ccf0_s
{
    void QueuedModel_Run();
};
struct FUN_0043d180_s
{
    void QueuedModel_Finish();
};
struct FUN_00443190_s
{
    int GetCombinedValue();
};
struct ObjA
{
    void Model_IncManualRefCount();
};
struct FUN_0043b230_s
{
    NiNode* NiObjectNET_GetControllers();
};
void Warning_005b5e40(const char*, ...);
struct ModelMapStand
{
    virtual void v0();
    virtual void v1();
    virtual bool Get(char*, Model**);
};
// @fnv 0x00447080
// src: XBOX_PDB 0x00447080
NiNode* FUN_00447080_shell::ModelLoader_LoadFile(char* apFilename, int aeLODFadeMult, bool abPrepareObject,
                                         bool abSuppressWarning, bool abFaceGenModel, bool abDontIncrementRefCount)
{
    Model* pmodel = 0;
    if (!(*(ModelMapStand**)this)->Get(apFilename, &pmodel))
    {
        FUN_0043c6e0::FUN_0043c830 queuedModel(apFilename, 0, aeLODFadeMult, abPrepareObject, 0);
        reinterpret_cast<FUN_00443ff0Class*>(&queuedModel)->QueuedModel_SetFaceGenModel(abFaceGenModel);
        reinterpret_cast<FUN_00447190_dummy*>(&queuedModel)->QueuedModel_SetForceLoad(1);
        reinterpret_cast<FUN_0043ccf0_s*>(&queuedModel)->QueuedModel_Run();
        reinterpret_cast<FUN_0043d180_s*>(&queuedModel)->QueuedModel_Finish();
        pmodel = (Model*)(unsigned int)queuedModel.model;
    }
    else if (!reinterpret_cast<FUN_00443190_s*>(pmodel)->GetCombinedValue())
    {
        Warning_005b5e40("MODELS: LoadFile retrieved model %s with a zero ref count", apFilename);
    }
    if (pmodel)
    {
        if (!abDontIncrementRefCount)
            reinterpret_cast<ObjA*>(pmodel)->Model_IncManualRefCount();
        return reinterpret_cast<FUN_0043b230_s*>(pmodel)->NiObjectNET_GetControllers();
    }
    return 0;
}
}  // namespace fnv_00447080

namespace fnv_00447a40 {
struct FUN_00447a40_shell : public ModelLoader
{
    void ModelLoader_QueueFaceGenFile(char*, int, QueuedFile*, int);
};

struct LoadedFile;
struct FUN_0044b160 : public NiPointer<LoadedFile>
{
    FUN_0044b160(LoadedFile* pObject) : NiPointer<LoadedFile>(pObject)
    {}
    ~FUN_0044b160();
};
struct QueueObj
{
    QueueObj(int);
    void* m_pObject;
};
struct QHeadPtr : public QueueObj
{
    QHeadPtr(int pObject) : QueueObj(pObject)
    {}
    ~QHeadPtr();
};
struct Flt
{
    operator unsigned int();
};
struct QHeadLocal
{
    void SetParent(QueuedFile*);
};
struct FUN_004483a0_S
{
    LoadedFile* GetHolderValue(const char*);
};
struct FUN_004420b0
{
    FUN_004420b0(unsigned int, int);
    char pad[0x40];
};
struct FUN_00441f80
{
    FUN_00441f80(const char*, int, int);
    char pad[0x40];
};

// Loads the file via GetHolderValue; if loaded, queues a FUN_004420b0 task with the parent, otherwise queues a FUN_00441f80 task and sets its parent.
// @fnv 0x00447a40
// src: COMMUNITY 0x00447a40
void FUN_00447a40_shell::ModelLoader_QueueFaceGenFile(char* apFileName, int aePriority, QueuedFile* apParent, int aeFileIndex)
{
    FUN_0044b160 m_pLoadedFile(((FUN_004483a0_S*)this)->GetHolderValue(apFileName));
    if (*(Flt*)&m_pLoadedFile)
    {
        if (apParent)
        {
            QHeadPtr spqueuedFaceGenFile((int)new FUN_004420b0(*(Flt*)&m_pLoadedFile, aePriority));
            ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->SetParent(apParent);
            ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->OnChildCompletion();
        }
        return;
    }
    QHeadPtr spqueuedFaceGenFile((int)new FUN_00441f80(apFileName, aePriority, aeFileIndex));
    ((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->SetParent(apParent);
    ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->DispatchToManager();
}
}  // namespace fnv_00447a40

struct Virt00448370
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Stand00448370
{
    char _pad[0x24];
    Virt00448370* field24;
    void __thiscall ModelLoader_RemoveLoadedFileFromMap(int);
};
// Calls the virtual method f5 on field24, passing a through.
// @fnv 0x00448370
// src: XBOX_PDB 0x00448370
void __thiscall Stand00448370::ModelLoader_RemoveLoadedFileFromMap(int aiValue)
{
    field24->f5(aiValue);
}

namespace fnv_00448cc0 {
struct GlobalObject_00448e00
{
    GlobalObject_00448e00();
    __int64 iStart;
    __int64 iEnd;
};
struct FUN_00448e30_this
{
    void init(float);
};
bool __fastcall IsNotStateSix(int);
bool __fastcall BSPrecisionTimer_Check(__int64*);
extern float DAT_01017130;
struct FUN_004499c0
{
    ~FUN_004499c0();
    void* p0;
    void* p1;
    void* p2;
    void* p3;
};
struct FUN_0044cc10 : public FUN_004499c0
{
    FUN_0044cc10();
};
struct FUN_006ebde0_shell
{
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
};
struct QHeadPtr
{
    ~QHeadPtr();
    void* p;
};
struct QueueObj : public QHeadPtr
{
    QueueObj(int);
};
struct Flt
{
    operator unsigned int();
};
struct QueuedTask_00448cc0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Run();
};
struct Queue_00448cc0
{
    bool ProcessIteration(FUN_0044cc10*, int*, QueueObj*, bool);
};
struct ModelLoaderStand_00448cc0
{
    char pad[0xc];
    Queue_00448cc0* m_pPrimaryTaskProcessor;
    bool ProcessQueuedTasks();
};

// Initializes a timer, then repeatedly dequeues tasks and runs them until the queue is empty or the timer expires; returns whether the queue is empty.
// @fnv 0x00448cc0
bool ModelLoaderStand_00448cc0::ProcessQueuedTasks()
{
    GlobalObject_00448e00 kTimer;
    if (IsNotStateSix((int)DAT_01202d98))
        ((FUN_00448e30_this*)&kTimer)->init(DAT_01017130);
    else
        ((FUN_00448e30_this*)&kTimer)->init(5.0f);
    {
        FUN_0044cc10 kTaskList;
        while (!((FUN_006ebde0_shell*)&kTaskList)->LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished() && !BSPrecisionTimer_Check((__int64*)&kTimer))
        {
            int iCount = 0;
            QueueObj kTask(0);
            if (m_pPrimaryTaskProcessor->ProcessIteration(&kTaskList, &iCount, &kTask, true))
                ((QueuedTask_00448cc0*)(unsigned int)*(Flt*)&kTask)->Run();
        }
        return ((FUN_006ebde0_shell*)&kTaskList)->LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
    }
}
}  // namespace fnv_00448cc0

namespace fnv_0044afe0 {
struct KFModel
{
    void KFModel_IncRefCount(void);
};
struct S0044afe0
{
    KFModel* p;
    S0044afe0* SetRetainedKFModel(KFModel* a);
};
// Stores the given KFModel pointer in p and, if it is non-null, calls its FUN_0044b010 method; returns this.
// @fnv 0x0044afe0
// src: GUESS 0x0044afe0 (confidence: medium)
S0044afe0* S0044afe0::SetRetainedKFModel(KFModel* apModel)
{
    p = apModel;
    if (p != 0)
        p->KFModel_IncRefCount();
    return this;
}
}  // namespace fnv_0044afe0

namespace fnv_00528ce0 {
bool __cdecl CompareAndSwapEx(void*, int, int);
int __fastcall ClearLowBit(int*);
struct FUN_0044df00Class
{
    char* ClearLowBit_Thunk();
};
struct Flt
{
    operator unsigned int();
};
struct V40
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0a();
    virtual void f0b();
    virtual void f0c();
    virtual void f0d();
    virtual void f0e();
    virtual void f0f();
    virtual void f10();
};
struct FUN_00528ce0_shell
{
    V40* pObject;
    bool LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_RemoveAt_00528ce0(void* apA, void* apB);
    bool ProcessNode(void* apA, void* apB);
    void FUN_005292a0(int);
    void LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
};

// @fnv 0x00528ce0
// src: COMMUNITY 0x00528ce0
bool FUN_00528ce0_shell::LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_RemoveAt_00528ce0(void* apA, void* apB)
{
    bool bResult = false;
    while (1)
    {
        unsigned int kCur;
        if (!ProcessNode(apA, apB))
        {
            bResult = false;
            break;
        }
        {
            unsigned int kOld;
            unsigned int kNew;
            reinterpret_cast<GO*>(&kOld)->SetTaggedPointer(false, (void*)ClearLowBit((int*)((char*)this + 0x18)));
            reinterpret_cast<GO*>(&kNew)->SetTaggedPointer(true, (void*)ClearLowBit((int*)((char*)this + 0x18)));
            if (!CompareAndSwapEx(((FUN_0044df00Class*)((char*)this + 0x14))->ClearLowBit_Thunk() + 8,
                              (unsigned int)*(Flt*)&kNew, (unsigned int)*(Flt*)&kOld))
                continue;
            reinterpret_cast<GO*>(&kCur)->SetTaggedPointer(false, (void*)ClearLowBit((int*)((char*)this + 0x14)));
            if (CompareAndSwapEx(*(void**)((char*)this + 0x10), (unsigned int)*(Flt*)&kOld, (unsigned int)*(Flt*)&kCur))
                FUN_005292a0(ClearLowBit((int*)((char*)this + 0x14)));
            else
                ProcessNode(apA, apB);
            pObject->f10();
            bResult = true;
            break;
        }
    }
    LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
    return bResult;
}
}  // namespace fnv_00528ce0

namespace fnv_00443270 {
struct FUN_006ebde0_shell
{
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
};
struct FUN_00443190_shell
{
    int GetCombinedValue();
};
int __fastcall KFModel_GetRefCount(int*);
int __fastcall _ref_0084e3a0(void*);
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl _FNV_Warning(const char*, ...);
unsigned int __cdecl _strlen(const char*);

struct Flt
{
    operator unsigned int();
};
struct FUN_004431d0
{
    char m_buf[0x10c];
    ~FUN_004431d0();
};
struct FUN_004498e0 : FUN_004431d0
{
    FUN_004498e0();
};
struct FUN_00443220
{
    char m_buf[0x110];
    ~FUN_00443220();
};
struct FUN_00449960 : FUN_00443220
{
    FUN_00449960();
};
struct Map_443270
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual int GetCount();
    bool TryGetNextEntry(void* pIter, const char** ppKey, void** ppVal, int a);
};
struct File_443270
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
    virtual void v34();
    virtual void WriteString(BSStringT<char>*, int);
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void Write(const char*, unsigned int);
};
struct FUN_00443270_shell
{
    Map_443270* m_pModels;
    Map_443270* m_pAnims;
    void ModelLoader_OutputModelMapContents(File_443270* pFile, bool bAll);
};
// Iterates the model and animation maps, formats each entry's counts into a line, logs it via _FNV_Warning and optionally writes it to pFile.
// @fnv 0x00443270
// src: XBOX_PDB 0x00443270
void FUN_00443270_shell::ModelLoader_OutputModelMapContents(File_443270* pFile, bool bAll)
{
    if (m_pModels->GetCount())
    {
        FUN_004498e0 kIter;
        while (!((FUN_006ebde0_shell*)&kIter)->LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
        {
            const char* pKey = 0;
            void* pVal = 0;
            if (m_pModels->TryGetNextEntry(&kIter, &pKey, &pVal, 1))
            {
                if (((FUN_00443190_shell*)pVal)->GetCombinedValue() > 0 || bAll)
                {
                    char acBuf[1024];
                    _sprintf_s(acBuf, 1024, "MODELS:\t%3d\t%3d\t%3d\t%s\r\n",
                               ((FUN_00443190_shell*)pVal)->GetCombinedValue(), ((GridArray*)pVal)->GetCenterX(),
                               ((GridArray*)pVal)->m_fCenterY(), pKey);
                    _FNV_Warning(acBuf);
                    if (pFile)
                        pFile->Write(acBuf, _strlen(acBuf) + 1);
                }
            }
        }
    }
    if (m_pAnims->GetCount())
    {
        FUN_00449960 kIter2;
        while (!((FUN_006ebde0_shell*)&kIter2)->LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
        {
            const char* pKey2 = 0;
            void* pVal2 = 0;
            if (m_pAnims->TryGetNextEntry(&kIter2, &pKey2, &pVal2, 1))
            {
                if (KFModel_GetRefCount((int*)pVal2) > 0)
                {
                    BSStringT<char> kStr;
                    kStr.PrintfString("ANIMATION:\t%3d\t%3d\t%3d\t%s\r\n", KFModel_GetRefCount((int*)pVal2), _ref_0084e3a0(pVal2),
                                 ((BSAudio*)pVal2)->GetAudioBackendData(), pKey2);
                    _FNV_Warning((const char*)(unsigned int)*(Flt*)&kStr);
                    if (pFile)
                        pFile->WriteString(&kStr, 1);
                }
            }
        }
    }
}
}  // namespace fnv_00443270

struct FileFinder
{
    static NiFile* GetFile(char const*, int, unsigned int, unsigned int);
};
NiFile* __cdecl ArchiveManager_GetFileByFileEntry(int, int, int, int);
// @fnv 0x00c3cff0
BSFile* QueuedFileEntry::GetFile(int aeArchiveTypeIndex, int aeArchiveType)
{
    BSFile* pFile = 0;
    if (m_pFileEntry)
    {
        pFile = static_cast<BSFile*>(ArchiveManager_GetFileByFileEntry(aeArchiveTypeIndex, reinterpret_cast<int>(m_pFileEntry), -1, 0));
    }
    if (pFileName && !pFile)
    {
        char plookupFileName[260];
        GetLookupFileName(aeArchiveTypeIndex, plookupFileName);
        pFile = static_cast<BSFile*>(FileFinder::GetFile(plookupFileName, 0, -1, aeArchiveType));
    }
    return pFile;
}

// QueuedTexture.h lacks the 0x0043c650 Cancel override; this adapter declares only that operation, with no layout copy.
struct TextureCancellationOperations : QueuedTexture
{
    void CancelTexture(int aePreviousState, void* apTaskOwner);
};

// @fnv 0x0043c650
void TextureCancellationOperations::CancelTexture(int aePreviousState, void* apTaskOwner)
{
    QueuedFile_Cancel(aePreviousState, reinterpret_cast<RefObj*>(apTaskOwner));
    if (GetFileEntry())
    {
        if (reinterpret_cast<FUN_0043c630_shell*>(this)->QueuedTexture_GetInQueuedTextureMap())
        {
            reinterpret_cast<FUN_0043c100_shell*>(this)->QueuedTexture_SetInQueuedTextureMap(false);
            g_modelLoader->ForwardToVTableSlot(GetFileEntry());
        }
    }
}

struct FUN_00449130_s
{
    bool __fastcall BSTask_int64_GetTaskCanceled();
};
struct Flt_s
{
    operator unsigned int();
};
struct FUN_0043ea30_s
{
    void QueuedReplacementKFList_NotifyChildFinishedPostProcessing();
};
struct FUN_00490fa0_s
{
    void Animation_QueueReplacementAnimation(unsigned int);
};
struct FUN_0043e9b0_s
{
    void QueuedReplacementKF_PostProcess();
};
// @fnv 0x0043e9b0
// src: XBOX_PDB 0x0043e9b0
void FUN_0043e9b0_s::QueuedReplacementKF_PostProcess()
{
    if (!((FUN_00449130_s*)this)->BSTask_int64_GetTaskCanceled())
    {
        ((FUN_00490fa0_s*)*(void**)((char*)this + 0x38))->Animation_QueueReplacementAnimation((unsigned int)*(Flt_s*)((char*)this + 0x30));
        if (*(void**)((char*)this + 0x3c))
            ((FUN_0043ea30_s*)*(void**)((char*)this + 0x3c))->QueuedReplacementKFList_NotifyChildFinishedPostProcessing();
    }
}

namespace fnv_0043ea30 {
struct Holder14
{
    void ForwardToInner(int);
};
struct FUN_0043ea30_shell : IOTask
{
    void QueuedReplacementKFList_NotifyChildFinishedPostProcessing();
};
// @fnv 0x0043ea30
// src: XBOX_PDB 0x0043ea30
void FUN_0043ea30_shell::QueuedReplacementKFList_NotifyChildFinishedPostProcessing()
{
    ((int*)this)[12]++;
    if (BSTask_int64_GetTaskFinished() && QueuedFile_GetAllChildrenFinished() && ((int*)this)[11] == ((int*)this)[12])
        ((Holder14*)g_modelLoader)->ForwardToInner(((int*)this)[10]);
}
}  // namespace fnv_0043ea30

namespace fnv_0043f240 {

struct BipedAnim
{
    bool IsSlotHidden(int);
    BSFaceGenModel* GetFaceGenModelForSlot(int);
};

bool __fastcall BSTask_int64_GetTaskCanceled(int*);

}  // namespace fnv_0043f240

namespace fnv_00440710 {
extern int _data_011c16bc;
struct QueueObj
{
    int x;
    QueueObj(int);
    ~QueueObj();
};
struct E_00449210
{
    void LockFreeQueue_NiPointer_IOTask_Push(QueueObj*);
};
struct FUN_00440710_t
{
    int p0, p1, p2, p3, p4, p5, p6;
    E_00449210* q;
    void DispatchToQueue(int a);
};
// Constructs a QueueObj from a and passes its address to q->FUN_00449240.
// @fnv 0x00440710
void FUN_00440710_t::DispatchToQueue(int aiValue)
{
    QueueObj o(aiValue);
    q->LockFreeQueue_NiPointer_IOTask_Push(&o);
}
}  // namespace fnv_00440710

struct Loader_S
{
    unsigned char ReleaseAllObjects();
    unsigned char ProcessQueuedTasks();
};
// Calls ReleaseAllObjects and ProcessQueuedTasks on g_modelLoader and returns 1 only if both return nonzero.
// @fnv 0x00446e40
// src: COMMUNITY 0x00446e40
char ModelLoader_UpdateSecondaryQueueCallback()
{
    unsigned char a = 1;
    unsigned char b = 1;
    a = ((Loader_S*)g_modelLoader)->ReleaseAllObjects();
    b = ((Loader_S*)g_modelLoader)->ProcessQueuedTasks();
    return (a && b) ? 1 : 0;
}

struct S_0044dbc0
{
    virtual ~S_0044dbc0();
};
struct FUN_00449c50 : S_0044dbc0
{
    void ClearBucketsAndRecreateManager(int);
    virtual ~FUN_00449c50();
};
// Destructor that calls FUN_0044c480 with argument 1.
// @fnv 0x00449c50
FUN_00449c50::~FUN_00449c50()
{
    ClearBucketsAndRecreateManager(1);
}

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};

struct FUN_00449cb0_Helper
{
    unsigned int ComputeNameHash(char* name);
};

// Hashes the null-terminated name with a 33x multiplier and returns the hash modulo the object's flags value.
// @fnv 0x00449cb0
unsigned int FUN_00449cb0_Helper::ComputeNameHash(char* name)
{
    unsigned int hash = 0;
    while (*name)
    {
        hash = hash * 32 + hash + (signed char)*name;
        name++;
    }
    return hash % ((TESObjectREFR_GetFlags_Helper*)((TESObjectREFR*)this))->CallGetFlags();
}

struct FUN_0044c480
{
    virtual ~FUN_0044c480();
    void FUN_0044c3f0(int);
};

struct FUN_00449d60 : FUN_0044c480
{
    virtual ~FUN_00449d60();
};

// Destructor that calls FUN_0044c3f0 with 1.
// @fnv 0x00449d60
FUN_00449d60::~FUN_00449d60()
{
    FUN_0044c3f0(1);
}

namespace fnv_00449ec0 {
extern int DAT_0101737c;
struct FUN_0044c480
{
    virtual ~FUN_0044c480();
    void M(bool);
};
struct FUN_00449ec0 : FUN_0044c480
{
    virtual ~FUN_00449ec0();
};
// Destructor that calls M(true) on the base class.
// @fnv 0x00449ec0
FUN_00449ec0::~FUN_00449ec0()
{
    M(true);
}
}  // namespace fnv_00449ec0

namespace fnv_0044b300 {
struct FUN_0044b2a0_Class
{
    void InitScriptRunLock_Thunk();
};
void __fastcall FUN_0044b2e0(void*);
struct FUN_0044b300_Class
{
    FUN_0044b2a0_Class* m_pObject;
    FUN_0044b300_Class* ProcessAndReturnValue_0044b300(FUN_0044b2a0_Class* value);
};
// @fnv 0x0044b300
// src: GUESS 0x0044b300 (confidence: low)
FUN_0044b300_Class* FUN_0044b300_Class::ProcessAndReturnValue_0044b300(FUN_0044b2a0_Class* apObject)
{
    if (m_pObject != apObject)
    {
        if (m_pObject)
            FUN_0044b2e0(m_pObject);
        m_pObject = apObject;
        if (m_pObject)
            m_pObject->InitScriptRunLock_Thunk();
    }
    return this;
}
}  // namespace fnv_0044b300

namespace fnv_005292a0 {
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};

struct ModelLoaderDeletedNodeScanCall
{ // Local call-only form of LockFreeMap<K,T>::DeletedNodeScanner: 0x005292a0 calls 0x0044f070, but this erased queue does not identify its K/T specialization.
    void ScanForDeletedNodes();
};
struct FUN_005292a0
{
    unsigned int f0, f4, f8, fc, f10, f14, f18, f1c;
    unsigned int f20;
    void SetRace(unsigned int race);
};
// @fnv 0x005292a0
void FUN_005292a0::SetRace(unsigned int race)
{
    ((QIdlePtr*)(race + 4))->operator=(0);
    ((TESRaceForm*)race)->Initialize(f1c);
    f1c = race;
    f20++;
    if (f20 == (unsigned int)((BSAudio*)*(unsigned int*)this)->GetAudioBackendData())
        ((ModelLoaderDeletedNodeScanCall*)this)->ScanForDeletedNodes();
}
}  // namespace fnv_005292a0

namespace fnv_00666510 {

struct FUN_0044f200_Class
{
    void FilterListByQueueData();
};
struct FUN_00666510_Class
{
    void AddRace(TESRaceForm* pRace);
};
// @fnv 0x00666510
void FUN_00666510_Class::AddRace(TESRaceForm* pRace)
{
    *(unsigned int*)((char*)pRace + 4) = 0;
    pRace->Initialize(*(unsigned int*)((char*)this + 0x1c));
    *(TESRaceForm**)((char*)this + 0x1c) = pRace;
    *(unsigned int*)((char*)this + 0x20) += 1;
    if (*(unsigned int*)((char*)this + 0x20) == (unsigned int)(*(BSAudio**)((char*)this))->GetAudioBackendData())
        ((FUN_0044f200_Class*)this)->FilterListByQueueData();
}
}  // namespace fnv_00666510

namespace fnv_009052e0 {
struct KFModel
{
    void KFModel_IncRefCount();
    void KFModel_DecRefCount();
};
struct KFModelPtr
{
    KFModel* p;
    KFModel* AssignRetainedObject_009052e0(const KFModelPtr& other);
};
// @fnv 0x009052e0
// src: GUESS 0x009052e0 (confidence: medium)
KFModel* KFModelPtr::AssignRetainedObject_009052e0(const KFModelPtr& other)
{
    if (p != other.p)
    {
        if (p)
            p->KFModel_DecRefCount();
        p = other.p;
        if (p)
            p->KFModel_IncRefCount();
    }
    return (KFModel*)this;
}
}  // namespace fnv_009052e0

// Opens the file at apPath with NiFile::GetFile, saves the stream to it, deletes the file object and returns whether the save succeeded.
// @fnv 0x00c3a950
bool NiStream::Save(const char* apPath)
{
    NiFile* pFile = NiFile::GetFile(apPath, 1, 0x2800);
    bool bResult = false;
    if (pFile)
    {
        bResult = Save(pFile);
        delete pFile;
    }
    return bResult;
}

void __cdecl _Deallocate(void*);

// Destroys the BSStream, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0043d150
void* BSStream::FUN_0043d150(unsigned int flags)
{
    this->BSStream::~BSStream();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0043d8c0 {

void _Deallocate(void*);

}  // namespace fnv_0043d8c0

namespace fnv_0043d910 {
struct FNStub
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual char* vfn_18();
    char* GetFullName();
};

struct ModelLoaderQueueTexture : ModelLoader
{
    void QueueModelFilePath(const char*, int, QueuedFile*);
};

bool __cdecl CleanPath(const char*, char*, unsigned int);

}  // namespace fnv_0043d910

namespace fnv_0043da00 {
// BSTreeManager.h does not yet declare this external operation. This declaration-only
// adapter supplies its member-call ABI without duplicating the manager's layout.
struct ModelLoaderTreeOperations
{
    void BSTreeManager_AddBackgroundLoadedTree(int, BSTreeNode*);
};

typedef AutoMemHelper AutoMemContext;

BSTreeManager* DAT_011d5c48;

// Looks up a BSTreeNode by pRef and pTree via DAT_011d5c48 and passes it to FUN_00665b80 with pRef, inside an AutoMemContext scope.

}  // namespace fnv_0043da00

namespace fnv_0043e8f0 {
void __cdecl _Deallocate(void* ptr);

class FUN_0043e920_class
{
  public:
    void DoNothing_0043e920();
    void* FUN_0043e8f0(unsigned int flags);
};

// src: GUESS 0x0043e920 (confidence: high)
void FUN_0043e920_class::DoNothing_0043e920()
{}

// Calls FUN_0043e920, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0043e8f0
void* FUN_0043e920_class::FUN_0043e8f0(unsigned int flags)
{
    DoNothing_0043e920();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0043e8f0

struct FNStub
{
    char* GetFullName();
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);


// Formats "Queued head for NPC %s" into apDescription using the full name of the object at this+0x28, and returns true.
// @fnv 0x0043eed0
bool QueuedHead::GetQueuedHeadDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Queued head for NPC %s",
               reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(
                                             *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x28)) +
                                         0xd0)
                   ->GetFullName());
    return true;
}

namespace fnv_0043f030 {

void __cdecl _Deallocate(void* ptr);

}  // namespace fnv_0043f030

namespace fnv_0043f2b0 {

class FUN_0043c610_shell
{
  public:
    void RunVirtualMethod28();
};

bool __fastcall BSTask_int64_GetTaskCanceled(int*);

// If the object at offset 0x1c is zero and FUN_00449130 returns false, adds this to the post-process queue, then calls RunVirtualMethod28.

}  // namespace fnv_0043f2b0

namespace fnv_0043fb80 {

struct FUN_004aeb20_holder
{
    void AttachFaceGenModel(BSFaceGenModel*, NiNode*, BIPED_OBJECT);
};

struct BipedAnim : public FUN_004aeb20_holder
{
};

struct Standin0043fb50
{
    void DispatchToVirtual(int);
};

}  // namespace fnv_0043fb80

namespace fnv_0043fe10 {
void _Deallocate(void*);

struct FUN_00440eb0_class
{
    void FUN_0043fe40(void);
    void* FUN_0043fe10(unsigned int flags);
};

// @fnv 0x0043fe10
void* FUN_00440eb0_class::FUN_0043fe10(unsigned int flags)
{
    FUN_0043fe40();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_0043fe10

void __cdecl _Deallocate(void*);

// @fnv 0x00441cf0
void* QueuedFileLoad::FUN_00441cf0(unsigned int flags)
{
    FUN_00441d20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00446990 {
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};

struct FUN_00446990_StandIn
{
    unsigned int m_iFadeNodeMode[8];
    TESObjectREFR* m_pObject;

    unsigned int GetObjectFlags();
};

// Returns the flags of m_pObject via CallGetFlags, or 0 when m_pObject is null.
// @fnv 0x00446990
unsigned int FUN_00446990_StandIn::GetObjectFlags()
{
    return m_pObject ? reinterpret_cast<TESObjectREFR_GetFlags_Helper*>(m_pObject)->CallGetFlags() : 0;
}
}  // namespace fnv_00446990

namespace fnv_00449ab0 {
struct FUN_00449ea0_cls
{
    void ForwardCall_00449ea0(void);
    void* LockFreeCaseInsensitiveStringMap_LoadedFile_Destroy(unsigned int flags);
};

void _Deallocate(void* p);

// @fnv 0x00449ab0
// src: COMMUNITY 0x00449ab0
void* FUN_00449ea0_cls::LockFreeCaseInsensitiveStringMap_LoadedFile_Destroy(unsigned int flags)
{
    ForwardCall_00449ea0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449ab0

void __fastcall Object_SetVirtualTable_004499a0(int**);
void __cdecl _Deallocate(void*);

struct FUN_00449b70_Class
{
    void* FUN_00449b70(unsigned int flags);
};

// @fnv 0x00449b70
void* FUN_00449b70_Class::FUN_00449b70(unsigned int flags)
{
    Object_SetVirtualTable_004499a0((int**)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00449d10 {
struct FUN_00449c50
{
    virtual ~FUN_00449c50();
    FUN_00449c50* FUN_00449d10(unsigned int flags);
};

void _Deallocate(void* ptr);

FUN_00449c50::~FUN_00449c50()
{}

// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x00449d10
FUN_00449c50* FUN_00449c50::FUN_00449d10(unsigned int flags)
{
    FUN_00449c50::~FUN_00449c50();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_00449d10

namespace fnv_00449e70 {
struct FUN_00449d60
{
    virtual ~FUN_00449d60();
    void* FUN_00449e70(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449e70
void* FUN_00449d60::FUN_00449e70(unsigned int flags)
{
    this->FUN_00449d60::~FUN_00449d60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449e70

struct FUN_0044adb0_class
{
    unsigned char pad[0x4c];
    unsigned int count;
    ModelLoader** entries;

    void BSTaskManager_int64_ForceSignal();
};

// @fnv 0x0044adb0
// src: COMMUNITY 0x0044adb0
void FUN_0044adb0_class::BSTaskManager_int64_ForceSignal()
{
    for (unsigned int i = 0; i < count; ++i)
    {
        entries[i]->ProcessQueuedFile();
    }
}

// Emit the shared virtual destructor's scalar deleting entry point.
InterfacedClass::InterfacedClass()
{}

namespace fnv_00906320 {

class QHeadPtr
{
  public:
    ~QHeadPtr();
};

class FUN_009066d0_Class
{
  public:
    bool LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_Remove();
};

struct FUN_00906320_Class
{
    unsigned char _padding[0x20];
    RecursiveSpinLock _spinLock;

    FUN_009066d0_Class* LockFreeMap_GetInterface_0(int*, QHeadPtr*);
    bool LockFreeMap_T_Key_NiPointer_IOTask_Remove(int*, QHeadPtr);
};

// Locks the spin lock, calls FUN_009066d0 on the object returned by FUN_00449f80, unlocks, and returns the result.
// @fnv 0x00906320
// src: COMMUNITY 0x00906320
bool FUN_00906320_Class::LockFreeMap_T_Key_NiPointer_IOTask_Remove(int* a, QHeadPtr q)
{
    _spinLock.Lock(0);
    bool result = LockFreeMap_GetInterface_0(a, &q)->LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_Remove();
    _spinLock.Unlock();
    return result;
}
}  // namespace fnv_00906320

struct FUN_009157c0
{
    void Method(void);
};

void _Deallocate(void* p);

struct FUN_00915790
{
    void* DeleteThis(unsigned int flags);
};

// Calls Method on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00915790
void* FUN_00915790::DeleteThis(unsigned int flags)
{
    ((FUN_009157c0*)this)->Method();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00449dc0 {

unsigned int _BSStringLength(char const*);

struct FUN_00449dc0_Class
{
    char* LockFreeStringMap_Model_GenerateKey(char const*);
};

// @fnv 0x00449dc0
// src: COMMUNITY 0x00449dc0
char* FUN_00449dc0_Class::LockFreeStringMap_Model_GenerateKey(char const* apString)
{
    AutoMemHelper helper(6, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h", 0x1d7);

    unsigned int length = _BSStringLength(apString) + 1;
    char* result2 = new char[length];

    TaskQueueInterface::CopyStringToBuffer(result2, length, apString);
    return result2;
}
}  // namespace fnv_00449dc0

namespace fnv_009066d0 {
struct FUN_0044df00Class
{
    int ClearLowBit_Thunk();
};

struct FUN_00529000_Class
{
    void LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
};

int __fastcall ClearLowBit(int*);
bool __cdecl CompareAndSwapEx(void*, int, int);

struct FUN_009066d0_Class : public FUN_00529000_Class
{
    char pad[0x0F];
    void* member10;
    FUN_0044df00Class member14;
    int* member18;

    bool LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_Remove(int, int);
    bool LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_FindValue(int, int);
    void FUN_005292a0(int);
};

// @fnv 0x009066d0
// src: COMMUNITY 0x009066d0
bool FUN_009066d0_Class::LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_Remove(int arg1, int arg2)
{
    bool result = false;

    while (true)
    {
        if (!LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_FindValue(arg1, arg2))
        {
            result = false;
            break;
        }

        // These tagged-pointer scratch values have no owning GO lifetime.
        unsigned int go3;
        unsigned int go2;
        unsigned int go1;

        reinterpret_cast<GO*>(&go3)->SetTaggedPointer(false, (void*)ClearLowBit((int*)&member18));
        reinterpret_cast<GO*>(&go2)->SetTaggedPointer(true, (void*)ClearLowBit((int*)&member18));

        if (!CompareAndSwapEx((void*)(member14.ClearLowBit_Thunk() + 8), reinterpret_cast<GO*>(&go2)->operator unsigned int(),
                          reinterpret_cast<GO*>(&go3)->operator unsigned int()))
        {
            continue;
        }

        reinterpret_cast<GO*>(&go1)->SetTaggedPointer(false, (void*)ClearLowBit((int*)&member14));

        if (CompareAndSwapEx(member10, reinterpret_cast<GO*>(&go3)->operator unsigned int(), reinterpret_cast<GO*>(&go1)->operator unsigned int()))
        {
            FUN_005292a0(ClearLowBit((int*)&member14));
        }
        else
        {
            LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_FindValue(arg1, arg2);
        }

        result = true;
        break;
    }

    LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
    return result;
}
}  // namespace fnv_009066d0

class B43D100Object
{
  public:
    virtual ~B43D100Object();
};

// Deletes the owned B43D100Object and clears the pointer to null.
// @fnv 0x0043d100
void BSStream::DestroyObject()
{
    delete reinterpret_cast<B43D100Object*>(unk5c4);
    unk5c4 = 0;
}

// Constructor-like thiscall with 3 stack args: calls a base routine with two
// args, stores the class vtable pointer, stores the third arg at +0x38, returns this.

extern char DAT_0101698c[];

struct FUN_0043bd10_base
{
    void FUN_0043bd10(int a1, int a2);
};

// Retained: QueuedTreeBillboard.h lacks the three-argument constructor.
struct FUN_0043d540_cls : FUN_0043bd10_base
{
    void* m_pVTable;
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
    int m_iValue38;

    FUN_0043d540_cls* InitializeFields_0043d540(int a1, int a2, int a3);
};

// Calls the base constructor with a1 and a2, sets the vtable pointer to DAT_0101698c, stores a3 in m_iValue38, and returns this.
// @fnv 0x0043d540
// src: GUESS 0x0043d540 (confidence: low)
FUN_0043d540_cls* FUN_0043d540_cls::InitializeFields_0043d540(int a1, int a2, int aiValue)
{
    FUN_0043bd10(a1, a2);
    m_pVTable = (void*)DAT_0101698c;
    m_iValue38 = aiValue;
    return this;
}

class Sub_0043d5b0
{
  public:
    unsigned int m_00;
    int Release(unsigned int flags);
};

class Base_0043d5b0
{
  public:
    virtual ~Base_0043d5b0();
};

class FUN_0043d5b0_cls : public Base_0043d5b0
{
  public:
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
    Sub_0043d5b0* m_38;
    virtual ~FUN_0043d5b0_cls();
};

// Destructor that releases the Sub_0043d5b0 stored in m_38 with flag 1 if it is non-null.
// @fnv 0x0043d5b0
FUN_0043d5b0_cls::~FUN_0043d5b0_cls()
{
    Sub_0043d5b0* copy;
    Sub_0043d5b0* tmp;
    copy = m_38;
    tmp = copy;
    tmp != 0 ? tmp->Release(1) : 0;
}

class Obj43D730
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void Update();

    void QueuedTreeBillboard_PostProcess();
};

// @fnv 0x0043d730
// src: XBOX_PDB 0x0043d730
void Obj43D730::QueuedTreeBillboard_PostProcess()
{
    Update();
}

// Create a temporary object from the owner, run the batch with it described by a stack packet,
// then delete the object.

class D750Object
{
  public:
    virtual ~D750Object();
};

class D750Owner
{
  public:
    D750Object* Create(int iFlags);
    void* GetTarget();
};

struct D750Packet
{
    int m_iFlags;
    D750Object* m_pPointer;
    void* m_pkTarget;
    D750Packet();
};

struct D750Data
{
    D750Owner* m_pkOwnerManager;
    void* m_pvArg1;
    void* m_pvArg2;
    void* m_pvArg3;
    unsigned short m_usElementCount;
    void* m_pvArg5;
    void* m_pvArg6;
};

void __cdecl D750Process(void* pvArg1, void* pvArg2, void* pvArg3, D750Packet* pkPacket, void* pvArg5, void* pvArg6,
                         unsigned int ItemUpdateArray);

class D750Batch
{
  public:
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
    D750Data* m_pUserData;

    void CreateAndProcessObject();
};

// @fnv 0x0043d750
void D750Batch::CreateAndProcessObject()
{
    D750Object* pkObject = m_pUserData->m_pkOwnerManager->Create(1);
    if (pkObject)
    {
        D750Packet kPacket;
        kPacket.m_pkTarget = m_pUserData->m_pkOwnerManager->GetTarget();
        kPacket.m_pPointer = pkObject;
        kPacket.m_iFlags = 0;
        D750Process(m_pUserData->m_pvArg1, m_pUserData->m_pvArg2, m_pUserData->m_pvArg3, &kPacket, m_pUserData->m_pvArg5,
                    m_pUserData->m_pvArg6, m_pUserData->m_usElementCount);
        delete kPacket.m_pPointer;
    }
}

extern int DAT_010169d4;

// Retained: QueuedTreeModel.h lacks this four-argument constructor.
class FUN_0043d850_cls
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
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
    unsigned int m_48;
    void* m_4c;

    void FUN_0043c890(void* tmp, unsigned int a3, unsigned int a4, int one, int zero);
    FUN_0043d850_cls* QueuedTreeModel_QueuedTreeModel(unsigned int a1, void* a2, unsigned int a3, unsigned int a4);
};

// @fnv 0x0043d850
// src: EXE 0x0043d850
FUN_0043d850_cls* FUN_0043d850_cls::QueuedTreeModel_QueuedTreeModel(unsigned int a1, void* a2, unsigned int auiArg3, unsigned int auiArg4)
{
    FUN_0043c890((a2 != 0) ? (void*)((char*)a2 + 0x30) : 0, auiArg3, auiArg4, 1, 0);
    m_ppVirtualMethodTable = (void*)&DAT_010169d4;
    m_48 = a1;
    m_4c = a2;
    m_18 = 0x1e;
    return this;
}

// UpdateStateAndNotify : save-game state update helper.
//
// The object keeps a pointer to the pending change record at +0x48.
// The method first hands the two arguments to the internal state updater
// and then, once the update counter reaches 4, notifies the global
// listener (DAT_011d5c48) about the pending record.

class SaveGameChange;  // opaque record type

class SaveGameListener
{
  public:
    void Notify(SaveGameChange* pChange);
};

// Global listener instance (defined elsewhere in the game).
extern SaveGameListener* DAT_011d5c48;

struct FUN_0043dac0_cls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    SaveGameChange* m_48;

    void UpdateState(int aIndex, int aFlags);

    void UpdateStateAndNotify(int aIndex, int aFlags);
};

// Calls UpdateState with aIndex and aFlags, then notifies DAT_011d5c48 with m_48 when aIndex is at least 4.
// @fnv 0x0043dac0
void FUN_0043dac0_cls::UpdateStateAndNotify(int aIndex, int aFlags)
{
    UpdateState(aIndex, aFlags);

    if (aIndex >= 4)
    {
        DAT_011d5c48->Notify(m_48);
    }
}

class B43E8B0Base
{
  public:
    B43E8B0Base(int iArg1, int iArg2);
    virtual ~B43E8B0Base();

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
};

// Retained: QueuedReplacementKF.h lacks the four-argument constructor and
// the derived fields at 0x38/0x3C.
class FUN_0043e8b0_cls : public B43E8B0Base
{
  public:
    FUN_0043e8b0_cls(int iArg1, int iArg2, int iValue38, int iValue3C);
    virtual ~FUN_0043e8b0_cls();

    int m_iValue38;
    int m_iValue3C;
};

// Base constructor runs with iArg1 and iArg2, then stores iValue38 and iValue3C into m_iValue38 and m_iValue3C.
// @fnv 0x0043e8b0
FUN_0043e8b0_cls::FUN_0043e8b0_cls(int iArg1, int iArg2, int iValue38, int iValue3C) : B43E8B0Base(iArg1, iArg2)
{
    m_iValue38 = iValue38;
    m_iValue3C = iValue3C;
}

struct SaveLoadBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;

    SaveLoadBase(unsigned int flags);
    virtual ~SaveLoadBase();
};

struct SaveLoadTarget
{
    unsigned int Compute();
};

struct SaveLoadElemA
{
    int unk00;

    SaveLoadElemA();
    ~SaveLoadElemA();
};

struct SaveLoadElemB
{
    int unk00;

    SaveLoadElemB();
    ~SaveLoadElemB();
};

class FUN_0043ef10 : public SaveLoadBase
{
  public:
    SaveLoadTarget* m_pFlagTarget;
    SaveLoadElemA m_arrA[20];
    SaveLoadElemB m_arrB[20];
    SaveLoadElemB m_arrC[20];
    unsigned int m_11c;
    unsigned char m_120;

    FUN_0043ef10(SaveLoadTarget* target, unsigned int flags, unsigned int unused);
    virtual ~FUN_0043ef10();
};

// Initializes the base with flags, stores the target pointer, clears m_120, and sets m_11c to the target's Compute() result.
// @fnv 0x0043ef10
FUN_0043ef10::FUN_0043ef10(SaveLoadTarget* target, unsigned int flags, unsigned int unused)
    : SaveLoadBase(flags), m_pFlagTarget(target)
{
    m_120 = 0;
    m_11c = m_pFlagTarget->Compute();
}

struct SpawnedCallee
{
    void SetObjectAndAddReference(void* pObject);
};

struct FUN_0043f060_cls : public SpawnedCallee
{
    void ForwardCall_0043f060();
};

// @fnv 0x0043f060
// src: GUESS 0x0043f060 (confidence: low)
void FUN_0043f060_cls::ForwardCall_0043f060()
{
    SetObjectAndAddReference(0);
}

class FUN_0043f220_cls
{
  public:
    int unk00;
    void* GetEntryAt(int a1);
};

// @fnv 0x0043f220
void* FUN_0043f220_cls::GetEntryAt(int aiIndex)
{
    return (char*)this + aiIndex * 16 + 0x2c;
}

namespace fnv_0043fb10 {
struct VirtObj0043fb50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};

struct Standin0043fb50
{
    char _pad[0x18];
    VirtObj0043fb50* m_18;
    void DispatchToVirtual(int);
};

struct Host0043fb10
{
    char _pad[0x11c];
    Standin0043fb50* m_11c;
    void QueuedFile_Cancel(int, int);
    void CallWithArgsAndForwardMember(int a, int b);
};

extern Standin0043fb50* g_11c3b3c;

// Calls FUN_00c3cb70 with a and b, then calls DispatchToVirtual on g_11c3b3c passing m_11c.
// @fnv 0x0043fb10
void Host0043fb10::CallWithArgsAndForwardMember(int aiArg1, int aiArg2)
{
    QueuedFile_Cancel(aiArg1, aiArg2);
    g_11c3b3c->DispatchToVirtual((int)m_11c);
}
}  // namespace fnv_0043fb10

struct SpawnedBase
{
    virtual ~SpawnedBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    SpawnedBase(int a1);
};

struct ModelLoaderSubObjA
{
    int unk00;
    ModelLoaderSubObjA(int v);
    ~ModelLoaderSubObjA();
};

struct ModelLoaderSubObjB
{
    int unk00;
    ModelLoaderSubObjB(int v);
    ~ModelLoaderSubObjB();
};

struct FUN_0043fd40 : SpawnedBase
{
    int m_28;
    ModelLoaderSubObjA m_2c;
    NiPointer<Model> m_30;
    NiPointer<NiNode> m_34;
    ModelLoaderSubObjA m_38;

    FUN_0043fd40(int a1, int a2);
    virtual ~FUN_0043fd40();
};

// Constructs a SpawnedBase-derived object, storing a1 in m_28 and initializing the four sub-objects to 0.
// @fnv 0x0043fd40
FUN_0043fd40::FUN_0043fd40(int a1, int a2) : SpawnedBase(a2), m_28(a1), m_2c(0), m_30(0), m_34(0), m_38(0)
{}

class Base_b4619
{
  public:
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
    ~Base_b4619();
};

class Sub4_b4619
{
  public:
    unsigned int m_00;
    ~Sub4_b4619();
};

class SubB_b4619
{
  public:
    unsigned int m_00;
    ~SubB_b4619();
};

class SubC_b4619
{
  public:
    unsigned int m_00;
    ~SubC_b4619();
};

class FUN_0043fe40_cls : public Base_b4619
{
  public:
    Sub4_b4619 m_2c;
    SubB_b4619 m_30;
    SubC_b4619 m_34;
    Sub4_b4619 m_38;
    ~FUN_0043fe40_cls();
};

// Destructor for FUN_0043fe40_cls; destroys its Base_b4619 base and the Sub4_b4619, SubB_b4619 and SubC_b4619 members.
// @fnv 0x0043fe40
FUN_0043fe40_cls::~FUN_0043fe40_cls()
{}






#include "../../include/NiPointer.h"
using ::NiPointer;


struct ModelSourceStub
{
    const char* GetModelFilePath();
};
void __cdecl TESModel_GetDistantModelName(char*, const char*);

struct AttachTaskStub
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
    virtual void Attach(NiNode*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    ModelSourceStub* pSource;
    void AttachModelFromSource();
};

// @fnv 0x00440190
void AttachTaskStub::AttachModelFromSource()
{
    NiNode* pNode = 0;
    char acPath[264];
    TESModel_GetDistantModelName(acPath, pSource->GetModelFilePath());
    NiPointer<Model> spLoaded(0);
    g_modelLoader->GetModel(acPath, spLoaded);
    if (spLoaded && spLoaded->GetObject3D())
    {
        NiObject* pClonedObject = spLoaded->GetObject3D()->Clone();
        if (pClonedObject)
        {
            pNode = pClonedObject->IsSceneNode();
            if (!pNode)
            {
                (NiPointer<NiObject>(pClonedObject));
            }
            else if (pNode->IsFadeNode())
            {
                pNode->BSFadeNode_SetLODMultType(6);
            }
        }
    }
    if (pNode)
    {
        Attach(pNode);
    }
}

enum B4404C0Priority
{
    B4404C0_PRIORITY_CRITICAL = 0
};

class B4404C0Task
{
  public:
    B4404C0Task(B4404C0Priority ePriority);
    virtual ~B4404C0Task();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct B4404C0Handle
{
    int m_iValue;

    void Set(int iValue);
};

class FUN_004404c0 : public B4404C0Task
{
  public:
    void* m_pvTarget;
    B4404C0Handle m_kHandle;

    FUN_004404c0(void* pvTarget, int iHandle);
    virtual ~FUN_004404c0();
};

// Constructs a critical-priority task storing the target pointer and setting the handle to the given value.
// @fnv 0x004404c0
FUN_004404c0::FUN_004404c0(void* pvTarget, int iHandle) : B4404C0Task(B4404C0_PRIORITY_CRITICAL)
{
    m_pvTarget = pvTarget;
    m_kHandle.Set(iHandle);
}

struct PriorityKey
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned __int64 key;
    void __thiscall IOTask_SetPriority(unsigned char priority);
};

// Replaces the priority byte stored in bits 16-23 of key, preserving all other bits.
// @fnv 0x004405d0
// src: COMMUNITY 0x004405d0
void PriorityKey::IOTask_SetPriority(unsigned char priority)
{
    key = (key & 0xffffffffff00ffffui64) + ((__int64)priority << 16);
}

class SaveBase_b3799
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    ~SaveBase_b3799();
};

class SaveSub_b3799
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ~SaveSub_b3799();
};

// Retained: AttachDistant3DTask.h omits its target/handle members and
// constructor; the handle destructor and original base unwind are required here.
class FUN_004406b0 : public SaveBase_b3799
{
  public:
    SaveSub_b3799 m_1c;
    ~FUN_004406b0();
};

// @fnv 0x004406b0
FUN_004406b0::~FUN_004406b0()
{}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

class B40DC0Base
{
  public:
    const char* GetTypeName();
};

class B40DC0Ref
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
    virtual const char* GetEditorID();

    unsigned int GetFormID();
    B40DC0Base* GetBaseObject();
};

class B40DC0Task
{
  public:
    bool IsComplete();
    bool FormatQueuedRefDescription(char* pcBuffer, unsigned int uiSize);

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
    B40DC0Ref* m_pkRef;
};

// If the task is not complete, formats the queued ref's editor ID, form ID and base object type name into pcBuffer and returns true; otherwise returns false.
// @fnv 0x00440dc0
bool B40DC0Task::FormatQueuedRefDescription(char* pcBuffer, unsigned int uiSize)
{
    if (IsComplete())
        return false;
    _sprintf_s(pcBuffer, uiSize, "Queued ref '%s' (%08X) of type %s", m_pkRef->GetEditorID(), m_pkRef->GetFormID(),
               m_pkRef->GetBaseObject()->GetTypeName());
    return true;
}

struct Node1;
struct Node2;
struct Node3;
struct Node4;
struct Node5;
struct Node0
{
    Node1* BGSSaveFormBuffer_GetForm();
};
struct Node1
{
    Node2* CreateBillboardSceneObject(int);
};
struct Node2
{
    Node3* FUN_0043b4a0(int);
};
struct Node3
{
    Node4* NiGeometry_GetModelData();
    Node5* FUN_00a59d30(int);
};
struct Node4
{
    void FUN_00a67050(int);
    void SetByteAtOffset38(int);
    void FUN_004410f0(int);
};
struct Node5
{
    int FUN_00441110();
    void BSShaderProperty_SetFlag(int, int);
};
void __cdecl FUN_00b57e30(Node3*, int, int);
struct Owner
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void OnChildCompletion();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34(Node2*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Node0* unk28;
    void QueuedTree_UseDistant3D();
};
// @fnv 0x00440fd0
// src: XBOX_PDB 0x00440fd0
void Owner::QueuedTree_UseDistant3D()
{
    Node1* node1 = unk28->BGSSaveFormBuffer_GetForm();
    Node2* node2 = node1->CreateBillboardSceneObject(0);
    if (node2)
    {
        Node3* node3 = node2->FUN_0043b4a0(0);
        Node4* status = node3->NiGeometry_GetModelData();
        status->FUN_00a67050(0x4000);
        status->SetByteAtOffset38(0x11);
        status->FUN_004410f0(1);
        FUN_00b57e30(node3, 0, 0);
        Node5* action = (node3->FUN_00a59d30(3) == 0 ? false : node3->FUN_00a59d30(3)->FUN_00441110() == 0xb)
                            ? node3->FUN_00a59d30(3)
                            : 0;
        if (action)
        {
            action->BSShaderProperty_SetFlag(13, 1);
            action->BSShaderProperty_SetFlag(22, 1);
        }
        vfn_34(node2);
    }
}

namespace fnv_004420b0 {
struct SpawnedBase
{
    virtual ~SpawnedBase();
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

    SpawnedBase(int a1, int a2);
};

struct ModelLoaderSubObjA
{
    int unk00;
    ModelLoaderSubObjA(int v);
    ~ModelLoaderSubObjA();
};

struct ModelLoaderSubObjB
{
    int unk00;
    ModelLoaderSubObjB(int v);
    ~ModelLoaderSubObjB();
};

struct FUN_004420b0 : SpawnedBase
{
    ModelLoaderSubObjA m_kPointA;
    ModelLoaderSubObjB m_kPointB;

    FUN_004420b0(int a1, int a2);
    virtual ~FUN_004420b0();
};

// @fnv 0x004420b0
FUN_004420b0::FUN_004420b0(int a1, int a2) : SpawnedBase(a1, a2), m_kPointA(0), m_kPointB(0)
{}
}  // namespace fnv_004420b0

class C4422C0Object
{
  public:
    virtual ~C4422C0Object();
};

// @fnv 0x004422c0
BackgroundCloneThread::~BackgroundCloneThread()
{
    delete (C4422C0Object*)m_pCloneQueue;
}

struct FUN_00444540_Scope
{
    unsigned int m_00;
    FUN_00444540_Scope(int mode);
    ~FUN_00444540_Scope();
};

class FUN_00444540_cls
{
  public:
    unsigned int m_00;
    void DispatchWithScope(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
    void Dispatch(unsigned int a, unsigned int b, FUN_00444540_Scope& scope, unsigned int c, unsigned int d,
                  unsigned int e);
};

// Creates a scope object with mode 0 and forwards all arguments to Dispatch.
// @fnv 0x00444540
void FUN_00444540_cls::DispatchWithScope(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e)
{
    FUN_00444540_Scope scope(0);
    Dispatch(a, b, scope, c, d, e);
}

struct S_004445c0_Obj
{
    S_004445c0_Obj(int a, int b, int c, int d);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    void FUN_00443aa0(int a);
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
};
struct S_004445c0_Ptr
{
    S_004445c0_Obj* m_pObject;
    S_004445c0_Ptr(S_004445c0_Obj* p);
    ~S_004445c0_Ptr();
    S_004445c0_Obj* operator->() const;
};
struct S_004445c0_Dest
{
    S_004445c0_Ptr& FUN_0092c820(const S_004445c0_Ptr& p);
};
struct S_004445c0_This
{
    void ModelLoader_QueueTreeModel(int a1, int a2, S_004445c0_Dest* a3, int a4, int a5, int a6);
};
// Allocates an object from the given arguments, calls FUN_00443aa0 and v8 on it, then passes it to FUN_0092c820 on the destination.
// @fnv 0x004445c0
// src: XBOX_PDB 0x004445c0
void S_004445c0_This::ModelLoader_QueueTreeModel(int aiArg1, int aiArg2, S_004445c0_Dest* pDest, int aiArg4, int aiArg5, int aiArg6)
{
    S_004445c0_Ptr sp(new S_004445c0_Obj(aiArg1, aiArg2, aiArg4, aiArg6));
    sp->FUN_00443aa0(aiArg5);
    sp->v8();
    pDest->FUN_0092c820(sp);
}

struct Obj3D
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void SetX(int);  // 0x1c
    virtual void Y();        // 0x20
    int IOTask_GetIOTaskPriority();
};
struct RefPtr
{
    void* m;
    RefPtr(void*);
    ~RefPtr();
    Obj3D* Modelloader_GetReferencedThis();
    void AssignTaskReference(void*);
};
struct Base3D
{
    int FUN_00401170();
};
struct Proc
{
    void InitScriptRunLockForObject();
    void TESObjectCELL_IncCriticalQueuedRefCount();
};
struct Ref
{
    char pad[0x224];
    bool Projectile_IsFlagSet(int);
    Base3D* BGSSaveFormBuffer_GetForm();
    Proc* FUN_008d6f30();
    bool TESObjectREFR_Is3DCritical();
};
struct RefV
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void w77();
    virtual void w78();
    virtual void w79();
    virtual void w80();
    virtual void w81();
    virtual void w82();
    virtual void w83();
    virtual void w84();
    virtual void w85();
    virtual void w86();
    virtual void w87();
    virtual void w88();
    virtual void w89();
    virtual void w90();
    virtual void w91();
    virtual void w92();
    virtual void w93();
    virtual void w94();
    virtual void w95();
    virtual void w96();
    virtual void w97();
    virtual void w98();
    virtual void w99();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void w107();
    virtual void w108();
    virtual void w109();
    virtual void w110();
    virtual void w111();
    virtual void w112();
    virtual void w113();
    virtual void w114();
    virtual void w115();
    virtual void w116();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual void w125();
    virtual void w126();
    virtual void w127();
    virtual void w128();
    virtual void w129();
    virtual void w130();
    virtual void w131();
    virtual void w132();
    virtual void w133();
    virtual void w134();
    virtual void w135();
    virtual void w136();
    virtual bool IsX();
};
struct Queue
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(Ref*, RefPtr*);  // 0x8
    virtual void v3();
    virtual bool Add(Ref*, RefPtr*, bool);  // 0x10
};
struct Mgr
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
    bool FUN_00444d20();
};
struct G1
{
    int TESMain_GetThread();
};
struct TaskA
{
    char d[72];
    TaskA(int);
    void* operator new(unsigned int);
};
struct TaskB
{
    char d[64];
    TaskB(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskC
{
    char d[72];
    TaskC(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskD
{
    char d[64];
    TaskD(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskE
{
    char d[64];
    TaskE(Ref*, int);
    void* operator new(unsigned int);
};

int FUN_0040fc90();
bool Interface_IsInMenuMode();
extern Mgr* DAT_011ddf38;
extern Ref* DAT_011dea3c;
extern G1* DAT_011dea0c;

struct ML
{
    int unk0, unk4;
    Queue* q8;
    Queue* qc;
    void ModelLoader_QueueReference(Ref* ref, int a2, bool a3);
};

// Checks manager and ref state, updates or creates a queued load task for ref, then adds it to q8 and optionally qc.
// @fnv 0x00444850
// src: XBOX_PDB 0x00444850
void ML::ModelLoader_QueueReference(Ref* ref, int aiValue, bool a3)
{
    if (DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading() && !DAT_011ddf38->FUN_00444d20())
        return;
    if (ref->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 0xd)
        return;
    if (((RefV*)ref)->IsX())
    {
        Ref* r = ref;
        if (r->Projectile_IsFlagSet(2))
            return;
    }
    RefPtr p(0);
    if (q8->Lookup(ref, &p))
    {
        int v = p.Modelloader_GetReferencedThis()->IOTask_GetIOTaskPriority();
        if (v != aiValue)
            p.Modelloader_GetReferencedThis()->SetX(aiValue);
        return;
    }
    AutoMemHelper memCtx(0x31, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc4e);
    if (ref == DAT_011dea3c)
    {
        AutoMemHelper c2(0x34, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc53);
        p.AssignTaskReference(new TaskA(aiValue));
    }
    else
    {
        switch (ref->BGSSaveFormBuffer_GetForm()->FUN_00401170())
        {
        case 0x25: {
            p.AssignTaskReference(new TaskB(ref, aiValue));
            break;
        }
        case 0x2a: {
            AutoMemHelper memCtx3(0x32, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc6b);
            p.AssignTaskReference(new TaskC(ref, aiValue));
            break;
        }
        case 0x2b: {
            AutoMemHelper memCtx4(0x32, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc72);
            p.AssignTaskReference(new TaskD(ref, aiValue));
            break;
        }
        default: {
            p.AssignTaskReference(new TaskE(ref, aiValue));
            break;
        }
        }
    }
    if (q8->Add(ref, &p, false))
    {
        bool b = false;
        if (a3 && FUN_0040fc90() == DAT_011dea0c->TESMain_GetThread() && !Interface_IsInMenuMode())
            b = true;
        if (b)
            qc->Add(ref, &p, true);
        else
            p.Modelloader_GetReferencedThis()->Y();
        if (ref->FUN_008d6f30())
        {
            ref->FUN_008d6f30()->InitScriptRunLockForObject();
            if (ref->TESObjectREFR_Is3DCritical())
                ref->FUN_008d6f30()->TESObjectCELL_IncCriticalQueuedRefCount();
        }
    }
    else
    {
        p.AssignTaskReference(0);
    }
}

namespace fnv_00445370 {
class TargetObj
{
  public:
    virtual void v00();
    virtual void v04();
    virtual bool v08(unsigned int a, TargetObj** out);
    virtual void v0c();
    virtual void v10();
    virtual void v14(unsigned int a);
    void FinishScriptRunLockIfActive();
    bool BGSSaveLoadGame_GetSaveGameLoading();
    int KFModel_GetRefCount();
    int FUN_00443240(int a);
};

extern TargetObj* DAT_011ddf38;

class FUN_00445370_cls
{
  public:
    void* m_00;
    TargetObj* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    unsigned char m_2c;
    void ModelLoader_ReleaseKF(unsigned int a1, bool flag);
};

// @fnv 0x00445370
// src: XBOX_PDB 0x00445370
void FUN_00445370_cls::ModelLoader_ReleaseKF(unsigned int a1, bool flag)
{
    TargetObj* p = 0;
    if (this->m_04->v08(a1, &p))
    {
        p->FinishScriptRunLockIfActive();
        if (DAT_011ddf38 != 0 && DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading())
        {
            flag = false;
            this->m_2c = 1;
        }
        if (flag)
        {
            if (p->KFModel_GetRefCount() == 0)
            {
                this->m_04->v14(a1);
                TargetObj* a = p;
                TargetObj* aQ = a;
                (aQ != 0) ? aQ->FUN_00443240(1) : 0;
            }
        }
    }
}
}  // namespace fnv_00445370

struct AC_0042f730;
extern IOManager* DAT_01202d98;

class SaveTmp_b9539
{
  public:
    AC_0042f730* m_pObject;
    SaveTmp_b9539(AC_0042f730* pObject);
    ~SaveTmp_b9539();
    int Get(int n);
};


class SaveCaller_b9539
{
  public:
    virtual void v0();
    virtual void v1();
    virtual bool v2(int a, SaveTmp_b9539* pTmp);
};

class SaveOwner_b9539
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    SaveCaller_b9539* m_10;
    void ModelLoader_CancelAnimIdle(int a);
};

// @fnv 0x004454d0
// src: COMMUNITY 0x004454d0
void SaveOwner_b9539::ModelLoader_CancelAnimIdle(int a)
{
    SaveTmp_b9539 tmp(0);
    if (this->m_10->v2(a, &tmp))
    {
        DAT_01202d98->BSTaskManager_CancelTask(tmp.Get(0));
    }
}

class B445670Cell;

class B445670Ref
{
  public:
    B445670Cell* GetParentCell();
};

class B445670Cell
{
  public:
    void* GetLoadedData();
};

class B445670Iterator
{
  public:
    B445670Iterator();
    ~B445670Iterator();
    bool IsDone();

    int m_iIndex;
    int m_iArrayLength;
    int m_iBucket;
    void* m_pvCurrent;
};

class B445670Handle
{
  public:
    B445670Handle(void* pvObject);
    ~B445670Handle();

    void* m_pvObject;
};

class B445670Table
{
  public:
    bool AdvanceRequest(B445670Iterator* pkIter, B445670Ref** ppkRef, B445670Handle* pkHandle, int iFlag);
};

class B445670Loader
{
  public:
    void ModelLoader_CancelReference(B445670Ref* pkRef);
    void ModelLoader_CancelReferencesForCell(B445670Cell* pkCell);

    int unk00;
    int unk04;
    B445670Table* m_pkTable;
};

// Iterates the table and calls FUN_00445570 on each ref whose parent cell is pkCell, after checking the cell has loaded data.
// @fnv 0x00445670
// src: XBOX_PDB 0x00445670
void B445670Loader::ModelLoader_CancelReferencesForCell(B445670Cell* pkCell)
{
    if (!pkCell || !pkCell->GetLoadedData())
        return;

    B445670Iterator kIter;
    while (!kIter.IsDone())
    {
        B445670Ref* pkRef = 0;
        B445670Handle kHandle2(0);
        if (m_pkTable->AdvanceRequest(&kIter, &pkRef, &kHandle2, 1))
        {
            if (pkRef->GetParentCell() == pkCell)
                ModelLoader_CancelReference(pkRef);
        }
    }
}

int FUN_00406d30(char* dst, unsigned int size, const char* src);
char* strrchr_0040ab30(char* str, int ch);

// TESModelList accessors not yet declared by its shared header.
struct CreatureData114
{
    int FUN_00717e50();
    int GetOffsetC();
};

struct ItemEntry
{
    ~ItemEntry();
    int FUN_0044ddc0(int a, int b, void* ref);
    int unk00;
};

struct ModelLoaderHelper445
{
    void QueueKFPathsFromList(int a, int b, int c, int d, char* path);
    void ModelLoader_QueueBoundObject(int v);
    void ModelLoader_QueueCreatureParts(TESModel* model, int a, int b, void* ref);
};

// @fnv 0x004457d0
// src: COMMUNITY 0x004457d0
void ModelLoaderHelper445::ModelLoader_QueueCreatureParts(TESModel* model, int aiArg1, int aiArg2, void* ref)
{
    TESCreature* creature = dynamic_cast<TESCreature*>(reinterpret_cast<TESModel*>(model));
    char path[0x104];
    if (creature)
    {
        int node = reinterpret_cast<CreatureData114*>(reinterpret_cast<char*>(&creature->m_kModelPaths) - sizeof(void*))->FUN_00717e50();
        FUN_00406d30(path, 0x104, model->GetModelFilePath());
        char* slash = strrchr_0040ab30(path, '\\');
        if (slash)
        {
            slash[1] = 0;
        }
        QueueKFPathsFromList(node, reinterpret_cast<CreatureData114*>(reinterpret_cast<char*>(&creature->m_kModelPaths) - sizeof(void*))->GetOffsetC(), aiArg1, aiArg2, path);
        if (ref)
        {
            InventoryChanges* changes = InventoryChanges::GetOrAddInventoryChanges(ref);
            int count;
            ItemEntry* entry = changes->SelectBestWeapon(creature, &count, 6, 0);
            if (entry)
            {
                ModelLoader_QueueBoundObject(entry->FUN_0044ddc0(aiArg1, aiArg2, ref));
                delete entry;
            }
            entry = changes->FindBestAmmoChange(creature, 0);
            if (entry)
            {
                ModelLoader_QueueBoundObject(entry->FUN_0044ddc0(aiArg1, aiArg2, ref));
                delete entry;
            }
        }
    }
}

int ModelLoaderStrcpyS(char* dst, unsigned int size, const char* src);
int ModelLoaderStrcatS(char* dst, unsigned int size, const char* src);

struct KFQueueOwner
{
    void* MakeTask(int index);
};

struct ModelLoaderKFList : public ModelLoader
{
    void QueueKFPath(const char* path, void* task, int priority, void* queued, int a, int b, int c, int d);
    void QueueKFPathDirect(const char* path, int priority, void* queued, int a, bool b, bool c, bool d);
    void QueueKFPathsFromList(BSSimpleList<const char*>* list, KFQueueOwner* owner, int priority, void* queued,
                              const char* prefix);
};

// Walks a list of names, optionally prefixes each into a path buffer, and queues each KF path either via owner tasks or directly.
// @fnv 0x004463b0
void ModelLoaderKFList::QueueKFPathsFromList(BSSimpleList<const char*>* apNames, KFQueueOwner* owner, int priority,
                                             void* queued, const char* prefix)
{
    BSSimpleList<const char*>* iter = apNames;
    int index = 0;
    while (iter)
    {
        const char* name = iter->GetItem();
        if (name)
        {
            char path[260];
            if (prefix)
            {
                ModelLoaderStrcpyS(path, 260, prefix);
                ModelLoaderStrcatS(path, 260, name);
                name = path;
            }
            if (owner)
            {
                QueueKFPath(name, owner->MakeTask(index), priority, queued, 0, 1, 0, 0);
            }
            else
            {
                QueueKFPathDirect(name, priority, queued, 0, 1, 0, 0);
            }
        }
        index++;
        iter = iter->GetNext();
    }
}

struct IndexedValueTable
{
    unsigned int count;
    unsigned int* values;
    unsigned int GetValueAt(unsigned int index);
};

// Returns values[index] when index is below count, otherwise returns 0.
// @fnv 0x004464c0
unsigned int IndexedValueTable::GetValueAt(unsigned int index)
{
    return index < count ? values[index] : 0;
}

class FUN_004469c0_base
{
  public:
    FUN_004469c0_base(unsigned int);
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    unsigned int unk04[9];
};

class FUN_004469c0 : public FUN_004469c0_base
{
  public:
    FUN_004469c0(unsigned int a, unsigned int b);
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
};

// Constructs the object, forwarding b to the base constructor and initializing m_28 with a while zeroing m_2c and m_30.
// @fnv 0x004469c0
FUN_004469c0::FUN_004469c0(unsigned int auiValue, unsigned int auiBaseArg) : FUN_004469c0_base(auiBaseArg)
{
    m_28 = auiValue;
    m_2c = 0;
    m_30 = 0;
}

class FUN_00448330_Target
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual unsigned char vfn_10(unsigned int a1, unsigned int* pa2, bool flag);
};

class FUN_00448330_cls
{
  public:
    unsigned int unk00[9];
    FUN_00448330_Target* m_pFlagTarget;
    unsigned char DispatchVirtualCall(unsigned int a1, unsigned int a2);
};

// @fnv 0x00448330
unsigned char FUN_00448330_cls::DispatchVirtualCall(unsigned int auiArg, unsigned int a2)
{
    unsigned char r = m_pFlagTarget->vfn_10(auiArg, &a2, false);
    return r;
}

class FUN_004483a0_holder
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual bool vfn_08(unsigned int arg, unsigned int* out);
};

class FUN_004483a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    FUN_004483a0_holder* m_pHolder;
    unsigned int GetHolderValue(unsigned int arg);
};

// Calls m_pHolder->vfn_08 with arg and an output slot, returning the output value if it succeeds, otherwise 0.
// @fnv 0x004483a0
unsigned int FUN_004483a0_cls::GetHolderValue(unsigned int arg)
{
    unsigned int out = 0;
    if (m_pHolder->vfn_08(arg, &out))
    {
        return out;
    }
    return 0;
}

struct B449Entry
{
    bool InvokeWithArgs();
};

class B449Map
{
  public:
    B449Entry* LockFreeMap_GetInterface_0(void* pKey, int iIndex);
    bool UpdateState_004498b0(void* pKey, int iIndex);
};

// Looks up the entry for pKey and iIndex and returns the result of its InvokeWithArgs check.
// @fnv 0x004498b0
// src: GUESS 0x004498b0 (confidence: low)
bool B449Map::UpdateState_004498b0(void* pKey, int iIndex)
{
    bool bResult = LockFreeMap_GetInterface_0(pKey, iIndex)->InvokeWithArgs();
    return bResult;
}

void BSTaskThread_SetPauseSleepEnabled(unsigned char value);
void __cdecl BSSleep(unsigned long);

struct QueuedTask
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Run(int eState, int arg);
    int unk04;
    int unk08;
    int eState;
    bool SetState(int eCurrentState, int eNewState);
    void Model_IncManualRefCount();
    void BSTask_int64_DecRefCount();
};

struct TaskProcessor
{
    void BSTaskManager_int64_RemoveTask(void* pTask);
    void BSTaskManager_CancelTask(QueuedTask* pTask, int arg);
};

// @fnv 0x0044ac40
// src: COMMUNITY 0x0044ac40
void TaskProcessor::BSTaskManager_CancelTask(QueuedTask* pTask, int arg)
{
    BSTaskThread_SetPauseSleepEnabled(0);
    while (true)
    {
        int eState = pTask->eState;
        switch (eState)
        {
        case 0:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, arg);
                return;
            }
            break;
        case 1:
            if (pTask->SetState(eState, 6))
            {
                pTask->Model_IncManualRefCount();
                BSTaskManager_int64_RemoveTask(pTask);
                pTask->Run(eState, arg);
                pTask->BSTask_int64_DecRefCount();
                return;
            }
            break;
        case 2:
            while (pTask->eState == 3)
            {
                BSSleep(0);
            }
            break;
        case 3:
            while (pTask->eState == 3)
            {
                BSSleep(0);
            }
            break;
        case 4:
            while (pTask->eState == 4)
            {
                BSSleep(0);
            }
            break;
        case 5:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, arg);
                return;
            }
            break;
            return;
        default:
            return;
        }
    }
}

struct Entry44
{
    int unk00;
    int unk04;
    long unk08;
};

struct Slot44
{
    int m_val;
    int GetHead();
    Entry44* GetEntry();
};

struct TP44
{
    int m_p;
    TP44(bool b, int p);
    operator long() const;
};

bool __cdecl CompareAndSwapEx(long volatile* param_1, long param_2, long param_3);

struct Obj44
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    long volatile* unk10;
    Slot44 unk14;
    Slot44 unk18;
    bool TryInsert(int a, int b);
    void Finish(int p);
    void Release();
    bool TryInsertAndFinish(int a, int b);
};

// Loops calling TryInsert, compares entries via FUN_004491c0, calls Finish or TryInsert again, then Release and returns whether it succeeded.
// @fnv 0x0044d3f0
bool Obj44::TryInsertAndFinish(int aiFirst, int aiSecond)
{
    bool result2 = false;
    while (1)
    {
        if (!TryInsert(aiFirst, aiSecond))
        {
            result2 = false;
            break;
        }
        TP44 first2(false, unk18.GetHead());
        TP44 second(true, unk18.GetHead());
        if (!CompareAndSwapEx(&unk14.GetEntry()->unk08, second, first2))
            continue;
        TP44 third(false, unk14.GetHead());
        if (CompareAndSwapEx(unk10, first2, third))
            Finish(unk14.GetHead());
        else
            TryInsert(aiFirst, aiSecond);
        result2 = true;
        break;
    }
    Release();
    return result2;
}

class FUN_0044df40_PtrHolder
{
  public:
    unsigned int m_00;
    FUN_0044df40_PtrHolder(unsigned int init);
    ~FUN_0044df40_PtrHolder();
    void Assign(const void* p);
};

class FUN_0044df40_Plain
{
  public:
    FUN_0044df40_Plain();
};

class FUN_0044df40_cls
{
  public:
    unsigned int m_00;
    FUN_0044df40_PtrHolder m_04;
    FUN_0044df40_Plain m_08;
    FUN_0044df40_cls(unsigned int a1, const void* a2);
};

// @fnv 0x0044df40
FUN_0044df40_cls::FUN_0044df40_cls(unsigned int uiValue, const void* pPointer) : m_04(0), m_08()
{
    m_00 = uiValue;
    m_04.Assign(pPointer);
}

class LoaderNode;
class LoaderEntryA;
class LoaderEntryB;

extern unsigned char DAT_011f36bc;
extern unsigned char DAT_011f36e4;

void* __cdecl NiObject_DynamicCast(void* key, LoaderNode* node);

class LoaderEntryA
{
  public:
    void Method(unsigned int flags);
};

class LoaderEntryB
{
  public:
    void Method(unsigned int flags);
};

class LoaderNode
{
  public:
    LoaderNode* Next();
};

class FUN_004f05c0_cls
{
  public:
    LoaderNode* First();
    void ApplyFlagsToEntries(unsigned int flags);
};

// Iterates the node list from First(), looks up two entries per node via FUN_00653270 and calls Method(flags) on each non-null entry.
// @fnv 0x004f05c0
void FUN_004f05c0_cls::ApplyFlagsToEntries(unsigned int flags)
{
    for (LoaderNode* node = First(); node != 0; node = node->Next())
    {
        LoaderEntryA* a = (LoaderEntryA*)NiObject_DynamicCast(&DAT_011f36bc, node);
        LoaderEntryB* b = (LoaderEntryB*)NiObject_DynamicCast(&DAT_011f36e4, node);
        if (a != 0)
        {
            a->Method(flags);
        }
        if (b != 0)
        {
            b->Method(flags);
        }
    }
}

class QueueCursor
{
  public:
    QueueCursor();
    ~QueueCursor();
    bool AtEnd();
    void* m_pCurrent;
};

class QueueSlot
{
  public:
    QueueSlot(int flag);
    ~QueueSlot();
    void* Take(int which);
    void* m_pInventoryEntryData;
};

class QueueSubmitter
{
  public:
    void Submit(void* item);
};

class FUN_00527fc0_cls
{
  public:
    bool Step(QueueCursor* cursor, int* index, QueueSlot* slot, int mode);
    void SubmitQueuedItems();
};

// Iterates the cursor until it reaches the end, calling Step on each slot and submitting the taken item through the submitter at DAT_01202d98 when Step succeeds.
// @fnv 0x00527fc0
void FUN_00527fc0_cls::SubmitQueuedItems()
{
    unsigned int pad[3];
    {
        QueueCursor cursor;
        while (!cursor.AtEnd())
        {
            int index = 0;
            QueueSlot slot7(0);
            if (this->Step(&cursor, &index, &slot7, 1))
            {
                reinterpret_cast<QueueSubmitter*>(DAT_01202d98)->Submit(slot7.Take(0));
            }
        }
    }
}

class AC_00528080_obj;

unsigned int __cdecl PackShortPair(unsigned short, unsigned short);

class SaveLoadCallLocal
{
  public:
    AC_00528080_obj* m_pObject;
    SaveLoadCallLocal(AC_00528080_obj* pObject);
    ~SaveLoadCallLocal();
};

class SaveLoadCallerShell
{
  public:
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int handle, SaveLoadCallLocal* pLocal);
    bool CallSaveLoadWithHandle(unsigned short a, unsigned short b);
};

// Computes a handle from two 16-bit values, wraps a null object in a local, and passes both to the virtual v2 call.
// @fnv 0x00528080
bool SaveLoadCallerShell::CallSaveLoadWithHandle(unsigned short ausValue1, unsigned short ausValue2)
{
    unsigned int handle = PackShortPair(ausValue1, ausValue2);
    SaveLoadCallLocal local(0);
    return this->v2(handle, &local);
}

class FUN_00529000_cls
{
  public:
    void* unk00;
    unsigned int* m_04;
    unsigned int* m_08;
    unsigned int* m_0C;
    void LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
};

// Sets the three unsigned int values pointed to by m_04, m_08 and m_0C to zero.
// @fnv 0x00529000
// src: COMMUNITY 0x00529000
void FUN_00529000_cls::LockFreeMap_LockFreeMapInterface_ClearReferencedNodes()
{
    *m_04 = 0;
    *m_08 = 0;
    *m_0C = 0;
}

struct Z_00626c50
{
    void bhkWorldObject_GetCollisionFilter();
};

struct Y_00626c50
{
    void bhkWorldObject_SetCollisionFilter();
};

struct Mgr_00626c50
{
    unsigned int unk00;
    unsigned int unk04;
    void* Modelloader_GetReferencedThis(unsigned int key);
};

struct Local_00626c50
{
    unsigned int v;
    void CFilter_SetGroup(unsigned int a);
};

struct FUN_00626c50_cls
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    Mgr_00626c50 m_3a0;
    unsigned int m_3a8;
    void HitCaster_SetShapeGroup(unsigned int a1);
};

// Stores a1 in m_3a8, passes it to local.FUN_0059ce80, and calls FUN_0043b4f0/FUN_00626cb0 on objects obtained from m_3a0.FUN_00559450.
// @fnv 0x00626c50
// src: XBOX_PDB 0x00626c50
void FUN_00626c50_cls::HitCaster_SetShapeGroup(unsigned int auiValue)
{
    Local_00626c50 local;
    reinterpret_cast<Z_00626c50*>(m_3a0.Modelloader_GetReferencedThis((unsigned int)&local))->bhkWorldObject_GetCollisionFilter();
    local.CFilter_SetGroup(auiValue);
    m_3a8 = auiValue;
    reinterpret_cast<Y_00626c50*>(m_3a0.Modelloader_GetReferencedThis(local.v))->bhkWorldObject_SetCollisionFilter();
}

class C1C50Filter
{
  public:
    C1C50Filter();

    void SetLayer(unsigned int uiLayer);

    unsigned int m_uiFilterInfo;
};

class C1C50HkObject
{
  public:
    C1C50Filter GetFilter();
    void SetFilter(C1C50Filter kFilter);
};

class C1C50WorldObject
{
  public:
    C1C50HkObject* GetHkObject();
    void ViewCaster_SetShapeGroup(unsigned int uiLayer);

    int unk00;
    int unk04;
    unsigned int m_uiLayer;
};

// Sets the layer on the filter obtained from GetHkObject, stores it in m_uiLayer, and writes the filter back.
// @fnv 0x00631c50
// src: XBOX_PDB 0x00631c50
void C1C50WorldObject::ViewCaster_SetShapeGroup(unsigned int uiLayer)
{
    C1C50Filter kFilter = GetHkObject()->GetFilter();
    kFilter.SetLayer(uiLayer);
    m_uiLayer = uiLayer;
    GetHkObject()->SetFilter(kFilter);
}

struct QueryResult
{
    void __thiscall FUN_006147e0();
    void __thiscall BuildBodyModTexturePath();
};
struct QueryObject
{
    QueryResult* __thiscall TESNPC_GetRace(QueryObject*, char*);
    QueryResult* __thiscall TESNPC_GetRace(QueryObject*, char*, char*);
};
extern "C" void __cdecl BSTexturePalette_RemoveTexture_0(char*);
// @fnv 0x006570e0
// src: COMMUNITY 0x006570e0
void __cdecl BSFaceGenManager_ClearBodyTexturesFromPalette(QueryObject* apQueryObject)
{
    char firstPath[264];
    char secondPath[264];
    apQueryObject->TESNPC_GetRace(apQueryObject, secondPath)->FUN_006147e0();
    apQueryObject->TESNPC_GetRace(apQueryObject, secondPath, firstPath)->BuildBodyModTexturePath();
    BSTexturePalette_RemoveTexture_0(firstPath);
}

struct SyncNode
{
    int unk00;
    int unk04;
    int state;
};
struct NodeLink
{
    SyncNode* value;
    SyncNode* ClearLowBit();
    SyncNode* ClearLowBit_Thunk();
};
struct StateValue
{
    int value;
    void SetTaggedPointer(bool, SyncNode*);
    int Modelloader_GetReferencedThis();
};
struct Controller
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
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
    virtual void Update();
};
struct Worker
{
    Controller* controller;
    int unk04;
    int unk08;
    int unk0c;
    int* state;
    NodeLink current;
    NodeLink pending;
    bool ProcessNodeChain(int, int);
    void AddRace(SyncNode*);
    void LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
    bool AdvanceState(int, int);
};
bool __cdecl CompareAndSwapEx(int*, int, int);
// Loops while ProcessNodeChain holds, compares pending/current state values via FUN_004491c0, updates the controller and returns whether a step succeeded.
// @fnv 0x00666080
bool Worker::AdvanceState(int aiArg1, int aiArg2)
{
    bool result = false;
    while (true)
    {
        if (!ProcessNodeChain(aiArg1, aiArg2))
        {
            result = false;
            break;
        }
        StateValue after;
        after.SetTaggedPointer(false, pending.ClearLowBit());
        StateValue now;
        now.SetTaggedPointer(true, pending.ClearLowBit());
        if (!CompareAndSwapEx(&current.ClearLowBit_Thunk()->state, now.Modelloader_GetReferencedThis(), after.Modelloader_GetReferencedThis()))
            continue;
        StateValue before;
        before.SetTaggedPointer(false, current.ClearLowBit());
        if (CompareAndSwapEx(state, after.Modelloader_GetReferencedThis(), before.Modelloader_GetReferencedThis()))
            AddRace(current.ClearLowBit());
        else
            ProcessNodeChain(aiArg1, aiArg2);
        controller->Update();
        result = true;
        break;
    }
    LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
    return result;
}

struct FUN_006ec830_target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int Call(int a, int b, int c);
};

struct FUN_006ec830_cls
{
    FUN_006ec830_target* m_00;
    int UpdateState_006ec9b0(int p);
    int InvokeWithArgs(int a1, int a2);
};

// Calls the virtual Call method on m_00 with a1 twice and a2, then passes the result to FUN_006ec9b0 and returns it.
// @fnv 0x006ec830
int FUN_006ec830_cls::InvokeWithArgs(int aiArg1, int aiArg2)
{
    return UpdateState_006ec9b0(m_00->Call(aiArg1, aiArg1, aiArg2));
}

namespace fnv_00906af0 {
struct QH_0092c820
{
    void BSTask_int64_DecRefCount();
    void Model_IncManualRefCount();
};

void ProgramFlow();

struct IntegerMapEntry
{
    int key;
    NP value;
    bool IsOccupied();
};

struct TaggedEntry
{
    int m_bits;
    int GetPixelBitData();
    int Raw() const;
    IntegerMapEntry* GetEntry();
};

struct EntryRef
{
    int m_uiFilterValue;
    int Get() const;
};

struct LocalRef
{
    void* m_p;
    void* Init(bool b, void* p);
    int Get() const;
};

struct QueueOwner
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
    virtual void Process(int key, int arg);
    TaggedEntry* Lookup(int index);
};

struct QueueWalker
{
    QueueOwner* m_pOwnerObject;
    int unk04;
    int* m_out;
    int unk0c;
    TaggedEntry* m_ref;
    TaggedEntry m_entry;
    void Finish();
    bool ProcessEntry(int index, int arg, NP* dest);
};

// @fnv 0x00906af0
bool QueueWalker::ProcessEntry(int index, int arg, NP* dest)
{
    bool result = false;
    while (1)
    {
        LocalRef local;
        TaggedEntry* entry = m_pOwnerObject->Lookup(index);
        m_ref = entry;
        m_entry = *m_ref;
        *m_out = m_entry.GetPixelBitData();
        ProgramFlow();
        local.Init(false, (void*)m_entry.GetPixelBitData());
        if (m_ref->Raw() != local.Get())
            continue;
        if (!m_entry.GetPixelBitData())
        {
            result = false;
            break;
        }
        m_pOwnerObject->Process(m_entry.GetEntry()->key, arg);
        dest->operator=(m_entry.GetEntry()->value);
        result = true;
        ProgramFlow();
        if (m_entry.GetEntry()->IsOccupied())
            continue;
        break;
    }
    Finish();
    return result;
}
}  // namespace fnv_00906af0

extern "C" int __cdecl FUN_00aa1a20(unsigned int, unsigned int, unsigned int);
extern "C" void __cdecl NormalizePathSeparators(void*);
extern "C" void __cdecl FUN_00ec65a6(void*, unsigned int, unsigned int);

class SpawnedObject
{
  public:
    virtual int vfn_00(int);
};

// @fnv 0x00c3a8a0
// src: XBOX_PDB 0x00c3a8a0
bool NiStream::BSStream_Load(const char* a1, BSFile* a2)
{
    if (a2 == 0)
    {
        a2 = (BSFile*)FUN_00aa1a20((unsigned int)a1, 0, 0x2800);
    }
    bool result = false;
    if (a2 != 0)
    {
        void* e = m_acFileName;
        FUN_00ec65a6(e, 0x104, (unsigned int)a1);
        NormalizePathSeparators(m_acFileName);
        result = NiStream::Load((NiBinaryStream*)a2);
        SpawnedObject* p1 = (SpawnedObject*)a2;
        SpawnedObject* p2 = p1;
        (p2 != 0) ? p2->vfn_00(1) : 0;
    }
    return result;
}

// FUN_0043ace0 worker2 a2run3 A1: NiSortAdjustNode drop m_a8 (pack NiMemObject is 1B, +4 align -> 42 fields = 0xac alloc like ORIG)
int __cdecl BSstrlen(const char*);
void* __cdecl FormHeap_Allocate(unsigned int);
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
void __fastcall BSStream_FreeAllObjects(void*);
void* __fastcall FUN_00413f40(void*);
void* __fastcall FUN_0043b1b0(void*);
bool __cdecl WildCard_Match(int, const char*);
void* __cdecl Object_DispatchCommandFour(unsigned int);
void __cdecl FUN_004b5d10(void*);
void* __fastcall NiObjectNET_GetControllers(void*);
void* __cdecl NiObject_DynamicCast(void*, void*);
void* __fastcall GetStringAtOffset(void*);
void __cdecl MessageHandler_IncDisableWarningCount(bool);
unsigned int __cdecl NiZBufferProperty_GetType();
void* __cdecl NiZBufferProperty_GetDefault();
unsigned int __cdecl NiVertexColorProperty_GetType();
void* __cdecl NiVertexColorProperty_GetDefault();
int __cdecl Warning_005b5e40(const char*, ...);
bool __cdecl HasMorpherController(void*);
void __cdecl FUN_00b57e30(void*, unsigned char, unsigned char);
extern char DAT_0101667c[];
extern char DAT_0101666c[];
extern char DAT_01016618[];
extern char DAT_010165c8[];
extern unsigned char DAT_01185520;
extern int DAT_011f36ac;

struct SubRef
{
    void FUN_0066b0d0(void*);
};
struct SortObj
{
    SortObj* FUN_00a5ecb0(unsigned int);
};

struct PropObj
{
    void* FUN_00a59d30(unsigned int);
    void NiAVObject_RemoveProperty(unsigned int);
};
struct Cls260
{
    bool NiZBufferProperty_IsEqualFast(unsigned short*);
};
struct ElemV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual int v0c();
    virtual void d04();
    virtual void d05();
    virtual int v18();
};
struct Arg1V
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual bool v60(const char*, int);
};
struct BigV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void vF8(int, void*);
};
struct CtrlV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void v90(void*, int);
};
struct ThisS
{
    char* m_buf;
    int m_04;
    int m_08;
    SubRef m_sub;
    void Model_InitModel(const char* a0, BSStream* a1, unsigned char a2, unsigned char a3);
};

// Copies a0 into m_buf, builds m_sub from a1's elements (wrapping in a NiSortAdjustNode when needed), and applies property/control updates.
// @fnv 0x0043ace0
// src: XBOX_PDB 0x0043ace0
void ThisS::Model_InitModel(const char* apName, BSStream* apSource, unsigned char a2, unsigned char a3)
{
    bool q;
    {
        unsigned long count;
        {
            ElemV* elem;
            {
                void* x1;
                {
                    int iDynIndex;
                    {
                        int iElemIndex;
                        {
                            ElemV* pForm;
                            {
                                bool flagB;
                                {
                                    void* tmp;
                                    {
                                        void* z;
                                        {
                                            void* ctrlObj;
                                            {
                                                void* prop;
                                                {
                                                    void* pPropA;
                                                    {
                                                        void* pPropB;
                                                        {
                                                            bool flagC;
                                                            {
                                                                char* c;
                                                                {
                                                                    m_04 = 0;
                                                                    m_08 = 0;
                                                                    count = BSstrlen(apName) + 1;
                                                                    c = (char*)FormHeap_Allocate(count);
                                                                    m_buf = c;
                                                                    FUN_00406d30(m_buf, count, apName);
                                                                    if (apSource->GetRefAt21C() == 0)
                                                                    {
                                                                        BSStream_FreeAllObjects(apSource);
                                                                        if (!((Arg1V*)apSource)->v60(DAT_0101667c, 0))
                                                                        {
                                                                            m_buf = 0;
                                                                            return;
                                                                        }
                                                                    }
                                                                    elem = (ElemV*)apSource->GetStringAt(0);
                                                                    q = false;
                                                                    if (elem != 0 && elem->v0c() != 0)
                                                                    {
                                                                        x1 = FUN_0043b1b0(FUN_00413f40(elem));
                                                                        if (x1 != 0 &&
                                                                            WildCard_Match((int)x1, DAT_0101666c))
                                                                        {
                                                                            m_sub.FUN_0066b0d0(
                                                                                (SortObj*)new NiSortAdjustNode(0));
                                                                            ((BigV*)Modelloader_GetReferencedThis((int*)&m_sub))
                                                                                ->vF8(0, elem);
                                                                        }
                                                                        else
                                                                        {
                                                                            m_sub.FUN_0066b0d0(elem);
                                                                        }
                                                                        q = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        iDynIndex = 0;
                                                                        for (iElemIndex = 0;
                                                                             iElemIndex < (unsigned int)apSource->GetRefAt21C();
                                                                             ++iElemIndex)
                                                                        {
                                                                            elem = (ElemV*)apSource->GetStringAt(
                                                                                iElemIndex);
                                                                            if (elem != 0)
                                                                            {
                                                                                if (elem->v0c() != 0 ||
                                                                                    elem->v18() != 0)
                                                                                {
                                                                                    pForm = elem;
                                                                                    if (Modelloader_GetReferencedThis((int*)&m_sub) == 0)
                                                                                    {
                                                                                        m_sub.FUN_0066b0d0(
                                                                                            (SortObj*)new NiSortAdjustNode(
                                                                                                0));
                                                                                    }
                                                                                    ((BigV*)Modelloader_GetReferencedThis((int*)&m_sub))
                                                                                        ->vF8(iDynIndex++, pForm);
                                                                                    q = true;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    if (q)
                                                                    {
                                                                        FUN_004b5d10((void*)Modelloader_GetReferencedThis((int*)&m_sub));
                                                                        if (DAT_01185520)
                                                                        {
                                                                            z = NiObjectNET_GetControllers(
                                                                                (void*)Modelloader_GetReferencedThis((int*)&m_sub));
                                                                            ctrlObj = NiObject_DynamicCast(&DAT_011f36ac, z);
                                                                            if (ctrlObj != 0)
                                                                            {
                                                                                prop = GetStringAtOffset(ctrlObj);
                                                                                if (prop != 0)
                                                                                {
                                                                                    if (FUN_0043b1b0(FUN_00413f40(
                                                                                            (void*)Modelloader_GetReferencedThis(
                                                                                                (int*)&m_sub))) != 0)
                                                                                    {
                                                                                        ((CtrlV*)prop)
                                                                                            ->v90(
                                                                                                FUN_00413f40(
                                                                                                    (void*)Modelloader_GetReferencedThis(
                                                                                                        (int*)&m_sub)),
                                                                                                0);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                        flagB = false;
                                                                        MessageHandler_IncDisableWarningCount(true);
                                                                        tmp = ((PropObj*)Modelloader_GetReferencedThis((int*)&m_sub))
                                                                                  ->FUN_00a59d30(NiZBufferProperty_GetType());
                                                                        if (tmp != 0)
                                                                        {
                                                                            pPropA = tmp;
                                                                            if (((Cls260*)pPropA)
                                                                                    ->NiZBufferProperty_IsEqualFast((
                                                                                        unsigned short*)NiZBufferProperty_GetDefault()))
                                                                            {
                                                                                ((PropObj*)Modelloader_GetReferencedThis((int*)&m_sub))
                                                                                    ->NiAVObject_RemoveProperty(NiZBufferProperty_GetType());
                                                                                flagB = true;
                                                                            }
                                                                        }
                                                                        tmp = ((PropObj*)Modelloader_GetReferencedThis((int*)&m_sub))
                                                                                  ->FUN_00a59d30(NiVertexColorProperty_GetType());
                                                                        if (0 != tmp)
                                                                        {
                                                                            pPropB = tmp;
                                                                            if (((Cls260*)pPropB)
                                                                                    ->NiZBufferProperty_IsEqualFast((
                                                                                        unsigned short*)NiVertexColorProperty_GetDefault()))
                                                                            {
                                                                                ((PropObj*)Modelloader_GetReferencedThis((int*)&m_sub))
                                                                                    ->NiAVObject_RemoveProperty(NiVertexColorProperty_GetType());
                                                                                flagB = true;
                                                                            }
                                                                        }
                                                                        if (flagB)
                                                                        {
                                                                            if (((char*)apSource)[8])
                                                                            {
                                                                                Warning_005b5e40(DAT_01016618,
                                                                                             (char*)apSource + 8,
                                                                                             apName);
                                                                            }
                                                                            else
                                                                            {
                                                                                Warning_005b5e40(DAT_010165c8, apName);
                                                                            }
                                                                        }
                                                                        MessageHandler_IncDisableWarningCount(false);
                                                                        if (a2)
                                                                        {
                                                                            flagC = false;
                                                                            if (a3 || HasMorpherController((void*)Modelloader_GetReferencedThis(
                                                                                          (int*)&m_sub)))
                                                                            {
                                                                                flagC = true;
                                                                            }
                                                                            FUN_00b57e30(
                                                                                (void*)Modelloader_GetReferencedThis((int*)&m_sub), a3,
                                                                                flagC);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern int DAT_010169d4;

struct FUN_0043d8f0_Class : public FUN_0043c830
{
    void SetVtableAndProcessState_0043d8f0();
};

// @fnv 0x0043d8f0
// src: GUESS 0x0043d8f0 (confidence: low)
void FUN_0043d8f0_Class::SetVtableAndProcessState_0043d8f0()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010169d4);
    this->FUN_0043c830::~FUN_0043c830();
}

namespace ModelResources {
struct Main;
struct Form;
struct Entry;
struct Model
{
    unsigned int value;
    unsigned int FUN_0048cee0();
};
struct Prefix18
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
};
struct Source : Prefix18, Model
{
    bool FUN_00408a20();
    void FUN_00408970();
};
struct Link
{
    unsigned int value;
    bool FUN_008256d0();
    Entry** FUN_006815c0();
    Link* FUN_00726070();
};
struct Prefix4
{
    unsigned int value;
};
struct Iterator : Prefix4, Link
{
};
struct PrefixC
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};
struct ListOwner : PrefixC, Iterator
{
};
struct List
{
    void FUN_00470470();
    ~List();
};
struct Form
{
    int FUN_00401170();
};
struct WeaponPrefix : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
};
struct Weapon : WeaponPrefix, Model
{
};
struct ModelPair
{
    Model* GetBipedModel(int);
};
struct Armor : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    ModelPair models;
};
struct Misc : Form
{
    List* CollectModelPaths(int, int);
};

struct Reference
{
    bool IsArchetypeFlagSet();
    bool FUN_004088a0();
    Form* FUN_005f5f80();
    bool IsFlagSet_00403e60(unsigned int);
    bool FUN_00408880();
    void FUN_00408790();
};
struct Entry
{
    Reference* FUN_00825c00();
};
struct Manager
{
    void ModelLoader_QueueModel(Model*, void*, Main*, void*, int, int, int);
    void QueueKFPathsFromList(List*, int, void*, Main*, int);
    void QueueModelAnimations(Model*, void*, Main*, int, int, int);
};
extern Manager* DAT_011c3b3c;
void* TES_GetLODMult(Form*);
void MagicItem_IncrementGlobalCounter();
struct Main
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
    virtual void Complete();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    ListOwner* owner;
    Source* source;
    void* IOTask_GetIOTaskPriority();
    void SetFieldCToFive();
    void UpdateModels();
};
// Loads the source model if needed, then walks the owner's entries and dispatches weapon, armor, misc and creature models to the manager before completing.
// @fnv 0x0043dc70
void Main::UpdateModels()
{
    bool loaded = false;
    if (source->FUN_0048cee0() > 0 && !source->FUN_00408a20())
    {
        DAT_011c3b3c->ModelLoader_QueueModel(static_cast<Model*>(source), IOTask_GetIOTaskPriority(), this, 0, 1, 0, 0);
        loaded = true;
    }
    source->FUN_00408970();
    Iterator* iterator = static_cast<Iterator*>(owner);
    if (!iterator->FUN_008256d0())
        while (iterator)
        {
            Entry* entry = *iterator->FUN_006815c0();
            Reference* reference = entry->FUN_00825c00();
            if (reference->IsArchetypeFlagSet() && (!loaded || !reference->FUN_004088a0()))
            {
                Form* form = reference->FUN_005f5f80();
                if (form)
                {
                    if (reference->IsFlagSet_00403e60(0x10000))
                    {
                        if (form->FUN_00401170() == 40)
                        {
                            Weapon* weapon = (Weapon*)form;
                            if (weapon->FUN_0048cee0() > 0)
                                DAT_011c3b3c->ModelLoader_QueueModel(static_cast<Model*>(weapon), IOTask_GetIOTaskPriority(), this,
                                                           TES_GetLODMult(weapon), 1, 0, 0);
                        }
                    }
                    else if (reference->IsFlagSet_00403e60(0x20000))
                    {
                        if (form->FUN_00401170() == 24)
                        {
                            Armor* armor = (Armor*)form;
                            DAT_011c3b3c->ModelLoader_QueueModel(armor->models.GetBipedModel(0), IOTask_GetIOTaskPriority(), this,
                                                       TES_GetLODMult(armor), 1, 0, 0);
                            DAT_011c3b3c->ModelLoader_QueueModel(armor->models.GetBipedModel(1), IOTask_GetIOTaskPriority(), this,
                                                       TES_GetLODMult(armor), 1, 0, 0);
                        }
                    }
                    else if (reference->IsFlagSet_00403e60(0x40000))
                    {
                        if (form->FUN_00401170() == 42)
                        {
                            Misc* miscSlot0 = (Misc*)form;
                            List* listSlot0 = miscSlot0->CollectModelPaths(1, 1);
                            DAT_011c3b3c->QueueKFPathsFromList(listSlot0, 0, IOTask_GetIOTaskPriority(), this, 0);
                            listSlot0->FUN_00470470();
                            delete listSlot0;
                        }
                        else if (form->FUN_00401170() == 43)
                        {
                            TESCreature* creature = reinterpret_cast<TESCreature*>(form);
                            DAT_011c3b3c->QueueModelAnimations(reinterpret_cast<Model*>(static_cast<TESModel*>(creature)), IOTask_GetIOTaskPriority(), this, 0,
                                                               1, 1);
                            DAT_011c3b3c->ModelLoader_QueueModel(reinterpret_cast<Model*>(static_cast<TESModel*>(creature)), IOTask_GetIOTaskPriority(), this,
                                                       TES_GetLODMult(reinterpret_cast<Form*>(creature)), 1, 0, 0);
                        }
                    }
                }
                if (!reference->FUN_00408880() && !reference->FUN_004088a0() && reference->IsFlagSet_00403e60(0x40000))
                    MagicItem_IncrementGlobalCounter();
                reference->FUN_00408790();
            }
            iterator = static_cast<Iterator*>(iterator->FUN_00726070());
        }
    SetFieldCToFive();
    Complete();
}
}







// 0x0043e750 returns TESObjectANIO; its TESModel base is at 0x18.
class AnimData43E
{
  public:
    TESObjectANIO* ComputePositionAtTime(int iIndex);
};

class Handle43E
{
  public:
    AnimData43E* Get() const;

    AnimData43E* m_pPointer;
};

class Task43E;



extern ModelLoader* g_pkModelLoader43E;

class Task43E
{
  public:
    int GetPriority();
    void Finish();
    void LoadModelsAndFinish();

    void* m_ppVirtualMethodTable;
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
    Handle43E m_kData;
};

// @fnv 0x0043e690
void Task43E::LoadModelsAndFinish()
{
    if (m_kData.Get())
    {
        for (int i = 0; i < 2; i++)
        {
            if (m_kData.Get()->ComputePositionAtTime(i))
                g_pkModelLoader43E->ProcessModelRequest(m_kData.Get()->ComputePositionAtTime(i), GetPriority(), this, 2,
                                                        true, 0, 0);
        }
    }
    Finish();
}

struct FUN_0043e840_shell : public ModelLoader
{
    void QueuedFile_Cancel(int, int);
    void QueuedAnimIdle_Cancel(int param_2, int param_3);
};
// Calls FUN_00c3cb70 with the two arguments, then passes the queued file at this+0x3c to g_modelLoader->DispatchAnimIdle.
// @fnv 0x0043e840
// src: XBOX_PDB 0x0043e840
void FUN_0043e840_shell::QueuedAnimIdle_Cancel(int aiArg1, int aiArg2)
{
    QueuedFile_Cancel(aiArg1, aiArg2);
    g_modelLoader->DispatchAnimIdle((QueuedFile*)Modelloader_GetReferencedThis((int*)((char*)this + 0x3c)));
}

struct FUN_0043eac0_class
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

    void __thiscall QueuedFile_Cancel(int param_1, int param_2);
    void __thiscall ForwardToHolder(int param_1, int param_2);
};

extern Holder14* DAT_011c3b3c;

// Calls FUN_00c3cb70 with the two arguments, then calls ForwardToInner on DAT_011c3b3c passing unk28.
// @fnv 0x0043eac0
void __thiscall FUN_0043eac0_class::ForwardToHolder(int param_1, int param_2)
{
    QueuedFile_Cancel(param_1, param_2);
    DAT_011c3b3c->ForwardToInner(unk28);
}

namespace fnv_0043ed90 {
struct RefActor;
struct LoadedNode
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    RefActor* owner;
};
struct NodePointer
{
    LoadedNode* node;
    LoadedNode* Modelloader_GetReferencedThis();
};
struct AnimationManager
{
    void AttachHeadModels(RefActor*, int, LoadedNode*, LoadedNode*);
};
struct RefActor
{
    AnimationManager* BGSSaveFormBuffer_GetForm();
    const char* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
extern RefActor* DAT_011dea3c;
void __cdecl FUN_004b6dc0(LoadedNode*, const char*);
struct AttachTask
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
    NodePointer first;
    NodePointer second;
    void QueuedHead_Attach(RefActor* actor, int arg);
};
// @fnv 0x0043ed90
// src: XBOX_PDB 0x0043ed90
void AttachTask::QueuedHead_Attach(RefActor* actor, int arg)
{
    AutoMemContext manager((MEM_CONTEXT)0x37, true,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x613);
    AnimationManager* scope = actor->BGSSaveFormBuffer_GetForm();
    scope->AttachHeadModels(actor, arg, first.Modelloader_GetReferencedThis(), second.Modelloader_GetReferencedThis());
    if (actor != DAT_011dea3c)
    {
        FUN_004b6dc0(first.Modelloader_GetReferencedThis(), actor->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        if (second.Modelloader_GetReferencedThis())
            FUN_004b6dc0(second.Modelloader_GetReferencedThis(), actor->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
    }
    if (second.Modelloader_GetReferencedThis())
        second.Modelloader_GetReferencedThis()->owner = actor;
    if (first.Modelloader_GetReferencedThis())
        first.Modelloader_GetReferencedThis()->owner = actor;
}
}  // namespace fnv_0043ed90

struct SaveItem
{
    unsigned int unk00;
    unsigned int m_04;
};

struct SaveSub
{
    bool FUN_004ae8a0(int index);
    SaveItem* GetEntryAt(int index);
};

struct SaveHolder
{
    void LoadMesh(unsigned int value, int result, int owner, int flag);
};

extern QueueModelHolder* g_QueueHolder;

class FUN_0043f120_cls
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void OnChildCompletion();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    SaveSub* m_28;
    unsigned int m_2c[20];
    int IOTask_GetIOTaskPriority();
    void QueuedHelmet_SetFinishedQueuing(int flag);
    void QueuedHelmet_QueueMe();
};

// @fnv 0x0043f120
// src: XBOX_PDB 0x0043f120
void FUN_0043f120_cls::QueuedHelmet_QueueMe()
{
    for (int i = 0; i < 20; i++)
    {
        if (m_28->FUN_004ae8a0(i))
        {
            unsigned int v = m_28->GetEntryAt(i)->m_04;
            g_QueueHolder->ModelLoader_QueueModel_00443dc0(v, (QueueObj*)&m_2c[i], IOTask_GetIOTaskPriority(), (int)this, 3, true, true, true, 0.0f);
            reinterpret_cast<SaveHolder*>(g_QueueHolder)->LoadMesh(v, IOTask_GetIOTaskPriority(), (int)this, -1);
        }
    }
    QueuedHelmet_SetFinishedQueuing(1);
    OnChildCompletion();
}

struct FnvSceneNode
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual int vfn18();
    FnvSceneNode* NiTimeController_GetNext();
    FnvSceneNode* NiObjectNET_GetControllers();
    FnvSceneNode* NiGeometry_GetSkinInstance();
    FnvSceneNode* NiGeometry_GetModelData();
    FnvSceneNode* NiGeometry_GetModelData(void*);
    void FUN_00a5d510();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4c();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5c();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6c();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7c();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8c();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9c();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual void vfnD0();
    virtual void vfnD4();
    virtual void vfnD8();
    virtual void vfnDC();
    virtual void vfnE0();
    virtual void vfnE4(void*);
    void SetRotate_0043fa80(const NiMatrix3&);  // NiAVObject: set local rotation
    FnvSceneNode* NiAVObject_GetRotate_006a9540(void*, void*);
    bool ApplyMorphs(void*, FnvSceneNode*, int);
    void FUN_00603ad0(void*);
};
struct FnvRenderSelector
{
    FnvRenderSelector* BGSSaveFormBuffer_GetForm();
    int FUN_00401170();
    void FUN_00603ad0(void*);
};
struct FnvMaster
{
    FnvRenderSelector* FUN_0043f010();
    FnvSceneNode* NiTimeController_GetNext();
    FnvSceneNode* BipedAnim_LoadFaceGenModel(int);
    FnvSceneNode* LoadSlotObject();
};
struct FnvRefPtr
{
    FnvSceneNode* value;
    FnvSceneNode* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(FnvSceneNode*);
    void FUN_0066b0d0(FnvSceneNode*, FnvSceneNode*, FnvSceneNode*, int);
};
struct FnvList
{
    unsigned int FUN_0043b480();
    FnvSceneNode* FUN_0043b4a0(unsigned int);
};
struct FnvLink
{
    FnvSceneNode* NiObjectNET_GetControllers();
};
struct FnvGuard
{
    int lock;
    FnvGuard(int, bool, const char*, int);
    ~FnvGuard();
};
struct FnvHandle
{
    FnvSceneNode* object;
    FnvHandle(FnvSceneNode*);
    ~FnvHandle();
    FnvSceneNode* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(FnvSceneNode*);
};
struct FnvEntry
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18, field1c;
    FnvEntry();
    ~FnvEntry();
};
struct FnvGeometry
{
    const NiMatrix3& NiAVObject_GetRotate_006a9540();  // NiAVObject: local rotation (this+0x34)
};
extern "C" const char DAT_01016840[];
extern "C" float DAT_01016b78;

extern "C" void __cdecl FUN_00ec782f(FnvEntry*, unsigned, unsigned, void*, void*);
extern "C" void __cdecl FUN_00ec5fce(FnvEntry*, unsigned, unsigned, void*);

struct FnvQueueManager
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48(void*);
};

struct FnvRoot
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FnvMaster* master28;
    FnvRefPtr references[20];
    FnvRefPtr attachments[20];
    FnvRefPtr children[20];
    int p11c;
    bool QueuedHelmet_GetFinishedQueuing();
    bool QueuedFile_GetAllChildrenFinished();
    bool IsFieldCZero();
    void NotifyParents();
    bool BSTask_int64_GetTaskFinished();
    bool BSTask_int64_GetTaskCanceled();
    void QueuedHelmet_CheckFinished();
};

// @fnv 0x0043f2f0
// src: XBOX_PDB 0x0043f2f0
void FnvRoot::QueuedHelmet_CheckFinished()
{
    if (!QueuedHelmet_GetFinishedQueuing())
    {
        NotifyParents();
        return;
    }
    if (QueuedFile_GetAllChildrenFinished() && IsFieldCZero())
    {
        DAT_01202d98->AddTask(reinterpret_cast<QIOTask*>(this));
        return;
    }

    FnvGuard fileAccess(0x32, true, DAT_01016840, 0x690);
    {
        FnvHandle current(0);
        if (BSTask_int64_GetTaskFinished() && QueuedFile_GetAllChildrenFinished() && !BSTask_int64_GetTaskCanceled() && (void*)p11c != DAT_011dea3c)
        {
            for (int index = 0; index < 20; ++index)
            {
                if (references[index].Modelloader_GetReferencedThis() && references[index].Modelloader_GetReferencedThis()->NiTimeController_GetNext() &&
                    references[index].Modelloader_GetReferencedThis()->NiTimeController_GetNext()->NiObjectNET_GetControllers())
                {
                    children[index].FUN_0066b0d0(master28->LoadSlotObject(), attachments[index].Modelloader_GetReferencedThis(),
                                                 references[index].Modelloader_GetReferencedThis()->NiTimeController_GetNext()->NiObjectNET_GetControllers(),
                                                 index);
                    if (children[index].Modelloader_GetReferencedThis())
                    {
                        bool found = false;
                        for (unsigned int i = 0; i < ((FnvList*)children[index].Modelloader_GetReferencedThis())->FUN_0043b480(); ++i)
                        {
                            FnvSceneNode* linkedNode;
                            {
                                FnvSceneNode* node = ((FnvList*)children[index].Modelloader_GetReferencedThis())->FUN_0043b4a0(i);
                                if (!node || !node->vfn18())
                                    continue;
                                {
                                    FnvSceneNode* selectedNode = node;
                                    linkedNode = selectedNode->NiGeometry_GetSkinInstance();
                                    if (linkedNode)
                                    {
                                        found = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (!found)
                        {
                            FnvSceneNode* fallback = attachments[index].Modelloader_GetReferencedThis()
                                                         ? attachments[index].Modelloader_GetReferencedThis()
                                                         : master28->BipedAnim_LoadFaceGenModel(index);
                            if (fallback)
                            {
                                for (unsigned int j = 0; j < ((FnvList*)children[index].Modelloader_GetReferencedThis())->FUN_0043b480();
                                     ++j)
                                {
                                    FnvSceneNode* node = ((FnvList*)children[index].Modelloader_GetReferencedThis())->FUN_0043b4a0(j);
                                    {
                                        FnvSceneNode* geometry = node;
                                        if (geometry && geometry->NiGeometry_GetModelData() && master28->FUN_0043f010() &&
                                            master28->FUN_0043f010()->BGSSaveFormBuffer_GetForm() &&
                                            master28->FUN_0043f010()->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 42)
                                        {
                                            FnvRenderSelector* a = master28->FUN_0043f010()->BGSSaveFormBuffer_GetForm();
                                            FnvEntry p[4];   // Resource entries for the selected geometry.
                                            FnvHandle h(0);  // Retains the active scene object.
                                            geometry->NiGeometry_GetModelData(&current.object)->FUN_00a5d510();
                                            h.FUN_0066b0d0(current.Modelloader_GetReferencedThis());
                                            geometry->vfnE4(h.Modelloader_GetReferencedThis());
                                            a->FUN_00603ad0(p);
                                            if (!BSFaceGenManager_GetUseFaceGenHeads() || fallback->ApplyMorphs(p, geometry, 0))
                                            {
                                                NiMatrix3 matForward;
                                                matForward.MakeYRotation(DAT_01016b78);
                                                geometry->SetRotate_0043fa80(((FnvGeometry*)geometry)->NiAVObject_GetRotate_006a9540() * matForward);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        NotifyParents();
    }
}

struct AttachNode
{
    void NiAVObject_SetTranslate(const NiPoint3* pkPos);
    void SetRotate_0043fa80(const NiMatrix3& kRot);
    void NiAVObject_SetScale(float fScale);
};
struct ActorV_S
{
    float GetScale();
};

struct AttachRef
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual const NiPoint3* GetPos();
    NiMatrix3 TESObjectREFR_GetOrientation();
    void TESObjectREFR_Set3DSimple(AttachNode* pkNode);
    void TESObjectREFR_SetHasTemp3D(bool bArg);
};
struct OSGlobals;
extern OSGlobals* g_osGlobals;
unsigned int __fastcall TESMain_GetThread(OSGlobals* pkGlobals);
unsigned int gm_GetCurrentThreadId();
extern int g_TES;
struct AttachTES
{
    void TES_AttachModel(AttachRef* pkRef, int iCell, int a, int b);
};
struct AttachLoader
{
    void DispatchToQueue(QueuedFile* pkTask);
};
struct FUN_00440310_shell : QueuedReference
{
    AttachRef* m_pkRef;
    char pad2c[0xc];
    NiPointer<QueuedFile> m_spTask;
    void QueuedReference_AttachDistant3D(AttachNode* pkNode);
};
// @fnv 0x00440310
// src: XBOX_PDB 0x00440310
void FUN_00440310_shell::QueuedReference_AttachDistant3D(AttachNode* pkNode)
{
    pkNode->NiAVObject_SetTranslate(m_pkRef->GetPos());
    pkNode->SetRotate_0043fa80(m_pkRef->TESObjectREFR_GetOrientation());
    pkNode->NiAVObject_SetScale(((ActorV_S*)m_pkRef)->GetScale());
    if (TESMain_GetThread(g_osGlobals) == gm_GetCurrentThreadId())
    {
        m_pkRef->TESObjectREFR_Set3DSimple(pkNode);
        ((AttachTES*)g_TES)->TES_AttachModel(m_pkRef, ((BSOcclusionPlane*)m_pkRef)->GetCullResult(), 0, 0);
        m_pkRef->TESObjectREFR_SetHasTemp3D(true);
    }
    else
    {
        m_spTask = (QueuedFile*)new FUN_004404c0(m_pkRef, (int)pkNode);
        ((AttachLoader*)g_modelLoader)->DispatchToQueue(m_spTask);
    }
}

namespace fnv_004408f0 {
class SLNode;
class SLObj28
{
  public:
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
    virtual void v1cc(int, int);
    void Callee2(int);
    SLNode* Get();
    unsigned char Check2();
};

class SLNode
{
  public:
    void Callee3(int);
};

class SLHelper
{
  public:
    void Callee();
    void Callee4(SLObj28*);
};

extern SLHelper* DAT_011c3b3c;

class FUN_004408f0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    SLObj28* m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    void QueuedReference_Cancel(int a1, int a2);
    void Mid(int a1, int a2);
};

// @fnv 0x004408f0
// src: XBOX_PDB 0x004408f0
void FUN_004408f0_cls::QueuedReference_Cancel(int a1, int a2)
{
    if (Modelloader_GetReferencedThis((int*)&m_38) != 0)
    {
        ((SLHelper*)Modelloader_GetReferencedThis((int*)&m_38))->Callee();
    }
    Mid(a1, a2);
    if (Modelloader_GetReferencedThis((int*)&m_34) != 0)
    {
        m_28->Callee2(Modelloader_GetReferencedThis((int*)&m_34));
        ((SLNode*)&m_34)->Callee3(0);
        m_28->v1cc(0, 0);
    }
    DAT_011c3b3c->Callee4(m_28);
    if (m_28->Get() != 0)
    {
        FinishScriptRunLockAndReset((char*)m_28->Get());
        if (m_28->Check2())
        {
            FinishScriptRun((char*)m_28->Get());
        }
    }
}
}  // namespace fnv_004408f0

class B440ED0Form;

class B440ED0Reference
{
  public:
    B440ED0Form* GetObjectReference();
    bool TESObjectREFR_GetVisibleDistant();
    bool TESObjectREFR_GetIsImposter();
};

int __cdecl TES_GetLODMult(B440ED0Form* pkForm);

class B440ED0Task;

class B440ED0ModelLoader
{
  public:
    void DispatchWithScope(B440ED0Reference* pkReference, B440ED0Form* pkForm, int ePriority, B440ED0Task* pkTask,
                           int iType);
};

extern B440ED0ModelLoader* g_pkB440ED0ModelLoader;

class B440ED0Task
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_iMemContext;
    int unk1C;
    int unk20;
    int unk24;
    B440ED0Reference* m_pkReference;

    int GetPriority();
    void QueuedTree_QueueModels();
};

// Resolves the task's reference to a form, derives a load type from it, and submits the reference to the model loader with the task's priority.
// @fnv 0x00440ed0
// src: XBOX_PDB 0x00440ed0
void B440ED0Task::QueuedTree_QueueModels()
{
    AutoMemHelper kMemHelper8(m_iMemContext, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x847);
    B440ED0Form* pkObject = m_pkReference->GetObjectReference();
    B440ED0Form* pkForm = pkObject;
    int iType = TES_GetLODMult(pkObject);
    if (m_pkReference && m_pkReference->TESObjectREFR_GetVisibleDistant())
        iType = 6;
    if (m_pkReference && m_pkReference->TESObjectREFR_GetIsImposter())
        iType = 10;
    g_pkB440ED0ModelLoader->DispatchWithScope(m_pkReference, pkForm, GetPriority(), this, iType);
}

class B441420Info;

class B441420Array
{
  public:
    B441420Info*& GetAt(int iIndex);
};

class B441420Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    B441420Array m_kInfos;

    B441420Info* GetInfoAt(int iIndex);
};

// @fnv 0x00441420
B441420Info* B441420Owner::GetInfoAt(int iIndex)
{
    return m_kInfos.GetAt(iIndex);
}

struct MLPackage
{
    bool GetForceUnequipWeapon();
};

struct MLActor
{
    struct MLParentCell* GetParentCell();
    MLPackage* GetCurrentPackage();
};

struct MLCellBase
{
    int unk00;
};

struct MLAttachTarget
{
    int unk00;
};

struct MLParentCell : MLCellBase
{
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
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    bool FUN_005f1590(MLActor* apActor);
    void FUN_005fa0a0(MLActor* apActor);
    void FUN_005f9e00(MLActor* apActor, bool abFlag1, bool abFlag2, bool abFlag3);
};

struct MLParentCellEx : MLParentCell, MLAttachTarget
{
};

struct MLLoadTask;

struct MLModelLoader
{
    void QueueModelAnimations(MLAttachTarget* apTarget, int aiPriority, MLLoadTask* apTask, MLActor* apActor,
                              bool abFlag1, bool abFlag2);
    void ModelLoader_QueueCreatureParts(MLAttachTarget* apTarget, int aiPriority, MLLoadTask* apTask, MLActor* apActor);
};

extern MLModelLoader* g_pMLModelLoader;

struct MLLoadTask
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MEM_CONTEXT eMemContext;
    int unk1C;
    int unk20;
    int unk24;
    MLActor* pActor;

    int GetPriority();
    void QueueDismemberedLimbLoads();
    void ProcessLoadTask();
};

// @fnv 0x004419a0
void MLLoadTask::ProcessLoadTask()
{
    AutoMemContext kMemContext5(eMemContext, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x925);
    MLParentCellEx* pCell4 = (MLParentCellEx*)pActor->GetParentCell();
    MLActor* pTaskActor = pActor;
    bool bUnequipB = true;
    MLPackage* pPackage9 = pTaskActor->GetCurrentPackage();
    if (pPackage9 && pPackage9->GetForceUnequipWeapon())
        bUnequipB = false;

    bool m_bHeaderParsed = pCell4->FUN_005f1590(pActor);
    if (!m_bHeaderParsed)
        pCell4->FUN_005fa0a0(pActor);
    else
        pCell4->FUN_005f9e00(pActor, true, bUnequipB, false);

    MLAttachTarget* pTarget5 = pCell4;
    g_pMLModelLoader->QueueModelAnimations(pTarget5, GetPriority(), this, pActor, true, false);
    g_pMLModelLoader->ModelLoader_QueueCreatureParts(pTarget5, GetPriority(), this, pActor);
    QueueDismemberedLimbLoads();
}

struct Cls492c0
{
    Cls492c0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls496a0
{
    Cls496a0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4b750
{
    Cls4b750(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4ba10
{
    Cls4ba10(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4bbe0
{
    Cls4bbe0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4be80
{
    Cls4be80(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4b500
{
    Cls4b500(int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4c760
{
    Cls4c760(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls497c0
{
    Cls497c0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct ShellTask28
{
    void BSTaskThread_StartThread();
};
void FUN_00446e30();
void ModelLoader_LoadQueuedPriorityCallback();
void ModelLoader_GetExternalCountCallback();
void ModelLoader_PauseCallback();
void ModelLoader_ResumeCallback();
struct Mgr442650
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    BackgroundCloneThread* m_28;
    char m_2c;
    Mgr442650* ModelLoader_ModelLoader();
};
// @fnv 0x00442650
// src: COMMUNITY 0x00442650
Mgr442650* Mgr442650::ModelLoader_ModelLoader()
{
    m_00 = new Cls492c0(10, 1009, 12);
    m_04 = new Cls496a0(10, 1009, 12);
    m_08 = new Cls4b750(10, 5039, 12);
    m_0c = new Cls4b750(10, 5039, 12);
    m_10 = new Cls4ba10(10, 251, 12);
    m_14 = new Cls4bbe0(10, 251, 12);
    m_18 = new Cls4be80(10, 251, 12);
    m_1c = new Cls4b500(10, 8);
    m_20 = new Cls4c760(10, 1009, 12);
    m_24 = new Cls497c0(10, 1009, 12);
    m_28 = new BackgroundCloneThread(10);
    ((ShellTask28*)m_28)->BSTaskThread_StartThread();
    m_2c = 0;
    if (DAT_01202d98)
    {
        ((ModelLoaderIOOperations*)DAT_01202d98)->EffectSetting_SetLight((void*)FUN_00446e30);
        ((ModelLoaderIOOperations*)DAT_01202d98)->FUN_004febb0((void*)ModelLoader_UpdateSecondaryQueueCallback);
        ((ModelLoaderIOOperations*)DAT_01202d98)->FUN_00442a80((void*)ModelLoader_LoadQueuedPriorityCallback);
        ((ModelLoaderIOOperations*)DAT_01202d98)->MobileObject_SetTalkingActivatorRef((void*)ModelLoader_GetExternalCountCallback);
        ((ModelLoaderIOOperations*)DAT_01202d98)->FUN_004febd0((void*)ModelLoader_PauseCallback);
        ((ModelLoaderIOOperations*)DAT_01202d98)->SetWaterForm((void*)ModelLoader_ResumeCallback);
    }
    return this;
}

struct QEntry444;

struct QTask444
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void Queue8();
    virtual void v009();
    virtual void QueueA();
    void FUN_00443aa0(QueuedFile* pkParent);
    void QueuedModel_SetFaceGenModel(bool bValue);
};

struct FUN_0043c960
{
    char pad[0x48];
    FUN_0043c960(QEntry444* pkEntry, int iPriority);
};

struct FUN_0043c6e0
{
    char pad[0x48];
    FUN_0043c6e0(int iKey, int iPriority, int iExtra, bool bFlagA, bool bFlagB);
};

struct QPtr444
{
    QTask444* Modelloader_GetReferencedThis() const;
};

struct QOut444
{
    void FUN_0092c820(const GlobalObject_00528cb0& kPtr);
    void AssignTaskReference(QueuedFile* pkFile);
};

struct QEntry444
{
    void Model_IncManualRefCount();
};

struct QMap444
{
    virtual void v0();
    virtual void v1();
    virtual bool GetAt(int iKey, QEntry444** ppkEntry);
};

struct FUN_004440d0_shell
{
    QMap444* m_pTaskMap;

    void QueueTaskByKey(int iKey, QOut444& kOut, int iPriority, QueuedFile* pkParent, int iExtra, bool bFlagA,
                        bool bFlagB, bool bFlagC);
};

// @fnv 0x004440d0
void FUN_004440d0_shell::QueueTaskByKey(int iKey, QOut444& kOut, int iPriority, QueuedFile* pkParent, int iExtra,
                                        bool bFlagA, bool bFlagB, bool bFlagC)
{
    QEntry444* pkEntry = 0;
    if (m_pTaskMap->GetAt(iKey, &pkEntry))
    {
        if (bFlagB)
            pkEntry->Model_IncManualRefCount();
        if (pkParent)
        {
            GlobalObject_00528cb0 kTask((int)new FUN_0043c960(pkEntry, iPriority));
            ((QPtr444*)&kTask)->Modelloader_GetReferencedThis()->FUN_00443aa0(pkParent);
            ((QPtr444*)&kTask)->Modelloader_GetReferencedThis()->QueueA();
            kOut.FUN_0092c820(kTask);
            return;
        }
        kOut.AssignTaskReference(0);
        return;
    }
    GlobalObject_00528cb0 kNewTask((int)new FUN_0043c6e0(iKey, iPriority, iExtra, bFlagA, bFlagB));
    ((QPtr444*)&kNewTask)->Modelloader_GetReferencedThis()->QueuedModel_SetFaceGenModel(bFlagC);
    ((QPtr444*)&kNewTask)->Modelloader_GetReferencedThis()->FUN_00443aa0(pkParent);
    ((QPtr444*)&kNewTask)->Modelloader_GetReferencedThis()->Queue8();
    kOut.FUN_0092c820(kNewTask);
}

namespace fnv_00444350 {
struct QFile444
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
    virtual void Start();
    virtual void v11();
    virtual void SetPriority(int);
    void SetParent(QFile444*);
    void SetFlag(bool);
};
struct QHead444 : public QFile444
{
    QHead444(void* apKey, int aePriority, void* apNPC, bool abA, bool abB);
    QHead444(void* apEntry, int aePriority);
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
};
struct QPtr444
{
    QPtr444(QHead444*);
    ~QPtr444();
    operator QHead444*() const;
    QHead444* operator->() const;
    QPtr444& operator=(const QPtr444&);
    QPtr444& operator=(QHead444*);
    int p;
};
struct QEntry444
{
    void AddRef();
};
struct QMap444
{
    virtual void v0();
    virtual void v1();
    virtual bool GetAt(void* apKey, QEntry444** appOut);
};
struct HeadLoader444
{
    QMap444* pMap;
    void ModelLoader_QueueModel_00444350(void* apKey, int aiArg2, QPtr444* apOut, int aePriority, QFile444* apParent, void* apNPC,
                      bool abA, bool abB, bool abFlag);
};

// @fnv 0x00444350
// src: XBOX_PDB 0x00444350
void HeadLoader444::ModelLoader_QueueModel_00444350(void* apKey, int aiArg2, QPtr444* apOut, int aePriority, QFile444* apParent,
                                 void* apNPC, bool abA, bool abB, bool abFlag)
{
    QEntry444* pEntry = 0;
    if (pMap->GetAt(apKey, &pEntry))
    {
        if (abB)
            pEntry->AddRef();
        if (apParent)
        {
            QPtr444 spHead(new QHead444(pEntry, aePriority));
            spHead->SetParent(apParent);
            spHead->Start();
            *apOut = spHead;
            return;
        }
        *apOut = 0;
        return;
    }
    QPtr444 spNew(new QHead444(apKey, aePriority, apNPC, abA, abB));
    spNew->SetFlag(abFlag);
    spNew->SetParent(apParent);
    spNew->SetPriority(aiArg2);
    *apOut = spNew;
}
}  // namespace fnv_00444350

struct S_00444d40_Class
{
    void QueueModelForObject(int param1, GlobalObject_00528cb0* param2, int param3, int param4, int param5);

    void ModelLoader_QueueBoundObject(int param1, int param2, int param3, int param4);
};

// @fnv 0x00444d40
// src: XBOX_PDB 0x00444d40
void S_00444d40_Class::ModelLoader_QueueBoundObject(int param1, int param2, int param3, int param4)
{
    GlobalObject_00528cb0 local(0);

    QueueModelForObject(param1, &local, param2, param3, param4);
}

struct QHelmetPtr
{
    void* p;
    QHelmetPtr(QueuedHelmet* = 0);
    ~QHelmetPtr();
    QueuedHelmet* operator->() const;
    QHelmetPtr& operator=(QueuedHelmet*);
};


struct QHelmetQueue
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(NiRenderer* ref, QHelmetPtr* ptr);
    virtual void v3();
    virtual bool Add(NiRenderer* ref, QHelmetPtr* ptr, bool flag);
};

struct QHelmetDest
{
    void Assign(const QHelmetPtr&);
};

struct FUN_004450c0_holder : public ModelLoader
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    QHelmetQueue* m_pPrimaryTaskProcessor;

    void ModelLoader_QueueHelmet(FUN_0043f010* a1, QHelmetDest* a2, int a3, QueuedFile* a4, int a5);
};

// Looks up a queued helmet for a1's renderer, creates and adds one if missing, then assigns it to a2.
// @fnv 0x004450c0
// src: XBOX_PDB 0x004450c0
void FUN_004450c0_holder::ModelLoader_QueueHelmet(FUN_0043f010* a1, QHelmetDest* a2, int a3, QueuedFile* a4, int a5)
{
    QHelmetPtr ptr(0);
    if (!this->m_pPrimaryTaskProcessor->Lookup(a1->Get(), &ptr))
    {
        ptr = new QueuedHelmet(a1, a3, a5);
        if (this->m_pPrimaryTaskProcessor->Add(a1->Get(), &ptr, false))
        {
            ptr->SetParent(a4);
            ptr->DispatchToManager();
        }
        else
        {
            ptr = 0;
        }
    }
    a2->Assign(ptr);
}

struct FUN_00445430_obj
{
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int a1, void* pGuard);
};

struct LoadScopeGuard : public S_0042f730
{
    LoadScopeGuard(AC_0042f730* p)
    {
        SetObjectAndAddReference(p);
    }
    int Modelloader_GetReferencedThis(int a1);
    ~LoadScopeGuard();
};

struct FUN_00445430_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00445430_obj* m_14;
    void ModelLoader_CancelReplacementKFList(unsigned int a1);
};


LoadScopeGuard::~LoadScopeGuard()
{
    BSTask_int64_DecRefCount_ReleaseTaskReference((void**)this);
}

// @fnv 0x00445430
// src: COMMUNITY 0x00445430
void FUN_00445430_cls::ModelLoader_CancelReplacementKFList(unsigned int a1)
{
    LoadScopeGuard guard(0);
    if (m_14->v2(a1, &guard))
    {
        DAT_01202d98->BSTaskManager_CancelTask(guard.Modelloader_GetReferencedThis(0));
    }
}

namespace fnv_00445570 {
struct FUN_00445570_obj
{
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int a1, void* pGuard);
};

struct FUN_00445570_obj2
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned int a1);
};

struct LoadScopeGuard : public S_0042f730
{
    LoadScopeGuard(AC_0042f730* p)
    {
        SetObjectAndAddReference(p);
    }
    int Modelloader_GetReferencedThis(int a1);
    ~LoadScopeGuard();
};

struct FUN_00445570_cls
{
    int unk00;
    int unk04;
    FUN_00445570_obj* m_08;
    FUN_00445570_obj2* m_0c;
    int unk10;
    int unk14;
    FUN_00445570_obj* m_18;
    void ModelLoader_CancelReference(unsigned int a1);
};


LoadScopeGuard::~LoadScopeGuard()
{
    BSTask_int64_DecRefCount_ReleaseTaskReference((void**)this);
}

// @fnv 0x00445570
// src: XBOX_PDB 0x00445570
void FUN_00445570_cls::ModelLoader_CancelReference(unsigned int a1)
{
    LoadScopeGuard guardA(0);
    if (m_08->v2(a1, &guardA))
    {
        DAT_01202d98->BSTaskManager_CancelTask(guardA.Modelloader_GetReferencedThis(0));
        m_0c->v5(a1);
    }
    LoadScopeGuard guardB(0);
    if (m_18->v2(a1, &guardB))
    {
        DAT_01202d98->BSTaskManager_CancelTask(guardB.Modelloader_GetReferencedThis(0));
    }
}
}  // namespace fnv_00445570

int ModelLoaderStrcpyS(char*, unsigned int, const char*);
int ModelLoaderStrcatS(char*, unsigned int, const char*);
int _strnicmp(const char*, const char*, unsigned int);
int sprintf(char*, const char*, ...);
char* strrchr_0040ab30(char*, int);
unsigned int BSStringLength(const char*);
struct AnimList
{
    char* item;
    AnimList* next;
    AnimList();
    ~AnimList();
    void AddHead(char*&);
};
struct AnimNode
{
    char*& GetItem();
    AnimNode* GetNext();
};
struct Weapon445
{
    int GetType();
};

extern int weaponAnimTypes[];
extern const char* DAT_011977a4[];
struct AnimManager445
{
    void* Load(char*, int, AnimList*);
};
extern AnimManager445* DAT_011cb6a0;
struct GlobalLoader445
{
    void Register(void*);
};

struct AnimLoader445
{
    AnimList* MakeList(char*, char*, int);
    AnimList* MakeRaceList(char*, int, int, void*);
    void QueueList(AnimList*, int, int, char*);
    void QueueModelAnimations(TESModel*, int, int, Actor*, bool, bool);
};
// @fnv 0x00445a10
void AnimLoader445::QueueModelAnimations(TESModel* model, int priority, int queued, Actor* actor, bool useSkeleton,
                                         bool forceSkeleton)
{
    char idleSlash[260];
    ModelLoaderStrcpyS(idleSlash, 260, model->GetModelFilePath());
    {
        Actor* actorCast;
        char* skeletonSlash = strrchr_0040ab30(idleSlash, 92);
        if (actor && actor->HasHealth(1))
        {
            if (skeletonSlash && !_strnicmp(skeletonSlash + 1, "Skeleton", 8))
            {
                char a[260];
                ModelLoaderStrcpyS(a, 260, "Data\\");
                if (_strnicmp(idleSlash, "Meshes\\", 7))
                    ModelLoaderStrcatS(a, 260, "Meshes\\");
                ModelLoaderStrcatS(a, 260, idleSlash);
                char* extraList;
                extraList = strrchr_0040ab30(a, 92);
                ModelLoaderStrcpyS(extraList, 260 - (extraList - a), "\\MTIdle.KF");
                AnimList* i;
                i = MakeList(a, idleSlash, 0);
                QueueList(i, priority, queued, 0);
                delete i;
                actorCast = actor->IsActor() ? actor : 0;
                if (actorCast && reinterpret_cast<Weapon445*>(actorCast->GetActiveWeapon()))
                {
                    const char* p;
                    p = DAT_011977a4[weaponAnimTypes[reinterpret_cast<Weapon445*>(actorCast->GetActiveWeapon())->GetType()]];
                    if (p && *p)
                    {
                        sprintf(extraList, "\\%sHolster.KF", p);
                        i = MakeList(a, idleSlash, 0);
                        QueueList(i, priority, queued, 0);
                        delete i;
                        sprintf(extraList, "\\PA%sHolster.KF", p);
                        i = MakeList(a, idleSlash, 0);
                        QueueList(i, priority, queued, 0);
                        delete i;
                    }
                }
                ModelLoaderStrcpyS(extraList, 260 - (extraList - a), "\\Death.KF");
                i = MakeList(a, idleSlash, 0);
                QueueList(i, priority, queued, 0);
                delete i;
            }
        }
        else
        {
            char* weaponName;
            TESAnimation* n;
            weaponName = strrchr_0040ab30(idleSlash, 92);
            const int loadFlags = 0;
            if (((weaponName && !_strnicmp(1 + weaponName, "Skeleton", 8)) || forceSkeleton) && useSkeleton)
            {
                void* raceContext;
                raceContext = 0;
                if (actor && actor->IsActor())
                {
                    Actor* filename = actor;
                    raceContext = filename->Actor::GetRace();
                }
                AnimList* skeletonAnimations;
                skeletonAnimations = MakeRaceList(idleSlash, 1, 1, raceContext);
                QueueList(skeletonAnimations, priority, queued, 0);
                delete skeletonAnimations;
            }
            else if (actor->IsCharacter())
            {
                char b[260];
                ModelLoaderStrcpyS(b, 260, idleSlash);
                char* directorySlash;
                directorySlash = strrchr_0040ab30(b, 92);
                if (actor->GetIsChildSize(1))
                    ModelLoaderStrcpyS(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Child\\IdleAnims");
                else if (actor->GetSex() == 1)
                    ModelLoaderStrcpyS(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Female\\IdleAnims");
                else
                    ModelLoaderStrcpyS(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Male\\IdleAnims");
                AnimList* idleAnimations;
                idleAnimations = new AnimList;
                ((GlobalLoader445*)g_modelLoader)->Register(DAT_011cb6a0->Load(b, loadFlags, idleAnimations));
                QueueList(idleAnimations, priority, queued, 0);
                delete idleAnimations;
            }
            n = dynamic_cast<TESAnimation*>(model);
            if (n && n->HasSpecialAnimations())
            {
                AnimList* pObj;
                pObj = new AnimList;
                AnimNode* race;
                race = (AnimNode*)n->GetKFFileList();
                while (race)
                {
                    unsigned long ptr;
                    const char* animationFile;
                    animationFile = race->GetItem();
                    ptr = BSStringLength(animationFile) + 1;
                    char* copy;
                    copy = new char[ptr];
                    ModelLoaderStrcpyS(copy, ptr, animationFile);
                    pObj->AddHead(copy);
                    race = race->GetNext();
                }
                char prefix[260];
                ModelLoaderStrcpyS(prefix, 260, model->GetModelFilePath());
                char* idx;
                idx = strrchr_0040ab30(prefix, 92);
                if (idx)
                    ModelLoaderStrcpyS(idx, 260 - (idx - prefix), "\\SpecialAnims\\");
                QueueList(pObj, priority, queued, prefix);
                delete pObj;
            }
        }
    }
}

namespace P516 {
struct Task
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Queue();
    virtual void v24();
    virtual void Finish();
    void FUN_00443aa0(Task*);
    void SetFieldCToFive();
    unsigned int GetObjectFlags();
};
struct Group : Task
{
    Group(void*, int);
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
};
struct File : Task
{
    File(const char*, int, void*, Task*);
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
};
struct Ptr
{
    Task* p;
    Ptr(Task*);
    ~Ptr();
    Task* Get();
    void Set(Task*);
};
struct Paths
{
    const char** FUN_006815c0();
    Paths* FUN_00726070();
    void FUN_0063f7b0();
};
struct Owner
{
    void Animation_QueueReplacementAnimation(Task*);
};
struct FileMap
{
    virtual void v0();
    virtual void v4();
    virtual bool Lookup(const char*, Task**);
};
struct GroupMap
{
    virtual void v0();
    virtual void v4();
    virtual bool Lookup(Owner*, Ptr*);
    virtual void vc();
    virtual void Insert(Owner*, Ptr*, int);
};
struct Loader
{
    int unk00;
    FileMap* files;
    int unk08;
    int unk0c;
    int unk10;
    GroupMap* groups;
    void LoadFiles(Paths*, Owner*, int, Task*, const char*);
};
// @fnv 0x004465f0
void Loader::LoadFiles(Paths* apPaths, Owner* owner, int priority, Task* parent, const char* prefix)
{
    if (!apPaths || !owner)
        return;
    Paths* node = apPaths;
    if (node && *node->FUN_006815c0())
    {
        AutoMemContext memory((MEM_CONTEXT)0x33, true,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xe9f);
        Ptr group(0);
        while (node)
        {
            const char* entry = *node->FUN_006815c0();
            if (entry)
            {
                const char* h = entry;
                char p[260];
                if (prefix)
                {
                    ModelLoaderStrcpyS(p, 260, prefix);
                    ModelLoaderStrcatS(p, 260, entry);
                    h = p;
                }
                Task* a = 0;
                if (files->Lookup(h, &a))
                    owner->Animation_QueueReplacementAnimation(a);
                else
                {
                    if (!group.Get() && !groups->Lookup(owner, &group))
                    {
                        group.Set(new Group(owner, priority));
                    }
                    Ptr i(new File(h, priority, owner, group.Get()));
                    i.Get()->FUN_00443aa0(group.Get());
                    i.Get()->Queue();
                }
                delete entry;
                node->FUN_0063f7b0();
            }
            else
                node = node->FUN_00726070();
        }
        if (group.Get() && group.Get()->GetObjectFlags() > 0)
        {
            group.Get()->FUN_00443aa0(parent);
            groups->Insert(owner, &group, 1);
            group.Get()->SetFieldCToFive();
            group.Get()->Finish();
        }
        else
            group.Set(0);
    }
}
}

namespace fnv_00447330 {
struct FUN_00447300_shell : public ModelLoader
{
    void* FUN_00447300(char*, char*, void*);
};
struct KFGlobal447330
{
    void* FUN_00600700(char*, int);
    void FUN_00600170(char*, void*, int);
};
extern KFGlobal447330* DAT_011cb6a0;
struct KFList447330
{
    ~KFList447330();
    bool _ref_008256d0();
    char** _ref_006815c0();
    void _ref_0063f7b0();
};
char* __cdecl strrchr_0040ab30(char*, int);
int __cdecl ModelLoaderStrcpyS(char*, unsigned int, const char*);
void __cdecl _Deallocate(void*);

struct FUN_00447330_shell : public ModelLoader
{
    void* ModelLoader_BuildKFFileList(char* arg0, bool arg1, bool arg2, int arg3);
};

// @fnv 0x00447330
// src: COMMUNITY 0x00447330
void* FUN_00447330_shell::ModelLoader_BuildKFFileList(char* apPath, bool abLoadLocomotion, bool arg2, int aiIndex)
{
    AutoMemHelper helper2(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                          0x108e);
    void* retVal_2;
    char buf6[260];
    char* p;
    void* res3;
    if (DAT_011cb6a0 != 0 && DAT_011cb6a0->FUN_00600700(apPath, 0) != 0)
    {
        retVal_2 = 0;
        if (aiIndex == 12)
        {
            int i5;
            for (i5 = 0; (unsigned int)i5 < 12; i5++)
            {
                if (retVal_2 != 0)
                {
                    ((FUN_00447850_shell*)this)->ModelLoader_CopyFilenameList(DAT_011cb6a0->FUN_00600700(apPath, i5), retVal_2);
                }
                else
                {
                    retVal_2 = ((FUN_00447850_shell*)this)->ModelLoader_CopyFilenameList(DAT_011cb6a0->FUN_00600700(apPath, i5), 0);
                }
            }
        }
        else if (aiIndex != 0 && arg2)
        {
            retVal_2 = ((FUN_00447850_shell*)this)->ModelLoader_CopyFilenameList(DAT_011cb6a0->FUN_00600700(apPath, 0), 0);
            ((FUN_00447850_shell*)this)->ModelLoader_CopyFilenameList(DAT_011cb6a0->FUN_00600700(apPath, aiIndex), retVal_2);
        }
        else
        {
            retVal_2 = ((FUN_00447850_shell*)this)->ModelLoader_CopyFilenameList(DAT_011cb6a0->FUN_00600700(apPath, aiIndex), 0);
        }
        return retVal_2;
    }
    ModelLoaderStrcpyS(buf6, 260, "Data\\Meshes\\");
    ModelLoaderStrcatS(buf6, 260, apPath);
    p = strrchr_0040ab30(buf6, '\\');
    if (p == 0)
    {
        return 0;
    }
    ModelLoaderStrcpyS(p, 260 - (p - buf6), "\\*.KF");
    res3 = ((FUN_00447300_shell*)this)->FUN_00447300(buf6, apPath, 0);
    if (abLoadLocomotion && BSStringLength(apPath))
    {
        char buf3[260];
        char* pA;
        KFList447330* res4;
        ModelLoaderStrcpyS(buf3, 260, apPath);
        pA = strrchr_0040ab30(buf3, '\\');
        if (pA != 0)
        {
            *pA = 0;
            ModelLoaderStrcatS(pA, 260 - (pA - buf3), "\\Locomotion\\");
            ModelLoaderStrcpyS(p, 260 - (p - buf6), "\\Locomotion\\*.KF");
            if (res3 == 0)
            {
                res3 = ((FUN_00447300_shell*)this)->FUN_00447300(buf6, buf3, 0);
            }
            else
            {
                ((FUN_00447300_shell*)this)->FUN_00447300(buf6, buf3, res3);
            }
            ModelLoaderStrcatS(pA, 260 - (pA - buf3), "Hurt\\");
            ModelLoaderStrcatS(pA, 260 - (pA - buf3), "IdleAnims");
            ModelLoaderStrcpyS(p, 260 - (p - buf6), "\\Locomotion\\Hurt\\*.KF");
            res4 = (KFList447330*)((FUN_00447300_shell*)this)->FUN_00447300(buf6, buf3, 0);
            if (res4 != 0)
            {
                DAT_011cb6a0->FUN_00600170(buf3, res4, 1);
                while (!res4->_ref_008256d0())
                {
                    char* head = *res4->_ref_006815c0();
                    delete head;
                    res4->_ref_0063f7b0();
                }
                delete res4;
            }
        }
    }
    DAT_011cb6a0->FUN_00600170(apPath, res3, 0);
    return res3;
}
}  // namespace fnv_00447330

struct MeshSource
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual const char* Path();
};
struct CacheNode
{
};
struct ModelLoaderCacheData
{
    int unk00;
    int unk04;
    int ready;
};
struct NodeHandle
{
    CacheNode* value;
    NodeHandle(CacheNode*);
    ~NodeHandle();
    operator CacheNode*() const;
};
struct DataHandle
{
    ModelLoaderCacheData* value;
    DataHandle(ModelLoaderCacheData*);
    ~DataHandle();
    operator ModelLoaderCacheData*() const;
    ModelLoaderCacheData* operator->() const;
};
struct MeshName
{
    char* data;
    short length;
    short capacity;
    MeshName();
    ~MeshName();
    operator const char*() const;
};
struct MeshCache
{
    bool LookupModelAndGetFlags(const char*, NodeHandle*, DataHandle*);
};
MeshCache* FUN_00652110();
void BuildEgmFilename(MeshName*, const char*, int);
struct MeshTask
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void Queue();
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
    MeshTask(CacheNode*, ModelLoaderCacheData*);
    void SetParent(void*);
};
struct TaskHandle
{
    MeshTask* value;
    TaskHandle(MeshTask*);
    ~TaskHandle();
    operator MeshTask*() const;
    MeshTask* operator->() const;
};
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_00406d50(char*, unsigned int, const char*);
void* operator new(unsigned int);
struct MeshLoader
{
    void ModelLoader_QueueFaceGenFile(const char*, int, void*, int);
    void LoadMesh(MeshSource*, int, void*, int);
};
// Builds a Meshes\ path from source->Path(), looks up cached mesh data for each variant and queues a MeshTask, otherwise loads it via FUN_00447a40.
// @fnv 0x00447bf0
void MeshLoader::LoadMesh(MeshSource* source, int priority, void* parent, int kind)
{
    NodeHandle node2(0);
    DataHandle data7(0);
    char path2[260];
    FUN_00406d30(path2, 260, "Meshes\\");
    FUN_00406d50(path2, 260, source->Path());
    if (kind == 9)
    {
        for (int index = 0; index < 2; index++)
        {
            MeshName name;
            BuildEgmFilename(&name, path2, index);
            if (FUN_00652110() && FUN_00652110()->LookupModelAndGetFlags(name, &node2, &data7) && node2 && data7 &&
                ((ModelLoaderCacheData*)data7)->ready)
            {
                if (parent)
                {
                    TaskHandle task(new MeshTask(node2, data7));
                    ((MeshTask*)task)->SetParent(parent);
                    ((MeshTask*)task)->Queue();
                }
                continue;
            }
            ModelLoader_QueueFaceGenFile(name, priority, parent, 1);
        }
    }
    else
    {
        MeshName other5;
        BuildEgmFilename(&other5, path2, -1);
        if (FUN_00652110() && FUN_00652110()->LookupModelAndGetFlags(other5, &node2, &data7) && node2 && data7 &&
            ((ModelLoaderCacheData*)data7)->ready)
        {
            if (parent)
            {
                TaskHandle taskOther4(new MeshTask(node2, data7));
                ((MeshTask*)taskOther4)->SetParent(parent);
                ((MeshTask*)taskOther4)->Queue();
            }
            return;
        }
        ModelLoader_QueueFaceGenFile(other5, priority, parent, 1);
    }
}

struct RecursiveModelNode;
struct RecursiveModelChild
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual RecursiveModelNode* GetNode();
};
struct RecursiveModelNode
{
    unsigned int GetFormID();
    unsigned int GetChildCount();
    RecursiveModelChild* GetChild(unsigned int index);
};
struct ModelPathComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* GetPath();
};
struct ModelForm
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    ModelPathComponent model;
    bool Skip();
};
struct ModelFormLookup
{
    ModelForm* Find(unsigned int id);
};
extern ModelFormLookup* DAT_011c3f2c;
extern int DAT_01202de8;
bool __cdecl NiObject_IsKindOf(const void* type, const RecursiveModelNode* node);

struct RecursiveModelLoader
{
    ModelMapStub* models;
    Model* Load(const char* path, bool a, bool b, int c, int d, int e);
    void LoadModelTree(RecursiveModelNode* node);
};

// Recursively loads models for a node and its children: looks up the node's form, loads its model path if missing, then recurses into child nodes.
// @fnv 0x00448a90
void RecursiveModelLoader::LoadModelTree(RecursiveModelNode* node)
{
    if (!node)
        return;
    if (NiObject_IsKindOf(&DAT_01202de8, node))
    {
        RecursiveModelNode* object = node;
        ModelForm* form = DAT_011c3f2c->Find(object->GetFormID());
        if (form && !form->Skip())
        {
            Model* model = 0;
            if (!models->Lookup(form->model.GetPath(), &model))
            {
                if (Load(form->model.GetPath(), false, true, 0, 0, 0))
                {
                    if (models->Lookup(form->model.GetPath(), &model))
                        model->ReleaseScriptRunLock();
                }
            }
        }
    }
    for (unsigned int index = 0; index < node->GetChildCount(); ++index)
    {
        RecursiveModelChild* child = node->GetChild(index);
        if (child)
        {
            RecursiveModelNode* nested = child->GetNode();
            if (nested)
                LoadModelTree(nested);
        }
    }
}

struct R449_b
{
    bool TryInsertAndFinish();
};

struct Q449_b
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RecursiveSpinLock lock;
    R449_b* LockFreeMap_GetInterface_0(void* a1, int* a2);
    bool ProcessAndReturnValue_00449700(void* a1, int a2);
};

// Locks the lock, calls FUN_00449f80 with a1 and a2, invokes TryInsertAndFinish on the result, unlocks, and returns that bool.
// @fnv 0x00449700
// src: GUESS 0x00449700 (confidence: low)
bool Q449_b::ProcessAndReturnValue_00449700(void* a1, int iValue)
{
    lock.Lock(0);
    bool res = LockFreeMap_GetInterface_0(a1, &iValue)->TryInsertAndFinish();
    lock.Unlock();
    return res;
}

class C44D510Object;

class C44D510Pointer
{
  public:
    C44D510Pointer& operator=(const C44D510Pointer& kOther);

    C44D510Object* m_pPointer;
};

class C44D510Entry
{
  public:
    bool IsPendingRemoval();

    int unk00;
    C44D510Pointer m_spValue;
};

class C44D510Iterator
{
  public:
    C44D510Entry* Get();
};

void __cdecl C44D510Yield();

class C44D510Cache
{
  public:
    bool Find(unsigned int uiKey, unsigned int uiHash);
    void Unlock();

    bool LookupAndUnlock(unsigned int uiKey, unsigned int uiHash, C44D510Pointer& spResult);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C44D510Iterator m_kIterator;
};

// Finds the entry for uiKey/uiHash, copies its value into spResult, yields, and unlocks; returns false if the entry is pending removal.
// @fnv 0x0044d510
bool C44D510Cache::LookupAndUnlock(unsigned int uiKey, unsigned int uiHash, C44D510Pointer& spResult)
{
    bool bFound = Find(uiKey, uiHash);
    if (bFound)
    {
        spResult = m_kIterator.Get()->m_spValue;
        C44D510Yield();
        if (m_kIterator.Get()->IsPendingRemoval())
            bFound = false;
    }
    Unlock();
    return bFound;
}

void __cdecl ProgramFlow();
struct Traversal : Worker
{
    bool FindKeyInTraversal(int index, const int* key);
};
// Walks the traversal's linked nodes, syncing state, and returns true when a node's observed value equals *key.
// @fnv 0x0044e820
bool Traversal::FindKeyInTraversal(int index, const int* key)
{
    int* head = reinterpret_cast<int*>(reinterpret_cast<FUN_0044ee20_class*>(controller)->GetElementAddress(index));
    while (true)
    {
        bool initial = false;
        state = head;
        current = *reinterpret_cast<NodeLink*>(state);
        *reinterpret_cast<SyncNode**>(unk08) = current.ClearLowBit();
        ProgramFlow();
        StateValue retry;
        retry.SetTaggedPointer(false, current.ClearLowBit());
        if (Modelloader_GetReferencedThis(state) != retry.Modelloader_GetReferencedThis())
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *reinterpret_cast<NodeLink*>(&current.ClearLowBit_Thunk()->state);
            *reinterpret_cast<SyncNode**>(unk04) = pending.ClearLowBit();
            ProgramFlow();
            if (Modelloader_GetReferencedThis(reinterpret_cast<int*>(&pending)) != Modelloader_GetReferencedThis(&current.ClearLowBit_Thunk()->state))
            {
                initial = true;
                break;
            }
            int observed = current.ClearLowBit()->unk04;
            StateValue value;
            value.SetTaggedPointer(false, current.ClearLowBit());
            if (Modelloader_GetReferencedThis(state) != value.Modelloader_GetReferencedThis())
            {
                initial = true;
                break;
            }
            if (!LockFreeMap_MarkedPointer_GetMark(reinterpret_cast<int*>(&pending)))
            {
                if (observed == *key)
                    return true;
                state = &current.ClearLowBit_Thunk()->state;
                *reinterpret_cast<SyncNode**>(unk0c) = current.ClearLowBit();
                ProgramFlow();
            }
            else
            {
                StateValue next;
                next.SetTaggedPointer(false, pending.ClearLowBit());
                if (CompareAndSwapEx(state, next.Modelloader_GetReferencedThis(), value.Modelloader_GetReferencedThis()))
                {
                    AddRace(current.ClearLowBit());
                }
                else
                {
                    initial = true;
                    break;
                }
            }
            current = pending;
            *reinterpret_cast<SyncNode**>(unk08) = pending.ClearLowBit();
            ProgramFlow();
        }
        if (initial)
            continue;
    }
}

class B44F890Setting
{
  public:
    void Setting_GetViewerStrings(int iArg);
};

class B44F890Node
{
  public:
    B44F890Setting** GetItem();
};

class B44F890Collection
{
  public:
    B44F890Node* GetFirstNode();
    B44F890Node* GetNextNode(B44F890Node* pkNode);
    int SettingCollectionList_Setting_GetViewerStrings(int iArg);
};

// @fnv 0x0044f890
// src: XBOX_PDB 0x0044f890
int B44F890Collection::SettingCollectionList_Setting_GetViewerStrings(int iArg)
{
    AutoMemHelper kMemHelper(9, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\Setting.h", 0x326);
    B44F890Node* pkNode = GetFirstNode();
    int iCount = 0;
    while (pkNode)
    {
        (*pkNode->GetItem())->Setting_GetViewerStrings(iArg);
        pkNode = GetNextNode(pkNode);
        iCount++;
    }
    return iCount;
}

struct FUN_00490fa0_lk
{
    FUN_00490fa0_lk(int v);
    ~FUN_00490fa0_lk();
    int v;
};

struct FUN_00490fa0_src
{
    int FUN_005585e0();
};

struct FUN_00490fa0_dst
{
    void FUN_00905820(FUN_00490fa0_src** pp);
};

class FUN_00490fa0_cls
{
  public:
    void Animation_QueueReplacementAnimation(FUN_00490fa0_src* p);
};

// @fnv 0x00490fa0
// src: XBOX_PDB 0x00490fa0
void FUN_00490fa0_cls::Animation_QueueReplacementAnimation(FUN_00490fa0_src* pSource)
{
    FUN_00490fa0_lk lk(pSource->FUN_005585e0());
    if (Modelloader_GetReferencedThis((int*)&lk) == 0)
        return;
    QueuedChildren_AddFinishedChild((char*)pSource);
    QueuedChildren_AddFinishedChild((char*)pSource);
    reinterpret_cast<FUN_00490fa0_dst*>((char*)this + 0x104)->FUN_00905820(&pSource);
}

struct SearchController
{
    int GetElementAddress(int);
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual bool Accept(int, int);
    virtual bool Finish(int, int);
};
void __cdecl ProgramFlow();
struct SearchWorker
{
    SearchController* controller;
    SyncNode** pendingGuard;
    SyncNode** currentGuard;
    SyncNode** removedGuard;
    int* state;
    NodeLink current;
    NodeLink pending;
    void FUN_005292a0(SyncNode*);
    bool ProcessNode(int key, int output);
};
// Walks the node chain from controller->GetElementAddress(key), validating links and calling controller->Accept/Finish or FUN_005292a0 on each node.
// @fnv 0x00529030
bool SearchWorker::ProcessNode(int key, int output)
{
    int* head = (int*)controller->GetElementAddress(key);
    while (true)
    {
        bool p = false;
        state = head;
        current = *(NodeLink*)state;
        *currentGuard = current.ClearLowBit();
        ProgramFlow();
        StateValue j;
        j.SetTaggedPointer(false, current.ClearLowBit());
        if (Modelloader_GetReferencedThis(state) != j.Modelloader_GetReferencedThis())
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *(NodeLink*)&current.ClearLowBit_Thunk()->state;
            *pendingGuard = pending.ClearLowBit();
            ProgramFlow();
            if (Modelloader_GetReferencedThis((int*)&pending) != Modelloader_GetReferencedThis(&current.ClearLowBit_Thunk()->state))
            {
                p = true;
                break;
            }
            int e = current.ClearLowBit()->unk00;
            StateValue h;
            h.SetTaggedPointer(false, current.ClearLowBit());
            if (Modelloader_GetReferencedThis(state) != h.Modelloader_GetReferencedThis())
            {
                p = true;
                break;
            }
            if (!LockFreeMap_MarkedPointer_GetMark((int*)&pending))
            {
                if (controller->Accept(e, output))
                    return controller->Finish(e, output);
                state = &current.ClearLowBit_Thunk()->state;
                *removedGuard = current.ClearLowBit();
                ProgramFlow();
            }
            else
            {
                StateValue desired;
                desired.SetTaggedPointer(false, pending.ClearLowBit());
                if (CompareAndSwapEx(state, desired.Modelloader_GetReferencedThis(), h.Modelloader_GetReferencedThis()))
                    FUN_005292a0(current.ClearLowBit());
                else
                {
                    p = true;
                    break;
                }
            }
            current = pending;
            *currentGuard = pending.ClearLowBit();
            ProgramFlow();
        }
        if (p)
            continue;
    }
}

struct Form3;
struct Cell3;
struct Render3;
struct Other3;
struct Position3;
struct Radio3;
struct Ref3;
struct Obj3;
struct Proc3;
struct Fixed3
{
    operator const char*() const;
};
struct Ptr3
{
    Obj3* p;
    Ptr3(Obj3*);
    ~Ptr3();
    operator Obj3*() const;
    Ptr3& operator=(Obj3*);
};
struct Text3
{
    char* p;
    Text3();
    operator char*() const;
    void SaveHavok(Ref3*);
    void SaveAnim(Ref3*);
};
struct Flags3
{
    int bits;
    Flags3(int);
    Flags3(const Flags3&);
};
struct Extra3
{
    void* Primitive();
    float Modifier();
    void SetSavedHavokData(char*);
    void SetSavedAnimation(char*);
};
struct Prim3
{
    void Clear();
};
struct Update3
{
    float time;
    bool a, b;
    int flags;
    Update3(float, bool, bool);
};
struct Obj3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual Obj3* AsNode();
    virtual Obj3* AsOther();
    Obj3* Parent();
    Fixed3& GetName();
    NiPoint3& Position();
    NiMatrix3& Rotation();
    float Scale();
    bool HasCollision();
    void AssignReference(Ref3*);
    bool Cleanup();
    void Clear();
    void SetPos(const NiPoint3&);
    void SetRot(const NiMatrix3*);
    void SetScale(float);
    void Post();
    void Update(Update3&);
};
struct Proc3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual void unused15c();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual void unused1d0();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void unused1f0();
    virtual void unused1f4();
    virtual void unused1f8();
    virtual void unused1fc();
    virtual void unused200();
    virtual void unused204();
    virtual void unused208();
    virtual void unused20c();
    virtual void unused210();
    virtual void unused214();
    virtual void unused218();
    virtual void unused21c();
    virtual void unused220();
    virtual void unused224();
    virtual void unused228();
    virtual void unused22c();
    virtual void unused230();
    virtual void unused234();
    virtual void unused238();
    virtual void unused23c();
    virtual void unused240();
    virtual void unused244();
    virtual void unused248();
    virtual void unused24c();
    virtual void unused250();
    virtual void unused254();
    virtual void unused258();
    virtual void unused25c();
    virtual void unused260();
    virtual void unused264();
    virtual void unused268();
    virtual void unused26c();
    virtual void unused270();
    virtual void unused274();
    virtual void unused278();
    virtual void unused27c();
    virtual void unused280();
    virtual void unused284();
    virtual void unused288();
    virtual void unused28c();
    virtual void unused290();
    virtual void unused294();
    virtual void unused298();
    virtual void unused29c();
    virtual void unused2a0();
    virtual void unused2a4();
    virtual void unused2a8();
    virtual void unused2ac();
    virtual void unused2b0();
    virtual void unused2b4();
    virtual void unused2b8();
    virtual void unused2bc();
    virtual void unused2c0();
    virtual void unused2c4();
    virtual void unused2c8();
    virtual void unused2cc();
    virtual void unused2d0();
    virtual void unused2d4();
    virtual void unused2d8();
    virtual void unused2dc();
    virtual void unused2e0();
    virtual void unused2e4();
    virtual void unused2e8();
    virtual void unused2ec();
    virtual void unused2f0();
    virtual void unused2f4();
    virtual void unused2f8();
    virtual void unused2fc();
    virtual void unused300();
    virtual void unused304();
    virtual void unused308();
    virtual void unused30c();
    virtual void unused310();
    virtual void unused314();
    virtual void unused318();
    virtual void unused31c();
    virtual void unused320();
    virtual void unused324();
    virtual void unused328();
    virtual void unused32c();
    virtual void unused330();
    virtual void unused334();
    virtual void unused338();
    virtual void unused33c();
    virtual void unused340();
    virtual void unused344();
    virtual void unused348();
    virtual void unused34c();
    virtual void unused350();
    virtual void unused354();
    virtual void unused358();
    virtual void unused35c();
    virtual void unused360();
    virtual void unused364();
    virtual void unused368();
    virtual void unused36c();
    virtual void unused370();
    virtual void unused374();
    virtual void unused378();
    virtual void unused37c();
    virtual void unused380();
    virtual void unused384();
    virtual void unused388();
    virtual void unused38c();
    virtual void unused390();
    virtual void unused394();
    virtual void unused398();
    virtual void unused39c();
    virtual void unused3a0();
    virtual void unused3a4();
    virtual void unused3a8();
    virtual void unused3ac();
    virtual void unused3b0();
    virtual void unused3b4();
    virtual void unused3b8();
    virtual void unused3bc();
    virtual void unused3c0();
    virtual void unused3c4();
    virtual void unused3c8();
    virtual void unused3cc();
    virtual void unused3d0();
    virtual void unused3d4();
    virtual void unused3d8();
    virtual void unused3dc();
    virtual void unused3e0();
    virtual void unused3e4();
    virtual void unused3e8();
    virtual void unused3ec();
    virtual void unused3f0();
    virtual void unused3f4();
    virtual void unused3f8();
    virtual void unused3fc();
    virtual void unused400();
    virtual void unused404();
    virtual void unused408();
    virtual void unused40c();
    virtual void unused410();
    virtual void unused414();
    virtual void unused418();
    virtual void unused41c();
    virtual void unused420();
    virtual void unused424();
    virtual void unused428();
    virtual void unused42c();
    virtual void unused430();
    virtual void unused434();
    virtual void unused438();
    virtual void unused43c();
    virtual void unused440();
    virtual void unused444();
    virtual void unused448();
    virtual void unused44c();
    virtual void unused450();
    virtual void unused454();
    virtual void unused458();
    virtual void unused45c();
    virtual void unused460();
    virtual void unused464();
    virtual void unused468();
    virtual void unused46c();
    virtual void unused470();
    virtual void unused474();
    virtual void unused478();
    virtual void unused47c();
    virtual void unused480();
    virtual void unused484();
    virtual void unused488();
    virtual void unused48c();
    virtual void unused490();
    virtual void unused494();
    virtual void unused498();
    virtual void unused49c();
    virtual void unused4a0();
    virtual void unused4a4();
    virtual void unused4a8();
    virtual void unused4ac();
    virtual void unused4b0();
    virtual void unused4b4();
    virtual void unused4b8();
    virtual void unused4bc();
    virtual void unused4c0();
    virtual void unused4c4();
    virtual void unused4c8();
    virtual void unused4cc();
    virtual void unused4d0();
    virtual void unused4d4();
    virtual void unused4d8();
    virtual void unused4dc();
    virtual void unused4e0();
    virtual void unused4e4();
    virtual void unused4e8();
    virtual void unused4ec();
    virtual void unused4f0();
    virtual void unused4f4();
    virtual void unused4f8();
    virtual void ClearE(int);
    virtual void unused500();
    virtual void unused504();
    virtual void unused508();
    virtual void unused50c();
    virtual void unused510();
    virtual void unused514();
    virtual void unused518();
    virtual void unused51c();
    virtual void unused520();
    virtual void unused524();
    virtual void unused528();
    virtual void unused52c();
    virtual void unused530();
    virtual void unused534();
    virtual void unused538();
    virtual void unused53c();
    virtual void unused540();
    virtual void unused544();
    virtual void unused548();
    virtual void unused54c();
    virtual void unused550();
    virtual void unused554();
    virtual void unused558();
    virtual void unused55c();
    virtual void unused560();
    virtual void unused564();
    virtual void unused568();
    virtual void unused56c();
    virtual void unused570();
    virtual void unused574();
    virtual void unused578();
    virtual void unused57c();
    virtual void unused580();
    virtual void unused584();
    virtual void unused588();
    virtual void unused58c();
    virtual void unused590();
    virtual void unused594();
    virtual void unused598();
    virtual void unused59c();
    virtual void unused5a0();
    virtual void unused5a4();
    virtual void unused5a8();
    virtual void unused5ac();
    virtual void unused5b0();
    virtual void unused5b4();
    virtual void unused5b8();
    virtual void unused5bc();
    virtual void unused5c0();
    virtual void unused5c4();
    virtual void unused5c8();
    virtual void unused5cc();
    virtual void unused5d0();
    virtual void unused5d4();
    virtual void unused5d8();
    virtual void unused5dc();
    virtual void unused5e0();
    virtual void unused5e4();
    virtual void unused5e8();
    virtual void unused5ec();
    virtual void unused5f0();
    virtual void ClearD(int);
    virtual void unused5f8();
    virtual void unused5fc();
    virtual void unused600();
    virtual void unused604();
    virtual void unused608();
    virtual void unused60c();
    virtual void unused610();
    virtual void unused614();
    virtual void unused618();
    virtual void unused61c();
    virtual void unused620();
    virtual void unused624();
    virtual void unused628();
    virtual void unused62c();
    virtual void unused630();
    virtual void unused634();
    virtual void unused638();
    virtual void unused63c();
    virtual void unused640();
    virtual void unused644();
    virtual void unused648();
    virtual void unused64c();
    virtual void unused650();
    virtual void unused654();
    virtual void unused658();
    virtual void unused65c();
    virtual void unused660();
    virtual void unused664();
    virtual void unused668();
    virtual void unused66c();
    virtual void unused670();
    virtual void unused674();
    virtual void unused678();
    virtual void unused67c();
    virtual void unused680();
    virtual void unused684();
    virtual void unused688();
    virtual void unused68c();
    virtual void unused690();
    virtual void unused694();
    virtual void unused698();
    virtual void unused69c();
    virtual void unused6a0();
    virtual void unused6a4();
    virtual void unused6a8();
    virtual void unused6ac();
    virtual void unused6b0();
    virtual void unused6b4();
    virtual void unused6b8();
    virtual void unused6bc();
    virtual void unused6c0();
    virtual void unused6c4();
    virtual void unused6c8();
    virtual void unused6cc();
    virtual void unused6d0();
    virtual void unused6d4();
    virtual void unused6d8();
    virtual void unused6dc();
    virtual void unused6e0();
    virtual void unused6e4();
    virtual void unused6e8();
    virtual void unused6ec();
    virtual void unused6f0();
    virtual void unused6f4();
    virtual void unused6f8();
    virtual void unused6fc();
    virtual void unused700();
    virtual void unused704();
    virtual void unused708();
    virtual void unused70c();
    virtual void unused710();
    virtual void unused714();
    virtual void unused718();
    virtual void unused71c();
    virtual void unused720();
    virtual void unused724();
    virtual void unused728();
    virtual void unused72c();
    virtual void unused730();
    virtual void unused734();
    virtual void unused738();
    virtual void unused73c();
    virtual void unused740();
    virtual void unused744();
    virtual void unused748();
    virtual void unused74c();
    virtual void unused750();
    virtual void unused754();
    virtual void unused758();
    virtual void unused75c();
    virtual void unused760();
    virtual void unused764();
    virtual void unused768();
    virtual void unused76c();
    virtual void unused770();
    virtual void unused774();
    virtual void unused778();
    virtual void unused77c();
    virtual void unused780();
    virtual void unused784();
    virtual void unused788();
    virtual void unused78c();
    virtual void unused790();
    virtual void ClearB(int);
    virtual void unused798();
    virtual void ClearA(int);
    virtual void unused7a0();
    virtual void ClearC(int);
    void Reset();
    int Level();
};
struct Parent3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void Attach(Obj3*, bool);
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void Detach(Obj3*);
};
struct Delete3
{
    virtual ~Delete3();
};
struct Ref3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void Mark(int);
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual bool IsSpecial();
    virtual bool IsActor();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual bool IsObstacle();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual Obj3* SoundObject();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void ClearSlot(int);
    virtual void unused1f4();
    virtual void unused1f8();
    virtual void unused1fc();
    virtual void unused200();
    virtual void unused204();
    virtual void unused208();
    virtual void unused20c();
    virtual void unused210();
    virtual void unused214();
    virtual void unused218();
    virtual void unused21c();
    virtual void unused220();
    virtual bool HasSound();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    Form3* base;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    Cell3* cell;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    Render3* render;
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
    Delete3* owned;
    Other3* other;
    void TESObjectREFR_Set3D(Obj3*, bool);
    Obj3* Get3DSimple();
    Proc3* Process();
    int ProcessLevel();
    Extra3* Extras();
    void UpdateReferenceTransform();
    Position3* Transform();
    float GetScale();
    bool HasModifier();
    Form3* GetBase();
    bool Temporary();
    bool IsDeleted();
    void CleanupState();
    bool SaveAnimation();
    void ClearX(int);
    void ClearY(int);
    void ActorCleanup();
    void ActorZero(int);
    void EmptyA();
    void EmptyB();
    void SetFlag(unsigned int, bool);
    Other3* Physics();
    void Changed(bool);
    bool Flag(unsigned int);
    void Set3D(Obj3*);
    bool NeedsReload();
    void SetLoaded(bool);
    Radio3* Radio();
};
struct Form3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void Notify(Ref3*);
    int Type();
};
struct Cell3
{
    bool Active();
};
struct Render3
{
    int a, b, c, d, e;
    Ptr3 object;
};
struct Other3
{
    void Clear(int);
    void Reset();
};
struct Position3
{
    int a, b, c, d;
    NiPoint3 position;
};
struct Radio3
{
    Radio3* Cell();
    void Clear(int);
};
struct Loader3
{
    void Remove(Ref3*);
};
struct Queue3
{
    void Detach(Obj3*);
};
struct Scene3
{
    void RemoveObject(Obj3*);
    void RemoveSpecial(Obj3*);
};
struct World3
{
    void Remove(Ref3*);
};
struct Vats3
{
    void Remove(Ref3*);
};
struct Save3
{
    bool GetAllowChanges();
    bool Has(Ref3*, Flags3);
};
struct Load3
{
    bool GetLoading();
};
struct Audio3
{
    void Remove(Obj3*, float, bool);
};
struct Nav3
{
    void Add(Ref3*);
    void Remove(Ref3*);
    void Update(Ref3*);
};
struct BaseState3
{
    void Off();
    void On(Form3*);
};

extern Save3* g_BGSSaveLoadGame;
extern Load3* g_TESSaveLoadGame;
extern World3 DAT_011e0e80;
extern Vats3 DAT_011f2250;
extern Ref3* _g_thePlayer;
void FNV_Warning(const char*, ...);
bool AILinearTaskThreadManager_ShouldQueue3DTask();
Queue3* FUN_004537b0();
Scene3* FUN_00450b80(int);
BaseState3* BGSDestructibleObjectForm_GetDestructionForm(Form3*);
void TESObjectREFR_RemoveSounds(Obj3*);
bool TESObjectREFR_HasAddonFlags(Obj3*);
void TESObjectREFR_RemoveAddonNodes(Obj3*);
int ArrowProjectile_GetArrowCount();
void ArrowProjectile_DeleteAttachedArrows(Ref3*, bool);
void GarbageCollector_Add_00868660(Obj3*);
void NiObjectGarbage_Add(Obj3*);
void bhkNiCollisionObject_ResetSim(Obj3*, bool);
Audio3* BSAudio_QInstance();
Nav3* GetNav3();
void baseNotify3(Form3*, Ref3*);
// Swaps the reference's 3D object for replacement, detaching and cleaning up the old one and attaching the new one with its saved transform.
// @fnv 0x005702e0
// src: XBOX_PDB 0x005702e0
void Ref3::TESObjectREFR_Set3D(Obj3* replacement, bool warn)
{
    if (Get3DSimple() == replacement)
    {
        if (!replacement)
        {
            ((Loader3*)g_modelLoader)->Remove(this);
            SetLoaded(false);
        }
        return;
    }
    if (Get3DSimple() && !Get3DSimple()->Parent())
        ((Loader3*)g_modelLoader)->Remove(this);
    if (render && (Obj3*)render->object && !replacement && IsActor() && Process() && ProcessLevel() <= 1)
    {
        if (warn)
            FNV_Warning("AI: Unloading art for a high or middle high process actor (%s).",
                        ((Obj3*)render->object)->GetName().operator const char*());
        Proc3* process = Process();
        process->ClearA(0);
        process->ClearB(0);
        process->ClearC(0);
        process->Reset();
    }
    if (render)
        render->b = 0;
    Prim3* c = (Prim3*)Extras()->Primitive();
    if (!replacement && c)
        c->Clear();
    if (!replacement)
        UpdateReferenceTransform();
    NiPoint3 e = Transform()->position;
    NiMatrix3 rotation4;
    float scale4 = GetScale();
    Parent3* parentTmp = 0;
    Ref3* actor17 = 0;
    if (IsActor())
        actor17 = this;
    if (Get3DSimple() && replacement && base && base->Type() == 0x25)
        return;
    if (HasModifier() && Extras()->Modifier() != 0.0)
    {
        if (Get3DSimple() && !replacement)
            BGSDestructibleObjectForm_GetDestructionForm(GetBase())->Off();
        else if (replacement && !Get3DSimple())
            BGSDestructibleObjectForm_GetDestructionForm(GetBase())->On(GetBase());
    }
    Ptr3 oldVar(Get3DSimple());
    if ((Obj3*)oldVar)
    {
        parentTmp = (Parent3*)((Obj3*)oldVar)->Parent();
        if (parentTmp)
        {
            if (!(Temporary() && base && base->Type() == 0x25))
            {
                if (AILinearTaskThreadManager_ShouldQueue3DTask())
                    FUN_004537b0()->Detach(oldVar);
                else
                    parentTmp->Detach(oldVar);
            }
            e = ((Obj3*)oldVar)->Position();
            rotation4 = ((Obj3*)oldVar)->Rotation();
            scale4 = ((Obj3*)oldVar)->Scale();
        }
        FUN_00450b80(0)->RemoveObject(oldVar);
        if (IsSpecial())
            FUN_00450b80(0)->RemoveSpecial(oldVar);
        if (!replacement)
        {
            bool cleaned = false;
            Obj3* otherObj = ((Obj3*)oldVar)->AsOther();
            if (otherObj)
            {
                otherObj->AssignReference(0);
                cleaned = otherObj->Cleanup();
            }
            if (((Obj3*)oldVar)->HasCollision())
                TESObjectREFR_RemoveSounds(((Obj3*)oldVar)->AsNode());
            CleanupState();
            DAT_011f2250.Remove(this);
            if (!IsDeleted() && g_BGSSaveLoadGame->GetAllowChanges())
            {
                if (g_BGSSaveLoadGame->Has(this, Flags3(4)))
                {
                    Text3 data;
                    data.SaveHavok(this);
                    Extras()->SetSavedHavokData(data);
                }
                if (g_BGSSaveLoadGame->Has(this, Flags3(0x10000000)))
                {
                    bool save = false;
                    if (!IsActor())
                        save = SaveAnimation();
                    if (save)
                    {
                        Text3 data;
                        data.SaveAnim(this);
                        Extras()->SetSavedAnimation(data);
                    }
                    else
                        Mark(0x10000000);
                }
            }
            ClearX(0);
            ClearY(0);
            if (actor17)
            {
                ActorCleanup();
                ActorZero(0);
                EmptyA();
                EmptyB();
            }
            ClearSlot(0);
            bool collision9 = TESObjectREFR_HasAddonFlags(((Obj3*)oldVar)->AsNode());
            SetFlag(2, collision9);
            if (collision9)
                TESObjectREFR_RemoveAddonNodes(oldVar);
            if (actor17)
            {
                Ref3* ref = this;
                if (ref)
                {
                    Other3* physics = ref->Physics();
                    if (physics)
                        physics->Clear(0);
                    if (ref->Process())
                        ref->Process()->ClearD(0);
                }
                if (actor17->owned)
                {
                    delete actor17->owned;
                    actor17->owned = 0;
                }
                if (actor17->other)
                    actor17->other->Reset();
            }
            if (cleaned || HasSound() || IsSpecial())
                BSAudio_QInstance()->Remove(SoundObject(), 0.0f, false);
            Changed(true);
        }
        if (!cell || !cell->Active())
        {
            DAT_011e0e80.Remove(this);
            if (ArrowProjectile_GetArrowCount() > 0)
                ArrowProjectile_DeleteAttachedArrows(this, true);
        }
        if (actor17 && actor17 != _g_thePlayer)
        {
            Proc3* process = actor17->Process();
            if (process && process->Level() <= 1)
            {
                Proc3* high = process;
                high->ClearE(0);
            }
            GarbageCollector_Add_00868660(oldVar);
        }
        else
            NiObjectGarbage_Add(oldVar);
        bool flag = Flag(4);
        oldVar = 0;
        Set3D(0);
        if (!replacement && base)
        {
            if (!NeedsReload())
            {
                if (!flag)
                    base->Notify(this);
            }
            else
                ((Loader3*)g_modelLoader)->Remove(this);
        }
    }
    else if (!replacement)
        ((Loader3*)g_modelLoader)->Remove(this);
    if (!replacement)
        SetLoaded(false);
    Set3D(replacement);
    if (replacement && parentTmp)
    {
        replacement->SetPos(e);
        replacement->SetRot(&rotation4);
        replacement->SetScale(scale4);
        parentTmp->Attach(replacement, true);
        bhkNiCollisionObject_ResetSim(replacement, true);
        replacement->Post();
        Update3 update(0.0f, false, false);
        replacement->Update(update);
    }
    if (replacement && base && base->Type() != 0x25)
        replacement->AssignReference(this);
    if (!g_TESSaveLoadGame->GetLoading() && !replacement && Radio() && Radio()->Cell())
        Radio()->Cell()->Clear(0);
    if (IsObstacle())
    {
        if (replacement)
            GetNav3()->Add(this);
        else
            GetNav3()->Remove(this);
    }
    if (!replacement && GetBase() && GetBase()->Type() == 0x1c)
        GetNav3()->Update(this);
}

struct ControllerV
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual bool Call34(int, int);
    virtual bool Call38(int, int);
};
void ProgramFlow();

// @fnv 0x006662a0
bool Worker::ProcessNodeChain(int a1, int a2)
{
    int head7;
    bool flag_;
    StateValue svA2;
    StateValue svB;
    int nodeVal;
    StateValue svC2;
    head7 = ((FUN_0044ee20_class*)controller)->GetElementAddress(a1);
    while (1)
    {
        flag_ = 0;
        state = (int*)head7;
        current = *(NodeLink*)state;
        *(int*)unk08 = (int)current.ClearLowBit();
        ProgramFlow();
        svA2.SetTaggedPointer(0, current.ClearLowBit());
        if (((StateValue*)state)->Modelloader_GetReferencedThis() != svA2.Modelloader_GetReferencedThis())
            continue;
        while (1)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *(NodeLink*)((char*)current.ClearLowBit_Thunk() + 8);
            *(int*)unk04 = (int)pending.ClearLowBit();
            ProgramFlow();
            if (((StateValue*)&pending)->Modelloader_GetReferencedThis() !=
                ((StateValue*)((char*)current.ClearLowBit_Thunk() + 8))->Modelloader_GetReferencedThis())
            {
                flag_ = 1;
                break;
            }
            nodeVal = *(int*)current.ClearLowBit();
            svB.SetTaggedPointer(0, current.ClearLowBit());
            if (((StateValue*)state)->Modelloader_GetReferencedThis() != svB.Modelloader_GetReferencedThis())
            {
                flag_ = 1;
                break;
            }
            if (!LockFreeMap_MarkedPointer_GetMark((int*)&pending))
            {
                if (((ControllerV*)controller)->Call34(nodeVal, a2))
                    return ((ControllerV*)controller)->Call38(nodeVal, a2);
                state = (int*)((char*)current.ClearLowBit_Thunk() + 8);
                *(int*)unk0c = (int)current.ClearLowBit();
                ProgramFlow();
            }
            else
            {
                svC2.SetTaggedPointer(0, pending.ClearLowBit());
                if (CompareAndSwapEx(state, svC2.Modelloader_GetReferencedThis(), svB.Modelloader_GetReferencedThis()))
                {
                    AddRace(current.ClearLowBit());
                }
                else
                {
                    flag_ = 1;
                    break;
                }
            }
            current = pending;
            *(int*)unk08 = (int)pending.ClearLowBit();
            ProgramFlow();
        }
        if (flag_)
            continue;
    }
}

struct MatchNode;
struct FUN_006ecba0
{
    MatchNode* value;
    MatchNode* ClearLowBit();
    MatchNode* ClearLowBit_Thunk();
    unsigned int Modelloader_GetReferencedThis();
    bool LockFreeMap_MarkedPointer_GetMark();
    FUN_006ecba0(bool, MatchNode*);
};
struct FUN_0044e370
{
    void* value;
    FUN_0044e370(void*);
    ~FUN_0044e370();
    bool LightRefData_IsEqual(void*);
};
struct MatchNode
{
    MatchNode* value;
    void* payload;
    FUN_006ecba0 next;
};
struct MatchMap
{
    FUN_006ecba0* GetElementAddress(unsigned int);
};
void __cdecl ProgramFlow();
bool __cdecl CompareAndSwapEx(FUN_006ecba0*, unsigned int, unsigned int);
struct MatchOwner
{
    MatchMap* map;
    MatchNode** hazardNext;
    MatchNode** hazardCurrent;
    MatchNode** hazardRemoved;
    FUN_006ecba0* cursor;
    FUN_006ecba0 current;
    FUN_006ecba0 next;
    void FUN_005292a0(MatchNode*);
    bool LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_FindValue(unsigned int key, void* output);
};
// @fnv 0x00906820
// src: COMMUNITY 0x00906820
bool MatchOwner::LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_FindValue(unsigned int key, void* output)
{
    FUN_006ecba0* bucket = map->GetElementAddress(key);
    while (true)
    {
        bool first = false;
        cursor = bucket;
        current = *cursor;
        *hazardCurrent = current.ClearLowBit();
        ProgramFlow();
        FUN_006ecba0 retry(false, current.ClearLowBit());
        if (cursor->Modelloader_GetReferencedThis() != retry.Modelloader_GetReferencedThis())
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            next = current.ClearLowBit_Thunk()->next;
            *hazardNext = next.ClearLowBit();
            ProgramFlow();
            if (next.Modelloader_GetReferencedThis() != current.ClearLowBit_Thunk()->next.Modelloader_GetReferencedThis())
            {
                first = true;
                break;
            }
            FUN_0044e370 observed(&current.ClearLowBit()->payload);
            FUN_006ecba0 ref(false, current.ClearLowBit());
            if (cursor->Modelloader_GetReferencedThis() != ref.Modelloader_GetReferencedThis())
            {
                first = true;
                break;
            }
            if (!next.LockFreeMap_MarkedPointer_GetMark())
            {
                if (observed.LightRefData_IsEqual(output))
                    return true;
                cursor = &current.ClearLowBit_Thunk()->next;
                *hazardRemoved = current.ClearLowBit();
                ProgramFlow();
            }
            else
            {
                FUN_006ecba0 replacement(false, next.ClearLowBit());
                if (CompareAndSwapEx(cursor, replacement.Modelloader_GetReferencedThis(), ref.Modelloader_GetReferencedThis()))
                {
                    FUN_005292a0(current.ClearLowBit());
                }
                else
                {
                    first = true;
                    break;
                }
            }
            current = next;
            *hazardCurrent = next.ClearLowBit();
            ProgramFlow();
        }
        if (first)
            continue;
    }
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long* lAddend);

struct FUN_00ae78e0_Class
{
    struct SUB
    {
        long unk30;
        void* unk34;
    };
    char pad0[0x30];
    SUB sub;
    char pad38[0x10];
    unsigned char unk48;
    void __thiscall ReleaseSemaphoreAndIncrement();
};

// If unk48 is set, releases one count on the semaphore at sub.unk34 and increments sub.unk30.
// @fnv 0x00ae78e0
void FUN_00ae78e0_Class::ReleaseSemaphoreAndIncrement()
{
    if (unk48 != 0)
    {
        SUB* v = &sub;
        ReleaseSemaphore(v->unk34, 1, 0);
        InterlockedIncrement(&v->unk30);
    }
}

namespace fnv_0043fc40 {
struct FUN_0043fcd0_t
{
    NiAVObject* TESObjectREFR_Get3D();
};

class FUN_00565210_shell
{
  public:
    void TESObjectREFR_SetHasTemp3D(bool);
};
struct FUN_00570f70_t
{
    void TESObjectREFR_Set3DSimple(const char*);
};
struct FUN_00451ef0_t
{
    void TES_AttachModel(TESObjectREFR*, int, int, int);
};
extern int g_TES;
bool __fastcall BSTask_int64_GetTaskCanceled(int*);

class FUN_0043fc40_t
{
  public:
    char _pad[0x18];
    TESObjectREFR* m_pReference;
    BSStringT<char> m_kName;
    void AttachDistant3DTask_PostProcess();
};

// @fnv 0x0043fc40
// src: XBOX_PDB 0x0043fc40
void FUN_0043fc40_t::AttachDistant3DTask_PostProcess()
{
    if (!BSTask_int64_GetTaskCanceled((int*)this) && m_pReference && !((FUN_0043fcd0_t*)m_pReference)->TESObjectREFR_Get3D())
    {
        ((FUN_00570f70_t*)m_pReference)->TESObjectREFR_Set3DSimple(m_kName);
        ((FUN_00451ef0_t*)g_TES)->TES_AttachModel(m_pReference, ((BSOcclusionPlane*)m_pReference)->GetCullResult(), 0, 0);
        ((FUN_00565210_shell*)m_pReference)->TESObjectREFR_SetHasTemp3D(true);
    }
    else
    {
        *(NiPointer<NiNode>*)&m_kName = (NiNode*)0;
    }
}
}  // namespace fnv_0043fc40

// DestroyAllStreams
struct MyAVObject : NiAVObject
{
    bool IsPowerAttack_005f26c0();
};

struct ModelEntry
{
    int unk04;
    int unk08;
    int GetCombinedValue();
    ~ModelEntry();
};

struct KFModelEntry
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int KFModel_GetRefCount();
    MyAVObject* GetNode();
    ~KFModelEntry();
};

__declspec(align(4)) struct IterA
{
    int f00, f01, f02, f03, f04, f05, f06, f07, f08, f09;
    int f10, f11, f12, f13, f14, f15, f16, f17, f18, f19;
    int f20, f21, f22, f23, f24, f25, f26, f27, f28, f29;
    int f30, f31, f32, f33, f34, f35, f36, f37, f38, f39;
    int f40, f41, f42, f43, f44, f45, f46, f47, f48, f49;
    int f50, f51, f52, f53, f54, f55, f56, f57, f58, f59;
    int f60, f61, f62, f63, f64, f65, f66, f67, f68;
    IterA();
    ~IterA();
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
};

__declspec(align(4)) struct IterB
{
    void* vtable;
    int unk04;
    char* pathPtr;
    int unk0c;
    char path[260];
    IterB();
    ~IterB();
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
};

struct StreamObj
{
    virtual ~StreamObj();
    virtual void reservedA();
    virtual void reservedB();
    virtual void reservedC();
    virtual void reservedD();
    virtual void* processEntry(int);
    virtual void reservedE();
    virtual void reservedF();
    virtual void reservedG();
    virtual void reservedH();
    virtual void reservedI();
    virtual void reservedJ();
    virtual void reservedK();
    virtual void reservedL();
    virtual void reservedM();
    virtual void reservedN();
    virtual void reservedO();
    virtual int queryGate();
    bool TryGetNextEntry(void*, int*, void*, int);
};

void __cdecl _FNV_Warning(const char*, ...);
extern const char DAT_01016ea0[];
extern const char DAT_01016e70[];

struct Self
{
    StreamObj* m_00;
    StreamObj* m_04;
    StreamObj* m_08;
    StreamObj* m_0c;
    StreamObj* m_10;
    StreamObj* m_14;
    StreamObj* m_18;
    StreamObj* m_1c;
    StreamObj* m_20;
    StreamObj* m_24;
    StreamObj* m_28;
    void ModelLoader_OutputModelMapContents(int, int);
    void DestroyAllStreams();
};

// Clears both stream tables, warns about leftover entries, then deletes all stream objects held by the Self.
// @fnv 0x00442aa0
void Self::DestroyAllStreams()
{
    ModelLoader_OutputModelMapContents(0, 0);
    if (m_00->queryGate())
    {
        unsigned int a_count = 0;
        IterA m_iter;
        while (!m_iter.LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
        {
            int o = 0;
            ModelEntry* e = 0;
            if (m_00->TryGetNextEntry(&m_iter, &o, &e, 1))
            {
                if (e->GetCombinedValue() > 0)
                    a_count++;
                delete e;
            }
        }
        if (a_count > 0)
            _FNV_Warning(DAT_01016ea0, a_count);
    }

    IterB iterB;
    while (!iterB.LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
    {
        int c = 0;
        KFModelEntry* t = 0;
        if (m_04->TryGetNextEntry(&iterB, &c, &t, 1) && t)
        {
            if (!t->GetNode() || t->GetNode()->IsPowerAttack_005f26c0())
            {
                m_04->processEntry(c);
                delete t;
            }
        }
    }

    if (m_04->queryGate())
    {
        unsigned int countC = 0;
        IterB iterC;
        while (!iterC.LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
        {
            int c1 = 0;
            KFModelEntry* c2 = 0;
            if (m_04->TryGetNextEntry(&iterC, &c1, &c2, 1))
            {
                if (c2->KFModel_GetRefCount() > 0)
                    countC++;
                delete c2;
            }
        }
        if (countC > 0)
            _FNV_Warning(DAT_01016e70, countC);
    }

    delete m_00;
    delete m_04;
    delete m_1c;
    delete m_18;
    delete m_14;
    delete m_10;
    delete m_08;
    delete m_0c;
    delete m_28;
    delete m_20;
    delete m_24;
}

namespace fnv_0043d180 {
extern "C" char DAT_01016840;
extern "C" char DAT_011c63cc;
extern "C" char DAT_011c3be4;
extern "C" char DAT_011c3bb8;
extern "C" char DAT_011c3b3c;
struct Guard43
{
    int x;
    Guard43(int, bool, char*, int);
    ~Guard43();
};
struct Update43
{
    int data[3];
    void FUN_0043d410(float, bool, bool);
};
struct Bound43
{
    float FUN_0084d030();
};
struct Fade43
{
    void NiAVObject_Update(const Update43&);
    Bound43& NiAVObject_GetWorldBound();
    void FUN_00b4dfd0(float, float);
    void BSFadeNode_SetLODMultType(int);
};
struct Obj43
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Fade43* v4();
};
struct Model43
{
    void Model_IncManualRefCount();
    Obj43* NiObjectNET_GetControllers();
};
struct Ptr43
{
    Model43* Modelloader_GetReferencedThis();
};
// Returns a NiPoint3 by value (hidden result pointer first, as the original pushes it).
NiPoint3 __cdecl TESObjectREFR_GetBoundMax(Obj43*);
struct Loader43
{
    unsigned char CallFoo(int, Model43*);
    void ModelLoader_FindModel(int, Ptr43&);
};
struct C43
{
    char pad[24];
    int field18;
    char pad1[20];
    Ptr43 ptr;
    int field34;
    int field38;
    bool QueuedModel_GetAddRefCount();
    bool QueuedModel_GetCachedModel();
    float QueuedModel_GetOverriddenVisualDistance();
    int FUN_0045cd60();
    void RunVirtualMethod28();
    void QueuedModel_Finish();
};
// Updates the fade node of the model's object: recomputes range from settings and radius, applies fade and field38, and reloads the model if needed.
// @fnv 0x0043d180
// src: XBOX_PDB 0x0043d180
void C43::QueuedModel_Finish()
{
    Guard43 guard(field18, true, &DAT_01016840, 997);
    if (ptr.Modelloader_GetReferencedThis())
    {
        if (QueuedModel_GetAddRefCount())
            ptr.Modelloader_GetReferencedThis()->Model_IncManualRefCount();
        if (!QueuedModel_GetCachedModel() && ptr.Modelloader_GetReferencedThis()->NiObjectNET_GetControllers())
        {
            Fade43* node2 = ptr.Modelloader_GetReferencedThis()->NiObjectNET_GetControllers()->v4();
            if (node2)
            {
                Update43 update4;
                update4.FUN_0043d410(0.0f, false, false);
                node2->NiAVObject_Update(update4);
                float radius = node2->NiAVObject_GetWorldBound().FUN_0084d030();
                if (radius < 0.0010000000474974513)
                    radius = TESObjectREFR_GetBoundMax(ptr.Modelloader_GetReferencedThis()->NiObjectNET_GetControllers()).z * 0.5;
                float maximum = 3.402823466e+38f;
                maximum = (*reinterpret_cast<unsigned int*>(reinterpret_cast<Setting*>(&DAT_011c63cc)->Setting_Int()) << 12) * 0.5 - (radius + 2048.0);
                float scaled5 = radius * *((Setting*)&DAT_011c3be4)->Setting_Float_00403e20();
                float range = radius != 0.0 && scaled5 < maximum ? scaled5 : maximum;
                if (QueuedModel_GetOverriddenVisualDistance() != 0.0)
                    range = QueuedModel_GetOverriddenVisualDistance();
                node2->FUN_00b4dfd0(range * *((Setting*)&DAT_011c3bb8)->Setting_Float_00403e20(), range);
                node2->BSFadeNode_SetLODMultType(field38);
            }
            if (!(*(Loader43**)&DAT_011c3b3c)->CallFoo(FUN_0045cd60(), ptr.Modelloader_GetReferencedThis()))
                (*(Loader43**)&DAT_011c3b3c)->ModelLoader_FindModel(FUN_0045cd60(), ptr);
        }
    }
    RunVirtualMethod28();
}
}  // namespace fnv_0043d180

class NodePointer
{
    NiNode* node;

  public:
    NodePointer(NiNode*);
    operator NiNode*() const;
    ~NodePointer();
};
class TextureTask : public QueuedFile
{
  public:
    unsigned int unk28;
    unsigned int unk2c;
    NiNode* model;
    bool loaded;
    TextureTask(BSFileEntry*, int);
    TextureTask(NiNode*, int);
    void SetParent(QueuedFile*);
};
class TextureTaskPointer
{
    TextureTask* task;

  public:
    TextureTaskPointer(TextureTask*);
    ~TextureTaskPointer();
    TextureTask* operator->() const;
};
class TextureNodeInfo
{
  public:
    int NiTexture_GetTextureQualityLevel();
};
void __cdecl GetNodePointer(BSFileEntry*, NodePointer&);
void* __cdecl operator new(unsigned int);
class TextureLoader
{
  public:
    bool IsLoadTexturesDegraded();
    bool ModelLoader_ReuseQueuedTexture(BSFileEntry*, int, QueuedFile*);
    bool QueueTextureLoad(BSFileEntry*, int, QueuedFile*);
};
// Loads the file's node; if it is a usable model it queues a TextureTask for the node, otherwise falls back to FUN_00443540 or queues a TextureTask for the file.
// @fnv 0x00443af0
bool TextureLoader::QueueTextureLoad(BSFileEntry* file, int priority, QueuedFile* parent)
{
    NodePointer node(0);
    GetNodePointer(file, node);
    if ((NiNode*)node)
    {
        bool skip = false;
        if (((TextureNodeInfo*)(NiNode*)node)->NiTexture_GetTextureQualityLevel() == 3 && !IsLoadTexturesDegraded())
            skip = true;
        if (!skip)
        {
            if (parent)
            {
                TextureTaskPointer request(new TextureTask((NiNode*)node, priority));
                request->SetParent(parent);
                request->OnChildCompletion();
                return true;
            }
            return false;
        }
    }
    if (ModelLoader_ReuseQueuedTexture(file, priority, parent))
        return true;
    TextureTaskPointer request(new TextureTask(file, priority));
    request->SetParent(parent);
    request->DispatchToManager();
    return true;
}

namespace fnv_00443dc0 {
class QHeadLocal
{
  public:
    void ActorCause_IncRefCount();
};

class QNewFile;

using ::NiPointer;

class QueueObj
{
  public:
    virtual void d0();
    virtual void d4();
    virtual void d8();
    virtual void dc();
    virtual void d10();
    virtual void* d14(QHeadLocal** out);
    void FUN_0092c820(NiPointer<QNewFile>& p);
    void AssignTaskReference(QNewFile* p);
};

class QHolderObj
{
  public:
    virtual void h0();
    virtual void h4();
    virtual bool h8(void* arg);
};

class QNewFile
{
  public:
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
    QNewFile(QHeadLocal* p, int a);
    QNewFile(void* p, int a, int b, bool c, bool d);
    void TESQuest_SetScriptProcessingDelay(float f);
    void SetParent(QNewFile* p);
    void QueuedModel_SetFaceGenModel(unsigned char b);
    char pad[0x44];
};

class QueueModelHolder
{
  public:
    QHolderObj* m_pHolder;
    void ModelLoader_QueueModel_00443dc0(int a1, QueueObj* a2, int a3, int a4, int a5, bool a6, bool a7, bool a8, float a9);
};

// @fnv 0x00443dc0
// src: XBOX_PDB 0x00443dc0
void QueueModelHolder::ModelLoader_QueueModel_00443dc0(int pQueueObj, QueueObj* a2, int a3, int pParent, int a5, bool bFlag1, bool bFlag2,
                                    bool bFlag3, float fValue)
{
    QHeadLocal* pHead = 0;
    if (m_pHolder->h8(((QueueObj*)pQueueObj)->d14(&pHead)))
    {
        if (bFlag2)
        {
            pHead->ActorCause_IncRefCount();
        }
        if (pParent)
        {
            NiPointer<QNewFile> sp(new QNewFile(pHead, a3));
            ((QNewFile*)sp)->TESQuest_SetScriptProcessingDelay(fValue);
            ((QNewFile*)sp)->SetParent((QNewFile*)pParent);
            ((QNewFile*)sp)->v28();
            a2->FUN_0092c820(sp);
            return;
        }
        a2->AssignTaskReference(0);
        return;
    }
    NiPointer<QNewFile> sp(new QNewFile((void*)pQueueObj, a3, a5, bFlag1, bFlag2));
    ((QNewFile*)sp)->TESQuest_SetScriptProcessingDelay(fValue);
    ((QNewFile*)sp)->SetParent((QNewFile*)pParent);
    ((QNewFile*)sp)->QueuedModel_SetFaceGenModel(bFlag3);
    ((QNewFile*)sp)->v20();
    a2->FUN_0092c820(sp);
}
}  // namespace fnv_00443dc0

namespace fnv_00448080 {
extern "C" char DAT_01016fac;
struct Task448
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    void FUN_00443aa0(void*);
    Task448(void*, void*);
    char data[60];
};
struct Ref448
{
    void* p;
    Ref448(int);
    ~Ref448();
    void* Modelloader_GetReferencedThis();
};
struct RefB448
{
    void* p;
    RefB448(int);
    ~RefB448();
    void* Modelloader_GetReferencedThis();
};
struct String448
{
    void* p;
    int n;
    String448();
    ~String448();
    void* Modelloader_GetReferencedThis();
};
struct Head448
{
    void* p;
    Head448(Task448*);
    ~Head448();
    Task448* Modelloader_GetReferencedThis();
};
struct Manager448
{
    bool LookupModelAndGetFlags(void*, Ref448*, RefB448*);
};
Manager448* FUN_00652110();
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_00406d50(char*, unsigned int, const char*);
void BuildEgmFilename(String448*, char*, int);
void BuildTriPathAndSet(String448*, char*, int);
struct Owner448
{
    void ModelLoader_QueueFaceGenFile(void*, int, void*, int);
    void LoadTaskFromPath(Task448*, int, void*, int);
};
// @fnv 0x00448080
void Owner448::LoadTaskFromPath(Task448* pTask, int x, void* parent, int unused)
{
    Ref448 a(0);
    RefB448 b(0);
    char pathX[260];
    FUN_00406d30(pathX, 260, &DAT_01016fac);
    FUN_00406d50(pathX, 260, pTask->v5());
    String448 s3;
    BuildEgmFilename(&s3, pathX, -1);
    if (FUN_00652110() && FUN_00652110()->LookupModelAndGetFlags(s3.Modelloader_GetReferencedThis(), &a, &b) && a.Modelloader_GetReferencedThis() &&
        b.Modelloader_GetReferencedThis())
    {
        if (parent)
        {
            Head448 h3(new Task448(a.Modelloader_GetReferencedThis(), b.Modelloader_GetReferencedThis()));
            h3.Modelloader_GetReferencedThis()->FUN_00443aa0(parent);
            h3.Modelloader_GetReferencedThis()->v10();
        }
        return;
    }
    String448 t2;
    BuildTriPathAndSet(&t2, pathX, -1);
    ModelLoader_QueueFaceGenFile(t2.Modelloader_GetReferencedThis(), x, parent, 1);
}
}  // namespace fnv_00448080

namespace fnv_00448620 {
struct FUN_0045585e0_t;
struct FUN_004498e0_t;
struct FUN_00449960_t;

struct FUN_00443190_t
{
    ~FUN_00443190_t();
    int GetCombinedValue();
};
struct FUN_004431b0_t
{
    ~FUN_004431b0_t();
    int KFModel_GetRefCount();
    FUN_0045585e0_t* GetSkinData();
};
struct FUN_0045585e0_t
{
    int GetType();
};

struct FUN_0044c640_host
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
    bool TryGetNextEntry(FUN_004498e0_t*, int*, FUN_00443190_t**, int);
    bool TryGetNextEntry(FUN_00449960_t*, int*, FUN_004431b0_t**, int);
};

struct FUN_0042ce10_t
{
    bool BGSSaveLoadGame_GetSaveGameLoading();
};

struct FUN_004498e0_t
{
    FUN_004498e0_t();
    ~FUN_004498e0_t();
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
    char pad[0x10c];
};

struct FUN_00449960_t
{
    FUN_00449960_t();
    ~FUN_00449960_t();
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
    char pad[0x110];
};

extern "C" FUN_0042ce10_t* DAT_011ddf38;

struct FUN_00448620_cls
{
    FUN_0044c640_host* p0;
    FUN_0044c640_host* p4;
    char pad[0x24];
    bool b2c;
    void ModelLoader_ClearUnusedModels(bool);
};

// @fnv 0x00448620
// src: XBOX_PDB 0x00448620
void FUN_00448620_cls::ModelLoader_ClearUnusedModels(bool b)
{
    if (!b && DAT_011ddf38 != 0 && DAT_011ddf38->BGSSaveLoadGame_GetSaveGameLoading())
    {
        b2c = true;
        return;
    }
    if (p0 != 0)
    {
        FUN_004498e0_t entryA;
        while (!entryA.LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
        {
            FUN_00443190_t* v12c = 0;
            int v128 = 0;
            if (p0->TryGetNextEntry(&entryA, &v128, &v12c, 1) && v12c != 0 && !v12c->GetCombinedValue())
            {
                p0->v5(v128);
                delete v12c;
            }
        }
    }
    if (p4 != 0)
    {
        FUN_00449960_t entryB;
        while (!entryB.LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
        {
            FUN_004431b0_t* pEntryB = 0;
            int iIndexB = 0;
            if (p4->TryGetNextEntry(&entryB, &iIndexB, &pEntryB, 1) && pEntryB != 0 && !pEntryB->KFModel_GetRefCount())
            {
                bool bRemovable = true;
                if (pEntryB->GetSkinData() != 0 && pEntryB->GetSkinData()->GetType() >= 0x5c &&
                    pEntryB->GetSkinData()->GetType() < 0x66)
                    bRemovable = false;
                if (bRemovable)
                {
                    p4->v5(iIndexB);
                    delete pEntryB;
                }
            }
        }
    }
    b2c = false;
}
}  // namespace fnv_00448620

namespace fnv_004436c0 {
struct NiObjQ
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
    void FUN_00443aa0(void* p);
    int NiTexture_GetTextureQualityLevel();
};
struct SPBaseQ
{
    NiObjQ* m_p;
    NiObjQ* Modelloader_GetReferencedThis();
};
struct FUN_00633c90 : SPBaseQ
{
    FUN_00633c90(NiObjQ* p);
    ~FUN_00633c90();
};
struct FUN_00528cb0 : SPBaseQ
{
    FUN_00528cb0(NiObjQ* p);
    ~FUN_00528cb0();
    FUN_00528cb0& AssignTaskReference(NiObjQ* p);
};
struct FUN_0043bef0 : NiObjQ
{
    char pad[0x34];
    FUN_0043bef0(NiObjQ* p, void* q);
};
struct FUN_0043be60 : NiObjQ
{
    char pad[0x34];
    FUN_0043be60(void* p, void* q);
};
struct FUN_0043bd10 : NiObjQ
{
    char pad[0x34];
    FUN_0043bd10(const char* p, void* q);
};
struct FUN_006815c0
{
    int m0, m4;
    FUN_006815c0();
};
void __cdecl FindTextureByPath(const char* s, FUN_00633c90* p);
void __cdecl FUN_00af4200(const char* s, char* buf, unsigned int n);
void __cdecl HashPathComponents(char* buf, FUN_006815c0* a, FUN_006815c0* b);
void* __cdecl FindFileEntryInArchives(int n, FUN_006815c0* a, FUN_006815c0* b, char* buf);
class FUN_004436c0_Class
{
  public:
    bool IsLoadTexturesDegraded();
    bool ModelLoader_ReuseQueuedTexture(void* p, void* q, void* r);
    bool LoadTexture(const char* pcName, void* p2, void* p3);
};
// Looks up pcName, then either configures a found object or searches archives and constructs another object.
// @fnv 0x004436c0
bool FUN_004436c0_Class::LoadTexture(const char* pcName, void* p2, void* p3)
{
    FUN_00633c90 spA5(0);
    FindTextureByPath(pcName, &spA5);
    if (spA5.Modelloader_GetReferencedThis())
    {
        bool bSkip = false;
        if (spA5.Modelloader_GetReferencedThis()->NiTexture_GetTextureQualityLevel() == 3 && !IsLoadTexturesDegraded())
            bSkip = true;
        if (!bSkip)
        {
            if (p3)
            {
                FUN_00528cb0 spB4(new FUN_0043bef0(spA5.Modelloader_GetReferencedThis(), p2));
                spB4.Modelloader_GetReferencedThis()->FUN_00443aa0(p3);
                spB4.Modelloader_GetReferencedThis()->v28();
                return true;
            }
            return false;
        }
    }
    char acPath7[0x104];
    FUN_00af4200(pcName, acPath7, 0x104);
    FUN_006815c0 kA;
    FUN_006815c0 kB;
    HashPathComponents(acPath7, &kA, &kB);
    void* pRes_ = FindFileEntryInArchives(1, &kA, &kB, acPath7);
    if (pRes_ && ModelLoader_ReuseQueuedTexture(pRes_, p2, p3))
        return true;
    FUN_00528cb0 spC4(0);
    if (pRes_)
    {
        spC4.AssignTaskReference(new FUN_0043be60(pRes_, p2));
        reinterpret_cast<QueuedFileEntry*>(spC4.Modelloader_GetReferencedThis())->SetFileName_00c3cee0(acPath7);
    }
    else
    {
        spC4.AssignTaskReference(new FUN_0043bd10(pcName, p2));
    }
    spC4.Modelloader_GetReferencedThis()->FUN_00443aa0(p3);
    spC4.Modelloader_GetReferencedThis()->v20();
    return true;
}
}  // namespace fnv_004436c0

namespace fnv_00447980 {
struct QIdle
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Run();
};
class QIdlePtr
{
  public:
    QIdlePtr(QIdle* p);
    ~QIdlePtr();
    operator QIdle*() const;
    QIdle* m_p;
};
class FUN_0043d540 : public QIdle
{
  public:
    FUN_0043d540(int a, int b, int c);
    void* operator new(unsigned int);
    unsigned int unk[15];
};
class OwnerX
{
  public:
    void RunIdleTask(int a, int c);
};
// Creates a FUN_0043d540 idle task with the given parameters and immediately runs it via QIdle::Run.
// @fnv 0x00447980
void OwnerX::RunIdleTask(int aiParam1, int aiParam3)
{
    QIdlePtr spIdle(new FUN_0043d540(aiParam1, 4, aiParam3));
    ((QIdle*)spIdle)->Run();
}
}  // namespace fnv_00447980

namespace fnv_004492f0 {

template <class T> unsigned int BSStringLength(const T* p);
extern "C" int __cdecl tolower(int);
class StrMapX
{
  public:
    char* GetLowercaseKey(const char* pKey);
};
// Allocates and returns a lowercase copy of pKey while an AutoMemContext is active.
// @fnv 0x004492f0
char* StrMapX::GetLowercaseKey(const char* pKey)
{
    AutoMemContext kContext(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h",
                            0x1fd);
    char* pCopy = new char[BSStringLength(pKey) + 1];
    char* pDst = pCopy;
    while (*pKey)
    {
        *pDst++ = tolower(*pKey++);
    }
    *pDst = 0;
    return pCopy;
}
}  // namespace fnv_004492f0

struct NodeX;
struct PtrX
{
    void AssignTaskReference(void* p);
    void FUN_0092c820(PtrX* p);
};
struct NodeX
{
    NodeX* m_pkNext;
    PtrX m_kData;
};
struct ListX
{
    virtual void v0(), v4(), v8();
    virtual void Vc();
    NodeX* m_pkHead;
    NodeX* m_pkTail;
};
bool CompareAndSwapEx(NodeX** ppkDest, NodeX* pkNew, NodeX* pkCmp);
struct QueueX
{
    ListX* m_pkList;
    NodeX** m_ppkHazard0;
    NodeX** m_ppkHazard1;
    void LockFreeQueue_Interface_NiPointer_IOTask_DeleteNode(NodeX* pkNode);
    bool Pop(PtrX& kOut);
};
// Atomically removes the head node from the lock-free list, copies its data into kOut, and returns false when the queue is empty.
// @fnv 0x0044cec0
bool QueueX::Pop(PtrX& kOut)
{
    NodeX* volatile pkHead = 0;
    while (true)
    {
        pkHead = m_pkList->m_pkHead;
        *m_ppkHazard0 = pkHead;
        if (pkHead != m_pkList->m_pkHead)
            continue;
        NodeX* pkTail = m_pkList->m_pkTail;
        NodeX* volatile pkNext = pkHead->m_pkNext;
        *m_ppkHazard1 = pkNext;
        if (pkHead != m_pkList->m_pkHead)
            continue;
        if (!pkNext)
        {
            *m_ppkHazard0 = 0;
            kOut.AssignTaskReference(0);
            return false;
        }
        if (pkHead == pkTail)
        {
            CompareAndSwapEx(&m_pkList->m_pkTail, pkNext, pkTail);
            continue;
        }
        kOut.FUN_0092c820(&pkNext->m_kData);
        if (CompareAndSwapEx(&m_pkList->m_pkHead, pkNext, pkHead))
        {
            m_pkList->Vc();
            pkNext->m_kData.AssignTaskReference(0);
            break;
        }
    }
    *m_ppkHazard0 = 0;
    *m_ppkHazard1 = 0;
    LockFreeQueue_Interface_NiPointer_IOTask_DeleteNode(pkHead);
    return true;
}

struct Item44F950;
struct Node44F950
{
    Item44F950* m_item;
    Node44F950* m_pkNext;
    Item44F950*& GetItem();
};
class Owner44F950
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual bool CheckItem(Item44F950* pkItem);
    bool BaseCheck();
    Node44F950* GetHead();
    Node44F950* GetNext(Node44F950* pkNode);
    bool CheckAllItems();
};

// Returns true if BaseCheck passes and every item in the linked list of nodes passes CheckItem.
// @fnv 0x0044f950
bool Owner44F950::CheckAllItems()
{
    bool bResult = BaseCheck();
    if (bResult)
    {
        Node44F950* pkNode = GetHead();
        while (pkNode)
        {
            bResult &= CheckItem(pkNode->GetItem());
            pkNode = GetNext(pkNode);
        }
    }
    return bResult;
}

class QIdle;

class QIdleRef
{
  public:
    QIdle* m_pObject;
    QIdleRef(QIdle* object);
    ~QIdleRef();
};

class QIdleBase
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    char pad[0x34];
    QIdleBase(void* first, int second);
    ~QIdleBase();
};

struct FUN_0043e580 : QIdleBase
{
    virtual void v00();
    virtual void v04();
    void* m_38;
    QIdleRef m_3c;

    FUN_0043e580(void* first, int second, QIdle* third, void* fourth);
};

// Initializes QIdleBase from first and second, then m_38 from fourth and m_3c from third.
// @fnv 0x0043e580
FUN_0043e580::FUN_0043e580(void* apBase, int second, QIdle* apIdle, void* fourth)
    : QIdleBase(apBase, second), m_38(fourth), m_3c(apIdle)
{}

class BaseTaskMgr
{
  public:
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
    ~BaseTaskMgr();
};

struct ElemA
{
    int unk00;
    ~ElemA();
};

struct ElemB
{
    int unk00;
    ~ElemB();
};

class LoaderMgr : public BaseTaskMgr
{
  public:
    ElemA unk2C[20];
    ElemB unk7C[20];
    ElemB unkCC[20];
    ~LoaderMgr();
};

// @fnv 0x0043f080
LoaderMgr::~LoaderMgr()
{}

namespace fnv_00440640 {
struct FUN_00449a20_cls
{
    void DoNothing_004490e0();
    void ForwardCall_00440640();
};

// src: GUESS 0x004490e0 (confidence: high)
void FUN_00449a20_cls::DoNothing_004490e0()
{}

// @fnv 0x00440640
// src: GUESS 0x00440640 (confidence: low)
void FUN_00449a20_cls::ForwardCall_00440640()
{
    DoNothing_004490e0();
}
}  // namespace fnv_00440640

#include <ctype.h>
struct LockFreeCaseInsensitiveStringMap_t
{
    void LockFreeMap_char_const_T_Data_Lookup(const char* apKey, void* apValue);
    void LockFreeCaseInsensitiveStringMap_Model_GetAt(const char* apKey, void* apValue);
};
// Lowercases apKey into acLowerKey and calls FUN_00449530 with the lowercased key and apValue.
// @fnv 0x004493d0
// src: COMMUNITY 0x004493d0
void LockFreeCaseInsensitiveStringMap_t::LockFreeCaseInsensitiveStringMap_Model_GetAt(const char* apKey, void* apValue)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    LockFreeMap_char_const_T_Data_Lookup(acLowerKey, apValue);
}

namespace fnv_00449460 {
struct LockFreeCaseInsensitiveStringMap_t
{
    void LockFreeMap_char_const_T_Data_SetAtAlt(const char* apKey, void* apValue, bool abFlag);
    void LockFreeCaseInsensitiveStringMap_Model_SetAtAlt(const char* apKey, void* apValue, bool abFlag);
};
// Lowercases apKey into a 1000-byte buffer and forwards it with apValue and abFlag to FUN_00449580.
// @fnv 0x00449460
// src: COMMUNITY 0x00449460
void LockFreeCaseInsensitiveStringMap_t::LockFreeCaseInsensitiveStringMap_Model_SetAtAlt(const char* apKey, void* apValue, bool abFlag)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    LockFreeMap_char_const_T_Data_SetAtAlt(acLowerKey, apValue, abFlag);
}
}  // namespace fnv_00449460

namespace fnv_00449750 {
struct LockFreeCaseInsensitiveStringMap_t
{
    unsigned int FUN_0044ddc0();
    unsigned int GetBucketIndex(const char* apKey);
};
// Computes a case-insensitive hash of apKey and returns it modulo the table size from FUN_0044ddc0.
// @fnv 0x00449750
unsigned int LockFreeCaseInsensitiveStringMap_t::GetBucketIndex(const char* apKey)
{
    unsigned int uiHash = 0;
    while (*apKey)
    {
        uiHash = (uiHash << 5) + uiHash + tolower(*apKey++);
    }
    return uiHash % FUN_0044ddc0();
}
}  // namespace fnv_00449750

namespace fnv_004497f0 {
struct LockFreeCaseInsensitiveStringMap_t
{
    void LockFreeMap_char_const_T_Data_RemoveAt(const char* apKey);
    void LockFreeCaseInsensitiveStringMap_Model_RemoveAt(const char* apKey);
};
// Lowercases apKey into acLowerKey and calls FUN_004495d0 with the lowercased key.
// @fnv 0x004497f0
// src: COMMUNITY 0x004497f0
void LockFreeCaseInsensitiveStringMap_t::LockFreeCaseInsensitiveStringMap_Model_RemoveAt(const char* apKey)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    LockFreeMap_char_const_T_Data_RemoveAt(acLowerKey);
}
}  // namespace fnv_004497f0

namespace reference_queue_types {
namespace FUN_00528cb0 {
struct FUN_0044cbf0
{
    void* p;
    FUN_0044cbf0(void*);
    ~FUN_0044cbf0();
};
}
}

struct FUN_00445750_map
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(void* r, reference_queue_types::FUN_00528cb0::FUN_0044cbf0* out);
};

struct FUN_00445750_arg
{
    void* r;
};

// @fnv 0x00445750
// @fnv 0x00445750
// src: XBOX_PDB 0x00445750
bool __fastcall ModelLoader_IsReferenceQueued(char* this_ptr, FUN_00445750_arg a)
{
    reference_queue_types::FUN_00528cb0::FUN_0044cbf0 g(0);
    return (*(FUN_00445750_map**)(this_ptr + 8))->Lookup(a.r, &g);
}

// HighProcess_MLd model-file loader
extern "C" unsigned int __BSStringLength(const char*);
extern "C" void ref_005b5e40(const char*, ...);
extern "C" int DAT_011f94c0;
extern "C" const char DAT_01016840[];
extern "C" const char DAT_010168c4[];
extern "C" const char DAT_010168ec[];
extern "C" const char DAT_010168f4[];

class NiPointerShell_MLd
{
  public:
    unsigned int _ref_00726070();
};

struct Blob16
{
    int a, b, c, d;
};
struct Blob64
{
    Blob16 a, b, c, d;
};
struct Blob256
{
    Blob64 a, b, c, d;
};
struct Blob1024
{
    Blob256 a, b, c, d;
};
struct Blob1488
{
    Blob1024 a;
    Blob256 b;
    Blob64 c, d, e;
    Blob16 f;
};

class HighProcess_MLd
{
  public:
    int GetProcessLevel();
};

class SetterHelper_MLd
{
  public:
    void FUN_0044aed0(void*);
};


extern ModelLoader* g_pModelLoader;

class FUN_0043ccf0_shell
{
  public:
    void QueuedModel_Run();
    char m_uiStandInValue[0x18];
    int m_field18;
    char m_iValueAfterStandIn[0x14];
    int m_model30;
};

// Loads the named model, checks the pointer at offset 0x30, then tries stream loading and may assign a new Model.
// @fnv 0x0043ccf0
// src: XBOX_PDB 0x0043ccf0
void FUN_0043ccf0_shell::QueuedModel_Run()
{
    AutoMemHelper mem5(m_field18, 1, DAT_01016840, 0x3b8);

    if (__BSStringLength((const char*)((HighProcess_MLd*)this)->GetProcessLevel()) > 0)
    {
        g_pModelLoader->LoadModel((const char*)((HighProcess_MLd*)this)->GetProcessLevel(),
                                  *(NiPointer<Model>*)&m_model30);
        if (((NiPointerShell_MLd*)((char*)this + 0x30))->_ref_00726070() != 0)
        {
            ((FUN_0043cf60_shell*)this)->QueuedModel_SetAlreadyInModelMap(true);
            return;
        }

        void* pFile5 = reinterpret_cast<QueuedFileEntry*>(this)->GetFile(0, true);
        BSStream stream;

        DAT_011f94c0 = ((HighProcess_MLd*)this)->GetProcessLevel();

        if ((pFile5 != 0 && ((NiStream*)&stream)
                                ->BSStream_Load((const char*)((HighProcess_MLd*)this)->GetProcessLevel(), (BSFile*)pFile5)) ||
            ((FUN_0043cf90_shell*)this)->QueuedModel_GetForceLoad())
        {
            ((SetterHelper_MLd*)((char*)this + 0x30))
                ->FUN_0044aed0(new Model((const char*)((HighProcess_MLd*)this)->GetProcessLevel(), (BSStream*)&stream,
                                         ((FUN_0043cf40_shell*)this)->QueuedModel_GetPrepareAfterLoad(),
                                         ((FUN_0043cfb0_shell*)this)->QueuedModel_GetFaceGenModel()));
        }
        else
        {
            ref_005b5e40(DAT_010168c4, pFile5 ? DAT_010168f4 : DAT_010168ec,
                         (const char*)((HighProcess_MLd*)this)->GetProcessLevel());
        }

        DAT_011f94c0 = 0;
    }
}

__if_not_exists(WaitForSingleObject)
{
    extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
}

__if_not_exists(FinishScriptRunLock)
{
    void FinishScriptRunLock(void*);
}

class SemaphoreFields
{
  public:
    void* unk00;
    void* m_pSemaphore;
};

struct SemaphoreWaitReceiver
{
    void BSSemaphore_Wait();
};

// Blocks indefinitely on m_pSemaphore via WaitForSingleObject, then releases the script run lock with FinishScriptRunLock.
// @fnv 0x004424e0
// src: COMMUNITY 0x004424e0
void SemaphoreWaitReceiver::BSSemaphore_Wait()
{
    WaitForSingleObject(((SemaphoreFields*)this)->m_pSemaphore, 0xffffffffUL);
    FinishScriptRunLock(this);
}

class FUN_00c3b970_cls
{
  public:
    NiRefObject* m_pReferencedObject;

    FUN_00c3b970_cls& AssignReferencedObject(NiRefObject* obj);
};

// Swaps the referenced object, releasing the old reference and acquiring a new one when the pointer changes.
// @fnv 0x00c3b970
// src: GUESS 0x00c3b970 (confidence: high)
FUN_00c3b970_cls& FUN_00c3b970_cls::AssignReferencedObject(NiRefObject* apRefObject)
{
    NiRefObject* pOldRefObject;
    NiRefObject* pNewRefObject;
    if (m_pReferencedObject != apRefObject)
    {
        if (m_pReferencedObject != 0)
        {
            pOldRefObject = m_pReferencedObject;
            if (InterlockedDecrement((volatile long*)&pOldRefObject->m_uiRefCount) == 0)
            {
                pOldRefObject->DeleteThis();
            }
        }
        m_pReferencedObject = apRefObject;
        if (m_pReferencedObject != 0)
        {
            pNewRefObject = m_pReferencedObject;
            InterlockedIncrement((long*)&pNewRefObject->m_uiRefCount);
        }
    }
    return *this;
}

NiNode* __fastcall FUN_0059bb30(NiAVObject* object);

struct ParentByteQuery : NiAVObject
{

    int NiTexture_GetTextureQualityLevel();
};

// Returns FUN_0043c470() on the parent returned by FUN_0059bb30, or 0 if no parent exists.
// @fnv 0x0043c430
// src: COMMUNITY 0x0043c430
int ParentByteQuery::NiTexture_GetTextureQualityLevel()

{

    return FUN_0059bb30(this) ? reinterpret_cast<NiAVObject*>(&FUN_0059bb30(this)->GetTranslate_0043c490())->EvaluateValue_0043c470() : 0;
}

struct CharacterClone : public QueuedCharacter
{
    void* cloneTarget;
    bool QueuedCharacter_BackgroundClone();
};

struct CloneObjectAccessor
{
    void* VATS_GetVATSLight();
};
void __fastcall AttachHeadAndFaceParts(void*);
struct Helper_00440a90
{
    bool QueuedReference_BackgroundClone();
};
void __cdecl TESObjectREFR_SetBackgroundLoadingRef(void*, void*);
void __cdecl TESObjectREFR_ClearBackgroundLoadingRef();

// Creates an AutoMemContext, checks a helper and clone accessor, then calls FUN_00441780, FUN_004418b0 and FUN_004417c0 when both checks pass.
// @fnv 0x004416c0
// src: XBOX_PDB 0x004416c0
bool CharacterClone::QueuedCharacter_BackgroundClone()
{
    AutoMemContext tempMemContext(
        aeMemoryContext, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8e4);
    bool bresult = ((Helper_00440a90*)this)->QueuedReference_BackgroundClone();
    if (bresult && ((CloneObjectAccessor*)this)->VATS_GetVATSLight())
    {
        TESObjectREFR_SetBackgroundLoadingRef(cloneTarget, ((CloneObjectAccessor*)this)->VATS_GetVATSLight());
        AttachHeadAndFaceParts(this);
        TESObjectREFR_ClearBackgroundLoadingRef();
    }
    return bresult;
}

struct LockedResult
{
    void Enqueue();
};

struct LockedReceiver
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    RecursiveSpinLock lock;
    LockedResult* LockFreeMap_GetInterface_0(void*);
};

struct ReceiverArgument
{
    void* value;
};

// Locks the receiver, calls FUN_0044cd40 on the result of FUN_00449f80 with argument.value, then unlocks the receiver.
// @fnv 0x00449240
// src: COMMUNITY 0x00449240
void __fastcall LockFreeQueue_NiPointer_IOTask_Push(LockedReceiver* receiver, ReceiverArgument argument)
{
    receiver->lock.Lock(0);
    receiver->LockFreeMap_GetInterface_0(argument.value)->Enqueue();
    receiver->lock.Unlock();
}

void _Deallocate(void*);

struct ModelLoaderDeleteEntry449 : public ModelLoader
{
    void* FUN_00449b40(unsigned int flags);
};

// Calls FUN_00443220, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00449b40
void* ModelLoaderDeleteEntry449::FUN_00449b40(unsigned int flags)
{
    this->ForwardCall_00443220();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
    unsigned int state;
};
struct CleanupReceiver
{
    void FUN_0065f240();
};
struct FUN_0044a040 : public FUN_0065cfb0
{
    ~FUN_0044a040();
};
// Calls FUN_0065f240 on the current object.
// @fnv 0x0044a040
FUN_0044a040::~FUN_0044a040()
{
    ((CleanupReceiver*)this)->FUN_0065f240();
}

// Implementations using the shared class declarations.
// @fnv 0x0043d820
// src: XBOX_PDB 0x0043d820
bool QueuedTreeBillboard::GetDescription_0043d820(char* apDescription, unsigned int aiBufferSize)
{
    return QueuedFileEntry_GetDescription(apDescription, aiBufferSize, "Tree Billboard");
}

// @fnv 0x0043d580
void* __thiscall QueuedTreeBillboard::FUN_0043d580(unsigned int flags)
{
    FUN_0043d5b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

// @fnv 0x0043ea00
// src: XBOX_PDB 0x0043ea00
bool __thiscall QueuedReplacementKF::GetDescription_0043ea00(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<QueuedFileEntry*>(this)->GetDescription(apDescription, aiBufferSize, "Replacement KF");
}

// @fnv 0x0043c6b0
// src: XBOX_PDB 0x0043c6b0
bool QueuedTreeModel::QueuedTexture_GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return QueuedFileEntry_GetDescription(apDescription, aiBufferSize, "texture");
}

// @fnv 0x0043d510
// src: XBOX_PDB 0x0043d510
bool QueuedTreeModel::QueuedModel_GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return QueuedFileEntry_GetDescription(apDescription, aiBufferSize, "model");
}

// @fnv 0x0043e550
// src: XBOX_PDB 0x0043e550
bool QueuedTreeModel::QueuedKF_GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return QueuedFileEntry_GetDescription(apDescription, aiBufferSize, "KF");
}

// @fnv 0x0043fc10
bool QueuedHelmet::FormatQueuedHelmetDescription(char* apDescription, unsigned int aiBufferSize)
{
    fnv_0043fc10::_sprintf_s(apDescription, aiBufferSize, "Queued helmet for biped anim %08X", pExistingBipedAnim);
    return true;
}

// @fnv 0x004412e0
void QueuedActor::QueueDismemberedLimbLoads()
{
    ExtraDismemberedLimbs* pextraLimbs;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8a2);
    Actor* pactor = *(Actor**)((char*)this + 0x28);
    pactor->AddDefaultSpells();
    pextraLimbs = fnv_004412e0::BSFile_GetDevice((TESObjectREFR*)pactor)->GetDismemberedLimbs();
    if (pextraLimbs)
    {
        IO_TASK_PRIORITY epriority = ((IOTask*)this)->IOTask_GetIOTaskPriority();
        for (unsigned int i = 0; i < ((fnv_004412e0::TESObjectREFR_GetFlags_Helper*)&pextraLimbs->parts)->CallGetFlags(); i++)
        {
            fnv_004412e0::DismembermentPart* pdismemberedLimb = reinterpret_cast<fnv_004412e0::DismembermentPart*>(pextraLimbs->GetInfoAt(i));
            for (unsigned int j = 0; j < ((fnv_004412e0::TESObjectREFR_GetFlags_Helper*)&pdismemberedLimb->parts)->CallGetFlags();
                 j++)
            {
                unsigned int uiBoundObject = ((fnv_004412e0::FUN_006a7ad0_shell*)&pdismemberedLimb->parts)->BSSimpleArray_NiAVObject_1024_GetAt(j);
                ((fnv_004412e0::FUN_00444d40_shell*)g_modelLoader)
                    ->ModelLoader_QueueBoundObject(uiBoundObject, epriority, this, *(Actor**)((char*)this + 0x28));
            }
        }
    }
    QueuedReference_QueueModels();
}

// @fnv 0x0043f240
void QueuedHelmet::UpdateFaceGenModels()
{
    for (int i = 0; i < 20; i++)
    {
        if (reinterpret_cast<fnv_0043f240::BipedAnim*>(pExistingBipedAnim)->IsSlotHidden(i) && !fnv_0043f240::BSTask_int64_GetTaskCanceled((int*)this))
            *(GO*)((char*)this + 0x7c + i * 4) = (void*)reinterpret_cast<fnv_0043f240::BipedAnim*>(pExistingBipedAnim)->GetFaceGenModelForSlot(i);
    }
}

// @fnv 0x0043d8c0
void* QueuedTreeModel::FUN_0043d8c0(unsigned int flags)
{
    this->SetVtableAndProcessState_0043d8f0();

    if (flags & 1)
        fnv_0043d8c0::_Deallocate(this);

    return this;
}

// @fnv 0x0043d910
void QueuedTreeModel::QueueTreeModelLoad()
{
    if (pTree->TESIconTree::GetTextureResourceName()[0] != 0)
    {
        char pfilename[260];

        TaskQueueInterface::CopyStringToBuffer(pfilename, 0x104, pTree->GetTextureResourcePath());

        ModelLoaderStrcatS(pfilename, 0x104, pTree->TESIconTree::GetTextureResourceName());

        {
            char pbasefilename[260];

            fnv_0043d910::CleanPath(pfilename, pbasefilename, 0x104);

            reinterpret_cast<fnv_0043d910::ModelLoaderQueueTexture*>(g_modelLoader)
                ->QueueModelFilePath(pbasefilename, this->IOTask_GetIOTaskPriority(), reinterpret_cast<QueuedFile*>(this));
        }
    }

    this->QueuedModel::DispatchToManager();
}

// @fnv 0x0043da00
// src: XBOX_PDB 0x0043da00
void QueuedTreeModel::Run_0043da00()
{
    BSTreeNode* ptreeNode;
    AutoMemHelper tempMemContext(0x1e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                                  0x476);

    ptreeNode = fnv_0043da00::DAT_011d5c48->CreateTreeInstance(reinterpret_cast<int>(pRef), reinterpret_cast<int>(pTree));
    reinterpret_cast<fnv_0043da00::ModelLoaderTreeOperations*>(fnv_0043da00::DAT_011d5c48)
        ->BSTreeManager_AddBackgroundLoadedTree(reinterpret_cast<int>(pRef), ptreeNode);
}

// @fnv 0x0043f030
void* QueuedHelmet::FUN_0043f030(unsigned int flags)
{
    FUN_0043f080();

    if (flags & 1)
        fnv_0043f030::_Deallocate(this);

    return this;
}

// @fnv 0x0043f2b0
// src: XBOX_PDB 0x0043f2b0
void QueuedHelmet::Finish_0043f2b0()
{
    if (!reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x1c)->operator unsigned int() &&
        !fnv_0043f2b0::BSTask_int64_GetTaskCanceled(reinterpret_cast<int*>(this)))
    {
        reinterpret_cast<IOTask*>(this)->AddToPostProcessQueue();
    }

    reinterpret_cast<fnv_0043f2b0::FUN_0043c610_shell*>(this)->RunVirtualMethod28();
}

// @fnv 0x0043fb80
void QueuedHelmet::ApplyQueuedModels()
{
    int n;
    for (n = 0; n < 0x14; ++n)
    {
        if (m_kQueuedModelsSecondary[n].operator unsigned int() != 0)
        {
            reinterpret_cast<fnv_0043fb80::BipedAnim*>(pExistingBipedAnim)->AttachFaceGenModel(
                reinterpret_cast<BSFaceGenModel*>(m_kQueuedModels[n].operator unsigned int()),
                reinterpret_cast<NiNode*>(m_kQueuedModelsSecondary[n].operator unsigned int()),
                static_cast<BIPED_OBJECT>(n));
        }
    }

    reinterpret_cast<fnv_0043fb80::Standin0043fb50*>(g_modelLoader)->DispatchToVirtual(pRef);
}

// @fnv 0x00440050
// src: XBOX_PDB 0x00440050
void QueuedActor::QueuedReference_QueueModels()
{
    fnv_00440050::TESModelV* ptesModel;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x752);
    void* pobj = ((fnv_00440050::FUN_007af430_shell*)*(void**)((char*)this + 0x28))->BGSSaveFormBuffer_GetForm();
    ptesModel = ((fnv_00440050::FUN_00571630_shell*)*(void**)((char*)this + 0x28))->FUN_00571630();
    if (!ptesModel || !*ptesModel->GetModelFileName())
        return;
    ((fnv_00440050::FUN_00444dc0_shell*)g_modelLoader)
        ->QueueModelForObject(pobj, (char*)this + 0x2c, ((IOTask*)this)->IOTask_GetIOTaskPriority(), this,
                              *(void**)((char*)this + 0x28));
    if (!*(fnv_00440050::Flt*)((char*)this + 0x2c))
        ((fnv_00440050::FUN_004472a0_shell*)g_modelLoader)->ModelLoader_FindModel(ptesModel->GetModelFileName(), (char*)this + 0x30);
    fnv_00440050::FUN_00477640_shell* pdestruct = fnv_00440050::BGSDestructibleObjectForm_GetDestructionForm(pobj);
    if (pdestruct)
        pdestruct->FUN_00477640(pobj, ((IOTask*)this)->IOTask_GetIOTaskPriority(), this);
}

// @fnv 0x00441e40
void QueuedFileLoad::Run()
{
    BSFile* pfile;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x976);
    *(NiPointer<fnv_00441e40::LoadedFile>*)m_pLoadedFile =
        ((fnv_00441e40::FUN_004483a0_t*)g_modelLoader)->GetHolderValue(((fnv_00441e40::Proc_S*)this)->GetNext());
    if (*(fnv_00441e40::Flt*)m_pLoadedFile)
        return;
    pfile = GetFile(fnv_00441e40::ModelLoader_GetArchiveTypeIndexForIOFileIndex(m_iLoadPriority), 0xffff);
    if (pfile)
        *(NiPointer<fnv_00441e40::LoadedFile>*)m_pLoadedFile = (fnv_00441e40::LoadedFile*)new fnv_00441e40::LoadedFile(((fnv_00441e40::Proc_S*)this)->GetNext(), pfile);
    else
        fnv_00441e40::_FNV_Warning("MODELS: Could not get file for %s.", ((fnv_00441e40::Proc_S*)this)->GetNext());
}
