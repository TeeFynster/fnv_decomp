
// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent_gs_nogs_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* __cdecl hkpBoxBoxAgent_createBoxBoxAgent(void);
extern "C" void* __cdecl hkpBoxBoxAgent_staticGetPenetrations(void);
extern "C" void* __cdecl FUN_00dac450(void);
extern "C" void* __cdecl Object_ProcessEntries_00daf8e0(void);
struct FUN_00d408e0_1 {
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    unsigned char b1;
    unsigned char b2;
};
void __cdecl Object_InitializeAgentFunctionTable_00d408e0(FUN_00d408e0_1* a);
struct S_00d40180_Target {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(unsigned short id, void* p);
};
struct S_00d40180_Entry {
    unsigned short unk0;
    unsigned short m_iOwnerObjectOffset;
};
struct S_00d40180 {
    virtual ~S_00d40180();
    int unk4;
    S_00d40180_Target* m_target;
    int unkC;
    S_00d40180_Entry m_entries[8];
    unsigned char unk30;
    unsigned char m_uiItemCount;
    void DispatchAndDelete(void* p);
};
typedef void (__cdecl* D41FD0Func)();
struct D41FD0AgentFuncs {
    D41FD0Func m_pCreateFunc;
    D41FD0Func m_pQueryPenetrationsFunc;
    D41FD0Func m_pGetPenetrationsFunc;
    D41FD0Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct D41FD0CollisionDispatcher {
    void registerCollisionAgent(D41FD0AgentFuncs& f, int typeA, int typeB);
};
void __cdecl D41FD0CreateAgent();
void __cdecl D41FD0StaticGetPenetrations();
void __cdecl D41FD0StaticGetClosestPoints();
void __cdecl D41FD0StaticLinearCast();
void __cdecl RegisterStaticCollisionAgent(D41FD0CollisionDispatcher* dispatcher);
extern "C" const double DAT_010cf200;
extern "C" char DAT_010cf1c4;
extern "C" void* __cdecl FUN_00dacc00(void* a1, void* a2, void* a3, void* a4);
extern "C" void* __cdecl hkMemoryRouter_getInstance(void);
class Allocator
{
public:
    virtual void* Get0(void);
    virtual void* Alloc(unsigned int size);
};
class Holder
{
public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* m_pAllocator;
};
class SrcObj
{
public:
    void* unk00;
    void* unk04;
    float m_08;
};
class SubStub
{
public:
    void InitializeEmptyEntries();
};
class SpawnedObject
{
public:
    void* vptr;
    unsigned short m_04;
    unsigned short m_06;
    void* m_08;
};
void* hkpBoxBoxAgent_createBoxBoxAgent(void* a1, void* a2, void* a3, void* a4);
extern "C" void __cdecl hkpBoxBoxAgent_staticGetClosestPoints(void* a, void* b, void* c, void* d);
// @fnv 0x00d406a0
// src: HAVOK_SRC 0x00d406a0
extern "C" void __stdcall hkpBoxBoxAgent_getClosestPoints(void* a, void* b, void* c, void* d) {
    hkpBoxBoxAgent_staticGetClosestPoints(a, b, c, d);
}
typedef void (__cdecl *FUN_00d406c0_fn4)(void*, void*, void*, void*);
extern "C" void* __cdecl hkpBoxBoxAgent_staticGetPenetrations(void);
void __stdcall hkpBoxBoxAgent_getPenetrations(void* a1, void* a2, void* a3, void* a4);

#include <xmmintrin.h>
inline void* operator new(unsigned int, void* p) { return p; }



extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long DAT_0126835c;

struct TimerEntry70 {
    const char* name;
    unsigned int ticks;
    unsigned int unused;
};

struct TimerStream70 {
    void* unk00;
    TimerEntry70* top;
    TimerEntry70* start;
    TimerEntry70* end;
};

struct __declspec(align(16)) Vec70 {
    union { __m128 quad; struct { float x,y,z,w; }; };
    Vec70() {}
    Vec70& operator=(const Vec70& a) {
        quad=a.quad;
        return *this;
    }
};

struct Transform70 {
    Vec70 x, y, z, t;
    Transform70() {}
    Transform70(const Transform70& a) {
        x = a.x;
        y = a.y;
        z = a.z;
        t = a.t;
    }
    void hkTransform_setMulInverseMul(const Transform70*, const Transform70*);
};

struct Shape70 {
    int unk00, unk04, unk08, unk0c;
    float radius;
    int unk14, unk18, unk1c;
    Vec70 half;
    float GetRadius() const { return radius; }
};

struct Body70 {
    Shape70* shape;
    int unk04;
    Transform70* transform;
};

struct Input70 {
    int unk00, unk04;
    float tolerance;
    float GetTolerance() const { return tolerance; }
};

struct Contact70 {
    Vec70 point, normal;
    Body70* a;
    Body70* b;
};

struct Collector70 {
    virtual void Unknown();
    virtual void Add(Contact70*);
};

struct hkBool70 {
    char m_cBooleanValue;
    hkBool70() {}
    hkBool70(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

struct Query70 {
    Body70* bodyA;
    Body70* bodyB;
    int flags08, flags0c, flags10;
    Transform70* transformA;
    Transform70* transformB;
    int unk1c;
    Transform70 relative;
    Vec70 halfA, halfB, toleranceVec, expandedA, expandedB;
    float tolerance, epsilon;
    int unkB8, unkBC;
    Vec70 workC0, workD0, workE0, workF0, work100, work110, work120;

    Query70() {}
    __forceinline Query70(Body70* a, Body70* b, const Transform70& rel, const Vec70& ha, const Vec70& hb, float tol)
        : bodyA(a), bodyB(b), flags08(0), flags0c(0), flags10(0),
          transformA(a->transform), transformB(b->transform), relative(rel),
          halfA(ha), halfB(hb), tolerance(tol), epsilon(0.01f) {
        toleranceVec.quad=_mm_set1_ps(tol);
        expandedA.quad=_mm_add_ps(toleranceVec.quad, ha.quad);
        expandedB.quad=_mm_add_ps(toleranceVec.quad, hb.quad);
    }

    hkBool70 UpdateState_00db2750(Contact70*);
};

struct CollisionWork70 {
    Contact70 contact;
    Transform70 relative;
    Query70 query;
};

// @fnv 0x00d40470
// src: XBOX_PDB 0x00d40470
extern "C" void __cdecl hkpBoxBoxAgent_staticGetClosestPoints(void* first, void* second, void* rawInput, void* rawCollector)
{
    {
        TimerStream70* stream = (TimerStream70*)TlsGetValue(DAT_0126835c);
        if (stream->top < stream->end) {
            TimerEntry70* r = stream->top;
            r->name = "TtBoxBox";
            unsigned int stamp;
            __asm {
                rdtsc
                mov dword ptr[stamp], eax
            }
            r->ticks = stamp;
            stream->top = r + 1;
        }
    }

    Body70* a = (Body70*)first;
    Body70* b = (Body70*)second;
    Contact70 contact;
    Transform70 relative;
    Query70 query;
    Shape70* sa = a->shape;
    Shape70* sb = b->shape;
    Vec70 hb, ha;
    float r_ha=sa->GetRadius();
    ha; ha.quad=_mm_set1_ps(r_ha);
    ha.quad=_mm_add_ps(sa->half.quad, ha.quad);
    float r_hb=sb->GetRadius();
    hb; hb.quad=_mm_set1_ps(r_hb);
    hb.quad=_mm_add_ps(sb->half.quad, hb.quad);

    relative.hkTransform_setMulInverseMul(a->transform, b->transform);

    new (&query) Query70(a, b, relative, ha, hb, ((Input70*)rawInput)->GetTolerance());

    contact.a = a;
    contact.b = b;

    hkBool70 hit = query.UpdateState_00db2750(&contact);

    if (hit) {
        ((Collector70*)rawCollector)->Add(&contact);
    }

    {
        TimerStream70* stream = (TimerStream70*)TlsGetValue(DAT_0126835c);
        if (stream->top < stream->end) {
            TimerEntry70* r = stream->top;
            r->name = "Et";
            unsigned int stamp;
            __asm {
                rdtsc
                mov dword ptr[stamp], eax
            }
            r->ticks = stamp;
            stream->top = r + 1;
        }
    }
}
