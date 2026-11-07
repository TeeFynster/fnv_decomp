#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/dynamics/constraint/atom/hkpconstraintatom_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/atom/hkpconstraintatom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Preserve this unit's intrinsic storage and aliasing model.
#define _INCLUDED_MM2
// Exe 0x00d21d10 FUN_00d21d10: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rcp_ps(LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, LocalM128);
#define FNV_VEC4_SIMD
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkVector4q.h"
#include "../../../../../../include/hkSimdRealq.h"
#include "../../../../../../include/hkpModifierConstraintAtom.h"
struct FUN_00d21ce0_cls
{
    void* m_base;
    void* m_pBridge;
    void* m_pConstraintData;
    void hkpBridgeConstraintAtom_init(void* data);
};
int __cdecl hkpModifierConstraintAtom_addAllModifierDataToConstraintInfo(void* pNode, void* a, void* b);
void __stdcall nullsub_31(int, int, int, int, int, int);
struct FUN_00d21de0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    FUN_00d21de0_cls* __thiscall hkpSimpleContactConstraintAtom_hkpSimpleContactConstraintAtom(int a);
};
#include "../../../../../../include/hkMatrix3.h"

struct hkpSimpleConstraintInfoInitInputq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3 m_kInverseInertiaMatrix;
    hkVector4q m_vInverseInertiaAndMass;
    const hkMatrix3* m_rotation;
};
class hkpMassChangerModifierConstraintAtomq
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4q m_kFactorA;
    hkVector4q m_kFactorB;

    void ScaleInverseInertia(const void* cp, hkpSimpleConstraintInfoInitInputq& inA, void* velA,
                             hkpSimpleConstraintInfoInitInputq& inB, void* velB);
};
// hkRotation layout (three Vec4 columns) of the motion transform and inverse inertia, over this unit's Vec4.
struct AtomRotation
{
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
};
// hkTransform layout (rotation + translation) over this unit's Vec4.
struct AtomTransform
{
    AtomRotation m_rotation;
    Vec4 m_vTranslation;
};
static __forceinline void SetRotatedDirection(Vec4& out, const AtomRotation& a, const Vec4& b)
{
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xAA);
    const LocalM128 r1 = _mm_mul_ps(b1, a.m_kColumn1.m_vComponents);
    const LocalM128 r0 = _mm_mul_ps(b0, a.m_kColumn0.m_vComponents);
    const LocalM128 r2 = _mm_mul_ps(b2, a.m_kColumn2.m_vComponents);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}
static __forceinline LocalM128 crossq(const LocalM128& v1, const LocalM128& v2)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xC9), _mm_shuffle_ps(v2, v2, 0xD2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xD2), _mm_shuffle_ps(v2, v2, 0xC9));
    return _mm_sub_ps(cross0, cross1);
}
struct InitInput
{
    Vec4 m_kFirstVector;
    AtomRotation m_kInverseInertiaMatrix;
    Vec4 m_vInverseInertiaAndMass;
    const AtomTransform* m_kMotionTransform;
};
struct BodyVelocity
{
    Vec4 m_kTranslationalVelocity;
    Vec4 m_kAngularVelocity;
};
struct ComChangerAtom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kDisplacementA;
    Vec4 m_kDisplacementB;

    void UpdateFields_00d22160(const void* cp, InitInput& inA, BodyVelocity& velA, InitInput& inB, BodyVelocity& velB);
};
extern LocalM128 DAT_012689a0;
extern LocalM128 DAT_012689b0;
extern LocalM128 DAT_012689c0;
extern LocalM128 DAT_012689d0;
void __stdcall SetGlobalVectors(int, int, const LocalM128* source1, int, const LocalM128* source2);
struct Cls_00d21fc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 m_uiValueCount;
    void __thiscall CopyData_00d21fc0(LocalM128* a, int b, int c, int d, int e, int out);
};

extern LocalM128 DAT_010ec7f0;
extern LocalM128 DAT_012689a0;
extern LocalM128 DAT_012689b0;
extern LocalM128 DAT_012689c0;
extern LocalM128 DAT_012689d0;
static inline LocalM128 Blend_d21d10(const LocalM128& v, const LocalM128& kRef, const float& t)
{
    LocalM128 s = _mm_load_ss(&t);
    s = _mm_shuffle_ps(s, s, 0);
    return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, s), kRef), _mm_mul_ps(v, s));
}
struct SoftContactVelocityBlend
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_fWeight;
    void UpdateState_00d21d10(int a1, int a2, int a3, LocalM128* pkA, int a5, LocalM128* pkB);
};
// @fnv 0x00d21d10
// src: GUESS 0x00d21d10 (confidence: low)
void SoftContactVelocityBlend::UpdateState_00d21d10(int a1, int a2, int a3, LocalM128* pkA, int a5, LocalM128* pkB)
{
    float t = m_fWeight;
    pkA[0] = Blend_d21d10(pkA[0], DAT_012689a0, t);
    pkA[1] = Blend_d21d10(pkA[1], DAT_012689b0, t);
    pkB[0] = Blend_d21d10(pkB[0], DAT_012689c0, t);
    pkB[1] = Blend_d21d10(pkB[1], DAT_012689d0, t);
}
