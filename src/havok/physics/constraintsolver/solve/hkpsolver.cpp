#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// havok/physics/constraintsolver/solve/hkpsolver.cpp: free functions (5 functions)

#include "fnv_asm_helpers.h"
// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern unsigned char DAT_011b9434[128];

// @fnv 0x00d921d0
// src: GUESS 0x00d921d0 (confidence: low)
int __cdecl Hkpsolver_GetIndexedValue_00d921d0(const signed char* index)
{
    return DAT_011b9434[*index];
}

typedef ::__m128 LocalM128;

using ::_mm_add_ss;

// Adds the lowest single-precision float of b to that of a and stores the result in out.
// @fnv 0x00c6cce0
extern "C" void __cdecl AddScalarFloat(LocalM128* pResult, const LocalM128* pLeft, const LocalM128* pRight)
{
    *pResult = _mm_add_ss(*pLeft, *pRight);
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
extern "C" void __cdecl SubtractScalarFloat(LocalM128* pResult, const LocalM128* pLeft, const LocalM128* pRight)
{
    *pResult = _mm_sub_ss(*pLeft, *pRight);
}

// FUN_00d892d0: single-ret __cdecl void function. Body is empty; the claimed
// 17-byte extent is 15 int3 padding bytes plus the next function's ret.
// @fnv 0x00d892d0
// src: XBOX_PDB 0x00d892d0
void hkSolveUpload()
{
}
