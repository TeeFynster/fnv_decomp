#pragma once

#include "NiPoint3.h"

class NavMesh;
class NavMeshTriangle;

class NavMeshTriangleReference
{
public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    float m_fCenterX;
    float m_fCenterY;
    float m_fCenterZ;

    NiPoint3 FUN_006a6eb0() const;
    NavMeshTriangle* FUN_006a78d0() const;
    NavMeshTriangle* GetTriangle();
    void SetGridPosition(void*);
};
