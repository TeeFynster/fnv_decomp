// Distinct original implementations share reconstructed identifiers.
// Keep each matched body under its own address-qualified name.
#define ProcessAgent ProcessAgent_fnv_00dacd50

// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Preserve the original intrinsic views: the CRT byte arrays would add /GS instrumentation to SIMD locals.
#define _INCLUDED_MM2
// Exe 0x00dacd50 ProcessAgent: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_load_ss(const float*);
    float _mm_cvtss_f32(LocalM128);
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
    void _mm_store_ss(float*, LocalM128);
}

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpGskfAgent.h"
#include "../../../../../../../include/hkpCdBody.h"

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);

extern DWORD DAT_0126835c;
extern const char str_010ceca0[];

inline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}
inline char* __cdecl hkMonitorStream::getEnd()
{
    return m_end.m_storage;
}
inline void __cdecl hkMonitorStream::setEnd(char* e)
{
    m_end.m_storage = e;
}
struct SweepFactors
{
    union
    {
        volatile unsigned int ticks;
        float a;
    };
    union
    {
        volatile unsigned int laterTicks;
        float b;
    };
};

__forceinline float& hkVector4::operator()(int i)
{
    return ((float*)&m_vComponents)[i];
}
inline const float& hkVector4::operator()(int i) const
{
    return ((const float*)&m_vComponents)[i];
}

struct GskAgentInput
{
    int unk00;
    int unk04;
    float m_fScalar;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

static __forceinline void calcTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, float deltaTime,
                                      hkVector4& timInfo, SweepFactors& work)
{
    work.b = deltaTime;
    work.a = work.b * (*(const volatile float*)&(ms0.m_kSweptTransform.m_vCenterOfMass1(3)));
    work.b *= ms1.m_kSweptTransform.m_vCenterOfMass1(3);
    LocalM128 r0 = _mm_load_ss(&work.a);
    LocalM128 s0 = _mm_shuffle_ps(r0, r0, 0);
    timInfo.m_vComponents = (_mm_add_ps(
        (_mm_mul_ps((_mm_sub_ps((ms0.m_kSweptTransform.m_vCenterOfMass0.m_vComponents), (ms0.m_kSweptTransform.m_vCenterOfMass1.m_vComponents))), s0)),
        (_mm_mul_ps((_mm_shuffle_ps((_mm_load_ss(&work.b)), (_mm_load_ss(&work.b)), 0)),
                    (_mm_sub_ps((ms1.m_kSweptTransform.m_vCenterOfMass1.m_vComponents), (ms1.m_kSweptTransform.m_vCenterOfMass0.m_vComponents)))))));
    timInfo(3) =
        (*(const volatile float*)&(ms0.m_kDeltaAngle(3))) * work.a * (*(const volatile float*)&(ms0.m_fObjectRadius)) +
        (*(const volatile float*)&(ms1.m_kDeltaAngle(3))) * work.b * (*(const volatile float*)&(ms1.m_fObjectRadius));
}

// @fnv 0x00dacd50
void hkpGskfAgent::ProcessAgent(const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input, WorldOperationEntry& result)
{
    SweepFactors work;
    hkVector4& separatingNormal = m_vSeparatingNormal;
    {
        hkMonitorStream& s = hkMonitorStream::getInstance();
        if (s.getEnd() < s.m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerBeginListCommand* h = (hkMonitorStream::TimerBeginListCommand*)s.getEnd();
            h->m_commandAndMonitor = "LtGskAgent";
            h->m_nameOfFirstSplit = "StTim";
            _ReadWriteBarrier();
            work.ticks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_time0 = work.ticks;
            s.setEnd((char*)(h + 1));
        }
    }
    if (m_fFloatValue != input.m_uiStartTime)
    {
        hkVector4 timInfo;
        calcTimInfo(*(const hkMotionState*)a.m_pMotionState, *(const hkMotionState*)b.m_pMotionState, input.m_fTimeStep, timInfo, work);
        if (separatingNormal(3) > input.m_fScalar)
        {
            LocalM128 p = _mm_mul_ps(separatingNormal.m_vComponents, timInfo.m_vComponents);
            LocalM128 w = _mm_shuffle_ps(timInfo.m_vComponents, timInfo.m_vComponents, 0xff);
            LocalM128 z = _mm_shuffle_ps(p, p, 0xaa);
            LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
            LocalM128 d = _mm_add_ps(_mm_add_ss(z, w), _mm_add_ss(y, p));
            _mm_store_ss(&work.b, d);
            separatingNormal(3) -= work.b;
            if (separatingNormal(3) > input.m_fScalar)
                goto END;
        }
    }
    {
        hkMonitorStream& s = hkMonitorStream::getInstance();
        if (s.getEnd() < s.m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s.getEnd();
            h->m_commandAndMonitor = str_010ceca0;
            _ReadWriteBarrier();
            work.laterTicks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_time0 = work.laterTicks;
            s.setEnd((char*)(h + 1));
        }
    }
    m_fFloatValue = input.m_fEndTime;
    ProcessGskCollision(a, b, input, result);
END: {
    hkMonitorStream& s = hkMonitorStream::getInstance();
    if (s.getEnd() < s.m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s.getEnd();
        h->m_commandAndMonitor = "lt";
        _ReadWriteBarrier();
        work.laterTicks = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_time0 = work.laterTicks;
        s.setEnd((char*)(h + 1));
    }
}
}
