#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

namespace IterativeSweepSimd {
typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_load_ss;
using ::_mm_load_ps;
using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_store_ss;
using ::_mm_store_ps;
}
}
extern "C" void _ReadWriteBarrier();

struct __declspec(align(16)) IterativeSweep_hkVector4
{
    union
    {
        IterativeSweepSimd::LocalM128 quad;
        struct
        {
            float x, y, z, w;
        };
    };

    __forceinline void SetAllComponents(float v)
    {
        IterativeSweepSimd::LocalM128 scalar = IterativeSweepSimd::_mm_load_ss(&v);
        quad = IterativeSweepSimd::_mm_shuffle_ps(scalar, scalar, 0);
    }
};

struct __declspec(align(16)) IterativeSweep_hkTransform
{
    IterativeSweep_hkVector4 m_kColumn0;
    IterativeSweep_hkVector4 m_kColumn1;
    IterativeSweep_hkVector4 m_kColumn2;
    IterativeSweep_hkVector4 m_vTranslation;
    IterativeSweep_hkVector4 m_center0;
    IterativeSweep_hkVector4 m_center1;
    IterativeSweep_hkVector4 m_qRotation0;
    IterativeSweep_hkVector4 m_qRotation1;
    IterativeSweep_hkVector4 m_centerLocal;
    IterativeSweep_hkVector4 m_kDeltaAngle;
    float m_fSphereRadius;
    float m_linearLimit;
    float m_fAngularLimit;
    float m_timeFactor;
    void FUN_00d431b0(const void* src);
};

struct IterativeSweep_hkpShape
{
    void* vtable;
    int unk04;
    int unk08;
    int m_type;
};

struct IterativeSweep_hkpCdBody
{
    const IterativeSweep_hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_kMotionState;
    const IterativeSweep_hkpCdBody* m_parent;
};

struct __declspec(align(16)) IterativeSweep_hkContactPoint
{
    IterativeSweep_hkVector4 m_vContactPosition;
    IterativeSweep_hkVector4 m_vSeparatingNormal;
};

struct __declspec(align(16)) IterativeSweep_hkpRootCdPoint
{
    IterativeSweep_hkContactPoint m_kPoint;
    const IterativeSweep_hkpCdBody* m_pRootCollidableA;
    const IterativeSweep_hkpCdBody* m_pRootCollidableB;
};

struct IterativeSweep_hkpCdPointCollector
{
    virtual void unk_dtor();
    virtual void AddCdPoint(const IterativeSweep_hkpRootCdPoint& point) = 0;
    float m_fEarlyOutDistance;
};

extern float DAT_0104da48;

extern char DAT_010cebe0;
struct __declspec(align(16)) IterativeSweep_hkpSimpleClosestContactCollector
{
    void* m_ppVirtualMethodTable;
    float m_fEarlyOutDistance;
    bool m_bHit;
    IterativeSweep_hkContactPoint m_kHitPoint;
    __forceinline IterativeSweep_hkpSimpleClosestContactCollector()
    {
        m_fEarlyOutDistance = m_kHitPoint.m_vSeparatingNormal.w = DAT_0104da48;
        m_ppVirtualMethodTable = &DAT_010cebe0;
        m_bHit = false;
    }
};

typedef void (*IterativeSweep_hkpLinearCastFunc)(const IterativeSweep_hkpCdBody*, const IterativeSweep_hkpCdBody*,
                                                 const void*, IterativeSweep_hkpSimpleClosestContactCollector*) throw();

struct IterativeSweep_AgentFunctions
{
    void* create;
    void* penetrations;
    IterativeSweep_hkpLinearCastFunc closest;
    void* linearCast;
    int flipped;
};
struct IterativeSweep_CollisionDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char m_types[32][32];
    unsigned char m_predictiveTypes[32][32];
    IterativeSweep_AgentFunctions m_functions[256];
};

struct IterativeSweep_hkpLinearCastPath
{
    float m_minDistance;
    int m_numIterations;
};

struct __declspec(align(16)) IterativeSweep_hkpCollisionInput
{
    IterativeSweep_CollisionDispatcher* m_pCollisionDispatcher;
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

struct __declspec(align(16)) IterativeSweep_hkpLinearCastCollisionInput : public IterativeSweep_hkpCollisionInput
{
    IterativeSweep_hkVector4 m_step;
    float m_extraPenetration;
    float m_fMaxExtraPenetration;
    IterativeSweep_hkpLinearCastPath* m_path;
};

__forceinline float IterativeSweep_dot3(const IterativeSweep_hkVector4& a, const IterativeSweep_hkVector4& b)
{
    IterativeSweepSimd::LocalM128 mul = IterativeSweepSimd::_mm_mul_ps(a.quad, b.quad);
    IterativeSweepSimd::LocalM128 shuf1 = IterativeSweepSimd::_mm_shuffle_ps(mul, mul, 0x55);
    IterativeSweepSimd::LocalM128 shuf2 = IterativeSweepSimd::_mm_shuffle_ps(mul, mul, 0xaa);
    IterativeSweepSimd::LocalM128 sum = IterativeSweepSimd::_mm_add_ss(shuf1, mul);
    sum = IterativeSweepSimd::_mm_add_ss(shuf2, sum);
    float res;
    IterativeSweepSimd::_mm_store_ss(&res, sum);
    return res;
}

__forceinline IterativeSweep_hkpLinearCastFunc IterativeSweep_getLinearCastFunc(
    const IterativeSweep_CollisionDispatcher* dispatcher, int typeA, int typeB)
{
    unsigned char index = dispatcher->m_types[typeA][typeB];
    return dispatcher->m_functions[index].closest;
}

// @fnv 0x00daf8e0
// src: GUESS 0x00daf8e0 (confidence: low)
void Object_ProcessEntries_00daf8e0(const IterativeSweep_hkpCdBody* bodyA, const IterativeSweep_hkpCdBody* bodyB,
                  const IterativeSweep_hkpLinearCastCollisionInput* input,
                  IterativeSweep_hkpCdPointCollector* castCollector, IterativeSweep_hkpCdPointCollector* startCollector)
{
    IterativeSweep_hkpSimpleClosestContactCollector localCastCollector;
    IterativeSweep_hkpCollisionInput linearInput;
    linearInput = *input;
    linearInput.m_fScalar += input->m_fMaxExtraPenetration;

    IterativeSweep_hkpLinearCastFunc func = IterativeSweep_getLinearCastFunc(
        input->m_pCollisionDispatcher, bodyA->m_pCollisionShape->m_type, bodyB->m_pCollisionShape->m_type);
    func(bodyA, bodyB, &linearInput, &localCastCollector);

    if (!localCastCollector.m_bHit)
    {
        return;
    }

    IterativeSweep_hkpRootCdPoint hitPoint;
    hitPoint.m_kPoint.m_vSeparatingNormal.quad = localCastCollector.m_kHitPoint.m_vSeparatingNormal.quad;
    hitPoint.m_pRootCollidableA = bodyA;
    hitPoint.m_pRootCollidableB = bodyB;
    hitPoint.m_kPoint.m_vContactPosition.quad = localCastCollector.m_kHitPoint.m_vContactPosition.quad;

    const float& frac4 = localCastCollector.m_kHitPoint.m_vSeparatingNormal.w;
    if (frac4 < input->m_fScalar && startCollector)
        startCollector->AddCdPoint(hitPoint);

    IterativeSweep_hkVector4 step;
    step.quad = input->m_step.quad;
    float i = IterativeSweep_dot3(step, localCastCollector.m_kHitPoint.m_vSeparatingNormal);
    float c = frac4 + i;
    if (c > 0.0f)
        return;
    if (0.0 <= i + input->m_extraPenetration)
        return;
    const IterativeSweep_hkpLinearCastPath* path = input->m_path;
    if (path->m_minDistance >= frac4)
    {
        if (frac4 > 0.0f)
        {
            float maxDistance = (frac4 - c) * castCollector->m_fEarlyOutDistance;
            if (maxDistance < frac4)
                return;
        }
        hitPoint.m_kPoint.m_vSeparatingNormal.w = 0.0f;
        castCollector->AddCdPoint(hitPoint);
        return;
    }
    float localTransform = frac4 / (frac4 - c);
    IterativeSweep_hkpSimpleClosestContactCollector projectedDistance;
    IterativeSweep_hkTransform fraction;
    fraction.FUN_00d431b0(bodyA->m_kMotionState);

    IterativeSweep_hkpCdBody tempBodyA;
    tempBodyA.m_parent = bodyA;
    tempBodyA.m_kMotionState = &fraction;
    tempBodyA.m_pCollisionShape = bodyA->m_pCollisionShape;
    tempBodyA.m_uiCollisionShapeKey = 0xffffffff;

    int iterations = path->m_numIterations;

    while (--iterations >= 0)
    {
        projectedDistance.m_kHitPoint.m_vSeparatingNormal.w = DAT_0104da48;
        projectedDistance.m_bHit = false;
        projectedDistance.m_fEarlyOutDistance = DAT_0104da48;

        IterativeSweep_hkVector4 hitDist;
        hitDist.SetAllComponents(localTransform);
        fraction.m_vTranslation.quad = IterativeSweepSimd::_mm_add_ps(
            IterativeSweepSimd::_mm_mul_ps(hitDist.quad, step.quad),
            ((const IterativeSweep_hkTransform*)bodyA->m_kMotionState)->m_vTranslation.quad);

        func(&tempBodyA, bodyB, &linearInput, &projectedDistance);

        if (projectedDistance.m_bHit == 0)
        {
            return;
        }

        IterativeSweepSimd::LocalM128 position =
            IterativeSweepSimd::_mm_load_ps(&projectedDistance.m_kHitPoint.m_vContactPosition.x);
        _ReadWriteBarrier();
        double currentFraction = localTransform;
        IterativeSweepSimd::LocalM128 normal =
            IterativeSweepSimd::_mm_load_ps(&projectedDistance.m_kHitPoint.m_vSeparatingNormal.x);
        step.quad = input->m_step.quad;
        _ReadWriteBarrier();
        IterativeSweepSimd::_mm_store_ps(&hitPoint.m_kPoint.m_vContactPosition.x, position);
        IterativeSweepSimd::_mm_store_ps(&hitPoint.m_kPoint.m_vSeparatingNormal.x, normal);

        float subDot = IterativeSweep_dot3(step, hitPoint.m_kPoint.m_vSeparatingNormal);
        hitPoint.m_kPoint.m_vSeparatingNormal.w = currentFraction;
        if (subDot >= 0.0f)
        {
            return;
        }

        float negDot = -subDot;
        float travel = negDot * currentFraction;
        float r = projectedDistance.m_kHitPoint.m_vSeparatingNormal.w;
        if (r + travel > negDot)
        {
            return;
        }

        if (input->m_path->m_minDistance >= r)
            break;

        localTransform = currentFraction + r / negDot;
        if (localTransform > castCollector->m_fEarlyOutDistance)
        {
            return;
        }
    }

    castCollector->AddCdPoint(hitPoint);
}
