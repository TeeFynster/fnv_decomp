// src/havok/common/base/math/matrix/hkmatrix4_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/math/matrix/hkmatrix4_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHs-c- /Gy (unit lists /MT /O2 /GS- /EHs-c- /Gy). Declarations copied from that unit's skeleton.


// src/havok/common/base/math/matrix/hkmatrix4_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/matrix/hkmatrix4.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkMatrix4.h"


__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
}

struct CB20B0_Class
{
    void hkTransform_set4x4ColumnMajor(void* src);
};
struct SourceBlockCDF
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};
struct TargetBlockCDF
{
    void hkMatrix3_setMul(SourceBlockCDF* pkSource, int iArg);
};
struct FUN_00cdf230_cls
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    SourceBlockCDF m_kSource;
    TargetBlockCDF m_kRoomNode;
    void hkpRagdollConstraintData_setTarget(int iArg);
};
struct Row
{
    __m128 v;
    void operator+=(const Row& o)
    {
        __m128 t = o.v;
        v = _mm_add_ps(t, v);
    }
};
// src: GUESS 0x00de88a0 (confidence: low)
__declspec(noinline) void hkMatrix4::ProcessAndReturnValue_00de88a0(const hkSimdReal& s, const hkMatrix4& m)
{
    m_kColumn0.setMul4(s, m.m_kColumn0);
    m_kColumn1.setMul4(s, m.m_kColumn1);
    m_kColumn2.setMul4(s, m.m_kColumn2);
    m_kColumn3.setMul4(s, m.m_kColumn3);
}

static __forceinline float zvalue(const hkVector4& v)
{
    return v.m_vComponents.m128_f32[2];
}
static __forceinline float scalarIdentity(float x)
{
    return x;
}
extern "C" double __cdecl fabs(double);
struct S00de8910_Work_b10903
{
    hkVector4 invDetVec;
    hkMatrix4 adj;
};

// @fnv 0x00de8910
// src: GUESS 0x00de8910 (confidence: low)
int hkMatrix4::UpdateState_00de8910(float epsilon)
{
    const hkVector4& column2 = m_kColumn2;
    const float& val2x = column2.m_vComponents.m128_f32[0];
    const float& val2y = column2.m_vComponents.m128_f32[1];
    const float& val2z = column2.m_vComponents.m128_f32[2];
    const float& val2w = column2.m_vComponents.m128_f32[3];

    float s0 =
        -((*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * m_kColumn1.m_vComponents.m128_f32[0]) +
        m_kColumn0.m_vComponents.m128_f32[0] * m_kColumn1.m_vComponents.m128_f32[1];
    float s1 = -((*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * val2x) +
               (*(const volatile float*)&val2y) * m_kColumn0.m_vComponents.m128_f32[0];
    float s2 =
        -((*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * m_kColumn3.m_vComponents.m128_f32[0]) +
        m_kColumn0.m_vComponents.m128_f32[0] * m_kColumn3.m_vComponents.m128_f32[1];
    float s3 = -(val2x * m_kColumn1.m_vComponents.m128_f32[1]) + val2y * m_kColumn1.m_vComponents.m128_f32[0];
    float s4 = -(m_kColumn3.m_vComponents.m128_f32[0] * m_kColumn1.m_vComponents.m128_f32[1]) +
               m_kColumn3.m_vComponents.m128_f32[1] * m_kColumn1.m_vComponents.m128_f32[0];
    float s5 = -(m_kColumn3.m_vComponents.m128_f32[0] * val2y) + val2x * m_kColumn3.m_vComponents.m128_f32[1];

    float c0 = -(m_kColumn1.m_vComponents.m128_f32[2] * m_kColumn0.m_vComponents.m128_f32[3]) +
               m_kColumn1.m_vComponents.m128_f32[3] * m_kColumn0.m_vComponents.m128_f32[2];
    float c1 = val2w * m_kColumn0.m_vComponents.m128_f32[2] -
               (*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[3]) * (float)(+val2z);
    float c2 = -(m_kColumn3.m_vComponents.m128_f32[2] * m_kColumn0.m_vComponents.m128_f32[3]) +
               m_kColumn3.m_vComponents.m128_f32[3] * m_kColumn0.m_vComponents.m128_f32[2];
    float c3 = -((*(const volatile float*)&m_kColumn1.m_vComponents.m128_f32[3]) * (*(const volatile float*)&val2z)) +
               val2w * m_kColumn1.m_vComponents.m128_f32[2];
    float c4 = -(m_kColumn3.m_vComponents.m128_f32[2] * m_kColumn1.m_vComponents.m128_f32[3]) +
               (*(const volatile float*)&m_kColumn3.m_vComponents.m128_f32[3]) * m_kColumn1.m_vComponents.m128_f32[2];
    float c5 = -(m_kColumn3.m_vComponents.m128_f32[2] * (*(const volatile float*)&val2w)) +
               (*(const volatile float*)&m_kColumn3.m_vComponents.m128_f32[3]) * (float)(double)val2z;

    S00de8910_Work_b10903 w;
    float det = (float)(s0)*c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
    float invDet = 1.0f / det;

    *(__m128*)&w.invDetVec = _mm_load_ss(&invDet);
    if ((float)fabs(det) <= epsilon)
    {
        return 1;
    }

    w.adj.m_kColumn0.x = m_kColumn1.m_vComponents.m128_f32[1] * c5 - scalarIdentity(val2y) * c4 +
                         m_kColumn3.m_vComponents.m128_f32[1] * c3;
    w.adj.m_kColumn0.y = -(*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * c5 + val2y * c2 -
                         m_kColumn3.m_vComponents.m128_f32[1] * c1;
    w.adj.m_kColumn0.z = -m_kColumn1.m_vComponents.m128_f32[1] * c2 +
                         (*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * c4 +
                         m_kColumn3.m_vComponents.m128_f32[1] * scalarIdentity(c0);
    w.adj.m_kColumn0.w = m_kColumn1.m_vComponents.m128_f32[1] * c1 -
                         (*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * c3 - val2y * c0;

    w.adj.m_kColumn1.x =
        -m_kColumn1.m_vComponents.m128_f32[0] * c5 + val2x * c4 - m_kColumn3.m_vComponents.m128_f32[0] * c3;
    w.adj.m_kColumn1.y =
        m_kColumn0.m_vComponents.m128_f32[0] * c5 - val2x * c2 + m_kColumn3.m_vComponents.m128_f32[0] * c1;
    w.adj.m_kColumn1.z = -m_kColumn0.m_vComponents.m128_f32[0] * c4 + m_kColumn1.m_vComponents.m128_f32[0] * c2 -
                         m_kColumn3.m_vComponents.m128_f32[0] * c0;
    w.adj.m_kColumn1.w =
        m_kColumn0.m_vComponents.m128_f32[0] * c3 - m_kColumn1.m_vComponents.m128_f32[0] * c1 + val2x * c0;

    w.adj.m_kColumn2.x =
        m_kColumn1.m_vComponents.m128_f32[3] * s5 - val2w * s4 + m_kColumn3.m_vComponents.m128_f32[3] * s3;
    w.adj.m_kColumn2.y =
        -m_kColumn0.m_vComponents.m128_f32[3] * s5 + val2w * s2 - (float)(m_kColumn3.m_vComponents.m128_f32[3]) * s1;
    w.adj.m_kColumn2.z = m_kColumn0.m_vComponents.m128_f32[3] * s4 - m_kColumn1.m_vComponents.m128_f32[3] * s2 +
                         m_kColumn3.m_vComponents.m128_f32[3] * s0;
    w.adj.m_kColumn2.w =
        -m_kColumn0.m_vComponents.m128_f32[3] * s3 + m_kColumn1.m_vComponents.m128_f32[3] * s1 - val2w * s0;

    w.adj.m_kColumn3.x = -m_kColumn1.m_vComponents.m128_f32[2] * s5 + zvalue(m_kColumn2) * s4 -
                         m_kColumn3.m_vComponents.m128_f32[2] * s3;
    w.adj.m_kColumn3.y = m_kColumn0.m_vComponents.m128_f32[2] * s5 - *(&m_kColumn2.m_vComponents.m128_f32[2]) * s2 +
                         m_kColumn3.m_vComponents.m128_f32[2] * s1;
    w.adj.m_kColumn3.z = -m_kColumn0.m_vComponents.m128_f32[2] * s4 + m_kColumn1.m_vComponents.m128_f32[2] * s2 -
                         m_kColumn3.m_vComponents.m128_f32[2] * s0;
    w.adj.m_kColumn3.w =
        m_kColumn0.m_vComponents.m128_f32[2] * s3 - m_kColumn1.m_vComponents.m128_f32[2] * s1 + (float)(+val2z) * s0;

    ProcessAndReturnValue_00de88a0(*(const hkSimdReal*)&w.invDetVec, w.adj);
    return 0;
}
