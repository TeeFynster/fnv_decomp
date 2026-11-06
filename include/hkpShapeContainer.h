#pragma once

#include "hkpShape.h"

struct hkpShapeBuffer;
struct ClassMemberDescriptor;

typedef unsigned int hkpShapeKey;

class hkpShapeContainer
{
public:
    static const ClassMemberDescriptor Members[];

    enum ReferencePolicy
    {
        REFERENCE_POLICY_IGNORE,
        REFERENCE_POLICY_INCREMENT
    };

    virtual ~hkpShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual hkpShapeKey GetFirstKey() const = 0;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const = 0;
    virtual hkUint32 GetFilterInfoForKey(hkpShapeKey key) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const = 0;
    virtual void vf06();
};
