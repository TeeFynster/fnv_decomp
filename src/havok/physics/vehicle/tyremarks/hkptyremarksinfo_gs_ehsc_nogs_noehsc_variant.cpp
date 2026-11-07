
// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/tyremarks/hkptyremarksinfo.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/vehicle/tyremarks/hkptyremarksinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/tyremarks/hkptyremarksinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkpTyremarksWheel.h"

struct __declspec(align(16)) hkpTyremark
{
    hkVector4 m_kPointA, m_kPointB;
};

__declspec(noinline) hkpTyremark* __thiscall hkpTyremarksWheel::ComputeIndex(int index)
{
    return &m_data[(m_iMaxNumTyremarks + index) % m_numTyremarks];
}

struct S00e39e90_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkArray<hkpTyremarksWheel*> m_kTyremarksWheels;

    void __thiscall hkpTyremarksInfo_getWheelTyremarksStrips(int arg1, int wheelIndex, hkpTyremark* out);
};

// @fnv 0x00e39e90
// src: HAVOK_SRC 0x00e39e90
void __thiscall S00e39e90_Info::hkpTyremarksInfo_getWheelTyremarksStrips(int arg1, int wheelIndex, hkpTyremark* out)
{
    hkpTyremarksWheel* wheel = m_kTyremarksWheels.m_data[wheelIndex];
    int n = wheel->m_numTyremarks;
    int i = 0;

    if (n > 0)
    {
        hkpTyremark* dst = out;

        do
        {
            hkpTyremark* src = wheel->ComputeIndex(i);
            _mm_store_ps(&dst->m_kPointA.x, _mm_load_ps(&src->m_kPointA.x));
            _mm_store_ps(&dst->m_kPointB.x, _mm_load_ps(&src->m_kPointB.x));
            i++;
            dst++;
        } while (i < n);
    }
}
