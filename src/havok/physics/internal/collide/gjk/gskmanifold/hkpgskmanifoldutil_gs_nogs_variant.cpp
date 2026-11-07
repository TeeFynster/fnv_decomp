
// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00dad640_Entry
{
    unsigned short unk0;
    unsigned short id;
    unsigned int unk4;
};
struct S_00dad640_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[1];
};
struct S_00dad640_Target
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void Release(unsigned short id, void* arg);
};
void ReleaseAllEntries(S_00dad640_Set* set, S_00dad640_Target* target, void* arg);
struct S_00dad4d0_Key
{
    unsigned short ids[4];
    unsigned char numA;
    unsigned char numB;
};
struct S_00dad4d0_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dad4d0_Raw
{
    unsigned int lo;
    unsigned int hi;
};
struct S_00dad4d0_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad4d0_Entry entries[1];

    unsigned short Id(unsigned char off)
    {
        return *(unsigned short*)((char*)&entries[count] + (off >> 3));
    }
};
bool FindAndPromoteEntry(S_00dad4d0_Set* set, S_00dad4d0_Key* key);
void __fastcall hkGskManifold_garbageCollect(int unused, S_00dad640_Set* set);
void __cdecl _hkGskManifold_removePoint(S_00dad640_Set* set, unsigned int index);

#include <xmmintrin.h>
struct S_00dad6a0_Vec
{
    __m128 m_afExtents[16];
    __m128 m_v100;
    int unk110;
    int unk114;
    int unk118;
    float m_pFreeList;
};

struct S_00dad6a0_Out
{
    __m128 m_v0;
    __m128 m_v10;
    __m128 m_v20;
};

struct S_00dad6a0_Rec
{
    int unk0;
    unsigned char m_kPointA;
    unsigned char m_kPointB;
};
// @fnv 0x00dad6a0
// src: GUESS 0x00dad6a0 (confidence: low)
static __declspec(noinline) int Object_ProcessAndReturnValue_00dad6a0(S_00dad6a0_Rec* rec, S_00dad6a0_Vec* vecs, S_00dad6a0_Out* out)
{
    const __m128& pa = *(__m128*)((char*)vecs + rec->m_kPointA);
    const __m128& pb = *(__m128*)((char*)vecs + rec->m_kPointB);
    __m128 d = _mm_sub_ps(pa, pb);
    __m128 sq = _mm_mul_ps(d, d);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    float f;
    _mm_store_ss(&f, s);
    if (f > vecs->m_pFreeList)
    {
        return 1;
    }
    out->m_v10 = d;
    out->m_v20 = vecs->m_v100;
    out->m_v0 = pa;
    return 0;
}
volatile int g_rec;
volatile int g_vecs;
volatile int g_out;
volatile int g_res;
void CallTarget_dad6a0()
{
    S_00dad6a0_Out* o = (S_00dad6a0_Out*)g_out;
    g_res = Object_ProcessAndReturnValue_00dad6a0((S_00dad6a0_Rec*)g_rec, (S_00dad6a0_Vec*)g_vecs, o);
    g_res = Object_ProcessAndReturnValue_00dad6a0((S_00dad6a0_Rec*)g_rec, (S_00dad6a0_Vec*)g_vecs, o);
}
