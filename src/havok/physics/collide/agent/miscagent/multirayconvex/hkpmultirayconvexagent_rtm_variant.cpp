#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Preserve the intrinsic representation used by the original compiler; the SDK
// union's byte arrays would add /GS instrumentation to these stack records.
#define _INCLUDED_MM2
// Exe 0x00d37010 FUN_00d37010: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct { float x, y, z, w; };
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_load_ss(const float*);
}

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpMultiRayShape.h"
#include "../../../../../../../include/hkpShape.h"

// Havok's default vector and transform constructors leave their storage untouched.
inline hkTransform::hkTransform() {}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern unsigned int DAT_0126835c;
extern char DAT_010ceda8[];
extern char DAT_010c41f8[];
extern LocalM128 DAT_010ec7f0;

static void timer(const char* name, volatile unsigned& ticks)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* event = (hkMonitorStream::TimerCommand*)stream->m_end.m_storage;
    if ((char*)event < stream->m_capacityMinus16.m_storage)
    {
        event->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        ticks = (unsigned)__rdtsc();
        event->m_time0 = ticks;
        stream->m_end.m_storage = (char*)(event + 1);
    }
}

inline void hkVector4::SetTransformedPosition(const hkTransform& transform, const hkVector4& vector)
{
    LocalM128 v = vector.m_vComponents;
    m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), transform.m_kColumn1),
                                        _mm_mul_ps(_mm_shuffle_ps(v, v, 0), transform.m_kColumn0)),
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), transform.m_kColumn2), transform.m_vTranslation));
}

static LocalM128 point(const hkTransform& transform, LocalM128 vector)
{
    hkVector4 result;
    result.SetTransformedPosition(transform, reinterpret_cast<const hkVector4&>(vector));
    return result.m_vComponents;
}

static LocalM128 direction(const hkTransform& transform, LocalM128 v)
{
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), transform.m_kColumn1),
                                 _mm_mul_ps(_mm_shuffle_ps(v, v, 0), transform.m_kColumn0)),
                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), transform.m_kColumn2));
}

// These query and result records do not yet have shared headers.
struct ShapeRayCastQuery
{
    hkVector4 from, to;
    unsigned filter;
    int collection;
};

struct ShapeRayCastOutput
{
    hkVector4 normal;
    float fraction;
    int m_uiExtraInfo;
    int unk18;
    int unk1c;
    unsigned shapeKeys[8];
    int level;

    ShapeRayCastOutput()
    {
        fraction = 1.0f;
        m_uiExtraInfo = -1;
        shapeKeys[0] = -1;
        level = 0;
    }
};

struct ContactPointPair
{
    hkContactPoint point;
    const hkpCdBody* bodyA;
    const hkpCdBody* bodyB;
};

struct RayLocals
{
    ContactPointPair hit;
    hkTransform relative;
};

// @fnv 0x00d37010
// src: HAVOK_SRC 0x00d37010
void __stdcall hkpMultiRayConvexAgent_getClosestPoints(const hkpCdBody* a, const hkpCdBody* b, void* unused, hkpCdPointCollector* collector)
{

    union
    {
        volatile unsigned ticks;
        int remaining;
    } counter;

    timer(DAT_010ceda8, counter.ticks);

    const hkpMultiRayShape* shape = static_cast<const hkpMultiRayShape*>(a->m_pCollisionShape);

    const hkpShape* target = b->m_pCollisionShape;

    RayLocals L;
    ShapeRayCastQuery input;

    L.relative.hkTransform_setMulInverseMul(b->m_pMotionState, a->m_pMotionState);

    int count = shape->m_kRays.m_iElementCount;

    const hkpMultiRayShape::Ray* ray = shape->m_kRays.m_data;

    L.hit.bodyB = b;

    L.hit.bodyA = a;

    input.filter = 0;

    input.collection = 0;

    if (count > 0)
        for (counter.remaining = count; counter.remaining; --counter.remaining)
        {

            ShapeRayCastOutput output;
            LocalM128 from = ray->m_kRayStart.m_vComponents;

            input.from.m_vComponents = point(L.relative, from);

            LocalM128 to = ray->m_kRayEnd.m_vComponents;

            input.to.m_vComponents = point(L.relative, to);

            // Preserve the original two-byte result slot; the returned hkBool occupies its second byte.
            __declspec(align(2)) hkBool success[2] = {hkBool(), target->IntersectRayWithShape(input, output)};

            if (success[1])
            {

                float fraction = output.fraction;

                LocalM128 t = _mm_load_ss(&fraction);
                t = _mm_shuffle_ps(t, t, 0);

                LocalM128 p = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), input.from.m_vComponents), _mm_mul_ps(input.to.m_vComponents, t));

                const hkTransform* world = static_cast<const hkTransform*>(b->m_pMotionState);

                L.hit.point.m_vContactPosition.m_vComponents = point(*world, p);

                L.hit.point.m_vSeparatingNormal.m_vComponents = direction(*world, output.normal.m_vComponents);

                L.hit.point.m_vSeparatingNormal.w = (fraction - 1.0) * ray->m_kRayStart.w + shape->m_fRayRadius;

                collector->AddCdPoint(L.hit);
            }

            ++ray;
        }

    timer(DAT_010c41f8, counter.ticks);
}
