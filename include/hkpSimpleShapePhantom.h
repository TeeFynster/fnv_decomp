#pragma once

#include "hkpShapePhantom.h"
#include "hkaAnimation.h"
#include "hkBool.h"

class hkpSimpleShapePhantomCollisionDetail;

class hkpSimpleShapePhantom : public hkpShapePhantom
{
public:
    hkArray<hkpSimpleShapePhantomCollisionDetail> m_kCollisionDetails;
    hkBool m_bOrderDirty;
    char pad16D[0x3];
};
