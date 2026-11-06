#pragma once

#include "hkpShape.h"

class hkpListShapeChildInfo
{
public:
    const hkpShape* m_pCollisionShape;
    union
    {
        int unk04;
        unsigned int m_uiCollisionFilterData;
        int m_iFilter;
    };
    union
    {
        int unk08;
        int m_iShapeKey;
    };
    union
    {
        int unk0c;
        int m_iChildShapeCount;
    };
};
