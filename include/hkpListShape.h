#pragma once

#include "hkpShapeCollection.h"
#include "hkaAnimation.h"
#include "hkVector4.h"

class hkpListShapeChildInfo;

typedef unsigned short hkUint16;
typedef unsigned int hkUint32_S;

class hkpListShape : public hkpShapeCollection
{
public:
    enum ListShapeFlags
    {
        ALL_FLAGS_CLEAR = 0,
        DISABLE_SPU_CACHE_FOR_LIST_CHILD_INFO = 1
    };

    enum { MAX_DISABLED_CHILDREN = 256 };

    static const ClassMemberDescriptor Members[];

    hkpListShape(const hkpShape* const* shapeArray, int numShapes,
                 hkpShapeContainer::ReferencePolicy ref = hkpShapeContainer::REFERENCE_POLICY_INCREMENT);

    virtual int GetNumChildShapes() const;
    const hkpShape* getChildShapeInl(int i) const;
    hkpListShape* FUN_00cf5640(const hkpShape* const*, int, int);

    void InitializeChildShapes(const hkpShape* const* shapeArray, int numShapes,
                               const hkUint32_S* filterInfoArray = 0,
                               hkpShapeContainer::ReferencePolicy ref = hkpShapeContainer::REFERENCE_POLICY_INCREMENT);

    hkArray<hkpListShapeChildInfo> m_kChildInfoList;
    hkUint16 m_flags;
    hkUint16 m_usNumDisabledChildren;
    char pad28[8];
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    hkUint32_S m_uiChildEnabledFlags[8];
};
