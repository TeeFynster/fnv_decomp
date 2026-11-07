
// src/havok/common/base/math/quaternion/hkquaternion_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/math/quaternion/hkquaternion_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/base/math/quaternion/hkquaternion_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/quaternion/hkquaternion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/base/math/quaternion/hkquaternion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/quaternion/hkquaternion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
/* PACKET-DECLARATIONS IS PROVIDED BY THE CHECKER; DO NOT INCLUDE IT IN YOUR SUBMISSION.
   Only submit the TARGET definition and any genuinely missing declarations that are required
   for compilation. Do not write or repeat packet-declarations, nor any headers that might
   be present in the checker's context. */
class FUN_005611c0_t
{
  public:
    void normalize_005611c0();
    void hkQuaternion_setAndNormalize(float* pts);
};
static float g_sink2550;
extern "C" double cb2550_clobber(double x);
// src: COMMUNITY 0x00cb2550
static __declspec(noinline) void quaternionFromRotatation(FUN_005611c0_t* obj, float* pts)
{
    float s = pts[0] * pts[1];
    s = (float)cb2550_clobber(s);
    s += pts[5];
    g_sink2550 = s;
    if (s > 1.0e9f)
        *(int*)obj = 0;
}
#include <xmmintrin.h>
#include <math.h>
struct FUN_00cb24c0_cls
{
    __m128 m_00;
    void hkVector4_isOk4(unsigned char* flag);
    unsigned char* IsNormalized(unsigned char* flag);
};
struct Block64
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
    __m128 v3;
};
struct SubObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    void CallSub(Block64* p);
};
__declspec(align(16)) struct FUN_00cf5950_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    SubObj m_sub;
    Block64 m_block;

    void CopyBlock(Block64* src);
};
struct S00cb2550_V4
{
    union
    {
        __m128 q;
        float v[4];
    };
};
struct S00cb2550_Rot
{
    float m[3][4];
    float operator()(int r, int c) const
    {
        return m[c][r];
    }
};
struct S00cb2550_Quat
{
    S00cb2550_V4 q;
};
static void quaternionFromRotatation(S00cb2550_Quat* self, const S00cb2550_Rot& r);
void S00cb2550_caller(S00cb2550_Quat* q, const S00cb2550_Rot& r);
#include <xmmintrin.h>
#include <math.h>

#include <xmmintrin.h>
#include <math.h>
float __cdecl ClampedAcos(float x);
extern float DAT_01012054;
extern double DAT_010c8758;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
inline __m128 scalar(float f)
{
    return _mm_load_ss(&f);
}
class Rotation
{
  public:
    __m128 m_v;
    void D3D_ComputeClearColor(const __m128* a, const __m128* b, float t);
};
// @fnv 0x00cb2850
// src: XBOX_PDB 0x00cb2850
void Rotation::D3D_ComputeClearColor(const __m128* a, const __m128* b, float t)
{
    __m128 va = *a;
    __m128 vb = *b;
    __m128 products = _mm_mul_ps(vb, va);
    __m128 sum = _mm_add_ps(products, _mm_shuffle_ps(products, products, 0x4e));
    sum = _mm_add_ps(sum, _mm_shuffle_ps(sum, sum, 0xb1));
    float dot;
    float d;
    _mm_store_ss(&dot, sum);
    d = dot;
    float sign = 1.0f;
    if (dot < 0.0f)
    {
        d = -dot;
        sign = DAT_01012054;
    }
    __m128 result;
    if (d < DAT_010c8758)
    {
        float angle = ClampedAcos(d);
        float inverse = 1.0f / sqrtf(1.0f - d * d);
        float angle_t = angle * t;
        __m128 first_vector = scalar(sinf(angle - angle_t) * inverse);
        float second = sinf(angle_t) * inverse;
        __m128 weighted_first = _mm_mul_ps(_mm_shuffle_ps(first_vector, first_vector, 0), va);
        __m128 second_vector = scalar(second * sign);
        result = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(second_vector, second_vector, 0), vb), weighted_first);
    }
    else
    {
        __m128 first_vector = scalar(1.0f - t);
        __m128 second_vector = scalar(t * sign);
        result = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(second_vector, second_vector, 0), vb),
                            _mm_mul_ps(_mm_shuffle_ps(first_vector, first_vector, 0), va));
    }
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 zero = _mm_set_ss(DAT_01011d78);
    __m128 squares = _mm_mul_ps(result, result);
    __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(squares, squares, 0x4e), squares);
    __m128 norm_sum = _mm_add_ps(sum0, _mm_shuffle_ps(sum0, sum0, 0xb1));
    __m128 is_zero = _mm_cmpeq_ss(norm_sum, zero);
    __m128 reciprocal = _mm_rsqrt_ss(norm_sum);
    __m128 corrected = _mm_mul_ss(_mm_mul_ss(half, reciprocal),
                                  _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(norm_sum, reciprocal), reciprocal)));
    corrected = _mm_andnot_ps(is_zero, corrected);
    __m128 scale = _mm_shuffle_ps(corrected, corrected, 0);
    m_v = _mm_mul_ps(scale, result);
}
