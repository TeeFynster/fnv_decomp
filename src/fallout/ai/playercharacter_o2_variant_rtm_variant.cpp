// src/fallout/ai/playercharacter_o2_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/playercharacter_o2_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/fallout/ai/playercharacter_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/playercharacter.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "PlayerCharacter.h"
#include "../../../include/NiPoint3.h"
struct FUN_00c6fd20_class
{
    void* m_60c;
    int bhkCharacterController_GetSupportBody();
};

#include <xmmintrin.h>
extern "C" double __cdecl sqrt(double);
class ScalarValue
{
    ::__m128 value;

  public:
    ScalarValue()
    {}
    ScalarValue(const ::__m128& v) : value(v)
    {}
    ScalarValue(float f) : value((_mm_load_ss)(&f))
    {}
    operator float() const
    {
        float f;
        (_mm_store_ss)(&f, value);
        return f;
    }
    __forceinline const ::__m128& Vector4f() const
    {
        return value;
    }
    __forceinline ::__m128 Broadcast() const
    {
        return (_mm_shuffle_ps)(value, value, 0);
    }
};
extern const ::__m128 DAT_010c7160;
inline ScalarValue operator-(const ScalarValue& b)
{
    return (_mm_sub_ss)(DAT_010c7160, b.Vector4f());
}
// local form of hkVector4: 0x00c6f500 needs ScalarValue inline math and copy calls (shared extent 1263 vs 1302).
struct __declspec(align(16)) ParticleVectorLocal_00c6f500
{
    ::__m128 value;
    ParticleVectorLocal_00c6f500()
    {}
    ParticleVectorLocal_00c6f500(const ParticleVectorLocal_00c6f500& v) : value(v.value)
    {}
    ParticleVectorLocal_00c6f500(const ::__m128& v) : value(v)
    {}
    void operator=(const ParticleVectorLocal_00c6f500& v)
    {
        value = v.value;
    }
    const float& At(int i) const
    {
        return reinterpret_cast<const float*>(&value)[i];
    }
    float& At(int i)
    {
        return reinterpret_cast<float*>(&value)[i];
    }
    __forceinline ScalarValue Dot(const ParticleVectorLocal_00c6f500& v) const
    {
        ::__m128 product = (_mm_mul_ps)(value, v.value);
        ::__m128 first = (_mm_add_ss)((_mm_shuffle_ps)(product, product, 0x55), product);
        return (_mm_add_ss)((_mm_shuffle_ps)(product, product, 0xaa), first);
    }
    __forceinline ScalarValue LengthSq() const
    {
        return Dot(*this);
    }
    __forceinline ScalarValue Length() const
    {
        return (_mm_sqrt_ss)(Dot(*this).Vector4f());
    }
    __forceinline ScalarValue InverseLength() const
    {
        ::__m128 half = (_mm_set_ss)(0.5f);
        ::__m128 three = (_mm_set_ss)(3.0f);
        ::__m128 zero = (_mm_set_ss)(0.0f);
        ::__m128 square = Dot(*this).Vector4f();
        ::__m128 mask = (_mm_cmpeq_ss)(square, zero);
        ::__m128 estimate = (_mm_rsqrt_ss)(square);
        ::__m128 correction = (_mm_sub_ss)(three, (_mm_mul_ss)((_mm_mul_ss)(square, estimate), estimate));
        ::__m128 refined = (_mm_mul_ss)((_mm_mul_ss)(half, estimate), correction);
        return (_mm_andnot_ps)(mask, refined);
    }
    __forceinline void Normalize()
    {
        ::__m128 scale = InverseLength().Broadcast();
        value = (_mm_mul_ps)(scale, value);
    }
    __forceinline bool NormalizeNonzero()
    {
        float q = LengthSq();
        if (q != 0.0f)
        {
            Mul(1.0f / (float)sqrt(q));
            return true;
        }
        return false;
    }
    __forceinline void Mul(const ScalarValue& a)
    {
        value = (_mm_mul_ps)(a.Broadcast(), value);
    }
    __forceinline void Add(const ParticleVectorLocal_00c6f500& b)
    {
        value = (_mm_add_ps)(value, b.value);
    }
    __forceinline void Sub(const ParticleVectorLocal_00c6f500& b)
    {
        value = (_mm_sub_ps)(value, b.value);
    }
    __forceinline void Cross(const ParticleVectorLocal_00c6f500& a, const ParticleVectorLocal_00c6f500& b)
    {
        ::__m128 lhs = (_mm_mul_ps)((_mm_shuffle_ps)(a.value, a.value, 0xc9), (_mm_shuffle_ps)(b.value, b.value, 0xd2));
        ::__m128 rhs = (_mm_mul_ps)((_mm_shuffle_ps)(a.value, a.value, 0xd2), (_mm_shuffle_ps)(b.value, b.value, 0xc9));
        value = (_mm_sub_ps)(lhs, rhs);
    }
};
extern const double DAT_0102fc70, DAT_0109c9e0, DAT_01011588, DAT_0103c7c8, DAT_0101a6b0;
extern const float DAT_01013ea4, DAT_0101df44;
struct __declspec(align(16)) Particle
{
    unsigned int unk_000;
    unsigned int unk_004;
    unsigned int unk_008;
    unsigned int unk_00c;
    unsigned int unk_010;
    unsigned int unk_014;
    unsigned int unk_018;
    unsigned int unk_01c;
    unsigned int unk_020;
    unsigned int unk_024;
    unsigned int unk_028;
    unsigned int unk_02c;
    unsigned int unk_030;
    unsigned int unk_034;
    unsigned int unk_038;
    unsigned int unk_03c;
    unsigned int unk_040;
    unsigned int unk_044;
    unsigned int unk_048;
    unsigned int unk_04c;
    unsigned int unk_050;
    unsigned int unk_054;
    unsigned int unk_058;
    unsigned int unk_05c;
    unsigned int unk_060;
    unsigned int unk_064;
    unsigned int unk_068;
    unsigned int unk_06c;
    unsigned int unk_070;
    unsigned int unk_074;
    unsigned int unk_078;
    unsigned int unk_07c;
    unsigned int unk_080;
    unsigned int unk_084;
    unsigned int unk_088;
    unsigned int unk_08c;
    unsigned int unk_090;
    unsigned int unk_094;
    unsigned int unk_098;
    unsigned int unk_09c;
    unsigned int unk_0a0;
    unsigned int unk_0a4;
    unsigned int unk_0a8;
    unsigned int unk_0ac;
    unsigned int unk_0b0;
    unsigned int unk_0b4;
    unsigned int unk_0b8;
    unsigned int unk_0bc;
    unsigned int unk_0c0;
    unsigned int unk_0c4;
    unsigned int unk_0c8;
    unsigned int unk_0cc;
    unsigned int unk_0d0;
    unsigned int unk_0d4;
    unsigned int unk_0d8;
    unsigned int unk_0dc;
    unsigned int unk_0e0;
    unsigned int unk_0e4;
    unsigned int unk_0e8;
    unsigned int unk_0ec;
    unsigned int unk_0f0;
    unsigned int unk_0f4;
    unsigned int unk_0f8;
    unsigned int unk_0fc;
    unsigned int unk_100;
    unsigned int unk_104;
    unsigned int unk_108;
    unsigned int unk_10c;
    unsigned int unk_110;
    unsigned int unk_114;
    unsigned int unk_118;
    unsigned int unk_11c;
    unsigned int unk_120;
    unsigned int unk_124;
    unsigned int unk_128;
    unsigned int unk_12c;
    unsigned int unk_130;
    unsigned int unk_134;
    unsigned int unk_138;
    unsigned int unk_13c;
    unsigned int unk_140;
    unsigned int unk_144;
    unsigned int unk_148;
    unsigned int unk_14c;
    unsigned int unk_150;
    unsigned int unk_154;
    unsigned int unk_158;
    unsigned int unk_15c;
    unsigned int unk_160;
    unsigned int unk_164;
    unsigned int unk_168;
    unsigned int unk_16c;
    unsigned int unk_170;
    unsigned int unk_174;
    unsigned int unk_178;
    unsigned int unk_17c;
    unsigned int unk_180;
    unsigned int unk_184;
    unsigned int unk_188;
    unsigned int unk_18c;
    unsigned int unk_190;
    unsigned int unk_194;
    unsigned int unk_198;
    unsigned int unk_19c;
    unsigned int unk_1a0;
    unsigned int unk_1a4;
    unsigned int unk_1a8;
    unsigned int unk_1ac;
    unsigned int unk_1b0;
    unsigned int unk_1b4;
    unsigned int unk_1b8;
    unsigned int unk_1bc;
    unsigned int unk_1c0;
    unsigned int unk_1c4;
    unsigned int unk_1c8;
    unsigned int unk_1cc;
    unsigned int unk_1d0;
    unsigned int unk_1d4;
    unsigned int unk_1d8;
    unsigned int unk_1dc;
    unsigned int unk_1e0;
    unsigned int unk_1e4;
    unsigned int unk_1e8;
    unsigned int unk_1ec;
    unsigned int unk_1f0;
    unsigned int unk_1f4;
    unsigned int unk_1f8;
    unsigned int unk_1fc;
    unsigned int unk_200;
    unsigned int unk_204;
    unsigned int unk_208;
    unsigned int unk_20c;
    unsigned int unk_210;
    unsigned int unk_214;
    unsigned int unk_218;
    unsigned int unk_21c;
    unsigned int unk_220;
    unsigned int unk_224;
    unsigned int unk_228;
    unsigned int unk_22c;
    unsigned int unk_230;
    unsigned int unk_234;
    unsigned int unk_238;
    unsigned int unk_23c;
    unsigned int unk_240;
    unsigned int unk_244;
    unsigned int unk_248;
    unsigned int unk_24c;
    unsigned int unk_250;
    unsigned int unk_254;
    unsigned int unk_258;
    unsigned int unk_25c;
    unsigned int unk_260;
    unsigned int unk_264;
    unsigned int unk_268;
    unsigned int unk_26c;
    unsigned int unk_270;
    unsigned int unk_274;
    unsigned int unk_278;
    unsigned int unk_27c;
    unsigned int unk_280;
    unsigned int unk_284;
    unsigned int unk_288;
    unsigned int unk_28c;
    unsigned int unk_290;
    unsigned int unk_294;
    unsigned int unk_298;
    unsigned int unk_29c;
    unsigned int unk_2a0;
    unsigned int unk_2a4;
    unsigned int unk_2a8;
    unsigned int unk_2ac;
    unsigned int unk_2b0;
    unsigned int unk_2b4;
    unsigned int unk_2b8;
    unsigned int unk_2bc;
    unsigned int unk_2c0;
    unsigned int unk_2c4;
    unsigned int unk_2c8;
    unsigned int unk_2cc;
    unsigned int unk_2d0;
    unsigned int unk_2d4;
    unsigned int unk_2d8;
    unsigned int unk_2dc;
    unsigned int unk_2e0;
    unsigned int unk_2e4;
    unsigned int unk_2e8;
    unsigned int unk_2ec;
    unsigned int unk_2f0;
    unsigned int unk_2f4;
    unsigned int unk_2f8;
    unsigned int unk_2fc;
    unsigned int unk_300;
    unsigned int unk_304;
    unsigned int unk_308;
    unsigned int unk_30c;
    unsigned int unk_310;
    unsigned int unk_314;
    unsigned int unk_318;
    unsigned int unk_31c;
    unsigned int unk_320;
    unsigned int unk_324;
    unsigned int unk_328;
    unsigned int unk_32c;
    unsigned int unk_330;
    unsigned int unk_334;
    unsigned int unk_338;
    unsigned int unk_33c;
    unsigned int unk_340;
    unsigned int unk_344;
    unsigned int unk_348;
    unsigned int unk_34c;
    unsigned int unk_350;
    unsigned int unk_354;
    unsigned int unk_358;
    unsigned int unk_35c;
    unsigned int unk_360;
    unsigned int unk_364;
    unsigned int unk_368;
    unsigned int unk_36c;
    unsigned int unk_370;
    unsigned int unk_374;
    unsigned int unk_378;
    unsigned int unk_37c;
    unsigned int unk_380;
    unsigned int unk_384;
    unsigned int unk_388;
    unsigned int unk_38c;
    unsigned int unk_390;
    unsigned int unk_394;
    unsigned int unk_398;
    unsigned int unk_39c;
    unsigned int unk_3a0;
    unsigned int unk_3a4;
    unsigned int unk_3a8;
    unsigned int unk_3ac;
    unsigned int unk_3b0;
    unsigned int unk_3b4;
    unsigned int unk_3b8;
    unsigned int unk_3bc;
    unsigned int unk_3c0;
    unsigned int unk_3c4;
    unsigned int unk_3c8;
    unsigned int unk_3cc;
    unsigned int unk_3d0;
    unsigned int unk_3d4;
    unsigned int unk_3d8;
    unsigned int unk_3dc;
    unsigned int unk_3e0;
    unsigned int unk_3e4;
    unsigned int unk_3e8;
    unsigned int unk_3ec;
    unsigned int unk_3f0;
    unsigned int unk_3f4;
    unsigned int unk_3f8;
    unsigned int unk_3fc;
    unsigned int unk_400;
    unsigned int unk_404;
    unsigned int unk_408;
    unsigned int unk_40c;
    unsigned int unk_410;
    unsigned int flags;
    unsigned int unk_418;
    unsigned int unk_41c;
    unsigned int unk_420;
    unsigned int unk_424;
    unsigned int unk_428;
    unsigned int unk_42c;
    unsigned int unk_430;
    unsigned int unk_434;
    unsigned int unk_438;
    unsigned int unk_43c;
    unsigned int unk_440;
    unsigned int unk_444;
    unsigned int unk_448;
    unsigned int unk_44c;
    unsigned int unk_450;
    unsigned int unk_454;
    unsigned int unk_458;
    unsigned int unk_45c;
    unsigned int unk_460;
    unsigned int unk_464;
    unsigned int unk_468;
    unsigned int unk_46c;
    unsigned int unk_470;
    unsigned int unk_474;
    unsigned int unk_478;
    unsigned int unk_47c;
    unsigned int unk_480;
    unsigned int unk_484;
    unsigned int unk_488;
    unsigned int unk_48c;
    unsigned int unk_490;
    unsigned int unk_494;
    unsigned int unk_498;
    unsigned int unk_49c;
    unsigned int unk_4a0;
    unsigned int unk_4a4;
    unsigned int unk_4a8;
    unsigned int unk_4ac;
    unsigned int unk_4b0;
    unsigned int unk_4b4;
    unsigned int unk_4b8;
    unsigned int unk_4bc;
    unsigned int unk_4c0;
    unsigned int unk_4c4;
    unsigned int unk_4c8;
    unsigned int unk_4cc;
    ParticleVectorLocal_00c6f500 localDirection;
    unsigned int unk_4e0;
    unsigned int unk_4e4;
    unsigned int unk_4e8;
    unsigned int unk_4ec;
    unsigned int unk_4f0;
    unsigned int unk_4f4;
    unsigned int unk_4f8;
    unsigned int unk_4fc;
    ParticleVectorLocal_00c6f500 modifier;
    unsigned int unk_510;
    unsigned int unk_514;
    unsigned int unk_518;
    unsigned int unk_51c;
    unsigned int unk_520;
    float modifierTime;
    float rotation;
    float rotationTime;
    unsigned int unk_530;
    unsigned int unk_534;
    unsigned int unk_538;
    unsigned int unk_53c;
    unsigned int unk_540;
    unsigned int unk_544;
    unsigned int unk_548;
    unsigned int unk_54c;
    unsigned int unk_550;
    unsigned int unk_554;
    unsigned int unk_558;
    unsigned int unk_55c;
    unsigned int unk_560;
    unsigned int unk_564;
    unsigned int unk_568;
    unsigned int unk_56c;
    unsigned int unk_570;
    unsigned int unk_574;
    unsigned int unk_578;
    unsigned int unk_57c;
    ParticleVectorLocal_00c6f500 accumulatedImpulse;
    unsigned int impulseCount;
    unsigned int unk_594;
    unsigned int unk_598;
    unsigned int unk_59c;
    unsigned int unk_5a0;
    unsigned int unk_5a4;
    unsigned int unk_5a8;
    unsigned int unk_5ac;
    unsigned int unk_5b0;
    unsigned int unk_5b4;
    unsigned int unk_5b8;
    unsigned int unk_5bc;
    unsigned int unk_5c0;
    unsigned int unk_5c4;
    unsigned int unk_5c8;
    unsigned int unk_5cc;
    unsigned int unk_5d0;
    unsigned int unk_5d4;
    unsigned int unk_5d8;
    unsigned int unk_5dc;
    unsigned int unk_5e0;
    unsigned int unk_5e4;
    unsigned int unk_5e8;
    unsigned int unk_5ec;
    unsigned int unk_5f0;
    float lifetime;
    unsigned int unk_5f8;
    unsigned int unk_5fc;
    unsigned int unk_600;
    unsigned int startFrame;
    __forceinline void AddPush(const ParticleVectorLocal_00c6f500& delta)
    {
        ParticleVectorLocal_00c6f500& sum = accumulatedImpulse;
        sum.Add(delta);
        ++impulseCount;
    }
    const ParticleVectorLocal_00c6f500* bhkCharacterProxy_GethkPosition() const;
    void UpdateMaxVelocity(NiPoint3* direction, float timeStep);
    void UpdateLargestAbsoluteThreshold(float angle, float impactStrength);
};
struct Source
{
    unsigned int unk_000;
    unsigned int unk_004;
    unsigned int unk_008;
    unsigned int unk_00c;
    unsigned int unk_010;
    unsigned int unk_014;
    unsigned int unk_018;
    unsigned int unk_01c;
    unsigned int unk_020;
    unsigned int unk_024;
    unsigned int unk_028;
    unsigned int unk_02c;
    unsigned int unk_030;
    unsigned int unk_034;
    unsigned int unk_038;
    unsigned int unk_03c;
    unsigned int unk_040;
    unsigned int unk_044;
    unsigned int unk_048;
    unsigned int unk_04c;
    unsigned int unk_050;
    unsigned int unk_054;
    unsigned int unk_058;
    unsigned int unk_05c;
    unsigned int unk_060;
    unsigned int unk_064;
    unsigned int unk_068;
    unsigned int unk_06c;
    unsigned int unk_070;
    unsigned int unk_074;
    unsigned int unk_078;
    unsigned int unk_07c;
    unsigned int unk_080;
    unsigned int unk_084;
    unsigned int unk_088;
    unsigned int unk_08c;
    unsigned int unk_090;
    unsigned int unk_094;
    unsigned int unk_098;
    unsigned int unk_09c;
    unsigned int unk_0a0;
    unsigned int unk_0a4;
    unsigned int unk_0a8;
    unsigned int unk_0ac;
    unsigned int unk_0b0;
    unsigned int unk_0b4;
    unsigned int unk_0b8;
    unsigned int unk_0bc;
    Particle* particle;
    void FUN_00c90510();
    void FUN_00c905b0();
    const ParticleVectorLocal_00c6f500* hkpCharacterProxy_getLinearVelocity();
};
extern void __cdecl FUN_00458620(NiPoint3* result, const ParticleVectorLocal_00c6f500* value);
extern float __cdecl BSMIN(float fTargetUpperBound, float value);
extern float __cdecl BSMAX_00404010(float fTargetUpperBound, float value);
struct ParticleController
{
    unsigned int unk_000;
    unsigned int unk_004;
    unsigned int unk_008;
    unsigned int unk_00c;
    unsigned int unk_010;
    unsigned int unk_014;
    unsigned int unk_018;
    unsigned int unk_01c;
    unsigned int unk_020;
    unsigned int unk_024;
    unsigned int unk_028;
    unsigned int unk_02c;
    unsigned int unk_030;
    unsigned int unk_034;
    unsigned int unk_038;
    unsigned int unk_03c;
    unsigned int unk_040;
    unsigned int unk_044;
    unsigned int unk_048;
    unsigned int unk_04c;
    unsigned int unk_050;
    unsigned int unk_054;
    unsigned int unk_058;
    unsigned int unk_05c;
    unsigned int unk_060;
    unsigned int unk_064;
    unsigned int unk_068;
    unsigned int unk_06c;
    unsigned int unk_070;
    unsigned int unk_074;
    unsigned int unk_078;
    unsigned int unk_07c;
    unsigned int unk_080;
    unsigned int unk_084;
    unsigned int unk_088;
    unsigned int unk_08c;
    unsigned int unk_090;
    unsigned int unk_094;
    unsigned int unk_098;
    unsigned int unk_09c;
    unsigned int unk_0a0;
    unsigned int unk_0a4;
    unsigned int unk_0a8;
    unsigned int unk_0ac;
    unsigned int unk_0b0;
    unsigned int unk_0b4;
    unsigned int unk_0b8;
    unsigned int unk_0bc;
    unsigned int unk_0c0;
    unsigned int unk_0c4;
    unsigned int unk_0c8;
    unsigned int unk_0cc;
    unsigned int unk_0d0;
    unsigned int unk_0d4;
    unsigned int unk_0d8;
    unsigned int unk_0dc;
    unsigned int unk_0e0;
    unsigned int unk_0e4;
    unsigned int unk_0e8;
    unsigned int unk_0ec;
    unsigned int unk_0f0;
    unsigned int unk_0f4;
    unsigned int unk_0f8;
    unsigned int unk_0fc;
    unsigned int unk_100;
    unsigned int unk_104;
    unsigned int unk_108;
    unsigned int unk_10c;
    unsigned int unk_110;
    unsigned int unk_114;
    unsigned int unk_118;
    unsigned int unk_11c;
    unsigned int unk_120;
    unsigned int unk_124;
    unsigned int unk_128;
    unsigned int unk_12c;
    unsigned int unk_130;
    unsigned int unk_134;
    unsigned int unk_138;
    unsigned int unk_13c;
    unsigned int unk_140;
    unsigned int unk_144;
    unsigned int unk_148;
    unsigned int unk_14c;
    unsigned int unk_150;
    unsigned int unk_154;
    unsigned int unk_158;
    unsigned int unk_15c;
    unsigned int unk_160;
    unsigned int unk_164;
    unsigned int unk_168;
    unsigned int unk_16c;
    unsigned int unk_170;
    unsigned int unk_174;
    unsigned int unk_178;
    unsigned int unk_17c;
    unsigned int unk_180;
    unsigned int unk_184;
    unsigned int unk_188;
    unsigned int unk_18c;
    unsigned int unk_190;
    unsigned int unk_194;
    unsigned int unk_198;
    unsigned int unk_19c;
    unsigned int unk_1a0;
    unsigned int unk_1a4;
    unsigned int unk_1a8;
    unsigned int unk_1ac;
    unsigned int unk_1b0;
    unsigned int unk_1b4;
    unsigned int unk_1b8;
    unsigned int unk_1bc;
    unsigned int unk_1c0;
    unsigned int unk_1c4;
    unsigned int unk_1c8;
    unsigned int unk_1cc;
    unsigned int unk_1d0;
    unsigned int unk_1d4;
    unsigned int unk_1d8;
    unsigned int unk_1dc;
    unsigned int unk_1e0;
    unsigned int unk_1e4;
    unsigned int unk_1e8;
    unsigned int unk_1ec;
    unsigned int targetFrame;
    unsigned int currentFrame;
    unsigned int unk_1f8;
    unsigned int unk_1fc;
    unsigned int unk_200;
    unsigned int unk_204;
    unsigned int unk_208;
    unsigned int unk_20c;
    unsigned int unk_210;
    unsigned int unk_214;
    unsigned int unk_218;
    unsigned int unk_21c;
    unsigned int unk_220;
    unsigned int unk_224;
    Source* previousParticle;
};
struct ControllerPrefix
{
    unsigned int unk_000;
    unsigned int unk_004;
    unsigned int unk_008;
    unsigned int unk_00c;
    unsigned int unk_010;
    unsigned int unk_014;
    unsigned int unk_018;
    unsigned int unk_01c;
    unsigned int unk_020;
    unsigned int unk_024;
    unsigned int unk_028;
    unsigned int unk_02c;
    unsigned int unk_030;
    unsigned int unk_034;
    unsigned int unk_038;
    unsigned int unk_03c;
    unsigned int unk_040;
    unsigned int unk_044;
    unsigned int unk_048;
    unsigned int unk_04c;
    unsigned int unk_050;
    unsigned int unk_054;
    unsigned int unk_058;
    unsigned int unk_05c;
    unsigned int unk_060;
    unsigned int unk_064;
    unsigned int unk_068;
    unsigned int unk_06c;
    unsigned int unk_070;
    unsigned int unk_074;
    unsigned int unk_078;
    unsigned int unk_07c;
    unsigned int unk_080;
    unsigned int unk_084;
    unsigned int unk_088;
    unsigned int unk_08c;
    unsigned int unk_090;
    unsigned int unk_094;
    unsigned int unk_098;
    unsigned int unk_09c;
    unsigned int unk_0a0;
    unsigned int unk_0a4;
    unsigned int unk_0a8;
    unsigned int unk_0ac;
    unsigned int unk_0b0;
    unsigned int unk_0b4;
    unsigned int unk_0b8;
    unsigned int unk_0bc;
    unsigned int unk_0c0;
    unsigned int unk_0c4;
    unsigned int unk_0c8;
    unsigned int unk_0cc;
    unsigned int unk_0d0;
    unsigned int unk_0d4;
    unsigned int unk_0d8;
    unsigned int unk_0dc;
    unsigned int unk_0e0;
    unsigned int unk_0e4;
    unsigned int unk_0e8;
    unsigned int unk_0ec;
    unsigned int unk_0f0;
    unsigned int unk_0f4;
    unsigned int unk_0f8;
    unsigned int unk_0fc;
    unsigned int unk_100;
    unsigned int unk_104;
    unsigned int unk_108;
    unsigned int unk_10c;
    unsigned int unk_110;
    unsigned int unk_114;
    unsigned int unk_118;
    unsigned int unk_11c;
    unsigned int unk_120;
    unsigned int unk_124;
    unsigned int unk_128;
    unsigned int unk_12c;
    unsigned int unk_130;
    unsigned int unk_134;
    unsigned int unk_138;
    unsigned int unk_13c;
    unsigned int unk_140;
    unsigned int unk_144;
    unsigned int unk_148;
    unsigned int unk_14c;
    unsigned int unk_150;
    unsigned int unk_154;
    unsigned int unk_158;
    unsigned int unk_15c;
    unsigned int unk_160;
    unsigned int unk_164;
    unsigned int unk_168;
    unsigned int unk_16c;
    unsigned int unk_170;
    unsigned int unk_174;
    unsigned int unk_178;
    unsigned int unk_17c;
    unsigned int unk_180;
    unsigned int unk_184;
    unsigned int unk_188;
    unsigned int unk_18c;
    unsigned int unk_190;
    unsigned int unk_194;
    unsigned int unk_198;
    unsigned int unk_19c;
    unsigned int unk_1a0;
    unsigned int unk_1a4;
    unsigned int unk_1a8;
    unsigned int unk_1ac;
    unsigned int unk_1b0;
    unsigned int unk_1b4;
    unsigned int unk_1b8;
    unsigned int unk_1bc;
    unsigned int unk_1c0;
    unsigned int unk_1c4;
    unsigned int unk_1c8;
    unsigned int unk_1cc;
    unsigned int unk_1d0;
    unsigned int unk_1d4;
    unsigned int unk_1d8;
    unsigned int unk_1dc;
    unsigned int unk_1e0;
    unsigned int unk_1e4;
    unsigned int unk_1e8;
    unsigned int unk_1ec;
    unsigned int unk_1f0;
    unsigned int unk_1f4;
    unsigned int unk_1f8;
    unsigned int unk_1fc;
    unsigned int unk_200;
    unsigned int unk_204;
    unsigned int unk_208;
    unsigned int unk_20c;
    unsigned int unk_210;
    unsigned int unk_214;
    unsigned int unk_218;
    unsigned int unk_21c;
    unsigned int unk_220;
    unsigned int unk_224;
    unsigned int unk_228;
    unsigned int unk_22c;
    unsigned int unk_230;
    unsigned int unk_234;
    unsigned int unk_238;
    unsigned int unk_23c;
    unsigned int unk_240;
    unsigned int unk_244;
    unsigned int unk_248;
    unsigned int unk_24c;
    unsigned int unk_250;
    unsigned int unk_254;
    unsigned int unk_258;
    unsigned int unk_25c;
    unsigned int unk_260;
    unsigned int unk_264;
    unsigned int unk_268;
    unsigned int unk_26c;
    unsigned int unk_270;
    unsigned int unk_274;
    unsigned int unk_278;
    unsigned int unk_27c;
    unsigned int unk_280;
    unsigned int unk_284;
    unsigned int unk_288;
    unsigned int unk_28c;
    unsigned int unk_290;
    unsigned int unk_294;
    unsigned int unk_298;
    unsigned int unk_29c;
    unsigned int unk_2a0;
    unsigned int unk_2a4;
    unsigned int unk_2a8;
    unsigned int unk_2ac;
    unsigned int unk_2b0;
    unsigned int unk_2b4;
    unsigned int unk_2b8;
    unsigned int unk_2bc;
    unsigned int unk_2c0;
    unsigned int unk_2c4;
    unsigned int unk_2c8;
    unsigned int unk_2cc;
    unsigned int unk_2d0;
    unsigned int unk_2d4;
    unsigned int unk_2d8;
    unsigned int unk_2dc;
    unsigned int unk_2e0;
    unsigned int unk_2e4;
    unsigned int unk_2e8;
    unsigned int unk_2ec;
    unsigned int unk_2f0;
    unsigned int unk_2f4;
    unsigned int unk_2f8;
    unsigned int unk_2fc;
    unsigned int unk_300;
    unsigned int unk_304;
    unsigned int unk_308;
    unsigned int unk_30c;
    unsigned int unk_310;
    unsigned int unk_314;
    unsigned int unk_318;
    unsigned int unk_31c;
    unsigned int unk_320;
    unsigned int unk_324;
    unsigned int unk_328;
    unsigned int unk_32c;
    unsigned int unk_330;
    unsigned int unk_334;
    unsigned int unk_338;
    unsigned int unk_33c;
    unsigned int unk_340;
    unsigned int unk_344;
    unsigned int unk_348;
    unsigned int unk_34c;
    unsigned int unk_350;
    unsigned int unk_354;
    unsigned int unk_358;
    unsigned int unk_35c;
    unsigned int unk_360;
    unsigned int unk_364;
    unsigned int unk_368;
    unsigned int unk_36c;
    unsigned int unk_370;
    unsigned int unk_374;
    unsigned int unk_378;
    unsigned int unk_37c;
    unsigned int unk_380;
    unsigned int unk_384;
    unsigned int unk_388;
    unsigned int unk_38c;
    unsigned int unk_390;
    unsigned int unk_394;
    unsigned int unk_398;
    unsigned int unk_39c;
    unsigned int unk_3a0;
    unsigned int unk_3a4;
    unsigned int unk_3a8;
    unsigned int unk_3ac;
    unsigned int unk_3b0;
    unsigned int unk_3b4;
    unsigned int unk_3b8;
    unsigned int unk_3bc;
    unsigned int unk_3c0;
    unsigned int unk_3c4;
    unsigned int unk_3c8;
    unsigned int unk_3cc;
    unsigned int unk_3d0;
    unsigned int unk_3d4;
    unsigned int unk_3d8;
    unsigned int unk_3dc;
    unsigned int unk_3e0;
    unsigned int unk_3e4;
    unsigned int unk_3e8;
    unsigned int unk_3ec;
    unsigned int unk_3f0;
    unsigned int unk_3f4;
    unsigned int unk_3f8;
    unsigned int unk_3fc;
    unsigned int unk_400;
    unsigned int unk_404;
    unsigned int unk_408;
    unsigned int unk_40c;
};
struct ControllerOwner : ControllerPrefix, ParticleController
{
    const ParticleVectorLocal_00c6f500* bhkCharacterProxy_GethkLinearVelocity() const;
};
extern const float DAT_01267bcc;
__declspec(noinline) void Particle::UpdateMaxVelocity(NiPoint3* direction, float timeStep)
{
    ParticleVectorLocal_00c6f500 proposed;
    proposed.At(0) = direction->x * DAT_01267bcc;
    proposed.At(1) = direction->y * DAT_01267bcc;
    proposed.At(2) = direction->z * DAT_01267bcc;
    proposed.At(3) = 0.0f;
    proposed.Mul(1.0f / timeStep);
    if (float(proposed.LengthSq()) > float(modifier.LengthSq()))
    {
        modifierTime = timeStep;
        modifier = proposed;
    }
}
float __cdecl HK2NI(float);
__declspec(noinline) void __cdecl FUN_00458620(NiPoint3* result, const ParticleVectorLocal_00c6f500* value)
{
    result->x = HK2NI(float(ScalarValue((_mm_load_ss)(&value->At(0)))));
    result->y = HK2NI(float(ScalarValue((_mm_load_ss)(&value->At(1)))));
    result->z = HK2NI(float(ScalarValue((_mm_load_ss)(&value->At(2)))));
}
// @fnv 0x00c6f500
// src: COMMUNITY 0x00c6f500
__declspec(noinline) void __fastcall bhkCharacterListener_characterInteractionCallback_0(ParticleController* self, void*, unsigned int mode, Source* source,
                                                  const ParticleVectorLocal_00c6f500* transform)
{
    ControllerOwner* owner;
    Particle* particle = source->particle;
    source->FUN_00c90510();
    if (self->previousParticle)
        self->previousParticle->FUN_00c905b0();
    self->previousParticle = source;
    if (!particle)
        return;
    unsigned int priority = particle->startFrame;
    unsigned int sizeFlag = self->targetFrame;
    if (priority > self->currentFrame || (particle->flags & 0x4000u))
        return;
    {
        NiPoint3 adjusted;
        ParticleVectorLocal_00c6f500 ownVelocity = *source->hkpCharacterProxy_getLinearVelocity();
        ParticleVectorLocal_00c6f500 normal = transform[1];
        normal.At(2) = 0.0f;
        if (float(normal.LengthSq()) > 0.0f)
            normal.Normalize();
        owner = static_cast<ControllerOwner*>(self);
        ownVelocity = *owner->bhkCharacterProxy_GethkLinearVelocity();
        ownVelocity.At(2) = 0.0f;
        float speed = ownVelocity.Length();
        if (sizeFlag == 2)
            speed += DAT_0102fc70;
        speed *= DAT_0109c9e0;
        normal.Mul(speed);
        FUN_00458620(&adjusted, &normal);
        particle->AddPush(normal);
        particle->UpdateMaxVelocity(&adjusted, 0.01f);
    }
    if (!(particle->flags & 1u))
        return;
    ParticleVectorLocal_00c6f500 separation = transform[0];
    separation.Sub(*particle->bhkCharacterProxy_GethkPosition());
    separation.At(2) = 0.0f;
    ParticleVectorLocal_00c6f500 projection = particle->localDirection;
    projection.At(2) = 0.0f;
    projection.Normalize();
    float along = separation.Dot(projection);
    projection.Mul(along);
    float scale = float(projection.Length()) / (particle->lifetime * DAT_01011588) - DAT_0103c7c8;
    ParticleVectorLocal_00c6f500 otherNormal = transform[1];
    otherNormal.At(2) = 0.0f;
    otherNormal.Normalize();
    ParticleVectorLocal_00c6f500 current = *owner->bhkCharacterProxy_GethkLinearVelocity();
    current.At(2) = 0.0f;
    float angle = 0.0f;
    if (current.NormalizeNonzero())
        angle = -otherNormal.Dot(current);
    scale *= angle;
    scale = BSMAX_00404010(0.0f, BSMIN(1.0f, scale));
    if (scale > 0.0f)
    {
        ParticleVectorLocal_00c6f500 side;
        side.Cross(separation, projection);
        if (side.At(2) > 0.0f)
            scale *= DAT_0101a6b0;
        scale *= 2.0f;
        particle->UpdateLargestAbsoluteThreshold(scale, DAT_0101df44);
    }
}
