
// src/havok/physics/collide/shape/misc/transform/hkptransformshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/transform/hkptransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpTransformShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkTransform.h"

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010cc448[];
extern const char str_010c41f8[];
struct CF5Mon
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pFreeList;
};
struct CF5Timer12
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int unk08;
};
struct CF5Vec
{
    float x, y, z, w;
};
struct CF5Rot
{
    CF5Vec c0;
    CF5Vec c1;
    CF5Vec c2;
};
struct CF5Transform
{
    CF5Rot rotation;
    CF5Vec translation;
};
struct CF5Input
{
    CF5Vec m_vFrom;
    CF5Vec m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct CF5Output
{
    CF5Vec m_vHitNormal;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_keys[8];
    int m_iValueAtOffset04;
    void hkVector4_setRotatedDir(const CF5Rot* rot, float* dir);
};
static __forceinline void xfInvPos(CF5Vec& dst, const CF5Transform& xf, const CF5Vec& v)
{
    __m128 delta = _mm_sub_ps(*(const __m128*)&v, *(const __m128*)&xf.translation);
    __m128 axis0 = *(const __m128*)&xf.rotation.c0;
    __m128 axis1 = *(const __m128*)&xf.rotation.c1;
    __m128 axis2 = *(const __m128*)&xf.rotation.c2;
    __m128 low = _mm_unpacklo_ps(axis0, axis1);
    __m128 last = _mm_shuffle_ps(_mm_unpackhi_ps(axis0, axis1), axis2, 0xe4);
    axis0 = _mm_movelh_ps(low, axis2);
    axis1 = _mm_shuffle_ps(_mm_movehl_ps(axis0, low), axis2, 0xd4);
    axis2 = last;
    __m128 first = _mm_mul_ps(axis0, _mm_shuffle_ps(delta, delta, 0));
    __m128 second = _mm_mul_ps(axis1, _mm_shuffle_ps(delta, delta, 0x55));
    __m128 third = _mm_mul_ps(axis2, _mm_shuffle_ps(delta, delta, 0xaa));
    *(__m128*)&dst = _mm_add_ps(_mm_add_ps(first, second), third);
}

static void stamp1(CF5Mon* mon, const char* tag)
{
    char* pos = mon->m_kRayEnd;
    if (pos < mon->m_pFreeList)
    {
        volatile unsigned int ticks;
        CF5Timer12* t = (CF5Timer12*)pos;
        t->m_name = tag;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        t->m_ticks = ticks;
        mon->m_kRayEnd = pos + sizeof(CF5Timer12);
    }
}

// @fnv 0x00cf5b20
hkBool hkpTransformShape::IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const
{
    const CF5Input& in = reinterpret_cast<const CF5Input&>(input);
    CF5Output& out = reinterpret_cast<CF5Output&>(output);
    {
        CF5Mon* mon = (CF5Mon*)TlsGetValue(DAT_0126835c);
        stamp1(mon, str_010cc448);
    }
    CF5Input sub = in;
    xfInvPos(sub.m_vFrom, reinterpret_cast<const CF5Transform&>(m_kMotionTransform), in.m_vFrom);
    xfInvPos(sub.m_vTo, reinterpret_cast<const CF5Transform&>(m_kMotionTransform), in.m_vTo);
    out.m_iValueAtOffset04++;
    hkBool hit = m_pContainedShape.m_pContainedShape->IntersectRayWithShape(
        reinterpret_cast<const ShapeRayCastQuery&>(sub), reinterpret_cast<ShapeRayCastOutput&>(out));
    out.m_iValueAtOffset04--;
    if (hit.m_cBooleanValue)
    {
        CF5Vec n = out.m_vHitNormal;
        out.hkVector4_setRotatedDir(&reinterpret_cast<const CF5Transform&>(m_kMotionTransform).rotation, &n.x);
        out.m_keys[out.m_iValueAtOffset04] = 0;
    }
    {
        CF5Mon* mon = (CF5Mon*)TlsGetValue(DAT_0126835c);
        stamp1(mon, str_010c41f8);
    }
    return hit;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern unsigned long hkMonitorStreamTlsIndex;

struct hkMonitorTimerCommand
{
    const char* m_pCommandName;
    hkUint32 m_uiStartTicks;
    hkUint32 m_uiEndTicks;
};

struct hkMonitorStreamInstance
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

// Havok's default constructors leave these temporary objects uninitialized.
inline hkTransform::hkTransform() {}
inline hkpCdBody::hkpCdBody() {}

struct hkVector4Sse
{
    __m128 m_vComponents;
};
struct SolTransform
{
    hkVector4Sse c0, c1, c2, tr;
};

struct hkpShapeRayCastInputSse
{
    hkVector4Sse m_vFrom;
    hkVector4Sse m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
    int unk28;
    int unk2C;
};

static __forceinline void timerCommand(const char* name)
{
    hkMonitorStreamInstance* stream = (hkMonitorStreamInstance*)TlsGetValue(hkMonitorStreamTlsIndex);
    char* end = stream->m_kRayEnd;
    if (end < stream->m_pCurrentCommand)
    {
        hkMonitorTimerCommand* h = (hkMonitorTimerCommand*)end;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile hkUint32 ticks = (hkUint32)__rdtsc();
        h->m_uiStartTicks = ticks;
        stream->m_kRayEnd = (char*)(h + 1);
    }
}

static __forceinline __m128 transformInversePos(const SolTransform& t, __m128 v)
{
    __m128 b = _mm_sub_ps(v, t.tr.m_vComponents);
    __m128 c0 = t.c0.m_vComponents;
    __m128 c1 = t.c1.m_vComponents;
    __m128 c2 = t.c2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0));
    c0 = _mm_movelh_ps(tmp, c2);
    tmp = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(tmp, c2, _MM_SHUFFLE(3, 1, 1, 0));
    c2 = ctmp;
    __m128 b0 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 0, 0, 0));
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 b1 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1));
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 b2 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(2, 2, 2, 2));
    __m128 r2 = _mm_mul_ps(c2, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

// @fnv 0x00cf5cc0
void hkpTransformShape::CastRayWithCollector(const ShapeRayCastQuery& ray, const hkpCdBody& cdBody,
                                            hkpRayHitCollector& collector) const
{
    const hkpShapeRayCastInputSse& input = reinterpret_cast<const hkpShapeRayCastInputSse&>(ray);
    timerCommand("TtrcTransform");

    __m128 from = transformInversePos(reinterpret_cast<const SolTransform&>(m_kMotionTransform), input.m_vFrom.m_vComponents);
    hkpShapeRayCastInputSse subInput = input;
    subInput.m_vFrom.m_vComponents = from;
    subInput.m_vTo.m_vComponents = transformInversePos(reinterpret_cast<const SolTransform&>(m_kMotionTransform), input.m_vTo.m_vComponents);

    hkTransform t;
    t.SetProduct(*static_cast<const hkTransform*>(cdBody.m_pMotionState), m_kMotionTransform);

    hkpCdBody body;
    body.m_pMotionState = &t;
    body.m_parent = &cdBody;
    const hkpShape* child = m_pContainedShape.m_pContainedShape;
    body.m_pCollisionShape = child;
    body.m_uiCollisionShapeKey = 0;
    child->CastRayWithCollector(reinterpret_cast<const ShapeRayCastQuery&>(subInput), body, collector);

    timerCommand("Et");
}
