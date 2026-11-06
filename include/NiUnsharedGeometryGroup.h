#pragma once

#include "NiGeometryGroup.h"

class NiUnsharedGeometryGroup : public NiGeometryGroup
{
public:
    virtual ~NiUnsharedGeometryGroup();

    void* __thiscall Destroy(unsigned int flags);
    static NiGeometryGroup* Create();

};
