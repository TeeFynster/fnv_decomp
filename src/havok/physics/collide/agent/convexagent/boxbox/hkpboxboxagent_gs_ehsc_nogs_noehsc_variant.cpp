#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/V4.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpBoxShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"

// The shared constructors are out of line; these temporary values need no initialization.
__forceinline V4::V4() {}
__forceinline void V4::operator=(const V4& other) { bits = other.bits; }
__forceinline hkTransform::hkTransform() {}

// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl hkpBoxBoxAgent_staticGetClosestPoints(void* a, void* b, void* c, void* d);
// @fnv 0x00d406a0
// src: HAVOK_SRC 0x00d406a0
extern "C" void __stdcall hkpBoxBoxAgent_getClosestPoints(void* a, void* b, void* c, void* d)
{
    hkpBoxBoxAgent_staticGetClosestPoints(a, b, c, d);
}

__forceinline void setRotatedInverseDir_d409(hkVector4& out, const hkRotation& r, const hkVector4& v)
{
    __m128 c0 = r.m_kColumn0.m_vComponents;
    __m128 c1 = r.m_kColumn1.m_vComponents;
    __m128 c2 = r.m_kColumn2.m_vComponents;
    {
        __m128 t = _mm_unpacklo_ps(c0, c1);
        __m128 ct = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(t, c2);
        c1 = _mm_movehl_ps(c0, t);
        c1 = _mm_shuffle_ps(c1, c2, 0xd4);
        c2 = _mm_shuffle_ps(ct, c2, 0xe4);
    }
    __m128 b1 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    __m128 b0 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    __m128 b2 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(b1, c1), _mm_mul_ps(b0, c0)), _mm_mul_ps(b2, c2));
}

struct RotatedDir_d409
{
    hkVector4 unk00;
    hkVector4 unk10;
    hkRotation m_rotation;
    hkVector4 m_dir;
    hkVector4 unk60;
    hkVector4 unk70;
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unkA0;
    hkVector4 unkB0;
    hkVector4 m_dirCopy;
    hkVector4 m_localDir;

    void UpdateFields_00d40940();
};

// @fnv 0x00d40940
// src: GUESS 0x00d40940 (confidence: low)
void RotatedDir_d409::UpdateFields_00d40940()
{
    m_dirCopy.m_vComponents = m_dir.m_vComponents;
    setRotatedInverseDir_d409(m_localDir, m_rotation, m_dirCopy);
}

extern "C" unsigned __int64 __rdtsc(void);
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier();
struct Parameters
{
    int unk00;
    int unk04;
    float offset08;
};
struct Job
{
    __forceinline Job() {}
    hkpCdBody* first;
    hkpCdBody* second;
    Parameters* parameters08;
    void* data0C;
    void* unk10;
    const void* dataA14;
    const void* dataB18;
    hkTransform transform20;
    V4 minA60, minB70;
    hkVector4 tolerance80, expandedA90, expandedBA0;
    float toleranceB0;
    float epsilonB4;
    int unkB8;
    int unkBC;
    hkVector4 translationC0, translationD0, translationE0, translationF0;
    hkVector4 axis100, axis110, axis120;
    void hkpBoxBoxCollisionDetection_calcManifold(hkpCdBodyPairCollector* callback);
};
class Manager
{
  public:
    void* unk00;
    void* unk04;
    void* data08;
    void* unk0C;
    hkpCdBodyPairCollector callback10;
    void hkpBoxBoxAgent_processCollision(hkpCdBody* a, hkpCdBody* b, Parameters* parameters, void* p4);
};
inline void timer(const char* tag)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* r = reinterpret_cast<hkMonitorStream::TimerCommand*>(s->m_end.m_storage);
    if (r < reinterpret_cast<hkMonitorStream::TimerCommand*>(s->m_capacityMinus16.m_storage))
    {
        r->m_commandAndMonitor = tag;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        r->m_time0 = stamp;
        s->m_end.m_storage = reinterpret_cast<char*>(r + 1);
    }
}
inline __m128 splat(float v)
{
    return _mm_set1_ps(v);
}
// @fnv 0x00d40280
// src: HAVOK_SRC 0x00d40280
void Manager::hkpBoxBoxAgent_processCollision(hkpCdBody* a, hkpCdBody* b, Parameters* parameters, void* p4)
{
    timer("TtBoxBox");
    const hkpBoxShape* kIter;
    kIter = static_cast<const hkpBoxShape*>(a->m_pCollisionShape);
    const hkpBoxShape* tolerance = static_cast<const hkpBoxShape*>(b->m_pCollisionShape);
    struct Work
    {
        __forceinline Work() {}
        V4 minB, minA;
        hkTransform t;
        Job job;
    } w;
    V4* __restrict minA = &w.minA;
    V4* __restrict minB = &w.minB;
    _mm_store_ps(&minA->x, _mm_add_ps(splat(kIter->getRadius()), kIter->m_vHalfExtents.m_vComponents));
    _mm_store_ps(&minB->x, _mm_add_ps(splat(tolerance->getRadius()), tolerance->m_vHalfExtents.m_vComponents));
    hkTransform* __restrict t = &w.t;
    Job* __restrict job = &w.job;
    t->hkTransform_setMulInverseMul(a->m_pMotionState, b->m_pMotionState);
    const float shapeB = parameters->offset08;
    job->toleranceB0 = shapeB;
    job->epsilonB4 = 0.01f;
    job->transform20.m_row0 = t->m_row0;
    job->transform20.m_row1 = t->m_row1;
    job->transform20.m_row2 = t->m_row2;
    job->data0C = data08;
    job->parameters08 = parameters;
    job->unk10 = p4;
    job->dataA14 = a->m_pMotionState;
    job->dataB18 = b->m_pMotionState;
    job->transform20.m_row3 = t->m_row3;
    job->first = a;
    job->second = b;
    job->minA60 = *minA;
    job->minB70 = *minB;
    job->tolerance80.m_vComponents = splat(shapeB);
    job->expandedA90.m_vComponents = _mm_add_ps(splat(shapeB), minA->m);
    job->expandedBA0.m_vComponents = _mm_add_ps(splat(shapeB), minB->m);
    job->hkpBoxBoxCollisionDetection_calcManifold(&callback10);
    timer("Et");
}

extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier();
struct Query
{
    __forceinline Query() {}
    hkpCdBody* first;
    hkpCdBody* second;
    unsigned int count08, count0C, count10;
    const void* dataA;
    const void* dataB;
    unsigned int unk1C;
    hkTransform transform20;
    V4 minA60, minB70;
    hkVector4 tolerance80, expandedA90, expandedBA0;
    float toleranceB0;
    float epsilonB4;
    int unkB8;
    int unkBC;
    hkVector4 translationC0, translationD0, separationE0, separationF0, axis100, axis110, axis120;
    void UpdateFields_00d40940();
    int ProcessAndReturnValue_00db0ec0(hkVector4*);
    __forceinline void init(hkpCdBody* a, hkpCdBody* b, const hkTransform& t, const V4& minA, const V4& minB, float tolerance,
                            float epsilon)
    {
        first = a;
        second = b;
        count08 = 0;
        count0C = 0;
        count10 = 0;
        dataA = a->m_pMotionState;
        dataB = b->m_pMotionState;
        transform20.m_row0 = t.m_row0;
        transform20.m_row1 = t.m_row1;
        transform20.m_row2 = t.m_row2;
        transform20.m_row3 = t.m_row3;
        minA60 = minA;
        minB70 = minB;
        toleranceB0 = tolerance;
        epsilonB4 = epsilon;
        tolerance80.m_vComponents = _mm_set1_ps(tolerance);
        expandedA90.m_vComponents = _mm_add_ps(_mm_set1_ps(tolerance), minA.m);
        expandedBA0.m_vComponents = _mm_add_ps(_mm_set1_ps(tolerance), minB.m);
    }
};
// @fnv 0x00d406c0
// src: XBOX_PDB 0x00d406c0
void __cdecl hkpBoxBoxAgent_staticGetPenetrations(hkpCdBody* a, hkpCdBody* b, Parameters* parameters, hkpCdBodyPairCollector* callback)
{
    timer("TtBoxBox");
    const hkpBoxShape* shapeA = static_cast<const hkpBoxShape*>(a->m_pCollisionShape);
    const hkpBoxShape* shapeB = static_cast<const hkpBoxShape*>(b->m_pCollisionShape);
    struct CollisionWork
    {
        __forceinline CollisionWork() {}
        V4 minB, minA;
        hkTransform relative;
        Query query;
    } work;
    V4* __restrict minA = &work.minA;
    V4* __restrict minB = &work.minB;
    _mm_store_ps(&minA->x, _mm_add_ps(splat(shapeA->getRadius()), shapeA->m_vHalfExtents.m_vComponents));
    _mm_store_ps(&minB->x, _mm_add_ps(splat(shapeB->getRadius()), shapeB->m_vHalfExtents.m_vComponents));
    hkTransform* __restrict transform = &work.relative;
    Query* __restrict query = &work.query;
    transform->hkTransform_setMulInverseMul(a->m_pMotionState, b->m_pMotionState);
    query->init(a, b, *transform, *minA, *minB, parameters->offset08, 0.01f);
    query->UpdateFields_00d40940();
    if (!query->ProcessAndReturnValue_00db0ec0(&query->tolerance80))
        callback->AddCdBodyPair(*a, *b);
    timer("Et");
}
