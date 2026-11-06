
// src/staging/blk_00a60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00a60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv_asm_helpers.h"
#include "../../include/NiPoint3.h"
// src/staging/blk_00a60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern unsigned char DAT_011f4a54;
extern int DAT_011f4a50;
int __cdecl FUN_00a74880();
int __cdecl FUN_00a74900();
void __cdecl FUN_00a74a10();
int __cdecl FUN_00a74bc0();
int __cdecl FUN_00a74cb0();
void __cdecl FUN_00a74d80(int);
void __cdecl FUN_00a74d90(int);
void __cdecl FUN_00a74da0();
struct XfRSLocal {
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    float tx;
    float ty;
    float tz;
    float scale;
};
void FUN_00a74bc0(unsigned short count, NiPoint3* in, NiPoint3* out, XfRSLocal* xf);
struct A74CB0Matrix3 {
    float m_afEntries[3][3];
};
void FUN_00a74cb0(unsigned short m_usPassCountLocal, const NiPoint3* pkIn, NiPoint3* pkOut, const A74CB0Matrix3* pkMatrix);

// @fnv 0x00a74880
void __cdecl FUN_00a74880(unsigned short count, const float* src, float* dst, const float* matrix) {
    unsigned int n = count;
    fnv_TransformVectors(n, src, dst, matrix);
}

struct ScaledMatrix {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
// @fnv 0x00a74900
void __cdecl FUN_00a74900(unsigned short count, const NiPoint3* src,
                        NiPoint3* dst, const XfRSLocal* xf) {
    unsigned int n = count;
    ScaledMatrix m;
    ScaledMatrix* matrix = &m;
    float tx = xf->tx;
    float ty = xf->ty;
    float tz = xf->tz;
    float scale = xf->scale;
    m.m00 = xf->m00 * scale;
    m.m01 = xf->m01 * scale;
    m.m02 = xf->m02 * scale;
    m.m10 = xf->m10 * scale;
    m.m11 = xf->m11 * scale;
    m.m12 = xf->m12 * scale;
    m.m20 = xf->m20 * scale;
    m.m21 = xf->m21 * scale;
    m.m22 = xf->m22 * scale;
    fnv_TransformPoints(n, src, dst, matrix, tx, ty, tz);
}
