// src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpubroadphasejob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpubroadphasejob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned __int64 u64;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(u32);
extern "C" long (__stdcall* DAT_00fdf1ec)(volatile long*, long);
extern "C" u64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern "C" u32 DAT_0126835c;

extern const char str_010d3e68[];
extern const char str_010cd3d8[];
extern const char str_010c41f8[];
extern const char str_010d3e4c[];
extern const char str_010d3e38[];
extern const char str_010cc5bc[];
extern const char str_010cc5e4[];
extern const char str_010cc5d8[];
extern const char str_01076f38[];

struct StepWords { u32 start, end, delta, inverseDelta; };
struct BreachWords {u32 word0,word1,word2,word3;};
struct S93ba0_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, int size);
    virtual void v3();
    virtual void ReturnMemory(void* p, int size);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual bool hasSpace(int size);
};

struct S93ba0_Mem {
    char* lifoCursor;
    int unk04;
    int unk08;
    int unk0c;
    S93ba0_Alloc* AllocateMemoryBlock;
    int unk14;
    S93ba0_Alloc* heapAlloc;
    __forceinline S93ba0_Alloc& solver() { return *heapAlloc; }
    __forceinline S93ba0_Alloc* getBlockAlloc() { return AllocateMemoryBlock; }
};

extern "C" S93ba0_Mem* __cdecl hkMemoryRouter_getInstance();

struct S93ba0_Stream {
    int unk00;
    char* current;
    char* start;
    char* limit;
};

struct S93ba0_Cmd {
    const char* name;
    u32 time;
    int unk08;
    const char* extra;
    __forceinline void setTime() {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        time=ticks;
    }
};

__forceinline void S93ba0_timer(const char* name, const char* extra = 0)
{
    S93ba0_Stream* s = (S93ba0_Stream*)TlsGetValue(DAT_0126835c);
    S93ba0_Cmd* c = (S93ba0_Cmd*)s->current;
    if ((char*)c < s->limit) {
        c->name = name;
        if (extra) c->extra = extra;
        _ReadWriteBarrier();
        c->setTime();
        s->current = (char*)c + (extra ? 16 : 12);
    }
}

struct S93ba0_Pair { u32 a; u32 b; };

struct S93ba0_LocalArray {
    S93ba0_Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S93ba0_Pair* m_pTrailingData;

    __forceinline S93ba0_LocalArray(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        S93ba0_Mem* mem = hkMemoryRouter_getInstance();
        char* p = mem->lifoCursor;
        mem->lifoCursor = p + ((n * 8 + 127) & ~127);
        m_data = (S93ba0_Pair*)p;
        m_iCapacityState = n | 0x80000000;
        m_pTrailingData = (S93ba0_Pair*)p;
    }
    __forceinline void SetNodeCount(int v){m_iCapacityState=v;}
    __forceinline void setData(S93ba0_Pair* v){m_data=v;}
    __forceinline int& capacityRef(){return m_iCapacityState;}
    __forceinline S93ba0_Pair*& dataRef(){return m_data;}
    __forceinline void resetStorage(){m_data=0;m_iCapacityState=0x80000000;}
    __forceinline ~S93ba0_LocalArray()
    {
        S93ba0_Pair* local = m_pTrailingData;
        if (local == m_data) m_iElementCount = 0;
        hkMemoryRouter_getInstance()->lifoCursor = (char*)local;
        S93ba0_Alloc* a = hkMemoryRouter_getInstance()->getBlockAlloc();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000u) == 0)
            a->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * 8);
        m_data=0;
        m_iCapacityState=0x80000000;
    }
};

struct S93ba0_Chunk {
    int count;
    S93ba0_Chunk* next;
    int unk08;
    int unk0c;
    BreachWords firstRecord;
};

struct S93ba0_Node { S93ba0_Node* next; };

struct S93ba0_Block {
    int unk00;
    int unk04;
    int pending;
    volatile long refCount;
    int numThreads;
    void* buffer;
    int unk18;
    int bufferSize;
    char state;
    S93ba0_Chunk* chunks;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    void* table;
    u16 unk54;
    u16 tableCount;
    int unk58;
    void* arrData;
    int arrSize;
    int arrCapacityAndFlags;
    S93ba0_Node* bigNodes;
    int unk6c, unk70, unk74;
    S93ba0_Node* smallNodes;
};

struct S93ba0_Conn {
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
    int lockId;
};

struct S93ba0_Stager {
    void FUN_00cf70f0(S93ba0_Pair* data, int size);
    void hkpTypedBroadPhaseDispatcher_addPairs(S93ba0_Pair* data, int size, void* extra);
};

struct S93ba0_Device {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    S93ba0_Stager* stager;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    char* extra;
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
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    u8 unkD4; u8 enabled; u16 unkD6;
    int unk0d8;
    int unk0dc;
    int outputCapacity;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    StepWords info;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int pairCapacity;
    void FUN_00c911d0(int v);
    void hkpWorld_unlockIslandForConstraintUpdate(int v);
};

struct S93ba0_Builder {
    void FUN_00d0c030(int a, int b, void* device, S93ba0_LocalArray* first, S93ba0_LocalArray* second);
};

struct S93ba0_Setup {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    u8 unk24; u8 oldFlags; u8 newFlags; u8 unk27;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    S93ba0_Conn** conn;
    int buildParam;
    int unk50;
    int unk54;
    int pitch;
    int param;
    int count;
};

struct S93ba0_Job {
    u8 type;
    u8 flag1;
    u8 flag2;
    u8 unk03;
    u16 size;
    short id;
    int unk08, unk0c, unk10;
    S93ba0_Setup* setup;
    S93ba0_Block* block;
    int unk1c;
    void* blocks;
    u16 unk24;
    u16 numBlocks;
    u16 count;
    u16 capacity;
    int param;
    StepWords info;
    int unk40;
    u16 pitch;
};

struct S93ba0_Owner {
    S93ba0_Device* device;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
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
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    S93ba0_Builder* builder;
};

struct S93ba0_Output {
    void* ProcessCallback(void* a, void* b, int c);
    void* hkJobQueue_finishAddAndGetNextJob(int a, int b, void* job, int c);
};

extern "C" void __cdecl hkpWorldOperationUtil_markIslandInactiveMt(void* device, void* setup);
extern "C" void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(void* device, void* data, int count);
extern "C" void* __cdecl FUN_00d96530(int count, int size);

__forceinline void S93ba0_copy4(void* dst,const void* src,int n) { const u32* s=(const u32*)src; u32* d=(u32*)dst; for(int j=0;j<n;++j) { *d++=*s++; } }
struct T26_WaitExport { u32 begin; union {u32 end; int total;}; };
struct T26_WaitSolve { u32 begin; union {u32 end; char* copy;}; };
struct T26_Stamps { u32 begin,end; };
struct T26_Control { char* marker; int last; };
static __forceinline void initNext(S93ba0_Job* job, S93ba0_Device* dev,int param,int count,int cap,int pitch) {
        job->type = 13;
        job->flag1 = 0;
        job->flag2 = 1;
_ReadWriteBarrier();
        job->size = 0x50;
        job->id = -1;
        _ReadWriteBarrier();
        job->info.start = dev->info.start;
        job->info.end = dev->info.end;
        job->info.delta = dev->info.delta;
        job->info.inverseDelta = dev->info.inverseDelta;
        job->unk24 = 0;
        job->param = param;
        job->count = (u16)count;
        job->capacity = (u16)cap;
        job->blocks = 0;
        job->flag1 = 1;
        job->unk40 = 0;
        job->pitch = (u16)pitch;
}
// @fnv 0x00d93ba0
// src: COMMUNITY 0x00d93ba0
void* __cdecl hkpSingleThreadedJobsOnIsland_cpuBroadPhaseJob(S93ba0_Owner* owner, S93ba0_Output* output, S93ba0_Job* nextJobOut) throw()
{
    S93ba0_Job* job = nextJobOut;

    int total;
    char* copy;


    char* marker; int last;
    int index; S93ba0_Conn** conn;
    S93ba0_Setup* setup = job->setup;
    S93ba0_timer( str_010d3e68);
    if (job->block->pending && owner->device->enabled &&
        (setup->newFlags & 12) && !(setup->oldFlags & 12))
        hkpWorldOperationUtil_markIslandInactiveMt(owner->device, setup);

    marker = &job->block->state;
    S93ba0_LocalArray first(owner->device->pairCapacity);
    S93ba0_LocalArray second(owner->device->pairCapacity);
    S93ba0_Block* block = job->block;
    owner->builder->FUN_00d0c030(
        (int)setup->conn, setup->buildParam, owner->device, &first, &second);

    last = 1 - block->numThreads;
    int left = 0;
    volatile long* ref = &block->refCount;
    long prev;
    if (block->numThreads == 1)
        { prev = *ref; *ref = prev - 1; }
    else
        prev = DAT_00fdf1ec(ref, -1);

    if (prev == block->numThreads) {
        if (marker) {
            S93ba0_timer( str_010cd3d8);
            while (*(volatile char*)marker != 1 && *(volatile char*)marker != 2) {}
            S93ba0_timer( str_010c41f8);
        }
        if (block->chunks) {
            total = 0;
            for (S93ba0_Chunk* c = block->chunks; c; c = c->next)
                total += c->count;
            S93ba0_Mem* mem = hkMemoryRouter_getInstance();
            copy = mem->lifoCursor;
            mem->lifoCursor = copy + ((total * 16 + 127) & ~127);
            index = 0;
            for (S93ba0_Chunk* c = block->chunks; c; c = c->next) {
                int n = c->count * 4;
                u32* src = &c->firstRecord.word0;
                S93ba0_copy4(copy + index * 16, src, n);
                index += c->count;
            }
            hkpWorldCallbackUtil_fireContactImpulseLimitBreached(owner->device, copy, total);
            hkMemoryRouter_getInstance()->lifoCursor = copy;
        }
        *marker = 2;
    } else {
        if (*marker != 2) {
            S93ba0_timer( str_010d3e4c);
            while (*(volatile char*)marker != 2) {}
            S93ba0_timer( str_010c41f8);
        }
        if (block->numThreads <= 2)
            left = -1;
        else
            left = DAT_00fdf1ec(ref, -1) - 1;
    }

    if (first.m_iElementCount + second.m_iElementCount > 0) {
        S93ba0_timer( str_010d3e38, str_010cc5bc);
        conn = setup->conn;
        S93ba0_Device* device = (S93ba0_Device*)owner->device;
        if (first.m_iElementCount + second.m_iElementCount > 0) {
            S93ba0_timer( str_010cc5e4);
            device->FUN_00c911d0((*conn)->lockId);
            device->stager->FUN_00cf70f0(second.m_data, second.m_iElementCount);
            const int needed = first.m_iElementCount;
            if (!hkMemoryRouter_getInstance()->getBlockAlloc()->hasSpace(needed << 10)) {
                device->hkpWorld_unlockIslandForConstraintUpdate((*conn)->lockId);
            } else {
                S93ba0_timer( str_010cc5d8);
                char* extra = device->extra;
                device->stager->hkpTypedBroadPhaseDispatcher_addPairs(
                    first.m_data, first.m_iElementCount, extra ? extra + 8 : 0);
                device->hkpWorld_unlockIslandForConstraintUpdate((*conn)->lockId);
            }
        }
        S93ba0_timer( str_01076f38);
    }

    if (left == last) {
        while (block->bigNodes) {
            S93ba0_Node* n = block->bigNodes;
            block->bigNodes = n->next;
            hkMemoryRouter_getInstance()->getBlockAlloc()->ReleaseBlock(n, 0x1000);
        }
        while (block->smallNodes) {
            S93ba0_Node* n = block->smallNodes;
            block->smallNodes = n->next;
            hkMemoryRouter_getInstance()->getBlockAlloc()->ReleaseBlock(n, 0x30);
        }
        void* buffer = block->buffer;
        if (buffer) {
            int bufferSize = block->bufferSize;
            hkMemoryRouter_getInstance()->solver().ReturnMemory(buffer,bufferSize);
            block->buffer = 0;
        }
        if (block->numThreads > 1) {
            int tableCount = block->tableCount;
            void* table = block->table;
            hkMemoryRouter_getInstance()->getBlockAlloc()->ReturnMemory(table, tableCount * 4);
            block->table = 0;
        }
        S93ba0_Alloc* a = hkMemoryRouter_getInstance()->getBlockAlloc();
        block->arrSize = 0;
        if ((block->arrCapacityAndFlags & 0x80000000u) == 0)
            a->ReturnMemory(block->arrData, (block->arrCapacityAndFlags & 0x3fffffff) * 4);
        block->arrData = 0;
        block->arrCapacityAndFlags = 0x80000000;
        hkMemoryRouter_getInstance()->getBlockAlloc()->ReleaseBlock(block, 0x80);
    }


    int count = (*(S93ba0_Setup* volatile*)&setup)->count;
    if (count > 0) {
        S93ba0_Device* dev = owner->device;
        int cap = dev->outputCapacity;
        _ReadWriteBarrier();
int param=setup->param;int pitch=setup->pitch;
initNext(job,dev,param,count,cap,pitch);
        if (count > cap) {
            int n = (count - 1) / cap + 1;
            job->blocks = FUN_00d96530(n, 16);
            job->numBlocks = (u16)n;
        }
        S93ba0_timer( str_010c41f8);
        return output->hkJobQueue_finishAddAndGetNextJob(0, 1, job, 0);
    } else {
        S93ba0_timer( str_010c41f8);
        return output->ProcessCallback(job, job, 0);
    }

}
