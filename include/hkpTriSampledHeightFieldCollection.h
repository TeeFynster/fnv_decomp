#pragma once

#include "hkpShapeCollection.h"
#include "hkpSampledHeightFieldShape.h"
#include "hkaAnimation.h"
#include "hkVector4.h"

typedef unsigned short hkUint16;

class hkpTriSampledHeightFieldCollection : public hkpShapeCollection
{
public:
    const hkpSampledHeightFieldShape* getHeightFieldShape() const;

    hkpSampledHeightFieldShape* m_pHeightFieldShape;
    hkInt32 m_iChildSize;
    hkReal m_fSphereRadius;
    hkArray<hkUint16> m_kWeldingInfo;
    hkVector4 m_kTriangleExtrusion;
};
