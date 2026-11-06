// bscore/bstimer.cpp: free functions (4 functions)

#include "../../include/GameTimerRecord.h"

// The engine tick-count helper lives outside this unit; the PC build resolves
unsigned int gm_GetTickCount();

// kernel32 tick count, reached directly through the import address table.
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

// Decrements the reference count and, when it reaches zero, records elapsed tick counts for two timestamps.
// @fnv 0x00aa5040
void GameTimerRecord::Enable()
{
    if (m_ucFirstTimerByte)
    {
        if (--m_ucFirstTimerByte == 0)
        {
            unsigned int uiTickCount = GetTickCount();
            m_uiFirstTimerValue = uiTickCount - m_uiFirstTimerValue;
            m_uiSecondTimerValue = uiTickCount - m_uiSecondTimerValue;
        }
    }
}

// @fnv 0x00771520
void GameTimerRecord::Update()
{
    Update(gm_GetTickCount());
}

extern float DAT_011ac3a0;
extern float DAT_011ac3a4;

// @fnv 0x00aa4db0
void GameTimerRecord::SetGlobalTimeMultiplier(float afMult, bool abNow)
{
    bool bUseGlobal = m_bFirstTimerFlag;
    if (bUseGlobal)
    {
        DAT_011ac3a4 = afMult;
        if (abNow)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
    else
    {
        DAT_011ac3a4 = afMult;
        if (afMult == DAT_011ac3a0)
        {
            return;
        }
        fTimeSinceScaleStart /= DAT_011ac3a0;
        DAT_011ac3a0 = afMult;
        fTimeSinceScaleStart *= DAT_011ac3a0;
    }
}

extern float DAT_011ac3a0;
extern float DAT_011ac3a4;
extern float DAT_011ac3ac;

// Moves DAT_011ac3a0 toward DAT_011ac3a4 by a fraction of DAT_011ac3ac, clamping so it does not overshoot the target.
// @fnv 0x00aa4e40
void GameTimerRecord::UpdateGlobalTimeMultiplier()
{
    if (DAT_011ac3a0 < DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f + DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 > DAT_011ac3a4)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
    else if (DAT_011ac3a0 > DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f - DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 < DAT_011ac3a4)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
}
