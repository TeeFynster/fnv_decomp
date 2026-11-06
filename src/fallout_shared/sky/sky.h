#ifndef FNV_FALLOUT_SHARED_SKY_SKY_H
#define FNV_FALLOUT_SHARED_SKY_SKY_H

#include "sky_Dependencies.h"

// @fnv 0x0046dd00
Sky* Sky::GetInstance()
{
    if (!pInstance)
    {
        AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true, "..\\Fallout Shared\\Sky\\Sky.h", 0x118);
        pInstance = new Sky;
    }
    return pInstance;
}

// @fnv 0x0059e950
bool Sky::IsRaining()
{
    return (m_pRegionWeather && m_pRegionWeather->IsRainy() &&
            m_fWeatherBlend > m_pRegionWeather->GetWeatherData(6, 0.999f, 0.0f)) ||
           (m_pPreviousWeather && m_pPreviousWeather->IsRainy() &&
            m_fWeatherBlend < m_pPreviousWeather->GetWeatherData(7, 1.0f, 0.001f));
}
#endif
