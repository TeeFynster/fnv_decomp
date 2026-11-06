#pragma once

class NiPoint3;

class NavMeshEdgeVertexPair
{
public:
    const NiPoint3* p1;
    const NiPoint3* p2;

    NavMeshEdgeVertexPair();
};
