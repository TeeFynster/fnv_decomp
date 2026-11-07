#pragma once

#include "NiGeometryGroup.h"
#include "NiTPointerMap.h"

class NiVBSet;

class NiStaticGeometryGroup : public NiGeometryGroup
{
public:
    NiStaticGeometryGroup();

    virtual void Purge();
    virtual ~NiStaticGeometryGroup();

    void Purge_00e946b0();
    void FUN_00e98710();
    void* Destroy(unsigned int);

    NiTPointerMap<unsigned int, NiVBSet*> map;
};
