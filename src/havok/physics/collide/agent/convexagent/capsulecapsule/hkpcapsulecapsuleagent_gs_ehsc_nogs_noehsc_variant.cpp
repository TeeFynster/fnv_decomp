
// src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"

struct Callback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void invoke(unsigned short, int);
};
struct FUN_00d3b3d0_Class
{
    virtual void release(int);
    int unk04;
    Callback* unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    void InvokeCallbacksAndRelease(int);
};
typedef void(__cdecl* HandlerFn)();
void __cdecl hkpCapsuleCapsuleAgent_createCapsuleCapsuleAgent();
void __cdecl hkpCapsuleCapsuleAgent_staticGetPenetrations();
void __cdecl UpdateFields_00d3bd80();
void __cdecl Object_ProcessEntries_00daf8e0();
struct HandlerSet
{
    HandlerFn m_pfnFirst;
    HandlerFn m_pfnSecond;
    HandlerFn m_pfnThird;
    HandlerFn m_pfnFourth;
    char m_cFlagA;
    char m_cFlagB;
};
struct Registry
{
    void AppendRecordAndRegisterAgents(HandlerSet* apHandlers, int aiFirst, int aiSecond);
};
void __cdecl RegisterHandlers(Registry* apRegistry);
void __cdecl hkpCapsuleCapsuleAgent_staticGetPenetrations(const void* a, const void* b, const void* c, void* d);
struct D3B6D0Agent
{
    virtual void ForwardToHandler(const void* a, const void* b, const void* c, void* d);
};

extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
#include <windows.h>
// The profiler keeps one 12 byte entry per marked call site in a per thread buffer.
// The entry holds the name of the marked site and a timestamp taken from the TSC.
struct ProfilerTls
{
    int unk00;
    char* unk04;  // write cursor
    char* unk08;
    char* unk0C;  // end of the buffer
};

// One row of a 4x4 matrix.  The rows are copied as raw dwords, so the
// stand-in keeps them as 32 bit words.
struct __declspec(align(16)) MatRow
{
    unsigned int c0, c1, c2, c3;
};

// The four rows of a transform matrix.  Row 0 of the source matrix is kept in
// the last slot, row 1 in the first one and so on (the rows are rotated).
struct MatSlots
{
    MatRow m0;  // slot 0  <- source row 1
    MatRow m1;  // slot 1  <- source row 2
    MatRow m2;  // slot 2  <- source row 3
    MatRow m3;  // slot 3  <- source row 0
};

// The two transformed segments: the ray (v2,v3) and the segment (v0,v1).
struct Segments
{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    Vec4 v3;
};

// The two direction vectors of the ray and of the segment.
struct Rays
{
    Vec4 edge;
    Vec4 dir;
};

// Result of the ray / segment intersection.
struct RayHit
{
    Vec4 point;
    Vec4 point2;
    float distSq;
};

// A capsule: four points (the last two are the segment ends) plus its transform.
struct Capsule
{
    float* unk00;
    int unk04;
    float* unk08;
};

struct HitHandler
{
    virtual void slot00();
    virtual void slot04(Capsule*, Capsule*);
};

extern int DAT_0126835c;
extern char DAT_010cefcc[];
extern char DAT_010c41f8[];
extern "C" void _ReadWriteBarrier();

void __cdecl hkLineSegmentUtil_closestLineSegLineSeg(void*, void*, void*, void*, void*);

template <class T> struct LazyPtr
{
    T* p;
    LazyPtr(T* q) : p(q)
    {}
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
};
// @fnv 0x00d3b420
// src: XBOX_PDB 0x00d3b420
void __cdecl hkpCapsuleCapsuleAgent_staticGetPenetrations(Capsule* pFirst, Capsule* pSecond, void* pUnused, HitHandler* pHandler)
{
    ProfilerTls* pTls = (ProfilerTls*)TlsGetValue(DAT_0126835c);
    char* pCur = pTls->unk04;
    if (pCur < pTls->unk0C)
    {
        *(const char**)pCur = DAT_010cefcc;
        _ReadWriteBarrier();
        volatile unsigned ts = (unsigned)__rdtsc();
        *(unsigned*)(pCur + 4) = ts;
        pTls->unk04 = pCur + 12;
    }

    // The point arrays of both capsules and the transform matrices.
    const float* pSrc = pFirst->unk00;
    const float* pSrc2 = pSecond->unk00;

    // --- the transform matrix of the first capsule ---
    // The rows are kept rotated: row 0 ends up in the last slot.
    MatSlots mat;
    const MatRow* m = (const MatRow*)pFirst->unk08;
    const unsigned int* s = (const unsigned int*)m;
    unsigned int* d = (unsigned int*)&mat;
    mat.m3.c0 = m[0].c0;
    mat.m3.c1 = m[0].c1;
    mat.m3.c2 = m[0].c2;
    mat.m3.c3 = m[0].c3;
    mat.m0.c0 = m[1].c0;
    mat.m0.c1 = m[1].c1;
    mat.m0.c2 = m[1].c2;
    mat.m0.c3 = m[1].c3;
    mat.m1.c0 = m[2].c0;
    mat.m1.c1 = m[2].c1;
    mat.m1.c2 = m[2].c2;
    mat.m1.c3 = m[2].c3;
    mat.m2.c0 = m[3].c0;
    mat.m2.c1 = m[3].c1;
    mat.m2.c2 = m[3].c2;
    mat.m2.c3 = m[3].c3;

    Segments seg;

    // --- transform the two segment ends of the first capsule ---
    // The last two points of the capsule are the ends of its segment; they are
    // transformed by the matrix and written back into the segment slots.

    __m128 m0 = _mm_load_ps((const float*)&mat.m3);
    __m128 m1 = _mm_load_ps((const float*)&mat.m0);
    __m128 m2 = _mm_load_ps((const float*)&mat.m1);
    __m128 m3 = _mm_load_ps((const float*)&mat.m2);
    for (int i = 1; i >= 0; --i)
    {
        __m128 r = _mm_load_ps(pSrc + (i + 2) * 4);
        __m128 b = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x55), m1);
        __m128 a = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x00), m0);
        __m128 c = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xaa), m2);
        *((__m128*)&seg.v2 + i) = _mm_add_ps(_mm_add_ps(b, a), _mm_add_ps(c, m3));
    }

    // --- the transform matrix of the second capsule ---
    m = (const MatRow*)pSecond->unk08;
    const unsigned int* s2 = (const unsigned int*)m;
    unsigned int* d2 = (unsigned int*)&mat;
    mat.m2.c0 = m[0].c0;
    mat.m2.c1 = m[0].c1;
    mat.m2.c2 = m[0].c2;
    mat.m2.c3 = m[0].c3;
    mat.m1.c0 = m[1].c0;
    mat.m1.c1 = m[1].c1;
    mat.m1.c2 = m[1].c2;
    mat.m1.c3 = m[1].c3;
    mat.m0.c0 = m[2].c0;
    mat.m0.c1 = m[2].c1;
    mat.m0.c2 = m[2].c2;
    mat.m0.c3 = m[2].c3;
    mat.m3.c0 = m[3].c0;
    mat.m3.c1 = m[3].c1;
    mat.m3.c2 = m[3].c2;
    mat.m3.c3 = m[3].c3;

    // --- transform the two segment ends of the second capsule ---

    m0 = _mm_load_ps((const float*)&mat.m2);
    m1 = _mm_load_ps((const float*)&mat.m1);
    m2 = _mm_load_ps((const float*)&mat.m0);
    m3 = _mm_load_ps((const float*)&mat.m3);
    for (int i = 1; i >= 0; --i)
    {
        __m128 r = _mm_load_ps(pSrc2 + (i + 2) * 4);
        __m128 b = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x55), m1);
        __m128 a = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x00), m0);
        __m128 c = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xaa), m2);
        *((__m128*)&seg.v0 + i) = _mm_add_ps(_mm_add_ps(b, a), _mm_add_ps(c, m3));
    }

    // The direction of the two segments.
    Rays rays;
    *(__m128*)&rays.dir = _mm_sub_ps(*(const __m128*)&seg.v3, *(const __m128*)&seg.v2);
    *(__m128*)&rays.edge = _mm_sub_ps(*(const __m128*)&seg.v1, *(const __m128*)&seg.v0);

    // Intersect the ray with the segment.
    RayHit hit;
    hkLineSegmentUtil_closestLineSegLineSeg(&seg.v2, &rays.dir, &seg.v0, &rays.edge, &hit);

    // The two radii decide whether the capsules overlap.
    float t = pSrc[4] + pSrc2[4];
    if (hit.distSq < t * t)
    {
        pHandler->slot04(pFirst, pSecond);
    }

    // --- leave the profiler ---
    pTls = (ProfilerTls*)TlsGetValue(DAT_0126835c);
    pCur = pTls->unk04;
    if (pCur < pTls->unk0C)
    {
        *(const char**)pCur = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned ts = (unsigned)__rdtsc();
        *(unsigned*)(pCur + 4) = ts;
        pTls->unk04 = pCur + 12;
    }
}

#include <xmmintrin.h>
namespace fnv_00d3b6f0 {
struct __declspec(align(16)) MatRow
{
    unsigned int c0, c1, c2, c3;
};
struct MatSlots
{
    MatRow m0, m1, m2, m3;
};
struct Segments
{
    Vec4 v0, v1, v2, v3;
};
struct Capsule
{
    float* unk00;
    int unk04;
    float* unk08;
};
struct Context
{
    int unk00, unk04;
    float scale;
};
struct TransformOutput
{
    float rows[3][8];
};
void __cdecl hkCollideCapsuleUtilManifoldCapsVsCaps(const void*, float, const void*, float, TransformOutput*);
// @fnv 0x00d3b6f0
// src: XBOX_PDB 0x00d3b6f0
static __declspec(noinline) void getThreeClosestPointsInl(Capsule* first, TransformOutput* dst, Context* context, Capsule* second)
{
    const float* nodeA = first->unk00;
    float scaleValue = context->scale;
    dst->rows[0][7] = scaleValue;
    dst->rows[1][7] = scaleValue;
    dst->rows[2][7] = scaleValue;
    const float* nodeB = second->unk00;
    Vec4 resultA[2], resultB[2];
    {
        MatRow row0, row1, row2, row3;
        const MatRow* m = (const MatRow*)first->unk08;
        row0.c0 = m[0].c0;
        row0.c1 = m[0].c1;
        row0.c2 = m[0].c2;
        row0.c3 = m[0].c3;
        row1.c0 = m[1].c0;
        row1.c1 = m[1].c1;
        row1.c2 = m[1].c2;
        row1.c3 = m[1].c3;
        row2.c0 = m[2].c0;
        row2.c1 = m[2].c1;
        row2.c2 = m[2].c2;
        row2.c3 = m[2].c3;
        row3.c0 = m[3].c0;
        row3.c1 = m[3].c1;
        row3.c2 = m[3].c2;
        row3.c3 = m[3].c3;
        __m128 r0 = *(const __m128*)&row0;
        __m128 r1 = *(const __m128*)&row1;
        __m128 r2 = *(const __m128*)&row2;
        __m128 r3 = *(const __m128*)&row3;
        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(nodeA + (i + 2) * 4);
            __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), r1);
            __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), r0);
            __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), r2);
            *((__m128*)resultA + i) = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, r3));
        }
    }
    {
        MatRow row0, row1, row2, row3;
        const MatRow* m = (const MatRow*)second->unk08;
        row3.c0 = m[0].c0;
        row3.c1 = m[0].c1;
        row3.c2 = m[0].c2;
        row3.c3 = m[0].c3;
        row2.c0 = m[1].c0;
        row2.c1 = m[1].c1;
        row2.c2 = m[1].c2;
        row2.c3 = m[1].c3;
        row1.c0 = m[2].c0;
        row1.c1 = m[2].c1;
        row1.c2 = m[2].c2;
        row1.c3 = m[2].c3;
        row0.c0 = m[3].c0;
        row0.c1 = m[3].c1;
        row0.c2 = m[3].c2;
        row0.c3 = m[3].c3;
        __m128 r0 = *(const __m128*)&row3;
        __m128 r1 = *(const __m128*)&row2;
        __m128 r2 = *(const __m128*)&row1;
        __m128 r3 = *(const __m128*)&row0;
        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(nodeB + (i + 2) * 4);
            __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), r1);
            __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), r0);
            __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), r2);
            *((__m128*)resultB + i) = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, r3));
        }
    }
    hkCollideCapsuleUtilManifoldCapsVsCaps(resultA, nodeA[4], resultB, nodeB[4], dst);
}
Context* volatile contextSource;
Capsule* volatile firstSource;
TransformOutput* volatile outputSource;
Capsule* volatile secondSource;
void invokeTransform()
{
    getThreeClosestPointsInl(firstSource, outputSource, contextSource, secondSource);
}
}  // namespace fnv_00d3b6f0

struct TimerEntry
{
    const char* tag;
    unsigned stamp;
    unsigned extra;
};

struct CapsuleShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kVertexA;
    Vec4 m_kVertexB;

    const Vec4* GetIndexedVertices() const
    {
        return &m_kVertexA;
    }
};

struct CdBody
{
    CapsuleShape* m_pCollisionShape;
    int unk04;
    const MatSlots* m_kMotionState;
};

struct CollisionInput
{
    int unk00;
    int unk04;
    float m_fScalar;
};

struct PointResult
{
    struct
    {
        float x, y, z, w;
    } m_vHitNormal;
    float m_posAndDistX;
    float m_posAndDistY;
    float m_posAndDistZ;
    float m_fClosestPointDistanceSquared;
};

struct BasisRows
{
    MatRow row1, row0, row2;
};
union EndpointScratch
{
    MatRow row;
    __m128 endpoints[2];  // Raw scratch storage permits overlap with row without constructing Vec4.
};
struct ContactWorkspace
{
    PointResult results[3];
    Vec4 verticesA[2];
};

struct AlignedPairData
{
    Vec4 m_vec0;
    Vec4 m_vec1;
    unsigned int m_usContactPointId;
    int unk24;
    int unk28;
    int unk2C;
};

struct Collector
{
    AlignedPairData* m_cur;
    int m_unk04;
};

struct MyCallback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual unsigned short slot0C(const CdBody* a, const CdBody* b, const CollisionInput* c, Collector* d, int e,
                                  PointResult* f);
    virtual void slot10();
    virtual void invoke(unsigned short id, int unk);
};

extern "C" void __cdecl hkCollideCapsuleUtilManifoldCapsVsCaps(const Vec4* verticesA, float radiusA, const Vec4* verticesB, float radiusB,
                                     PointResult* results);

struct Agent : FUN_00d3b3d0_Class
{
    void hkpCapsuleCapsuleAgent_processCollision(const CdBody* bodyA, const CdBody* bodyB, const CollisionInput* input, Collector* collector);
};

// @fnv 0x00d3c060
// src: HAVOK_SRC 0x00d3c060
void Agent::hkpCapsuleCapsuleAgent_processCollision(const CdBody* bodyA, const CdBody* bodyB, const CollisionInput* input, Collector* collector)
{
    ProfilerTls* ms = (ProfilerTls*)TlsGetValue(DAT_0126835c);
    {
        TimerEntry* cursor = (TimerEntry*)ms->unk04;
        if (cursor < (TimerEntry*)ms->unk0C)
        {
            cursor->tag = DAT_010cefcc;
            _ReadWriteBarrier();
            volatile unsigned timestamp = (unsigned)__rdtsc();
            cursor->stamp = timestamp;
            ms->unk04 = (char*)(cursor + 1);
        }
    }

    BasisRows basis;
    EndpointScratch scratch;
    ContactWorkspace contacts;

    float tol = input->m_fScalar;
    CapsuleShape* capA = bodyA->m_pCollisionShape;
    const MatSlots* transformA = bodyA->m_kMotionState;
    contacts.results[0].m_fClosestPointDistanceSquared = tol;
    contacts.results[1].m_fClosestPointDistanceSquared = tol;
    CapsuleShape* capB = bodyB->m_pCollisionShape;
    contacts.results[2].m_fClosestPointDistanceSquared = tol;

    {
        basis.row0.c0 = transformA->m0.c0;
        basis.row0.c1 = transformA->m0.c1;
        basis.row0.c2 = transformA->m0.c2;
        basis.row0.c3 = transformA->m0.c3;
        __m128 m0 = _mm_load_ps((const float*)&basis.row0);
        basis.row1.c0 = transformA->m1.c0;
        basis.row1.c1 = transformA->m1.c1;
        basis.row1.c2 = transformA->m1.c2;
        basis.row1.c3 = transformA->m1.c3;
        __m128 m1 = _mm_load_ps((const float*)&basis.row1);
        basis.row2.c0 = transformA->m2.c0;
        basis.row2.c1 = transformA->m2.c1;
        basis.row2.c2 = transformA->m2.c2;
        basis.row2.c3 = transformA->m2.c3;
        scratch.row.c0 = transformA->m3.c0;
        __m128 m2 = _mm_load_ps((const float*)&basis.row2);
        scratch.row.c1 = transformA->m3.c1;
        scratch.row.c2 = transformA->m3.c2;
        scratch.row.c3 = transformA->m3.c3;
        __m128 m3 = _mm_load_ps((const float*)&scratch.row);

        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(&capA->GetIndexedVertices()[i].x);
            __m128 y = _mm_shuffle_ps(v, v, 0x55);
            __m128 x = _mm_shuffle_ps(v, v, 0x00);
            __m128 r0 = _mm_mul_ps(x, m0);
            __m128 r1 = _mm_mul_ps(y, m1);
            r1 = _mm_add_ps(r1, r0);

            __m128 z = _mm_shuffle_ps(v, v, 0xaa);
            __m128 r2 = _mm_mul_ps(z, m2);
            r2 = _mm_add_ps(r2, m3);

            __m128 res = _mm_add_ps(r1, r2);
            *((__m128*)contacts.verticesA + i) = res;
        }
    }

    {
        const MatSlots* transformB = bodyB->m_kMotionState;
        scratch.row.c0 = transformB->m0.c0;
        scratch.row.c1 = transformB->m0.c1;
        scratch.row.c2 = transformB->m0.c2;
        scratch.row.c3 = transformB->m0.c3;
        __m128 m0 = _mm_load_ps((const float*)&scratch.row);
        basis.row2.c0 = transformB->m1.c0;
        basis.row2.c1 = transformB->m1.c1;
        basis.row2.c2 = transformB->m1.c2;
        basis.row2.c3 = transformB->m1.c3;
        __m128 m1 = _mm_load_ps((const float*)&basis.row2);
        basis.row1.c0 = transformB->m2.c0;
        basis.row1.c1 = transformB->m2.c1;
        basis.row1.c2 = transformB->m2.c2;
        basis.row1.c3 = transformB->m2.c3;
        __m128 m2 = _mm_load_ps((const float*)&basis.row1);
        basis.row0.c0 = transformB->m3.c0;
        basis.row0.c1 = transformB->m3.c1;
        basis.row0.c2 = transformB->m3.c2;
        basis.row0.c3 = transformB->m3.c3;
        __m128 m3 = _mm_load_ps((const float*)&basis.row0);

        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(&capB->GetIndexedVertices()[i].x);
            __m128 y = _mm_shuffle_ps(v, v, 0x55);
            __m128 x = _mm_shuffle_ps(v, v, 0x00);
            __m128 r0 = _mm_mul_ps(x, m0);
            __m128 r1 = _mm_mul_ps(y, m1);
            r1 = _mm_add_ps(r1, r0);

            __m128 z = _mm_shuffle_ps(v, v, 0xaa);
            __m128 r2 = _mm_mul_ps(z, m2);
            r2 = _mm_add_ps(r2, m3);

            __m128 res = _mm_add_ps(r1, r2);
            *((__m128*)scratch.endpoints + i) = res;
        }
    }

    hkCollideCapsuleUtilManifoldCapsVsCaps(contacts.verticesA, capA->m_fSphereRadius, (const Vec4*)scratch.endpoints, capB->m_fSphereRadius, contacts.results);

    Collector* output = collector;
    PointResult* res = contacts.results;
    unsigned short* contactId = &this->unk0C;
    for (int i = 3; i != 0; --i)
    {
        const CollisionInput* collisionInput = input;
        if (res->m_fClosestPointDistanceSquared < collisionInput->m_fScalar)
        {
            if (*contactId == 0xffff)
            {
                *contactId = ((MyCallback*)this->unk08)->slot0C(bodyA, bodyB, collisionInput, output, 0, res);
                if (*contactId == 0xffff)
                {
                    goto next;
                }
            }
            AlignedPairData* outPoint = output->m_cur;
            __m128 normal = _mm_load_ps(&res->m_vHitNormal.x);
            output->m_cur = outPoint + 1;
            _mm_store_ps(&outPoint->m_vec0.x, normal);
            _mm_store_ps(&outPoint->m_vec1.x, _mm_load_ps(&res->m_posAndDistX));
            outPoint->m_usContactPointId = *contactId;
        }
        else
        {
            if (*contactId != 0xffff)
            {
                ((MyCallback*)this->unk08)->invoke(*contactId, output->m_unk04);
                *contactId = 0xffff;
            }
        }
    next:
        contactId++;
        res++;
    }

    ms = (ProfilerTls*)TlsGetValue(DAT_0126835c);
    {
        TimerEntry* cursor = (TimerEntry*)ms->unk04;
        if (cursor < (TimerEntry*)ms->unk0C)
        {
            cursor->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned timestamp = (unsigned)__rdtsc();
            cursor->stamp = timestamp;
            ms->unk04 = (char*)(cursor + 1);
        }
    }
}
