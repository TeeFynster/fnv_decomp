#pragma once

#include "hkpHeightFieldShape.h"
#include "hkVector4.h"

typedef int hkInt32;
typedef unsigned char hkUint8;

class hkpSampledHeightFieldShape : public hkpHeightFieldShape
{
public:
    enum HeightFieldType
    {
        HEIGHTFIELD_STORAGE = 0,
        HEIGHTFIELD_COMPRESSED = 1,
        HEIGHTFIELD_USER = 2,
        HEIGHTFIELD_MAX_ID = 3
    };


    virtual void v12();
    virtual hkReal GetHeightAtGridPoint(int x, int z) const;
    virtual hkBool IsTriangleWindingFlipped() const;

    hkReal getHeightAt(int x, int z) const throw();
    hkReal getScaledHeight(int x, int z) const throw();

    hkInt32 m_iXResolution;
    hkInt32 m_iZResolution;
    hkReal m_fHeightScale;
    hkBool m_bUseProjectionBasedHeight;
    hkUint8 m_ucHeightFieldType;
    char pad1E[0x2];
    hkVector4 m_kHeightScaleVector;
    hkVector4 m_kInverseScale;
    hkVector4 m_kOffset;
    hkVector4 SetCenterPosition;
};
