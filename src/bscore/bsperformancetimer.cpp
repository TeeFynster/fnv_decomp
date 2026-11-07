// bscore/bsperformancetimer.cpp: PerformanceTimerManager (3 functions)

#include "bsperformancetimer_decls.h"
// @fnv 0x0045d260
PerformanceMeasurement* PerformanceTimerManager::Register(char*, char*, bool, bool)
{
    return reinterpret_cast<PerformanceMeasurement*>(this);
}
// @fnv 0x007005d0
PerformanceTimerManager* PerformanceTimerManager::BeginFrame()
{
    m_ppMeasurements = 0;
    m_iTimerCount = 0;
    for (int i = 0; i < 3; ++i)
    {
        DAT_011d8830[i].active = false;
        DAT_011d8830[i].count = 0;
        DAT_011d8830[i].time = 0.0f;
        DAT_011d8830[i].object = 0;
    }
    return this;
}

void* __cdecl operator new(unsigned int);

struct FUN_006ff690
{
    FUN_006ff690();
    char pad[0x44];
};

extern FUN_006ff690* DAT_011d8794;

// Returns the global FUN_006ff690 instance, constructing it with new if it has not been created yet.
// @fnv 0x006ff580
// src: COMMUNITY 0x006ff580
FUN_006ff690* __cdecl SteamAPICallbacks_GetSingleton()
{
    if (!DAT_011d8794)
        DAT_011d8794 = new FUN_006ff690;
    return DAT_011d8794;
}
