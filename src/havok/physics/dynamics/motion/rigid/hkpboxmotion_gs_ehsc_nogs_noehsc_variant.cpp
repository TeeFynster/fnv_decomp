#include <xmmintrin.h>

// src/havok/physics/dynamics/motion/rigid/hkpboxmotion_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/motion/rigid/hkpboxmotion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/motion/rigid/hkpboxmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpboxmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpBoxMotion.h"
struct FUN_00d1e670_StandIn
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4(float) = 0;

    void FUN_00d1e670(float);
};
typedef ::__m128 __m128;
extern "C" __m128 _mm_setzero_ps(void);
struct Cls_00d1e7b0
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float m_c0;
    float m_c4;
    float m_c8;
    void WriteDiagonal(float* pOut);
};

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct __declspec(align(16)) Vector4D1E850
{
    float x;
    float y;
    float z;
    float w;
    __m128& Vector4f()
    {
        return *reinterpret_cast<__m128*>(this);
    }
    const __m128& Vector4f() const
    {
        return *reinterpret_cast<const __m128*>(this);
    }
};
// local form of hkRotation: 0x00d1e850 needs implicit construction and original SIMD column access; shared form gives 123 bytes vs exe 109.
struct RotationD1E850
{
    Vector4D1E850 m_kColumn0;
    Vector4D1E850 m_kColumn1;
    Vector4D1E850 m_kColumn2;
};
struct PairOutD1E850
{
    void FUN_00cd5610(const RotationD1E850* pkRotation, const hkVector4* pkColumns);
};
struct ShapeD1E850 : hkpBoxMotion
{
    void hkpBoxMotion_getInertiaInvWorld(int pkOutRaw);
};

static const __m128& QuadD1E850(const hkVector4& value)
{
    return *reinterpret_cast<const __m128*>(&value);
}

// @fnv 0x00d1e850
// src: HAVOK_SRC 0x00d1e850
void ShapeD1E850::hkpBoxMotion_getInertiaInvWorld(int pkOutRaw)
{
    RotationD1E850 kScaled;
    kScaled.m_kColumn0.Vector4f() =
        _mm_mul_ps(_mm_shuffle_ps(QuadD1E850(m_kInertiaAndMassInv), QuadD1E850(m_kInertiaAndMassInv), 0x00),
                   QuadD1E850(m_kMotionState.m_kMotionTransform.m_rotation.m_kColumn0));
    kScaled.m_kColumn1.Vector4f() =
        _mm_mul_ps(_mm_shuffle_ps(QuadD1E850(m_kInertiaAndMassInv), QuadD1E850(m_kInertiaAndMassInv), 0x55),
                   QuadD1E850(m_kMotionState.m_kMotionTransform.m_rotation.m_kColumn1));
    kScaled.m_kColumn2.Vector4f() =
        _mm_mul_ps(_mm_shuffle_ps(QuadD1E850(m_kInertiaAndMassInv), QuadD1E850(m_kInertiaAndMassInv), 0xaa),
                   QuadD1E850(m_kMotionState.m_kMotionTransform.m_rotation.m_kColumn2));
    (reinterpret_cast<PairOutD1E850*>(*(volatile int*)&pkOutRaw))
        ->FUN_00cd5610(&kScaled, &m_kMotionState.m_kMotionTransform.m_rotation.m_kColumn0);
}
