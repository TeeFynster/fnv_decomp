#include "../../../include/Pathing.h"
#include "../../../include/NavMeshBounds.h"
#include "../../../include/PathBuilderDetailedPathInfos.h"
class FindTriangleForLocationFilter;

class PathingLocationArray
{
  public:
    void ConstructItems(PathingLocation*, unsigned int);
};



extern TES* g_TES;
const BSSimpleArray<const NavMeshInfo*, 1024>* Pathing_GetPotentialNavMeshInfoForLocation(TESObjectCELL*);
const BSSimpleArray<const NavMeshInfo*, 1024>* ForwardToPathing(TESWorldSpace*, unsigned int);



extern double DAT_0106cd60;
