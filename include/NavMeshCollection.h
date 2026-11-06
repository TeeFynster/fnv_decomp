#pragma once

#include "NavMeshPtr.h"

class NavMeshCollection
{
public:
    unsigned int data[4];

    NavMeshCollection();
    NavMeshPtr GetNavMeshAt(unsigned int index);
    void AppendNavMesh(NiPointer<NavMesh> mesh);
    unsigned int FUN_0044ddc0();
    NavMeshPtr& FUN_00877a30(unsigned int i);
    void RemoveAndCollect(unsigned int index);
};
