
// src/havok/physics/collide/shape/convex/triangle/hkptriangleshape_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/triangle/hkptriangleshape_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/convex/triangle/hkptriangleshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/triangle/hkptriangleshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/shape/convex/triangle/hkptriangleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/triangle/hkptriangleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpTriangleShape.h"
extern char const* const g_01268970_arg1;
void __cdecl hkReferencedObject_calcContentStatistics(char const*, char const* const*);
void __cdecl hkpTriangleShape_calcContentStatistics(char const* arg1, char const* const* arg2);
class FUN_00d1ff10_cls : public hkpTriangleShape
{
  public:
    int FUN_00d1ff10();
};
static int __cdecl getSingleEdgeBitcode(unsigned short weldingInfo, int edge);
int __cdecl ExtractEdge(unsigned short weldingInfo, int edge);

#include <xmmintrin.h>

extern "C" unsigned int DAT_011b3b4c[];
extern "C" float DAT_011b3b20[];

struct FUN_00d20370_Triangle
{
    __m128 unknown00;
    __m128 unknown10;
    __m128 vertexA;
    __m128 vertexB;
    __m128 vertexC;
    __m128 extrusion;

    void __thiscall hkpTriangleShape_convertVertexIdsToVerticesImpl(const unsigned short* indexes, int count, __m128* output);
};

// @fnv 0x00d20370
// src: XBOX_PDB 0x00d20370
void __thiscall FUN_00d20370_Triangle::hkpTriangleShape_convertVertexIdsToVerticesImpl(const unsigned short* indexes, int count, __m128* output)
{
    for (int remaining = count - 1; remaining >= 0; --remaining)
    {
        const __m128* src = (const __m128*)((const char*)this + (DAT_011b3b4c[*indexes] + 2) * 16);
        __m128 original = *src;
        *output = original;

        __m128 a = _mm_load_ss(&DAT_011b3b20[*indexes]);
        __m128 b = _mm_shuffle_ps(a, a, 0);
        *output = _mm_add_ps(_mm_mul_ps(b, extrusion), original);
        ((unsigned int*)output)[3] = (unsigned int)(*indexes) | 0x3f000000u;

        output += 1;
        indexes += 1;
    }
}
