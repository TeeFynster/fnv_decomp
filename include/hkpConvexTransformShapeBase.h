#pragma once

#include "hkpConvexShape.h"
#include "hkpSingleShapeContainer.h"

class hkpConvexTransformShapeBase : public hkpConvexShape
{
public:
    hkpConvexTransformShapeBase(int type, float radius, const hkpConvexShape* childShape, int ref);

    virtual void vf17();

    const hkpConvexShape* GetShapeForKey() const;

    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
};
