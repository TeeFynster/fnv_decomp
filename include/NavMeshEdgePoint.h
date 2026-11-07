#pragma once

class NavMeshEdgePoint
{
public:
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;

    NavMeshEdgePoint();
    NavMeshEdgePoint(const NavMeshEdgePoint&); // 0x006a0e50 (0x006b1e50 copy-constructs through it)
    NavMeshEdgePoint& operator=(const NavMeshEdgePoint& src);
    NavMeshEdgePoint& CopyFields_006dbb40(const NavMeshEdgePoint& src);
};
