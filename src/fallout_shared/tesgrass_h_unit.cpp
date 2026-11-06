#include "../../include/TESGrass.h"

// @fnv 0x0082d680
unsigned short TESGrass::GetUnitsFromSurface()
{
    return Data.m_usUnitsFromSurface;
}

// @fnv 0x0058e430
void TESGrass::SetUnderwater(GRASS_WATER_STATE state)
{
    Data.m_eWaterState = static_cast<TESGrass__GRASS_WATER_STATE>(state);
}
