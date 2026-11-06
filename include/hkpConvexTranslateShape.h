#pragma once

#include "hkpConvexTransformShapeBase.h"
#include "hkVector4.h"

class hkpConvexTranslateShape : public hkpConvexTransformShapeBase
{
public:
    hkpConvexTranslateShape(const hkpConvexShape* childShape, const hkVector4& translation, int ref = 1);
    virtual ~hkpConvexTranslateShape() throw();

    const hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }

    const hkpConvexShape* GetShapeForKey() const;
    hkpConvexTranslateShape* init(const hkpConvexShape* child, const hkVector4& translation);

    hkVector4 m_vTranslation;
};
