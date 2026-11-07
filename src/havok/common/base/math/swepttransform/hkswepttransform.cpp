
// src/havok/common/base/math/swepttransform/hkswepttransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/swepttransform/hkswepttransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkVector4q.h"


static const __declspec(align(16)) float g_quadOne[4] = {1.0f, 1.0f, 1.0f, 1.0f};

__forceinline void hkVector4q::setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t)
{
    const __m128 one = *(const __m128*)g_quadOne;
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(one, t.m_vComponents), a.m_vComponents),
                               _mm_mul_ps(b.m_vComponents, t.m_vComponents));
}

struct hkQuaternionq
{
    hkVector4q m_vec;

    __forceinline void normalize()
    {
        __m128 dot = _mm_mul_ps(m_vec.m_vComponents, m_vec.m_vComponents);
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0x4e));
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0xb1));

        const __m128 e = _mm_rsqrt_ss(dot);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 half = _mm_set_ss(0.5f);

        const __m128 lenSqE2 = _mm_mul_ss(_mm_mul_ss(dot, e), e);
        const __m128 isZero = _mm_cmpeq_ss(dot, zero);
        const __m128 invLen = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, lenSqE2)));
        m_vec.m_vComponents = _mm_mul_ps(m_vec.m_vComponents, _mm_shuffle_ps(invLen, invLen, 0));
    }
};

// local form of hkRotation: 0x00cf22d0 needs inline column access and original SIMD aliases; shared rotation changes 26 exe bytes.
struct hkRotationq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    void hkRotation_set(const hkQuaternionq& q);
    __forceinline const hkVector4q& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
};

struct hkTransformq
{
    hkRotationq m_rotation;
    hkVector4q m_vTranslation;
};

__forceinline void hkVector4q::SetRotatedDirection(const hkRotationq& r, const hkVector4q& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

// local form of hkSweptTransform: 0x00cf22d0 needs the original inline q-vector interpolation form; canonical swept member does not reproduce exe bytes.
class hkSweptTransformq
{
  public:
    hkVector4q m_vCenterOfMass0;
    hkVector4q m_vCenterOfMass1;
    hkQuaternionq m_qRotation0;
    hkQuaternionq m_qRotation1;
    hkVector4q m_vCenterOfMassLocal;

    void Evaluate(float time, hkTransformq& transformOut) const;
};

// Interpolates rotation and translation between two swept states at the given time and writes the result into transformOut.
// @fnv 0x00cf22d0
void hkSweptTransformq::Evaluate(float time, hkTransformq& transformOut) const
{
    float t = (time - m_vCenterOfMass0.m_vComponents.m128_f32[3]) * m_vCenterOfMass1.m_vComponents.m128_f32[3];
    hkVector4q t4;
    t4.m_vComponents = _mm_set_ps1(t);

    hkQuaternionq q;
    q.m_vec.setInterpolate4(m_qRotation0.m_vec, m_qRotation1.m_vec, t4);
    q.normalize();
    transformOut.m_rotation.hkRotation_set(q);

    transformOut.m_vTranslation.setInterpolate4(m_vCenterOfMass0, m_vCenterOfMass1, t4);
    hkVector4q centerShift;
    centerShift.SetRotatedDirection(transformOut.m_rotation, m_vCenterOfMassLocal);
    transformOut.m_vTranslation.sub4(centerShift);
}

namespace fnv_00cf2410 {
// Exe 0x00cf2410 FUN_00cf2410: retain this LocalM128 view; the CRT type does not reproduce this function.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);
struct Swept_00cf2410_Sub
{
    void hkSweptTransform_initSweptTransform(LocalM128 const* a, LocalM128 const* b);
};
struct Swept_00cf2410_Cb
{
    void hkRotation_set(void* p);
};
struct Swept_00cf2410
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
    LocalM128 m_vContactPosition;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    LocalM128 m_vVector;
    float m_inverseTime;
    void hkMotionState_initMotionState(LocalM128 const& position, LocalM128 const& rotation);
};
// Passes position and rotation to one method, passes rotation to another, stores position, sets m_inverseTime to 1.0f, and zeroes m_vVector.
// @fnv 0x00cf2410
// src: XBOX_PDB 0x00cf2410
void Swept_00cf2410::hkMotionState_initMotionState(LocalM128 const& position, LocalM128 const& rotation)
{
    ((Swept_00cf2410_Sub*)((char*)this + 0x40))->hkSweptTransform_initSweptTransform(&position, &rotation);
    ((Swept_00cf2410_Cb*)this)->hkRotation_set(const_cast<LocalM128*>(&rotation));
    m_vContactPosition = position;
    m_inverseTime = 1.0f;
    m_vVector = _mm_setzero_ps();
}
}  // namespace fnv_00cf2410
