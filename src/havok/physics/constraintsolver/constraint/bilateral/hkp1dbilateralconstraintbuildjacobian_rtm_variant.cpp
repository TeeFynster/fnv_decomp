#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
// src/havok/physics/constraintsolver/constraint/bilateral/hkp1dbilateralconstraintbuildjacobian_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/constraint/bilateral/hkp1dbilateralconstraintbuildjacobian.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/constraintsolver/constraint/bilateral/hkp1dbilateralconstraintbuildjacobian.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/bilateral/hkp1dbilateralconstraintbuildjacobian.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Preserve the unit's original intrinsic layout: VC9 /GS treats the SDK's
// additional byte lanes as a local character buffer and changes parameter spills.
#define _INCLUDED_MM2
// Exe 0x00dcfc00 FUN_00dcfc00: retain this LocalM128 view; the CRT type does not preserve this unit.
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
extern "C" LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"

inline float& hkVector4::component(int i)
{
    return m_vComponents.m128_f32[i];
}


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
static __forceinline float HorizontalAdd4Scalar(const hkVector4& vector)
{
    LocalM128 sum0 = _mm_add_ps(_mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0x4e), vector.m_vComponents);
    LocalM128 sum1 = _mm_add_ps(_mm_shuffle_ps(sum0, sum0, 0xb1), sum0);
    float r;
    _mm_store_ss(&r, sum1);
    return r;
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
void __cdecl ComputeAngularJacobian(const Info_dcf880& info, const QueryIn_dcf880& aQueryIn,
                                    QueryOut_dcf880& aQueryOut);
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
    return v.m_vComponents;
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
void __cdecl hk1dLinearFrictionBuildJacobian(S_00dcf100_In* pInput, S_00dcf100_Cfg* pConfig, S_00dcf100_Out** ppOut);
void __cdecl hkLoadVelocityAccumulators();
extern double DAT_010c9300;
static void Object_BuildLinearAngularJacobianRow(Jac_dcf880* out, const Info_dcf880* info, const QueryIn_dcf880* in, float scale);
Jac_dcf880* volatile g_out_dcf460;
const Info_dcf880* volatile g_info_dcf460;
const QueryIn_dcf880* volatile g_in_dcf460;
volatile float g_scale_dcf460;
void CallTarget_dcf460();
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
void __cdecl Hkp1dbilateralconstraintbuildjacobian_BuildJacobianAndAdvance(Input_dcf5b0* a1, S_00dcf100_Cfg* a2, Jacobian_dcf5b0** a3, float k);
extern double DAT_010c9300;
void __cdecl hk1dLinearLimitBuildJacobian(Info_dcf880* a1, S_00dcf100_Cfg* a2, Jac_dcf880** a3);
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
void __cdecl Hkp1dbilateralconstraintbuildjacobian_BuildRotatedVertexJacobianPairs(Src* s, Cfg* cfg, JOut** a3);
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
void __cdecl hk1dLinearBilateralConstraintBuildJacobian(Input_dcf280* a1, S_00dcf100_Cfg* a2, Jacobian_dcf280** a3);
static __forceinline LocalM128 S_00dcf720_cross(const LocalM128& a, const LocalM128& b)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
static __forceinline LocalM128 S_00dcf720_rotate(const hkMatrix3& r, const LocalM128& v)
{
    const LocalM128 b0 = _mm_shuffle_ps(v, v, 0x0);
    const LocalM128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
    const LocalM128 b1 = _mm_shuffle_ps(v, v, 0x55);
    const LocalM128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
    const LocalM128 b2 = _mm_shuffle_ps(v, v, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
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
    hkMatrix3 m_coreFromWorld;
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
        LocalM128 ang0 = _mm_mul_ps(m_kAngularVelocity[0].m_vComponents, m_kAngularVelocity[0].m_vComponents);
        LocalM128 ang1 = _mm_mul_ps(m_kAngularVelocity[1].m_vComponents, m_kAngularVelocity[1].m_vComponents);
        ang0 = _mm_mul_ps(ang0, mA.m_vInverseInertiaAndMass.m_vComponents);
        ang1 = _mm_mul_ps(ang1, mB.m_vInverseInertiaAndMass.m_vComponents);
        const LocalM128 sumInvMass = _mm_add_ps(mA.m_vInverseInertiaAndMass.m_vComponents, mB.m_vInverseInertiaAndMass.m_vComponents);
        ang0 = _mm_add_ps(ang0, ang1);
        ang0 = _mm_shuffle_ps(ang0, _mm_unpackhi_ps(ang0, sumInvMass), 0xc4);
        LocalM128 sum = _mm_add_ps(_mm_shuffle_ps(ang0, ang0, 0x4e), ang0);
        sum = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
        float r;
        _mm_store_ss(&r, sum);
        return r;
    }
};
void hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(const S_00dcf720_Info& info, const S_00dcf720_QueryIn& in, S_00dcf720_Jacobian* jac, float rhsFactor);
// Adapted from an earlier contributor's 2026-10-21 WIP; retain prior credit.
static const double S00dcee80_kEps = 1.1920928955078125e-07;
static inline void S_00dcee80_setRotatedDir(hkVector4& out, const hkMatrix3& a, const LocalM128 b)
{

    const LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0x55), a.m_kColumn1.m_vComponents);

    const LocalM128 r0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0x00), a.m_kColumn0.m_vComponents);

    const LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xaa), a.m_kColumn2.m_vComponents);

    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
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

        const LocalM128 s = _mm_add_ss(_mm_shuffle_ps(dia.m_vComponents, dia.m_vComponents, 0x55), dia.m_vComponents);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(dia.m_vComponents, dia.m_vComponents, 0xaa), s));
        return r;
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
void hk1dAngularBilateralConstraintBuildJacobian(const S_00dcee80_Info& info, const S_00dcee80_QueryIn& in, S_00dcee80_QueryOut& out);

#include <math.h>
struct Input102
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float factor, tau;
    int unk28, unk2c;
    Accum_dcf880* bodyA;
    Accum_dcf880* bodyB;
};
struct Row102
{
    hkVector4 linear, angularA, angularB;
};
extern hkVector4 DAT_010ec7f0;
extern double DAT_010c9300;
extern hkVector4 DAT_01268370[];
void Hkpbuildjacobianfromatoms_BuildThreeConstraintRows(const hkVector4*, const hkVector4*, const Input102*, Row102*);
static float DotValue(LocalM128 v, LocalM128 a)
{
    LocalM128 p = _mm_mul_ps(v, a);
    LocalM128 t = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
    float f;
    _mm_store_ss(&f, t);
    return f;
}
static void RotateCols(hkVector4& out, const hkVector4& c0, const hkVector4& c1, const hkVector4& c2,
                       const hkVector4& v)
{
    LocalM128 r0 = _mm_mul_ps(c0.m_vComponents, _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0));
    LocalM128 r1 = _mm_mul_ps(c1.m_vComponents, _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55));
    LocalM128 r2 = _mm_mul_ps(c2.m_vComponents, _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa));
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
// @fnv 0x00dcfc00
// src: XBOX_PDB 0x00dcfc00
void hkStabilizedBallSocketConstraintBuildJacobian_noSchema(const hkVector4* pivotA, const hkVector4* pivotB, float maxForce, const Input102* in, Row102* jac)
{
    Accum_dcf880* bodyA = in->bodyA;
    Accum_dcf880* bodyB = in->bodyB;
    Hkpbuildjacobianfromatoms_BuildThreeConstraintRows(pivotA, pivotB, in, jac);
    hkVector4 velocity;
    velocity.component(0) = jac[0].linear.m_vComponents.m128_f32[3];
    velocity.component(1) = jac[1].linear.m_vComponents.m128_f32[3];
    velocity.component(2) = jac[2].linear.m_vComponents.m128_f32[3];
    float limit = in->factor * maxForce;
    LocalM128 squared = _mm_mul_ps(velocity.m_vComponents, velocity.m_vComponents);
    LocalM128 sum =
        _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared));
    float length;
    _mm_store_ss(&length, _mm_sqrt_ss(sum));
    if (length > limit)
    {
        float scale = limit / length;
        scale = sqrtf(scale);
        scale = sqrtf(scale);
        double eps = DAT_010c9300;
        LocalM128 ones = DAT_010ec7f0.m_vComponents;
        LocalM128 t = _mm_load_ss(&scale);
        LocalM128 sa = _mm_shuffle_ps(t, t, 0);
        hkVector4 a;
        a.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ones, sa), bodyA->m_kCenterPosition.m_vComponents),
                                     _mm_mul_ps(pivotA->m_vComponents, sa));
        LocalM128 t2 = _mm_load_ss(&scale);
        LocalM128 sb = _mm_shuffle_ps(t2, t2, 0);
        hkVector4 b;
        b.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ones, sb), bodyB->m_kCenterPosition.m_vComponents),
                                     _mm_mul_ps(pivotB->m_vComponents, sb));
        Row102* row = jac;
        hkVector4* axis = DAT_01268370;
        int n = 0;
        do
        {
            float tau = in->tau;
            float factor = in->factor;
            row->linear = *axis;
            hkVector4 ra;
            hkVector4 rb;
            ra.setSub4(a, bodyA->m_kCenterPosition);
            rb.setSub4(b, bodyB->m_kCenterPosition);
            hkVector4 ca;
            hkVector4 cb;
            ca.setCross(ra, *axis);
            cb.setCross(*axis, rb);
            RotateCols(row->angularA, bodyA->m_rot.m_kColumn0, bodyA->m_rot.m_kColumn1, bodyA->m_rot.m_kColumn2, ca);
            LocalM128 rotationB0 = _mm_mul_ps(bodyB->m_rot.m_kColumn0.m_vComponents,
                                           _mm_shuffle_ps(cb.m_vComponents, cb.m_vComponents, 0));
            LocalM128 rotationB1 = _mm_mul_ps(bodyB->m_rot.m_kColumn1.m_vComponents,
                                           _mm_shuffle_ps(cb.m_vComponents, cb.m_vComponents, 85));
            LocalM128 rotationB2 = _mm_mul_ps(bodyB->m_rot.m_kColumn2.m_vComponents,
                                           _mm_shuffle_ps(cb.m_vComponents, cb.m_vComponents, 170));
            row->angularB.m_vComponents = _mm_add_ps(_mm_add_ps(rotationB0, rotationB1), rotationB2);
            hkVector4 invB;
            invB.m_vComponents = bodyB->m_vInverseInertiaAndMass.m_vComponents;
            hkVector4 invA;
            invA.m_vComponents = bodyA->m_vInverseInertiaAndMass.m_vComponents;
            hkVector4 massA;
            hkVector4 massB;
            hkVector4 total;
            hkVector4 linearMass;
            massA.setMul4(row->angularA, row->angularA);
            massA.mul4(invA);
            massB.setMul4(row->angularB, row->angularB);
            massB.mul4(invB);
            total.setAdd4(massA, massB);
            linearMass.setAdd4(invA, invB);
            total.setXYZW(total, linearMass);
            float diagonal = HorizontalAdd4Scalar(total) + eps;
            LocalM128 projectedInput = _mm_sub_ps(b.m_vComponents, a.m_vComponents);
            row->angularB.m_vComponents.m128_f32[3] = diagonal;
            row->angularA.m_vComponents.m128_f32[3] = tau / diagonal;
            row->linear.m_vComponents.m128_f32[3] = DotValue(projectedInput, axis->m_vComponents) * factor;
            ++axis;
            ++row;
            ++n;
        } while (n < 3);

        float k = scale;
        jac[0].linear.m_vComponents.m128_f32[3] = velocity.m_vComponents.m128_f32[0] * k;
        jac[1].linear.m_vComponents.m128_f32[3] = velocity.m_vComponents.m128_f32[1] * k;
        jac[2].linear.m_vComponents.m128_f32[3] = velocity.m_vComponents.m128_f32[2] * k;
    }
}
