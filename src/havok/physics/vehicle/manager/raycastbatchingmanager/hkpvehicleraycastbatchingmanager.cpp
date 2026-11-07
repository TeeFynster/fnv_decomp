
// src/havok/physics/vehicle/manager/raycastbatchingmanager/hkpvehicleraycastbatchingmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/manager/raycastbatchingmanager/hkpvehicleraycastbatchingmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleRayCastBatchingManager.h"
#include "../../../../../../include/hkMonitorStream.h"

struct hkObjE42A {
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int unk10;
    unsigned short m_14;

    int GetAlignedSize(int n) const;
};

inline int ALIGN16_E42A(int x) { return (x + 15) & ~15; }

// Computes the sum of 16-byte-aligned sizes derived from m_14, n, and m_0c.
// @fnv 0x00e42ac0
int hkObjE42A::GetAlignedSize(int n) const
{
    int k = m_14;
    return ALIGN16_E42A(k * 0x60) + ALIGN16_E42A(k * 0x50) + ALIGN16_E42A(n * 0x10) + ALIGN16_E42A(m_0c);
}

struct Buffers {char* first;char* second;char* third;char* fourth;};
struct Obj{int a,b,c,byte_size,d;unsigned short count;void ComputeBufferLayout(char* base,int unused,Buffers* out) const;};
inline int align16(int n){return (n+15)&~15;}
// Computes aligned offsets for four buffers from count and byte_size and stores the resulting pointers in out.
// @fnv 0x00e42b00
void Obj::ComputeBufferLayout(char* base,int unused,Buffers* out) const {
 int n=count;int iByteSize=byte_size;
 char* p=base+align16(n*80);out->second=p;p+=align16(n*96);char* pThird=p;p+=align16(iByteSize);out->first=base;out->fourth=p;out->third=pThird;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern unsigned long DAT_0126835c;
struct TimerStream { void* start; hkMonitorStream::TimerCommand* current; void* unused; hkMonitorStream::TimerCommand* end; };
struct WheelResult { hkVector4 position, normal, suspension, contact, friction, extra; };
struct WheelCommand { hkVector4 position, direction, from, to; void* results; int count; int enabled; int state; };
struct Vehicle;
struct WheelCaster {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void v20(); virtual void v24(); virtual void v28();
 virtual void finish(Vehicle*, signed char, WheelResult*);
 virtual void v30(); virtual void v34(); virtual void v38();
 virtual void cast(Vehicle*, signed char, void*, WheelResult*);
 virtual void skip(Vehicle*, signed char, WheelResult*);
};
struct VehicleData { hkVector4 first, second; unsigned char wheels; };
struct Vehicle {
 unsigned field00, field04, field08, field0c, field10, field14, field18;
 VehicleData* data;
 unsigned field20, field24, field28, field2c, field30, field34, field38;
 WheelCaster* caster;
 void hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(void*, WheelResult*);
};
struct Allocator {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void freeBlock(void*, int);
};
struct ThreadMemory { char* stack; unsigned field04, field08, field0c; Allocator* allocator; Allocator& heap() { return *allocator; } };
ThreadMemory* hkMemoryRouter_getInstance();
void hkArrayUtil__reserve(Allocator*, hkArrayBase<WheelResult>*, int, int);
struct LocalWheelResults : hkArrayBase<WheelResult> {
 LocalWheelResults() : hkArrayBase<WheelResult>(FinishingFlag(0)) {}
 WheelResult* original;
 void initialize() {
  m_data = 0; m_iElementCount = 0; m_iCapacityState = 0x80000000;
  ThreadMemory* memory = hkMemoryRouter_getInstance();
  WheelResult* block = (WheelResult*)memory->stack;
  memory->stack = (char*)(block + 16);
  m_data = block; m_iCapacityState = 0x80000010; original = block;
 }
 void resize(int size) {
  Allocator& allocator = hkMemoryRouter_getInstance()->heap();
  _ReadWriteBarrier();
  int capacity = m_iCapacityState & 0x3fffffff;
  if (capacity < size) {
   int grown = capacity * 2;
   if (size >= grown) grown = size;
   hkArrayUtil__reserve(&allocator, this, grown, sizeof(WheelResult));
  }
  m_iElementCount = size;
 }
 void release() {
  WheelResult* saved = original;
  if (saved == m_data) m_iElementCount = 0;
  hkMemoryRouter_getInstance()->stack = (char*)saved;
  Allocator& allocator = hkMemoryRouter_getInstance()->heap();
  m_iElementCount = 0;
  if ((m_iCapacityState & 0x80000000) == 0)
   allocator.freeBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(WheelResult));
 }
};
struct BatchOutputs { WheelCommand* commands; void* temporary; unsigned char* flags; void* end; };
struct RayBatchManager {
 unsigned field00, field04; Vehicle** vehicles; int vehicleCount; unsigned field10; hkUint16 wheels, field16;
 void ComputeBufferLayout(WheelCommand*, void*, BatchOutputs*);
 void hkpVehicleRayCastBatchingManager_stepVehiclesUsingCastResults(void* input, void* world, WheelCommand* commands);
};
// Records timer entries TtDoVehicles and Et around a loop that casts or skips each wheel per vehicle via its caster and passes the results to FUN_00e39030.
// @fnv 0x00e42da0
// src: HAVOK_LIB 0x00e42da0
void RayBatchManager::hkpVehicleRayCastBatchingManager_stepVehiclesUsingCastResults(void* input, void* world, WheelCommand* commands)
{
 TimerStream* timer = (TimerStream*)TlsGetValue(DAT_0126835c);
 hkMonitorStream::TimerCommand* record = timer->current;
 if (record < timer->end) {
  record->m_commandAndMonitor = "TtDoVehicles";
  _ReadWriteBarrier();
  volatile unsigned tick = (unsigned)__rdtsc();
  record->m_time0 = tick;
  timer->current = record + 1;
 }
 int count = vehicleCount;
 LocalWheelResults results;
 BatchOutputs active;
 ComputeBufferLayout(commands, world, &active);
 WheelCommand* cursor = active.commands;
 results.initialize();
 for (int i = 0; i < count; ++i) {
  Vehicle* vehicle = vehicles[i];
  int wheelCount = vehicle->data->wheels;
  results.resize(wheelCount);
  int wheels = vehicle->data->wheels;
  WheelCaster* caster = vehicle->caster;
  for (signed char wheel = 0; wheel < wheels; ++wheel) {
   int enabled = active.flags[i];
   if (enabled && cursor->enabled)
    caster->cast(vehicle, wheel, cursor->results, &results.m_data[wheel]);
   else
    caster->skip(vehicle, wheel, &results.m_data[wheel]);
   caster->finish(vehicle, wheel, &results.m_data[wheel]);
   if (enabled) ++cursor;
  }
  vehicles[i]->hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(input, results.m_data);
 }
 timer = (TimerStream*)TlsGetValue(DAT_0126835c);
 record = timer->current;
 if (record < timer->end) {
  record->m_commandAndMonitor = "Et";
  _ReadWriteBarrier();
  volatile unsigned tick = (unsigned)__rdtsc();
  record->m_time0 = tick;
  timer->current = record + 1;
 }
 results.release();
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

inline void hkMonitorStream::TimerCommand::setTime()
{
    _ReadWriteBarrier();
    hkUint32 ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}

struct VRMonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static unsigned long ms_uiThreadLocalStorageIndex;

    static VRMonitorStream& GetMonitorStream() { return *(VRMonitorStream*)TlsGetValue(ms_uiThreadLocalStorageIndex); }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }

    void timerCommand(const char* name)
    {
        if (memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)m_kRayEnd;
            h->m_commandAndMonitor = name;
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct VRCommand
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
};

struct VROutput
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
};

struct VRJobHeader
{
    int m_iJobId;
    int unk04,unk08,unk0c;
};

struct VRBatch
{
    VRCommand* m_pCommandArray;
    VROutput* m_pOutput;
    hkUint8* m_uiEdgeIndex;
    VRJobHeader* m_pJobHeader;
};

struct VRWheelCollide
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual int BuildCastCommands(const struct VRVehicle* vehicle, const void* filter, int filterSize, VRCommand* commandStorage, VROutput* outputStorage);
};

struct VRVehicle
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
    VRWheelCollide* m_pWheelCollide;
};

struct VRWorld
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
    const void* m_pCollisionInput;
    const void* m_pCollisionFilter;
};

struct __declspec(align(16)) VRJob
{
    hkUint8 m_ucSubType;
    hkUint8 m_eJobType;
    hkUint8 m_eSpuType;
    hkUint8 m_pad03;
    hkUint16 m_iElementCount;
    hkInt16 m_iAffinity;
    int unk08,unk0c;

    VRJob(hkUint8 type, hkUint8 subType, hkUint16 size, hkUint8 spuType)
        : m_ucSubType(subType), m_eJobType(type), m_eSpuType(spuType), m_iElementCount(size), m_iAffinity(-1) {}
};

struct VRCollisionQueryJob : VRJob
{
    void* m_pCompletionSemaphore;
    VRJobHeader* m_pCollisionQueryJobHeader;
    hkUint32* m_pJobDoneHeader;
    const void* m_pCollisionInput;

    VRCollisionQueryJob(hkUint8 subType, hkUint16 size)
        : VRJob(3, subType, size, 0)
    {
        m_pCompletionSemaphore = 0;
        m_pJobDoneHeader = 0;
    }
};

struct VRRayCastJob : VRCollisionQueryJob
{
    int m_iCommandCapacity;
    const VRCommand* m_pCommands;
    int m_iCommandCount;
    int m_pad2c;

    VRRayCastJob(const void* input, VRJobHeader* jobHeader, const VRCommand* commandArray, int numCommands, void* semaphore)
        : VRCollisionQueryJob(0, sizeof(VRRayCastJob))
    {
        m_eSpuType = 1;
        m_pCollisionInput = input;
        m_pCompletionSemaphore = semaphore;
        m_pCollisionQueryJobHeader = jobHeader;
        m_iCommandCapacity = 90;
        m_pCommands = commandArray;
        m_iCommandCount = numCommands;
        m_pCollisionQueryJobHeader->m_iJobId = ((numCommands - 1) / 90) + 1;
    }

    void ExecuteRayCastJob();
};

struct VRJobQueue
{
    void EnqueueJob(VRJob& job, int priority);
};

struct VehicleRayCastBatchingManager
{
    int unk00;
    int unk04;
    VRVehicle** m_ppVehicles;
    int m_numVehicles;
    int unk10;
    hkUint16 m_uiTotalWheelCount;
    hkUint16 unk16;

    VRVehicle** registeredVehicles() const { return m_ppVehicles; }

    void getBufferBreakdown(void* buffer, int numJobs, VRBatch& batchOut);
    int hkpVehicleRayCastBatchingManager_buildAndAddCastJobs(const VRWorld* world, int filterSize, int numJobs, VRJobQueue* jobQueue, void* semaphore, void* buffer);
};

// @fnv 0x00e42b50
// src: HAVOK_LIB 0x00e42b50
int VehicleRayCastBatchingManager::hkpVehicleRayCastBatchingManager_buildAndAddCastJobs(const VRWorld* world, int filterSize, int numJobs, VRJobQueue* jobQueue, void* semaphore, void* buffer)
{
    VROutput* outputStorage;
    VRMonitorStream::GetMonitorStream().timerCommand("TtBuildAndAddRaycastJobs");

    const void* filter = world->m_pCollisionFilter;
    const int numVehicles = m_numVehicles;

    VRBatch batch;
    getBufferBreakdown(buffer, numJobs, batch);

    int numCommands = 0;
    VRMonitorStream::GetMonitorStream().timerCommand("TtBuildCommands");

    {
        VRCommand* commandStorage = batch.m_pCommandArray;
        outputStorage = batch.m_pOutput;
        for (int i = 0; i < numVehicles; i++)
        {
            VRVehicle* vehicle = registeredVehicles()[i];
            int numCommandsAdded = vehicle->m_pWheelCollide->BuildCastCommands(vehicle, filter, filterSize, commandStorage, outputStorage);
            if (numCommandsAdded > 0)
            {
                numCommands += numCommandsAdded;
                batch.m_uiEdgeIndex[i] = (hkUint8)numCommandsAdded;
                commandStorage += numCommandsAdded;
                outputStorage += numCommandsAdded;
            }
            else
            {
                batch.m_uiEdgeIndex[i] = 0;
            }
        }
    }

    VRMonitorStream::GetMonitorStream().timerCommand("Et");

    if (numJobs >= numCommands)
    {
        numJobs = numCommands;
    }

    const int commandsPerJob = numCommands / numJobs;
    const int remainder = numCommands % numJobs;
    {
        VRCommand* commands = batch.m_pCommandArray;
        VRJobHeader* jobHeader = batch.m_pJobHeader;
        for (int j = 0; j < numJobs; j++)
        {
            const int count = commandsPerJob + (j < remainder);
            VRRayCastJob job(world->m_pCollisionInput, jobHeader, commands, count, semaphore);
            job.ExecuteRayCastJob();
            jobQueue->EnqueueJob(job, 1);
            commands += count;
            jobHeader++;
        }
    }

    VRMonitorStream::GetMonitorStream().timerCommand("Et");

    return numJobs;
}
