#pragma once

#include "NiGeometry.h"

class NiTriBasedGeomData;
class NiShadeProperty;

class NiTriBasedGeom : public NiGeometry
{
  public:
    NiTriBasedGeom(NiTriBasedGeomData* data) throw();
    virtual ~NiTriBasedGeom();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual void ReplaceModelData(NiGeometryData* data);
    virtual void GetTrianglePoints(unsigned short triangle, NiPoint3** a, NiPoint3** b, NiPoint3** c);

    void CopyMemberData(NiTriBasedGeom* source, CloningProcess* process);
    unsigned short GetTriangleCount();
    void SetNumberOfVertices(unsigned short count);
    unsigned short GetNumberOfVertices();
    NiTriBasedGeom* IsTriBasedGeom();
    void GetTriangleVertexIndices(unsigned short triangle, unsigned short* a, unsigned short* b, unsigned short* c);
    void GetTriangleVertexIndices(unsigned short triangle, unsigned short& a, unsigned short& b, unsigned short& c);
    unsigned short* GetStripIndices();
    void GetTriangle(unsigned short triangle, unsigned short& a, unsigned short& b, unsigned short& c);
    NiShadeProperty* GetProperty(unsigned int type);
    void SetBitfield(unsigned short value, unsigned short mask, unsigned short shift);
    void vfn_dc();
    void vfn_e0();
    void __local_vftable_ctor_closure();
};
