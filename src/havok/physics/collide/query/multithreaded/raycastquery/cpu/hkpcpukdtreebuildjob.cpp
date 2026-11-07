
// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreebuildjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreebuildjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <windows.h>
#include "../../../../../../../../include/Pair.h"
extern DWORD DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);
unsigned __int64 __cdecl __rdtsc(void);
struct __declspec(align(8)) ScratchWord
{
    DWORD unk00;
    DWORD value;
};
struct TraceRecord
{
    const char* m_pTag;
    DWORD m_dwTime;
    DWORD unk08;
};
struct TraceBuffer
{
    DWORD unk00;
    TraceRecord* m_pCurrent;
    DWORD unk08;
    TraceRecord* m_pRecordEnd;
};
struct ArgStruct
{
    DWORD unk00;
    unsigned short size;
    short index;
    DWORD unk08;
    DWORD unk0c;
    int m_10;
    int* m_14;
    DWORD unk18;
    DWORD unk1c;
    int m_20;
    int m_24;
    char* m_28;
    int m_2c;
    int* m_30;
    int* m_34;
    int m_38;
    int m_3c;
    int m_40;
};
struct Head
{
    int m_20;
    int m_24;
    unsigned short s0;
    unsigned short s1;
    unsigned short s2;
    unsigned short s3;
    unsigned short s4;
    unsigned short s5;
    unsigned short s6;
    unsigned short s7;
};
struct Vec16
{
    float f0;
    float f1;
    float f2;
    float f3;
};
struct __declspec(align(16)) VecA
{
    float x;
    float y;
    float z;
    float w;
};
extern float DAT_012684d0[4];
struct InElem
{
    DWORD* m_20ptr;
    DWORD m_24;
    DWORD m_28;
    Vec16 m_2cvec;
    DWORD m_3c;
    VecA m_40vec;
    DWORD unk30;
    DWORD unk34;
    DWORD unk38;
    DWORD unk3c;
    VecA initialVector;
};
struct OutElem
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short size;
    short index;
    DWORD unk08;
    DWORD unk0c;
    int m_10;
    int* m_14;
    DWORD m_18;
    DWORD unk1c;
    char* m_20;
    int m_24;
    DWORD m_28;
    DWORD m_2c;
    DWORD m_30;
    DWORD m_34;
    DWORD m_38;
    DWORD unk3c;
    VecA m_40vec;
    int* m_50;
    DWORD m_54;
    int m_58;
    DWORD unk5c;
    OutElem()
    {
        b0 = 4;
        b1 = 3;
        size = 0x60;
        index = -1;
        m_10 = 0;
        m_18 = 0;
        b2 = 1;
        m_14 = 0;
        m_50 = 0;
    }
};
__forceinline void FillChild(OutElem& out, const InElem& in, ArgStruct* arg, int child, int count, int offset,
                             ScratchWord* scratch, int rem)
{
    out.m_14 = arg->m_14;
    __m128 vector = *(const __m128*)&in.m_40vec;
    if (child)
        (&out - 1)->m_58 = count;
    out.m_2c = in.m_20ptr[0];
    out.m_30 = in.m_20ptr[1];
    out.m_28 = in.m_24;
    out.m_54 = in.m_28;
    out.m_34 = *(DWORD*)&in.m_2cvec.f0;
    out.m_38 = *(DWORD*)&in.m_2cvec.f1;
    out.m_10 = arg->m_10;
    out.m_24 = arg->m_2c;
    if (child == 1)
        scratch->value = rem;
    _mm_store_ps(&out.m_40vec.x, vector);
    int* pointer = arg->m_30;
    if (child)
    {
        if (pointer)
            pointer += child;
        else
            pointer = 0;
    }
    if (child == 0)
    {
        out.m_20 = arg->m_28 + offset * 8;
        out.m_50 = pointer;
    }
    else
    {
        out.m_50 = pointer;
        out.m_20 = arg->m_28 + offset * 8;
    }
}
struct Ctx
{
    int hkJobQueue_lockQueue(void* p);
    int InsertItemAndNotify(int h, void* p, int z);
    void hkJobQueue_unlockQueue(int h);
    int ProcessCallback(ArgStruct* a, ArgStruct* b, int z);
};
extern "C" void __cdecl MixChannels(Head* a1, char* a2, int a3, int a4, int a5, int a6, DWORD* a7);
extern "C" void __cdecl ProcessEntries_00df37b0(Head* a1, char* a2, int a3, int a4, void* a5, int* a6, unsigned short* a7);
struct ContextHandle
{
    Ctx* object;
    Ctx* operator->() const
    {
        return object;
    }
};
struct ArgHandle
{
    ArgStruct* object;
    ArgStruct* operator->() const
    {
        return object;
    }
    operator ArgStruct*() const
    {
        return object;
    }
};
// If arg->m_38 < 8 calls MixChannels, else calls FUN_00df37b0 and queues four child elements on ctx, with trace records around it and a final ProcessCallback call.
// @fnv 0x00df7e20
int __cdecl BuildKdTreeDistributed(ContextHandle ctx, ArgStruct* input, ...)
{
    ScratchWord scratch;
    TraceBuffer* pTraceBuf = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    TraceRecord* pTraceRec = pTraceBuf->m_pCurrent;
    if (pTraceRec < pTraceBuf->m_pRecordEnd)
    {
        pTraceRec->m_pTag = "TtCpuKdTreeBuildFastDistributed";
        _ReadWriteBarrier();
        *(volatile DWORD*)&scratch.value = (DWORD)__rdtsc();
        pTraceRec->m_dwTime = *(volatile DWORD*)&scratch.value;
        pTraceBuf->m_pCurrent = pTraceRec + 1;
    }
    ArgStruct* arg = input;
    int zero;
    Head head;
    head.m_20 = arg->m_20;
    head.m_24 = arg->m_24;
    int result;
    if (8 > arg->m_38)
    {
        MixChannels(&head, arg->m_28, arg->m_2c, arg->m_3c, arg->m_38, arg->m_40, &scratch.value);
        result = 0;
        int* p30 = arg->m_30;
        if (p30 != 0)
        {
            p30[0] = (int)scratch.value;
            p30[1] = (int)scratch.value;
            p30[2] = (int)scratch.value;
            p30[3] = (int)scratch.value;
        }
    }
    else
    {
        InElem in[4];
        __m128 initial = _mm_load_ps(DAT_012684d0);
        // The helper fills these pairs without running Pair constructors.
        int pairStorage[4 * sizeof(Pair) / sizeof(int)];
        Pair* pairs = reinterpret_cast<Pair*>(pairStorage);
        head.s2 = 0;
        head.s1 = 0;
        head.s0 = 0;
        head.s6 = -1;
        head.s5 = -1;
        head.s4 = -1;
        in[0].m_20ptr = (DWORD*)&pairs[0];
        in[1].m_20ptr = (DWORD*)&pairs[1];
        in[2].m_20ptr = (DWORD*)&pairs[2];
        in[3].m_20ptr = (DWORD*)&pairs[3];
        in[0].m_28 = -1;
        _mm_store_ps(&in[0].initialVector.x, initial);
        in[1].m_28 = -1;
        _mm_store_ps(&in[1].initialVector.x, initial);
        in[2].m_28 = -1;
        _mm_store_ps(&in[2].initialVector.x, initial);
        in[3].m_28 = -1;
        _mm_store_ps(&in[3].initialVector.x, initial);
        ProcessEntries_00df37b0(&head, arg->m_28, arg->m_3c, arg->m_38, &in[0].m_20ptr, arg->m_34, &head.s0);
        OutElem out[4];
        result = 0;
        int iQuarter = arg->m_40 / 4;
        int iCumulative = 8;
        FillChild(out[0], in[0], arg, 0, iQuarter, iCumulative, &scratch, 0);
        int rem = iQuarter & 1;
        arg->m_34[0] += rem + iQuarter;
        iCumulative += arg->m_34[0];
        FillChild(out[1], in[1], arg, 1, iQuarter, iCumulative, &scratch, rem);
        arg->m_34[1] += rem + iQuarter;
        iCumulative += arg->m_34[1];
        FillChild(out[2], in[2], arg, 2, iQuarter, iCumulative, &scratch, 0);
        arg->m_34[2] += scratch.value + iQuarter;
        iCumulative += arg->m_34[2];
        FillChild(out[3], in[3], arg, 3, iQuarter, iCumulative, &scratch, 0);
        arg->m_34[3] += scratch.value + iQuarter;
        out[3].m_58 = arg->m_40 - iQuarter * 3;
        *arg->m_14 = 4;
        struct BigBuf
        {
            void* unk000;
            DWORD unk004;
            DWORD unk008;
            DWORD unk00c;
            DWORD unk010;
            DWORD unk014;
            DWORD unk018;
            DWORD unk01c;
            DWORD unk020;
            DWORD unk024;
            DWORD unk028;
            DWORD unk02c;
            DWORD unk030;
            DWORD unk034;
            DWORD unk038;
            DWORD unk03c;
            DWORD unk040;
            DWORD unk044;
            DWORD unk048;
            DWORD unk04c;
            DWORD unk050;
            DWORD unk054;
            DWORD unk058;
            DWORD unk05c;
            DWORD unk060;
            DWORD unk064;
            DWORD unk068;
            DWORD unk06c;
            DWORD unk070;
            DWORD unk074;
            DWORD unk078;
            DWORD unk07c;
            DWORD unk080;
            DWORD unk084;
            DWORD unk088;
            DWORD unk08c;
            DWORD unk090;
            DWORD unk094;
            DWORD unk098;
            DWORD unk09c;
            DWORD unk0a0;
            DWORD unk0a4;
            DWORD unk0a8;
            DWORD unk0ac;
            DWORD unk0b0;
            DWORD unk0b4;
            DWORD unk0b8;
            DWORD unk0bc;
            DWORD unk0c0;
            DWORD unk0c4;
            DWORD unk0c8;
            DWORD unk0cc;
            DWORD unk0d0;
            DWORD unk0d4;
            DWORD unk0d8;
            DWORD unk0dc;
            DWORD unk0e0;
            DWORD unk0e4;
            DWORD unk0e8;
            DWORD unk0ec;
            DWORD unk0f0;
            DWORD unk0f4;
            DWORD unk0f8;
            DWORD unk0fc;
            DWORD unk100;
            DWORD unk104;
            DWORD unk108;
            DWORD unk10c;
            DWORD unk110;
            DWORD unk114;
            DWORD unk118;
            DWORD unk11c;
            DWORD unk120;
            DWORD unk124;
            DWORD unk128;
            DWORD unk12c;
            DWORD unk130;
            DWORD unk134;
            DWORD unk138;
            DWORD unk13c;
            DWORD unk140;
            DWORD unk144;
            DWORD unk148;
            DWORD unk14c;
            DWORD unk150;
            DWORD unk154;
            DWORD unk158;
            DWORD unk15c;
            DWORD unk160;
            DWORD unk164;
            DWORD unk168;
            DWORD unk16c;
        } buf;
        int h = ctx->hkJobQueue_lockQueue(&buf);
        ctx->InsertItemAndNotify(h, &out[0], result);
        ctx->InsertItemAndNotify(h, &out[1], result);
        ctx->InsertItemAndNotify(h, &out[2], result);
        ctx->InsertItemAndNotify(h, &out[3], result);
        ctx->hkJobQueue_unlockQueue(h);
        (void)buf;
    }
    zero = ctx->ProcessCallback(arg, arg, result);
    TraceBuffer* pTraceBuf2 = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    if (pTraceBuf2->m_pCurrent < pTraceBuf2->m_pRecordEnd)
    {
        TraceRecord* pTraceRec2 = pTraceBuf2->m_pCurrent;
        pTraceRec2->m_pTag = "Et";
        _ReadWriteBarrier();
        *(volatile DWORD*)&scratch.value = (DWORD)__rdtsc();
        pTraceRec2->m_dwTime = *(volatile DWORD*)&scratch.value;
        pTraceBuf2->m_pCurrent = pTraceRec2 + 1;
    }
    return zero;
}

extern unsigned long DAT_0126835c;
extern char str_010cc5c4;
extern char str_010d3ea4;
extern char str_010d3eb8;
extern char str_01076f38;

struct S00d947e0_Tls
{
    int unk00;
    char* unk04;
    int unk08;
    char* unk0C;
};

struct S00d947e0_Obj
{
    char unk000;
};

struct S00d947e0_Info
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
    short unk54;
    short unk56;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
};

struct S00d947e0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    short unk12;
    int unk14;
    S00d947e0_Info* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};

enum S00d947e0_JobType
{
    S00d947e0_JOB_DYNAMICS = 0
};
enum S00d947e0_SpuType
{
    S00d947e0_SPU_DISABLED = 2
};

template <class E, class S> struct S00d947e0_Enum
{
    S m_kStorage;
    __forceinline S00d947e0_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
};

struct __declspec(align(16)) S00d947e0_Job
{
    unsigned char m_subType;
    S00d947e0_Enum<S00d947e0_JobType, unsigned char> m_eJobType;
    S00d947e0_Enum<S00d947e0_SpuType, unsigned char> m_spuType;
    unsigned char m_03;
    unsigned short m_iElementCount;
    short m_iAffinity;
    int m_08;
    int m_0c;

    __forceinline S00d947e0_Job(unsigned char subType, unsigned short size)
        : m_subType(subType), m_eJobType(S00d947e0_JOB_DYNAMICS), m_spuType(S00d947e0_SPU_DISABLED), m_iElementCount(size),
          m_iAffinity(-1)
    {}
};

struct S00d947e0_DynJob : S00d947e0_Job
{
    short m_10;
    short m_12;
    int m_14;
    S00d947e0_Info* m_18;
    int m_1c;

    __forceinline S00d947e0_DynJob(unsigned char subType, unsigned short size, const S00d947e0_Data& src)
        : S00d947e0_Job(subType, size)
    {
        m_10 = src.unk10;
        m_14 = src.unk14;
    }
};

struct S00d947e0_Cmd : S00d947e0_DynJob
{
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    short m_34;
    short m_36;
    int m_38;
    unsigned char m_3c;
    unsigned char m_3d;
    short m_3e;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;

    __forceinline S00d947e0_Cmd(const S00d947e0_Data& src, S00d947e0_Info* info) : S00d947e0_DynJob(0xb, 0x40, src)
    {
        m_18 = info;
        m_1c = src.unk1c;
        m_20 = info->unk78;
        m_36 = 0;
        m_3c = 0;
        m_34 = info->unk54;
        m_30 = info->unk14;
    }
};

struct S00d947e0_Queue
{
    void hkJobQueue_addJob(const S00d947e0_Job& job, int a);
    void ProcessCallback(S00d947e0_Data* a, S00d947e0_Data* b, int c);
};

static __forceinline void S00d947e0_memClear16(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    }
}

void __cdecl hkSolveConstraints(void* a, int b, int c, int d);
void __cdecl hkExportImpulsesAndRhs(void* a, int b, int c, int d);

// Writes profiler records, clears a buffer, calls FUN_00d8d030, queues an S00d947e0_Cmd via a2->FUN_00d04b50, calls FUN_00df0680, then calls a2->ProcessCallback.
// @fnv 0x00d947e0
// src: HAVOK_LIB 0x00d947e0
void __cdecl hkCpuSolveConstraintsJob(S00d947e0_Obj** a1, S00d947e0_Queue* apQueue, S00d947e0_Data* apData)
{
    volatile unsigned int tb;

    S00d947e0_Tls* tls = (S00d947e0_Tls*)TlsGetValue(DAT_0126835c);
    char* cur = tls->unk04;
    if (cur < tls->unk0C)
    {
        *(char**)cur = &str_010cc5c4;
        *(char**)(cur + 0xc) = &str_010d3ea4;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = tb;
        tls->unk04 = cur + 0x10;
    }

    int base = apData->unk20;
    int p28 = apData->unk28 + base;
    int p2c = apData->unk2c + base;
    int p30 = apData->unk30 + base;
    unsigned int bytes = (apData->unk38 * 4 + 15) & 0xfffffff0u;
    S00d947e0_memClear16((int*)p30, bytes / 16);
    hkSolveConstraints(&(*a1)->unk000 + 0x1e0, p2c, p28, p30);

    S00d947e0_Info* info = apData->unk18;
    apQueue->hkJobQueue_addJob(S00d947e0_Cmd(*apData, info), 0);

    tls = (S00d947e0_Tls*)TlsGetValue(DAT_0126835c);
    cur = tls->unk04;
    if (cur < tls->unk0C)
    {
        *(char**)cur = &str_010d3eb8;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = tb;
        tls->unk04 = cur + 0xc;
    }

    hkExportImpulsesAndRhs(&(*a1)->unk000 + 0x1e0, info->unk40, info->unk3c, info->unk30);

    tls = (S00d947e0_Tls*)TlsGetValue(DAT_0126835c);
    cur = tls->unk04;
    if (cur < tls->unk0C)
    {
        *(char**)cur = &str_01076f38;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = tb;
        tls->unk04 = cur + 0xc;
    }

    apQueue->ProcessCallback(apData, apData, 0);
}
