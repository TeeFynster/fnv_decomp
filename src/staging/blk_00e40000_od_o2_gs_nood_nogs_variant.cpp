#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/staging/blk_00e40000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkQuaternion.h"

#include <xmmintrin.h>
#include <math.h>
struct RotationVector
{
    LocalM128 m_vComponents;
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};
extern const LocalM128 DAT_01017d10;
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
float __cdecl Atan2(float y, float x);

static __forceinline float AbsValue(float r)
{
    return (float)fabs(r);
}
static __forceinline float SafeAcos(float r)
{
    if (AbsValue(r) >= 1.0f)
    {
        r = r > 0.0f ? 0.0f : 3.1415927410125732421875f;
        return r;
    }
    return (float)acos(r);
}

// @fnv 0x00e52320
// src: GUESS 0x00e52320 (confidence: low)
void __cdecl Object_UpdateFields_00e52320(const RotationVector* rotation, unsigned int* packed)
{
    RotationVector value = *rotation;
    *packed = 0;
    int sx = value(0) < 0.0f ? 1 : 0;
    int sy = value(1) < 0.0f ? 1 : 0;
    int sz = value(2) < 0.0f ? 1 : 0;
    int sw = value(3) < 0.0f ? 1 : 0;
    *packed = (sx | sy << 1 | sz << 2 | sw << 3) << 28;
    value.m_vComponents = _mm_and_ps(DAT_01017d10, value.m_vComponents);
    float magnitude = value(3);
    if (value(0) != 0.0f || value(1) != 0.0f || value(2) != 0.0f)
    {
        LocalM128 lanes = value.m_vComponents;
        LocalM128 squared = _mm_mul_ps(lanes, lanes);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), sum);
        LocalM128 estimate = _mm_rsqrt_ss(sum);
        LocalM128 mask = _mm_cmpeq_ss(sum, _mm_set_ss(DAT_01011d78));
        squared = _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(sum, estimate), estimate));
        sum = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), estimate), squared));
        value.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(sum, sum, 0), lanes);
        float angle = SafeAcos(value(2));
        int latitude = (int)(angle * 2.0 / 3.1415927410125732421875 * 511.0 + 0.5);
        int columns = latitude * 2;
        int longitude = (int)(Atan2(value(1), value(0)) * 2.0f / 3.1415927410125732421875f * columns + 0.5);
        int direction = longitude + latitude * latitude;
        magnitude = (float)sqrt(1.0f - magnitude);
        *packed |= ((unsigned int)(magnitude * 1023.0 + 0.5) << 18) | direction;
    }
}

namespace fnv_00e526f0 {
typedef ::__m128 LocalM128;

extern "C"
{
using ::_mm_and_ps;
    double __cdecl sqrt(double);
}

extern const LocalM128 DAT_01017d10;

// @fnv 0x00e526f0
// src: GUESS 0x00e526f0 (confidence: low)
void __cdecl hkQuaternion_ComputeValues_00e526f0(const hkQuaternion* q, short* out)
{
    extern float packingScale;
    extern unsigned int scaleInitialized;
    if ((scaleInitialized & 1) == 0)
    {
        scaleInitialized |= 1;
        packingScale = float(sqrt(2.0)) * 16383.0;
    }
    LocalM128 a = _mm_and_ps(*reinterpret_cast<const LocalM128*>(&q->unk00), DAT_01017d10);
    short largest = 0;
    if (a.m128_f32[1] > a.m128_f32[0])
        largest = 1;
    if (a.m128_f32[2] > a.m128_f32[largest])
        largest = 2;
    if (a.m128_f32[3] > a.m128_f32[largest])
        largest = 3;

    int L = largest;
    int i = (L == 0);
    short v[3];
    v[0] = (short)(int)(reinterpret_cast<const float*>(&q->unk00)[i] * packingScale) + 0x3fff;
    i++;
    i += (i == L);
    v[1] = (short)(int)(reinterpret_cast<const float*>(&q->unk00)[i] * packingScale) + 0x3fff;
    i++;
    i += (i == L);
    v[2] = (short)(int)(reinterpret_cast<const float*>(&q->unk00)[i] * packingScale) + 0x3fff;

    out[0] = (short)((largest << 15) | v[0]);
    out[1] = (short)(((largest >> 1) << 15) | v[1]);
    int sign = (reinterpret_cast<const float*>(&q->unk00)[L] < 0.0f) ? 1 : 0;
    out[2] = (short)((sign << 15) | v[2]);
}
}  // namespace fnv_00e526f0

union __declspec(align(16)) PackedQuaternionOutput
{
    LocalM128 simd;
    float components[4];
};
// @fnv 0x00e52920
// src: GUESS 0x00e52920 (confidence: low)
void Object_UpdateFields_00e52920(const unsigned char* p, PackedQuaternionOutput* output)
{
    static float scale;
    extern unsigned int scaleInitialized;
    if ((scaleInitialized & 1) == 0)
    {
        scaleInitialized |= 1;
        scale = (float)(1.0 / ((float)sqrt(2.0) * 63.0));
    }
    struct
    {
        short a, b, c;
    } v;
    v.a = (short)(p[0] & 0x7f);
    v.b = (short)(p[1] & 0x7f);
    v.c = (short)(p[2] & 0x7f);
    unsigned int missing = ((p[1] & 0x80) | (p[0] >> 1)) >> 6;
    output->simd = _mm_setzero_ps();
    unsigned int index = missing == 0;
    output->components[index] = (v.a - 63) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.b - 63) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.c - 63) * scale;
    float remainder = 1.0f - output->components[0] * output->components[0] -
                      output->components[1] * output->components[1] - output->components[2] * output->components[2] -
                      output->components[3] * output->components[3];
    output->components[missing] = sqrtf(remainder);
    if (p[2] & 0x80)
        output->components[missing] = -output->components[missing];
}

namespace fnv_00e52c30 {
union __declspec(align(16)) PackedQuaternionOutput
{
    LocalM128 simd;
    float components[4];
};
// @fnv 0x00e52c30
// src: GUESS 0x00e52c30 (confidence: low)
void Runtime_ComputeValues_00e52c30(const unsigned char* p, PackedQuaternionOutput* output)
{
    static float scale;
    extern unsigned int scaleInitialized;
    if ((scaleInitialized & 1) == 0)
    {
        scaleInitialized |= 1;
        scale = (float)(1.0 / ((float)sqrt(2.0) * 2047.0));
    }
    struct
    {
        short a, b, c;
    } v;
    v.a = (short)(((p[1] & 0x0f) << 8) | p[0]);
    v.b = (short)((p[2] << 4) | ((p[1] & 0xf0) >> 4));
    v.c = (short)(((p[4] & 0x0f) << 8) | p[3]);
    unsigned int missing = (p[4] >> 4) & 3;
    output->simd = _mm_setzero_ps();
    unsigned int index = missing == 0;
    output->components[index] = (v.a - 2047) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.b - 2047) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.c - 2047) * scale;
    float remainder = 1.0f - output->components[0] * output->components[0] -
                      output->components[1] * output->components[1] - output->components[2] * output->components[2] -
                      output->components[3] * output->components[3];
    output->components[missing] = sqrtf(remainder);
    if (p[4] & 64)
        output->components[missing] = -output->components[missing];
}
}  // namespace fnv_00e52c30

struct FNV_ALIGN(16) hkpMoppObbVirtualMachine_queryObb
{
    int m[16];
    void Query(int a1, int a2, int a3, float a4, int a5);
};

// @fnv 0x00e5cfe0
// src: HAVOK_LIB 0x00e5cfe0
void _hkMoppObbVirtualMachine_queryObb(int a1, int a2, int a3, float a4, int a5)
{
    hkpMoppObbVirtualMachine_queryObb obj;
    obj.Query(a1, a2, a3, a4, a5);
}
