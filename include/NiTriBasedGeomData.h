#pragma once

#include "NiGeometryData.h"

class NiTriBasedGeomData : public NiGeometryData
{
  public:
    NiTriBasedGeomData(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*,
                       unsigned short, NiGeometryData__DataFlags, unsigned short);
    virtual ~NiTriBasedGeomData();

    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);

    virtual void vf41();
    virtual void vf42();
    virtual void GetTriangleIndices(unsigned short, unsigned short*, unsigned short*, unsigned short*);
    virtual void GetStripData(unsigned short*, const unsigned short**, const unsigned short**, unsigned int*);

    unsigned short GetNumTriangles();
    void GetTriangles(unsigned short&, const unsigned short*&, const unsigned short*&, unsigned int&);

    unsigned short m_usTriangles;
    unsigned char _pad42[2];
};
