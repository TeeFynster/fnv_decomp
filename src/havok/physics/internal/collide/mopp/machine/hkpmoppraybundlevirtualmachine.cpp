// havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp: RayBundleCopy (2 functions)

#include "fnv_asm_helpers.h"
// src/havok/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppraybundlevirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
__declspec(align(16)) struct FUN_00dd4a50_cls
{
    __m128 m_v00;
    unsigned int m_i10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    __m128 m_v20;
    unsigned int m_i30;
    unsigned int m_i34;

    FUN_00dd4a50_cls* InitializeFields_00dd4a50(const FUN_00dd4a50_cls* src);
};

// Copies m_v00, m_i10, m_v20, m_i30 and m_i34 from src into this and returns this.
// @fnv 0x00dd4a50
// src: GUESS 0x00dd4a50 (confidence: low)
FUN_00dd4a50_cls* FUN_00dd4a50_cls::InitializeFields_00dd4a50(const FUN_00dd4a50_cls* src)
{
    m_v00 = src->m_v00;
    m_i10 = src->m_i10;
    m_v20 = src->m_v20;
    m_i30 = src->m_i30;
    m_i34 = src->m_i34;
    return this;
}

struct S00dd4a90_Vector
{
    S00dd4a90_Vector& operator=(const S00dd4a90_Vector& v) { m_vComponents = v.m_vComponents; return *this; }
    __m128 m_vComponents;
};

struct S00dd4a90_Vec4
{
    float x, y, z, w;
};

struct S00dd4a90_Rotation
{
    S00dd4a90_Vector m_cols[3];
};

struct RayBundleCopy
{
    S00dd4a90_Rotation m_kLocalRotations[2];
    S00dd4a90_Vec4 m_extra;
    RayBundleCopy& CopyRotationsAndExtraVector(const RayBundleCopy& rhs);
};

// Copies the two local rotation matrices and the extra vector from rhs into this RayBundleCopy and returns a reference to this.
// @fnv 0x00dd4a90
// src: GUESS 0x00dd4a90 (confidence: high)
RayBundleCopy& RayBundleCopy::CopyRotationsAndExtraVector(const RayBundleCopy& rhs)
{
    for (unsigned int i = 0; i < 2; ++i)
        m_kLocalRotations[i] = rhs.m_kLocalRotations[i];
    m_extra = rhs.m_extra;
    return *this;
}
