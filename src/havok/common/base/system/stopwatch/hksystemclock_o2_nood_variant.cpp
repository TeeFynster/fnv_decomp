// src/havok/common/base/system/stopwatch/hksystemclock_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/havok/common/base/system/stopwatch/hksystemclock.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/havok/common/base/system/stopwatch/hksystemclock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/stopwatch/hksystemclock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

__declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* lpPerformanceCount);
__declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* lpFrequency);

extern double DAT_0106b798;

struct Obj
{
    virtual long long v0();
    virtual long long v1();
    virtual long long v2();
    virtual long long GetCounter();
    unsigned __int64 hkWindowsSystemClock_getTicksPerSecond();
};

unsigned __int64 g_freq;

// @fnv 0x00dd8e20
// src: HAVOK_LIB 0x00dd8e20
unsigned __int64 Obj::hkWindowsSystemClock_getTicksPerSecond()
{
    if (g_freq != 0)
        return g_freq;

    double best = DAT_0106b798;
    int count = 10;
    while (count != 0)
    {
        long long t1 = this->GetCounter();
        __int64 q1;
        QueryPerformanceCounter(&q1);
        volatile int busy = 1;
        for (int i = 0x1388; i != 0; --i)
        {
            busy = busy * busy + busy;
        }
        long long t2 = this->GetCounter();
        __int64 q2;
        QueryPerformanceCounter(&q2);
        QueryPerformanceFrequency((__int64*)&g_freq);

        unsigned __int64 num = (unsigned __int64)(t2 - t1);
        unsigned __int64 den = (unsigned __int64)(q2 - q1);
        double ratio = (double)num / (double)den;
        if (best > ratio)
            best = ratio;
        --count;
    }
    g_freq = (unsigned __int64)(best * (double)g_freq);
    return g_freq;
}
