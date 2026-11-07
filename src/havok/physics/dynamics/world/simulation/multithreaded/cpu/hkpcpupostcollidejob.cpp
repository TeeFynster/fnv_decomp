
// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpupostcollidejob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpupostcollidejob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();
extern unsigned int DAT_0126835c;
extern void* DAT_0fdf044;
extern void* DAT_010d3de4;
extern void* DAT_010d3dd4;
extern void* DAT_010d3dc8;
extern void* DAT_01076f38;

static void* tlsGetValue()
{
    return ((void*(__stdcall*)(unsigned int))DAT_0fdf044)(DAT_0126835c);
}

struct ShapeCmds
{
    int m_offset;
    int m_iElementCount;
    inline char* get()
    {
        return (char*)this + m_offset;
    }
};

struct Shape
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    ShapeCmds m_10;
};

struct ShapeList
{
    int count;
    int unk04;
    int unk08;
    Shape* shapes[1];
    void hkpAgentSectorHeader_deallocate();
};

struct Caller;

struct TargetClass
{
    int __thiscall ProcessCallback(Caller* a, Caller* b, int c);
};

struct Accum
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
};

struct Caller
{
    void* vtbl;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    Accum* m_14;
    void* unk18;
    void* unk1c;
    ShapeList* m_20;
};

struct Worker
{
    void __thiscall EnterLock(Accum* a);
    void __thiscall hkpWorld_unlockIslandForConstraintUpdate(Accum* a);
};

extern "C" int __cdecl hkPhysicsCommandMachineProcess(Worker* a, char* b, int c);

struct TlsObject
{
    int unk00;
    char* records;
    int unk08;
    char* recordsEnd;
};

// Accumulates shape data into a shared Accum under a lock, logs timing events, and optionally calls a target class method.
// @fnv 0x00d931a0
int __cdecl AccumulateShapes(Worker** a1, TargetClass* apTarget, Caller* apCaller)
{
    TlsObject* tls = (TlsObject*)tlsGetValue();
    char* rec = tls->records;
    if (rec < tls->recordsEnd)
    {
        *(const void**)rec = &DAT_010d3de4;
        *(const void**)(rec + 12) = &DAT_010d3dd4;
        _ReadWriteBarrier();
        volatile unsigned int ts = (unsigned int)__rdtsc();
        *(unsigned int*)(rec + 4) = ts;
        tls->records = rec + 16;
    }

    Accum* acc = apCaller->m_14;
    (*a1)->EnterLock(acc);

    int count = apCaller->m_20->count;
    for (int i = 0; i < count; i++)
    {
        if (i < count - 4)
        {
            _mm_prefetch((const char*)apCaller->m_20->shapes[(short)(i + 4)], _MM_HINT_NTA);
        }

        Shape* shape = apCaller->m_20->shapes[(short)i];
        int v = shape->m_iWordAt00;
        if (acc->m_8 > v)
        {
            v = acc->m_8;
        }
        acc->m_8 = v;
        acc->m_iThirdValue += shape->m_iWordAt04;
        acc->m_10 += shape->m_8;
        acc->m_14 += shape->m_iThirdValue;

        if (shape->m_10.m_iElementCount)
        {
            int val = (unsigned int)shape->m_10.m_iElementCount >> 4;
            TlsObject* tls2 = (TlsObject*)tlsGetValue();
            char* rec8 = tls2->records;
            if (rec8 < tls2->recordsEnd)
            {
                *(const void**)rec8 = &DAT_010d3dc8;
                *(float*)(rec8 + 4) = (float)val;
                tls2->records = rec8 + 8;
            }
            hkPhysicsCommandMachineProcess(*a1, shape->m_10.get(), shape->m_10.m_iElementCount);
        }
    }

    apCaller->m_20->hkpAgentSectorHeader_deallocate();
    (*a1)->hkpWorld_unlockIslandForConstraintUpdate(acc);

    {
        TlsObject* tls3 = (TlsObject*)tlsGetValue();
        char* rec12 = tls3->records;
        if (rec12 < tls3->recordsEnd)
        {
            *(const void**)rec12 = &DAT_01076f38;
            _ReadWriteBarrier();
            volatile unsigned int ts3 = (unsigned int)__rdtsc();
            *(unsigned int*)(rec12 + 4) = ts3;
            tls3->records = rec12 + 12;
        }
    }

    if (apTarget)
    {
        return apTarget->ProcessCallback(apCaller, apCaller, 0);
    }
    else
    {
        return 2;
    }
}
