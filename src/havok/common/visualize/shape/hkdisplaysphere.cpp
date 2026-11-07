#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/common/visualize/shape/hkdisplaysphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkReferencedObject.h"

#include "../../../../../include/hkVector4.h"


inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

inline float& hkVector4::operator()(int i)
{
    return m_vComponents.m128_f32[i];
}

inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

extern float DAT_012683b0;

struct FUN_008cd6a0_Class
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        float* d = &m_kColumn0(0);
        d[0] = 1.0f;
        d[5] = 1.0f;
        d[10] = 1.0f;
        m_vTranslation.setZero4();
    }
    void hkRotation_set(void* p) throw();
};

// Preserve the inlined base construction used by this unit.


struct __declspec(align(16)) ShapeBase : hkReferencedObject
{
    int m_ulUserData;
    FUN_008cd6a0_Class m_kMotionTransform;
    int m_type;

    ShapeBase()
    {
        m_ulUserData = 0;
        m_type = 1;
        m_kMotionTransform.setIdentity();
    }
};

struct __declspec(align(16)) FUN_00e0af50 : ShapeBase
{
    hkVector4 m_vec;
    int m_kPointA;
    int m_kPointB;

    FUN_00e0af50(const hkVector4& v, int a, int b);
};

// @fnv 0x00e0af50
FUN_00e0af50::FUN_00e0af50(const hkVector4& aVec, int a, int b)
{
    m_vec.m_vComponents.m128_i32[0] = aVec.m_vComponents.m128_i32[0];
    m_vec.m_vComponents.m128_i32[1] = aVec.m_vComponents.m128_i32[1];
    m_vec.m_vComponents.m128_i32[2] = aVec.m_vComponents.m128_i32[2];
    m_vec.m_vComponents.m128_i32[3] = aVec.m_vComponents.m128_i32[3];
    m_kPointA = a;
    m_kPointB = b;
    FUN_008cd6a0_Class& t = m_kMotionTransform;
    t.hkRotation_set(&DAT_012683b0);
    t.m_vTranslation = aVec;
}

// @fnv 0x00e0af40
// src: COMMUNITY 0x00e0af40
void __stdcall nullsub_91(int a, int b)
{}
