// fallout/ai/ailineartaskthreadmanager.cpp: AIThreadManager (21 functions)

#include <new>
#include "ailineartaskthreadmanager_rendering.h"
#include "../../../include/AILinearTaskThread.h"
#include "../../../include/BSThread.h"
#include "../../../include/ActorMover.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BGSDestructibleObjectForm.h"
#include "../../../include/CombatTargetMap.h"
#include "../../../include/CountingSemaphore.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/RecursiveSpinLock.h"
#include "../../../include/SkyObject.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/NavMeshObstacleManager.h"

typedef void(__cdecl* AIThreadFunction)();




class AIThreadManager
{
  public:
    enum AI_THREAD_INDEX
    {
        AI_THREAD_1 = 0,
        AI_THREAD_2 = 1,
        AI_THREAD_COUNT = 2
    };
    AILinearTaskThread* m_pTaskThreads[3];
    unsigned char layoutPadding0[0x30];
    void* threadHandles1[12];
    void* threadHandles2[8];
    void LaunchWorkerThread(AI_THREAD_INDEX, unsigned int, AIThreadFunction, const char*, BSThread::StackSize);
    void StartRenderingTaskThread();
    static void SetThreadingEnabled(bool);
};

extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern "C" unsigned int gPreferredMoveMode;

// @fnv 0x008c7290
void AIThreadManager::StartRenderingTaskThread()
{
    int i = 0;
    int j;
    for (; i <= 11; ++i)
        threadHandles1[i] = CreateEventA(0, 1, 0, 0);

    j = 0;
    for (; j <= 7; ++j)
        threadHandles2[j] = CreateEventA(0, 1, 0, 0);

    if (*reinterpret_cast<int*>(((SettingT_GameSettingCollection_*)0x011c3ea4)->Int()) > 2)
    {
        LaunchWorkerThread(AI_THREAD_1, *reinterpret_cast<int*>(((SettingT_GameSettingCollection_*)0x011dfb34)->Int()),
                           (AIThreadFunction)0x008c7da0, "AI Linear Task Thread 1", (BSThread::StackSize)0x10000);
        LaunchWorkerThread(AI_THREAD_2, *reinterpret_cast<int*>(((SettingT_GameSettingCollection_*)0x011dfb18)->Int()),
                           (AIThreadFunction)0x008c7f50, "AI Linear Task Thread 2", (BSThread::StackSize)0x10000);
    }
    else
    {
        LaunchWorkerThread(AI_THREAD_1, *reinterpret_cast<int*>(((SettingT_GameSettingCollection_*)0x011dfb34)->Int()),
                           (AIThreadFunction)0x008c7bd0, "AI Linear Task Thread", (BSThread::StackSize)0x10000);
    }

    gPreferredMoveMode = ((ActorMover*)m_pTaskThreads[0])->GetCurrentMoveModeType();
}

// @fnv 0x008c74d0
void AIThreadManager::LaunchWorkerThread(AI_THREAD_INDEX threadIndex, unsigned int processor,
                                         AIThreadFunction taskFunction, const char* threadName,
                                         BSThread::StackSize stackSize)
{
    if (threadIndex < 3 && threadIndex < 2 && !m_pTaskThreads[threadIndex])
    {
        m_pTaskThreads[threadIndex] = new AILinearTaskThread(taskFunction);
        m_pTaskThreads[threadIndex]->Initialize(stackSize, threadName, false);
        m_pTaskThreads[threadIndex]->SetSchedulingPriority(processor);
        m_pTaskThreads[threadIndex]->SetThreadPriority(0);

        if (!threadName)
        {
            char generatedName[0x104];
            sprintf_s(generatedName, 0x104, "AI Linear Task Thread DEF %i", threadIndex);
            m_pTaskThreads[threadIndex]->SetName(generatedName);
        }
    }
}

// Updates DAT_011dfa18 to the rendering flag and, when it was set and rendering is false, calls FUN_008c80c0.
// @fnv 0x008c80e0
void AIThreadManager::SetThreadingEnabled(bool rendering)
{
    if (DAT_011dfa18 && !rendering)
    {
        DAT_011dfa18 = rendering;
        FUN_008c80c0();
    }
    DAT_011dfa18 = rendering;
}


struct FUN_008c7490_this
{
    char pad[0x3c];
    CountingSemaphore sem;
};

// @fnv 0x008c7490
void __fastcall FUN_008c7490(FUN_008c7490_this* pThis)
{
    pThis->sem.Wait();
}

struct ActiveEffect;
struct Actor;
struct PackedTaskQueueProcessor;
struct Character;
struct DismemberLimbTaskData;
struct BooleanFloatQuery;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiNode;
struct TESBoundObject;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TaskQueueInterface
{
    void ThreadProcessInput();
    void ThreadBeginSecondaryInput();
    void ThreadProcessSecondaryInput();
    void ThreadEndSecondaryInput();
    void ProcessQueue();
    void ProcessTaskQueue();
    unsigned long QProcessingThread();
    void ExamplePrintFloat(float);
    void ExamplePrintInt(int);
    void QueueSkyEmittanceUpdate(NiNode*, NiColor*);
    void ProcessPackedTask(unsigned int, TESObjectREFR*, ...);
    void QueueWeaponFire(TESObjectWEAP*, TESObjectREFR*);
    void QueueParallelTaskProcessing();
    void QueueCellTransformChildTask(NiNode*);
    void QueueActorHavokSync(NiNode*);
    void QueueActorNodeUpdate(Actor*, NiAVObject*);
    void QueueParticlesUpdate(NiNode*);
    void QueueMorphControllerUpdate(NiNode*);
    void QueueNodeAttach(NiAVObject*, NiNode*, bool, bool);
    void QueueNodeDetach(NiAVObject*);
    void QueueBiped3DDetach(NiAVObject*);
    void QueueSSNRemoveObject(NiAVObject*, int);
    void QueueObjectUpdate(NiAVObject*);
    void QueueActorHitMe(Actor*, BooleanFloatQuery*);
    void QueueActorCreateBlood(Actor*, BooleanFloatQuery*);
    void QueueMobileObjectInitialize(MobileObject*);
    void QueueMHEInstantiateHitEffects(ActiveEffect*);
    void QueueReferenceFloatTask(TESObjectREFR*, float, bool);
    void QueuePickedUpObjectRemoval(TESObjectREFR*, bool);
    void QueueActorDismemberLimb(Actor*, float*, DismemberLimbTaskData*);
    void QueueActorCombatTask(Actor*, bool, bool);
    void QueueActorKnockExplosion(Actor*, float, float, float, float);
    void QueueHavokInit(TESObjectREFR*);
    void QueueHavokAdd(NiAVObject*);
    void QueueHavokDelete(NiAVObject*);
    void QueueHavokMotionChange(NiAVObject*, int);
    void QueueHavokMove(TESObjectREFR*);
    void QueueHavokDetach(TESObjectREFR*);
    void QueueHavokAdjustForceAddCount(NiAVObject*, bool, bool, bool);
    void CopyStringToBuffer(Actor*, TESObjectWEAP*);
    void QueueRemoveWeapon(Actor*, TESBoundObject*);
    void QueueSet3DNull(TESObjectREFR*);
    void QueueDismemberLimb(Actor*, int, int, bool, bool);
    void QueueWaterObjectForAdd(TESObjectREFR*, TESObjectREFR*, float);
    void QueueWaterObjectForRemove(TESObjectREFR*, TESObjectREFR*, float);
    void QueueObstacleDoorOpen(TESObjectREFR*);
    void QueueObstacleDoorClose(TESObjectREFR*);
    void QueueCharacterReset3D(Character*);
    void QueueReferenceStateTask(TESObjectREFR*, bool, bool);
    void QueueActorDataTask(Actor*, void*);
    void QueueActorSetHavokWeapon(Actor*, bool);
    void QueueWaterSplashEffects(float, void*);
    void QueueAddRipple(float, void*);
    void QueueActorTriggerPain(Actor*, bool, bool);
    void QueueActorDisarm(Actor*);
    void QueueActorResetLoadedAnims(Actor*);
    void QueueActorAnimationTask(Actor*);
    void QueueDeleteActiveEffect(ActiveEffect*);
    static void Instantiate(PackedTaskQueueProcessor*, PackedTaskQueueProcessor*);
    static void Shutdown();
    static TaskQueueInterface* GetInstance();
    static void ProcessQueuedTask(void*);
    bool QQueueFurtherTasks();
    static bool QActive();
    static void SetActive(bool);
    PackedTaskQueueProcessor* GetActiveQueue();
    void SetActiveQueue(void*);
    void* __vecDelDtor(unsigned int);
    PackedTaskQueueProcessor* m_pPrimaryTaskProcessor;
    PackedTaskQueueProcessor* m_pSecondaryTaskProcessor;
    PackedTaskQueueProcessor* m_pTaskQueueProcessor;
    unsigned long m_uiTaskFlags;
};
typedef char _sizecheck_TaskQueueInterface[sizeof(TaskQueueInterface) == 16 ? 1 : -1];

unsigned int __cdecl gm_GetCurrentThreadId(void);
bool __cdecl FUN_00713d90(void);
bool __fastcall FUN_0087a730(void*);
bool __cdecl FUN_008c7bc0(void);
void* __stdcall FUN_00713d80(int);
unsigned int __fastcall GetValueWithItemResult(void*);
unsigned long __fastcall _ref_0084e3a0(void*);
extern SettingT_GameSettingCollection_ g_011c3ea4;
extern BSAudio* g_osGlobals;

// @fnv 0x008c7aa0
bool __cdecl FUN_008c7aa0()
{
    bool bretval = false;
    bool bretvalBug44071 = false;
    if (*reinterpret_cast<int*>(g_011c3ea4.Int()) > 1 && FUN_00713d90())
    {
        TaskQueueInterface* pqueueInterface = TaskQueueInterface::GetInstance();
        if (FUN_0087a730(pqueueInterface))
            bretvalBug44071 = true;

        unsigned long icurrthread = gm_GetCurrentThreadId();
        if (icurrthread != (unsigned long)g_osGlobals->GetAudioBackendData())
        {
            if (FUN_008c7bc0() || GetValueWithItemResult(FUN_00713d80(1)) < 6)
                bretval = true;
        }
        else
        {
            if (!FUN_008c7bc0())
            {
                if (GetValueWithItemResult(FUN_00713d80(0)) < 11 || GetValueWithItemResult(FUN_00713d80(1)) < 7)
                    bretval = true;
                else
                    bretval = false;
            }
        }

        if (!bretval)
        {
            unsigned long iprocessthread = _ref_0084e3a0(TaskQueueInterface::GetInstance());
            if (iprocessthread != 0 && icurrthread != iprocessthread)
                bretval = true;
        }
    }
    bretval = bretval || bretvalBug44071;
    return bretval;
}

__declspec(thread) int DAT_tls_0264;
// @fnv 0x0047b200
int FUN_0047b200()
{
    return DAT_tls_0264;
}

struct FUN_0086c600_shell
{
    void SignalAtOffset();
};
struct FUN_0087a6b0_shell
{
    FUN_0086c600_shell* p;
    void FUN_0087a6b0();
};
// @fnv 0x0087a6b0
void FUN_0087a6b0_shell::FUN_0087a6b0()
{
    p->SignalAtOffset();
}

struct FUN_0086cdd0_shell
{
    void FUN_0086cdd0();
};
struct FUN_0087a6d0_shell
{
    FUN_0086cdd0_shell* p;
    void FUN_0087a6d0();
};
// @fnv 0x0087a6d0
void FUN_0087a6d0_shell::FUN_0087a6d0()
{
    p->FUN_0086cdd0();
}

namespace fnv_008c74b0 {

struct FUN_008c74b0_shell
{
    unsigned char layoutPadding[0x48];
    CountingSemaphore semaphore;
    void SignalThread();
};

// @fnv 0x008c74b0
void FUN_008c74b0_shell::SignalThread()
{
    ((unsigned char*)this)[0x48] = 1;
    ((CountingSemaphore*)((unsigned char*)this + 0x30))->Signal();
}
}  // namespace fnv_008c74b0

extern bool DAT_011dfa18;

// @fnv 0x008c7bc0
bool FUN_008c7bc0()
{
    return DAT_011dfa18;
}

namespace fnv_008c80b0 {

extern CountingSemaphore g_011dfafc;

// @fnv 0x008c80b0
void FUN_008c80b0()
{
    g_011dfafc.Wait();
}
}  // namespace fnv_008c80b0

namespace fnv_008c80c0 {
extern CountingSemaphore g_011dfafc;

// @fnv 0x008c80c0
void FUN_008c80c0()
{
    g_011dfafc.Signal();
}
}  // namespace fnv_008c80c0

void __cdecl FUN_008c80b0();

// @fnv 0x008c80d0
void __cdecl FUN_008c80d0()
{
    FUN_008c80b0();
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
struct FUN_008c79e0_shell
{
    void* apThreads[3];
    int aiCurrent[2];
    char pad[0x78];
    void** ppEvents[2];
    void SignalThreadEvent(int aiIndex, int aiEvent);
};
// If aiIndex is below 2 and the thread handle exists, signals the event at ppEvents[aiIndex][aiEvent] and stores aiEvent in aiCurrent[aiIndex].
// @fnv 0x008c79e0
void FUN_008c79e0_shell::SignalThreadEvent(int aiIndex, int aiEvent)
{
    if (aiIndex < 2 && apThreads[aiIndex])
    {
        SetEvent(ppEvents[aiIndex][aiEvent]);
        aiCurrent[aiIndex] = aiEvent;
    }
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
struct FUN_008c7a70_shell
{
    char pad[0x8c];
    void** ppEvents[2];
    void WaitForEvent(int aiIndex, int aiEvent);
};
// Waits indefinitely on the event at ppEvents[aiIndex][aiEvent].
// @fnv 0x008c7a70
void FUN_008c7a70_shell::WaitForEvent(int aiIndex, int aiEvent)
{
    WaitForSingleObject(ppEvents[aiIndex][aiEvent], 0xffffffff);
}

struct FUN_008c7d80_shell
{
    void* m_pObjectPointers[3];
    int aiCurrent[2];
    char pad[0x74];
    void SetCurrent(int aiIndex, int aiValue);
};
// @fnv 0x008c7d80
void FUN_008c7d80_shell::SetCurrent(int aiIndex, int aiValue)
{
    aiCurrent[aiIndex] = aiValue;
}

struct ArrHelper
{
    unsigned int GetSize();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct FUN_00986c40_obj
{
    bool FUN_00986c40();
    void FUN_00986150();
};
extern Twin_0084d030 g_timeGlobal;
void __cdecl FUN_009915e0(float);
struct FUN_00991500_shell
{
    char pad[0x14];
    CombatTargetMap* m_pTargetMap;
    void FUN_00991500(bool abFlag);
};
// @fnv 0x00991500
void FUN_00991500_shell::FUN_00991500(bool abFlag)
{
    AutoMemHelper kMem(0x2b, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\CombatManager.cpp",
                       0x8b);
    if (!abFlag)
    {
        FUN_009915e0(g_timeGlobal.GetStoredFloatValue());
        for (unsigned int i = 0; i < ((ArrHelper*)this)->GetSize(); i++)
        {
            FUN_00986c40_obj* pEntry = (FUN_00986c40_obj*)*((Arr*)this)->GetAt(i);
            if (pEntry && !pEntry->FUN_00986c40())
                pEntry->FUN_00986150();
        }
        m_pTargetMap->ResetTargetMap();
    }
}

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

void __fastcall FUN_008c74b0(void*);
void __fastcall FUN_008c7490(void*);

struct TaskThreadStandin
{
    virtual ~TaskThreadStandin();
};

struct FUN_008c73a0_shell : public AIThreadManager
{
    void FUN_008c73a0();
};

// @fnv 0x008c73a0
void FUN_008c73a0_shell::FUN_008c73a0()
{
    unsigned int i;
    int j;
    int iHandleIndex1;

    for (i = 0; i < 2; ++i)
    {
        if (m_pTaskThreads[i])
        {
            FUN_008c74b0(m_pTaskThreads[i]);
            FUN_008c7490(m_pTaskThreads[i]);
            delete (TaskThreadStandin*)m_pTaskThreads[i];
            m_pTaskThreads[i] = 0;
        }
    }

    for (iHandleIndex1 = 0; iHandleIndex1 <= 11; ++iHandleIndex1)
    {
        CloseHandle(threadHandles1[iHandleIndex1]);
    }

    for (j = 0; j <= 7; ++j)
    {
        CloseHandle(threadHandles2[j]);
    }
}

namespace fnv_008c7bd0 {



struct Zt5TES
{
    void FUN_00453550(float);
};

struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
};



struct FUN_008c79e0_shell
{
    void SignalThreadEvent(int);
};

struct FUN_008c7d80_shell
{
    void SetCurrent(int);
};

struct FUN_0087a6b0_shell
{
    void FUN_0087a6b0();
};

struct FUN_0087a6d0_shell
{
    void FUN_0087a6d0();
};

struct FUN_00991500_shell
{
    void FUN_00991500(bool);
};

struct FUN_0096cb50_shell
{
    void UpdateHighProcessActors();
};

struct FUN_009784c0_shell
{
    void FUN_009784c0();
};

struct FUN_00455640_shell
{
    void FUN_00455640();
};


// ProcessListsView: unit-local view (declares only what 0x008c7bd0 calls), not the shared ProcessLists; renamed so no local type keeps the shared name
struct ProcessListsView
{
    void RunActorUpdates();
};

struct GlobalObject_0096d020
{
    void FUN_0096cca0();
    void FUN_0096cda0();
    void FUN_0096bcd0(float, int);
    void UpdateDetection();
    void FUN_0096db30(float, int, int);
};

void* __stdcall FUN_00713d80(int);
void __fastcall FUN_0086fd70(void*);
float __cdecl FUN_00453850();
bool __cdecl FUN_005c42d0();
void __cdecl FUN_005ae270();
void __cdecl FUN_005a9d60();
void __cdecl FUN_008c80d0();
void __cdecl ProcessPlayerCellActors();
void __fastcall FUN_00991dc0(void*);

extern BSAudio* g_osGlobals;
extern int g_TES;
extern SettingT_GameSettingCollection_ g_011d73e4;
extern int DAT_011e0e80;
extern RecursiveSpinLock DAT_011f11a0;
extern void* BGSSaveLoadGlobalDataWorldspacePtr;

// @fnv 0x008c7bd0
void __cdecl FUN_008c7bd0()
{
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(0))->SignalThreadEvent(0);
    FUN_0086fd70(g_osGlobals);
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(0))->SignalThreadEvent(1);

    reinterpret_cast<FUN_0087a6b0_shell*>(TaskQueueInterface::GetInstance())->FUN_0087a6b0();

    reinterpret_cast<FUN_00991500_shell*>(BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00991500(FUN_005c42d0());

    DAT_011f11a0.Lock(0);
    reinterpret_cast<GlobalObject_0096d020*>(&DAT_011e0e80)->FUN_0096cca0();
    reinterpret_cast<GlobalObject_0096d020*>(&DAT_011e0e80)->FUN_0096cda0();
    DAT_011f11a0.Unlock();

    reinterpret_cast<FUN_00455640_shell*>(g_TES)->FUN_00455640();

    DAT_011f11a0.Lock(0);
    reinterpret_cast<FUN_009784c0_shell*>(&DAT_011e0e80)->FUN_009784c0();
    DAT_011f11a0.Unlock();

    FUN_00991dc0(BGSSaveLoadGlobalDataWorldspacePtr);

    DAT_011f11a0.Lock(0);
    reinterpret_cast<GlobalObject_0096d020*>(&DAT_011e0e80)->FUN_0096bcd0(0.0f, 0);
    ProcessPlayerCellActors();
    reinterpret_cast<GlobalObject_0096d020*>(&DAT_011e0e80)->UpdateDetection();
    reinterpret_cast<GlobalObject_0096d020*>(&DAT_011e0e80)->FUN_0096db30(0.0f, 0, 0);
    reinterpret_cast<SkyObject*>(&DAT_011e0e80)->Update(0.0f, 0);
    reinterpret_cast<ProcessListsView*>(&DAT_011e0e80)->RunActorUpdates();
    reinterpret_cast<FUN_0096cb50_shell*>(&DAT_011e0e80)->UpdateHighProcessActors();
    BGSDestructibleObjectForm::UpdateDestructionMap();
    DAT_011f11a0.Unlock();

    reinterpret_cast<Zt5TES*>(g_TES)->FUN_00453550(FUN_00453850());

    reinterpret_cast<FUN_008c7d80_shell*>(FUN_00713d80(1))->SetCurrent(6);
    FUN_008c80d0();

    if (*reinterpret_cast<unsigned char*>(g_011d73e4.Bool()))
        NavMeshObstacleManager::GetSingleton()->Update();

    reinterpret_cast<FUN_0087a6d0_shell*>(TaskQueueInterface::GetInstance())->FUN_0087a6d0();
    FUN_005ae270();
    FUN_005a9d60();

    reinterpret_cast<FUN_008c7d80_shell*>(FUN_00713d80(0))->SetCurrent(11);
    reinterpret_cast<FUN_008c7d80_shell*>(FUN_00713d80(1))->SetCurrent(7);
}
}  // namespace fnv_008c7bd0

class Sky;
namespace fnv_008c7f50 {

struct Zt5TES
{
    void FUN_00453550(float);
};

struct FUN_0096c330_shell
{
    void UpdateDetection();
    void FUN_0096db30(float, int, int);
};

struct FUN_0087a6b0_shell
{
    void FUN_0087a6b0();
};

struct FUN_0087a6d0_shell
{
    void FUN_0087a6d0();
};

class TaskQueueInterface
{
  public:
    static TaskQueueInterface* __cdecl GetInstance();
};

struct FUN_008c79e0_shell
{
    void SignalThreadEvent(int);
};

struct FUN_008c7a70_shell
{
    void WaitForEvent(int);
};



struct FUN_0096cb50_shell
{
    void UpdateHighProcessActors();
};

void* __stdcall FUN_00713d80(int);
float __cdecl FUN_00453850(void);
void __cdecl FUN_005ae270(void);
void __cdecl FUN_005a9d60(void);
extern int g_TES;
extern int DAT_011e0e80;

// @fnv 0x008c7f50
void FUN_008c7f50()
{
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(0);
    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80(0))->WaitForEvent(1);

    reinterpret_cast<FUN_0087a6b0_shell*>(TaskQueueInterface::GetInstance())->FUN_0087a6b0();
    reinterpret_cast<FUN_0096c330_shell*>(&DAT_011e0e80)->UpdateDetection();

    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(1);
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(2);
    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80(0))->WaitForEvent(2);

    reinterpret_cast<FUN_0096c330_shell*>(&DAT_011e0e80)->FUN_0096db30(0.0f, 0, 0);

    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(3);
    reinterpret_cast<SkyObject*>(&DAT_011e0e80)->Update(0.0f, 0);
    reinterpret_cast<FUN_0096cb50_shell*>(&DAT_011e0e80)->UpdateHighProcessActors();

    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(4);
    BGSDestructibleObjectForm::UpdateDestructionMap();

    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(5);
    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80(0))->WaitForEvent(4);

    reinterpret_cast<Zt5TES*>(g_TES)->FUN_00453550(FUN_00453850());

    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(6);
    reinterpret_cast<FUN_0087a6d0_shell*>(TaskQueueInterface::GetInstance())->FUN_0087a6d0();

    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80(0))->WaitForEvent(8);
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80(1))->SignalThreadEvent(7);

    FUN_005ae270();
    FUN_005a9d60();

    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80(0))->WaitForEvent(9);
    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80(0))->WaitForEvent(11);
}
}  // namespace fnv_008c7f50

namespace fnv_008c7da0 {
struct FUN_00455640_shell
{
    void FUN_00455640();
};

struct FUN_0087a6b0_shell
{
    void FUN_0087a6b0();
};

struct FUN_0087a6d0_shell
{
    void FUN_0087a6d0();
};

struct FUN_008c79e0_shell
{
    void SignalThreadEvent(int, int);
};

struct FUN_008c7a70_shell
{
    void WaitForEvent(int, int);
};

struct FUN_009784c0_shell
{
    void FUN_009784c0();
};

struct FUN_00991500_shell
{
    void FUN_00991500(bool);
};

struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
};

// ProcessListsView: unit-local view (declares only what 0x008c7da0 calls), not the shared ProcessLists; renamed so no local type keeps the shared name
struct ProcessListsView
{
    void FUN_0096cca0();
    void FUN_0096cda0();
    void FUN_0096bcd0(float, int);
    static void ProcessPlayerCellActors();
    void RunActorUpdates();
};




extern BSAudio* g_osGlobals;
extern FUN_00455640_shell* g_TES;
extern void* BGSSaveLoadGlobalDataWorldspacePtr;
extern int DAT_011e0e80;
extern SettingT_GameSettingCollection_ g_011d73e4;

void* __cdecl FUN_00713d80();
void __fastcall FUN_0086fd70(void*);
void __fastcall FUN_00991dc0(void*);
void __cdecl FUN_005a9d60();
void __cdecl FUN_005ae270();
bool __cdecl FUN_005c42d0();
void __cdecl FUN_008c80d0();

// @fnv 0x008c7da0
void __cdecl FUN_008c7da0()
{
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 0);
    FUN_0086fd70(g_osGlobals);
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 1);
    reinterpret_cast<FUN_0087a6b0_shell*>(TaskQueueInterface::GetInstance())->FUN_0087a6b0();
    reinterpret_cast<FUN_00991500_shell*>(BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00991500(FUN_005c42d0());
    reinterpret_cast<ProcessListsView*>(&DAT_011e0e80)->FUN_0096cca0();
    reinterpret_cast<ProcessListsView*>(&DAT_011e0e80)->FUN_0096cda0();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 2);
    g_TES->FUN_00455640();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 3);
    FUN_00991dc0(BGSSaveLoadGlobalDataWorldspacePtr);
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 4);
    reinterpret_cast<FUN_009784c0_shell*>(&DAT_011e0e80)->FUN_009784c0();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 5);
    reinterpret_cast<ProcessListsView*>(&DAT_011e0e80)->FUN_0096bcd0(0.0f, 0);
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 6);
    ProcessListsView::ProcessPlayerCellActors();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 10);
    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80())->WaitForEvent(1, 1);
    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80())->WaitForEvent(1, 3);
    reinterpret_cast<ProcessListsView*>(&DAT_011e0e80)->RunActorUpdates();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 7);
    reinterpret_cast<FUN_0087a6d0_shell*>(TaskQueueInterface::GetInstance())->FUN_0087a6d0();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 8);
    reinterpret_cast<FUN_008c7a70_shell*>(FUN_00713d80())->WaitForEvent(1, 7);
    FUN_008c80d0();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 9);
    if (*reinterpret_cast<unsigned char*>(g_011d73e4.Bool()))
        NavMeshObstacleManager::GetSingleton()->Update();
    FUN_005ae270();
    FUN_005a9d60();
    reinterpret_cast<FUN_008c79e0_shell*>(FUN_00713d80())->SignalThreadEvent(0, 11);
}
}  // namespace fnv_008c7da0
