#include "../../../../../../../../../include/hkArrayBase.h"

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolllimitsdrawer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolllimitsdrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolllimitsdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolllimitsdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "../../../../../../../../../include/Vec4.h"
#include <math.h>
struct Renderer;

extern float DAT_01011d78;
extern const float DAT_01017718;
extern float DAT_01016248;
extern double DAT_01030f38;
extern float DAT_010c44d0;
__forceinline __m128 cross0(const Vec4& b, const Vec4& a)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const __m128&>(a), reinterpret_cast<const __m128&>(a), 0xd2), _mm_shuffle_ps(reinterpret_cast<const __m128&>(b), reinterpret_cast<const __m128&>(b), 0xc9)),
                      _mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const __m128&>(a), reinterpret_cast<const __m128&>(a), 0xc9), _mm_shuffle_ps(reinterpret_cast<const __m128&>(b), reinterpret_cast<const __m128&>(b), 0xd2)));
}
__forceinline void cross1(__m128& dst, const Vec4& b, const Vec4& a)
{
    dst = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const __m128&>(a), reinterpret_cast<const __m128&>(a), 0xd2), _mm_shuffle_ps(reinterpret_cast<const __m128&>(b), reinterpret_cast<const __m128&>(b), 0xc9)),
                     _mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const __m128&>(a), reinterpret_cast<const __m128&>(a), 0xc9), _mm_shuffle_ps(reinterpret_cast<const __m128&>(b), reinterpret_cast<const __m128&>(b), 0xd2)));
}
struct SourceView
{
    int u00, u04, u08, u0c;
    Vec4 rows10[4];
    Vec4 rows50[4];
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    int uc0;
    int uc4;
    int uc8;
    int ucc;
    int ud0;
    int ud4;
    int ud8;
    int udc;
    int ue0;
    int ue4;
    int ue8;
    unsigned char uec, ued, uee, indexEF;
    int uf0;
    int uf4;
    int uf8;
    int ufc;
    int u100;
    int u104;
    int u108;
    float u10c;
    int u110;
    unsigned char u114, u115, u116, index117;
    unsigned char index118, u119, u11a, u11b;
    float angle11c, angle120;
};
struct Source
{
    int u00, u04, u08, u0c;
    SourceView body;
};
struct Input
{
    int u00, u04, u08;
    Source* source;
};
struct SubC0
{
    void hkpPrimitiveDrawer_setDisplayHandler(Renderer* a);
    void ComputeValues_00e10d50(void* a, void* b, void* c, int d, float e, int a2, int a3);
};

struct CharacterBufferState
{
    int u00, u04, u08, u0c;
    void* owner;
};
extern CharacterBufferState* hkMemoryRouter_getInstance();
extern void hkArrayUtil__reserve(void* owner, hkArrayBase<void*>* arr, int newCap, int stride);
extern int PackBytesBigEndian(int a, int b, int c, int d);
struct Renderer
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void draw(hkArrayBase<void*>*, int color, int a2, int a3);
};
struct Cls
{
    int u00;
    int u04;
    int u08;
    float f0c;
    float f10;
    float f14;
    int p18;
    float f1c;
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
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    void UpdateState_00de6730(Input* a0, Renderer* a1, int a2, int a3);
    void hkpConstraintDrawer_updateCommonParameters(void* a0, void* b, void* c);
    void hkpConstraintDrawer_drawPivots(int a2, int a3);
    void InitializeFields_00de5370(float angle, float scale, int flags, void* point, void* source);
    void SetFromVectors(void* a, void* b, void* c, void* d);
};
typedef int(__thiscall* VCall38)(void* self, void* a, int color, int a2, int a3);
struct Big
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, ma, mb, mc, md, me, mf;
};
struct __declspec(align(16)) Geometry
{
    __m128 v60;
    __m128 out70;
    __m128 v80, v48;
    __m128 scaleVector, outB0;
    __m128 v30;
    Big tD0, t110;
};
__forceinline void prepareAxes(Cls* self, SourceView* src, Geometry& geometry)
{
    Vec4* columnBase1 = src->rows50;
    Vec4* columnBase2 = src->rows10;
    ((Vec4*)&geometry.v80)->hkVector4_setRotatedDir(&self->unk90, src->rows50[src->indexEF]);

    {
        __m128 zeroRaw, threeRaw, halfRaw;
        // Transform the first normalized cross product.
        {
            int offset117 = src->index117 << 4;
            int offset118 = src->index118 << 4;
            unsigned int base1 = (unsigned int)columnBase1;
            __m128 cr = cross0(*(Vec4*)(base1 + offset117), *(Vec4*)(base1 + offset118));
            __m128 sq = _mm_mul_ps(cr, cr);
            __m128 ds = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
            __m128 rsq;
            rsq = _mm_rsqrt_ss(ds);
            zeroRaw = _mm_set_ss(0.0f);
            threeRaw = _mm_set_ss(DAT_01017718);
            halfRaw = _mm_set_ss(DAT_01016248);
            __m128 isZero = _mm_cmpeq_ss(ds, zeroRaw);
            __m128 prod5 = _mm_mul_ss(_mm_mul_ss(ds, rsq), rsq);
            prod5 = _mm_sub_ss(threeRaw, prod5);
            prod5 = _mm_mul_ss(_mm_mul_ss(halfRaw, rsq), prod5);
            prod5 = _mm_andnot_ps(isZero, prod5);
            prod5 = _mm_shuffle_ps(prod5, prod5, 0);
            _mm_store_ps((float*)&geometry.out70, _mm_mul_ps(prod5, cr));
            ((Vec4*)&geometry.out70)->hkVector4_setRotatedDir(&self->unk90, *(Vec4*)&geometry.out70);
        }
        ((Vec4*)&geometry.v60)->hkVector4_setRotatedDir(&self->unk90, *(Vec4*)((unsigned int)columnBase1 + (src->index118 << 4)));
        // Transform the second normalized cross product.
        {
            int offset117 = src->index117 << 4;
            int offset118 = src->index118 << 4;
            unsigned int base2 = (unsigned int)columnBase2;
            __m128 cr;
            cross1(cr, *(Vec4*)(base2 + offset118), *(Vec4*)(base2 + offset117));
            __m128 sq;
            sq = _mm_mul_ps(cr, cr);
            __m128 ds = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
            __m128 rsq = _mm_rsqrt_ss(ds);
            __m128 isZero = _mm_cmpeq_ss(ds, zeroRaw);
            __m128 prod5 = _mm_mul_ss(_mm_mul_ss(ds, rsq), rsq);
            prod5 = _mm_sub_ss(threeRaw, prod5);
            prod5 = _mm_mul_ss(_mm_mul_ss(halfRaw, rsq), prod5);
            prod5 = _mm_andnot_ps(isZero, prod5);
            prod5 = _mm_shuffle_ps(prod5, prod5, 0);
            _mm_store_ps((float*)&geometry.outB0, _mm_mul_ps(prod5, cr));
            ((Vec4*)&geometry.v48)->hkVector4_setRotatedDir(&self->unk60, *(Vec4*)&geometry.outB0);
        }
    }
    ((Vec4*)&geometry.v30)->hkVector4_setRotatedDir(&self->unk60, *(Vec4*)((unsigned int)columnBase2 + (src->indexEF << 4)));
}
__forceinline void drawGroups(Cls* self, Renderer* a1, int a2, int a3, Cls* objectD0, Cls* object160, Cls* object280)
{
    __declspec(align(16)) hkArrayBase<void*> zeroArray, halfArray, threeArray;
    zeroArray.m_data = 0;
    zeroArray.m_iElementCount = 0;
    zeroArray.m_iCapacityState = (int)0x80000000;
    halfArray.m_data = 0;
    halfArray.m_iElementCount = 0;
    halfArray.m_iCapacityState = (int)0x80000000;
    threeArray.m_data = 0;
    threeArray.m_iElementCount = 0;
    threeArray.m_iCapacityState = (int)0x80000000;
    {
        CharacterBufferState* ar;
        int cap;
        void* owner;
        ar = hkMemoryRouter_getInstance();
        owner = ar->owner;
        int nc;
        cap = zeroArray.m_iCapacityState & 0x3fffffff;
        if (cap < 1)
        {
            nc = cap * 2;
            if (nc <= 1)
                nc = 1;
            hkArrayUtil__reserve(owner, &zeroArray, nc, 4);
        }
        zeroArray.m_iElementCount = 1;
    }
    {
        CharacterBufferState* ar;
        int cap;
        void* owner;
        ar = hkMemoryRouter_getInstance();
        owner = ar->owner;
        int nc;
        cap = threeArray.m_iCapacityState & 0x3fffffff;
        if (cap < 1)
        {
            nc = cap * 2;
            if (nc <= 1)
                nc = 1;
            hkArrayUtil__reserve(owner, &threeArray, nc, 4);
        }
        threeArray.m_iElementCount = 1;
    }
    {
        CharacterBufferState* ar;
        int cap;
        void* owner;
        ar = hkMemoryRouter_getInstance();
        owner = ar->owner;
        int nc;
        cap = halfArray.m_iCapacityState & 0x3fffffff;
        if (cap < 2)
        {
            nc = cap * 2;
            if (nc <= 2)
                nc = 2;
            hkArrayUtil__reserve(owner, &halfArray, nc, 4);
        }
        halfArray.m_iElementCount = 2;
    }
    ((void**)zeroArray.m_data)[0] = objectD0;
    ((void**)halfArray.m_data)[0] = object160;
    ((void**)halfArray.m_data)[1] = &self->unk1f0;
    ((void**)threeArray.m_data)[0] = object280;
    a1->draw(&zeroArray, 0xffffff00, a2, a3);
    a1->draw(&halfArray, 0xffff0000, a2, a3);
    a1->draw(&threeArray, PackBytesBigEndian(0xff, 0, 0xff, 0xff), a2, a3);

    {
        CharacterBufferState* ar = hkMemoryRouter_getInstance();
        void* ow = ar->owner;
        threeArray.m_iElementCount = 0;
        if (!(threeArray.m_iCapacityState & (int)0x80000000))
        {
            void** ovt = *(void***)ow;
            ((void(__thiscall*)(void*, void*, int))ovt[4])(ow, threeArray.m_data, (threeArray.m_iCapacityState & 0x3fffffff) * 4);
        }
        threeArray.m_data = 0;
        threeArray.m_iCapacityState = (int)0x80000000;
    }
    {
        CharacterBufferState* ar = hkMemoryRouter_getInstance();
        void* ow = ar->owner;
        halfArray.m_iElementCount = 0;
        if (!(halfArray.m_iCapacityState & (int)0x80000000))
        {
            void** ovt = *(void***)ow;
            ((void(__thiscall*)(void*, void*, int))ovt[4])(ow, halfArray.m_data, (halfArray.m_iCapacityState & 0x3fffffff) * 4);
        }
        halfArray.m_data = 0;
        halfArray.m_iCapacityState = (int)0x80000000;
    }
    {
        CharacterBufferState* ar = hkMemoryRouter_getInstance();
        void* ow = ar->owner;
        zeroArray.m_iElementCount = 0;
        if (!(zeroArray.m_iCapacityState & (int)0x80000000))
        {
            void** ovt = *(void***)ow;
            ((void(__thiscall*)(void*, void*, int))ovt[4])(ow, zeroArray.m_data, (zeroArray.m_iCapacityState & 0x3fffffff) * 4);
        }
        zeroArray.m_data = 0;
        zeroArray.m_iCapacityState = (int)0x80000000;
    }
}
// @fnv 0x00de6730
// src: GUESS 0x00de6730 (confidence: low)
void Cls::UpdateState_00de6730(Input* a0, Renderer* a1, int a2, int a3)
{
    struct ArcPointers
    {
        Cls* object160;
        Cls* objectD0;
    } arcs;
    Source* srcHome = a0->source;
    Geometry geometry;  // Normalization constants and draw groups have disjoint lifetimes.

    ((SubC0*)&unkc0)->hkpPrimitiveDrawer_setDisplayHandler(a1);
    hkpConstraintDrawer_updateCommonParameters(a0, &geometry.tD0, &geometry.t110);
    Vec4* object50 = (Vec4*)(&unk50);
    object50->setTransformedPos_00c7f640((const Buf40*)&geometry.tD0, &srcHome->body.rows50[3]);
    ((Vec4*)(&unk40))->setTransformedPos_00c7f640((const Buf40*)&geometry.t110, &srcHome->body.rows10[3]);
    hkpConstraintDrawer_drawPivots(a2, a3);

    SourceView* src = &srcHome->body;
    prepareAxes(this, src, geometry);
    float prod1 = f1c * f0c;
    ((SubC0*)&unkc0)->ComputeValues_00e10d50(object50, &geometry.v80, &geometry.out70, 0xff008000, prod1, a2, a3);
    float prod2 = f0c * f1c;
    ((SubC0*)&unkc0)
        ->ComputeValues_00e10d50(&unk40, &geometry.v30, &geometry.v48, PackBytesBigEndian(0xff, 0xff, 0, 0xff), prod2, a2, a3);

    arcs.objectD0 = (Cls*)&unkd0;
    float prod3 = f1c;
    prod3 *= f10;
    void* self18;
    self18 = (void*)p18;
    ((Cls*)arcs.objectD0)->InitializeFields_00de5370(srcHome->body.u10c, prod3, (int)self18, &geometry.v80, object50);
    Cls* object280 = (Cls*)&unk280;
    float n = f14 * f1c;
    geometry.scaleVector = _mm_set1_ps(n);
    ((Cls*)object280)->SetFromVectors(&geometry.v60, &geometry.out70, object50, &geometry.scaleVector);
    arcs.object160 = (Cls*)&unk160;
    float scale = f1c * f10;
    float savedAngle = src->angle11c;
    ((Cls*)arcs.object160)
        ->InitializeFields_00de5370((float)(DAT_01030f38 - fabs(src->angle120)), scale, p18, &geometry.v60, object50);
    float prod6 = f1c * f10;
    _mm_store_ps((float*)&geometry.v60, _mm_xor_ps(_mm_load_ps((float*)&geometry.v60), _mm_load_ps(&DAT_010c44d0)));
    ((Cls*)(&unk1f0))->InitializeFields_00de5370((float)(DAT_01030f38 - fabs(savedAngle)), prod6, p18, &geometry.v60, object50);
    drawGroups(this, a1, a2, a3, arcs.objectD0, arcs.object160, object280);
}
