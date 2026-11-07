#pragma once

#include "NiPoint3.h"
#include "BSSimpleArray.h"

class NavMeshBounds
{
public:
    // RTTI BSSimpleArray<NavMeshBounds::NavMeshBoundsTriangle,1024> (vftable 0x0106b28c); 6 bytes, GetAt 0x0069ccf0
    // scales the index by 6 and 0x0069c070 reads three vertex indices from it
    struct NavMeshBoundsTriangle
    {
        unsigned short a, b, c;
    };

    NiPoint3 min;
    NiPoint3 max;
    BSSimpleArray<NavMeshBoundsTriangle, 1024> triangles;
    // BSSimpleArray<NiPoint3,1024> (RTTI vftable 0x0101e114): 12-byte elements (0x006a1440, CopyTo 0x0069cfe0), the
    // vertices 0x0069c070 indexes; src: COMMUNITY (JIP NavMeshBounds pointArr at +0x28)
    BSSimpleArray<NiPoint3, 1024> vertices;

    NavMeshBounds();
    ~NavMeshBounds();
    void CopyTo(NavMeshBounds* other);
    NiPoint3 DistanceFromPointToBounds(const NiPoint3& point);
    bool ContainsPoint(const NiPoint3& point);
};
