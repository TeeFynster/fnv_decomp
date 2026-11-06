#pragma once

#include "BSSimpleArray.h"
#include "NiPoint3.h"

class ParentSpaceNode;
class TeleportLink;

class PathingPath
{
public:
    BSSimpleArray<ParentSpaceNode, 1024> Spaces; // +0x00
    BSSimpleArray<TeleportLink, 1024> Doors;     // +0x10
    NiPoint3 Start;                              // +0x20
    NiPoint3 End;                                // +0x2c

    PathingPath();
    ~PathingPath();
    float CalculatePathDistance();
    void Clear();
#if !defined(_MSC_VER) || defined(__vecDelDtor)
    void* __vecDelDtor(unsigned int);
#endif
    // MSVC supplies __vecDelDtor(unsigned int) from the destructor.
};
