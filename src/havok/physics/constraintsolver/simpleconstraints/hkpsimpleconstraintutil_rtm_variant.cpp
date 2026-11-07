
// src/havok/physics/constraintsolver/simpleconstraints/hkpsimpleconstraintutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/simpleconstraints/hkpsimpleconstraintutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/constraintsolver/simpleconstraints/hkpsimpleconstraintutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/simpleconstraints/hkpsimpleconstraintutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>

// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    int m128_i32[4];
} __m128, LocalM128;

extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

#include "../../../../../include/hkVector4.h"


struct ContactConstraint
{
    hkVector4 unk000;
    hkVector4 unk010;
    hkVector4 unk020;
    hkVector4 unk030;
    hkVector4 unk040;
    hkVector4 unk050;
    hkVector4 unk060;
    hkVector4 unk070;
    hkVector4 unk080;
    hkVector4 unk090;
    hkVector4 unk0a0;
    hkVector4 unk0b0;
    hkVector4 unk0c0;
    hkVector4 unk0d0;
    hkVector4 unk0e0;
    hkVector4 unk0f0;
    hkVector4 unk100;
    hkVector4 unk110;
    hkVector4 unk120;
    hkVector4 m_kColumn0;  // 0x130
    hkVector4 m_kColumn1;  // 0x140
    hkVector4 m_kColumn2;  // 0x150
    hkVector4 m_inv0;      // 0x160
    hkVector4 m_inv1;      // 0x170
    hkVector4 m_inv2;      // 0x180
};

struct ContactParams
{
    float m_fSlipAngle;    // 0x00
    float m_fElasticity;   // 0x04
    float m_usFlags;       // 0x08
    float m_minNormalVel;  // 0x0c
    float m_targetVel;     // 0x10
    float m_slipFactor;    // 0x14
    bool m_clipped;        // 0x18
};

extern __m128 DAT_010c44d0;
void __cdecl FUN_00df22f0(bool* flag);
void __cdecl hkVector4_UpdateFields_00df5e80(ContactConstraint* c, void* bodyA, void* bodyB, hkVector4* outVel);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern __m128 DAT_010cbfc0;
struct ContactBody
{
    hkVector4 linear;
    hkVector4 angular;
};
static __forceinline __m128 transform(const hkVector4& a, const hkVector4& b, const hkVector4& d, __m128 v)
{
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b.m_vComponents),
                                 _mm_mul_ps(_mm_shuffle_ps(v, v, 0), a.m_vComponents)),
                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), d.m_vComponents));
}
// src: GUESS 0x00df5d20 (confidence: low)
__declspec(noinline) void __cdecl Object_ProcessAndReturnValue_00df5d20(ContactConstraint* c, hkVector4* impulse, void* bodyA, void* bodyB)
{
    ContactBody* a = static_cast<ContactBody*>(bodyA);
    ContactBody* b = static_cast<ContactBody*>(bodyB);
    __m128 linear = transform(c->unk100, c->unk110, c->unk120, impulse->m_vComponents);
    __m128 ma = _mm_shuffle_ps(c->unk060.m_vComponents, c->unk060.m_vComponents, 0xff);
    ma = _mm_shuffle_ps(ma, ma, 0);
    a->linear.m_vComponents = _mm_add_ps(_mm_mul_ps(ma, linear), a->linear.m_vComponents);
    __m128 mb = _mm_shuffle_ps(c->unk0e0.m_vComponents, c->unk0e0.m_vComponents, 0xff);
    mb = _mm_shuffle_ps(mb, mb, 0);
    b->linear.m_vComponents = _mm_sub_ps(b->linear.m_vComponents, _mm_mul_ps(mb, linear));
    a->angular.m_vComponents =
        _mm_add_ps(transform(c->unk030, c->unk040, c->unk050, impulse->m_vComponents), a->angular.m_vComponents);
    b->angular.m_vComponents =
        _mm_sub_ps(b->angular.m_vComponents, transform(c->unk0b0, c->unk0c0, c->unk0d0, impulse->m_vComponents));
    a->angular.m_vComponents = _mm_and_ps(a->angular.m_vComponents, DAT_010cbfc0);
    b->angular.m_vComponents = _mm_and_ps(b->angular.m_vComponents, DAT_010cbfc0);
    a->linear.m_vComponents = _mm_and_ps(a->linear.m_vComponents, DAT_010cbfc0);
    b->linear.m_vComponents = _mm_and_ps(b->linear.m_vComponents, DAT_010cbfc0);
}

static __forceinline float minSpeed(float a, float b)
{
    return a < b ? a : b;
}
static __forceinline float contactSolve(ContactConstraint* c, ContactParams* p, void* bodyA, void* bodyB,
                                        hkVector4& relVel)
{
    float rest = p->m_fElasticity;
    relVel.m_vComponents = _mm_xor_ps(DAT_010c44d0, relVel.m_vComponents);
    float bounce = rest * (relVel.m_vComponents.m128_f32[0]);
    relVel.m_vComponents.m128_f32[0] = (p->m_targetVel + bounce) + (relVel.m_vComponents.m128_f32[0]);

    float maxImp = p->m_usFlags;
    __m128 v = relVel.m_vComponents;
    __m128 vy = _mm_shuffle_ps(v, v, 0x55);
    __m128 vx = _mm_shuffle_ps(v, v, 0x00);
    __m128 vz = _mm_shuffle_ps(v, v, 0xaa);
    __m128 imp =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(vy, c->m_inv1.m_vComponents), _mm_mul_ps(vx, c->m_inv0.m_vComponents)),
                   _mm_mul_ps(vz, c->m_inv2.m_vComponents));

    hkVector4 impulse;
    impulse.m_vComponents = imp;
    p->m_clipped = false;

    if (impulse.m_vComponents.m128_f32[0] > maxImp)
    {
        float scale = maxImp / impulse.m_vComponents.m128_f32[0];
        __m128 s = _mm_load_ss(&scale);
        s = _mm_shuffle_ps(s, s, 0);
        imp = _mm_mul_ps(s, imp);
        impulse.m_vComponents = imp;
        p->m_clipped = true;
    }

    hkVector4 impSq;
    impSq.m_vComponents = _mm_mul_ps(imp, imp);
    float tangSq = impSq.m_vComponents.m128_f32[1] + impSq.m_vComponents.m128_f32[2];
    float maxTangSq = p->m_fSlipAngle * p->m_fSlipAngle * impSq.m_vComponents.m128_f32[0];

    float finalImp;
    if (tangSq > maxTangSq || impulse.m_vComponents.m128_f32[0] < 0.0f)
    {
        impulse.m_vComponents = _mm_setzero_ps();
        float normalVel = relVel.m_vComponents.m128_f32[0];
        float vy0 = relVel.m_vComponents.m128_f32[1];
        float vz0 = relVel.m_vComponents.m128_f32[2];
        float velTangSq = vy0 * vy0 + vz0 * vz0;

        float imp0 = normalVel * c->m_kColumn0.m_vComponents.m128_f32[3];
        if (imp0 > maxImp)
        {
            p->m_clipped = true;
            imp0 = maxImp;
        }

        __m128 s0 = _mm_load_ss(&imp0);
        s0 = _mm_shuffle_ps(s0, s0, 0);
        relVel.m_vComponents = _mm_sub_ps(relVel.m_vComponents, _mm_mul_ps(s0, c->m_kColumn0.m_vComponents));

        const hkVector4& row1 = c->m_kColumn1;
        float rvy = relVel.m_vComponents.m128_f32[1];
        float rvz = relVel.m_vComponents.m128_f32[2];
        float t1 = (c->m_kColumn2.m_vComponents.m128_f32[2] * rvy - rvz * c->m_kColumn2.m_vComponents.m128_f32[1]) *
                   row1.m_vComponents.m128_f32[3];
        float t2 = (row1.m_vComponents.m128_f32[1] * rvz - rvy * c->m_kColumn2.m_vComponents.m128_f32[1]) *
                   row1.m_vComponents.m128_f32[3];
        float tLenSq = t1 * t1 + t2 * t2;
        float maxT = p->m_fSlipAngle * imp0;
        float maxTSq = maxT * maxT;

        if (tLenSq > maxTSq)
        {
            float invLen = (float)sqrt(maxTSq / tLenSq);
            t1 *= invLen;
            t2 *= invLen;
        }

        __m128 st1 = _mm_load_ss(&t1);
        __m128 st2 = _mm_load_ss(&t2);
        impulse.m_vComponents.m128_f32[1] = t1;
        impulse.m_vComponents.m128_f32[2] = t2;
        st1 = _mm_shuffle_ps(st1, st1, 0);
        st2 = _mm_shuffle_ps(st2, st2, 0);
        relVel.m_vComponents = _mm_sub_ps(_mm_sub_ps(relVel.m_vComponents, _mm_mul_ps(st1, row1.m_vComponents)),
                                          _mm_mul_ps(st2, c->m_kColumn2.m_vComponents));

        float rawDImp = (relVel.m_vComponents.m128_f32[0] - bounce) * c->m_kColumn0.m_vComponents.m128_f32[3];
        float dImp = 0.0 > rawDImp ? 0.0f : rawDImp;
        if (dImp + imp0 > maxImp)
        {
            p->m_clipped = true;
            dImp = maxImp - imp0;
        }
        impulse.m_vComponents.m128_f32[0] = imp0 + dImp;

        __m128 sd = _mm_load_ss(&dImp);
        sd = _mm_shuffle_ps(sd, sd, 0);
        relVel.m_vComponents = _mm_sub_ps(relVel.m_vComponents, _mm_mul_ps(sd, c->m_kColumn0.m_vComponents));

        float rvy2 = relVel.m_vComponents.m128_f32[1];
        float rvz2 = relVel.m_vComponents.m128_f32[2];
        float remTangSq = rvy2 * rvy2 + rvz2 * rvz2;
        remTangSq = minSpeed(remTangSq, velTangSq);
        float remTang = (float)sqrt(remTangSq);
        impulse.m_vComponents.m128_f32[0] += remTang * c->m_kColumn0.m_vComponents.m128_f32[3] * p->m_slipFactor;
        if (impulse.m_vComponents.m128_f32[0] > maxImp)
        {
            p->m_clipped = true;
            impulse.m_vComponents.m128_f32[0] = maxImp;
        }
        finalImp = impulse.m_vComponents.m128_f32[0];
    }
    else
    {
        finalImp = impulse.m_vComponents.m128_f32[0];
    }

    Object_ProcessAndReturnValue_00df5d20(c, &impulse, bodyA, bodyB);
    return finalImp;
}

// @fnv 0x00df5f80
// src: GUESS 0x00df5f80 (confidence: low)
float __cdecl Object_ProcessAndReturnValue_00df5f80(ContactConstraint* c, ContactParams* p, void* bodyA, void* bodyB)
{
    static bool s_keyValid = false;
    if (!s_keyValid)
    {
        FUN_00df22f0(&s_keyValid);
        if (!s_keyValid)
        {
            return 0.0f;
        }
    }

    hkVector4 relVel;
    hkVector4_UpdateFields_00df5e80(c, bodyA, bodyB, &relVel);

    if (relVel.m_vComponents.m128_f32[0] > p->m_minNormalVel)
    {
        relVel.m_vComponents.m128_f32[0] = p->m_minNormalVel;
        if (p->m_minNormalVel >= p->m_targetVel)
        {
            return 0.0f;
        }
    }

    return contactSolve(c, p, bodyA, bodyB, relVel);
}
