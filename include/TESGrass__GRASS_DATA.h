#pragma once

#include <stddef.h>

enum TESGrass__GRASS_WATER_STATE
{
    TESGrass__GRASS_WATER_STATE_GWS_ABOVE_ONLY_ATLEAST = 0,
    TESGrass__GRASS_WATER_STATE_GWS_ABOVE_ONLY_ATMOST = 1,
    TESGrass__GRASS_WATER_STATE_GWS_BELOW_ONLY_ATLEAST = 2,
    TESGrass__GRASS_WATER_STATE_GWS_BELOW_ONLY_ATMOST = 3,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATLEAST = 4,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATMOST = 5,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATMOST_ABOVE = 6,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATMOST_BELOW = 7,
    TESGrass__GRASS_WATER_STATE_GWS_COUNT = 8
};

class TESGrass__GRASS_DATA
{
public:
    void ResetGrassData();

    unsigned char m_ucDensity;
    unsigned char m_ucMinSlope;
    unsigned char m_ucMaxSlope;
    unsigned char layoutPadding3[1];
    unsigned short m_usUnitsFromSurface;
    unsigned char layoutPadding6[2];
    TESGrass__GRASS_WATER_STATE m_eWaterState;
    float m_fPositionRange;
    float m_fHeightRange;
    float m_fWavePeriod;
    float m_fWavePhase;
    char cFlags;
    unsigned char layoutPadding1D[3];
};

typedef char TESGrass__GRASS_DATA_size_check[sizeof(TESGrass__GRASS_DATA) == 32 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_density_check[offsetof(TESGrass__GRASS_DATA, m_ucDensity) == 0x00 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_min_slope_check[offsetof(TESGrass__GRASS_DATA, m_ucMinSlope) == 0x01 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_max_slope_check[offsetof(TESGrass__GRASS_DATA, m_ucMaxSlope) == 0x02 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_padding3_check[offsetof(TESGrass__GRASS_DATA, layoutPadding3) == 0x03 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_units_check[offsetof(TESGrass__GRASS_DATA, m_usUnitsFromSurface) == 0x04 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_padding6_check[offsetof(TESGrass__GRASS_DATA, layoutPadding6) == 0x06 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_water_state_check[offsetof(TESGrass__GRASS_DATA, m_eWaterState) == 0x08 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_position_range_check[offsetof(TESGrass__GRASS_DATA, m_fPositionRange) == 0x0C ? 1 : -1];
typedef char TESGrass__GRASS_DATA_height_range_check[offsetof(TESGrass__GRASS_DATA, m_fHeightRange) == 0x10 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_wave_period_check[offsetof(TESGrass__GRASS_DATA, m_fWavePeriod) == 0x14 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_wave_phase_check[offsetof(TESGrass__GRASS_DATA, m_fWavePhase) == 0x18 ? 1 : -1];
typedef char TESGrass__GRASS_DATA_flags_check[offsetof(TESGrass__GRASS_DATA, cFlags) == 0x1C ? 1 : -1];
typedef char TESGrass__GRASS_DATA_padding1D_check[offsetof(TESGrass__GRASS_DATA, layoutPadding1D) == 0x1D ? 1 : -1];
