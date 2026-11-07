// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/Transform.h"
struct S_00db4b50_B
{
    float unk00;
    int unk04;
    float unk08;
};
struct S_00db4b50_A
{
    char* unk00;
    char* unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
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
    S_00db4b50_B* unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
};
struct S_00db4b50_Out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    float unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
};

void hkSweptTransform_ComputeValues_00cf1710(void* a, float b, float c, void* out);
__forceinline void S_rotInv(const __m128* r, const __m128* in, int n, __m128* out)
{
    __m128 a0 = r[0], a1 = r[1], a2 = r[2];
    {
        __m128 t0 = _mm_unpacklo_ps(a0, a1);
        __m128 t1 = _mm_unpackhi_ps(a0, a1);
        a0 = _mm_movelh_ps(t0, a2);
        a1 = _mm_shuffle_ps(_mm_movehl_ps(a0, t0), a2, 0xd4);
        a2 = _mm_shuffle_ps(t1, a2, 0xe4);
    }
    for (int i = 0; i < n; i++)
    {
        __m128 v = in[i];
        __m128 s = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), a1), _mm_mul_ps(_mm_shuffle_ps(v, v, 0), a0));
        out[i] = _mm_add_ps(s, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), a2));
    }
}

// Calls FUN_00cf1710 twice using a's two pointers and b's values, fills out via sub-object calls and S_rotInv, and sets out->unkcc to -a->unk14.
// @fnv 0x00db4b50
// src: GUESS 0x00db4b50 (confidence: low)
void hkTransform_setMulInverseMul_UpdateState_00db4b50(S_00db4b50_A* a, float f, S_00db4b50_Out* out)
{
    S_00db4b50_B* b = a->unk40;
    float t = b->unk08 * f;
    hkSweptTransform_ComputeValues_00cf1710(a->unk00 + 0x40, b->unk00, t, out);
    hkSweptTransform_ComputeValues_00cf1710(a->unk04 + 0x40, b->unk00, t, &out->unk40);
    void* m = &out->unk80;
    ((Transform*)m)->hkTransform_setMulInverseMul(out, &out->unk40);
    ((Vec4*)&out->unkc0)->hkVector4_setRotatedDir(m, *(const Vec4*)&a->unk20);
    ((Vec4*)&out->unkd0)->setTransformedPos_00c7f640((const Buf40*)m, &a->unk30);
    out->unkcc = -a->unk14;
    *(__m128*)&out->unk110 = *(__m128*)(a->unk00 + 0x80);
    S_rotInv((const __m128*)&out->unk00, (const __m128*)&a->unk60, 2, (__m128*)&out->unkf0);
    ((Vec4*)&out->unk120)->setTransformedPos_00c7f640((const Buf40*)m, a->unk04 + 0x80);
    ((Vec4*)&out->unke0)->hkVector4_setRotatedInverseDir(*(const Rot*)out, *(const Vec4*)&a->unk50);
}

namespace fnv_00db52c0 {
// Exe 0x00db52c0 FUN_00db52c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movehl_ps(LocalM128, LocalM128);

struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4::Aligned vector20;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    Vec4::Aligned vectora0;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    Vec4::Aligned vector130;
    void hkpGsk_getClosestFeature(void*, void*, Transform*, Vec4*);
};
// hkpConvexShape view: m_radius at +0x10 (hkReferencedObject 8 + userData + type); distance = d - radiusA - radiusB
struct GskConvexShape
{
    int unk00, unk04, unk08, unk0c;
    float radius;
};
struct PairArg
{
    GskConvexShape* p;
};
struct OutArg
{
    Vec4* p;
};

static __forceinline void calculate(Vec4& output, const Transform& frame, LocalM128 r)
{
    LocalM128 x3 = reinterpret_cast<const LocalM128&>(frame.r[0]);
    LocalM128 x1 = reinterpret_cast<const LocalM128&>(frame.r[1]);
    LocalM128 x5 = reinterpret_cast<const LocalM128&>(frame.r[2]);
    LocalM128 x2 = x3;
    x2 = _mm_unpacklo_ps(x2, x1);
    x3 = _mm_unpackhi_ps(x3, x1);
    LocalM128 x4 = x2;
    x4 = _mm_movelh_ps(x4, x5);
    x1 = x4;
    x1 = _mm_movehl_ps(x1, x2);
    x1 = _mm_shuffle_ps(x1, x5, 0xd4);
    x2 = r;
    x2 = _mm_shuffle_ps(x2, r, 0x55);
    x2 = _mm_mul_ps(x2, x1);
    x1 = r;
    x1 = _mm_shuffle_ps(x1, r, 0);
    x1 = _mm_mul_ps(x1, x4);
    x3 = _mm_shuffle_ps(x3, x5, 0xe4);
    r = _mm_shuffle_ps(r, r, 0xaa);
    x2 = _mm_add_ps(x2, x1);
    x3 = _mm_mul_ps(x3, r);
    x2 = _mm_add_ps(x2, x3);
    reinterpret_cast<LocalM128&>(output) = x2;
}
// @fnv 0x00db52c0
// src: GUESS 0x00db52c0 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00db52c0(Shape* obj, const Transform* mat, const Transform* other, GskConvexShape* apPairA,
                                              GskConvexShape* apPairB, OutArg a3, Vec4* apResult)
{
    Vec4* out = a3.p;
    // Preserve aligned stack storage without introducing /GS checks for Transform's array members.
    __declspec(align(16)) void* transformStorage[sizeof(Transform) / sizeof(void*)];
    Transform& localTransform = *reinterpret_cast<Transform*>(transformStorage);
    Vec4::Aligned shapeResult(Vec4::Uninitialized);
    localTransform.hkTransform_setMulInverseMul(mat, other);
    obj->hkpGsk_getClosestFeature(apPairA, apPairB, &localTransform, &shapeResult);

    LocalM128 v = reinterpret_cast<const LocalM128&>(shapeResult);
    LocalM128 p = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), reinterpret_cast<const LocalM128&>(mat->r[1]));
    p = _mm_add_ps(p, _mm_mul_ps(_mm_shuffle_ps(v, v, 0), reinterpret_cast<const LocalM128&>(mat->r[0])));
    p = _mm_add_ps(p, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), reinterpret_cast<const LocalM128&>(mat->r[2])));
    reinterpret_cast<LocalM128&>(*out) = p;

    LocalM128 q;
    if (obj->unk00 == 1)
        q = reinterpret_cast<const LocalM128&>(obj->vector20);
    else if (obj->unk04 == 1)
    {
        q = _mm_shuffle_ps(v, v, 0xff);
        q = _mm_shuffle_ps(q, q, 0);
        q = _mm_mul_ps(q, v);
        q = _mm_add_ps(q, reinterpret_cast<const LocalM128&>(obj->vectora0));
    }
    else
        q = reinterpret_cast<const LocalM128&>(obj->vector130);

    double distance = shapeResult.w;
    LocalM128 w = _mm_shuffle_ps(v, v, 0xff);
    LocalM128 w2 = _mm_shuffle_ps(w, w, 0);
    LocalM128 r = _mm_sub_ps(q, _mm_mul_ps(w2, v));
    r = _mm_sub_ps(r, reinterpret_cast<const LocalM128&>(localTransform.r[3]));
    calculate(*apResult, localTransform, r);
    out->w = (distance - apPairA->radius) - apPairB->radius;
}
extern Shape* volatile inputObj;
extern const Transform* volatile inputMat;
extern const Transform* volatile inputOther;
extern GskConvexShape* volatile inputPair1;
extern GskConvexShape* volatile inputPair2;
extern Vec4* volatile inputOut1;
extern Vec4* volatile inputOut2;
void emit_function()
{
    PairArg p1 = {inputPair1}, p2 = {inputPair2};
    OutArg o1 = {inputOut1}, o2 = {inputOut2};
    Object_UpdateFields_00db52c0(inputObj, inputMat, inputOther, p1.p, p2.p, o1, o2.p);
}
}  // namespace fnv_00db52c0

extern const double DAT_010c9300;
void* __cdecl hkMemoryRouter_getInstance();
struct Table
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    unsigned int(__thiscall* f2c)(struct Ctrl*);
    void(__thiscall* f30)(struct Ctrl*, unsigned int);
};
struct Ctrl
{
    Table* tab;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float f10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    float fa0;
};
struct Stat
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    float fa0;
};
struct ObjA
{
    Ctrl* ctrl;
    unsigned int unk04;
    void* p8;
};
struct ObjB
{
    Ctrl* ctrl;
    unsigned int unk04;
    Stat* p8;
};
struct In
{
    ObjA* a;
    ObjB* b;
    unsigned int unk08;
    unsigned char* p0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    __m128 v70;
};
struct Out
{
    void* f0;
    void* f4;
    unsigned int f8;
    unsigned int f0c;
    unsigned int f10;
    float f14;
    float f18;
    float f1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned char* f40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    __m128 f50;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float f6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    float f7c;
};
// Fills out from in: stores both p8 pointers and the f10 sum, reserves v*16 bytes (rounded to 128) from FUN_00c85750's cursor, and computes f18 and f1c.
// @fnv 0x00db53f0
// src: GUESS 0x00db53f0 (confidence: low)
static __declspec(noinline) void hkMemoryRouter_getInstance_UpdateState_00db53f0(In* in, Out* out)
{
    ObjA* a = in->a;
    ObjB* b = in->b;
    Ctrl* pCtrlA = a->ctrl;
    Ctrl* pCtrlB = b->ctrl;
    Stat* pStatA = (Stat*)a->p8;
    Stat* pStatB = (Stat*)b->p8;
    out->f0 = pStatA;
    out->f4 = pStatB;
    out->f14 = pCtrlB->f10 + pCtrlA->f10;
    out->f50 = in->v70;
    out->f40 = in->p0c + 0x50;
    int v = pCtrlA->tab->f2c(pCtrlA);
    out->f10 = v;
    out->f0c = v;
    unsigned int* pBlockCursor = (unsigned int*)hkMemoryRouter_getInstance();
    unsigned int uiBlockStart = *pBlockCursor;
    int sz = v * 16;
    sz = sz + 0x7f;
    sz = sz & 0xffffff80;
    *pBlockCursor = uiBlockStart + sz;
    out->f8 = uiBlockStart;
    pCtrlA->tab->f30(pCtrlA, uiBlockStart);
    float t1 = pStatB->fa0 * out->f7c * out->f7c;
    float t2 = pStatA->fa0 * out->f6c * out->f6c;
    float t = t1 + t2;
    out->f18 = t;
    out->f1c = (float)(1.0 / ((double)t + DAT_010c9300));
}

extern In* volatile inputIn;
extern Out* volatile inputOut;
void emit_function()
{
    hkMemoryRouter_getInstance_UpdateState_00db53f0(inputIn, inputOut);
}
