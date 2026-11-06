// gamebryo2.2/corelibs/nicollision/nicollisionutils_decls.h: declares RayTriangleIntersector

#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiPosData.h"

class RayTriangleIntersector
{
  public:
    static bool IntersectRayTriangle(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&,
                                     const NiPoint3&, bool, NiPoint3&, float&, float&, float&);
};
