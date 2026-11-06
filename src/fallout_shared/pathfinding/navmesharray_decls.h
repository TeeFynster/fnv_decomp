#ifndef NAVMESHARRAY_DECLS_H
#define NAVMESHARRAY_DECLS_H

class NavMesh;
#include "../../../include/NavMeshPtr.h"
class GlobalObject_00869f00
{
  public:
    unsigned int GetSize();
    NavMesh*& GetAt(unsigned int);
};
NavMeshPtr MakeNavMeshPointer(NavMesh*);
#endif
