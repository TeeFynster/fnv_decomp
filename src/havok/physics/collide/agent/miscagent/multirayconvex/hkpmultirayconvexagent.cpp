
// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryRouter.h"

void hkpMultiRayConvexAgent_staticGetPenetrations(int a, int b, int c, int d);

struct FUN_00d37690_Class
{
    void __thiscall ForwardToFunction(int a, int b, int c, int d);
};

// @fnv 0x00d37690
void __thiscall FUN_00d37690_Class::ForwardToFunction(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    hkpMultiRayConvexAgent_staticGetPenetrations(aiArg1, aiArg2, aiArg3, aiArg4);
}

void hkpMultiRayConvexAgent_createMultiRayConvexAgent(int a, int b, int c, int d);
void FUN_00d37780(int a, int b, int c, int d);
void Object_ProcessState_00d37860(int a, int b, int c, int d);
void Object_UpdateFields_00d378a0(int a, int b, int c, int d);
void hkpMultiRayConvexAgent_staticGetClosestPoints(int a, int b, int c, int d);
void Object_ProcessEntries_00daf8e0();
void Object_UpdateFields_00d3ac80();

struct FUN_00cfbbe0_Arg
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    char f4;
    char f5;
};

struct FUN_00cfbbe0_Class
{
    void __thiscall AppendRecordAndRegisterAgents(FUN_00cfbbe0_Arg* a, int b, int c);
};

// Builds two FUN_00cfbbe0_Arg descriptors from function pointers and flags and passes each to FUN_00cfbbe0 with size arguments 0x12/0x18 and 0x18/0x12.
// @fnv 0x00d377d0
// src: XBOX_PDB 0x00d377d0
void hkpMultiRayConvexAgent_registerAgent(int pClass)
{
    FUN_00cfbbe0_Class* p = (FUN_00cfbbe0_Class*)pClass;
    FUN_00cfbbe0_Arg arg;
    arg.f0 = (void*)&FUN_00d37780;
    arg.f1 = (void*)&Object_ProcessState_00d37860;
    arg.f2 = (void*)&Object_UpdateFields_00d378a0;
    arg.f3 = (void*)&Object_UpdateFields_00d3ac80;
    arg.f4 = 1;
    arg.f5 = 1;
    p->AppendRecordAndRegisterAgents(&arg, 0x12, 0x18);
    arg.f0 = (void*)&hkpMultiRayConvexAgent_createMultiRayConvexAgent;
    arg.f1 = (void*)&hkpMultiRayConvexAgent_staticGetPenetrations;
    arg.f2 = (void*)&hkpMultiRayConvexAgent_staticGetClosestPoints;
    arg.f3 = (void*)&Object_ProcessEntries_00daf8e0;
    arg.f4 = 0;
    arg.f5 = 1;
    p->AppendRecordAndRegisterAgents(&arg, 0x18, 0x12);
}

struct Handler
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void process(unsigned short index, int argument);
};
struct Owner
{
    virtual ~Owner();
    int unk04;
    Handler* handler;
    unsigned short* values;
    int count;
    void ProcessValuesAndDelete(int argument);
};
// Calls handler->process for each non-0xffff value in values, then deletes this.
// @fnv 0x00d36fc0
void Owner::ProcessValuesAndDelete(int argument)
{
    int length = count;
    for (int i = 0; i < length; ++i)
    {
        unsigned short index = values[i];
        if (index != 0xffff)
            handler->process(index, argument);
    }
    delete this;
}

struct S_00d37860_Base
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    bool m_bHit;
    S_00d37860_Base() : m_bHit(false)
    {}
};

struct S_00d37860_Collector : S_00d37860_Base
{
    int m_iFilter;
    S_00d37860_Collector(int filter) : m_iFilter(filter)
    {}
    virtual void f1();
};

void hkpMultiRayConvexAgent_staticGetPenetrations(void* b, void* a, void* c, S_00d37860_Collector* collector);

// Builds a collector from filter and runs FUN_00d374f0 with b, a, c and the collector.
// @fnv 0x00d37860
// src: GUESS 0x00d37860 (confidence: low)
void Object_ProcessState_00d37860(void* a, void* b, void* c, int filter)
{
    S_00d37860_Collector collector(filter);
    hkpMultiRayConvexAgent_staticGetPenetrations(b, a, c, &collector);
}

struct Payload
{
    const char* name;
    float value;
    int id;
};
extern float DAT_0104da48;
extern const char DAT_010ce7fc[];
void hkpMultiRayConvexAgent_staticGetClosestPoints(int, int, int, Payload*);
// Builds a Payload from DAT_010ce7fc, DAT_0104da48 and d, then passes it with b, a and c to FUN_00d37280.
// @fnv 0x00d378a0
// src: GUESS 0x00d378a0 (confidence: low)
void Object_UpdateFields_00d378a0(int aiArg1, int aiArg2, int aiArg3, int aiId)
{
    Payload p;
    p.name = DAT_010ce7fc;
    p.value = DAT_0104da48;
    p.id = aiId;
    hkpMultiRayConvexAgent_staticGetClosestPoints(aiArg2, aiArg1, aiArg3, &p);
}

struct D376B0Allocator;

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(D376B0Allocator* alloc, void* array, int numElements, int sizeElem);

class D376B0ReferencedObject
{
  public:
    D376B0ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

// hkInplaceArray<hkUint16, 4> without a destructor (Havok was built without EH).
struct D376B0IndexArray
{
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned short m_kStorage[4];

    D376B0IndexArray() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000004)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void SetSizeAndGrow(int n)
    {
        D376B0Allocator& alloc = *(D376B0Allocator*)(&hkMemoryRouter_getInstance().heap());
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(unsigned short));
        }
        m_iElementCount = n;
    }
};

struct D376B0Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_numChildren;
};

struct D376B0ShapeRef
{
    D376B0Shape* m_pCollisionShape;
};

class D376B0Filter : public D376B0ReferencedObject
{
  public:
    D376B0Filter(void* userData) : m_ulUserData(userData)
    {}

    void* m_ulUserData;
};

class FUN_00d376b0 : public D376B0Filter
{
  public:
    FUN_00d376b0(const D376B0ShapeRef& shape, void* ReportDiagnostic, void* unused1, void* userData);
    virtual void unk00();

    D376B0IndexArray m_ppIndices;
};

// Constructs a filter from a shape reference, sizing an index array to the shape's child count and filling it with 0xffff.
// @fnv 0x00d376b0
FUN_00d376b0::FUN_00d376b0(const D376B0ShapeRef& shape, void* pUnused, void* unused1, void* userData)
    : D376B0Filter(userData)
{
    int n = shape.m_pCollisionShape->m_numChildren;
    m_ppIndices.SetSizeAndGrow(n);
    for (int i = 0; i < n; i++)
        m_ppIndices.m_data[i] = 0xffff;
}

namespace fnv_00d37740 {
struct S_00d376b0_Class
{
    int unk00;
    short unk04;
    void __thiscall FUN_00d376b0(int a, int b, int c, int d);
};

struct S_00d37740_Interface
{
    virtual void FUN_00d37740_Unknown() = 0;
    virtual S_00d376b0_Class* FUN_00d37740_Method(int a) = 0;
};

hkMemoryRouter* hkMemoryRouter_getInstance();

// @fnv 0x00d37740
// src: HAVOK_LIB 0x00d37740
void hkpMultiRayConvexAgent_createMultiRayConvexAgent(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    hkMemoryRouter* obj = hkMemoryRouter_getInstance();
    S_00d376b0_Class* result = ((S_00d37740_Interface*)(&obj->heap()))->FUN_00d37740_Method(0x20);

    result->unk04 = 0x20;
    result->FUN_00d376b0(aiArg1, aiArg2, aiArg3, aiArg4);
}
}  // namespace fnv_00d37740

namespace fnv_00d37780 {
// FUN_00d37780 - the original returns the freshly allocated object in EAX
// (`mov eax, esi` right before the epilogue), but the unit declares it as
// `void FUN_00d37780(int,int,int,int)`, so the definition carries the real
// return type under a name that still contains the canary tag.
struct Allocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p);
};

hkMemoryRouter* hkMemoryRouter_getInstance();

struct SpawnedObject
{
    virtual ~SpawnedObject()
    {}
    unsigned short m_iElementCount;
};

struct FUN_00d376b0_cls
{
    int unk00;
    void FUN_00d376b0(int a, int b, int c, int d);
};

// @fnv 0x00d37780
// src: GUESS 0x00d37780 (confidence: medium)
void* Object_AllocateStorage_00d37780(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    Allocator* alloc = (Allocator*)(&pAllocHolder->heap());
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x20);
    obj->m_iElementCount = 0x20;
    ((FUN_00d376b0_cls*)obj)->FUN_00d376b0(aiArg2, aiArg1, aiArg3, aiArg4);
    // the original writes the derived vtable pointer into the object here
    obj->SpawnedObject::~SpawnedObject();
    return obj;
}
}  // namespace fnv_00d37780
