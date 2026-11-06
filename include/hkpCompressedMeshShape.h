#pragma once

#include "hkpShapeCollection.h"
#include "hkArray.h"
#include "hkTransform.h"
#include "hkVector4.h"
#include "hkAabb.h"

class hkpCompressedMeshShapeBigTriangle;
class hkpCompressedMeshShapeChunk;
class hkpCompressedMeshShapeConvexPiece;
class hkpNamedMeshMaterial;

class __declspec(novtable) hkpCompressedMeshShape : public hkpShapeCollection
{
public:
    enum MaterialType
    {
        MATERIAL_NONE = 0,
        MATERIAL_SINGLE_VALUE_PER_CHUNK = 1,
        MATERIAL_ONE_BYTE_PER_TRIANGLE = 2,
        MATERIAL_TWO_BYTES_PER_TRIANGLE = 3,
        MATERIAL_FOUR_BYTES_PER_TRIANGLE = 4
    };

    hkpCompressedMeshShape(float value);
    hkpCompressedMeshShape(FinishingFlag flag) throw();

    unsigned int GetShapeIndexMask();
    void SetWeldingType(unsigned char weldingType);
    void __thiscall SetAttribute(unsigned long instanceMask, unsigned short attributeValue);

    virtual ~hkpCompressedMeshShape() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    virtual void vf11(int);
    virtual void vf12(int, int);

    int m_iBitsPerIndex;
    int m_iBitsPerWIndex;
    int m_iNumBitsForIndex;
    int m_iNumBitsForWIndex;
    float m_fSphereRadius;
    unsigned char m_eWeldingType;
    unsigned char m_ucMaterialType;
    char pad2E[0x2];
    hkArray<unsigned int> m_kMaterials;
    hkArray<unsigned short> m_kMaterialIndices16;
    hkArray<unsigned char> m_kMaterialIndices8;
    hkArray<hkTransform> m_kTransforms;
    hkArray<hkVector4> m_kBigVertices;
    hkArray<hkpCompressedMeshShapeBigTriangle> m_kBigTriangles;
    hkArray<hkpCompressedMeshShapeChunk> m_kChunks;
    hkArray<hkpCompressedMeshShapeConvexPiece> m_kConvexPieces;
    float m_eScriptError;
    char pad94[0xC];
    hkAabb m_kBounds;
    void* m_pUserData;
    unsigned short m_iIndexStriding;
    unsigned short m_iNumTriangles;
    hkArray<hkpNamedMeshMaterial> m_kNamedMaterials;
    char padD4[0x1C];
};
