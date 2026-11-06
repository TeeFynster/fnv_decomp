#pragma once

// Havok 7.1 hkpGsk status (values: the 7.1.0-r1 hkpcollide.pdb).
enum hkpGskStatus
{
    HK_GSK_OK = 0,
    HK_GSK_PD_HEURISTIC_SAMPLING = 1,
    HK_GSK_PD_OUT_OF_MEMORY = 2,
    HK_GSK_PD_UNSOLVABLE = 3,
    HK_GSK_PENETRATING = 4
};
