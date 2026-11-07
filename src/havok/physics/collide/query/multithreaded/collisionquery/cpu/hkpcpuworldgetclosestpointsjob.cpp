
// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00df6a30_Inner
{
    int unk0;
    float unk4;
};
struct S_00df6a30
{
    int unk0;
    int unk4;
    S_00df6a30_Inner* unk8;
    float EvaluateValue_00df6a30();
};
// @fnv 0x00df6a30
// src: GUESS 0x00df6a30 (confidence: low)
float S_00df6a30::EvaluateValue_00df6a30()
{
    return unk8->unk4;
}

struct DF6B10Event
{
    int unk00;
    int unk04;
    int unk08;
    void* m_kCollisionBody;
};

struct DF6B10Primary
{
    virtual void vfunc00();
};

struct DF6B10Listener
{
    virtual int HandleEvent(DF6B10Event* event);
};

struct DF6B10Object : DF6B10Primary, DF6B10Listener
{
    int handleBody(void* body);

    virtual int HandleEvent(DF6B10Event* event);
};

// @fnv 0x00df6b10
int DF6B10Object::HandleEvent(DF6B10Event* event)
{
    void* body = event->m_kCollisionBody;
    return handleBody(body);
}

struct FUN_00df6a40_inner
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

class FUN_00df6a40_cls
{
  public:
    int m_00;
    int m_04;
    FUN_00df6a40_inner* m_08;

    bool* hkCpuWorldGetClosestPointsCollector_hasHit(bool* out);
};

// @fnv 0x00df6a40
// src: HAVOK_LIB 0x00df6a40
bool* FUN_00df6a40_cls::hkCpuWorldGetClosestPointsCollector_hasHit(bool* pbResult)
{
    *pbResult = m_08->m_14 > 0;
    return pbResult;
}

struct DF6A60Bool
{
    char m_cBooleanValue;

    DF6A60Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DF6A60Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};

struct DF6A60Collidable
{
    const DF6A60Shape* m_pCollisionShape;
};

struct DF6A60CdPointCollector
{
    int unk00;
    float m_fEarlyOutDistance;
};

struct DF6A60LinearCastInput;

typedef void(__cdecl* DF6A60LinearCastFunc)(const DF6A60Collidable& bodyA, const DF6A60Collidable& bodyB,
                                            const DF6A60LinearCastInput& input, DF6A60CdPointCollector& collector);

struct DF6A60AgentFuncs
{
    DF6A60LinearCastFunc m_pLinearCastFunc;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct DF6A60Dispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
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
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[64][32];
    int unk9A0;
    int unk9A4;
    DF6A60AgentFuncs m_agent2Funcs[1];

    DF6A60LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_pLinearCastFunc;
    }
};

struct DF6A60LinearCastInput
{
    const DF6A60Dispatcher* m_pCollisionDispatcher;
};

struct DF6A60CollidableCollidableFilter
{
    virtual void unk00();
    virtual DF6A60Bool IsCollisionEnabled(const DF6A60Collidable& a, const DF6A60Collidable& b) const;
};

struct DF6A60Filter
{
    int unk00;
    int unk04;
    DF6A60CollidableCollidableFilter m_collidableFilter;
};

struct DF6A60CastCollector
{
    int unk00;
    int unk04;
    int unk08;
    const DF6A60Filter* m_iFilter;
    DF6A60CdPointCollector* m_pPointCollector;
    const DF6A60Collidable* m_pCollidableA;
    int m_shapeTypeA;
    int unk1C;
    DF6A60LinearCastInput m_pRayCastInput;

    float LinearCastAgainst(const DF6A60Collidable* collidableB);
};

// @fnv 0x00df6a60
float DF6A60CastCollector::LinearCastAgainst(const DF6A60Collidable* collidableB)
{
    const DF6A60Shape* shapeB = collidableB->m_pCollisionShape;
    if (shapeB && (m_pCollidableA != collidableB))
    {
        if (m_iFilter->m_collidableFilter.IsCollisionEnabled(*m_pCollidableA, *collidableB))
        {
            int typeB = shapeB->m_type;
            DF6A60LinearCastFunc pLinearCastFunc =
                m_pRayCastInput.m_pCollisionDispatcher->getLinearCastFunc(m_shapeTypeA, typeB);
            pLinearCastFunc(*m_pCollidableA, *collidableB, m_pRayCastInput, *m_pPointCollector);
        }
    }
    return m_pPointCollector->m_fEarlyOutDistance;
}

// GetHelperResultForOffset: thiscall member that forwards a byte-adjusted pointer to a
// sibling thiscall helper (the helper receives `this` in ecx and pops its
// single stack argument).
struct FUN_00df6af0_cls
{
    float Helper(int value);
    float GetHelperResultForOffset(int a1, int a2);
};

// @fnv 0x00df6af0
float FUN_00df6af0_cls::GetHelperResultForOffset(int aiBase, int aiUnused)
{
    signed char c = *(signed char*)(aiBase + 5);
    int v = c + aiBase;
    return this->Helper(v);
}

struct SiblingCls_df6a60
{
    float Call(int a);
};

struct FUN_00df6b30_cls
{
    unsigned char* hkCpuWorldGetClosestPointsCollector_addMidPhaseHit(unsigned char* out, int a);
};

// @fnv 0x00df6b30
// src: HAVOK_LIB 0x00df6b30
unsigned char* FUN_00df6b30_cls::hkCpuWorldGetClosestPointsCollector_addMidPhaseHit(unsigned char* out, int a)
{
    ((SiblingCls_df6a60*)((char*)this - 8))->Call(a);
    *out = 0;
    return out;
}

extern float DAT_0104da48;
extern int DAT_0108f288;
extern "C" __declspec(dllimport) long __stdcall DAT_00fdf1ec(long volatile*, long);

struct CopyQuad
{
    int x;
    int y;
    int z;
    int w;
};
struct __declspec(align(16)) QueryPoint
{
    CopyQuad parts[7];
};
struct QueryInput
{
    const DF6A60Dispatcher* dispatcher;
    int unk04;
    float tolerance;
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
};
struct QueryCollector
{
    int* table;
    float earlyOut;
    QueryPoint* base;
    QueryPoint* next;
    int capacity;
    int count;
    QueryCollector(QueryPoint* b, int c)
        : earlyOut(DAT_0104da48), base(b), next(b), capacity(c), count(0), table(&DAT_0108f288)
    {}
};
struct QueryJob
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float tolerance;
};
struct PairCommand
{
    const DF6A60Collidable* a;
    const DF6A60Collidable* b;
    QueryPoint* results;
    int capacity;
    int numResults;
    long volatile* sharedIndex;
    int unk18;
    int unk1C;
};
typedef void(__cdecl* QueryFunction)(const DF6A60Collidable&, const DF6A60Collidable&, const QueryInput&,
                                     QueryCollector&);

inline QueryPoint* allocateResults(PairCommand* command, const QueryCollector& collector)
{
    {
        int hits = collector.count;
        int start = DAT_00fdf1ec(command->sharedIndex, hits);
        if (start + hits <= command->capacity)
            return command->results + start;
        DAT_00fdf1ec(command->sharedIndex, -hits);
        return 0;
    }
}

// Iterates over PairCommand entries, dispatches collision queries via the dispatcher, and copies resulting QueryPoints into each command's output buffer.
// @fnv 0x00df6e00
// src: XBOX_PDB 0x00df6e00
void hkCpuPairGetClosestPointsImplementation(const QueryJob* job, const QueryInput* source, PairCommand* commands, int count)
{
    QueryPoint buffer[16];
    QueryCollector collector(buffer, 1);
    QueryInput input;
    input.tolerance = job->tolerance;
    input.dispatcher = source->dispatcher;
    input.unk0C = source->unk0C;
    for (int i = 0; i < count; ++i)
    {
        PairCommand* command = &commands[i];
        const DF6A60Collidable* a = command->a;
        const DF6A60Collidable* b = command->b;
        const DF6A60Shape* pShapeA = a->m_pCollisionShape;
        const DF6A60Shape* pShapeB = b->m_pCollisionShape;
        collector.earlyOut = DAT_0104da48;
        collector.base = buffer;
        collector.next = buffer;
        collector.capacity = command->capacity;
        collector.table = &DAT_0108f288;
        collector.count = 0;
        QueryFunction pQueryFunc =
            (QueryFunction)source->dispatcher->getLinearCastFunc(pShapeA->m_type, pShapeB->m_type);
        pQueryFunc(*a, *b, input, collector);
        QueryPoint* out;
        if (!command->sharedIndex)
            out = command->results;
        else
            out = allocateResults(command, collector);
        if (out)
        {
            int hits = (unsigned short)collector.count;
            command->numResults = hits;
            if (hits > 0)
            {
                const int* src = (const int*)buffer;
                int* dest = (int*)out;
                int remaining = hits * 7;
                do
                {
                    dest[0] = src[0];
                    dest[1] = src[1];
                    dest[2] = src[2];
                    dest[3] = src[3];
                    src += 4;
                    dest += 4;
                    --remaining;
                } while (remaining > 0);
            }
        }
    }
}

// FUN_00df6db0 - base-class adjustment thunk (8 bytes):
//
//     sub ecx, 4
//     jmp  <the derived class' implementation of the overridden virtual>
//
// The secondary base sub-object starts four bytes into the derived object, so
// the vtable slot that the base contributes to the derived class holds an
// adjustor thunk: it moves `this` back to the derived object and tail-calls
// the derived implementation.  The implementation itself lives in another
// translation unit, so it is only declared here.

struct PrimaryBase
{
    PrimaryBase();
    virtual void FUN_00df6db0(int flag);
};

struct SecondaryBase
{
    SecondaryBase();
    virtual void FUN_00df6db0(int flag);
};

struct Derived : public PrimaryBase, public SecondaryBase
{
    Derived();
// @fnv 0x00df6db0
    virtual void FUN_00df6db0(int flag);
};

PrimaryBase::PrimaryBase()
{}
SecondaryBase::SecondaryBase()
{}
Derived::Derived() : PrimaryBase(), SecondaryBase()
{}

struct DF6DC0Primary
{
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00df6dc0();

    int unk04;
};

struct DF6DC0Secondary
{
    virtual void AdjustThisAndForward_00df6dc0();
};

struct DF6DC0Object : DF6DC0Primary, DF6DC0Secondary
{
    DF6DC0Object();

// @fnv 0x00df6dc0
// src: GUESS 0x00df6dc0 (confidence: low)
    virtual void AdjustThisAndForward_00df6dc0();
};

DF6DC0Object::DF6DC0Object()
{}

struct S_00df6dd0_A
{
    virtual ~S_00df6dd0_A()
    {}
};
struct S_00df6dd0_B
{
    virtual void Func();
    ~S_00df6dd0_B()
    {}
};
struct S_00df6dd0_C
{
    virtual void Func2();
    ~S_00df6dd0_C()
    {}
};

struct FUN_00df6dd0 : S_00df6dd0_A, S_00df6dd0_B, S_00df6dd0_C
{
    FUN_00df6dd0();
    virtual ~FUN_00df6dd0();
};

// Default constructor for the FUN_00df6dd0 class, initializing its multiple inheritance bases.
// @fnv 0x00df6dd0
FUN_00df6dd0::FUN_00df6dd0()
{}
FUN_00df6dd0::~FUN_00df6dd0()
{}
