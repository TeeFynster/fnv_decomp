#pragma once

#include "hkReferencedObject.h"

class hkResourceBase : public hkReferencedObject
{
public:
    enum Type
    {
        TYPE_RESOURCE = 0,
        TYPE_CONTAINER = 1
    };
};
