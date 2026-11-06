#pragma once

class NavMeshEdgeData;

class NavMeshTriangleHandle
{
public:
    unsigned short m_usIndex;

    void Set(const NavMeshEdgeData&);
};

class NavMeshPOVData
{
public:
    NavMeshTriangleHandle m_kFirstEdge;
    NavMeshTriangleHandle m_kSecondEdge;
};
