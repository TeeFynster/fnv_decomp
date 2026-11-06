#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

class hkpConvexVerticesConnectivity : public hkReferencedObject
{
public:
    virtual void vf03();

    hkArray<hkUint16> m_kVertexIndices;
    hkArray<hkUint8> m_kNumVerticesPerFace;
};
