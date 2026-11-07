#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpLinkedCollidable.h"


// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// This flag variant only defines FUN_00cfe1d0; the unused parent-unit allocator,
// dispatcher, collidable and narrow-phase track declarations are omitted.

__forceinline void hkVector4::mul(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::add(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
template <int I> __forceinline void hkVector4::splat(const hkVector4& a)
{
    m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, I * 0x55);
}
struct Matrix
{
    hkVector4 c0, c1, c2, c3;
    __forceinline void inversePosition(hkVector4& out, const hkVector4& pos) const
    {
        hkVector4 t;
        t.m_vComponents = pos.m_vComponents;
        t.m_vComponents = _mm_sub_ps(t.m_vComponents, c3.m_vComponents);
        hkVector4 a = c0, b = c1, c = c2;
        __m128 lo = _mm_unpacklo_ps(a.m_vComponents, b.m_vComponents);
        __m128 hi = _mm_unpackhi_ps(a.m_vComponents, b.m_vComponents);
        a.m_vComponents = _mm_movelh_ps(lo, c.m_vComponents);
        b.m_vComponents = _mm_shuffle_ps(_mm_movehl_ps(a.m_vComponents, lo), c.m_vComponents, 0xd4);
        c.m_vComponents = _mm_shuffle_ps(hi, c.m_vComponents, 0xe4);
        hkVector4 x, y;
        y.splat<1>(t);
        y.mul(y, b);
        x.splat<0>(t);
        t.splat<2>(t);
        x.mul(x, a);
        c.mul(c, t);
        y.add(y, x);
        out.add(y, c);
    }
};

struct Node;
struct Entry
{
    Node* node;
    int unk4;
    hkVector4* data;
    Entry* parent;
};
struct Node
{
    int unk00;
    int unk04;
    int unk08;
    int type;
    int unk10;
    Node* next;
    int unk18;
    int unk1c;
    hkVector4 v20;
    Matrix rows;
};
// @fnv 0x00cfe1d0
// src: XBOX_PDB 0x00cfe1d0
Entry* __cdecl hkAgentMachine_processTransformedShapes(Entry* h, Entry* out, hkVector4* b, unsigned int n, unsigned char* c)
{
    Node* node = h->node;
    if (node->type == 0xf)
    {
        hkVector4* dst = b + 6;
        do
        {
            hkVector4* m = h->data;
            __m128 m0 = m[0].m_vComponents;
            __m128 m1 = m[1].m_vComponents;
            __m128 m2 = m[2].m_vComponents;
            char* rows = (char*)&node->rows;
            int cnt = 3;
            char* src = rows + 3 * sizeof(hkVector4);
            int delta = (int)b;
            do
            {
                __m128 v = *(__m128*)src;
                __m128 x = _mm_shuffle_ps(v, v, 0);
                __m128 y = _mm_shuffle_ps(v, v, 0x55);
                __m128 z = _mm_shuffle_ps(v, v, 0xaa);
                *(__m128*)(src - (int)rows + delta) =
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, m1), _mm_mul_ps(x, m0)), _mm_mul_ps(z, m2));
                --cnt;
                src -= sizeof(hkVector4);
            } while (cnt >= 0);
            _mm_store_ps(&dst[-3].x, _mm_add_ps(_mm_load_ps(&m[3].x), _mm_load_ps(&dst[-3].x)));
            dst[-2].m_vComponents = m[4].m_vComponents;
            dst[-1].m_vComponents = m[5].m_vComponents;
            dst->setMul(m + 6, &node->v20);
            (dst + 1)->setMul(m + 7, &node->v20);

            Entry* a = out;
            node->rows.inversePosition(dst[2], m[8]);
            dst[3].m_vComponents = m[9].m_vComponents;
            dst[4].x = m[10].x;

            if (a != 0)
            {
                a->parent = h;
                a->data = b;
            }
            Node* next = node->next;
            b += 11;
            dst += 11;
            a->node = next;
            a->unk4 = 0;
            h = out++;
            node = h->node;
            *c = 8;
        } while (node->type == 0xf);
    }
    return h;
}
