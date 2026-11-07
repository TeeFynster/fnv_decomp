#pragma once

#include "AStarSearch.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class NavMeshSearchNode;
class NavMeshSearchLink;
class NavMeshTriangleReference;
class NavMeshTriangleEdgeReference;
class NavMesh;
class PathingRequest;
class FleeStartNode;
class FleePath;
class Node;
class NodeArray;
enum SearchResult;

typedef AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference> SearchNode;

class NavMeshSearchFlee : public AStarSearch<NavMeshSearchNode, NavMeshSearchLink>
{
public:
    virtual ~NavMeshSearchFlee();
    virtual bool ExpandNode(Node* node, NodeArray* output);
    virtual bool IsNodeValid(const SearchNode* apNode);

    void* DestroyIfFlagged(unsigned int flags);
    const SearchNode* GetFieldAt2050();
    void SetNodeFleeCost(SearchNode* apNode, NavMesh* apNavMesh, unsigned short aiTriangle);
    unsigned int GetKeyForNode_006a94f0(NavMesh*, unsigned short);
    unsigned int GetKeyForNode_006a94f0();
    SearchNode* FUN_006a7c90(unsigned int, const FleeStartNode*, float);
    bool FUN_006a7d60(FleePath*, unsigned int, bool);
    SearchResult FUN_006a7e00(unsigned int, NavMesh*, unsigned short, float, Node**);
    bool StartFleeSearch(PathingRequest* request, const FleeStartNode* start,
                         FleePath* path, unsigned int limit);

    unsigned int pad0[0x2054 / 4];
    PathingRequest* pRequest;
    unsigned int pad205c[5];
    NiPoint3 kAvoidVector;
    float fFleeRange;
    bool bHasDestination;
    NiPoint3 kDestination;
};
