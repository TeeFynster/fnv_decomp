#pragma once

#include "NiRefObject.h"

class ObstacleUndoData : public NiRefObject
{
public:
    virtual ~ObstacleUndoData();
    void* Destroy(unsigned int flags);
};
