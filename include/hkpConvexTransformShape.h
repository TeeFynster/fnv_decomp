#pragma once

#include "hkpConvexTransformShapeBase.h"
#include "hkTransform.h"

class hkpConvexTransformShape : public hkpConvexTransformShapeBase
{
public:
    hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform, int ref = 1);

    const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }

    const hkpConvexShape* GetShapeForKey() const;

    hkTransform m_kMotionTransform;
};
