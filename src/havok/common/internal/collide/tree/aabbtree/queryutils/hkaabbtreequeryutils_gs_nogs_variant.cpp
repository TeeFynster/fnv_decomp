#include "../../../../../../../../include/hkArray.h"

// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils_gs_nogs_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d1bb40_Class
{
    int* FUN_00d1bb40(unsigned short index);
};
inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}
struct S_00d1bcb0_Allocator
{
    int unk00;
};
struct S_00d1bcb0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d1bcb0_Allocator* m_pStreamAllocator;
    S_00d1bcb0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00d1bcb0_Router* FUN_00c85750();
void ResizeAudioStream(S_00d1bcb0_Allocator& alloc, void* array, int sizeElem);
struct S_00d1bcb0_Entry
{
    int m_kPointA;
    int m_kPointB;
};
typedef hkArray<S_00d1bcb0_Entry> S_00d1bcb0_Array;
struct S_00d1bcb0
{
    int unk00;
    S_00d1bcb0_Array* m_ppData;
    bool FUN_00d1bcb0(int a, int b);
};
extern int __cdecl FUN_00d1c560(void*, int, int, int, int, int);
int __cdecl CallWithDefaults(void* arg0, int arg1, int arg2);
int __cdecl FUN_00d1c560(void* a, void* b, int c, int d, void* e, void* f);
int __cdecl FUN_00d1d4d0(void* a, void* b, void* e, void* f);
extern int __cdecl FUN_00d1c560(void*, int, int, int, int, int);
int __cdecl FUN_00d1d500(void* arg0, int arg1, int arg2);
extern "C" void* __cdecl FUN_00d1ce50(void* p, int a, int b, int c, int d, int e);
// @fnv 0x00d1d540
extern "C" void* __cdecl FUN_00d1d540(void* p, int a, int d, int e)
{
    if (!p)
        return 0;
    return FUN_00d1ce50(p, a, 0, 0, d, e);
}

extern "C" void* __cdecl FUN_00d1d240(void* p, int a, int b, int c, int d, int e);
// @fnv 0x00d1d570
extern "C" void* __cdecl FUN_00d1d570(void* p, int a, int b)
{
    if (!p)
        return p;
    return FUN_00d1d240(p, a, b, 0, 0, 0);
}

extern "C" void __cdecl FUN_00d1ca00();
// @fnv 0x00d1d530
extern "C" void __cdecl FUN_00d1d530()
{
    FUN_00d1ca00();
}

#include <xmmintrin.h>
struct BoundVector
{
    __m128 value;
    __forceinline BoundVector(__m128 a) : value(a)
    {}
};

struct Node
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
    unsigned short m_childIndex;
    unsigned short m_unk22;
    unsigned short m_flags;
    unsigned short m_siblingIndex;
};

struct RayTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d1bb40_Class nodes;
};

struct RayQuerySet
{
    __m128 m_vRayOrigins[3];
    __m128 m_vInverseDirection[3];
    int m_activeRays;
};

struct RayCollector
{
    virtual ~RayCollector();
    virtual float GetHitDistance(const Node* node);
};

extern const __m128 kZero;
extern const __m128 kActiveMasks[];
extern const int kBitMasks[];

// @fnv 0x00d1ca00
void FUN_00d1ca00(RayTree* tree, Node* node, Node* endNode, const RayQuerySet* rayBundle, RayCollector** collectors,
                  const float* maxDistances)
{
    __m128 maxT = _mm_setr_ps(maxDistances[0], maxDistances[1], maxDistances[2], maxDistances[3]);

    for (;;)
    {
        BoundVector bounds[2] = {node->m_kMinimumCorner, node->m_kMaximumCorner};

        Node* nextNode;
        if (node->m_siblingIndex != 0x7fff)
            nextNode = (Node*)tree->nodes.FUN_00d1bb40(node->m_siblingIndex);
        else
            nextNode = 0;

        __m128 minSplat[3];
        __m128 maxSplat[3];

        maxSplat[0] = _mm_shuffle_ps(bounds[1].value, bounds[1].value, 0);
        maxSplat[1] = _mm_shuffle_ps(bounds[1].value, bounds[1].value, 0x55);
        maxSplat[2] = _mm_shuffle_ps(bounds[1].value, bounds[1].value, 0xaa);

        minSplat[0] = _mm_shuffle_ps(bounds[0].value, bounds[0].value, 0);
        minSplat[1] = _mm_shuffle_ps(bounds[0].value, bounds[0].value, 0x55);
        minSplat[2] = _mm_shuffle_ps(bounds[0].value, bounds[0].value, 0xaa);

        __m128 fNearT[3];
        __m128 fFarT[3];

        for (int i = 0; i < 3; ++i)
        {
            __m128 t0 =
                _mm_mul_ps(_mm_sub_ps(minSplat[i], rayBundle->m_vRayOrigins[i]), rayBundle->m_vInverseDirection[i]);
            __m128 t1 =
                _mm_mul_ps(_mm_sub_ps(maxSplat[i], rayBundle->m_vRayOrigins[i]), rayBundle->m_vInverseDirection[i]);
            fNearT[i] = _mm_min_ps(t0, t1);
            fFarT[i] = _mm_max_ps(t0, t1);
        }

        int activeRays = rayBundle->m_activeRays;
        __m128 tEnter = _mm_max_ps(_mm_max_ps(_mm_max_ps(fNearT[0], fNearT[1]), fNearT[2]), kZero);
        __m128 tExit = fFarT[0];
        tExit = _mm_min_ps(tExit, fFarT[1]);
        tExit = _mm_min_ps(tExit, fFarT[2]);
        tExit = _mm_min_ps(tExit, maxT);

        __m128 mask = kActiveMasks[activeRays];
        __m128 cmp = _mm_and_ps(_mm_cmplt_ps(tEnter, tExit), mask);
        int hitMask = _mm_movemask_ps(cmp);

        if (activeRays & hitMask)
        {
            if ((node->m_flags & 0x8000) == 0)
            {
                node = (Node*)tree->nodes.FUN_00d1bb40(node->m_childIndex);
                continue;
            }

            for (int r = 0; r < 4; ++r)
            {
                if (kBitMasks[r] & hitMask)
                {
                    ((float*)&maxT)[r] = collectors[r]->GetHitDistance(node);
                }
            }
        }

        if (nextNode == endNode)
            break;
        node = nextNode;
    }
}
