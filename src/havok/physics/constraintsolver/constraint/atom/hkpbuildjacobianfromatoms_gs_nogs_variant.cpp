
// src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/atom/hkpbuildjacobianfromatoms.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// The .rdata double added to the first matrix element (0.25) lives in the
// original image, so it is only declared here.
extern const double DAT_010c9300;
// arg1: the six float vector
struct FUN_00d6ce70_Vector
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
};
// arg2: the scale struct, the two floats at +4 and +8 are read
struct FUN_00d6ce70_Scale
{
    float unk00;
    float f04;
    float f08;
};
// arg3: the destination struct, the product is stored at +0x1c
struct FUN_00d6ce70_Dest
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float f1c;
};
// the 0x40 byte matrix block the cursor walks over
struct FUN_00d6ce70_Matrix
{
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;
};
// arg4: the cursor pointing at the next matrix block
struct FUN_00d6ce70_Cursor
{
    FUN_00d6ce70_Matrix* matrix;
};
void Hkpbuildjacobianfromatoms_UpdateState_00d6ce70(FUN_00d6ce70_Vector* v, FUN_00d6ce70_Scale* s, FUN_00d6ce70_Dest* dest, FUN_00d6ce70_Cursor* cursor);
struct WriterContext
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
};
struct WriterArgs
{
    unsigned int value_bits;
    unsigned char flag;
};
struct WriterRecord
{
    unsigned char type;
    unsigned char flag;
    unsigned short unk02;
    unsigned short low;
    unsigned short high;
    unsigned int value;
    unsigned int whole;
};
extern double _DAT_010c9300;
static void WriteFloatRecord(WriterContext* object, float** cursor, WriterArgs args);
void RecordWrite_use(WriterContext* object, float** cursor, WriterArgs args);

#include <xmmintrin.h>
extern const __m128 DAT_010c44d0;

struct S_00d6cb30_Vector4
{
    __m128 m_vComponents;
    void setNeg4(const S_00d6cb30_Vector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
};

#include "../../../../../../include/hkRotation.h"


inline void S_00d6cb30_setRotatedDir(S_00d6cb30_Vector4& out, const hkRotation& m, const S_00d6cb30_Vector4& v)
{
    const __m128 b = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(b, m.m_kColumn1.m_vComponents);
    const __m128 c = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(c, m.m_kColumn0.m_vComponents);
    const __m128 a = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(a, m.m_kColumn2.m_vComponents);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}

struct S_00d6cb30_Accumulator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00d6cb30_Vector4 m_vInverseInertiaAndMass;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    hkRotation m_coreFromWorldMatrix;
};

struct S_00d6cb30_Jacobian
{
    S_00d6cb30_Vector4 m_kAngularVelocity[2];
    float unk20;
    float unk24;
    float unk28;
    int unk2C;
};

struct S_00d6cb30_Info
{
    S_00d6cb30_Vector4 m_kAxisEndPoints;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
};

struct S_00d6cb30_QueryIn
{
    int unk00;
    int unk04;
    float unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    const S_00d6cb30_Accumulator* m_pBodyA;
    const S_00d6cb30_Accumulator* m_pBodyB;
};

struct S_00d6cb30_QueryOut
{
    S_00d6cb30_Jacobian* m_pQueryResultSchema;
};

__forceinline float BuildAngular431(const S_00d6cb30_Info* info, const S_00d6cb30_QueryIn* in, S_00d6cb30_Jacobian* jac)
{
    S_00d6cb30_Vector4 negAxis;
    negAxis.setNeg4(info->m_kAxisEndPoints);
    const S_00d6cb30_Accumulator* bodyB = in->m_pBodyB;
    const S_00d6cb30_Accumulator* bodyA = in->m_pBodyA;

    S_00d6cb30_setRotatedDir(jac->m_kAngularVelocity[0], bodyA->m_coreFromWorldMatrix, info->m_kAxisEndPoints);
    S_00d6cb30_setRotatedDir(jac->m_kAngularVelocity[1], bodyB->m_coreFromWorldMatrix, negAxis);

    __m128 a0 =
        _mm_mul_ps(_mm_mul_ps(jac->m_kAngularVelocity[0].m_vComponents, jac->m_kAngularVelocity[0].m_vComponents),
                   bodyA->m_vInverseInertiaAndMass.m_vComponents);
    __m128 a1 =
        _mm_mul_ps(_mm_mul_ps(jac->m_kAngularVelocity[1].m_vComponents, jac->m_kAngularVelocity[1].m_vComponents),
                   bodyB->m_vInverseInertiaAndMass.m_vComponents);
    __m128 s = _mm_add_ps(a0, a1);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(s, s, 0xaa), _mm_add_ss(_mm_shuffle_ps(s, s, 0x55), s));
    float diag;
    _mm_store_ss(&diag, sum);
    diag = diag + 1.1920928955078125e-07;
    return diag;
}
// @fnv 0x00d6cb30
// src: GUESS 0x00d6cb30 (confidence: low)
void __cdecl HkpbuildjacobianfromatomsGsNogs_UpdateState_00d6cb30(const S_00d6cb30_Info* info, const S_00d6cb30_QueryIn* in, S_00d6cb30_QueryOut* out)
{
    float x = info->unk1C;
    S_00d6cb30_Jacobian* jac = out->m_pQueryResultSchema;
    float diag = BuildAngular431(info, in, jac);
    jac->m_kAngularVelocity[0].m_vComponents.m128_f32[3] = x / diag;

    float n = -in->unk08;
    float a = info->unk10;
    float b = info->unk14;
    jac->m_kAngularVelocity[1].m_vComponents.m128_f32[3] = info->unk18 * n;
    S_00d6cb30_Jacobian* j = out->m_pQueryResultSchema;
    out->m_pQueryResultSchema = j + 1;
    j->unk20 = a * n * x;
    j->unk24 = b * n * x;
    j->unk28 = x;
    j->m_kAngularVelocity[0].m_vComponents.m128_f32[0] += 1.1920928955078125e-07;
    *(unsigned char*)j = 0xd;
}
