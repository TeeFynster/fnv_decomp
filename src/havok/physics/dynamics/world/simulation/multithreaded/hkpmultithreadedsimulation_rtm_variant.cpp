// hkMemoryRouterQ_hkpmultithreadedsimulation_rtm_variant: local type (was include/hkMemoryRouterQ.h, which had no evidence of one real class); no method of it is bound to a named game function
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkBool.h"

class hkMemoryRouterQ_hkpmultithreadedsimulation_rtm_variant
{
public:
    int unk00;
    int unk04;
    int unk08;
    union
    {
        int unk0C;
        int unk0c;
    };
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }

    hkMemoryAllocator& debug();
};
#include "../../../../../../../include/Pair.h"
#include "../../../../../../../include/Vec4.h"

__forceinline float Vec4::delta() const
{
    return z;
}

__forceinline void Vec4::set(float start, float end)
{
    x = start;
    y = end;
    z = end - start;
    w = z == 0.0f ? 0.0f : 1.0f / z;
}

// src/havok/physics/dynamics/world/simulation/multithreaded/hkpmultithreadedsimulation_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/world/simulation/multithreaded/hkpmultithreadedsimulation.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/world/simulation/multithreaded/hkpmultithreadedsimulation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/hkpmultithreadedsimulation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl Deallocate(void*);
extern int DAT_010c63bc;
struct FUN_00d04300
{
    int* m_p;
    FUN_00d04300(bool del);
};
int __fastcall hkpMultiThreadedSimulation_getMultithreadConfig(int self, int, int* out);
void __fastcall hkpMultiThreadedSimulation_setMultithreadConfig(void* this_, int, int* arg, int);
struct S_00d02020_Owner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(void* other);
};
struct S_00d02020_Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char m_iOwnerOffset;
    S_00d02020_Owner* getOwner()
    {
        return (S_00d02020_Owner*)((char*)this + m_iOwnerOffset);
    }
};
struct S_00d02020_Handle
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    S_00d02020_Collidable* getOwner()
    {
        return (S_00d02020_Collidable*)((char*)this + m_iOwnerOffset);
    }
};
struct S_00d02020_Pair
{
    S_00d02020_Handle* m_kPointA;
    S_00d02020_Handle* m_kPointB;
};
void __stdcall hkpMultiThreadedSimulation_MtPhantomBroadPhaseListener_removeCollisionPair(S_00d02020_Pair* pair);
struct CompareValue
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unkA0, unkA4, unkA8, unkAc, unkB0, unkB4, unkB8, unkBc;
    unsigned int unkC0, unkC4, unkC8, unkCc, unkD0;
    unsigned int key;
};
struct CompareReference
{
    CompareValue* value;
};
struct CompareObject
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44;
    CompareReference* reference;
};
void __cdecl CompareObjectKeys(bool* result, CompareObject* left, CompareObject* right);
struct Registry
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
};
struct World
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
    Registry* registry;
};
struct Reserve
{
    void hkpBroadPhase_enableMultiThreading(int);
};
struct Owner
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
    Reserve* reserve;
};
struct FUN_00d0d020
{
    virtual void method0();
    int unk04, unk08;
    Owner* volatile owner;
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
    __declspec(nothrow) FUN_00d0d020(World*);
};
struct ListenerA
{
    virtual void method0();
    void* context;
    ListenerA() : context(0)
    {}
};
struct ListenerB
{
    virtual void method0();
    void* context;
    ListenerB() : context(0)
    {}
};
struct ListenerC
{
    virtual void method0();
    void* context;
    ListenerC() : context(0)
    {}
};
struct Array
{
    void* data;
    int count;
    unsigned capacity;
    Array() : data(0), count(0), capacity(0x80000000)
    {}
};
struct FUN_00cf6da0
{
    int debugInfo, lockCount, recursionCount;
    void* owningThread;
    void* semaphore;
    unsigned spinCount;
    __declspec(nothrow) FUN_00cf6da0(int);
};
struct FUN_00c90f30
{
    int value;
    __declspec(nothrow) FUN_00c90f30();
};
struct FUN_00d02c80 : FUN_00d0d020
{
    virtual void method0();
    ListenerA a;
    ListenerB b;
    ListenerC c;
    volatile bool enabled;
    Array first;
    FUN_00cf6da0 firstLock;
    Array second;
    FUN_00cf6da0 secondLock;
    FUN_00c90f30 counter;
    int unkB8, unkBC;
    volatile int active;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    FUN_00cf6da0 queueLock;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    FUN_00cf6da0 workLock;
    FUN_00d02c80(World*);
};
// FUN_00d01fc0  (0x00d01fc0, 89 bytes)
//
// The function takes a pair of "handle" pointers.  Each handle is a small
// header (a dword, a one byte type tag at +4 and a signed byte offset at +5)
// that points at a sub node; the sub node carries a second signed byte offset
// at +0x10 that leads to the polymorphic object.
//
// For each of the two handles the type tag is tested against 2.  When the
// first handle has that type the object behind it is asked to process the
// second handle (as a real call), and when the second handle has that type
// the object behind it is asked to process the first handle (as a tail call
// that forwards its argument in place).
//
// The object is reached through the virtual at vtable offset 0x1c (the eighth
// virtual of the class).
// A handle header: the type tag sits at +4, the offset to the sub node at +5.
struct Handle
{
    int unk00;           // +0
    unsigned char type;  // +4  the type tag
    signed char off;     // +5  byte offset of the sub node
};
// The pair of handles the function works on.
struct HandlePair
{
    Handle* first;   // +0
    Handle* second;  // +4
};
// The polymorphic object the handles lead to.  The interesting virtual is the
// eighth one, i.e. the one at vtable offset 0x1c.
struct HandleTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(Handle* other);
};
// The sub node: a byte offset at +0x10 that leads to the polymorphic object.
struct SubNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char off10;  // +0x10  byte offset of the polymorphic object
};
void __stdcall hkpMultiThreadedSimulation_MtPhantomBroadPhaseListener_addCollisionPair(HandlePair* pHandlePair);
bool pairLessThan(int* apPairA, int* apPairB);
struct PairEntry
{
    int first;
    int second;
};
struct PairArray
{
    PairEntry* m_data;
    int m_iElementCount;
    unsigned int m_pRayCursor;
};
char* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, PairArray* arr, int elemSize);
void __cdecl hkpWorldAgentUtil_addAgent(char* a, char* b, char* c);
struct FUN_00d026e0_cls
{
    int unk00;
    char* m_04;
    void ProcessPair(int* pr);
};
struct SortPair8
{
    int m_key;
    int m_uiFilterValue;
};
typedef bool(__cdecl* SortPairLess)(const SortPair8* lhs, const SortPair8* rhs);
void __cdecl QuickSortPairs(SortPair8* apPairs, int lo, int hi, SortPairLess apLess);
void __stdcall hkpMultiThreadedSimulation_MtBroadPhaseBorderListener_removeCollisionPair(S_00d02020_Pair* pair);
void __stdcall hkpMultiThreadedSimulation_61(int);
void __stdcall hkpMultiThreadedSimulation_assertThereIsNoCollisionInformationForEntities(int, int, int);
struct OwnerD020;
class PhantomD020
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(OwnerD020* pkOther);
};
struct OwnerD020
{
    char unk00[0x10];
    signed char m_cPhantomOffset;

    PhantomD020* GetPhantom()
    {
        return (PhantomD020*)((char*)this + m_cPhantomOffset);
    }
};
struct CollidableD020
{
    int unk00;
    char m_cType;
    signed char m_cOwnerOffset;

    OwnerD020* GetOwner()
    {
        return (OwnerD020*)((char*)this + m_cOwnerOffset);
    }
};
// Two broad-phase collision-handle pointers; shared Pair stores two integer values.
struct BroadPhaseHandlePair
{
    CollidableD020* m_pkA;
    CollidableD020* m_pkB;
};
void __stdcall NotifyPhantomCollision(BroadPhaseHandlePair* pkPair);
inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
struct GroupIdentity
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short count;
};
// Exe 0x00d022b0: unit-local Vector4f view; declarations and layout are preserved.
struct HkpmultithreadedsimulationVector4fView
{
    int x, y, z, w;
};
struct __declspec(align(16)) CollisionInput
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    HkpmultithreadedsimulationVector4fView unk20, unk30, unk40;
    int unk50, unk54, unk58, unk5C, unk60;
    void* scratch;
    int unk68, unk6C, unk70, unk74, unk78, unk7C;
    void FUN_00cfa7d0(const CollisionInput*);
};
struct __declspec(align(16)) SolverContext
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    void hkpConstraintQueryIn_set(void*, void*, int);
};
struct PhysicsOwner
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    GroupIdentity* unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    CollisionInput* input;
    int unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4;
    int batchSize;
    int threshold;
    int unkF0, unkF4, unkF8, unkFC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0;
};
struct JobByte
{
    unsigned char value;
    __forceinline JobByte(int v) : value((unsigned char)v)
    {}
    __forceinline JobByte& operator=(int v)
    {
        value = (unsigned char)v;
        return *this;
    }
};
struct JobHeader
{
    JobByte type;
    JobByte subtype;
    JobByte spu;
    unsigned char unk03;
    unsigned short size;
    short thread;
    unsigned short unk08, unk0A, unk0C, unk0E;
    __forceinline JobHeader(unsigned char t, unsigned char st, unsigned short sz, unsigned char sp)
        : type(t), subtype(st), spu(sp)
    {
        size = sz;
        thread = -1;
    }
};
struct JobBase : JobHeader
{
    unsigned short count, unk12;
    GroupIdentity* unk14;
    int unk18, header;
    __forceinline JobBase(unsigned char t, unsigned char st, unsigned short sz, unsigned char sp)
        : JobHeader(t, st, sz, sp)
    {
        count = 0xffff;
        unk14 = 0;
        unk18 = 0;
    }
};
struct TaskInput
{
    int unk00, unk04, unk08, unk0C;
    void* unk10;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    HkpmultithreadedsimulationVector4fView step;
};
struct __declspec(align(16)) BuildJob : JobBase
{
    void* results;
    unsigned short unk24, unk26, numItems, batch;
    int** items;
    HkpmultithreadedsimulationVector4fView step;
    unsigned char flag;
    __forceinline BuildJob(int** p, int n, TaskInput* input, int b, hkBool f) : JobBase(15, 0, 80, 1)
    {
        step = input->step;
        count = 0;
        unk24 = 0;
        results = 0;
        items = p;
        numItems = (unsigned short)n;
        batch = (unsigned short)b;
        subtype = 1;
        flag = f.m_cBooleanValue;
    }
};
struct __declspec(align(16)) ResultJob : JobHeader
{
    unsigned short count, unk12;
    GroupIdentity* group;
    int unk18, header;
    void* results;
    int unk24, unk28, unk2C;
    __forceinline ResultJob(BuildJob* j) : JobHeader(14, 0, 48, 2)
    {
        count = j->count;
        group = j->unk14;
        unk18 = j->unk18;
        header = j->header;
        count = j->count;
        results = j->results;
    }
};
struct JobQueue
{
    void AddObjectCopy(BuildJob*, int);
    void hkJobQueue_processAllJobs();
};
struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void freeBlock(void*, int);
};
struct ThreadState
{
    char* top;
    int unk04, unk08, unk0C;
    Allocator* allocator;
    __forceinline Allocator& heap()
    {
        return *allocator;
    }
};
void* __cdecl AllocateBlockHeader(int, int);
extern int DAT_01269210;
struct Processor;
struct __declspec(align(16)) ProcessingContext
{
    PhysicsOwner* owner;
    int unk04, unk08, unk0C;
    SolverContext solver;
    CollisionInput input;
    Processor* processor;
    void* step;
    float delta;
    int* shared;
};
void __cdecl AccumulateShapes(ProcessingContext*, JobQueue*, ResultJob*);
struct Processor
{
    int unk00, unk04, unk08;
    PhysicsOwner* owner;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    JobQueue* active;

    void ProcessGroups(int**, int, struct Group*, int, TaskInput*, hkBool);
    void hkpContinuousSimulation_processAgentNnEntries(int**, int, TaskInput*, GroupIdentity*, hkBool);
};
struct Group
{
    GroupIdentity* id;
    int count, start, unk0C;
    BuildJob* job;
    int unk14;
};
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize);
extern "C" void __cdecl hkString_memSet(void* p, int v, int n);
__forceinline hkMemoryRouterQ_hkpmultithreadedsimulation_rtm_variant& getRouter()
{
    return *(hkMemoryRouterQ_hkpmultithreadedsimulation_rtm_variant*)hkMemoryRouter_getInstance();
}
#include "../../../../../../../include/hkArray.h"
// The function's local arrays are released by explicit calls (no destructor, no EH state), so they are hkArrayBase
// with hkArray's pushBack / clearAndDeallocate (hkArray.inl bodies, through the router's stream heap) as members.
template <class T> struct StreamHeapArrayQ : hkArrayBase<T>
{
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(this->m_data, this->getCapacity() * sizeof(T));
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }
    __forceinline void ClearAndRelease()
    {
        _clearAndDeallocate(*getRouter().m_pStreamAllocator);
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, const T& t)
    {
        if (this->m_iElementCount == this->getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        this->m_data[this->m_iElementCount++] = t;
    }
    __forceinline void AddBack(const T& t)
    {
        _pushBack(*getRouter().m_pStreamAllocator, t);
    }
    __forceinline hkArray<T>& array() { return static_cast<hkArray<T>&>(static_cast<hkArrayBase<T>&>(*this)); }
};
template <class T> __forceinline T* hkAllocateStackQ(int n)
{
    char*& stackTop = reinterpret_cast<char*&>(getRouter().unk00);
    char* p = stackTop;
    stackTop = p + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)p;
}
template <class T> __forceinline void hkDeallocateStackQ(T* p)
{
    reinterpret_cast<char*&>(getRouter().unk00) = (char*)p;
}
template <class T> struct hkLocalArrayQ : StreamHeapArrayQ<T>
{
    T* m_pStackAllocation;

    __forceinline hkLocalArrayQ(int n)
    {
        this->m_data = hkAllocateStackQ<T>(n);
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline void release()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackQ(m_pStackAllocation);
        this->ClearAndRelease();
    }
};
struct AgentTableEntryQ
{
    void* m_func;
    bool m_bIsPredictive;
    char pad05;
    short pad06;
    int pad08[14];
};
struct DispatcherQ
{
    int unk00[0x1c30 / 4];
    AgentTableEntryQ m_kAgent3FunctionTable[32];
};
struct WorldQ
{
    int unk00[0x20];
    DispatcherQ* m_pDispatcher;
};
struct AgentEntryQ
{
    int unk00;
    int unk04;
    int unk08;
    signed char m_ucNnTrackType;
};
struct SimulationIslandQ;
struct CollidableQ;
struct CollisionEntryQ
{
    AgentEntryQ* m_pAgentEntry;
    CollidableQ* m_pCollidable;
};
struct EntityQ;
struct CollidableQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    __forceinline EntityQ* getOwner()
    {
        return (EntityQ*)((char*)this + m_iOwnerOffset);
    }
};
struct LinkedCollidableQ
{
    void CopyAndSortGeometryList(hkArray<CollisionEntryQ>& entries);
};
struct EntityQ
{
    int unk00[4];
    LinkedCollidableQ m_kCollidable;
    int unk14[0x25];
    unsigned short m_usStorageIndex;
    short unkaa;
    int unkac[8];
    SimulationIslandQ* m_pSimulationIsland;
    int unkd0;
    int m_d4;
    void FUN_00c90510();
};
struct SimulationIslandQ
{
    int unk00[0x13];
    int m_iActorEntryCount;
};
struct InputQ
{
    int LookupHashEntry(int key, int flag);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator* heap, int key, EntityQ* entity);
};
struct CollideSimQ
{
    int unk00;
    int unk04;
    int unk08;
    WorldQ* m_pOwningWorld;
    int unk10[0xb];
    int m_3c;
    int unk40[0x20];
    int m_c0;
    void hkpContinuousSimulation_collideEntitiesOfOneIslandNarrowPhaseContinuous_toiOnly(EntityQ** entities, int numEntities, void* input, int* out);
    void hkpMultiThreadedSimulation_processAgentNnEntries(AgentEntryQ** entries, int numEntries, void* input, SimulationIslandQ* island, hkBool flag);
    void ProcessCollisionEntries(EntityQ** entities, int numEntities, void* input, InputQ* collInput) throw();
};
extern "C" void _ReadWriteBarrier(void);
struct S00d02880_Elem
{
    int key;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct S00d02880_Heap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
};
struct S00d02880_Arr
{
    S00d02880_Elem* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};
static inline void S00d02880_Zero(S00d02880_Elem* p)
{
    if (p)
    {
        p->key = 0;
        p->unk04 = 0;
        p->unk08 = 0;
        p->unk0c = 0;
        p->unk10 = 0;
        p->unk14 = 0;
    }
}
struct S00d02880_Key
{
    int v;
};
static S00d02880_Elem* getIslandEntriesInfo(S00d02880_Arr* b, S00d02880_Key t);
S00d02880_Elem* S00d02880_Call(S00d02880_Arr* a, S00d02880_Key key);
#include <windows.h>
#include <xmmintrin.h>
extern unsigned int DAT_0126835c;
struct TraceRecord
{
    const char* name;
    unsigned int counter;
    unsigned int unk08;
};
struct TraceBuffer
{
    int unk00;
    TraceRecord* next;
    int unk08;
    TraceRecord* end;
};
static __forceinline void WriteTrace(const char* name)
{
    TraceBuffer* trace = static_cast<TraceBuffer*>(TlsGetValue(DAT_0126835c));
    if (trace->next < trace->end)
    {
        TraceRecord* record = trace->next;
        record->name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = static_cast<unsigned int>(__rdtsc());
        record->counter = t;
        trace->next = record + 1;
    }
}
struct Logger
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void Log(int level, unsigned int code, void* text, const char* file, int line);
};
extern Logger* DAT_01268360;
struct MessageBuilder
{
    char* buffer;
    unsigned int capacity;
    char* cursor;
    __declspec(nothrow) MessageBuilder(char* buffer, unsigned int capacity);
    void ProcessAndReturnValue_00cc01c0(const char* text);
    void FUN_00cc00e0();
};
struct ObjectLink
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
    char* subTable80;
};
struct Event
{
    float x;
    float y;
    unsigned char kind;
    unsigned char flags;
    short unk0a;
    void* ptr0c;
    void* ptr10;
    int count14;
    float u;
    float v;
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
    __m128 mat50;
    __m128 mat60;
};
struct EventMeta
{
    int unk00;
    int unk04;
    int resource08;
    signed char unk0c;
    char unk0d;
    char unk0e;
    char unk0f;
    char* begin10;
    char* begin14;
};
struct FUN_00d02e70_cls
{
    int unk00;
    int unk04;
    int unk08;
    ObjectLink* owner0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Event* items30;
    int count34;
    unsigned int capacity38;
    void AddToiEvent(char* input, EventMeta* meta, CRITICAL_SECTION* cs);
};
template <class T> __forceinline void exchangePairField(T& a, T& b)
{
    T old = a;
    a = b;
    b = old;
}
struct PairKeyOwner
{
    int unk00, unk04, unk08, unk0c, unk10;
    int key;
};
struct PairStorage
{
    Handle* first;
    Handle* second;
};
struct TypedPair : PairStorage
{
    __forceinline Handle* left() const
    {
        return first;
    }
    __forceinline Handle* right() const
    {
        return second;
    }
};
template <class T> struct PairListBase
{
    T* data;
    int count;
    int capacity;
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline T* end()
    {
        return data + count;
    }
    __forceinline int size() const
    {
        return count;
    }
};
template <class T> struct PairList : PairListBase<T>
{
};
static __forceinline int pairKey(Handle* h)
{
    return ((PairKeyOwner*)((char*)h + h->off))->key;
}
template <class T, class L> inline void sortPairs(T* data, int count, L less)
{
    if (count > 1)
    {
        int lo = 0;
        int hi = count - 1;
        QuickSortPairs((SortPair8*)data, lo, hi, (SortPairLess)less);
    }
}
void __cdecl sortPairList(PairList<TypedPair>& list);
extern int DAT_01269200;
extern const float DAT_0104da48 = 3.402820018375656e+38f;
struct ProfileNamedRecord : TraceRecord
{
    const char* sub;
};
struct RuntimeBase
{

    virtual ~RuntimeBase();
    virtual const void* classInfo() const;
    virtual void memoryStats(void*, const void*) const;

    unsigned short allocationFlags;
    short referenceCount;
};
struct Job
{
    int hkJobQueue_getMasterThreadFinishingFlags();
    void SetSimulationEnabled(int);
    void SetValue(int);
};
struct Jobs : RuntimeBase
{
    virtual void start(Job*, int);
    virtual void wait();
};
struct Entity;
struct Body;
struct Agent;
struct Dispatcher;
struct Constraint;
struct PendingConstraints
{
    int count;
    Constraint* entries[128];
};
struct Island
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short storageIndex, dirtyIndex;
};
struct __declspec(align(16)) ContactGeometry
{
    float position[4];
    float normal[4];
};
struct Contact
{
    ContactGeometry geometry;
    int contactId;
};
struct __declspec(align(16)) ToiCache
{
    unsigned short vertex0, vertex1, vertex2, vertex3;
    unsigned char dimA, dimB, maxDimA, maxDimB, flags;
};
struct SolverAmounts
{
    float impulse, velocity;
    __forceinline SolverAmounts() : impulse(0.0f), velocity(0.0f)
    {}
};
struct ContactMaterial
{
    unsigned userData;
    unsigned char friction, restitution, maxImpulse, flags;
};
struct ContactProperties : SolverAmounts, ContactMaterial
{
    float internal;
};
struct __declspec(align(16)) ExtendedProperties : ContactProperties
{
    unsigned userDataExt[7];
};
struct ToiResult
{

    ContactGeometry geometry;

    float time, velocity;

    ToiCache cache;

    ExtendedProperties properties;

    __forceinline ToiResult() : time(DAT_0104da48)
    {}
};
struct OutputBase
{

    Contact* firstFree;
    Island* island;

    Contact contacts[256];

    ToiResult toi;

    __forceinline OutputBase(Island* owner) : island(owner)
    {}

    __forceinline bool empty() const
    {
        return firstFree == contacts;
    }

    __forceinline bool hasToi() const
    {
        return toi.time != 3.402820018375656e+38;
    }
};
struct Output : OutputBase
{

    void* potential;

    __forceinline Output(Island* owner) : OutputBase(owner)
    {}

    __forceinline void reset()
    {
        firstFree = contacts;
        toi.time = DAT_0104da48;
        potential = 0;
    }
};
struct Manager : RuntimeBase
{
    virtual void SetContactPair();
    virtual void reserveContacts();
    virtual void removeContact();
    virtual void process(const Body&, const Body&, const Dispatcher&, OutputBase&);
};
struct Agent
{
    int f00, f04;
    Manager* manager;
    signed char kind;
    char flagD, flagE, flagF;
    Body* dataA;
    Body* dataB;
};
struct Body
{
    int f00, f04, f08, f0c;
    signed char ownerOffset;
    char p11, p12, p13;
    int f14;
    short f18;
    signed char type;
    char flag1b;
};
struct Entity
{

    int f000;

    int f004;

    int f008;

    int f00c;

    int f010;

    int f014;

    int f018;

    int f01c;

    unsigned short index20, unk22;

    int f024;

    int f028;

    int f02c;

    int f030;

    int f034;

    int f038;

    int f03c;

    int f040;

    int f044;

    int f048;

    int f04c;

    int f050;

    int f054;

    int f058;

    int f05c;

    int f060;

    int f064;

    int f068;

    int f06c;

    int f070;

    int f074;

    int f078;

    int f07c;

    int f080;

    int f084;

    int f088;

    int f08c;

    int f090;

    int f094;

    int f098;

    char f09c, f09d, f09e, f09f;

    int f0a0;

    int f0a4;

    int f0a8;

    int f0ac;

    int f0b0;

    int f0b4;

    int f0b8;

    int f0bc;

    int f0c0;

    int f0c4;

    int f0c8;

    Island* f0cc;
};
struct Quality
{

    int f00;

    int f04;

    int f08;

    int f0c;

    int f10;

    int f14;

    int f18;

    int f1c;

    int f20;

    int f24;

    int f28;

    int f2c;

    int f30;

    int f34;

    int f38;

    int f3c;
};
struct Config
{

    int f0000, f0004, f0008, f000c, f0010, f0014, f0018, f001c;

    int f0020, f0024, f0028, f002c, f0030, f0034, f0038, f003c;

    int f0040, f0044, f0048, f004c, f0050, f0054, f0058, f005c;

    int f0060, f0064, f0068, f006c, f0070, f0074, f0078, f007c;

    int f0080, f0084, f0088, f008c, f0090, f0094, f0098, f009c;

    int f00a0, f00a4, f00a8, f00ac, f00b0, f00b4, f00b8, f00bc;

    int f00c0, f00c4, f00c8, f00cc, f00d0, f00d4, f00d8, f00dc;

    int f00e0, f00e4, f00e8, f00ec, f00f0, f00f4, f00f8, f00fc;

    int f0100, f0104, f0108, f010c, f0110, f0114, f0118, f011c;

    int f0120, f0124, f0128, f012c, f0130, f0134, f0138, f013c;

    int f0140, f0144, f0148, f014c, f0150, f0154, f0158, f015c;

    int f0160, f0164, f0168, f016c, f0170, f0174, f0178, f017c;

    int f0180, f0184, f0188, f018c, f0190, f0194, f0198, f019c;

    int f01a0, f01a4, f01a8, f01ac, f01b0, f01b4, f01b8, f01bc;

    int f01c0, f01c4, f01c8, f01cc, f01d0, f01d4, f01d8, f01dc;

    int f01e0, f01e4, f01e8, f01ec, f01f0, f01f4, f01f8, f01fc;

    int f0200, f0204, f0208, f020c, f0210, f0214, f0218, f021c;

    int f0220, f0224, f0228, f022c, f0230, f0234, f0238, f023c;

    int f0240, f0244, f0248, f024c, f0250, f0254, f0258, f025c;

    int f0260, f0264, f0268, f026c, f0270, f0274, f0278, f027c;

    int f0280, f0284, f0288, f028c, f0290, f0294, f0298, f029c;

    int f02a0, f02a4, f02a8, f02ac, f02b0, f02b4, f02b8, f02bc;

    int f02c0, f02c4, f02c8, f02cc, f02d0, f02d4, f02d8, f02dc;

    int f02e0, f02e4, f02e8, f02ec, f02f0, f02f4, f02f8, f02fc;

    int f0300, f0304, f0308, f030c, f0310, f0314, f0318, f031c;

    int f0320, f0324, f0328, f032c, f0330, f0334, f0338, f033c;

    int f0340, f0344, f0348, f034c, f0350, f0354, f0358, f035c;

    int f0360, f0364, f0368, f036c, f0370, f0374, f0378, f037c;

    int f0380, f0384, f0388, f038c, f0390, f0394, f0398, f039c;

    int f03a0, f03a4, f03a8, f03ac, f03b0, f03b4, f03b8, f03bc;

    int f03c0, f03c4, f03c8, f03cc, f03d0, f03d4, f03d8, f03dc;

    int f03e0, f03e4, f03e8, f03ec, f03f0, f03f4, f03f8, f03fc;

    int f0400, f0404, f0408, f040c, f0410, f0414, f0418, f041c;

    int f0420, f0424, f0428, f042c, f0430, f0434, f0438, f043c;

    int f0440, f0444, f0448, f044c, f0450, f0454, f0458, f045c;

    int f0460, f0464, f0468, f046c, f0470, f0474, f0478, f047c;

    int f0480, f0484, f0488, f048c, f0490, f0494, f0498, f049c;

    int f04a0, f04a4, f04a8, f04ac, f04b0, f04b4, f04b8, f04bc;

    int f04c0, f04c4, f04c8, f04cc, f04d0, f04d4, f04d8, f04dc;

    int f04e0, f04e4, f04e8, f04ec, f04f0, f04f4, f04f8, f04fc;

    int f0500, f0504, f0508, f050c, f0510, f0514, f0518, f051c;

    int f0520, f0524, f0528, f052c, f0530, f0534, f0538, f053c;

    int f0540, f0544, f0548, f054c, f0550, f0554, f0558, f055c;

    int f0560, f0564, f0568, f056c, f0570, f0574, f0578, f057c;

    int f0580, f0584, f0588, f058c, f0590, f0594, f0598, f059c;

    int f05a0, f05a4, f05a8, f05ac, f05b0, f05b4, f05b8, f05bc;

    int f05c0, f05c4, f05c8, f05cc, f05d0, f05d4, f05d8, f05dc;

    int f05e0, f05e4, f05e8, f05ec, f05f0, f05f4, f05f8, f05fc;

    int f0600, f0604, f0608, f060c, f0610, f0614, f0618, f061c;

    int f0620, f0624, f0628, f062c, f0630, f0634, f0638, f063c;

    int f0640, f0644, f0648, f064c, f0650, f0654, f0658, f065c;

    int f0660, f0664, f0668, f066c, f0670, f0674, f0678, f067c;

    int f0680, f0684, f0688, f068c, f0690, f0694, f0698, f069c;

    int f06a0, f06a4, f06a8, f06ac, f06b0, f06b4, f06b8, f06bc;

    int f06c0, f06c4, f06c8, f06cc, f06d0, f06d4, f06d8, f06dc;

    int f06e0, f06e4, f06e8, f06ec, f06f0, f06f4, f06f8, f06fc;

    int f0700, f0704, f0708, f070c, f0710, f0714, f0718, f071c;

    int f0720, f0724, f0728, f072c, f0730, f0734, f0738, f073c;

    int f0740, f0744, f0748, f074c, f0750, f0754, f0758, f075c;

    int f0760, f0764, f0768, f076c, f0770, f0774, f0778, f077c;

    int f0780, f0784, f0788, f078c, f0790, f0794, f0798, f079c;

    int f07a0, f07a4, f07a8, f07ac, f07b0, f07b4, f07b8, f07bc;

    int f07c0, f07c4, f07c8, f07cc, f07d0, f07d4, f07d8, f07dc;

    int f07e0, f07e4, f07e8, f07ec, f07f0, f07f4, f07f8, f07fc;

    int f0800, f0804, f0808, f080c, f0810, f0814, f0818, f081c;

    int f0820, f0824, f0828, f082c, f0830, f0834, f0838, f083c;

    int f0840, f0844, f0848, f084c, f0850, f0854, f0858, f085c;

    int f0860, f0864, f0868, f086c, f0870, f0874, f0878, f087c;

    int f0880, f0884, f0888, f088c, f0890, f0894, f0898, f089c;

    int f08a0, f08a4, f08a8, f08ac, f08b0, f08b4, f08b8, f08bc;

    int f08c0, f08c4, f08c8, f08cc, f08d0, f08d4, f08d8, f08dc;

    int f08e0, f08e4, f08e8, f08ec, f08f0, f08f4, f08f8, f08fc;

    int f0900, f0904, f0908, f090c, f0910, f0914, f0918, f091c;

    int f0920, f0924, f0928, f092c, f0930, f0934, f0938, f093c;

    int f0940, f0944, f0948, f094c, f0950, f0954, f0958, f095c;

    int f0960, f0964, f0968, f096c, f0970, f0974, f0978, f097c;

    int f0980, f0984, f0988, f098c, f0990, f0994, f0998, f099c;

    int f09a0, f09a4, f09a8, f09ac, f09b0, f09b4, f09b8, f09bc;

    int f09c0, f09c4, f09c8, f09cc, f09d0, f09d4, f09d8, f09dc;

    int f09e0, f09e4, f09e8, f09ec, f09f0, f09f4, f09f8, f09fc;

    int f0a00, f0a04, f0a08, f0a0c, f0a10, f0a14, f0a18, f0a1c;

    int f0a20, f0a24, f0a28, f0a2c, f0a30, f0a34, f0a38, f0a3c;

    int f0a40, f0a44, f0a48, f0a4c, f0a50, f0a54, f0a58, f0a5c;

    int f0a60, f0a64, f0a68, f0a6c, f0a70, f0a74, f0a78, f0a7c;

    int f0a80, f0a84, f0a88, f0a8c, f0a90, f0a94, f0a98, f0a9c;

    int f0aa0, f0aa4, f0aa8, f0aac, f0ab0, f0ab4, f0ab8, f0abc;

    int f0ac0, f0ac4, f0ac8, f0acc, f0ad0, f0ad4, f0ad8, f0adc;

    int f0ae0, f0ae4, f0ae8, f0aec, f0af0, f0af4, f0af8, f0afc;

    int f0b00, f0b04, f0b08, f0b0c, f0b10, f0b14, f0b18, f0b1c;

    int f0b20, f0b24, f0b28, f0b2c, f0b30, f0b34, f0b38, f0b3c;

    int f0b40, f0b44, f0b48, f0b4c, f0b50, f0b54, f0b58, f0b5c;

    int f0b60, f0b64, f0b68, f0b6c, f0b70, f0b74, f0b78, f0b7c;

    int f0b80, f0b84, f0b88, f0b8c, f0b90, f0b94, f0b98, f0b9c;

    int f0ba0, f0ba4, f0ba8, f0bac, f0bb0, f0bb4, f0bb8, f0bbc;

    int f0bc0, f0bc4, f0bc8, f0bcc, f0bd0, f0bd4, f0bd8, f0bdc;

    int f0be0, f0be4, f0be8, f0bec, f0bf0, f0bf4, f0bf8, f0bfc;

    int f0c00, f0c04, f0c08, f0c0c, f0c10, f0c14, f0c18, f0c1c;

    int f0c20, f0c24, f0c28, f0c2c, f0c30, f0c34, f0c38, f0c3c;

    int f0c40, f0c44, f0c48, f0c4c, f0c50, f0c54, f0c58, f0c5c;

    int f0c60, f0c64, f0c68, f0c6c, f0c70, f0c74, f0c78, f0c7c;

    int f0c80, f0c84, f0c88, f0c8c, f0c90, f0c94, f0c98, f0c9c;

    int f0ca0, f0ca4, f0ca8, f0cac, f0cb0, f0cb4, f0cb8, f0cbc;

    int f0cc0, f0cc4, f0cc8, f0ccc, f0cd0, f0cd4, f0cd8, f0cdc;

    int f0ce0, f0ce4, f0ce8, f0cec, f0cf0, f0cf4, f0cf8, f0cfc;

    int f0d00, f0d04, f0d08, f0d0c, f0d10, f0d14, f0d18, f0d1c;

    int f0d20, f0d24, f0d28, f0d2c, f0d30, f0d34, f0d38, f0d3c;

    int f0d40, f0d44, f0d48, f0d4c, f0d50, f0d54, f0d58, f0d5c;

    int f0d60, f0d64, f0d68, f0d6c, f0d70, f0d74, f0d78, f0d7c;

    int f0d80, f0d84, f0d88, f0d8c, f0d90, f0d94, f0d98, f0d9c;

    int f0da0, f0da4, f0da8, f0dac, f0db0, f0db4, f0db8, f0dbc;

    int f0dc0, f0dc4, f0dc8, f0dcc, f0dd0, f0dd4, f0dd8, f0ddc;

    int f0de0, f0de4, f0de8, f0dec, f0df0, f0df4, f0df8, f0dfc;

    int f0e00, f0e04, f0e08, f0e0c, f0e10, f0e14, f0e18, f0e1c;

    int f0e20, f0e24, f0e28, f0e2c, f0e30, f0e34, f0e38, f0e3c;

    int f0e40, f0e44, f0e48, f0e4c, f0e50, f0e54, f0e58, f0e5c;

    int f0e60, f0e64, f0e68, f0e6c, f0e70, f0e74, f0e78, f0e7c;

    int f0e80, f0e84, f0e88, f0e8c, f0e90, f0e94, f0e98, f0e9c;

    int f0ea0, f0ea4, f0ea8, f0eac, f0eb0, f0eb4, f0eb8, f0ebc;

    int f0ec0, f0ec4, f0ec8, f0ecc, f0ed0, f0ed4, f0ed8, f0edc;

    int f0ee0, f0ee4, f0ee8, f0eec, f0ef0, f0ef4, f0ef8, f0efc;

    int f0f00, f0f04, f0f08, f0f0c, f0f10, f0f14, f0f18, f0f1c;

    int f0f20, f0f24, f0f28, f0f2c, f0f30, f0f34, f0f38, f0f3c;

    int f0f40, f0f44, f0f48, f0f4c, f0f50, f0f54, f0f58, f0f5c;

    int f0f60, f0f64, f0f68, f0f6c, f0f70, f0f74, f0f78, f0f7c;

    int f0f80, f0f84, f0f88, f0f8c, f0f90, f0f94, f0f98, f0f9c;

    int f0fa0, f0fa4, f0fa8, f0fac, f0fb0, f0fb4, f0fb8, f0fbc;

    int f0fc0, f0fc4, f0fc8, f0fcc, f0fd0, f0fd4, f0fd8, f0fdc;

    int f0fe0, f0fe4, f0fe8, f0fec, f0ff0, f0ff4, f0ff8, f0ffc;

    int f1000, f1004, f1008, f100c, f1010, f1014, f1018, f101c;

    int f1020, f1024, f1028, f102c, f1030, f1034, f1038, f103c;

    int f1040, f1044, f1048, f104c, f1050, f1054, f1058, f105c;

    int f1060, f1064, f1068, f106c, f1070, f1074, f1078, f107c;

    int f1080, f1084, f1088, f108c, f1090, f1094, f1098, f109c;

    int f10a0, f10a4, f10a8, f10ac, f10b0, f10b4, f10b8, f10bc;

    int f10c0, f10c4, f10c8, f10cc, f10d0, f10d4, f10d8, f10dc;

    int f10e0, f10e4, f10e8, f10ec, f10f0, f10f4, f10f8, f10fc;

    int f1100, f1104, f1108, f110c, f1110, f1114, f1118, f111c;

    int f1120, f1124, f1128, f112c, f1130, f1134, f1138, f113c;

    int f1140, f1144, f1148, f114c, f1150, f1154, f1158, f115c;

    int f1160, f1164, f1168, f116c, f1170, f1174, f1178, f117c;

    int f1180, f1184, f1188, f118c, f1190, f1194, f1198, f119c;

    int f11a0, f11a4, f11a8, f11ac, f11b0, f11b4, f11b8, f11bc;

    int f11c0, f11c4, f11c8, f11cc, f11d0, f11d4, f11d8, f11dc;

    int f11e0, f11e4, f11e8, f11ec, f11f0, f11f4, f11f8, f11fc;

    int f1200, f1204, f1208, f120c, f1210, f1214, f1218, f121c;

    int f1220, f1224, f1228, f122c, f1230, f1234, f1238, f123c;

    int f1240, f1244, f1248, f124c, f1250, f1254, f1258, f125c;

    int f1260, f1264, f1268, f126c, f1270, f1274, f1278, f127c;

    int f1280, f1284, f1288, f128c, f1290, f1294, f1298, f129c;

    int f12a0, f12a4, f12a8, f12ac, f12b0, f12b4, f12b8, f12bc;

    int f12c0, f12c4, f12c8, f12cc, f12d0, f12d4, f12d8, f12dc;

    int f12e0, f12e4, f12e8, f12ec, f12f0, f12f4, f12f8, f12fc;

    int f1300, f1304, f1308, f130c, f1310, f1314, f1318, f131c;

    int f1320, f1324, f1328, f132c, f1330, f1334, f1338, f133c;

    int f1340, f1344, f1348, f134c, f1350, f1354, f1358, f135c;

    int f1360, f1364, f1368, f136c, f1370, f1374, f1378, f137c;

    int f1380, f1384, f1388, f138c, f1390, f1394, f1398, f139c;

    int f13a0, f13a4, f13a8, f13ac, f13b0, f13b4, f13b8, f13bc;

    int f13c0, f13c4, f13c8, f13cc, f13d0, f13d4, f13d8, f13dc;

    int f13e0, f13e4, f13e8, f13ec, f13f0, f13f4, f13f8, f13fc;

    int f1400, f1404, f1408, f140c, f1410, f1414, f1418, f141c;

    int f1420, f1424, f1428, f142c, f1430, f1434, f1438, f143c;

    int f1440, f1444, f1448, f144c, f1450, f1454, f1458, f145c;

    int f1460, f1464, f1468, f146c, f1470, f1474, f1478, f147c;

    int f1480, f1484, f1488, f148c, f1490, f1494, f1498, f149c;

    int f14a0, f14a4, f14a8, f14ac, f14b0, f14b4, f14b8, f14bc;

    int f14c0, f14c4, f14c8, f14cc, f14d0, f14d4, f14d8, f14dc;

    int f14e0, f14e4, f14e8, f14ec, f14f0, f14f4, f14f8, f14fc;

    int f1500, f1504, f1508, f150c, f1510, f1514, f1518, f151c;

    int f1520, f1524, f1528, f152c, f1530, f1534, f1538, f153c;

    int f1540, f1544, f1548, f154c, f1550, f1554, f1558, f155c;

    int f1560, f1564, f1568, f156c, f1570, f1574, f1578, f157c;

    int f1580, f1584, f1588, f158c, f1590, f1594, f1598, f159c;

    int f15a0, f15a4, f15a8, f15ac, f15b0, f15b4, f15b8, f15bc;

    int f15c0, f15c4, f15c8, f15cc, f15d0, f15d4, f15d8, f15dc;

    int f15e0, f15e4, f15e8, f15ec, f15f0, f15f4, f15f8, f15fc;

    int f1600, f1604, f1608, f160c, f1610, f1614, f1618, f161c;

    int f1620, f1624, f1628, f162c, f1630, f1634, f1638, f163c;

    int f1640, f1644, f1648, f164c, f1650, f1654, f1658, f165c;

    int f1660, f1664, f1668, f166c, f1670, f1674, f1678, f167c;

    int f1680, f1684, f1688, f168c, f1690, f1694, f1698, f169c;

    int f16a0, f16a4, f16a8, f16ac, f16b0, f16b4, f16b8, f16bc;

    int f16c0, f16c4, f16c8, f16cc, f16d0, f16d4, f16d8, f16dc;

    int f16e0, f16e4, f16e8, f16ec, f16f0, f16f4, f16f8, f16fc;

    int f1700, f1704, f1708, f170c, f1710, f1714, f1718, f171c;

    int f1720, f1724, f1728, f172c, f1730, f1734, f1738, f173c;

    int f1740, f1744, f1748, f174c, f1750, f1754, f1758, f175c;

    int f1760, f1764, f1768, f176c, f1770, f1774, f1778, f177c;

    int f1780, f1784, f1788, f178c, f1790, f1794, f1798, f179c;

    int f17a0, f17a4, f17a8, f17ac, f17b0, f17b4, f17b8, f17bc;

    int f17c0, f17c4, f17c8, f17cc, f17d0, f17d4, f17d8, f17dc;

    int f17e0, f17e4, f17e8, f17ec, f17f0, f17f4, f17f8, f17fc;

    int f1800, f1804, f1808, f180c, f1810, f1814, f1818, f181c;

    int f1820, f1824, f1828, f182c, f1830, f1834, f1838, f183c;

    int f1840, f1844, f1848, f184c, f1850, f1854, f1858, f185c;

    int f1860, f1864, f1868, f186c, f1870, f1874, f1878, f187c;

    int f1880, f1884, f1888, f188c, f1890, f1894, f1898, f189c;

    int f18a0, f18a4, f18a8, f18ac, f18b0, f18b4, f18b8, f18bc;

    int f18c0, f18c4, f18c8, f18cc, f18d0, f18d4, f18d8, f18dc;

    int f18e0, f18e4, f18e8, f18ec, f18f0, f18f4, f18f8, f18fc;

    int f1900, f1904, f1908, f190c, f1910, f1914, f1918, f191c;

    int f1920, f1924, f1928, f192c, f1930, f1934, f1938, f193c;

    int f1940, f1944, f1948, f194c, f1950, f1954, f1958, f195c;

    int f1960, f1964, f1968, f196c, f1970, f1974, f1978, f197c;

    int f1980, f1984, f1988, f198c, f1990, f1994, f1998, f199c;

    int f19a0, f19a4, f19a8, f19ac, f19b0, f19b4, f19b8, f19bc;

    int f19c0, f19c4, f19c8, f19cc, f19d0, f19d4, f19d8, f19dc;

    int f19e0, f19e4, f19e8, f19ec, f19f0, f19f4, f19f8, f19fc;

    int f1a00, f1a04, f1a08, f1a0c, f1a10, f1a14, f1a18, f1a1c;

    int f1a20, f1a24, f1a28, f1a2c, f1a30, f1a34, f1a38, f1a3c;

    int f1a40, f1a44, f1a48, f1a4c, f1a50, f1a54, f1a58, f1a5c;

    int f1a60, f1a64, f1a68, f1a6c, f1a70, f1a74, f1a78, f1a7c;

    int f1a80, f1a84, f1a88, f1a8c, f1a90, f1a94, f1a98, f1a9c;

    int f1aa0, f1aa4, f1aa8, f1aac, f1ab0, f1ab4, f1ab8, f1abc;

    int f1ac0, f1ac4, f1ac8, f1acc, f1ad0, f1ad4, f1ad8, f1adc;

    int f1ae0, f1ae4, f1ae8, f1aec, f1af0, f1af4, f1af8, f1afc;

    int f1b00, f1b04, f1b08, f1b0c, f1b10, f1b14, f1b18, f1b1c;

    int f1b20, f1b24, f1b28, f1b2c, f1b30, f1b34, f1b38, f1b3c;

    int f1b40, f1b44, f1b48, f1b4c, f1b50, f1b54, f1b58, f1b5c;

    int f1b60, f1b64, f1b68, f1b6c, f1b70, f1b74, f1b78, f1b7c;

    int f1b80, f1b84, f1b88, f1b8c, f1b90, f1b94, f1b98, f1b9c;

    int f1ba0, f1ba4, f1ba8, f1bac;

    signed char collisionTable[100];

    int f1c14, f1c18, f1c1c;

    Quality qualities[10];
};
struct Dispatcher
{

    Config* f000;

    int f004;

    int f008;

    int f00c;

    int f010;

    int f014;

    int f018;

    int f01c;

    int f020;

    int f024;

    int f028;

    int f02c;

    int f030;

    int f034;

    int f038;

    int f03c;

    int f040;

    int f044;

    int f048;

    int f04c;

    int f050;

    int f054;

    int f058;

    int f05c;

    Quality* f060;
};
struct StepWorld
{

    int f000;

    int f004;

    int f008;

    int f00c;

    int f010;

    int f014;

    int f018;

    int f01c;

    int f020;

    int f024;

    Island** f028;

    int f02c;

    int f030;

    int f034;

    int f038;

    int f03c;

    int f040;

    int f044;

    int f048;

    int f04c;

    int f050;

    int f054;

    int f058;

    int f05c;

    int f060;

    int f064;

    int f068;

    int f06c;

    int f070;

    int f074;

    Dispatcher* f078;

    int f07c;

    int f080;

    int f084;

    int f088;

    int f08c;

    int f090;

    int f094;

    int f098;

    char f09c, f09d, f09e, f09f;

    int f0a0;

    int f0a4;

    int f0a8;

    int f0ac;

    int f0b0;

    int f0b4;

    int f0b8;

    int f0bc;

    int f0c0;

    int f0c4;

    int f0c8;

    int f0cc;

    int f0d0;

    int f0d4;

    int f0d8;

    int f0dc;

    int f0e0;

    char f0e4, f0e5, f0e6, f0e7;

    int f0e8;

    int f0ec;

    int f0f0;

    int f0f4;

    int f0f8;

    int f0fc;

    int f100;

    int f104;

    int f108;

    int f10c;

    int f110;

    int f114;

    int f118;

    int f11c;

    int f120;

    int f124;

    int f128;

    int f12c;

    int f130;

    int f134;

    int f138;

    int f13c;

    int f140;

    int f144;

    int f148;

    int f14c;

    int f150;

    int f154;

    int f158;

    int f15c;

    int f160;

    int f164;

    int f168;

    int f16c;

    int f170;

    int f174;

    int f178;

    int f17c;

    int f180;

    int f184;

    int f188;

    int f18c;

    int f190;

    int f194;

    int f198;

    int f19c;

    int f1a0;

    int f1a4;

    int f1a8;

    int f1ac;

    int f1b0;

    int f1b4;

    PendingConstraints* f1b8;

    void IncrementCounter();
    void nullsub_6();
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void hkpWorld_unlock();
    int hkpWorld_getMemoryWatchDog();
};
struct TimeInfo
{
    float start, end, delta, inverse;
};
struct StepPair
{
    Handle* first;
    Handle* second;
};
void __cdecl hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(Island**, int, int, void(__cdecl*)(bool*, CompareObject*, CompareObject*));
void __cdecl hkpTypedBroadPhaseDispatcher_removeDuplicates(PairArray*, PairArray*);
void __cdecl sortPairList(PairArray*);
void __cdecl hkpWorldOperationUtil_internalMergeTwoIslands(StepWorld*, Island*, Island*);
Agent* __cdecl hkpWorldAgentUtil_addAgent(Body*, Body*, Dispatcher*);
Agent* __cdecl FindEntryValue(Body*, Body*);
void __cdecl hkpWorldAgentUtil_removeAgentAndItsToiEvents(Agent*);
void __cdecl hkAgentNnMachine_ProcessAgent(Agent*, Dispatcher*, Output*, Manager*);
void __cdecl hkpWorldCallbackUtil_fireConstraintViolated(StepWorld*, Constraint*);
void __cdecl hkpWorldCallbackUtil_firePostCollideCallback(StepWorld*, TimeInfo*);
void __cdecl ProcessChildLoop(StepWorld*);
__forceinline Body* bodyOf(Handle* h)
{
    return (Body*)((char*)h + h->off);
}
__forceinline Entity* entityOf(Body* b)
{
    return (Entity*)((char*)b + b->ownerOffset);
}
template <class T> __forceinline void releasePairElements(T* items, int total)
{
    while (total > 0)
    {
        T& element = items[--total];
        element.~T();
    }
}
template <class T> struct PairBufferBase
{

    T* data;
    int count;
    unsigned capacity;

    __forceinline int size() const
    {
        return count;
    }

    __forceinline T& operator[](int n)
    {
        return data[n];
    }

    __forceinline const T& operator[](int n) const
    {
        return data[n];
    }

    __forceinline void clear()
    {
        releasePairElements(data, count);
        count = 0;
    }
};
template <class T> struct PairBuffer : PairBufferBase<T>
{
};
struct Stepper
{

    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();

    int f004;

    int f008;

    StepWorld* f00c;

    int f010;

    int f014;

    float f018;

    float f01c;

    int f020;

    int f024;

    int f028;

    int f02c;

    int f030;

    int f034;

    int f038;

    int f03c;

    int f040;

    int f044;

    int f048;

    int f04c;

    int f050;

    int f054;

    int f058;

    int f05c;

    int f060;

    int f064;

    volatile char enabled;
    char flag69, flag6a, flag6b;

    PairBuffer<StepPair> added;

    int f078;

    int f07c;

    int f080;

    int f084;

    int f088;

    int f08c;

    PairBuffer<StepPair> removed;

    char f09c, f09d, f09e, f09f;

    int f0a0;

    int f0a4;

    int f0a8;

    int f0ac;

    int f0b0;

    int f0b4;

    int f0b8;

    int f0bc;

    int f0c0;

    int f0c4;

    int f0c8;

    int f0cc;

    int f0d0;

    int f0d4;

    int f0d8;

    int f0dc;

    int f0e0;

    char f0e4, f0e5, f0e6, f0e7;

    int f0e8;

    int f0ec;

    int f0f0;

    int f0f4;

    int f0f8;

    int f0fc;

    int f100;

    void AddToiEvent(Output*, Agent*, void*);

    int hkpMultiThreadedSimulation_finishMtStep(Job*, Jobs*);
};
extern "C" void _ReadWriteBarrier(void);
unsigned __int64 __cdecl __rdtsc(void);
struct DeallocCtx
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* pData, int iSize);
};
struct Singleton
{
    int* m_00;
    int m_04;
    int m_08;
    int m_0c;
    DeallocCtx* m_10;
};
void __cdecl ResizeAudioStream(void*, PairArray*, int);
static inline Singleton* GetSingleton()
{
    return (Singleton*)hkMemoryRouter_getInstance();
}
struct ArrPair
{
    Pair* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    __forceinline void AppendN(void* a, int b, int n)
    {
        for (int k = 0; k < n; ++k)
        {
            Pair& pr = m_pData[m_iArrayLength++];
            pr.a = (int)a;
            pr.b = b;
        }
    }
};
struct ArrGroup
{
    Group* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void ZeroNew(int idx)
    {
        Group* t = m_pData + idx;
        if (t != 0)
        {
            t->id = 0;
            t->count = 0;
            t->start = 0;
            t->unk0C = 0;
            t->job = 0;
            t->unk14 = 0;
        }
    }
    __forceinline Group& FindOrAdd(GroupIdentity* key)
    {
        for (int k = 0; k < m_iArrayLength; ++k)
        {
            if (key == m_pData[k].id)
                return m_pData[k];
        }
        Singleton* allocator = GetSingleton();
        if (m_iArrayLength == (m_iCapacity & 0x3fffffff))
            ResizeAudioStream(allocator->m_10, (PairArray*)this, 24);
        ZeroNew(m_iArrayLength);
        Group* added = m_pData + m_iArrayLength++;
        if (added != 0)
        {
            added->id = 0;
            added->count = 0;
            added->start = 0;
            added->unk0C = 0;
            added->job = 0;
            added->unk14 = 0;
        }
        m_pData[m_iArrayLength - 1].id = key;
        return m_pData[m_iArrayLength - 1];
    }
};
struct ObjA
{
    int m_00;
    int m_04;
    int m_08;
    void EnsureCapacity(DeallocCtx* ctx, int zero);
    int LookupHashEntry(void* elem, int zero);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(DeallocCtx* ctx, void* elem, int one);
    void ProcessArgument(DeallocCtx* ctx);
    void Object_DoNothing();
};
struct CollisionCell
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
    int active;
    unsigned char enabled;
    unsigned char unk35, unk36, unk37;
    int unk38, unk3c;
};
struct CollisionTable
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    int unk0df4;
    int unk0df8;
    int unk0dfc;
    int unk0e00;
    int unk0e04;
    int unk0e08;
    int unk0e0c;
    int unk0e10;
    int unk0e14;
    int unk0e18;
    int unk0e1c;
    int unk0e20;
    int unk0e24;
    int unk0e28;
    int unk0e2c;
    int unk0e30;
    int unk0e34;
    int unk0e38;
    int unk0e3c;
    int unk0e40;
    int unk0e44;
    int unk0e48;
    int unk0e4c;
    int unk0e50;
    int unk0e54;
    int unk0e58;
    int unk0e5c;
    int unk0e60;
    int unk0e64;
    int unk0e68;
    int unk0e6c;
    int unk0e70;
    int unk0e74;
    int unk0e78;
    int unk0e7c;
    int unk0e80;
    int unk0e84;
    int unk0e88;
    int unk0e8c;
    int unk0e90;
    int unk0e94;
    int unk0e98;
    int unk0e9c;
    int unk0ea0;
    int unk0ea4;
    int unk0ea8;
    int unk0eac;
    int unk0eb0;
    int unk0eb4;
    int unk0eb8;
    int unk0ebc;
    int unk0ec0;
    int unk0ec4;
    int unk0ec8;
    int unk0ecc;
    int unk0ed0;
    int unk0ed4;
    int unk0ed8;
    int unk0edc;
    int unk0ee0;
    int unk0ee4;
    int unk0ee8;
    int unk0eec;
    int unk0ef0;
    int unk0ef4;
    int unk0ef8;
    int unk0efc;
    int unk0f00;
    int unk0f04;
    int unk0f08;
    int unk0f0c;
    int unk0f10;
    int unk0f14;
    int unk0f18;
    int unk0f1c;
    int unk0f20;
    int unk0f24;
    int unk0f28;
    int unk0f2c;
    int unk0f30;
    int unk0f34;
    int unk0f38;
    int unk0f3c;
    int unk0f40;
    int unk0f44;
    int unk0f48;
    int unk0f4c;
    int unk0f50;
    int unk0f54;
    int unk0f58;
    int unk0f5c;
    int unk0f60;
    int unk0f64;
    int unk0f68;
    int unk0f6c;
    int unk0f70;
    int unk0f74;
    int unk0f78;
    int unk0f7c;
    int unk0f80;
    int unk0f84;
    int unk0f88;
    int unk0f8c;
    int unk0f90;
    int unk0f94;
    int unk0f98;
    int unk0f9c;
    int unk0fa0;
    int unk0fa4;
    int unk0fa8;
    int unk0fac;
    int unk0fb0;
    int unk0fb4;
    int unk0fb8;
    int unk0fbc;
    int unk0fc0;
    int unk0fc4;
    int unk0fc8;
    int unk0fcc;
    int unk0fd0;
    int unk0fd4;
    int unk0fd8;
    int unk0fdc;
    int unk0fe0;
    int unk0fe4;
    int unk0fe8;
    int unk0fec;
    int unk0ff0;
    int unk0ff4;
    int unk0ff8;
    int unk0ffc;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100c;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101c;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102c;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103c;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104c;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105c;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106c;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107c;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108c;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109c;
    int unk10a0;
    int unk10a4;
    int unk10a8;
    int unk10ac;
    int unk10b0;
    int unk10b4;
    int unk10b8;
    int unk10bc;
    int unk10c0;
    int unk10c4;
    int unk10c8;
    int unk10cc;
    int unk10d0;
    int unk10d4;
    int unk10d8;
    int unk10dc;
    int unk10e0;
    int unk10e4;
    int unk10e8;
    int unk10ec;
    int unk10f0;
    int unk10f4;
    int unk10f8;
    int unk10fc;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110c;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111c;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112c;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113c;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114c;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115c;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116c;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117c;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118c;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119c;
    int unk11a0;
    int unk11a4;
    int unk11a8;
    int unk11ac;
    int unk11b0;
    int unk11b4;
    int unk11b8;
    int unk11bc;
    int unk11c0;
    int unk11c4;
    int unk11c8;
    int unk11cc;
    int unk11d0;
    int unk11d4;
    int unk11d8;
    int unk11dc;
    int unk11e0;
    int unk11e4;
    int unk11e8;
    int unk11ec;
    int unk11f0;
    int unk11f4;
    int unk11f8;
    int unk11fc;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120c;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121c;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122c;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123c;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124c;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125c;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126c;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127c;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128c;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129c;
    int unk12a0;
    int unk12a4;
    int unk12a8;
    int unk12ac;
    int unk12b0;
    int unk12b4;
    int unk12b8;
    int unk12bc;
    int unk12c0;
    int unk12c4;
    int unk12c8;
    int unk12cc;
    int unk12d0;
    int unk12d4;
    int unk12d8;
    int unk12dc;
    int unk12e0;
    int unk12e4;
    int unk12e8;
    int unk12ec;
    int unk12f0;
    int unk12f4;
    int unk12f8;
    int unk12fc;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130c;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131c;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132c;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133c;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134c;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135c;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136c;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137c;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138c;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139c;
    int unk13a0;
    int unk13a4;
    int unk13a8;
    int unk13ac;
    int unk13b0;
    int unk13b4;
    int unk13b8;
    int unk13bc;
    int unk13c0;
    int unk13c4;
    int unk13c8;
    int unk13cc;
    int unk13d0;
    int unk13d4;
    int unk13d8;
    int unk13dc;
    int unk13e0;
    int unk13e4;
    int unk13e8;
    int unk13ec;
    int unk13f0;
    int unk13f4;
    int unk13f8;
    int unk13fc;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140c;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141c;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142c;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143c;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144c;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145c;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146c;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147c;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148c;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149c;
    int unk14a0;
    int unk14a4;
    int unk14a8;
    int unk14ac;
    int unk14b0;
    int unk14b4;
    int unk14b8;
    int unk14bc;
    int unk14c0;
    int unk14c4;
    int unk14c8;
    int unk14cc;
    int unk14d0;
    int unk14d4;
    int unk14d8;
    int unk14dc;
    int unk14e0;
    int unk14e4;
    int unk14e8;
    int unk14ec;
    int unk14f0;
    int unk14f4;
    int unk14f8;
    int unk14fc;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150c;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151c;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152c;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153c;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154c;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155c;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156c;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157c;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158c;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159c;
    int unk15a0;
    int unk15a4;
    int unk15a8;
    int unk15ac;
    int unk15b0;
    int unk15b4;
    int unk15b8;
    int unk15bc;
    int unk15c0;
    int unk15c4;
    int unk15c8;
    int unk15cc;
    int unk15d0;
    int unk15d4;
    int unk15d8;
    int unk15dc;
    int unk15e0;
    int unk15e4;
    int unk15e8;
    int unk15ec;
    int unk15f0;
    int unk15f4;
    int unk15f8;
    int unk15fc;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160c;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161c;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162c;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163c;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164c;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165c;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166c;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167c;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168c;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169c;
    int unk16a0;
    int unk16a4;
    int unk16a8;
    int unk16ac;
    int unk16b0;
    int unk16b4;
    int unk16b8;
    int unk16bc;
    int unk16c0;
    int unk16c4;
    int unk16c8;
    int unk16cc;
    int unk16d0;
    int unk16d4;
    int unk16d8;
    int unk16dc;
    int unk16e0;
    int unk16e4;
    int unk16e8;
    int unk16ec;
    int unk16f0;
    int unk16f4;
    int unk16f8;
    int unk16fc;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170c;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171c;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172c;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173c;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174c;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175c;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176c;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177c;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178c;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179c;
    int unk17a0;
    int unk17a4;
    int unk17a8;
    int unk17ac;
    int unk17b0;
    int unk17b4;
    int unk17b8;
    int unk17bc;
    int unk17c0;
    int unk17c4;
    int unk17c8;
    int unk17cc;
    int unk17d0;
    int unk17d4;
    int unk17d8;
    int unk17dc;
    int unk17e0;
    int unk17e4;
    int unk17e8;
    int unk17ec;
    int unk17f0;
    int unk17f4;
    int unk17f8;
    int unk17fc;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180c;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181c;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182c;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183c;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184c;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185c;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186c;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187c;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188c;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189c;
    int unk18a0;
    int unk18a4;
    int unk18a8;
    int unk18ac;
    int unk18b0;
    int unk18b4;
    int unk18b8;
    int unk18bc;
    int unk18c0;
    int unk18c4;
    int unk18c8;
    int unk18cc;
    int unk18d0;
    int unk18d4;
    int unk18d8;
    int unk18dc;
    int unk18e0;
    int unk18e4;
    int unk18e8;
    int unk18ec;
    int unk18f0;
    int unk18f4;
    int unk18f8;
    int unk18fc;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190c;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191c;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192c;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193c;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194c;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195c;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196c;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197c;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198c;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199c;
    int unk19a0;
    int unk19a4;
    int unk19a8;
    int unk19ac;
    int unk19b0;
    int unk19b4;
    int unk19b8;
    int unk19bc;
    int unk19c0;
    int unk19c4;
    int unk19c8;
    int unk19cc;
    int unk19d0;
    int unk19d4;
    int unk19d8;
    int unk19dc;
    int unk19e0;
    int unk19e4;
    int unk19e8;
    int unk19ec;
    int unk19f0;
    int unk19f4;
    int unk19f8;
    int unk19fc;
    int unk1a00;
    int unk1a04;
    int unk1a08;
    int unk1a0c;
    int unk1a10;
    int unk1a14;
    int unk1a18;
    int unk1a1c;
    int unk1a20;
    int unk1a24;
    int unk1a28;
    int unk1a2c;
    int unk1a30;
    int unk1a34;
    int unk1a38;
    int unk1a3c;
    int unk1a40;
    int unk1a44;
    int unk1a48;
    int unk1a4c;
    int unk1a50;
    int unk1a54;
    int unk1a58;
    int unk1a5c;
    int unk1a60;
    int unk1a64;
    int unk1a68;
    int unk1a6c;
    int unk1a70;
    int unk1a74;
    int unk1a78;
    int unk1a7c;
    int unk1a80;
    int unk1a84;
    int unk1a88;
    int unk1a8c;
    int unk1a90;
    int unk1a94;
    int unk1a98;
    int unk1a9c;
    int unk1aa0;
    int unk1aa4;
    int unk1aa8;
    int unk1aac;
    int unk1ab0;
    int unk1ab4;
    int unk1ab8;
    int unk1abc;
    int unk1ac0;
    int unk1ac4;
    int unk1ac8;
    int unk1acc;
    int unk1ad0;
    int unk1ad4;
    int unk1ad8;
    int unk1adc;
    int unk1ae0;
    int unk1ae4;
    int unk1ae8;
    int unk1aec;
    int unk1af0;
    int unk1af4;
    int unk1af8;
    int unk1afc;
    int unk1b00;
    int unk1b04;
    int unk1b08;
    int unk1b0c;
    int unk1b10;
    int unk1b14;
    int unk1b18;
    int unk1b1c;
    int unk1b20;
    int unk1b24;
    int unk1b28;
    int unk1b2c;
    int unk1b30;
    int unk1b34;
    int unk1b38;
    int unk1b3c;
    int unk1b40;
    int unk1b44;
    int unk1b48;
    int unk1b4c;
    int unk1b50;
    int unk1b54;
    int unk1b58;
    int unk1b5c;
    int unk1b60;
    int unk1b64;
    int unk1b68;
    int unk1b6c;
    int unk1b70;
    int unk1b74;
    int unk1b78;
    int unk1b7c;
    int unk1b80;
    int unk1b84;
    int unk1b88;
    int unk1b8c;
    int unk1b90;
    int unk1b94;
    int unk1b98;
    int unk1b9c;
    int unk1ba0;
    int unk1ba4;
    int unk1ba8;
    int unk1bac;
    int unk1bb0;
    int unk1bb4;
    int unk1bb8;
    int unk1bbc;
    int unk1bc0;
    int unk1bc4;
    int unk1bc8;
    int unk1bcc;
    int unk1bd0;
    int unk1bd4;
    int unk1bd8;
    int unk1bdc;
    int unk1be0;
    int unk1be4;
    int unk1be8;
    int unk1bec;
    int unk1bf0;
    int unk1bf4;
    int unk1bf8;
    int unk1bfc;
    CollisionCell cells[32];
};
struct SubObj
{
    unsigned char unk00_00;
    unsigned char unk00_01;
    unsigned char unk00_02;
    unsigned char unk00_03;
    unsigned char unk00_04;
    unsigned char unk00_05;
    unsigned char unk00_06;
    unsigned char unk00_07;
    unsigned char unk00_08;
    unsigned char unk00_09;
    unsigned char unk00_0a;
    unsigned char unk00_0b;
    unsigned char unk00_0c;
    unsigned char unk00_0d;
    unsigned char unk00_0e;
    unsigned char unk00_0f;
    unsigned char unk00_10;
    unsigned char unk00_11;
    unsigned char unk00_12;
    unsigned char unk00_13;
    unsigned char unk00_14;
    unsigned char unk00_15;
    unsigned char unk00_16;
    unsigned char unk00_17;
    unsigned char unk00_18;
    unsigned char unk00_19;
    unsigned char unk00_1a;
    unsigned char unk00_1b;
    unsigned char unk00_1c;
    unsigned char unk00_1d;
    unsigned char unk00_1e;
    unsigned char unk00_1f;
    unsigned char unk00_20;
    unsigned char unk00_21;
    unsigned char unk00_22;
    unsigned char unk00_23;
    unsigned char unk00_24;
    unsigned char unk00_25;
    unsigned char unk00_26;
    unsigned char unk00_27;
    unsigned char unk00_28;
    unsigned char unk00_29;
    unsigned char unk00_2a;
    unsigned char unk00_2b;
    unsigned char unk00_2c;
    unsigned char unk00_2d;
    unsigned char unk00_2e;
    unsigned char unk00_2f;
    unsigned char unk00_30;
    unsigned char unk00_31;
    unsigned char unk00_32;
    unsigned char unk00_33;
    unsigned char unk00_34;
    unsigned char unk00_35;
    unsigned char unk00_36;
    unsigned char unk00_37;
    unsigned char unk00_38;
    unsigned char unk00_39;
    unsigned char unk00_3a;
    unsigned char unk00_3b;
    unsigned char unk00_3c;
    unsigned char unk00_3d;
    unsigned char unk00_3e;
    unsigned char unk00_3f;
    unsigned char unk00_40;
    unsigned char unk00_41;
    unsigned char unk00_42;
    unsigned char unk00_43;
    unsigned char unk00_44;
    unsigned char unk00_45;
    unsigned char unk00_46;
    unsigned char unk00_47;
    unsigned char unk00_48;
    unsigned char unk00_49;
    unsigned char unk00_4a;
    unsigned char unk00_4b;
    unsigned char unk00_4c;
    unsigned char unk00_4d;
    unsigned char unk00_4e;
    unsigned char unk00_4f;
    unsigned char unk00_50;
    unsigned char unk00_51;
    unsigned char unk00_52;
    unsigned char unk00_53;
    unsigned char unk00_54;
    unsigned char unk00_55;
    unsigned char unk00_56;
    unsigned char unk00_57;
    unsigned char unk00_58;
    unsigned char unk00_59;
    unsigned char unk00_5a;
    unsigned char unk00_5b;
    unsigned char unk00_5c;
    unsigned char unk00_5d;
    unsigned char unk00_5e;
    unsigned char unk00_5f;
    unsigned char unk00_60;
    unsigned char unk00_61;
    unsigned char unk00_62;
    unsigned char unk00_63;
    unsigned char unk00_64;
    unsigned char unk00_65;
    unsigned char unk00_66;
    unsigned char unk00_67;
    unsigned char unk00_68;
    unsigned char unk00_69;
    unsigned char unk00_6a;
    unsigned char unk00_6b;
    unsigned char unk00_6c;
    unsigned char unk00_6d;
    unsigned char unk00_6e;
    unsigned char unk00_6f;
    unsigned char unk00_70;
    unsigned char unk00_71;
    unsigned char unk00_72;
    unsigned char unk00_73;
    unsigned char unk00_74;
    unsigned char unk00_75;
    unsigned char unk00_76;
    unsigned char unk00_77;
    void* m_78;
    unsigned char unk7c_00;
    unsigned char unk7c_01;
    unsigned char unk7c_02;
    unsigned char unk7c_03;
    CollisionTable* m_80;
    unsigned char unk84_00;
    unsigned char unk84_01;
    unsigned char unk84_02;
    unsigned char unk84_03;
    unsigned char unk84_04;
    unsigned char unk84_05;
    unsigned char unk84_06;
    unsigned char unk84_07;
    int m_8c;
    int m_90;
    int m_94;
    unsigned char unk98_00;
    unsigned char unk98_01;
    unsigned char unk98_02;
    unsigned char unk98_03;
    char m_9c;
    unsigned char unk9d_00;
    unsigned char unk9d_01;
    unsigned char unk9d_02;
    unsigned char unk9d_03;
    unsigned char unk9d_04;
    unsigned char unk9d_05;
    unsigned char unk9d_06;
    int m_a4;
    void* GetIn()
    {
        return m_78;
    }
    void FUN_00c91120();
    void UpdateFields_00c91140();
};
struct ElemSub
{
    SubNode* first;
    SubNode* second;
    void CopyAndSortGeometryList(ArrPair* out);
};
struct Elem
{
    unsigned char unk00_00;
    unsigned char unk00_01;
    unsigned char unk00_02;
    unsigned char unk00_03;
    unsigned char unk00_04;
    unsigned char unk00_05;
    unsigned char unk00_06;
    unsigned char unk00_07;
    unsigned char unk00_08;
    unsigned char unk00_09;
    unsigned char unk00_0a;
    unsigned char unk00_0b;
    signed char m_0c;
    unsigned char unk0d_00;
    unsigned char unk0d_01;
    unsigned char unk0d_02;
    ElemSub links;
    unsigned char unk18_00;
    unsigned char unk18_01;
    unsigned char unk18_02;
    unsigned char unk18_03;
    unsigned char unk18_04;
    unsigned char unk18_05;
    unsigned char unk18_06;
    unsigned char unk18_07;
    unsigned char unk18_08;
    unsigned char unk18_09;
    unsigned char unk18_0a;
    unsigned char unk18_0b;
    unsigned char unk18_0c;
    unsigned char unk18_0d;
    unsigned char unk18_0e;
    unsigned char unk18_0f;
    unsigned char unk18_10;
    unsigned char unk18_11;
    unsigned char unk18_12;
    unsigned char unk18_13;
    unsigned char unk18_14;
    unsigned char unk18_15;
    unsigned char unk18_16;
    unsigned char unk18_17;
    unsigned char unk18_18;
    unsigned char unk18_19;
    unsigned char unk18_1a;
    unsigned char unk18_1b;
    unsigned char unk18_1c;
    unsigned char unk18_1d;
    unsigned char unk18_1e;
    unsigned char unk18_1f;
    unsigned char unk18_20;
    unsigned char unk18_21;
    unsigned char unk18_22;
    unsigned char unk18_23;
    unsigned char unk18_24;
    unsigned char unk18_25;
    unsigned char unk18_26;
    unsigned char unk18_27;
    unsigned char unk18_28;
    unsigned char unk18_29;
    unsigned char unk18_2a;
    unsigned char unk18_2b;
    unsigned char unk18_2c;
    unsigned char unk18_2d;
    unsigned char unk18_2e;
    unsigned char unk18_2f;
    unsigned char unk18_30;
    unsigned char unk18_31;
    unsigned char unk18_32;
    unsigned char unk18_33;
    unsigned char unk18_34;
    unsigned char unk18_35;
    unsigned char unk18_36;
    unsigned char unk18_37;
    unsigned char unk18_38;
    unsigned char unk18_39;
    unsigned char unk18_3a;
    unsigned char unk18_3b;
    unsigned char unk18_3c;
    unsigned char unk18_3d;
    unsigned char unk18_3e;
    unsigned char unk18_3f;
    unsigned char unk18_40;
    unsigned char unk18_41;
    unsigned char unk18_42;
    unsigned char unk18_43;
    unsigned char unk18_44;
    unsigned char unk18_45;
    unsigned char unk18_46;
    unsigned char unk18_47;
    unsigned char unk18_48;
    unsigned char unk18_49;
    unsigned char unk18_4a;
    unsigned char unk18_4b;
    unsigned char unk18_4c;
    unsigned char unk18_4d;
    unsigned char unk18_4e;
    unsigned char unk18_4f;
    unsigned char unk18_50;
    unsigned char unk18_51;
    unsigned char unk18_52;
    unsigned char unk18_53;
    unsigned char unk18_54;
    unsigned char unk18_55;
    unsigned char unk18_56;
    unsigned char unk18_57;
    unsigned char unk18_58;
    unsigned char unk18_59;
    unsigned char unk18_5a;
    unsigned char unk18_5b;
    unsigned char unk18_5c;
    unsigned char unk18_5d;
    unsigned char unk18_5e;
    unsigned char unk18_5f;
    unsigned char unk18_60;
    unsigned char unk18_61;
    unsigned char unk18_62;
    unsigned char unk18_63;
    unsigned char unk18_64;
    unsigned char unk18_65;
    unsigned char unk18_66;
    unsigned char unk18_67;
    unsigned char unk18_68;
    unsigned char unk18_69;
    unsigned char unk18_6a;
    unsigned char unk18_6b;
    unsigned char unk18_6c;
    unsigned char unk18_6d;
    unsigned char unk18_6e;
    unsigned char unk18_6f;
    unsigned char unk18_70;
    unsigned char unk18_71;
    unsigned char unk18_72;
    unsigned char unk18_73;
    unsigned char unk18_74;
    unsigned char unk18_75;
    unsigned char unk18_76;
    unsigned char unk18_77;
    unsigned char unk18_78;
    unsigned char unk18_79;
    unsigned char unk18_7a;
    unsigned char unk18_7b;
    unsigned char unk18_7c;
    unsigned char unk18_7d;
    unsigned char unk18_7e;
    unsigned char unk18_7f;
    unsigned char unk18_80;
    unsigned char unk18_81;
    unsigned char unk18_82;
    unsigned char unk18_83;
    unsigned char unk18_84;
    unsigned char unk18_85;
    unsigned char unk18_86;
    unsigned char unk18_87;
    unsigned char unk18_88;
    unsigned char unk18_89;
    unsigned char unk18_8a;
    unsigned char unk18_8b;
    unsigned char unk18_8c;
    unsigned char unk18_8d;
    unsigned char unk18_8e;
    unsigned char unk18_8f;
    unsigned char unk18_90;
    unsigned char unk18_91;
    unsigned char unk18_92;
    unsigned char unk18_93;
    unsigned char unk18_94;
    unsigned char unk18_95;
    unsigned char unk18_96;
    unsigned char unk18_97;
    unsigned char unk18_98;
    unsigned char unk18_99;
    unsigned char unk18_9a;
    unsigned char unk18_9b;
    unsigned char unk18_9c;
    unsigned char unk18_9d;
    unsigned char unk18_9e;
    unsigned char unk18_9f;
    unsigned char unk18_a0;
    unsigned char unk18_a1;
    unsigned char unk18_a2;
    unsigned char unk18_a3;
    unsigned char unk18_a4;
    unsigned char unk18_a5;
    unsigned char unk18_a6;
    unsigned char unk18_a7;
    unsigned char unk18_a8;
    unsigned char unk18_a9;
    unsigned char unk18_aa;
    unsigned char unk18_ab;
    unsigned char unk18_ac;
    unsigned char unk18_ad;
    unsigned char unk18_ae;
    unsigned char unk18_af;
    unsigned char unk18_b0;
    unsigned char unk18_b1;
    unsigned char unk18_b2;
    unsigned char unk18_b3;
    int m_cc;
    unsigned char unkD0_00;
    unsigned char unkD0_01;
    unsigned char unkD0_02;
    unsigned char unkD0_03;
    unsigned char unkD0_04;
    unsigned char unkD0_05;
    unsigned char unkD0_06;
    unsigned char unkD0_07;
    unsigned char unkD0_08;
    unsigned char unkD0_09;
    unsigned char unkD0_0a;
    unsigned char unkD0_0b;
    unsigned char unkD0_0c;
    unsigned char unkD0_0d;
    unsigned char unkD0_0e;
    unsigned char unkD0_0f;
    unsigned char unkD0_10;
    unsigned char unkD0_11;
    unsigned char unkD0_12;
    unsigned char unkD0_13;
    unsigned char unkD0_14;
    unsigned char unkD0_15;
    unsigned char unkD0_16;
    unsigned char unkD0_17;
    char m_e8;
    unsigned char unkE9_00;
    unsigned char unkE9_01;
    unsigned char unkE9_02;
    unsigned char unkE9_03;
    unsigned char unkE9_04;
    unsigned char unkE9_05;
    unsigned char unkE9_06;
    unsigned char unkE9_07;
    unsigned char unkE9_08;
    unsigned char unkE9_09;
    unsigned char unkE9_0a;
    unsigned char unkE9_0b;
    unsigned char unkE9_0c;
    unsigned char unkE9_0d;
    unsigned char unkE9_0e;
    unsigned char unkE9_0f;
    unsigned char unkE9_10;
    unsigned char unkE9_11;
    unsigned char unkE9_12;
    unsigned char unkE9_13;
    unsigned char unkE9_14;
    unsigned char unkE9_15;
    unsigned char unkE9_16;
    unsigned char unkE9_17;
    unsigned char unkE9_18;
    unsigned char unkE9_19;
    unsigned char unkE9_1a;
    unsigned char unkE9_1b;
    unsigned char unkE9_1c;
    unsigned char unkE9_1d;
    unsigned char unkE9_1e;
    unsigned char unkE9_1f;
    unsigned char unkE9_20;
    unsigned char unkE9_21;
    unsigned char unkE9_22;
    unsigned char unkE9_23;
    unsigned char unkE9_24;
    unsigned char unkE9_25;
    unsigned char unkE9_26;
    unsigned char unkE9_27;
    unsigned char unkE9_28;
    unsigned char unkE9_29;
    unsigned char unkE9_2a;
    unsigned char unkE9_2b;
    unsigned char unkE9_2c;
    unsigned char unkE9_2d;
    unsigned char unkE9_2e;
    unsigned char unkE9_2f;
    unsigned char unkE9_30;
    unsigned char unkE9_31;
    unsigned char unkE9_32;
    unsigned char unkE9_33;
    unsigned char unkE9_34;
    unsigned char unkE9_35;
    unsigned char unkE9_36;
    unsigned char unkE9_37;
    unsigned char unkE9_38;
    unsigned char unkE9_39;
    unsigned char unkE9_3a;
    unsigned char unkE9_3b;
    unsigned char unkE9_3c;
    unsigned char unkE9_3d;
    unsigned char unkE9_3e;
    unsigned char unkE9_3f;
    unsigned char unkE9_40;
    unsigned char unkE9_41;
    unsigned char unkE9_42;
    unsigned char unkE9_43;
    unsigned char unkE9_44;
    unsigned char unkE9_45;
    unsigned char unkE9_46;
    unsigned char unkE9_47;
    unsigned char unkE9_48;
    unsigned char unkE9_49;
    unsigned char unkE9_4a;
    unsigned char unkE9_4b;
    unsigned char unkE9_4c;
    unsigned char unkE9_4d;
    unsigned char unkE9_4e;
    unsigned char unkE9_4f;
    unsigned char unkE9_50;
    unsigned char unkE9_51;
    unsigned char unkE9_52;
    unsigned char unkE9_53;
    unsigned char unkE9_54;
    unsigned char unkE9_55;
    unsigned char unkE9_56;
    unsigned char unkE9_57;
    unsigned char unkE9_58;
    unsigned char unkE9_59;
    unsigned char unkE9_5a;
    unsigned char unkE9_5b;
    unsigned char unkE9_5c;
    unsigned char unkE9_5d;
    unsigned char unkE9_5e;
    unsigned char unkE9_5f;
    unsigned char unkE9_60;
    unsigned char unkE9_61;
    unsigned char unkE9_62;
    float m_14c;
    void FUN_00c905b0();
};
struct ParamObj
{
    Pair* m_pData;
    int m_04;
    int m_iArrayLength;
    void ResetEntries();
    int First()
    {
        int index = 0;
        if (m_iArrayLength >= 0)
        {
            while (index <= m_iArrayLength && m_pData[index].a == -1)
                ++index;
        }
        return index;
    }
    int Next(int index)
    {
        ++index;
        if (index <= m_iArrayLength)
        {
            while (index <= m_iArrayLength && m_pData[index].a == -1)
                ++index;
        }
        return index;
    }
};
struct CollisionFlag
{
    char value;
    CollisionFlag(char v) : value(v)
    {}
};
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    SubObj* m_0c;
    void hkpMultiThreadedSimulation_collideEntitiesNeedingPsiCollisionDetectionNarrowPhase_toiOnly(ParamObj* p0, ParamObj* p1);
    void ProcessGroups(int* a, int b, Group* c, int d, void* e, CollisionFlag f);
};

namespace StepBeginSse {
// Exe 0x00d022b0 FUN_00d022b0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    void _mm_store_ps(float*, LocalM128);
}
}
extern "C" void _ReadWriteBarrier();
extern "C" void __debugbreak();
extern int DAT_01269210;
extern char DAT_010ccbb0, DAT_010cc5bc, DAT_010cc5b0, DAT_01076f38;
namespace StepBeginDetail {
struct Ring
{
    int unk00;
    int* cur;
    int unk08;
    int* end;
};
struct Entry16
{
    const char* id;
    int ts;
    int unk;
    const char* id2;
};
struct Entry12
{
    const char* id;
    int ts;
    int unk;
};
static __forceinline void writeBeginTrace(volatile int& ts)
{
    Ring* ring = (Ring*)TlsGetValue(DAT_0126835c);
    Entry16* cur = (Entry16*)ring->cur;
    if ((int*)cur < ring->end)
    {
        cur->id = &DAT_010ccbb0;
        cur->id2 = &DAT_010cc5bc;
        _ReadWriteBarrier();
        ts = (int)__rdtsc();
        cur->ts = ts;
        cur += 1;
        ring->cur = (int*)cur;
    }
}
static __forceinline void writeTrace(const char* name, volatile int& ts2)
{
    Ring* ring2 = (Ring*)TlsGetValue(DAT_0126835c);
    Entry12* cur2 = (Entry12*)ring2->cur;
    if ((int*)cur2 < ring2->end)
    {
        cur2->id = name;
        _ReadWriteBarrier();
        ts2 = (int)__rdtsc();
        cur2->ts = ts2;
        cur2 += 1;
        ring2->cur = (int*)cur2;
    }
}

struct Obj;
struct MemoryInfo
{
    int maximum;
    int total;
    void* largest;
};
struct Sub78
{
    int unk00;
    int unk04;
    float m_08;
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
    Vec4 m_50;
};
struct S4cObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(Obj* o, Vec4* v);
};
struct GlobObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual bool v20(int v);
};
struct Glob
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    GlobObj* m_18;
};
void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(void* p);
void __cdecl hkpWorldMemoryUtil_checkMemoryForIntegration(void* p);
void __cdecl hkSolveUpload();
struct Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec4 m_10;
    Vec4 m_20;
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
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    float m_10c;
    float m_110;
    int m_114;
    int unk118;
    int unk11c;
    float m_120;
    char unk124;
    char m_125;
    char m_126;
    char m_127;
    __forceinline void setup(const Vec4& v, const Vec4& direction)
    {
        m_10c = m_120 * v.z;
        m_110 = (float)m_114 * v.w;
        StepBeginSse::_mm_store_ps(
            (float*)&m_10, StepBeginSse::_mm_mul_ps(StepBeginSse::_mm_shuffle_ps(StepBeginSse::_mm_load_ss(&m_10c),
                                                                                 StepBeginSse::_mm_load_ss(&m_10c), 0),
                                                    StepBeginSse::_mm_load_ps((const float*)&direction)));
        float dz = v.z;
        StepBeginSse::_mm_store_ps(
            (float*)&m_20, StepBeginSse::_mm_mul_ps(StepBeginSse::_mm_shuffle_ps(StepBeginSse::_mm_load_ss(&dz),
                                                                                 StepBeginSse::_mm_load_ss(&dz), 0),
                                                    StepBeginSse::_mm_load_ps((const float*)&direction)));
    }
    __forceinline void advanceCounters()
    {
        unsigned char c = ++(unsigned char&)m_127;
        if ((((c - 4) & 7)) == 0)
            m_125 ^= 1;
        if ((c & 7) == 0)
            m_125 ^= 2;
        if ((c & 15) == 0)
        {
            m_126 = 1 - m_126;
            m_127 = 0;
        }
    }
};
struct __declspec(align(16)) Msg : JobBase
{
    int d20;
    __forceinline Msg() : JobBase(0, 0, 48, 2)
    {
        count = 0;
    }
};
struct ArgCls
{
    void hkJobQueue_setQueueCapacityForJobType(int a, int b);
    void AddObjectCopy(Msg* m, int b);
};
struct QueueHandle
{
    ArgCls* queue;
};
struct RegA
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
    void hkpConstraintQueryIn_set(Sub* s, Vec4* v, void* h);
};
struct RegB
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
    void FUN_00cfa7d0(Sub78* s);
};
struct EdiObj
{
    Obj* m_00;
    int unk04;
    int unk08;
    int unk0c;
    RegA m_10;
    RegB m_90;
    void* m_110;
    void* m_114;
    float m_118;
    void* m_11c;
};
struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Vec4 m_10;
    int unk20;
    int unk24;
    int unk28;
    int m_2c;
    int unk30;
    int unk34;
    int m_38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    S4cObj* m_4c;
    int m_50;
    char m_54;
    char unk55;
    char unk56;
    char unk57;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    EdiObj* m_74;
    Sub78* m_78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    char m_9c;
    char unk9d;
    char unk9e;
    char unk9f;
    int unka0;
    int m_a4;
    int unka8;
    int unkac;
    char m_b0;
    char unkb1;
    char unkb2;
    char unkb3;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    int* m_1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    Vec4 m_1d0;
    Sub m_1e0;
    __forceinline void unlock()
    {
        if (--m_94 == 0 && m_9c == 0)
        {
            if (m_8c)
                FUN_00c91120();
            if (m_a4 == 1 && m_90)
                UpdateFields_00c91140();
        }
    }
    void* hkpWorld_getMemoryWatchDog();
    void ComputeMemoryUsage(MemoryInfo* out);
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void nullsub_6();
};
struct Simulation
{
    int unk00;
    int unk04;
    int unk08;
    Obj* volatile m_0c;
    int unk10;
    int unk14;
    float m_18;
    float m_1c;
    int unk20;
    int unk24;
    int m_28;
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
    volatile bool m_68;
    char unk69;
    char unk6a;
    char unk6b;
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
    int m_b8;
    int m_bc;
    int hkpMultiThreadedSimulation_stepBeginSt(ArgCls* arg, float dt);
    void hkpSimulation_applyActions();
};
static __forceinline void scaleGravity(Vec4* dst, const Obj& world, const float& scale)
{
    StepBeginSse::_mm_store_ps(
        (float*)dst, StepBeginSse::_mm_mul_ps(StepBeginSse::_mm_shuffle_ps(StepBeginSse::_mm_load_ss(&scale),
                                                                           StepBeginSse::_mm_load_ss(&scale), 0),
                                              StepBeginSse::_mm_load_ps((const float*)&world.m_10)));
}
// @fnv 0x00d022b0
// src: XBOX_PDB 0x00d022b0
int Simulation::hkpMultiThreadedSimulation_stepBeginSt(ArgCls* arg, float dt)
{
    union StepTraceScratch
    {
        volatile int ticks;
        float start;
    };
    StepTraceScratch scratch;
    writeBeginTrace(scratch.ticks);
    m_68 = 1;
    m_0c->m_94 += 1;
    m_1c = dt;
    __declspec(align(16)) Vec4 v;
    scratch.start = m_18;
    v.set(scratch.start, dt + m_18);
    m_0c->m_1d0 = v;
    m_0c->m_78->m_50 = v;
    {
        Obj* world = m_0c;
        world->m_4c->v14(world, &v);
    }
    hkpWorldOperationUtil_cleanupDirtyIslands(m_0c);
    MemoryInfo outVal;
    m_0c->ComputeMemoryUsage(&outVal);
    Glob* g = (Glob*)hkMemoryRouter_getInstance();
    bool ok = g->m_18->v20(outVal.maximum);
    if (!ok)
    {
        if (m_0c->hkpWorld_getMemoryWatchDog())
        {
            m_0c->unlock();
            hkpWorldMemoryUtil_checkMemoryForIntegration(m_0c);
            m_0c->m_94 += 1;
        }
        else
        {
            if (m_0c->m_54)
                __debugbreak();
            m_28 = 1;
            return 1;
        }
    }
    hkSolveUpload();
    m_0c->m_1d0 = v;
    Sub* sub = &const_cast<Obj*&>(m_0c)->m_1e0;
    sub->m_10c = sub->m_120 * v.z;
    sub->m_110 = (float)sub->m_114 * v.w;
    scaleGravity(&sub->m_10, *m_0c, sub->m_10c);
    scaleGravity(&sub->m_20, *m_0c, v.delta());
    *m_0c->m_1b8 = 0;
    Obj* world = m_0c;
    EdiObj* edi = world->m_74;
    edi->m_114 = &world->m_1d0;
    edi->m_90.FUN_00cfa7d0(m_0c->m_78);
    world = m_0c;
    edi->m_10.hkpConstraintQueryIn_set(&world->m_1e0, &world->m_1d0, world->m_1b8);
    edi->m_110 = this;
    edi->m_118 = m_0c->m_78->m_08;
    edi->m_11c = &DAT_01269210;
    edi->m_00 = m_0c;
    world = m_0c;
    int count = world->m_2c;
    if (count > 0)
    {
        if (world->m_b0)
        {
            writeTrace(&DAT_010cc5b0, scratch.ticks);
            m_0c->m_98 -= 1;
            hkpSimulation_applyActions();
            m_0c->m_98 += 1;
        }
        Msg msg;
        msg.d20 = count;
        msg.header = (int)m_0c->m_74;
        arg->hkJobQueue_setQueueCapacityForJobType(0, count);
        arg->hkJobQueue_setQueueCapacityForJobType(1, count);
        arg->AddObjectCopy(&msg, 1);
    }
    m_0c->m_1e0.advanceCounters();
    world = m_0c;
    m_b8 = world->m_2c;
    m_bc = world->m_38;
    world->nullsub_6();
    writeTrace(&DAT_01076f38, scratch.ticks);
    return 0;
}

}
