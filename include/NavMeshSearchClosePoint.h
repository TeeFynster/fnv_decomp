#pragma once

#include "AStarSearch.h"

class NavMeshSearchNode;
class NavMeshSearchLink;
class NavMeshTriangleReference;
class NavMesh;
class NMNode;
class NMNodeArray;

class NavMeshSearchClosePoint : public AStarSearch<NavMeshSearchNode, NavMeshSearchLink>
{
public:
    virtual ~NavMeshSearchClosePoint();
    virtual bool AddAdjacentNodes(NMNode* apNode, NMNodeArray* apNodes);
    virtual bool IsNodeWithinSearchCriteria(NavMeshTriangleReference* apNode);

    void SetNodeFromTriangle(NavMeshTriangleReference* node, NavMesh* mesh,
                             unsigned short triangle);

    float fAvoidRadius;
};
