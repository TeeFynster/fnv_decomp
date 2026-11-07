// Retain the unit's original intrinsic type; VC9 treats the SDK's byte-array
// aliases in __m128 as stack buffers and otherwise adds a security cookie.
// Exe 0x00daf540 FUN_00daf540: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
#define _INCLUDED_MM2
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);

#include <new>
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpIterativeLinearCastAgent.h"
#include "../../../../../../../include/hkpSimpleClosestContactCollector.h"

// The original body constructor leaves its members uninitialized.
__forceinline hkpCdBody::hkpCdBody() {}
// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

__forceinline const float& hkVector4::component(int k) const
{
    return lanes[k];
}
__forceinline float& hkVector4::component(int k)
{
    return lanes[k];
}
__forceinline void hkVector4::SetAllComponents(float v)
{
    LocalM128 t = _mm_load_ss(&v);
    quad = _mm_shuffle_ps(t, t, 0);
}

__forceinline float hkContactPoint::getDistance() const
{
    return m_vSeparatingNormal.w;
}
__forceinline void hkContactPoint::setDistance(float value)
{
    m_vSeparatingNormal.component(3) = value;
}
__forceinline void hkContactPoint::setSeparatingNormal(const hkVector4& value, float distance)
{
    m_vSeparatingNormal.quad = value.quad;
    setDistance(distance);
}

struct __declspec(align(16)) ContactPointPair
{
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pRootCollidableA;
    const hkpCdBody* m_pRootCollidableB;
};

extern float DAT_0104da48;
// Preserve this unit's inlined collector construction.
__declspec(nothrow) __forceinline hkpCdPointCollector::hkpCdPointCollector()
    : m_fEarlyOutDistance(DAT_0104da48) {}
__declspec(nothrow) __forceinline hkpSimpleClosestContactCollector::hkpSimpleClosestContactCollector()
{
    m_fEarlyOutDistance = reinterpret_cast<hkContactPoint&>(contact).m_vSeparatingNormal.w = DAT_0104da48;
    m_bOk = false;
}

typedef void (*hkpLinearCastFunc)(const hkpCdBody*, const hkpCdBody*, const void*, hkpCdPointCollector*) throw();

struct hkpLinearCastPath
{
    float m_minDistance;
    int m_numIterations;
};

struct __declspec(align(16)) CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

struct __declspec(align(16)) ShapeSweepParameters : public CollisionAgentContext
{
    hkVector4 m_step;
    float m_extraPenetration;
    float m_fMaxExtraPenetration;
    hkpLinearCastPath* m_path;
};

__forceinline float dot3(const hkVector4& a, const hkVector4& b)
{
    LocalM128 mul = _mm_mul_ps(a.quad, b.quad);
    LocalM128 shuf1 = _mm_shuffle_ps(mul, mul, 0x55);
    LocalM128 shuf2 = _mm_shuffle_ps(mul, mul, 0xaa);
    LocalM128 sum = _mm_add_ss(shuf1, mul);
    sum = _mm_add_ss(shuf2, sum);
    float res;
    _mm_store_ss(&res, sum);
    return res;
}

// The original motion-state copy does not throw. Keep placement-new cleanup
// out of the caller while using the shared copy constructor.
__declspec(nothrow) __forceinline void copyMotionState(void* storage, const void* source)
{
    ::new (storage) hkMotionState(*static_cast<const hkMotionState*>(source));
}

// @fnv 0x00daf540
// src: GUESS 0x00daf540 (confidence: low)
void hkpIterativeLinearCastAgent::ProcessEntries_00daf540(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                                               const ShapeSweepParameters* input, hkpCdPointCollector* castCollector,
                                               hkpCdPointCollector* startCollector)
{
    // Explicit storage preserves the original collector lifetime without adding
    // virtual-destructor cleanup on every exit.
    __declspec(align(16)) LocalM128 localCastCollectorStorage[sizeof(hkpSimpleClosestContactCollector) / sizeof(LocalM128)];
    hkpSimpleClosestContactCollector& localCastCollector = *::new (static_cast<void*>(localCastCollectorStorage)) hkpSimpleClosestContactCollector;
    CollisionAgentContext linearInput = *input;
    linearInput.m_fScalar += input->m_fMaxExtraPenetration;
    CastImpl(bodyA, bodyB, &linearInput, &localCastCollector);
    if (!localCastCollector.m_bOk)
        return;

    ContactPointPair hitPoint;
    hitPoint.m_kPoint.m_vContactPosition.quad = reinterpret_cast<const hkContactPoint&>(localCastCollector.contact).m_vContactPosition.quad;
    hitPoint.m_pRootCollidableB = bodyB;
    hitPoint.m_pRootCollidableA = bodyA;
    hitPoint.m_kPoint.m_vSeparatingNormal.quad = reinterpret_cast<const hkContactPoint&>(localCastCollector.contact).m_vSeparatingNormal.quad;

    const float& distance = reinterpret_cast<hkContactPoint&>(localCastCollector.contact).m_vSeparatingNormal.w;
    if (distance < input->m_fScalar && startCollector)
        startCollector->AddCdPoint(hitPoint);

    hkVector4 step;
    step.quad = input->m_step.quad;
    float closing = dot3(input->m_step, reinterpret_cast<const hkContactPoint&>(localCastCollector.contact).m_vSeparatingNormal);
    float endpoint = distance + closing;
    if (endpoint > 0.0f)
        return;
    if (0.0 <= closing + input->m_extraPenetration)
        return;
    const hkpLinearCastPath* path = input->m_path;
    if (path->m_minDistance >= distance)
    {
        if (distance > 0.0f)
        {
            float t = distance / (distance - endpoint);
            if (t > castCollector->m_fEarlyOutDistance)
                return;
            hitPoint.m_kPoint.setDistance(t);
        }
        else
        {
            hitPoint.m_kPoint.setDistance(0.0f);
        }
        castCollector->AddCdPoint(hitPoint);
        return;
    }

    hitPoint.m_kPoint.setDistance(distance / (distance - endpoint));
    __declspec(align(16)) LocalM128 projectedDistanceStorage[sizeof(hkpSimpleClosestContactCollector) / sizeof(LocalM128)];
    hkpSimpleClosestContactCollector& projectedDistance = *::new (static_cast<void*>(projectedDistanceStorage)) hkpSimpleClosestContactCollector;
    LocalM128 motionStorage[sizeof(hkMotionState) / sizeof(LocalM128)];
    hkMotionState& motion = *reinterpret_cast<hkMotionState*>(motionStorage);
    copyMotionState(motionStorage, bodyA->m_pMotionState);
    hkpCdBody movedBody;
    movedBody.m_parent = bodyA;
    movedBody.m_pMotionState = &motion;
    movedBody.m_pCollisionShape = bodyA->m_pCollisionShape;
    movedBody.m_uiCollisionShapeKey = 0xffffffff;
    int iterations = path->m_numIterations;
    while (--iterations >= 0)
    {
        reinterpret_cast<hkContactPoint&>(projectedDistance.contact).m_vSeparatingNormal.w = DAT_0104da48;
        projectedDistance.m_fEarlyOutDistance = DAT_0104da48;
        projectedDistance.m_bOk = false;
        hkVector4 delta;
        float broadcast = hitPoint.m_kPoint.getDistance();
        delta.SetAllComponents(broadcast);
        motion.m_kMotionTransform.m_vTranslation = _mm_add_ps(_mm_mul_ps(delta.quad, step.quad),
                                                ((const hkTransform*)bodyA->m_pMotionState)->m_vTranslation);
        CastImpl(&movedBody, bodyB, &linearInput, &projectedDistance);

        step.quad = input->m_step.quad;
        float approach = dot3(input->m_step, reinterpret_cast<const hkContactPoint&>(projectedDistance.contact).m_vSeparatingNormal);
        if (approach >= 0.0f)
            return;
        float roundedSpeed = -approach;
        float oldFraction = hitPoint.m_kPoint.getDistance();
        float travel = oldFraction * roundedSpeed;
        float separation = reinterpret_cast<hkContactPoint&>(projectedDistance.contact).m_vSeparatingNormal.w;
        if (separation + travel > roundedSpeed)
            return;
        float newFraction = oldFraction + separation / roundedSpeed;
        if (newFraction > castCollector->m_fEarlyOutDistance)
            return;
        hitPoint.m_kPoint.m_vContactPosition.quad = reinterpret_cast<const hkContactPoint&>(projectedDistance.contact).m_vContactPosition.quad;
        hitPoint.m_kPoint.setSeparatingNormal(reinterpret_cast<const hkContactPoint&>(projectedDistance.contact).m_vSeparatingNormal, newFraction);
        if (input->m_path->m_minDistance >= separation)
            break;
    }
    castCollector->AddCdPoint(hitPoint);
}
