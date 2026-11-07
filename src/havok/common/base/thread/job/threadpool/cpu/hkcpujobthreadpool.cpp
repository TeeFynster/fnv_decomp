#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include <windows.h>

// These lifetime methods were inline in this unit's original Havok implementation.

// Local until include/hkCpuJobThreadPoolCinfo.h supplies this 0x20-byte configuration.
struct hkCpuJobThreadPoolCinfo
{
    int m_numThreads;
    int m_stackSize;
    int m_timerBufferPerThreadAllocation;
    int m_threadPriority;
    const int* m_hardwareThreadIds;
    int m_numHardwareThreadIds;
    int m_hardwareThreadIdsCapacity;
    const char* m_name;
    hkCpuJobThreadPoolCinfo();
};

// @fnv 0x00d2d380
hkCpuJobThreadPoolCinfo::hkCpuJobThreadPoolCinfo()
{
    m_numThreads = 1;
    m_stackSize = 0x3d0900;
    m_threadPriority = 0;
    m_hardwareThreadIds = 0;
    m_numHardwareThreadIds = 0;
    m_hardwareThreadIdsCapacity = 0x80000000;
    m_name = "HavokWorkerThread";
    m_timerBufferPerThreadAllocation = 0;
}

class hkThread
{
  public:
    int m_iThreadHandle;
    int m_uiThreadId;
    int m_08;
    int m_0c;

    // Thread startup does not unwind the pool constructor.
    int hkThread_startThread(void*(__cdecl* pfnFunc)(void*), void* pvArg, const char* pcName, int iStackSize) throw();
};

// src/havok/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d2ced0
{
    void PerformVoidOperation();
};
// @fnv 0x00d2ced0
void FUN_00d2ced0::PerformVoidOperation()
{
    int i = 0;
    if (*(int*)((char*)this + 0x130) > i)
    {
        char* p = (char*)this + 0x34;
        do
        {
            *(int*)p = *(int*)(p - 4);
            *(unsigned char*)(p - 0xb) = 1;
            p += 0x30;
            ++i;
        } while (i < *(int*)((char*)this + 0x130));
    }
}

struct FUN_00d2d330_shell
{
    void InitializeWorkerThread();
    void hkCpuJobThreadPool_removeThread();
    void hkCpuJobThreadPool_setNumThreads(int desired);
};

// @fnv 0x00d2d330
// src: HAVOK_LIB 0x00d2d330
void FUN_00d2d330_shell::hkCpuJobThreadPool_setNumThreads(int desired)
{
    if (desired > 6)
        desired = 6;
    while (((int*)this)[0x130 / 4] < desired)
        InitializeWorkerThread();
    while (((int*)this)[0x130 / 4] > desired)
        hkCpuJobThreadPool_removeThread();
}

struct FUN_00d2ce30_shell
{
    unsigned char m_ucValue;
    bool hkCpuJobThreadPool_isProcessing();
};

// @fnv 0x00d2ce30
// src: HAVOK_LIB 0x00d2ce30
bool FUN_00d2ce30_shell::hkCpuJobThreadPool_isProcessing()
{
    return ((unsigned char*)this)[0x13c] != 0;
}

struct FUN_00d2ce90_class
{
    unsigned char padding_000[0x12c];
    void* m_uiFilterValue;
    int m_uiItemCount;
    unsigned char padding_134[0x08];
    bool m_running;

    void hkCpuJobThreadPool_waitForCompletion();
};

int __fastcall hkSemaphore_acquire(void*);

// @fnv 0x00d2ce90
// src: HAVOK_LIB 0x00d2ce90
void FUN_00d2ce90_class::hkCpuJobThreadPool_waitForCompletion()
{
    if (m_running)
    {
        for (int i = 0; i < m_uiItemCount; ++i)
        {
            hkSemaphore_acquire(&m_uiFilterValue);
        }

        m_running = false;
    }
}

struct FUN_00d2ce40_cls
{
    int hkCpuJobThreadPool_getNumThreads();
};

// @fnv 0x00d2ce40
// src: COMMUNITY 0x00d2ce40
int FUN_00d2ce40_cls::hkCpuJobThreadPool_getNumThreads()
{
    return *(int*)((char*)this + 0x130);
}

class FUN_00d2cf00
{
  public:
    ~FUN_00d2cf00() throw();
};

class hkMemoryAllocatorXd2d3b0
{
  public:
    virtual ~hkMemoryAllocatorXd2d3b0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXd2d3b0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXd2d3b0* m_pStreamAllocator;

    hkMemoryAllocatorXd2d3b0& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXd2d3b0& __cdecl hkMemoryRouter_getInstance() throw();

class hkObjd2d3b0 : public FUN_00d2cf00
{
  public:
    hkObjd2d3b0* DestroyIfFlagged(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkObjd2d3b0*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

// Runs the base destructor and, when bit 0 of uiFlags is set, frees the object via operator delete; returns this.
// @fnv 0x00d2d3b0
hkObjd2d3b0* hkObjd2d3b0::DestroyIfFlagged(unsigned int uiFlags) throw()
{
    this->FUN_00d2cf00::~FUN_00d2cf00();
    if (uiFlags & 1)
        hkObjd2d3b0::operator delete(this);
    return this;
}

class ElemD2CD
{
  public:
    void FUN_00d04390(int flag);
    int unk00[12];
};

class OwnerD2CD
{
  public:
    int unk00[11];
    ElemD2CD m_pElements[5];
    int unk11C[3];
    int m_128;
    int unk12C;
    int m_iCapacityFlags;
    int unk134[2];
    hkBool m_13C;

    void hkCpuJobThreadPool_processAllJobs(int value, int unused);
};

// Stores value in m_128, sets m_13C to true, and calls FUN_00d04390(1) on each element up to m_iCapacityFlags.
// @fnv 0x00d2cde0
// src: HAVOK_LIB 0x00d2cde0
void OwnerD2CD::hkCpuJobThreadPool_processAllJobs(int value, int unused)
{
    m_128 = value;
    m_13C = true;
    for (int i = m_iCapacityFlags - 1; i >= 0; i--)
        m_pElements[i].FUN_00d04390(1);
}

extern char DAT_010ce774;
extern char DAT_0102e388;
void hkReferencedObject_setLockMode(int);

struct EventObjD2C
{
    void ForwardCall_00d04370();
    void FUN_00d04390(int);
};

struct ThreadObjD2C
{
    void* m_threadPool;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_ucState;
    char pad19[3];
    EventObjD2C m_evt;
    int unk20;
    int unk24;
    int unk28;
    EventObjD2C m_pTail;
    void hkThread_stopThread_ForwardCall_00d87a70();
};

struct VBaseD2C
{
    void* vptr00;
    int unk04;
    int unk08;
    int unk0c;
};

struct ArrBaseD2C
{
    ThreadObjD2C m_threads[6];
};

struct ClsD2C : VBaseD2C, ArrBaseD2C
{
    int m_uiItemCount;
    void hkCpuJobThreadPool_waitForCompletion();
    void ProcessEntries_00d2cf00();
};

// @fnv 0x00d2cf00
// src: GUESS 0x00d2cf00 (confidence: low)
void ClsD2C::ProcessEntries_00d2cf00()
{
    *(void**)this = (void*)&DAT_010ce774;
    hkCpuJobThreadPool_waitForCompletion();
    for (int i = 0; i < m_uiItemCount; ++i)
    {
        ArrBaseD2C::m_threads[i].m_ucState = 1;
        ArrBaseD2C::m_threads[i].m_evt.FUN_00d04390(1);
    }
    for (int j = 0; j < m_uiItemCount; ++j)
    {
        hkSemaphore_acquire(&ArrBaseD2C::m_threads[5].m_pTail);
    }
    hkReferencedObject_setLockMode(0);
    ArrBaseD2C::m_threads[5].m_pTail.ForwardCall_00d04370();
    int k = 5;
    ArrBaseD2C* ab = static_cast<ArrBaseD2C*>(this);
    ThreadObjD2C(*arr)[6] = &ab->m_threads;
    ThreadObjD2C* th = &arr[0][6];
    do
    {
        --th;
        th->m_evt.ForwardCall_00d04370();
        th->hkThread_stopThread_ForwardCall_00d87a70();
    } while (--k >= 0);
    *(void**)this = (void*)&DAT_0102e388;
}

namespace fnv_00d2d110 {
extern "C" void __cdecl hkReferencedObject_setLockMode(int iLockMode);
void* __cdecl CpuJobThreadMain(void* pvArg);

class FUN_00d2cd80
{
  public:
    int m_00;
    int m_04;
    // Havok shared-data initialization does not throw.
    FUN_00d2cd80() throw();
};

class FUN_00d2cda0
{
  public:
    FUN_00d2cd80* m_sharedData;
    int m_04;
    hkThread m_iThreadHandle;
    int m_uiThreadId;
    int m_iOffset1C;
    bool m_ucState;
    bool m_bOffset21;
    int m_24;
    char* m_pOffset28;
    char* m_pOffset2C;

    // Havok worker-data initialization does not throw.
    FUN_00d2cda0() throw();
};

class FUN_00d2d110 : public hkReferencedObject
{
  public:
    FUN_00d2cda0 m_kThreadData[6];
    FUN_00d2cd80 m_kSharedData;
    int m_iHardwareInfoValue;
    int m_iStackSize;
    int m_iThirdValue;
    bool m_bFlag;
    const char* m_pName;
    int m_iTimerBufferPerThreadAllocation;

    FUN_00d2d110(const hkCpuJobThreadPoolCinfo& kCi);
};

// Initializes the thread pool by copying config, capping thread count, and spawning worker threads with hardware-affinity assignment.
// @fnv 0x00d2d110
FUN_00d2d110::FUN_00d2d110(const hkCpuJobThreadPoolCinfo& kCi)
{
    m_bFlag = false;
    m_pName = kCi.m_name;
    m_iTimerBufferPerThreadAllocation = kCi.m_timerBufferPerThreadAllocation;
    m_iStackSize = kCi.m_stackSize;
    m_iThirdValue = kCi.m_threadPriority;
    int iNumThreads = kCi.m_numThreads;
    if (iNumThreads > 6)
        iNumThreads = 5;
    m_iHardwareInfoValue = iNumThreads;

    SYSTEM_INFO kSysInfo;
    GetSystemInfo(&kSysInfo);
    int iNumCores = kSysInfo.dwNumberOfProcessors;

    for (int i = 0; i < iNumThreads; i++)
    {
        FUN_00d2cda0& kData = m_kThreadData[i];
        kData.m_sharedData = &m_kSharedData;
        int iThreadId = i + 1;
        kData.m_uiThreadId = iThreadId;
        kData.m_pOffset28 = 0;
        kData.m_pOffset2C = 0;
        kData.m_ucState = false;
        kData.m_bOffset21 = false;
        if (kCi.m_numHardwareThreadIds > 0)
            kData.m_iOffset1C = kCi.m_hardwareThreadIds[i];
        else
            kData.m_iOffset1C = iThreadId % iNumCores;
        kData.m_iThreadHandle.hkThread_startThread(CpuJobThreadMain, &kData, m_pName, m_iTimerBufferPerThreadAllocation);
    }
    hkReferencedObject_setLockMode(1);
}
}  // namespace fnv_00d2d110

#include <xmmintrin.h>
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long dwTlsIndex, void* lpTlsValue);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();
extern "C" __declspec(dllimport) unsigned long __stdcall SetThreadIdealProcessor(void* hThread,
                                                                                 unsigned long dwIdealProcessor);

struct hkThreadLocalD2
{
    void setData(void* p)
    {
        TlsSetValue(m_slot, p);
    }
    unsigned long m_slot;
};
extern hkThreadLocalD2 DAT_012687c8;

struct hkMonitorStreamD2
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* GetStreamStart() const
    {
        return m_kRayStart;
    }
    char* GetStreamEnd() const
    {
        return m_kRayEnd;
    }
};
struct hkMonitorTlsD2
{
    hkMonitorStreamD2* getData()
    {
        return (hkMonitorStreamD2*)TlsGetValue(m_slot);
    }
    unsigned long m_slot;
};
extern hkMonitorTlsD2 DAT_0126835c;
void __cdecl ResizeBuffer(hkMonitorStreamD2* pStream, int iSize);
void __cdecl hkMonitorStream_reset(hkMonitorStreamD2* pStream);

struct hkMemoryRouterD2
{
    hkMemoryRouterD2();
    void* m_aiEntries;
    void* m_pTemp;
    void* m_pStreamAllocator;
    void* m_pDebugAllocator;
    void* m_pSolver;
    void* m_pUserData;
    void* m_pRefObjectLocalStore;
    void* m_lifoStart;
    void* m_lifoEnd;
};

struct hkMemorySystemFlagsD2
{
    hkMemorySystemFlagsD2(int v) : m_kStorage(v)
    {}
    hkMemorySystemFlagsD2(const hkMemorySystemFlagsD2& o) : m_kStorage(o.m_kStorage)
    {}
    int m_kStorage;
};

class hkMemorySystemD2
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void InitializeThreadRouter(hkMemoryRouterD2& router, const char* name, hkMemorySystemFlagsD2 flags);
    virtual void ThreadQuit(hkMemoryRouterD2& router, hkMemorySystemFlagsD2 flags);
};
hkMemorySystemD2* __cdecl hkMemorySystem_getInstance();
void __cdecl hkBaseSystem_initThread(hkMemoryRouterD2* router);
void __cdecl hkBaseSystem_quitThread();

struct hkSemaphoreD2
{
    void FUN_00d04390(int count);
    void* m_pCompletionSemaphore;
};
int __fastcall hkSemaphore_acquire(void*);

struct hkJobQueueD2
{
    void hkJobQueue_processAllJobs();
};

// Workers point to the shared queue/semaphore block at pool offset 0x128, not to the pool base.
struct SharedJobQueueData
{
    hkJobQueueD2* m_kQueues;
    hkSemaphoreD2 m_kWorkerSemaphore;
    int m_iHardwareInfoValue;
    int m_bFlag;
    int m_iThreadPriority;
};

struct hkCpuThreadDataD2
{
    SharedJobQueueData* m_threadPool;
    void* m_iThreadHandle;
    int m_uiThreadId;
    int m_monitorStreamSize;
    int m_hardwareThreadId0;
    int m_hardwareThreadId1;
    void* m_threadNumber;
    unsigned long m_iOffset1C;
    bool m_ucState;
    bool m_bOffset21;
    hkSemaphoreD2 m_pCompletionSemaphore;
    char* m_pOffset28;
    char* m_pOffset2C;
};

// Initializes thread-local state and memory router, then loops processing job queues until the thread state flag is set.
// @fnv 0x00d2cfb0
void* __cdecl CpuJobThreadMain(void* apThreadData)
{
    hkCpuThreadDataD2& threadData = *static_cast<hkCpuThreadDataD2*>(apThreadData);
    SharedJobQueueData* threadPool = threadData.m_threadPool;

    DAT_012687c8.setData(threadData.m_threadNumber);
    _mm_setcsr(_mm_getcsr() | 0x8000);
    SetThreadIdealProcessor(GetCurrentThread(), threadData.m_iOffset1C);

    hkMemoryRouterD2 memoryRouter;
    hkMemorySystem_getInstance()->InitializeThreadRouter(memoryRouter, "hkCpuJobThreadPool", hkMemorySystemFlagsD2(3));
    hkBaseSystem_initThread(&memoryRouter);

    if (threadPool->m_iThreadPriority > 0)
    {
        hkMonitorStreamD2* pStream = DAT_0126835c.getData();
        ResizeBuffer(pStream, threadPool->m_iThreadPriority);
    }
    threadData.m_pOffset28 = DAT_0126835c.getData()->GetStreamStart();
    threadData.m_pOffset2C = DAT_0126835c.getData()->GetStreamEnd();

    hkSemaphore_acquire(&threadData.m_pCompletionSemaphore);
    while (!threadData.m_ucState)
    {
        if (threadData.m_bOffset21)
        {
            hkMonitorStream_reset(DAT_0126835c.getData());
            threadData.m_pOffset2C = DAT_0126835c.getData()->GetStreamEnd();
            threadData.m_bOffset21 = false;
        }
        threadPool->m_kQueues->hkJobQueue_processAllJobs();
        threadData.m_pOffset2C = DAT_0126835c.getData()->GetStreamEnd();
        threadPool->m_kWorkerSemaphore.FUN_00d04390(1);
        hkSemaphore_acquire(&threadData.m_pCompletionSemaphore);
    }

    hkBaseSystem_quitThread();
    hkMemorySystem_getInstance()->ThreadQuit(memoryRouter, hkMemorySystemFlagsD2(3));
    threadPool->m_kWorkerSemaphore.FUN_00d04390(1);
    return 0;
}

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

// 0x00d2d2c0 copies each worker's monitor begin/end at offsets 0x28/0x2c into this range.
struct MonitorStreamRange
{
    int m_kPointA;
    int m_kPointB;
};

typedef hkArrayBase<MonitorStreamRange> MonitorStreamRanges;

struct Record_d2d2c0
{
    int m_kPointA;
    int m_kPointB;
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
};

struct Owner_d2d2c0
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
    Record_d2d2c0 m_records[5];
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int m_uiItemCount;

    void hkCpuJobThreadPool_appendTimerData(MonitorStreamRanges* arr, void* alloc);
};

// @fnv 0x00d2d2c0
// src: HAVOK_LIB 0x00d2d2c0
void Owner_d2d2c0::hkCpuJobThreadPool_appendTimerData(MonitorStreamRanges* apPairArray, void* alloc)
{
    int index = 0;
    if (m_uiItemCount > 0)
    {
        int* source = &m_records[0].m_kPointB;
        do
        {
            if (apPairArray->m_iElementCount == (apPairArray->m_iCapacityState & 0x3FFFFFFF))
                ResizeAudioStream(alloc, apPairArray, 8);
            int remaining = 1;
            do
            {
                MonitorStreamRange& pair = apPairArray->m_data[apPairArray->m_iElementCount];
                ++apPairArray->m_iElementCount;
                pair.m_kPointA = source[-1];
                pair.m_kPointB = source[0];
            } while (--remaining);
            ++index;
            source += 12;
        } while (index < m_uiItemCount);
    }
}

namespace fnv_00d2d240 {
void* __cdecl CpuJobThreadMain(void* pArg);

struct hkWorkerThreadPoolBaseD2D
{
    int unk00;
    int unk04;
};

struct WorkerThreadDataD2D
{
    hkWorkerThreadPoolBaseD2D* m_threadPool;
    int unk04;
    hkThread m_iThreadHandle;
    int m_uiThreadId;
    int m_iOffset1C;
    bool m_ucState;
    bool m_clearTimerData;
    int unk24;
    void* m_pOffset28;
    void* m_pOffset2C;
};

class hkCpuJobThreadPool
{
  public:
    int unk000;
    int unk004;
    WorkerThreadDataD2D m_kThreadData[6];
    hkWorkerThreadPoolBaseD2D m_threadPoolBase;
    int m_iHardwareInfoValue;
    int unk134;
    int unk138;
    int unk13C;
    const char* m_pName;
    int m_iTimerBufferPerThreadAllocation;
    void InitializeWorkerThread();
};

// Configures a WorkerThreadDataD2D entry with thread pool, ID, and processor affinity, then starts the worker thread via m_iThreadHandle.
// @fnv 0x00d2d240
void hkCpuJobThreadPool::InitializeWorkerThread()
{
    WorkerThreadDataD2D& data = m_kThreadData[m_iHardwareInfoValue];

    data.m_threadPool = &m_threadPoolBase;
    data.m_uiThreadId = m_iHardwareInfoValue + 1;
    data.m_pOffset28 = 0;
    data.m_pOffset2C = 0;
    data.m_ucState = false;
    data.m_clearTimerData = false;

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    int threadId = data.m_uiThreadId;
    int processorCount = *(volatile int*)&sysInfo.dwNumberOfProcessors;
    data.m_iOffset1C = threadId % processorCount;

    data.m_iThreadHandle.hkThread_startThread(CpuJobThreadMain, &data, m_pName, m_iTimerBufferPerThreadAllocation);

    m_iHardwareInfoValue++;
}
}  // namespace fnv_00d2d240

struct WorkerThreadHandleD2
{
    void* m_handle;
    unsigned __int64 m_uiThreadId;

    void hkThread_stopThread();
};

struct WorkerThreadRecordD2
{
    SharedJobQueueData* m_sharedData;
    WorkerThreadHandleD2 m_iThreadHandle;
    int m_uiThreadId;
    int m_iOffset1C;
    bool m_ucState;
    bool m_bOffset21;
    hkSemaphoreD2 m_pCompletionSemaphore;
    char* m_monitorBegin;
    char* m_monitorEnd;
};

struct WorkerThreadPoolViewD2
{
    void* m_ppVirtualMethodTable;
    unsigned short m_memorySizeAndFlags;
    unsigned short m_sReferenceCount;
    WorkerThreadRecordD2 m_workers[6];
    SharedJobQueueData m_sharedData;

    void hkCpuJobThreadPool_removeThread();
};

// Decrements the shared counter, sets the selected worker state to true, calls its semaphore method, calls FUN_00d04380, and closes its thread handle.
// @fnv 0x00d2ce50
// src: HAVOK_LIB 0x00d2ce50
void WorkerThreadPoolViewD2::hkCpuJobThreadPool_removeThread()
{
    WorkerThreadPoolViewD2* pool = this;
    --pool->m_sharedData.m_iHardwareInfoValue;
    WorkerThreadRecordD2& worker = pool->m_workers[pool->m_sharedData.m_iHardwareInfoValue];
    worker.m_ucState = true;
    worker.m_pCompletionSemaphore.FUN_00d04390(1);
    hkSemaphore_acquire(&pool->m_sharedData.m_kWorkerSemaphore);
    worker.m_iThreadHandle.hkThread_stopThread();
}
