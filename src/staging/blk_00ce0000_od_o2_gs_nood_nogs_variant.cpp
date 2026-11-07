// staging/blk_00ce0000_od_o2_gs_nood_nogs_variant.cpp: RayCaster (3 functions)

#include <windows.h>
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
// src/staging/blk_00ce0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00ce0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00ce0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct Vec4Target
{
    __m128 m_v0;
    __m128 m_v1;
    void __thiscall setMul(const __m128* a, const __m128* b);
};

__declspec(align(16)) struct Vec4Pod
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};

// @fnv 0x00ce2ca0
// src: GUESS 0x00ce2ca0 (confidence: low)
void Object_UpdateFields_00ce2ca0(void* unused, __m128* dst, const __m128* a, const __m128* b)
{
    dst[0] = _mm_add_ps(_mm_mul_ps(a[2], b[0]), a[0]);
    ((Vec4Target*)(dst + 1))->setMul(a + 1, b + 1);
    dst[2] = b[2];
}

extern const __m128 DAT_010c4c10;

struct FUN_00cf2280_cls
{
    __m128 m_00;
    __m128 m_10;
    __m128 m_20;
    __m128 m_30;
    __m128 m_40;

    void hkSweptTransform_initSweptTransform(const __m128* a, const __m128* b);
};

// @fnv 0x00cf2280
// src: XBOX_PDB 0x00cf2280
void FUN_00cf2280_cls::hkSweptTransform_initSweptTransform(const __m128* a, const __m128* b)
{
    m_00 = _mm_and_ps(*a, DAT_010c4c10);
    m_10 = _mm_and_ps(*a, DAT_010c4c10);
    m_20 = *b;
    m_30 = *b;
    m_40 = _mm_setzero_ps();
}

extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct RayInput
{
    __m128 m_vFrom;
    __m128 m_vTo;
    unsigned char m_bFlag;
};

struct RayCastQuery
{
    __m128 m_vFrom;
    int m_iOne;
    const __m128* m_pTo;
    int m_uiLogicalSize;
    int m_iZero;
};

class RayCaster;

class RayWorld
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void CastRay(RayCastQuery* q, RayCaster* c, int z);
};

class RayCaster
{
  public:
    void UpdateFields_00cfaa40(RayWorld* world, RayInput* input, char* source, int a4);

    int unk00;
    RayInput* m_pInput;
    char* m_pSource14;
    int m_i0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    char* m_pSource10;
};

// @fnv 0x00cfaa40
// src: GUESS 0x00cfaa40 (confidence: low)
void RayCaster::UpdateFields_00cfaa40(RayWorld* world, RayInput* input, char* source, int a4)
{
    volatile DWORD tick;
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtRayCastSimpl";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    m_pInput = input;
    m_i0C = a4;
    m_pSource14 = source ? source + 0x14 : 0;
    if (input->m_bFlag)
        m_pSource10 = source ? source + 0x10 : 0;
    else
        m_pSource10 = 0;

    RayCastQuery q;
    __m128 from = _mm_load_ps((const float*)&input->m_vFrom);
    q.m_pTo = &input->m_vTo;
    q.m_iOne = 1;
    q.m_uiLogicalSize = 0x10;
    q.m_iZero = 0;
    _mm_store_ps((float*)&q.m_vFrom, from);
    world->CastRay(&q, this, 0);

    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}
