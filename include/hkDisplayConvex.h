#pragma once

#include "hkDisplayGeometry.h"

class hkGeometry;

class hkDisplayConvex : public hkDisplayGeometry
{
public:
    hkGeometry* m_pSourceGeometry;

    hkDisplayConvex(hkGeometry* geom);
};
