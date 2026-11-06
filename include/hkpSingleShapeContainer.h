#pragma once

#include "hkpShapeContainer.h"

class hkpSingleShapeContainer : public hkpShapeContainer
{
public:
    static const ClassMemberDescriptor Members[];

    hkpSingleShapeContainer(hkpShape* child, int ref);

    virtual ~hkpSingleShapeContainer();
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const;

    inline const hkpShape* getChild() const
    {
        return m_pContainedShape;
    }

    const hkpShape* m_pContainedShape;
};
