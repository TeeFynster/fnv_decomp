// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// This RTM unit owns only FUN_00d892f0; unused parent-unit scaffolding was removed.
// Exe 0x00d892f0 FUN_00d892f0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps();

extern "C"
{
    LocalM128 _mm_load_ps1(const float* p);
    LocalM128 _mm_load_ss(const float* p);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
}

#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkVector4.h"

// Havok's inline bodies (hkVector4.inl) for the forms the shared header only declares; the original inlines them.
__forceinline hkSimdReal::hkSimdReal(const LocalM128& x) { m_vValue = x; }
__forceinline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& a) { m_vComponents = _mm_mul_ps(r.m_vValue, a.m_vComponents); }
__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& a) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.m_vValue, a.m_vComponents)); }
__forceinline hkSimdReal hkVector4::getSimdAt0() const { return _mm_shuffle_ps(m_vComponents, m_vComponents, 0); }

struct D892Params
{
    hkVector4 unk00;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 m_fGain;
};

struct D892State
{
    int unk00;
    int unk04;
    float m_dt;
    int unk0c;
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;
    hkVector4 unk30;
    hkVector4 m_errorA;
    hkVector4 m_errorB;
};

// @fnv 0x00d892f0
// src: GUESS 0x00d892f0 (confidence: low)
static __declspec(noinline) void hkVector4_UpdateState_00d892f0(const D892Params* params, bool update, D892State* state,
                                              const hkVector4* vel, const hkVector4* damping)
{
    LocalM128 dt = _mm_load_ss(&state->m_dt);
    hkVector4 dtVel;
    dtVel.setMul4(hkSimdReal(_mm_shuffle_ps(dt, dt, 0)), *vel);
    hkVector4 d0;
    d0.setSub4(state->m_vContactPosition, state->m_errorA);
    hkVector4 d1;
    d1.setSub4(state->m_fVelocity, state->m_errorB);
    state->m_errorA.addMul4(params->m_fGain.getSimdAt0(), d0);
    state->m_errorB.addMul4(params->m_fGain.getSimdAt0(), d1);
    if (!update)
    {
        state->m_fVelocity.setAdd4(state->m_errorB, d1);
        hkVector4 pos;
        pos.setAdd4(d0, state->m_errorA);
        pos.add4(dtVel);
        state->m_vContactPosition = pos;
    }
    else
    {
        state->m_errorA.mul4(*damping);
        {
            hkVector4& eB = state->m_errorB;
            eB.setMul4(*damping, eB);
        }
        state->m_fVelocity = d1;
        state->m_vContactPosition = d0;
    }
}

void D892_Entry(const D892Params* params, bool update, D892State* state, const hkVector4* vel, const hkVector4* damping)
{
    hkVector4_UpdateState_00d892f0(params, update, state, vel, damping);
}
