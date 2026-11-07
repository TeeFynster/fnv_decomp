#include <xmmintrin.h>
typedef ::__m128 LocalM128;

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
    LocalM128 m_00;
    void hkVector4_isOk4(unsigned char* flag);
    unsigned char* IsNormalized(unsigned char* flag);
};
struct Block64
{
    LocalM128 v0;
    LocalM128 v1;
    LocalM128 v2;
    LocalM128 v3;
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
        LocalM128 q;
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
namespace fnv_00cb2700 {
typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_setzero_ps;
using ::_mm_store_ps;
using ::_mm_load_ps;
using ::_mm_mul_ps;
using ::_mm_shuffle_ps;
using ::_mm_add_ss;
using ::_mm_set_ss;
using ::_mm_cmpeq_ss;
using ::_mm_rsqrt_ss;
using ::_mm_mul_ss;
using ::_mm_sub_ss;
using ::_mm_andnot_ps;
}

union VecStorage
{
    LocalM128 quad;
    float axis[4];
};

struct PerpendicularVector
{
    LocalM128 m_result;

    void hkQuaternionf_setFlippedRotation(const float* v);
};

extern "C" double fabs(double);
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern "C" void _ReadWriteBarrier();

static __forceinline LocalM128 inverse_length(LocalM128 t)
{
    LocalM128 mask = _mm_cmpeq_ss(t, _mm_set_ss(0.0f));
    LocalM128 inv = _mm_rsqrt_ss(t);
    LocalM128 xi = _mm_mul_ss(_mm_mul_ss(t, inv), inv);
    LocalM128 yy = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inv), _mm_sub_ss(_mm_set_ss(DAT_01017718), xi));
    return _mm_andnot_ps(mask, yy);
}

// @fnv 0x00cb2700
// src: COMMUNITY 0x00cb2700
void PerpendicularVector::hkQuaternionf_setFlippedRotation(const float* v)
{
    VecStorage w;
    float a;
    float b;
    float c;
    int i0 = 0;
    int i1 = i0 + 1;
    int i2 = i0 + 2;

    {
        volatile float rounded = (float)fabs((double)v[0]);
        a = rounded;
    }
    {
        volatile float rounded = (float)fabs((double)v[1]);
        b = rounded;
    }
    {
        volatile float rounded = (float)fabs((double)v[2]);
        c = rounded;
    }

    if (b < a)
    {
        a = b;
        i1 = 0;
        i0 = i2 - 1;
    }
    if (c < a)
    {
        i2 = i0;
    }

    w.quad = _mm_setzero_ps();
    w.axis[i1] = v[i2];
    w.axis[i2] = -v[i1];

    float zz = 0.0f;
    LocalM128 sq = _mm_mul_ps(w.quad, w.quad);
    LocalM128 p1 = _mm_shuffle_ps(sq, sq, 0x55);
    LocalM128 p2 = _mm_shuffle_ps(sq, sq, 0xaa);
    LocalM128 t = _mm_add_ss(p1, sq);
    t = _mm_add_ss(p2, t);

    LocalM128 s = inverse_length(t);

    LocalM128 sv = _mm_shuffle_ps(s, s, 0);
    LocalM128 r = _mm_mul_ps(sv, w.quad);
    r.m128_f32[3] = zz;
    m_result = r;
}
}  // namespace fnv_00cb2700
