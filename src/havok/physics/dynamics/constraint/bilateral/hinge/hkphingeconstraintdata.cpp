
// src/havok/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkpConstraintData.h"

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

// No approved include/hkpHingeConstraintData.h exists yet; retain the reflected 0xB0 layout locally.
class hkpHingeConstraintData : public hkpConstraintData
{
public:
    char padC[4];
    char m_kBridgeAtoms[0xA0];

    void setMaxLinearImpulse(float value);
    float getMaxLinearImpulse();
    void setBodyToNotify(int index);
    unsigned int getNotifiedBodyIndex();
    void* __thiscall getConstraintInfo(int param);
    void SetLocalTransforms(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                            const hkVector4& pivot, const hkVector4& axis);
    void SetConstraintPivotFrames(const hkVector4& pivotA, const hkVector4& pivotB,
                     const hkVector4& axisA, const hkVector4& axisB);
    hkBool hkpPointToPlaneConstraintData_isValid() const;
};

// @fnv 0x00cbe1b0
// src: HAVOK_LIB 0x00cbe1b0
void hkpHingeConstraintData::setBodyToNotify(int index)
{
    reinterpret_cast<unsigned char*>(this)[0xa6] = (unsigned char)(1 << index);
}

extern "C" void* __cdecl hkpConstraintData_getConstraintInfoUtil(void* thisPtr, int size, int param);

// @fnv 0x00cbe210
// src: HAVOK_LIB 0x00cbe210
void* __thiscall hkpHingeConstraintData::getConstraintInfo(int param)
{
    return hkpConstraintData_getConstraintInfoUtil((char*)this + 0x10, 0x9c, param);
}

// Writes 5 and 0x28 into target[1] and target[0] when param is nonzero, otherwise writes zeros.
// @fnv 0x00cbe1e0
void __stdcall SetTargetValues(char param, int* target)
{
    if (param)
    {
        target[1] = 5;
        target[0] = 0x28;
    }
    else
    {
        target[1] = 0;
        target[0] = 0;
    }
}

// @fnv 0x00cbe190
// src: HAVOK_LIB 0x00cbe190
void hkpHingeConstraintData::setMaxLinearImpulse(float value)
{
    *(float*)((char*)this + 0xa8) = value;
}

// @fnv 0x00cbe1a0
// src: XBOX_PDB 0x00cbe1a0
float hkpHingeConstraintData::getMaxLinearImpulse()
{
    return *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0xA8);
}

// Reads a flag byte at +0xA6 and returns it shifted right by one.

// @fnv 0x00cbe1d0
// src: HAVOK_LIB 0x00cbe1d0
unsigned int hkpHingeConstraintData::getNotifiedBodyIndex()
{
    return (unsigned int)reinterpret_cast<const unsigned char*>(this)[0xA6] >> 1;
}

// @fnv 0x00cbe230
// src: GUESS 0x00cbe230 (confidence: high)
int __cdecl hkpHingeConstraintData_ReturnOne()
{
    return 1;
}

// The old transform stand-in called hkRotation::IsOrthonormal (0x00CB2E70), as bound by other units.
// @fnv 0x00cbe750
// src: HAVOK_LIB 0x00cbe750
hkBool hkpHingeConstraintData::hkpPointToPlaneConstraintData_isValid() const
{
    const hkTransform& transformA = *reinterpret_cast<const hkTransform*>(m_kBridgeAtoms + 0x10);
    const hkTransform& transformB = *reinterpret_cast<const hkTransform*>(m_kBridgeAtoms + 0x50);
    return transformA.m_rotation.IsOrthonormal(0.001f) && transformB.m_rotation.IsOrthonormal(0.001f);
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00cbe240 {
// Exe 0x00cbe240 SetLocalTransforms: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
}

// local hkVector4q form for 0x00cbe240: built on this namespace's own __m128 union with inline const operator(); the shared hkVector4q uses the real __m128 and declares const operator() out of line
union hkVector4qView_00cbe240
{
    LocalM128 m_vComponents;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }

    void hkVector4_setRotatedInverseDir(const hkRotation& r, const hkVector4qView_00cbe240& v);
    void hkVector4_setTransformedInversePos(const hkTransform& t, const hkVector4& v);
};

struct hkpSetLocalTransformsAtom
{
    hkUint16 m_type;
    hkUint16 unk02;
    hkUint32 unk04;
    hkUint32 unk08;
    hkUint32 unk0C;
    hkVector4qView_00cbe240 m_kRotationA[3];
    hkVector4qView_00cbe240 m_kTranslationA;
    hkVector4qView_00cbe240 m_kRotationB[3];
    hkVector4qView_00cbe240 m_kTranslationB;
};

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkNormalize3(hkVector4qView_00cbe240& v)
{
    LocalM128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4qView_00cbe240& in, hkVector4qView_00cbe240& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetCross(hkVector4qView_00cbe240& out, const hkVector4qView_00cbe240& v0, const hkVector4qView_00cbe240& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

}  // namespace fnv_00cbe240

// Builds a perpendicular basis from axis, then writes each body's rotation and translation (pivot) into m_kBridgeAtoms via FUN_004b4ab0 and FUN_00c7f690.
// @fnv 0x00cbe240
void hkpHingeConstraintData::SetLocalTransforms(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                                  const hkVector4& pivot, const hkVector4& axis)
{
    using namespace fnv_00cbe240;
    hkpSetLocalTransformsAtom& t = *reinterpret_cast<hkpSetLocalTransformsAtom*>(&m_kBridgeAtoms);
    const hkVector4qView_00cbe240& axle = reinterpret_cast<const hkVector4qView_00cbe240&>(axis);

    hkVector4qView_00cbe240 perpToAxle1;
    hkVector4qView_00cbe240 perpToAxle2;
    hkCalculatePerpendicularVector(axle, perpToAxle1);
    hkNormalize3(perpToAxle1);
    hkSetCross(perpToAxle2, axle, perpToAxle1);

    t.m_kRotationA[0].hkVector4_setRotatedInverseDir(bodyATransform.m_rotation, axle);
    t.m_kRotationA[1].hkVector4_setRotatedInverseDir(bodyATransform.m_rotation, perpToAxle1);
    t.m_kRotationA[2].hkVector4_setRotatedInverseDir(bodyATransform.m_rotation, perpToAxle2);
    t.m_kTranslationA.hkVector4_setTransformedInversePos(bodyATransform, pivot);

    t.m_kRotationB[0].hkVector4_setRotatedInverseDir(bodyBTransform.m_rotation, axle);
    t.m_kRotationB[1].hkVector4_setRotatedInverseDir(bodyBTransform.m_rotation, perpToAxle1);
    t.m_kRotationB[2].hkVector4_setRotatedInverseDir(bodyBTransform.m_rotation, perpToAxle2);
    t.m_kTranslationB.hkVector4_setTransformedInversePos(bodyBTransform, pivot);
}


namespace fnv_00cbe400 {
// Exe 0x00cbe240 SetLocalTransforms: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
}

// local hkVector4q form for 0x00cbe400: built on this namespace's own __m128 union with inline const operator(); the shared hkVector4q uses the real __m128 and declares const operator() out of line
union hkVector4qView_00cbe400
{
    LocalM128 m_vComponents;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

struct hkMatrix3q
{
    hkVector4qView_00cbe400 m_col[3];
};

struct hkpHingeTransforms
{
    char pad0[0x10];
    hkMatrix3q m_kRotationA;
    hkVector4qView_00cbe400 m_kTranslationA;
    hkMatrix3q m_kRotationB;
    hkVector4qView_00cbe400 m_kTranslationB;
};

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkNormalize3(hkVector4qView_00cbe400& v)
{
    LocalM128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4qView_00cbe400& in, hkVector4qView_00cbe400& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetCross(hkVector4qView_00cbe400& out, const hkVector4qView_00cbe400& v0, const hkVector4qView_00cbe400& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

}  // namespace fnv_00cbe400

// Stores pivotA and pivotB as translations, and builds rotation matrices for A and B from axisA and axisB using hkCalculatePerpendicularVector and hkSetCross.
// @fnv 0x00cbe400
// src: GUESS 0x00cbe400 (confidence: medium)
void hkpHingeConstraintData::SetConstraintPivotFrames(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axisA,
                                            const hkVector4& axisB)
{
    using namespace fnv_00cbe400;
    hkpHingeTransforms& t = *reinterpret_cast<hkpHingeTransforms*>(&m_kBridgeAtoms);

    t.m_kTranslationA.m_vComponents = reinterpret_cast<const hkVector4qView_00cbe400&>(pivotA).m_vComponents;
    t.m_kTranslationB.m_vComponents = reinterpret_cast<const hkVector4qView_00cbe400&>(pivotB).m_vComponents;

    hkVector4qView_00cbe400& axleA = t.m_kRotationA.m_col[0];
    axleA.m_vComponents = reinterpret_cast<const hkVector4qView_00cbe400&>(axisA).m_vComponents;
    hkNormalize3(axleA);
    hkCalculatePerpendicularVector(axleA, t.m_kRotationA.m_col[1]);
    hkNormalize3(t.m_kRotationA.m_col[1]);
    hkSetCross(t.m_kRotationA.m_col[2], axleA, t.m_kRotationA.m_col[1]);

    hkVector4qView_00cbe400& axleB = t.m_kRotationB.m_col[0];
    axleB.m_vComponents = reinterpret_cast<const hkVector4qView_00cbe400&>(axisB).m_vComponents;
    hkNormalize3(axleB);
    hkCalculatePerpendicularVector(axleB, t.m_kRotationB.m_col[1]);
    hkNormalize3(t.m_kRotationB.m_col[1]);
    hkSetCross(t.m_kRotationB.m_col[2], axleB, t.m_kRotationB.m_col[1]);
}

