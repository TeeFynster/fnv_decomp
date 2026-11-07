
// src/havok/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/havok/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern void __cdecl operator delete(void*);
void __fastcall Object_UpdateFields_0059cf00(void*);
struct HKPCloseStrayHitCollector
{
    void* __thiscall Destroy(unsigned int flags);
};

#include <xmmintrin.h>
void __cdecl CollectValuesReversed(void* dst, unsigned int size, void* src);

struct HKPCloseNode
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    HKPCloseNode* m_0c;
};

struct FUN_00ca9440_src
{
    __m128 m_00;
    float m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
};

struct FUN_00ca9440_cls
{
    unsigned int unk00;
    float m_04;
    __m128 m_10;
    float m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    HKPCloseNode* m_60;

    void hkpClosestRayHitCollector_addRayHit(HKPCloseNode* node, FUN_00ca9440_src* src);
};

// @fnv 0x00ca9440
// src: XBOX_PDB 0x00ca9440
void FUN_00ca9440_cls::hkpClosestRayHitCollector_addRayHit(HKPCloseNode* node, FUN_00ca9440_src* src)
{
    if (src->m_10 < m_20)
    {
        m_10 = src->m_00;
        m_20 = src->m_10;
        m_24 = src->m_14;
        m_28 = src->m_18;
        m_2c = src->m_1c;
        CollectValuesReversed(&m_30, 8, node);
        HKPCloseNode* last = node;
        while (last->m_0c)
            last = last->m_0c;
        m_60 = last;
        m_04 = src->m_10;
    }
}
