#pragma once

#include "NavMeshPOVSearch.h"

class PathSmootherPOVPoint;

class PathSmootherPOVAvoidanceNode
{
public:
    PathSmootherPOVPoint* m_pAvoidNode;
    ANGLE_DIRECTION Direction;
    float m_fPathDistance;
};
