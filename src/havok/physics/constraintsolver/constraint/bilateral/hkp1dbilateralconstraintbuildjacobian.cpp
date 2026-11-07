#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/physics/constraintsolver/constraint/bilateral/hkp1dbilateralconstraintbuildjacobian.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/bilateral/hkp1dbilateralconstraintbuildjacobian.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00dcee80 FUN_00dcee80: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned int m128_u32[4];
} __m128, LocalM128;

extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

// Keep the original intrinsic layout: its alias information affects code generation.
#define _INCLUDED_MM2
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"

// Preserve the scalar reductions and inline operations used by this unit.
inline LocalM128& hkVector4::q() { return reinterpret_cast<LocalM128&>(*this); }
inline const LocalM128& hkVector4::q() const { return reinterpret_cast<const LocalM128&>(*this); }

inline void hkVector4::operator=(const hkVector4& o)
{
    m_vComponents = o.m_vComponents;
}

inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::mul4(const hkVector4& a)
{
    m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
}

inline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}

inline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

inline void hkVector4::setXYZW(const hkVector4& xyz, const hkVector4& w)
{
    m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
}

static inline float HorizontalAdd4Scalar(const hkVector4& vector)
{
    LocalM128 sum0 = _mm_add_ps(_mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0x4e), vector.m_vComponents);
    LocalM128 sum1 = _mm_add_ps(_mm_shuffle_ps(sum0, sum0, 0xb1), sum0);
    float r;
    _mm_store_ss(&r, sum1);
    return r;
}

static inline float Dot3ScalarSIMD(const hkVector4& vector, const hkVector4& a)
{
    LocalM128 x2 = _mm_mul_ps(vector.m_vComponents, a.m_vComponents);
    LocalM128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    float f;
    _mm_store_ss(&f, r);
    return f;
}


inline void SetRotatedDirection(hkVector4& out, const hkMatrix3& r, const hkVector4& b)
{
    LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    LocalM128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    LocalM128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    LocalM128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct Accum_dcf880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_kCenterPosition;
    hkMatrix3 m_rot;
};

struct Info_dcf880
{
    hkVector4 m_kPivotA;
    hkVector4 m_kPivotB;
    hkVector4 m_dir;
    float m_30;
    float m_34;
};

struct QueryIn_dcf880
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_factor;
    int unk24;
    int unk28;
    int unk2c;
    Accum_dcf880* m_pBodyA;
    Accum_dcf880* m_pBodyB;
};

struct Jac_dcf880
{
    hkVector4 m_kLinearJacobian;
    hkVector4 m_angular0;
    hkVector4 m_angular1;
    float m_30;
    float m_34;
    int unk38;
    int unk3c;
};

struct QueryOut_dcf880
{
    Jac_dcf880* m_pJacobian;
};

// @fnv 0x00dcf880
void __cdecl ComputeAngularJacobian(const Info_dcf880& info, const QueryIn_dcf880& aQueryIn, QueryOut_dcf880& aQueryOut)
{
    const Accum_dcf880* bodyA = aQueryIn.m_pBodyA;
    float factor = aQueryIn.m_factor;
    const Accum_dcf880* bodyB = aQueryIn.m_pBodyB;
    Jac_dcf880* jac = aQueryOut.m_pJacobian;
    jac->m_kLinearJacobian = info.m_dir;
    {
        hkVector4 vDeltaA;
        vDeltaA.setSub4(info.m_kPivotA, bodyA->m_kCenterPosition);
        hkVector4 vDeltaB;
        vDeltaB.setSub4(info.m_kPivotB, bodyB->m_kCenterPosition);
        LocalM128 dir = info.m_dir.m_vComponents;
        LocalM128 vDirYZX = _mm_shuffle_ps(dir, dir, 0xc9);
        LocalM128 vDirZXY = _mm_shuffle_ps(dir, dir, 0xd2);
        hkVector4 vAngularA;
        vAngularA.m_vComponents =
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(vDeltaA.m_vComponents, vDeltaA.m_vComponents, 0xc9), vDirZXY),
                       _mm_mul_ps(_mm_shuffle_ps(vDeltaA.m_vComponents, vDeltaA.m_vComponents, 0xd2), vDirYZX));
        hkVector4 vAngularB;
        vAngularB.m_vComponents =
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(vDeltaB.m_vComponents, vDeltaB.m_vComponents, 0xd2), vDirYZX),
                       _mm_mul_ps(_mm_shuffle_ps(vDeltaB.m_vComponents, vDeltaB.m_vComponents, 0xc9), vDirZXY));
        SetRotatedDirection(jac->m_angular0, bodyA->m_rot, vAngularA);
        SetRotatedDirection(jac->m_angular1, bodyB->m_rot, vAngularB);
    }
    {
        LocalM128 vJacA = jac->m_angular0.m_vComponents;
        LocalM128 vJacB = jac->m_angular1.m_vComponents;
        hkVector4 vWeighted;
        vWeighted.m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_mul_ps(vJacA, vJacA), bodyA->m_vInverseInertiaAndMass.m_vComponents),
                       _mm_mul_ps(_mm_mul_ps(vJacB, vJacB), bodyB->m_vInverseInertiaAndMass.m_vComponents));
        hkVector4 m;
        m.m_vComponents =
            _mm_add_ps(bodyA->m_vInverseInertiaAndMass.m_vComponents, bodyB->m_vInverseInertiaAndMass.m_vComponents);
        hkVector4 s;
        s.setXYZW(vWeighted, m);
        float diag = HorizontalAdd4Scalar(s) + 1.1920928955078125e-07;
        jac->m_angular1.m_vComponents.m128_f32[3] = diag;
        jac->m_angular0.m_vComponents.m128_f32[3] = 1.0f / diag;
    }
    {
        hkVector4 d;
        d.setSub4(info.m_kPivotB, info.m_kPivotA);
        jac->m_kLinearJacobian.m_vComponents.m128_f32[3] = Dot3ScalarSIMD(d, info.m_dir) * factor;
    }
    Jac_dcf880* pJacOut = aQueryOut.m_pJacobian;
    float f34 = info.m_34;
    pJacOut->m_30 = info.m_30;
    pJacOut->m_34 = f34;
    pJacOut->m_kLinearJacobian.m_vComponents.m128_f32[0] += 1.1920928955078125e-07;
    *(unsigned char*)pJacOut = 7;
    aQueryOut.m_pJacobian = pJacOut + 1;
}

struct __declspec(align(16)) S_00dcf100_Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    hkVector4 invI;
    hkVector4 pos;
    hkVector4 col0;
    hkVector4 col1;
    hkVector4 col2;
};

struct S_00dcf100_Ref
{
    int unk00;
    float f04;
};

struct __declspec(align(16)) S_00dcf100_In
{
    hkVector4 v0;
    hkVector4 v1;
    float f20;
    S_00dcf100_Ref* p24;
};

struct S_00dcf100_Cfg
{
    int unk00;
    float f04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float f20;
    float f24;
    int unk28;
    int unk2c;
    S_00dcf100_Body* b30;
    S_00dcf100_Body* b34;
};

struct __declspec(align(16)) S_00dcf100_Out
{
    hkVector4 q0;
    hkVector4 t0;
    hkVector4 t1;
    float f30;
    int unk34;
    int unk38;
    int unk3c;
};

static __forceinline LocalM128 S_Ld(const hkVector4& v)
{
    return *(const LocalM128*)&v;
}

static __forceinline LocalM128 S_Cross(LocalM128 a, LocalM128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}

static __forceinline LocalM128 S_Rot(LocalM128 v, const S_00dcf100_Body* b)
{
    LocalM128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), S_Ld(b->col1)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), S_Ld(b->col0)));
    return _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), S_Ld(b->col2)));
}

// @fnv 0x00dcf100
// src: XBOX_PDB 0x00dcf100
void __cdecl hk1dLinearFrictionBuildJacobian(S_00dcf100_In* pInput, S_00dcf100_Cfg* pConfig, S_00dcf100_Out** ppOut)
{
    S_00dcf100_Out* out = *ppOut;
    S_00dcf100_Body* b0 = pConfig->b30;
    S_00dcf100_Body* b1 = pConfig->b34;
    float mass = pConfig->f24;
    *(LocalM128*)&out->q0 = S_Ld(pInput->v1);
    LocalM128 r0 = _mm_sub_ps(S_Ld(pInput->v0), S_Ld(b0->pos));
    LocalM128 r1 = _mm_sub_ps(S_Ld(pInput->v0), S_Ld(b1->pos));
    LocalM128 A1 = S_Ld(pInput->v1);
    LocalM128 c0 = S_Cross(r0, A1);
    LocalM128 c1 = S_Cross(A1, r1);
    *(LocalM128*)&out->t0 = S_Rot(c0, b0);
    LocalM128 t1 = S_Rot(c1, b1);
    *(LocalM128*)&out->t1 = t1;
    LocalM128 t0 = S_Ld(out->t0);
    LocalM128 vInvI1 = S_Ld(b1->invI);
    LocalM128 sum = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(t1, t1), vInvI1), _mm_mul_ps(_mm_mul_ps(t0, t0), S_Ld(b0->invI)));
    LocalM128 m = _mm_add_ps(S_Ld(b0->invI), vInvI1);
    LocalM128 hi = _mm_unpackhi_ps(sum, m);
    LocalM128 v = _mm_shuffle_ps(sum, hi, 0xc4);
    LocalM128 h = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4e), v);
    h = _mm_add_ps(_mm_shuffle_ps(h, h, 0xb1), h);
    float fHSum;
    _mm_store_ss(&fHSum, h);
    float d = (float)(fHSum + 1.1920928955078125e-07);
    out->t1.w = d;
    out->t0.w = mass / d;
    out->q0.w = pInput->p24->f04 * pConfig->f20;
    S_00dcf100_Out* cur = *ppOut;
    *ppOut = cur + 1;
    cur->f30 = pInput->f20 * pConfig->f04;
    *(float*)cur = (float)(*(float*)cur + 1.1920928955078125e-07);
    *(unsigned char*)cur = 9;
}

// @fnv 0x00dcee70
// src: XBOX_PDB 0x00dcee70
void __cdecl hkLoadVelocityAccumulators()
{}

extern double DAT_010c9300;
// Fills out with info's direction as the linear term and two angular terms from the body pivot offsets, then sets w terms from inverse inertia, rhs and scale.
// @fnv 0x00dcf460
// src: GUESS 0x00dcf460 (confidence: medium)
static __declspec(noinline) void Object_BuildLinearAngularJacobianRow(Jac_dcf880* apJacobian, const Info_dcf880* info,
                                              const QueryIn_dcf880* apQuery, float scale)
{
    const Accum_dcf880* bodyA = apQuery->m_pBodyA;
    const Accum_dcf880* bodyB = apQuery->m_pBodyB;
    float rhs = *(const float*)&apQuery->unk24;

    apJacobian->m_kLinearJacobian = info->m_dir;
    hkVector4 rA;
    rA.setSub4(info->m_kPivotA, bodyA->m_kCenterPosition);
    hkVector4 rB;
    rB.setSub4(info->m_kPivotA, bodyB->m_kCenterPosition);

    LocalM128 dir = info->m_dir.m_vComponents;
    LocalM128 dirC9 = _mm_shuffle_ps(dir, dir, 0xc9);
    LocalM128 dirD2 = _mm_shuffle_ps(dir, dir, 0xd2);
    hkVector4 vA;
    vA.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(rA.m_vComponents, rA.m_vComponents, 0xc9), dirD2),
                                  _mm_mul_ps(_mm_shuffle_ps(rA.m_vComponents, rA.m_vComponents, 0xd2), dirC9));
    hkVector4 vB;
    vB.m_vComponents = _mm_sub_ps(_mm_mul_ps(dirC9, _mm_shuffle_ps(rB.m_vComponents, rB.m_vComponents, 0xd2)),
                                  _mm_mul_ps(dirD2, _mm_shuffle_ps(rB.m_vComponents, rB.m_vComponents, 0xc9)));
    SetRotatedDirection(apJacobian->m_angular0, bodyA->m_rot, vA);
    SetRotatedDirection(apJacobian->m_angular1, bodyB->m_rot, vB);

    hkVector4 tA;
    tA.setMul4(apJacobian->m_angular0, apJacobian->m_angular0);
    tA.mul4(bodyA->m_vInverseInertiaAndMass);

    hkVector4 tB;
    tB.setMul4(apJacobian->m_angular1, apJacobian->m_angular1);
    tB.mul4(bodyB->m_vInverseInertiaAndMass);

    hkVector4 sumAB;
    sumAB.setAdd4(tA, tB);

    hkVector4 invMassesSum;
    invMassesSum.setAdd4(bodyA->m_vInverseInertiaAndMass, bodyB->m_vInverseInertiaAndMass);

    hkVector4 combined;
    combined.setXYZW(sumAB, invMassesSum);

    float sum = HorizontalAdd4Scalar(combined) + DAT_010c9300;
    apJacobian->m_angular1.m_vComponents.m128_f32[3] = sum;
    apJacobian->m_angular0.m_vComponents.m128_f32[3] = rhs / sum;
    apJacobian->m_kLinearJacobian.m_vComponents.m128_f32[3] = apQuery->m_factor * scale;
}
Jac_dcf880* volatile g_out_dcf460;
const Info_dcf880* volatile g_info_dcf460;
const QueryIn_dcf880* volatile g_in_dcf460;
volatile float g_scale_dcf460;
void CallTarget_dcf460()
{
    Jac_dcf880* o = g_out_dcf460;
    const Info_dcf880* i = g_info_dcf460;
    const QueryIn_dcf880* n = g_in_dcf460;
    Object_BuildLinearAngularJacobianRow(o, i, n, g_scale_dcf460);
    Object_BuildLinearAngularJacobianRow(o, i, n, g_scale_dcf460);
}

struct Input_dcf5b0
{
    LocalM128 pivot;
    LocalM128 unused10;
    LocalM128 direction;
};

struct Jacobian_dcf5b0
{
    hkVector4 linear;
    hkVector4 angularA;
    hkVector4 angularB;
};
extern double DAT_010c9300;

// Builds a Jacobian from a pivot, direction and two body frames, writes it to the output slot, and advances the output pointer.
// @fnv 0x00dcf5b0
// src: GUESS 0x00dcf5b0 (confidence: medium)
void __cdecl Hkp1dbilateralconstraintbuildjacobian_BuildJacobianAndAdvance(Input_dcf5b0* apInput, S_00dcf100_Cfg* apCfg, Jacobian_dcf5b0** ppJacobian, float k)
{
    S_00dcf100_Body* ecx = apCfg->b30;
    float fa = apCfg->f24;
    S_00dcf100_Body* edx = apCfg->b34;
    Jacobian_dcf5b0* out = *ppJacobian;
    out->linear.quad = apInput->direction;
    LocalM128 p0 = apInput->pivot;
    LocalM128 a = _mm_sub_ps(p0, S_Ld(ecx->pos));
    LocalM128 b = _mm_sub_ps(apInput->pivot, S_Ld(edx->pos));
    LocalM128 x = apInput->direction;
    LocalM128 s3 = _mm_shuffle_ps(x, x, 0xc9);
    LocalM128 s4 = _mm_shuffle_ps(x, x, 0xd2);
    LocalM128 ac9 = _mm_shuffle_ps(a, a, 0xc9);
    LocalM128 ad2 = _mm_shuffle_ps(a, a, 0xd2);
    LocalM128 bc9 = _mm_shuffle_ps(b, b, 0xc9);
    LocalM128 bd2 = _mm_shuffle_ps(b, b, 0xd2);
    LocalM128 c1 = _mm_sub_ps(_mm_mul_ps(ac9, s4), _mm_mul_ps(ad2, s3));
    LocalM128 c2 = _mm_sub_ps(_mm_mul_ps(bd2, s3), _mm_mul_ps(bc9, s4));

    LocalM128 m50 = S_Ld(ecx->col0);
    LocalM128 m60 = S_Ld(ecx->col1);
    LocalM128 m70 = S_Ld(ecx->col2);
    LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0x55), m60);
    r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0), m50));
    r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0xaa), m70));
    out->angularA.quad = r1;

    LocalM128 n50 = S_Ld(edx->col0);
    LocalM128 n60 = S_Ld(edx->col1);
    LocalM128 n70 = S_Ld(edx->col2);
    LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0x55), n60);
    r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0), n50));
    r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0xaa), n70));
    out->angularB.quad = r2;

    LocalM128 f30 = S_Ld(edx->invI);
    LocalM128 e30 = S_Ld(ecx->invI);
    r1 = out->angularA.quad;
    LocalM128 sq = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(r2, r2), f30), _mm_mul_ps(_mm_mul_ps(r1, r1), e30));
    LocalM128 t = _mm_add_ps(e30, f30);
    LocalM128 unp = _mm_unpackhi_ps(sq, t);
    LocalM128 v = _mm_shuffle_ps(sq, unp, 0xc4);
    LocalM128 h = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4e), v);
    LocalM128 g = _mm_add_ps(_mm_shuffle_ps(h, h, 0xb1), h);
    float sum;
    _mm_store_ss(&sum, g);

    double c = 1.1920928955078125e-7;
    float tt = (float)((double)sum + c);
    out->angularB.w = tt;
    out->angularA.w = fa / tt;
    out->linear.w = apCfg->f20 * k;
    out = *ppJacobian + 1;
    out[-1].linear.x = (float)(c + out[-1].linear.x);
    *(unsigned char*)&out[-1].linear = 5;
    *ppJacobian = out;
}

extern double DAT_010c9300;

// @fnv 0x00dcfa30
// src: XBOX_PDB 0x00dcfa30
void __cdecl hk1dLinearLimitBuildJacobian(Info_dcf880* a1, S_00dcf100_Cfg* apCfg, Jac_dcf880** ppJacobian)
{
    LocalM128 x = a1->m_dir.m_vComponents;
    Jac_dcf880* out = *ppJacobian;
    float fa = apCfg->f24;
    S_00dcf100_Body* A = apCfg->b30;
    S_00dcf100_Body* B = apCfg->b34;
    float fCfg20 = apCfg->f20;
    out->m_kLinearJacobian.m_vComponents = x;

    LocalM128 a = _mm_sub_ps(a1->m_kPivotA.m_vComponents, S_Ld(A->pos));
    LocalM128 b = _mm_sub_ps(a1->m_kPivotB.m_vComponents, S_Ld(B->pos));

    LocalM128 x2 = a1->m_dir.m_vComponents;
    LocalM128 s3 = _mm_shuffle_ps(x2, x2, 0xc9);
    LocalM128 s4 = _mm_shuffle_ps(x2, x2, 0xd2);
    LocalM128 c1 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), s4), _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), s3));
    LocalM128 c2 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), s3), _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), s4));

    LocalM128 m50 = S_Ld(A->col0);
    LocalM128 m60 = S_Ld(A->col1);
    LocalM128 m70 = S_Ld(A->col2);
    LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0x55), m60);
    r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0), m50));
    r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0xaa), m70));
    out->m_angular0.m_vComponents = r1;

    LocalM128 n50 = S_Ld(B->col0);
    LocalM128 n60 = S_Ld(B->col1);
    LocalM128 n70 = S_Ld(B->col2);
    LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0x55), n60);
    r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0), n50));
    r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0xaa), n70));
    out->m_angular1.m_vComponents = r2;

    LocalM128 f30 = S_Ld(B->invI);
    LocalM128 e30 = S_Ld(A->invI);
    r1 = out->m_angular0.m_vComponents;
    LocalM128 sq = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(r1, r1), e30), _mm_mul_ps(_mm_mul_ps(r2, r2), f30));
    LocalM128 t = _mm_add_ps(e30, f30);
    LocalM128 unp = _mm_unpackhi_ps(sq, t);
    LocalM128 v = _mm_shuffle_ps(sq, unp, 0xc4);
    LocalM128 h = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4e), v);
    LocalM128 g = _mm_add_ps(_mm_shuffle_ps(h, h, 0xb1), h);
    float sum;
    _mm_store_ss(&sum, g);

    float tt = (float)((double)sum + DAT_010c9300);
    double c = DAT_010c9300;
    out->m_angular1.m_vComponents.m128_f32[3] = tt;
    out->m_angular0.m_vComponents.m128_f32[3] = fa / tt;

    LocalM128 d =
        _mm_mul_ps(_mm_sub_ps(a1->m_kPivotB.m_vComponents, a1->m_kPivotA.m_vComponents), a1->m_dir.m_vComponents);
    LocalM128 p = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    LocalM128 q = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), p);
    float dot;
    _mm_store_ss(&dot, q);
    out->m_kLinearJacobian.m_vComponents.m128_f32[3] = dot * fCfg20;

    float nfb = -apCfg->f20;
    float t30 = a1->m_30;
    float t34 = a1->m_34;
    Jac_dcf880* o = *ppJacobian;
    *ppJacobian = o + 1;
    o->m_30 = t30 * nfb;
    o->m_34 = t34 * nfb;
    o->m_kLinearJacobian.m_vComponents.m128_f32[0] = (float)(c + o->m_kLinearJacobian.m_vComponents.m128_f32[0]);
    *(unsigned char*)&o->m_kLinearJacobian.m_vComponents = 8;
}

extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern double DAT_010c9300;
extern LocalM128 DAT_010c44d0;
struct Src
{
    LocalM128* verts;
    float* volatile fl;
    float unk08;
    int count;
};
struct Cfg
{
    int unk00;
    volatile float unk04;
    float unk08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    S_00dcf100_Body* A;
    S_00dcf100_Body* B;
};

struct JOut
{
    hkVector4 a, b;
    float c20;
    int unk24, unk28, unk2c;
};
// For each of s->count vertices, writes its A- and B-rotated vectors to the output array, with 1/(inertia-weighted squared sum + epsilon) in a.w.
// @fnv 0x00dcefb0
// src: GUESS 0x00dcefb0 (confidence: medium)
void __cdecl Hkp1dbilateralconstraintbuildjacobian_BuildRotatedVertexJacobianPairs(Src* apSrc, Cfg* cfg, JOut** appOut)
{
    float* pFloats = apSrc->fl;
    JOut* out = *appOut;
    LocalM128* pv = apSrc->verts;
    float sum;
    int i = apSrc->count - 1;
    if (i >= 0)
    {
        double c = DAT_010c9300;
        float* pf = pFloats + 1;
        do
        {
            S_00dcf100_Body* B = cfg->B;
            S_00dcf100_Body* A = cfg->A;
            LocalM128 neg = _mm_xor_ps((*pv), DAT_010c44d0);
            LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps((*pv), (*pv), 0x55), S_Ld(A->col1));
            r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps((*pv), (*pv), 0), S_Ld(A->col0)));
            r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps((*pv), (*pv), 0xaa), S_Ld(A->col2)));
            out->a.quad = r1;
            LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(neg, neg, 0x55), S_Ld(B->col1));
            r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(neg, neg, 0), S_Ld(B->col0)));
            r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(neg, neg, 0xaa), S_Ld(B->col2)));
            out->b.quad = r2;
            LocalM128 reloaded = out->a.quad;
            LocalM128 sq = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(reloaded, reloaded), S_Ld(A->invI)),
                                   _mm_mul_ps(_mm_mul_ps(r2, r2), S_Ld(B->invI)));
            LocalM128 s1 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
            LocalM128 s2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s1);
            _mm_store_ss(&sum, s2);
            float tt = (float)((double)sum + c);
            out->a.w = 1.0f / tt;
            out->b.w = cfg->unk08 * *pf;
            out->c20 = apSrc->unk08 * cfg->unk04;
            out->a.x = (float)((double)out->a.x + c);
            *(unsigned char*)&out->a = 0xe;
            ++out;
            pv++;
            pf += 2;
        } while (--i >= 0);
    }
    *appOut = out;
}

struct Input_dcf280
{
    LocalM128 pivot;
    LocalM128 pivotB;
    LocalM128 direction;
};

struct Jacobian_dcf280
{
    hkVector4 linear;
    hkVector4 angularA;
    hkVector4 angularB;
};
extern double DAT_010c9300;

// Fills the Jacobian at *a3 with the direction as the linear term and two angular terms from pivot offsets of the two bodies in a2, then advances *a3.
// @fnv 0x00dcf280
// src: XBOX_PDB 0x00dcf280
void __cdecl hk1dLinearBilateralConstraintBuildJacobian(Input_dcf280* apInput, S_00dcf100_Cfg* apCfg, Jacobian_dcf280** ppJacobian)
{
    LocalM128 x0 = apInput->direction;
    S_00dcf100_Body* ecx = apCfg->b30;
    float fa = apCfg->f24;
    S_00dcf100_Body* edx = apCfg->b34;
    float fa2 = apCfg->f20;
    Jacobian_dcf280* out = *ppJacobian;
    out->linear.quad = x0;

    LocalM128 p0 = apInput->pivot;
    LocalM128 a = _mm_sub_ps(p0, S_Ld(ecx->pos));
    LocalM128 b = _mm_sub_ps(apInput->pivot, S_Ld(edx->pos));
    LocalM128 x = apInput->direction;

    LocalM128 c1 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(x, x, 0xd2)),
                           _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(x, x, 0xc9)));
    LocalM128 c2 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(x, x, 0xc9)),
                           _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(x, x, 0xd2)));

    LocalM128 m50 = S_Ld(ecx->col0);
    LocalM128 m60 = S_Ld(ecx->col1);
    LocalM128 m70 = S_Ld(ecx->col2);
    LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0x55), m60);
    r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0), m50));
    r1 = _mm_add_ps(r1, _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0xaa), m70));
    out->angularA.quad = r1;

    LocalM128 n50 = S_Ld(edx->col0);
    LocalM128 n60 = S_Ld(edx->col1);
    LocalM128 n70 = S_Ld(edx->col2);
    LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0x55), n60);
    r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0), n50));
    r2 = _mm_add_ps(r2, _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0xaa), n70));
    out->angularB.quad = r2;

    LocalM128 f30 = S_Ld(edx->invI);
    LocalM128 e30 = S_Ld(ecx->invI);
    r1 = out->angularA.quad;
    hkVector4 hq1;
    hq1.m_vComponents = r1;
    hq1.mul4(hq1);
    hq1.mul4(ecx->invI);
    hkVector4 hq2;
    hq2.m_vComponents = r2;
    hq2.mul4(hq2);
    hq2.mul4(edx->invI);
    hq1.add4(hq2);
    LocalM128 sq = hq1.m_vComponents;
    LocalM128 t = _mm_add_ps(e30, f30);
    LocalM128 unp = _mm_unpackhi_ps(sq, t);
    LocalM128 v = _mm_shuffle_ps(sq, unp, 0xc4);
    LocalM128 h = _mm_add_ps(_mm_shuffle_ps(v, v, 0x4e), v);
    LocalM128 g = _mm_add_ps(_mm_shuffle_ps(h, h, 0xb1), h);
    float sum;
    _mm_store_ss(&sum, g);

    double c = 1.1920928955078125e-7;
    sum = (float)((double)sum + c);
    out->angularB.w = sum;
    out->angularA.w = fa / sum;

    LocalM128 z = _mm_sub_ps(apInput->pivot, apInput->pivot);
    LocalM128 w = _mm_mul_ps(z, apInput->direction);
    LocalM128 w1 = _mm_shuffle_ps(w, w, 0x55);
    w1 = _mm_add_ss(w1, w);
    LocalM128 w2 = _mm_shuffle_ps(w, w, 0xaa);
    w2 = _mm_add_ss(w2, w1);
    {
        float d;
        _mm_store_ss(&d, w2);
        out->linear.w = d * fa2;
    }

    LocalM128 y = _mm_sub_ps(apInput->pivotB, apInput->pivot);
    y = _mm_mul_ps(y, apInput->direction);
    LocalM128 y1 = _mm_shuffle_ps(y, y, 0x55);
    y1 = _mm_add_ss(y1, y);
    LocalM128 y2 = _mm_shuffle_ps(y, y, 0xaa);
    y2 = _mm_add_ss(y2, y1);
    {
        float s;
        _mm_store_ss(&s, y2);
        out->linear.w = apCfg->f20 * s;
    }

    out = *ppJacobian + 1;
    out[-1].linear.x = (float)(c + out[-1].linear.x);
    *(unsigned char*)&out[-1].linear = 5;
    *ppJacobian = out;
}

static __forceinline LocalM128 S_00dcf720_cross(const LocalM128& a, const LocalM128& b)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}

#include "../../../../../../include/hkRotation.h"


static __forceinline LocalM128 S_00dcf720_rotate(const hkRotation& r, const LocalM128& v)
{
    const LocalM128 b0 = _mm_shuffle_ps(v, v, 0x0);
    const LocalM128 r0 = _mm_mul_ps(b0, r.m_kColumn0.q());
    const LocalM128 b1 = _mm_shuffle_ps(v, v, 0x55);
    const LocalM128 r1 = _mm_mul_ps(b1, r.m_kColumn1.q());
    const LocalM128 b2 = _mm_shuffle_ps(v, v, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(b2, r.m_kColumn2.q());
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct S_00dcf720_Accumulator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_kCenterOfMass1;
    hkRotation m_coreFromWorld;
};

struct S_00dcf720_QueryIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20;
    float m_fFourthQueryValue;
    int unk28;
    int unk2c;
    const S_00dcf720_Accumulator* m_pBodyA;
    const S_00dcf720_Accumulator* m_pBodyB;
};

struct S_00dcf720_Info
{
    hkVector4 m_kPivotVector;
    hkVector4 unk10;
    hkVector4 m_kAxisEndPoints;
};

struct S_00dcf720_Jacobian
{
    hkVector4 m_kLinearJacobian;
    hkVector4 m_kAngularVelocity[2];

    __forceinline float getDiag(const S_00dcf720_Accumulator& mA, const S_00dcf720_Accumulator& mB) const
    {
        LocalM128 ang0 = _mm_mul_ps(m_kAngularVelocity[0].q(), m_kAngularVelocity[0].q());
        LocalM128 ang1 = _mm_mul_ps(m_kAngularVelocity[1].q(), m_kAngularVelocity[1].q());
        ang0 = _mm_mul_ps(ang0, mA.m_vInverseInertiaAndMass.q());
        ang1 = _mm_mul_ps(ang1, mB.m_vInverseInertiaAndMass.q());
        const LocalM128 sumInvMass = _mm_add_ps(mA.m_vInverseInertiaAndMass.q(), mB.m_vInverseInertiaAndMass.q());
        ang0 = _mm_add_ps(ang0, ang1);
        ang0 = _mm_shuffle_ps(ang0, _mm_unpackhi_ps(ang0, sumInvMass), 0xc4);
        LocalM128 sum = _mm_add_ps(_mm_shuffle_ps(ang0, ang0, 0x4e), ang0);
        sum = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
        float r;
        _mm_store_ss(&r, sum);
        return r;
    }
};

// Builds a Jacobian from info's axis and pivot for two bodies, storing diag in angular[1].w and the fourth query value divided by diag in angular[0].w.
// @fnv 0x00dcf720
// src: XBOX_PDB 0x00dcf720
void hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(const S_00dcf720_Info& info, const S_00dcf720_QueryIn& in, S_00dcf720_Jacobian* jac, float rhsFactor)
{
    const S_00dcf720_Accumulator& bodyA = *in.m_pBodyA;
    const S_00dcf720_Accumulator& bodyB = *in.m_pBodyB;
    float virtMassFactor = in.m_fFourthQueryValue;

    jac->m_kLinearJacobian.q() = info.m_kAxisEndPoints.q();
    LocalM128 rA = _mm_sub_ps(info.m_kPivotVector.q(), bodyA.m_kCenterOfMass1.q());
    LocalM128 rB = _mm_sub_ps(info.m_kPivotVector.q(), bodyB.m_kCenterOfMass1.q());
    const LocalM128 axis = info.m_kAxisEndPoints.q();
    LocalM128 tA = S_00dcf720_cross(rA, axis);
    LocalM128 tB = S_00dcf720_cross(axis, rB);
    jac->m_kAngularVelocity[0].q() = S_00dcf720_rotate(bodyA.m_coreFromWorld, tA);
    jac->m_kAngularVelocity[1].q() = S_00dcf720_rotate(bodyB.m_coreFromWorld, tB);

    float diag = jac->getDiag(bodyA, bodyB);
    diag = diag + 1.1920928955078125e-7;
    jac->m_kAngularVelocity[1].w = diag;
    jac->m_kAngularVelocity[0].w = virtMassFactor / diag;
    jac->m_kLinearJacobian.w = in.unk20 * rhsFactor;
}

// Adapted from an earlier contributor's 2026-10-21 WIP; retain prior credit.

extern "C" LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);

static const double S00dcee80_kEps = 1.1920928955078125e-07;

inline float hkVector4::dot3scalar(const hkVector4& a) const
{
    return y * a.y + x * a.x + z * a.z;
}

static inline float HorizontalAdd3Scalar(const hkVector4& vector)
{
    const LocalM128 s = _mm_add_ss(_mm_shuffle_ps(vector.q(), vector.q(), 0x55), vector.q());
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(vector.q(), vector.q(), 0xaa), s));
    return r;
}

inline void hkVector4::setNeg4(const hkVector4& v)
{

    q() = _mm_xor_ps(v.q(), DAT_010c44d0);
}

#include "../../../../../../include/hkMatrix3.h"


static inline void S_00dcee80_setRotatedDir(hkVector4& out, const hkMatrix3& a, const LocalM128 b)
{

    const LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0x55), a.m_kColumn1.q());

    const LocalM128 r0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0x00), a.m_kColumn0.q());

    const LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xaa), a.m_kColumn2.q());

    out.q() = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}

struct S_00dcee80_Accumulator
{

    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;

    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    hkVector4 m_vInverseInertiaAndMass, m_kCenterOfMass1;

    hkMatrix3 m_kInverseInertiaMatrix;
};

struct S_00dcee80_QueryIn
{

    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    float m_fThirdQueryValue;
    float m_fFourthQueryValue;
    int unk28;
    int unk2c;

    const S_00dcee80_Accumulator* m_pBodyA;

    const S_00dcee80_Accumulator* m_pBodyB;
};

struct S_00dcee80_Info
{
    hkVector4 m_kPointA, m_kAxisEndPoints, m_kPointB;
};

struct __declspec(align(16)) S_00dcee80_Jacobian
{

    hkVector4 m_kAngularVelocity[2];

    __forceinline float getAngularDiag(const S_00dcee80_Accumulator& mA, const S_00dcee80_Accumulator& mB) const
    {

        hkVector4 dia;
        dia.setMul4(m_kAngularVelocity[0], m_kAngularVelocity[0]);

        dia.mul4(mA.m_vInverseInertiaAndMass);

        hkVector4 dib;
        dib.setMul4(m_kAngularVelocity[1], m_kAngularVelocity[1]);

        dib.mul4(mB.m_vInverseInertiaAndMass);

        dia.add4(dib);

        return HorizontalAdd3Scalar(dia);
    }
};

struct S_00dcee80_SchemaHeader
{
    float m_uiFilterValue;
};

struct S_00dcee80_QueryOut
{
    S_00dcee80_Jacobian* m_jacobians;
};

// Fills a Jacobian's two angular terms from info's axis end points and the bodies' inverse inertia matrices, sets their w terms, and advances out.m_jacobians.
// @fnv 0x00dcee80
// src: XBOX_PDB 0x00dcee80
void hk1dAngularBilateralConstraintBuildJacobian(const S_00dcee80_Info& info, const S_00dcee80_QueryIn& in, S_00dcee80_QueryOut& out)
{

    const LocalM128 axis = info.m_kAxisEndPoints.q();

    hkVector4 negAxisV;
    negAxisV.setNeg4(info.m_kAxisEndPoints);

    const LocalM128 negAxis = negAxisV.q();

    S_00dcee80_Jacobian* jac = out.m_jacobians;

    const S_00dcee80_Accumulator* mB = in.m_pBodyB;

    const S_00dcee80_Accumulator* mA = in.m_pBodyA;

    const float virtMassFactor = in.m_fFourthQueryValue;

    S_00dcee80_setRotatedDir(jac->m_kAngularVelocity[0], mA->m_kInverseInertiaMatrix, axis);

    S_00dcee80_setRotatedDir(jac->m_kAngularVelocity[1], mB->m_kInverseInertiaMatrix, negAxis);

    const float diag = jac->getAngularDiag(*mA, *mB) + S00dcee80_kEps;

    jac->m_kAngularVelocity[0].w = virtMassFactor / diag;

    const float dot = info.m_kPointA.dot3scalar(info.m_kPointB);

    jac->m_kAngularVelocity[1].w = -dot * in.m_fThirdQueryValue;

    S_00dcee80_SchemaHeader* head = reinterpret_cast<S_00dcee80_SchemaHeader*>(out.m_jacobians);

    out.m_jacobians = out.m_jacobians + 1;

    head->m_uiFilterValue = head->m_uiFilterValue + S00dcee80_kEps;

    *reinterpret_cast<unsigned char*>(head) = 0xc;
}
