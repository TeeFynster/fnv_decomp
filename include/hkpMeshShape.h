#pragma once

#include "hkpShapeCollection.h"
#include "hkVector4.h"
#include "hkaAnimation.h"

class hkpMeshShapeSubpart;
struct MeshFinishFlag;

typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

class hkpMeshShape : public hkpShapeCollection
{
public:
    enum MeshShapeIndexStridingType
    {
        INDICES_INVALID = 0,
        INDICES_INT16 = 1,
        INDICES_INT32 = 2,
        INDICES_MAX_ID = 3
    };

    enum MeshShapeMaterialIndexStridingType
    {
        MATERIAL_INDICES_INVALID = 0,
        MATERIAL_INDICES_INT8 = 1,
        MATERIAL_INDICES_INT16 = 2,
        MATERIAL_INDICES_MAX_ID = 3
    };

    hkpMeshShape(float fRadius, int iNumBitsForSubpartIndex) throw();
    hkpMeshShape(FinishingFlag flag);
    hkpMeshShape(MeshFinishFlag flag);

    virtual void vf13();

    char pad18[0x8];
    hkVector4 m_kScaling;
    hkInt32 m_iNumBitsForSubpartIndex;
    hkArray<hkpMeshShapeSubpart> m_kSubparts;
    hkArray<hkUint16> m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    char pad4D[0x3];
    hkReal m_fSphereRadius;
    hkInt32 m_auiShapeKeys[3];
};
