#pragma once

// src: XBOX_PDB (MiscStatManager, empty utility class); AddMiscStat is exe 0x004d5e10.
class MiscStatManager
{
public:
    enum MiscStat
    {
        MS_STIMPAKS_TAKEN = 0x10,
        MS_RAD_AWAY_TAKEN = 0x12,
        MS_COUNT = 43
    };
    static void AddMiscStat(MiscStat stat, int delta);
};
