#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/physics/constraintsolver/solve/hkpsolver_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/havok/physics/constraintsolver/solve/hkpsolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern unsigned char DAT_011b9434[128];
int __cdecl Hkpsolver_GetIndexedValue_00d921d0(const signed char* index);
typedef ::__m128 LocalM128;
using ::_mm_add_ss;
// @fnv 0x00c6cce0
extern "C" void __cdecl AddScalarFloat(LocalM128* out, const LocalM128* a, const LocalM128* b)
{
    *out = _mm_add_ss(*a, *b);
}

// @fnv 0x00d921c0
// src: GUESS 0x00d921c0 (confidence: low)
char* __cdecl Object_ComputeValue_00d921c0(char* dst, const char* src)
{
    *dst = *src;
    return dst;
}

using ::_mm_sub_ss;
// @fnv 0x00c6ccc0
extern "C" void __cdecl SubtractScalarFloat(LocalM128* out, const LocalM128* a, const LocalM128* b)
{
    *out = _mm_sub_ss(*a, *b);
}

using ::_mm_mul_ss;

struct Vec4Src
{
    LocalM128* GetVec();
};

struct Vec4Dst
{
    void SetVec(const LocalM128& v);
};

// @fnv 0x00891060
// src: GUESS 0x00891060 (confidence: low)
Vec4Dst* __cdecl Object_ProcessAndReturnValue_00891060(Vec4Dst* out, Vec4Src* b, Vec4Src* a)
{
    out->SetVec(_mm_mul_ss(*b->GetVec(), *a->GetVec()));
    return out;
}
