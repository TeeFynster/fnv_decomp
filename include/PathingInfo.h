#pragma once

#include "BSSimpleArray.h"
#include "PathingPath.h"

class PathingInfoEntry;
class NavMeshInfo;
class TESObjectREFR;

class PathingInfo
{
public:
    BSSimpleArray<PathingInfoEntry, 1024> Items;
    unsigned int m_uiNavMeshInfoCount;
    BSSimpleArray<const NavMeshInfo*, 1024> NavMeshInfoPointerArray;
    BSSimpleArray<TESObjectREFR*, 1024> TESObjectReferenceArray;
    PathingPath NavMeshReferenceCollection;

    PathingInfo();
    ~PathingInfo();
};
