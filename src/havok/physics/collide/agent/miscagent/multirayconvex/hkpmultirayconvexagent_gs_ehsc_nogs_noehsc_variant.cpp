// The normal is hkVector4: its rotation method is bound to 0x00c7f700 in other Havok units.
#include "../../../../../../../include/hkVector4.h"
// The four SIMD columns and relative-transform call at 0x00cb22f0 identify hkTransform.
#include "../../../../../../../include/hkTransform.h"
// The 32-byte endpoint pair is hkpMultiRayShape::Ray (m_kRayStart, m_kRayEnd).
#include "../../../../../../../include/hkpMultiRayShape.h"

// Havok's default transform constructor leaves its storage untouched.
inline hkTransform::hkTransform() {}


// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void hkpMultiRayConvexAgent_staticGetPenetrations(int a, int b, int c, int d);
struct FUN_00d37690_Class {
    void __thiscall ForwardToFunction(int a, int b, int c, int d);
};
void hkpMultiRayConvexAgent_createMultiRayConvexAgent(int a, int b, int c, int d);
void FUN_00d37780(int a, int b, int c, int d);
void Object_ProcessState_00d37860(int a, int b, int c, int d);
void Object_UpdateFields_00d378a0(int a, int b, int c, int d);
void hkpMultiRayConvexAgent_staticGetClosestPoints(int a, int b, int c, int d);
void Object_ProcessEntries_00daf8e0();
void Object_UpdateFields_00d3ac80();
struct FUN_00cfbbe0_Arg {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    char f4;
    char f5;
};
struct FUN_00cfbbe0_Class {
    void __thiscall AppendRecordAndRegisterAgents(FUN_00cfbbe0_Arg* a, int b, int c);
};
void hkpMultiRayConvexAgent_registerAgent(int a);
struct Handler {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void process(unsigned short index, int argument);
};
struct Owner {
    virtual ~Owner();
    int unk04;
    Handler* handler;
    unsigned short* values;
    int count;
    void ProcessValuesAndDelete(int argument);
};
struct S_00d37860_Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    bool m_bHit;
    S_00d37860_Base() : m_bHit(false) {}
};
struct S_00d37860_Collector : S_00d37860_Base {
    int m_iFilter;
    S_00d37860_Collector(int filter) : m_iFilter(filter) {}
    virtual void f1();
};
void hkpMultiRayConvexAgent_staticGetPenetrations(void* b, void* a, void* c, S_00d37860_Collector* collector);
void Object_ProcessState_00d37860(void* a, void* b, void* c, int filter);
struct Payload { const char* name; float value; int id; };
extern float DAT_0104da48;
extern const char DAT_010ce7fc[];
void hkpMultiRayConvexAgent_staticGetClosestPoints(int, int, int, Payload*);
void Object_UpdateFields_00d378a0(int a, int b, int c, int d);
struct D376B0Allocator;
struct D376B0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D376B0Allocator* m_pStreamAllocator;

    D376B0Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" D376B0MemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(D376B0Allocator* alloc, void* array, int numElements, int sizeElem);
class D376B0ReferencedObject {
public:
    D376B0ReferencedObject() : m_sReferenceCount(1) {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
// hkInplaceArray<hkUint16, 4> without a destructor (Havok was built without EH).
struct D376B0IndexArray {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned short m_kStorage[4];

    D376B0IndexArray() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000004) {}

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void SetSizeAndGrow(int n)
    {
        D376B0Allocator& alloc = hkMemoryRouter_getInstance().heap();
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(unsigned short));
        }
        m_iElementCount = n;
    }
};
struct D376B0Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_numChildren;
};
struct D376B0ShapeRef {
    D376B0Shape* m_pCollisionShape;
};
class D376B0Filter : public D376B0ReferencedObject {
public:
    D376B0Filter(void* userData) : m_ulUserData(userData) {}

    void* m_ulUserData;
};
class FUN_00d376b0 : public D376B0Filter {
public:
    FUN_00d376b0(const D376B0ShapeRef& shape, void* ReportDiagnostic, void* unused1, void* userData);
    virtual void unk00();

    D376B0IndexArray m_ppIndices;
};

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
#include <windows.h>
extern DWORD hkMonitorStreamTls;

struct S_00d374f0_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d374f0_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d374f0_Timer(const char* name) {
    S_00d374f0_MonitorStream* s = (S_00d374f0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        S_00d374f0_TimerCommand* h = (S_00d374f0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

static __forceinline void S_00d374f0_SetTransformedPos(hkVector4& out, const hkTransform& t, const hkVector4& b)
{
    const __m128 xb = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 yb = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 zb = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 t0 = _mm_mul_ps(xb, t.m_kColumn0);
    const __m128 t1 = _mm_mul_ps(yb, t.m_kColumn1);
    const __m128 t2 = _mm_mul_ps(zb, t.m_kColumn2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(t1, t0), _mm_add_ps(t2, t.m_vTranslation));
}

struct S_00d374f0_Bool {
    char m_cBooleanValue;
    S_00d374f0_Bool() {}
    operator bool() const { return m_cBooleanValue != 0; }
};

struct __declspec(align(16)) S_00d374f0_RayInput {
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    unsigned int m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
    S_00d374f0_RayInput() : m_uiFilterInfo(0), m_pRayShapeCollectionFilter(0) {}
};

struct __declspec(align(16)) S_00d374f0_RayOutputBase {
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1c;
    S_00d374f0_RayOutputBase() { m_fHitFraction = 1.0f; m_iExtraInfo = -1; }
};

struct __declspec(align(16)) S_00d374f0_RayOutput : S_00d374f0_RayOutputBase {
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    S_00d374f0_RayOutput() { m_uiShapeKeyIndex = 0; m_uiShapeKeys[0] = 0xffffffff; }
};

struct S_00d374f0_ConvexShape {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual S_00d374f0_Bool RayCast(const S_00d374f0_RayInput& input, S_00d374f0_RayOutput& output) const;
};

struct S_00d374f0_MultiRayShape {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    hkpMultiRayShape::Ray* m_data;
    int m_iElementCount;
    int m_pRayCursor;
};

struct S_00d374f0_CdBody {
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
    const S_00d374f0_CdBody* m_parent;
};

struct S_00d374f0_Collector {
    virtual ~S_00d374f0_Collector();
    virtual void AddCdBodyPair(const S_00d374f0_CdBody& a, const S_00d374f0_CdBody& b);
    S_00d374f0_Bool m_fHitDistance;
};

// @fnv 0x00d374f0
// src: XBOX_PDB 0x00d374f0
void hkpMultiRayConvexAgent_staticGetPenetrations(const S_00d374f0_CdBody& bodyA, const S_00d374f0_CdBody& bodyB, int input, S_00d374f0_Collector* collector)
{
    S_00d374f0_Timer("TtmultiRay-cnvx-getPen");
    const S_00d374f0_MultiRayShape* msA = (const S_00d374f0_MultiRayShape*)bodyA.m_pCollisionShape;
    const S_00d374f0_ConvexShape* convexB = (const S_00d374f0_ConvexShape*)bodyB.m_pCollisionShape;

    S_00d374f0_Collector* col = collector;
    hkTransform bTa;
    bTa.hkTransform_setMulInverseMul(*bodyB.m_pMotionState, *bodyA.m_pMotionState);

    int nRays = msA->m_iElementCount;
    const hkpMultiRayShape::Ray* rayA = msA->m_data;
    S_00d374f0_RayInput rayInput;
    S_00d374f0_RayOutput rayResults;
    while (nRays-- && !col->m_fHitDistance)
    {
        S_00d374f0_SetTransformedPos(rayInput.m_vFrom, bTa, rayA->m_kRayStart);
        S_00d374f0_SetTransformedPos(rayInput.m_vTo, bTa, rayA->m_kRayEnd);
        S_00d374f0_Bool hit = convexB->RayCast(rayInput, rayResults);
        if (hit.m_cBooleanValue)
        {
            col->AddCdBodyPair(bodyA, bodyB);
        }
        rayA++;
    }
    S_00d374f0_Timer("Et");
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned int DAT_0126835c;
extern char DAT_010ceda8[];
extern char DAT_010c41f8[];
extern __m128 DAT_010ec7f0;
struct Event378 { const char* tag; unsigned time; unsigned other; };
struct Timer378 { int unused; Event378* current; int unknown; Event378* end; };
inline void timer378(const char* tag) {
    Timer378* timer = (Timer378*)TlsGetValue(DAT_0126835c);
    if (timer->current < timer->end) {
        Event378* e = timer->current;
        e->tag = tag;
        unsigned time;
        __asm {
            rdtsc
            mov dword ptr[time], eax
        }
        e->time = time;
        timer->current = e + 1;
    }
}
struct Ray378 { hkVector4 from,to; unsigned filter; unsigned userData; };
struct OutputBase378 { hkVector4 normal; float fraction; int m_uiExtraInfo; };
struct Output378 : OutputBase378 { unsigned shapeKeys[8]; int keyIndex; };
struct Bool378 { char value; };
struct Shape378 {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual Bool378 RayCast(const Ray378&, Output378&) const;
    int field04,field08,field0c;
    hkpMultiRayShape::Ray* rays;
    int count;
    int field18;
    float radius;
};
struct Body378 { Shape378* shape; int other; hkTransform* transform; };
struct Contact378 {
    hkVector4 position;
    hkVector4 normal;
    unsigned index;
    unsigned material;
    unsigned userData;
    unsigned other;
};
struct ContactBuffer378 { Contact378* current; int context; };
struct ContactManager378 {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual unsigned short add(Body378*, Body378*, void*, ContactBuffer378*, int, Contact378*);
    virtual void slot4();
    virtual void remove(unsigned short, int);
};
struct Agent378 {
    virtual void slot0();
    int unknown;
    ContactManager378* manager;
    unsigned short* indices;
    void __thiscall hkpMultiRayConvexAgent_processCollision(Body378*, Body378*, void*, ContactBuffer378*);
};
inline __m128 transform378(const hkTransform& t, __m128 p) {
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p,p,0x55),t.m_kColumn1),_mm_mul_ps(_mm_shuffle_ps(p,p,0),t.m_kColumn0)),
                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p,p,0xaa),t.m_kColumn2),t.m_vTranslation));
}
struct Scratch378 { Ray378 ray; hkTransform relative; hkVector4 position; };
// @fnv 0x00d378e0
// src: HAVOK_SRC 0x00d378e0
void Agent378::hkpMultiRayConvexAgent_processCollision(Body378* a, Body378* b, void* input, ContactBuffer378* buffer) {
    timer378(DAT_010ceda8);
    struct { int count; Shape378* target; Shape378* source; } shapes;
    shapes.source = a->shape;
    shapes.target = b->shape;
    Scratch378 scratch;
    scratch.relative.hkTransform_setMulInverseMul(b->transform,a->transform);
    shapes.count = shapes.source->count;
    scratch.ray.filter = 0;
    scratch.ray.userData = 0;
    hkpMultiRayShape::Ray* current = shapes.source->rays;
    for (int i=0; i<shapes.count; ++current, ++i) {
        Output378 hit;
        scratch.ray.from.v = transform378(scratch.relative,current->m_kRayStart.v);
        scratch.ray.to.v = transform378(scratch.relative,current->m_kRayEnd.v);
        hit.fraction = 1.0f;
        hit.m_uiExtraInfo = -1;
        hit.shapeKeys[0] = -1;
        hit.keyIndex = 0;
        Bool378 DidHit = shapes.target->RayCast(scratch.ray,hit);
        if (!DidHit.value) {
            unsigned short id = indices[i];
            if (id != 0xffff) {
                manager->remove(id,buffer->context);
                indices[i] = 0xffff;
            }
        } else {
            Contact378* contact = buffer->current;
            __m128 fraction = _mm_set1_ps(hit.fraction);
            scratch.position.v = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0,fraction),scratch.ray.from.v),_mm_mul_ps(fraction,scratch.ray.to.v));
            contact->position.setTransformedPos_00c7f640(*b->transform, scratch.position);
            contact->normal.hkVector4_setRotatedDir(reinterpret_cast<const hkRotation*>(b->transform), &hit.normal);
            contact->normal.w = (hit.fraction-1.0)*current->m_kRayStart.w+shapes.source->radius;
            if (indices[i] == 0xffff) {
                unsigned short iContactPointId = manager->add(a,b,input,buffer,0,contact); indices[i] = iContactPointId;
            }
            if (indices[i] != 0xffff) {
                ++buffer->current;
                contact->index = indices[i];
            }
        }
    }
    timer378(DAT_010c41f8);
}
