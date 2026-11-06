#pragma once

class NavMesh;

class NavMeshTriangleEdgeReference
{
public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    unsigned char layoutPadding6[2];
    int m_iEdgeIndex;
};
