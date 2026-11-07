
// src/havok/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppearlyexitobbvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkBool.h"
extern char DAT_0126efba;
void ValidateHavokKeyCode(char* pKey);
struct S_00e647e0_Shape;
struct S_00e647e0_Input { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; S_00e647e0_Shape* m_pCollisionShape; };
struct S_00e647e0_Local { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48; int unk4C; };
struct S_00e647e0 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    hkBool m_bHasHit; char unk41; char unk42; char unk43;
    S_00e647e0_Input* m_pRayCastInput;
    void ComputeValues_00e645b0(const void* a, const void* b, const void* c, S_00e647e0_Local* out);
    void queryOBBOnTree(S_00e647e0_Local* l, S_00e647e0_Shape* shape);
    hkBool SetupAndProcessShape(S_00e647e0_Input* input, const void* b, const void* c, const void* d);
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();

extern const __m128 DAT_01017d10;
extern const __m128 DAT_010c44d0;

struct S_00e645b0_Transform {
    __m128 col0;
    __m128 col1;
    __m128 col2;
    __m128 translation;
};

struct S_00e645b0_Input {
    int unk00; int unk04; int unk08; int unk0C;
    float origin_x;
    float origin_y;
    float origin_z;
    float invCellSize;
    S_00e647e0_Shape* m_pCollisionShape;
};

struct SignedWords { short low; short high; };
static __forceinline int highWord(const int& value) { return ((const SignedWords*)&value)->high; }

static inline int S_00e645b0_Cell(float v, float origin, float inv) {
    float d = (v - origin) * inv;
    return fnv_FloatToInt(d);
}

static __forceinline float VecScalar(__m128 v) { float result; _mm_store_ss(&result, v); return result; }
static __forceinline int RadiusCell(float size, float inv) { return fnv_FloatToInt(size * inv); }

struct VectorValue {
    __m128 v;
    VectorValue() {}
    VectorValue(__m128 x):v(x) {}
    VectorValue(const VectorValue& x):v(x.v) {}
    VectorValue operator+(const VectorValue& x) const { VectorValue r; r.v=_mm_add_ps(v,x.v); return r; }
    VectorValue operator-() const { VectorValue r; r.v=_mm_xor_ps(v,DAT_010c44d0); return r; }
};

struct AabbOut { __m128 m_kMinimumCorner; __m128 m_kMaximumCorner; };
static __forceinline void CalcAabb(const S_00e645b0_Transform& t, const __m128& he, const float& r, AabbOut& out) {
    __m128 tx = _mm_and_ps(_mm_mul_ps(_mm_shuffle_ps(he, he, 0), t.col0), DAT_01017d10);
    __m128 ty = _mm_and_ps(_mm_mul_ps(_mm_shuffle_ps(he, he, 0x55), t.col1), DAT_01017d10);
    __m128 tz = _mm_and_ps(_mm_mul_ps(_mm_shuffle_ps(he, he, 0xaa), t.col2), DAT_01017d10);
    __m128 ext = _mm_add_ps(ty, tx);
    ext = _mm_add_ps(ext, tz);
    ext = _mm_add_ps(ext, _mm_load_ps1(&r));
    out.m_kMinimumCorner = _mm_xor_ps(ext, DAT_010c44d0);
    out.m_kMaximumCorner = ext;
    out.m_kMaximumCorner = _mm_add_ps(out.m_kMaximumCorner, t.translation);
    out.m_kMinimumCorner = _mm_add_ps(out.m_kMinimumCorner, t.translation);
}
struct PointerArg { const void* p; };
struct BoundsWorker {
 int unk00,unk04,unk08,unk0C,unk10,unk14,unk18,unk1C,unk20,unk24,unk28,unk2C,unk30,unk34,unk38,unk3C;
 hkBool m_bHasHit; char unk41,unk42,unk43; S_00e647e0_Input* m_pRayCastInput;
 void ComputeValues_00e645b0(const void* a, PointerArg b, const void* c, S_00e647e0_Local* out);
};

// @fnv 0x00e645b0
// src: GUESS 0x00e645b0 (confidence: low)
void BoundsWorker::ComputeValues_00e645b0(const void* a, PointerArg b, const void* c, S_00e647e0_Local* out) {
    const __m128* pExt = (const __m128*)a;
    const S_00e645b0_Transform* t = (const S_00e645b0_Transform*)b.p;
    const float* pRadius = (const float*)c;

    AabbOut aabb;
    CalcAabb(*t, *pExt, *pRadius, aabb);
    const float* mn = (const float*)&aabb.m_kMinimumCorner;
    const float* mxv = (const float*)&aabb.m_kMaximumCorner;

    this->unk20 = S_00e645b0_Cell(mn[0], ((S_00e645b0_Input*)this->m_pRayCastInput)->origin_x, ((S_00e645b0_Input*)this->m_pRayCastInput)->invCellSize) - 1;
    this->unk10 = S_00e645b0_Cell(mxv[0], ((S_00e645b0_Input*)this->m_pRayCastInput)->origin_x, ((S_00e645b0_Input*)this->m_pRayCastInput)->invCellSize) + 1;
    this->unk24 = S_00e645b0_Cell(mn[1], ((S_00e645b0_Input*)this->m_pRayCastInput)->origin_y, ((S_00e645b0_Input*)this->m_pRayCastInput)->invCellSize) - 1;
    this->unk14 = S_00e645b0_Cell(mxv[1], ((S_00e645b0_Input*)this->m_pRayCastInput)->origin_y, ((S_00e645b0_Input*)this->m_pRayCastInput)->invCellSize) + 1;
    this->unk28 = S_00e645b0_Cell(mn[2], ((S_00e645b0_Input*)this->m_pRayCastInput)->origin_z, ((S_00e645b0_Input*)this->m_pRayCastInput)->invCellSize) - 1;
    S_00e645b0_Input* lastInput = (S_00e645b0_Input*)this->m_pRayCastInput;
    _ReadWriteBarrier();
    this->unk18 = S_00e645b0_Cell(mxv[2], lastInput->origin_z, lastInput->invCellSize) + 1;

    this->unk30 = (this->unk20 + this->unk10) >> 1;
    this->unk34 = (this->unk24 + this->unk14) >> 1;
    this->unk38 = (this->unk28 + this->unk18) >> 1;

    __m128 ext2 = _mm_mul_ps(*pExt, *pExt);
    __m128 ext2_y = _mm_shuffle_ps(ext2, ext2, 0x55);
    __m128 ext2_z = _mm_shuffle_ps(ext2, ext2, 0xaa);
    __m128 len_sq = _mm_add_ss(ext2_y, ext2);
    len_sq = _mm_add_ss(ext2_z, len_sq);
    __m128 len = _mm_sqrt_ss(len_sq);


    this->unk3C = RadiusCell(*pRadius + VecScalar(len), ((S_00e645b0_Input*)this->m_pRayCastInput)->invCellSize) + 1;

    out->unk10 = highWord(this->unk20);
    out->unk00 = highWord(this->unk10) + 1;
    out->unk14 = highWord(this->unk24);
    out->unk04 = highWord(this->unk14) + 1;
    out->unk18 = highWord(this->unk28);
    out->unk08 = highWord(this->unk18) + 1;
    out->unk20 = highWord(this->unk30);
    out->unk24 = highWord(this->unk34);
    out->unk28 = highWord(this->unk38);
    out->unk2C = highWord(this->unk3C) + 1;
    out->unk30 = 0;
    out->unk34 = 0;
    out->unk38 = 0;
    out->unk3C = 0;
    out->unk40 = 0;
    out->unk44 = 0;
}
