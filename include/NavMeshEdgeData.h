#pragma once

class NavMesh;

class NavMeshEdgeData
{
public:
    NavMeshEdgeData();
    NavMeshEdgeData(NavMesh*, unsigned short, int);
    NavMeshEdgeData(const NavMeshEdgeData&);
    NavMeshEdgeData& operator=(const NavMeshEdgeData&);

    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int m_iEdgeIndex;
};
