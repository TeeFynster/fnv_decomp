
// src/staging/blk_00440000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00440000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00440000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct S004586d0_Obj
{
    __declspec(align(16)) float x, y, z, w;
    float EvaluateValue_004586d0();
};
// @fnv 0x004586d0
// src: GUESS 0x004586d0 (confidence: low)
float S004586d0_Obj::EvaluateValue_004586d0()
{
    float tmp;
    _mm_store_ss(&tmp, *(__m128*)this);
    return tmp;
}

struct Holder
{
    __m128 value;
    void FUN_004a3c90(Holder* other);
    Holder* hkVector4_getSimdAt(Holder* target, int index);
};

// @fnv 0x00458700
// src: COMMUNITY 0x00458700
Holder* Holder::hkVector4_getSimdAt(Holder* target, int index)
{
    switch (index)
    {
    case 0:
        target->FUN_004a3c90(this);
        return target;
    case 1:
        target->FUN_004a3c90((Holder*)&static_cast<const __m128&>(_mm_shuffle_ps(value, value, 0x55)));
        return target;
    case 2:
        target->FUN_004a3c90((Holder*)&static_cast<const __m128&>(_mm_shuffle_ps(value, value, 0xaa)));
        return target;
    default:
        target->FUN_004a3c90((Holder*)&static_cast<const __m128&>(_mm_shuffle_ps(value, value, 0xff)));
        return target;
    }
}

class S00458900_Comparison
{
  public:
    bool hkVector4Comparison_allAreSet(int mask) const;  // allAreSet
    __m128 m_uiMask;
};

class S00458900_Vector
{
  public:
    S00458900_Vector();                                                       // FUN_006815c0
    void hkVector4_setSub4(const S00458900_Vector* a, const S00458900_Vector* b);  // setSub4
    void hkVector4_setAbs4(const S00458900_Vector* v);                             // setAbs4
    void hkVector4_setAll(float f);
    S00458900_Comparison hkVector4_compareLessThanEqual4(const S00458900_Vector* v) const;  // compareLessThan4
    bool hkVector4_equals3(const S00458900_Vector* v, float epsilon) const;   // equals3
    __m128 m_vComponents;
};

// @fnv 0x00458900
// src: XBOX_PDB 0x00458900
bool S00458900_Vector::hkVector4_equals3(const S00458900_Vector* v, float epsilon) const
{
    S00458900_Vector kDiff;
    kDiff.hkVector4_setSub4(this, v);
    kDiff.hkVector4_setAbs4(&kDiff);
    S00458900_Vector kEpsilon;
    kEpsilon.hkVector4_setAll(epsilon);
    return kDiff.hkVector4_compareLessThanEqual4(&kEpsilon).hkVector4Comparison_allAreSet(7);
}

struct FUN_00458990_Holder
{
    __m128 m_v;
    int hkVector4Comparison_allAreSet(int mask);
};

// @fnv 0x00458990
// src: COMMUNITY 0x00458990
int FUN_00458990_Holder::hkVector4Comparison_allAreSet(int mask)
{
    return (_mm_movemask_ps(m_v) & mask) == mask;
}

struct FUN_004589c0_cls
{
    __m128 m_v;
    void hkVector4_setAll(float value);
};
// @fnv 0x004589c0
// src: COMMUNITY 0x004589c0
void FUN_004589c0_cls::hkVector4_setAll(float value)
{
    m_v = _mm_set1_ps(value);
}

struct S00458a10_Vector
{
    __m128 m_vComponents;
    void hkVector4_setSub4(const S00458a10_Vector* a, const S00458a10_Vector* b);
};

// @fnv 0x00458a10
// src: XBOX_PDB 0x00458a10
void S00458a10_Vector::hkVector4_setSub4(const S00458a10_Vector* a, const S00458a10_Vector* b)
{
    m_vComponents = _mm_sub_ps(a->m_vComponents, b->m_vComponents);
}

struct Mask4
{
    unsigned int x, y, z, w;
};
union MaskVec
{
    __m128 v;
    Mask4 m;
};

class VecMask
{
  public:
    __m128 m_v;
    Mask4* hkVector4_compareLessThanEqual4(Mask4* out, const __m128* b);
};

// @fnv 0x00458a60
// src: COMMUNITY 0x00458a60
Mask4* VecMask::hkVector4_compareLessThanEqual4(Mask4* out, const __m128* b)
{
    MaskVec t;
    t.v = _mm_cmple_ps(m_v, *b);
    *out = t.m;
    return out;
}

extern __m128 DAT_01017d10;  // abs mask (0x7fffffff x4)

struct S00458ad0_Vector
{
    __m128 m_vComponents;
    void hkVector4_setAbs4(const S00458ad0_Vector* v);  // setAbs4
};

// @fnv 0x00458ad0
// src: COMMUNITY 0x00458ad0
void S00458ad0_Vector::hkVector4_setAbs4(const S00458ad0_Vector* v)
{
    m_vComponents = _mm_and_ps(v->m_vComponents, DAT_01017d10);
}
