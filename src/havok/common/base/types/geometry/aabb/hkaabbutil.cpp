#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/common/base/types/geometry/aabb/hkaabbutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/geometry/aabb/hkaabbutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00cbec90 FUN_00cbec90: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_and_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_load_ps1(const float* p);

extern "C"
{
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_rsqrt_ss(LocalM128 a);
    LocalM128 _mm_cmpeq_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_andnot_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm8);
    LocalM128 _mm_set_ss(float a);
    LocalM128 _mm_set_ps1(float a);
}

// This unit supplies its original SSE intrinsic declarations above.
#define _INCLUDED_MM2
#include "../../../../../../../include/hkVector4q.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkTransform.h"


extern const LocalM128 DAT_01017d10;
extern const LocalM128 DAT_010c44d0;


__forceinline void setAbs4(hkVector4q& result, const hkVector4q& v)
{
    result.m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10);
}

__forceinline void hkVector4q::setNeg4(const hkVector4q& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}

__forceinline void hkVector4q::add4(const hkVector4q& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4q::setAdd4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void setTransformedPos(hkVector4q& result, const hkTransform& t, const hkVector4q& b)
{
    const LocalM128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), t.m_kColumn0);
    const LocalM128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), t.m_kColumn1);
    const LocalM128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), t.m_kColumn2);
    result.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation));
}

// Transforms a local-space AABB (center, halfExtents, extraRadius) into world space via localToWorld and writes the result to aabbOut.
// @fnv 0x00d26230
// src: XBOX_PDB 0x00d26230
void __cdecl hkAabbUtil_calcAabb_00d26230(const hkTransform& localToWorld, const hkVector4q& halfExtents,
                          const hkVector4q& center, float extraRadius, hkAabb& aabbOut)
{
    hkVector4q vHeX;
    vHeX.m_vComponents = _mm_shuffle_ps(halfExtents.m_vComponents, halfExtents.m_vComponents, 0x00);
    hkVector4q vHeY;
    vHeY.m_vComponents = _mm_shuffle_ps(halfExtents.m_vComponents, halfExtents.m_vComponents, 0x55);
    hkVector4q vHeZ;
    vHeZ.m_vComponents = _mm_shuffle_ps(halfExtents.m_vComponents, halfExtents.m_vComponents, 0xaa);

    hkVector4q transformedX;
    transformedX.m_vComponents = _mm_mul_ps(vHeX.m_vComponents, localToWorld.m_kColumn0);
    hkVector4q transformedY;
    transformedY.m_vComponents = _mm_mul_ps(vHeY.m_vComponents, localToWorld.m_kColumn1);
    hkVector4q transformedZ;
    transformedZ.m_vComponents = _mm_mul_ps(vHeZ.m_vComponents, localToWorld.m_kColumn2);

    setAbs4(transformedX, transformedX);
    setAbs4(transformedY, transformedY);
    setAbs4(transformedZ, transformedZ);

    hkVector4q extra;
    extra.m_vComponents = _mm_load_ps1(&extraRadius);
    transformedZ.add4(extra);

    hkVector4q max;
    max.setAdd4(transformedX, transformedY);
    max.add4(transformedZ);

    hkVector4q min;
    min.setNeg4(max);

    hkVector4q vCenter;
    setTransformedPos(vCenter, localToWorld, center);

    max.add4(vCenter);
    min.add4(vCenter);

    aabbOut.m_kMaximumCorner = max.m_vec;
    aabbOut.m_kMinimumCorner = min.m_vec;
}

static const __declspec(align(16)) float g_quadOne[4] = {1.0f, 1.0f, 1.0f, 1.0f};

__forceinline void hkVector4q::setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t)
{
    const LocalM128 one = *(const LocalM128*)g_quadOne;
    const LocalM128 weight = t.m_vComponents;
    LocalM128 weighted = b.m_vComponents;
    weighted = _mm_mul_ps(weighted, weight);
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(one, weight), a.m_vComponents), weighted);
}

__forceinline const float& hkVector4q::operator()(int i) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[i];
}

struct hkQuaternionq
{
    hkVector4q m_vec;

    __forceinline void normalize()
    {
        LocalM128 dot = _mm_mul_ps(m_vec.m_vComponents, m_vec.m_vComponents);
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0x4e));
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0xb1));

        const LocalM128 e = _mm_rsqrt_ss(dot);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 half = _mm_set_ss(0.5f);

        const LocalM128 lenSqE2 = _mm_mul_ss(_mm_mul_ss(dot, e), e);
        const LocalM128 isZero = _mm_cmpeq_ss(dot, zero);
        const LocalM128 invLen = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, lenSqE2)));
        m_vec.m_vComponents = _mm_mul_ps(m_vec.m_vComponents, _mm_shuffle_ps(invLen, invLen, 0));
    }
    __forceinline void normalizeLoop()
    {
        LocalM128 dot = _mm_mul_ps(m_vec.m_vComponents, m_vec.m_vComponents);
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0x4e));
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0xb1));

        const LocalM128 e = _mm_rsqrt_ss(dot);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 half = _mm_set_ss(0.5f);

        const LocalM128 lenSqE2 = _mm_mul_ss(_mm_mul_ss(dot, e), e);
        const LocalM128 isZero = _mm_cmpeq_ss(dot, zero);
        const LocalM128 invLen = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, lenSqE2)));
        m_vec.m_vComponents = _mm_mul_ps(m_vec.m_vComponents, _mm_shuffle_ps(invLen, invLen, 0));
    }
};

// local form of hkRotation: 0x00cbec90 needs original inline rotation/transform copying; shared form gives 1278 bytes vs exe 1276.
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
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

// local form of hkSweptTransform: 0x00cbec90 needs the original inline sampling form; shared form gives 1278 bytes vs exe 1276.
class hkSweptTransformq
{
  public:
    hkVector4q m_vCenterOfMass0;
    hkVector4q m_vCenterOfMass1;
    hkQuaternionq m_qRotation0;
    hkQuaternionq m_qRotation1;
    hkVector4q m_vCenterOfMassLocal;

    __forceinline float getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    __forceinline float getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }

    __forceinline void EvaluateTransformAtTime(const float& time, hkTransformq& transformOut) const
    {
        float t = (time - m_vCenterOfMass0(3)) * m_vCenterOfMass1(3);
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
    __forceinline void approxTransformAtLoop(const float& time, hkTransformq& transformOut) const
    {
        float t = (time - m_vCenterOfMass0(3)) * m_vCenterOfMass1(3);
        hkVector4q t4;
        LocalM128 weight = _mm_set_ps1(t);

        hkQuaternionq q;
        LocalM128 left = _mm_sub_ps(*(const LocalM128*)g_quadOne, weight);
        left = _mm_mul_ps(left, m_qRotation0.m_vec.m_vComponents);
        t4.m_vComponents = weight;
        LocalM128 right = _mm_mul_ps(_mm_load_ps(t4.m_vComponents.m128_f32), m_qRotation1.m_vec.m_vComponents);
        q.m_vec.m_vComponents = _mm_add_ps(left, right);

        q.normalizeLoop();
        transformOut.m_rotation.hkRotation_set(q);

        transformOut.m_vTranslation.setInterpolate4(m_vCenterOfMass0, m_vCenterOfMass1, t4);
        hkVector4q centerShift;
        centerShift.SetRotatedDirection(transformOut.m_rotation, m_vCenterOfMassLocal);
        transformOut.m_vTranslation.sub4(centerShift);
    }
};

struct hkMotionStateq
{
    hkTransformq m_kMotionTransform;
    hkSweptTransformq m_kSweptTransform;
    hkVector4q m_kDeltaAngle;
};

struct SweptSampleInfo
{
    hkTransformq m_frame;
    void hkTransform_setInverse(const hkMotionStateq* motionState);
};

struct SweptTransformSamples
{
    const hkMotionStateq* m_kMotionState;
    int unk04;
    int unk08;
    int unk0C;
    hkTransformq m_kTransforms[4];
    int m_numQsTransforms;
    int unk114;
    int unk118;
    int unk11C;
    hkTransformq m_kMotionTransform;
    SweptSampleInfo m_info;
};

// Stores motionState and sample info in out, then evaluates swept transforms at times based on delta angle, filling m_kTransforms and m_numQsTransforms.
// @fnv 0x00cbec90
// src: GUESS 0x00cbec90 (confidence: medium)
void hkMotionStateq_SampleSweptMotionTransforms(const hkMotionStateq* motionState, SweptTransformSamples* out)
{
    out->m_kMotionState = motionState;
    out->m_info.hkTransform_setInverse(motionState);

    const hkSweptTransformq& swept = motionState->m_kSweptTransform;
    swept.EvaluateTransformAtTime(swept.m_vCenterOfMass0(3), out->m_kMotionTransform);

    if (swept.getInvDeltaTime() != 0.0f)
    {
        float deltaTime = 1.0f / swept.getInvDeltaTime();
        float angle = motionState->m_kDeltaAngle.m_vComponents.m128_f32[3];

        if (angle <= 0.39269909262657166)
        {
            out->m_kTransforms[0] = out->m_kMotionTransform;
            float fScale = 1.0f - angle * angle * 0.5;
            out->m_kTransforms[0].m_vTranslation(3) = 1.0f / fScale;
            out->m_numQsTransforms = 1;
        }
        else if (angle <= 0.78539818525314331)
        {
            float time = swept.getBaseTime() + deltaTime * 0.5;
            swept.EvaluateTransformAtTime(time, out->m_kTransforms[0]);
            float fScale = 1.0f - angle * angle * 0.25 * 0.5;
            out->m_kTransforms[0].m_vTranslation(3) = 1.0f / fScale;
            out->m_numQsTransforms = 1;
        }
        else
        {
            out->m_numQsTransforms = 0;
            float numSteps = (angle + 0.39269909262657166) / 0.39269909262657166;
            float invNumSteps = 1.0f / numSteps;
            for (float i = 1.0f; i < numSteps; i += 2.0)
            {
                float time = swept.getBaseTime() + i * invNumSteps * deltaTime;
                hkTransformq& t = out->m_kTransforms[out->m_numQsTransforms++];
                swept.approxTransformAtLoop(time, t);
                t.m_vTranslation(3) = 1.0824f;
            }
        }
    }
    else
    {
        out->m_numQsTransforms = 0;
    }
}
