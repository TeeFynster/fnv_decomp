#pragma once

#include "NavMeshSearch.h"
#include "NiPoint3.h"

class NavMeshSearchLocation;
class PathingLocation;
class PathBuilderDetailedPathInfos;
class Mesh;
class Location;
class OpenSet;
class ClosedSet;
class Node;
class NodeOutput;

class NavMeshSearchMaxCost : public NavMeshSearch
{
public:
    NavMeshSearchMaxCost();
    virtual ~NavMeshSearchMaxCost();
    virtual bool CollectConnections(const SearchNode*, BSSimpleArray<SearchNode*, 1024>*);
    virtual bool HasReachedGoal(const SearchNode*);

    void UpdateFields_006ab480();
    void* __thiscall Destroy(unsigned int flags);
    int GetField2048();
    bool IsGoalNode_006abb60(const SearchNode* apNode);

    bool StartSearch(int aiSearchType, NavMeshSearchLocation* apStart,
                     PathingLocation* apGoal, PathBuilderDetailedPathInfos* apInfos,
                     PathBuilderDetailedPathInfos* apAltInfos);
    void FUN_006a7c40();
    unsigned int GetKeyForNode_006a94f0(NavMesh* apNavMesh, unsigned short ausTriangle);
    void FUN_006a7c90(unsigned int auiNode, NavMeshSearchLocation* apStart, float afDistance);
    bool FUN_006a7d60(PathBuilderDetailedPathInfos* apInfos,
                      PathBuilderDetailedPathInfos* apAltInfos, bool abArg);

    NiPoint3 FindPath(int unused, Location* initial, NiPoint3* fallback, Location* target, float cost);
    unsigned int Index(Mesh*, unsigned short);
    void Add(unsigned int, Location*, float);
    using NavMeshSearch::Run;
    bool Run(OpenSet*, ClosedSet*, int);
    Node* Result();

    int FUN_006a7e00(unsigned int, float, NavMeshTriangleReference**);
    void FUN_006a6ef0(NavMeshTriangleReference*, NavMesh*, unsigned short);
    bool ExpandNeighborNodes(NavMeshTriangleReference* source, NodeOutput* output);
    void FUN_006a6b00();

    float maxCost;
    union
    {
        bool hasGoal;
        bool bHasGoal;
        bool flag;
    };
};
