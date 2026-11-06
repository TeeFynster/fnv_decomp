#pragma once

#include "hkaAnimation.h"
#include "hkQsTransform.h"

class hkaInterleavedUncompressedAnimation : public hkaAnimation
{
public:
    hkArray<hkQsTransform> m_kTransforms;
    hkArray<hkReal> m_kFloats;
};
