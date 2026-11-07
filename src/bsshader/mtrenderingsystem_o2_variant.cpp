// src/bsshader/mtrenderingsystem_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/mtrenderingsystem.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "mtrenderingsystem_decls.h"
#include "../../include/BSLinearTaskThread.h"
#include "../../include/BSThread.h"
#include "../../include/NiRefObject.h"
#include "../../include/MemoryManager.h"
#include "../../include/BSCullingProcess.h"
#pragma optimize("gty", on)
#pragma optimize("", off)
#pragma optimize("gty", on)
#pragma optimize("", off)

namespace fnv_00ba3690 {
#pragma optimize("gty", on)
extern "C" void _ReadWriteBarrier(void);

struct HandlerRegistration
{
    void* queuedHead;
    void* queuedTail;
    unsigned int queuedCount;
    HandlerRegistration();
    ~HandlerRegistration();
};

struct ThreadNode
{
    void* firstTask;
    void* lastTask;
    unsigned int taskCount;
    unsigned int nextTask;
    void* batch;
    void* renderer;
    unsigned int stage;
    unsigned int flags;
    ThreadNode();
    ~ThreadNode();
};

struct RenderingState
{
    int threadStages[3];
    int threadCounts[3];
    HandlerRegistration taskQueues[3];
    ThreadNode taskThreads[24];

    RenderingState();
};

// @fnv 0x00ba3690
RenderingState::RenderingState()
{
    int i = 0;
    do
    {
        threadStages[i] = 0;
        threadCounts[i] = 0;
        _ReadWriteBarrier();
    } while (++i < 3);
}
}  // namespace fnv_00ba3690

namespace RenderStageWait {
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct WaitHandleCounter
{
    volatile long count;
    void* handle;
    unsigned int maximum;

    __forceinline void Acquire()
    {
        WaitForSingleObject(handle, ~0UL);
        InterlockedDecrement(&count);
    }
};

struct ThreadStages : ::TaskThreadManager
{
    void* renderWorker;
    void* visibilityWorker;
    void* linearWorker;
    volatile int completed[3];
    WaitHandleCounter signals[3];
};

// @fnv 0x00ba3130
// src: COMMUNITY 0x00ba3130
extern "C" void __fastcall MTRenderingSystem_WaitOnThreadStage(ThreadStages* system, void*, int threadIndex, int stage)
{
    if (!::DAT_011f94b4)
        return;

    while (system->completed[threadIndex] < stage)
    {
        system->signals[threadIndex].Acquire();
        ++system->completed[threadIndex];
    }
}
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

extern MemoryManager _g_memoryManager;

// Preserve the original inlined reference operations with the shared layout.
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void BSCullingProcess::SetAccumulator(NiRefObject* accumulator)
{
    if (accumulator)
    {
        m_acRendererDataA.m_pObject = reinterpret_cast<NiAccumulator*>(accumulator);
        accumulator->IncRefCount();
    }
}

inline void BSCullingProcess::SetCullMode(unsigned int mode)
{
    unk90 = mode;
}

inline void BSCullingProcess::SetCompoundFrustum(TaskArg1* frustum)
{
    unkC0 = reinterpret_cast<int>(frustum);
}

// The shared base does not declare its original visible-set constructor.
// Keep that native initialization and scoped cleanup without duplicating its layout.
class CullingBaseInitialization
{
  public:
    void Initialize(NiVisibleArray*);
};
extern "C" const void* DAT_0101e2ec;

class CullingProcessScope
{
    unsigned int storage[sizeof(BSCullingProcess) / sizeof(unsigned int)];

  public:
    __forceinline CullingProcessScope()
    {
        BSCullingProcess& culling = Get();
        reinterpret_cast<CullingBaseInitialization*>(&culling)->Initialize(0);
        *reinterpret_cast<const void**>(&culling) = &DAT_0101e2ec;
        culling.unk90 = 0;
        culling.unkBc = 0;
        culling.unkC0 = 0;
        culling.m_acRendererDataA.m_pObject = 0;
    }

    __forceinline ~CullingProcessScope()
    {
        Get().FUN_004a0f60();
    }

    __forceinline BSCullingProcess& Get()
    {
        return *reinterpret_cast<BSCullingProcess*>(storage);
    }
};

namespace AccumTaskDetail {

// Unit-local view of NiPointer for the code in namespace AccumTaskDetail: built on the shared NiPointer, that code does not compile or does not match.
template <class T> class NiPointer_AccumTaskDetail
{
  public:
    T* m_pObject;

    __forceinline NiPointer_AccumTaskDetail& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
            {
                m_pObject->DecRefCount();
            }
            m_pObject = pObject;
            if (m_pObject)
            {
                m_pObject->IncRefCount();
            }
        }
        return *this;
    }
};

class Class0xa4
{
  public:
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

    Class0xa4();
    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }
    void operator delete(void* p)
    {
        _g_memoryManager.Free(p);
    }
};

class TaskArg1
{
  public:
    void FUN_00c477f0(Class0xa4* obj);
};

void __cdecl BSShaderUtil_AccumulateScene(void* arg0, void* arg2, BSCullingProcess* pCulling);
void __cdecl BSShaderUtil_AccumulateSceneList(void* arg0, void* arg, BSCullingProcess* pCulling);

struct TaskItem
{
    NiPointer_AccumTaskDetail<NiRefObject> sp00;
    Class0xa4* p04;
    NiPointer_AccumTaskDetail<NiRefObject> sp08;
    void* unk0c;
    void* unk10;
    NiPointer_AccumTaskDetail<NiRefObject> sp14;
    unsigned int cullMode;
    void* unk1c;
};

class AccumTaskReceiver : public ::TaskThreadManager
{
  public:
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
    TaskItem tasks[24];

    __forceinline TaskItem& GetTask(unsigned int index)
    {
        return tasks[index];
    }
};

// @fnv 0x00ba3390
// src: COMMUNITY 0x00ba3390
void __fastcall MTRenderingSystem_AddAccumTask(AccumTaskReceiver* self, void*, NiRefObject* a1, TaskArg1* a2, NiRefObject* a3, void* a4,
                             void* a5, NiRefObject* a6, unsigned int a7, unsigned int a8, void* a9)
{
    if (::DAT_011f94b4)
    {
        self->GetTask(a8).sp00 = a1;
        self->GetTask(a8).p04 = 0;
        self->GetTask(a8).sp08 = a3;
        self->GetTask(a8).unk0c = a4;
        self->GetTask(a8).unk10 = a5;
        self->GetTask(a8).sp14 = a6;
        self->GetTask(a8).cullMode = a7;
        self->GetTask(a8).unk1c = a9;

        if (a2)
        {
            Class0xa4* obj = new Class0xa4();
            self->GetTask(a8).p04 = obj;
            a2->FUN_00c477f0(obj);
        }
    }
    else
    {
        CullingProcessScope cullingScope;
        BSCullingProcess& culling = cullingScope.Get();
        culling.SetAccumulator(a6);
        culling.SetCullMode(a7);
        culling.SetCompoundFrustum(reinterpret_cast<::TaskArg1*>(a2));
        if (a3)
        {
            BSShaderUtil_AccumulateScene(a1, a3, &culling);
        }
        if (a4)
        {
            BSShaderUtil_AccumulateSceneList(a1, a4, &culling);
        }
        if (a5)
        {
            BSShaderUtil_AccumulateSceneList(a1, a5, &culling);
        }
    }
}

}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace RenderShutdownDetail {
typedef int(__stdcall* SemaphoreRelease)(void*, long, long*);
inline void Signal(ThreadSemaphore& signal, SemaphoreRelease release)
{
    release(signal.handle, 1, 0);
    InterlockedIncrement(&signal.count);
}
inline void Wait(ThreadSemaphore& signal)
{
    WaitForSingleObject(signal.handle, 0xffffffffUL);
    InterlockedDecrement(&signal.count);
}
struct RenderTaskManager : ::TaskThreadManager
{
    BSLinearTaskThread* tasks[2];
};
// @fnv 0x00ba2d80
// src: COMMUNITY 0x00ba2d80
void __fastcall MTRenderingSystem_DestroyThreads(RenderTaskManager* manager)
{
    if (!::DAT_011f94b4)
        return;
    SemaphoreRelease release = &ReleaseSemaphore;
    for (unsigned int index = 0; index < 2; ++index)
    {
        BSLinearTaskThread* task = manager->tasks[index];
        if (task)
        {
            task->stopping = true;
            Signal(task->request, release);
            task = manager->tasks[index];
            Wait(task->completion);
            delete manager->tasks[index];
            manager->tasks[index] = 0;
        }
    }
}

}

int sprintf_s(char*, size_t, const char*, ...);

extern MemoryManager g_memoryManager;
extern void* DAT_010b7f50;
struct RenderTaskThread : BSLinearTaskThread
{
    void(__cdecl* m_pTaskFunction)();
    RenderTaskThread(void(__cdecl* f)())
    {
        *(void**)this = &DAT_010b7f50;
        m_pTaskFunction = f;
    }
    void* operator new(size_t s)
    {
        return g_memoryManager.Allocate(s);
    }
    void operator delete(void*);
};
struct ThreadOwner
{
    RenderTaskThread* m_threads[2];
    void MTRenderingSystem_AddThread(int index, unsigned int affinity, void(__cdecl* task)(), const char* name,
                      unsigned int stackSize);
};
// @fnv 0x00ba2e00
// src: COMMUNITY 0x00ba2e00
void ThreadOwner::MTRenderingSystem_AddThread(int index, unsigned int affinity, void(__cdecl* task)(), const char* name,
                               unsigned int stackSize)
{
    if (index < 3 && index < 2 && !m_threads[index])
    {
        m_threads[index] = new RenderTaskThread(task);
        m_threads[index]->Initialize(stackSize, name, false);
        m_threads[index]->FUN_00aa6550(affinity);
        m_threads[index]->SetThreadPriority(0);
        if (!name)
        {
            char buf[0x104];
            sprintf_s(buf, 0x104, "Rendering Task Thread DEF %i", index);
            m_threads[index]->SetName(buf);
        }
    }
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount,
                                                                long* lpPreviousCount);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
class ThreadCoordinator_ba2f30
{
  public:
    BSLinearTaskThread* workers[2];
    unsigned int unk08;
    volatile unsigned int counters[2];
    void MTRenderingSystem_StartThreads();
};
// @fnv 0x00ba2f30
// src: COMMUNITY 0x00ba2f30
void ThreadCoordinator_ba2f30::MTRenderingSystem_StartThreads()
{
    if (!DAT_011f94b4)
        return;
    volatile unsigned int* current = counters;
    unsigned int remaining = 2;
    do
    {
        *current++ = 0;
    } while (--remaining);
    for (unsigned int index = 0; index < 2; ++index)
    {
        BSLinearTaskThread* worker = workers[index];
        if (worker != 0)
        {
            ThreadSemaphore* synchronization = &worker->request;
            ReleaseSemaphore(synchronization->handle, 1, 0);
            InterlockedIncrement(&synchronization->count);
        }
    }
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern bool DAT_011f94b4;

class FUN_00ba2fa0_C
{
  public:
    BSLinearTaskThread* m_apThreads[2];

    void MTRenderingSystem_WaitForThreads();
};

// @fnv 0x00ba2fa0
// src: COMMUNITY 0x00ba2fa0
void FUN_00ba2fa0_C::MTRenderingSystem_WaitForThreads()
{
    if (DAT_011f94b4)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            BSLinearTaskThread* pThread = m_apThreads[i];
            if (pThread)
            {
                RenderShutdownDetail::Wait(pThread->completion);
            }
        }
    }
}

namespace fnv_00ba2ff0 {
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern MemoryManager g_memoryManager;
namespace fnv_ba2ff0_cleanup {
// @fnv 0x00ba2ff0
void* __fastcall FUN_00ba2ff0(BSLinearTaskThread* self, void*, unsigned int flags)
{
    CloseHandle(self->completion.handle);
    CloseHandle(self->request.handle);
    self->BSThread::~BSThread();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}
}  // namespace fnv_00ba2ff0

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

struct FUN_00ba3030
{
    NiPointer<NiRefObject> m_p1;
    int m_iValueAfterStandIn;
    NiPointer<NiRefObject> m_p2;
    int m_pAuxiliaryObject[2];
    NiPointer<NiRefObject> m_p3;
    int m_pad3[2];

    ~FUN_00ba3030();
};

// @fnv 0x00ba3030
FUN_00ba3030::~FUN_00ba3030()
{}

struct FUN_00ba30e0
{
    int state00;
    int unk04;
    int state08;
    int unk0c;
    int unk10;
    int state14;

    FUN_00ba30e0();
};

// @fnv 0x00ba30e0
FUN_00ba30e0::FUN_00ba30e0()
{
    state00 = 0;
    state08 = 0;
    state14 = 0;
}

__declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern int(__stdcall* DAT_00fdf1c0)(void*);

namespace ThreadStageSignalDetail {
struct Semaphore
{
    volatile int count;
    void* handle;
    int maximum;
};

class RenderingStageController : public TaskThreadManager
{
  public:
    void* threads[3];
    volatile int stages[3];
    Semaphore semaphores[3];

    void MTRenderingSystem_SetThreadStage(int threadIndex, int stage);
};

// @fnv 0x00ba30f0
// src: COMMUNITY 0x00ba30f0
void RenderingStageController::MTRenderingSystem_SetThreadStage(int threadIndex, int stage)
{
    if (DAT_011f94b4 && threadIndex < 2)
    {
        Semaphore& signal = semaphores[threadIndex];
        ReleaseSemaphore(signal.handle, 1, 0);
        DAT_00fdf1c0(const_cast<int*>(&signal.count));
    }
}
}

namespace fnv_00ba3190 {
extern "C" unsigned long __readfsdword(unsigned long offset);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* semaphore, long releaseCount,
                                                                long* previousCount);

struct SubObjMt
{
    void FUN_00c47770();
};

extern MemoryManager g_memoryManager;

struct MTRenderingSystem_Helper
{
    void MTRenderingSystem_WaitOnThreadStage(int a, int b);
};

void BSShaderUtil_AccumulateScene(NiRefObject* a, NiRefObject* b, BSCullingProcess* c);
void BSShaderUtil_AccumulateSceneList(NiRefObject* a, void* b, BSCullingProcess* c);
static inline void AddB(NiRefObject* a, NiRefObject* b, BSCullingProcess* c)
{
    BSShaderUtil_AccumulateScene(a, b, c);
}
static inline void AddC(NiRefObject* a, void* b, BSCullingProcess* c)
{
    BSShaderUtil_AccumulateSceneList(a, b, c);
}

struct TaskRecordMt
{
    NiRefObject* unk00;
    SubObjMt* unk04;
    NiRefObject* unk08;
    void* unk0C;
    void* unk10;
    NiRefObject* unk14;
    int unk18;
    int unk1C;
};
extern TaskRecordMt DAT_012000e4[23];

extern unsigned int DAT_0126fd98;
extern volatile long DAT_012000ac;
extern void* DAT_012000b0;

static inline void Release(NiRefObject*& rp)
{
    NiRefObject* p = rp;
    if (p)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)) == 0)
            p->DeleteThis();
        rp = 0;
    }
}

// @fnv 0x00ba3190
// src: COMMUNITY 0x00ba3190
void MTRenderingSystem_TaskThreadCallback()
{
    for (int i = 1; i < 24; i++)
    {
        TaskRecordMt* rec = &DAT_012000e4[i - 1];
        ((MTRenderingSystem_Helper*)&DAT_01200088)->MTRenderingSystem_WaitOnThreadStage(0, i);
        if (rec->unk14)
        {
            *(int*)(((char**)__readfsdword(0x2c))[DAT_0126fd98] + 0x2bc) = rec->unk1C;
            CullingProcessScope cullScope;
            BSCullingProcess& cull = cullScope.Get();
            NiRefObject* p = rec->unk14;
            if (p)
            {
                cull.m_acRendererDataA.m_pObject = reinterpret_cast<NiAccumulator*>(p);
                InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
            }
            cull.unk90 = rec->unk18;
            cull.unkC0 = reinterpret_cast<int>(rec->unk04);
            if (rec->unk08)
                AddB(rec->unk00, rec->unk08, &cull);
            if (rec->unk0C)
                AddC(rec->unk00, rec->unk0C, &cull);
            if (rec->unk10)
                AddC(rec->unk00, rec->unk10, &cull);
            rec->unk1C = 0;
            rec->unk0C = 0;
            rec->unk10 = 0;
            Release(rec->unk14);
            Release(rec->unk00);
            Release(rec->unk08);
            SubObjMt* s = rec->unk04;
            if (s)
            {
                s->FUN_00c47770();
                g_memoryManager.Deallocate(s);
                rec->unk04 = 0;
            }
        }
        if (DAT_011f94b4)
        {
            ReleaseSemaphore(DAT_012000b0, 1, 0);
            InterlockedIncrement(&DAT_012000ac);
        }
    }
}
}  // namespace fnv_00ba3190

void __cdecl ForwardCall_00ba2d70();
void __cdecl FUN_00ba3030();
void __stdcall FUN_00ec5fce(void*, unsigned int, int, void(__cdecl*)());

struct LinearTaskRecord
{
    unsigned int taskId;
    unsigned int flags;
    unsigned int state;
};

struct RenderTaskRecord
{
    unsigned int type;
    unsigned int index;
    unsigned int input;
    unsigned int output;
    unsigned int width;
    unsigned int height;
    unsigned int format;
    unsigned int options;
};

struct LinearTaskGroup
{
    LinearTaskRecord tasks[3];
    __forceinline ~LinearTaskGroup()
    {
        FUN_00ec5fce(tasks, sizeof(LinearTaskRecord), 3, ForwardCall_00ba2d70);
    }
};

struct RenderTaskGroup
{
    RenderTaskRecord tasks[24];
    __forceinline ~RenderTaskGroup()
    {
        FUN_00ec5fce(tasks, sizeof(RenderTaskRecord), 24, FUN_00ba3030);
    }
};

struct FUN_00ba3620
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    LinearTaskGroup linearTasks;
    RenderTaskGroup renderTasks;
    ~FUN_00ba3620();
};

// @fnv 0x00ba3620
FUN_00ba3620::~FUN_00ba3620()
{}
