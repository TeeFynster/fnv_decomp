#pragma once

class NavMesh;
class PathQuery;

class PathNode
{
public:
    NavMesh* mesh;
    unsigned short tri;
    unsigned char unk06[2];
    int edge;

    PathNode(const PathNode*);
    void FUN_005ae3d0(char* const& value);
    PathQuery* PathingSolution_GetLastVirtualNode();
    float GetHeuristic();
};
