
// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpufirejacobiansetupcallbackjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpufirejacobiansetupcallbackjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
// Havok constraint-callback pass of the integrate job: lets each constraint with callbacks update its
// runtime data, then frees the callback list and finishes the job on the job queue.

extern DWORD hkMonitorStreamTls;

struct S_00d94c40_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d94c40_TimerBeginListCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    const char* m_pFirst;
};

struct S_00d94c40_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d94c40_TimerBeginList(const char* name, const char* firstSplit)
{
    S_00d94c40_MonitorStream* s = (S_00d94c40_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d94c40_TimerBeginListCommand* h = (S_00d94c40_TimerBeginListCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = firstSplit;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00d94c40_Timer(const char* name)
{
    S_00d94c40_MonitorStream* s = (S_00d94c40_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d94c40_TimerCommand* h = (S_00d94c40_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d94c40_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d94c40_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d94c40_Heap* m_pStreamAllocator;
    S_00d94c40_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00d94c40_Router* hkMemoryRouter_getInstance();

struct S_00d94c40_Instance;
struct S_00d94c40_Runtime;

__declspec(align(16)) struct S_00d94c40_Input
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
    int m_offsetA;
    int m_offsetB;
    int m_pFirstQueryData;
    int m_pSecondQueryData;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    S_00d94c40_Instance* m_pConstraintChainInstance;
    int m_ulUserData;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct S_00d94c40_Data
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void update(S_00d94c40_Input& input);
};

struct S_00d94c40_Motion
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_motionId;
};

struct S_00d94c40_Body
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
    int m_solverOffset;
};

struct S_00d94c40_Instance
{
    int unk00;
    int unk04;
    int unk08;
    S_00d94c40_Data* m_data;
    S_00d94c40_Runtime* m_pByteBuffer;
    S_00d94c40_Motion* m_pFirstQueryData;
    S_00d94c40_Motion* m_pSecondQueryData;
};

struct S_00d94c40_Node
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00d94c40_Node* m_next;
};

struct S_00d94c40_Constraint
{
    S_00d94c40_Instance* ms_uiThreadLocalStorageIndex;
    S_00d94c40_Body* m_pBodyA;
    S_00d94c40_Body* m_pBodyB;
    S_00d94c40_Node* m_node;
    unsigned short unk10;
    unsigned char m_callbackFlags;
    unsigned char unk13;
    int unk14;
    int unk18;
    int m_ulUserData;
};

struct S_00d94c40_Header
{
    S_00d94c40_Runtime* m_pRuntime;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short m_usTrailingValue;
};

struct S_00d94c40_Runtime
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_iElementCount;
};

struct S_00d94c40_Callback
{
    S_00d94c40_Constraint* m_pHavokConstraint;
    S_00d94c40_Header* m_kHeader;
};

struct S_00d94c40_TaskData
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
    int m_solverOffset;
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
    S_00d94c40_Callback* m_kCallbackFunctions;
    int m_numCallbacks;
};

struct S_00d94c40_Job
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00d94c40_TaskData* m_taskData;
};

struct S_00d94c40_Context
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d94c40_Input m_pRayCastInput;
};

struct S_00d94c40_JobQueue
{
    void ProcessCallback(S_00d94c40_Job* finishedJob, S_00d94c40_Job& jobOut, int waitStatus);
};

void __cdecl hkSimpleContactConstraintData_fireCallbacks(S_00d94c40_Data* data, S_00d94c40_Input* input, S_00d94c40_Node* node, int mode);

// For each callback, fills input from its constraint and runs FUN_00d92900 and/or update per its flags, frees the array, then calls jobQueue->ProcessCallback.
// @fnv 0x00d94c40
void __cdecl ExecuteConstraintCallbacks(S_00d94c40_Context* context, S_00d94c40_JobQueue* jobQueue, S_00d94c40_Job* job)
{
    S_00d94c40_TaskData* taskData = job->m_taskData;
    S_00d94c40_Input input = context->m_pRayCastInput;
    if (taskData->m_numCallbacks > 0)
    {
        S_00d94c40_TimerBeginList("LtIntegrate", "StConstraintCallbacks");
        for (int i = 0; i < taskData->m_numCallbacks; i++)
        {
            S_00d94c40_Constraint* pConstraint = taskData->m_kCallbackFunctions[i].m_pHavokConstraint;
            input.m_pConstraintChainInstance = pConstraint->ms_uiThreadLocalStorageIndex;
            input.m_ulUserData = pConstraint->m_ulUserData;
            input.m_offsetA = pConstraint->m_pBodyA->m_solverOffset + taskData->m_solverOffset;
            input.m_offsetB = pConstraint->m_pBodyB->m_solverOffset + taskData->m_solverOffset;
            input.m_pFirstQueryData = pConstraint->ms_uiThreadLocalStorageIndex->m_pFirstQueryData->m_motionId;
            input.m_pSecondQueryData = pConstraint->ms_uiThreadLocalStorageIndex->m_pSecondQueryData->m_motionId;
            if (pConstraint->m_callbackFlags & 9)
            {
                S_00d94c40_Instance* instance = pConstraint->ms_uiThreadLocalStorageIndex;
                S_00d94c40_Data* data = instance->m_data;
                S_00d94c40_Runtime* oldRuntime = instance->m_pByteBuffer;
                S_00d94c40_Node* node = pConstraint->m_node;
                while (node->m_type >= 0x17)
                {
                    node = node->m_next;
                }
                hkSimpleContactConstraintData_fireCallbacks(data, &input, node, 2);
                S_00d94c40_Runtime* newRuntime = pConstraint->ms_uiThreadLocalStorageIndex->m_pByteBuffer;
                if (oldRuntime != newRuntime)
                {
                    S_00d94c40_Header* header = taskData->m_kCallbackFunctions[i].m_kHeader;
                    header->m_pRuntime = newRuntime;
                    header->m_usTrailingValue = newRuntime->m_iElementCount;
                }
            }
            if (pConstraint->m_callbackFlags & 4)
            {
                pConstraint->ms_uiThreadLocalStorageIndex->m_data->update(input);
            }
        }
        int iNumCallbacks = taskData->m_numCallbacks;
        S_00d94c40_Callback* p = taskData->m_kCallbackFunctions;
        hkMemoryRouter_getInstance()->heap().ReleaseBlock(p, iNumCallbacks * sizeof(S_00d94c40_Callback));
        taskData->m_kCallbackFunctions = 0;
        taskData->m_numCallbacks = 0;
        S_00d94c40_Timer("lt");
    }
    jobQueue->ProcessCallback(job, *job, 0);
}
