
// src/havok/common/base/math/quaternion/hkquaternion_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/math/quaternion/hkquaternion.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

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

__declspec(align(16)) struct FUN_00cb2450_cls
{
    __m128 m_00;
    void hkQuaternion_setAxisAngle(__m128* v, float a1);
};
struct LFrame
{
    float unk04;
    float x;
    volatile float s;
};
// @fnv 0x00cb2450
// src: XBOX_PDB 0x00cb2450
void FUN_00cb2450_cls::hkQuaternion_setAxisAngle(__m128* v, float a1)
{
    LFrame f;
    f.x = (float)(a1 * 0.5);
    f.s = (float)sin((double)f.x);
    f.s = f.s;
    __m128 t = _mm_load_ss((const float*)&f.s);
    __m128 splat = _mm_shuffle_ps(t, t, 0);
    __m128 vv = *v;
    m_00 = _mm_mul_ps(splat, vv);
    f.s = (float)cos((double)f.x);
    ((float*)this)[3] = f.s;
}
