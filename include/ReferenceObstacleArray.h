#pragma once

#include "NiRefObject.h"

class ReferenceObstacleArray : public NiRefObject
{
public:
    virtual ~ReferenceObstacleArray();
    void* DestroyIfFlagged(unsigned int flags);

    unsigned int formID;
};
