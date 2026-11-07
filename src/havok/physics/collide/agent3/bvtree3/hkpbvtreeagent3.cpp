
// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl InitAndReturnTail(void*, void*, void*);
void __fastcall hkBvTreeAgent3_process(void* self, int, void*, int);
void __fastcall CallWithValueSource(void* self, int, int, int);
void __fastcall hkBvTreeAgent3_ProcessState_00d2d430(void* self, int, int, int);
void __fastcall Object__hkAgent1nMachine_WarpTime_Thunk(void* self, int, int, int);
// @fnv 0x00d2d9d0
// src: GUESS 0x00d2d9d0 (confidence: low)
void hkBvTreeAgent3_process_UpdateState_00d2d9d0(void* pObject)
{
    *(void**)pObject = (void*)&InitAndReturnTail;
    *(void**)((char*)pObject + 0x2c) = (void*)&hkBvTreeAgent3_process;
    *(int*)((char*)pObject + 0x28) = 0;
    *(int*)((char*)pObject + 8) = 0;
    *(int*)((char*)pObject + 0xc) = 0;
    *(int*)((char*)pObject + 0x10) = 0;
    *(int*)((char*)pObject + 0x14) = 0;
    *(void**)((char*)pObject + 0x18) = (void*)&CallWithValueSource;
    *(void**)((char*)pObject + 0x1c) = (void*)&hkBvTreeAgent3_ProcessState_00d2d430;
    *(int*)((char*)pObject + 0x20) = 0xd2d460;
    *(void**)((char*)pObject + 0x24) = (void*)&Object__hkAgent1nMachine_WarpTime_Thunk;
    *(int*)((char*)pObject + 4) = 0xda6dc0;
    *(char*)((char*)pObject + 0x30) = 1;
}

extern "C" void __cdecl _hkAgent1nMachine_WarpTime(void*, float, float, int);
// @fnv 0x00d2d480
// src: GUESS 0x00d2d480 (confidence: medium)
void __cdecl Object__hkAgent1nMachine_WarpTime_Thunk(void*, void* target, float first, float second, int flags)
{
    _hkAgent1nMachine_WarpTime(target, first, second, flags);
}

// Exe 0x00d2d4b0: unit-local Interface view; declarations and layout are preserved.
struct Hkpbvtreeagent3InterfaceView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
// @fnv 0x00d2d4b0
// src: GUESS 0x00d2d4b0 (confidence: low)
void Hkpbvtreeagent3_ForwardCall_00d2d4b0(Hkpbvtreeagent3InterfaceView** a)
{
    (*a)->f4();
}

struct LessU32
{
    int pad;
    bool operator()(unsigned a, unsigned b) const
    {
        return a < b;
    }
};

// Partitions pArr[d..h] around a middle pivot using cmpLess, swapping out-of-order elements, then recurses on the left part and loops on the right.
// @fnv 0x00d2da70
extern "C" void __cdecl QuickSortRange(unsigned* auiArray, int aiLow, int aiHigh, LessU32 aComparator)
{
setpoint:
    int iRight = aiHigh;
    int iLeft = aiLow;
    __declspec(align(16)) unsigned pivot = auiArray[(aiLow + aiHigh) >> 1];
    do
    {
        while (aComparator(auiArray[iLeft], pivot))
            iLeft++;
        while (aComparator(pivot, auiArray[iRight]))
            iRight--;
        if (iRight >= iLeft)
        {
            if (iRight != iLeft)
            {
                unsigned t = auiArray[iRight];
                auiArray[iRight] = auiArray[iLeft];
                auiArray[iLeft] = t;
            }
            iRight--;
            iLeft++;
        }
    } while (iLeft <= iRight);
    if (aiLow < iRight)
        QuickSortRange(auiArray, aiLow, iRight, aComparator);
    if (iLeft < aiHigh)
    {
        aiLow = iLeft;
        goto setpoint;
    }
}

struct ValueSource
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
};

struct CallBuf
{
    int unk00;
    ValueSource** unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(void* a, void* b);

// Calls f4 on the ValueSource, fills a CallBuf with the arguments and result, then passes it to FUN_00da48e0 with p2.
// @fnv 0x00d2d3e0
void __cdecl CallWithValueSource(void* apUnused, void* p2, int aiArg0, ValueSource** apValueSource, int aiArg1,
                                 int aiArg2, int aiArg3)
{
    int r;
    r = (*apValueSource)->f4();
    CallBuf callBuf;
    callBuf.unk00 = aiArg0;
    callBuf.unk04 = apValueSource;
    callBuf.unk10 = aiArg1;
    callBuf.unk14 = aiArg2;
    callBuf.unk0c = r;
    callBuf.unk18 = aiArg3;
    hkAgent1nMachine_UpdateShapeCollectionFilter(p2, &callBuf);
}

struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int m_kind;            // 0x0c
    unsigned char m_flag;  // 0x10
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    void* m_ptr18;  // 0x18
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_ptr34;  // 0x34
};

// Returns a pointer stored in the object based on its kind: m_ptr18 for kind 8 when m_flag is 1, m_ptr34 for kind 10, otherwise null.
// @fnv 0x00d2d4c0
void* __cdecl GetSpawnedObjectPointer(void** holder)
{
    SpawnedObject* obj = (SpawnedObject*)*holder;
    switch (obj->m_kind)
    {
    case 8:
        if (obj->m_flag == 1)
        {
            return obj->m_ptr18;
        }
        return 0;
    case 10:
        return obj->m_ptr34;
    default:
        return 0;
    }
}

struct Agent
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(const char* typeName);
    virtual void f7();
};

extern "C" void __cdecl hkpAgentMachineUtil_calc1nStatistics(int, int, void*);
extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(int, int);

// Calls p->f6 with the type name hkBvTreeAgent3, then FUN_00d97250 with a2, a3 and p, then p->f7().
// @fnv 0x00d2d430
// src: GUESS 0x00d2d430 (confidence: low)
void __cdecl hkBvTreeAgent3_ProcessState_00d2d430(int a1, int a2, int a3, Agent* pAgent)
{
    pAgent->f6("hkBvTreeAgent3");
    hkpAgentMachineUtil_calc1nStatistics(a2, a3, pAgent);
    pAgent->f7();
}

// src: GUESS 0x00d2d460 (confidence: low)
void __cdecl Object_ForwardCall_00d2d460(int a, int b, int c)
{
    hkpAgent1nSector_ProcessEntries_00da3510(b, c);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" const char str_010ce7ec[];
extern "C" const char str_010ce7e0[];
extern "C" const char str_010ce7d4[];
extern "C" const char str_01076f38[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;

struct S00d2d890_Rec
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
    const char* tag;
};
struct S00d2d890_Buf
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct __declspec(align(16)) S00d2d890_Local
{
    int b00;
    int b01;
    int b02;
    int b03;
    int b04;
    int b05;
    int b06;
    int b07;
    int b08;
    int b09;
    int b0a;
    int b0b;
    int b0c;
    int b0d;
    int b0e;
    int b0f;
    S00d2d890_Local()
    {}
    void hkTransform_setInverse(void* a);
};
struct S00d2d890_Hits
{
    int q000;
    int q001;
    int q002;
    int q003;
    int q004;
    int q005;
    int q006;
    int q007;
    int q008;
    int q009;
    int q00a;
    int q00b;
    int q00c;
    int q00d;
    int q00e;
    int q00f;
    int q010;
    int q011;
    int q012;
    int q013;
    int q014;
    int q015;
    int q016;
    int q017;
    int q018;
    int q019;
    int q01a;
    int q01b;
    int q01c;
    int q01d;
    int q01e;
    int q01f;
    int q020;
    int q021;
    int q022;
    int q023;
    int q024;
    int q025;
    int q026;
    int q027;
    int q028;
    int q029;
    int q02a;
    int q02b;
    int q02c;
    int q02d;
    int q02e;
    int q02f;
    int q030;
    int q031;
    int q032;
    int q033;
    int q034;
    int q035;
    int q036;
    int q037;
    int q038;
    int q039;
    int q03a;
    int q03b;
    int q03c;
    int q03d;
    int q03e;
    int q03f;
    int q040;
    int q041;
    int q042;
    int q043;
    int q044;
    int q045;
    int q046;
    int q047;
    int q048;
    int q049;
    int q04a;
    int q04b;
    int q04c;
    int q04d;
    int q04e;
    int q04f;
    int q050;
    int q051;
    int q052;
    int q053;
    int q054;
    int q055;
    int q056;
    int q057;
    int q058;
    int q059;
    int q05a;
    int q05b;
    int q05c;
    int q05d;
    int q05e;
    int q05f;
    int q060;
    int q061;
    int q062;
    int q063;
    int q064;
    int q065;
    int q066;
    int q067;
    int q068;
    int q069;
    int q06a;
    int q06b;
    int q06c;
    int q06d;
    int q06e;
    int q06f;
    int q070;
    int q071;
    int q072;
    int q073;
    int q074;
    int q075;
    int q076;
    int q077;
    int q078;
    int q079;
    int q07a;
    int q07b;
    int q07c;
    int q07d;
    int q07e;
    int q07f;
};
struct S00d2d890_Rec3
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
};
struct S00d2d890_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
char** hkMemoryRouter_getInstance();
int hkpCdBody_UpdateState_00d2d4f0(int a, int b, S00d2d890_Local* l, void* c, int d, int e, char* f, int g);
int Hkpbvtreeagent3_ForwardCall_00d2d4b0(int a, S00d2d890_Hits* h);
int hkAgent1nMachine_Process(int a, void* b, int c, char* d, int e);

// Takes 0x4000 bytes from an arena, calls FUN_00d2d4f0, FUN_00d2d4b0 and FUN_00da4aa0 between timing markers, restores the arena and returns child + 0x10.
// @fnv 0x00d2d890
// src: HAVOK_LIB 0x00d2d890
char* __cdecl hkBvTreeAgent3_process(char* self, int a1, char* child, int a3, int a4)
{
    volatile unsigned int tb;
    S00d2d890_Buf* t = (S00d2d890_Buf*)TlsGetValue(DAT_0126835c);
    if (t->cur < t->end)
    {
        S00d2d890_Rec* r = (S00d2d890_Rec*)t->cur;
        r->name = str_010ce7ec;
        r->tag = str_010ce7e0;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        r->stamp = tb;
        t->cur = (char*)(r + 1);
    }
    char** arena = hkMemoryRouter_getInstance();
    char* mark = *arena;
    *arena = mark + 0x4000;
    S00d2d890_Local loc;
    loc.hkTransform_setInverse(self + 0x20);
    S00d2d890_Hits hits;
    int c = *(int*)(self + 0xc);
    int p1 = *(int*)(self + 4);
    int p0 = *(int*)self;
    int numHits = hkpCdBody_UpdateState_00d2d4f0(p0, p1, &loc, self + 0x70, c, 0, mark, 0x1000);
    int tree = *(int*)(self + 4);
    int r4b = Hkpbvtreeagent3_ForwardCall_00d2d4b0(tree, &hits);

    t = (S00d2d890_Buf*)TlsGetValue(DAT_0126835c);
    if (t->cur < t->end)
    {
        S00d2d890_Rec3* r = (S00d2d890_Rec3*)t->cur;
        r->name = str_010ce7d4;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        r->stamp = tb;
        t->cur = (char*)(r + 1);
    }
    char* cond = numHits < 0 ? 0 : mark;
    hkAgent1nMachine_Process((int)child, self, (*(volatile int*)&r4b), cond, a4);
    t = (S00d2d890_Buf*)TlsGetValue(DAT_0126835c);
    if (t->cur < t->end)
    {
        S00d2d890_Rec3* r = (S00d2d890_Rec3*)t->cur;
        r->name = str_01076f38;
        _ReadWriteBarrier();
        tb = (unsigned int)__rdtsc();
        r->stamp = tb;
        t->cur = (char*)(r + 1);
    }
    *hkMemoryRouter_getInstance() = mark;
    return child + 0x10;
}

struct FUN_00cfbd60_Obj
{
    void AddEntry(void* a1, int a2, int a3);
};
__declspec(noinline) void hkBvTreeAgent3_process_UpdateState_00d2d9d0(void* pObject);

struct __declspec(align(16)) S_00d2da20_AgentFuncs
{
    void* m_pCreateFunc;
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
    void* unk2C;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
    bool unk32;
    S_00d2da20_AgentFuncs()
    {
        m_bIsFlipped = false;
        m_bIsPredictive = false;
        unk32 = false;
        unk18 = 0;
        unk1C = 0;
        unk20 = 0;
        unk24 = 0;
        unk28 = 0;
    }
};

// Builds an S_00d2da20_AgentFuncs with FUN_00d2d9d0, then passes it to target->FUN_00cfbd60 with -1 and 8.
// @fnv 0x00d2da20
// src: HAVOK_LIB 0x00d2da20
void hkBvTreeAgent3_registerAgent3(FUN_00cfbd60_Obj* target)
{
    S_00d2da20_AgentFuncs agentFuncs;
    hkBvTreeAgent3_process_UpdateState_00d2d9d0(&agentFuncs);
    target->AddEntry(&agentFuncs, -1, 8);
}
