#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/staging/blk_00e20000_od_o2_oy_gs_nood_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e20000_od.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /Oy /GS- /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/staging/blk_00e20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_shuffle_ps;
using ::_mm_setzero_ps;
using ::_mm_load_ss;
using ::_mm_store_ps;
}

struct Invert6Vector
{
    union
    {
        LocalM128 quad;
        float component[4];
    };
    __forceinline void multiply(float factor)
    {
        LocalM128 scalar = _mm_load_ss(&factor);
        quad = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), quad);
    }
    __forceinline void addMultiple(float factor, const Invert6Vector& source)
    {
        LocalM128 scalar = _mm_load_ss(&factor);
        quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), source.quad), quad);
    }
};
struct Invert6Block
{
    Invert6Vector column[3];
    __forceinline void setZero()
    {
        column[0].quad = _mm_setzero_ps();
        column[1].quad = _mm_setzero_ps();
        column[2].quad = _mm_setzero_ps();
    }
    __forceinline void setIdentity()
    {
        column[0].quad = _mm_setzero_ps();
        column[1].quad = _mm_setzero_ps();
        _mm_store_ps(column[2].component, _mm_setzero_ps());
        column[0].component[0] = 1.0f;
        column[1].component[1] = 1.0f;
        column[2].component[2] = 1.0f;
    }
};
struct Invert6Matrix
{
    Invert6Block block[2][2];
    __forceinline Invert6Matrix(const Invert6Matrix& source)
    {
        block[0][0].column[0].quad = source.block[0][0].column[0].quad;
        block[0][0].column[1].quad = source.block[0][0].column[1].quad;
        block[0][0].column[2].quad = source.block[0][0].column[2].quad;
        block[0][1].column[0].quad = source.block[0][1].column[0].quad;
        block[0][1].column[1].quad = source.block[0][1].column[1].quad;
        block[0][1].column[2].quad = source.block[0][1].column[2].quad;
        block[1][0].column[0].quad = source.block[1][0].column[0].quad;
        block[1][0].column[1].quad = source.block[1][0].column[1].quad;
        block[1][0].column[2].quad = source.block[1][0].column[2].quad;
        block[1][1].column[0].quad = source.block[1][1].column[0].quad;
        block[1][1].column[1].quad = source.block[1][1].column[1].quad;
        block[1][1].column[2].quad = source.block[1][1].column[2].quad;
    }
    void ProcessEntries_00e29620(const Invert6Matrix& source);
};
// @fnv 0x00e29620
// src: GUESS 0x00e29620 (confidence: low)
void Invert6Matrix::ProcessEntries_00e29620(const Invert6Matrix& source)
{
    Invert6Matrix temporary = source;
    block[0][0].setIdentity();
    block[0][1].setZero();
    block[1][0].setZero();
    block[1][1].setIdentity();
    for (int b = 0; b < 2; ++b)
    {
        for (int i = 0; i < 3; ++i)
        {
            float inverse = 1.0f / temporary.block[b][b].column[i].component[i];
            temporary.block[0][b].column[i].multiply(inverse);
            temporary.block[1][b].column[i].multiply(inverse);
            block[0][b].column[i].multiply(inverse);
            block[1][b].column[i].multiply(inverse);
            for (int k = 0; k < 2; ++k)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (k != b || j != i)
                    {
                        float factor = -temporary.block[b][k].column[j].component[i];
                        temporary.block[0][k].column[j].addMultiple(factor, temporary.block[0][b].column[i]);
                        temporary.block[1][k].column[j].addMultiple(factor, temporary.block[1][b].column[i]);
                        block[0][k].column[j].addMultiple(factor, block[0][b].column[i]);
                        block[1][k].column[j].addMultiple(factor, block[1][b].column[i]);
                    }
                }
            }
        }
    }
}
