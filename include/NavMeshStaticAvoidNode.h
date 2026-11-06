#pragma once

#include "PathingAvoidNode.h"

class NavMeshStaticAvoidNode : public PathingAvoidNode
{
public:
    unsigned short m_usTriangleID;
    unsigned char layoutPadding26[2];

    unsigned short GetShortValueAtOffset24();
    float GetFloatAtOffset1C();
};
