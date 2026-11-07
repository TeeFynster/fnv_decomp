// src/havok/physics/collide/query/castutil/hkpworldlinearcaster_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/query/castutil/hkpworldlinearcaster_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/query/castutil/hkpworldlinearcaster_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/castutil/hkpworldlinearcaster.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/query/castutil/hkpworldlinearcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/castutil/hkpworldlinearcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FloatHolder
{
    int unk00;
    float m_04;
};
struct SlotRecord
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    signed char m_05;
};
struct SlotTarget
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
};
struct FuncEntry
{
    void* pfn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
typedef int(__cdecl* SlotFn)(int, int, int, int, int);
struct NodeMatcher
{
    virtual void v00();
    virtual unsigned char* Match(SlotRecord** ppRecord, int aKey, int aSlot);
};
struct FUN_00cfae50_cls
{
    int unk00;
    int unk04;
    NodeMatcher* m_08;
    FloatHolder* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int unk1c;
    unsigned char* m_20;

    float InvokeSlotHandler(SlotRecord* a1, int a2);
};

#include <xmmintrin.h>

extern __m128 DAT_010ec7f0;
extern float DAT_01016248;

struct __declspec(align(16)) S_00cfaed0_V4
{
    float x, y, z, w;
};
struct S_00cfaed0_Sub
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S_00cfaed0_V4 v30;
};
struct S_00cfaed0_Out
{
    S_00cfaed0_V4 a;
    S_00cfaed0_V4 b;
};
struct S_00cfaed0_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(S_00cfaed0_Sub* s, float f, S_00cfaed0_Out* out);
    int unk04, unk08, unk0c;
};
struct S_00cfaed0_P2
{
    S_00cfaed0_Obj* unk00;
    int unk04;
    S_00cfaed0_Sub* unk08;
};
struct S_00cfaed0_P3
{
    S_00cfaed0_V4 v;
    float f10;
    float f14;
};
struct S_00cfaed0_P5
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    S_00cfaed0_V4 v20;
    S_00cfaed0_V4 v30;
    S_00cfaed0_V4 v40;
};
struct S_00cfaed0_Info
{
    S_00cfaed0_V4 pos;
    S_00cfaed0_V4 sum;
    S_00cfaed0_V4 dir;
    int param;
    S_00cfaed0_Info()
    {
        param = 0;
    }
};
struct S_00cfaed0_Locals
{
    S_00cfaed0_Out out;
    S_00cfaed0_Info info;
};
__forceinline __m128 S_00cfaed0_LengthV(const __m128& d)
{
    __m128 sq = _mm_mul_ps(d, d);
    return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq)));
}
__forceinline float S_00cfaed0_Length(__m128 d)
{
    __m128 sq = _mm_mul_ps(d, d);
    float r;
    _mm_store_ss(&r,
                 _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq))));
    return r;
}
struct S_00cfaed0_This;
struct S_00cfaed0_Iface;
struct S_00cfaed0_IfaceP
{
    S_00cfaed0_Iface* p;
    S_00cfaed0_Iface* val() const
    {
        return p;
    }
};
struct S_00cfaed0_Iface
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b(S_00cfaed0_Info* info, S_00cfaed0_This* t);
};
struct S_00cfaed0_This
{
    int unk00;
    S_00cfaed0_P3* p3;
    int p4, p8, p9;
    S_00cfaed0_P2* p2;
    int unk18, unk1c;
    int u20, u24, u28, u2c, u30, u34;
    int unk38, unk3c;
    S_00cfaed0_V4 v40;
    S_00cfaed0_V4 v50;
    S_00cfaed0_V4 v60;
    S_00cfaed0_V4 v70;
    float f80;
    float f84;
    int p6;
    void ComputeValues_00cfaed0(S_00cfaed0_Iface* p1, S_00cfaed0_P2* a2, S_00cfaed0_P3* a3, int a4, S_00cfaed0_P5* a5, int a6,
                      int a7, int a8, int a9);
};

struct S_00cfaed0_Real
{
    __m128 r;
    S_00cfaed0_Real(const float& x)
    {
        r = _mm_load_ss(&x);
    }
};
struct S_00cfaed0_Vec
{
    __m128 q;
    __forceinline void setInterpolate4(const S_00cfaed0_Vec& a, const S_00cfaed0_Vec& b, const S_00cfaed0_Real& t)
    {
        __m128 tt = _mm_shuffle_ps(t.r, t.r, 0);
        q = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, tt), a.q), _mm_mul_ps(b.q, tt));
    }
    __forceinline void setSub4(const S_00cfaed0_Vec& a, const S_00cfaed0_Vec& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void setAdd4(const S_00cfaed0_Vec& a, const S_00cfaed0_Vec& b)
    {
        q = _mm_add_ps(a.q, b.q);
    }
    __forceinline void mul4(const S_00cfaed0_Real& t)
    {
        q = _mm_mul_ps(_mm_shuffle_ps(t.r, t.r, 0), q);
    }
    __forceinline void setMul4(const S_00cfaed0_Real& t, const S_00cfaed0_Vec& v)
    {
        q = _mm_mul_ps(_mm_shuffle_ps(t.r, t.r, 0), v.q);
    }
};
// @fnv 0x00cfaed0
// src: GUESS 0x00cfaed0 (confidence: low)
void S_00cfaed0_This::ComputeValues_00cfaed0(S_00cfaed0_Iface* p1, S_00cfaed0_P2* a2, S_00cfaed0_P3* a3, int a4,
                                   S_00cfaed0_P5* a5, int a6, int a7, int a8, int a9)
{
    *(volatile int*)&p8 = a8;
    p9 = *(volatile int*)&a9;
    p2 = a2;
    p4 = a4;
    p3 = a3;
    unk18 = a2->unk00->unk0c;
    u20 = a5->u00;
    u24 = a5->u04;
    u28 = a5->u08;
    u2c = a5->u0c;
    u30 = a5->u10;
    u34 = a5->u14;
    *(__m128*)&v40 = *(__m128*)&a5->v20;
    *(__m128*)&v50 = *(__m128*)&a5->v30;
    *(__m128*)&v60 = *(__m128*)&a5->v40;
    p6 = a6;
    struct
    {
        float len;
        float f14;
    } t;
    t.f14 = a3->f14;
    S_00cfaed0_Locals L;
    S_00cfaed0_Info& info = L.info;
    __m128 d = _mm_sub_ps(*(__m128*)&a3->v, *(__m128*)&a2->unk08->v30);
    *(__m128*)&v70 = d;
    _mm_store_ss(&t.len, S_00cfaed0_LengthV(d));
    f84 = t.len;
    *(float*)&u28 = t.f14;
    S_00cfaed0_Out& out = L.out;
    a2->unk00->v07(a2->unk08, a3->f14, &out);
    S_00cfaed0_Vec& oa = *(S_00cfaed0_Vec*)&out.a;
    S_00cfaed0_Vec& ob = *(S_00cfaed0_Vec*)&out.b;
    S_00cfaed0_Real h1(DAT_01016248), h2(DAT_01016248);
    S_00cfaed0_Vec pos;
    pos.setInterpolate4(oa, ob, h1);
    f80 = a3->f10;
    *(__m128*)&info.pos = pos.q;
    *(__m128*)&info.sum = _mm_add_ps(pos.q, d);
    info.param = a7;
    S_00cfaed0_Vec d2;
    d2.setSub4(ob, oa);
    ((S_00cfaed0_Vec*)&info.dir)->setMul4(h2, d2);
    p1->v1b(&info, this);
}
