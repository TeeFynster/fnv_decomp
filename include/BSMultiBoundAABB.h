#pragma once

#include "BSMultiBoundShape.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "Vec4.h"

class BSMultiBoundAABB : public BSMultiBoundShape
{
public:
    NiPoint3 Center;
    NiPoint3 m_kOffset;

    BSMultiBoundAABB();
    virtual ~BSMultiBoundAABB();
    virtual int GetDebugGeomShapeSize();
    virtual void SetGridPosition(const NiPoint3& center);

    const Vec57& extent();
    void setExtent(const Vec57& extent);

    float GetPointLength();
    void BSMultiBoundAABB_GetVertices(NiPoint3* points);
    void GetNiBound(Vec4* point);
    void* FUN_004a7060(unsigned int flags);
};
