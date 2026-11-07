
// src/havok/physics/utilities/actions/reorient/hkpreorientaction_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/reorient/hkpreorientaction_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/reorient/hkpreorientaction_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/actions/reorient/hkpreorientaction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/actions/reorient/hkpreorientaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/reorient/hkpreorientaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpReorientAction.h"
#include <xmmintrin.h>

#include <math.h>
extern const __m128 DAT_010c71e0;
extern const __m128 DAT_01017d10;

class ReorientApplyScalar
{
    __m128 bits;

  public:
    ReorientApplyScalar()
    {}
    ReorientApplyScalar(float value)
    {
        bits = _mm_load_ss(&value);
    }
    ReorientApplyScalar(const __m128& value) : bits(value)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, bits);
        return result;
    }
    __forceinline const __m128& quad() const
    {
        return bits;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(bits, bits, 0);
    }
};
class ReorientApplyVector
{
    __m128 bits;

  public:
    __forceinline ReorientApplyVector()
    {}
    __forceinline ReorientApplyVector(const ReorientApplyVector& value) : bits(value.bits)
    {}
    __forceinline ReorientApplyVector(const __m128& value) : bits(value)
    {}
    __forceinline void operator=(const ReorientApplyVector& value)
    {
        bits = value.bits;
    }
    __forceinline void operator=(const __m128& value)
    {
        bits = value;
    }
    operator __m128() const
    {
        return bits;
    }
    __forceinline __m128& quad()
    {
        return bits;
    }
    __forceinline const __m128& quad() const
    {
        return bits;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&bits)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&bits)[i];
    }
    __forceinline void add(const ReorientApplyVector& a, const ReorientApplyVector& b)
    {
        bits = _mm_add_ps(a.bits, b.bits);
    }
    __forceinline void sub(const ReorientApplyVector& a)
    {
        bits = _mm_sub_ps(bits, a.bits);
    }
    __forceinline void mul(const ReorientApplyVector& a, const ReorientApplyVector& b)
    {
        bits = _mm_mul_ps(a.bits, b.bits);
    }
    __forceinline void mul(const ReorientApplyScalar& s, const ReorientApplyVector& a)
    {
        bits = _mm_mul_ps(s.splat(), a.bits);
    }
    __forceinline void accumulate(const ReorientApplyScalar& s, const ReorientApplyVector& a)
    {
        bits = _mm_add_ps(bits, _mm_mul_ps(s.splat(), a.bits));
    }
    __forceinline void accumulate(const ReorientApplyVector& a, const ReorientApplyVector& b)
    {
        bits = _mm_add_ps(bits, _mm_mul_ps(a.bits, b.bits));
    }
    __forceinline void sumProduct(const ReorientApplyVector& a, const ReorientApplyVector& b,
                                  const ReorientApplyVector& c)
    {
        bits = _mm_add_ps(a.bits, _mm_mul_ps(b.bits, c.bits));
    }
    __forceinline void broadcastW(const ReorientApplyVector& a)
    {
        bits = _mm_shuffle_ps(a.bits, a.bits, 0xff);
    }
    __forceinline void broadcastX()
    {
        bits = _mm_shuffle_ps(bits, bits, 0);
    }
    __forceinline ReorientApplyScalar dot(const ReorientApplyVector& b) const
    {
        __m128 terms = _mm_mul_ps(bits, b.bits);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
        return _mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), sum);
    }
    __forceinline void cross(const ReorientApplyVector& a, const ReorientApplyVector& b)
    {
        __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.bits, a.bits, 0xc9), _mm_shuffle_ps(b.bits, b.bits, 0xd2));
        __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.bits, a.bits, 0xd2), _mm_shuffle_ps(b.bits, b.bits, 0xc9));
        bits = _mm_sub_ps(left, right);
    }
    __forceinline ReorientApplyScalar invLength() const
    {
        const __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        const __m128 squared = dot(*this).quad();
        const __m128 mask = _mm_cmpeq_ss(squared, zero);
        const __m128 estimate = _mm_rsqrt_ss(squared);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
        return _mm_andnot_ps(mask, refined);
    }
    __forceinline void normalize()
    {
        __m128 reciprocal = invLength().splat();
        bits = _mm_mul_ps(reciprocal, bits);
    }
    __forceinline void absolute(const ReorientApplyVector& a)
    {
        bits = _mm_and_ps(a.bits, DAT_01017d10);
    }
    __forceinline int major() const
    {
        ReorientApplyVector magnitude;
        magnitude.absolute(*this);
        return magnitude(0) < magnitude(1) ? (magnitude(1) < magnitude(2) ? 2 : 1)
                                           : (magnitude(0) < magnitude(2) ? 2 : 0);
    }
    __forceinline void rotate(const ReorientApplyVector& rotation, const ReorientApplyVector& direction)
    {
        ReorientApplyVector bias;
        bias.quad() = DAT_010c71e0;
        ReorientApplyVector real;
        real.broadcastW(rotation);
        ReorientApplyVector factor;
        factor.sumProduct(bias, real, real);
        ReorientApplyVector result;
        result.mul(direction, factor);
        ReorientApplyVector projection;
        projection.quad() = rotation.dot(direction).quad();
        projection.broadcastX();
        result.accumulate(projection, rotation);
        ReorientApplyVector perpendicular;
        perpendicular.cross(rotation, direction);
        result.accumulate(real, perpendicular);
        add(result, result);
    }
};
struct ReorientApplyMotionView
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void ApplyAngularImpulseToBodies(const ReorientApplyVector& imp);
};
class ReorientApplyBodyView
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    ReorientApplyMotionView m_pMotionState;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    ReorientApplyVector m_rotation;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    ReorientApplyVector m_kAngularVelocity;
    void activate_00c9c1d0();
};

struct ReorientApplyStepInfo
{
    float start, end, delta, inverse;
};
inline float reorientApplyAngle(float value)
{
    if ((float)fabs(value) >= 1.0f)
    {
        value = value > 0.0f ? 0.0f : 3.14159265358979f;
        return value;
    }
    value = (float)acos(value);
    double rounded = value;
    return (float)rounded;
}
// The shared action has no applyAction declaration; this data-less adapter uses its checked layout.
struct ReorientApplyActionView : hkpReorientAction
{
    __declspec(noinline) void hkpReorientAction_applyAction(const ReorientApplyStepInfo& info);
};
// @fnv 0x00e445b0
// src: HAVOK_SRC 0x00e445b0
__declspec(noinline) void ReorientApplyActionView::hkpReorientAction_applyAction(const ReorientApplyStepInfo& info)
{
    ReorientApplyBodyView* body = reinterpret_cast<ReorientApplyBodyView*>(m_pEntity);
    ReorientApplyVector up;
    up.rotate(body->m_rotation, reinterpret_cast<const ReorientApplyVector&>(m_vUpAxis));
    ReorientApplyVector axis;
    axis.rotate(body->m_rotation, reinterpret_cast<const ReorientApplyVector&>(m_vRotationAxis));
    ReorientApplyVector projected(reinterpret_cast<const ReorientApplyVector&>(m_vUpAxis));
    float distance = projected.dot(axis);
    projected.accumulate(-distance, axis);
    projected.normalize();
    float angle = reorientApplyAngle(up.dot(projected));
    ReorientApplyVector crossing;
    crossing.cross(up, projected);
    float a = crossing(crossing.major());
    float b = axis(axis.major());
    if ((a < 0.0f) != (b < 0.0f))
        angle = -angle;
    ReorientApplyVector drag;
    drag.mul(m_fMotorDamping * info.inverse, body->m_kAngularVelocity);
    ReorientApplyVector impulse;
    impulse.mul(m_fSpringStrength * angle * info.inverse, axis);
    impulse.sub(drag);
    body->activate_00c9c1d0();
    body->m_pMotionState.ApplyAngularImpulseToBodies(impulse);
}
