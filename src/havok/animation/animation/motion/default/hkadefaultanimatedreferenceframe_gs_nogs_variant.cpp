#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkOstream.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQsTransform.h"

// Definitions retained here so the original inline arithmetic remains available.
inline hkQuaternion::hkQuaternion() {}
inline hkQsTransform::hkQsTransform() {}
inline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
inline hkSimdReal::hkSimdReal(const __m128& x) : v(x) {}
inline float hkSimdReal::getReal() const
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    __m128 m = _mm_mul_ps(v, a.v);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 xy = _mm_add_ss(y, m);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    return hkSimdReal(_mm_add_ss(z, xy));
}
// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00e41080_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float unk30;

    float __thiscall GetUnk30();
};
#include <xmmintrin.h>

struct E41090Bool
{
    char m_cBooleanValue;
    E41090Bool& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};
struct FUN_00e41090
{
    FUN_00e41090();

    int unk00;
    int unk04;
    float unk08;
    int unk0C;
    E41090Bool unk10;
    E41090Bool unk11;
    E41090Bool unk12;
    E41090Bool unk13;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_vStart;
    hkVector4 m_vEnd;
};

#include <math.h>
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkMemoryAllocator.h"




// src: COMMUNITY 0x00c74ac0
__declspec(noinline) void hkQuaternion::setMulInverse(const void* pa, const void* pb) throw()
{
    const __m128 a = *(const __m128*)pa;
    const __m128 b = *(const __m128*)pb;
    __m128 xyz = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)),
                            _mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)));
    __m128 aw = _mm_shuffle_ps(a, a, 0xff);
    aw = _mm_shuffle_ps(aw, aw, 0);
    xyz = _mm_sub_ps(xyz, _mm_mul_ps(aw, b));
    __m128 bw = _mm_shuffle_ps(b, b, 0xff);
    bw = _mm_shuffle_ps(bw, bw, 0);
    xyz = _mm_add_ps(xyz, _mm_mul_ps(bw, a));
    __m128 prod = _mm_mul_ps(a, b);
    __m128 half = _mm_add_ps(_mm_shuffle_ps(prod, prod, 0x4e), prod);
    __m128 dot = _mm_add_ps(_mm_shuffle_ps(half, half, 0xb1), half);
    dot = _mm_shuffle_ps(dot, dot, 0);
    __m128 upper = _mm_unpackhi_ps(xyz, dot);
    *(__m128*)this = _mm_shuffle_ps(xyz, upper, 0xc4);
}


extern "C" void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* mem, void* arr, int newCap, int elemSize) throw();
#include "../../../../../../include/hkArray.h"
struct Config
{
    const hkQsTransform* m_kTransforms;
    int m_numQsTransforms;
    float m_fAnimationDuration;
    int m_iValueAfterAnimationDuration;
    bool m_unk10;
    bool m_unk11;
    bool m_unk12;
    bool m_bFlag13;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_vStart;
    hkVector4 m_vEnd;
};

extern hkError* DAT_01268360;
extern int DAT_01268700;
extern int DAT_010e57a4;
extern const char DAT_010ebe28[], DAT_010ebdec[], DAT_010ebdcc[], DAT_01012630[], DAT_010ebde0[], DAT_010ebd70[];
extern "C" void __cdecl hkaDefaultAnimatedReferenceFrame_project(const Config* cfg, const void* v1, void* outV, const void* v2) throw();
extern "C" void __cdecl hkQsTransform_UpdateState_00e41bf0(void* outTransform, float time, const hkQsTransform* transforms, int numTransforms,
                                     float duration) throw();

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
extern "C" void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* mem, void* arr, int newCap, int elemSize) throw();

class FUN_00e41830
{
  public:
    int* m_ppVirtualMethodTable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_unk08;
    int m_unk0C;
    hkVector4 m_vStart;
    hkVector4 m_vEnd;
    float m_fAnimationDuration;
    hkArray<hkVector4> m_kAnimationVectorSamples;
    FUN_00e41830(const Config& config) throw();
};
static __forceinline float dot3(__m128 a, __m128 b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 m_plus_y = _mm_add_ss(y, m);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    __m128 res = _mm_add_ss(z, m_plus_y);
    float out;
    _mm_store_ss(&out, res);
    return out;
}
static __forceinline __m128 cross(const __m128& a, const __m128& b)
{
    __m128 a_yzx = _mm_shuffle_ps(a, a, 0xc9);
    __m128 b_zxy = _mm_shuffle_ps(b, b, 0xd2);
    __m128 a_zxy = _mm_shuffle_ps(a, a, 0xd2);
    __m128 b_yzx = _mm_shuffle_ps(b, b, 0xc9);
    return _mm_sub_ps(_mm_mul_ps(a_yzx, b_zxy), _mm_mul_ps(a_zxy, b_yzx));
}
static __forceinline float my_fabs(float f)
{
    return fabsf(f);
}

struct AngleRotation
{
    __m128 value;
    int hkQuaternion_decomposeRestAxis(const hkVector4* axis, hkVector4* rest, float* angle) throw();
};
static __forceinline __m128 projectAxis(__m128 value, __m128 axis)
{
    __m128 mul = _mm_mul_ps(value, axis);
    __m128 lo = _mm_add_ss(_mm_shuffle_ps(mul, mul, 0x55), mul);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(mul, mul, 0xaa), lo);
    return _mm_mul_ps(_mm_shuffle_ps(sum, sum, 0), axis);
}
// src: XBOX_PDB 0x00e41220
extern "C" __declspec(noinline) void __cdecl hkaDefaultAnimatedReferenceFrame_project(const Config* cfg, const void* transform, void* prev,
                                                          const void* output) throw()
{
    const hkQsTransform* pose = (const hkQsTransform*)transform;
    hkVector4* result = (hkVector4*)output;
    __m128 up = projectAxis(pose->m_vTranslation.v, cfg->m_vStart.v);
    __m128 side = projectAxis(pose->m_vTranslation.v, cross(cfg->m_vStart.v, cfg->m_vEnd.v));
    __m128 front = projectAxis(pose->m_vTranslation.v, cfg->m_vEnd.v);
    result->v = _mm_setzero_ps();
    if (cfg->m_unk11)
        result->v = _mm_add_ps(result->v, front);
    if (cfg->m_unk10)
        result->v = _mm_add_ps(result->v, up);
    if (cfg->m_unk12)
        result->v = _mm_add_ps(result->v, side);
    if (cfg->m_bFlag13)
    {
        hkVector4 rest;
        float angle;
        ((AngleRotation*)&pose->m_rotation)->hkQuaternion_decomposeRestAxis(&cfg->m_vStart, &rest, &angle);
        float previous = ((const hkVector4*)prev)->v.m128_f32[3];
        while (angle - previous > double(3.14159265358979323846f))
            angle -= double(6.28318530717958647692f);
        while (angle - previous < -double(3.14159265358979323846f))
            angle += double(6.28318530717958647692f);
        result->v.m128_f32[3] = angle;
    }
    else
        result->v.m128_f32[3] = 0.0f;
}

// @fnv 0x00e41830
FUN_00e41830::FUN_00e41830(const Config& config) throw() : m_ppVirtualMethodTable(&DAT_010e57a4), m_sReferenceCount(1)
{
    int numSamples =
        config.m_iValueAfterAnimationDuration == -1 ? config.m_numQsTransforms : config.m_iValueAfterAnimationDuration;
    hkArray<hkVector4>& samples = m_kAnimationVectorSamples;
    m_vStart.v = config.m_vStart.v;
    m_vEnd.v = config.m_vEnd.v;
    float duration = config.m_fAnimationDuration;
    m_fAnimationDuration = duration;
    float dt = duration / (float)(numSamples - 1);
    hkVector4 tempV0;
    hkQsTransform startTransform;
    startTransform.m_vTranslation.v = config.m_kTransforms[0].m_vTranslation.v;
    *(__m128*)&startTransform.m_rotation = *(const __m128*)&config.m_kTransforms[0].m_rotation;
    startTransform.m_vScale.v = config.m_kTransforms[0].m_vScale.v;
    {
        hkVector4 outV0;
        tempV0.v = _mm_setzero_ps();
        hkaDefaultAnimatedReferenceFrame_project(&config, &DAT_01268700, &tempV0, &outV0);
        tempV0.v = outV0.v;
    }
    if (config.m_bFlag13)
    {
        float dotForward = my_fabs(config.m_vEnd.dot3(tempV0).getReal());
        hkVector4 cr;
        cr.v = cross(config.m_vStart.v, config.m_vEnd.v);
        float dotSide = my_fabs(cr.dot3(tempV0).getReal());
        if (dotForward > 0.01f || dotSide > 0.01f)
        {
            {
                char buf[512];
                hkOstream os((void*)buf, 512);
                os.operator<<(DAT_010ebe28);
                DAT_01268360->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 88);
            }
            {
                char buf[512];
                hkOstream os((void*)buf, 512);
                os.operator<<(DAT_010ebdcc)
                    .WriteFloat(dotForward)
                    .operator<<(DAT_01012630)
                    .WriteFloat(dotSide)
                    .operator<<(DAT_010ebde0);
                DAT_01268360->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 89);
            }
            {
                char buf[512];
                hkOstream os((void*)buf, 512);
                os.operator<<(DAT_010ebd70);
                DAT_01268360->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 90);
            }
        }
    }
    hkMemoryAllocator& mem = reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap());
    const int cap = samples.m_iCapacityState & 0x3fffffff;
    if (cap < numSamples)
    {
        int newCap = cap + cap;
        if (numSamples >= newCap)
        {
            newCap = numSamples;
        }
        hkArrayUtil__reserve(&mem, &samples, newCap, sizeof(hkVector4));
    }
    samples.m_iElementCount = numSamples;
    for (int i = 0; i < numSamples; ++i)
    {
        __m128 unitScale = _mm_set1_ps(1.0f);
        float time = (float)i * dt;
        hkQsTransform curTransform;
        hkQsTransform_UpdateState_00e41bf0(&curTransform, time, config.m_kTransforms, config.m_numQsTransforms, config.m_fAnimationDuration);
        hkQsTransform qh;
        qh.m_rotation.setMulInverse(&curTransform.m_rotation, &startTransform.m_rotation);
        qh.m_vTranslation.v = _mm_sub_ps(curTransform.m_vTranslation.v, startTransform.m_vTranslation.v);
        qh.m_vScale.v = unitScale;
        hkVector4 sampleOut;
        hkaDefaultAnimatedReferenceFrame_project(&config, &qh, &tempV0, &sampleOut);
        __m128 sample = sampleOut.v;
        samples.m_data[i].v = sample;
        tempV0.v = sample;
    }
}
