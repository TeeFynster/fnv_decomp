
// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bshavok/bhksphereshape.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x0056e9f0  bhkSphereShape::GetRTTI                 (16 bytes)
#include "../../include/bhkConvexShape.h"
#include "../../include/bhkSphereShape.h"

// @fnv 0x0056e9f0
const NiRTTI* bhkSphereShape::GetRTTI() const
{
    return &ms_kRTTI;
}
