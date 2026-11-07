
// src/havok/physics/constraintsolver/constraint/motor/hkpmotorbuildjacobian.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/motor/hkpmotorbuildjacobian.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct VectorA
{
    float x;
    float y;
    float z;
    float w;
    float v4;
    float v5;
};
struct VectorB
{
    float unk00;
    float y;
    float z;
};
struct Result
{
    float unk00;
    float unk04;
    float unk08;
    float value;
};
struct Buffer
{
    float* cursor;
};
// Computes a->x*b->z into out->value, advances buffer->cursor by 0x50, and writes scaled and copied components of a into the cursor's preceding slots.
// @fnv 0x00dd03c0
// src: HAVOK_LIB 0x00dd03c0
void __cdecl _hk1dLinearVelocityMotorCommitJacobian(VectorA* pVectorA, VectorB* pVectorB, Result* pResult, Buffer* buffer)
{
    pResult->value = pVectorA->x * pVectorB->z;
    float* cursor = buffer->cursor;
    *cursor += 0.00000011920928955078125;
    *(unsigned char*)cursor = 10;
    cursor = (float*)((char*)cursor + 0x50);
    buffer->cursor = cursor;
    cursor[-8] = pVectorA->z * pVectorB->y;
    cursor[-7] = pVectorA->w * pVectorB->y;
    cursor[-6] = pVectorA->y;
    cursor[-5] = pVectorA->v4;
    cursor[-4] = pVectorA->v5;
}

#include <xmmintrin.h>
struct __declspec(align(16)) S_00dd0260_Vector4
{
    float x;
    float y;
    float z;
    float w;

    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }

    void operator=(const S_00dd0260_Vector4& v)
    {
        q() = v.q();
    }
    float& operator()(int i)
    {
        return (&x)[i];
    }

    void setSub4(const S_00dd0260_Vector4& a, const S_00dd0260_Vector4& b)
    {
        q() = _mm_sub_ps(a.q(), b.q());
    }
    void setAdd4(const S_00dd0260_Vector4& a, const S_00dd0260_Vector4& b)
    {
        q() = _mm_add_ps(a.q(), b.q());
    }
    void setMul4(const S_00dd0260_Vector4& a, const S_00dd0260_Vector4& b)
    {
        q() = _mm_mul_ps(a.q(), b.q());
    }
    void mul4(const S_00dd0260_Vector4& a)
    {
        q() = _mm_mul_ps(q(), a.q());
    }
    void add4(const S_00dd0260_Vector4& a)
    {
        q() = _mm_add_ps(q(), a.q());
    }
    void setCross(const S_00dd0260_Vector4& v1, const S_00dd0260_Vector4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.q(), v1.q(), _MM_SHUFFLE(3, 0, 2, 1)),
                                         _mm_shuffle_ps(v2.q(), v2.q(), _MM_SHUFFLE(3, 1, 0, 2)));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.q(), v1.q(), _MM_SHUFFLE(3, 1, 0, 2)),
                                         _mm_shuffle_ps(v2.q(), v2.q(), _MM_SHUFFLE(3, 0, 2, 1)));
        q() = _mm_sub_ps(cross0, cross1);
    }
    void setXYZ_W(const S_00dd0260_Vector4& xyz, const S_00dd0260_Vector4& ww)
    {
        q() = _mm_shuffle_ps(xyz.q(), _mm_unpackhi_ps(xyz.q(), ww.q()), _MM_SHUFFLE(3, 0, 1, 0));
    }
    __forceinline float horizontalAdd4() const
    {
        const __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(q(), q(), _MM_SHUFFLE(1, 0, 3, 2)), q());
        const __m128 sum1 = _mm_shuffle_ps(sum0, sum0, _MM_SHUFFLE(2, 3, 0, 1));
        // volatile: keeps the out-pointer load after the x87 reload, as in the original
        volatile float r;
        _mm_store_ss((float*)&r, _mm_add_ps(sum0, sum1));
        return r;
    }
};

// local form of hkMatrix3: 0x00dd0260 needs inline column q accessors; shared form gives 305 bytes vs exe 338.
struct S_00dd0260_Matrix3
{
    S_00dd0260_Vector4 m_kColumn0;
    S_00dd0260_Vector4 m_kColumn1;
    S_00dd0260_Vector4 m_kColumn2;
};

static inline void S_00dd0260_setRotatedDir(S_00dd0260_Vector4& out, const S_00dd0260_Matrix3& a,
                                            const S_00dd0260_Vector4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.q(), b.q(), _MM_SHUFFLE(0, 0, 0, 0));
    const __m128 r0 = _mm_mul_ps(a.m_kColumn0.q(), b0);
    const __m128 b1 = _mm_shuffle_ps(b.q(), b.q(), _MM_SHUFFLE(1, 1, 1, 1));
    const __m128 r1 = _mm_mul_ps(a.m_kColumn1.q(), b1);
    const __m128 b2 = _mm_shuffle_ps(b.q(), b.q(), _MM_SHUFFLE(2, 2, 2, 2));
    const __m128 r2 = _mm_mul_ps(a.m_kColumn2.q(), b2);
    out.q() = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct S_00dd0260_Accumulator
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
    S_00dd0260_Vector4 m_vInverseInertiaAndMass;
    S_00dd0260_Vector4 m_kCenterOfMass1;
    S_00dd0260_Matrix3 m_kInverseInertiaMatrix;
};

struct S_00dd0260_QueryIn
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
    const S_00dd0260_Accumulator* m_pBodyA;
    const S_00dd0260_Accumulator* m_pBodyB;
};

struct S_00dd0260_Jacobian
{
    S_00dd0260_Vector4 m_kLinearJacobian;
    S_00dd0260_Vector4 m_kAngularVelocity[2];

    __forceinline float getDiag(const S_00dd0260_Accumulator& mA, const S_00dd0260_Accumulator& mB) const
    {
        S_00dd0260_Vector4 mass01;
        mass01.setAdd4(mA.m_vInverseInertiaAndMass, mB.m_vInverseInertiaAndMass);
        S_00dd0260_Vector4 dia;
        dia.setMul4(m_kAngularVelocity[0], m_kAngularVelocity[0]);
        S_00dd0260_Vector4 dib;
        dib.setMul4(m_kAngularVelocity[1], m_kAngularVelocity[1]);
        dia.mul4(mA.m_vInverseInertiaAndMass);
        dib.mul4(mB.m_vInverseInertiaAndMass);
        dia.add4(dib);
        dia.setXYZ_W(dia, mass01);
        return dia.horizontalAdd4();
    }
};

struct S_00dd0260_PadJac
{
    S_00dd0260_Jacobian* m_kStorage;
    S_00dd0260_Jacobian* val() const
    {
        return m_kStorage;
    }
};

struct S_00dd0260_PadSpu
{
    float* m_kStorage;
    float* val() const
    {
        return m_kStorage;
    }
};

static const double DAT_010c9300 = 1.1920928955078125e-07;

// Fills a Jacobian from dir and pos, computes its diagonal plus a small epsilon, stores the inverse in the Jacobian and writes it to invDiagOut.
// @fnv 0x00dd0260
void ComputeJacobian(const S_00dd0260_Vector4& dir, const S_00dd0260_Vector4& pos, const S_00dd0260_QueryIn& in,
                     S_00dd0260_PadJac pjac, S_00dd0260_PadSpu invDiagOut)
{
    const S_00dd0260_Accumulator* mA = in.m_pBodyA;
    const S_00dd0260_Accumulator* mB = in.m_pBodyB;

    S_00dd0260_Jacobian& jac = *pjac.val();
    jac.m_kLinearJacobian = dir;
    S_00dd0260_Vector4 r0;
    r0.setSub4(pos, mA->m_kCenterOfMass1);
    S_00dd0260_Vector4 r1;
    r1.setSub4(pos, mB->m_kCenterOfMass1);
    S_00dd0260_Vector4 vCrossA;
    vCrossA.setCross(r0, dir);
    S_00dd0260_Vector4 vCrossB;
    vCrossB.setCross(dir, r1);
    S_00dd0260_setRotatedDir(jac.m_kAngularVelocity[0], mA->m_kInverseInertiaMatrix, vCrossA);
    S_00dd0260_setRotatedDir(jac.m_kAngularVelocity[1], mB->m_kInverseInertiaMatrix, vCrossB);

    float diag = jac.getDiag(*mA, *mB) + DAT_010c9300;
    float* out = invDiagOut.val();
    jac.m_kAngularVelocity[1](3) = diag;
    float invDiag = 1.0f / diag;
    jac.m_kAngularVelocity[0](3) = invDiag;
    *out = invDiag;
}
