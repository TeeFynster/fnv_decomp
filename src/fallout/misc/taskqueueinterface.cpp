#include "../../../include/SettingT.h"
#include "../../../include/BSPackedTask.h"
#include "../../../include/InterfaceManager.h"
// fallout/misc/taskqueueinterface.cpp: TaskQueueInterface, Holder, Host, TaskQueueProxy and more (69 functions)

#include <stddef.h>
#include "../../../include/SETTING_VALUE.h"
#include "../../../include/ActorCombatGroup.h"
#include "../../../include/TESWaterSystem.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/HighProcess.h"
#include "../../../include/Creature.h"
#include "../../../include/MagicHitEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/Character.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TESObjectWEAP.h"
#include "../../../include/NiAdditionalGeometryData.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/BSFadeNode.h"
#include "../../../include/TESSound.h"
#include "../../../include/BSSimpleList.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/BGSOpenCloseForm.h"
#include "../../../include/DetailedActorPathHandler.h"
#include "../../../include/Script.h"
#include "../../../include/TES.h"
#include "../../../include/TESWaterListener.h"
#include "../../../include/bhkCharacterController.h"
#include "../../../include/bhkWorld.h"
#include "../../../include/NavMeshObstacleManager.h"
#include "../../../include/BSScrapArray.h"
#include "../../../include/BSSimpleArray.h"
#include "../../../include/DFALL.h"
#include "../../../include/NiTMapBase.h"

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

class TESObjectCELL;
class TESQuest;
#include "../../../include/NiTMapItem.h"

// Remaining unit-specific declarations from taskqueueinterface_decls.h.
class BSPackedTask;
class BooleanFloatQuery;
class DismemberLimbTaskData;
class Date;
class bhkWorld;
class bhkCharacterController;
class CombatThreatRecord;
class ParentSpaceNode;
class SandboxProcedureData;
class TaskQueueParallelWork;
class TaskQueueParallelManager;
#define TASK_PROCESS(actor) ((actor)->MobileObject::FUN_008d8520())
class BooleanFloatQuery
{
  public:
    Actor* m_pkAttacker;
    char layoutPadding04_pad4[4];
    void* m_pSourceReference;
    int m_uiHitLocation;
    int m_uiHitFlags;
    float afDamageAmount;
    void DecRefCount();  // @ref 0x0087cea0 DecRefCount@BooleanFloatQuery
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    char m_vOffset1[12];
    char m_vOffset2[12];
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
};
class DismemberLimbTaskData
{
  public:
    unsigned int uiLimb;
    int iDismembermentOption;
    Actor* pActor;
};
class BipedAnim
{
  public:
    static void SetNodeTranslation(NiAVObject*);                   // @ref 0x004ab0c0 SetNodeTranslation@BipedAnim
    static void SetNodeTranslation(NiAVObject*, const NiPoint3&);  // @ref 0x00b553d0 SetNodeTranslation@BipedAnim
    void AttachFaceGenNode();                                      // @ref 0x00571b50 AttachFaceGenNode@BipedAnim
};
FNV_STATIC_ASSERT(sizeof(NiUpdateData) == 12);
void FUN_005c0740(TESObjectREFR*, unsigned char, float);  // @ref 0x005c0740 FUN_005c0740
void FUN_005c0b10(TESObjectREFR*, unsigned char, float);  // @ref 0x005c0b10 FUN_005c0b10
void FUN_005d3c20(TESObjectREFR*, float);                 // @ref 0x005d3c20 FUN_005d3c20
void FUN_005d4c20(TESObjectREFR*, float);                 // @ref 0x005d4c20 FUN_005d4c20
void UpdateSceneGraph(NiAVObject*);                       // @ref 0x005526f0 UpdateSceneGraph
void UpdateControllersRecursive(NiAVObject*);             // @ref 0x00552790 UpdateControllersRecursive
void FUN_00892460(TESObjectREFR*, bool);                  // @ref 0x00892460 FUN_00892460
void FUN_00c6a270(NiAVObject*, bool, bool, int);          // @ref 0x00c6a270 FUN_00c6a270
void FUN_00c69fc0(NiAVObject*, bool, bool, bool);         // @ref 0x00c69fc0 FUN_00c69fc0
void* GetObjectFromNode(NiAVObject*, bool, int);  // @ref 0x00c69ee0 GetObjectFromNode
void* FUN_00458b20();  // @ref 0x00458b20 FUN_00458b20
class TaskQueueParallelWork
{
  public:
    void(__cdecl* pCallback)(unsigned int, void*);
    void* pData;
    unsigned int ItemUpdateArray;
    unsigned int uiNext;
    void Construct(void(__cdecl*)(unsigned int, void*), void*, unsigned int);  // @ref 0x0087cf10 Construct
};
class TaskQueueParallelManager
{
  public:
    void FUN_00c44c90(TaskQueueParallelWork*);  // @ref 0x00c44c90 FUN_00c44c90
};
class BSSimpleArray_SandBoxChoiceListItem_1024_
{
  public:
    void Clear(bool);  // @ref 0x008454f0 Clear@BSSimpleArray_SandBoxChoiceListItem_1024_
};
class INISettingCollection;
using ::SettingT;                                                              // @ref 0x00408d60 Bool@?$SettingT
void UpdateAnimObjFromTask(unsigned int, void*);                // @ref 0x0087cf50 UpdateAnimObjFromTask
void FUN_0087cfb0(unsigned int, void*);                         // @ref 0x0087cfb0 FUN_0087cfb0
void FUN_0087d030(BSScrapArray<NiPointer<NiAVObject>, 1024>*);  // @ref 0x0087d030 FUN_0087d030
NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int, CombatThreatRecord*>*
FUN_0087ce70();                                            // @ref 0x0087ce70 FUN_0087ce70
extern BSSimpleArray<ParentSpaceNode, 1024> DAT_011df244;  // @ref 0x011df244 DAT_011df244
extern BSSimpleArray<ParentSpaceNode, 1024> DAT_011df1c4;  // @ref 0x011df1c4 DAT_011df1c4
extern SettingT<INISettingCollection> DAT_011df1b8;        // @ref 0x011df1b8 DAT_011df1b8
extern TaskQueueParallelManager* DAT_01202df4;             // @ref 0x01202df4 DAT_01202df4
extern TES* g_TES;
extern PlayerCharacter* g_thePlayer;
int Warning(const char*, ...);
void operator delete(void*);
extern bool DAT_011a31f4;
extern "C" __declspec(dllimport) void __stdcall DebugBreak();



class QuestStage
{
  public:
    unsigned char GetIndex();
};

InterfaceManager* FUN_004b7210();
#include "../../../include/CountingSemaphore.h"
#include "../../../include/GO.h"

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSPACKEDTASK_H
#define FNV_BSPACKEDTASK_H
class BSPackedTask;
union BSPackedTask__PackedTaskVariantData;
#pragma pack(push, 4)

#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSPackedTask__PackedTaskVariantData) == 4);
FNV_STATIC_ASSERT(offsetof(BSPackedTask__PackedTaskVariantData, bData) == 0);
FNV_STATIC_ASSERT(offsetof(BSPackedTask__PackedTaskVariantData, pcDataA) == 0);
FNV_STATIC_ASSERT(offsetof(BSPackedTask__PackedTaskVariantData, psDataA) == 0);
FNV_STATIC_ASSERT(offsetof(BSPackedTask__PackedTaskVariantData, iData) == 0);
FNV_STATIC_ASSERT(offsetof(BSPackedTask__PackedTaskVariantData, fData) == 0);
FNV_STATIC_ASSERT(offsetof(BSPackedTask__PackedTaskVariantData, pData) == 0);
#pragma pack(push, 4)

#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSPackedTask) == 32);
FNV_STATIC_ASSERT(offsetof(BSPackedTask, m_akPackedTaskVariantData) == 0);
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSPACKEDTASKQUEUE_H
#define FNV_BSPACKEDTASKQUEUE_H
class BSPackedTask;
class PackedTaskQueueProcessor;
class BSScrapHeapQueueElem_BSPackedTask_;
class BSTCommonMessageQueue_BSPackedTask_;
class BSTCommonScrapHeapMessageQueue_BSPackedTask_;
class BSTMessageQueue_BSPackedTask_;
class ScrapHeapBuffer;
#pragma pack(push, 4)
class BSTMessageQueue_BSPackedTask_
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    // BSTMessageQueue<BSPackedTask>
    // const BSTMessageQueue<BSPackedTask>& __cdecl BSTMessageQueue<BSPackedTask>::*(const BSTMessageQueue<BSPackedTask>&)
    // void __cdecl BSTMessageQueue<BSPackedTask>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTMessageQueue_BSPackedTask_) == 4);
FNV_STATIC_ASSERT(offsetof(BSTMessageQueue_BSPackedTask_, m_ppVirtualMethodTable) == 0);
#pragma pack(push, 4)
class BSTCommonMessageQueue_BSPackedTask_ : public BSTMessageQueue_BSPackedTask_
{
  public:
    // base BSTMessageQueue<BSPackedTask> at +0x0, size 4
    unsigned int m_uiLockState;  // +0x4, 4 bytes
    // BSTCommonMessageQueue<BSPackedTask>
    // void __cdecl BSTCommonMessageQueue<BSPackedTask>::*()
    // bool __cdecl BSTCommonMessageQueue<BSPackedTask>::*(const BSPackedTask&)
    // bool __cdecl BSTCommonMessageQueue<BSPackedTask>::*(const BSPackedTask&)
    // bool __cdecl BSTCommonMessageQueue<BSPackedTask>::*(BSPackedTask&)
    // bool __cdecl BSTCommonMessageQueue<BSPackedTask>::*(BSPackedTask&)
    // const BSTCommonMessageQueue<BSPackedTask>& __cdecl BSTCommonMessageQueue<BSPackedTask>::*(const BSTCommonMessageQueue<BSPackedTask>&)
    // void __cdecl BSTCommonMessageQueue<BSPackedTask>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTCommonMessageQueue_BSPackedTask_) == 8);
FNV_STATIC_ASSERT(offsetof(BSTCommonMessageQueue_BSPackedTask_, m_uiLockState) == 4);
#pragma pack(push, 4)
class BSTCommonScrapHeapMessageQueue_BSPackedTask_ : public BSTCommonMessageQueue_BSPackedTask_
{
  public:
    // base BSTCommonMessageQueue<BSPackedTask> at +0x0, size 8
    ScrapHeapBuffer* m_pAllocator;                      // +0x8, 4 bytes
    BSScrapHeapQueueElem_BSPackedTask_* pHead;          // +0xC, 4 bytes
    BSScrapHeapQueueElem_BSPackedTask_** m_ppTailLink;  // +0x10, 4 bytes
    // BSTCommonScrapHeapMessageQueue<BSPackedTask>
    // void __cdecl BSTCommonScrapHeapMessageQueue<BSPackedTask>::*()
    // void __cdecl BSTCommonScrapHeapMessageQueue<BSPackedTask>::*(ScrapHeapBuffer*)
    // bool __cdecl BSTCommonScrapHeapMessageQueue<BSPackedTask>::*()
    // const BSTCommonScrapHeapMessageQueue<BSPackedTask>& __cdecl BSTCommonScrapHeapMessageQueue<BSPackedTask>::*(const BSTCommonScrapHeapMessageQueue<BSPackedTask>&)
    // bool __cdecl BSTCommonScrapHeapMessageQueue<BSPackedTask>::*(const BSPackedTask&)
    // bool __cdecl BSTCommonScrapHeapMessageQueue<BSPackedTask>::*(BSPackedTask&)
    // void __cdecl BSTCommonScrapHeapMessageQueue<BSPackedTask>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTCommonScrapHeapMessageQueue_BSPackedTask_) == 20);
FNV_STATIC_ASSERT(offsetof(BSTCommonScrapHeapMessageQueue_BSPackedTask_, m_pAllocator) == 8);
FNV_STATIC_ASSERT(offsetof(BSTCommonScrapHeapMessageQueue_BSPackedTask_, pHead) == 12);
FNV_STATIC_ASSERT(offsetof(BSTCommonScrapHeapMessageQueue_BSPackedTask_, m_ppTailLink) == 16);
FNV_STATIC_ASSERT(sizeof(CountingSemaphore) == 12);
FNV_STATIC_ASSERT(offsetof(CountingSemaphore, iCount) == 0);
FNV_STATIC_ASSERT(offsetof(CountingSemaphore, hSemaphore) == 4);
FNV_STATIC_ASSERT(offsetof(CountingSemaphore, m_iMaximumCount) == 8);
#pragma pack(push, 4)
class PackedTaskQueueProcessor
{
  public:
    BSTCommonScrapHeapMessageQueue_BSPackedTask_ Queue;             // +0x0, 20 bytes
    CountingSemaphore m_kQueuedTaskSemaphore;                       // +0x14, 12 bytes
    void(__cdecl* m_pTaskCompletionCallback)(const BSPackedTask&);  // +0x20, 4 bytes
    bool m_bIsProcessing;                                           // +0x24, 1 bytes
    unsigned char layoutPadding25[3];
    void Process();
    bool CallVirtualMethod1(const BSPackedTask&);
    // PackedTaskQueueProcessor
    // void __cdecl PackedTaskQueueProcessor::*()
    // void __cdecl PackedTaskQueueProcessor::*()
    // void __cdecl PackedTaskQueueProcessor::*()
    // bool __cdecl PackedTaskQueueProcessor::*(const BSPackedTask&)
    // bool __cdecl PackedTaskQueueProcessor::*()
    // bool __cdecl PackedTaskQueueProcessor::*()
    // bool __cdecl PackedTaskQueueProcessor::*()
    // void __cdecl PackedTaskQueueProcessor::*()
    // const PackedTaskQueueProcessor& __cdecl PackedTaskQueueProcessor::*(const PackedTaskQueueProcessor&)
    // void* __cdecl PackedTaskQueueProcessor::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackedTaskQueueProcessor) == 40);
FNV_STATIC_ASSERT(offsetof(PackedTaskQueueProcessor, Queue) == 0);
FNV_STATIC_ASSERT(offsetof(PackedTaskQueueProcessor, m_kQueuedTaskSemaphore) == 20);
FNV_STATIC_ASSERT(offsetof(PackedTaskQueueProcessor, m_pTaskCompletionCallback) == 32);
FNV_STATIC_ASSERT(offsetof(PackedTaskQueueProcessor, m_bIsProcessing) == 36);
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TASKQUEUEINTERFACE_H
#define FNV_TASKQUEUEINTERFACE_H
class PackedTaskQueueProcessor;
class TaskQueueInterface;
#pragma pack(push, 4)
class TaskQueueInterface
{
  public:
    PackedTaskQueueProcessor* m_pPrimaryTaskProcessor;    // +0x0, 4 bytes
    PackedTaskQueueProcessor* m_pSecondaryTaskProcessor;  // +0x4, 4 bytes
    PackedTaskQueueProcessor* m_pTaskQueueProcessor;      // +0x8, 4 bytes
    unsigned long m_uiTaskFlags;                          // +0xC, 4 bytes
    void ProcessTaskQueue();
    NiPoint3& QueueActorAnimationTask(NiPoint3& akDest);
    static void CopyStringToBuffer(char* apBuffer, unsigned int auiSize, const char* apSource);
    void QueueActorDisarm(bool abCritical);
    void QueueReferenceStateTask(bool abOpen);
    void SetTaskFlagDWord(bool abSet, unsigned int auiMask);
    void SetTaskFlagWord(bool abSet, unsigned short ausMask);
    static void ProcessQueuedTask(const BSPackedTask&);
    void ProcessPackedTask(const BSPackedTask&);
    static void ThreadProcessInput(unsigned int);
    static void ThreadProcessSecondaryInput();
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*()
    // unsigned long __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(float)
    // void __cdecl TaskQueueInterface::*(int)
    // void __cdecl TaskQueueInterface::*(NiNode*, NiColor*)
    // void __cdecl TaskQueueInterface::*(unsigned int, TESObjectREFR*, ...)
    // void __cdecl TaskQueueInterface::*(TESObjectWEAP*, TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(Actor*, NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(NiNode*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, NiNode*, bool, bool)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, int)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(Actor*, BooleanFloatQuery*)
    // void __cdecl TaskQueueInterface::*(Actor*, BooleanFloatQuery*)
    // void __cdecl TaskQueueInterface::*(MobileObject*)
    // void __cdecl TaskQueueInterface::*(ActiveEffect*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, float, bool)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, float*, DismemberLimbTaskData*)
    // void __cdecl TaskQueueInterface::*(Actor*, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, float, float, float, float)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, int)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(NiAVObject*, bool, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, TESObjectWEAP*)
    // void __cdecl TaskQueueInterface::*(Actor*, TESBoundObject*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(Actor*, int, int, bool, bool)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, TESObjectREFR*, float)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, TESObjectREFR*, float)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*)
    // void __cdecl TaskQueueInterface::*(Character*)
    // void __cdecl TaskQueueInterface::*(TESObjectREFR*, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*, const NiPoint3&)
    // void __cdecl TaskQueueInterface::*(Actor*, bool)
    // void __cdecl TaskQueueInterface::*(float, const NiPoint3&)
    // void __cdecl TaskQueueInterface::*(float, const NiPoint3&)
    // void __cdecl TaskQueueInterface::*(Actor*, bool, bool)
    // void __cdecl TaskQueueInterface::*(Actor*)
    // void __cdecl TaskQueueInterface::*(Actor*)
    // void __cdecl TaskQueueInterface::*(Actor*)
    // void __cdecl TaskQueueInterface::*(ActiveEffect*)
    // void __cdecl TaskQueueInterface::*(PackedTaskQueueProcessor&, PackedTaskQueueProcessor&)
    // void __cdecl TaskQueueInterface::*()
    // TaskQueueInterface* __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(const BSPackedTask&)
    // void __cdecl TaskQueueInterface::*()
    // bool __cdecl TaskQueueInterface::*()
    // bool __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(bool)
    // TaskQueueInterface
    // PackedTaskQueueProcessor* __cdecl TaskQueueInterface::*()
    // void __cdecl TaskQueueInterface::*(const BSPackedTask&)
    // void* __cdecl TaskQueueInterface::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TaskQueueInterface) == 16);
FNV_STATIC_ASSERT(offsetof(TaskQueueInterface, m_pPrimaryTaskProcessor) == 0);
FNV_STATIC_ASSERT(offsetof(TaskQueueInterface, m_pSecondaryTaskProcessor) == 4);
FNV_STATIC_ASSERT(offsetof(TaskQueueInterface, m_pTaskQueueProcessor) == 8);
FNV_STATIC_ASSERT(offsetof(TaskQueueInterface, m_uiTaskFlags) == 12);
#endif

extern "C" int strcpy_s(char* apDestination, unsigned int auiSize, const char* apSource);
unsigned int gm_GetCurrentThreadId();

// @fnv 0x00406d30
void TaskQueueInterface::CopyStringToBuffer(char* apBuffer, unsigned int auiSize, const char* apSource)
{
    strcpy_s(apBuffer, auiSize, apSource);
}

// @fnv 0x00450f90
void TaskQueueInterface::QueueActorDisarm(bool abCritical)
{
    SetTaskFlagDWord(abCritical, 1);
}

// @fnv 0x0047aa40
void TaskQueueInterface::QueueReferenceStateTask(bool abOpen)
{
    SetTaskFlagWord(abOpen, 8);
}

// @fnv 0x005c3420
NiPoint3& TaskQueueInterface::QueueActorAnimationTask(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(&m_pSecondaryTaskProcessor);
    return akDest;
}

// @fnv 0x0087a850
void TaskQueueInterface::ProcessTaskQueue()
{
    m_uiTaskFlags = gm_GetCurrentThreadId();
    m_pSecondaryTaskProcessor->Process();
    m_uiTaskFlags = 0;
    m_pTaskQueueProcessor = m_pPrimaryTaskProcessor;
}

// @fnv 0x0087d160
void TaskQueueInterface::ProcessPackedTask(const BSPackedTask& task)
{
    if (DAT_011a31f4)
    {
        if (!reinterpret_cast<PackedTaskQueueProcessor*>(
                 reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(this)->GetSize())
                 ->CallVirtualMethod1(task))
            DebugBreak();
    }
    else
    {
        ProcessQueuedTask(task);
    }
}

// If FUN_004b7210() returns an object whose GetIndex() is nonzero, forwards input to its FUN_00984f60 method.
// @fnv 0x007034c0
void TaskQueueInterface::ThreadProcessInput(unsigned int input)
{
    if (FUN_004b7210() && reinterpret_cast<QuestStage*>(FUN_004b7210())->GetIndex())
        FUN_004b7210()->FUN_00984f60(input);
}

// @fnv 0x00703490
void TaskQueueInterface::ThreadProcessSecondaryInput()
{
    if (FUN_004b7210() && reinterpret_cast<QuestStage*>(FUN_004b7210())->GetIndex())
        FUN_004b7210()->ClearActivatePickResults();
}

struct CallTarget
{
    float Tail();
};

struct FUN_0087ce50_cls
{
    CallTarget* Head();
    float GetHeadTail();
};

// Dispatches a packed task by its opcode, calling the matching engine routine for each case.
// @fnv 0x0087b990
void TaskQueueInterface::ProcessQueuedTask(const BSPackedTask& akTask)
{
    switch (akTask.m_akPackedTaskVariantData[0].iData)
    {
    case 0:
        Warning("Float %.2f", akTask.m_akPackedTaskVariantData[1].fData);
        break;
    case 1:
        Warning("Int %d", akTask.m_akPackedTaskVariantData[1].iData);
        break;
    case 2: {
        NiAVObject* pTaskObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        NiPoint3 kColor(akTask.m_akPackedTaskVariantData[2].fData, akTask.m_akPackedTaskVariantData[3].fData,
                        akTask.m_akPackedTaskVariantData[4].fData);
        BipedAnim::SetNodeTranslation(pTaskObject, kColor);
        break;
    }
    case 32: {
        TESObjectWEAP* pWeapon = static_cast<TESObjectWEAP*>(akTask.m_akPackedTaskVariantData[1].pData);
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[2].pData);
        pWeapon->Fire(m_pWorldReferenceInfo);
        break;
    }
    case 31: {
        unsigned int auiFormId = akTask.m_akPackedTaskVariantData[2].iData;
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(TESForm::GetFormByID(auiFormId));
        if (m_pWorldReferenceInfo)
        {
            switch (akTask.m_akPackedTaskVariantData[1].iData)
            {
            case 0x1007:
                FUN_005c0740(m_pWorldReferenceInfo, akTask.m_akPackedTaskVariantData[3].pcDataA[0],
                             akTask.m_akPackedTaskVariantData[4].fData);
                break;
            case 0x1009:
                FUN_005c0b10(m_pWorldReferenceInfo, akTask.m_akPackedTaskVariantData[3].pcDataA[0],
                             akTask.m_akPackedTaskVariantData[4].fData);
                break;
            case 0x113c:
                Script::SetReferenceScale(m_pWorldReferenceInfo, akTask.m_akPackedTaskVariantData[3].fData);
                break;
            case 0x1156:
                FUN_005d3c20(m_pWorldReferenceInfo, akTask.m_akPackedTaskVariantData[3].fData);
                break;
            case 0x109e:
            case 0x124f: {
                float fY;
                auiFormId = akTask.m_akPackedTaskVariantData[3].iData;
                TESObjectREFR* target = static_cast<TESObjectREFR*>(TESForm::GetFormByID(auiFormId));
                float fX = akTask.m_akPackedTaskVariantData[4].fData;
                fY = akTask.m_akPackedTaskVariantData[5].fData;
                float fZ = akTask.m_akPackedTaskVariantData[6].fData;
                int iFade = 0;
                if (akTask.m_akPackedTaskVariantData[1].iData == 0x124f)
                    iFade = 1;
                if (m_pWorldReferenceInfo->IsActor() && m_pWorldReferenceInfo != g_thePlayer)
                {
                    Actor* pActor = static_cast<Actor*>(m_pWorldReferenceInfo);
                    if (TASK_PROCESS(pActor))
                    {
                        // Actor.h names slot 0x420 Unk_108; this call consumes its float result.
                    if (reinterpret_cast<MobileObject*>(pActor)->GetCurrentProcessLevel() == 0 &&
                            reinterpret_cast<float (__thiscall*)(Actor*)>((*reinterpret_cast<void***>(pActor))[0x420 / 4])(pActor) > 0.0 && iFade > 0.0)
                        {
                            HighProcess* pProcess = static_cast<HighProcess*>(TASK_PROCESS(pActor));
                            pProcess->RefreshProcessState(pActor, target, fX, fY, fZ);
                        }
                        else
                        {
                            Script::MoveReferenceToPosition(m_pWorldReferenceInfo, target, fX, fY, fZ);
                        }
                    }
                    else
                    {
                        Script::MoveReferenceToPosition(m_pWorldReferenceInfo, target, fX, fY, fZ);
                    }
                }
                else
                {
                    Script::MoveReferenceToPosition(m_pWorldReferenceInfo, target, fX, fY, fZ);
                }
                break;
            }
            case 0x116c:
                FUN_005d4c20(m_pWorldReferenceInfo, akTask.m_akPackedTaskVariantData[3].fData);
                break;
            case 0x11df: {
                auiFormId = akTask.m_akPackedTaskVariantData[3].iData;
                TESObjectREFR* target = static_cast<TESObjectREFR*>(TESForm::GetFormByID(auiFormId));
                Script::MatchFaceGeometry(m_pWorldReferenceInfo, target, akTask.m_akPackedTaskVariantData[4].iData);
                break;
            }
            }
        }
        break;
    }
    case 4: {
        if (DAT_011df244.GetSize() > 0)
        {
            TaskQueueParallelWork kWork;
            kWork.Construct(FUN_0087cfb0, &DAT_011df244, DAT_011df244.GetSize());
            DAT_01202df4->FUN_00c44c90(&kWork);
            reinterpret_cast<BSSimpleArray_SandBoxChoiceListItem_1024_*>(&DAT_011df244)->Clear(false);
        }
        if (DAT_011df1c4.GetSize() > 0)
        {
            BSScrapArray<NiPointer<NiAVObject>, 1024> nodeList;
            FUN_0087d030(&nodeList);
            TaskQueueParallelWork kWork;
            kWork.Construct(UpdateAnimObjFromTask, &nodeList,
                            reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&nodeList)->GetSize());
            DAT_01202df4->FUN_00c44c90(&kWork);
        }
        if (!DAT_011df1b8.Bool()[0])
            g_TES->FUN_00453900();
        break;
    }
    case 3: {
        NiNode* pNode = static_cast<NiNode*>(akTask.m_akPackedTaskVariantData[1].pData);
        DetailedActorPathHandler::UpdateSceneNode(pNode);
        break;
    }
    case 5: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        bool bTestMultibounds = false;
        if (reinterpret_cast<FUN_0087ce50_cls*>(pObject)->GetHeadTail() == 0.0)
            bTestMultibounds = true;
        UpdateSceneGraph(pObject);
        if (bTestMultibounds && reinterpret_cast<FUN_0087ce50_cls*>(pObject)->GetHeadTail() > 0.0)
            reinterpret_cast<DetailedActorPathHandler*>(g_TES->GetDetailedActorPathHandler())
                ->HandleReferenceUpdate(TESObjectREFR::GetReferenceFromNiAVObject(pObject), false, false);
        pObject->FUN_00401970();
        break;
    }
    case 6: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        UpdateControllersRecursive(pObject);
        pObject->FUN_00401970();
        break;
    }
    case 7: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        NiNode* pParent = static_cast<NiNode*>(akTask.m_akPackedTaskVariantData[2].pData);
        bool bFirstFree = akTask.m_akPackedTaskVariantData[3].bData;
        bool bUpdate = akTask.m_akPackedTaskVariantData[4].bData;
        pParent->AttachChildInAvailableSlot(pObject, bFirstFree);
        pObject->CompleteAttachUpdate();
        if (bUpdate)
            pObject->UpdateSceneObject();
        pObject->FUN_00401970();
        pParent->FUN_00401970();
        break;
    }
    case 8: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        NiNode* pParent = pObject->GetParent();
        if (pParent)
            pParent->RemoveObject(pObject);
        pObject->FUN_00401970();
        break;
    }
    case 47: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        BipedAnim::SetNodeTranslation(pObject);
        pObject->FUN_00401970();
        break;
    }
    case 9: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        ShadowSceneNode* pScene =
            NiAdditionalGeometryData::GetShadowSceneNodeForIndex(akTask.m_akPackedTaskVariantData[2].iData);
        if (pScene)
            pScene->ShadowSceneNode::RemoveObject(pObject);
        pObject->FUN_00401970();
        break;
    }
    case 10: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        NiUpdateData kUpdate(0.0f, false, false);
        pObject->Update(static_cast<const NiUpdateData&>(kUpdate));
        pObject->FUN_00401970();
        break;
    }
    case 11: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        BooleanFloatQuery* hitData = static_cast<BooleanFloatQuery*>(akTask.m_akPackedTaskVariantData[2].pData);
        pActor->ProcessActorDamage(hitData->afDamageAmount, hitData);
        if (hitData->m_pkAttacker)
            hitData->m_pkAttacker->FUN_0088fb00(hitData->afDamageAmount, hitData, pActor);
        hitData->DecRefCount();
        break;
    }
    case 12: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        if (m_pWorldReferenceInfo->IsExplosion())
        {
            Actor* pActor = static_cast<Actor*>(m_pWorldReferenceInfo);
            pActor->Unk_C1();
        }
    }
    case 13: {
        struct DamageRequestState
        {
            NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int, CombatThreatRecord*>* pMap;
            float fAmount;
            char reservedFoundA, reservedFoundB, reservedFoundC;
            bool bFound;
            TESObjectREFR* ref;
            CombatThreatRecord* pValue;
            char reservedAllowA, reservedAllowB, reservedAllowC;
            bool bAllowDestroyed;
            void* point;
        } state;
        state.ref = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        state.fAmount = akTask.m_akPackedTaskVariantData[2].fData;
        state.bAllowDestroyed = akTask.m_akPackedTaskVariantData[3].bData;
        state.bFound = false;
        state.pMap = FUN_0087ce70();
        state.point = state.pMap->GetFirstPos();
        state.pValue = 0;
        while (state.point && !state.bFound)
        {
            unsigned int uiKey = 0;
            state.pMap->GetNext(state.point, uiKey, state.pValue);
            if (uiKey == reinterpret_cast<unsigned int>(state.ref))
                state.bFound = true;
        }
        if (state.bFound)
        {
            if (state.ref->IsActor())
            {
                Actor* pActor = static_cast<Actor*>(state.ref);
                pActor->DamageHealthAndFatigue(state.fAmount, 0.0f, 0);
            }
            else
            {
                state.ref->DamageObject(state.fAmount, state.bAllowDestroyed);
            }
        }
        break;
    }
    case 48: {
        TESObjectREFR* reference = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        bool bFlag = akTask.m_akPackedTaskVariantData[2].bData;
        FUN_00892460(reference, bFlag);
        break;
    }
    case 14: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        float* afDamageAmount = static_cast<float*>(akTask.m_akPackedTaskVariantData[2].pData);
        pActor->Kill(pActor->m_pActorReference, *afDamageAmount);
        DismemberLimbTaskData* pLimbData =
            static_cast<DismemberLimbTaskData*>(akTask.m_akPackedTaskVariantData[3].pData);
        if (pLimbData)
        {
            pActor->HandleDismembermentTask(pLimbData->iDismembermentOption, pLimbData->uiLimb, pLimbData->pActor);
            delete pLimbData;
        }
        delete afDamageAmount;
        break;
    }
    case 15: {
        Actor* pQueuedActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        bool bPower = akTask.m_akPackedTaskVariantData[2].bData;
        bool fForce = akTask.m_akPackedTaskVariantData[3].bData;
        pQueuedActor->ProcessQueuedHit(bPower, fForce);
        break;
    }
    case 16: {
        struct PushActorRequest
        {
            float fForce;
            Actor* pActor;
        } request;
        request.pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        NiPoint3 kPosition(akTask.m_akPackedTaskVariantData[2].fData, akTask.m_akPackedTaskVariantData[3].fData,
                           akTask.m_akPackedTaskVariantData[4].fData);
        request.fForce = akTask.m_akPackedTaskVariantData[5].fData;
        if (request.pActor && TASK_PROCESS(request.pActor))
            TASK_PROCESS(request.pActor)->PushActorAway(request.pActor, kPosition, request.fForce);
        break;
    }
    case 17: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        BooleanFloatQuery* hitData = static_cast<BooleanFloatQuery*>(akTask.m_akPackedTaskVariantData[2].pData);
        if (pActor)
            pActor->ProcessHitData(hitData, 0);
        hitData->DecRefCount();
        break;
    }
    case 18: {
        ActiveEffect* pEffect = static_cast<ActiveEffect*>(akTask.m_akPackedTaskVariantData[1].pData);
        if (pEffect)
            reinterpret_cast<Script*>(pEffect)->SetOwnerQuest(
                reinterpret_cast<TESQuest*>(MagicHitEffect::GetEffectsForActiveEffect(pEffect)));
        break;
    }
    case 19: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        if (pObject)
        {
            TESObjectREFR* m_pWorldReferenceInfo = TESObjectREFR::GetReferenceFromNiAVObject(pObject);
            TESObjectCELL* cell = m_pWorldReferenceInfo ? m_pWorldReferenceInfo->GetParentCell() : 0;
            bhkWorld* pWorld = cell ? reinterpret_cast<ExtraDataList*>(cell)->GetRoomId() : 0;
            if (pWorld)
                pWorld->AddObject(pObject, true, true, 0, false);
            pObject->FUN_00401970();
        }
        break;
    }
    case 20: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        if (pObject)
        {
            FUN_00c6a270(pObject, true, true, 0);
            GetObjectFromNode(pObject, true, 0);
            pObject->FUN_00401970();
        }
        break;
    }
    case 21: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        TESObjectWEAP* pWeapon = static_cast<TESObjectWEAP*>(akTask.m_akPackedTaskVariantData[2].pData);
        m_pWorldReferenceInfo->SetExtraDataString(pWeapon);
        break;
    }
    case 22: {
        Actor* pTargetActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        unsigned int uiObjectID = akTask.m_akPackedTaskVariantData[2].iData;
        if (TASK_PROCESS(pTargetActor) && TASK_PROCESS(pTargetActor)->GetActiveWeapon())
        {
            BSSimpleArray<ParentSpaceNode, 1024>* pEntry =
                reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(TASK_PROCESS(pTargetActor)->GetActiveWeapon());
            if (pEntry->GetSize() == uiObjectID)
            {
                reinterpret_cast<BipedAnim*>(pTargetActor)->AttachFaceGenNode();
                if (TASK_PROCESS(pTargetActor))
                    TASK_PROCESS(pTargetActor)->SetCurrentArmor(0, 0, false);
            }
        }
        break;
    }
    case 24: {
        Actor* m_pAttachedReference = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        unsigned int uiAV = akTask.m_akPackedTaskVariantData[2].iData;
        unsigned int uiLimb = akTask.m_akPackedTaskVariantData[3].iData;
        bool bFlagA = akTask.m_akPackedTaskVariantData[3].bData;
        bool bDismember = akTask.m_akPackedTaskVariantData[4].bData;
        m_pAttachedReference->DismemberLimb(uiAV, uiLimb, bFlagA, bDismember, true, false);
        break;
    }
    case 23: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        m_pWorldReferenceInfo->Set3D(0, false);
        break;
    }
    case 25: {
        TESObjectREFR* ref = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        TESObjectREFR* pWaterReference = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[2].pData);
        float fRate = akTask.m_akPackedTaskVariantData[3].fData;
        g_TES->GetActorScale()->SetWaterHeight(ref, pWaterReference, fRate);
        break;
    }
    case 26: {
        TESObjectREFR* ref = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        TESObjectREFR* pWaterReference = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[2].pData);
        float fRate = akTask.m_akPackedTaskVariantData[3].fData;
        g_TES->GetActorScale()->UpdateWaterZone(ref, pWaterReference, fRate);
        break;
    }
    case 27: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        NavMeshObstacleManager::GetSingleton()->RemoveObstacleReference(m_pWorldReferenceInfo);
        break;
    }
    case 28: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        NavMeshObstacleManager::GetSingleton()->AddObstacleReference(m_pWorldReferenceInfo);
        break;
    }
    case 29: {
        Character* pCharacter = static_cast<Character*>(akTask.m_akPackedTaskVariantData[1].pData);
        if (pCharacter)
            pCharacter->Reset3D();
        break;
    }
    case 30: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        bool isOpen = akTask.m_akPackedTaskVariantData[2].bData;
        bool bSnap = akTask.m_akPackedTaskVariantData[3].bData;
        if (m_pWorldReferenceInfo)
            BGSOpenCloseForm::SetOpenState(m_pWorldReferenceInfo, isOpen, bSnap);
        break;
    }
    case 33: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        NiPoint3 kPosition(akTask.m_akPackedTaskVariantData[2].fData, akTask.m_akPackedTaskVariantData[3].fData,
                           akTask.m_akPackedTaskVariantData[4].fData);
        if (pActor)
            pActor->SetPos(&kPosition);
        break;
    }
    case 34: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        int iFlags = akTask.m_akPackedTaskVariantData[2].iData;
        if (pObject)
        {
            Creature::SetNodeFlagsRecursive(pObject, iFlags, true, false, true);
            pObject->FUN_00401970();
        }
        break;
    }
    case 35: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        bool bFlag = akTask.m_akPackedTaskVariantData[2].bData;
        if (pActor)
            pActor->FUN_008a5f20(bFlag);
        break;
    }
    case 36: {
        float fWaterLevelItem = akTask.m_akPackedTaskVariantData[1].fData;
        NiPoint3 kPosition(akTask.m_akPackedTaskVariantData[2].fData, akTask.m_akPackedTaskVariantData[3].fData,
                           akTask.m_akPackedTaskVariantData[4].fData);
        TESWaterListener::UpdateWaterHeightAtPosition(fWaterLevelItem, kPosition);
        break;
    }
    case 37: {
        float rippleRadius = akTask.m_akPackedTaskVariantData[1].fData;
        NiPoint3 kPosition(akTask.m_akPackedTaskVariantData[2].fData, akTask.m_akPackedTaskVariantData[3].fData,
                           akTask.m_akPackedTaskVariantData[4].fData);
        g_TES->GetActorScale()->AddWaterRipple(kPosition, rippleRadius);
        break;
    }
    case 38: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        bool bFirstFlag = akTask.m_akPackedTaskVariantData[2].bData;
        bool bFlagB = akTask.m_akPackedTaskVariantData[3].bData;
        if (pActor)
            pActor->RefreshActorInteraction(bFirstFlag, bFlagB);
        break;
    }
    case 39: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        if (pActor)
            pActor->ProcessQueuedActorUpdate();
        break;
    }
    case 40: {
        Actor* pActor = static_cast<Actor*>(akTask.m_akPackedTaskVariantData[1].pData);
        if (pActor)
            pActor->OnLifeStateChanged();
        break;
    }
    case 41: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        m_pWorldReferenceInfo->vfn_01fc(false);
        break;
    }
    case 45: {
        TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(akTask.m_akPackedTaskVariantData[1].pData);
        m_pWorldReferenceInfo->AnimateNiNode();
        break;
    }
    case 42: {
        TESForm* pForm = TESForm::GetFormByID(akTask.m_akPackedTaskVariantData[1].iData);
        if (pForm && pForm->GetIsReference())
        {
            TESObjectREFR* m_pWorldReferenceInfo = static_cast<TESObjectREFR*>(pForm);
            m_pWorldReferenceInfo->Unload3D();
        }
        break;
    }
    case 49: {
        NiAVObject* pObject = static_cast<NiAVObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        FUN_00c69fc0(pObject, akTask.m_akPackedTaskVariantData[2].bData, akTask.m_akPackedTaskVariantData[3].bData,
                     akTask.m_akPackedTaskVariantData[4].bData);
        pObject->FUN_00401970();
        break;
    }
    case 44: {
        MobileObject* pActor = static_cast<MobileObject*>(akTask.m_akPackedTaskVariantData[1].pData);
        bhkCharacterController* pController = pActor->GetPhysicsCharacterController();
        if (pController)
        {
            pController->FUN_005620e0(static_cast<const TESObjectREFR*>(pActor)->GetPos());
            pController->FUN_0080fb00(FUN_00458b20());
            pController->FUN_005d10f0();
            pController->FUN_0087cee0();
            pController->ResetState();
        }
        break;
    }
    case 46: {
        ActiveEffect* pEffect = static_cast<ActiveEffect*>(akTask.m_akPackedTaskVariantData[1].pData);
        delete pEffect;
        break;
    }
    }
}

struct FUN_0043b370_cls
{
    char pad[0x30];
    unsigned int flags;
    void FUN_0043b370(bool set, unsigned int m);
};
// Sets or clears the bits of m in flags depending on set.
// @fnv 0x0043b370
void FUN_0043b370_cls::FUN_0043b370(bool set, unsigned int auiMask)
{
    if (set)
        flags |= auiMask;
    else
        flags &= ~auiMask;
}

struct FUN_0047aa60_cls
{
    char pad[8];
    unsigned short flags;
    void FUN_0047aa60(bool set, unsigned short m);
};
// Sets or clears the bits of flags selected by m, depending on set.
// @fnv 0x0047aa60
void FUN_0047aa60_cls::FUN_0047aa60(bool set, unsigned short ausMask)
{
    if (set)
        flags |= ausMask;
    else
        flags &= ~ausMask;
}

struct FUN_0087b190_shell : public TaskQueueInterface
{
    void QueueActorTask(Actor*);
};

// @fnv 0x0087b190
void FUN_0087b190_shell::QueueActorTask(Actor* apActor)
{
    char task[sizeof(BSPackedTask)];
    if (apActor)
    {
        reinterpret_cast<BSPackedTask&>(task).m_akPackedTaskVariantData[0].iData = 0x2c;
        reinterpret_cast<BSPackedTask&>(task).m_akPackedTaskVariantData[1].pData = apActor;
        ProcessPackedTask(reinterpret_cast<BSPackedTask&>(task));
    }
}

struct FUN_0087b270_shell : public TaskQueueInterface
{
    void QueueRefTask(TESObjectREFR*);
};

// @fnv 0x0087b270
void FUN_0087b270_shell::QueueRefTask(TESObjectREFR* apRef)
{
    union
    {
        BSPackedTask task;
        char gs[32];
    };
    task.m_akPackedTaskVariantData[0].iData = 0x29;
    task.m_akPackedTaskVariantData[1].pData = apRef;
    ProcessPackedTask(task);
}

struct FUN_0087b2b0_shell : public TaskQueueInterface
{
    void FUN_0087b2b0(TESObjectREFR*);
};


// @fnv 0x0087b2b0
void FUN_0087b2b0_shell::FUN_0087b2b0(TESObjectREFR* apRef)
{
    union
    {
        BSPackedTask task;
        char buf[32];
    } u;
    u.task.m_akPackedTaskVariantData[0].iData = 0x2a;
    u.task.m_akPackedTaskVariantData[1].iData = reinterpret_cast<TESSound*>(apRef)->Deallocate();
    ProcessPackedTask(u.task);
}

struct FUN_0087b400_shell : public TaskQueueInterface
{
    void FUN_0087b400(TESObjectREFR*);
};

// @fnv 0x0087b400
void FUN_0087b400_shell::FUN_0087b400(TESObjectREFR* apRef)
{
    union
    {
        BSPackedTask task;
        char gs_trigger[32];
    } u;
    u.task.m_akPackedTaskVariantData[0].iData = 0x17;
    u.task.m_akPackedTaskVariantData[1].pData = apRef;
    ProcessPackedTask(u.task);
}

struct FUN_0087b650_shell : public TaskQueueInterface
{
    void QueueActorLocationTask(Actor*, void*);
};

// @fnv 0x0087b650
void FUN_0087b650_shell::QueueActorLocationTask(Actor* apActor, void* aLocation)
{
    union
    {
        BSPackedTask task;
        char gs_trigger[32];
    };
    task.m_akPackedTaskVariantData[0].iData = 33;
    task.m_akPackedTaskVariantData[1].pData = apActor;
    task.m_akPackedTaskVariantData[2].fData = ((const NiPoint3*)aLocation)->x;
    task.m_akPackedTaskVariantData[3].fData = ((const NiPoint3*)aLocation)->y;
    task.m_akPackedTaskVariantData[4].fData = ((const NiPoint3*)aLocation)->z;
    ProcessPackedTask(task);
}

struct FUN_0087cee0_shell : public bhkCharacterController
{
    bool FUN_0087cee0();
};

struct DummyFlags
{
    int FUN_00621270(int flag);
};

// @fnv 0x0087cee0
bool FUN_0087cee0_shell::FUN_0087cee0()
{
    return ((DummyFlags*)((char*)this + 0x410))->FUN_00621270(0x80) != 0;
}

struct FUN_0087cf10_shell
{
    void* a;
    void* b;
    void* c;
    void* d;
    FUN_0087cf10_shell* __thiscall Construct(void* a, void* b, void* c);
};

// Stores the three arguments into fields a, b and c, clears field d, and returns this.
// @fnv 0x0087cf10
FUN_0087cf10_shell* __thiscall FUN_0087cf10_shell::Construct(void* apArg1, void* apArg2, void* apArg3)
{
    this->a = apArg1;
    this->b = apArg2;
    this->c = apArg3;
    this->d = 0;
    return this;
}

struct RagH
{
    bool FUN_00552490();
};


struct FUN_00844160_entry
{
    MobileObject* pActor;
    BSFadeNode* pNode;
};

struct FUN_00844160_shell
{
    FUN_00844160_entry* FUN_00844160(int aiIndex);
};

struct MobileObjectDialogueView
{
    bool IsInDialogueWithPlayer() const;
};

void __cdecl SetTlsValueAndReset(BSFadeNode* apNode, int aiState);

// @fnv 0x0087cfb0
void __cdecl FUN_0087cfb0(void* apData, int aiIndex)
{
    FUN_00844160_shell* pshell = static_cast<FUN_00844160_shell*>(apData);
    FUN_00844160_entry* pentry = pshell->FUN_00844160(aiIndex);
    if (pentry->pActor && *reinterpret_cast<RagH**>(reinterpret_cast<char*>(pentry->pActor) + 0xac) &&
        (*reinterpret_cast<RagH**>(reinterpret_cast<char*>(pentry->pActor) + 0xac))->FUN_00552490() &&
        !pentry->pNode->FUN_00552470() &&
        !reinterpret_cast<MobileObjectDialogueView*>(pentry->pActor)->IsInDialogueWithPlayer())
        SetTlsValueAndReset(pentry->pNode, 2);
}

extern int __cdecl InitScriptRunLock(void*);

struct FUN_0087adf0_shell
{
    int __thiscall InitScriptRunLockForSelf();
};

// @fnv 0x0087adf0
int __thiscall FUN_0087adf0_shell::InitScriptRunLockForSelf()
{
    return InitScriptRunLock((char*)this + 0x60);
}

float __cdecl GetFloatByType(int, int, int);
// Multiplies a by the rating returned by GetFloatByType(b, 0x18, 1) and returns the product.
// @fnv 0x00648c80
float __cdecl FUN_00648c80(float afConditionMult, int b)
{
    float fRating;
    float fConditionMult;
    fConditionMult = afConditionMult;
    fRating = GetFloatByType(b, 0x18, 1);
    fConditionMult *= fRating;
    return fConditionMult;
}

struct FUN_0087aa40_Holder
{
    void FUN_0087aa40(int, int);
};
// @fnv 0x0087aa40
void FUN_0087aa40_Holder::FUN_0087aa40(int aiArg0, int aiArg1)
{
    char buf[32];
    ((int*)buf)[0] = 0x20;
    ((int*)buf)[1] = aiArg0;
    ((int*)buf)[2] = aiArg1;
    ((TaskQueueInterface*)this)->ProcessPackedTask(*(BSPackedTask*)buf);
}

struct FUN_0087aa90_shell : TaskQueueInterface
{
    void FUN_0087aa90();
};
// @fnv 0x0087aa90
void FUN_0087aa90_shell::FUN_0087aa90()
{
    char task[32];
    ((BSPackedTask&)task).m_akPackedTaskVariantData[0].iData = 4;
    ProcessPackedTask((BSPackedTask&)task);
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011df214;
struct S5460
{
    unsigned int FUN_00845460();
};
struct S006950d0
{
    unsigned int* GetElement(unsigned int);
};
struct S0087ab50
{
    void SetPairIfEnabled(unsigned int, unsigned int);
};
// If the global flag is set, gets an index and stores a1 and a2 into the two elements of the array entry at that index.
// @fnv 0x0087ab50
void S0087ab50::SetPairIfEnabled(unsigned int uiFirst, unsigned int uiSecond)
{
    if (*g_011df214.Bool())
    {
        unsigned int uiIndex = ((S5460*)&DAT_011df244)->FUN_00845460();
        ((S006950d0*)&DAT_011df244)->GetElement(uiIndex)[0] = uiFirst;
        ((S006950d0*)&DAT_011df244)->GetElement(uiIndex)[1] = uiSecond;
    }
}

struct G00559a40
{
    void FUN_0040f6e0();
};
struct FakeTask
{
    int i0;
    void* p1;
    char rest[24];
};
struct FUN_0087abb0_shell : public TaskQueueInterface
{
    void FUN_0087abb0(G00559a40*);
};
// Builds a task with type 6 and the given object, calls the object's FUN_0040f6e0, then queues the packed task.
// @fnv 0x0087abb0
void FUN_0087abb0_shell::FUN_0087abb0(G00559a40* pObject)
{
    FakeTask task;
    task.i0 = 6;
    task.p1 = pObject;
    pObject->FUN_0040f6e0();
    ProcessPackedTask(reinterpret_cast<BSPackedTask&>(task));
}

namespace fnv_0087ac00 {
struct G00559a40
{
    void FUN_0040f6e0();
};
struct Owner0087ac00 : public TaskQueueInterface
{
    void QueueTaskWithTwoObjects(G00559a40*, G00559a40*, bool, bool);
};
// @fnv 0x0087ac00
void Owner0087ac00::QueueTaskWithTwoObjects(G00559a40* pFirstObject, G00559a40* pSecondObject, bool bFlag1, bool bFlag2)
{
    union U
    {
        BSPackedTask task;
        char buf[32];
    };
    U u;
    u.task.m_akPackedTaskVariantData[0].iData = 7;
    u.task.m_akPackedTaskVariantData[1].pData = pFirstObject;
    u.task.m_akPackedTaskVariantData[2].pData = pSecondObject;
    u.task.m_akPackedTaskVariantData[3].bData = bFlag1;
    u.task.m_akPackedTaskVariantData[4].bData = bFlag2;
    pFirstObject->FUN_0040f6e0();
    pSecondObject->FUN_0040f6e0();
    ProcessPackedTask(u.task);
}
}  // namespace fnv_0087ac00

namespace fnv_0087ac60 {
struct G00559a40
{
    void FUN_0040f6e0();
};
struct FUN_0087AC60_Holder
{
    void FUN_0087ac60(G00559a40*);
};
// If a1 is non-null, builds a BSPackedTask with id 8 and a1 as data, calls a1->FUN_0040f6e0(), then queues the task via this.
// @fnv 0x0087ac60
void FUN_0087AC60_Holder::FUN_0087ac60(G00559a40* pObject)
{
    if (pObject)
    {
        union
        {
            BSPackedTask task;
            char buf[32];
        };
        task.m_akPackedTaskVariantData[0].iData = 8;
        task.m_akPackedTaskVariantData[1].pData = pObject;
        pObject->FUN_0040f6e0();
        ((TaskQueueInterface*)this)->ProcessPackedTask(task);
    }
}
}  // namespace fnv_0087ac60

namespace fnv_0087acb0 {
struct G00559a40
{
    void FUN_0040f6e0();
};
struct FUN_0087acb0_host : TaskQueueInterface
{
    void FUN_0087acb0(G00559a40*);
};
// @fnv 0x0087acb0
void FUN_0087acb0_host::FUN_0087acb0(G00559a40* pObject)
{
    if (pObject)
    {
        union UU
        {
            BSPackedTask t;
            char c[32];
        } packedTask;
        packedTask.t.m_akPackedTaskVariantData[0].iData = 47;
        packedTask.t.m_akPackedTaskVariantData[1].pData = pObject;
        pObject->FUN_0040f6e0();
        ProcessPackedTask(packedTask.t);
    }
}
}  // namespace fnv_0087acb0

namespace fnv_0087ad00 {
struct G00559a40
{
    void FUN_0040f6e0();
};
struct TaskBuf0087ad00
{
    int v0;
    void* v1;
    void* v2;
    char rest[20];
};
struct H0087ad00
{
    void FUN_0087ad00(G00559a40* a1, void* a2);
};
// @fnv 0x0087ad00
void H0087ad00::FUN_0087ad00(G00559a40* apObject, void* apData)
{
    if (apObject)
    {
        TaskBuf0087ad00 task;
        task.v0 = 9;
        task.v1 = apObject;
        task.v2 = apData;
        apObject->FUN_0040f6e0();
        ((TaskQueueInterface*)this)->ProcessPackedTask((const BSPackedTask&)task);
    }
}
}  // namespace fnv_0087ad00

namespace fnv_0087ad50 {
struct G00559a40
{
    void FUN_0040f6e0();
};
struct Host : TaskQueueInterface
{
    void FUN_0087ad50(G00559a40*);
};
struct HostBuf
{
    int i0;
    G00559a40* p1;
    char c[24];
};
// @fnv 0x0087ad50
void Host::FUN_0087ad50(G00559a40* a1)
{
    if (a1)
    {
        HostBuf b;
        b.i0 = 10;
        b.p1 = a1;
        a1->FUN_0040f6e0();
        ProcessPackedTask((BSPackedTask&)b);
    }
}
}  // namespace fnv_0087ad50

namespace fnv_0087ada0 {
struct FUN_0087adf0_shell
{
    int InitScriptRunLockForSelf();
};
struct FUN_0087ada0_shell : public TaskQueueInterface
{
    void FUN_0087ada0(int, FUN_0087adf0_shell*);
};
// @fnv 0x0087ada0
void FUN_0087ada0_shell::FUN_0087ada0(int aiTaskArg, FUN_0087adf0_shell* a2)
{
    char buf[32];
    if (a2)
    {
        ((BSPackedTask*)buf)->m_akPackedTaskVariantData[0].iData = 11;
        ((BSPackedTask*)buf)->m_akPackedTaskVariantData[1].iData = aiTaskArg;
        ((BSPackedTask*)buf)->m_akPackedTaskVariantData[2].pData = a2;
        a2->InitScriptRunLockForSelf();
        ProcessPackedTask(*(BSPackedTask*)buf);
    }
}
}  // namespace fnv_0087ada0

namespace fnv_0087ae10 {
struct FUN_0087adf0_shell
{
    int InitScriptRunLockForSelf();
};
struct FUN_0087ae10_shell : TaskQueueInterface
{
    void FUN_0087ae10(int, FUN_0087adf0_shell*);
};
// @fnv 0x0087ae10
void FUN_0087ae10_shell::FUN_0087ae10(int a, FUN_0087adf0_shell* b)
{
    char task[32];
    if (b)
    {
        ((int*)task)[0] = 17;
        ((int*)task)[1] = a;
        ((FUN_0087adf0_shell**)task)[2] = b;
        b->InitScriptRunLockForSelf();
        ProcessPackedTask(*(BSPackedTask*)task);
    }
}
}  // namespace fnv_0087ae10

struct Host
{
    void QueueCheckTask(TESObjectREFR* p);
};
// @fnv 0x0087ae60
void Host::QueueCheckTask(TESObjectREFR* pObj)
{
    if (pObj && pObj->IsExplosion())
    {
        char buf[32];
        ((int*)buf)[0] = 12;
        ((TESObjectREFR**)buf)[1] = pObj;
        ((TaskQueueInterface*)this)->ProcessPackedTask(*(BSPackedTask*)buf);
    }
}

struct TaskBuf
{
    int i0;
    void* p1;
    float f2;
    bool b;
    char rest[19];
};
struct TaskQueueProxy : public TaskQueueInterface
{
    void QueueDamageTask(TESObjectREFR* apObject, float afDamage, bool abSelfDamage);
};
// @fnv 0x0087af50
void TaskQueueProxy::QueueDamageTask(TESObjectREFR* apObject, float afDamage, bool abSelfDamage)
{
    TaskBuf task;
    if (apObject)
    {
        task.i0 = 0xD;
        task.p1 = apObject;
        task.f2 = afDamage;
        task.b = abSelfDamage;
        ProcessPackedTask(reinterpret_cast<BSPackedTask&>(task));
    }
}

struct FUN_0087aff0_Buf
{
    int i0;
    void* p1;
    void* p2;
    void* p3;
    char rest[16];
};
struct FUN_0087aff0_This : TaskQueueInterface
{
    void FUN_0087aff0(void* a1, void* a2, void* a3);
};
// @fnv 0x0087aff0
void FUN_0087aff0_This::FUN_0087aff0(void* a1, void* a2, void* a3)
{
    if (a1)
    {
        FUN_0087aff0_Buf b;
        b.i0 = 14;
        b.p1 = a1;
        b.p2 = a2;
        b.p3 = a3;
        ProcessPackedTask(reinterpret_cast<BSPackedTask&>(b));
    }
}

struct FUN_0087b040_shell : public TaskQueueInterface
{
    void QueuePowerAttackTask(Actor* apActor, bool abPowerAttack, bool abInCombatAttack);
};
// If apActor is non-null, packs a task with id 15, the actor, and the two attack flags, then queues it.
// @fnv 0x0087b040
void FUN_0087b040_shell::QueuePowerAttackTask(Actor* apActor, bool abPowerAttack, bool abInCombatAttack)
{
    if (apActor)
    {
        char task[32];
        reinterpret_cast<BSPackedTask&>(task).m_akPackedTaskVariantData[0].iData = 15;
        reinterpret_cast<BSPackedTask&>(task).m_akPackedTaskVariantData[1].pData = apActor;
        reinterpret_cast<BSPackedTask&>(task).m_akPackedTaskVariantData[2].bData = abPowerAttack;
        reinterpret_cast<BSPackedTask&>(task).m_akPackedTaskVariantData[3].bData = abInCombatAttack;
        ProcessPackedTask(reinterpret_cast<BSPackedTask&>(task));
    }
}

namespace fnv_0087b0f0 {
struct G00559a40
{
    void FUN_0040f6e0();
};
struct FUN_0087b0f0_shell : TaskQueueInterface
{
    void FUN_0087b0f0(G00559a40*);
};
// @fnv 0x0087b0f0
void FUN_0087b0f0_shell::FUN_0087b0f0(G00559a40* p)
{
    if (p)
    {
        p->FUN_0040f6e0();
        char task[32];
        ((BSPackedTask*)task)->m_akPackedTaskVariantData[0].iData = 0x13;
        ((BSPackedTask*)task)->m_akPackedTaskVariantData[1].pData = p;
        ProcessPackedTask(*(BSPackedTask*)task);
    }
}
}  // namespace fnv_0087b0f0

namespace fnv_0087b140 {
struct G00559a40
{
    void FUN_0040f6e0();
};
struct FUN_0087b140_Holder : public TaskQueueInterface
{
    void QueueTaskIfPresent(G00559a40*);
};
// @fnv 0x0087b140
void FUN_0087b140_Holder::QueueTaskIfPresent(G00559a40* a)
{
    char buf[32];
    if (a)
    {
        a->FUN_0040f6e0();
        ((int*)buf)[0] = 20;
        ((G00559a40**)buf)[1] = a;
        ProcessPackedTask(*(BSPackedTask*)buf);
    }
}
}  // namespace fnv_0087b140

namespace fnv_0087b1e0 {
struct G00559a40
{
    void FUN_0040f6e0();
};
union TaskUnion
{
    BSPackedTask task;
    char buf[32];
};
struct Holder : TaskQueueInterface
{
    void FUN_0087b1e0(G00559a40* a1, int a2);
};
// @fnv 0x0087b1e0
void Holder::FUN_0087b1e0(G00559a40* apObject, int aiValue)
{
    if (apObject)
    {
        apObject->FUN_0040f6e0();
        TaskUnion task;
        task.task.m_akPackedTaskVariantData[0].iData = 0x22;
        task.task.m_akPackedTaskVariantData[1].pData = apObject;
        task.task.m_akPackedTaskVariantData[2].iData = aiValue;
        ProcessPackedTask(task.task);
    }
}
}  // namespace fnv_0087b1e0

struct FUN_0087b230_Holder : TaskQueueInterface
{
    void FUN_0087b230(int);
};
// @fnv 0x0087b230
void FUN_0087b230_Holder::FUN_0087b230(int aiValue)
{
    char task[32];
    ((int*)task)[0] = 45;
    ((int*)task)[1] = aiValue;
    ProcessPackedTask(*reinterpret_cast<BSPackedTask*>(task));
}

struct FUN_0087b440_holder
{
    void FUN_0087b440(int, int, int, bool, bool);
};
// @fnv 0x0087b440
void FUN_0087b440_holder::FUN_0087b440(int aiArg0, int aiArg1, int aiArg2, bool abFlag0, bool abFlag1)
{
    char buf[32];
    ((int*)buf)[0] = 0x18;
    ((int*)buf)[1] = aiArg0;
    ((int*)buf)[2] = aiArg1;
    ((int*)buf)[3] = aiArg2;
    buf[16] = abFlag0;
    buf[20] = abFlag1;
    reinterpret_cast<TaskQueueInterface*>(this)->ProcessPackedTask(*reinterpret_cast<BSPackedTask*>(buf));
}

struct FakeTaskQueue
{
    void FUN_0087b4a0(int a, int b, float c);
};
// Builds a 32-byte task with opcode 0x19 and the three arguments, then passes it to the queue interface.
// @fnv 0x0087b4a0
void FakeTaskQueue::FUN_0087b4a0(int aiArg1, int aiArg2, float afArg3)
{
    char task[32];
    ((int*)task)[0] = 0x19;
    ((int*)task)[1] = aiArg1;
    ((int*)task)[2] = aiArg2;
    ((float*)task)[3] = afArg3;
    ((TaskQueueInterface*)this)->ProcessPackedTask(*(BSPackedTask*)task);
}

struct Holder0087b4f0
{
    void FUN_0087b4f0(int a, int b, float c);
};
// Builds a BSPackedTask with id 26 and the three arguments, then queues it via TaskQueueInterface.
// @fnv 0x0087b4f0
void Holder0087b4f0::FUN_0087b4f0(int aiArg0, int aiArg1, float afArg2)
{
    char task[32];
    ((BSPackedTask*)task)->m_akPackedTaskVariantData[0].iData = 26;
    ((BSPackedTask*)task)->m_akPackedTaskVariantData[1].iData = aiArg0;
    ((BSPackedTask*)task)->m_akPackedTaskVariantData[2].iData = aiArg1;
    ((BSPackedTask*)task)->m_akPackedTaskVariantData[3].fData = afArg2;
    ((TaskQueueInterface*)this)->ProcessPackedTask(*(BSPackedTask*)task);
}

struct FUN_0087b540_Holder : public TaskQueueInterface
{
    void FUN_0087b540(int);
};
// @fnv 0x0087b540
void FUN_0087b540_Holder::FUN_0087b540(int a1)
{
    char buf[32];
    *reinterpret_cast<int*>(buf) = 0x1B;
    *reinterpret_cast<int*>(buf + 4) = a1;
    ProcessPackedTask(*reinterpret_cast<BSPackedTask*>(buf));
}

struct TaskBuf87580
{
    int i0;
    int i1;
    char rest[24];
};
struct Holder87b580
{
    void FUN_0087b580(int);
};
// Builds a task buffer with type 0x1c and the given value, then queues it through the task queue interface.
// @fnv 0x0087b580
void Holder87b580::FUN_0087b580(int aiValue)
{
    TaskBuf87580 t;
    t.i0 = 0x1c;
    t.i1 = aiValue;
    reinterpret_cast<TaskQueueInterface*>(this)->ProcessPackedTask(*reinterpret_cast<const BSPackedTask*>(&t));
}

struct Unnamed_0087b5c0 : TaskQueueInterface
{
    void FUN_0087b5c0(int);
};
// @fnv 0x0087b5c0
void Unnamed_0087b5c0::FUN_0087b5c0(int aiArg)
{
    char task[32];
    *(int*)&task[0] = 29;
    *(int*)&task[4] = aiArg;
    ProcessPackedTask(*(const BSPackedTask*)task);
}

struct FUN_0087b600_Holder : TaskQueueInterface
{
    void FUN_0087b600(int a, bool b, bool c);
};
// @fnv 0x0087b600
void FUN_0087b600_Holder::FUN_0087b600(int aiValue, bool abFlag1, bool abFlag2)
{
    char buf[32];
    ((int*)buf)[0] = 30;
    ((int*)buf)[1] = aiValue;
    buf[8] = abFlag1;
    buf[12] = abFlag2;
    ProcessPackedTask(*(BSPackedTask*)buf);
}

struct FUN_0087b6b0_shell : TaskQueueInterface
{
    void FUN_0087b6b0(int a1, bool b1);
};
// @fnv 0x0087b6b0
void FUN_0087b6b0_shell::FUN_0087b6b0(int aiValue, bool abFlag)
{
    char task[32];
    ((BSPackedTask*)task)->m_akPackedTaskVariantData[0].iData = 0x23;
    ((BSPackedTask*)task)->m_akPackedTaskVariantData[1].iData = aiValue;
    ((BSPackedTask*)task)->m_akPackedTaskVariantData[2].bData = abFlag;
    ProcessPackedTask(*(BSPackedTask*)task);
}

struct FUN_0087b700_shell : TaskQueueInterface
{
    void FUN_0087b700(float, NiPoint3*);
};
// @fnv 0x0087b700
void FUN_0087b700_shell::FUN_0087b700(float afValue, NiPoint3* apPoint)
{
    char task[32];
    ((BSPackedTask&)task).m_akPackedTaskVariantData[0].iData = 0x24;
    ((BSPackedTask&)task).m_akPackedTaskVariantData[1].fData = afValue;
    ((BSPackedTask&)task).m_akPackedTaskVariantData[2].fData = ((float*)apPoint)[0];
    ((BSPackedTask&)task).m_akPackedTaskVariantData[3].fData = ((float*)apPoint)[1];
    ((BSPackedTask&)task).m_akPackedTaskVariantData[4].fData = ((float*)apPoint)[2];
    ProcessPackedTask((BSPackedTask&)task);
}

struct Holder
{
    void FUN_0087b760(float, NiPoint3*);
};
// Builds a 0x25 task from a float and a NiPoint3 and queues it through TaskQueueInterface.
// @fnv 0x0087b760
void Holder::FUN_0087b760(float afValue, NiPoint3* apPoint)
{
    char task[32];
    ((int*)task)[0] = 0x25;
    ((float*)task)[1] = afValue;
    ((float*)task)[2] = ((float*)apPoint)[0];
    ((float*)task)[3] = ((float*)apPoint)[1];
    ((float*)task)[4] = ((float*)apPoint)[2];
    ((TaskQueueInterface*)this)->ProcessPackedTask(*(BSPackedTask*)task);
}

struct FUN_0087b7c0_Proxy : TaskQueueInterface
{
    void FUN_0087b7c0(int a, bool b, bool c);
};
// @fnv 0x0087b7c0
void FUN_0087b7c0_Proxy::FUN_0087b7c0(int aiValue, bool abFlag1, bool abFlag2)
{
    char buf[32];
    ((int*)buf)[0] = 0x26;
    ((int*)buf)[1] = aiValue;
    buf[8] = abFlag1;
    buf[12] = abFlag2;
    ProcessPackedTask(*(BSPackedTask*)buf);
}

struct FUN_0087b810_Host : TaskQueueInterface
{
    void QueueTaskWithId(int);
};
// @fnv 0x0087b810
void FUN_0087b810_Host::QueueTaskWithId(int aiValue)
{
    union U
    {
        char buf[32];
        BSPackedTask task;
    } u;
    u.task.m_akPackedTaskVariantData[0].iData = 39;
    u.task.m_akPackedTaskVariantData[1].iData = aiValue;
    ProcessPackedTask(u.task);
}

namespace fnv_0087b850 {
struct Holder
{
    void FUN_0087b850(int);
};
// @fnv 0x0087b850
void Holder::FUN_0087b850(int aiValue)
{
    char task[32];
    *reinterpret_cast<int*>(task) = 0x28;
    *reinterpret_cast<int*>(task + 4) = aiValue;
    reinterpret_cast<TaskQueueInterface*>(this)->ProcessPackedTask(*reinterpret_cast<const BSPackedTask*>(task));
}
}  // namespace fnv_0087b850

struct MyOwner : public TaskQueueInterface
{
    void QueueTaskWithValue(int);
};
// @fnv 0x0087b890
void MyOwner::QueueTaskWithValue(int aiValue)
{
    union
    {
        BSPackedTask task;
        char buf[32];
    } u;
    u.task.m_akPackedTaskVariantData[0].iData = 46;
    u.task.m_akPackedTaskVariantData[1].iData = aiValue;
    ProcessPackedTask(u.task);
}

int __cdecl FinishScriptRunLock(void*);
void __cdecl _Deallocate(void*);
struct S_0087cea0
{
    void ReleaseScriptRunLock();
};
// Releases the script run lock at offset 0x60; if that fails, deallocates this object.
// @fnv 0x0087cea0
void S_0087cea0::ReleaseScriptRunLock()
{
    if (!FinishScriptRunLock((void*)((char*)this + 0x60)))
    {
        void* p = this;
        _Deallocate(p);
    }
}

struct Unk_0097fa10
{
    char _pad[128];
    ActorCombatGroup* m_pGroup;
    bool FUN_0097fa10(Actor*);
};
// @fnv 0x0097fa10
bool Unk_0097fa10::FUN_0097fa10(Actor* apActor)
{
    return m_pGroup ? m_pGroup->ContainsActor(apActor) : false;
}

struct FUN_0087a890_shell
{
    void* vtbl;
    void* m_04;
    void __thiscall CallVirtualMethod1(int a);
};
// @fnv 0x0087a890
void __thiscall FUN_0087a890_shell::CallVirtualMethod1(int a)
{
    ((void(__thiscall*)(void*, int))((void**)this->vtbl)[1])(this, a);
}

struct FUN_0087afa0_Holder : TaskQueueInterface
{
    void FUN_0087afa0(void* a1, bool a2);
};
// @fnv 0x0087afa0
void FUN_0087afa0_Holder::FUN_0087afa0(void* apTaskData, bool abFlag)
{
    struct TaskBuf
    {
        int i0;
        void* p1;
        bool b2;
        char pad[23];
    };
    TaskBuf task;
    if (apTaskData)
    {
        task.i0 = 0x30;
        task.p1 = apTaskData;
        task.b2 = abFlag;
        ProcessPackedTask(reinterpret_cast<BSPackedTask&>(task));
    }
}

namespace fnv_0087aad0 {
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct S2f850
{
    unsigned int FUN_006c61b0(const GO&);
};
struct FUN_0087aad0_s
{
    void FUN_0087aad0(int);
};
// If the global flag at DAT_011df1b8 is set, constructs a GO from a and passes it to FUN_006c61b0 on DAT_011df1c4.
// @fnv 0x0087aad0
void FUN_0087aad0_s::FUN_0087aad0(int a)
{
    if (*(unsigned char*)((GlobalObject_0045cf30*)(void*)&DAT_011df1b8)->Bool())
    {
        GO t(a);
        ((S2f850*)(void*)&DAT_011df1c4)->FUN_006c61b0(t);
    }
}
}  // namespace fnv_0087aad0

class FNVFloatSource
{
  public:
    float* GetValue();
};
extern FNVFloatSource* DAT_0119b310[];
extern FNVFloatSource* DAT_0119b324[];
extern FNVFloatSource* DAT_0119b338[];

// Returns a float from one of three FNVFloatSource arrays selected by type (0x10 or 0x18) and useAlt, defaulting to 1.0f.
// @fnv 0x00648cb0
float __cdecl GetFloatByType(int index, int type, int useAlt)
{
    float result = 1.0f;
    switch (type)
    {
    case 0x10:
        result = ((unsigned char)useAlt != 0) ? *DAT_0119b310[index]->GetValue() : *DAT_0119b324[index]->GetValue();
        break;
    case 0x18:
        result = *DAT_0119b338[index]->GetValue();
        break;
    }
    return result;
}

struct FunTask090
{
    int i0;
    void* p1;
    float f[4];
    int unk18;
    bool unk1c;
    char pc1d[3];
};

struct FUN_0087b090_shell
{
    void Q160(FunTask090*);
    void FUN_0087b090(unsigned int a1, float a2, float a3, float a4, float a5);
};

// Fills a FunTask090 with the given pointer and four floats and passes it to Q160 when the pointer is non-null.
// @fnv 0x0087b090
void FUN_0087b090_shell::FUN_0087b090(unsigned int a1, float a2, float a3, float a4, float a5)
{
    FunTask090 task;
    if (a1 != 0)
    {
        task.i0 = 0x10;
        task.p1 = (void*)a1;
        task.f[0] = a2;
        task.f[1] = a3;
        task.f[2] = a4;
        task.f[3] = a5;
        this->Q160(&task);
    }
}

struct FUN_0087a670
{
    unsigned int taskIdentifier;
    unsigned int taskFlags;
    void* taskContext;
    unsigned int taskState;
    FUN_0087a670(unsigned int first, unsigned int second);
};
extern FUN_0087a670* DAT_011df1a8;
// Allocates a FUN_0087a670 task object with the two given values and stores it in DAT_011df1a8.
// @fnv 0x0087b8d0
void __cdecl FUN_0087b8d0(unsigned int first, unsigned int second)
{
    DAT_011df1a8 = new FUN_0087a670(first, second);
}

namespace fnv_0087b950 {
class FNVTaskQueueStub
{
  public:
    void* FUN_007b3fa0_stub(int a);
};

extern FNVTaskQueueStub* DAT_011df1a8;

// Calls FUN_007b3fa0_stub(1) on DAT_011df1a8 if non-null, then sets DAT_011df1a8 to null.
// @fnv 0x0087b950
void __cdecl ClearTaskQueue()
{
    FNVTaskQueueStub* queue = DAT_011df1a8;
    FNVTaskQueueStub* first = queue;
    void* result;
    if (first != 0)
    {
        result = first->FUN_007b3fa0_stub(1);
    }
    else
    {
        result = 0;
    }
    DAT_011df1a8 = 0;
}
}  // namespace fnv_0087b950


// @fnv 0x0087ce50
float FUN_0087ce50_cls::GetHeadTail()
{
    return Head()->Tail();
}

// the map object is a concrete NiTMap (NiTMapBase is abstract)
extern NiTMap<unsigned int, CombatThreatRecord*> DAT_011c4104;

// @fnv 0x0087ce70
NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int,
           CombatThreatRecord*>* __cdecl FUN_0087ce70()
{
    return &DAT_011c4104;
}

struct WrapperShell;
struct AnimObj;

struct TaskShell
{
    WrapperShell* FUN_006a7ad0(void* pvArg);
};

struct WrapperShell
{
    AnimObj* FUN_00559450();
};

struct AnimObj
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
    virtual void v09();
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
    virtual void Update(const NiUpdateData&);
};

// @fnv 0x0087cf50
void UpdateAnimObjFromTask(unsigned int auiTask, void* pvArg)
{
    TaskShell* pTask = reinterpret_cast<TaskShell*>(auiTask);
    AnimObj* pObj = pTask->FUN_006a7ad0(pvArg)->FUN_00559450();
    if (pObj != 0)
    {
        NiUpdateData upd(0.0f, false, false);
        pObj->Update(upd);
    }
}

struct PhysicsState
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual void vfn_00e8();
    virtual void vfn_00ec();
    virtual void vfn_00f0();
    virtual void vfn_00f4();
    virtual void vfn_00f8();
    virtual void vfn_00fc();
    virtual void vfn_0100();
    virtual void vfn_0104();
    virtual void vfn_0108();
    virtual void vfn_010c();
    virtual void vfn_0110();
    virtual void vfn_0114();
    virtual void vfn_0118();
    virtual void vfn_011c();
    virtual void vfn_0120();
    virtual void vfn_0124();
    virtual void vfn_0128();
    virtual void vfn_012c();
    virtual void vfn_0130();
    virtual void vfn_0134();
    virtual void vfn_0138();
    virtual void vfn_013c();
    virtual void vfn_0140();
    virtual void vfn_0144();
    virtual void vfn_0148();
    virtual void vfn_014c();
    virtual void vfn_0150();
    virtual void vfn_0154();
    virtual void vfn_0158();
    virtual void vfn_015c();
    virtual void vfn_0160();
    virtual void vfn_0164();
    virtual void vfn_0168();
    virtual void vfn_016c();
    virtual void vfn_0170();
    virtual void vfn_0174();
    virtual void vfn_0178();
    virtual void vfn_017c();
    virtual void vfn_0180();
    virtual void vfn_0184();
    virtual void vfn_0188();
    virtual void vfn_018c();
    virtual void vfn_0190();
    virtual void vfn_0194();
    virtual void vfn_0198();
    virtual void vfn_019c();
    virtual void vfn_01a0();
    virtual void vfn_01a4();
    virtual void vfn_01a8();
    virtual void vfn_01ac();
    virtual void vfn_01b0();
    virtual void vfn_01b4();
    virtual void vfn_01b8();
    virtual void vfn_01bc();
    virtual void vfn_01c0();
    virtual void vfn_01c4();
    virtual void vfn_01c8();
    virtual void vfn_01cc();
    virtual int IsEligible();
};
struct ActorController
{
    PhysicsState* FUN_00822b40();
};
struct EntityRef
{
    ActorController* FUN_0059bb30();
};
struct FUN_0087aec0_shell : TaskQueueInterface
{
    void FUN_0087aec0(EntityRef* reference);
    void FUN_0087d160(const FakeTask& task);
};
// @fnv 0x0087aec0
void FUN_0087aec0_shell::FUN_0087aec0(EntityRef* reference)
{
    if (reference)
    {
        FakeTask task;
        task.i0 = 0x12;
        if (reference->FUN_0059bb30()->FUN_00822b40())
        {
            if (reference->FUN_0059bb30()->FUN_00822b40()->IsEligible())
            {
                task.p1 = reference;
                FUN_0087d160(task);
            }
        }
        else
        {
            task.p1 = reference;
            FUN_0087d160(task);
        }
    }
}

#include <stdarg.h>
class FormTaskRef
{
  public:
    unsigned int GetFormID();
};
struct ScriptParamInfo
{
    const char* name;
    unsigned int type;
    unsigned int optional;
};
struct ScriptCommandInfo
{
    const char* name;
    const char* shortName;
    unsigned int opcode;
    const char* help;
    unsigned short needsParent;
    unsigned short numParams;
    ScriptParamInfo* params;
    void* execute;
    void* parse;
    void* evaluate;
    unsigned int flags;
};
extern ScriptCommandInfo scriptCommands[];
union TaskScalar
{
    int iData;
    float fData;
};
struct PlainPackedTask
{
    TaskScalar m_akPackedTaskVariantData[8];
};
// Packs a script command opcode, form ID, and variadic parameters into a 32-byte task buffer and submits it to the task queue.
// @fnv 0x0087a8b0
void __cdecl FUN_0087a8b0(TaskQueueInterface* queue, unsigned int opcode, FormTaskRef* form, ...)
{
    int h;
    int p;
    unsigned short a;
    char task[32];
    ((int*)task)[0] = 31;
    ((int*)task)[1] = opcode;
    if (form)
        ((int*)task)[2] = form->GetFormID();
    else
        ((int*)task)[2] = 0;
    {
        va_list args;
        va_start(args, form);
        h = 3;
        p = opcode - 0x1000;
        a = scriptCommands[p].numParams;
        for (int s = 0; s < a; s++)
        {
            if (h < 8)
            {
                switch (scriptCommands[p].params[s].type)
                {
                case 2:
                    ((float*)task)[h++] = (float)va_arg(args, double);
                    break;
                case 1:
                case 8:
                    ((int*)task)[h++] = va_arg(args, int);
                    break;
                case 4:
                case 6: {
                    FormTaskRef* k = va_arg(args, FormTaskRef*);
                    if (k)
                        ((int*)task)[h] = k->GetFormID();
                    else
                        ((int*)task)[h] = 0;
                    h++;
                    break;
                }
                }
            }
        }
        va_end(args);
    }
    queue->ProcessPackedTask(*(const BSPackedTask*)&task);
}

// Use the game's out-of-line smart-pointer constructor and destructor.
template <> NiPointer<NiAVObject>::NiPointer(NiAVObject* object);
template <> NiPointer<NiAVObject>::~NiPointer();

// The game calls its own instances of these helpers here (GetAt 0x6a7ad0, Add 0x6c61b0, Clear 0x6c6200,
// NiNode child count/child accessors 0x43b480/0x43b4a0), so they get function-specific names that no other
// function in the file binds elsewhere.
class FUN_0087d030_NodeChildren : public NiNode
{
  public:
    unsigned int FUN_0043b480();
    NiAVObject* GetAt(unsigned int index);
};

class FUN_0087d030_ParentArray
{
  public:
    void** m_ppVirtualMethodTable;
    NiPointer<NiNode>* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    NiPointer<NiNode>& GetAt(int index);
    void Clear(bool freeMemory);
};

class FUN_0087d030_ObjectArray
{
  public:
    void** m_ppVirtualMethodTable;
    NiPointer<NiAVObject>* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int Add(NiPointer<NiAVObject>& item);
};

// Iterates a global parent array, adding each child (or the parent itself when it has ten or fewer children) to apArray, then clears the global array.
// @fnv 0x0087d030
void FUN_0087d030(BSScrapArray<NiPointer<NiAVObject>, 1024>* apArray)
{
    unsigned int uiParentCount = ((FUN_0087d030_ParentArray&)DAT_011df1c4).GetSize();
    for (unsigned int iParentIndex = 0; iParentIndex < uiParentCount; iParentIndex++)
    {
        NiNode* pParent = ((FUN_0087d030_ParentArray&)DAT_011df1c4).GetAt(iParentIndex);
        unsigned int uiChildCount = ((FUN_0087d030_NodeChildren*)pParent)->FUN_0043b480();
        if (uiChildCount > 10)
        {
            for (unsigned int iChildIndex = 0; iChildIndex < uiChildCount; iChildIndex++)
            {
                NiAVObject* pChild = ((FUN_0087d030_NodeChildren*)pParent)->GetAt(iChildIndex);
                if (pChild)
                {
                    NiPointer<NiAVObject> spChild(pChild);
                    ((FUN_0087d030_ObjectArray*)apArray)->Add(spChild);
                }
            }
        }
        else
        {
            NiPointer<NiAVObject> spRetainedObject(pParent);
            ((FUN_0087d030_ObjectArray*)apArray)->Add(spRetainedObject);
        }
    }
    ((FUN_0087d030_ParentArray&)DAT_011df1c4).Clear(false);
}
