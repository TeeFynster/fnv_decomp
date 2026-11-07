
// src/fallout_shared/pathfinding/navmeshmath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshmath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiPoint2.h"
#include "../../../include/NiPoint3.h"
bool __cdecl ComputeBarycentricCoordinates(const NiPoint2&, const NiPoint2&, const NiPoint2&, const NiPoint2&,
                                           NiPoint3*);
// @fnv 0x006b9790
// src: XBOX_PDB 0x006b9790
bool __cdecl NavMeshMath_Get2DBaryCentricCoord(const NiPoint3& aPoint1, const NiPoint3& aPoint2, const NiPoint3& aPoint3,
                          const NiPoint3& aPoint4, NiPoint3* out)
{
    return ComputeBarycentricCoordinates(NiPoint2(aPoint1.x, aPoint1.y), NiPoint2(aPoint2.x, aPoint2.y),
                                         NiPoint2(aPoint3.x, aPoint3.y), NiPoint2(aPoint4.x, aPoint4.y), out);
}
