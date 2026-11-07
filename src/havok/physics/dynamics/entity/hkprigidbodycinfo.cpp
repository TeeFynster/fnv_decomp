
// src/havok/physics/dynamics/entity/hkprigidbodycinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/hkprigidbodycinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
extern const __m128 identityRotation;
struct Owner
{
    int unk00, unk04, unk08;
    volatile unsigned char active, unk0d;
    volatile unsigned short mask;
    __m128 position, rotation, velocity, angularVelocity;
    __m128 axisX, axisY, axisZ, translation;
    volatile float mass, drag, tolerance, friction, restitution, damping, maxSpeed, maxAngularSpeed, limit;
    volatile unsigned char enabled, awake, mode, group, flag0, flag1, flag2, flag3;
    Owner* InitializePhysicsFields();
};
// Resets position, rotation, velocity, and axes to defaults, sets physical properties, flags, and returns this.
// @fnv 0x00cf5ea0
// src: GUESS 0x00cf5ea0 (confidence: medium)
Owner* Owner::InitializePhysicsFields()
{
    _mm_store_ps(reinterpret_cast<float*>(&position), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&rotation), identityRotation);
    _mm_store_ps(reinterpret_cast<float*>(&velocity), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&angularVelocity), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&axisX), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&axisY), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&axisZ), _mm_setzero_ps());
    axisX.m128_f32[0] = 1.0f;
    axisY.m128_f32[1] = 1.0f;
    axisZ.m128_f32[2] = 1.0f;
    enabled = 1;
    mass = 1.0f;
    _mm_store_ps(reinterpret_cast<float*>(&translation), _mm_setzero_ps());
    drag = 0.0f;
    tolerance = 0.05f;
    friction = 1.0f;
    restitution = 0.5f;
    damping = 0.4f;
    maxSpeed = 200.0f;
    maxAngularSpeed = 200.0f;
    limit = -1.0f;
    awake = 1;
    active = 1;
    mask = 0xffff;
    mode = 2;
    group = 0xff;
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    flag0 = 0;
    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
    return this;
}

struct S_00cf5f80_Vec
{
    __m128 m_vComponents;
};

struct S_00cf5f80_In
{
    int unk0;
    float m_f4;
    int unk8;
    int unkc;
    S_00cf5f80_Vec m_vTranslation;
    S_00cf5f80_Vec m_kColumn0;
    S_00cf5f80_Vec m_kColumn1;
    S_00cf5f80_Vec m_kColumn2;
};

struct S_00cf5f80
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    S_00cf5f80_Vec m_kColumn0;
    S_00cf5f80_Vec m_kColumn1;
    S_00cf5f80_Vec m_kColumn2;
    S_00cf5f80_Vec m_vTranslation;
    float m_f90;
    void CopyTransformFields(const S_00cf5f80_In* in);
};

// Copies m_f4, the three columns and the translation from in into this object.
// @fnv 0x00cf5f80
// src: GUESS 0x00cf5f80 (confidence: medium)
void S_00cf5f80::CopyTransformFields(const S_00cf5f80_In* in)
{
    m_f90 = in->m_f4;
    m_kColumn0.m_vComponents = in->m_kColumn0.m_vComponents;
    m_kColumn1.m_vComponents = in->m_kColumn1.m_vComponents;
    m_kColumn2.m_vComponents = in->m_kColumn2.m_vComponents;
    m_vTranslation.m_vComponents = in->m_vTranslation.m_vComponents;
}

struct S_00cf5fc0_Vec
{
    float x, y, z, w;
};
struct S_00cf5fc0_Src
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
    __declspec(align(16)) S_00cf5fc0_Vec unk30;
};
struct S_00cf5fc0_Sub
{
    void FUN_00cb26e0(const S_00cf5fc0_Src* p);
};
struct S_00cf5fc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __declspec(align(16)) S_00cf5fc0_Vec unk10;
    S_00cf5fc0_Sub unk20;
    void UpdateFields_00cf5fc0(const S_00cf5fc0_Src* p);
};
// Copies the 16-byte vector from p->unk30 into unk10 and calls unk20.FUN_00cb26e0 with p.
// @fnv 0x00cf5fc0
// src: GUESS 0x00cf5fc0 (confidence: low)
void S_00cf5fc0::UpdateFields_00cf5fc0(const S_00cf5fc0_Src* apSrc)
{
    reinterpret_cast<__m128&>(unk10) = reinterpret_cast<const __m128&>(apSrc->unk30);
    unk20.FUN_00cb26e0(apSrc);
}
