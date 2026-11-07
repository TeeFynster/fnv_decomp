// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/Transform.h"

extern "C" void __cdecl hkpSphereSphereAgent_staticGetPenetrations(void* a, void* b, void* c, void* d);
void __stdcall hkpSphereSphereAgent_getPenetrations(void* a, void* c, void* b, void* d);
struct S_00d3f660_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release(unsigned short id, void* arg);
};
struct S_00d3f660
{
    virtual ~S_00d3f660();
    int unk4;
    S_00d3f660_Owner* unk8;
    unsigned short unkC;
    void ReleaseAndDelete(void* arg);
};

#include <xmmintrin.h>
#include <windows.h>
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

// ---------------------------------------------------------------------------
// stand-ins for the game's types
// ---------------------------------------------------------------------------

struct S_00d3f780_Node
{  // the shape/node referenced by the bodies
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float radius() const
    {
        return unk10;
    }  // radius
};

struct S_00d3f780_In
{
    S_00d3f780_Node* unk00;
    int unk04;
    Transform* unk08;
};

struct S_00d3f780_C
{
    int unk00;
    int unk04;
    float unk08;
};

struct S_00d3f780_Out
{                  // one contact record (0x30 bytes)
    __m128 unk00;  // contact point
    __m128 unk10;
    unsigned int unk20;  // owner id
};

struct S_00d3f780_D
{
    S_00d3f780_Out* unk00;
    void* unk04;
};

// the profiling scope the game pushes around every measured block
struct S_00d3f780_Scope
{
    int unk00;
    char* unk04;
    char* unk08;
    char* unk0C;
};

struct S_00d3f780_Rec
{
    const void* vtbl;
    unsigned int time;
    unsigned int unk08;
};

struct S_00d3f780_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned short v3(S_00d3f780_In* a, S_00d3f780_In* b, S_00d3f780_C* c, S_00d3f780_D* d, int e,
                              S_00d3f780_Out* f);
    virtual void v4();
    virtual void Release(unsigned short id, void* arg);
};

struct S_00d3f780_Obj
{
    void* vptr;
    int unk4;
    S_00d3f780_Owner* unk8;
    unsigned short unkC;
    void hkpSphereSphereAgent_processCollision(S_00d3f780_In* a, S_00d3f780_In* b, S_00d3f780_C* c, S_00d3f780_D* d);
};

// ---------------------------------------------------------------------------
// the game's globals
// ---------------------------------------------------------------------------

extern DWORD DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern const __m128 DAT_01268370;
extern "C" double __cdecl sqrt(double);

// ---------------------------------------------------------------------------
// sphere against sphere: reports the contact to the owner and keeps the
// contact id in the object
// ---------------------------------------------------------------------------

// @fnv 0x00d3f780
// src: HAVOK_SRC 0x00d3f780
void S_00d3f780_Obj::hkpSphereSphereAgent_processCollision(S_00d3f780_In* a, S_00d3f780_In* b, S_00d3f780_C* c, S_00d3f780_D* d)
{
    float inv = 1.0f;
    union
    {
        volatile unsigned int tick;
        float distance;
    } scratch;
    {
        S_00d3f780_Scope* scope = (S_00d3f780_Scope*)TlsGetValue(DAT_0126835c);
        char* cur = scope->unk04;
        if (cur < scope->unk0C)
        {
            S_00d3f780_Rec* rec = (S_00d3f780_Rec*)cur;
            rec->vtbl = "TtSphereSphere";
            _ReadWriteBarrier();
            scratch.tick = (unsigned int)__rdtsc();
            rec->time = scratch.tick;
            scope->unk04 = cur + 12;
        }
    }

    // the sum of the two radii and the extra offset
    S_00d3f780_Node* shapeA = a->unk00;
    S_00d3f780_Node* shapeB = b->unk00;
    const __m128* posB = &b->unk08->r[3];

    // the vector between the two placements and its squared length
    __m128 diff = _mm_sub_ps(a->unk08->r[3], *posB);
    float rad = shapeA->radius() + shapeB->radius() + c->unk08;
    __m128 sq = _mm_mul_ps(diff, diff);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xAA), sum);
    _mm_store_ss(&scratch.distance, sum);

    if (scratch.distance < rad * rad)
    {  // the spheres overlap
        S_00d3f780_Out* out = d->unk00;
        float depth;
        if (scratch.distance > 0.0f)
        {
            float dist = (float)sqrt((double)scratch.distance);
            inv = 1.0f / dist;  // the inverse distance
            __m128 sc = _mm_load_ss(&inv);
            __m128 bcast = _mm_shuffle_ps(sc, sc, 0);
            out->unk10 = _mm_mul_ps(bcast, diff);  // the contact normal
            depth = scratch.distance * inv - (shapeA->radius() + shapeB->radius());
        }
        else
        {  // degenerate: the centres coincide
            out->unk10 = DAT_01268370;
            depth = -(shapeA->radius() + shapeB->radius());
        }
        // the point of contact on the second sphere
        float radiusB = shapeB->radius();
        __m128 rb = _mm_load_ss(&radiusB);
        __m128 bcast = _mm_shuffle_ps(rb, rb, 0);
        out->unk00 = _mm_add_ps(_mm_mul_ps(bcast, out->unk10), *posB);
        // the penetration depth shares the last component of the normal
        volatile float& distance = out->unk10.m128_f32[3];
        distance = depth;

        if (unkC == 0xffff)
        {  // no contact yet: ask the owner for one
            unkC = unk8->v3(a, b, c, d, 0, out);
        }
        if (unkC != 0xffff)
        {
            out->unk20 = unkC;
            ++d->unk00;
        }
    }
    else
    {  // the spheres are apart
        if (unkC != 0xffff)
        {  // drop the contact we had
            unk8->Release(unkC, d->unk04);
            unkC = 0xffff;
        }
    }

    {
        S_00d3f780_Scope* scope = (S_00d3f780_Scope*)TlsGetValue(DAT_0126835c);
        char* cur = scope->unk04;
        if (cur < scope->unk0C)
        {
            S_00d3f780_Rec* rec = (S_00d3f780_Rec*)cur;
            rec->vtbl = "Et";
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            rec->time = stamp;
            scope->unk04 = cur + 12;
        }
    }
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d3f980 {
#include <xmmintrin.h>
#include <math.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern unsigned int DAT_0126835c;
extern char DAT_010cf1a4[];
extern char DAT_010c41f8[];
extern __m128 DAT_01268370;
struct Shape
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    float radius;
    float getRadius() const
    {
        return radius;
    }
};
struct Body
{
    Shape* shape;
    int shapeKey;
    Transform* transform;
    const Body* parent;
};
struct Input
{
    int unk00;
    int unk04;
    float tolerance;
};
union ScalarScratch
{
    struct
    {
        float squaredDistance, distance, radiusB, radiusA;
    } collision;
    struct
    {
        volatile unsigned int beginStamp, endStamp;
    } profiling;
};
// hkpCdPoint: hkContactPoint (position, separating normal) then m_cdBodyA/m_cdBodyB, handed to
// hkpCdPointCollector::addCdPoint (slot 1). Local because Body is this unit's hkpCdBody view.
struct CdPoint
{
    __m128 position;
    __m128 normal;
    const Body* a;
    const Body* b;
};
struct Collector
{
    virtual void v0();
    virtual void AddContactPoint(const CdPoint&);
};
struct Event
{
    const char* tag;
    unsigned int time;
    unsigned int timeHigh;
};
struct Monitor
{
    void* vtable;
    Event* current;
    Event* begin;
    Event* end;
};
// @fnv 0x00d3f980
// src: HAVOK_SRC 0x00d3f980
void __stdcall hkpSphereSphereAgent_getClosestPoints(const Body* a, const Body* b, const Input* input, Collector* collector)
{
    ScalarScratch scratch;
    {
        Monitor* stream = (Monitor*)TlsGetValue(DAT_0126835c);
        Event* p = stream->current;
        if (p < stream->end)
        {
            p->tag = DAT_010cf1a4;
            _ReadWriteBarrier();
            scratch.profiling.beginStamp = (unsigned int)__rdtsc();
            p->time = scratch.profiling.beginStamp;
            stream->current = p + 1;
        }
    }
    const Shape* shapeA = a->shape;
    const Shape* shapeB = b->shape;
    const __m128& posB = b->transform->r[3];
    CdPoint point;
    point.a = a;
    point.b = b;
    __m128 diff = _mm_sub_ps(a->transform->r[3], posB);
    scratch.collision.distance = shapeB->getRadius() + shapeA->radius + input->tolerance;
    __m128 sq = _mm_mul_ps(diff, diff);
    __m128 add1 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 distSqM = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), add1);
    _mm_store_ss(&scratch.collision.squaredDistance, distSqM);
    if (scratch.collision.squaredDistance < scratch.collision.distance * scratch.collision.distance)
    {
        __m128 normal;
        if (scratch.collision.squaredDistance > 0.0f)
        {
            volatile float& rootValue = scratch.collision.distance;
            rootValue = sqrt((double)scratch.collision.squaredDistance);
            scratch.collision.distance = 1.0f / rootValue;

            normal = _mm_mul_ps(_mm_load1_ps(&scratch.collision.distance), diff);
            scratch.collision.distance = scratch.collision.distance * scratch.collision.squaredDistance;
        }
        else
        {
            scratch.collision.distance = 0.0f;
            normal = _mm_shuffle_ps(DAT_01268370, _mm_unpackhi_ps(DAT_01268370, point.normal), 0xc4);
        }
        point.normal = normal;
        scratch.collision.radiusA = shapeA->radius;
        scratch.collision.radiusB = shapeB->getRadius();
        scratch.collision.squaredDistance = shapeB->getRadius();
        __m128 scale = _mm_load_ss(&scratch.collision.squaredDistance);
        __m128 scaleCopy = scale;
        __m128 radiusBroadcast = _mm_shuffle_ps(scaleCopy, scale, 0);
        point.position = _mm_add_ps(_mm_mul_ps(radiusBroadcast, normal), posB);
        point.normal.m128_f32[3] = scratch.collision.distance - (scratch.collision.radiusA + scratch.collision.radiusB);
        collector->AddContactPoint(point);
    }
    {
        Monitor* stream = (Monitor*)TlsGetValue(DAT_0126835c);
        Event* p = stream->current;
        if (p < stream->end)
        {
            p->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            scratch.profiling.endStamp = (unsigned int)__rdtsc();
            p->time = scratch.profiling.endStamp;
            stream->current = p + 1;
        }
    }
}
}  // namespace fnv_00d3f980
