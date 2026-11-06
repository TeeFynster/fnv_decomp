#pragma once

#include "hkContactPoint.h"

// Havok 7.1 Physics/Collide/Query/Collector/PointCollector/hkpRootCdPoint.h: 0x30 bytes, the contact point then per
// body the root collidable and the shape key (hkpClosestCdPointCollector holds it as m_hitPoint at +0x10). Member
// names are the ones the FNV units use.
struct hkpRootCdPoint
{
    hkContactPoint m_kPoint;           // +0x00
    const void* m_pRootCollidableA;    // +0x20
    unsigned int m_uiShapeKeyA;        // +0x24
    const void* m_pRootCollidableB;    // +0x28
    unsigned int m_uiShapeKeyB;        // +0x2C
};
