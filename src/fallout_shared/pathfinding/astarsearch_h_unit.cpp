// fallout_shared/pathfinding/astarsearch_h_unit.cpp: free functions (1 function)

#include "astarsearch.h"

struct FUN_00996840_shell
{
    unsigned int __thiscall AStarNodeMap_GetBucketIndex(unsigned int a);
};

// @fnv 0x00996840
// src: COMMUNITY 0x00996840
unsigned int __thiscall FUN_00996840_shell::AStarNodeMap_GetBucketIndex(unsigned int auiValue)
{
    return auiValue % 0x7f7;
}
