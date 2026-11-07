#pragma once

#include "hkpExtendedMeshShape.h"
#include "hkVector4.h"
#include "hkpMeshMaterial.h"
#include "hkArray.h"   // the arrays' ~hkArray (bufFree through the thread heap) is unit-defined

class hkpStorageExtendedMeshShapeMeshSubpartStorage;
class hkpStorageExtendedMeshShapeShapeSubpartStorage;
struct Subpart;
struct TrianglesSubpart;
struct ShapesSubpart;
struct SourceArg;

class hkpStorageExtendedMeshShape : public hkpExtendedMeshShape
{
public:
    // Havok 7.1 hkpStorageExtendedMeshShape::Material (12 bytes).
    struct Material : public hkpMeshMaterial
    {
        short m_restitution;  // hkHalf
        short m_friction;     // hkHalf
        unsigned long m_userData;
    };
    struct MeshSubpartStorage;
    // RTTI hkpStorageExtendedMeshShape::ShapeSubpartStorage : hkReferencedObject, vftable 0x010cfd10;
    // destructor 0x00d4ac70, deleting destructor 0x00d4ad20. Arrays at +0x08/+0x14/+0x20.
    struct ShapeSubpartStorage : public hkReferencedObject
    {
        virtual ~ShapeSubpartStorage() throw();

        hkArray<unsigned char> m_kMaterialIndices8;
        hkArray<Material> m_kMaterials;
        hkArray<unsigned short> m_kMaterialIndices16;
    };

    hkpStorageExtendedMeshShape(FinishingFlag flag) throw();
    hkpStorageExtendedMeshShape(const hkpExtendedMeshShape* mesh) throw();
    virtual ~hkpStorageExtendedMeshShape() throw();

    virtual void addTrianglesSubpart(SourceArg sourceArg);
    virtual int addShapesSubpart(const TrianglesSubpart& partIn);

    Subpart* hkpExtendedMeshShape_expandOneTriangleSubparts();
    TrianglesSubpart* AppendElement();
    void hkpExtendedMeshShape_recalcAabbExtents();
    int Vec4(Subpart* part, int index);
    int hkpExtendedMeshShape__getNumChildShapesInShapesSubpart(TrianglesSubpart& part);
    void addTrianglesSubpart(const Subpart& part) throw();
    void addShapesSubpart(const ShapesSubpart& part) throw();

    unsigned char unk18[0x68];
    hkVector4 m_kAabbHalfExtents;
    hkVector4 m_kAabbCenter;
    unsigned char unkA0[0x10];
    int m_iNumBitsForSubpartIndex;
    hkArray<Subpart> m_kTrianglesSubparts;
    hkArray<ShapesSubpart> m_kShapesSubparts;
    hkArray<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned char unkD9[0x7];
    int m_iNumTriangles;
    hkReal m_fSphereRadius;
    unsigned char unkE8[0x8];
    hkArray<hkpStorageExtendedMeshShapeMeshSubpartStorage*> m_kMeshSubparts;
    hkArray<hkpStorageExtendedMeshShapeShapeSubpartStorage*> m_kShapeSubparts;
    unsigned char unk108[0x8];
};
