#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/staging/blk_00e40000_od_o2_nood_variant_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00e40000_od_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FloatLess
{
    bool operator()(const float& a, const float& b) const
    {
        return a < b;
    }
};
void __cdecl hkAlgorithm_quickSortRecursive_float_class_hkAlgorithm_less_float(float* pArr, int d, int h, FloatLess cmpLess);
typedef ::__m128 LocalM128;
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_mul_ss;
using ::_mm_shuffle_ps;
using ::_mm_movemask_ps;
static inline LocalM128 Dot3v(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
static inline LocalM128 Dot3_e4b570(LocalM128 p)
{
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
int __cdecl Runtime_ProcessEntries_00e4b570(const LocalM128* point, const LocalM128* verts, float* out);

extern "C" double __cdecl sqrt(double);

using ::_mm_and_ps;
using ::_mm_store_ps;

struct Quaternion81
{
    float x, y, z, w;
};
// @fnv 0x00e52590
// src: GUESS 0x00e52590 (confidence: low)
void __cdecl Runtime_ComputeValues_00e52590(const Quaternion81* quaternion, unsigned char* packed)
{
    static float scale = static_cast<float>(sqrt(2.0)) * 2047.0;
    const float* components = &quaternion->x;
    __declspec(align(16)) static const unsigned int absMask[4] = {0x7fffffffu, 0x7fffffffu, 0x7fffffffu, 0x7fffffffu};
    __declspec(align(16)) float abs[4];
    _mm_store_ps(abs,
                 _mm_and_ps(*reinterpret_cast<const LocalM128*>(quaternion), *reinterpret_cast<const LocalM128*>(absMask)));
    unsigned int largest = 0;
    if (abs[1] > abs[0])
        largest = 1;
    if (abs[2] > abs[largest])
        largest = 2;
    if (abs[3] > abs[largest])
        largest = 3;
    unsigned int lane = largest == 0;
    short quantized[3];
    quantized[0] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    ++lane;
    lane += lane == largest;
    quantized[1] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    ++lane;
    lane += lane == largest;
    quantized[2] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    packed[0] = static_cast<unsigned char>(quantized[0]);
    packed[1] = static_cast<unsigned char>((quantized[0] >> 8) | (quantized[1] << 4));
    packed[2] = static_cast<unsigned char>(quantized[1] >> 4);
    packed[3] = static_cast<unsigned char>(quantized[2]);
    unsigned int negative = components[largest] < 0.0f;
    packed[4] = static_cast<unsigned char>(((largest | (negative << 2)) << 4) | (quantized[2] >> 8));
}
