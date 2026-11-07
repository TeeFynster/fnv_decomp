#define FNV64_HKVECTOR4_OWN_ASSIGN
#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/agent/miscagent/transform/hkptransformagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/transform/hkptransformagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Retain the unit's SIMD representation: VC9's standard byte-array views add stack cookies.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned int m128_u32[4];
} __m128, LocalM128;
#endif

#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipCollector.h"
#include "../../../../../../../include/hkpSymmetricAgent.h"
#include <new>

// These no-op implementations keep local temporaries free of constructor calls.
__forceinline hkTransform::hkTransform() {}
__forceinline hkVector4::hkVector4() throw() {}
__forceinline void hkVector4::operator=(const hkVector4& vector)
{
    reinterpret_cast<unsigned int*>(this)[0] = reinterpret_cast<const unsigned int*>(&vector)[0];
    reinterpret_cast<unsigned int*>(this)[1] = reinterpret_cast<const unsigned int*>(&vector)[1];
    reinterpret_cast<unsigned int*>(this)[2] = reinterpret_cast<const unsigned int*>(&vector)[2];
    reinterpret_cast<unsigned int*>(this)[3] = reinterpret_cast<const unsigned int*>(&vector)[3];
}
__forceinline hkpCdPointCollector::hkpCdPointCollector() throw() {}

struct CollisionAgentFunctionTable {
    void* f0;
    void* f4;
    void* f8;
    void* fc;
    char f10;
    char f11;
};
struct Agent {
    void AppendRecordAndRegisterAgents(CollisionAgentFunctionTable* af, int a, int b);
};
void __cdecl CreateTransformAgent();
void __cdecl RunCollector();
void __cdecl RunSymmetricAgentFlipCollector();
void __cdecl hkVector4_UpdateState_00d43370();
void __cdecl BuildHeaderAndDispatchHandler();
void __cdecl ProcessTransformShapeCollision();
void __cdecl hkpTransformAgent_staticGetClosestPoints();
void __cdecl DispatchClosestPoints();

// Fills a callback struct with two sets of function pointers and flags and registers each set on self via FUN_00cfbbe0 with ranges (-1,15) and (15,-1).
// @fnv 0x00d43120
void RegisterCallbacks(Agent* pAgent)
{
    CollisionAgentFunctionTable af;
    af.f0 = (void*)&CreateTransformAgent;
    af.f4 = (void*)&RunCollector;
    af.f8 = (void*)&RunSymmetricAgentFlipCollector;
    af.fc = (void*)&hkVector4_UpdateState_00d43370;
    af.f10 = 1;
    af.f11 = 1;
    pAgent->AppendRecordAndRegisterAgents(&af, -1, 15);

    af.f0 = (void*)&BuildHeaderAndDispatchHandler;
    af.f4 = (void*)&ProcessTransformShapeCollision;
    af.f8 = (void*)&hkpTransformAgent_staticGetClosestPoints;
    af.fc = (void*)&DispatchClosestPoints;
    af.f10 = 0;
    af.f11 = 1;
    pAgent->AppendRecordAndRegisterAgents(&af, 15, -1);
}

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10(float a, float b, int c);
};

struct Obj {
    int pad[3];
    Target* m_target;
    int ForwardToTarget(float a, float b, int c);
};

// Calls v10 on m_target with the given float and int arguments and returns its result.
// @fnv 0x00d42a10
int Obj::ForwardToTarget(float a, float b, int c)
{
    return m_target->v10(a, b, c);
}

typedef int (__thiscall *FUN_00d42a60_method)(void*);
struct FUN_00d42a60_vtable {
    FUN_00d42a60_method slot00;
    FUN_00d42a60_method slot04;
    FUN_00d42a60_method slot08;
    FUN_00d42a60_method slot0c;
    FUN_00d42a60_method slot10;
    FUN_00d42a60_method slot14;
    FUN_00d42a60_method slot18;
    FUN_00d42a60_method slot1c;
    FUN_00d42a60_method slot20;
    FUN_00d42a60_method slot24;
    FUN_00d42a60_method slot28;
    FUN_00d42a60_method slot2c;
    FUN_00d42a60_method slot30;
    FUN_00d42a60_method slot34;
};
struct FUN_00d42a60_interface {
    FUN_00d42a60_vtable* vtable;
};
struct FUN_00d42a60_class {
    void* unk00;
    void* unk04;
    void* unk08;
    FUN_00d42a60_interface* unk0c;
    int __thiscall hkpTransformAgent_createZombie();
};
// @fnv 0x00d42a60
// src: HAVOK_LIB 0x00d42a60
int FUN_00d42a60_class::hkpTransformAgent_createZombie() {
    FUN_00d42a60_method method = unk0c->vtable->slot34;
    return method(unk0c);
}

struct Body {
    char pad[0x14];
    int unk14;
    char pad2[0x18];
    hkTransform unk30;
};
struct Source {
    Body* body;
    int unk04;
    const hkTransform* rot;
};
struct Input {
    int unk00;
    int unk04;
    hkTransform* xf;
    Source* src;
};
struct Collector {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int Process(Input* in, int a, int b, int c, int d);
};
struct Caster {
    int unk00;
    int unk04;
    int unk08;
    Collector* coll;
    int ProcessSource(Source* s, int a, int b, int c, int d);
};
// @fnv 0x00d42cf0
int Caster::ProcessSource(Source* pSource, int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    Body* body = pSource->body;
    hkTransform xf;
    xf.hkTransform_setMul(*pSource->rot, body->unk30);
    Input in;
    in.xf = &xf;
    in.src = pSource;
    in.unk00 = body->unk14;
    in.unk04 = 0;
    return coll->Process(&in, aiArg1, aiArg2, aiArg3, aiArg4);
}


struct S_00d42d60_Shape
{
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};

struct S_00d42d60_TransformShape : S_00d42d60_Shape
{
    int unk10;
    S_00d42d60_Shape* m_pContainedShape;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkTransform m_kMotionTransform;
};


#include "../../../../../../../include/hkpCdBody.h"
inline hkpCdBody::hkpCdBody() {}


struct S_00d42d60_Input;
struct S_00d42d60_Collector;

typedef void (__cdecl *S_00d42d60_Func)(const hkpCdBody&, const hkpCdBody&,
                                         const S_00d42d60_Input&, S_00d42d60_Collector*, S_00d42d60_Collector*);

struct S_00d42d60_Funcs
{
    S_00d42d60_Func m_getClosestPoints;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct S_00d42d60_Dispatcher
{
    char unk000[0x1a0];
    unsigned char m_agent2TypeMap[32][32];
    char unk5a0[0x9ac - 0x5a0];
    S_00d42d60_Funcs m_agent2Funcs[64];
};

struct S_00d42d60_Input
{
    S_00d42d60_Dispatcher* m_pCollisionDispatcher;
};


// @fnv 0x00d42d60
void __cdecl DispatchClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                          const S_00d42d60_Input& input, S_00d42d60_Collector* pCollectorA, S_00d42d60_Collector* pCollectorB)
{
    const S_00d42d60_TransformShape* pTransformShape = (const S_00d42d60_TransformShape*)bodyA.m_pCollisionShape;
    __declspec(align(16)) hkTransform t;
    t.hkTransform_setMul(*(const hkTransform*)bodyA.m_pMotionState, pTransformShape->m_kMotionTransform);

    hkpCdBody childBody;
    childBody.m_parent = &bodyA;
    childBody.m_pMotionState = &t;
    childBody.m_pCollisionShape = reinterpret_cast<const hkpShape*>(pTransformShape->m_pContainedShape);
    childBody.m_uiCollisionShapeKey = 0;

    S_00d42d60_Dispatcher* d = input.m_pCollisionDispatcher;
    unsigned char agent = d->m_agent2TypeMap[reinterpret_cast<const S_00d42d60_Shape*>(childBody.m_pCollisionShape)->m_type][reinterpret_cast<const S_00d42d60_Shape*>(bodyB.m_pCollisionShape)->m_type];
    d->m_agent2Funcs[agent].m_getClosestPoints(childBody, bodyB, input, pCollectorA, pCollectorB);
}

namespace fnv_00d42ed0 {
struct Object { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; hkTransform transform; };
struct Input { Object* object; int unk04; hkTransform* transform; };
struct DispatchData { int unk00; int unk04; hkTransform* unk08; Input* unk0c; };
struct Handler { virtual int V0(); virtual int V1(); virtual int V2(); virtual int Dispatch(DispatchData*,int,int,int); };
struct Owner { int a,b,c; Handler* handler; void hkpTransformAgent_getPenetrations(Input*,int,int,int); };
// @fnv 0x00d42ed0
// src: HAVOK_LIB 0x00d42ed0
void Owner::hkpTransformAgent_getPenetrations(Input* input,int aiArg1,int aiArg2,int aiArg3)
{
    Object* object=input->object;
    hkTransform temp;
    temp.hkTransform_setMul(*input->transform, object->transform);
    DispatchData data;
    data.unk08=&temp;
    data.unk0c=input;
    data.unk00=object->unk14;
    data.unk04=0;
    handler->Dispatch(&data,aiArg1,aiArg2,aiArg3);
}
}  // namespace fnv_00d42ed0

namespace fnv_00d42fc0 {
struct Object { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; hkTransform transform; };
struct Input { Object* object; int unk04; hkTransform* transform; };
struct DispatchData { int unk00; int unk04; hkTransform* unk08; Input* unk0c; };
struct Handler {
    virtual int V0(); virtual int V1(); virtual int V2(); virtual int V3();
    virtual int V4(); virtual int V5(); virtual int V6(); virtual int V7();
    virtual int Dispatch(DispatchData*, int, int, int);
};
struct Owner { int unk00; int unk04; int unk08; Handler* handler; int hkpTransformAgent_updateShapeCollectionFilter(Input*, int, int, int); };
// @fnv 0x00d42fc0
// src: HAVOK_LIB 0x00d42fc0
int Owner::hkpTransformAgent_updateShapeCollectionFilter(Input* input, int aiArg1, int aiArg2, int aiArg3)
{
    Object* object = input->object;
    hkTransform temp;
    temp.hkTransform_setMul(*input->transform, object->transform);
    DispatchData data;
    data.unk08 = &temp;
    data.unk0c = input;
    data.unk00 = object->unk14;
    data.unk04 = 0;
    return handler->Dispatch(&data, aiArg1, aiArg2, aiArg3);
}
}  // namespace fnv_00d42fc0

struct D432F0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    bool m_bFound;

    D432F0CollectorBase() : m_bFound(false) {}
};

struct D432F0Collector : D432F0CollectorBase {
    int m_iData;

    D432F0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};

void __cdecl ProcessTransformShapeCollision(int a, int b, int c, D432F0CollectorBase* collector);

// Constructs a D432F0Collector from d and calls ProcessTransformShapeCollision with b, a, c and the collector.
// @fnv 0x00d432f0
void __cdecl RunCollector(int aiArgA, int aiArgB, int aiArgC, int aiData)
{
    D432F0Collector collector(aiData);
    ProcessTransformShapeCollision(aiArgB, aiArgA, aiArgC, &collector);
}

extern float DAT_0104da48;
extern void __cdecl hkpTransformAgent_staticGetClosestPoints(void*, void*, int, void*);

// Builds a local hkpSymmetricAgentFlipCollector from DAT_0104da48 and arg4, then calls FUN_00d42e50 with arg2, arg1, arg3 and the collector.
// @fnv 0x00d43330
void __cdecl RunSymmetricAgentFlipCollector(void* arg1, void* arg2, int arg3, int arg4)
{
    void* storage[3];
    hkpSymmetricAgentFlipCollector& local = *::new (storage) hkpSymmetricAgentFlipCollector;
    local.m_fEarlyOutDistance = DAT_0104da48;
    local.unk08 = reinterpret_cast<void*>(arg4);
    hkpTransformAgent_staticGetClosestPoints(arg2, arg1, arg3, &local);
}

struct CallData { void* descriptor; float bound; unsigned int value; };
extern unsigned char DAT_010ce7fc;
extern float DAT_0104da48;
struct Wrapper {
    void hkpTransformAgent_getClosestPoints(void*, void*, unsigned int, CallData*);
    void UpdateFields_00d434a0(void*, void*, unsigned int, unsigned int);
};
// Builds a CallData from fourth and DAT_0104da48 with descriptor DAT_010ce7fc, then calls FUN_00d42de0 with second, first and third.
// @fnv 0x00d434a0
// src: GUESS 0x00d434a0 (confidence: low)
void Wrapper::UpdateFields_00d434a0(void* first, void* second, unsigned int third, unsigned int fourth) {
    CallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpTransformAgent_getClosestPoints(second, first, third, &data);
}

extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);

extern char DAT_010ce80c[];
extern const __m128 DAT_010c44d0;

struct Input_d43620 {
    int m_auiShapeKeys[20];
    __m128 m_dir;
    int m_pAuxiliaryObject[4];
};

struct Collector_d43620 {
    void* m_vtbl;
    float m_fHitFraction;
    int m_auiShapeKeys[2];
    __declspec(align(16)) hkVector4 m_dir;
    int m_uiFilterValue;

    Collector_d43620* Init(const __m128& dir, int value)
    {
        m_vtbl = DAT_010ce80c;
        m_fHitFraction = 3.40282e+38f;
        m_dir = *(const hkVector4*)&dir;
        m_uiFilterValue = value;
        return this;
    }
};

struct Caster_d43620 {
    int ProcessSource(int a, int b, const Input_d43620* in, Collector_d43620* c, Collector_d43620* c2);
    int ProcessAndReturnValue_00d43620(int a, int b, const Input_d43620* in, int c, int d);
};

// @fnv 0x00d43620
// src: GUESS 0x00d43620 (confidence: low)
int Caster_d43620::ProcessAndReturnValue_00d43620(int aiArg1, int aiArg2, const Input_d43620* apInput, int aiValue1, int aiValue2)
{
    Input_d43620 rev = *apInput;
    rev.m_dir = _mm_xor_ps(apInput->m_dir, DAT_010c44d0);

    Collector_d43620 c1;
    c1.Init(apInput->m_dir, aiValue1);
    Collector_d43620 c2;
    if (aiValue2) { c2.Init(apInput->m_dir, aiValue2); return ProcessSource(aiArg2, aiArg1, &rev, &c1, &c2); }
    return ProcessSource(aiArg2, aiArg1, &rev, &c1, 0);
}

// FUN_00d429c0: thiscall, one stack argument (callee pops 4).
// Forwards the argument to a virtual slot of the member at +0x0c, then
// calls this object's virtual slot 0 (scalar deleting dtor) with flags = 1.

class ForwardTarget {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(unsigned int arg);
};

class ForwardOwner {
public:
    virtual void vDtor(unsigned int flags);
    void hkpTransformAgent_cleanup(unsigned int arg);
    unsigned int unk04;
    unsigned int unk08;
    ForwardTarget* m_0c;
};

// Forwards arg to the target's v1c and then calls the virtual destructor with flags 1.
// @fnv 0x00d429c0
// src: HAVOK_LIB 0x00d429c0
void ForwardOwner::hkpTransformAgent_cleanup(unsigned int arg)
{
    m_0c->v1c(arg);
    vDtor(1);
}

struct DecompTarget {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c(const char* text, void* ctx, int flag);
};

struct DecompOwner {
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;

    int hkpTransformAgent_calcContentStatistics(DecompTarget* target, int unusedArg);
};

// @fnv 0x00d429e0
// src: HAVOK_LIB 0x00d429e0
int DecompOwner::hkpTransformAgent_calcContentStatistics(DecompTarget* target, int unusedArg) {
    return target->v0c("ChildAgent", m_0c, 0);
}

struct S_00d42a40_T {
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
    virtual void v2C(int a);
};

struct S_00d42a40_H {
    int unk00;
    int unk04;
    int unk08;
    S_00d42a40_T* m_0C;
    void hkpTransformAgent_removePoint(int a);
};

// @fnv 0x00d42a40
// src: HAVOK_LIB 0x00d42a40
void S_00d42a40_H::hkpTransformAgent_removePoint(int a) {
    m_0C->v2C(a);
}

struct FnvCpu_FUN_00d42a50_CpuInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d42a50_CpuOwner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d42a50_CpuInterface* target;
    void hkpTransformAgent_commitPotential(int arg0);
};
// @fnv 0x00d42a50
// src: HAVOK_LIB 0x00d42a50
void FnvCpu_FUN_00d42a50_CpuOwner::hkpTransformAgent_commitPotential(int arg0)
{
    target->Invoke(arg0);
}

extern char DAT_010cf280[];
struct Header {
    const char* tag;
    unsigned short byteCount;
    unsigned short format;
    int userValue;
    int result;
};
struct Allocator {
    virtual void* unknown();
    virtual Header* allocate(int size);
};
struct Resource { int unk00;int unk04;int unk08;int unk0c; Allocator* allocator; };
Resource* __cdecl hkMemoryRouter_getInstance();

struct Meta {int unk00; int unk04; int unk08; int sequence;};
struct Root {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    Meta* volatile meta;
    int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
    hkTransform portion30;
};
struct DataHandle{int handle;DataHandle(int n):handle(n) {}};
struct InputA { Root* root; int unk04; int data; };
struct Path {int unk00; int unk04; int unk08; int subIndex;};
struct InputB {Path* path;};
struct InputC {unsigned char* state; int unk04;int unk08;int unk0c;int unk10;int tableFlag;};
__declspec(align(16)) struct WorkArea {
    hkTransform m_kMotionTransform;
    void* entries[28];
    void CopyFrom(struct DataHandle data);
    __forceinline void SetTransformProduct(struct DataHandle data, const hkTransform& transform)
    {
        m_kMotionTransform.hkTransform_setMul(
            *reinterpret_cast<const hkTransform*>(data.handle),
            transform);
    }
};
struct CallbackArgs {
    Meta* meta;
    int zero;
    WorkArea* workspace;
    InputA* source;
};
typedef int (__cdecl *Handler)(CallbackArgs*,InputB*,InputC*,int);
struct HandlerEntry {
    Handler handler;
    int unk04; int unk08; int unk0c; int unk10;
};
// Allocates a 16-byte Header, fills tag/format/userValue, runs workspace setup, selects a handler by kind from a table and stores its return in header->result.
// @fnv 0x00d42a70
Header* __cdecl BuildHeaderAndDispatchHandler(InputA* pSource,InputB* pPathInput,InputC* pStateInput,int value) {
    Resource* resource = hkMemoryRouter_getInstance();
    Header* header = resource->allocator->allocate(16);
    header->byteCount=16;
    header->format=1;
    header->userValue=value;
    header->tag=DAT_010cf280;
    Root* root=pSource->root;
    Meta* meta=root->meta;
    WorkArea workspace;
    workspace.CopyFrom(DataHandle(pSource->data));
    workspace.SetTransformProduct(DataHandle(pSource->data), root->portion30);
    CallbackArgs callbackArgs = {meta,0,&workspace,pSource};
    Path* path=pPathInput->path;
    bool flag=pStateInput->tableFlag!=0;
    unsigned char* data=pStateInput->state;
    int subIndex=path->subIndex;
    int iSequence=meta->sequence;
    unsigned char* pKindTable=flag ? data+0x5a0 : data+0x1a0;
    unsigned char kind=pKindTable[(iSequence<<5)+subIndex];
    Handler handler=((HandlerEntry*)(data+0x9a0))[kind].handler;
    header->result=handler(&callbackArgs,pPathInput,pStateInput,value);
    return header;
}


struct Shape_00d42f40
{
    void* vtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int type;
};

struct TransformShape_00d42f40 : Shape_00d42f40
{
    unsigned int unk10;
    Shape_00d42f40* child;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    hkTransform transform;
};

struct CollisionBody_00d42f40
{
    Shape_00d42f40* shape;
    unsigned int shapeKey;
    const hkTransform* transform;
    const CollisionBody_00d42f40* parent;
};

struct CollisionInput_00d42f40;
typedef void (__cdecl *CollisionFunction_00d42f40)(
    const CollisionBody_00d42f40*, const CollisionBody_00d42f40*,
    const CollisionInput_00d42f40*, void*);

struct AgentFunctions_00d42f40
{
    CollisionFunction_00d42f40 process;
    void* create;
    void* closestPoints;
    void* penetrations;
    void* linearCast;
};

struct Dispatcher_00d42f40
{
    CollisionFunction_00d42f40 getFunction(unsigned int firstType, unsigned int secondType) const
    {
        const unsigned char* storage = reinterpret_cast<const unsigned char*>(this);
        const unsigned int lookupRow = firstType + 13;
        const unsigned int agent = storage[lookupRow * 32 + secondType];
        const AgentFunctions_00d42f40* functions =
            reinterpret_cast<const AgentFunctions_00d42f40*>(storage + 0x9A4);
        return functions[agent].process;
    }
};

struct CollisionInput_00d42f40
{
    const Dispatcher_00d42f40* dispatcher;
};

// Builds a child collision body from the transform shape's child and transform, then dispatches it against the second body via the dispatcher.
// @fnv 0x00d42f40
void __cdecl ProcessTransformShapeCollision(
    const CollisionBody_00d42f40* first,
    const CollisionBody_00d42f40* second,
    const CollisionInput_00d42f40* input,
    void* output)
{
    const TransformShape_00d42f40* shape =
        static_cast<const TransformShape_00d42f40*>(first->shape);
    hkTransform transform;
    transform.hkTransform_setMul(*first->transform, shape->transform);

    CollisionBody_00d42f40 childBody;
    childBody.parent = first;
    childBody.transform = &transform;
    childBody.shape = shape->child;
    childBody.shapeKey = 0;

    input->dispatcher->getFunction(childBody.shape->type, second->shape->type)(
        &childBody, second, input, output);
}

struct CallTarget_00d42fc0 { int hkpTransformAgent_updateShapeCollectionFilter(int, int, int, int); };
struct SearchObject {
    int ProcessAndReturnValue_00d43600(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d43600
// src: GUESS 0x00d43600 (confidence: low)
int SearchObject::ProcessAndReturnValue_00d43600(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiResult = (unsigned int)((CallTarget_00d42fc0*)this)->hkpTransformAgent_updateShapeCollectionFilter((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)uiResult;
}

__declspec(align(16)) struct S_00d431b0_Raw {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
};

struct S_00d431b0_Rows {
    hkVector4 r0;
    hkVector4 r1;
    hkVector4 r2;
    hkVector4 r3;
};

struct S_00d431b0_Blk {
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
};

struct S_00d431b0 {
    S_00d431b0_Rows rows;
    S_00d431b0_Blk blk;
    int u90;
    int u94;
    int u98;
    int u9c;
    float fa0;
    float fa4;
    float fa8;
    char ba;
    char bb;
    char bc;
    S_00d431b0& CopyFrom(const S_00d431b0& o);
};

// Copies the rows, blk, u90-u9c, fa0-fa8 and ba-bc members from o into this object and returns *this.
// @fnv 0x00d431b0
S_00d431b0& S_00d431b0::CopyFrom(const S_00d431b0& aOther) {
    S_00d431b0_Raw t;
    t.u00 = ((const S_00d431b0_Raw*)&aOther.rows)->u00;
    t.u04 = ((const S_00d431b0_Raw*)&aOther.rows)->u04;
    t.u08 = ((const S_00d431b0_Raw*)&aOther.rows)->u08;
    t.u0c = ((const S_00d431b0_Raw*)&aOther.rows)->u0c;
    t.u10 = ((const S_00d431b0_Raw*)&aOther.rows)->u10;
    t.u14 = ((const S_00d431b0_Raw*)&aOther.rows)->u14;
    t.u18 = ((const S_00d431b0_Raw*)&aOther.rows)->u18;
    t.u1c = ((const S_00d431b0_Raw*)&aOther.rows)->u1c;
    t.u20 = ((const S_00d431b0_Raw*)&aOther.rows)->u20;
    t.u24 = ((const S_00d431b0_Raw*)&aOther.rows)->u24;
    t.u28 = ((const S_00d431b0_Raw*)&aOther.rows)->u28;
    t.u2c = ((const S_00d431b0_Raw*)&aOther.rows)->u2c;
    t.u30 = ((const S_00d431b0_Raw*)&aOther.rows)->u30;
    t.u34 = ((const S_00d431b0_Raw*)&aOther.rows)->u34;
    t.u38 = ((const S_00d431b0_Raw*)&aOther.rows)->u38;
    t.u3c = ((const S_00d431b0_Raw*)&aOther.rows)->u3c;
    rows.r0.m_vComponents = ((const S_00d431b0_Rows*)&t)->r0.m_vComponents;
    rows.r1.m_vComponents = ((const S_00d431b0_Rows*)&t)->r1.m_vComponents;
    rows.r2.m_vComponents = ((const S_00d431b0_Rows*)&t)->r2.m_vComponents;
    rows.r3.m_vComponents = ((const S_00d431b0_Rows*)&t)->r3.m_vComponents;
    blk = aOther.blk;
    u90 = aOther.u90;
    u94 = aOther.u94;
    u98 = aOther.u98;
    u9c = aOther.u9c;
    fa0 = aOther.fa0;
    fa4 = aOther.fa4;
    fa8 = aOther.fa8;
    ba = aOther.ba;
    bb = aOther.bb;
    bc = aOther.bc;
    return *this;
}

extern const __m128 DAT_010c4c00;
extern "C" __m128 __cdecl _mm_mul_ps(__m128, __m128);
extern "C" __m128 __cdecl _mm_add_ps(__m128, __m128);
extern "C" __m128 __cdecl _mm_shuffle_ps(__m128, __m128, unsigned int);

// Local inline adapters for vector operations absent from the shared declaration.
__forceinline hkSimdReal::hkSimdReal(const __m128& r) : m_vValue(r) {}
__forceinline hkSimdReal getDistanceSimdReal(const hkVector4& vector) {
    return hkSimdReal(_mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0xff));
}
__forceinline void addMul4(hkVector4& vector, const hkSimdReal& r, const hkVector4& a) {
    vector.m_vComponents = _mm_add_ps(_mm_mul_ps(r.m_vValue, a.m_vComponents), vector.m_vComponents);
}
__forceinline void setNeg3(hkVector4& vector, const hkVector4& a) {
    vector.m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c4c00);
}
__forceinline void setNeg3(hkVector4& vector) {
    vector.m_vComponents = _mm_xor_ps(vector.m_vComponents, DAT_010c4c00);
}

struct __declspec(align(16)) AlignedPairData {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct Features {
    unsigned char a : 4;
    unsigned char b : 4;
    __forceinline void flip() {
        unsigned char t = a;
        a = b;
        b = t;
    }
};
struct ConvexFeaturePairCache {
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    Features m_features;
    unsigned char m_auiShapeKeys;
    __forceinline void flip() {

        unsigned char t = m_features.a;
        m_features.a = m_features.b;
        unsigned char dimA;
        m_features.b = t;
        dimA = m_ucDimensionA;

        unsigned char dimB = m_ucDimensionB;
        m_ucDimensionB = dimA;
        m_ucDimensionA = dimB;

        int idx = (int)dimB + (int)dimA - 1;
        unsigned short v0 = m_kVertices[0];
        m_kVertices[0] = m_kVertices[idx];
        m_kVertices[idx] = v0;

        if ((m_ucDimensionA & m_ucDimensionB) == 2) {
            unsigned short v1 = m_kVertices[1];
            m_kVertices[1] = m_kVertices[2];
            m_kVertices[2] = v1;
        }

    }
};

struct __declspec(align(16)) CollisionCacheState {
    hkVector4 m_vSeparatingNormal;
    float m_uiCommandId;
    int unk3034;
    int unk3038;
    int unk303c;
    ConvexFeaturePairCache m_kGskCache;
    __forceinline void flip() {
        setNeg3(m_vSeparatingNormal);
        m_kGskCache.flip();
    }
};

struct Output {
    AlignedPairData* m_pAlignedPairData;
    int unk0004; int unk0008; int unk000c; int unk0010; int unk0014; int unk0018; int unk001c; int unk0020; int unk0024; int unk0028;
    int unk002c; int unk0030; int unk0034; int unk0038; int unk003c; int unk0040; int unk0044; int unk0048; int unk004c; int unk0050;
    int unk0054; int unk0058; int unk005c; int unk0060; int unk0064; int unk0068; int unk006c; int unk0070; int unk0074; int unk0078;
    int unk007c; int unk0080; int unk0084; int unk0088; int unk008c; int unk0090; int unk0094; int unk0098; int unk009c; int unk00a0;
    int unk00a4; int unk00a8; int unk00ac; int unk00b0; int unk00b4; int unk00b8; int unk00bc; int unk00c0; int unk00c4; int unk00c8;
    int unk00cc; int unk00d0; int unk00d4; int unk00d8; int unk00dc; int unk00e0; int unk00e4; int unk00e8; int unk00ec; int unk00f0;
    int unk00f4; int unk00f8; int unk00fc; int unk0100; int unk0104; int unk0108; int unk010c; int unk0110; int unk0114; int unk0118;
    int unk011c; int unk0120; int unk0124; int unk0128; int unk012c; int unk0130; int unk0134; int unk0138; int unk013c; int unk0140;
    int unk0144; int unk0148; int unk014c; int unk0150; int unk0154; int unk0158; int unk015c; int unk0160; int unk0164; int unk0168;
    int unk016c; int unk0170; int unk0174; int unk0178; int unk017c; int unk0180; int unk0184; int unk0188; int unk018c; int unk0190;
    int unk0194; int unk0198; int unk019c; int unk01a0; int unk01a4; int unk01a8; int unk01ac; int unk01b0; int unk01b4; int unk01b8;
    int unk01bc; int unk01c0; int unk01c4; int unk01c8; int unk01cc; int unk01d0; int unk01d4; int unk01d8; int unk01dc; int unk01e0;
    int unk01e4; int unk01e8; int unk01ec; int unk01f0; int unk01f4; int unk01f8; int unk01fc; int unk0200; int unk0204; int unk0208;
    int unk020c; int unk0210; int unk0214; int unk0218; int unk021c; int unk0220; int unk0224; int unk0228; int unk022c; int unk0230;
    int unk0234; int unk0238; int unk023c; int unk0240; int unk0244; int unk0248; int unk024c; int unk0250; int unk0254; int unk0258;
    int unk025c; int unk0260; int unk0264; int unk0268; int unk026c; int unk0270; int unk0274; int unk0278; int unk027c; int unk0280;
    int unk0284; int unk0288; int unk028c; int unk0290; int unk0294; int unk0298; int unk029c; int unk02a0; int unk02a4; int unk02a8;
    int unk02ac; int unk02b0; int unk02b4; int unk02b8; int unk02bc; int unk02c0; int unk02c4; int unk02c8; int unk02cc; int unk02d0;
    int unk02d4; int unk02d8; int unk02dc; int unk02e0; int unk02e4; int unk02e8; int unk02ec; int unk02f0; int unk02f4; int unk02f8;
    int unk02fc; int unk0300; int unk0304; int unk0308; int unk030c; int unk0310; int unk0314; int unk0318; int unk031c; int unk0320;
    int unk0324; int unk0328; int unk032c; int unk0330; int unk0334; int unk0338; int unk033c; int unk0340; int unk0344; int unk0348;
    int unk034c; int unk0350; int unk0354; int unk0358; int unk035c; int unk0360; int unk0364; int unk0368; int unk036c; int unk0370;
    int unk0374; int unk0378; int unk037c; int unk0380; int unk0384; int unk0388; int unk038c; int unk0390; int unk0394; int unk0398;
    int unk039c; int unk03a0; int unk03a4; int unk03a8; int unk03ac; int unk03b0; int unk03b4; int unk03b8; int unk03bc; int unk03c0;
    int unk03c4; int unk03c8; int unk03cc; int unk03d0; int unk03d4; int unk03d8; int unk03dc; int unk03e0; int unk03e4; int unk03e8;
    int unk03ec; int unk03f0; int unk03f4; int unk03f8; int unk03fc; int unk0400; int unk0404; int unk0408; int unk040c; int unk0410;
    int unk0414; int unk0418; int unk041c; int unk0420; int unk0424; int unk0428; int unk042c; int unk0430; int unk0434; int unk0438;
    int unk043c; int unk0440; int unk0444; int unk0448; int unk044c; int unk0450; int unk0454; int unk0458; int unk045c; int unk0460;
    int unk0464; int unk0468; int unk046c; int unk0470; int unk0474; int unk0478; int unk047c; int unk0480; int unk0484; int unk0488;
    int unk048c; int unk0490; int unk0494; int unk0498; int unk049c; int unk04a0; int unk04a4; int unk04a8; int unk04ac; int unk04b0;
    int unk04b4; int unk04b8; int unk04bc; int unk04c0; int unk04c4; int unk04c8; int unk04cc; int unk04d0; int unk04d4; int unk04d8;
    int unk04dc; int unk04e0; int unk04e4; int unk04e8; int unk04ec; int unk04f0; int unk04f4; int unk04f8; int unk04fc; int unk0500;
    int unk0504; int unk0508; int unk050c; int unk0510; int unk0514; int unk0518; int unk051c; int unk0520; int unk0524; int unk0528;
    int unk052c; int unk0530; int unk0534; int unk0538; int unk053c; int unk0540; int unk0544; int unk0548; int unk054c; int unk0550;
    int unk0554; int unk0558; int unk055c; int unk0560; int unk0564; int unk0568; int unk056c; int unk0570; int unk0574; int unk0578;
    int unk057c; int unk0580; int unk0584; int unk0588; int unk058c; int unk0590; int unk0594; int unk0598; int unk059c; int unk05a0;
    int unk05a4; int unk05a8; int unk05ac; int unk05b0; int unk05b4; int unk05b8; int unk05bc; int unk05c0; int unk05c4; int unk05c8;
    int unk05cc; int unk05d0; int unk05d4; int unk05d8; int unk05dc; int unk05e0; int unk05e4; int unk05e8; int unk05ec; int unk05f0;
    int unk05f4; int unk05f8; int unk05fc; int unk0600; int unk0604; int unk0608; int unk060c; int unk0610; int unk0614; int unk0618;
    int unk061c; int unk0620; int unk0624; int unk0628; int unk062c; int unk0630; int unk0634; int unk0638; int unk063c; int unk0640;
    int unk0644; int unk0648; int unk064c; int unk0650; int unk0654; int unk0658; int unk065c; int unk0660; int unk0664; int unk0668;
    int unk066c; int unk0670; int unk0674; int unk0678; int unk067c; int unk0680; int unk0684; int unk0688; int unk068c; int unk0690;
    int unk0694; int unk0698; int unk069c; int unk06a0; int unk06a4; int unk06a8; int unk06ac; int unk06b0; int unk06b4; int unk06b8;
    int unk06bc; int unk06c0; int unk06c4; int unk06c8; int unk06cc; int unk06d0; int unk06d4; int unk06d8; int unk06dc; int unk06e0;
    int unk06e4; int unk06e8; int unk06ec; int unk06f0; int unk06f4; int unk06f8; int unk06fc; int unk0700; int unk0704; int unk0708;
    int unk070c; int unk0710; int unk0714; int unk0718; int unk071c; int unk0720; int unk0724; int unk0728; int unk072c; int unk0730;
    int unk0734; int unk0738; int unk073c; int unk0740; int unk0744; int unk0748; int unk074c; int unk0750; int unk0754; int unk0758;
    int unk075c; int unk0760; int unk0764; int unk0768; int unk076c; int unk0770; int unk0774; int unk0778; int unk077c; int unk0780;
    int unk0784; int unk0788; int unk078c; int unk0790; int unk0794; int unk0798; int unk079c; int unk07a0; int unk07a4; int unk07a8;
    int unk07ac; int unk07b0; int unk07b4; int unk07b8; int unk07bc; int unk07c0; int unk07c4; int unk07c8; int unk07cc; int unk07d0;
    int unk07d4; int unk07d8; int unk07dc; int unk07e0; int unk07e4; int unk07e8; int unk07ec; int unk07f0; int unk07f4; int unk07f8;
    int unk07fc; int unk0800; int unk0804; int unk0808; int unk080c; int unk0810; int unk0814; int unk0818; int unk081c; int unk0820;
    int unk0824; int unk0828; int unk082c; int unk0830; int unk0834; int unk0838; int unk083c; int unk0840; int unk0844; int unk0848;
    int unk084c; int unk0850; int unk0854; int unk0858; int unk085c; int unk0860; int unk0864; int unk0868; int unk086c; int unk0870;
    int unk0874; int unk0878; int unk087c; int unk0880; int unk0884; int unk0888; int unk088c; int unk0890; int unk0894; int unk0898;
    int unk089c; int unk08a0; int unk08a4; int unk08a8; int unk08ac; int unk08b0; int unk08b4; int unk08b8; int unk08bc; int unk08c0;
    int unk08c4; int unk08c8; int unk08cc; int unk08d0; int unk08d4; int unk08d8; int unk08dc; int unk08e0; int unk08e4; int unk08e8;
    int unk08ec; int unk08f0; int unk08f4; int unk08f8; int unk08fc; int unk0900; int unk0904; int unk0908; int unk090c; int unk0910;
    int unk0914; int unk0918; int unk091c; int unk0920; int unk0924; int unk0928; int unk092c; int unk0930; int unk0934; int unk0938;
    int unk093c; int unk0940; int unk0944; int unk0948; int unk094c; int unk0950; int unk0954; int unk0958; int unk095c; int unk0960;
    int unk0964; int unk0968; int unk096c; int unk0970; int unk0974; int unk0978; int unk097c; int unk0980; int unk0984; int unk0988;
    int unk098c; int unk0990; int unk0994; int unk0998; int unk099c; int unk09a0; int unk09a4; int unk09a8; int unk09ac; int unk09b0;
    int unk09b4; int unk09b8; int unk09bc; int unk09c0; int unk09c4; int unk09c8; int unk09cc; int unk09d0; int unk09d4; int unk09d8;
    int unk09dc; int unk09e0; int unk09e4; int unk09e8; int unk09ec; int unk09f0; int unk09f4; int unk09f8; int unk09fc; int unk0a00;
    int unk0a04; int unk0a08; int unk0a0c; int unk0a10; int unk0a14; int unk0a18; int unk0a1c; int unk0a20; int unk0a24; int unk0a28;
    int unk0a2c; int unk0a30; int unk0a34; int unk0a38; int unk0a3c; int unk0a40; int unk0a44; int unk0a48; int unk0a4c; int unk0a50;
    int unk0a54; int unk0a58; int unk0a5c; int unk0a60; int unk0a64; int unk0a68; int unk0a6c; int unk0a70; int unk0a74; int unk0a78;
    int unk0a7c; int unk0a80; int unk0a84; int unk0a88; int unk0a8c; int unk0a90; int unk0a94; int unk0a98; int unk0a9c; int unk0aa0;
    int unk0aa4; int unk0aa8; int unk0aac; int unk0ab0; int unk0ab4; int unk0ab8; int unk0abc; int unk0ac0; int unk0ac4; int unk0ac8;
    int unk0acc; int unk0ad0; int unk0ad4; int unk0ad8; int unk0adc; int unk0ae0; int unk0ae4; int unk0ae8; int unk0aec; int unk0af0;
    int unk0af4; int unk0af8; int unk0afc; int unk0b00; int unk0b04; int unk0b08; int unk0b0c; int unk0b10; int unk0b14; int unk0b18;
    int unk0b1c; int unk0b20; int unk0b24; int unk0b28; int unk0b2c; int unk0b30; int unk0b34; int unk0b38; int unk0b3c; int unk0b40;
    int unk0b44; int unk0b48; int unk0b4c; int unk0b50; int unk0b54; int unk0b58; int unk0b5c; int unk0b60; int unk0b64; int unk0b68;
    int unk0b6c; int unk0b70; int unk0b74; int unk0b78; int unk0b7c; int unk0b80; int unk0b84; int unk0b88; int unk0b8c; int unk0b90;
    int unk0b94; int unk0b98; int unk0b9c; int unk0ba0; int unk0ba4; int unk0ba8; int unk0bac; int unk0bb0; int unk0bb4; int unk0bb8;
    int unk0bbc; int unk0bc0; int unk0bc4; int unk0bc8; int unk0bcc; int unk0bd0; int unk0bd4; int unk0bd8; int unk0bdc; int unk0be0;
    int unk0be4; int unk0be8; int unk0bec; int unk0bf0; int unk0bf4; int unk0bf8; int unk0bfc; int unk0c00; int unk0c04; int unk0c08;
    int unk0c0c; int unk0c10; int unk0c14; int unk0c18; int unk0c1c; int unk0c20; int unk0c24; int unk0c28; int unk0c2c; int unk0c30;
    int unk0c34; int unk0c38; int unk0c3c; int unk0c40; int unk0c44; int unk0c48; int unk0c4c; int unk0c50; int unk0c54; int unk0c58;
    int unk0c5c; int unk0c60; int unk0c64; int unk0c68; int unk0c6c; int unk0c70; int unk0c74; int unk0c78; int unk0c7c; int unk0c80;
    int unk0c84; int unk0c88; int unk0c8c; int unk0c90; int unk0c94; int unk0c98; int unk0c9c; int unk0ca0; int unk0ca4; int unk0ca8;
    int unk0cac; int unk0cb0; int unk0cb4; int unk0cb8; int unk0cbc; int unk0cc0; int unk0cc4; int unk0cc8; int unk0ccc; int unk0cd0;
    int unk0cd4; int unk0cd8; int unk0cdc; int unk0ce0; int unk0ce4; int unk0ce8; int unk0cec; int unk0cf0; int unk0cf4; int unk0cf8;
    int unk0cfc; int unk0d00; int unk0d04; int unk0d08; int unk0d0c; int unk0d10; int unk0d14; int unk0d18; int unk0d1c; int unk0d20;
    int unk0d24; int unk0d28; int unk0d2c; int unk0d30; int unk0d34; int unk0d38; int unk0d3c; int unk0d40; int unk0d44; int unk0d48;
    int unk0d4c; int unk0d50; int unk0d54; int unk0d58; int unk0d5c; int unk0d60; int unk0d64; int unk0d68; int unk0d6c; int unk0d70;
    int unk0d74; int unk0d78; int unk0d7c; int unk0d80; int unk0d84; int unk0d88; int unk0d8c; int unk0d90; int unk0d94; int unk0d98;
    int unk0d9c; int unk0da0; int unk0da4; int unk0da8; int unk0dac; int unk0db0; int unk0db4; int unk0db8; int unk0dbc; int unk0dc0;
    int unk0dc4; int unk0dc8; int unk0dcc; int unk0dd0; int unk0dd4; int unk0dd8; int unk0ddc; int unk0de0; int unk0de4; int unk0de8;
    int unk0dec; int unk0df0; int unk0df4; int unk0df8; int unk0dfc; int unk0e00; int unk0e04; int unk0e08; int unk0e0c; int unk0e10;
    int unk0e14; int unk0e18; int unk0e1c; int unk0e20; int unk0e24; int unk0e28; int unk0e2c; int unk0e30; int unk0e34; int unk0e38;
    int unk0e3c; int unk0e40; int unk0e44; int unk0e48; int unk0e4c; int unk0e50; int unk0e54; int unk0e58; int unk0e5c; int unk0e60;
    int unk0e64; int unk0e68; int unk0e6c; int unk0e70; int unk0e74; int unk0e78; int unk0e7c; int unk0e80; int unk0e84; int unk0e88;
    int unk0e8c; int unk0e90; int unk0e94; int unk0e98; int unk0e9c; int unk0ea0; int unk0ea4; int unk0ea8; int unk0eac; int unk0eb0;
    int unk0eb4; int unk0eb8; int unk0ebc; int unk0ec0; int unk0ec4; int unk0ec8; int unk0ecc; int unk0ed0; int unk0ed4; int unk0ed8;
    int unk0edc; int unk0ee0; int unk0ee4; int unk0ee8; int unk0eec; int unk0ef0; int unk0ef4; int unk0ef8; int unk0efc; int unk0f00;
    int unk0f04; int unk0f08; int unk0f0c; int unk0f10; int unk0f14; int unk0f18; int unk0f1c; int unk0f20; int unk0f24; int unk0f28;
    int unk0f2c; int unk0f30; int unk0f34; int unk0f38; int unk0f3c; int unk0f40; int unk0f44; int unk0f48; int unk0f4c; int unk0f50;
    int unk0f54; int unk0f58; int unk0f5c; int unk0f60; int unk0f64; int unk0f68; int unk0f6c; int unk0f70; int unk0f74; int unk0f78;
    int unk0f7c; int unk0f80; int unk0f84; int unk0f88; int unk0f8c; int unk0f90; int unk0f94; int unk0f98; int unk0f9c; int unk0fa0;
    int unk0fa4; int unk0fa8; int unk0fac; int unk0fb0; int unk0fb4; int unk0fb8; int unk0fbc; int unk0fc0; int unk0fc4; int unk0fc8;
    int unk0fcc; int unk0fd0; int unk0fd4; int unk0fd8; int unk0fdc; int unk0fe0; int unk0fe4; int unk0fe8; int unk0fec; int unk0ff0;
    int unk0ff4; int unk0ff8; int unk0ffc; int unk1000; int unk1004; int unk1008; int unk100c; int unk1010; int unk1014; int unk1018;
    int unk101c; int unk1020; int unk1024; int unk1028; int unk102c; int unk1030; int unk1034; int unk1038; int unk103c; int unk1040;
    int unk1044; int unk1048; int unk104c; int unk1050; int unk1054; int unk1058; int unk105c; int unk1060; int unk1064; int unk1068;
    int unk106c; int unk1070; int unk1074; int unk1078; int unk107c; int unk1080; int unk1084; int unk1088; int unk108c; int unk1090;
    int unk1094; int unk1098; int unk109c; int unk10a0; int unk10a4; int unk10a8; int unk10ac; int unk10b0; int unk10b4; int unk10b8;
    int unk10bc; int unk10c0; int unk10c4; int unk10c8; int unk10cc; int unk10d0; int unk10d4; int unk10d8; int unk10dc; int unk10e0;
    int unk10e4; int unk10e8; int unk10ec; int unk10f0; int unk10f4; int unk10f8; int unk10fc; int unk1100; int unk1104; int unk1108;
    int unk110c; int unk1110; int unk1114; int unk1118; int unk111c; int unk1120; int unk1124; int unk1128; int unk112c; int unk1130;
    int unk1134; int unk1138; int unk113c; int unk1140; int unk1144; int unk1148; int unk114c; int unk1150; int unk1154; int unk1158;
    int unk115c; int unk1160; int unk1164; int unk1168; int unk116c; int unk1170; int unk1174; int unk1178; int unk117c; int unk1180;
    int unk1184; int unk1188; int unk118c; int unk1190; int unk1194; int unk1198; int unk119c; int unk11a0; int unk11a4; int unk11a8;
    int unk11ac; int unk11b0; int unk11b4; int unk11b8; int unk11bc; int unk11c0; int unk11c4; int unk11c8; int unk11cc; int unk11d0;
    int unk11d4; int unk11d8; int unk11dc; int unk11e0; int unk11e4; int unk11e8; int unk11ec; int unk11f0; int unk11f4; int unk11f8;
    int unk11fc; int unk1200; int unk1204; int unk1208; int unk120c; int unk1210; int unk1214; int unk1218; int unk121c; int unk1220;
    int unk1224; int unk1228; int unk122c; int unk1230; int unk1234; int unk1238; int unk123c; int unk1240; int unk1244; int unk1248;
    int unk124c; int unk1250; int unk1254; int unk1258; int unk125c; int unk1260; int unk1264; int unk1268; int unk126c; int unk1270;
    int unk1274; int unk1278; int unk127c; int unk1280; int unk1284; int unk1288; int unk128c; int unk1290; int unk1294; int unk1298;
    int unk129c; int unk12a0; int unk12a4; int unk12a8; int unk12ac; int unk12b0; int unk12b4; int unk12b8; int unk12bc; int unk12c0;
    int unk12c4; int unk12c8; int unk12cc; int unk12d0; int unk12d4; int unk12d8; int unk12dc; int unk12e0; int unk12e4; int unk12e8;
    int unk12ec; int unk12f0; int unk12f4; int unk12f8; int unk12fc; int unk1300; int unk1304; int unk1308; int unk130c; int unk1310;
    int unk1314; int unk1318; int unk131c; int unk1320; int unk1324; int unk1328; int unk132c; int unk1330; int unk1334; int unk1338;
    int unk133c; int unk1340; int unk1344; int unk1348; int unk134c; int unk1350; int unk1354; int unk1358; int unk135c; int unk1360;
    int unk1364; int unk1368; int unk136c; int unk1370; int unk1374; int unk1378; int unk137c; int unk1380; int unk1384; int unk1388;
    int unk138c; int unk1390; int unk1394; int unk1398; int unk139c; int unk13a0; int unk13a4; int unk13a8; int unk13ac; int unk13b0;
    int unk13b4; int unk13b8; int unk13bc; int unk13c0; int unk13c4; int unk13c8; int unk13cc; int unk13d0; int unk13d4; int unk13d8;
    int unk13dc; int unk13e0; int unk13e4; int unk13e8; int unk13ec; int unk13f0; int unk13f4; int unk13f8; int unk13fc; int unk1400;
    int unk1404; int unk1408; int unk140c; int unk1410; int unk1414; int unk1418; int unk141c; int unk1420; int unk1424; int unk1428;
    int unk142c; int unk1430; int unk1434; int unk1438; int unk143c; int unk1440; int unk1444; int unk1448; int unk144c; int unk1450;
    int unk1454; int unk1458; int unk145c; int unk1460; int unk1464; int unk1468; int unk146c; int unk1470; int unk1474; int unk1478;
    int unk147c; int unk1480; int unk1484; int unk1488; int unk148c; int unk1490; int unk1494; int unk1498; int unk149c; int unk14a0;
    int unk14a4; int unk14a8; int unk14ac; int unk14b0; int unk14b4; int unk14b8; int unk14bc; int unk14c0; int unk14c4; int unk14c8;
    int unk14cc; int unk14d0; int unk14d4; int unk14d8; int unk14dc; int unk14e0; int unk14e4; int unk14e8; int unk14ec; int unk14f0;
    int unk14f4; int unk14f8; int unk14fc; int unk1500; int unk1504; int unk1508; int unk150c; int unk1510; int unk1514; int unk1518;
    int unk151c; int unk1520; int unk1524; int unk1528; int unk152c; int unk1530; int unk1534; int unk1538; int unk153c; int unk1540;
    int unk1544; int unk1548; int unk154c; int unk1550; int unk1554; int unk1558; int unk155c; int unk1560; int unk1564; int unk1568;
    int unk156c; int unk1570; int unk1574; int unk1578; int unk157c; int unk1580; int unk1584; int unk1588; int unk158c; int unk1590;
    int unk1594; int unk1598; int unk159c; int unk15a0; int unk15a4; int unk15a8; int unk15ac; int unk15b0; int unk15b4; int unk15b8;
    int unk15bc; int unk15c0; int unk15c4; int unk15c8; int unk15cc; int unk15d0; int unk15d4; int unk15d8; int unk15dc; int unk15e0;
    int unk15e4; int unk15e8; int unk15ec; int unk15f0; int unk15f4; int unk15f8; int unk15fc; int unk1600; int unk1604; int unk1608;
    int unk160c; int unk1610; int unk1614; int unk1618; int unk161c; int unk1620; int unk1624; int unk1628; int unk162c; int unk1630;
    int unk1634; int unk1638; int unk163c; int unk1640; int unk1644; int unk1648; int unk164c; int unk1650; int unk1654; int unk1658;
    int unk165c; int unk1660; int unk1664; int unk1668; int unk166c; int unk1670; int unk1674; int unk1678; int unk167c; int unk1680;
    int unk1684; int unk1688; int unk168c; int unk1690; int unk1694; int unk1698; int unk169c; int unk16a0; int unk16a4; int unk16a8;
    int unk16ac; int unk16b0; int unk16b4; int unk16b8; int unk16bc; int unk16c0; int unk16c4; int unk16c8; int unk16cc; int unk16d0;
    int unk16d4; int unk16d8; int unk16dc; int unk16e0; int unk16e4; int unk16e8; int unk16ec; int unk16f0; int unk16f4; int unk16f8;
    int unk16fc; int unk1700; int unk1704; int unk1708; int unk170c; int unk1710; int unk1714; int unk1718; int unk171c; int unk1720;
    int unk1724; int unk1728; int unk172c; int unk1730; int unk1734; int unk1738; int unk173c; int unk1740; int unk1744; int unk1748;
    int unk174c; int unk1750; int unk1754; int unk1758; int unk175c; int unk1760; int unk1764; int unk1768; int unk176c; int unk1770;
    int unk1774; int unk1778; int unk177c; int unk1780; int unk1784; int unk1788; int unk178c; int unk1790; int unk1794; int unk1798;
    int unk179c; int unk17a0; int unk17a4; int unk17a8; int unk17ac; int unk17b0; int unk17b4; int unk17b8; int unk17bc; int unk17c0;
    int unk17c4; int unk17c8; int unk17cc; int unk17d0; int unk17d4; int unk17d8; int unk17dc; int unk17e0; int unk17e4; int unk17e8;
    int unk17ec; int unk17f0; int unk17f4; int unk17f8; int unk17fc; int unk1800; int unk1804; int unk1808; int unk180c; int unk1810;
    int unk1814; int unk1818; int unk181c; int unk1820; int unk1824; int unk1828; int unk182c; int unk1830; int unk1834; int unk1838;
    int unk183c; int unk1840; int unk1844; int unk1848; int unk184c; int unk1850; int unk1854; int unk1858; int unk185c; int unk1860;
    int unk1864; int unk1868; int unk186c; int unk1870; int unk1874; int unk1878; int unk187c; int unk1880; int unk1884; int unk1888;
    int unk188c; int unk1890; int unk1894; int unk1898; int unk189c; int unk18a0; int unk18a4; int unk18a8; int unk18ac; int unk18b0;
    int unk18b4; int unk18b8; int unk18bc; int unk18c0; int unk18c4; int unk18c8; int unk18cc; int unk18d0; int unk18d4; int unk18d8;
    int unk18dc; int unk18e0; int unk18e4; int unk18e8; int unk18ec; int unk18f0; int unk18f4; int unk18f8; int unk18fc; int unk1900;
    int unk1904; int unk1908; int unk190c; int unk1910; int unk1914; int unk1918; int unk191c; int unk1920; int unk1924; int unk1928;
    int unk192c; int unk1930; int unk1934; int unk1938; int unk193c; int unk1940; int unk1944; int unk1948; int unk194c; int unk1950;
    int unk1954; int unk1958; int unk195c; int unk1960; int unk1964; int unk1968; int unk196c; int unk1970; int unk1974; int unk1978;
    int unk197c; int unk1980; int unk1984; int unk1988; int unk198c; int unk1990; int unk1994; int unk1998; int unk199c; int unk19a0;
    int unk19a4; int unk19a8; int unk19ac; int unk19b0; int unk19b4; int unk19b8; int unk19bc; int unk19c0; int unk19c4; int unk19c8;
    int unk19cc; int unk19d0; int unk19d4; int unk19d8; int unk19dc; int unk19e0; int unk19e4; int unk19e8; int unk19ec; int unk19f0;
    int unk19f4; int unk19f8; int unk19fc; int unk1a00; int unk1a04; int unk1a08; int unk1a0c; int unk1a10; int unk1a14; int unk1a18;
    int unk1a1c; int unk1a20; int unk1a24; int unk1a28; int unk1a2c; int unk1a30; int unk1a34; int unk1a38; int unk1a3c; int unk1a40;
    int unk1a44; int unk1a48; int unk1a4c; int unk1a50; int unk1a54; int unk1a58; int unk1a5c; int unk1a60; int unk1a64; int unk1a68;
    int unk1a6c; int unk1a70; int unk1a74; int unk1a78; int unk1a7c; int unk1a80; int unk1a84; int unk1a88; int unk1a8c; int unk1a90;
    int unk1a94; int unk1a98; int unk1a9c; int unk1aa0; int unk1aa4; int unk1aa8; int unk1aac; int unk1ab0; int unk1ab4; int unk1ab8;
    int unk1abc; int unk1ac0; int unk1ac4; int unk1ac8; int unk1acc; int unk1ad0; int unk1ad4; int unk1ad8; int unk1adc; int unk1ae0;
    int unk1ae4; int unk1ae8; int unk1aec; int unk1af0; int unk1af4; int unk1af8; int unk1afc; int unk1b00; int unk1b04; int unk1b08;
    int unk1b0c; int unk1b10; int unk1b14; int unk1b18; int unk1b1c; int unk1b20; int unk1b24; int unk1b28; int unk1b2c; int unk1b30;
    int unk1b34; int unk1b38; int unk1b3c; int unk1b40; int unk1b44; int unk1b48; int unk1b4c; int unk1b50; int unk1b54; int unk1b58;
    int unk1b5c; int unk1b60; int unk1b64; int unk1b68; int unk1b6c; int unk1b70; int unk1b74; int unk1b78; int unk1b7c; int unk1b80;
    int unk1b84; int unk1b88; int unk1b8c; int unk1b90; int unk1b94; int unk1b98; int unk1b9c; int unk1ba0; int unk1ba4; int unk1ba8;
    int unk1bac; int unk1bb0; int unk1bb4; int unk1bb8; int unk1bbc; int unk1bc0; int unk1bc4; int unk1bc8; int unk1bcc; int unk1bd0;
    int unk1bd4; int unk1bd8; int unk1bdc; int unk1be0; int unk1be4; int unk1be8; int unk1bec; int unk1bf0; int unk1bf4; int unk1bf8;
    int unk1bfc; int unk1c00; int unk1c04; int unk1c08; int unk1c0c; int unk1c10; int unk1c14; int unk1c18; int unk1c1c; int unk1c20;
    int unk1c24; int unk1c28; int unk1c2c; int unk1c30; int unk1c34; int unk1c38; int unk1c3c; int unk1c40; int unk1c44; int unk1c48;
    int unk1c4c; int unk1c50; int unk1c54; int unk1c58; int unk1c5c; int unk1c60; int unk1c64; int unk1c68; int unk1c6c; int unk1c70;
    int unk1c74; int unk1c78; int unk1c7c; int unk1c80; int unk1c84; int unk1c88; int unk1c8c; int unk1c90; int unk1c94; int unk1c98;
    int unk1c9c; int unk1ca0; int unk1ca4; int unk1ca8; int unk1cac; int unk1cb0; int unk1cb4; int unk1cb8; int unk1cbc; int unk1cc0;
    int unk1cc4; int unk1cc8; int unk1ccc; int unk1cd0; int unk1cd4; int unk1cd8; int unk1cdc; int unk1ce0; int unk1ce4; int unk1ce8;
    int unk1cec; int unk1cf0; int unk1cf4; int unk1cf8; int unk1cfc; int unk1d00; int unk1d04; int unk1d08; int unk1d0c; int unk1d10;
    int unk1d14; int unk1d18; int unk1d1c; int unk1d20; int unk1d24; int unk1d28; int unk1d2c; int unk1d30; int unk1d34; int unk1d38;
    int unk1d3c; int unk1d40; int unk1d44; int unk1d48; int unk1d4c; int unk1d50; int unk1d54; int unk1d58; int unk1d5c; int unk1d60;
    int unk1d64; int unk1d68; int unk1d6c; int unk1d70; int unk1d74; int unk1d78; int unk1d7c; int unk1d80; int unk1d84; int unk1d88;
    int unk1d8c; int unk1d90; int unk1d94; int unk1d98; int unk1d9c; int unk1da0; int unk1da4; int unk1da8; int unk1dac; int unk1db0;
    int unk1db4; int unk1db8; int unk1dbc; int unk1dc0; int unk1dc4; int unk1dc8; int unk1dcc; int unk1dd0; int unk1dd4; int unk1dd8;
    int unk1ddc; int unk1de0; int unk1de4; int unk1de8; int unk1dec; int unk1df0; int unk1df4; int unk1df8; int unk1dfc; int unk1e00;
    int unk1e04; int unk1e08; int unk1e0c; int unk1e10; int unk1e14; int unk1e18; int unk1e1c; int unk1e20; int unk1e24; int unk1e28;
    int unk1e2c; int unk1e30; int unk1e34; int unk1e38; int unk1e3c; int unk1e40; int unk1e44; int unk1e48; int unk1e4c; int unk1e50;
    int unk1e54; int unk1e58; int unk1e5c; int unk1e60; int unk1e64; int unk1e68; int unk1e6c; int unk1e70; int unk1e74; int unk1e78;
    int unk1e7c; int unk1e80; int unk1e84; int unk1e88; int unk1e8c; int unk1e90; int unk1e94; int unk1e98; int unk1e9c; int unk1ea0;
    int unk1ea4; int unk1ea8; int unk1eac; int unk1eb0; int unk1eb4; int unk1eb8; int unk1ebc; int unk1ec0; int unk1ec4; int unk1ec8;
    int unk1ecc; int unk1ed0; int unk1ed4; int unk1ed8; int unk1edc; int unk1ee0; int unk1ee4; int unk1ee8; int unk1eec; int unk1ef0;
    int unk1ef4; int unk1ef8; int unk1efc; int unk1f00; int unk1f04; int unk1f08; int unk1f0c; int unk1f10; int unk1f14; int unk1f18;
    int unk1f1c; int unk1f20; int unk1f24; int unk1f28; int unk1f2c; int unk1f30; int unk1f34; int unk1f38; int unk1f3c; int unk1f40;
    int unk1f44; int unk1f48; int unk1f4c; int unk1f50; int unk1f54; int unk1f58; int unk1f5c; int unk1f60; int unk1f64; int unk1f68;
    int unk1f6c; int unk1f70; int unk1f74; int unk1f78; int unk1f7c; int unk1f80; int unk1f84; int unk1f88; int unk1f8c; int unk1f90;
    int unk1f94; int unk1f98; int unk1f9c; int unk1fa0; int unk1fa4; int unk1fa8; int unk1fac; int unk1fb0; int unk1fb4; int unk1fb8;
    int unk1fbc; int unk1fc0; int unk1fc4; int unk1fc8; int unk1fcc; int unk1fd0; int unk1fd4; int unk1fd8; int unk1fdc; int unk1fe0;
    int unk1fe4; int unk1fe8; int unk1fec; int unk1ff0; int unk1ff4; int unk1ff8; int unk1ffc; int unk2000; int unk2004; int unk2008;
    int unk200c; int unk2010; int unk2014; int unk2018; int unk201c; int unk2020; int unk2024; int unk2028; int unk202c; int unk2030;
    int unk2034; int unk2038; int unk203c; int unk2040; int unk2044; int unk2048; int unk204c; int unk2050; int unk2054; int unk2058;
    int unk205c; int unk2060; int unk2064; int unk2068; int unk206c; int unk2070; int unk2074; int unk2078; int unk207c; int unk2080;
    int unk2084; int unk2088; int unk208c; int unk2090; int unk2094; int unk2098; int unk209c; int unk20a0; int unk20a4; int unk20a8;
    int unk20ac; int unk20b0; int unk20b4; int unk20b8; int unk20bc; int unk20c0; int unk20c4; int unk20c8; int unk20cc; int unk20d0;
    int unk20d4; int unk20d8; int unk20dc; int unk20e0; int unk20e4; int unk20e8; int unk20ec; int unk20f0; int unk20f4; int unk20f8;
    int unk20fc; int unk2100; int unk2104; int unk2108; int unk210c; int unk2110; int unk2114; int unk2118; int unk211c; int unk2120;
    int unk2124; int unk2128; int unk212c; int unk2130; int unk2134; int unk2138; int unk213c; int unk2140; int unk2144; int unk2148;
    int unk214c; int unk2150; int unk2154; int unk2158; int unk215c; int unk2160; int unk2164; int unk2168; int unk216c; int unk2170;
    int unk2174; int unk2178; int unk217c; int unk2180; int unk2184; int unk2188; int unk218c; int unk2190; int unk2194; int unk2198;
    int unk219c; int unk21a0; int unk21a4; int unk21a8; int unk21ac; int unk21b0; int unk21b4; int unk21b8; int unk21bc; int unk21c0;
    int unk21c4; int unk21c8; int unk21cc; int unk21d0; int unk21d4; int unk21d8; int unk21dc; int unk21e0; int unk21e4; int unk21e8;
    int unk21ec; int unk21f0; int unk21f4; int unk21f8; int unk21fc; int unk2200; int unk2204; int unk2208; int unk220c; int unk2210;
    int unk2214; int unk2218; int unk221c; int unk2220; int unk2224; int unk2228; int unk222c; int unk2230; int unk2234; int unk2238;
    int unk223c; int unk2240; int unk2244; int unk2248; int unk224c; int unk2250; int unk2254; int unk2258; int unk225c; int unk2260;
    int unk2264; int unk2268; int unk226c; int unk2270; int unk2274; int unk2278; int unk227c; int unk2280; int unk2284; int unk2288;
    int unk228c; int unk2290; int unk2294; int unk2298; int unk229c; int unk22a0; int unk22a4; int unk22a8; int unk22ac; int unk22b0;
    int unk22b4; int unk22b8; int unk22bc; int unk22c0; int unk22c4; int unk22c8; int unk22cc; int unk22d0; int unk22d4; int unk22d8;
    int unk22dc; int unk22e0; int unk22e4; int unk22e8; int unk22ec; int unk22f0; int unk22f4; int unk22f8; int unk22fc; int unk2300;
    int unk2304; int unk2308; int unk230c; int unk2310; int unk2314; int unk2318; int unk231c; int unk2320; int unk2324; int unk2328;
    int unk232c; int unk2330; int unk2334; int unk2338; int unk233c; int unk2340; int unk2344; int unk2348; int unk234c; int unk2350;
    int unk2354; int unk2358; int unk235c; int unk2360; int unk2364; int unk2368; int unk236c; int unk2370; int unk2374; int unk2378;
    int unk237c; int unk2380; int unk2384; int unk2388; int unk238c; int unk2390; int unk2394; int unk2398; int unk239c; int unk23a0;
    int unk23a4; int unk23a8; int unk23ac; int unk23b0; int unk23b4; int unk23b8; int unk23bc; int unk23c0; int unk23c4; int unk23c8;
    int unk23cc; int unk23d0; int unk23d4; int unk23d8; int unk23dc; int unk23e0; int unk23e4; int unk23e8; int unk23ec; int unk23f0;
    int unk23f4; int unk23f8; int unk23fc; int unk2400; int unk2404; int unk2408; int unk240c; int unk2410; int unk2414; int unk2418;
    int unk241c; int unk2420; int unk2424; int unk2428; int unk242c; int unk2430; int unk2434; int unk2438; int unk243c; int unk2440;
    int unk2444; int unk2448; int unk244c; int unk2450; int unk2454; int unk2458; int unk245c; int unk2460; int unk2464; int unk2468;
    int unk246c; int unk2470; int unk2474; int unk2478; int unk247c; int unk2480; int unk2484; int unk2488; int unk248c; int unk2490;
    int unk2494; int unk2498; int unk249c; int unk24a0; int unk24a4; int unk24a8; int unk24ac; int unk24b0; int unk24b4; int unk24b8;
    int unk24bc; int unk24c0; int unk24c4; int unk24c8; int unk24cc; int unk24d0; int unk24d4; int unk24d8; int unk24dc; int unk24e0;
    int unk24e4; int unk24e8; int unk24ec; int unk24f0; int unk24f4; int unk24f8; int unk24fc; int unk2500; int unk2504; int unk2508;
    int unk250c; int unk2510; int unk2514; int unk2518; int unk251c; int unk2520; int unk2524; int unk2528; int unk252c; int unk2530;
    int unk2534; int unk2538; int unk253c; int unk2540; int unk2544; int unk2548; int unk254c; int unk2550; int unk2554; int unk2558;
    int unk255c; int unk2560; int unk2564; int unk2568; int unk256c; int unk2570; int unk2574; int unk2578; int unk257c; int unk2580;
    int unk2584; int unk2588; int unk258c; int unk2590; int unk2594; int unk2598; int unk259c; int unk25a0; int unk25a4; int unk25a8;
    int unk25ac; int unk25b0; int unk25b4; int unk25b8; int unk25bc; int unk25c0; int unk25c4; int unk25c8; int unk25cc; int unk25d0;
    int unk25d4; int unk25d8; int unk25dc; int unk25e0; int unk25e4; int unk25e8; int unk25ec; int unk25f0; int unk25f4; int unk25f8;
    int unk25fc; int unk2600; int unk2604; int unk2608; int unk260c; int unk2610; int unk2614; int unk2618; int unk261c; int unk2620;
    int unk2624; int unk2628; int unk262c; int unk2630; int unk2634; int unk2638; int unk263c; int unk2640; int unk2644; int unk2648;
    int unk264c; int unk2650; int unk2654; int unk2658; int unk265c; int unk2660; int unk2664; int unk2668; int unk266c; int unk2670;
    int unk2674; int unk2678; int unk267c; int unk2680; int unk2684; int unk2688; int unk268c; int unk2690; int unk2694; int unk2698;
    int unk269c; int unk26a0; int unk26a4; int unk26a8; int unk26ac; int unk26b0; int unk26b4; int unk26b8; int unk26bc; int unk26c0;
    int unk26c4; int unk26c8; int unk26cc; int unk26d0; int unk26d4; int unk26d8; int unk26dc; int unk26e0; int unk26e4; int unk26e8;
    int unk26ec; int unk26f0; int unk26f4; int unk26f8; int unk26fc; int unk2700; int unk2704; int unk2708; int unk270c; int unk2710;
    int unk2714; int unk2718; int unk271c; int unk2720; int unk2724; int unk2728; int unk272c; int unk2730; int unk2734; int unk2738;
    int unk273c; int unk2740; int unk2744; int unk2748; int unk274c; int unk2750; int unk2754; int unk2758; int unk275c; int unk2760;
    int unk2764; int unk2768; int unk276c; int unk2770; int unk2774; int unk2778; int unk277c; int unk2780; int unk2784; int unk2788;
    int unk278c; int unk2790; int unk2794; int unk2798; int unk279c; int unk27a0; int unk27a4; int unk27a8; int unk27ac; int unk27b0;
    int unk27b4; int unk27b8; int unk27bc; int unk27c0; int unk27c4; int unk27c8; int unk27cc; int unk27d0; int unk27d4; int unk27d8;
    int unk27dc; int unk27e0; int unk27e4; int unk27e8; int unk27ec; int unk27f0; int unk27f4; int unk27f8; int unk27fc; int unk2800;
    int unk2804; int unk2808; int unk280c; int unk2810; int unk2814; int unk2818; int unk281c; int unk2820; int unk2824; int unk2828;
    int unk282c; int unk2830; int unk2834; int unk2838; int unk283c; int unk2840; int unk2844; int unk2848; int unk284c; int unk2850;
    int unk2854; int unk2858; int unk285c; int unk2860; int unk2864; int unk2868; int unk286c; int unk2870; int unk2874; int unk2878;
    int unk287c; int unk2880; int unk2884; int unk2888; int unk288c; int unk2890; int unk2894; int unk2898; int unk289c; int unk28a0;
    int unk28a4; int unk28a8; int unk28ac; int unk28b0; int unk28b4; int unk28b8; int unk28bc; int unk28c0; int unk28c4; int unk28c8;
    int unk28cc; int unk28d0; int unk28d4; int unk28d8; int unk28dc; int unk28e0; int unk28e4; int unk28e8; int unk28ec; int unk28f0;
    int unk28f4; int unk28f8; int unk28fc; int unk2900; int unk2904; int unk2908; int unk290c; int unk2910; int unk2914; int unk2918;
    int unk291c; int unk2920; int unk2924; int unk2928; int unk292c; int unk2930; int unk2934; int unk2938; int unk293c; int unk2940;
    int unk2944; int unk2948; int unk294c; int unk2950; int unk2954; int unk2958; int unk295c; int unk2960; int unk2964; int unk2968;
    int unk296c; int unk2970; int unk2974; int unk2978; int unk297c; int unk2980; int unk2984; int unk2988; int unk298c; int unk2990;
    int unk2994; int unk2998; int unk299c; int unk29a0; int unk29a4; int unk29a8; int unk29ac; int unk29b0; int unk29b4; int unk29b8;
    int unk29bc; int unk29c0; int unk29c4; int unk29c8; int unk29cc; int unk29d0; int unk29d4; int unk29d8; int unk29dc; int unk29e0;
    int unk29e4; int unk29e8; int unk29ec; int unk29f0; int unk29f4; int unk29f8; int unk29fc; int unk2a00; int unk2a04; int unk2a08;
    int unk2a0c; int unk2a10; int unk2a14; int unk2a18; int unk2a1c; int unk2a20; int unk2a24; int unk2a28; int unk2a2c; int unk2a30;
    int unk2a34; int unk2a38; int unk2a3c; int unk2a40; int unk2a44; int unk2a48; int unk2a4c; int unk2a50; int unk2a54; int unk2a58;
    int unk2a5c; int unk2a60; int unk2a64; int unk2a68; int unk2a6c; int unk2a70; int unk2a74; int unk2a78; int unk2a7c; int unk2a80;
    int unk2a84; int unk2a88; int unk2a8c; int unk2a90; int unk2a94; int unk2a98; int unk2a9c; int unk2aa0; int unk2aa4; int unk2aa8;
    int unk2aac; int unk2ab0; int unk2ab4; int unk2ab8; int unk2abc; int unk2ac0; int unk2ac4; int unk2ac8; int unk2acc; int unk2ad0;
    int unk2ad4; int unk2ad8; int unk2adc; int unk2ae0; int unk2ae4; int unk2ae8; int unk2aec; int unk2af0; int unk2af4; int unk2af8;
    int unk2afc; int unk2b00; int unk2b04; int unk2b08; int unk2b0c; int unk2b10; int unk2b14; int unk2b18; int unk2b1c; int unk2b20;
    int unk2b24; int unk2b28; int unk2b2c; int unk2b30; int unk2b34; int unk2b38; int unk2b3c; int unk2b40; int unk2b44; int unk2b48;
    int unk2b4c; int unk2b50; int unk2b54; int unk2b58; int unk2b5c; int unk2b60; int unk2b64; int unk2b68; int unk2b6c; int unk2b70;
    int unk2b74; int unk2b78; int unk2b7c; int unk2b80; int unk2b84; int unk2b88; int unk2b8c; int unk2b90; int unk2b94; int unk2b98;
    int unk2b9c; int unk2ba0; int unk2ba4; int unk2ba8; int unk2bac; int unk2bb0; int unk2bb4; int unk2bb8; int unk2bbc; int unk2bc0;
    int unk2bc4; int unk2bc8; int unk2bcc; int unk2bd0; int unk2bd4; int unk2bd8; int unk2bdc; int unk2be0; int unk2be4; int unk2be8;
    int unk2bec; int unk2bf0; int unk2bf4; int unk2bf8; int unk2bfc; int unk2c00; int unk2c04; int unk2c08; int unk2c0c; int unk2c10;
    int unk2c14; int unk2c18; int unk2c1c; int unk2c20; int unk2c24; int unk2c28; int unk2c2c; int unk2c30; int unk2c34; int unk2c38;
    int unk2c3c; int unk2c40; int unk2c44; int unk2c48; int unk2c4c; int unk2c50; int unk2c54; int unk2c58; int unk2c5c; int unk2c60;
    int unk2c64; int unk2c68; int unk2c6c; int unk2c70; int unk2c74; int unk2c78; int unk2c7c; int unk2c80; int unk2c84; int unk2c88;
    int unk2c8c; int unk2c90; int unk2c94; int unk2c98; int unk2c9c; int unk2ca0; int unk2ca4; int unk2ca8; int unk2cac; int unk2cb0;
    int unk2cb4; int unk2cb8; int unk2cbc; int unk2cc0; int unk2cc4; int unk2cc8; int unk2ccc; int unk2cd0; int unk2cd4; int unk2cd8;
    int unk2cdc; int unk2ce0; int unk2ce4; int unk2ce8; int unk2cec; int unk2cf0; int unk2cf4; int unk2cf8; int unk2cfc; int unk2d00;
    int unk2d04; int unk2d08; int unk2d0c; int unk2d10; int unk2d14; int unk2d18; int unk2d1c; int unk2d20; int unk2d24; int unk2d28;
    int unk2d2c; int unk2d30; int unk2d34; int unk2d38; int unk2d3c; int unk2d40; int unk2d44; int unk2d48; int unk2d4c; int unk2d50;
    int unk2d54; int unk2d58; int unk2d5c; int unk2d60; int unk2d64; int unk2d68; int unk2d6c; int unk2d70; int unk2d74; int unk2d78;
    int unk2d7c; int unk2d80; int unk2d84; int unk2d88; int unk2d8c; int unk2d90; int unk2d94; int unk2d98; int unk2d9c; int unk2da0;
    int unk2da4; int unk2da8; int unk2dac; int unk2db0; int unk2db4; int unk2db8; int unk2dbc; int unk2dc0; int unk2dc4; int unk2dc8;
    int unk2dcc; int unk2dd0; int unk2dd4; int unk2dd8; int unk2ddc; int unk2de0; int unk2de4; int unk2de8; int unk2dec; int unk2df0;
    int unk2df4; int unk2df8; int unk2dfc; int unk2e00; int unk2e04; int unk2e08; int unk2e0c; int unk2e10; int unk2e14; int unk2e18;
    int unk2e1c; int unk2e20; int unk2e24; int unk2e28; int unk2e2c; int unk2e30; int unk2e34; int unk2e38; int unk2e3c; int unk2e40;
    int unk2e44; int unk2e48; int unk2e4c; int unk2e50; int unk2e54; int unk2e58; int unk2e5c; int unk2e60; int unk2e64; int unk2e68;
    int unk2e6c; int unk2e70; int unk2e74; int unk2e78; int unk2e7c; int unk2e80; int unk2e84; int unk2e88; int unk2e8c; int unk2e90;
    int unk2e94; int unk2e98; int unk2e9c; int unk2ea0; int unk2ea4; int unk2ea8; int unk2eac; int unk2eb0; int unk2eb4; int unk2eb8;
    int unk2ebc; int unk2ec0; int unk2ec4; int unk2ec8; int unk2ecc; int unk2ed0; int unk2ed4; int unk2ed8; int unk2edc; int unk2ee0;
    int unk2ee4; int unk2ee8; int unk2eec; int unk2ef0; int unk2ef4; int unk2ef8; int unk2efc; int unk2f00; int unk2f04; int unk2f08;
    int unk2f0c; int unk2f10; int unk2f14; int unk2f18; int unk2f1c; int unk2f20; int unk2f24; int unk2f28; int unk2f2c; int unk2f30;
    int unk2f34; int unk2f38; int unk2f3c; int unk2f40; int unk2f44; int unk2f48; int unk2f4c; int unk2f50; int unk2f54; int unk2f58;
    int unk2f5c; int unk2f60; int unk2f64; int unk2f68; int unk2f6c; int unk2f70; int unk2f74; int unk2f78; int unk2f7c; int unk2f80;
    int unk2f84; int unk2f88; int unk2f8c; int unk2f90; int unk2f94; int unk2f98; int unk2f9c; int unk2fa0; int unk2fa4; int unk2fa8;
    int unk2fac; int unk2fb0; int unk2fb4; int unk2fb8; int unk2fbc; int unk2fc0; int unk2fc4; int unk2fc8; int unk2fcc; int unk2fd0;
    int unk2fd4; int unk2fd8; int unk2fdc; int unk2fe0; int unk2fe4; int unk2fe8; int unk2fec; int unk2ff0; int unk2ff4; int unk2ff8;
    int unk2ffc; int unk3000; int unk3004; int unk3008; int unk300c; int unk3010; int unk3014; int unk3018; int unk301c;
    CollisionCacheState m_fTimeOfImpact;
};

struct hkpGskAgent {
    void hkpTransformAgent_processCollision(const hkpCdBody& bodyB, const hkpCdBody& bodyA, const GskAgentInput& input, Output& output);
};

// @fnv 0x00d434e0
template <>
// src: GUESS 0x00d434e0 (confidence: low)
void hkpSymmetricAgent<hkpGskAgent>::ProcessEntries_00d434e0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const GskAgentInput& input, Output& output)
{
    float oldTime = output.m_fTimeOfImpact.m_uiCommandId;
    AlignedPairData* cp = output.m_pAlignedPairData;

    reinterpret_cast<hkpGskAgent*>(this)->hkpTransformAgent_processCollision(bodyB, bodyA, input, output);

    while (cp < output.m_pAlignedPairData) {
        addMul4(cp->m_vContactPosition, getDistanceSimdReal(cp->m_vSeparatingNormal), cp->m_vSeparatingNormal);
        setNeg3(cp->m_vSeparatingNormal, cp->m_vSeparatingNormal);
        cp++;
    }

    if (oldTime != output.m_fTimeOfImpact.m_uiCommandId) {
        setNeg3(output.m_fTimeOfImpact.m_vSeparatingNormal);

        unsigned char t = output.m_fTimeOfImpact.m_kGskCache.m_features.a;
        output.m_fTimeOfImpact.m_kGskCache.m_features.a = output.m_fTimeOfImpact.m_kGskCache.m_features.b;
        unsigned char dimA;
        output.m_fTimeOfImpact.m_kGskCache.m_features.b = t;
        dimA = output.m_fTimeOfImpact.m_kGskCache.m_ucDimensionA;

        unsigned char dimB = output.m_fTimeOfImpact.m_kGskCache.m_ucDimensionB;
        output.m_fTimeOfImpact.m_kGskCache.m_ucDimensionB = dimA;
        int idx = (int)dimB + (int)dimA - 1;
        output.m_fTimeOfImpact.m_kGskCache.m_ucDimensionA = dimB;
        unsigned short v0 = output.m_fTimeOfImpact.m_kGskCache.m_kVertices[0];
        unsigned short* v = output.m_fTimeOfImpact.m_kGskCache.m_kVertices;
        v[0] = v[idx];
        v[idx] = v0;

        if ((output.m_fTimeOfImpact.m_kGskCache.m_ucDimensionA & output.m_fTimeOfImpact.m_kGskCache.m_ucDimensionB) == 2) {
            unsigned short v1 = output.m_fTimeOfImpact.m_kGskCache.m_kVertices[1];
            output.m_fTimeOfImpact.m_kGskCache.m_kVertices[1] = output.m_fTimeOfImpact.m_kGskCache.m_kVertices[2];
            output.m_fTimeOfImpact.m_kGskCache.m_kVertices[2] = v1;
        }
    }
}

struct S_00d43030_Shape {
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};
struct __declspec(align(16)) S_00d43030_TransformShape : S_00d43030_Shape {
    void* m_containerVtbl;
    S_00d43030_Shape* m_pContainedShape;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    hkTransform m_kMotionTransform;
};
// local form of hkpCdBody: 0x00d43030 needs its inline four-field constructor and original motion-state copy; shared adaptation does not reproduce exe bytes.
struct S_00d43030_CdBody {
    const S_00d43030_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d43030_CdBody* m_parent;
    S_00d43030_CdBody(const S_00d43030_CdBody* parent, const WorkArea* ms, const S_00d43030_Shape* shape, unsigned int key) { m_pCollisionShape = shape; m_uiCollisionShapeKey = key; m_pMotionState = ms; m_parent = parent; }
    const S_00d43030_Shape* getShape() const { return m_pCollisionShape; }
    const WorkArea* GetMotionState() const { return static_cast<const WorkArea*>(m_pMotionState); }
    const hkTransform& getTransform() const { return static_cast<const WorkArea*>(m_pMotionState)->m_kMotionTransform; }
};
struct S_00d43030_ContactMgr;
struct S_00d43030_CollisionInput;
struct S_00d43030_Agent;
typedef S_00d43030_Agent* (*S_00d43030_CreateFunc)(const S_00d43030_CdBody&, const S_00d43030_CdBody&, const S_00d43030_CollisionInput&, S_00d43030_ContactMgr*);
struct S_00d43030_AgentFuncs {
    S_00d43030_CreateFunc m_pCreateFunc;
    void* unk04; void* unk08; void* unk0C; void* unk10;
};
struct S_00d43030_Dispatcher {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    S_00d43030_AgentFuncs m_agent2Funcs[32];
    __forceinline S_00d43030_Agent* getNewCollisionAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) const;
};
struct S_00d43030_CollisionInput {
    S_00d43030_Dispatcher* m_pCollisionDispatcher;
    int unk04; int unk08; int unk0C; int unk10;
    int m_bCreatePredictiveAgents;
};
__forceinline S_00d43030_Agent* S_00d43030_Dispatcher::getNewCollisionAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) const
{
    int typeA = bodyA.getShape()->m_type;
    int typeB = bodyB.getShape()->m_type;
    const unsigned char (*tbl)[32] = input.m_bCreatePredictiveAgents ? m_agent3TypeMap : m_agent2TypeMap;
    int idx = tbl[typeA][typeB];
    S_00d43030_CreateFunc f = m_agent2Funcs[idx].m_pCreateFunc;
    return f(bodyA, bodyB, input, mgr);
}

struct S_00d43030_Router : Resource {
    Allocator& heap() { return *allocator; }
};

struct S_00d43030_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00d43030_RefObj() throw();
    __forceinline S_00d43030_RefObj() throw() { m_sReferenceCount = 1; }
    __forceinline void* operator new(unsigned int nbytes)
    {
        S_00d43030_RefObj* b = static_cast<S_00d43030_RefObj*>((void*)static_cast<S_00d43030_Router*>(hkMemoryRouter_getInstance())->heap().allocate(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void operator delete(void*) {}
};
struct S_00d43030_Agent : S_00d43030_RefObj {
    S_00d43030_ContactMgr* m_pContactManager;
    __forceinline S_00d43030_Agent(S_00d43030_ContactMgr* mgr) throw() : m_pContactManager(mgr) {}
    virtual void vfn04();
};
struct S_00d43030_TransformAgent : S_00d43030_Agent {
    S_00d43030_Agent* m_pAgent;
    __forceinline S_00d43030_TransformAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw();
    virtual void vfn04();
};
__forceinline S_00d43030_TransformAgent::S_00d43030_TransformAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw()
    : S_00d43030_Agent(mgr)
{
    const S_00d43030_TransformShape* tShapeA = static_cast<const S_00d43030_TransformShape*>(bodyA.getShape());
    const S_00d43030_Shape* childShape = tShapeA->m_pContainedShape;

    WorkArea ms;
    ms.CopyFrom(DataHandle(reinterpret_cast<int>(bodyA.GetMotionState())));
    ms.SetTransformProduct(DataHandle(reinterpret_cast<int>(bodyA.GetMotionState())),
        tShapeA->m_kMotionTransform);

    S_00d43030_CdBody newOperandA(&bodyA, &ms, childShape, 0);
    m_pAgent = input.m_pCollisionDispatcher->getNewCollisionAgent(newOperandA, bodyB, input, mgr);
}
// Retained until the shared hkpSymmetricAgent inherits AGENT and supports this
// constructor: its base layout and inherited allocator are required here.
template <class AGENT> struct S_00d43030_Symmetric : AGENT {
    __forceinline S_00d43030_Symmetric(const S_00d43030_CdBody& A, const S_00d43030_CdBody& B, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr) throw()
        : AGENT(B, A, input, mgr) {}
    virtual void vfn04();
};

// Allocates a symmetric TransformAgent for the two bodies and returns it as an Agent pointer.
// @fnv 0x00d43030
S_00d43030_Agent* CreateTransformAgent(const S_00d43030_CdBody& bodyA, const S_00d43030_CdBody& bodyB, const S_00d43030_CollisionInput& input, S_00d43030_ContactMgr* mgr)
{
    S_00d43030_TransformAgent* agent = new S_00d43030_Symmetric<S_00d43030_TransformAgent>(bodyA, bodyB, input, mgr);
    return agent;
}

extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    __m128 m_vComponents;
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    __declspec(align(16)) hkVector4 m_key;
    int m_uiFilterValue;
};

void __cdecl DispatchClosestPoints(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// XORs the input vector with DAT_010c44d0, builds a Record_d2e9 with m_fScalar and a4, and calls DispatchClosestPoints with an optional second record using a5.
// @fnv 0x00d43370
// src: GUESS 0x00d43370 (confidence: low)
void __cdecl hkVector4_UpdateState_00d43370(int a2, int a1, const Input_d2e9* input, int a4, int a5)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = (const unsigned int*)DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = *(const hkVector4*)&input->m_vComponents;
    rec.m_uiFilterValue = a4;

    if (a5 != 0) {
        Record_d2e9 rec2;
        rec2.m_vtbl = (const unsigned int*)DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = *(const hkVector4*)&input->m_vComponents;
        rec2.m_uiFilterValue = a5;
        DispatchClosestPoints(a1, a2, &local, &rec, &rec2);
    } else {
        DispatchClosestPoints(a1, a2, &local, &rec, 0);
    }
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);

extern unsigned long DAT_0126835c;

struct S_00d42b50_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        m_uiStartTicks = t;
    }
};

struct S_00d42b50_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d42b50_MonitorStream& GetMonitorStream()
    {
        return *(S_00d42b50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
};

struct __declspec(align(16)) S_00d42b50_Rot {
    float x, y, z, w;
    void setMul(const hkVector4* a, const hkVector4* b);
};


struct S_00d42b50_Motion {
    hkTransform m_kMotionTransform;
    hkVector4 unk40;
    hkVector4 unk50;
    S_00d42b50_Rot unk60;
    S_00d42b50_Rot unk70;
    hkVector4 unk80;
    hkVector4 unk90;
    float unkA0;
};

struct S_00d42b50_Shape {
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
};

struct S_00d42b50_TShape : S_00d42b50_Shape {
    int unk10;
    S_00d42b50_Shape* m_pContainedShape;
    int unk18;
    int unk1C;
    __declspec(align(16)) hkVector4 m_rotation;
    hkTransform m_kMotionTransform;
};

struct S_00d42b50_CdBody {
    const S_00d42b50_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d42b50_Motion* m_pMotionState;
    const S_00d42b50_CdBody* m_parent;
};

struct S_00d42b50_Input;
struct S_00d42b50_Output;

struct S_00d42b50_Agent {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void ProcessAgent(const S_00d42b50_CdBody& a, const S_00d42b50_CdBody& b, const S_00d42b50_Input& in, S_00d42b50_Output& out);
};

struct S_00d42b50_Cls {
    int unk00;
    int unk04;
    int unk08;
    S_00d42b50_Agent* m_pAgent;
    void hkpTransformAgent_processCollision(const S_00d42b50_CdBody& bodyA, const S_00d42b50_CdBody& bodyB, const S_00d42b50_Input& input, S_00d42b50_Output& output);
};

// @fnv 0x00d42b50
// src: HAVOK_SRC 0x00d42b50
void S_00d42b50_Cls::hkpTransformAgent_processCollision(const S_00d42b50_CdBody& bodyA, const S_00d42b50_CdBody& bodyB, const S_00d42b50_Input& input, S_00d42b50_Output& output)
{
    union Scratch {
        unsigned int tick;
        const S_00d42b50_TShape* shape;
    } scratch;
    {
        S_00d42b50_MonitorStream& mStream = S_00d42b50_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S_00d42b50_TimerCommand* h = (S_00d42b50_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "TtTransform";
            { unsigned int fnv_ticks;
                __asm {
                    rdtsc
                    mov dword ptr[fnv_ticks], eax
                }
                scratch.tick = fnv_ticks; }
            h->m_uiStartTicks = scratch.tick;
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }

    scratch.shape = (const S_00d42b50_TShape*)bodyA.m_pCollisionShape;
    const hkTransform& xf = scratch.shape->m_kMotionTransform;
    S_00d42b50_Motion ms;
    ms.m_kMotionTransform.hkTransform_setMul(bodyA.m_pMotionState->m_kMotionTransform, xf);
    const S_00d42b50_Motion* src = bodyA.m_pMotionState;
    _mm_store_ps(&ms.unk40.x, _mm_load_ps(&src->unk40.x));
    _mm_store_ps(&ms.unk50.x, _mm_load_ps(&src->unk50.x));
    ms.unk60.setMul((const hkVector4*)&src->unk60, &scratch.shape->m_rotation);
    ms.unk70.setMul((const hkVector4*)&src->unk70, &scratch.shape->m_rotation);

    __m128 delta = _mm_sub_ps(_mm_load_ps(&src->unk80.x), _mm_load_ps(&xf.m_vTranslation.m128_f32[0]));
    __m128 xcol = _mm_load_ps(&xf.m_kColumn0.m128_f32[0]);
    __m128 ycol = _mm_load_ps(&xf.m_kColumn1.m128_f32[0]);
    __m128 zcol = _mm_load_ps(&xf.m_kColumn2.m128_f32[0]);
    {
        __m128 low = _mm_unpacklo_ps(xcol, ycol);
        __m128 last = _mm_shuffle_ps(_mm_unpackhi_ps(xcol, ycol), zcol, 0xe4);
        xcol = _mm_movelh_ps(low, zcol);
        ycol = _mm_shuffle_ps(_mm_movehl_ps(xcol, low), zcol, 0xd4);
        zcol = last;
    }
    __m128 sx = _mm_shuffle_ps(delta, delta, 0);
    __m128 px = _mm_mul_ps(xcol, sx);
    __m128 sy = _mm_shuffle_ps(delta, delta, 0x55);
    __m128 py = _mm_mul_ps(ycol, sy);
    __m128 sz = _mm_shuffle_ps(delta, delta, 0xaa);
    __m128 pz = _mm_mul_ps(zcol, sz);
    _mm_store_ps(&ms.unk80.x, _mm_add_ps(_mm_add_ps(px, py), pz));
    _mm_store_ps(&ms.unk90.x, _mm_load_ps(&src->unk90.x));
    ms.unkA0 = src->unkA0;

    S_00d42b50_CdBody newBody;
    newBody.m_pMotionState = &ms;
    newBody.m_parent = &bodyA;
    newBody.m_pCollisionShape = scratch.shape->m_pContainedShape;
    newBody.m_uiCollisionShapeKey = 0;
    m_pAgent->ProcessAgent(newBody, bodyB, input, output);

    {
        S_00d42b50_MonitorStream& mStream = S_00d42b50_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S_00d42b50_TimerCommand* h = (S_00d42b50_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "Et";
            { unsigned int fnv_ticks;
                __asm {
                    rdtsc
                    mov dword ptr[fnv_ticks], eax
                }
                scratch.tick = fnv_ticks; }
            h->m_uiStartTicks = scratch.tick;
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }
}

// TtShapeCollection::v3 (0x00d43460): builds a sector descriptor and hands it
// to the TtTransform implementation with the first two arguments swapped.
struct SectorDesc {
    void* sectorPtrs;   // +0: table of "SectorPtrs" handlers
    bool  unk04;        // +4
    int   unk08;        // +8
};

struct TtTransform {
    void hkpTransformAgent_getPenetrations(int, int, int, SectorDesc*);
};

struct TtShapeCollection : TtTransform {
    void UpdateFields_00d43460(int a, int b, int c, int d);
};

// Builds a SectorDesc from d and the static sectorPtrs, then calls TtTransform::FUN_00d42ed0 with b, a, c and that descriptor.
// @fnv 0x00d43460
// src: GUESS 0x00d43460 (confidence: low)
void TtShapeCollection::UpdateFields_00d43460(int a, int b, int c, int d) {
    SectorDesc s;
    s.unk04 = false;
    s.sectorPtrs = (void*)0x10ce81c;
    s.unk08 = d;
    TtTransform::hkpTransformAgent_getPenetrations(b, a, c, &s);
}

struct CollisionAgentContext;

struct TimInvalidationTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void RemovePoint(const CollisionAgentContext& input);
};

struct TransformTimForwarder
{
    int unk00;
    int unk04;
    int unk08;
    TimInvalidationTarget* m_pAgent;
    void hkpTransformAgent_invalidateTim(const CollisionAgentContext& input);
};

// @fnv 0x00d42a00
// src: HAVOK_LIB 0x00d42a00
void TransformTimForwarder::hkpTransformAgent_invalidateTim(const CollisionAgentContext& input)
{
    m_pAgent->RemovePoint(input);
}

struct TransformClosestPointCollector;

struct TransformClosestChildAgent {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void getClosestPoints(const hkpCdBody& bodyA,
        const hkpCdBody& bodyB, const S_00d42d60_Input& input,
        TransformClosestPointCollector& collector);
};

struct TransformClosestAgent {
    int unk00;
    int unk04;
    int unk08;
    TransformClosestChildAgent* m_pAgent;
    void hkpTransformAgent_getClosestPoints(const hkpCdBody& bodyA,
        const hkpCdBody& bodyB, const S_00d42d60_Input& input,
        TransformClosestPointCollector& collector);
};

// Builds a temporary child body from bodyA's contained shape and motion transform, then delegates to m_pAgent to collect closest points with bodyB.
// @fnv 0x00d42de0
// src: HAVOK_LIB 0x00d42de0
void TransformClosestAgent::hkpTransformAgent_getClosestPoints(const hkpCdBody& bodyA,
    const hkpCdBody& bodyB, const S_00d42d60_Input& input,
    TransformClosestPointCollector& collector)
{
    __declspec(align(16)) hkTransform transform;
    const S_00d42d60_TransformShape* shape =
        reinterpret_cast<const S_00d42d60_TransformShape*>(bodyA.m_pCollisionShape);
    transform.hkTransform_setMul(
        *static_cast<const hkTransform*>(bodyA.m_pMotionState),
        shape->m_kMotionTransform);

    hkpCdBody childBody;
    childBody.m_pMotionState = &transform;
    childBody.m_parent = &bodyA;
    childBody.m_pCollisionShape = reinterpret_cast<const hkpShape*>(shape->m_pContainedShape);
    childBody.m_uiCollisionShapeKey = 0;
    m_pAgent->getClosestPoints(childBody, bodyB, input, collector);
}

struct TransformClosestDispatcher
{
    int unk000; int unk004; int unk008; int unk00c;
    int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c;
    int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c;
    int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c;
    int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c;
    int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac;
    int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc;
    int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec;
    int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c;
    int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c;
    int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c;
    int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c;
    int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c;
    int unk190; int unk194; int unk198; int unk19c;
    unsigned char agentTypes[32][32];
    unsigned char predictiveAgentTypes[32][32];
    CollisionAgentFunctionTable functions[64];
};

struct __declspec(align(16)) TransformClosestFrame
{
    const Shape_00d42f40* shape;
    unsigned int shapeKey;
    const hkTransform* motion;
    const CollisionBody_00d42f40* parent;
    hkTransform transform;
};

// @fnv 0x00d42e50
// src: HAVOK_LIB 0x00d42e50
void __cdecl hkpTransformAgent_staticGetClosestPoints(const CollisionBody_00d42f40* bodyA,
                         const CollisionBody_00d42f40* bodyB,
                         const CollisionInput_00d42f40* input, void* collector)
{
    const TransformShape_00d42f40* shape =
        static_cast<const TransformShape_00d42f40*>(bodyA->shape);
    TransformClosestFrame frame;
    frame.transform.hkTransform_setMul(*bodyA->transform, shape->transform);
    frame.parent = bodyA;
    frame.motion = &frame.transform;
    const Shape_00d42f40* child = shape->child;
    frame.shape = child;
    frame.shapeKey = 0;

    const unsigned char* table = reinterpret_cast<const unsigned char*>(input->dispatcher);
    unsigned int index = ((child->type + 13) << 5) + bodyB->shape->type;
    unsigned char agent = table[index];
    const TransformClosestDispatcher* dispatcher =
        reinterpret_cast<const TransformClosestDispatcher*>(input->dispatcher);
    void* function = dispatcher->functions[agent].f8;
    reinterpret_cast<void (__cdecl*)(const void*, const CollisionBody_00d42f40*,
                                    const CollisionInput_00d42f40*, void*)>(function)
        (&frame.shape, bodyB, input, collector);
}
