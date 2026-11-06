// fallout_shared/pathfinding/navmesharray.h: declares NavMeshCollection
#ifndef NAVMESHARRAY_H
#define NAVMESHARRAY_H

#include "navmesharray_decls.h"
#include "../../../include/NavMeshCollection.h"
// @fnv 0x00464f60
NavMeshPtr NavMeshCollection::GetNavMeshAt(unsigned int index)
{
    if (index >= reinterpret_cast<GlobalObject_00869f00*>(data)->GetSize())
        return MakeNavMeshPointer(0);
    return reinterpret_cast<const NavMeshPtr&>(reinterpret_cast<GlobalObject_00869f00*>(data)->GetAt(index));
}
#endif
