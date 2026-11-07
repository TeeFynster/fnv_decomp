
// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/kdtreecollector/hkpkdtreecollidableraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/Vec4.h"

struct FUN_00d97a10_Class
{
    void hkKdTreeCollidableRayBundleCaster_getHitFractions(float* p) const;
};
struct S_00d979e0_Inner
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
};
struct S_00d979e0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d979e0_Inner* unk10;
    float hkpKdTreeCollidableRaycaster_getHitFraction() const;
};
struct S_00d98300_Entry
{
    float m_00;
    int m_04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int m_30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    void reset()
    {
        m_00 = 1.0f;
        m_04 = -1;
        m_30 = 0;
        m_10 = -1;
    }
};
struct S_00d98300
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d98300_Entry m_entries[4];
    void ResetEntries();
};
struct NestedFlagBlock
{
    unsigned long blk_00;  // 0x00
    unsigned long blk_04;  // 0x04
    unsigned long blk_08;  // 0x08
    unsigned long blk_0c;  // 0x0c
    unsigned long blk_10;  // 0x10
    unsigned long blk_14;  // 0x14
    unsigned long blk_18;  // 0x18
    unsigned long blk_1c;  // 0x1c
    unsigned long blk_20;  // 0x20
    unsigned long blk_24;  // 0x24
    unsigned long blk_28;  // 0x28
    unsigned long blk_2c;  // 0x2c
    unsigned long blk_30;  // 0x30
    unsigned long blk_34;  // 0x34
    unsigned long blk_38;  // 0x38
    unsigned long blk_3c;  // 0x3c
    unsigned long blk_40;  // 0x40
    unsigned long blk_44;  // 0x44
    unsigned long blk_48;  // 0x48
    unsigned long blk_4c;  // 0x4c
    unsigned long flag;    // 0x50
};
struct FUN_00d979c0_Class
{
    unsigned long dword_00;   // 0x00
    unsigned long dword_04;   // 0x04
    unsigned long dword_08;   // 0x08
    unsigned long dword_0c;   // 0x0c
    NestedFlagBlock* nested;  // 0x10

    bool* GetFlag(bool* out);
};
struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};
struct FUN_00d979f0_cls : SpawnedBase
{
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;

    FUN_00d979f0_cls* ResetFields() throw();
};
// Scalar deleting destructor of a small polymorphic Havok helper with an empty destructor.
void __cdecl operator delete(void* pvMem);
class FUN_00d979a0
{
// @fnv 0x00d979a0
  public:
    FUN_00d979a0()
    {}
    virtual ~FUN_00d979a0()
    {}

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    static void operator delete(void*, void*)
    {}

    int m_iData;
};
void* D979A0Make(void* pvMem)
{
    return new (pvMem) FUN_00d979a0;
}
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct S00d97bf0_Rec
{
    const char* name;
    unsigned int tsc;
    unsigned int unk08;
};
struct S00d97bf0_Pool
{
    void* unk00;
    S00d97bf0_Rec* cur;
    void* unk08;
    S00d97bf0_Rec* end;
};
struct S00d97bf0_Obj;
void __cdecl hkKdTreeUtils_castRayIterative(int* p, int a, int b, int c, S00d97bf0_Obj* d);
struct S00d97bf0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2(int a);

    int m04;
    int m08;
    int m0C;
    int m10;

    int __thiscall hkpKdTreeCollidableRaycaster_castRayIterative(int a0, int a1, int a2, int a3);
};
struct D98360Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct D98360MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D98360Allocator* m_pStreamAllocator;

    D98360Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" D98360MemoryRouter& __cdecl hkMemoryRouter_getInstance();
struct D98360Base
{
    virtual ~D98360Base()
    {}

    int unk04;
};
struct FUN_00d98360 : D98360Base
{
    int unk08;
    int unk0C;
    int unk10;

    FUN_00d98360();
    virtual ~FUN_00d98360();

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, nbytes);
    }
};
FUN_00d98360::FUN_00d98360()
{}

#include <xmmintrin.h>
extern float DAT_01012054;
extern float DAT_01012068;
extern int DAT_010c92e0[4];
struct Mat4
{
    __m128 r0;
    __m128 r1;
    __m128 r2;
    __m128 r3;
};
struct Entry30
{
    __m128 a;
    __m128 b;
    int f20;
    int f24;
    int f28;
};
struct SubObj
{
    virtual void Vf0();
    virtual char* Query(char* out, Entry30* e, void* a0);
};
struct __declspec(align(16)) CandF
{
    float v0[4];
    float score;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
};
struct DestEnt
{
    CandF c;
    void* owner;
    int f58;
    int f5c;
    __forceinline void Copy(const DestEnt& source)
    {
        DestEnt& d = *this;
        const CandF& c = source.c;
        _mm_store_ps(d.c.v0, _mm_load_ps(c.v0));
        d.c.score = c.score;
        d.c.f14 = c.f14;
        d.c.f18 = c.f18;
        d.c.f1c = c.f1c;
        d.c.f20 = c.f20;
        d.c.f24 = c.f24;
        d.c.f28 = c.f28;
        d.c.f2c = c.f2c;
        d.c.f30 = c.f30;
        d.c.f34 = c.f34;
        d.c.f38 = c.f38;
        d.c.f3c = c.f3c;
        d.c.f40 = c.f40;
        d.owner = source.owner;
    }
};
struct __declspec(align(16)) PtsBlockF
{
    __m128 v[6];
    int t60;
    int t64;
    int t68;
    int t6c;
};
struct HeadObj
{
    virtual void Vf0();
    virtual void Vf1();
    virtual void Vf2();
    virtual void Vf3();
    virtual void Vf4();
    virtual void Vf5();
    virtual void Vf6();
    virtual void Vf7();
    virtual void Vf8();
    virtual void Vf9();
    virtual Vec4 Eval(PtsBlockF* pts, CandF* cands, float* mask);
};
struct Arg0
{
    HeadObj* head;
    int unk04;
    Mat4* mat;
};
static __forceinline Vec4 Xform(const Mat4& m, __m128 p)
{
    __m128 d = _mm_sub_ps(p, m.r3);
    __m128 r0 = m.r0;
    __m128 r1 = m.r1;
    __m128 r2 = m.r2;
    __m128 low = _mm_unpacklo_ps(r0, r1);
    __m128 high = _mm_unpackhi_ps(r0, r1);
    r0 = _mm_movelh_ps(low, r2);
    r1 = _mm_shuffle_ps(_mm_movehl_ps(r0, low), r2, 0xd4);
    r2 = _mm_shuffle_ps(high, r2, 0xe4);
    __m128 mx = _mm_mul_ps(r0, _mm_shuffle_ps(d, d, 0));
    __m128 my = _mm_mul_ps(r1, _mm_shuffle_ps(d, d, 0x55));
    __m128 mz = _mm_mul_ps(r2, _mm_shuffle_ps(d, d, 0xaa));
    __declspec(align(16)) Vec4 result;
    *reinterpret_cast<__m128*>(&result) = _mm_add_ps(_mm_add_ps(mx, my), mz);
    return result;
}
static __forceinline __m128 Rotate(const Mat4& m, __m128 p)
{
    return _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0x55), m.r1), _mm_mul_ps(_mm_shuffle_ps(p, p, 0), m.r0)),
        _mm_mul_ps(_mm_shuffle_ps(p, p, 0xaa), m.r2));
}

extern "C" void _WriteBarrier();
struct __declspec(align(16)) ScalarColumn
{
    float x, y, z, w;
};
static __forceinline __m128 Column(const __m128& a, const __m128& b)
{
    return _mm_shuffle_ps(a, b, 0x88);
}
struct ThisCls
{
    int unk00;
    Entry30* entries;
    SubObj* sub;
    int m_0c;
    DestEnt* dest;
    void hkKdTreeCollidableRayBundleCaster_addMidPhaseHit(Arg0* a0, __m128* a1);
};
// @fnv 0x00d97c90
// src: HAVOK_SRC 0x00d97c90
void ThisCls::hkKdTreeCollidableRayBundleCaster_addMidPhaseHit(Arg0* a0, __m128* a1)
{
    HeadObj* head = a0->head;
    if (head == 0)
        return;
    {
        __declspec(align(16)) CandF cands[4];
        Mat4* mat = a0->mat;
        float one = 1.0f;
        PtsBlockF pts;
        pts.t60 = 0;
        pts.t64 = 0;
        __m128 valsV;
        if (sub != 0)
        {
            __declspec(align(16)) float vals[4];
            for (int i = 0; i < 4; i++)
            {
                int mask = _mm_movemask_ps(*a1);
                char outb;
                if ((DAT_010c92e0[i] & mask) != 0 && *sub->Query(&outb, &entries[i], a0) != 0)
                    vals[i] = one;
                else
                    vals[i] = -1.0f;
            }
            valsV = _mm_load_ps(vals);
        }
        else
        {
            valsV = _mm_set1_ps(1.0f);
        }
        __declspec(align(16)) float maskF[4];
        _mm_store_ps(maskF, _mm_cmple_ps(_mm_setzero_ps(), valsV));
        {
            pts.v[0] = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[0].a));
            pts.v[3] = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[0].b));
            pts.v[1] = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[1].a));
            pts.v[4] = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[1].b));
            __m128 t4 = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[2].a));
            pts.v[2] = t4;
            __m128 t5 = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[2].b));
            pts.v[5] = t5;
            __m128 t6 = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[3].a));
            __m128 t7 = *reinterpret_cast<const __m128*>(&Xform(*mat, entries[3].b));
            __m128 t0 = pts.v[0];
            const __m128& t1 = pts.v[3];
            __m128 t2 = pts.v[1];
            __m128 t3 = pts.v[4];
            __m128 low02 = _mm_shuffle_ps(t0, t2, 0x44);
            _WriteBarrier();
            __m128 high02 = _mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(&pts.v[0])),
                                           _mm_load_ps(reinterpret_cast<const float*>(&pts.v[1])), 0xee);
            __m128 low46 = _mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(&pts.v[2])), t6, 0x44);
            const __m128& firstColumn = _mm_shuffle_ps(low02, low46, 0x88);
            __m128 high46 = _mm_shuffle_ps(t4, t6, 0xee);
            pts.v[1] = _mm_shuffle_ps(low02, low46, 0xdd);
            pts.v[2] = _mm_shuffle_ps(high02, high46, 0x88);
            __m128 low13 = _mm_shuffle_ps(t1, t3, 0x44);
            __m128 high13 = _mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(&pts.v[3])),
                                           _mm_load_ps(reinterpret_cast<const float*>(&pts.v[4])), 0xee);
            pts.v[0] = firstColumn;
            __m128 low57 = _mm_shuffle_ps(t5, t7, 0x44);
            __m128 high57 = _mm_shuffle_ps(t5, t7, 0xee);
            pts.v[3] = _mm_shuffle_ps(low13, low57, 0x88);
            pts.v[4] = _mm_shuffle_ps(low13, low57, 0xdd);
            pts.v[5] = _mm_shuffle_ps(high13, high57, 0x88);
            _WriteBarrier();
        }
        pts.t60 = entries[0].f24;
        pts.t64 = m_0c;
        for (int i = 0; i < 4; i++)
        {
            cands[i].score = one;
            cands[i].f14 = -1;
            cands[i].f20 = -1;
            cands[i].f40 = 0;
        }
        head->Eval(&pts, cands, maskF);
        for (int i = 0; i < 4; i++)
        {
            if (cands[i].score < one && cands[i].score < dest[i].c.score)
            {
                dest[i].Copy(*static_cast<DestEnt*>(static_cast<void*>(&cands[i])));
                dest[i].owner = a0;
                *reinterpret_cast<__m128*>(dest[i].c.v0) = Rotate(*mat, _mm_load_ps(cands[i].v0));
            }
        }
    }
}
